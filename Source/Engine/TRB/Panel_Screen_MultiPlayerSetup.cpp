
//----- (004A00B0) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::TribeMPSetupScreen(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // edi@1
  int v2; // esi@1
  char *v3; // ebx@3
  TDrawArea *v4; // esi@5
  int v5; // eax@5
  int v6; // eax@7
  int v7; // esi@15
  int v8; // ebp@16
  TDropDownPanel **v9; // ebx@16
  int v10; // eax@17
  TDropDownPanel *v11; // ecx@17
  TDropDownPanel **v12; // ebx@21
  TPanel **v13; // ebp@24
  signed int v14; // ebx@25
  bool v15; // sf@33
  unsigned __int8 v16; // of@33
  int v17; // esi@39
  TTextPanel **v18; // ebx@39
  TTextPanel **v19; // esi@44
  TButtonPanel **v20; // esi@53
  TPanel **v21; // esi@54
  TPanel **v22; // esi@56
  TButtonPanel **v23; // esi@59
  int v24; // ebx@68
  TPanel *v25; // esi@69
  int v26; // [sp-8h] [bp-130h]@18
  signed int y; // [sp+10h] [bp-118h]@15
  char str[256]; // [sp+1Ch] [bp-10Ch]@26
  int v29; // [sp+124h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aMpSetupScreen);
  v1->vfptr = (TPanelVtbl *)&TribeMPSetupScreen::`vftable';
  v29 = 0;
  TDebuggingLog::Log(L, aChatScreenCons);
  TribeMPSetupScreen::init_vars(v1);
  TChat::ClearChat(chat);
  v2 = 1;
  do
    TChat::setInChatGroup(chat, v2++, 1);
  while ( v2 < 9 );
  v3 = info_file_name_in;
  if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
    v3 = aScr2;
  v4 = rge_base_game->draw_area;
  v5 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ( !TEasy_Panel::setup((TEasy_Panel *)&v1->vfptr, v4, 0, v3, (v5 != 0) + 50052, 1, 0, 0, 0, 0, 1) )
  {
    v1->error_code = 1;
    return;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
  v6 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ( TEasy_Panel::create_text(
         (TEasy_Panel *)&v1->vfptr,
         (TPanel *)&v1->vfptr,
         &v1->title,
         9679 - (v6 != 0),
         20,
         6,
         600,
         30,
         1,
         1,
         0,
         0)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v1->vfptr,
         (TPanel *)&v1->vfptr,
         &v1->playerTitle,
         9680,
         26,
         50,
         160,
         30,
         0,
         0,
         1,
         0)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v1->vfptr,
         (TPanel *)&v1->vfptr,
         &v1->civTitle,
         9681,
         189,
         50,
         160,
         30,
         0,
         0,
         1,
         0)
    && (RGE_Base_Game::singlePlayerGame(rge_base_game)
     || TCommunications_Handler::IsHost(comm)
     || TEasy_Panel::create_text(
          (TEasy_Panel *)&v1->vfptr,
          (TPanel *)&v1->vfptr,
          &v1->settingsTitle,
          9682,
          420,
          50,
          210,
          30,
          0,
          0,
          1,
          0)) )
  {
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->colorTitle,
           9646,
           240,
           50,
           100,
           30,
           0,
           0,
           1,
           0) )
    {
      TTextPanel::set_alignment(v1->colorTitle, 0, AlignRight);
      if ( TEasy_Panel::create_text(
             (TEasy_Panel *)&v1->vfptr,
             (TPanel *)&v1->vfptr,
             &v1->teamTitle,
             9647,
             310,
             50,
             100,
             30,
             0,
             0,
             1,
             0) )
      {
        TTextPanel::set_alignment(v1->teamTitle, 0, AlignRight);
        y = 85;
        v7 = (int)v1->playerCivDrop;
        do
        {
          v8 = y - 1;
          v9 = (TDropDownPanel **)(v7 - 32);
          if ( !TEasy_Panel::create_drop_down(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TDropDownPanel **)(v7 - 32),
                  158,
                  100,
                  7,
                  y - 1,
                  158,
                  24,
                  11) )
            return;
          TDropDownPanel::set_draw_style(*v9, (int)v9, v8, (int)v1, DrawStyleLeftButton);
          TDropDownPanel::set_draw_val_rect(*v9, 0);
          TPanel::set_help_info((TPanel *)&(*v9)->vfptr, 30201, -1);
          TDropDownPanel::empty_list(*v9);
          v10 = RGE_Base_Game::multiplayerGame(rge_base_game);
          v11 = *v9;
          if ( v10 )
          {
            TDropDownPanel::append_line(v11, 9683, 4);
            TDropDownPanel::append_line(*v9, 9684, 1);
            v26 = 9685;
          }
          else
          {
            TDropDownPanel::append_line(v11, 9683, 4);
            v26 = 9686;
          }
          TDropDownPanel::append_line(*v9, v26, 0);
          if ( !TEasy_Panel::create_drop_down(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TDropDownPanel **)v7,
                  128,
                  100,
                  170,
                  v8,
                  128,
                  24,
                  11) )
            return;
          TDropDownPanel::set_draw_style(*(TDropDownPanel **)v7, (int)v9, v8, (int)v1, DrawStyleLeftButton);
          TDropDownPanel::set_draw_val_rect(*(TDropDownPanel **)v7, 0);
          TPanel::set_help_info(*(TPanel **)v7, 30202, 155401);
          TDropDownPanel::empty_list(*(TDropDownPanel **)v7);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10231, 1);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10232, 2);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10233, 3);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10234, 4);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10235, 5);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10236, 6);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10237, 7);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10238, 8);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10239, 9);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10240, 10);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10241, 11);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10242, 12);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10246, 13);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10247, 14);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10249, 15);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10248, 16);
          TDropDownPanel::append_line(*(TDropDownPanel **)v7, 10250, 17);
          v12 = (TDropDownPanel **)(v7 + 32);
          if ( !TEasy_Panel::create_drop_down(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TDropDownPanel **)(v7 + 32),
                  40,
                  100,
                  324,
                  v8,
                  40,
                  24,
                  11) )
            return;
          TDropDownPanel::set_draw_style(*v12, (int)v12, v8, (int)v1, DrawStyleLeftButton);
          TDropDownPanel::set_draw_val_rect(*v12, 0);
          TPanel::set_help_info((TPanel *)&(*v12)->vfptr, 30203, -1);
          if ( !TEasy_Panel::create_button(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TButtonPanel **)(v7 - 96),
                  message_in,
                  0,
                  310,
                  y,
                  30,
                  20,
                  11,
                  0,
                  1) )
            return;
          TPanel::set_help_info(*(TPanel **)(v7 - 96), 30212, -1);
          if ( !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 160),
                  message_in,
                  305,
                  y,
                  40,
                  22,
                  11,
                  1,
                  1,
                  0) )
            return;
          v13 = (TPanel **)(v7 - 64);
          if ( !TEasy_Panel::create_button(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TButtonPanel **)(v7 - 64),
                  9648,
                  0,
                  380,
                  y,
                  30,
                  20,
                  11,
                  0,
                  1) )
            return;
          TPanel::set_help_info(*v13, 30211, -1);
          TButtonPanel::set_state_info((TButtonPanel *)*v13, 5);
          v14 = 1;
          do
          {
            sprintf(str, aD_3, v14);
            TButtonPanel::set_text((TButtonPanel *)*v13, v14, str);
            TButtonPanel::set_id((TButtonPanel *)*v13, v14, v14 + 1, 0);
            ++v14;
          }
          while ( v14 < 5 );
          if ( !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 128),
                  message_in,
                  375,
                  y,
                  40,
                  22,
                  11,
                  1,
                  1,
                  0)
            || !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 320),
                  message_in,
                  28,
                  y + 2,
                  139,
                  22,
                  11,
                  0,
                  0,
                  0)
            || !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 288),
                  message_in,
                  191,
                  y + 2,
                  109,
                  22,
                  11,
                  0,
                  0,
                  0)
            || !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 256),
                  message_in,
                  345,
                  y + 2,
                  40,
                  22,
                  11,
                  0,
                  0,
                  0)
            || !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 224),
                  9695,
                  337,
                  y + 3,
                  20,
                  22,
                  6,
                  0,
                  0,
                  0)
            || !TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  (TTextPanel **)(v7 - 192),
                  message_in,
                  353,
                  y + 3,
                  29,
                  22,
                  6,
                  0,
                  0,
                  0) )
          {
            return;
          }
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v7 - 224) + 20))(0);
          v7 += 4;
          v16 = __OFSUB__(y + 24, 277);
          v15 = y - 253 < 0;
          y += 24;
        }
        while ( v15 ^ v16 );
        if ( RGE_Base_Game::singlePlayerGame(rge_base_game) || TCommunications_Handler::IsHost(comm) )
        {
          if ( !TEasy_Panel::create_button(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  &v1->gameSettingsButton,
                  9682,
                  0,
                  420,
                  50,
                  210,
                  30,
                  0,
                  0,
                  0) )
            return;
          TPanel::set_help_info((TPanel *)v1->gameSettingsButton, 30204, -1);
        }
        if ( TEasy_Panel::create_text(
               (TEasy_Panel *)&v1->vfptr,
               (TPanel *)&v1->vfptr,
               &v1->scenarioName,
               message_in,
               420,
               84,
               220,
               68,
               11,
               0,
               0,
               1) )
        {
          v17 = 83;
          v18 = v1->settingText;
          do
          {
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    v18,
                    message_in,
                    420,
                    v17,
                    220,
                    20,
                    11,
                    0,
                    0,
                    0) )
              return;
            v17 += 24;
            ++v18;
          }
          while ( v17 < 563 );
          if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
          {
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->chatTitle,
                    9687,
                    10,
                    280,
                    100,
                    20,
                    4,
                    0,
                    1,
                    0) )
              return;
            v19 = &v1->chatBox;
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->chatBox,
                    message_in,
                    10,
                    300,
                    400,
                    96,
                    10,
                    0,
                    0,
                    0)
              || !TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->chatScrollbar, *v19, 20)
              || !TEasy_Panel::create_edit(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->chatInput,
                    message_in,
                    247,
                    0,
                    10,
                    402,
                    400,
                    23,
                    10,
                    1,
                    0) )
            {
              return;
            }
            TPanel::set_help_info((TPanel *)&v1->chatInput->vfptr, 30206, -1);
            ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*v19)->vfptr[1].set_rect)(
              3,
              v1->bevel_color1,
              v1->bevel_color2,
              v1->bevel_color3,
              v1->bevel_color4,
              v1->bevel_color5,
              v1->bevel_color6);
            TPanel::set_help_info((TPanel *)&(*v19)->vfptr, 30205, -1);
            TTextPanel::empty_list(*v19);
          }
          if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
          {
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->numberPlayersTitle,
                    9688,
                    26,
                    295,
                    335,
                    20,
                    0,
                    0,
                    1,
                    0)
              || !TEasy_Panel::create_drop_down(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->numberPlayersDrop,
                    70,
                    100,
                    31,
                    322,
                    70,
                    24,
                    11) )
            {
              return;
            }
            TPanel::set_help_info((TPanel *)&v1->numberPlayersDrop->vfptr, 30208, -1);
          }
          v1->i_am_ready = 0;
          if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
          {
            v20 = &v1->startButton;
            if ( !TEasy_Panel::create_button(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->startButton,
                    message_in,
                    0,
                    70,
                    440,
                    240,
                    30,
                    0,
                    0,
                    0) )
              return;
            TButtonPanel::set_text(*v20, 0, 9710);
            TPanel::set_help_info((TPanel *)*v20, 30207, -1);
            TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)*v20);
            v21 = (TPanel **)&v1->cancelButton;
            if ( !TEasy_Panel::create_button(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->cancelButton,
                    4002,
                    0,
                    330,
                    440,
                    240,
                    30,
                    0,
                    0,
                    0) )
              return;
          }
          else
          {
            v22 = (TPanel **)&v1->ready_button;
            if ( TCommunications_Handler::IsHost(comm) )
            {
              if ( !TEasy_Panel::create_check_box(
                      (TEasy_Panel *)&v1->vfptr,
                      (TPanel *)&v1->vfptr,
                      &v1->ready_button,
                      10,
                      440,
                      30,
                      30,
                      0,
                      0) )
                return;
              if ( !TEasy_Panel::create_text(
                      (TEasy_Panel *)&v1->vfptr,
                      (TPanel *)&v1->vfptr,
                      &v1->ready_button_label,
                      9663,
                      45,
                      440,
                      150,
                      30,
                      0,
                      0,
                      1,
                      0) )
                return;
              TPanel::set_help_info(*v22, 30210, -1);
              v23 = &v1->startButton;
              if ( !TEasy_Panel::create_button(
                      (TEasy_Panel *)&v1->vfptr,
                      (TPanel *)&v1->vfptr,
                      &v1->startButton,
                      message_in,
                      0,
                      195,
                      440,
                      200,
                      30,
                      0,
                      0,
                      0) )
                return;
              TButtonPanel::set_text(*v23, 0, 9710);
              TPanel::set_help_info((TPanel *)*v23, 30207, -1);
              TButtonPanel::set_disabled(*v23, 1);
              v21 = (TPanel **)&v1->cancelButton;
              if ( !TEasy_Panel::create_button(
                      (TEasy_Panel *)&v1->vfptr,
                      (TPanel *)&v1->vfptr,
                      &v1->cancelButton,
                      4002,
                      0,
                      405,
                      440,
                      180,
                      30,
                      0,
                      0,
                      0) )
                return;
              TPanel::set_help_info(*v21, 30002, -1);
              if ( !TEasy_Panel::create_button(
                      (TEasy_Panel *)&v1->vfptr,
                      (TPanel *)&v1->vfptr,
                      &v1->netInfoButton,
                      9711,
                      0,
                      600,
                      400,
                      30,
                      30,
                      0,
                      0,
                      0) )
                return;
              TPanel::set_help_info((TPanel *)v1->netInfoButton, 30209, -1);
              TCommunications_Handler::SetMyReadiness(comm, 0, 0, 0, 0, 0, 0, 0, 0);
              goto LABEL_67;
            }
            if ( !TEasy_Panel::create_check_box(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->ready_button,
                    100,
                    440,
                    30,
                    30,
                    0,
                    0) )
              return;
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->ready_button_label,
                    9663,
                    135,
                    440,
                    150,
                    30,
                    0,
                    0,
                    1,
                    0) )
              return;
            TPanel::set_help_info(*v22, 30210, -1);
            v21 = (TPanel **)&v1->cancelButton;
            if ( !TEasy_Panel::create_button(
                    (TEasy_Panel *)&v1->vfptr,
                    (TPanel *)&v1->vfptr,
                    &v1->cancelButton,
                    4002,
                    0,
                    330,
                    440,
                    240,
                    30,
                    0,
                    0,
                    0) )
              return;
          }
          TPanel::set_help_info(*v21, 30002, -1);
LABEL_67:
          if ( TEasy_Panel::create_button(
                 (TEasy_Panel *)&v1->vfptr,
                 (TPanel *)&v1->vfptr,
                 &v1->help_button,
                 4009,
                 0,
                 600,
                 440,
                 30,
                 30,
                 0,
                 0,
                 0) )
          {
            v24 = (int)&v1->close_button;
            if ( TEasy_Panel::create_button(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->close_button,
                   1002,
                   0,
                   0,
                   0,
                   0,
                   0,
                   -1,
                   -1,
                   0) )
            {
              (*(void (__stdcall **)(signed int))(**(_DWORD **)v24 + 20))(1);
              (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v24 + 24))(
                9,
                4,
                4,
                4,
                4,
                17,
                17,
                17,
                17,
                0,
                0,
                0,
                0);
              v25 = *v21;
              v25[2].max_wid = 27;
              v25[2].min_hgt = 0;
              TribeMPSetupScreen::setupTabOrder(v1);
              TDebuggingLog::Log(L, aChatScreenUpda);
              TribeMPSetupScreen::updateSummary(v1);
              if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
              {
                TribeMPSetupScreen::setupSinglePlayerPlayers(v1);
                TribeMPSetupScreen::fillPlayers(v1);
              }
              TDebuggingLog::Log(L, aChatScreenCo_1);
            }
          }
          return;
        }
      }
    }
  }
}
// 5732C8: using guessed type int (__thiscall *TribeMPSetupScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004A0D60) --------------------------------------------------------
TribeMPSetupScreen *__thiscall TribeMPSetupScreen::`scalar deleting destructor'(TribeMPSetupScreen *this, unsigned int __flags)
{
  TribeMPSetupScreen *v2; // esi@1

  v2 = this;
  TribeMPSetupScreen::~TribeMPSetupScreen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A0D80) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::init_vars(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // esi@1
  char *v2; // eax@1
  signed int v3; // ecx@1
  TTextPanel **v4; // eax@3
  signed int v5; // ecx@3
  int v6; // eax@6
  unsigned int v7; // eax@6
  signed int v8; // ebx@6
  char v9; // al@7
  int v10; // edx@11
  signed int v11; // eax@12
  int v12; // eax@27

  v1 = this;
  this->title = 0;
  this->playerTitle = 0;
  this->civTitle = 0;
  this->settingsTitle = 0;
  this->colorTitle = 0;
  this->teamTitle = 0;
  v2 = (char *)this->playerCivDrop;
  v3 = 8;
  do
  {
    *((_DWORD *)v2 - 8) = 0;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 8) = 0;
    *((_DWORD *)v2 - 24) = 0;
    *((_DWORD *)v2 - 16) = 0;
    *((_DWORD *)v2 - 80) = 0;
    *((_DWORD *)v2 - 72) = 0;
    *((_DWORD *)v2 - 64) = 0;
    *((_DWORD *)v2 - 56) = 0;
    *((_DWORD *)v2 - 48) = 0;
    *((_DWORD *)v2 - 40) = 0;
    *((_DWORD *)v2 - 32) = 0;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  v1->chatInput = 0;
  v1->chatTitle = 0;
  v1->chatScrollbar = 0;
  v1->chatBox = 0;
  v1->gameSettingsButton = 0;
  v1->scenarioName = 0;
  v1->victoryFixedText = 0;
  v4 = v1->settingValue;
  v5 = 20;
  do
  {
    *(v4 - 20) = 0;
    *v4 = 0;
    ++v4;
    --v5;
  }
  while ( v5 );
  v1->mapSizeLabel = 0;
  v1->mapSizeDrop = 0;
  v1->mapTypeLabel = 0;
  v1->mapTypeDrop = 0;
  v1->numberPlayersTitle = 0;
  v1->numberPlayersDrop = 0;
  v1->numberPlayersText = 0;
  v1->hiddenMapButton = 0;
  v1->hiddenMapText = 0;
  v1->victoryTypeLabel = 0;
  v1->victoryTypeDrop = 0;
  v1->victoryAmountLabel = 0;
  v1->victoryAmountInput = 0;
  v1->ready_button_label = 0;
  v1->startButton = 0;
  v1->readyButtons[0] = 0;
  v1->readyButtons[1] = 0;
  v1->cancelButton = 0;
  v1->help_button = 0;
  v1->ready_button = 0;
  v1->close_button = 0;
  v1->cancelMode = 0;
  v1->playerToKick = 0;
  v1->myCivilization = 0;
  v1->myScenarioPlayer = -1;
  v1->myPlayerColor = 0;
  v1->myPlayerTeam = 0;
  v1->myScenarioChecksum = 0;
  v1->saveScenarioName[0] = 0;
  v1->saveRandomGame = RGE_Base_Game::randomGame(rge_base_game);
  v1->saveScenarioChecksum = 0;
  v1->scenarioInfo = 0;
  v1->numberAnyPlayers = 8;
  v1->scenarioPlayerCount = 8;
  v1->settingsFixed = 0;
  v1->sent_cd_status = 0;
  v1->netInfoButton = 0;
  v1->i_am_ready = 0;
  memset(v1->scenarioCheckSum, 0, sizeof(v1->scenarioCheckSum));
  v1->last_send_shared = 0;
  v1->resend_game_options = 0;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    RGE_Base_Game::setCampaignGame(rge_base_game, 0);
    RGE_Base_Game::setSavedGame(rge_base_game, 0);
    RGE_Base_Game::setScenarioGame(rge_base_game, 0);
    RGE_Base_Game::setScenarioName(rge_base_game, message_in);
    TRIBE_Game::setMapSize((TRIBE_Game *)rge_base_game, Large);
    TRIBE_Game::setMapType((TRIBE_Game *)rge_base_game, MostlyLand);
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game, 0, 0);
    TRIBE_Game::setAnimals((TRIBE_Game *)rge_base_game, 1);
    TRIBE_Game::setPredators((TRIBE_Game *)rge_base_game, 1);
    RGE_Base_Game::setNumberPlayers(rge_base_game, 8);
    RGE_Base_Game::setFullVisibility(rge_base_game, 0);
    RGE_Base_Game::setFogOfWar(rge_base_game, 1);
    RGE_Base_Game::setAllowCheatCodes(rge_base_game, 0);
    TRIBE_Game::setRandomizePositions((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setLongCombat((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setAllowTrading((TRIBE_Game *)rge_base_game, 1);
    TRIBE_Game::setFullTechTree((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setStartingAge((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setStartingUnits((TRIBE_Game *)rge_base_game, 0);
    v6 = RGE_Base_Game::get_single_player_difficulty(rge_base_game);
    RGE_Base_Game::setDifficulty(rge_base_game, v6);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game, 0);
    v7 = debug_timeGetTime();
    debug_srand(aCMsdevWorkA_42, 579, v7);
    v8 = 0;
    do
    {
      v1->defaultColor[v8] = v8 + 1;
      v9 = debug_rand(aCMsdevWorkA_42, 584);
      TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v8, (unsigned __int8)(v9 % -16) + 1);
      TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v8, v8);
      RGE_Base_Game::setPlayerHasCD(rge_base_game, v8, 0);
      RGE_Base_Game::setPlayerVersion(rge_base_game, v8, 0);
      TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v8, v1->defaultColor[v8]);
      RGE_Base_Game::setPlayerTeam(rge_base_game, v8, 1);
      TRIBE_Game::setComputerName((TRIBE_Game *)rge_base_game, v8++, 0);
    }
    while ( v8 < 8 );
    if ( TCommunications_Handler::IsHost(comm) )
    {
      RGE_Base_Game::setPlayerVersion(rge_base_game, 0, 1);
      ((void (*)(void))rge_base_game->vfptr->send_game_options)();
      v1->resend_game_options = 0;
    }
  }
  else
  {
    if ( !RGE_Base_Game::scenarioGame(rge_base_game) )
    {
      TRIBE_Game::setMapSize((TRIBE_Game *)rge_base_game, Large);
      v10 = debug_rand(aCMsdevWorkA_42, 618) % 10;
      if ( v10 >= 2 )
      {
        switch ( v10 )
        {
          case 2:
            v11 = 3;
            break;
          case 3:
            v11 = 2;
            break;
          case 4:
            v11 = 1;
            break;
          case 5:
            v11 = 5;
            break;
          case 6:
            v11 = 6;
            break;
          case 7:
            v11 = 7;
            break;
          default:
            v11 = v10 != 8 ? 0 : 8;
            break;
        }
      }
      else
      {
        v11 = 4;
      }
      TRIBE_Game::setMapType((TRIBE_Game *)rge_base_game, (TRIBE_Game::MapType)v11);
    }
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game, 0, 0);
    RGE_Base_Game::setNumberPlayers(rge_base_game, 4);
    RGE_Base_Game::setCampaignGame(rge_base_game, 0);
    RGE_Base_Game::setSavedGame(rge_base_game, 0);
    TRIBE_Game::setAnimals((TRIBE_Game *)rge_base_game, 1);
    TRIBE_Game::setPredators((TRIBE_Game *)rge_base_game, 1);
    RGE_Base_Game::setFullVisibility(rge_base_game, 0);
    RGE_Base_Game::setFogOfWar(rge_base_game, 1);
    RGE_Base_Game::setAllowCheatCodes(rge_base_game, 1);
    TRIBE_Game::setRandomizePositions((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setLongCombat((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setAllowTrading((TRIBE_Game *)rge_base_game, 1);
    TRIBE_Game::setFullTechTree((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setStartingAge((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setStartingUnits((TRIBE_Game *)rge_base_game, 0);
    v12 = RGE_Base_Game::get_single_player_difficulty(rge_base_game);
    RGE_Base_Game::setDifficulty(rge_base_game, v12);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game, 0);
  }
}

//----- (004A1300) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::~TribeMPSetupScreen(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // esi@1
  T_Scenario *v2; // ecx@1
  int v3; // edi@3
  signed int v4; // ebx@3
  TPanel **v5; // edi@5
  signed int v6; // ebx@5

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeMPSetupScreen::`vftable';
  v2 = this->scenarioInfo;
  if ( v2 )
  {
    ((void (__stdcall *)(signed int))v2->vfptr->~RGE_Scenario)(1);
    v1->scenarioInfo = 0;
  }
  TPanelSystem::destroyPanel(&panel_system, aGameSettingsSc);
  TPanelSystem::destroyPanel(&panel_system, aSelectTribeScr);
  TPanelSystem::destroyPanel(&panel_system, aKickDialog);
  TPanelSystem::destroyPanel(&panel_system, aOkdialog);
  TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
  TPanel::delete_panel((TPanel **)&v1->title);
  TPanel::delete_panel((TPanel **)&v1->playerTitle);
  TPanel::delete_panel((TPanel **)&v1->civTitle);
  TPanel::delete_panel((TPanel **)&v1->settingsTitle);
  TPanel::delete_panel((TPanel **)&v1->colorTitle);
  TPanel::delete_panel((TPanel **)&v1->teamTitle);
  v3 = (int)v1->playerCivDrop;
  v4 = 8;
  do
  {
    TPanel::delete_panel((TPanel **)(v3 - 32));
    TPanel::delete_panel((TPanel **)v3);
    TPanel::delete_panel((TPanel **)(v3 + 32));
    TPanel::delete_panel((TPanel **)(v3 - 96));
    TPanel::delete_panel((TPanel **)(v3 - 64));
    TPanel::delete_panel((TPanel **)(v3 - 320));
    TPanel::delete_panel((TPanel **)(v3 - 288));
    TPanel::delete_panel((TPanel **)(v3 - 256));
    TPanel::delete_panel((TPanel **)(v3 - 224));
    TPanel::delete_panel((TPanel **)(v3 - 192));
    TPanel::delete_panel((TPanel **)(v3 - 160));
    TPanel::delete_panel((TPanel **)(v3 - 128));
    v3 += 4;
    --v4;
  }
  while ( v4 );
  TPanel::delete_panel((TPanel **)&v1->chatInput);
  TPanel::delete_panel((TPanel **)&v1->chatTitle);
  TPanel::delete_panel((TPanel **)&v1->chatBox);
  TPanel::delete_panel((TPanel **)&v1->gameSettingsButton);
  TPanel::delete_panel((TPanel **)&v1->scenarioName);
  TPanel::delete_panel((TPanel **)&v1->victoryFixedText);
  v5 = (TPanel **)v1->settingValue;
  v6 = 20;
  do
  {
    TPanel::delete_panel(v5 - 20);
    TPanel::delete_panel(v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  TPanel::delete_panel((TPanel **)&v1->mapSizeLabel);
  TPanel::delete_panel((TPanel **)&v1->mapSizeDrop);
  TPanel::delete_panel((TPanel **)&v1->mapTypeLabel);
  TPanel::delete_panel((TPanel **)&v1->mapTypeDrop);
  TPanel::delete_panel((TPanel **)&v1->numberPlayersTitle);
  TPanel::delete_panel((TPanel **)&v1->numberPlayersDrop);
  TPanel::delete_panel((TPanel **)&v1->numberPlayersText);
  TPanel::delete_panel((TPanel **)&v1->hiddenMapButton);
  TPanel::delete_panel((TPanel **)&v1->hiddenMapText);
  TPanel::delete_panel((TPanel **)&v1->victoryTypeLabel);
  TPanel::delete_panel((TPanel **)&v1->victoryTypeDrop);
  TPanel::delete_panel((TPanel **)&v1->victoryAmountLabel);
  TPanel::delete_panel((TPanel **)&v1->victoryAmountInput);
  TPanel::delete_panel((TPanel **)&v1->startButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TPanel::delete_panel((TPanel **)&v1->ready_button);
  TPanel::delete_panel((TPanel **)&v1->ready_button_label);
  TPanel::delete_panel((TPanel **)&v1->netInfoButton);
  TPanel::delete_panel((TPanel **)&v1->help_button);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5732C8: using guessed type int (__thiscall *TribeMPSetupScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004A1640) --------------------------------------------------------
int __thiscall TribeMPSetupScreen::handle_idle(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // esi@1
  RGE_Base_Game *v2; // ecx@1

  v1 = this;
  v2 = rge_base_game;
  if ( !rge_base_game->input_enabled )
  {
    RGE_Base_Game::enable_input(rge_base_game);
    v2 = rge_base_game;
  }
  if ( RGE_Base_Game::multiplayerGame(v2) )
  {
    if ( !v1->last_send_shared )
    {
LABEL_7:
      v1->last_send_shared = debug_timeGetTime();
      return TPanel::handle_idle((TPanel *)&v1->vfptr);
    }
    if ( debug_timeGetTime() != v1->last_send_shared )
    {
      TCommunications_Handler::SendSharedData(comm, 0);
      goto LABEL_7;
    }
  }
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004A16D0) --------------------------------------------------------
int __stdcall TribeMPSetupScreen::key_down_action(int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004A16E0) --------------------------------------------------------
int __thiscall TribeMPSetupScreen::action(TribeMPSetupScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeMPSetupScreen *v5; // esi@1
  int v6; // ebp@2
  TEditPanel *v7; // eax@4
  int result; // eax@7
  TButtonPanel *v9; // ecx@8
  unsigned int v10; // edi@15
  char *v11; // edi@16
  char *v12; // eax@16
  char *v13; // ST1C_4@17
  char *v14; // ST1C_4@18
  unsigned int v15; // ST18_4@21
  unsigned int v16; // ST14_4@21
  unsigned int v17; // ST10_4@21
  int v18; // eax@21
  TEditPanel *v19; // eax@22
  unsigned int v20; // eax@27
  int v21; // eax@28
  TEditPanel *v22; // eax@29
  TEditPanel *v23; // eax@37
  TribeGameSettingsScreen *v24; // eax@41
  TEditPanel *v25; // eax@53
  int v26; // edi@61
  TPanel **v27; // eax@61
  TPanel *v28; // ecx@65
  char *v29; // eax@69
  TDropDownPanel *v30; // ecx@70
  int v31; // eax@72
  int v32; // edi@83
  int v33; // ST1C_4@83
  int v34; // edi@89
  PLAYERHUMANITY v35; // eax@99
  int v36; // eax@100
  int v37; // eax@104
  int v38; // eax@106
  int v39; // ebp@106
  int v40; // edi@106
  int v41; // eax@115
  int v42; // eax@118
  char file_name[260]; // [sp+14h] [bp-228h]@16
  _finddata_t file_info; // [sp+118h] [bp-124h]@16
  int v45; // [sp+238h] [bp-4h]@41

  v5 = this;
  if ( !fromPanel )
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  v6 = actionIn;
  if ( fromPanel == (TPanel *)this->startButton && actionIn == 1 )
  {
    v7 = this->chatInput;
    if ( v7 )
    {
      if ( v7->active )
        TPanel::set_curr_child((TPanel *)&this->vfptr, (TPanel *)&this->chatInput->vfptr);
    }
    TribeMPSetupScreen::startGame(v5);
    return 1;
  }
  v9 = this->ready_button;
  if ( (TButtonPanel *)fromPanel == v9 && actionIn == 1 )
  {
    if ( TButtonPanel::get_state(v9) )
    {
      TDebuggingLog::Log(L, aSelectedIMRead);
      if ( TCommunications_Handler::IsHost(comm) )
      {
        TCommunications_Handler::SetMyReadiness(comm, 1, 0, 0, 0, 0, 0, 0, 0);
      }
      else
      {
        if ( (unsigned __int8)RGE_Base_Game::playerVersion(rge_base_game, 0) != 1 )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5->ready_button + 224))(0);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 9699, 0, 450, 100);
          return 1;
        }
        v10 = TCommunications_Handler::WhoAmI(comm) - 1;
        TDebuggingLog::Log(L, aSavingMycivMyt);
        v5->myCivilization = TDropDownPanel::get_id(v5->playerCivDrop[v10]);
        v5->myScenarioPlayer = TDropDownPanel::get_id(v5->scenarioPlayerDrop[v10]);
        v5->myPlayerColor = TButtonPanel::get_id(v5->playerColor[v10]);
        v5->myPlayerTeam = TButtonPanel::get_state(v5->playerTeam[v10]) + 1;
        if ( RGE_Base_Game::scenarioGame(rge_base_game) )
        {
          v11 = rge_base_game->prog_info->scenario_dir;
          v12 = RGE_Base_Game::scenarioName(rge_base_game);
          sprintf(file_name, aSS_scn, v11, v12);
          if ( _findfirst(file_name, &file_info) == -1 )
          {
            v13 = RGE_Base_Game::scenarioName(rge_base_game);
            sprintf(file_name, aS_scx, v13);
          }
          else
          {
            v14 = RGE_Base_Game::scenarioName(rge_base_game);
            sprintf(file_name, aS_scn, v14);
          }
          v5->myScenarioChecksum = (int)RGE_Base_Game::get_scenario_checksum(rge_base_game, file_name);
        }
        else
        {
          v5->myScenarioChecksum = 0;
        }
        v15 = v5->myScenarioChecksum;
        v16 = v5->myPlayerTeam;
        v17 = v5->myPlayerColor;
        LOBYTE(v18) = RGE_Base_Game::check_for_cd(rge_base_game, 0);
        TCommunications_Handler::SetMyReadiness(
          comm,
          1,
          v5->myCivilization,
          v5->myScenarioPlayer + 1,
          v18 + 1,
          v17,
          v16,
          v15,
          1u);
      }
      v19 = v5->chatInput;
      if ( v19 && v19->active )
        TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->chatInput->vfptr);
      v5->i_am_ready = 1;
    }
    else
    {
      TDebuggingLog::Log(L, aSelectedNotRea);
      if ( TCommunications_Handler::IsHost(comm) )
      {
        v20 = 0;
      }
      else
      {
        LOBYTE(v21) = RGE_Base_Game::check_for_cd(rge_base_game, 0);
        v20 = v21 + 1;
      }
      TCommunications_Handler::SetMyReadiness(comm, 0, 0, 0, v20, 0, 0, 0, 0);
      v22 = v5->chatInput;
      if ( v22 && v22->active )
        TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->chatInput->vfptr);
      v5->i_am_ready = 0;
    }
    TribeMPSetupScreen::fillPlayers(v5);
    if ( TCommunications_Handler::IsHost(comm) )
    {
      TButtonPanel::set_disabled(v5->gameSettingsButton, v5->i_am_ready);
      TButtonPanel::set_disabled(v5->startButton, v5->i_am_ready == 0);
      ((void (*)(void))rge_base_game->vfptr->send_game_options)();
      v5->resend_game_options = 0;
      TCommunications_Handler::SendSharedData(comm, 1);
      return 1;
    }
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->gameSettingsButton && actionIn == 1 )
  {
    v23 = v5->chatInput;
    if ( v23 && v23->active )
      TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->chatInput->vfptr);
    if ( !TPanelSystem::panel(&panel_system, aGameSettingsSc) )
    {
      RGE_Base_Game::disable_input(rge_base_game);
      v24 = (TribeGameSettingsScreen *)operator new(0x560u);
      v45 = 0;
      if ( v24 )
        TribeGameSettingsScreen::TribeGameSettingsScreen(v24);
      v45 = -1;
    }
    TPanelSystem::setCurrentPanel(&panel_system, aGameSettingsSc, 0);
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->help_button && actionIn == 1 )
  {
    TEasy_Panel::setup_popup_help((TEasy_Panel *)&v5->vfptr);
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->close_button && actionIn == 1 )
  {
    RGE_Base_Game::close(rge_base_game);
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->cancelButton && actionIn == 1 )
  {
    v25 = v5->chatInput;
    if ( v25 && v25->active )
      TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->chatInput->vfptr);
    TribeMPSetupScreen::cancelScreen(0);
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->netInfoButton )
  {
    if ( actionIn == 1 )
    {
      TribeMPSetupScreen::showNetInfo(v5);
      return 1;
    }
  }
  else if ( actionIn == 1 )
  {
    v26 = 0;
    v27 = (TPanel **)v5->playerTeam;
    while ( 1 )
    {
      if ( fromPanel == *(v27 - 8) )
      {
        v41 = TButtonPanel::get_id(v5->playerColor[v26]);
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v26, v41);
        if ( RGE_Base_Game::multiplayerGame(rge_base_game) && !TCommunications_Handler::IsHost(comm) )
        {
          v5->myPlayerColor = TButtonPanel::get_id(v5->playerColor[v26]);
          return 1;
        }
        return 1;
      }
      if ( fromPanel == *v27 )
        break;
      ++v26;
      ++v27;
      if ( v26 >= 8 )
        goto LABEL_65;
    }
    v42 = TButtonPanel::get_state(v5->playerTeam[v26]);
    RGE_Base_Game::setPlayerTeam(rge_base_game, v26, v42 + 1);
    if ( RGE_Base_Game::multiplayerGame(rge_base_game) && !TCommunications_Handler::IsHost(comm) )
    {
      v5->myPlayerTeam = TButtonPanel::get_state(v5->playerTeam[v26]) + 1;
      return 1;
    }
    return 1;
  }
LABEL_65:
  v28 = (TPanel *)&v5->chatInput->vfptr;
  if ( fromPanel == v28
    && !actionIn
    && TEditPanel::currentLine((TEditPanel *)v28)
    && *TEditPanel::currentLine(v5->chatInput) )
  {
    v29 = TEditPanel::currentLine(v5->chatInput);
    TCommunications_Handler::SendChatMsgAll(comm, v29);
    TEditPanel::set_text(v5->chatInput, message_in);
    return 1;
  }
  v30 = v5->numberPlayersDrop;
  if ( (TDropDownPanel *)fromPanel == v30 && !actionIn )
  {
    v31 = TDropDownPanel::get_id(v30);
    RGE_Base_Game::setNumberPlayers(rge_base_game, v31);
    TribeMPSetupScreen::updateSummary(v5);
    return 1;
  }
  if ( TPanel::panelName(fromPanel) )
  {
    if ( !strcmp(TPanel::panelName(fromPanel), aGameSettingsSc) )
    {
      if ( actionIn )
      {
        TribeMPSetupScreen::updateSummary(v5);
        if ( !RGE_Base_Game::singlePlayerGame(rge_base_game) )
        {
          ((void (*)(void))rge_base_game->vfptr->send_game_options)();
          v5->resend_game_options = 0;
        }
      }
      TPanelSystem::setCurrentPanel(&panel_system, aMpSetupScreen, 0);
      return 1;
    }
    v6 = actionIn;
  }
  if ( TPanel::panelName(fromPanel) )
  {
    if ( !strcmp(TPanel::panelName(fromPanel), aKickDialog) )
    {
      if ( actionIn )
      {
        TDropDownPanel::set_line((TDropDownPanel *)v5->playerTeam[v5->playerToKick + 7], 0);
      }
      else
      {
        v32 = TDropDownPanel::get_id((TDropDownPanel *)v5->playerTeam[v5->playerToKick + 7]);
        TCommunications_Handler::Kick(comm, v5->playerToKick);
        TCommunications_Handler::SetPlayerHumanity(comm, v5->playerToKick, (PLAYERHUMANITY)v32);
        v33 = TDropDownPanel::get_line((TDropDownPanel *)v5->playerTeam[v5->playerToKick + 7], v32);
        TDropDownPanel::set_line((TDropDownPanel *)v5->playerTeam[v5->playerToKick + 7], v33);
      }
      fromPanel->vfptr->__vecDelDtor(fromPanel, 1u);
      return 1;
    }
    v6 = actionIn;
  }
  if ( v6 || RGE_Base_Game::numberPlayers(rge_base_game) <= 0 )
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  v34 = (int)v5->playerCivDrop;
  while ( 1 )
  {
    if ( fromPanel == *(TPanel **)(v34 - 32) )
    {
      if ( RGE_Base_Game::multiplayerGame(rge_base_game)
        && TDropDownPanel::get_line(v5->playerNameDrop[v6]) > 0
        && TCommunications_Handler::IsPlayerHuman(comm, v6 + 1) )
      {
        TribeMPSetupScreen::kickPlayer(v5, v6 + 1);
        result = 1;
      }
      else
      {
        v35 = TDropDownPanel::get_id(v5->playerNameDrop[v6]);
        TCommunications_Handler::SetPlayerHumanity(comm, v6 + 1, v35);
        result = 1;
      }
      return result;
    }
    if ( fromPanel == *(TPanel **)v34 )
    {
      v36 = TDropDownPanel::get_id(v5->playerCivDrop[v6]);
      TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v6, v36);
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) && !TCommunications_Handler::IsHost(comm) )
      {
        v5->myCivilization = TDropDownPanel::get_id(v5->playerCivDrop[v6]);
        return 1;
      }
      return 1;
    }
    if ( fromPanel == *(TPanel **)(v34 + 32) )
      break;
    ++v6;
    v34 += 4;
    if ( v6 >= RGE_Base_Game::numberPlayers(rge_base_game) )
      return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  }
  if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    v38 = TDropDownPanel::get_id(v5->scenarioPlayerDrop[0]);
    TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, 0, v38);
    v39 = 1;
    v40 = 0;
    do
    {
      if ( v40 != TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, 0) )
      {
        if ( RGE_Scenario::Get_player_Active((RGE_Scenario *)&v5->scenarioInfo->vfptr, v40) )
        {
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v39++, v40);
          if ( v39 >= RGE_Base_Game::numberPlayers(rge_base_game) )
            break;
        }
      }
      ++v40;
    }
    while ( v40 < 8 );
    TribeMPSetupScreen::fillPlayers(v5);
    return 1;
  }
  v37 = TDropDownPanel::get_id(v5->scenarioPlayerDrop[v6]);
  TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v6, v37);
  if ( TCommunications_Handler::IsHost(comm) )
    return 1;
  v5->myScenarioPlayer = TDropDownPanel::get_id(v5->scenarioPlayerDrop[v6]);
  return 1;
}

//----- (004A2060) --------------------------------------------------------
int __thiscall TribeMPSetupScreen::startGame(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // ebp@1
  int result; // eax@2
  int v3; // ebx@6
  unsigned int v4; // esi@6
  int *v5; // edi@6
  int v6; // esi@11
  int v7; // edi@12
  char *v8; // ST0C_4@17
  char *v9; // eax@17
  int v10; // ebx@23
  int v11; // esi@23
  int v12; // edi@24
  PLAYERHUMANITY v13; // eax@24
  int v14; // eax@26
  signed int v15; // ebx@30
  int v16; // esi@30
  int v17; // edi@31
  PLAYERHUMANITY v18; // eax@31
  int v19; // ST0C_4@41
  char *v20; // eax@41
  int v21; // ST0C_4@45
  char *v22; // eax@45
  int v23; // edi@46
  int v24; // esi@46
  int v25; // eax@50
  int v26; // ST0C_4@50
  unsigned int v27; // eax@50
  int v28; // eax@50
  int v29; // eax@57
  signed int v30; // esi@58
  int i; // esi@61
  int v32; // eax@63
  int v33; // eax@65
  signed int v34; // edx@68
  int v35; // ebp@70
  signed int v36; // edi@70
  int *v37; // ebx@70
  PLAYERHUMANITY v38; // eax@71
  int v39; // eax@73
  TRIBE_Game *v40; // ecx@73
  int v41; // eax@73
  RGE_Base_Game *v42; // ecx@73
  signed int v43; // esi@76
  int *v44; // edi@76
  char *v45; // ST0C_4@87
  char *v46; // eax@87
  int send_options; // [sp+10h] [bp-568h]@1
  TEasy_Panel *v48; // [sp+14h] [bp-564h]@1
  int temp_team[8]; // [sp+18h] [bp-560h]@30
  int temp_color[8]; // [sp+38h] [bp-540h]@69
  int temp_civ[8]; // [sp+58h] [bp-520h]@68
  char Dest; // [sp+78h] [bp-500h]@41
  char msg[1024]; // [sp+178h] [bp-400h]@17

  v1 = this;
  v48 = (TEasy_Panel *)this;
  send_options = 0;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    result = TCommunications_Handler::IsHost(comm);
    if ( result )
    {
      if ( TCommunications_Handler::AllPlayersReady(comm) )
      {
        if ( RGE_Base_Game::scenarioGame(rge_base_game) )
        {
          v3 = 0;
          v4 = 1;
          v5 = v1->scenarioCheckSum;
          while ( v4 == TCommunications_Handler::WhoAmI(comm)
               || TCommunications_Handler::GetPlayerHumanity(comm, v4) != 2
               || *v5 == v1->myScenarioChecksum )
          {
            ++v3;
            ++v5;
            if ( (signed int)++v4 >= 9 )
              goto LABEL_11;
          }
          v45 = TCommunications_Handler::GetPlayerName(comm, v3 + 1);
          v46 = TPanel::get_string(9697);
          sprintf(msg, v46, v45);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, msg, 0, 450, 100);
          result = 0;
        }
        else
        {
LABEL_11:
          v6 = 0;
          while ( 1 )
          {
            v7 = v6 + 1;
            if ( v6 + 1 != TCommunications_Handler::WhoAmI(comm)
              && TCommunications_Handler::GetPlayerHumanity(comm, v6 + 1) == 2
              && (unsigned __int8)RGE_Base_Game::playerVersion(rge_base_game, v6) != 1 )
            {
              break;
            }
            ++v6;
            if ( v7 >= 8 )
              goto LABEL_18;
          }
          v8 = TCommunications_Handler::GetPlayerName(comm, v6 + 1);
          v9 = TPanel::get_string(9698);
          sprintf(msg, v9, v8);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, msg, 0, 450, 100);
          result = 0;
        }
      }
      else
      {
        TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 9665, 0, 450, 100);
        result = 0;
      }
    }
  }
  else
  {
LABEL_18:
    if ( RGE_Base_Game::scenarioGame(rge_base_game) && !v1->scenarioInfo )
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 9666, 0, 450, 100);
      return 0;
    }
    if ( RGE_Base_Game::multiplayerGame(rge_base_game) && RGE_Base_Game::scenarioGame(rge_base_game) )
    {
      v10 = 0;
      v11 = 0;
      do
      {
        v12 = v11 + 1;
        v13 = TCommunications_Handler::GetPlayerHumanity(comm, v11 + 1);
        if ( v13 == 2 || v13 == 4 )
        {
          v14 = TDropDownPanel::get_id(v1->scenarioPlayerDrop[0], v10);
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v11, v14);
          if ( ++v10 >= TTextPanel::numberLines((TTextPanel *)&v1->scenarioPlayerDrop[0]->list_panel->vfptr) )
            v10 = 0;
        }
        ++v11;
      }
      while ( v12 < 8 );
    }
    if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
      goto LABEL_90;
    v15 = 0;
    memset(temp_team, 0, sizeof(temp_team));
    v16 = 0;
    if ( RGE_Base_Game::numberPlayers(rge_base_game) > 0 )
    {
      do
      {
        v17 = v16 + 1;
        v18 = TCommunications_Handler::GetPlayerHumanity(comm, v16 + 1);
        if ( v18 == 2 )
        {
          if ( !*(&v48 + TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v16)) )
          {
            ++v15;
            *(&v48 + TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v16)) = (TEasy_Panel *)1;
          }
        }
        else if ( v18 == 4 )
        {
          ++v15;
        }
        ++v16;
      }
      while ( v17 < RGE_Base_Game::numberPlayers(rge_base_game) );
    }
    if ( v15 < 2 )
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 9670, 0, 450, 100);
      return 0;
    }
    if ( RGE_Base_Game::scenarioGame(rge_base_game) && v15 > v1->scenarioPlayerCount )
    {
      v19 = v1->scenarioPlayerCount;
      v20 = TPanel::get_string(9667);
      sprintf(&Dest, v20, v19);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, &Dest, 0, 450, 100);
      return 0;
    }
    if ( RGE_Base_Game::scenarioGame(rge_base_game) && v1->settingsFixed && v15 != v1->scenarioPlayerCount )
    {
      v21 = v1->scenarioPlayerCount;
      v22 = TPanel::get_string(9669);
      sprintf(&Dest, v22, v21);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, &Dest, 0, 450, 100);
      return 0;
    }
    v23 = 0;
    v24 = 0;
    while ( v24 < RGE_Base_Game::numberPlayers(rge_base_game) )
    {
      if ( TCommunications_Handler::GetPlayerHumanity(comm, ++v24) == 2 )
        ++v23;
    }
    LOBYTE(v25) = RGE_Base_Game::check_for_cd(rge_base_game, 0);
    v26 = v25;
    v27 = TCommunications_Handler::WhoAmI(comm);
    RGE_Base_Game::setPlayerHasCD(rge_base_game, v27 - 1, v26);
    LOBYTE(v28) = RGE_Base_Game::check_for_cd(rge_base_game, v23);
    if ( v28 )
    {
LABEL_90:
      if ( RGE_Base_Game::scenarioGame(rge_base_game) )
      {
        if ( TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game) )
        {
          TribeMPSetupScreen::calcRandomPositions(v1);
          if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
            send_options = 1;
        }
      }
      if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
      {
        v29 = RGE_Base_Game::numberPlayers(rge_base_game);
        if ( v29 < 8 )
        {
          v30 = v29 + 1;
          do
            TCommunications_Handler::SetPlayerHumanity(comm, v30++, 0);
          while ( v30 < 9 );
        }
      }
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
      {
        for ( i = 0; i < RGE_Base_Game::numberPlayers(rge_base_game); ++i )
        {
          if ( TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, i) >= 50 )
          {
            TDebuggingLog::Log(L, aHostReset2Civ5);
            v32 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, i);
            TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, i, v32 - 50);
            send_options = 1;
          }
          if ( RGE_Base_Game::playerTeam(rge_base_game, i) >= 50 )
          {
            TDebuggingLog::Log(L, aHostReset2Team);
            v33 = RGE_Base_Game::playerTeam(rge_base_game, i);
            RGE_Base_Game::setPlayerTeam(rge_base_game, i, v33 - 50);
            send_options = 1;
          }
        }
      }
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
      {
        v34 = 0;
        memset32(temp_team, 1, 8u);
        memset32(temp_civ, 1, 8u);
        do
        {
          temp_color[v34] = v34 + 1;
          ++v34;
        }
        while ( v34 < 8 );
        v35 = 0;
        v36 = 1;
        v37 = temp_team;
        do
        {
          v38 = TCommunications_Handler::GetPlayerHumanity(comm, v36);
          if ( v38 == 2 || v38 == 4 )
          {
            v39 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v36 - 1);
            v40 = (TRIBE_Game *)rge_base_game;
            temp_color[v35] = v39;
            v41 = TRIBE_Game::civilization(v40, v36 - 1);
            v42 = rge_base_game;
            temp_civ[v35] = v41;
            *v37 = RGE_Base_Game::playerTeam(v42, v36 - 1);
            ++v35;
            ++v37;
          }
          ++v36;
        }
        while ( v36 < 9 );
        if ( v35 > 0 )
        {
          v43 = 0;
          v44 = temp_team;
          do
          {
            TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v43, temp_color[v43]);
            TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v43, temp_civ[v43]);
            RGE_Base_Game::setPlayerTeam(rge_base_game, v43++, *v44);
            ++v44;
          }
          while ( v43 < 8 );
          send_options = 1;
        }
      }
      TPanelSystem::destroyPanel(&panel_system, aStatusScreen);
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
      {
        if ( send_options || *(_DWORD *)&v48[1].popup_info_file_name[212] )
        {
          ((void (*)(void))rge_base_game->vfptr->send_game_options)();
          *(_DWORD *)&v48[1].popup_info_file_name[212] = 0;
        }
        TCommunications_Handler::LaunchMultiplayerGame(comm);
        TChat::setWindowHandle(chat, AppWnd);
        TCommunications_Handler::SetWindowHandle(comm, AppWnd);
      }
      if ( TRIBE_Game::start_game((TRIBE_Game *)rge_base_game, 0) )
      {
        result = 1;
      }
      else
      {
        TEasy_Panel::popupOKDialog(v48, 2401, 0, 450, 100);
        result = 0;
      }
    }
    else
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 2009, 0, 450, 100);
      result = 0;
    }
  }
  return result;
}

//----- (004A27A0) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::calcRandomPositions(TribeMPSetupScreen *this)
{
  int v1; // ebp@1
  int v2; // esi@1
  PLAYERHUMANITY v3; // eax@2
  int v4; // ebx@6
  int v5; // esi@6
  int *v6; // edi@6
  int v7; // ebp@12
  int v8; // esi@13
  PLAYERHUMANITY v9; // eax@13
  int v10; // eax@15
  int v11; // ecx@15
  int *v12; // edx@16
  int v13; // edi@21
  int v14; // esi@22
  int v15; // eax@22
  unsigned int v16; // edx@22
  int v17; // edx@22
  int v18; // esi@28
  TribeMPSetupScreen *v19; // [sp+10h] [bp-2Ch]@1
  int pos; // [sp+14h] [bp-28h]@0
  int position_used[8]; // [sp+1Ch] [bp-20h]@6

  v19 = this;
  v1 = 0;
  v2 = 0;
  while ( v2 < RGE_Base_Game::numberPlayers(rge_base_game) )
  {
    v3 = TCommunications_Handler::GetPlayerHumanity(comm, ++v2);
    if ( v3 == 2 || v3 == 4 )
      ++v1;
  }
  v4 = 0;
  v5 = 0;
  v6 = position_used;
  do
  {
    if ( TDropDownPanel::get_line(v19->scenarioPlayerDrop[0], v5) == -1 )
    {
      *v6 = -2;
    }
    else
    {
      *v6 = -1;
      ++v4;
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 8 );
  if ( v1 <= v4 )
  {
    v7 = 0;
    if ( RGE_Base_Game::numberPlayers(rge_base_game) > 0 )
    {
      do
      {
        v8 = v7 + 1;
        v9 = TCommunications_Handler::GetPlayerHumanity(comm, v7 + 1);
        if ( v9 == 2 || v9 == 4 )
        {
          v10 = 0;
          v11 = v19->scenarioPlayerCount;
          if ( v11 > 0 )
          {
            v12 = position_used;
            while ( *v12 != -1 )
            {
              ++v10;
              ++v12;
              if ( v10 >= v11 )
                goto LABEL_21;
            }
            pos = v10;
          }
LABEL_21:
          v13 = 0;
          while ( 1 )
          {
            v14 = v19->scenarioPlayerCount;
            v15 = debug_rand(aCMsdevWorkA_42, 1508);
            v16 = (signed int)(v14 * v15 + ((unsigned __int64)(-2147418109i64 * v14 * v15) >> 32)) >> 14;
            v17 = (v16 >> 31) + v16;
            if ( v17 < v14 )
            {
              if ( v17 < 0 )
                v17 = 0;
            }
            else
            {
              v17 = v14 - 1;
            }
            if ( position_used[v17] == -1 )
              break;
            if ( ++v13 >= 1000 )
            {
              v18 = pos;
              goto LABEL_30;
            }
          }
          v18 = v17;
          pos = v17;
LABEL_30:
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v7, v18);
          position_used[v18] = v7;
          v8 = v7 + 1;
        }
        v7 = v8;
      }
      while ( v8 < RGE_Base_Game::numberPlayers(rge_base_game) );
    }
  }
}

//----- (004A2910) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::showNetInfo(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // ebx@1
  RGE_Communications_Addresses *v2; // eax@1
  RGE_Communications_Addresses *v3; // eax@2
  RGE_Communications_Addresses *v4; // ebp@2
  unsigned int v5; // eax@5
  char *v6; // ST0C_4@6
  char *v7; // eax@6
  unsigned int v8; // ebx@6
  char *v9; // edi@6
  char *v10; // edi@6
  char *v11; // esi@6
  unsigned int v12; // eax@6
  int v13; // ecx@6
  unsigned int v14; // ebx@6
  unsigned int num_addr; // [sp+10h] [bp-514h]@5
  TribeMPSetupScreen *v16; // [sp+14h] [bp-510h]@1
  char message[1024]; // [sp+18h] [bp-50Ch]@5
  char temp_str[256]; // [sp+418h] [bp-10Ch]@6
  int v19; // [sp+520h] [bp-4h]@1

  v1 = this;
  v16 = this;
  v2 = (RGE_Communications_Addresses *)operator new(0x224u);
  v19 = 0;
  if ( v2 )
  {
    RGE_Communications_Addresses::RGE_Communications_Addresses(v2, comm);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v19 = -1;
  if ( v4 )
  {
    v5 = v4->AddressesAvailable;
    message[0] = 0;
    num_addr = v5;
    if ( v5 )
    {
      strcat(message, asc_5868AC);
      v6 = RGE_Communications_Addresses::GetHostName(v4);
      v7 = TPanel::get_string(9100);
      sprintf(temp_str, v7, v6);
      strcat(message, temp_str);
      v8 = strlen(Str) + 1;
      v9 = &message[strlen(message)];
      qmemcpy(v9, Str, 4 * (v8 >> 2));
      v11 = &Str[4 * (v8 >> 2)];
      v10 = &v9[4 * (v8 >> 2)];
      v12 = num_addr;
      v13 = v8 & 3;
      v14 = 0;
      qmemcpy(v10, v11, v13);
      if ( num_addr )
      {
        do
        {
          if ( RGE_Communications_Addresses::GetAddress(v4, v14) )
          {
            strcat(message, RGE_Communications_Addresses::GetAddress(v4, v14));
            strcat(message, text_in);
          }
          if ( RGE_Communications_Addresses::GetAlias(v4, v14) )
            strcat(message, RGE_Communications_Addresses::GetAlias(v4, v14));
          strcat(message, Str);
          v12 = num_addr;
          ++v14;
        }
        while ( v14 < num_addr );
      }
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v16->vfptr, message, aOkdialog, 450, 18 * v12 + 100);
    }
    else
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 9101, 0, 450, 100);
    }
    RGE_Communications_Addresses::~RGE_Communications_Addresses(v4);
    operator delete(v4);
  }
}

//----- (004A2BA0) --------------------------------------------------------
void __stdcall TribeMPSetupScreen::cancelScreen(int lobbyTimeout)
{
  TribeSelectScenarioScreen *v2; // eax@3
  TribeSPMenuScreen *v3; // eax@6
  TRIBE_Screen_Main_Error *v4; // eax@11
  TRIBE_Screen_Main_Error *v5; // eax@12
  TribeJoinScreen *v6; // eax@18
  char *v7; // [sp-8h] [bp-14h]@5

  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
  {
    RGE_Base_Game::disable_input(rge_base_game);
    if ( RGE_Base_Game::scenarioGame(rge_base_game) )
    {
      v2 = (TribeSelectScenarioScreen *)operator new(0x4D8u);
      if ( v2 )
        TribeSelectScenarioScreen::TribeSelectScenarioScreen(v2);
      v7 = aSelectScenario;
    }
    else
    {
      v3 = (TribeSPMenuScreen *)operator new(0x49Cu);
      if ( v3 )
        TribeSPMenuScreen::TribeSPMenuScreen(v3);
      v7 = aSinglePlayerMe;
    }
  }
  else if ( TCommunications_Handler::IsLobbyLaunched(comm) )
  {
    if ( !lobbyTimeout
      || ((v4 = (TRIBE_Screen_Main_Error *)operator new(0x484u)) == 0 ? (v5 = 0) : TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error(v4),
          !v5 || v5->error_code) )
    {
      RGE_Base_Game::close(rge_base_game);
      return;
    }
    TRIBE_Screen_Main_Error::set_text(v5, 2410);
    v7 = aMainErrorScree;
  }
  else
  {
    RGE_Base_Game::disable_input(rge_base_game);
    TCommunications_Handler::UnlinkToLevel(comm, SERVICE_AVAILABLE);
    v6 = (TribeJoinScreen *)operator new(0x4B0u);
    if ( v6 )
      TribeJoinScreen::TribeJoinScreen(v6);
    v7 = aJoinScreen;
  }
  TPanelSystem::setCurrentPanel(&panel_system, v7, 0);
  TPanelSystem::destroyPanel(&panel_system, aMpSetupScreen);
}

//----- (004A2D50) --------------------------------------------------------
int __thiscall TribeMPSetupScreen::handle_user_command(TribeMPSetupScreen *this, unsigned int wParam, int lParam)
{
  TribeMPSetupScreen *v3; // edi@1
  int v4; // esi@4
  int v5; // eax@6
  int v6; // eax@8
  int result; // eax@10
  signed int v8; // ebp@11
  int v9; // eax@13
  unsigned int v10; // eax@14
  int v11; // esi@16
  PLAYERHUMANITY v12; // edi@17
  int v13; // eax@20
  int v14; // edi@23
  int v15; // eax@34
  int v16; // eax@37
  int v17; // edi@45
  int v18; // edi@51
  int i; // esi@64
  int v20; // eax@66
  int v21; // eax@69
  unsigned int v22; // eax@78
  int v23; // eax@79
  unsigned int v24; // ST1C_4@79
  int v25; // eax@79
  char *v26; // ST20_4@87
  char *v27; // eax@87
  char *v28; // ST20_4@88
  char *v29; // eax@88
  TribeMPSetupScreen *v30; // [sp+10h] [bp-12Ch]@1
  _DWORD *v31; // [sp+14h] [bp-128h]@16
  int PlayerNo; // [sp+18h] [bp-124h]@17
  unsigned int user5; // [sp+1Ch] [bp-120h]@19
  unsigned int user4; // [sp+20h] [bp-11Ch]@19
  unsigned int user1; // [sp+24h] [bp-118h]@19
  unsigned int user3; // [sp+28h] [bp-114h]@19
  unsigned int user7; // [sp+2Ch] [bp-110h]@19
  unsigned int user2; // [sp+30h] [bp-10Ch]@19
  unsigned int user6; // [sp+34h] [bp-108h]@19
  int ready; // [sp+38h] [bp-104h]@19
  char message[256]; // [sp+3Ch] [bp-100h]@87

  v3 = this;
  v30 = this;
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
    return 1;
  switch ( wParam )
  {
    case 0x17BBu:
      TDebuggingLog::Log(L, aUser_commandCo, wParam, lParam);
      if ( !TCommunications_Handler::IsHost(comm) )
        goto LABEL_92;
      v4 = 0;
      if ( RGE_Base_Game::numberPlayers(rge_base_game) <= 0 )
        goto LABEL_92;
      do
      {
        if ( TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, v4) >= 50 )
        {
          TDebuggingLog::Log(L, aHostResetCiv50);
          v5 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, v4);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v4, v5 - 50);
          v3->resend_game_options = 1;
        }
        if ( RGE_Base_Game::playerTeam(rge_base_game, v4) >= 50 )
        {
          TDebuggingLog::Log(L, aHostResetTeam5);
          v6 = RGE_Base_Game::playerTeam(rge_base_game, v4);
          RGE_Base_Game::setPlayerTeam(rge_base_game, v4, v6 - 50);
          v3->resend_game_options = 1;
        }
        ++v4;
      }
      while ( v4 < RGE_Base_Game::numberPlayers(rge_base_game) );
      return 1;
    case 0x17A4u:
      TDebuggingLog::Log(L, aUser_command_2, wParam, lParam);
      v8 = 0;
      if ( TCommunications_Handler::IsHost(comm) )
      {
        if ( !v3->sent_cd_status )
        {
          v3->sent_cd_status = 1;
          LOBYTE(v9) = RGE_Base_Game::check_for_cd(rge_base_game, 0);
          if ( v9 )
          {
            v8 = 1;
            v10 = TCommunications_Handler::WhoAmI(comm);
            RGE_Base_Game::setPlayerHasCD(rge_base_game, v10 - 1, 1);
          }
        }
      }
      if ( !TCommunications_Handler::IsHost(comm) )
        goto LABEL_62;
      v11 = 0;
      v31 = v3->scenarioCheckSum;
      break;
    case 0x17D5u:
      TDebuggingLog::Log(L, aUser_commandCh, wParam, lParam);
      TribeMPSetupScreen::fillChat(v3, lParam);
      return 1;
    case 0x17A6u:
      TDebuggingLog::Log(L, aUser_command_4, wParam, lParam);
      ((void (*)(void))rge_base_game->vfptr->receive_game_options)();
      for ( i = 0; i < RGE_Base_Game::numberPlayers(rge_base_game); ++i )
      {
        if ( TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, i) >= 50 )
        {
          TDebuggingLog::Log(L, aCiv250);
          v20 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, i);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, i, v20 - 50);
          if ( i + 1 == TCommunications_Handler::WhoAmI(comm) )
          {
            v3->myCivilization = 0;
            TDebuggingLog::Log(L, aResettingMyciv);
          }
        }
        if ( RGE_Base_Game::playerTeam(rge_base_game, i) >= 50 )
        {
          TDebuggingLog::Log(L, aTeam250);
          v21 = RGE_Base_Game::playerTeam(rge_base_game, i);
          RGE_Base_Game::setPlayerTeam(rge_base_game, i, v21 - 50);
          if ( i + 1 == TCommunications_Handler::WhoAmI(comm) )
          {
            v3->myPlayerTeam = 0;
            TDebuggingLog::Log(L, aResettingMytea);
          }
        }
      }
      if ( v3->myScenarioPlayer && strcmp(v3->saveScenarioName, RGE_Base_Game::scenarioName(rge_base_game)) )
        v3->myScenarioPlayer = -1;
      TribeMPSetupScreen::updateSummary(v3);
      if ( TCommunications_Handler::IsHost(comm) )
        goto LABEL_92;
      if ( v3->sent_cd_status )
      {
        if ( v3->myScenarioChecksum == v3->saveScenarioChecksum )
        {
          v22 = TCommunications_Handler::WhoAmI(comm);
          if ( TCommunications_Handler::IsPlayerReady(comm, v22) == v3->i_am_ready )
            goto LABEL_92;
        }
      }
      v23 = v3->myScenarioChecksum;
      v24 = v23;
      v3->sent_cd_status = 1;
      v3->saveScenarioChecksum = v23;
      LOBYTE(v25) = RGE_Base_Game::check_for_cd(rge_base_game, 0);
      TCommunications_Handler::SetMyReadiness(comm, v3->i_am_ready, 0, 0, v25 + 1, 0, 0, v24, 1u);
      return 1;
    case 0x17A7u:
      TDebuggingLog::Log(L, aUser_command_7, wParam, lParam);
      TChat::setWindowHandle(chat, AppWnd);
      TCommunications_Handler::SetWindowHandle(comm, AppWnd);
      TRIBE_Game::start_game((TRIBE_Game *)rge_base_game, 0);
      return 1;
    case 0x17A8u:
      TDebuggingLog::Log(L, aUser_comman_12, wParam, lParam);
      goto LABEL_83;
    case 0x17A9u:
      TDebuggingLog::Log(L, aUser_command_3, wParam, lParam);
LABEL_83:
      TribeMPSetupScreen::handleKickedPlayer(0);
      return 1;
    case 0x17B2u:
      TDebuggingLog::Log(L, aUser_comman_11, wParam, lParam);
      TribeMPSetupScreen::handleKickedPlayer(1);
      return 1;
    case 0x17AAu:
      TDebuggingLog::Log(L, aUser_command_1, wParam, lParam);
      TribeMPSetupScreen::handleKickedPlayer(1);
      return 1;
    case 0x17B3u:
      TDebuggingLog::Log(L, aUser_command_5, wParam, lParam);
      TribeMPSetupScreen::fillPlayers(v3);
      return 1;
    case 0x17B7u:
      TDebuggingLog::Log(L, aUser_command_0, wParam, lParam);
      v26 = TCommunications_Handler::GetPlayerName(comm, lParam);
      v27 = TPanel::get_string(9694);
      sprintf(message, v27, v26);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v3->vfptr, message, 0, 450, 100);
      return 1;
    case 0x17B6u:
      TDebuggingLog::Log(L, aUser_comman_10, wParam, lParam);
      v28 = TCommunications_Handler::GetPlayerName(comm, lParam);
      v29 = TPanel::get_string(9693);
      sprintf(message, v29, v28);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v3->vfptr, message, 0, 450, 100);
      return 1;
    case 0x17B9u:
      TDebuggingLog::Log(L, aUser_command_8, wParam, lParam);
      if ( TCommunications_Handler::IsLobbyLaunched(comm) )
      {
        TribeMPSetupScreen::cancelScreen(1);
        result = 1;
      }
      else
      {
        TribeMPSetupScreen::handleKickedPlayer(0);
LABEL_92:
        result = 1;
      }
      return result;
    case 0x17AEu:
      TDebuggingLog::Log(L, aUser_command_6, wParam, lParam);
      TribeMPSetupScreen::cancelScreen(0);
      return 1;
    default:
      TDebuggingLog::Log(L, aUser_commandUn, wParam, lParam);
      return 1;
  }
  do
  {
    PlayerNo = v11 + 1;
    v12 = TCommunications_Handler::GetPlayerHumanity(comm, v11 + 1);
    if ( TCommunications_Handler::WhoAmI(comm) == v11 + 1 )
    {
      if ( v12 == 2 )
        goto LABEL_58;
    }
    else if ( v12 == 2 )
    {
      TCommunications_Handler::GetClientReadiness(
        comm,
        PlayerNo,
        &ready,
        &user1,
        &user2,
        &user3,
        &user4,
        &user5,
        &user6,
        &user7);
      if ( user1 )
      {
        v13 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, v11);
        if ( user1 != v13 )
        {
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v11, user1);
          v8 = 1;
        }
      }
      if ( user2 )
      {
        v14 = user2 - 1;
        if ( v14 != TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, v11) )
        {
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v11, v14);
          v8 = 1;
        }
      }
      if ( !user3 )
        goto LABEL_33;
      if ( user3 == 1 )
      {
        if ( RGE_Base_Game::playerHasCD(rge_base_game, v11) != 1 )
          goto LABEL_33;
        RGE_Base_Game::setPlayerHasCD(rge_base_game, v11, 0);
      }
      else
      {
        if ( user3 != 2 || RGE_Base_Game::playerHasCD(rge_base_game, v11) )
          goto LABEL_33;
        RGE_Base_Game::setPlayerHasCD(rge_base_game, v11, 1);
      }
      v8 = 1;
LABEL_33:
      if ( user4 )
      {
        v15 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v11);
        if ( user4 != v15 )
        {
          TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v11, user4);
          v8 = 1;
        }
      }
      if ( user5 )
      {
        v16 = RGE_Base_Game::playerTeam(rge_base_game, v11);
        if ( user5 != v16 )
        {
          RGE_Base_Game::setPlayerTeam(rge_base_game, v11, user5);
          v8 = 1;
        }
      }
      if ( user6 )
        *v31 = user6;
      if ( user7 )
      {
        RGE_Base_Game::setPlayerVersion(rge_base_game, v11, user7);
        v8 = 1;
      }
      goto LABEL_58;
    }
    if ( v12 != 4 )
    {
      v17 = (unsigned __int8)((char)debug_rand(aCMsdevWorkA_42, 1750) % -16) + 1;
      if ( TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, v11) != v17 )
      {
        TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v11, v17);
        v8 = 1;
      }
      if ( TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, v11) != v11 )
      {
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v11, v11);
        v8 = 1;
      }
      if ( RGE_Base_Game::playerHasCD(rge_base_game, v11) )
      {
        RGE_Base_Game::setPlayerHasCD(rge_base_game, v11, 0);
        v8 = 1;
      }
      v18 = v30->defaultColor[v11];
      if ( TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v11) != v18 )
      {
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v11, v18);
        v8 = 1;
      }
      if ( RGE_Base_Game::playerTeam(rge_base_game, v11) != 1 )
      {
        RGE_Base_Game::setPlayerTeam(rge_base_game, v11, 1);
        v8 = 1;
      }
      if ( (unsigned __int8)RGE_Base_Game::playerVersion(rge_base_game, v11) )
      {
        RGE_Base_Game::setPlayerVersion(rge_base_game, v11, 0);
        v8 = 1;
      }
      *v31 = 0;
    }
LABEL_58:
    ++v11;
    ++v31;
  }
  while ( PlayerNo < 8 );
  if ( v8 )
  {
    ((void (*)(void))rge_base_game->vfptr->send_game_options)();
    v30->resend_game_options = 0;
  }
  v3 = v30;
LABEL_62:
  TribeMPSetupScreen::fillPlayers(v3);
  v3->vfptr->set_redraw((TPanel *)v3, RedrawNormal);
  return 1;
}

//----- (004A37C0) --------------------------------------------------------
int __stdcall TribeMPSetupScreen::handle_timer_command(unsigned int wParam, int lParam)
{
  return 1;
}

//----- (004A37D0) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::fillPlayers(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // edi@1
  int v2; // ebx@3
  signed int v3; // ebp@5
  int v4; // esi@7
  int v5; // ebp@10
  int v6; // eax@11
  int v7; // eax@11
  int v8; // esi@17
  signed int v9; // ebp@19
  TPanelVtbl *v10; // ebx@25
  int v11; // eax@25
  TPanelVtbl *v12; // ebx@28
  char *v13; // eax@28
  TPanelVtbl *v14; // ebx@30
  char *v15; // eax@30
  TPanelVtbl *v16; // ebx@32
  char *v17; // eax@32
  int v18; // eax@35
  __int16 v19; // bx@37
  int v20; // edx@40
  int v21; // ebx@43
  int v22; // eax@49
  __int16 v23; // ax@52
  unsigned int v24; // ebx@67
  char *v25; // eax@74
  int v26; // eax@75
  TPanelVtbl *v27; // ebx@75
  TTextPanel *v28; // ecx@76
  char *v29; // eax@79
  TDropDownPanel *v30; // ecx@80
  int v31; // eax@84
  int v32; // eax@83
  TPanelVtbl *v33; // ebx@88
  char *v34; // eax@88
  TDropDownPanel *v35; // ecx@88
  int v36; // eax@92
  int v37; // eax@91
  TPanelVtbl *v38; // ebx@94
  char *v39; // eax@94
  TPanelVtbl *v40; // eax@97
  int v41; // ebx@103
  int v42; // ebx@116
  int v43; // ebp@116
  signed int v44; // [sp+38h] [bp-24h]@0
  int humanity; // [sp+48h] [bp-14h]@4
  int humanitya; // [sp+48h] [bp-14h]@19
  char *text1; // [sp+4Ch] [bp-10h]@3
  unsigned int color2; // [sp+50h] [bp-Ch]@5
  unsigned int color1; // [sp+54h] [bp-8h]@37
  char *text2; // [sp+58h] [bp-4h]@37

  v1 = this;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) && TCommunications_Handler::IsHost(comm) )
  {
    v2 = 0;
    text1 = 0;
    if ( RGE_Base_Game::numberPlayers(rge_base_game) > 0 )
    {
      humanity = (int)v1->playerNameText;
      do
      {
        v3 = v2 + 1;
        color2 = v2 + 1;
        if ( TCommunications_Handler::IsPlayerReady(comm, v2 + 1) )
        {
          if ( *(_DWORD *)(*(_DWORD *)humanity + 288) == 255 )
          {
            v4 = 0;
            if ( RGE_Base_Game::numberPlayers(rge_base_game) > 0 )
            {
              do
              {
                if ( v2 != v4 )
                {
                  if ( TCommunications_Handler::IsPlayerReady(comm, v4 + 1) )
                  {
                    v5 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v4);
                    if ( v5 == TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v2) )
                    {
                      TDebuggingLog::Log(L, aSettingCivTeam, v2, v4);
                      v6 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, v2);
                      TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v4, v6 + 50);
                      v7 = RGE_Base_Game::playerTeam(rge_base_game, v2);
                      RGE_Base_Game::setPlayerTeam(rge_base_game, v4, v7 + 50);
                      text1 = (char *)1;
                    }
                  }
                }
                ++v4;
              }
              while ( v4 < RGE_Base_Game::numberPlayers(rge_base_game) );
              v3 = color2;
            }
          }
        }
        v2 = v3;
        humanity += 4;
      }
      while ( v3 < RGE_Base_Game::numberPlayers(rge_base_game) );
    }
    if ( text1 )
      ((void (*)(void))rge_base_game->vfptr->send_game_options)();
  }
  v8 = 0;
  if ( RGE_Base_Game::numberPlayers(rge_base_game) > 0 )
  {
    while ( 1 )
    {
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
      {
        humanitya = TCommunications_Handler::GetPlayerHumanity(comm, v8 + 1);
        v9 = TCommunications_Handler::WhoAmI(comm) == v8 + 1;
      }
      else if ( v8 )
      {
        humanitya = TDropDownPanel::get_id(v1->playerNameDrop[v8]);
        v9 = 0;
      }
      else
      {
        humanitya = 2;
        v9 = 1;
      }
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) && humanitya == 2 )
      {
        v10 = v1->playerCDText[v8]->vfptr;
        v11 = RGE_Base_Game::playerHasCD(rge_base_game, v8);
        (*(void (__thiscall **)(TTextPanel *, int))&v10->gap10[4])(v1->playerCDText[v8], v11);
        if ( TCommunications_Handler::IsHost(comm) || (unsigned __int8)RGE_Base_Game::playerVersion(rge_base_game, 0) )
        {
          v16 = v1->playerVersionText[v8]->vfptr;
          v17 = RGE_Base_Game::playerVersionString(rge_base_game, v8);
          (*(void (__thiscall **)(TTextPanel *, char *, signed int))&v16[1].gap4[4])(
            v1->playerVersionText[v8],
            v17,
            v44);
          (*(void (__cdecl **)(signed int))&v1->playerVersionText[v8]->vfptr->gap10[4])(1);
        }
        else if ( v8 )
        {
          if ( v9 )
          {
            RGE_Base_Game::setPlayerVersion(rge_base_game, v8, 1);
            v14 = v1->playerVersionText[v8]->vfptr;
            v15 = RGE_Base_Game::playerVersionString(rge_base_game, v8);
            (*(void (__thiscall **)(TTextPanel *, char *, signed int))&v14[1].gap4[4])(
              v1->playerVersionText[v8],
              v15,
              v44);
            (*(void (__cdecl **)(signed int))&v1->playerVersionText[v8]->vfptr->gap10[4])(1);
          }
          else
          {
            (*(void (__stdcall **)(_DWORD))&v1->playerVersionText[v8]->vfptr->gap10[4])(0);
          }
        }
        else
        {
          v12 = v1->playerVersionText[0]->vfptr;
          v13 = RGE_Base_Game::playerVersionString(rge_base_game, 0);
          (*(void (__thiscall **)(TTextPanel *, char *, signed int))&v12[1].gap4[4])(v1->playerVersionText[0], v13, v44);
          (*(void (__cdecl **)(signed int))&v1->playerVersionText[0]->vfptr->gap10[4])(1);
        }
      }
      else
      {
        (*(void (__stdcall **)(_DWORD, signed int))&v1->playerCDText[v8]->vfptr->gap10[4])(0, v44);
        (*(void (__cdecl **)(signed int))&v1->playerVersionText[v8]->vfptr->gap10[4])(0);
      }
      if ( v9 != 1 || (v18 = v1->myPlayerColor) == 0 )
        v18 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, v8);
      if ( (TButtonPanel::set_state_by_id(v1->playerColor[v8], v18),
            v19 = TButtonPanel::get_state(v1->playerColor[v8]),
            TButtonPanel::get_text(v1->playerColor[v8], v19, &text1, &text2),
            TButtonPanel::get_text_color(v1->playerColor[v8], v19, &color1, &color2),
            (*(void (__stdcall **)(char *))&v1->playerColorText[v8]->vfptr[1].gap4[4])(text1),
            TTextPanel::set_text_color(v1->playerColorText[v8], color1, color2),
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v1->playerColor[v8] + 20))(0),
            (*(void (__stdcall **)(_DWORD))&v1->playerColorText[v8]->vfptr->gap10[4])(0),
            RGE_Base_Game::multiplayerGame(rge_base_game))
        && v9
        && !v1->i_am_ready
        || RGE_Base_Game::singlePlayerGame(rge_base_game) && v9 && v1->numberAnyPlayers > 1 )
      {
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v1->playerColor[v8] + 20))(1);
        TButtonPanel::set_disabled(v1->playerColor[v8], 0);
        v21 = humanitya;
      }
      else
      {
        v21 = humanitya;
        if ( humanitya == 2 )
          (*(void (__stdcall **)(signed int))&v1->playerColorText[v8]->vfptr->gap10[4])(1);
      }
      if ( v9 == 1 && v1->myPlayerTeam )
      {
        LOWORD(v20) = LOWORD(v1->myPlayerTeam) - 1;
        (*(void (__stdcall **)(int))(*(_DWORD *)v1->playerTeam[v8] + 224))(v20);
      }
      else
      {
        v22 = RGE_Base_Game::playerTeam(rge_base_game, v8);
        if ( v22 >= 50 )
          v22 -= 50;
        (*(void (__stdcall **)(int))(*(_DWORD *)v1->playerTeam[v8] + 224))(v22 - 1);
      }
      if ( (v23 = TButtonPanel::get_state(v1->playerTeam[v8]),
            TButtonPanel::get_text(v1->playerTeam[v8], v23, &text1, &text2),
            (*(void (__stdcall **)(char *))&v1->playerTeamText[v8]->vfptr[1].gap4[4])(text1),
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v1->playerTeam[v8] + 20))(0),
            (*(void (__stdcall **)(_DWORD))&v1->playerTeamText[v8]->vfptr->gap10[4])(0),
            RGE_Base_Game::multiplayerGame(rge_base_game))
        && (v9 && !v1->i_am_ready || TCommunications_Handler::IsHost(comm) && v21 == 4 && !v1->i_am_ready)
        || RGE_Base_Game::singlePlayerGame(rge_base_game) && (v9 || v21 == 4) )
      {
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v1->playerTeam[v8] + 20))(1);
        TButtonPanel::set_disabled(v1->playerTeam[v8], 0);
      }
      else if ( v21 == 2 || v21 == 4 )
      {
        (*(void (__stdcall **)(signed int))&v1->playerTeamText[v8]->vfptr->gap10[4])(1);
      }
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
      {
        if ( v21 != 2 || (v24 = 255, TCommunications_Handler::IsPlayerReady(comm, v8 + 1)) )
          v24 = 65280;
        TDropDownPanel::set_val_text_color(v1->playerNameDrop[v8], v24, 0);
        TTextPanel::set_text_color(v1->playerNameText[v8], v24, 0);
        v21 = humanitya;
      }
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
        break;
      v28 = v1->playerNameText[v8];
      if ( v9 != 1 )
      {
        v27 = v28->vfptr;
LABEL_79:
        v29 = TDropDownPanel::get_text(v1->playerNameDrop[v8]);
        (*(void (__thiscall **)(TTextPanel *, char *))&v27[1].gap4[4])(v1->playerNameText[v8], v29);
        goto LABEL_80;
      }
      (*(void (__stdcall **)(signed int))&v28->vfptr[1].gap4[0])(9651);
LABEL_80:
      v30 = v1->playerCivDrop[v8];
      if ( v30->mode != 2 )
      {
        if ( v9 == 1 && v1->myCivilization )
        {
          v32 = TDropDownPanel::get_line(v30, v1->myCivilization);
        }
        else
        {
          v31 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, v8);
          if ( v31 >= 50 )
            v31 -= 50;
          v32 = TDropDownPanel::get_line(v1->playerCivDrop[v8], v31);
        }
        TDropDownPanel::set_line(v1->playerCivDrop[v8], v32);
      }
      v33 = v1->playerCivText[v8]->vfptr;
      v34 = TDropDownPanel::get_text(v1->playerCivDrop[v8]);
      (*(void (__thiscall **)(TTextPanel *, char *))&v33[1].gap4[4])(v1->playerCivText[v8], v34);
      v35 = v1->scenarioPlayerDrop[v8];
      if ( v35->mode != 2 )
      {
        if ( v9 != 1 || v1->myScenarioPlayer == -1 )
        {
          v36 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, v8);
          v37 = TDropDownPanel::get_line(v1->scenarioPlayerDrop[v8], v36);
        }
        else
        {
          v37 = TDropDownPanel::get_line(v35, v1->myScenarioPlayer);
        }
        TDropDownPanel::set_line(v1->scenarioPlayerDrop[v8], v37);
      }
      v38 = v1->scenarioPlayerText[v8]->vfptr;
      v39 = TDropDownPanel::get_text(v1->scenarioPlayerDrop[v8]);
      (*(void (__thiscall **)(TTextPanel *, char *))&v38[1].gap4[4])(v1->scenarioPlayerText[v8], v39);
      if ( RGE_Base_Game::multiplayerGame(rge_base_game) && TCommunications_Handler::IsHost(comm) && !v9 )
      {
        (*(void (__stdcall **)(signed int, signed int))&v1->playerNameDrop[v8]->vfptr->gap10[4])(1, v44);
        v44 = 0;
        v40 = v1->playerNameText[v8]->vfptr;
      }
      else
      {
        (*(void (__stdcall **)(_DWORD, signed int))&v1->playerNameDrop[v8]->vfptr->gap10[4])(0, v44);
        v44 = 1;
        v40 = v1->playerNameText[v8]->vfptr;
      }
      (*(void (**)(void))&v40->gap10[4])();
      (*(void (__stdcall **)(_DWORD))&v1->playerCivDrop[v8]->vfptr->gap10[4])(0);
      (*(void (__stdcall **)(_DWORD))&v1->playerCivText[v8]->vfptr->gap10[4])(0);
      if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
        goto LABEL_121;
      if ( v9 && !v1->i_am_ready )
        goto LABEL_110;
      if ( TCommunications_Handler::IsHost(comm) )
      {
        v41 = humanitya;
        if ( humanitya == 4 && !v1->i_am_ready )
          goto LABEL_110;
      }
      else
      {
LABEL_121:
        v41 = humanitya;
      }
      if ( !RGE_Base_Game::singlePlayerGame(rge_base_game) || !v9 && v41 != 4 )
      {
        if ( v41 == 2 || v41 == 4 )
          (*(void (__stdcall **)(signed int))&v1->playerCivText[v8]->vfptr->gap10[4])(1);
        goto LABEL_114;
      }
LABEL_110:
      (*(void (__stdcall **)(signed int))&v1->playerCivDrop[v8]->vfptr->gap10[4])(1);
LABEL_114:
      (*(void (__stdcall **)(_DWORD))&v1->scenarioPlayerDrop[v8]->vfptr->gap10[4])(0);
      (*(void (__stdcall **)(_DWORD))&v1->scenarioPlayerText[v8++]->vfptr->gap10[4])(0);
      if ( v8 >= RGE_Base_Game::numberPlayers(rge_base_game) )
        goto LABEL_115;
    }
    if ( TDropDownPanel::get_id(v1->playerNameDrop[v8], 0) == 2 )
      TDropDownPanel::delete_line(v1->playerNameDrop[v8], 0);
    if ( v21 == 2 )
    {
      v25 = TCommunications_Handler::GetPlayerName(comm, v8 + 1);
      TDropDownPanel::insert_line(v1->playerNameDrop[v8], 0, v25, 2);
    }
    v26 = TDropDownPanel::get_line(v1->playerNameDrop[v8], v21);
    TDropDownPanel::set_line(v1->playerNameDrop[v8], v26);
    v27 = v1->playerNameText[v8]->vfptr;
    goto LABEL_79;
  }
LABEL_115:
  if ( v8 < 8 )
  {
    v42 = (int)&v1->playerCivDrop[v8];
    v43 = 8 - v8;
    do
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 32) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v42 + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 + 32) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 96) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 160) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 64) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 128) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 320) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 288) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 256) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 224) + 20))(0);
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v42 - 192) + 20))(0);
      v42 += 4;
      --v43;
    }
    while ( v43 );
  }
  TribeMPSetupScreen::fillPlayerColors(v1);
}

//----- (004A4100) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::fillChat(TribeMPSetupScreen *this, int line_no)
{
  TribeMPSetupScreen *v2; // esi@1
  int v3; // eax@2
  int v4; // edi@4
  char *v5; // eax@8

  v2 = this;
  if ( !RGE_Base_Game::singlePlayerGame(rge_base_game) )
  {
    v3 = TTextPanel::numberLines(v2->chatBox);
    v4 = v3 > 0 && v2->chatBox->bot_line == v3 - 1;
    if ( v3 >= 100 )
      TTextPanel::delete_line(v2->chatBox, 0);
    v5 = TChat::GetChatMsg(chat, line_no);
    TTextPanel::word_wrap_append(v2->chatBox, v5);
    if ( v4 )
      TTextPanel::scroll(v2->chatBox, 7, 0, 1);
  }
}

//----- (004A4190) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::updateSummary(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // ebp@1
  void *v2; // edi@1
  bool v3; // zf@1
  int v4; // eax@1
  T_Scenario *v5; // ecx@9
  int v6; // ebx@9
  char *v7; // esi@11
  char *v8; // eax@11
  char *v9; // ST4C_4@12
  char *v10; // ST4C_4@13
  TDropDownPanel **v11; // esi@18
  signed int v12; // edi@18
  TDropDownPanel **v13; // edi@25
  signed int v14; // esi@25
  int v15; // ebx@28
  signed int v16; // edi@28
  TDropDownPanel **v17; // esi@34
  signed int v18; // edi@34
  int v19; // ebx@36
  char *v20; // edi@37
  TDropDownPanel **v21; // edi@37
  signed int v22; // esi@37
  int v23; // eax@42
  char *v24; // esi@46
  char *v25; // eax@46
  char *v26; // ST4C_4@47
  char *v27; // ST4C_4@48
  int v28; // esi@51
  signed int v29; // edi@51
  char *v30; // ST4C_4@54
  char *v31; // eax@54
  int v32; // ebx@54
  char *v33; // eax@58
  char *v34; // eax@61
  char *v35; // eax@68
  int v36; // ebx@68
  char *v37; // eax@69
  char *v38; // eax@79
  int v39; // ST4C_4@83
  char *v40; // eax@83
  int v41; // ST4C_4@84
  char *v42; // eax@84
  char *v43; // eax@85
  int v44; // ebx@86
  char *v45; // eax@88
  int v46; // ST4C_4@90
  char *v47; // eax@90
  char *v48; // eax@87
  char *v49; // eax@94
  int v50; // ebx@95
  TRIBE_Game::Age v51; // eax@95
  char *v52; // eax@100
  int v53; // ebx@100
  TRIBE_Game::ResourceLevel v54; // eax@100
  char *v55; // eax@103
  int v56; // ebx@103
  int v57; // eax@103
  int v58; // ebx@103
  char *v59; // eax@106
  int v60; // ebx@106
  char *v61; // eax@107
  char *v62; // eax@109
  int v63; // ebx@109
  char *v64; // eax@112
  int v65; // ebx@112
  char *v66; // eax@114
  char *v67; // eax@116
  char v68; // al@118
  char *v69; // eax@120
  int v70; // ebx@120
  int v71; // ST4C_4@120
  char *v72; // eax@120
  int v73; // [sp+44h] [bp-550h]@96
  char *v74; // [sp+48h] [bp-54Ch]@96
  char *v75; // [sp+48h] [bp-54Ch]@118
  int v76; // [sp+50h] [bp-544h]@0
  int v77; // [sp+50h] [bp-544h]@106
  int v78; // [sp+50h] [bp-544h]@112
  char str1[256]; // [sp+64h] [bp-530h]@11
  char str2[256]; // [sp+164h] [bp-430h]@22
  char file_name[260]; // [sp+264h] [bp-330h]@11
  char str3[256]; // [sp+37Ch] [bp-218h]@103
  struct _finddata_t v83; // [sp+47Ch] [bp-118h]@46

  v1 = this;
  v2 = 0;
  v3 = RGE_Base_Game::scenarioGame(rge_base_game) == 0;
  v4 = v1->saveRandomGame;
  if ( v3 )
  {
    if ( v4 )
      goto LABEL_7;
    goto LABEL_6;
  }
  if ( v4 || strcmp(RGE_Base_Game::scenarioName(rge_base_game), v1->saveScenarioName) )
LABEL_6:
    v2 = (void *)1;
LABEL_7:
  if ( v2 )
  {
    if ( RGE_Base_Game::scenarioGame(rge_base_game) )
    {
      v5 = v1->scenarioInfo;
      v6 = 0;
      if ( v5 )
      {
        ((void (__stdcall *)(signed int))v5->vfptr->~RGE_Scenario)(1);
        v1->scenarioInfo = 0;
      }
      v7 = rge_base_game->prog_info->scenario_dir;
      v8 = RGE_Base_Game::scenarioName(rge_base_game);
      sprintf(str1, aSS_scn, v7, v8);
      if ( _findfirst(str1, (struct _finddata_t *)file_name) == -1 )
      {
        v9 = RGE_Base_Game::scenarioName(rge_base_game);
        sprintf(str1, aS_scx, v9);
      }
      else
      {
        v10 = RGE_Base_Game::scenarioName(rge_base_game);
        sprintf(str1, aS_scn, v10);
      }
      if ( str1[0] != 46 )
        v1->scenarioInfo = (T_Scenario *)RGE_Base_Game::get_scenario_info(rge_base_game, (int)v1, v2, str1, 0);
      if ( v1->scenarioInfo )
      {
        v11 = v1->scenarioPlayerDrop;
        v12 = 8;
        do
        {
          TDropDownPanel::empty_list(*v11);
          ++v11;
          --v12;
        }
        while ( v12 );
        v1->settingsFixed = T_Scenario::any_sp_victory(v1->scenarioInfo);
        v1->numberAnyPlayers = 0;
        v1->scenarioPlayerCount = 0;
        do
        {
          if ( RGE_Scenario::Get_player_Active((RGE_Scenario *)&v1->scenarioInfo->vfptr, v6) )
          {
            ++v1->scenarioPlayerCount;
            sprintf(str2, aD_3, v6 + 1);
            if ( RGE_Base_Game::multiplayerGame(rge_base_game)
              || RGE_Base_Game::singlePlayerGame(rge_base_game)
              && RGE_Scenario::Get_player_Type((RGE_Scenario *)&v1->scenarioInfo->vfptr, v6) == 1 )
            {
              v13 = v1->scenarioPlayerDrop;
              v14 = 8;
              ++v1->numberAnyPlayers;
              do
              {
                TDropDownPanel::append_line(*v13, str2, v6);
                ++v13;
                --v14;
              }
              while ( v14 );
            }
          }
          ++v6;
        }
        while ( v6 < 9 );
        v15 = -1;
        v16 = 0;
        while ( 1 )
        {
          if ( ++v15 == 9 )
            v15 = 0;
          if ( RGE_Scenario::Get_player_Active((RGE_Scenario *)&v1->scenarioInfo->vfptr, v15) )
          {
            v1->defaultColor[v16] = v15 + 1;
            TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v16, v15);
            TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v16, v1->defaultColor[v16]);
            RGE_Base_Game::setPlayerTeam(rge_base_game, v16++, 1);
            if ( v16 >= 8 )
              break;
          }
        }
      }
      else
      {
        RGE_Base_Game::setScenarioGame(rge_base_game, 0);
      }
    }
    if ( RGE_Base_Game::randomGame(rge_base_game) )
    {
      v17 = v1->scenarioPlayerDrop;
      v18 = 8;
      do
      {
        TDropDownPanel::empty_list(*v17);
        ++v17;
        --v18;
      }
      while ( v18 );
      v1->scenarioPlayerCount = 8;
      v1->numberAnyPlayers = 8;
      v19 = 0;
      v1->settingsFixed = 0;
      do
      {
        v20 = &v1->defaultColor[v19];
        *v20 = v19 + 1;
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v19, v19);
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v19, (unsigned __int8)*v20);
        RGE_Base_Game::setPlayerTeam(rge_base_game, v19, 1);
        sprintf(str2, aD_3, &v20[1 - ((_DWORD)v1 + 2144)]);
        v21 = v1->scenarioPlayerDrop;
        v22 = 8;
        do
        {
          TDropDownPanel::append_line(*v21, str2, v19);
          ++v21;
          --v22;
        }
        while ( v22 );
        ++v19;
      }
      while ( v19 < 8 );
    }
    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
      TribeMPSetupScreen::setupSinglePlayerPlayers(v1);
    v23 = RGE_Base_Game::randomGame(rge_base_game);
    v1->saveRandomGame = v23;
    if ( v23 )
      v1->saveScenarioName[0] = 0;
    else
      strcpy(v1->saveScenarioName, RGE_Base_Game::scenarioName(rge_base_game));
    memset(v1->scenarioCheckSum, 0, sizeof(v1->scenarioCheckSum));
    if ( RGE_Base_Game::scenarioGame(rge_base_game) )
    {
      v24 = rge_base_game->prog_info->scenario_dir;
      v25 = RGE_Base_Game::scenarioName(rge_base_game);
      sprintf(file_name, aSS_scn, v24, v25);
      if ( _findfirst(file_name, &v83) == -1 )
      {
        v26 = RGE_Base_Game::scenarioName(rge_base_game);
        sprintf(file_name, aS_scx, v26);
      }
      else
      {
        v27 = RGE_Base_Game::scenarioName(rge_base_game);
        sprintf(file_name, aS_scn, v27);
      }
      v1->myScenarioChecksum = (int)RGE_Base_Game::get_scenario_checksum(rge_base_game, file_name);
    }
    else
    {
      v1->myScenarioChecksum = 0;
    }
  }
  v28 = (int)v1->settingText;
  v29 = 20;
  do
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v28 + 20))(0);
    v28 += 4;
    --v29;
  }
  while ( v29 );
  if ( RGE_Base_Game::scenarioGame(rge_base_game) )
  {
    v30 = RGE_Base_Game::scenarioName(rge_base_game);
    v31 = TPanel::get_string(9709);
    sprintf(str2, v31, v30);
    (*(void (__stdcall **)(char *))&v1->scenarioName->vfptr[1].gap4[4])(str2);
    v32 = 3;
  }
  else
  {
    if ( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
      TPanel::get_string(9751, str1, 256);
    else
      TPanel::get_string(9653, str1, 256);
    v33 = TPanel::get_string(9709);
    sprintf(str2, v33, str1);
    (*(void (__stdcall **)(char *))&v1->scenarioName->vfptr[1].gap4[4])(str2);
    v32 = 1;
  }
  if ( RGE_Base_Game::randomGame(rge_base_game) )
  {
    switch ( TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game) )
    {
      case 0:
        v34 = TPanel::get_string(10611);
        goto LABEL_67;
      case 1:
        v34 = TPanel::get_string(10612);
        goto LABEL_67;
      case 2:
        v34 = TPanel::get_string(10613);
        goto LABEL_67;
      case 3:
        v34 = TPanel::get_string(10614);
        goto LABEL_67;
      case 4:
        v34 = TPanel::get_string(10615);
        goto LABEL_67;
      case 5:
        v34 = TPanel::get_string(10616);
LABEL_67:
        strcpy(str1, v34);
        break;
      default:
        break;
    }
    v35 = TPanel::get_string(9690);
    sprintf(str2, v35, str1);
    (*(void (__stdcall **)(char *))&v1->settingText[v32]->vfptr[1].gap4[4])(str2);
    (*(void (__stdcall **)(signed int))&v1->settingText[v32]->vfptr->gap10[4])(1);
    v36 = v32 + 1;
    switch ( TRIBE_Game::mapType((TRIBE_Game *)rge_base_game) )
    {
      case 0:
        v37 = TPanel::get_string(10602);
        goto LABEL_78;
      case 1:
        v37 = TPanel::get_string(10603);
        goto LABEL_78;
      case 2:
        v37 = TPanel::get_string(10604);
        goto LABEL_78;
      case 3:
        v37 = TPanel::get_string(10605);
        goto LABEL_78;
      case 4:
        v37 = TPanel::get_string(10606);
        goto LABEL_78;
      case 5:
        v37 = TPanel::get_string(10607);
        goto LABEL_78;
      case 6:
        v37 = TPanel::get_string(10608);
        goto LABEL_78;
      case 7:
        v37 = TPanel::get_string(10609);
        goto LABEL_78;
      case 8:
        v37 = TPanel::get_string(10610);
LABEL_78:
        strcpy(str1, v37);
        break;
      default:
        break;
    }
    v38 = TPanel::get_string(9654);
    sprintf(str2, v38, str1);
    (*(void (__stdcall **)(char *))&v1->settingText[v36]->vfptr[1].gap4[4])(str2);
    (*(void (__stdcall **)(signed int))&v1->settingText[v36]->vfptr->gap10[4])(1);
    v32 = v36 + 1;
  }
  if ( RGE_Base_Game::scenarioGame(rge_base_game) )
  {
    if ( v1->settingsFixed || v1->scenarioPlayerCount == 2 )
    {
      v41 = v1->scenarioPlayerCount;
      v42 = TPanel::get_string(9655);
      sprintf(str2, aSD_2, v42, v41);
    }
    else
    {
      v39 = v1->scenarioPlayerCount;
      v40 = TPanel::get_string(9655);
      sprintf(str2, aSDD, v40, 2, v39);
    }
  }
  else
  {
    v43 = TPanel::get_string(9655);
    sprintf(str2, aS28, v43);
  }
  (*(void (__stdcall **)(char *))&v1->settingText[v32]->vfptr[1].gap4[4])(str2);
  (*(void (__stdcall **)(signed int))&v1->settingText[v32]->vfptr->gap10[4])(1);
  v44 = v32 + 1;
  switch ( TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) )
  {
    case 1:
      v48 = TPanel::get_string(4321);
      break;
    case 7:
      v45 = TPanel::get_string(4329);
      goto LABEL_90;
    case 8:
      v45 = TPanel::get_string(4330);
LABEL_90:
      strcpy(str1, v45);
      v46 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
      v47 = TPanel::get_string(9662);
      sprintf(str2, v47, str1, v46);
      goto LABEL_95;
    default:
      if ( RGE_Base_Game::randomGame(rge_base_game) )
        goto LABEL_92;
      v48 = TPanel::get_string(4327);
      break;
    case 9:
LABEL_92:
      v48 = TPanel::get_string(4332);
      break;
  }
  strcpy(str1, v48);
  v49 = TPanel::get_string(9660);
  sprintf(str2, v49, str1);
LABEL_95:
  (*(void (__stdcall **)(char *))&v1->settingText[v44]->vfptr[1].gap4[4])(str2);
  (*(void (__stdcall **)(signed int))&v1->settingText[v44]->vfptr->gap10[4])(1);
  v50 = v44 + 1;
  v51 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  if ( v51 )
  {
    if ( v51 == 1 )
    {
      v74 = str1;
      v73 = 4206;
    }
    else
    {
      v74 = str1;
      v73 = v51 + 4199;
    }
  }
  else
  {
    v74 = str1;
    v73 = 4327;
  }
  TPanel::get_string(v73, v74, 256);
  v52 = TPanel::get_string(9700);
  sprintf(str2, v52, str1);
  (*(void (__stdcall **)(char *, int))&v1->settingText[v50]->vfptr[1].gap4[4])(str2, v76);
  (*(void (__stdcall **)(signed int))&v1->settingText[v50]->vfptr->gap10[4])(1);
  v53 = v50 + 1;
  v54 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  if ( v54 )
    TPanel::get_string(v54 + 9701, &str1[4], 256);
  else
    TPanel::get_string(4327, &str1[4], 256);
  v55 = TPanel::get_string(9701);
  sprintf(&str2[4], v55, &str1[4]);
  (*(void (__stdcall **)(char *))&v1->settingText[v53]->vfptr[1].gap4[4])(&str2[4]);
  (*(void (__stdcall **)(signed int))&v1->settingText[v53]->vfptr->gap10[4])(1);
  v56 = v53 + 1;
  RGE_Base_Game::difficulty(rge_base_game);
  v57 = RGE_Base_Game::difficulty(rge_base_game);
  TPanel::get_string(v57 + 11216, &str1[4], 256);
  TPanel::get_string(9696, &str2[4], 256);
  sprintf(&str3[4], &str2[4], &str1[4]);
  (*(void (__stdcall **)(char *))&v1->settingText[v56]->vfptr[1].gap4[4])(&str3[4]);
  (*(void (__stdcall **)(signed int))&v1->settingText[v56]->vfptr->gap10[4])(1);
  v58 = v56 + 1;
  if ( TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game) )
    TPanel::get_string(4004, &str1[4], 256);
  else
    TPanel::get_string(4003, &str1[4], 256);
  v59 = TPanel::get_string(9705);
  sprintf(&str2[4], v59, &str1[4]);
  (*(void (__cdecl **)(char *))&v1->settingText[v58]->vfptr[1].gap4[4])(&str2[4]);
  (*(void (__stdcall **)(signed int))&v1->settingText[v58]->vfptr->gap10[4])(1);
  v60 = v58 + 1;
  if ( RGE_Base_Game::fullVisibility(rge_base_game) )
    v61 = TPanel::get_string(4003);
  else
    v61 = TPanel::get_string(4004);
  strcpy(str1, v61);
  v62 = TPanel::get_string(9656);
  sprintf(str2, v62, str1);
  (*(void (__stdcall **)(char *, int))&v1->settingText[v60]->vfptr[1].gap4[4])(str2, v77);
  (*(void (__stdcall **)(signed int))&v1->settingText[v60]->vfptr->gap10[4])(1);
  v63 = v60 + 1;
  if ( TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game) )
    TPanel::get_string(4003, &str1[4], 256);
  else
    TPanel::get_string(4004, &str1[4], 256);
  v64 = TPanel::get_string(9708);
  sprintf(&str2[4], v64, &str1[4]);
  (*(void (__cdecl **)(char *))&v1->settingText[v63]->vfptr[1].gap4[4])(&str2[4]);
  (*(void (__stdcall **)(signed int))&v1->settingText[v63]->vfptr->gap10[4])(1);
  v65 = v63 + 1;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
      v66 = TPanel::get_string(4003);
    else
      v66 = TPanel::get_string(4004);
    strcpy(str1, v66);
    v67 = TPanel::get_string(9659);
    sprintf(str2, v67, str1);
    (*(void (__stdcall **)(char *))&v1->settingText[v65]->vfptr[1].gap4[4])(str2);
    (*(void (__stdcall **)(signed int))&v1->settingText[v65++]->vfptr->gap10[4])(1);
  }
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    v75 = str1;
    v68 = RGE_Base_Game::mpPathFinding(rge_base_game);
  }
  else
  {
    v75 = str1;
    v68 = RGE_Base_Game::pathFinding(rge_base_game);
  }
  TPanel::get_string((unsigned __int8)v68 + 9742, v75, 256);
  v69 = TPanel::get_string(9713);
  sprintf(str2, v69, str1);
  (*(void (__stdcall **)(char *))&v1->settingText[v65]->vfptr[1].gap4[4])(str2);
  (*(void (__stdcall **)(signed int))&v1->settingText[v65]->vfptr->gap10[4])(1);
  v70 = v65 + 1;
  v71 = (unsigned __int8)TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
  v72 = TPanel::get_string(9712);
  sprintf(str2, v72, v71);
  (*(void (__stdcall **)(char *))&v1->settingText[v70]->vfptr[1].gap4[4])(str2);
  (*(void (__thiscall **)(TTextPanel *, signed int))&v1->settingText[v70]->vfptr->gap10[4])(v1->settingText[v70], 1);
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
  {
    if ( RGE_Base_Game::scenarioGame(rge_base_game) && (v1->settingsFixed || v1->scenarioPlayerCount < 3) )
    {
      (*(void (__stdcall **)(_DWORD, int))&v1->numberPlayersTitle->vfptr->gap10[4])(0, v78);
      (*(void (__cdecl **)(signed int))&v1->numberPlayersDrop->vfptr->gap10[4])(0);
    }
    else
    {
      (*(void (__stdcall **)(signed int, int))&v1->numberPlayersTitle->vfptr->gap10[4])(1, v78);
      (*(void (__cdecl **)(signed int))&v1->numberPlayersDrop->vfptr->gap10[4])(1);
    }
  }
  TribeMPSetupScreen::fillPlayers(v1);
}

//----- (004A4FC0) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::kickPlayer(TribeMPSetupScreen *this, int p)
{
  TribeMPSetupScreen *v2; // esi@1
  char *v3; // ST0C_4@1
  char *v4; // eax@1
  char text[256]; // [sp+4h] [bp-100h]@1

  v2 = this;
  this->playerToKick = p;
  v3 = TCommunications_Handler::GetPlayerName(comm, p);
  v4 = TPanel::get_string(9672);
  sprintf(text, v4, v3);
  TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v2->vfptr, text, aKickDialog, 450, 100);
}

//----- (004A5020) --------------------------------------------------------
void __stdcall TribeMPSetupScreen::handleKickedPlayer(int really_kicked)
{
  TEasy_Panel *v2; // eax@1

  TribeMPSetupScreen::cancelScreen(0);
  v2 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  if ( v2 )
    TEasy_Panel::popupOKDialog(v2, 9674 - (really_kicked != 0), 0, 450, 100);
}

//----- (004A5060) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::activateVictoryPanels(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // esi@1

  v1 = this;
  if ( TDropDownPanel::get_id(this->victoryTypeDrop) != 1 && TDropDownPanel::get_id(v1->victoryTypeDrop) )
  {
    (*(void (__stdcall **)(signed int))&v1->victoryAmountLabel->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v1->victoryAmountInput->vfptr->gap10[4])(1);
    switch ( TDropDownPanel::get_id(v1->victoryTypeDrop) )
    {
      case 2:
        (*(void (__stdcall **)(signed int))&v1->victoryAmountLabel->vfptr[1].gap4[0])(9675);
        break;
      case 3:
      case 4:
      case 5:
        (*(void (__stdcall **)(signed int))&v1->victoryAmountLabel->vfptr[1].gap4[0])(9676);
        break;
      case 6:
        (*(void (__stdcall **)(signed int))&v1->victoryAmountLabel->vfptr[1].gap4[0])(9677);
        break;
      default:
        return;
    }
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))&v1->victoryAmountLabel->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v1->victoryAmountInput->vfptr->gap10[4])(0);
  }
}

//----- (004A5130) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::setupTabOrder(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // esi@1
  TPanel *v2; // eax@2
  TPanel *v3; // edx@2
  TPanelVtbl *v4; // eax@2
  TPanel *v5; // eax@3
  TPanel *v6; // edx@4
  TPanelVtbl *v7; // eax@4
  TPanel *v8; // ecx@5
  TPanelVtbl *v9; // edx@5
  TPanel *tabList[4]; // [sp+4h] [bp-10h]@2

  v1 = this;
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
  {
    v2 = (TPanel *)v1->startButton;
    v3 = (TPanel *)v1->gameSettingsButton;
    tabList[1] = (TPanel *)v1->cancelButton;
    tabList[0] = v2;
    v4 = v1->vfptr;
    tabList[2] = v3;
    v4->set_tab_order((TPanel *)v1, (TPanel *)tabList, (TPanel *)3);
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)v1->startButton);
  }
  else
  {
    tabList[0] = (TPanel *)&v1->chatInput->vfptr;
    v5 = (TPanel *)v1->gameSettingsButton;
    if ( v5 )
    {
      v6 = (TPanel *)v1->cancelButton;
      tabList[1] = (TPanel *)v1->startButton;
      tabList[3] = v5;
      v7 = v1->vfptr;
      tabList[2] = v6;
      v7->set_tab_order((TPanel *)v1, (TPanel *)tabList, (TPanel *)4);
      TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->chatInput->vfptr);
    }
    else
    {
      v8 = (TPanel *)v1->cancelButton;
      v9 = v1->vfptr;
      tabList[1] = (TPanel *)v1->ready_button;
      tabList[2] = v8;
      v9->set_tab_order((TPanel *)v1, (TPanel *)tabList, (TPanel *)3);
      TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->chatInput->vfptr);
    }
  }
}

//----- (004A5210) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::setupSinglePlayerPlayers(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // ebx@1
  int v2; // edi@2
  int v3; // ebp@3
  int v4; // esi@3
  int v5; // eax@5
  int v6; // esi@11
  int v7; // eax@15
  int v8; // eax@15
  int v9; // eax@15
  int v10; // esi@17
  char v11; // al@18
  int v12; // esi@19
  signed int v13; // esi@21
  int first_any_player; // [sp+10h] [bp-Ch]@2
  int first_any_civ; // [sp+14h] [bp-8h]@2
  int first_any_color; // [sp+18h] [bp-4h]@2

  v1 = this;
  if ( RGE_Base_Game::scenarioGame(rge_base_game) )
  {
    v2 = -1;
    first_any_player = -1;
    first_any_civ = -1;
    first_any_color = -1;
    if ( v1->scenarioInfo )
    {
      v3 = 0;
      v4 = 0;
      do
      {
        if ( RGE_Scenario::Get_player_Active((RGE_Scenario *)&v1->scenarioInfo->vfptr, v4) )
        {
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v3, v4);
          v5 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)&v1->scenarioInfo->vfptr, v4);
          TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v3, v5);
          TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v3, v4 + 1);
          if ( RGE_Scenario::Get_player_Type((RGE_Scenario *)&v1->scenarioInfo->vfptr, v4) == 1
            && first_any_player == -1 )
          {
            first_any_player = v4;
            first_any_civ = RGE_Scenario::Get_player_Civ((RGE_Scenario *)&v1->scenarioInfo->vfptr, v4);
            first_any_color = v4 + 1;
          }
          v2 = first_any_player;
          ++v3;
        }
        ++v4;
      }
      while ( v4 < 9 );
    }
    RGE_Base_Game::setNumberPlayers(rge_base_game, v1->scenarioPlayerCount);
    if ( v2 != -1 )
    {
      v6 = 1;
      if ( v1->scenarioPlayerCount > 1 )
      {
        while ( TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, v6) != v2 )
        {
          if ( ++v6 >= v1->scenarioPlayerCount )
            goto LABEL_16;
        }
        v7 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, 0);
        TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v6, v7);
        v8 = TRIBE_Game::civilization((TRIBE_Game *)rge_base_game, 0);
        TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v6, v8);
        v9 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, 0);
        TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v6, v9);
      }
LABEL_16:
      TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, 0, v2);
      TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, 0, first_any_civ);
      TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, 0, first_any_color);
    }
  }
  else
  {
    v10 = 0;
    do
    {
      v11 = debug_rand(aCMsdevWorkA_42, 2865);
      TRIBE_Game::setCivilization((TRIBE_Game *)rge_base_game, v10, (unsigned __int8)(v11 % -16) + 1);
      TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v10, v10 + 1);
      ++v10;
    }
    while ( v10 < 8 );
  }
  v12 = 0;
  do
    RGE_Base_Game::setPlayerTeam(rge_base_game, v12++, 1);
  while ( v12 < 8 );
  TCommunications_Handler::SetPlayerHumanity(comm, 1u, ME_HUMAN);
  v13 = 2;
  do
    TCommunications_Handler::SetPlayerHumanity(comm, v13++, ME_COMPUTER);
  while ( v13 <= 8 );
  TCommunications_Handler::SetPlayerHumanity(comm, 9u, 0);
  TribeMPSetupScreen::fillNumberPlayers(v1);
}

//----- (004A5440) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::fillNumberPlayers(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // edi@1
  int i; // esi@1
  int v3; // eax@3
  int v4; // eax@3
  char str[16]; // [sp+8h] [bp-10h]@2

  v1 = this;
  TDropDownPanel::empty_list(this->numberPlayersDrop);
  for ( i = 2; i <= v1->scenarioPlayerCount; ++i )
  {
    sprintf(str, aD_3, i);
    TDropDownPanel::append_line(v1->numberPlayersDrop, str, i);
  }
  v3 = RGE_Base_Game::numberPlayers(rge_base_game);
  v4 = TDropDownPanel::get_line(v1->numberPlayersDrop, v3);
  TDropDownPanel::set_line(v1->numberPlayersDrop, v4);
}

//----- (004A54C0) --------------------------------------------------------
void __thiscall TribeMPSetupScreen::fillPlayerColors(TribeMPSetupScreen *this)
{
  TribeMPSetupScreen *v1; // ebx@1
  TButtonPanel **v2; // edi@1
  int v3; // ebp@2
  int v4; // esi@2
  RGE_Scenario *v5; // ecx@4
  unsigned int v6; // [sp-8h] [bp-30h]@9
  signed int v7; // [sp+10h] [bp-18h]@1
  TribeMPSetupScreen *v8; // [sp+14h] [bp-14h]@1
  char str[16]; // [sp+18h] [bp-10h]@8

  v1 = this;
  v8 = this;
  v2 = this->playerColor;
  v7 = 8;
  do
  {
    v3 = 0;
    v4 = 0;
    do
    {
      if ( !RGE_Base_Game::scenarioGame(rge_base_game)
        || (v5 = (RGE_Scenario *)&v1->scenarioInfo->vfptr) == 0
        || RGE_Scenario::Get_player_Active(v5, v3)
        && (!RGE_Base_Game::singlePlayerGame(rge_base_game)
         || RGE_Scenario::Get_player_Type((RGE_Scenario *)&v1->scenarioInfo->vfptr, v3) == 1) )
      {
        sprintf(str, aD_3, v3 + 1);
        TButtonPanel::set_text(*v2, v4, str);
        TButtonPanel::set_id(*v2, v4, v3 + 1, 0);
        switch ( v3 )
        {
          case 0:
            v6 = 16711680;
            goto LABEL_17;
          case 1:
            v6 = 255;
            goto LABEL_17;
          case 2:
            v6 = 0xFFFF;
            goto LABEL_17;
          case 3:
            v6 = 2639475;
            goto LABEL_17;
          case 4:
            v6 = 484592;
            goto LABEL_17;
          case 5:
            v6 = 65280;
            goto LABEL_17;
          case 6:
            v6 = 11842740;
            goto LABEL_17;
          case 7:
            v6 = 9682731;
LABEL_17:
            TButtonPanel::set_text_color(*v2, v4, v6, 0);
            break;
          default:
            break;
        }
        v1 = v8;
        ++v4;
      }
      ++v3;
    }
    while ( v3 < 8 );
    TButtonPanel::set_state_info(*v2, v4);
    ++v2;
    --v7;
  }
  while ( v7 );
}
