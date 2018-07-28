
//----- (004888E0) --------------------------------------------------------
void __thiscall RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(RGE_RMM_Terrain_Generator *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Terrain_Info *in_info)
{
  RGE_RMM_Terrain_Generator *v4; // ebx@1

  v4 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, parent_module, 1);
  v4->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Terrain_Generator::`vftable';
  qmemcpy(&v4->info, in_info, sizeof(v4->info));
  LODWORD(v4->schedule) = 0x40000000;
}
// 571F58: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Terrain_Generator::`vftable')(RGE_RMM_Terrain_Generator *this);

//----- (00488920) --------------------------------------------------------
char __thiscall RGE_RMM_Terrain_Generator::generate(RGE_RMM_Terrain_Generator *this)
{
  RGE_RMM_Terrain_Generator *v1; // ebx@1
  int v2; // eax@1
  float *v3; // ecx@1
  double v4; // st7@2
  int v5; // eax@3
  int v6; // ebp@3
  int v7; // eax@5
  RGE_Terrain_Info_Line v9; // [sp-20h] [bp-1C0h]@5
  int index; // [sp+10h] [bp-190h]@1
  float terrain_table[99]; // [sp+14h] [bp-18Ch]@1

  v1 = this;
  RGE_RMM_Terrain_Generator::generate_modifiers(this);
  v2 = 0;
  v3 = terrain_table;
  index = 0;
  do
  {
    v4 = (double)index;
    ++v2;
    ++v3;
    index = v2;
    *(v3 - 1) = v4;
  }
  while( v2 < 99 );
  v5 = RGE_Zone_Map_List::create_zone_map(v1->map->map_zones, terrain_table, 99);
  v1->map_zone = RGE_Zone_Map_List::get_zone_map(v1->map->map_zones, v5);
  v6 = 0;
  if( v1->info.terrain_num > 0 )
  {
    index = (int)&v1->info;
    do
    {
      qmemcpy(&v9, (const void *)index, sizeof(v9));
      RGE_RMM_Terrain_Generator::base_terrain_generate(v1, v9);
      v7 = v1->info.terrain_num;
      ++v6;
      index += 32;
    }
    while( v6 < v7 );
  }
  RGE_RMM_Terrain_Generator::check_borders(v1);
  return 1;
}

//----- (004889D0) --------------------------------------------------------
char __stdcall RGE_RMM_Terrain_Generator::water(char terrain)
{
  char result; // al@1

  result = terrain;
  if( terrain != 1 )
  {
    if( terrain == 4 )
      result = 1;
    else
      result = terrain == 22;
  }
  return result;
}

//----- (004889F0) --------------------------------------------------------
void __thiscall RGE_RMM_Terrain_Generator::check_borders(RGE_RMM_Terrain_Generator *this)
{
  RGE_RMM_Terrain_Generator *v1; // esi@1
  int v2; // ebp@1
  int v3; // ecx@1
  int v4; // eax@1
  int v5; // edi@2
  char v6; // bl@4
  RGE_Tile *v7; // edx@24
  int max_y; // [sp+8h] [bp-Ch]@1
  int x; // [sp+Ch] [bp-8h]@2
  int max_x; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  v3 = this->map_height;
  max_y = v3 - 1;
  v4 = v1->map_width;
  max_x = v4 - 1;
  if( v3 > 0 )
  {
    do
    {
      v5 = 0;
      for( x = 0; x < v4; ++x )
      {
        if( !RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2][v5] + 5) & 0x1F) )
        {
          v6 = 0;
          if( v2 > 0 && RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2 - 1][v5] + 5) & 0x1F)
            || v2 < max_y && RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2 + 1][v5] + 5) & 0x1F) )
          {
            v6 = 1;
          }
          if( v5 > 0
            && (RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2][v5] - 19) & 0x1F)
             || v2 > 0 && RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2 - 1][v5] - 19) & 0x1F)
             || v2 < max_y && RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2 + 1][v5] - 19) & 0x1F)) )
          {
            v6 = 1;
          }
          if( x < max_x
            && (RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2][v5 + 1] + 5) & 0x1F)
             || v2 > 0 && RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2 - 1][v5 + 1] + 5) & 0x1F)
             || v2 < max_y
             && RGE_RMM_Terrain_Generator::water(*((_BYTE *)&v1->map_row_offset[v2 + 1][v5 + 1] + 5) & 0x1F)) )
          {
            v6 = 1;
          }
          if( v6 == 1 )
          {
            v7 = v1->map_row_offset[v2];
            *((_BYTE *)&v7[v5] + 5) = *((_BYTE *)&v7[v5] + 5) & 0xE2 | 2;
          }
        }
        v4 = v1->map_width;
        ++v5;
      }
      ++v2;
    }
    while( v2 < v1->map_height );
  }
}

//----- (00488B90) --------------------------------------------------------
char __thiscall RGE_RMM_Terrain_Generator::check_terrain(RGE_RMM_Terrain_Generator *this, char target, int x, int y, int spacing, char base_terrain)
{
  int v6; // edx@1
  int v7; // ebp@2
  int v8; // esi@2
  int v9; // eax@2
  int v10; // edi@2
  int v11; // edx@6
  int v12; // edx@8
  int v13; // ebx@10
  RGE_Tile *v14; // edx@10
  int v15; // edi@12
  _BYTE *v16; // esi@13
  char v17; // bl@14
  char result; // al@21
  int v19; // ebp@22
  int v20; // esi@22
  int v21; // eax@22
  int v22; // edx@22
  int v23; // edi@26
  int v24; // edi@28
  RGE_Tile **v25; // edi@30
  int v26; // ecx@30
  _BYTE *v27; // esi@33
  int v28; // ecx@33
  RGE_Tile *v29; // esi@38
  RGE_RMM_Terrain_Generator *v30; // [sp+10h] [bp-18h]@1
  char count; // [sp+14h] [bp-14h]@1
  int index1; // [sp+18h] [bp-10h]@10
  RGE_Tile **v33; // [sp+1Ch] [bp-Ch]@11
  int i_base_terrain; // [sp+20h] [bp-8h]@1
  int xa; // [sp+30h] [bp+8h]@31
  int spacinga; // [sp+38h] [bp+10h]@2
  int y1; // [sp+3Ch] [bp+14h]@22

  v30 = this;
  count = 1;
  v6 = spacing;
  i_base_terrain = this->map->terrain_types[(unsigned __int8)base_terrain].impassable_terrain;
  if( spacing <= 0 )
    goto LABEL_22;
  v7 = x - spacing;
  v8 = y - spacing;
  v9 = spacing + x;
  v10 = spacing + y;
  spacinga = spacing + y;
  if( x - v6 < 0 )
    v7 = 0;
  if( v8 < 0 )
    v8 = 0;
  v11 = this->map_width;
  if( v9 >= v11 )
    v9 = v11 - 1;
  v12 = this->map_height;
  if( v10 >= v12 )
    spacinga = v12 - 1;
  v13 = v7;
  v14 = &this->map_row_offset[v8][v7];
  index1 = v8;
  if( v8 > spacinga )
  {
LABEL_22:
    v19 = x - 2;
    v20 = y - 2;
    v21 = x + 2;
    v22 = y + 2;
    y1 = x + 2;
    if( x - 2 < 0 )
      v19 = 0;
    if( v20 < 0 )
      v20 = 0;
    v23 = this->map_width;
    if( v21 >= v23 )
    {
      v21 = v23 - 1;
      y1 = v23 - 1;
    }
    v24 = this->map_height;
    if( v22 >= v24 )
      v22 = v24 - 1;
    v25 = &this->map_row_offset[v20];
    v26 = (int)&(*v25)[v19].screen_xpos;
    if( v20 <= v22 )
    {
      xa = v22 - v20 + 1;
      do
      {
        if( v19 <= v21 )
        {
          v27 = (_BYTE *)(v26 + 5);
          v28 = v21 - v19 + 1;
          do
          {
            if( (*v27 & 0x1F) == target )
              ++count;
            v27 += 24;
            --v28;
          }
          while( v28 );
          v21 = y1;
        }
        v29 = v25[1];
        ++v25;
        v26 = (int)&v29[v19].screen_xpos;
        --xa;
      }
      while( xa );
    }
    result = count;
  }
  else
  {
    v33 = &this->map_row_offset[v8];
    while( 1 )
    {
      v15 = v7;
      if( v7 <= v9 )
        break;
LABEL_19:
      ++v33;
      v14 = &(*v33)[v13];
      if( ++index1 > spacinga )
        goto LABEL_22;
    }
    v16 = (char *)v14 + 5;
    while( 1 )
    {
      v17 = *v16 & 0x1F;
      if( v17 != base_terrain && (*v16 & 0x1F) != i_base_terrain && v17 != target )
        break;
      ++v15;
      v16 += 24;
      if( v15 > v9 )
      {
        v13 = v7;
        this = v30;
        goto LABEL_19;
      }
    }
    result = 0;
  }
  return result;
}

//----- (00488D50) --------------------------------------------------------
void __thiscall RGE_RMM_Terrain_Generator::generate_modifiers(RGE_RMM_Terrain_Generator *this)
{
  RGE_RMM_Terrain_Generator *v1; // ebx@1
  int v2; // ebp@1
  int i; // edi@2
  signed int v4; // ecx@3
  int v5; // esi@4
  int v6; // eax@5
  int v7; // ecx@5
  int v8; // ecx@9
  int modifier; // [sp+Ch] [bp-Ch]@3
  int v10; // [sp+10h] [bp-8h]@4

  v1 = this;
  v2 = 0;
  memset(this->search_map, 0, this->map_height * this->map_width);
  if( this->map_height > 0 )
  {
    do
    {
      for( i = 0; i < v1->map_width; ++i )
      {
        v4 = 0;
        modifier = 0;
        if( v1->info.hot_spot_num > 0 )
        {
          v5 = (int)&v1->info.hot_spots[0].y;
          v10 = v1->info.hot_spot_num;
          do
          {
            v6 = i - *(_DWORD *)(v5 - 4);
            v7 = v2 - *(_DWORD *)v5;
            if( v6 < 0 )
              v6 = -v6;
            if( v7 < 0 )
              v7 = -v7;
            v8 = *(_DWORD *)(v5 + 4) - (unsigned __int64)(signed __int64)sqrt((double)(v7 * v7 + v6 * v6));
            if( v8 > 0 )
              modifier += v8 * *(_DWORD *)(v5 + 8);
            v5 += 16;
            --v10;
          }
          while( v10 );
          v4 = modifier;
        }
        if( v4 <= 100 )
          v1->search_map_rows[v2][i] = v4;
        else
          v1->search_map_rows[v2][i] = 101;
      }
      ++v2;
    }
    while( v2 < v1->map_height );
  }
}

//----- (00488E40) --------------------------------------------------------
double __stdcall RGE_RMM_Terrain_Generator::fig_chance(int count, int x, int y, int clumpiness_factor)
{
  return (double)(250 - count * clumpiness_factor);
}

//----- (00488E60) --------------------------------------------------------
int __thiscall RGE_RMM_Terrain_Generator::count_map_tiles(RGE_RMM_Terrain_Generator *this, char terrain)
{
  int v2; // edi@1
  RGE_Tile *v3; // edx@1
  unsigned int i; // esi@1

  v2 = 0;
  v3 = *this->map_row_offset;
  for( i = (unsigned int)&v3[this->map_height * this->map_width]; (unsigned int)v3 < i; ++v3 )
  {
    if( (*((_BYTE *)v3 + 5) & 0x1F) == terrain )
      ++v2;
  }
  return v2;
}

//----- (00488EA0) --------------------------------------------------------
void __thiscall RGE_RMM_Terrain_Generator::link_stack_randomly(RGE_RMM_Terrain_Generator *this, Map_Stack *loc_stack, char base_terrain_type)
{
  RGE_RMM_Terrain_Generator *v3; // edi@1
  Map_Stack *v4; // ebx@1
  int v5; // eax@1
  int v6; // edx@1
  Map_Stack *v7; // ecx@1
  int v8; // ebp@1
  int v9; // edx@1
  unsigned int v10; // eax@1
  unsigned int v11; // edx@1
  __int64 v12; // rax@3
  int v13; // eax@3
  int v14; // esi@5
  int v15; // eax@5
  unsigned int v16; // edx@5
  int max_y; // [sp+10h] [bp-4h]@1
  Map_Stack *loc_stacka; // [sp+18h] [bp+4h]@4

  v3 = this;
  v4 = loc_stack;
  v5 = this->map_height;
  v6 = this->map_width;
  max_y = v5 - 1;
  v7 = this->stack_array;
  v8 = v6 - 1;
  v9 = 3 * v6 * v5;
  v10 = (unsigned int)&v7[1];
  v7->prev = loc_stack;
  v11 = (unsigned int)&v7[8 * v9 / 0x18u - 1];
  v7->next = v7 + 1;
  loc_stack->next = v7;
  *(_DWORD *)(v11 + 16) = 0;
  *(_DWORD *)(v11 + 20) = v11 - 24;
  if( (unsigned int)&v7[1] < v11 )
  {
    do
    {
      *(_DWORD *)(v10 + 16) = v10 + 24;
      *(_DWORD *)(v10 + 20) = v10 - 24;
      v10 += 24;
    }
    while( v10 < v11 );
  }
  v12 = v3->map_width * v3->map_height;
  v13 = ((BYTE4(v12) & 7) + (signed int)v12) >> 3;
  if( v13 > 0 )
  {
    loc_stacka = (Map_Stack *)v13;
    do
    {
      v14 = v8 * debug_rand(aCMsdevWorkA_55, 271) / 0x7FFF;
      v15 = debug_rand(aCMsdevWorkA_55, 272);
      v16 = (signed int)(max_y * v15 + ((unsigned __int64)(-2147418109i64 * max_y * v15) >> 32)) >> 14;
      RGE_Random_Map_Module::add_stack_node(v4, &v3->stack_offsets[(v16 >> 31) + v16][v14]);
      loc_stacka = (Map_Stack *)((char *)loc_stacka - 1);
    }
    while( loc_stacka );
  }
}

//----- (00488F90) --------------------------------------------------------
void __thiscall RGE_RMM_Terrain_Generator::remove_area_from_lists(RGE_RMM_Terrain_Generator *this, int x, int y, int spacing)
{
  RGE_RMM_Terrain_Generator *v4; // ebp@1
  int v5; // ebx@1
  int v6; // ecx@1
  int v7; // edi@1
  int v8; // eax@1
  bool v9; // sf@1
  int v10; // edx@5
  int v11; // edx@7
  int v12; // esi@11
  int v13; // edi@11
  int xa; // [sp+14h] [bp+4h]@1
  int y1; // [sp+18h] [bp+8h]@9
  int y_index; // [sp+1Ch] [bp+Ch]@1

  v4 = this;
  v5 = x - spacing;
  v6 = y - spacing;
  v7 = spacing + x;
  v8 = y + spacing;
  v9 = x - spacing < 0;
  y_index = spacing + x;
  xa = v8;
  if( v9 )
    v5 = 0;
  if( v6 < 0 )
    v6 = 0;
  v10 = v4->map_width;
  if( v7 >= v10 )
  {
    y_index = v10 - 1;
    v7 = v10 - 1;
  }
  v11 = v4->map_height;
  if( v8 >= v11 )
  {
    xa = v11 - 1;
    v8 = v11 - 1;
  }
  for( y1 = v6; y1 <= v8; ++y1 )
  {
    if( v5 <= v7 )
    {
      v12 = v5;
      v13 = v7 - v5 + 1;
      do
      {
        RGE_Random_Map_Module::remove_stack_node(&v4->stack_offsets[y1][v12]);
        ++v12;
        --v13;
      }
      while( v13 );
      v8 = xa;
      v7 = y_index;
    }
  }
}

//----- (00489030) --------------------------------------------------------
char __thiscall RGE_RMM_Terrain_Generator::base_terrain_generate(RGE_RMM_Terrain_Generator *this, RGE_Terrain_Info_Line info_line)
{
  RGE_RMM_Terrain_Generator *v2; // esi@1
  int v3; // edi@1
  int v4; // eax@1
  char *v5; // ebx@3
  int v6; // eax@4
  Map_Stack *v7; // edi@5
  signed int v8; // ebx@5
  Map_Stack *v9; // edi@10
  RGE_Tile *v10; // ecx@16
  int v11; // eax@16
  int v12; // ecx@18
  int tot_cost; // ST10_4@24
  RGE_Zone_Map *v14; // ecx@24
  char v15; // al@24
  int v16; // edx@25
  int v17; // ecx@25
  float v18; // ebx@26
  Map_Stack *v19; // edi@35
  char v20; // al@40
  int v21; // edx@40
  int i; // ecx@40
  int v23; // eax@45
  float v24; // edx@45
  RGE_Tile *v25; // ecx@45
  int v26; // eax@45
  int v27; // ecx@47
  Map_Stack *v28; // ebx@56
  int v29; // eax@60
  int v30; // edi@60
  int v31; // edx@60
  int v32; // eax@60
  int v33; // ebp@63
  int v34; // eax@63
  int v35; // edi@68
  int v36; // eax@69
  unsigned int v37; // edx@69
  float v38; // ST10_4@69
  float v39; // ST10_4@73
  float v40; // ST10_4@76
  float v41; // ST10_4@79
  Map_Stack *v42; // ebx@84
  int v43; // edi@86
  char v44; // cl@87
  int v45; // eax@93
  Map_Stack *v46; // edi@99
  signed int v47; // ebx@99
  int y; // [sp+14h] [bp-A54h]@11
  int x; // [sp+18h] [bp-A50h]@11
  float chance; // [sp+1Ch] [bp-A4Ch]@1
  char done; // [sp+23h] [bp-A45h]@55
  int base_area; // [sp+24h] [bp-A44h]@7
  int v54; // [sp+28h] [bp-A40h]@66
  int index1; // [sp+2Ch] [bp-A3Ch]@9
  int clump_size; // [sp+30h] [bp-A38h]@1
  float in_zone; // [sp+34h] [bp-A34h]@11
  int max_y; // [sp+38h] [bp-A30h]@1
  int max_x; // [sp+3Ch] [bp-A2Ch]@1
  Map_Stack loc_stack; // [sp+40h] [bp-A28h]@7
  char terrain_fairness_zones_visited[99]; // [sp+58h] [bp-A10h]@4
  char terrain_fairness_zones[99]; // [sp+BCh] [bp-9ACh]@4
  Map_Stack stack[99]; // [sp+120h] [bp-948h]@5

  v2 = this;
  v3 = 0;
  v4 = this->map_width - 1;
  clump_size = 0;
  max_x = v4;
  max_y = this->map_height - 1;
  chance = 0.0;
  if( info_line.avoid_hot_spots == 2 && this->info.hot_spot_num > 0 )
  {
    v5 = (char *)this->info.hot_spots;
    do
    {
      terrain_fairness_zones[v3] = RGE_Zone_Map::get_zone_info(v2->map_zone, *(_DWORD *)v5, *((_DWORD *)v5 + 1));
      v6 = v2->info.hot_spot_num;
      terrain_fairness_zones_visited[v3++] = 0;
      v5 += 16;
    }
    while( v3 < v6 );
  }
  v7 = stack;
  v8 = 99;
  do
  {
    RGE_Random_Map_Module::init_stack(v7);
    ++v7;
    --v8;
  }
  while( v8 );
  loc_stack.next = 0;
  loc_stack.prev = 0;
  RGE_RMM_Terrain_Generator::link_stack_randomly(v2, &loc_stack, info_line.base_terrain_type);
  base_area = 2 * (unsigned __int64)(signed __int64)sqrt((double)info_line.terrain_size / (double)info_line.clumps);
  if( base_area < 2 )
    base_area = 2;
  index1 = 0;
  if( info_line.clumps > 0 )
  {
    v9 = stack;
    do
    {
      if( !RGE_Random_Map_Module::pop_stack(&loc_stack, &x, &y, &in_zone) )
        break;
      if( (*((_BYTE *)&v2->map_row_offset[y][x] + 5) & 0x1F) == info_line.base_terrain_type
        && RGE_RMM_Terrain_Generator::check_terrain(
             v2,
             info_line.terrain_type,
             x,
             y,
             info_line.spacing,
             info_line.base_terrain_type)
        && (!info_line.avoid_hot_spots || !v2->search_map_rows[y][x]) )
      {
        RGE_RMM_Terrain_Generator::remove_area_from_lists(v2, x, y, base_area);
        v10 = v2->map_row_offset[y];
        *((_BYTE *)&v10[x] + 5) ^= (*((_BYTE *)&v10[x] + 5) ^ LOBYTE(info_line.terrain_type)) & 0x1F;
        v11 = x;
        if( x > 0 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, x - 1, y, 0.0, 0.0);
          v11 = x;
        }
        v12 = y;
        if( y > 0 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, v11, y - 1, 0.0, 0.0);
          v12 = y;
          v11 = x;
        }
        if( v11 < v2->map_width - 1 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, v11 + 1, v12, 0.0, 0.0);
          v12 = y;
          v11 = x;
        }
        if( v12 < v2->map_height - 1 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, v11, v12 + 1, 0.0, 0.0);
          v12 = y;
          v11 = x;
        }
        tot_cost = v12;
        v14 = v2->map_zone;
        ++clump_size;
        ++index1;
        ++v9;
        v15 = RGE_Zone_Map::get_zone_info(v14, v11, tot_cost);
        if( info_line.avoid_hot_spots == 2 )
        {
          v16 = v2->info.hot_spot_num;
          v17 = 0;
          if( v16 > 0 )
          {
            v18 = chance;
            do
            {
              if( terrain_fairness_zones[v17] == v15 && !terrain_fairness_zones_visited[v17] )
              {
                terrain_fairness_zones_visited[v17] = 1;
                ++LODWORD(v18);
              }
              ++v17;
            }
            while( v17 < v16 );
            chance = v18;
          }
        }
      }
    }
    while( index1 < info_line.clumps );
  }
  if( info_line.avoid_hot_spots == 2 && SLODWORD(chance) < v2->info.hot_spot_num )
  {
    v19 = &stack[index1];
    do
    {
      if( !RGE_Random_Map_Module::pop_stack(&loc_stack, &x, &y, &in_zone) )
        break;
      if( (*((_BYTE *)&v2->map_row_offset[y][x] + 5) & 0x1F) == info_line.base_terrain_type
        && RGE_RMM_Terrain_Generator::check_terrain(
             v2,
             info_line.terrain_type,
             x,
             y,
             info_line.spacing,
             info_line.base_terrain_type)
        && v2->search_map_rows[y][x] < 0x1Eu )
      {
        v20 = RGE_Zone_Map::get_zone_info(v2->map_zone, x, y);
        v21 = v2->info.hot_spot_num;
        for( i = 0; i < v21; ++i )
        {
          if( terrain_fairness_zones[i] == v20 && !terrain_fairness_zones_visited[i] )
            break;
        }
        if( i != v21 )
        {
          v23 = base_area;
          LODWORD(v24) = LODWORD(chance) + 1;
          terrain_fairness_zones_visited[i] = 1;
          chance = v24;
          RGE_RMM_Terrain_Generator::remove_area_from_lists(v2, x, y, v23);
          v25 = v2->map_row_offset[y];
          *((_BYTE *)&v25[x] + 5) ^= (*((_BYTE *)&v25[x] + 5) ^ LOBYTE(info_line.terrain_type)) & 0x1F;
          v26 = x;
          if( x > 0 )
          {
            RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v19, x - 1, y, 0.0, 0.0);
            v26 = x;
          }
          v27 = y;
          if( y > 0 )
          {
            RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v19, v26, y - 1, 0.0, 0.0);
            v27 = y;
            v26 = x;
          }
          if( v26 < v2->map_width - 1 )
          {
            RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v19, v26 + 1, v27, 0.0, 0.0);
            v27 = y;
            v26 = x;
          }
          if( v27 < v2->map_height - 1 )
            RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v19, v26, v27 + 1, 0.0, 0.0);
          ++clump_size;
          ++index1;
          ++v19;
        }
      }
    }
    while( SLODWORD(chance) < v2->info.hot_spot_num );
  }
  do
  {
    done = 1;
    if( index1 > 0 )
    {
      v28 = stack;
      base_area = index1;
      do
      {
        if( clump_size < info_line.terrain_size && RGE_Random_Map_Module::pop_stack(v28, &x, &y, &in_zone) )
        {
          done = 0;
          if( !info_line.avoid_hot_spots )
          {
            v30 = y;
            v32 = x;
LABEL_63:
            v33 = (int)&v2->map_row_offset[v30][v32].screen_xpos;
            v34 = (unsigned __int8)RGE_RMM_Terrain_Generator::check_terrain(
                                     v2,
                                     info_line.terrain_type,
                                     v32,
                                     v30,
                                     info_line.spacing,
                                     info_line.base_terrain_type);
            if( (*(_BYTE *)(v33 + 5) & 0x1F) == info_line.base_terrain_type && v34 > 0 )
            {
              chance = RGE_RMM_Terrain_Generator::fig_chance(v34, x, y, info_line.clumpiness_factor);
              if( info_line.avoid_hot_spots )
              {
                v54 = v2->search_map_rows[y][x];
                chance = (double)v54 + chance;
              }
              *(_BYTE *)(v33 + 5) ^= (*(_BYTE *)(v33 + 5) ^ LOBYTE(info_line.terrain_type)) & 0x1F;
              if( x <= 0 )
              {
                v35 = info_line.base_terrain_type;
              }
              else
              {
                v35 = info_line.base_terrain_type;
                if( (*(_BYTE *)(v33 - 19) & 0x1F) == info_line.base_terrain_type )
                {
                  v36 = debug_rand(aCMsdevWorkA_55, 469);
                  v37 = (signed int)(100 * v36 + ((unsigned __int64)(-214741810900i64 * v36) >> 32)) >> 14;
                  v54 = (v37 >> 31) + v37;
                  v38 = (double)v54 + chance;
                  RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v28, x - 1, y, 0.0, v38);
                }
              }
              if( x < max_x && (*(_BYTE *)(v33 + 29) & 0x1F) == v35 )
              {
                v54 = 100 * debug_rand(aCMsdevWorkA_55, 471) / 0x7FFF;
                v39 = (double)v54 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v28, x + 1, y, 0.0, v39);
              }
              if( y > 0 && (*(_BYTE *)(v33 - 24 * v2->map_width + 5) & 0x1F) == v35 )
              {
                v54 = 100 * debug_rand(aCMsdevWorkA_55, 473) / 0x7FFF;
                v40 = (double)v54 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v28, x, y - 1, 0.0, v40);
              }
              if( y < max_y && (*(_BYTE *)(v33 + 24 * v2->map_width + 5) & 0x1F) == v35 )
              {
                v54 = 100 * debug_rand(aCMsdevWorkA_55, 475) / 0x7FFF;
                v41 = (double)v54 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v28, x, y + 1, 0.0, v41);
              }
              ++clump_size;
            }
            goto LABEL_81;
          }
          v29 = debug_rand(aCMsdevWorkA_55, 454);
          v30 = y;
          v31 = 100 * v29 / 0x7FFF;
          v32 = x;
          if( v2->search_map_rows[y][x] <= v31 )
            goto LABEL_63;
        }
LABEL_81:
        ++v28;
        --base_area;
      }
      while( base_area );
    }
  }
  while( !done );
  if( info_line.clumps > 0 )
  {
    v42 = stack;
    base_area = info_line.clumps;
    while( !RGE_Random_Map_Module::pop_stack(v42, &x, &y, &in_zone) )
    {
LABEL_98:
      ++v42;
      if( !--base_area )
        goto LABEL_99;
    }
    while( 2 )
    {
      v43 = (int)&v2->map_row_offset[y][x].screen_xpos;
      if( x <= 0 )
      {
        v44 = info_line.terrain_type;
        goto LABEL_92;
      }
      v44 = info_line.terrain_type;
      if( (*(_BYTE *)(v43 - 19) & 0x1F) == LOBYTE(info_line.terrain_type)
        && x < max_x
        && (*(_BYTE *)(v43 + 29) & 0x1F) == LOBYTE(info_line.terrain_type) )
      {
LABEL_96:
        *(_BYTE *)(v43 + 5) ^= (*(_BYTE *)(v43 + 5) ^ v44) & 0x1F;
      }
      else
      {
LABEL_92:
        if( y > 0 )
        {
          v45 = 24 * v2->map_width;
          if( (*(_BYTE *)(v43 - v45 + 5) & 0x1F) == v44 && y > max_y && (*(_BYTE *)(v43 + v45 + 5) & 0x1F) == v44 )
            goto LABEL_96;
        }
      }
      if( !RGE_Random_Map_Module::pop_stack(v42, &x, &y, &in_zone) )
        goto LABEL_98;
      continue;
    }
  }
LABEL_99:
  v46 = stack;
  v47 = 99;
  do
  {
    RGE_Random_Map_Module::deinit_stack(v46);
    ++v46;
    --v47;
  }
  while( v47 );
  return 1;
}
