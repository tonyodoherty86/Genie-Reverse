
/**
 * @file    Engine\TRB\ActionHeal.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004CE930) --------------------------------------------------------
void __userpurge TRIBE_Action_Heal::TRIBE_Action_Heal(TRIBE_Action_Heal *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Heal *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Heal::`vftable';
  v4->action_type = 105;
}
// 575080: using guessed type int (__thiscall *TRIBE_Action_Heal::`vftable')(void *Memory, unsigned int __flags);

//----- (004CE960) --------------------------------------------------------
TRIBE_Action_Heal *__thiscall TRIBE_Action_Heal::`vector deleting destructor'(TRIBE_Action_Heal *this, unsigned int __flags)
{
  TRIBE_Action_Heal *v2; // esi@1

  v2 = this;
  TRIBE_Action_Heal::~TRIBE_Action_Heal(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CE990) --------------------------------------------------------
void __thiscall TRIBE_Action_Heal::TRIBE_Action_Heal(TRIBE_Action_Heal *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Heal *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Heal::`vftable';
  v4->action_type = 105;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  v4->target_x = target_obj_in->world_x;
  v4->target_y = target_obj_in->world_y;
  v4->target_z = target_obj_in->world_z;
}
// 575080: using guessed type int (__thiscall *TRIBE_Action_Heal::`vftable')(void *Memory, unsigned int __flags);

//----- (004CEA10) --------------------------------------------------------
void __thiscall TRIBE_Action_Heal::TRIBE_Action_Heal(TRIBE_Action_Heal *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Heal *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Heal::`vftable';
  v6->action_type = 105;
  v6->target_x = x;
  v6->target_z = z;
}
// 575080: using guessed type int (__thiscall *TRIBE_Action_Heal::`vftable')(void *Memory, unsigned int __flags);

//----- (004CEA50) --------------------------------------------------------
void __thiscall TRIBE_Action_Heal::first_in_stack(TRIBE_Action_Heal *this, char first_time)
{
  RGE_Static_Object *v2; // eax@1
  __int16 v3; // ax@2

  v2 = this->target_obj;
  if ( v2 )
  {
    v3 = v2->master_obj->object_group;
    if ( v3 != 21 && v3 != 2 && v3 != 20 && v3 != 22 )
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(4);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
  }
}

//----- (004CEA90) --------------------------------------------------------
void __thiscall TRIBE_Action_Heal::set_state(TRIBE_Action_Heal *this, char new_state)
{
  TRIBE_Action_Heal *v2; // esi@1
  RGE_Action_Move_To *v3; // eax@4
  RGE_Action *v4; // eax@5
  RGE_Action *v5; // edi@5
  RGE_Static_Object *v6; // eax@10
  RGE_Action_Move_To *v7; // eax@10
  RGE_Action *v8; // eax@11
  RGE_Action *v9; // edi@11
  RGE_Static_Object *v10; // eax@16
  RGE_Static_ObjectVtbl **v11; // ecx@16
  RGE_Static_ObjectVtbl *v12; // edx@16
  RGE_Sound *v13; // ecx@17

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  switch ( new_state )
  {
    case 3:
      ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD))v2->obj->vfptr->notify)(
        v2->obj->id,
        v2->obj->id,
        514,
        603,
        0,
        0);
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      break;
    case 2:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      break;
    case 0xB:
      v3 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v3 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v3,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          0.0,
          v2->task->move_sprite);
        v5 = v4;
      }
      else
      {
        v5 = 0;
      }
      if ( v5 )
      {
        RGE_Action::setSubAction(v5, 1);
        RGE_Action_List::add_action(v2->sub_actions, v5);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 4:
      v6 = v2->target_obj;
      v2->target_x = v6->world_x;
      v2->target_y = v6->world_y;
      v2->target_z = v6->world_z;
      v7 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v7 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(v7, v2->obj, v2->target_obj, 0.40000001, v2->task->move_sprite);
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      if ( v9 )
      {
        RGE_Action_List::add_action(v2->sub_actions, v9);
        RGE_Action::setSubAction(v9, 1);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 6:
      v10 = v2->target_obj;
      v2->target_x = v10->world_x;
      v11 = &v2->obj->vfptr;
      v2->target_y = v10->world_y;
      v12 = *v11;
      v2->target_z = v10->world_z;
      (*(void (__stdcall **)(RGE_Sprite *))&v12->gap4[52])(v2->task->move_sprite);
      break;
    case 7:
      (*(void (__stdcall **)(_DWORD))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite);
      v13 = v2->task->work_sound;
      if ( v13 )
        RGE_Sound::play(v13, 1);
      break;
    default:
      return;
  }
}

//----- (004CECF0) --------------------------------------------------------
char __thiscall TRIBE_Action_Heal::update(TRIBE_Action_Heal *this)
{
  TRIBE_Action_Heal *v1; // esi@1
  RGE_Static_Object *v2; // eax@6
  RGE_ActionVtbl *v3; // edi@8
  char result; // al@8
  RGE_ActionVtbl *v5; // edi@16
  RGE_Static_Object *v6; // eax@19
  RGE_Static_Object *v7; // ecx@23
  RGE_Action_Object *v8; // eax@27
  RGE_Player *v9; // edx@27
  double v10; // st7@27
  RGE_Game_World *v11; // eax@27
  float *v12; // edx@27
  char v13; // al@29
  long double v14; // st7@33
  RGE_Static_Object *v15; // eax@36
  float work; // [sp+8h] [bp-4h]@27

  v1 = this;
  if ( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
    goto LABEL_8;
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if ( !v2 )
    goto LABEL_42;
  if ( v2->object_state != 2 )
  {
LABEL_8:
    v3 = v1->vfptr;
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
    v3->set_state((RGE_Action *)v1, 3);
    return 0;
  }
  if ( v2 && !(*(int (__stdcall **)(_DWORD))&v1->obj->owner->vfptr->gap4[24])(v2->owner->id) )
  {
    v1->vfptr->set_state((RGE_Action *)v1, 1);
    ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
      v1->obj->id,
      v1->obj->id,
      507,
      603,
      0,
      0);
    result = 4;
  }
  else
  {
LABEL_42:
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
            goto LABEL_16;
          case 3u:
            goto LABEL_17;
          default:
            goto LABEL_39;
        }
        goto LABEL_39;
      case 4:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 4u:
          case 5u:
LABEL_16:
            v5 = v1->vfptr;
            v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
            v5->set_state((RGE_Action *)v1, 11);
            result = 0;
            break;
          case 3u:
LABEL_17:
            v1->vfptr->set_state((RGE_Action *)v1, 13);
            result = 0;
            break;
          case 1u:
          case 2u:
            v1->vfptr->set_state((RGE_Action *)v1, 6);
            result = 0;
            break;
          default:
            goto LABEL_39;
        }
        return result;
      case 6:
        v6 = v1->target_obj;
        if ( !v6 )
        {
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          return 0;
        }
        if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                                 v6,
                                 0,
                                 0) )
          goto LABEL_39;
        v1->vfptr->set_state((RGE_Action *)v1, 7);
        result = 0;
        break;
      case 7:
        v7 = v1->target_obj;
        if ( v7 )
        {
          if ( v7->world_x != v1->target_x || v1->target_y != v7->world_y )
          {
            v14 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v1->obj->vfptr, v1->target_obj);
            if ( v14 <= v1->task->work_range || v14 <= 0.5 )
            {
              v15 = v1->target_obj;
              v1->target_x = v15->world_x;
              v1->target_y = v15->world_y;
              v1->target_z = v15->world_z;
              result = 0;
            }
            else
            {
              v1->vfptr->set_state((RGE_Action *)v1, 3);
              result = 0;
            }
          }
          else
          {
            v8 = v1->obj;
            v9 = v8->owner;
            v10 = v1->task->work_val1 * *(float *)&v8->master_obj[1].obj_max;
            v11 = v9->world;
            v12 = v9->attributes;
            work = v10 * v11->world_time_delta_seconds;
            if ( v12[56] > 0.1 )
              work = work * v12[56];
            v13 = ((int (__stdcall *)(float))v7->vfptr->heal)(COERCE_FLOAT(LODWORD(work)));
            if ( v13 == 1 )
            {
              v1->vfptr->set_state((RGE_Action *)v1, 3);
              result = 0;
            }
            else if ( v13 == 2 )
            {
              ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
                v1->obj->id,
                v1->obj->id,
                507,
                603,
                0,
                0);
              v1->vfptr->set_state((RGE_Action *)v1, 2);
              result = 0;
            }
            else
            {
LABEL_39:
              result = 0;
            }
          }
        }
        else
        {
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          result = 0;
        }
        break;
      case 1:
        return 1;
      case 0xD:
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          505,
          603,
          0,
          0);
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        return 3;
      default:
        goto LABEL_39;
    }
  }
  return result;
}

//----- (004CF030) --------------------------------------------------------
int __thiscall TRIBE_Action_Heal::work(TRIBE_Action_Heal *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Heal *v5; // esi@1
  char v6; // al@3
  RGE_ActionVtbl *v8; // ebx@7

  v5 = this;
  if ( obj_in )
  {
    if ( obj_in == this->target_obj )
    {
      v6 = this->state;
      if ( v6 == 4 || v6 == 6 )
        return 1;
      if ( v6 == 7 )
        return 1;
    }
    v8 = this->vfptr;
    ((void (__stdcall *)(RGE_Static_Object *))this->vfptr->set_target_obj)(obj_in);
    v5->target_x = obj_in->world_x;
    v5->target_y = obj_in->world_y;
    v5->target_z = obj_in->world_z;
    v8->first_in_stack((RGE_Action *)v5, 1);
    return 1;
  }
  return 0;
}
