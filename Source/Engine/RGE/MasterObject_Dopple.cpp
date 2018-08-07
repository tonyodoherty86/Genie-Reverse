
//----- (004510C0) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object *this, RGE_Master_Doppleganger_Object *other_object, int do_setup)
{
  RGE_Master_Doppleganger_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    (RGE_Master_Animated_Object *)&this->vfptr,
    (RGE_Master_Animated_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Doppleganger_Object::`vftable';
  if( do_setup )
    RGE_Master_Doppleganger_Object::setup(v3, other_object);
}
// 570520: using guessed type int (__thiscall *RGE_Master_Doppleganger_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451120) --------------------------------------------------------
RGE_Master_Doppleganger_Object *__thiscall RGE_Master_Doppleganger_Object::`vector deleting destructor'(RGE_Master_Doppleganger_Object *this, unsigned int __flags)
{
  RGE_Master_Doppleganger_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00451140) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  RGE_Master_Doppleganger_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    (RGE_Master_Animated_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Doppleganger_Object::`vftable';
  if( do_setup )
    RGE_Master_Doppleganger_Object::setup(v5, infile, infile, sprites, sounds);
}
// 570520: using guessed type int (__thiscall *RGE_Master_Doppleganger_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004511B0) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  RGE_Master_Doppleganger_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    (RGE_Master_Animated_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Doppleganger_Object::`vftable';
  if( do_setup )
    RGE_Master_Doppleganger_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 570520: using guessed type int (__thiscall *RGE_Master_Doppleganger_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451230) --------------------------------------------------------
int __thiscall RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object *this, RGE_Master_Doppleganger_Object *other_object)
{
  RGE_Master_Doppleganger_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Animated_Object::setup(
    (RGE_Master_Animated_Object *)&this->vfptr,
    (RGE_Master_Animated_Object *)&other_object->vfptr);
  v2->master_type = 25;
  v2->fog_flag = 3;
  return 1;
}

//----- (00451250) --------------------------------------------------------
int __userpurge RGE_Master_Doppleganger_Object::setup@<eax>(RGE_Master_Doppleganger_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Master_Doppleganger_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object *)&this->vfptr, a2, infile, sprites, sounds);
  v5->master_type = 25;
  return 1;
}

//----- (00451280) --------------------------------------------------------
int __thiscall RGE_Master_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  RGE_Master_Doppleganger_Object *v5; // esi@1
  int result; // eax@1

  v5 = this;
  RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  result = 1;
  v5->master_type = 25;
  v5->recyclable = 1;
  return result;
}

//----- (004512C0) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::~RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object *this)
{
  this->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Doppleganger_Object::`vftable';
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object((RGE_Master_Animated_Object *)&this->vfptr);
}
// 570520: using guessed type int (__thiscall *RGE_Master_Doppleganger_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004512D0) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::make_new_obj(RGE_Master_Doppleganger_Object *this, RGE_Player *owner, float x, float y, float z, RGE_Static_Object *obj_to_dopple)
{
  RGE_Master_Doppleganger_Object *v6; // edi@1
  RGE_Static_Object *v7; // eax@2
  RGE_Doppleganger_Object *v8; // eax@4

  v6 = this;
  if( this->recyclable && (v7 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
  {
    (*(void (__thiscall **)(RGE_Static_Object *, RGE_Master_Doppleganger_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD, RGE_Static_Object *))&v7->vfptr[1].gap4[0])(
      v7,
      v6,
      owner,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z),
      obj_to_dopple);
  }
  else
  {
    v8 = (RGE_Doppleganger_Object *)operator new(0xB0u);
    if( v8 )
      RGE_Doppleganger_Object::RGE_Doppleganger_Object(v8, v6, owner, x, y, z, 1, obj_to_dopple);
  }
}

//----- (004513B0) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::make_new_master(RGE_Master_Doppleganger_Object *this)
{
  RGE_Master_Doppleganger_Object *v1; // esi@1
  RGE_Master_Doppleganger_Object *v2; // eax@1

  v1 = this;
  v2 = (RGE_Master_Doppleganger_Object *)operator new(0xBCu);
  if( v2 )
    RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(v2, v1, 1);
}

//----- (00451420) --------------------------------------------------------
void __thiscall RGE_Master_Doppleganger_Object::copy_obj(RGE_Master_Doppleganger_Object *this, RGE_Master_Static_Object *source)
{
  RGE_Master_Animated_Object::copy_obj((RGE_Master_Animated_Object *)&this->vfptr, source);
}

//----- (00451430) --------------------------------------------------------
void __fastcall RGE_Master_Doppleganger_Object::save(RGE_Master_Doppleganger_Object *this, int a2, int outfile)
{
  RGE_Master_Animated_Object::save((RGE_Master_Animated_Object *)&this->vfptr, a2, outfile);
}
