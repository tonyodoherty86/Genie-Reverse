
/**
 * @file    Engine\TRB\ActionMakeObj.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D0DD0) --------------------------------------------------------
void __userpurge TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(TRIBE_Action_Make_Obj *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  int v4; // edi@1
  TRIBE_Action_Make_Obj *v5; // esi@1

  v4 = infile;
  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Make_Obj::`vftable';
  v5->action_type = 102;
  rge_read(a2, v4, v4, &v5->obj_id, 2);
  rge_read(a2, v4, v4, &v5->work_done, 4);
  rge_read(a2, v4, v4, &v5->unique_id, 4);
  if ( save_game_version < 7.23 )
    v5->pre_paid = 0;
  else
    rge_read(a2, infile, infile, &v5->pre_paid, 1);
}
// 5751A8: using guessed type int (__thiscall *TRIBE_Action_Make_Obj::`vftable')(void *Memory, unsigned int __flags);
// 58EBCC: using guessed type float save_game_version;

//----- (004D0E90) --------------------------------------------------------
TRIBE_Action_Make_Obj *__thiscall TRIBE_Action_Make_Obj::`scalar deleting destructor'(TRIBE_Action_Make_Obj *this, unsigned int __flags)
{
  TRIBE_Action_Make_Obj *v2; // esi@1

  v2 = this;
  TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D0EB0) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(TRIBE_Action_Make_Obj *this, RGE_Action_Object *obj_in, __int16 id, int uniqueID, char paid)
{
  TRIBE_Action_Make_Obj *v5; // esi@1

  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v5->pre_paid = paid;
  v5->unique_id = uniqueID;
  v5->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Make_Obj::`vftable';
  v5->action_type = 102;
  v5->obj_id = id;
  LODWORD(v5->work_done) = 0;
}
// 5751A8: using guessed type int (__thiscall *TRIBE_Action_Make_Obj::`vftable')(void *Memory, unsigned int __flags);

//----- (004D0FC0) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Obj::first_in_stack(TRIBE_Action_Make_Obj *this, char first_time)
{
  TRIBE_Action_Make_Obj *v2; // esi@1
  __int16 v3; // dx@2
  RGE_Action_Object *v4; // eax@3
  int v5; // ebx@3
  int v6; // ST10_4@3
  RGE_Action_Object *v7; // edi@4
  TRIBE_Player *v8; // ecx@4
  int v9; // ebx@5
  int v10; // ST10_4@5
  RGE_Action_Object *v11; // eax@6
  int v12; // edi@6
  int v13; // ST1C_4@6
  int v14; // ST18_4@6

  v2 = this;
  if ( first_time )
  {
    v3 = this->obj_id;
    if ( v3 < 0 )
    {
      v4 = this->obj;
      v5 = this->unique_id;
      v6 = v4->id;
      ((void (__stdcall *)(RGE_Player *, char *, _DWORD))v4->owner->vfptr->logMessage)(v4->owner, aCancelingTra_2, v3);
LABEL_6:
      v11 = v2->obj;
      v12 = v2->unique_id;
      v13 = v11->id;
      v14 = v2->obj_id;
      (*(void (__stdcall **)(_DWORD))&v11->owner->vfptr[1].gap4[16])(0);
      return;
    }
    v7 = this->obj;
    v8 = (TRIBE_Player *)v7->owner;
    if ( !v8->master_objects[v3] )
    {
      v9 = v2->unique_id;
      v10 = v7->id;
      ((void (__stdcall *)(TRIBE_Player *, char *, _DWORD))v8->vfptr->logMessage)(v8, aCancelingTra_3, v3);
      goto LABEL_6;
    }
    if ( v2->pre_paid || TRIBE_Player::pay_obj_cost(v8, v3, 1.0, 0) )
    {
      v2->vfptr->set_state((RGE_Action *)v2, 6);
    }
    else
    {
      v2->obj->owner->vfptr->logMessage(v2->obj->owner, aCancelingTra_1, v2->obj_id, v2->obj->id, v2->unique_id);
      (*(void (__stdcall **)(_DWORD, _DWORD, int, int))&v2->obj->owner->vfptr[1].gap4[16])(
        0,
        v2->obj_id,
        v2->obj->id,
        v2->unique_id);
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v2->obj->vfptr->notify)(
        v2->obj->id,
        v2->obj->id,
        505,
        619,
        0,
        0);
      v2->vfptr->set_state((RGE_Action *)v2, 1);
    }
  }
}

//----- (004D10E0) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Obj::set_state(TRIBE_Action_Make_Obj *this, char new_state)
{
  this->state = new_state;
}

//----- (004D10F0) --------------------------------------------------------
char __thiscall TRIBE_Action_Make_Obj::update(TRIBE_Action_Make_Obj *this)
{
  TRIBE_Action_Make_Obj *v1; // esi@1
  char result; // al@8
  RGE_Static_Object *newObject; // [sp+18h] [bp-4h]@6

  v1 = this;
  if ( this->state == 1 )
  {
    result = 1;
  }
  else if ( this->state != 6
         || (!rge_base_game->quick_build ? (this->work_done = *(float *)&this->obj->master_obj[1].obj_max
                                                            * this->obj->owner->world->world_time_delta_seconds
                                                            + this->work_done) : (LODWORD(this->work_done) = 1148846080),
             newObject = (RGE_Static_Object *)HIWORD(this->obj->owner->master_objects[this->obj_id][1].hotkey_id),
             (double)(signed int)newObject > this->work_done) )
  {
    result = 0;
  }
  else
  {
    this->vfptr->set_state((RGE_Action *)this, 1);
    if ( TRIBE_Action_Make_Obj::place_obj(v1, &newObject) )
    {
      rge_base_game->vfptr->notification(
        rge_base_game,
        102,
        v1->obj->owner->id,
        v1->obj_id,
        (signed __int64)v1->obj->world_x,
        (signed __int64)v1->obj->world_y);
      (*(void (__stdcall **)(_DWORD, int, int, int))&v1->obj->owner->vfptr[1].gap4[20])(
        v1->obj_id,
        v1->obj->id,
        v1->unique_id,
        newObject->id);
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
        v1->obj->id,
        v1->obj->id,
        506,
        619,
        0,
        0);
      result = 1;
    }
    else
    {
      TRIBE_Player::reimburse_obj_cost((TRIBE_Player *)v1->obj->owner, v1->obj_id);
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        104,
        v1->obj->owner->id,
        v1->obj_id,
        0,
        0);
      v1->obj->owner->vfptr->logMessage(v1->obj->owner, aCancelingTra_4, v1->obj_id, v1->obj->id, v1->unique_id);
      (*(void (__stdcall **)(_DWORD, _DWORD, int, int))&v1->obj->owner->vfptr[1].gap4[16])(
        0,
        v1->obj_id,
        v1->obj->id,
        v1->unique_id);
      ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
        v1->obj->id,
        v1->obj->id,
        505,
        619,
        0,
        0);
      result = 1;
    }
  }
  return result;
}

//----- (004D12B0) --------------------------------------------------------
char __thiscall TRIBE_Action_Make_Obj::place_obj(TRIBE_Action_Make_Obj *this, RGE_Static_Object **rObj)
{
  TRIBE_Action_Make_Obj *v2; // esi@1
  RGE_Action_Object *v3; // eax@1
  int v4; // edx@1
  RGE_Player *v5; // ecx@1
  RGE_Master_Static_Object *v6; // eax@1
  RGE_Master_Static_Object *v7; // edi@1
  double v8; // st7@1
  char (__thiscall *v9)(RGE_Master_Static_Object *, RGE_Player *, float, float, int *, char, char, char, char, char, char); // ebp@1
  double v10; // st7@1
  __int16 v11; // bx@2
  int v12; // edx@4
  int v13; // eax@5
  unsigned int v14; // edx@5
  signed int v15; // ST4C_4@7
  RGE_Action_Object *v16; // eax@7
  double v17; // st7@7
  signed int v18; // ST4C_4@10
  bool v19; // sf@14
  unsigned __int8 v20; // of@14
  float radius_x; // [sp+28h] [bp-18h]@1
  float radius_y; // [sp+2Ch] [bp-14h]@1
  float radius_2x; // [sp+30h] [bp-10h]@1
  float radius_2y; // [sp+34h] [bp-Ch]@1
  int index; // [sp+38h] [bp-8h]@1

  v2 = this;
  index = 0;
  v3 = this->obj;
  v4 = this->obj_id;
  v5 = v3->owner;
  v6 = v3->master_obj;
  v7 = v5->master_objects[v4];
  v8 = v6->radius_x + v7->radius_x - -0.0099999998;
  v9 = v7->vfptr->check_placement;
  radius_x = v8;
  radius_2x = v8 + v8;
  v10 = v6->radius_y + v7->radius_y - -0.0099999998;
  radius_y = v10;
  radius_2y = v10 + v10;
  while ( 2 )
  {
    v11 = 0;
    do
    {
      if ( v11 >= 40 )
      {
        v13 = debug_rand(aCMsdevWorkA_40, 194);
        v14 = (signed int)(2 * v13 + ((unsigned __int64)(-4294836218i64 * v13) >> 32)) >> 14;
        v12 = v14 + (v14 >> 31) + 2;
      }
      else
      {
        v12 = 2 * debug_rand(aCMsdevWorkA_40, 192) / 0x7FFF;
      }
      switch ( (signed __int16)v12 )
      {
        case 0:
          v2->target_y = v2->obj->world_y + radius_y;
          v15 = debug_rand(aCMsdevWorkA_40, 199);
          v16 = v2->obj;
          v17 = (double)v15;
          goto LABEL_11;
        case 1:
          v2->target_x = v2->obj->world_x - radius_x;
          v2->target_y = (double)debug_rand(aCMsdevWorkA_40, 203) * radius_2y * 0.000030518509
                       - radius_y
                       + v2->obj->world_y;
          break;
        case 2:
          v2->target_x = v2->obj->world_x + radius_x;
          v2->target_y = (double)debug_rand(aCMsdevWorkA_40, 207) * radius_2y * 0.000030518509
                       - radius_y
                       + v2->obj->world_y;
          break;
        case 3:
          v2->target_y = v2->obj->world_y - radius_y;
          v18 = debug_rand(aCMsdevWorkA_40, 211);
          v16 = v2->obj;
          v17 = (double)v18;
LABEL_11:
          v2->target_x = v17 * radius_2x * 0.000030518509 - radius_x + v16->world_x;
          break;
        default:
          break;
      }
      if ( !(unsigned __int8)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD, signed int))v9)(
                               v7,
                               v2->obj->owner,
                               LODWORD(v2->target_x),
                               LODWORD(v2->target_y),
                               0,
                               1,
                               1,
                               1,
                               0,
                               0,
                               1) )
      {
        *rObj = (RGE_Static_Object *)((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v2->obj->owner->master_objects[v2->obj_id]->vfptr->make_new_obj)(
                                       v2->obj->owner,
                                       LODWORD(v2->target_x),
                                       LODWORD(v2->target_y),
                                       LODWORD(v2->obj->world_z));
        return 1;
      }
      ++v11;
    }
    while ( v11 < 60 );
    radius_x = v7->radius_x + v7->radius_x + radius_x;
    radius_y = v7->radius_y + v7->radius_y + radius_y;
    radius_2x = v7->radius_x * 4.0 + radius_2x;
    v20 = __OFSUB__(index + 1, 3);
    v19 = (signed __int16)(index++ - 2) < 0;
    radius_2y = v7->radius_y * 4.0 + radius_2y;
    if ( v19 ^ v20 )
      continue;
    return 0;
  }
}

//----- (004D1550) --------------------------------------------------------
int __thiscall TRIBE_Action_Make_Obj::stop(TRIBE_Action_Make_Obj *this)
{
  TRIBE_Action_Make_Obj *v1; // esi@1

  v1 = this;
  this->obj->owner->vfptr->logMessage(this->obj->owner, aStoppingTrain8, this->obj_id, this->obj->id, this->unique_id);
  if ( v1->state != 1 )
  {
    v1->vfptr->set_state((RGE_Action *)v1, 1);
    if ( !v1->pre_paid )
      TRIBE_Player::reimburse_obj_cost((TRIBE_Player *)v1->obj->owner, v1->obj_id);
  }
  ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
    103,
    v1->obj->owner->id,
    v1->obj_id,
    0,
    0);
  ((void (__stdcall *)(int, int, signed int, signed int, _DWORD, _DWORD))v1->obj->vfptr->notify)(
    v1->obj->id,
    v1->obj->id,
    505,
    619,
    0,
    0);
  return 1;
}

//----- (004D15F0) --------------------------------------------------------
void __thiscall TRIBE_Action_Make_Obj::get_info(TRIBE_Action_Make_Obj *this, __int16 *id, __int16 *progress, char *name, __int16 name_size)
{
  *id = this->obj_id;
  if ( this->state == 1 )
    *progress = 100;
  else
    *progress = (signed __int64)(this->work_done
                               * 100.0
                               / (double)HIWORD(this->obj->owner->master_objects[this->obj_id][1].hotkey_id));
  if ( name )
  {
    strncpy(name, this->obj->owner->master_objects[this->obj_id]->name, name_size);
    name[name_size - 1] = 0;
  }
}
