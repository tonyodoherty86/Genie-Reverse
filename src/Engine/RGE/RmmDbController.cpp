
//----- (00482B70) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(RGE_RMM_Database_Controller *this, char *land_file, char *terrain_file, char *object_file, char *map_file)
{
  int v5; // esi@1
  RGE_RMM_Database_Controller *v6; // edi@1
  FILE *v7; // eax@1
  FILE *v8; // ebx@1
  int *v9; // ebp@2
  int v10; // ebx@4
  FILE *v11; // eax@11
  FILE *v12; // ebp@11
  int v13; // esi@13
  size_t *v14; // ebx@13
  signed int v15; // ebp@14
  int v16; // edi@15
  int v17; // eax@16
  FILE *v18; // ebp@21
  int v19; // esi@23
  int v20; // ebx@23
  int v21; // edi@25
  FILE *v22; // eax@31
  FILE *v23; // ebp@31
  int v24; // esi@33
  int v25; // ebx@33
  int v26; // edi@35
  int v27; // eax@36
  _iobuf *infile; // [sp+10h] [bp-34h]@1
  _iobuf *infilea; // [sp+10h] [bp-34h]@11
  int map_id; // [sp+14h] [bp-30h]@13
  RGE_RMM_Database_Controller *v31; // [sp+18h] [bp-2Ch]@1
  int land_num; // [sp+1Ch] [bp-28h]@12
  int terrain_num; // [sp+20h] [bp-24h]@22
  int object_num; // [sp+24h] [bp-20h]@32
  int temp_terrain_type; // [sp+28h] [bp-1Ch]@16
  int temp_zone; // [sp+2Ch] [bp-18h]@16
  int temp_placement_type; // [sp+30h] [bp-14h]@16
  int temp_amount_of_land_used_percent; // [sp+34h] [bp-10h]@16
  int temp_by_player_flag; // [sp+38h] [bp-Ch]@16
  int temp_group_flag; // [sp+3Ch] [bp-8h]@36
  int temp_scale_flag; // [sp+40h] [bp-4h]@36
  char *map_filea; // [sp+54h] [bp+10h]@12
  char *map_fileb; // [sp+54h] [bp+10h]@22
  char *map_filec; // [sp+54h] [bp+10h]@32

  v5 = 0;
  v6 = this;
  v31 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, 0, 0, 0);
  v6->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Database_Controller::`vftable';
  v6->world = 0;
  v6->map_type = -1;
  v6->number_of_players = 0;
  v7 = fopen(map_file, Mode);
  v8 = v7;
  infile = v7;
  if ( !v7 )
  {
    v9 = &v6->map_info.map_num;
    v6->map_info.maps = 0;
    v6->map_info.map_num = 0;
    goto LABEL_10;
  }
  v9 = &v6->map_info.map_num;
  fscanf(v7, aD_5, &v6->map_info);
  if ( v6->map_info.map_num <= 0 )
  {
    v6->map_info.maps = 0;
    goto LABEL_8;
  }
  v6->map_info.maps = (RGE_Map_Data_Entry *)calloc(v6->map_info.map_num, 0x48u);
  if ( *v9 <= 0 )
  {
LABEL_8:
    fclose(v8);
    goto LABEL_10;
  }
  v10 = 0;
  do
  {
    fscanf(infile, aD_3, &v6->map_info.maps[v10]);
    ++v5;
    ++v10;
  }
  while ( v5 < *v9 );
  fclose(infile);
LABEL_10:
  if ( *v9 <= 0 )
  {
    *v9 = 0;
    v6->map_info.maps = 0;
  }
  else
  {
    v11 = fopen(land_file, Mode);
    v12 = v11;
    infilea = v11;
    if ( v11 )
    {
      fscanf(v11, aD_3, &land_num);
      map_filea = 0;
      if ( land_num > 0 )
      {
        do
        {
          fscanf(v12, aD_3, &map_id);
          v13 = (int)&v6->map_info.maps[map_id].land_info;
          v14 = (size_t *)&v6->map_info.maps[map_id].land_info.land_num;
          fscanf(
            v12,
            aDDDDDDDDD,
            v14,
            v13,
            &v6->map_info.maps[map_id].land_info.map_edge_buffer[1],
            &v6->map_info.maps[map_id].land_info.map_edge_buffer[2],
            &v6->map_info.maps[map_id].land_info.map_edge_buffer[3],
            &v6->map_info.maps[map_id].land_info.map_edge_fade,
            &v6->map_info.maps[map_id].land_info.land_placement_edge,
            &v6->map_info.maps[map_id].land_info.base_terrain,
            &v6->map_info.maps[map_id].land_info.grown_land_percent);
          if ( (signed int)*v14 <= 0 )
          {
            *(_DWORD *)(v13 + 40) = 0;
          }
          else
          {
            *(_DWORD *)(v13 + 40) = calloc(*v14, 0x2Cu);
            v15 = 0;
            if ( (signed int)*v14 > 0 )
            {
              v16 = 0;
              do
              {
                v17 = v16 + *(_DWORD *)(v13 + 40);
                fscanf(
                  infilea,
                  aDDDDDDDDDDDD,
                  v16 + *(_DWORD *)(v13 + 40),
                  &temp_terrain_type,
                  v17 + 8,
                  v17 + 12,
                  &temp_zone,
                  &temp_placement_type,
                  v17 + 20,
                  v17 + 24,
                  &temp_amount_of_land_used_percent,
                  &temp_by_player_flag,
                  v17 + 32,
                  v17 + 36);
                ++v15;
                *(_BYTE *)(*(_DWORD *)(v13 + 40) + v16 + 4) = temp_terrain_type;
                *(_BYTE *)(*(_DWORD *)(v13 + 40) + v16 + 16) = temp_zone;
                *(_BYTE *)(*(_DWORD *)(v13 + 40) + v16 + 17) = temp_placement_type;
                *(_BYTE *)(*(_DWORD *)(v13 + 40) + v16 + 28) = temp_amount_of_land_used_percent;
                *(_BYTE *)(*(_DWORD *)(v13 + 40) + v16 + 29) = temp_by_player_flag;
                *(_DWORD *)(*(_DWORD *)(v13 + 40) + v16 + 40) = 8;
                v16 += 44;
              }
              while ( v15 < (signed int)*v14 );
              v6 = v31;
            }
            v12 = infilea;
          }
          ++map_filea;
        }
        while ( (signed int)map_filea < land_num );
      }
      fclose(v12);
    }
    v18 = fopen(terrain_file, Mode);
    if ( v18 )
    {
      fscanf(v18, aD_3, &terrain_num);
      map_fileb = 0;
      if ( terrain_num > 0 )
      {
        do
        {
          fscanf(v18, aD_3, &map_id);
          v19 = (int)&v6->map_info.maps[map_id].terrain_info.terrain_num;
          fscanf(v18, aD_3, v19);
          v20 = 0;
          if ( *(_DWORD *)v19 <= 0 )
          {
            *(_DWORD *)(v19 + 4) = 0;
          }
          else
          {
            *(_DWORD *)(v19 + 4) = calloc(*(_DWORD *)v19, 0x18u);
            if ( *(_DWORD *)v19 > 0 )
            {
              v21 = 0;
              do
              {
                fscanf(
                  v18,
                  aDDDDD,
                  *(_DWORD *)(v19 + 4) + v21,
                  *(_DWORD *)(v19 + 4) + v21 + 4,
                  *(_DWORD *)(v19 + 4) + v21 + 8,
                  *(_DWORD *)(v19 + 4) + v21 + 12,
                  *(_DWORD *)(v19 + 4) + v21 + 16);
                ++v20;
                *(_DWORD *)(*(_DWORD *)(v19 + 4) + v21 + 20) = 20;
                v21 += 24;
              }
              while ( v20 < *(_DWORD *)v19 );
              v6 = v31;
            }
          }
          ++map_fileb;
        }
        while ( (signed int)map_fileb < terrain_num );
      }
      fclose(v18);
    }
    v22 = fopen(object_file, Mode);
    v23 = v22;
    if ( v22 )
    {
      fscanf(v22, aD_3, &object_num);
      map_filec = 0;
      if ( object_num > 0 )
      {
        do
        {
          fscanf(v23, aD_3, &map_id);
          v24 = (int)&v6->map_info.maps[map_id].object_info.object_num;
          fscanf(v23, aD_3, v24);
          v25 = 0;
          if ( *(_DWORD *)v24 <= 0 )
          {
            *(_DWORD *)(v24 + 4) = 0;
          }
          else
          {
            *(_DWORD *)(v24 + 4) = calloc(*(_DWORD *)v24, 0x2Cu);
            if ( *(_DWORD *)v24 > 0 )
            {
              v26 = 0;
              do
              {
                v27 = *(_DWORD *)(v24 + 4) + v26;
                fscanf(
                  v23,
                  aDDDDDDDDDDDD,
                  v27,
                  v27 + 4,
                  &temp_group_flag,
                  &temp_scale_flag,
                  v27 + 12,
                  v27 + 16,
                  v27 + 20,
                  v27 + 24,
                  v27 + 28,
                  v27 + 32,
                  v27 + 36,
                  v27 + 40);
                ++v25;
                *(_BYTE *)(*(_DWORD *)(v24 + 4) + v26 + 8) = temp_group_flag;
                *(_BYTE *)(*(_DWORD *)(v24 + 4) + v26 + 9) = temp_scale_flag;
                v26 += 44;
              }
              while ( v25 < *(_DWORD *)v24 );
              v6 = v31;
            }
          }
          ++map_filec;
        }
        while ( (signed int)map_filec < object_num );
      }
      fclose(v23);
    }
  }
}
// 571E88: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Database_Controller::`vftable')(RGE_RMM_Database_Controller *this);

//----- (00483020) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(RGE_RMM_Database_Controller *this, int infile)
{
  RGE_RMM_Database_Controller *v2; // edi@1
  int v3; // esi@1
  int *v4; // ebx@1
  RGE_Map_Data_Entry *v5; // eax@2
  int v6; // ecx@2
  RGE_Map_Data_Entry *v7; // edx@4
  int v8; // edi@4
  int v9; // ebx@4
  int v10; // ebp@4
  signed int v11; // eax@4
  void *v12; // eax@5
  void *v13; // eax@7
  void *v14; // eax@9
  RGE_Elevation_Data_Entry *v15; // eax@11
  int index; // [sp+10h] [bp-1Ch]@2
  RGE_RMM_Database_Controller *v17; // [sp+14h] [bp-18h]@1
  RGE_Elevation_Data *elevation_info; // [sp+18h] [bp-14h]@4
  int *v19; // [sp+1Ch] [bp-10h]@1
  int infilea; // [sp+30h] [bp+4h]@3

  v2 = this;
  v17 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, 0, 0, 0);
  v3 = infile;
  v4 = &v2->map_info.map_num;
  v2->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Database_Controller::`vftable';
  v2->world = 0;
  v2->map_type = -1;
  v2->number_of_players = 0;
  v19 = &v2->map_info.map_num;
  rge_read(0, (int)v2, infile, &v2->map_info, 8);
  if ( v2->map_info.map_num > 0 )
  {
    v5 = (RGE_Map_Data_Entry *)calloc(v2->map_info.map_num, 0x48u);
    v6 = *v4;
    v2->map_info.maps = v5;
    rge_read(0, (int)v2, infile, v5, 72 * v6);
    index = 0;
    if ( *v4 > 0 )
    {
      infilea = 0;
      do
      {
        v7 = v2->map_info.maps;
        v8 = (int)&v7[infilea].land_info;
        v9 = (int)&v7[infilea].terrain_info.terrain_num;
        v10 = (int)&v7[infilea].object_info.object_num;
        elevation_info = &v7[infilea].elevation_info;
        rge_read(v10, v8, v3, (void *)v8, 44);
        v11 = *(_DWORD *)(v8 + 36);
        if ( v11 > 0 )
        {
          v12 = calloc(v11, 0x2Cu);
          *(_DWORD *)(v8 + 40) = v12;
          v8 = *(_DWORD *)(v8 + 36);
          rge_read(v10, v8, v3, v12, 44 * v8);
        }
        rge_read(v10, v8, v3, (void *)v9, 8);
        if ( *(_DWORD *)v9 > 0 )
        {
          v13 = calloc(*(_DWORD *)v9, 0x18u);
          *(_DWORD *)(v9 + 4) = v13;
          rge_read(v10, v8, v3, v13, 24 * *(_DWORD *)v9);
        }
        rge_read(v10, v8, v3, (void *)v10, 8);
        if ( *(_DWORD *)v10 > 0 )
        {
          v14 = calloc(*(_DWORD *)v10, 0x2Cu);
          *(_DWORD *)(v10 + 4) = v14;
          v10 = *(_DWORD *)v10;
          rge_read(v10, v8, v3, v14, 44 * v10);
        }
        rge_read(v10, (int)elevation_info, v3, elevation_info, 8);
        if ( elevation_info->elevation_num > 0 )
        {
          v15 = (RGE_Elevation_Data_Entry *)calloc(elevation_info->elevation_num, 0x18u);
          elevation_info->elevation = v15;
          rge_read(v10, elevation_info->elevation_num, v3, v15, 24 * elevation_info->elevation_num);
        }
        ++infilea;
        v2 = v17;
        ++index;
      }
      while ( index < *v19 );
    }
  }
}
// 571E88: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Database_Controller::`vftable')(RGE_RMM_Database_Controller *this);

//----- (00483200) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller(RGE_RMM_Database_Controller *this)
{
  RGE_RMM_Database_Controller *v1; // esi@1
  int v2; // eax@1
  int v3; // ebx@3
  int v4; // edi@4
  int v5; // eax@5
  RGE_Map_Data_Entry *v6; // edx@7
  int v7; // eax@9
  int v8; // eax@11

  v1 = this;
  v2 = this->map_info.map_num;
  this->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Database_Controller::`vftable';
  if ( v2 > 0 && this->map_info.maps )
  {
    v3 = 0;
    if ( v2 > 0 )
    {
      v4 = 0;
      do
      {
        v5 = (int)&v1->map_info.maps[v4].map_id;
        if ( *(_DWORD *)(v5 + 40) > 0 )
          free(*(void **)(v5 + 44));
        v6 = v1->map_info.maps;
        if ( v6[v4].terrain_info.terrain_num > 0 )
          free(v6[v4].terrain_info.terrain);
        v7 = (int)&v1->map_info.maps[v4].map_id;
        if ( *(_DWORD *)(v7 + 56) > 0 )
          free(*(void **)(v7 + 60));
        v8 = (int)&v1->map_info.maps[v4].map_id;
        if ( *(_DWORD *)(v8 + 64) > 0 )
          free(*(void **)(v8 + 68));
        ++v3;
        ++v4;
      }
      while ( v3 < v1->map_info.map_num );
    }
    free(v1->map_info.maps);
    v1->map_info.map_num = 0;
  }
  RGE_Random_Map_Module::~RGE_Random_Map_Module((RGE_Random_Map_Module *)&v1->vfptr);
}
// 571E88: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Database_Controller::`vftable')(RGE_RMM_Database_Controller *this);

//----- (004832E0) --------------------------------------------------------
char __thiscall RGE_RMM_Database_Controller::save(RGE_RMM_Database_Controller *this, int outfile)
{
  int v2; // esi@1
  RGE_RMM_Database_Controller *v3; // edi@1
  char *v4; // ebx@1
  RGE_Map_Data_Entry *v5; // edx@5
  int v6; // edi@5
  int v7; // ebx@5
  int v8; // ebp@5
  int v9; // eax@5
  bool v10; // sf@13
  unsigned __int8 v11; // of@13
  int index; // [sp+10h] [bp-10h]@2
  RGE_RMM_Database_Controller *v14; // [sp+14h] [bp-Ch]@1
  RGE_Elevation_Data *elevation_info; // [sp+18h] [bp-8h]@5
  char *v16; // [sp+1Ch] [bp-4h]@1
  int outfilea; // [sp+24h] [bp+4h]@3

  v2 = outfile;
  v3 = this;
  v14 = this;
  v4 = (char *)&this->map_info;
  v16 = (char *)&this->map_info;
  rge_write(outfile, &this->map_info, 8);
  if ( *(_DWORD *)v4 > 0 )
  {
    rge_write(outfile, v3->map_info.maps, 72 * *(_DWORD *)v4);
    index = 0;
    if ( *(_DWORD *)v4 > 0 )
    {
      outfilea = 0;
      while ( 1 )
      {
        v5 = v3->map_info.maps;
        v6 = (int)&v5[outfilea].land_info;
        v7 = (int)&v5[outfilea].terrain_info.terrain_num;
        v8 = (int)&v5[outfilea].object_info.object_num;
        elevation_info = &v5[outfilea].elevation_info;
        rge_write(v2, (void *)v6, 44);
        v9 = *(_DWORD *)(v6 + 36);
        if ( v9 > 0 )
          rge_write(v2, *(void **)(v6 + 40), 44 * v9);
        rge_write(v2, (void *)v7, 8);
        if ( *(_DWORD *)v7 > 0 )
          rge_write(v2, *(void **)(v7 + 4), 24 * *(_DWORD *)v7);
        rge_write(v2, (void *)v8, 8);
        if ( *(_DWORD *)v8 > 0 )
          rge_write(v2, *(void **)(v8 + 4), 44 * *(_DWORD *)v8);
        rge_write(v2, elevation_info, 8);
        if ( elevation_info->elevation_num > 0 )
          rge_write(v2, elevation_info->elevation, 24 * elevation_info->elevation_num);
        v11 = __OFSUB__(index + 1, *(_DWORD *)v16);
        v10 = index++ + 1 - *(_DWORD *)v16 < 0;
        ++outfilea;
        if ( !(v10 ^ v11) )
          break;
        v3 = v14;
      }
    }
  }
  return 1;
}

//----- (00483430) --------------------------------------------------------
char __thiscall RGE_RMM_Database_Controller::generate(RGE_RMM_Database_Controller *this)
{
  RGE_RMM_Database_Controller *v1; // esi@1
  RGE_RMM_Terrain_Generator *v2; // eax@1
  RGE_RMM_Land_Generator *v3; // eax@3
  RGE_RMM_Object_Generator *v4; // eax@5
  RGE_RMM_Elevation_Generator *v5; // eax@7

  v1 = this;
  v2 = (RGE_RMM_Terrain_Generator *)operator new(0x12CCu);
  if ( v2 )
    RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(
      v2,
      v1->map,
      (RGE_Random_Map_Module *)&v1->vfptr,
      &v1->terrain_info);
  v3 = (RGE_RMM_Land_Generator *)operator new(0x1468u);
  if ( v3 )
    RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(v3, v1->map, (RGE_Random_Map_Module *)&v1->vfptr, &v1->land_info);
  v4 = (RGE_RMM_Object_Generator *)operator new(0x1920u);
  if ( v4 )
    RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(
      v4,
      v1->map,
      (RGE_Random_Map_Module *)&v1->vfptr,
      v1->world,
      &v1->object_info,
      1);
  v5 = (RGE_RMM_Elevation_Generator *)operator new(0xFB0u);
  if ( v5 )
    RGE_RMM_Elevation_Generator::RGE_RMM_Elevation_Generator(
      v5,
      v1->map,
      (RGE_Random_Map_Module *)&v1->vfptr,
      &v1->elevation_info);
  return RGE_Random_Map_Module::generate((RGE_Random_Map_Module *)&v1->vfptr);
}

//----- (00483540) --------------------------------------------------------
char __thiscall RGE_RMM_Database_Controller::init(RGE_RMM_Database_Controller *this, RGE_Map *in_map, RGE_Game_World *in_world, char type, int player_num, int fixed_positions)
{
  RGE_RMM_Database_Controller *v6; // esi@1
  RGE_Random_Map_ModuleVtbl *v7; // edi@1

  v6 = this;
  this->world = in_world;
  this->map_type = (unsigned __int8)type;
  this->number_of_players = player_num;
  RGE_Random_Map_Module::update_map_info((RGE_Random_Map_Module *)&this->vfptr, in_map);
  RGE_Random_Map_Module::create_shared_resources((RGE_Random_Map_Module *)&v6->vfptr);
  v7 = v6->vfptr;
  ((void (__thiscall *)(RGE_RMM_Database_Controller *, int))v6->vfptr[1].generate)(v6, fixed_positions);
  v7[2].generate((RGE_Random_Map_Module *)v6);
  v7[3].generate((RGE_Random_Map_Module *)v6);
  v7[4].generate((RGE_Random_Map_Module *)v6);
  return 1;
}

//----- (004835A0) --------------------------------------------------------
char __thiscall RGE_RMM_Database_Controller::de_init(RGE_RMM_Database_Controller *this)
{
  RGE_RMM_Database_Controller *v1; // edi@1
  RGE_Random_Map_Module_List *v2; // eax@1
  RGE_Random_Map_Module *v3; // esi@2

  v1 = this;
  v2 = this->list;
  this->world = 0;
  this->map_type = -1;
  for ( this->number_of_players = 0; v2; v2 = v1->list )
  {
    v3 = v2->module;
    if ( v2->module )
    {
      RGE_Random_Map_Module::~RGE_Random_Map_Module(v2->module);
      operator delete(v3);
    }
  }
  RGE_Random_Map_Module::destroy_shared_resources((RGE_Random_Map_Module *)&v1->vfptr);
  RGE_Random_Map_Module::update_map_info((RGE_Random_Map_Module *)&v1->vfptr, 0);
  return 0;
}

//----- (00483600) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::calc_land_start(RGE_RMM_Database_Controller *this, int land_index, int edge, int land_num, RGE_Land_Data_Entry *info)
{
  RGE_RMM_Database_Controller *v5; // edi@1
  int v6; // eax@1
  int v7; // ebx@1
  signed int v8; // esi@1
  int v9; // ebp@1
  double v10; // st7@1
  double v11; // ST4C_8@6
  double v12; // ST40_8@6
  signed __int64 v13; // rax@6
  double v14; // st7@6
  signed __int64 v15; // rax@6
  int v16; // esi@10
  int v17; // ecx@12
  int v18; // esi@19
  int v19; // ebp@19
  int v20; // ecx@23
  int *v21; // edx@24
  int v22; // eax@33
  int v23; // edx@39
  int *v24; // eax@39
  int v25; // esi@43
  int v26; // eax@44
  unsigned int v27; // edx@44
  int v28; // edx@44
  bool v29; // zf@44
  int mid_x1; // [sp+10h] [bp-30h]@6
  int mid_x2; // [sp+14h] [bp-2Ch]@6
  int mid_y1; // [sp+18h] [bp-28h]@6
  int *v33; // [sp+1Ch] [bp-24h]@18
  int mid_y2; // [sp+20h] [bp-20h]@6
  int v35; // [sp+24h] [bp-1Ch]@25
  int v36; // [sp+28h] [bp-18h]@24
  float bound_square; // [sp+34h] [bp-Ch]@6
  int v38; // [sp+38h] [bp-8h]@17
  int edgea; // [sp+48h] [bp+8h]@17
  char index; // [sp+4Ch] [bp+Ch]@19
  int not_done; // [sp+50h] [bp+10h]@27

  v5 = this;
  v6 = debug_rand(aCMsdevWorkA_19, 451);
  TDebuggingLog::Log(L, aRandomMapCalcL, v6);
  v7 = edge;
  v8 = v5->map_width;
  v9 = 2 * edge;
  v10 = (double)(v5->map_width - 2 * edge) / sqrt((double)land_num);
  if ( land_num <= 3 )
  {
    if ( land_num < 7 )
      goto LABEL_6;
  }
  else if ( land_num < 7 )
  {
    v10 = v10 * 0.89999998;
    goto LABEL_6;
  }
  v10 = v10 * 0.80000001;
LABEL_6:
  bound_square = v10 * v10;
  v11 = (double)(v8 / 2);
  mid_x1 = (signed __int64)(v11 - v10 * 0.9);
  v12 = (double)(v5->map_height / 2);
  v13 = (signed __int64)(v12 - v10 * 0.9);
  v14 = v10 * -0.9;
  mid_y1 = v13;
  mid_x2 = (signed __int64)(v11 - v14);
  v15 = (signed __int64)(v12 - v14);
  mid_y2 = v15;
  if ( mid_x1 <= edge )
    mid_x1 = edge + 1;
  if ( mid_y1 <= edge )
    mid_y1 = edge + 1;
  v16 = v8 - edge;
  if ( mid_x2 >= v16 - 1 )
    mid_x2 = v16 - 2;
  v17 = v5->map_height - edge;
  if ( (signed int)v15 >= v17 - 1 )
    mid_y2 = v17 - 2;
  if ( info->placement_type )
  {
    if ( info->placement_type == 1 )
    {
      TDebuggingLog::Log(L, aRandomMapCal_3);
      if ( land_index < land_num + land_index )
      {
        v23 = land_num;
        v24 = &v5->land_info.land[land_index].y;
        do
        {
          *(v24 - 1) = info->x;
          *v24 = info->y;
          v24 += 13;
          --v23;
        }
        while ( v23 );
      }
    }
    else if ( info->placement_type == 2 )
    {
      TDebuggingLog::Log(L, aRandomMapCal_5);
      edgea = land_index;
      v38 = land_index + land_num;
      if ( land_index < land_index + land_num )
      {
        v33 = &v5->land_info.land[land_index].y;
        while ( 1 )
        {
          index = 0;
          v18 = v7 + (v5->map_width - 2 * v7) * debug_rand(aCMsdevWorkA_19, 508) / 0x7FFF;
          v19 = v7 + (v5->map_height - 2 * v7) * debug_rand(aCMsdevWorkA_19, 509) / 0x7FFF;
          if ( v18 <= mid_x1 || v18 >= mid_x2 || v19 <= mid_y1 || v19 >= mid_y2 )
          {
            v20 = land_index;
            if ( land_index >= edgea )
              goto LABEL_35;
            v21 = &v5->land_info.land[land_index].y;
            v36 = (int)&v5->land_info.land[land_index].y;
            while ( 1 )
            {
              v35 = v18 - *(v21 - 1);
              if ( v35 < 0 )
                v35 = -(v18 - *(v21 - 1));
              not_done = v19 - *v21;
              if ( not_done < 0 )
                not_done = -(v19 - *v21);
              if ( (double)(not_done * not_done + v35 * v35) <= bound_square )
                break;
              ++v20;
              v21 = (int *)(v36 + 52);
              v36 += 52;
              if ( v20 >= edgea )
                goto LABEL_35;
            }
            if ( v20 == edgea - 1 )
            {
              v22 = (int)v5 + 52 * v20;
              *(_DWORD *)(v22 + 72) = v19;
              *(_DWORD *)(v22 + 68) = v18;
              TDebuggingLog::Log(L, aRandomMapCal_2, v20, v18, v19);
            }
          }
          index = 1;
LABEL_35:
          if ( !index )
          {
            *(v33 - 1) = v18;
            *v33 = v19;
            TDebuggingLog::Log(L, aRandomMapCal_2, edgea++, v18, v19);
            v33 += 13;
            if ( edgea >= v38 )
              break;
          }
        }
      }
    }
  }
  else
  {
    TDebuggingLog::Log(L, aRandomMapCal_4);
    if ( land_index < land_index + land_num )
    {
      v25 = (int)&v5->land_info.land[land_index].y;
      do
      {
        v26 = debug_rand(aCMsdevWorkA_19, 485);
        v27 = (signed int)((v5->map_width - v9) * v26
                         + ((unsigned __int64)(-2147418109i64 * (v5->map_width - v9) * v26) >> 32)) >> 14;
        *(_DWORD *)(v25 - 4) = edge + (v27 >> 31) + v27;
        v25 += 52;
        v28 = edge + (v5->map_height - v9) * debug_rand(aCMsdevWorkA_19, 486) / 0x7FFF;
        v29 = land_num == 1;
        *(_DWORD *)(v25 - 52) = v28;
        --land_num;
      }
      while ( !v29 );
    }
  }
  TDebuggingLog::Log(L, aRandomMapCal_0);
}

//----- (00483A20) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::add_land_module(RGE_RMM_Database_Controller *this, char fixed_positions)
{
  RGE_RMM_Database_Controller *v2; // ebp@1
  int v3; // ebx@1
  int v4; // edi@1
  char *v5; // esi@1
  unsigned int v6; // edx@1
  int v7; // ecx@1
  int i; // eax@1
  int v9; // ebx@6
  int v10; // edi@7
  RGE_Land_Data_Entry *v11; // eax@9
  int v12; // ecx@11
  int v13; // edx@12
  int v14; // ebp@17
  int v15; // ecx@17
  RGE_RMM_Database_Controller *v16; // edx@20
  int v17; // ebp@20
  signed int v18; // ebx@20
  int *v19; // esi@24
  int v20; // edx@24
  signed int v21; // edi@24
  int v22; // ebp@25
  signed int v23; // eax@27
  int (*v24)[8]; // ecx@28
  signed int v25; // edi@30
  signed int v26; // esi@30
  int *v27; // ecx@31
  int v28; // eax@32
  int v29; // edx@33
  int v30; // edi@33
  char *v31; // eax@33
  int v32; // edx@33
  int v33; // edx@39
  int *v34; // ecx@40
  int v35; // edi@40
  int *v36; // ebp@40
  int v37; // eax@42
  int *v38; // edi@43
  int v39; // esi@44
  int v40; // eax@45
  int v41; // ecx@50
  int v42; // ebp@53
  int v43; // eax@54
  int *v44; // ecx@55
  int v45; // ebx@58
  int v46; // eax@61
  int *v47; // ecx@62
  int v48; // ebp@70
  int v49; // eax@70
  char *v50; // ecx@71
  int v51; // edi@76
  int v52; // esi@76
  int *v53; // edx@77
  int v54; // ecx@78
  int v55; // eax@82
  int *v56; // edx@83
  char *v57; // ebx@89
  int v58; // edx@91
  int *v59; // ecx@92
  int v60; // eax@93
  bool v61; // sf@102
  unsigned __int8 v62; // of@102
  int v63; // edi@105
  int *v64; // edx@106
  int v65; // eax@107
  int v66; // ecx@114
  RGE_RMM_Database_Controller *v67; // esi@115
  int *v68; // edx@115
  int v69; // eax@116
  int v70; // eax@119
  int *v71; // ecx@120
  int v72; // edx@121
  RGE_RMM_Database_Controller *v73; // [sp+10h] [bp-190h]@1
  int current_team; // [sp+14h] [bp-18Ch]@10
  int (*current_teama)[8]; // [sp+14h] [bp-18Ch]@21
  int current_teamb; // [sp+14h] [bp-18Ch]@39
  int index; // [sp+18h] [bp-188h]@20
  int indexa; // [sp+18h] [bp-188h]@39
  int indexb; // [sp+18h] [bp-188h]@52
  int index1; // [sp+1Ch] [bp-184h]@6
  int *index1a; // [sp+1Ch] [bp-184h]@21
  int index1b; // [sp+1Ch] [bp-184h]@58
  int edge; // [sp+20h] [bp-180h]@1
  int *edgea; // [sp+20h] [bp-180h]@40
  int *edgeb; // [sp+20h] [bp-180h]@53
  int v86; // [sp+24h] [bp-17Ch]@50
  int land_wanted; // [sp+28h] [bp-178h]@1
  int v88; // [sp+2Ch] [bp-174h]@89
  int v89; // [sp+30h] [bp-170h]@43
  int v90; // [sp+30h] [bp-170h]@59
  int swap; // [sp+34h] [bp-16Ch]@0
  int start_land; // [sp+38h] [bp-168h]@58
  int ty[8]; // [sp+3Ch] [bp-164h]@51
  int v94; // [sp+5Ch] [bp-144h]@58
  int team_size[8]; // [sp+60h] [bp-140h]@24
  int player_teams[8]; // [sp+80h] [bp-120h]@33
  int distances[8][8]; // [sp+A0h] [bp-100h]@21

  v2 = this;
  v73 = this;
  v3 = this->map_width;
  v4 = this->map_height;
  v5 = (char *)&this->map_info.maps[this->map_type].land_info;
  v6 = (unsigned __int64)(1374389535i64 * v4 * v3 * this->map_info.maps[this->map_type].land_info.grown_land_percent) >> 32;
  edge = this->map_info.maps[this->map_type].land_info.land_placement_edge;
  v7 = 0;
  land_wanted = (v6 >> 31) + ((signed int)v6 >> 5);
  v73->land_info.land_num = 0;
  for ( i = 0; i < *((_DWORD *)v5 + 9); v7 += 44 )
  {
    if ( *(_BYTE *)(v7 + *((_DWORD *)v5 + 10) + 29) )
      v2->land_info.land_num += v2->number_of_players;
    else
      ++v2->land_info.land_num;
    ++i;
  }
  v2->land_info.base_terrain = v5[24];
  v2->land_info.wall_1_avoidance_line = *(_DWORD *)v5;
  v2->land_info.wall_2_avoidance_line = *((_DWORD *)v5 + 1);
  v2->land_info.wall_3_avoidance_line = v3 - *((_DWORD *)v5 + 2);
  v9 = 0;
  v2->land_info.wall_4_avoidance_line = v4 - *((_DWORD *)v5 + 3);
  v2->land_info.wall_fade = v5[16];
  index1 = 0;
  if ( *((_DWORD *)v5 + 9) > 0 )
  {
    v10 = 0;
    while ( 1 )
    {
      v11 = (RGE_Land_Data_Entry *)(v10 + *((_DWORD *)v5 + 10));
      if ( v11->by_player_flag )
      {
        RGE_RMM_Database_Controller::calc_land_start(v2, v9, edge, v2->number_of_players, v11);
        current_team = 0;
        if ( v2->number_of_players > 0 )
        {
          v12 = (int)&v73->land_info.land[v9].area;
          do
          {
            *(_DWORD *)(v12 - 16) = *(_BYTE *)(v10 + *((_DWORD *)v5 + 10) + 4);
            *(_DWORD *)v12 = *(_DWORD *)(v10 + *((_DWORD *)v5 + 10) + 8);
            *(_DWORD *)(v12 - 4) = *(_DWORD *)(v10 + *((_DWORD *)v5 + 10) + 12);
            v13 = *((_DWORD *)v5 + 10);
            if ( *(_BYTE *)(v10 + v13 + 29) == 1 )
              *(_BYTE *)(v12 + 4) = *(_BYTE *)(v10 + v13 + 16);
            else
              *(_BYTE *)(v12 + 4) = current_team;
            v12 += 52;
            ++v9;
            *(_DWORD *)(v12 - 72) = land_wanted
                                  * *(_BYTE *)(v10 + *((_DWORD *)v5 + 10) + 28)
                                  / (100
                                   * v73->number_of_players);
            *(_DWORD *)(v12 - 44) = *(_DWORD *)(v10 + *((_DWORD *)v5 + 10) + 40);
            *(_DWORD *)(v12 - 40) = v73->land_info.wall_1_avoidance_line;
            *(_DWORD *)(v12 - 36) = v73->land_info.wall_2_avoidance_line;
            *(_DWORD *)(v12 - 32) = v73->land_info.wall_3_avoidance_line;
            *(_DWORD *)(v12 - 28) = v73->land_info.wall_4_avoidance_line;
            *(_BYTE *)(v12 - 24) = v73->land_info.wall_fade;
            ++current_team;
          }
          while ( current_team < v73->number_of_players );
        }
      }
      else
      {
        v14 = (int)v73 + 52 * v9;
        *(_DWORD *)(v14 + 64) = v11->terrain_type;
        *(_DWORD *)(v14 + 80) = *(_DWORD *)(v10 + *((_DWORD *)v5 + 10) + 8);
        *(_DWORD *)(v14 + 76) = *(_DWORD *)(v10 + *((_DWORD *)v5 + 10) + 12);
        *(_BYTE *)(v14 + 84) = *(_BYTE *)(v10 + *((_DWORD *)v5 + 10) + 16);
        RGE_RMM_Database_Controller::calc_land_start(
          v73,
          v9,
          edge,
          1,
          (RGE_Land_Data_Entry *)(*((_DWORD *)v5 + 10) + v10));
        *(_DWORD *)(v14 + 60) = land_wanted * *(_BYTE *)(v10 + *((_DWORD *)v5 + 10) + 28) / 100;
        *(_DWORD *)(v14 + 88) = *(_DWORD *)(v10 + *((_DWORD *)v5 + 10) + 40);
        *(_DWORD *)(v14 + 92) = v73->land_info.wall_1_avoidance_line;
        *(_DWORD *)(v14 + 96) = v73->land_info.wall_2_avoidance_line;
        *(_DWORD *)(v14 + 100) = v73->land_info.wall_3_avoidance_line;
        v15 = v9++ + 2;
        (&v73->vfptr)[13 * v15] = (RGE_Random_Map_ModuleVtbl *)v73->land_info.wall_4_avoidance_line;
        *(_BYTE *)(v14 + 108) = v73->land_info.wall_fade;
      }
      v10 += 44;
      if ( ++index1 >= *((_DWORD *)v5 + 9) )
        break;
      v2 = v73;
    }
  }
  if ( fixed_positions )
  {
    v16 = v73;
    v17 = 0;
    index = 0;
    v18 = v73->land_info.land_num;
    if ( v18 > 0 )
    {
      current_teama = distances;
      index1a = &v73->land_info.land[0].y;
      while ( 1 )
      {
        if ( v18 > 0 )
        {
          v19 = team_size;
          v20 = (int)&v16->land_info.land[0].y;
          v21 = v18;
          do
          {
            v22 = *(_DWORD *)(v20 - 4);
            v20 += 52;
            ++v19;
            --v21;
            *(v19 - 1) = (*index1a - *(_DWORD *)(v20 - 52)) * (*index1a - *(_DWORD *)(v20 - 52))
                       + (*(index1a - 1) - v22) * (*(index1a - 1) - v22);
          }
          while ( v21 );
          v17 = index;
        }
        v23 = 0;
        if ( v18 > 0 )
        {
          v24 = current_teama;
          do
          {
            (*v24)[0] = v23++;
            v24 = (int (*)[8])((char *)v24 + 4);
          }
          while ( v23 < v18 );
        }
        do
        {
          v25 = 1;
          v26 = 1;
          if ( v18 > 1 )
          {
            v27 = &team_size[1];
            do
            {
              v28 = *(v27 - 1);
              if ( v28 > *v27 )
              {
                *(v27 - 1) = *v27;
                v29 = v26 + 8 * v17;
                *v27 = v28;
                v30 = distances[0][v29];
                v31 = (char *)distances + 4 * v29;
                v32 = player_teams[v29 + 7];
                *((_DWORD *)v31 - 1) = v30;
                *(_DWORD *)v31 = v32;
                v25 = 0;
              }
              ++v26;
              ++v27;
            }
            while ( v26 < v18 );
          }
        }
        while ( !v25 );
        index = ++v17;
        index1a += 13;
        ++current_teama;
        if ( v17 >= v18 )
          break;
        v16 = v73;
      }
    }
    if ( v18 > 0 )
      memset(player_teams, 0xFFu, 4 * v18);
    v33 = 0;
    current_teamb = 0;
    indexa = 0;
    if ( v18 > 0 )
    {
      v34 = player_teams;
      v35 = 4 - (_DWORD)player_teams;
      v36 = team_size;
      edgea = player_teams;
      do
      {
        if ( *v34 == -1 )
        {
          v37 = 0;
          *v34 = v33;
          *v36 = 1;
          if ( v18 > 0 )
          {
            v89 = (int)v34 + v35;
            v38 = player_teams;
            do
            {
              v39 = v37 + 1;
              if ( !RGE_Player::relation(*(RGE_Player **)((char *)v73->world->players + v89), v37 + 1) )
              {
                v40 = *v36 + 1;
                *v38 = current_teamb;
                *v36 = v40;
              }
              v37 = v39;
              ++v38;
            }
            while ( v39 < v73->land_info.land_num );
            v33 = current_teamb;
            v35 = 4 - (_DWORD)player_teams;
            v34 = edgea;
          }
          ++v33;
          ++v36;
          current_teamb = v33;
        }
        ++v34;
        v18 = v73->land_info.land_num;
        ++indexa;
        edgea = v34;
      }
      while ( indexa < v18 );
    }
    v41 = v73->land_info.land_num;
    v86 = v73->land_info.land_num;
    if ( v41 > 0 )
      memset(ty, 0xFFu, 4 * v41);
    indexb = 0;
    if ( v33 > 0 )
    {
      v42 = v86;
      edgeb = team_size;
      do
      {
        v43 = 0;
        if ( v42 > 0 )
        {
          v44 = ty;
          do
          {
            if ( *v44 == -1 )
              break;
            ++v43;
            ++v44;
          }
          while ( v43 < v42 );
        }
        start_land = v43;
        index1b = 0;
        v45 = *edgeb;
        v94 = *edgeb;
        if ( v94 > 0 )
        {
          v90 = v45;
          do
          {
            while ( 1 )
            {
              v46 = 0;
              if ( v45 > 0 )
              {
                v47 = distances[start_land];
                while ( ty[*v47] != -1 )
                {
                  ++v46;
                  ++v47;
                  if ( v46 >= v45 )
                    goto LABEL_67;
                }
                ty[*v47] = indexb;
              }
LABEL_67:
              if ( v46 < v45 )
                break;
              if ( v45 < v42 )
                v90 = ++v45;
              v48 = v42 - 1;
              v49 = v48;
              if ( v48 >= 0 )
              {
                v50 = (char *)distances + 4 * (v48 + 8 * start_land);
                while ( ty[*(_DWORD *)v50] != -1 )
                {
                  --v49;
                  v50 -= 4;
                  if ( v49 < 0 )
                    goto LABEL_76;
                }
                swap = *(_DWORD *)v50;
              }
LABEL_76:
              v51 = -1;
              v52 = 0;
              if ( v86 > 0 )
              {
                v53 = distances[swap];
                while ( 1 )
                {
                  v54 = ty[*v53];
                  if ( v54 != indexb && v54 > -1 )
                    break;
                  ++v52;
                  ++v53;
                  if ( v52 >= v86 )
                    goto LABEL_88;
                }
                v51 = ty[*v53];
                land_wanted = *v53;
                v55 = 0;
                if ( v45 > 0 )
                {
                  v56 = distances[start_land];
                  while ( ty[*v56] != v51 )
                  {
                    ++v55;
                    ++v56;
                    if ( v55 >= v45 )
                      goto LABEL_88;
                  }
                  v51 = ty[*v56];
                  land_wanted = *v56;
                }
              }
LABEL_88:
              ty[swap] = v51;
              ty[land_wanted] = -1;
              if ( v48 < 0 )
              {
                v42 = v86;
              }
              else
              {
                v88 = v48 + 1;
                v57 = (char *)distances + 4 * (v48 + 8 * v51);
                do
                {
                  if ( ty[*(_DWORD *)v57] == v51 )
                  {
                    v58 = 0;
                    if ( v86 > 0 )
                    {
                      v59 = distances[swap];
                      while ( 1 )
                      {
                        v60 = *v59;
                        if ( ty[*v59] == -1 && v60 != land_wanted )
                          break;
                        ++v58;
                        ++v59;
                        if ( v58 >= v86 )
                          goto LABEL_98;
                      }
                      ty[*(_DWORD *)v57] = -1;
                      ty[v60] = v51;
                    }
                  }
LABEL_98:
                  v57 -= 4;
                  --v88;
                }
                while ( v88 );
                v42 = v86;
                v45 = v90;
              }
            }
            ++index1b;
          }
          while ( index1b < v94 );
          v33 = current_teamb;
        }
        v62 = __OFSUB__(indexb + 1, v33);
        v61 = indexb++ + 1 - v33 < 0;
        ++edgeb;
      }
      while ( v61 ^ v62 );
    }
    if ( v86 > 0 )
      memset(team_size, 0xFFu, 4 * v86);
    v63 = 0;
    if ( v86 > 0 )
    {
      v64 = ty;
      do
      {
        v65 = 0;
        if ( v86 > 0 )
        {
          while ( team_size[v65] != -1 || player_teams[v65] != *v64 )
          {
            if ( ++v65 >= v86 )
              goto LABEL_113;
          }
          team_size[v65] = v63;
        }
LABEL_113:
        ++v63;
        ++v64;
      }
      while ( v63 < v86 );
    }
    v66 = 0;
    if ( v86 <= 0 )
    {
      v67 = v73;
    }
    else
    {
      v67 = v73;
      v68 = ty;
      do
      {
        v69 = team_size[v66++];
        ++v68;
        v69 *= 13;
        team_size[v66 + 7] = *(&v73->land_info.land[0].x + v69);
        *(v68 - 1) = *(&v73->land_info.land[0].y + v69);
      }
      while ( v66 < v86 );
    }
    v70 = 0;
    if ( v86 > 0 )
    {
      v71 = &v67->land_info.land[0].y;
      do
      {
        v72 = player_teams[v70++];
        *(v71 - 1) = v72;
        *v71 = *(&start_land + v70);
        v71 += 13;
      }
      while ( v70 < v67->land_info.land_num );
    }
  }
}

//----- (00484160) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::add_terrain_module(RGE_RMM_Database_Controller *this)
{
  RGE_RMM_Database_Controller *v1; // ebx@1
  int v2; // ebp@1
  RGE_Map_Data_Entry *v3; // esi@1
  signed int v4; // edx@1
  unsigned int v5; // eax@1
  char *v6; // edi@2
  int v7; // edx@3
  int v8; // edi@4
  int v9; // ecx@4
  int v10; // eax@5
  int *v11; // eax@8
  int *v12; // edx@8
  int v13; // eax@11
  int v14; // ebp@11
  int index; // [sp+10h] [bp-Ch]@1
  int indexa; // [sp+10h] [bp-Ch]@4
  int land_tile_num; // [sp+14h] [bp-8h]@1
  int land_tile_numa; // [sp+14h] [bp-8h]@7

  v1 = this;
  v2 = 0;
  index = 0;
  v3 = &this->map_info.maps[this->map_type];
  v4 = (signed int)((unsigned __int64)(1374389535i64 * v3->land_info.grown_land_percent * v1->map_height * v1->map_width) >> 32) >> 5;
  v5 = (signed int)((unsigned __int64)(1374389535i64 * v3->land_info.grown_land_percent * v1->map_height * v1->map_width) >> 32) >> 5;
  this->terrain_info.terrain_num = v3->terrain_info.terrain_num;
  land_tile_num = (v5 >> 31) + v4;
  if ( v3->terrain_info.terrain_num > 0 )
  {
    v6 = (char *)&this->terrain_info.terrain[0].terrain_type;
    do
    {
      *((_DWORD *)v6 - 2) = (signed __int64)((double)(land_tile_num * v3->terrain_info.terrain[v2].terrain_percent)
                                           * 0.0099999998);
      v6 += 32;
      v7 = v3->terrain_info.terrain[v2].terrain_type;
      ++v2;
      *((_DWORD *)v6 - 8) = v7;
      *((_DWORD *)v6 - 7) = *((_DWORD *)&v3->terrain_info.terrain[v2] - 4);
      *((_DWORD *)v6 - 5) = *((_DWORD *)&v3->terrain_info.terrain[v2] - 2);
      *((_DWORD *)v6 - 9) = 0;
      *((_DWORD *)v6 - 6) = *((_DWORD *)&v3->terrain_info.terrain[v2] - 3);
      *((_DWORD *)v6 - 4) = *((_DWORD *)&v3->terrain_info.terrain[v2] - 1);
      *((_DWORD *)v6 - 3) = 1;
      ++index;
    }
    while ( index < v3->terrain_info.terrain_num );
  }
  v8 = 0;
  v9 = 0;
  for ( indexa = 0; indexa < v3->land_info.land_num; ++indexa )
  {
    v10 = (int)&v3->land_info.land[v8].land_id;
    if ( *(_DWORD *)(v10 + 32) >= 0 )
    {
      if ( *(_BYTE *)(v10 + 29) )
      {
        land_tile_numa = 0;
        if ( v1->number_of_players > 0 )
        {
          v11 = &v1->terrain_info.hot_spots[v9].y;
          v12 = &v1->land_info.land[v9].y;
          do
          {
            ++v9;
            *(v11 - 1) = *(v12 - 1);
            *v11 = *v12;
            v12 += 13;
            v11 += 4;
            *(v11 - 3) = v3->land_info.land[v8].radius;
            *(v11 - 2) = v3->land_info.land[v8].fade;
            ++land_tile_numa;
          }
          while ( land_tile_numa < v1->number_of_players );
        }
      }
      else
      {
        v13 = (int)v1 + 16 * v9;
        *(_DWORD *)(v13 + 8408) = v1->land_info.land[v9].x;
        *(_DWORD *)(v13 + 8412) = v1->land_info.land[v9].y;
        v14 = 4 * (v9++ + 526);
        (&v1->vfptr)[v14] = (RGE_Random_Map_ModuleVtbl *)v3->land_info.land[v8].radius;
        *(_DWORD *)(v13 + 8420) = v3->land_info.land[v8].fade;
      }
    }
    ++v8;
  }
  v1->terrain_info.hot_spot_num = v9;
}

//----- (00484320) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::add_object_module(RGE_RMM_Database_Controller *this)
{
  int v1; // edi@1
  RGE_Map_Data_Entry *v2; // edx@1
  int v3; // esi@2
  char *v4; // eax@2
  int v5; // ebx@3
  int v6; // eax@4
  int v7; // ebx@4
  signed int v8; // esi@4
  char *v9; // eax@7
  char *v10; // edi@7
  bool v11; // zf@8
  int index1; // [sp+10h] [bp-4h]@6

  v1 = 0;
  v2 = &this->map_info.maps[this->map_type];
  this->object_info.object_num = v2->object_info.object_num;
  if ( v2->object_info.object_num > 0 )
  {
    v3 = 0;
    v4 = (char *)&this->object_info.objects[0].terrain;
    do
    {
      ++v1;
      v4 += 48;
      v5 = v2->object_info.objects[v3].obj_id;
      ++v3;
      *((_DWORD *)v4 - 13) = v5;
      *((_DWORD *)v4 - 12) = *((_DWORD *)&v2->object_info.objects[v3] - 10);
      *(v4 - 44) = *((_BYTE *)&v2->object_info.objects[v3] - 36);
      *(v4 - 43) = *((_BYTE *)&v2->object_info.objects[v3] - 35);
      *((_DWORD *)v4 - 10) = *((_DWORD *)&v2->object_info.objects[v3] - 8);
      *((_DWORD *)v4 - 9) = *((_DWORD *)&v2->object_info.objects[v3] - 7);
      *((_DWORD *)v4 - 8) = *((_DWORD *)&v2->object_info.objects[v3] - 6);
      *((_DWORD *)v4 - 6) = *((_DWORD *)&v2->object_info.objects[v3] - 4);
      *((_DWORD *)v4 - 5) = *((_DWORD *)&v2->object_info.objects[v3] - 3);
      *((_DWORD *)v4 - 4) = *((_DWORD *)&v2->object_info.objects[v3] - 2);
      *((_DWORD *)v4 - 3) = *((_DWORD *)&v2->object_info.objects[v3] - 1);
      *((_DWORD *)v4 - 7) = *((_DWORD *)&v2->object_info.objects[v3] - 5);
      *((_DWORD *)v4 - 2) = 1;
    }
    while ( v1 < v2->object_info.object_num );
  }
  v6 = this->land_info.land_num;
  v7 = 0;
  this->object_info.land_num = v6;
  v8 = 0;
  if ( v2->land_info.land->by_player_flag )
    v8 = 1;
  index1 = 0;
  if ( v6 > 0 )
  {
    v9 = (char *)&this->object_info.lands[0].y;
    v10 = (char *)&this->land_info.land[0].y;
    do
    {
      *((_DWORD *)v9 - 1) = *((_DWORD *)v10 - 1);
      *(_DWORD *)v9 = *(_DWORD *)v10;
      v11 = v8 == 0;
      *((_DWORD *)v9 + 1) = v2->land_info.land[v7].land_id;
      *((_DWORD *)v9 + 2) = v8;
      if ( v8 > 0 )
      {
        if ( ++v8 > this->number_of_players )
          v8 = 0;
        v11 = v8 == 0;
      }
      if ( v11 )
      {
        ++v7;
        if ( v2->land_info.land[v7].by_player_flag )
          v8 = 1;
      }
      v10 += 52;
      v9 += 16;
      ++index1;
    }
    while ( index1 < this->land_info.land_num );
  }
}

//----- (00484470) --------------------------------------------------------
void __thiscall RGE_RMM_Database_Controller::add_elevation_module(RGE_RMM_Database_Controller *this)
{
  char *v1; // esi@1
  int v2; // ebp@1
  signed int v3; // edx@1
  unsigned int v4; // eax@1
  int v5; // edx@1
  int v6; // edi@1
  unsigned int v7; // edx@1
  int v8; // edx@1
  int v9; // eax@2
  char *v10; // eax@5
  char *v11; // edi@5
  int v12; // edi@8
  char *v13; // eax@8
  int index2; // [sp+10h] [bp-8h]@4
  int index; // [sp+14h] [bp-4h]@1

  v1 = (char *)&this->map_info.maps[this->map_type].land_info;
  v2 = 0;
  v3 = (signed int)((unsigned __int64)(1374389535i64
                                     * this->map_height
                                     * this->map_info.maps[this->map_type].land_info.grown_land_percent
                                     * this->map_width) >> 32) >> 5;
  v4 = (signed int)((unsigned __int64)(1374389535i64
                                     * this->map_height
                                     * this->map_info.maps[this->map_type].land_info.grown_land_percent
                                     * this->map_width) >> 32) >> 5;
  this->elevation_info.elevation_num = 4;
  v5 = (v4 >> 31) + v3;
  v6 = v5;
  this->elevation_info.elevation[0].elevation = 1;
  this->elevation_info.elevation[0].clumps = 10;
  this->elevation_info.elevation[0].base_terrain_type = 0;
  this->elevation_info.elevation[0].base_elevation = 0;
  v7 = (signed int)((unsigned __int64)(13743895350i64 * v5) >> 32) >> 5;
  this->elevation_info.elevation[0].spacing = 2;
  this->elevation_info.elevation[0].elevation_size = (v7 >> 31) + v7;
  this->elevation_info.elevation[1].elevation = 2;
  this->elevation_info.elevation[1].elevation_size = 8 * v6 / 100;
  this->elevation_info.elevation[1].clumps = 8;
  this->elevation_info.elevation[2].elevation_size = 6 * v6 / 100;
  this->elevation_info.elevation[1].base_terrain_type = 0;
  this->elevation_info.elevation[1].base_elevation = 1;
  this->elevation_info.elevation[1].spacing = 1;
  this->elevation_info.elevation[2].elevation = 3;
  this->elevation_info.elevation[2].clumps = 6;
  this->elevation_info.elevation[2].base_terrain_type = 0;
  this->elevation_info.elevation[2].base_elevation = 2;
  this->elevation_info.elevation[2].spacing = 1;
  this->elevation_info.elevation[3].elevation_size = 4 * v6 / 100;
  this->elevation_info.elevation[3].elevation = 4;
  this->elevation_info.elevation[3].clumps = 4;
  this->elevation_info.elevation[3].base_terrain_type = 0;
  this->elevation_info.elevation[3].base_elevation = 3;
  this->elevation_info.elevation[3].spacing = 1;
  v8 = 0;
  for ( index = 0; index < *((_DWORD *)v1 + 9); ++index )
  {
    v9 = v2 + *((_DWORD *)v1 + 10);
    if ( *(_DWORD *)(v9 + 32) >= 0 )
    {
      if ( *(_BYTE *)(v9 + 29) )
      {
        index2 = 0;
        if ( this->number_of_players > 0 )
        {
          v10 = (char *)&this->elevation_info.hot_spots[v8].y;
          v11 = (char *)&this->land_info.land[v8].y;
          do
          {
            ++v8;
            *((_DWORD *)v10 - 1) = *((_DWORD *)v11 - 1);
            *(_DWORD *)v10 = *(_DWORD *)v11;
            v11 += 52;
            v10 += 16;
            *((_DWORD *)v10 - 3) = *(_DWORD *)(v2 + *((_DWORD *)v1 + 10) + 32);
            *((_DWORD *)v10 - 2) = *(_DWORD *)(v2 + *((_DWORD *)v1 + 10) + 36);
            ++index2;
          }
          while ( index2 < this->number_of_players );
        }
      }
      else
      {
        (&this->vfptr)[4 * (v8 + 1170)] = (RGE_Random_Map_ModuleVtbl *)this->land_info.land[v8].x;
        v12 = this->land_info.land[v8].y;
        v13 = (char *)this + 16 * v8++;
        *((_DWORD *)v13 + 4681) = v12;
        *((_DWORD *)v13 + 4682) = *(_DWORD *)(v2 + *((_DWORD *)v1 + 10) + 32);
        *((_DWORD *)v13 + 4683) = *(_DWORD *)(v2 + *((_DWORD *)v1 + 10) + 36);
      }
    }
    v2 += 44;
  }
  this->elevation_info.hot_spot_num = v8;
}
