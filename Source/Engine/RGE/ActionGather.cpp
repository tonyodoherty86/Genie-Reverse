
/**
 * @file    Engine\RGE\ActionGather.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00402EA0) --------------------------------------------------------
void __userpurge RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Gather *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Gather *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Gather::`vftable';
  v4->action_type = 5;
  rge_read(a2, infile, infile, &v4->targetType, 4);
}
// 56E218: using guessed type int (__thiscall *RGE_Action_Gather::`vftable')(void *Memory, unsigned int __flags);

//----- (00402F10) --------------------------------------------------------
RGE_Action_Gather *__thiscall RGE_Action_Gather::`vector deleting destructor'(RGE_Action_Gather *this, unsigned int __flags)
{
  RGE_Action_Gather *v2; // esi@1

  v2 = this;
  RGE_Action_Gather::~RGE_Action_Gather(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00402F40) --------------------------------------------------------
void __thiscall RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Gather *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  RGE_Action_Gather *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Gather::`vftable';
  v4->action_type = 5;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  if( target_obj_in )
  {
    v4->target_x = target_obj_in->world_x;
    v4->target_y = target_obj_in->world_y;
    v4->target_z = target_obj_in->world_z;
    v4->targetType = target_obj_in->master_obj->id;
  }
}
// 56E218: using guessed type int (__thiscall *RGE_Action_Gather::`vftable')(void *Memory, unsigned int __flags);

//----- (00402FD0) --------------------------------------------------------
void __thiscall RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Gather *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  RGE_Action_Gather *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&RGE_Action_Gather::`vftable';
  v6->action_type = 5;
  v6->target_x = x;
  v6->target_z = z;
  v6->targetType = -1;
}
// 56E218: using guessed type int (__thiscall *RGE_Action_Gather::`vftable')(void *Memory, unsigned int __flags);

//----- (00403020) --------------------------------------------------------
void __thiscall RGE_Action_Gather::save(RGE_Action_Gather *this, int outfile)
{
  RGE_Action_Gather *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->targetType, 4);
}

//----- (00403050) --------------------------------------------------------
void __thiscall RGE_Action_Gather::first_in_stack(RGE_Action_Gather *this, char first_time)
{
  RGE_Action_Gather *v2; // esi@1
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
  if( v3->attribute_type_held != (_WORD)v4 )
    ((void (__stdcall *)(RGE_Task *, _DWORD))v3->vfptr->set_attribute)(v4, 0);
  if( first_time )
  {
    v5 = v2->target_obj;
    if( v5 )
    {
      v6 = v2->obj;
      if( v5->owner != v6->owner
        || (v7 = v6->master_obj, v8 = v5->master_obj->id, v8 != LOWORD(v7[1].radius_x)) && v8 != HIWORD(v7[1].radius_x)
        || v6->attribute_amount_held <= 0.0 )
      {
        set_state((RGE_Action *)v2, 4);
      }
      else
      {
        v9 = v2->vfptr;
        set_target_obj2((RGE_Action *)v2, v2->target_obj);
        v9->set_target_obj((RGE_Action *)v2, 0);
        LODWORD(v2->target_x) = -1082130432;
        LODWORD(v2->target_y) = -1082130432;
        LODWORD(v2->target_z) = -1082130432;
        v9->set_state((RGE_Action *)v2, 8);
      }
    }
    else
    {
      set_state((RGE_Action *)v2, 3);
    }
  }
  else
  {
    set_state((RGE_Action *)v2, 3);
  }
}

//----- (00403110) --------------------------------------------------------
void __thiscall RGE_Action_Gather::set_state(RGE_Action_Gather *this, char new_state)
{
  RGE_Action_Gather *v2; // esi@1
  int v3; // eax@1
  RGE_Static_ObjectVtbl **v4; // ecx@3
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
  RGE_Static_ObjectVtbl **v17; // eax@14
  RGE_Static_ObjectVtbl *v18; // edi@14
  RGE_Sprite *v19; // eax@14
  RGE_Task *v20; // ecx@15
  RGE_Action_Object *v21; // ecx@15
  RGE_Sound *v22; // ecx@17
  RGE_Action_Object *v23; // ecx@19
  char v24; // al@22
  RGE_ActionVtbl *v25; // edi@22
  bool v26; // zf@22
  RGE_Action_Object *v27; // eax@22
  RGE_Master_Static_Object *v28; // ecx@22
  RGE_Static_Object *v29; // eax@23
  RGE_Static_Object *v30; // eax@24
  RGE_Action_Move_To *v31; // edi@27
  RGE_Sprite *v32; // eax@28
  RGE_Action *v33; // eax@28
  RGE_Static_Object *v34; // edx@34

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v2->state = new_state;
  v3 = (unsigned __int8)new_state - 1;
  switch ( new_state )
  {
    case Search:
      ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))v2->obj->vfptr->notify)(
        v2->obj->id,
        v2->obj->id,
        514,
        609,
        v2->targetType,
        0);
      LODWORD(v2->timer) = -1054867456;
      goto LABEL_40;
    case Wait:
      v4 = &v2->obj->vfptr;
      LODWORD(v2->timer) = 0;
      v5 = *v4;
      v6 = RGE_Action_Gather::get_wait_sprite(v2);
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v5->gap4[52])(v2->obj, v6);
      set_target_obj((RGE_Action *)v2, 0);
      set_target_obj2((RGE_Action *)v2, 0);
      LODWORD(v2->target_x) = -1082130432;
      LODWORD(v2->target_y) = -1082130432;
      LODWORD(v2->target_z) = -1082130432;
      return;
    case Move:
    case Attack:
      LODWORD(v2->timer) = 0;
      v8 = (RGE_Action_Move_To *)operator new(0x44u);
      if( v8 )
      {
        v9 = RGE_Action_Gather::get_move_sprite(v2);
        RGE_Action_Move_To::RGE_Action_Move_To(
          v8,
          v2->obj,
          v2->target_x,
          v2->target_y,
          v2->target_z,
          v2->task->work_range,
          v9);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      if( v11 )
      {
        RGE_Action::setSubAction(v11, 1);
        RGE_Action_List::add_action(v2->sub_actions, v11);
      }
      else
      {
        set_state((RGE_Action *)v2, Failed);
      }
      return;
    case Goto:
      v12 = v2->target_obj;
      LODWORD(v2->timer) = 0;
      if( !v12 )
      {
        set_state((RGE_Action *)v2, Failed);
        return;
      }
      v2->target_x = v12->world_x;
      v2->target_y = v12->world_y;
      v2->target_z = v12->world_z;
      v13 = (RGE_Action_Move_To *)operator new(0x44u);
      if( !v13 )
        goto LABEL_29;
      v14 = RGE_Action_Gather::get_move_sprite(v2);
      RGE_Action_Move_To::RGE_Action_Move_To(v13, v2->obj, v2->target_obj, v2->task->work_range, v14);
      v16 = v15;
      goto LABEL_30;
    case Work:
      v17 = &v2->obj->vfptr;
      LODWORD(v2->timer) = 0;
      v18 = *v17;
      v19 = RGE_Action_Gather::get_move_sprite(v2);
      goto LABEL_41;
    case Work2:
      v20 = v2->task;
      LODWORD(v2->timer) = 0;
      LOWORD(v3) = v20->attribute_type;
      v21 = v2->obj;
      if( v21->attribute_type_held != (_WORD)v3 )
        ((void (__stdcall *)(int, _DWORD))v21->vfptr->set_attribute)(v3, 0);
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->task->work_sprite);
      v22 = v2->task->work_sound;
      if( v22 )
        RGE_Sound::play(v22, 1);
      return;
    case Return:
      v23 = v2->obj;
      if( v23->attribute_amount_held <= 0.0 )
      {
        v34 = v2->target_obj;
        if( v34
          && v34->attribute_amount_held <= 0.0
          && !(unsigned __int8)((int (__stdcall *)(_DWORD))v23->vfptr->keepGatheringWhenObjectIsOut)(v34->master_obj->id) )
        {
          set_target_obj((RGE_Action *)v2, 0);
        }
        set_state((RGE_Action *)v2, Search);
      }
      else if( v2->target_obj2
             || (LOWORD(v23->master_obj[1].radius_x) == -1 ? set_target_obj2((RGE_Action *)v2, 0) : (v24 = ((int (*)(void))v23->vfptr->useSameZoneDropsite)(), v25 = v2->vfptr, v26 = v24 == 1, v27 = v2->obj, v28 = v27->master_obj, !v26) ? (v30 = RGE_Object_List::find_by_master_ids(v27->owner->objects, LOWORD(v28[1].radius_x), HIWORD(v28[1].radius_x), v27->world_x, v27->world_y, 1, 2, 0), v25->set_target_obj2((RGE_Action *)v2, v30)) : (v29 = RGE_Object_List::find_by_master_ids(v27->owner->objects, LOWORD(v28[1].radius_x), HIWORD(v28[1].radius_x), v27->world_x, v27->world_y, 1, 2, (RGE_Static_Object *)&v2->obj->vfptr), v25->set_target_obj2((RGE_Action *)v2, v29)),
                 v2->target_obj2) )
      {
        v31 = (RGE_Action_Move_To *)operator new(0x44u);
        if( v31 )
        {
          v32 = RGE_Action_Gather::get_move_sprite(v2);
          RGE_Action_Move_To::RGE_Action_Move_To(v31, v2->obj, v2->target_obj2, v2->task->work_range, v32);
          v16 = v33;
        }
        else
        {
LABEL_29:
          v16 = 0;
        }
LABEL_30:
        if( v16 )
        {
          RGE_Action_List::add_action(v2->sub_actions, v16);
          RGE_Action::setSubAction(v16, 1);
        }
        else
        {
          set_state((RGE_Action *)v2, Failed);
        }
      }
      else
      {
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v2->obj->vfptr->notify)(
          v2->obj->id,
          v2->obj->id,
          515,
          609,
          0,
          0);
        set_state((RGE_Action *)v2, Failed);
      }
      return;
    case Done:
    case Failed:
    case Invalidated:
      LODWORD(v2->timer) = 0;
LABEL_40:
      v18 = v2->obj->vfptr;
      v19 = RGE_Action_Gather::get_wait_sprite(v2);
LABEL_41:
      (*(void (__thiscall **)(RGE_Action_Object *, RGE_Sprite *))&v18->gap4[52])(v2->obj, v19);
      return;
    default:
      return;
  }
}

//----- (00403590) --------------------------------------------------------
char __thiscall RGE_Action_Gather::update(RGE_Action_Gather *this)
{
  RGE_Action_Gather *v1; // esi@1
  RGE_Static_Object *v2; // eax@7
  RGE_Static_Object *v3; // eax@10
  RGE_Static_Object *v4; // ecx@13
  __int16 v5; // ax@14
  char result; // al@16
  RGE_Action_Object *v7; // ecx@19
  unsigned __int8 v9; // c0@19
  unsigned __int8 v10; // c3@19
  RGE_Static_ObjectVtbl *v11; // edx@20
  RGE_ActionVtbl *v12; // edi@22
  RGE_Player *v13; // ecx@25
  RGE_ActionVtbl *v14; // edi@29
  RGE_Static_Object *v15; // edx@37
  RGE_ActionVtbl *v16; // edi@39
  double v17; // st7@46
  __int16 v18; // ax@50
  RGE_Action_Object *v19; // eax@53
  double v20; // st5@53
  double v21; // rt1@53
  double v22; // st5@53
  float max_hold; // ST34_4@55
  double v24; // st6@53
  double v25; // st6@54
  float v26; // ST10_4@55
  RGE_Action_Object *v27; // ecx@55
  RGE_Static_Object *v28; // edx@56
  unsigned __int8 v30; // c0@60
  unsigned __int8 v31; // c3@60
  RGE_ActionVtbl *v32; // edx@61
  RGE_Action_Object *v33; // ecx@63
  RGE_Action_Object *v34; // ecx@66
  RGE_Sound *v35; // ecx@67
  RGE_Task *v36; // edx@69
  __int16 v37; // ST34_2@71
  RGE_ActionVtbl *v38; // edi@72
  float give_amount; // [sp+2Ch] [bp-Ch]@53
  float modifier; // [sp+30h] [bp-8h]@51

  v1 = this;
  if( this->targetID != -1 && !RGE_Game_World::object(this->obj->owner->world, this->targetID) )
    set_target_obj((RGE_Action *)v1, 0);
  if( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    set_target_obj2((RGE_Action *)v1, 0);
  v2 = v1->target_obj;
  if( v2 && v2->object_state >= 7u )
    set_target_obj((RGE_Action *)v1, 0);
  v3 = v1->target_obj2;
  if( v3 && v3->object_state >= 7u )
    set_target_obj2((RGE_Action *)v1, 0);
  v4 = v1->target_obj;
  if( v4 && (v5 = v4->owner->id) != 0 && v5 != v1->obj->owner->id )
  {
    set_state((RGE_Action *)v1, Done);
    v1->obj->vfptr->notify((RGE_Static_Object *)v1->obj, v1->obj->id, v1->obj->id, 507, 609, 0, 0);
    result = 4;
  }
  else
  {
    switch ( this->state )
    {
      case 3:
        if( this->timer >= 0.0 )
          goto LABEL_84;
        this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
        if( v9 | v10 )
          goto LABEL_84;
        LODWORD(this->timer) = -1054867456;
        this->obj->notify(
          this->obj->id,
          this->obj->id,
          514,
          609,
          this->targetType,
          0);
        return 0;
      case 0xB:
      case 0xF:
        switch (sub_actions->update() )
        {
          case 4u:
            v12 = v1->vfptr;
            set_target_obj((RGE_Action *)v1, 0);
            if( this->state == 11 )
            {
              v12->set_state((RGE_Action *)this, Move);
              result = 0;
            }
            else
            {
              v12->set_state((RGE_Action *)this, MoveNoSearch);
              result = 0;
            }
            return result;
          case 3u:
            v13 = this->obj->owner;
            goto LABEL_31;
          case 1u:
          case 2u:
          case 5u:
            if( this->state != 11 )
              goto LABEL_76;
            set_state((RGE_Action *)this, Search);
            return 0;
          default:
            goto LABEL_84;
        }
        goto LABEL_84;
      case 4:
        switch (sub_actions->vfptr->update() )
        {
          case 4u:
          case 5u:
            set_target_obj((RGE_Action *)this, 0);
            set_state((RGE_Action *)this, Move);
            result = 0;
            break;
          case 3u:
            v13 = this->obj->owner;
LABEL_31:
            if( RGE_Player::computerPlayer(v13) != 1 )
              goto LABEL_44;
            set_state((RGE_Action *)this, Failed);
            result = 0;
            break;
          case 1u:
          case 2u:
            set_state((RGE_Action *)this, Work);
            result = 0;
            break;
          default:
            goto LABEL_84;
        }
        return result;
      case 6:
        if( !v4 )
        {
          set_state((RGE_Action *)this, Search);
          return 0;
        }
        if( !(unsigned __int8)(*(int (__thiscall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD))&v1->obj->vfptr[1].gap4[4])(
                                 this->obj,
                                 v4,
                                 0,
                                 0) )
          goto LABEL_84;
        v15 = this->target_obj;
        if( v15->attribute_amount_held > 0.0
          || (unsigned __int8)(obj->keepGatheringWhenObjectIsOut(target_obj->master_obj->id) )
        {
          set_state((RGE_Action *)this, Work2);
          result = 0;
        }
        else
        {
          set_target_obj((RGE_Action *)this, 0);
          set_state((RGE_Action *)this, Search);
          result = 0;
        }
        return result;
      case 7:
        if( !v4 )
        {
          if( this->obj->attribute_amount_held <= 0.0 )
          {
LABEL_44:
            set_state((RGE_Action *)this, Search);
            result = 0;
          }
          else
          {
            set_state((RGE_Action *)this, Return);
            result = 0;
          }
          return result;
        }
        if( rge_base_game->quick_build )
          v17 = v4->attribute_amount_held;
        else
          v17 = this->task->work_val1
              * (float)this->obj->master_obj[1].obj_max
              * this->obj->owner->world->world_time_delta_seconds;
        if( v17 > v4->attribute_amount_held )
          v17 = v4->attribute_amount_held;
        v18 = this->task->attribute_type2;
        if( v18 == -1 )
          modifier = 1.0;
        else
          modifier = v1->obj->owner->attributes[v18];
        v19 = this->obj;
        v20 = modifier * v17;
        give_amount = v20;
        v21 = v20;
        v22 = (double)obj->master_obj->attribute_max_amount * modifier;
        v24 = v22 - obj->attribute_amount_held;
        if( v21 > v24 )
        {
          v25 = give_amount - v24;
          v17 = v17 - v25 / modifier;
          give_amount = v25;
        }
        v26 = -v17;
        ((void (__stdcall *)(_DWORD, signed int, signed int))v4->vfptr->set_attribute_amount)(LODWORD(v26), 1, 1);
        (this->obj->set_attribute_amount(
          COERCE_FLOAT(LODWORD(give_amount)),
          1,
          0);
        v27 = this->obj;
        max_hold = v22;
        if( v27->attribute_amount_held >= (double)max_hold
          || (v28 = this->target_obj, v28->attribute_amount_held <= 0.0)
          && !this->obj->keepGatheringWhenObjectIsOut(v28->master_obj->id) )
        {
          set_state((RGE_Action *)this, Return);
          return 0;
        }
        goto LABEL_84;
      case 8:
        if( this->timer >= 0.0 )
        {
          switch ( this->sub_actions->update() )
          {
            case 3u:
            case 4u:
            case 5u:
              v33 = v1->obj;
              LODWORD(this->timer) = -1069547520;
              (*(void (**)(void))&v33->vfptr[1].gap4[0])();
              result = 0;
              break;
            case 1u:
            case 2u:
              if( this->target_obj2 )
              {
                if( this->obj->distance_to_object(this->target_obj2) <= 1.0 )
                {
                  if( this->task->work_sound2 )
                    RGE_Sound::play(this->task_work_sound2, 1);
                  v36 = this->task;
                  LOWORD(v36) = v36->attribute_type3;
                  if( (_WORD)v36 == -1 )
                    LOWORD(v36) = this->obj->attribute_type_held;
                  v37 = (signed __int16)v36;
                  this->obj->owner->add_attribute_num(
                    v36,
                    LODWORD(this->obj->attribute_amount_held),
                    1);
                  this->obj->owner->trackUnitGather(
                    this->obj->owner,
                    this->obj->id,
                    v37,
                    this->obj->attribute_amount_held);
                  this->obj->set_attribute(-1, 0);
                  if( this->target_obj )
                  {
                    set_target_obj2((RGE_Action *)this, 0);
                    this->set_state((RGE_Action *)this, Goto);
                    result = 0;
                  }
                  else if( LODWORD(this->target_x) == -1082130432 || LODWORD(this->target_y) == -1082130432 )
                  {
LABEL_76:
                    if( RGE_Player::computerPlayer(this->obj->owner) == 1 )
                    {
                      set_state((RGE_Action *)this, Done);
                      result = 0;
                    }
                    else
                    {
                      set_state((RGE_Action *)this, Wait);
                      result = 0;
                    }
                  }
                  else
                  {
                    set_state((RGE_Action *)this, Move);
                    result = 0;
                  }
                }
                else
                {
                  v34 = this->obj;
                  LODWORD(this->timer) = -1069547520;
                  (*(void (**)(void))&v34->vfptr[1].gap4[0])();
                  result = 0;
                }
              }
              else
              {
                set_state((RGE_Action *)this, Return);
                result = 0;
              }
              break;
            default:
              goto LABEL_84;
          }
        }
        else
        {
          this->timer = this->obj->owner->world->world_time_delta_seconds + this->timer;
          if( v30 | v31 )
          {
LABEL_84:
            result = 0;
          }
          else
          {
            LODWORD(this->timer) = 0;
            this->set_state((RGE_Action *)this, Return);
            result = 0;
          }
        }
        break;
      case 1:
        return 1;
      case 0xD:
        this->obj->notify(
          this->obj->id,
          this->obj->id,
          505,
          609,
          0,
          0);
        if( RGE_Player::computerPlayer(this->obj->owner) == 1 )
        {
          set_state((RGE_Action *)this, Done);
          result = 3;
        }
        else
        {
          set_state((RGE_Action *)this, Wait);
          result = 3;
        }
        return result;
      default:
        goto LABEL_84;
    }
  }
  return result;
}

//----- (00403C60) --------------------------------------------------------
RGE_Sprite *__thiscall RGE_Action_Gather::get_move_sprite(RGE_Action_Gather *this)
{
  RGE_Task *v1; // esi@1
  __int16 v2; // ax@1
  RGE_Action_Object *v3; // ecx@2
  RGE_Sprite *result; // eax@4

  if( task->attribute_type == -1
    || (v3 = this->obj, v3->attribute_type_held != task->attribute_type)
    || (signed int)(signed __int64)v3->attribute_amount_held <= 0
    || (result = this->task->carry_sprite) == 0 )
  {
    result = this->task->move_sprite;
  }
  return result;
}

//----- (00403C90) --------------------------------------------------------
RGE_Sprite *__thiscall RGE_Action_Gather::get_wait_sprite(RGE_Action_Gather *this)
{
  RGE_Action_Gather *v1; // esi@1
  RGE_Task *v2; // edi@1
  __int16 v3; // ax@1
  RGE_Action_Object *v4; // ecx@2
  RGE_Sprite *result; // eax@4

  v2 = this->task;
  v3 = v2->attribute_type;
  if( v3 == -1
    || (v4 = this->obj, v3 != v4->attribute_type_held)
    || (signed int)(signed __int64)v4->attribute_amount_held <= 0
    || (result = v2->carry_sprite) == 0 )
  {
    result = this->obj->master_obj->sprite;
  }
  return result;
}

//----- (00403CD0) --------------------------------------------------------
int __thiscall RGE_Action_Gather::stop(RGE_Action_Gather *this)
{
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(2);
  return 1;
}

//----- (00403CE0) --------------------------------------------------------
int __thiscall RGE_Action_Gather::move_to(RGE_Action_Gather *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  RGE_Action_Gather *v5; // esi@1
  RGE_Action_Object *v6; // edx@2
  RGE_Master_Static_Object *v7; // eax@3
  RGE_ActionVtbl *v9; // edi@8
  RGE_ActionVtbl *v11; // edi@9

  v5 = this;
  int16_t obj_in_id = obj_in->master_obj_id;
  if( obj_in &&
    && (obj_in->owner == this->obj->owner)
    && ((obj_in_id == LOWORD(this->obj_master_obj[1].radius_x)) || obj_in_id == HIWORD(this->obj_master_obj[1].radius_x))
    && this->obj->attribute_amount_held > 0.0 )
  {
    if( obj_in != this->target_obj2 || this->state != Return )
    {
      this->set_target_obj((RGE_Action *)this, nullptr);
      LODWORD(this->target_x) = -1082130432;
      LODWORD(this->target_y) = -1082130432;
      LODWORD(this->target_z) = -1082130432;
      this->set_target_obj2((RGE_Action *)this, obj_in);
      this->set_state((RGE_Action *)this, Return);
      return 1;
    }
  }
  else
  {
    v5->target_z = z;
    v5->target_x = x;
    v5->target_y = y;
    this->set_target_obj((RGE_Action *)this, 0);
    this->set_state((RGE_Action *)this, 15);
  }
  return 1;
}

//----- (00403D90) --------------------------------------------------------
int __thiscall RGE_Action_Gather::work(RGE_Action_Gather *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  RGE_Master_Static_Object *v8; // eax@7
  __int16 v9; // cx@7
  int result; // eax@10
  RGE_ActionVtbl *v12; // ebx@11
  RGE_ActionVtbl *v13; // edi@12

  if( !obj_in )
  {
    v13 = this->vfptr;
    this->target_z = z;
    this->target_x = x;
    this->target_y = y;
    ((void (__stdcall *)(_DWORD))v13->set_target_obj)(0);
    v13->set_state((RGE_Action *)this, 15);
    return 1;
  }
  if( obj_in == this->target_obj )
  {
    char v6 = this->state;
    if( v6 == 4 || v6 == 6 || v6 == 7 )
      return 1;
  }
  if( obj_in->owner != this->obj->owner
    || (v8 = this->obj->master_obj, v9 = obj_in->master_obj->id, v9 != LOWORD(v8[1].radius_x)) && v9 != HIWORD(v8[1].radius_x)
    || this->obj->attribute_amount_held <= 0.0 )
  {
    this->set_target_obj((RGE_Action *)this, obj_in);
    this->target_x = obj_in->world_x;
    this->target_y = obj_in->world_y;
    this->target_z = obj_in->world_z;
    this->set_target_obj2((RGE_Action *)this, 0);
    this->set_state((RGE_Action *)this, 4);
    result = 1;
  }
  else
  {
    LODWORD(this->timer) = 0;
    this->set_target_obj((RGE_Action *)this, 0);
    LODWORD(this->target_x) = -1082130432;
    LODWORD(this->target_y) = -1082130432;
    LODWORD(this->target_z) = -1082130432;
    this->set_target_obj2((RGE_Action *)this, obj_in);
    this->set_state((RGE_Action *)this, 8);
    result = 1;
  }
  return result;
}
