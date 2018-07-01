
//----- (0043F340) --------------------------------------------------------
void __thiscall TribeMenuDialog::TribeMenuDialog(TribeMenuDialog *this, TScreenPanel *parentPanel)
{
  TribeMenuDialog *v2; // esi@1
  int v3; // ebp@1
  int v4; // ST24_4@6
  char *v5; // ST20_4@6
  TDrawArea *v6; // eax@6
  signed int v7; // edi@7
  int v8; // ebp@8
  TButtonPanel **v9; // ST04_4@12
  int v10; // edi@12
  int v11; // ebp@13
  TButtonPanel **v12; // ST04_4@13
  int v13; // edi@13
  int v14; // ebp@14
  TButtonPanel **v15; // ST04_4@15
  int v16; // edi@15
  int v17; // ebp@16
  TButtonPanel **v18; // ST04_4@16
  int v19; // edi@16
  int v20; // ebp@17
  TButtonPanel **v21; // ST04_4@17
  TButtonPanel **v22; // ST04_4@19
  int v23; // edi@19
  int v24; // ebp@20
  TButtonPanel **v25; // ST04_4@20
  int v26; // edi@20
  int v27; // ebp@21
  TButtonPanel **v28; // ST04_4@21
  int v29; // edi@21
  TButtonPanel **v30; // ST04_4@22
  int v31; // edi@22
  int v32; // eax@23

  v2 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aMenuDialog);
  v2->vfptr = (TPanelVtbl *)&TribeMenuDialog::`vftable';
  memset(v2->button, 0, sizeof(v2->button));
  v3 = 300;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) && !LOBYTE(RGE_Base_Game::get_player(rge_base_game)->sound_driver) )
    v3 = 335;
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
    v3 += 105;
  v4 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parentPanel->vfptr);
  v5 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parentPanel->vfptr);
  v6 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
  if ( TDialogPanel::setup((TDialogPanel *)&v2->vfptr, v6, (TPanel *)&parentPanel->vfptr, 400, v3, v5, v4, 1) )
  {
    v7 = 1;
    if ( TEasy_Panel::create_button(
           (TEasy_Panel *)&v2->vfptr,
           (TPanel *)&v2->vfptr,
           v2->button,
           9273,
           0,
           20,
           15,
           360,
           30,
           0,
           0,
           4) )
    {
      v8 = 65;
      if ( RGE_Base_Game::multiplayerGame(rge_base_game)
        && !LOBYTE(RGE_Base_Game::get_player(rge_base_game)->sound_driver) )
      {
        v7 = 2;
        if ( !TEasy_Panel::create_button(
                (TEasy_Panel *)&v2->vfptr,
                (TPanel *)&v2->vfptr,
                &v2->button[1],
                9280,
                0,
                20,
                65,
                360,
                30,
                0,
                0,
                12) )
          return;
        v8 = 100;
      }
      v9 = &v2->button[v7];
      v10 = v7 + 1;
      if ( TEasy_Panel::create_button(
             (TEasy_Panel *)&v2->vfptr,
             (TPanel *)&v2->vfptr,
             v9,
             9271,
             0,
             20,
             v8,
             360,
             30,
             0,
             0,
             7) )
      {
        v11 = v8 + 35;
        v12 = &v2->button[v10];
        v13 = v10 + 1;
        if ( TEasy_Panel::create_button(
               (TEasy_Panel *)&v2->vfptr,
               (TPanel *)&v2->vfptr,
               v12,
               9278,
               0,
               20,
               v11,
               360,
               30,
               0,
               0,
               9) )
        {
          v14 = v11 + 35;
          if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
          {
            v15 = &v2->button[v13];
            v16 = v13 + 1;
            if ( !TEasy_Panel::create_button(
                    (TEasy_Panel *)&v2->vfptr,
                    (TPanel *)&v2->vfptr,
                    v15,
                    9272,
                    0,
                    20,
                    v14,
                    360,
                    30,
                    0,
                    0,
                    1) )
              return;
            v17 = v14 + 35;
            v18 = &v2->button[v16];
            v19 = v16 + 1;
            if ( !TEasy_Panel::create_button(
                    (TEasy_Panel *)&v2->vfptr,
                    (TPanel *)&v2->vfptr,
                    v18,
                    9276,
                    0,
                    20,
                    v17,
                    360,
                    30,
                    0,
                    0,
                    3) )
              return;
            v20 = v17 + 35;
            v21 = &v2->button[v19];
            v13 = v19 + 1;
            if ( !TEasy_Panel::create_button(
                    (TEasy_Panel *)&v2->vfptr,
                    (TPanel *)&v2->vfptr,
                    v21,
                    9279,
                    0,
                    20,
                    v20,
                    360,
                    30,
                    0,
                    0,
                    11) )
              return;
            v14 = v20 + 35;
          }
          v22 = &v2->button[v13];
          v23 = v13 + 1;
          if ( TEasy_Panel::create_button(
                 (TEasy_Panel *)&v2->vfptr,
                 (TPanel *)&v2->vfptr,
                 v22,
                 9274,
                 0,
                 20,
                 v14,
                 360,
                 30,
                 0,
                 0,
                 5) )
          {
            v24 = v14 + 35;
            v25 = &v2->button[v23];
            v26 = v23 + 1;
            if ( TEasy_Panel::create_button(
                   (TEasy_Panel *)&v2->vfptr,
                   (TPanel *)&v2->vfptr,
                   v25,
                   9205,
                   0,
                   20,
                   v24,
                   360,
                   30,
                   0,
                   0,
                   8) )
            {
              v27 = v24 + 35;
              v28 = &v2->button[v26];
              v29 = v26 + 1;
              if ( TEasy_Panel::create_button(
                     (TEasy_Panel *)&v2->vfptr,
                     (TPanel *)&v2->vfptr,
                     v28,
                     9209,
                     0,
                     20,
                     v27,
                     360,
                     30,
                     0,
                     0,
                     10) )
              {
                v30 = &v2->button[v29];
                v31 = v29 + 1;
                if ( TEasy_Panel::create_button(
                       (TEasy_Panel *)&v2->vfptr,
                       (TPanel *)&v2->vfptr,
                       v30,
                       9275,
                       0,
                       20,
                       v27 + 50,
                       360,
                       30,
                       0,
                       0,
                       6) )
                {
                  v32 = *(&v2->button_sound_id + v31);
                  *(_DWORD *)(v32 + 668) = 0;
                  *(_DWORD *)(v32 + 664) = 27;
                  TPanel::set_curr_child((TPanel *)&v2->vfptr, (TPanel *)v2->button[0]);
                  TPanel::set_tab_order((TPanel **)v2->button, v31);
                }
              }
            }
          }
        }
      }
    }
  }
}
// 56FC30: using guessed type int (__thiscall *TribeMenuDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043F690) --------------------------------------------------------
TribeMenuDialog *__thiscall TribeMenuDialog::`scalar deleting destructor'(TribeMenuDialog *this, unsigned int __flags)
{
  TribeMenuDialog *v2; // esi@1

  v2 = this;
  TribeMenuDialog::~TribeMenuDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043F6B0) --------------------------------------------------------
void __thiscall TribeMenuDialog::~TribeMenuDialog(TribeMenuDialog *this)
{
  TribeMenuDialog *v1; // edi@1
  TPanel **v2; // esi@1
  signed int v3; // ebx@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeMenuDialog::`vftable';
  v2 = (TPanel **)this->button;
  v3 = 11;
  do
  {
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56FC30: using guessed type int (__thiscall *TribeMenuDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043F720) --------------------------------------------------------
int __thiscall TribeMenuDialog::action(TribeMenuDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeSaveGameScreen *v5; // eax@4
  TribeSaveGameScreen *v7; // eax@8
  TEasy_Panel *v8; // esi@12
  TEasy_Panel *v9; // esi@19
  TScreenPanel *v10; // esi@21
  TribeConfigDialog *v11; // eax@21
  TribeAchievementsScreen *v12; // edi@24
  char *v13; // eax@25
  TScreenPanel *v14; // esi@28
  TribeAboutDialog *v15; // eax@28
  TEasy_Panel *v16; // esi@31
  TRIBE_Mission_Screen *v17; // eax@33
  TEasy_Panel *v18; // esi@42

  if ( !fromPanel || actionIn != 1 )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  if ( a1 == 1 )
  {
    v5 = (TribeSaveGameScreen *)operator new(0x6A4u);
    if ( v5 )
      TribeSaveGameScreen::TribeSaveGameScreen(v5, 0, 0, 0);
    TPanelSystem::setCurrentPanel(&panel_system, aSaveGameScreen, 0);
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    return 1;
  }
  if ( a1 == 2 )
  {
    v7 = (TribeSaveGameScreen *)operator new(0x6A4u);
    if ( v7 )
      TribeSaveGameScreen::TribeSaveGameScreen(v7, SaveScenario, 0, 0);
    TPanelSystem::setCurrentPanel(&panel_system, aSaveGameScreen, 0);
    return 1;
  }
  if ( a1 == 3 )
  {
    v8 = (TEasy_Panel *)this->parent_panel;
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    TEasy_Panel::popupYesNoDialog(v8, 3100, panel_title, 450, 100);
    return 1;
  }
  if ( a1 == 8 )
  {
    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
      RGE_Base_Game::set_paused(rge_base_game, 0, 0);
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    WinHelpA(rge_base_game->prog_window, szHelp, 3u, 0);
    return 1;
  }
  if ( a1 == 4 )
  {
    confirmed_close = 1;
    v9 = (TEasy_Panel *)this->parent_panel;
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    TEasy_Panel::popupYesNoDialog(v9, 3101, aQuitgamedialog, 450, 100);
    return 1;
  }
  if ( a1 == 5 )
  {
    v10 = (TScreenPanel *)this->parent_panel;
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    v11 = (TribeConfigDialog *)operator new(0x564u);
    if ( v11 )
    {
      TribeConfigDialog::TribeConfigDialog(v11, 0, v10);
      return 1;
    }
    return 1;
  }
  if ( a1 == 7 )
  {
    v12 = (TribeAchievementsScreen *)operator new(0x5F8u);
    if ( v12 )
    {
      v13 = TPanel::get_string(9886);
      TribeAchievementsScreen::TribeAchievementsScreen(v12, v13, 0);
    }
    TPanelSystem::setCurrentPanel(&panel_system, aAchievementsSc, 0);
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    return 1;
  }
  if ( a1 == 10 )
  {
    v14 = (TScreenPanel *)this->parent_panel;
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    v15 = (TribeAboutDialog *)operator new(0x4C4u);
    if ( v15 )
    {
      TribeAboutDialog::TribeAboutDialog(v15, (int)v15, v14);
      return 1;
    }
    return 1;
  }
  if ( a1 == 11 )
  {
    v16 = (TEasy_Panel *)this->parent_panel;
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    TEasy_Panel::popupYesNoDialog(v16, 3102, aRestartdialog, 450, 100);
    return 1;
  }
  if ( a1 == 9 )
  {
    v17 = (TRIBE_Mission_Screen *)operator new(0x49Cu);
    if ( v17 )
      TRIBE_Mission_Screen::TRIBE_Mission_Screen(v17, 0, 1, rge_base_game->world->scenario->mission_picture);
    TPanelSystem::setCurrentPanel(&panel_system, aMissionDialog, 0);
    TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
    return 1;
  }
  if ( a1 != 6 )
  {
    if ( a1 == 12 )
    {
      v18 = (TEasy_Panel *)this->parent_panel;
      TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
      TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
      TEasy_Panel::popupYesNoDialog(v18, 3103, aResigndialog, 450, 100);
      return 1;
    }
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
    RGE_Base_Game::set_paused(rge_base_game, 0, 0);
  TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
  TPanelSystem::destroyPanel(&panel_system, aMenuDialog);
  return 1;
}
// 86BACC: using guessed type int confirmed_close;
