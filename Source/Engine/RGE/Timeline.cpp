
//----- (0050D5B0) --------------------------------------------------------
void __userpurge RGE_Timeline::RGE_Timeline(RGE_Timeline *this@<ecx>, _WORD *a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  RGE_Timeline *v4; // esi@1
  int v5; // edi@1
  char *v6; // ebx@1
  int v7; // ST04_4@1
  bool v8; // zf@1
  bool v9; // sf@1
  void *v10; // esi@2
  RGE_Game_World *v11; // ecx@3
  RGE_Game_World *v12; // eax@7
  RGE_Game_World *v13; // edx@10
  __int16 *v14; // ecx@10
  int v15; // eax@10
  int v16; // edx@10
  __int16 target_player_id; // [sp+Eh] [bp-Eh]@2
  RGE_Timeline *v18; // [sp+10h] [bp-Ch]@1
  int index; // [sp+14h] [bp-8h]@1
  __int16 *v20; // [sp+18h] [bp-4h]@1

  v4 = this;
  v5 = infile;
  v6 = (char *)&this->list_num;
  v18 = this;
  v7 = infile;
  this->vfptr = (RGE_TimelineVtbl *)&RGE_Timeline::`vftable';
  v20 = &this->list_num;
  rge_read((int)a2, v5, v7, &this->list_num, 2);
  rge_read((int)a2, v5, v5, &v4->avail_id, 2);
  rge_read((int)a2, v5, v5, &v4->old_time, 4);
  v8 = *(_WORD *)v6 == 0;
  v9 = *(_WORD *)v6 < 0;
  v4->world = gworld;
  v4->time_list = 0;
  gworld = (RGE_Game_World *)&v4->time_list;
  index = 0;
  if ( !v9 && !v8 )
  {
    do
    {
      v10 = calloc(1u, 0x30u);
      rge_read((int)a2, v5, v5, v10, 4);
      rge_read((int)a2, v5, v5, (char *)v10 + 4, 1);
      rge_read((int)a2, v5, v5, (char *)v10 + 6, 2);
      rge_read((int)a2, v5, v5, (char *)v10 + 8, 1);
      rge_read((int)a2, v5, v5, (char *)v10 + 12, 4);
      rge_read((int)a2, v5, v5, (char *)v10 + 16, 4);
      rge_read((int)a2, v5, v5, (char *)v10 + 20, 4);
      rge_read((int)a2, v5, v5, (char *)v10 + 24, 2);
      rge_read((int)a2, v5, v5, (char *)v10 + 32, 2);
      rge_read((int)a2, v5, v5, &infile, 2);
      a2 = (char *)v10 + 40;
      rge_read((int)v10 + 40, v5, v5, (char *)v10 + 40, 2);
      rge_read((int)v10 + 40, v5, v5, &target_player_id, 2);
      if ( (signed __int16)infile >= 0 && (v11 = v18->world) != 0 )
        *((_DWORD *)v10 + 7) = RGE_Object_List::find_by_id(
                                 v11->players[(signed __int16)infile]->objects,
                                 *((_WORD *)v10 + 16));
      else
        *((_DWORD *)v10 + 7) = 0;
      if ( target_player_id >= 0 && (v12 = v18->world) != 0 )
        *((_DWORD *)v10 + 9) = RGE_Object_List::find_by_id(v12->players[(signed __int16)infile]->objects, *a2);
      else
        *((_DWORD *)v10 + 9) = 0;
      v13 = gworld;
      v14 = v20;
      gworld = (RGE_Game_World *)((char *)v10 + 44);
      gworld->vfptr = 0;
      v15 = index;
      v13->vfptr = (RGE_Game_WorldVtbl *)v10;
      v16 = *v14;
      index = v15 + 1;
    }
    while ( v15 + 1 < v16 );
  }
}
// 5766F4: using guessed type int (__thiscall *RGE_Timeline::`vftable')(void *Memory, unsigned int __flags);

//----- (0050D790) --------------------------------------------------------
RGE_Timeline *__thiscall RGE_Timeline::`vector deleting destructor'(RGE_Timeline *this, unsigned int __flags)
{
  RGE_Timeline *v2; // esi@1

  v2 = this;
  RGE_Timeline::~RGE_Timeline(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0050D7B0) --------------------------------------------------------
void __thiscall RGE_Timeline::RGE_Timeline(RGE_Timeline *this, RGE_Game_World *gworld)
{
  this->world = gworld;
  this->vfptr = (RGE_TimelineVtbl *)&RGE_Timeline::`vftable';
  this->time_list = 0;
  this->list_num = 0;
  this->avail_id = 0;
  LODWORD(this->old_time) = -1082130432;
}
// 5766F4: using guessed type int (__thiscall *RGE_Timeline::`vftable')(void *Memory, unsigned int __flags);

//----- (0050D7E0) --------------------------------------------------------
void __thiscall RGE_Timeline::~RGE_Timeline(RGE_Timeline *this)
{
  RGE_Timeline *v1; // esi@1
  RGE_Time_Entry *v2; // eax@1
  RGE_Time_Entry *v3; // edi@2

  v1 = this;
  v2 = this->time_list;
  this->vfptr = (RGE_TimelineVtbl *)&RGE_Timeline::`vftable';
  if ( v2 )
  {
    do
    {
      v3 = v1->time_list->next;
      free(v1->time_list);
      v1->time_list = v3;
    }
    while ( v3 );
  }
  v1->avail_id = 0;
  LODWORD(v1->old_time) = -1082130432;
  v1->world = 0;
  v1->list_num = 0;
}
// 5766F4: using guessed type int (__thiscall *RGE_Timeline::`vftable')(void *Memory, unsigned int __flags);

//----- (0050D830) --------------------------------------------------------
void __thiscall RGE_Timeline::save(RGE_Timeline *this, int outfile)
{
  RGE_Timeline *v2; // esi@1
  int v3; // edi@1
  char *v4; // ebp@1
  int v5; // edx@1
  int v6; // ebx@1
  int v7; // ebp@2
  int v8; // esi@4
  int v9; // eax@4
  int v10; // eax@7
  int target_player_id; // [sp+10h] [bp-Ch]@8
  RGE_Timeline *v12; // [sp+14h] [bp-8h]@1
  __int16 *v13; // [sp+18h] [bp-4h]@1

  v2 = this;
  v3 = outfile;
  v4 = (char *)&this->list_num;
  v12 = this;
  v13 = &this->list_num;
  rge_write(outfile, &this->list_num, 2);
  rge_write(v3, &v2->avail_id, 2);
  rge_write(v3, &v2->old_time, 4);
  v6 = 0;
  if ( *(_WORD *)v4 > 0 )
  {
    v7 = 0;
    while ( 1 )
    {
      v8 = (int)&v2->time_list[v7];
      v9 = *(_DWORD *)(v8 + 28);
      if ( v9 )
      {
        v5 = *(_DWORD *)(v9 + 12);
        LOWORD(v9) = *(_WORD *)(v5 + 74);
        outfile = v9;
      }
      else
      {
        outfile = -1;
      }
      v10 = *(_DWORD *)(v8 + 36);
      if ( v10 )
      {
        LOWORD(v5) = *(_WORD *)(*(_DWORD *)(v10 + 12) + 74);
        target_player_id = v5;
      }
      else
      {
        target_player_id = -1;
      }
      rge_write(v3, (void *)v8, 4);
      rge_write(v3, (void *)(v8 + 4), 1);
      rge_write(v3, (void *)(v8 + 6), 2);
      rge_write(v3, (void *)(v8 + 8), 1);
      rge_write(v3, (void *)(v8 + 12), 4);
      rge_write(v3, (void *)(v8 + 16), 4);
      rge_write(v3, (void *)(v8 + 20), 4);
      rge_write(v3, (void *)(v8 + 24), 2);
      rge_write(v3, (void *)(v8 + 32), 2);
      rge_write(v3, &outfile, 2);
      rge_write(v3, (void *)(v8 + 40), 2);
      rge_write(v3, &target_player_id, 2);
      ++v6;
      ++v7;
      v5 = *v13;
      if ( v6 >= v5 )
        break;
      v2 = v12;
    }
  }
}

//----- (0050D9A0) --------------------------------------------------------
void __fastcall RGE_Timeline::update(RGE_Timeline *this, RGE_Master_Static_Object **a2)
{
  RGE_Timeline *v2; // ebx@1
  RGE_Game_World *v3; // eax@1
  RGE_Time_Entry *v4; // esi@1
  RGE_Time_Entry *v5; // ecx@1
  RGE_Static_Object *v6; // eax@6
  RGE_Static_Object *v7; // eax@9
  RGE_Static_Object *v8; // ecx@16
  RGE_Player *v9; // eax@19
  RGE_Master_Static_Object *v10; // ecx@19
  int v11; // eax@20
  RGE_Time_Entry *i; // ecx@20
  RGE_Static_Object *v13; // ecx@27
  RGE_Static_Object *v14; // ecx@29
  float time; // [sp+10h] [bp-8h]@1

  v2 = this;
  v3 = this->world;
  v4 = 0;
  v5 = this->time_list;
  time = (double)v3->world_time * 0.001;
  if ( v5 )
  {
    LOBYTE(a2) = 8;
    do
    {
      if ( !v4 && v5->time > (double)v2->old_time )
        v4 = v5;
      v6 = v5->this_obj;
      if ( v6 && v6->object_state >= 8u )
        v5->this_obj = 0;
      v7 = v5->target_obj;
      if ( v7 && v7->object_state >= 8u )
        v5->target_obj = 0;
      v5 = v5->next;
    }
    while ( v5 );
    for ( ; v4; v4 = v4->next )
    {
      if ( v4->time > (double)time )
        break;
      switch ( v4->command )
      {
        case 0:
          v8 = v4->this_obj;
          if ( v8 && v4->target_obj )
            ((void (__stdcall *)(RGE_Static_Object *))v8->vfptr->set_attack)(v4->target_obj);
          break;
        case 1:
          v9 = v2->world->players[v4->player];
          a2 = v9->master_objects;
          v10 = a2[v4->obj_type];
          if ( v10 )
          {
            v11 = ((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v10->vfptr->make_new_obj)(
                    v9,
                    LODWORD(v4->x),
                    LODWORD(v4->y),
                    0);
            for ( i = v2->time_list; i; i = i->next )
            {
              if ( v4->this_obj_id == i->this_obj_id )
                i->this_obj = (RGE_Static_Object *)v11;
              LOWORD(a2) = v4->this_obj_id;
              if ( (_WORD)a2 == i->target_obj_id )
                i->target_obj = (RGE_Static_Object *)v11;
            }
          }
          break;
        case 2:
          v13 = v4->this_obj;
          if ( v13 )
            ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v13->vfptr->move_to)(
              0,
              LODWORD(v4->x),
              LODWORD(v4->y),
              LODWORD(v4->z));
          break;
        case 4:
          v14 = v4->this_obj;
          if ( v14 )
            ((void (__fastcall *)(RGE_Static_Object *, _WORD))v14->vfptr->destroy_obj)(v14, (_WORD)a2);
          break;
        default:
          continue;
      }
    }
  }
  v2->old_time = time;
}

//----- (0050DB10) --------------------------------------------------------
void __thiscall RGE_Timeline::mock_update(RGE_Timeline *this, float time)
{
  RGE_Timeline *v2; // edi@1
  RGE_Time_Entry *v3; // edx@2
  RGE_Time_Entry *v4; // esi@2
  float *v5; // ecx@3
  RGE_Player *v6; // eax@11
  RGE_Master_Static_Object *v7; // ecx@11
  int v8; // eax@12
  RGE_Time_Entry *j; // ecx@12
  RGE_Static_Object *v10; // ecx@19
  RGE_Time_Entry *i; // eax@20
  RGE_Time_Entry *v12; // eax@30
  RGE_Time_Entry *v13; // ecx@31
  RGE_Time_Entry *k; // esi@36
  RGE_Static_Object *v15; // ecx@41
  RGE_Time_Entry *m; // eax@42
  RGE_Player *v17; // eax@50
  RGE_Master_Static_Object *v18; // ecx@50
  int v19; // eax@51
  RGE_Time_Entry *l; // ecx@51

  v2 = this;
  if ( time < (double)this->old_time )
  {
    v3 = this->time_list;
    v4 = this->time_list;
    if ( v4 )
    {
      do
      {
        v5 = &v4->next->time;
        if ( !v5 )
          break;
        if ( *v5 > (double)v2->old_time )
          break;
        v4 = v4->next;
      }
      while ( v5 );
      while ( v4 )
      {
        if ( v4->time <= (double)time )
          break;
        if ( v4->time <= (double)v2->old_time )
        {
          if ( v4->command == 1 )
          {
            v10 = v4->this_obj;
            if ( v10 )
            {
              for ( i = v3; i; i = i->next )
              {
                if ( v10 == i->this_obj )
                  i->this_obj = 0;
                if ( v10 == i->target_obj )
                  i->target_obj = 0;
              }
              if ( v10 )
                ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
            }
          }
          else if ( v4->command == 4 )
          {
            v6 = v2->world->players[v4->player];
            v7 = v6->master_objects[v4->obj_type];
            if ( v7 )
            {
              v8 = ((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v7->vfptr->make_new_obj)(
                     v6,
                     LODWORD(v4->x),
                     LODWORD(v4->y),
                     0);
              for ( j = v2->time_list; j; j = j->next )
              {
                if ( v4->this_obj_id == j->this_obj_id )
                  j->this_obj = (RGE_Static_Object *)v8;
                if ( v4->this_obj_id == j->target_obj_id )
                  j->target_obj = (RGE_Static_Object *)v8;
              }
            }
          }
        }
        v3 = v2->time_list;
        if ( v4 == v3 )
        {
          v4 = 0;
        }
        else
        {
          v12 = v2->time_list;
          if ( v3 )
          {
            do
            {
              v13 = v12->next;
              if ( v13 == v4 )
                v4 = v12;
              v12 = v12->next;
            }
            while ( v13 );
          }
        }
      }
    }
  }
  if ( v2->old_time < (double)time )
  {
    for ( k = v2->time_list; k; k = k->next )
    {
      if ( k->time > (double)v2->old_time && k->time <= (double)time )
      {
        if ( k->command == 1 )
        {
          v17 = v2->world->players[k->player];
          v18 = v17->master_objects[k->obj_type];
          if ( v18 )
          {
            v19 = ((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v18->vfptr->make_new_obj)(
                    v17,
                    LODWORD(k->x),
                    LODWORD(k->y),
                    0);
            for ( l = v2->time_list; l; l = l->next )
            {
              if ( k->this_obj_id == l->this_obj_id )
                l->this_obj = (RGE_Static_Object *)v19;
              if ( k->this_obj_id == l->target_obj_id )
                l->target_obj = (RGE_Static_Object *)v19;
            }
          }
        }
        else if ( k->command == 4 )
        {
          v15 = k->this_obj;
          if ( v15 )
          {
            for ( m = v2->time_list; m; m = m->next )
            {
              if ( v15 == m->this_obj )
                m->this_obj = 0;
              if ( v15 == m->target_obj )
                m->target_obj = 0;
            }
            if ( v15 )
              ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
          }
        }
      }
    }
  }
  v2->old_time = time;
}

//----- (0050DD30) --------------------------------------------------------
__int16 __thiscall RGE_Timeline::find_id(RGE_Timeline *this, RGE_Static_Object *obj)
{
  RGE_Time_Entry *v2; // eax@1
  __int16 result; // ax@5

  v2 = this->time_list;
  if ( v2 )
  {
    while ( v2->command != 1 || v2->this_obj != obj )
    {
      v2 = v2->next;
      if ( !v2 )
        return -1;
    }
    result = v2->this_obj_id;
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (0050DD70) --------------------------------------------------------
RGE_Time_Entry *__thiscall RGE_Timeline::add(RGE_Timeline *this, float time)
{
  RGE_Timeline *v2; // ebx@1
  RGE_Time_Entry *v3; // esi@1
  char *v4; // edi@1
  float *v5; // eax@2
  RGE_Time_Entry *result; // eax@2

  v2 = this;
  v3 = this->time_list;
  v4 = (char *)&this->time_list;
  if ( v3 )
  {
    while ( v3->time <= (double)time )
    {
      v4 = (char *)&v3->next;
      v3 = v3->next;
      if ( !v3 )
      {
        result = (RGE_Time_Entry *)calloc(1u, 0x30u);
        result->time = time;
        result->next = 0;
        *(_DWORD *)v4 = result;
        ++v2->list_num;
        return result;
      }
    }
    result = (RGE_Time_Entry *)calloc(1u, 0x30u);
    result->time = time;
    result->next = v3;
    *(_DWORD *)v4 = result;
    ++v2->list_num;
  }
  else
  {
    v5 = (float *)calloc(1u, 0x30u);
    *(_DWORD *)v4 = v5;
    *v5 = time;
    ++v2->list_num;
    result = *(RGE_Time_Entry **)v4;
  }
  return result;
}

//----- (0050DE00) --------------------------------------------------------
RGE_Time_Entry *__thiscall RGE_Timeline::add_attack(RGE_Timeline *this, float time, RGE_Static_Object *obj, RGE_Static_Object *target)
{
  RGE_Timeline *v4; // ebx@1
  RGE_Time_Entry *v5; // eax@1
  RGE_Time_Entry *v6; // esi@1

  v4 = this;
  v5 = RGE_Timeline::add(this, time);
  v6 = v5;
  if ( v5 )
  {
    v5->this_obj = obj;
    v5->player = obj->owner->id;
    v5->this_obj_id = RGE_Timeline::find_id(v4, obj);
    v6->target_obj = target;
    v6->target_obj_id = RGE_Timeline::find_id(v4, obj);
    v6->command = 0;
  }
  return v6;
}

//----- (0050DE50) --------------------------------------------------------
RGE_Time_Entry *__thiscall RGE_Timeline::add_create(RGE_Timeline *this, float time, __int16 obj_id, char player, float x, float y, float z)
{
  RGE_Timeline *v7; // edi@1
  int v8; // ebx@1
  RGE_Time_Entry *v9; // esi@1
  RGE_Player *v10; // eax@1
  RGE_Master_Static_Object *v11; // ebp@1

  v7 = this;
  v8 = 0;
  v9 = RGE_Timeline::add(this, time);
  v10 = v7->world->players[(unsigned __int8)player];
  v11 = v10->master_objects[obj_id];
  if ( v11 )
    v8 = ((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))v11->vfptr->make_new_obj)(
           v11,
           v10,
           LODWORD(x),
           LODWORD(y),
           0);
  if ( v9 && v11 )
  {
    v9->player = player;
    v9->obj_type = obj_id;
    v9->this_obj = (RGE_Static_Object *)v8;
    v9->this_obj_id = v7->avail_id++;
    v9->x = x;
    v9->y = y;
    v9->z = z;
    v9->command = 1;
  }
  return v9;
}

//----- (0050DEF0) --------------------------------------------------------
RGE_Time_Entry *__thiscall RGE_Timeline::add_move(RGE_Timeline *this, float time, RGE_Static_Object *obj, float x, float y, float z)
{
  RGE_Timeline *v6; // edi@1
  RGE_Time_Entry *v7; // esi@1

  v6 = this;
  v7 = RGE_Timeline::add(this, time);
  if ( v7 )
  {
    v7->player = obj->owner->id;
    v7->this_obj = obj;
    v7->this_obj_id = RGE_Timeline::find_id(v6, obj);
    v7->x = x;
    v7->y = y;
    v7->z = z;
    v7->command = 2;
  }
  return v7;
}

//----- (0050DF40) --------------------------------------------------------
RGE_Time_Entry *__thiscall RGE_Timeline::add_delete(RGE_Timeline *this, float time, RGE_Static_Object *obj)
{
  RGE_Timeline *v3; // edi@1
  RGE_Time_Entry *result; // eax@2
  RGE_Time_Entry *v5; // ebx@3
  RGE_Time_Entry *i; // eax@4
  char v7; // dl@6
  __int16 v8; // dx@11
  RGE_Static_ObjectVtbl *v9; // eax@11

  v3 = this;
  if ( obj )
  {
    v5 = RGE_Timeline::add(this, time);
    if ( v5 )
    {
      for ( i = v3->time_list; i; i = i->next )
      {
        if ( obj == i->this_obj )
        {
          v7 = i->command;
          i->this_obj = 0;
          if ( v7 == 1 )
            v5->this_obj_id = i->this_obj_id;
        }
        if ( obj == i->target_obj )
          i->target_obj = 0;
      }
      v5->player = obj->owner->id;
      v8 = obj->master_obj->id;
      v5->command = 4;
      v5->obj_type = v8;
      v5->x = obj->world_x;
      v9 = obj->vfptr;
      v5->y = obj->world_y;
      v9->__vecDelDtor(obj, 1);
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050DFD0) --------------------------------------------------------
void __thiscall RGE_Timeline::sub(RGE_Timeline *this, RGE_Time_Entry *entry)
{
  RGE_Timeline *v2; // edi@1
  RGE_Time_Entry *v3; // esi@1
  RGE_Time_Entry **v4; // ecx@1
  RGE_Time_Entry **v5; // eax@2
  RGE_Time_Entry *i; // eax@7

  v2 = this;
  v3 = this->time_list;
  v4 = &this->time_list;
  if ( v3 )
  {
    v5 = v4;
    if ( v3 )
    {
      while ( v3 != entry )
      {
        v5 = &v3->next;
        v3 = v3->next;
        if ( !v3 )
          return;
      }
      *v5 = v3->next;
      if ( v3->command == 1 )
      {
        for ( i = *v4; i; i = i->next )
          ;
      }
      else
      {
        i = entry;
      }
      RGE_Timeline::sub(v2, i);
      free(v3);
      --v2->list_num;
    }
  }
}
