
/**
 * @file    Engine\TRB\ActionRepair.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D1680) --------------------------------------------------------
void __userpurge TRIBE_Action_Repair::TRIBE_Action_Repair(TRIBE_Action_Repair *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in, int do_setup)
{
  TRIBE_Action_Repair *v5; // esi@1

  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 0);
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Repair::`vftable';
  v5->action_type = 106;
  if ( do_setup )
    TRIBE_Action_Repair::setup(v5, a2, infile, obj_in);
}
// 575208: using guessed type int (__thiscall *TRIBE_Action_Repair::`vftable')(void *Memory, unsigned int __flags);

//----- (004D16F0) --------------------------------------------------------
TRIBE_Action_Repair *__thiscall TRIBE_Action_Repair::`vector deleting destructor'(TRIBE_Action_Repair *this, unsigned int __flags)
{
  TRIBE_Action_Repair *v2; // esi@1

  v2 = this;
  TRIBE_Action_Repair::~TRIBE_Action_Repair(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D1720) --------------------------------------------------------
void __thiscall TRIBE_Action_Repair::TRIBE_Action_Repair(TRIBE_Action_Repair *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Repair *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Repair::`vftable';
  v4->action_type = 106;
  v4->save_target_command_flag = 0;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  if ( target_obj_in )
  {
    v4->target_x = target_obj_in->world_x;
    v4->target_y = target_obj_in->world_y;
    v4->target_z = target_obj_in->world_z;
    TRIBE_Action_Repair::meet_target(v4);
  }
}
// 575208: using guessed type int (__thiscall *TRIBE_Action_Repair::`vftable')(void *Memory, unsigned int __flags);

//----- (004D17B0) --------------------------------------------------------
void __thiscall TRIBE_Action_Repair::TRIBE_Action_Repair(TRIBE_Action_Repair *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Repair *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Repair::`vftable';
  v6->action_type = 106;
  v6->target_x = x;
  v6->target_z = z;
  v6->save_target_command_flag = 0;
}
// 575208: using guessed type int (__thiscall *TRIBE_Action_Repair::`vftable')(void *Memory, unsigned int __flags);

//----- (004D1800) --------------------------------------------------------
int __userpurge TRIBE_Action_Repair::setup@<eax>(TRIBE_Action_Repair *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Repair *v4; // esi@1
  int result; // eax@1
  int v6; // ebx@1

  v4 = this;
  result = RGE_Action::setup((RGE_Action *)&this->vfptr, a2, infile, obj_in);
  v6 = result;
  if ( save_game_version < 6.5 )
  {
    v4->save_target_command_flag = 0;
  }
  else
  {
    rge_read(a2, infile, infile, &v4->save_target_command_flag, 1);
    result = v6;
  }
  return result;
}
// 58EBCC: using guessed type float save_game_version;

//----- (004D1850) --------------------------------------------------------
void __thiscall TRIBE_Action_Repair::save(TRIBE_Action_Repair *this, int outfile)
{
  TRIBE_Action_Repair *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->save_target_command_flag, 1);
}

//----- (004D1880) --------------------------------------------------------
void __thiscall TRIBE_Action_Repair::first_in_stack(TRIBE_Action_Repair *this, char first_time)
{
  if ( first_time && this->target_obj )
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(4);
  else
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
}

//----- (004D18B0) --------------------------------------------------------
void __thiscall TRIBE_Action_Repair::set_state(TRIBE_Action_Repair *this, char new_state)
{
  TRIBE_Action_Repair *v2; // esi@1
  RGE_Action_Object *v3; // ecx@2
  int v4; // eax@2
  RGE_Static_ObjectVtbl *v5; // edx@2
  RGE_Action_Move_To *v6; // eax@3
  RGE_Action *v7; // eax@4
  RGE_Action *v8; // edi@4
  RGE_Static_Object *v9; // eax@9
  RGE_Action_Move_To *v10; // eax@11
  RGE_Action *v11; // eax@12
  RGE_Action *v12; // edi@12
  RGE_Static_Object *v13; // ecx@17
  __int16 v14; // ax@18
  RGE_Static_Object *v15; // eax@24
  RGE_Static_ObjectVtbl **v16; // ecx@24
  RGE_Static_ObjectVtbl *v17; // edx@24
  RGE_Sound *v18; // ecx@25
  RGE_Action_Object *v19; // ecx@28
  signed int v20; // [sp+8h] [bp-24h]@2

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  switch ( new_state )
  {
    case 3:
      v3 = v2->obj;
      v4 = v3->id;
      v5 = v3->vfptr;
      v20 = 514;
      goto LABEL_29;
    case 0xB:
      v6 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v6 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v6,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          0.0,
          v2->task->move_sprite);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      if ( v8 )
      {
        RGE_Action::setSubAction(v8, 1);
        RGE_Action_List::add_action(v2->sub_actions, v8);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      return;
    case 4:
      v9 = v2->target_obj;
      if ( v9 )
      {
        v2->target_x = v9->world_x;
        v2->target_y = v9->world_y;
        v2->target_z = v9->world_z;
      }
      v10 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v10 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v10,
          v2->obj,
          v2->target_obj,
          v2->obj->master_obj[1].construction_radius_x,
          v2->task->move_sprite);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( v12 )
      {
        RGE_Action_List::add_action(v2->sub_actions, v12);
        RGE_Action::setSubAction(v12, 1);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      return;
    case 0xA:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      v13 = v2->target_obj;
      LODWORD(v2->timer) = 1065353216;
      if ( v13 )
      {
        v14 = v13->master_obj->object_group;
        if ( (v14 == 2 || v14 == 20 || v14 == 21 || v14 == 22)
          && LOBYTE(v13[2].groupCommanderValue) == v2->save_target_command_flag )
        {
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, signed int))&v13->vfptr->gap154[0])(
            LODWORD(v2->obj->world_x),
            LODWORD(v2->obj->world_y),
            LODWORD(v2->obj->world_z),
            0,
            1);
        }
      }
      return;
    case 6:
      v15 = v2->target_obj;
      v2->target_x = v15->world_x;
      v16 = &v2->obj->vfptr;
      v2->target_y = v15->world_y;
      v17 = *v16;
      v2->target_z = v15->world_z;
      (*(void (__stdcall **)(RGE_Sprite *))&v17->gap4[52])(v2->task->move_sprite);
      return;
    case 7:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite);
      v18 = v2->task->work_sound;
      if ( v18 )
        RGE_Sound::play(v18, 1);
      return;
    case 1:
      v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
      if ( !v2->subActionValue )
      {
        v19 = v2->obj;
        v4 = v19->id;
        v5 = v19->vfptr;
        v20 = 506;
LABEL_29:
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v5->notify)(v4, v4, v20, 618, 0, 0);
      }
      goto LABEL_30;
    case 2:
LABEL_30:
      (*(void (__stdcall **)(_DWORD))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      break;
    default:
      return;
  }
}

//----- (004D1BB0) --------------------------------------------------------
char __thiscall TRIBE_Action_Repair::update(TRIBE_Action_Repair *this)
{
  TRIBE_Action_Repair *v1; // esi@1
  RGE_Static_Object *v2; // eax@6
  RGE_ActionVtbl *v3; // edi@12
  char result; // al@12
  RGE_ActionVtbl *v5; // edi@15
  long double v6; // st7@16
  RGE_Static_Object *v7; // eax@19
  RGE_Static_Object *v8; // edx@23
  float v9; // ST14_4@27
  char v10; // al@27
  long double v11; // st7@31
  RGE_Static_Object *v12; // eax@33
  RGE_Static_Object *v13; // edx@34
  RGE_Static_Object *v14; // ecx@35
  unsigned __int8 v16; // c0@35
  unsigned __int8 v17; // c3@35
  long double v18; // st7@36

  v1 = this;
  if ( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
    goto LABEL_15;
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if ( v2
    && (v2->object_state != 2 || v2 && !(*(int (__stdcall **)(_DWORD))&v1->obj->owner->vfptr->gap4[24])(v2->owner->id)) )
  {
LABEL_15:
    v5 = v1->vfptr;
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
    v5->set_state((RGE_Action *)v1, 1);
    result = 0;
  }
  else
  {
    switch ( v1->state )
    {
      case 0xB:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 4u:
            v3 = v1->vfptr;
            v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
            v3->set_state((RGE_Action *)v1, 11);
            result = 0;
            break;
          case 1u:
          case 2u:
          case 3u:
          case 5u:
            v1->vfptr->set_state((RGE_Action *)v1, 1);
            result = 0;
            break;
          default:
            goto LABEL_41;
        }
        return result;
      case 4:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 4u:
          case 5u:
            goto LABEL_15;
          case 1u:
          case 2u:
          case 3u:
            v6 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v1->obj->vfptr, v1->target_obj) - 2.0;
            distance = v6;
            if ( v6 > 0.4 )
            {
              v1->vfptr->set_state((RGE_Action *)v1, 10);
              result = 0;
            }
            else
            {
              v1->vfptr->set_state((RGE_Action *)v1, 6);
              result = 0;
            }
            return result;
          default:
            goto LABEL_41;
        }
        goto LABEL_41;
      case 6:
        v7 = v1->target_obj;
        if ( !v7 )
        {
          v1->vfptr->set_state((RGE_Action *)v1, 1);
          return 0;
        }
        if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                                 v7,
                                 0,
                                 0) )
          goto LABEL_41;
        v1->vfptr->set_state((RGE_Action *)v1, 7);
        result = 0;
        break;
      case 7:
        v8 = v1->target_obj;
        if ( v8 )
        {
          if ( v8->world_x != v1->target_x || v1->target_y != v8->world_y )
          {
            v11 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v1->obj->vfptr, v1->target_obj) - 2.0;
            distance = v11;
            if ( v11 <= 0.4 )
            {
              v12 = v1->target_obj;
              v1->target_x = v12->world_x;
              v1->target_y = v12->world_y;
              v1->target_z = v12->world_z;
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
            v9 = v1->task->work_val1
               * v1->obj->owner->world->world_time_delta_seconds
               * *(float *)&v1->obj->master_obj[1].obj_max;
            v10 = ((int (__thiscall *)(RGE_Static_Object *, _DWORD))v8->vfptr->heal)(v8, LODWORD(v9));
            if ( v10 == 1 )
            {
              v1->vfptr->set_state((RGE_Action *)v1, 1);
              result = 0;
            }
            else if ( v10 == 2 )
            {
              ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
                v1->obj->id,
                v1->obj->id,
                507,
                618,
                0,
                0);
              ((void (__stdcall *)(signed int, _DWORD, int, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
                107,
                v1->obj->owner->id,
                v1->target_obj->id,
                0,
                0);
              v1->vfptr->set_state((RGE_Action *)v1, 2);
              result = 0;
            }
            else
            {
LABEL_41:
              result = 0;
            }
          }
        }
        else
        {
          v1->vfptr->set_state((RGE_Action *)v1, 1);
          result = 0;
        }
        break;
      case 0xA:
        v13 = v1->target_obj;
        if ( !v13 )
          goto LABEL_41;
        v14 = (RGE_Static_Object *)&v1->obj->vfptr;
        v1->timer = v1->timer - v14->owner->world->world_time_delta_seconds;
        if ( !(v16 | v17) )
          goto LABEL_41;
        v18 = RGE_Static_Object::distance_to_object(v14, v13) - 2.0;
        distance = v18;
        if ( v18 > 0.4 )
        {
          LODWORD(v1->timer) = 1065353216;
          result = 0;
        }
        else
        {
          v1->vfptr->set_state((RGE_Action *)v1, 6);
          result = 0;
        }
        return result;
      case 1:
        return 1;
      case 0xD:
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          505,
          618,
          0,
          0);
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        return 3;
      default:
        goto LABEL_41;
    }
  }
  return result;
}

//----- (004D1F50) --------------------------------------------------------
int __thiscall TRIBE_Action_Repair::stop(TRIBE_Action_Repair *this)
{
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(2);
  return 1;
}

//----- (004D1F60) --------------------------------------------------------
int __thiscall TRIBE_Action_Repair::move_to(TRIBE_Action_Repair *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Repair *v5; // esi@1
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

//----- (004D1FA0) --------------------------------------------------------
int __thiscall TRIBE_Action_Repair::work(TRIBE_Action_Repair *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Repair *v5; // esi@1
  char v6; // al@3
  RGE_ActionVtbl *v7; // ebx@5
  RGE_ActionVtbl *v9; // edi@6

  v5 = this;
  if ( obj_in )
  {
    if ( obj_in != this->target_obj || (v6 = this->state, v6 != 4) && v6 != 6 )
    {
      v7 = this->vfptr;
      ((void (__stdcall *)(RGE_Static_Object *))this->vfptr->set_target_obj)(obj_in);
      v5->target_x = obj_in->world_x;
      v5->target_y = obj_in->world_y;
      v5->target_z = obj_in->world_z;
      TRIBE_Action_Repair::meet_target(v5);
      v7->set_state((RGE_Action *)v5, 4);
      return 1;
    }
  }
  else
  {
    v9 = this->vfptr;
    this->target_y = y;
    this->target_x = x;
    this->target_z = z;
    ((void (__stdcall *)(_DWORD))v9->set_target_obj)(0);
    v9->set_state((RGE_Action *)v5, 11);
  }
  return 1;
}

//----- (004D2020) --------------------------------------------------------
void __thiscall TRIBE_Action_Repair::meet_target(TRIBE_Action_Repair *this)
{
  TRIBE_Action_Repair *v1; // edi@1
  __int16 v2; // ax@1
  RGE_Object_Node *v3; // ebp@5
  RGE_Static_Object *v4; // esi@6
  RGE_Static_ObjectVtbl *v5; // ebx@8
  RGE_Action_Object *v6; // esi@11
  RGE_Static_Object *v7; // ebx@11
  RGE_Static_Object *v8; // ecx@12
  RGE_Static_ObjectVtbl *v9; // edx@12
  float v10; // ST2C_4@12
  float v11; // ST28_4@12
  RGE_Action *v12; // eax@15
  double v13; // st7@15
  RGE_Static_Object *v14; // edx@15
  RGE_Action *v15; // eax@15
  RGE_Static_Object *v16; // eax@16
  XYPoint dest; // [sp+20h] [bp-18h]@11
  XYPoint start; // [sp+28h] [bp-10h]@11
  XYPoint rVal; // [sp+30h] [bp-8h]@11

  v1 = this;
  v2 = this->target_obj->master_obj->object_group;
  if ( v2 == 2 || v2 == 20 || v2 == 21 || v2 == 22 )
  {
    v3 = this->obj->owner->objects->list;
    if ( v3 )
    {
      while ( 1 )
      {
        v4 = v3->node;
        if ( v3->node != (RGE_Static_Object *)v1->obj && v4->master_obj->id == 156 )
        {
          v5 = v4->vfptr;
          if ( v4->vfptr->get_target_obj(v3->node) == v1->target_obj && v5->actionState(v4) != 2 )
            break;
        }
        v3 = v3->next;
        if ( !v3 )
          goto LABEL_11;
      }
      if ( (unsigned __int8)((int (*)(void))v1->target_obj->vfptr->actionState)() == 11 )
      {
        v12 = RGE_Action_List::get_action((RGE_Action_List *)v1->target_obj[2].unitAIValue);
        v13 = RGE_Action::targetX(v12);
        v14 = v1->target_obj;
        v1->target_x = v13;
        v15 = RGE_Action_List::get_action((RGE_Action_List *)v14[2].unitAIValue);
        v1->target_y = RGE_Action::targetY(v15);
      }
      else
      {
        v16 = v1->target_obj;
        v1->target_x = v16->world_x;
        v1->target_y = v16->world_y;
      }
    }
    else
    {
LABEL_11:
      v6 = v1->obj;
      start.x = (signed __int64)v6->world_x;
      v7 = v1->target_obj;
      start.y = (signed __int64)v6->world_y;
      dest.x = (signed __int64)v7->world_x;
      dest.y = (signed __int64)v7->world_y;
      if ( v6->vfptr->firstTileAlongLine((RGE_Static_Object *)v6, &start, &dest, &rVal, 2, 2, 1) == 1 )
      {
        v8 = v1->target_obj;
        v9 = v8->vfptr;
        v10 = (double)rVal.x - -0.5;
        v1->target_x = v10;
        v11 = (double)rVal.y - -0.5;
        v1->target_y = v11;
        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, signed int))&v9->gap154[0])(
          LODWORD(v10),
          LODWORD(v11),
          LODWORD(v8->world_z),
          0,
          1);
        v1->save_target_command_flag = v1->target_obj[2].groupCommanderValue;
      }
    }
  }
}
