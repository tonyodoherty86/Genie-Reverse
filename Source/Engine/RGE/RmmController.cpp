
//----- (004821A0) --------------------------------------------------------
void __thiscall RGE_RMM_Controller::RGE_RMM_Controller(RGE_RMM_Controller *this, RGE_Map *in_map, RGE_Game_World *world, char type, int player_num)
{
  RGE_RMM_Controller *v5; // esi@1
  RGE_Terrain_Info v6; // [sp+Ch] [bp-26DCh]@1
  RGE_Land_Info info; // [sp+12A4h] [bp-1444h]@1
  int v8; // [sp+26E4h] [bp-4h]@1

  v5 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, 0, 1);
  v8 = 0;
  v5->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Controller::`vftable';
  RGE_RMM_Controller::add_land_module(v5, &info, (unsigned __int8)type, player_num);
  RGE_RMM_Controller::add_terrain_module(v5, &v6, &info, (unsigned __int8)type);
  RGE_RMM_Controller::add_object_module(v5, (int)world, world, &info);
}
// 571E68: using guessed type char (__thiscall *RGE_RMM_Controller::`vftable')(RGE_RMM_Controller *this);

//----- (00482270) --------------------------------------------------------
void __thiscall RGE_RMM_Controller::add_land_module(RGE_RMM_Controller *this, RGE_Land_Info *info, int type, int player_num)
{
  RGE_Land_Info *v4; // edi@1
  RGE_RMM_Controller *v5; // ebx@1
  signed int v6; // eax@2
  int v7; // edx@3
  int v8; // edx@4
  int v9; // edx@5
  int v10; // esi@7
  unsigned int v11; // edx@7
  long double v12; // st7@7
  float bound_square; // ST40_4@34
  double v14; // st6@7
  double v15; // ST38_8@7
  long double v16; // ST30_8@7
  signed __int64 v17; // rax@7
  int v18; // ecx@13
  char v19; // al@15
  char *v20; // edi@16
  int v21; // eax@23
  unsigned int v22; // edx@23
  int v23; // esi@23
  int v24; // ebp@23
  char *v25; // edx@29
  int v26; // ecx@30
  int v27; // eax@32
  RGE_RMM_Land_Generator *v28; // eax@44
  int index; // [sp+10h] [bp-3Ch]@15
  int mid_x1; // [sp+14h] [bp-38h]@7
  int mid_x2; // [sp+18h] [bp-34h]@7
  int mid_y1; // [sp+1Ch] [bp-30h]@7
  int index2; // [sp+20h] [bp-2Ch]@28
  int mid_y2; // [sp+24h] [bp-28h]@7
  RGE_RMM_Controller *v35; // [sp+38h] [bp-14h]@1
  int land_tile_num; // [sp+3Ch] [bp-10h]@7
  char player_numa; // [sp+58h] [bp+Ch]@23

  v4 = info;
  v5 = this;
  info->land_num = player_num;
  v35 = this;
  switch ( type )
  {
    case 3:
      info->base_terrain = 1;
      v6 = 90;
      info->wall_1_avoidance_line = 0;
      info->wall_2_avoidance_line = 0;
      info->wall_3_avoidance_line = 0;
      info->wall_4_avoidance_line = 0;
      info->wall_fade = 0;
      break;
    case 2:
      info->base_terrain = 1;
      info->wall_1_avoidance_line = 4;
      info->wall_2_avoidance_line = 4;
      v6 = 70;
      info->wall_3_avoidance_line = this->map_width - 5;
      v7 = this->map_height - 5;
      info->wall_fade = 34;
      info->wall_4_avoidance_line = v7;
      break;
    case 1:
      info->base_terrain = 1;
      info->wall_1_avoidance_line = 6;
      info->wall_2_avoidance_line = 6;
      v6 = 50;
      info->wall_3_avoidance_line = this->map_width - 7;
      v8 = this->map_height - 7;
      info->wall_fade = 20;
      info->wall_4_avoidance_line = v8;
      break;
    case 0:
      info->base_terrain = 1;
      info->wall_1_avoidance_line = 8;
      info->wall_2_avoidance_line = 8;
      v6 = 30;
      info->wall_3_avoidance_line = this->map_width - 9;
      v9 = this->map_height - 9;
      info->wall_fade = 20;
      info->wall_4_avoidance_line = v9;
      break;
    default:
      v6 = 0;
      info->base_terrain = 0;
      info->wall_1_avoidance_line = 0;
      info->wall_2_avoidance_line = 0;
      info->wall_3_avoidance_line = 0;
      info->wall_4_avoidance_line = 0;
      info->wall_fade = 0;
      break;
  }
  v10 = this->map_width;
  v11 = (unsigned __int64)(1374389535i64 * v10 * this->map_height * v6) >> 32;
  land_tile_num = (v11 >> 31) + ((signed int)v11 >> 5);
  v12 = (double)(v10 - 16) / sqrt((double)player_num) * 0.8;
  v14 = (double)(v10 / 2);
  mid_x1 = (signed __int64)(v14 - v12 * 0.9);
  v15 = (double)(this->map_height / 2);
  mid_y1 = (signed __int64)(v15 - v12 * 0.9);
  v16 = v12 * -0.9;
  mid_x2 = (signed __int64)(v14 - v16);
  v17 = (signed __int64)(v15 - v16);
  mid_y2 = v17;
  if( mid_x1 <= 8 )
    mid_x1 = 9;
  if( mid_y1 <= 8 )
    mid_y1 = 9;
  if( mid_x2 >= v10 - 9 )
    mid_x2 = v10 - 10;
  v18 = this->map_height;
  if( (signed int)v17 >= v18 - 9 )
    mid_y2 = v18 - 10;
  v19 = 0;
  index = 0;
  if( player_num > 0 )
  {
    v20 = (char *)&info->land[0].area;
    while( 1 )
    {
      switch ( type )
      {
        case 2:
        case 3:
        case 4:
          *((_DWORD *)v20 - 4) = 0;
          *(_DWORD *)v20 = 3;
          *((_DWORD *)v20 - 1) = 5;
          v20[4] = 0;
          break;
        case 1:
          *((_DWORD *)v20 - 4) = 0;
          *(_DWORD *)v20 = 4;
          goto LABEL_22;
        case 0:
          *((_DWORD *)v20 - 4) = 0;
          *(_DWORD *)v20 = 7;
LABEL_22:
          *((_DWORD *)v20 - 1) = 5;
          v20[4] = v19;
          break;
        default:
          goto LABEL_23;
      }
      do
      {
LABEL_23:
        player_numa = 0;
        v21 = debug_rand(aCMsdevWorkA_15, 209);
        v22 = (signed int)((v5->map_width - 16) * v21
                         + ((unsigned __int64)(-2147418109i64 * (v5->map_width - 16) * v21) >> 32)) >> 14;
        v23 = v22 + (v22 >> 31) + 8;
        v24 = (v5->map_height - 16) * debug_rand(aCMsdevWorkA_15, 210) / 0x7FFF + 8;
        if( v23 <= mid_x1 || v23 >= mid_x2 || v24 <= mid_y1 || v24 >= mid_y2 )
        {
          index2 = 0;
          if( index > 0 )
          {
            v25 = (char *)&info->land[0].x;
            do
            {
              v26 = v23 - *(_DWORD *)v25;
              if( v23 - *(_DWORD *)v25 < 0 )
                v26 = -v26;
              v27 = v24 - *((_DWORD *)v25 + 1);
              if( v27 < 0 )
                v27 = -v27;
              bound_square = v12 * v12;
              if( (double)(v27 * v27 + v26 * v26) <= bound_square )
              {
                if( !player_numa && index2 == index - 1 )
                {
                  *((_DWORD *)v25 + 1) = v24;
                  *(_DWORD *)v25 = v23;
                }
                player_numa = 1;
              }
              v25 += 52;
              ++index2;
            }
            while( index2 < index );
            v5 = v35;
          }
        }
        else
        {
          player_numa = 1;
        }
      }
      while( player_numa );
      *((_DWORD *)v20 - 3) = v23;
      *((_DWORD *)v20 - 2) = v24;
      v20 += 52;
      *((_DWORD *)v20 - 18) = land_tile_num / info->land_num;
      if( ++index >= info->land_num )
        break;
      v19 = index;
    }
    v4 = info;
  }
  v28 = (RGE_RMM_Land_Generator *)operator new(0x1468u);
  if( v28 )
    RGE_RMM_Land_Generator::RGE_RMM_Land_Generator(v28, v5->map, (RGE_Random_Map_Module *)&v5->vfptr, v4);
}

//----- (004826E0) --------------------------------------------------------
void __thiscall RGE_RMM_Controller::add_terrain_module(RGE_RMM_Controller *this, RGE_Terrain_Info *info, RGE_Land_Info *land_info, int type)
{
  RGE_RMM_Controller *v4; // edi@1
  int v5; // eax@2
  int v6; // eax@2
  unsigned int v7; // edx@2
  int v8; // eax@3
  int v9; // eax@3
  unsigned int v10; // edx@3
  int v11; // edx@5
  int v12; // eax@5
  char *v13; // eax@6
  char *v14; // ecx@6
  RGE_RMM_Terrain_Generator *v15; // eax@8

  v4 = this;
  info->terrain_num = 2;
  switch ( type )
  {
    case 3:
    case 4:
      v5 = this->map_width * this->map_height;
      info->terrain[0].terrain_type = 10;
      info->terrain[0].clumps = 30;
      info->terrain[0].base_terrain_type = 0;
      info->terrain[0].terrain_generated = 0;
      info->terrain[0].terrain_size = 20 * v5 / 100;
      info->terrain[0].spacing = 2;
      v6 = this->map_width * this->map_height;
      info->terrain[1].terrain_type = 6;
      info->terrain[1].clumps = 17;
      v7 = (signed int)((unsigned __int64)(41231686050i64 * v6) >> 32) >> 5;
      info->terrain[1].terrain_size = (v7 >> 31) + v7;
      goto LABEL_4;
    case 0:
    case 1:
    case 2:
      v8 = this->map_width * this->map_height;
      info->terrain[0].terrain_type = 10;
      info->terrain[0].clumps = 20;
      info->terrain[0].base_terrain_type = 0;
      info->terrain[0].terrain_generated = 0;
      info->terrain[0].terrain_size = 20 * v8 / 100;
      info->terrain[0].spacing = 2;
      v9 = this->map_width * this->map_height;
      info->terrain[1].terrain_type = 6;
      info->terrain[1].clumps = 7;
      v10 = (signed int)((unsigned __int64)(41231686050i64 * v9) >> 32) >> 5;
      info->terrain[1].terrain_size = (v10 >> 31) + v10;
LABEL_4:
      info->terrain[1].base_terrain_type = 0;
      info->terrain[1].terrain_generated = 0;
      info->terrain[1].spacing = 0;
      break;
    default:
      break;
  }
  v11 = 0;
  v12 = land_info->land_num;
  info->hot_spot_num = v12;
  if( v12 > 0 )
  {
    v13 = (char *)&info->hot_spots[0].y;
    v14 = (char *)&land_info->land[0].y;
    do
    {
      ++v11;
      *((_DWORD *)v13 - 1) = *((_DWORD *)v14 - 1);
      *(_DWORD *)v13 = *(_DWORD *)v14;
      *((_DWORD *)v13 + 1) = 12;
      *((_DWORD *)v13 + 2) = 20;
      v14 += 52;
      v13 += 16;
    }
    while( v11 < info->hot_spot_num );
  }
  v15 = (RGE_RMM_Terrain_Generator *)operator new(0x12CCu);
  if( v15 )
    RGE_RMM_Terrain_Generator::RGE_RMM_Terrain_Generator(v15, v4->map, (RGE_Random_Map_Module *)&v4->vfptr, info);
}

//----- (004828A0) --------------------------------------------------------
int __thiscall RGE_RMM_Controller::count_map_tiles(RGE_RMM_Controller *this, char terrain)
{
  return this->map_height * this->map_width;
}

//----- (004828B0) --------------------------------------------------------
void __userpurge RGE_RMM_Controller::add_object_module(RGE_RMM_Controller *this@<ecx>, int a2@<eax>, RGE_Game_World *world, RGE_Land_Info *land_info)
{
  void *v4; // esp@1
  int v5; // esi@1
  int v6; // ecx@1
  char *v7; // eax@2
  char *v8; // edx@2
  RGE_RMM_Object_Generator *v9; // eax@4
  RGE_RMM_Controller *parent_module; // [sp+0h] [bp-18DCh]@1
  RGE_Object_Info in_info; // [sp+8h] [bp-18D4h]@1
  int v12; // [sp+18D0h] [bp-Ch]@1
  int (*v13)(); // [sp+18D4h] [bp-8h]@1
  int v14; // [sp+18D8h] [bp-4h]@1

  v14 = -1;
  v13 = _L32328;
  v12 = a2;
  v4 = alloca(6352);
  parent_module = this;
  in_info.object_num = 6;
  in_info.objects[1].land_outer_radius = 4;
  in_info.objects[2].object_number_per_group = 6;
  in_info.objects[3].object_number_per_group = 6;
  in_info.objects[3].group_area = 4;
  in_info.objects[4].object_number_per_group = 6;
  in_info.objects[0].obj_id = 109;
  in_info.objects[0].terrain = 0;
  in_info.objects[0].group_flag = 0;
  in_info.objects[0].scale_flag = 0;
  in_info.objects[0].object_number_per_group = 1;
  in_info.objects[0].object_number_varience = 0;
  in_info.objects[0].number_of_groups = 1;
  in_info.objects[0].player_id = -1;
  in_info.objects[0].land_id = 0;
  in_info.objects[0].land_inner_radius = 0;
  in_info.objects[0].land_outer_radius = 0;
  in_info.objects[1].obj_id = 83;
  in_info.objects[1].terrain = 0;
  in_info.objects[1].group_flag = 0;
  in_info.objects[1].scale_flag = 0;
  in_info.objects[1].object_number_per_group = 1;
  in_info.objects[1].object_number_varience = 0;
  in_info.objects[1].number_of_groups = 3;
  in_info.objects[1].player_id = -1;
  in_info.objects[1].land_id = 0;
  in_info.objects[1].land_inner_radius = 2;
  in_info.objects[2].obj_id = 65;
  in_info.objects[2].terrain = 0;
  in_info.objects[2].group_flag = 1;
  in_info.objects[2].scale_flag = 1;
  in_info.objects[2].object_number_varience = 3;
  in_info.objects[2].number_of_groups = 10;
  in_info.objects[2].group_area = 3;
  in_info.objects[2].player_id = 0;
  in_info.objects[2].land_id = -1;
  in_info.objects[2].land_inner_radius = -1;
  in_info.objects[2].land_outer_radius = -1;
  in_info.objects[3].obj_id = 102;
  in_info.objects[3].terrain = -1;
  in_info.objects[3].group_flag = 2;
  in_info.objects[3].scale_flag = 0;
  in_info.objects[3].object_number_varience = 2;
  in_info.objects[3].number_of_groups = 1;
  in_info.objects[3].player_id = 0;
  in_info.objects[3].land_id = 0;
  in_info.objects[3].land_inner_radius = 9;
  in_info.objects[3].land_outer_radius = 15;
  in_info.objects[4].obj_id = 66;
  in_info.objects[4].terrain = -1;
  in_info.objects[4].group_flag = 2;
  in_info.objects[4].scale_flag = 0;
  in_info.objects[4].object_number_varience = 2;
  in_info.objects[4].number_of_groups = 1;
  in_info.objects[4].group_area = 4;
  in_info.objects[4].player_id = 0;
  in_info.objects[4].land_id = 0;
  in_info.objects[4].land_inner_radius = 9;
  in_info.objects[4].land_outer_radius = 15;
  in_info.objects[5].obj_id = 59;
  in_info.objects[5].terrain = -1;
  in_info.objects[5].group_area = 3;
  in_info.objects[5].land_inner_radius = 9;
  in_info.objects[5].object_number_varience = 2;
  v5 = land_info->land_num;
  v6 = 0;
  in_info.objects[5].group_flag = 1;
  in_info.objects[5].scale_flag = 0;
  in_info.objects[5].object_number_per_group = 5;
  in_info.objects[5].number_of_groups = 1;
  in_info.objects[5].player_id = 0;
  in_info.objects[5].land_id = 0;
  in_info.objects[5].land_outer_radius = 15;
  in_info.land_num = v5;
  if( v5 > 0 )
  {
    v7 = (char *)&in_info.lands[0].y;
    v8 = (char *)&land_info->land[0].y;
    do
    {
      ++v6;
      *((_DWORD *)v7 - 1) = *((_DWORD *)v8 - 1);
      *(_DWORD *)v7 = *(_DWORD *)v8;
      *((_DWORD *)v7 + 1) = 0;
      *((_DWORD *)v7 + 2) = v6;
      v8 += 52;
      v7 += 16;
    }
    while( v6 < v5 );
  }
  v9 = (RGE_RMM_Object_Generator *)operator new(0x1920u);
  v14 = 0;
  if( v9 )
    RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(
      v9,
      parent_module->map,
      (RGE_Random_Map_Module *)&parent_module->vfptr,
      world,
      &in_info,
      1);
}
// 55E63E: using guessed type int _L32328();
