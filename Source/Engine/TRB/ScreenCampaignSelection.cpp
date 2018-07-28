
//----- (004909D0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(TRIBE_Screen_Campaign_Selection *this)
{
  TRIBE_Screen_Campaign_Selection *v1; // esi@1
  TTextPanel **v2; // edi@4
  int v3; // eax@7
  TTextPanel **v4; // edi@7
  TDropDownPanel **v5; // edi@11
  int v6; // eax@12
  int v7; // eax@12
  TPanel **v8; // ebx@12
  TButtonPanel *v9; // ebp@14
  int v10; // ebp@14
  TDropDownPanel *v11; // edx@15
  TPanel *v12; // eax@15
  TPanel *v13; // ecx@15
  TPanel *v14; // eax@15
  TPanel *tabList[5]; // [sp+3Ch] [bp-20h]@15
  int v16; // [sp+58h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aCampaignSelect);
  v16 = 0;
  v1->vfptr = (TPanelVtbl *)&TRIBE_Screen_Campaign_Selection::`vftable';
  TRIBE_Screen_Campaign_Selection::init_vars(v1);
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, aScr2, 50052, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           11213,
           20,
           10,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      v2 = (TTextPanel **)&v1->campaignList;
      v1->campaignListX = 20;
      v1->campaignListY = 70;
      v1->campaignListWidth = 600;
      v1->campaignListHeight = 130;
      if ( TEasy_Panel::create_list(
             (TEasy_Panel *)&v1->vfptr,
             (TPanel *)&v1->vfptr,
             &v1->campaignList,
             20,
             70,
             600,
             130,
             11) )
      {
        if ( TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->campaignScrollbar, *v2, 20) )
        {
          if ( TEasy_Panel::create_text(
                 (TEasy_Panel *)&v1->vfptr,
                 (TPanel *)&v1->vfptr,
                 &v1->campaignTitle,
                 11214,
                 v1->campaignListX - 5,
                 v1->campaignListY - 20,
                 200,
                 20,
                 4,
                 0,
                 0,
                 0) )
          {
            (*(void (__stdcall **)(signed int))&(*v2)->vfptr[1].gap4[0])(11101);
            v3 = v1->campaignListHeight + v1->campaignListY + 30;
            v4 = (TTextPanel **)&v1->scenarioList;
            v1->scenarioListX = 20;
            v1->scenarioListY = v3;
            v1->scenarioListWidth = 600;
            v1->scenarioListHeight = 130;
            if ( TEasy_Panel::create_list(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->scenarioList,
                   20,
                   v3,
                   600,
                   130,
                   11) )
            {
              if ( TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->scenarioScrollbar, *v4, 20) )
              {
                if ( TEasy_Panel::create_text(
                       (TEasy_Panel *)&v1->vfptr,
                       (TPanel *)&v1->vfptr,
                       &v1->scenarioTitle,
                       9726,
                       v1->scenarioListX - 5,
                       v1->scenarioListY - 20,
                       200,
                       20,
                       4,
                       0,
                       0,
                       0) )
                {
                  (*v4)->sorted = 0;
                  if ( TEasy_Panel::create_text(
                         (TEasy_Panel *)&v1->vfptr,
                         (TPanel *)&v1->vfptr,
                         &v1->difficultyTitle,
                         11215,
                         15,
                         370,
                         200,
                         20,
                         4,
                         0,
                         0,
                         0) )
                  {
                    v5 = &v1->difficultyDrop;
                    if ( TEasy_Panel::create_drop_down(
                           (TEasy_Panel *)&v1->vfptr,
                           (TPanel *)&v1->vfptr,
                           &v1->difficultyDrop,
                           130,
                           100,
                           20,
                           390,
                           130,
                           24,
                           11) )
                    {
                      TDropDownPanel::empty_list(*v5);
                      TDropDownPanel::append_line(*v5, 11220, 4);
                      TDropDownPanel::append_line(*v5, 11219, 3);
                      TDropDownPanel::append_line(*v5, 11218, 2);
                      TDropDownPanel::append_line(*v5, 11217, 1);
                      TDropDownPanel::append_line(*v5, 11216, 0);
                      v6 = RGE_Base_Game::difficulty(rge_base_game);
                      v7 = TDropDownPanel::get_line(*v5, v6);
                      TDropDownPanel::set_line(*v5, v7);
                      v8 = (TPanel **)&v1->okButton;
                      if ( TEasy_Panel::create_button(
                             (TEasy_Panel *)&v1->vfptr,
                             (TPanel *)&v1->vfptr,
                             &v1->okButton,
                             4001,
                             0,
                             70,
                             440,
                             240,
                             30,
                             0,
                             0,
                             0) )
                      {
                        if ( TEasy_Panel::create_button(
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
                        {
                          v9 = v1->cancelButton;
                          *((_DWORD *)v9 + 166) = 27;
                          *((_DWORD *)v9 + 167) = 0;
                          v10 = (int)&v1->close_button;
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
                            (*(void (__stdcall **)(signed int))(**(_DWORD **)v10 + 20))(1);
                            (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v10 + 24))(
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
                            v11 = *v5;
                            v12 = (TPanel *)&v1->campaignList->vfptr;
                            tabList[1] = (TPanel *)&v1->scenarioList->vfptr;
                            v13 = (TPanel *)v1->cancelButton;
                            tabList[2] = (TPanel *)v11;
                            tabList[0] = v12;
                            v14 = *v8;
                            tabList[4] = v13;
                            tabList[3] = v14;
                            TPanel::set_tab_order(tabList, 5);
                            TPanel::set_curr_child((TPanel *)&v1->vfptr, *v8);
                            TRIBE_Screen_Campaign_Selection::fillCampaigns(v1);
                            TRIBE_Screen_Campaign_Selection::fillScenarios(v1);
                            TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->campaignList->vfptr);
                            v1->campaignsLoaded = 1;
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
  else
  {
    v1->error_code = 1;
  }
}
// 5723D0: using guessed type int (__thiscall *TRIBE_Screen_Campaign_Selection::`vftable')(void *Memory, unsigned int __flags);

//----- (00490E10) --------------------------------------------------------
TRIBE_Screen_Campaign_Selection *__thiscall TRIBE_Screen_Campaign_Selection::`vector deleting destructor'(TRIBE_Screen_Campaign_Selection *this, unsigned int __flags)
{
  TRIBE_Screen_Campaign_Selection *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00490E30) --------------------------------------------------------
void __thiscall TRIBE_Screen_Campaign_Selection::init_vars(TRIBE_Screen_Campaign_Selection *this)
{
  int v1; // eax@1

  this->title = 0;
  this->campaignTitle = 0;
  this->campaignList = 0;
  this->campaignScrollbar = 0;
  this->scenarioTitle = 0;
  this->scenarioList = 0;
  this->scenarioScrollbar = 0;
  this->difficultyTitle = 0;
  this->difficultyDrop = 0;
  this->okButton = 0;
  this->cancelButton = 0;
  this->close_button = 0;
  this->campaignsLoaded = 0;
  v1 = RGE_Base_Game::get_single_player_difficulty(rge_base_game);
  RGE_Base_Game::setDifficulty(rge_base_game, v1);
}

//----- (00490EA0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection(TRIBE_Screen_Campaign_Selection *this)
{
  TRIBE_Screen_Campaign_Selection *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Campaign_Selection::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->campaignTitle);
  TPanel::delete_panel((TPanel **)&v1->campaignList);
  TPanel::delete_panel((TPanel **)&v1->campaignScrollbar);
  TPanel::delete_panel((TPanel **)&v1->scenarioTitle);
  TPanel::delete_panel((TPanel **)&v1->scenarioList);
  TPanel::delete_panel((TPanel **)&v1->scenarioScrollbar);
  TPanel::delete_panel((TPanel **)&v1->difficultyTitle);
  TPanel::delete_panel((TPanel **)&v1->difficultyDrop);
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5723D0: using guessed type int (__thiscall *TRIBE_Screen_Campaign_Selection::`vftable')(void *Memory, unsigned int __flags);

//----- (00490F90) --------------------------------------------------------
int __thiscall TRIBE_Screen_Campaign_Selection::handle_idle(TRIBE_Screen_Campaign_Selection *this)
{
  TRIBE_Screen_Campaign_Selection *v1; // esi@1

  v1 = this;
  if ( this->campaignsLoaded
    || (TRIBE_Screen_Campaign_Selection::fillCampaigns(this),
        TRIBE_Screen_Campaign_Selection::fillScenarios(v1),
        TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->campaignList->vfptr),
        (v1->campaignsLoaded = 1) != 0) )
  {
    if ( !rge_base_game->input_enabled )
      RGE_Base_Game::enable_input(rge_base_game);
  }
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (00490FF0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Campaign_Selection::action(TRIBE_Screen_Campaign_Selection *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TRIBE_Screen_Campaign_Selection *v5; // esi@1
  TButtonPanel *v6; // edi@3
  TRIBE_Screen_Name *v8; // eax@8
  TListPanel *v9; // ecx@14
  RGE_Game_Info *v10; // edi@16
  int v11; // eax@16

  v5 = this;
  if ( !fromPanel || !this->campaignsLoaded )
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  v6 = this->okButton;
  if ( (TButtonPanel *)fromPanel == v6 && actionIn == 1 )
  {
    TRIBE_Screen_Campaign_Selection::startGame(this);
    return 1;
  }
  if ( fromPanel != (TPanel *)this->cancelButton || actionIn != 1 )
  {
    if ( fromPanel == (TPanel *)this->close_button && actionIn == 1 )
    {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
    v9 = this->campaignList;
    if ( (TListPanel *)fromPanel == v9 && actionIn == 1 )
    {
      v10 = rge_base_game->player_game_info;
      v11 = TTextPanel::get_id((TTextPanel *)&v9->vfptr);
      RGE_Game_Info::set_current_campaign(v10, v11);
      TRIBE_Screen_Campaign_Selection::fillScenarios(v5);
      return 1;
    }
    if ( fromPanel == (TPanel *)v5->scenarioList && actionIn == 3 )
    {
      v5->vfptr->action((TPanel *)v5, (TPanel *)v6, 1, 0, 0);
      return 1;
    }
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  }
  RGE_Base_Game::disable_input(rge_base_game);
  v8 = (TRIBE_Screen_Name *)operator new(0x4A0u);
  if ( v8 )
    TRIBE_Screen_Name::TRIBE_Screen_Name(v8);
  TPanelSystem::setCurrentPanel(&panel_system, aNameSelectionS, 0);
  TPanelSystem::destroyPanel(&panel_system, aCampaignSelect);
  return 1;
}

//----- (004911A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Campaign_Selection::fillCampaigns(TRIBE_Screen_Campaign_Selection *this)
{
  TRIBE_Screen_Campaign_Selection *v1; // ebx@1
  RGE_Game_Info *v2; // ecx@1
  int v3; // eax@1
  int v4; // edi@1
  int v5; // esi@2
  int v6; // eax@4
  int i; // esi@4
  RGE_Game_Info *v8; // esi@7
  int v9; // eax@7
  char **campaigns; // [sp+Ch] [bp-8h]@1
  int currentCampaign; // [sp+10h] [bp-4h]@1

  v1 = this;
  TTextPanel::empty_list((TTextPanel *)&this->campaignList->vfptr);
  v2 = rge_base_game->player_game_info;
  campaigns = 0;
  v3 = RGE_Game_Info::get_campaign_list(v2, &campaigns, &currentCampaign);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0;
    v1->campaignList->sorted = 1;
    if ( v3 > 0 )
    {
      do
      {
        TTextPanel::append_line((TTextPanel *)&v1->campaignList->vfptr, campaigns[v5], v5);
        ++v5;
      }
      while ( v5 < v4 );
    }
    v6 = TTextPanel::get_line((TTextPanel *)&v1->campaignList->vfptr, currentCampaign);
    TTextPanel::set_line((TTextPanel *)&v1->campaignList->vfptr, v6);
    for ( i = 0; i < v4; ++i )
      free(campaigns[i]);
    free(campaigns);
    if ( TTextPanel::get_line((TTextPanel *)&v1->campaignList->vfptr) != -1 )
    {
      v8 = rge_base_game->player_game_info;
      v9 = TTextPanel::get_id((TTextPanel *)&v1->campaignList->vfptr);
      RGE_Game_Info::set_current_campaign(v8, v9);
    }
  }
}

//----- (00491290) --------------------------------------------------------
void __thiscall TRIBE_Screen_Campaign_Selection::fillScenarios(TRIBE_Screen_Campaign_Selection *this)
{
  TRIBE_Screen_Campaign_Selection *v1; // ebx@1
  RGE_Game_Info *v2; // ecx@1
  int v3; // eax@1
  int v4; // edi@1
  int v5; // esi@2
  int v6; // eax@4
  int i; // esi@4
  char **scenarios; // [sp+8h] [bp-8h]@1
  int currentScenario; // [sp+Ch] [bp-4h]@1

  v1 = this;
  TTextPanel::empty_list((TTextPanel *)&this->scenarioList->vfptr);
  v2 = rge_base_game->player_game_info;
  scenarios = 0;
  v3 = RGE_Game_Info::get_scenario_list(v2, &scenarios, &currentScenario);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0;
    if ( v3 > 0 )
    {
      do
      {
        TTextPanel::append_line((TTextPanel *)&v1->scenarioList->vfptr, scenarios[v5], v5);
        ++v5;
      }
      while ( v5 < v4 );
    }
    v6 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr, currentScenario);
    TTextPanel::set_line((TTextPanel *)&v1->scenarioList->vfptr, v6);
    for ( i = 0; i < v4; ++i )
      free(scenarios[i]);
    free(scenarios);
    TListPanel::scroll_cur_line(v1->scenarioList, 7, 0, 1);
  }
}

//----- (00491350) --------------------------------------------------------
void __thiscall TRIBE_Screen_Campaign_Selection::startGame(TRIBE_Screen_Campaign_Selection *this)
{
  TRIBE_Screen_Campaign_Selection *v1; // edi@1
  RGE_Game_Info *v2; // esi@2
  int v3; // eax@2
  signed int v4; // esi@2
  int v5; // eax@2
  int v6; // eax@2
  int v7; // ebp@2
  RGE_Scenario *v8; // eax@2
  int v9; // edi@4
  int v10; // edi@13
  int v11; // eax@17
  int v12; // eax@17
  signed int v13; // eax@19
  int v14; // edi@20
  signed int v15; // eax@21
  int v16; // esi@22
  T_Scenario *scenario_info; // [sp+10h] [bp-Ch]@2
  int first_any_color; // [sp+14h] [bp-8h]@2
  TRIBE_Screen_Campaign_Selection *v19; // [sp+18h] [bp-4h]@1

  v1 = this;
  v19 = this;
  if ( TTextPanel::get_line((TTextPanel *)&this->scenarioList->vfptr) != -1 )
  {
    v2 = rge_base_game->player_game_info;
    v3 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr);
    RGE_Game_Info::set_current_scenario(v2, v3);
    RGE_Base_Game::setScenarioGame(rge_base_game, 1);
    RGE_Base_Game::setCampaignGame(rge_base_game, 1);
    v4 = 0;
    RGE_Base_Game::setSavedGame(rge_base_game, 0);
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game, 0, 0);
    v5 = TDropDownPanel::get_id(v1->difficultyDrop);
    RGE_Base_Game::setDifficulty(rge_base_game, v5);
    v6 = TDropDownPanel::get_id(v1->difficultyDrop);
    RGE_Base_Game::set_single_player_difficulty(rge_base_game, v6);
    TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, 0);
    TRIBE_Game::setQuickStartGame((TRIBE_Game *)rge_base_game, 0);
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
    v7 = -1;
    first_any_color = 0;
    v8 = RGE_Base_Game::get_scenario_info(rge_base_game, -1, v1, 0, 1);
    scenario_info = (T_Scenario *)v8;
    if ( v8 )
    {
      v9 = 0;
      while ( 1 )
      {
        if ( RGE_Scenario::Get_player_Active(v8, v9) )
        {
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v4, v9);
          TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v4, v9 + 1);
          RGE_Base_Game::setPlayerTeam(rge_base_game, v4++, 1);
          if ( v7 == -1 && RGE_Scenario::Get_player_Type((RGE_Scenario *)&scenario_info->vfptr, v9) == 1 )
          {
            v7 = v9;
            first_any_color = v9 + 1;
          }
        }
        if ( ++v9 >= 9 )
          break;
        v8 = (RGE_Scenario *)scenario_info;
      }
      ((void (__stdcall *)(signed int))scenario_info->vfptr->~RGE_Scenario)(1);
      if ( v4 )
      {
        RGE_Base_Game::setNumberPlayers(rge_base_game, v4);
        if ( v7 != -1 )
        {
          v10 = 1;
          if ( v4 > 1 )
          {
            while ( TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, v10) != v7 )
            {
              if ( ++v10 >= v4 )
                goto LABEL_18;
            }
            v11 = TRIBE_Game::scenarioPlayer((TRIBE_Game *)rge_base_game, 0);
            TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, v10, v11);
            v12 = TRIBE_Game::playerColor((TRIBE_Game *)rge_base_game, 0);
            TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, v10, v12);
          }
LABEL_18:
          TRIBE_Game::setScenarioPlayer((TRIBE_Game *)rge_base_game, 0, v7);
          TRIBE_Game::setPlayerColor((TRIBE_Game *)rge_base_game, 0, first_any_color);
        }
        TCommunications_Handler::SetPlayerHumanity(comm, 1u, ME_HUMAN);
        v13 = 1;
        if ( v4 > 1 )
        {
          do
          {
            v14 = v13 + 1;
            TCommunications_Handler::SetPlayerHumanity(comm, v13 + 1, ME_COMPUTER);
            v13 = v14;
          }
          while ( v14 < v4 );
        }
        v15 = v4;
        if ( v4 < 9 )
        {
          do
          {
            v16 = v15 + 1;
            TCommunications_Handler::SetPlayerHumanity(comm, v15 + 1, 0);
            v15 = v16;
          }
          while ( v16 < 9 );
        }
        if ( !TRIBE_Game::start_game((TRIBE_Game *)rge_base_game, 0) )
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v19->vfptr, 2401, 0, 450, 100);
      }
    }
    else
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 2506, 0, 450, 100);
    }
  }
}
