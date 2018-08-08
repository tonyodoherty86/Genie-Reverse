
//----- (004CCA60) --------------------------------------------------------
void __thiscall TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Tree_Object *this, TRIBE_Master_Tree_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  TRIBE_Tree_Object *v7; // esi@1

  v7 = this;
  RGE_Static_Object::RGE_Static_Object(
    (RGE_Static_Object *)&this->vfptr,
    (RGE_Master_Static_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v7->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Tree_Object::`vftable';
  if ( do_setup )
    RGE_Static_Object::setup(
      (RGE_Static_Object *)&v7->vfptr,
      (RGE_Master_Static_Object *)&tobj->vfptr,
      obj_owner,
      x,
      y,
      z);
}
// 574CB0: using guessed type int (__thiscall *TRIBE_Tree_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004CCAF0) --------------------------------------------------------
TRIBE_Tree_Object *__thiscall TRIBE_Tree_Object::`vector deleting destructor'(TRIBE_Tree_Object *this, unsigned int __flags)
{
  TRIBE_Tree_Object *v2; // esi@1

  v2 = this;
  TRIBE_Tree_Object::~TRIBE_Tree_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CCB20) --------------------------------------------------------
void __userpurge TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Tree_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
  TRIBE_Tree_Object *v5; // esi@1

  v5 = this;
  RGE_Static_Object::RGE_Static_Object((RGE_Static_Object *)&this->vfptr, a2, infile, gworld, 0);
  v5->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Tree_Object::`vftable';
  if ( do_setup )
    RGE_Static_Object::setup((RGE_Static_Object *)&v5->vfptr, a2, infile, gworld);
}
// 574CB0: using guessed type int (__thiscall *TRIBE_Tree_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004CCB90) --------------------------------------------------------
void __thiscall TRIBE_Tree_Object::set_object_state(TRIBE_Tree_Object *this, char new_object_state)
{
  RGE_Static_Object::set_object_state((RGE_Static_Object *)&this->vfptr, new_object_state);
}
