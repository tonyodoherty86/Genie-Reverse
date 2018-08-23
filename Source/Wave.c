
/**
 * @file    Engine\Wave.c
 * @author  Yvan Burrie
 * @date    2018/08/21
 * @version 1.0
 */
#include <mmsystem.h>
/**
 *
 */
MMRESULT WaveOpenFile( char *pszFileName, void **phmmioIn, WAVEFORMATEX **ppwfxInfo, MMCKINFO *pckInRIFF )
{
    HMMIO           hmmioIn = NULL;
    MMCKINFO        ckIn;           // chunk info. for general use.
    PCMWAVEFORMAT   pcmWaveFormat;  // Temp PCM structure to load in.
    WORD            cbExtraAlloc;   // Extra bytes for waveformatex
    int             nError = 0;     // Return value.

    // Initialization
    *ppwfxInfo = NULL;

    if( (hmmioIn = mmioOpen(pszFileName, NULL, MMIO_ALLOCBUF | MMIO_READ)) == NULL ){
        nError = ER_CANNOTOPEN;
        goto ERROR_READING_WAVE;
    }

    if( (nError = (int)mmioDescend(hmmioIn, pckInRIFF, NULL, 0)) != 0 )
    {
        goto ERROR_READING_WAVE;
    }

    if( (pckInRIFF->ckid != FOURCC_RIFF) || (pckInRIFF->fccType != mmioFOURCC('W', 'A', 'V', 'E')) ){
        nError = ER_NOTWAVEFILE;
        goto ERROR_READING_WAVE;
    }

    /* Search the input file for for the 'fmt ' chunk.     */
    ckIn.ckid = mmioFOURCC('f', 'm', 't', ' ');
    if( (nError = (int)mmioDescend(hmmioIn, &ckIn, pckInRIFF, MMIO_FINDCHUNK)) != 0 ){
        goto ERROR_READING_WAVE;
    }

    /* Expect the 'fmt' chunk to be at least as large as <PCMWAVEFORMAT>;
     * if there are extra parameters at the end, we'll ignore them */
    if( ckIn.cksize < (long)sizeof(PCMWAVEFORMAT) ){
        nError = ER_NOTWAVEFILE;
        goto ERROR_READING_WAVE;
    }

    /* Read the 'fmt ' chunk into <pcmWaveFormat>.*/
    if( mmioRead(hmmioIn, (HPSTR) &pcmWaveFormat, (long)sizeof(pcmWaveFormat)) != (long)sizeof(pcmWaveFormat) ){
        nError = ER_CANNOTREAD;
        goto ERROR_READING_WAVE;
    }

    // Allocate the waveformatex, but if its not pcm
    // format, read the next word, and thats how many extra
    // bytes to allocate.
    if( pcmWaveFormat.wf.wFormatTag == WAVE_FORMAT_PCM ){
        cbExtraAlloc = 0;
    }else{
        // Read in length of extra bytes.
        if(mmioRead(hmmioIn, (HPSTR) &cbExtraAlloc, (long)sizeof(cbExtraAlloc)) != (long)sizeof(cbExtraAlloc)){
            nError = ER_CANNOTREAD;
            goto ERROR_READING_WAVE;
        }
    }

    // Now allocate that waveformatex structure.
    if( (*ppwfxInfo = GlobalAlloc(GMEM_FIXED, sizeof(WAVEFORMATEX)+cbExtraAlloc)) == NULL ){
        nError = ER_MEM;
        goto ERROR_READING_WAVE;
    }

    // Copy the bytes from the pcm structure to the waveformatex structure
    memcpy(*ppwfxInfo, &pcmWaveFormat, sizeof(pcmWaveFormat));
    (*ppwfxInfo)->cbSize = cbExtraAlloc;

    // Read those extra bytes into the structure, if cbExtraAlloc != 0.
    if(cbExtraAlloc != 0){
        if(mmioRead(hmmioIn, (HPSTR) (((BYTE*)&((*ppwfxInfo)->cbSize)) + sizeof(cbExtraAlloc)), (long)(cbExtraAlloc)) != (long)(cbExtraAlloc)){
            nError = ER_NOTWAVEFILE;
            goto ERROR_READING_WAVE;
        }
    }

    /* Ascend the input file out of the 'fmt ' chunk. */
    if((nError = mmioAscend(hmmioIn, &ckIn, 0)) != 0){
        goto ERROR_READING_WAVE;
    }

    goto TEMPCLEANUP;

    ERROR_READING_WAVE:
    if(*ppwfxInfo != NULL){
        GlobalFree(*ppwfxInfo);
        *ppwfxInfo = NULL;
    }

    if(hmmioIn != NULL){
        mmioClose(hmmioIn, 0);
        hmmioIn = NULL;
    }

    TEMPCLEANUP:
    *phmmioIn = hmmioIn;

    return(nError);
}

/**
 *
 */
int WaveStartDataRead(
    HMMIO *phmmioIn,
    MMCKINFO *pckIn,
    MMCKINFO *pckInRIFF )
{
    int nError=0;

    // Perform a seek...
    if((nError = mmioSeek(*phmmioIn, pckInRIFF->dwDataOffset + sizeof(FOURCC), SEEK_SET)) == -1)
    {
        // ASSERT(FALSE);
    }

    nError = 0;

    // Search the input file for for the 'data' chunk.
    pckIn->ckid = mmioFOURCC('d', 'a', 't', 'a');
    nError = mmioDescend(*phmmioIn, pckIn, pckInRIFF, MMIO_FINDCHUNK);

    return(nError);
}

/**
 *
 */
MMRESULT WaveReadFile(
    HMMIO hmmioIn,
    UINT cbRead,
    BYTE *pbDest,
    MMCKINFO *pckIn,
    UINT *cbActualRead )
{
    MMIOINFO    mmioinfoIn;         // current status of <hmmioIn>
    int         nError=0;
    UINT        cT, cbDataIn;

    if((nError = mmioGetInfo(hmmioIn, &mmioinfoIn, 0)) != 0)
    {
        goto ERROR_CANNOT_READ;
    }

    cbDataIn = cbRead;
    if(cbDataIn > pckIn->cksize)
        cbDataIn = pckIn->cksize;

    pckIn->cksize -= cbDataIn;

    for (cT = 0; cT < cbDataIn; cT++)
    {
        /* Copy the bytes from the io to the buffer. */
        if(mmioinfoIn.pchNext == mmioinfoIn.pchEndRead)
        {
            if((nError = mmioAdvance(hmmioIn, &mmioinfoIn, MMIO_READ)) != 0)
            {
                goto ERROR_CANNOT_READ;
            }
            if(mmioinfoIn.pchNext == mmioinfoIn.pchEndRead)
            {
                nError = ER_CORRUPTWAVEFILE;
                goto ERROR_CANNOT_READ;
            }
        }

        // Actual copy.
        *((BYTE*)pbDest+cT) = *((BYTE*)mmioinfoIn.pchNext)++;
    }

    if((nError = mmioSetInfo(hmmioIn, &mmioinfoIn, 0)) != 0)
    {
        goto ERROR_CANNOT_READ;
    }

    *cbActualRead = cbDataIn;
    goto FINISHED_READING;

    ERROR_CANNOT_READ:
    *cbActualRead = 0;

    FINISHED_READING:
    return nError;

}

/**
 *
 */
int WaveCloseReadFile(
    HMMIO *phmmio,
    WAVEFORMATEX **ppwfxSrc )
{
    if(*ppwfxSrc != NULL)
    {
        GlobalFree(*ppwfxSrc);
        *ppwfxSrc = NULL;
    }

    if(*phmmio != NULL)
    {
        mmioClose(*phmmio, 0);
        *phmmio = NULL;
    }

    return(0);
}

/**
 *
 */
MMRESULT WaveCreateFile(
    TCHAR *pszFileName,
    HMMIO *phmmioOut,
    WAVEFORMATEX *pwfxDest,
    MMCKINFO *pckOut,
    MMCKINFO *pckOutRIFF )
{
    int       nError;        // Return value
    DWORD     dwFactChunk;   // Contains the actual fact chunk. Garbage until WaveCloseWriteFile.
    MMCKINFO  ckOut1;

    dwFactChunk = (DWORD)-1;
    nError = 0;

    *phmmioOut = mmioOpen(pszFileName, NULL,
        MMIO_ALLOCBUF | MMIO_READWRITE|MMIO_CREATE);

    if(*phmmioOut == NULL)
    {
        nError = ER_CANNOTWRITE;
        goto ERROR_CANNOT_WRITE;    // cannot save WAVE file
    }

    /* Create the output file RIFF chunk of form type 'WAVE'. */
    pckOutRIFF->fccType = mmioFOURCC('W', 'A', 'V', 'E');
    pckOutRIFF->cksize = 0;
    if((nError = mmioCreateChunk(*phmmioOut, pckOutRIFF, MMIO_CREATERIFF)) != 0)
    {
        goto ERROR_CANNOT_WRITE;    // cannot write file, probably
    }

    /* We are now descended into the 'RIFF' chunk we just created.
     * Now create the 'fmt ' chunk. Since we know the size of this chunk,
     * specify it in the MMCKINFO structure so MMIO doesn't have to seek
     * back and set the chunk size after ascending from the chunk.
     */
    pckOut->ckid = mmioFOURCC('f', 'm', 't', ' ');
    pckOut->cksize = sizeof(PCMWAVEFORMAT);   // we know the size of this ck.
    if((nError = mmioCreateChunk(*phmmioOut, pckOut, 0)) != 0)
    {
        goto ERROR_CANNOT_WRITE;    // cannot write file, probably
    }

    /* Write the PCMWAVEFORMAT structure to the 'fmt ' chunk if its that type. */
    if(pwfxDest->wFormatTag == WAVE_FORMAT_PCM)
    {
        if(mmioWrite(*phmmioOut, (HPSTR) pwfxDest, sizeof(PCMWAVEFORMAT))
            != sizeof(PCMWAVEFORMAT))
        {
            nError = ER_CANNOTWRITE;
            goto ERROR_CANNOT_WRITE;    // cannot write file, probably
        }
    }
    else
    {
        // Write the variable length size.
        if((UINT)mmioWrite(*phmmioOut, (HPSTR) pwfxDest, sizeof(*pwfxDest)+pwfxDest->cbSize)
            != (sizeof(*pwfxDest)+pwfxDest->cbSize))
        {
            nError = ER_CANNOTWRITE;
            goto ERROR_CANNOT_WRITE;    // cannot write file, probably
        }
    }

    /* Ascend out of the 'fmt ' chunk, back into the 'RIFF' chunk. */
    if((nError = mmioAscend(*phmmioOut, pckOut, 0)) != 0)
    {
        goto ERROR_CANNOT_WRITE;    // cannot write file, probably
    }

    // Now create the fact chunk, not required for PCM but nice to have.  This is filled
    // in when the close routine is called.
    ckOut1.ckid = mmioFOURCC('f', 'a', 'c', 't');
    ckOut1.cksize = 0;
    if((nError = mmioCreateChunk(*phmmioOut, &ckOut1, 0)) != 0)
    {
        goto ERROR_CANNOT_WRITE;    // cannot write file, probably
    }

    if(mmioWrite(*phmmioOut, (HPSTR)&dwFactChunk, sizeof(dwFactChunk)) != sizeof(dwFactChunk))
    {
        nError = ER_CANNOTWRITE;
        goto ERROR_CANNOT_WRITE;
    }

    // Now ascend out of the fact chunk...
    if((nError = mmioAscend(*phmmioOut, &ckOut1, 0)) != 0)
    {
        nError = ER_CANNOTWRITE;        // cannot write file, probably
        goto ERROR_CANNOT_WRITE;
    }

    goto DONE_CREATE;

    ERROR_CANNOT_WRITE:
    // Maybe delete the half-written file?  For now, its good to leave the
    // file there for debugging.

    DONE_CREATE:
    return(nError);
}

/**
 *
 */
MMRESULT WaveStartDataWrite(
    HMMIO *phmmioOut,
    MMCKINFO *pckOut,
    MMIOINFO *pmmioinfoOut )
{
    MMRESULT nError = 0;

    /* Create the 'data' chunk that holds the waveform samples. */
    pckOut->ckid = mmioFOURCC('d', 'a', 't', 'a');
    pckOut->cksize = 0;

    if( (nError = mmioCreateChunk(*phmmioOut, pckOut, 0)) != 0 ){
        return nError;
    }

    nError = mmioGetInfo(*phmmioOut, pmmioinfoOut, 0);

    return nError;
}

/**
 *
 */
MMRESULT WaveWriteFile(
    HMMIO hmmioOut,
    UINT cbWrite,
    BYTE *pbSrc,
    MMCKINFO *pckOut,
    UINT *cbActualWrite,
    MMIOINFO *pmmioinfoOut )
{
    MMRESULT nError = 0;

    *cbActualWrite = 0;

    for( UINT cT = 0; cT < cbWrite; cT++ ){

        if( pmmioinfoOut->pchNext == pmmioinfoOut->pchEndWrite ){

            pmmioinfoOut->dwFlags |= MMIO_DIRTY;

            if( (nError = mmioAdvance(hmmioOut, pmmioinfoOut, MMIO_WRITE)) != 0 ){
                goto ERROR_CANNOT_WRITE;
            }
        }

        *((BYTE*)pmmioinfoOut->pchNext)++ = *((BYTE*)pbSrc + cT);
        (*cbActualWrite)++;
    }

    ERROR_CANNOT_WRITE:

    return nError;
}

/**
 *
 */
MMRESULT WaveCloseWriteFile(
    HMMIO *phmmioOut,
    MMCKINFO *pckOut,
    MMCKINFO *pckOutRIFF,
    MMIOINFO *pmmioinfoOut,
    DWORD cSamples )
{
    MMRESULT nError = 0;

    if( *phmmioOut == NULL ){
        return 0;
    }

    pmmioinfoOut->dwFlags |= MMIO_DIRTY;
    if( (nError = mmioSetInfo(*phmmioOut, pmmioinfoOut, 0)) != 0 ){
        /* cannot flush, probably... */
        goto ERROR_CANNOT_WRITE;
    }

    /* Ascend the output file out of the 'data' chunk -- this will cause the chunk size of the 'data' chunk to be written. */
    if( (nError = mmioAscend(*phmmioOut, pckOut, 0)) != 0 ){
        goto ERROR_CANNOT_WRITE;
    }

    /* Do this here instead... */
    if( (nError = mmioAscend(*phmmioOut, pckOutRIFF, 0)) != 0 ){
        goto ERROR_CANNOT_WRITE;
    }

    nError = mmioSeek(*phmmioOut, 0, SEEK_SET);
    if( (nError = (int)mmioDescend(*phmmioOut, pckOutRIFF, NULL, 0)) != 0 ){
        goto ERROR_CANNOT_WRITE;
    }

    nError = 0;
    pckOut->ckid = mmioFOURCC('f', 'a', 'c', 't');
    if( (nError = mmioDescend(*phmmioOut, pckOut, pckOutRIFF, MMIO_FINDCHUNK)) == 0 ){
        /* If it didn't fail, write the fact chunk out, if it failed, not critical, just assert (below). */
        nError = mmioWrite(*phmmioOut, (HPSTR)&cSamples, sizeof(DWORD));
        nError = mmioAscend(*phmmioOut, pckOut, 0);
    }
    nError = 0;

    /* Ascend the output file out of the 'RIFF' chunk -- this will cause the chunk size of the 'RIFF' chunk to be written. */
    if( (nError = mmioAscend(*phmmioOut, pckOutRIFF, 0)) != 0 ){
        goto ERROR_CANNOT_WRITE;
    }


    ERROR_CANNOT_WRITE:
    if( *phmmioOut != NULL ){
        mmioClose(*phmmioOut, 0);
        *phmmioOut = NULL;
    }

    return nError;
}

/**
 *
 */
int WaveCopyUselessChunks(
    HMMIO *phmmioIn,
    MMCKINFO *pckIn,
    MMCKINFO *pckInRiff,
    HMMIO *phmmioOut,
    MMCKINFO *pckOut,
    MMCKINFO *pckOutRiff )
{
    /* First seek to the start of the file, not including the riff header... */
    int  nError = mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + sizeof(FOURCC), SEEK_SET);

    if( nError == -1 ){
        nError = ER_CANNOTREAD;
        goto ERROR_IN_PROC;
    }

    nError = 0;

    while( mmioDescend(*phmmioIn, pckIn, pckInRiff, 0) == 0 ){

        /* quickly check for corrupt RIFF file--don't ascend past end! */
        if( (pckIn->dwDataOffset + pckIn->cksize) > (pckInRiff->dwDataOffset + pckInRiff->cksize) ){
            goto ERROR_IN_PROC;
        }

        switch( pckIn->ckid ){

        /* explicitly skip these... */
        case mmioFOURCC('f', 'm', 't', ' '):
            break;

        case mmioFOURCC('d', 'a', 't', 'a'):
            break;

        case mmioFOURCC('f', 'a', 'c', 't'):
            break;

        case mmioFOURCC('J', 'U', 'N', 'K'):
            break;

        case mmioFOURCC('P', 'A', 'D', ' '):
            break;

        case mmioFOURCC('c', 'u', 'e', ' '):
            break;

        /* copy chunks that are OK to copy */
        case mmioFOURCC('p', 'l', 's', 't'):
            /* although without the 'cue' chunk, it doesn't make much sense */
            riffCopyChunk(*phmmioIn, *phmmioOut, pckIn);
            break;

        case mmioFOURCC('D', 'I', 'S', 'P'):
            riffCopyChunk(*phmmioIn, *phmmioOut, pckIn);
            break;

        /* don't copy unknown chunks */
        default:
            break;
        }

        /* step up to prepare for next chunk */
        mmioAscend(*phmmioIn, pckIn, 0);
    }

    ERROR_IN_PROC:
    /* Seek back to riff header */
    int nErrorT = mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + sizeof(FOURCC), SEEK_SET);

    return nError;
}

/**
 *
 */
BOOL riffCopyChunk( HMMIO hmmioSrc, HMMIO hmmioDst, const LPMMCKINFO lpck )
{
    HPSTR hpBuf = (HPSTR)GlobalAllocPtr(GHND, lpck->cksize);
    if( hpBuf == NULL ){
        return FALSE;
    }

    MMCKINFO ck;
    ck.ckid   = lpck->ckid;
    ck.cksize = lpck->cksize;

    if( mmioCreateChunk(hmmioDst, &ck, 0) ){
        goto rscc_Error;
    }

    if( mmioRead(hmmioSrc, hpBuf, lpck->cksize) != (LONG)lpck->cksize ){
        goto rscc_Error;
    }

    if( mmioWrite(hmmioDst, hpBuf, lpck->cksize) != (LONG)lpck->cksize ){
        goto rscc_Error;
    }

    if( mmioAscend(hmmioDst, &ck, 0) ){
        goto rscc_Error;
    }

    if( hpBuf ){
        GlobalFreePtr(hpBuf);
    }

    return TRUE;

    rscc_Error:

    if( hpBuf ){
        GlobalFreePtr(hpBuf);
    }

    return FALSE;
}

/**
 *
 */
MMRESULT WaveLoadFile(
    TCHAR *pszFileName,
    UINT *cbSize,
    WAVEFORMATEX **ppwfxInfo,
    BYTE **ppbData )
{
    HMMIO hmmioIn;
    MMCKINFO ckInRiff, ckIn;
    int nError;
    UINT cbActualRead;

    *ppbData = NULL;
    *ppwfxInfo = NULL;
    *cbSize = 0;

    if( (nError = WaveOpenFile(pszFileName, &hmmioIn, ppwfxInfo, &ckInRiff)) != 0 ){
        goto ERROR_LOADING;
    }

    if( (nError = WaveStartDataRead(&hmmioIn, &ckIn, &ckInRiff)) != 0 ){
        goto ERROR_LOADING;
    }

    /* Ok, size of wave data is in ckIn, allocate that buffer. */
    if( (*ppbData = (BYTE *)GlobalAlloc(GMEM_FIXED, ckIn.cksize)) == NULL ){
        nError = ER_MEM;
        goto ERROR_LOADING;
    }

    if( (nError = WaveReadFile(hmmioIn, ckIn.cksize, *ppbData, &ckIn, &cbActualRead)) != 0 ){
        goto ERROR_LOADING;
    }

    *cbSize = cbActualRead;
    goto DONE_LOADING;

    ERROR_LOADING:
    if( *ppbData != NULL ){
        GlobalFree(*ppbData);
        *ppbData = NULL;
    }

    if( *ppwfxInfo != NULL ){
        GlobalFree(*ppwfxInfo);
        *ppwfxInfo = NULL;
    }

    DONE_LOADING:
    /* Close the wave file. */
    if( hmmioIn != NULL ){
        mmioClose(hmmioIn, 0);
        hmmioIn = NULL;
    }

    return nError;
}

/**
 *
 */
MMRESULT WaveLoadFile(
    TCHAR *pszFileName,
    UINT *cbSize,
    UINT *pcSamples,
    WAVEFORMATEX **ppwfxInfo,
    BYTE **ppbData )
{
    return WaveLoadFile(pszFileName, cbSize, ppwfxInfo, ppbData);
}

/**
 *
 */
MMRESULT WaveSaveFile(
    TCHAR *pszFileName,
    UINT cbSize,
    DWORD cSamples,
    WAVEFORMATEX *pwfxDest,
    BYTE *pbData )
{
    HMMIO hmmioOut;
    MMCKINFO ckOut, ckOutRIFF, mmioinfoOut;
    UINT cbActualWrite;
    int nError;

    switch( TRUE ){

    case (nError = WaveCreateFile(pszFileName, &hmmioOut, pwfxDest, &ckOut, &ckOutRIFF)) != 0:
        break;

    case (nError = WaveStartDataWrite(&hmmioOut, &ckOut, &mmioinfoOut)) != 0:
        break;

    case (nError = WaveWriteFile(hmmioOut, cbSize, pbData, &ckOut, &cbActualWrite, &mmioinfoOut)) != 0:
        break;

    case (nError = WaveCloseWriteFile(&hmmioOut, &ckOut, &ckOutRIFF, &mmioinfoOut, cSamples)) != 0:
        break;
    }

    return nError;
}
