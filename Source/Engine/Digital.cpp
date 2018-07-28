
//----- (004BCC40) --------------------------------------------------------
void __thiscall TDigital::TDigital(TDigital *this, TSound_Driver *in_sound_system, char *file_name, int res_id)
{
  TDigital *v4; // esi@1

  v4 = this;
  TDigital::init_vars(this);
  v4->sound_system = in_sound_system;
  v4->resource_id = res_id;
  if( file_name )
  {
    strncpy(v4->sound_file, file_name, 0xCu);
    v4->sound_file[12] = 0;
  }
}

//----- (004BCC80) --------------------------------------------------------
void __thiscall TDigital::TDigital(TDigital *this, TDigital *first)
{
  TDigital *v2; // esi@1

  v2 = this;
  TDigital::init_vars(this);
  v2->owner = first;
  v2->volume = first->volume;
  v2->pitch = first->pitch;
  v2->pan = first->pan;
  v2->loop = first->loop;
}

//----- (004BCCC0) --------------------------------------------------------
void __thiscall TDigital::init_vars(TDigital *this)
{
  this->sound_system = 0;
  this->owner = 0;
  this->loaded = 0;
  this->failed = 0;
  this->sound_file[0] = 0;
  this->wave_data = 0;
  this->wave_info = 0;
  this->sound_buffer = 0;
  this->data_size = 0;
  this->volume = 0;
  this->pitch = 0;
  this->pan = 0;
  this->loop = 0;
}

//----- (004BCCF0) --------------------------------------------------------
void __thiscall TDigital::exit(TDigital *this)
{
  TDigital *v1; // esi@1
  TDigital *v2; // ecx@1

  v1 = this;
  v2 = this->owner;
  if( v2 )
  {
    TDigital::exit(v2);
    TDigital::init_vars(v1);
  }
  else if( v1->loaded )
  {
    TDigital::stop(v1);
    TDigital::unload(v1);
    TDigital::init_vars(v1);
  }
}

//----- (004BCD30) --------------------------------------------------------
int __thiscall TDigital::load(TDigital *this, char *file_name, int res_id)
{
  TDigital *v3; // ebp@1
  char v4; // al@1
  TDigital *v5; // ecx@2
  int v7; // ebx@10
  int v8; // eax@14
  int v9; // esi@14
  unsigned int v10; // ST1C_4@19
  char *v11; // eax@19
  char *v12; // edx@22
  tWAVEFORMATEX *v13; // eax@23
  char *v14; // eax@24
  IDirectSoundBuffer **v15; // ebx@25
  unsigned int v16; // ecx@25
  tWAVEFORMATEX *v17; // edx@25
  TSound_Driver *v18; // eax@25
  tWAVEFORMATEX *v19; // eax@26
  char *v20; // ecx@26
  unsigned int v21; // ecx@28
  char *v22; // ST1C_4@30
  IDirectSoundBuffer *v23; // eax@31
  tWAVEFORMATEX *v24; // edx@31
  char *v25; // eax@31
  char *v26; // ebx@34
  unsigned int v27; // ST1C_4@35
  char *v28; // eax@35
  int v29; // eax@36
  tWAVEFORMATEX *v30; // eax@40
  int v31; // eax@41
  IDirectSoundBuffer **v32; // ebx@44
  unsigned int v33; // edx@44
  tWAVEFORMATEX *v34; // eax@44
  TSound_Driver *v35; // ecx@44
  unsigned int v36; // ecx@47
  IDirectSoundBuffer *v37; // eax@51
  tWAVEFORMATEX *v38; // edx@52
  unsigned int size1; // [sp+30h] [bp-15Ch]@27
  unsigned int size2; // [sp+34h] [bp-158h]@27
  void *mem2; // [sp+38h] [bp-154h]@27
  void *mem1; // [sp+3Ch] [bp-150h]@27
  int load_type; // [sp+40h] [bp-14Ch]@34
  _DSBUFFERDESC buffer_desc; // [sp+44h] [bp-148h]@1
  _tag_wavheader wave_hdr; // [sp+58h] [bp-134h]@15
  int resDataSize; // [sp+84h] [bp-108h]@34
  char file_with_path[260]; // [sp+88h] [bp-104h]@14

  buffer_desc.dwFlags = 0;
  buffer_desc.dwBufferBytes = 0;
  v3 = this;
  buffer_desc.dwReserved = 0;
  buffer_desc.lpwfxFormat = 0;
  v4 = this->failed;
  buffer_desc.dwSize = 0;
  if( v4 )
    return 0;
  v5 = this->owner;
  if( v5 )
    return TDigital::load(v5, file_name, -1);
  if( !v3->sound_system )
    return 0;
  color_log(-70, -70, 1);
  if( v3->loaded )
    TDigital::unload(v3);
  if( file_name )
  {
    strncpy(v3->sound_file, file_name, 0xCu);
    v3->sound_file[12] = 0;
  }
  if( v3->sound_file[0] )
  {
    v7 = res_id;
    if( res_id <= -1 )
      v7 = v3->resource_id;
    if( sound_file_first || v7 < 0 )
    {
      sprintf(file_with_path, aSS, v3->sound_system->path, v3->sound_file);
      v8 = _open(file_with_path, 0, 0);
      v9 = v8;
      if( v8 != -1 )
      {
        if( (unsigned int)read(v8, &wave_hdr, 0x2Cu) <= 0 )
        {
          v3->failed = 1;
          _close(v9);
          goto LABEL_54;
        }
        if( strncmp(wave_hdr.szRIFF, aRiff, 4u) || wave_hdr.wFormatTag != 1 )
        {
          v3->failed = 1;
          _close(v9);
          goto LABEL_54;
        }
        v10 = wave_hdr.dwDataLength;
        v3->data_size = wave_hdr.dwDataLength;
        v11 = (char *)malloc(v10);
        v3->wave_data = v11;
        if( !v11 )
        {
          v3->failed = 1;
          _close(v9);
          goto LABEL_54;
        }
        if( (unsigned int)read(v9, v11, v3->data_size) <= 0 )
        {
          v12 = v3->wave_data;
          v3->failed = 1;
          free(v12);
          v3->wave_data = 0;
          _close(v9);
          goto LABEL_54;
        }
        _close(v9);
        v13 = (tWAVEFORMATEX *)malloc(0x12u);
        v3->wave_info = v13;
        if( !v13 )
        {
          v14 = v3->wave_data;
          v3->failed = 1;
          free(v14);
          v3->wave_data = 0;
          goto LABEL_54;
        }
        v13->wFormatTag = wave_hdr.wFormatTag;
        v15 = &v3->sound_buffer;
        v3->wave_info->nChannels = wave_hdr.nChannels;
        v3->wave_info->nSamplesPerSec = wave_hdr.nSamplesPerSec;
        v3->wave_info->nAvgBytesPerSec = wave_hdr.nAvgBytesPerSec;
        v3->wave_info->nBlockAlign = wave_hdr.nBlockAlign;
        v3->wave_info->wBitsPerSample = wave_hdr.wBitsPerSample;
        v3->wave_info->cbSize = 0;
        v16 = v3->data_size;
        v17 = v3->wave_info;
        v18 = v3->sound_system;
        buffer_desc.dwSize = 20;
        buffer_desc.dwFlags = 226;
        buffer_desc.dwBufferBytes = v16;
        buffer_desc.dwReserved = 0;
        buffer_desc.lpwfxFormat = v17;
        if( ((int (__stdcall *)(IDirectSound *, _DSBUFFERDESC *, int, _DWORD))v18->direct_sound->vfptr[1].QueryInterface)(
               v18->direct_sound,
               &buffer_desc,
               (int)&v3->sound_buffer,
               0) )
        {
          v19 = v3->wave_info;
          v3->failed = 1;
          *v15 = 0;
          free(v19);
          v20 = v3->wave_data;
          v3->wave_info = 0;
          free(v20);
          v3->wave_data = 0;
          goto LABEL_54;
        }
        if( ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, void **, unsigned int *, void **, unsigned int *, _DWORD))(*v15)->vfptr[3].Release)(
               *v15,
               0,
               v3->data_size,
               &mem1,
               &size1,
               &mem2,
               &size2,
               0) )
        {
          v23 = *v15;
          v3->failed = 1;
          v23->vfptr->Release((IUnknown *)v23);
          v24 = v3->wave_info;
          *v15 = 0;
          free(v24);
          v25 = v3->wave_data;
          v3->wave_info = 0;
          free(v25);
          v3->wave_data = 0;
          goto LABEL_54;
        }
        qmemcpy(mem1, v3->wave_data, size1);
        v21 = size2;
        if( size2 )
        {
          qmemcpy(mem2, &v3->wave_data[size1], size2);
          v21 = size2;
        }
        ((void (__stdcall *)(IDirectSoundBuffer *, void *, unsigned int, void *, unsigned int))(*v15)->vfptr[6].AddRef)(
          *v15,
          mem1,
          size1,
          mem2,
          v21);
        free(v3->wave_info);
        v22 = v3->wave_data;
        v3->wave_info = 0;
        free(v22);
        v3->wave_data = 0;
LABEL_50:
        v3->loaded = 1;
        color_log(-70, 95, 1);
        return 1;
      }
    }
    if( v7 <= -1 || (v26 = RESFILE_load(0x77617620u, v7, &load_type, &resDataSize)) == 0 )
    {
      v3->failed = 1;
      goto LABEL_54;
    }
    qmemcpy(&wave_hdr, v26, sizeof(wave_hdr));
    v27 = wave_hdr.dwDataLength;
    v3->data_size = wave_hdr.dwDataLength;
    v28 = (char *)malloc(v27);
    v3->wave_data = v28;
    if( !v28 )
    {
      v29 = load_type;
      v3->failed = 1;
      if( v29 == 1 )
        free(v26);
      goto LABEL_54;
    }
    qmemcpy(v28, v26 + 44, v3->data_size);
    if( load_type == 1 )
      free(v26);
    v30 = (tWAVEFORMATEX *)malloc(0x12u);
    v3->wave_info = v30;
    if( !v30 )
    {
      v31 = load_type;
      v3->failed = 1;
      if( v31 == 1 )
        free(v26);
      goto LABEL_54;
    }
    v30->wFormatTag = wave_hdr.wFormatTag;
    v32 = &v3->sound_buffer;
    v3->wave_info->nChannels = wave_hdr.nChannels;
    v3->wave_info->nSamplesPerSec = wave_hdr.nSamplesPerSec;
    v3->wave_info->nAvgBytesPerSec = wave_hdr.nAvgBytesPerSec;
    v3->wave_info->nBlockAlign = wave_hdr.nBlockAlign;
    v3->wave_info->wBitsPerSample = wave_hdr.wBitsPerSample;
    v3->wave_info->cbSize = 0;
    v33 = v3->data_size;
    v34 = v3->wave_info;
    buffer_desc.dwReserved = 0;
    v35 = v3->sound_system;
    buffer_desc.dwSize = 20;
    buffer_desc.dwFlags = 226;
    buffer_desc.dwBufferBytes = v33;
    buffer_desc.lpwfxFormat = v34;
    if( ((int (__stdcall *)(IDirectSound *, _DSBUFFERDESC *, int, _DWORD))v35->direct_sound->vfptr[1].QueryInterface)(
           v35->direct_sound,
           &buffer_desc,
           (int)&v3->sound_buffer,
           0) )
    {
      v3->failed = 1;
    }
    else
    {
      if( !((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, void **, unsigned int *, void **, unsigned int *, _DWORD))(*v32)->vfptr[3].Release)(
              *v32,
              0,
              v3->data_size,
              &mem1,
              &size1,
              &mem2,
              &size2,
              0) )
      {
        qmemcpy(mem1, v3->wave_data, size1);
        v36 = size2;
        if( size2 )
        {
          qmemcpy(mem2, &v3->wave_data[size1], size2);
          v36 = size2;
        }
        ((void (__stdcall *)(IDirectSoundBuffer *, void *, unsigned int, void *, unsigned int))(*v32)->vfptr[6].AddRef)(
          *v32,
          mem1,
          size1,
          mem2,
          v36);
        free(v3->wave_info);
        v3->wave_info = 0;
        goto LABEL_50;
      }
      v37 = *v32;
      v3->failed = 1;
      v37->vfptr->Release((IUnknown *)v37);
    }
    v38 = v3->wave_info;
    *v32 = 0;
    free(v38);
    v3->wave_info = 0;
  }
LABEL_54:
  color_log(-70, 95, 1);
  return 0;
}
// 86BC00: using guessed type unsigned __int8 sound_file_first;

//----- (004BD300) --------------------------------------------------------
void __thiscall TDigital::unload(TDigital *this)
{
  TDigital *v1; // esi@1
  TDigital *i; // eax@1
  IDirectSoundBuffer *v3; // eax@4

  v1 = this;
  for( i = this->owner; i; i = i->owner )
    v1 = i;
  if( v1->loaded )
  {
    TDigital::stop(v1);
    v3 = v1->sound_buffer;
    if( v3 )
    {
      v3->vfptr->Release((IUnknown *)v1->sound_buffer);
      v1->sound_buffer = 0;
    }
    if( v1->wave_data )
    {
      free(v1->wave_data);
      v1->wave_data = 0;
    }
    if( v1->wave_info )
    {
      free(v1->wave_info);
      v1->wave_info = 0;
    }
    v1->loaded = 0;
  }
  v1->failed = 0;
}

//----- (004BD370) --------------------------------------------------------
IDirectSoundBuffer *__thiscall TDigital::play(TDigital *this)
{
  TDigital *v1; // edi@1
  TDigital *v2; // esi@1
  TSound_Driver *v3; // eax@3
  IDirectSoundBuffer *result; // eax@7
  int v5; // ebx@10
  unsigned int status; // [sp+Ch] [bp-4h]@10

  v1 = this;
  v2 = this->owner;
  if( !v2 )
    v2 = this;
  v3 = v2->sound_system;
  if( !v2->sound_system || !v3->ready || v3->mute )
    return (IDirectSoundBuffer *)1;
  if( v2->loaded || (result = (IDirectSoundBuffer *)TDigital::load(v2, this->sound_file, -1)) != 0 )
  {
    result = v2->sound_buffer;
    if( !result )
    {
      v2->failed = 1;
      return result;
    }
    ((void (__stdcall *)(int, unsigned int *))result->vfptr[3].QueryInterface)((int)result, &status);
    v5 = v2->loop != 0;
    ((void (__stdcall *)(IDirectSoundBuffer *, int))v2->sound_buffer->vfptr[5].QueryInterface)(
      v2->sound_buffer,
      v1->volume);
    ((void (__stdcall *)(IDirectSoundBuffer *, unsigned int))v2->sound_buffer->vfptr[5].Release)(
      v2->sound_buffer,
      v1->pitch);
    ((void (__stdcall *)(IDirectSoundBuffer *, int))v2->sound_buffer->vfptr[5].AddRef)(v2->sound_buffer, v1->pan);
    ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD))v2->sound_buffer->vfptr[4].AddRef)(v2->sound_buffer, 0);
    if( ((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, _DWORD, int))v2->sound_buffer->vfptr[4].QueryInterface)(
           v2->sound_buffer,
           0,
           0,
           v5) == -2005401450 )
    {
      result = (IDirectSoundBuffer *)TDigital::load(v2, 0, -1);
      if( !result )
        return result;
      ((void (__stdcall *)(IDirectSoundBuffer *, int))v2->sound_buffer->vfptr[5].QueryInterface)(
        v2->sound_buffer,
        v1->volume);
      ((void (__stdcall *)(IDirectSoundBuffer *, unsigned int))v2->sound_buffer->vfptr[5].Release)(
        v2->sound_buffer,
        v1->pitch);
      ((void (__stdcall *)(IDirectSoundBuffer *, int))v2->sound_buffer->vfptr[5].AddRef)(v2->sound_buffer, v1->pan);
      ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD))v2->sound_buffer->vfptr[4].AddRef)(v2->sound_buffer, 0);
      ((void (__stdcall *)(IDirectSoundBuffer *, _DWORD, _DWORD, int))v2->sound_buffer->vfptr[4].QueryInterface)(
        v2->sound_buffer,
        0,
        0,
        v5);
    }
    return (IDirectSoundBuffer *)1;
  }
  return result;
}

//----- (004BD490) --------------------------------------------------------
void __thiscall TDigital::stop(TDigital *this)
{
  TDigital *i; // eax@1
  IDirectSoundBuffer *v2; // ecx@6

  for( i = this->owner; i; i = i->owner )
    this = i;
  if( this->sound_system && this->sound_system->ready && this->loaded )
  {
    v2 = this->sound_buffer;
    if( v2 )
      ((void (__stdcall *)(IDirectSoundBuffer *))v2->vfptr[6].QueryInterface)(v2);
  }
}

//----- (004BD4C0) --------------------------------------------------------
void __thiscall TDigital::set_loop(TDigital *this, __int16 loop_count)
{
  if( loop_count )
    this->loop = 1;
  else
    this->loop = 0;
}

//----- (004BD4E0) --------------------------------------------------------
void __thiscall TDigital::set_volume(TDigital *this, int in_vol)
{
  TDigital *v2; // eax@1

  v2 = this->owner;
  this->volume = in_vol;
  if( !v2 )
    v2 = this;
  if( v2->loaded )
    ((void (__stdcall *)(_DWORD, int))v2->sound_buffer->vfptr[5].QueryInterface)(v2->sound_buffer, in_vol);
}

//----- (004BD510) --------------------------------------------------------
void __thiscall TDigital::set_pitch(TDigital *this, unsigned int in_pitch)
{
  TDigital *v2; // eax@1

  v2 = this->owner;
  this->pitch = in_pitch;
  if( !v2 )
    v2 = this;
  if( v2->loaded )
    ((void (__stdcall *)(_DWORD, unsigned int))v2->sound_buffer->vfptr[5].Release)(v2->sound_buffer, in_pitch);
}

//----- (004BD540) --------------------------------------------------------
void __thiscall TDigital::set_pan(TDigital *this, int in_pan)
{
  TDigital *v2; // eax@1

  v2 = this->owner;
  this->pan = in_pan;
  if( !v2 )
    v2 = this;
  if( v2->loaded )
    ((void (__stdcall *)(_DWORD, int))v2->sound_buffer->vfptr[5].AddRef)(v2->sound_buffer, in_pan);
}

//----- (004BD570) --------------------------------------------------------
int __thiscall TDigital::is_playing(TDigital *this)
{
  TDigital *v1; // eax@1
  IDirectSoundBuffer *v2; // eax@5
  int result; // eax@9
  unsigned int status; // [sp+8h] [bp-4h]@1

  status = (unsigned int)this;
  v1 = this->owner;
  if( !v1 )
    v1 = this;
  result = 0;
  if( this->sound_system )
  {
    if( v1->loaded )
    {
      v2 = v1->sound_buffer;
      if( v2 )
      {
        if( !((int (__stdcall *)(IDirectSoundBuffer *, unsigned int *))v2->vfptr[3].QueryInterface)(v2, &status)
          && (status == 1 || status == 4) )
        {
          result = 1;
        }
      }
    }
  }
  return result;
}

//----- (004BD5C0) --------------------------------------------------------
int __thiscall TDigital::add_to_play_list(TDigital *this)
{
  TSound_Driver *v1; // eax@1
  int result; // eax@3

  v1 = this->sound_system;
  if( !this->sound_system || v1->mute )
    result = 0;
  else
    result = TSound_Driver::add_to_play_list(v1, this);
  return result;
}
