
/**
 * @file    Engine\TRB\ActionMakeTech.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D21B0) --------------------------------------------------------
void __userpurge TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  int v4; // edi@1
  TRIBE_Action_Make_Tech *v5; // esi@1

  v4 = infile;
  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Make_Tech::`vftable';
  v5->action_type = 103;
  rge_read(a2, v4, v4, &v5->tech_id, 2);
  rge_read(a2, v4, v4, &v5->unique_id, 4);
}
// 575280: using guessed type int (__thiscall *TRIBE_Action_Make_Tech::`vftable')(void *Memory, unsigned int __flags);

//----- (004D2230) --------------------------------------------------------
TRIBE_Action_Make_Tech *__thiscall TRIBE_Action_Make_Tech::`scalar deleting destructor'(TRIBE_Action_Make_Tech *this, unsigned int __flags)
{
  TRIBE_Action_Make_Tech *v2; // esi@1

  v2 = this;
  TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D2250) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech *this, RGE_Action_Object *obj_in, __int16 id, int uID)
{
  TRIBE_Action_Make_Tech *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->unique_id = uID;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Make_Tech::`vftable';
  v4->action_type = 103;
  v4->tech_id = id;
}
// 575280: using guessed type int (__thiscall *TRIBE_Action_Make_Tech::`vftable')(void *Memory, unsigned int __flags);

//----- (004D2290) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech(TRIBE_Action_Make_Tech *this)
{
  TRIBE_Action_Make_Tech *v1; // esi@1

  v1 = this;
  this->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Make_Tech::`vftable';
  if ( this->state != 1 )
  {
    TRIBE_Player_Tech::cancel_research((TRIBE_Player_Tech *)this->obj->owner[1].vfptr, this->tech_id, 0);
    if ( !rge_base_game->world->game_state )
    {
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        101,
        v1->obj->owner->id,
        v1->tech_id,
        0,
        0);
      ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))v1->obj->owner->vfptr[1].isNeutral)(
        v1->tech_id,
        v1->obj->id,
        -1,
        v1->unique_id);
      ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
        v1->obj->id,
        v1->obj->id,
        505,
        620,
        0,
        0);
    }
  }
  RGE_Action::~RGE_Action((RGE_Action *)&v1->vfptr);
}
// 575280: using guessed type int (__thiscall *TRIBE_Action_Make_Tech::`vftable')(void *Memory, unsigned int __flags);

//----- (004D2370) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Tech::save(TRIBE_Action_Make_Tech *this, int outfile)
{
  TRIBE_Action_Make_Tech *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->tech_id, 2);
  rge_write(outfile, &v2->unique_id, 4);
}

//----- (004D23B0) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Tech::first_in_stack(TRIBE_Action_Make_Tech *this, char first_time)
{
  TRIBE_Action_Make_Tech *v2; // esi@1
  __int16 v3; // ax@2

  v2 = this;
  if ( first_time )
  {
    v3 = this->tech_id;
    if ( v3 >= 0 )
    {
      if ( TRIBE_Player_Tech::start_research(
             (TRIBE_Player_Tech *)this->obj->owner[1].vfptr,
             v3,
             1u,
             (__int16 *)&first_time) == 1 )
      {
        v2->vfptr->set_state((RGE_Action *)v2, 6);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v2->obj->owner->vfptr[1].isNeutral)(
          first_time,
          v2->tech_id,
          v2->obj->id,
          v2->unique_id);
        ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD))v2->obj->vfptr->notify)(
          v2->obj->id,
          v2->obj->id,
          505,
          620,
          0,
          0);
        v2->vfptr->set_state((RGE_Action *)v2, 1);
      }
    }
  }
}

//----- (004D2440) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Tech::set_state(TRIBE_Action_Make_Tech *this, char new_state)
{
  this->state = new_state;
}

//----- (004D2450) --------------------------------------------------------
char __thiscall TRIBE_Action_Make_Tech::update(TRIBE_Action_Make_Tech *this)
{
  TRIBE_Action_Make_Tech *v1; // esi@1
  float work; // ST28_4@5
  char v3; // al@4
  char result; // al@7

  v1 = this;
  if ( this->state == 1 )
  {
    result = 1;
  }
  else if ( this->state != 6
         || (!rge_base_game->quick_build ? (work = this->obj->owner->world->world_time_delta_seconds
                                                 * *(float *)&this->obj->master_obj[1].obj_max,
                                            v3 = TRIBE_Player_Tech::research(
                                                   (TRIBE_Player_Tech *)this->obj->owner[1].vfptr,
                                                   this->tech_id,
                                                   work)) : (v3 = TRIBE_Player_Tech::research(
                                                                    (TRIBE_Player_Tech *)this->obj->owner[1].vfptr,
                                                                    this->tech_id,
                                                                    1000.0)),
             v3) )
  {
    result = 0;
  }
  else
  {
    v1->vfptr->set_state((RGE_Action *)v1, 1);
    rge_base_game->vfptr->notification(
      rge_base_game,
      100,
      v1->obj->owner->id,
      v1->tech_id,
      (signed __int64)v1->obj->world_x,
      (signed __int64)v1->obj->world_y);
    ((void (__stdcall *)(_DWORD, int, int))v1->obj->owner->vfptr[1].isAllNeutral)(
      v1->tech_id,
      v1->obj->id,
      v1->unique_id);
    ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
      v1->obj->id,
      v1->obj->id,
      506,
      620,
      0,
      0);
    result = 1;
  }
  return result;
}

//----- (004D2550) --------------------------------------------------------
int __thiscall TRIBE_Action_Make_Tech::stop(TRIBE_Action_Make_Tech *this)
{
  TRIBE_Action_Make_Tech *v1; // esi@1

  v1 = this;
  ((void (__stdcall *)(signed int))this->vfptr->set_state)(1);
  TRIBE_Player_Tech::cancel_research((TRIBE_Player_Tech *)v1->obj->owner[1].vfptr, v1->tech_id, 1u);
  ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
    101,
    v1->obj->owner->id,
    v1->tech_id,
    0,
    0);
  ((void (__stdcall *)(_DWORD, int, signed int, int))v1->obj->owner->vfptr[1].isNeutral)(
    v1->tech_id,
    v1->obj->id,
    -1,
    v1->unique_id);
  ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
    v1->obj->id,
    v1->obj->id,
    505,
    620,
    0,
    0);
  return 1;
}

//----- (004D25E0) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Tech::get_info(TRIBE_Action_Make_Tech *this, __int16 *id, __int16 *progress, char *name, __int16 name_size)
{
  TRIBE_Action_Make_Tech *v5; // edi@1
  const char *v6; // eax@5

  v5 = this;
  *id = this->tech_id;
  if ( this->state == 1 )
    *progress = 100;
  else
    *progress = TRIBE_Player_Tech::get_progress((TRIBE_Player_Tech *)this->obj->owner[1].vfptr, this->tech_id);
  if ( name )
  {
    v6 = TRIBE_Player_Tech::get_name((TRIBE_Player_Tech *)v5->obj->owner[1].vfptr, v5->tech_id);
    strncpy(name, v6, name_size);
    name[name_size - 1] = 0;
  }
}
