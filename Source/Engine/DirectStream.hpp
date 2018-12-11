#pragma once

#include "IDA.h"

/**
 * @file    Engine\DirectStream.hpp
 * @author  Yvan Burrie
 * @date    2018/08/24
 * @version 1.0
 */

IDirectSoundBuffer *DSLoadSoundBuffer( IDirectSound *pDS, LPCTSTR lpName );

int DSReloadSoundBuffer( IDirectSoundBuffer *pDSB, LPCTSTR lpName );

int DSGetWaveResource( HMODULE hModule, LPCTSTR lpName, WAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize );

int DSFillSoundBuffer( IDirectSoundBuffer *pDSB, char *pbWaveData, unsigned int cbWaveSize );

int DSParseWaveResource( void *pvRes, WAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize );



BOOL ds_stream_init( HWND *hWnd, IDirectSound *lpd, IDirectSoundBuffer *lpb );

int ds_stream_exit();

BOOL ds_stream_file( CHAR *szName, char bLoop, int Volume );

int ds_stream_volume( int val );

int ds_stream_pause();

int ds_stream_resume();

int ds_stream_stop();

UINT ds_stream_messages( HWND *hWnd, UINT wMsg );

TIMECALLBACK ds_stream_time_func;
