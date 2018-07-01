
//----- (0053DAB0) --------------------------------------------------------
void __thiscall RGE_Main_View::RGE_Main_View(RGE_Main_View *this)
{
  RGE_Main_View *v1; // esi@1

  v1 = this;
  RGE_View::RGE_View((RGE_View *)&this->vfptr);
  v1->map_view = 0;
  v1->last_mouse_scroll_time = 0;
  v1->mouse_scrolling = 0;
  v1->last_key_scroll_time = 0;
  v1->key_scrolling = 0;
  v1->save_player = 0;
  v1->vfptr = (TPanelVtbl *)&RGE_Main_View::`vftable';
  v1->mouse_move_tolerance = 10;
  v1->mouse_last_x = -1;
  v1->mouse_last_y = -1;
}
// 5777F0: using guessed type int (__thiscall *RGE_Main_View::`vftable')(void *Memory, unsigned int __flags);

//----- (0053DB10) --------------------------------------------------------
RGE_Main_View *__thiscall RGE_Main_View::`scalar deleting destructor'(RGE_Main_View *this, unsigned int __flags)
{
  RGE_Main_View *v2; // esi@1

  v2 = this;
  RGE_Main_View::~RGE_Main_View(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0053DB40) --------------------------------------------------------
int __thiscall RGE_Main_View::handle_idle(RGE_Main_View *this)
{
  RGE_Main_View *v1; // esi@1
  int v2; // esi@1

  v1 = this;
  color_log(69, 69, 5);
  RGE_Main_View::do_auto_scroll(v1);
  color_log(69, 22, 5);
  RGE_Main_View::handle_keys(v1);
  color_log(69, 36, 5);
  v2 = TPanel::handle_idle((TPanel *)&v1->vfptr);
  color_log(69, 95, 5);
  return v2;
}

//----- (0053DBA0) --------------------------------------------------------
int __thiscall RGE_Main_View::do_auto_scroll(RGE_Main_View *this)
{
  RGE_Main_View *v1; // esi@1
  int v2; // eax@1
  signed __int16 v3; // bp@6
  RGE_Prog_Info *v4; // ebx@12
  int v5; // eax@14
  unsigned int v6; // edi@24
  int v7; // eax@24
  double v8; // st7@25
  double v9; // st7@26
  double v10; // st6@26
  double v11; // st7@26
  double v12; // st6@27
  RGE_Player *v13; // ecx@34
  double v14; // st6@34
  double v15; // st5@34
  float y; // ST04_4@37
  float x; // ST00_4@37
  RGE_Player *v18; // ecx@39
  double v19; // st7@39
  double v20; // st6@39
  float v21; // ST04_4@42
  float v22; // ST00_4@42
  TPanel *v23; // ecx@43
  signed __int16 vert_scroll; // [sp+18h] [bp-2Ch]@12
  float scroll_dist2; // [sp+1Ch] [bp-28h]@33
  tagPOINT point; // [sp+24h] [bp-20h]@12
  unsigned int v28; // [sp+2Ch] [bp-18h]@26
  int v29; // [sp+30h] [bp-14h]@26
  tagRECT rect; // [sp+34h] [bp-10h]@12

  v1 = this;
  v2 = rge_base_game->prog_mode;
  if ( v2 != 4 && v2 != 6 && v2 != 7 && v2 != 5
    || RGE_Base_Game::get_paused(rge_base_game)
    || (v3 = 0, !rge_base_game->prog_info->auto_scroll)
    || GetForegroundWindow() != v1->render_area->Wnd
    || TPanelSystem::modalPanel(&panel_system)
    || TPanelSystem::mouseOwner(&panel_system) && (RGE_Main_View *)TPanelSystem::mouseOwner(&panel_system) != v1
    || v1->key_scrolling )
  {
    v1->mouse_scrolling = 0;
    return 0;
  }
  GetWindowRect(v1->render_area->Wnd, &rect);
  GetCursorPos(&point);
  vert_scroll = 0;
  v4 = rge_base_game->prog_info;
  if ( GetAsyncKeyState(1) >= 0 && GetAsyncKeyState(2) >= 0 )
  {
    v5 = v4->mouse_scroll_edge;
    if ( point.x >= v5 + rect.left )
    {
      if ( point.x > rect.right - v5 )
        v3 = 1;
    }
    else
    {
      v3 = -1;
    }
    if ( point.y >= rect.top + v5 )
    {
      if ( point.y > rect.bottom - v5 )
        vert_scroll = 1;
    }
    else
    {
      vert_scroll = -1;
    }
    if ( v3 || vert_scroll )
    {
      v6 = debug_timeGetTime();
      v7 = v6 - v1->last_mouse_scroll_time;
      if ( v1->mouse_scrolling )
      {
        v28 = v4->key_scroll_interval;
        v29 = 0;
        v9 = (double)(unsigned int)v7 / (double)(signed int)v28;
        v10 = v9;
        v11 = (double)(signed int)(signed __int64)v9;
        if ( v10 - v11 >= 0.5 )
          v12 = 0.5;
        else
          v12 = 0.0;
        v8 = v11 + v12;
      }
      else
      {
        v8 = 1.0;
        v1->mouse_scrolling = 1;
      }
      if ( v8 > v4->mouse_scroll_max_dist )
        v8 = v4->mouse_scroll_max_dist;
      if ( v8 > 0.0 )
      {
        scroll_dist2 = v8 + v8;
        if ( v3 == -1 )
        {
          v13 = v1->player;
          v14 = v13->view_y - v8;
          v15 = v13->view_x - v8;
        }
        else
        {
          if ( v3 != 1 )
            goto LABEL_38;
          v13 = v1->player;
          v14 = v13->view_y + v8;
          v15 = v13->view_x + v8;
        }
        y = v14;
        x = v15;
        RGE_Player::set_view_loc(v13, x, y);
LABEL_38:
        if ( vert_scroll == -1 )
        {
          v18 = v1->player;
          v19 = v18->view_y - scroll_dist2;
          v20 = v18->view_x + scroll_dist2;
        }
        else
        {
          if ( vert_scroll != 1 )
          {
LABEL_43:
            v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
            v23 = v1->map_view;
            if ( v23 )
              ((void (__stdcall *)(signed int))v23->vfptr->set_redraw)(1);
            v1->last_mouse_scroll_time = v6;
            goto LABEL_46;
          }
          v18 = v1->player;
          v19 = v18->view_y + scroll_dist2;
          v20 = v18->view_x - scroll_dist2;
        }
        v21 = v19;
        v22 = v20;
        RGE_Player::set_view_loc(v18, v22, v21);
        goto LABEL_43;
      }
    }
  }
LABEL_46:
  if ( !v3 && !vert_scroll )
    v1->mouse_scrolling = 0;
  return v1->mouse_scrolling;
}

//----- (0053DEB0) --------------------------------------------------------
int __thiscall RGE_Main_View::handle_keys(RGE_Main_View *this)
{
  RGE_Main_View *v1; // ebp@1
  int v2; // eax@2
  signed int v3; // ebx@7
  RGE_Prog_Info *v4; // edi@8
  RGE_Player *v5; // eax@9
  RGE_Static_Object *v6; // esi@10
  float x; // ST28_4@12
  float v8; // ST24_4@12
  float v9; // ST28_4@14
  float v10; // ST24_4@14
  float v11; // ST28_4@16
  float v12; // ST24_4@16
  float v13; // ST28_4@18
  float v14; // ST24_4@18
  unsigned int v15; // esi@30
  double v16; // st7@31
  double v17; // st7@32
  double v18; // st6@32
  double v19; // st7@32
  double v20; // st6@33
  RGE_Player *v21; // ecx@40
  double v22; // st6@40
  double v23; // st5@40
  float y; // ST2C_4@43
  float v25; // ST28_4@43
  RGE_Player *v26; // ecx@45
  double v27; // st7@45
  double v28; // st6@45
  float v29; // ST2C_4@48
  float v30; // ST28_4@48
  TPanel *v31; // ebp@54
  signed __int16 horz_scroll; // [sp+40h] [bp-118h]@8
  signed __int16 vert_scroll; // [sp+44h] [bp-114h]@8
  float scroll_dist2; // [sp+48h] [bp-110h]@39
  char pbKeyState[256]; // [sp+58h] [bp-100h]@8

  v1 = this;
  if ( RGE_Base_Game::get_paused(rge_base_game)
    || (v2 = rge_base_game->prog_mode, v2 != 4) && v2 != 6 && v2 != 7 && v2 != 5
    || GetForegroundWindow() != v1->render_area->Wnd
    || (v3 = 0, !v1->have_focus) )
  {
    v1->key_scrolling = 0;
    return 0;
  }
  GetKeyboardState(pbKeyState);
  horz_scroll = 0;
  vert_scroll = 0;
  v4 = rge_base_game->prog_info;
  if ( rge_base_game->game_mode == 18 )
  {
    v5 = v1->player;
    if ( v5 )
    {
      v6 = v5->selected_obj;
      if ( v6 )
      {
        if ( pbKeyState[38] > 1u )
        {
          x = v6->world_y - v4->key_scroll_object_move;
          v8 = v6->world_x + v4->key_scroll_object_move;
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[48])(LODWORD(v8), LODWORD(x), 0);
          v3 = 1;
        }
        if ( pbKeyState[40] > 1u )
        {
          v9 = v6->world_y + v4->key_scroll_object_move;
          v10 = v6->world_x - v4->key_scroll_object_move;
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))&v1->player->selected_obj->vfptr->gap4[48])(
            LODWORD(v10),
            LODWORD(v9),
            0);
          v3 = 1;
        }
        if ( pbKeyState[37] > 1u )
        {
          v11 = v6->world_y - v4->key_scroll_object_move;
          v12 = v6->world_x - v4->key_scroll_object_move;
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))&v1->player->selected_obj->vfptr->gap4[48])(
            LODWORD(v12),
            LODWORD(v11),
            0);
          v3 = 1;
        }
        if ( pbKeyState[39] > 1u )
        {
          v13 = v6->world_y + v4->key_scroll_object_move;
          v14 = v6->world_x + v4->key_scroll_object_move;
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))&v1->player->selected_obj->vfptr->gap4[48])(
            LODWORD(v14),
            LODWORD(v13),
            0);
          v3 = 1;
        }
        goto LABEL_50;
      }
    }
  }
  if ( !v1->player )
    goto LABEL_50;
  if ( pbKeyState[37] <= 1u )
  {
    if ( pbKeyState[39] > 1u )
      horz_scroll = 1;
  }
  else
  {
    horz_scroll = -1;
  }
  if ( pbKeyState[38] <= 1u )
  {
    if ( pbKeyState[40] > 1u )
      vert_scroll = 1;
  }
  else
  {
    vert_scroll = -1;
  }
  if ( !horz_scroll && !vert_scroll )
    goto LABEL_50;
  v15 = debug_timeGetTime();
  if ( v1->key_scrolling )
  {
    v17 = (double)(v15 - v1->last_key_scroll_time) / (double)(signed int)v4->key_scroll_interval;
    v18 = v17;
    v19 = (double)(signed int)(signed __int64)v17;
    if ( v18 - v19 >= 0.5 )
      v20 = 0.5;
    else
      v20 = 0.0;
    v16 = v19 + v20;
  }
  else
  {
    v16 = 1.0;
    v1->key_scrolling = 1;
  }
  if ( v16 > v4->key_scroll_max_dist )
    v16 = v4->key_scroll_max_dist;
  if ( v16 <= 0.0 )
    goto LABEL_50;
  scroll_dist2 = v16 + v16;
  if ( horz_scroll == -1 )
  {
    v21 = v1->player;
    v22 = v21->view_y - v16;
    v23 = v21->view_x - v16;
  }
  else
  {
    if ( horz_scroll != 1 )
      goto LABEL_44;
    v21 = v1->player;
    v22 = v21->view_y + v16;
    v23 = v21->view_x + v16;
  }
  y = v22;
  v25 = v23;
  RGE_Player::set_view_loc(v21, v25, y);
LABEL_44:
  if ( vert_scroll == -1 )
  {
    v26 = v1->player;
    v27 = v26->view_y - scroll_dist2;
    v28 = v26->view_x + scroll_dist2;
LABEL_48:
    v29 = v27;
    v30 = v28;
    RGE_Player::set_view_loc(v26, v30, v29);
    goto LABEL_49;
  }
  if ( vert_scroll == 1 )
  {
    v26 = v1->player;
    v27 = v26->view_y + scroll_dist2;
    v28 = v26->view_x - scroll_dist2;
    goto LABEL_48;
  }
LABEL_49:
  v1->last_key_scroll_time = v15;
  v3 = 1;
LABEL_50:
  if ( !horz_scroll && !vert_scroll )
    v1->key_scrolling = 0;
  if ( v3 )
  {
    v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
    v31 = v1->map_view;
    if ( v31 )
      v31->vfptr->set_redraw(v31, RedrawNormal);
  }
  return v3;
}

//----- (0053E280) --------------------------------------------------------
int __thiscall RGE_Main_View::handle_mouse_up(RGE_Main_View *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Main_View *v6; // esi@1
  unsigned int v7; // edi@1
  int v8; // esi@1
  unsigned int v9; // eax@1

  v6 = this;
  v7 = debug_timeGetTime();
  v8 = TPanel::handle_mouse_up((TPanel *)&v6->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
  v9 = debug_timeGetTime();
  RGE_Base_Game::add_to_timing(rge_base_game, 13, v9 - v7);
  return v8;
}

//----- (0053E2F0) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_move_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  int v5; // eax@1
  int result; // eax@5
  int v7; // eax@6

  v5 = rge_base_game->prog_mode;
  if ( v5 == 4 || v5 == 6 || v5 == 7 || v5 == 5 )
  {
    v7 = rge_base_game->game_mode;
    if ( v7 == 1 || v7 > 6 && v7 <= 8 )
      ((void (__stdcall *)(signed int))this->vfptr->set_redraw)(1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053E340) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_left_down_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Main_View *v5; // esi@1
  int v6; // eax@2
  int v7; // edi@6
  TPanelVtbl *v8; // edi@8
  int v9; // ecx@9
  int v10; // eax@9
  TDrawArea *v11; // edx@9
  TDrawArea *v12; // edx@11
  int v13; // edi@15
  RGE_Master_Static_Object *v14; // ecx@16
  RGE_Game_World *v15; // eax@19
  RGE_Master_Static_Object *v16; // ecx@19
  RGE_Player *v17; // ecx@21
  RGE_Player *v18; // ecx@26
  RGE_Active_Sprite_List *v19; // ecx@31
  char v20; // bl@32
  RGE_Sprite *v21; // ecx@33
  RGE_Game_World *v22; // eax@36
  RGE_Static_Object *v23; // edx@36
  RGE_Player *v24; // edx@36
  RGE_Static_Object *v25; // eax@36
  RGE_Static_Object *v26; // ecx@38
  TDrawArea *v27; // eax@39
  int result; // eax@43
  int min_x; // [sp+10h] [bp-24h]@9
  int max_y; // [sp+14h] [bp-20h]@9
  tagPOINT point; // [sp+18h] [bp-1Ch]@9
  RGE_Pick_Info pick_info; // [sp+20h] [bp-14h]@7

  v5 = this;
  if ( RGE_Base_Game::get_paused(rge_base_game)
    || (v6 = rge_base_game->prog_mode, v6 != 4) && v6 != 6 && v6 != 7 && v6 != 5 )
  {
    result = 0;
  }
  else
  {
    v7 = rge_base_game->game_mode;
    color_log(76, -70, 1);
    switch ( v7 )
    {
      case 18:
        if ( RGE_Main_View::pick1(v5, 41, 0, x, y, &pick_info, v5->player->selected_obj, 1) == 52 )
        {
          RGE_Player::unselect_object(v5->player);
          RGE_Player::select_one_object(v5->player, pick_info.object, 1);
          v8 = v5->vfptr;
          v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
          if ( pick_info.object->sprite )
          {
            RGE_Static_Object::get_frame(
              pick_info.object,
              (__int16 *)&min_x,
              (__int16 *)&min_x + 1,
              (__int16 *)&max_y + 1,
              (__int16 *)&max_y);
            v9 = pick_info.scr_x - (signed __int16)min_x;
            v10 = pick_info.scr_y - SHIWORD(min_x);
            v11 = v5->render_area;
            point.x = pick_info.scr_x - (signed __int16)min_x;
            point.y = pick_info.scr_y - SHIWORD(min_x);
            if ( v11->DrawSystem->ScreenMode == 1 )
            {
              ClientToScreen(v11->Wnd, &point);
              v10 = point.y;
              v9 = point.x;
            }
            v12 = v5->render_area;
            if ( v12->DrawSystem->ScreenMode == 1 )
            {
              ScreenToClient(v12->Wnd, &point);
              v10 = point.y;
              v9 = point.x;
            }
            (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v8[1].gap4[4])(
              v5,
              4,
              v9,
              v10,
              ctrl_key,
              shift_key);
          }
        }
        break;
      case 1:
        if ( RGE_Main_View::pick1(v5, 40, 0, x, y, &pick_info, 0, 1) == 51 )
        {
          RGE_Main_View::fixup_pick_info(v5, &pick_info);
          v13 = rge_base_game->master_obj_id;
          if ( v13 != -1 )
          {
            v14 = v5->player->master_objects[v13];
            if ( v14 )
            {
              ((void (__stdcall *)(RGE_Pick_Info *, float *, RGE_Game_World *, _DWORD))v14->vfptr->alignment)(
                &pick_info,
                &pick_info.y,
                v5->world,
                0);
              ((void (__stdcall *)(int, _DWORD, _DWORD, _DWORD))v5->player->vfptr->command_place_object)(
                v13,
                LODWORD(pick_info.x),
                LODWORD(pick_info.y),
                0);
            }
            else if ( v13 != -1 )
            {
              v15 = v5->world;
              v16 = (*v15->players)->master_objects[v13];
              if ( v16 )
              {
                ((void (__stdcall *)(RGE_Pick_Info *, float *, RGE_Game_World *, _DWORD))v16->vfptr->alignment)(
                  &pick_info,
                  &pick_info.y,
                  v15,
                  0);
                (*(void (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v5->world->players + 176))(
                  v13,
                  LODWORD(pick_info.x),
                  LODWORD(pick_info.y),
                  0);
              }
            }
          }
        }
        break;
      case 9:
      case 10:
      case 19:
        v17 = v5->player;
        if ( v17->selected_obj )
        {
          RGE_Player::unselect_object(v17);
          v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
        }
        if ( v7 == 19 )
          (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(19, 0);
        (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v5->vfptr[1].gap4[4])(
          v5,
          9,
          x,
          y,
          ctrl_key,
          shift_key);
        break;
      case 2:
      case 3:
      case 17:
        v18 = v5->player;
        if ( v18->selected_obj )
        {
          RGE_Player::unselect_object(v18);
          v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
        }
        goto LABEL_28;
      case 21:
LABEL_28:
        (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v5->vfptr[1].gap4[4])(
          v5,
          3,
          x,
          y,
          ctrl_key,
          shift_key);
        break;
      case 15:
        if ( RGE_Main_View::pick1(v5, 41, 0, x, y, &pick_info, v5->player->selected_obj, 1) == 52
          && pick_info.object->master_obj->object_group != 34 )
        {
          v19 = pick_info.object->sprite_list;
          if ( v19 )
          {
            v20 = RGE_Active_Sprite_List::get_lowest_draw_level(v19);
          }
          else
          {
            v21 = pick_info.object->sprite;
            if ( v21 )
              v20 = RGE_Sprite::get_lowest_draw_level(v21);
            else
              v20 = 20;
          }
          v22 = RGE_Base_Game::get_player(rge_base_game);
          v23 = pick_info.object;
          v5->save_player = (RGE_Player *)v22;
          v24 = v23->owner;
          LOWORD(v24) = v24->id;
          (*(void (__stdcall **)(RGE_Player *))&rge_base_game->vfptr->gap8[12])(v24);
          rge_base_game->master_obj_id = pick_info.object->master_obj->id;
          v25 = pick_info.object;
          v5->movable_object = pick_info.object;
          v25->object_state = 7;
          if ( !v20 )
            v5->vfptr->set_redraw((TPanel *)v5, RedrawFull);
          (*(void (__stdcall **)(signed int, signed int))&rge_base_game->vfptr->gap8[8])(8, 1);
          v26 = v5->movable_object;
          if ( v26->sprite )
          {
            RGE_Static_Object::get_frame(
              v26,
              (__int16 *)&min_x,
              (__int16 *)&min_x + 1,
              (__int16 *)&max_y + 1,
              (__int16 *)&max_y);
            point.x = pick_info.scr_x - (signed __int16)min_x;
            point.y = pick_info.scr_y - SHIWORD(min_x);
            v27 = v5->render_area;
            if ( v27->DrawSystem->ScreenMode == 1 )
              ClientToScreen(v27->Wnd, &point);
          }
          (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v5->vfptr[1].gap4[4])(
            v5,
            9,
            x,
            y,
            ctrl_key,
            shift_key);
        }
        break;
      default:
        TPanel::capture_mouse((TPanel *)&v5->vfptr);
        break;
    }
    color_log(76, 95, 1);
    result = 1;
  }
  return result;
}

//----- (0053E7F0) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_left_move_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Main_View *v5; // esi@1
  int v6; // eax@1
  int result; // eax@5
  bool v8; // zf@6
  char v9; // al@6
  TPanelVtbl *v10; // edi@13

  v5 = this;
  v6 = rge_base_game->prog_mode;
  if ( v6 == 4 || v6 == 6 || v6 == 7 || v6 == 5 )
  {
    v8 = RGE_Base_Game::get_paused(rge_base_game) == 0;
    v9 = v5->scroll_action;
    if ( v8 )
    {
      if ( v9 )
      {
        ((void (__thiscall *)(RGE_Main_View *, int, int))v5->vfptr[1].set_rect)(v5, x, y);
        result = 1;
      }
      else
      {
        switch ( rge_base_game->game_mode )
        {
          case 0:
            TPanel::release_mouse((TPanel *)&v5->vfptr);
            v10 = v5->vfptr;
            (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v5->vfptr[1].gap4[4])(
              v5,
              2,
              v5->mouse_down_x,
              v5->mouse_down_y,
              ctrl_key,
              shift_key);
            ((void (__thiscall *)(RGE_Main_View *, int, int))v10[1].set_rect)(v5, x, y);
            result = 1;
            break;
          case 1:
          case 7:
          case 8:
            v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
            goto LABEL_15;
          default:
LABEL_15:
            result = 1;
            break;
        }
      }
    }
    else if ( v9 )
    {
      (*(void (__thiscall **)(RGE_Main_View *))&v5->vfptr[1].gap10[0])(v5);
      result = 0;
    }
    else
    {
      TPanel::release_mouse((TPanel *)&v5->vfptr);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053E910) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_left_up_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  int v5; // eax@1
  RGE_Main_View *v6; // esi@1
  TPanelVtbl *v8; // edi@7
  int v9; // eax@10
  RGE_Player *v10; // eax@15
  RGE_Base_Game *v11; // ecx@19
  int v12; // ebx@19
  RGE_Static_Object *v13; // edx@24
  RGE_Player *v14; // ecx@26
  RGE_Static_Object *v15; // eax@26
  char v16; // al@28
  RGE_Player *v17; // eax@44
  RGE_Static_Object *v18; // eax@47
  RGE_Active_Sprite_List *v19; // ecx@47
  char v20; // bl@48
  RGE_Sprite *v21; // ecx@49
  TPanel *v22; // ecx@59
  int v23; // eax@66
  char v24; // al@71
  RGE_Player *v25; // ecx@72
  RGE_Player *v26; // ecx@85
  RGE_Static_Object *v27; // ebx@85
  int v28; // eax@89
  RGE_Player *v29; // ecx@95
  RGE_Player *v30; // eax@97
  int v31; // eax@99
  int v32; // eax@112
  RGE_Pick_Info *v33; // [sp+8h] [bp-30h]@69
  RGE_Pick_Info *v34; // [sp+8h] [bp-30h]@80
  RGE_Static_Object *v35; // [sp+Ch] [bp-2Ch]@69
  RGE_Static_Object *v36; // [sp+Ch] [bp-2Ch]@80
  RGE_Pick_Info pick_info; // [sp+24h] [bp-14h]@23

  v5 = rge_base_game->prog_mode;
  v6 = this;
  if ( v5 != 4 && v5 != 6 && v5 != 7 && v5 != 5 )
    return 0;
  color_log(76, 22, 1);
  if ( v6->scroll_action )
  {
    v8 = v6->vfptr;
    (*(void (__thiscall **)(RGE_Main_View *))&v6->vfptr[1].gap10[0])(v6);
    if ( rge_base_game->game_mode == 21 )
    {
      v9 = !ctrl_key && !shift_key;
      ((void (__thiscall *)(RGE_Main_View *, int, int, int, int, int))v8[1].draw_finish)(
        v6,
        v6->sel_col1,
        v6->sel_row1,
        v6->sel_col2,
        v6->sel_row2,
        v9);
    }
    if ( rge_base_game->game_mode == 8 )
    {
      ((void (__thiscall *)(RGE_Main_View *, int, int, signed int))v8[1].set_fixed_position)(v6, x, y, 1);
      if ( rge_base_game->sub_game_mode == 1 )
      {
        v6->movable_object->object_state = 2;
        v6->movable_object = 0;
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(15, 0);
        v10 = v6->save_player;
        if ( v10 )
        {
          LOWORD(v10) = v10->id;
          (*(void (__stdcall **)(RGE_Player *))&rge_base_game->vfptr->gap8[12])(v10);
          v6->save_player = 0;
        }
      }
    }
    goto LABEL_120;
  }
  TPanel::release_mouse((TPanel *)&v6->vfptr);
  if ( RGE_Base_Game::get_paused(rge_base_game) )
  {
    color_log(76, 95, 1);
    return 0;
  }
  v11 = rge_base_game;
  v12 = rge_base_game->game_mode;
  if ( (shift_key || ctrl_key) && v12 != 7 && v12 != 21 )
  {
    if ( RGE_Main_View::pick1(v6, 41, 2, x, y, &pick_info, 0, 0) == 52 )
    {
      v13 = pick_info.object;
      if ( pick_info.object->selected & 1 )
      {
        RGE_Player::unselect_one_object(v6->player, pick_info.object);
      }
      else
      {
        v14 = v6->player;
        v15 = v14->selected_obj;
        if ( v15 )
        {
          if ( v15->owner != v14
            || (v16 = RGE_Player::get_select_level(v14, v15),
                v13 = pick_info.object,
                v16 != pick_info.object->master_obj->select_level) )
          {
            RGE_Player::unselect_object(v6->player);
            v13 = pick_info.object;
          }
        }
        if ( ctrl_key )
          RGE_Player::select_one_object(v6->player, v13, 1);
        else
          RGE_Player::select_object(v6->player, v13);
      }
      v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
    }
    if ( ctrl_key )
      goto LABEL_120;
    v11 = rge_base_game;
    if ( rge_base_game->prog_info->interface_style == 2 )
      goto LABEL_120;
  }
  switch ( v12 )
  {
    case 4:
      ((void (__thiscall *)(RGE_Main_View *, int, int))v6->vfptr[1].set_overlapped_redraw)(v6, x, y);
      goto LABEL_120;
    case 5:
      ((void (__thiscall *)(RGE_Main_View *, int, int))v6->vfptr[1].draw_setup)(v6, x, y);
      goto LABEL_120;
    case 7:
      if ( ctrl_key || shift_key )
        ((void (__thiscall *)(RGE_Main_View *, int, int, _DWORD))v6->vfptr[1].set_fixed_position)(v6, x, y, 0);
      else
        ((void (__thiscall *)(RGE_Main_View *, int, int, signed int))v6->vfptr[1].set_fixed_position)(v6, x, y, 1);
      goto LABEL_120;
    case 8:
      ((void (__thiscall *)(RGE_Main_View *, int, int, signed int))v6->vfptr[1].set_fixed_position)(v6, x, y, 1);
      if ( rge_base_game->sub_game_mode == 1 )
      {
        v6->movable_object->object_state = 2;
        v6->movable_object = 0;
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(15, 0);
        v17 = v6->save_player;
        if ( v17 )
        {
          LOWORD(v17) = v17->id;
          (*(void (__stdcall **)(RGE_Player *))&rge_base_game->vfptr->gap8[12])(v17);
          v6->save_player = 0;
        }
      }
      goto LABEL_120;
    case 14:
      if ( RGE_Main_View::pick1(v6, 41, 0, x, y, &pick_info, v6->player->selected_obj, 1) == 52 )
      {
        v18 = pick_info.object;
        v19 = pick_info.object->sprite_list;
        if ( v19 )
        {
          v20 = RGE_Active_Sprite_List::get_lowest_draw_level(v19);
          v18 = pick_info.object;
        }
        else
        {
          v21 = pick_info.object->sprite;
          if ( v21 )
          {
            v20 = RGE_Sprite::get_lowest_draw_level(v21);
            v18 = pick_info.object;
          }
          else
          {
            v20 = 20;
          }
        }
        if ( rge_base_game->prog_mode == 7 )
        {
          if ( v18 )
            v18->vfptr->__vecDelDtor(v18, 1u);
        }
        else
        {
          v18->vfptr->destroy_obj(v18);
        }
        if ( !v20 )
          v6->vfptr->set_redraw((TPanel *)v6, RedrawFull);
      }
      goto LABEL_120;
    case 16:
      if ( RGE_Main_View::pick1(v6, 41, 1, x, y, &pick_info, v6->player->selected_obj, 1) == 52 )
      {
        v22 = v6->parent_panel;
        if ( v22 )
        {
          ((void (__stdcall *)(RGE_Main_View *, signed int, RGE_Static_Object *, _DWORD))v22->vfptr->action)(
            v6,
            16,
            pick_info.object,
            0);
          RGE_Player::select_one_object(v6->player, pick_info.object, 1);
          v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        }
        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
      }
      goto LABEL_120;
    case 20:
      if ( RGE_Main_View::pick1(v6, 41, 2, x, y, &pick_info, v6->player->selected_obj, 1) == 52 )
        ((void (__stdcall *)(signed int))pick_info.object->vfptr->rotate)(1);
      goto LABEL_120;
    case 0:
    case 6:
      if ( v12 == 6 )
      {
        (*(void (__stdcall **)(_DWORD, _DWORD))&v11->vfptr->gap8[8])(0, 0);
        v11 = rge_base_game;
      }
      v23 = v6->mouse_last_x;
      if ( v11->prog_info->interface_style == 2 )
      {
        if ( x != v23 || y != v6->mouse_last_y )
        {
          v35 = 0;
          v33 = &pick_info;
        }
        else
        {
          v35 = v6->player->selected_obj;
          v33 = &pick_info;
        }
        v24 = RGE_Main_View::pick1(v6, 41, 2, x, y, v33, v35, 0);
        v6->mouse_last_x = -1;
        v6->mouse_last_y = -1;
        if ( v24 == 52 )
        {
          v25 = v6->player;
          if ( pick_info.object->selected & 1 )
          {
            if ( v25->sel_count <= 1 )
              goto LABEL_120;
            RGE_Player::unselect_object(v25);
            RGE_Player::select_one_object(v6->player, pick_info.object, 1);
          }
          else
          {
            RGE_Player::unselect_object(v25);
            RGE_Player::select_object(v6->player, pick_info.object);
          }
          v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
          v6->mouse_last_x = x;
          v6->mouse_last_y = y;
LABEL_120:
          color_log(76, 95, 1);
          return 1;
        }
        RGE_Player::unselect_object(v6->player);
LABEL_119:
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        goto LABEL_120;
      }
      if ( x != v23 || y != v6->mouse_last_y )
      {
        v36 = 0;
        v34 = &pick_info;
      }
      else
      {
        v36 = v6->player->selected_obj;
        v34 = &pick_info;
      }
      LOBYTE(ctrl_key) = RGE_Main_View::pick1(v6, 42, 1, x, y, v34, v36, 1);
      if ( (_BYTE)ctrl_key != 52 || x != v6->mouse_last_x || y != v6->mouse_last_y )
        goto LABEL_87;
      v26 = v6->player;
      v27 = pick_info.object;
      if ( pick_info.object != v26->selected_obj )
      {
        RGE_Player::unselect_object(v26);
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
LABEL_87:
        v27 = pick_info.object;
      }
      v6->mouse_last_x = -1;
      v6->mouse_last_y = -1;
      if ( (_BYTE)ctrl_key != 52 )
        goto LABEL_111;
      v28 = rge_base_game->prog_mode;
      if ( v28 != 5 && v6->player->sel_count > 0 && v28 != 7 )
      {
        if ( ((int (__thiscall *)(RGE_Main_View *, int, int, _DWORD, signed int))v6->vfptr[1].set_redraw)(
               v6,
               x,
               y,
               0,
               -1) )
        {
          return 1;
        }
        v27 = pick_info.object;
      }
      if ( !(v27->selected & 1) )
      {
        v30 = v6->player;
        if ( v27->owner == v30 || !v30->sel_count )
        {
          if ( v27->master_obj->select_level >= 2u
            && (v6->map->map_visible_flag
             || RGE_Visible_Map::get_visible(
                  v6->player->visible,
                  (signed __int64)v27->world_x,
                  (signed __int64)v27->world_y) == 15) )
          {
            RGE_Player::unselect_object(v6->player);
            RGE_Player::select_object(v6->player, pick_info.object);
            v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
            v6->mouse_last_x = x;
            v6->mouse_last_y = y;
          }
          goto LABEL_120;
        }
        v31 = rge_base_game->prog_mode;
        if ( v31 != 5 && v31 != 7 )
        {
          if ( ((int (__thiscall *)(RGE_Main_View *, int, int, signed int, signed int))v6->vfptr[1].set_redraw)(
                 v6,
                 x,
                 y,
                 1,
                 -1) )
          {
            goto LABEL_120;
          }
          v27 = pick_info.object;
        }
        if ( v27->master_obj->select_level >= 2u
          && (v6->map->map_visible_flag
           || RGE_Visible_Map::get_visible(
                v6->player->visible,
                (signed __int64)v27->world_x,
                (signed __int64)v27->world_y) == 15) )
        {
          RGE_Player::unselect_object(v6->player);
          RGE_Player::select_object(v6->player, pick_info.object);
          v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
          v6->mouse_last_x = x;
          v6->mouse_last_y = y;
          goto LABEL_120;
        }
LABEL_111:
        if ( (_BYTE)ctrl_key != 51 )
          goto LABEL_120;
        v32 = rge_base_game->prog_mode;
        if ( v32 == 5 || v32 == 7 )
          goto LABEL_120;
        if ( !shift_key )
        {
          ((void (__thiscall *)(RGE_Main_View *, int, int, signed int, signed int))v6->vfptr[1].set_redraw)(
            v6,
            x,
            y,
            1,
            -1);
          goto LABEL_120;
        }
        if ( !RGE_Player::get_selected_objects_to_command(
                v6->player,
                (RGE_Static_Object ***)&shift_key,
                (__int16 *)&ctrl_key,
                -1,
                -1,
                -1,
                -1) )
          goto LABEL_120;
        free((void *)shift_key);
        if ( !allow_user_commands )
          goto LABEL_120;
        RGE_Main_View::fixup_pick_info(v6, &pick_info);
        ((void (__stdcall *)(_DWORD, _DWORD, signed int))v6->player->vfptr->command_add_waypoint)(
          LODWORD(pick_info.x),
          LODWORD(pick_info.y),
          1065353216);
        RGE_Main_View::reset_display_object_selection(v6, 2);
        RGE_View::add_overlay_sprite(
          (RGE_View *)&v6->vfptr,
          rge_base_game->shapes[1],
          0,
          x + v6->map_scr_x_offset,
          y + v6->map_scr_y_offset,
          0,
          15,
          0,
          1,
          0xFAu);
        goto LABEL_119;
      }
      v29 = v6->player;
      if ( v29->sel_count <= 1 )
        return 1;
      RGE_Player::unselect_object(v29);
      RGE_Player::select_one_object(v6->player, pick_info.object, 1);
      v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
      v6->mouse_last_x = x;
      v6->mouse_last_y = y;
      return 1;
    default:
      goto LABEL_120;
  }
}
// 58631C: using guessed type int allow_user_commands;

//----- (0053F220) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_right_down_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Main_View *v5; // esi@1
  int v6; // eax@2
  RGE_Base_Game *v7; // eax@6
  RGE_Player *v8; // ecx@8
  int result; // eax@11

  v5 = this;
  if ( RGE_Base_Game::get_paused(rge_base_game)
    || (v6 = rge_base_game->prog_mode, v6 != 4) && v6 != 6 && v6 != 7 && v6 != 5 )
  {
    result = 0;
  }
  else
  {
    color_log(76, 36, 1);
    v7 = rge_base_game;
    if ( rge_base_game->game_mode == 19 )
    {
      v8 = v5->player;
      if ( v8->selected_obj )
      {
        RGE_Player::unselect_object(v8);
        v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
        v7 = rge_base_game;
      }
      (*(void (__thiscall **)(RGE_Base_Game *, signed int, signed int))&v7->vfptr->gap8[8])(v7, 19, 1);
      (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v5->vfptr[1].gap4[4])(
        v5,
        9,
        x,
        y,
        ctrl_key,
        shift_key);
    }
    else
    {
      TPanel::capture_mouse((TPanel *)&v5->vfptr);
    }
    color_log(76, 95, 1);
    result = 1;
  }
  return result;
}

//----- (0053F2F0) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_right_move_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Main_View *v5; // esi@1
  int v6; // eax@1
  bool v7; // zf@5
  char v8; // al@5
  int result; // eax@7
  TPanelVtbl *v10; // edi@12

  v5 = this;
  v6 = rge_base_game->prog_mode;
  if ( v6 != 4 && v6 != 6 && v6 != 7 && v6 != 5 )
    return 0;
  v7 = RGE_Base_Game::get_paused(rge_base_game) == 0;
  v8 = v5->scroll_action;
  if ( v7 )
  {
    if ( v8 )
    {
      ((void (__thiscall *)(RGE_Main_View *, int, int))v5->vfptr[1].set_rect)(v5, x, y);
      return 1;
    }
    if ( !v5->player->sel_count )
    {
      TPanel::release_mouse((TPanel *)&v5->vfptr);
      v10 = v5->vfptr;
      (*(void (__thiscall **)(RGE_Main_View *, signed int, int, int, int, int))&v5->vfptr[1].gap4[4])(
        v5,
        1,
        v5->mouse_down_x,
        v5->mouse_down_y,
        ctrl_key,
        shift_key);
      ((void (__thiscall *)(RGE_Main_View *, int, int))v10[1].set_rect)(v5, x, y);
      return 1;
    }
    return 0;
  }
  if ( v8 )
  {
    (*(void (__thiscall **)(RGE_Main_View *))&v5->vfptr[1].gap10[0])(v5);
    result = 0;
  }
  else
  {
    TPanel::release_mouse((TPanel *)&v5->vfptr);
    result = 0;
  }
  return result;
}

//----- (0053F3D0) --------------------------------------------------------
int __thiscall RGE_Main_View::mouse_right_up_action(RGE_Main_View *this, int x, int y, int ctrl_key, int shift_key)
{
  int v5; // eax@1
  RGE_Main_View *v6; // esi@1
  char v8; // al@12
  RGE_Base_Game *v9; // ecx@15
  int v10; // eax@15
  int v11; // eax@18
  RGE_Static_Object **list; // [sp+Ch] [bp-18h]@21
  RGE_Pick_Info pick_info; // [sp+10h] [bp-14h]@9

  v5 = rge_base_game->prog_mode;
  v6 = this;
  if ( v5 != 4 && v5 != 6 && v5 != 7 && v5 != 5 )
    return 0;
  color_log(76, 50, 1);
  if ( !v6->scroll_action )
  {
    TPanel::release_mouse((TPanel *)&v6->vfptr);
    if ( rge_base_game->game_mode == 20 )
    {
      if ( RGE_Main_View::pick1(v6, 41, 2, x, y, &pick_info, v6->player->selected_obj, 1) == 52 )
        ((void (__stdcall *)(signed int))pick_info.object->vfptr->rotate)(-1);
      goto LABEL_33;
    }
    if ( RGE_Base_Game::get_paused(rge_base_game) || (v8 = v6->mouse_action, v8 != 1) && v8 != 2 )
    {
      color_log(76, 95, 1);
      return 0;
    }
    v9 = rge_base_game;
    v10 = rge_base_game->prog_mode;
    if ( rge_base_game->prog_info->interface_style == 2 )
    {
      if ( v10 == 5 || v10 == 7 )
        goto LABEL_33;
      v11 = rge_base_game->game_mode;
      if ( v11 )
      {
        if ( v11 == 21 )
        {
          RGE_View::set_selection_area((RGE_View *)&v6->vfptr, -1, -1, -1, -1);
          v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
          v9 = rge_base_game;
        }
        (*(void (__stdcall **)(_DWORD, _DWORD))&v9->vfptr->gap8[8])(0, 0);
        goto LABEL_33;
      }
      if ( !shift_key )
      {
        ((void (__thiscall *)(RGE_Main_View *, int, int, signed int, signed int))v6->vfptr[1].set_redraw)(
          v6,
          x,
          y,
          1,
          -1);
        goto LABEL_33;
      }
      if ( !RGE_Player::get_selected_objects_to_command(v6->player, &list, (__int16 *)&shift_key, -1, -1, -1, -1) )
        goto LABEL_33;
      free(list);
      if ( !allow_user_commands || RGE_Main_View::pick1(v6, 40, 0, x, y, &pick_info, 0, 1) != 51 )
        goto LABEL_33;
      RGE_Main_View::fixup_pick_info(v6, &pick_info);
      ((void (__stdcall *)(_DWORD, _DWORD, signed int))v6->player->vfptr->command_add_waypoint)(
        LODWORD(pick_info.x),
        LODWORD(pick_info.y),
        1065353216);
      RGE_Main_View::reset_display_object_selection(v6, 2);
      RGE_View::add_overlay_sprite(
        (RGE_View *)&v6->vfptr,
        rge_base_game->shapes[1],
        0,
        x + v6->map_scr_x_offset,
        y + v6->map_scr_y_offset,
        0,
        15,
        0,
        1,
        0xFAu);
    }
    else
    {
      if ( v10 == 7 )
        goto LABEL_33;
      if ( rge_base_game->game_mode )
      {
        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
        goto LABEL_33;
      }
      RGE_Player::unselect_object(v6->player);
    }
    v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
    goto LABEL_33;
  }
  (*(void (__thiscall **)(RGE_Main_View *))&v6->vfptr[1].gap10[0])(v6);
LABEL_33:
  color_log(76, 95, 1);
  return 1;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0053F660) --------------------------------------------------------
int __thiscall RGE_Main_View::start_scroll_view(RGE_Main_View *this, char scroll_action_in, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Main_View *v6; // esi@1
  TPanel *v7; // ecx@2
  int result; // eax@4

  v6 = this;
  if ( RGE_View::start_scroll_view((RGE_View *)&this->vfptr, scroll_action_in, x, y, ctrl_key, shift_key) )
  {
    v7 = v6->map_view;
    if ( v7 )
      ((void (__stdcall *)(signed int))v7->vfptr->set_redraw)(1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053F6B0) --------------------------------------------------------
int __thiscall RGE_Main_View::handle_scroll_view(RGE_Main_View *this, int x, int y)
{
  RGE_Main_View *v3; // esi@1
  TPanel *v4; // ecx@2
  int result; // eax@4

  v3 = this;
  if ( RGE_View::handle_scroll_view((RGE_View *)&this->vfptr, x, y) )
  {
    v4 = v3->map_view;
    if ( v4 )
      ((void (__stdcall *)(signed int))v4->vfptr->set_redraw)(1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053F6F0) --------------------------------------------------------
void __thiscall RGE_Main_View::draw(RGE_Main_View *this)
{
  RGE_Main_View *v1; // esi@1
  unsigned int v2; // ebx@1
  unsigned int v3; // ebp@1
  TPanelVtbl *v4; // edi@7
  unsigned int v5; // esi@8
  unsigned int v6; // eax@8

  v1 = this;
  v2 = debug_timeGetTime();
  v3 = RGE_Base_Game::get_accum_time(rge_base_game, 11);
  if ( v1->world && v1->player )
  {
    if ( do_draw_log )
      write_draw_log2(aVs);
    color_log(76, 76, 1);
    RGE_View::draw((RGE_View *)&v1->vfptr);
    color_log(76, 95, 1);
    if ( do_draw_log )
      write_draw_log2(aVf);
  }
  else
  {
    v4 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    TDrawArea::Clear(v1->render_area, &v1->clip_rect, v1->color);
    v4->draw_finish((TPanel *)v1);
  }
  v5 = RGE_Base_Game::get_accum_time(rge_base_game, 11) - v3;
  v6 = debug_timeGetTime();
  RGE_Base_Game::add_to_timing(rge_base_game, 6, v6 - v2 - v5);
  RGE_Base_Game::increment_view_update_count(rge_base_game);
  RGE_Base_Game::add_to_timing(rge_base_game, 12, v5);
}
// 62C498: using guessed type int do_draw_log;

//----- (0053F810) --------------------------------------------------------
int __thiscall RGE_Main_View::command_place_object(RGE_Main_View *this, int x, int y, int reset_mode)
{
  RGE_Main_View *v4; // ebp@1
  int v5; // ebx@3
  int v6; // edx@5
  signed int v7; // eax@5
  int v8; // esi@5
  int v9; // edi@7
  int v10; // edx@7
  int v11; // ST14_4@7
  float v12; // ST08_4@7
  float v13; // ST04_4@7
  RGE_Game_World *v14; // eax@7
  int v15; // eax@8
  RGE_Game_World *v16; // eax@9
  int v18; // esi@14
  RGE_Game_World *v19; // eax@15
  RGE_Active_Sprite_List *v20; // ecx@17
  char v21; // al@18
  RGE_Sprite *v22; // esi@19
  RGE_Pick_Info pick_info; // [sp+38h] [bp-14h]@2

  v4 = this;
  if ( allow_user_commands )
  {
    if ( RGE_Main_View::pick1(this, 40, 0, x, y, &pick_info, 0, 1) == 51 )
    {
      RGE_Main_View::fixup_pick_info(v4, &pick_info);
      v5 = rge_base_game->master_obj_id;
      if ( v5 != -1 )
      {
        if ( *(_DWORD *)(RGE_Base_Game::get_player(rge_base_game)->sprite_update_index + 4 * v5) )
        {
          v6 = RGE_Base_Game::get_player(rge_base_game)->sprite_update_index;
          v7 = 1;
          v8 = *(_DWORD *)(v6 + 4 * v5);
          if ( rge_base_game->sub_game_mode == 3 )
            v7 = 0;
          v9 = *(_DWORD *)v8;
          (*(void (__thiscall **)(int, RGE_Pick_Info *, float *, RGE_Game_World *, signed int))(*(_DWORD *)v8 + 36))(
            v8,
            &pick_info,
            &pick_info.y,
            v4->world,
            v7);
          LOBYTE(v10) = *(_BYTE *)(v8 + 100);
          v11 = v10;
          v12 = pick_info.y;
          v13 = pick_info.x;
          v14 = RGE_Base_Game::get_player(rge_base_game);
          if ( !((*(int (__thiscall **)(int, RGE_Game_World *, float, float, _DWORD, signed int, int, _DWORD, signed int, signed int, signed int))(v9 + 32))(
                   v8,
                   v14,
                   COERCE_FLOAT(LODWORD(v13)),
                   COERCE_FLOAT(LODWORD(v12)),
                   0,
                   1,
                   v11,
                   0,
                   1,
                   1,
                   1) & 0xFF) )
          {
            v15 = rge_base_game->game_mode;
            if ( v15 == 1 )
            {
              v16 = RGE_Base_Game::get_player(rge_base_game);
              if ( (unsigned __int8)((int (__thiscall *)(RGE_Game_World *, int, _DWORD, _DWORD, _DWORD))v16->vfptr->init)(
                                      v16,
                                      v5,
                                      LODWORD(pick_info.x),
                                      LODWORD(pick_info.y),
                                      0) )
              {
                if ( reset_mode )
                {
                  (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                  return 1;
                }
                return 1;
              }
            }
            else if ( v15 == 8 )
            {
              if ( rge_base_game->sub_game_mode == 1 )
              {
                v18 = (int)v4->movable_object;
                (*(void (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v18 + 52))(
                  v4->movable_object,
                  LODWORD(pick_info.x),
                  LODWORD(pick_info.y),
                  0);
              }
              else
              {
                v19 = RGE_Base_Game::get_player(rge_base_game);
                v18 = ((int (__thiscall *)(RGE_Game_World *, int, _DWORD, _DWORD, _DWORD, signed int))v19->vfptr->load_scenario7)(
                        v19,
                        v5,
                        LODWORD(pick_info.x),
                        LODWORD(pick_info.y),
                        0,
                        1);
              }
              if ( v18 )
              {
                v20 = *(RGE_Active_Sprite_List **)(v18 + 24);
                if ( v20 )
                {
                  v21 = RGE_Active_Sprite_List::get_lowest_draw_level(v20);
                }
                else
                {
                  v22 = *(RGE_Sprite **)(v18 + 16);
                  if ( v22 )
                    v21 = RGE_Sprite::get_lowest_draw_level(v22);
                  else
                    v21 = 20;
                }
                if ( !v21 )
                {
                  v4->vfptr->set_redraw((TPanel *)v4, RedrawFull);
                  return 1;
                }
                v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0053FA10) --------------------------------------------------------
int __thiscall RGE_Main_View::command_make_do(RGE_Main_View *this, int x, int y, int work_on_tile, __int16 action_type)
{
  RGE_Main_View *v5; // esi@1
  RGE_Static_Object *v6; // eax@3
  RGE_Static_Object *v7; // edi@3
  int v8; // ebx@4
  int v10; // edi@9
  __int16 list_num; // [sp+12h] [bp-1Eh]@2
  RGE_Static_Object **list; // [sp+14h] [bp-1Ch]@2
  int attacking; // [sp+18h] [bp-18h]@3
  RGE_Pick_Info pick_info; // [sp+1Ch] [bp-14h]@8

  v5 = this;
  if ( !allow_user_commands
    || !RGE_Player::get_selected_objects_to_command(this->player, &list, &list_num, -1, -1, -1, -1) )
  {
    return 0;
  }
  free(list);
  color_log(76, -70, 2);
  v6 = RGE_Main_View::pick_best_target(v5, x, y, &attacking, action_type);
  v7 = v6;
  if ( v6 )
  {
    v8 = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD))v5->player->vfptr->command_make_do)(
           v6,
           LODWORD(v6->world_x),
           LODWORD(v6->world_y)) & 0xFF;
    if ( v8 )
      RGE_View::display_object_selection((RGE_View *)&v5->vfptr, v7->id, 1500, 2, 2);
    RGE_View::reset_overlay_sprites((RGE_View *)&v5->vfptr);
    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
    color_log(76, 95, 2);
    return v8;
  }
  if ( !work_on_tile || RGE_Main_View::pick1(v5, 40, 0, x, y, &pick_info, 0, 1) != 51 )
  {
    RGE_View::reset_overlay_sprites((RGE_View *)&v5->vfptr);
    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
    color_log(76, 95, 2);
    return 0;
  }
  RGE_Main_View::fixup_pick_info(v5, &pick_info);
  v10 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v5->player->vfptr->command_make_move)(
          0,
          LODWORD(pick_info.x),
          LODWORD(pick_info.y)) & 0xFF;
  if ( v10 )
  {
    RGE_Main_View::reset_display_object_selection(v5, 2);
    RGE_View::add_overlay_sprite(
      (RGE_View *)&v5->vfptr,
      rge_base_game->shapes[2],
      0,
      x + v5->map_scr_x_offset,
      y + v5->map_scr_y_offset,
      0,
      15,
      0,
      2,
      0x5Au);
    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
  }
  color_log(76, 95, 2);
  return v10;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0053FBD0) --------------------------------------------------------
char __thiscall RGE_Main_View::pick1(RGE_Main_View *this, char pick_mode_in, char select_level, int x, int y, RGE_Pick_Info *pick_info, RGE_Static_Object *last_picked_object, int pick_dopples)
{
  RGE_Main_View *v8; // esi@1
  RGE_Pick_Info *v9; // edi@2
  int v10; // eax@3
  int v11; // ecx@5
  char result; // al@6
  RGE_Static_Object *v13; // eax@8
  __int16 v14; // bx@8
  void *v15; // ebp@9
  RGE_Static_Object *v16; // edi@11
  int v17; // eax@18
  RGE_Static_Object *v18; // ecx@18
  __int16 v19; // bx@25
  __int16 v20; // bp@25
  _WORD *v21; // ecx@25
  RGE_Static_Object *v22; // edi@27
  bool v23; // sf@40
  unsigned __int8 v24; // of@40
  int target_count; // [sp+10h] [bp-8h]@5
  int found_last; // [sp+14h] [bp-4h]@24
  RGE_Static_Object *pick_mode_ina; // [sp+1Ch] [bp+4h]@8
  RGE_Static_Object *pick_mode_inb; // [sp+1Ch] [bp+4h]@24
  int xa; // [sp+24h] [bp+Ch]@8
  int xb; // [sp+24h] [bp+Ch]@24
  int i; // [sp+28h] [bp+10h]@9
  void *ia; // [sp+28h] [bp+10h]@25
  RGE_Static_Object *last_picked_objecta; // [sp+30h] [bp+18h]@8

  v8 = this;
  if ( pick_mode_in != 41 )
  {
    if ( pick_mode_in != 42
      || (result = RGE_Main_View::pick1(this, 41, select_level, x, y, pick_info, last_picked_object, 1), result != 52) )
    {
      result = RGE_View::pick((RGE_View *)&v8->vfptr, 40, select_level, x, y, pick_info, last_picked_object);
    }
    return result;
  }
  v9 = pick_info;
  LODWORD(pick_info->x) = 0;
  LODWORD(pick_info->y) = 0;
  pick_info->scr_x = 0;
  pick_info->scr_y = 0;
  pick_info->object = 0;
  pick_info->tile = 0;
  if ( select_level )
    v10 = RGE_View::pick_objects((RGE_View *)&this->vfptr, x, y, 10, 20, 15, 4, 1);
  else
    v10 = RGE_View::pick_objects((RGE_View *)&this->vfptr, x, y, 0, 40, 15, 4, 1);
  v11 = v10;
  target_count = v10;
  if ( !v10 )
    return 50;
  if ( !last_picked_object )
  {
    v13 = 0;
    v14 = 0;
    pick_mode_ina = 0;
    last_picked_objecta = 0;
    xa = 0;
    if ( v11 > 0 )
    {
      v15 = &Picked_Objects;
      i = v11;
      do
      {
        if ( *(_DWORD *)v15 >= 0 )
        {
          v16 = v8->world->objectsValue[*(_DWORD *)v15];
          if ( v16 )
          {
            if ( v16->object_state < 7u
              && v16->master_obj->select_level >= (unsigned __int8)select_level
              && (pick_dopples
               || v8->map->map_visible_flag
               || (int)v8->vfptr[1].__vecDelDtor((TPanel *)v8, (unsigned int)v16)
               || RGE_Visible_Map::get_visible(
                    v8->player->visible,
                    (signed __int64)v16->world_x,
                    (signed __int64)v16->world_y) == 15) )
            {
              v17 = (*(int (__thiscall **)(RGE_Main_View *, RGE_Static_Object *, _DWORD))&v8->vfptr[1].gap4[0])(
                      v8,
                      v16,
                      *((_WORD *)v15 + 2));
              if ( v17 > xa )
              {
                v14 = *((_WORD *)v15 + 4) + LOWORD(v8->render_rect.left);
                LOWORD(v18) = *((_WORD *)v15 + 5) + LOWORD(v8->render_rect.top);
                pick_mode_ina = v16;
                xa = v17;
                last_picked_objecta = v18;
              }
            }
          }
        }
        v15 = (char *)v15 + 12;
        --i;
      }
      while ( i );
      v13 = pick_mode_ina;
      v9 = pick_info;
    }
    if ( v13 )
    {
      v9->object = v13;
      v9->scr_x = v14;
      v9->scr_y = (signed __int16)last_picked_objecta;
      v9->x = v13->world_x;
      v9->y = v13->world_y;
      return 52;
    }
    return 50;
  }
  found_last = 0;
  pick_mode_inb = 0;
  xb = 0;
  if ( v10 <= 0 )
  {
    v19 = (signed __int16)last_picked_object;
    v20 = 0;
    goto LABEL_44;
  }
  v19 = (signed __int16)last_picked_object;
  v20 = 0;
  v21 = &Picked_Objects;
  ia = &Picked_Objects;
  while ( 1 )
  {
    if ( *(_DWORD *)v21 < 0 )
      goto LABEL_40;
    v22 = v8->world->objectsValue[*(_DWORD *)v21];
    if ( !v22
      || v22->object_state >= 7u
      || v22->master_obj->select_level < (unsigned __int8)select_level
      || (*(int (__thiscall **)(RGE_Main_View *, RGE_Static_Object *, _DWORD))&v8->vfptr[1].gap4[0])(v8, v22, v21[2]) <= 0
      || !pick_dopples
      && !v8->map->map_visible_flag
      && !(int)v8->vfptr[1].__vecDelDtor((TPanel *)v8, (unsigned int)v22)
      && RGE_Visible_Map::get_visible(v8->player->visible, (signed __int64)v22->world_x, (signed __int64)v22->world_y) != 15 )
    {
      goto LABEL_40;
    }
    if ( v22 != last_picked_object )
      break;
    found_last = 1;
LABEL_40:
    v21 = (char *)ia + 12;
    v24 = __OFSUB__(xb + 1, target_count);
    v23 = xb++ + 1 - target_count < 0;
    ia = (char *)ia + 12;
    if ( !(v23 ^ v24) )
      goto LABEL_44;
  }
  if ( !found_last )
  {
    if ( !pick_mode_inb )
    {
      pick_mode_inb = v22;
      v20 = *((_WORD *)ia + 4) + LOWORD(v8->render_rect.left);
      v19 = *((_WORD *)ia + 5) + LOWORD(v8->render_rect.top);
    }
    goto LABEL_40;
  }
  pick_mode_inb = v22;
  v20 = LOWORD(v8->render_rect.left) + word_87D4A8[6 * xb];
  v19 = LOWORD(v8->render_rect.top) + word_87D4AA[6 * xb];
LABEL_44:
  if ( found_last && !pick_mode_inb )
  {
    pick_mode_inb = last_picked_object;
    v20 = LOWORD(v8->render_rect.left) + word_87D4A8[6 * xb];
    v19 = LOWORD(v8->render_rect.top) + word_87D4AA[6 * xb];
  }
  if ( pick_mode_inb )
  {
    pick_info->object = pick_mode_inb;
    pick_info->scr_x = v20;
    pick_info->scr_y = v19;
    pick_info->x = pick_mode_inb->world_x;
    pick_info->y = pick_mode_inb->world_y;
    return 52;
  }
  return 50;
}
// 87D4A8: using guessed type __int16 word_87D4A8[];
// 87D4AA: using guessed type __int16 word_87D4AA[];

//----- (0053FFB0) --------------------------------------------------------
int __thiscall RGE_Main_View::pick_objects1(RGE_Main_View *this, int x, int y, RGE_Static_Object **object_list, int max_objects)
{
  RGE_Static_Object *v5; // eax@1
  RGE_Static_Object **v6; // edi@1
  RGE_Main_View *v7; // ebx@1
  int v8; // esi@1
  RGE_Pick_Info pick_info; // [sp+10h] [bp-14h]@3

  v5 = 0;
  v6 = object_list;
  v7 = this;
  v8 = 0;
  while ( v8 != max_objects )
  {
    if ( (unsigned __int8)RGE_View::pick((RGE_View *)&v7->vfptr, 41, 0, x, y, &pick_info, v5) != 52 )
      break;
    v5 = pick_info.object;
    if ( v8 > 0 && pick_info.object == *object_list )
      break;
    *v6 = pick_info.object;
    ++v8;
    ++v6;
  }
  return v8;
}

//----- (00540010) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Main_View::pick_best_target(RGE_Main_View *this, int x, int y, int *attacking_in, __int16 action_type)
{
  RGE_Main_View *v5; // ebx@1
  RGE_Static_Object *result; // eax@3
  int v7; // ebp@3
  int v8; // edx@8
  RGE_Static_Object *v9; // eax@9
  RGE_Master_Action_Object *v10; // edi@9
  int v11; // eax@12
  RGE_Static_Object *v12; // ebp@13
  int v13; // esi@15
  TPanelVtbl *v14; // edx@20
  int v15; // eax@20
  int v16; // ebx@20
  RGE_Task_ListVtbl *v17; // edx@20
  signed int v18; // ebx@23
  RGE_Player *v19; // eax@23
  RGE_Master_Static_Object *v20; // edi@24
  int v21; // esi@28
  int v22; // ebp@35
  int v23; // eax@35
  bool v24; // sf@37
  unsigned __int8 v25; // of@37
  int v26; // esi@40
  int v27; // ecx@40
  _DWORD *v28; // edi@41
  int v29; // edx@42
  __int16 *v30; // [sp+34h] [bp-224h]@10
  __int16 selected_count; // [sp+3Ah] [bp-21Eh]@4
  RGE_Main_View *v32; // [sp+3Ch] [bp-21Ch]@1
  RGE_Static_Object **selected_objects; // [sp+40h] [bp-218h]@4
  int i; // [sp+44h] [bp-214h]@8
  int j; // [sp+48h] [bp-210h]@9
  int target_count; // [sp+4Ch] [bp-20Ch]@3
  RGE_Master_Action_Object *master_obj; // [sp+50h] [bp-208h]@9
  unsigned int v38; // [sp+54h] [bp-204h]@20
  int valid_target_count[64]; // [sp+58h] [bp-200h]@7
  int attacking[64]; // [sp+158h] [bp-100h]@7

  v5 = this;
  v32 = this;
  if ( attacking_in )
    *attacking_in = 0;
  result = (RGE_Static_Object *)RGE_View::pick_objects((RGE_View *)&this->vfptr, x, y, 10, 20, 15, 4, 1);
  v7 = (int)result;
  target_count = (int)result;
  if ( result )
  {
    if ( !RGE_Player::get_selected_objects_to_command(v5->player, &selected_objects, &selected_count, -1, -1, -1, -1) )
      return 0;
    if ( v7 > 0 )
    {
      memset(attacking, 0, 4 * ((unsigned int)(4 * v7) >> 2));
      memset(valid_target_count, 0, 4 * ((unsigned int)(4 * v7) >> 2));
    }
    v8 = 0;
    i = 0;
    if ( selected_count <= 0 )
      goto LABEL_40;
    while ( 1 )
    {
      j = 0;
      v9 = selected_objects[v8];
      v10 = (RGE_Master_Action_Object *)v9->master_obj;
      master_obj = (RGE_Master_Action_Object *)v9->master_obj;
      if ( v7 <= 0 )
        goto LABEL_39;
      v30 = word_87D4A4;
      while ( 1 )
      {
        v11 = *((_DWORD *)v30 - 1);
        if ( v11 >= 0 )
        {
          v12 = v5->world->objectsValue[v11];
          if ( v12 )
          {
            if ( v12->object_state < 7u )
            {
              v13 = ((int (__stdcall *)(RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v10->tasks->vfptr->get_target_task)(
                      selected_objects[v8],
                      v12,
                      0,
                      0,
                      0);
              if ( v13 )
              {
                if ( action_type != -1 && *(_WORD *)(v13 + 6) != action_type )
                  v13 = 0;
                if ( v13 )
                {
                  v14 = v5->vfptr;
                  v38 = 4 * j;
                  v15 = (*(int (__thiscall **)(RGE_Main_View *, RGE_Static_Object *, _DWORD))&v14[1].gap4[0])(
                          v5,
                          v12,
                          *v30);
                  v16 = v38;
                  v17 = v10->tasks->vfptr;
                  valid_target_count[v38 / 4] += v15;
                  if ( !((int (__stdcall *)(int))v17->is_attack_task)(v13) )
                    goto LABEL_37;
LABEL_36:
                  *(int *)((char *)attacking + v16) = 1;
                  goto LABEL_37;
                }
              }
              if ( v10->task_by_group )
              {
                v18 = 0;
                v19 = v32->player;
                if ( v19->master_object_num > 0 )
                {
                  while ( 1 )
                  {
                    v20 = v19->master_objects[v18];
                    if ( v20 )
                    {
                      if ( v20->object_group == master_obj->object_group
                        && v20->master_type == master_obj->master_type
                        && LOBYTE(v20[1].radius_y) == master_obj->task_by_group )
                      {
                        v21 = (*(int (__stdcall **)(RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v20[1].undead_sprite + 4))(
                                selected_objects[i],
                                v12,
                                0,
                                0,
                                0);
                        if ( v21 )
                        {
                          if ( action_type != -1 && *(_WORD *)(v21 + 6) != action_type )
                            v21 = 0;
                          if ( v21 )
                            break;
                        }
                      }
                    }
                    ++v18;
                    v19 = v32->player;
                    if ( v18 >= v19->master_object_num )
                      goto LABEL_37;
                  }
                  v16 = 4 * j;
                  v22 = (*(int (__stdcall **)(RGE_Static_Object *, _DWORD))&v32->vfptr[1].gap4[0])(v12, *v30)
                      + *(int *)((char *)valid_target_count + v16);
                  v23 = *(_DWORD *)v20[1].undead_sprite;
                  *(int *)((char *)valid_target_count + v16) = v22;
                  if ( (*(int (__stdcall **)(int))(v23 + 8))(v21) )
                    goto LABEL_36;
                }
              }
            }
          }
        }
LABEL_37:
        v7 = target_count;
        v25 = __OFSUB__(j + 1, target_count);
        v24 = j++ + 1 - target_count < 0;
        v30 += 6;
        if ( !(v24 ^ v25) )
          break;
        v10 = master_obj;
        v8 = i;
        v5 = v32;
      }
      v8 = i;
      v5 = v32;
LABEL_39:
      i = ++v8;
      if ( v8 >= selected_count )
      {
LABEL_40:
        free(selected_objects);
        v26 = 0;
        result = 0;
        v27 = 0;
        if ( v7 > 0 )
        {
          v28 = &Picked_Objects;
          do
          {
            v29 = valid_target_count[v27];
            if ( v29 > v26 )
            {
              result = v5->world->objectsValue[*v28];
              if ( attacking_in )
              {
                *attacking_in = attacking[v27];
                v7 = target_count;
              }
              v26 = v29;
            }
            ++v27;
            v28 += 3;
          }
          while ( v27 < v7 );
        }
        return result;
      }
    }
  }
  return result;
}
// 87D4A4: using guessed type __int16 word_87D4A4[];

//----- (00540350) --------------------------------------------------------
int __thiscall RGE_Main_View::command_make_move(RGE_Main_View *this, int x, int y)
{
  RGE_Main_View *v3; // esi@1
  int v4; // edi@3
  int result; // eax@5
  __int16 list_num; // [sp+Ah] [bp-1Ah]@2
  RGE_Static_Object **list; // [sp+Ch] [bp-18h]@2
  RGE_Pick_Info pick_info; // [sp+10h] [bp-14h]@3

  v3 = this;
  if ( allow_user_commands
    && RGE_Player::get_selected_objects_to_command(this->player, &list, &list_num, -1, -1, -1, -1) )
  {
    free(list);
    v4 = 0;
    if ( RGE_Main_View::pick1(v3, 42, 1, x, y, &pick_info, 0, 1) != 50 )
    {
      RGE_Main_View::fixup_pick_info(v3, &pick_info);
      v4 = (unsigned __int8)((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD))v3->player->vfptr->command_make_move)(
                              pick_info.object,
                              LODWORD(pick_info.x),
                              LODWORD(pick_info.y));
      v3->vfptr->set_redraw((TPanel *)v3, RedrawNormal);
    }
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 58631C: using guessed type int allow_user_commands;

//----- (00540420) --------------------------------------------------------
int __thiscall RGE_Main_View::command_make_work(RGE_Main_View *this, int x, int y)
{
  RGE_Main_View *v3; // esi@1
  RGE_Static_Object *v4; // eax@3
  RGE_Static_Object *v5; // edi@3
  int v6; // ebx@4
  int v8; // edi@8
  __int16 list_num; // [sp+12h] [bp-1Eh]@2
  RGE_Static_Object **list; // [sp+14h] [bp-1Ch]@2
  int attacking; // [sp+18h] [bp-18h]@3
  RGE_Pick_Info pick_info; // [sp+1Ch] [bp-14h]@7

  v3 = this;
  if ( !allow_user_commands
    || !RGE_Player::get_selected_objects_to_command(this->player, &list, &list_num, -1, -1, -1, -1) )
  {
    return 0;
  }
  free(list);
  v4 = RGE_Main_View::pick_best_target(v3, x, y, &attacking, -1);
  v5 = v4;
  if ( v4 )
  {
    v6 = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD))v3->player->vfptr->command_make_work)(
           v4,
           LODWORD(v4->world_x),
           LODWORD(v4->world_y)) & 0xFF;
    if ( v6 )
      RGE_View::display_object_selection((RGE_View *)&v3->vfptr, v5->id, 1500, 2, 2);
    RGE_View::reset_overlay_sprites((RGE_View *)&v3->vfptr);
    v3->vfptr->set_redraw((TPanel *)v3, RedrawNormal);
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    return v6;
  }
  if ( RGE_Main_View::pick1(v3, 40, 0, x, y, &pick_info, 0, 1) != 51 )
  {
    RGE_View::reset_overlay_sprites((RGE_View *)&v3->vfptr);
    v3->vfptr->set_redraw((TPanel *)v3, RedrawNormal);
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    return 0;
  }
  RGE_Main_View::fixup_pick_info(v3, &pick_info);
  v8 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v3->player->vfptr->command_make_work)(
         0,
         LODWORD(pick_info.x),
         LODWORD(pick_info.y)) & 0xFF;
  if ( v8 )
  {
    RGE_Main_View::reset_display_object_selection(v3, 2);
    RGE_View::add_overlay_sprite(
      (RGE_View *)&v3->vfptr,
      rge_base_game->shapes[2],
      0,
      x + v3->map_scr_x_offset,
      y + v3->map_scr_y_offset,
      0,
      15,
      0,
      2,
      0x5Au);
  }
  v3->vfptr->set_redraw((TPanel *)v3, RedrawNormal);
  (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
  return v8;
}
// 58631C: using guessed type int allow_user_commands;

//----- (005405C0) --------------------------------------------------------
int __thiscall RGE_Main_View::command_place_multi_object(RGE_Main_View *this, int x1, int y1, int x2, int y2, int reset_mode)
{
  RGE_Main_View *v6; // esi@1

  v6 = this;
  RGE_View::set_selection_area((RGE_View *)&this->vfptr, -1, -1, -1, -1);
  v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
  return 0;
}

//----- (005405E0) --------------------------------------------------------
char __thiscall RGE_Main_View::get_help_info(RGE_Main_View *this, char **string, int *page, int x, int y)
{
  RGE_Main_View *v5; // esi@1
  int v6; // eax@2
  char result; // al@2
  RGE_Pick_Info pick_info; // [sp+Ch] [bp-14h]@1

  v5 = this;
  if ( RGE_Main_View::pick1(this, 41, 2, x, y, &pick_info, 0, 1) == 52 )
  {
    v6 = RGE_Master_Static_Object::get_help_message(pick_info.object->master_obj);
    strcpy(*string, TPanel::get_string(v6));
    *page = RGE_Master_Static_Object::get_help_page(pick_info.object->master_obj);
    result = 1;
  }
  else
  {
    result = TPanel::get_help_info((TPanel *)&v5->vfptr, string, page, x, y);
  }
  return result;
}

//----- (00540680) --------------------------------------------------------
void __thiscall RGE_Main_View::fixup_pick_info(RGE_Main_View *this, RGE_Pick_Info *pick_info)
{
  double v2; // st7@3
  double v3; // st7@7

  if ( pick_info->x >= 0.0 )
  {
    v2 = (double)this->map->map_width;
    if ( v2 <= pick_info->x )
      pick_info->x = v2 - 1.0;
  }
  else
  {
    LODWORD(pick_info->x) = 0;
  }
  if ( pick_info->y >= 0.0 )
  {
    v3 = (double)this->map->map_height;
    if ( v3 <= pick_info->y )
      pick_info->y = v3 - 1.0;
  }
  else
  {
    LODWORD(pick_info->y) = 0;
  }
}

//----- (00540700) --------------------------------------------------------
void __thiscall RGE_Main_View::reset_display_object_selection(RGE_Main_View *this, int reset_type)
{
  int v2; // esi@1
  int v3; // edx@2
  DisplaySelectedObjRec *v4; // eax@3

  v2 = 0;
  if ( this->DispSel_List_Max > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->DispSel_List[v3];
      if ( v4->active == 1 && v4->select_type == reset_type )
        v4->start_time -= v4->duration;
      ++v2;
      ++v3;
    }
    while ( v2 < this->DispSel_List_Max );
  }
}
