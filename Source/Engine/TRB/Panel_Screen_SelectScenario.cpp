
//----- (004B3C90) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::TribeSelectScenarioScreen(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1
  char *v2; // ebx@1
  TDrawArea *v3; // edi@3
  int v4; // eax@3
  TTextPanel **v5; // ebp@6
  int v6; // eax@10
  int v7; // ecx@10
  int v8; // edx@10
  TTextPanel **v9; // ebx@11
  TPanel **v10; // edi@14
  TPanel *v11; // edi@15
  int v12; // edi@15

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aSelectScenario);
  v1->vfptr = (TPanelVtbl *)&TribeSelectScenarioScreen::`vftable';
  TribeSelectScenarioScreen::init_vars(v1);
  v2 = info_file_name_in;
  if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
    v2 = aScr2;
  v3 = rge_base_game->draw_area;
  v4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ( TEasy_Panel::setup((TEasy_Panel *)&v1->vfptr, v3, 0, v2, (v4 != 0) + 50052, 1, 0, 0, 0, 0, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           9722,
           20,
           10,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      v5 = (TTextPanel **)&v1->scenarioList;
      v1->scenarioListX = 20;
      v1->scenarioListY = 70;
      v1->scenarioListWidth = 600;
      v1->scenarioListHeight = 263;
      if ( TEasy_Panel::create_list(
             (TEasy_Panel *)&v1->vfptr,
             (TPanel *)&v1->vfptr,
             &v1->scenarioList,
             20,
             70,
             600,
             263,
             11) )
      {
        TTextPanel::set_second_column_pos(*v5, (v1->scenarioListWidth - 60) * v1->pnl_wid / v1->ideal_width);
        (*(void (__stdcall **)(signed int))&(*v5)->vfptr[1].gap4[0])(9725);
        if ( TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->scenarioScrollbar, *v5, 20) )
        {
          TPanel::set_help_info((TPanel *)&v1->scenarioScrollbar->vfptr, -1, -1);
          if ( TEasy_Panel::create_text(
                 (TEasy_Panel *)&v1->vfptr,
                 (TPanel *)&v1->vfptr,
                 &v1->scenarioTitle,
                 9726,
                 v1->scenarioListX,
                 v1->scenarioListY - 20,
                 300,
                 20,
                 4,
                 0,
                 0,
                 0) )
          {
            if ( TEasy_Panel::create_text(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->scenarioPlayersTitle,
                   9727,
                   v1->scenarioListWidth + v1->scenarioListX - 220,
                   v1->scenarioListY - 20,
                   200,
                   20,
                   4,
                   0,
                   0,
                   0) )
            {
              TTextPanel::set_alignment(v1->scenarioPlayersTitle, AlignTop, AlignRight);
              v6 = v1->scenarioListX;
              v7 = v1->scenarioListHeight + v1->scenarioListY + 25;
              v8 = v1->scenarioListWidth;
              v1->missionTextY = v7;
              v1->missionTextX = v6;
              v1->missionTextWidth = v8;
              v1->missionTextHeight = 60;
              if ( TEasy_Panel::create_text(
                     (TEasy_Panel *)&v1->vfptr,
                     (TPanel *)&v1->vfptr,
                     &v1->missionTitle,
                     9728,
                     v6,
                     v7 - 20,
                     400,
                     20,
                     4,
                     0,
                     0,
                     0) )
              {
                v9 = &v1->missionText;
                if ( TEasy_Panel::create_text(
                       (TEasy_Panel *)&v1->vfptr,
                       (TPanel *)&v1->vfptr,
                       &v1->missionText,
                       message_in,
                       v1->missionTextX,
                       v1->missionTextY,
                       v1->missionTextWidth,
                       v1->missionTextHeight,
                       11,
                       0,
                       0,
                       1) )
                {
                  ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*v9)->vfptr[1].set_rect)(
                    3,
                    v1->bevel_color1,
                    v1->bevel_color2,
                    v1->bevel_color3,
                    v1->bevel_color4,
                    v1->bevel_color5,
                    v1->bevel_color6);
                  if ( TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->missionScrollbar, *v9, 20) )
                  {
                    TPanel::set_help_info((TPanel *)&v1->missionScrollbar->vfptr, 30002, -1);
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
                      TPanel::set_help_info((TPanel *)v1->okButton, 30001, -1);
                      v10 = (TPanel **)&v1->cancelButton;
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
                        TPanel::set_help_info(*v10, 30002, -1);
                        v11 = *v10;
                        v11[2].max_wid = 27;
                        v11[2].min_hgt = 0;
                        v12 = (int)&v1->close_button;
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
                          (*(void (__stdcall **)(signed int))(**(_DWORD **)v12 + 20))(1);
                          (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v12 + 24))(
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
                          TribeSelectScenarioScreen::fillScenarios(v1);
                          v1->scenariosLoaded = 1;
                          TribeSelectScenarioScreen::getSettings(v1);
                          TribeSelectScenarioScreen::fillMissionText(v1);
                          TribeSelectScenarioScreen::activatePanels(v1);
                          TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&(*v5)->vfptr);
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
// 573D50: using guessed type int (__thiscall *TribeSelectScenarioScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B4100) --------------------------------------------------------
TribeSelectScenarioScreen *__thiscall TribeSelectScenarioScreen::`scalar deleting destructor'(TribeSelectScenarioScreen *this, unsigned int __flags)
{
  TribeSelectScenarioScreen *v2; // esi@1

  v2 = this;
  TribeSelectScenarioScreen::~TribeSelectScenarioScreen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B4120) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::init_vars(TribeSelectScenarioScreen *this)
{
  this->last_scenario_line = -1;
  this->title = 0;
  this->scenarioTitle = 0;
  this->scenarioPlayersTitle = 0;
  this->scenarioList = 0;
  this->scenarioScrollbar = 0;
  this->scenarioCount = 0;
  this->scenarioMission = 0;
  this->scenarioFixed = 0;
  this->scenariosLoaded = 0;
  this->missionTitle = 0;
  this->missionText = 0;
  this->missionScrollbar = 0;
  this->okButton = 0;
  this->cancelButton = 0;
  this->close_button = 0;
}

//----- (004B4190) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::~TribeSelectScenarioScreen(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeSelectScenarioScreen::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->scenarioTitle);
  TPanel::delete_panel((TPanel **)&v1->scenarioPlayersTitle);
  TPanel::delete_panel((TPanel **)&v1->scenarioList);
  TPanel::delete_panel((TPanel **)&v1->scenarioScrollbar);
  TPanel::delete_panel((TPanel **)&v1->missionTitle);
  TPanel::delete_panel((TPanel **)&v1->missionText);
  TPanel::delete_panel((TPanel **)&v1->missionScrollbar);
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573D50: using guessed type int (__thiscall *TribeSelectScenarioScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B4280) --------------------------------------------------------
int __thiscall TribeSelectScenarioScreen::handle_idle(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1

  v1 = this;
  if ( !this->scenariosLoaded )
  {
    TribeSelectScenarioScreen::fillScenarios(this);
    TribeSelectScenarioScreen::fillMissionText(v1);
    v1->scenariosLoaded = 1;
    TribeSelectScenarioScreen::activatePanels(v1);
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->scenarioList->vfptr);
  }
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004B42E0) --------------------------------------------------------
int __thiscall TribeSelectScenarioScreen::action(TribeSelectScenarioScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeSelectScenarioScreen *v5; // esi@1
  TButtonPanel *v6; // edx@3
  TribeMPSetupScreen *v7; // eax@5
  TribeSPMenuScreen *v9; // eax@10

  v5 = this;
  if ( !fromPanel || !this->scenariosLoaded )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  v6 = this->okButton;
  if ( (TButtonPanel *)fromPanel == v6 && actionIn == 1 )
  {
    TPanel::set_curr_child((TPanel *)&this->vfptr, (TPanel *)&this->scenarioList->vfptr);
    TribeSelectScenarioScreen::sendSettings(v5);
    RGE_Base_Game::disable_input(rge_base_game);
    v7 = (TribeMPSetupScreen *)operator new(0x890u);
    if ( v7 )
      TribeMPSetupScreen::TribeMPSetupScreen(v7);
    TPanelSystem::setCurrentPanel(&panel_system, aMpSetupScreen, 0);
    TPanelSystem::destroyPanel(&panel_system, aSelectScenario);
    return 1;
  }
  if ( fromPanel != (TPanel *)this->cancelButton || actionIn != 1 )
  {
    if ( fromPanel == (TPanel *)this->close_button && actionIn == 1 )
    {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
    if ( fromPanel == (TPanel *)this->scenarioList )
    {
      if ( actionIn == 3 )
      {
        this->vfptr->action((TPanel *)this, (TPanel *)v6, 1, 0, 0);
        return 1;
      }
      if ( actionIn == 1 )
      {
        TribeSelectScenarioScreen::fillMissionText(this);
        TribeSelectScenarioScreen::activatePanels(v5);
        return 1;
      }
    }
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  TPanel::set_curr_child((TPanel *)&this->vfptr, (TPanel *)&this->scenarioList->vfptr);
  RGE_Base_Game::disable_input(rge_base_game);
  v9 = (TribeSPMenuScreen *)operator new(0x49Cu);
  if ( v9 )
    TribeSPMenuScreen::TribeSPMenuScreen(v9);
  TPanelSystem::setCurrentPanel(&panel_system, aSinglePlayerMe, 0);
  TPanelSystem::destroyPanel(&panel_system, aSelectScenario);
  return 1;
}

//----- (004B44F0) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::fillScenarios(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // ebp@1
  RGE_Scenario_File_Info *v2; // ebx@1
  const char *v3; // eax@2
  unsigned int v4; // kr04_4@3
  int v5; // ecx@3
  char **v6; // eax@4
  size_t v7; // ecx@4
  int *v8; // eax@4
  char **v9; // ecx@4
  int v10; // esi@6
  int v11; // eax@9
  RGE_Scenario_Header *v12; // ebx@9
  char *v13; // edx@10
  const char *v14; // edi@11
  signed int v15; // ebx@13
  int i; // [sp+10h] [bp-224h]@6
  RGE_Scenario_File_Info *scenario_info_file; // [sp+14h] [bp-220h]@1
  char player_str[20]; // [sp+18h] [bp-21Ch]@16
  char file_name[260]; // [sp+2Ch] [bp-208h]@3
  char scenario_file[260]; // [sp+130h] [bp-104h]@18

  v1 = this;
  v2 = rge_base_game->scenario_info;
  scenario_info_file = rge_base_game->scenario_info;
  RGE_Scenario_File_Info::reload_scenarios(scenario_info_file);
  TTextPanel::empty_list((TTextPanel *)&v1->scenarioList->vfptr);
  v1->scenarioList->sorted = 1;
  for ( v1->scenarioCount = 0; ; ++v1->scenarioCount )
  {
    v3 = RGE_Scenario_File_Info::get_scenario_name(v2, v1->scenarioCount);
    if ( !v3 )
      break;
    v4 = strlen(v3) + 1;
    strncpy(file_name, v3, v4 - 5);
    v5 = v1->scenarioCount;
    file_name[v4 - 5] = 0;
    TTextPanel::append_line((TTextPanel *)&v1->scenarioList->vfptr, file_name, v5);
  }
  v6 = (char **)calloc(v1->scenarioCount, 4u);
  v7 = v1->scenarioCount;
  v1->scenarioMission = v6;
  v8 = (int *)calloc(v7, 4u);
  v9 = v1->scenarioMission;
  v1->scenarioFixed = v8;
  if ( v9 )
  {
    if ( v8 )
    {
      v10 = 0;
      i = 0;
      if ( v1->scenarioCount > 0 )
      {
        while ( 1 )
        {
          v11 = TTextPanel::get_id((TTextPanel *)&v1->scenarioList->vfptr, v10);
          v12 = RGE_Scenario_File_Info::get_scenario_info(v2, v11);
          if ( v12 )
          {
            v1->scenarioMission[v10] = (char *)calloc(0x1000u, 1u);
            v13 = v1->scenarioMission[v10];
            if ( v13 )
            {
              v14 = v12->description;
              if ( v14 )
              {
                strcpy(v13, v14);
                v10 = i;
              }
            }
            v1->scenarioFixed[v10] = (int)v12[1].vfptr;
            v15 = v12[1].error_code;
            if ( v15 > 0 )
            {
              if ( v1->scenarioFixed[v10] || v15 < 3 )
                sprintf(player_str, aD_3, v15);
              else
                sprintf(player_str, aDD_0, 2, v15);
              strcpy(scenario_file, TTextPanel::get_text((TTextPanel *)&v1->scenarioList->vfptr, v10));
              TTextPanel::change_line((TTextPanel *)&v1->scenarioList->vfptr, i, scenario_file, player_str, 0);
              v10 = i;
            }
          }
          i = ++v10;
          if ( v10 >= v1->scenarioCount )
            break;
          v2 = scenario_info_file;
        }
      }
    }
  }
}

//----- (004B4720) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::fillMissionText(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1
  int v2; // edi@1

  v1 = this;
  (*(void (__stdcall **)(char *))&this->missionText->vfptr[1].gap4[4])(message_in);
  v2 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr);
  if ( v2 >= 0 )
    (*(void (__stdcall **)(_DWORD))&v1->missionText->vfptr[1].gap4[4])(v1->scenarioMission[v2]);
  v1->last_scenario_line = v2;
}

//----- (004B4770) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::getSettings(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1
  char *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@1

  v1 = this;
  this->last_scenario_line = -1;
  v2 = RGE_Base_Game::scenarioName(rge_base_game);
  v3 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr, v2);
  v4 = v3;
  if ( v3 == -1 )
  {
    TListPanel::scroll_cur_line(v1->scenarioList, 1, 0, 1);
  }
  else
  {
    TListPanel::scroll_cur_line(v1->scenarioList, 1, v3, 1);
    v1->last_scenario_line = v4 - 1;
  }
}

//----- (004B47D0) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::sendSettings(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1
  char *v2; // eax@1

  v1 = this;
  RGE_Base_Game::setScenarioGame(rge_base_game, 1);
  v2 = TTextPanel::get_text((TTextPanel *)&v1->scenarioList->vfptr);
  RGE_Base_Game::setScenarioName(rge_base_game, v2);
  TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, 0);
}

//----- (004B4810) --------------------------------------------------------
void __thiscall TribeSelectScenarioScreen::activatePanels(TribeSelectScenarioScreen *this)
{
  TribeSelectScenarioScreen *v1; // esi@1
  TPanel *v2; // eax@1
  TPanel *v3; // edx@1
  TPanelVtbl *v4; // eax@1
  TPanel *v5; // eax@1
  TPanel *tabList[4]; // [sp+8h] [bp-10h]@1

  v1 = this;
  (*(void (__stdcall **)(signed int))&this->missionTitle->vfptr->gap10[4])(1);
  (*(void (__stdcall **)(signed int))&v1->missionText->vfptr->gap10[4])(1);
  v2 = (TPanel *)&v1->scenarioList->vfptr;
  v3 = (TPanel *)v1->cancelButton;
  tabList[1] = (TPanel *)v1->okButton;
  tabList[0] = v2;
  v4 = v1->vfptr;
  tabList[2] = v3;
  v4->set_tab_order((TPanel *)v1, (TPanel *)tabList, (TPanel *)3);
  v5 = v1->curr_child;
  if ( !v5 || !v5->active )
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)v1->okButton);
}
