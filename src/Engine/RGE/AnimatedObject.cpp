
//----- (0041A150) --------------------------------------------------------
void __thiscall RGE_Animated_Object::RGE_Animated_Object(RGE_Animated_Object *this, RGE_Master_Animated_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  RGE_Animated_Object *v7; // esi@1

  v7 = this;
  RGE_Static_Object::RGE_Static_Object(
    (RGE_Static_Object *)&this->vfptr,
    (RGE_Master_Static_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v7->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Animated_Object::`vftable';
  if ( do_setup )
    RGE_Animated_Object::setup(v7, tobj, obj_owner, x, y, z);
}
// 56EC10: using guessed type int (__thiscall *RGE_Animated_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0041A1E0) --------------------------------------------------------
RGE_Animated_Object *__thiscall RGE_Animated_Object::`vector deleting destructor'(RGE_Animated_Object *this, unsigned int __flags)
{
  RGE_Animated_Object *v2; // esi@1

  v2 = this;
  RGE_Animated_Object::~RGE_Animated_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0041A210) --------------------------------------------------------
void __userpurge RGE_Animated_Object::RGE_Animated_Object(RGE_Animated_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
  RGE_Animated_Object *v5; // esi@1

  v5 = this;
  RGE_Static_Object::RGE_Static_Object((RGE_Static_Object *)&this->vfptr, a2, infile, gworld, 0);
  v5->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Animated_Object::`vftable';
  if ( do_setup )
    RGE_Animated_Object::setup(v5, a2, infile, gworld);
}
// 56EC10: using guessed type int (__thiscall *RGE_Animated_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0041A280) --------------------------------------------------------
void __thiscall RGE_Animated_Object::recycle_in_to_game(RGE_Animated_Object *this, RGE_Master_Static_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Animated_Object *v6; // esi@1

  v6 = this;
  RGE_Static_Object::recycle_in_to_game((RGE_Static_Object *)&this->vfptr, tobj, obj_owner, x, y, z);
  LODWORD(v6->speed) = 0;
  RGE_Static_Object::set_sleep_flag((RGE_Static_Object *)&v6->vfptr, 0);
}

//----- (0041A2C0) --------------------------------------------------------
int __thiscall RGE_Animated_Object::setup(RGE_Animated_Object *this, RGE_Master_Animated_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Animated_Object *v6; // esi@1

  v6 = this;
  RGE_Static_Object::setup(
    (RGE_Static_Object *)&this->vfptr,
    (RGE_Master_Static_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z);
  v6->type = 20;
  LODWORD(v6->speed) = 0;
  RGE_Static_Object::set_sleep_flag((RGE_Static_Object *)&v6->vfptr, 0);
  return 1;
}

//----- (0041A310) --------------------------------------------------------
int __userpurge RGE_Animated_Object::setup@<eax>(RGE_Animated_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  RGE_Animated_Object *v4; // esi@1

  v4 = this;
  RGE_Static_Object::setup((RGE_Static_Object *)&this->vfptr, a2, infile, gworld);
  v4->type = 20;
  rge_read(a2, infile, infile, &v4->speed, 4);
  return 1;
}

//----- (0041A350) --------------------------------------------------------
char __thiscall RGE_Animated_Object::update(RGE_Animated_Object *this)
{
  RGE_Animated_Object *v1; // esi@1
  char v2; // bl@1

  v1 = this;
  v2 = RGE_Static_Object::update((RGE_Static_Object *)&this->vfptr);
  if ( v1->object_state == 3 )
  {
    if ( v1->master_obj->death_sprite )
      v1->vfptr->set_object_state((RGE_Static_Object *)v1, 4);
    else
      v1->vfptr->set_object_state((RGE_Static_Object *)v1, 5);
  }
  else if ( v1->object_state == 4
         && !(unsigned __int8)((int (__stdcall *)(RGE_Sprite *))v1->sprite_list->vfptr->is_animating)(v1->sprite) )
  {
    v1->object_state = 5;
    LODWORD(v1->speed) = 0;
  }
  ((void (__stdcall *)(_DWORD, _DWORD))v1->sprite_list->vfptr->update)(
    LODWORD(v1->owner->world->world_time_delta_seconds),
    LODWORD(v1->speed));
  return v2;
}

//----- (0041A3D0) --------------------------------------------------------
void __thiscall RGE_Animated_Object::save(RGE_Animated_Object *this, int outfile)
{
  RGE_Animated_Object *v2; // esi@1

  v2 = this;
  RGE_Static_Object::save((RGE_Static_Object *)&this->vfptr, outfile);
  rge_write(outfile, &v2->speed, 4);
}

//----- (0041A400) --------------------------------------------------------
void __thiscall RGE_Animated_Object::transform(RGE_Animated_Object *this, RGE_Master_Static_Object *obj)
{
  RGE_Static_Object::transform((RGE_Static_Object *)&this->vfptr, obj);
}

//----- (0041A410) --------------------------------------------------------
void __thiscall RGE_Animated_Object::set_being_worked_on(RGE_Animated_Object *this, RGE_Action_Object *work_obj, __int16 action_type, char attack_flag)
{
  RGE_Static_Object::set_being_worked_on((RGE_Static_Object *)&this->vfptr, work_obj, action_type, attack_flag);
}

//----- (0041A430) --------------------------------------------------------
void __thiscall RGE_Animated_Object::release_being_worked_on(RGE_Animated_Object *this, RGE_Static_Object *caller)
{
  RGE_Animated_Object *v2; // esi@1

  v2 = this;
  RGE_Static_Object::release_being_worked_on((RGE_Static_Object *)&this->vfptr, caller);
  RGE_Static_Object::set_sleep_flag((RGE_Static_Object *)&v2->vfptr, 0);
}

//----- (00405F40) --------------------------------------------------------
double __thiscall RGE_Animated_Object::getSpeed(RGE_Animated_Object *this)
{
  return this->speed;
}
