float TRIBE_Cliff_Higher_Check_Table[200] =
{
   3.1400001,
   4.71,
  -1.0,
  -1.0,
   1.5,
  -1.0,
   1.0,
   1.0,
   1.58,
   4.6999998,
  -1.0,
  -1.0,
   1.5,
  -1.5,
   1.5,
   1.5,
   1.58,
   4.6999998,
  -1.0,
  -1.0,
   1.5,
  -1.5,
   1.5,
   1.5,
   1.5700001,
   3.1400001,
  -1.0,
  -1.0,
   1.0,
  -1.5,
   1.5,
  -1.0,
   0.0099999998,
   3.1300001,
  -1.0,
  -1.0,
  -1.5,
  -1.5,
   1.5,
  -1.5,
   0.0099999998,
   3.1300001,
  -1.0,
  -1.0,
  -1.5,
  -1.5,
   1.5,
  -1.5,
   0.0,
   1.5700001,
  -1.0,
  -1.0,
  -1.0,
  -1.0,
   1.0,
  -1.5,
   4.7199998,
   6.2800002,
   0.0,
   1.5599999,
   0.5,
  -1.5,
   0.5,
   1.5,
   4.7199998,
   6.2800002,
   0.0,
   1.5599999,
   0.5,
  -1.5,
   0.5,
   1.5,
   4.71,
   6.2800002,
  -1.0,
  -1.0,
  -1.0,
  -1.0,
   1.0,
   1.0,
   3.1500001,
   6.27,
  -1.0,
  -1.0,
  -1.5,
  -0.5,
   1.5,
  -0.5,
   3.1500001,
   6.27,
  -1.0,
  -1.0,
  -1.5,
  -0.5,
   1.5,
  -0.5,
   0.0,
   1.5700001,
  -1.0,
  -1.0,
   1.0,
  -1.5,
   0.0,
   1.5,
   4.71,
   6.2800002,
  -1.0,
  -1.0,
   0.0,
  -1.0,
   1.0,
   0.0,
   3.1400001,
   4.71,
  -1.0,
  -1.0,
  -1.5,
   0.0,
   1.5,
  -1.0,
   1.5700001,
   3.1400001,
  -1.0,
  -1.0,
  -1.5,
  -1.5,
   1.5,
   1.5,
   0.0099999998,
   3.1300001,
  -1.0,
  -1.0,
  -1.5,
   0.0,
   1.5,
  -1.5,
   0.0099999998,
   3.1300001,
  -1.0,
  -1.0,
  -1.5,
  -1.5,
   1.5,
   0.0,
   1.58,
   4.6999998,
  -1.0,
  -1.0,
   0.0,
  -1.5,
   1.5,
   1.5,
   1.58,
   4.6999998,
  -1.0,
  -1.0,
   1.5,
  -1.5,
   0.0,
   1.5,
   3.1500001,
   6.27,
  -1.0,
  -1.0,
  -1.5,
   0.0,
   1.5,
  -1.0,
   3.1500001,
   6.27,
  -1.0,
  -1.0,
  -1.5,
  -1.0,
   1.5,
   0.0,
   4.7199998,
   6.2800002,
   0.0,
   1.5599999,
   0.0,
  -1.5,
   1.0,
   1.5,
   4.7199998,
   6.2800002,
   0.0,
   1.5599999,
   1.0,
  -1.5,
   0.0,
   1.5,
   1.5700001,
   3.1400001,
  -1.0,
  -1.0,
  -1.5,
  -1.5,
   1.5,
   1.5
};

//----- (004CA0F0) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::TRIBE_Combat_Object(TRIBE_Combat_Object *this, TRIBE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  TRIBE_Combat_Object *v7; // esi@1

  v7 = this;
  RGE_Combat_Object::RGE_Combat_Object(
    (RGE_Combat_Object *)&this->vfptr,
    (RGE_Master_Combat_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v7->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Combat_Object::`vftable';
  if ( do_setup )
    TRIBE_Combat_Object::setup(v7, tobj, obj_owner, x, y, z);
}
// 574A20: using guessed type int (__thiscall *TRIBE_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004CA180) --------------------------------------------------------
TRIBE_Combat_Object *__thiscall TRIBE_Combat_Object::`vector deleting destructor'(TRIBE_Combat_Object *this, unsigned int __flags)
{
  TRIBE_Combat_Object *v2; // esi@1

  v2 = this;
  TRIBE_Combat_Object::~TRIBE_Combat_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CA1A0) --------------------------------------------------------
void __userpurge TRIBE_Combat_Object::TRIBE_Combat_Object(TRIBE_Combat_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
  TRIBE_Combat_Object *v5; // esi@1

  v5 = this;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)&this->vfptr, a2, infile, gworld, 0);
  v5->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Combat_Object::`vftable';
  if ( do_setup )
    TRIBE_Combat_Object::setup(v5, a2, infile, gworld);
}
// 574A20: using guessed type int (__thiscall *TRIBE_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004CA210) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::~TRIBE_Combat_Object(TRIBE_Combat_Object *this)
{
  TRIBE_Combat_Object *v1; // esi@1
  RGE_Master_Static_Object *v2; // ecx@2
  int v3; // edi@2
  RGE_Master_Static_Object *v4; // ecx@5
  __int16 v5; // ax@5
  __int16 v6; // cx@10

  v1 = this;
  this->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Combat_Object::`vftable';
  if ( this->own_master )
  {
    v2 = this->master_obj;
    v3 = v2->id;
    if ( v2 )
      ((void (__stdcall *)(signed int))v2->vfptr->__vecDelDtor)(1);
    v1->master_obj = v1->owner->master_objects[v3];
  }
  v4 = v1->master_obj;
  v5 = v4->object_group;
  if ( v5 == 4 || v5 == 21 || v5 == 2 )
  {
    v1->owner->attributes[37] = v1->owner->attributes[37] - 1.0;
  }
  else if ( v5 != 18 && v4->master_type == 70 || (v6 = v4->id, v6 == 79) || v6 == 69 || v6 == 199 )
  {
    v1->owner->attributes[40] = v1->owner->attributes[40] - 1.0;
  }
  RGE_Combat_Object::~RGE_Combat_Object((RGE_Combat_Object *)&v1->vfptr);
}
// 574A20: using guessed type int (__thiscall *TRIBE_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004CA300) --------------------------------------------------------
int __thiscall TRIBE_Combat_Object::setup(TRIBE_Combat_Object *this, TRIBE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  TRIBE_Combat_Object *v6; // esi@1
  RGE_Static_ObjectVtbl *v7; // eax@3
  RGE_Master_Static_Object *v8; // ecx@3
  __int16 v9; // ax@3
  __int16 v10; // cx@8

  v6 = this;
  RGE_Combat_Object::setup(
    (RGE_Combat_Object *)&this->vfptr,
    (RGE_Master_Combat_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z);
  if ( !v6->owner->id )
    v6->capture_flag = 1;
  v7 = v6->vfptr;
  v6->type = 70;
  v7[1].destroy_obj((RGE_Static_Object *)v6);
  v8 = v6->master_obj;
  v6->own_master = 0;
  v9 = v8->object_group;
  if ( v9 == 4 || v9 == 21 || v9 == 2 )
  {
    v6->owner->attributes[37] = v6->owner->attributes[37] - -1.0;
  }
  else if ( v9 != 18 && v8->master_type == 70 || (v10 = v8->id, v10 == 79) || v10 == 69 || v10 == 199 )
  {
    v6->owner->attributes[40] = v6->owner->attributes[40] - -1.0;
  }
  if ( v6->master_obj->object_group == 18 )
  {
    LODWORD(v6->attribute_amount_held) = 1120403456;
    v6->attribute_type_held = 34;
  }
  return 1;
}

//----- (004CA3E0) --------------------------------------------------------
int __userpurge TRIBE_Combat_Object::setup@<eax>(TRIBE_Combat_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  int v4; // edi@1
  TRIBE_Combat_Object *v5; // esi@1
  TRIBE_Master_Combat_Object *v6; // eax@3
  RGE_Master_Static_Object *v7; // eax@4
  TRIBE_Master_Building_Object *v8; // eax@6
  UnitAIModule *v9; // esi@11

  v4 = infile;
  v5 = this;
  RGE_Combat_Object::setup((RGE_Combat_Object *)&this->vfptr, a2, infile, gworld);
  v5->type = 70;
  rge_read(a2, v4, v4, &v5->own_master, 1);
  if ( v5->own_master )
  {
    rge_read(a2, v4, v4, &gworld, 1);
    if ( (_BYTE)gworld == 70 )
    {
      v6 = (TRIBE_Master_Combat_Object *)operator new(0x164u);
      if ( v6 )
      {
        TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
          v6,
          v4,
          v5->owner->world->sprites,
          v5->owner->world->sounds,
          1);
LABEL_9:
        v5->master_obj = v7;
        goto LABEL_10;
      }
      goto LABEL_8;
    }
    if ( (_BYTE)gworld == 80 )
    {
      v8 = (TRIBE_Master_Building_Object *)operator new(0x17Cu);
      if ( v8 )
      {
        TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(
          v8,
          v4,
          v5->owner->world->sprites,
          v5->owner->world->sounds,
          1);
        goto LABEL_9;
      }
LABEL_8:
      v7 = 0;
      goto LABEL_9;
    }
  }
LABEL_10:
  rge_read(a2, v4, v4, &infile, 4);
  if ( infile == 1 )
  {
    v5->vfptr[1].destroy_obj((RGE_Static_Object *)v5);
    v9 = v5->unitAIValue;
    if ( v9 )
      (*(void (__thiscall **)(UnitAIModule *, int))&v9->vfptr->gap4[4])(v9, v4);
  }
  return 1;
}

//----- (004CA510) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::create_action_list(TRIBE_Combat_Object *this)
{
  TRIBE_Combat_Object *v1; // esi@1
  TRIBE_Action_List *v2; // eax@1

  v1 = this;
  v2 = (TRIBE_Action_List *)operator new(0xCu);
  if ( v2 )
    TRIBE_Action_List::TRIBE_Action_List(v2, (RGE_Action_Object *)&v1->vfptr);
}

//----- (004CA570) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::save(TRIBE_Combat_Object *this, int outfile)
{
  int v2; // edi@1
  TRIBE_Combat_Object *v3; // esi@1

  v2 = outfile;
  v3 = this;
  RGE_Combat_Object::save((RGE_Combat_Object *)&this->vfptr, outfile);
  rge_write(v2, &v3->own_master, 1);
  if ( v3->own_master )
    ((void (__stdcall *)(int))v3->master_obj->vfptr->save)(v2);
  if ( v3->unitAIValue )
  {
    outfile = 1;
    rge_write(v2, &outfile, 4);
    (*(void (__stdcall **)(int))&v3->unitAIValue->vfptr->gap4[0])(v2);
  }
  else
  {
    outfile = 0;
    rge_write(v2, &outfile, 4);
  }
}

//----- (004CA5F0) --------------------------------------------------------
char __thiscall TRIBE_Combat_Object::update(TRIBE_Combat_Object *this)
{
  char v2; // c0@3

  if ( this->master_obj->object_group == 18 && this->object_state == 2 )
  {
    this->attribute_amount_held = this->owner->attributes[35] * this->owner->world->world_time_delta_seconds
                                + this->attribute_amount_held;
    if ( !v2 )
      LODWORD(this->attribute_amount_held) = 1120403456;
    this->attribute_type_held = 34;
  }
  return RGE_Combat_Object::update((RGE_Combat_Object *)&this->vfptr);
}

//----- (004CA640) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::modify(TRIBE_Combat_Object *this, float amount, char flag)
{
  signed int v3; // esi@2
  signed int v4; // edx@2
  RGE_Master_Static_Object *v5; // edi@3
  RGE_Master_Static_Object *v6; // edi@5
  RGE_Master_Static_Object *v7; // edi@7

  if ( flag == 101 )
  {
    v3 = 112;
    v4 = 106;
    do
    {
      v5 = this->master_obj;
      if ( *(_WORD *)((char *)&v5->vfptr + v4) == 4 )
      {
        this->owner->attributes[4] = this->owner->attributes[4] - *(float *)((char *)&v5->vfptr + v3);
        this->owner->attributes[4] = amount + this->owner->attributes[4];
      }
      v6 = this->master_obj;
      if ( *(_WORD *)((char *)&v6->vfptr + v4) == 11 )
      {
        this->owner->attributes[11] = this->owner->attributes[11] - *(float *)((char *)&v6->vfptr + v3);
        this->owner->attributes[11] = this->owner->attributes[11] - amount;
      }
      v7 = this->master_obj;
      if ( *(_WORD *)((char *)&v7->vfptr + v4) == 19 )
      {
        this->owner->attributes[19] = this->owner->attributes[19] - *(float *)((char *)&v7->vfptr + v3);
        this->owner->attributes[19] = this->owner->attributes[19] - amount;
      }
      v4 += 2;
      v3 += 4;
    }
    while ( v4 < 112 );
  }
  RGE_Static_Object::modify((RGE_Static_Object *)&this->vfptr, amount, flag);
}

//----- (004CA700) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::transform(TRIBE_Combat_Object *this, RGE_Master_Static_Object *obj)
{
  TRIBE_Combat_Object *v2; // esi@1
  RGE_Master_Static_Object *v3; // edi@1

  v2 = this;
  v3 = this->master_obj;
  RGE_Action_Object::transform((RGE_Action_Object *)&this->vfptr, obj);
  if ( v2->own_master == 1 )
  {
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    v2->own_master = 0;
  }
}

//----- (004CA740) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::set_object_state(TRIBE_Combat_Object *this, char new_object_state)
{
  if ( this->owner->world->game_state
    || (unsigned __int8)new_object_state < 3u
    || this->object_state > 2u
    || this->master_obj->object_group != 1 )
  {
    RGE_Static_Object::set_object_state((RGE_Static_Object *)&this->vfptr, new_object_state);
  }
  else
  {
    TRIBE_Combat_Object::reposition_artifact(this);
  }
}

//----- (004CA780) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::cancel_object(TRIBE_Combat_Object *this)
{
  ((void (*)(void))this->vfptr->die_die_die)();
}

//----- (004CA790) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::die_die_die(TRIBE_Combat_Object *this)
{
  TRIBE_Combat_Object *v1; // edi@1
  RGE_Action *v2; // eax@3
  TRIBE_Action_Convert *v3; // esi@3

  v1 = this;
  if ( this->object_state == 2 && this->owner->attributes[57] >= 1.0 )
  {
    v2 = RGE_Action_List::get_action(this->actions);
    v3 = (TRIBE_Action_Convert *)v2;
    if ( v2 )
    {
      if ( v2->vfptr->type(v2) == 104 )
        TRIBE_Action_Convert::martyrdom(v3);
    }
  }
  RGE_Static_Object::die_die_die((RGE_Static_Object *)&v1->vfptr);
}

//----- (004CA7F0) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::damage(TRIBE_Combat_Object *this, int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject)
{
  TRIBE_Combat_Object *v6; // esi@1
  double v7; // st7@1
  RGE_Static_ObjectVtbl *v8; // edi@3
  float temp_hp; // [sp+10h] [bp-4h]@1

  v6 = this;
  v7 = this->hp;
  temp_hp = this->hp;
  if ( v7 >= 1.0 )
  {
    RGE_Combat_Object::damage(
      (RGE_Combat_Object *)&this->vfptr,
      v7,
      weapon_num,
      damage,
      attack_modifier,
      attacking_player,
      attackingObject);
    if ( v6->hp < 1.0 )
    {
      v8 = v6->vfptr;
      if ( !v6->vfptr->produceWhenKilledBy((RGE_Static_Object *)v6, attackingObject->master_obj->object_group) )
        ((void (__thiscall *)(TRIBE_Combat_Object *, _DWORD, _DWORD, signed int))v8->set_attribute_amount)(v6, 0, 0, 1);
    }
    if ( temp_hp - v6->hp < 1.0 )
      v6->hp = temp_hp - 1.0;
    if ( v6->owner->id > 0 && v6->hp < 1.0 )
      ((void (__thiscall *)(RGE_Player *, signed int, signed int, _DWORD))attacking_player->vfptr->add_attribute_num)(
        attacking_player,
        20,
        1065353216,
        0);
  }
}

//----- (004CA8C0) --------------------------------------------------------
void __userpurge TRIBE_Combat_Object::change_ownership(TRIBE_Combat_Object *this@<ecx>, int a2@<ebp>, RGE_Player *new_owner)
{
  TRIBE_Combat_Object *v3; // esi@1
  char *v4; // ecx@2
  RGE_Master_Static_Object *v5; // eax@6
  char v6; // al@13
  UnitAIModule *v7; // ecx@17

  v3 = this;
  if ( this->id >= 0 )
  {
    v4 = (char *)this->VUR_Ptrs;
    a2 = 9;
    do
    {
      if ( *(_DWORD *)v4 )
        *(_BYTE *)(*(_DWORD *)v4 + 5) = new_owner->id;
      v4 += 4;
      --a2;
    }
    while ( a2 );
  }
  v5 = v3->master_obj;
  if ( v5->object_group == 1 )
  {
    RGE_Action_Object::change_ownership((RGE_Action_Object *)&v3->vfptr, a2, new_owner);
  }
  else if ( new_owner->master_objects[v5->id] )
  {
    if ( v3->selected & 1 )
      RGE_Player::unselect_one_object(v3->owner, (RGE_Static_Object *)&v3->vfptr);
    RGE_Static_Object::take_attribute_from_owner((RGE_Static_Object *)&v3->vfptr);
    ((void (__stdcall *)(TRIBE_Combat_Object *, _DWORD, _DWORD, _DWORD))v3->owner->vfptr->removeObject)(
      v3,
      v3->sleep_flag,
      v3->dopple_flag,
      v3->player_object_node);
    v3->player_object_node = new_owner->vfptr->addObject(
                               new_owner,
                               (RGE_Static_Object *)v3,
                               v3->sleep_flag,
                               v3->dopple_flag);
    if ( v3->object_state == 2 )
      v3->vfptr->unexplore_terrain((RGE_Static_Object *)v3, v3->owner, 0, -1);
    v6 = v3->own_master;
    v3->owner = new_owner;
    if ( !v6 )
    {
      v3->master_obj = (RGE_Master_Static_Object *)((int (*)(void))v3->master_obj->vfptr->make_new_master)();
      v3->own_master = 1;
    }
    if ( v3->object_state == 2 )
      v3->vfptr->explore_terrain((RGE_Static_Object *)v3, v3->owner, 0, -1);
    RGE_Static_Object::give_attribute_to_owner((RGE_Static_Object *)&v3->vfptr);
    v7 = v3->unitAIValue;
    if ( v7 )
      UnitAIModule::purgeNotifyQueue(v7, v3->owner->world->world_time);
    v3->vfptr->notify((RGE_Static_Object *)v3, v3->id, v3->id, 523, new_owner->id, 0, 0);
  }
}

//----- (004CAA00) --------------------------------------------------------
double __thiscall TRIBE_Combat_Object::calc_attack_modifier(TRIBE_Combat_Object *this, RGE_Static_Object *target)
{
  if ( this->master_obj[1].attribute_type_held[1] < 0 )
  {
    if ( this->world_z < (double)target->world_z )
      return 0.66659999;
  }
  else if ( ((int (__stdcall *)(RGE_Static_Object *))this->vfptr[1].create_doppleganger_when_dying)(target) )
  {
    return 1.5;
  }
  return 1.0;
}

//----- (004CAA50) --------------------------------------------------------
char __thiscall TRIBE_Combat_Object::attack(TRIBE_Combat_Object *this, RGE_Static_Object *target, RGE_Combat_Object *attacker)
{
  TRIBE_Combat_Object *v3; // esi@1
  RGE_Player *v4; // ecx@3

  v3 = this;
  if ( this->master_obj[1].attribute_type_held[1] >= 0 )
  {
    if ( target )
    {
      v4 = target->owner;
      if ( v4->id > 0 )
        ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))v4->vfptr->make_new_object)(
          112,
          LODWORD(v3->world_x),
          LODWORD(v3->world_y),
          LODWORD(v3->world_z),
          0);
    }
  }
  return RGE_Combat_Object::attack((RGE_Combat_Object *)&v3->vfptr, target, attacker);
}

//----- (004CAAA0) --------------------------------------------------------
char __thiscall TRIBE_Combat_Object::do_attack(TRIBE_Combat_Object *this, RGE_Static_Object *target, RGE_Combat_Object *attacker, float x, float y, float z)
{
  TRIBE_Combat_Object *v6; // esi@1
  char result; // al@2
  __int16 v8; // ax@4
  RGE_Master_Static_Object *v9; // ecx@7
  double v10; // st7@8
  RGE_Static_ObjectVtbl *v11; // ebx@9
  float za; // [sp+30h] [bp+14h]@10

  v6 = this;
  if ( target )
  {
    if ( rge_base_game->quick_build && ((v8 = this->master_obj->id, v8 == 122) || v8 == 123) )
    {
      this->vfptr->notify((RGE_Static_Object *)this, this->id, this->id, 512, 600, target->id, 0);
      target->vfptr->die_die_die(target);
      result = 1;
    }
    else
    {
      v9 = this->master_obj;
      if ( v9[1].construction_radius_y <= 0.0 || (v10 = v9[1].construction_radius_x, v10 >= 0.99000001) )
      {
        result = RGE_Combat_Object::do_attack((RGE_Combat_Object *)&v6->vfptr, target, attacker, x, y, z);
      }
      else
      {
        v11 = v6->vfptr;
        (*(void (__thiscall **)(TRIBE_Combat_Object *, _DWORD, _DWORD, _DWORD, RGE_Combat_Object *, RGE_Static_Object *))&v6->vfptr[1].gap4[48])(
          v6,
          LODWORD(x),
          LODWORD(y),
          LODWORD(z),
          attacker,
          target);
        v11->notify((RGE_Static_Object *)v6, v6->id, v6->id, 512, 600, target->id, 0);
        if ( 100 * debug_rand(aCMsdevWorkAg_9, 529) / 0x7FFF <= v6->master_obj[1].attribute_type_held[2] )
        {
          v11->calc_attack_modifier((RGE_Static_Object *)v6, target);
          za = v10;
          ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, RGE_Player *, RGE_Combat_Object *))target->vfptr->damage)(
            target,
            v6->master_obj[1].portrait_pict,
            *(_DWORD *)&v6->master_obj[1].tile_req1,
            LODWORD(za),
            v6->owner,
            attacker);
        }
        result = 1;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CAC10) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::get_armor(TRIBE_Combat_Object *this, __int16 *cur_armor_in, __int16 *orig_armor_in)
{
  RGE_Master_Static_Object *v3; // eax@1
  signed int i; // edx@1
  int v5; // eax@2
  bool v6; // zf@2
  int v7; // eax@2
  __int16 v8; // ax@3

  *cur_armor_in = LOBYTE(this->master_obj[1].death_spawn_obj_id);
  v3 = this->master_obj;
  for ( i = 0; i < *(_WORD *)&v3[1].sort_number; ++i )
  {
    v5 = *(_DWORD *)&v3[1].button_pict;
    v6 = *(_WORD *)(v5 + 4 * i) == 4;
    v7 = v5 + 4 * i;
    if ( v6 )
    {
      v8 = *(_WORD *)(v7 + 2);
      if ( v8 > *cur_armor_in )
        *cur_armor_in = v8;
    }
    v3 = this->master_obj;
  }
  *orig_armor_in = LOWORD(this->master_obj[1].multiple_attribute_mod);
}

//----- (004CAC80) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::get_pierce_armor(TRIBE_Combat_Object *this, __int16 *cur_armor_in, __int16 *orig_armor_in)
{
  signed int v3; // edx@1
  RGE_Master_Static_Object *v4; // eax@1
  int v5; // eax@2
  bool v6; // zf@2
  int v7; // eax@2
  __int16 v8; // ax@3

  v3 = 0;
  *cur_armor_in = 0;
  v4 = this->master_obj;
  if ( *(_WORD *)&v4[1].sort_number > 0 )
  {
    do
    {
      v5 = *(_DWORD *)&v4[1].button_pict;
      v6 = *(_WORD *)(v5 + 4 * v3) == 3;
      v7 = v5 + 4 * v3;
      if ( v6 )
      {
        v8 = *(_WORD *)(v7 + 2);
        if ( v8 > *cur_armor_in )
          *cur_armor_in = v8;
      }
      v4 = this->master_obj;
      ++v3;
    }
    while ( v3 < *(_WORD *)&v4[1].sort_number );
  }
  *orig_armor_in = *(_WORD *)&this->master_obj[1].draw_flag;
}

//----- (004CACE0) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::reposition_artifact(TRIBE_Combat_Object *this)
{
  TRIBE_Combat_Object *v1; // esi@1
  RGE_Static_Object *v2; // edi@1
  int v3; // ebp@2
  RGE_Map *v4; // ebx@4
  int v5; // edi@6
  unsigned __int8 v6; // al@7
  unsigned __int8 v7; // al@10
  int v8; // edi@17
  unsigned __int8 v9; // al@18
  unsigned __int8 v10; // al@21
  bool v11; // zf@28
  bool v12; // sf@28
  RGE_Static_Object *v13; // eax@41
  RGE_Static_ObjectVtbl *v14; // edi@46
  float y_pos; // [sp+5Ch] [bp-28h]@2
  float x_pos; // [sp+60h] [bp-24h]@2
  int y1; // [sp+64h] [bp-20h]@2
  int x2; // [sp+68h] [bp-1Ch]@4
  int x1; // [sp+6Ch] [bp-18h]@2
  int y2; // [sp+70h] [bp-14h]@4
  int found_pos; // [sp+74h] [bp-10h]@4
  int x; // [sp+78h] [bp-Ch]@6
  int xa; // [sp+78h] [bp-Ch]@17
  int map_max_x; // [sp+7Ch] [bp-8h]@4
  int map_max_y; // [sp+80h] [bp-4h]@4

  v1 = this;
  v2 = this->inside_obj;
  if ( v2 )
  {
    x1 = (signed __int64)v2->world_x;
    v3 = (signed __int64)v2->world_y;
    y1 = (signed __int64)v2->world_y;
    x_pos = v2->world_x;
    y_pos = v2->world_y;
  }
  else
  {
    x1 = (signed __int64)this->world_x;
    y1 = (signed __int64)this->world_y;
    v3 = (signed __int64)this->world_y;
    x_pos = this->world_x;
    y_pos = this->world_y;
  }
  x2 = x1;
  y2 = v3;
  found_pos = 0;
  v4 = this->owner->world->map;
  map_max_x = v4->map_width - 1;
  map_max_y = v4->map_height - 1;
  while ( 1 )
  {
    v5 = x1;
    x = x1;
    if ( x1 <= x2 )
    {
      while ( 1 )
      {
        v6 = RGE_Map::get_terrain(v4, v5, v3);
        if ( v6 != 1 && v6 != 2 )
        {
          x_pos = (double)x - -0.5;
          y_pos = (double)y1 - -0.5;
          if ( !(unsigned __int8)((int (__stdcall *)(_DWORD, float, float, _DWORD, signed int, signed int, signed int, _DWORD, signed int, signed int))v1->master_obj->vfptr->check_placement)(
                                   v1->owner,
                                   COERCE_FLOAT(LODWORD(x_pos)),
                                   COERCE_FLOAT(LODWORD(y_pos)),
                                   0,
                                   1,
                                   1,
                                   1,
                                   0,
                                   1,
                                   1) )
            break;
        }
        v7 = RGE_Map::get_terrain(v4, v5, y2);
        if ( v7 != 1 && v7 != 2 )
        {
          x_pos = (double)x - -0.5;
          y_pos = (double)y2 - -0.5;
          if ( !(unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v1->master_obj->vfptr->check_placement)(
                                   v1->owner,
                                   LODWORD(x_pos),
                                   LODWORD(y_pos),
                                   0,
                                   1,
                                   1,
                                   1,
                                   0,
                                   1,
                                   1) )
            break;
        }
        x = ++v5;
        if ( v5 > x2 )
          goto LABEL_16;
      }
      found_pos = 1;
    }
LABEL_16:
    if ( found_pos )
      break;
    v8 = v3 + 1;
    xa = v3 + 1;
    if ( v3 + 1 <= y2 - 1 )
    {
      while ( 1 )
      {
        v9 = RGE_Map::get_terrain(v4, x1, v8);
        if ( v9 != 1 && v9 != 2 )
        {
          x_pos = (double)x1 - -0.5;
          y_pos = (double)xa - -0.5;
          if ( !(unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v1->master_obj->vfptr->check_placement)(
                                   v1->owner,
                                   LODWORD(x_pos),
                                   LODWORD(y_pos),
                                   0,
                                   1,
                                   1,
                                   1,
                                   0,
                                   1,
                                   1) )
            break;
        }
        v10 = RGE_Map::get_terrain(v4, x2, v8);
        if ( v10 != 1 && v10 != 2 )
        {
          x_pos = (double)x2 - -0.5;
          y_pos = (double)xa - -0.5;
          if ( !(unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v1->master_obj->vfptr->check_placement)(
                                   v1->owner,
                                   LODWORD(x_pos),
                                   LODWORD(y_pos),
                                   0,
                                   0,
                                   1,
                                   1,
                                   0,
                                   1,
                                   1) )
            break;
        }
        xa = ++v8;
        if ( v8 > y2 - 1 )
          goto LABEL_27;
      }
      found_pos = 1;
    }
LABEL_27:
    if ( found_pos )
      break;
    v11 = x1 == 0;
    v12 = x1 < 0;
    if ( !x1 )
    {
      if ( x2 == map_max_x && !y1 && y2 == map_max_y )
      {
        v13 = v1->inside_obj;
        if ( v13 )
        {
          x_pos = v13->world_x;
          y_pos = v13->world_y;
        }
        else
        {
          x_pos = v1->world_x;
          y_pos = v1->world_y;
        }
        break;
      }
      v11 = 1;
      v12 = 0;
    }
    if ( !v12 && !v11 )
      --x1;
    if ( y1 > 0 )
      --y1;
    if ( x2 < map_max_x )
      ++x2;
    if ( y2 < map_max_y )
      ++y2;
    v3 = y1;
  }
  RGE_Static_Object::set_location((RGE_Static_Object *)&v1->vfptr, x_pos, y_pos, v1->world_z);
  if ( v1->inside_obj )
    v1->vfptr->exit_obj((RGE_Static_Object *)v1);
  v14 = v1->vfptr;
  (*(void (__thiscall **)(TRIBE_Combat_Object *, float, float, _DWORD))&v1->vfptr->gap4[48])(
    v1,
    COERCE_FLOAT(LODWORD(x_pos)),
    COERCE_FLOAT(LODWORD(y_pos)),
    LODWORD(v1->world_z));
  v14->change_ownership((RGE_Static_Object *)v1, *v1->owner->world->players);
  ((void (__thiscall *)(TRIBE_Combat_Object *, _DWORD, float, float, _DWORD))v14->move_to)(
    v1,
    0,
    COERCE_FLOAT(LODWORD(x_pos)),
    COERCE_FLOAT(LODWORD(y_pos)),
    LODWORD(v1->world_z));
  LODWORD(v1->hp) = 1065353216;
}

//----- (004CB040) --------------------------------------------------------
int __thiscall TRIBE_Combat_Object::can_debark(TRIBE_Combat_Object *this)
{
  int result; // eax@2

  if ( this->master_obj->unit_level == 7 )
    result = this->objects->number_of_objects != 0;
  else
    result = 0;
  return result;
}

//----- (004CB060) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Combat_Object::hunt(TRIBE_Combat_Object *this, int targetID, int unconditional)
{
  TRIBE_Combat_Object *v3; // edi@1
  RGE_Static_Object *result; // eax@1
  int v5; // esi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Static_ObjectVtbl *v10; // ebp@9
  RGE_Task *v11; // ebx@9
  TRIBE_Action_Hunt *v12; // eax@10
  int v13; // eax@11
  int v14; // esi@11

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 110) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 110) )
      {
        v10 = v3->vfptr;
        result = (RGE_Static_Object *)(*(int (__thiscall **)(TRIBE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                        v3,
                                        v5,
                                        *(_DWORD *)(v5 + 56),
                                        *(_DWORD *)(v5 + 60),
                                        *(_DWORD *)(v5 + 64));
        v11 = (RGE_Task *)result;
        if ( !result )
          return result;
        v12 = (TRIBE_Action_Hunt *)operator new(0x44u);
        if ( v12 )
        {
          TRIBE_Action_Hunt::TRIBE_Action_Hunt(v12, (RGE_Action_Object *)&v3->vfptr, v11, (RGE_Static_Object *)v5);
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        if ( !v14 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v10[1].gap4[28])(v3, v14);
      }
      else
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (004CB1B0) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Combat_Object::convert(TRIBE_Combat_Object *this, int targetID, int unconditional)
{
  TRIBE_Combat_Object *v3; // edi@1
  RGE_Static_Object *result; // eax@1
  int v5; // esi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Static_ObjectVtbl *v10; // ebp@9
  RGE_Task *v11; // ebx@9
  TRIBE_Action_Convert *v12; // eax@10
  int v13; // eax@11
  int v14; // esi@11

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 104) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 104) )
      {
        v10 = v3->vfptr;
        result = (RGE_Static_Object *)(*(int (__thiscall **)(TRIBE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                        v3,
                                        v5,
                                        *(_DWORD *)(v5 + 56),
                                        *(_DWORD *)(v5 + 60),
                                        *(_DWORD *)(v5 + 64));
        v11 = (RGE_Task *)result;
        if ( !result )
          return result;
        v12 = (TRIBE_Action_Convert *)operator new(0x48u);
        if ( v12 )
        {
          TRIBE_Action_Convert::TRIBE_Action_Convert(v12, (RGE_Action_Object *)&v3->vfptr, v11, (RGE_Static_Object *)v5);
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        if ( !v14 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v10[1].gap4[28])(v3, v14);
      }
      else
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (004CB300) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Combat_Object::heal(TRIBE_Combat_Object *this, int targetID, int unconditional)
{
  TRIBE_Combat_Object *v3; // edi@1
  RGE_Static_Object *result; // eax@1
  int v5; // esi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Static_ObjectVtbl *v10; // ebp@9
  RGE_Task *v11; // ebx@9
  TRIBE_Action_Heal *v12; // eax@10
  int v13; // eax@11
  int v14; // esi@11

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 105) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 105) )
      {
        v10 = v3->vfptr;
        result = (RGE_Static_Object *)(*(int (__thiscall **)(TRIBE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                        v3,
                                        v5,
                                        *(_DWORD *)(v5 + 56),
                                        *(_DWORD *)(v5 + 60),
                                        *(_DWORD *)(v5 + 64));
        v11 = (RGE_Task *)result;
        if ( !result )
          return result;
        v12 = (TRIBE_Action_Heal *)operator new(0x40u);
        if ( v12 )
        {
          TRIBE_Action_Heal::TRIBE_Action_Heal(v12, (RGE_Action_Object *)&v3->vfptr, v11, (RGE_Static_Object *)v5);
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        if ( !v14 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v10[1].gap4[28])(v3, v14);
      }
      else
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (004CB450) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Combat_Object::repair(TRIBE_Combat_Object *this, int targetID, int unconditional)
{
  TRIBE_Combat_Object *v3; // esi@1
  RGE_Static_Object *result; // eax@1
  int v5; // edi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Master_Static_Object *v10; // eax@9
  RGE_Static_ObjectVtbl *v11; // ebp@11
  RGE_Task *v12; // ebx@11
  TRIBE_Action_Repair *v13; // eax@12
  int v14; // eax@13
  int v15; // edi@13

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( !unconditional && RGE_Action_List::have_action(v3->actions) == 1 )
    {
      v6 = RGE_Action_List::get_action(v3->actions);
      if ( (int)v6->vfptr->get_target_obj(v6) == v5 )
      {
        v7 = RGE_Action_List::get_action(v3->actions);
        if ( v7->vfptr->type(v7) == 106 )
          return (RGE_Static_Object *)1;
      }
    }
    if ( RGE_Action_List::have_action(v3->actions) == 1 )
    {
      v8 = RGE_Action_List::get_action(v3->actions);
      if ( v8->vfptr->type(v8) == 106 )
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
        return (RGE_Static_Object *)1;
      }
    }
    v10 = (RGE_Master_Static_Object *)*((_DWORD *)v3->owner->master_objects + 156);
    if ( v10 )
      v3->vfptr->transform((RGE_Static_Object *)v3, v10);
    v11 = v3->vfptr;
    result = (RGE_Static_Object *)(*(int (__thiscall **)(TRIBE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                    v3,
                                    v5,
                                    *(_DWORD *)(v5 + 56),
                                    *(_DWORD *)(v5 + 60),
                                    *(_DWORD *)(v5 + 64));
    v12 = (RGE_Task *)result;
    if ( result )
    {
      v13 = (TRIBE_Action_Repair *)operator new(0x44u);
      if ( v13 )
      {
        TRIBE_Action_Repair::TRIBE_Action_Repair(v13, (RGE_Action_Object *)&v3->vfptr, v12, (RGE_Static_Object *)v5);
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      if ( !v15 )
        return 0;
      RGE_Action_List::delete_list(v3->actions);
      (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v11[1].gap4[28])(v3, v15);
      return (RGE_Static_Object *)1;
    }
  }
  return result;
}

//----- (004CB5C0) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Combat_Object::build(TRIBE_Combat_Object *this, int targetID, int unconditional)
{
  TRIBE_Combat_Object *v3; // edi@1
  RGE_Static_Object *result; // eax@1
  int v5; // esi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Static_ObjectVtbl *v10; // ebp@9
  RGE_Task *v11; // ebx@9
  TRIBE_Action_Build *v12; // eax@10
  int v13; // eax@11
  int v14; // esi@11

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 101) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 101) )
      {
        v10 = v3->vfptr;
        result = (RGE_Static_Object *)(*(int (__thiscall **)(TRIBE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                        v3,
                                        v5,
                                        *(_DWORD *)(v5 + 56),
                                        *(_DWORD *)(v5 + 60),
                                        *(_DWORD *)(v5 + 64));
        v11 = (RGE_Task *)result;
        if ( !result )
          return result;
        v12 = (TRIBE_Action_Build *)operator new(0x40u);
        if ( v12 )
        {
          TRIBE_Action_Build::TRIBE_Action_Build(v12, (RGE_Action_Object *)&v3->vfptr, v11, (RGE_Static_Object *)v5);
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        if ( !v14 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v10[1].gap4[28])(v3, v14);
      }
      else
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (004CB710) --------------------------------------------------------
RGE_Static_Object *__thiscall TRIBE_Combat_Object::trade(TRIBE_Combat_Object *this, int targetID, int unconditional)
{
  TRIBE_Combat_Object *v3; // edi@1
  RGE_Static_Object *result; // eax@1
  int v5; // esi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Static_ObjectVtbl *v10; // ebp@9
  RGE_Task *v11; // ebx@9
  TRIBE_Action_Trade *v12; // eax@10
  int v13; // eax@11
  int v14; // esi@11

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 111) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 111) )
      {
        v10 = v3->vfptr;
        result = (RGE_Static_Object *)(*(int (__thiscall **)(TRIBE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                        v3,
                                        v5,
                                        *(_DWORD *)(v5 + 56),
                                        *(_DWORD *)(v5 + 60),
                                        *(_DWORD *)(v5 + 64));
        v11 = (RGE_Task *)result;
        if ( !result )
          return result;
        v12 = (TRIBE_Action_Trade *)operator new(0x48u);
        if ( v12 )
        {
          TRIBE_Action_Trade::TRIBE_Action_Trade(v12, (RGE_Action_Object *)&v3->vfptr, v11, (RGE_Static_Object *)v5);
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        if ( !v14 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v10[1].gap4[28])(v3, v14);
      }
      else
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (004CB860) --------------------------------------------------------
bool __stdcall TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int oType)
{
  return oType == 50 || oType == 45;
}

//----- (004CB880) --------------------------------------------------------
bool __thiscall TRIBE_Combat_Object::produceWhenKilledBy(TRIBE_Combat_Object *this, int oGroup)
{
  int v2; // eax@1
  bool result; // al@3

  v2 = this->master_obj->object_group;
  if ( v2 == 9 || v2 == 10 )
    result = oGroup == 4;
  else
    result = 1;
  return result;
}

//----- (004CB8B0) --------------------------------------------------------
bool __thiscall TRIBE_Combat_Object::useSameZoneDropsite(TRIBE_Combat_Object *this)
{
  int v1; // eax@1

  v1 = this->master_obj->object_group;
  return v1 != 21 && v1 != 2;
}

//----- (004CB8D0) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::initUnitAI(TRIBE_Combat_Object *this)
{
  TRIBE_Combat_Object *v1; // esi@1
  RGE_Master_Static_Object *v2; // eax@1
  __int16 v3; // ax@2
  TribeArtifactUnitAIModule *v4; // eax@4
  UnitAIModule *v5; // eax@5
  TribeCivilianUnitAIModule *v6; // eax@6
  UnitAIModule *v7; // eax@7
  TribePriestUnitAIModule *v8; // eax@8
  UnitAIModule *v9; // eax@9
  TribeHuntedAnimalUnitAIModule *v10; // eax@10
  UnitAIModule *v11; // eax@11
  __int16 v12; // ax@12
  TribeHuntedAnimalUnitAIModule *v13; // eax@13
  UnitAIModule *v14; // eax@14
  TribeElephantUnitAIModule *v15; // eax@16
  UnitAIModule *v16; // eax@17
  TribeLionUnitAIModule *v17; // eax@19
  UnitAIModule *v18; // eax@20
  TribePreditorUnitAIModule *v19; // eax@21
  UnitAIModule *v20; // eax@22
  TribeFishingShipUnitAIModule *v21; // eax@23
  UnitAIModule *v22; // eax@24
  TribeTradeShipUnitAIModule *v23; // eax@25
  UnitAIModule *v24; // eax@26
  TribeTransportShipUnitAIModule *v25; // eax@27
  UnitAIModule *v26; // eax@28
  __int16 v27; // ax@29
  TribeBuildingUnitAIModule *v28; // eax@35
  UnitAIModule *v29; // eax@36
  TribeTowerUnitAIModule *v30; // eax@37
  UnitAIModule *v31; // eax@38
  TribeSoldierUnitAIModule *v32; // eax@39
  UnitAIModule *v33; // eax@40

  v1 = this;
  v2 = this->master_obj;
  switch ( v2->object_group )
  {
    case 1:
      v3 = v2->id;
      if ( v3 != 99 && v3 != 10 )
      {
        v4 = (TribeArtifactUnitAIModule *)operator new(0x134u);
        if ( !v4 )
          goto LABEL_41;
        TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(v4, (RGE_Static_Object *)&v1->vfptr, 5);
        v1->unitAIValue = v5;
      }
      break;
    case 4:
      v6 = (TribeCivilianUnitAIModule *)operator new(0x134u);
      if ( !v6 )
        goto LABEL_41;
      TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(v6, (RGE_Static_Object *)&v1->vfptr, 10);
      v1->unitAIValue = v7;
      break;
    case 18:
      v8 = (TribePriestUnitAIModule *)operator new(0x134u);
      if ( !v8 )
        goto LABEL_41;
      TribePriestUnitAIModule::TribePriestUnitAIModule(v8, (RGE_Static_Object *)&v1->vfptr, 10);
      v1->unitAIValue = v9;
      break;
    case 9:
      v10 = (TribeHuntedAnimalUnitAIModule *)operator new(0x134u);
      if ( !v10 )
        goto LABEL_41;
      TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(v10, (RGE_Static_Object *)&v1->vfptr, 10);
      v1->unitAIValue = v11;
      break;
    case 10:
      v12 = v2->id;
      switch ( v12 )
      {
        case 157:
          v13 = (TribeHuntedAnimalUnitAIModule *)operator new(0x134u);
          if ( !v13 )
            goto LABEL_41;
          TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(v13, (RGE_Static_Object *)&v1->vfptr, 10);
          v1->unitAIValue = v14;
          break;
        case 48:
          v15 = (TribeElephantUnitAIModule *)operator new(0x134u);
          if ( !v15 )
            goto LABEL_41;
          TribeElephantUnitAIModule::TribeElephantUnitAIModule(v15, (RGE_Static_Object *)&v1->vfptr, 10);
          v1->unitAIValue = v16;
          break;
        case 126:
          v17 = (TribeLionUnitAIModule *)operator new(0x134u);
          if ( !v17 )
            goto LABEL_41;
          TribeLionUnitAIModule::TribeLionUnitAIModule(v17, (RGE_Static_Object *)&v1->vfptr, 10);
          v1->unitAIValue = v18;
          break;
        default:
          v19 = (TribePreditorUnitAIModule *)operator new(0x134u);
          if ( !v19 )
            goto LABEL_41;
          TribePreditorUnitAIModule::TribePreditorUnitAIModule(v19, (RGE_Static_Object *)&v1->vfptr, 10);
          v1->unitAIValue = v20;
          break;
      }
      break;
    case 21:
      v21 = (TribeFishingShipUnitAIModule *)operator new(0x134u);
      if ( !v21 )
        goto LABEL_41;
      TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(v21, (RGE_Static_Object *)&v1->vfptr, 10);
      v1->unitAIValue = v22;
      break;
    case 2:
      v23 = (TribeTradeShipUnitAIModule *)operator new(0x134u);
      if ( !v23 )
        goto LABEL_41;
      TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(v23, (RGE_Static_Object *)&v1->vfptr, 10);
      v1->unitAIValue = v24;
      break;
    case 20:
      v25 = (TribeTransportShipUnitAIModule *)operator new(0x134u);
      if ( !v25 )
        goto LABEL_41;
      TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(v25, (RGE_Static_Object *)&v1->vfptr, 10);
      v1->unitAIValue = v26;
      break;
    case 3:
    case 27:
      v27 = v2->id;
      if ( v27 == 79 || v27 == 199 || v27 == 69 || v27 == 278 || v27 == 383 || v27 == 380 )
      {
        v30 = (TribeTowerUnitAIModule *)operator new(0x134u);
        if ( !v30 )
          goto LABEL_41;
        TribeTowerUnitAIModule::TribeTowerUnitAIModule(v30, (RGE_Static_Object *)&v1->vfptr, 10);
        v1->unitAIValue = v31;
      }
      else
      {
        v28 = (TribeBuildingUnitAIModule *)operator new(0x134u);
        if ( !v28 )
          goto LABEL_41;
        TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(v28, (RGE_Static_Object *)&v1->vfptr, 10);
        v1->unitAIValue = v29;
      }
      break;
    default:
      v32 = (TribeSoldierUnitAIModule *)operator new(0x134u);
      if ( v32 )
      {
        TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(v32, (RGE_Static_Object *)&v1->vfptr, 10);
        v1->unitAIValue = v33;
      }
      else
      {
LABEL_41:
        v1->unitAIValue = 0;
      }
      break;
    case 5:
    case 7:
    case 8:
    case 11:
    case 14:
    case 15:
    case 16:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
      return;
  }
}

//----- (004CBD30) --------------------------------------------------------
int __cdecl lines_intersect()
{
  return 1;
}

//----- (004CBD40) --------------------------------------------------------
int __thiscall TRIBE_Combat_Object::higher_check_for_cliff(TRIBE_Combat_Object *this, RGE_Static_Object *target, int XTileInt, int YTileInt, float StartX, float StartY, float DestX, float DestY, RGE_Map *Map, RGE_Static_Object *LastCliffObject, float *AngleToTarget, int *HigherCalc)
{
  TRIBE_Combat_Object *v12; // esi@1
  RGE_Object_Node *v13; // ebx@5
  RGE_Static_Object *v14; // ecx@6
  long double v15; // st7@9
  char v17; // c0@9
  signed int v18; // eax@11
  signed int v19; // esi@11
  float b_y2; // ST1C_4@11
  float b_x2; // ST18_4@11
  float b_y1; // ST14_4@11
  float b_x1; // ST10_4@11
  int result; // eax@14
  int v25; // esi@18
  TRIBE_Combat_Object *v26; // [sp+20h] [bp-4h]@1

  v12 = this;
  v26 = this;
  if ( YTileInt < 0 )
    return 0;
  if ( YTileInt >= Map->map_height )
    return 0;
  if ( XTileInt < 0 )
    return 0;
  if ( XTileInt >= Map->map_width )
    return 0;
  v13 = Map->map_row_offset[YTileInt][XTileInt].objects.list;
  if ( !v13 )
    return 0;
  while ( 1 )
  {
    v14 = v13->node;
    if ( v13->node->master_obj->object_group != 34 || v14 == LastCliffObject )
      goto LABEL_13;
    LastCliffObject = v13->node;
    if ( *(_DWORD *)AngleToTarget == -1082130432 )
    {
      v15 = atan2(target->world_x - v12->world_x, target->world_y - v12->world_y);
      *AngleToTarget = v15;
      if ( v17 )
        *AngleToTarget = v15 - -6.2831855;
    }
    v18 = v14->facet;
    v19 = v18;
    v18 *= 32;
    b_y2 = *(float *)(v18 + 5796468) + DestY;
    b_x2 = *(float *)(v18 + 5796464) + DestX;
    b_y1 = *(float *)(v18 + 5796460) + StartY;
    b_x1 = *(float *)(v18 + 5796456) + StartX;
    if ( lines_intersect() )
      break;
    v12 = v26;
LABEL_13:
    v13 = v13->next;
    if ( !v13 )
      return 0;
  }
  if ( (v19 >= 25
     || *AngleToTarget < (double)TRIBE_Cliff_Higher_Check_Table[8 * v19]
     || *AngleToTarget > (double)TRIBE_Cliff_Higher_Check_Table[8 * v19 + 1])
    && ((v25 = 32 * v19, *AngleToTarget < (double)*(float *)(v25 + 5796448))
     || *AngleToTarget > (double)*(float *)(v25 + 5796452)) )
  {
    --*HigherCalc;
    result = 1;
  }
  else
  {
    ++*HigherCalc;
    result = 1;
  }
  return result;
}

//----- (004CBEF0) --------------------------------------------------------
int __thiscall TRIBE_Combat_Object::higher_than_target(TRIBE_Combat_Object *this, RGE_Static_Object *target)
{
  TRIBE_Combat_Object *v2; // ebp@1
  int result; // eax@2
  long double v4; // st7@3
  long double v6; // st6@3
  char v7; // c3@3
  long double v8; // st5@7
  int v9; // ecx@9
  long double v10; // st5@9
  double v11; // st7@9
  double v13; // st7@9
  char v14; // c0@9
  RGE_Player *v15; // eax@16
  int v16; // eax@16
  int v17; // eax@16
  double v18; // st6@18
  int v19; // esi@18
  signed __int64 v20; // rax@18
  int v21; // edi@18
  void (__thiscall *v22)(RGE_Static_Object *); // ebx@20
  float StartY; // [sp+6Ch] [bp-48h]@3
  float StartX; // [sp+70h] [bp-44h]@3
  float XStep; // [sp+74h] [bp-40h]@9
  float YStep; // [sp+78h] [bp-3Ch]@9
  float DestY; // [sp+7Ch] [bp-38h]@3
  float DestX; // [sp+80h] [bp-34h]@3
  int HigherCalc; // [sp+84h] [bp-30h]@16
  float XTile; // [sp+88h] [bp-2Ch]@16
  float YTile; // [sp+8Ch] [bp-28h]@16
  float AngleToTarget; // [sp+90h] [bp-24h]@16
  int NumSteps; // [sp+94h] [bp-20h]@9
  int PriorX; // [sp+98h] [bp-1Ch]@16
  int PriorY; // [sp+9Ch] [bp-18h]@16
  int Tile_Dy1; // [sp+A0h] [bp-14h]@14
  int Tile_Dx1; // [sp+A4h] [bp-10h]@14
  int Tile_Dy2; // [sp+A8h] [bp-Ch]@14
  int Tile_Dx2; // [sp+ACh] [bp-8h]@14
  int v40; // [sp+B0h] [bp-4h]@17

  v2 = this;
  if ( this->world_z <= (double)target->world_z )
  {
    DestX = target->world_x;
    StartX = this->world_x;
    v4 = DestX - StartX;
    DestY = target->world_y;
    StartY = this->world_y;
    v6 = DestY - StartY;
    if ( v7 && v6 == 0.0 )
    {
      result = 0;
    }
    else
    {
      if ( fabs(v4) >= fabs(v6) )
        v8 = v4;
      else
        v8 = v6;
      v9 = 2 * abs((signed __int64)v8);
      v10 = v4;
      v11 = (double)v9;
      XStep = v10 / v11;
      YStep = v6 / v11;
      *(float *)&NumSteps = YStep;
      v13 = XStep;
      if ( v14 )
        v13 = -XStep;
      if ( YStep < 0.0 )
        *(float *)&NumSteps = -YStep;
      if ( v13 <= *(float *)&NumSteps )
      {
        Tile_Dx1 = -1;
        Tile_Dy1 = 0;
        Tile_Dx2 = 1;
        Tile_Dy2 = 0;
      }
      else
      {
        Tile_Dy1 = -1;
        Tile_Dx1 = 0;
        Tile_Dx2 = 0;
        Tile_Dy2 = 1;
      }
      XTile = StartX;
      PriorX = -999;
      PriorY = -999;
      v15 = v2->owner;
      YTile = StartY;
      v16 = (int)v15->world->map;
      AngleToTarget = -1.0;
      NumSteps = v16;
      v17 = 0;
      HigherCalc = 0;
      if ( v9 > 0 )
      {
        v40 = v9;
        do
        {
          v18 = XTile + XStep;
          XTile = v18;
          YTile = YTile + YStep;
          v19 = (signed __int64)v18;
          v20 = (signed __int64)YTile;
          v21 = v20;
          if ( v19 != PriorX || (_DWORD)v20 != PriorY )
          {
            v22 = v2->vfptr[1].remove_visible_resource;
            PriorX = (signed __int64)v18;
            PriorY = (signed __int64)YTile;
            if ( !((int (__thiscall *)(TRIBE_Combat_Object *, RGE_Static_Object *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, float *, int *))v22)(
                    v2,
                    target,
                    v19,
                    v20,
                    LODWORD(StartX),
                    LODWORD(StartY),
                    LODWORD(DestX),
                    LODWORD(DestY),
                    NumSteps,
                    0,
                    &AngleToTarget,
                    &HigherCalc)
              && !((int (__thiscall *)(TRIBE_Combat_Object *, RGE_Static_Object *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, float *, int *))v22)(
                    v2,
                    target,
                    v19 + Tile_Dx1,
                    v21 + Tile_Dy1,
                    LODWORD(StartX),
                    LODWORD(StartY),
                    LODWORD(DestX),
                    LODWORD(DestY),
                    NumSteps,
                    0,
                    &AngleToTarget,
                    &HigherCalc) )
            {
              ((void (__thiscall *)(TRIBE_Combat_Object *, RGE_Static_Object *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, float *, int *))v22)(
                v2,
                target,
                v19 + Tile_Dx2,
                v21 + Tile_Dy2,
                LODWORD(StartX),
                LODWORD(StartY),
                LODWORD(DestX),
                LODWORD(DestY),
                NumSteps,
                0,
                &AngleToTarget,
                &HigherCalc);
            }
          }
          --v40;
        }
        while ( v40 );
        v17 = HigherCalc;
      }
      if ( v17 < 1 )
        v17 = 0;
      if ( v17 > 0 )
        v17 = 1;
      result = v17 > 0;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004CC1B0) --------------------------------------------------------
char __thiscall TRIBE_Combat_Object::area_attack(TRIBE_Combat_Object *this, float x, float y, float z, RGE_Combat_Object *attacker, RGE_Static_Object *ignore_object)
{
  TRIBE_Combat_Object *v6; // edi@1
  double v7; // st7@1
  char result; // al@2
  signed __int16 v9; // si@3
  int v10; // eax@3
  int v11; // ecx@14
  int v12; // ebp@15
  RGE_Static_Object *v13; // esi@16
  RGE_Master_Static_Object *v14; // edx@17
  __int16 v15; // ax@17
  RGE_Master_Static_Object *v16; // ecx@23
  double v17; // st7@24
  char v19; // c0@24
  double v20; // st6@28
  double v21; // st7@29
  double v22; // st6@32
  RGE_Static_ObjectVtbl *v23; // ebx@36
  float v24; // ST24_4@36
  bool v25; // zf@40
  float attack_modifier; // [sp+18h] [bp-28h]@24
  int x0; // [sp+1Ch] [bp-24h]@3
  int x1; // [sp+20h] [bp-20h]@3
  int v29; // [sp+24h] [bp-1Ch]@12
  float ry; // [sp+28h] [bp-18h]@28
  int v31; // [sp+2Ch] [bp-14h]@14
  int v32; // [sp+30h] [bp-10h]@14
  int v33; // [sp+34h] [bp-Ch]@12
  RGE_Map *map; // [sp+38h] [bp-8h]@1
  float r2; // [sp+3Ch] [bp-4h]@1

  v6 = this;
  v7 = this->master_obj[1].construction_radius_y;
  map = this->owner->world->map;
  r2 = v7 * v7;
  if ( v7 > 0.0 )
  {
    x0 = (unsigned __int64)(signed __int64)(x - v7) - 2;
    x1 = (unsigned __int64)(signed __int64)(v7 + x) + 2;
    v9 = (unsigned __int64)(signed __int64)(y - v7) - 2;
    v10 = (unsigned __int64)(signed __int64)(v7 + y) + 2;
    if ( (signed __int16)x0 < 0 )
      LOWORD(x0) = 0;
    if ( (signed __int16)x1 > (signed __int16)(LOWORD(map->map_width) - 1) + 1 )
      LOWORD(x1) = map->map_width;
    if ( v9 < 0 )
      v9 = 0;
    if ( (signed __int16)v10 > (signed __int16)(LOWORD(map->map_height) - 1) + 1 )
      LOWORD(v10) = map->map_height;
    if ( v9 < (signed __int16)v10 )
    {
      v29 = v9;
      v33 = (signed __int16)v10 - v9;
      do
      {
        if ( (signed __int16)x0 < (signed __int16)x1 )
        {
          v11 = 24 * (signed __int16)x0;
          v31 = 24 * (signed __int16)x0;
          v32 = (signed __int16)x1 - (signed __int16)x0;
          do
          {
            v12 = *(int *)((char *)&map->map_row_offset[v29]->objects.list + v11);
            if ( v12 )
            {
              do
              {
                v13 = *(RGE_Static_Object **)v12;
                if ( *(RGE_Static_Object **)v12 != ignore_object )
                {
                  if ( (v14 = v6->master_obj, v15 = v14->id, v15 != 46) && v15 != 40 && v15 != 339 && v15 != 345
                    || v13->owner != v6->owner )
                  {
                    if ( (TRIBE_Combat_Object *)v13 != v6 )
                    {
                      v16 = v13->master_obj;
                      if ( (unsigned __int8)v16->area_effect_object_level >= v14[1].elevation_flag )
                      {
                        v17 = v13->world_x - x;
                        attack_modifier = v13->world_y - y;
                        if ( v19 )
                          v17 = -v17;
                        if ( attack_modifier < 0.0 )
                          attack_modifier = -attack_modifier;
                        v20 = v16->radius_x;
                        ry = v16->radius_y;
                        if ( v17 <= v20 )
                          v21 = 0.0;
                        else
                          v21 = v17 - v20;
                        if ( attack_modifier <= (double)ry )
                          v22 = 0.0;
                        else
                          v22 = attack_modifier - ry;
                        if ( r2 > v21 * v21 + v22 * v22
                          && (signed __int16)(100 * debug_rand(aCMsdevWorkAg_9, 1619) / 0x7FFF) <= v6->master_obj[1].attribute_type_held[2] )
                        {
                          v6->vfptr->calc_attack_modifier((RGE_Static_Object *)v6, v13);
                          v23 = v13->vfptr;
                          v24 = v21;
                          ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, RGE_Player *, RGE_Combat_Object *))v13->vfptr->damage)(
                            v13,
                            v6->master_obj[1].portrait_pict,
                            *(_DWORD *)&v6->master_obj[1].tile_req1,
                            LODWORD(v24),
                            v6->owner,
                            attacker);
                          if ( v13->hp < 1.0 )
                            ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, signed int))v23->set_attribute_amount)(
                              v13,
                              0,
                              0,
                              1);
                        }
                      }
                    }
                  }
                }
                v12 = *(_DWORD *)(v12 + 4);
              }
              while ( v12 );
              v11 = v31;
            }
            v11 += 24;
            v25 = v32 == 1;
            v31 = v11;
            --v32;
          }
          while ( !v25 );
        }
        v25 = v33 == 1;
        ++v29;
        --v33;
      }
      while ( !v25 );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004CC4C0) --------------------------------------------------------
char __thiscall TRIBE_Combat_Object::heal(TRIBE_Combat_Object *this, float healing)
{
  TRIBE_Combat_Object *v2; // esi@1
  RGE_Master_Static_Object *v3; // ecx@1
  __int16 v4; // ax@1
  char result; // al@5
  double v6; // st7@6
  double v7; // st6@6
  float modifier; // ST04_4@8
  float healinga; // [sp+14h] [bp+4h]@6

  v2 = this;
  v3 = this->master_obj;
  v4 = v3->object_group;
  if ( v4 == 2 || v4 == 20 || v4 == 21 || v4 == 22 )
  {
    v6 = (double)v3->hp;
    v7 = healing * v6 / (double)HIWORD(v3[1].hotkey_id);
    healinga = v7;
    if ( v7 + v2->hp > v6 )
      healinga = v6 - v2->hp;
    modifier = healinga / (double)(2 * v3->hp);
    if ( TRIBE_Player::pay_obj_cost((TRIBE_Player *)v2->owner, v3->id, modifier, 1) )
      result = RGE_Static_Object::heal((RGE_Static_Object *)&v2->vfptr, healinga);
    else
      result = 2;
  }
  else
  {
    result = RGE_Static_Object::heal((RGE_Static_Object *)&v2->vfptr, healing);
  }
  return result;
}

//----- (004CC570) --------------------------------------------------------
BOOL __thiscall TRIBE_Combat_Object::canRepair(TRIBE_Combat_Object *this)
{
  RGE_Master_Static_Object *v1; // eax@1
  float modifier; // ST08_4@1

  v1 = this->master_obj;
  modifier = ((double)v1->hp - this->hp) / (double)v1->hp;
  return TRIBE_Player::check_obj_cost((TRIBE_Player *)this->owner, v1->id, 0, modifier, 0) != 0;
}

//----- (004CC5B0) --------------------------------------------------------
void __thiscall TRIBE_Combat_Object::do_repair(TRIBE_Combat_Object *this, RGE_Static_Object *obj)
{
  RGE_Static_Object *v2; // ebp@1
  TRIBE_Combat_Object *v3; // esi@1
  RGE_Sprite *v4; // eax@4
  int v5; // ecx@4
  int v6; // ebx@4
  RGE_Static_Object **v7; // edi@5
  RGE_Static_Object *v8; // esi@6
  RGE_Master_Static_Object *v9; // edx@7
  __int16 v10; // ax@8
  RGE_Task *v11; // eax@14
  __int16 v12; // di@14
  RGE_Action *v13; // eax@17
  int v14; // esi@20
  UnitAIModule *v15; // ecx@25
  int v16; // eax@26
  int v17; // esi@26
  TRIBE_Combat_Object *v18; // [sp+10h] [bp-4h]@1
  RGE_Static_Object *obja; // [sp+18h] [bp+4h]@14

  v2 = obj;
  v3 = this;
  v18 = this;
  if ( (TRIBE_Combat_Object *)obj != this )
  {
    if ( this->master_obj->id != 156 )
      ((void (__stdcall *)(_DWORD))this->vfptr->transform)(*((_DWORD *)this->owner->master_objects + 156));
    v4 = v3->master_obj[1].undead_sprite;
    v5 = 0;
    v6 = *(_WORD *)&v4->pict_name[8];
    if ( v6 <= 0 )
    {
      v8 = obj;
    }
    else
    {
      v7 = *(RGE_Static_Object ***)&v4->pict_name[4];
      do
      {
        v8 = *v7;
        if ( HIWORD((*v7)->id) == 106 )
        {
          v9 = obj->master_obj;
          if ( v9->master_type == 80 )
          {
            v10 = (__int16)v8->master_obj;
            if ( v10 == -1 || !v10 )
              break;
          }
          if ( LOWORD(v8->master_obj) == v9->object_group )
            break;
        }
        v8 = 0;
        ++v5;
        ++v7;
      }
      while ( v5 < v6 );
    }
    v11 = RGE_Action_List::get_task(v18->actions);
    v12 = 0;
    obja = 0;
    if ( v11
      && (RGE_Task *)v8 == v11
      && RGE_Action_List::action_work(v18->actions, v2, v2->world_x, v2->world_y, v2->world_z) )
    {
      v13 = RGE_Action_List::get_action(v18->actions);
      v12 = v13->vfptr->type(v13);
      obja = (RGE_Static_Object *)1;
    }
    if ( !obja )
    {
      if ( v8 )
        v14 = ((int (__stdcall *)(RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v18->actions->vfptr->create_task_action)(
                v8,
                v2,
                LODWORD(v2->world_x),
                LODWORD(v2->world_y),
                LODWORD(v2->world_z));
      else
        v14 = 0;
      if ( v14 )
      {
        v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 24))(v14);
        (*(void (__thiscall **)(TRIBE_Combat_Object *, int))&v18->vfptr[1].gap4[28])(v18, v14);
      }
      else
      {
        v12 = 0;
      }
    }
    v15 = v18->unitAIValue;
    if ( v15 )
    {
      v16 = -1;
      v17 = -1;
      if ( v12 == 106 )
      {
        v17 = 618;
        v16 = 718;
      }
      UnitAIModule::setCurrentOrder(v15, v16);
      UnitAIModule::setCurrentAction(v18->unitAIValue, v17);
      UnitAIModule::setCurrentTarget(
        v18->unitAIValue,
        v2->id,
        v2->master_obj->object_group,
        v2->world_x,
        v2->world_y,
        v2->world_z);
      UnitAIModule::setTaskedByPlayer(v18->unitAIValue);
    }
  }
}
