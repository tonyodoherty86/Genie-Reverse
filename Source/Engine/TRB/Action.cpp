
//----- (004D38E0) --------------------------------------------------------
void __userpurge TRIBE_Action::TRIBE_Action(TRIBE_Action *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in, int do_setup)
{
  TRIBE_Action *v5; // esi@1

  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 0);
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action::`vftable';
  if ( do_setup )
    TRIBE_Action::setup(v5, a2, infile, obj_in);
}
// 5753E0: using guessed type int (__thiscall *TRIBE_Action::`vftable')(void *Memory, unsigned int __flags);

//----- (004D3950) --------------------------------------------------------
TRIBE_Action *__thiscall TRIBE_Action::`scalar deleting destructor'(TRIBE_Action *this, unsigned int __flags)
{
  TRIBE_Action *v2; // esi@1

  v2 = this;
  TRIBE_Action::~TRIBE_Action(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D3980) --------------------------------------------------------
void __thiscall TRIBE_Action::TRIBE_Action(TRIBE_Action *this, RGE_Action_Object *obj_in, int do_setup)
{
  TRIBE_Action *v3; // esi@1

  v3 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 0);
  v3->vfptr = (RGE_ActionVtbl *)&TRIBE_Action::`vftable';
  if ( do_setup )
    TRIBE_Action::setup(v3, obj_in);
}
// 5753E0: using guessed type int (__thiscall *TRIBE_Action::`vftable')(void *Memory, unsigned int __flags);

//----- (004D39E0) --------------------------------------------------------
int __userpurge TRIBE_Action::setup@<eax>(TRIBE_Action *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  return RGE_Action::setup((RGE_Action *)&this->vfptr, a2, infile, obj_in);
}

//----- (004D3A00) --------------------------------------------------------
int __thiscall TRIBE_Action::setup(TRIBE_Action *this, RGE_Action_Object *obj_in)
{
  return RGE_Action::setup((RGE_Action *)&this->vfptr, obj_in);
}

//----- (004D3A10) --------------------------------------------------------
void __thiscall TRIBE_Action::create_action_list(TRIBE_Action *this, RGE_Action_Object *obj_in)
{
  TRIBE_Action *v2; // esi@1
  TRIBE_Action_List *v3; // eax@1

  v2 = this;
  v3 = (TRIBE_Action_List *)operator new(0xCu);
  if ( v3 )
    TRIBE_Action_List::TRIBE_Action_List(v3, v2->obj);
}
