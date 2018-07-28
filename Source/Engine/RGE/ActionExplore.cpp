
/**
 * @file    Engine\RGE\ActionExplore.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00402B40) --------------------------------------------------------
void __userpurge RGE_Action_Explore::RGE_Action_Explore(RGE_Action_Explore *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Explore *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Explore::`vftable';
  v4->action_type = 4;
}
// 56E1B0: using guessed type int (__thiscall *RGE_Action_Explore::`vftable')(void *Memory, unsigned int __flags);

//----- (00402B70) --------------------------------------------------------
RGE_Action_Explore *__thiscall RGE_Action_Explore::`vector deleting destructor'(RGE_Action_Explore *this, unsigned int __flags)
{
  RGE_Action_Explore *v2; // esi@1

  v2 = this;
  RGE_Action_Explore::~RGE_Action_Explore(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00402BA0) --------------------------------------------------------
void __thiscall RGE_Action_Explore::RGE_Action_Explore(RGE_Action_Explore *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  RGE_Action_Explore *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&RGE_Action_Explore::`vftable';
  v6->action_type = 4;
  v6->target_x = x;
  v6->target_z = z;
}
// 56E1B0: using guessed type int (__thiscall *RGE_Action_Explore::`vftable')(void *Memory, unsigned int __flags);

//----- (00402BE0) --------------------------------------------------------
void __thiscall RGE_Action_Explore::first_in_stack(RGE_Action_Explore *this, char first_time)
{
  if ( LODWORD(this->target_x) == -1082130432 )
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
  else
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(11);
}

//----- (00402C00) --------------------------------------------------------
void __thiscall RGE_Action_Explore::set_state(RGE_Action_Explore *this, char new_state)
{
  RGE_Action_Explore *v2; // esi@1
  RGE_ActionVtbl *v3; // edi@5
  RGE_Task *v4; // eax@6
  RGE_Sprite *v5; // eax@7
  RGE_Sprite *v6; // edi@8
  RGE_Action_Move_To *v7; // eax@10
  RGE_Action *v8; // eax@11
  RGE_Action *v9; // edi@11

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
        605,
        0,
        0);
      goto LABEL_3;
    case 1:
    case 0xD:
    case 0xE:
LABEL_3:
      (*(void (__stdcall **)(RGE_Sprite *))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      break;
    default:
      return;
    case 2:
      (*(void (__stdcall **)(_DWORD))&v2->obj->vfptr->gap4[52])(v2->obj->master_obj->sprite);
      v3 = v2->vfptr;
      v2->vfptr->set_target_obj((RGE_Action *)v2, 0);
      v3->set_target_obj2((RGE_Action *)v2, 0);
      LODWORD(v2->target_x) = -1082130432;
      LODWORD(v2->target_y) = -1082130432;
      LODWORD(v2->target_z) = -1082130432;
      break;
    case 0xB:
      v4 = v2->task;
      if ( v4 && (v5 = v4->move_sprite) != 0 )
        v6 = v5;
      else
        v6 = *(RGE_Sprite **)&v2->obj->master_obj[1].master_type;
      v7 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v7 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(v7, v2->obj, v2->target_x, v2->target_y, v2->target_z, 0.0, v6);
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      if ( v9 )
      {
        RGE_Action::setSubAction(v9, 1);
        RGE_Action_List::add_action(v2->sub_actions, v9);
      }
      else
      {
        v2->vfptr->set_state((RGE_Action *)v2, 13);
      }
      break;
  }
}

//----- (00402D90) --------------------------------------------------------
char __thiscall RGE_Action_Explore::update(RGE_Action_Explore *this)
{
  RGE_Action_Explore *v1; // esi@1
  char result; // al@4
  RGE_ActionVtbl *v3; // edi@6

  v1 = this;
  if ( this->state == 1 )
  {
    result = 1;
  }
  else
  {
    if ( this->state == 11 )
    {
      switch ( (unsigned __int8)((int (*)(void))this->sub_actions->vfptr->update)() )
      {
        case 4u:
          v3 = v1->vfptr;
          v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
          v3->set_state((RGE_Action *)v1, 11);
          return 0;
        case 1u:
        case 2u:
        case 5u:
          v1->vfptr->set_state((RGE_Action *)v1, 3);
          return 0;
        case 3u:
          v1->vfptr->set_state((RGE_Action *)v1, 13);
          break;
        default:
          break;
      }
    }
    else if ( this->state == 13 )
    {
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))this->obj->vfptr->notify)(
        this->obj->id,
        this->obj->id,
        505,
        605,
        0,
        0);
      v1->vfptr->set_state((RGE_Action *)v1, 2);
      return 3;
    }
    result = 0;
  }
  return result;
}

//----- (00402E40) --------------------------------------------------------
int __thiscall RGE_Action_Explore::work(RGE_Action_Explore *this, RGE_Static_Object *obj_in, float x, float y, float z)
{
  RGE_ActionVtbl *v5; // edx@3
  int result; // eax@3

  if ( x < 0.0 || y < 0.0 )
  {
    ((void (__stdcall *)(signed int))this->vfptr->set_state)(3);
    result = 1;
  }
  else
  {
    this->target_x = x;
    this->target_y = y;
    v5 = this->vfptr;
    this->target_z = z;
    ((void (__stdcall *)(signed int))v5->set_state)(11);
    result = 1;
  }
  return result;
}
