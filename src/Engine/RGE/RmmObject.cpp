
//----- (00485C50) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(RGE_RMM_Object_Generator *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Game_World *in_world, RGE_Object_Info *in_info, char add_terrain_objects)
{
  RGE_RMM_Object_Generator *v6; // ebx@1

  v6 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, parent_module, 1);
  v6->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Object_Generator::`vftable';
  v6->world = in_world;
  if ( in_info )
  {
    qmemcpy(&v6->info, in_info, sizeof(v6->info));
  }
  else
  {
    v6->info.object_num = 0;
    v6->info.land_num = 0;
  }
  LODWORD(v6->schedule) = 1077936128;
  v6->add_terrain = add_terrain_objects;
}
// 571ED8: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Object_Generator::`vftable')(RGE_RMM_Object_Generator *this);

//----- (00485CB0) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::add_quick_obj(RGE_RMM_Object_Generator *this, int obj_id, int count, int er)
{
  this->info.objects[this->info.object_num].obj_id = obj_id;
  this->info.objects[this->info.object_num].terrain = -1;
  this->info.objects[this->info.object_num].group_flag = 0;
  this->info.objects[this->info.object_num].scale_flag = 0;
  this->info.objects[this->info.object_num].object_number_per_group = 1;
  this->info.objects[this->info.object_num].object_number_varience = 1;
  this->info.objects[this->info.object_num].number_of_groups = count;
  this->info.objects[this->info.object_num].group_area = 2;
  this->info.objects[this->info.object_num].player_id = 0;
  this->info.objects[this->info.object_num].land_id = -1;
  this->info.objects[this->info.object_num].land_inner_radius = 0;
  this->info.objects[this->info.object_num].land_outer_radius = 1;
  (&this->vfptr)[12 * (this->info.object_num++ + 2)] = (RGE_Random_Map_ModuleVtbl *)er;
}

//----- (00485DC0) --------------------------------------------------------
char __thiscall RGE_RMM_Object_Generator::generate(RGE_RMM_Object_Generator *this)
{
  RGE_RMM_Object_Generator *v1; // esi@1
  int v2; // edi@3
  RGE_Object_Info_Line *v3; // ebx@4

  v1 = this;
  if ( this->add_terrain )
  {
    LOWORD(this) = LOWORD(this->map_height) - 1;
    RGE_Map::set_terrain(v1->map, *v1->world->players, v1->world, 0, 0, LOWORD(v1->map_width) - 1, (int)this, 1, 0, 0);
  }
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)&v1->vfptr);
  memset(v1->terrain_table, 0, sizeof(v1->terrain_table));
  v2 = 0;
  if ( v1->info.object_num > 0 )
  {
    v3 = v1->info.objects;
    do
    {
      RGE_RMM_Object_Generator::generate_objects(v1, v3);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->info.object_num );
  }
  RGE_Zone_Map_List::delete_zone_maps(v1->map->map_zones);
  return 1;
}

//----- (00485E50) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::generate_objects(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line)
{
  RGE_RMM_Object_Generator *v2; // ebx@1
  signed int v3; // edx@2
  int v4; // eax@4
  int v5; // ebp@5
  char *v6; // edi@6

  v2 = this;
  if ( info_line->scale_flag )
  {
    v3 = info_line->number_of_groups * this->map_width * this->map_height / 20736;
    info_line->number_of_groups = v3;
    if ( v3 < 1 )
      info_line->number_of_groups = 1;
  }
  v4 = info_line->land_id;
  if ( v4 < 0 )
  {
    if ( v4 == -1 )
    {
      RGE_RMM_Object_Generator::place_objects(this, info_line);
    }
    else if ( v4 == -2 )
    {
      RGE_RMM_Object_Generator::place_avoid_objects(this, info_line, info_line->land_inner_radius);
    }
  }
  else
  {
    v5 = 0;
    if ( this->info.land_num > 0 )
    {
      v6 = (char *)&this->info.lands[0].y;
      do
      {
        if ( *((_DWORD *)v6 + 1) == info_line->land_id )
          RGE_RMM_Object_Generator::place_land_objects(
            v2,
            info_line,
            *((_DWORD *)v6 - 1),
            *(_DWORD *)v6,
            info_line->land_inner_radius,
            info_line->land_outer_radius,
            v5);
        ++v5;
        v6 += 16;
      }
      while ( v5 < v2->info.land_num );
    }
  }
}

//----- (00485F10) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::make_placement_stack(RGE_RMM_Object_Generator *this, Map_Stack *stack, int x, int y, int inner_radius, int outer_radius)
{
  RGE_RMM_Object_Generator *v6; // edi@1
  int v7; // esi@4
  int v8; // ebp@4
  int v9; // ecx@4
  int v10; // edx@4
  int v11; // eax@8
  int v12; // eax@10
  int v13; // edx@13
  int v14; // eax@14
  int v15; // ebp@15
  int v16; // ebx@16
  int v17; // esi@18
  bool v18; // zf@21
  int v19; // ecx@23
  int v20; // edx@23
  int v21; // ebx@23
  int v22; // ebp@23
  int v23; // esi@28
  int v24; // eax@28
  unsigned int v25; // edx@28
  int v26; // eax@28
  int y1; // [sp+10h] [bp-10h]@4
  Map_Stack *last; // [sp+14h] [bp-Ch]@13
  int v29; // [sp+18h] [bp-8h]@14
  int v30; // [sp+1Ch] [bp-4h]@14
  int xa; // [sp+28h] [bp+8h]@4
  int x0; // [sp+2Ch] [bp+Ch]@4
  int outer_radiusa; // [sp+34h] [bp+14h]@4
  int outer_radiusb; // [sp+34h] [bp+14h]@26

  v6 = this;
  stack->next = 0;
  stack->prev = 0;
  if ( x < 0 || y < 0 || outer_radius < 0 )
  {
    xa = 0;
    x0 = 0;
    outer_radiusa = this->map_width - 1;
    v9 = this->map_width - 1;
    y1 = v6->map_height - 1;
    v7 = 0;
    v8 = 0;
  }
  else
  {
    v7 = x - outer_radius;
    v8 = y - outer_radius;
    v9 = outer_radius + x;
    v10 = outer_radius + y;
    xa = v7;
    x0 = y - outer_radius;
    outer_radiusa = v9;
    y1 = v10;
    if ( v7 < 0 )
    {
      xa = 0;
      v7 = 0;
    }
    if ( v8 < 0 )
    {
      x0 = 0;
      v8 = 0;
    }
    v11 = v6->map_width;
    if ( v9 >= v11 )
    {
      outer_radiusa = v11 - 1;
      v9 = v11 - 1;
    }
    v12 = v6->map_height;
    if ( v10 >= v12 )
      y1 = v12 - 1;
  }
  v13 = y1;
  last = stack;
  if ( v8 <= y1 )
  {
    v14 = 4 * v8;
    v29 = 4 * v8;
    v30 = y1 - v8 + 1;
    do
    {
      v15 = v7;
      if ( v7 <= v9 )
      {
        v16 = v7;
        do
        {
          if ( (*(char **)((char *)v6->search_map_rows + v14))[v15] )
          {
            v17 = (int)&(*(Map_Stack **)((char *)v6->stack_offsets + v14))[v16].x;
            RGE_Random_Map_Module::add_stack_node(last, &(*(Map_Stack **)((char *)v6->stack_offsets + v14))[v16]);
            v9 = outer_radiusa;
            v14 = v29;
            last = (Map_Stack *)v17;
            v7 = xa;
          }
          ++v15;
          ++v16;
        }
        while ( v15 <= v9 );
        v13 = y1;
      }
      v14 += 4;
      v18 = v30 == 1;
      v29 = v14;
      --v30;
    }
    while ( !v18 );
    v8 = x0;
  }
  v19 = v9 - v7 - 1;
  v20 = v13 - v8 - 1;
  v21 = v19;
  v22 = v20;
  if ( v19 > 1 && v20 > 1 && v19 * v20 / 4 > 0 )
  {
    outer_radiusb = v19 * v20 / 4;
    while ( 1 )
    {
      v23 = v7 + v21 * debug_rand(aCMsdevWorkA_47, 175) / 0x7FFF;
      v24 = debug_rand(aCMsdevWorkA_47, 176);
      v25 = v22 * v24 + ((unsigned __int64)(-2147418109i64 * v22 * v24) >> 32);
      v26 = x0 + (v25 >> 31) + ((signed int)v25 >> 14);
      if ( v6->search_map_rows[v26][v23] )
        RGE_Random_Map_Module::add_stack_node(stack, &v6->stack_offsets[v26][v23]);
      if ( !--outer_radiusb )
        break;
      v7 = xa;
    }
  }
}

//----- (00486110) --------------------------------------------------------
char __thiscall RGE_RMM_Object_Generator::to_close(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line, int x, int y)
{
  int v4; // edi@1
  int v5; // esi@1
  char *v6; // edx@2
  int v7; // ebx@2
  int v8; // ecx@3
  int v9; // eax@5
  char result; // al@10

  v4 = this->info.land_num;
  v5 = 0;
  if ( v4 <= 0 )
  {
    result = 0;
  }
  else
  {
    v6 = (char *)&this->info.lands[0].y;
    v7 = info_line->land_inner_radius;
    while ( 1 )
    {
      v8 = x - *((_DWORD *)v6 - 1);
      if ( v8 < 0 )
        v8 = -v8;
      v9 = y - *(_DWORD *)v6;
      if ( y - *(_DWORD *)v6 < 0 )
        v9 = -v9;
      if ( v8 < v7 && v9 < v7 )
        break;
      ++v5;
      v6 += 16;
      if ( v5 >= v4 )
        return 0;
    }
    result = 1;
  }
  return result;
}

//----- (00486180) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::set_search_area(RGE_RMM_Object_Generator *this, int x, int y, int radius, char set_num)
{
  RGE_RMM_Object_Generator *v5; // esi@1
  int v6; // edi@1
  int v7; // ecx@1
  int v8; // edx@1
  int v9; // ebp@1
  bool v10; // sf@1
  int v11; // eax@5
  int v12; // eax@7
  int v13; // ebx@9
  int v14; // eax@10
  int v15; // ebx@11
  int xa; // [sp+14h] [bp+4h]@1
  int radiusa; // [sp+1Ch] [bp+Ch]@9

  v5 = this;
  v6 = x - radius;
  v7 = y - radius;
  v8 = radius + x;
  v9 = radius + y;
  v10 = x - radius < 0;
  xa = radius + y;
  if ( v10 )
    v6 = 0;
  if ( v7 < 0 )
    v7 = 0;
  v11 = v5->map_width;
  if ( v8 >= v11 )
    v8 = v11 - 1;
  v12 = v5->map_height;
  if ( v9 >= v12 )
  {
    v9 = v12 - 1;
    xa = v12 - 1;
  }
  v13 = v7;
  for ( radiusa = v7; v13 <= v9; radiusa = v13 )
  {
    v14 = v6;
    if ( v6 <= v8 )
    {
      v15 = v13;
      do
        v5->search_map_rows[v15][++v14 - 1] = set_num;
      while ( v14 <= v8 );
      v9 = xa;
      v13 = radiusa;
    }
    ++v13;
  }
}

//----- (00486210) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::remove_area_from_lists(RGE_RMM_Object_Generator *this, int x, int y, int spacing)
{
  RGE_RMM_Object_Generator *v4; // ebp@1
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
  if ( v9 )
    v5 = 0;
  if ( v6 < 0 )
    v6 = 0;
  v10 = v4->map_width;
  if ( v7 >= v10 )
  {
    y_index = v10 - 1;
    v7 = v10 - 1;
  }
  v11 = v4->map_height;
  if ( v8 >= v11 )
  {
    xa = v11 - 1;
    v8 = v11 - 1;
  }
  for ( y1 = v6; y1 <= v8; ++y1 )
  {
    if ( v5 <= v7 )
    {
      v12 = v5;
      v13 = v7 - v5 + 1;
      do
      {
        RGE_Random_Map_Module::remove_stack_node(&v4->stack_offsets[y1][v12]);
        ++v12;
        --v13;
      }
      while ( v13 );
      v8 = xa;
      v7 = y_index;
    }
  }
}

//----- (004862B0) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::place_avoid_objects(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line, int inner_radius)
{
  RGE_RMM_Object_Generator *v3; // esi@1
  int v4; // ebp@1
  RGE_Object_Info_Line *v5; // edi@1
  char *v6; // ebx@2
  RGE_Player *v7; // ebp@4
  int v8; // ecx@6
  int v9; // ecx@8
  RGE_Master_Static_Object **v10; // edx@8
  RGE_Master_Static_Object *v11; // ebx@8
  int y; // [sp+3Ch] [bp-30h]@4
  int x; // [sp+40h] [bp-2Ch]@4
  float tile_x; // [sp+44h] [bp-28h]@8
  int count; // [sp+48h] [bp-24h]@4
  int v16; // [sp+4Ch] [bp-20h]@8
  float zone; // [sp+50h] [bp-1Ch]@4
  Map_Stack obj_stack; // [sp+54h] [bp-18h]@4
  RGE_Object_Info_Line *info_linea; // [sp+70h] [bp+4h]@8

  v3 = this;
  v4 = 0;
  memset(this->search_map, 1u, this->map_width * this->map_height);
  v5 = info_line;
  if ( this->info.land_num > 0 )
  {
    v6 = (char *)this->info.lands;
    do
    {
      RGE_RMM_Object_Generator::set_search_area(v3, *(_DWORD *)v6, *((_DWORD *)v6 + 1), info_line->land_inner_radius, 0);
      ++v4;
      v6 += 16;
    }
    while ( v4 < v3->info.land_num );
  }
  RGE_Random_Map_Module::init_stack(&obj_stack);
  RGE_RMM_Object_Generator::make_placement_stack(v3, &obj_stack, -1, -1, -1, -1);
  v7 = v3->world->players[info_line->player_id <= -1 ? 0 : info_line->player_id];
  count = info_line->number_of_groups;
  while ( RGE_Random_Map_Module::pop_stack(&obj_stack, &x, &y, &zone) )
  {
    if ( count <= 0 )
      break;
    v8 = v5->terrain;
    if ( v8 < 0 || (*((_BYTE *)&v3->map_row_offset[y][x] + 5) & 0x1F) == v8 )
    {
      v9 = v5->obj_id;
      v10 = v7->master_objects;
      tile_x = (double)x;
      v11 = v10[v9];
      *(float *)&info_linea = (double)y;
      v16 = (signed __int16)(signed __int64)v11->radius_x;
      if ( v11->radius_x - (double)v16 > 0.0 )
        tile_x = tile_x - -0.5;
      v16 = (signed __int16)(signed __int64)v11->radius_y;
      if ( v11->radius_y - (double)v16 > 0.0 )
        *(float *)&info_linea = *(float *)&info_linea - -0.5;
      if ( !(unsigned __int8)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, RGE_Object_Info_Line *, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, signed int))v11->vfptr->check_placement)(
                               v11,
                               v7,
                               LODWORD(tile_x),
                               info_linea,
                               0,
                               0,
                               1,
                               1,
                               1,
                               0,
                               1) )
      {
        RGE_RMM_Object_Generator::remove_area_from_lists(v3, x, y, v5->object_exclusion_zone);
        if ( v5->group_flag )
        {
          if ( v5->group_flag == 1 )
          {
            RGE_RMM_Object_Generator::place_group(v3, v5, x, y, v7);
          }
          else if ( v5->group_flag == 2 )
          {
            RGE_RMM_Object_Generator::place_cluster(v3, v5, x, y, v7);
          }
        }
        else
        {
          ((void (__thiscall *)(RGE_Player *, int, _DWORD, RGE_Object_Info_Line *, _DWORD, signed int))v7->vfptr->make_new_object)(
            v7,
            v5->obj_id,
            LODWORD(tile_x),
            info_linea,
            0,
            1);
        }
        --count;
      }
    }
  }
  RGE_Random_Map_Module::deinit_stack(&obj_stack);
}

//----- (004864F0) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::place_objects(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line)
{
  RGE_RMM_Object_Generator *v2; // ebp@1
  RGE_Object_Info_Line *v3; // edi@1
  RGE_Player *v4; // ebx@1
  int v5; // ecx@3
  int v6; // ecx@5
  RGE_Master_Static_Object **v7; // edx@5
  RGE_Master_Static_Object *v8; // esi@5
  int y; // [sp+3Ch] [bp-30h]@1
  int x; // [sp+40h] [bp-2Ch]@1
  float tile_x; // [sp+44h] [bp-28h]@5
  int count; // [sp+48h] [bp-24h]@1
  int v13; // [sp+4Ch] [bp-20h]@5
  float zone; // [sp+50h] [bp-1Ch]@1
  Map_Stack obj_stack; // [sp+54h] [bp-18h]@1
  RGE_Object_Info_Line *info_linea; // [sp+70h] [bp+4h]@5

  v2 = this;
  memset(this->search_map, 1u, this->map_height * this->map_width);
  RGE_Random_Map_Module::init_stack(&obj_stack);
  RGE_RMM_Object_Generator::make_placement_stack(v2, &obj_stack, -1, -1, -1, -1);
  v3 = info_line;
  v4 = v2->world->players[info_line->player_id <= -1 ? 0 : info_line->player_id];
  count = info_line->number_of_groups;
  while ( RGE_Random_Map_Module::pop_stack(&obj_stack, &x, &y, &zone) )
  {
    if ( count <= 0 )
      break;
    v5 = v3->terrain;
    if ( v5 < 0 || (*((_BYTE *)&v2->map_row_offset[y][x] + 5) & 0x1F) == v5 )
    {
      v6 = v3->obj_id;
      v7 = v4->master_objects;
      tile_x = (double)x;
      v8 = v7[v6];
      *(float *)&info_linea = (double)y;
      v13 = (signed __int16)(signed __int64)v8->radius_x;
      if ( v8->radius_x - (double)v13 > 0.0 )
        tile_x = tile_x - -0.5;
      v13 = (signed __int16)(signed __int64)v8->radius_y;
      if ( v8->radius_y - (double)v13 > 0.0 )
        *(float *)&info_linea = *(float *)&info_linea - -0.5;
      if ( !(unsigned __int8)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, RGE_Object_Info_Line *, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, signed int))v8->vfptr->check_placement)(
                               v8,
                               v4,
                               LODWORD(tile_x),
                               info_linea,
                               0,
                               0,
                               1,
                               1,
                               1,
                               0,
                               1) )
      {
        RGE_RMM_Object_Generator::remove_area_from_lists(v2, x, y, v3->object_exclusion_zone);
        if ( v3->group_flag )
        {
          if ( v3->group_flag == 1 )
          {
            RGE_RMM_Object_Generator::place_group(v2, v3, x, y, v4);
          }
          else if ( v3->group_flag == 2 )
          {
            RGE_RMM_Object_Generator::place_cluster(v2, v3, x, y, v4);
          }
        }
        else
        {
          ((void (__thiscall *)(RGE_Player *, int, _DWORD, RGE_Object_Info_Line *, _DWORD, signed int))v4->vfptr->make_new_object)(
            v4,
            v3->obj_id,
            LODWORD(tile_x),
            info_linea,
            0,
            1);
        }
        --count;
      }
    }
  }
  RGE_Random_Map_Module::deinit_stack(&obj_stack);
}

//----- (00486700) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::place_land_objects(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line, int map_x, int map_y, int inner_radius, int outer_radius, int land_id)
{
  int v7; // ebp@1
  RGE_RMM_Object_Generator *v8; // ebx@1
  int v9; // eax@5
  int v10; // ecx@7
  int v11; // edi@9
  int v12; // esi@10
  RGE_Object_Info_Line *v13; // esi@12
  int v14; // ecx@12
  int v15; // eax@12
  RGE_Game_World *v16; // eax@15
  RGE_Player *v17; // edi@15
  RGE_Master_Static_Object *v18; // ecx@15
  int v19; // eax@19
  int v20; // ecx@19
  int v21; // edx@26
  RGE_Master_Static_Object **v22; // eax@26
  RGE_Master_Static_Object *v23; // ebp@26
  int y; // [sp+3Ch] [bp-38h]@16
  int min_x0; // [sp+40h] [bp-34h]@1
  int min_x1; // [sp+44h] [bp-30h]@1
  int min_y0; // [sp+48h] [bp-2Ch]@1
  int min_y1; // [sp+4Ch] [bp-28h]@1
  int v29; // [sp+50h] [bp-24h]@26
  float zone; // [sp+54h] [bp-20h]@16
  int temp; // [sp+58h] [bp-1Ch]@16
  Map_Stack obj_stack; // [sp+5Ch] [bp-18h]@12
  RGE_Object_Info_Line *info_linea; // [sp+78h] [bp+4h]@16
  int count; // [sp+7Ch] [bp+8h]@26
  char tile_y; // [sp+80h] [bp+Ch]@16

  v7 = inner_radius;
  v8 = this;
  min_x0 = map_x - inner_radius;
  min_y0 = map_y - inner_radius;
  min_x1 = inner_radius + map_x;
  min_y1 = inner_radius + map_y;
  if ( map_x - inner_radius < 0 )
    min_x0 = 0;
  if ( map_y - inner_radius < 0 )
    min_y0 = 0;
  v9 = this->map_width;
  if ( inner_radius + map_x >= v9 )
    min_x1 = v9 - 1;
  v10 = this->map_height;
  if ( inner_radius + map_y >= v10 )
    min_y1 = v10 - 1;
  memset(v8->search_map, 1u, v9 * v10);
  v11 = 0;
  if ( v8->info.land_num > 0 )
  {
    v12 = (int)v8->info.lands;
    do
    {
      RGE_RMM_Object_Generator::set_search_area(v8, *(_DWORD *)v12, *(_DWORD *)(v12 + 4), v7, 0);
      ++v11;
      v12 += 16;
    }
    while ( v11 < v8->info.land_num );
  }
  RGE_Random_Map_Module::init_stack(&obj_stack);
  RGE_RMM_Object_Generator::make_placement_stack(v8, &obj_stack, map_x, map_y, v7, outer_radius);
  v13 = info_line;
  v14 = 0;
  v15 = info_line->player_id;
  if ( v15 > -1 || (v15 = v8->info.lands[land_id].player_id, v15 > 0) )
    v14 = v15;
  v16 = v8->world;
  v17 = v16->players[v14];
  v18 = v17->master_objects[info_line->obj_id];
  if ( v18 )
  {
    land_id = (int)RGE_Zone_Map_List::get_zone_map(v8->map->map_zones, v16->terrains[v18->terrain], 32, &temp);
    tile_y = RGE_Zone_Map::get_zone_info((RGE_Zone_Map *)land_id, map_x, map_y);
    info_linea = (RGE_Object_Info_Line *)info_line->number_of_groups;
    while ( RGE_Random_Map_Module::pop_stack(&obj_stack, &inner_radius, &y, &zone) )
    {
      if ( (signed int)info_linea <= 0 )
        break;
      if ( tile_y == RGE_Zone_Map::get_zone_info((RGE_Zone_Map *)land_id, inner_radius, y) )
      {
        v19 = v13->terrain;
        v20 = inner_radius;
        if ( v19 >= 0 )
        {
          if ( (*((_BYTE *)&v8->map_row_offset[y][inner_radius] + 5) & 0x1F) != v19 )
            continue;
          v20 = inner_radius;
        }
        if ( v20 > min_x0 && v20 < min_x1 && y > min_y0 && y < min_y1 )
          continue;
        v21 = v13->obj_id;
        v22 = v17->master_objects;
        *(float *)&outer_radius = (double)inner_radius;
        v23 = v22[v21];
        *(float *)&count = (double)y;
        v29 = (signed __int16)(signed __int64)v23->radius_x;
        if ( v23->radius_x - (double)v29 > 0.0 )
          *(float *)&outer_radius = *(float *)&outer_radius - -0.5;
        v29 = (signed __int16)(signed __int64)v23->radius_y;
        if ( v23->radius_y - (double)v29 > 0.0 )
          *(float *)&count = *(float *)&count - -0.5;
        if ( (unsigned __int8)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, int, int, _DWORD, _DWORD, signed int, signed int, signed int, signed int, signed int))v23->vfptr->check_placement)(
                                v23,
                                v17,
                                outer_radius,
                                count,
                                0,
                                0,
                                1,
                                1,
                                1,
                                1,
                                1) )
        {
          if ( !v13->group_flag && !obj_stack.next )
            ((void (__thiscall *)(RGE_Player *, int, int, int, _DWORD, signed int))v17->vfptr->make_new_object)(
              v17,
              v13->obj_id,
              outer_radius,
              count,
              0,
              1);
          continue;
        }
        RGE_RMM_Object_Generator::remove_area_from_lists(v8, inner_radius, y, v13->object_exclusion_zone);
        if ( !v13->group_flag )
        {
          ((void (__thiscall *)(RGE_Player *, int, int, int, _DWORD, signed int))v17->vfptr->make_new_object)(
            v17,
            v13->obj_id,
            outer_radius,
            count,
            0,
            1);
LABEL_37:
          info_linea = (RGE_Object_Info_Line *)((char *)info_linea - 1);
          continue;
        }
        if ( v13->group_flag == 1 )
        {
          RGE_RMM_Object_Generator::place_group(v8, v13, inner_radius, y, v17);
          info_linea = (RGE_Object_Info_Line *)((char *)info_linea - 1);
        }
        else
        {
          if ( v13->group_flag != 2 )
            goto LABEL_37;
          RGE_RMM_Object_Generator::place_cluster(v8, v13, inner_radius, y, v17);
          info_linea = (RGE_Object_Info_Line *)((char *)info_linea - 1);
        }
      }
    }
    RGE_Random_Map_Module::deinit_stack(&obj_stack);
  }
}

//----- (00486A60) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::place_group(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line, int map_x, int map_y, RGE_Player *player)
{
  RGE_RMM_Object_Generator *v5; // ebx@1
  RGE_Object_Info_Line *v6; // esi@1
  int v7; // ebp@1
  int v8; // edi@1
  RGE_Player *v9; // edi@4
  int v10; // ecx@6
  RGE_Master_Static_Object *v11; // esi@8
  int y; // [sp+3Ch] [bp-2Ch]@3
  int x; // [sp+40h] [bp-28h]@3
  RGE_RMM_Object_Generator *v14; // [sp+44h] [bp-24h]@1
  int v15; // [sp+48h] [bp-20h]@8
  float zone; // [sp+4Ch] [bp-1Ch]@3
  Map_Stack obj_stack; // [sp+50h] [bp-18h]@1
  int map_xa; // [sp+70h] [bp+8h]@8
  int tile_y; // [sp+74h] [bp+Ch]@1
  int count; // [sp+78h] [bp+10h]@8

  v5 = this;
  v14 = this;
  RGE_Random_Map_Module::init_stack(&obj_stack);
  v6 = info_line;
  RGE_RMM_Object_Generator::make_placement_stack(v5, &obj_stack, map_x, map_y, 0, info_line->group_area);
  v7 = info_line->object_number_per_group;
  v8 = info_line->object_number_varience;
  tile_y = 2 * v8 * debug_rand(aCMsdevWorkA_47, 530) / 0x7FFF - v8 + v7;
  if ( tile_y < 1 )
    tile_y = 1;
  if ( RGE_Random_Map_Module::pop_stack(&obj_stack, &x, &y, &zone) )
  {
    v9 = player;
    do
    {
      if ( tile_y <= 0 )
        break;
      v10 = v6->terrain;
      if ( v10 < 0 || (*((_BYTE *)&v5->map_row_offset[y][x] + 5) & 0x1F) == v10 )
      {
        *(float *)&count = (double)x;
        v11 = v9->master_objects[v6->obj_id];
        *(float *)&map_xa = (double)y;
        v15 = (signed __int16)(signed __int64)v11->radius_x;
        if ( v11->radius_x - (double)v15 > 0.0 )
          *(float *)&count = *(float *)&count - -0.5;
        v15 = (signed __int16)(signed __int64)v11->radius_y;
        if ( v11->radius_y - (double)v15 > 0.0 )
          *(float *)&map_xa = *(float *)&map_xa - -0.5;
        if ( !(unsigned __int8)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, int, int, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, signed int))v11->vfptr->check_placement)(
                                 v11,
                                 v9,
                                 count,
                                 map_xa,
                                 0,
                                 0,
                                 1,
                                 1,
                                 1,
                                 0,
                                 1) )
        {
          ((void (__thiscall *)(RGE_Player *, int, int, int, _DWORD, signed int))v9->vfptr->make_new_object)(
            v9,
            info_line->obj_id,
            count,
            map_xa,
            0,
            1);
          --tile_y;
        }
        v5 = v14;
        v6 = info_line;
      }
    }
    while ( RGE_Random_Map_Module::pop_stack(&obj_stack, &x, &y, &zone) );
  }
  RGE_Random_Map_Module::deinit_stack(&obj_stack);
}

//----- (00486C40) --------------------------------------------------------
void __thiscall RGE_RMM_Object_Generator::place_cluster(RGE_RMM_Object_Generator *this, RGE_Object_Info_Line *info_line, int map_x, int map_y, RGE_Player *player)
{
  RGE_RMM_Object_Generator *v5; // esi@1
  int v6; // eax@1
  int v7; // edx@1
  int v8; // ecx@1
  int v9; // edi@1
  int v10; // ebp@1
  int v11; // eax@5
  int v12; // eax@7
  int v13; // eax@10
  int v14; // ebp@13
  int v15; // edi@13
  int v16; // ebp@13
  RGE_Master_Static_Object *v17; // edi@19
  RGE_Master_Static_ObjectVtbl *v18; // ebp@23
  int v19; // eax@24
  int v20; // ecx@25
  float tot_cost; // ST4C_4@26
  float v22; // ST4C_4@30
  float v23; // ST4C_4@33
  float v24; // ST4C_4@36
  int y; // [sp+60h] [bp-38h]@9
  int x; // [sp+64h] [bp-34h]@10
  float tile_y; // [sp+68h] [bp-30h]@19
  float tile_x; // [sp+6Ch] [bp-2Ch]@19
  int x1; // [sp+70h] [bp-28h]@1
  int y0; // [sp+74h] [bp-24h]@1
  int y1; // [sp+78h] [bp-20h]@1
  float zone; // [sp+7Ch] [bp-1Ch]@15
  Map_Stack obj_stack; // [sp+80h] [bp-18h]@1
  int map_xa; // [sp+A0h] [bp+8h]@13
  int count; // [sp+A4h] [bp+Ch]@1

  v5 = this;
  obj_stack.next = 0;
  obj_stack.prev = 0;
  RGE_Random_Map_Module::init_stack(&obj_stack);
  RGE_Random_Map_Module::add_stack_node(&obj_stack, &v5->stack_offsets[map_y][map_x]);
  v6 = info_line->group_area;
  v7 = map_x - v6;
  v8 = map_y - v6;
  v9 = v6 + map_x;
  v10 = v6 + map_y;
  count = map_x - v6;
  y0 = v8;
  x1 = v6 + map_x;
  y1 = v10;
  if ( map_x - v6 < 0 )
  {
    count = 0;
    v7 = 0;
  }
  if ( v8 < 0 )
  {
    y0 = 0;
    v8 = 0;
  }
  v11 = v5->map_width;
  if ( v9 >= v11 )
  {
    x1 = v11 - 1;
    v9 = v11 - 1;
  }
  v12 = v5->map_height;
  if ( v10 >= v12 )
  {
    y1 = v12 - 1;
    v10 = v12 - 1;
  }
  for ( y = v8; y <= v10; ++y )
  {
    v13 = v7;
    for ( x = v7; x <= v9; ++x )
    {
      v5->search_map_rows[y][v13] = 1;
      v13 = x + 1;
    }
  }
  v14 = info_line->object_number_per_group;
  v15 = info_line->object_number_varience;
  v16 = 2 * v15 * debug_rand(aCMsdevWorkA_47, 598) / 0x7FFF - v15 + v14;
  map_xa = v16;
  if ( v16 < 1 )
  {
    map_xa = 1;
    v16 = 1;
  }
  if ( RGE_Random_Map_Module::pop_stack(&obj_stack, &x, &y, &zone) )
  {
    while ( v16 > 0 )
    {
      v17 = player->master_objects[info_line->obj_id];
      tile_x = (double)x;
      tile_y = (double)y;
      if ( v17->radius_x - (double)(signed __int16)(signed __int64)v17->radius_x > 0.0 )
        tile_x = tile_x - -0.5;
      if ( v17->radius_y - (double)(signed __int16)(signed __int64)v17->radius_y > 0.0 )
        tile_y = tile_y - -0.5;
      v18 = v17->vfptr;
      v17->vfptr->alignment(v17, &tile_x, &tile_y, v5->world, 1);
      if ( !(unsigned __int8)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, signed int))v18->check_placement)(
                               v17,
                               player,
                               LODWORD(tile_x),
                               LODWORD(tile_y),
                               0,
                               0,
                               1,
                               1,
                               1,
                               0,
                               1) )
      {
        ((void (__thiscall *)(RGE_Player *, int, _DWORD, _DWORD, _DWORD, signed int))player->vfptr->make_new_object)(
          player,
          info_line->obj_id,
          LODWORD(tile_x),
          LODWORD(tile_y),
          0,
          1);
        --map_xa;
        v5->search_map_rows[y][x] = 0;
        v19 = x;
        if ( x <= count )
        {
          v20 = y;
        }
        else
        {
          v20 = y;
          if ( v5->search_map_rows[y][x - 1] )
          {
            tot_cost = (double)debug_rand(aCMsdevWorkA_47, 624);
            RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v5->vfptr, &obj_stack, x - 1, y, 0.0, tot_cost);
            v20 = y;
            v19 = x;
          }
        }
        if ( v19 < x1 && v5->search_map_rows[v20][v19 + 1] )
        {
          v22 = (double)debug_rand(aCMsdevWorkA_47, 627);
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v5->vfptr, &obj_stack, x + 1, y, 0.0, v22);
          v20 = y;
          v19 = x;
        }
        if ( v20 > y0 && v5->search_map_rows[v20 - 1][v19] )
        {
          v23 = (double)debug_rand(aCMsdevWorkA_47, 630);
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v5->vfptr, &obj_stack, x, y - 1, 0.0, v23);
          v20 = y;
          v19 = x;
        }
        if ( v20 < y1 && v5->search_map_rows[v20 + 1][v19] )
        {
          v24 = (double)debug_rand(aCMsdevWorkA_47, 633);
          RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v5->vfptr, &obj_stack, x, y + 1, 0.0, v24);
        }
      }
      if ( !RGE_Random_Map_Module::pop_stack(&obj_stack, &x, &y, &zone) )
        break;
      v16 = map_xa;
    }
  }
  RGE_Random_Map_Module::deinit_stack(&obj_stack);
}
