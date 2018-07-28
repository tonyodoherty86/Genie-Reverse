
//----- (0050F410) --------------------------------------------------------
void __thiscall TRIBE_Map::TRIBE_Map(TRIBE_Map *this, int infile, RGE_Sound **sound, char setup)
{
  TRIBE_Map *v4; // esi@1
  TRIBE_Map *v5; // eax@3
  signed int v6; // ecx@3

  v4 = this;
  RGE_Map::RGE_Map((RGE_Map *)&this->vfptr, infile, infile, sound, 0);
  v4->vfptr = (RGE_MapVtbl *)&TRIBE_Map::`vftable';
  if( setup )
    TRIBE_Map::data_load_random_map(v4, infile);
  v5 = (TRIBE_Map *)((char *)v4 + 36380);
  v4->old_cliff_x = -1;
  v4->old_cliff_y = -1;
  v4->safe_cliff_x = -1;
  v4->safe_cliff_y = -1;
  v6 = 256;
  do
  {
    LODWORD(v5[-1].cliff_master_table[255].offset_y) = 0;
    v5->vfptr = 0;
    v5[-1].cliff_master_table[255].info.info[1] = 0;
    v5[-1].cliff_master_table[255].info.info[2] = 0;
    v5[-1].cliff_master_table[255].info.info[3] = 0;
    LODWORD(v5[-1].cliff_master_table[255].offset_x) = 0;
    v5[-1].cliff_master_table[255].facet = -1;
    v5[-1].cliff_master_table[255].id2 = -1;
    v5[-1].cliff_master_table[255].facet2 = -1;
    v5[-1].cliff_master_table[255].info.info[0] = -1;
    v5 = (TRIBE_Map *)((char *)v5 + 40);
    --v6;
  }
  while( v6 );
  TRIBE_Map::setup_cliff_type(v4, 1, 0, 0, 0, 264, 16, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 1, 0, 0, 264, 18, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 0, 1, 0, 264, 17, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 0, 0, 1, 264, 19, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, -1, 0, 0, 0, 266, 20, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, -1, 0, 0, 265, 22, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 0, -1, 0, 266, 21, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 0, 0, -1, 265, 23, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, -1, 1, 0, 0, 270, 0, -1, -1, 1.5, 2.0);
  TRIBE_Map::setup_cliff_type(v4, 0, -1, -1, 0, 272, 9, -1, -1, 1.0, 2.0);
  TRIBE_Map::setup_cliff_type(v4, 0, 0, 1, -1, 268, 6, -1, -1, 1.0, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 1, 0, 0, 1, 264, 3, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 1, -1, 0, 0, 267, 12, -1, -1, 2.0, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 1, 1, 0, 264, 15, -1, -1, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 0, -1, 1, 269, 14, -1, -1, 1.5, 1.0);
  TRIBE_Map::setup_cliff_type(v4, -1, 0, 0, -1, 271, 13, -1, -1, 2.0, 1.0);
  TRIBE_Map::setup_cliff_type(v4, 1, 0, 1, 0, 264, 4, 264, 5, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, 1, 0, 1, 264, 1, 264, 2, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, -1, 0, -1, 0, 266, 11, 266, 10, 1.5, 1.5);
  TRIBE_Map::setup_cliff_type(v4, 0, -1, 0, -1, 265, 8, 265, 7, 1.5, 1.5);
}
// 5767C8: using guessed type int (__thiscall *TRIBE_Map::`vftable')(void *Memory, unsigned int __flags);

//----- (0050F740) --------------------------------------------------------
TRIBE_Map *__thiscall TRIBE_Map::`vector deleting destructor'(TRIBE_Map *this, unsigned int __flags)
{
  TRIBE_Map *v2; // esi@1

  v2 = this;
  TRIBE_Map::~TRIBE_Map(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0050F760) --------------------------------------------------------
void __thiscall TRIBE_Map::TRIBE_Map(TRIBE_Map *this, char *border_tbl, char *overlay_tbl, char *terrain_tbl, char *map_tbl, __int16 TileWid, __int16 TileHgt, __int16 ElevHgt, RGE_Sound **sound)
{
  TRIBE_Map *v9; // esi@1

  v9 = this;
  RGE_Map::RGE_Map((RGE_Map *)&this->vfptr, border_tbl, terrain_tbl, map_tbl, TileWid, TileHgt, ElevHgt, sound);
  v9->vfptr = (RGE_MapVtbl *)&TRIBE_Map::`vftable';
}
// 5767C8: using guessed type int (__thiscall *TRIBE_Map::`vftable')(void *Memory, unsigned int __flags);

//----- (0050F7A0) --------------------------------------------------------
void __thiscall TRIBE_Map::~TRIBE_Map(TRIBE_Map *this)
{
  this->vfptr = (RGE_MapVtbl *)&TRIBE_Map::`vftable';
  RGE_Map::~RGE_Map((RGE_Map *)&this->vfptr);
}
// 5767C8: using guessed type int (__thiscall *TRIBE_Map::`vftable')(void *Memory, unsigned int __flags);

//----- (0050F7B0) --------------------------------------------------------
void __thiscall TRIBE_Map::save(TRIBE_Map *this, int outfile)
{
  RGE_Map::save((RGE_Map *)&this->vfptr, outfile);
}

//----- (0050F7C0) --------------------------------------------------------
void __thiscall TRIBE_Map::map_generate(TRIBE_Map *this, RGE_Player *owner, RGE_Game_World *gworld, RGE_Player_Info *player_info, char *zone_terrain)
{
  this->rge_game_world = gworld;
  this->rge_player = owner;
  this->zones = zone_terrain;
  TRIBE_Map::map_generate(this, player_info);
}

//----- (0050F800) --------------------------------------------------------
void __thiscall TRIBE_Map::data_load_random_map(TRIBE_Map *this, int infile)
{
  TRIBE_Map *v2; // esi@1
  TRIBE_RMM_Database_Controller *v3; // eax@1
  RGE_RMM_Database_Controller *v4; // eax@2

  v2 = this;
  v3 = (TRIBE_RMM_Database_Controller *)operator new(0x4F5Cu);
  if( v3 )
    TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(v3, infile);
  else
    v4 = 0;
  v2->random_map = v4;
}

//----- (0050F860) --------------------------------------------------------
void __thiscall TRIBE_Map::load_random_map(TRIBE_Map *this, char *rmm_map_file, char *rmm_land_file, char *rmm_terr_file, char *rmm_obj_file)
{
  TRIBE_Map *v5; // esi@1
  TRIBE_RMM_Database_Controller *v6; // eax@1
  RGE_RMM_Database_Controller *v7; // eax@2

  v5 = this;
  v6 = (TRIBE_RMM_Database_Controller *)operator new(0x4F5Cu);
  if( v6 )
    TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(
      v6,
      rmm_land_file,
      rmm_terr_file,
      rmm_obj_file,
      rmm_map_file);
  else
    v7 = 0;
  v5->random_map = v7;
}

//----- (0050F8D0) --------------------------------------------------------
void __thiscall TRIBE_Map::check_tile_for_forest_change(TRIBE_Map *this, __int16 x, __int16 y, RGE_Game_World *world)
{
  TRIBE_Map *v4; // esi@1
  RGE_Tile **v5; // ecx@1
  __int16 v6; // di@1
  __int16 v7; // bp@1
  int v8; // edx@1
  char v9; // bl@1
  char v10; // al@9
  int v11; // eax@11
  __int16 i; // si@19
  RGE_Tile **v13; // ecx@26
  int v14; // eax@26
  int v15; // ebp@27
  RGE_Tile **v16; // edi@27
  int v17; // ebp@27
  _BYTE *v18; // edx@29
  int v19; // ecx@29
  char v20; // al@30
  RGE_Tile *v21; // edx@34
  char success; // [sp+13h] [bp-11h]@1
  __int16 x0; // [sp+14h] [bp-10h]@1
  __int16 x1; // [sp+18h] [bp-Ch]@1
  TRIBE_Map *v25; // [sp+1Ch] [bp-8h]@1
  __int16 y1; // [sp+20h] [bp-4h]@1

  v4 = this;
  v5 = this->map_row_offset;
  v6 = y - 1;
  v7 = y + 1;
  v25 = v4;
  y1 = y + 1;
  v8 = (int)&v5[y][x].screen_xpos;
  x0 = x - 1;
  v9 = 0;
  x1 = x + 1;
  success = 0;
  if( (signed __int16)(x - 1) < 0 )
    x0 = 0;
  if( v6 < 0 )
    v6 = 0;
  if( (signed __int16)(x + 1) >= v4->map_width )
    x1 = LOWORD(v4->map_width) - 1;
  if( v7 >= v4->map_height )
  {
    v7 = LOWORD(v4->map_height) - 1;
    y1 = LOWORD(v4->map_height) - 1;
  }
  v10 = *(_BYTE *)(v8 + 5) & 0x1F;
  if( v10 == 10 )
  {
    v13 = &v5[v6];
    v14 = (int)&(*v13)[x0].screen_xpos;
    if( v6 <= v7 )
    {
      v15 = v7 - v6;
      v16 = v13;
      v17 = v15 + 1;
      do
      {
        if( x0 <= x1 )
        {
          v18 = (_BYTE *)(v14 + 5);
          v19 = x1 - x0 + 1;
          do
          {
            v20 = *v18 & 0x1F;
            if( v20 != 10 && v20 != 18 )
              success = 1;
            v18 += 24;
            --v19;
          }
          while( v19 );
        }
        v21 = v16[1];
        ++v16;
        v14 = (int)&v21[x0].screen_xpos;
        --v17;
      }
      while( v17 );
    }
    if( success )
      TRIBE_Map::change_terrain(v4, x, y, 18, world);
  }
  else if( v10 == 18 )
  {
    v11 = *(_DWORD *)(v8 + 16);
    if( v11 )
    {
      do
      {
        if( *(_WORD *)(*(_DWORD *)(*(_DWORD *)v11 + 8) + 20) == 15 && *(_BYTE *)(*(_DWORD *)v11 + 72) < 8u )
          v9 = 1;
        v11 = *(_DWORD *)(v11 + 4);
      }
      while( v11 );
      v7 = y1;
    }
    if( !v9 )
    {
      TRIBE_Map::change_terrain(v4, x, y, 0, world);
      for( ; v6 <= v7; ++v6 )
      {
        for( i = x0; i <= x1; ++i )
        {
          if( i != x || v6 != y )
            TRIBE_Map::check_tile_for_forest_change(v25, i, v6, world);
        }
      }
    }
  }
}

//----- (0050FA90) --------------------------------------------------------
void __thiscall TRIBE_Map::change_terrain(TRIBE_Map *this, __int16 map_col, __int16 map_row, char new_terrain, RGE_Game_World *world)
{
  __int16 v5; // di@1
  __int16 v6; // bp@1
  int v7; // esi@1
  RGE_Tile *v8; // eax@1
  __int16 v9; // ax@1
  RGE_Player *v10; // eax@3
  __int16 v11; // di@9
  int v12; // eax@12
  int v13; // ebp@21
  int v14; // esi@22
  unsigned __int8 v15; // bl@22
  char v16; // bl@22
  bool v17; // zf@29
  bool v18; // sf@29
  unsigned __int8 v19; // of@29
  TRIBE_Map *v20; // [sp+10h] [bp-1Ch]@1
  int col; // [sp+14h] [bp-18h]@21
  __int16 col2; // [sp+18h] [bp-14h]@16
  __int16 col1; // [sp+1Ch] [bp-10h]@9
  int row; // [sp+20h] [bp-Ch]@19
  int v25; // [sp+24h] [bp-8h]@19
  __int16 row2; // [sp+28h] [bp-4h]@18
  RGE_Player *map_cola; // [sp+30h] [bp+4h]@3
  RGE_Player *player; // [sp+34h] [bp+8h]@18
  char new_terraina; // [sp+38h] [bp+Ch]@22

  v5 = map_col;
  v20 = this;
  v6 = map_row;
  v7 = map_col;
  v8 = &this->map_row_offset[map_row][map_col];
  *((_BYTE *)v8 + 5) ^= (*((_BYTE *)v8 + 5) ^ new_terrain) & 0x1F;
  v9 = world->curr_player;
  if( v9 <= 0 || v9 >= world->player_num )
  {
    map_cola = 0;
    v10 = 0;
  }
  else
  {
    v10 = world->players[v9];
    map_cola = v10;
  }
  if( v10 && world->game_state != 3 )
    RGE_Tile_List::add_node(&v10->diam_tile_list, v7, map_row);
  if( v5 )
  {
    col1 = v7 - 1;
    v11 = v7 - 1;
  }
  else
  {
    v11 = 0;
    col1 = 0;
  }
  if( map_row )
    v12 = map_row - 1;
  else
    v12 = 0;
  if( v7 != v20->map_width - 1 )
    LOWORD(v7) = v7 + 1;
  col2 = v7;
  if( map_row != v20->map_height - 1 )
    v6 = map_row + 1;
  row2 = v6;
  player = (RGE_Player *)v12;
  if( (signed __int16)v12 <= v6 )
  {
    row = (signed __int16)v12;
    v25 = (signed __int16)v12;
    do
    {
      if( v11 <= col2 )
      {
        col = v11;
        v13 = v11;
        do
        {
          v14 = (int)&v20->map_row_offset[v25][v13].screen_xpos;
          v15 = *(_BYTE *)(v14 + 6);
          new_terraina = v15 >> 4;
          v16 = v15 & 0xF;
          RGE_Map::get_border_type((RGE_Map *)&v20->vfptr, v11, (__int16)player);
          if( map_cola
            && ((*(_BYTE *)(v14 + 6) & 0xF) != v16 || *(_BYTE *)(v14 + 6) >> 4 != new_terraina)
            && world->game_state != 3 )
          {
            RGE_Tile_List::add_node(&map_cola->diam_tile_list, col, row);
          }
          ++v11;
          ++v13;
          ++col;
        }
        while( v11 <= col2 );
        v11 = col1;
      }
      v19 = __OFSUB__((_WORD)player + 1, row2);
      v17 = (_WORD)player + 1 == row2;
      v18 = (signed __int16)((_WORD)player + 1 - row2) < 0;
      player = (RGE_Player *)((char *)player + 1);
      ++row;
      ++v25;
    }
    while( (unsigned __int8)(v18 ^ v19) | v17 );
  }
}

//----- (0050FC40) --------------------------------------------------------
char __thiscall TRIBE_Map::do_terrain_brush(TRIBE_Map *this, int x, int y, int brush_size, char terrain_id)
{
  TRIBE_Map *v5; // esi@1
  int v6; // ebp@1
  int v7; // edi@1
  int v8; // ebx@1
  int v9; // ecx@1
  bool v10; // sf@1
  int v11; // eax@3
  int v12; // eax@7
  int xa; // [sp+14h] [bp+4h]@1
  int brush_sizea; // [sp+1Ch] [bp+Ch]@1

  v5 = this;
  v6 = brush_size + x;
  v7 = x - brush_size;
  v8 = y - brush_size;
  v9 = brush_size + y;
  v10 = x - brush_size < 0;
  xa = x - brush_size;
  brush_sizea = brush_size + y;
  if( v10 )
  {
    xa = 0;
    v7 = 0;
  }
  v11 = v5->map_width;
  if( v6 >= v11 )
    v6 = v11 - 1;
  if( v8 < 0 )
    v8 = 0;
  v12 = v5->map_height;
  if( v9 >= v12 )
    brush_sizea = v12 - 1;
  if( !TRIBE_Map::water(terrain_id) )
  {
    if( v8 <= brush_sizea )
    {
      while( 1 )
      {
        if( xa <= v6 )
        {
          do
            RGE_Map::set_terrain((RGE_Map *)&v5->vfptr, v5->game_world, v7++, v8, terrain_id, 0, 0);
          while( v7 <= v6 );
        }
        if( ++v8 > brush_sizea )
          break;
        v7 = xa;
      }
    }
    return 1;
  }
  if( v8 > brush_sizea )
    return 1;
  while( 1 )
  {
    if( xa <= v6 )
    {
      do
      {
        if( TRIBE_Map::do_terrain_brush_check(v5, v7, v8) )
          RGE_Map::set_terrain((RGE_Map *)&v5->vfptr, v5->game_world, v7, v8, terrain_id, 0, 0);
        ++v7;
      }
      while( v7 <= v6 );
    }
    if( ++v8 > brush_sizea )
      break;
    v7 = xa;
  }
  return 1;
}

//----- (0050FD40) --------------------------------------------------------
char __thiscall TRIBE_Map::do_terrain_brush_stroke(TRIBE_Map *this, int x1, int y1, int x2, int y2, int brush_size, int terrain_id)
{
  int v7; // edi@2
  int v8; // ebx@2
  int v9; // ebp@5
  int v10; // eax@5
  TRIBE_Map *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  RGE_Map::do_terrain_brush_stroke((RGE_Map *)&this->vfptr, x1, y1, x2, y2, brush_size, terrain_id);
  if( x1 >= x2 )
  {
    v7 = x2 - brush_size;
    v8 = x1 + brush_size;
  }
  else
  {
    v7 = x1 - brush_size;
    v8 = brush_size + x2;
  }
  if( y1 >= y2 )
  {
    v9 = y2 - brush_size;
    v10 = brush_size + y1;
  }
  else
  {
    v9 = y1 - brush_size;
    v10 = brush_size + y2;
  }
  TRIBE_Map::tribe_clean_terrain(v12, v10 + 2, v7 - 2, v9 - 2, v8 + 2, v10 + 2, 1, terrain_id);
  return 1;
}

//----- (0050FDD0) --------------------------------------------------------
char __thiscall TRIBE_Map::do_elevation_brush_stroke(TRIBE_Map *this, int x1, int y1, int x2, int y2, int brush_size, int elevation_height)
{
  int v7; // eax@2
  int v8; // esi@2
  int v9; // edi@2
  int v10; // ebp@5
  int v11; // ecx@5
  int v12; // edi@7
  int v13; // ebp@7
  int v14; // esi@7
  TRIBE_Map *v16; // [sp+10h] [bp-4h]@1
  int y2a; // [sp+24h] [bp+10h]@7

  v16 = this;
  RGE_Map::do_elevation_brush_stroke((RGE_Map *)&this->vfptr, x1, y1, x2, y2, brush_size, elevation_height);
  if( x1 >= x2 )
  {
    v7 = (unsigned __int8)elevation_height;
    v8 = x2 - brush_size - (unsigned __int8)elevation_height;
    v9 = (unsigned __int8)elevation_height + x1 + brush_size;
  }
  else
  {
    v7 = (unsigned __int8)elevation_height;
    v8 = x1 - (brush_size + (unsigned __int8)elevation_height);
    v9 = brush_size + (unsigned __int8)elevation_height + x2;
  }
  if( y1 >= y2 )
  {
    v10 = y2 - brush_size - v7;
    v11 = v7 + brush_size + y1;
  }
  else
  {
    v10 = y1 - (v7 + brush_size);
    v11 = v7 + brush_size + y2;
  }
  v12 = v9 + 2;
  v13 = v10 - 2;
  v14 = v8 - 2;
  y2a = v11 + 2;
  TRIBE_Map::tribe_clean_elevation(v16, v14, v13, v12, v11 + 2);
  TRIBE_Map::tribe_clean_terrain(v16, y2a, v14, v13, v12, y2a, 1, 0);
  return 1;
}

//----- (0050FE90) --------------------------------------------------------
void __thiscall TRIBE_Map::setup_cliff_type(TRIBE_Map *this, int r, int d, int l, int u, int id, int facet, int id2, int facet2, float offset_x, float offset_y)
{
  char *v11; // eax@1

  v11 = (char *)this + 40 * (u + 4 * (l + 4 * (d + 4 * r)) + 85);
  *((_DWORD *)v11 + 9086) = id;
  *((_DWORD *)v11 + 9087) = facet;
  *((_DWORD *)v11 + 9088) = id2;
  *((_DWORD *)v11 + 9089) = facet2;
  *((float *)v11 + 9094) = offset_x;
  *((float *)v11 + 9095) = offset_y;
  *((_DWORD *)&this->vfptr + 10 * (u + 4 * (l + 4 * (d + 4 * r)) + 994)) = r;
  *((_DWORD *)v11 + 9091) = d;
  *((_DWORD *)v11 + 9092) = l;
  *((_DWORD *)v11 + 9093) = u;
}

//----- (0050FF20) --------------------------------------------------------
RGE_Static_ObjectVtbl *__thiscall TRIBE_Map::find_cliff(TRIBE_Map *this, int x, int y)
{
  RGE_Tile **v3; // edi@3
  int v4; // edx@3
  RGE_Tile *v5; // eax@3
  int v6; // esi@3
  RGE_Static_ObjectVtbl *result; // eax@3
  __int16 v8; // cx@4
  int v9; // edx@7
  __int16 v10; // cx@8
  __int16 v11; // cx@12
  __int16 v12; // cx@16

  if( 3 * x + 2 <= this->map_width && 3 * y + 2 <= this->map_height )
  {
    v3 = this->map_row_offset;
    v4 = 3 * x + 1;
    v5 = v3[3 * y + 1];
    v6 = (int)&v5[v4].screen_xpos;
    for( result = (RGE_Static_ObjectVtbl *)v5[v4].objects.list;
          result;
          result = *(RGE_Static_ObjectVtbl **)&result->gap4[0] )
    {
      v8 = *(_WORD *)(*((_DWORD *)result->__vecDelDtor + 2) + 16);
      if( v8 >= 264 && v8 <= 273 )
        return (RGE_Static_ObjectVtbl *)result->__vecDelDtor;
    }
    v9 = (int)&v3[3 * y + 2][v4].screen_xpos;
    for( result = *(RGE_Static_ObjectVtbl **)(v9 + 16); result; result = *(RGE_Static_ObjectVtbl **)&result->gap4[0] )
    {
      v10 = *(_WORD *)(*((_DWORD *)result->__vecDelDtor + 2) + 16);
      if( v10 >= 264 && v10 <= 273 )
        return (RGE_Static_ObjectVtbl *)result->__vecDelDtor;
    }
    for( result = *(RGE_Static_ObjectVtbl **)(v6 + 40); result; result = *(RGE_Static_ObjectVtbl **)&result->gap4[0] )
    {
      v11 = *(_WORD *)(*((_DWORD *)result->__vecDelDtor + 2) + 16);
      if( v11 >= 264 && v11 <= 273 )
        return (RGE_Static_ObjectVtbl *)result->__vecDelDtor;
    }
    result = *(RGE_Static_ObjectVtbl **)(v9 + 40);
    if( result )
    {
      while( 1 )
      {
        v12 = *(_WORD *)(*((_DWORD *)result->__vecDelDtor + 2) + 16);
        if( v12 >= 264 && v12 <= 273 )
          break;
        result = *(RGE_Static_ObjectVtbl **)&result->gap4[0];
        if( !result )
          return result;
      }
      return (RGE_Static_ObjectVtbl *)result->__vecDelDtor;
    }
  }
  return 0;
}

//----- (00510020) --------------------------------------------------------
TRIBE_Cliff_Info *__thiscall TRIBE_Map::get_cliff_info(TRIBE_Map *this, TRIBE_Cliff_Info *result, RGE_Static_Object *__$ReturnUdt)
{
  TRIBE_Cliff_Info *v3; // eax@2
  int v4; // esi@3
  signed int v5; // edx@3
  int v6; // edi@3
  char *v7; // eax@3
  char *v8; // ecx@10

  if( __$ReturnUdt )
  {
    v4 = __$ReturnUdt->facet;
    v5 = 0;
    v6 = __$ReturnUdt->master_obj->id;
    v7 = (char *)&this->cliff_master_table[0].facet;
    while( (*((_DWORD *)v7 - 1) != v6 || *(_DWORD *)v7 != v4)
         && (*((_DWORD *)v7 + 1) != v6 || *((_DWORD *)v7 + 2) != v4) )
    {
      ++v5;
      v7 += 40;
      if( v5 >= 256 )
      {
        v3 = result;
        result->info[0] = 0;
        result->info[1] = 0;
        result->info[2] = 0;
        result->info[3] = 0;
        return v3;
      }
    }
    v8 = (char *)this + 40 * (v5 + 909);
    v3 = result;
    result->info[0] = *(_DWORD *)v8;
    result->info[1] = *((_DWORD *)v8 + 1);
    result->info[2] = *((_DWORD *)v8 + 2);
    result->info[3] = *((_DWORD *)v8 + 3);
  }
  else
  {
    v3 = result;
    result->info[0] = 0;
    result->info[1] = 0;
    result->info[2] = 0;
    result->info[3] = 0;
  }
  return v3;
}

//----- (005100D0) --------------------------------------------------------
bool __thiscall TRIBE_Map::check_cliff_valid(TRIBE_Map *this, TRIBE_Cliff_Info info)
{
  return this->cliff_master_table[info.info[3] + 4 * (info.info[2] + 4 * (info.info[1] + 4 * info.info[0])) + 85].id >= 0;
}

//----- (00510110) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Map::make_new_cliff(TRIBE_Map *this, int x, int y, TRIBE_Cliff_Info info)
{
  TRIBE_Map *v4; // ebx@1
  char *v5; // esi@1
  int v6; // eax@3
  signed int v7; // edi@7
  int v8; // esi@7
  bool v9; // sf@9
  unsigned __int8 v10; // of@9
  RGE_Static_Object *result; // eax@12
  int id; // [sp+14h] [bp-14h]@3
  RGE_Static_Object *new_cliff; // [sp+18h] [bp-10h]@6
  int facet; // [sp+1Ch] [bp-Ch]@3
  int xa; // [sp+2Ch] [bp+4h]@6
  int i; // [sp+30h] [bp+8h]@1
  float world_y; // [sp+34h] [bp+Ch]@1

  v4 = this;
  v5 = (char *)this + 40 * (info.info[3] + 4 * (info.info[2] + 4 * (info.info[1] + 4 * info.info[0])) + 85);
  world_y = (double)(3 * x) + *((float *)v5 + 9094);
  *(float *)&i = (double)(3 * y) + *((float *)v5 + 9095);
  if( *((_DWORD *)v5 + 9088) <= -1 || 2 * debug_rand(aCMsdevWorkA_28, 545) <= 0x7FFF )
  {
    facet = *((_DWORD *)v5 + 9087);
    id = *((_DWORD *)v5 + 9086);
    v6 = *((_DWORD *)v5 + 9086);
  }
  else
  {
    v6 = *((_DWORD *)v5 + 9088);
    id = *((_DWORD *)v5 + 9088);
    facet = *((_DWORD *)v5 + 9089);
  }
  if( v6 < 0 )
  {
    result = 0;
  }
  else
  {
    new_cliff = (RGE_Static_Object *)(*(int (__stdcall **)(int, float, int, _DWORD, _DWORD))(**(_DWORD **)v4->game_world->players
                                                                                           + 148))(
                                       v6,
                                       COERCE_FLOAT(LODWORD(world_y)),
                                       i,
                                       0,
                                       0);
    xa = -1;
    do
    {
      v7 = 3;
      v8 = (unsigned __int64)(signed __int64)*(float *)&i - 1;
      do
      {
        RGE_Tile_List::add_node(
          &v4->game_world->players[v4->game_world->curr_player]->diam_tile_list,
          xa + (unsigned __int64)(signed __int64)world_y,
          v8++);
        --v7;
      }
      while( v7 );
      v10 = __OFSUB__(xa + 1, 2);
      v9 = xa++ - 1 < 0;
    }
    while( v9 ^ v10 );
    if( new_cliff )
      new_cliff->facet = facet;
    TRIBE_World::check_destructables((TRIBE_World *)v4->game_world, 0, id, world_y, *(float *)&i, 1);
    result = new_cliff;
  }
  return result;
}

//----- (005102A0) --------------------------------------------------------
void __thiscall TRIBE_Map::remove_cliff_edge(TRIBE_Map *this, int x, int y, int direction)
{
  TRIBE_Map *v4; // esi@1
  RGE_Static_Object *v5; // eax@9
  RGE_Static_Object *v6; // ebx@9
  TRIBE_Cliff_Info *v7; // eax@9
  int v8; // edx@9
  signed int v9; // ebp@10
  signed int v10; // esi@11
  TRIBE_Cliff_Info v11; // ST08_16@14
  TRIBE_Map *v12; // [sp+10h] [bp-24h]@1
  TRIBE_Cliff_Info cliff_info; // [sp+14h] [bp-20h]@9
  TRIBE_Cliff_Info result; // [sp+24h] [bp-10h]@9

  v4 = this;
  v12 = this;
  switch ( direction )
  {
    case 0:
      if( ++x < this->map_width )
        goto LABEL_9;
      break;
    case 2:
      if( x > 0 )
      {
        --x;
        goto LABEL_9;
      }
      break;
    case 3:
      if( y > 0 )
      {
        --y;
        goto LABEL_9;
      }
      break;
    case 1:
      if( ++y < this->map_height )
        goto LABEL_9;
      break;
    default:
LABEL_9:
      v5 = (RGE_Static_Object *)TRIBE_Map::find_cliff(this, x, y);
      v6 = v5;
      v7 = TRIBE_Map::get_cliff_info(v4, &result, v5);
      cliff_info.info[0] = v7->info[0];
      cliff_info.info[1] = v7->info[1];
      v8 = v7->info[3];
      cliff_info.info[2] = v7->info[2];
      cliff_info.info[3] = v8;
      if( v6 )
      {
        v9 = -1;
        do
        {
          v10 = -1;
          do
            RGE_Tile_List::add_node(
              &v12->game_world->players[v12->game_world->curr_player]->diam_tile_list,
              (unsigned __int64)(signed __int64)v6->world_x + v9,
              (unsigned __int64)(signed __int64)v6->world_y + v10++);
          while( v10 < 2 );
          ++v9;
        }
        while( v9 < 2 );
        v6->vfptr->__vecDelDtor(v6, 1u);
        cliff_info.info[TRIBE_Map::reverse_cliff_direction(direction)] = 0;
        *(_QWORD *)&v11.info[0] = *(_QWORD *)&cliff_info.info[0];
        *(_QWORD *)&v11.info[2] = *(_QWORD *)&cliff_info.info[2];
        TRIBE_Map::make_new_cliff(v12, x, y, v11);
      }
      break;
  }
}

//----- (00510410) --------------------------------------------------------
int __stdcall TRIBE_Map::reverse_cliff_direction(int direction)
{
  int result; // eax@1

  result = direction + 2;
  if( direction + 2 >= 4 )
    result = direction - 2;
  return result;
}

//----- (00510430) --------------------------------------------------------
int __thiscall TRIBE_Map::add_cliff_edge(TRIBE_Map *this, int x, int y, int direction, int facing, int save_direction)
{
  TRIBE_Map *v6; // edi@1
  RGE_Static_Object *v7; // ebx@1
  signed int v8; // ebp@1
  int result; // eax@1
  signed int i; // esi@6
  int v11; // ebp@12
  int v12; // esi@15
  TRIBE_Cliff_Info *v13; // ebx@15
  int v14; // edx@20
  signed int v15; // eax@20
  TRIBE_Cliff_Info *v16; // ecx@20
  signed int v17; // eax@26
  TRIBE_Cliff_Info *v18; // edx@26
  char *v19; // esi@36
  TRIBE_Cliff_Info v20; // ST08_16@36
  char *v21; // esi@39
  TRIBE_Cliff_Info v22; // ST08_16@39
  TRIBE_Cliff_Info v23; // ST08_16@41
  int v24; // esi@42
  TRIBE_Cliff_Info *v25; // ebx@42
  int v26; // esi@48
  char *v27; // ebx@49
  TRIBE_Cliff_Info v28; // ST08_16@49
  char *v29; // ebx@54
  TRIBE_Cliff_Info v30; // ST08_16@54
  TRIBE_Cliff_Info v31; // ST08_16@58
  char *v32; // ebx@60
  TRIBE_Cliff_Info v33; // ST08_16@60
  char *v34; // ebx@65
  TRIBE_Cliff_Info v35; // ST08_16@65
  TRIBE_Cliff_Info v36; // ST08_16@69
  TRIBE_Cliff_Info *v37; // ebx@70
  TRIBE_Cliff_Info v38; // ST08_16@79
  int possible_facing1; // [sp+10h] [bp-24h]@1
  signed int possible_direction1; // [sp+14h] [bp-20h]@1
  int possible_facing2; // [sp+18h] [bp-1Ch]@1
  signed int possible_direction2; // [sp+1Ch] [bp-18h]@1
  TRIBE_Map *v43; // [sp+20h] [bp-14h]@1
  TRIBE_Cliff_Info cliff_info; // [sp+24h] [bp-10h]@1

  v6 = this;
  v43 = this;
  v7 = (RGE_Static_Object *)TRIBE_Map::find_cliff(this, x, y);
  TRIBE_Map::get_cliff_info(v6, &cliff_info, v7);
  v8 = -1;
  possible_facing1 = 0;
  result = cliff_info.info[direction];
  possible_direction1 = -1;
  possible_direction2 = -1;
  possible_facing2 = 0;
  if( !result )
    goto LABEL_82;
  if( !facing )
    return result;
  if( facing == result )
  {
    result = facing;
  }
  else
  {
LABEL_82:
    if( v7 )
    {
      for( i = -1; ; i = -1 )
      {
        while( 1 )
        {
          RGE_Tile_List::add_node(
            &v6->game_world->players[v6->game_world->curr_player]->diam_tile_list,
            (unsigned __int64)(signed __int64)v7->world_x + v8,
            (unsigned __int64)(signed __int64)v7->world_y + i++);
          if( i >= 2 )
            break;
          v6 = v43;
        }
        if( ++v8 >= 2 )
          break;
        v6 = v43;
      }
      v7->vfptr->__vecDelDtor(v7, 1u);
      v6 = v43;
    }
    v11 = save_direction;
    if( save_direction == direction )
      v11 = -1;
    if( v11 < 0 )
    {
      v14 = 0;
      v15 = 0;
      v16 = &cliff_info;
      do
      {
        if( v16->info[0] && v15 != direction )
          ++v14;
        ++v15;
        v16 = (TRIBE_Cliff_Info *)((char *)v16 + 4);
      }
      while( v15 < 4 );
      if( v14 == 2 )
      {
        v17 = 0;
        v18 = &cliff_info;
        do
        {
          if( v18->info[0] && v17 != direction )
          {
            if( possible_direction1 >= 0 )
            {
              possible_direction2 = v17;
              possible_facing2 = v18->info[0];
            }
            else
            {
              possible_direction1 = v17;
              possible_facing1 = v18->info[0];
            }
            v18->info[0] = 0;
          }
          ++v17;
          v18 = (TRIBE_Cliff_Info *)((char *)v18 + 4);
        }
        while( v17 < 4 );
      }
    }
    else
    {
      v12 = 0;
      v13 = &cliff_info;
      do
      {
        if( v12 != v11 )
        {
          TRIBE_Map::remove_cliff_edge(v6, x, y, v12);
          v13->info[0] = 0;
        }
        ++v12;
        v13 = (TRIBE_Cliff_Info *)((char *)v13 + 4);
      }
      while( v12 < 4 );
    }
    if( facing )
    {
      cliff_info.info[direction] = facing;
      if( possible_direction1 > -1 )
      {
        v19 = (char *)&cliff_info + 4 * possible_direction1;
        *(_DWORD *)v19 = possible_facing1;
        *(_QWORD *)&v20.info[0] = *(_QWORD *)&cliff_info.info[0];
        *(_QWORD *)&v20.info[2] = *(_QWORD *)&cliff_info.info[2];
        if( !TRIBE_Map::check_cliff_valid(v6, v20) )
        {
          *(_DWORD *)v19 = 0;
          TRIBE_Map::remove_cliff_edge(v6, x, y, possible_direction1);
        }
      }
      if( possible_direction2 > -1 )
      {
        v21 = (char *)&cliff_info + 4 * possible_direction2;
        *(_DWORD *)v21 = possible_facing2;
        *(_QWORD *)&v22.info[0] = *(_QWORD *)&cliff_info.info[0];
        *(_QWORD *)&v22.info[2] = *(_QWORD *)&cliff_info.info[2];
        if( !TRIBE_Map::check_cliff_valid(v6, v22) )
        {
          *(_DWORD *)v21 = 0;
          TRIBE_Map::remove_cliff_edge(v6, x, y, possible_direction2);
        }
      }
      *(_QWORD *)&v23.info[0] = *(_QWORD *)&cliff_info.info[0];
      *(_QWORD *)&v23.info[2] = *(_QWORD *)&cliff_info.info[2];
      if( !TRIBE_Map::check_cliff_valid(v6, v23) )
      {
        v24 = 0;
        v25 = &cliff_info;
        do
        {
          if( v24 != direction )
          {
            if( v25->info[0] )
            {
              TRIBE_Map::remove_cliff_edge(v6, x, y, v24);
              v25->info[0] = 0;
            }
          }
          ++v24;
          v25 = (TRIBE_Cliff_Info *)((char *)v25 + 4);
        }
        while( v24 < 4 );
      }
    }
    else
    {
      facing = 1;
      v26 = 0;
      cliff_info.info[direction] = 1;
      if( possible_direction1 > -1 )
      {
        v27 = (char *)&cliff_info + 4 * possible_direction1;
        *(_DWORD *)v27 = possible_facing1;
        *(_QWORD *)&v28.info[0] = *(_QWORD *)&cliff_info.info[0];
        *(_QWORD *)&v28.info[2] = *(_QWORD *)&cliff_info.info[2];
        if( TRIBE_Map::check_cliff_valid(v6, v28) )
        {
          v26 = 1;
          possible_facing1 = 0;
        }
        else
        {
          *(_DWORD *)v27 = 0;
        }
      }
      if( !v26 )
      {
        if( possible_direction2 > -1 )
        {
          v29 = (char *)&cliff_info + 4 * possible_direction2;
          *(_DWORD *)v29 = possible_facing2;
          *(_QWORD *)&v30.info[0] = *(_QWORD *)&cliff_info.info[0];
          *(_QWORD *)&v30.info[2] = *(_QWORD *)&cliff_info.info[2];
          if( TRIBE_Map::check_cliff_valid(v6, v30) )
          {
            v26 = 1;
            possible_facing2 = 0;
          }
          else
          {
            *(_DWORD *)v29 = 0;
          }
        }
        if( !v26 )
        {
          *(_QWORD *)&v31.info[0] = *(_QWORD *)&cliff_info.info[0];
          *(_QWORD *)&v31.info[2] = *(_QWORD *)&cliff_info.info[2];
          if( !TRIBE_Map::check_cliff_valid(v6, v31) )
          {
            cliff_info.info[direction] = -1;
            facing = -1;
            if( possible_direction1 > -1 )
            {
              v32 = (char *)&cliff_info + 4 * possible_direction1;
              *(_DWORD *)v32 = possible_facing1;
              *(_QWORD *)&v33.info[0] = *(_QWORD *)&cliff_info.info[0];
              *(_QWORD *)&v33.info[2] = *(_QWORD *)&cliff_info.info[2];
              if( TRIBE_Map::check_cliff_valid(v6, v33) )
              {
                v26 = 1;
                possible_facing1 = 0;
              }
              else
              {
                *(_DWORD *)v32 = 0;
              }
            }
            if( !v26 )
            {
              if( possible_direction2 > -1 )
              {
                v34 = (char *)&cliff_info + 4 * possible_direction2;
                *(_DWORD *)v34 = possible_facing2;
                *(_QWORD *)&v35.info[0] = *(_QWORD *)&cliff_info.info[0];
                *(_QWORD *)&v35.info[2] = *(_QWORD *)&cliff_info.info[2];
                if( TRIBE_Map::check_cliff_valid(v6, v35) )
                {
                  v26 = 1;
                  possible_facing2 = 0;
                }
                else
                {
                  *(_DWORD *)v34 = 0;
                }
              }
              if( !v26 )
              {
                *(_QWORD *)&v36.info[0] = *(_QWORD *)&cliff_info.info[0];
                *(_QWORD *)&v36.info[2] = *(_QWORD *)&cliff_info.info[2];
                if( !TRIBE_Map::check_cliff_valid(v6, v36) )
                {
                  v37 = &cliff_info;
                  do
                  {
                    if( v26 != direction && v37->info[0] )
                    {
                      TRIBE_Map::remove_cliff_edge(v6, x, y, v26);
                      v37->info[0] = 0;
                    }
                    ++v26;
                    v37 = (TRIBE_Cliff_Info *)((char *)v37 + 4);
                  }
                  while( v26 < 4 );
                }
              }
            }
          }
        }
      }
      if( possible_facing1 )
        TRIBE_Map::remove_cliff_edge(v6, x, y, possible_direction1);
      if( possible_facing2 )
        TRIBE_Map::remove_cliff_edge(v6, x, y, possible_direction2);
    }
    *(_QWORD *)&v38.info[0] = *(_QWORD *)&cliff_info.info[0];
    *(_QWORD *)&v38.info[2] = *(_QWORD *)&cliff_info.info[2];
    TRIBE_Map::make_new_cliff(v6, x, y, v38);
    result = facing;
  }
  return result;
}

//----- (00510960) --------------------------------------------------------
void __thiscall TRIBE_Map::delete_cliff(TRIBE_Map *this, int x, int y)
{
  TRIBE_Map *v3; // ebp@1
  RGE_Static_Object *v4; // ebx@1
  TRIBE_Cliff_Info *v5; // eax@2
  int v6; // esi@2
  TRIBE_Cliff_Info *v7; // edi@2
  signed int v8; // esi@7
  bool v9; // sf@9
  unsigned __int8 v10; // of@9
  TRIBE_Cliff_Info cliff_info; // [sp+8h] [bp-20h]@1
  TRIBE_Cliff_Info result; // [sp+18h] [bp-10h]@2
  int ya; // [sp+30h] [bp+8h]@6

  v3 = this;
  v4 = (RGE_Static_Object *)TRIBE_Map::find_cliff(this, x, y);
  TRIBE_Map::get_cliff_info(v3, &cliff_info, v4);
  if( v4 )
  {
    v5 = TRIBE_Map::get_cliff_info(v3, &result, v4);
    v6 = 0;
    cliff_info.info[0] = v5->info[0];
    v7 = &cliff_info;
    cliff_info.info[1] = v5->info[1];
    cliff_info.info[2] = v5->info[2];
    cliff_info.info[3] = v5->info[3];
    do
    {
      if( v7->info[0] )
        TRIBE_Map::remove_cliff_edge(v3, x, y, v6);
      ++v6;
      v7 = (TRIBE_Cliff_Info *)((char *)v7 + 4);
    }
    while( v6 < 4 );
    ya = -1;
    do
    {
      v8 = -1;
      do
        RGE_Tile_List::add_node(
          &v3->game_world->players[v3->game_world->curr_player]->diam_tile_list,
          (unsigned __int64)(signed __int64)v4->world_x + ya,
          (unsigned __int64)(signed __int64)v4->world_y + v8++);
      while( v8 < 2 );
      v10 = __OFSUB__(ya + 1, 2);
      v9 = ya++ - 1 < 0;
    }
    while( v9 ^ v10 );
    v4->vfptr->__vecDelDtor(v4, 1u);
  }
}

//----- (00510A50) --------------------------------------------------------
char __thiscall TRIBE_Map::do_cliff_brush(TRIBE_Map *this, int x, int y, char cliff_id, char delete_cliff_flag)
{
  TRIBE_Map *v5; // esi@1
  int v6; // edi@1
  int v7; // ebp@1
  char result; // al@2
  int v9; // eax@3
  int v10; // ecx@10
  int v11; // edx@11
  int v12; // ebx@11
  int v13; // ebx@25
  int v14; // eax@30
  int ya; // [sp+18h] [bp+8h]@30

  v5 = this;
  v6 = x / 3;
  v7 = y / 3;
  if( RGE_Map::do_cliff_brush(x, y, cliff_id, delete_cliff_flag) )
    return 1;
  v9 = v5->old_cliff_x;
  v5->safe_cliff_x = v6;
  v5->safe_cliff_y = v7;
  if( v9 == v6 && v5->old_cliff_y == v7
    || 3 * v6 + 2 >= v5->map_width
    || 3 * v7 + 2 >= v5->map_height
    || v6 < 0
    || v7 < 0 )
  {
    return 0;
  }
  if( v9 != -1 )
  {
    v10 = v5->old_cliff_y;
    if( v10 != -1 )
    {
      v11 = y - 3 * v10;
      v12 = x - 3 * v9;
      if( v12 >= 3 || v12 <= -1 )
      {
        v7 = v5->old_cliff_y;
        goto LABEL_17;
      }
      if( v11 >= 3 || v11 <= -1 )
      {
        v6 = v9;
        goto LABEL_17;
      }
      return 0;
    }
  }
LABEL_17:
  if( v6 != v9 || v7 != v5->old_cliff_y )
  {
    if( delete_cliff_flag )
    {
      ((void (__thiscall *)(TRIBE_Map *, int, int))v5->vfptr[1].__vecDelDtor)(v5, v6, v7);
      result = 1;
    }
    else if( v9 == -1 )
    {
      v5->old_cliff_direction = -1;
      v5->old_cliff_x = v6;
      v5->old_cliff_y = v7;
      result = 1;
    }
    else
    {
      if( v9 >= v6 )
      {
        if( v9 <= v6 )
        {
          v13 = 1;
          if( v5->old_cliff_y >= v7 )
            v13 = 3;
        }
        else
        {
          v13 = 2;
        }
      }
      else
      {
        v13 = 0;
      }
      ya = TRIBE_Map::add_cliff_edge(v5, v9, v5->old_cliff_y, v13, 0, v5->old_cliff_direction);
      v14 = TRIBE_Map::reverse_cliff_direction(v13);
      v5->old_cliff_direction = v14;
      v5->old_cliff_x = v6;
      v5->old_cliff_y = v7;
      TRIBE_Map::add_cliff_edge(v5, v6, v7, v14, ya, -1);
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00510C10) --------------------------------------------------------
char __thiscall TRIBE_Map::do_cliff_brush_stroke(TRIBE_Map *this, int x1, int y1, int x2, int y2, int cliff_id, int delete_cliff)
{
  if( this->safe_cliff_x != x1 / 3 || this->safe_cliff_y != y1 / 3 )
  {
    this->old_cliff_x = -1;
    this->old_cliff_y = -1;
    this->safe_cliff_x = -1;
    this->safe_cliff_y = -1;
    this->old_cliff_direction = -1;
  }
  RGE_Map::do_cliff_brush_stroke((RGE_Map *)&this->vfptr, x1, y1, x2, y2, cliff_id, delete_cliff);
  return 1;
}

//----- (00510C90) --------------------------------------------------------
char __stdcall TRIBE_Map::water(char terrain)
{
  char result; // al@1

  result = terrain;
  if( terrain != 1 )
  {
    if( terrain == 22 )
      result = 1;
    else
      result = terrain == 4;
  }
  return result;
}

//----- (00510CB0) --------------------------------------------------------
void __thiscall TRIBE_Map::clean_borders(TRIBE_Map *this, int x1, int y1, int x2, int y2, char terrain_id)
{
  TRIBE_Map *v6; // esi@1
  int v7; // ecx@1
  int v8; // eax@1
  int v9; // ebp@3
  int v10; // eax@10
  int v11; // edi@10
  int v12; // ebx@11
  int v13; // edi@12
  RGE_Tile **v14; // eax@13
  int v15; // ecx@13
  char v16; // al@13
  char v17; // bl@36
  int v18; // [sp+10h] [bp-8h]@1
  int v19; // [sp+14h] [bp-4h]@1
  int y1a; // [sp+20h] [bp+8h]@11
  char y1b; // [sp+20h] [bp+8h]@14

  v6 = this;
  v7 = this->map_height;
  v8 = v6->map_width;
  v18 = v7 - 1;
  v19 = v8 - 1;
  if( x1 < 0 )
    x1 = 0;
  v9 = y1;
  if( y1 < 0 )
    v9 = 0;
  if( x2 >= v8 )
    x2 = v8 - 1;
  if( y2 >= v7 )
    y2 = v7 - 1;
  if( v9 <= y2 )
  {
    v10 = x2;
    v11 = x1;
    do
    {
      v12 = v11;
      y1a = v11;
      if( v11 <= v10 )
      {
        v13 = v11;
        do
        {
          v14 = v6->map_row_offset;
          v15 = (int)&v14[v9];
          v16 = *((_BYTE *)&v14[v9][v13] + 5) & 0x1F;
          if( v16 == 2 )
          {
            y1b = 0;
            if( v9 > 0 && TRIBE_Map::water(*(_BYTE *)(*(_DWORD *)(v15 - 4) + v13 * 24 + 5) & 0x1F)
              || v9 < v18 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 + 1][v13] + 5) & 0x1F) )
            {
              y1b = 1;
            }
            if( v13 > 0
              && (TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9][v13] - 19) & 0x1F)
               || v9 > 0 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 - 1][v13] - 19) & 0x1F)
               || v9 < v18 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 + 1][v13] - 19) & 0x1F)) )
            {
              y1b = 1;
            }
            if( v12 < v19
              && (TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9][v13 + 1] + 5) & 0x1F)
               || v9 > 0 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 - 1][v13 + 1] + 5) & 0x1F)
               || v9 < v18 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 + 1][v13 + 1] + 5) & 0x1F)) )
            {
              y1b = 1;
            }
            if( y1b != 1 )
              RGE_Map::set_terrain((RGE_Map *)&v6->vfptr, v6->game_world, v12, v9, terrain_id, 0, 0);
          }
          else if( !TRIBE_Map::water(v16) )
          {
            v17 = 0;
            if( v9 > 0 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 - 1][v13] + 5) & 0x1F)
              || v9 < v18 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 + 1][v13] + 5) & 0x1F) )
            {
              v17 = 1;
            }
            if( v13 > 0
              && (TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9][v13] - 19) & 0x1F)
               || v9 > 0 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 - 1][v13] - 19) & 0x1F)
               || v9 < v18 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 + 1][v13] - 19) & 0x1F)) )
            {
              v17 = 1;
            }
            if( y1a < v19
              && (TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9][v13 + 1] + 5) & 0x1F)
               || v9 > 0 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 - 1][v13 + 1] + 5) & 0x1F)
               || v9 < v18 && TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v9 + 1][v13 + 1] + 5) & 0x1F)) )
            {
              v17 = 1;
            }
            if( v17 == 1 )
              RGE_Map::set_terrain((RGE_Map *)&v6->vfptr, v6->game_world, y1a, v9, 2, 0, 0);
            v12 = y1a;
          }
          v10 = x2;
          ++v12;
          ++v13;
          y1a = v12;
        }
        while( v12 <= x2 );
        v11 = x1;
      }
      ++v9;
    }
    while( v9 <= y2 );
  }
}

//----- (00511000) --------------------------------------------------------
char __thiscall TRIBE_Map::do_terrain_brush_check(TRIBE_Map *this, int x, int y)
{
  int v3; // esi@1
  RGE_Tile *v4; // edi@1
  char result; // al@3
  int v6; // eax@4
  int v7; // ebx@4
  int v8; // esi@8
  int v9; // eax@18
  char v10; // cl@18
  int v11; // eax@18

  v3 = y;
  v4 = &this->map_row_offset[y][x];
  if( x > 0 && v4[-1].tile_type )
    return 0;
  v6 = this->map_width;
  v7 = v6 - 1;
  if( x < v6 - 1 && v4[1].tile_type )
    return 0;
  if( y > 0 )
  {
    v8 = (int)&v4[-v6].screen_xpos;
    if( *(_BYTE *)(v8 + 4) )
      return 0;
    if( x > 0 && *(_BYTE *)(v8 - 20) )
      return 0;
    if( x < v7 && *(_BYTE *)(v8 + 28) )
      return 0;
    v3 = y;
  }
  if( v3 >= this->map_height - 1 )
    goto LABEL_29;
  v9 = 3 * v6;
  v10 = v4[8 * v9 / 0x18u].tile_type;
  v11 = (int)&v4[8 * v9 / 0x18u].screen_xpos;
  if( v10 )
    return 0;
  if( x > 0 && *(_BYTE *)(v11 - 20) )
    return 0;
  if( x < v7 && *(_BYTE *)(v11 + 28) )
    result = 0;
  else
LABEL_29:
    result = 1;
  return result;
}

//----- (005110E0) --------------------------------------------------------
void __thiscall TRIBE_Map::tribe_clean_elevation(TRIBE_Map *this, int x1, int y1, int x2, int y2)
{
  int v5; // edi@1
  TRIBE_Map *v6; // esi@1
  int v7; // ebp@3
  int v8; // eax@5
  int v9; // eax@7
  int v10; // ebx@11

  v5 = x1;
  v6 = this;
  if( x1 < 0 )
  {
    x1 = 0;
    v5 = 0;
  }
  v7 = y1;
  if( y1 < 0 )
    v7 = 0;
  v8 = this->map_width;
  if( x2 >= v8 )
    x2 = v8 - 1;
  v9 = this->map_height;
  if( y2 >= v9 )
    y2 = v9 - 1;
  for( ; v7 <= y2; ++v7 )
  {
    if( v5 <= x2 )
    {
      v10 = v5;
      do
      {
        if( TRIBE_Map::water(*((_BYTE *)&v6->map_row_offset[v7][v10] + 5) & 0x1F) )
        {
          if( !TRIBE_Map::do_terrain_brush_check(v6, v5, v7) )
            RGE_Map::set_terrain((RGE_Map *)&v6->vfptr, v6->game_world, v5, v7, 0, 0, 0);
        }
        ++v5;
        ++v10;
      }
      while( v5 <= x2 );
      v5 = x1;
    }
  }
}

//----- (005111A0) --------------------------------------------------------
void __userpurge TRIBE_Map::tribe_clean_terrain(TRIBE_Map *this@<ecx>, int a2@<eax>, int x1, int y1, int x2, int y2, char check_terrain, char replacement_terrain)
{
  TRIBE_Map *v8; // esi@1
  int v9; // edi@1
  int v10; // ebp@3
  int v11; // eax@5
  int v12; // ebx@5
  int v13; // eax@7
  int v14; // ecx@7
  int v15; // ecx@19
  RGE_Tile **v16; // edx@20
  int v17; // eax@20
  signed __int16 v18; // bx@24
  char v19; // al@50
  signed __int16 v20; // cx@61
  bool v21; // sf@140
  unsigned __int8 v22; // of@140
  RGE_Game_World *v23; // [sp-18h] [bp-6Ch]@117
  __int16 v24; // [sp-14h] [bp-68h]@117
  __int16 v25; // [sp-10h] [bp-64h]@117
  char v26; // [sp-Ch] [bp-60h]@117
  char change_flag; // [sp+13h] [bp-41h]@9
  RGE_Tile *til; // [sp+14h] [bp-40h]@20
  signed __int16 place2; // [sp+18h] [bp-3Ch]@24
  signed __int16 place4; // [sp+1Ch] [bp-38h]@24
  signed __int16 place6; // [sp+20h] [bp-34h]@24
  signed __int16 place8; // [sp+24h] [bp-30h]@24
  signed __int16 place3; // [sp+28h] [bp-2Ch]@24
  signed __int16 place5; // [sp+2Ch] [bp-28h]@24
  signed __int16 place7; // [sp+30h] [bp-24h]@24
  int pass_index; // [sp+34h] [bp-20h]@17
  int offset2; // [sp+38h] [bp-1Ch]@1
  __int16 v38; // [sp+3Ch] [bp-18h]@1
  __int16 offset1; // [sp+40h] [bp-14h]@1
  __int16 offset3; // [sp+44h] [bp-10h]@1
  __int16 offset7; // [sp+48h] [bp-Ch]@1
  __int16 offset5; // [sp+4Ch] [bp-8h]@1
  int v43; // [sp+50h] [bp-4h]@19

  v8 = this;
  LOWORD(a2) = this->map_width;
  v9 = x1;
  v38 = a2;
  offset1 = -1 - a2;
  offset2 = -a2;
  offset3 = 1 - a2;
  offset5 = a2 + 1;
  offset7 = a2 - 1;
  if( x1 < 0 )
  {
    v9 = 0;
    x1 = 0;
  }
  v10 = y1;
  if( y1 < 0 )
  {
    v10 = 0;
    y1 = 0;
  }
  v11 = this->map_width;
  v12 = x2;
  if( x2 >= v11 )
  {
    v12 = v11 - 1;
    x2 = v11 - 1;
  }
  v13 = this->map_height;
  v14 = y2;
  if( y2 >= v13 )
  {
    v14 = v13 - 1;
    y2 = v13 - 1;
  }
  do
  {
    change_flag = 0;
    if( v9 > 0 )
      x1 = --v9;
    if( v10 > 0 )
      y1 = --v10;
    if( v12 < v8->map_width - 1 )
      x2 = ++v12;
    if( v14 < v8->map_height - 1 )
      y2 = ++v14;
    pass_index = 0;
    do
    {
      if( v10 > v14 )
        goto LABEL_140;
      v15 = 24 * v9;
      v43 = 24 * v9;
      do
      {
        v16 = v8->map_row_offset;
        v17 = (int)&v16[v10]->screen_xpos + v15;
        til = (RGE_Tile *)((char *)v16[v10] + v15);
        if( v9 > v12 )
          goto LABEL_138;
        while( 1 )
        {
          if( TRIBE_Map::water(*(_BYTE *)(v17 + 5) & 0x1F) )
            goto LABEL_136;
          v18 = 0;
          place2 = 0;
          place3 = 0;
          place4 = 0;
          place5 = 0;
          place6 = 0;
          place7 = 0;
          place8 = 0;
          if( v10 > 0 && TRIBE_Map::water(*((_BYTE *)&til[(signed __int16)offset2] + 5) & 0x1F) )
            place2 = 1;
          if( v10 < v8->map_height - 1 && TRIBE_Map::water(*((_BYTE *)&til[v38] + 5) & 0x1F) )
            place6 = 1;
          if( v9 > 0 && TRIBE_Map::water(*((_BYTE *)&til[-1] + 5) & 0x1F) )
            place8 = 1;
          if( v9 < v8->map_width - 1 && TRIBE_Map::water(*((_BYTE *)&til[1] + 5) & 0x1F) )
            place4 = 1;
          if( v10 > 0 )
          {
            if( v9 > 0 && TRIBE_Map::water(*((_BYTE *)&til[offset1] + 5) & 0x1F) )
              v18 = 1;
            if( v9 < v8->map_width - 1 && TRIBE_Map::water(*((_BYTE *)&til[offset3] + 5) & 0x1F) )
              place3 = 1;
          }
          if( v10 < v8->map_height - 1 )
          {
            if( v9 > 0 && TRIBE_Map::water(*((_BYTE *)&til[offset7] + 5) & 0x1F) )
              place7 = 1;
            if( v9 < v8->map_width - 1 && TRIBE_Map::water(*((_BYTE *)&til[offset5] + 5) & 0x1F) )
              place5 = 1;
          }
          v19 = 0;
          if( !pass_index )
          {
            if( place2 && place6 || place4 && place8 )
              goto LABEL_113;
            goto LABEL_114;
          }
          if( v18 )
          {
            if( place3 && !place2 || place4 && !place3 )
            {
              v20 = place7;
            }
            else
            {
              v20 = place7;
              if( (!place7 || place8) && (!place6 || place7) )
              {
                if( place5 && !place6 && !place4 )
                  v19 = 1;
                goto LABEL_72;
              }
            }
            v19 = 1;
          }
          else
          {
            v20 = place7;
          }
LABEL_72:
          if( place3
            && !v19
            && (v18 && !place2 || place8 && !v18 || place5 && !place4 || place6 && !place5 || v20 && !place8 && !place6) )
          {
            v19 = 1;
          }
          if( place5
            && !v19
            && (place3 && !place4 || place2 && !place3 || v20 && !place6 || place8 && !v20 || v18 && !place8 && !place2) )
          {
            v19 = 1;
          }
          if( v20 )
          {
            if( v19 )
              goto LABEL_115;
            if( v18 && !place8
              || place2 && !v18
              || place5 && !place6
              || place4 && !place5
              || place3 && !place4 && !place2 )
            {
LABEL_113:
              v19 = 1;
              goto LABEL_114;
            }
          }
LABEL_114:
          if( !v19 )
            goto LABEL_136;
LABEL_115:
          if( TRIBE_Map::water(replacement_terrain) )
          {
            if( !TRIBE_Map::do_terrain_brush_check(v8, v9, v10) )
              goto LABEL_136;
            v26 = replacement_terrain;
            v25 = v10;
            v24 = v9;
            v23 = v8->game_world;
          }
          else
          {
            if( v18 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9 - 1, v10 - 1, replacement_terrain, 0, 0);
            if( place2 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9, v10 - 1, replacement_terrain, 0, 0);
            if( place3 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9 + 1, v10 - 1, replacement_terrain, 0, 0);
            if( place4 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9 + 1, v10, replacement_terrain, 0, 0);
            if( place5 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9 + 1, v10 + 1, replacement_terrain, 0, 0);
            if( place6 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9, v10 + 1, replacement_terrain, 0, 0);
            if( place7 )
              RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v8->game_world, v9 - 1, v10 + 1, replacement_terrain, 0, 0);
            if( !place8 )
              goto LABEL_135;
            v26 = replacement_terrain;
            v25 = v10;
            v24 = v9 - 1;
            v23 = v8->game_world;
          }
          RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, v23, v24, v25, v26, 0, 0);
LABEL_135:
          change_flag = 1;
LABEL_136:
          ++v9;
          ++til;
          if( v9 > x2 )
            break;
          v17 = (int)til;
        }
        v9 = x1;
        v15 = v43;
        v12 = x2;
LABEL_138:
        ++v10;
      }
      while( v10 <= y2 );
      v10 = y1;
      v14 = y2;
LABEL_140:
      v22 = __OFSUB__(pass_index + 1, 2);
      v21 = pass_index++ - 1 < 0;
    }
    while( v21 ^ v22 );
  }
  while( change_flag );
  TRIBE_Map::clean_borders(v8, v9, y1, v12, y2, replacement_terrain);
  RGE_Map::set_terrain((RGE_Map *)&v8->vfptr, 0, 0, v9, y1, v12, y2, 0, 0, 0);
}
