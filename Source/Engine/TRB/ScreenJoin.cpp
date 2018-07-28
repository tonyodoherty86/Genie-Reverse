
//----- (00491650) --------------------------------------------------------
void __thiscall TribeJoinScreen::TribeJoinScreen(TribeJoinScreen *this)
{
  TribeJoinScreen *v1; // esi@1
  signed int v2; // edi@1
  TTextPanel **v3; // ebp@6
  TTextPanel *v4; // ecx@8
  TPanel **v5; // ebx@8
  TPanel **v6; // edi@11
  TPanel *v7; // eax@12
  TPanel *v8; // edx@13
  TPanel *v9; // eax@13
  TPanel *v10; // edx@13
  TPanel *v11; // eax@13
  TPanel *tabList[5]; // [sp+3Ch] [bp-20h]@13
  int v13; // [sp+58h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aJoinScreen);
  v1->vfptr = (TPanelVtbl *)&TribeJoinScreen::`vftable';
  v1->startedSession = 0;
  v1->listFilled = 0;
  Sess = 0;
  v1->game_count = 0;
  v1->waitingToStart = 0;
  v1->joinTime = 0;
  v1->close_button = 0;
  v13 = 0;
  TCommunications_Handler::SetPlayerHumanity(comm, 1u, ME_HUMAN);
  v2 = 2;
  do
    TCommunications_Handler::SetPlayerHumanity(comm, v2++, 0);
  while( v2 <= 9 );
  if( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, info_file_name_in, 50053, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           9631,
           20,
           20,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v1->vfptr,
        (TPanel *)&v1->vfptr,
        &v1->listTitle,
        9640,
        20,
        65,
        600,
        20,
        4,
        0,
        0,
        0);
      v3 = (TTextPanel **)&v1->list;
      if( TEasy_Panel::create_list((TEasy_Panel *)&v1->vfptr, (TPanel *)&v1->vfptr, &v1->list, 20, 90, 600, 270, 11) )
      {
        if( TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->scrollbar, *v3, 20) )
        {
          v4 = *v3;
          v1->listFilled = 1;
          (*(void (__stdcall **)(signed int))&v4->vfptr[1].gap4[0])(9643);
          v5 = (TPanel **)&v1->refreshButton;
          if( TEasy_Panel::create_button(
                 (TEasy_Panel *)&v1->vfptr,
                 (TPanel *)&v1->vfptr,
                 &v1->refreshButton,
                 9633,
                 0,
                 210,
                 370,
                 220,
                 30,
                 0,
                 0,
                 0) )
          {
            if( TEasy_Panel::create_button(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->joinButton,
                   9632,
                   0,
                   10,
                   440,
                   200,
                   30,
                   0,
                   0,
                   0) )
            {
              if( TEasy_Panel::create_button(
                     (TEasy_Panel *)&v1->vfptr,
                     (TPanel *)&v1->vfptr,
                     &v1->createButton,
                     9634,
                     0,
                     220,
                     440,
                     200,
                     30,
                     0,
                     0,
                     0) )
              {
                v6 = (TPanel **)&v1->cancelButton;
                if( TEasy_Panel::create_button(
                       (TEasy_Panel *)&v1->vfptr,
                       (TPanel *)&v1->vfptr,
                       &v1->cancelButton,
                       4002,
                       0,
                       430,
                       440,
                       200,
                       30,
                       0,
                       0,
                       0) )
                {
                  v7 = *v6;
                  v7[2].max_wid = 27;
                  v7[2].min_hgt = 0;
                  if( TEasy_Panel::create_button(
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
                    (*(void (__stdcall **)(signed int))(*(_DWORD *)v1->close_button + 20))(1);
                    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v1->close_button + 24))(
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
                    TPanel::set_curr_child((TPanel *)&v1->vfptr, *v5);
                    v8 = (TPanel *)*v3;
                    v9 = *v5;
                    tabList[2] = (TPanel *)v1->joinButton;
                    tabList[0] = v8;
                    v10 = (TPanel *)v1->createButton;
                    tabList[1] = v9;
                    v11 = *v6;
                    tabList[3] = v10;
                    tabList[4] = v11;
                    TPanel::set_tab_order(tabList, 5);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v1->error_code = 1;
  }
}
// 5724F8: using guessed type int (__thiscall *TribeJoinScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (00491970) --------------------------------------------------------
TribeJoinScreen *__thiscall TribeJoinScreen::`vector deleting destructor'(TribeJoinScreen *this, unsigned int __flags)
{
  TribeJoinScreen *v2; // esi@1

  v2 = this;
  TribeJoinScreen::~TribeJoinScreen(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00491A80) --------------------------------------------------------
int __thiscall TribeJoinScreen::handle_idle(TribeJoinScreen *this)
{
  TribeJoinScreen *v1; // esi@1
  int result; // eax@7

  v1 = this;
  if( !this->waitingToStart )
  {
    if( this->listFilled )
    {
      if( !rge_base_game->input_enabled )
        RGE_Base_Game::enable_input(rge_base_game);
    }
    if( !v1->waitingToStart )
      goto LABEL_11;
  }
  if( debug_timeGetTime() - v1->joinTime > 0x2710 )
  {
    TCommunications_Handler::UnlinkToLevel(comm, SERVICE_AVAILABLE);
    v1->waitingToStart = 0;
    RGE_Base_Game::enable_input(rge_base_game);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 9635, 0, 450, 100);
    result = 1;
  }
  else
  {
LABEL_11:
    result = TPanel::handle_idle((TPanel *)&v1->vfptr);
  }
  return result;
}

//----- (00491B20) --------------------------------------------------------
int __thiscall TribeJoinScreen::handle_user_command(TribeJoinScreen *this, unsigned int wParam, int lParam)
{
  TribeJoinScreen *v3; // esi@1
  TribeMPSetupScreen *v4; // eax@3
  int result; // eax@5

  v3 = this;
  switch ( wParam )
  {
    case 0x17B8u:
      if( !this->waitingToStart )
        goto LABEL_8;
      v4 = (TribeMPSetupScreen *)operator new(0x890u);
      if( v4 )
        TribeMPSetupScreen::TribeMPSetupScreen(v4);
      TPanelSystem::setCurrentPanel(&panel_system, aMpSetupScreen, 0);
      TPanelSystem::destroyPanel(&panel_system, aJoinScreen);
      result = 1;
      break;
    case 0x17A8u:
    case 0x17A9u:
    case 0x17AAu:
    case 0x17B2u:
      if( !this->waitingToStart )
        goto LABEL_8;
      TCommunications_Handler::UnlinkToLevel(comm, SERVICE_AVAILABLE);
      v3->waitingToStart = 0;
      RGE_Base_Game::enable_input(rge_base_game);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v3->vfptr, 9635, 0, 450, 100);
      result = 1;
      break;
    default:
LABEL_8:
      result = TPanel::handle_user_command(wParam, lParam);
      break;
  }
  return result;
}

//----- (00491C70) --------------------------------------------------------
void __thiscall TribeJoinScreen::fillList(TribeJoinScreen *this)
{
  TribeJoinScreen *v1; // edi@1
  TListPanel *v2; // ecx@1
  TCommunications_Sessions *v3; // eax@2
  TCommunications_Sessions *v4; // eax@3
  int v5; // eax@9
  TTextPanel *v6; // ecx@9
  int i; // esi@10
  unsigned int v8; // ST10_4@11
  unsigned int v9; // ST0C_4@11
  char *v10; // eax@11
  char szTemp[126]; // [sp+Ch] [bp-8Ch]@11
  int v12; // [sp+94h] [bp-4h]@2

  v1 = this;
  RGE_Base_Game::disable_input(rge_base_game);
  v2 = v1->list;
  v1->listFilled = 0;
  v1->game_count = 0;
  (*(void (__stdcall **)(signed int))&v2->vfptr[1].gap4[0])(9641);
  RGE_Base_Game::draw_window(rge_base_game);
  if( v1->startedSession )
  {
    TCommunications_Sessions::Refresh(Sess);
  }
  else
  {
    v3 = (TCommunications_Sessions *)operator new(0x457B0u);
    v12 = 0;
    if( v3 )
      TCommunications_Sessions::TCommunications_Sessions(v3, comm);
    else
      v4 = 0;
    v12 = -1;
    Sess = v4;
    if( !v4 )
    {
      (*(void (__stdcall **)(signed int))&v1->list->vfptr[1].gap4[0])(9643);
      return;
    }
    v1->startedSession = 1;
  }
  v5 = TCommunications_Sessions::GetSessionCount(Sess);
  v6 = (TTextPanel *)&v1->list->vfptr;
  v1->game_count = v5;
  if( v5 <= 0 )
  {
    (*(void (__stdcall **)(signed int))&v6->vfptr[1].gap4[0])(9643);
  }
  else
  {
    TTextPanel::empty_list(v6);
    for( i = 0; i < v1->game_count; ++i )
    {
      v8 = TCommunications_Sessions::GetSessionMaxPlayers(Sess, i);
      v9 = TCommunications_Sessions::GetSessionCurrentPlayers(Sess, i);
      v10 = TCommunications_Sessions::GetSessionName(Sess, i);
      sprintf(szTemp, aS_1d_1d, v10, v9, v8);
      TTextPanel::append_line((TTextPanel *)&v1->list->vfptr, szTemp, 0);
    }
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->list->vfptr);
  }
  v1->listFilled = 1;
}

//----- (00491E20) --------------------------------------------------------
int __thiscall TribeJoinScreen::action(TribeJoinScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeJoinScreen *v5; // esi@1
  TListPanel *v6; // ecx@2
  int result; // eax@5
  int v8; // eax@9
  _GUID *v9; // eax@9
  char *v10; // eax@10
  TribeMPStartupScreen *v11; // eax@15
  TribeMPCreateDialog *v12; // eax@20
  char temp[256]; // [sp+8h] [bp-20Ch]@10
  char string[256]; // [sp+108h] [bp-10Ch]@10
  int v15; // [sp+210h] [bp-4h]@15

  v5 = this;
  if( !fromPanel )
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  v6 = this->list;
  if( (TListPanel *)fromPanel == v6 )
  {
    if( actionIn == 3 && v5->game_count > 0 )
    {
      ((void (__fastcall *)(TribeJoinScreen *, signed int, TButtonPanel *, signed int, _DWORD, _DWORD))v5->vfptr->action)(
        v5,
        3,
        v5->joinButton,
        1,
        0,
        0);
      return 1;
    }
    return 1;
  }
  if( fromPanel == (TPanel *)v5->joinButton )
  {
    if( actionIn == 1 )
    {
      if( v5->game_count <= 0 )
      {
        TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 9636, 0, 450, 100);
        result = 1;
      }
      else
      {
        v8 = TTextPanel::currentLineNumber((TTextPanel *)&v6->vfptr);
        v9 = TCommunications_Sessions::GetSessionGUID(Sess, v8);
        if( TCommunications_Handler::JoinMultiplayerGame(comm, v9) )
        {
          RGE_Base_Game::disable_input(rge_base_game);
          v5->waitingToStart = 1;
          v5->joinTime = debug_timeGetTime();
          result = 1;
        }
        else
        {
          TPanel::get_string(9635, temp, 256);
          v10 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
          sprintf(string, temp, v10);
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, string, 0, 450, 100);
          result = 1;
        }
      }
      return result;
    }
    return 1;
  }
  if( fromPanel != (TPanel *)v5->cancelButton )
  {
    if( fromPanel == (TPanel *)v5->createButton && actionIn == 1 )
    {
      v12 = (TribeMPCreateDialog *)operator new(0x4A4u);
      v15 = 1;
      if( v12 )
      {
        TribeMPCreateDialog::TribeMPCreateDialog(v12, (TPanel *)&v5->vfptr);
        return 1;
      }
      return 1;
    }
    if( fromPanel == (TPanel *)v5->refreshButton )
    {
      if( actionIn == 1 )
      {
        TribeJoinScreen::fillList(v5);
        return 1;
      }
      return 1;
    }
    if( fromPanel == (TPanel *)v5->close_button && actionIn == 1 )
    {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  }
  if( actionIn != 1 )
    return 1;
  RGE_Base_Game::disable_input(rge_base_game);
  TCommunications_Handler::UnlinkToLevel(comm, SINGLE_PLAYER);
  v11 = (TribeMPStartupScreen *)operator new(0x6A0u);
  v15 = 0;
  if( v11 )
    TribeMPStartupScreen::TribeMPStartupScreen(v11);
  v15 = -1;
  TPanelSystem::setCurrentPanel(&panel_system, aMpStartupScree, 0);
  TPanelSystem::destroyPanel(&panel_system, aJoinScreen);
  return 1;
}
