
/**
 * @file    Engine\DirectStream.cpp
 * @author  Yvan Burrie
 * @date    2018/08/19
 * @version 1.0
 */

int bTimerInstalled;
int bFileOpen;

/**
 *
 */
IDirectSoundBuffer *DSLoadSoundBuffer( IDirectSound *pDS, LPCTSTR lpName )
{
    IDirectSoundBuffer *pDSB = NULL;
    DSBUFFERDESC dsBD = {0};
    BYTE *pbWaveData;

    if( DSGetWaveResource(NULL, lpName, &dsBD.lpwfxFormat, &pbWaveData, &dsBD.dwBufferBytes) ){

        dsBD.dwSize  = sizeof(dsBD);
        dsBD.dwFlags = DSBCAPS_STATIC|DSBCAPS_GETCURRENTPOSITION2;

        if( SUCCEEDED(IDirectSound_CreateSoundBuffer(pDS, &dsBD, &pDSB, NULL)) ){
            if( DSFillSoundBuffer(pDSB, pbWaveData, dsBD.dwBufferBytes) == 0 ){
                IDirectSoundBuffer_Release(pDSB);
                pDSB = NULL;
            }
        }else{
            pDSB = NULL;
        }
    }

    if( NULL == pDSB ){
        OutputDebugString("Could not load sound buffer!\n");
    }

    return pDSB;
}

/**
 *
 */
BOOL DSReloadSoundBuffer( IDirectSoundBuffer *pDSB, LPCTSTR lpName )
{
    BOOL result = FALSE;
    BYTE *pbWaveData;
    DWORD cbWaveSize;

    if( DSGetWaveResource(NULL, lpName, NULL, &pbWaveData, &cbWaveSize) ){
        if( SUCCEEDED(IDirectSoundBuffer_Restore(pDSB)) && DSFillSoundBuffer(pDSB, pbWaveData, cbWaveSize) ){
            result = TRUE;
        }
    }

    if( FALSE == result ){
        OutputDebugString("Could not reload sound buffer!\n");
    }

    return result;
}

/**
 *
 */
BOOL DSGetWaveResource( HMODULE hModule, LPCTSTR lpName, WAVEFORMATEX **ppWaveHeader, BYTE **ppbWaveData, DWORD *pcbWaveSize )
{
    HRSRC hResInfo;
    HGLOBAL hResData;
    void *pvRes;

    if( ((hResInfo = FindResource(hModule, lpName, c_szWAV)) != NULL) &&
        ((hResData = LoadResource(hModule, hResInfo)) != NULL) &&
        ((pvRes = LockResource(hResData)) != NULL) &&
        DSParseWaveResource(pvRes, ppWaveHeader, ppbWaveData, pcbWaveSize) ){
        return TRUE;
    }else{
        OutputDebugString("Could not get wave resource!\n");
        return FALSE;
    }
}

BOOL DSFillSoundBuffer(IDirectSoundBuffer *pDSB, BYTE *pbWaveData, DWORD cbWaveSize)
{
    if( pDSB && pbWaveData && cbWaveSize ){

        LPVOID pMem1, pMem2;
        DWORD dwSize1, dwSize2;

        if( SUCCEEDED(IDirectSoundBuffer_Lock(pDSB, 0, cbWaveSize, &pMem1, &dwSize1, &pMem2, &dwSize2, 0)) ){

            CopyMemory(pMem1, pbWaveData, dwSize1);

            if( 0 != dwSize2 ){
                CopyMemory(pMem2, pbWaveData+dwSize1, dwSize2);
            }

            IDirectSoundBuffer_Unlock(pDSB, pMem1, dwSize1, pMem2, dwSize2);

            return TRUE;
        }
    }

    OutputDebugString("Could not fill sound buffer!\n");

    return FALSE;
}

BOOL DSParseWaveResource( void *pvRes, WAVEFORMATEX **ppWaveHeader, BYTE **ppbWaveData,DWORD *pcbWaveSize )
{
    if( ppWaveHeader ){
        *ppWaveHeader = NULL;
    }

    if( ppbWaveData ){
        *ppbWaveData = NULL;
    }

    if( pcbWaveSize ){
        *pcbWaveSize = 0;
    }

    DWORD *pdw     = (DWORD *)pvRes;
    DWORD dwRiff   = *pdw++;
    DWORD dwLength = *pdw++;
    DWORD dwType   = *pdw++;

    if( dwRiff != mmioFOURCC('R', 'I', 'F', 'F') ){
        goto exit; /* not a RIFF */
    }

    if( dwType != mmioFOURCC('W', 'A', 'V', 'E') ){
        goto exit; /* not a WAV */
    }

    DWORD *pdwEnd = (DWORD *)((BYTE *)pdw + dwLength - 4);

    while( pdw < pdwEnd ){

        dwType   = *pdw++;
        dwLength = *pdw++;

        switch( dwType ){

        case mmioFOURCC('f', 'm', 't', ' '):

            if( ppWaveHeader && !*ppWaveHeader ){

                if( dwLength < sizeof(WAVEFORMAT) ){
                    goto exit; /* not a WAV */
                }

                *ppWaveHeader = (WAVEFORMATEX *)pdw;

                if( (!ppbWaveData || *ppbWaveData) &&
                    (!pcbWaveSize || *pcbWaveSize) ){
                    return TRUE;
                }
            }
            break;

        case mmioFOURCC('d', 'a', 't', 'a'):

            if( (ppbWaveData && !*ppbWaveData) ||
                (pcbWaveSize && !*pcbWaveSize) ){

                if( ppbWaveData ){
                    *ppbWaveData = (LPBYTE)pdw;
                }

                if( pcbWaveSize ){
                    *pcbWaveSize = dwLength;
                }

                if( !ppWaveHeader || *ppWaveHeader ){
                    return TRUE;
                }
            }
            break;
        }

        pdw = (DWORD *)((BYTE *)pdw + ((dwLength + 1) & ~1));
    }

    exit:
    OutputDebugString( "Could not parse wave resource!\n" );

    return FALSE;
}

#include "SoundObject.c"
#include "Wave.c"

int ds_stream_init( HWND *hWnd, IDirectSound *lpd, IDirectSoundBuffer *lpb )
{
    int result; // eax@1

    uLastPercent = 100;
    lpDSBStreamBuffer = 0;
    bFileOpen = 0;
    bPlaying = 0;
    bTimerInstalled = 0;
    uTimerID = 0;
    main_wnd = hWnd;
    result = 1;
    lpBuffer = (int)lpb;
    lpDS = (int)lpd;
    ds_ready = 1;
    return result;
}

int ds_stream_exit()
{
    int result; // eax@1

    result = ds_ready;
    if( ds_ready )
    {
        if( bFileOpen || bPlaying || (result = bTimerInstalled) != 0 )
            result = ds_stream_stop();
        ds_ready = 0;
    }
    return result;
}

int ds_stream_file( char *szName, char bLoop, int Volume )
{
    int result; // eax@6
    unsigned int v4; // esi@15
    unsigned int v5; // ecx@16
    char *v6; // edi@18
    unsigned int dwLen1; // [sp+30h] [bp-28h]@13
    char *lpWrite1; // [sp+34h] [bp-24h]@13
    unsigned int uChkErr; // [sp+38h] [bp-20h]@16
    char *lpWrite2; // [sp+3Ch] [bp-1Ch]@13
    unsigned int dwLen2; // [sp+40h] [bp-18h]@13
    _DSBUFFERDESC dsbd; // [sp+44h] [bp-14h]@11

    if( bFileOpen || bPlaying || bTimerInstalled )
        ds_stream_stop();
    stream_paused = 0;
    if( WaveOpenFile(szName, &hmmioIn, &wiWave, &pckInRIFF) )
    {
        result = 0;
    }
    else if( wiWave->wFormatTag == 1 )
    {
        if( WaveStartDataRead(&hmmioIn, &pckIn, &pckInRIFF) )
        {
            WaveCloseReadFile(&hmmioIn, &wiWave);
            result = 0;
        }
        else
        {
            dword_888498 = 120 * wiWave->nAvgBytesPerSec / 0x64 / 6;
            dword_888494 = 6 * dword_888498;
            memset(&dsbd, 0, 0x14u);
            dsbd.lpwfxFormat = wiWave;
            dsbd.dwSize = 20;
            dsbd.dwFlags = 224;
            dsbd.dwBufferBytes = 6 * dword_888498;
            if( (*(int (__stdcall **)(int, _DSBUFFERDESC *, int *, _DWORD))(*(_DWORD *)lpDS + 12))(
                         lpDS,
                         &dsbd,
                         &lpDSBStreamBuffer,
                         0) )
            {
                result = 0;
            }
            else
            {
                dword_888490 = lpDSBStreamBuffer;
                dword_8884B0 = 0;
                dword_8884B4 = 0;
                if( (*(int (__stdcall **)(int, _DWORD, int, char **, unsigned int *, char **, unsigned int *, _DWORD))(*(_DWORD *)lpDSBStreamBuffer + 44))(
                             lpDSBStreamBuffer,
                             0,
                             dword_888494,
                             &lpWrite1,
                             &dwLen1,
                             &lpWrite2,
                             &dwLen2,
                             0) )
                {
                    result = 0;
                }
                else
                {
                    v4 = dwLen1;
                    if( dwLen1 )
                    {
                        WaveReadFile(hmmioIn, dwLen1, lpWrite1, &pckIn, &uChkErr);
                        v5 = uChkErr;
                        v4 = dwLen1;
                        if( uChkErr < dwLen1 )
                        {
                            if( dword_8884AC )
                            {
                                v6 = lpWrite1;
                                do
                                {
                                    v6 += v5;
                                    dwLen1 = v4 - v5;
                                    WaveStartDataRead(&hmmioIn, &pckIn, &pckInRIFF);
                                    WaveReadFile(hmmioIn, dwLen1, v6, &pckIn, &uChkErr);
                                    v5 = uChkErr;
                                    v4 = dwLen1;
                                }
                                while( uChkErr < dwLen1 );
                            }
                            else
                            {
                                dword_8884B0 = 1;
                                dword_8884B4 = uChkErr / dword_888498;
                                memset(&lpWrite1[uChkErr], wiWave->wBitsPerSample != 8 ? 0 : 0x80, dwLen1 - uChkErr);
                                v4 = dwLen1;
                            }
                        }
                    }
                    (*(void (__stdcall **)(int, char *, unsigned int, char *, _DWORD))(*(_DWORD *)lpDSBStreamBuffer + 76))(
                        lpDSBStreamBuffer,
                        lpWrite1,
                        v4,
                        lpWrite2,
                        0);
                    dword_8884A4 = 0;
                    dword_8884A0 = 0;
                    dword_88849C = 0;
                    dword_8884A8 = 0;
                    dword_8884AC = (unsigned __int8)bLoop;
                    bFileOpen = 1;
                    SendMessageA(main_wnd, 0x502u, 0, 0);
                    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)lpDSBStreamBuffer + 52))(lpDSBStreamBuffer, 0);
                    (*(void (__stdcall **)(int, int))(*(_DWORD *)lpDSBStreamBuffer + 60))(lpDSBStreamBuffer, Volume);
                    (*(void (__stdcall **)(int, _DWORD, _DWORD, signed int))(*(_DWORD *)lpDSBStreamBuffer + 48))(
                        lpDSBStreamBuffer,
                        0,
                        0,
                        1);
                    if( timeBeginPeriod(0x32u) )
                    {
                        (*(void (__stdcall **)(int))(*(_DWORD *)lpDSBStreamBuffer + 72))(lpDSBStreamBuffer);
                        bTimerInstalled = 0;
                        bPlaying = 0;
                        result = 0;
                    }
                    else
                    {
                        uTimerID = timeSetEvent(0x32u, 0xAu, ds_stream_time_func, 0, 1u);
                        if( uTimerID )
                            bTimerInstalled = 1;
                        bPlaying = 1;
                        result = 1;
                    }
                }
            }
        }
    }
    else
    {
        WaveCloseReadFile(&hmmioIn, &wiWave);
        result = 0;
    }
    return result;
}

int ds_stream_volume( int val )
{
    int result; // eax@1

    result = lpDSBStreamBuffer;
    if( lpDSBStreamBuffer )
        result = (*(int (__stdcall **)(int, int))(*(_DWORD *)lpDSBStreamBuffer + 60))(lpDSBStreamBuffer, val) == 0;
    return result;
}

int ds_stream_pause()
{
    int result; // eax@1

    result = 1;
    stream_paused = 1;
    return result;
}

int ds_stream_resume()
{
    stream_paused = 0;
    return 1;
}

int ds_stream_stop()
{
    int v0; // eax@4

    dword_8884A8 = 1;
    if( bTimerInstalled )
    {
        bTimerInstalled = 0;
        timeKillEvent(uTimerID);
        timeEndPeriod(0x32u);
    }
    if( bPlaying )
    {
        v0 = lpDSBStreamBuffer;
        bPlaying = 0;
        if( !lpDSBStreamBuffer )
            goto LABEL_7;
        (*(void (__stdcall **)(int))(*(_DWORD *)lpDSBStreamBuffer + 72))(lpDSBStreamBuffer);
    }
    v0 = lpDSBStreamBuffer;
LABEL_7:
    if( bFileOpen )
    {
        if( wiWave )
        {
            WaveCloseReadFile(&hmmioIn, &wiWave);
            v0 = lpDSBStreamBuffer;
            wiWave = 0;
        }
        if( v0 )
        {
            (*(void (__stdcall **)(int))(*(_DWORD *)v0 + 8))(v0);
            lpDSBStreamBuffer = 0;
            dword_888490 = 0;
        }
        bFileOpen = 0;
    }
    return 1;
}

unsigned int ds_stream_messages( HWND *hWnd, unsigned int wMsg )
{
    unsigned int v2; // eax@3
    signed __int64 v3; // rax@5

    if( wMsg == 1280 )
    {
        ds_stream_stop();
    }
    else if( wMsg == 1282 )
    {
        v2 = dword_8884A4;
        if( dword_8884A4 > pckInRIFF.cksize )
        {
            v2 = dword_8884A4 - pckInRIFF.cksize;
            dword_8884A4 -= pckInRIFF.cksize;
        }
        v3 = (signed __int64)(double)(100 * v2 / pckInRIFF.cksize);
        if( (_DWORD)v3 != uLastPercent )
        {
            uLastPercent = v3;
            return 0;
        }
    }
    return 0;
}

void ds_stream_time_func( UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2 )
{
    unsigned int v5; // edx@12
    int v6; // edx@14
    unsigned __int16 v7; // ax@21
    int v8; // ecx@25
    int v9; // eax@25
    unsigned int v10; // eax@31
    unsigned __int16 v11; // cx@35
    char *v12; // esi@42
    unsigned int v13; // ecx@50
    unsigned int v14; // eax@52
    unsigned __int16 v15; // dx@56
    char *v16; // esi@64
    unsigned int dwLen1; // [sp+2Ch] [bp-1Ch]@18
    unsigned int dwLen2; // [sp+30h] [bp-18h]@18
    char *lpWrite1; // [sp+34h] [bp-14h]@18
    unsigned int uChkErr; // [sp+38h] [bp-10h]@31
    char *lpWrite2; // [sp+3Ch] [bp-Ch]@18
    unsigned int dwPlay; // [sp+40h] [bp-8h]@5
    unsigned int dwWrite; // [sp+44h] [bp-4h]@5

    if( !bInTimer && !stream_paused )
    {
        bInTimer = 1;
        if( dword_8884A8 )
            goto LABEL_76;
        if( !dword_888490 )
            goto LABEL_76;
        (*(void (__stdcall **)(int, unsigned int *, unsigned int *))(*(_DWORD *)dword_888490 + 16))(
            dword_888490,
            &dwPlay,
            &dwWrite);
        if( dword_88849C < dwPlay && dword_888498 + dword_88849C > dwPlay )
            goto LABEL_76;
        if( dword_8884B0 && !dword_8884B4 )
        {
            if( !dword_8884A8 )
            {
                dword_8884A8 = 1;
                PostMessageA(main_wnd, 0x500u, 0, 0);
                bInTimer = 0;
                return;
            }
            goto LABEL_76;
        }
        if( dwPlay >= dword_8884A0 )
            v5 = dwPlay;
        else
            v5 = dwPlay + dword_888494;
        v6 = v5 - dword_8884A0;
        dword_8884A0 = dwPlay;
        dword_8884A4 += v6;
        PostMessageA(main_wnd, 0x502u, 0, 0);
        if( dword_8884B0 && dword_8884B4 )
        {
            if( --dword_8884B4 <= 1
                || !dword_888490
                || (*(int (__stdcall **)(int, int, int, char **, unsigned int *, char **, unsigned int *, _DWORD))(*(_DWORD *)dword_888490 + 44))(
                         dword_888490,
                         dword_88849C,
                         dword_888498,
                         &lpWrite1,
                         &dwLen1,
                         &lpWrite2,
                         &dwLen2,
                         0) )
            {
                goto LABEL_76;
            }
            if( wiWave && lpWrite1 )
            {
                v7 = wiWave->wBitsPerSample;
                if( v7 == 8 )
                {
                    memset(lpWrite1, 128, dwLen1);
                }
                else if( v7 == 16 )
                {
                    memset(lpWrite1, 0, dwLen1);
                }
            }
            (*(void (__stdcall **)(int, char *, unsigned int, char *, unsigned int))(*(_DWORD *)dword_888490 + 76))(
                dword_888490,
                lpWrite1,
                dwLen1,
                lpWrite2,
                dwLen2);
            v8 = dword_888494;
            v9 = dword_888498 + dword_88849C;
            dword_88849C += dword_888498;
            if( dword_88849C < (unsigned int)dword_888494 )
                goto LABEL_76;
            goto LABEL_75;
        }
        if( !dword_888490
            || (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_888490
                                                                                                                                                                                            + 44))(
                     dword_888490,
                     dword_88849C,
                     dword_888498,
                     &lpWrite1,
                     &dwLen1,
                     &lpWrite2,
                     &dwLen2,
                     0) )
        {
            goto LABEL_76;
        }
        if( !dwLen1 || dword_8884A8 )
        {
            if( dwLen1 && dword_8884A8 && wiWave && lpWrite1 )
                memset(lpWrite1, wiWave->wBitsPerSample != 8 ? 0 : 0x80, dwLen1);
        }
        else
        {
            WaveReadFile(hmmioIn, dwLen1, lpWrite1, &pckIn, &uChkErr);
            v10 = uChkErr;
            if( uChkErr < dwLen1 )
            {
                if( dword_8884AC )
                {
                    v12 = lpWrite1;
                    if( lpWrite1 )
                    {
                        do
                        {
                            v12 += v10;
                            dwLen1 -= v10;
                            WaveStartDataRead(&hmmioIn, &pckIn, &pckInRIFF);
                            WaveReadFile(hmmioIn, dwLen1, v12, &pckIn, &uChkErr);
                            v10 = uChkErr;
                        }
                        while( uChkErr < dwLen1 );
                    }
                }
                else
                {
                    if( wiWave && lpWrite1 )
                    {
                        v11 = wiWave->wBitsPerSample;
                        if( v11 == 8 )
                        {
                            memset(&lpWrite1[uChkErr], 128, dwLen1 - uChkErr);
                        }
                        else if( v11 == 16 )
                        {
                            memset(&lpWrite1[uChkErr], 0, dwLen1 - uChkErr);
                        }
                    }
                    dword_8884B0 = 1;
                    if( dwPlay <= dword_88849C )
                        dword_8884B4 = (dword_88849C - dwPlay) / dword_888498;
                    else
                        dword_8884B4 = (dword_888494 + dword_88849C - dwPlay) / dword_888498;
                }
            }
        }
        v13 = dwLen2;
        if( dwLen2 )
        {
            if( dword_8884A8 )
            {
                if( dwLen2 && dword_8884A8 && wiWave && lpWrite2 )
                {
                    memset(lpWrite2, wiWave->wBitsPerSample != 8 ? 0 : 0x80, dwLen2);
                    v13 = dwLen2;
                }
            }
            else
            {
                WaveReadFile(hmmioIn, dwLen2, lpWrite2, &pckIn, &uChkErr);
                v14 = uChkErr;
                v13 = dwLen2;
                if( uChkErr >= dwLen2 )
                    goto LABEL_72;
                if( !dword_8884AC )
                {
                    if( !wiWave || !lpWrite2 )
                        goto LABEL_61;
                    v15 = wiWave->wBitsPerSample;
                    if( v15 == 8 )
                    {
                        memset(&lpWrite2[uChkErr], 128, dwLen2 - uChkErr);
                    }
                    else
                    {
                        if( v15 != 16 )
                            goto LABEL_61;
                        memset(&lpWrite2[uChkErr], 0, dwLen2 - uChkErr);
                    }
                    v13 = dwLen2;
LABEL_61:
                    dword_8884B0 = 1;
                    if( dwPlay <= dword_88849C )
                        dword_8884B4 = (dword_88849C - dwPlay) / dword_888498;
                    else
                        dword_8884B4 = (dword_888494 + dword_88849C - dwPlay) / dword_888498;
                    goto LABEL_72;
                }
                v16 = lpWrite2;
                if( lpWrite2 )
                {
                    do
                    {
                        v16 += v14;
                        dwLen2 = v13 - v14;
                        WaveStartDataRead(&hmmioIn, &pckIn, &pckInRIFF);
                        WaveReadFile(hmmioIn, dwLen2, v16, &pckIn, &uChkErr);
                        v14 = uChkErr;
                        v13 = dwLen2;
                    }
                    while( uChkErr < dwLen2 );
                }
            }
        }
LABEL_72:
        if( dword_888490 )
            (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, unsigned int))(*(_DWORD *)dword_888490 + 76))(
                dword_888490,
                lpWrite1,
                dwLen1,
                lpWrite2,
                v13);
        v8 = dword_888494;
        v9 = dword_888498 + dword_88849C;
        dword_88849C += dword_888498;
        if( dword_88849C < (unsigned int)dword_888494 )
            goto LABEL_76;
LABEL_75:
        dword_88849C = v9 - v8;
LABEL_76:
        bInTimer = 0;
    }
}
