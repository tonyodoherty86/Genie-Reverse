
/**
 * @file    Engine\DirectStream.hpp
 * @author  Yvan Burrie
 * @date    2018/08/19
 * @version 1.0
 */

IDirectSoundBuffer *DSLoadSoundBuffer( IDirectSound *pDS, char *lpName );

int DSReloadSoundBuffer( IDirectSoundBuffer *pDSB, char *lpName );

int DSGetWaveResource( void *hModule, char *lpName, WAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize );

int DSFillSoundBuffer( IDirectSoundBuffer *pDSB, char *pbWaveData, unsigned int cbWaveSize );

int DSParseWaveResource( void *pvRes, WAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize );



int ds_stream_init( HWND *hWnd, IDirectSound *lpd, IDirectSoundBuffer *lpb );

int ds_stream_exit();

int ds_stream_file( char *szName, char bLoop, int Volume );

int ds_stream_volume( int val );

int ds_stream_pause();

int ds_stream_resume();

int ds_stream_stop();

unsigned int ds_stream_messages( HWND *hWnd, UINT wMsg );

TIMECALLBACK ds_stream_time_func;
