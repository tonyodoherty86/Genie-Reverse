
/**
 * @file    Engine\RGE\Sprite.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

RGE_Sprite::RGE_Sprite(short in_id)
{
    this->id = in_id;
}

RGE_Sprite::RGE_Sprite(int infile, RGE_Sound **sounds, RGE_Color_Table **c_tables)
{
    this->color_tables = c_tables;

    short temp_short;

    rge_read(infile, this->name, sizeof(this->name));
    rge_read(infile, this->pict_name, sizeof(this->pict_name));

    rge_read(infile, &this->resource_id, 4);
    rge_read(infile, &this->loaded, 1);
    rge_read(infile, &this->color_flag, 1);
    rge_read(infile, &this->draw_level, 1);
    rge_read(infile, &this->color_table, 2);
    rge_read(infile, &this->transparent_picking_flag, 1);

    rge_read(infile, &this->box_x1, 2);
    rge_read(infile, &this->box_y1, 2);
    rge_read(infile, &this->box_x2, 2);
    rge_read(infile, &this->box_y2, 2);

    rge_read(infile, &this->draw_list_num, 2);

    rge_read(infile, &temp_short, 2);
    rge_read(infile, &this->micro_man_sound, 1);
    rge_read(infile, &this->frame_num, 2);
    rge_read(infile, &this->facet_num, 2);
    rge_read(infile, &this->base_speed, 4);
    rge_read(infile, &this->duration, 4);
    rge_read(infile, &this->pause_between_loops, 4);
    rge_read(infile, &this->flag, 1);
    rge_read(infile, &this->id, 2);
    rge_read(infile, &this->mirror_flag, 1);

#if RGE_SPRITE_EDITOR_FLAG_EXISTS
    if( save_game_version >= 10.72 ){
        rge_read(infile, &this->editor_flag, 1);
    }else{
        this->editor_flag = 0;
    }
#endif

    if( temp_short >= 0 ){
        this->main_sound = sounds[temp_short];
    }else{
        this->main_sound = nullptr;
    }

    if( this->draw_list_num > 0 ){
        this->draw_list = new RGE_Picture_List[this->draw_list_num];
        rge_read(infile, this->draw_list, sizeof(RGE_Picture_List) * this->draw_list_num);
    }else{
        this->draw_list = nullptr;
    }

    /* read micro management sounds */
    if( this->micro_man_sound ){
        this->sound_list = new RGE_Sound_List[this->facet_num];
        for( int i = 0; i < this->facet_num; i++ ){
            for( int j = 0; j < 3; j++ ){
                rge_read(infile, this->sound_list[i]->sound[j], 2);
                rge_read(v5, &temp_short, 2);
                if( temp_short >= 0 ){
                    this->sound_list[i]->sound[j] = sounds[temp_short];
                }else{
                    this->sound_list[i]->sound[j] = nullptr;
                }
            }
        }
    }else{
        this->sound_list = nullptr;
    }
}

RGE_Sprite::~RGE_Sprite()
{
    if( this->shape &&
        this->loaded ){
        delete this->shape;
    }

    this->loaded = false;

    this->shape = nullptr;

    if( this->sound_list ){
        delete this->sound_list;
    }

    if( this->draw_list ){
        delete this->draw_list;
    }

    this->color_tables = nullptr;
}

void RGE_Sprite::save(int outfile)
{
    short temp_short;

    rge_write(outfile, this->name, sizeof(this->name));
    rge_write(outfile, this->pict_name, sizeof(this->pict_name));

    rge_write(outfile, &this->resource_id, 4);
    rge_write(outfile, &this->loaded, 1);
    rge_write(outfile, &this->color_flag, 1);
    rge_write(outfile, &this->draw_level, 1);
    rge_write(outfile, &this->color_table, 2);
    rge_write(outfile, &this->transparent_picking_flag, 1);

    rge_write(outfile, &this->box_x1, 2);
    rge_write(outfile, &this->box_y1, 2);
    rge_write(outfile, &this->box_x2, 2);
    rge_write(outfile, &this->box_y2, 2);

    rge_write(outfile, &this->draw_list_num, 2);

    if( this->main_sound ){
        temp_short = this->main_sound->id;
    }else{
        temp_short = -1;
    }
    rge_write(outfile, &temp_short, 2);

    rge_write(outfile, &this->micro_man_sound, 1);
    rge_write(outfile, &this->frame_num, 2);
    rge_write(outfile, &this->facet_num, 2);
    rge_write(outfile, &this->base_speed, 4);
    rge_write(outfile, &this->duration, 4);
    rge_write(outfile, &this->pause_between_loops, 4);
    rge_write(outfile, &this->flag, 1);
    rge_write(outfile, &this->id, 2);
    rge_write(outfile, &this->mirror_flag, 1);

#if RGE_SPRITE_EDITOR_FLAG_EXISTS
    if( save_game_version >= 10.72 ){
        rge_write(outfile, &this->editor_flag, 1);
    }
#endif

    if( this->draw_list ){
        rge_write(outfile, this->draw_list, this->draw_list_num * sizeof(RGE_Picture_List));
    }
    if( this->micro_man_sound ){
        for( int i = 0; i < this->facet_num; i++ ){
            for( int j = 0; j < 3; j++ ){
                rge_write(outfile, &this->sound_list[i]->frame[j], 2);
                if( this->sound_list[i]->sound[j] ){
                    temp_short = this->sound_list[i]->sound[j]->id;
                }else{
                    temp_short = -1;
                }
                rge_write(outfile, &temp_short, 2);
            }
        }
    }
}

void RGE_Sprite::load_facets(RGE_Sprite **sprites)
{
    this->shape = nullptr;
    this->loaded = true;
}

void RGE_Sprite::play_sound(short frame1, short frame2, short facet)
{
    if( facet >= this->facet_num ){
        facet = 0;
    }
    if( frame1 != frame2 ){
        if( this->main_sound && (!frame1 || frame2 < frame1 && frame2) ){
            this->main_sound->play(1);
        }
        int v13;
        if( this->micro_man_sound ){
            if( frame1 >= frame2 ){
                int v14 = 20 * facet + 12;
                for( v13 = 0; v13 < 3; v13++ ){
                    int v16 = *(_WORD *)((char *)this->sound_list->sound + v14);
                    if( v16 <= -1 )
                        break;
                    if( v16 >= frame1 || v16 < frame2 )
                        this->sound_list->sound[v13 + 4 * facet + facet]->play(1);
                    v14 += 2;
                }
            }else{
                int v9 = 20 * facet + 12;
                for( v13 = 0; v13 < 3; v13++ ){
                    int v11 = *(_WORD *)((char *)this->sound_list->sound + v9);
                    if( v11 <= -1 )
                        break;
                    if( v11 >= frame1 && v11 < frame2 )
                        this->sound_list->sound[v13 + 4 * facet + facet]->play(1);
                    v9 += 2;
                }
            }
        }
    }
}

/*
void RGE_Sprite::play_sound(short a2, short arg4, short arg8, RGE_Static_Object *a5, int a3, int a4)
{
  short v7; // bp@1
  RGE_Sprite *v8; // ebx@1
  RGE_Sound *v9; // ecx@4
  int v10; // esi@15
  signed int v11; // edi@15
  int v12; // ebp@15
  RGE_Sound_List *v13; // ecx@16
  signed int v14; // eax@16
  int v15; // eax@21
  int v16; // esi@26
  signed int v17; // edi@26
  int v18; // ebp@26
  RGE_Sound_List *v19; // ecx@27
  signed int v20; // eax@27
  int v21; // eax@32
  int v22; // [sp-10h] [bp-20h]@10
  int v23; // [sp-10h] [bp-20h]@21
  int v24; // [sp-10h] [bp-20h]@32
  int v25; // [sp-Ch] [bp-1Ch]@10
  int v26; // [sp-Ch] [bp-1Ch]@21
  int v27; // [sp-Ch] [bp-1Ch]@32
  short v28; // [sp-8h] [bp-18h]@10
  short v29; // [sp-8h] [bp-18h]@21
  short v30; // [sp-8h] [bp-18h]@32
  short v31; // [sp-4h] [bp-14h]@10
  short v32; // [sp-4h] [bp-14h]@21
  short v33; // [sp-4h] [bp-14h]@32

  v7 = arg8;
  v8 = this;

  if( arg8 >= this->facet_num )
    v7 = 0;
  if( a2 == arg4 )
    return;
  v9 = this->main_sound;
  if( v9 && (!a2 || arg4 < a2 && arg4) )
  {
    if( a5 )
    {
      if( !sub_4D3A60(a5, &a3, &a4) )
        goto LABEL_13;
      v31 = -1;
      v28 = -1;
      v25 = a4;
      v22 = a3;
      v9 = v8->main_sound;
    }
    else
    {
      v31 = -1;
      v28 = -1;
      v25 = a4;
      v22 = a3;
    }
    RGE_Sound::play(v9, 2, v22, v25, v28, v31);
  }
LABEL_13:
  if( v8->micro_man_sound )
  {
    if( a2 < arg4 )
    {
      v10 = v7;
      v11 = 0;
      v12 = 20 * v7 + 12;
      while ( 1 )
      {
        v13 = v8->sound_list;
        v14 = *(v13->sound + v12);
        if( v14 <= -1 )
          return;
        if( v14 >= a2 && v14 < arg4 )
        {
          if( !a5 )
          {
            v32 = -1;
            v29 = -1;
            v26 = 0;
            v23 = 0;
            v15 = v11 + 4 * v10 + v10;
            goto LABEL_23;
          }
          if( sub_4D3A60(a5, &a3, &a4) )
          {
            v32 = -1;
            v29 = -1;
            v26 = a4;
            v23 = a3;
            v13 = v8->sound_list;
            v15 = v11 + 4 * v10 + v10;
LABEL_23:
            RGE_Sound::play(v13->sound[v15], 2, v23, v26, v29, v32);
            goto LABEL_24;
          }
        }
LABEL_24:
        ++v11;
        v12 += 2;
        if( v11 >= 3 )
          return;
      }
    }
    v16 = v7;
    v17 = 0;
    v18 = 20 * v7 + 12;
    do
    {
      v19 = v8->sound_list;
      v20 = *(v19->sound + v18);
      if( v20 <= -1 )
        return;
      if( v20 >= a2 || v20 < arg4 )
      {
        if( !a5 )
        {
          v33 = -1;
          v30 = -1;
          v27 = a4;
          v24 = a3;
          v21 = v17 + 4 * v16 + v16;
          goto LABEL_34;
        }
        if( sub_4D3A60(a5, &a3, &a4) )
        {
          v33 = -1;
          v30 = -1;
          v27 = a4;
          v24 = a3;
          v19 = v8->sound_list;
          v21 = v17 + 4 * v16 + v16;
LABEL_34:
          RGE_Sound::play(v19->sound[v21], 2, v24, v27, v30, v33);
          goto LABEL_35;
        }
      }
LABEL_35:
      ++v17;
      v18 += 2;
    }
    while ( v17 < 3 );
  }
}
*/

char RGE_Sprite::get_facetindex(int facet, int frame, int *facetindex)
{
    if( this->mirror_flag &&
        this->facet_num == 2 ){

        *facetindex = frame;

        return facet;
    }
    if( this->mirror_flag == 0 ||
        facet <= this->mirror_flag &&
        facet >= this->facet_num >> 2 ){

        if( this->mirror_flag ){
            *facetindex = frame + this->frame_num * (facet - (this->facet_num >> 2));
        }else{
            *facetindex = frame + facet * this->frame_num;
        }
        return 0;
    }else{
        if( facet <= this->facet_num >> 1 ){
            *facetindex = (this->facet_num >> 1) - facet;
        }else{
            *facetindex = this->facet_num + (this->facet_num >> 1) - facet;
        }
        *facetindex = frame + this->frame_num * (*facetindex - (this->facet_num >> 2));

        return 1;
    }
}

//----- (004C01A0) --------------------------------------------------------
void __thiscall RGE_Sprite::do_draw(RGE_Sprite *this, int facet, int frame, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area, char min_draw_level)
{
  int v8; // ebx@1
  RGE_Sprite *v9; // esi@1
  unsigned int v10; // edi@5
  TShape *v11; // eax@5
  TShape *v12; // eax@6
  unsigned int v13; // eax@8
  signed int v14; // ecx@9
  int v15; // eax@18
  int v16; // eax@31
  char *v17; // [sp-4h] [bp-12Ch]@33
  char *v18; // [sp-4h] [bp-12Ch]@37
  int facetindex; // [sp+10h] [bp-118h]@13
  char *fname; // [sp+14h] [bp-114h]@1
  TShape *v21; // [sp+18h] [bp-110h]@5
  char s[256]; // [sp+1Ch] [bp-10Ch]@15
  int v23; // [sp+124h] [bp-4h]@5

  v8 = frame;
  v9 = this;
  fname = 0;
  if ( frame >= this->frame_num )
    v8 = 0;
  if ( !this->shape )
  {
    if ( !this->loaded )
      return;
    addstring(&fname, this->pict_name, a_shp);
    v10 = debug_timeGetTime();
    v11 = (TShape *)operator new(0x20u);
    v21 = v11;
    v23 = 0;
    if ( v11 )
      TShape::TShape(v11, fname, v9->resource_id);
    else
      v12 = 0;
    v23 = -1;
    v9->shape = v12;
    v13 = debug_timeGetTime();
    RGE_Base_Game::add_to_timing(rge_base_game, 11, v13 - v10);
    free(fname);
  }
  v14 = v9->draw_level;
  v9->delta_time = 0;
  SDI_Draw_Level = v14;
  if ( v14 < (unsigned __int8)min_draw_level )
    SDI_Draw_Level = (unsigned __int8)min_draw_level;
  SDI_List->Select_Box = 0;
  if ( v9->box_x1 )
    SDI_List->Select_Box = &v9->box_x1;
  if ( RGE_Sprite::get_facetindex(v9, facet, v8, &facetindex) )
  {
    if ( do_draw_log )
    {
      sprintf(s, aSDDDDM, v9, x, y, facetindex, v9->color_flag);
      if ( safe_draw_log )
        write_draw_log2(s);
      else
        write_draw_log(s);
    }
    LOWORD(v15) = v9->color_table;
    if ( (signed __int16)v15 >= 0 )
    {
      v15 = (signed __int16)v15;
      if ( v9->color_tables[(signed __int16)v15] )
      {
        ASMSet_Color_Xform(16 * (v15 + 1));
        TShape::shape_mirror(
          v9->shape,
          draw_area,
          x,
          y,
          facetindex,
          v9->color_flag,
          v9->color_tables[v9->color_table]->table);
      }
      else
      {
        TShape::shape_mirror(v9->shape, draw_area, x, y, facetindex, v9->color_flag, 0);
      }
    }
    else if ( player_color )
    {
      ASMSet_Color_Xform(16 * (player_color->id + 1));
      TShape::shape_mirror(v9->shape, draw_area, x, y, facetindex, v9->color_flag, player_color->table);
    }
    else
    {
      TShape::shape_mirror(v9->shape, draw_area, x, y, facetindex, v9->color_flag, 0);
    }
  }
  else
  {
    if ( do_draw_log )
    {
      sprintf(s, aSDDDDU, v9, x, y, facetindex, v9->color_flag);
      if ( safe_draw_log )
        write_draw_log2(s);
      else
        write_draw_log(s);
    }
    LOWORD(v16) = v9->color_table;
    if ( (signed __int16)v16 >= 0 )
    {
      v16 = (signed __int16)v16;
      if ( v9->color_tables[(signed __int16)v16] )
      {
        ASMSet_Color_Xform(16 * (v16 + 1));
        v18 = v9->color_tables[v9->color_table]->table;
      }
      else
      {
        v18 = 0;
      }
      TShape::shape_draw(v9->shape, draw_area, x, y, facetindex, v9->color_flag, v18);
    }
    else
    {
      if ( player_color )
      {
        ASMSet_Color_Xform(16 * (player_color->id + 1));
        v17 = player_color->table;
      }
      else
      {
        v17 = 0;
      }
      TShape::shape_draw(v9->shape, draw_area, x, y, facetindex, v9->color_flag, v17);
    }
  }
  if ( do_draw_log )
  {
    if ( safe_draw_log )
      write_draw_log2(asc_580464);
    else
      write_draw_log(asc_580464);
  }
}
// 592A5C: using guessed type int safe_draw_log;
// 62C498: using guessed type int do_draw_log;

//----- (004C04F0) --------------------------------------------------------
int __thiscall RGE_Sprite::draw(RGE_Sprite *this, int facet, int frame, int x, int y, int sx, int sy, RGE_Color_Table *player_color, TDrawArea *draw_area, char min_draw_level)
{
  RGE_Sprite *v10; // edx@1
  int v11; // ebx@1
  __int16 v12; // si@3
  int result; // eax@5
  int v14; // esi@6
  int v15; // esi@7
  __int16 v16; // ax@7
  RGE_Sprite *v17; // ecx@9
  int v18; // eax@9
  char v19; // dl@9
  bool v20; // cf@9
  bool v21; // zf@9
  int v22; // edx@9
  int v23; // ecx@13
  bool v24; // sf@13
  unsigned __int8 v25; // of@13
  RGE_Sprite *v26; // [sp+10h] [bp-Ch]@1
  int index; // [sp+14h] [bp-8h]@5
  int v28; // [sp+18h] [bp-4h]@6

  v10 = this;
  v11 = facet;
  v26 = this;
  if ( facet >= this->facet_num )
  {
    v11 = 0;
    facet = 0;
  }
  v12 = this->draw_list_num;
  if ( v12 > 0 && this->draw_list )
  {
    result = 0;
    index = 0;
    if ( v12 > 0 )
    {
      v14 = 0;
      v28 = 0;
      do
      {
        v15 = (int)&v10->draw_list->picture_num + v14;
        v16 = *(_WORD *)(v15 + 12);
        if ( v16 < 0 || v16 == v11 )
        {
          v17 = *(RGE_Sprite **)(v15 + 4);
          v18 = v11 * v17->facet_num / v10->facet_num;
          v19 = v17->draw_level;
          v20 = (unsigned __int8)v19 < 0xAu;
          v21 = v19 == 10;
          v22 = *(_WORD *)(v15 + 10);
          if ( v20 || v21 )
            RGE_Sprite::do_draw(
              v17,
              v18,
              frame,
              sx + *(_WORD *)(v15 + 8),
              sy + v22,
              player_color,
              draw_area,
              min_draw_level);
          else
            RGE_Sprite::do_draw(
              v17,
              v18,
              frame,
              x + *(_WORD *)(v15 + 8),
              y + v22,
              player_color,
              draw_area,
              min_draw_level);
          v11 = facet;
          v10 = v26;
        }
        v23 = v10->draw_list_num;
        result = index + 1;
        v14 = v28 + 16;
        v25 = __OFSUB__(index + 1, v23);
        v24 = index++ + 1 - v23 < 0;
        v28 += 16;
      }
      while ( v24 ^ v25 );
    }
  }
  else
  {
    if ( this->draw_level > 0xAu )
      RGE_Sprite::do_draw(this, v11, frame, x, y, player_color, draw_area, min_draw_level);
    else
      RGE_Sprite::do_draw(this, v11, frame, sx, sy, player_color, draw_area, min_draw_level);
    result = 1;
  }
  return result;
}

//----- (004C0620) --------------------------------------------------------
char __thiscall RGE_Sprite::normal_draw(RGE_Sprite *this, int facet, int frame, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area)
{
  RGE_Sprite *v7; // esi@1
  int v8; // edi@1
  __int16 v9; // ax@3
  signed int v10; // ebx@3
  int v11; // eax@7
  RGE_Sprite *v12; // ecx@7
  __int16 v13; // dx@8
  int index; // [sp+10h] [bp-4h]@5
  int faceta; // [sp+18h] [bp+4h]@6

  v7 = this;
  v8 = facet;
  if ( facet >= this->facet_num )
    v8 = 0;
  v9 = this->draw_list_num;
  v10 = 0;
  if ( v9 <= 0 || !this->draw_list )
  {
    if ( this->draw_level == 20 )
      RGE_Sprite::do_draw(this, v8, frame, x, y, player_color, draw_area, 0);
    LOBYTE(v10) = 1;
    return v10;
  }
  index = 0;
  if ( v9 <= 0 )
    return v10;
  faceta = 0;
  do
  {
    v11 = (int)&v7->draw_list[faceta].picture_num;
    v12 = *(RGE_Sprite **)(v11 + 4);
    if ( v12->draw_level == 20 )
    {
      v13 = *(_WORD *)(v11 + 12);
      if ( v13 < 0 || v13 == v8 )
      {
        RGE_Sprite::do_draw(
          v12,
          v8 * v12->facet_num / v7->facet_num,
          frame,
          x + *(_WORD *)(v11 + 8),
          y + *(_WORD *)(v11 + 10),
          player_color,
          draw_area,
          0);
        v10 = index;
      }
    }
    index = ++v10;
    ++faceta;
  }
  while ( v10 < v7->draw_list_num );
  return v10;
}

//----- (004C0720) --------------------------------------------------------
char __thiscall RGE_Sprite::shadow_draw(RGE_Sprite *this, int facet, int frame, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area, char flag)
{
  int v8; // ebp@1
  RGE_Sprite *v9; // edi@1
  __int16 v10; // ax@3
  RGE_Picture_List *v11; // ecx@7
  RGE_Sprite *v12; // esi@7
  int v13; // eax@7
  char v14; // cl@7
  __int16 v15; // cx@9
  char v17; // al@14
  int v18; // [sp+10h] [bp-4h]@6
  int faceta; // [sp+18h] [bp+4h]@5

  v8 = facet;
  v9 = this;
  if ( facet >= this->facet_num )
    v8 = 0;
  v10 = this->draw_list_num;
  if ( v10 <= 0 || !this->draw_list )
  {
    v17 = this->draw_level;
    if ( v17 != flag && (unsigned __int8)v17 < 0x14u )
      RGE_Sprite::do_draw(this, v8, frame, x, y, player_color, draw_area, 0);
    return 1;
  }
  faceta = 0;
  if ( v10 <= 0 )
    return faceta;
  v18 = 0;
  do
  {
    v11 = v9->draw_list;
    v12 = v11[v18].sprite;
    v13 = (int)&v11[v18].picture_num;
    v14 = v12->draw_level;
    if ( v14 != flag && (unsigned __int8)v14 < 0x14u )
    {
      v15 = *(_WORD *)(v13 + 12);
      if ( v15 < 0 || v15 == v8 )
        RGE_Sprite::do_draw(
          v12,
          v8 * v12->facet_num / v9->facet_num,
          frame,
          x + *(_WORD *)(v13 + 8),
          y + *(_WORD *)(v13 + 10),
          player_color,
          draw_area,
          0);
    }
    ++v18;
    ++faceta;
  }
  while ( faceta < v9->draw_list_num );
  return faceta;
}

//----- (004C0840) --------------------------------------------------------
int __thiscall RGE_Sprite::get_size(RGE_Sprite *this, int *xmin, int *ymin, int *xmax, int *ymax, int facet)
{
  RGE_Sprite *v6; // esi@1
  unsigned int v7; // edi@3
  TShape *v8; // eax@3
  TShape *v9; // eax@4
  unsigned int v10; // eax@6
  char *fname; // [sp+8h] [bp-14h]@3
  TShape *v13; // [sp+Ch] [bp-10h]@3
  int v14; // [sp+18h] [bp-4h]@3

  v6 = this;
  if ( this->shape )
    return (unsigned __int8)TShape::shape_minmax(v6->shape, xmin, ymin, xmax, ymax, facet);
  if ( this->loaded )
  {
    fname = 0;
    addstring(&fname, this->pict_name, a_shp);
    v7 = debug_timeGetTime();
    v8 = (TShape *)operator new(0x20u);
    v13 = v8;
    v14 = 0;
    if ( v8 )
      TShape::TShape(v8, fname, v6->resource_id);
    else
      v9 = 0;
    v14 = -1;
    v6->shape = v9;
    v10 = debug_timeGetTime();
    RGE_Base_Game::add_to_timing(rge_base_game, 11, v10 - v7);
    free(fname);
    return (unsigned __int8)TShape::shape_minmax(v6->shape, xmin, ymin, xmax, ymax, facet);
  }
  return 0;
}

//----- (004C0960) --------------------------------------------------------
int __thiscall RGE_Sprite::get_frame(RGE_Sprite *this, __int16 *min_x, __int16 *min_y, __int16 *max_x, __int16 *max_y, int facet, int frame)
{
  RGE_Sprite *v7; // esi@1
  unsigned int v8; // edi@3
  TShape *v9; // eax@3
  TShape *v10; // eax@4
  unsigned int v11; // eax@6
  __int16 v12; // ax@7
  __int16 *v13; // ebp@11
  __int16 *v14; // edi@11
  __int16 *v15; // ebx@11
  __int16 v16; // ax@11
  int v17; // edi@14
  char *fname; // [sp+10h] [bp-14h]@3
  TShape *v20; // [sp+14h] [bp-10h]@3
  int v21; // [sp+20h] [bp-4h]@3
  __int16 *min_xa; // [sp+28h] [bp+4h]@13

  v7 = this;
  if ( !this->shape )
  {
    if ( !this->loaded )
      return 0;
    fname = 0;
    addstring(&fname, this->pict_name, a_shp);
    v8 = debug_timeGetTime();
    v9 = (TShape *)operator new(0x20u);
    v20 = v9;
    v21 = 0;
    if ( v9 )
      TShape::TShape(v9, fname, v7->resource_id);
    else
      v10 = 0;
    v21 = -1;
    v7->shape = v10;
    v11 = debug_timeGetTime();
    RGE_Base_Game::add_to_timing(rge_base_game, 11, v11 - v8);
    free(fname);
  }
  v12 = v7->box_x1;
  if ( (v12 || v7->box_x2) && (v7->box_y1 || v7->box_y2) )
  {
    *min_x = v12;
    *min_y = v7->box_y1;
    *max_x = v7->box_x2;
    *max_y = v7->box_y2;
  }
  else
  {
    v13 = min_x;
    v14 = min_y;
    *min_x = 0;
    *min_y = 0;
    v15 = max_x;
    *max_x = 0;
    *max_y = 0;
    v16 = v7->draw_list_num;
    if ( v16 > 0 && v7->draw_list )
    {
      min_xa = 0;
      if ( v16 > 0 )
      {
        v17 = 0;
        do
        {
          if ( v7->transparent_picking_flag )
          {
            v15 = max_x;
            RGE_Sprite::get_frame_min_max(
              v7->draw_list[v17].sprite,
              v13,
              min_y,
              max_x,
              max_y,
              facet * v7->draw_list[v17].sprite->facet_num / v7->facet_num,
              frame,
              v7->draw_list[v17].offset_x,
              v7->draw_list[v17].offset_y);
          }
          ++v17;
          min_xa = (__int16 *)((char *)min_xa + 1);
        }
        while ( (signed int)min_xa < v7->draw_list_num );
        v14 = min_y;
      }
    }
    else
    {
      RGE_Sprite::get_frame_min_max(v7, min_x, min_y, max_x, max_y, facet, frame, 0, 0);
    }
    if ( !*v13 && !*v15 || !*v14 && !*max_y )
      return 0;
  }
  return 1;
}

//----- (004C0B70) --------------------------------------------------------
int __thiscall RGE_Sprite::get_frame_min_max(RGE_Sprite *this, __int16 *min_x, __int16 *min_y, __int16 *max_x, __int16 *max_y, int facet, int frame, __int16 pic_x, __int16 pic_y)
{
  int v9; // eax@1
  RGE_Sprite *v10; // esi@1
  int v11; // edi@3
  int result; // eax@3
  int v13; // eax@5
  int v14; // esi@5
  int v15; // eax@7
  int v16; // esi@7
  int v17; // edi@7
  int v18; // ebx@7
  int facetindex; // [sp+Ch] [bp-Ch]@3
  int calc_min_y; // [sp+10h] [bp-8h]@3
  int calc_max_y; // [sp+14h] [bp-4h]@3

  v9 = frame;
  v10 = this;
  if ( frame >= this->frame_num )
    v9 = 0;
  v11 = (unsigned __int8)RGE_Sprite::get_facetindex(this, facet, v9, &facetindex);
  result = RGE_Sprite::get_size(v10, &facet, &calc_min_y, &frame, &calc_max_y, facetindex);
  if ( result )
  {
    if ( v11 )
    {
      v13 = -frame;
      v14 = -facet;
    }
    else
    {
      v14 = frame;
      v13 = facet;
    }
    v15 = pic_x + v13;
    v16 = pic_x + v14;
    v17 = pic_y + calc_min_y;
    v18 = pic_y + calc_max_y;
    if ( v15 < *min_x )
      *min_x = v15;
    if ( v17 < *min_y )
      *min_y = v17;
    if ( v16 > *max_x )
      *max_x = v16;
    if ( v18 > *max_y )
      *max_y = v18;
    result = 1;
  }
  return result;
}

//----- (004C0C50) --------------------------------------------------------
char __thiscall RGE_Sprite::get_lowest_draw_level(RGE_Sprite *this)
{
  int v1; // esi@1
  char result; // al@2
  char *v3; // edx@4

  LOWORD(v1) = this->draw_list_num;
  if ( (_WORD)v1 )
  {
    result = 20;
    if ( (signed __int16)v1 > 0 )
    {
      v3 = (char *)&this->draw_list->sprite;
      v1 = (signed __int16)v1;
      do
      {
        if ( *(_BYTE *)(*(_DWORD *)v3 + 41) < (unsigned __int8)result )
          result = *(_BYTE *)(*(_DWORD *)v3 + 41);
        v3 += 16;
        --v1;
      }
      while ( v1 );
    }
  }
  else
  {
    result = this->draw_level;
  }
  return result;
}

//----- (004C0C90) --------------------------------------------------------
char __thiscall RGE_Sprite::hit_test(RGE_Sprite *this, __int16 x, __int16 y, int facet, int frame)
{
  RGE_Sprite *v5; // edi@1
  int v6; // ebx@1
  __int16 v7; // ax@1
  __int16 v8; // cx@3
  char result; // al@9
  __int16 v10; // ax@10
  int index; // [sp+10h] [bp-4h]@12

  v5 = this;
  v6 = 0;
  v7 = this->box_x1;
  if ( (v7 || this->box_x2)
    && ((v8 = this->box_y1) != 0 || v5->box_y2)
    && x >= v7
    && x <= v5->box_x2
    && y >= v8
    && y <= v5->box_y2 )
  {
    result = 1;
  }
  else
  {
    v10 = v5->draw_list_num;
    if ( v10 > 0 && v5->draw_list )
    {
      index = 0;
      if ( v10 <= 0 )
      {
LABEL_15:
        result = 0;
      }
      else
      {
        while ( !RGE_Sprite::shape_hit_test(
                   v5->draw_list[v6].sprite,
                   x - v5->draw_list[v6].offset_x,
                   y - v5->draw_list[v6].offset_y,
                   facet * v5->draw_list[v6].sprite->facet_num / v5->facet_num,
                   frame) )
        {
          ++v6;
          if ( ++index >= v5->draw_list_num )
            goto LABEL_15;
        }
        result = 1;
      }
    }
    else
    {
      result = RGE_Sprite::shape_hit_test(v5, x, y, facet, frame);
    }
  }
  return result;
}

//----- (004C0D80) --------------------------------------------------------
char __thiscall RGE_Sprite::shape_hit_test(RGE_Sprite *this, __int16 x, __int16 y, int facet, int frame)
{
  RGE_Sprite *v5; // esi@1
  unsigned int v6; // edi@3
  TShape *v7; // eax@3
  TShape *v8; // eax@4
  unsigned int v9; // eax@6
  int v10; // eax@7
  char v11; // bl@9
  TShape *v12; // ecx@12
  bool v13; // zf@15
  bool v14; // sf@15
  unsigned __int8 v15; // of@15
  char result; // al@21
  TShape *v17; // ecx@22
  char *fname; // [sp+Ch] [bp-28h]@3
  int shape_num; // [sp+10h] [bp-24h]@9
  int xmin; // [sp+14h] [bp-20h]@13
  int xmax; // [sp+18h] [bp-1Ch]@13
  int ymin; // [sp+1Ch] [bp-18h]@13
  int ymax; // [sp+20h] [bp-14h]@13
  TShape *v24; // [sp+24h] [bp-10h]@3
  int v25; // [sp+30h] [bp-4h]@3

  v5 = this;
  if ( !this->shape )
  {
    if ( !this->loaded )
      return 0;
    fname = 0;
    addstring(&fname, this->pict_name, a_shp);
    v6 = debug_timeGetTime();
    v7 = (TShape *)operator new(0x20u);
    v24 = v7;
    v25 = 0;
    if ( v7 )
      TShape::TShape(v7, fname, v5->resource_id);
    else
      v8 = 0;
    v25 = -1;
    v5->shape = v8;
    v9 = debug_timeGetTime();
    RGE_Base_Game::add_to_timing(rge_base_game, 11, v9 - v6);
    free(fname);
  }
  v10 = frame;
  if ( frame > v5->frame_num )
    v10 = 0;
  v11 = RGE_Sprite::get_facetindex(v5, facet, v10, &shape_num);
  if ( !v5->transparent_picking_flag )
    return 0;
  if ( v5->transparent_picking_flag != 1 )
  {
    if ( v5->transparent_picking_flag == 2 )
    {
      v12 = v5->shape;
      if ( v12 )
      {
        TShape::shape_minmax(v12, &xmin, &ymin, &xmax, &ymax, shape_num);
        if ( v11 )
        {
          if ( x >= -xmax )
          {
            v15 = __OFSUB__(x, -xmin);
            v13 = x == -xmin;
            v14 = x + xmin < 0;
LABEL_18:
            if ( (unsigned __int8)(v14 ^ v15) | v13 && y >= ymin && y <= ymax )
              return 1;
            return 0;
          }
        }
        else if ( x >= xmin )
        {
          v15 = __OFSUB__(x, xmax);
          v13 = x == xmax;
          v14 = x - xmax < 0;
          goto LABEL_18;
        }
      }
    }
    return 0;
  }
  v17 = v5->shape;
  if ( !v17 )
    return 0;
  if ( v11 )
    result = TShape::shape_check(v17, -x, y, shape_num);
  else
    result = TShape::shape_check(v17, x, y, shape_num);
  return result;
}

//----- (004C0F90) --------------------------------------------------------
void __thiscall RGE_Sprite::make_active_sprite(RGE_Sprite *this)
{
  RGE_Sprite *v1; // esi@1
  RGE_Active_Animated_Sprite *v2; // eax@2
  RGE_Active_Sprite *v3; // eax@4

  v1 = this;
  if ( this->flag & 1 )
  {
    v2 = (RGE_Active_Animated_Sprite *)operator new(0x28u);
    if ( v2 )
      RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(v2, v1);
  }
  else
  {
    v3 = (RGE_Active_Sprite *)operator new(0x14u);
    if ( v3 )
      RGE_Active_Sprite::RGE_Active_Sprite(v3, v1);
  }
}

//----- (004C1030) --------------------------------------------------------
int __thiscall RGE_Sprite::check_for_shadows(RGE_Sprite *this)
{
  int v1; // edx@1
  RGE_Picture_List *v2; // esi@2
  int v3; // eax@3
  int v4; // ecx@4

  LOWORD(v1) = this->draw_list_num;
  if ( (signed __int16)v1 > 0 && (v2 = this->draw_list) != 0 )
  {
    v1 = (signed __int16)v1;
    v3 = 0;
    if ( (signed __int16)v1 > 0 )
    {
      v4 = (int)&v2->sprite;
      while ( *(_BYTE *)(*(_DWORD *)v4 + 41) )
      {
        ++v3;
        v4 += 16;
        if ( v3 >= v1 )
          return 0;
      }
      return 1;
    }
  }
  else if ( !this->draw_level )
  {
    return 1;
  }
  return 0;
}

//----- (004C1080) --------------------------------------------------------
void __thiscall RGE_Sprite::update(RGE_Sprite *this, unsigned int curr_time)
{
  RGE_Sprite *v2; // esi@1
  TShape *v3; // edi@2
  int v4; // ecx@3
  int v5; // ebx@5
  signed int v6; // eax@5

  v2 = this;
  if ( this->loaded )
  {
    v3 = this->shape;
    if ( v3 )
    {
      v4 = this->delta_time;
      if ( (double)v2->delta_time == 0.0 )
      {
        v2->last_time = curr_time;
        v2->delta_time = 1;
      }
      else
      {
        v5 = v2->last_time;
        v2->last_time = curr_time;
        v6 = v4 + curr_time - v5;
        v2->delta_time = v6;
        if ( v6 >= 180000 )
        {
          if ( v3 )
          {
            TShape::~TShape(v3);
            operator delete(v3);
          }
          v2->shape = 0;
        }
      }
    }
  }
}
