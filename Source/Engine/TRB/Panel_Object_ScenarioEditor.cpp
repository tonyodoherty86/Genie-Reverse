
//----- (004BEDC0) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object(TRIBE_Scenario_Editor_Panel_Object *this, TDrawArea *render_area_in, TPanel *parent_panel_in, void *font_in, int font_wid_in, int font_hgt_in, TShape *unit_pics_in, TShape **bldg_pics_in, TRIBE_Player *player_in)
{
  TRIBE_Scenario_Editor_Panel_Object *v9; // esi@1

  v9 = this;
  TRIBE_Panel_Object::TRIBE_Panel_Object(
    (TRIBE_Panel_Object *)&this->vfptr,
    render_area_in,
    parent_panel_in,
    font_in,
    font_wid_in,
    font_hgt_in,
    unit_pics_in,
    bldg_pics_in,
    player_in);
  v9->vfptr = (TPanelVtbl *)&TRIBE_Scenario_Editor_Panel_Object::`vftable';
  v9->master_game_obj = 0;
  v9->master_culture_id = 0;
}
// 574440: using guessed type int (__thiscall *TRIBE_Scenario_Editor_Panel_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004BEE10) --------------------------------------------------------
TRIBE_Scenario_Editor_Panel_Object *__thiscall TRIBE_Scenario_Editor_Panel_Object::`vector deleting destructor'(TRIBE_Scenario_Editor_Panel_Object *this, unsigned int __flags)
{
  TRIBE_Scenario_Editor_Panel_Object *v2; // esi@1

  v2 = this;
  TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004BEE30) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object(TRIBE_Scenario_Editor_Panel_Object *this)
{
  this->vfptr = (TPanelVtbl *)&TRIBE_Scenario_Editor_Panel_Object::`vftable';
  TRIBE_Panel_Object::~TRIBE_Panel_Object((TRIBE_Panel_Object *)&this->vfptr);
}
// 574440: using guessed type int (__thiscall *TRIBE_Scenario_Editor_Panel_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004BEE40) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Editor_Panel_Object::set_master_info(TRIBE_Scenario_Editor_Panel_Object *this, RGE_Master_Static_Object *master_game_object_in, TRIBE_Player *master_player_in)
{
  this->master_game_obj = master_game_object_in;
  this->player = master_player_in;
  if ( master_player_in )
    this->master_culture_id = master_player_in->culture;
  else
    this->master_culture_id = 0;
}

//----- (004BEE70) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Editor_Panel_Object::draw(TRIBE_Scenario_Editor_Panel_Object *this)
{
  TRIBE_Scenario_Editor_Panel_Object *v1; // ebp@1
  TPanel *v2; // ecx@7
  TPanelVtbl *v3; // ebx@9
  RGE_Master_Static_Object *v4; // eax@10
  __int16 v5; // si@10
  TShape *v6; // edi@12
  TRIBE_Player *v7; // eax@14
  RGE_Color_Table *v8; // eax@15
  RGE_Sprite *v9; // eax@18
  TRIBE_Player *v10; // eax@23
  __int16 v11; // ax@27
  RGE_Master_Static_Object *v12; // edx@36
  signed int v13; // esi@36
  char v14; // al@36
  signed __int16 v15; // di@43
  signed int v16; // ecx@43
  float *v17; // esi@43
  signed int v18; // esi@49
  signed __int64 v19; // rax@53
  void *(__thiscall *v20)(TPanel *, unsigned int); // esi@55
  signed __int64 v21; // rax@55
  RGE_Master_Static_Object *v22; // eax@59
  __int16 v23; // cx@59
  char v24; // al@59
  __int16 v25; // ax@62
  __int16 v26; // di@62
  char v27; // cl@62
  RGE_Master_Static_Object *v28; // eax@65
  char v29; // cl@65
  int text_flag; // [sp+18h] [bp-E4h]@0
  TPanelVtbl *v31; // [sp+1Ch] [bp-E0h]@9
  HGDIOBJ old_font; // [sp+20h] [bp-DCh]@23
  int min_x; // [sp+24h] [bp-D8h]@19
  int min_y; // [sp+28h] [bp-D4h]@19
  int max_y; // [sp+2Ch] [bp-D0h]@19
  int max_x; // [sp+30h] [bp-CCh]@19
  char name[100]; // [sp+34h] [bp-C8h]@24
  char str[100]; // [sp+98h] [bp-64h]@28

  v1 = this;
  if ( !this->render_area || !this->visible || !this->active )
  {
LABEL_69:
    v1->need_redraw = 0;
    return;
  }
  if ( this->mode == 2 )
  {
    TRIBE_Panel_Object::draw_score((TRIBE_Panel_Object *)&this->vfptr);
    return;
  }
  if ( !this->master_game_obj )
  {
    v2 = this->parent_panel;
    if ( v2 )
    {
      ((void (__stdcall *)(int))v2->vfptr->draw_rect)((int)&v1->clip_rect);
      v1->need_redraw = 0;
      return;
    }
    goto LABEL_69;
  }
  v3 = this->vfptr;
  v31 = this->vfptr;
  ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
  TDrawArea::Clear(v1->render_area, &v1->clip_rect, 0);
  if ( TDrawArea::Lock(v1->render_area, 0, 1) )
  {
    v4 = v1->master_game_obj;
    text_flag = 1;
    v5 = v4->button_pict;
    if ( v5 == -1 )
    {
      v9 = v4->sprite;
      if ( v9 )
      {
        text_flag = 0;
        if ( RGE_Sprite::get_size(v9, &min_x, &min_y, &max_x, &max_y, 0) )
          RGE_Sprite::do_draw(
            v1->master_game_obj->sprite,
            0,
            0,
            v1->pnl_x - min_x + 10,
            v1->pnl_y - min_y + 40,
            v1->player->color_table,
            v1->render_area,
            0);
      }
    }
    else
    {
      if ( v4->unit_level == 2 )
      {
        v6 = v1->bldg_pics[v1->master_culture_id];
        v5 += HIWORD(v4[1].outline_radius_z);
      }
      else
      {
        v6 = v1->unit_pics;
      }
      v7 = v1->player;
      if ( v7 && (v8 = v7->color_table, v8 != (RGE_Color_Table *)-40) )
      {
        ASMSet_Color_Xform(16 * (v8->id + 1));
        TShape::shape_draw(v6, v1->render_area, v1->pnl_x + 2, v1->pnl_y + 33, v5, 1, v1->player->color_table->table);
      }
      else
      {
        TShape::shape_draw(v6, v1->render_area, v1->pnl_x + 2, v1->pnl_y + 33, v5, 0, 0);
      }
    }
    TDrawArea::Unlock(v1->render_area, 0);
  }
  if ( TDrawArea::GetDc(v1->render_area, 0) )
  {
    SetBkMode(v1->render_area->DrawDc, 1);
    SetTextColor(v1->render_area->DrawDc, 0xFFFFFFu);
    SelectClipRgn(v1->render_area->DrawDc, v1->clip_rgn);
    old_font = SelectObject(v1->render_area->DrawDc, v1->font);
    v10 = v1->player;
    if ( v10 )
    {
      (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
        105,
        v10->id,
        0,
        name,
        100);
      if ( !strcmp(name, aUnknown) )
        strcpy(name, aGaia_1);
      TextOutA(v1->render_area->DrawDc, v1->pnl_x + 2, v1->pnl_y, name, strlen(name));
    }
    v11 = v1->master_game_obj->string_id;
    if ( v11 <= 0 )
      str[0] = 0;
    else
      (*(void (__stdcall **)(_DWORD, char *, signed int))&rge_base_game->vfptr->gap8[24])(v11, str, 100);
    if ( !str[0] )
      strcpy(str, v1->master_game_obj->name);
    sprintf(name, aS_2, str);
    TextOutA(v1->render_area->DrawDc, v1->pnl_x + 2, v1->pnl_y + 15, name, strlen(name));
    if ( text_flag )
    {
      sprintf(str, aDD, v1->master_game_obj->hp, v1->master_game_obj->hp);
      TextOutA(v1->render_area->DrawDc, v1->pnl_x + 5, v1->pnl_y + 85, str, strlen(str));
      SelectObject(v1->render_area->DrawDc, old_font);
      SelectClipRgn(v1->render_area->DrawDc, 0);
    }
    TDrawArea::ReleaseDc(v1->render_area, 0);
    v3 = v31;
  }
  if ( !text_flag )
  {
LABEL_68:
    v3->draw_finish((TPanel *)v1);
    return;
  }
  v12 = v1->master_game_obj;
  v13 = 0;
  v14 = v12->unit_level;
  if ( v14 == 3 )
  {
LABEL_58:
    ((void (__thiscall *)(TRIBE_Scenario_Editor_Panel_Object *, _DWORD, signed int, signed int, _DWORD, _DWORD))v3[1].__vecDelDtor)(
      v1,
      0,
      7,
      1,
      HIWORD(v12[1].multiple_attribute_mod),
      HIWORD(v12[1].multiple_attribute_mod));
    v13 = 1;
LABEL_59:
    v22 = v1->master_game_obj;
    v23 = LOWORD(v22[1].multiple_attribute_mod);
    v24 = v22->unit_level;
    if ( v24 == 4 || v24 == 6 )
      ((void (__thiscall *)(TRIBE_Scenario_Editor_Panel_Object *, signed int, signed int, signed int, _DWORD, _DWORD))v3[1].__vecDelDtor)(
        v1,
        v13++,
        8,
        1,
        v23,
        v23);
    v25 = TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor(v1);
    v26 = v25;
    v27 = v1->master_game_obj->unit_level;
    if ( v27 == 4 || v27 == 6 )
      ((void (__thiscall *)(TRIBE_Scenario_Editor_Panel_Object *, signed int, signed int, signed int, _DWORD, _DWORD))v3[1].__vecDelDtor)(
        v1,
        v13++,
        10,
        1,
        v25,
        v25);
    v28 = v1->master_game_obj;
    v29 = v28->unit_level;
    if ( v29 == 4 || v29 == 6 )
      ((void (__thiscall *)(TRIBE_Scenario_Editor_Panel_Object *, signed int, signed int, signed int, _DWORD, _DWORD))v3[1].__vecDelDtor)(
        v1,
        v13,
        6,
        1,
        (signed __int16)(signed __int64)*(float *)&v28[1].attribute_flag[0],
        v26);
    goto LABEL_68;
  }
  if ( v14 == 9 || v14 == 4 || v14 == 5 || v14 == 6 || v14 == 7 )
  {
    if ( v14 != 3 && v14 != 4 )
      goto LABEL_59;
    goto LABEL_58;
  }
  if ( v14 != 1 )
  {
    if ( v14 == 2 )
    {
      v20 = v3[1].__vecDelDtor;
      ((void (__thiscall *)(TRIBE_Scenario_Editor_Panel_Object *, _DWORD, signed int, signed int, _DWORD, _DWORD))v20)(
        v1,
        0,
        7,
        1,
        HIWORD(v12[1].multiple_attribute_mod),
        HIWORD(v12[1].multiple_attribute_mod));
      ((void (__thiscall *)(TRIBE_Scenario_Editor_Panel_Object *, signed int, signed int, signed int, _DWORD, _DWORD))v20)(
        v1,
        1,
        8,
        1,
        LOWORD(v1->master_game_obj[1].multiple_attribute_mod),
        LOWORD(v1->master_game_obj[1].multiple_attribute_mod));
      v21 = (signed __int64)v1->master_game_obj[1].construction_radius_x;
      ((void (__fastcall *)(TRIBE_Scenario_Editor_Panel_Object *, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD))v20)(
        v1,
        HIDWORD(v21),
        2,
        6,
        1,
        v21,
        v21);
      v3->draw_finish((TPanel *)v1);
      return;
    }
    goto LABEL_68;
  }
  v15 = -1;
  v16 = 0;
  v17 = v12->attribute_amount_held;
  while ( *v17 <= 0.0 )
  {
    ++v16;
    ++v17;
    if ( v16 >= 3 )
      goto LABEL_48;
  }
  v15 = v12->attribute_type_held[v16];
LABEL_48:
  switch ( v15 )
  {
    case 0:
    case 15:
    case 16:
    case 17:
      v18 = 2;
      break;
    case 1:
      v18 = 0;
      break;
    case 2:
      v18 = 1;
      break;
    case 3:
      v18 = 3;
      break;
    default:
      goto LABEL_68;
  }
  v19 = (signed __int64)v12->attribute_amount_held[v16];
  ((void (__fastcall *)(TRIBE_Scenario_Editor_Panel_Object *, _DWORD, _DWORD, signed int, _DWORD, _DWORD, _DWORD))v3[1].__vecDelDtor)(
    v1,
    HIDWORD(v19),
    0,
    v18,
    0,
    v19,
    0);
  v3->draw_finish((TPanel *)v1);
}

//----- (004BF4D0) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Editor_Panel_Object::draw_item(TRIBE_Scenario_Editor_Panel_Object *this, int row, int pic_index, TRIBE_Panel_Object::ValueType val_type, int val1, int val2)
{
  TRIBE_Scenario_Editor_Panel_Object *v6; // esi@1
  char val_str[20]; // [sp+10h] [bp-14h]@6
  HGDIOBJ val1a; // [sp+34h] [bp+10h]@15

  v6 = this;
  if ( this->item_pic && pic_index != -1 && TDrawArea::Lock(this->render_area, 0, 1) )
  {
    TShape::shape_draw(v6->item_pic, v6->render_area, v6->pnl_x + 60, v6->pnl_y + 18 * row + 30, pic_index, 0, 0);
    TDrawArea::Unlock(v6->render_area, 0);
  }
  switch ( val_type )
  {
    case 0:
      sprintf(val_str, aD_3, val1);
      break;
    case 1:
      if ( val2 <= val1 )
        sprintf(val_str, aD_3, val1);
      else
        sprintf(val_str, aDD_3, val1, val2 - val1);
      break;
    case 2:
      sprintf(val_str, aDD, val1, val2);
      break;
    case 3:
      sprintf(val_str, aD_2, val1);
      break;
    default:
      val_str[0] = 0;
      break;
  }
  if ( val_str[0] )
  {
    if ( TDrawArea::GetDc(v6->render_area, 0) )
    {
      SetBkMode(v6->render_area->DrawDc, 1);
      SetTextColor(v6->render_area->DrawDc, 0xFFFFFFu);
      SelectClipRgn(v6->render_area->DrawDc, v6->clip_rgn);
      val1a = SelectObject(v6->render_area->DrawDc, v6->font);
      TextOutA(v6->render_area->DrawDc, v6->pnl_x + 100, v6->pnl_y + 18 * row + 32, val_str, strlen(val_str));
      SelectObject(v6->render_area->DrawDc, val1a);
      SelectClipRgn(v6->render_area->DrawDc, 0);
      TDrawArea::ReleaseDc(v6->render_area, 0);
    }
  }
}

//----- (004BF6C0) --------------------------------------------------------
int __thiscall TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action(TRIBE_Scenario_Editor_Panel_Object *this, int x, int y, int ctrl_key, int shift_key)
{
  int v5; // et1@1

  TPanel::release_mouse((TPanel *)&this->vfptr);
  v5 = rge_base_game->prog_mode;
  return 1;
}

//----- (004BF6E0) --------------------------------------------------------
int __thiscall TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor(TRIBE_Scenario_Editor_Panel_Object *this)
{
  RGE_Master_Static_Object *v1; // ecx@1
  int result; // eax@2
  int v3; // edx@5
  int v4; // ecx@6

  v1 = this->master_game_obj;
  if ( v1 )
  {
    if ( v1->master_type == 70 )
    {
      v3 = *(_WORD *)&v1[1].sort_number;
      result = 0;
      if ( v3 > 0 )
      {
        v4 = *(_DWORD *)&v1[1].button_pict;
        do
        {
          if ( *(_WORD *)v4 == 3 )
            result = *(_WORD *)(v4 + 2);
          v4 += 4;
          --v3;
        }
        while ( v3 );
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
