
//----- (00485200) --------------------------------------------------------
void __thiscall RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(RGE_RMM_Land_Generator *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Land_Info *in_info)
{
  RGE_RMM_Land_Generator *v4; // ebx@1

  v4 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, parent_module, 1);
  v4->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Land_Generator::`vftable';
  LODWORD(v4->schedule) = 1065353216;
  qmemcpy(&v4->info, in_info, sizeof(v4->info));
}
// 571EC8: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Land_Generator::`vftable')(RGE_RMM_Land_Generator *this);

//----- (00485240) --------------------------------------------------------
char __usercall RGE_RMM_Land_Generator::generate@<al>(RGE_RMM_Land_Generator *this@<ecx>, int a2@<ebx>)
{
  RGE_RMM_Land_Generator *v2; // esi@1
  char *v3; // edi@1
  unsigned int v4; // edx@1
  int v5; // eax@1
  int v6; // eax@1

  v2 = this;
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)&this->vfptr);
  v3 = v2->search_map;
  LOBYTE(a2) = v2->info.land_num;
  BYTE1(a2) = v2->info.land_num;
  v4 = v2->map_height * v2->map_width;
  v5 = a2 << 16;
  LOWORD(v5) = a2;
  memset32(v3, v5, v4 >> 2);
  memset(&v3[4 * (v4 >> 2)], a2, v4 & 3);
  LOWORD(v4) = LOWORD(v2->map_width) - 1;
  RGE_Map::set_terrain(
    v2->map,
    0,
    0,
    0,
    0,
    v4,
    (unsigned __int16)(LOWORD(v2->map_height) - 1),
    v2->info.base_terrain,
    1,
    0);
  RGE_RMM_Land_Generator::base_land_generate(v2);
  LOBYTE(v6) = v2->info.base_terrain;
  RGE_Map::clean_terrain(v2->map, v6, 0, 0, v2->map_width, v2->map_height, v2->info.base_terrain);
  return 1;
}

//----- (004852D0) --------------------------------------------------------
char __thiscall RGE_RMM_Land_Generator::check_terrain_and_zone(RGE_RMM_Land_Generator *this, char target, char land_num, int x, int y)
{
  int v5; // esi@1
  int v6; // edi@1
  char *v7; // ebx@1
  int v8; // eax@1
  int v9; // ebp@1
  char **v10; // ecx@1
  int v12; // esi@3
  char **v13; // edx@4
  int i; // ecx@11
  int count; // [sp+10h] [bp-1Ch]@1
  RGE_RMM_Land_Generator *octogon_y1; // [sp+14h] [bp-18h]@1
  int cx0; // [sp+18h] [bp-14h]@1
  int cx1; // [sp+1Ch] [bp-10h]@1
  int y1; // [sp+20h] [bp-Ch]@1
  int x0; // [sp+24h] [bp-8h]@1
  int x1; // [sp+28h] [bp-4h]@1
  int zone; // [sp+38h] [bp+Ch]@1
  int cy0; // [sp+3Ch] [bp+10h]@1

  v5 = y;
  v6 = x;
  octogon_y1 = this;
  count = 0;
  v7 = (char *)this + 52 * (unsigned __int8)land_num;
  v8 = *((_DWORD *)v7 + 17);
  x0 = x - v8;
  v9 = y - v8;
  x1 = x + v8;
  y1 = y + v8;
  cx0 = x - 2;
  zone = y - 2;
  cx1 = v6 + 2;
  cy0 = y + 2;
  v10 = this->search_map_rows;
  if ( (unsigned __int8)v10[v5][v6] != octogon_y1->info.land_num )
    return 0;
  v12 = v9;
  if ( v9 <= y1 )
  {
    v13 = &v10[v9];
    while ( 1 )
    {
      if ( v12 >= 0 )
      {
        if ( v12 < octogon_y1->map_height )
        {
          for ( i = x0; i <= x1; ++i )
          {
            if ( i >= 0 )
            {
              if ( i < octogon_y1->map_width )
              {
                if ( (*v13)[i] == v7[72] )
                {
                  if ( v12 >= zone && v12 <= cy0 && i >= cx0 && i <= cx1 )
                    ++count;
                }
                else if ( (unsigned __int8)(*v13)[i] < octogon_y1->info.land_num )
                {
                  return 0;
                }
              }
              else if ( i < cx1 )
              {
                ++count;
              }
            }
            else if ( i > cx0 )
            {
              ++count;
            }
          }
        }
        else if ( v12 < cy0 )
        {
          count += 5;
        }
      }
      else if ( v12 > zone )
      {
        count += 5;
      }
      ++v12;
      ++v13;
      if ( v12 > y1 )
        return count;
    }
  }
  return 0;
}

//----- (00485480) --------------------------------------------------------
char __thiscall RGE_RMM_Land_Generator::chance(RGE_RMM_Land_Generator *this, int x, int y, int land_type)
{
  char *v4; // edx@1
  int v5; // ebp@2
  int v6; // eax@2
  int v7; // ebx@2
  int v8; // eax@4
  int v9; // ecx@6
  int v10; // ecx@7
  int v11; // eax@7
  int v12; // eax@15
  char land_typea; // [sp+1Ch] [bp+Ch]@1

  v4 = (char *)this + 52 * land_type;
  land_typea = this->info.land[land_type].wall_fade;
  if ( land_typea )
  {
    v5 = *((_DWORD *)v4 + 22);
    v6 = *((_DWORD *)v4 + 20) - x;
    v7 = *((_DWORD *)v4 + 20) - x;
    if ( v6 <= x - v5 )
      v7 = x - v5;
    v8 = *((_DWORD *)v4 + 20) + v6;
    if ( v8 <= this->map_width - v5 + x - v5 )
      v8 = this->map_width - v5 + x - v5;
    v9 = *((_DWORD *)v4 + 21);
    if ( v8 <= 0 )
    {
      v10 = v9 - y;
      v11 = y - *((_DWORD *)v4 + 23);
    }
    else
    {
      v10 = v8 + v9 - y;
      v11 = y + v8 - *((_DWORD *)v4 + 23);
    }
    if ( v10 > v11 )
      v11 = v10;
    if ( v7 < 0 )
      v7 = 0;
    if ( v11 < 0 )
      v11 = 0;
    v12 = (unsigned __int8)land_typea * (v7 + v11);
    if ( v12 >= 100 )
      LOBYTE(v12) = 101;
  }
  else
  {
    LOBYTE(v12) = 0;
  }
  return v12;
}

//----- (00485520) --------------------------------------------------------
char __thiscall RGE_RMM_Land_Generator::base_land_generate(RGE_RMM_Land_Generator *this)
{
  RGE_RMM_Land_Generator *v1; // esi@1
  Map_Stack *v2; // ebx@2
  Map_Stack *v3; // edi@4
  Map_Stack *v4; // ebp@4
  Map_Stack *v5; // ecx@4
  int v6; // eax@4
  int v7; // ecx@4
  int v8; // ebx@4
  int v9; // edi@4
  int v10; // ebp@4
  int v11; // eax@8
  int v12; // eax@10
  int v13; // eax@12
  int v14; // ebx@33
  int v15; // ebp@34
  int v16; // ecx@36
  bool v17; // sf@36
  unsigned __int8 v18; // of@36
  int v19; // eax@37
  int v20; // edi@37
  int *v21; // ebp@38
  int v22; // ecx@39
  int v23; // ebx@41
  int v24; // eax@41
  unsigned int v25; // edx@41
  RGE_Tile *v26; // edx@42
  char v27; // bl@42
  int v28; // edi@42
  int v29; // eax@44
  int v30; // eax@46
  Map_Stack *v31; // ebx@46
  float tot_cost; // ST20_4@46
  float v33; // ST20_4@50
  float v34; // ST20_4@53
  float v35; // ST20_4@56
  int v36; // eax@59
  int v37; // eax@61
  Map_Stack *v38; // ebp@62
  char *v39; // edi@62
  char v40; // bl@63
  int v41; // edi@72
  int v42; // ecx@65
  char **v43; // ecx@69
  int v44; // ecx@75
  int v45; // edi@76
  Map_Stack *v46; // ebx@77
  int y; // [sp+14h] [bp-B10h]@40
  int x; // [sp+18h] [bp-B0Ch]@40
  Map_Stack *v50; // [sp+1Ch] [bp-B08h]@2
  Map_Stack *i; // [sp+20h] [bp-B04h]@2
  int index1; // [sp+24h] [bp-B00h]@1
  int index3; // [sp+28h] [bp-AFCh]@12
  RGE_Tile *tile; // [sp+2Ch] [bp-AF8h]@19
  char done; // [sp+33h] [bp-AF1h]@37
  char *zone; // [sp+34h] [bp-AF0h]@12
  int index2; // [sp+38h] [bp-AECh]@18
  int x1; // [sp+3Ch] [bp-AE8h]@4
  int *terrain; // [sp+40h] [bp-AE4h]@2
  int max_y; // [sp+44h] [bp-AE0h]@1
  int max_x; // [sp+48h] [bp-ADCh]@1
  float in_zone; // [sp+4Ch] [bp-AD8h]@40
  int land_size[99]; // [sp+50h] [bp-AD4h]@2
  Map_Stack stack[99]; // [sp+1DCh] [bp-948h]@2

  v1 = this;
  index1 = 0;
  max_x = this->map_width - 1;
  max_y = this->map_height - 1;
  if ( this->info.land_num > 0 )
  {
    v2 = (Map_Stack *)&this->info.land[0].base_size;
    v50 = stack;
    terrain = land_size;
    for ( i = (Map_Stack *)&this->info.land[0].base_size; ; v2 = i )
    {
      RGE_Random_Map_Module::init_stack(v50);
      v3 = v2[-1].next;
      v4 = v2[-1].prev;
      v5 = v2[-1].next;
      *terrain = 0;
      v6 = v2->x;
      v7 = (int)&v5->x - v2->x;
      v8 = (int)&v4->x - v2->x;
      v9 = (int)&v3->x + v6;
      v10 = (int)&v4->x + v6;
      x1 = v7;
      if ( v7 < 0 )
      {
        x1 = 0;
        v7 = 0;
      }
      if ( v8 < 0 )
        v8 = 0;
      v11 = v1->map_width;
      if ( v9 >= v11 )
        v9 = v11 - 1;
      v12 = v1->map_height;
      if ( v10 >= v12 )
        v10 = v12 - 1;
      RGE_Map::set_terrain(v1->map, 0, 0, v7, v8, v9, v10, LOBYTE(i[-1].tot_cost), 1, 0);
      v13 = x1;
      index3 = v8;
      LOBYTE(zone) = LOBYTE(i->cost);
      for ( land_size[(unsigned __int8)zone] = (v10 - v8 + 1) * (v9 - x1 + 1); index3 <= v10; ++index3 )
      {
        if ( v13 <= v9 )
        {
          do
            v1->search_map_rows[index3][++v13 - 1] = (char)zone;
          while ( v13 <= v9 );
          v13 = x1;
        }
      }
      if ( v13 > 0 )
      {
        index2 = v8;
        if ( v8 <= v10 )
        {
          tile = (RGE_Tile *)(v13 - 1);
          *(float *)&index3 = (double)index1;
          do
            RGE_Random_Map_Module::push_stack(
              (RGE_Random_Map_Module *)&v1->vfptr,
              v50,
              (int)tile,
              index2++,
              *(float *)&index3,
              0.0);
          while ( index2 <= v10 );
          v13 = x1;
        }
      }
      if ( v8 > 0 )
      {
        index2 = v13;
        if ( v13 <= v9 )
        {
          *(float *)&index3 = (double)index1;
          do
            RGE_Random_Map_Module::push_stack(
              (RGE_Random_Map_Module *)&v1->vfptr,
              v50,
              index2++,
              v8 - 1,
              *(float *)&index3,
              0.0);
          while ( index2 <= v9 );
          v13 = x1;
        }
      }
      if ( v9 < v1->map_width - 1 && v8 <= v10 )
      {
        *(float *)&index3 = (double)index1;
        do
          RGE_Random_Map_Module::push_stack(
            (RGE_Random_Map_Module *)&v1->vfptr,
            v50,
            v9 + 1,
            v8++,
            *(float *)&index3,
            0.0);
        while ( v8 <= v10 );
        v13 = x1;
      }
      if ( v10 < v1->map_height - 1 )
      {
        v14 = v13;
        if ( v13 <= v9 )
        {
          v15 = v10 + 1;
          *(float *)&index3 = (double)index1;
          do
            RGE_Random_Map_Module::push_stack(
              (RGE_Random_Map_Module *)&v1->vfptr,
              v50,
              v14++,
              v15,
              *(float *)&index3,
              0.0);
          while ( v14 <= v9 );
        }
      }
      v16 = v1->info.land_num;
      v18 = __OFSUB__(index1 + 1, v16);
      v17 = index1++ + 1 - v16 < 0;
      ++terrain;
      i = (Map_Stack *)((char *)i + 52);
      ++v50;
      if ( !(v17 ^ v18) )
        break;
    }
  }
  do
  {
    v19 = v1->info.land_num;
    v20 = 0;
    done = 1;
    index1 = 0;
    if ( v19 > 0 )
    {
      i = (Map_Stack *)land_size;
      v50 = stack;
      v21 = &v1->info.land[0].clumpiness_factor;
      do
      {
        v22 = *(v21 - 7);
        zone = (char *)i->x;
        if ( (signed int)zone < v22 && RGE_Random_Map_Module::pop_stack(v50, &x, &y, &in_zone) )
        {
          done = 0;
          v23 = (unsigned __int8)RGE_RMM_Land_Generator::chance(v1, x, y, v20);
          v24 = debug_rand(aCMsdevWorkA_53, 299);
          v25 = (signed int)(100 * v24 + ((unsigned __int64)(-214741810900i64 * v24) >> 32)) >> 14;
          if ( v23 > (signed int)((v25 >> 31) + v25) )
          {
            v1->search_map_rows[y][x] = -1;
          }
          else
          {
            v26 = &v1->map_row_offset[y][x];
            v27 = *((_BYTE *)v21 - 24);
            LOBYTE(terrain) = *((_BYTE *)v21 - 24);
            tile = v26;
            v28 = (unsigned __int8)RGE_RMM_Land_Generator::check_terrain_and_zone(v1, (char)terrain, v20, x, y);
            if ( v1->search_map_rows[y][x] == v1->info.land_num && v28 > 0 )
            {
              *((_BYTE *)tile + 5) ^= (*((_BYTE *)tile + 5) ^ v27) & 0x1F;
              v1->search_map_rows[y][x] = *((_BYTE *)v21 - 4);
              v29 = x;
              if ( x <= 0 || v1->search_map_rows[y][x - 1] != v1->info.land_num )
              {
                v31 = v50;
              }
              else
              {
                v30 = debug_rand(aCMsdevWorkA_53, 312);
                v31 = v50;
                tile = (RGE_Tile *)(100 * v30 / 0x7FFF - *v21 * v28 + 250);
                tot_cost = (double)(signed int)tile;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v1->vfptr, v50, x - 1, y, 0.0, tot_cost);
                v29 = x;
              }
              if ( v29 < max_x && v1->search_map_rows[y][v29 + 1] == v1->info.land_num )
              {
                tile = (RGE_Tile *)(100 * debug_rand(aCMsdevWorkA_53, 315) / 0x7FFF - *v21 * v28 + 250);
                v33 = (double)(signed int)tile;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v1->vfptr, v31, x + 1, y, 0.0, v33);
                v29 = x;
              }
              if ( y > 0 && v1->search_map_rows[y - 1][v29] == v1->info.land_num )
              {
                tile = (RGE_Tile *)(100 * debug_rand(aCMsdevWorkA_53, 318) / 0x7FFF - *v21 * v28 + 250);
                v34 = (double)(signed int)tile;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v1->vfptr, v31, x, y - 1, 0.0, v34);
                v29 = x;
              }
              if ( y < max_y && v1->search_map_rows[y + 1][v29] == v1->info.land_num )
              {
                tile = (RGE_Tile *)(100 * debug_rand(aCMsdevWorkA_53, 321) / 0x7FFF - *v21 * v28 + 250);
                v35 = (double)(signed int)tile;
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v1->vfptr, v31, x, y + 1, 0.0, v35);
              }
              i->x = (int)(zone + 1);
            }
            v20 = index1;
          }
        }
        v36 = v1->info.land_num;
        ++v20;
        v21 += 13;
        index1 = v20;
        ++v50;
        i = (Map_Stack *)((char *)i + 4);
      }
      while ( v20 < v36 );
    }
  }
  while ( !done );
  v37 = v1->info.land_num;
  index1 = 0;
  if ( v37 > 0 )
  {
    v38 = stack;
    v39 = &v1->info.land[0].zone;
    i = stack;
    zone = &v1->info.land[0].zone;
    do
    {
      v40 = *v39;
      LOBYTE(terrain) = *(v39 - 20);
      if ( RGE_Random_Map_Module::pop_stack(v38, &x, &y, &in_zone) )
      {
        do
        {
          if ( x >= 1
            && (v42 = (int)&v1->search_map_rows[y][x], *(_BYTE *)(v42 - 1) == v40)
            && x < max_x
            && *(_BYTE *)(v42 + 1) == v40
            || y >= 1 && (v43 = v1->search_map_rows, v43[y - 1][x] == v40) && y < max_y && v43[y + 1][x] == v40 )
          {
            v41 = (int)&v1->map_row_offset[y][x].screen_xpos;
            *(_BYTE *)(v41 + 5) ^= (*(_BYTE *)(v41 + 5) ^ (unsigned __int8)terrain) & 0x1F;
          }
          v38 = i;
        }
        while ( RGE_Random_Map_Module::pop_stack(i, &x, &y, &in_zone) );
        v39 = zone;
      }
      v44 = v1->info.land_num;
      v39 += 52;
      ++v38;
      v18 = __OFSUB__(index1 + 1, v44);
      v17 = index1++ + 1 - v44 < 0;
      zone = v39;
      i = v38;
    }
    while ( v17 ^ v18 );
  }
  v45 = 0;
  if ( v1->info.land_num > 0 )
  {
    v46 = stack;
    do
    {
      RGE_Random_Map_Module::deinit_stack(v46);
      ++v45;
      ++v46;
    }
    while ( v45 < v1->info.land_num );
  }
  return 1;
}
