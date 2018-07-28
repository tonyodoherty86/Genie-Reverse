
//----- (004477E0) --------------------------------------------------------
IDirectSoundBuffer *__cdecl DSLoadSoundBuffer(IDirectSound *pDS, char *lpName)
{
  IUnknownVtbl *v2; // edx@2
  IDirectSoundBuffer *pDSB; // [sp+10h] [bp-18h]@1
  _DSBUFFERDESC dsBD; // [sp+14h] [bp-14h]@1

  dsBD.dwFlags = 0;
  dsBD.dwBufferBytes = 0;
  dsBD.dwReserved = 0;
  dsBD.lpwfxFormat = 0;
  pDSB = 0;
  dsBD.dwSize = 0;
  if( DSGetWaveResource(0, lpName, &dsBD.lpwfxFormat, &lpName, &dsBD.dwBufferBytes) )
  {
    v2 = pDS->vfptr;
    dsBD.dwSize = 20;
    dsBD.dwFlags = 226;
    if( ((int (__stdcall *)(IDirectSound *, _DSBUFFERDESC *, IDirectSoundBuffer **, _DWORD))v2[1].QueryInterface)(
           pDS,
           &dsBD,
           &pDSB,
           0) < 0 )
      return 0;
    if( !DSFillSoundBuffer(pDSB, lpName, dsBD.dwBufferBytes) )
    {
      pDSB->vfptr->Release((IUnknown *)pDSB);
      return 0;
    }
  }
  return pDSB;
}

//----- (00447890) --------------------------------------------------------
int __cdecl DSReloadSoundBuffer(IDirectSoundBuffer *pDSB, char *lpName)
{
  signed int v2; // esi@1
  char *pbWaveData; // [sp+8h] [bp-4h]@1

  v2 = 0;
  if( DSGetWaveResource(0, lpName, 0, &pbWaveData, (unsigned int *)&lpName)
    && (pDSB->vfptr[6].Release((IUnknown *)pDSB) & 0x80000000) == 0
    && DSFillSoundBuffer(pDSB, pbWaveData, (unsigned int)lpName) )
  {
    v2 = 1;
  }
  return v2;
}

//----- (004478F0) --------------------------------------------------------
int __cdecl DSGetWaveResource(void *hModule, char *lpName, tWAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize)
{
  HRSRC v5; // eax@1
  HGLOBAL v6; // eax@2
  void *v7; // eax@3
  int result; // eax@5

  v5 = FindResourceA(hModule, lpName, "WAV");
  result = 0;
  if( v5 )
  {
    v6 = LoadResource(hModule, v5);
    if( v6 )
    {
      v7 = LockResource(v6);
      if( v7 )
      {
        if( DSParseWaveResource(v7, ppWaveHeader, ppbWaveData, pcbWaveSize) )
          result = 1;
      }
    }
  }
  return result;
}

//----- (00447950) --------------------------------------------------------
SNDOBJ *__cdecl SndObjCreate(IDirectSound *pDS, char *lpName, int iConcurrent)
{
  SNDOBJ *v3; // esi@1
  int v4; // edi@2
  signed int v5; // ebp@2
  SNDOBJ *v6; // eax@4
  _DWORD *v7; // edi@6
  IDirectSoundBuffer *v8; // eax@8
  char *pbData; // [sp+10h] [bp-Ch]@1
  unsigned int cbData; // [sp+14h] [bp-8h]@1
  tWAVEFORMATEX *pWaveHeader; // [sp+18h] [bp-4h]@1

  v3 = 0;
  if( DSGetWaveResource(0, lpName, &pWaveHeader, &pbData, &cbData) )
  {
    v4 = iConcurrent;
    v5 = 1;
    if( iConcurrent < 1 )
      v4 = 1;
    v6 = (SNDOBJ *)LocalAlloc(0x40u, 4 * v4 + 16);
    v3 = v6;
    if( v6 )
    {
      v6->iAlloc = v4;
      v6->pbWaveData = pbData;
      v6->cbWaveSize = cbData;
      v6->Buffers[0] = DSLoadSoundBuffer(pDS, lpName);
      if( v3->iAlloc > 1 )
      {
        v7 = &v3[1].pbWaveData;
        while( 1 )
        {
          if( ((int (__stdcall *)(IDirectSound *, IDirectSoundBuffer *, _DWORD *))pDS->vfptr[1].Release)(
                 pDS,
                 v3->Buffers[0],
                 v7) < 0 )
          {
            v8 = DSLoadSoundBuffer(pDS, lpName);
            *v7 = v8;
            if( !v8 )
              break;
          }
          ++v5;
          ++v7;
          if( v5 >= v3->iAlloc )
            return v3;
        }
        SndObjDestroy(v3);
        v3 = 0;
      }
    }
  }
  return v3;
}

//----- (00447A20) --------------------------------------------------------
void __cdecl SndObjDestroy(SNDOBJ *pSO)
{
  int v1; // edi@2
  char *v2; // esi@3

  if( pSO )
  {
    v1 = 0;
    if( pSO->iAlloc > 0 )
    {
      v2 = (char *)pSO->Buffers;
      do
      {
        if( *(_DWORD *)v2 )
        {
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v2 + 8))(*(_DWORD *)v2);
          *(_DWORD *)v2 = 0;
        }
        ++v1;
        v2 += 4;
      }
      while( v1 < pSO->iAlloc );
    }
    LocalFree(pSO);
  }
}

//----- (00447A60) --------------------------------------------------------
IDirectSoundBuffer *__cdecl SndObjGetFreeBuffer(SNDOBJ *pSO)
{
  SNDOBJ *v1; // edi@1
  IDirectSoundBuffer *result; // eax@2
  IDirectSoundBuffer *v3; // esi@3
  signed int v4; // eax@7
  int v5; // ecx@8

  v1 = pSO;
  if( pSO )
  {
    v3 = pSO->Buffers[pSO->iCurrent];
    if( v3 )
    {
      if( ((int (__stdcall *)(IDirectSoundBuffer *, SNDOBJ **))v3->vfptr[3].QueryInterface)(v3, &pSO) < 0 )
        pSO = 0;
      if( ((unsigned __int8)pSO & 1) == 1 )
      {
        v4 = v1->iAlloc;
        if( v4 <= 1 )
        {
          v3 = 0;
        }
        else
        {
          v5 = v1->iCurrent + 1;
          v1->iCurrent = v5;
          if( v5 >= v4 )
            v1->iCurrent = 0;
          v3 = v1->Buffers[v1->iCurrent];
          if( ((int (__stdcall *)(IDirectSoundBuffer *, SNDOBJ **))v3->vfptr[3].QueryInterface)(v3, &pSO) >= 0
            && ((unsigned __int8)pSO & 1) == 1 )
          {
            ((void (__stdcall *)(IDirectSoundBuffer *))v3->vfptr[6].QueryInterface)(v3);
            ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD))v3->vfptr[4].AddRef)(v3, 0);
          }
        }
      }
      if( v3
        && (unsigned __int8)pSO & 2
        && ((v3->vfptr[6].Release((IUnknown *)v3) & 0x80000000) != 0
         || !DSFillSoundBuffer(v3, v1->pbWaveData, v1->cbWaveSize)) )
      {
        v3 = 0;
      }
    }
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00447B20) --------------------------------------------------------
SNDOBJ *__cdecl SndObjPlay(SNDOBJ *pSO, unsigned int dwPlayFlags)
{
  SNDOBJ *result; // eax@1
  SNDOBJ *v3; // esi@1
  IDirectSoundBuffer *v4; // eax@4

  result = pSO;
  v3 = 0;
  if( pSO )
  {
    if( !(dwPlayFlags & 1) || pSO->iAlloc == 1 )
    {
      v4 = SndObjGetFreeBuffer(pSO);
      if( v4 )
        v3 = (SNDOBJ *)(((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, _DWORD, unsigned int))v4->vfptr[4].QueryInterface)(
                          v4,
                          0,
                          0,
                          dwPlayFlags) >= 0);
    }
    result = v3;
  }
  return result;
}

//----- (00447B70) --------------------------------------------------------
int __cdecl SndObjStop(SNDOBJ *pSO)
{
  int result; // eax@2
  int v2; // edi@3
  char *v3; // esi@4

  if( pSO )
  {
    v2 = 0;
    if( pSO->iAlloc > 0 )
    {
      v3 = (char *)pSO->Buffers;
      do
      {
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v3 + 72))(*(_DWORD *)v3);
        (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)v3 + 52))(*(_DWORD *)v3, 0);
        ++v2;
        v3 += 4;
      }
      while( v2 < pSO->iAlloc );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00447BC0) --------------------------------------------------------
int __cdecl DSFillSoundBuffer(IDirectSoundBuffer *pDSB, char *pbWaveData, unsigned int cbWaveSize)
{
  IDirectSoundBuffer *v3; // esi@1
  char *v4; // edi@2
  char *v5; // eax@5
  int result; // eax@7
  void *pMem1; // [sp+20h] [bp-4h]@4

  v3 = pDSB;
  if( pDSB
    && (v4 = pbWaveData) != 0
    && cbWaveSize
    && ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, void **, IDirectSoundBuffer **, unsigned int *, char **, _DWORD))pDSB->vfptr[3].Release)(
         pDSB,
         0,
         cbWaveSize,
         &pMem1,
         &pDSB,
         &cbWaveSize,
         &pbWaveData,
         0) >= 0 )
  {
    memcpy(pMem1, v4, (size_t)pDSB);
    v5 = pbWaveData;
    if( pbWaveData )
    {
      memcpy((void *)cbWaveSize, (char *)pDSB + (_DWORD)v4, (size_t)pbWaveData);
      v5 = pbWaveData;
    }
    ((void (__stdcall *)(IDirectSoundBuffer *, void *, IDirectSoundBuffer *, unsigned int, char *))v3->vfptr[6].AddRef)(
      v3,
      pMem1,
      pDSB,
      cbWaveSize,
      v5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00447C60) --------------------------------------------------------
int __cdecl DSParseWaveResource(void *pvRes, tWAVEFORMATEX **ppWaveHeader, char **ppbWaveData, unsigned int *pcbWaveSize)
{
  char *v4; // eax@7
  unsigned int v5; // esi@9
  int v6; // ecx@10
  unsigned int v7; // edx@10
  tWAVEFORMATEX *v8; // eax@10

  if( ppWaveHeader )
    *ppWaveHeader = 0;
  if( ppbWaveData )
    *ppbWaveData = 0;
  if( pcbWaveSize )
    *pcbWaveSize = 0;
  v4 = (char *)pvRes + 12;
  if( *(_DWORD *)pvRes == 1179011410 && *((_DWORD *)pvRes + 2) == 1163280727 )
  {
    v5 = (unsigned int)&v4[*((_DWORD *)pvRes + 1) - 4];
    if( (unsigned int)v4 < v5 )
    {
      while( 1 )
      {
        v6 = *(_DWORD *)v4;
        v7 = *((_DWORD *)v4 + 1);
        v8 = (tWAVEFORMATEX *)(v4 + 8);
        if( v6 == 544501094 )
        {
          if( ppWaveHeader && !*ppWaveHeader )
          {
            if( v7 < 0xE )
              return 0;
            *ppWaveHeader = v8;
            if( (!ppbWaveData || *ppbWaveData) && (!pcbWaveSize || *pcbWaveSize) )
              return 1;
          }
        }
        else if( v6 == 1635017060 && (ppbWaveData && !*ppbWaveData || pcbWaveSize && !*pcbWaveSize) )
        {
          if( ppbWaveData )
            *ppbWaveData = (char *)v8;
          if( pcbWaveSize )
            *pcbWaveSize = v7;
          if( !ppWaveHeader || *ppWaveHeader )
            return 1;
        }
        v4 = (char *)v8 + ((v7 + 1) & 0xFFFFFFFE);
        if( (unsigned int)v4 >= v5 )
          return 0;
      }
    }
  }
  return 0;
}

//----- (00447D50) --------------------------------------------------------
MMRESULT __cdecl WaveOpenFile(char *pszFileName, void **phmmioIn, tWAVEFORMATEX **ppwfxInfo, _MMCKINFO *pckInRIFF)
{
  char *v4; // ecx@1
  HMMIO v5; // eax@1
  void *v6; // edi@1
  MMRESULT v7; // esi@2
  _MMCKINFO *v8; // ebx@3
  __int16 v9; // ax@11
  tWAVEFORMATEX *v10; // eax@15
  tWAVEFORMATEX **v11; // esi@15
  LONG v12; // eax@18
  MMRESULT result; // eax@19
  tWAVEFORMATEX **v14; // ebx@22
  pcmwaveformat_tag pcmWaveFormat; // [sp+10h] [bp-24h]@8
  _MMCKINFO ckIn; // [sp+20h] [bp-14h]@6

  v4 = pszFileName;
  *ppwfxInfo = 0;
  v5 = mmioOpenA(v4, 0, 0x10000u);
  v6 = v5;
  if( v5 )
  {
    v8 = pckInRIFF;
    v7 = mmioDescend(v5, pckInRIFF, 0, 0);
    if( !v7 )
    {
      if( v8->ckid != 1179011410 || v8->fccType != 1163280727 )
        goto LABEL_29;
      ckIn.ckid = 544501094;
      v7 = mmioDescend(v6, &ckIn, v8, 0x10u);
      if( v7 )
        goto ERROR_READING_WAVE;
      if( ckIn.cksize < 0x10 )
        goto LABEL_29;
      if( mmioRead(v6, (HPSTR)&pcmWaveFormat, 16) != 16 )
      {
        v7 = 57602;
        goto ERROR_READING_WAVE;
      }
      if( pcmWaveFormat.wf.wFormatTag == 1 )
      {
        v9 = 0;
        pszFileName = 0;
      }
      else
      {
        if( mmioRead(v6, (HPSTR)&pszFileName, 2) != 2 )
        {
          v7 = 57602;
          goto ERROR_READING_WAVE;
        }
        v9 = (signed __int16)pszFileName;
      }
      v10 = (tWAVEFORMATEX *)GlobalAlloc(0, (unsigned __int16)v9 + 18);
      v11 = ppwfxInfo;
      *ppwfxInfo = v10;
      if( !v10 )
      {
        v7 = 57344;
        goto ERROR_READING_WAVE;
      }
      memcpy(v10, &pcmWaveFormat, 0x10u);
      (*v11)->cbSize = (unsigned __int16)pszFileName;
      if( (_WORD)pszFileName )
      {
        v12 = mmioRead(v6, (HPSTR)&(*v11)[1], (unsigned __int16)pszFileName);
        if( v12 != (unsigned __int16)pszFileName )
        {
LABEL_29:
          v7 = 57601;
          goto ERROR_READING_WAVE;
        }
      }
      result = mmioAscend(v6, &ckIn, 0);
      v7 = result;
      if( !result )
      {
        *phmmioIn = v6;
        return result;
      }
    }
  }
  else
  {
    v7 = 57600;
  }
ERROR_READING_WAVE:
  v14 = ppwfxInfo;
  if( *ppwfxInfo )
  {
    GlobalFree(*ppwfxInfo);
    *v14 = 0;
  }
  if( v6 )
  {
    mmioClose(v6, 0);
    v6 = 0;
  }
  *phmmioIn = v6;
  return v7;
}

//----- (00447EF0) --------------------------------------------------------
MMRESULT __cdecl WaveStartDataRead(void **phmmioIn, _MMCKINFO *pckIn, _MMCKINFO *pckInRIFF)
{
  MMRESULT result; // eax@2

  if( mmioSeek(*phmmioIn, pckInRIFF->dwDataOffset + 4, 0) == -1 )
  {
    result = 1;
  }
  else
  {
    pckIn->ckid = 1635017060;
    result = mmioDescend(*phmmioIn, pckIn, pckInRIFF, 0x10u);
  }
  return result;
}

//----- (00447F40) --------------------------------------------------------
int __cdecl WaveReadFile(void *hmmioIn, unsigned int cbRead, char *pbDest, _MMCKINFO *pckIn, unsigned int *cbActualRead)
{
  int result; // eax@1
  unsigned int v6; // ebx@2
  unsigned int v7; // eax@2
  unsigned int v8; // edi@4
  char *v9; // ecx@5
  char *v10; // esi@6
  size_t v11; // esi@9
  _MMIOINFO mmioinfoIn; // [sp+10h] [bp-48h]@1

  result = mmioGetInfo(hmmioIn, &mmioinfoIn, 0) != 0;
  if( result )
    goto ERROR_CANNOT_READ;
  v6 = cbRead;
  v7 = pckIn->cksize;
  if( cbRead > v7 )
    v6 = pckIn->cksize;
  v8 = 0;
  pckIn->cksize = v7 - v6;
  if( !v6 )
  {
LABEL_13:
    result = mmioSetInfo(hmmioIn, &mmioinfoIn, 0);
    if( !result )
    {
      *cbActualRead = v6;
      return result;
    }
ERROR_CANNOT_READ:
    *cbActualRead = 0;
    return result;
  }
  v9 = mmioinfoIn.pchNext;
  while( 1 )
  {
    v10 = mmioinfoIn.pchEndRead;
    if( v9 == mmioinfoIn.pchEndRead )
    {
      result = mmioAdvance(hmmioIn, &mmioinfoIn, 0);
      if( result )
        goto ERROR_CANNOT_READ;
      v9 = mmioinfoIn.pchNext;
      v10 = mmioinfoIn.pchEndRead;
      if( mmioinfoIn.pchNext == mmioinfoIn.pchEndRead )
        break;
    }
    v11 = v10 - v9;
    if( v6 - v8 >= v11 )
    {
      memcpy(&pbDest[v8], v9, v11);
    }
    else
    {
      v11 = v6 - v8;
      memcpy(&pbDest[v8], v9, v6 - v8);
    }
    v8 += v11;
    v9 = &mmioinfoIn.pchNext[v11];
    mmioinfoIn.pchNext += v11;
    if( v8 >= v6 )
      goto LABEL_13;
  }
  result = 57603;
  *cbActualRead = 0;
  return result;
}

//----- (00448040) --------------------------------------------------------
int __cdecl WaveCloseReadFile(void **phmmio, tWAVEFORMATEX **ppwfxSrc)
{
  if( *ppwfxSrc )
  {
    GlobalFree(*ppwfxSrc);
    *ppwfxSrc = 0;
  }
  if( *phmmio )
  {
    mmioClose(*phmmio, 0);
    *phmmio = 0;
  }
  return 0;
}

//----- (00448080) --------------------------------------------------------
MMRESULT __cdecl WaveCreateFile(char *pszFileName, void **phmmioOut, tWAVEFORMATEX *pwfxDest, _MMCKINFO *pckOut, _MMCKINFO *pckOutRIFF)
{
  HMMIO v5; // eax@1
  MMRESULT result; // eax@2
  void *v7; // ecx@9
  unsigned int dwFactChunk; // [sp+10h] [bp-18h]@1
  _MMCKINFO ckOut1; // [sp+14h] [bp-14h]@9

  dwFactChunk = -1;
  v5 = mmioOpenA(pszFileName, 0, 0x11002u);
  *phmmioOut = v5;
  if( !v5 )
    return 57604;
  pckOutRIFF->fccType = 1163280727;
  pckOutRIFF->cksize = 0;
  result = mmioCreateChunk(*phmmioOut, pckOutRIFF, 0x20u);
  if( !result )
  {
    pckOut->ckid = 544501094;
    pckOut->cksize = 16;
    result = mmioCreateChunk(*phmmioOut, pckOut, 0);
    if( !result )
    {
      if( pwfxDest->wFormatTag == 1 )
      {
        if( mmioWrite(*phmmioOut, (const char *)pwfxDest, 16) != 16 )
          return 57604;
      }
      else if( mmioWrite(*phmmioOut, (const char *)pwfxDest, pwfxDest->cbSize + 18) != pwfxDest->cbSize + 18 )
      {
        return 57604;
      }
      result = mmioAscend(*phmmioOut, pckOut, 0);
      if( !result )
      {
        v7 = *phmmioOut;
        ckOut1.cksize = 0;
        ckOut1.ckid = 1952670054;
        result = mmioCreateChunk(v7, &ckOut1, 0);
        if( !result )
        {
          if( mmioWrite(*phmmioOut, (const char *)&dwFactChunk, 4) != 4 )
            return 57604;
          result = mmioAscend(*phmmioOut, &ckOut1, 0);
          if( result )
            return 57604;
        }
      }
    }
  }
  return result;
}

//----- (004481A0) --------------------------------------------------------
MMRESULT __cdecl WaveStartDataWrite(void **phmmioOut, _MMCKINFO *pckOut, _MMIOINFO *pmmioinfoOut)
{
  MMRESULT result; // eax@1

  pckOut->ckid = 1635017060;
  pckOut->cksize = 0;
  result = mmioCreateChunk(*phmmioOut, pckOut, 0);
  if( !result )
    result = mmioGetInfo(*phmmioOut, pmmioinfoOut, 0);
  return result;
}

//----- (004481E0) --------------------------------------------------------
MMRESULT __cdecl WaveWriteFile(void *hmmioOut, unsigned int cbWrite, char *pbSrc, _MMCKINFO *pckOut, unsigned int *cbActualWrite, _MMIOINFO *pmmioinfoOut)
{
  MMRESULT result; // eax@1
  unsigned int v7; // edi@1

  result = 0;
  v7 = 0;
  *cbActualWrite = 0;
  if( cbWrite )
  {
    do
    {
      if( pmmioinfoOut->pchNext == pmmioinfoOut->pchEndWrite )
      {
        pmmioinfoOut->dwFlags |= 0x10000000u;
        result = mmioAdvance(hmmioOut, pmmioinfoOut, 1u);
        if( result )
          break;
      }
      *pmmioinfoOut->pchNext++ = pbSrc[v7++];
      ++*cbActualWrite;
    }
    while( v7 < cbWrite );
  }
  return result;
}

//----- (00448250) --------------------------------------------------------
MMRESULT __cdecl WaveCloseWriteFile(void **phmmioOut, _MMCKINFO *pckOut, _MMCKINFO *pckOutRIFF, _MMIOINFO *pmmioinfoOut, unsigned int cSamples)
{
  MMRESULT v6; // edi@3

  if( !*phmmioOut )
    return 0;
  pmmioinfoOut->dwFlags |= 0x10000000u;
  v6 = mmioSetInfo(*phmmioOut, pmmioinfoOut, 0);
  if( !v6 )
  {
    v6 = mmioAscend(*phmmioOut, pckOut, 0);
    if( !v6 )
    {
      v6 = mmioAscend(*phmmioOut, pckOutRIFF, 0);
      if( !v6 )
      {
        mmioSeek(*phmmioOut, 0, 0);
        v6 = mmioDescend(*phmmioOut, pckOutRIFF, 0, 0);
        if( !v6 )
        {
          pckOut->ckid = 1952670054;
          if( mmioDescend(*phmmioOut, pckOut, pckOutRIFF, 0x10u) )
            return 1;
          mmioWrite(*phmmioOut, (const char *)&cSamples, 4);
          mmioAscend(*phmmioOut, pckOut, 0);
          v6 = mmioAscend(*phmmioOut, pckOutRIFF, 0);
        }
      }
    }
  }
  if( *phmmioOut )
  {
    mmioClose(*phmmioOut, 0);
    *phmmioOut = 0;
  }
  return v6;
}

//----- (00448340) --------------------------------------------------------
int __cdecl WaveCopyUselessChunks(void **phmmioIn, _MMCKINFO *pckIn, _MMCKINFO *pckInRiff, void **phmmioOut)
{
  signed int v4; // esi@2
  unsigned int v5; // eax@5

  if( mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + 4, 0) == -1 )
  {
    v4 = 57602;
  }
  else
  {
    while( !mmioDescend(*phmmioIn, pckIn, pckInRiff, 0) )
    {
      if( pckIn->cksize + pckIn->dwDataOffset > pckInRiff->dwDataOffset + pckInRiff->cksize )
        break;
      v5 = pckIn->ckid;
      if( pckIn->ckid != 541344080 && (v5 == 1347635524 || v5 == 1953721456) )
        riffCopyChunk(*phmmioIn, *phmmioOut, pckIn);
      mmioAscend(*phmmioIn, pckIn, 0);
    }
    v4 = 0;
  }
  mmioSeek(*phmmioIn, pckInRiff->dwDataOffset + 4, 0);
  return v4;
}

//----- (00448400) --------------------------------------------------------
LPVOID __cdecl riffCopyChunk(void *hmmioSrc, void *hmmioDst, _MMCKINFO *const lpck)
{
  HGLOBAL v3; // eax@1
  LPVOID result; // eax@1
  void *v5; // edi@1
  unsigned int v6; // edx@2
  unsigned int v7; // ebx@3
  HGLOBAL v8; // eax@6
  HGLOBAL v9; // eax@6
  HGLOBAL v10; // eax@7
  HGLOBAL v11; // eax@7
  _MMCKINFO ck; // [sp+10h] [bp-14h]@2

  v3 = GlobalAlloc(0x42u, lpck->cksize);
  result = GlobalLock(v3);
  v5 = result;
  if( result )
  {
    v6 = lpck->cksize;
    ck.ckid = lpck->ckid;
    ck.cksize = v6;
    if( mmioCreateChunk(hmmioDst, &ck, 0)
      || (v7 = lpck->cksize, mmioRead(hmmioSrc, (HPSTR)v5, lpck->cksize) != v7)
      || mmioWrite(hmmioDst, (const char *)v5, v7) != lpck->cksize
      || mmioAscend(hmmioDst, &ck, 0) )
    {
      v8 = GlobalHandle(v5);
      GlobalUnlock(v8);
      v9 = GlobalHandle(v5);
      GlobalFree(v9);
      result = 0;
    }
    else
    {
      v10 = GlobalHandle(v5);
      GlobalUnlock(v10);
      v11 = GlobalHandle(v5);
      GlobalFree(v11);
      result = (LPVOID)1;
    }
  }
  return result;
}

//----- (004484D0) --------------------------------------------------------
MMRESULT __cdecl WaveLoadFile(char *pszFileName, unsigned int *cbSize, unsigned int *pcSamples, tWAVEFORMATEX **ppwfxInfo, char **ppbData)
{
  HGLOBAL *v5; // ebx@1
  HGLOBAL *v6; // esi@1
  tWAVEFORMATEX **v7; // ST0C_4@1
  MMRESULT v8; // edi@1
  char *v9; // eax@3
  _MMCKINFO ckIn; // [sp+10h] [bp-28h]@2
  _MMCKINFO ckInRiff; // [sp+24h] [bp-14h]@1

  v5 = (HGLOBAL *)ppwfxInfo;
  v6 = (HGLOBAL *)ppbData;
  v7 = ppwfxInfo;
  *ppbData = 0;
  *v5 = 0;
  *cbSize = 0;
  v8 = WaveOpenFile(pszFileName, (void **)&ppbData, v7, &ckInRiff);
  if( !v8 )
  {
    v8 = WaveStartDataRead((void **)&ppbData, &ckIn, &ckInRiff);
    if( !v8 )
    {
      v9 = (char *)GlobalAlloc(0, ckIn.cksize);
      *v6 = v9;
      if( v9 )
      {
        v8 = WaveReadFile(ppbData, ckIn.cksize, v9, &ckIn, (unsigned int *)&ppwfxInfo);
        if( !v8 )
        {
          *cbSize = (unsigned int)ppwfxInfo;
          goto DONE_LOADING;
        }
      }
      else
      {
        v8 = 57344;
      }
    }
  }
  if( *v6 )
  {
    GlobalFree(*v6);
    *v6 = 0;
  }
  if( *v5 )
  {
    GlobalFree(*v5);
    *v5 = 0;
  }
DONE_LOADING:
  if( ppbData )
    mmioClose(ppbData, 0);
  return v8;
}

//----- (004485C0) --------------------------------------------------------
MMRESULT __cdecl WaveSaveFile(char *pszFileName, unsigned int cbSize, unsigned int cSamples, tWAVEFORMATEX *pwfxDest, char *pbData)
{
  MMRESULT result; // eax@1
  void *hmmioOut; // [sp+0h] [bp-78h]@1
  unsigned int cbActualWrite; // [sp+4h] [bp-74h]@3
  _MMCKINFO ckOut; // [sp+8h] [bp-70h]@1
  _MMCKINFO ckOutRIFF; // [sp+1Ch] [bp-5Ch]@1
  _MMIOINFO mmioinfoOut; // [sp+30h] [bp-48h]@2

  result = WaveCreateFile(pszFileName, &hmmioOut, pwfxDest, &ckOut, &ckOutRIFF);
  if( !result )
  {
    result = WaveStartDataWrite(&hmmioOut, &ckOut, &mmioinfoOut);
    if( !result )
    {
      result = WaveWriteFile(hmmioOut, cbSize, pbData, &ckOut, &cbActualWrite, &mmioinfoOut);
      if( !result )
        result = WaveCloseWriteFile(&hmmioOut, &ckOut, &ckOutRIFF, &mmioinfoOut, cSamples);
    }
  }
  return result;
}

//----- (00448660) --------------------------------------------------------
int __cdecl ds_stream_init(void *hWnd, IDirectSound *lpd, IDirectSoundBuffer *lpb)
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
// 62E654: using guessed type int ds_ready;
// 86BAB4: using guessed type int bPlaying;
// 888454: using guessed type int uLastPercent;
// 888458: using guessed type int lpBuffer;
// 8884B8: using guessed type int lpDS;
// 8884C8: using guessed type int bTimerInstalled;
// 8884CC: using guessed type int bFileOpen;
// 8884D0: using guessed type int lpDSBStreamBuffer;

//----- (004486B0) --------------------------------------------------------
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
// 62E654: using guessed type int ds_ready;
// 86BAB4: using guessed type int bPlaying;
// 8884C8: using guessed type int bTimerInstalled;
// 8884CC: using guessed type int bFileOpen;

//----- (004486F0) --------------------------------------------------------
int __cdecl ds_stream_file(char *szName, char bLoop, int Volume)
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
// 86BAB4: using guessed type int bPlaying;
// 888490: using guessed type int dword_888490;
// 888494: using guessed type int dword_888494;
// 888498: using guessed type int dword_888498;
// 88849C: using guessed type int dword_88849C;
// 8884A0: using guessed type int dword_8884A0;
// 8884A4: using guessed type int dword_8884A4;
// 8884A8: using guessed type int dword_8884A8;
// 8884AC: using guessed type int dword_8884AC;
// 8884B0: using guessed type int dword_8884B0;
// 8884B4: using guessed type int dword_8884B4;
// 8884B8: using guessed type int lpDS;
// 8884C0: using guessed type int stream_paused;
// 8884C8: using guessed type int bTimerInstalled;
// 8884CC: using guessed type int bFileOpen;
// 8884D0: using guessed type int lpDSBStreamBuffer;

//----- (00448A40) --------------------------------------------------------
int __cdecl ds_stream_volume(int val)
{
  int result; // eax@1

  result = lpDSBStreamBuffer;
  if( lpDSBStreamBuffer )
    result = (*(int (__stdcall **)(int, int))(*(_DWORD *)lpDSBStreamBuffer + 60))(lpDSBStreamBuffer, val) == 0;
  return result;
}
// 8884D0: using guessed type int lpDSBStreamBuffer;

//----- (00448A60) --------------------------------------------------------
int __cdecl ds_stream_pause()
{
  int result; // eax@1

  result = 1;
  stream_paused = 1;
  return result;
}
// 8884C0: using guessed type int stream_paused;

//----- (00448A70) --------------------------------------------------------
int __cdecl ds_stream_resume()
{
  stream_paused = 0;
  return 1;
}
// 8884C0: using guessed type int stream_paused;

//----- (00448A80) --------------------------------------------------------
int __cdecl ds_stream_stop()
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
// 86BAB4: using guessed type int bPlaying;
// 888490: using guessed type int dword_888490;
// 8884A8: using guessed type int dword_8884A8;
// 8884C8: using guessed type int bTimerInstalled;
// 8884CC: using guessed type int bFileOpen;
// 8884D0: using guessed type int lpDSBStreamBuffer;

//----- (00448B30) --------------------------------------------------------
unsigned int __cdecl ds_stream_messages(void *hWnd, unsigned int wMsg)
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
// 888454: using guessed type int uLastPercent;
// 8884A4: using guessed type int dword_8884A4;

//----- (00448BA0) --------------------------------------------------------
void __stdcall ds_stream_time_func(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
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
// 888490: using guessed type int dword_888490;
// 888494: using guessed type int dword_888494;
// 888498: using guessed type int dword_888498;
// 88849C: using guessed type int dword_88849C;
// 8884A0: using guessed type int dword_8884A0;
// 8884A4: using guessed type int dword_8884A4;
// 8884A8: using guessed type int dword_8884A8;
// 8884AC: using guessed type int dword_8884AC;
// 8884B0: using guessed type int dword_8884B0;
// 8884B4: using guessed type int dword_8884B4;
// 8884C0: using guessed type int stream_paused;
