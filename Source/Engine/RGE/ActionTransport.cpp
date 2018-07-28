
/**
 * @file    Engine\RGE\Action.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00406D60) --------------------------------------------------------
void __userpurge RGE_Action_Transport::RGE_Action_Transport(RGE_Action_Transport *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Transport *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Transport::`vftable';
  v4->action_type = 12;
}
// 56E650: using guessed type int (__thiscall *RGE_Action_Transport::`vftable')(void *Memory, unsigned int __flags);

//----- (00406D90) --------------------------------------------------------
RGE_Action_Transport *__thiscall RGE_Action_Transport::`scalar deleting destructor'(RGE_Action_Transport *this, unsigned int __flags)
{
  RGE_Action_Transport *v2; // esi@1

  v2 = this;
  RGE_Action_Transport::~RGE_Action_Transport(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00406DC0) --------------------------------------------------------
void __thiscall RGE_Action_Transport::RGE_Action_Transport(RGE_Action_Transport *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  RGE_Action_Transport *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&RGE_Action_Transport::`vftable';
  v6->action_type = 12;
  v6->target_x = x;
  v6->target_z = z;
}
// 56E650: using guessed type int (__thiscall *RGE_Action_Transport::`vftable')(void *Memory, unsigned int __flags);

//----- (00406E00) --------------------------------------------------------
void __thiscall RGE_Action_Transport::first_in_stack(RGE_Action_Transport *this, char first_time)
{
  if( first_time )
  {
    if( this->target_x < 0.0 || this->target_y < 0.0 )
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(2);
    else
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(11);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(2);
  }
}

//----- (00406E50) --------------------------------------------------------
void __thiscall RGE_Action_Transport::set_state(RGE_Action_Transport *this, char new_state)
{
  RGE_Action_Transport *v2; // esi@1
  RGE_Action_Move_To *v3; // eax@5
  RGE_Action *v4; // eax@6
  RGE_Action_Move_To *v5; // eax@7
  RGE_Action *v6; // edi@10

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  if( new_state == 2 )
  {
    (*(void (__stdcall **)(_DWORD))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
    return;
  }
  if( new_state == 4 || new_state == 11 )
  {
    if( v2->task )
    {
      v3 = (RGE_Action_Move_To *)operator new(0x44u);
      if( v3 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v3,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          0.30000001,
          v2->task->move_sprite);
        goto LABEL_10;
      }
    }
    else
    {
      v5 = (RGE_Action_Move_To *)operator new(0x44u);
      if( v5 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v5,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          0.30000001,
          v2->obj->master_obj->sprite);
        goto LABEL_10;
      }
    }
    v4 = 0;
LABEL_10:
    v6 = v4;
    if( v4 )
    {
      RGE_Action_List::add_action(v2->sub_actions, v4);
      RGE_Action::setSubAction(v6, 1);
    }
    else
    {
      v2->vfptr->set_state((RGE_Action *)v2, 2);
    }
  }
}

//----- (00406F90) --------------------------------------------------------
char __thiscall RGE_Action_Transport::update(RGE_Action_Transport *this)
{
  RGE_Action_Transport *v1; // esi@1
  unsigned __int8 v2; // al@2
  unsigned __int8 v4; // al@5
  int v5; // eax@8
  int v6; // eax@12
  bool v7; // zf@12
  RGE_Action_Object *v8; // eax@12
  RGE_PlayerVtbl **v9; // ecx@14
  int v10; // eax@14
  RGE_PlayerVtbl *v11; // edx@14
  RGE_Map *v12; // edi@15
  RGE_PlayerVtbl **v13; // ecx@19
  signed int v14; // [sp-10h] [bp-18h]@14

  v1 = this;
  switch ( this->state )
  {
    case 0xB:
      v2 = ((int (*)(void))this->sub_actions->vfptr->update)();
      if( !v2 || v2 > 5u )
        return 0;
      v1->vfptr->set_state((RGE_Action *)v1, 2);
      return 0;
    case 4:
      v4 = ((int (*)(void))this->sub_actions->vfptr->update)();
      if( !v4 || v4 > 5u )
        return 0;
      v1->vfptr->set_state((RGE_Action *)v1, 6);
      return 0;
    case 6:
      v5 = RGE_Action_Transport::targetZone(this);
      if( v5 != -1 && !RGE_Static_Object::withinRangeOfZone((RGE_Static_Object *)&v1->obj->vfptr, v5, 2.0) )
        goto LABEL_18;
      if( v1->obj->objects->number_of_objects <= 0 )
        goto LABEL_21;
      if( ((int (__thiscall *)(RGE_Action_Transport *))v1->vfptr[1].__vecDelDtor)(v1) )
      {
        v6 = RGE_Action_Transport::targetZone(v1);
        v7 = RGE_Static_Object::drop_held_objects((RGE_Static_Object *)&v1->obj->vfptr, v6) == 0;
        v8 = v1->obj;
        if( !v7 )
        {
          if( v8->objects->number_of_objects <= 0 )
          {
LABEL_21:
            v1->vfptr->set_state((RGE_Action *)v1, 2);
            return 0;
          }
          v9 = &v8->owner->vfptr;
          v10 = v8->id;
          v11 = *v9;
          v14 = 518;
LABEL_20:
          ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v11->notify)(v10, v10, v14, 614, 0, 0);
          goto LABEL_21;
        }
      }
      else
      {
        v12 = v1->obj->owner->world->map;
        if( LODWORD(v1->target_x) != -1082130432
          && (RGE_Map::get_terrain(v12, (signed __int64)v1->target_x, (signed __int64)v1->target_y) == 1
           || RGE_Map::get_terrain(v12, (signed __int64)v1->target_x, (signed __int64)v1->target_y) == 22) )
        {
          goto LABEL_21;
        }
LABEL_18:
        v8 = v1->obj;
      }
      v13 = &v8->owner->vfptr;
      v10 = v8->id;
      v11 = *v13;
      v14 = 519;
      goto LABEL_20;
    case 1:
      return 1;
    case 0xD:
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))this->obj->vfptr->notify)(
        this->obj->id,
        this->obj->id,
        505,
        614,
        0,
        0);
      v1->vfptr->set_state((RGE_Action *)v1, 2);
      return 3;
    default:
      return 0;
  }
}

//----- (00407160) --------------------------------------------------------
int __thiscall RGE_Action_Transport::stop(RGE_Action_Transport *this)
{
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(2);
  return 1;
}

//----- (00407170) --------------------------------------------------------
int __thiscall RGE_Action_Transport::move_to(RGE_Action_Transport *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  RGE_ActionVtbl *v5; // edx@1

  this->target_x = x;
  this->target_y = y;
  v5 = this->vfptr;
  this->target2ID = 0;
  this->target_z = z;
  ((void (__stdcall *)(signed int))v5->set_state)(11);
  return 1;
}

//----- (004071A0) --------------------------------------------------------
int __thiscall RGE_Action_Transport::work(RGE_Action_Transport *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  RGE_Action_Transport *v5; // esi@1
  int v6; // edi@1
  RGE_ActionVtbl *v7; // edx@4
  RGE_Static_Object *v9; // ecx@7
  float distance; // [sp+0h] [bp-4h]@1

  v5 = this;
  this->target2ID = 1;
  v6 = (unsigned __int8)RGE_Static_Object::lookupZone(
                          (RGE_Static_Object *)&this->obj->vfptr,
                          (signed __int64)x,
                          (signed __int64)y);
  distance = RGE_Static_Object::distance_to_position((RGE_Static_Object *)&v5->obj->vfptr, x, y, v5->obj->world_z);
  if( v6 != -1
    && RGE_Static_Object::withinRangeOfZone((RGE_Static_Object *)&v5->obj->vfptr, v6, 2.0) == 1
    && distance <= 2.0 )
  {
    v5->target_y = y;
    v7 = v5->vfptr;
    v5->target_x = x;
    v5->target_z = z;
    v7->set_state((RGE_Action *)v5, 6);
    return 1;
  }
  if( x >= 0.0 && y >= 0.0 )
  {
    v5->target_x = x;
    v5->target_y = y;
    v9 = (RGE_Static_Object *)&v5->obj->vfptr;
    v5->target_z = z;
    if( obj_in != v9 )
    {
      v5->vfptr->set_state((RGE_Action *)v5, 11);
      return 1;
    }
    v5->vfptr->set_state((RGE_Action *)v5, 4);
  }
  return 1;
}

//----- (004072B0) --------------------------------------------------------
int __thiscall RGE_Action_Transport::next_to_drop_off_terrain(RGE_Action_Transport *this)
{
  RGE_Task *v1; // eax@1
  int result; // eax@3
  RGE_Action_Object *v3; // esi@4
  RGE_Master_Static_Object *v4; // ebx@4
  int v5; // ebp@4
  int v6; // edi@4
  signed __int64 v7; // rax@4
  RGE_Map *v8; // ebx@4
  int v9; // ecx@6
  signed int v10; // ecx@10
  int v11; // ebp@12
  int v12; // esi@15
  int x2; // [sp+10h] [bp-10h]@4
  RGE_Action_Transport *v14; // [sp+14h] [bp-Ch]@1
  int y2; // [sp+18h] [bp-8h]@4
  int x1; // [sp+1Ch] [bp-4h]@4

  v1 = this->task;
  v14 = this;
  if( v1 && v1->terrain_id == -1 )
  {
    result = 1;
  }
  else
  {
    v3 = this->obj;
    v4 = v3->master_obj;
    v5 = (signed __int64)(v3->world_x - v4->radius_x - 1.0);
    x1 = (signed __int64)(v3->world_x - v4->radius_x - 1.0);
    v6 = (signed __int64)(v3->world_y - v4->radius_y - 1.0);
    x2 = (signed __int64)(v4->radius_x + v3->world_x - -1.0);
    v7 = (signed __int64)(v4->radius_y + v3->world_y - -1.0);
    y2 = v7;
    v8 = v3->owner->world->map;
    if( v5 < 0 )
      x1 = 0;
    v9 = v8->map_width;
    if( x2 >= v9 )
      x2 = v9 - 1;
    if( v6 < 0 )
      v6 = 0;
    v10 = v8->map_height;
    if( (signed int)v7 >= v10 )
      y2 = v10 - 1;
    v11 = RGE_Action_Transport::targetZone(v14);
    if( LODWORD(v14->target_x) != -1082130432 )
      v11 = (unsigned __int8)RGE_Static_Object::lookupZone(
                               (RGE_Static_Object *)&v14->obj->vfptr,
                               (signed __int64)v14->target_x,
                               (signed __int64)v14->target_y);
    if( v6 > y2 )
    {
      result = 0;
    }
    else
    {
      while( 1 )
      {
        v12 = x1;
        if( x1 <= x2 )
          break;
LABEL_21:
        if( ++v6 > y2 )
          return 0;
      }
      while( v11 != -1
           && (unsigned __int8)RGE_Static_Object::lookupZone((RGE_Static_Object *)&v14->obj->vfptr, v12, v6) != v11
           || RGE_Map::get_terrain(v8, v12, v6) != 2 && RGE_Map::get_terrain(v8, v12, v6) != 4 )
      {
        if( ++v12 > x2 )
          goto LABEL_21;
      }
      result = 1;
    }
  }
  return result;
}

//----- (00407420) --------------------------------------------------------
int __thiscall RGE_Action_Transport::targetZone(RGE_Action_Transport *this)
{
  int result; // eax@2

  if( LODWORD(this->target_x) == -1082130432 )
    result = -1;
  else
    result = (unsigned __int8)RGE_Static_Object::lookupZone(
                                (RGE_Static_Object *)&this->obj->vfptr,
                                (signed __int64)this->target_x,
                                (signed __int64)this->target_y);
  return result;
}
