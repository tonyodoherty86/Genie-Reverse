#pragma once

/**
 * @file    Engine\Wave.h
 * @author  Yvan Burrie
 * @date    2018/08/23
 * @version 1.0
 */


#include "IDA.h"

#ifdef WINDOWS
#include <windows.h>
#else
typedef int MMRESULT;
typedef int MMCKINFO;
typedef int MMIOINFO;
typedef long LPMMCKINFO;
typedef int HMMIO;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define WAVEVERSION 1

#ifndef ER_MEM
#define ER_MEM              0xe000
#endif

#ifndef ER_CANNOTOPEN
#define ER_CANNOTOPEN       0xe100
#endif

#ifndef ER_NOTWAVEFILE
#define ER_NOTWAVEFILE      0xe101
#endif

#ifndef ER_CANNOTREAD
#define ER_CANNOTREAD       0xe102
#endif

#ifndef ER_CORRUPTWAVEFILE
#define ER_CORRUPTWAVEFILE  0xe103
#endif

#ifndef ER_CANNOTWRITE
#define ER_CANNOTWRITE      0xe104
#endif

/*
int WaveOpenFile(TCHAR*, HMMIO *, WAVEFORMATEX **, MMCKINFO *);
int WaveStartDataRead(HMMIO *, MMCKINFO *, MMCKINFO *);
int WaveReadFile(HMMIO, UINT, BYTE *, MMCKINFO *, UINT *);
int WaveCloseReadFile(HMMIO *, WAVEFORMATEX **);

int WaveCreateFile(TCHAR*, HMMIO *, WAVEFORMATEX *, MMCKINFO *, MMCKINFO *);
int WaveStartDataWrite(HMMIO *, MMCKINFO *, MMIOINFO *);
int WaveWriteFile(HMMIO, UINT, BYTE *, MMCKINFO *, UINT *, MMIOINFO *);
int WaveCloseWriteFile(HMMIO *, MMCKINFO *, MMCKINFO *, MMIOINFO *, DWORD);

int WaveLoadFile(TCHAR*, UINT *, WAVEFORMATEX **, BYTE **);
int WaveSaveFile(TCHAR*, UINT, DWORD, WAVEFORMATEX *, BYTE *);

int WaveCopyUselessChunks(HMMIO *, MMCKINFO *, MMCKINFO *, HMMIO *, MMCKINFO *, MMCKINFO *);
BOOL riffCopyChunk(HMMIO, HMMIO, const LPMMCKINFO);
*/

/**
 * @brief Opens a Wave file for reading.
 * @param pszFileName Input filename to load.
 * @param phmmioIn Pointer to handle which will be used for further mmio routines.
 * @param ppwfxInfo Ptr to ptr to WaveFormatEx structure with all info about the file.
 * @return Returns 0 if successful, the error code if not.
 *
 * This function will open a wave input file and prepare it for reading, so the data can be easily read with WaveReadFile.
 */
MMRESULT WaveOpenFile( char *pszFileName, void **phmmioIn, WAVEFORMATEX **ppwfxInfo, MMCKINFO *pckInRIFF );

/**
    This routine has to be called before WaveReadFile as it searchs for the
    chunk to descend into for reading, that is, the 'data' chunk.  For
    simplicity, this used to be in the open routine, but was taken out and
    moved to a separate routine so there was more control on the chunks that
    are before the data chunk, such as 'fact', etc...
 */
MMRESULT WaveStartDataRead( void **phmmioIn, MMCKINFO *pckIn, MMCKINFO *pckInRIFF );

/**
  This will read wave data from the wave file.  Makre sure we're descended into
    the data chunk, else this will fail bigtime!
    hmmioIn         - Handle to mmio.
    cbRead          - # of bytes to read.
    pbDest          - Destination buffer to put bytes.
    cbActualRead- # of bytes actually read.
*/
MMRESULT WaveReadFile(
    HMMIO hmmioIn,
    UINT cbRead,
    BYTE *pbDest,
    MMCKINFO *pckIn,
    UINT *cbActualRead );

/**
 * This will close the wave file openned with WaveOpenFile.
    phmmioIn - Pointer to the handle to input MMIO.
    ppwfxSrc - Pointer to pointer to WaveFormatEx structure.
    Returns 0 if successful, non-zero if there was a warning.
*/
int WaveCloseReadFile( void **phmmio, WAVEFORMATEX **ppwfxSrc );

/**
 * This routine will create a wave file for writing.  This will automatically overwrite any
    existing file with the same name, so be careful and check before hand!!!
    pszFileName     - Pointer to filename to write.
    phmmioOut               - Pointer to HMMIO handle that is used for further writes
    pwfxDest                - Valid waveformatex destination structure.
    pckOut                  - Pointer to be set with the MMCKINFO.
    pckOutRIFF              - Pointer to be set with the RIFF info.
*/
MMRESULT WaveCreateFile(
    char *pszFileName,
    void **phmmioOut,
    WAVEFORMATEX *pwfxDest,
    MMCKINFO *pckOut,
    MMCKINFO *pckOutRIFF );

/**
 * This routine has to be called before any data is written to the wave output file, via wavewritefile.
 * This sets up the data to write, and creates the data chunk.
 */
MMRESULT WaveStartDataWrite(
    HMMIO *phmmioOut,
    MMCKINFO *pckOut,
    MMIOINFO *pmmioinfoOut );
//MMRESULT WaveStartDataWrite( void **phmmioOut, MMCKINFO *pckOut, MMIOINFO *pmmioinfoOut );

/**
 This routine will write out data to a wave file.
    hmmioOut                - Handle to hmmioOut filled by WaveCreateFile
    cbWrite                 - # of bytes to write out.
    pbSrc                   - Pointer to source.
    pckOut                  - pointer to ckOut filled by WaveCreateFile
    cbActualWrite   - # of actual bytes written.
    pmmioinfoOut    - Pointer to mmioinfoOut filled by WaveCreateFile.
    Returns 0 if successful, else the error code.
 */
MMRESULT WaveWriteFile(
    HMMIO hmmioOut,
    UINT cbWrite,
    BYTE *pbSrc,
    MMCKINFO *pckOut,
    UINT *cbActualWrite,
    MMIOINFO *pmmioinfoOut );
//MMRESULT WaveWriteFile( void *hmmioOut, unsigned int cbWrite, char *pbSrc, MMCKINFO *pckOut, unsigned int *cbActualWrite, MMIOINFO *pmmioinfoOut );

/**
  This routine will close a wave file used for writing.  Returns 0 if successful, else
    the error code.
    phmmioOut       - Pointer to mmio handle for saving.
    pckOut          - Pointer to the MMCKINFO for saving.
    pckOutRiff      - Pointer to the riff MMCKINFO for saving.
    pmmioinfoOut    - Pointer to mmioinfo for saving.
    cSamples        - # of samples saved, for the fact chunk.  For PCM, this isn't used but
                      will be written anyway, so this can be zero as long as programs ignore
                      this field when they load PCM formats.
 */
MMRESULT WaveCloseWriteFile(
    HMMIO *phmmioOut,
    MMCKINFO *pckOut,
    MMCKINFO *pckOutRIFF,
    MMIOINFO *pmmioinfoOut,
    DWORD cSamples );

/**
  This routine will copy from a source wave file to a destination wave file all those useless chunks
    (well, the ones useless to conversions, etc --> apparently people use them!).  The source will be
    seeked to the begining, but the destination has to be at a current pointer to put the new chunks.
    This will also seek     back to the start of the wave riff header at the end of the routine.
    phmmioIn                - Pointer to input mmio file handle.
    pckIn                   - Pointer to a nice ckIn to use.
    pckInRiff               - Pointer to the main riff.
    phmmioOut               - Pointer to output mmio file handle.
    pckOut                  - Pointer to nice ckOut to use.
    pckOutRiff              - Pointer to the main riff.
    Returns 0 if successful, else the error code.  If this routine fails, it still attemps to seek back to
    the start of the wave riff header, though this too could be unsuccessful.
 */
int WaveCopyUselessChunks(
    HMMIO *phmmioIn,
    MMCKINFO *pckIn,
    MMCKINFO *pckInRiff,
    HMMIO *phmmioOut,
    MMCKINFO *pckOut,
    MMCKINFO *pckOutRiff );
//int WaveCopyUselessChunks( void **phmmioIn, MMCKINFO *pckIn, MMCKINFO *pckInRiff, void **phmmioOut );

/**
 *
 */
BOOL riffCopyChunk( HMMIO hmmioSrc, HMMIO hmmioDst, const LPMMCKINFO lpck );
//LPVOID riffCopyChunk( void *hmmioSrc, void *hmmioDst, MMCKINFO *const lpck );

/**
 * @brief Loads a full wave file into memory.
 * @param szFileName
 * @param cbSize Size of loaded wave (returned).
 * @param cSamples Number of samples loaded.
 * @param ppwfxInfo Pointer to pointer to waveformatex structure. The wfx structure IS ALLOCATED by this routine! Make sure to free it!
 * @param ppbData Pointer to a byte pointer (globalalloc) which is allocated by this routine.  Make sure to free it!
 * @return Returns 0 on success or the error code on failure.
 */
MMRESULT WaveLoadFile(
    TCHAR *pszFileName,
    UINT *cbSize,
    WAVEFORMATEX **ppwfxInfo,
    BYTE **ppbData );

/**
 *
 */
/*
MMRESULT WaveLoadFile(
    TCHAR *pszFileName,
    UINT *cbSize,
    UINT *pcSamples,
    WAVEFORMATEX **ppwfxInfo,
    BYTE **ppbData );
*/

/**
 *
 */
MMRESULT WaveLoadFile(
    TCHAR *pszFileName,
    UINT *cbSize,
    WAVEFORMATEX **ppwfxInfo,
    BYTE **ppbData );

/**
 * @brief Saves a wave file currently in memory.
 * @param pszFileName FileName to save to. Automatically overwritten, be careful!
 * @param cbSize Size in bytes to write.
 * @param cSamples Number of samples to write, used to make the fact chunk. (if !PCM)
 * @param pwfxDest Pointer to waveformatex structure.
 * @param pbData Pointer to the data.
 */
MMRESULT WaveSaveFile(
    TCHAR *pszFileName,
    UINT cbSize,
    DWORD cSamples,
    WAVEFORMATEX *pwfxDest,
    BYTE *pbData );

#ifdef __cplusplus
}
#endif
