
//----- (004898D0) --------------------------------------------------------
void __thiscall RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(RGE_Panel_Tool_Box *this, TDrawArea *draw_area_in, TPanel *parent_in, int x, int y, int wid, int hgt, void *font, int font_wid, int font_hgt, TDigital *sound, TScreenPanel *screen_panel_in, RGE_View *view_in, RGE_Diamond_Map *map_in)
{
  RGE_Panel_Tool_Box *v14; // esi@1
  TButtonPanel *v15; // eax@5
  TPanel *v16; // eax@6
  TButtonPanel *v17; // eax@10
  TPanel *v18; // eax@11
  TButtonPanel *v19; // eax@15
  TPanel *v20; // eax@16
  TButtonPanel *v21; // eax@20
  TPanel *v22; // eax@21
  TButtonPanel *v23; // eax@25
  TPanel *v24; // eax@26
  TButtonPanel *v25; // eax@30
  TPanel *v26; // eax@31
  TButtonPanel *v27; // edx@35
  TButtonPanel *v28; // ecx@35
  TButtonPanel *v29; // eax@35
  TButtonPanel *v30; // edx@35
  TButtonPanel *v31; // edx@35
  TButtonPanel *v32; // eax@35
  TPanel *v33; // eax@36
  TButtonPanel *mode_buttons[6]; // [sp+14h] [bp-24h]@35
  int v35; // [sp+34h] [bp-4h]@1

  v14 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v14->screen_panel = screen_panel_in;
  v14->view = view_in;
  v14->map = map_in;
  v35 = 0;
  v14->vfptr = (TPanelVtbl *)&RGE_Panel_Tool_Box::`vftable';
  v14->game_mode_button = 0;
  v14->object_mode_button = 0;
  v14->delete_mode_button = 0;
  v14->move_mode_button = 0;
  v14->terrain_mode_button = 0;
  v14->elevation_mode_button = 0;
  v14->command_button = 0;
  v14->dialog = 0;
  if( !TPanel::setup((TPanel *)&v14->vfptr, draw_area_in, parent_in, x, y, wid, hgt, 0) )
    v14->error_code = 1;
  if( v14->view )
  {
    v15 = (TButtonPanel *)operator new(0x2B8u);
    LOBYTE(v35) = 1;
    if( v15 )
      TButtonPanel::TButtonPanel(v15);
    else
      v16 = 0;
    LOBYTE(v35) = 0;
    v14->game_mode_button = (TButtonPanel *)v16;
    if( v16 )
    {
      TButtonPanel::setup(
        v16,
        v14->render_area,
        (TPanel *)&v14->vfptr,
        0,
        0,
        50,
        30,
        (TPanel *)3,
        sound,
        (TPanel *)1,
        0);
      TButtonPanel::set_text_info(v14->game_mode_button, aGame, font, font_wid, font_hgt, -1, -1);
      TButtonPanel::set_text(v14->game_mode_button, 1, aGame_1);
      v17 = (TButtonPanel *)operator new(0x2B8u);
      LOBYTE(v35) = 2;
      if( v17 )
        TButtonPanel::TButtonPanel(v17);
      else
        v18 = 0;
      LOBYTE(v35) = 0;
      v14->object_mode_button = (TButtonPanel *)v18;
      if( v18 )
      {
        TButtonPanel::setup(
          v18,
          v14->render_area,
          (TPanel *)&v14->vfptr,
          52,
          0,
          50,
          30,
          (TPanel *)3,
          sound,
          (TPanel *)1,
          0);
        TButtonPanel::set_text_info(v14->object_mode_button, aObj_0, font, font_wid, font_hgt, -1, -1);
        TButtonPanel::set_text(v14->object_mode_button, 1, aObj);
        v19 = (TButtonPanel *)operator new(0x2B8u);
        LOBYTE(v35) = 3;
        if( v19 )
          TButtonPanel::TButtonPanel(v19);
        else
          v20 = 0;
        LOBYTE(v35) = 0;
        v14->move_mode_button = (TButtonPanel *)v20;
        if( v20 )
        {
          TButtonPanel::setup(
            v20,
            v14->render_area,
            (TPanel *)&v14->vfptr,
            104,
            0,
            50,
            30,
            (TPanel *)3,
            sound,
            (TPanel *)1,
            0);
          TButtonPanel::set_text_info(v14->move_mode_button, aMove, font, font_wid, font_hgt, -1, -1);
          TButtonPanel::set_text(v14->move_mode_button, 1, aMove_1);
          v21 = (TButtonPanel *)operator new(0x2B8u);
          LOBYTE(v35) = 4;
          if( v21 )
            TButtonPanel::TButtonPanel(v21);
          else
            v22 = 0;
          LOBYTE(v35) = 0;
          v14->delete_mode_button = (TButtonPanel *)v22;
          if( v22 )
          {
            TButtonPanel::setup(
              v22,
              v14->render_area,
              (TPanel *)&v14->vfptr,
              156,
              0,
              50,
              30,
              (TPanel *)3,
              sound,
              (TPanel *)1,
              0);
            TButtonPanel::set_text_info(v14->delete_mode_button, aDel_0, font, font_wid, font_hgt, -1, -1);
            TButtonPanel::set_text(v14->delete_mode_button, 1, aDel);
            v23 = (TButtonPanel *)operator new(0x2B8u);
            LOBYTE(v35) = 5;
            if( v23 )
              TButtonPanel::TButtonPanel(v23);
            else
              v24 = 0;
            LOBYTE(v35) = 0;
            v14->terrain_mode_button = (TButtonPanel *)v24;
            if( v24 )
            {
              TButtonPanel::setup(
                v24,
                v14->render_area,
                (TPanel *)&v14->vfptr,
                208,
                0,
                50,
                30,
                (TPanel *)3,
                sound,
                (TPanel *)1,
                0);
              TButtonPanel::set_text_info(v14->terrain_mode_button, aTerr, font, font_wid, font_hgt, -1, -1);
              TButtonPanel::set_text(v14->terrain_mode_button, 1, aTerr_1);
              (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14->terrain_mode_button + 20))(0);
              v25 = (TButtonPanel *)operator new(0x2B8u);
              LOBYTE(v35) = 6;
              if( v25 )
                TButtonPanel::TButtonPanel(v25);
              else
                v26 = 0;
              LOBYTE(v35) = 0;
              v14->elevation_mode_button = (TButtonPanel *)v26;
              if( v26 )
              {
                TButtonPanel::setup(
                  v26,
                  v14->render_area,
                  (TPanel *)&v14->vfptr,
                  260,
                  0,
                  50,
                  30,
                  (TPanel *)3,
                  sound,
                  (TPanel *)1,
                  0);
                TButtonPanel::set_text_info(v14->elevation_mode_button, aElev, font, font_wid, font_hgt, -1, -1);
                TButtonPanel::set_text(v14->elevation_mode_button, 1, aElev_1);
                (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14->elevation_mode_button + 20))(0);
                v27 = v14->object_mode_button;
                v28 = v14->game_mode_button;
                mode_buttons[2] = v14->move_mode_button;
                v29 = v14->terrain_mode_button;
                mode_buttons[1] = v27;
                v30 = v14->delete_mode_button;
                mode_buttons[4] = v29;
                mode_buttons[3] = v30;
                v31 = v14->elevation_mode_button;
                mode_buttons[0] = v28;
                mode_buttons[5] = v31;
                TButtonPanel::set_radio_info(v28, mode_buttons, 6);
                TButtonPanel::set_radio_info(v14->object_mode_button, mode_buttons, 6);
                TButtonPanel::set_radio_info(v14->move_mode_button, mode_buttons, 6);
                TButtonPanel::set_radio_info(v14->delete_mode_button, mode_buttons, 6);
                TButtonPanel::set_radio_info(v14->terrain_mode_button, mode_buttons, 6);
                TButtonPanel::set_radio_info(v14->elevation_mode_button, mode_buttons, 6);
                v32 = (TButtonPanel *)operator new(0x2B8u);
                LOBYTE(v35) = 7;
                if( v32 )
                  TButtonPanel::TButtonPanel(v32);
                else
                  v33 = 0;
                LOBYTE(v35) = 0;
                v14->command_button = (TButtonPanel *)v33;
                if( v33 )
                {
                  TButtonPanel::setup(
                    v33,
                    v14->render_area,
                    (TPanel *)&v14->vfptr,
                    314,
                    0,
                    50,
                    30,
                    (TPanel *)3,
                    sound,
                    (TPanel *)1,
                    0);
                  TButtonPanel::set_text_info(v14->command_button, aCmd_0, font, font_wid, font_hgt, -1, -1);
                  TButtonPanel::set_text(v14->command_button, 1, aCmd);
                  TButtonPanel::set_state_info(v14->command_button, 2);
                  RGE_Panel_Tool_Box::game_mode_changed(v14, rge_base_game->game_mode, rge_base_game->game_mode);
                }
                else
                {
                  v14->error_code = 1;
                }
              }
              else
              {
                v14->error_code = 1;
              }
            }
            else
            {
              v14->error_code = 1;
            }
          }
          else
          {
            v14->error_code = 1;
          }
        }
        else
        {
          v14->error_code = 1;
        }
      }
      else
      {
        v14->error_code = 1;
      }
    }
    else
    {
      v14->error_code = 1;
    }
  }
  else
  {
    v14->error_code = 1;
  }
}
// 571F60: using guessed type int (__thiscall *RGE_Panel_Tool_Box::`vftable')(void *Memory, unsigned int __flags);

//----- (00489E70) --------------------------------------------------------
RGE_Panel_Tool_Box *__thiscall RGE_Panel_Tool_Box::`vector deleting destructor'(RGE_Panel_Tool_Box *this, unsigned int __flags)
{
  RGE_Panel_Tool_Box *v2; // esi@1

  v2 = this;
  RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00489E90) --------------------------------------------------------
void __thiscall RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box(RGE_Panel_Tool_Box *this)
{
  RGE_Panel_Tool_Box *v1; // esi@1
  TButtonPanel *v2; // ecx@1
  TButtonPanel *v3; // ecx@3
  TButtonPanel *v4; // ecx@5
  TButtonPanel *v5; // ecx@7
  TButtonPanel *v6; // ecx@9
  TButtonPanel *v7; // ecx@11
  TButtonPanel *v8; // ecx@13

  v1 = this;
  this->vfptr = (TPanelVtbl *)&RGE_Panel_Tool_Box::`vftable';
  v2 = this->game_mode_button;
  if( v2 )
    (**(void (__stdcall ***)(_DWORD))v2)(1);
  v3 = v1->object_mode_button;
  if( v3 )
    (**(void (__stdcall ***)(_DWORD))v3)(1);
  v4 = v1->move_mode_button;
  if( v4 )
    (**(void (__stdcall ***)(_DWORD))v4)(1);
  v5 = v1->delete_mode_button;
  if( v5 )
    (**(void (__stdcall ***)(_DWORD))v5)(1);
  v6 = v1->terrain_mode_button;
  if( v6 )
    (**(void (__stdcall ***)(_DWORD))v6)(1);
  v7 = v1->elevation_mode_button;
  if( v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  v8 = v1->command_button;
  if( v8 )
    (**(void (__stdcall ***)(_DWORD))v8)(1);
  TPanel::~TPanel((TPanel *)&v1->vfptr);
}
// 571F60: using guessed type int (__thiscall *RGE_Panel_Tool_Box::`vftable')(void *Memory, unsigned int __flags);

//----- (00489F50) --------------------------------------------------------
int __thiscall RGE_Panel_Tool_Box::action(RGE_Panel_Tool_Box *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  RGE_Panel_Tool_Box *v5; // ebp@1
  int result; // eax@4
  RGE_Dialog_List *v7; // eax@7
  TPanel *v8; // eax@8
  char *v9; // ST10_4@11
  int v10; // ST08_4@11
  char *v11; // eax@11
  TPanel *v12; // ecx@12
  RGE_Base_GameVtbl *v13; // edx@26
  TPanel *v14; // ecx@29
  TPanel **v15; // edi@29
  int v16; // eax@31
  __int16 v17; // ax@32
  RGE_Player *v18; // eax@32
  __int16 v19; // ax@35

  v5 = this;
  if( !from_panel )
    return 0;
  if( from_panel == (TPanel *)this->game_mode_button && action_in == 1 )
  {
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    return 1;
  }
  if( from_panel != (TPanel *)this->object_mode_button || action_in != 1 )
  {
    if( from_panel == (TPanel *)this->move_mode_button && action_in == 1 )
    {
      (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(18, 0);
      return 1;
    }
    if( from_panel == (TPanel *)this->delete_mode_button && action_in == 1 )
    {
      (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(14, 0);
      return 1;
    }
    if( from_panel == (TPanel *)this->elevation_mode_button && action_in == 1 )
    {
      (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(3, 0);
      return 1;
    }
    if( from_panel == (TPanel *)this->command_button && action_in == 1 )
    {
      v13 = rge_base_game->vfptr;
      if( rge_base_game->prog_mode == 4 )
      {
        (*(void (__stdcall **)(signed int))&v13->gap8[4])(6);
        result = 1;
        rge_base_game->world->temp_pause = 1;
      }
      else
      {
        (*(void (__stdcall **)(signed int))&v13->gap8[4])(4);
        result = 1;
      }
      return result;
    }
    v14 = this->dialog;
    v15 = &v5->dialog;
    if( from_panel == v14 )
    {
      if( !strcmp(TPanel::panelName(v14), aObjectListDial) )
      {
        v16 = action_in;
        if( action_in == 1 )
        {
          v17 = ((int (*)(void))(*v15)->vfptr[1].handle_size)();
          rge_base_game->master_obj_id = v17;
          RGE_Base_Game::delete_dialog(&v5->dialog);
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(1, 0);
          v18 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
          RGE_Player::unselect_object(v18);
          return 1;
        }
      }
      else
      {
        if( strcmp(TPanel::panelName(*v15), aTerrainListDia) )
          return 1;
        v16 = action_in;
        if( action_in == 1 )
        {
          v19 = ((int (*)(void))(*v15)->vfptr[1].handle_size)();
          rge_base_game->terrain_id = v19;
          RGE_Base_Game::delete_dialog(&v5->dialog);
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(2, 0);
          return 1;
        }
      }
      if( v16 == 2 )
      {
        RGE_Base_Game::delete_dialog(&v5->dialog);
        RGE_Panel_Tool_Box::game_mode_changed(v5, rge_base_game->game_mode, rge_base_game->game_mode);
      }
      return 1;
    }
    return 0;
  }
  v7 = (RGE_Dialog_List *)operator new(0x4BCu);
  if( v7 )
    RGE_Dialog_List::RGE_Dialog_List(v7, aObjectListDial);
  else
    v8 = 0;
  v5->dialog = v8;
  if( !v8 )
    return 1;
  v9 = TPanel::get_string(9002);
  v10 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&v5->screen_panel->vfptr);
  v11 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&v5->screen_panel->vfptr);
  if( RGE_Dialog_List::setup((RGE_Dialog_List *)v5->dialog, v5->screen_panel, v11, v10, 1, v9) )
    return 1;
  v12 = v5->dialog;
  if( v12 )
    ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
  v5->dialog = 0;
  return 1;
}

//----- (0048A320) --------------------------------------------------------
int __thiscall RGE_Panel_Tool_Box::key_down_action(RGE_Panel_Tool_Box *this, int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  RGE_Panel_Tool_Box *v6; // esi@1
  int v7; // eax@2
  int v8; // edi@9
  RGE_Active_Sprite_List *v9; // ecx@10
  char v10; // bl@11
  RGE_Sprite *v11; // ecx@12
  RGE_Game_World *v13; // eax@18
  RGE_Map *v14; // ecx@18
  RGE_Diamond_Map *v15; // ecx@21
  int v16; // [sp-14h] [bp-30h]@18
  int v17; // [sp-10h] [bp-2Ch]@18
  int v18; // [sp-Ch] [bp-28h]@18
  int v19; // [sp-8h] [bp-24h]@18
  int y2; // [sp+Ch] [bp-10h]@18
  int x2; // [sp+10h] [bp-Ch]@18
  int y1; // [sp+14h] [bp-8h]@18
  int x1; // [sp+18h] [bp-4h]@18

  v6 = this;
  if( RGE_Base_Game::get_paused(rge_base_game) )
    return 0;
  v7 = rge_base_game->prog_mode;
  if( v7 != 4 && v7 != 6 && v7 != 7 )
    return 0;
  if( key == 33 )
  {
    if( rge_base_game->game_mode != 3 )
      return 0;
    RGE_View::get_selection_area(v6->view, &x1, &y1, &x2, &y2, 1);
    RGE_Map::set_elev(rge_base_game->world->map, x1, y1, x2, y2, 0, 1, 1);
    v19 = y2;
    v18 = x2;
    v13 = (RGE_Game_World *)rge_base_game;
    v17 = y1;
    v16 = x1;
    v14 = rge_base_game->world->map;
    goto LABEL_21;
  }
  if( key == 34 )
  {
    if( rge_base_game->game_mode != 3 )
      return 0;
    RGE_View::get_selection_area(v6->view, &x1, &y1, &x2, &y2, 1);
    RGE_Map::set_elev(rge_base_game->world->map, x1, y1, x2, y2, 0, -1, 1);
    v19 = y2;
    v18 = x2;
    v17 = y1;
    v16 = x1;
    v13 = rge_base_game->world;
    v14 = v13->map;
LABEL_21:
    RGE_Map::clean_elevation(v14, (int)v13, v16, v17, v18, v19, 8);
    ((void (__stdcall *)(signed int))v6->view->vfptr->set_redraw)(2);
    v15 = v6->map;
    if( v15 )
      ((void (__stdcall *)(signed int))v15->vfptr->set_redraw)(2);
    return 1;
  }
  if( key == 46 && rge_base_game->game_mode == 18 )
  {
    v8 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num;
    if( v8 )
    {
      v9 = *(RGE_Active_Sprite_List **)(v8 + 24);
      if( v9 )
      {
        v10 = RGE_Active_Sprite_List::get_lowest_draw_level(v9);
      }
      else
      {
        v11 = *(RGE_Sprite **)(v8 + 16);
        v10 = v11 ? RGE_Sprite::get_lowest_draw_level(v11) : 20;
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 104))(v8);
      if( !v10 )
      {
        ((void (__stdcall *)(signed int))v6->view->vfptr->set_redraw)(2);
        return 1;
      }
    }
    return 1;
  }
  return 0;
}

//----- (0048A520) --------------------------------------------------------
void __thiscall RGE_Panel_Tool_Box::game_mode_changed(RGE_Panel_Tool_Box *this, int old_mode, int new_mode)
{
  RGE_Panel_Tool_Box *v3; // esi@1
  RGE_Player *v4; // eax@2
  TButtonPanel *v5; // ecx@8
  RGE_Player *v6; // eax@10

  v3 = this;
  switch ( old_mode )
  {
    case 1:
    case 18:
      v4 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::unselect_object(v4);
      break;
    case 2:
    case 3:
      RGE_View::set_selection_area(this->view, -1, -1, -1, -1);
      break;
    default:
      break;
  }
  switch ( new_mode )
  {
    case 1:
      TButtonPanel::set_radio_button(v3->object_mode_button);
      break;
    case 18:
      TButtonPanel::set_radio_button(v3->move_mode_button);
      break;
    case 14:
      TButtonPanel::set_radio_button(v3->delete_mode_button);
      break;
    case 2:
      v5 = v3->terrain_mode_button;
      goto LABEL_10;
    case 3:
      v5 = v3->elevation_mode_button;
LABEL_10:
      TButtonPanel::set_radio_button(v5);
      v6 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
      RGE_Player::unselect_object(v6);
      break;
    default:
      TButtonPanel::set_radio_button(v3->game_mode_button);
      break;
  }
}

//----- (0048A640) --------------------------------------------------------
void __thiscall RGE_Panel_Tool_Box::draw(RGE_Panel_Tool_Box *this)
{
  RGE_Panel_Tool_Box *v1; // esi@1
  TPanelVtbl *v2; // edi@4

  v1 = this;
  if( this->render_area && this->visible )
  {
    if( this->active )
    {
      v2 = this->vfptr;
      ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
      TDrawArea::Clear(v1->render_area, &v1->clip_rect, 0);
      v2->draw_finish((TPanel *)v1);
    }
  }
}
