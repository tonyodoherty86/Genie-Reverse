
//----- (004B69A0) --------------------------------------------------------
void __thiscall TribeSPMenuScreen::TribeSPMenuScreen(TribeSPMenuScreen *this)
{
  TribeSPMenuScreen *v1; // ebx@1
  TButtonPanel **v2; // esi@3
  int v3; // edi@4
  TButtonPanel **v4; // ebp@4
  int v5; // edi@7
  TButtonPanel *v6; // eax@8
  TPanel *tabList[6]; // [sp+38h] [bp-24h]@8
  int v8; // [sp+58h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aSinglePlayerMe);
  v1->vfptr = (TPanelVtbl *)&TribeSPMenuScreen::`vftable';
  v8 = 0;
  RGE_Base_Game::setSinglePlayerGame(rge_base_game, 1);
  RGE_Base_Game::setScenarioName(rge_base_game, message_in);
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, aScr2, 50052, 1) )
  {
    v2 = v1->button;
    memset(v1->button, 0, sizeof(v1->button));
    v1->close_button = 0;
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           9220,
           20,
           20,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      v3 = 118;
      v4 = v1->button;
      while ( TEasy_Panel::create_button(
                (TEasy_Panel *)&v1->vfptr,
                (TPanel *)&v1->vfptr,
                v4,
                message_in,
                0,
                170,
                v3,
                300,
                40,
                0,
                0,
                0) )
      {
        v3 += 50;
        ++v4;
        if ( v3 >= 418 )
        {
          v5 = (int)&v1->close_button;
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
            (*(void (__stdcall **)(signed int))(**(_DWORD **)v5 + 20))(1);
            (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v5 + 24))(
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
            TButtonPanel::set_text(*v2, 0, 9226);
            TButtonPanel::set_text(v1->button[1], 0, 9224);
            TButtonPanel::set_text(v1->button[2], 0, 9227);
            TButtonPanel::set_text(v1->button[3], 0, 9221);
            TButtonPanel::set_text(v1->button[4], 0, 9223);
            TButtonPanel::set_text(v1->button[5], 0, 9225);
            v6 = v1->button[5];
            *((_DWORD *)v6 + 166) = 27;
            *((_DWORD *)v6 + 167) = 0;
            TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)*v2);
            qmemcpy(tabList, v2, sizeof(tabList));
            TPanel::set_tab_order(tabList, 6);
          }
          return;
        }
      }
    }
  }
  else
  {
    v1->error_code = 1;
  }
}
// 573FA0: using guessed type int (__thiscall *TribeSPMenuScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B6BE0) --------------------------------------------------------
TribeSPMenuScreen *__thiscall TribeSPMenuScreen::`scalar deleting destructor'(TribeSPMenuScreen *this, unsigned int __flags)
{
  TribeSPMenuScreen *v2; // esi@1

  v2 = this;
  TribeSPMenuScreen::~TribeSPMenuScreen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B6C00) --------------------------------------------------------
void __thiscall TribeSPMenuScreen::~TribeSPMenuScreen(TribeSPMenuScreen *this)
{
  TribeSPMenuScreen *v1; // edi@1
  TPanel **v2; // esi@1
  signed int v3; // ebx@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeSPMenuScreen::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  v2 = (TPanel **)v1->button;
  v3 = 7;
  do
  {
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573FA0: using guessed type int (__thiscall *TribeSPMenuScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B6C90) --------------------------------------------------------
int __thiscall TribeSPMenuScreen::handle_idle(TribeSPMenuScreen *this)
{
  TribeSPMenuScreen *v1; // esi@1

  v1 = this;
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004B6CC0) --------------------------------------------------------
int __thiscall TribeSPMenuScreen::action(TribeSPMenuScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeSPMenuScreen *v5; // ebx@1
  TPanel *v6; // eax@4
  TPanel *v8; // eax@11
  TPanel *v9; // eax@15
  RGE_Game_Info *v10; // ecx@19
  int v11; // eax@19
  int v12; // edi@19
  int v13; // esi@20
  TRIBE_Screen_Name *v14; // eax@23
  TRIBE_Dialog_Name *v15; // eax@26
  TPanel *v16; // eax@29

  v5 = this;
  if ( !fromPanel || actionIn != 1 )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  if ( fromPanel == (TPanel *)this->button[0] )
  {
    RGE_Base_Game::setCampaignGame(rge_base_game, 0);
    RGE_Base_Game::setSavedGame(rge_base_game, 0);
    RGE_Base_Game::setScenarioGame(rge_base_game, 0);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game, 0);
    RGE_Base_Game::disable_input(rge_base_game);
    v6 = (TPanel *)operator new(0x890u);
    fromPanel = v6;
LABEL_7:
    if ( v6 )
      TribeMPSetupScreen::TribeMPSetupScreen((TribeMPSetupScreen *)v6);
    TPanelSystem::setCurrentPanel(&panel_system, aMpSetupScreen, 0);
    TPanelSystem::destroyPanel(&panel_system, aSinglePlayerMe);
    return 1;
  }
  if ( fromPanel == (TPanel *)this->button[2] )
  {
    RGE_Base_Game::setCampaignGame(rge_base_game, 0);
    RGE_Base_Game::setSavedGame(rge_base_game, 0);
    RGE_Base_Game::setScenarioGame(rge_base_game, 0);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, 1);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game, 0);
    RGE_Base_Game::disable_input(rge_base_game);
    v6 = (TPanel *)operator new(0x890u);
    fromPanel = v6;
    goto LABEL_7;
  }
  if ( fromPanel == (TPanel *)this->button[3] )
  {
    RGE_Base_Game::setCampaignGame(rge_base_game, 0);
    RGE_Base_Game::setSavedGame(rge_base_game, 0);
    RGE_Base_Game::setScenarioGame(rge_base_game, 1);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game, 0);
    RGE_Base_Game::disable_input(rge_base_game);
    v8 = (TPanel *)operator new(0x4D8u);
    fromPanel = v8;
    if ( v8 )
      TribeSelectScenarioScreen::TribeSelectScenarioScreen((TribeSelectScenarioScreen *)v8);
    TPanelSystem::setCurrentPanel(&panel_system, aSelectScenario, 0);
    TPanelSystem::destroyPanel(&panel_system, aSinglePlayerMe);
    return 1;
  }
  if ( fromPanel == (TPanel *)this->button[4] )
  {
    RGE_Base_Game::disable_input(rge_base_game);
    v9 = (TPanel *)operator new(0x494u);
    fromPanel = v9;
    if ( v9 )
      TribeLoadSavedGameScreen::TribeLoadSavedGameScreen((TribeLoadSavedGameScreen *)v9);
    TPanelSystem::setCurrentPanel(&panel_system, aLoadSavedGameS, 0);
    TPanelSystem::destroyPanel(&panel_system, aSinglePlayerMe);
    return 1;
  }
  if ( fromPanel == (TPanel *)this->button[1] )
  {
    RGE_Base_Game::disable_input(rge_base_game);
    v10 = rge_base_game->player_game_info;
    fromPanel = 0;
    v11 = RGE_Game_Info::get_people_list(v10, (char ***)&fromPanel, &actionIn);
    v12 = v11;
    if ( v11 > 0 )
    {
      v13 = 0;
      if ( v11 > 0 )
      {
        do
          free(*((void **)&fromPanel->vfptr + v13++));
        while ( v13 < v12 );
      }
      free(fromPanel);
      if ( v12 > 0 )
      {
        v14 = (TRIBE_Screen_Name *)operator new(0x4A0u);
        a2 = (unsigned int)v14;
        if ( v14 )
          TRIBE_Screen_Name::TRIBE_Screen_Name(v14);
        TPanelSystem::setCurrentPanel(&panel_system, aNameSelectionS, 0);
        TPanelSystem::destroyPanel(&panel_system, aSinglePlayerMe);
        return 1;
      }
    }
    v15 = (TRIBE_Dialog_Name *)operator new(0x4A4u);
    a2 = (unsigned int)v15;
    if ( v15 )
    {
      TRIBE_Dialog_Name::TRIBE_Dialog_Name(v15, (TScreenPanel *)&v5->vfptr);
      return 1;
    }
    return 1;
  }
  if ( fromPanel != (TPanel *)this->button[5] )
  {
    if ( fromPanel == (TPanel *)this->close_button )
    {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  RGE_Base_Game::disable_input(rge_base_game);
  v16 = (TPanel *)operator new(0x4B0u);
  fromPanel = v16;
  if ( v16 )
    TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu((TRIBE_Screen_Main_Menu *)v16);
  TPanelSystem::setCurrentPanel(&panel_system, aMainMenu, 0);
  TPanelSystem::destroyPanel(&panel_system, aSinglePlayerMe);
  return 1;
}
