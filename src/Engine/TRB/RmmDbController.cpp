
//----- (004876C0) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(TRIBE_RMM_Database_Controller *this, char *land_file, char *terrain_file, char *object_file, char *map_file)
{
  TRIBE_RMM_Database_Controller *v5; // esi@1

  v5 = this;
  RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(
    (RGE_RMM_Database_Controller *)&this->vfptr,
    land_file,
    terrain_file,
    object_file,
    map_file);
  v5->vfptr = (RGE_Random_Map_ModuleVtbl *)&TRIBE_RMM_Database_Controller::`vftable';
}
// 571F00: using guessed type unsigned __int8 (__thiscall *TRIBE_RMM_Database_Controller::`vftable')(TRIBE_RMM_Database_Controller *__hidden this);

//----- (004876F0) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(TRIBE_RMM_Database_Controller *this, int infile)
{
  TRIBE_RMM_Database_Controller *v2; // esi@1

  v2 = this;
  RGE_RMM_Database_Controller::RGE_RMM_Database_Controller((RGE_RMM_Database_Controller *)&this->vfptr, infile);
  v2->vfptr = (RGE_Random_Map_ModuleVtbl *)&TRIBE_RMM_Database_Controller::`vftable';
}
// 571F00: using guessed type unsigned __int8 (__thiscall *TRIBE_RMM_Database_Controller::`vftable')(TRIBE_RMM_Database_Controller *__hidden this);

//----- (00487710) --------------------------------------------------------
char __thiscall TRIBE_RMM_Database_Controller::init(TRIBE_RMM_Database_Controller *this, RGE_Map *in_map, RGE_Game_World *in_world, char type, int player_num, int fixed_position)
{
  TRIBE_RMM_Database_Controller *v6; // ebx@1
  signed int v7; // eax@2
  signed int v8; // eax@3
  int v9; // ecx@3
  int v10; // eax@23
  int v11; // edx@25
  char *v12; // ecx@26
  int v13; // eax@26
  int v14; // esi@27
  RGE_RMM_Cliffs_Generator *v15; // eax@30
  RGE_Map *v16; // edx@31
  RGE_Cliffs_Info v18; // [sp-4C0h] [bp-99Ch]@31
  int base_cliff_size; // [sp+Ch] [bp-4D0h]@14
  RGE_Cliffs_Info cliff_info; // [sp+10h] [bp-4CCh]@22
  int v21; // [sp+4D8h] [bp-4h]@30

  v6 = this;
  LOBYTE(fixed_position) = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game) == 0;
  RGE_RMM_Database_Controller::init(
    (RGE_RMM_Database_Controller *)&v6->vfptr,
    in_map,
    in_world,
    type,
    player_num,
    fixed_position);
  if ( debug_rand(aCMsdevWorkAg_4, 64) > 0x1FFF )
  {
    v7 = v6->map_width;
    if ( v7 > 72 )
    {
      if ( v7 > 96 )
      {
        if ( v7 > 120 )
        {
          if ( v7 > 144 )
          {
            if ( v7 > 200 )
            {
              if ( v7 > 250 )
              {
                v8 = base_cliff_size;
                v9 = base_cliff_size;
              }
              else
              {
                v8 = 28;
                v9 = 20;
              }
            }
            else
            {
              v8 = 18;
              v9 = 20;
            }
          }
          else
          {
            v8 = 8;
            v9 = 16;
          }
        }
        else
        {
          v8 = 6;
          v9 = 14;
        }
      }
      else
      {
        v8 = 4;
        v9 = 12;
      }
    }
    else
    {
      v8 = 3;
      v9 = 10;
    }
    switch ( v6->map_type )
    {
      case 0:
        v8 = 0;
        v9 = 0;
        break;
      case 1:
        v8 -= 5;
        v9 -= 6;
        break;
      case 2:
        v8 -= 3;
        v9 -= 2;
        break;
      case 5:
      case 6:
      case 8:
        v9 -= 4;
        break;
      default:
        break;
    }
    if ( v9 < 3 )
      v9 = 3;
    cliff_info.number_of_cliffs = v8;
    cliff_info.number_of_cliffs_variance = 2;
    cliff_info.cliff_terrain_spacing = 2;
    cliff_info.cliff_to_cliff_spacing = 2;
    if ( v9 - 3 > 0 )
      v10 = (v9 - 3) / 2;
    else
      v10 = 0;
    v11 = v6->terrain_info.hot_spot_num;
    cliff_info.cliff_size_variance = v10;
    cliff_info.average_cliff_size = v9 - v10;
    cliff_info.hot_spot_num = v11;
    if ( v11 > 0 )
    {
      v12 = (char *)&cliff_info.hot_spots[0].y;
      v13 = (int)&v6->terrain_info.hot_spots[0].y;
      do
      {
        v14 = *(_DWORD *)(v13 - 4);
        v13 += 16;
        *((_DWORD *)v12 - 1) = v14;
        *(_DWORD *)v12 = *(_DWORD *)(v13 - 16);
        *((_DWORD *)v12 + 1) = *(_DWORD *)(v13 - 12);
        v12 += 12;
        --v11;
      }
      while ( v11 );
    }
    if ( cliff_info.average_cliff_size > 0 && cliff_info.number_of_cliffs > 0 )
    {
      v15 = (RGE_RMM_Cliffs_Generator *)operator new(0x508u);
      base_cliff_size = (int)v15;
      v21 = 0;
      if ( v15 )
      {
        v16 = v6->map;
        qmemcpy(&v18, &cliff_info, sizeof(v18));
        RGE_RMM_Cliffs_Generator::RGE_RMM_Cliffs_Generator(v15, v16, (RGE_Random_Map_Module *)&v6->vfptr, v18);
      }
    }
  }
  return 1;
}

//----- (00487930) --------------------------------------------------------
char __thiscall TRIBE_RMM_Database_Controller::de_init(TRIBE_RMM_Database_Controller *this)
{
  RGE_RMM_Database_Controller::de_init((RGE_RMM_Database_Controller *)&this->vfptr);
  return 1;
}

//----- (00487940) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::add_land_module(TRIBE_RMM_Database_Controller *this, char fixed_positions)
{
  TRIBE_RMM_Database_Controller *v2; // esi@1
  int v3; // eax@1
  RGE_Map_Data_Entry *v4; // edx@1
  int v5; // edi@1
  int *v6; // ecx@1
  signed int v7; // eax@3
  int v8; // ecx@7
  int v9; // eax@7
  int *v10; // ecx@8
  int v11; // ecx@11
  int v12; // eax@11
  int *v13; // ecx@12
  int v14; // ecx@15
  int v15; // eax@15
  int *v16; // ecx@16
  int v17; // ecx@19
  int v18; // eax@19
  int *v19; // ecx@20
  int v20; // ecx@24
  int v21; // eax@24
  int *v22; // eax@25
  int v23; // ecx@28
  int v24; // eax@28
  int *v25; // eax@29
  signed int v26; // eax@31
  int v27; // eax@36
  char *v28; // ecx@37
  int v29; // eax@40
  char *v30; // ecx@41
  int v31; // eax@43
  signed int v32; // ecx@43
  bool v33; // sf@43
  unsigned __int8 v34; // of@43
  signed int v35; // eax@43
  char *v36; // ecx@45
  char *v37; // ecx@49
  signed int v38; // eax@52
  int v39; // eax@53
  char *v40; // ecx@54
  int v41; // eax@58
  char *v42; // ecx@59
  int v43; // eax@61
  signed int v44; // eax@63
  unsigned int v45; // edx@63
  int v46; // edx@64
  int v47; // eax@70
  int v48; // edi@72
  int v49; // eax@73
  int v50; // ecx@78
  int v51; // ecx@80
  signed int v52; // ecx@83
  signed int v53; // edi@83
  signed int v54; // ebp@83
  int v55; // ebx@84
  int v56; // eax@86

  v2 = this;
  v3 = this->map_type;
  v4 = this->map_info.maps;
  v5 = v4[v3].land_info.land_placement_edge;
  v6 = &v4[v3].land_info.land_placement_edge;
  if ( v3 == 5 || v3 == 8 )
  {
    v7 = v2->map_width;
    if ( v7 < 100 )
      *v6 = v7 >= 80 ? 25 : 20;
  }
  RGE_RMM_Database_Controller::add_land_module((RGE_RMM_Database_Controller *)&v2->vfptr, fixed_positions);
  v2->map_info.maps[v2->map_type].land_info.land_placement_edge = v5;
  if ( v2->map_type < 5 )
  {
    if ( debug_rand(aCMsdevWorkAg_4, 185) < 0x3FFF )
    {
      v8 = v2->land_info.land_num;
      v9 = 0;
      v2->land_info.wall_1_avoidance_line = -1;
      if ( v8 > 0 )
      {
        v10 = &v2->land_info.land[0].wall_1_avoidance_line;
        do
        {
          *v10 = -1;
          ++v9;
          v10 += 13;
        }
        while ( v9 < v2->land_info.land_num );
      }
    }
    if ( debug_rand(aCMsdevWorkAg_4, 192) < 0x3FFF )
    {
      v11 = v2->land_info.land_num;
      v12 = 0;
      v2->land_info.wall_2_avoidance_line = -1;
      if ( v11 > 0 )
      {
        v13 = &v2->land_info.land[0].wall_2_avoidance_line;
        do
        {
          *v13 = -1;
          ++v12;
          v13 += 13;
        }
        while ( v12 < v2->land_info.land_num );
      }
    }
    if ( debug_rand(aCMsdevWorkAg_4, 199) < 0x3FFF )
    {
      v14 = v2->land_info.land_num;
      v2->land_info.wall_3_avoidance_line = v2->map_width;
      v15 = 0;
      if ( v14 > 0 )
      {
        v16 = &v2->land_info.land[0].wall_3_avoidance_line;
        do
        {
          ++v15;
          *v16 = v2->map_width;
          v16 += 13;
        }
        while ( v15 < v2->land_info.land_num );
      }
    }
    if ( debug_rand(aCMsdevWorkAg_4, 206) < 0x3FFF )
    {
      v17 = v2->land_info.land_num;
      v2->land_info.wall_4_avoidance_line = v2->map_height;
      v18 = 0;
      if ( v17 > 0 )
      {
        v19 = &v2->land_info.land[0].wall_4_avoidance_line;
        do
        {
          ++v18;
          *v19 = v2->map_height;
          v19 += 13;
        }
        while ( v18 < v2->land_info.land_num );
      }
    }
  }
  if ( v2->map_type == 8 )
  {
    if ( debug_rand(aCMsdevWorkAg_4, 216) >= 0x3FFF )
    {
      v23 = 0;
      v2->land_info.wall_4_avoidance_line = v2->map_height;
      v24 = v2->land_info.land_num;
      v2->land_info.wall_2_avoidance_line = -1;
      if ( v24 > 0 )
      {
        v25 = &v2->land_info.land[0].wall_4_avoidance_line;
        do
        {
          *(v25 - 2) = -1;
          *v25 = v2->map_height;
          ++v23;
          v25 += 13;
        }
        while ( v23 < v2->land_info.land_num );
      }
    }
    else
    {
      v20 = 0;
      v2->land_info.wall_3_avoidance_line = v2->map_width;
      v21 = v2->land_info.land_num;
      v2->land_info.wall_1_avoidance_line = -1;
      if ( v21 > 0 )
      {
        v22 = &v2->land_info.land[0].wall_3_avoidance_line;
        do
        {
          *(v22 - 2) = -1;
          *v22 = v2->map_width;
          ++v20;
          v22 += 13;
        }
        while ( v20 < v2->land_info.land_num );
      }
    }
  }
  v26 = v2->map_type;
  if ( v26 >= 2 && v26 <= 6 || v26 == 8 )
  {
    if ( debug_rand(aCMsdevWorkAg_4, 241) < 0x3FFF )
    {
      if ( debug_rand(aCMsdevWorkAg_4, 247) >= 0x3FFF )
      {
        v29 = 0;
        if ( v2->land_info.land_num > 0 )
        {
          v30 = &v2->land_info.land[0].zone;
          do
          {
            *v30 = v29;
            v29 += 2;
            v30 += 104;
          }
          while ( v29 < v2->land_info.land_num );
        }
      }
      else
      {
        v27 = 0;
        if ( v2->land_info.land_num > 0 )
        {
          v28 = &v2->land_info.land[0].zone;
          do
          {
            *v28 = 0;
            v27 += 2;
            v28 += 104;
          }
          while ( v27 < v2->land_info.land_num );
        }
      }
      v31 = debug_rand(aCMsdevWorkAg_4, 255);
      v32 = v2->land_info.land_num;
      v34 = __OFSUB__(v31, 0x3FFF);
      v33 = v31 - 0x3FFF < 0;
      v35 = 1;
      if ( v33 ^ v34 )
      {
        if ( v32 > 1 )
        {
          v36 = &v2->land_info.land[1].zone;
          do
          {
            *v36 = 1;
            v35 += 2;
            v36 += 104;
          }
          while ( v35 < v2->land_info.land_num );
          TRIBE_RMM_Database_Controller::add_shallows_module(v2);
          goto LABEL_61;
        }
      }
      else if ( v32 > 1 )
      {
        v37 = &v2->land_info.land[1].zone;
        do
        {
          *v37 = v35;
          v35 += 2;
          v37 += 104;
        }
        while ( v35 < v2->land_info.land_num );
      }
      TRIBE_RMM_Database_Controller::add_shallows_module(v2);
      goto LABEL_61;
    }
    v38 = v2->map_type;
    if ( v38 == 4 )
    {
      v39 = 0;
      if ( v2->land_info.land_num > 0 )
      {
        v40 = &v2->land_info.land[0].zone;
        do
        {
          *v40 = 0;
          ++v39;
          v40 += 52;
        }
        while ( v39 < v2->land_info.land_num );
      }
      v2->land_info.base_terrain = 0;
    }
    else if ( v38 >= 5 )
    {
      v41 = 0;
      if ( v2->land_info.land_num > 0 )
      {
        v42 = &v2->land_info.land[0].zone;
        do
        {
          *v42 = 0;
          ++v41;
          v42 += 52;
        }
        while ( v41 < v2->land_info.land_num );
      }
    }
  }
LABEL_61:
  v43 = v2->map_type;
  if ( v43 == 5 || v43 == 8 )
  {
    v44 = v2->map_width;
    v45 = 20;
    if ( v44 < 100 )
    {
      v46 = v44 < 80;
      LOBYTE(v46) = v44 >= 80;
      v45 = ((v46 - 1) & 0xFFFFFFFB) + 15;
      if ( v2->land_info.wall_1_avoidance_line > 0 )
        v2->land_info.wall_1_avoidance_line = v45;
      if ( v2->land_info.wall_2_avoidance_line > 0 )
        v2->land_info.wall_2_avoidance_line = v45;
      if ( v2->land_info.wall_3_avoidance_line < v44 )
        v2->land_info.wall_3_avoidance_line = v44 - v45;
      v47 = v2->map_height;
      if ( v2->land_info.wall_4_avoidance_line < v47 )
        v2->land_info.wall_4_avoidance_line = v47 - v45;
      v48 = 0;
      if ( v2->land_info.land_num > 0 )
      {
        v49 = (int)&v2->land_info.land[0].wall_2_avoidance_line;
        do
        {
          if ( *(_DWORD *)(v49 - 4) > 0 )
            *(_DWORD *)(v49 - 4) = v45;
          if ( *(_DWORD *)v49 > 0 )
            *(_DWORD *)v49 = v45;
          v50 = v2->map_width;
          if ( *(_DWORD *)(v49 + 4) < v50 )
            *(_DWORD *)(v49 + 4) = v50 - v45;
          v51 = v2->map_height;
          if ( *(_DWORD *)(v49 + 8) < v51 )
            *(_DWORD *)(v49 + 8) = v51 - v45;
          ++v48;
          v49 += 52;
        }
        while ( v48 < v2->land_info.land_num );
      }
    }
    v52 = v2->land_info.land_num;
    v53 = 0;
    v54 = (signed __int64)((double)(signed int)((v2->map_height - 2 * v45) * (v2->map_width - 2 * v45)) * 0.8);
    if ( v52 > 0 )
    {
      v55 = (int)&v2->land_info;
      do
      {
        v55 += 52;
        ++v53;
        *(_DWORD *)(v55 - 52) = v54 / v52;
        v52 = v2->land_info.land_num;
      }
      while ( v53 < v52 );
    }
  }
  v56 = debug_rand(aCMsdevWorkAg_4, 311);
  TDebuggingLog::Log(L, aRandomMapLandI, v56);
}

//----- (00487DD0) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::add_terrain_module(TRIBE_RMM_Database_Controller *this)
{
  TRIBE_RMM_Database_Controller *v1; // esi@1
  signed int v2; // ST1C_4@1
  int v3; // ebx@1
  int *v4; // edi@2
  int v5; // edi@8
  int v6; // ecx@9
  int v7; // eax@10
  int v8; // edx@22
  int *v9; // eax@23
  int v10; // ecx@24
  int v11; // eax@30
  int land_tile_num; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = this->map_width * this->map_height * this->map_info.maps[this->map_type].land_info.grown_land_percent / 100;
  RGE_RMM_Database_Controller::add_terrain_module((RGE_RMM_Database_Controller *)&this->vfptr);
  v3 = 0;
  *(float *)&land_tile_num = (double)v2 * 0.000049999999;
  if ( v1->terrain_info.terrain_num > 0 )
  {
    v4 = &v1->terrain_info.terrain[0].clumps;
    do
    {
      if ( *(v4 - 1) != 6 && *(float *)&land_tile_num > 1.0 )
        *v4 = (signed __int64)((double)*v4 * *(float *)&land_tile_num);
      ++v3;
      v4 += 8;
    }
    while ( v3 < v1->terrain_info.terrain_num );
  }
  if ( debug_rand(aCMsdevWorkAg_4, 340) >= 0x1FFF )
  {
    v8 = 0;
    if ( v1->terrain_info.terrain_num > 0 )
    {
      v9 = &v1->terrain_info.terrain[0].avoid_hot_spots;
      do
      {
        v10 = *(v9 - 5);
        if ( v10 == 6 )
        {
          *v9 = 0;
        }
        else if ( v10 == 10 || v10 == 13 )
        {
          *v9 = 2;
        }
        ++v8;
        v9 += 8;
      }
      while ( v8 < v1->terrain_info.terrain_num );
    }
  }
  else
  {
    v5 = 0;
    if ( v1->terrain_info.terrain_num > 0 )
    {
      v6 = (int)&v1->terrain_info.terrain[0].clumps;
      do
      {
        v7 = *(_DWORD *)(v6 - 4);
        switch ( v7 )
        {
          case 13:
            *(_DWORD *)(v6 - 12) *= 3;
            *(_DWORD *)v6 *= 3;
            *(_DWORD *)(v6 + 16) = 2;
            break;
          case 20:
            *(_DWORD *)(v6 - 12) /= 2;
            *(_DWORD *)v6 /= 2;
            break;
          case 19:
            *(_DWORD *)(v6 - 12) /= 2;
            *(_DWORD *)v6 /= 2;
            break;
          case 10:
            *(_DWORD *)(v6 - 12) /= 2;
            *(_DWORD *)v6 /= 2;
            *(_DWORD *)(v6 + 16) = 2;
            break;
          case 6:
            *(_DWORD *)(v6 - 12) *= 2;
            *(_DWORD *)(v6 + 16) = 0;
            break;
        }
        ++v5;
        v6 += 32;
      }
      while ( v5 < v1->terrain_info.terrain_num );
    }
  }
  v11 = debug_rand(aCMsdevWorkAg_4, 384);
  TDebuggingLog::Log(L, aRandomMapTerra, v11);
}

//----- (00487FA0) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::add_object_module(TRIBE_RMM_Database_Controller *this)
{
  TRIBE_RMM_Database_Controller *v1; // ebp@1
  int v2; // ecx@2
  int *v3; // eax@3
  int v4; // ecx@7
  int *v5; // eax@8
  int v6; // ecx@13
  char *v7; // eax@14
  int v8; // edx@14
  char *v9; // edi@15
  signed int v10; // esi@16
  int v11; // ebx@16
  RGE_Map *v12; // ecx@16
  int v13; // eax@16
  int v14; // esi@18
  int v15; // eax@18
  signed int v16; // ecx@20
  int v17; // eax@20
  int v18; // edx@20
  RGE_Land_Info_Line *v19; // ecx@21
  int v20; // ebx@22
  int v21; // ebx@23
  int v22; // esi@25
  int v23; // edi@25
  int *v24; // edx@26
  int v25; // ecx@30
  bool v26; // sf@30
  unsigned __int8 v27; // of@30
  int v28; // eax@35
  int v29; // eax@35
  int v30; // edx@38
  int v31; // esi@41
  int *v32; // ecx@42
  int v33; // eax@43
  __int64 v34; // rax@48
  signed int v35; // edx@49
  int v36; // eax@53
  char done; // [sp+13h] [bp-11h]@25
  int extra_island_roll; // [sp+14h] [bp-10h]@18
  int count; // [sp+18h] [bp-Ch]@24
  int index1; // [sp+1Ch] [bp-8h]@25
  int v41; // [sp+20h] [bp-4h]@26

  v1 = this;
  RGE_RMM_Database_Controller::add_object_module((RGE_RMM_Database_Controller *)&this->vfptr);
  debug_rand(aCMsdevWorkAg_4, 408);
  if ( TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game) == 1 )
  {
    v2 = 0;
    if ( v1->object_info.object_num > 0 )
    {
      v3 = &v1->object_info.objects[0].number_of_groups;
      do
      {
        if ( *(v3 - 5) == 83 )
          *v3 = 1;
        ++v2;
        v3 += 12;
      }
      while ( v2 < v1->object_info.object_num );
    }
    v4 = 0;
    if ( v1->object_info.object_num > 0 )
    {
      v5 = &v1->object_info.objects[0].number_of_groups;
      do
      {
        if ( *(v5 - 5) == 109 )
          *v5 = 0;
        ++v4;
        v5 += 12;
      }
      while ( v4 < v1->object_info.object_num );
    }
  }
  if ( v1->map_type == 6 )
  {
    v6 = v1->land_info.land_num;
    if ( v6 > 0 )
    {
      v7 = (char *)&v1->land_info + 52 * v6;
      v8 = v1->land_info.land_num;
      do
      {
        v9 = v7;
        v7 -= 52;
        --v8;
        qmemcpy(v9, v7, 0x34u);
      }
      while ( v8 );
    }
    v10 = v1->map_width;
    v11 = v1->map_height;
    v1->land_info.land[0].zone = v1->land_info.land_num;
    v1->land_info.land[0].terrain_type = 1;
    v1->land_info.land[0].area = 7;
    v1->land_info.land[0].base_size = 2;
    v12 = v1->map;
    v1->land_info.land[0].land_size = (signed __int64)((double)((v10 - 2 * (v10 / 6)) * (v11 - 2 * (v10 / 6))) * 0.7);
    v1->land_info.land[0].clumpiness_factor = 10;
    v1->land_info.land[0].x = v12->map_width / 2;
    v1->land_info.land[0].wall_1_avoidance_line = v10 / 6;
    v1->land_info.land[0].y = v12->map_height / 2;
    v13 = v1->land_info.land_num + 1;
    v1->land_info.land[0].wall_2_avoidance_line = v10 / 6;
    v1->land_info.land[0].wall_3_avoidance_line = v10 - v10 / 6;
    v1->land_info.land[0].wall_4_avoidance_line = v11 - v10 / 6;
    v1->land_info.land[0].wall_fade = 10;
    v1->land_info.land_num = v13;
  }
  if ( v1->map_type < 2 )
  {
    v14 = 4 * debug_rand(aCMsdevWorkAg_4, 451) / 0x7FFF + 1;
    v15 = v1->number_of_players;
    extra_island_roll = v14;
    if ( v14 + v15 > 10 )
    {
      extra_island_roll = 10 - v15;
      v14 = 10 - v15;
    }
    v16 = v1->land_info.land_num;
    v17 = v14 * (v1->map_width + v1->map_height) / v16;
    v18 = 0;
    if ( v16 > 0 )
    {
      v19 = v1->land_info.land;
      do
      {
        v20 = v19->land_size;
        ++v19;
        ++v18;
        v19[-1].land_size = v20 - v17;
      }
      while ( v18 < v1->land_info.land_num );
    }
    v21 = 0;
    if ( v14 > 0 )
    {
      do
      {
        v1->land_info.land[v1->land_info.land_num + v21].terrain_type = 0;
        v1->land_info.land[v1->land_info.land_num + v21].area = 7;
        v1->land_info.land[v1->land_info.land_num + v21].base_size = 3;
        v1->land_info.land[v1->land_info.land_num + v21].zone = LOBYTE(v1->land_info.land_num) + v21;
        count = 0;
        v1->land_info.land[v1->land_info.land_num + v21].land_size = (signed __int64)((double)(v1->map_width
                                                                                             + v1->map_height)
                                                                                    * 1.25);
        v1->land_info.land[v1->land_info.land_num + v21].clumpiness_factor = 10;
        v1->land_info.land[v1->land_info.land_num + v21].wall_1_avoidance_line = v1->land_info.wall_1_avoidance_line;
        v1->land_info.land[v1->land_info.land_num + v21].wall_2_avoidance_line = v1->land_info.wall_2_avoidance_line;
        v1->land_info.land[v1->land_info.land_num + v21].wall_3_avoidance_line = v1->land_info.wall_3_avoidance_line;
        (&v1->vfptr)[13 * (v21 + v1->land_info.land_num + 2)] = (RGE_Random_Map_ModuleVtbl *)v1->land_info.wall_4_avoidance_line;
        v1->land_info.land[v1->land_info.land_num + v21].wall_fade = v1->land_info.wall_fade;
        do
        {
          ++count;
          done = 1;
          v22 = (v1->map_width - 16) * debug_rand(aCMsdevWorkAg_4, 478) / 0x7FFF + 8;
          index1 = 0;
          v23 = (v1->map_height - 16) * debug_rand(aCMsdevWorkAg_4, 479) / 0x7FFF + 8;
          if ( v1->land_info.land_num <= 0 )
          {
LABEL_31:
            if ( done )
              break;
          }
          else
          {
            v24 = &v1->land_info.land[0].y;
            v41 = (int)&v1->land_info.land[0].y;
            while ( done )
            {
              if ( (v23 - *v24) * (v23 - *v24) + (v22 - *(v24 - 1)) * (v22 - *(v24 - 1)) < 400 )
                done = 0;
              v25 = v1->land_info.land_num;
              v24 = (int *)(v41 + 52);
              v27 = __OFSUB__(index1 + 1, v25);
              v26 = index1++ + 1 - v25 < 0;
              v41 += 52;
              if ( !(v26 ^ v27) )
                goto LABEL_31;
            }
          }
        }
        while ( count < 1000 );
        if ( count >= 1000 )
          extra_island_roll = v21;
        v1->land_info.land[v1->land_info.land_num + v21].x = v22;
        v1->land_info.land[v1->land_info.land_num + v21].y = v23;
        v1->object_info.objects[v1->object_info.object_num].terrain = -1;
        v1->object_info.objects[v1->object_info.object_num].group_flag = 2;
        v1->object_info.objects[v1->object_info.object_num].scale_flag = 0;
        v1->object_info.objects[v1->object_info.object_num].object_number_per_group = 8;
        v1->object_info.objects[v1->object_info.object_num].object_number_varience = 0;
        v1->object_info.objects[v1->object_info.object_num].number_of_groups = 1;
        v1->object_info.objects[v1->object_info.object_num].group_area = 4;
        v1->object_info.objects[v1->object_info.object_num].player_id = 0;
        v1->object_info.objects[v1->object_info.object_num].land_id = v1->land_info.land_num + v21;
        (&v1->vfptr)[12 * (v1->object_info.object_num + 209)] = 0;
        v1->object_info.objects[v1->object_info.object_num].land_outer_radius = 26;
        v1->object_info.objects[v1->object_info.object_num].object_exclusion_zone = 0;
        v28 = debug_rand(aCMsdevWorkAg_4, 509);
        v27 = __OFSUB__(v28, 0x3FFF);
        v26 = v28 - 0x3FFF < 0;
        v29 = v1->object_info.object_num;
        if ( v26 ^ v27 )
          v1->object_info.objects[v29].obj_id = 102;
        else
          v1->object_info.objects[v29].obj_id = 66;
        v30 = v1->object_info.land_num;
        ++v1->object_info.object_num;
        v1->object_info.lands[v30].y = v23;
        (&v1->vfptr)[4 * (v1->object_info.land_num + 922)] = (RGE_Random_Map_ModuleVtbl *)v22;
        v1->object_info.lands[v1->object_info.land_num].id = v1->land_info.land_num + v21;
        v1->object_info.lands[v1->object_info.land_num].player_id = 0;
        ++v21;
        ++v1->object_info.land_num;
      }
      while ( v21 < extra_island_roll );
      v14 = extra_island_roll;
    }
    v1->land_info.land_num += v14;
  }
  v31 = 0;
  if ( v1->object_info.object_num > 0 )
  {
    v32 = &v1->object_info.objects[0].object_exclusion_zone;
    do
    {
      v33 = *(v32 - 3);
      if ( v33 < 0 )
      {
        if ( v33 == -2 )
        {
          switch ( *(v32 - 11) )
          {
            case 65:
              v34 = v1->map->map_width;
              *v32 = ((BYTE4(v34) & 7) + (signed int)v34) >> 3;
              break;
            case 59:
            case 66:
              v35 = v1->map->map_width;
              goto LABEL_51;
            case 102:
              v35 = v1->map->map_width;
LABEL_51:
              *v32 = v35 / 6;
              break;
            default:
              break;
          }
        }
      }
      else
      {
        switch ( *(v32 - 11) )
        {
          case 59:
          case 65:
          case 66:
          case 102:
            *v32 = 12;
            break;
          default:
            break;
        }
      }
      ++v31;
      v32 += 12;
    }
    while ( v31 < v1->object_info.object_num );
  }
  v36 = debug_rand(aCMsdevWorkAg_4, 566);
  TDebuggingLog::Log(L, aRandomMapObjec, v36);
}

//----- (00488700) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::add_elevation_module(TRIBE_RMM_Database_Controller *this)
{
  TRIBE_RMM_Database_Controller *v1; // ebx@1
  double v2; // st7@1
  int v3; // edi@3
  RGE_Elevation_Info_Line *v4; // esi@4
  int v5; // eax@6

  v1 = this;
  RGE_RMM_Database_Controller::add_elevation_module((RGE_RMM_Database_Controller *)&this->vfptr);
  v2 = (70.0 - (double)debug_rand(aCMsdevWorkAg_4, 579) * -0.0018311106) * 0.0099999998;
  if ( v1->map_type == 7 )
    v2 = v2 * 5.0;
  v3 = 0;
  if ( v1->elevation_info.elevation_num > 0 )
  {
    v4 = v1->elevation_info.elevation;
    do
    {
      v4->elevation_size = (signed __int64)((double)v4->elevation_size * v2);
      ++v3;
      ++v4;
    }
    while ( v3 < v1->elevation_info.elevation_num );
  }
  v5 = debug_rand(aCMsdevWorkAg_4, 587);
  TDebuggingLog::Log(L, aRandomMapEleva, v5);
}

//----- (004887A0) --------------------------------------------------------
void __thiscall TRIBE_RMM_Database_Controller::add_shallows_module(TRIBE_RMM_Database_Controller *this)
{
  TRIBE_RMM_Database_Controller *v1; // esi@1
  int v2; // edx@1
  char *v3; // ecx@2
  int *v4; // eax@2
  RGE_RMM_Shallows_Generator *v5; // eax@4
  int v6; // eax@6
  RGE_Shallows_Info shallows_info; // [sp+Ch] [bp-328h]@1
  int v8; // [sp+330h] [bp-4h]@4

  v1 = this;
  v2 = 0;
  shallows_info.shallows_num = this->land_info.land_num;
  if ( shallows_info.shallows_num > 0 )
  {
    v3 = (char *)&shallows_info.shallows[0].y;
    v4 = &v1->land_info.land[0].y;
    do
    {
      ++v2;
      *((_DWORD *)v3 - 1) = *(v4 - 1);
      *(_DWORD *)v3 = *v4;
      v4 += 13;
      v3 += 8;
    }
    while ( v2 < shallows_info.shallows_num );
  }
  v5 = (RGE_RMM_Shallows_Generator *)operator new(0x34Cu);
  v8 = 0;
  if ( v5 )
    RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(
      v5,
      v1->map,
      (RGE_Random_Map_Module *)&v1->vfptr,
      &shallows_info);
  v8 = -1;
  v6 = debug_rand(aCMsdevWorkAg_4, 607);
  TDebuggingLog::Log(L, aRandomMapShall, v6);
}

//----- (00488870) --------------------------------------------------------
char __thiscall TRIBE_RMM_Database_Controller::generate(TRIBE_RMM_Database_Controller *this)
{
  TRIBE_RMM_Database_Controller *v1; // esi@1
  int v2; // ebx@1
  int v3; // ebp@2
  int v4; // edi@3
  int v5; // edx@4
  RGE_Tile **v6; // ecx@5
  char ret_num; // [sp+Bh] [bp-1h]@1

  v1 = this;
  ret_num = RGE_RMM_Database_Controller::generate((RGE_RMM_Database_Controller *)&this->vfptr);
  v2 = 0;
  if ( v1->map_height > 0 )
  {
    v3 = 0;
    do
    {
      v4 = 0;
      if ( v1->map_width > 0 )
      {
        v5 = 0;
        do
        {
          v6 = &v1->map_row_offset[v3];
          if ( (*((_BYTE *)&(*v6)[v5] + 5) & 0x1F) == 16 )
            *((_BYTE *)&(*v6)[v5] + 5) &= 0xE0u;
          ++v4;
          ++v5;
        }
        while ( v4 < v1->map_width );
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->map_height );
  }
  return ret_num;
}
