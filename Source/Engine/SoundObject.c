
/**
 * @file    Engine\SoundObject.c
 * @author  Yvan Burrie
 * @date    2018/08/19
 * @version 1.0
 */

/**
 *
 */
SNDOBJ *SndObjCreate( IDirectSound *pDS, LPCTSTR lpName, int iConcurrent )
{
    SNDOBJ *pSO = NULL;
    LPWAVEFORMATEX pWaveHeader;
    BYTE *pbData;
    UINT cbData;

    if(DSGetWaveResource(NULL, lpName, &pWaveHeader, &pbData, (ULONG*)&cbData)){
        if(iConcurrent < 1)
            iConcurrent = 1;

        if((pSO = (SNDOBJ *)LocalAlloc(LPTR, sizeof(SNDOBJ) +
        (iConcurrent-1) * sizeof(IDirectSoundBuffer *))) != NULL)
        {
            int i;

            pSO->iAlloc = iConcurrent;
            pSO->pbWaveData = pbData;
            pSO->cbWaveSize = cbData;
            pSO->Buffers[0] = DSLoadSoundBuffer(pDS, lpName);

        for (i=1; i<pSO->iAlloc; i++)
        {
        if(FAILED(IDirectSound_DuplicateSoundBuffer(pDS,
                    pSO->Buffers[0], &pSO->Buffers[i])))
                {
            pSO->Buffers[i] = DSLoadSoundBuffer(pDS, lpName);
            if(!pSO->Buffers[i]) {
            SndObjDestroy(pSO);
            pSO = NULL;
            break;
            }
        }
            }
        }
    }

    if( NULL == pSO )
        OutputDebugString( "Could not create SndObj object\n" );

    return pSO;
}

/**
 *
 */
void SndObjDestroy( SNDOBJ *pSO )
{
    if( pSO ){
        for( int i = 0; i < pSO->iAlloc; i++ ){
            if( pSO->Buffers[i] ){
                IDirectSoundBuffer_Release(pSO->Buffers[i]);
                pSO->Buffers[i] = NULL;
            }
        }
        LocalFree((HANDLE)pSO);
    }
}

IDirectSoundBuffer *SndObjGetFreeBuffer(SNDOBJ *pSO)
{
    IDirectSoundBuffer *pDSB;

    if(pSO == NULL)
        return NULL;

    if(pDSB = pSO->Buffers[pSO->iCurrent])
    {
        HRESULT hres;
        DWORD dwStatus;

        hres = IDirectSoundBuffer_GetStatus(pDSB, &dwStatus);

        if(FAILED(hres))
            dwStatus = 0;

        if((dwStatus & DSBSTATUS_PLAYING) == DSBSTATUS_PLAYING)
        {
            if(pSO->iAlloc > 1)
            {
                if(++pSO->iCurrent >= pSO->iAlloc)
                    pSO->iCurrent = 0;

                pDSB = pSO->Buffers[pSO->iCurrent];
                hres = IDirectSoundBuffer_GetStatus(pDSB, &dwStatus);

                if(SUCCEEDED(hres) && (dwStatus & DSBSTATUS_PLAYING) == DSBSTATUS_PLAYING)
                {
                    IDirectSoundBuffer_Stop(pDSB);
                    IDirectSoundBuffer_SetCurrentPosition(pDSB, 0);
                }
            }
            else
            {
                pDSB = NULL;
            }
        }

        if(pDSB && (dwStatus & DSBSTATUS_BUFFERLOST))
        {
            if(FAILED(IDirectSoundBuffer_Restore(pDSB)) ||
                !DSFillSoundBuffer(pDSB, pSO->pbWaveData, pSO->cbWaveSize))
            {
                pDSB = NULL;
            }
        }
    }

    if( NULL == pDSB )
        OutputDebugString( "Could not get free buffer for SndObj!\n" );

    return pDSB;
}

BOOL SndObjPlay(SNDOBJ *pSO, DWORD dwPlayFlags)
{
    BOOL result = FALSE;

    if(pSO == NULL)
        return FALSE;

    if((!(dwPlayFlags & DSBPLAY_LOOPING) || (pSO->iAlloc == 1)))
    {
    IDirectSoundBuffer *pDSB = SndObjGetFreeBuffer(pSO);
    if(pDSB != NULL) {
        result = SUCCEEDED(IDirectSoundBuffer_Play(pDSB, 0, 0, dwPlayFlags));
    }
    }

    return result;
}

BOOL SndObjStop(SNDOBJ *pSO)
{
    int i;

    if(pSO == NULL)
        return FALSE;

    for (i=0; i<pSO->iAlloc; i++)
    {
        IDirectSoundBuffer_Stop(pSO->Buffers[i]);
        IDirectSoundBuffer_SetCurrentPosition(pSO->Buffers[i], 0);
    }

    return TRUE;
}
