
/**
 * @file    Engine\RGE\Action.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00405510) --------------------------------------------------------
void __userpurge RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Move_To *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Move_To *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Move_To::`vftable';
  v4->action_type = 1;
  rge_read(a2, infile, infile, &v4->range, 4);
}
// 56E3A0: using guessed type int (__thiscall *RGE_Action_Move_To::`vftable')(void *Memory, unsigned int __flags);

//----- (00405580) --------------------------------------------------------
RGE_Action_Move_To *__thiscall RGE_Action_Move_To::`vector deleting destructor'(RGE_Action_Move_To *this, unsigned int __flags)
{
  RGE_Action_Move_To *v2; // esi@1

  v2 = this;
  RGE_Action_Move_To::~RGE_Action_Move_To(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004055A0) --------------------------------------------------------
void __thiscall RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Move_To *this, RGE_Action_Object *obj_in, float x, float y, float z, float range_in, RGE_Sprite *sprite_in)
{
  RGE_Action_Move_To *v7; // esi@1
  RGE_Master_Static_Object *v8; // eax@4
  RGE_Sprite *v9; // ecx@4

  v7 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v7->target_x = x;
  v7->target_z = z;
  v7->range = range_in;
  v7->vfptr = (RGE_ActionVtbl *)&RGE_Action_Move_To::`vftable';
  v7->action_type = 1;
  v7->target_y = y;
  v7->sprite = sprite_in;
  if ( range_in <= 0.0 )
    LODWORD(v7->range) = 1053609165;
  if ( !sprite_in )
  {
    v8 = v7->obj->master_obj;
    v9 = *(RGE_Sprite **)&v8[1].master_type;
    if ( v9 )
      v7->sprite = v9;
    else
      v7->sprite = v8->sprite;
  }
}
// 56E3A0: using guessed type int (__thiscall *RGE_Action_Move_To::`vftable')(void *Memory, unsigned int __flags);

//----- (00405620) --------------------------------------------------------
void __thiscall RGE_Action_Move_To::RGE_Action_Move_To(RGE_Action_Move_To *this, RGE_Action_Object *obj_in, RGE_Static_Object *target_obj_in, float range_in, RGE_Sprite *sprite_in)
{
  RGE_Action_Move_To *v5; // esi@1
  RGE_Master_Static_Object *v6; // eax@6
  RGE_Sprite *v7; // ecx@6

  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v5->vfptr = (RGE_ActionVtbl *)&RGE_Action_Move_To::`vftable';
  v5->action_type = 1;
  RGE_Action::set_target_obj((RGE_Action *)&v5->vfptr, target_obj_in);
  if ( target_obj_in )
  {
    v5->target_x = target_obj_in->world_x;
    v5->target_y = target_obj_in->world_y;
    v5->target_z = target_obj_in->world_z;
  }
  v5->range = range_in;
  v5->sprite = sprite_in;
  if ( range_in <= 0.0 )
    LODWORD(v5->range) = 1053609165;
  if ( !sprite_in )
  {
    v6 = v5->obj->master_obj;
    v7 = *(RGE_Sprite **)&v6[1].master_type;
    if ( v7 )
      v5->sprite = v7;
    else
      v5->sprite = v6->sprite;
  }
}
// 56E3A0: using guessed type int (__thiscall *RGE_Action_Move_To::`vftable')(void *Memory, unsigned int __flags);

//----- (004056E0) --------------------------------------------------------
void __thiscall RGE_Action_Move_To::~RGE_Action_Move_To(RGE_Action_Move_To *this)
{
  RGE_Action_Move_To *v1; // esi@1

  v1 = this;
  this->vfptr = (RGE_ActionVtbl *)&RGE_Action_Move_To::`vftable';
  ((void (__stdcall *)(_DWORD))this->obj->vfptr->removeAllUserDefinedWaypoints)(0);
  (*(void (**)(void))&v1->obj->vfptr[1].gap4[0])();
  RGE_Action::~RGE_Action((RGE_Action *)&v1->vfptr);
}
// 56E3A0: using guessed type int (__thiscall *RGE_Action_Move_To::`vftable')(void *Memory, unsigned int __flags);

//----- (00405750) --------------------------------------------------------
void __thiscall RGE_Action_Move_To::save(RGE_Action_Move_To *this, int outfile)
{
  RGE_Action_Move_To *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->range, 4);
}

//----- (00405780) --------------------------------------------------------
void __userpurge RGE_Action_Move_To::first_in_stack(RGE_Action_Move_To *this@<ecx>, double a2@<st0>, char first_time)
{
  RGE_Action_Move_To *v3; // esi@1
  RGE_Static_Object *v4; // eax@1

  v3 = this;
  v4 = this->target_obj;
  if ( v4 && RGE_Static_Object::inRange((RGE_Static_Object *)&this->obj->vfptr, v4, this->range) )
  {
    v3->vfptr->set_state((RGE_Action *)v3, 1);
  }
  else
  {
    ((void (*)(void))v3->obj->vfptr->maximumSpeed)();
    if ( a2 == 0.0 )
      v3->vfptr->set_state((RGE_Action *)v3, 13);
    else
      v3->vfptr->set_state((RGE_Action *)v3, 3);
  }
}

//----- (004057E0) --------------------------------------------------------
void __thiscall RGE_Action_Move_To::set_state(RGE_Action_Move_To *this, char new_state)
{
  this->state = new_state;
  switch ( new_state )
  {
    case 4:
      (*(void (__stdcall **)(_DWORD))&this->obj->vfptr->gap4[52])(this->sprite);
      break;
    case 1:
    case 0xD:
    case 0xE:
      if ( !this->subActionValue )
        (*(void (__thiscall **)(_DWORD, _DWORD))&this->obj->vfptr->gap4[52])(this->obj, this->obj->master_obj->sprite);
      break;
    default:
      return;
  }
}

//----- (00405850) --------------------------------------------------------
char __thiscall RGE_Action_Move_To::update(RGE_Action_Move_To *this)
{
  RGE_Action_Move_To *v1; // esi@1
  RGE_Static_Object *v2; // eax@7
  char result; // al@11
  RGE_Static_Object *v4; // eax@19
  double v5; // st7@21
  signed __int64 v6; // rax@21
  double v7; // st7@21
  RGE_Action_Object *v8; // ecx@21
  RGE_Static_Object *v9; // eax@23
  double v10; // st7@29
  char v12; // c0@29
  int v13; // eax@33
  RGE_Static_Object *v14; // eax@40
  double v15; // st7@41
  char v17; // c0@41
  RGE_ActionVtbl *v18; // edi@45
  char (__thiscall *v19)(RGE_Action *); // edi@45
  float yDiff; // [sp+8h] [bp-8h]@21
  float v21; // [sp+Ch] [bp-4h]@41

  v1 = this;
  if ( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
  {
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
    goto LABEL_10;
  }
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if ( v2 && v2->object_state >= 7u )
  {
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
LABEL_10:
    if ( v1->subActionValue == 1 )
    {
      result = 5;
    }
    else
    {
      ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))v1->obj->vfptr->notify)(
        v1->obj->id,
        v1->obj->id,
        507,
        610,
        v1->targetID,
        0);
      result = 4;
    }
    return result;
  }
  switch ( v1->state )
  {
    case 3:
      if ( v2 && RGE_Static_Object::inRange((RGE_Static_Object *)&v1->obj->vfptr, v2, v1->range) )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 1);
        if ( !v1->subActionValue )
          ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
            v1->obj->id,
            v1->obj->id,
            506,
            610,
            0,
            0);
        ((void (__stdcall *)(_DWORD))v1->obj->vfptr->setWaitingToMove)(0);
        result = 2;
        v1->obj->pathingGroupMembers.numberValue = 0;
      }
      else
      {
        v4 = v1->target_obj;
        if ( v4 )
        {
          v1->target_x = v4->world_x;
          v1->target_y = v4->world_y;
          v1->target_z = v4->world_z;
        }
        RGE_Moving_Object::setGoal((RGE_Moving_Object *)&v1->obj->vfptr, v1->target_x, v1->target_y, 1.0);
        v5 = v1->target_y;
        LOBYTE(yDiff) = (signed __int64)v1->target_x;
        v6 = (signed __int64)v5;
        v7 = v1->target_z;
        BYTE1(yDiff) = v6;
        v8 = v1->obj;
        BYTE2(yDiff) = (signed __int64)v7;
        if ( !v8->finalUserDefinedWaypoint )
        {
          ((void (__stdcall *)(float *, _DWORD))v8->vfptr->addUserDefinedWaypoint)(&yDiff, 0);
          RGE_Moving_Object::setFinalUserDefinedWaypoint((RGE_Moving_Object *)&v1->obj->vfptr);
        }
        RGE_Moving_Object::setActionRange((RGE_Moving_Object *)&v1->obj->vfptr, v1->range);
        v9 = v1->target_obj;
        if ( v9 )
        {
          RGE_Moving_Object::setTargetID((RGE_Moving_Object *)&v1->obj->vfptr, v9->id);
          RGE_Moving_Object::setTargetRadius(
            (RGE_Moving_Object *)&v1->obj->vfptr,
            v1->target_obj->master_obj->radius_x,
            v1->target_obj->master_obj->radius_y);
        }
        else
        {
          RGE_Moving_Object::setTargetID((RGE_Moving_Object *)&v1->obj->vfptr, -1);
          RGE_Moving_Object::setTargetRadius((RGE_Moving_Object *)&v1->obj->vfptr, 0.0, 0.0);
        }
        if ( RGE_Moving_Object::findPath((RGE_Moving_Object *)&v1->obj->vfptr) )
          goto LABEL_38;
        v1->vfptr->set_state((RGE_Action *)v1, 4);
        result = 0;
      }
      break;
    case 4:
      if ( v2 )
      {
        v10 = v1->target_x - v2->world_x;
        yDiff = v1->target_y - v2->world_y;
        if ( v12 || v10 > 1.0 || yDiff < -1.0 || yDiff > 1.0 )
          goto LABEL_52;
      }
      v13 = RGE_Moving_Object::doMove((RGE_Moving_Object *)&v1->obj->vfptr);
      if ( !v13 )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 1);
        goto LABEL_35;
      }
      if ( v13 != 2 )
        goto LABEL_38;
      v14 = v1->target_obj;
      if ( v14
        && ((v15 = v1->target_x - v14->world_x, v21 = v1->target_y - v14->world_y, v17)
         || v15 > 1.0
         || v21 < -1.0
         || v21 > 1.0) )
      {
LABEL_52:
        ((void (__stdcall *)(int, int, signed int, _DWORD, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          508,
          0,
          0,
          0);
        v18 = v1->vfptr;
        v1->vfptr->set_state((RGE_Action *)v1, 3);
        v19 = v18->update;
        v19((RGE_Action *)&v1->vfptr);
        v19((RGE_Action *)&v1->vfptr);
        result = 0;
      }
      else
      {
        if ( !v1->subActionValue )
          ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
            v1->obj->id,
            v1->obj->id,
            506,
            610,
            0,
            0);
        v1->vfptr->set_state((RGE_Action *)v1, 1);
        result = 2;
      }
      break;
    case 0xD:
LABEL_35:
      if ( !v1->subActionValue )
        ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          505,
          610,
          0,
          0);
      result = 3;
      break;
    default:
LABEL_38:
      result = 0;
      break;
    case 1:
      result = 1;
      break;
  }
  return result;
}

//----- (00405BF0) --------------------------------------------------------
char __thiscall RGE_Action_Move_To::is_in_range(RGE_Action_Move_To *this)
{
  RGE_Action_Move_To *v1; // esi@1
  RGE_Static_Object *v2; // eax@1
  long double v3; // st7@3

  v1 = this;
  v2 = this->target_obj;
  if ( this->range <= 0.0 )
  {
    if ( v2 && RGE_Static_Object::inRange((RGE_Static_Object *)&this->obj->vfptr, v2, 0.25) )
      return 1;
  }
  else
  {
    if ( v2 )
      v3 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)&this->obj->vfptr, v2);
    else
      v3 = RGE_Static_Object::distance_to_position(
             (RGE_Static_Object *)&this->obj->vfptr,
             this->target_x,
             this->target_y,
             this->target_z);
    if ( v3 <= v1->range )
      return 1;
  }
  return 0;
}
