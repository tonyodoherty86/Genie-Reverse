
/**
 * @file    Engine\TRB\ActionTrade.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D2660) --------------------------------------------------------
void __userpurge TRIBE_Action_Trade::TRIBE_Action_Trade(TRIBE_Action_Trade *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  int v4; // edi@1
  TRIBE_Action_Trade *v5; // esi@1

  v4 = infile;
  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Trade::`vftable';
  rge_read(a2, v4, v4, &v5->pick_up_x, 4);
  rge_read(a2, v4, v4, &v5->pick_up_y, 4);
  v5->action_type = 111;
}
// 5752E8: using guessed type int (__thiscall *TRIBE_Action_Trade::`vftable')(void *Memory, unsigned int __flags);

//----- (004D26E0) --------------------------------------------------------
TRIBE_Action_Trade *__thiscall TRIBE_Action_Trade::`scalar deleting destructor'(TRIBE_Action_Trade *this, unsigned int __flags)
{
  TRIBE_Action_Trade *v2; // esi@1

  v2 = this;
  TRIBE_Action_Trade::~TRIBE_Action_Trade(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D2710) --------------------------------------------------------
void __thiscall TRIBE_Action_Trade::TRIBE_Action_Trade(TRIBE_Action_Trade *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Trade *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Trade::`vftable';
  v4->action_type = 111;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  v4->target_x = target_obj_in->world_x;
  v4->target_y = target_obj_in->world_y;
  v4->target_z = target_obj_in->world_z;
  LODWORD(v4->pick_up_x) = -1082130432;
  LODWORD(v4->pick_up_y) = -1082130432;
}
// 5752E8: using guessed type int (__thiscall *TRIBE_Action_Trade::`vftable')(void *Memory, unsigned int __flags);

//----- (004D27A0) --------------------------------------------------------
void __thiscall TRIBE_Action_Trade::TRIBE_Action_Trade(TRIBE_Action_Trade *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Trade *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->target_y = y;
  v6->task = task_in;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Trade::`vftable';
  LODWORD(v6->pick_up_x) = -1082130432;
  LODWORD(v6->pick_up_y) = -1082130432;
  v6->action_type = 111;
  v6->target_x = x;
  v6->target_z = z;
}
// 5752E8: using guessed type int (__thiscall *TRIBE_Action_Trade::`vftable')(void *Memory, unsigned int __flags);

//----- (004D27F0) --------------------------------------------------------
void __thiscall TRIBE_Action_Trade::save(TRIBE_Action_Trade *this, int outfile)
{
  TRIBE_Action_Trade *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->pick_up_x, 4);
  rge_write(outfile, &v2->pick_up_y, 4);
}

//----- (004D2830) --------------------------------------------------------
void __thiscall TRIBE_Action_Trade::first_in_stack(TRIBE_Action_Trade *this, char first_time)
{
  RGE_Action_Object *v2; // edx@1
  __int16 v3; // ax@1

  v2 = this->obj;
  v3 = v2->attribute_type_held;
  if ( v3 && v3 != 2 && v3 != 1 )
    v2->attribute_type_held = 1;
  if ( first_time )
  {
    if ( this->target_obj )
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(4);
    else
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(2);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
  }
}

//----- (004D2880) --------------------------------------------------------
void __thiscall TRIBE_Action_Trade::set_state(TRIBE_Action_Trade *this, char new_state)
{
  TRIBE_Action_Trade *v2; // esi@1
  RGE_Static_ObjectVtbl *v3; // edi@2
  RGE_Sprite *v4; // eax@2
  RGE_Static_ObjectVtbl *v5; // edi@3
  RGE_Sprite *v6; // eax@3
  RGE_ActionVtbl *v7; // edi@3
  RGE_Action_Move_To *v8; // edi@4
  RGE_Sprite *v9; // eax@5
  RGE_Action *v10; // eax@5
  RGE_Action *v11; // edi@5
  RGE_Static_Object *v12; // eax@10
  RGE_Action_Move_To *v13; // edi@12
  RGE_Sprite *v14; // eax@13
  RGE_Action *v15; // eax@13
  RGE_Action *v16; // edi@13
  RGE_Static_ObjectVtbl *v17; // edi@14
  RGE_Sprite *v18; // eax@14
  RGE_Sound *v19; // ecx@15
  RGE_Static_Object *v20; // eax@17
  RGE_Action_Object *v21; // ecx@20
  RGE_Static_Object *v22; // eax@21
  RGE_Master_Static_Object *v23; // eax@23
  __int16 v24; // dx@23
  RGE_ActionVtbl *v25; // edi@24
  RGE_Static_Object *v26; // eax@24
  RGE_Action_Move_To *v27; // edi@27
  RGE_Sprite *v28; // eax@28
  RGE_Action *v29; // eax@28
  RGE_Static_Object *v30; // edx@34
  RGE_ActionVtbl *v31; // edi@37

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  switch ( new_state )
  {
    case 3:
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v2->obj->vfptr->notify)(
        v2->obj->id,
        v2->obj->id,
        514,
        615,
        0,
        0);
      v3 = v2->obj->vfptr;
      v4 = TRIBE_Action_Trade::get_wait_sprite(v2);
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v3->gap4[52])(v2->obj, v4);
      break;
    case 2:
      v5 = v2->obj->vfptr;
      v6 = TRIBE_Action_Trade::get_wait_sprite(v2);
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v5->gap4[52])(v2->obj, v6);
      v7 = v2->vfptr;
      v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
      v7->set_target_obj2((RGE_Action *)v2, 0);
      LODWORD(v2->target_x) = -1082130432;
      LODWORD(v2->target_y) = -1082130432;
      LODWORD(v2->target_z) = -1082130432;
      break;
    case 0xB:
      v8 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v8 )
      {
        v9 = TRIBE_Action_Trade::get_move_sprite(v2);
        RGE_Action_Move_To::RGE_Action_Move_To(v8, v2->obj, v2->target_x, v2->target_y, v2->target_z, 0.0, v9);
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
        v13 = (RGE_Action_Move_To *)operator new(0x44u);
        if ( !v13 )
          goto LABEL_29;
        v14 = TRIBE_Action_Trade::get_move_sprite(v2);
        RGE_Action_Move_To::RGE_Action_Move_To(v13, v2->obj, v2->target_obj, v2->task->work_range, v14);
        v16 = v15;
        goto LABEL_30;
      }
      v2->vfptr->set_state((RGE_Action *)v2, 13);
      break;
    case 6:
      v17 = v2->obj->vfptr;
      v18 = TRIBE_Action_Trade::get_move_sprite(v2);
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v17->gap4[52])(v2->obj, v18);
      break;
    case 7:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite);
      v19 = v2->task->work_sound;
      if ( v19 )
        RGE_Sound::play(v19, 1);
      v20 = v2->target_obj;
      if ( v20 )
      {
        v2->pick_up_x = v20->world_x;
        v2->pick_up_y = v20->world_y;
      }
      else
      {
        LODWORD(v2->pick_up_x) = -1082130432;
        LODWORD(v2->pick_up_y) = -1082130432;
      }
      break;
    case 8:
      v21 = v2->obj;
      if ( v21->attribute_amount_held <= 0.0 )
      {
        v30 = v2->target_obj;
        if ( v30
          && v30->attribute_amount_held <= 0.0
          && !(unsigned __int8)((int (__stdcall *)(_DWORD))v21->vfptr->keepGatheringWhenObjectIsOut)(v30->master_obj->id) )
        {
          v31 = v2->vfptr;
          v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
          v31->set_state((RGE_Action *)v2, 3);
        }
      }
      else
      {
        v22 = v2->target_obj2;
        if ( !v22 || v22->master_obj->id != LOWORD(v21->master_obj[1].radius_x) )
        {
          v23 = v21->master_obj;
          v24 = LOWORD(v23[1].radius_x);
          if ( v24 == -1 )
          {
            v2->vfptr->set_target_obj2((RGE_Action *)v2, 0);
          }
          else
          {
            v25 = v2->vfptr;
            v26 = RGE_Object_List::find_by_master_ids(
                    v21->owner->objects,
                    v24,
                    HIWORD(v23[1].radius_x),
                    v21->world_x,
                    v21->world_y,
                    1,
                    2,
                    (RGE_Static_Object *)&v2->obj->vfptr);
            v25->set_target_obj2((RGE_Action *)v2, v26);
          }
        }
        if ( v2->target_obj2 )
        {
          v27 = (RGE_Action_Move_To *)operator new(0x44u);
          if ( v27 )
          {
            v28 = TRIBE_Action_Trade::get_move_sprite(v2);
            RGE_Action_Move_To::RGE_Action_Move_To(v27, v2->obj, v2->target_obj2, 0.0, v28);
            v16 = v29;
          }
          else
          {
LABEL_29:
            v16 = 0;
          }
LABEL_30:
          if ( v16 )
          {
            RGE_Action_List::add_action(v2->sub_actions, v16);
            RGE_Action::setSubAction(v16, 1);
          }
          else
          {
            v2->vfptr->set_state((RGE_Action *)v2, 13);
          }
        }
        else
        {
          ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v2->obj->vfptr->notify)(
            v2->obj->id,
            v2->obj->id,
            515,
            615,
            0,
            0);
          v2->vfptr->set_state((RGE_Action *)v2, 13);
        }
      }
      break;
    default:
      return;
  }
}

//----- (004D2CB0) --------------------------------------------------------
char __thiscall TRIBE_Action_Trade::update(TRIBE_Action_Trade *this)
{
  TRIBE_Action_Trade *v1; // esi@1
  RGE_Static_Object *v2; // eax@7
  RGE_Static_Object *v3; // eax@10
  RGE_Static_Object *v4; // edx@13
  RGE_ActionVtbl *v5; // edi@15
  char result; // al@17
  unsigned __int8 v8; // c0@20
  unsigned __int8 v9; // c3@20
  unsigned __int8 v11; // c0@25
  unsigned __int8 v12; // c3@25
  RGE_Static_Object *v13; // edx@33
  RGE_ActionVtbl *v14; // edi@35
  RGE_Action_Object *v15; // ecx@37
  __int16 v16; // ax@41
  RGE_Action_Object *v17; // eax@45
  RGE_Player *v18; // ecx@45
  double v19; // st7@45
  signed int v20; // edx@45
  float *v21; // edi@45
  double v22; // st7@45
  float *v23; // edi@45
  float *v24; // edi@47
  float v25; // ST10_4@49
  RGE_Action_Object *v26; // ecx@49
  RGE_Static_Object *v27; // edx@50
  unsigned __int8 v29; // c0@54
  unsigned __int8 v30; // c3@54
  RGE_ActionVtbl *v31; // edx@55
  RGE_Sound *v32; // ecx@60
  RGE_Static_Object *v33; // eax@64
  double v34; // st6@64
  double v35; // st7@64
  float v36; // ST24_4@64
  double v37; // st7@64
  RGE_Action_Object *v38; // edx@66
  RGE_Player *v39; // ecx@66
  RGE_Action_Object *v40; // ecx@72
  int v41; // edx@72
  float take_amount; // [sp+20h] [bp-8h]@45
  float take_amounta; // [sp+20h] [bp-8h]@70
  float max_hold; // [sp+24h] [bp-4h]@45

  v1 = this;
  if ( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if ( v2 && v2->object_state >= 7u )
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
  v3 = v1->target_obj2;
  if ( v3 && v3->object_state >= 7u )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v4 = v1->target_obj;
  if ( v4 && v1->obj->owner->id == v4->owner->id )
  {
    v5 = v1->vfptr;
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
    v5->set_target_obj2((RGE_Action *)v1, 0);
    v5->set_state((RGE_Action *)v1, 1);
    if ( !v1->subActionValue )
      ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))v1->obj->vfptr->notify)(
        v1->obj->id,
        v1->obj->id,
        507,
        615,
        v1->targetID,
        0);
    result = 4;
  }
  else
  {
    switch ( v1->state )
    {
      case 0xB:
        if ( v1->timer >= 0.0 )
        {
          switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
          {
            case 1u:
            case 2u:
            case 5u:
              goto LABEL_40;
            case 3u:
            case 4u:
              goto LABEL_57;
            default:
              goto LABEL_79;
          }
          goto LABEL_79;
        }
        v1->timer = v1->obj->owner->world->world_time_delta_seconds + v1->timer;
        if ( v8 | v9 )
          goto LABEL_79;
        LODWORD(v1->timer) = 0;
        if ( !v4 )
          goto LABEL_40;
        v1->vfptr->set_state((RGE_Action *)v1, 4);
        result = 0;
        break;
      case 4:
        if ( v1->timer >= 0.0 )
        {
          switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
          {
            case 1u:
            case 2u:
              v1->vfptr->set_state((RGE_Action *)v1, 6);
              return 0;
            case 5u:
              goto LABEL_35;
            case 3u:
            case 4u:
              goto LABEL_57;
            default:
              goto LABEL_79;
          }
          goto LABEL_79;
        }
        v1->timer = v1->obj->owner->world->world_time_delta_seconds + v1->timer;
        if ( v11 | v12 )
          goto LABEL_79;
        LODWORD(v1->timer) = 0;
        if ( !v4 )
          goto LABEL_40;
        v1->vfptr->set_state((RGE_Action *)v1, 4);
        result = 0;
        break;
      case 6:
        if ( v4 )
        {
          if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                                   v4,
                                   0,
                                   0) )
            goto LABEL_79;
          v13 = v1->target_obj;
          if ( v13->attribute_amount_held > 0.0
            || (unsigned __int8)((int (__stdcall *)(_DWORD))v1->obj->vfptr->keepGatheringWhenObjectIsOut)(v13->master_obj->id) )
          {
            v1->vfptr->set_state((RGE_Action *)v1, 7);
            result = 0;
          }
          else
          {
LABEL_35:
            v14 = v1->vfptr;
            v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
            v14->set_state((RGE_Action *)v1, 3);
            result = 0;
          }
        }
        else
        {
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          result = 0;
        }
        break;
      case 7:
        v15 = v1->obj;
        if ( v4 )
        {
          v16 = v15->attribute_type_held;
          if ( v16 && v16 != 2 && v16 != 1 )
            v15->attribute_type_held = 1;
          v17 = v1->obj;
          v20 = v17->master_obj->attribute_max_amount;
          v18 = v17->owner;
          v19 = (double)v20;
          LOWORD(v20) = v17->attribute_type_held;
          v21 = v18->attributes;
          max_hold = v19;
          take_amount = v19 - v17->attribute_amount_held;
          v22 = v21[(signed __int16)v20];
          v23 = &v21[(signed __int16)v20];
          if ( v22 < take_amount )
            take_amount = *v23;
          v24 = v1->target_obj->owner->attributes;
          if ( v24[9] < (double)take_amount )
            take_amount = v24[9];
          v25 = -take_amount;
          ((void (__stdcall *)(signed int, _DWORD, signed int))v18->vfptr->add_attribute_num)(v20, LODWORD(v25), 1);
          v1->target_obj->owner->attributes[9] = v1->target_obj->owner->attributes[9] - take_amount;
          v1->obj->attribute_amount_held = take_amount + v1->obj->attribute_amount_held;
          v26 = v1->obj;
          if ( v26->attribute_amount_held >= (double)max_hold )
          {
LABEL_76:
            v1->vfptr->set_state((RGE_Action *)v1, 8);
            result = 0;
          }
          else
          {
            v27 = v1->target_obj;
            if ( v27->owner->attributes[9] > 0.0
              || (unsigned __int8)((int (__stdcall *)(_DWORD))v26->vfptr->keepGatheringWhenObjectIsOut)(v27->master_obj->id) )
            {
              goto LABEL_79;
            }
            v1->vfptr->set_state((RGE_Action *)v1, 8);
            result = 0;
          }
        }
        else if ( v15->attribute_amount_held <= 0.0 )
        {
LABEL_40:
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          result = 0;
        }
        else
        {
          v1->vfptr->set_state((RGE_Action *)v1, 8);
          result = 0;
        }
        break;
      case 8:
        if ( v1->timer >= 0.0 )
        {
          switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
          {
            case 3u:
            case 4u:
            case 5u:
LABEL_57:
              LODWORD(v1->timer) = -1090519040;
              result = 0;
              break;
            case 1u:
            case 2u:
              if ( !v1->target_obj2 )
                goto LABEL_76;
              if ( v1->obj->attribute_amount_held > 0.0 )
              {
                v32 = v1->task->work_sound2;
                if ( v32 )
                  RGE_Sound::play(v32, 1);
                if ( v1->pick_up_x < 0.0 || v1->pick_up_y < 0.0 )
                {
                  v37 = 0.34999999;
                }
                else
                {
                  v33 = v1->target_obj2;
                  v34 = v1->pick_up_x - v33->world_x;
                  v35 = v1->pick_up_y - v33->world_y;
                  v36 = v34;
                  v37 = (v34 * v36 + v35 * v35) * 0.00025125628 * 0.69999999;
                }
                v38 = v1->obj;
                v39 = v38->owner;
                if ( v39->master_player_id == 15 )
                  v37 = v37 + v37;
                if ( v37 < 0.35 )
                  v37 = 0.34999999;
                take_amounta = v38->attribute_amount_held * v37;
                if ( take_amounta > 75.0 )
                  take_amounta = 75.0;
                ((void (__stdcall *)(signed int, float, signed int))v39->vfptr->add_attribute_num)(
                  3,
                  COERCE_FLOAT(LODWORD(take_amounta)),
                  1);
                v40 = v1->obj;
                LOWORD(v41) = v40->attribute_type_held;
                ((void (__stdcall *)(int, _DWORD))v40->vfptr->set_attribute)(v41, 0);
              }
              if ( v1->target_obj )
              {
                v1->vfptr->set_state((RGE_Action *)v1, 4);
                result = 0;
              }
              else
              {
                v1->vfptr->set_state((RGE_Action *)v1, 3);
                result = 0;
              }
              break;
            default:
              goto LABEL_79;
          }
        }
        else
        {
          v1->timer = v1->obj->owner->world->world_time_delta_seconds + v1->timer;
          if ( v29 | v30 )
            goto LABEL_79;
          v31 = v1->vfptr;
          LODWORD(v1->timer) = 0;
          v31->set_state((RGE_Action *)v1, 8);
          result = 0;
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
          615,
          0,
          0);
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        result = 3;
        break;
      default:
LABEL_79:
        result = 0;
        break;
    }
  }
  return result;
}

//----- (004D32C0) --------------------------------------------------------
RGE_Sprite *__thiscall TRIBE_Action_Trade::get_move_sprite(TRIBE_Action_Trade *this)
{
  RGE_Task *v1; // esi@1
  __int16 v2; // ax@1
  RGE_Action_Object *v3; // ecx@2
  RGE_Sprite *result; // eax@4

  v1 = this->task;
  v2 = v1->attribute_type;
  if ( v2 == -1
    || (v3 = this->obj, v3->attribute_type_held != v2)
    || (signed int)(signed __int64)v3->attribute_amount_held <= 0
    || (result = v1->carry_sprite) == 0 )
  {
    result = v1->move_sprite;
  }
  return result;
}

//----- (004D32F0) --------------------------------------------------------
RGE_Sprite *__thiscall TRIBE_Action_Trade::get_wait_sprite(TRIBE_Action_Trade *this)
{
  TRIBE_Action_Trade *v1; // esi@1
  RGE_Task *v2; // edi@1
  __int16 v3; // ax@1
  RGE_Action_Object *v4; // ecx@2
  RGE_Sprite *result; // eax@4

  v1 = this;
  v2 = this->task;
  v3 = v2->attribute_type;
  if ( v3 == -1
    || (v4 = this->obj, v3 != v4->attribute_type_held)
    || (signed int)(signed __int64)v4->attribute_amount_held <= 0
    || (result = v2->carry_sprite) == 0 )
  {
    result = v1->obj->master_obj->sprite;
  }
  return result;
}

//----- (004D3330) --------------------------------------------------------
int __thiscall TRIBE_Action_Trade::stop(TRIBE_Action_Trade *this)
{
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(2);
  return 1;
}

//----- (004D3340) --------------------------------------------------------
int __thiscall TRIBE_Action_Trade::move_to(TRIBE_Action_Trade *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Trade *v5; // esi@1
  RGE_Action_Object *v6; // ecx@2
  RGE_ActionVtbl *v7; // edi@6
  RGE_ActionVtbl *v9; // edi@7

  v5 = this;
  if ( obj_in
    && (v6 = this->obj, obj_in->owner == v6->owner)
    && obj_in->master_obj->id == LOWORD(v6->master_obj[1].radius_x) )
  {
    if ( obj_in != v5->target_obj2 || v5->state != 8 )
    {
      v7 = v5->vfptr;
      v5->vfptr->set_target_obj2((RGE_Action *)v5, obj_in);
      v7->set_state((RGE_Action *)v5, 8);
      return 1;
    }
  }
  else
  {
    v9 = v5->vfptr;
    v5->target_y = y;
    v5->target_x = x;
    v5->target_z = z;
    v9->set_target_obj((RGE_Action *)v5, 0);
    v9->set_state((RGE_Action *)v5, 11);
  }
  return 1;
}

//----- (004D33C0) --------------------------------------------------------
int __thiscall TRIBE_Action_Trade::work(TRIBE_Action_Trade *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Trade *v5; // esi@1
  char v6; // cl@3
  RGE_Action_Object *v7; // ecx@6
  RGE_ActionVtbl *v8; // edi@8
  int result; // eax@8
  RGE_ActionVtbl *v10; // edi@9
  RGE_ActionVtbl *v11; // edi@10

  v5 = this;
  if ( !obj_in )
  {
    v11 = this->vfptr;
    this->target_y = y;
    this->target_x = x;
    this->target_z = z;
    ((void (__stdcall *)(_DWORD))v11->set_target_obj)(0);
    v11->set_state((RGE_Action *)v5, 11);
    return 1;
  }
  if ( obj_in == this->target_obj )
  {
    v6 = this->state;
    if ( v6 == 4 || v6 == 6 || v6 == 7 )
      return 1;
  }
  v7 = v5->obj;
  if ( obj_in->owner != v7->owner || obj_in->master_obj->id != LOWORD(v7->master_obj[1].radius_x) )
  {
    v10 = v5->vfptr;
    v5->vfptr->set_target_obj((RGE_Action *)v5, obj_in);
    v10->set_state((RGE_Action *)v5, 4);
    result = 1;
  }
  else
  {
    v8 = v5->vfptr;
    v5->vfptr->set_target_obj2((RGE_Action *)v5, obj_in);
    v8->set_state((RGE_Action *)v5, 8);
    result = 1;
  }
  return result;
}
