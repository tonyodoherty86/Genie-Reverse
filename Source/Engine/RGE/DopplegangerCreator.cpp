
//----- (00442100) --------------------------------------------------------
void __thiscall RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(RGE_Doppleganger_Creator *this, RGE_Player *player, int initial_size)
{
  RGE_Doppleganger_Creator *v3; // esi@1

  v3 = this;
  this->Objects = (RGE_Static_Object **)calloc(initial_size, 4u);
  v3->Map_Addresses = (unsigned int **)calloc(initial_size, 4u);
  v3->Last_Map_Value = (unsigned int *)calloc(initial_size, 4u);
  v3->Object_ids = (int *)calloc(initial_size, 4u);
  v3->allocated_size = initial_size;
  v3->active_size = 0;
  v3->owner = player;
  if( !DDlogf )
    DDlogf = fopen(aCAoedoppl_txt, aW_1);
}

//----- (00442180) --------------------------------------------------------
void __thiscall RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator(RGE_Doppleganger_Creator *this)
{
  RGE_Doppleganger_Creator *v1; // esi@1
  int *v2; // esi@7

  v1 = this;
  if( this->Objects )
    free(this->Objects);
  if( v1->Map_Addresses )
    free(v1->Map_Addresses);
  if( v1->Last_Map_Value )
    free(v1->Last_Map_Value);
  v2 = v1->Object_ids;
  if( v2 )
    free(v2);
  if( DDlogf )
  {
    fclose(DDlogf);
    DDlogf = 0;
  }
}

//----- (004421F0) --------------------------------------------------------
int __thiscall RGE_Doppleganger_Creator::add_doppleganger_check(RGE_Doppleganger_Creator *this, RGE_Static_Object *theObj, unsigned int *UMV_addr)
{
  RGE_Doppleganger_Creator *v3; // esi@1
  int result; // eax@6
  int v5; // edx@7
  int v6; // eax@8
  RGE_Static_Object **v7; // ecx@9

  v3 = this;
  if( DDlogf )
    fprintf(DDlogf, aAdc_DPDIdD, this->owner->world->world_time, this->owner->id, theObj->id);
  if( v3->active_size >= v3->allocated_size )
    RGE_Doppleganger_Creator::expand_allocations(v3, 30);
  if( theObj->owner->id == v3->owner->id )
  {
    v5 = v3->active_size;
    if( v5 <= 0 || (v6 = 0, v5 <= 0) )
    {
LABEL_12:
      v3->Objects[v5] = theObj;
      v3->Map_Addresses[v3->active_size] = UMV_addr;
      v3->Last_Map_Value[v3->active_size] = *UMV_addr;
      v3->Object_ids[v3->active_size++] = theObj->id;
      result = 1;
    }
    else
    {
      v7 = v3->Objects;
      while( *v7 != theObj )
      {
        ++v6;
        ++v7;
        if( v6 >= v5 )
          goto LABEL_12;
      }
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004422B0) --------------------------------------------------------
int __thiscall RGE_Doppleganger_Creator::remove_doppleganger_check(RGE_Doppleganger_Creator *this, RGE_Static_Object *theObj)
{
  RGE_Doppleganger_Creator *v2; // esi@1
  int v3; // edx@3
  int v4; // eax@4
  RGE_Static_Object **v5; // edi@5
  RGE_Static_Object **v6; // ecx@5
  int result; // eax@8
  int v8; // eax@10

  v2 = this;
  if( DDlogf )
    fprintf(DDlogf, aRdc_DPDIdD, this->owner->world->world_time, this->owner->id, theObj->id);
  v3 = v2->active_size;
  if( v3 <= 0 || (v4 = 0, v3 <= 0) )
  {
    result = 0;
  }
  else
  {
    v5 = v2->Objects;
    v6 = v2->Objects;
    while( *v6 != theObj )
    {
      ++v4;
      ++v6;
      if( v4 >= v3 )
        return 0;
    }
    v2->active_size = v3 - 1;
    if( v4 < v3 - 1 )
    {
      v8 = v4;
      v5[v8] = v5[v3 - 1];
      v2->Map_Addresses[v8] = v2->Map_Addresses[v2->active_size];
      v2->Last_Map_Value[v8] = v2->Last_Map_Value[v2->active_size];
      v2->Object_ids[v8] = v2->Object_ids[v2->active_size];
    }
    v2->Objects[v2->active_size] = 0;
    v2->Map_Addresses[v2->active_size] = 0;
    v2->Last_Map_Value[v2->active_size] = 0;
    v2->Object_ids[v2->active_size] = 0;
    result = 1;
  }
  return result;
}

//----- (00442390) --------------------------------------------------------
void __thiscall RGE_Doppleganger_Creator::perform_doppleganger_checks(RGE_Doppleganger_Creator *this)
{
  RGE_Doppleganger_Creator *v1; // esi@1
  RGE_Static_Object *v2; // ecx@1
  int v3; // eax@1
  int v4; // edi@2
  unsigned int *v5; // ecx@3
  unsigned int v6; // ebp@3
  RGE_Static_Object **v7; // eax@4
  RGE_Static_Object *v8; // ebx@4
  signed int v9; // ebx@6
  unsigned int i; // ebp@6
  RGE_Static_Object *v11; // edi@10
  RGE_Static_Object *v12; // ST1C_4@11
  int v13; // ecx@11
  unsigned int Unified_Map_Value; // [sp+14h] [bp-14h]@3
  int x; // [sp+18h] [bp-10h]@2
  RGE_Static_Object *remove_me; // [sp+1Ch] [bp-Ch]@1
  int v17; // [sp+20h] [bp-8h]@8

  v1 = this;
  v2 = 0;
  v3 = v1->active_size;
  remove_me = 0;
  if( v3 > 0 )
  {
    v4 = 0;
    x = 0;
    if( v3 > 0 )
    {
      do
      {
        v5 = v1->Map_Addresses[v4];
        v6 = *v5;
        Unified_Map_Value = *v5;
        if( *v5 != v1->Last_Map_Value[v4] )
        {
          v7 = v1->Objects;
          v8 = v7[v4];
          if( v8 && (v8 = v7[v4], RGE_Game_World::object(v1->owner->world, v1->Object_ids[v4]) == v8) )
          {
            v9 = 1;
            for( i = (unsigned __int16)(v1->Last_Map_Value[v4] >> 1) & (unsigned __int16)((v1->Last_Map_Value[v4] ^ v6) >> 1) & 0x7FFF;
                  i;
                  i >>= 1 )
            {
              if( (i & 1) == 1 )
              {
                v17 = v1->owner->id;
                if( v9 != v17 )
                {
                  if( DDlogf )
                  {
                    v11 = v1->Objects[v4];
                    fprintf(
                      DDlogf,
                      aNewDop_DByPDFo,
                      v1->owner->world->world_time,
                      v17,
                      v9,
                      v11->id,
                      (unsigned int)(signed __int64)v11->world_x,
                      (unsigned int)(signed __int64)v11->world_y);
                    v4 = x;
                  }
                  v12 = v1->Objects[v4];
                  v13 = *((_DWORD *)v1->owner->world->players[v9]->master_objects + 243);
                  (*(void (__thiscall **)(int, RGE_Player *, _DWORD, _DWORD, _DWORD, RGE_Static_Object *))(*(_DWORD *)v13 + 56))(
                    v13,
                    v1->owner->world->players[v9],
                    LODWORD(v12->world_x),
                    LODWORD(v12->world_y),
                    LODWORD(v12->world_z),
                    v12);
                }
              }
              ++v9;
            }
            v6 = Unified_Map_Value;
          }
          else
          {
            remove_me = v8;
            if( DDlogf )
              fprintf(DDlogf, aRemoveCheck_DB, v1->owner->world->world_time, v1->owner->id, v1->Object_ids[v4]);
          }
          v1->Last_Map_Value[v4] = v6;
        }
        x = ++v4;
      }
      while( v4 < v1->active_size );
      v2 = remove_me;
    }
    if( v2 )
      RGE_Doppleganger_Creator::remove_doppleganger_check(v1, v2);
  }
}

//----- (00442540) --------------------------------------------------------
void __thiscall RGE_Doppleganger_Creator::expand_allocations(RGE_Doppleganger_Creator *this, int grow_size)
{
  RGE_Doppleganger_Creator *v2; // ebx@1
  size_t v3; // edx@3
  RGE_Static_Object **v4; // ebp@3
  unsigned int *TLast_Map_Value; // ST24_4@3
  int *v6; // eax@3
  int *TObject_ids; // ST28_4@3
  unsigned int **grow_sizea; // [sp+1Ch] [bp+4h]@3

  v2 = this;
  if( DDlogf )
    fprintf(DDlogf, aResize_DPDGrow, this->owner->world->world_time, this->owner->id, grow_size);
  v3 = grow_size + v2->allocated_size;
  v2->allocated_size = v3;
  v4 = (RGE_Static_Object **)calloc(v3, 4u);
  grow_sizea = (unsigned int **)calloc(v2->allocated_size, 4u);
  TLast_Map_Value = (unsigned int *)calloc(v2->allocated_size, 4u);
  v6 = (int *)calloc(v2->allocated_size, 4u);
  qmemcpy(v4, v2->Objects, 4 * v2->active_size);
  TObject_ids = v6;
  qmemcpy(grow_sizea, v2->Map_Addresses, 4 * v2->active_size);
  qmemcpy(TLast_Map_Value, v2->Last_Map_Value, 4 * v2->active_size);
  qmemcpy(v6, v2->Object_ids, 4 * v2->active_size);
  free(v2->Objects);
  free(v2->Map_Addresses);
  free(v2->Last_Map_Value);
  free(v2->Object_ids);
  v2->Objects = v4;
  v2->Map_Addresses = grow_sizea;
  v2->Last_Map_Value = TLast_Map_Value;
  v2->Object_ids = TObject_ids;
}
