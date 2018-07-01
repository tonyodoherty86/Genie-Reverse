
//----- (00436830) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::RGE_Diamond_Map(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->world = 0;
  v1->player = 0;
  v1->map = 0;
  v1->repos_mouse = 0;
  v1->last_player = 0;
  v1->map_image_start_y = 0;
  v1->map_image_lines = 0;
  v1->map_tile_rows = 0;
  v1->map_image_wid = 0;
  v1->map_image_hgt = 0;
  v1->map_tile_row_cnt = 0;
  LODWORD(v1->map_row_step) = 0;
  v1->map_tile_draw_hgt = 0;
  v1->map_tile_draw_wid = 0;
  LODWORD(v1->map_col_ratio) = 0;
  LODWORD(v1->map_row_ratio) = 0;
  v1->save_area = 0;
  v1->own_save_area = 0;
  v1->view_rect.left = 0;
  v1->view_rect.top = 0;
  v1->view_rect.right = 0;
  v1->view_rect.bottom = 0;
  v1->main_view = 0;
  v1->scrolling = 0;
  v1->draw_objects_mode = 0;
  v1->cur_player_bit = 0;
  v1->vfptr = (TPanelVtbl *)&RGE_Diamond_Map::`vftable';
  v1->view_col = -1;
  v1->view_row = -1;
  v1->render_all = 1;
  v1->fog_color = -1;
}
// 56F508: using guessed type int (__thiscall *RGE_Diamond_Map::`vftable')(void *Memory, unsigned int __flags);

//----- (00436910) --------------------------------------------------------
RGE_Diamond_Map *__thiscall RGE_Diamond_Map::`vector deleting destructor'(RGE_Diamond_Map *this, unsigned int __flags)
{
  RGE_Diamond_Map *v2; // esi@1

  v2 = this;
  RGE_Diamond_Map::~RGE_Diamond_Map(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004369C0) --------------------------------------------------------
int __thiscall RGE_Diamond_Map::setup(RGE_Diamond_Map *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, int color_in, int all_visible_in, TDrawArea *save_area_in)
{
  this->save_area = save_area_in;
  this->own_save_area = 0;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, color_in);
  return 1;
}

//----- (00436A10) --------------------------------------------------------
int __thiscall RGE_Diamond_Map::set_bitmap(RGE_Diamond_Map *this, char *map_bmp, int res_id)
{
  RGE_Diamond_Map *v3; // esi@1
  TPicture *v4; // eax@5
  TPicture *v5; // eax@6
  TPicture *v6; // ebp@6
  int result; // eax@9
  signed __int16 v8; // bx@12
  size_t v9; // edi@12
  int v10; // ebp@13
  int v11; // eax@13
  int v12; // eax@14
  int v13; // eax@14
  signed __int16 v14; // ax@16
  int v15; // ecx@16
  _BYTE *v16; // edx@16
  __int16 i; // di@22
  __int16 pic_pitch; // [sp+10h] [bp-14h]@15
  signed __int16 pic_hgt; // [sp+14h] [bp-10h]@12
  char *map_bmpa; // [sp+28h] [bp+4h]@15
  TPicture *y; // [sp+2Ch] [bp+8h]@6

  v3 = this;
  if ( this->map_image_lines )
  {
    free(this->map_image_lines);
    v3->map_image_lines = 0;
  }
  if ( v3->map_tile_rows )
  {
    free(v3->map_tile_rows);
    v3->map_tile_rows = 0;
  }
  v4 = (TPicture *)operator new(0x20u);
  if ( v4 )
  {
    TPicture::TPicture(v4, map_bmp, res_id, 0, 0, 0);
    v6 = v5;
    y = v5;
  }
  else
  {
    y = 0;
    v6 = 0;
  }
  if ( v6 )
  {
    if ( v6->Dib )
    {
      v8 = v6->Width;
      v9 = LOWORD(v6->Height);
      pic_hgt = v6->Height;
      v3->map_image_lines = (RGE_Map_Image_Line *)calloc(v9, 6u);
      if ( v6->Orien == 1 )
      {
        v10 = (int)v6->Bits;
        LOBYTE(v11) = TPicture::AlignedWidth(y);
      }
      else
      {
        LOBYTE(v12) = TPicture::AlignedWidth(v6);
        v10 = (int)&y->Bits[(v9 - 1) * v12];
        LOBYTE(v13) = TPicture::AlignedWidth(y);
        v11 = -v13;
      }
      pic_pitch = v11;
      v3->map_image_start_y = -1;
      v3->map_image_wid = 0;
      v3->map_image_hgt = 0;
      map_bmpa = 0;
      if ( pic_hgt > 0 )
      {
        do
        {
          v14 = -1;
          v15 = 0;
          v16 = (_BYTE *)v10;
          if ( v8 > 0 )
          {
            while ( *v16 != -1 )
            {
              ++v16;
              if ( (signed __int16)++v15 >= v8 )
                goto LABEL_21;
            }
            v14 = v15;
          }
LABEL_21:
          if ( v14 != -1 )
          {
            for ( i = 0; (signed __int16)v15 < v8; ++v15 )
            {
              if ( *v16 != -1 )
                break;
              ++i;
              ++v16;
            }
            v3->map_image_lines[v3->map_image_hgt].start_x = v14;
            v3->map_image_lines[v3->map_image_hgt++].line_len = i;
            if ( i > v3->map_image_wid )
              v3->map_image_wid = i;
            if ( v3->map_image_start_y == -1 )
              v3->map_image_start_y = (signed __int16)map_bmpa;
          }
          v10 += pic_pitch;
          ++map_bmpa;
        }
        while ( (signed __int16)map_bmpa < pic_hgt );
      }
      TPicture::~TPicture(y);
      operator delete(y);
      if ( v3->world )
        RGE_Diamond_Map::set_world(v3, v3->world);
      result = 1;
    }
    else
    {
      TPicture::~TPicture(v6);
      operator delete(v6);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00436C30) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::set_world(RGE_Diamond_Map *this, RGE_Game_World *world_in)
{
  RGE_Diamond_Map *v2; // esi@1
  __int16 v3; // di@1
  RGE_Map *v4; // eax@3
  RGE_Map *v5; // ecx@3
  __int16 v6; // dx@3
  __int16 v7; // dx@3
  RGE_Map_Tile_Row *v8; // eax@3
  RGE_Map_Tile_Row *v9; // eax@5
  __int16 v10; // cx@5
  __int16 v11; // ax@5
  double v12; // st7@5
  double v13; // st7@7
  double v14; // st6@8
  RGE_Map_Image_Line *v15; // ecx@9
  __int16 v16; // di@9
  int v17; // ebp@9
  signed __int64 v18; // rax@9
  int v19; // ebx@12
  double v20; // st4@15
  double v21; // st3@15
  double v22; // st5@15
  int v23; // ecx@15
  double v24; // rt1@15
  double v25; // st2@15
  double v26; // st5@15
  double v27; // rtt@15
  double v28; // st2@15
  double v29; // st3@15
  double v31; // rt0@15
  double v32; // st2@15
  double v33; // st4@15
  char v34; // c3@15
  int v35; // edi@17
  int v36; // ecx@17
  double v37; // st5@18
  signed __int16 v38; // ax@20
  bool v39; // sf@23
  unsigned __int8 v40; // of@23
  double v41; // st6@25
  __int16 v42; // cx@25
  __int16 v43; // ax@27
  __int16 v44; // ax@29
  __int16 v45; // bx@29
  double v46; // st6@29
  RGE_Map_Tile_Row *v47; // edx@30
  int v48; // ecx@30
  int v49; // eax@32
  TPanelVtbl *v50; // edx@34
  signed __int16 tot_draw_wid; // [sp+10h] [bp-10h]@7
  float tile_row; // [sp+14h] [bp-Ch]@5
  float tile_rowa; // [sp+14h] [bp-Ch]@15
  float col_step; // [sp+1Ch] [bp-4h]@15
  RGE_Game_World *world_ina; // [sp+24h] [bp+4h]@7
  RGE_Game_World *world_inb; // [sp+24h] [bp+4h]@27

  v2 = this;
  v3 = 0;
  this->world = world_in;
  if ( world_in && this->map_image_lines )
  {
    v4 = world_in->map;
    this->map = v4;
    v5 = this->map;
    v2->map_wid = v4->map_width;
    LOWORD(v4) = v5->map_height;
    v6 = v2->map_wid;
    v2->map_hgt = (signed __int16)v4;
    v7 = (_WORD)v4 + v6;
    v8 = v2->map_tile_rows;
    v2->map_tile_row_cnt = v7 - 1;
    if ( v8 )
      free(v8);
    v9 = (RGE_Map_Tile_Row *)calloc(v2->map_tile_row_cnt, 0x24u);
    v10 = v2->map_tile_row_cnt;
    v2->map_tile_rows = v9;
    v11 = v2->map_image_hgt;
    tile_row = 0.0;
    v12 = (double)v10 / (double)v11;
    v2->map_row_step = v12;
    if ( v10 > v11 )
      tile_row = v12 * 0.5;
    v13 = 0.0;
    tot_draw_wid = 0;
    world_ina = 0;
    if ( v11 > 0 )
    {
      v14 = tile_row;
      do
      {
        v15 = v2->map_image_lines;
        v16 = v15[(signed __int16)world_ina].line_len;
        v18 = (signed __int64)v14;
        v17 = (signed __int64)v14;
        LOWORD(v18) = v2->map_tile_row_cnt;
        if ( (signed __int16)v17 >= (signed __int16)v18 )
          LOWORD(v17) = v18 - 1;
        v15[(signed __int16)world_ina].tile_row = v17;
        LOWORD(v18) = v2->map_wid;
        if ( (signed __int16)v17 >= (signed __int16)v18 )
        {
          WORD2(v18) = v2->map_hgt - v17;
          v19 = HIDWORD(v18) + v18 - 1;
        }
        else
        {
          LOWORD(v19) = v2->map_hgt;
          if ( (signed __int16)v17 < (signed __int16)v19 )
            LOWORD(v19) = v17 + 1;
        }
        v20 = (double)(signed __int16)v19;
        v21 = (double)v16;
        col_step = v20 / v21;
        v22 = v20 / v21;
        v23 = (signed __int64)(1.0 / v22);
        LODWORD(tile_rowa) = (signed __int64)(1.0 / v22);
        v24 = 1.0 / v22;
        v25 = v22;
        v26 = v20;
        v27 = v25;
        v28 = v21;
        v29 = v27;
        v31 = v28;
        v32 = v24;
        v33 = v31;
        if ( !v34 )
        {
          LOWORD(v23) = v23 + 1;
          LOWORD(tile_rowa) = v23;
        }
        v35 = (signed __int16)v17;
        v2->map_tile_rows[v35].image_line = (signed __int16)world_ina;
        v2->map_tile_rows[v35].draw = 1;
        v2->map_tile_rows[v35].row_len = v19;
        v2->map_tile_rows[v35].col_step = v29;
        v2->map_tile_rows[v35].draw_wid = v23;
        v2->map_tile_rows[v35].draw_step = v32;
        v2->map_tile_rows[v35].num_tiles = (signed __int64)(v33 / v32);
        v2->map_tile_rows[v35].ratio = v33 / v26;
        v36 = (int)&v2->map_tile_rows[v35].image_line;
        if ( *(float *)(v36 + 32) >= 1.0 )
          v37 = 0.0;
        else
          v37 = col_step * 0.5;
        *(float *)(v36 + 12) = v37;
        v38 = v2->map_wid;
        if ( (signed __int16)v17 >= v38 )
        {
          v2->map_tile_rows[v35].map_row = v17 - v38 + 1;
          v2->map_tile_rows[v35].map_col = 0;
        }
        else
        {
          v2->map_tile_rows[v35].map_row = 0;
          v2->map_tile_rows[v35].map_col = v2->map_wid - v17 - 1;
        }
        v13 = v13 + v2->map_tile_rows[v35].ratio;
        tot_draw_wid += LOWORD(tile_rowa);
        v40 = __OFSUB__((_WORD)world_ina + 1, v2->map_image_hgt);
        v39 = (signed __int16)((_WORD)world_ina + 1 - v2->map_image_hgt) < 0;
        world_ina = (RGE_Game_World *)((char *)world_ina + 1);
        v14 = v14 + v2->map_row_step;
      }
      while ( v39 ^ v40 );
      v3 = 0;
    }
    v41 = 1.0 / v2->map_row_step;
    v42 = (signed __int64)v41;
    v2->map_tile_draw_hgt = v42;
    if ( (double)v42 != v41 )
      v2->map_tile_draw_hgt = v42 + 1;
    v43 = tot_draw_wid / v2->map_image_hgt;
    world_inb = (RGE_Game_World *)v2->map_image_hgt;
    v2->map_tile_draw_wid = v43;
    if ( v43 == v3 )
      v2->map_tile_draw_wid = 1;
    v44 = v2->map_tile_row_cnt;
    v45 = 0;
    v46 = (double)(signed int)world_inb;
    v2->map_col_ratio = v13 / v46;
    v2->map_row_ratio = v46 / (double)v44;
    if ( v44 > v3 )
    {
      do
      {
        v47 = v2->map_tile_rows;
        v48 = v45;
        if ( v47[v48].draw )
        {
          v3 = v45;
        }
        else
        {
          v49 = v3;
          v47[v48].image_line = v47[v49].image_line;
          v2->map_tile_rows[v48].row_len = v2->map_tile_rows[v49].row_len;
          v2->map_tile_rows[v48].col_step = v2->map_tile_rows[v49].col_step;
          v2->map_tile_rows[v48].draw_wid = v2->map_tile_rows[v49].draw_wid;
          v2->map_tile_rows[v48].draw_step = v2->map_tile_rows[v49].draw_step;
          v2->map_tile_rows[v48].num_tiles = v2->map_tile_rows[v49].num_tiles;
          v2->map_tile_rows[v48].ratio = v2->map_tile_rows[v49].ratio;
          v2->map_tile_rows[v48].col_extra = v2->map_tile_rows[v49].col_extra;
        }
        ++v45;
      }
      while ( v45 < v2->map_tile_row_cnt );
    }
    v50 = v2->vfptr;
    v2->view_col = -1;
    v2->view_row = -1;
    v50->set_redraw((TPanel *)v2, RedrawFull);
  }
  else
  {
    this->map = 0;
  }
}

//----- (00437070) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::set_player(RGE_Diamond_Map *this, RGE_Player *player_in)
{
  TPanelVtbl *v2; // edx@1

  v2 = this->vfptr;
  this->player = player_in;
  ((void (__stdcall *)(signed int))v2->set_redraw)(2);
}

//----- (00437090) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::set_redraw(RGE_Diamond_Map *this, TPanel::RedrawMode redraw_mode)
{
  RGE_Diamond_Map *v2; // esi@1

  v2 = this;
  TPanel::set_redraw((TPanel *)&this->vfptr, redraw_mode);
  if ( redraw_mode == 2 )
    v2->render_all = 1;
}

//----- (004370C0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::delete_surfaces(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1
  TDrawArea *v2; // edi@1

  v1 = this;
  v2 = this->save_area;
  if ( v2 && this->own_save_area )
  {
    if ( v2 )
    {
      TDrawArea::~TDrawArea(this->save_area);
      operator delete(v2);
    }
    v1->save_area = 0;
    v1->own_save_area = 0;
  }
}

//----- (00437110) --------------------------------------------------------
int __stdcall TPanel::mouse_move_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437120) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::create_surfaces(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1
  TDrawArea *v2; // ecx@1
  TDrawArea *v3; // eax@2
  TDrawArea *v4; // eax@3
  TDrawArea *v5; // edi@7

  v1 = this;
  v2 = this->save_area;
  if ( v2 )
  {
    if ( v1->own_save_area )
      TDrawArea::SetSize(v2, v1->pnl_wid, v1->pnl_hgt, 0);
  }
  else
  {
    v3 = (TDrawArea *)operator new(0x100u);
    if ( v3 )
      TDrawArea::TDrawArea(v3, aDiamondMapRest, 0);
    else
      v4 = 0;
    v1->save_area = v4;
    if ( v4 )
    {
      if ( TDrawArea::Init(v4, v1->render_area->DrawSystem, v1->pnl_wid, v1->pnl_hgt, 0, 0) )
      {
        v1->own_save_area = 1;
      }
      else
      {
        v5 = v1->save_area;
        if ( v5 )
        {
          TDrawArea::~TDrawArea(v1->save_area);
          operator delete(v5);
        }
        v1->save_area = 0;
      }
    }
  }
}

//----- (00437230) --------------------------------------------------------
int __stdcall TPanel::mouse_left_down_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437240) --------------------------------------------------------
int __stdcall TPanel::mouse_left_hold_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437250) --------------------------------------------------------
int __stdcall TPanel::mouse_left_move_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437260) --------------------------------------------------------
int __stdcall TPanel::mouse_left_up_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437270) --------------------------------------------------------
int __stdcall TPanel::mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437280) --------------------------------------------------------
int __stdcall TPanel::mouse_right_down_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00437290) --------------------------------------------------------
int __stdcall TPanel::mouse_right_hold_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004372A0) --------------------------------------------------------
int __stdcall TPanel::mouse_right_move_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004372B0) --------------------------------------------------------
int __stdcall TPanel::mouse_right_up_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004372C0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1
  TPanelVtbl *v2; // edi@9
  int v3; // eax@9
  TPanel *v4; // ecx@10
  TPanelVtbl *v5; // edi@20
  TPanel *v6; // ecx@22

  v1 = this;
  if ( this->render_area && this->save_area && this->visible && this->active )
  {
    if ( this->map && this->player && this->map_image_lines && this->map_tile_rows )
    {
      v2 = this->vfptr;
      ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
      v3 = v1->render_all;
      v1->cur_player_bit = 1 << LOBYTE(v1->world->curr_player);
      if ( v3 )
      {
        v4 = v1->parent_panel;
        if ( v4 )
        {
          ((void (__stdcall *)(int))v4->vfptr->draw_rect)((int)&v1->clip_rect);
          TDrawArea::Copy(v1->render_area, v1->save_area, 0, 0, &v1->render_rect, 0);
          RGE_Diamond_Map::clear_image(v1);
        }
        else
        {
          TDrawArea::Clear(v1->save_area, 0, v1->color);
        }
        RGE_Diamond_Map::draw_all_tiles(v1);
        v1->render_all = 0;
      }
      else
      {
        RGE_Diamond_Map::draw_explored_tiles(v1);
      }
      RGE_Diamond_Map::copy_image(v1);
      if ( rge_base_game->game_mode != 21 )
        ((void (__thiscall *)(RGE_Diamond_Map *))v2[1].__vecDelDtor)(v1);
      (*(void (__thiscall **)(RGE_Diamond_Map *))&v2[1].gap4[0])(v1);
      if ( TDrawArea::Lock(v1->render_area, aDiam_mapDraw, 1) )
      {
        (*(void (__thiscall **)(RGE_Diamond_Map *))&v2[1].gap10[0])(v1);
        TDrawArea::Unlock(v1->render_area, aDiam_mapDraw);
      }
      v2->draw_finish((TPanel *)v1);
      RGE_Tile_List::del_list(&v1->player->diam_tile_list);
    }
    else
    {
      v5 = this->vfptr;
      ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
      if ( v1->map_image_lines )
      {
        RGE_Diamond_Map::clear_image(v1);
        RGE_Diamond_Map::copy_image(v1);
        v5->draw_finish((TPanel *)v1);
      }
      else
      {
        v6 = v1->parent_panel;
        if ( v6 )
        {
          ((void (__stdcall *)(int))v6->vfptr->draw_rect)((int)&v1->clip_rect);
          v5->draw_finish((TPanel *)v1);
        }
        else
        {
          TDrawArea::Clear(v1->render_area, &v1->clip_rect, v1->color);
          v5->draw_finish((TPanel *)v1);
        }
      }
    }
  }
  else
  {
    this->need_redraw = 0;
  }
}

//----- (00437490) --------------------------------------------------------
int __stdcall TPanel::mouse_right_dbl_click_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004374A0) --------------------------------------------------------
int __stdcall TPanel::key_down_action(int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004374B0) --------------------------------------------------------
int __stdcall TPanel::char_action(int key, __int16 count)
{
  return 0;
}

//----- (004374C0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::clear_image(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1
  TDrawArea *v2; // eax@2
  __int16 v3; // dx@2
  int v4; // ebx@3
  char *v5; // ecx@3
  __int16 v6; // ax@3
  int v7; // ebx@3
  __int16 v8; // cx@5
  __int16 v9; // dx@5
  __int16 *v10; // edi@6
  int v11; // eax@6
  __int16 v12; // dx@9
  __int16 v13; // ax@9
  __int16 v14; // cx@9
  __int16 v15; // bp@10
  signed int v16; // ebp@11
  bool v17; // zf@17
  int v18; // [sp+4h] [bp-10h]@6
  int v19; // [sp+8h] [bp-Ch]@6
  int v20; // [sp+Ch] [bp-8h]@6
  int v21; // [sp+10h] [bp-4h]@6

  v1 = this;
  if ( TDrawArea::Lock(this->save_area, aDiam_mapClear_, 1) )
  {
    v2 = v1->save_area;
    v3 = v1->map_image_start_y;
    if ( v2->Orien == 1 )
    {
      v4 = v2->Pitch * v3;
      v5 = v2->Bits;
      v6 = v2->Pitch;
      v7 = (int)&v5[v4];
    }
    else
    {
      v7 = (int)&v2->Bits[v2->Pitch * (v2->Height - v3 - 1)];
      v6 = -LOWORD(v2->Pitch);
    }
    v8 = v3 + LOWORD(v1->pnl_y);
    v9 = v8 + v1->map_image_hgt;
    if ( v8 < v9 )
    {
      v21 = v6;
      v10 = &v1->map_image_lines->line_len;
      v11 = v8;
      v19 = (int)&v1->map_image_lines->line_len;
      v18 = v8;
      v20 = v9 - v8;
      do
      {
        if ( v11 >= v1->clip_rect.top && v11 <= v1->clip_rect.bottom )
        {
          v12 = *(v10 - 1);
          v13 = v12 + LOWORD(v1->pnl_x);
          v14 = *v10 + v12 + LOWORD(v1->pnl_x) - 1;
          if ( (signed __int16)(v12 + LOWORD(v1->pnl_x)) < v1->clip_rect.left )
          {
            v15 = LOWORD(v1->clip_rect.left) - v13;
            v13 = v1->clip_rect.left;
            v12 += v15;
          }
          v16 = v1->clip_rect.right;
          if ( v14 > v16 )
            v14 = v1->clip_rect.right;
          if ( v13 >= v1->clip_rect.left && v14 <= v16 )
            memset((void *)(v12 + v7), v1->color, v14 - v13 + 1);
          v11 = v18;
        }
        v10 = (__int16 *)(v19 + 6);
        v7 += v21;
        ++v11;
        v17 = v20 == 1;
        v19 += 6;
        v18 = v11;
        --v20;
      }
      while ( !v17 );
    }
    TDrawArea::Unlock(v1->save_area, aDiam_mapClear_);
  }
}

//----- (00437620) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::copy_image(RGE_Diamond_Map *this)
{
  int v1; // edx@1
  int v2; // edx@1
  tagRECT r; // [sp+0h] [bp-10h]@1

  v1 = this->pnl_wid - 1;
  r.left = 0;
  r.right = v1;
  v2 = this->pnl_hgt - 1;
  r.top = 0;
  r.bottom = v2;
  TDrawArea::Copy(this->save_area, this->render_area, this->pnl_x, this->pnl_y, &r, 0);
}

//----- (00437660) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_all_tiles(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // edi@1
  int v2; // ebx@2
  int v3; // esi@3

  v1 = this;
  if ( TDrawArea::Lock(this->save_area, aDiam_mapDraw_a, 1) )
  {
    v2 = 0;
    if ( v1->map_hgt > 0 )
    {
      do
      {
        v3 = 0;
        if ( v1->map_wid > 0 )
        {
          do
            RGE_Diamond_Map::draw_tile(v1, v3++, v2, 0, 0);
          while ( (signed __int16)v3 < v1->map_wid );
        }
        ++v2;
      }
      while ( (signed __int16)v2 < v1->map_hgt );
    }
    TDrawArea::Unlock(v1->save_area, aDiam_mapDraw_a);
  }
}

//----- (004376D0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_explored_tiles(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // edi@1
  int v2; // edx@2
  int v3; // esi@3
  RGE_Tile_List_Node *v4; // eax@4
  RGE_Tile_List_Node *list; // [sp+4h] [bp-8h]@1
  int list_size; // [sp+8h] [bp-4h]@1

  v1 = this;
  RGE_Tile_List::get_list_info(&this->player->diam_tile_list, &list, &list_size);
  if ( list_size > 0 && TDrawArea::Lock(v1->save_area, aDiam_mapDraw_e, 1) )
  {
    v3 = 0;
    if ( list_size > 0 )
    {
      v4 = list;
      do
      {
        LOWORD(v2) = v4->row;
        LOWORD(v4) = v4->col;
        RGE_Diamond_Map::draw_tile(v1, (int)v4, v2, 0, 0);
        ++v3;
        v4 = list + 1;
        ++list;
      }
      while ( v3 < list_size );
    }
    TDrawArea::Unlock(v1->save_area, aDiam_mapDraw_e);
  }
}

//----- (00437760) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_tile(RGE_Diamond_Map *this, int col, int row, int fog, __int16 override_color)
{
  RGE_Diamond_Map *v5; // edi@1
  RGE_Map_Tile_Row *v6; // edx@1
  RGE_Map *v7; // ebx@2
  signed int v8; // ecx@4
  signed int v9; // esi@6
  double v10; // st7@7
  __int16 v11; // cx@7
  int v12; // eax@12
  int v13; // esi@12
  int v14; // ecx@12
  char v15; // cl@13
  int v16; // edx@19
  int v17; // ecx@19
  int v18; // eax@20
  int v19; // ebp@20
  int i; // edx@23
  RGE_Object_Node *v21; // eax@27
  __int16 v22; // dx@34
  int v23; // ebx@40
  int v24; // ecx@43
  int v25; // ebx@45
  int v26; // ebp@45
  __int16 v27; // dx@50
  int v28; // eax@50
  int v29; // esi@50
  int v30; // ebx@56
  int v31; // ecx@59
  int v32; // ebp@61
  int v33; // ebx@61
  char color; // [sp+10h] [bp-1Ch]@1
  int y; // [sp+14h] [bp-18h]@12
  int ya; // [sp+14h] [bp-18h]@50
  RGE_Map_Tile_Row *tile_row; // [sp+18h] [bp-14h]@1
  unsigned __int8 terrain; // [sp+1Ch] [bp-10h]@12
  int x; // [sp+20h] [bp-Ch]@12
  int xa; // [sp+20h] [bp-Ch]@50
  RGE_Tile **v41; // [sp+28h] [bp-4h]@2
  int rowa; // [sp+34h] [bp+8h]@19
  int rowb; // [sp+34h] [bp+8h]@34
  int rowc; // [sp+34h] [bp+8h]@50
  int override_colora; // [sp+3Ch] [bp+10h]@19
  int override_colorb; // [sp+3Ch] [bp+10h]@43
  int override_colorc; // [sp+3Ch] [bp+10h]@59

  v5 = this;
  color = 0;
  v6 = &this->map_tile_rows[this->map_wid + (signed __int16)row - (signed __int16)col - 1];
  tile_row = v6;
  if ( !v6->draw )
    return;
  v7 = this->map;
  v41 = v7->map_row_offset;
  if ( !v7->map_visible_flag
    && !((unsigned int)(&unified_map_offsets)[(signed __int16)row][(signed __int16)col] & this->player->mutualExploredMask) )
  {
    return;
  }
  LOWORD(v8) = row;
  if ( (signed __int16)col < (signed __int16)row )
    LOWORD(v8) = col;
  v9 = 0;
  v8 = (signed __int16)v8;
  if ( v6->ratio >= 1.0 )
  {
    v11 = (signed __int64)((double)v8 * v6->draw_step);
  }
  else
  {
    v10 = (double)v8 * v6->ratio;
    v11 = (signed __int64)v10;
    if ( v10 - (double)v11 >= v6->ratio )
      goto LABEL_11;
  }
  v9 = 1;
LABEL_11:
  if ( v9 )
  {
    v12 = v6->image_line;
    v13 = v11 + v5->map_image_lines[v12].start_x;
    v14 = v12 + v5->map_image_start_y;
    x = v13;
    y = v12 + v5->map_image_start_y;
    terrain = *((_BYTE *)&v41[(signed __int16)row][(signed __int16)col] + 5) & 0x1F;
    if ( fog )
    {
      HIWORD(v28) = HIWORD(v6);
      v27 = v5->map_tile_draw_hgt;
      LOWORD(v28) = tile_row->draw_wid;
      v29 = v5->pnl_x + v13;
      xa = v29;
      ya = v5->pnl_y + v14;
      rowc = v28;
      if ( v27 == 1 )
      {
        if ( (_WORD)v28 == 1 )
        {
          TDrawArea::SetPixel(v5->render_area, v29, ya, v5->fog_color);
        }
        else if ( (_WORD)v28 == 2 )
        {
          TDrawArea::SetPixel(v5->render_area, v29, ya, v5->fog_color);
          TDrawArea::SetPixel(v5->render_area, v29 + 1, ya, v5->fog_color);
        }
        else if ( (signed __int16)v28 > 0 )
        {
          v30 = (signed __int16)v28;
          do
          {
            TDrawArea::SetPixel(v5->render_area, v29++, ya, v5->fog_color);
            --v30;
          }
          while ( v30 );
        }
      }
      else
      {
        v31 = 0;
        override_colorc = 0;
        if ( v27 > 0 )
        {
          do
          {
            if ( (signed __int16)v28 > 0 )
            {
              v32 = (signed __int16)v28;
              v33 = ya + (signed __int16)v31;
              do
              {
                TDrawArea::SetPixel(v5->render_area, v29++, v33, v5->fog_color);
                --v32;
              }
              while ( v32 );
              v31 = override_colorc;
              LOWORD(v28) = rowc;
              v29 = xa;
            }
            override_colorc = ++v31;
          }
          while ( (signed __int16)v31 < v5->map_tile_draw_hgt );
        }
      }
    }
    else
    {
      v15 = override_color;
      if ( (_BYTE)override_color )
      {
LABEL_18:
        color = v15;
      }
      else
      {
        switch ( v41[(signed __int16)row][(signed __int16)col].tile_type )
        {
          case 0:
            color = v7->terrain_types[terrain].map_med_color;
            break;
          case 1:
          case 4:
          case 5:
          case 7:
          case 8:
          case 9:
          case 0xC:
          case 0xD:
          case 0xF:
            color = v7->terrain_types[terrain].map_low_color;
            break;
          case 2:
          case 3:
          case 6:
          case 0xA:
          case 0xB:
          case 0xE:
          case 0x10:
            v15 = v7->terrain_types[terrain].map_hi_color;
            goto LABEL_18;
          default:
            break;
        }
      }
      v16 = row;
      rowa = (signed __int16)row + 2;
      v17 = v16 - 1;
      for ( override_colora = v16 - 1; ; override_colora = v17 )
      {
        HIWORD(v18) = HIWORD(rowa);
        v19 = (signed __int16)v17;
        if ( (signed __int16)v17 >= rowa )
          break;
        if ( (signed __int16)v17 > -1 && (signed __int16)v17 < v5->map_hgt )
        {
LABEL_24:
          for ( i = col - 1; (signed __int16)i < (signed __int16)col + 2; ++i )
          {
            if ( (signed __int16)i > -1 && (signed __int16)i < v5->map_wid )
            {
              v21 = v41[v19][(signed __int16)i].objects.list;
              if ( v21 )
              {
                while ( v21->node->master_obj->map_draw_level != 4 )
                {
                  v21 = v21->next;
                  if ( !v21 )
                  {
                    v17 = override_colora;
                    ++i;
                    goto LABEL_24;
                  }
                }
                color = v21->node->master_obj->map_color;
              }
            }
            v17 = override_colora;
          }
        }
        ++v17;
      }
      v22 = v5->map_tile_draw_hgt;
      LOWORD(v18) = tile_row->draw_wid;
      rowb = v18;
      if ( v22 == 1 )
      {
        if ( (_WORD)v18 == 1 )
        {
          TDrawArea::SetPixel(v5->save_area, v13, y, color);
        }
        else if ( (_WORD)v18 == 2 )
        {
          TDrawArea::SetPixel(v5->save_area, v13, y, color);
          TDrawArea::SetPixel(v5->save_area, v13 + 1, y, color);
        }
        else if ( (signed __int16)v18 > 0 )
        {
          v23 = (signed __int16)v18;
          do
          {
            TDrawArea::SetPixel(v5->save_area, v13++, y, color);
            --v23;
          }
          while ( v23 );
        }
      }
      else
      {
        v24 = 0;
        override_colorb = 0;
        if ( v22 > 0 )
        {
          do
          {
            if ( (signed __int16)v18 > 0 )
            {
              v25 = (signed __int16)v18;
              v26 = y + (signed __int16)v24;
              do
              {
                TDrawArea::SetPixel(v5->save_area, v13++, v26, color);
                --v25;
              }
              while ( v25 );
              v24 = override_colorb;
              LOWORD(v18) = rowb;
              v13 = x;
            }
            override_colorb = ++v24;
          }
          while ( (signed __int16)v24 < v5->map_tile_draw_hgt );
        }
      }
    }
  }
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (00437C20) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_selected_area(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // ebx@1
  RGE_View *v2; // ecx@1
  int v3; // edi@4
  int v4; // eax@5
  int v5; // esi@5
  int sel_col2; // [sp+4h] [bp-10h]@2
  int sel_col1; // [sp+8h] [bp-Ch]@2
  int sel_row2; // [sp+Ch] [bp-8h]@2
  int sel_row1; // [sp+10h] [bp-4h]@2

  v1 = this;
  v2 = this->main_view;
  if ( v2
    && RGE_View::get_selection_area(v2, &sel_col1, &sel_row1, &sel_col2, &sel_row2, 1)
    && TDrawArea::Lock(v1->render_area, aDiam_mapDraw_s, 1) )
  {
    v3 = sel_row1;
    if ( sel_row1 <= sel_row2 )
    {
      v4 = sel_col2;
      v5 = sel_col1;
      do
      {
        if ( v5 <= v4 )
        {
          do
          {
            RGE_Diamond_Map::draw_tile(v1, v5, v3, 1, 0);
            v4 = sel_col2;
            ++v5;
          }
          while ( v5 <= sel_col2 );
          v5 = sel_col1;
        }
        ++v3;
      }
      while ( v3 <= sel_row2 );
    }
    TDrawArea::Unlock(v1->render_area, aDiam_mapDraw_s);
  }
}

//----- (00437CC0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_objects(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1
  RGE_Game_World *v2; // eax@2
  RGE_Object_Node *j; // edi@2
  RGE_Game_World *v4; // eax@6
  signed __int16 v5; // cx@6
  RGE_Player *v6; // ebp@7
  RGE_Object_Node *v7; // edi@7
  char color1; // ST34_1@7
  char color2; // ST30_1@7
  RGE_Object_Node *k; // ebp@11
  RGE_Static_Object *v11; // edi@12
  __int16 v12; // di@20
  __int16 v13; // bx@20
  RGE_Player *v14; // eax@21
  RGE_Static_Object *v15; // eax@22
  RGE_Player *v16; // eax@25
  RGE_Object_Node *v17; // ebx@25
  char v18; // ST34_1@26
  char v19; // ST30_1@25
  RGE_Static_Object *v20; // edi@27
  signed int i; // [sp+38h] [bp-4h]@6

  v1 = this;
  if ( TDrawArea::Lock(this->render_area, aDiam_mapDraw_o, 1) )
  {
    v2 = v1->world;
    v1->draw_objects_mode = 1;
    for ( j = (*v2->players)->objects->list; j; j = j->next )
    {
      if ( j->node )
        (*(void (__thiscall **)(RGE_Diamond_Map *, RGE_Static_Object *, signed int, signed int))&v1->vfptr[1].gap4[4])(
          v1,
          j->node,
          255,
          255);
    }
    v4 = v1->world;
    v1->draw_objects_mode = 2;
    v5 = 1;
    i = 1;
    if ( v4->player_num > 1 )
    {
      do
      {
        v6 = v4->players[v5];
        v7 = v6->doppleganger_objects->list;
        color1 = v6->color_table->map_color;
        for ( color2 = v6->color_table->map_color; v7; v7 = v7->next )
        {
          if ( v7->node )
            (*(void (__thiscall **)(RGE_Diamond_Map *, RGE_Static_Object *))&v1->vfptr[1].gap4[4])(v1, v7->node);
        }
        for ( k = v6->objects->list; k; k = k->next )
        {
          v11 = k->node;
          if ( k->node && !(v11->selected & 1) && (v11->owner != v1->player || !v11->vfptr->underAttack(k->node)) )
            (*(void (__thiscall **)(RGE_Diamond_Map *, RGE_Static_Object *))&v1->vfptr[1].gap4[4])(v1, v11);
        }
        v4 = v1->world;
        v5 = i++ + 1;
      }
      while ( (signed __int16)i < v4->player_num );
    }
    if ( v1->player->sel_count > 0 )
    {
      v12 = 0;
      v1->draw_objects_mode = 3;
      v13 = 0;
      do
      {
        v14 = v1->player;
        if ( v13 >= v14->sel_count )
          break;
        v15 = v14->sel_list[v12];
        if ( v15 )
        {
          (*(void (__thiscall **)(RGE_Diamond_Map *, RGE_Static_Object *, signed int, signed int))&v1->vfptr[1].gap4[4])(
            v1,
            v15,
            255,
            255);
          ++v13;
        }
        ++v12;
      }
      while ( v12 < 25 );
    }
    v16 = v1->player;
    v1->draw_objects_mode = 4;
    v17 = v16->objects->list;
    v19 = v16->color_table->map_color;
    if ( v17 )
    {
      v18 = v16->color_table->map_color;
      do
      {
        v20 = v17->node;
        if ( v17->node )
        {
          if ( v20->vfptr->underAttack(v17->node) )
            (*(void (__thiscall **)(RGE_Diamond_Map *, RGE_Static_Object *))&v1->vfptr[1].gap4[4])(v1, v20);
        }
        v17 = v17->next;
      }
      while ( v17 );
    }
    TDrawArea::Unlock(v1->render_area, aDiam_mapDraw_o);
  }
}

//----- (00437EC0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_visible_object(RGE_Diamond_Map *this, RGE_Static_Object *game_obj, char color1, char color2)
{
  RGE_Static_Object *v4; // esi@1
  RGE_Diamond_Map *v5; // ebx@1
  double v6; // st7@2
  RGE_Player *v7; // edi@2
  RGE_Map *v8; // ebp@3
  char v9; // al@3
  unsigned __int32 *v10; // edx@5
  char v11; // cl@5
  signed int v12; // ecx@22
  int v13; // edi@22
  signed int v14; // edx@22
  RGE_Master_Static_Object *v15; // ecx@24
  int row; // [sp+10h] [bp-4h]@2
  RGE_Static_Object *game_obja; // [sp+18h] [bp+4h]@2

  v4 = game_obj;
  v5 = this;
  if ( game_obj->tile )
  {
    v6 = game_obj->world_y;
    game_obja = (RGE_Static_Object *)(signed __int64)game_obj->world_x;
    v7 = this->player;
    row = (signed __int64)v6;
    if ( !v7->visible )
      goto LABEL_34;
    v8 = this->map;
    v9 = v8->map_visible_flag;
    if ( v9 )
    {
      if ( !v8->fog_flag )
        goto LABEL_34;
    }
    v10 = (&unified_map_offsets)[(signed __int16)(signed __int64)v6][(signed __int16)game_obja];
    v11 = 0;
    if ( (unsigned int)v10 & v7->mutualExploredMask )
      v11 = -128;
    if ( (unsigned int)v10 & v7->mutualVisibleMask )
      v11 = 15;
    if ( v9 && !v11 )
      v11 = -128;
    if ( !v8->fog_flag && v11 == -128 )
LABEL_34:
      v11 = 15;
    if ( v11 == 15 || v11 == -128 && v4->master_obj->fog_flag )
    {
      if ( v4->type == 25 )
      {
        if ( v11 == 15 )
          return;
        if ( v7->mutualAlly[v4->owner->id] != 1 || (unsigned int)v4[1].tile & v5->cur_player_bit )
        {
          v12 = 255;
          v13 = 0;
          v14 = 255;
        }
        else
        {
          v12 = BYTE1(v4[1].inside_obj);
          v13 = LOBYTE(v4[1].inside_obj);
          v14 = BYTE1(v4[1].inside_obj);
        }
      }
      else
      {
        v15 = v4->master_obj;
        v13 = v15->map_draw_level;
        if ( v13 == 3 )
          v12 = v15->map_color;
        else
          v12 = (unsigned __int8)color1;
        v14 = (unsigned __int8)color2;
      }
      switch ( v13 )
      {
        case 2:
          ((void (__thiscall *)(RGE_Diamond_Map *, RGE_Static_Object *, int, signed int, signed int, RGE_Static_Object *))v5->vfptr[1].set_rect)(
            v5,
            game_obja,
            row,
            v12,
            2,
            v4);
          break;
        case 1:
          ((void (__thiscall *)(RGE_Diamond_Map *, RGE_Static_Object *, int, signed int, signed int, RGE_Static_Object *))v5->vfptr[1].set_rect)(
            v5,
            game_obja,
            row,
            v14,
            1,
            v4);
          break;
        case 3:
          ((void (__thiscall *)(RGE_Diamond_Map *, RGE_Static_Object *, int, signed int, signed int, RGE_Static_Object *))v5->vfptr[1].set_rect)(
            v5,
            game_obja,
            row,
            v12,
            2,
            v4);
          break;
        default:
          return;
      }
    }
  }
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (00438060) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_object(RGE_Diamond_Map *this, __int16 col, __int16 row, char color, __int16 size, RGE_Static_Object *game_obj)
{
  RGE_Diamond_Map *v6; // esi@1
  __int16 v7; // cx@1
  int v8; // edi@1
  double v9; // st7@4
  __int16 v10; // cx@6
  __int16 v11; // ax@6
  int v12; // edi@9
  int v13; // ebx@9
  int v14; // edi@11
  int v15; // ebx@11

  v6 = this;
  v7 = row;
  v8 = (int)&v6->map_tile_rows[row + v6->map_wid - col - 1].image_line;
  if ( col < row )
    v7 = col;
  if ( *(float *)(v8 + 32) >= 1.0 )
    v9 = (double)v7 * *(float *)(v8 + 24);
  else
    v9 = (double)v7 * *(float *)(v8 + 32);
  v10 = (unsigned __int64)(signed __int64)v9 + LOWORD(v6->pnl_x) + v6->map_image_lines[*(_WORD *)v8].start_x;
  v11 = *(_WORD *)v8 + v6->map_image_start_y + LOWORD(v6->pnl_y);
  switch ( size )
  {
    case 1:
      TDrawArea::FillRect(v6->render_area, v10 - 1, v11 - 1, v10 + 1, v11 + 1, color);
      break;
    case 2:
      v12 = v11;
      v13 = v10;
      TDrawArea::FillRect(v6->render_area, v13, v11 - 1, v13, v11 + 1, color);
      TDrawArea::FillRect(v6->render_area, v13 - 1, v12, v13 + 1, v12, color);
      break;
    case 3:
      v14 = v11;
      v15 = v10;
      TDrawArea::FillRect(v6->render_area, v10 - 3, v11, v10 + 3, v11 + 1, color);
      TDrawArea::FillRect(v6->render_area, v15 - 2, v14 - 1, v15 + 2, v14 + 2, color);
      break;
    case 4:
      TDrawArea::FillRect(v6->render_area, v10 - 2, v11 - 2, v10 + 2, v11 + 2, color);
      break;
  }
}

//----- (004381D0) --------------------------------------------------------
void __userpurge RGE_Diamond_Map::draw_clipped_horz_line(RGE_Diamond_Map *this@<ecx>, RGE_Map_Image_Line *a2@<eax>, __int16 x, __int16 y, __int16 len, char color, RGE_Map_Image_Line *image_line)
{
  RGE_Map_Image_Line *v7; // esi@1
  int v8; // edi@1
  __int16 v9; // dx@1
  __int16 v10; // ax@3
  __int16 v11; // si@3
  int xa; // [sp+14h] [bp+4h]@3
  RGE_Map_Image_Line *image_linea; // [sp+24h] [bp+14h]@1

  v7 = image_line;
  LOWORD(a2) = image_line->start_x;
  v8 = image_line->start_x + this->pnl_x;
  v9 = x;
  image_linea = a2;
  if ( x < v8 )
    v9 = (_WORD)a2 + LOWORD(this->pnl_x);
  v10 = len;
  v11 = v7->line_len;
  xa = v9;
  if ( len + v9 - 1 >= v8 + v11 )
    v10 = (_WORD)image_linea + v11 + LOWORD(this->pnl_x) - v9;
  TDrawArea::DrawHorzLine(this->render_area, xa, y, v10, color);
}

//----- (00438250) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::draw_view_rect(RGE_Diamond_Map *this)
{
  RGE_Diamond_Map *v1; // esi@1
  RGE_Player *v2; // edi@1
  int v3; // ebp@1
  signed __int64 v4; // rax@1
  bool v5; // zf@1
  RGE_Map *v6; // ecx@4
  int v7; // edi@7
  __int16 v8; // cx@7
  double v9; // st7@10
  __int16 v10; // bx@12
  __int16 v11; // di@12
  double v12; // st7@12
  int v13; // edi@12
  signed int v14; // eax@12
  int v15; // ebx@12
  __int16 v16; // cx@12
  int v17; // ebx@13
  int i; // edx@13
  int v19; // ecx@14
  int v20; // edi@14
  int v21; // eax@16
  int v22; // edi@16
  int v23; // ebp@16
  int v24; // eax@16
  int v25; // ecx@18
  int v26; // eax@21
  int v27; // ecx@24
  int v28; // edx@24
  float vwid; // [sp+10h] [bp-10h]@12
  int vhgt; // [sp+14h] [bp-Ch]@10
  int row; // [sp+18h] [bp-8h]@1
  int v32; // [sp+1Ch] [bp-4h]@12

  v1 = this;
  v2 = this->player;
  v3 = (signed __int64)v2->view_x;
  v4 = (signed __int64)v2->view_y;
  v5 = (_WORD)v3 == this->view_col;
  row = v4;
  if ( !v5 || (_WORD)v4 != this->view_row )
  {
    if ( (signed __int16)v3 < 0 )
      return;
    v6 = this->map;
    if ( (signed __int16)v3 >= v6->map_width || (signed __int16)v4 < 0 || (signed __int16)v4 >= v6->map_height )
      return;
    v7 = (int)&v1->map_tile_rows[v1->map_wid
                               - (signed __int16)(signed __int64)v2->view_x
                               + (signed __int16)(signed __int64)v2->view_y
                               - 1].image_line;
    v8 = row;
    if ( (signed __int16)v3 < (signed __int16)row )
      v8 = v3;
    if ( *(float *)(v7 + 32) >= 1.0 )
    {
      vhgt = v8;
      v9 = (double)v8 * *(float *)(v7 + 24);
    }
    else
    {
      vhgt = v8;
      v9 = (double)v8 * *(float *)(v7 + 32);
    }
    v10 = *(_WORD *)v7 + v1->map_image_start_y + LOWORD(v1->pnl_y);
    v11 = (unsigned __int64)(signed __int64)v9 + LOWORD(v1->pnl_x) + v1->map_image_lines[*(_WORD *)v7].start_x;
    RGE_View::get_max_size(v1->main_view, (__int16 *)&vwid, (__int16 *)&vhgt);
    v12 = (double)v11;
    v13 = SLOWORD(vwid) / 2;
    v32 = SLOWORD(vwid) / 2;
    v1->view_rect.left = (signed __int64)(v12 - (double)v32 * v1->map_col_ratio);
    v14 = v10;
    v15 = (signed __int16)vhgt;
    v32 = (signed __int16)vhgt;
    vwid = (double)v14;
    v1->view_rect.top = (signed __int64)(vwid - (double)(signed __int16)vhgt * v1->map_row_ratio);
    v32 = v13 + 2;
    v1->view_rect.right = (signed __int64)((double)(v13 + 2) * v1->map_col_ratio + v12);
    v32 = v15 + 4;
    v16 = row;
    v1->view_rect.bottom = (signed __int64)((double)(v15 + 4) * v1->map_row_ratio + vwid);
    v1->view_col = v3;
    v1->view_row = v16;
  }
  v17 = v1->view_rect.top;
  for ( i = v1->view_rect.bottom; v17 <= i; ++v17 )
  {
    v19 = v1->map_image_start_y;
    v20 = v1->pnl_y;
    if ( v17 >= v20 + v19 && v17 <= v1->map_image_hgt + v20 + v19 - 1 )
    {
      v21 = v17 - v19 - v20;
      v22 = v1->view_rect.right;
      v23 = (int)&v1->map_image_lines[v21].tile_row;
      v24 = v1->view_rect.left;
      if ( v17 == v1->view_rect.top || v17 == i )
      {
        v27 = v1->pnl_x + *(_WORD *)(v23 + 2);
        v28 = v27 + *(_WORD *)(v23 + 4);
        if ( v24 < v28 && v22 >= v27 )
        {
          if ( v24 < v27 )
            v24 = v1->pnl_x + *(_WORD *)(v23 + 2);
          if ( v22 >= v28 )
            v22 = v28 - 1;
          TDrawArea::DrawHorzLine(v1->render_area, v24, v17, v22 - v24 + 1, -1);
        }
      }
      else
      {
        v25 = v1->pnl_x + *(_WORD *)(v23 + 2);
        if ( v24 < v25 + *(_WORD *)(v23 + 4) && v24 >= v25 )
          TDrawArea::SetPixel(v1->render_area, v24, v17, -1);
        v26 = v1->pnl_x + *(_WORD *)(v23 + 2);
        if ( v22 < v26 + *(_WORD *)(v23 + 4) && v22 >= v26 )
          TDrawArea::SetPixel(v1->render_area, v22, v17, -1);
      }
    }
    i = v1->view_rect.bottom;
  }
}

//----- (00438530) --------------------------------------------------------
int __thiscall RGE_Diamond_Map::pick_tile(RGE_Diamond_Map *this, int x, int y, __int16 *col, __int16 *row, RGE_Tile **tile)
{
  RGE_Diamond_Map *v6; // edi@1
  RGE_Map_Image_Line *v7; // esi@2
  int v8; // ebx@3
  int v9; // ecx@3
  int v10; // eax@3
  int v11; // edx@3
  int v12; // ecx@5
  int v13; // edx@5
  int v14; // ecx@5
  int v15; // esi@7
  signed __int64 v16; // rax@7
  __int16 v17; // cx@7
  __int16 v18; // si@7
  int result; // eax@13

  v6 = this;
  if ( this->map
    && (v7 = this->map_image_lines) != 0
    && (v8 = this->pnl_x, v9 = y - this->pnl_y, v10 = x - v8, v11 = v6->map_image_start_y, v9 >= v11)
    && v9 <= v6->map_image_hgt + v11 - 1
    && (v12 = 3 * (v9 - v11), v13 = v7[2 * v12 / 6u].start_x, v14 = (int)&v7[2 * v12 / 6u].tile_row, v10 >= v13)
    && v10 <= *(_WORD *)(v14 + 4) + v13 - 1 )
  {
    v15 = (int)&v6->map_tile_rows[*(_WORD *)v14].image_line;
    v16 = (signed __int64)((double)(v10 - v13) * *(float *)(v15 + 8) + *(float *)(v15 + 12));
    v17 = v16 + *(_WORD *)(v15 + 16);
    v18 = v16 + *(_WORD *)(v15 + 18);
    if ( col )
      *col = v17;
    if ( row )
      *row = v18;
    if ( tile )
      *tile = &v6->map->map_row_offset[v18][v17];
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00438630) --------------------------------------------------------
int __thiscall RGE_Diamond_Map::handle_size(RGE_Diamond_Map *this, int win_wid, int win_hgt)
{
  RGE_Diamond_Map *v3; // esi@1

  v3 = this;
  TPanel::handle_size((TPanel *)&this->vfptr, win_wid, win_hgt);
  v3->view_col = -1;
  v3->view_row = -1;
  RGE_Diamond_Map::create_surfaces(v3);
  return 0;
}

//----- (00438670) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::start_scroll_view(RGE_Diamond_Map *this, int x, int y)
{
  int v3; // ebx@1
  RGE_Diamond_Map *v4; // esi@1
  int v5; // edi@1
  double v6; // st7@2
  signed int v7; // ST20_4@2
  float v8; // ST10_4@2
  float v9; // ST0C_4@2
  RGE_View *v10; // ecx@2
  RGE_Tile *tile; // [sp+18h] [bp-4h]@1

  v3 = x;
  v4 = this;
  v5 = y;
  if ( RGE_Diamond_Map::pick_tile(this, x, y, (__int16 *)&x, (__int16 *)&y, &tile) )
  {
    TPanel::capture_mouse((TPanel *)&v4->vfptr);
    v6 = (double)(signed __int16)y - -0.5;
    v7 = (signed __int16)x;
    v4->scrolling = 1;
    v8 = v6;
    v9 = (double)v7 - -0.5;
    RGE_Player::set_view_loc(v4->player, v9, v8);
    v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
    v10 = v4->main_view;
    if ( v10 )
      ((void (__stdcall *)(signed int))v10->vfptr->set_redraw)(1);
    v4->mouse_last_x = v3;
    v4->mouse_last_y = v5;
  }
}

//----- (00438720) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::handle_scroll_view(RGE_Diamond_Map *this, int x, int y)
{
  int v3; // ebx@1
  RGE_Diamond_Map *v4; // esi@1
  int v5; // edi@1
  float v6; // ST10_4@2
  float v7; // ST0C_4@2
  RGE_View *v8; // ecx@2
  RGE_Tile *tile; // [sp+18h] [bp-4h]@1

  v3 = x;
  v4 = this;
  v5 = y;
  if ( RGE_Diamond_Map::pick_tile(this, x, y, (__int16 *)&x, (__int16 *)&y, &tile) )
  {
    v6 = (double)(signed __int16)y - -0.5;
    v7 = (double)(signed __int16)x - -0.5;
    RGE_Player::set_view_loc(v4->player, v7, v6);
    v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
    v8 = v4->main_view;
    if ( v8 )
      ((void (__stdcall *)(signed int))v8->vfptr->set_redraw)(1);
    v4->mouse_last_x = v3;
    v4->mouse_last_y = v5;
  }
}

//----- (004387C0) --------------------------------------------------------
void __thiscall RGE_Diamond_Map::end_scroll_view(RGE_Diamond_Map *this)
{
  this->scrolling = 0;
  TPanel::release_mouse((TPanel *)&this->vfptr);
}

//----- (004387D0) --------------------------------------------------------
int __thiscall RGE_Diamond_Map::is_inside(RGE_Diamond_Map *this, int x, int y)
{
  int v3; // ebx@1
  int v4; // edi@1
  RGE_Diamond_Map *v5; // esi@1
  int result; // eax@2
  RGE_Tile *tile; // [sp+Ch] [bp-4h]@2

  v3 = x;
  v4 = y;
  v5 = this;
  if ( TPanel::is_inside((TPanel *)&this->vfptr, x, y) )
    result = RGE_Diamond_Map::pick_tile(v5, v3, v4, (__int16 *)&x, (__int16 *)&y, &tile);
  else
    result = 0;
  return result;
}
