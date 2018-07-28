
/**
 * @file    Engine\TRB\ActionHunt.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004CF090) --------------------------------------------------------
void __userpurge TRIBE_Action_Hunt::TRIBE_Action_Hunt(TRIBE_Action_Hunt *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Hunt *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Hunt::`vftable';
  v4->action_type = 110;
  rge_read(a2, infile, infile, &v4->targetType, 4);
}
// 5750F0: using guessed type int (__thiscall *TRIBE_Action_Hunt::`vftable')(void *Memory, unsigned int __flags);

//----- (004CF100) --------------------------------------------------------
TRIBE_Action_Hunt *__thiscall TRIBE_Action_Hunt::`vector deleting destructor'(TRIBE_Action_Hunt *this, unsigned int __flags)
{
  TRIBE_Action_Hunt *v2; // esi@1

  v2 = this;
  TRIBE_Action_Hunt::~TRIBE_Action_Hunt(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CF130) --------------------------------------------------------
void __thiscall TRIBE_Action_Hunt::TRIBE_Action_Hunt(TRIBE_Action_Hunt *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Hunt *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Hunt::`vftable';
  v4->action_type = 110;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  if ( target_obj_in )
  {
    if ( target_obj_in->object_state < 7u )
    {
      v4->target_x = target_obj_in->world_x;
      v4->target_y = target_obj_in->world_y;
      v4->target_z = target_obj_in->world_z;
      v4->targetType = target_obj_in->master_obj->id;
    }
  }
}
// 5750F0: using guessed type int (__thiscall *TRIBE_Action_Hunt::`vftable')(void *Memory, unsigned int __flags);

//----- (004CF1C0) --------------------------------------------------------
void __thiscall TRIBE_Action_Hunt::TRIBE_Action_Hunt(TRIBE_Action_Hunt *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Hunt *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Hunt::`vftable';
  v6->action_type = 110;
  v6->target_x = x;
  v6->target_z = z;
  v6->targetType = -1;
}
// 5750F0: using guessed type int (__thiscall *TRIBE_Action_Hunt::`vftable')(void *Memory, unsigned int __flags);

//----- (004CF210) --------------------------------------------------------
void __thiscall TRIBE_Action_Hunt::save(TRIBE_Action_Hunt *this, int outfile)
{
  TRIBE_Action_Hunt *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->targetType, 4);
}

//----- (004CF240) --------------------------------------------------------
void __thiscall TRIBE_Action_Hunt::first_in_stack(TRIBE_Action_Hunt *this, char first_time)
{
  TRIBE_Action_Hunt *v2; // esi@1
  RGE_Action_Object *v3; // ecx@1
  RGE_Task *v4; // eax@1
  RGE_Static_Object *v5; // ecx@4
  RGE_Action_Object *v6; // edi@5
  RGE_Master_Static_Object *v7; // eax@6
  __int16 v8; // dx@6
  RGE_ActionVtbl *v9; // edi@9

  v2 = this;
  v4 = this->task;
  v3 = this->obj;
  LOWORD(v4) = v4->attribute_type;
  if ( v3->attribute_type_held != (_WORD)v4 )
    ((void (__stdcall *)(RGE_Task *, _DWORD))v3->vfptr->set_attribute)(v4, 0);
  if ( first_time )
  {
    v5 = v2->target_obj;
    if ( v5 )
    {
      v6 = v2->obj;
      if ( v5->owner != v6->owner
        || (v7 = v6->master_obj, v8 = v5->master_obj->id, v8 != LOWORD(v7[1].radius_x)) && v8 != HIWORD(v7[1].radius_x)
        || v6->attribute_amount_held <= 0.0 )
      {
        v2->vfptr->set_state((RGE_Action *)v2, 4);
      }
      else
      {
        v9 = v2->vfptr;
        v2->vfptr->set_target_obj2((RGE_Action *)v2, v2->target_obj);
        v9->set_target_obj((RGE_Action *)v2, 0);
        LODWORD(v2->target_x) = -1082130432;
        LODWORD(v2->target_y) = -1082130432;
        LODWORD(v2->target_z) = -1082130432;
        v9->set_state((RGE_Action *)v2, 8);
      }
    }
    else
    {
      v2->vfptr->set_state((RGE_Action *)v2, 3);
    }
  }
  else
  {
    v2->vfptr->set_state((RGE_Action *)v2, 3);
  }
}

//----- (004CF300) --------------------------------------------------------
void __thiscall TRIBE_Action_Hunt::set_state(TRIBE_Action_Hunt *this, char new_state)
{
  TRIBE_Action_Hunt *v2; // esi@1
  int v3; // eax@1
  RGE_Static_ObjectVtbl *v4; // edi@2
  RGE_Sprite *v5; // eax@2
  RGE_Static_ObjectVtbl *v6; // edi@3
  RGE_Sprite *v7; // eax@3
  RGE_ActionVtbl *v8; // edi@3
  RGE_Action_Move_To *v9; // edi@4
  RGE_Sprite *v10; // eax@5
  RGE_Action *v11; // eax@5
  RGE_Action *v12; // edi@5
  RGE_Static_Object *v13; // eax@10
  RGE_Action_Move_To *v14; // edi@14
  RGE_Sprite *v15; // eax@15
  RGE_Action *v16; // eax@15
  RGE_Action *v17; // edi@15
  RGE_Action_Attack *v18; // edi@19
  RGE_Task *v19; // ecx@20
  RGE_Master_Static_Object *v20; // eax@20
  __int16 v21; // ST20_2@20
  __int16 v22; // ST1C_2@20
  float v23; // ST18_4@20
  float v24; // ST14_4@20
  RGE_Sprite *v25; // ST0C_4@20
  RGE_Sprite *v26; // eax@20
  RGE_Action *v27; // eax@20
  RGE_Static_ObjectVtbl **v28; // ecx@24
  RGE_Static_ObjectVtbl *v29; // edi@24
  RGE_Sprite *v30; // eax@24
  RGE_Task *v31; // edx@25
  RGE_Action_Object *v32; // ecx@25
  RGE_Sound *v33; // ecx@27
  RGE_Action_Object *v34; // ecx@29
  RGE_Master_Static_Object *v35; // eax@31
  __int16 v36; // dx@31
  RGE_ActionVtbl *v37; // edi@32
  RGE_Static_Object *v38; // eax@32
  RGE_Action_Move_To *v39; // edi@35
  RGE_Sprite *v40; // eax@36
  RGE_Action *v41; // eax@36
  RGE_Static_Object *v42; // eax@44
  RGE_Static_ObjectVtbl **v43; // ecx@48

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  v3 = (unsigned __int8)new_state - 1;
  switch ( new_state )
  {
    case 3:
      ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))v2->obj->vfptr->notify)(
        v2->obj->id,
        v2->obj->id,
        514,
        613,
        v2->targetType,
        0);
      v4 = v2->obj->vfptr;
      v5 = TRIBE_Action_Hunt::get_wait_sprite(v2);
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v4->gap4[52])(v2->obj, v5);
      LODWORD(v2->timer) = -1054867456;
      break;
    case 2:
      v6 = v2->obj->vfptr;
      v7 = TRIBE_Action_Hunt::get_wait_sprite(v2);
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v6->gap4[52])(v2->obj, v7);
      v8 = v2->vfptr;
      v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
      v8->set_target_obj2((RGE_Action *)v2, 0);
      LODWORD(v2->timer) = 0;
      LODWORD(v2->target_x) = -1082130432;
      LODWORD(v2->target_y) = -1082130432;
      LODWORD(v2->target_z) = -1082130432;
      break;
    case 0xB:
    case 0xF:
      LODWORD(v2->timer) = 0;
      v9 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v9 )
      {
        v10 = TRIBE_Action_Hunt::get_move_sprite(v2);
        RGE_Action_Move_To::RGE_Action_Move_To(
          v9,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          v2->task->work_range,
          v10);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( v12 )
      {
        RGE_Action::setSubAction(v12, 1);
        RGE_Action_List::add_action(v2->sub_actions, v12);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 4:
      v13 = v2->target_obj;
      LODWORD(v2->timer) = 0;
      if ( v13 )
      {
        v2->target_x = v13->world_x;
        v2->target_y = v13->world_y;
        v2->target_z = v13->world_z;
        if ( v13->object_state > 2u )
        {
          v14 = (RGE_Action_Move_To *)operator new(0x44u);
          if ( v14 )
          {
            v15 = TRIBE_Action_Hunt::get_move_sprite(v2);
            RGE_Action_Move_To::RGE_Action_Move_To(v14, v2->obj, v2->target_obj, v2->task->work_range, v15);
            v17 = v16;
          }
          else
          {
            v17 = 0;
          }
          if ( v17 )
            goto LABEL_40;
          v2->vfptr->set_state((RGE_Action *)v2, 13);
        }
        else
        {
          v2->vfptr->set_state((RGE_Action *)v2, 12);
        }
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
    case 0xC:
      LODWORD(v2->timer) = 0;
      v18 = (RGE_Action_Attack *)operator new(0x5Cu);
      if ( v18 )
      {
        v19 = v2->task;
        v20 = v2->obj->master_obj;
        v21 = HIWORD(v20[1].attribute_amount_held[0]);
        v22 = v20[1].attribute_type_held[1];
        v23 = v20[1].attribute_rot;
        v24 = v19->work_range;
        v25 = v19->work_sprite;
        v26 = TRIBE_Action_Hunt::get_move_sprite(v2);
        RGE_Action_Attack::RGE_Action_Attack(v18, v2->obj, v2->target_obj, v26, v25, 0, v24, v23, v22, v21);
        v17 = v27;
      }
      else
      {
        v17 = 0;
      }
      if ( v17 )
        goto LABEL_40;
      v2->vfptr->set_state((RGE_Action *)v2, 13);
      break;
    case 6:
      v28 = &v2->obj->vfptr;
      LODWORD(v2->timer) = 0;
      v29 = *v28;
      v30 = TRIBE_Action_Hunt::get_move_sprite(v2);
      goto LABEL_49;
    case 7:
      v31 = v2->task;
      v32 = v2->obj;
      LODWORD(v2->timer) = 0;
      LOWORD(v3) = v31->attribute_type;
      if ( v32->attribute_type_held != (_WORD)v3 )
        ((void (__stdcall *)(int, _DWORD))v32->vfptr->set_attribute)(v3, 0);
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite2);
      v33 = v2->task->work_sound;
      if ( v33 )
        RGE_Sound::play(v33, 1);
      break;
    case 8:
      v34 = v2->obj;
      if ( v34->attribute_amount_held <= 0.0 )
      {
        v42 = v2->target_obj;
        if ( v42 && v42->attribute_amount_held <= 0.0 )
          v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
        v2->vfptr->set_state((RGE_Action *)v2, 3);
      }
      else if ( v2->target_obj2
             || ((v35 = v34->master_obj, v36 = LOWORD(v35[1].radius_x), v36 == -1) ? v2->vfptr->set_target_obj2(
                                                                                       (RGE_Action *)v2,
                                                                                       0) : (v37 = v2->vfptr,
                                                                                             v38 = RGE_Object_List::find_by_master_ids(
                                                                                                     v34->owner->objects,
                                                                                                     v36,
                                                                                                     HIWORD(v35[1].radius_x),
                                                                                                     v34->world_x,
                                                                                                     v34->world_y,
                                                                                                     1,
                                                                                                     2,
                                                                                                     (RGE_Static_Object *)&v2->obj->vfptr),
                                                                                             v37->set_target_obj2(
                                                                                               (RGE_Action *)v2,
                                                                                               v38)),
                 v2->target_obj2) )
      {
        v39 = (RGE_Action_Move_To *)operator new(0x44u);
        if ( v39 )
        {
          v40 = TRIBE_Action_Hunt::get_move_sprite(v2);
          RGE_Action_Move_To::RGE_Action_Move_To(v39, v2->obj, v2->target_obj2, v2->task->work_range, v40);
          v17 = v41;
        }
        else
        {
          v17 = 0;
        }
        if ( v17 )
        {
LABEL_40:
          RGE_Action_List::add_action(v2->sub_actions, v17);
          RGE_Action::setSubAction(v17, 1);
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
          613,
          0,
          0);
        if ( RGE_Player::computerPlayer(v2->obj->owner) )
          v2->vfptr->set_state((RGE_Action *)v2, 1);
        else
          v2->vfptr->set_state((RGE_Action *)v2, 2);
      }
      break;
    case 1:
    case 0xD:
    case 0xE:
      v43 = &v2->obj->vfptr;
      LODWORD(v2->timer) = 0;
      v29 = *v43;
      v30 = TRIBE_Action_Hunt::get_wait_sprite(v2);
LABEL_49:
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v29->gap4[52])(v2->obj, v30);
      break;
    default:
      return;
  }
}

//----- (004CF860) --------------------------------------------------------
char __thiscall TRIBE_Action_Hunt::update(TRIBE_Action_Hunt *this)
{
  TRIBE_Action_Hunt *v1; // esi@1
  RGE_Static_Object *v2; // eax@7
  RGE_Static_Object *v3; // eax@10
  RGE_Action_Object *v4; // ecx@15
  unsigned __int8 v6; // c0@15
  unsigned __int8 v7; // c3@15
  RGE_Static_ObjectVtbl *v8; // edx@16
  char result; // al@16
  RGE_ActionVtbl *v10; // edi@18
  RGE_ActionVtbl *v11; // edi@30
  RGE_Static_Object *v12; // eax@34
  RGE_ActionVtbl *v13; // edi@38
  RGE_Static_Object *v14; // ecx@40
  double v15; // st7@45
  __int16 v16; // ax@49
  RGE_Action_Object *v17; // eax@52
  double v18; // st5@52
  double v19; // rt1@52
  double v20; // st5@52
  float max_hold; // ST34_4@54
  double v22; // st6@52
  double v23; // st6@53
  float v24; // ST10_4@54
  unsigned __int8 v26; // c0@58
  unsigned __int8 v27; // c3@58
  RGE_ActionVtbl *v28; // edi@59
  RGE_Action_Object *v29; // ecx@61
  RGE_Action_Object *v30; // edx@63
  RGE_Action_Object *v31; // ecx@64
  RGE_Sound *v32; // ecx@65
  __int16 v33; // ST34_2@69
  RGE_ActionVtbl *v34; // edi@70
  float give_amount; // [sp+2Ch] [bp-Ch]@52
  float modifier; // [sp+30h] [bp-8h]@50

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
  switch ( v1->state )
  {
    case 3:
      if ( v1->timer >= 0.0 )
        goto LABEL_82;
      v4 = v1->obj;
      v1->timer = v4->owner->world->world_time_delta_seconds + v1->timer;
      if ( v6 | v7 )
        goto LABEL_82;
      v8 = v4->vfptr;
      LODWORD(v1->timer) = -1054867456;
      ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))v8->notify)(
        v4->id,
        v4->id,
        514,
        613,
        v1->targetType,
        0);
      return 0;
    case 0xB:
    case 0xF:
      switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
      {
        case 4u:
          v10 = v1->vfptr;
          v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
          if ( v1->state == 11 )
          {
            v10->set_state((RGE_Action *)v1, 11);
            result = 0;
          }
          else
          {
            v10->set_state((RGE_Action *)v1, 15);
            result = 0;
          }
          break;
        case 1u:
        case 2u:
        case 5u:
          if ( v1->state != 11 )
            goto LABEL_74;
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          result = 0;
          break;
        case 3u:
          if ( RGE_Player::computerPlayer(v1->obj->owner) != 1 )
            goto LABEL_43;
          v1->vfptr->set_state((RGE_Action *)v1, 13);
          result = 0;
          break;
        default:
          goto LABEL_82;
      }
      return result;
    case 4:
      switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
      {
        case 3u:
          if ( RGE_Player::computerPlayer(v1->obj->owner) != 1 )
            goto LABEL_43;
          v1->vfptr->set_state((RGE_Action *)v1, 13);
          return 0;
        case 1u:
        case 2u:
          v1->vfptr->set_state((RGE_Action *)v1, 6);
          return 0;
        case 4u:
        case 5u:
          goto LABEL_30;
        default:
          goto LABEL_82;
      }
      goto LABEL_82;
    case 0xC:
      switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
      {
        case 4u:
LABEL_30:
          v11 = v1->vfptr;
          v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
          v11->set_state((RGE_Action *)v1, 11);
          return 0;
        case 1u:
        case 2u:
        case 5u:
          if ( !v1->target_obj )
            goto LABEL_33;
          v1->vfptr->set_state((RGE_Action *)v1, 4);
          result = 0;
          break;
        case 3u:
LABEL_33:
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          result = 0;
          break;
        default:
          goto LABEL_82;
      }
      return result;
    case 6:
      v12 = v1->target_obj;
      if ( !v12 )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 3);
        return 0;
      }
      if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                               v12,
                               0,
                               0) )
        goto LABEL_43;
      if ( v1->target_obj->attribute_amount_held > 0.0 )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 7);
        result = 0;
      }
      else
      {
        v13 = v1->vfptr;
        v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
        v13->set_state((RGE_Action *)v1, 3);
        result = 0;
      }
      return result;
    case 7:
      v14 = v1->target_obj;
      if ( !v14 )
      {
        if ( v1->obj->attribute_amount_held <= 0.0 )
        {
LABEL_43:
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          result = 0;
        }
        else
        {
          v1->vfptr->set_state((RGE_Action *)v1, 8);
          result = 0;
        }
        return result;
      }
      if ( rge_base_game->quick_build )
        v15 = v14->attribute_amount_held;
      else
        v15 = v1->task->work_val1
            * *(float *)&v1->obj->master_obj[1].obj_max
            * v1->obj->owner->world->world_time_delta_seconds;
      if ( v15 > v14->attribute_amount_held )
        v15 = v14->attribute_amount_held;
      v16 = v1->task->attribute_type2;
      if ( v16 == -1 )
        modifier = 1.0;
      else
        modifier = v1->obj->owner->attributes[v16];
      v17 = v1->obj;
      v18 = modifier * v15;
      give_amount = v18;
      v19 = v18;
      v20 = (double)v17->master_obj->attribute_max_amount * modifier;
      v22 = v20 - v17->attribute_amount_held;
      if ( v19 > v22 )
      {
        v23 = give_amount - v22;
        v15 = v15 - v23 / modifier;
        give_amount = v23;
      }
      v24 = -v15;
      ((void (__stdcall *)(_DWORD, signed int, signed int))v14->vfptr->set_attribute_amount)(LODWORD(v24), 1, 1);
      ((void (__stdcall *)(float, signed int, _DWORD))v1->obj->vfptr->set_attribute_amount)(
        COERCE_FLOAT(LODWORD(give_amount)),
        1,
        0);
      max_hold = v20;
      if ( v1->obj->attribute_amount_held >= (double)max_hold || v1->target_obj->attribute_amount_held <= 0.0 )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 8);
        return 0;
      }
      goto LABEL_82;
    case 8:
      if ( v1->timer >= 0.0 )
      {
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 3u:
          case 4u:
          case 5u:
            v29 = v1->obj;
            LODWORD(v1->timer) = -1069547520;
            (*(void (**)(void))&v29->vfptr[1].gap4[0])();
            result = 0;
            break;
          case 1u:
          case 2u:
            if ( v1->target_obj2 )
            {
              if ( RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v1->obj->vfptr, v1->target_obj2) <= 1.0 )
              {
                v32 = v1->task->work_sound2;
                if ( v32 )
                  RGE_Sound::play(v32, 1);
                LOWORD(v30) = v1->task->attribute_type3;
                if ( (_WORD)v30 == -1 )
                {
                  v30 = v1->obj;
                  LOWORD(v30) = v30->attribute_type_held;
                }
                v33 = (signed __int16)v30;
                ((void (__stdcall *)(RGE_Action_Object *, _DWORD, _DWORD))v1->obj->owner->vfptr->add_attribute_num)(
                  v30,
                  LODWORD(v1->obj->attribute_amount_held),
                  0);
                v1->obj->owner->vfptr->trackUnitGather(
                  v1->obj->owner,
                  v1->obj->id,
                  v33,
                  (signed __int64)v1->obj->attribute_amount_held);
                ((void (__stdcall *)(signed int, _DWORD))v1->obj->vfptr->set_attribute)(-1, 0);
                if ( v1->target_obj )
                {
                  v34 = v1->vfptr;
                  v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
                  v34->set_state((RGE_Action *)v1, 4);
                  result = 0;
                }
                else if ( LODWORD(v1->target_x) == -1082130432 || LODWORD(v1->target_y) == -1082130432 )
                {
LABEL_74:
                  if ( RGE_Player::computerPlayer(v1->obj->owner) )
                  {
                    v1->vfptr->set_state((RGE_Action *)v1, 1);
                    result = 0;
                  }
                  else
                  {
                    v1->vfptr->set_state((RGE_Action *)v1, 2);
                    result = 0;
                  }
                }
                else
                {
                  v1->vfptr->set_state((RGE_Action *)v1, 11);
                  result = 0;
                }
              }
              else
              {
                v31 = v1->obj;
                LODWORD(v1->timer) = -1069547520;
                (*(void (**)(void))&v31->vfptr[1].gap4[0])();
                result = 0;
              }
            }
            else
            {
              v1->vfptr->set_state((RGE_Action *)v1, 8);
              result = 0;
            }
            break;
          default:
            goto LABEL_82;
        }
      }
      else
      {
        v1->timer = v1->obj->owner->world->world_time_delta_seconds + v1->timer;
        if ( v26 | v27 )
        {
LABEL_82:
          result = 0;
        }
        else
        {
          v28 = v1->vfptr;
          LODWORD(v1->timer) = 0;
          v28->set_target_obj2((RGE_Action *)v1, 0);
          v28->set_state((RGE_Action *)v1, 8);
          result = 0;
        }
      }
      return result;
    case 1:
      if ( !RGE_Player::computerPlayer(v1->obj->owner) )
        v1->vfptr->set_state((RGE_Action *)v1, 2);
      return 1;
    case 0xD:
      v1->obj->vfptr->notify((RGE_Static_Object *)v1->obj, v1->obj->id, v1->obj->id, 505, 613, 0, 0);
      return 3;
    default:
      goto LABEL_82;
  }
}

//----- (004CFF20) --------------------------------------------------------
RGE_Sprite *__thiscall TRIBE_Action_Hunt::get_move_sprite(TRIBE_Action_Hunt *this)
{
  RGE_Task *v1; // esi@1
  __int16 v2; // ax@1
  RGE_Action_Object *v3; // ecx@2
  RGE_Sprite *result; // eax@4

  v1 = this->task;
  v2 = v1->attribute_type;
  if ( v2 == -1
    || (v3 = this->obj, v2 != v3->attribute_type_held)
    || (signed int)(signed __int64)v3->attribute_amount_held <= 0
    || (result = v1->carry_sprite) == 0 )
  {
    result = v1->move_sprite;
  }
  return result;
}

//----- (004CFF50) --------------------------------------------------------
RGE_Sprite *__thiscall TRIBE_Action_Hunt::get_wait_sprite(TRIBE_Action_Hunt *this)
{
  TRIBE_Action_Hunt *v1; // esi@1
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

//----- (004CFF90) --------------------------------------------------------
int __thiscall TRIBE_Action_Hunt::stop(TRIBE_Action_Hunt *this)
{
  TRIBE_Action_Hunt *v1; // esi@1
  int result; // eax@2

  v1 = this;
  if ( RGE_Player::computerPlayer(this->obj->owner) )
  {
    v1->vfptr->set_state((RGE_Action *)v1, 1);
    result = 1;
  }
  else
  {
    v1->vfptr->set_state((RGE_Action *)v1, 2);
    result = 1;
  }
  return result;
}

//----- (004CFFD0) --------------------------------------------------------
int __thiscall TRIBE_Action_Hunt::move_to(TRIBE_Action_Hunt *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Hunt *v5; // esi@1
  RGE_Action_Object *v6; // edx@2
  RGE_Master_Static_Object *v7; // eax@3
  __int16 v8; // cx@3
  RGE_ActionVtbl *v9; // edi@8
  RGE_ActionVtbl *v11; // edi@9

  v5 = this;
  if ( obj_in
    && (v6 = this->obj, obj_in->owner == v6->owner)
    && ((v7 = v6->master_obj, v8 = obj_in->master_obj->id, v8 == LOWORD(v7[1].radius_x)) || v8 == HIWORD(v7[1].radius_x))
    && v6->attribute_amount_held > 0.0 )
  {
    if ( obj_in != v5->target_obj2 || v5->state != 8 )
    {
      v9 = v5->vfptr;
      v5->vfptr->set_target_obj((RGE_Action *)v5, 0);
      LODWORD(v5->target_x) = -1082130432;
      LODWORD(v5->target_y) = -1082130432;
      LODWORD(v5->target_z) = -1082130432;
      v9->set_target_obj2((RGE_Action *)v5, obj_in);
      v9->set_state((RGE_Action *)v5, 8);
      return 1;
    }
  }
  else
  {
    v11 = v5->vfptr;
    v5->target_z = z;
    v5->target_x = x;
    v5->target_y = y;
    v11->set_target_obj((RGE_Action *)v5, 0);
    v11->set_state((RGE_Action *)v5, 15);
  }
  return 1;
}

//----- (004D0080) --------------------------------------------------------
int __thiscall TRIBE_Action_Hunt::work(TRIBE_Action_Hunt *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Hunt *v5; // esi@1
  RGE_Action_Object *v6; // edx@2
  RGE_Master_Static_Object *v7; // eax@3
  __int16 v8; // cx@3
  RGE_ActionVtbl *v9; // edi@6
  int result; // eax@6
  RGE_ActionVtbl *v11; // edi@7
  RGE_ActionVtbl *v12; // edi@8

  v5 = this;
  if ( obj_in )
  {
    v6 = this->obj;
    if ( obj_in->owner != v6->owner
      || (v7 = v6->master_obj, v8 = obj_in->master_obj->id, v8 != LOWORD(v7[1].radius_x))
      && v8 != HIWORD(v7[1].radius_x)
      || v6->attribute_amount_held <= 0.0 )
    {
      v11 = v5->vfptr;
      v5->vfptr->set_target_obj((RGE_Action *)v5, obj_in);
      v11->set_target_obj2((RGE_Action *)v5, 0);
      v11->set_state((RGE_Action *)v5, 4);
      result = 1;
    }
    else
    {
      v9 = v5->vfptr;
      v5->vfptr->set_target_obj((RGE_Action *)v5, 0);
      LODWORD(v5->timer) = 0;
      LODWORD(v5->target_x) = -1082130432;
      LODWORD(v5->target_y) = -1082130432;
      LODWORD(v5->target_z) = -1082130432;
      v9->set_target_obj2((RGE_Action *)v5, obj_in);
      v9->set_state((RGE_Action *)v5, 8);
      result = 1;
    }
  }
  else
  {
    v12 = this->vfptr;
    this->target_z = z;
    this->target_x = x;
    this->target_y = y;
    ((void (__stdcall *)(_DWORD))v12->set_target_obj)(0);
    v12->set_state((RGE_Action *)v5, 15);
    result = 1;
  }
  return result;
}
