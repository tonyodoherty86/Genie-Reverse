
/**
 * @file    Engine\DirectStream.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

struct SNDOBJ
{
  char *pbWaveData;
  unsigned int cbWaveSize;
  int iAlloc;
  int iCurrent;
  IDirectSoundBuffer *Buffers[1];
};

IDirectSoundBuffer *DSLoadSoundBuffer(IDirectSound *pDS, char *lpName);
int DSReloadSoundBuffer(IDirectSoundBuffer *pDSB, char *lpName);
int DSGetWaveResource(void *hModule, char *lpName, WAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize);
SNDOBJ *SndObjCreate(IDirectSound *pDS, char *lpName, int iConcurrent);
void SndObjDestroy(SNDOBJ *pSO);
IDirectSoundBuffer *SndObjGetFreeBuffer(SNDOBJ *pSO);
SNDOBJ *SndObjPlay(SNDOBJ *pSO, unsigned int dwPlayFlags);
int SndObjStop(SNDOBJ *pSO);
int DSFillSoundBuffer(IDirectSoundBuffer *pDSB, char *pbWaveData, unsigned int cbWaveSize);
int DSParseWaveResource(void *pvRes, WAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize);

MMRESULT WaveOpenFile(char *pszFileName, void **phmmioIn, WAVEFORMATEX **ppwfxInfo, MMCKINFO *pckInRIFF);
MMRESULT WaveStartDataRead(void **phmmioIn, MMCKINFO *pckIn, MMCKINFO *pckInRIFF);
int WaveReadFile(void *hmmioIn, unsigned int cbRead, char *pbDest, MMCKINFO *pckIn, unsigned int *cbActualRead);
int WaveCloseReadFile(void **phmmio, WAVEFORMATEX **ppwfxSrc);
MMRESULT WaveCreateFile(char *pszFileName, void **phmmioOut, WAVEFORMATEX *pwfxDest, MMCKINFO *pckOut, MMCKINFO *pckOutRIFF);
MMRESULT WaveStartDataWrite(void **phmmioOut, MMCKINFO *pckOut, MMIOINFO *pmmioinfoOut);
MMRESULT WaveWriteFile(void *hmmioOut, unsigned int cbWrite, char *pbSrc, MMCKINFO *pckOut, unsigned int *cbActualWrite, MMIOINFO *pmmioinfoOut);
MMRESULT WaveCloseWriteFile(void **phmmioOut, MMCKINFO *pckOut, MMCKINFO *pckOutRIFF, MMIOINFO *pmmioinfoOut, unsigned int cSamples);
int WaveCopyUselessChunks(void **phmmioIn, MMCKINFO *pckIn, MMCKINFO *pckInRiff, void **phmmioOut);
LPVOID riffCopyChunk(void *hmmioSrc, void *hmmioDst, MMCKINFO *const lpck);
MMRESULT WaveLoadFile(char *pszFileName, unsigned int *cbSize, unsigned int *pcSamples, WAVEFORMATEX **ppwfxInfo, char **ppbData);
MMRESULT WaveSaveFile(char *pszFileName, unsigned int cbSize, unsigned int cSamples, WAVEFORMATEX *pwfxDest, char *pbData);

int ds_stream_init(HWND *hWnd, IDirectSound *lpd, IDirectSoundBuffer *lpb);
int ds_stream_exit();
int ds_stream_file(char *szName, char bLoop, int Volume);
int ds_stream_volume(int val);
int ds_stream_pause();
int ds_stream_resume();
int ds_stream_stop();
unsigned int ds_stream_messages(HWND *hWnd, UINT wMsg);
TIMECALLBACK ds_stream_time_func;
