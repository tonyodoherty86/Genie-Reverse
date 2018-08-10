
//----- (004A81E0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::TRIBE_Screen_Sed(TRIBE_Screen_Sed *this, char *scenario_name_in, int is_multi_player_in)
{
  TRIBE_Screen_Sed *v3; // esi@1
  char *v4; // eax@3
  RGE_Main_View *v5; // eax@7
  RGE_Main_View *v6; // edi@7
  RGE_View *v7; // ecx@8
  RGE_Diamond_Map_View *v8; // eax@13
  RGE_Diamond_Map *v9; // eax@14
  RGE_Font *v10; // edi@19
  TMessagePanel *v11; // eax@19
  TMessagePanel *v12; // eax@20
  TPanel *v13; // eax@25
  TPanel *v14; // eax@26
  char v15; // cl@35
  int v16; // edi@35
  char *v17; // eax@35
  int v18; // edi@38
  char name[260]; // [sp+3Ch] [bp-214h]@36
  char temp_name[260]; // [sp+140h] [bp-110h]@3
  int v21; // [sp+24Ch] [bp-4h]@1

  v3 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aScenarioEdit_0);
  v21 = 0;
  v3->vfptr = (TPanelVtbl *)&TRIBE_Screen_Sed::`vftable';
  v3->is_multi_player = 0;
  v3->scenario_mode = 0;
  v3->map_type = 0;
  v3->mp_victory_type = 2;
  v3->brush_size = 0;
  v3->paint_type = 0;
  v3->player_num = 1;
  v3->message_type = 0;
  v3->SelectedObject = 0;
  v3->DestinationObject = 0;
  v3->CurrentPlayer = 0;
  v3->need_to_save_flag = 0;
  v3->valid_save_spot_flag = 0;
  TRIBE_Screen_Sed::init_module_variables(v3);
  v3->update_interval = 200;
  v3->last_update_time = debug_timeGetTime();
  v3->map_redraw_interval = 1000;
  v3->last_map_redraw_time = debug_timeGetTime();
  v3->save_text_color = 0;
  v3->save_window_color = 0;
  v3->changed_system_colors = 0;
  v3->CurrentVictory = 0;
  (*(void (__stdcall **)(signed int))&rge_base_game->vfptr->gap8[4])(7);
  if ( TRIBE_Screen_Sed::command_new_map(v3, scenario_name_in, is_multi_player_in, 0, 144, 144, 1) )
  {
    v4 = TRegistry::RegGetInt(rge_base_game->registry, 0, aGameFileNumber);
    sprintf(temp_name, aDefaultD_scx, v4);
    if ( scenario_name_in && !strcmp(scenario_name_in, temp_name) )
      v3->need_to_save_flag = 1;
    if ( TScreenPanel::setup((TScreenPanel *)&v3->vfptr, rge_base_game->draw_area, aScr5, 50055, 1)
      && ((TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v3->vfptr, 0),
           v5 = (RGE_Main_View *)operator new(0x380u),
           v6 = v5,
           LOBYTE(v21) = 1,
           !v5) ? (v7 = 0) : (RGE_Main_View::RGE_Main_View(v5),
                              v6->vfptr = (TPanelVtbl *)&TRIBE_Main_View::`vftable',
                              v7 = (RGE_View *)v6),
          (LOBYTE(v21) = 0, (v3->main_view = (TRIBE_Main_View *)v7) != 0)
       && !v7->error_code
       && RGE_View::setup(v7, v3->render_area, (TPanel *)&v3->vfptr, 0, 0, 0, 0, 161, 0, border_line_file)
       && ((v8 = (RGE_Diamond_Map_View *)operator new(0x16Cu), LOBYTE(v21) = 2, !v8) ? (v9 = 0) : RGE_Diamond_Map_View::RGE_Diamond_Map_View(v8),
           (LOBYTE(v21) = 0, (v3->map_view = (RGE_Diamond_Map_View *)v9) != 0)
        && !v9->error_code
        && RGE_Diamond_Map::setup(
             v9,
             v3->render_area,
             (TPanel *)&v3->vfptr,
             0,
             0,
             0,
             0,
             161,
             0,
             rge_base_game->map_save_area)
        && ((RGE_Diamond_Map::set_bitmap((RGE_Diamond_Map *)&v3->map_view->vfptr, aMap640_bmp, 50401),
             v3->map_view->main_view = (RGE_View *)&v3->main_view->vfptr,
             v3->main_view->map_view = (TPanel *)&v3->map_view->vfptr,
             TPanel::set_help_info((TPanel *)&v3->main_view->vfptr, -1, -1),
             v10 = RGE_Base_Game::get_font(rge_base_game, 11),
             v11 = (TMessagePanel *)operator new(0x380u),
             LOBYTE(v21) = 3,
             !v11) ? (v12 = 0) : TMessagePanel::TMessagePanel(v11, v10->font, v10->font_wid, v10->font_hgt),
            (LOBYTE(v21) = 0, (v3->message_panel = v12) != 0)
         && !v12->error_code
         && (*(int (__thiscall **)(TMessagePanel *, TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v12->vfptr->gap4[0])(
              v12,
              v3->render_area,
              v3->main_view,
              0,
              0,
              0,
              0,
              0)
         && ((v13 = (TPanel *)operator new(0xF4u), LOBYTE(v21) = 4, !v13) ? (v14 = 0) : TPanel::TPanel(v13),
             (LOBYTE(v21) = 0, (v3->bottom_panel = v14) != 0)
          && !v14->error_code
          && (*(int (__thiscall **)(TPanel *, TDrawArea *, TRIBE_Screen_Sed *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v14->vfptr->gap4[0])(
               v14,
               v3->render_area,
               v3,
               0,
               0,
               0,
               0,
               0))))) )
    {
      TRIBE_Screen_Sed::create_all_buttons_etc(v3);
      if ( scenario_name_in && *scenario_name_in )
      {
        if ( strstr(scenario_name_in, a_scn) || strstr(scenario_name_in, a_scn_1) )
        {
          v15 = *scenario_name_in;
          v16 = 0;
          v17 = scenario_name_in;
          do
          {
            v17[name - scenario_name_in] = v15;
            v15 = v17[1];
            ++v16;
            ++v17;
          }
          while ( v15 != 46 );
          name[v16] = 0;
          sprintf(scenario_name_in, aS_scx, name);
          RGE_Scenario::Set_scenario_name(v3->world->scenario, scenario_name_in);
        }
        v18 = 0;
        do
        {
          if ( !RGE_Scenario::Get_player_Active(v3->world->scenario, v18) )
            break;
          ++v18;
        }
        while ( v18 < 8 );
        v10 = (RGE_Font *)(v18 - 1);
        TDropDownPanel::set_line(v3->player_number_list, (int)v10);
      }
      else
      {
        TRIBE_Screen_Sed::set_player_active(v3, 0, 1);
        TRIBE_Screen_Sed::set_player_active(v3, 1, 1);
        TDropDownPanel::set_line(v3->player_number_list, 1);
      }
      TRIBE_Screen_Sed::SavePlayerActiveStatus(v3);
      TPanel::set_curr_child((TPanel *)&v3->vfptr, v3->bottom_panel);
      TRIBE_Screen_Sed::position_panels(v3, 0, (int)scenario_name_in, (int)v10);
      TRIBE_Screen_Sed::set_panel_info(v3);
      TRIBE_Screen_Sed::set_map_type(v3, MapTypeBlank, 0);
      TRIBE_Screen_Sed::set_mp_victory_type(v3, VictoryTypeStandard, 0);
      TRIBE_Screen_Sed::set_brush_size(v3, BrushSizeVerySmall);
      TRIBE_Screen_Sed::set_paint_type(v3, PaintTypeTerrain, 0);
      TRIBE_Screen_Sed::set_player(v3, 1, 0, 0);
      TRIBE_Screen_Sed::set_unit_player(v3, 1);
      TRIBE_Screen_Sed::set_message_type(v3, MessageTypeDescription, 0);
      TRIBE_Screen_Sed::set_scenario_mode(v3, ScenarioModeMap);
      TRIBE_Screen_Sed::set_unit(v3, -1);
      RGE_Map::set_map_visible(v3->world->map, 1);
      RGE_Map::set_map_fog(v3->world->map, 0);
    }
    else
    {
      v3->error_code = 1;
    }
  }
  else
  {
    v3->error_code = 1;
  }
}
// 572AA8: using guessed type int (__thiscall *TRIBE_Main_View::`vftable')(void *Memory, unsigned int __flags);
// 5739C0: using guessed type int (__thiscall *TRIBE_Screen_Sed::`vftable')(void *Memory, unsigned int __flags);

//----- (004A8750) --------------------------------------------------------
TRIBE_Screen_Sed *__thiscall TRIBE_Screen_Sed::`scalar deleting destructor'(TRIBE_Screen_Sed *this, unsigned int __flags)
{
  TRIBE_Screen_Sed *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Sed::~TRIBE_Screen_Sed(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A8770) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_panel_info(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  RGE_Player *v2; // eax@1
  RGE_Player *v3; // eax@1

  v1 = this;
  RGE_View::set_world((RGE_View *)&this->main_view->vfptr, (RGE_Game_World *)&this->world->vfptr);
  v2 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_View::set_player((RGE_View *)&v1->main_view->vfptr, v2);
  RGE_Diamond_Map::set_world((RGE_Diamond_Map *)&v1->map_view->vfptr, (RGE_Game_World *)&v1->world->vfptr);
  v3 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_Diamond_Map::set_player((RGE_Diamond_Map *)&v1->map_view->vfptr, v3);
}

//----- (004A87D0) --------------------------------------------------------
void __stdcall TRIBE_Screen_Sed::set_string(char *text, int text_id, int max_size)
{
  TPanel::get_string(text_id, text, max_size);
}

//----- (004A87F0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_button(TRIBE_Screen_Sed *this, TPanel *parent, TButtonPanel **button, int text_id, int ButtonSelectFlag)
{
  TRIBE_Screen_Sed *v5; // esi@1
  char str1[120]; // [sp+4h] [bp-78h]@1

  v5 = this;
  TPanel::get_string(text_id, str1, 120);
  return TRIBE_Screen_Sed::create_button(v5, parent, button, str1, 0, 0, 0);
}

//----- (004A8840) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_button(TRIBE_Screen_Sed *this, TPanel *parent, TButtonPanel **button, char *text1, char *text2, char *text3, char *text4)
{
  TRIBE_Screen_Sed *v7; // esi@1
  int result; // eax@1

  v7 = this;
  result = TEasy_Panel::create_button((TEasy_Panel *)&this->vfptr, parent, button, text1, text2, 0, 0, 0, 0, 10, 1, 0);
  if ( result )
  {
    if ( text3 )
      TButtonPanel::set_text(*button, 2, text3);
    if ( text4 )
      TButtonPanel::set_text(*button, 3, text4);
    TPanel::set_z_order((TPanel *)*button, 1, 0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*button + 20))(0);
    if ( v7->use_bevels )
      TButtonPanel::set_bevel_info(
        *button,
        3,
        v7->bevel_color1,
        v7->bevel_color2,
        v7->bevel_color3,
        v7->bevel_color4,
        v7->bevel_color5,
        v7->bevel_color6);
    result = 1;
  }
  return result;
}

//----- (004A8910) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_text(TRIBE_Screen_Sed *this, TPanel *parent, TTextPanel **text_panel, int text_id)
{
  int result; // eax@1

  result = TEasy_Panel::create_text((TEasy_Panel *)&this->vfptr, parent, text_panel, text_id, 0, 0, 0, 0, 10, 0, 0, 0);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)&(*text_panel)->vfptr, 1, 0);
    (*(void (__stdcall **)(_DWORD))&(*text_panel)->vfptr->gap10[4])(0);
    result = 1;
  }
  return result;
}

//----- (004A8960) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_text(TRIBE_Screen_Sed *this, TPanel *parent, TTextPanel **text_panel, char *text)
{
  int result; // eax@1

  result = TEasy_Panel::create_text((TEasy_Panel *)&this->vfptr, parent, text_panel, text, 0, 0, 0, 0, 10, 0, 0, 0);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)&(*text_panel)->vfptr, 1, 0);
    (*(void (__stdcall **)(_DWORD))&(*text_panel)->vfptr->gap10[4])(0);
    result = 1;
  }
  return result;
}

//----- (004A89B0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_input(TRIBE_Screen_Sed *this, TPanel *parent, TInputPanel **input_panel, char *value, __int16 max_len, TInputPanel::FormatType format_type)
{
  int result; // eax@1

  result = TEasy_Panel::create_input(
             (TEasy_Panel *)&this->vfptr,
             parent,
             input_panel,
             value,
             max_len,
             format_type,
             0,
             0,
             0,
             0,
             10);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)&(*input_panel)->vfptr, 1, 0);
    (*(void (__stdcall **)(_DWORD))&(*input_panel)->vfptr->gap10[4])(0);
    result = 1;
  }
  return result;
}

//----- (004A8A00) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_edit(TRIBE_Screen_Sed *this, TPanel *parent, TEditPanel **edit_panel, char *value, __int16 max_len, TEditPanel::FormatType format_type, int enable_ime, int turn_ime_on)
{
  int result; // eax@1

  result = TEasy_Panel::create_edit(
             (TEasy_Panel *)&this->vfptr,
             parent,
             edit_panel,
             value,
             max_len,
             format_type,
             0,
             0,
             0,
             0,
             10,
             enable_ime,
             turn_ime_on);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)&(*edit_panel)->vfptr, 1, 0);
    (*(void (__stdcall **)(_DWORD))&(*edit_panel)->vfptr->gap10[4])(0);
    result = 1;
  }
  return result;
}

//----- (004A8A60) --------------------------------------------------------
char *__thiscall TRIBE_Screen_Sed::create_drop_down(TRIBE_Screen_Sed *this, TPanel *parent, TDropDownPanel **drop_panel)
{
  TRIBE_Screen_Sed *v3; // ebx@1
  int v4; // eax@25
  char *result; // eax@30
  TDropDownPanel **v6; // edi@31
  TDropDownPanel **v7; // edi@33
  TDropDownPanel **v8; // edi@35
  signed int v9; // esi@36
  TDropDownPanel **v10; // edi@39
  signed int v11; // esi@40
  TDropDownPanel **v12; // edi@43
  TDropDownPanel **v13; // edi@45
  TDropDownPanel **v14; // edi@47
  TDropDownPanel **v15; // edi@49
  TDropDownPanel **v16; // edi@51
  TDropDownPanel **v17; // edi@53
  TDropDownPanel **v18; // ebp@55
  int v19; // esi@56
  RGE_Game_WorldVtbl *v20; // eax@56
  int v21; // edi@57
  char *v22; // eax@58
  TDropDownPanel **v23; // eax@65
  TDropDownPanel **v24; // edi@75
  int v25; // ebp@76
  RGE_Player *v26; // esi@76
  int v27; // ecx@76
  RGE_Master_Static_Object *v28; // eax@77
  __int16 v29; // dx@79
  char *v30; // [sp-Ch] [bp-124h]@66
  char v31; // [sp-8h] [bp-120h]@66
  char v32; // [sp-4h] [bp-11Ch]@66
  int end_i; // [sp+10h] [bp-108h]@76
  RGE_Player *player; // [sp+14h] [bp-104h]@76
  char str[256]; // [sp+18h] [bp-100h]@80

  v3 = this;
  if ( drop_panel == &this->victory_object_list
    || drop_panel == &this->victory_attribute_list
    || drop_panel == &this->victory_ages_list
    || drop_panel == &this->victory_tech_list
    || drop_panel == &this->BuildList
    || drop_panel == &this->CityLayout
    || drop_panel == &this->AiRules
    || drop_panel == &this->victory_time )
  {
    v4 = 220;
  }
  else if ( drop_panel == &this->victory_drop_down )
  {
    v4 = 180;
  }
  else if ( drop_panel == this->cinematic_input
         || drop_panel == &this->cinematic_input[1]
         || drop_panel == &this->cinematic_input[2]
         || drop_panel == &this->cinematic_input[3]
         || drop_panel == &this->default_terrain_drop
         || drop_panel == &this->map_size_drop
         || drop_panel == &this->map_style_drop )
  {
    v4 = 170;
  }
  else if ( drop_panel == &this->player_advance_civilization_drop
         || drop_panel == &this->player_list
         || drop_panel == &this->player_number_list
         || drop_panel == &this->unit_player_list
         || drop_panel == &this->victory_player_list
         || drop_panel == &this->options_player_list
         || drop_panel == &this->Diplomacy_player_list
         || drop_panel == &this->victory_enemy_player_list )
  {
    v4 = 150;
  }
  else
  {
    v4 = 130;
  }
  result = TEasy_Panel::create_drop_down((TEasy_Panel *)&this->vfptr, parent, drop_panel, v4, 100, 0, 0, v4, 22, 10);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)&(*drop_panel)->vfptr, 1, 0);
    (*(void (__stdcall **)(_DWORD))&(*drop_panel)->vfptr->gap10[4])(0);
    TDropDownPanel::empty_list(*drop_panel);
    v6 = &v3->map_size_drop;
    if ( drop_panel == &v3->map_size_drop )
    {
      TDropDownPanel::append_line(*v6, 10611, 0);
      TDropDownPanel::append_line(*v6, 10612, 0);
      TDropDownPanel::append_line(*v6, 10613, 0);
      TDropDownPanel::append_line(*v6, 10614, 0);
      TDropDownPanel::append_line(*v6, 10615, 0);
      TDropDownPanel::append_line(*v6, 10616, 0);
      TDropDownPanel::set_line(*v6, 3);
      return (char *)(v3->error_code == 0);
    }
    v7 = &v3->map_style_drop;
    if ( drop_panel == &v3->map_style_drop )
    {
      TDropDownPanel::append_line(*v7, 10602, 0);
      TDropDownPanel::append_line(*v7, 10603, 0);
      TDropDownPanel::append_line(*v7, 10604, 0);
      TDropDownPanel::append_line(*v7, 10605, 0);
      TDropDownPanel::append_line(*v7, 10606, 0);
      TDropDownPanel::append_line(*v7, 10607, 0);
      TDropDownPanel::append_line(*v7, 10608, 0);
      TDropDownPanel::append_line(*v7, 10609, 0);
      TDropDownPanel::append_line(*v7, 10610, 0);
      TDropDownPanel::set_line(*v7, 3);
      return (char *)(v3->error_code == 0);
    }
    v8 = &v3->player_number_list;
    if ( drop_panel == &v3->player_number_list )
    {
      v9 = 0;
      do
        TDropDownPanel::append_line(*v8, v9++ + 10359, 0);
      while ( v9 < 8 );
      TDropDownPanel::set_line(*v8, 0);
      return (char *)(v3->error_code == 0);
    }
    v10 = &v3->victory_enemy_player_list;
    if ( drop_panel == &v3->victory_enemy_player_list )
    {
      v11 = 0;
      do
        TDropDownPanel::append_line(*v10, v11++ + 10359, 0);
      while ( v11 < 8 );
      TDropDownPanel::set_line(*v10, 0);
      return (char *)(v3->error_code == 0);
    }
    v12 = &v3->victory_attribute_list;
    if ( drop_panel == &v3->victory_attribute_list )
    {
      TDropDownPanel::append_line(*v12, 10370, 43);
      TDropDownPanel::append_line(*v12, 10371, 41);
      TDropDownPanel::append_line(*v12, 10372, 44);
      TDropDownPanel::append_line(*v12, 10374, 40);
      TDropDownPanel::append_line(*v12, 10375, 21);
      TDropDownPanel::append_line(*v12, 10376, 20);
      TDropDownPanel::append_line(*v12, 10377, 37);
      TDropDownPanel::set_line(*v12, 0);
      return (char *)(v3->error_code == 0);
    }
    v13 = &v3->default_terrain_drop;
    if ( drop_panel == &v3->default_terrain_drop )
    {
      TDropDownPanel::append_line(*v13, 10621, 0);
      TDropDownPanel::append_line(*v13, 10622, 0);
      TDropDownPanel::append_line(*v13, 10623, 0);
      TDropDownPanel::append_line(*v13, 10624, 0);
      TDropDownPanel::append_line(*v13, 10625, 0);
      TDropDownPanel::append_line(*v13, 10626, 0);
      TDropDownPanel::append_line(*v13, 10627, 0);
      TDropDownPanel::append_line(*v13, 10628, 0);
      TDropDownPanel::append_line(*v13, 10629, 0);
      TDropDownPanel::set_line(*v13, 0);
      return (char *)(v3->error_code == 0);
    }
    v14 = v3->player_setting_drop;
    if ( drop_panel == v3->player_setting_drop )
    {
      TDropDownPanel::append_line(*v14, 10211, 0);
      TDropDownPanel::append_line(*v14, 10212, 0);
      TDropDownPanel::set_line(*v14, 0);
      return (char *)(v3->error_code == 0);
    }
    v15 = &v3->victory_drop_down;
    if ( drop_panel == &v3->victory_drop_down )
    {
      TDropDownPanel::append_line(*v15, 10321, 0);
      TDropDownPanel::append_line(*v15, 10322, 0);
      TDropDownPanel::append_line(*v15, 10323, 0);
      TDropDownPanel::append_line(*v15, 10324, 0);
      TDropDownPanel::append_line(*v15, 10325, 0);
      TDropDownPanel::append_line(*v15, 10326, 0);
      TDropDownPanel::append_line(*v15, 10327, 0);
      TDropDownPanel::append_line(*v15, 10328, 0);
      TDropDownPanel::append_line(*v15, 10329, 0);
      TDropDownPanel::append_line(*v15, 10330, 0);
      TDropDownPanel::append_line(*v15, 10331, 0);
      TDropDownPanel::append_line(*v15, 10332, 0);
      TDropDownPanel::append_line(*v15, 10333, 0);
      TDropDownPanel::append_line(*v15, 10334, 0);
      TDropDownPanel::append_line(*v15, 10335, 0);
      TDropDownPanel::append_line(*v15, 10336, 0);
      TDropDownPanel::append_line(*v15, 10337, 0);
      TDropDownPanel::append_line(*v15, 10338, 0);
      TDropDownPanel::append_line(*v15, 10319, 0);
      TDropDownPanel::set_line(*v15, 0);
      return (char *)(v3->error_code == 0);
    }
    v16 = &v3->player_setting_drop[1];
    if ( drop_panel == &v3->player_setting_drop[1] )
    {
      TDropDownPanel::append_line(*v16, 10231, 0);
      TDropDownPanel::append_line(*v16, 10232, 0);
      TDropDownPanel::append_line(*v16, 10233, 0);
      TDropDownPanel::append_line(*v16, 10234, 0);
      TDropDownPanel::append_line(*v16, 10235, 0);
      TDropDownPanel::append_line(*v16, 10236, 0);
      TDropDownPanel::append_line(*v16, 10237, 0);
      TDropDownPanel::append_line(*v16, 10238, 0);
      TDropDownPanel::append_line(*v16, 10239, 0);
      TDropDownPanel::append_line(*v16, 10240, 0);
      TDropDownPanel::append_line(*v16, 10241, 0);
      TDropDownPanel::append_line(*v16, 10242, 0);
      TDropDownPanel::append_line(*v16, 10246, 0);
      TDropDownPanel::append_line(*v16, 10247, 0);
      TDropDownPanel::append_line(*v16, 10249, 0);
      TDropDownPanel::append_line(*v16, 10248, 0);
      TDropDownPanel::set_line(*v16, 0);
      return (char *)(v3->error_code == 0);
    }
    v17 = &v3->victory_ages_list;
    if ( drop_panel == &v3->victory_ages_list )
    {
      TDropDownPanel::append_line(*v17, 4201, 0);
      TDropDownPanel::append_line(*v17, 4202, 0);
      TDropDownPanel::append_line(*v17, 4203, 0);
      TDropDownPanel::append_line(*v17, 4204, 0);
      TDropDownPanel::set_line(*v17, 0);
      return (char *)(v3->error_code == 0);
    }
    v18 = &v3->victory_tech_list;
    if ( drop_panel == &v3->victory_tech_list )
    {
      TDropDownPanel::set_sorted(*v18, 1);
      v19 = 0;
      v20 = rge_base_game->world[1].vfptr;
      if ( *((_WORD *)&v20->data_load_world + 2) > 0 )
      {
        v21 = 0;
        do
        {
          v22 = TPanel::get_string(*(_WORD *)((char *)v20->data_load_world + v21 + 42));
          if ( v22 && *v22 )
            TDropDownPanel::append_line(*v18, v22, v19);
          ++v19;
          v21 += 60;
          v20 = rge_base_game->world[1].vfptr;
        }
        while ( v19 < *((_WORD *)&v20->data_load_world + 2) );
      }
      TDropDownPanel::set_line(*v18, 0);
      return (char *)(v3->error_code == 0);
    }
    if ( drop_panel == &v3->AiRules )
    {
      TRIBE_Screen_Sed::MakeFileList(v3->AiRules, rge_base_game->prog_info->ai_dir, a_per, 0, 1);
    }
    else
    {
      v23 = &v3->BuildList;
      if ( drop_panel == &v3->BuildList )
      {
        v32 = 1;
        v31 = 1;
        v30 = a_ai;
      }
      else
      {
        v23 = &v3->CityLayout;
        if ( drop_panel != &v3->CityLayout )
        {
          if ( drop_panel == v3->cinematic_input
            || drop_panel == &v3->cinematic_input[1]
            || drop_panel == &v3->cinematic_input[2] )
          {
            TRIBE_Screen_Sed::MakeFileList(*drop_panel, rge_base_game->prog_info->avi_dir, extension, 1, 0);
          }
          else
          {
            if ( drop_panel != &v3->cinematic_input[3] )
            {
              v24 = &v3->victory_object_list;
              if ( drop_panel == &v3->victory_object_list )
              {
                TDropDownPanel::set_sorted(*v24, 1);
                TDropDownPanel::empty_list(*v24);
                v25 = 0;
                v26 = (RGE_Player *)*((_DWORD *)v3->world->players + 1);
                player = v26;
                v27 = v26->master_object_num;
                end_i = v26->master_object_num;
                if ( v27 > 0 )
                {
                  do
                  {
                    v28 = v26->master_objects[v25];
                    if ( v28 && !v28->hide_in_scenario_editor )
                    {
                      v29 = v28->string_id;
                      if ( v29 <= 0 )
                      {
                        strcpy(str, v28->name);
                        v26 = player;
                      }
                      else
                      {
                        (*(void (__stdcall **)(_DWORD, char *, signed int))&rge_base_game->vfptr->gap8[24])(
                          v29,
                          str,
                          256);
                      }
                      TDropDownPanel::append_line(v3->victory_object_list, str, v25);
                      v27 = end_i;
                    }
                    ++v25;
                  }
                  while ( v25 < v27 );
                }
                TDropDownPanel::set_line(v3->victory_object_list, 0);
              }
              return (char *)(v3->error_code == 0);
            }
            TRIBE_Screen_Sed::MakeFileList(*drop_panel, message_in, a_bmp, 1, 0);
          }
          goto LABEL_86;
        }
        v32 = 0;
        v31 = 1;
        v30 = a_cty;
      }
      TRIBE_Screen_Sed::MakeFileList(*v23, rge_base_game->prog_info->ai_dir, v30, v31, v32);
    }
LABEL_86:
    TDropDownPanel::set_line(*drop_panel, 0);
    return (char *)(v3->error_code == 0);
  }
  return result;
}

//----- (004A9320) --------------------------------------------------------
int __stdcall TRIBE_Screen_Sed::SetupListOfTerrain(TListPanel *list)
{
  TTextPanel::empty_list((TTextPanel *)&list->vfptr);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10621, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10622, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10623, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10624, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10625, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10626, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10627, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10628, 0);
  TTextPanel::append_line((TTextPanel *)&list->vfptr, 10629, 0);
  return 8;
}

//----- (004A93C0) --------------------------------------------------------
char *__thiscall TRIBE_Screen_Sed::create_list(TRIBE_Screen_Sed *this, TPanel *parent, TListPanel **list_panel, TScrollBarPanel **scrollbar_panel)
{
  TRIBE_Screen_Sed *v4; // esi@1
  char *result; // eax@1
  TTextPanel **v6; // edi@3
  int v7; // eax@4
  int v8; // esi@5
  char str1[50]; // [sp+Ch] [bp-70h]@4
  char str2[60]; // [sp+40h] [bp-3Ch]@5

  v4 = this;
  result = TEasy_Panel::create_list((TEasy_Panel *)&this->vfptr, parent, list_panel, 0, 0, 0, 0, 10);
  if ( result )
  {
    (*(void (__stdcall **)(_DWORD))&(*list_panel)->vfptr->gap10[4])(0);
    TTextPanel::empty_list((TTextPanel *)&(*list_panel)->vfptr);
    result = (char *)TEasy_Panel::create_auto_scrollbar(
                       (TEasy_Panel *)&v4->vfptr,
                       scrollbar_panel,
                       (TTextPanel *)&(*list_panel)->vfptr,
                       20);
    if ( result )
    {
      v6 = (TTextPanel **)&v4->paint_elevation_list;
      if ( list_panel == &v4->paint_elevation_list )
      {
        TRIBE_Screen_Sed::set_string(str1, 10631, 50);
        v7 = 0;
        do
        {
          v8 = v7 + 1;
          sprintf(str2, aSD_2, str1, v7 + 1);
          TTextPanel::append_line(*v6, str2, 0);
          v7 = v8;
        }
        while ( v8 < 7 );
        result = (char *)1;
      }
      else
      {
        if ( list_panel == &v4->paint_terrain_list )
          TRIBE_Screen_Sed::SetupListOfTerrain(v4->paint_terrain_list);
        result = (char *)1;
      }
    }
  }
  return result;
}

//----- (004A94A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::~TRIBE_Screen_Sed(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  TPanel **v2; // edi@1
  signed int v3; // ebx@1
  TPanel **v4; // edi@3
  signed int v5; // ebx@3
  TPanel **v6; // edi@5
  signed int v7; // ebx@5
  TPanel **v8; // edi@7
  signed int v9; // ebx@7
  TPanel **v10; // edi@9
  signed int v11; // ebx@9
  TPanel **v12; // edi@11
  signed int v13; // ebx@11
  TRIBE_Scenario_Editor_Panel_Object *v14; // ecx@15
  TShape *v15; // edi@17
  TShape **v16; // ebx@19
  signed int v17; // ebp@19
  TShape *v18; // edi@20
  TPanel **v19; // edi@23
  signed int v20; // ebx@23
  TPanel **v21; // edi@25
  signed int v22; // ebx@25
  TPanel **v23; // edi@27
  signed int v24; // ebx@27
  TPanel **v25; // edi@29
  signed int v26; // ebx@29
  TPanel **v27; // edi@31
  signed int v28; // ebx@31
  TPanel **v29; // edi@33
  signed int v30; // ebx@33
  TPanel **v31; // edi@35
  signed int v32; // ebx@35
  TPanel **v33; // edi@37
  signed int v34; // ebx@37
  TPanel **v35; // ebx@39
  int v36; // edi@39
  signed int v37; // ebp@39
  TPanel **v38; // edi@41
  signed int v39; // ebx@41
  TShape *v40; // edi@43
  TRIBE_World *v41; // ecx@45

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Sed::`vftable';
  TPanelSystem::destroyPanel(&panel_system, aQuitsavedialog);
  TPanelSystem::destroyPanel(&panel_system, aOpensavedialog);
  TPanelSystem::destroyPanel(&panel_system, aNewsavedialog);
  TPanelSystem::destroyPanel(&panel_system, aSaveGameScreen);
  TPanelSystem::destroyPanel(&panel_system, aScenarioMenuDi);
  TPanel::delete_panel((TPanel **)&v1->map_type_label);
  v2 = (TPanel **)v1->map_type_text;
  v3 = 3;
  do
  {
    TPanel::delete_panel(v2 - 3);
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  TPanel::delete_panel((TPanel **)&v1->default_terrain_label);
  TPanel::delete_panel((TPanel **)&v1->default_terrain_drop);
  TPanel::delete_panel((TPanel **)&v1->map_size_label);
  TPanel::delete_panel((TPanel **)&v1->map_size_drop);
  TPanel::delete_panel((TPanel **)&v1->map_style_drop);
  TPanel::delete_panel((TPanel **)&v1->map_style_label);
  TPanel::delete_panel((TPanel **)&v1->map_generating_text);
  TPanel::delete_panel((TPanel **)&v1->random_seed_label);
  TPanel::delete_panel((TPanel **)&v1->random_seed_input);
  TPanel::delete_panel((TPanel **)&v1->random_seed_used_label);
  TPanel::delete_panel((TPanel **)&v1->random_seed_used_text);
  TPanel::delete_panel((TPanel **)&v1->generate_map_button);
  TPanel::delete_panel((TPanel **)&v1->brush_size_label);
  v4 = (TPanel **)v1->brush_size_button_label;
  v5 = 5;
  do
  {
    TPanel::delete_panel(v4 - 5);
    TPanel::delete_panel(v4);
    ++v4;
    --v5;
  }
  while ( v5 );
  TPanel::delete_panel((TPanel **)&v1->paint_type_label);
  v6 = (TPanel **)v1->paint_type_button_label;
  v7 = 3;
  do
  {
    TPanel::delete_panel(v6 - 3);
    TPanel::delete_panel(v6);
    ++v6;
    --v7;
  }
  while ( v7 );
  TPanel::delete_panel((TPanel **)&v1->paint_terrain_label);
  TPanel::delete_panel((TPanel **)&v1->paint_terrain_list);
  TPanel::delete_panel((TPanel **)&v1->paint_terrain_scrollbar);
  TPanel::delete_panel((TPanel **)&v1->paint_elevation_list);
  TPanel::delete_panel((TPanel **)&v1->paint_elevation_scrollbar);
  TPanel::delete_panel((TPanel **)&v1->player_advance_civilization_drop);
  TPanel::delete_panel((TPanel **)&v1->player_label);
  TPanel::delete_panel((TPanel **)&v1->player_starting_age_label);
  TPanel::delete_panel((TPanel **)&v1->player_build_text);
  TPanel::delete_panel((TPanel **)&v1->player_city_text);
  TPanel::delete_panel((TPanel **)&v1->AiRules_text);
  TPanel::delete_panel((TPanel **)&v1->player_list);
  TPanel::delete_panel((TPanel **)&v1->player_number_list);
  v8 = (TPanel **)v1->player_inven_input;
  v9 = 5;
  do
  {
    TPanel::delete_panel(v8 - 5);
    TPanel::delete_panel(v8);
    ++v8;
    --v9;
  }
  while ( v9 );
  v10 = (TPanel **)v1->player_setting_drop;
  v11 = 2;
  do
  {
    TPanel::delete_panel(v10 - 3);
    TPanel::delete_panel(v10);
    ++v10;
    --v11;
  }
  while ( v11 );
  TPanel::delete_panel((TPanel **)&v1->BuildList);
  TPanel::delete_panel((TPanel **)&v1->CityLayout);
  TPanel::delete_panel((TPanel **)&v1->AiRules);
  TPanel::delete_panel((TPanel **)&v1->unit_player_list);
  v12 = (TPanel **)v1->unit_mode_select_label;
  v13 = 4;
  do
  {
    TPanel::delete_panel(v12 - 4);
    TPanel::delete_panel(v12);
    ++v12;
    --v13;
  }
  while ( v13 );
  TPanel::delete_panel((TPanel **)&v1->unit_list);
  TPanel::delete_panel((TPanel **)&v1->unit_scrollbar);
  if ( v1->unit_list_info )
  {
    free(v1->unit_list_info);
    v1->unit_list_info = 0;
  }
  v14 = v1->object_panel;
  if ( v14 )
  {
    ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
    v1->object_panel = 0;
  }
  v15 = v1->button_unit_pics;
  if ( v15 )
  {
    TShape::~TShape(v1->button_unit_pics);
    operator delete(v15);
    v1->button_unit_pics = 0;
  }
  v16 = v1->button_bldg_pics;
  v17 = 5;
  do
  {
    v18 = *v16;
    if ( *v16 )
    {
      TShape::~TShape(*v16);
      operator delete(v18);
      *v16 = 0;
    }
    ++v16;
    --v17;
  }
  while ( v17 );
  v19 = (TPanel **)v1->victory_cond_on;
  v20 = 6;
  do
  {
    TPanel::delete_panel(v19);
    ++v19;
    --v20;
  }
  while ( v20 );
  v21 = (TPanel **)v1->victory_text_and_or;
  v22 = 2;
  do
  {
    TPanel::delete_panel(v21 - 5);
    TPanel::delete_panel(v21);
    ++v21;
    --v22;
  }
  while ( v22 );
  TPanel::delete_panel((TPanel **)&v1->victory_amount_label);
  TPanel::delete_panel((TPanel **)&v1->victory_long_label);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_label);
  TPanel::delete_panel((TPanel **)&v1->victory_label_conquest);
  TPanel::delete_panel((TPanel **)&v1->victory_label_explore);
  TPanel::delete_panel((TPanel **)&v1->victory_label_explore_percent);
  TPanel::delete_panel((TPanel **)&v1->victory_label_ruins);
  TPanel::delete_panel((TPanel **)&v1->victory_label_artifacts);
  TPanel::delete_panel((TPanel **)&v1->victory_label_discoveries);
  TPanel::delete_panel((TPanel **)&v1->victory_label_gold);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_explore);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_ruins);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_artifacts);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_discoveries);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_gold);
  v23 = (TPanel **)v1->victory_cond_type;
  v24 = 5;
  do
  {
    TPanel::delete_panel(v23 - 5);
    TPanel::delete_panel(v23);
    ++v23;
    --v24;
  }
  while ( v24 );
  TPanel::delete_panel((TPanel **)&v1->victory_score_label);
  TPanel::delete_panel((TPanel **)&v1->victory_score);
  TPanel::delete_panel((TPanel **)&v1->victory_time_label);
  TPanel::delete_panel((TPanel **)&v1->victory_time);
  v25 = (TPanel **)v1->victory_button;
  v26 = 12;
  do
  {
    TPanel::delete_panel(v25);
    ++v25;
    --v26;
  }
  while ( v26 );
  TPanel::delete_panel((TPanel **)&v1->victory_drop_down);
  TPanel::delete_panel((TPanel **)&v1->victory_object_list);
  TPanel::delete_panel((TPanel **)&v1->victory_player_list);
  TPanel::delete_panel((TPanel **)&v1->victory_ages_list);
  TPanel::delete_panel((TPanel **)&v1->victory_tech_list);
  TPanel::delete_panel((TPanel **)&v1->victory_button_set_object);
  TPanel::delete_panel((TPanel **)&v1->victory_button_set_destination);
  TPanel::delete_panel((TPanel **)&v1->victory_button_go_to_dest);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_text);
  TPanel::delete_panel((TPanel **)&v1->victory_condition_type);
  TPanel::delete_panel((TPanel **)&v1->victory_amount_text);
  TPanel::delete_panel((TPanel **)&v1->victory_amount_input);
  TPanel::delete_panel((TPanel **)&v1->victory_enemy_player_list);
  TPanel::delete_panel((TPanel **)&v1->victory_attribute_list);
  TPanel::delete_panel((TPanel **)&v1->victory_which_enemy_text);
  TPanel::delete_panel((TPanel **)&v1->victory_object_scrollbar);
  v27 = (TPanel **)v1->message_button_label;
  v28 = 5;
  do
  {
    TPanel::delete_panel(v27 - 5);
    TPanel::delete_panel(v27);
    ++v27;
    --v28;
  }
  while ( v28 );
  TPanel::delete_panel((TPanel **)&v1->message_input);
  v29 = (TPanel **)v1->cinematic_input;
  v30 = 4;
  do
  {
    TPanel::delete_panel(v29 - 4);
    TPanel::delete_panel(v29);
    ++v29;
    --v30;
  }
  while ( v30 );
  v31 = (TPanel **)v1->options_button;
  v32 = 1;
  do
  {
    TPanel::delete_panel(v31 - 1);
    TPanel::delete_panel(v31);
    ++v31;
    --v32;
  }
  while ( v32 );
  TPanel::delete_panel((TPanel **)&v1->options_player_list);
  TPanel::delete_panel((TPanel **)&v1->options_disable_tech_text);
  v33 = (TPanel **)v1->options_disable_text;
  v34 = 16;
  do
  {
    TPanel::delete_panel(v33 - 16);
    TPanel::delete_panel(v33);
    ++v33;
    --v34;
  }
  while ( v34 );
  v35 = (TPanel **)v1->Diplomacy_AlliedVictory;
  v36 = (int)&v1->Diplomacy_friend_box[0][1];
  v37 = 8;
  do
  {
    TPanel::delete_panel((TPanel **)&v1->Diplomacy_player_list);
    TPanel::delete_panel(v35 - 37);
    TPanel::delete_panel((TPanel **)(v36 - 4));
    TPanel::delete_panel((TPanel **)v36);
    TPanel::delete_panel((TPanel **)(v36 + 4));
    TPanel::delete_panel(v35);
    ++v35;
    v36 += 12;
    --v37;
  }
  while ( v37 );
  TPanel::delete_panel((TPanel **)v1->Diplomacy_status_label);
  TPanel::delete_panel((TPanel **)&v1->Diplomacy_status_label[1]);
  TPanel::delete_panel((TPanel **)&v1->Diplomacy_status_label[2]);
  TPanel::delete_panel((TPanel **)&v1->Diplomacy_status_label[3]);
  TPanel::delete_panel((TPanel **)&v1->menu_button);
  TPanel::delete_panel((TPanel **)&v1->help_button);
  v38 = (TPanel **)v1->scenario_mode_button;
  v39 = 10;
  do
  {
    TPanel::delete_panel(v38);
    ++v38;
    --v39;
  }
  while ( v39 );
  TPanel::delete_panel(&v1->bottom_panel);
  TPanel::delete_panel((TPanel **)&v1->message_panel);
  TPanel::delete_panel((TPanel **)&v1->main_view);
  TPanel::delete_panel((TPanel **)&v1->map_view);
  v40 = v1->background_pic;
  if ( v40 )
  {
    TShape::~TShape(v1->background_pic);
    operator delete(v40);
    v1->background_pic = 0;
  }
  v41 = v1->world;
  if ( v41 )
    ((void (*)(void))v41->vfptr->del_game_info)();
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5739C0: using guessed type int (__thiscall *TRIBE_Screen_Sed::`vftable')(void *Memory, unsigned int __flags);

//----- (004A9CC0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_scenario_mode(TRIBE_Screen_Sed *this, TRIBE_Screen_Sed::ScenarioMode new_mode)
{
  TRIBE_Screen_Sed *v2; // esi@1
  int v3; // edi@3
  int v4; // ebx@8
  signed int v5; // ebp@8
  int v6; // ebx@13
  signed int v7; // ebp@13
  int v8; // ebx@15
  signed int v9; // ebp@15
  int v10; // ebx@20
  signed int v11; // ebp@20
  int v12; // ebx@22
  signed int v13; // ebp@22
  int v14; // eax@23
  int v15; // eax@25
  int v16; // eax@25
  int v17; // eax@30
  __int16 v18; // ax@31
  __int16 v19; // di@33
  RGE_Game_World *v20; // ST08_4@33
  RGE_Master_Static_Object *v21; // ST04_4@33
  int v22; // eax@41
  int v23; // eax@42
  RGE_Player *v24; // eax@42
  int v25; // ebx@43
  signed int v26; // ebp@43
  int v27; // ebx@48
  signed int v28; // ebp@48
  char *v29; // eax@51
  char *v30; // eax@59
  TPanel **v31; // ebp@60
  int v32; // ebx@60
  char *v33; // eax@63
  int v34; // eax@63
  char *v35; // eax@63
  int v36; // eax@63
  char *v37; // eax@63
  int v38; // eax@63
  char *v39; // eax@63
  int v40; // eax@63
  char *v41; // eax@64
  char *v42; // eax@64
  char *v43; // eax@66
  char *v44; // eax@66
  char *v45; // eax@66
  char *v46; // eax@66
  int v47; // ebp@70
  TButtonPanel **v48; // ebx@70
  TButtonPanel *v49; // ecx@71
  RGE_Diamond_Map_View *v50; // ecx@77
  int v51; // ebx@79
  int v52; // eax@79
  __int16 v53; // ax@79
  int v54; // ebx@82
  signed int v55; // ebp@82
  int v56; // ebx@87
  signed int v57; // ebp@87
  bool v58; // sf@89
  unsigned __int8 v59; // of@89
  TPanelVtbl *v60; // edi@93
  int v61; // [sp+4h] [bp-24h]@52
  int v62; // [sp+8h] [bp-20h]@50
  int i; // [sp+1Ch] [bp-Ch]@60
  int ia; // [sp+1Ch] [bp-Ch]@69
  int activate_counter; // [sp+20h] [bp-8h]@1
  TRIBE_Screen_Sed::ScenarioMode mode; // [sp+24h] [bp-4h]@0

  v2 = this;
  activate_counter = 0;
  this->valid_save_spot_flag = 0;
  do
  {
    if ( activate_counter )
    {
      if ( new_mode != 11 )
        mode = new_mode;
      v3 = 1;
    }
    else
    {
      v3 = 0;
      mode = v2->scenario_mode;
    }
    switch ( mode )
    {
      case 1:
        (*(void (__stdcall **)(int))&v2->map_type_label->vfptr->gap10[4])(v3);
        v4 = (int)v2->map_type_text;
        v5 = 3;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v4 - 12) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v4 + 20))(v3);
          v4 += 4;
          --v5;
        }
        while ( v5 );
        (*(void (__stdcall **)(int))(*(_DWORD *)v2->generate_map_button + 20))(v3);
        if ( v3 )
          TRIBE_Screen_Sed::set_map_type(v2, v2->map_type, 1);
        else
          TRIBE_Screen_Sed::set_map_type(v2, 0, 0);
        break;
      case 2:
        (*(void (__stdcall **)(int))&v2->brush_size_label->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->paint_type_label->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->paint_terrain_label->vfptr->gap10[4])(v3);
        v6 = (int)v2->brush_size_button_label;
        v7 = 5;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v6 - 20) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v6 + 20))(v3);
          v6 += 4;
          --v7;
        }
        while ( v7 );
        v8 = (int)v2->paint_type_button_label;
        v9 = 3;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v8 - 12) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v8 + 20))(v3);
          v8 += 4;
          --v9;
        }
        while ( v9 );
        if ( v3 )
        {
          TRIBE_Screen_Sed::set_brush_size(v2, v2->brush_size);
          TRIBE_Screen_Sed::set_paint_type(v2, v2->paint_type, 1);
        }
        else
        {
          TRIBE_Screen_Sed::set_brush_size(v2, 0);
          TRIBE_Screen_Sed::set_paint_type(v2, 0, 0);
        }
        break;
      case 3:
        (*(void (__stdcall **)(int))&v2->player_list->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->player_number_list->vfptr->gap10[4])(v3);
        v10 = (int)v2->player_inven_input;
        v11 = 5;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v10 - 20) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v10 + 20))(v3);
          v10 += 4;
          --v11;
        }
        while ( v11 );
        v12 = (int)v2->player_setting_drop;
        v13 = 2;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v12 - 12) + 20))(v3);
          v14 = (*(int (__stdcall **)(int))(**(_DWORD **)v12 + 20))(v3);
          v12 += 4;
          --v13;
        }
        while ( v13 );
        if ( v3 )
        {
          v15 = T_Scenario::GetPlayerAge((T_Scenario *)v2->world->scenario, v2->player_num - 1);
          TDropDownPanel::setCurrentLineNumber(v2->player_advance_civilization_drop, v15);
          LOWORD(v16) = v2->player_num;
          TRIBE_Screen_Sed::set_player(v2, v16, 0, 1);
          TPanel::set_curr_child(v2->bottom_panel, 0);
          (*(void (__stdcall **)(_DWORD))&v2->map_view->vfptr->gap10[4])(0);
        }
        else
        {
          LOWORD(v14) = v2->player_num;
          TRIBE_Screen_Sed::set_player(v2, v14, 1, 0);
          (*(void (__stdcall **)(signed int))&v2->map_view->vfptr->gap10[4])(1);
          TRIBE_Screen_Sed::SavePlayerActiveStatus(v2);
        }
        (*(void (__stdcall **)(int))&v2->player_advance_civilization_drop->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->player_label->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->player_starting_age_label->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->player_build_text->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->player_city_text->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->AiRules_text->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->BuildList->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->CityLayout->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->AiRules->vfptr->gap10[4])(v3);
        break;
      case 4:
        (*(void (__stdcall **)(int))&v2->unit_player_list->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->unit_list->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->object_panel->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))(*(_DWORD *)v2->unit_mode_select[0] + 20))(v3);
        (*(void (__stdcall **)(int))(*(_DWORD *)v2->unit_mode_select[1] + 20))(v3);
        (*(void (__stdcall **)(int))(*(_DWORD *)v2->unit_mode_select[2] + 20))(v3);
        (*(void (__stdcall **)(int))(*(_DWORD *)v2->unit_mode_select[3] + 20))(v3);
        if ( v3 )
          TButtonPanel::set_radio_button(v2->unit_mode_select[0]);
        (*(void (__stdcall **)(int))&v2->unit_mode_select_label[0]->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->unit_mode_select_label[1]->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->unit_mode_select_label[2]->vfptr->gap10[4])(v3);
        v17 = (*(int (__stdcall **)(int))&v2->unit_mode_select_label[3]->vfptr->gap10[4])(v3);
        LOWORD(v17) = v2->player_num;
        if ( v3 )
        {
          TRIBE_Screen_Sed::set_unit_player(v2, v17);
          v18 = TTextPanel::currentLineNumber((TTextPanel *)&v2->unit_list->vfptr);
          TRIBE_Screen_Sed::set_unit(v2, v18);
          TPanel::set_curr_child(v2->bottom_panel, (TPanel *)&v2->unit_list->vfptr);
          TRIBE_Screen_Sed::set_paint_object_mode(v2);
          (*(void (__stdcall **)(int, signed int))&rge_base_game->vfptr->gap8[8])(rge_base_game->game_mode, 4);
          if ( rge_base_game->master_obj_id != -1 && RGE_Base_Game::get_player(rge_base_game) )
          {
            v19 = rge_base_game->master_obj_id;
            v20 = RGE_Base_Game::get_player(rge_base_game);
            v21 = v2->world->players[HIWORD(RGE_Base_Game::get_player(rge_base_game)->master_players)]->master_objects[v19];
            TRIBE_Scenario_Editor_Panel_Object::set_master_info(v2->object_panel, v21, (TRIBE_Player *)v20);
          }
          else
          {
            TRIBE_Scenario_Editor_Panel_Object::set_master_info(v2->object_panel, 0, 0);
          }
          ((void (__stdcall *)(signed int))v2->object_panel->vfptr->set_redraw)(1);
        }
        else
        {
          if ( (signed __int16)v17 < 1 || (signed __int16)v17 > 8 )
          {
            v2->player_num = 1;
            TRIBE_Screen_Sed::set_player(v2, 1, 0, 0);
          }
          (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
          TRIBE_Screen_Sed::set_unit(v2, -1);
        }
        break;
      case 6:
        TRIBE_Screen_Sed::activate_victory_panel(v2, v3);
        if ( v3 )
        {
          TRIBE_Screen_Sed::load_victory_cond_from_scenario(v2, v2->CurrentVictory);
          v22 = TDropDownPanel::get_line(v2->victory_drop_down);
          TRIBE_Screen_Sed::activate_victory_proper_fields(v2, v22, v3);
        }
        else
        {
          TRIBE_Screen_Sed::save_victory_cond_in_scenario(v2, v2->CurrentVictory);
          v23 = TDropDownPanel::get_line(v2->victory_drop_down);
          TRIBE_Screen_Sed::activate_victory_proper_fields(v2, v23, 0);
          v2->SelectedObject = 0;
          v2->DestinationObject = 0;
          v24 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(v24);
        }
        break;
      case 7:
        (*(void (__stdcall **)(int))&v2->victory_condition_label->vfptr->gap10[4])(v3);
        v25 = (int)v2->victory_cond_type;
        v26 = 5;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v25 - 20) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v25 + 20))(v3);
          v25 += 4;
          --v26;
        }
        while ( v26 );
        if ( v3 )
        {
          TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario(v2);
          (*(void (__stdcall **)(_DWORD))&v2->map_view->vfptr->gap10[4])(0);
          TRIBE_Screen_Sed::set_mp_victory_type(v2, v2->mp_victory_type, 1);
        }
        else
        {
          TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario(v2);
          (*(void (__stdcall **)(signed int))&v2->map_view->vfptr->gap10[4])(1);
          TRIBE_Screen_Sed::set_mp_victory_type(v2, 0, 0);
        }
        break;
      case 9:
        v27 = (int)v2->message_button_label;
        v28 = 5;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v27 - 20) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v27 + 20))(v3);
          v27 += 4;
          --v28;
        }
        while ( v28 );
        TButtonPanel::set_radio_button(v2->message_button[v2->current_message]);
        v62 = v2->current_message;
        if ( v3 )
        {
          v29 = RGE_Scenario::Get_message(v2->world->scenario, v62);
          TEditPanel::set_text(v2->message_input, v29);
          switch ( v2->current_message )
          {
            case 0:
              v61 = 30576;
              goto LABEL_57;
            case 1:
              v61 = 30577;
              goto LABEL_57;
            case 2:
              v61 = 30578;
              goto LABEL_57;
            case 3:
              v61 = 30579;
              goto LABEL_57;
            case 4:
              v61 = 30580;
LABEL_57:
              TPanel::set_help_info((TPanel *)&v2->message_input->vfptr, v61, -1);
              break;
            default:
              break;
          }
          TRIBE_Screen_Sed::set_message_type(v2, v2->message_type, 1);
          (*(void (__stdcall **)(_DWORD))&v2->map_view->vfptr->gap10[4])(0);
          TPanel::set_curr_child(v2->bottom_panel, (TPanel *)&v2->message_input->vfptr);
        }
        else
        {
          v30 = TEditPanel::get_input_buffer(v2->message_input);
          RGE_Scenario::Set_message(v2->world->scenario, v30, v62);
          TRIBE_Screen_Sed::set_message_type(v2, 0, 0);
          (*(void (__stdcall **)(signed int))&v2->map_view->vfptr->gap10[4])(1);
          TRIBE_Screen_Sed::save_info_in_scenario(v2);
        }
        break;
      case 10:
        v31 = (TPanel **)v2->cinematic_input;
        i = 4;
        v32 = (int)v2->cinematic_input;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v32 - 16) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v32 + 20))(v3);
          v32 += 4;
          --i;
        }
        while ( i );
        if ( v3 )
        {
          TPanel::set_curr_child(v2->bottom_panel, *v31);
          v33 = RGE_Scenario::Get_Cine_PreGame(v2->world->scenario);
          v34 = TDropDownPanel::get_line((TDropDownPanel *)*v31, v33);
          TDropDownPanel::setCurrentLineNumber((TDropDownPanel *)*v31, v34);
          v35 = RGE_Scenario::Get_Cine_Victory(v2->world->scenario);
          v36 = TDropDownPanel::get_line(v2->cinematic_input[1], v35);
          TDropDownPanel::setCurrentLineNumber(v2->cinematic_input[1], v36);
          v37 = RGE_Scenario::Get_Cine_Loss(v2->world->scenario);
          v38 = TDropDownPanel::get_line(v2->cinematic_input[2], v37);
          TDropDownPanel::setCurrentLineNumber(v2->cinematic_input[2], v38);
          v39 = RGE_Scenario::Get_Mission_Bmp(v2->world->scenario);
          v40 = TDropDownPanel::get_line(v2->cinematic_input[3], v39);
          if ( v40 == -1 )
          {
            v41 = RGE_Scenario::Get_Mission_Bmp(v2->world->scenario);
            TDropDownPanel::append_line(v2->cinematic_input[3], v41, 0);
            v42 = RGE_Scenario::Get_Mission_Bmp(v2->world->scenario);
            v40 = TDropDownPanel::get_line(v2->cinematic_input[3], v42);
          }
          TDropDownPanel::setCurrentLineNumber(v2->cinematic_input[3], v40);
        }
        else
        {
          v43 = TDropDownPanel::currentLine((TDropDownPanel *)*v31);
          RGE_Scenario::Set_Cine_PreGame(v2->world->scenario, v43);
          v44 = TDropDownPanel::currentLine(v2->cinematic_input[1]);
          RGE_Scenario::Set_Cine_Victory(v2->world->scenario, v44);
          v45 = TDropDownPanel::currentLine(v2->cinematic_input[2]);
          RGE_Scenario::Set_Cine_Loss(v2->world->scenario, v45);
          v46 = TDropDownPanel::currentLine(v2->cinematic_input[3]);
          RGE_Scenario::Set_Mission_Bmp(v2->world->scenario, v46);
        }
        break;
      case 5:
        if ( v2->player_num < 1 )
          v2->player_num = 1;
        (*(void (__stdcall **)(int))&v2->Diplomacy_player_list->vfptr->gap10[4])(v3);
        ia = 0;
        if ( TDropDownPanel::get_line(v2->player_number_list) >= 0 )
        {
          v47 = (int)&v2->Diplomacy_friend_box[0][1];
          v48 = v2->Diplomacy_AlliedVictory;
          do
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)*(v48 - 37) + 20))(v3);
            v49 = *v48;
            if ( ia != v2->player_num - 1 )
            {
              (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v49 + 20))(0);
              (*(void (__stdcall **)(int))(**(_DWORD **)(v47 - 4) + 20))(v3);
              (*(void (__stdcall **)(int))(**(_DWORD **)v47 + 20))(v3);
              v49 = *(TButtonPanel **)(v47 + 4);
            }
            (*(void (__stdcall **)(int))(*(_DWORD *)v49 + 20))(v3);
            ++v48;
            v47 += 12;
            ++ia;
          }
          while ( ia <= TDropDownPanel::get_line(v2->player_number_list) );
        }
        (*(void (__stdcall **)(int))&v2->Diplomacy_status_label[0]->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->Diplomacy_status_label[1]->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->Diplomacy_status_label[2]->vfptr->gap10[4])(v3);
        (*(void (__stdcall **)(int))&v2->Diplomacy_status_label[3]->vfptr->gap10[4])(v3);
        if ( v3 )
          TRIBE_Screen_Sed::load_diplomacy_from_scenario(v2, v2->player_num - 1);
        else
          TRIBE_Screen_Sed::save_diplomacy_in_scenario(v2, v2->player_num - 1);
        break;
      case 8:
        v50 = v2->map_view;
        if ( v3 )
        {
          (*(void (__stdcall **)(_DWORD))&v50->vfptr->gap10[4])(0);
          v51 = *(_DWORD *)v2->options_button[0];
          v52 = T_Scenario::GetScenarioOption((T_Scenario *)v2->world->scenario, 2);
          (*(void (__thiscall **)(TButtonPanel *, int))(v51 + 224))(v2->options_button[0], v52);
          TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(v2);
          v53 = v2->player_num;
          if ( v53 )
            TDropDownPanel::setCurrentLineNumber(v2->options_player_list, v53 - 1);
          else
            TDropDownPanel::setCurrentLineNumber(v2->options_player_list, 0);
        }
        else
        {
          (*(void (__stdcall **)(signed int))&v50->vfptr->gap10[4])(1);
          TRIBE_Screen_Sed::SaveDisabledItemsInScenario(v2);
        }
        v54 = (int)v2->options_button;
        v55 = 1;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v54 - 4) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v54 + 20))(v3);
          v54 += 4;
          --v55;
        }
        while ( v55 );
        (*(void (__stdcall **)(int))&v2->options_player_list->vfptr->gap10[4])(v3);
        if ( v3 )
          TDropDownPanel::set_line(v2->options_player_list, v2->player_num - 1);
        else
          v2->player_num = TDropDownPanel::get_line(v2->options_player_list) + 1;
        (*(void (__stdcall **)(int))&v2->options_disable_tech_text->vfptr->gap10[4])(v3);
        v56 = (int)v2->options_disable_text;
        v57 = 16;
        do
        {
          (*(void (__stdcall **)(int))(**(_DWORD **)(v56 - 64) + 20))(v3);
          (*(void (__stdcall **)(int))(**(_DWORD **)v56 + 20))(v3);
          v56 += 4;
          --v57;
        }
        while ( v57 );
        break;
      default:
        break;
    }
    v59 = __OFSUB__(activate_counter + 1, 2);
    v58 = activate_counter++ - 1 < 0;
  }
  while ( v58 ^ v59 );
  if ( new_mode != 11 )
  {
    v2->scenario_mode = new_mode;
    if ( new_mode )
      TButtonPanel::set_radio_button(*((TButtonPanel **)&v2->bottom_panel + new_mode));
    v60 = v2->vfptr;
    v2->vfptr->handle_size((TPanel *)v2, v2->pnl_wid, v2->pnl_hgt);
    v60->set_redraw((TPanel *)v2, RedrawNormal);
  }
  v2->valid_save_spot_flag = 1;
}

//----- (004AA730) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_paint_object_mode(TRIBE_Screen_Sed *this)
{
  _DWORD *v1; // edx@1
  signed int v2; // esi@1
  int v3; // eax@1
  int v4; // eax@2

  v1 = this;
  v2 = 0;
  v3 = rge_base_game->master_obj_id;
  if ( v3 != -1 )
  {
    v1 = this->world->players[this->player_num]->master_objects;
    v4 = v1[v3];
    if ( v4 )
    {
      if ( *(_BYTE *)(v4 + 4) == 80 )
      {
        LOBYTE(v1) = *(_BYTE *)(v4 + 364);
        if ( (_BYTE)v1 )
          v2 = 1;
      }
    }
  }
  if ( v2 )
    (*(void (__fastcall **)(RGE_Base_Game *, void *, signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(
      rge_base_game,
      v1,
      21,
      0);
  else
    (*(void (__stdcall **)(signed int, int))&rge_base_game->vfptr->gap8[8])(8, rge_base_game->sub_game_mode);
}

//----- (004AA7A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_map_type(TRIBE_Screen_Sed *this, TRIBE_Screen_Sed::MapType new_val, int activate_panels)
{
  TRIBE_Screen_Sed *v3; // edi@1
  signed int v4; // ebp@1
  TRIBE_Screen_Sed::MapType v5; // eax@3
  signed int v6; // esi@3
  int v7; // eax@7
  int v8; // eax@8
  void *v9; // ecx@12

  v3 = this;
  v4 = 0;
  do
  {
    if ( !v4 )
    {
      v5 = v3->map_type;
      v6 = 0;
      goto LABEL_7;
    }
    if ( new_val == MapTypeNone )
      return;
    if ( !activate_panels )
      break;
    v5 = new_val;
    v6 = 1;
LABEL_7:
    v7 = v5 - 1;
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          (*(void (__stdcall **)(signed int))&v3->map_size_label->vfptr->gap10[4])(v6);
          (*(void (__stdcall **)(signed int))&v3->map_size_drop->vfptr->gap10[4])(v6);
          (*(void (__stdcall **)(signed int))&v3->map_style_label->vfptr->gap10[4])(v6);
          (*(void (__stdcall **)(signed int))&v3->map_style_drop->vfptr->gap10[4])(v6);
          (*(void (__stdcall **)(signed int))&v3->random_seed_label->vfptr->gap10[4])(v6);
          (*(void (__stdcall **)(signed int))&v3->random_seed_input->vfptr->gap10[4])(v6);
          if ( v6 )
            TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->random_seed_input->vfptr);
        }
        goto LABEL_15;
      }
      (*(void (__stdcall **)(signed int))&v3->map_size_label->vfptr->gap10[4])(v6);
      (*(void (__stdcall **)(signed int))&v3->map_size_drop->vfptr->gap10[4])(v6);
      (*(void (__stdcall **)(signed int))&v3->map_style_label->vfptr->gap10[4])(v6);
      (*(void (__stdcall **)(signed int))&v3->map_style_drop->vfptr->gap10[4])(v6);
      (*(void (__stdcall **)(signed int))&v3->random_seed_used_label->vfptr->gap10[4])(v6);
      v9 = v3->random_seed_used_text;
    }
    else
    {
      (*(void (__stdcall **)(signed int))&v3->map_size_label->vfptr->gap10[4])(v6);
      (*(void (__stdcall **)(signed int))&v3->map_size_drop->vfptr->gap10[4])(v6);
      (*(void (__stdcall **)(signed int))&v3->default_terrain_label->vfptr->gap10[4])(v6);
      v9 = v3->default_terrain_drop;
    }
    (*(void (__stdcall **)(signed int))(*(_DWORD *)v9 + 20))(v6);
LABEL_15:
    ++v4;
  }
  while ( v4 < 2 );
  v3->map_type = new_val;
  TButtonPanel::set_radio_button(*(&v3->help_button + new_val));
  ((void (__stdcall *)(signed int))v3->bottom_panel->vfptr->set_redraw)(1);
}

//----- (004AA8F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_mp_victory_type(TRIBE_Screen_Sed *this, TRIBE_Screen_Sed::VictoryType new_val, int activate_panels)
{
  int v3; // eax@1
  TRIBE_Screen_Sed *v4; // edi@1
  TRIBE_Screen_Sed::VictoryType v5; // eax@3
  signed int v6; // esi@3
  int v7; // ebx@10
  signed int v8; // ebp@10
  int v9; // ebx@12
  signed int v10; // ebp@12
  bool v11; // sf@16
  unsigned __int8 v12; // of@16
  int activate_counter; // [sp+34h] [bp-4h]@1

  v3 = 0;
  v4 = this;
  activate_counter = 0;
  do
  {
    if ( v3 )
    {
      v5 = new_val;
      if ( new_val == VictoryTypeNone )
        return;
      if ( !activate_panels )
        goto LABEL_18;
      v6 = 1;
    }
    else
    {
      v5 = v4->mp_victory_type;
      v6 = 0;
    }
    switch ( v5 )
    {
      case 3:
        (*(void (__stdcall **)(signed int))&v4->victory_score_label->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_score->vfptr->gap10[4])(v6);
        break;
      case 4:
        (*(void (__stdcall **)(signed int))&v4->victory_time_label->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_time->vfptr->gap10[4])(v6);
        break;
      case 5:
        v7 = (int)v4->victory_cond_on;
        v8 = 5;
        do
        {
          (*(void (__stdcall **)(signed int))(**(_DWORD **)v7 + 20))(v6);
          v7 += 4;
          --v8;
        }
        while ( v8 );
        v9 = (int)v4->victory_text_and_or;
        v10 = 2;
        do
        {
          (*(void (__stdcall **)(signed int))(**(_DWORD **)(v9 - 20) + 20))(v6);
          (*(void (__stdcall **)(signed int))(**(_DWORD **)v9 + 20))(v6);
          v9 += 4;
          --v10;
        }
        while ( v10 );
        (*(void (__stdcall **)(signed int))&v4->victory_amount_label->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_label_conquest->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_label_explore->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_label_ruins->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_label_artifacts->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_label_discoveries->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_condition_explore->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_condition_ruins->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_condition_artifacts->vfptr->gap10[4])(v6);
        (*(void (__stdcall **)(signed int))&v4->victory_condition_discoveries->vfptr->gap10[4])(v6);
        if ( v6 == 1 )
          TPanel::set_curr_child(v4->bottom_panel, (TPanel *)&v4->victory_condition_explore->vfptr);
        break;
      default:
        break;
    }
    v3 = activate_counter + 1;
    v12 = __OFSUB__(activate_counter + 1, 2);
    v11 = activate_counter++ - 1 < 0;
  }
  while ( v11 ^ v12 );
  v5 = new_val;
LABEL_18:
  v4->mp_victory_type = v5;
  TButtonPanel::set_radio_button((TButtonPanel *)v4->victory_cond_type_label[v5 + 4]);
  ((void (__stdcall *)(signed int))v4->bottom_panel->vfptr->set_redraw)(1);
}

//----- (004AAA90) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_brush_size(TRIBE_Screen_Sed *this, TRIBE_Screen_Sed::BrushSize new_val)
{
  TRIBE_Screen_Sed *v2; // esi@1

  v2 = this;
  if ( new_val )
  {
    this->brush_size = new_val;
    TButtonPanel::set_radio_button(*((TButtonPanel **)&this->brush_size_label + new_val));
    switch ( v2->brush_size )
    {
      case 1:
        rge_base_game->brush_size = 1;
        break;
      case 2:
        rge_base_game->brush_size = 3;
        break;
      case 3:
        rge_base_game->brush_size = 5;
        break;
      case 4:
        rge_base_game->brush_size = 7;
        break;
      case 5:
        rge_base_game->brush_size = 9;
        break;
      default:
        rge_base_game->brush_size = 2;
        break;
    }
  }
}

//----- (004AAB60) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_paint_type(TRIBE_Screen_Sed *this, TRIBE_Screen_Sed::PaintType new_val, int activate_panels)
{
  TRIBE_Screen_Sed *v3; // esi@1
  signed int v4; // edi@3
  TRIBE_Screen_Sed::PaintType v5; // eax@4
  int v6; // ebx@7
  signed int v7; // ebp@7
  int v8; // ebx@12
  signed int v9; // ebp@12
  __int16 v10; // ax@15
  __int16 v11; // ax@17
  __int16 v12; // ax@19
  bool v13; // sf@21
  unsigned __int8 v14; // of@21
  int activate_counter; // [sp+2Ch] [bp-8h]@1
  TRIBE_Screen_Sed::PaintType val; // [sp+30h] [bp-4h]@3

  v3 = this;
  activate_counter = 0;
  do
  {
    if ( activate_counter )
    {
      v5 = new_val;
      if ( new_val == PaintTypeNone )
        return;
      if ( !activate_panels )
        goto LABEL_23;
      val = new_val;
      v4 = 1;
    }
    else
    {
      v4 = 0;
      val = v3->paint_type;
    }
    (*(void (__stdcall **)(signed int))&v3->brush_size_label->vfptr->gap10[4])(v4);
    v6 = (int)v3->brush_size_button_label;
    v7 = 5;
    do
    {
      (*(void (__stdcall **)(signed int))(**(_DWORD **)(v6 - 20) + 20))(v4);
      (*(void (__stdcall **)(signed int))(**(_DWORD **)v6 + 20))(v4);
      v6 += 4;
      --v7;
    }
    while ( v7 );
    if ( val == 1 )
    {
      (*(void (__stdcall **)(signed int))&v3->paint_terrain_list->vfptr->gap10[4])(v4);
      (*(void (__stdcall **)(signed int))&v3->paint_terrain_label->vfptr->gap10[4])(v4);
      if ( v4 )
      {
        v12 = TTextPanel::currentLineNumber((TTextPanel *)&v3->paint_terrain_list->vfptr);
        TRIBE_Screen_Sed::set_terrain(v3, v12);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(9, 0);
        goto LABEL_21;
      }
    }
    else if ( val == 2 )
    {
      (*(void (__stdcall **)(signed int))&v3->paint_elevation_list->vfptr->gap10[4])(v4);
      (*(void (__stdcall **)(_DWORD))&v3->paint_terrain_label->vfptr->gap10[4])(v4);
      if ( v4 )
      {
        v11 = TTextPanel::currentLineNumber((TTextPanel *)&v3->paint_elevation_list->vfptr);
        TRIBE_Screen_Sed::set_elevation(v3, v11);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(10, 0);
        goto LABEL_21;
      }
    }
    else
    {
      if ( val != 3 )
        goto LABEL_21;
      (*(void (__stdcall **)(_DWORD))&v3->paint_elevation_list->vfptr->gap10[4])(0);
      (*(void (__stdcall **)(_DWORD))&v3->paint_terrain_list->vfptr->gap10[4])(0);
      (*(void (__stdcall **)(_DWORD))&v3->paint_terrain_label->vfptr->gap10[4])(0);
      (*(void (__stdcall **)(_DWORD))&v3->brush_size_label->vfptr->gap10[4])(0);
      v8 = (int)v3->brush_size_button_label;
      v9 = 5;
      do
      {
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(v8 - 20) + 20))(0);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v8 + 20))(0);
        v8 += 4;
        --v9;
      }
      while ( v9 );
      if ( v4 )
      {
        v10 = TTextPanel::currentLineNumber((TTextPanel *)&v3->paint_elevation_list->vfptr);
        TRIBE_Screen_Sed::set_elevation(v3, v10);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(19, 0);
        goto LABEL_21;
      }
    }
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
LABEL_21:
    v14 = __OFSUB__(activate_counter + 1, 2);
    v13 = activate_counter++ - 1 < 0;
  }
  while ( v13 ^ v14 );
  v5 = new_val;
LABEL_23:
  v3->paint_type = v5;
  TButtonPanel::set_radio_button(*((TButtonPanel **)&v3->paint_type_label + v5));
  ((void (__stdcall *)(signed int))v3->bottom_panel->vfptr->set_redraw)(1);
}

//----- (004AAD50) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_terrain(TRIBE_Screen_Sed *this, __int16 val)
{
  __int16 v2; // ax@2

  switch ( val )
  {
    case 1:
      v2 = 6;
      break;
    case 2:
      v2 = 10;
      break;
    case 3:
      v2 = 1;
      break;
    case 4:
      v2 = 13;
      break;
    case 5:
      v2 = 20;
      break;
    case 6:
      v2 = 4;
      break;
    case 7:
      v2 = 19;
      break;
    case 8:
      v2 = 22;
      break;
    default:
      v2 = 0;
      break;
  }
  rge_base_game->terrain_id = v2;
  TListPanel::scroll_cur_line(this->paint_terrain_list, 1, val, 1);
}

//----- (004AADF0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_elevation(TRIBE_Screen_Sed *this, __int16 val)
{
  rge_base_game->elevation_height = val;
  TListPanel::scroll_cur_line(this->paint_elevation_list, 1, val, 1);
}

//----- (004AAE20) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_player(TRIBE_Screen_Sed *this, int val, char save_player, char load_player)
{
  TRIBE_Screen_Sed *v4; // esi@1
  int v5; // edi@1
  RGE_Player *v6; // eax@3
  const char *v7; // eax@4
  const char *v8; // eax@4
  const char *v9; // eax@4
  const char *v10; // eax@4
  char *v11; // eax@4
  int v12; // eax@4
  int v13; // eax@4
  char *v14; // eax@4
  char *v15; // eax@4
  char *v16; // eax@4
  int v17; // edi@5
  int v18; // eax@7
  int v19; // eax@7
  int v20; // eax@7
  int v21; // eax@7
  PlayerName *v22; // eax@7
  int v23; // eax@7
  int v24; // eax@7
  char *v25; // eax@7
  int v26; // eax@7
  char *v27; // eax@8
  char *v28; // eax@8
  char *v29; // eax@9
  int v30; // eax@9
  char *v31; // eax@10
  char *v32; // eax@10
  char *v33; // eax@11
  int v34; // eax@11
  char *v35; // eax@12
  char *v36; // eax@12
  char str[30]; // [sp+Ch] [bp-20h]@7
  signed int save_playera; // [sp+34h] [bp+8h]@4
  signed int save_playerb; // [sp+34h] [bp+8h]@4
  signed int save_playerc; // [sp+34h] [bp+8h]@4
  signed int save_playerd; // [sp+34h] [bp+8h]@4

  v4 = this;
  v5 = this->player_num - 1;
  if ( v5 < 0 )
    v5 = 0;
  v6 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(v6);
  if ( save_player )
  {
    v7 = TEditPanel::currentLine(v4->player_inven_input[0]);
    save_playera = atoi(v7);
    T_Scenario::Set_player_Food((T_Scenario *)v4->world->scenario, v5, save_playera);
    *v4->world->players[v4->player_num]->attributes = (double)save_playera;
    v8 = TEditPanel::currentLine(v4->player_inven_input[1]);
    save_playerb = atoi(v8);
    T_Scenario::Set_player_Wood((T_Scenario *)v4->world->scenario, v5, save_playerb);
    v4->world->players[v4->player_num]->attributes[1] = (double)save_playerb;
    v9 = TEditPanel::currentLine(v4->player_inven_input[2]);
    save_playerc = atoi(v9);
    T_Scenario::Set_player_Stone((T_Scenario *)v4->world->scenario, v5, save_playerc);
    v4->world->players[v4->player_num]->attributes[2] = (double)save_playerc;
    v10 = TEditPanel::currentLine(v4->player_inven_input[3]);
    save_playerd = atoi(v10);
    T_Scenario::Set_player_Gold((T_Scenario *)v4->world->scenario, v5, save_playerd);
    v4->world->players[v4->player_num]->attributes[3] = (double)save_playerd;
    v11 = TEditPanel::currentLine(v4->player_inven_input[4]);
    RGE_Scenario::SetPlayerName(v4->world->scenario, v5, v11);
    v12 = TDropDownPanel::currentLineNumber(v4->player_setting_drop[0]);
    RGE_Scenario::Set_player_Type(v4->world->scenario, v5, v12);
    v13 = TDropDownPanel::currentLineNumber(v4->player_setting_drop[1]);
    RGE_Scenario::Set_player_Civ(v4->world->scenario, v5, v13 + 1);
    v14 = TDropDownPanel::currentLine(v4->AiRules);
    RGE_Scenario::Set_player_AI(v4->world->scenario, v5, v14, 0);
    v15 = TDropDownPanel::currentLine(v4->BuildList);
    RGE_Scenario::Set_BuildList(v4->world->scenario, v5, v15, 0);
    v16 = TDropDownPanel::currentLine(v4->CityLayout);
    RGE_Scenario::Set_CityPlan(v4->world->scenario, v5, v16, 0);
  }
  v17 = (signed __int16)val - 1;
  v4->player_num = val;
  if ( (_WORD)val )
  {
    TDropDownPanel::set_line(v4->player_list, v17);
    (*(void (__stdcall **)(_DWORD))&rge_base_game->vfptr->gap8[12])(val);
    if ( load_player == 1 )
    {
      v18 = T_Scenario::Get_player_Food((T_Scenario *)v4->world->scenario, v17);
      sprintf(str, aD_3, v18);
      TEditPanel::set_text(v4->player_inven_input[0], str);
      v19 = T_Scenario::Get_player_Wood((T_Scenario *)v4->world->scenario, v17);
      sprintf(str, aD_3, v19);
      TEditPanel::set_text(v4->player_inven_input[1], str);
      v20 = T_Scenario::Get_player_Stone((T_Scenario *)v4->world->scenario, v17);
      sprintf(str, aD_3, v20);
      TEditPanel::set_text(v4->player_inven_input[2], str);
      v21 = T_Scenario::Get_player_Gold((T_Scenario *)v4->world->scenario, v17);
      sprintf(str, aD_3, v21);
      TEditPanel::set_text(v4->player_inven_input[3], str);
      v22 = RGE_Scenario::GetPlayerName(v4->world->scenario, v17);
      TEditPanel::set_text(v4->player_inven_input[4], v22->Name);
      v23 = RGE_Scenario::Get_player_Type(v4->world->scenario, v17);
      TDropDownPanel::setCurrentLineNumber(v4->player_setting_drop[0], v23);
      v24 = RGE_Scenario::Get_player_Civ(v4->world->scenario, v17);
      TDropDownPanel::setCurrentLineNumber(v4->player_setting_drop[1], v24 - 1);
      v25 = RGE_Scenario::Get_player_AI(v4->world->scenario, v17, 0);
      v26 = TDropDownPanel::get_line(v4->AiRules, v25);
      if ( v26 == -1 )
      {
        v27 = RGE_Scenario::Get_player_AI(v4->world->scenario, v17, 0);
        TDropDownPanel::append_line(v4->AiRules, v27, 0);
        v28 = RGE_Scenario::Get_player_AI(v4->world->scenario, v17, 0);
        v26 = TDropDownPanel::get_line(v4->AiRules, v28);
      }
      TDropDownPanel::setCurrentLineNumber(v4->AiRules, v26);
      v29 = RGE_Scenario::Get_BuildList(v4->world->scenario, v17, 0);
      v30 = TDropDownPanel::get_line(v4->BuildList, v29);
      if ( v30 == -1 )
      {
        v31 = RGE_Scenario::Get_BuildList(v4->world->scenario, v17, 0);
        TDropDownPanel::append_line(v4->BuildList, v31, 0);
        v32 = RGE_Scenario::Get_BuildList(v4->world->scenario, v17, 0);
        v30 = TDropDownPanel::get_line(v4->BuildList, v32);
      }
      TDropDownPanel::setCurrentLineNumber(v4->BuildList, v30);
      v33 = RGE_Scenario::Get_CityPlan(v4->world->scenario, v17, 0);
      v34 = TDropDownPanel::get_line(v4->CityLayout, v33);
      if ( v34 == -1 )
      {
        v35 = RGE_Scenario::Get_CityPlan(v4->world->scenario, v17, 0);
        TDropDownPanel::append_line(v4->CityLayout, v35, 0);
        v36 = RGE_Scenario::Get_CityPlan(v4->world->scenario, v17, 0);
        v34 = TDropDownPanel::get_line(v4->CityLayout, v36);
      }
      TDropDownPanel::setCurrentLineNumber(v4->CityLayout, v34);
    }
  }
}

//----- (004AB2B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_player_active(TRIBE_Screen_Sed *this, __int16 player_num_in, int active_in)
{
  RGE_Scenario::Set_player_Active(this->world->scenario, player_num_in, active_in);
}

//----- (004AB2D0) --------------------------------------------------------
int __cdecl TRIBE_Screen_Sed_unit_list_compare(void *arg1, void *arg2)
{
  int v2; // eax@1
  int result; // eax@2

  v2 = CompareStringA(0x400u, 1u, (PCNZCH)arg1, -1, (PCNZCH)arg2, -1);
  if ( v2 == 1 )
    result = -1;
  else
    result = v2 == 3;
  return result;
}

//----- (004AB300) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_unit_player(TRIBE_Screen_Sed *this, int val)
{
  TRIBE_Screen_Sed *v2; // ebx@1
  RGE_Game_World *v3; // eax@1
  __int16 v4; // di@1
  float v5; // ST24_4@1
  float v6; // ST28_4@1
  __int16 v7; // ST20_2@1
  RGE_Player *v8; // ebp@1
  int v9; // esi@1
  __int16 v10; // di@4
  int v11; // ecx@5
  int v12; // edx@5
  RGE_Master_Static_Object *v13; // eax@6
  __int16 v14; // ax@10
  TRIBE_Screen_Sed::List_Info *v15; // eax@11
  float v16; // edi@13
  int v17; // eax@14
  int v18; // edx@16
  int v19; // eax@16
  __int16 v20; // si@16
  _DWORD *v21; // esi@21
  char *v22; // ebp@23
  int v23; // eax@29
  __int16 v24; // di@31
  signed __int16 is_error; // [sp+10h] [bp-Ch]@12
  int is_errora; // [sp+10h] [bp-Ch]@22
  float save_view_x; // [sp+14h] [bp-8h]@13
  float save_view_xa; // [sp+14h] [bp-8h]@21
  signed __int16 end_i; // [sp+18h] [bp-4h]@4
  __int16 end_ia; // [sp+18h] [bp-4h]@22
  int vala; // [sp+20h] [bp+4h]@12
  int valb; // [sp+20h] [bp+4h]@22

  v2 = this;
  v3 = RGE_Base_Game::get_player(rge_base_game);
  v4 = LOWORD(v3[1].game_speed);
  v5 = v3[1].timer;
  v6 = *(float *)&v3[1].old_time;
  v7 = HIWORD(v3[1].game_speed);
  (*(void (__stdcall **)(int))&rge_base_game->vfptr->gap8[12])(val);
  v2->player_num = val;
  v8 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::set_view_loc(v8, v5, v6);
  RGE_Player::set_map_loc(v8, v4, v7);
  RGE_View::set_player((RGE_View *)&v2->main_view->vfptr, v8);
  RGE_Diamond_Map::set_player((RGE_Diamond_Map *)&v2->map_view->vfptr, v8);
  TDropDownPanel::setCurrentLineNumber(v2->unit_player_list, (signed __int16)val);
  TTextPanel::empty_list((TTextPanel *)&v2->unit_list->vfptr);
  v9 = 0;
  if ( v2->unit_list_info )
  {
    free(v2->unit_list_info);
    v2->unit_list_info = 0;
  }
  if ( v8 )
  {
    v2->unit_list_size = 1;
    v10 = v8->master_object_num;
    end_i = v10;
    if ( v10 > 0 )
    {
      v11 = 0;
      v12 = v10;
      do
      {
        v13 = v8->master_objects[v11];
        if ( v13 && !v13->hide_in_scenario_editor )
          ++v2->unit_list_size;
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    v14 = v2->unit_list_size;
    if ( v14 )
    {
      v15 = (TRIBE_Screen_Sed::List_Info *)calloc(v14, 0x66u);
      v2->unit_list_info = v15;
      if ( v15 )
      {
        v15->id = -1;
        TRIBE_Screen_Sed::set_string(v2->unit_list_info->text, 10101, 20);
        is_error = 1;
        vala = 0;
        if ( v10 > 0 )
        {
          v16 = 0.0;
          save_view_x = 0.0;
          do
          {
            v17 = *(int *)((char *)v8->master_objects + LODWORD(v16));
            if ( v17 && !*(_BYTE *)(v17 + 78) )
            {
              v18 = is_error;
              v2->unit_list_info[v18].id = v9;
              v19 = *(int *)((char *)v8->master_objects + LODWORD(v16));
              v20 = *(_WORD *)(v19 + 12);
              if ( v20 <= 0 )
              {
                strcpy(v2->unit_list_info[v18].text, *(const char **)(v19 + 8));
                v16 = save_view_x;
              }
              else
              {
                (*(void (__stdcall **)(_DWORD, int, signed int))&rge_base_game->vfptr->gap8[24])(
                  v20,
                  (int)&v2->unit_list_info[v18],
                  100);
              }
              v9 = vala;
              ++is_error;
            }
            ++v9;
            LODWORD(v16) += 4;
            vala = v9;
            save_view_x = v16;
          }
          while ( (signed __int16)v9 < end_i );
        }
        qsort(
          v2->unit_list_info,
          v2->unit_list_size,
          0x66u,
          (int (__cdecl *)(const void *, const void *))TRIBE_Screen_Sed_unit_list_compare);
        *(float *)&v21 = COERCE_FLOAT(calloc(v2->unit_list_size, 4u));
        save_view_xa = *(float *)&v21;
        if ( *(float *)&v21 != 0.0 )
        {
          is_errora = 0;
          end_ia = 0;
          valb = 0;
          if ( v2->unit_list_size > 0 )
          {
            while ( 1 )
            {
              v22 = (char *)calloc(0x64u, 1u);
              v21[(signed __int16)valb] = v22;
              if ( !v22 )
                break;
              strcpy(v22, v2->unit_list_info[(signed __int16)valb].text);
              if ( v2->unit_list_info[(signed __int16)valb].id == rge_base_game->master_obj_id )
                end_ia = valb;
              *(float *)&v21 = save_view_xa;
              if ( (signed __int16)++valb >= v2->unit_list_size )
                goto LABEL_29;
            }
            is_errora = 1;
          }
LABEL_29:
          HIWORD(v23) = HIWORD(is_errora);
          if ( !is_errora )
          {
            LOWORD(v23) = v2->unit_list_size;
            ((void (__stdcall *)(void *, int))v2->unit_list->vfptr[1].__vecDelDtor)(v21, v23);
            TListPanel::scroll_cur_line(v2->unit_list, 1, end_ia, 1);
          }
          v24 = 0;
          if ( v2->unit_list_size > 0 )
          {
            do
            {
              if ( v21[v24] )
                free((void *)v21[v24]);
              ++v24;
            }
            while ( v24 < v2->unit_list_size );
          }
          free(v21);
        }
      }
    }
  }
}

//----- (004AB670) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_unit(TRIBE_Screen_Sed *this, __int16 val)
{
  if ( val == -1 )
  {
    rge_base_game->master_obj_id = -1;
    TListPanel::scroll_cur_line(this->unit_list, 1, -1, 1);
  }
  else
  {
    rge_base_game->master_obj_id = this->unit_list_info[val].id;
    TListPanel::scroll_cur_line(this->unit_list, 1, val, 1);
  }
}

//----- (004AB6E0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_message_type(TRIBE_Screen_Sed *this, TRIBE_Screen_Sed::MessageType new_val, int activate_panels)
{
  TRIBE_Screen_Sed *v3; // esi@1

  v3 = this;
  (*(void (__stdcall **)(int))&this->message_input->vfptr->gap10[4])(activate_panels);
  ((void (__stdcall *)(signed int))v3->bottom_panel->vfptr->set_redraw)(1);
}

//----- (004AB710) --------------------------------------------------------
int __userpurge TRIBE_Screen_Sed::handle_size@<eax>(TRIBE_Screen_Sed *this@<ecx>, int a2@<ebp>, int win_wid, int win_hgt)
{
  TRIBE_Screen_Sed *v4; // esi@1

  v4 = this;
  TPanel::handle_size((TPanel *)&this->vfptr, win_wid, win_hgt);
  TRIBE_Screen_Sed::position_panels(v4, win_wid, a2, win_hgt);
  TPanel::handle_size((TPanel *)&v4->vfptr, win_wid, win_hgt);
  return 0;
}

//----- (004AB740) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::handle_idle(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  unsigned int v2; // edi@2

  v1 = this;
  if ( rge_base_game->prog_mode == 7 )
  {
    v2 = debug_timeGetTime();
    if ( v1->last_update_time - v2 >= v1->update_interval && !TPanelSystem::modalPanel(&panel_system) )
    {
      ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(1);
      if ( v1->last_map_redraw_time - v2 >= v1->map_redraw_interval )
      {
        ((void (__stdcall *)(signed int))v1->map_view->vfptr->set_redraw)(1);
        v1->last_map_redraw_time = v2;
      }
    }
  }
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004AB7D0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::key_down_action(TRIBE_Screen_Sed *this, int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  TRIBE_Screen_Sed *v6; // esi@1
  int result; // eax@5
  TRIBE_Screen_Sed::ScenarioMode v8; // eax@24
  int v9; // edi@24
  TRIBE_Screen_Sed::ScenarioMode v10; // eax@42
  TPanel *v11; // ecx@43
  TPanel *v12; // ecx@46
  TPanel *v13; // esi@47
  int v14; // edi@51
  RGE_Active_Sprite_List *v15; // ecx@52
  char v16; // bl@53
  RGE_Sprite *v17; // ecx@54

  v6 = this;
  if ( TPanelSystem::modalPanel(&panel_system) )
    return 0;
  if ( !ctrl_key )
  {
    switch ( key )
    {
      case 48:
      case 49:
      case 50:
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
      case 56:
        v8 = v6->scenario_mode;
        v9 = key - 48;
        if ( v8 == 8 && v9 > 0 )
        {
          TRIBE_Screen_Sed::SaveDisabledItemsInScenario(v6);
          TDropDownPanel::setCurrentLineNumber(v6->options_player_list, key - 49);
          v6->vfptr->action((TPanel *)v6, (TPanel *)v6->options_player_list, 3, 0, 0);
          TRIBE_Screen_Sed::set_player(v6, v9, 0, 0);
          v6->player_num = v9;
          TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(v6);
          return 0;
        }
        if ( v8 != 3 || v9 <= 0 )
        {
          if ( v8 == 4 )
          {
            TDropDownPanel::setCurrentLineNumber(v6->unit_player_list, v9);
            v6->vfptr->action((TPanel *)v6, (TPanel *)v6->unit_player_list, 0, 0, 0);
            return 0;
          }
          if ( v8 != 6 || v9 <= 0 )
          {
            if ( v8 == 5 )
            {
              if ( v9 <= 0 )
                return 0;
              TDropDownPanel::setCurrentLineNumber(v6->Diplomacy_player_list, key - 49);
              v6->vfptr->action((TPanel *)v6, (TPanel *)v6->Diplomacy_player_list, 1, 0, 0);
              result = 0;
            }
            else
            {
              if ( v9 <= 0 )
                return 0;
              TRIBE_Screen_Sed::set_player(v6, v9, 0, 0);
              v6->player_num = v9;
              result = 0;
            }
          }
          else
          {
            if ( v6->bottom_panel->curr_child )
              return 0;
            TDropDownPanel::setCurrentLineNumber(v6->victory_player_list, key - 49);
            v6->vfptr->action((TPanel *)v6, (TPanel *)v6->victory_player_list, 1, 0, 0);
            result = 0;
          }
        }
        else
        {
          if ( v6->bottom_panel->curr_child )
            return 0;
          TDropDownPanel::setCurrentLineNumber(v6->player_list, key - 49);
          v6->vfptr->action((TPanel *)v6, (TPanel *)v6->player_list, 0, 0, 0);
          result = 0;
        }
        return result;
      case 9:
        v10 = v6->scenario_mode;
        if ( v10 == 3 )
        {
          v11 = v6->bottom_panel;
          if ( v11->curr_child )
            return 0;
          TPanel::set_curr_child(v11, (TPanel *)&v6->player_inven_input[0]->vfptr);
          return 0;
        }
        if ( v10 == 6 )
        {
          v12 = v6->bottom_panel;
          if ( !v12->curr_child )
          {
            v13 = (TPanel *)&v6->victory_amount_input->vfptr;
            if ( v13->active )
            {
              TPanel::set_curr_child(v12, v13);
              return 0;
            }
          }
        }
        break;
      case 27:
        TRIBE_Screen_Sed::command_cancel();
        return 0;
      case 46:
        if ( v6->scenario_mode != 4 )
          return 0;
        v14 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num;
        if ( v14 )
        {
          v15 = *(RGE_Active_Sprite_List **)(v14 + 24);
          if ( v15 )
          {
            v16 = RGE_Active_Sprite_List::get_lowest_draw_level(v15);
          }
          else
          {
            v17 = *(RGE_Sprite **)(v14 + 16);
            v16 = v17 ? RGE_Sprite::get_lowest_draw_level(v17) : 20;
          }
          (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
          if ( !v16 )
            ((void (__stdcall *)(signed int))v6->main_view->vfptr->set_redraw)(2);
        }
        return 1;
      default:
        return 0;
    }
    return 0;
  }
  switch ( key )
  {
    case 65:
      if ( rge_base_game->outline_type == 3 )
      {
        rge_base_game->outline_type = 0;
        result = 1;
      }
      else
      {
        rge_base_game->outline_type = 3;
        result = 1;
      }
      return result;
    case 77:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[0] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeMap);
      return 0;
    case 84:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[1] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeTerrain);
      return 0;
    case 80:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[2] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModePlayers);
      return 0;
    case 85:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[3] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeUnits);
      return 0;
    case 68:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[4] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeDiplomacy);
      return 0;
    case 73:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[5] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeVictory);
      return 0;
    case 86:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[6] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeVictoryMulti);
      return 0;
    case 79:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[7] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeOptions);
      return 0;
    case 87:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[8] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeMessages);
      return 0;
    case 67:
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v6->scenario_mode_button[9] + 224))(1);
      TRIBE_Screen_Sed::set_scenario_mode(v6, ScenarioModeCinematics);
      return 0;
    case 66:
      ++View_Grid_Mode;
      if ( RGE_Base_Game::gameDeveloperMode(rge_base_game) )
      {
        if ( View_Grid_Mode <= 4 )
          goto LABEL_22;
      }
      else if ( View_Grid_Mode <= 1 )
      {
        goto LABEL_22;
      }
      View_Grid_Mode = 0;
LABEL_22:
      ((void (__stdcall *)(signed int))v6->main_view->vfptr->set_redraw)(2);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}
// 87D7B4: using guessed type int View_Grid_Mode;

//----- (004ABCD0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::action(TRIBE_Screen_Sed *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TRIBE_Screen_Sed *v5; // esi@1
  RGE_Static_Object *v7; // ST0C_4@5
  RGE_Player *v8; // eax@5
  RGE_Static_Object *v9; // ST0C_4@7
  RGE_Player *v10; // eax@7
  int v11; // ebx@8
  RGE_Player *v12; // eax@26
  RGE_Static_Object *v13; // ST0C_4@31
  RGE_Player *v14; // eax@31
  RGE_Static_Object *v15; // esi@32
  RGE_Player *v16; // eax@33
  signed int v17; // eax@41
  TPanel **v18; // ecx@41
  signed int v19; // eax@48
  TPanel **v20; // ecx@48
  int v21; // ST10_4@61
  char *v22; // eax@61
  signed int v23; // eax@61
  TPanel **v24; // ecx@61
  char *v25; // eax@66
  __int16 v26; // ax@77
  int v27; // eax@77
  TDropDownPanel *v28; // ecx@82
  int v29; // eax@83
  int v30; // edi@86
  RGE_Player *v31; // eax@87
  RGE_Player *v32; // eax@89
  RGE_Player *v33; // eax@91
  RGE_Static_Object *v34; // esi@91
  TPanel *v35; // eax@92
  RGE_Player *v36; // eax@94
  RGE_Static_Object *v37; // esi@94
  RGE_Player *v38; // eax@95
  RGE_Player *v39; // eax@98
  RGE_Player *v40; // eax@100
  double v41; // st7@103
  double v42; // st6@103
  char v44; // c3@103
  RGE_Player *v45; // eax@104
  RGE_Player *v46; // eax@104
  TDropDownPanel *v47; // ecx@105
  int v48; // eax@106
  int v49; // edi@107
  TPanel **v50; // ebx@107
  int v51; // eax@110
  RGE_Player *v52; // eax@110
  int v53; // eax@110
  RGE_Static_Object *v54; // ST0C_4@111
  RGE_Player *v55; // eax@111
  RGE_Static_Object *v56; // ST0C_4@113
  RGE_Player *v57; // eax@113
  signed int v58; // eax@119
  TPanel **v59; // ecx@119
  int v60; // edi@125
  int v61; // edi@126
  int v62; // ebx@133
  TRIBE_Screen_Sed::MapType v63; // eax@133
  int v64; // ebx@133
  const char *v65; // eax@145
  signed int v66; // ebp@147
  int v67; // ebp@150
  signed int v68; // edi@150
  signed int v69; // edi@152
  TTextPanel *v70; // ecx@159
  __int16 v71; // ax@160
  TTextPanel *v72; // ecx@161
  __int16 v73; // ax@162
  signed int v74; // eax@166
  TPanel **v75; // ecx@166
  signed int v76; // eax@169
  TPanel **v77; // ecx@169
  int v78; // eax@178
  TPanel **v79; // ecx@178
  TDropDownPanel *v80; // ecx@185
  int v81; // eax@188
  TDropDownPanel *v82; // ecx@189
  int v83; // eax@190
  int v84; // eax@190
  int v85; // eax@190
  int v86; // ecx@192
  TDropDownPanel *v87; // ecx@194
  int v88; // eax@195
  TPanel *v89; // ecx@201
  int v90; // eax@202
  int v91; // eax@202
  RGE_Base_GameVtbl *v92; // edx@202
  __int16 v93; // di@206
  RGE_Game_World *v94; // ST10_4@206
  RGE_Master_Static_Object *v95; // ST0C_4@206
  TTextPanel *v96; // ecx@211
  __int16 v97; // ax@212
  RGE_Base_Game *v98; // ecx@212
  int v99; // eax@212
  __int16 v100; // di@217
  RGE_Game_World *v101; // ST10_4@217
  RGE_Master_Static_Object *v102; // ST0C_4@217
  RGE_Player *v103; // eax@224
  signed int v104; // edi@232
  TPanel **v105; // eax@232
  __int16 v106; // ax@243
  int v107; // eax@243
  TButtonPanel *v108; // ecx@249
  int v109; // eax@250
  int v110; // eax@256
  TRIBE_Screen_Sed_Open *v111; // eax@264
  int x2; // [sp+14h] [bp-34h]@103
  int x1; // [sp+18h] [bp-30h]@103
  int y1; // [sp+1Ch] [bp-2Ch]@103
  int y2; // [sp+20h] [bp-28h]@103
  char random_val[24]; // [sp+24h] [bp-24h]@149
  float v117; // [sp+44h] [bp-4h]@264
  TPanel *from_panela; // [sp+4Ch] [bp+4h]@103
  TPanel *from_panelb; // [sp+4Ch] [bp+4h]@144
  float old_seed; // [sp+50h] [bp+8h]@103
  int old_seedb; // [sp+50h] [bp+8h]@104
  int old_seeda; // [sp+50h] [bp+8h]@125
  int old_seedc; // [sp+50h] [bp+8h]@151
  int map_size; // [sp+54h] [bp+Ch]@104

  v5 = this;
  if ( !from_panel )
    return 0;
  if ( from_panel != (TPanel *)this->main_view )
  {
    if ( this->SelectedObject )
    {
      v7 = this->SelectedObject;
      v8 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_one_object(v8, v7, 0);
    }
    if ( v5->DestinationObject )
    {
      v9 = v5->DestinationObject;
      v10 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::select_one_object(v10, v9, 0);
    }
  }
  v11 = action_in;
  if ( !action_in
    && (from_panel == (TPanel *)v5->random_seed_input
     || from_panel == (TPanel *)v5->player_inven_input[0]
     || from_panel == (TPanel *)v5->player_inven_input[1]
     || from_panel == (TPanel *)v5->player_inven_input[2]
     || from_panel == (TPanel *)v5->player_inven_input[3]
     || from_panel == (TPanel *)v5->player_inven_input[4]
     || from_panel == (TPanel *)v5->player_setting_label[0]
     || from_panel == (TPanel *)v5->victory_condition_explore
     || from_panel == (TPanel *)v5->victory_condition_ruins
     || from_panel == (TPanel *)v5->victory_condition_artifacts
     || from_panel == (TPanel *)v5->victory_condition_discoveries
     || from_panel == (TPanel *)v5->victory_condition_gold
     || from_panel == (TPanel *)v5->victory_amount_input
     || from_panel == (TPanel *)v5->message_input) )
  {
    v5->need_to_save_flag = 1;
  }
  if ( from_panel == (TPanel *)v5->main_view )
  {
    if ( action_in == 16 )
    {
      v12 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::unselect_object(v12);
      if ( v5->SelectRegionFlag == 1 )
        v5->SelectedObject = (RGE_Static_Object *)action_val1;
      if ( v5->SelectRegionFlag == 2 )
        v5->DestinationObject = (RGE_Static_Object *)action_val1;
      if ( v5->SelectedObject )
      {
        v13 = v5->SelectedObject;
        v14 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::select_one_object(v14, v13, 0);
      }
      v15 = v5->DestinationObject;
      if ( v15 )
      {
        v16 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::select_one_object(v16, v15, 0);
      }
      (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
      return 1;
    }
    if ( action_in == 17 && rge_base_game->game_mode == 17 )
      (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
  }
  if ( action_in != 1 )
  {
    v19 = 0;
    v20 = (TPanel **)v5->scenario_mode_button;
    do
    {
      if ( from_panel == *v20 )
        return 1;
      ++v19;
      ++v20;
    }
    while ( v19 < 10 );
    if ( from_panel != (TPanel *)v5->menu_button && from_panel != (TPanel *)v5->help_button )
      goto LABEL_53;
    return 1;
  }
  v17 = 0;
  v18 = (TPanel **)v5->scenario_mode_button;
  do
  {
    if ( from_panel == *v18 )
    {
      TRIBE_Screen_Sed::set_scenario_mode(v5, (TRIBE_Screen_Sed::ScenarioMode)(v17 + 1));
      return 1;
    }
    ++v17;
    ++v18;
  }
  while ( v17 < 10 );
  if ( from_panel == (TPanel *)v5->menu_button )
  {
    TRIBE_Screen_Sed::command_menu(v5);
    return 1;
  }
  if ( from_panel == (TPanel *)v5->help_button )
  {
    TEasy_Panel::setup_popup_help((TEasy_Panel *)&v5->vfptr);
    return 1;
  }
LABEL_53:
  if ( TPanel::panelName(from_panel) && !strcmp(TPanel::panelName(from_panel), aOkdialog) )
  {
    if ( !action_in )
    {
      TPanelSystem::destroyPanel(&panel_system, aOkdialog);
      TRIBE_Screen_Sed::set_scenario_mode(v5, ScenarioModePlayers);
    }
    return 1;
  }
  switch ( v5->scenario_mode )
  {
    case 9:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in != 1 )
        goto LABEL_251;
      v21 = v5->current_message;
      v22 = TEditPanel::get_input_buffer(v5->message_input);
      RGE_Scenario::Set_message(v5->world->scenario, v22, v21);
      v23 = 0;
      v24 = (TPanel **)v5->message_button;
      while ( from_panel != *v24 )
      {
        ++v23;
        ++v24;
        if ( v23 >= 5 )
          goto LABEL_66;
      }
      v5->current_message = v23;
LABEL_66:
      v25 = RGE_Scenario::Get_message(v5->world->scenario, v5->current_message);
      TEditPanel::set_text(v5->message_input, v25);
      switch ( v5->current_message )
      {
        case 0:
          TPanel::set_help_info((TPanel *)&v5->message_input->vfptr, 30576, -1);
          break;
        case 1:
          TPanel::set_help_info((TPanel *)&v5->message_input->vfptr, 30577, -1);
          break;
        case 2:
          TPanel::set_help_info((TPanel *)&v5->message_input->vfptr, 30578, -1);
          break;
        case 3:
          TPanel::set_help_info((TPanel *)&v5->message_input->vfptr, 30579, -1);
          break;
        case 4:
          TPanel::set_help_info((TPanel *)&v5->message_input->vfptr, 30580, -1);
          break;
        default:
          goto LABEL_251;
      }
      goto LABEL_251;
    case 6:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( (!action_in || action_in == 1) && from_panel == (TPanel *)v5->victory_player_list )
      {
        TRIBE_Screen_Sed::save_victory_cond_in_scenario(v5, v5->CurrentVictory);
        TRIBE_Screen_Sed::activate_victory_panel(v5, 0);
        TRIBE_Screen_Sed::activate_victory_proper_fields(v5, 0, 0);
        v26 = TDropDownPanel::get_line(v5->victory_player_list) + 1;
        v5->player_num = v26;
        T_Scenario::SetSPWhich((T_Scenario *)v5->world->scenario, v26 - 1);
        v5->CurrentVictory = 0;
        TRIBE_Screen_Sed::load_victory_cond_from_scenario(v5, 0);
        TRIBE_Screen_Sed::activate_victory_panel(v5, 1);
        v27 = TDropDownPanel::get_line(v5->victory_drop_down);
        TRIBE_Screen_Sed::activate_victory_proper_fields(v5, v27, 1);
      }
      if ( !action_in && from_panel == (TPanel *)v5->victory_amount_input )
        TPanel::set_curr_child(v5->bottom_panel, 0);
      if ( action_in == 2 )
      {
        v28 = v5->victory_drop_down;
        if ( (TDropDownPanel *)from_panel == v28 )
        {
          v29 = TDropDownPanel::get_line(v28);
          TRIBE_Screen_Sed::activate_victory_proper_fields(v5, v29, 1);
        }
      }
      if ( action_in != 1 )
        goto LABEL_251;
      if ( from_panel == (TPanel *)v5->victory_amount_input )
        return 1;
      v30 = TDropDownPanel::get_line(v5->victory_drop_down);
      if ( from_panel == (TPanel *)v5->victory_drop_down )
      {
        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
        v5->DestinationObject = 0;
        v5->SelectedObject = 0;
        v31 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(v31);
      }
      if ( v30 == 2 )
      {
        v5->DestinationObject = 0;
        v32 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(v32);
      }
      if ( from_panel == (TPanel *)v5->victory_button_set_object )
      {
        v5->SelectRegionFlag = 1;
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(16, 0);
        v33 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(v33);
        v34 = v5->DestinationObject;
        goto LABEL_99;
      }
      v35 = (TPanel *)v5->victory_button_set_destination;
      if ( from_panel == v35 )
      {
        if ( v30 != 1 )
        {
          v5->SelectRegionFlag = 3;
          v36 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(v36);
          v37 = v5->SelectedObject;
          if ( v37 )
          {
            v38 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::select_one_object(v38, v37, 0);
          }
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(17, 0);
          return 1;
        }
        if ( from_panel == v35 )
        {
          v5->SelectRegionFlag = 2;
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(16, 0);
          v39 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(v39);
          v34 = v5->SelectedObject;
LABEL_99:
          if ( v34 )
          {
            v40 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::select_one_object(v40, v34, 0);
          }
          return 1;
        }
      }
      if ( from_panel == (TPanel *)v5->victory_button_go_to_dest && v30 != 1 )
      {
        RGE_View::get_selection_area((RGE_View *)&v5->main_view->vfptr, &x1, &y1, &x2, &y2, 1);
        v41 = (double)x2;
        v42 = (double)x1;
        *(float *)&from_panela = (double)y1;
        old_seed = (double)y2;
        v5->px1 = v42;
        v5->py1 = *(float *)&from_panela;
        v5->SelectRegionFlag = 0;
        v5->px2 = v41;
        v5->py2 = old_seed;
        if ( !v44 )
        {
          *(float *)&map_size = v41 - (v41 - v42) * 0.5;
          *(float *)&old_seedb = old_seed - (old_seed - *(float *)&from_panela) * 0.5;
          v45 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::set_view_loc(v45, *(float *)&map_size, *(float *)&old_seedb);
          v46 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::set_map_loc(v46, (signed __int64)*(float *)&map_size, (signed __int64)*(float *)&old_seedb);
        }
        return 1;
      }
      v47 = v5->victory_drop_down;
      if ( (TDropDownPanel *)from_panel == v47 )
      {
        v48 = TDropDownPanel::get_line(v47);
        TRIBE_Screen_Sed::activate_victory_proper_fields(v5, v48, 0);
      }
      v49 = 0;
      v50 = (TPanel **)v5->victory_button;
      do
      {
        if ( from_panel == *v50 && v5->CurrentVictory != v49 )
        {
          v51 = TDropDownPanel::get_line(v5->victory_drop_down);
          TRIBE_Screen_Sed::activate_victory_proper_fields(v5, v51, 0);
          TRIBE_Screen_Sed::save_victory_cond_in_scenario(v5, v5->CurrentVictory);
          TRIBE_Screen_Sed::activate_victory_panel(v5, 0);
          v52 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(v52);
          v5->CurrentVictory = v49;
          TRIBE_Screen_Sed::load_victory_cond_from_scenario(v5, v49);
          TRIBE_Screen_Sed::activate_victory_panel(v5, 1);
          v53 = TDropDownPanel::get_line(v5->victory_drop_down);
          TRIBE_Screen_Sed::activate_victory_proper_fields(v5, v53, 1);
          if ( v5->SelectedObject )
          {
            v54 = v5->SelectedObject;
            v55 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::select_one_object(v55, v54, 0);
          }
          if ( v5->DestinationObject )
          {
            v56 = v5->DestinationObject;
            v57 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::select_one_object(v57, v56, 0);
          }
        }
        ++v49;
        ++v50;
      }
      while ( v49 < 12 );
      v11 = action_in;
LABEL_251:
      if ( TPanel::panelName(from_panel) && !strcmp(TPanel::panelName(from_panel), aQuitsavedialog) )
      {
        TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_0, 0);
        TPanelSystem::destroyPanel(&panel_system, aQuitsavedialog);
        if ( v11 )
        {
          if ( v11 == 1 )
          {
            TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
            if ( v110 )
              TPanelSystem::destroyPanel(&panel_system, aScenarioEdit_0);
            else
              RGE_Base_Game::close(rge_base_game);
          }
        }
        else
        {
          TRIBE_Screen_Sed::command_save(v5, 0, 1);
        }
        return 1;
      }
      if ( TPanel::panelName(from_panel) && !strcmp(TPanel::panelName(from_panel), aOpensavedialog) )
      {
        TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_0, 0);
        TPanelSystem::destroyPanel(&panel_system, aOpensavedialog);
        if ( v11 )
        {
          if ( v11 == 1 )
          {
            v111 = (TRIBE_Screen_Sed_Open *)operator new(0x490u);
            v117 = 0.0;
            if ( v111 )
              TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(v111);
            v117 = -6.8056469e38/*NaN*/;
            TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_2, 0);
          }
        }
        else
        {
          TRIBE_Screen_Sed::command_save(v5, 0, 2);
        }
        return 1;
      }
      if ( TPanel::panelName(from_panel) && !strcmp(TPanel::panelName(from_panel), aNewsavedialog) )
      {
        TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_0, 0);
        TPanelSystem::destroyPanel(&panel_system, aNewsavedialog);
        if ( v11 )
        {
          if ( v11 == 1 )
            TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game, 0, 0);
        }
        else
        {
          TRIBE_Screen_Sed::command_save(v5, 0, 3);
        }
        return 1;
      }
      return 0;
    case 1:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in != 1 )
        goto LABEL_251;
      v58 = 0;
      v59 = (TPanel **)v5->map_type_button;
      do
      {
        if ( from_panel == *v59 )
        {
          TRIBE_Screen_Sed::set_map_type(v5, (TRIBE_Screen_Sed::MapType)(v58 + 1), 1);
          return 1;
        }
        ++v58;
        ++v59;
      }
      while ( v58 < 3 );
      if ( from_panel != (TPanel *)v5->generate_map_button )
        goto LABEL_251;
      (*(void (__stdcall **)(signed int))&v5->map_generating_text->vfptr->gap10[4])(1);
      v5->vfptr->set_redraw((TPanel *)v5, RedrawFull);
      InvalidateRect(rge_base_game->prog_window, 0, 0);
      RGE_Base_Game::draw_window(rge_base_game);
      v60 = TDropDownPanel::currentLineNumber(v5->map_size_drop);
      old_seeda = TDropDownPanel::currentLineNumber(v5->map_style_drop);
      switch ( v60 )
      {
        case 0:
          v61 = 72;
          break;
        case 1:
          v61 = 96;
          break;
        case 2:
          v61 = 120;
          break;
        case 3:
          v61 = 144;
          break;
        case 4:
          v61 = 200;
          break;
        case 5:
          v61 = 250;
          break;
        default:
          v61 = old_seeda;
          break;
      }
      v62 = TDropDownPanel::get_line(v5->player_number_list);
      v63 = v5->map_type;
      v64 = v62 + 1;
      if ( v63 == 1 )
      {
        switch ( TDropDownPanel::currentLineNumber(v5->default_terrain_drop) )
        {
          case 0:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 0, v61, v61);
            break;
          case 1:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 6, v61, v61);
            break;
          case 2:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 10, v61, v61);
            break;
          case 3:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 1, v61, v61);
            break;
          case 4:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 13, v61, v61);
            break;
          case 5:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 20, v61, v61);
            break;
          case 6:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 4, v61, v61);
            break;
          case 7:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 19, v61, v61);
            break;
          case 8:
            RGE_Map::clear_map(v5->world->map, *v5->world->players, (RGE_Game_World *)&v5->world->vfptr, 22, v61, v61);
            break;
          default:
            break;
        }
      }
      else
      {
        from_panelb = (TPanel *)rge_base_game->random_map_seed;
        if ( v63 == 3 )
        {
          v65 = TEditPanel::currentLine(v5->random_seed_input);
          rge_base_game->random_map_seed = atoi(v65);
        }
        else
        {
          rge_base_game->random_map_seed = -1;
        }
        v66 = 0;
        do
        {
          RGE_Player::reset_selected(v5->world->players[v66]);
          ++v66;
        }
        while ( v66 < 9 );
        ((void (__stdcall *)(TRIBE_World *, int, int, int, int))v5->world->map->vfptr->map_generate2)(
          v5->world,
          v61,
          v61,
          old_seeda,
          v64);
        rge_base_game->random_map_seed = (int)from_panelb;
        itoa(rge_base_game->save_random_map_seed, random_val, 10);
        (*(void (__stdcall **)(char *))&v5->random_seed_used_text->vfptr[1].gap4[4])(random_val);
        debug_rand(aCMsdevWorkAg_6, 2904);
      }
      v67 = v61 / 2;
      v68 = 0;
      do
      {
        RGE_Player::set_map_loc(v5->world->players[v68], v67, v67);
        *(float *)&old_seedc = (double)v67;
        RGE_Player::set_view_loc(v5->world->players[v68], *(float *)&old_seedc, *(float *)&old_seedc);
        ++v68;
      }
      while ( v68 < 8 );
      v69 = 0;
      do
      {
        RGE_Tile_List::del_list(&v5->world->players[v69]->tile_list);
        RGE_Player::set_map_visible(v5->world->players[v69]);
        ++v69;
      }
      while ( v69 < 8 );
      TRIBE_Screen_Sed::set_panel_info(v5);
      (*(void (__stdcall **)(_DWORD))&v5->map_generating_text->vfptr->gap10[4])(0);
      return 1;
    case 2:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in != 2 && action_in != 1 )
        goto LABEL_251;
      v70 = (TTextPanel *)&v5->paint_terrain_list->vfptr;
      if ( (TTextPanel *)from_panel == v70 )
      {
        v71 = TTextPanel::currentLineNumber(v70);
        TRIBE_Screen_Sed::set_terrain(v5, v71);
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v5->brush_size_button[0] + 20))(1);
        return 1;
      }
      v72 = (TTextPanel *)&v5->paint_elevation_list->vfptr;
      if ( (TTextPanel *)from_panel == v72 )
      {
        v73 = TTextPanel::currentLineNumber(v72);
        TRIBE_Screen_Sed::set_elevation(v5, v73);
        return 1;
      }
      if ( action_in != 1 )
        goto LABEL_251;
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      v74 = 0;
      v75 = (TPanel **)v5->brush_size_button;
      do
      {
        if ( from_panel == *v75 )
        {
          TRIBE_Screen_Sed::set_brush_size(v5, (TRIBE_Screen_Sed::BrushSize)(v74 + 1));
          return 1;
        }
        ++v74;
        ++v75;
      }
      while ( v74 < 5 );
      v76 = 0;
      v77 = (TPanel **)v5->paint_type_button;
      while ( from_panel != *v77 )
      {
        ++v76;
        ++v77;
        if ( v76 >= 3 )
          goto LABEL_251;
      }
      TRIBE_Screen_Sed::set_paint_type(v5, (TRIBE_Screen_Sed::PaintType)(v76 + 1), 1);
      return 1;
    case 3:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in )
        goto LABEL_193;
      v78 = 0;
      v79 = (TPanel **)v5->player_inven_input;
      while ( from_panel != *v79 )
      {
        ++v78;
        ++v79;
        if ( v78 >= 5 )
          goto LABEL_183;
      }
      TPanel::set_curr_child(v5->bottom_panel, 0);
LABEL_183:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      v80 = v5->player_advance_civilization_drop;
      if ( (TDropDownPanel *)from_panel == v80 )
      {
        if ( v5->valid_save_spot_flag )
          v5->need_to_save_flag = 1;
        v81 = TDropDownPanel::currentLineNumber(v80);
        T_Scenario::SetPlayerAge((T_Scenario *)v5->world->scenario, v5->player_num - 1, v81);
      }
      v82 = v5->player_list;
      if ( (TDropDownPanel *)from_panel == v82 )
      {
        v83 = TDropDownPanel::get_line(v82);
        TRIBE_Screen_Sed::set_player(v5, v83 + 1, 1, 1);
        v84 = TDropDownPanel::get_line(v5->player_list);
        v85 = T_Scenario::GetPlayerAge((T_Scenario *)v5->world->scenario, v84);
        TDropDownPanel::setCurrentLineNumber(v5->player_advance_civilization_drop, v85);
      }
      if ( from_panel == (TPanel *)v5->player_number_list )
      {
        LOWORD(v78) = v5->player_num;
        TRIBE_Screen_Sed::set_player(v5, v78, 1, 0);
        TRIBE_Screen_Sed::SavePlayerActiveStatus(v5);
        LOWORD(v86) = v5->player_num;
        TRIBE_Screen_Sed::set_player(v5, v86, 0, 1);
      }
LABEL_193:
      if ( action_in == 1 )
      {
        v87 = v5->player_advance_civilization_drop;
        if ( (TDropDownPanel *)from_panel == v87 )
        {
          v88 = TDropDownPanel::currentLineNumber(v87);
          T_Scenario::SetPlayerAge((T_Scenario *)v5->world->scenario, v5->player_num - 1, v88);
        }
      }
      goto LABEL_251;
    case 4:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in )
        goto LABEL_209;
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      v89 = (TPanel *)&v5->unit_player_list->vfptr;
      if ( from_panel != v89 )
        goto LABEL_209;
      v90 = TDropDownPanel::get_line((TDropDownPanel *)v89);
      TRIBE_Screen_Sed::set_unit_player(v5, v90);
      v91 = TDropDownPanel::get_line(v5->unit_player_list);
      v92 = rge_base_game->vfptr;
      if ( v91 )
      {
        (*(void (__stdcall **)(int, signed int))&v92->gap8[8])(rge_base_game->game_mode, 4);
        if ( rge_base_game->master_obj_id != -1 && RGE_Base_Game::get_player(rge_base_game) )
        {
          v93 = rge_base_game->master_obj_id;
          v94 = RGE_Base_Game::get_player(rge_base_game);
          v95 = v5->world->players[HIWORD(RGE_Base_Game::get_player(rge_base_game)->master_players)]->master_objects[v93];
          TRIBE_Scenario_Editor_Panel_Object::set_master_info(v5->object_panel, v95, (TRIBE_Player *)v94);
        }
        else
        {
          TRIBE_Scenario_Editor_Panel_Object::set_master_info(v5->object_panel, 0, 0);
        }
        TRIBE_Screen_Sed::set_paint_object_mode(v5);
        ((void (__stdcall *)(signed int))v5->object_panel->vfptr->set_redraw)(2);
        return 1;
      }
      (*(void (__stdcall **)(int, signed int))&v92->gap8[8])(rge_base_game->game_mode, 3);
LABEL_209:
      if ( action_in != 2 && action_in != 1 )
        goto LABEL_251;
      v96 = (TTextPanel *)&v5->unit_list->vfptr;
      if ( (TTextPanel *)from_panel == v96 )
      {
        v97 = TTextPanel::currentLineNumber(v96);
        TRIBE_Screen_Sed::set_unit(v5, v97);
        v98 = rge_base_game;
        v99 = rge_base_game->game_mode;
        if ( v99 != 8 && v99 != 21 )
        {
          TButtonPanel::set_radio_button(v5->unit_mode_select[0]);
          v98 = rge_base_game;
        }
        if ( v98->master_obj_id != -1 && RGE_Base_Game::get_player(v98) )
        {
          v100 = rge_base_game->master_obj_id;
          v101 = RGE_Base_Game::get_player(rge_base_game);
          v102 = v5->world->players[HIWORD(RGE_Base_Game::get_player(rge_base_game)->master_players)]->master_objects[v100];
          TRIBE_Scenario_Editor_Panel_Object::set_master_info(v5->object_panel, v102, (TRIBE_Player *)v101);
        }
        else
        {
          TRIBE_Scenario_Editor_Panel_Object::set_master_info(v5->object_panel, 0, 0);
        }
        TRIBE_Screen_Sed::set_paint_object_mode(v5);
        ((void (__stdcall *)(signed int))v5->object_panel->vfptr->set_redraw)(1);
        return 1;
      }
      if ( action_in == 1 )
      {
        if ( from_panel == (TPanel *)v5->unit_mode_select[0] )
        {
          TRIBE_Screen_Sed::set_paint_object_mode(v5);
        }
        else if ( from_panel == (TPanel *)v5->unit_mode_select[1] )
        {
          v103 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(v103);
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(14, 0);
        }
        else if ( from_panel == (TPanel *)v5->unit_mode_select[2] )
        {
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(15, 0);
        }
        else if ( from_panel == (TPanel *)v5->unit_mode_select[3] )
        {
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(20, 0);
        }
      }
      goto LABEL_251;
    case 7:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in != 1 )
        goto LABEL_251;
      v104 = 0;
      v105 = (TPanel **)v5->victory_cond_type;
      while ( from_panel != *v105 )
      {
        ++v104;
        ++v105;
        if ( v104 >= 5 )
          goto LABEL_251;
      }
      TRIBE_Screen_Sed::set_mp_victory_type(v5, (TRIBE_Screen_Sed::VictoryType)(v104 + 1), 1);
      if ( v104 != 4 )
      {
        T_Scenario::Set_Multi_Conquest((T_Scenario *)v5->world->scenario, 1);
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v5->victory_cond_on[0] + 224))(1);
      }
      return 1;
    case 5:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in && action_in != 1 )
        goto LABEL_251;
      if ( from_panel == (TPanel *)v5->Diplomacy_player_list )
      {
        (*(void (__stdcall **)(signed int))&v5->Diplomacy_status_label[3 * v5->player_num + 1]->vfptr->gap10[4])(1);
        (*(void (__stdcall **)(signed int))(**((_DWORD **)&v5->vfptr + 3 * (v5->player_num + 184)) + 20))(1);
        (*(void (__stdcall **)(signed int))&v5->Diplomacy_status_label[3 * v5->player_num + 3]->vfptr->gap10[4])(1);
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5->Diplomacy_friend_box[7][v5->player_num + 2] + 20))(0);
        v106 = TDropDownPanel::get_line(v5->Diplomacy_player_list) + 1;
        v5->player_num = v106;
        (*(void (__stdcall **)(_DWORD))&v5->Diplomacy_status_label[3 * v106 + 1]->vfptr->gap10[4])(0);
        (*(void (__stdcall **)(_DWORD))(**((_DWORD **)&v5->vfptr + 3 * (v5->player_num + 184)) + 20))(0);
        (*(void (__stdcall **)(_DWORD))&v5->Diplomacy_status_label[3 * v5->player_num + 3]->vfptr->gap10[4])(0);
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v5->Diplomacy_friend_box[7][v5->player_num + 2] + 20))(1);
        v107 = TDropDownPanel::get_line(v5->Diplomacy_player_list);
        TRIBE_Screen_Sed::load_diplomacy_from_scenario(v5, v107);
      }
      if ( action_in != 1 )
        goto LABEL_251;
      TRIBE_Screen_Sed::save_diplomacy_in_scenario(v5, v5->player_num - 1);
      return 1;
    case 8:
      if ( v5->valid_save_spot_flag )
        v5->need_to_save_flag = 1;
      if ( action_in == 1 )
      {
        TRIBE_Screen_Sed::SaveDisabledItemsInScenario(v5);
        TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(v5);
        v108 = v5->options_button[0];
        if ( (TButtonPanel *)from_panel == v108 )
        {
          v109 = TButtonPanel::get_state(v108);
          T_Scenario::SetScenarioOption((T_Scenario *)v5->world->scenario, 2, v109);
        }
      }
      goto LABEL_251;
    default:
      goto LABEL_251;
  }
}

//----- (004AD0F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::draw(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  TPanelVtbl *v2; // ebx@7
  int rect; // ST34_4@8
  int rect_8; // ST3C_4@8
  int v5; // edi@8

  v1 = this;
  TEasy_Panel::draw((TEasy_Panel *)&this->vfptr);
  if ( v1->use_bevels
    && v1->main_view
    && v1->render_rect.left == v1->clip_rect.left
    && v1->render_rect.top == v1->clip_rect.top
    && v1->render_rect.right == v1->clip_rect.right
    && v1->render_rect.bottom == v1->clip_rect.bottom )
  {
    v2 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    if ( TDrawArea::Lock(v1->render_area, aScr_sedDraw, 1) )
    {
      rect = v1->main_view->render_rect.left;
      rect_8 = v1->main_view->render_rect.right;
      v5 = v1->main_view->render_rect.bottom;
      TDrawArea::DrawBevel3(
        v1->render_area,
        0,
        0,
        v1->pnl_wid - 1,
        v1->main_view->render_rect.top - 1,
        v1->bevel_color1,
        v1->bevel_color2,
        v1->bevel_color3,
        v1->bevel_color4,
        v1->bevel_color5,
        v1->bevel_color6);
      TDrawArea::DrawBevel3(
        v1->render_area,
        0,
        v5 + 1,
        v1->pnl_wid - 1,
        v1->pnl_hgt - 1,
        v1->bevel_color1,
        v1->bevel_color2,
        v1->bevel_color3,
        v1->bevel_color4,
        v1->bevel_color5,
        v1->bevel_color6);
      TDrawArea::Unlock(v1->render_area, aScr_sedDraw);
    }
    v2->draw_finish((TPanel *)v1);
  }
}

//----- (004AD240) --------------------------------------------------------
void TRIBE_Screen_Sed::command_cancel()
{
  RGE_Player *v1; // eax@1
  RGE_Player *v2; // eax@1

  v1 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_object(v1);
  v2 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
  RGE_Player::unselect_area(v2);
}

//----- (004AD270) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::command_menu(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  TRIBE_Dialog_Sed_Menu *v2; // eax@1
  int v3; // eax@2
  int result; // eax@6

  v1 = this;
  v2 = (TRIBE_Dialog_Sed_Menu *)operator new(0x4B4u);
  if ( v2 )
    TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(v2, v1);
  else
    v3 = 0;
  if ( v3 && *(_DWORD *)(v3 + 216) )
  {
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004AD300) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::command_new(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1

  v1 = this;
  if ( TRIBE_Screen_Sed::need_to_save(this) )
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)&v1->vfptr, 9287, aNewsavedialog, 450, 100);
  else
    TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game, 0, 0);
}

//----- (004AD340) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::command_new_map(TRIBE_Screen_Sed *this, char *scenario_name_in, int is_multi_player_in, int random_seed_in, int width, int height, int display_in)
{
  TRIBE_Screen_Sed *v7; // eax@1
  TRIBE_Game *v8; // ecx@1
  int v10; // esi@14
  char *v11; // ebx@14
  char *v12; // ebp@14
  RGE_Player_Info *v13; // edi@14
  RGE_Base_Game *v14; // eax@19
  TSound_Driver *v15; // eax@19
  int v16; // ebx@21
  TRIBE_World *v17; // ecx@22
  TSound_Driver *v18; // eax@24
  int v19; // esi@28
  TRIBE_Screen_Sed *v20; // [sp+10h] [bp-7D8h]@1
  int tribe; // [sp+14h] [bp-7D4h]@14
  RGE_Player_Info player_info; // [sp+1Ch] [bp-7CCh]@14
  RGE_Map_Gen_Info map_info; // [sp+2C8h] [bp-520h]@14

  v7 = this;
  this->need_to_save_flag = 0;
  v8 = (TRIBE_Game *)rge_base_game;
  v20 = v7;
  if ( !rge_base_game->world )
  {
    if ( display_in )
    {
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1101, 0, -1);
      v8 = (TRIBE_Game *)rge_base_game;
    }
    if ( !TRIBE_Game::load_game_data(v8) )
    {
      if ( display_in )
        TRIBE_Game::close_status_message();
      return 0;
    }
    v8 = (TRIBE_Game *)rge_base_game;
    v7 = v20;
  }
  v7->world = (TRIBE_World *)v8->world;
  if ( display_in )
  {
    if ( scenario_name_in )
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1103, 0, -1);
    else
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1102, 0, -1);
    v7 = v20;
  }
  player_info.map_info = &map_info;
  player_info.map_width = width;
  player_info.map_height = height;
  player_info.scenario = scenario_name_in;
  v10 = 0;
  player_info.ai_info = 0;
  player_info.player_num = 8;
  tribe = 0;
  v11 = (char *)player_info.player_id_hash;
  v12 = (char *)player_info.color;
  v13 = &player_info;
  while ( 1 )
  {
    if ( ++tribe >= v7->world->master_player_num )
      tribe = 1;
    TRIBE_Screen_Sed::set_string((char *)v13, (int)(&player_info.type[v10] + 10341 - ((_DWORD)&player_info + 585)), 65);
    player_info.type[v10] = 0;
    player_info.tribe[v10] = tribe;
    *(_WORD *)v12 = -1;
    *(_DWORD *)v11 = v10++;
    v13 = (RGE_Player_Info *)((char *)v13 + 65);
    v12 += 2;
    v11 += 4;
    if ( v10 >= 8 )
      break;
    v7 = v20;
  }
  v14 = rge_base_game;
  player_info.player_id_hash[v10] = v10;
  map_info.base_terrain = 0;
  v15 = v14->sound_system;
  if ( v15 )
    v15->mute = 1;
  v16 = ((int (__stdcall *)(RGE_Player_Info *, int))v20->world->vfptr->new_scenario)(&player_info, random_seed_in) & 0xFF;
  if ( v16 )
  {
    v17 = v20->world;
    if ( v17->player_num < 8 )
    {
      v16 = 0;
      ((void (*)(void))v17->vfptr->del_game_info)();
    }
  }
  v18 = rge_base_game->sound_system;
  if ( v18 )
    v18->mute = 0;
  if ( v16 && v20->player_number_list )
  {
    v19 = 0;
    do
    {
      if ( !RGE_Scenario::Get_player_Active(v20->world->scenario, v19) )
        break;
      ++v19;
    }
    while ( v19 < 8 );
    if ( v19 < 8 && v19 > 0 )
      TDropDownPanel::set_line(v20->player_number_list, v19 - 1);
    TRIBE_Screen_Sed::SavePlayerActiveStatus(v20);
  }
  return v16;
}

//----- (004AD590) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::command_open(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  TRIBE_Screen_Sed_Open *v2; // eax@3

  v1 = this;
  if ( TRIBE_Screen_Sed::need_to_save(this) )
  {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)&v1->vfptr, 9287, aOpensavedialog, 450, 100);
  }
  else
  {
    v2 = (TRIBE_Screen_Sed_Open *)operator new(0x490u);
    if ( v2 )
      TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(v2);
    TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_2, 0);
  }
}

//----- (004AD630) --------------------------------------------------------
void TRIBE_Screen_Sed::command_outline()
{
  char v1; // cl@1

  v1 = rge_base_game->outline_type;
  switch ( rge_base_game->outline_type )
  {
    case 0:
    case 3:
      rge_base_game->outline_type = 2;
      break;
    case 2:
      rge_base_game->outline_type = 1;
      break;
    case 1:
      v1 = 0;
      goto LABEL_5;
    default:
LABEL_5:
      rge_base_game->outline_type = v1;
      break;
  }
}

//----- (004AD680) --------------------------------------------------------
void __stdcall TRIBE_Screen_Sed::command_player(int id)
{
  (*(void (__stdcall **)(_DWORD))&rge_base_game->vfptr->gap8[12])(id);
}

//----- (004AD6A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::command_quit(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  int v2; // eax@3

  v1 = this;
  if ( TRIBE_Screen_Sed::need_to_save(this) )
  {
    TEasy_Panel::popupYesNoCancelDialog((TEasy_Panel *)&v1->vfptr, 9287, aQuitsavedialog, 450, 100);
  }
  else
  {
    TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
    if ( v2 )
      TPanelSystem::destroyPanel(&panel_system, aScenarioEdit_0);
    else
      RGE_Base_Game::close(rge_base_game);
  }
}

//----- (004AD700) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::command_save(TRIBE_Screen_Sed *this, char kill_menu, char quit_after_save)
{
  TRIBE_Screen_Sed *v3; // ebp@1
  const char *v4; // edi@5
  char *v5; // eax@11
  int v6; // eax@14
  TRIBE_Screen_Sed_Open *v7; // eax@18
  char temp_name[260]; // [sp+10h] [bp-110h]@11
  int v9; // [sp+11Ch] [bp-4h]@18

  v3 = this;
  TRIBE_Screen_Sed::set_scenario_mode(this, ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)v3->world->scenario, 1);
  if ( RGE_Scenario::active_player_count(v3->world->scenario) >= 1 )
  {
    if ( RGE_Scenario::any_player_count(v3->world->scenario) >= 1 )
    {
      v4 = RGE_Scenario::Get_scenario_name(v3->world->scenario);
      if ( *v4 )
      {
        TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1104, 0, -1);
        if ( kill_menu )
          TPanelSystem::destroyPanel(&panel_system, aScenarioMenuDi);
        if ( (unsigned __int8)((int (__stdcall *)(const char *))v3->world->vfptr->save_scenario)(v4) )
        {
          TRIBE_Game::close_status_message();
          v5 = TRegistry::RegGetInt(rge_base_game->registry, 0, aGameFileNumber);
          sprintf(temp_name, aDefaultD, v5);
          if ( strcmp(v4, temp_name) )
            v3->need_to_save_flag = 0;
          switch ( quit_after_save )
          {
            case 1:
              TRIBE_Game::start_menu((TRIBE_Game *)rge_base_game);
              if ( v6 )
                TPanelSystem::destroyPanel(&panel_system, aScenarioEdit_0);
              else
                RGE_Base_Game::close(rge_base_game);
              break;
            case 2:
              v7 = (TRIBE_Screen_Sed_Open *)operator new(0x490u);
              v9 = 0;
              if ( v7 )
                TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(v7);
              v9 = -1;
              TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_2, 0);
              break;
            case 3:
              TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game, 0, 0);
              break;
          }
        }
        else
        {
          TRIBE_Game::close_status_message();
          TEasy_Panel::popupOKDialog((TEasy_Panel *)&v3->vfptr, 2403, 0, 450, 100);
        }
      }
      else
      {
        TRIBE_Screen_Sed::command_save_as(v3, quit_after_save);
      }
    }
    else
    {
      TPanelSystem::destroyPanel(&panel_system, aScenarioMenuDi);
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v3->vfptr, 10051, 0, 450, 100);
    }
  }
  else
  {
    TPanelSystem::destroyPanel(&panel_system, aScenarioMenuDi);
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v3->vfptr, 10050, 0, 450, 100);
  }
}

//----- (004AD960) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::command_save_as(TRIBE_Screen_Sed *this, char quit_after_save)
{
  TRIBE_Screen_Sed *v2; // esi@1
  TribeSaveGameScreen *v3; // eax@5
  char scenario_name[224]; // [sp+8h] [bp-ECh]@5
  int v5; // [sp+F0h] [bp-4h]@5

  v2 = this;
  TRIBE_Screen_Sed::set_scenario_mode(this, ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)v2->world->scenario, 1);
  if ( RGE_Scenario::active_player_count(v2->world->scenario) >= 1 )
  {
    if ( RGE_Scenario::any_player_count(v2->world->scenario) >= 1 )
    {
      scenario_name[0] = 0;
      v3 = (TribeSaveGameScreen *)operator new(0x6A4u);
      v5 = 0;
      if ( v3 )
        TribeSaveGameScreen::TribeSaveGameScreen(v3, SaveScenarioEdit, scenario_name, (unsigned __int8)quit_after_save);
      v5 = -1;
      TPanelSystem::setCurrentPanel(&panel_system, aSaveGameScreen, 0);
      TPanelSystem::destroyPanel(&panel_system, aScenarioMenuDi);
    }
    else
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v2->vfptr, 10051, 0, 450, 100);
    }
  }
  else
  {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v2->vfptr, 10050, 0, 450, 100);
  }
}

//----- (004ADA70) --------------------------------------------------------
char *__thiscall TRIBE_Screen_Sed::scenario_get_default_name(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  char *v2; // eax@1
  char *v3; // eax@3
  char temp_name[260]; // [sp+4h] [bp-104h]@3

  v1 = this;
  v2 = RGE_Scenario::Get_scenario_name(this->world->scenario);
  if ( !v2 || !*v2 )
  {
    v3 = TRegistry::RegGetInt(rge_base_game->registry, 0, aGameFileNumber);
    sprintf(temp_name, aDefaultD_scx, v3);
    RGE_Scenario::Set_scenario_name(v1->world->scenario, temp_name);
  }
  return RGE_Scenario::Get_scenario_name(v1->world->scenario);
}

//----- (004ADAF0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::command_quick_save(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1

  v1 = this;
  TRIBE_Screen_Sed::scenario_get_default_name(this);
  TRIBE_Screen_Sed::command_save(v1, 0, 0);
}

//----- (004ADB10) --------------------------------------------------------
char *__thiscall TRIBE_Screen_Sed::scenario_save_defaulted(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  char *result; // eax@2
  char *v3; // eax@5
  char *v4; // eax@7

  v1 = this;
  TRIBE_Screen_Sed::set_scenario_mode(this, ScenarioModeSave);
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)v1->world->scenario, 1);
  if ( RGE_Scenario::active_player_count(v1->world->scenario) >= 1 )
  {
    if ( RGE_Scenario::any_player_count(v1->world->scenario) >= 1 )
    {
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1104, 0, -1);
      v3 = TRegistry::RegGetInt(rge_base_game->registry, 0, aGameFileNumber);
      sprintf(temp_name, aDefaultD_scx, v3);
      if ( (unsigned __int8)((int (__stdcall *)(char *))v1->world->vfptr->save_scenario)(temp_name) )
      {
        v4 = TRegistry::RegGetInt(rge_base_game->registry, 0, aGameFileNumber);
        sprintf(temp_name, aDefaultD, v4);
        result = temp_name;
      }
      else
      {
        TRIBE_Game::close_status_message();
        TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 2403, 0, 450, 100);
        result = 0;
      }
    }
    else
    {
      TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 10051, 0, 450, 100);
      result = 0;
    }
  }
  else
  {
    TEasy_Panel::popupOKDialog((TEasy_Panel *)&v1->vfptr, 10050, 0, 450, 100);
    result = 0;
  }
  return result;
}

//----- (004ADC30) --------------------------------------------------------
char __thiscall TRIBE_Screen_Sed::need_to_save(TRIBE_Screen_Sed *this)
{
  return this->need_to_save_flag;
}

//----- (004ADC40) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::set_focus(TRIBE_Screen_Sed *this, int have_focus_in)
{
  TRIBE_Screen_Sed *v2; // esi@1

  v2 = this;
  TScreenPanel::set_focus((TScreenPanel *)&this->vfptr, have_focus_in);
  if ( v2->have_focus )
    RGE_Base_Game::set_windows_mouse(rge_base_game, 0);
  else
    RGE_Base_Game::set_windows_mouse(rge_base_game, 1);
}

//----- (004ADC80) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::SaveDisabledItemsInScenario(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // edi@1
  int v2; // esi@3
  TButtonPanel **v3; // ebx@3

  v1 = this;
  if ( !this->player_num )
    this->player_num = 1;
  v2 = 0;
  v3 = this->options_disable_button;
  do
  {
    if ( TButtonPanel::get_state(*v3) )
      T_Scenario::SetDisabledTechnology((T_Scenario *)v1->world->scenario, v1->player_num - 1, v2, 0);
    else
      T_Scenario::SetDisabledTechnology((T_Scenario *)v1->world->scenario, v1->player_num - 1, v2, 1);
    ++v2;
    ++v3;
  }
  while ( v2 < 16 );
  v1->player_num = TDropDownPanel::get_line(v1->options_player_list) + 1;
}

//----- (004ADD00) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::LoadDisabledItemsFromScenario(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // ebx@1
  int v2; // esi@1
  char *v3; // edi@1
  int v4; // eax@2
  int v5; // ecx@2

  v1 = this;
  v2 = 0;
  v3 = (char *)this->options_disable_button;
  do
  {
    v4 = T_Scenario::GetDisabledTechnology((T_Scenario *)v1->world->scenario, v1->player_num - 1, v2);
    v5 = *(_DWORD *)v3;
    if ( v4 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 224))(0);
    else
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v5 + 224))(1);
    ++v2;
    v3 += 4;
  }
  while ( v2 < 16 );
}

//----- (004ADD60) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::save_multi_victory_cond_in_scenario(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  int v2; // eax@8
  int v3; // eax@8
  int v4; // eax@18
  int v5; // eax@18
  const char *v6; // eax@25
  signed int v7; // edi@25
  const char *v8; // eax@32
  int v9; // edi@32
  const char *v10; // eax@35
  int v11; // edi@35
  const char *v12; // eax@38
  int v13; // edi@38
  const char *v14; // eax@41
  int v15; // edi@41
  int v16; // [sp-4h] [bp-Ch]@3
  int v17; // [sp-4h] [bp-Ch]@11

  v1 = this;
  switch ( this->mp_victory_type )
  {
    case 1:
      T_Scenario::SetMPVictory((T_Scenario *)this->world->scenario, 0);
      break;
    case 2:
      v16 = 1;
      goto LABEL_7;
    case 3:
      T_Scenario::SetMPVictory((T_Scenario *)this->world->scenario, 2);
      break;
    case 4:
      T_Scenario::SetMPVictory((T_Scenario *)this->world->scenario, 3);
      break;
    default:
      v16 = 4;
LABEL_7:
      T_Scenario::SetMPVictory((T_Scenario *)this->world->scenario, v16);
      break;
  }
  v2 = TDropDownPanel::get_id(v1->victory_score);
  T_Scenario::SetVictoryScore((T_Scenario *)v1->world->scenario, v2);
  v3 = TDropDownPanel::get_id(v1->victory_time);
  T_Scenario::SetVictoryTime((T_Scenario *)v1->world->scenario, v3);
  if ( TButtonPanel::get_state(v1->victory_cond_type[0]) )
  {
    T_Scenario::SetMPVictory((T_Scenario *)v1->world->scenario, 0);
    goto LABEL_18;
  }
  if ( TButtonPanel::get_state(v1->victory_cond_type[1]) )
  {
    v17 = 1;
  }
  else
  {
    if ( TButtonPanel::get_state(v1->victory_cond_type[2]) )
    {
      T_Scenario::SetMPVictory((T_Scenario *)v1->world->scenario, 2);
      goto LABEL_18;
    }
    if ( TButtonPanel::get_state(v1->victory_cond_type[3]) )
    {
      T_Scenario::SetMPVictory((T_Scenario *)v1->world->scenario, 3);
      goto LABEL_18;
    }
    v17 = 4;
  }
  T_Scenario::SetMPVictory((T_Scenario *)v1->world->scenario, v17);
LABEL_18:
  v4 = TDropDownPanel::get_id(v1->victory_score);
  T_Scenario::SetVictoryScore((T_Scenario *)v1->world->scenario, v4);
  v5 = TDropDownPanel::get_id(v1->victory_time);
  T_Scenario::SetVictoryTime((T_Scenario *)v1->world->scenario, v5);
  if ( TButtonPanel::get_state(v1->victory_and_or[1]) )
    T_Scenario::Set_victory_all_flag((T_Scenario *)v1->world->scenario, 1);
  else
    T_Scenario::Set_victory_all_flag((T_Scenario *)v1->world->scenario, 0);
  if ( TButtonPanel::get_state(v1->victory_cond_on[0]) || !TButtonPanel::get_state(v1->victory_cond_type[4]) )
    T_Scenario::Set_Multi_Conquest((T_Scenario *)v1->world->scenario, 1);
  else
    T_Scenario::Set_Multi_Conquest((T_Scenario *)v1->world->scenario, 0);
  v6 = TEditPanel::currentLine(v1->victory_condition_explore);
  v7 = atoi(v6);
  if ( TButtonPanel::get_state(v1->victory_cond_on[1]) )
  {
    if ( v7 < 1 )
      v7 = 1;
    if ( v7 > 100 )
      v7 = 100;
    T_Scenario::Set_Multi_Exploration((T_Scenario *)v1->world->scenario, v7);
  }
  else
  {
    T_Scenario::Set_Multi_Exploration((T_Scenario *)v1->world->scenario, 0);
  }
  v8 = TEditPanel::currentLine(v1->victory_condition_ruins);
  v9 = atoi(v8);
  if ( TButtonPanel::get_state(v1->victory_cond_on[2]) )
    T_Scenario::Set_Multi_Ruins((T_Scenario *)v1->world->scenario, v9);
  else
    T_Scenario::Set_Multi_Ruins((T_Scenario *)v1->world->scenario, 0);
  v10 = TEditPanel::currentLine(v1->victory_condition_artifacts);
  v11 = atoi(v10);
  if ( TButtonPanel::get_state(v1->victory_cond_on[3]) )
    T_Scenario::Set_Multi_Artifacts((T_Scenario *)v1->world->scenario, v11);
  else
    T_Scenario::Set_Multi_Artifacts((T_Scenario *)v1->world->scenario, 0);
  v12 = TEditPanel::currentLine(v1->victory_condition_discoveries);
  v13 = atoi(v12);
  if ( TButtonPanel::get_state(v1->victory_cond_on[4]) )
    T_Scenario::Set_Multi_Discoveries((T_Scenario *)v1->world->scenario, v13);
  else
    T_Scenario::Set_Multi_Discoveries((T_Scenario *)v1->world->scenario, 0);
  v14 = TEditPanel::currentLine(v1->victory_condition_gold);
  v15 = atoi(v14);
  if ( TButtonPanel::get_state(v1->victory_cond_on[5]) )
    T_Scenario::Set_Multi_Gold((T_Scenario *)v1->world->scenario, v15);
  else
    T_Scenario::Set_Multi_Gold((T_Scenario *)v1->world->scenario, 0);
}

//----- (004AE070) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::save_victory_cond_in_scenario(TRIBE_Screen_Sed *this, int which)
{
  TRIBE_Screen_Sed *v2; // esi@1
  int v3; // edi@8
  const char *v4; // eax@9
  int v5; // ebx@9
  int v6; // eax@9
  TDropDownPanel *v7; // ecx@9
  int v8; // ebp@9
  TRIBE_World *v9; // edx@9
  int v10; // eax@36
  int v11; // ST10_4@38
  int v12; // eax@40
  int x1; // [sp+10h] [bp-14h]@9
  int y1; // [sp+14h] [bp-10h]@9
  int x2; // [sp+18h] [bp-Ch]@9
  int y2; // [sp+1Ch] [bp-8h]@9
  int VictoryType; // [sp+20h] [bp-4h]@9
  int whicha; // [sp+28h] [bp+4h]@9

  v2 = this;
  if ( TButtonPanel::get_state(this->victory_and_or[1]) )
    T_Scenario::Set_victory_all_flag((T_Scenario *)v2->world->scenario, 1);
  else
    T_Scenario::Set_victory_all_flag((T_Scenario *)v2->world->scenario, 0);
  if ( TButtonPanel::get_state(v2->victory_cond_on[0]) || !TButtonPanel::get_state(v2->victory_cond_type[4]) )
    T_Scenario::Set_Multi_Conquest((T_Scenario *)v2->world->scenario, 1);
  else
    T_Scenario::Set_Multi_Conquest((T_Scenario *)v2->world->scenario, 0);
  v3 = which;
  if ( which >= 0 )
  {
    v4 = TEditPanel::currentLine(v2->victory_amount_input);
    v5 = atoi(v4);
    v6 = TDropDownPanel::get_line(v2->victory_drop_down);
    v7 = v2->victory_enemy_player_list;
    VictoryType = v6;
    v8 = TDropDownPanel::get_line(v7) + 1;
    whicha = TDropDownPanel::get_id(v2->victory_object_list);
    RGE_View::get_selection_area((RGE_View *)&v2->main_view->vfptr, &x1, &y1, &x2, &y2, 1);
    v9 = v2->world;
    v2->px1 = (double)x1;
    v2->py1 = (double)y1;
    v2->px2 = (double)x2;
    v2->py2 = (double)y2;
    T_Scenario::ClearSPVictoryCondition((T_Scenario *)v9->scenario, v3);
    switch ( VictoryType )
    {
      case 1:
        if ( v2->SelectedObject )
        {
          if ( v2->DestinationObject )
          {
            T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 3);
            T_Scenario::SetSPObject((T_Scenario *)v2->world->scenario, v3, v2->SelectedObject);
            T_Scenario::SetSPDestObjectID((T_Scenario *)v2->world->scenario, v3, v2->DestinationObject);
          }
        }
        return;
      case 2:
        if ( v2->SelectedObject )
        {
          T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 3);
          T_Scenario::SetSPObject((T_Scenario *)v2->world->scenario, v3, v2->SelectedObject);
          T_Scenario::SetSPRectangle((T_Scenario *)v2->world->scenario, v3, v2->px1, v2->py1, v2->px2, v2->py2);
        }
        return;
      case 3:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 2);
        T_Scenario::SetSPObjectType((T_Scenario *)v2->world->scenario, v3, whicha);
        goto LABEL_39;
      case 4:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 2);
        T_Scenario::SetSPObjectType((T_Scenario *)v2->world->scenario, v3, whicha);
        T_Scenario::SetSPAmount((T_Scenario *)v2->world->scenario, v3, v5);
        T_Scenario::SetSPRectangle((T_Scenario *)v2->world->scenario, v3, v2->px1, v2->py1, v2->px2, v2->py2);
        return;
      case 5:
        if ( v8 >= 1 && v8 <= 8 && v5 )
        {
          T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 1);
          T_Scenario::SetSPPlayerID((T_Scenario *)v2->world->scenario, v3, v8);
          T_Scenario::SetSPObjectType((T_Scenario *)v2->world->scenario, v3, whicha);
          T_Scenario::SetSPAmount((T_Scenario *)v2->world->scenario, v3, v5);
        }
        return;
      case 6:
        if ( v2->SelectedObject )
        {
          T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 1);
          T_Scenario::SetSPObject((T_Scenario *)v2->world->scenario, v3, v2->SelectedObject);
        }
        return;
      case 7:
        if ( v8 >= 1 && v8 <= 8 )
        {
          T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 1);
          T_Scenario::SetSPPlayerID((T_Scenario *)v2->world->scenario, v3, v8);
          T_Scenario::SetSPObjectType((T_Scenario *)v2->world->scenario, v3, whicha);
          T_Scenario::SetSPAllFlag((T_Scenario *)v2->world->scenario, v3, 1);
        }
        return;
      case 8:
        if ( v8 >= 1 && v8 <= 8 )
        {
          T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 1);
          T_Scenario::SetSPPlayerID((T_Scenario *)v2->world->scenario, v3, v8);
        }
        return;
      case 9:
        if ( v2->SelectedObject )
        {
          T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 5);
          T_Scenario::SetSPObject((T_Scenario *)v2->world->scenario, v3, v2->SelectedObject);
        }
        return;
      case 10:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 0);
        goto LABEL_39;
      case 11:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 3);
        goto LABEL_39;
      case 12:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 1);
        goto LABEL_39;
      case 13:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 2);
        goto LABEL_39;
      case 14:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 4);
        goto LABEL_39;
      case 15:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 5);
        v10 = TDropDownPanel::get_line(v2->victory_ages_list);
        T_Scenario::SetSPAmount((T_Scenario *)v2->world->scenario, v3, v10 + 1);
        return;
      case 16:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 4);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, 6);
        goto LABEL_39;
      case 17:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 6);
        v11 = TDropDownPanel::get_id(v2->victory_attribute_list);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, v11);
LABEL_39:
        T_Scenario::SetSPAmount((T_Scenario *)v2->world->scenario, v3, v5);
        break;
      case 18:
        T_Scenario::SetSPVictoryType((T_Scenario *)v2->world->scenario, v3, 7);
        v12 = TDropDownPanel::get_id(v2->victory_tech_list);
        T_Scenario::SetSPAttribType((T_Scenario *)v2->world->scenario, v3, v12);
        break;
      default:
        return;
    }
  }
}

//----- (004AE620) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::load_victory_cond_from_scenario(TRIBE_Screen_Sed *this, int which)
{
  TRIBE_Screen_Sed *v2; // esi@1
  int v3; // eax@1
  int v4; // edx@1
  int v5; // edi@4
  TRIBE_World *v6; // ecx@5
  int v7; // eax@5
  int v8; // eax@5
  int v9; // eax@5
  RGE_Static_Object *v10; // eax@5
  TRIBE_World *v11; // ecx@5
  int v12; // eax@14
  int v13; // [sp+0h] [bp-58h]@0
  RGE_Static_Object *obj; // [sp+10h] [bp-48h]@5
  int y2; // [sp+14h] [bp-44h]@5
  int x2; // [sp+18h] [bp-40h]@5
  int y1; // [sp+1Ch] [bp-3Ch]@5
  int x1; // [sp+20h] [bp-38h]@5
  int VictoryType; // [sp+24h] [bp-34h]@5
  int Amount; // [sp+28h] [bp-30h]@5
  RGE_Static_Object *destobj; // [sp+2Ch] [bp-2Ch]@5
  char str[40]; // [sp+30h] [bp-28h]@5
  int whicha; // [sp+5Ch] [bp+4h]@5

  v2 = this;
  v3 = T_Scenario::Get_victory_all_flag((T_Scenario *)this->world->scenario);
  v4 = *(_DWORD *)v2->victory_and_or[0];
  if ( v3 )
  {
    (*(void (__stdcall **)(_DWORD, int))(v4 + 224))(0, v13);
    (*(void (__cdecl **)(signed int))(*(_DWORD *)v2->victory_and_or[1] + 224))(1);
  }
  else
  {
    (*(void (__stdcall **)(signed int, int))(v4 + 224))(1, v13);
    (*(void (__cdecl **)(signed int))(*(_DWORD *)v2->victory_and_or[1] + 224))(0);
  }
  v5 = which;
  if ( which >= 0 )
  {
    v6 = v2->world;
    v2->SelectedObject = 0;
    v2->DestinationObject = 0;
    ((void (*)(void))v6->scenario->vfptr->rehook)();
    T_Scenario::SetSPWhich((T_Scenario *)v2->world->scenario, v2->player_num - 1);
    Amount = T_Scenario::GetSPAmount((T_Scenario *)v2->world->scenario, which);
    itoa(Amount, str, 10);
    TEditPanel::set_text(v2->victory_amount_input, str);
    v7 = T_Scenario::GetSPPlayerID((T_Scenario *)v2->world->scenario, which);
    TDropDownPanel::set_line(v2->victory_enemy_player_list, v7 - 1);
    v8 = T_Scenario::GetSPObjectType((T_Scenario *)v2->world->scenario, which);
    v9 = TDropDownPanel::get_line(v2->victory_object_list, v8);
    TDropDownPanel::setCurrentLineNumber(v2->victory_object_list, v9);
    obj = T_Scenario::GetSPObject((T_Scenario *)v2->world->scenario, which);
    v10 = T_Scenario::GetSPDestObjectID((T_Scenario *)v2->world->scenario, which);
    v11 = v2->world;
    v2->SelectedObject = obj;
    v2->DestinationObject = v10;
    destobj = v10;
    VictoryType = T_Scenario::GetSPVictoryType((T_Scenario *)v11->scenario, which);
    whicha = T_Scenario::GetSPAttribType((T_Scenario *)v2->world->scenario, which);
    T_Scenario::GetSPRectangle((T_Scenario *)v2->world->scenario, v5, &v2->px1, &v2->py1, &v2->px2, &v2->py2);
    x1 = (signed __int64)v2->px1;
    y1 = (signed __int64)v2->py1;
    x2 = (signed __int64)v2->px2;
    y2 = (signed __int64)v2->py2;
    RGE_View::set_selection_area((RGE_View *)&v2->main_view->vfptr, -1, -1, -1, -1);
    if ( v2->px2 != 0.0 )
      RGE_View::set_selection_area((RGE_View *)&v2->main_view->vfptr, x1, y1, x2, y2);
    switch ( VictoryType )
    {
      case 4:
        switch ( whicha )
        {
          case 0:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 10);
            break;
          case 3:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 11);
            break;
          case 1:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 12);
            break;
          case 2:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 13);
            break;
          case 4:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 14);
            break;
          case 5:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 15);
            v12 = T_Scenario::GetSPAmount((T_Scenario *)v2->world->scenario, v5);
            TDropDownPanel::setCurrentLineNumber(v2->victory_ages_list, v12 - 1);
            break;
          case 6:
            TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 16);
            break;
          default:
            return;
        }
        break;
      case 6:
        TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 17);
        TDropDownPanel::setCurrentLineId(v2->victory_attribute_list, whicha);
        break;
      case 7:
        TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 18);
        TDropDownPanel::setCurrentLineId(v2->victory_tech_list, whicha);
        break;
      case 5:
        if ( obj )
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 9);
        break;
      case 1:
        if ( Amount )
        {
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 5);
        }
        else if ( obj )
        {
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 6);
        }
        else if ( T_Scenario::GetSPAllFlag((T_Scenario *)v2->world->scenario, v5) )
        {
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 7);
        }
        else
        {
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 8);
        }
        break;
      case 2:
        T_Scenario::GetSPRectangle((T_Scenario *)v2->world->scenario, v5, &v2->px1, &v2->py1, &v2->px2, &v2->py2);
        if ( v2->px2 <= 0.0 )
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 3);
        else
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 4);
        break;
      case 3:
        if ( destobj )
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 1);
        else
          TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 2);
        break;
      case 0:
        TDropDownPanel::setCurrentLineNumber(v2->victory_drop_down, 0);
        break;
      default:
        return;
    }
  }
}

//----- (004AE9D0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::load_multi_victory_cond_from_scenario(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  int v2; // eax@7
  int v3; // eax@8
  int v4; // eax@10
  int v5; // eax@11
  TButtonPanel *v6; // ecx@14
  int v7; // eax@16
  TButtonPanel *v8; // ecx@16
  int v9; // edi@19
  int v10; // edx@19
  int v11; // edi@22
  int v12; // edx@22
  int v13; // edi@25
  int v14; // edx@25
  int v15; // edi@28
  int v16; // edx@28
  int v17; // edi@31
  int v18; // edx@31
  char str[20]; // [sp+18h] [bp-14h]@20

  v1 = this;
  switch ( T_Scenario::GetMPVictory((T_Scenario *)this->world->scenario) )
  {
    case 0:
      v1->mp_victory_type = 1;
      break;
    case 1:
      v1->mp_victory_type = 2;
      break;
    case 2:
      v1->mp_victory_type = 3;
      break;
    case 3:
      v1->mp_victory_type = 4;
      break;
    default:
      v1->mp_victory_type = 5;
      break;
  }
  v2 = T_Scenario::GetVictoryScore((T_Scenario *)v1->world->scenario);
  if ( v2 )
    v3 = TDropDownPanel::get_line(v1->victory_score, v2);
  else
    v3 = TDropDownPanel::get_line(v1->victory_score, 900);
  TDropDownPanel::set_line(v1->victory_score, v3);
  v4 = T_Scenario::GetVictoryTime((T_Scenario *)v1->world->scenario);
  if ( v4 )
    v5 = TDropDownPanel::get_line(v1->victory_time, v4);
  else
    v5 = TDropDownPanel::get_line(v1->victory_time, 9000);
  TDropDownPanel::set_line(v1->victory_time, v5);
  if ( T_Scenario::Get_victory_all_flag((T_Scenario *)v1->world->scenario) )
    v6 = v1->victory_and_or[1];
  else
    v6 = v1->victory_and_or[0];
  TButtonPanel::set_radio_button(v6);
  v7 = T_Scenario::Get_Multi_Conquest((T_Scenario *)v1->world->scenario);
  v8 = v1->victory_cond_on[0];
  if ( v7 )
    (*(void (__stdcall **)(signed int))(*(_DWORD *)v8 + 224))(1);
  else
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 224))(0);
  v9 = T_Scenario::Get_Multi_Exploration((T_Scenario *)v1->world->scenario);
  v10 = *(_DWORD *)v1->victory_cond_on[1];
  if ( v9 )
  {
    (*(void (__stdcall **)(signed int))(v10 + 224))(1);
    itoa(v9, str, 10);
    TEditPanel::set_text(v1->victory_condition_explore, str);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))(v10 + 224))(0);
    TEditPanel::set_text(v1->victory_condition_explore, text);
  }
  v11 = T_Scenario::Get_Multi_Ruins((T_Scenario *)v1->world->scenario);
  v12 = *(_DWORD *)v1->victory_cond_on[2];
  if ( v11 )
  {
    (*(void (__stdcall **)(signed int))(v12 + 224))(1);
    itoa(v11, str, 10);
    TEditPanel::set_text(v1->victory_condition_ruins, str);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))(v12 + 224))(0);
    TEditPanel::set_text(v1->victory_condition_ruins, text);
  }
  v13 = T_Scenario::Get_Multi_Artifacts((T_Scenario *)v1->world->scenario);
  v14 = *(_DWORD *)v1->victory_cond_on[3];
  if ( v13 )
  {
    (*(void (__stdcall **)(signed int))(v14 + 224))(1);
    itoa(v13, str, 10);
    TEditPanel::set_text(v1->victory_condition_artifacts, str);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))(v14 + 224))(0);
    TEditPanel::set_text(v1->victory_condition_artifacts, text);
  }
  v15 = T_Scenario::Get_Multi_Discoveries((T_Scenario *)v1->world->scenario);
  v16 = *(_DWORD *)v1->victory_cond_on[4];
  if ( v15 )
  {
    (*(void (__stdcall **)(signed int))(v16 + 224))(1);
    itoa(v15, str, 10);
    TEditPanel::set_text(v1->victory_condition_discoveries, str);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))(v16 + 224))(0);
    TEditPanel::set_text(v1->victory_condition_discoveries, text);
  }
  v17 = T_Scenario::Get_Multi_Gold((T_Scenario *)v1->world->scenario);
  v18 = *(_DWORD *)v1->victory_cond_on[5];
  if ( v17 )
  {
    (*(void (__stdcall **)(signed int))(v18 + 224))(1);
    itoa(v17, str, 10);
    TEditPanel::set_text(v1->victory_condition_gold, str);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))(v18 + 224))(0);
    TEditPanel::set_text(v1->victory_condition_gold, text);
  }
  T_Scenario::Save_victory_conditions_into_players((T_Scenario *)v1->world->scenario, 1);
}

//----- (004AECB0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::save_diplomacy_in_scenario(TRIBE_Screen_Sed *this, int which)
{
  TRIBE_Screen_Sed *v2; // edi@1
  int v3; // esi@2
  char *v4; // ebx@2
  int v5; // eax@10

  v2 = this;
  if ( which >= 0 )
  {
    v3 = 0;
    v4 = (char *)&this->Diplomacy_friend_box[0][1];
    do
    {
      if ( TButtonPanel::get_state(*((TButtonPanel **)v4 - 1)) == 1 )
      {
        T_Scenario::Set_player_attitude((T_Scenario *)v2->world->scenario, which, v3, 0);
      }
      else if ( TButtonPanel::get_state(*(TButtonPanel **)v4) == 1 )
      {
        T_Scenario::Set_player_attitude((T_Scenario *)v2->world->scenario, which, v3, 1);
      }
      else if ( TButtonPanel::get_state(*((TButtonPanel **)v4 + 1)) == 1 )
      {
        T_Scenario::Set_player_attitude((T_Scenario *)v2->world->scenario, which, v3, 3);
      }
      ++v3;
      v4 += 12;
    }
    while ( v3 < 8 );
    v5 = TButtonPanel::get_state(v2->Diplomacy_AlliedVictory[which]);
    T_Scenario::SetPlayerAlliedVictory((T_Scenario *)v2->world->scenario, which, v5);
  }
}

//----- (004AED50) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::load_diplomacy_from_scenario(TRIBE_Screen_Sed *this, int which)
{
  int v2; // esi@2
  char *v3; // ebx@2
  char *v4; // ebp@2
  int v5; // edi@4
  int v6; // ebx@11
  int v7; // eax@11
  TRIBE_Screen_Sed *v8; // [sp+4h] [bp-4h]@1

  v8 = this;
  if ( which >= 0 )
  {
    v2 = 0;
    v3 = (char *)this->Diplomacy_AlliedVictory;
    v4 = (char *)&this->Diplomacy_friend_box[0][1];
    while ( 1 )
    {
      v5 = T_Scenario::Get_player_attitude((T_Scenario *)this->world->scenario, which, v2);
      if ( !v5 )
        TButtonPanel::set_radio_button(*((TButtonPanel **)v4 - 1));
      if ( v5 == 1 )
        TButtonPanel::set_radio_button(*(TButtonPanel **)v4);
      if ( v5 == 3 )
        TButtonPanel::set_radio_button(*((TButtonPanel **)v4 + 1));
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v3 + 224))(0);
      ++v2;
      v3 += 4;
      v4 += 12;
      if ( v2 >= 8 )
        break;
      this = v8;
    }
    v6 = *(_DWORD *)v8->Diplomacy_AlliedVictory[which];
    v7 = T_Scenario::GetPlayerAlliedVictory((T_Scenario *)v8->world->scenario, which);
    (*(void (__thiscall **)(TButtonPanel *, int))(v6 + 224))(v8->Diplomacy_AlliedVictory[which], v7);
  }
}

//----- (004AEE10) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::activate_victory_proper_fields(TRIBE_Screen_Sed *this, int TypeOfVictory, int activate)
{
  TRIBE_Screen_Sed *v3; // esi@1
  TPanel *v4; // ecx@8
  TPanelVtbl *v5; // edx@8
  TPanel *ptr[2]; // [sp+14h] [bp-8h]@8

  v3 = this;
  this->SelectRegionFlag = 0;
  if ( activate )
  {
    TPanel::set_curr_child(this->bottom_panel, 0);
    switch ( TypeOfVictory )
    {
      case 1:
        (*(void (__stdcall **)(int))(*(_DWORD *)v3->victory_button_set_object + 20))(activate);
        (*(void (__stdcall **)(int))(*(_DWORD *)v3->victory_button_set_destination + 20))(activate);
        return;
      case 2:
        (*(void (__stdcall **)(int))(*(_DWORD *)v3->victory_button_set_object + 20))(activate);
        (*(void (__stdcall **)(int))(*(_DWORD *)v3->victory_button_set_destination + 20))(activate);
        (*(void (__stdcall **)(int))(*(_DWORD *)v3->victory_button_go_to_dest + 20))(activate);
        return;
      case 3:
        (*(void (__stdcall **)(int))&v3->victory_object_list->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30566, -1);
        goto LABEL_20;
      case 4:
        (*(void (__stdcall **)(int))&v3->victory_object_list->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30567, -1);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->victory_button_set_destination + 20))(activate);
        (*(void (__stdcall **)(int))(*(_DWORD *)v3->victory_button_go_to_dest + 20))(activate);
        return;
      case 5:
        (*(void (__stdcall **)(_DWORD))&v3->victory_object_list->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_which_enemy_text->vfptr->gap10[4])(activate);
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30568, -1);
        (*(void (__stdcall **)(int))&v3->victory_enemy_player_list->vfptr->gap10[4])(activate);
        v4 = (TPanel *)&v3->victory_amount_input->vfptr;
        v5 = v3->vfptr;
        ptr[0] = (TPanel *)&v3->victory_enemy_player_list->vfptr;
        ptr[1] = v4;
        v5->set_tab_order((TPanel *)v3, (TPanel *)ptr, (TPanel *)2);
        goto LABEL_11;
      case 7:
        (*(void (__stdcall **)(_DWORD))&v3->victory_object_list->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_which_enemy_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(int))&v3->victory_enemy_player_list->vfptr->gap10[4])(activate);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_enemy_player_list->vfptr);
        break;
      case 8:
        (*(void (__stdcall **)(_DWORD))&v3->victory_which_enemy_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_enemy_player_list->vfptr->gap10[4])(activate);
LABEL_11:
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_enemy_player_list->vfptr);
        break;
      case 6:
      case 9:
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->victory_button_set_object + 20))(activate);
        break;
      case 15:
        (*(void (__stdcall **)(int))&v3->victory_ages_list->vfptr->gap10[4])(activate);
        break;
      case 10:
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30569, -1);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        break;
      case 11:
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30570, -1);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        break;
      case 12:
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30571, -1);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        break;
      case 13:
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30572, -1);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        break;
      case 14:
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30573, -1);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        break;
      case 16:
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30574, -1);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
LABEL_20:
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        break;
      case 17:
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(activate);
        (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(activate);
        TPanel::set_help_info((TPanel *)&v3->victory_amount_input->vfptr, 30575, -1);
        TPanel::set_curr_child(v3->bottom_panel, (TPanel *)&v3->victory_amount_input->vfptr);
        (*(void (__stdcall **)(int))&v3->victory_attribute_list->vfptr->gap10[4])(activate);
        break;
      case 18:
        (*(void (__stdcall **)(int))&v3->victory_tech_list->vfptr->gap10[4])(activate);
        break;
      default:
        return;
    }
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))&this->victory_object_list->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_amount_text->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_amount_input->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->victory_button_set_object + 20))(0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->victory_button_set_destination + 20))(0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->victory_button_go_to_dest + 20))(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_which_enemy_text->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_enemy_player_list->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_attribute_list->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_ages_list->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v3->victory_tech_list->vfptr->gap10[4])(0);
  }
}

//----- (004AF320) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::init_module_variables(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // edx@1
  char *v2; // eax@1
  signed int v3; // ecx@1
  TTextPanel **v4; // eax@3
  signed int v5; // ecx@3
  TTextPanel **v6; // eax@5
  signed int v7; // ecx@5
  TEditPanel **v8; // eax@7
  signed int v9; // ecx@7
  TDropDownPanel **v10; // eax@9
  signed int v11; // ecx@9
  TTextPanel **v12; // eax@11
  signed int v13; // ecx@11
  TTextPanel **v14; // eax@13
  signed int v15; // ecx@13
  TButtonPanel **v16; // eax@15
  signed int v17; // ecx@15
  TTextPanel **v18; // eax@17
  signed int v19; // ecx@17
  TDropDownPanel **v20; // eax@19
  signed int v21; // ecx@19
  TButtonPanel **v22; // eax@21
  signed int v23; // ecx@21
  TTextPanel **v24; // eax@23
  signed int v25; // ecx@23
  TButtonPanel **v26; // ecx@25
  int v27; // eax@25
  signed int v28; // edi@25

  v1 = this;
  this->background_pic = 0;
  this->main_view = 0;
  this->map_view = 0;
  this->message_panel = 0;
  this->bottom_panel = 0;
  this->set_player_first_flag = 0;
  memset(this->scenario_mode_button, 0, sizeof(this->scenario_mode_button));
  this->menu_button = 0;
  this->help_button = 0;
  this->map_type_label = 0;
  v2 = (char *)this->map_type_text;
  v3 = 3;
  do
  {
    *((_DWORD *)v2 - 3) = 0;
    *(_DWORD *)v2 = 0;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  v1->default_terrain_drop = 0;
  v1->default_terrain_label = 0;
  v1->map_size_drop = 0;
  v1->map_size_label = 0;
  v1->map_style_drop = 0;
  v1->map_style_label = 0;
  v1->map_generating_text = 0;
  v1->random_seed_label = 0;
  v1->random_seed_input = 0;
  v1->random_seed_used_label = 0;
  v1->random_seed_used_text = 0;
  v1->generate_map_button = 0;
  v1->brush_size_label = 0;
  v1->paint_type_label = 0;
  v1->paint_terrain_label = 0;
  v4 = v1->brush_size_button_label;
  v5 = 5;
  do
  {
    *(v4 - 5) = 0;
    *v4 = 0;
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = v1->paint_type_button_label;
  v7 = 3;
  do
  {
    *(v6 - 3) = 0;
    *v6 = 0;
    ++v6;
    --v7;
  }
  while ( v7 );
  v1->paint_terrain_list = 0;
  v1->paint_terrain_scrollbar = 0;
  v1->paint_elevation_list = 0;
  v1->paint_elevation_scrollbar = 0;
  v1->player_advance_civilization_drop = 0;
  v1->player_label = 0;
  v1->player_starting_age_label = 0;
  v1->player_build_text = 0;
  v1->player_city_text = 0;
  v1->player_list = 0;
  v1->player_number_list = 0;
  v8 = v1->player_inven_input;
  v9 = 5;
  do
  {
    *(v8 - 5) = 0;
    *v8 = 0;
    ++v8;
    --v9;
  }
  while ( v9 );
  v10 = v1->player_setting_drop;
  v11 = 2;
  do
  {
    *(v10 - 3) = 0;
    *v10 = 0;
    ++v10;
    --v11;
  }
  while ( v11 );
  v1->BuildList = 0;
  v1->CityLayout = 0;
  v1->AiRules = 0;
  v1->unit_player_list = 0;
  v12 = v1->unit_mode_select_label;
  v13 = 4;
  do
  {
    *(v12 - 4) = 0;
    *v12 = 0;
    ++v12;
    --v13;
  }
  while ( v13 );
  v1->unit_list = 0;
  v1->unit_scrollbar = 0;
  v1->unit_list_info = 0;
  v1->button_unit_pics = 0;
  v1->button_bldg_pics[0] = 0;
  v1->button_bldg_pics[1] = 0;
  v1->button_bldg_pics[2] = 0;
  v1->button_bldg_pics[3] = 0;
  v1->button_bldg_pics[4] = 0;
  v1->object_panel = 0;
  v1->unit_list_size = 0;
  memset(v1->victory_cond_on, 0, sizeof(v1->victory_cond_on));
  v14 = v1->victory_text_and_or;
  v15 = 2;
  do
  {
    *(v14 - 5) = 0;
    *v14 = 0;
    ++v14;
    --v15;
  }
  while ( v15 );
  v1->victory_amount_label = 0;
  v1->victory_long_label = 0;
  v1->victory_condition_label = 0;
  v1->victory_label_conquest = 0;
  v1->victory_label_explore = 0;
  v1->victory_label_explore_percent = 0;
  v1->victory_label_ruins = 0;
  v1->victory_label_artifacts = 0;
  v1->victory_label_discoveries = 0;
  v1->victory_label_gold = 0;
  v1->victory_condition_explore = 0;
  v1->victory_condition_ruins = 0;
  v1->victory_condition_artifacts = 0;
  v1->victory_condition_discoveries = 0;
  v1->victory_condition_gold = 0;
  v16 = v1->victory_cond_type;
  v17 = 5;
  do
  {
    *(v16 - 5) = 0;
    *v16 = 0;
    ++v16;
    --v17;
  }
  while ( v17 );
  v1->victory_score_label = 0;
  v1->victory_score = 0;
  v1->victory_time_label = 0;
  v1->victory_time = 0;
  memset(v1->victory_button, 0, sizeof(v1->victory_button));
  v1->victory_drop_down = 0;
  v1->victory_object_list = 0;
  v1->victory_player_list = 0;
  v1->victory_ages_list = 0;
  v1->victory_tech_list = 0;
  v1->victory_button_set_object = 0;
  v1->victory_button_set_destination = 0;
  v1->victory_button_go_to_dest = 0;
  v1->victory_condition_text = 0;
  v1->victory_condition_type = 0;
  v1->victory_amount_text = 0;
  v1->victory_amount_input = 0;
  v1->victory_enemy_player_list = 0;
  v1->victory_attribute_list = 0;
  v1->victory_which_enemy_text = 0;
  v1->victory_object_scrollbar = 0;
  v18 = v1->message_button_label;
  v19 = 5;
  do
  {
    *(v18 - 5) = 0;
    *v18 = 0;
    ++v18;
    --v19;
  }
  while ( v19 );
  v1->message_input = 0;
  v20 = v1->cinematic_input;
  v21 = 4;
  do
  {
    *(v20 - 4) = 0;
    *v20 = 0;
    ++v20;
    --v21;
  }
  while ( v21 );
  v22 = v1->options_button;
  v23 = 1;
  do
  {
    *(v22 - 1) = 0;
    *v22 = 0;
    ++v22;
    --v23;
  }
  while ( v23 );
  v1->options_player_list = 0;
  v1->options_disable_tech_text = 0;
  v24 = v1->options_disable_text;
  v25 = 16;
  do
  {
    *(v24 - 16) = 0;
    *v24 = 0;
    ++v24;
    --v25;
  }
  while ( v25 );
  v1->Diplomacy_player_list = 0;
  v26 = v1->Diplomacy_AlliedVictory;
  v27 = (int)&v1->Diplomacy_friend_box[0][1];
  v28 = 8;
  do
  {
    *(v26 - 37) = 0;
    *(_DWORD *)(v27 - 4) = 0;
    *(_DWORD *)v27 = 0;
    *(_DWORD *)(v27 + 4) = 0;
    *v26 = 0;
    ++v26;
    v27 += 12;
    --v28;
  }
  while ( v28 );
  v1->Diplomacy_status_label[0] = 0;
  v1->Diplomacy_status_label[1] = 0;
  v1->Diplomacy_status_label[2] = 0;
  v1->Diplomacy_status_label[3] = 0;
  v1->world = 0;
}

//----- (004AF6C0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::create_all_buttons_etc(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  TPanel **v2; // ebp@1
  TButtonPanel **v3; // edi@11
  signed int v4; // ebx@11
  TPanel **v5; // edi@13
  int v6; // ST18_4@24
  int v7; // eax@24
  TButtonPanel **v8; // edi@34
  signed int v9; // ebx@34
  TButtonPanel **v10; // edi@57
  signed int v11; // ebx@57
  signed int v12; // ebx@59
  TButtonPanel **v13; // edi@59
  TPanel **v14; // ebx@61
  TButtonPanel **v15; // edi@69
  signed int v16; // ebp@69
  TPanel **v17; // edi@71
  TShape *v18; // eax@72
  TShape *v19; // eax@73
  signed int v20; // ebx@77
  signed int v21; // edi@78
  TShape *v22; // eax@80
  TShape *v23; // eax@81
  TPanel **v24; // ebx@86
  RGE_Font *v25; // edi@87
  TRIBE_Scenario_Editor_Panel_Object *v26; // eax@87
  TRIBE_Scenario_Editor_Panel_Object *v27; // eax@88
  signed int v28; // ebx@102
  TEditPanel **v29; // edi@102
  signed int v30; // edi@108
  TDropDownPanel **v31; // ebx@108
  TPanel **v32; // ebx@123
  TButtonPanel **v33; // edi@125
  signed int v34; // ebp@125
  TPanel **v35; // ebx@141
  TPanel **v36; // edi@142
  TPanel *v37; // edx@144
  TPanel *v38; // ecx@144
  TPanel *v39; // edx@144
  TButtonPanel **v40; // edi@154
  signed int v41; // ebp@154
  TPanel **v42; // edi@157
  TPanel **v43; // edi@159
  signed int v44; // edi@160
  TButtonPanel **v45; // ebx@160
  signed int v46; // edi@178
  TButtonPanel **v47; // ebx@178
  TPanel *v48; // ecx@181
  TButtonPanel **v49; // edi@186
  signed int v50; // ebx@186
  signed int v51; // edi@193
  TDropDownPanel **v52; // ebx@193
  signed int v53; // edi@198
  TButtonPanel **v54; // ebx@198
  signed int v55; // edi@202
  TButtonPanel **v56; // ebx@202
  int v57; // eax@221
  TTextPanel **v58; // ebx@221
  int v59; // edi@222
  int v60; // edi@225
  TPanel **v61; // ebx@227
  TPanel **v62; // ebp@228
  bool v63; // sf@230
  unsigned __int8 v64; // of@230
  void (__thiscall *i)(TPanel *, TPanel *, TPanel *); // [sp+24h] [bp-1C8h]@117
  int ia; // [sp+24h] [bp-1C8h]@225
  TButtonPanel **button; // [sp+28h] [bp-1C4h]@225
  TPanel *ptr[4]; // [sp+2Ch] [bp-1C0h]@144
  char str4[20]; // [sp+3Ch] [bp-1B0h]@161
  char str3[20]; // [sp+50h] [bp-19Ch]@161
  char str1[140]; // [sp+64h] [bp-188h]@161
  char str[100]; // [sp+F0h] [bp-FCh]@80
  char str2[140]; // [sp+154h] [bp-98h]@161
  int v74; // [sp+1E8h] [bp-4h]@72

  v1 = this;
  v2 = (TPanel **)this->scenario_mode_button;
  if ( TRIBE_Screen_Sed::create_button(this, (TPanel *)&this->vfptr, this->scenario_mode_button, 10010, 1) )
  {
    TPanel::set_help_info(*v2, 30400, -1);
    if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[1], 10011, 1) )
    {
      TPanel::set_help_info((TPanel *)v1->scenario_mode_button[1], 30401, -1);
      if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[2], 10012, 1) )
      {
        TPanel::set_help_info((TPanel *)v1->scenario_mode_button[2], 30402, -1);
        if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[3], 10013, 1) )
        {
          TPanel::set_help_info((TPanel *)v1->scenario_mode_button[3], 30403, -1);
          if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[4], 10018, 1) )
          {
            TPanel::set_help_info((TPanel *)v1->scenario_mode_button[4], 30408, -1);
            if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[5], 10014, 1) )
            {
              TPanel::set_help_info((TPanel *)v1->scenario_mode_button[5], 30404, -1);
              if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[6], 10019, 1) )
              {
                TPanel::set_help_info((TPanel *)v1->scenario_mode_button[6], 30409, -1);
                if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[7], 10017, 1) )
                {
                  TPanel::set_help_info((TPanel *)v1->scenario_mode_button[7], 30407, -1);
                  if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->scenario_mode_button[8], 10015, 1) )
                  {
                    TPanel::set_help_info((TPanel *)v1->scenario_mode_button[8], 30405, -1);
                    if ( TRIBE_Screen_Sed::create_button(
                           v1,
                           (TPanel *)&v1->vfptr,
                           &v1->scenario_mode_button[9],
                           10016,
                           1) )
                    {
                      TPanel::set_help_info((TPanel *)v1->scenario_mode_button[9], 30406, -1);
                      v3 = (TButtonPanel **)v2;
                      v4 = 10;
                      do
                      {
                        TButtonPanel::set_radio_info(*v3, (TButtonPanel **)v2, 10);
                        (*(void (__stdcall **)(signed int))(*(_DWORD *)*v3 + 20))(1);
                        ++v3;
                        --v4;
                      }
                      while ( v4 );
                      v5 = (TPanel **)&v1->menu_button;
                      if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->menu_button, 10020, 0) )
                      {
                        TPanel::set_help_info(*v5, 30540, -1);
                        (*(void (__stdcall **)(signed int))&(*v5)->vfptr->gap10[4])(1);
                        if ( TRIBE_Screen_Sed::create_button(v1, (TPanel *)&v1->vfptr, &v1->help_button, 4009, 0) )
                        {
                          (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v1->help_button + 20))(
                            v1->help_button,
                            1);
                          if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->map_type_label, 10662) )
                          {
                            if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, v1->map_type_button) )
                            {
                              TPanel::set_help_info((TPanel *)v1->map_type_button[0], 30415, -1);
                              if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->map_type_button[1]) )
                              {
                                TPanel::set_help_info((TPanel *)v1->map_type_button[1], 30416, -1);
                                if ( TRIBE_Screen_Sed::create_radio_button(
                                       v1,
                                       v1->bottom_panel,
                                       &v1->map_type_button[2]) )
                                {
                                  TPanel::set_help_info((TPanel *)v1->map_type_button[2], 30417, -1);
                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->map_type_text, 10652) )
                                  {
                                    if ( TRIBE_Screen_Sed::create_text(
                                           v1,
                                           v1->bottom_panel,
                                           &v1->map_type_text[1],
                                           10653) )
                                    {
                                      if ( TRIBE_Screen_Sed::create_text(
                                             v1,
                                             v1->bottom_panel,
                                             &v1->map_type_text[2],
                                             10654) )
                                      {
                                        if ( TRIBE_Screen_Sed::create_text(
                                               v1,
                                               v1->bottom_panel,
                                               &v1->default_terrain_label,
                                               10655) )
                                        {
                                          if ( TRIBE_Screen_Sed::create_drop_down(
                                                 v1,
                                                 v1->bottom_panel,
                                                 &v1->default_terrain_drop) )
                                          {
                                            TPanel::set_help_info((TPanel *)&v1->default_terrain_drop->vfptr, 30422, -1);
                                            v6 = TPanel::height((TPanel *)&v1->vfptr) - 200;
                                            v7 = TPanel::width((TPanel *)&v1->vfptr);
                                            if ( TEasy_Panel::create_text(
                                                   (TEasy_Panel *)&v1->vfptr,
                                                   (TPanel *)&v1->main_view->vfptr,
                                                   &v1->map_generating_text,
                                                   10661,
                                                   0,
                                                   0,
                                                   v7,
                                                   v6,
                                                   1,
                                                   1,
                                                   1,
                                                   0) )
                                            {
                                              (*(void (__thiscall **)(TTextPanel *, _DWORD))&v1->map_generating_text->vfptr->gap10[4])(
                                                v1->map_generating_text,
                                                0);
                                              if ( TRIBE_Screen_Sed::create_text(
                                                     v1,
                                                     v1->bottom_panel,
                                                     &v1->map_size_label,
                                                     10656) )
                                              {
                                                if ( TRIBE_Screen_Sed::create_drop_down(
                                                       v1,
                                                       v1->bottom_panel,
                                                       &v1->map_size_drop) )
                                                {
                                                  TPanel::set_help_info((TPanel *)&v1->map_size_drop->vfptr, 30418, -1);
                                                  if ( TRIBE_Screen_Sed::create_text(
                                                         v1,
                                                         v1->bottom_panel,
                                                         &v1->map_style_label,
                                                         10657) )
                                                  {
                                                    if ( TRIBE_Screen_Sed::create_drop_down(
                                                           v1,
                                                           v1->bottom_panel,
                                                           &v1->map_style_drop) )
                                                    {
                                                      TPanel::set_help_info(
                                                        (TPanel *)&v1->map_style_drop->vfptr,
                                                        30419,
                                                        -1);
                                                      if ( TRIBE_Screen_Sed::create_text(
                                                             v1,
                                                             v1->bottom_panel,
                                                             &v1->random_seed_label,
                                                             10658) )
                                                      {
                                                        if ( TRIBE_Screen_Sed::create_edit(
                                                               v1,
                                                               v1->bottom_panel,
                                                               &v1->random_seed_input,
                                                               text,
                                                               5,
                                                               FormatUnsignedInt,
                                                               0,
                                                               0) )
                                                        {
                                                          TPanel::set_help_info(
                                                            (TPanel *)&v1->random_seed_input->vfptr,
                                                            30420,
                                                            -1);
                                                          if ( TRIBE_Screen_Sed::create_text(
                                                                 v1,
                                                                 v1->bottom_panel,
                                                                 &v1->random_seed_used_label,
                                                                 10659) )
                                                          {
                                                            if ( TRIBE_Screen_Sed::create_text(
                                                                   v1,
                                                                   v1->bottom_panel,
                                                                   &v1->random_seed_used_text,
                                                                   text) )
                                                            {
                                                              if ( TRIBE_Screen_Sed::create_button(
                                                                     v1,
                                                                     v1->bottom_panel,
                                                                     &v1->generate_map_button,
                                                                     10660,
                                                                     0) )
                                                              {
                                                                TPanel::set_help_info(
                                                                  (TPanel *)v1->generate_map_button,
                                                                  30421,
                                                                  -1);
                                                                v8 = v1->map_type_button;
                                                                v9 = 3;
                                                                do
                                                                {
                                                                  TButtonPanel::set_radio_info(
                                                                    *v8,
                                                                    v1->map_type_button,
                                                                    3);
                                                                  ++v8;
                                                                  --v9;
                                                                }
                                                                while ( v9 );
                                                                if ( TRIBE_Screen_Sed::create_text(
                                                                       v1,
                                                                       v1->bottom_panel,
                                                                       &v1->brush_size_label,
                                                                       10671) )
                                                                {
                                                                  if ( TRIBE_Screen_Sed::create_text(
                                                                         v1,
                                                                         v1->bottom_panel,
                                                                         &v1->paint_terrain_label,
                                                                         10684) )
                                                                  {
                                                                    if ( TRIBE_Screen_Sed::create_radio_button(
                                                                           v1,
                                                                           v1->bottom_panel,
                                                                           v1->brush_size_button) )
                                                                    {
                                                                      TPanel::set_help_info(
                                                                        (TPanel *)v1->brush_size_button[0],
                                                                        30425,
                                                                        -1);
                                                                      if ( TRIBE_Screen_Sed::create_radio_button(
                                                                             v1,
                                                                             v1->bottom_panel,
                                                                             &v1->brush_size_button[1]) )
                                                                      {
                                                                        TPanel::set_help_info(
                                                                          (TPanel *)v1->brush_size_button[1],
                                                                          30426,
                                                                          -1);
                                                                        if ( TRIBE_Screen_Sed::create_radio_button(
                                                                               v1,
                                                                               v1->bottom_panel,
                                                                               &v1->brush_size_button[2]) )
                                                                        {
                                                                          TPanel::set_help_info(
                                                                            (TPanel *)v1->brush_size_button[2],
                                                                            30427,
                                                                            -1);
                                                                          if ( TRIBE_Screen_Sed::create_radio_button(
                                                                                 v1,
                                                                                 v1->bottom_panel,
                                                                                 &v1->brush_size_button[3]) )
                                                                          {
                                                                            TPanel::set_help_info(
                                                                              (TPanel *)v1->brush_size_button[3],
                                                                              30428,
                                                                              -1);
                                                                            if ( TRIBE_Screen_Sed::create_radio_button(
                                                                                   v1,
                                                                                   v1->bottom_panel,
                                                                                   &v1->brush_size_button[4]) )
                                                                            {
                                                                              TPanel::set_help_info(
                                                                                (TPanel *)v1->brush_size_button[4],
                                                                                30429,
                                                                                -1);
                                                                              if ( TRIBE_Screen_Sed::create_text(
                                                                                     v1,
                                                                                     v1->bottom_panel,
                                                                                     v1->brush_size_button_label,
                                                                                     10672) )
                                                                              {
                                                                                if ( TRIBE_Screen_Sed::create_text(
                                                                                       v1,
                                                                                       v1->bottom_panel,
                                                                                       &v1->brush_size_button_label[1],
                                                                                       10673) )
                                                                                {
                                                                                  if ( TRIBE_Screen_Sed::create_text(
                                                                                         v1,
                                                                                         v1->bottom_panel,
                                                                                         &v1->brush_size_button_label[2],
                                                                                         10674) )
                                                                                  {
                                                                                    if ( TRIBE_Screen_Sed::create_text(
                                                                                           v1,
                                                                                           v1->bottom_panel,
                                                                                           &v1->brush_size_button_label[3],
                                                                                           10675) )
                                                                                    {
                                                                                      if ( TRIBE_Screen_Sed::create_text(
                                                                                             v1,
                                                                                             v1->bottom_panel,
                                                                                             &v1->brush_size_button_label[4],
                                                                                             10676) )
                                                                                      {
                                                                                        if ( TRIBE_Screen_Sed::create_text(
                                                                                               v1,
                                                                                               v1->bottom_panel,
                                                                                               &v1->paint_type_label,
                                                                                               10681) )
                                                                                        {
                                                                                          if ( TRIBE_Screen_Sed::create_radio_button(
                                                                                                 v1,
                                                                                                 v1->bottom_panel,
                                                                                                 v1->paint_type_button) )
                                                                                          {
                                                                                            TPanel::set_help_info(
                                                                                              (TPanel *)v1->paint_type_button[0],
                                                                                              30430,
                                                                                              -1);
                                                                                            if ( TRIBE_Screen_Sed::create_radio_button(
                                                                                                   v1,
                                                                                                   v1->bottom_panel,
                                                                                                   &v1->paint_type_button[1]) )
                                                                                            {
                                                                                              TPanel::set_help_info(
                                                                                                (TPanel *)v1->paint_type_button[1],
                                                                                                30431,
                                                                                                -1);
                                                                                              if ( TRIBE_Screen_Sed::create_radio_button(
                                                                                                     v1,
                                                                                                     v1->bottom_panel,
                                                                                                     &v1->paint_type_button[2]) )
                                                                                              {
                                                                                                TPanel::set_help_info(
                                                                                                  (TPanel *)v1->paint_type_button[2],
                                                                                                  30432,
                                                                                                  -1);
                                                                                                if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->paint_type_button_label, 10010) )
                                                                                                {
                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->paint_type_button_label[1], 10631) )
                                                                                                  {
                                                                                                    if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->paint_type_button_label[2], 10682) )
                                                                                                    {
                                                                                                      if ( TRIBE_Screen_Sed::create_list(v1, v1->bottom_panel, &v1->paint_terrain_list, &v1->paint_terrain_scrollbar) )
                                                                                                      {
                                                                                                        TPanel::set_help_info((TPanel *)&v1->paint_terrain_list->vfptr, 30433, -1);
                                                                                                        if ( TRIBE_Screen_Sed::create_list(v1, v1->bottom_panel, &v1->paint_elevation_list, &v1->paint_elevation_scrollbar) )
                                                                                                        {
                                                                                                          TPanel::set_help_info((TPanel *)&v1->paint_elevation_list->vfptr, 30434, -1);
                                                                                                          v10 = v1->brush_size_button;
                                                                                                          v11 = 5;
                                                                                                          do
                                                                                                          {
                                                                                                            TButtonPanel::set_radio_info(*v10, v1->brush_size_button, 5);
                                                                                                            ++v10;
                                                                                                            --v11;
                                                                                                          }
                                                                                                          while ( v11 );
                                                                                                          v12 = 3;
                                                                                                          v13 = v1->paint_type_button;
                                                                                                          do
                                                                                                          {
                                                                                                            TButtonPanel::set_radio_info(*v13, v1->paint_type_button, 3);
                                                                                                            ++v13;
                                                                                                            --v12;
                                                                                                          }
                                                                                                          while ( v12 );
                                                                                                          v14 = (TPanel **)v1->unit_mode_select;
                                                                                                          if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, v1->unit_mode_select) )
                                                                                                          {
                                                                                                            TPanel::set_help_info(*v14, 30456, -1);
                                                                                                            if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->unit_mode_select[1]) )
                                                                                                            {
                                                                                                              TPanel::set_help_info((TPanel *)v1->unit_mode_select[1], 30455, -1);
                                                                                                              if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->unit_mode_select[2]) )
                                                                                                              {
                                                                                                                TPanel::set_help_info((TPanel *)v1->unit_mode_select[2], 30457, -1);
                                                                                                                if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->unit_mode_select[3]) )
                                                                                                                {
                                                                                                                  TPanel::set_help_info((TPanel *)v1->unit_mode_select[3], 30458, -1);
                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->unit_mode_select_label, 10103) )
                                                                                                                  {
                                                                                                                    if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->unit_mode_select_label[1], 10104) )
                                                                                                                    {
                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->unit_mode_select_label[2], 10105) )
                                                                                                                      {
                                                                                                                        if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->unit_mode_select_label[3], 10106) )
                                                                                                                        {
                                                                                                                          v15 = v1->unit_mode_select;
                                                                                                                          v16 = 4;
                                                                                                                          do
                                                                                                                          {
                                                                                                                            TButtonPanel::set_radio_info(*v15, v1->unit_mode_select, 4);
                                                                                                                            ++v15;
                                                                                                                            --v16;
                                                                                                                          }
                                                                                                                          while ( v16 );
                                                                                                                          TButtonPanel::set_radio_button((TButtonPanel *)*v14);
                                                                                                                          v17 = (TPanel **)&v1->unit_list;
                                                                                                                          if ( TRIBE_Screen_Sed::create_list(v1, (TPanel *)&v1->vfptr, &v1->unit_list, &v1->unit_scrollbar) )
                                                                                                                          {
                                                                                                                            TPanel::set_help_info(*v17, 30459, -1);
                                                                                                                            TPanel::set_z_order(*v17, 2, 0);
                                                                                                                            v18 = (TShape *)operator new(0x20u);
                                                                                                                            v74 = 0;
                                                                                                                            if ( v18 )
                                                                                                                              TShape::TShape(v18, aBtnunit_shp, 50730);
                                                                                                                            else
                                                                                                                              v19 = 0;
                                                                                                                            v74 = -1;
                                                                                                                            v1->button_unit_pics = v19;
                                                                                                                            if ( v19 && TShape::is_loaded(v19) )
                                                                                                                            {
                                                                                                                              v20 = 0;
                                                                                                                              while ( 1 )
                                                                                                                              {
                                                                                                                                v21 = v20;
                                                                                                                                if ( v20 == 4 )
                                                                                                                                  v21 = 1;
                                                                                                                                sprintf(str, aBtnbldgD_shp, v21);
                                                                                                                                v22 = (TShape *)operator new(0x20u);
                                                                                                                                v74 = 1;
                                                                                                                                if ( v22 )
                                                                                                                                  TShape::TShape(v22, str, v21 + 50704);
                                                                                                                                else
                                                                                                                                  v23 = 0;
                                                                                                                                v74 = -1;
                                                                                                                                v1->button_bldg_pics[v21] = v23;
                                                                                                                                if ( !v23 || !TShape::is_loaded(v23) )
                                                                                                                                  break;
                                                                                                                                if ( ++v20 >= 5 )
                                                                                                                                {
                                                                                                                                  v24 = (TPanel **)&v1->unit_player_list;
                                                                                                                                  if ( !TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->unit_player_list) )
                                                                                                                                    return;
                                                                                                                                  TPanel::set_help_info(*v24, 30460, -1);
                                                                                                                                  v25 = RGE_Base_Game::get_font(rge_base_game, 10);
                                                                                                                                  v26 = (TRIBE_Scenario_Editor_Panel_Object *)operator new(0x21Cu);
                                                                                                                                  v74 = 2;
                                                                                                                                  if ( v26 )
                                                                                                                                    TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object(v26, v1->render_area, (TPanel *)&v1->vfptr, v25->font, v25->font_wid, v25->font_hgt, v1->button_unit_pics, v1->button_bldg_pics, 0);
                                                                                                                                  else
                                                                                                                                    v27 = 0;
                                                                                                                                  v74 = -1;
                                                                                                                                  v1->object_panel = v27;
                                                                                                                                  if ( v27 && !v27->error_code )
                                                                                                                                  {
                                                                                                                                    (*(void (__thiscall **)(TRIBE_Scenario_Editor_Panel_Object *, _DWORD))&v27->vfptr->gap10[4])(v27, 0);
                                                                                                                                    TPanel::set_z_order(*v24, 1, 0);
                                                                                                                                    if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_label, 10340) )
                                                                                                                                    {
                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_starting_age_label, 10261) )
                                                                                                                                      {
                                                                                                                                        if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->player_advance_civilization_drop) )
                                                                                                                                        {
                                                                                                                                          TPanel::set_help_info((TPanel *)&v1->player_advance_civilization_drop->vfptr, 30565, -1);
                                                                                                                                          TRIBE_Screen_Sed::Set_player_advance_civilization_text(v1, 0);
                                                                                                                                          if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->player_list) )
                                                                                                                                          {
                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->player_list->vfptr, 30438, -1);
                                                                                                                                            if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->player_number_list) )
                                                                                                                                            {
                                                                                                                                              TPanel::set_help_info((TPanel *)&v1->player_number_list->vfptr, 30439, -1);
                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->player_inven_label, 10251) )
                                                                                                                                              {
                                                                                                                                                if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_inven_label[1], 10252) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_inven_label[2], 10253) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_inven_label[3], 10254) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_inven_label[4], 10245) )
                                                                                                                                                {
                                                                                                                                                  v28 = 0;
                                                                                                                                                  v29 = v1->player_inven_input;
                                                                                                                                                  while ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, v29, text, 5, FormatUnsignedInt, 0, 0) )
                                                                                                                                                  {
                                                                                                                                                    ++v28;
                                                                                                                                                    ++v29;
                                                                                                                                                    if ( v28 >= 4 )
                                                                                                                                                    {
                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->player_inven_input[0]->vfptr, 30440, 1);
                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->player_inven_input[1]->vfptr, 30441, 1);
                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->player_inven_input[2]->vfptr, 30443, 1);
                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->player_inven_input[3]->vfptr, 30442, 1);
                                                                                                                                                      if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->player_inven_input[4], message_in, 28, 0, 1, 1) )
                                                                                                                                                      {
                                                                                                                                                        TPanel::set_help_info((TPanel *)&v1->player_inven_input[4]->vfptr, 30444, 1);
                                                                                                                                                        if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->player_setting_label, 10256) )
                                                                                                                                                        {
                                                                                                                                                          if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_setting_label[1], 10257) )
                                                                                                                                                          {
                                                                                                                                                            v30 = 0;
                                                                                                                                                            v31 = v1->player_setting_drop;
                                                                                                                                                            while ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, v31) )
                                                                                                                                                            {
                                                                                                                                                              ++v30;
                                                                                                                                                              ++v31;
                                                                                                                                                              if ( v30 >= 2 )
                                                                                                                                                              {
                                                                                                                                                                TPanel::set_help_info((TPanel *)&v1->player_setting_drop[0]->vfptr, 30445, -1);
                                                                                                                                                                TPanel::set_help_info((TPanel *)&v1->player_setting_drop[1]->vfptr, 30446, -1);
                                                                                                                                                                if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->BuildList) )
                                                                                                                                                                {
                                                                                                                                                                  TPanel::set_help_info((TPanel *)&v1->BuildList->vfptr, 30447, -1);
                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->CityLayout) )
                                                                                                                                                                  {
                                                                                                                                                                    TPanel::set_help_info((TPanel *)&v1->CityLayout->vfptr, 30448, -1);
                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->AiRules) )
                                                                                                                                                                    {
                                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->AiRules->vfptr, 30449, -1);
                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_build_text, 10259) )
                                                                                                                                                                      {
                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->player_city_text, 10260) )
                                                                                                                                                                        {
                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->AiRules_text, 10258) )
                                                                                                                                                                          {
                                                                                                                                                                            i = v1->vfptr->set_tab_order;
                                                                                                                                                                            i((TPanel *)&v1->vfptr, (TPanel *)v1->player_inven_input, (TPanel *)5);
                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, v1->victory_cond_on) )
                                                                                                                                                                            {
                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->victory_cond_on[0], 30468, -1);
                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, &v1->victory_cond_on[1]) )
                                                                                                                                                                              {
                                                                                                                                                                                TPanel::set_help_info((TPanel *)v1->victory_cond_on[1], 30470, -1);
                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, &v1->victory_cond_on[2]) )
                                                                                                                                                                                {
                                                                                                                                                                                  TPanel::set_help_info((TPanel *)v1->victory_cond_on[2], 30471, -1);
                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, &v1->victory_cond_on[3]) )
                                                                                                                                                                                  {
                                                                                                                                                                                    TPanel::set_help_info((TPanel *)v1->victory_cond_on[3], 30472, -1);
                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, &v1->victory_cond_on[4]) )
                                                                                                                                                                                    {
                                                                                                                                                                                      TPanel::set_help_info((TPanel *)v1->victory_cond_on[4], 30473, -1);
                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, &v1->victory_cond_on[5]) )
                                                                                                                                                                                      {
                                                                                                                                                                                        TPanel::set_help_info((TPanel *)v1->victory_cond_on[5], 30474, -1);
                                                                                                                                                                                        v32 = (TPanel **)v1->victory_and_or;
                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, v1->victory_and_or) )
                                                                                                                                                                                        {
                                                                                                                                                                                          TPanel::set_help_info(*v32, 30465, -1);
                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->victory_and_or[1]) )
                                                                                                                                                                                          {
                                                                                                                                                                                            TPanel::set_help_info((TPanel *)v1->victory_and_or[1], 30467, -1);
                                                                                                                                                                                            v33 = v1->victory_and_or;
                                                                                                                                                                                            v34 = 2;
                                                                                                                                                                                            do
                                                                                                                                                                                            {
                                                                                                                                                                                              TButtonPanel::set_radio_info(*v33, v1->victory_and_or, 2);
                                                                                                                                                                                              ++v33;
                                                                                                                                                                                              --v34;
                                                                                                                                                                                            }
                                                                                                                                                                                            while ( v34 );
                                                                                                                                                                                            TButtonPanel::set_radio_button((TButtonPanel *)*v32);
                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->victory_text_and_or, 10402) )
                                                                                                                                                                                            {
                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_text_and_or[1], 10403) )
                                                                                                                                                                                              {
                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_amount_label, 10404) )
                                                                                                                                                                                                {
                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_long_label, 10405) )
                                                                                                                                                                                                  {
                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_condition_label, 4320) )
                                                                                                                                                                                                    {
                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_conquest, 4321) )
                                                                                                                                                                                                      {
                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_explore, 4322) )
                                                                                                                                                                                                        {
                                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_explore_percent, 4327) )
                                                                                                                                                                                                          {
                                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_ruins, 4323) )
                                                                                                                                                                                                            {
                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_artifacts, 4324) )
                                                                                                                                                                                                              {
                                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_discoveries, 4325) )
                                                                                                                                                                                                                {
                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_label_gold, 4326) )
                                                                                                                                                                                                                  {
                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->victory_condition_explore, text_in, 3, FormatUnsignedInt, 0, 0) )
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->victory_condition_explore->vfptr, 30475, -1);
                                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->victory_condition_ruins, text_in, 2, FormatUnsignedInt, 0, 0) )
                                                                                                                                                                                                                      {
                                                                                                                                                                                                                        TPanel::set_help_info((TPanel *)&v1->victory_condition_ruins->vfptr, 30476, -1);
                                                                                                                                                                                                                        v35 = (TPanel **)&v1->victory_condition_artifacts;
                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->victory_condition_artifacts, text_in, 2, FormatUnsignedInt, 0, 0) )
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                          TPanel::set_help_info(*v35, 30477, -1);
                                                                                                                                                                                                                          v36 = (TPanel **)&v1->victory_condition_discoveries;
                                                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->victory_condition_discoveries, text_in, 2, FormatUnsignedInt, 0, 0) )
                                                                                                                                                                                                                          {
                                                                                                                                                                                                                            TPanel::set_help_info(*v36, 30478, -1);
                                                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->victory_condition_gold, text_in, 5, FormatUnsignedInt, 0, 0) )
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)&v1->victory_condition_gold->vfptr, 30479, -1);
                                                                                                                                                                                                                              v37 = (TPanel *)&v1->victory_condition_explore->vfptr;
                                                                                                                                                                                                                              v38 = *v35;
                                                                                                                                                                                                                              ptr[1] = (TPanel *)&v1->victory_condition_ruins->vfptr;
                                                                                                                                                                                                                              ptr[0] = v37;
                                                                                                                                                                                                                              v39 = *v36;
                                                                                                                                                                                                                              ptr[2] = v38;
                                                                                                                                                                                                                              ptr[3] = v39;
                                                                                                                                                                                                                              i((TPanel *)&v1->vfptr, (TPanel *)ptr, (TPanel *)4);
                                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->victory_cond_type_label, 4332) )
                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_cond_type_label[1], 4321) )
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_cond_type_label[2], 4330) )
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_cond_type_label[3], 4329) )
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_cond_type_label[4], 4331) )
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, v1->victory_cond_type) )
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                          TPanel::set_help_info((TPanel *)v1->victory_cond_type[0], 30550, -1);
                                                                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->victory_cond_type[1]) )
                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)v1->victory_cond_type[1], 30551, -1);
                                                                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->victory_cond_type[2]) )
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->victory_cond_type[2], 30552, -1);
                                                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->victory_cond_type[3]) )
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                TPanel::set_help_info((TPanel *)v1->victory_cond_type[3], 30553, -1);
                                                                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, &v1->victory_cond_type[4]) )
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                  TPanel::set_help_info((TPanel *)v1->victory_cond_type[4], 30554, -1);
                                                                                                                                                                                                                                                  v40 = v1->victory_cond_type;
                                                                                                                                                                                                                                                  v41 = 5;
                                                                                                                                                                                                                                                  do
                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                    TButtonPanel::set_radio_info(*v40, v1->victory_cond_type, 5);
                                                                                                                                                                                                                                                    ++v40;
                                                                                                                                                                                                                                                    --v41;
                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                  while ( v41 );
                                                                                                                                                                                                                                                  TButtonPanel::set_radio_button(v1->victory_cond_type[1]);
                                                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_score_label, 4330) )
                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                    v42 = (TPanel **)&v1->victory_score;
                                                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_score) )
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                      TPanel::set_help_info(*v42, 30555, -1);
                                                                                                                                                                                                                                                      TDropDownPanel::empty_list((TDropDownPanel *)*v42);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a3000, 3000);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a2700, 2700);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a2400, 2400);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a2100, 2100);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a1800, 1800);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a1500, 1500);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a1200, 1200);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a900, 900);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a800, 800);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a700, 700);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a600, 600);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a500, 500);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a400, 400);
                                                                                                                                                                                                                                                      TDropDownPanel::append_line((TDropDownPanel *)*v42, a300, 300);
                                                                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_time_label, 4329) )
                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                        v43 = (TPanel **)&v1->victory_time;
                                                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_time) )
                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                          TPanel::set_help_info(*v43, 30556, -1);
                                                                                                                                                                                                                                                          TDropDownPanel::empty_list((TDropDownPanel *)*v43);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9780, 15000);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9781, 13000);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9782, 11000);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9783, 9000);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9784, 7000);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9785, 5000);
                                                                                                                                                                                                                                                          TDropDownPanel::append_line((TDropDownPanel *)*v43, 9786, 3000);
                                                                                                                                                                                                                                                          v44 = 1;
                                                                                                                                                                                                                                                          v45 = v1->victory_button;
                                                                                                                                                                                                                                                          while ( 1 )
                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                            sprintf(str1, aD_3, v44);
                                                                                                                                                                                                                                                            sprintf(str2, aD_0, v44);
                                                                                                                                                                                                                                                            sprintf(str3, aD_1, v44);
                                                                                                                                                                                                                                                            sprintf(str4, aD_4, v44);
                                                                                                                                                                                                                                                            if ( !TRIBE_Screen_Sed::create_button(v1, v1->bottom_panel, v45, str1, str2, str3, str4) )
                                                                                                                                                                                                                                                              break;
                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)*v45, 30482, -1);
                                                                                                                                                                                                                                                            ++v45;
                                                                                                                                                                                                                                                            if ( ++v44 - 1 >= 12 )
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_drop_down) )
                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_object_list) )
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_player_list) )
                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_enemy_player_list) )
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_attribute_list) )
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_ages_list) )
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->victory_tech_list) )
                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_drop_down->vfptr, 30486, -1);
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_object_list->vfptr, 30484, -1);
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_player_list->vfptr, 30483, -1);
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_ages_list->vfptr, 30485, -1);
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_enemy_player_list->vfptr, 30560, -1);
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_attribute_list->vfptr, 30561, -1);
                                                                                                                                                                                                                                                                            TPanel::set_help_info((TPanel *)&v1->victory_tech_list->vfptr, 30562, -1);
                                                                                                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_condition_text, 10352) )
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_condition_type, 10353) )
                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_button(v1, v1->bottom_panel, &v1->victory_button_set_object, 10354, 0) )
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_button(v1, v1->bottom_panel, &v1->victory_button_set_destination, 10355, 0) )
                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_button(v1, v1->bottom_panel, &v1->victory_button_go_to_dest, 10356, 0) )
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                      TPanel::set_help_info((TPanel *)v1->victory_button_set_object, 30487, -1);
                                                                                                                                                                                                                                                                                      TPanel::set_help_info((TPanel *)v1->victory_button_set_destination, 30488, -1);
                                                                                                                                                                                                                                                                                      TPanel::set_help_info((TPanel *)v1->victory_button_go_to_dest, 30489, -1);
                                                                                                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_amount_text, 10357) )
                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->victory_which_enemy_text, 10358) && TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->victory_amount_input, text, 5, FormatUnsignedInt, 0, 0) )
                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                          v46 = 0;
                                                                                                                                                                                                                                                                                          v47 = v1->message_button;
                                                                                                                                                                                                                                                                                          while ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, v47) )
                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                            ++v46;
                                                                                                                                                                                                                                                                                            ++v47;
                                                                                                                                                                                                                                                                                            if ( v46 >= 5 )
                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                              v48 = (TPanel *)v1->message_button[0];
                                                                                                                                                                                                                                                                                              v1->current_message = 0;
                                                                                                                                                                                                                                                                                              TPanel::set_help_info(v48, 30492, -1);
                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->message_button[1], 30493, -1);
                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->message_button[2], 30494, -1);
                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->message_button[3], 30495, -1);
                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->message_button[4], 30496, -1);
                                                                                                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->message_button_label, 10806) )
                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->message_button_label[1], 10807) )
                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->message_button_label[2], 10808) )
                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->message_button_label[3], 10809) )
                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                      if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->message_button_label[4], 10801) )
                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                        v49 = v1->message_button;
                                                                                                                                                                                                                                                                                                        v50 = 5;
                                                                                                                                                                                                                                                                                                        do
                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                          TButtonPanel::set_radio_info(*v49, v1->message_button, 5);
                                                                                                                                                                                                                                                                                                          ++v49;
                                                                                                                                                                                                                                                                                                          --v50;
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                        while ( v50 );
                                                                                                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_edit(v1, v1->bottom_panel, &v1->message_input, message_in, 4095, FormatMultiLine, 1, 1) )
                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                          TPanel::set_help_info((TPanel *)&v1->message_input->vfptr, -1, -1);
                                                                                                                                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->cinematic_label, 11001) )
                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->cinematic_label[1], 11002) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->cinematic_label[2], 11003) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->cinematic_label[3], 11004) )
                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                              v51 = 0;
                                                                                                                                                                                                                                                                                                              v52 = v1->cinematic_input;
                                                                                                                                                                                                                                                                                                              while ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, v52) )
                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                ++v51;
                                                                                                                                                                                                                                                                                                                ++v52;
                                                                                                                                                                                                                                                                                                                if ( v51 >= 4 )
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                  TPanel::set_help_info((TPanel *)&v1->cinematic_input[0]->vfptr, 30500, -1);
                                                                                                                                                                                                                                                                                                                  TPanel::set_help_info((TPanel *)&v1->cinematic_input[1]->vfptr, 30501, -1);
                                                                                                                                                                                                                                                                                                                  TPanel::set_help_info((TPanel *)&v1->cinematic_input[2]->vfptr, 30502, -1);
                                                                                                                                                                                                                                                                                                                  TPanel::set_help_info((TPanel *)&v1->cinematic_input[3]->vfptr, 30503, -1);
                                                                                                                                                                                                                                                                                                                  if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->options_label, 9732) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_tech_text, 13015) )
                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                    v53 = 0;
                                                                                                                                                                                                                                                                                                                    v54 = v1->options_button;
                                                                                                                                                                                                                                                                                                                    while ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, v54) )
                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                      ++v53;
                                                                                                                                                                                                                                                                                                                      ++v54;
                                                                                                                                                                                                                                                                                                                      if ( v53 >= 1 )
                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                        TPanel::set_help_info((TPanel *)v1->options_button[0], 30505, -1);
                                                                                                                                                                                                                                                                                                                        if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->options_player_list) )
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                          TPanel::set_help_info((TPanel *)&v1->options_player_list->vfptr, 30507, -1);
                                                                                                                                                                                                                                                                                                                          v55 = 0;
                                                                                                                                                                                                                                                                                                                          v56 = v1->options_disable_button;
                                                                                                                                                                                                                                                                                                                          while ( TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, v56) )
                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                            ++v55;
                                                                                                                                                                                                                                                                                                                            ++v56;
                                                                                                                                                                                                                                                                                                                            if ( v55 >= 16 )
                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[0], 30508, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[1], 30509, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[2], 30510, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[3], 30511, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[4], 30512, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[5], 30513, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[6], 30514, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[7], 30515, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[8], 30516, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[9], 30517, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[10], 30518, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[11], 30519, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[12], 30520, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[13], 30521, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[14], 30522, -1);
                                                                                                                                                                                                                                                                                                                              TPanel::set_help_info((TPanel *)v1->options_disable_button[15], 30523, -1);
                                                                                                                                                                                                                                                                                                                              if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->options_disable_text, 13001) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[1], 13002) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[2], 13003) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[3], 13004) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[4], 13005) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[5], 13006) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[6], 13007) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[7], 13008) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[8], 13009) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[9], 13010) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[10], 13011) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[11], 13012) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[12], 13013) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[13], 13014) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[14], 13016) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->options_disable_text[15], 13017) )
                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                v57 = 0;
                                                                                                                                                                                                                                                                                                                                v58 = v1->Diplomacy_player_text;
                                                                                                                                                                                                                                                                                                                                while ( 1 )
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                  v59 = v57 + 1;
                                                                                                                                                                                                                                                                                                                                  sprintf(str1, aD_3, v57 + 1);
                                                                                                                                                                                                                                                                                                                                  if ( !TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v58, str1) )
                                                                                                                                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                                                                                                                  v57 = v59;
                                                                                                                                                                                                                                                                                                                                  ++v58;
                                                                                                                                                                                                                                                                                                                                  if ( v59 >= 8 )
                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                    if ( TRIBE_Screen_Sed::create_drop_down(v1, v1->bottom_panel, &v1->Diplomacy_player_list) )
                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                      TPanel::set_help_info((TPanel *)&v1->Diplomacy_player_list->vfptr, 30525, -1);
                                                                                                                                                                                                                                                                                                                                      ia = 0;
                                                                                                                                                                                                                                                                                                                                      button = v1->Diplomacy_AlliedVictory;
                                                                                                                                                                                                                                                                                                                                      v60 = (int)v1->Diplomacy_friend_box;
                                                                                                                                                                                                                                                                                                                                      while ( TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, (TButtonPanel **)v60) )
                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                        TPanel::set_help_info(*(TPanel **)v60, 30527, -1);
                                                                                                                                                                                                                                                                                                                                        v61 = (TPanel **)(v60 + 4);
                                                                                                                                                                                                                                                                                                                                        if ( !TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, (TButtonPanel **)(v60 + 4)) )
                                                                                                                                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                                                                                                                                        TPanel::set_help_info(*v61, 30528, -1);
                                                                                                                                                                                                                                                                                                                                        v62 = (TPanel **)(v60 + 8);
                                                                                                                                                                                                                                                                                                                                        if ( !TRIBE_Screen_Sed::create_radio_button(v1, v1->bottom_panel, (TButtonPanel **)(v60 + 8)) )
                                                                                                                                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                                                                                                                                        TPanel::set_help_info(*v62, 30529, -1);
                                                                                                                                                                                                                                                                                                                                        TButtonPanel::set_radio_info(*(TButtonPanel **)v60, (TButtonPanel **)v60, 3);
                                                                                                                                                                                                                                                                                                                                        TButtonPanel::set_radio_info((TButtonPanel *)*v61, (TButtonPanel **)v60, 3);
                                                                                                                                                                                                                                                                                                                                        TButtonPanel::set_radio_info((TButtonPanel *)*v62, (TButtonPanel **)v60, 3);
                                                                                                                                                                                                                                                                                                                                        TButtonPanel::set_radio_button((TButtonPanel *)*v61);
                                                                                                                                                                                                                                                                                                                                        if ( !TRIBE_Screen_Sed::create_check_box(v1, v1->bottom_panel, button) )
                                                                                                                                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                                                                                                                                        TPanel::set_help_info((TPanel *)*button, 30526, -1);
                                                                                                                                                                                                                                                                                                                                        v60 += 12;
                                                                                                                                                                                                                                                                                                                                        v64 = __OFSUB__(ia + 1, 8);
                                                                                                                                                                                                                                                                                                                                        v63 = ia++ - 7 < 0;
                                                                                                                                                                                                                                                                                                                                        ++button;
                                                                                                                                                                                                                                                                                                                                        if ( !(v63 ^ v64) )
                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                          if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, v1->Diplomacy_status_label, 10701) && TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->Diplomacy_status_label[1], 10702) )
                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                            if ( TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->Diplomacy_status_label[2], 10703) )
                                                                                                                                                                                                                                                                                                                                              TRIBE_Screen_Sed::create_text(v1, v1->bottom_panel, &v1->Diplomacy_status_label[3], 10704);
                                                                                                                                                                                                                                                                                                                                          }
                                                                                                                                                                                                                                                                                                                                          return;
                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                    return;
                                                                                                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                              }
                                                                                                                                                                                                                                                                                                                              return;
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                          }
                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                        return;
                                                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                                                                                  return;
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
                                                                                                                                                                                                                                                                                              return;
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
                                                                                                                                                                                                                                                              }
                                                                                                                                                                                                                                                              return;
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
                                                                                                                                                                  }
                                                                                                                                                                }
                                                                                                                                                                return;
                                                                                                                                                              }
                                                                                                                                                            }
                                                                                                                                                          }
                                                                                                                                                        }
                                                                                                                                                      }
                                                                                                                                                      return;
                                                                                                                                                    }
                                                                                                                                                  }
                                                                                                                                                }
                                                                                                                                              }
                                                                                                                                            }
                                                                                                                                          }
                                                                                                                                        }
                                                                                                                                      }
                                                                                                                                    }
                                                                                                                                    return;
                                                                                                                                  }
                                                                                                                                  break;
                                                                                                                                }
                                                                                                                              }
                                                                                                                            }
                                                                                                                            v1->error_code = 1;
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
  }
}

//----- (004B1A50) --------------------------------------------------------
void __usercall TRIBE_Screen_Sed::position_panels(TRIBE_Screen_Sed *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  TRIBE_Screen_Sed *v4; // esi@1
  signed int v5; // edi@2
  int v6; // eax@4
  signed int v7; // edi@7
  int v8; // eax@9
  TTextPanel *v9; // edi@12
  int v10; // ebx@12
  signed int v11; // ebp@14
  int v12; // ebx@14
  signed int v13; // edi@15
  signed int v14; // edi@18
  int v15; // ebx@18
  signed int v16; // edi@20
  int v17; // ebx@20
  signed int v18; // edi@22
  int v19; // ebx@22
  signed int v20; // edi@24
  int v21; // ebx@24
  signed int v22; // ebx@26
  int v23; // edi@26
  int v24; // ebx@28
  signed int v25; // edi@28
  int v26; // ebx@30
  signed int v27; // edi@30
  int v28; // ebx@32
  signed int v29; // edi@32
  signed int v30; // edi@34
  int v31; // ebp@34
  int v32; // ebx@34
  int v33; // [sp-4h] [bp-8h]@2

  v4 = this;
  if ( this->main_view )
  {
    v33 = a4;
    v5 = 0;
    do
    {
      if ( v5 )
        v6 = *((_DWORD *)&v4->bottom_panel + v5);
      else
        v6 = 0;
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4->scenario_mode_button[v5++] + 24))(
        7,
        2,
        2,
        2,
        2,
        50,
        109,
        22,
        22,
        v6,
        0,
        0,
        0);
    }
    while ( v5 < 5 );
    v7 = 5;
    do
    {
      if ( v7 == 5 )
        v8 = 0;
      else
        v8 = *((_DWORD *)&v4->bottom_panel + v7);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4->scenario_mode_button[v7] + 24))(
        7,
        2,
        2,
        2,
        2,
        50,
        109,
        22,
        22,
        v8,
        *((_DWORD *)&v4->background_pic + v7),
        0,
        0);
      ++v7;
    }
    while ( v7 < 10 );
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))(*(_DWORD *)v4->menu_button + 24))(
      9,
      2,
      5,
      3,
      3,
      58,
      58,
      20,
      40,
      0,
      0,
      0,
      0,
      a2,
      a3,
      v33);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4->help_button + 24))(
      10,
      5,
      5,
      5,
      5,
      20,
      30,
      20,
      30,
      0,
      0,
      0,
      0);
    (*(void (__stdcall **)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v4->map_view->vfptr->gap10[8])(
      10,
      0,
      0,
      0,
      0,
      230,
      230,
      135,
      135,
      0,
      0,
      0,
      0);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, RGE_Diamond_Map_View *, _DWORD))&v4->bottom_panel->vfptr->gap10[8])(
      8,
      2,
      2,
      2,
      2,
      0,
      0,
      137,
      137,
      0,
      0,
      v4->map_view,
      0);
    (*(void (__stdcall **)(signed int, _DWORD, signed int, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, TButtonPanel *, _DWORD, TPanel *))&v4->unit_list->vfptr->gap10[8])(
      7,
      0,
      6,
      0,
      4,
      124,
      200,
      0,
      0,
      0,
      v4->menu_button,
      0,
      v4->bottom_panel);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v4->object_panel->vfptr->gap10[8])(
      8,
      4,
      4,
      4,
      4,
      150,
      150,
      108,
      108,
      0,
      0,
      0,
      0);
    v9 = (TTextPanel *)&v4->unit_list->vfptr;
    v10 = TTextPanel::numberLines((TTextPanel *)&v4->unit_list->vfptr);
    if ( v10 > TTextPanel::numberDrawLines(v9) )
    {
      (*(void (__stdcall **)(signed int, _DWORD, signed int, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, TButtonPanel *, _DWORD, TPanel *))&v4->unit_list->vfptr->gap10[8])(
        7,
        0,
        6,
        0,
        4,
        104,
        220,
        0,
        0,
        0,
        v4->menu_button,
        0,
        v4->bottom_panel);
      (*(void (__stdcall **)(signed int, signed int, signed int, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD, TListPanel *, TButtonPanel *, _DWORD, TPanel *))&v4->unit_scrollbar->vfptr->gap10[8])(
        7,
        1,
        1,
        0,
        2,
        18,
        18,
        0,
        0,
        v4->unit_list,
        v4->menu_button,
        0,
        v4->bottom_panel);
      v9 = (TTextPanel *)v4->unit_scrollbar;
    }
    (*(void (__stdcall **)(signed int, _DWORD, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *, TButtonPanel *, _DWORD, TPanel *))&v4->main_view->vfptr->gap10[8])(
      7,
      0,
      6,
      0,
      4,
      0,
      0,
      0,
      0,
      v9,
      v4->menu_button,
      0,
      v4->bottom_panel);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v4->message_panel->vfptr->gap10[8])(
      8,
      4,
      4,
      4,
      4,
      0,
      0,
      24,
      24,
      0,
      0,
      0,
      0);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_type_label->vfptr->set_fixed_position)(
      4,
      4,
      120,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->map_type_button[0] + 28))(
      4,
      22,
      22,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->map_type_button[1] + 28))(
      4,
      44,
      22,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->map_type_button[2] + 28))(
      4,
      66,
      22,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_type_text[0]->vfptr->set_fixed_position)(
      36,
      22,
      115,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_type_text[1]->vfptr->set_fixed_position)(
      36,
      44,
      115,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_type_text[2]->vfptr->set_fixed_position)(
      36,
      66,
      115,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_size_label->vfptr->set_fixed_position)(
      170,
      4,
      130,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_size_drop->vfptr->set_fixed_position)(
      170,
      22,
      170,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_style_label->vfptr->set_fixed_position)(
      170,
      48,
      130,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->map_style_drop->vfptr->set_fixed_position)(
      170,
      66,
      170,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->default_terrain_label->vfptr->set_fixed_position)(
      170,
      48,
      130,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->default_terrain_drop->vfptr->set_fixed_position)(
      170,
      66,
      170,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->random_seed_label->vfptr->set_fixed_position)(
      36,
      90,
      120,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->random_seed_input->vfptr->set_fixed_position)(
      36,
      112,
      55,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->random_seed_used_label->vfptr->set_fixed_position)(
      36,
      90,
      120,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->random_seed_used_text->vfptr->set_fixed_position)(
      36,
      112,
      55,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->generate_map_button + 28))(
      180,
      96,
      130,
      38);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_terrain_list->vfptr->set_fixed_position)(
      115,
      23,
      165,
      110);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_terrain_label->vfptr->set_fixed_position)(
      115,
      1,
      60,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_elevation_list->vfptr->set_fixed_position)(
      115,
      23,
      165,
      110);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_type_label->vfptr->set_fixed_position)(
      2,
      1,
      110,
      20);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->paint_type_button[0] + 28))(
      2,
      23,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->paint_type_button[1] + 28))(
      2,
      45,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->paint_type_button[2] + 28))(
      2,
      67,
      30,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_type_button_label[0]->vfptr->set_fixed_position)(
      33,
      23,
      81,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_type_button_label[1]->vfptr->set_fixed_position)(
      33,
      45,
      81,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->paint_type_button_label[2]->vfptr->set_fixed_position)(
      33,
      67,
      81,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->brush_size_label->vfptr->set_fixed_position)(
      280,
      4,
      110,
      20);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->brush_size_button[0] + 28))(
      282,
      23,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->brush_size_button[1] + 28))(
      282,
      45,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->brush_size_button[2] + 28))(
      282,
      67,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->brush_size_button[3] + 28))(
      282,
      89,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->brush_size_button[4] + 28))(
      282,
      111,
      30,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->brush_size_button_label[0]->vfptr->set_fixed_position)(
      313,
      23,
      90,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->brush_size_button_label[1]->vfptr->set_fixed_position)(
      313,
      45,
      90,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->brush_size_button_label[2]->vfptr->set_fixed_position)(
      313,
      67,
      90,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->brush_size_button_label[3]->vfptr->set_fixed_position)(
      313,
      89,
      90,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->brush_size_button_label[4]->vfptr->set_fixed_position)(
      313,
      111,
      90,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_label->vfptr->set_fixed_position)(
      4,
      4,
      80,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_starting_age_label->vfptr->set_fixed_position)(
      4,
      92,
      95,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_advance_civilization_drop->vfptr->set_fixed_position)(
      4,
      110,
      150,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_label->vfptr->set_fixed_position)(
      4,
      42,
      150,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_list->vfptr->set_fixed_position)(
      4,
      7,
      150,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_number_list->vfptr->set_fixed_position)(
      4,
      62,
      150,
      22);
    v11 = 166;
    v12 = (int)v4->player_inven_input;
    do
    {
      v13 = 25;
      do
      {
        (*(void (__stdcall **)(signed int, int, signed int, signed int))(**(_DWORD **)(v12 - 20) + 28))(
          v11,
          v13 - 18,
          55,
          18);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v12 + 28))(
          v11,
          v13,
          55,
          22);
        v13 += 44;
        v12 += 4;
      }
      while ( v13 < 113 );
      v11 += 68;
    }
    while ( v11 < 302 );
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_inven_label[4]->vfptr->set_fixed_position)(
      166,
      92,
      100,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_inven_input[4]->vfptr->set_fixed_position)(
      166,
      110,
      125,
      22);
    v14 = 25;
    v15 = (int)v4->player_setting_drop;
    do
    {
      (*(void (__stdcall **)(signed int, int, signed int, signed int))(**(_DWORD **)(v15 - 12) + 28))(
        500,
        v14 - 18,
        130,
        18);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v15 + 28))(500, v14, 130, 22);
      v14 += 44;
      v15 += 4;
    }
    while ( v14 < 113 );
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->BuildList->vfptr->set_fixed_position)(
      300,
      69,
      190,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->CityLayout->vfptr->set_fixed_position)(
      300,
      25,
      190,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_build_text->vfptr->set_fixed_position)(
      300,
      51,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->player_city_text->vfptr->set_fixed_position)(
      300,
      7,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->AiRules_text->vfptr->set_fixed_position)(
      300,
      92,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->AiRules->vfptr->set_fixed_position)(
      300,
      110,
      190,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->unit_player_list->vfptr->set_fixed_position)(
      4,
      4,
      150,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->unit_mode_select[0] + 28))(
      160,
      22,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->unit_mode_select[1] + 28))(
      160,
      48,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->unit_mode_select[2] + 28))(
      160,
      74,
      30,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->unit_mode_select[3] + 28))(
      160,
      98,
      30,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->unit_mode_select_label[0]->vfptr->set_fixed_position)(
      192,
      22,
      110,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->unit_mode_select_label[1]->vfptr->set_fixed_position)(
      192,
      48,
      110,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->unit_mode_select_label[2]->vfptr->set_fixed_position)(
      192,
      74,
      110,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->unit_mode_select_label[3]->vfptr->set_fixed_position)(
      192,
      98,
      110,
      22);
    ((void (__stdcall *)(signed int, _DWORD, signed int, signed int))v4->victory_condition_label->vfptr->set_fixed_position)(
      34,
      0,
      120,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_type[0] + 28))(
      14,
      18,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_type[1] + 28))(
      14,
      38,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_type[2] + 28))(
      14,
      58,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_type[3] + 28))(
      14,
      78,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_type[4] + 28))(
      14,
      98,
      20,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_cond_type_label[0]->vfptr->set_fixed_position)(
      34,
      18,
      120,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_cond_type_label[1]->vfptr->set_fixed_position)(
      34,
      38,
      120,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_cond_type_label[2]->vfptr->set_fixed_position)(
      34,
      58,
      120,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_cond_type_label[3]->vfptr->set_fixed_position)(
      34,
      78,
      120,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_cond_type_label[4]->vfptr->set_fixed_position)(
      34,
      98,
      120,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_score_label->vfptr->set_fixed_position)(
      164,
      18,
      100,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_score->vfptr->set_fixed_position)(
      164,
      40,
      100,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_time_label->vfptr->set_fixed_position)(
      164,
      18,
      220,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_time->vfptr->set_fixed_position)(
      164,
      40,
      220,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_on[0] + 28))(
      164,
      18,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_on[1] + 28))(
      164,
      38,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_on[2] + 28))(
      164,
      58,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_on[3] + 28))(
      164,
      78,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_on[4] + 28))(
      164,
      98,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_cond_on[5] + 28))(
      164,
      118,
      20,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_label_conquest->vfptr->set_fixed_position)(
      184,
      18,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_label_explore->vfptr->set_fixed_position)(
      184,
      38,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_label_ruins->vfptr->set_fixed_position)(
      184,
      58,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_label_artifacts->vfptr->set_fixed_position)(
      184,
      78,
      130,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_label_discoveries->vfptr->set_fixed_position)(
      184,
      98,
      130,
      18);
    ((void (__stdcall *)(signed int, _DWORD, signed int, signed int))v4->victory_amount_label->vfptr->set_fixed_position)(
      294,
      0,
      90,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_condition_explore->vfptr->set_fixed_position)(
      294,
      38,
      60,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_condition_ruins->vfptr->set_fixed_position)(
      294,
      58,
      60,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_condition_artifacts->vfptr->set_fixed_position)(
      294,
      78,
      60,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_condition_discoveries->vfptr->set_fixed_position)(
      294,
      98,
      60,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_and_or[0] + 28))(
      384,
      18,
      20,
      18);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_and_or[1] + 28))(
      384,
      38,
      20,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_text_and_or[0]->vfptr->set_fixed_position)(
      404,
      18,
      90,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_text_and_or[1]->vfptr->set_fixed_position)(
      404,
      38,
      90,
      18);
    v16 = 0;
    v17 = (int)v4->victory_button;
    do
    {
      (*(void (__stdcall **)(int, _DWORD, signed int, signed int))(**(_DWORD **)v17 + 28))(
        48 * (v16 / 4) + 220,
        26 * ((((unsigned __int64)v16 >> 32) ^ abs(v16) & 3) - ((unsigned __int64)v16 >> 32)) + 30,
        44,
        22);
      ++v16;
      v17 += 4;
    }
    while ( v16 < 12 );
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_player_list->vfptr->set_fixed_position)(
      4,
      4,
      150,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_drop_down->vfptr->set_fixed_position)(
      4,
      28,
      180,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_condition_text->vfptr->set_fixed_position)(
      220,
      4,
      140,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_button_set_object + 28))(
      4,
      56,
      150,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_button_set_destination
                                                                          + 28))(
      4,
      82,
      150,
      22);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v4->victory_button_go_to_dest + 28))(
      4,
      108,
      150,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_amount_text->vfptr->set_fixed_position)(
      160,
      80,
      60,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_amount_input->vfptr->set_fixed_position)(
      160,
      102,
      50,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_enemy_player_list->vfptr->set_fixed_position)(
      4,
      102,
      150,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_attribute_list->vfptr->set_fixed_position)(
      4,
      56,
      180,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_which_enemy_text->vfptr->set_fixed_position)(
      4,
      80,
      150,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_object_list->vfptr->set_fixed_position)(
      4,
      56,
      180,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_ages_list->vfptr->set_fixed_position)(
      4,
      56,
      180,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->victory_tech_list->vfptr->set_fixed_position)(
      4,
      56,
      180,
      22);
    v18 = 8;
    v19 = (int)v4->message_button_label;
    do
    {
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v19 - 20) + 28))(
        4,
        v18,
        30,
        18);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v19 + 28))(36, v18, 130, 18);
      v18 += 25;
      v19 += 4;
    }
    while ( v18 < 133 );
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v4->message_input->vfptr->gap10[8])(
      7,
      175,
      4,
      40,
      4,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0);
    v20 = 22;
    v21 = (int)v4->cinematic_input;
    do
    {
      (*(void (__stdcall **)(signed int, int, signed int, signed int))(**(_DWORD **)(v21 - 16) + 28))(
        4,
        v20 - 18,
        170,
        18);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v21 + 28))(4, v20, 170, 22);
      v20 += 44;
      v21 += 4;
    }
    while ( v20 < 154 );
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->cinematic_label[3]->vfptr->set_fixed_position)(
      178,
      4,
      170,
      18);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->cinematic_input[3]->vfptr->set_fixed_position)(
      178,
      22,
      170,
      22);
    v22 = 44;
    v23 = (int)v4->options_label;
    do
    {
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v23 + 4) + 28))(
        3,
        v22,
        20,
        20);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v23 + 28))(22, v22, 135, 20);
      v22 += 26;
      v23 += 4;
    }
    while ( v22 < 70 );
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->options_disable_tech_text->vfptr->set_fixed_position)(
      160,
      3,
      160,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->options_player_list->vfptr->set_fixed_position)(
      3,
      3,
      150,
      22);
    v24 = (int)v4->options_disable_text;
    v25 = 26;
    do
    {
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v24 - 64) + 28))(
        160,
        v25,
        20,
        20);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v24 + 28))(180, v25, 135, 20);
      v25 += 20;
      v24 += 4;
    }
    while ( v25 < 126 );
    v26 = (int)&v4->options_disable_text[5];
    v27 = 26;
    do
    {
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v26 - 64) + 28))(
        315,
        v27,
        20,
        20);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v26 + 28))(335, v27, 135, 20);
      v27 += 20;
      v26 += 4;
    }
    while ( v27 < 126 );
    v28 = (int)&v4->options_disable_text[10];
    v29 = 6;
    do
    {
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v28 - 64) + 28))(
        470,
        v29,
        20,
        20);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v28 + 28))(490, v29, 135, 20);
      v29 += 20;
      v28 += 4;
    }
    while ( v29 < 126 );
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->Diplomacy_player_list->vfptr->set_fixed_position)(
      4,
      4,
      150,
      22);
    v30 = 150;
    v31 = (int)v4->Diplomacy_AlliedVictory;
    v32 = (int)&v4->Diplomacy_friend_box[0][1];
    do
    {
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v31 - 148) + 28))(
        v30,
        28,
        30,
        22);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v32 - 4) + 28))(
        v30,
        52,
        26,
        18);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v32 + 28))(v30, 72, 26, 18);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)(v32 + 4) + 28))(
        v30,
        92,
        26,
        18);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v31 + 28))(v30, 112, 26, 18);
      v30 += 31;
      v31 += 4;
      v32 += 12;
    }
    while ( v30 < 398 );
    ((void (__stdcall *)(signed int))v4->Diplomacy_status_label[0]->vfptr->set_fixed_position)(2);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->Diplomacy_status_label[1]->vfptr->set_fixed_position)(
      2,
      72,
      145,
      22);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v4->Diplomacy_status_label[2]->vfptr->set_fixed_position)(
      2,
      92,
      145,
      22);
    v4->Diplomacy_status_label[3]->vfptr->set_fixed_position((TPanel *)v4->Diplomacy_status_label[3], 2, 112, 145, 22);
  }
}
// 4B1A50: could not find valid save-restore pair for ebx
// 4B1A50: could not find valid save-restore pair for ebp
// 4B1A50: could not find valid save-restore pair for edi

//----- (004B29E0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::activate_victory_panel(TRIBE_Screen_Sed *this, int activate)
{
  TRIBE_Screen_Sed *v2; // edi@1
  int v3; // esi@1
  char *v4; // ebp@1
  int v5; // eax@2

  v2 = this;
  v3 = 0;
  v4 = (char *)this->victory_button;
  do
  {
    (*(void (__stdcall **)(int))(**(_DWORD **)v4 + 20))(activate);
    v5 = (v2->CurrentVictory == v3) + (T_Scenario::GetSPVictoryType((T_Scenario *)v2->world->scenario, v3) != 0 ? 2 : 0);
    if ( activate )
      (*(void (__stdcall **)(int))(**(_DWORD **)v4 + 224))(v5);
    ++v3;
    v4 += 4;
  }
  while ( v3 < 12 );
  (*(void (__stdcall **)(int))&v2->victory_drop_down->vfptr->gap10[4])(activate);
  (*(void (__stdcall **)(int))&v2->victory_condition_text->vfptr->gap10[4])(activate);
  (*(void (__stdcall **)(int))&v2->victory_player_list->vfptr->gap10[4])(activate);
  if ( activate )
    TDropDownPanel::set_line(v2->victory_player_list, v2->player_num - 1);
  else
    v2->player_num = TDropDownPanel::get_line(v2->victory_player_list) + 1;
}

//----- (004B2AA0) --------------------------------------------------------
int __stdcall TRIBE_Screen_Sed::MakeFileList(TDropDownPanel *drop_down, char *dir, char *extension, char append_none, char append_random)
{
  __int32 v6; // ebp@5
  unsigned int v7; // kr0C_4@6
  int count; // [sp+10h] [bp-328h]@1
  int extension_strlen; // [sp+14h] [bp-324h]@5
  _finddata_t fileInfo; // [sp+18h] [bp-320h]@5
  char file_name[260]; // [sp+130h] [bp-208h]@6
  char path[260]; // [sp+234h] [bp-104h]@5

  count = 0;
  TDropDownPanel::empty_list(drop_down);
  if ( append_none )
    TDropDownPanel::append_line(drop_down, 10101, 0);
  if ( append_random )
    TDropDownPanel::append_line(drop_down, 10107, 0);
  sprintf(path, aSS_0, dir, extension);
  v6 = _findfirst(path, &fileInfo);
  extension_strlen = strlen(extension);
  if ( v6 != -1 )
  {
    do
    {
      ++count;
      v7 = strlen(fileInfo.name) + 1;
      strncpy(file_name, fileInfo.name, v7 - 1 - extension_strlen);
      file_name[v7 - 1 - extension_strlen] = 0;
      TDropDownPanel::append_line(drop_down, file_name, 0);
    }
    while ( _findnext(v6, &fileInfo) != -1 );
  }
  return count;
}

//----- (004B2BC0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::Set_player_advance_civilization_text(TRIBE_Screen_Sed *this, int newmode)
{
  TRIBE_Screen_Sed *v2; // esi@1

  v2 = this;
  TDropDownPanel::empty_list(this->player_advance_civilization_drop);
  TDropDownPanel::append_line(v2->player_advance_civilization_drop, 4201, 0);
  TDropDownPanel::append_line(v2->player_advance_civilization_drop, 4202, 1);
  TDropDownPanel::append_line(v2->player_advance_civilization_drop, 4203, 2);
  TDropDownPanel::append_line(v2->player_advance_civilization_drop, 4204, 3);
  TDropDownPanel::append_line(v2->player_advance_civilization_drop, 4205, 4);
  TDropDownPanel::setCurrentLineNumber(v2->player_advance_civilization_drop, 0);
  (*(void (__stdcall **)(_DWORD))&v2->player_advance_civilization_drop->vfptr->gap10[4])(0);
  return 1;
}

//----- (004B2C50) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed::SavePlayerActiveStatus(TRIBE_Screen_Sed *this)
{
  TRIBE_Screen_Sed *v1; // esi@1
  int v2; // ebx@1
  TRIBE_World *v3; // eax@1
  int v4; // ebx@1
  int i; // edi@1
  signed int v6; // edi@4

  v1 = this;
  v2 = TDropDownPanel::get_line(this->player_number_list);
  v3 = v1->world;
  v4 = v2 + 1;
  for ( i = 0; i < v3->player_num - 1; ++i )
  {
    RGE_Scenario::Set_player_Active(v3->scenario, i, i < v4);
    v3 = v1->world;
  }
  TDropDownPanel::empty_list(v1->victory_player_list);
  TDropDownPanel::empty_list(v1->victory_enemy_player_list);
  TDropDownPanel::empty_list(v1->options_player_list);
  TDropDownPanel::empty_list(v1->Diplomacy_player_list);
  TDropDownPanel::empty_list(v1->player_list);
  TDropDownPanel::empty_list(v1->unit_player_list);
  TDropDownPanel::append_line(v1->unit_player_list, 10102, 0);
  if ( v4 > 0 )
  {
    v6 = 10341;
    do
    {
      TDropDownPanel::append_line(v1->unit_player_list, v6, 0);
      TDropDownPanel::append_line(v1->victory_player_list, v6, 0);
      TDropDownPanel::append_line(v1->victory_enemy_player_list, v6, 0);
      TDropDownPanel::append_line(v1->options_player_list, v6, 0);
      TDropDownPanel::append_line(v1->Diplomacy_player_list, v6, 0);
      TDropDownPanel::append_line(v1->player_list, v6++, 0);
    }
    while ( v6 - 10341 < v4 );
  }
  if ( v1->player_num >= v4 )
    TRIBE_Screen_Sed::set_player(v1, v4, 0, 0);
  TDropDownPanel::set_line(v1->victory_player_list, v1->player_num - 1);
  TDropDownPanel::set_line(v1->options_player_list, v1->player_num - 1);
  TDropDownPanel::set_line(v1->Diplomacy_player_list, v1->player_num - 1);
  TDropDownPanel::set_line(v1->player_list, v1->player_num - 1);
  TDropDownPanel::set_line(v1->unit_player_list, v1->player_num);
}

//----- (004B2DD0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_check_box(TRIBE_Screen_Sed *this, TPanel *parent, TButtonPanel **button)
{
  TRIBE_Screen_Sed *v3; // esi@1
  int result; // eax@1

  v3 = this;
  result = TEasy_Panel::create_check_box((TEasy_Panel *)&this->vfptr, parent, button, 0, 0, 0, 0, 1, 0);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)*button, 1, 0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*button + 20))(0);
    if ( v3->use_bevels )
      TButtonPanel::set_bevel_info(
        *button,
        3,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    result = 1;
  }
  return result;
}

//----- (004B2E60) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed::create_radio_button(TRIBE_Screen_Sed *this, TPanel *parent, TButtonPanel **button)
{
  TRIBE_Screen_Sed *v3; // esi@1
  int result; // eax@1

  v3 = this;
  result = TEasy_Panel::create_radio_button((TEasy_Panel *)&this->vfptr, parent, button, 0, 0, 0, 0, 1, 0);
  if ( result )
  {
    TPanel::set_z_order((TPanel *)*button, 1, 0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*button + 20))(0);
    if ( v3->use_bevels )
      TButtonPanel::set_bevel_info(
        *button,
        3,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    result = 1;
  }
  return result;
}
