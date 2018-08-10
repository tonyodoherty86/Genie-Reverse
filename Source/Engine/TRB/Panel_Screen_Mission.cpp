
//----- (004B8100) --------------------------------------------------------
void __thiscall TRIBE_Mission_Screen::TRIBE_Mission_Screen(TRIBE_Mission_Screen *this, char *text_in, char from_game, TPicture *background_bmp)
{
  TRIBE_Mission_Screen *v4; // ebp@1
  TButtonPanel **v5; // ebx@1
  int v6; // eax@1
  RGE_Base_Game *v7; // edx@1
  const char *v8; // eax@3
  TButtonPanel **v9; // esi@9
  TButtonPanel **v10; // edi@9
  signed int v11; // eax@11
  TPanelVtbl *v12; // edi@17
  char *v13; // eax@17
  TPanelVtbl *v14; // edi@21
  char *v15; // eax@21
  TPanelVtbl *v16; // edi@26
  char *v17; // eax@26
  int v18; // [sp+7Ah] [bp-230h]@0
  int v19; // [sp+7Eh] [bp-22Ch]@0
  int v20; // [sp+82h] [bp-228h]@0
  int v21; // [sp+86h] [bp-224h]@0
  char starting_description; // [sp+8Dh] [bp-21Dh]@1
  char *v23; // [sp+8Eh] [bp-21Ch]@5
  TRIBE_Mission_Screen *v24; // [sp+92h] [bp-218h]@1
  char adjusted_name[260]; // [sp+96h] [bp-214h]@5
  char info_file[260]; // [sp+19Ah] [bp-110h]@1
  int v27; // [sp+2A6h] [bp-4h]@1

  v4 = this;
  v24 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aMissionDialog);
  v5 = v4->text_buttons;
  v27 = 0;
  starting_description = 0;
  v4->title = 0;
  v4->ok_button = 0;
  v4->list = 0;
  v4->scroll_bar = 0;
  v4->vc_back_bmp = 0;
  v6 = (int)v4->text_buttons;
  v4->vfptr = (TPanelVtbl *)&TRIBE_Mission_Screen::`vftable';
  v4->game_flag = from_game;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  TPanelSystem::currentPanel(&panel_system);
  v7 = rge_base_game;
  strcpy(info_file, aScr9);
  if ( TScreenPanel::setup((TScreenPanel *)&v4->vfptr, v7->draw_area, info_file, 50060, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v4->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v4->vfptr, 640, 480);
    v8 = RGE_Scenario::Get_scenario_name(rge_base_game->world->scenario);
    if ( v8 && *v8 )
    {
      v23 = strcpy(adjusted_name, v8);
      *((_BYTE *)&v24 + strlen(v8)) = 0;
    }
    else
    {
      strcpy(adjusted_name, TPanel::get_string(9813));
    }
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->title,
      adjusted_name,
      10,
      15,
      620,
      20,
      4,
      1,
      1,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->list,
      text_in,
      15,
      70,
      300,
      340,
      11,
      0,
      0,
      1);
    TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v4->vfptr, &v4->scroll_bar, v4->list, 20);
    if ( v4->use_bevels )
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v4->list->vfptr[1].set_rect)(
        3,
        v4->bevel_color1,
        v4->bevel_color2,
        v4->bevel_color3,
        v4->bevel_color4,
        v4->bevel_color5,
        v4->bevel_color6);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->ok_button,
      4001,
      0,
      200,
      440,
      240,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      v4->text_buttons,
      10801,
      0,
      325,
      316,
      180,
      30,
      0,
      -1,
      0);
    v9 = &v4->text_buttons[1];
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->text_buttons[1],
      10802,
      0,
      325,
      348,
      180,
      30,
      0,
      -1,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->text_buttons[2],
      10807,
      0,
      325,
      380,
      180,
      30,
      0,
      -1,
      0);
    v10 = v4->text_buttons;
    v23 = (char *)3;
    do
    {
      TButtonPanel::set_radio_info(*v10, v4->text_buttons, 3);
      ++v10;
      --v23;
    }
    while ( v23 );
    v11 = v4->pnl_wid;
    if ( v11 > 640 )
    {
      if ( v11 > 800 )
      {
        TEasy_Panel::set_ideal_size((TEasy_Panel *)&v4->vfptr, 1024, 768);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int, int, int, int, int))v4->title->vfptr->set_fixed_position)(
          3,
          15,
          1018,
          20,
          v18,
          v19,
          v20,
          v21);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->list->vfptr->set_fixed_position)(
          40,
          65,
          944,
          310);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)*v5 + 28))(10, 690, 240, 50);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)*v9 + 28))(266, 690, 240, 50);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->text_buttons[2] + 28))(
          522,
          690,
          240,
          50);
        (*(void (__cdecl **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->ok_button + 28))(
          774,
          690,
          240,
          50);
      }
      else
      {
        TEasy_Panel::set_ideal_size((TEasy_Panel *)&v4->vfptr, 800, 640);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int, int, int, int, int))v4->title->vfptr->set_fixed_position)(
          3,
          15,
          794,
          20,
          v18,
          v19,
          v20,
          v21);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->list->vfptr->set_fixed_position)(
          30,
          45,
          740,
          230);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)*v5 + 28))(5, 565, 190, 30);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)*v9 + 28))(205, 565, 190, 30);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->text_buttons[2] + 28))(
          405,
          565,
          190,
          30);
        (*(void (__cdecl **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->ok_button + 28))(
          605,
          565,
          190,
          30);
      }
    }
    else
    {
      ((void (__stdcall *)(signed int, signed int, signed int, signed int, int, int, int, int))v4->title->vfptr->set_fixed_position)(
        3,
        15,
        634,
        20,
        v18,
        v19,
        v20,
        v21);
      ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->list->vfptr->set_fixed_position)(
        20,
        50,
        600,
        115);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)*v5 + 28))(5, 445, 150, 30);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)*v9 + 28))(165, 445, 150, 30);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->text_buttons[2] + 28))(
        325,
        445,
        150,
        30);
      (*(void (__cdecl **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->ok_button + 28))(
        485,
        445,
        150,
        30);
    }
    if ( RGE_Scenario::Get_message(rge_base_game->world->scenario, 0) )
    {
      v12 = v4->list->vfptr;
      v13 = RGE_Scenario::Get_message(rge_base_game->world->scenario, 0);
      (*(void (__thiscall **)(TTextPanel *, char *))&v12[1].gap4[4])(v4->list, v13);
      TButtonPanel::set_radio_button(*v9);
      starting_description = 1;
    }
    else
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v9 + 20))(0);
    }
    if ( RGE_Scenario::Get_message(rge_base_game->world->scenario, 4) )
    {
      if ( !starting_description )
      {
        v14 = v4->list->vfptr;
        v15 = RGE_Scenario::Get_message(rge_base_game->world->scenario, 4);
        (*(void (__thiscall **)(TTextPanel *, char *))&v14[1].gap4[4])(v4->list, v15);
        TButtonPanel::set_radio_button(*v5);
      }
      ++starting_description;
    }
    else
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v5 + 20))(0);
    }
    if ( RGE_Scenario::Get_message(rge_base_game->world->scenario, 1) )
    {
      if ( !starting_description )
      {
        v16 = v4->list->vfptr;
        v17 = RGE_Scenario::Get_message(rge_base_game->world->scenario, 1);
        (*(void (__thiscall **)(TTextPanel *, char *))&v16[1].gap4[4])(v4->list, v17);
        TButtonPanel::set_radio_button(v4->text_buttons[2]);
      }
      ++starting_description;
    }
    else
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4->text_buttons[2] + 20))(0);
      if ( !starting_description )
        (*(void (__stdcall **)(_DWORD))&v4->list->vfptr->gap10[4])(0);
    }
    if ( starting_description == 1 )
    {
      (*(void (__thiscall **)(TButtonPanel *, _DWORD))(*(_DWORD *)*v5 + 20))(*v5, 0);
      (*(void (__thiscall **)(TButtonPanel *, _DWORD))(*(_DWORD *)*v9 + 20))(*v9, 0);
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4->text_buttons[2] + 20))(0);
    }
    TPanel::set_curr_child((TPanel *)&v4->vfptr, (TPanel *)v4->ok_button);
    v4->vc_back_bmp = background_bmp;
  }
  else
  {
    v4->error_code = 1;
  }
}
// 574318: using guessed type int (__thiscall *TRIBE_Mission_Screen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B87B0) --------------------------------------------------------
TRIBE_Mission_Screen *__thiscall TRIBE_Mission_Screen::`scalar deleting destructor'(TRIBE_Mission_Screen *this, unsigned int __flags)
{
  TRIBE_Mission_Screen *v2; // esi@1

  v2 = this;
  TRIBE_Mission_Screen::~TRIBE_Mission_Screen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B87D0) --------------------------------------------------------
void __thiscall TRIBE_Mission_Screen::~TRIBE_Mission_Screen(TRIBE_Mission_Screen *this)
{
  TRIBE_Mission_Screen *v1; // ebx@1
  TSound_Driver *v2; // ecx@3
  TTextPanel *v3; // ecx@5
  TTextPanel *v4; // ecx@7
  TScrollBarPanel *v5; // ecx@9
  TButtonPanel *v6; // ecx@11
  TButtonPanel **v7; // esi@13
  signed int v8; // edi@13

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Mission_Screen::`vftable';
  if ( !this->game_flag )
  {
    if ( rge_base_game->prog_info->use_sound )
    {
      v2 = rge_base_game->sound_system;
      if ( v2 )
        TSound_Driver::stop_stream(v2);
    }
  }
  v3 = v1->title;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->list;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->scroll_bar;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  v6 = v1->ok_button;
  if ( v6 )
    (**(void (__stdcall ***)(_DWORD))v6)(1);
  v7 = v1->text_buttons;
  v8 = 3;
  do
  {
    if ( *v7 )
      (**(void (__stdcall ***)(_DWORD))*v7)(1);
    ++v7;
    --v8;
  }
  while ( v8 );
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 574318: using guessed type int (__thiscall *TRIBE_Mission_Screen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B88B0) --------------------------------------------------------
int __thiscall TRIBE_Mission_Screen::handle_idle(TRIBE_Mission_Screen *this)
{
  TRIBE_Mission_Screen *v1; // esi@1

  v1 = this;
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004B88E0) --------------------------------------------------------
void __thiscall TRIBE_Mission_Screen::draw(TRIBE_Mission_Screen *this)
{
  TRIBE_Mission_Screen *v1; // esi@1
  TPanelVtbl *v2; // edi@2
  signed int v3; // eax@5
  int v4; // eax@6
  int v5; // edx@7
  int v6; // [sp-10h] [bp-14h]@6

  v1 = this;
  TScreenPanel::draw((TScreenPanel *)&this->vfptr);
  if ( v1->vc_back_bmp )
  {
    v2 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    if ( v1->need_redraw == 2 )
      TDrawArea::Clear(v1->render_area, &v1->clip_rect, v1->background_color1);
    if ( TDrawArea::Lock(v1->render_area, aScr_vcDraw, 1) )
    {
      v3 = v1->pnl_wid;
      if ( v3 > 640 )
      {
        v5 = v1->pnl_y;
        if ( v3 > 800 )
        {
          v6 = v5 + 363;
          v4 = v1->pnl_x + 197;
        }
        else
        {
          v6 = v5 + 280;
          v4 = v1->pnl_x + 83;
        }
      }
      else
      {
        v6 = v1->pnl_y + 166;
        v4 = v1->pnl_x + 7;
      }
      TPicture::Draw(v1->vc_back_bmp, v1->render_area, v4, v6, 0, 0);
      TDrawArea::Unlock(v1->render_area, aScr_vcDraw);
    }
    v2->draw_finish((TPanel *)v1);
  }
}

//----- (004B89A0) --------------------------------------------------------
int __thiscall TRIBE_Mission_Screen::action(TRIBE_Mission_Screen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TRIBE_Mission_Screen *v5; // esi@1
  TPanelVtbl *v6; // ebp@3
  char *v7; // eax@3
  TPanelVtbl *v8; // ebp@5
  char *v9; // eax@5
  TPanelVtbl *v10; // ebp@7
  char *v11; // eax@7
  int result; // eax@14

  v5 = this;
  if ( actionIn != 1 )
    goto LABEL_18;
  if ( fromPanel == (TPanel *)this->text_buttons[0] )
  {
    v6 = this->list->vfptr;
    v7 = RGE_Scenario::Get_message(rge_base_game->world->scenario, 4);
    (*(void (__thiscall **)(TTextPanel *, char *))&v6[1].gap4[4])(v5->list, v7);
  }
  if ( fromPanel == (TPanel *)v5->text_buttons[1] )
  {
    v8 = v5->list->vfptr;
    v9 = RGE_Scenario::Get_message(rge_base_game->world->scenario, 0);
    (*(void (__thiscall **)(TTextPanel *, char *))&v8[1].gap4[4])(v5->list, v9);
  }
  if ( fromPanel == (TPanel *)v5->text_buttons[2] )
  {
    v10 = v5->list->vfptr;
    v11 = RGE_Scenario::Get_message(rge_base_game->world->scenario, 1);
    (*(void (__thiscall **)(TTextPanel *, char *))&v10[1].gap4[4])(v5->list, v11);
  }
  if ( fromPanel != (TPanel *)v5->ok_button )
  {
LABEL_18:
    result = TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  }
  else
  {
    if ( v5->game_flag )
    {
      TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
      if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
        RGE_Base_Game::set_paused(rge_base_game, 0, 0);
    }
    else
    {
      TRIBE_Game::create_game_screen((TRIBE_Game *)rge_base_game);
    }
    TPanelSystem::destroyPanel(&panel_system, aMissionDialog);
    result = 1;
  }
  return result;
}

//----- (004B8AE0) --------------------------------------------------------
int __thiscall TRIBE_Mission_Screen::key_down_action(TRIBE_Mission_Screen *this, int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  TSound_Driver *v6; // ecx@5
  int result; // eax@7

  if ( ctrl_key && key == 86 )
  {
    if ( !this->game_flag && rge_base_game->prog_info->use_sound )
    {
      v6 = rge_base_game->sound_system;
      if ( v6 )
        TSound_Driver::stream_file(v6, aVoice_wav, 0, 0);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
