
//----- (0050F180) --------------------------------------------------------
void __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *this, TRIBE_Master_Tree_Object *other_object, int do_setup)
{
  TRIBE_Master_Tree_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Static_Object::RGE_Master_Static_Object(
    (RGE_Master_Static_Object *)&this->vfptr,
    (RGE_Master_Static_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Tree_Object::`vftable';
  if( do_setup )
  {
    RGE_Master_Static_Object::setup(
      (RGE_Master_Static_Object *)&v3->vfptr,
      (RGE_Master_Static_Object *)&other_object->vfptr);
    v3->master_type = 90;
  }
}
// 576790: using guessed type int (__thiscall *TRIBE_Master_Tree_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050F1F0) --------------------------------------------------------
TRIBE_Master_Tree_Object *__thiscall TRIBE_Master_Tree_Object::`scalar deleting destructor'(TRIBE_Master_Tree_Object *this, unsigned int __flags)
{
  TRIBE_Master_Tree_Object *v2; // esi@1

  v2 = this;
  TRIBE_Master_Tree_Object::~TRIBE_Master_Tree_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0050F220) --------------------------------------------------------
void __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  TRIBE_Master_Tree_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Static_Object::RGE_Master_Static_Object(
    (RGE_Master_Static_Object *)&this->vfptr,
    infile,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Tree_Object::`vftable';
  if( do_setup )
  {
    RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)&v5->vfptr, infile, infile, sprites, sounds);
    v5->master_type = 90;
  }
}
// 576790: using guessed type int (__thiscall *TRIBE_Master_Tree_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050F2A0) --------------------------------------------------------
void __thiscall TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  TRIBE_Master_Tree_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Static_Object::RGE_Master_Static_Object(
    (RGE_Master_Static_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Tree_Object::`vftable';
  if( do_setup )
  {
    RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)&v6->vfptr, infile, sprites, sounds, in_id);
    v6->master_type = 90;
  }
}
// 576790: using guessed type int (__thiscall *TRIBE_Master_Tree_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050F320) --------------------------------------------------------
void __thiscall TRIBE_Master_Tree_Object::make_new_obj(TRIBE_Master_Tree_Object *this, RGE_Player *owner, float x, float y, float z)
{
  TRIBE_Master_Tree_Object *v5; // esi@1
  TRIBE_Tree_Object *v6; // eax@1

  v5 = this;
  v6 = (TRIBE_Tree_Object *)operator new(0x88u);
  if( v6 )
    TRIBE_Tree_Object::TRIBE_Tree_Object(v6, v5, owner, x, y, z, 1);
}

//----- (0050F3A0) --------------------------------------------------------
void __thiscall TRIBE_Master_Tree_Object::make_new_master(TRIBE_Master_Tree_Object *this)
{
  TRIBE_Master_Tree_Object *v1; // esi@1
  TRIBE_Master_Tree_Object *v2; // eax@1

  v1 = this;
  v2 = (TRIBE_Master_Tree_Object *)operator new(0xB8u);
  if( v2 )
    TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(v2, v1, 1);
}
