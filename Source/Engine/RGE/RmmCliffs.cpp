
//----- (00481980) --------------------------------------------------------
void __thiscall RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(RGE_RMM_Cliffs_Generator *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Cliffs_Info cliff_info)
{
  RGE_RMM_Cliffs_Generator *v4; // ebx@1

  v4 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, parent_module, 1);
  v4->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Cliffs_Generator::`vftable';
  qmemcpy(&v4->info, &cliff_info, sizeof(v4->info));
  LODWORD(v4->schedule) = 1071644672;
}
// 571E64: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Cliffs_Generator::`vftable')(RGE_RMM_Cliffs_Generator *this);

//----- (004819C0) --------------------------------------------------------
char __thiscall RGE_RMM_Cliffs_Generator::generate(RGE_RMM_Cliffs_Generator *this)
{
  RGE_RMM_Cliffs_Generator *v1; // esi@1
  int i; // edi@1

  v1 = this;
  RGE_RMM_Cliffs_Generator::setup_cliff_maps(this);
  debug_rand(aCMsdevWorkA_56, 50);
  for( i = 0; i < v1->info.number_of_cliffs; ++i )
    RGE_RMM_Cliffs_Generator::generate_cliff(v1);
  return 1;
}

//----- (00481A00) --------------------------------------------------------
void __thiscall RGE_RMM_Cliffs_Generator::setup_cliff_maps(RGE_RMM_Cliffs_Generator *this)
{
  RGE_RMM_Cliffs_Generator *v1; // ebp@1
  int v2; // ebx@1
  int v3; // esi@1
  int v4; // edi@1
  signed int v5; // edx@5
  char v6; // bl@5
  RGE_Tile **v7; // edi@5
  unsigned __int8 *v8; // esi@6
  char v9; // al@7
  int v10; // esi@20
  char *v11; // eax@20
  bool v12; // sf@27
  unsigned __int8 v13; // of@27
  int v14; // esi@30
  int i; // ebx@32
  int v16; // esi@33
  int v17; // edi@34
  char **v18; // eax@35
  int v19; // ecx@35
  char water_area; // [sp+13h] [bp-2Dh]@5
  int cliff_x; // [sp+14h] [bp-2Ch]@3
  int cliff_y; // [sp+18h] [bp-28h]@1
  int cliff_width; // [sp+1Ch] [bp-24h]@1
  int v24; // [sp+20h] [bp-20h]@4
  int v25; // [sp+24h] [bp-1Ch]@2
  int cliff_height; // [sp+28h] [bp-18h]@1
  unsigned __int8 terrain_height; // [sp+2Ch] [bp-14h]@13
  signed int v28; // [sp+30h] [bp-10h]@6
  signed int v29; // [sp+34h] [bp-Ch]@5
  int cliff_height2; // [sp+38h] [bp-8h]@1
  int cliff_width2; // [sp+3Ch] [bp-4h]@1

  v1 = this;
  v2 = this->map_width / 3;
  cliff_width = v2;
  v3 = this->map_height / 3;
  cliff_height = v3;
  cliff_width2 = v2 - 1;
  cliff_height2 = v3 - 1;
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)&this->vfptr);
  RGE_Random_Map_Module::init_stack(&v1->valid_cliff_sites);
  memset(v1->search_map, 1u, v1->map_width * v1->map_height);
  v4 = 0;
  cliff_y = 0;
  if( v3 > 0 )
  {
    v25 = 0;
    do
    {
      cliff_x = 0;
      if( v2 > 0 )
      {
        v24 = 0;
        do
        {
          v5 = -1;
          v6 = 1;
          water_area = 0;
          v7 = &v1->map_row_offset[v25];
          v29 = 3;
          do
          {
            v28 = 3;
            v8 = (unsigned __int8 *)&(*v7)[v24] + 5;
            do
            {
              v9 = *v8 & 0x1F;
              if( v9 && v9 != 6 )
              {
                v6 = 0;
                if( v9 == 1 || v9 == 4 || v9 == 22 )
                  water_area = 1;
              }
              else
              {
                terrain_height = *v8 >> 5;
                if( v5 >= 0 )
                {
                  if( v5 != terrain_height )
                    v6 = 0;
                }
                else
                {
                  v5 = terrain_height;
                }
              }
              v8 += 24;
              --v28;
            }
            while( v28 );
            ++v7;
            --v29;
          }
          while( v29 );
          if( v6 )
          {
            v10 = cliff_x;
            v11 = &v1->search_map_rows[cliff_y][cliff_x];
            if( *v11 )
            {
              *v11 = v5 + 1;
              RGE_Random_Map_Module::push_stack(
                (RGE_Random_Map_Module *)&v1->vfptr,
                &v1->valid_cliff_sites,
                cliff_x,
                cliff_y,
                0.0,
                0.0);
            }
          }
          else
          {
            if( water_area )
              RGE_RMM_Cliffs_Generator::invalidate_cliff_area(v1, cliff_x, cliff_y, v1->info.cliff_terrain_spacing);
            v10 = cliff_x;
            v1->search_map_rows[cliff_y][cliff_x] = 0;
          }
          cliff_x = v10 + 1;
          v24 += 3;
        }
        while( v10 + 1 < cliff_width );
        v3 = cliff_height;
        v2 = cliff_width;
      }
      v13 = __OFSUB__(cliff_y + 1, v3);
      v12 = cliff_y++ + 1 - v3 < 0;
      v25 += 3;
    }
    while( v12 ^ v13 );
    v4 = 0;
  }
  if( v1->info.hot_spot_num > 0 )
  {
    v14 = (int)&v1->info.hot_spots[0].y;
    do
    {
      RGE_RMM_Cliffs_Generator::invalidate_cliff_area(
        v1,
        *(_DWORD *)(v14 - 4) / 3,
        *(_DWORD *)v14 / 3,
        *(_DWORD *)(v14 + 4) / 3 + 2);
      ++v4;
      v14 += 12;
    }
    while( v4 < v1->info.hot_spot_num );
  }
  for( i = 0; i < cliff_height; ++i )
  {
    v16 = 0;
    if( cliff_width > 0 )
    {
      v17 = 0;
      do
      {
        v18 = v1->search_map_rows;
        v19 = (int)&v18[i][v16];
        if( *(_BYTE *)v19
          && (i <= 0 || !v18[i - 1][v16])
          && (v17 <= 0 || !*(_BYTE *)(v19 - 1))
          && (i >= cliff_height2 || !v18[i + 1][v16])
          && (v16 >= cliff_width2 || !*(_BYTE *)(v19 + 1)) )
        {
          *(_BYTE *)v19 = 0;
          RGE_Random_Map_Module::remove_stack_node(&v1->stack_offsets[i][v17]);
        }
        ++v16;
        ++v17;
      }
      while( v16 < cliff_width );
    }
  }
  RGE_Random_Map_Module::randomize_stack(&v1->valid_cliff_sites);
}

//----- (00481CD0) --------------------------------------------------------
void __thiscall RGE_RMM_Cliffs_Generator::generate_cliff(RGE_RMM_Cliffs_Generator *this)
{
  RGE_RMM_Cliffs_Generator *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@1
  int v4; // edi@1
  signed int v5; // ecx@1
  Map_Stack *v6; // eax@1
  int v7; // edx@1
  int v8; // eax@7
  signed int v9; // ebx@7
  int v10; // eax@8
  unsigned int v11; // edx@8
  int v12; // edx@8
  int v13; // eax@23
  int v14; // edi@27
  int v15; // ebx@27
  char cliff_end_found; // [sp+2Eh] [bp-32h]@8
  char first_cliff; // [sp+2Fh] [bp-31h]@1
  int x; // [sp+30h] [bp-30h]@4
  int y; // [sp+34h] [bp-2Ch]@4
  int valid_height; // [sp+38h] [bp-28h]@7
  int index; // [sp+3Ch] [bp-24h]@7
  int this_cliff_size; // [sp+40h] [bp-20h]@1
  float cost; // [sp+44h] [bp-1Ch]@4
  Map_Stack cliff; // [sp+48h] [bp-18h]@3

  v1 = this;
  v2 = -1;
  v3 = this->info.cliff_size_variance;
  v4 = -1;
  v5 = 2 * v3 * debug_rand(aCMsdevWorkA_56, 196);
  first_cliff = 1;
  v6 = v1->valid_cliff_sites.next;
  v7 = v1->info.average_cliff_size + v5 / 0x7FFF - v3;
  this_cliff_size = v1->info.average_cliff_size + v5 / 0x7FFF - v3;
  if( v6 && v7 >= 3 )
  {
    RGE_Random_Map_Module::init_stack(&cliff);
    while( 1 )
    {
      RGE_Random_Map_Module::pop_stack(&v1->valid_cliff_sites, &x, &y, &cost);
      if( v1->search_map_rows[y][x] )
        break;
      if( !v1->valid_cliff_sites.next )
        return;
    }
    valid_height = v1->search_map_rows[y][x];
    RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v1->vfptr, &cliff, x, y, 0.0, 0.0);
    v1->search_map_rows[y][x] = 0;
    v8 = debug_rand(aCMsdevWorkA_56, 221);
    index = 0;
    v9 = 4 * v8 / 0x7FFF;
    if( this_cliff_size > 0 )
    {
      do
      {
        cliff_end_found = 0;
        v10 = debug_rand(aCMsdevWorkA_56, 227);
        v11 = (signed int)(100 * v10 + ((unsigned __int64)(-214741810900i64 * v10) >> 32)) >> 14;
        v12 = (v11 >> 31) + v11;
        if( v12 >= 18 )
        {
          if( v12 < 36 )
          {
            if( v9 < 3 )
              ++v9;
            else
              v9 = 0;
          }
        }
        else if( v9 > 0 )
        {
          --v9;
        }
        else
        {
          v9 = 3;
        }
        if( !RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(v1, v9, &x, &y, valid_height)
          && !RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(v1, v9 + 1, &x, &y, valid_height)
          && !RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(v1, v9 - 1, &x, &y, valid_height)
          && (!first_cliff || !RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(v1, v9 - 2, &x, &y, valid_height)) )
        {
          cliff_end_found = 1;
        }
        first_cliff = 0;
        if( cliff_end_found )
          break;
        RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v1->vfptr, &cliff, x, y, 0.0, 0.0);
        v13 = index;
        v1->search_map_rows[y][x] = 0;
        index = v13 + 1;
      }
      while( v13 + 1 < this_cliff_size );
    }
    while( cliff.next )
    {
      RGE_Random_Map_Module::pop_stack(&cliff, &x, &y, &cost);
      if( v2 == -1 )
      {
        v2 = x;
        v4 = y;
      }
      v14 = 3 * v4 + 1;
      v15 = 3 * v2 + 1;
      ((void (__stdcall *)(int, int, int, int, signed int, signed int))v1->map->vfptr->do_terrain_brush_stroke)(
        v15,
        v14,
        3 * x + 1,
        3 * y + 1,
        1,
        16);
      ((void (__stdcall *)(int, int, int, int, _DWORD, _DWORD))v1->map->vfptr->do_cliff_brush_stroke)(
        v15,
        v14,
        3 * x + 1,
        3 * y + 1,
        0,
        0);
      v4 = y;
      v2 = x;
      RGE_RMM_Cliffs_Generator::invalidate_cliff_area(v1, x, y, v1->info.cliff_to_cliff_spacing);
    }
  }
}

//----- (00481FC0) --------------------------------------------------------
char __thiscall RGE_RMM_Cliffs_Generator::check_for_valid_cliff_site(RGE_RMM_Cliffs_Generator *this, int direction, int *x, int *y, int valid_height)
{
  int v5; // ebx@1
  int v6; // esi@1
  int v7; // edi@1
  unsigned int v8; // edx@2
  char result; // al@16

  v5 = *y;
  v6 = direction;
  v7 = *x;
  if( direction > 3 )
  {
    v8 = (direction - 1) / 3u;
    do
    {
      v6 -= 3;
      --v8;
    }
    while( v8 );
  }
  if( v6 < 0 )
    v6 += (2 - v6) / 3u + 2 * ((2 - v6) / 3u);
  switch ( v6 )
  {
    case 0:
      if( v5 <= 0 )
        goto LABEL_17;
      --v5;
      break;
    case 1:
      if( v7 >= this->map_width / 3 - 1 )
        goto LABEL_17;
      ++v7;
      break;
    case 2:
      if( v5 >= this->map_height / 3 - 1 )
        goto LABEL_17;
      ++v5;
      break;
    case 3:
      if( v7 <= 0 )
        goto LABEL_17;
      --v7;
      break;
    default:
      break;
  }
  if( this->search_map_rows[v5][v7] == valid_height )
  {
    *x = v7;
    *y = v5;
    result = 1;
  }
  else
  {
LABEL_17:
    result = 0;
  }
  return result;
}

//----- (004820A0) --------------------------------------------------------
void __thiscall RGE_RMM_Cliffs_Generator::invalidate_cliff_area(RGE_RMM_Cliffs_Generator *this, int x, int y, int radius)
{
  RGE_RMM_Cliffs_Generator *v4; // edi@1
  int v5; // ecx@1
  int v6; // edx@1
  int v7; // ebx@1
  int v8; // eax@1
  int v9; // ebp@10
  int v10; // esi@11
  int v11; // ebx@12
  char *v12; // edx@13
  int cliff_width2; // [sp+10h] [bp-8h]@1
  int cliff_height2; // [sp+14h] [bp-4h]@1
  int xa; // [sp+1Ch] [bp+4h]@1
  int x2; // [sp+20h] [bp+8h]@10
  int radiusa; // [sp+24h] [bp+Ch]@1

  v4 = this;
  cliff_width2 = this->map_width / 3 - 1;
  cliff_height2 = this->map_height / 3 - 1;
  v5 = x - radius;
  v6 = y - radius;
  v7 = radius + x;
  v8 = y + radius;
  radiusa = v5;
  xa = v7;
  if( v5 < 0 )
  {
    radiusa = 0;
    v5 = 0;
  }
  if( v6 < 0 )
    v6 = 0;
  if( v7 > cliff_width2 )
  {
    xa = cliff_width2;
    v7 = cliff_width2;
  }
  if( v7 > cliff_height2 )
    v8 = cliff_height2;
  if( v6 <= v8 )
  {
    v9 = v6;
    x2 = v8 - v6 + 1;
    do
    {
      v10 = v5;
      if( v5 <= v7 )
      {
        v11 = v5;
        do
        {
          v12 = v4->search_map_rows[v9];
          if( v12[v10] )
          {
            v12[v10] = 0;
            RGE_Random_Map_Module::remove_stack_node(&v4->stack_offsets[v9][v11]);
            v5 = radiusa;
          }
          ++v10;
          ++v11;
        }
        while( v10 <= xa );
        v7 = xa;
      }
      ++v9;
      --x2;
    }
    while( x2 );
  }
}
