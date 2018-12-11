#include "Action.hpp"
#include "ActionList.hpp"

//----- (004D38E0) --------------------------------------------------------
TRIBE_Action::TRIBE_Action(int infile, RGE_Action_Object *obj_in, bool do_setup) :
    RGE_Action(infile, obj_in, do_setup)
{
  if (do_setup)
    TRIBE_Action::setup(infile, obj_in);
}
// 5753E0: using guessed type int (__thiscall *TRIBE_Action::`vftable')(void *Memory, unsigned int __flags);

//----- (004D3980) --------------------------------------------------------
TRIBE_Action::TRIBE_Action(RGE_Action_Object *obj_in, bool do_setup) :
    RGE_Action(obj_in, do_setup)
{
  if ( do_setup )
    TRIBE_Action::setup(obj_in);
}
// 5753E0: using guessed type int (__thiscall *TRIBE_Action::`vftable')(void *Memory, unsigned int __flags);

//----- (004D39E0) --------------------------------------------------------
bool TRIBE_Action::setup(int infile, RGE_Action_Object *obj_in)
{
  return RGE_Action::setup(infile, obj_in);
}

//----- (004D3A00) --------------------------------------------------------
bool TRIBE_Action::setup(RGE_Action_Object *obj_in)
{
  return RGE_Action::setup(obj_in);
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
