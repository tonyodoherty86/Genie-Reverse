
//----- (004407A0) --------------------------------------------------------
void __thiscall TribeSendMessageDialog::TribeSendMessageDialog(TribeSendMessageDialog *this, TScreenPanel *parentPanel)
{
  TribeSendMessageDialog *v2; // esi@1
  int v3; // eax@1
  signed int v4; // ecx@1
  TButtonPanel **v5; // eax@3
  signed int v6; // ecx@3
  TShape *v7; // eax@5
  TShape *v8; // eax@6
  int v9; // ST28_4@9
  char *v10; // ST24_4@9
  TDrawArea *v11; // eax@9
  int v12; // edi@11
  int v13; // ebx@11
  int v14; // eax@12
  signed int v15; // edi@13
  int j; // ebp@15
  PLAYERHUMANITY v17; // eax@17
  char *v18; // eax@24
  TButtonPanel **v19; // edi@29
  int v20; // eax@30
  TButtonPanel *v21; // ecx@30
  TButtonPanel **v22; // edi@46
  signed int v23; // ebx@46
  TPanel **v24; // edi@48
  TPanel *v25; // edi@49
  TButtonPanel **button; // [sp+14h] [bp-8Ch]@11
  int i; // [sp+18h] [bp-88h]@11
  int humanity; // [sp+1Ch] [bp-84h]@15
  RGE_Game_World *world; // [sp+20h] [bp-80h]@11
  int id; // [sp+24h] [bp-7Ch]@12
  int v31; // [sp+28h] [bp-78h]@13
  char temp_str[100]; // [sp+30h] [bp-70h]@25
  int v33; // [sp+9Ch] [bp-4h]@1

  v2 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aSendMessageDia);
  v33 = 0;
  v2->vfptr = (TPanelVtbl *)&TribeSendMessageDialog::`vftable';
  v2->title = 0;
  v3 = (int)v2->playerCivilization;
  v4 = 8;
  do
  {
    *(_DWORD *)(v3 - 32) = 0;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 32) = 0;
    *(_DWORD *)(v3 + 120) = 0;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  v5 = v2->radioButton;
  v6 = 3;
  do
  {
    *(v5 - 4) = 0;
    *v5 = 0;
    ++v5;
    --v6;
  }
  while ( v6 );
  v2->chatInput = 0;
  v2->chatTitle = 0;
  v2->okButton = 0;
  v2->help_button = 0;
  v2->backgroundPics = 0;
  v7 = (TShape *)operator new(0x20u);
  LOBYTE(v33) = 1;
  if ( v7 )
    TShape::TShape(v7, aDlg_plbn_shp, 50746);
  else
    v8 = 0;
  LOBYTE(v33) = 0;
  v2->backgroundPics = v8;
  if ( v8 )
  {
    v9 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parentPanel->vfptr);
    v10 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parentPanel->vfptr);
    v11 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
    if ( TDialogPanel::setup((TDialogPanel *)&v2->vfptr, v11, (TPanel *)&parentPanel->vfptr, 520, 465, v10, v9, 1) )
    {
      if ( TEasy_Panel::create_text(
             (TEasy_Panel *)&v2->vfptr,
             (TPanel *)&v2->vfptr,
             &v2->title,
             9831,
             5,
             10,
             v2->pnl_wid - 40,
             30,
             1,
             1,
             1,
             0) )
      {
        v12 = 1;
        i = 1;
        v13 = 40;
        world = rge_base_game->world;
        button = v2->checkButton;
        do
        {
          v14 = RGE_Base_Game::playerID(rge_base_game, v12);
          id = v14;
          if ( v14 )
          {
            v15 = 0;
            v31 = v14;
            if ( world->players[v14]->game_status == 2 )
              goto LABEL_52;
            if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
            {
              humanity = 0;
              for ( j = 1; j <= RGE_Base_Game::numberPlayers(rge_base_game); ++j )
              {
                if ( RGE_Base_Game::playerID(rge_base_game, j) == id )
                {
                  v17 = TCommunications_Handler::GetPlayerHumanity(comm, j);
                  if ( v17 == 2 || v17 == 4 )
                    humanity = v17;
                }
              }
              if ( humanity != 2 && humanity != 4 )
LABEL_52:
                v15 = 1;
            }
            v18 = TCommunications_Handler::GetPlayerName(comm, i);
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v2->vfptr,
                    (TPanel *)&v2->vfptr,
                    (TTextPanel **)button - 16,
                    v18,
                    50,
                    v13,
                    190,
                    30,
                    v15 != 0 ? 8 : 11,
                    0,
                    1,
                    0) )
              return;
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
              105,
              world->players[v31]->master_player_id,
              0,
              temp_str,
              100);
            if ( !TEasy_Panel::create_text(
                    (TEasy_Panel *)&v2->vfptr,
                    (TPanel *)&v2->vfptr,
                    (TTextPanel **)button - 8,
                    temp_str,
                    260,
                    v13,
                    120,
                    30,
                    11,
                    0,
                    1,
                    0) )
              return;
            if ( i == TCommunications_Handler::WhoAmI(comm)
              || TCommunications_Handler::GetPlayerHumanity(comm, i) != 2
              && TCommunications_Handler::GetPlayerHumanity(comm, i) != 4 )
            {
              v19 = button;
            }
            else
            {
              v19 = button;
              if ( !TEasy_Panel::create_check_box(
                      (TEasy_Panel *)&v2->vfptr,
                      (TPanel *)&v2->vfptr,
                      button,
                      10,
                      v13,
                      30,
                      30,
                      0,
                      0) )
                return;
              TPanel::set_help_info((TPanel *)*button, 30335, -1);
              v20 = TChat::inChatGroup(chat, i);
              v21 = *button;
              if ( v20 )
                (*(void (__stdcall **)(signed int))(*(_DWORD *)v21 + 224))(1);
              else
                (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v21 + 224))(0);
            }
            v19[22] = (TButtonPanel *)i;
            button = v19 + 1;
            v12 = i;
            v13 += 30;
          }
          i = ++v12;
        }
        while ( v12 < 9 );
        if ( TEasy_Panel::create_text(
               (TEasy_Panel *)&v2->vfptr,
               (TPanel *)&v2->vfptr,
               &v2->chatTitle,
               9832,
               10,
               315,
               120,
               30,
               4,
               1,
               1,
               0) )
        {
          if ( TEasy_Panel::create_edit(
                 (TEasy_Panel *)&v2->vfptr,
                 (TPanel *)&v2->vfptr,
                 &v2->chatInput,
                 message_in,
                 65,
                 0,
                 130,
                 315,
                 380,
                 23,
                 11,
                 1,
                 0) )
          {
            TPanel::set_help_info((TPanel *)&v2->chatInput->vfptr, 30330, -1);
            if ( TEasy_Panel::create_radio_button(
                   (TEasy_Panel *)&v2->vfptr,
                   (TPanel *)&v2->vfptr,
                   v2->radioButton,
                   45,
                   350,
                   30,
                   30,
                   0,
                   0) )
            {
              if ( TEasy_Panel::create_radio_button(
                     (TEasy_Panel *)&v2->vfptr,
                     (TPanel *)&v2->vfptr,
                     &v2->radioButton[1],
                     275,
                     350,
                     30,
                     30,
                     0,
                     0) )
              {
                if ( TEasy_Panel::create_radio_button(
                       (TEasy_Panel *)&v2->vfptr,
                       (TPanel *)&v2->vfptr,
                       &v2->radioButton[2],
                       45,
                       385,
                       30,
                       30,
                       0,
                       0) )
                {
                  if ( TEasy_Panel::create_radio_button(
                         (TEasy_Panel *)&v2->vfptr,
                         (TPanel *)&v2->vfptr,
                         &v2->radioButton[3],
                         275,
                         385,
                         30,
                         30,
                         0,
                         0) )
                  {
                    if ( TEasy_Panel::create_text(
                           (TEasy_Panel *)&v2->vfptr,
                           (TPanel *)&v2->vfptr,
                           v2->radioTitle,
                           9833,
                           75,
                           350,
                           200,
                           30,
                           11,
                           0,
                           1,
                           0) )
                    {
                      TPanel::set_help_info((TPanel *)&v2->radioTitle[0]->vfptr, -1, -1);
                      if ( TEasy_Panel::create_text(
                             (TEasy_Panel *)&v2->vfptr,
                             (TPanel *)&v2->vfptr,
                             &v2->radioTitle[1],
                             9834,
                             305,
                             350,
                             200,
                             30,
                             11,
                             0,
                             1,
                             0) )
                      {
                        TPanel::set_help_info((TPanel *)&v2->radioTitle[1]->vfptr, -1, -1);
                        if ( TEasy_Panel::create_text(
                               (TEasy_Panel *)&v2->vfptr,
                               (TPanel *)&v2->vfptr,
                               &v2->radioTitle[2],
                               9835,
                               75,
                               385,
                               200,
                               30,
                               11,
                               0,
                               1,
                               0) )
                        {
                          TPanel::set_help_info((TPanel *)&v2->radioTitle[2]->vfptr, -1, -1);
                          if ( TEasy_Panel::create_text(
                                 (TEasy_Panel *)&v2->vfptr,
                                 (TPanel *)&v2->vfptr,
                                 &v2->radioTitle[3],
                                 9838,
                                 305,
                                 385,
                                 200,
                                 30,
                                 11,
                                 0,
                                 1,
                                 0) )
                          {
                            TPanel::set_help_info((TPanel *)&v2->radioTitle[3]->vfptr, -1, -1);
                            v22 = v2->radioButton;
                            v23 = 4;
                            do
                            {
                              TButtonPanel::set_radio_info(*v22, v2->radioButton, 4);
                              ++v22;
                              --v23;
                            }
                            while ( v23 );
                            (*(void (__stdcall **)(signed int))(*(_DWORD *)v2->radioButton[3] + 224))(1);
                            TPanel::set_help_info((TPanel *)v2->radioButton[0], 30331, -1);
                            TPanel::set_help_info((TPanel *)v2->radioButton[1], 30332, -1);
                            TPanel::set_help_info((TPanel *)v2->radioButton[2], 30333, -1);
                            TPanel::set_help_info((TPanel *)v2->radioButton[3], 30334, -1);
                            v24 = (TPanel **)&v2->okButton;
                            if ( TEasy_Panel::create_button(
                                   (TEasy_Panel *)&v2->vfptr,
                                   (TPanel *)&v2->vfptr,
                                   &v2->okButton,
                                   9836,
                                   0,
                                   100,
                                   425,
                                   300,
                                   30,
                                   0,
                                   0,
                                   0) )
                            {
                              TPanel::set_help_info(*v24, 30001, -1);
                              v25 = *v24;
                              v25[2].max_wid = 27;
                              v25[2].min_hgt = 0;
                              TPanel::set_curr_child((TPanel *)&v2->vfptr, (TPanel *)&v2->chatInput->vfptr);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
// 56FFC0: using guessed type int (__thiscall *TribeSendMessageDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (00440E00) --------------------------------------------------------
TribeSendMessageDialog *__thiscall TribeSendMessageDialog::`scalar deleting destructor'(TribeSendMessageDialog *this, unsigned int __flags)
{
  TribeSendMessageDialog *v2; // esi@1

  v2 = this;
  TribeSendMessageDialog::~TribeSendMessageDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00440E20) --------------------------------------------------------
void __thiscall TribeSendMessageDialog::~TribeSendMessageDialog(TribeSendMessageDialog *this)
{
  TribeSendMessageDialog *v1; // esi@1
  int v2; // edi@1
  signed int v3; // ebx@1
  TPanel **v4; // edi@3
  signed int v5; // ebx@3
  TShape *v6; // edi@5

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeSendMessageDialog::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  v2 = (int)v1->playerCivilization;
  v3 = 8;
  do
  {
    TPanel::delete_panel((TPanel **)(v2 - 32));
    TPanel::delete_panel((TPanel **)v2);
    TPanel::delete_panel((TPanel **)(v2 + 32));
    v2 += 4;
    --v3;
  }
  while ( v3 );
  v4 = (TPanel **)v1->radioButton;
  v5 = 4;
  do
  {
    TPanel::delete_panel(v4 - 4);
    TPanel::delete_panel(v4);
    ++v4;
    --v5;
  }
  while ( v5 );
  TPanel::delete_panel((TPanel **)&v1->chatInput);
  TPanel::delete_panel((TPanel **)&v1->chatTitle);
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->help_button);
  v6 = v1->backgroundPics;
  if ( v6 )
  {
    TShape::~TShape(v1->backgroundPics);
    operator delete(v6);
  }
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56FFC0: using guessed type int (__thiscall *TribeSendMessageDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (00440F20) --------------------------------------------------------
int __thiscall TribeSendMessageDialog::action(TribeSendMessageDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeSendMessageDialog *v5; // ebp@1
  TEditPanel *v6; // ecx@2
  TRIBE_Screen_Game *v7; // ebx@4
  TRIBE_Screen_Game *v9; // ebx@17
  int v10; // esi@29
  signed int v11; // ebx@38
  RGE_Player *v12; // edi@38
  int v13; // eax@40
  signed int v14; // ebx@47
  RGE_Player *v15; // edi@47
  int v16; // eax@49
  signed int v17; // edi@57
  TButtonPanel *v18; // et1@62
  char save_msg[66]; // [sp+10h] [bp-44h]@6

  v5 = this;
  if ( !fromPanel )
    return TPanel::action((TPanel *)&this->vfptr, 0, actionIn, a1, a2);
  v6 = this->chatInput;
  if ( (TEditPanel *)fromPanel == v6 )
  {
    if ( !actionIn )
    {
      v7 = (TRIBE_Screen_Game *)v5->parent_panel;
      if ( TEditPanel::currentLine(v6) && *TEditPanel::currentLine(v5->chatInput) )
        strcpy(save_msg, TEditPanel::currentLine(v5->chatInput));
      else
        save_msg[0] = 0;
      if ( save_msg[0] )
      {
        if ( !((int (__stdcall *)(_DWORD, char *))rge_base_game->vfptr->processCheatCode)(
                rge_base_game->world->curr_player,
                save_msg) )
        {
          if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
          {
            if ( rge_base_game->prog_mode != 5 )
            {
              TCommunications_Handler::SendGroupChatMsg(comm, save_msg);
              TDebuggingLog::Log(L, aSendChat_US, rge_base_game->world->world_time, save_msg);
            }
          }
          else
          {
            RGE_Base_Game::play_sound(rge_base_game, 2);
            TRIBE_Screen_Game::display_system_message(v7, save_msg);
          }
        }
        TEditPanel::set_text(v5->chatInput, message_in);
        return 1;
      }
    }
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->okButton )
  {
    if ( actionIn == 1 )
    {
      TribeSendMessageDialog::checkButtons(v5);
      v9 = (TRIBE_Screen_Game *)v5->parent_panel;
      if ( TEditPanel::currentLine(v5->chatInput) && *TEditPanel::currentLine(v5->chatInput) )
        strcpy(save_msg, TEditPanel::currentLine(v5->chatInput));
      else
        save_msg[0] = 0;
      TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
      TPanelSystem::destroyPanel(&panel_system, aSendMessageDia);
      if ( save_msg[0]
        && !((int (__stdcall *)(_DWORD, char *))rge_base_game->vfptr->processCheatCode)(
              rge_base_game->world->curr_player,
              save_msg) )
      {
        if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
        {
          RGE_Base_Game::play_sound(rge_base_game, 2);
          TRIBE_Screen_Game::display_system_message(v9, save_msg);
          return 1;
        }
        if ( rge_base_game->prog_mode != 5 )
        {
          TCommunications_Handler::SendGroupChatMsg(comm, save_msg);
          TDebuggingLog::Log(L, aSendChat_US, rge_base_game->world->world_time, save_msg);
          return 1;
        }
      }
      return 1;
    }
    goto LABEL_64;
  }
  if ( fromPanel == (TPanel *)v5->help_button )
  {
    TEasy_Panel::setup_popup_help((TEasy_Panel *)&v5->vfptr);
    return 1;
  }
  v10 = (int)v5->checkButton;
  if ( fromPanel == (TPanel *)v5->checkButton[0]
    || fromPanel == (TPanel *)v5->checkButton[1]
    || fromPanel == (TPanel *)v5->checkButton[2]
    || fromPanel == (TPanel *)v5->checkButton[3]
    || fromPanel == (TPanel *)v5->checkButton[4]
    || fromPanel == (TPanel *)v5->checkButton[5]
    || fromPanel == (TPanel *)v5->checkButton[6]
    || fromPanel == (TPanel *)v5->checkButton[7] )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5->radioButton[0] + 224))(0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5->radioButton[1] + 224))(0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5->radioButton[2] + 224))(0);
    (*(void (__stdcall **)(signed int))(*(_DWORD *)v5->radioButton[3] + 224))(1);
    goto LABEL_64;
  }
  if ( fromPanel == (TPanel *)v5->radioButton[0] )
  {
    v11 = 8;
    v12 = rge_base_game->world->players[rge_base_game->world->curr_player];
    do
    {
      if ( *(_DWORD *)v10 )
      {
        v13 = RGE_Base_Game::playerID(rge_base_game, *(_DWORD *)(v10 + 88));
        if ( v13 == v12->id || (*(int (__thiscall **)(RGE_Player *, int))&v12->vfptr->gap4[24])(v12, v13) )
          (*(void (__stdcall **)(signed int))(**(_DWORD **)v10 + 224))(1);
        else
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v10 + 224))(0);
      }
      v10 += 4;
      --v11;
    }
    while ( v11 );
    TribeSendMessageDialog::checkButtons(v5);
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->radioButton[1] )
  {
    v14 = 8;
    v15 = rge_base_game->world->players[rge_base_game->world->curr_player];
    do
    {
      if ( *(_DWORD *)v10 )
      {
        v16 = RGE_Base_Game::playerID(rge_base_game, *(_DWORD *)(v10 + 88));
        if ( v16 != v15->id && (*(int (__thiscall **)(RGE_Player *, int))&v15->vfptr->gap4[20])(v15, v16) )
          (*(void (__stdcall **)(signed int))(**(_DWORD **)v10 + 224))(1);
        else
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v10 + 224))(0);
      }
      v10 += 4;
      --v14;
    }
    while ( v14 );
    TribeSendMessageDialog::checkButtons(v5);
    return 1;
  }
  if ( fromPanel != (TPanel *)v5->radioButton[2] )
  {
    v18 = v5->radioButton[3];
    TribeSendMessageDialog::checkButtons(v5);
    return 1;
  }
  if ( actionIn != 1 )
  {
LABEL_64:
    TribeSendMessageDialog::checkButtons(v5);
    return 1;
  }
  v17 = 8;
  do
  {
    if ( *(_DWORD *)v10 )
      (*(void (__stdcall **)(signed int))(**(_DWORD **)v10 + 224))(1);
    v10 += 4;
    --v17;
  }
  while ( v17 );
  TribeSendMessageDialog::checkButtons(v5);
  return 1;
}

//----- (00441410) --------------------------------------------------------
void __thiscall TribeSendMessageDialog::checkButtons(TribeSendMessageDialog *this)
{
  int *v1; // esi@1
  signed int v2; // edi@1
  TButtonPanel *v3; // ecx@3

  v1 = this->commPlayers;
  v2 = 8;
  do
  {
    if ( *v1 )
    {
      v3 = (TButtonPanel *)*(v1 - 22);
      if ( v3 )
      {
        if ( TButtonPanel::get_state(v3) )
          TChat::setInChatGroup(chat, *v1, 1);
        else
          TChat::setInChatGroup(chat, *v1, 0);
      }
    }
    ++v1;
    --v2;
  }
  while ( v2 );
}

//----- (00441460) --------------------------------------------------------
void __thiscall TribeSendMessageDialog::draw(TribeSendMessageDialog *this)
{
  TribeSendMessageDialog *v1; // esi@1
  RGE_Game_World *v2; // ebx@2
  int v3; // edi@2
  int v4; // ebp@2
  int v5; // eax@3
  int v6; // edi@4
  RGE_Color_Table *v7; // eax@4
  int i; // [sp+4h] [bp-8h]@2
  TPanelVtbl *v9; // [sp+8h] [bp-4h]@2

  v1 = this;
  TEasy_Panel::draw((TEasy_Panel *)&this->vfptr);
  if ( v1->backgroundPics )
  {
    v2 = rge_base_game->world;
    v9 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    v3 = 1;
    v4 = 0;
    i = 1;
    do
    {
      v5 = RGE_Base_Game::playerID(rge_base_game, v3);
      if ( v5 )
      {
        v6 = v5;
        v7 = v2->players[v5]->color_table;
        if ( v7 )
        {
          ASMSet_Color_Xform(16 * (v7->id + 1));
          TShape::shape_draw(
            v1->backgroundPics,
            v1->render_area,
            v1->pnl_x + 50,
            v1->pnl_y + v4 + 40,
            0,
            1,
            v2->players[v6]->color_table->table);
        }
        v3 = i;
        v4 += 30;
      }
      i = ++v3;
    }
    while ( v3 < 9 );
    v9->draw_finish((TPanel *)v1);
  }
}

//----- (00441530) --------------------------------------------------------
void __thiscall TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(TribeSendQuickMessageDialog *this, TScreenPanel *parentPanel, TribeSendQuickMessageDialog::Mode m)
{
  TribeSendQuickMessageDialog *v3; // esi@1
  int v4; // ST28_4@1
  char *v5; // ST24_4@1
  TDrawArea *v6; // eax@1

  v3 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aSendQuickMessa);
  v3->modeValue = m;
  v3->vfptr = (TPanelVtbl *)&TribeSendQuickMessageDialog::`vftable';
  v4 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parentPanel->vfptr);
  v5 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parentPanel->vfptr);
  v6 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
  if ( TDialogPanel::setup((TDialogPanel *)&v3->vfptr, v6, (TPanel *)&parentPanel->vfptr, 540, 35, v5, v4, 1)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v3->vfptr,
         (TPanel *)&v3->vfptr,
         &v3->chatTitle,
         v3->modeValue != 0 ? 9837 : 9832,
         5,
         5,
         120,
         25,
         4,
         1,
         1,
         0) )
  {
    if ( TEasy_Panel::create_edit(
           (TEasy_Panel *)&v3->vfptr,
           (TPanel *)&v3->vfptr,
           &v3->chatInput,
           message_in,
           65,
           0,
           130,
           5,
           405,
           25,
           11,
           1,
           0) )
    {
      TPanel::set_curr_child((TPanel *)&v3->vfptr, (TPanel *)&v3->chatInput->vfptr);
    }
  }
}
// 5700F0: using guessed type int (__thiscall *TribeSendQuickMessageDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (00441630) --------------------------------------------------------
TribeSendQuickMessageDialog *__thiscall TribeSendQuickMessageDialog::`vector deleting destructor'(TribeSendQuickMessageDialog *this, unsigned int __flags)
{
  TribeSendQuickMessageDialog *v2; // esi@1

  v2 = this;
  TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00441650) --------------------------------------------------------
void __thiscall TribeSendQuickMessageDialog::~TribeSendQuickMessageDialog(TribeSendQuickMessageDialog *this)
{
  TribeSendQuickMessageDialog *v1; // esi@1
  TEditPanel *v2; // ecx@1
  TTextPanel *v3; // ecx@3

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeSendQuickMessageDialog::`vftable';
  v2 = this->chatInput;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->chatTitle;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 5700F0: using guessed type int (__thiscall *TribeSendQuickMessageDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (004416C0) --------------------------------------------------------
int __thiscall TribeSendQuickMessageDialog::action(TribeSendQuickMessageDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeSendQuickMessageDialog *v5; // esi@1
  TEditPanel *v6; // ecx@2
  TRIBE_Screen_Game *v7; // ebx@6
  char save_msg[66]; // [sp+Ch] [bp-44h]@6

  v5 = this;
  if ( fromPanel )
  {
    v6 = this->chatInput;
    if ( (TEditPanel *)fromPanel == v6 )
    {
      if ( !actionIn )
      {
        if ( TEditPanel::currentLine(v6) && *TEditPanel::currentLine(v5->chatInput) )
        {
          v7 = (TRIBE_Screen_Game *)v5->parent_panel;
          strcpy(save_msg, TEditPanel::currentLine(v5->chatInput));
          TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
          TPanelSystem::destroyPanel(&panel_system, aSendQuickMessa);
          if ( !((int (__stdcall *)(_DWORD, char *))rge_base_game->vfptr->processCheatCode)(
                  rge_base_game->world->curr_player,
                  save_msg) )
          {
            if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
            {
              RGE_Base_Game::play_sound(rge_base_game, 2);
              TRIBE_Screen_Game::display_system_message(v7, save_msg);
              return 1;
            }
            if ( rge_base_game->prog_mode != 5 )
            {
              TCommunications_Handler::SendGroupChatMsg(comm, save_msg);
              return 1;
            }
          }
          return 1;
        }
LABEL_12:
        TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
        TPanelSystem::destroyPanel(&panel_system, aSendQuickMessa);
        return 1;
      }
      if ( actionIn == 1 )
        goto LABEL_12;
    }
  }
  return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
}

//----- (00441840) --------------------------------------------------------
int __thiscall TribeSendQuickMessageDialog::handle_mouse_down(TribeSendQuickMessageDialog *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TribeSendQuickMessageDialog *v6; // esi@1
  TPanelVtbl *v7; // edi@1
  int result; // eax@2

  v6 = this;
  v7 = this->vfptr;
  if ( ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y) )
  {
    result = TEasy_Panel::handle_mouse_down((TEasy_Panel *)&v6->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
  }
  else
  {
    v7->action((TPanel *)v6, (TPanel *)v6->chatInput, 1, 0, 0);
    result = 1;
  }
  return result;
}
