
//----- (004023C0) --------------------------------------------------------
void __userpurge RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Enter *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Enter *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Enter::`vftable';
  v4->action_type = 3;
}
// 56E140: using guessed type int (__thiscall *RGE_Action_Enter::`vftable')(void *Memory, unsigned int __flags);

//----- (004023F0) --------------------------------------------------------
RGE_Action_Enter *__thiscall RGE_Action_Enter::`scalar deleting destructor'(RGE_Action_Enter *this, unsigned int __flags)
{
  RGE_Action_Enter *v2; // esi@1

  v2 = this;
  RGE_Action_Enter::~RGE_Action_Enter(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00402410) --------------------------------------------------------
void __thiscall RGE_Action_Enter::RGE_Action_Enter(RGE_Action_Enter *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  RGE_Action_Enter *v4; // edi@1
  RGE_Static_Object *v5; // esi@1
  char (__thiscall *v6)(RGE_Static_Object *); // ebp@2
  double v7; // st7@8
  signed __int64 v8; // rax@8
  double v9; // st7@8
  signed __int64 v10; // rax@8
  double v11; // st7@8
  double v12; // st7@9
  double v13; // st7@9
  RGE_Action *v14; // eax@12
  RGE_Action *v15; // eax@12
  XYPoint dest; // [sp+14h] [bp-24h]@8
  XYPoint start; // [sp+1Ch] [bp-1Ch]@8
  XYPoint rVal; // [sp+24h] [bp-14h]@8
  int v19; // [sp+34h] [bp-4h]@1
  RGE_Action_Object *obj_ina; // [sp+3Ch] [bp+4h]@9
  RGE_Task *task_ina; // [sp+40h] [bp+8h]@9
  RGE_Static_Object *target_obj_ina; // [sp+44h] [bp+Ch]@2

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v5 = target_obj_in;
  v19 = 0;
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Enter::`vftable';
  v4->action_type = 3;
  v4->task = task_in;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  if( target_obj_in )
  {
    v4->target_x = target_obj_in->world_x;
    v4->target_y = target_obj_in->world_y;
    v4->target_z = target_obj_in->world_z;
    target_obj_ina = (RGE_Static_Object *)target_obj_in->vfptr;
    v6 = v5->vfptr->actionState;
    if( (v6(v5) != 2
       || (RGE_Static_Object::more_room(v5) != 1 || RGE_Player::computerPlayer(v4->obj->owner))
       && RGE_Player::computerPlayer(v4->obj->owner) != 1)
      && (v6(v5) != 11 || RGE_Action_List::get_action((RGE_Action_List *)v5[2].unitAIValue)->target2ID) )
    {
      if( v6(v5) == 11 )
      {
        v14 = RGE_Action_List::get_action((RGE_Action_List *)v5[2].unitAIValue);
        v4->target_x = RGE_Action::targetX(v14);
        v15 = RGE_Action_List::get_action((RGE_Action_List *)v5[2].unitAIValue);
        v4->target_y = RGE_Action::targetY(v15);
      }
    }
    else
    {
      v7 = obj_in->world_y;
      start.x = (signed __int64)obj_in->world_x;
      v8 = (signed __int64)v7;
      v9 = v5->world_x;
      start.y = v8;
      v10 = (signed __int64)v9;
      v11 = v5->world_y;
      dest.x = v10;
      dest.y = (signed __int64)v11;
      if( obj_in->vfptr->firstTileAlongLine((RGE_Static_Object *)obj_in, &start, &dest, &rVal, 2, 2, 1) == 1 )
      {
        v12 = (double)rVal.x;
        *(float *)&task_ina = v12;
        v4->target_x = v12 - -0.5;
        v13 = (double)rVal.y;
        *(float *)&obj_ina = v13;
        v4->target_y = v13 - -0.5;
        ((void (__thiscall *)(RGE_Static_Object *, RGE_Task *, RGE_Action_Object *, _DWORD, signed int, signed int))LODWORD(target_obj_ina[2].attribute_amount_held))(
          v5,
          task_ina,
          obj_ina,
          LODWORD(v5->world_z),
          1056964608,
          1);
      }
      else
      {
        v4->target_x = v5->world_x;
        v4->target_y = v5->world_y;
        ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, signed int, signed int))LODWORD(target_obj_ina[2].attribute_amount_held))(
          v5,
          LODWORD(obj_in->world_x),
          LODWORD(obj_in->world_y),
          LODWORD(v5->world_z),
          1056964608,
          1);
      }
    }
  }
}
// 56E140: using guessed type int (__thiscall *RGE_Action_Enter::`vftable')(void *Memory, unsigned int __flags);

//----- (004025F0) --------------------------------------------------------
void __thiscall RGE_Action_Enter::~RGE_Action_Enter(RGE_Action_Enter *this)
{
  this->vfptr = (RGE_ActionVtbl *)&RGE_Action_Enter::`vftable';
  RGE_Action::~RGE_Action((RGE_Action *)&this->vfptr);
}
// 56E140: using guessed type int (__thiscall *RGE_Action_Enter::`vftable')(void *Memory, unsigned int __flags);

//----- (00402600) --------------------------------------------------------
void __thiscall RGE_Action_Enter::first_in_stack(RGE_Action_Enter *this, char first_time)
{
  ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(4);
}

//----- (00402610) --------------------------------------------------------
void __thiscall RGE_Action_Enter::set_state(RGE_Action_Enter *this, char new_state)
{
  RGE_Action_Enter *v2; // esi@1
  RGE_Action_Move_To *v3; // eax@2
  RGE_Action *v4; // eax@3
  RGE_Action *v5; // edi@3

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  switch ( new_state )
  {
    case 4:
      v3 = (RGE_Action_Move_To *)operator new(0x44u);
      if( v3 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(
          v3,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          v2->task->work_range,
          v2->task->move_sprite);
        v5 = v4;
      }
      else
      {
        v5 = 0;
      }
      if( v5 )
      {
        RGE_Action_List::add_action(v2->sub_actions, v5);
        RGE_Action::setSubAction(v5, 1);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 2:
      LODWORD(v2->timer) = 1065353216;
      goto LABEL_9;
    case 1:
    case 0xD:
    case 0xE:
LABEL_9:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      break;
    default:
      return;
  }
}

//----- (00402740) --------------------------------------------------------
char __thiscall RGE_Action_Enter::update(RGE_Action_Enter *this)
{
  RGE_Action_Enter *v1; // esi@1
  RGE_Static_Object *v2; // eax@6
  RGE_ActionVtbl *v3; // edi@10
  char result; // al@10
  RGE_Static_Object *v5; // ecx@12
  RGE_ActionVtbl *v6; // edi@19
  RGE_Static_Object *v7; // ecx@20
  double v8; // st7@20
  RGE_Action_Object *v9; // edi@27
  RGE_Static_Object *v10; // ebx@27
  double v11; // st6@28
  double v12; // st5@28
  double v13; // rt1@28
  double v14; // st5@28
  double v15; // rt2@28
  double v16; // st6@28
  double v17; // st7@28
  char v19; // c3@28
  RGE_Static_Object *v20; // eax@30
  RGE_ActionVtbl *v21; // edx@30
  RGE_Static_Object *v22; // ecx@32
  RGE_Static_ObjectVtbl *v23; // edx@32
  RGE_Action *v24; // eax@34
  double v25; // st7@34
  RGE_Static_Object *v26; // ecx@34
  RGE_Action *v27; // eax@34
  float v28; // [sp+1Ch] [bp-24h]@28
  float v29; // [sp+20h] [bp-20h]@28
  float v30; // [sp+24h] [bp-1Ch]@28
  XYPoint dest; // [sp+28h] [bp-18h]@27
  XYPoint start; // [sp+30h] [bp-10h]@27
  XYPoint rVal; // [sp+38h] [bp-8h]@27

  v1 = this;
  if( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
    goto LABEL_41;
  if( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if( !v2
    || v2->object_state < 3u && (!v2 || (*(int (__stdcall **)(_DWORD))&v1->obj->owner->vfptr->gap4[24])(v2->owner->id)) )
  {
    switch ( v1->state )
    {
      case 4:
        v5 = v1->target_obj;
        if( !v5 || RGE_Static_Object::is_dying(v5) )
        {
LABEL_19:
          v6 = v1->vfptr;
          v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
          v6->set_state((RGE_Action *)v1, 13);
          result = 0;
        }
        else
        {
          switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
          {
            case 3u:
              v1->vfptr->set_state((RGE_Action *)v1, 2);
              return 0;
            case 1u:
            case 2u:
              if( RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v1->obj->vfptr, v1->target_obj) - 1.0 <= v1->task->work_range )
              {
                ((void (__stdcall *)(RGE_Static_Object *))v1->obj->vfptr->enter_obj)(v1->target_obj);
                goto LABEL_23;
              }
              v1->vfptr->set_state((RGE_Action *)v1, 2);
              result = 0;
              break;
            case 4u:
            case 5u:
              goto LABEL_19;
            default:
              goto LABEL_38;
          }
        }
        break;
      case 2:
        v7 = (RGE_Static_Object *)&v1->obj->vfptr;
        v8 = v1->timer - v7->owner->world->world_time_delta_seconds;
        v1->timer = v8;
        if( v8 > 0.0 )
          goto LABEL_38;
        if( RGE_Static_Object::distance_to_object(v7, v1->target_obj) - 1.0 > v1->task->work_range )
        {
          if( (unsigned __int8)((int (*)(void))v1->target_obj->vfptr->actionState)() == 2 )
          {
            v9 = v1->obj;
            start.x = (signed __int64)v9->world_x;
            v10 = v1->target_obj;
            start.y = (signed __int64)v9->world_y;
            dest.x = (signed __int64)v10->world_x;
            dest.y = (signed __int64)v10->world_y;
            if( v9->vfptr->firstTileAlongLine((RGE_Static_Object *)v9, &start, &dest, &rVal, 2, 2, 1) == 1 )
            {
              v11 = (double)rVal.x;
              v30 = v11;
              v12 = (double)rVal.y;
              v29 = v12;
              v13 = v12 - -0.5;
              v14 = v1->target_x;
              v15 = v11 - -0.5;
              v16 = v13;
              v17 = v15;
              v28 = v13;
              if( v19 && v16 == v1->target_y )
              {
                v20 = v1->target_obj;
                v1->target_x = v20->world_x;
                v21 = v1->vfptr;
                v1->target_y = v20->world_y;
                v21->set_state((RGE_Action *)v1, 4);
                result = 0;
              }
              else
              {
                v1->target_x = v17;
                v1->target_y = v28;
                (*(void (__stdcall **)(float, float, _DWORD, _DWORD, signed int))&v1->target_obj->vfptr->gap154[0])(
                  COERCE_FLOAT(LODWORD(v30)),
                  COERCE_FLOAT(LODWORD(v29)),
                  LODWORD(v1->target_obj->world_z),
                  0,
                  1);
                v1->vfptr->set_state((RGE_Action *)v1, 4);
                result = 0;
              }
            }
            else
            {
              v22 = v1->target_obj;
              v1->target_x = v22->world_x;
              v23 = v22->vfptr;
              v1->target_y = v22->world_y;
              (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, signed int, signed int))&v23->gap154[0])(
                LODWORD(v1->obj->world_x),
                LODWORD(v1->obj->world_y),
                LODWORD(v22->world_z),
                1056964608,
                1);
              v1->vfptr->set_state((RGE_Action *)v1, 4);
              result = 0;
            }
          }
          else
          {
            if( (unsigned __int8)((int (*)(void))v1->target_obj->vfptr->actionState)() == 11 )
            {
              v24 = RGE_Action_List::get_action((RGE_Action_List *)v1->target_obj[2].unitAIValue);
              v25 = RGE_Action::targetX(v24);
              v26 = v1->target_obj;
              v1->target_x = v25;
              v27 = RGE_Action_List::get_action((RGE_Action_List *)v26[2].unitAIValue);
              v1->target_y = RGE_Action::targetY(v27);
            }
            v1->vfptr->set_state((RGE_Action *)v1, 4);
            result = 0;
          }
        }
        else
        {
          ((void (__stdcall *)(RGE_Static_Object *))v1->obj->vfptr->enter_obj)(v1->target_obj);
LABEL_23:
          if( !v1->subActionValue )
            ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
              v1->obj->id,
              v1->obj->id,
              506,
              617,
              0,
              0);
          v1->vfptr->set_state((RGE_Action *)v1, 1);
          result = 2;
        }
        break;
      case 1:
        result = 1;
        break;
      case 0xD:
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          505,
          617,
          0,
          0);
        result = 3;
        break;
      default:
LABEL_38:
        result = 0;
        break;
    }
  }
  else
  {
LABEL_41:
    v3 = v1->vfptr;
    v1->vfptr->set_state((RGE_Action *)v1, 1);
    v3->set_target_obj((RGE_Action *)v1, 0);
    ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
      v1->obj->id,
      v1->obj->id,
      507,
      617,
      0,
      0);
    result = 4;
  }
  return result;
}
