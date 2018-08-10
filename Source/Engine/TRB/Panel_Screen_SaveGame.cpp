
//----- (004A71F0) --------------------------------------------------------
void __thiscall TribeSaveGameScreen::TribeSaveGameScreen(TribeSaveGameScreen *this, TribeSaveGameScreen::Mode m, char *file_name, int quit_after_save_in)
{
  TribeSaveGameScreen *v4; // ebp@1
  TEasy_Panel *from_panel; // ST40_4@4
  TDrawArea *v6; // esi@4
  int v7; // eax@4
  __int16 v8; // ax@8
  TPanel **v9; // esi@13
  TButtonPanel **v10; // ebx@14
  TPanel **v11; // edi@15
  TPanel *v12; // eax@16
  TButtonPanel *v13; // eax@16
  TPanel *v14; // eax@18
  TPanel *v15; // edx@18
  TButtonPanel *v16; // ecx@18
  TPanel *v17; // edx@18
  TPanel *tabList[5]; // [sp+14h] [bp-128h]@18
  TribeSaveGameScreen *v19; // [sp+28h] [bp-114h]@1
  char info_file[260]; // [sp+2Ch] [bp-110h]@4
  int v21; // [sp+138h] [bp-4h]@1

  v4 = this;
  v19 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aSaveGameScreen);
  v4->quit_after_save = quit_after_save_in;
  v21 = 0;
  v4->modeValue = m;
  v4->vfptr = (TPanelVtbl *)&TribeSaveGameScreen::`vftable';
  v4->title = 0;
  v4->input = 0;
  v4->list = 0;
  v4->scrollbar = 0;
  v4->okButton = 0;
  v4->cancelButton = 0;
  v4->deleteButton = 0;
  if ( !file_name && m == SaveGame )
    file_name = TRIBE_Game::get_save_game_name((TRIBE_Game *)rge_base_game);
  from_panel = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  strcpy(info_file, TEasy_Panel::get_popup_info_file(from_panel));
  v6 = rge_base_game->draw_area;
  v7 = TEasy_Panel::get_popup_info_id(from_panel);
  if ( TScreenPanel::setup((TScreenPanel *)&v4->vfptr, v6, info_file, v7, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v4->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v4->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v4->vfptr,
           (TPanel *)&v4->vfptr,
           &v4->title,
           (v4->modeValue != 0) + 9411,
           20,
           20,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      v8 = 122 - strlen(rge_base_game->work_dir) <= 0x50 ? 122 - strlen(rge_base_game->work_dir) : 80;
      if ( TEasy_Panel::create_edit(
             (TEasy_Panel *)&v4->vfptr,
             (TPanel *)&v4->vfptr,
             &v4->input,
             file_name,
             v8,
             FormatFileNoExt,
             20,
             70,
             600,
             23,
             11,
             1,
             1) )
      {
        TPanel::set_help_info((TPanel *)&v4->input->vfptr, 30320, -1);
        if ( TEasy_Panel::create_list((TEasy_Panel *)&v4->vfptr, (TPanel *)&v4->vfptr, &v4->list, 20, 110, 600, 300, 11) )
        {
          if ( TEasy_Panel::create_auto_scrollbar(
                 (TEasy_Panel *)&v4->vfptr,
                 &v4->scrollbar,
                 (TTextPanel *)&v4->list->vfptr,
                 20) )
          {
            TPanel::set_help_info((TPanel *)&v4->scrollbar->vfptr, 30321, -1);
            v9 = (TPanel **)&v4->okButton;
            if ( TEasy_Panel::create_button(
                   (TEasy_Panel *)&v4->vfptr,
                   (TPanel *)&v4->vfptr,
                   &v4->okButton,
                   4001,
                   0,
                   30,
                   440,
                   180,
                   30,
                   0,
                   0,
                   0) )
            {
              v10 = &v4->deleteButton;
              if ( TEasy_Panel::create_button(
                     (TEasy_Panel *)&v4->vfptr,
                     (TPanel *)&v4->vfptr,
                     &v4->deleteButton,
                     9417,
                     0,
                     230,
                     440,
                     180,
                     30,
                     0,
                     0,
                     0) )
              {
                v11 = (TPanel **)&v4->cancelButton;
                if ( TEasy_Panel::create_button(
                       (TEasy_Panel *)&v4->vfptr,
                       (TPanel *)&v4->vfptr,
                       &v4->cancelButton,
                       4002,
                       0,
                       430,
                       440,
                       180,
                       30,
                       0,
                       0,
                       0) )
                {
                  TPanel::set_help_info(*v9, 30001, -1);
                  TPanel::set_help_info(*v11, 30002, -1);
                  v12 = *v11;
                  v12[2].max_wid = 27;
                  v12[2].min_hgt = 0;
                  v13 = *v10;
                  *((_DWORD *)v13 + 167) = 0;
                  *((_DWORD *)v13 + 166) = 46;
                  TribeSaveGameScreen::fillList(v4);
                  if ( !*TTextPanel::currentLine((TTextPanel *)&v4->list->vfptr) )
                    TButtonPanel::set_disabled(*v10, 1);
                  TPanel::set_curr_child((TPanel *)&v4->vfptr, (TPanel *)&v4->input->vfptr);
                  v14 = *v9;
                  v15 = (TPanel *)&v4->list->vfptr;
                  tabList[0] = (TPanel *)&v4->input->vfptr;
                  v16 = *v10;
                  tabList[2] = v14;
                  tabList[1] = v15;
                  v17 = *v11;
                  tabList[3] = (TPanel *)v16;
                  tabList[4] = v17;
                  TPanel::set_tab_order(tabList, 5);
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
    v4->error_code = 1;
  }
}
// 573898: using guessed type int (__thiscall *TribeSaveGameScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004A75A0) --------------------------------------------------------
TribeSaveGameScreen *__thiscall TribeSaveGameScreen::`vector deleting destructor'(TribeSaveGameScreen *this, unsigned int __flags)
{
  TribeSaveGameScreen *v2; // esi@1

  v2 = this;
  TribeSaveGameScreen::~TribeSaveGameScreen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A75C0) --------------------------------------------------------
void __thiscall TribeSaveGameScreen::~TribeSaveGameScreen(TribeSaveGameScreen *this)
{
  TribeSaveGameScreen *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeSaveGameScreen::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->input);
  TPanel::delete_panel((TPanel **)&v1->list);
  TPanel::delete_panel((TPanel **)&v1->scrollbar);
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TPanel::delete_panel((TPanel **)&v1->deleteButton);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573898: using guessed type int (__thiscall *TribeSaveGameScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004A7670) --------------------------------------------------------
void __thiscall TribeSaveGameScreen::fillList(TribeSaveGameScreen *this)
{
  TribeSaveGameScreen *v1; // ebp@1
  __int32 v2; // eax@2
  __int32 v3; // ebx@4
  unsigned int v4; // kr04_4@5
  __int32 v5; // eax@7
  __int32 v6; // ebx@9
  unsigned int v7; // kr0C_4@10
  TTextPanel *v8; // ecx@10
  char file_name[260]; // [sp+10h] [bp-21Ch]@2
  _finddata_t fileInfo; // [sp+114h] [bp-118h]@2

  v1 = this;
  TTextPanel::empty_list((TTextPanel *)&this->list->vfptr);
  v1->list->sorted = 1;
  if ( v1->modeValue )
  {
    sprintf(file_name, aS_scn_1, rge_base_game->prog_info->scenario_dir);
    v2 = _findfirst(file_name, &fileInfo);
  }
  else
  {
    sprintf(file_name, aS_gam_1, rge_base_game->prog_info->save_dir);
    v2 = _findfirst(file_name, &fileInfo);
  }
  v3 = v2;
  if ( v2 != -1 )
  {
    do
    {
      v4 = strlen(fileInfo.name) + 1;
      strncpy(file_name, fileInfo.name, v4 - 5);
      file_name[v4 - 5] = 0;
      TTextPanel::append_line((TTextPanel *)&v1->list->vfptr, file_name, 0);
    }
    while ( _findnext(v3, &fileInfo) != -1 );
  }
  if ( v1->modeValue )
  {
    sprintf(file_name, aS_scx_1, rge_base_game->prog_info->scenario_dir);
    v5 = _findfirst(file_name, &fileInfo);
  }
  else
  {
    sprintf(file_name, aS_gmx_1, rge_base_game->prog_info->save_dir);
    v5 = _findfirst(file_name, &fileInfo);
  }
  v6 = v5;
  if ( v5 != -1 )
  {
    do
    {
      v7 = strlen(fileInfo.name) + 1;
      strncpy(file_name, fileInfo.name, v7 - 5);
      v8 = (TTextPanel *)&v1->list->vfptr;
      file_name[v7 - 5] = 0;
      TTextPanel::append_line(v8, file_name, 0);
    }
    while ( _findnext(v6, &fileInfo) != -1 );
  }
}

//----- (004A7850) --------------------------------------------------------
int __thiscall TribeSaveGameScreen::action(TribeSaveGameScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeSaveGameScreen *v5; // ebp@1
  char *v6; // esi@6
  char *v7; // ST0C_4@6
  char *v8; // esi@7
  char *v9; // ST0C_4@7
  RGE_Prog_Info *v10; // esi@8
  char *v11; // ST0C_4@9
  char *v12; // ST0C_4@10
  int v13; // eax@11
  char *v14; // eax@11
  int result; // eax@12
  char *v16; // eax@16
  TTextPanel *v17; // ecx@17
  char *v18; // eax@19
  TPanel *v19; // eax@22
  FILE *v20; // eax@33
  FILE *v21; // eax@39
  TribeSaveGameScreen::Mode v22; // eax@42
  TribeSaveGameScreen::Mode v23; // eax@68
  int v24; // [sp-4h] [bp-348h]@30
  int v25; // [sp-4h] [bp-348h]@35
  char exist_flag; // [sp+13h] [bp-331h]@30
  char tempFileName[260]; // [sp+14h] [bp-330h]@6
  char text[556]; // [sp+118h] [bp-22Ch]@16

  v5 = this;
  if ( !fromPanel )
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aCancelDialog) )
  {
    TPanelSystem::destroyPanel(&panel_system, aCancelDialog);
    if ( !actionIn )
    {
      if ( v5->modeValue )
      {
        v8 = rge_base_game->prog_info->scenario_dir;
        v9 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
        sprintf(tempFileName, aSS_scn, v8, v9);
      }
      else
      {
        v6 = rge_base_game->prog_info->save_dir;
        v7 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
        sprintf(tempFileName, aSS_gam, v6, v7);
      }
      _unlink(tempFileName);
      v10 = rge_base_game->prog_info;
      if ( v5->modeValue )
      {
        v12 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
        sprintf(tempFileName, aSS_scx, v10->scenario_dir, v12);
      }
      else
      {
        v11 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
        sprintf(tempFileName, aSS_gmx, v10->save_dir, v11);
      }
      _unlink(tempFileName);
      v13 = TTextPanel::get_line((TTextPanel *)&v5->list->vfptr);
      TTextPanel::delete_line((TTextPanel *)&v5->list->vfptr, v13);
      v14 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
      TEditPanel::set_text(v5->input, v14);
      if ( !*TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr) )
      {
        TButtonPanel::set_disabled(v5->deleteButton, 1);
        return 1;
      }
    }
    return 1;
  }
  if ( fromPanel == (TPanel *)v5->deleteButton
    && actionIn == 1
    && *TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr) )
  {
    TPanel::get_string(9418, tempFileName, 256);
    v16 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
    sprintf(text, tempFileName, v16);
    TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v5->vfptr, text, aCancelDialog, 450, 100);
  }
  v17 = (TTextPanel *)&v5->list->vfptr;
  if ( (TTextPanel *)fromPanel == v17 && actionIn == 1 )
  {
    v18 = TTextPanel::currentLine(v17);
    TEditPanel::set_text(v5->input, v18);
    return 1;
  }
  if ( fromPanel != (TPanel *)v5->okButton || actionIn != 1 )
  {
    v19 = (TPanel *)&v5->input->vfptr;
    if ( (fromPanel != v19 || actionIn) && ((TTextPanel *)fromPanel != v17 || actionIn != 3) )
    {
      if ( fromPanel == (TPanel *)v5->cancelButton && actionIn == 1 || fromPanel == v19 && actionIn == 1 )
      {
        if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
          RGE_Base_Game::set_paused(rge_base_game, 0, 0);
        if ( v5->modeValue == 2 )
          TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_0, 0);
        else
          TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
        TPanelSystem::destroyPanel(&panel_system, aSaveGameScreen);
        return 1;
      }
      if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aOkdialog) )
      {
        TPanelSystem::destroyPanel(&panel_system, aOkdialog);
        TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->input->vfptr);
        return 1;
      }
      if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aYesnodialog) )
      {
        if ( actionIn )
        {
          TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
          TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->input->vfptr);
        }
        else
        {
          TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
          v23 = v5->modeValue;
          if ( v23 )
          {
            if ( v23 == 1 )
            {
              TEditPanel::get_trimmed_str(v5->input, v5->fileNameNoExt, 260);
              sprintf(tempFileName, aSS_scn, rge_base_game->prog_info->scenario_dir, v5->fileNameNoExt);
              _unlink(tempFileName);
              if ( !TRIBE_Game::save_scenario((TRIBE_Game *)rge_base_game, v5->fileName) )
              {
                TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 2403, 0, 450, 100);
                return 1;
              }
            }
            else if ( v23 == 2 )
            {
              TEditPanel::get_trimmed_str(v5->input, v5->fileNameNoExt, 260);
              sprintf(tempFileName, aSS_scn, rge_base_game->prog_info->scenario_dir, v5->fileNameNoExt);
              _unlink(tempFileName);
              TribeSaveGameScreen::save_for_scenario_editor(v5);
              return 1;
            }
          }
          else
          {
            TEditPanel::get_trimmed_str(v5->input, v5->fileNameNoExt, 260);
            sprintf(tempFileName, aSS_gam, rge_base_game->prog_info->save_dir, v5->fileNameNoExt);
            _unlink(tempFileName);
            if ( !TRIBE_Game::save_game((TRIBE_Game *)rge_base_game, v5->fileName) )
            {
              TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 2402, 0, 450, 100);
              return 1;
            }
          }
        }
        return 1;
      }
      return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
    }
  }
  TEditPanel::get_trimmed_str(v5->input, v5->fileNameNoExt, 260);
  if ( strlen(v5->fileNameNoExt) != 0 )
  {
    exist_flag = 0;
    v24 = (int)v5->fileNameNoExt;
    if ( v5->modeValue )
    {
      sprintf(v5->fileName, aS_scn, v24);
      sprintf(tempFileName, aSS, rge_base_game->prog_info->scenario_dir, v5->fileName);
    }
    else
    {
      sprintf(v5->fileName, aS_gam, v24);
      sprintf(tempFileName, aSS, rge_base_game->prog_info->save_dir, v5->fileName);
    }
    v20 = fopen(tempFileName, aRb);
    if ( v20 )
    {
      exist_flag = 1;
      fclose(v20);
    }
    v25 = (int)v5->fileNameNoExt;
    if ( v5->modeValue )
    {
      sprintf(v5->fileName, aS_scx, v25);
      sprintf(tempFileName, aSS, rge_base_game->prog_info->scenario_dir, v5->fileName);
    }
    else
    {
      sprintf(v5->fileName, aS_gmx, v25);
      sprintf(tempFileName, aSS, rge_base_game->prog_info->save_dir, v5->fileName);
    }
    if ( exist_flag )
      goto LABEL_81;
    v21 = fopen(tempFileName, aRb);
    if ( v21 )
    {
      exist_flag = 1;
      fclose(v21);
    }
    if ( exist_flag )
    {
LABEL_81:
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v5->vfptr, 9416, 0, 450, 100);
      return 1;
    }
    v22 = v5->modeValue;
    if ( v22 )
    {
      if ( v22 == 1 )
      {
        if ( !TRIBE_Game::save_scenario((TRIBE_Game *)rge_base_game, v5->fileName) )
        {
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 2403, 0, 450, 100);
          return 1;
        }
      }
      else if ( v22 == 2 )
      {
        TribeSaveGameScreen::save_for_scenario_editor(v5);
        return 1;
      }
    }
    else if ( !TRIBE_Game::save_game((TRIBE_Game *)rge_base_game, v5->fileName) )
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 2402, 0, 450, 100);
      return 1;
    }
    return 1;
  }
  if ( v5->modeValue )
  {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 9415, 0, 450, 100);
    result = 1;
  }
  else
  {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 9414, 0, 450, 100);
    result = 1;
  }
  return result;
}

//----- (004A8060) --------------------------------------------------------
void __thiscall TribeSaveGameScreen::save_for_scenario_editor(TribeSaveGameScreen *this)
{
  TribeSaveGameScreen *v1; // edi@1
  TPanel *v2; // eax@3
  int v3; // edi@5
  int v4; // eax@6
  TRIBE_Screen_Sed_Open *v5; // eax@10
  char *v6; // [sp-8h] [bp-20h]@12

  v1 = this;
  TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1104, 0, -1);
  RGE_Scenario::Set_scenario_name(rge_base_game->world->scenario, v1->fileName);
  if ( !(unsigned __int8)((int (__stdcall *)(char *))rge_base_game->world->vfptr->save_scenario)(v1->fileName) )
  {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 2403, 0, 450, 100);
    return;
  }
  v2 = TPanelSystem::panel(&panel_system, aScenarioEdit_0);
  if ( v2 )
    v2[4].fill_in_background = 0;
  v3 = v1->quit_after_save;
  if ( v3 != 1 )
  {
    if ( v3 == 2 )
    {
      v5 = (TRIBE_Screen_Sed_Open *)operator new(0x490u);
      if ( v5 )
        TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(v5);
      v6 = aScenarioEdit_2;
    }
    else
    {
      if ( v3 == 3 )
      {
        TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game, 0, 0);
        goto LABEL_17;
      }
      v6 = aScenarioEdit_0;
    }
    TPanelSystem::setCurrentPanel(&panel_system, v6, 0);
    goto LABEL_17;
  }
  TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
  if ( !v4 )
  {
    RGE_Base_Game::close(rge_base_game);
    return;
  }
  TPanelSystem::destroyPanel(&panel_system, aScenarioEdit_0);
LABEL_17:
  TPanelSystem::destroyPanel(&panel_system, aStatusScreen);
  TPanelSystem::destroyPanel(&panel_system, aSaveGameScreen);
}
