
//----- (00461910) --------------------------------------------------------
void __thiscall TMusic_System::TMusic_System(TMusic_System *this, char music_type_in, void *instance_in, void *window_in, TSound_Driver *sound_system_in, char *path_in)
{
  TMusic_System *v6; // ebx@1

  v6 = this;
  this->music_type = music_type_in;
  this->sound_system = sound_system_in;
  this->window = window_in;
  this->instance = instance_in;
  this->device_open = 0;
  this->device_id = 0;
  this->playing_track = 0;
  this->start_track = 0;
  this->end_track = 0;
  this->make_cur_track = 0;
  this->set_pos = 0;
  this->loop = 0;
  this->current_track = 0;
  this->track_count = 0;
  this->notify_waiting = 0;
  this->start_volume = 1;
  this->volume = 0;
  this->paused = 0;
  this->auto_paused = 0;
  this->inactivated = 0;
  this->fade_out = 0;
  this->fade_time = 2000;
  this->fading_track = 0;
  this->last_fade_time = 0;
  this->mixer_open = 0;
  this->mixer_handle = 0;
  this->midi_window = 0;
  this->file_name[0] = 0;
  if( path_in )
  {
    strcpy(this->path, path_in);
    TMusic_System::open_device(v6);
  }
  else
  {
    this->path[0] = 0;
    TMusic_System::open_device(this);
  }
}

//----- (00461A30) --------------------------------------------------------
int __thiscall TMusic_System::open_device(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  FILE *v2; // eax@5
  int result; // eax@7
  unsigned int v4; // eax@9
  FILE *v5; // eax@11
  unsigned int v6; // eax@15
  unsigned int v7; // ST00_4@15
  MCIDEVICEID v8; // ST00_4@15
  unsigned int v9; // eax@18
  tagMCI_STATUS_PARMS status_info; // [sp+8h] [bp-138h]@15
  tagMCI_SET_PARMS set_info; // [sp+18h] [bp-128h]@15
  tagMCI_OPEN_PARMSA open_info; // [sp+24h] [bp-11Ch]@14
  char file_name[261]; // [sp+38h] [bp-108h]@5

  v1 = this;
  if( this->music_type == 1 )
  {
    open_info.lpstrDeviceType = (char *)516;
    if( mciSendCommandA(0, 0x803u, 0x3102u, (DWORD_PTR)&open_info) )
      return 0;
    v6 = open_info.wDeviceID;
    v7 = open_info.wDeviceID;
    v1->device_open = 1;
    v1->device_id = v6;
    set_info.dwTimeFormat = 10;
    mciSendCommandA(v7, 0x80Du, 0x402u, (DWORD_PTR)&set_info);
    v8 = v1->device_id;
    status_info.dwItem = 3;
    if( !mciSendCommandA(v8, 0x814u, 0x102u, (DWORD_PTR)&status_info) )
      v1->track_count = status_info.dwReturn;
    if( TMusic_System::open_mixer(v1) )
    {
      v9 = 10000
         * v1->mixer_volume_value.dwValue
         / (v1->mixer_volume_control.Bounds.lMaximum - v1->mixer_volume_control.Bounds.lMinimum)
         - 10000;
      v1->start_volume = v9;
      v1->volume = v9;
    }
    result = 1;
  }
  else
  {
    if( this->music_type != 2 )
    {
      if( this->music_type == 3 )
      {
        this->track_count = 0;
        while( 1 )
        {
          sprintf(file_name, aSmusicD_wav, v1, v1->track_count + 1);
          v2 = fopen(file_name, Mode);
          if( !v2 )
            break;
          fclose(v2);
          ++v1->track_count;
        }
        v1->volume = 0;
        v1->device_open = 1;
        return 1;
      }
      return 0;
    }
    if( TMusic_System::open_mixer(this) )
    {
      v4 = 10000
         * v1->mixer_volume_value.dwValue
         / (v1->mixer_volume_control.Bounds.lMaximum - v1->mixer_volume_control.Bounds.lMinimum)
         - 10000;
      v1->start_volume = v4;
      v1->volume = v4;
    }
    for( v1->track_count = 0; ; ++v1->track_count )
    {
      sprintf(file_name, aSmusicD_mid, v1, v1->track_count + 1);
      v5 = fopen(file_name, Mode);
      if( !v5 )
        break;
      fclose(v5);
    }
    v1->device_open = 1;
    result = 1;
  }
  return result;
}

//----- (00461C60) --------------------------------------------------------
void __thiscall TMusic_System::close_device(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  int v2; // eax@6
  int v3; // eax@9

  v1 = this;
  if( this->device_open )
  {
    TMusic_System::stop_track(this);
    switch ( v1->music_type )
    {
      case 1:
        v3 = v1->start_volume;
        if( v3 != 1 )
        {
          TMusic_System::set_volume(v1, v3, 0);
          v1->start_volume = 1;
        }
        TMusic_System::close_mixer(v1);
        mciSendCommandA(v1->device_id, 0x804u, 2u, 0);
        v1->device_id = 0;
        v1->device_open = 0;
        v1->track_count = 0;
        break;
      case 2:
        v2 = v1->start_volume;
        if( v2 != 1 )
        {
          TMusic_System::set_volume(v1, v2, 0);
          v1->start_volume = 1;
        }
        TMusic_System::close_mixer(v1);
        v1->device_open = 0;
        v1->track_count = 0;
        break;
      case 3:
        v1->track_count = 0;
        v1->device_open = 0;
        break;
    }
  }
}

//----- (00461D20) --------------------------------------------------------
int __thiscall TMusic_System::open_mixer(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  UINT v2; // eax@1
  UINT v3; // edi@1
  UINT v4; // ebp@2
  HMIXEROBJ *v5; // ebx@3
  int v6; // eax@5
  unsigned int v7; // ecx@9
  HMIXEROBJ v8; // edx@9
  unsigned int v9; // ecx@10
  void *v10; // ST08_4@10
  int result; // eax@14
  unsigned int mixer_id; // [sp+10h] [bp-8h]@2
  unsigned int num_dev; // [sp+14h] [bp-4h]@1

  v1 = this;
  v2 = mixerGetNumDevs();
  v3 = v2;
  num_dev = v2;
  if( v2 )
  {
    v4 = 0;
    mixer_id = 0;
    if( v2 )
    {
      v5 = &v1->mixer_handle;
      while( 1 )
      {
        if( !mixerOpen(&v1->mixer_handle, v4, 0, 0, 0) )
        {
          memset(&v1->mixer_line_info, 0, sizeof(v1->mixer_line_info));
          v6 = v1->music_type;
          v1->mixer_line_info.cbStruct = 168;
          if( (_BYTE)v6 == 1 )
            v1->mixer_line_info.dwComponentType = 4101;
          else
            v1->mixer_line_info.dwComponentType = 4100;
          if( !mixerGetLineInfoA(*v5, &v1->mixer_line_info, 3u) )
          {
            memset(&v1->mixer_line_controls, 0, sizeof(v1->mixer_line_controls));
            memset(&v1->mixer_volume_control, 0, sizeof(v1->mixer_volume_control));
            v7 = v1->mixer_line_info.dwLineID;
            v1->mixer_line_controls.cbStruct = 24;
            v8 = *v5;
            v1->mixer_line_controls.dwLineID = v7;
            v1->mixer_line_controls.dwControlID = 1342373889;
            v1->mixer_line_controls.cControls = 1;
            v1->mixer_line_controls.cbmxctrl = 148;
            v1->mixer_line_controls.pamxctrl = &v1->mixer_volume_control;
            if( !mixerGetLineControlsA(v8, &v1->mixer_line_controls, 2u) )
            {
              memset(&v1->mixer_volume_details, 0, sizeof(v1->mixer_volume_details));
              v1->mixer_volume_value.dwValue = 0;
              v9 = v1->mixer_volume_control.dwControlID;
              v1->mixer_volume_details.cbStruct = 24;
              v10 = *v5;
              v1->mixer_volume_details.dwControlID = v9;
              v1->mixer_volume_details.cChannels = 1;
              v1->mixer_volume_details.cbDetails = 4;
              v1->mixer_volume_details.paDetails = &v1->mixer_volume_value;
              if( !mixerGetControlDetailsA(v10, &v1->mixer_volume_details, 0) )
              {
                result = 1;
                v1->mixer_open = 1;
                return result;
              }
            }
            v4 = mixer_id;
          }
          mixerClose(*v5);
          v3 = num_dev;
          *v5 = 0;
        }
        mixer_id = ++v4;
        if( v4 >= v3 )
          return 0;
      }
    }
  }
  return 0;
}

//----- (00461EC0) --------------------------------------------------------
void __thiscall TMusic_System::close_mixer(TMusic_System *this)
{
  TMusic_System *v1; // esi@1

  v1 = this;
  if( this->mixer_open )
  {
    if( this->mixer_handle )
    {
      mixerClose(this->mixer_handle);
      v1->mixer_handle = 0;
    }
    v1->mixer_open = 0;
  }
}

//----- (00461F00) --------------------------------------------------------
int __thiscall TMusic_System::set_music_type(TMusic_System *this, char music_type_in)
{
  TMusic_System *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if( music_type_in == this->music_type )
  {
    result = this->device_open;
  }
  else
  {
    TMusic_System::close_device(this);
    v2->music_type = music_type_in;
    result = TMusic_System::open_device(v2);
  }
  return result;
}

//----- (00461F40) --------------------------------------------------------
void __thiscall TMusic_System::set_fade_out(TMusic_System *this, int fade_out_in, unsigned int fade_time_in)
{
  this->fade_out = fade_out_in;
  this->fade_time = fade_time_in;
}

//----- (00461F60) --------------------------------------------------------
void __thiscall TMusic_System::set_volume(TMusic_System *this, int volume_in, int permanent)
{
  signed int v3; // eax@1
  TSound_Driver *v4; // ecx@11

  v3 = volume_in;
  if( volume_in >= -10000 )
  {
    if( volume_in > 0 )
      v3 = 0;
  }
  else
  {
    v3 = -10000;
  }
  if( permanent )
    this->volume = v3;
  if( this->device_open )
  {
    if( this->music_type == 1 )
    {
      if( !this->mixer_open )
        return;
    }
    else
    {
      if( this->music_type != 2 )
      {
        if( this->music_type == 3 )
        {
          v4 = this->sound_system;
          if( v4 )
            TSound_Driver::set_stream_volume(v4, v3);
        }
        return;
      }
      if( !this->mixer_open )
        return;
    }
    this->mixer_volume_value.dwValue = (v3 + 10000)
                                     * (this->mixer_volume_control.Bounds.lMaximum
                                      - this->mixer_volume_control.Bounds.lMinimum)
                                     / 0x2710u;
    mixerSetControlDetails(this->mixer_handle, &this->mixer_volume_details, 0);
  }
}

//----- (00462010) --------------------------------------------------------
int __thiscall TMusic_System::play_track(TMusic_System *this, int track_in, int loop_in, unsigned int set_pos_in)
{
  bool v4; // zf@1
  int result; // eax@4

  v4 = this->playing_track == 0;
  this->file_name[0] = 0;
  this->start_track = track_in;
  this->end_track = track_in;
  this->make_cur_track = 0;
  this->set_pos = set_pos_in;
  this->loop = loop_in;
  if( !v4 && this->fade_out && this->fade_time )
  {
    TMusic_System::start_fade(this);
    result = 1;
  }
  else
  {
    result = TMusic_System::play(this, track_in, track_in, 0, 0, set_pos_in);
  }
  return result;
}

//----- (00462090) --------------------------------------------------------
int __thiscall TMusic_System::play_file(TMusic_System *this, char *file_name_in, int loop_in, unsigned int set_pos_in)
{
  int result; // eax@2
  bool v5; // zf@3

  if( this->music_type == 1 )
  {
    result = 0;
  }
  else
  {
    strcpy(this->file_name, file_name_in);
    v5 = this->playing_track == 0;
    this->start_track = 0;
    this->end_track = 0;
    this->make_cur_track = 0;
    this->set_pos = set_pos_in;
    this->loop = loop_in;
    if( v5 || !this->fade_out || this->fade_time <= 0 )
    {
      result = TMusic_System::play(this, 0, 0, this->file_name, 0, set_pos_in);
    }
    else
    {
      TMusic_System::start_fade(this);
      result = 1;
    }
  }
  return result;
}

//----- (00462140) --------------------------------------------------------
int __thiscall TMusic_System::play_tracks(TMusic_System *this, int start_track_in, int end_track_in, int loop_in, int make_cur_track_in, unsigned int set_pos_in)
{
  int result; // eax@1
  int v7; // esi@4

  this->loop = loop_in;
  result = this->track_count;
  this->file_name[0] = 0;
  this->start_track = start_track_in;
  this->end_track = end_track_in;
  this->make_cur_track = make_cur_track_in;
  this->set_pos = set_pos_in;
  if( result )
  {
    if( start_track_in > result )
      this->start_track = result;
    v7 = this->start_track;
    if( end_track_in >= v7 )
    {
      if( end_track_in > result )
        this->end_track = result;
    }
    else
    {
      this->end_track = v7;
    }
    if( this->playing_track && this->fade_out && this->fade_time )
    {
      TMusic_System::start_fade(this);
      result = 1;
    }
    else
    {
      result = TMusic_System::play(this, v7, this->end_track, 0, make_cur_track_in, set_pos_in);
    }
  }
  return result;
}

//----- (00462200) --------------------------------------------------------
int __thiscall TMusic_System::play(TMusic_System *this, int start_track_in, int end_track_in, char *file_name_in, int make_cur_track_in, unsigned int set_pos_in)
{
  TMusic_System *v6; // ebp@1
  int v7; // eax@6
  int v8; // edx@7
  int v9; // eax@28
  void (__stdcall *v10)(MCIDEVICEID, UINT, DWORD_PTR, DWORD_PTR); // esi@29
  MCIERROR v11; // eax@29
  MCIERROR v12; // ebx@29
  unsigned int v13; // eax@33
  int v14; // eax@36
  DWORD_PTR v15; // esi@37
  MCIDEVICEID v16; // ST00_4@38
  int v17; // ecx@40
  MCIERROR v18; // eax@43
  int v19; // eax@44
  tagMCI_SEEK_PARMS seek_info; // [sp+10h] [bp-224h]@34
  tagMCI_OPEN_PARMSA open_info; // [sp+18h] [bp-21Ch]@29
  char track_name[261]; // [sp+2Ch] [bp-208h]@19
  char szErrorMsg[256]; // [sp+134h] [bp-100h]@30

  v6 = this;
  if( !this->device_open )
    return 0;
  if( this->playing_track )
    TMusic_System::stop_playing(this);
  if( file_name_in && *file_name_in )
  {
    v8 = start_track_in;
  }
  else
  {
    v7 = v6->track_count;
    if( !v7 )
      return 0;
    v8 = start_track_in;
    if( start_track_in > v7 || !start_track_in )
      return 0;
    if( make_cur_track_in )
      v6->current_track = make_cur_track_in;
    else
      v6->current_track = start_track_in;
  }
  if( v6->music_type == 1 )
  {
    v6->play_info.dwCallback = (unsigned int)v6->window;
    v15 = 1;
    if( set_pos_in )
    {
      seek_info.dwTo = set_pos_in;
      v16 = v6->device_id;
      seek_info.dwCallback = 0;
      mciSendCommandA(v16, 0x807u, 0xAu, (DWORD_PTR)&seek_info);
      v8 = start_track_in;
    }
    else
    {
      v15 = 5;
      v6->play_info.dwFrom = LOBYTE(v6->current_track);
    }
    v17 = v6->track_count;
    if( v8 < v17 && end_track_in < v17 )
    {
      v15 |= 8u;
      v6->play_info.dwTo = (unsigned __int8)(end_track_in + 1);
    }
    v18 = mciSendCommandA(v6->device_id, 0x806u, v15, (DWORD_PTR)&v6->play_info);
    if( v18 )
    {
      if( !mciGetErrorStringA(v18, szErrorMsg, 0x100u) )
        strcpy(szErrorMsg, aUnknowError);
    }
    else
    {
      v19 = v6->notify_waiting;
      v6->playing_track = 1;
      v6->notify_waiting = v19 + 1;
    }
  }
  else if( v6->music_type == 2 )
  {
    if( file_name_in && *file_name_in )
    {
      sprintf(track_name, aSS, v6, file_name_in);
      if( !strchr(track_name, 46) )
        strcat(track_name, a_mid);
    }
    else
    {
      sprintf(track_name, aSmusicD_mid, v6, v6->current_track);
    }
    v9 = _open(track_name, 0);
    if( v9 != -1 )
    {
      _close(v9);
      v10 = (void (__stdcall *)(MCIDEVICEID, UINT, DWORD_PTR, DWORD_PTR))mciSendCommandA;
      open_info.lpstrDeviceType = (char *)523;
      open_info.lpstrElementName = track_name;
      v11 = mciSendCommandA(0, 0x803u, 0x3200u, (DWORD_PTR)&open_info);
      v12 = v11;
      if( !v11 )
        goto LABEL_52;
      if( !mciGetErrorStringA(v11, szErrorMsg, 0x100u) )
      {
        strcpy(szErrorMsg, aUnknowError);
        v10 = (void (__stdcall *)(MCIDEVICEID, UINT, DWORD_PTR, DWORD_PTR))mciSendCommandA;
      }
      if( !v12 )
      {
LABEL_52:
        v13 = open_info.wDeviceID;
        v6->device_id = open_info.wDeviceID;
        if( set_pos_in )
        {
          seek_info.dwTo = set_pos_in;
          seek_info.dwCallback = 0;
          v10(v13, 0x807u, 8u, (DWORD_PTR)&seek_info);
        }
        v6->play_info.dwCallback = (unsigned int)v6->window;
        if( !((MCIERROR (__stdcall *)(MCIDEVICEID, UINT, DWORD_PTR, DWORD_PTR))v10)(
                v6->device_id,
                0x806u,
                1u,
                (DWORD_PTR)&v6->play_info) )
        {
          v14 = v6->notify_waiting;
          v6->playing_track = 1;
          v6->notify_waiting = v14 + 1;
        }
      }
    }
  }
  else if( v6->music_type == 3 && v6->sound_system )
  {
    if( file_name_in && *file_name_in )
      sprintf(track_name, aSS, v6, file_name_in);
    else
      sprintf(track_name, aSmusicD_wav, v6, v6->current_track);
    if( !TSound_Driver::stream_file(v6->sound_system, track_name, 0, v6->volume) )
      return 0;
    v6->playing_track = 1;
  }
  if( v6->playing_track )
  {
    v6->paused = 0;
    v6->auto_paused = 0;
    v6->inactivated = 0;
    return 1;
  }
  return 0;
}

//----- (004625C0) --------------------------------------------------------
int __thiscall TMusic_System::pause_play(TMusic_System *this)
{
  int result; // eax@4
  int v2; // eax@5
  TSound_Driver *v3; // ecx@10

  if( this->device_open && this->playing_track )
  {
    if( this->paused )
    {
      this->auto_paused = 0;
      return 1;
    }
    v2 = this->auto_paused;
    this->paused = 1;
    if( v2 )
    {
      this->auto_paused = 0;
      return 1;
    }
    if( this->music_type == 1 )
    {
      mciSendCommandA(this->device_id, 0x809u, 2u, 0);
    }
    else
    {
      if( this->music_type == 2 )
      {
        mciSendCommandA(this->device_id, 0x809u, 2u, 0);
        return 1;
      }
      if( this->music_type == 3 )
      {
        v3 = this->sound_system;
        if( v3 )
        {
          TSound_Driver::pause_stream(v3);
          return 1;
        }
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00462670) --------------------------------------------------------
int __thiscall TMusic_System::resume_play(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  int v2; // eax@4
  TSound_Driver *v4; // ecx@9

  v1 = this;
  if( this->device_open && this->playing_track && this->paused )
  {
    v2 = this->fading_track;
    this->paused = 0;
    this->auto_paused = 0;
    if( v2 )
    {
      TMusic_System::end_fade(this);
      return 1;
    }
    if( this->music_type == 1 )
    {
      if( !mciSendCommandA(this->device_id, 0x806u, 0, (DWORD_PTR)&this->play_info) )
      {
LABEL_14:
        ++v1->notify_waiting;
        return 1;
      }
    }
    else
    {
      if( this->music_type != 2 )
      {
        if( this->music_type == 3 )
        {
          v4 = this->sound_system;
          if( v4 )
          {
            TSound_Driver::resume_stream(v4);
            return 1;
          }
        }
        return 1;
      }
      if( !mciSendCommandA(this->device_id, 0x806u, 0, (DWORD_PTR)&this->play_info) )
        goto LABEL_14;
    }
    return 1;
  }
  return 0;
}

//----- (00462740) --------------------------------------------------------
int __thiscall TMusic_System::stop_track(TMusic_System *this)
{
  this->loop = 0;
  this->start_track = 0;
  this->end_track = 0;
  this->file_name[0] = 0;
  this->fading_track = 0;
  return TMusic_System::stop_playing(this);
}

//----- (00462770) --------------------------------------------------------
int __thiscall TMusic_System::stop_playing(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  int result; // eax@2
  TSound_Driver *v3; // ecx@6
  MCIDEVICEID v4; // ST00_4@8

  v1 = this;
  if( this->playing_track )
  {
    switch ( this->music_type )
    {
      case 1:
        mciSendCommandA(this->device_id, 0x808u, 2u, 0);
        v1->playing_track = 0;
        break;
      case 2:
        mciSendCommandA(this->device_id, 0x808u, 2u, 0);
        v4 = v1->device_id;
        v1->playing_track = 0;
        mciSendCommandA(v4, 0x804u, 2u, 0);
        v1->device_id = 0;
        break;
      case 3:
        v3 = this->sound_system;
        if( v3 )
          TSound_Driver::stop_stream(v3);
        break;
    }
    v1->playing_track = 0;
    v1->paused = 0;
    v1->auto_paused = 0;
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00462820) --------------------------------------------------------
int __thiscall TMusic_System::fade_track(TMusic_System *this)
{
  char v1; // dl@1

  v1 = this->playing_track;
  this->loop = 0;
  this->start_track = 0;
  this->end_track = 0;
  this->file_name[0] = 0;
  this->fading_track = 0;
  if( v1 )
    TMusic_System::start_fade(this);
  return 1;
}

//----- (00462860) --------------------------------------------------------
void __thiscall TMusic_System::start_fade(TMusic_System *this)
{
  TMusic_System *v1; // esi@1

  v1 = this;
  if( !this->fading_track )
  {
    this->fade_volume = this->volume;
    this->last_fade_time = debug_timeGetTime();
    v1->fading_track = 1;
  }
}

//----- (004628A0) --------------------------------------------------------
void __thiscall TMusic_System::do_fade(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  double v2; // st7@5
  int v3; // edi@5
  float time; // [sp+8h] [bp-10h]@2

  v1 = this;
  if( !this->paused )
  {
    time = (double)(debug_timeGetTime() - this->last_fade_time);
    if( v1->fade_volume <= -10000 && v1->playing_track )
      TMusic_System::stop_playing(v1);
    v2 = (double)v1->fade_time;
    v3 = (unsigned __int64)(signed __int64)(time / v2 * -10000.0) + v1->fade_volume;
    v1->fade_volume = v3;
    if( v3 > (signed int)(-10000 - (unsigned __int64)(signed __int64)(250.0 / v2 * 10000.0)) )
    {
      TMusic_System::set_volume(v1, v3, 0);
      v1->last_fade_time = debug_timeGetTime();
    }
    else
    {
      if( v1->playing_track )
        TMusic_System::stop_playing(v1);
      if( v1->fading_track )
        TMusic_System::end_fade(v1);
    }
  }
}

//----- (004629B0) --------------------------------------------------------
void __thiscall TMusic_System::end_fade(TMusic_System *this)
{
  TMusic_System *v1; // esi@1
  int v2; // eax@1
  int v3; // eax@1

  v1 = this;
  v2 = this->volume;
  this->fading_track = 0;
  TMusic_System::set_volume(this, v2, 0);
  v3 = v1->start_track;
  if( v3 > 0 && v1->end_track > 0 || v1->file_name[0] )
    TMusic_System::play(v1, v3, v1->end_track, v1->file_name, v1->make_cur_track, v1->set_pos);
}

//----- (00462A10) --------------------------------------------------------
unsigned int __thiscall TMusic_System::handle_messages(TMusic_System *this, void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
  TMusic_System *v5; // esi@1
  int v6; // eax@4
  char v8; // cl@17
  int v9; // eax@19

  v5 = this;
  if( msg > 0x113 )
  {
    if( msg == 953 )
    {
      v8 = this->music_type;
      if( v8 == 1 || v8 == 2 )
      {
        v9 = v5->notify_waiting;
        if( v9 > 0 )
          v5->notify_waiting = v9 - 1;
        if( !v5->notify_waiting && !v5->paused )
        {
          if( v8 == 1 )
            v5->playing_track = 0;
          TMusic_System::after_end_track(v5);
        }
      }
    }
    else if( msg == 1280 && this->music_type == 3 && !this->paused )
    {
      this->playing_track = 0;
      TMusic_System::after_end_track(this);
      return 0;
    }
  }
  else if( msg == 275 )
  {
    if( this->fading_track )
    {
      TMusic_System::do_fade(this);
      return 0;
    }
  }
  else if( msg == 28 )
  {
    v6 = this->inactivated;
    if( wparam )
    {
      if( v6 && this->auto_paused )
      {
        TMusic_System::resume_play(this);
        v5->auto_paused = 0;
        v5->inactivated = 0;
        return 0;
      }
    }
    else if( !v6 )
    {
      TMusic_System::pause_play(this);
      v5->auto_paused = 1;
      v5->inactivated = 1;
      return 0;
    }
  }
  return 0;
}

//----- (00462B40) --------------------------------------------------------
void __thiscall TMusic_System::after_end_track(TMusic_System *this)
{
  char v1; // bl@5
  char *v2; // edx@5
  int v3; // eax@6
  int v4; // eax@10

  if( this->music_type == 1 )
  {
    if( !this->fading_track && this->loop )
    {
LABEL_17:
      TMusic_System::play(this, this->start_track, this->end_track, 0, 0, 0);
      return;
    }
  }
  else
  {
    if( this->music_type == 2 )
    {
      if( this->fading_track )
        return;
      v1 = this->file_name[0];
      v2 = this->file_name;
      if( !v1 )
      {
        v4 = this->current_track;
        if( v4 < this->end_track )
        {
          TMusic_System::play(this, v4 + 1, v4 + 1, 0, 0, 0);
          return;
        }
      }
LABEL_12:
      if( !this->loop )
        return;
      if( v1 )
      {
        TMusic_System::play(this, 0, 0, v2, 0, 0);
        return;
      }
      goto LABEL_17;
    }
    if( this->music_type == 3 && !this->fading_track )
    {
      v1 = this->file_name[0];
      v2 = this->file_name;
      if( !v1 )
      {
        v3 = this->current_track;
        if( v3 < this->end_track )
        {
          TMusic_System::play(this, v3 + 1, v3 + 1, 0, 0, 0);
          return;
        }
      }
      goto LABEL_12;
    }
  }
}

//----- (00462C30) --------------------------------------------------------
int __thiscall TMusic_System::get_play_info(TMusic_System *this, char *music_type_in, int *track_from_in, int *track_to_in, int *cur_track_in, char *music_file_in, int *loop_in, unsigned int *pos_in)
{
  unsigned int v9; // ST00_4@6
  unsigned int v10; // ST00_4@8
  tagMCI_STATUS_PARMS status_info; // [sp+10h] [bp-10h]@6

  *music_type_in = this->music_type;
  *track_from_in = 0;
  *track_to_in = 0;
  *cur_track_in = 0;
  *music_file_in = 0;
  *loop_in = 0;
  *pos_in = 0;
  if( !this->device_open )
    return 0;
  if( this->playing_track )
  {
    *track_from_in = this->start_track;
    *track_to_in = this->end_track;
    *cur_track_in = this->current_track;
    strcpy(music_file_in, this->file_name);
    *loop_in = this->loop;
    *pos_in = 0;
    if( this->music_type != 1 )
    {
      if( this->music_type != 2 )
        return 1;
      v9 = this->device_id;
      status_info.dwItem = 2;
      if( mciSendCommandA(v9, 0x814u, 0x102u, (DWORD_PTR)&status_info) )
        return 1;
      goto LABEL_9;
    }
    v10 = this->device_id;
    status_info.dwItem = 2;
    if( !mciSendCommandA(v10, 0x814u, 0x102u, (DWORD_PTR)&status_info) )
    {
LABEL_9:
      *pos_in = status_info.dwReturn;
      return 1;
    }
  }
  return 1;
}
