
/**
 * @file    Engine\TRB\ActionDiscovery.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004CE530) --------------------------------------------------------
void __userpurge TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(TRIBE_Action_Discovery_Artifact *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Discovery_Artifact *v4; // esi@1
  RGE_Action_Object *v5; // ecx@1
  char *v6; // eax@1
  RGE_Action_Object *v7; // edx@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v5 = v4->obj;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Discovery_Artifact::`vftable';
  v4->action_type = 108;
  v6 = (char *)calloc(v5->owner->world->player_num, 1u);
  v7 = v4->obj;
  v4->flags = v6;
  rge_read(a2, infile, infile, v6, v7->owner->world->player_num);
}
// 575010: using guessed type int (__thiscall *TRIBE_Action_Discovery_Artifact::`vftable')(void *Memory, unsigned int __flags);

//----- (004CE5C0) --------------------------------------------------------
TRIBE_Action_Discovery_Artifact *__thiscall TRIBE_Action_Discovery_Artifact::`scalar deleting destructor'(TRIBE_Action_Discovery_Artifact *this, unsigned int __flags)
{
  TRIBE_Action_Discovery_Artifact *v2; // esi@1

  v2 = this;
  TRIBE_Action_Discovery_Artifact::~TRIBE_Action_Discovery_Artifact(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CE5F0) --------------------------------------------------------
void __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(TRIBE_Action_Discovery_Artifact *this, RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in)
{
  TRIBE_Action_Discovery_Artifact *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v4->task = task_in;
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Discovery_Artifact::`vftable';
  v4->action_type = 108;
  RGE_Action::set_target_obj((RGE_Action *)&v4->vfptr, target_obj_in);
  v4->flags = (char *)calloc(v4->obj->owner->world->player_num, 1u);
}
// 575010: using guessed type int (__thiscall *TRIBE_Action_Discovery_Artifact::`vftable')(void *Memory, unsigned int __flags);

//----- (004CE670) --------------------------------------------------------
void __thiscall TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(TRIBE_Action_Discovery_Artifact *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  TRIBE_Action_Discovery_Artifact *v6; // esi@1
  RGE_Action_Object *v7; // edx@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_x = x;
  v7 = v6->obj;
  v6->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Discovery_Artifact::`vftable';
  v6->action_type = 108;
  v6->target_y = y;
  v6->target_z = z;
  v6->flags = (char *)calloc(v7->owner->world->player_num, 1u);
}
// 575010: using guessed type int (__thiscall *TRIBE_Action_Discovery_Artifact::`vftable')(void *Memory, unsigned int __flags);

//----- (004CE6D0) --------------------------------------------------------
void __thiscall TRIBE_Action_Discovery_Artifact::save(TRIBE_Action_Discovery_Artifact *this, int outfile)
{
  TRIBE_Action_Discovery_Artifact *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, v2->flags, v2->obj->owner->world->player_num);
}

//----- (004CE700) --------------------------------------------------------
void __thiscall TRIBE_Action_Discovery_Artifact::first_in_stack(TRIBE_Action_Discovery_Artifact *this, char first_time)
{
  if ( first_time )
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(6);
}

//----- (004CE720) --------------------------------------------------------
void __thiscall TRIBE_Action_Discovery_Artifact::set_state(TRIBE_Action_Discovery_Artifact *this, char new_state)
{
  this->state = new_state;
  if ( new_state == 10 )
    LODWORD(this->timer) = 1077936128;
}

//----- (004CE740) --------------------------------------------------------
char __thiscall TRIBE_Action_Discovery_Artifact::update(TRIBE_Action_Discovery_Artifact *this)
{
  TRIBE_Action_Discovery_Artifact *v1; // esi@1
  unsigned __int8 v3; // c0@4
  unsigned __int8 v4; // c3@4
  char result; // al@5

  v1 = this;
  if ( this->state == 1 )
  {
    result = 1;
  }
  else
  {
    if ( this->state == 6 )
    {
      TRIBE_Action_Discovery_Artifact::check_objects(this);
      v1->vfptr->set_state((RGE_Action *)v1, 10);
    }
    else if ( this->state == 10 )
    {
      this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
      if ( v3 | v4 )
      {
        this->vfptr->set_state((RGE_Action *)this, 6);
        return 0;
      }
    }
    result = 0;
  }
  return result;
}

//----- (004CE7A0) --------------------------------------------------------
void __thiscall TRIBE_Action_Discovery_Artifact::check_objects(TRIBE_Action_Discovery_Artifact *this)
{
  TRIBE_Action_Discovery_Artifact *v1; // ebp@1
  RGE_Action_Object *v2; // esi@1
  RGE_Master_Static_Object *v3; // edi@1
  signed __int16 v4; // bx@1
  RGE_Player *v5; // ecx@1
  signed __int64 v6; // rax@1
  int v7; // edi@12
  int v8; // ecx@12
  int v9; // esi@13
  RGE_Player *v10; // eax@14
  char *v11; // eax@15
  bool v12; // zf@20
  int x0; // [sp+10h] [bp-1Ch]@1
  int x1; // [sp+14h] [bp-18h]@1
  int v15; // [sp+18h] [bp-14h]@10
  int v16; // [sp+1Ch] [bp-10h]@12
  int v17; // [sp+20h] [bp-Ch]@10
  TRIBE_Action_Discovery_Artifact *v18; // [sp+24h] [bp-8h]@1
  RGE_Map *map; // [sp+28h] [bp-4h]@1

  v1 = this;
  v18 = this;
  v2 = this->obj;
  v3 = v2->master_obj;
  x0 = (signed __int64)(v2->world_x - 1.0 - v3->radius_x);
  v4 = (signed __int64)(v2->world_y - 1.0 - v3->radius_y);
  x1 = (signed __int64)(v3->radius_x + v2->world_x - -1.0);
  v6 = (signed __int64)(v3->radius_y + v2->world_y - -1.0);
  v5 = v2->owner;
  HIDWORD(v6) = v5->world->map;
  map = v5->world->map;
  if ( (signed __int16)x0 < 0 )
    LOWORD(x0) = 0;
  if ( v4 < 0 )
    v4 = 0;
  if ( (signed int)(signed __int16)x1 >= *(_DWORD *)(HIDWORD(v6) + 8) )
    LOWORD(x1) = *(_WORD *)(HIDWORD(v6) + 8) - 1;
  if ( (signed int)(signed __int16)v6 >= *(_DWORD *)(HIDWORD(v6) + 12) )
    LOWORD(v6) = *(_WORD *)(HIDWORD(v6) + 12) - 1;
  if ( v4 <= (signed __int16)v6 )
  {
    v15 = 4 * v4;
    v17 = (signed __int16)v6 - v4 + 1;
    do
    {
      if ( (signed __int16)x0 <= (signed __int16)x1 )
      {
        v7 = 24 * (signed __int16)x0;
        v8 = (signed __int16)x1 - (signed __int16)x0 + 1;
        v16 = (signed __int16)x1 - (signed __int16)x0 + 1;
        do
        {
          v9 = *(_DWORD *)(*(_DWORD *)(v15 + *(_DWORD *)(HIDWORD(v6) + 36236)) + v7 + 16);
          if ( v9 )
          {
            do
            {
              v10 = *(RGE_Player **)(*(_DWORD *)v9 + 12);
              if ( v10 != v1->obj->owner )
              {
                v11 = &v1->flags[v10->id];
                if ( !*v11 )
                {
                  *v11 = 1;
                  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)v9 + 12)
                                                                                                  + 36)
                                                                                      + 648)
                                                                        + 24))(
                    *(_DWORD *)(*(_DWORD *)v9 + 12),
                    *(_DWORD *)(*(_DWORD *)v9 + 56),
                    *(_DWORD *)(*(_DWORD *)v9 + 60),
                    *(_DWORD *)(*(_DWORD *)v9 + 64));
                  v1 = v18;
                }
              }
              v9 = *(_DWORD *)(v9 + 4);
            }
            while ( v9 );
            v8 = v16;
            HIDWORD(v6) = map;
          }
          v7 += 24;
          v16 = --v8;
        }
        while ( v8 );
      }
      v12 = v17 == 1;
      v15 += 4;
      --v17;
    }
    while ( !v12 );
  }
}
