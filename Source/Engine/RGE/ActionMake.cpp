
/**
 * @file    Engine\RGE\ActionMake.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

#include "ActionMake.hpp"

//----- (004049B0) --------------------------------------------------------
void __userpurge RGE_Action_Make::RGE_Action_Make(RGE_Action_Make *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Make *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Make::`vftable';
  v4->action_type = 21;
}
// 56E2B8: using guessed type int (__thiscall *RGE_Action_Make::`vftable')(void *Memory, unsigned int __flags);

//----- (004049E0) --------------------------------------------------------
RGE_Action_Make *__thiscall RGE_Action_Make::`vector deleting destructor'(RGE_Action_Make *this, unsigned int __flags)
{
  RGE_Action_Make *v2; // esi@1

  v2 = this;
  RGE_Action_Make::~RGE_Action_Make(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00404A10) --------------------------------------------------------
void __thiscall RGE_Action_Make::RGE_Action_Make(RGE_Action_Make *this, RGE_Action_Object *obj_in, RGE_Task *task_in)
{
  RGE_Action_Make *v3; // esi@1

  v3 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v3->vfptr = (RGE_ActionVtbl *)&RGE_Action_Make::`vftable';
  v3->action_type = 21;
  v3->task = task_in;
}
// 56E2B8: using guessed type int (__thiscall *RGE_Action_Make::`vftable')(void *Memory, unsigned int __flags);

//----- (00404A40) --------------------------------------------------------
void __thiscall RGE_Action_Make::first_in_stack(RGE_Action_Make *this, char first_time)
{
  RGE_Action_Make *v2; // esi@1
  int v3; // eax@1
  RGE_Action_Object *v4; // ecx@2

  v2 = this;
  v3 = ((int (__stdcall *)(_DWORD))this->vfptr->set_state)(6);
  LOWORD(v3) = v2->task->attribute_type;
  if( (signed __int16)v3 >= 0 )
  {
    v4 = v2->obj;
    if( v4->attribute_type_held != (_WORD)v3 )
      ((void (__stdcall *)(int, _DWORD))v4->vfptr->set_attribute)(v3, 0);
  }
}

//----- (00404A70) --------------------------------------------------------
void __thiscall RGE_Action_Make::set_state(RGE_Action_Make *this, char new_state)
{
  RGE_Action_Object *v2; // edx@1

  v2 = this->obj;
  this->state = new_state;
  this->timer = v2->owner->attributes[36];
}

//----- (00404A90) --------------------------------------------------------
char __thiscall RGE_Action_Make::update(RGE_Action_Make *this)
{
  RGE_Action_Make *v1; // esi@1
  RGE_Action_Object *v2; // edi@4
  RGE_Player *v3; // ebx@4
  char result; // al@6
  RGE_Action_Object *v5; // eax@7
  RGE_Task *v6; // edx@7
  RGE_Player *v7; // ecx@7
  float work; // [sp+8h] [bp-8h]@7
  float pre_attribute; // [sp+Ch] [bp-4h]@7

  v1 = this;
  if( this->state == 1 )
  {
    result = 1;
  }
  else
  {
    if( this->state == 6 )
    {
      if( this->timer > 0.0 || (v2 = this->obj, v3 = v2->owner, v3->attributes[36] <= 0.0) )
      {
        v5 = this->obj;
        v6 = this->task;
        v7 = v5->owner;
        pre_attribute = v5->attribute_amount_held;
        work = *(float *)&v5->master_obj[1].obj_max * v7->world->world_time_delta_seconds * v6->work_val1;
        if( v6->work_flag )
        {
          LOWORD(v6) = v6->attribute_type;
          ((void (__stdcall *)(RGE_Task *, float, _DWORD))v7->vfptr->add_attribute_num)(
            v6,
            COERCE_FLOAT(LODWORD(work)),
            0);
        }
        else
        {
          v5->vfptr->set_attribute_amount((RGE_Static_Object *)v5, COERCE_FLOAT(LODWORD(work)), 1, 1);
        }
        v1->timer = v1->timer - (v1->obj->attribute_amount_held - pre_attribute);
      }
      else if( v2->attribute_amount_held <= 0.0 )
      {
        rge_base_game->vfptr->notification(
          rge_base_game,
          126,
          v3->id,
          v2->id,
          (signed __int64)v2->world_x,
          (signed __int64)v2->world_y);
        ((void (*)(void))v1->obj->vfptr->die_die_die)();
        return 0;
      }
    }
    result = 0;
  }
  return result;
}
