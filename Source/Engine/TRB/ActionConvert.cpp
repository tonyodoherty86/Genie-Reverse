
//----- (004CD9E0) --------------------------------------------------------
void __userpurge TRIBE_Action_Convert::TRIBE_Action_Convert(TRIBE_Action_Convert *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  int v4; // edi@1
  TRIBE_Action_Convert *v5; // esi@1

  v4 = infile;
  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  LODWORD(v5->requiredRange) = 1065353216;
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Convert::`vftable';
  v5->action_type = 104;
  rge_read(a2, v4, v4, &v5->was_same_owner, 1);
  rge_read(a2, v4, v4, &v5->requiredRange, 4);
}
// 574F90: using guessed type int (__thiscall *TRIBE_Action_Convert::`vftable')(void *Memory, unsigned int __flags);

//----- (004CDA60) --------------------------------------------------------
TRIBE_Action_Convert *__thiscall TRIBE_Action_Convert::`vector deleting destructor'(TRIBE_Action_Convert *this, unsigned int __flags)
{
  TRIBE_Action_Convert *v2; // esi@1

  v2 = this;
  TRIBE_Action_Convert::~TRIBE_Action_Convert(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CDA90) --------------------------------------------------------
void __thiscall TRIBE_Action_Convert::TRIBE_Action_Convert(TRIBE_Action_Convert *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Convert *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  LODWORD(v4->requiredRange) = 1065353216;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Convert::`vftable';
  v4->action_type = 104;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  if ( target_obj_in )
  {
    v4->target_x = target_obj_in->world_x;
    v4->target_y = target_obj_in->world_y;
    v4->target_z = target_obj_in->world_z;
  }
  v4->was_same_owner = 0;
}
// 574F90: using guessed type int (__thiscall *TRIBE_Action_Convert::`vftable')(void *Memory, unsigned int __flags);

//----- (004CDB20) --------------------------------------------------------
void __thiscall TRIBE_Action_Convert::TRIBE_Action_Convert(TRIBE_Action_Convert *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Convert *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  LODWORD(v6->requiredRange) = 1065353216;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Convert::`vftable';
  v6->action_type = 104;
  v6->target_x = x;
  v6->target_z = z;
  v6->was_same_owner = 0;
}
// 574F90: using guessed type int (__thiscall *TRIBE_Action_Convert::`vftable')(void *Memory, unsigned int __flags);

//----- (004CDB70) --------------------------------------------------------
void __thiscall TRIBE_Action_Convert::save(TRIBE_Action_Convert *this, int outfile)
{
  TRIBE_Action_Convert *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->was_same_owner, 1);
  rge_write(outfile, &v2->requiredRange, 4);
}

//----- (004CDBB0) --------------------------------------------------------
void __thiscall TRIBE_Action_Convert::first_in_stack(TRIBE_Action_Convert *this, char first_time)
{
  TRIBE_Action_Convert *v2; // esi@1
  RGE_Static_Object *v3; // edx@1
  RGE_Action_Object *v4; // edi@2
  int v5; // ebx@2
  __int16 v6; // ax@5
  RGE_Player *v7; // ecx@19
  RGE_Player *v8; // ecx@25
  __int16 v9; // ax@33

  v2 = this;
  v3 = this->target_obj;
  if ( !v3 )
    goto LABEL_37;
  v4 = this->obj;
  v5 = v3->master_obj->object_group;
  this->was_same_owner = v3->owner == v4->owner;
  v6 = v3->master_obj->id;
  if ( v6 != 109 && v5 != 27 && v6 != 159 && v6 != 158 && v6 != 163 && v6 != 276 )
  {
    if ( v4->attribute_amount_held < 100.0 )
    {
      this->vfptr->set_state((RGE_Action *)this, 13);
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        118,
        v2->obj->owner->id,
        0,
        0,
        0);
      return;
    }
    if ( v5 == 3 )
      LODWORD(this->requiredRange) = 1065353216;
    else
      this->requiredRange = v4->master_obj[1].construction_radius_x;
    if ( v5 == 30 )
    {
      this->vfptr->set_state((RGE_Action *)this, 13);
      return;
    }
    if ( v5 == 18 )
    {
      v7 = v4->owner;
      if ( v7->attributes[27] <= 0.0 )
      {
        if ( RGE_Player::computerPlayer(v7) == 1 )
          v2->vfptr->set_state((RGE_Action *)v2, 11);
        else
          v2->vfptr->set_state((RGE_Action *)v2, 13);
        ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
          119,
          v2->obj->owner->id,
          0,
          0,
          0);
        return;
      }
    }
    if ( v5 == 3 )
    {
      v8 = v4->owner;
      if ( v8->attributes[28] <= 0.0 )
      {
        if ( RGE_Player::computerPlayer(v8) == 1 )
          v2->vfptr->set_state((RGE_Action *)v2, 11);
        else
          v2->vfptr->set_state((RGE_Action *)v2, 13);
        ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
          120,
          v2->obj->owner->id,
          0,
          0,
          0);
        return;
      }
    }
LABEL_37:
    if ( first_time )
    {
      if ( v3 )
        v2->vfptr->set_state((RGE_Action *)v2, 4);
      else
        v2->vfptr->set_state((RGE_Action *)v2, 3);
    }
    else
    {
      v2->vfptr->set_state((RGE_Action *)v2, 3);
    }
    return;
  }
  if ( RGE_Player::computerPlayer(v4->owner) == 1 )
    v2->vfptr->set_state((RGE_Action *)v2, 11);
  else
    v2->vfptr->set_state((RGE_Action *)v2, 13);
  v9 = v2->target_obj->master_obj->id;
  if ( v9 == 109 )
  {
    ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
      121,
      v2->obj->owner->id,
      0,
      0,
      0);
  }
  else if ( v9 == 276 )
  {
    ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
      122,
      v2->obj->owner->id,
      0,
      0,
      0);
  }
}

//----- (004CDE10) --------------------------------------------------------
void __thiscall TRIBE_Action_Convert::set_state(TRIBE_Action_Convert *this, char new_state)
{
  TRIBE_Action_Convert *v2; // esi@1
  RGE_Action_Object *v3; // ecx@3
  RGE_Static_ObjectVtbl *v4; // eax@3
  RGE_Sprite *v5; // edx@3
  RGE_Action_Move_To *v6; // eax@6
  RGE_Action *v7; // eax@7
  RGE_Action *v8; // edi@7
  RGE_Static_Object *v9; // eax@12
  RGE_Action_Move_To *v10; // eax@12
  RGE_Action *v11; // eax@13
  RGE_Action *v12; // edi@13
  RGE_Sound *v13; // ecx@19
  RGE_Static_Object *v14; // eax@21
  RGE_Player *v15; // ecx@22

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
        604,
        0,
        0);
      goto LABEL_3;
    case 1:
    case 2:
    case 0xD:
    case 0xE:
LABEL_3:
      v3 = v2->obj;
      v4 = v3->vfptr;
      v5 = v3->master_obj->sprite;
      goto LABEL_4;
    default:
      return;
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
          v2->requiredRange,
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
      break;
    case 4:
      v9 = v2->target_obj;
      v2->target_x = v9->world_x;
      v2->target_y = v9->world_y;
      v2->target_z = v9->world_z;
      v10 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v10 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(v10, v2->obj, v2->target_obj, v2->requiredRange, v2->task->move_sprite);
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
      break;
    case 6:
      v4 = v2->obj->vfptr;
      v5 = v2->task->move_sprite;
LABEL_4:
      (*(void (__stdcall **)(RGE_Sprite *))&v4->gap4[52])(v5);
      break;
    case 7:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite);
      v13 = v2->task->work_sound;
      if ( v13 )
        RGE_Sound::play(v13, 1);
      v14 = v2->target_obj;
      if ( v14 )
      {
        v15 = v14->owner;
        if ( v15->id > 0 )
          ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))v15->vfptr->make_new_object)(
            112,
            LODWORD(v2->obj->world_x),
            LODWORD(v2->obj->world_y),
            LODWORD(v2->obj->world_z),
            0);
      }
      v2->timer = v2->task->work_val2;
      break;
  }
}

//----- (004CE070) --------------------------------------------------------
char __thiscall TRIBE_Action_Convert::update(TRIBE_Action_Convert *this)
{
  TRIBE_Action_Convert *v1; // esi@1
  RGE_Static_Object *v2; // eax@6
  RGE_ActionVtbl *v3; // edi@8
  char result; // al@8
  char v5; // al@11
  RGE_ActionVtbl *v6; // edi@20
  RGE_Static_Object *v7; // eax@23
  RGE_Static_Object *v8; // edi@27
  RGE_Action_Object *v9; // edx@29
  double v10; // st7@29
  RGE_Static_Object *v11; // eax@30
  RGE_Player *v12; // ecx@31
  signed int v13; // ST30_4@33
  RGE_Static_Object *v14; // eax@33
  RGE_Player *v15; // edi@33
  double v16; // st7@33
  __int16 v17; // ax@35
  RGE_Action_Object *v18; // edx@44

  v1 = this;
  if ( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
    goto LABEL_8;
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if ( !v2 )
    goto LABEL_52;
  if ( v2->object_state != 2 )
  {
LABEL_8:
    v3 = v1->vfptr;
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
    v3->set_state((RGE_Action *)v1, 3);
    return 0;
  }
  if ( v2 && (*(int (__stdcall **)(_DWORD))&v1->obj->owner->vfptr->gap4[24])(v2->owner->id) == 1 )
  {
    v5 = v1->state;
    if ( v5 == 7 || v5 == 6 || v5 == 4 )
      ((void (__stdcall *)(signed int, _DWORD))v1->obj->vfptr->set_attribute)(34, 0);
    v1->vfptr->set_state((RGE_Action *)v1, 1);
    ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
      v1->obj->id,
      v1->obj->id,
      507,
      604,
      0,
      0);
    result = 4;
  }
  else
  {
LABEL_52:
    switch ( v1->state )
    {
      case 0xB:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 3u:
            v1->vfptr->set_state((RGE_Action *)v1, 13);
            return 0;
          case 4u:
            goto LABEL_20;
          case 1u:
          case 2u:
          case 5u:
            goto LABEL_28;
          default:
            goto LABEL_49;
        }
        goto LABEL_49;
      case 4:
        switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
        {
          case 4u:
          case 5u:
LABEL_20:
            v6 = v1->vfptr;
            v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
            v6->set_state((RGE_Action *)v1, 11);
            result = 0;
            break;
          case 3u:
            v1->vfptr->set_state((RGE_Action *)v1, 13);
            result = 0;
            break;
          case 1u:
          case 2u:
            v1->vfptr->set_state((RGE_Action *)v1, 6);
            result = 0;
            break;
          default:
            goto LABEL_49;
        }
        return result;
      case 6:
        v7 = v1->target_obj;
        if ( !v7 )
        {
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          return 0;
        }
        if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                                 v7,
                                 0,
                                 0) )
          goto LABEL_49;
        v1->vfptr->set_state((RGE_Action *)v1, 7);
        result = 0;
        break;
      case 7:
        v8 = v1->target_obj;
        if ( v8 )
        {
          ((void (__fastcall *)(RGE_Static_Object *, _DWORD, int, int, signed int, int, _DWORD, _DWORD))v8->vfptr->notify)(
            v8,
            (unsigned __int64)(signed __int64)v8->hp >> 32,
            v1->obj->id,
            v8->id,
            500,
            v1->obj->id,
            (signed __int64)v8->hp,
            v8->master_obj->hp);
          v9 = v1->obj;
          v10 = v1->timer - v9->owner->world->world_time_delta_seconds;
          v1->timer = v10;
          if ( v10 > 0.0 )
          {
LABEL_49:
            result = 0;
          }
          else
          {
            v11 = v1->target_obj;
            if ( v11 )
            {
              v12 = v11->owner;
              if ( v12->id > 0 )
                ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))v12->vfptr->make_new_object)(
                  112,
                  LODWORD(v9->world_x),
                  LODWORD(v9->world_y),
                  LODWORD(v9->world_z),
                  0);
            }
            v13 = debug_rand(aCMsdevWorkA_22, 471);
            v14 = v1->target_obj;
            v15 = v14->owner;
            v16 = (double)v13 * 0.000030518509;
            if ( v15->master_player_id == 16 )
            {
              v16 = v16 * 4.0;
            }
            else
            {
              v17 = v14->master_obj->object_group;
              if ( v17 == 21 || v17 == 2 || v17 == 20 || v17 == 22 || v17 == 18 )
              {
                v16 = v16 + v16;
              }
              else if ( v17 == 35 || v17 == 23 )
              {
                v16 = v16 * 8.0;
              }
            }
            v18 = v1->obj;
            if ( v16 <= v1->task->work_val1 * *(float *)&v18->master_obj[1].obj_max )
            {
              ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
                123,
                v18->owner->id,
                v15->id,
                0,
                0);
              ((void (__stdcall *)(RGE_Player *))v1->target_obj->vfptr->change_ownership)(v1->obj->owner);
              ((void (__stdcall *)(signed int, signed int, _DWORD))v1->obj->owner->vfptr->add_attribute_num)(
                41,
                1065353216,
                0);
              ((void (__stdcall *)(signed int, _DWORD))v1->obj->vfptr->set_attribute)(34, 0);
              v1->vfptr->set_state((RGE_Action *)v1, 3);
            }
            v1->vfptr->set_state((RGE_Action *)v1, 4);
            result = 0;
          }
        }
        else
        {
LABEL_28:
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
          604,
          0,
          0);
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        return 3;
      default:
        goto LABEL_49;
    }
  }
  return result;
}

//----- (004CE450) --------------------------------------------------------
int __thiscall TRIBE_Action_Convert::work(TRIBE_Action_Convert *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  TRIBE_Action_Convert *v5; // esi@1
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

//----- (004CE4B0) --------------------------------------------------------
void __thiscall TRIBE_Action_Convert::martyrdom(TRIBE_Action_Convert *this)
{
  TRIBE_Action_Convert *v1; // esi@1
  RGE_Static_Object *v2; // eax@2

  v1 = this;
  if ( this->state == 7 )
  {
    v2 = this->target_obj;
    if ( v2 )
    {
      if ( v2->master_obj->object_group != 18 )
      {
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
          123,
          this->obj->owner->id,
          v2->owner->id,
          0,
          0);
        ((void (__stdcall *)(_DWORD))v1->target_obj->vfptr->change_ownership)(v1->obj->owner);
        ((void (__stdcall *)(signed int, signed int, _DWORD))v1->obj->owner->vfptr->add_attribute_num)(
          41,
          1065353216,
          0);
        ((void (__stdcall *)(signed int, _DWORD))v1->obj->vfptr->set_attribute)(34, 0);
        v1->vfptr->set_state((RGE_Action *)v1, 3);
      }
    }
  }
}
