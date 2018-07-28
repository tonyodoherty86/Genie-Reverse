
/**
 * @file    Engine\TRB\ActionBuild.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004CD1B0) --------------------------------------------------------
void __userpurge TRIBE_Action_Build::TRIBE_Action_Build(TRIBE_Action_Build *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Build *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Build::`vftable';
  v4->action_type = 101;
}
// 574F18: using guessed type int (__thiscall *TRIBE_Action_Build::`vftable')(void *Memory, unsigned int __flags);

//----- (004CD1E0) --------------------------------------------------------
TRIBE_Action_Build *__thiscall TRIBE_Action_Build::`vector deleting destructor'(TRIBE_Action_Build *this, unsigned int __flags)
{
  TRIBE_Action_Build *v2; // esi@1

  v2 = this;
  TRIBE_Action_Build::~TRIBE_Action_Build(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CD210) --------------------------------------------------------
void __thiscall TRIBE_Action_Build::TRIBE_Action_Build(TRIBE_Action_Build *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Build *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Build::`vftable';
  v4->action_type = 101;
  v4->task = task_in;
  if ( !target_obj_in || obj_in->owner->id == target_obj_in->owner->id )
  {
    RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
    v4->target_x = target_obj_in->world_x;
    v4->target_y = target_obj_in->world_y;
    v4->target_z = target_obj_in->world_z;
  }
}
// 574F18: using guessed type int (__thiscall *TRIBE_Action_Build::`vftable')(void *Memory, unsigned int __flags);

//----- (004CD2A0) --------------------------------------------------------
void __thiscall TRIBE_Action_Build::TRIBE_Action_Build(TRIBE_Action_Build *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Build *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Build::`vftable';
  v6->action_type = 101;
  v6->target_x = x;
  v6->target_z = z;
}
// 574F18: using guessed type int (__thiscall *TRIBE_Action_Build::`vftable')(void *Memory, unsigned int __flags);

//----- (004CD2E0) --------------------------------------------------------
void __thiscall TRIBE_Action_Build::first_in_stack(TRIBE_Action_Build *this, char first_time)
{
  if ( first_time )
  {
    if ( this->target_obj )
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(4);
    else
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
  }
}

//----- (004CD310) --------------------------------------------------------
void __thiscall TRIBE_Action_Build::set_state(TRIBE_Action_Build *this, char new_state)
{
  TRIBE_Action_Build *v2; // esi@1
  int v3; // eax@2
  RGE_Action_Object *v4; // ecx@2
  bool v5; // zf@2
  int v6; // eax@2
  RGE_Static_ObjectVtbl *v7; // edx@2
  RGE_ActionVtbl *v8; // edi@5
  RGE_Action_Move_To *v9; // eax@6
  RGE_Action *v10; // eax@7
  RGE_Action *v11; // edi@7
  RGE_Static_Object *v12; // eax@12
  RGE_Action_Move_To *v13; // eax@14
  RGE_Action *v14; // eax@15
  RGE_Action *v15; // edi@15
  RGE_Static_ObjectVtbl *v16; // edx@20
  RGE_Sprite *v17; // eax@20
  RGE_Sound *v18; // ecx@21
  RGE_Action_Object *v19; // ecx@23

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  switch ( new_state )
  {
    case 3:
      v3 = RGE_Player::computerPlayer(v2->obj->owner);
      v4 = v2->obj;
      v5 = v3 == 1;
      v6 = v4->id;
      v7 = v4->vfptr;
      if ( v5 )
      {
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v7->notify)(v6, v6, 506, 602, 0, 0);
        v2->vfptr->set_state((RGE_Action *)v2, 1);
        (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD))v7->notify)(v6, v6, 514, 602, 0, 0);
        (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      }
      break;
    case 2:
      (*(void (__stdcall **)(_DWORD))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      v8 = v2->vfptr;
      v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
      v8->set_target_obj2((RGE_Action *)v2, 0);
      LODWORD(v2->target_x) = -1082130432;
      LODWORD(v2->target_y) = -1082130432;
      LODWORD(v2->target_z) = -1082130432;
      break;
    case 0xB:
      v9 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v9 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v9,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          0.0,
          v2->task->move_sprite);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      if ( v11 )
      {
        RGE_Action::setSubAction(v11, 1);
        RGE_Action_List::add_action(v2->sub_actions, v11);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 4:
      v12 = v2->target_obj;
      if ( v12 )
      {
        v2->target_x = v12->world_x;
        v2->target_y = v12->world_y;
        v2->target_z = v12->world_z;
      }
      v13 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v13 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v13,
          v2->obj,
          v2->target_obj,
          v2->task->work_range,
          v2->task->move_sprite);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      if ( v15 )
      {
        RGE_Action_List::add_action(v2->sub_actions, v15);
        RGE_Action::setSubAction(v15, 1);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 6:
      v16 = v2->obj->vfptr;
      v17 = v2->task->move_sprite;
      goto LABEL_24;
    case 7:
      (*(void (__stdcall **)(_DWORD))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite);
      v18 = v2->task->work_sound;
      if ( v18 )
        RGE_Sound::play(v18, 1);
      break;
    case 1:
    case 0xD:
      v19 = v2->obj;
      v16 = v19->vfptr;
      v17 = v19->master_obj->sprite;
LABEL_24:
      (*(void (__stdcall **)(RGE_Sprite *))&v16->gap4[52])(v17);
      break;
    default:
      return;
  }
}

//----- (004CD5E0) --------------------------------------------------------
char __thiscall TRIBE_Action_Build::update(TRIBE_Action_Build *this)
{
  TRIBE_Action_Build *v1; // esi@1
  RGE_ActionVtbl *v2; // edi@3
  char result; // al@4
  RGE_Static_Object *v4; // ecx@8
  RGE_Action_Object *v5; // eax@12
  RGE_Static_Object *v6; // esi@12
  RGE_ActionVtbl *v7; // edi@13
  RGE_ActionVtbl *v8; // edi@19
  RGE_Static_Object *v9; // eax@24
  TRIBE_Building_Object *v10; // ecx@30
  RGE_Static_Object *v11; // eax@32
  float work; // [sp+8h] [bp-4h]@28

  v1 = this;
  if ( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
  {
    v2 = v1->vfptr;
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
    if ( v1->state != 2 )
    {
      v2->set_state((RGE_Action *)v1, 3);
      return 0;
    }
  }
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v4 = v1->target_obj;
  if ( !v4 || !v4->object_state || v1->timer != 0.0 )
    goto LABEL_41;
  if ( (double)v4->master_obj->hp > v4->hp )
  {
    RGE_Static_Object::removeAllFromPathingGroup((RGE_Static_Object *)&v1->obj->vfptr);
    v5 = v1->obj;
    v6 = v1->target_obj;
    ((void (__stdcall *)(_DWORD, int, signed int, int, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, signed int))v5->owner->vfptr->processAIOrder)(
      v5->owner->id,
      v5->id,
      718,
      v6->id,
      v6->owner->id,
      LODWORD(v6->world_x),
      LODWORD(v6->world_y),
      LODWORD(v6->world_z),
      1065353216,
      1,
      0,
      100);
    return 0;
  }
  v7 = v1->vfptr;
  v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
  if ( v1->state != 2 )
  {
    v7->set_state((RGE_Action *)v1, 3);
    result = 0;
  }
  else
  {
LABEL_41:
    switch ( v1->state )
    {
      case 0xB:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 1u:
          case 2u:
          case 5u:
            v1->vfptr->set_state((RGE_Action *)v1, 3);
            return 0;
          case 4u:
            goto LABEL_19;
          case 3u:
            goto LABEL_35;
          default:
            goto LABEL_38;
        }
        goto LABEL_38;
      case 4:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 4u:
          case 5u:
LABEL_19:
            v8 = v1->vfptr;
            v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
            v8->set_state((RGE_Action *)v1, 11);
            return 0;
          case 1u:
          case 2u:
            v1->vfptr->set_state((RGE_Action *)v1, 6);
            return 0;
          case 3u:
            goto LABEL_35;
          default:
            goto LABEL_38;
        }
        goto LABEL_38;
      case 6:
        if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                                 v1->target_obj,
                                 0,
                                 0) )
          goto LABEL_38;
        v1->vfptr->set_state((RGE_Action *)v1, 7);
        return 0;
      case 7:
        if ( v1->timer < 0.0 && (v9 = v1->target_obj) != 0 && v9->attribute_amount_held > 0.0 )
        {
          RGE_Static_Object::removeAllFromPathingGroup((RGE_Static_Object *)&v1->obj->vfptr);
          ((void (__stdcall *)(signed int))v1->obj->vfptr->setWaitingToMove)(1);
          ((void (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v1->obj->vfptr->do_command)(
            v1->target_obj,
            LODWORD(v1->target_obj->world_x),
            LODWORD(v1->target_obj->world_y),
            0);
          result = 0;
        }
        else
        {
          if ( rge_base_game->quick_build )
            work = 1000.0;
          else
            work = v1->task->work_val1
                 * *(float *)&v1->obj->master_obj[1].obj_max
                 * v1->obj->owner->world->world_time_delta_seconds;
          v10 = (TRIBE_Building_Object *)v1->target_obj;
          if ( v10 && !TRIBE_Building_Object::build(v10, work) )
          {
LABEL_38:
            result = 0;
          }
          else
          {
            v11 = v1->target_obj;
            if ( v11 && v11->master_obj->id == 50 )
            {
              LODWORD(v1->timer) = -1082130432;
              result = 0;
            }
            else
            {
LABEL_35:
              v1->vfptr->set_state((RGE_Action *)v1, 3);
              result = 0;
            }
          }
        }
        break;
      case 1:
        return 1;
      case 0xD:
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          505,
          602,
          0,
          0);
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        return 3;
      default:
        goto LABEL_38;
    }
  }
  return result;
}

//----- (004CD910) --------------------------------------------------------
int __thiscall TRIBE_Action_Build::stop(TRIBE_Action_Build *this)
{
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(2);
  return 1;
}

//----- (004CD920) --------------------------------------------------------
int __thiscall TRIBE_Action_Build::move_to(TRIBE_Action_Build *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Build *v5; // esi@1
  RGE_ActionVtbl *v6; // edi@1

  v5 = this;
  v6 = this->vfptr;
  this->target_y = y;
  this->target_x = x;
  this->target_z = z;
  ((void (__stdcall *)(_DWORD))v6->set_target_obj)(0);
  v6->set_state((RGE_Action *)v5, 11);
  return 1;
}

//----- (004CD960) --------------------------------------------------------
int __thiscall TRIBE_Action_Build::work(TRIBE_Action_Build *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Build *v5; // esi@1
  char v6; // cl@4
  RGE_ActionVtbl *v7; // edi@6
  RGE_ActionVtbl *v9; // edi@7

  v5 = this;
  if ( obj_in && obj_in->owner->id == this->obj->owner->id )
  {
    if ( obj_in != this->target_obj || (v6 = this->state, v6 != 4) && v6 != 6 )
    {
      v7 = v5->vfptr;
      v5->vfptr->set_target_obj((RGE_Action *)v5, obj_in);
      v7->set_state((RGE_Action *)v5, 4);
      return 1;
    }
  }
  else
  {
    v9 = this->vfptr;
    this->target_z = z;
    this->target_x = x;
    this->target_y = y;
    v9->set_target_obj((RGE_Action *)this, 0);
    v9->set_state((RGE_Action *)v5, 11);
  }
  return 1;
}
