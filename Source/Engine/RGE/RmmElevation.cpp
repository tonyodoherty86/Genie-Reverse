
//----- (004846C0) --------------------------------------------------------
void __thiscall RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(RGE_RMM_Elevation_Generator *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Elevation_Info *in_info)
{
  RGE_RMM_Elevation_Generator *v4; // ebx@1

  v4 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, parent_module, 1);
  v4->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Elevation_Generator::`vftable';
  qmemcpy(&v4->info, in_info, sizeof(v4->info));
  LODWORD(v4->schedule) = 1069547520;
}
// 571EC4: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Elevation_Generator::`vftable')(RGE_RMM_Elevation_Generator *this);

//----- (00484700) --------------------------------------------------------
char __thiscall RGE_RMM_Elevation_Generator::generate(RGE_RMM_Elevation_Generator *this)
{
  RGE_RMM_Elevation_Generator *v1; // ebx@1
  int i; // eax@2
  int v3; // ebp@3
  int v4; // edi@4
  RGE_Tile *v5; // edx@5
  int v6; // ebp@7
  int v7; // eax@9
  int v8; // edx@9
  int v9; // ecx@9
  int v10; // eax@9
  RGE_Elevation_Info_Line v12; // [sp-18h] [bp-2Ch]@9
  int v13; // [sp-8h] [bp-1Ch]@9
  signed int v14; // [sp-4h] [bp-18h]@9
  RGE_Elevation_Info *v15; // [sp+10h] [bp-4h]@8

  v1 = this;
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)&this->vfptr);
  if ( v1->info.elevation_num > 0 )
  {
    for ( i = 0; i < v1->map_height; ++i )
    {
      v3 = 0;
      if ( v1->map_width > 0 )
      {
        v4 = 0;
        do
        {
          v5 = v1->map_row_offset[i];
          ++v3;
          *((_BYTE *)&v5[v4] + 5) = 32 * LOBYTE(v1->info.elevation[0].base_elevation) | *((_BYTE *)&v5[v4] + 5) & 0x1F;
          ++v4;
        }
        while ( v3 < v1->map_width );
      }
    }
  }
  RGE_RMM_Elevation_Generator::generate_modifiers(v1);
  v6 = 0;
  if ( v1->info.elevation_num > 0 )
  {
    v15 = &v1->info;
    do
    {
      qmemcpy(&v12, v15, sizeof(v12));
      LOBYTE(v7) = RGE_RMM_Elevation_Generator::base_elevation_generate(v1, v12);
      v8 = v1->map_width;
      v9 = v1->map_height - 1;
      v14 = 8;
      v13 = v9;
      RGE_Map::clean_elevation(v1->map, v7, 0, 0, v8 - 1, v9, 8);
      v10 = v1->info.elevation_num;
      ++v6;
      v15 = (RGE_Elevation_Info *)((char *)v15 + 24);
    }
    while ( v6 < v10 );
  }
  return 1;
}

//----- (004847C0) --------------------------------------------------------
char __thiscall RGE_RMM_Elevation_Generator::check_start_elevation(RGE_RMM_Elevation_Generator *this, int x, int y, char base_terrain, char base_elevation, char spacing)
{
  int v6; // ebp@1
  int v7; // edx@1
  int v8; // edi@1
  int v9; // ebx@1
  int v10; // eax@5
  int v11; // eax@7
  RGE_Tile **v12; // ecx@9
  int v13; // esi@9
  int v14; // eax@9
  int v15; // edi@11
  unsigned __int8 *v16; // esi@12
  char result; // al@19
  int xa; // [sp+18h] [bp+4h]@9
  RGE_Tile **index1; // [sp+1Ch] [bp+8h]@10
  int spacinga; // [sp+28h] [bp+14h]@1

  v6 = x - (unsigned __int8)spacing;
  v7 = y - (unsigned __int8)spacing;
  v8 = (unsigned __int8)spacing + y;
  v9 = x + (unsigned __int8)spacing;
  spacinga = (unsigned __int8)spacing + y;
  if ( v6 < 0 )
    v6 = 0;
  if ( v7 < 0 )
    v7 = 0;
  v10 = this->map_width;
  if ( v9 >= v10 )
    v9 = v10 - 1;
  v11 = this->map_height;
  if ( v8 >= v11 )
    spacinga = v11 - 1;
  xa = v7;
  v12 = &this->map_row_offset[v7];
  v13 = v6;
  v14 = (int)&(*v12)[v6].screen_xpos;
  if ( v7 > spacinga )
  {
    result = 1;
  }
  else
  {
    index1 = v12;
    while ( 1 )
    {
      v15 = v6;
      if ( v6 <= v9 )
        break;
LABEL_18:
      ++index1;
      v14 = (int)&(*index1)[v13].screen_xpos;
      if ( ++xa > spacinga )
        return 1;
    }
    v16 = (unsigned __int8 *)(v14 + 5);
    while ( base_terrain != -1
         && (*v16 & 0x1F) == base_terrain
         && (unsigned __int8)(*v16 >> 5) >= (unsigned __int8)base_elevation )
    {
      ++v15;
      v16 += 24;
      if ( v15 > v9 )
      {
        v13 = v6;
        goto LABEL_18;
      }
    }
    result = 0;
  }
  return result;
}

//----- (004848A0) --------------------------------------------------------
char __thiscall RGE_RMM_Elevation_Generator::check_elevation(RGE_RMM_Elevation_Generator *this, char target, int x, int y, int spacing, char base_terrain, char base_elevation)
{
  int v7; // edx@1
  int v8; // ebp@2
  int v9; // esi@2
  int v10; // eax@2
  int v11; // ebx@2
  int v12; // edx@6
  int v13; // edx@8
  RGE_Tile **v14; // eax@10
  int v15; // ecx@10
  int v16; // edx@10
  int v17; // edi@12
  unsigned __int8 *v18; // esi@13
  int v19; // ebp@21
  int v20; // esi@21
  int v21; // eax@21
  int v22; // edx@21
  int v23; // edi@25
  int v24; // edi@27
  RGE_Tile **v25; // edi@29
  int v26; // ecx@29
  unsigned __int8 *v27; // esi@32
  int v28; // ecx@32
  RGE_Tile *v29; // esi@37
  int index1; // [sp+10h] [bp-14h]@10
  char count; // [sp+14h] [bp-10h]@1
  RGE_Tile **v33; // [sp+18h] [bp-Ch]@11
  RGE_RMM_Elevation_Generator *v34; // [sp+1Ch] [bp-8h]@1
  int spacinga; // [sp+34h] [bp+10h]@2
  int y1; // [sp+38h] [bp+14h]@21
  int x1; // [sp+3Ch] [bp+18h]@30

  v7 = spacing;
  v34 = this;
  count = 0;
  if ( spacing <= 0 )
    goto LABEL_21;
  v8 = x - spacing;
  v9 = y - spacing;
  v10 = spacing + y;
  v11 = spacing + x;
  spacinga = spacing + y;
  if ( x - v7 < 0 )
    v8 = 0;
  if ( v9 < 0 )
    v9 = 0;
  v12 = this->map_width;
  if ( v11 >= v12 )
    v11 = v12 - 1;
  v13 = this->map_height;
  if ( v10 >= v13 )
    spacinga = v13 - 1;
  v14 = this->map_row_offset;
  v15 = v8;
  v16 = (int)&v14[v9][v8].screen_xpos;
  index1 = v9;
  if ( v9 > spacinga )
  {
LABEL_20:
    this = v34;
LABEL_21:
    v19 = x - 2;
    v20 = y - 2;
    v21 = x + 2;
    v22 = y + 2;
    y1 = x + 2;
    if ( x - 2 < 0 )
      v19 = 0;
    if ( v20 < 0 )
      v20 = 0;
    v23 = this->map_width;
    if ( v21 >= v23 )
    {
      v21 = v23 - 1;
      y1 = v23 - 1;
    }
    v24 = this->map_height;
    if ( v22 >= v24 )
      v22 = v24 - 1;
    v25 = &this->map_row_offset[v20];
    v26 = (int)&(*v25)[v19].screen_xpos;
    if ( v20 <= v22 )
    {
      x1 = v22 - v20 + 1;
      do
      {
        if ( v19 <= v21 )
        {
          v27 = (unsigned __int8 *)(v26 + 5);
          v28 = v21 - v19 + 1;
          do
          {
            if ( *v27 >> 5 == target )
              ++count;
            v27 += 24;
            --v28;
          }
          while ( v28 );
          v21 = y1;
        }
        v29 = v25[1];
        ++v25;
        v26 = (int)&v29[v19].screen_xpos;
        --x1;
      }
      while ( x1 );
    }
    return count;
  }
  v33 = &v14[v9];
  while ( 1 )
  {
    v17 = v8;
    if ( v8 <= v11 )
      break;
LABEL_19:
    ++index1;
    ++v33;
    v16 = (int)&(*v33)[v15].screen_xpos;
    if ( index1 > spacinga )
      goto LABEL_20;
  }
  v18 = (unsigned __int8 *)(v16 + 5);
  while ( base_terrain != -1
       && (*v18 & 0x1F) == base_terrain
       && (unsigned __int8)(*v18 >> 5) >= (unsigned __int8)base_elevation )
  {
    ++v17;
    v18 += 24;
    if ( v17 > v11 )
    {
      v15 = v8;
      goto LABEL_19;
    }
  }
  return 0;
}

//----- (00484A40) --------------------------------------------------------
void __thiscall RGE_RMM_Elevation_Generator::generate_modifiers(RGE_RMM_Elevation_Generator *this)
{
  RGE_RMM_Elevation_Generator *v1; // ebx@1
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
  memset(this->search_map, 0, this->map_width * this->map_height);
  if ( this->map_height > 0 )
  {
    do
    {
      for ( i = 0; i < v1->map_width; ++i )
      {
        v4 = 0;
        modifier = 0;
        if ( v1->info.hot_spot_num > 0 )
        {
          v5 = (int)&v1->info.hot_spots[0].y;
          v10 = v1->info.hot_spot_num;
          do
          {
            v6 = i - *(_DWORD *)(v5 - 4);
            v7 = v2 - *(_DWORD *)v5;
            if ( v6 < 0 )
              v6 = -v6;
            if ( v7 < 0 )
              v7 = -v7;
            v8 = *(_DWORD *)(v5 + 4) - (unsigned __int64)(signed __int64)sqrt((double)(v7 * v7 + v6 * v6));
            if ( v8 > 0 )
              modifier += v8 * *(_DWORD *)(v5 + 8);
            v5 += 16;
            --v10;
          }
          while ( v10 );
          v4 = modifier;
        }
        if ( v4 <= 100 )
          v1->search_map_rows[v2][i] = v4;
        else
          v1->search_map_rows[v2][i] = 101;
      }
      ++v2;
    }
    while ( v2 < v1->map_height );
  }
}

//----- (00484B30) --------------------------------------------------------
double __stdcall RGE_RMM_Elevation_Generator::fig_chance(int count, int x, int y)
{
  return (double)(250 - 15 * count);
}

//----- (00484B50) --------------------------------------------------------
int __thiscall RGE_RMM_Elevation_Generator::count_map_tiles(RGE_RMM_Elevation_Generator *this, char terrain)
{
  int v2; // edi@1
  RGE_Tile *v3; // edx@1
  unsigned int i; // esi@1

  v2 = 0;
  v3 = *this->map_row_offset;
  for ( i = (unsigned int)&v3[this->map_height * this->map_width]; (unsigned int)v3 < i; ++v3 )
  {
    if ( (*((_BYTE *)v3 + 5) & 0x1F) == terrain )
      ++v2;
  }
  return v2;
}

//----- (00484B90) --------------------------------------------------------
void __thiscall RGE_RMM_Elevation_Generator::link_stack_randomly(RGE_RMM_Elevation_Generator *this, Map_Stack *loc_stack)
{
  RGE_RMM_Elevation_Generator *v2; // edi@1
  int v3; // eax@1
  int v4; // ecx@1
  Map_Stack *v5; // edx@1
  int v6; // ebp@1
  int v7; // ebx@1
  unsigned int v8; // ecx@1
  unsigned int v9; // eax@1
  __int64 v10; // rax@3
  int v11; // eax@3
  int v12; // esi@5
  int v13; // eax@5
  unsigned int v14; // edx@5
  int v15; // [sp+10h] [bp-4h]@4

  v2 = this;
  v3 = this->map_height;
  v4 = this->map_width;
  v5 = v2->stack_array;
  v6 = v3 - 1;
  v7 = v4 - 1;
  v5->prev = loc_stack;
  v8 = (unsigned int)&v5[v4 * v3 - 1];
  v9 = (unsigned int)&v5[1];
  v5->next = v5 + 1;
  *(_DWORD *)(v8 + 16) = 0;
  for ( *(_DWORD *)(v8 + 20) = v8 - 24; v9 < v8; v9 += 24 )
  {
    *(_DWORD *)(v9 + 16) = v9 + 24;
    *(_DWORD *)(v9 + 20) = v9 - 24;
  }
  v10 = v2->map_width * v2->map_height;
  v11 = ((BYTE4(v10) & 0xF) + (signed int)v10) >> 4;
  if ( v11 > 0 )
  {
    v15 = v11;
    do
    {
      v12 = v7 * debug_rand(aCMsdevWorkA_26, 250) / 0x7FFF;
      v13 = debug_rand(aCMsdevWorkA_26, 251);
      v14 = (signed int)(v6 * v13 + ((unsigned __int64)(-2147418109i64 * v6 * v13) >> 32)) >> 14;
      RGE_Random_Map_Module::add_stack_node(loc_stack, &v2->stack_offsets[(v14 >> 31) + v14][v12]);
      --v15;
    }
    while ( v15 );
  }
}

//----- (00484C80) --------------------------------------------------------
void __thiscall RGE_RMM_Elevation_Generator::remove_area_from_lists(RGE_RMM_Elevation_Generator *this, int x, int y, int spacing)
{
  RGE_RMM_Elevation_Generator *v4; // ebp@1
  int v5; // ebx@1
  int v6; // eax@1
  int v7; // edi@1
  bool v8; // sf@1
  int v9; // ecx@5
  int v10; // esi@9
  int v11; // edi@9
  int xa; // [sp+14h] [bp+4h]@1
  int spacinga; // [sp+1Ch] [bp+Ch]@7

  v4 = this;
  v5 = x - spacing;
  v6 = y - spacing;
  v7 = spacing + x;
  v8 = x - spacing < 0;
  xa = spacing + x;
  if ( v8 )
    v5 = 0;
  if ( v6 < 0 )
    v6 = 0;
  v9 = this->map_width;
  if ( v7 >= v9 )
  {
    xa = v9 - 1;
    v7 = v9 - 1;
  }
  for ( spacinga = v6; spacinga <= v7; ++spacinga )
  {
    if ( v5 <= v7 )
    {
      v10 = v5;
      v11 = v7 - v5 + 1;
      do
      {
        RGE_Random_Map_Module::remove_stack_node(&v4->stack_offsets[spacinga][v10]);
        ++v10;
        --v11;
      }
      while ( v11 );
      v7 = xa;
    }
  }
}

//----- (00484D00) --------------------------------------------------------
char __thiscall RGE_RMM_Elevation_Generator::base_elevation_generate(RGE_RMM_Elevation_Generator *this, RGE_Elevation_Info_Line info_line)
{
  RGE_RMM_Elevation_Generator *v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@1
  Map_Stack *v5; // edi@2
  signed int v6; // ebp@4
  int v7; // eax@6
  int v8; // ebx@6
  Map_Stack *v9; // edi@7
  _BYTE *v10; // eax@11
  int v11; // eax@11
  int v12; // ecx@13
  Map_Stack *v13; // ebx@23
  char *v14; // ecx@26
  int v15; // edi@26
  char *v16; // ebp@26
  int v17; // edi@27
  int v18; // eax@27
  double v19; // st7@29
  char v20; // al@29
  float tot_cost; // ST14_4@31
  float v22; // ST14_4@34
  float v23; // ST14_4@37
  float v24; // ST14_4@40
  Map_Stack *v25; // edi@47
  int v26; // ebx@47
  int x; // [sp+14h] [bp-988h]@8
  int y; // [sp+18h] [bp-984h]@8
  char done; // [sp+1Fh] [bp-97Dh]@22
  int v31; // [sp+20h] [bp-97Ch]@31
  int clump_size; // [sp+24h] [bp-978h]@1
  float chance; // [sp+28h] [bp-974h]@29
  int v34; // [sp+2Ch] [bp-970h]@23
  int max_y; // [sp+30h] [bp-96Ch]@1
  float in_zone; // [sp+34h] [bp-968h]@8
  int max_x; // [sp+38h] [bp-964h]@1
  Map_Stack loc_stack; // [sp+3Ch] [bp-960h]@4
  Map_Stack stack[99]; // [sp+54h] [bp-948h]@2

  v2 = this;
  v3 = info_line.clumps;
  v4 = this->map_width - 1;
  clump_size = 0;
  max_x = v4;
  max_y = this->map_height - 1;
  if ( info_line.clumps > 0 )
  {
    v5 = stack;
    do
    {
      RGE_Random_Map_Module::init_stack(v5);
      ++v5;
      --v3;
    }
    while ( v3 );
  }
  loc_stack.next = 0;
  loc_stack.prev = 0;
  RGE_RMM_Elevation_Generator::link_stack_randomly(v2, &loc_stack);
  v6 = (signed int)(signed __int64)sqrt((double)info_line.elevation_size / (double)info_line.clumps) / 2;
  if ( v6 < 2 )
    v6 = 2;
  v7 = info_line.clumps;
  v8 = 0;
  if ( info_line.clumps > 0 )
  {
    v9 = stack;
    do
    {
      if ( !RGE_Random_Map_Module::pop_stack(&loc_stack, &x, &y, &in_zone) )
        break;
      if ( !v2->search_map_rows[y][x]
        && RGE_RMM_Elevation_Generator::check_start_elevation(
             v2,
             x,
             y,
             info_line.base_terrain_type,
             info_line.base_elevation,
             info_line.spacing) )
      {
        RGE_RMM_Elevation_Generator::remove_area_from_lists(v2, x, y, v6);
        v10 = (char *)&v2->map_row_offset[y][x] + 5;
        *v10 = *v10 & 0x1F | 32 * LOBYTE(info_line.elevation);
        v11 = x;
        if ( x > 0 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, x - 1, y, 0.0, 0.0);
          v11 = x;
        }
        v12 = y;
        if ( y > 0 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, v11, y - 1, 0.0, 0.0);
          v12 = y;
          v11 = x;
        }
        if ( v11 < v2->map_width - 1 )
        {
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, v11 + 1, v12, 0.0, 0.0);
          v12 = y;
          v11 = x;
        }
        if ( v12 < v2->map_height - 1 )
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v9, v11, v12 + 1, 0.0, 0.0);
        ++v8;
        ++clump_size;
        ++v9;
      }
    }
    while ( v8 < info_line.clumps );
    v7 = info_line.clumps;
  }
  do
  {
    done = 1;
    if ( v7 > 0 )
    {
      v13 = stack;
      v34 = info_line.clumps;
      do
      {
        if ( clump_size < info_line.elevation_size && RGE_Random_Map_Module::pop_stack(v13, &x, &y, &in_zone) )
        {
          v14 = v2->search_map_rows[y];
          v15 = y;
          done = 0;
          v16 = &v14[x];
          if ( (unsigned __int8)*v16 > 100 * debug_rand(aCMsdevWorkA_26, 369) / 0x7FFF )
          {
            *v16 = 101;
          }
          else
          {
            v17 = (int)&v2->map_row_offset[v15][x].screen_xpos;
            v18 = (unsigned __int8)RGE_RMM_Elevation_Generator::check_elevation(
                                     v2,
                                     info_line.elevation,
                                     x,
                                     y,
                                     info_line.spacing,
                                     info_line.base_terrain_type,
                                     info_line.base_elevation);
            if ( (unsigned int)*(_BYTE *)(v17 + 5) >> 5 == info_line.base_elevation && v18 > 0 )
            {
              v19 = RGE_RMM_Elevation_Generator::fig_chance(v18, x, y);
              v20 = *(_BYTE *)(v17 + 5);
              chance = v19;
              *(_BYTE *)(v17 + 5) = v20 & 0x1F | 32 * LOBYTE(info_line.elevation);
              if ( x > 0 && (unsigned int)*(_BYTE *)(v17 - 19) >> 5 == info_line.base_elevation )
              {
                v31 = 100 * debug_rand(aCMsdevWorkA_26, 381) / 0x7FFF;
                tot_cost = (double)v31 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v13, x - 1, y, 0.0, tot_cost);
              }
              if ( x < max_x && (unsigned int)*(_BYTE *)(v17 + 29) >> 5 == info_line.base_elevation )
              {
                v31 = 100 * debug_rand(aCMsdevWorkA_26, 383) / 0x7FFF;
                v22 = (double)v31 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v13, x + 1, y, 0.0, v22);
              }
              if ( y > 0 && (unsigned int)*(_BYTE *)(v17 - 24 * v2->map_width + 5) >> 5 == info_line.base_elevation )
              {
                v31 = 100 * debug_rand(aCMsdevWorkA_26, 385) / 0x7FFF;
                v23 = (double)v31 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v13, x, y - 1, 0.0, v23);
              }
              if ( y < max_y && (unsigned int)*(_BYTE *)(v17 + 24 * v2->map_width + 5) >> 5 == info_line.base_elevation )
              {
                v31 = 100 * debug_rand(aCMsdevWorkA_26, 387) / 0x7FFF;
                v24 = (double)v31 + chance;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v2->vfptr, v13, x, y + 1, 0.0, v24);
              }
              ++clump_size;
            }
          }
        }
        ++v13;
        --v34;
      }
      while ( v34 );
      v7 = info_line.clumps;
    }
  }
  while ( !done );
  if ( v7 > 0 )
  {
    v25 = stack;
    v26 = v7;
    do
    {
      RGE_Random_Map_Module::deinit_stack(v25);
      ++v25;
      --v26;
    }
    while ( v26 );
  }
  return 1;
}
