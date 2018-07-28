
//----- (00401FE0) --------------------------------------------------------
void __userpurge RGE_Action_Bird::RGE_Action_Bird(RGE_Action_Bird *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  RGE_Action_Bird *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&RGE_Action_Bird::`vftable';
  v4->action_type = 10;
}
// 56E0D8: using guessed type int (__thiscall *RGE_Action_Bird::`vftable')(void *Memory, unsigned int __flags);

//----- (00402010) --------------------------------------------------------
RGE_Action_Bird *__thiscall RGE_Action_Bird::`scalar deleting destructor'(RGE_Action_Bird *this, unsigned int __flags)
{
  RGE_Action_Bird *v2; // esi@1

  v2 = this;
  RGE_Action_Bird::~RGE_Action_Bird(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00402040) --------------------------------------------------------
void __thiscall RGE_Action_Bird::RGE_Action_Bird(RGE_Action_Bird *this, RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z)
{
  RGE_Action_Bird *v6; // esi@1

  v6 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v6->task = task_in;
  v6->target_y = y;
  v6->vfptr = (RGE_ActionVtbl *)&RGE_Action_Bird::`vftable';
  v6->action_type = 10;
  v6->target_x = x;
  v6->target_z = z;
}
// 56E0D8: using guessed type int (__thiscall *RGE_Action_Bird::`vftable')(void *Memory, unsigned int __flags);

//----- (00402080) --------------------------------------------------------
void __thiscall RGE_Action_Bird::first_in_stack(RGE_Action_Bird *this, char first_time)
{
  RGE_Action_Bird *v2; // esi@1

  v2 = this;
  if( first_time )
  {
    (*(void (__stdcall **)(_DWORD, _DWORD, signed int))&this->obj->vfptr->gap4[48])(
      LODWORD(this->obj->world_x),
      LODWORD(this->obj->world_y),
      1086324736);
    v2->vfptr->set_state((RGE_Action *)v2, 3);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
  }
}

//----- (004020C0) --------------------------------------------------------
void __thiscall RGE_Action_Bird::set_state(RGE_Action_Bird *this, char new_state)
{
  RGE_Action_Bird *v2; // esi@1
  int v3; // eax@4
  unsigned int v4; // eax@4
  RGE_Task *v5; // edx@4
  RGE_Sprite *v6; // eax@4
  int v7; // eax@5
  unsigned int v8; // eax@5
  RGE_Task *v9; // edx@5
  RGE_Action_Object *v10; // ecx@6

  v2 = this;
  this->state = new_state;
  if( new_state == 4 )
  {
    v7 = debug_rand(source_name, 68);
    v8 = (signed int)(10 * v7 + ((unsigned __int64)(-21474181090i64 * v7) >> 32)) >> 14;
    v9 = v2->task;
    v2->timer = (double)(signed int)(v8 + (v8 >> 31) + 5);
    v6 = v9->move_sprite;
  }
  else
  {
    if( new_state != 6 )
    {
      RGE_Action_List::delete_list(this->sub_actions);
      return;
    }
    v3 = debug_rand(source_name, 76);
    v4 = (signed int)(10 * v3 + ((unsigned __int64)(-21474181090i64 * v3) >> 32)) >> 14;
    v5 = v2->task;
    v2->timer = (double)(signed int)(v4 + (v4 >> 31) + 5);
    v6 = v5->work_sprite;
  }
  v10 = v2->obj;
  if( v6 )
    (*(void (__stdcall **)(RGE_Sprite *))&v10->vfptr->gap4[52])(v6);
  else
    (*(void (__stdcall **)(RGE_Sprite *))&v10->vfptr->gap4[52])(v10->master_obj->sprite);
}

//----- (00402180) --------------------------------------------------------
char __thiscall RGE_Action_Bird::update(RGE_Action_Bird *this)
{
  RGE_Action_Bird *v1; // esi@1
  char result; // al@7
  RGE_Map *v3; // edi@12
  int v4; // eax@12
  RGE_Action_Object *v5; // edx@12
  RGE_Action_Move_To *v6; // eax@12
  RGE_Action *v7; // eax@13

  v1 = this;
  if( this->timer > 0.0 )
    this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
  switch ( this->state )
  {
    case 4:
      if( this->timer <= 0.0 )
        this->vfptr->set_state((RGE_Action *)this, 6);
      if( (((int (*)(void))v1->sub_actions->vfptr->update)() & 0xFF) != 1 )
        goto LABEL_19;
      v1->vfptr->set_state((RGE_Action *)v1, 3);
      result = 0;
      break;
    case 6:
      if( this->timer <= 0.0 )
        this->vfptr->set_state((RGE_Action *)this, 4);
      if( (((int (*)(void))v1->sub_actions->vfptr->update)() & 0xFF) != 1 )
        goto LABEL_19;
      v1->vfptr->set_state((RGE_Action *)v1, 3);
      result = 0;
      break;
    case 3:
      v3 = this->obj->owner->world->map;
      this->target_x = (double)(v3->map_width * debug_rand(source_name, 132) / 0x7FFF);
      v4 = debug_rand(source_name, 133);
      v5 = v1->obj;
      v1->target_y = (double)(v3->map_height * v4 / 0x7FFF);
      v1->target_z = v5->world_z;
      v6 = (RGE_Action_Move_To *)operator new(0x44u);
      if( v6 )
        RGE_Action_Move_To::RGE_Action_Move_To(
          v6,
          v1->obj,
          v1->target_x,
          v1->target_y,
          v1->target_z,
          v1->task->work_range,
          v1->obj->sprite);
      else
        v7 = 0;
      if( v7 )
      {
        RGE_Action_List::add_action(v1->sub_actions, v7);
        v1->vfptr->set_state((RGE_Action *)v1, 4);
        result = 0;
      }
      else
      {
        v1->vfptr->set_state((RGE_Action *)v1, 3);
        result = 0;
      }
      break;
    case 1:
      result = 1;
      break;
    default:
LABEL_19:
      result = 0;
      break;
  }
  return result;
}
