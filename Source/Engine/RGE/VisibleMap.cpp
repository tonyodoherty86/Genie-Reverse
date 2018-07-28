
//----- (0053B5A0) --------------------------------------------------------
void __thiscall Visible_Unit_Manager::Visible_Unit_Manager(Visible_Unit_Manager *this, int Num_Players, int Num_Categories)
{
  Visible_Unit_Manager *v3; // edi@1
  int v4; // ebp@1
  int v5; // ebx@2
  __int16 *v6; // esi@3
  _DWORD *v7; // ebx@6
  signed int v8; // esi@6
  struct VISIBLE_UNIT_REC **v9; // eax@7

  v3 = this;
  v4 = 0;
  this->Player_Count = Num_Players;
  this->Category_Count = Num_Categories + 1;
  this->distanceTable = 0;
  for ( this->PlayerDataPtrs = (VISIBLE_UNIT_PTR **)calloc(Num_Players, 4u); v4 < v3->Player_Count; ++v4 )
  {
    v5 = 0;
    v3->PlayerDataPtrs[v4] = (VISIBLE_UNIT_PTR *)calloc(v3->Category_Count, 8u);
    if ( v3->Category_Count > 0 )
    {
      v6 = &v3->PlayerDataPtrs[v4]->used;
      do
      {
        *(v6 - 1) = 32;
        *v6 = 0;
        *(_DWORD *)(v6 - 3) = calloc(0x20u, 8u);
        ++v5;
        v6 += 4;
      }
      while ( v5 < v3->Category_Count );
    }
  }
  v7 = v3->Return_Buffer;
  v8 = 0;
  do
  {
    v9 = (struct VISIBLE_UNIT_REC **)malloc(0x800u);
    *v7 = v9;
    (&VisibleUnitList)[v8] = v9;
    (&VisibleUnitList_Size)[v8] = 0;
    ++v8;
    ++v7;
  }
  while ( v8 < 5 );
  Visible_Unit_Manager::Build_Distance_Table(v3);
  VisibleUnitManager = v3;
}
// 87D7C8: using guessed type int *VisibleUnitList_Size;
// 87D7E0: using guessed type struct VISIBLE_UNIT_REC **VisibleUnitList;

//----- (0053B670) --------------------------------------------------------
void __thiscall Visible_Unit_Manager::~Visible_Unit_Manager(Visible_Unit_Manager *this)
{
  Visible_Unit_Manager *v1; // ebx@1
  int v2; // eax@2
  VISIBLE_UNIT_PTR *v3; // ebp@3
  int v4; // edi@4
  void **v5; // esi@5
  void **v6; // edi@12
  signed int v7; // esi@12
  char *v8; // ebx@16
  int i; // [sp+10h] [bp-4h]@2

  v1 = this;
  if ( this->PlayerDataPtrs )
  {
    v2 = 0;
    i = 0;
    if ( this->Player_Count > 0 )
    {
      do
      {
        v3 = v1->PlayerDataPtrs[v2];
        if ( v3 )
        {
          v4 = 0;
          if ( v1->Category_Count > 0 )
          {
            v5 = (void **)&v1->PlayerDataPtrs[v2]->unit_list;
            do
            {
              if ( *v5 )
                free(*v5);
              ++v4;
              v5 += 2;
            }
            while ( v4 < v1->Category_Count );
          }
          free(v3);
          v2 = i;
        }
        i = ++v2;
      }
      while ( v2 < v1->Player_Count );
    }
    free(v1->PlayerDataPtrs);
  }
  v6 = (void **)v1->Return_Buffer;
  v7 = 0;
  do
  {
    if ( *v6 )
      free(*v6);
    (&VisibleUnitList)[v7] = 0;
    (&VisibleUnitList_Size)[v7] = 0;
    ++v7;
    ++v6;
  }
  while ( v7 < 5 );
  v8 = v1->distanceTable;
  if ( v8 )
    free(v8);
  VisibleUnitManager = 0;
}
// 87D7C8: using guessed type int *VisibleUnitList_Size;
// 87D7E0: using guessed type struct VISIBLE_UNIT_REC **VisibleUnitList;

//----- (0053B730) --------------------------------------------------------
void __thiscall Visible_Unit_Manager::Build_Distance_Table(Visible_Unit_Manager *this)
{
  Visible_Unit_Manager *v1; // ebp@1
  char *v2; // edi@3
  struct LOSTBL ***v3; // ecx@3
  char v4; // bl@3
  struct LOSTBL **v5; // esi@4
  signed int v6; // eax@4
  signed int v7; // edx@5
  signed int v8; // ecx@5
  int v9; // eax@11
  int v10; // edi@12
  char *v11; // ecx@13
  struct LOSTBL ***v12; // [sp+10h] [bp-4h]@3

  v1 = this;
  if ( this->distanceTable )
    free(this->distanceTable);
  v2 = (char *)malloc(0x100u);
  v1->distanceTable = v2;
  memset(v2, 0xFFu, 0x100u);
  v3 = &NormalLOS;
  v4 = 0;
  v12 = &NormalLOS;
  do
  {
    v5 = *v3;
    v6 = (signed int)**v3;
    if ( v6 != 999 )
    {
      do
      {
        v7 = (signed int)v5[1];
        v8 = (signed int)v5[2];
        if ( v6 >= 0 && v6 <= 15 )
        {
          if ( v7 < 0 )
            v7 = 0;
          if ( v8 > 15 )
            v8 = 15;
          v9 = v7 + 16 * v6;
          if ( v7 <= v8 )
          {
            v10 = v8 - v7 + 1;
            do
            {
              v11 = &v1->distanceTable[v9];
              if ( *v11 == -1 )
                *v11 = v4;
              ++v9;
              --v10;
            }
            while ( v10 );
          }
        }
        v6 = (signed int)v5[3];
        v5 += 3;
      }
      while ( v6 != 999 );
      v3 = v12;
    }
    ++v3;
    ++v4;
    v12 = v3;
  }
  while ( (signed int)v3 <= (signed int)&off_58EA50 );
}
// 58EA10: using guessed type struct LOSTBL **NormalLOS;
// 58EA50: using guessed type void *off_58EA50;

//----- (0053B7E0) --------------------------------------------------------
void __thiscall Visible_Unit_Manager::Update_Unit_Info(Visible_Unit_Manager *this, int Object_Id, int player_id, int Xpos, int Ypos, int Category, unsigned int PriorUnifiedMap, unsigned int NewUnifiedMap, VISIBLE_UNIT_REC **ObjectPtrs)
{
  unsigned int v9; // edx@1
  int v10; // edi@2
  VISIBLE_UNIT_REC **v11; // esi@3
  VISIBLE_UNIT_PTR *v12; // ebp@6
  __int16 v13; // ax@7
  int v14; // ebx@8
  VISIBLE_UNIT_REC *v15; // eax@8
  VISIBLE_UNIT_REC *r; // ST20_4@8
  VISIBLE_UNIT_REC *v17; // eax@8
  signed int v18; // edx@8
  bool v19; // zf@8
  bool v20; // sf@8
  struct RGE_Static_Object *v21; // ecx@9
  int v22; // eax@13
  VISIBLE_UNIT_REC *v23; // ebx@13
  int v24; // eax@13
  VISIBLE_UNIT_REC *v25; // eax@14
  int v26; // edx@14
  struct RGE_Static_Object *v27; // edx@15
  int v28; // [sp+10h] [bp-10h]@3
  int i; // [sp+14h] [bp-Ch]@2
  Visible_Unit_Manager *v30; // [sp+1Ch] [bp-4h]@1
  unsigned int PriorUnifiedMapa; // [sp+38h] [bp+18h]@1

  v9 = (unsigned __int16)(PriorUnifiedMap ^ NewUnifiedMap);
  v30 = this;
  PriorUnifiedMapa = (unsigned __int16)(PriorUnifiedMap ^ NewUnifiedMap);
  if ( Category < this->Category_Count )
  {
    v10 = 0;
    i = 0;
    if ( this->Player_Count > 0 )
    {
      v11 = ObjectPtrs;
      v28 = 404 - (_DWORD)ObjectPtrs;
      do
      {
        if ( !v9 )
          break;
        if ( (v9 & 1) == 1 )
        {
          v12 = &this->PlayerDataPtrs[v10][Category];
          if ( (NewUnifiedMap & 1) == 1 )
          {
            v13 = v12->list_size;
            if ( v12->used == v13 )
            {
              v14 = v13;
              v15 = (VISIBLE_UNIT_REC *)calloc(2 * v13, 8u);
              qmemcpy(v15, v12->unit_list, 4 * ((unsigned int)(8 * v14) >> 2));
              r = v15;
              free(v12->unit_list);
              v17 = r;
              v18 = 0;
              v19 = v12->used == 0;
              v20 = v12->used < 0;
              v12->unit_list = r;
              v12->list_size = 2 * v14;
              if ( !v20 && !v19 )
              {
                do
                {
                  v21 = VIS_UNIT_objectsValue[v17->object_id];
                  if ( v21 )
                    *(VISIBLE_UNIT_REC **)((char *)ObjectPtrs + (_DWORD)v21 + v28) = v17;
                  ++v18;
                  ++v17;
                }
                while ( v18 < v12->used );
              }
              this = v30;
              v10 = i;
              v9 = PriorUnifiedMapa;
              v11 = ObjectPtrs;
            }
            v22 = v12->used;
            v23 = v12->unit_list;
            v23[v22].distance = 0;
            v24 = (int)&v23[v22].object_id;
            *(_DWORD *)v24 = Object_Id;
            *(_BYTE *)(v24 + 5) = player_id;
            *(_BYTE *)(v24 + 6) = Xpos;
            *(_BYTE *)(v24 + 7) = Ypos;
            ++v12->used;
            *v11 = (VISIBLE_UNIT_REC *)v24;
          }
          else
          {
            v25 = *v11;
            v26 = (int)&v12->unit_list[v12->used - 1].object_id;
            if ( (VISIBLE_UNIT_REC *)v26 != *v11 )
            {
              v25->object_id = *(_DWORD *)v26;
              *(_DWORD *)&v25->distance = *(_DWORD *)(v26 + 4);
              v27 = VIS_UNIT_objectsValue[v25->object_id];
              if ( v27 )
                *(VISIBLE_UNIT_REC **)((char *)v11 + (_DWORD)v27 + v28) = v25;
            }
            v9 = PriorUnifiedMapa;
            *v11 = 0;
            --v12->used;
          }
        }
        ++v11;
        v9 >>= 1;
        NewUnifiedMap >>= 1;
        ++v10;
        PriorUnifiedMapa = v9;
        i = v10;
        ObjectPtrs = v11;
      }
      while ( v10 < this->Player_Count );
    }
  }
}
// 87D7FC: using guessed type struct RGE_Static_Object **VIS_UNIT_objectsValue;

//----- (0053B9A0) --------------------------------------------------------
int __thiscall Visible_Unit_Manager::GetVisibleUnits(Visible_Unit_Manager *this, int Xpos, int Ypos, int LOS, int player, int *DesiredTypes, int DesiredCount, int *PlayerListMap)
{
  int v9; // esi@3
  int v10; // eax@5
  VISIBLE_UNIT_PTR *v11; // esi@7
  int v12; // eax@8
  int v13; // ebx@8
  int v14; // esi@8
  int v15; // eax@10
  char v16; // dl@13
  int v17; // edx@15
  int v18; // eax@15
  char v19; // cl@18
  int v20; // edx@20
  int v21; // eax@20
  char v22; // dl@21
  int v23; // eax@21
  int *v24; // ecx@21
  struct VISIBLE_UNIT_REC **v25; // edi@22
  struct VISIBLE_UNIT_REC *v26; // eax@22
  int count; // [sp+Ch] [bp-1Ch]@9
  VISIBLE_UNIT_PTR *PDP; // [sp+10h] [bp-18h]@7
  int x2; // [sp+14h] [bp-14h]@7
  int x1; // [sp+18h] [bp-10h]@7
  int y2; // [sp+1Ch] [bp-Ch]@7
  int y1; // [sp+20h] [bp-8h]@7
  int found; // [sp+24h] [bp-4h]@1
  char *distTbl; // [sp+3Ch] [bp+14h]@7

  found = 0;
  if ( DesiredCount <= 0 )
    return 0;
  v9 = player;
  if ( player >= this->Player_Count )
    return 0;
  v10 = LOS;
  if ( LOS > 15 )
  {
    v10 = 15;
    LOS = 15;
  }
  distTbl = this->distanceTable;
  v11 = this->PlayerDataPtrs[v9];
  VisibleUnitList_Size = 0;
  dword_87D7CC = 0;
  dword_87D7D0 = 0;
  dword_87D7D4 = 0;
  dword_87D7D8[0] = 0;
  x2 = v10 + Xpos;
  x1 = Xpos - v10;
  PDP = v11;
  y1 = Ypos - v10;
  y2 = Ypos + v10;
  do
  {
    v12 = *DesiredTypes;
    ++DesiredTypes;
    v13 = (int)&PDP[v12];
    v14 = *(_DWORD *)v13;
    if ( *(_DWORD *)(v13 + 6) & 0xFFFF )
    {
      count = *(_DWORD *)(v13 + 6) & 0xFFFF;
      do
      {
        v15 = *(_BYTE *)(v14 + 6);
        if ( v15 <= x2 )
        {
          if ( v15 >= Xpos )
          {
            v16 = v15 - Xpos;
          }
          else
          {
            if ( v15 < x1 )
              goto next_entry;
            v16 = Xpos - v15;
          }
          v17 = v16 & 0xF;
          v18 = *(_BYTE *)(v14 + 7);
          if ( v18 <= y2 )
          {
            if ( v18 >= Ypos )
            {
              v19 = v18 - Ypos;
do_dist:
              v20 = 16 * (v19 & 0xF) + v17;
              v21 = (unsigned __int8)distTbl[v20];
              if ( v21 <= LOS )
              {
                v22 = distTbl[v20];
                LOBYTE(v21) = *(_BYTE *)(v14 + 5);
                v23 = PlayerListMap[v21];
                v24 = (&VisibleUnitList_Size)[v23];
                if ( (signed int)v24 < 256 )
                {
                  v25 = &(&VisibleUnitList)[v23][2 * (_DWORD)v24];
                  (&VisibleUnitList_Size)[v23] = (int *)((char *)v24 + 1);
                  v26 = *(struct VISIBLE_UNIT_REC **)(v14 + 4);
                  LOBYTE(v26) = v22;
                  *v25 = *(struct VISIBLE_UNIT_REC **)v14;
                  v25[1] = v26;
                  ++found;
                }
              }
              goto next_entry;
            }
            if ( v18 >= y1 )
            {
              v19 = Ypos - v18;
              goto do_dist;
            }
          }
        }
next_entry:
        v14 += 8;
        --count;
      }
      while ( count );
    }
    --DesiredCount;
  }
  while ( DesiredCount );
  return found;
}
// 87D7C8: using guessed type int *VisibleUnitList_Size;
// 87D7CC: using guessed type int dword_87D7CC;
// 87D7D0: using guessed type int dword_87D7D0;
// 87D7D4: using guessed type int dword_87D7D4;
// 87D7D8: using guessed type int dword_87D7D8[];
// 87D7E0: using guessed type struct VISIBLE_UNIT_REC **VisibleUnitList;

//----- (0053BB30) --------------------------------------------------------
void __thiscall Visible_Resource_Manager::Visible_Resource_Manager(Visible_Resource_Manager *this, RGE_Player *list_owner, int num_lists)
{
  Visible_Resource_Manager *v3; // esi@1
  int *v4; // eax@2
  size_t v5; // ecx@2
  int v6; // edi@2

  v3 = this;
  this->num_visible_resource_lists = num_lists;
  if ( num_lists <= 0 )
  {
    this->VR_List = 0;
    this->VR_ListSize = 0;
    this->VR_ListUsed = 0;
    goto LABEL_6;
  }
  this->VR_List = (VISIBLE_RESOURCE_REC **)calloc(num_lists, 4u);
  v4 = (int *)calloc(v3->num_visible_resource_lists, 4u);
  v5 = v3->num_visible_resource_lists;
  v3->VR_ListSize = v4;
  v3->VR_ListUsed = (int *)calloc(v5, 4u);
  v6 = 0;
  if ( v3->num_visible_resource_lists <= 0 )
  {
LABEL_6:
    v3->owner = list_owner;
    return;
  }
  do
  {
    v3->VR_List[v6] = (VISIBLE_RESOURCE_REC *)malloc(0x100u);
    v3->VR_ListSize[v6] = 32;
    v3->VR_ListUsed[v6++] = 0;
  }
  while ( v6 < v3->num_visible_resource_lists );
  v3->owner = list_owner;
}

//----- (0053BBE0) --------------------------------------------------------
void __thiscall Visible_Resource_Manager::Visible_Resource_Manager(Visible_Resource_Manager *this, int infile, RGE_Player *list_owner)
{
  Visible_Resource_Manager *v3; // esi@1
  size_t *v4; // ebp@1
  int v5; // edi@2
  int v6; // ebx@4
  int *v7; // eax@5
  size_t v8; // ecx@5
  int v9; // edi@6
  VISIBLE_RESOURCE_REC *v10; // eax@6
  signed int v11; // ebx@8
  int v12; // eax@9

  v3 = this;
  v4 = (size_t *)&this->num_visible_resource_lists;
  if ( save_game_version < 7.1100001 )
  {
    v5 = infile;
    *v4 = 5;
  }
  else
  {
    v5 = infile;
    rge_read((int)v4, infile, infile, &this->num_visible_resource_lists, 4);
  }
  v6 = 0;
  if ( (signed int)*v4 <= 0 )
  {
    v3->VR_List = 0;
    v3->VR_ListSize = 0;
    v3->VR_ListUsed = 0;
LABEL_14:
    v3->owner = list_owner;
    return;
  }
  v3->VR_List = (VISIBLE_RESOURCE_REC **)calloc(*v4, 4u);
  v7 = (int *)calloc(*v4, 4u);
  v8 = *v4;
  v3->VR_ListSize = v7;
  v3->VR_ListUsed = (int *)calloc(v8, 4u);
  if ( (signed int)*v4 > 0 )
  {
    do
    {
      v9 = v6;
      rge_read((int)v4, 4 * v6, infile, &v3->VR_ListSize[v6], 4);
      rge_read((int)v4, v9 * 4, infile, &v3->VR_ListUsed[v9], 4);
      v10 = (VISIBLE_RESOURCE_REC *)malloc(8 * v3->VR_ListSize[v6++]);
      v3->VR_List[v9] = v10;
    }
    while ( v6 < (signed int)*v4 );
    v5 = infile;
  }
  v11 = 0;
  if ( (signed int)*v4 <= 0 )
    goto LABEL_14;
  do
  {
    v12 = v3->VR_ListUsed[v11];
    if ( v12 > 0 )
      rge_read((int)v4, v5, v5, v3->VR_List[v11], 8 * v12);
    ++v11;
  }
  while ( v11 < (signed int)*v4 );
  v3->owner = list_owner;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0053BD10) --------------------------------------------------------
void __thiscall Visible_Resource_Manager::~Visible_Resource_Manager(Visible_Resource_Manager *this)
{
  Visible_Resource_Manager *v1; // esi@1
  int i; // edi@1
  int *v3; // esi@9

  v1 = this;
  for ( i = 0; i < v1->num_visible_resource_lists; ++i )
  {
    if ( v1->VR_List[i] )
      free(v1->VR_List[i]);
  }
  if ( v1->VR_List )
    free(v1->VR_List);
  if ( v1->VR_ListSize )
    free(v1->VR_ListSize);
  v3 = v1->VR_ListUsed;
  if ( v3 )
    free(v3);
}

//----- (0053BD70) --------------------------------------------------------
void __thiscall Visible_Resource_Manager::save(Visible_Resource_Manager *this, int outfile)
{
  Visible_Resource_Manager *v2; // esi@1
  char *v3; // ebx@1
  int v4; // edi@1
  int i; // edi@3
  int v6; // eax@4

  v2 = this;
  v3 = (char *)&this->num_visible_resource_lists;
  rge_write(outfile, &this->num_visible_resource_lists, 4);
  v4 = 0;
  if ( *(_DWORD *)v3 > 0 )
  {
    do
    {
      rge_write(outfile, &v2->VR_ListSize[v4], 4);
      rge_write(outfile, &v2->VR_ListUsed[v4++], 4);
    }
    while ( v4 < v2->num_visible_resource_lists );
  }
  for ( i = 0; i < v2->num_visible_resource_lists; ++i )
  {
    v6 = v2->VR_ListUsed[i];
    if ( v6 > 0 )
      rge_write(outfile, v2->VR_List[i], 8 * v6);
  }
}

//----- (0053BE00) --------------------------------------------------------
void __thiscall Visible_Resource_Manager::Process_New_Tiles(Visible_Resource_Manager *this, RGE_Tile_List *tile_list)
{
  Visible_Resource_Manager *v2; // ebp@1
  int v3; // ebx@3
  RGE_Tile *v4; // edx@4
  int v5; // edi@4
  RGE_Object_Node *i; // esi@5
  RGE_Static_Object *v7; // eax@7
  RGE_Master_Static_Object *v8; // ecx@8
  int size; // [sp+8h] [bp-8h]@1
  RGE_Tile **TileOffsets; // [sp+Ch] [bp-4h]@3

  v2 = this;
  RGE_Tile_List::get_list_info(tile_list, (RGE_Tile_List_Node **)&tile_list, &size);
  if ( size > 0 )
  {
    if ( v2->num_visible_resource_lists )
    {
      v3 = 0;
      for ( TileOffsets = v2->owner->world->map->map_row_offset;
            v3 < size;
            tile_list = (RGE_Tile_List *)((char *)tile_list + 8) )
      {
        v4 = TileOffsets[tile_list->num_active];
        v5 = v4[tile_list->list_size].objects.number_of_objects;
        if ( v5 > 0 )
        {
          for ( i = v4[tile_list->list_size].objects.list; i; --v5 )
          {
            if ( v5 <= 0 )
              break;
            v7 = i->node;
            if ( i->node )
            {
              v8 = v7->master_obj;
              if ( v8->track_as_resource )
                Visible_Resource_Manager::AddResource(v2, v7->id, v8->resource_group);
            }
            i = i->next;
          }
        }
        ++v3;
      }
    }
  }
}

//----- (0053BED0) --------------------------------------------------------
void __thiscall Visible_Resource_Manager::AddResource(Visible_Resource_Manager *this, int Obj_Id, int ObjGroup)
{
  Visible_Resource_Manager *v3; // ebx@1
  struct RGE_Static_Object *v4; // edi@2
  int v5; // eax@3
  int v6; // ebp@3
  int n; // ST14_4@4
  int v8; // esi@5
  signed __int64 v9; // rax@5
  RGE_Static_Object *o; // [sp+Ch] [bp-4h]@2
  VISIBLE_RESOURCE_REC *ObjGroupa; // [sp+18h] [bp+8h]@4
  int ObjGroupb; // [sp+18h] [bp+8h]@5

  v3 = this;
  if ( this->num_visible_resource_lists )
  {
    v4 = VIS_UNIT_objectsValue[Obj_Id];
    o = VIS_UNIT_objectsValue[Obj_Id];
    if ( v4 )
    {
      v5 = this->VR_ListSize[ObjGroup];
      v6 = ObjGroup;
      if ( this->VR_ListUsed[ObjGroup] == v5 )
      {
        n = 2 * v5;
        ObjGroupa = (VISIBLE_RESOURCE_REC *)malloc(16 * v5);
        qmemcpy(ObjGroupa, v3->VR_List[v6], 8 * v3->VR_ListSize[v6]);
        free(v3->VR_List[v6]);
        v4 = o;
        v3->VR_List[v6] = ObjGroupa;
        v3->VR_ListSize[v6] = n;
      }
      v8 = (int)&v3->VR_List[v6][v3->VR_ListUsed[v6]].object_id;
      ObjGroupb = (signed __int64)v4->world_x;
      v9 = (signed __int64)v4->world_y;
      *(_DWORD *)v8 = Obj_Id;
      *(_BYTE *)(v8 + 4) = 0;
      *(_BYTE *)(v8 + 5) = 0;
      *(_BYTE *)(v8 + 6) = ObjGroupb;
      *(_BYTE *)(v8 + 7) = v9;
      ++v3->VR_ListUsed[v6];
    }
  }
}
// 87D7FC: using guessed type struct RGE_Static_Object **VIS_UNIT_objectsValue;

//----- (0053BFD0) --------------------------------------------------------
int __thiscall Visible_Resource_Manager::Remove_Resource(Visible_Resource_Manager *this, int Obj_Id, int ObjGroup)
{
  int v3; // edx@2
  int v4; // ebx@2
  int v5; // edx@3
  VISIBLE_RESOURCE_REC *v6; // edi@3
  int v7; // eax@3
  VISIBLE_RESOURCE_REC *v8; // esi@4
  int result; // eax@7

  if ( this->num_visible_resource_lists
    && (v3 = this->VR_ListUsed[ObjGroup], v4 = ObjGroup, v3)
    && (v5 = v3 - 1, v6 = this->VR_List[v4], v7 = 0, v5 >= 0) )
  {
    v8 = this->VR_List[v4];
    while ( v8->object_id != Obj_Id )
    {
      ++v7;
      ++v8;
      if ( v7 > v5 )
        return 0;
    }
    if ( v7 < v5 )
    {
      v6[v7].object_id = v6[v5].object_id;
      *(_DWORD *)&v6[v7].distance = *(_DWORD *)&v6[v5].distance;
    }
    --this->VR_ListUsed[v4];
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053C050) --------------------------------------------------------
VISIBLE_RESOURCE_REC *__thiscall Visible_Resource_Manager::Get_Closest_Resource(Visible_Resource_Manager *this, int Xpos, int Ypos, int Zone, int ResType, int *excList, int elSize)
{
  Visible_Resource_Manager *v7; // esi@1
  int v8; // ecx@2
  int v9; // eax@4
  VISIBLE_RESOURCE_REC *v10; // ecx@5
  VISIBLE_RESOURCE_REC *v11; // ebp@5
  int v12; // eax@7
  int v13; // ecx@7
  int v14; // edi@8
  int v15; // esi@11
  int v16; // esi@14
  int *v17; // eax@18
  int v18; // ecx@19
  VISIBLE_RESOURCE_REC *result; // eax@32
  int Reject; // [sp+14h] [bp-Ch]@7
  int v21; // [sp+18h] [bp-8h]@6
  VISIBLE_RESOURCE_REC *c; // [sp+1Ch] [bp-4h]@5
  int ResTypea; // [sp+30h] [bp+10h]@5

  v7 = this;
  if ( ResType >= 0
    && (v8 = this->num_visible_resource_lists) != 0
    && ResType < v8
    && (v9 = v7->VR_ListUsed[ResType]) != 0 )
  {
    v10 = 0;
    v11 = v7->VR_List[ResType];
    ResTypea = 9999;
    c = 0;
    if ( v9 > 0 )
    {
      v21 = v9;
      do
      {
        v12 = v11->pos_x;
        v13 = v11->pos_y;
        Reject = 0;
        if ( v12 <= Xpos )
          v14 = Xpos - v12;
        else
          v14 = v12 - Xpos;
        if ( v13 <= Ypos )
          v15 = Ypos - v13;
        else
          v15 = v13 - Ypos;
        if ( v14 <= v15 )
          v16 = v15 - (unsigned __int64)(signed __int64)(-0.61 - (double)v14 * 1.4) - v14;
        else
          v16 = v14 - (unsigned __int64)(signed __int64)(-0.61 - (double)v15 * 1.4) - v15;
        if ( v16 < ResTypea )
        {
          if ( elSize )
          {
            v17 = excList;
            if ( excList )
            {
              v18 = 0;
              if ( elSize > 0 )
              {
                while ( v11->object_id != *v17 )
                {
                  ++v18;
                  ++v17;
                  if ( v18 >= elSize )
                    goto LABEL_24;
                }
                Reject = 1;
              }
            }
          }
LABEL_24:
          if ( !Reject )
          {
            c = v11;
            ResTypea = v16;
          }
        }
        ++v11;
        --v21;
      }
      while ( v21 );
      v10 = c;
    }
    if ( ResTypea > 255 )
      ResTypea = 255;
    if ( v10 )
      v10->distance = ResTypea;
    result = v10;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053C1B0) --------------------------------------------------------
void __thiscall RGE_Visible_Map::RGE_Visible_Map(RGE_Visible_Map *this, RGE_Map *in_map, RGE_Player *in_player)
{
  RGE_Visible_Map *v3; // esi@1
  int v4; // ecx@1
  int v5; // edx@1
  char **v6; // eax@3
  int v7; // ecx@3
  int v8; // eax@3
  char v9; // cl@7
  unsigned int v10; // eax@7

  v3 = this;
  this->world = in_player->world;
  this->player = in_player;
  this->map = in_map;
  v4 = in_map->map_width;
  v3->widthValue = v4;
  v5 = in_map->map_height;
  v3->heightValue = v5;
  v3->numberTilesExploredValue = 0;
  v3->numberTotalTilesValue = v4 * v5;
  if ( v4 <= 0 || v5 <= 0 )
  {
    v3->visible_map = 0;
    v3->map_offsets = 0;
  }
  else
  {
    v3->visible_map = (char *)calloc(v4 * v5, 1u);
    v6 = (char **)calloc(v3->heightValue, 4u);
    v7 = v3->heightValue;
    v3->map_offsets = v6;
    v8 = 0;
    if ( v7 > 0 )
    {
      do
      {
        v3->map_offsets[v8] = &v3->visible_map[v3->widthValue * v8];
        ++v8;
      }
      while ( v8 < v3->heightValue );
    }
    memset(v3->visible_map, 0xFFu, v3->widthValue * v3->heightValue);
  }
  v9 = in_player->id;
  v3->input_csum = 0;
  v3->PlayerVisibleMaskValue = 1 << v9;
  v3->PlayerVisibleMaskInvertValue = ~(1 << v9);
  v10 = v3->PlayerVisibleMaskValue << 16;
  v3->PlayerExploredMaskValue = v10;
  v3->PlayerExploredMaskInvertValue = ~v10;
}

//----- (0053C290) --------------------------------------------------------
void __userpurge RGE_Visible_Map::RGE_Visible_Map(RGE_Visible_Map *this@<ecx>, int a2@<edi>, int infile, RGE_Game_World *theWorld)
{
  RGE_Visible_Map *v4; // esi@1
  int *v5; // ebx@1
  size_t *v6; // edi@1
  int v7; // ebp@3
  size_t v8; // eax@3
  char **v9; // eax@5
  signed int v10; // ecx@5
  signed int v11; // eax@5
  signed int v12; // eax@9
  signed int v13; // ecx@9
  __int16 player_id; // [sp+10h] [bp-4h]@3

  v4 = this;
  v5 = &this->widthValue;
  this->world = theWorld;
  this->map = theWorld->map;
  this->numberTilesExploredValue = 0;
  rge_read(infile, a2, infile, &this->widthValue, 4);
  v6 = (size_t *)&v4->heightValue;
  rge_read(infile, (int)&v4->heightValue, infile, &v4->heightValue, 4);
  if ( save_game_version >= 6.6999998 )
    rge_read(infile, (int)v6, infile, &v4->numberTilesExploredValue, 4);
  rge_read(infile, (int)v6, infile, &player_id, 2);
  v7 = *v5;
  v8 = *v5 * *v6;
  v4->numberTotalTilesValue = v8;
  v4->player = theWorld->players[player_id];
  if ( v7 <= 0 || (signed int)*v6 <= 0 )
  {
    v4->visible_map = 0;
    v4->map_offsets = 0;
  }
  else
  {
    v4->visible_map = (char *)calloc(v8, 1u);
    v9 = (char **)calloc(*v6, 4u);
    v10 = *v6;
    v4->map_offsets = v9;
    v11 = 0;
    if ( v10 > 0 )
    {
      do
      {
        v7 = (int)v4->visible_map;
        v4->map_offsets[v11] = (char *)(v7 + *v5 * v11);
        ++v11;
      }
      while ( v11 < (signed int)*v6 );
    }
    rge_read(v7, (int)v6, infile, v4->visible_map, *v6 * *v5);
  }
  v12 = 1 << player_id;
  v4->input_csum = 0;
  v4->PlayerVisibleMaskValue = v12;
  v13 = v12;
  v12 <<= 16;
  v4->PlayerExploredMaskValue = v12;
  v4->PlayerExploredMaskInvertValue = ~v12;
  v4->PlayerVisibleMaskInvertValue = ~v13;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0053C3C0) --------------------------------------------------------
void __thiscall RGE_Visible_Map::~RGE_Visible_Map(RGE_Visible_Map *this)
{
  RGE_Visible_Map *v1; // esi@1

  v1 = this;
  if ( this->visible_map )
  {
    free(this->visible_map);
    v1->visible_map = 0;
  }
  if ( v1->map_offsets )
  {
    free(v1->map_offsets);
    v1->map_offsets = 0;
  }
  v1->player = 0;
  v1->map = 0;
}

//----- (0053C400) --------------------------------------------------------
void __thiscall RGE_Visible_Map::save(RGE_Visible_Map *this, int outfile)
{
  RGE_Visible_Map *v2; // esi@1
  char *v3; // ebx@1
  int *v4; // ebp@1
  int v5; // ebx@3

  v2 = this;
  v3 = (char *)&this->widthValue;
  rge_write(outfile, &this->widthValue, 4);
  v4 = &v2->heightValue;
  rge_write(outfile, &v2->heightValue, 4);
  if ( save_game_version >= 6.6999998 )
    rge_write(outfile, &v2->numberTilesExploredValue, 4);
  rge_write(outfile, &v2->player->id, 2);
  v5 = *(_DWORD *)v3;
  if ( v5 > 0 && *v4 > 0 )
    rge_write(outfile, v2->visible_map, v5 * *v4);
}
// 58EBCC: using guessed type float save_game_version;

//----- (0053C490) --------------------------------------------------------
char __thiscall RGE_Visible_Map::get_visible(RGE_Visible_Map *this, int map_col, int map_row)
{
  RGE_Player *v3; // ecx@1
  unsigned __int32 *v4; // eax@1
  char result; // al@2

  v3 = this->player;
  v4 = (&unified_map_offsets)[map_row][map_col];
  if ( v3->mutualVisibleMask & (unsigned int)v4 )
    result = 15;
  else
    result = ((unsigned int)v4 & v3->mutualExploredMask) != 0 ? 0x80 : 0;
  return result;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053C4D0) --------------------------------------------------------
void __thiscall RGE_Visible_Map::set_all(RGE_Visible_Map *this, char vis_flag)
{
  RGE_Visible_Map *v2; // esi@1
  int i; // ecx@1
  int j; // eax@2
  int v5; // edi@7
  int v6; // ebp@7
  unsigned __int32 ***v7; // edx@8
  int k; // eax@9
  unsigned int v9; // edi@13
  int v10; // ebp@15
  unsigned __int32 ***v11; // edx@16
  int l; // eax@17

  v2 = this;
  log_map_call(this->world->world_time, this->player->id, 5, 0, (unsigned __int8)vis_flag, 0, 0, 0, 0);
  for ( i = 0; i < v2->heightValue; ++i )
  {
    for ( j = 0; j < v2->widthValue; v2->map_offsets[i][j - 1] = vis_flag )
      ++j;
  }
  if ( vis_flag != -1 && vis_flag )
  {
    v5 = v2->PlayerVisibleMaskValue | v2->PlayerExploredMaskValue;
    v6 = 0;
    if ( v2->heightValue > 0 )
    {
      v7 = &unified_map_offsets;
      do
      {
        for ( k = 0; k < v2->widthValue; ++k )
          (*v7)[k] = (unsigned __int32 *)(v5 | (unsigned int)(*v7)[k]);
        ++v6;
        ++v7;
      }
      while ( v6 < v2->heightValue );
    }
  }
  else
  {
    v9 = v2->PlayerVisibleMaskInvertValue;
    if ( vis_flag == -1 )
      v9 &= v2->PlayerExploredMaskInvertValue;
    v10 = 0;
    if ( v2->heightValue > 0 )
    {
      v11 = &unified_map_offsets;
      do
      {
        for ( l = 0; l < v2->widthValue; ++l )
          (*v11)[l] = (unsigned __int32 *)(v9 & (unsigned int)(*v11)[l]);
        ++v10;
        ++v11;
      }
      while ( v10 < v2->heightValue );
    }
  }
  if ( vis_flag == -1 )
    v2->numberTilesExploredValue = 0;
  else
    v2->numberTilesExploredValue = v2->numberTotalTilesValue;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053C5D0) --------------------------------------------------------
void __thiscall RGE_Visible_Map::explore_all(RGE_Visible_Map *this)
{
  RGE_Visible_Map *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@2
  int i; // edi@3
  char *v5; // edx@4

  v1 = this;
  log_map_call(this->world->world_time, this->player->id, 6, 0, 0, 0, 0, 0, 0);
  v2 = 0;
  if ( v1->heightValue > 0 )
  {
    v3 = 0;
    do
    {
      for ( i = 0; i < v1->widthValue; ++i )
      {
        v5 = v1->map_offsets[v3];
        if ( v5[i] == -1 )
        {
          v5[i] = 0;
          ++v1->numberTilesExploredValue;
          (&unified_map_offsets)[v3][i] = (unsigned __int32 *)(v1->PlayerExploredMaskValue | (unsigned int)(&unified_map_offsets)[v3][i]);
          RGE_Tile_List::add_node(&v1->player->tile_list, i, v2);
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->heightValue );
  }
  v1->player->tile_list.collapse_list = 1;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053C670) --------------------------------------------------------
double __thiscall RGE_Visible_Map::percentExplored(RGE_Visible_Map *this)
{
  return (double)this->numberTilesExploredValue / (double)this->numberTotalTilesValue;
}

//----- (0053C680) --------------------------------------------------------
void __thiscall RGE_Visible_Map::recomputeExplored(RGE_Visible_Map *this)
{
  int v1; // ebx@1
  int v2; // edi@1
  int v3; // esi@2
  int v4; // eax@3
  char **v5; // edx@4

  v1 = this->heightValue;
  v2 = 0;
  this->numberTilesExploredValue = 0;
  if ( v1 > 0 )
  {
    v3 = this->widthValue;
    do
    {
      v4 = 0;
      if ( v3 > 0 )
      {
        v5 = &this->map_offsets[v2];
        do
        {
          if ( (*v5)[v4] != -1 )
            ++this->numberTilesExploredValue;
          ++v4;
        }
        while ( v4 < v3 );
      }
      ++v2;
    }
    while ( v2 < v1 );
  }
}

//----- (0053C6C0) --------------------------------------------------------
struct LOSTBL **__stdcall RGE_Visible_Map::get_los_table(int radius, int Square)
{
  int v3; // eax@1
  struct LOSTBL **result; // eax@6

  v3 = radius;
  if ( radius > 16 )
    v3 = 16;
  if ( v3 < 0 )
    v3 = 0;
  if ( Square )
    result = (&SquareLOS)[v3];
  else
    result = (&NormalLOS)[v3];
  return result;
}
// 58EA10: using guessed type struct LOSTBL **NormalLOS;
// 58EA58: using guessed type struct LOSTBL **SquareLOS;

//----- (0053C6F0) --------------------------------------------------------
int __thiscall RGE_Visible_Map::explore_terrain(RGE_Visible_Map *this, int tx, int ty, int radius, int Square, int UpdateMap, int id)
{
  int v7; // ebx@1
  int v8; // esi@1
  RGE_Visible_Map *v9; // edi@1
  int result; // eax@2
  int v11; // eax@3
  int v12; // eax@3
  int v13; // eax@3
  int v14; // eax@3
  int v15; // eax@3
  RGE_Player *v16; // eax@3
  struct LOSTBL **v17; // ecx@11
  struct LOSTBL *i; // eax@13
  int v19; // edx@14
  int v20; // esi@16
  struct LOSTBL *v21; // eax@18
  int v22; // ecx@18
  char *v23; // ebx@20
  unsigned __int32 **v24; // ecx@20
  char v25; // al@23
  RGE_Tile_List *v26; // ecx@24
  RGE_Player *curVisPlayer; // [sp+Ch] [bp-14h]@6
  int y; // [sp+10h] [bp-10h]@14
  int Revealed; // [sp+14h] [bp-Ch]@1
  int x2; // [sp+18h] [bp-8h]@18
  int VisibleToCurPlayer; // [sp+1Ch] [bp-4h]@4
  RGE_Tile *tile; // [sp+30h] [bp+10h]@6
  unsigned int *u; // [sp+34h] [bp+14h]@20
  struct LOSTBL **Tbl; // [sp+3Ch] [bp+1Ch]@11

  v7 = tx;
  v8 = radius;
  v9 = this;
  Revealed = 0;
  log_map_call(this->world->world_time, this->player->id, 1, id, tx, ty, radius, Square, Map_Update_Suppresion);
  if ( Map_Update_Suppresion )
  {
    result = 0;
  }
  else
  {
    v11 = __ROL4__(v9->input_csum, 3);
    v12 = __ROL4__(v11 ^ 0x1010101, 2);
    v13 = __ROL4__(v9->player->id ^ v12, 3);
    v14 = __ROL4__(tx ^ v13, 4);
    v15 = __ROL4__(ty ^ v14, 3);
    v9->input_csum = Square + (radius ^ v15);
    v16 = v9->world->players[v9->world->curr_player];
    if ( v16 )
      VisibleToCurPlayer = v16->mutualAlly[v9->player->id] == 1;
    else
      VisibleToCurPlayer = 0;
    tile = 0;
    curVisPlayer = 0;
    if ( VisibleToCurPlayer )
      curVisPlayer = v9->world->players[v9->world->curr_player];
    if ( v8 > 16 )
      v8 = 16;
    if ( Square )
    {
      v17 = (&SquareLOS)[v8];
      Tbl = (&SquareLOS)[v8];
    }
    else
    {
      Tbl = (&NormalLOS)[v8];
      v17 = (&NormalLOS)[v8];
    }
    for ( i = *v17; i != (struct LOSTBL *)999; Tbl = v17 )
    {
      v19 = (int)&i->y_delta + ty;
      y = (int)&i->y_delta + ty;
      if ( (signed int)i + ty >= 0 && v19 < v9->heightValue )
      {
        v20 = (int)&v17[1]->y_delta + v7;
        if ( v20 < 0 )
          v20 = 0;
        v21 = v17[2];
        v22 = v9->widthValue;
        x2 = (int)&v21->y_delta + v7;
        if ( (signed int)v21 + v7 >= v22 )
          x2 = v22 - 1;
        v23 = &v9->map_offsets[v19][v20];
        v24 = &(&unified_map_offsets)[v19][v20];
        u = (unsigned int *)&(&unified_map_offsets)[v19][v20];
        if ( UpdateMap )
          tile = &v9->map->map_row_offset[v19][v20];
        for ( ; v20 <= x2; ++tile )
        {
          v25 = *v23 + 1;
          if ( *v23 == -1 )
          {
            ++Revealed;
            v26 = &v9->player->tile_list;
            ++v9->numberTilesExploredValue;
            RGE_Tile_List::add_node(v26, v20, y);
            if ( VisibleToCurPlayer )
              RGE_Tile_List::add_node(&curVisPlayer->diam_tile_list, v20, y);
            v24 = (unsigned __int32 **)u;
            v25 = 1;
            *v24 = (unsigned __int32 *)(v9->PlayerExploredMaskValue | (unsigned int)*v24);
          }
          if ( v25 == 1 )
          {
            if ( UpdateMap )
              tile->draw_as = 15;
            *v24 = (unsigned __int32 *)(v9->PlayerVisibleMaskValue | (unsigned int)*v24);
          }
          if ( v25 == -6 )
            v25 = -7;
          *v23++ = v25;
          ++v24;
          ++v20;
          u = (unsigned int *)v24;
        }
        v7 = tx;
        v17 = Tbl;
      }
      i = v17[3];
      v17 += 3;
    }
    result = Revealed;
  }
  return result;
}
// 58EA10: using guessed type struct LOSTBL **NormalLOS;
// 58EA58: using guessed type struct LOSTBL **SquareLOS;
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053C920) --------------------------------------------------------
void __thiscall RGE_Visible_Map::unexplore_terrain(RGE_Visible_Map *this, int tx, int ty, int radius, int Square, int UpdateMap, int id)
{
  RGE_Visible_Map *v7; // ebx@1
  int v8; // esi@1
  int v9; // edi@1
  int v10; // eax@2
  int v11; // eax@2
  int v12; // eax@2
  int v13; // eax@2
  int v14; // eax@2
  struct LOSTBL **v15; // edx@5
  struct LOSTBL *i; // eax@7
  int v17; // eax@8
  int v18; // ecx@10
  int v19; // esi@12
  int v20; // edx@12
  int v21; // esi@14
  char *v22; // eax@14
  unsigned __int32 **v23; // edi@14
  int v24; // esi@15
  int v25; // edx@17
  char v26; // cl@18
  RGE_Visible_Map *v27; // [sp+Ch] [bp-Ch]@1
  RGE_Tile *tile; // [sp+14h] [bp-4h]@1
  struct LOSTBL **Tbl; // [sp+2Ch] [bp+14h]@5

  v7 = this;
  v8 = radius;
  v9 = tx;
  v27 = this;
  tile = 0;
  log_map_call(this->world->world_time, this->player->id, 3, id, tx, ty, radius, Square, Map_Update_Suppresion);
  if ( !Map_Update_Suppresion )
  {
    v10 = __ROL4__(v7->input_csum, 3);
    v11 = __ROL4__(v10 ^ 0x20202020, 2);
    v12 = __ROL4__(v7->player->id ^ v11, 3);
    v13 = __ROL4__(tx ^ v12, 4);
    v14 = __ROL4__(ty ^ v13, 3);
    v7->input_csum = Square + (radius ^ v14);
    if ( radius > 16 )
      v8 = 16;
    if ( Square )
    {
      v15 = (&SquareLOS)[v8];
      Tbl = (&SquareLOS)[v8];
    }
    else
    {
      Tbl = (&NormalLOS)[v8];
      v15 = (&NormalLOS)[v8];
    }
    for ( i = *v15; i != (struct LOSTBL *)999; Tbl = v15 )
    {
      v17 = (int)&i->y_delta + ty;
      if ( v17 >= 0 && v17 < v7->heightValue )
      {
        v18 = (int)&v15[1]->y_delta + v9;
        if ( v18 < 0 )
          v18 = 0;
        v19 = v7->widthValue;
        v20 = (int)&v15[2]->y_delta + v9;
        if ( v20 >= v19 )
          v20 = v19 - 1;
        v21 = v17;
        v22 = &v7->map_offsets[v17][v18];
        v23 = &(&unified_map_offsets)[v21][v18];
        if ( UpdateMap )
        {
          v23 = &(&unified_map_offsets)[v21][v18];
          v24 = (int)&v7->map->map_row_offset[v21][v18].screen_xpos;
          v7 = v27;
          tile = (RGE_Tile *)v24;
        }
        if ( v18 <= v20 )
        {
          v25 = v20 - v18 + 1;
          do
          {
            v26 = *v22 - 1;
            if ( !*v22 )
              v26 = 0;
            if ( !v26 )
            {
              if ( UpdateMap )
                tile->draw_as = -128;
              *v23 = (unsigned __int32 *)(v7->PlayerVisibleMaskInvertValue & (unsigned int)*v23);
            }
            *v22++ = v26;
            ++v23;
            --v25;
            ++tile;
          }
          while ( v25 );
        }
        v15 = Tbl;
        v9 = tx;
      }
      i = v15[3];
      v15 += 3;
    }
  }
}
// 58EA10: using guessed type struct LOSTBL **NormalLOS;
// 58EA58: using guessed type struct LOSTBL **SquareLOS;
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053CAC0) --------------------------------------------------------
int __thiscall RGE_Visible_Map::explore_terrain_sq(RGE_Visible_Map *this, int tx1, int ty1, int tx2, int ty2, int UpdateMap, int id)
{
  int v7; // ebx@1
  RGE_Visible_Map *v8; // esi@1
  int v9; // edi@1
  int v10; // eax@2
  int v11; // eax@2
  int v12; // eax@2
  int v13; // eax@2
  int v14; // eax@2
  int v15; // eax@4
  int v16; // ecx@6
  int v17; // eax@16
  unsigned int v18; // eax@19
  unsigned __int32 **v19; // edi@19
  char *v20; // ecx@19
  char v21; // al@22
  RGE_Tile_List *v22; // ecx@23
  int result; // eax@34
  int isCurPlayer; // [sp+Ch] [bp-14h]@2
  int v25; // [sp+10h] [bp-10h]@17
  RGE_Player *curVisPlayer; // [sp+14h] [bp-Ch]@2
  int Revealed; // [sp+18h] [bp-8h]@1
  char *p; // [sp+1Ch] [bp-4h]@19
  int y; // [sp+2Ch] [bp+Ch]@16
  RGE_Tile *tile; // [sp+3Ch] [bp+1Ch]@2

  v7 = tx1;
  v8 = this;
  v9 = ty1;
  Revealed = 0;
  log_map_call(this->world->world_time, this->player->id, 2, id, tx1, ty1, tx2, ty2, Map_Update_Suppresion);
  if ( Map_Update_Suppresion )
    goto LABEL_38;
  isCurPlayer = v8->world->players[v8->world->curr_player]->mutualAlly[v8->player->id] == 1;
  tile = 0;
  curVisPlayer = 0;
  v10 = __ROL4__(v8->input_csum, 3);
  v11 = __ROL4__(v10 ^ 0x34343434, 2);
  v12 = __ROL4__(tx1 ^ v11, 4);
  v13 = __ROL4__(ty1 ^ v12, 3);
  v14 = __ROL4__(tx2 ^ v13, 3);
  v8->input_csum = ty2 ^ v14;
  if ( isCurPlayer )
    curVisPlayer = v8->world->players[v8->world->curr_player];
  v15 = v8->widthValue;
  if ( tx1 >= v15 || tx2 < 0 || (v16 = v8->heightValue, ty1 >= v16) || ty2 < 0 )
  {
LABEL_38:
    result = 0;
  }
  else
  {
    if ( tx1 < 0 )
    {
      tx1 = 0;
      v7 = 0;
    }
    if ( tx2 >= v15 )
      tx2 = v15 - 1;
    if ( ty1 < 0 )
      v9 = 0;
    if ( ty2 >= v16 )
      ty2 = v16 - 1;
    v17 = v9;
    y = v9;
    if ( v9 <= ty2 )
    {
      v25 = v7;
      while ( 1 )
      {
        v18 = v17;
        v19 = &(&unified_map_offsets)[v18][v25];
        v20 = &v8->map_offsets[v18][v7];
        p = &v8->map_offsets[v18][v7];
        if ( UpdateMap )
        {
          v20 = &v8->map_offsets[v18][v7];
          tile = &v8->map->map_row_offset[v18][tx1];
        }
        if ( tx1 <= tx2 )
        {
          do
          {
            v21 = *v20 + 1;
            if ( *v20 == -1 )
            {
              ++Revealed;
              v22 = &v8->player->tile_list;
              ++v8->numberTilesExploredValue;
              RGE_Tile_List::add_node(v22, v7, y);
              if ( isCurPlayer )
                RGE_Tile_List::add_node(&curVisPlayer->diam_tile_list, v7, y);
              v21 = 1;
              *v19 = (unsigned __int32 *)(v8->PlayerExploredMaskValue | (unsigned int)*v19);
              v20 = p;
            }
            if ( v21 == 1 )
            {
              if ( UpdateMap )
                tile->draw_as = 15;
              *v19 = (unsigned __int32 *)(v8->PlayerVisibleMaskValue | (unsigned int)*v19);
            }
            if ( v21 == -6 )
              v21 = -7;
            *v20++ = v21;
            ++v19;
            ++v7;
            p = v20;
            ++tile;
          }
          while ( v7 <= tx2 );
        }
        v17 = y++ + 1;
        if ( y > ty2 )
          break;
        v7 = tx1;
      }
    }
    result = Revealed;
  }
  return result;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053CCF0) --------------------------------------------------------
void __thiscall RGE_Visible_Map::unexplore_terrain_sq(RGE_Visible_Map *this, int tx1, int ty1, int tx2, int ty2, int UpdateMap, int id)
{
  RGE_Visible_Map *v7; // ebx@1
  int v8; // esi@1
  int v9; // edi@1
  int v10; // eax@2
  int v11; // eax@2
  int v12; // eax@2
  int v13; // eax@2
  int v14; // eax@2
  int v15; // eax@2
  int v16; // ecx@4
  char *v17; // eax@15
  unsigned __int32 **v18; // edx@15
  int v19; // ecx@16
  int v20; // esi@18
  char v21; // cl@19
  RGE_Visible_Map *v22; // [sp+Ch] [bp-8h]@1
  RGE_Tile *tile; // [sp+10h] [bp-4h]@1
  int y; // [sp+20h] [bp+Ch]@14

  v7 = this;
  v8 = ty1;
  v9 = tx1;
  v22 = this;
  tile = 0;
  log_map_call(this->world->world_time, this->player->id, 4, id, tx1, ty1, tx2, ty2, Map_Update_Suppresion);
  if ( !Map_Update_Suppresion )
  {
    v10 = __ROL4__(v7->input_csum, 3);
    v11 = __ROL4__(v10 ^ 0x56565656, 2);
    v12 = __ROL4__(tx1 ^ v11, 4);
    v13 = __ROL4__(ty1 ^ v12, 3);
    v14 = __ROL4__(tx2 ^ v13, 3);
    v7->input_csum = ty2 ^ v14;
    v15 = v7->widthValue;
    if ( tx1 < v15 && tx2 >= 0 )
    {
      v16 = v7->heightValue;
      if ( ty1 < v16 && ty2 >= 0 )
      {
        if ( tx1 < 0 )
          v9 = 0;
        if ( tx2 >= v15 )
          tx2 = v15 - 1;
        if ( ty1 < 0 )
          v8 = 0;
        if ( ty2 >= v16 )
          ty2 = v16 - 1;
        for ( y = v8; y <= ty2; ++y )
        {
          v17 = &v7->map_offsets[y][v9];
          v18 = &(&unified_map_offsets)[y][v9];
          if ( UpdateMap )
          {
            v19 = (int)&v7->map->map_row_offset[y][v9].screen_xpos;
            v7 = v22;
            tile = (RGE_Tile *)v19;
          }
          if ( v9 <= tx2 )
          {
            v20 = tx2 - v9 + 1;
            do
            {
              v21 = *v17 - 1;
              if ( !*v17 )
                v21 = 0;
              if ( !v21 )
              {
                if ( UpdateMap )
                  tile->draw_as = -128;
                *v18 = (unsigned __int32 *)(v22->PlayerVisibleMaskInvertValue & (unsigned int)*v18);
                v7 = v22;
              }
              *v17++ = v21;
              ++v18;
              --v20;
              ++tile;
            }
            while ( v20 );
          }
        }
      }
    }
  }
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053CE70) --------------------------------------------------------
unsigned int __thiscall RGE_Visible_Map::checksum_visible_inputs(RGE_Visible_Map *this)
{
  unsigned int result; // eax@1

  result = this->input_csum;
  this->input_csum = 0;
  return result;
}

//----- (0053CE80) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(RGE_Unified_Visible_Map *this, int width, int height)
{
  RGE_Unified_Visible_Map *v3; // esi@1
  int v4; // ecx@1

  v3 = this;
  this->mapWidth = width;
  this->mapHeight = height;
  Map_Update_Suppresion = 0;
  v4 = this->mapHeight;
  if ( v4 <= 0 || v3->mapWidth <= 0 )
  {
    v3->UnifiedVisibleMap = 0;
    v3->mapWidth = 0;
    v3->mapHeight = 0;
    RGE_Unified_Visible_Map::Set_Map_Offsets(v3);
  }
  else
  {
    v3->UnifiedVisibleMap = (unsigned int *)calloc(v4 * v3->mapWidth, 4u);
    RGE_Unified_Visible_Map::Set_Map_Offsets(v3);
  }
}

//----- (0053CEE0) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(RGE_Unified_Visible_Map *this, int infile, RGE_Game_World *world)
{
  RGE_Unified_Visible_Map *v3; // esi@1

  v3 = this;
  this->UnifiedVisibleMap = 0;
  this->mapWidth = 0;
  this->mapHeight = 0;
  Map_Update_Suppresion = 0;
  RGE_Unified_Visible_Map::load(this, infile);
  RGE_Unified_Visible_Map::Set_Map_Offsets(v3);
}

//----- (0053CF10) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::load(RGE_Unified_Visible_Map *this, int infile)
{
  RGE_Unified_Visible_Map *v2; // esi@1
  int v3; // ebp@1
  char *v4; // edi@1
  int oh; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = this->mapWidth;
  v4 = (char *)&this->mapHeight;
  oh = this->mapHeight;
  rge_read(this->mapWidth, (int)&this->mapHeight, infile, this, 4);
  rge_read(v3, (int)v4, infile, v4, 4);
  if ( *(_DWORD *)v4 <= 0 || v2->mapWidth <= 0 )
  {
    *(_DWORD *)v4 = 0;
    v2->UnifiedVisibleMap = 0;
    v2->mapWidth = 0;
  }
  else
  {
    if ( v3 != v2->mapWidth || oh != *(_DWORD *)v4 )
    {
      if ( v2->UnifiedVisibleMap )
        free(v2->UnifiedVisibleMap);
      v2->UnifiedVisibleMap = (unsigned int *)calloc(*(_DWORD *)v4 * v2->mapWidth, 4u);
    }
    rge_read(v3, (int)v4, infile, v2->UnifiedVisibleMap, 4 * *(_DWORD *)v4 * v2->mapWidth);
  }
}

//----- (0053CFC0) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(RGE_Unified_Visible_Map *this)
{
  RGE_Unified_Visible_Map *v1; // esi@1
  unsigned int *v2; // esi@1

  v1 = this;
  this->mapHeight = 0;
  RGE_Unified_Visible_Map::Set_Map_Offsets(this);
  v2 = v1->UnifiedVisibleMap;
  if ( v2 )
    free(v2);
}

//----- (0053CFF0) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::save(RGE_Unified_Visible_Map *this, int outfile)
{
  RGE_Unified_Visible_Map *v2; // esi@1
  int v3; // edi@1

  v2 = this;
  rge_write(outfile, this, 4);
  rge_write(outfile, &v2->mapHeight, 4);
  v3 = v2->mapHeight;
  if ( v3 > 0 && v2->mapWidth > 0 )
    rge_write(outfile, v2->UnifiedVisibleMap, 4 * v3 * v2->mapWidth);
}

//----- (0053D040) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::reset(RGE_Unified_Visible_Map *this)
{
  unsigned int *v1; // edi@1

  v1 = this->UnifiedVisibleMap;
  if ( v1 )
    memset(v1, 0, 4 * this->mapWidth * this->mapHeight);
}

//----- (0053D070) --------------------------------------------------------
void __thiscall RGE_Unified_Visible_Map::Set_Map_Offsets(RGE_Unified_Visible_Map *this)
{
  int v1; // eax@1
  unsigned __int32 ***v2; // edx@2
  int v3; // esi@3
  int v4; // eax@4

  v1 = 0;
  if ( this->mapHeight > 0 )
  {
    v2 = &unified_map_offsets;
    do
    {
      v3 = v1++ * this->mapWidth;
      ++v2;
      *(v2 - 1) = (unsigned __int32 **)&this->UnifiedVisibleMap[v3];
    }
    while ( v1 < this->mapHeight );
  }
  v4 = this->mapHeight;
  if ( v4 < 256 )
    memset((void *)(4 * v4 + 8939528), 0, 4 * (256 - v4));
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053D0C0) --------------------------------------------------------
void __stdcall RGE_Unified_Visible_Map::suppress_updates(int mode)
{
  Map_Update_Suppresion = mode;
}

//----- (0053D0D0) --------------------------------------------------------
int __thiscall RGE_Visible_Map::checksumVisible(RGE_Visible_Map *this)
{
  int result; // eax@1
  int v2; // ebp@1
  int v3; // edi@2
  int i; // edx@3

  result = 0;
  v2 = 0;
  if ( this->heightValue > 0 )
  {
    v3 = this->widthValue;
    do
    {
      for ( i = 0; i < v3; ++i )
        result ^= this->map_offsets[v2][i];
      ++v2;
    }
    while ( v2 < this->heightValue );
  }
  return result;
}

//----- (0053D110) --------------------------------------------------------
unsigned int __thiscall RGE_Visible_Map::checksumUnifiedVisible(RGE_Visible_Map *this)
{
  unsigned int result; // eax@1
  int v2; // edi@2
  unsigned __int32 ***v3; // esi@2
  int v4; // ebx@2
  unsigned __int32 **v5; // ecx@4
  int v6; // edx@4
  unsigned __int32 *v7; // ebp@5

  result = 0;
  if ( this->heightValue > 0 )
  {
    v2 = this->widthValue;
    v3 = &unified_map_offsets;
    v4 = this->heightValue;
    do
    {
      if ( v2 > 0 )
      {
        v5 = *v3;
        v6 = v2;
        do
        {
          v7 = *v5;
          ++v5;
          result ^= (unsigned int)v7;
          --v6;
        }
        while ( v6 );
      }
      ++v3;
      --v4;
    }
    while ( v4 );
  }
  return result;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (0053D150) --------------------------------------------------------
void __cdecl log_map_call(int wt, int plyr, int action, int id, int x1, int y1, int x2, int y2, int sup)
{
  int v9; // eax@1
  unsigned int v10; // eax@6

  v9 = VCALL_LOG_HEAD + 1;
  if ( VCALL_LOG_HEAD + 1 < 1024 )
  {
    if ( VCALL_LOG_TAIL >= 0 )
    {
      VCALL_LOG_TAIL = VCALL_LOG_HEAD + 2;
      if ( VCALL_LOG_HEAD + 2 >= 1024 )
        VCALL_LOG_TAIL = 0;
    }
  }
  else
  {
    v9 = 0;
    VCALL_LOG_TAIL = 1;
  }
  VCALL_LOG_HEAD = v9;
  v10 = 9 * v9;
  (&VCALL_LOG)[v10 / 9] = (struct VC_LOG *)wt;
  dword_87D80C[v10] = plyr;
  dword_87D810[v10] = action;
  dword_87D814[v10] = id;
  dword_87D818[v10] = x1;
  dword_87D81C[v10] = y1;
  dword_87D820[v10] = x2;
  dword_87D824[v10] = y2;
  dword_87D828[v10] = sup;
}
// 58CDD8: using guessed type int VCALL_LOG_HEAD;
// 58CDDC: using guessed type int VCALL_LOG_TAIL;
// 87D808: using guessed type struct VC_LOG *VCALL_LOG;
// 87D80C: using guessed type int dword_87D80C[];
// 87D810: using guessed type int dword_87D810[];
// 87D814: using guessed type int dword_87D814[];
// 87D818: using guessed type int dword_87D818[];
// 87D81C: using guessed type int dword_87D81C[];
// 87D820: using guessed type int dword_87D820[];
// 87D824: using guessed type int dword_87D824[];
// 87D828: using guessed type int dword_87D828[];

//----- (0053D200) --------------------------------------------------------
void __cdecl dump_vismap_log()
{
  signed int v0; // ebp@1
  FILE *v1; // edi@1
  int v2; // ebx@3
  unsigned int v3; // esi@13

  v0 = 0;
  v1 = fopen(aCAoeexlog_txt, aW_1);
  if ( VCALL_LOG_HEAD >= 0 )
  {
    v2 = VCALL_LOG_TAIL;
    if ( VCALL_LOG_TAIL < 0 )
      v2 = 0;
    do
    {
      switch ( dword_87D810[9 * v2] )
      {
        case 1:
          fprintf(v1, aExplore);
          break;
        case 2:
          fprintf(v1, aExploreSq);
          break;
        case 3:
          fprintf(v1, aUnexplore);
          break;
        case 4:
          fprintf(v1, aUnexploreSq);
          break;
        case 5:
          fprintf(v1, aSetAll);
          break;
        case 6:
          fprintf(v1, aExploreAll);
          break;
        default:
          fprintf(v1, aErrorUndefActi, dword_87D810[9 * v2]);
          break;
      }
      v3 = 9 * v2;
      fprintf(
        v1,
        aWtDPlyrDIdDX1D,
        (&VCALL_LOG)[v3 / 9],
        dword_87D80C[v3],
        dword_87D814[v3],
        dword_87D818[v3],
        dword_87D81C[v3],
        dword_87D820[v3],
        dword_87D824[v3],
        dword_87D828[v3]);
      if ( v2 == VCALL_LOG_HEAD )
        v0 = 1;
      if ( ++v2 >= 1024 )
        v2 = 0;
    }
    while ( !v0 );
    fclose(v1);
  }
  else
  {
    fprintf(v1, aNullLog);
    fclose(v1);
  }
}
// 58CDD8: using guessed type int VCALL_LOG_HEAD;
// 58CDDC: using guessed type int VCALL_LOG_TAIL;
// 87D808: using guessed type struct VC_LOG *VCALL_LOG;
// 87D80C: using guessed type int dword_87D80C[];
// 87D810: using guessed type int dword_87D810[];
// 87D814: using guessed type int dword_87D814[];
// 87D818: using guessed type int dword_87D818[];
// 87D81C: using guessed type int dword_87D81C[];
// 87D820: using guessed type int dword_87D820[];
// 87D824: using guessed type int dword_87D824[];
// 87D828: using guessed type int dword_87D828[];
