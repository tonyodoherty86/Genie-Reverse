
//----- (0048F5D0) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  TTextPanel **v2; // ebx@1
  TTextPanel **v3; // ebp@1
  TPanel **v4; // edi@1
  char *v5; // eax@3
  TButtonPanel *v6; // eax@3
  TPanel *v7; // eax@3
  TTextPanel *v8; // ecx@3
  TPanel *v9; // edx@3
  TPanel *v10; // eax@3
  TTextPanel *v11; // ecx@3
  TPanel *v12; // edx@3
  TPanel *v13; // eax@3
  TPanel *tabList[8]; // [sp+14h] [bp-2Ch]@3
  int v15; // [sp+3Ch] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aCampaignEditor);
  v2 = (TTextPanel **)&v1->scenarios;
  v3 = (TTextPanel **)&v1->campaign_scenarios;
  v4 = (TPanel **)&v1->filename_drop;
  v15 = 0;
  v1->vfptr = (TPanelVtbl *)&TRIBE_Campaign_Editor_Screen::`vftable';
  v1->title = 0;
  v1->scenarios_title = 0;
  v1->scenarios = 0;
  v1->scenarios_bar = 0;
  v1->campaign_scenarios_title = 0;
  v1->campaign_scenarios = 0;
  v1->campaign_scenarios_bar = 0;
  v1->filename_title = 0;
  v1->filename = 0;
  v1->cancel_button = 0;
  v1->save_button = 0;
  v1->ok_button = 0;
  v1->campaign = 0;
  v1->filename_drop = 0;
  v1->add_button = 0;
  v1->remove_button = 0;
  v1->move_scenario_up_button = 0;
  v1->move_scenario_down_button = 0;
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, info_file_name, 50054, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->title,
      11201,
      10,
      10,
      620,
      50,
      1,
      3,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->filename_title,
      11202,
      20,
      40,
      260,
      20,
      4,
      0,
      0,
      0);
    TEasy_Panel::create_drop_down(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->filename_drop,
      380,
      200,
      20,
      60,
      380,
      30 * v1->ideal_height / v1->pnl_hgt,
      11);
    v5 = TPanel::get_string(11210);
    TEasy_Panel::create_edit(
      (TEasy_Panel *)&v1->vfptr,
      *v4,
      &v1->filename,
      v5,
      100,
      FormatFileNoExt,
      0,
      0,
      360,
      30,
      11,
      1,
      1);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->save_button,
      11204,
      0,
      420,
      60,
      200,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->add_button,
      11205,
      0,
      280,
      260,
      160,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->remove_button,
      11206,
      0,
      460,
      260,
      160,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->scenarios_title,
      11207,
      20,
      100,
      200,
      20,
      4,
      0,
      0,
      0);
    TEasy_Panel::create_list((TEasy_Panel *)&v1->vfptr, (TPanel *)&v1->vfptr, &v1->scenarios, 20, 120, 600, 130, 11);
    TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->scenarios_bar, *v2, 20);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->campaign_scenarios_title,
      11208,
      20,
      280,
      200,
      20,
      4,
      0,
      0,
      0);
    TEasy_Panel::create_list(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->campaign_scenarios,
      20,
      300,
      500,
      130,
      11);
    TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v1->vfptr, &v1->campaign_scenarios_bar, *v3, 20);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->ok_button,
      4001,
      0,
      20,
      445,
      280,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->cancel_button,
      4002,
      0,
      340,
      445,
      280,
      30,
      0,
      0,
      0);
    v6 = v1->cancel_button;
    *((_DWORD *)v6 + 166) = 27;
    *((_DWORD *)v6 + 167) = 0;
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->move_scenario_up_button,
      11221,
      0,
      530,
      300,
      90,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->move_scenario_down_button,
      11222,
      0,
      530,
      340,
      90,
      30,
      0,
      0,
      0);
    v7 = (TPanel *)v1->save_button;
    v8 = *v2;
    tabList[0] = *v4;
    v9 = (TPanel *)v1->add_button;
    tabList[1] = v7;
    v10 = (TPanel *)v1->remove_button;
    tabList[2] = (TPanel *)v8;
    v11 = *v3;
    tabList[3] = v9;
    tabList[4] = v10;
    v12 = (TPanel *)v1->ok_button;
    v13 = (TPanel *)v1->cancel_button;
    tabList[5] = (TPanel *)v11;
    tabList[6] = v12;
    tabList[7] = v13;
    TPanel::set_tab_order(tabList, 8);
    TPanel::set_curr_child(*v4, (TPanel *)&v1->filename->vfptr);
    TPanel::set_curr_child((TPanel *)&v1->vfptr, *v4);
    TRIBE_Campaign_Editor_Screen::fill_scenario_list(v1);
    TRIBE_Campaign_Editor_Screen::fill_campaign_drop(v1);
    TTextPanel::empty_list(*v3);
    TRIBE_Campaign_Editor_Screen::load_campaign(v1);
    v1->need_to_save = 0;
  }
  else
  {
    v1->error_code = 1;
  }
}
// 5722A8: using guessed type int (__thiscall *TRIBE_Campaign_Editor_Screen::`vftable')(void *Memory, unsigned int __flags);

//----- (0048FA20) --------------------------------------------------------
TRIBE_Campaign_Editor_Screen *__thiscall TRIBE_Campaign_Editor_Screen::`scalar deleting destructor'(TRIBE_Campaign_Editor_Screen *this, unsigned int __flags)
{
  TRIBE_Campaign_Editor_Screen *v2; // esi@1

  v2 = this;
  TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048FA40) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  TTextPanel *v2; // ecx@1
  TTextPanel *v3; // ecx@3
  TTextPanel *v4; // ecx@5
  TListPanel *v5; // ecx@7
  TScrollBarPanel *v6; // ecx@9
  TListPanel *v7; // ecx@11
  TScrollBarPanel *v8; // ecx@13
  TTextPanel *v9; // ecx@15
  TEditPanel *v10; // ecx@17
  TDropDownPanel *v11; // ecx@19
  TButtonPanel *v12; // ecx@21
  TButtonPanel *v13; // ecx@23
  TButtonPanel *v14; // ecx@25
  TButtonPanel *v15; // ecx@27
  TButtonPanel *v16; // ecx@29
  TButtonPanel *v17; // ecx@31
  TButtonPanel *v18; // ecx@33

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Campaign_Editor_Screen::`vftable';
  TPanelSystem::destroyPanel(&panel_system, aCancelDialog);
  TPanelSystem::destroyPanel(&panel_system, aLoadDialog);
  v2 = v1->title;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->scenarios_title;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->campaign_scenarios_title;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->scenarios;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  v6 = v1->scenarios_bar;
  if ( v6 )
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  v7 = v1->campaign_scenarios;
  if ( v7 )
    ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
  v8 = v1->campaign_scenarios_bar;
  if ( v8 )
    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
  v9 = v1->filename_title;
  if ( v9 )
    ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
  v10 = v1->filename;
  if ( v10 )
    ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
  v11 = v1->filename_drop;
  if ( v11 )
    ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
  v12 = v1->cancel_button;
  if ( v12 )
    (**(void (__stdcall ***)(_DWORD))v12)(1);
  v13 = v1->save_button;
  if ( v13 )
    (**(void (__stdcall ***)(_DWORD))v13)(1);
  v14 = v1->ok_button;
  if ( v14 )
    (**(void (__stdcall ***)(_DWORD))v14)(1);
  v15 = v1->add_button;
  if ( v15 )
    (**(void (__stdcall ***)(_DWORD))v15)(1);
  v16 = v1->remove_button;
  if ( v16 )
    (**(void (__stdcall ***)(_DWORD))v16)(1);
  v17 = v1->move_scenario_up_button;
  if ( v17 )
    (**(void (__stdcall ***)(_DWORD))v17)(1);
  v18 = v1->move_scenario_down_button;
  if ( v18 )
    (**(void (__stdcall ***)(_DWORD))v18)(1);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5722A8: using guessed type int (__thiscall *TRIBE_Campaign_Editor_Screen::`vftable')(void *Memory, unsigned int __flags);

//----- (0048FBC0) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::fill_campaign_drop(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // ebp@1
  __int32 v2; // ebx@1
  unsigned int v3; // kr04_4@2
  __int32 v4; // ebx@3
  unsigned int v5; // kr0C_4@4
  char file_name[256]; // [sp+10h] [bp-218h]@1
  _finddata_t file_info; // [sp+110h] [bp-118h]@1

  v1 = this;
  TDropDownPanel::set_sorted(this->filename_drop, 1);
  TDropDownPanel::empty_list(v1->filename_drop);
  sprintf(file_name, aS_cpn, rge_base_game->prog_info->campaign_dir);
  v2 = _findfirst(file_name, &file_info);
  if ( v2 != -1 )
  {
    do
    {
      v3 = strlen(file_info.name) + 1;
      strncpy(file_name, file_info.name, v3 - 5);
      file_name[v3 - 5] = 0;
      TDropDownPanel::append_line(v1->filename_drop, file_name, 0);
    }
    while ( _findnext(v2, &file_info) != -1 );
  }
  sprintf(file_name, aS_cpx, rge_base_game->prog_info->campaign_dir);
  v4 = _findfirst(file_name, &file_info);
  if ( v4 != -1 )
  {
    do
    {
      v5 = strlen(file_info.name) + 1;
      strncpy(file_name, file_info.name, v5 - 5);
      file_name[v5 - 5] = 0;
      TDropDownPanel::append_line(v1->filename_drop, file_name, 0);
    }
    while ( _findnext(v4, &file_info) != -1 );
  }
}

//----- (0048FD20) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::fill_scenario_list(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // ebp@1
  __int32 v2; // ebx@1
  unsigned int v3; // kr04_4@2
  TTextPanel *v4; // ecx@2
  __int32 v5; // ebx@3
  unsigned int v6; // kr0C_4@4
  TTextPanel *v7; // ecx@4
  char file_name[256]; // [sp+10h] [bp-218h]@1
  _finddata_t file_info; // [sp+110h] [bp-118h]@1

  v1 = this;
  this->scenarios->sorted = 1;
  TTextPanel::empty_list((TTextPanel *)&this->scenarios->vfptr);
  sprintf(file_name, aS_scn_1, rge_base_game->prog_info->scenario_dir);
  v2 = _findfirst(file_name, &file_info);
  if ( v2 != -1 )
  {
    do
    {
      v3 = strlen(file_info.name) + 1;
      strncpy(file_name, file_info.name, v3 - 5);
      v4 = (TTextPanel *)&v1->scenarios->vfptr;
      file_name[v3 - 5] = 0;
      TTextPanel::append_line(v4, file_name, 0);
    }
    while ( _findnext(v2, &file_info) != -1 );
  }
  sprintf(file_name, aS_scx_1, rge_base_game->prog_info->scenario_dir);
  v5 = _findfirst(file_name, &file_info);
  if ( v5 != -1 )
  {
    do
    {
      v6 = strlen(file_info.name) + 1;
      strncpy(file_name, file_info.name, v6 - 5);
      v7 = (TTextPanel *)&v1->scenarios->vfptr;
      file_name[v6 - 5] = 0;
      TTextPanel::append_line(v7, file_name, 0);
    }
    while ( _findnext(v5, &file_info) != -1 );
  }
}

//----- (0048FE80) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // edi@1
  int v2; // ebx@2
  int i; // esi@3
  char **scenario_names; // [sp+8h] [bp-4h]@2

  v1 = this;
  if ( this->campaign )
  {
    TTextPanel::empty_list((TTextPanel *)&this->campaign_scenarios->vfptr);
    v2 = RGE_Campaign::scenario_info(v1->campaign, &scenario_names);
    if ( scenario_names )
    {
      for ( i = 0; i < v2; ++i )
      {
        TTextPanel::append_line((TTextPanel *)&v1->campaign_scenarios->vfptr, scenario_names[i], 0);
        free(scenario_names[i]);
      }
      free(scenario_names);
    }
  }
}

//----- (0048FF00) --------------------------------------------------------
char __thiscall TRIBE_Campaign_Editor_Screen::check_lists(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  int v2; // ebx@1
  int v3; // edi@1
  char *v4; // eax@2
  int i; // edi@4
  char *v6; // eax@5
  int v7; // eax@5
  char result; // al@6

  v1 = this;
  v2 = TTextPanel::numberLines((TTextPanel *)&this->campaign_scenarios->vfptr);
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_4:
    for ( i = 0; i < v2; ++i )
    {
      v6 = TTextPanel::get_text((TTextPanel *)&v1->campaign_scenarios->vfptr, i);
      v7 = TTextPanel::get_line((TTextPanel *)&v1->scenarios->vfptr, v6);
      TTextPanel::delete_line((TTextPanel *)&v1->scenarios->vfptr, v7);
    }
    result = 1;
  }
  else
  {
    while ( 1 )
    {
      v4 = TTextPanel::get_text((TTextPanel *)&v1->campaign_scenarios->vfptr, v3);
      if ( TTextPanel::get_line((TTextPanel *)&v1->scenarios->vfptr, v4) == -1 )
        break;
      if ( ++v3 >= v2 )
        goto LABEL_4;
    }
    result = 0;
  }
  return result;
}

//----- (0048FF80) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::load_campaign(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  TEditPanel *v2; // ecx@1
  char *v3; // eax@1
  char *v4; // eax@2
  RGE_Campaign *v5; // eax@3
  RGE_Campaign *v6; // eax@4
  char v7; // al@6
  RGE_Campaign *v8; // edi@6
  char v9; // bl@6
  char *text; // [sp+10h] [bp-130h]@1
  char *text2; // [sp+14h] [bp-12Ch]@1
  RGE_Campaign *v12; // [sp+18h] [bp-128h]@3
  _finddata_t file_info; // [sp+1Ch] [bp-124h]@1
  int v14; // [sp+13Ch] [bp-4h]@3

  v1 = this;
  v2 = this->filename;
  text = 0;
  text2 = 0;
  v3 = TEditPanel::get_text(v2);
  addstring(&text, v3, a_cpn);
  addstring(&text2, rge_base_game->prog_info->campaign_dir, text);
  if ( _findfirst(text2, &file_info) == -1
    && (v4 = TEditPanel::get_text(v1->filename),
        addstring(&text, v4, a_cpx),
        addstring(&text2, rge_base_game->prog_info->campaign_dir, text),
        _findfirst(text2, &file_info) == -1) )
  {
    v9 = 0;
  }
  else
  {
    v5 = (RGE_Campaign *)operator new(0x20Cu);
    v12 = v5;
    v14 = 0;
    if ( v5 )
      RGE_Campaign::RGE_Campaign(v5, text);
    else
      v6 = 0;
    v14 = -1;
    v1->campaign = v6;
    TRIBE_Campaign_Editor_Screen::fill_scenario_list(v1);
    TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list(v1);
    v7 = TRIBE_Campaign_Editor_Screen::check_lists(v1);
    v8 = v1->campaign;
    v9 = v7;
    if ( v8 )
    {
      RGE_Campaign::~RGE_Campaign(v1->campaign);
      operator delete(v8);
    }
    v1->campaign = 0;
  }
  if ( !v9 )
    TTextPanel::empty_list((TTextPanel *)&v1->campaign_scenarios->vfptr);
  free(text);
  free(text2);
  v1->need_to_save = 0;
}

//----- (00490120) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::make_campaign(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // ebp@1
  int v2; // edi@1
  TEditPanel *v3; // ecx@1
  char *v4; // eax@1
  char *v5; // esi@1
  char v6; // al@2
  signed int v7; // eax@4
  signed int v8; // ebx@4
  char **v9; // eax@5
  char **v10; // esi@6
  char *v11; // eax@7
  char *v12; // eax@7
  char *v13; // eax@12
  RGE_Campaign *v14; // eax@13
  RGE_Campaign *v15; // esi@13
  void **v16; // esi@18
  char **scenarios_filenames; // [sp+10h] [bp-23Ch]@5
  char **scenarios_text; // [sp+14h] [bp-238h]@5
  char *campaign_filename; // [sp+18h] [bp-234h]@1
  char *text; // [sp+1Ch] [bp-230h]@1
  int v21; // [sp+20h] [bp-22Ch]@6
  char test[260]; // [sp+24h] [bp-228h]@7
  _finddata_t file_info; // [sp+128h] [bp-124h]@7
  int v24; // [sp+248h] [bp-4h]@12

  v1 = this;
  v2 = 0;
  v3 = this->filename;
  campaign_filename = 0;
  v4 = TEditPanel::get_text(v3);
  v5 = v4;
  text = v4;
  if ( !v4 )
  {
LABEL_23:
    v1->need_to_save = 0;
    return;
  }
  v6 = *v4;
  if ( *v5 && v6 != 32 )
  {
    addstring(&campaign_filename, v5, a_cpx);
    v7 = TTextPanel::numberLines((TTextPanel *)&v1->campaign_scenarios->vfptr);
    v8 = v7;
    if ( v7 <= 0 )
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 11211, 0, 450, 100);
    }
    else
    {
      scenarios_text = (char **)calloc(v7, 4u);
      v9 = (char **)calloc(v8, 4u);
      scenarios_filenames = v9;
      if ( v8 > 0 )
      {
        v10 = v9;
        v21 = (char *)scenarios_text - (char *)v9;
        do
        {
          v11 = TTextPanel::get_text((TTextPanel *)&v1->campaign_scenarios->vfptr, v2);
          getstring((char **)((char *)v10 + v21), v11);
          v12 = TTextPanel::get_text((TTextPanel *)&v1->campaign_scenarios->vfptr, v2);
          getstring(v10, v12);
          sprintf(test, aSS_scn, rge_base_game->prog_info->scenario_dir, *v10);
          if ( _findfirst(test, &file_info) == -1 )
            addstring(v10, *v10, a_scx);
          else
            addstring(v10, *v10, a_scn);
          ++v2;
          ++v10;
        }
        while ( v2 < v8 );
        v5 = text;
      }
      v13 = (char *)operator new(0x20Cu);
      text = v13;
      v24 = 0;
      if ( v13 )
      {
        RGE_Campaign::RGE_Campaign((RGE_Campaign *)v13, campaign_filename, v5, v8, scenarios_filenames, scenarios_text);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      v24 = -1;
      v1->campaign = v15;
      if ( v15 )
      {
        RGE_Campaign::~RGE_Campaign(v15);
        operator delete(v15);
      }
      v1->campaign = 0;
      if ( v8 > 0 )
      {
        v16 = (void **)scenarios_filenames;
        do
        {
          free(*(void **)((char *)v16 + (char *)scenarios_text - (char *)scenarios_filenames));
          free(*v16);
          ++v16;
          --v8;
        }
        while ( v8 );
      }
      free(scenarios_text);
      free(scenarios_filenames);
    }
    free(campaign_filename);
    TRIBE_Campaign_Editor_Screen::fill_campaign_drop(v1);
    RGE_Base_Game::find_campaigns(rge_base_game);
    goto LABEL_23;
  }
  TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 11212, 0, 450, 100);
}

//----- (00490380) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::add_scenario(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  char *v2; // eax@1
  char *v3; // edi@1
  int v4; // eax@3
  int v5; // eax@3
  __int16 v6; // ax@3

  v1 = this;
  v2 = TTextPanel::get_text((TTextPanel *)&this->scenarios->vfptr);
  v3 = v2;
  if ( v2 && *v2 )
  {
    TTextPanel::append_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v2, 0);
    v4 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v3);
    TTextPanel::set_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v4);
    v5 = TTextPanel::get_line((TTextPanel *)&v1->scenarios->vfptr);
    TTextPanel::delete_line((TTextPanel *)&v1->scenarios->vfptr, v5);
    v6 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
    TListPanel::scroll_cur_line(v1->campaign_scenarios, 1, v6, 1);
  }
  v1->need_to_save = 1;
}

//----- (00490400) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::remove_scenario(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  char *v2; // eax@1
  char *v3; // edi@1
  int v4; // eax@3
  int v5; // eax@3
  __int16 v6; // ax@3

  v1 = this;
  v2 = TTextPanel::get_text((TTextPanel *)&this->campaign_scenarios->vfptr);
  v3 = v2;
  if ( v2 && *v2 )
  {
    TTextPanel::append_line((TTextPanel *)&v1->scenarios->vfptr, v2, 0);
    v4 = TTextPanel::get_line((TTextPanel *)&v1->scenarios->vfptr, v3);
    TTextPanel::set_line((TTextPanel *)&v1->scenarios->vfptr, v4);
    v5 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
    TTextPanel::delete_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v5);
    v6 = TTextPanel::get_line((TTextPanel *)&v1->scenarios->vfptr);
    TListPanel::scroll_cur_line(v1->scenarios, 1, v6, 1);
  }
  v1->need_to_save = 1;
}

//----- (00490480) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::move_scenario_up(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  char *v2; // eax@2
  char *v3; // ST04_4@4
  int v4; // eax@4
  int v5; // eax@4
  int v6; // eax@4
  __int16 v7; // ax@4

  v1 = this;
  if ( TTextPanel::get_line((TTextPanel *)&this->campaign_scenarios->vfptr) > 0 )
  {
    v2 = TTextPanel::get_text((TTextPanel *)&v1->campaign_scenarios->vfptr);
    if ( v2 )
    {
      if ( *v2 )
      {
        v3 = v2;
        v4 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TTextPanel::insert_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v4 - 1, v3, 0);
        v5 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TTextPanel::delete_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v5 + 1);
        v6 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TTextPanel::set_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v6 - 1);
        v7 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TListPanel::scroll_cur_line(v1->campaign_scenarios, 1, v7, 1);
      }
    }
    v1->need_to_save = 1;
  }
}

//----- (00490520) --------------------------------------------------------
void __thiscall TRIBE_Campaign_Editor_Screen::move_scenario_down(TRIBE_Campaign_Editor_Screen *this)
{
  TRIBE_Campaign_Editor_Screen *v1; // esi@1
  int v2; // edi@1
  char *v3; // eax@2
  char *v4; // ST04_4@4
  int v5; // eax@4
  int v6; // eax@4
  int v7; // eax@4
  __int16 v8; // ax@4

  v1 = this;
  v2 = TTextPanel::numberLines((TTextPanel *)&this->campaign_scenarios->vfptr) - 1;
  if ( TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr) < v2 )
  {
    v3 = TTextPanel::get_text((TTextPanel *)&v1->campaign_scenarios->vfptr);
    if ( v3 )
    {
      if ( *v3 )
      {
        v4 = v3;
        v5 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TTextPanel::insert_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v5 + 2, v4, 0);
        v6 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TTextPanel::delete_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v6);
        v7 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TTextPanel::set_line((TTextPanel *)&v1->campaign_scenarios->vfptr, v7 + 1);
        v8 = TTextPanel::get_line((TTextPanel *)&v1->campaign_scenarios->vfptr);
        TListPanel::scroll_cur_line(v1->campaign_scenarios, 1, v8, 1);
      }
    }
    v1->need_to_save = 1;
  }
}

//----- (004905D0) --------------------------------------------------------
int __thiscall TRIBE_Campaign_Editor_Screen::action(TRIBE_Campaign_Editor_Screen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TRIBE_Campaign_Editor_Screen *v5; // edi@1
  TDropDownPanel *v6; // ecx@3
  char *v7; // eax@15
  char *v8; // eax@16
  char *v9; // eax@21
  TRIBE_Screen_Sed_Menu *v10; // eax@22
  char *v11; // eax@50
  char str[256]; // [sp+14h] [bp-238h]@15
  char text[300]; // [sp+114h] [bp-138h]@15
  int v15; // [sp+248h] [bp-4h]@22

  v5 = this;
  if ( !fromPanel )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, 0, actionIn, a1, a2);
  v6 = this->filename_drop;
  if ( (TDropDownPanel *)fromPanel == v6 && actionIn == 2 )
  {
    TPanel::set_curr_child((TPanel *)&v6->vfptr, (TPanel *)&v5->filename->vfptr);
    TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->filename_drop->vfptr);
  }
  if ( actionIn == 3 )
  {
    if ( fromPanel == (TPanel *)v5->scenarios )
    {
      TRIBE_Campaign_Editor_Screen::add_scenario(v5);
    }
    else if ( fromPanel == (TPanel *)v5->campaign_scenarios )
    {
      TRIBE_Campaign_Editor_Screen::remove_scenario(v5);
    }
  }
  if ( fromPanel == (TPanel *)v5->filename_drop && !actionIn )
  {
    if ( v5->need_to_save && TTextPanel::numberLines((TTextPanel *)&v5->campaign_scenarios->vfptr) > 0 )
    {
      TPanel::get_string(11209, str, 256);
      v7 = TEditPanel::get_text(v5->filename);
      sprintf(text, str, v7);
      TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)&v5->vfptr, text, aLoadDialog, 450, 100);
    }
    else
    {
      v8 = TDropDownPanel::get_text(v5->filename_drop);
      TEditPanel::set_text(v5->filename, v8);
      TRIBE_Campaign_Editor_Screen::load_campaign(v5);
    }
  }
  if ( actionIn == 1 )
  {
    if ( fromPanel == (TPanel *)v5->ok_button )
    {
      if ( !v5->need_to_save || TTextPanel::numberLines((TTextPanel *)&v5->campaign_scenarios->vfptr) <= 0 )
      {
        v10 = (TRIBE_Screen_Sed_Menu *)operator new(0x490u);
        v15 = 0;
        if ( v10 )
          goto LABEL_43;
        goto LABEL_44;
      }
      TPanel::get_string(11209, str, 256);
      v9 = TEditPanel::get_text(v5->filename);
      sprintf(text, str, v9);
      TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)&v5->vfptr, text, aCancelDialog, 450, 100);
    }
    else if ( fromPanel == (TPanel *)v5->save_button )
    {
      TRIBE_Campaign_Editor_Screen::make_campaign(v5);
    }
    else
    {
      if ( fromPanel == (TPanel *)v5->cancel_button )
      {
        v10 = (TRIBE_Screen_Sed_Menu *)operator new(0x490u);
        v15 = 1;
        goto LABEL_42;
      }
      if ( fromPanel == (TPanel *)v5->add_button )
      {
        TRIBE_Campaign_Editor_Screen::add_scenario(v5);
      }
      else if ( fromPanel == (TPanel *)v5->remove_button )
      {
        TRIBE_Campaign_Editor_Screen::remove_scenario(v5);
      }
      else if ( fromPanel == (TPanel *)v5->move_scenario_up_button )
      {
        TRIBE_Campaign_Editor_Screen::move_scenario_up(v5);
      }
      else if ( fromPanel == (TPanel *)v5->move_scenario_down_button )
      {
        TRIBE_Campaign_Editor_Screen::move_scenario_down(v5);
      }
    }
  }
  if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aCancelDialog) )
  {
    TPanelSystem::destroyPanel(&panel_system, aCancelDialog);
    if ( !actionIn )
    {
      TRIBE_Campaign_Editor_Screen::make_campaign(v5);
LABEL_41:
      v10 = (TRIBE_Screen_Sed_Menu *)operator new(0x490u);
      v15 = 2;
LABEL_42:
      if ( v10 )
LABEL_43:
        TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(v10);
LABEL_44:
      v15 = -1;
      TPanelSystem::setCurrentPanel(&panel_system, aScenarioEditor, 0);
      TPanelSystem::destroyPanel(&panel_system, aCampaignEditor);
      return 1;
    }
    if ( actionIn == 1 )
      goto LABEL_41;
    return 1;
  }
  if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aLoadDialog) )
  {
    TPanelSystem::destroyPanel(&panel_system, aLoadDialog);
    if ( actionIn )
    {
      if ( actionIn != 1 )
        return 1;
    }
    else
    {
      TRIBE_Campaign_Editor_Screen::make_campaign(v5);
    }
    v11 = TDropDownPanel::get_text(v5->filename_drop);
    TEditPanel::set_text(v5->filename, v11);
    TRIBE_Campaign_Editor_Screen::load_campaign(v5);
    return 1;
  }
  return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
}
