
//----- (00401000) --------------------------------------------------------
void __userpurge RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Attack *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  int v4; // edi@1
  RGE_Action_Attack *v5; // esi@1

  v4 = infile;
  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v5->vfptr = (RGE_ActionVtbl *)&RGE_Action_Attack::`vftable';
  v5->action_type = 9;
  rge_read(a2, v4, v4, &v5->range, 4);
  rge_read(a2, v4, v4, &v5->min_range, 4);
  rge_read(a2, v4, v4, &v5->missile_id, 2);
  rge_read(a2, v4, v4, &v5->fire_missile_at_frame, 2);
  rge_read(a2, v4, v4, &v5->need_to_attack, 1);
  rge_read(a2, v4, v4, &v5->was_same_owner, 1);
  rge_read(a2, v4, v4, &v5->indirect_fire_flag, 1);
  rge_read(a2, v4, v4, &obj_in, 2);
  v5->move_sprite = RGE_Static_Object::get_sprite_pointer((RGE_Static_Object *)&v5->obj->vfptr, (__int16)obj_in);
  rge_read(a2, v4, v4, &obj_in, 2);
  v5->fight_sprite = RGE_Static_Object::get_sprite_pointer((RGE_Static_Object *)&v5->obj->vfptr, (__int16)obj_in);
  rge_read(a2, v4, v4, &obj_in, 2);
  v5->wait_sprite = RGE_Static_Object::get_sprite_pointer((RGE_Static_Object *)&v5->obj->vfptr, (__int16)obj_in);
}
// 56E058: using guessed type int (__thiscall *RGE_Action_Attack::`vftable')(void *Memory, unsigned int __flags);

//----- (00401130) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Action::get_target_obj(RGE_Action *this)
{
  return this->target_obj;
}

//----- (00401140) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Action::get_target_obj2(RGE_Action *this)
{
  return this->target_obj2;
}

//----- (00401150) --------------------------------------------------------
RGE_Action_Attack *__thiscall RGE_Action_Attack::`vector deleting destructor'(RGE_Action_Attack *this, unsigned int __flags)
{
  RGE_Action_Attack *v2; // esi@1

  v2 = this;
  RGE_Action_Attack::~RGE_Action_Attack(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00401170) --------------------------------------------------------
void __thiscall RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Attack *this, RGE_Action_Object *obj_in, RGE_Static_Object *target_obj_in, RGE_Sprite *move_sprite_in, RGE_Sprite *fight_sprite_in, RGE_Sprite *wait_sprite_in, float range_in, float min_range_in, __int16 missile_id_in, __int16 fire_missile_at_frame_in)
{
  RGE_Action_Attack *v10; // esi@1
  RGE_Master_Static_Object *v11; // eax@6
  RGE_Sprite *v12; // ecx@6
  char v14; // c3@14

  v10 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v10->vfptr = (RGE_ActionVtbl *)&RGE_Action_Attack::`vftable';
  v10->action_type = 9;
  RGE_Action::set_target_obj((RGE_Action *)&v10->vfptr, target_obj_in);
  v10->wait_sprite = wait_sprite_in;
  v10->range = range_in;
  v10->min_range = min_range_in;
  v10->missile_id = missile_id_in;
  LODWORD(v10->target_x) = -1082130432;
  LODWORD(v10->target_y) = -1082130432;
  LODWORD(v10->target_z) = -1082130432;
  v10->move_sprite = move_sprite_in;
  v10->fight_sprite = fight_sprite_in;
  v10->fire_missile_at_frame = fire_missile_at_frame_in;
  v10->need_to_attack = 0;
  v10->indirect_fire_flag = 0;
  v10->was_same_owner = target_obj_in && target_obj_in->owner == obj_in->owner;
  if ( !move_sprite_in )
  {
    v11 = v10->obj->master_obj;
    v12 = (RGE_Sprite *)v11[1].name;
    if ( !v12 )
      v12 = *(RGE_Sprite **)&v11[1].master_type;
    v10->move_sprite = v12;
  }
  if ( !fight_sprite_in )
    v10->fight_sprite = (RGE_Sprite *)v10->obj->master_obj[1].death_sound;
  if ( !wait_sprite_in )
    v10->wait_sprite = v10->obj->master_obj->sprite;
  if ( range_in == 0.0 )
  {
    v10->range = v10->obj->master_obj[1].construction_radius_x;
    if ( v14 )
      LODWORD(v10->range) = 1053609165;
  }
}
// 56E058: using guessed type int (__thiscall *RGE_Action_Attack::`vftable')(void *Memory, unsigned int __flags);

//----- (004012B0) --------------------------------------------------------
void __thiscall RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Attack *this, RGE_Action_Object *obj_in, float x, float y, float z, RGE_Sprite *move_sprite_in, RGE_Sprite *fight_sprite_in, RGE_Sprite *wait_sprite_in, float range_in, float min_range_in, __int16 missile_id_in, __int16 fire_missile_at_frame_in)
{
  RGE_Action_Attack *v12; // esi@1
  RGE_Master_Static_Object *v13; // eax@2
  RGE_Sprite *v14; // ecx@2
  char v16; // c3@10

  v12 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v12->target_x = x;
  v12->range = range_in;
  v12->min_range = min_range_in;
  v12->target_z = z;
  v12->target_y = y;
  v12->missile_id = missile_id_in;
  v12->vfptr = (RGE_ActionVtbl *)&RGE_Action_Attack::`vftable';
  v12->action_type = 9;
  v12->move_sprite = move_sprite_in;
  v12->fight_sprite = fight_sprite_in;
  v12->wait_sprite = wait_sprite_in;
  v12->fire_missile_at_frame = fire_missile_at_frame_in;
  v12->need_to_attack = 0;
  v12->was_same_owner = 0;
  v12->indirect_fire_flag = 2;
  if ( !move_sprite_in )
  {
    v13 = v12->obj->master_obj;
    v14 = (RGE_Sprite *)v13[1].name;
    if ( !v14 )
      v14 = *(RGE_Sprite **)&v13[1].master_type;
    v12->move_sprite = v14;
  }
  if ( !fight_sprite_in )
    v12->fight_sprite = (RGE_Sprite *)v12->obj->master_obj[1].death_sound;
  if ( !wait_sprite_in )
    v12->wait_sprite = v12->obj->master_obj->sprite;
  if ( range_in == 0.0 )
  {
    v12->range = v12->obj->master_obj[1].construction_radius_x;
    if ( v16 )
      LODWORD(v12->range) = 1053609165;
  }
}
// 56E058: using guessed type int (__thiscall *RGE_Action_Attack::`vftable')(void *Memory, unsigned int __flags);

//----- (004013A0) --------------------------------------------------------
void __thiscall RGE_Action_Attack::~RGE_Action_Attack(RGE_Action_Attack *this)
{
  this->vfptr = (RGE_ActionVtbl *)&RGE_Action_Attack::`vftable';
  RGE_Action::~RGE_Action((RGE_Action *)&this->vfptr);
}
// 56E058: using guessed type int (__thiscall *RGE_Action_Attack::`vftable')(void *Memory, unsigned int __flags);

//----- (004013B0) --------------------------------------------------------
void __thiscall RGE_Action_Attack::save(RGE_Action_Attack *this, int outfile)
{
  int v2; // edi@1
  RGE_Action_Attack *v3; // esi@1
  int v4; // ecx@1
  RGE_Sprite *v5; // eax@1
  int v6; // eax@4
  int v7; // edx@7
  RGE_Sprite *v8; // esi@7

  v2 = outfile;
  v3 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(v2, &v3->range, 4);
  rge_write(v2, &v3->min_range, 4);
  rge_write(v2, &v3->missile_id, 2);
  rge_write(v2, &v3->fire_missile_at_frame, 2);
  rge_write(v2, &v3->need_to_attack, 1);
  rge_write(v2, &v3->was_same_owner, 1);
  rge_write(v2, &v3->indirect_fire_flag, 1);
  v5 = v3->move_sprite;
  if ( v5 )
  {
    LOWORD(v4) = v5->id;
    outfile = v4;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v6 = (int)v3->fight_sprite;
  if ( v6 )
  {
    LOWORD(v6) = *(_WORD *)(v6 + 114);
    outfile = v6;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v8 = v3->wait_sprite;
  if ( v8 )
  {
    LOWORD(v7) = v8->id;
    outfile = v7;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
}

//----- (004014B0) --------------------------------------------------------
void __userpurge RGE_Action_Attack::first_in_stack(RGE_Action_Attack *this@<ecx>, double a2@<st0>, char first_time)
{
  RGE_Action_Attack *v3; // esi@1
  UnitAIModule *v4; // eax@3
  int rangeStatus; // [sp+4h] [bp-4h]@5

  v3 = this;
  ((void (*)(void))this->obj->vfptr->maximumSpeed)();
  if ( a2 == 0.0
    || RGE_Static_Object::unitAI((RGE_Static_Object *)&v3->obj->vfptr)
    && (v4 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v3->obj->vfptr), UnitAIModule::currentOrder(v4) == 725) )
  {
    rangeStatus = -1;
    if ( RGE_Action_Attack::ready_to_attack(v3, &rangeStatus) || rangeStatus == 1 )
      v3->vfptr->set_state((RGE_Action *)v3, 6);
    else
      v3->vfptr->set_state((RGE_Action *)v3, 13);
  }
  else
  {
    v3->vfptr->set_state((RGE_Action *)v3, 4);
  }
}

//----- (00401540) --------------------------------------------------------
int __thiscall RGE_Action_Attack::stop(RGE_Action_Attack *this)
{
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(1);
  return 1;
}

//----- (00401550) --------------------------------------------------------
void __thiscall RGE_Action_Attack::set_state(RGE_Action_Attack *this, char new_state)
{
  RGE_Action_Attack *v2; // esi@1
  char v3; // al@1
  char v4; // al@3
  RGE_Action_Move_To *v5; // eax@6
  RGE_Action *v6; // eax@7
  RGE_Action_Move_To *v7; // eax@8
  RGE_Action *v8; // edi@11
  RGE_Static_ObjectVtbl *v9; // eax@21
  RGE_Sprite *v10; // edx@22

  v2 = this;
  RGE_Action_List::delete_list(this->sub_actions);
  v3 = new_state;
  v2->state = new_state;
  switch ( v3 )
  {
    case 2:
      v2->indirect_fire_flag = 0;
      return;
    case 4:
      v4 = v2->indirect_fire_flag;
      if ( v4 )
        v2->indirect_fire_flag = v4 - 1;
      if ( v2->target_obj )
      {
        v5 = (RGE_Action_Move_To *)operator new(0x44u);
        *(_DWORD *)&new_state = v5;
        if ( v5 )
        {
          RGE_Action_Move_To::RGE_Action_Move_To(v5, v2->obj, v2->target_obj, v2->range, v2->move_sprite);
          goto LABEL_11;
        }
      }
      else
      {
        v7 = (RGE_Action_Move_To *)operator new(0x44u);
        *(_DWORD *)&new_state = v7;
        if ( v7 )
        {
          RGE_Action_Move_To::RGE_Action_Move_To(
            v7,
            v2->obj,
            v2->target_x,
            v2->target_y,
            v2->target_z,
            v2->range,
            v2->move_sprite);
          goto LABEL_11;
        }
      }
      v6 = 0;
LABEL_11:
      v8 = v6;
      if ( v6 )
      {
        RGE_Action_List::add_action(v2->sub_actions, v6);
        RGE_Action::setSubAction(v8, 1);
        LODWORD(v2->timer) = 0;
      }
      else
      {
        if ( !v2->subActionValue )
          ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int, RGE_Action *, RGE_Action *))v2->obj->vfptr->notify)(
            v2->obj->id,
            v2->obj->id,
            505,
            610,
            v6,
            v6);
        v2->vfptr->set_state((RGE_Action *)v2, 1);
      }
      return;
    case 6:
      if ( v2->indirect_fire_flag && v2->target_obj )
        v2->indirect_fire_flag = 0;
      *(_DWORD *)&new_state = -1;
      if ( !RGE_Action_Attack::ready_to_attack(v2, (int *)&new_state) )
      {
        v9 = v2->obj->vfptr;
        if ( v2->missile_id != -1 )
          goto LABEL_25;
        v10 = v2->fight_sprite;
        goto LABEL_26;
      }
      RGE_Combat_Object::reset_attack_timer((RGE_Combat_Object *)v2->obj);
      v2->vfptr->set_state((RGE_Action *)v2, 7);
      return;
    case 7:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->fight_sprite);
      v2->need_to_attack = 1;
      return;
    case 1:
    case 0xD:
    case 0xE:
      v9 = v2->obj->vfptr;
LABEL_25:
      v10 = v2->wait_sprite;
LABEL_26:
      (*(void (__stdcall **)(RGE_Sprite *))&v9->gap4[52])(v10);
      return;
    default:
      return;
  }
}

//----- (00401780) --------------------------------------------------------
char __thiscall RGE_Action_Attack::update(RGE_Action_Attack *this)
{
  RGE_Action_Attack *v1; // esi@1
  RGE_Action_Object *v2; // eax@1
  int v3; // ecx@1
  RGE_Static_Object *v4; // eax@6
  RGE_ActionVtbl *v5; // edi@8
  char result; // al@8
  RGE_Player *v7; // ecx@10
  RGE_Static_Object *v8; // eax@14
  signed __int64 v9; // rax@17
  void (__thiscall *v10)(RGE_Action *, char); // edi@35
  char v11; // al@35
  RGE_ActionVtbl *v12; // edi@50
  int rangeStatus; // [sp+8h] [bp-4h]@28

  v1 = this;
  v2 = this->obj;
  v3 = this->targetID;
  v1->timer = v2->owner->world->world_time_delta_seconds + v1->timer;
  if ( v3 != -1 && !RGE_Game_World::object(v2->owner->world, v3) )
    goto LABEL_8;
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v4 = v1->target_obj;
  if ( v4 )
  {
    if ( v4->object_state >= 3u )
    {
LABEL_8:
      v5 = v1->vfptr;
      v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
      v5->set_state((RGE_Action *)v1, 2);
      return 5;
    }
    if ( v4 )
    {
      v7 = v1->obj->owner;
      if ( v7->id )
      {
        if ( (*(int (__stdcall **)(_DWORD))&v7->vfptr->gap4[24])(v4->owner->id) )
        {
          v1->vfptr->set_state((RGE_Action *)v1, 1);
          if ( v1->subActionValue )
            return 4;
LABEL_25:
          ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))v1->obj->vfptr->notify)(
            v1->obj->id,
            v1->obj->id,
            507,
            600,
            v1->targetID,
            0);
          return 4;
        }
      }
    }
  }
  v8 = v1->target_obj;
  if ( v8 && v8->inside_obj )
  {
    v1->vfptr->set_state((RGE_Action *)v1, 1);
LABEL_24:
    if ( v1->subActionValue )
      return 4;
    goto LABEL_25;
  }
  LODWORD(v9) = v1->state - 1;
  switch ( v1->state )
  {
    case 4:
      switch ( (unsigned __int8)((int (*)(void))v1->sub_actions->vfptr->update)() )
      {
        case 3u:
          v1->vfptr->set_state((RGE_Action *)v1, 13);
          if ( !v1->subActionValue )
            goto LABEL_20;
          return 3;
        case 4u:
          v1->vfptr->set_state((RGE_Action *)v1, 14);
          goto LABEL_24;
        case 1u:
        case 2u:
          v1->vfptr->set_state((RGE_Action *)v1, 6);
          return 0;
        default:
          return 0;
      }
      return 0;
    case 0xD:
LABEL_20:
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
        v1->obj->id,
        v1->obj->id,
        505,
        600,
        0,
        0);
      return 3;
    default:
      return 0;
    case 6:
      rangeStatus = -1;
      if ( !RGE_Action_Attack::ready_to_attack(v1, &rangeStatus) )
        return 0;
      RGE_Combat_Object::reset_attack_timer((RGE_Combat_Object *)v1->obj);
      v1->vfptr->set_state((RGE_Action *)v1, 7);
      return 0;
    case 7:
      if ( v1->need_to_attack )
        goto LABEL_45;
      LODWORD(v9) = ((int (*)(void))v1->obj->vfptr->can_attack)();
      if ( (_BYTE)v9 != 1 )
        goto LABEL_38;
      if ( !v1->target_obj && !v1->indirect_fire_flag )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        return 0;
      }
      RGE_Combat_Object::reset_attack_timer((RGE_Combat_Object *)v1->obj);
      v10 = v1->vfptr->set_state;
      v10((RGE_Action *)&v1->vfptr, 6);
      v11 = v1->state;
      if ( v11 == 13 || v11 == 4 )
        return 0;
      LODWORD(v9) = ((int (__thiscall *)(RGE_Action_Attack *, signed int))v10)(v1, 7);
LABEL_38:
      if ( v1->need_to_attack )
      {
LABEL_45:
        LOWORD(v9) = v1->fire_missile_at_frame;
        if ( !(_WORD)v9 )
        {
          rangeStatus = v1->obj->sprite->frame_num;
          v9 = (signed __int64)((double)rangeStatus * 0.5);
        }
        if ( (unsigned __int8)((int (__stdcall *)(RGE_Sprite *, _DWORD))v1->obj->sprite_list->vfptr->frame_passed)(
                                v1->obj->sprite,
                                v9) )
        {
          RGE_Action_Attack::do_attack(v1);
          return 0;
        }
        return 0;
      }
      if ( (unsigned __int8)((int (__stdcall *)(RGE_Sprite *))v1->obj->sprite_list->vfptr->looped)(v1->obj->sprite) != 1
        && v1->obj->sprite->flag & 1 )
      {
        return 0;
      }
      if ( v1->target_obj || v1->indirect_fire_flag )
      {
        v1->vfptr->set_state((RGE_Action *)v1, 6);
        result = 0;
      }
      else
      {
        v1->vfptr->set_state((RGE_Action *)v1, 2);
        result = 0;
      }
      return result;
    case 2:
      if ( (unsigned __int8)((int (__stdcall *)(RGE_Sprite *))v1->obj->sprite_list->vfptr->looped)(v1->obj->sprite) != 1 )
        return 0;
      v12 = v1->vfptr;
      v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
      if ( !v1->subActionValue )
        ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
          v1->obj->id,
          v1->obj->id,
          506,
          600,
          0,
          0);
      v12->set_state((RGE_Action *)v1, 1);
      return v1->subActionValue != 1 ? 2 : 5;
    case 1:
      return 1;
  }
}

//----- (00401AD0) --------------------------------------------------------
int __thiscall RGE_Action_Attack::work(RGE_Action_Attack *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  RGE_Action_Attack *v5; // esi@1
  char v6; // cl@3
  RGE_ActionVtbl *v8; // edi@7

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
    v8 = v5->vfptr;
    v5->indirect_fire_flag = 0;
    v8->set_target_obj((RGE_Action *)v5, obj_in);
    v8->set_state((RGE_Action *)v5, 4);
    return 1;
  }
  return 0;
}

//----- (00401B30) --------------------------------------------------------
int __thiscall RGE_Action_Attack::ready_to_attack(RGE_Action_Attack *this, int *rangeState)
{
  RGE_Action_Attack *v2; // esi@1
  RGE_Static_Object *v4; // edi@3
  long double v5; // st7@4
  RGE_Master_Static_Object *v6; // eax@6
  long double v7; // st5@6
  long double v8; // st7@6
  float v9; // ST24_4@6
  __int16 v10; // ax@9
  char v11; // al@11
  RGE_Static_Object *v12; // edx@16
  unsigned __int8 v14; // c0@19
  unsigned __int8 v15; // c3@19
  RGE_Master_Static_Object *v16; // eax@25
  float v17; // et1@25
  long double v19; // st6@25
  char v20; // c0@25
  UnitAIModule *v21; // eax@31
  long double v22; // rt2@34
  long double v23; // st6@34
  UnitAIModule *v24; // eax@40
  RGE_Static_Object *v25; // eax@44
  float y_change; // [sp+Ch] [bp-8h]@19
  float z_change; // [sp+10h] [bp-4h]@19

  v2 = this;
  if ( !(unsigned __int8)(*(int (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD))&this->obj->vfptr[1].gap4[4])(
                           v2->target_obj,
                           LODWORD(v2->target_x),
                           LODWORD(this->target_y)) )
    return 0;
  v4 = v2->target_obj;
  if ( v4 )
  {
    if ( v4->owner->id > 0 )
    {
      v10 = v4->master_obj->object_group;
      if ( v10 != 3 && v10 != 27 )
      {
        v11 = RGE_Visible_Map::get_visible(
                v2->obj->owner->visible,
                (signed __int64)v4->world_x,
                (signed __int64)v4->world_y);
        if ( !v11 )
        {
          v2->vfptr->set_state((RGE_Action *)v2, 13);
          return 0;
        }
        if ( v11 == -128 && !v2->target_obj->master_obj->fog_flag )
        {
          v2->vfptr->set_state((RGE_Action *)v2, 13);
          return 0;
        }
      }
    }
    v12 = v2->target_obj;
    if ( v12->world_x != v2->target_x || v12->world_y != v2->target_y || v12->world_z != v2->target_z )
    {
      y_change = v12->world_y - v2->target_y;
      z_change = v12->world_z - v2->target_z;
      if ( !(v14 | v15)
        || v12->world_x - v2->target_x < -0.5
        || y_change > 0.5
        || y_change < -0.5
        || z_change > 0.5
        || z_change < -0.5 )
      {
        v5 = RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v2->obj->vfptr, v12);
        v16 = v2->obj->master_obj;
        v17 = v2->min_range;
        v19 = sqrt(v16->radius_x * v16->radius_x + v16->radius_y * v16->radius_y) + v2->range - -0.30000001;
        if ( v20 )
        {
          *rangeState = 0;
          goto LABEL_27;
        }
        v22 = v19;
        v23 = v5;
        v8 = v22;
        if ( v23 > v22 )
        {
          *rangeState = 2;
          goto LABEL_36;
        }
        v25 = v2->target_obj;
        v2->target_x = v25->world_x;
        v2->target_y = v25->world_y;
        v2->target_z = v25->world_z;
      }
    }
  }
  else
  {
    v5 = RGE_Static_Object::distance_to_position(
           (RGE_Static_Object *)&v2->obj->vfptr,
           v2->target_x,
           v2->target_y,
           v2->target_z);
    if ( v5 < v2->min_range )
    {
      *rangeState = 0;
LABEL_27:
      if ( !v2->subActionValue )
        ((void (__stdcall *)(int, int, signed int, _DWORD, _DWORD, _DWORD))v2->obj->vfptr->notify)(
          v2->obj->id,
          v2->obj->id,
          510,
          0,
          0,
          0);
      ((void (*)(void))v2->obj->vfptr->maximumSpeed)();
      if ( v5 == 0.0 )
      {
LABEL_33:
        v2->vfptr->set_state((RGE_Action *)v2, 13);
        return 0;
      }
      if ( RGE_Static_Object::unitAI((RGE_Static_Object *)&v2->obj->vfptr) )
      {
        v21 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v2->obj->vfptr);
        if ( UnitAIModule::currentOrder(v21) != 725 )
          return 0;
        goto LABEL_33;
      }
      return 0;
    }
    v6 = v2->obj->master_obj;
    v7 = v5;
    v8 = v6->radius_y;
    v9 = sqrt(v6->radius_x * v6->radius_x + v8 * v8) + v2->range - -0.30000001;
    if ( v7 > v9 )
    {
      *rangeState = 2;
LABEL_36:
      if ( !v2->subActionValue )
        ((void (__stdcall *)(int, int, signed int, _DWORD, _DWORD, _DWORD))v2->obj->vfptr->notify)(
          v2->obj->id,
          v2->obj->id,
          509,
          0,
          0,
          0);
      ((void (*)(void))v2->obj->vfptr->maximumSpeed)();
      if ( v8 != 0.0 )
      {
        if ( !RGE_Static_Object::unitAI((RGE_Static_Object *)&v2->obj->vfptr)
          || (v24 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v2->obj->vfptr),
              UnitAIModule::currentOrder(v24) != 725) )
        {
          v2->vfptr->set_state((RGE_Action *)v2, 4);
          return 0;
        }
      }
      v2->vfptr->set_state((RGE_Action *)v2, 13);
      return 0;
    }
  }
  *rangeState = 1;
  return (unsigned __int8)((int (*)(void))v2->obj->vfptr->can_attack)() != 0;
}

//----- (00401EC0) --------------------------------------------------------
void __thiscall RGE_Action_Attack::do_attack(RGE_Action_Attack *this)
{
  RGE_Action_Attack *v1; // esi@1
  RGE_Static_Object *v2; // eax@1
  RGE_Action_Object *v3; // ecx@1

  v1 = this;
  v2 = this->target_obj;
  v3 = this->obj;
  if ( v2 )
  {
    (*(void (__stdcall **)(RGE_Static_Object *, RGE_Action_Object *))&v3->vfptr[1].gap4[56])(v2, v3);
    v1->need_to_attack = 0;
  }
  else
  {
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, RGE_Action_Object *))&v3->vfptr[1].gap4[52])(
      LODWORD(v1->target_x),
      LODWORD(v1->target_y),
      LODWORD(v1->target_z),
      v3);
    v1->need_to_attack = 0;
  }
}

//----- (00401F00) --------------------------------------------------------
void __thiscall RGE_Action_Attack::copy_obj_sprites(RGE_Action_Attack *this, RGE_Master_Action_Object *source, RGE_Task *task, RGE_Task *new_task)
{
  RGE_Sprite *v4; // eax@1
  RGE_Sprite *v5; // eax@5
  RGE_Sprite *v6; // eax@9
  RGE_Sprite *v7; // eax@13
  RGE_Sprite *v8; // eax@21

  v4 = this->move_sprite;
  if ( v4 )
  {
    if ( task && new_task && v4 == task->move_sprite )
    {
      v5 = new_task->move_sprite;
    }
    else
    {
      if ( v4 != *(RGE_Sprite **)&this->obj->master_obj[1].master_type )
        goto LABEL_9;
      v5 = source->move_sprite;
    }
    this->move_sprite = v5;
  }
LABEL_9:
  v6 = this->fight_sprite;
  if ( v6 )
  {
    if ( task )
    {
      if ( new_task && v6 == task->work_sprite )
      {
        v7 = new_task->work_sprite;
LABEL_20:
        this->fight_sprite = v7;
        goto LABEL_21;
      }
      if ( task && new_task && v6 == task->work_sprite2 )
      {
        v7 = new_task->work_sprite2;
        goto LABEL_20;
      }
    }
    if ( v6 == (RGE_Sprite *)this->obj->master_obj[1].death_sound )
    {
      v7 = (RGE_Sprite *)source[1].vfptr;
      goto LABEL_20;
    }
  }
LABEL_21:
  v8 = this->wait_sprite;
  if ( !v8 )
    return;
  if ( !task )
    goto LABEL_34;
  if ( new_task && v8 == task->work_sprite )
  {
    this->wait_sprite = new_task->work_sprite;
    return;
  }
  if ( task && new_task && v8 == task->work_sprite2 )
  {
    this->wait_sprite = new_task->work_sprite2;
  }
  else
  {
LABEL_34:
    if ( v8 == this->obj->master_obj->sprite )
      this->wait_sprite = source->sprite;
  }
}
