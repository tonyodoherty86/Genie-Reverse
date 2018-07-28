
//----- (00546720) --------------------------------------------------------
char __cdecl zone_pop(Zone_Queue **zone_queue, Zone_Queue **zone_end, int *x, int *y)
{
  Zone_Queue *v4; // eax@1
  char result; // al@2
  Zone_Queue *v6; // ST00_4@3

  v4 = *zone_queue;
  if( *zone_queue )
  {
    v6 = *zone_queue;
    *x = v4->x;
    *y = v4->y;
    *zone_queue = v4->next;
    free(v6);
    if( !*zone_queue )
      *zone_end = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00546770) --------------------------------------------------------
void __cdecl zone_push(Zone_Queue **zone_queue, Zone_Queue **zone_end, int x, int y)
{
  Zone_Queue *v4; // eax@1

  v4 = (Zone_Queue *)calloc(1u, 0xCu);
  if( *zone_end )
    (*zone_end)->next = v4;
  v4->x = x;
  v4->y = y;
  *zone_end = v4;
  if( !*zone_queue )
    *zone_queue = v4;
}

//----- (005467B0) --------------------------------------------------------
void __userpurge RGE_Zone_Map::RGE_Zone_Map(RGE_Zone_Map *this@<ecx>, int a2@<ebp>, int infile, RGE_Map *new_map)
{
  RGE_Zone_Map *v4; // esi@1
  char *v5; // eax@1
  RGE_Map *v6; // edx@1
  char **v7; // eax@1
  RGE_Map *v8; // ecx@1
  int i; // eax@1
  int v10; // edi@3
  float *v11; // eax@4
  int v12; // ST08_4@4

  v4 = this;
  this->map = new_map;
  v5 = (char *)calloc(new_map->map_height * new_map->map_width, 1u);
  v6 = v4->map;
  v4->zone_map = v5;
  v7 = (char **)calloc(v6->map_height, 4u);
  v8 = v4->map;
  v4->zone_map_rows = v7;
  for( i = 0; i < v8->map_height; ++i )
  {
    v4->zone_map_rows[i] = &v4->zone_map[i * v8->map_width];
    v8 = v4->map;
  }
  v10 = infile;
  rge_read(a2, infile, infile, v4->zone_info, 255);
  rge_read(a2, v10, v10, v4, 1020);
  rge_read(a2, v10, v10, v4->zone_map, v4->map->map_width * v4->map->map_height);
  rge_read(a2, v10, v10, &v4->terrain_passability_rules_num, 4);
  if( v4->terrain_passability_rules_num <= 0 )
  {
    v4->terrain_passability_rules = 0;
  }
  else
  {
    v11 = (float *)calloc(v4->terrain_passability_rules_num, 4u);
    v12 = 4 * v4->terrain_passability_rules_num;
    v4->terrain_passability_rules = v11;
    rge_read(a2, infile, infile, v11, v12);
  }
}

//----- (005468C0) --------------------------------------------------------
void __thiscall RGE_Zone_Map::RGE_Zone_Map(RGE_Zone_Map *this, RGE_Map *new_map, float *new_terrain_rules, int new_terrain_rules_num)
{
  RGE_Zone_Map *v4; // ebx@1
  char *v5; // edi@1
  RGE_Map *v6; // eax@1
  char **v7; // eax@1
  RGE_Map *v8; // ecx@1
  int i; // eax@1
  signed int v10; // eax@3
  RGE_Zone_Map *v11; // ecx@3
  float *v12; // eax@5
  unsigned int v13; // edx@5

  v4 = this;
  this->map = new_map;
  v5 = (char *)calloc(new_map->map_width * new_map->map_height, 1u);
  v6 = v4->map;
  v4->zone_map = v5;
  memset(v5, 0xFFu, v6->map_width * v6->map_height);
  v7 = (char **)calloc(v4->map->map_height, 4u);
  v8 = v4->map;
  v4->zone_map_rows = v7;
  for( i = 0; i < v8->map_height; ++i )
  {
    v4->zone_map_rows[i] = &v4->zone_map[i * v8->map_width];
    v8 = v4->map;
  }
  v10 = 0;
  v11 = v4;
  do
  {
    v4->zone_info[v10] = -1;
    v11->numberTilesInZoneValue[0] = 0;
    ++v10;
    v11 = (RGE_Zone_Map *)((char *)v11 + 4);
  }
  while( v10 < 255 );
  v4->terrain_passability_rules_num = new_terrain_rules_num;
  v12 = (float *)calloc(new_terrain_rules_num, 4u);
  v13 = 4 * v4->terrain_passability_rules_num;
  v4->terrain_passability_rules = v12;
  qmemcpy(v12, new_terrain_rules, v13);
  RGE_Zone_Map::do_zone_map(v4);
}

//----- (005469C0) --------------------------------------------------------
void __thiscall RGE_Zone_Map::~RGE_Zone_Map(RGE_Zone_Map *this)
{
  RGE_Zone_Map *v1; // esi@1

  v1 = this;
  free(this->zone_map);
  free(v1->zone_map_rows);
  free(v1->terrain_passability_rules);
}

//----- (00546A00) --------------------------------------------------------
void __thiscall RGE_Zone_Map::save(RGE_Zone_Map *this, int outfile)
{
  RGE_Zone_Map *v2; // esi@1
  int v3; // ebx@1

  v2 = this;
  rge_write(outfile, this->zone_info, 255);
  rge_write(outfile, v2, 1020);
  rge_write(outfile, v2->zone_map, v2->map->map_width * v2->map->map_height);
  rge_write(outfile, &v2->terrain_passability_rules_num, 4);
  v3 = v2->terrain_passability_rules_num;
  if( v3 > 0 )
    rge_write(outfile, v2->terrain_passability_rules, 4 * v3);
}

//----- (00546A90) --------------------------------------------------------
char __thiscall RGE_Zone_Map::do_zone_map(RGE_Zone_Map *this)
{
  RGE_Zone_Map *v1; // ebp@1
  RGE_Map *v2; // eax@1
  signed int v3; // ebx@1
  int v4; // esi@1
  int v5; // edx@1
  char *v6; // edi@1
  int v7; // ecx@1
  int v8; // eax@2
  int v9; // edi@6
  int v10; // esi@7
  char **v11; // ecx@9
  int v13; // [sp+10h] [bp-14h]@8
  int y; // [sp+14h] [bp-10h]@6
  char group; // [sp+18h] [bp-Ch]@12
  int map_width; // [sp+1Ch] [bp-8h]@1
  int map_height; // [sp+20h] [bp-4h]@1

  v1 = this;
  v2 = this->map;
  v3 = 0;
  v4 = v2->map_width;
  v5 = v2->map_height;
  map_width = v4;
  memset(this->zone_info, 0xFFu, 0xFCu);
  v6 = &this->zone_info[252];
  *(_WORD *)v6 = -1;
  v7 = 0;
  map_height = v5;
  for( v6[2] = -1; v7 < v4; ++v7 )
  {
    v8 = 0;
    if( v5 > 0 )
    {
      do
        v1->zone_map_rows[v7][++v8 - 1] = -1;
      while( v8 < v5 );
      v4 = map_width;
    }
  }
  v9 = 0;
  y = 0;
  if( v4 > 0 )
  {
    do
    {
      v10 = 0;
      if( v5 > 0 )
      {
        v13 = 0;
        do
        {
          v11 = &v1->zone_map_rows[v9];
          if( (*v11)[v10] == -1 )
          {
            if( v3 >= 255 )
              v3 = 0;
            group = 1;
            if( v1->terrain_passability_rules[*((_BYTE *)&v1->map->map_row_offset[v9][v13] + 5) & 0x1F] <= 0.0 )
              group = 0;
            (*v11)[v10] = v3;
            RGE_Zone_Map::do_zone_map_area(v1, v10, y, group, v3);
            v5 = map_height;
            ++v3;
          }
          ++v10;
          ++v13;
        }
        while( v10 < v5 );
      }
      ++v9;
      ++y;
    }
    while( y < map_width );
  }
  return 1;
}

//----- (00546BB0) --------------------------------------------------------
void __thiscall RGE_Zone_Map::do_zone_map_area(RGE_Zone_Map *this, int x, int y, char group, char zone)
{
  RGE_Zone_Map *v5; // esi@1
  char v6; // bl@1
  RGE_Map *v7; // eax@1
  int v8; // ecx@1
  int v9; // eax@1
  int v10; // ecx@2
  int v11; // edx@2
  char *v12; // edi@3
  char *v13; // edi@7
  char *v14; // edi@11
  int v15; // eax@15
  int v16; // edx@15
  char *v17; // ecx@15
  Zone_Queue *zone_end; // [sp+10h] [bp-10h]@1
  Zone_Queue *zone_queue; // [sp+14h] [bp-Ch]@1
  int v20; // [sp+18h] [bp-8h]@1
  int v21; // [sp+1Ch] [bp-4h]@1

  v5 = this;
  v6 = zone;
  zone_queue = 0;
  zone_end = 0;
  v7 = this->map;
  v8 = v7->map_width;
  v9 = v7->map_height - 1;
  v20 = v8 - 1;
  v21 = v9;
  do
  {
    v10 = x;
    v11 = y;
    if( x > 0 )
    {
      v12 = &v5->zone_map_rows[y][x - 1];
      if( *v12 == -1
        && v5->terrain_passability_rules[*((_BYTE *)&v5->map->map_row_offset[y][x] - 19) & 0x1F] > 0.0 == group )
      {
        *v12 = v6;
        zone_push(&zone_queue, &zone_end, x - 1, y);
        v11 = y;
        v10 = x;
      }
    }
    if( v11 > 0 )
    {
      v13 = &v5->zone_map_rows[v11 - 1][v10];
      if( *v13 == -1
        && v5->terrain_passability_rules[*((_BYTE *)&v5->map->map_row_offset[v11 - 1][v10] + 5) & 0x1F] > 0.0 == group )
      {
        *v13 = v6;
        zone_push(&zone_queue, &zone_end, x, y - 1);
        v11 = y;
        v10 = x;
      }
    }
    if( v10 < v20 )
    {
      v14 = &v5->zone_map_rows[v11][v10 + 1];
      if( *v14 == -1
        && v5->terrain_passability_rules[*((_BYTE *)&v5->map->map_row_offset[v11][v10 + 1] + 5) & 0x1F] > 0.0 == group )
      {
        *v14 = v6;
        zone_push(&zone_queue, &zone_end, x + 1, y);
        v11 = y;
        v10 = x;
      }
    }
    if( v11 < v21 )
    {
      v15 = 4 * v11 + 4;
      v16 = (int)&(*(RGE_Tile **)((char *)v5->map->map_row_offset + v15))[v10].screen_xpos;
      v17 = &(*(char **)((char *)v5->zone_map_rows + v15))[v10];
      if( *v17 == -1 && v5->terrain_passability_rules[*(_BYTE *)(v16 + 5) & 0x1F] > 0.0 == group )
      {
        *v17 = v6;
        zone_push(&zone_queue, &zone_end, x, y + 1);
      }
    }
  }
  while( zone_pop(&zone_queue, &zone_end, &x, &y) );
}

//----- (00546E50) --------------------------------------------------------
RGE_Zone_Map *__thiscall RGE_Zone_Map::check_info(RGE_Zone_Map *this, float *new_terrain_rules, int new_terrain_rules_num)
{
  int v3; // esi@1
  int i; // edx@2
  double v5; // st7@3
  bool v6; // c0@3
  bool v7; // c3@3
  RGE_Zone_Map *result; // eax@8

  v3 = this->terrain_passability_rules_num;
  if( new_terrain_rules_num == v3 )
  {
    for( i = 0; i < v3; ++i )
    {
      v5 = this->terrain_passability_rules[i];
      v6 = v5 < 0.0;
      v7 = v5 == 0.0;
      if( new_terrain_rules[i] > 0.0 )
      {
        if( v6 || v7 )
          goto LABEL_9;
      }
      else if( !v6 && !v7 )
      {
        goto LABEL_9;
      }
    }
    result = this;
  }
  else
  {
LABEL_9:
    result = 0;
  }
  return result;
}

//----- (00546EB0) --------------------------------------------------------
char __thiscall RGE_Zone_Map::get_zone_info(RGE_Zone_Map *this, int x, int y)
{
  return this->zone_map_rows[y][x];
}

//----- (00546ED0) --------------------------------------------------------
int __thiscall RGE_Zone_Map::withinRange(RGE_Zone_Map *this, XYPoint start, XYPoint goal, float range)
{
  return RGE_Zone_Map::withinRange(this, this->zone_map_rows[start.y][start.x], goal, range);
}

//----- (00546F00) --------------------------------------------------------
int __thiscall RGE_Zone_Map::withinRange(RGE_Zone_Map *this, char startZone, XYPoint goal, float range)
{
  RGE_Zone_Map *v4; // edi@1
  signed __int64 v5; // rax@1
  int v6; // ecx@1
  int v7; // ebp@1
  int v8; // ebx@5
  int v9; // eax@5
  int v10; // eax@7
  int v11; // edi@9
  int v12; // esi@10
  int v13; // edx@11
  int v14; // esi@12
  int v15; // ecx@12
  int v17; // [sp+0h] [bp-14h]@10
  RGE_Zone_Map *v18; // [sp+8h] [bp-Ch]@1
  int max; // [sp+Ch] [bp-8h]@5
  int max_4; // [sp+10h] [bp-4h]@5

  v4 = this;
  v18 = this;
  v5 = (signed __int64)range;
  v6 = goal.x - v5;
  v7 = goal.y - v5;
  if( goal.x - (signed int)v5 < 0 )
    v6 = 0;
  if( v7 < 0 )
    v7 = 0;
  HIDWORD(v5) = goal.x + v5;
  v8 = v5 + goal.y;
  LODWORD(v5) = v4->map;
  max = HIDWORD(v5);
  max_4 = v8;
  if( SHIDWORD(v5) > *(_DWORD *)(v5 + 8) - 1 )
    max = *(_DWORD *)(v9 + 8) - 1;
  v10 = *(_DWORD *)(v9 + 12) - 1;
  if( v8 > v10 )
  {
    v8 = v10;
    max_4 = v10;
  }
  v11 = v6;
  if( v6 <= max )
  {
    v12 = goal.x - v6;
    v17 = goal.x - v6;
    while( 1 )
    {
      v13 = v7;
      if( v7 <= v8 )
        break;
LABEL_18:
      ++v11;
      v17 = --v12;
      if( v11 > max )
        return 0;
    }
    v14 = v12 * v12;
    v15 = goal.y - v7;
    while( 1 )
    {
      if( sqrt((double)(v14 + v15 * v15)) <= range )
      {
        if( v18->zone_map_rows[v13][v11] == startZone )
          return 1;
        v8 = max_4;
      }
      ++v13;
      --v15;
      if( v13 > v8 )
      {
        v12 = v17;
        goto LABEL_18;
      }
    }
  }
  return 0;
}

//----- (00547000) --------------------------------------------------------
int __thiscall RGE_Zone_Map::numberTilesInZone(RGE_Zone_Map *this, char zone)
{
  char v2; // bl@1
  RGE_Zone_Map *v3; // ebp@1
  int *v4; // esi@1
  int result; // eax@1
  RGE_Map *v6; // eax@2
  int v7; // edx@2
  int v8; // edi@2
  int v9; // ecx@2
  int v10; // eax@2
  char **v11; // edx@4
  int v12; // esi@4
  int mapWidth; // [sp+Ch] [bp-8h]@2
  int *v14; // [sp+10h] [bp-4h]@1
  int zonea; // [sp+18h] [bp+4h]@2

  v2 = zone;
  v3 = this;
  v4 = &this->numberTilesInZoneValue[(unsigned __int8)zone];
  v14 = v4;
  result = *v4;
  if( *v4 <= 0 )
  {
    v6 = this->map;
    v7 = 0;
    v8 = 0;
    v9 = v6->map_width;
    v10 = v6->map_height;
    mapWidth = v9;
    zonea = 0;
    if( v9 > 0 )
    {
      do
      {
        if( v10 > 0 )
        {
          v11 = v3->zone_map_rows;
          v12 = v10;
          do
          {
            if( (*v11)[v8] == v2 )
              ++zonea;
            ++v11;
            --v12;
          }
          while( v12 );
          v9 = mapWidth;
        }
        ++v8;
      }
      while( v8 < v9 );
      v7 = zonea;
      v4 = v14;
    }
    *v4 = v7;
    result = v7;
  }
  return result;
}

//----- (00547080) --------------------------------------------------------
BOOL __thiscall RGE_Zone_Map::findClosestPointInTerrainType(RGE_Zone_Map *this, XYPoint p, XYPoint *rVal, int type1, int type2, int range)
{
  RGE_Zone_Map *v6; // edx@1
  int v7; // ebx@1
  int v8; // esi@1
  int v9; // ecx@5
  RGE_Map *v10; // eax@5
  int v11; // eax@7
  int v12; // ebp@9
  int v13; // edi@12
  int v14; // eax@13
  RGE_Zone_Map *v16; // [sp+10h] [bp-14h]@1
  int max; // [sp+14h] [bp-10h]@5
  int max_4; // [sp+18h] [bp-Ch]@5
  int min_4; // [sp+20h] [bp-4h]@1
  int rangea; // [sp+3Ch] [bp+18h]@10

  v6 = this;
  v7 = p.x - range;
  v8 = p.y - range;
  v16 = this;
  min_4 = p.y - range;
  if( p.x - range < 0 )
    v7 = 0;
  if( v8 < 0 )
  {
    min_4 = 0;
    v8 = 0;
  }
  v9 = range + p.x;
  v10 = v6->map;
  max = range + p.x;
  max_4 = range + p.y;
  if( range + p.x > v10->map_width - 1 )
  {
    max = v10->map_width - 1;
    v9 = v10->map_width - 1;
  }
  v11 = v10->map_height - 1;
  if( range + p.y > v11 )
    max_4 = v11;
  v12 = -1;
  if( v7 <= v9 )
  {
    rangea = p.x - v7;
    do
    {
      if( v8 <= max_4 )
      {
        v13 = p.y - v8;
        do
        {
          v14 = RGE_Map::get_terrain(v16->map, v7, v8);
          if( (v14 == type1 || v14 == type2) && (v12 == -1 || v12 > v13 * v13 + rangea * rangea) )
          {
            v12 = v13 * v13 + rangea * rangea;
            rVal->x = v7;
            rVal->y = v8;
          }
          ++v8;
          --v13;
        }
        while( v8 <= max_4 );
        v8 = min_4;
        v9 = max;
      }
      ++v7;
      --rangea;
    }
    while( v7 <= v9 );
  }
  return v12 != -1;
}

//----- (00547180) --------------------------------------------------------
void __userpurge RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Zone_Map_List *this@<ecx>, int a2@<edi>, int infile, RGE_Map *in_map)
{
  RGE_Zone_Map_List *v4; // esi@1
  size_t *v5; // ebx@1
  signed int i; // edi@2
  RGE_Zone_Map *v7; // eax@3
  RGE_Zone_Map *v8; // eax@4

  v4 = this;
  v5 = (size_t *)&this->zone_map_num;
  this->zone_maps = 0;
  this->map = in_map;
  rge_read(infile, a2, infile, &this->zone_map_num, 4);
  if( (signed int)*v5 <= 0 )
  {
    v4->zone_maps = 0;
  }
  else
  {
    v4->zone_maps = (RGE_Zone_Map **)calloc(*v5, 4u);
    for( i = 0; i < (signed int)*v5; v4->zone_maps[i - 1] = v8 )
    {
      v7 = (RGE_Zone_Map *)operator new(0x51Cu);
      if( v7 )
        RGE_Zone_Map::RGE_Zone_Map(v7, infile, infile, v4->map);
      else
        v8 = 0;
      ++i;
    }
  }
}

//----- (00547240) --------------------------------------------------------
void __thiscall RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Zone_Map_List *this, RGE_Map *in_map)
{
  this->map = in_map;
  this->zone_maps = 0;
  this->zone_map_num = 0;
}

//----- (00547270) --------------------------------------------------------
void __thiscall RGE_Zone_Map_List::save(RGE_Zone_Map_List *this, int outfile)
{
  RGE_Zone_Map_List *v2; // ebx@1
  char *v3; // edi@1
  int i; // esi@2

  v2 = this;
  v3 = (char *)&this->zone_map_num;
  rge_write(outfile, &this->zone_map_num, 4);
  if( *(_DWORD *)v3 > 0 )
  {
    for( i = 0; i < *(_DWORD *)v3; ++i )
      RGE_Zone_Map::save(v2->zone_maps[i], outfile);
  }
}

//----- (005472B0) --------------------------------------------------------
int __thiscall RGE_Zone_Map_List::create_zone_map(RGE_Zone_Map_List *this, float *new_terrain_rules, int new_terrain_rules_num)
{
  RGE_Zone_Map_List *v3; // ebx@1
  int v4; // ebp@1
  int v5; // esi@1
  RGE_Zone_Map **v6; // eax@4
  RGE_Zone_Map **v7; // edi@4
  RGE_Zone_Map *v8; // eax@6
  RGE_Zone_Map *v9; // eax@7
  int v10; // eax@9
  int result; // eax@9
  int new_terrain_rules_numa; // [sp+24h] [bp+8h]@4

  v3 = this;
  v4 = new_terrain_rules_num;
  v5 = 0;
  if( this->zone_map_num <= 0 )
  {
LABEL_4:
    v6 = (RGE_Zone_Map **)calloc(v3->zone_map_num + 1, 4u);
    v7 = v6;
    new_terrain_rules_numa = (int)v6;
    if( v3->zone_maps )
    {
      qmemcpy(v6, v3->zone_maps, 4 * v3->zone_map_num);
      free(v3->zone_maps);
      v7 = (RGE_Zone_Map **)new_terrain_rules_numa;
    }
    v8 = (RGE_Zone_Map *)operator new(0x51Cu);
    if( v8 )
      RGE_Zone_Map::RGE_Zone_Map(v8, v3->map, new_terrain_rules, v4);
    else
      v9 = 0;
    v7[v3->zone_map_num] = v9;
    v10 = v3->zone_map_num + 1;
    v3->zone_maps = v7;
    v3->zone_map_num = v10;
    result = v10 - 1;
  }
  else
  {
    while( !RGE_Zone_Map::check_info(v3->zone_maps[v5], new_terrain_rules, new_terrain_rules_num) )
    {
      if( ++v5 >= v3->zone_map_num )
        goto LABEL_4;
    }
    if( RGE_Zone_Map::do_zone_map(v3->zone_maps[v5]) )
      result = v5;
    else
      result = -1;
  }
  return result;
}

//----- (005473B0) --------------------------------------------------------
RGE_Zone_Map *__thiscall RGE_Zone_Map_List::get_zone_map(RGE_Zone_Map_List *this, float *new_terrain_rules, int new_terrain_rules_num, int *zoneMapIndex)
{
  RGE_Zone_Map_List *v4; // ebx@1
  int v5; // esi@1
  RGE_Zone_Map **v6; // eax@4
  RGE_Zone_Map **v7; // ebp@4
  RGE_Zone_Map *v8; // eax@6
  RGE_Zone_Map *v9; // eax@7
  int v10; // eax@9
  RGE_Zone_Map *result; // eax@9

  v4 = this;
  v5 = 0;
  if( this->zone_map_num <= 0 )
  {
LABEL_4:
    v6 = (RGE_Zone_Map **)calloc(v4->zone_map_num + 1, 4u);
    v7 = v6;
    if( v4->zone_maps )
    {
      qmemcpy(v6, v4->zone_maps, 4 * v4->zone_map_num);
      free(v4->zone_maps);
    }
    v8 = (RGE_Zone_Map *)operator new(0x51Cu);
    if( v8 )
      RGE_Zone_Map::RGE_Zone_Map(v8, v4->map, new_terrain_rules, new_terrain_rules_num);
    else
      v9 = 0;
    v7[v4->zone_map_num] = v9;
    v10 = v4->zone_map_num + 1;
    v4->zone_maps = v7;
    v4->zone_map_num = v10;
    *zoneMapIndex = v10 - 1;
    result = v7[v4->zone_map_num - 1];
  }
  else
  {
    while( !RGE_Zone_Map::check_info(v4->zone_maps[v5], new_terrain_rules, new_terrain_rules_num) )
    {
      if( ++v5 >= v4->zone_map_num )
        goto LABEL_4;
    }
    *zoneMapIndex = v5;
    result = v4->zone_maps[v5];
  }
  return result;
}

//----- (005474B0) --------------------------------------------------------
RGE_Zone_Map *__thiscall RGE_Zone_Map_List::get_zone_map(RGE_Zone_Map_List *this, int id)
{
  RGE_Zone_Map *result; // eax@3

  if( id >= this->zone_map_num || id < 0 )
    result = 0;
  else
    result = this->zone_maps[id];
  return result;
}

//----- (005474D0) --------------------------------------------------------
void __thiscall RGE_Zone_Map_List::delete_zone_maps(RGE_Zone_Map_List *this)
{
  RGE_Zone_Map_List *v1; // edi@1
  int v2; // eax@2
  int v3; // ebx@3
  RGE_Zone_Map *v4; // esi@4

  v1 = this;
  if( this->zone_maps )
  {
    v2 = this->zone_map_num;
    if( v2 > 0 )
    {
      v3 = 0;
      if( v2 > 0 )
      {
        do
        {
          v4 = v1->zone_maps[v3];
          if( v4 )
          {
            RGE_Zone_Map::~RGE_Zone_Map(v1->zone_maps[v3]);
            operator delete(v4);
          }
          ++v3;
        }
        while( v3 < v1->zone_map_num );
      }
      free(v1->zone_maps);
      v1->zone_maps = 0;
      v1->zone_map_num = 0;
    }
  }
}
