#pragma once

#include "IDA.h"

/**
 * @file    Engine\SoundObject.h
 * @author  Yvan Burrie
 * @date    2018/08/19
 * @version 1.0
 */

typedef struct
{
    /**
     * @brief Pointer into wave resource for restore.
     */
    BYTE *pbWaveData;

    /**
     * @brief Size of wave data for restore.
     */
    DWORD cbWaveSize;

    /**
     * @brief Number of buffers.
     */
    int iAlloc;

    /**
     * @brief Current buffer.
     */
    int iCurrent;

    /**
     * @brief List of buffers.
     */
    IDirectSoundBuffer* Buffers[1];

} SNDOBJ, *HSNDOBJ;

SNDOBJ *SndObjCreate( IDirectSound *pDS, char *lpName, int iConcurrent );

void SndObjDestroy( SNDOBJ *pSO );

IDirectSoundBuffer *SndObjGetFreeBuffer( SNDOBJ *pSO );

SNDOBJ *SndObjPlay( SNDOBJ *pSO, unsigned int dwPlayFlags );

int SndObjStop( SNDOBJ *pSO );
