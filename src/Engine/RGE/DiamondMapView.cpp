
//----- (0053D360) --------------------------------------------------------
void __thiscall RGE_Diamond_Map_View::RGE_Diamond_Map_View(RGE_Diamond_Map_View *this)
{
  RGE_Diamond_Map_View *v1; // esi@1

  v1 = this;
  RGE_Diamond_Map::RGE_Diamond_Map((RGE_Diamond_Map *)&this->vfptr);
  v1->vfptr = (TPanelVtbl *)&RGE_Diamond_Map_View::`vftable';
  v1->mouse_move_tolerance = 0;
}
// 5776E8: using guessed type int (__thiscall *RGE_Diamond_Map_View::`vftable')(void *Memory, unsigned int __flags);

//----- (0053D380) --------------------------------------------------------
RGE_Diamond_Map_View *__thiscall RGE_Diamond_Map_View::`scalar deleting destructor'(RGE_Diamond_Map_View *this, unsigned int __flags)
{
  RGE_Diamond_Map_View *v2; // esi@1

  v2 = this;
  RGE_Diamond_Map_View::~RGE_Diamond_Map_View(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0053D3B0) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::handle_mouse_down(RGE_Diamond_Map_View *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  int v6; // ebx@1
  RGE_Diamond_Map_View *v7; // esi@1
  int v8; // edi@1
  int result; // eax@1
  RGE_Tile *tile; // [sp+Ch] [bp-4h]@1

  v6 = x;
  v7 = this;
  v8 = y;
  result = RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&this->vfptr, x, y, (__int16 *)&x, (__int16 *)&y, &tile);
  if ( result )
    result = TPanel::handle_mouse_down((TPanel *)&v7->vfptr, mouse_button_in, v6, v8, ctrl_key, shift_key);
  return result;
}

//----- (0053D400) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::mouse_left_down_action(RGE_Diamond_Map_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Diamond_Map_View *v5; // esi@1
  int v6; // eax@2
  int result; // eax@7

  v5 = this;
  if ( RGE_Base_Game::get_paused(rge_base_game)
    || (v6 = rge_base_game->prog_mode, v6 != 4) && v6 != 6 && v6 != 7 && v6 != 5 )
  {
    result = 0;
  }
  else if ( rge_base_game->prog_info->interface_style == 2 )
  {
    RGE_Diamond_Map::start_scroll_view((RGE_Diamond_Map *)&v5->vfptr, x, y);
    result = 1;
  }
  else
  {
    if ( v6 == 4 || v6 == 6 || v6 == 7 )
      TPanel::capture_mouse((TPanel *)&v5->vfptr);
    result = 1;
  }
  return result;
}

//----- (0053D480) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::mouse_left_move_action(RGE_Diamond_Map_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Diamond_Map_View *v5; // esi@1
  int v6; // eax@1
  bool v7; // zf@5
  int v8; // eax@5
  int result; // eax@7

  v5 = this;
  v6 = rge_base_game->prog_mode;
  if ( v6 != 4 && v6 != 6 && v6 != 7 && v6 != 5 )
    return 0;
  v7 = RGE_Base_Game::get_paused(rge_base_game) == 0;
  v8 = v5->scrolling;
  if ( v7 )
  {
    if ( v8 )
    {
      RGE_Diamond_Map::handle_scroll_view((RGE_Diamond_Map *)&v5->vfptr, x, y);
      return 1;
    }
    return 0;
  }
  if ( v8 )
  {
    RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)&v5->vfptr);
    result = 0;
  }
  else
  {
    TPanel::release_mouse((TPanel *)&v5->vfptr);
    result = 0;
  }
  return result;
}

//----- (0053D500) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::mouse_left_up_action(RGE_Diamond_Map_View *this, int x, int y, int ctrl_key, int shift_key)
{
  int v5; // eax@1
  RGE_Diamond_Map_View *v6; // esi@1
  int v8; // eax@10
  int v9; // eax@11
  __int16 row; // [sp+Ch] [bp-8h]@9
  __int16 col; // [sp+Eh] [bp-6h]@9
  RGE_Tile *tile; // [sp+10h] [bp-4h]@9

  v5 = rge_base_game->prog_mode;
  v6 = this;
  if ( v5 == 4 || v5 == 6 || v5 == 7 || v5 == 5 )
  {
    if ( this->scrolling )
    {
      RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)&this->vfptr);
      return 1;
    }
    TPanel::release_mouse((TPanel *)&this->vfptr);
    if ( !RGE_Base_Game::get_paused(rge_base_game)
      && rge_base_game->prog_mode != 5
      && RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&v6->vfptr, x, y, &col, &row, &tile) )
    {
      v8 = rge_base_game->game_mode;
      if ( v8 )
      {
        v9 = v8 - 4;
        if ( !v9 )
        {
          (*(void (__thiscall **)(RGE_Diamond_Map_View *, int, int))&v6->vfptr[1].gap10[8])(v6, x, y);
          return 1;
        }
        if ( v9 == 1 )
        {
          ((void (__thiscall *)(RGE_Diamond_Map_View *, int, int))v6->vfptr[1].set_fixed_position)(v6, x, y);
          return 1;
        }
      }
      else if ( rge_base_game->prog_info->interface_style != 2
             && (*(int (__thiscall **)(RGE_Diamond_Map_View *, int, int))&v6->vfptr[1].gap10[4])(v6, x, y) )
      {
        return 1;
      }
    }
  }
  return 0;
}

//----- (0053D620) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::mouse_right_down_action(RGE_Diamond_Map_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Diamond_Map_View *v5; // esi@1
  int v6; // eax@2
  int result; // eax@10

  v5 = this;
  if ( RGE_Base_Game::get_paused(rge_base_game)
    || (v6 = rge_base_game->prog_mode, v6 != 4) && v6 != 6 && v6 != 7 && v6 != 5 )
  {
    result = 0;
  }
  else
  {
    if ( rge_base_game->prog_info->interface_style == 2 )
    {
      if ( v6 == 4 || v6 == 6 || v6 == 7 )
      {
        TPanel::capture_mouse((TPanel *)&v5->vfptr);
        return 1;
      }
    }
    else
    {
      RGE_Diamond_Map::start_scroll_view((RGE_Diamond_Map *)&v5->vfptr, x, y);
    }
    result = 1;
  }
  return result;
}

//----- (0053D6A0) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::mouse_right_move_action(RGE_Diamond_Map_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Diamond_Map_View *v5; // esi@1
  int v6; // eax@1
  bool v7; // zf@5
  int v8; // eax@5
  int result; // eax@7

  v5 = this;
  v6 = rge_base_game->prog_mode;
  if ( v6 != 4 && v6 != 6 && v6 != 7 && v6 != 5 )
    return 0;
  v7 = RGE_Base_Game::get_paused(rge_base_game) == 0;
  v8 = v5->scrolling;
  if ( v7 )
  {
    if ( v8 )
    {
      RGE_Diamond_Map::handle_scroll_view((RGE_Diamond_Map *)&v5->vfptr, x, y);
      return 1;
    }
    return 0;
  }
  if ( v8 )
  {
    RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)&v5->vfptr);
    result = 0;
  }
  else
  {
    TPanel::release_mouse((TPanel *)&v5->vfptr);
    result = 0;
  }
  return result;
}

//----- (0053D720) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::mouse_right_up_action(RGE_Diamond_Map_View *this, int x, int y, int ctrl_key, int shift_key)
{
  RGE_Diamond_Map_View *v5; // esi@1
  int v6; // eax@1
  char v8; // al@8
  RGE_PlayerVtbl **v9; // ecx@17
  RGE_PlayerVtbl *v10; // edx@17
  float v11; // ST0C_4@17
  float v12; // ST08_4@17
  RGE_Tile *tile; // [sp+10h] [bp-4h]@16

  v5 = this;
  v6 = rge_base_game->prog_mode;
  if ( v6 != 4 && v6 != 6 && v6 != 7 && v6 != 5 )
    return 0;
  if ( this->scrolling )
  {
    RGE_Diamond_Map::end_scroll_view((RGE_Diamond_Map *)&this->vfptr);
    return 1;
  }
  TPanel::release_mouse((TPanel *)&this->vfptr);
  if ( RGE_Base_Game::get_paused(rge_base_game) )
    return 0;
  v8 = v5->mouse_action;
  if ( v8 != 1 && v8 != 2 )
    return 0;
  if ( rge_base_game->prog_info->interface_style != 2 )
  {
    if ( rge_base_game->prog_mode != 7 )
    {
      if ( rge_base_game->game_mode )
      {
        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
        return 0;
      }
      RGE_Player::unselect_object(v5->player);
    }
    return 0;
  }
  if ( rge_base_game->game_mode || rge_base_game->prog_mode == 5 )
    return 0;
  if ( !shift_key )
  {
    if ( (*(int (__thiscall **)(RGE_Diamond_Map_View *, int, int))&v5->vfptr[1].gap10[4])(v5, x, y) )
      return 1;
    return 0;
  }
  if ( RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&v5->vfptr, x, y, (__int16 *)&x, (__int16 *)&y, &tile) )
  {
    v9 = &v5->player->vfptr;
    shift_key = (signed __int16)y;
    v10 = *v9;
    shift_key = (signed __int16)x;
    v11 = (double)(signed __int16)y - -0.5;
    v12 = (double)(signed __int16)x - -0.5;
    ((void (__stdcall *)(_DWORD, _DWORD, signed int))v10->command_add_waypoint)(LODWORD(v12), LODWORD(v11), 1065353216);
  }
  return 1;
}

//----- (0053D890) --------------------------------------------------------
void __thiscall RGE_Diamond_Map_View::draw(RGE_Diamond_Map_View *this)
{
  RGE_Diamond_Map_View *v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int v3; // eax@1

  v1 = this;
  v2 = debug_timeGetTime();
  RGE_Diamond_Map::draw((RGE_Diamond_Map *)&v1->vfptr);
  v3 = debug_timeGetTime();
  RGE_Base_Game::add_to_timing(rge_base_game, 7, v3 - v2);
}

//----- (0053D8E0) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::command_make_do(RGE_Diamond_Map_View *this, int x, int y)
{
  RGE_Diamond_Map_View *v3; // esi@1
  int result; // eax@2
  int v5; // edi@3
  float v6; // ST10_4@4
  float v7; // ST0C_4@4
  RGE_Tile *tile; // [sp+14h] [bp-4h]@3

  v3 = this;
  if ( allow_user_commands )
  {
    v5 = 0;
    if ( RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&this->vfptr, x, y, (__int16 *)&x, (__int16 *)&y, &tile) )
    {
      v6 = (double)(signed __int16)y - -0.5;
      v7 = (double)(signed __int16)x - -0.5;
      v5 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v3->player->vfptr->command_make_do)(0, LODWORD(v7), LODWORD(v6)) & 0xFF;
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0053D970) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::command_make_move(RGE_Diamond_Map_View *this, int x, int y)
{
  RGE_Diamond_Map_View *v3; // edi@1
  int result; // eax@2
  int v5; // esi@3
  float v6; // ST10_4@4
  float v7; // ST0C_4@4
  RGE_Tile *tile; // [sp+14h] [bp-4h]@3

  v3 = this;
  if ( allow_user_commands )
  {
    v5 = 0;
    if ( RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&this->vfptr, x, y, (__int16 *)&x, (__int16 *)&y, &tile) )
    {
      v6 = (double)(signed __int16)y - -0.5;
      v7 = (double)(signed __int16)x - -0.5;
      v5 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v3->player->vfptr->command_make_move)(
             0,
             LODWORD(v7),
             LODWORD(v6)) & 0xFF;
    }
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0053DA10) --------------------------------------------------------
int __thiscall RGE_Diamond_Map_View::command_make_work(RGE_Diamond_Map_View *this, int x, int y)
{
  RGE_Diamond_Map_View *v3; // edi@1
  int result; // eax@2
  int v5; // esi@3
  float v6; // ST10_4@4
  float v7; // ST0C_4@4
  RGE_Tile *tile; // [sp+14h] [bp-4h]@3

  v3 = this;
  if ( allow_user_commands )
  {
    v5 = 0;
    if ( RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&this->vfptr, x, y, (__int16 *)&x, (__int16 *)&y, &tile) )
    {
      v6 = (double)(signed __int16)y - -0.5;
      v7 = (double)(signed __int16)x - -0.5;
      v5 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v3->player->vfptr->command_make_work)(
             0,
             LODWORD(v7),
             LODWORD(v6)) & 0xFF;
    }
    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 58631C: using guessed type int allow_user_commands;
