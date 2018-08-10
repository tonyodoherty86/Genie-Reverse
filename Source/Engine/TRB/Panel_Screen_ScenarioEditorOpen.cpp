
//----- (004B33D0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(TRIBE_Screen_Sed_Open *this)
{
  TRIBE_Screen_Sed_Open *v1; // ebp@1
  TTextPanel **v2; // ebx@1
  TEasy_Panel *from_panel; // ST3C_4@1
  TDrawArea *v4; // esi@1
  int v5; // eax@1
  TButtonPanel **v6; // esi@7
  TPanel **v7; // edi@8
  TPanel *v8; // eax@9
  TButtonPanel *v9; // eax@9
  TTextPanel *v10; // edx@11
  TButtonPanel *v11; // ecx@11
  TPanel *v12; // edx@11
  TPanel *tabList[4]; // [sp+14h] [bp-124h]@11
  TRIBE_Screen_Sed_Open *v14; // [sp+24h] [bp-114h]@1
  char info_file[260]; // [sp+28h] [bp-110h]@1
  int v16; // [sp+134h] [bp-4h]@1

  v1 = this;
  v14 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aScenarioEdit_2);
  v2 = (TTextPanel **)&v1->list;
  v16 = 0;
  v1->vfptr = (TPanelVtbl *)&TRIBE_Screen_Sed_Open::`vftable';
  v1->title = 0;
  v1->list = 0;
  v1->scrollbar = 0;
  v1->okButton = 0;
  v1->cancelButton = 0;
  v1->deleteButton = 0;
  from_panel = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
  strcpy(info_file, TEasy_Panel::get_info_file(from_panel));
  v4 = rge_base_game->draw_area;
  v5 = TEasy_Panel::get_info_id(from_panel);
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, v4, info_file, v5, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           9421,
           20,
           20,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      if ( TEasy_Panel::create_list((TEasy_Panel *)&v1->vfptr, (TPanel *)&v1->vfptr, &v1->list, 20, 70, 600, 340, 11) )
      {
        if ( TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->scrollbar, *v2, 20) )
        {
          if ( TEasy_Panel::create_button(
                 (TEasy_Panel *)&v1->vfptr,
                 (TPanel *)&v1->vfptr,
                 &v1->okButton,
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
            v6 = &v1->deleteButton;
            if ( TEasy_Panel::create_button(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->deleteButton,
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
              v7 = (TPanel **)&v1->cancelButton;
              if ( TEasy_Panel::create_button(
                     (TEasy_Panel *)&v1->vfptr,
                     (TPanel *)&v1->vfptr,
                     &v1->cancelButton,
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
                v8 = *v7;
                v8[2].max_wid = 27;
                v8[2].min_hgt = 0;
                v9 = *v6;
                *((_DWORD *)v9 + 167) = 0;
                *((_DWORD *)v9 + 166) = 46;
                TRIBE_Screen_Sed_Open::fillList(v1);
                if ( !*TTextPanel::currentLine(*v2) )
                {
                  TButtonPanel::set_disabled(v1->okButton, 1);
                  TButtonPanel::set_disabled(*v6, 1);
                }
                TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&(*v2)->vfptr);
                v10 = *v2;
                v11 = *v6;
                tabList[1] = (TPanel *)v1->okButton;
                tabList[0] = (TPanel *)v10;
                v12 = *v7;
                tabList[2] = (TPanel *)v11;
                tabList[3] = v12;
                TPanel::set_tab_order(tabList, 4);
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
// 573C28: using guessed type int (__thiscall *TRIBE_Screen_Sed_Open::`vftable')(void *Memory, unsigned int __flags);

//----- (004B3680) --------------------------------------------------------
TRIBE_Screen_Sed_Open *__thiscall TRIBE_Screen_Sed_Open::`vector deleting destructor'(TRIBE_Screen_Sed_Open *this, unsigned int __flags)
{
  TRIBE_Screen_Sed_Open *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B36A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed_Open::~TRIBE_Screen_Sed_Open(TRIBE_Screen_Sed_Open *this)
{
  TRIBE_Screen_Sed_Open *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Sed_Open::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->list);
  TPanel::delete_panel((TPanel **)&v1->scrollbar);
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TPanel::delete_panel((TPanel **)&v1->deleteButton);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573C28: using guessed type int (__thiscall *TRIBE_Screen_Sed_Open::`vftable')(void *Memory, unsigned int __flags);

//----- (004B3740) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed_Open::fillList(TRIBE_Screen_Sed_Open *this)
{
  TRIBE_Screen_Sed_Open *v1; // ebp@1
  __int32 v2; // ebx@1
  unsigned int v3; // kr04_4@2
  TTextPanel *v4; // ecx@2
  __int32 v5; // ebx@3
  unsigned int v6; // kr0C_4@4
  TTextPanel *v7; // ecx@4
  char file_name[260]; // [sp+10h] [bp-21Ch]@1
  _finddata_t fileInfo; // [sp+114h] [bp-118h]@1

  v1 = this;
  TTextPanel::empty_list((TTextPanel *)&this->list->vfptr);
  v1->list->sorted = 1;
  sprintf(file_name, aS_scn_1, rge_base_game->prog_info->scenario_dir);
  v2 = _findfirst(file_name, &fileInfo);
  if ( v2 != -1 )
  {
    do
    {
      v3 = strlen(fileInfo.name) + 1;
      strncpy(file_name, fileInfo.name, v3 - 5);
      v4 = (TTextPanel *)&v1->list->vfptr;
      file_name[v3 - 5] = 0;
      TTextPanel::append_line(v4, file_name, 0);
    }
    while ( _findnext(v2, &fileInfo) != -1 );
  }
  sprintf(file_name, aS_scx_1, rge_base_game->prog_info->scenario_dir);
  v5 = _findfirst(file_name, &fileInfo);
  if ( v5 != -1 )
  {
    do
    {
      v6 = strlen(fileInfo.name) + 1;
      strncpy(file_name, fileInfo.name, v6 - 5);
      v7 = (TTextPanel *)&v1->list->vfptr;
      file_name[v6 - 5] = 0;
      TTextPanel::append_line(v7, file_name, 0);
    }
    while ( _findnext(v5, &fileInfo) != -1 );
  }
}

//----- (004B38A0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed_Open::action(TRIBE_Screen_Sed_Open *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TRIBE_Screen_Sed_Open *v5; // esi@1
  char *v6; // edi@5
  char *v7; // eax@5
  char *v8; // edi@5
  char *v9; // eax@5
  int v10; // eax@5
  char *v12; // eax@10
  TTextPanel *v13; // ecx@11
  char *v14; // edi@17
  char *v15; // eax@17
  char *v16; // ST0C_4@18
  char *v17; // edi@19
  char *v18; // eax@19
  char *v19; // ST0C_4@20
  TRIBE_Screen_Sed_Menu *v20; // eax@27
  char *v21; // [sp-8h] [bp-458h]@26
  char str[256]; // [sp+14h] [bp-43Ch]@5
  char fileName[257]; // [sp+114h] [bp-33Ch]@17
  char text[556]; // [sp+218h] [bp-238h]@10
  int v25; // [sp+44Ch] [bp-4h]@27

  v5 = this;
  if ( fromPanel )
  {
    if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aCancelDialog) )
    {
      TPanelSystem::destroyPanel(&panel_system, aCancelDialog);
      if ( !actionIn )
      {
        v6 = rge_base_game->prog_info->scenario_dir;
        v7 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
        sprintf(str, aSS_scn, v6, v7);
        _unlink(str);
        v8 = rge_base_game->prog_info->scenario_dir;
        v9 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
        sprintf(str, aSS_scx, v8, v9);
        _unlink(str);
        v10 = TTextPanel::get_line((TTextPanel *)&v5->list->vfptr);
        TTextPanel::delete_line((TTextPanel *)&v5->list->vfptr, v10);
        if ( !*TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr) )
        {
          TButtonPanel::set_disabled(v5->okButton, 1);
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
      TPanel::get_string(9418, str, 256);
      v12 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
      sprintf(text, str, v12);
      TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v5->vfptr, text, aCancelDialog, 450, 100);
    }
    v13 = (TTextPanel *)&v5->list->vfptr;
    if ( (TTextPanel *)fromPanel == v13 )
    {
      if ( actionIn == 3 )
      {
        v5->vfptr->action((TPanel *)v5, (TPanel *)v5->okButton, 1, 0, 0);
        return 1;
      }
    }
    else if ( fromPanel == (TPanel *)v5->okButton )
    {
      if ( actionIn == 1 )
      {
        if ( TTextPanel::numberLines(v13) > 0 )
        {
          v14 = rge_base_game->prog_info->scenario_dir;
          v15 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
          sprintf(fileName, aSS_scn, v14, v15);
          if ( OpenFile(fileName, (LPOFSTRUCT)str, 0x4000u) == -1 )
          {
            v17 = rge_base_game->prog_info->scenario_dir;
            v18 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
            sprintf(fileName, aSS_scx, v17, v18);
            if ( OpenFile(fileName, (LPOFSTRUCT)str, 0x4000u) == -1 )
            {
              TEasy_Panel::popupOKDialog((TEasy_Panel *)&v5->vfptr, 9423, 0, 450, 100);
              return 1;
            }
            v19 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
            sprintf(fileName, aS_scx, v19);
          }
          else
          {
            v16 = TTextPanel::currentLine((TTextPanel *)&v5->list->vfptr);
            sprintf(fileName, aS_scn, v16);
          }
          TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game, fileName, 0);
          return 1;
        }
        return 1;
      }
    }
    else if ( fromPanel == (TPanel *)v5->cancelButton && actionIn == 1 )
    {
      if ( TPanelSystem::panel(&panel_system, aScenarioEdit_0) )
      {
        v21 = aScenarioEdit_0;
      }
      else
      {
        v20 = (TRIBE_Screen_Sed_Menu *)operator new(0x490u);
        v25 = 0;
        if ( v20 )
          TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(v20);
        v25 = -1;
        v21 = aScenarioEditor;
      }
      TPanelSystem::setCurrentPanel(&panel_system, v21, 0);
      TPanelSystem::destroyPanel(&panel_system, aScenarioEdit_2);
      return 1;
    }
  }
  return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
}
