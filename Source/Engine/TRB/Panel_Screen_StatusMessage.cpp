
//----- (004B7140) --------------------------------------------------------
void __thiscall TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(TRIBE_Screen_Status_Message *this, char *name, char *message_in, char *info_file_in, int info_id_in)
{
  TRIBE_Screen_Status_Message *v5; // ebx@1
  TPanel *v6; // eax@1
  TEasy_Panel *v7; // ebp@1
  int v8; // eax@5
  unsigned int v9; // ecx@7
  char v10; // al@7
  char *v11; // edi@7
  char *v12; // esi@7
  unsigned int v13; // ecx@10
  char v14; // al@10
  char *v15; // edi@10
  char *v16; // esi@10
  unsigned int v17; // ecx@11
  char v18; // al@11
  char *v19; // edi@11
  char *v20; // esi@11
  char info_file[260]; // [sp+14h] [bp-110h]@5
  int v22; // [sp+120h] [bp-4h]@1

  v5 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, name);
  v22 = 0;
  v5->vfptr = (TPanelVtbl *)&TRIBE_Screen_Status_Message::`vftable';
  v5->message = 0;
  v6 = TPanelSystem::currentPanel(&panel_system);
  v7 = (TEasy_Panel *)v6;
  if ( info_file_in || info_id_in != -1 )
  {
    v9 = strlen(info_file_in) + 1;
    v10 = v9;
    v9 >>= 2;
    qmemcpy(info_file, info_file_in, 4 * v9);
    v12 = &info_file_in[4 * v9];
    v11 = &info_file[4 * v9];
    LOBYTE(v9) = v10;
    v8 = info_id_in;
    qmemcpy(v11, v12, v9 & 3);
  }
  else if ( v6 && v6 != TPanelSystem::panel(&panel_system, aAchievementsSc) )
  {
    strcpy(info_file, TEasy_Panel::get_info_file(v7));
    v8 = TEasy_Panel::get_info_id(v7);
  }
  else
  {
    info_file[0] = 0;
    v8 = -1;
  }
  if ( !info_file[0] )
  {
    if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
    {
      v13 = strlen(info_file_name_in) + 1;
      v14 = v13;
      v13 >>= 2;
      qmemcpy(info_file, info_file_name_in, 4 * v13);
      v16 = &info_file_name_in[4 * v13];
      v15 = &info_file[4 * v13];
      LOBYTE(v13) = v14;
      v8 = 50053;
      qmemcpy(v15, v16, v13 & 3);
    }
    else
    {
      v17 = strlen(aScr2) + 1;
      v18 = v17;
      v17 >>= 2;
      qmemcpy(info_file, aScr2, 4 * v17);
      v20 = &aScr2[4 * v17];
      v19 = &info_file[4 * v17];
      LOBYTE(v17) = v18;
      v8 = 50052;
      qmemcpy(v19, v20, v17 & 3);
    }
  }
  if ( TScreenPanel::setup((TScreenPanel *)&v5->vfptr, rge_base_game->draw_area, info_file, v8, 0) )
  {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v5->vfptr, 640, 480);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v5->vfptr,
      (TPanel *)&v5->vfptr,
      &v5->message,
      message_in,
      40,
      40,
      560,
      400,
      4,
      1,
      1,
      1);
  }
  else
  {
    v5->error_code = 1;
  }
}
// 5740C8: using guessed type int (__thiscall *TRIBE_Screen_Status_Message::`vftable')(void *Memory, unsigned int __flags);

//----- (004B7310) --------------------------------------------------------
TRIBE_Screen_Status_Message *__thiscall TRIBE_Screen_Status_Message::`vector deleting destructor'(TRIBE_Screen_Status_Message *this, unsigned int __flags)
{
  TRIBE_Screen_Status_Message *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B7330) --------------------------------------------------------
void __thiscall TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(TRIBE_Screen_Status_Message *this, char *name, int message_in, char *info_file_in, int info_id_in)
{
  TRIBE_Screen_Status_Message *v5; // ebx@1
  TPanel *v6; // eax@1
  TEasy_Panel *v7; // ebp@1
  int v8; // eax@5
  unsigned int v9; // ecx@7
  char v10; // al@7
  char *v11; // edi@7
  char *v12; // esi@7
  unsigned int v13; // ecx@10
  char v14; // al@10
  char *v15; // edi@10
  char *v16; // esi@10
  unsigned int v17; // ecx@11
  char v18; // al@11
  char *v19; // edi@11
  char *v20; // esi@11
  char info_file[260]; // [sp+14h] [bp-110h]@5
  int v22; // [sp+120h] [bp-4h]@1

  v5 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, name);
  v22 = 0;
  v5->vfptr = (TPanelVtbl *)&TRIBE_Screen_Status_Message::`vftable';
  v5->message = 0;
  v6 = TPanelSystem::currentPanel(&panel_system);
  v7 = (TEasy_Panel *)v6;
  if ( info_file_in || info_id_in != -1 )
  {
    v9 = strlen(info_file_in) + 1;
    v10 = v9;
    v9 >>= 2;
    qmemcpy(info_file, info_file_in, 4 * v9);
    v12 = &info_file_in[4 * v9];
    v11 = &info_file[4 * v9];
    LOBYTE(v9) = v10;
    v8 = info_id_in;
    qmemcpy(v11, v12, v9 & 3);
  }
  else if ( v6 && v6 != TPanelSystem::panel(&panel_system, aAchievementsSc) )
  {
    strcpy(info_file, TEasy_Panel::get_info_file(v7));
    v8 = TEasy_Panel::get_info_id(v7);
  }
  else
  {
    info_file[0] = 0;
    v8 = -1;
  }
  if ( !info_file[0] )
  {
    if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
    {
      v13 = strlen(info_file_name_in) + 1;
      v14 = v13;
      v13 >>= 2;
      qmemcpy(info_file, info_file_name_in, 4 * v13);
      v16 = &info_file_name_in[4 * v13];
      v15 = &info_file[4 * v13];
      LOBYTE(v13) = v14;
      v8 = 50053;
      qmemcpy(v15, v16, v13 & 3);
    }
    else
    {
      v17 = strlen(aScr2) + 1;
      v18 = v17;
      v17 >>= 2;
      qmemcpy(info_file, aScr2, 4 * v17);
      v20 = &aScr2[4 * v17];
      v19 = &info_file[4 * v17];
      LOBYTE(v17) = v18;
      v8 = 50052;
      qmemcpy(v19, v20, v17 & 3);
    }
  }
  if ( TScreenPanel::setup((TScreenPanel *)&v5->vfptr, rge_base_game->draw_area, info_file, v8, 0) )
  {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v5->vfptr, 640, 480);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v5->vfptr,
      (TPanel *)&v5->vfptr,
      &v5->message,
      message_in,
      40,
      40,
      560,
      400,
      4,
      1,
      1,
      1);
  }
  else
  {
    v5->error_code = 1;
  }
}
// 5740C8: using guessed type int (__thiscall *TRIBE_Screen_Status_Message::`vftable')(void *Memory, unsigned int __flags);

//----- (004B7500) --------------------------------------------------------
void __thiscall TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message(TRIBE_Screen_Status_Message *this)
{
  TRIBE_Screen_Status_Message *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Status_Message::`vftable';
  TPanel::delete_panel((TPanel **)&this->message);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5740C8: using guessed type int (__thiscall *TRIBE_Screen_Status_Message::`vftable')(void *Memory, unsigned int __flags);

//----- (004B7560) --------------------------------------------------------
void __thiscall TRIBE_Screen_Status_Message::set_text(TRIBE_Screen_Status_Message *this, char *message_in)
{
  (*(void (__stdcall **)(_DWORD))&this->message->vfptr[1].gap4[4])(message_in);
}

//----- (004B7580) --------------------------------------------------------
void __thiscall TRIBE_Screen_Status_Message::set_text(TRIBE_Screen_Status_Message *this, int message_in)
{
  (*(void (__stdcall **)(_DWORD))&this->message->vfptr[1].gap4[0])(message_in);
}
