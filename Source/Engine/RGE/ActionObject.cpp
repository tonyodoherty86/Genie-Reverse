
/**
 * @file    Engine\RGE\ActionObject.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00405C60) --------------------------------------------------------
void __thiscall RGE_Action_Object::RGE_Action_Object(RGE_Action_Object *this, RGE_Master_Action_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  RGE_Action_Object *v7; // esi@1

  v7 = this;
  RGE_Moving_Object::RGE_Moving_Object(
    (RGE_Moving_Object *)&this->vfptr,
    (RGE_Master_Moving_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v7->lastActionValue = -1;
  v7->lastActionStateValue = -1;
  v7->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Action_Object::`vftable';
  if( do_setup )
    RGE_Action_Object::setup(v7, tobj, obj_owner, x, y, z);
}
// 56E420: using guessed type int (__thiscall *RGE_Action_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00405F70) --------------------------------------------------------
RGE_Action_Object *__thiscall RGE_Action_Object::`vector deleting destructor'(RGE_Action_Object *this, unsigned int __flags)
{
  RGE_Action_Object *v2; // esi@1

  v2 = this;
  RGE_Action_Object::~RGE_Action_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00405F90) --------------------------------------------------------
void __userpurge RGE_Action_Object::RGE_Action_Object(RGE_Action_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
  RGE_Action_Object *v5; // esi@1

  v5 = this;
  RGE_Moving_Object::RGE_Moving_Object((RGE_Moving_Object *)&this->vfptr, infile, gworld, 0);
  v5->lastActionValue = -1;
  v5->lastActionStateValue = -1;
  v5->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Action_Object::`vftable';
  if( do_setup )
    RGE_Action_Object::setup(v5, a2, infile, gworld);
}
// 56E420: using guessed type int (__thiscall *RGE_Action_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004060D0) --------------------------------------------------------
int __thiscall RGE_Action_Object::setup(RGE_Action_Object *this, RGE_Master_Action_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Action_Object *v6; // esi@1
  RGE_Static_ObjectVtbl *v7; // edx@1

  v6 = this;
  RGE_Moving_Object::setup(
    (RGE_Moving_Object *)&this->vfptr,
    (RGE_Master_Moving_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z);
  v7 = v6->vfptr;
  v6->type = 40;
  v6->waiting = 0;
  v6->actions = (RGE_Action_List *)(*(int (__thiscall **)(RGE_Action_Object *))&v7[1].gap4[44])(v6);
  v6->command_flag = 0;
  return 1;
}

//----- (00406120) --------------------------------------------------------
int __userpurge RGE_Action_Object::setup@<eax>(RGE_Action_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  RGE_Action_Object *v4; // esi@1
  RGE_Action_List *v5; // eax@4

  v4 = this;
  RGE_Moving_Object::setup((RGE_Moving_Object *)&this->vfptr, a2, infile, gworld);
  v4->type = 40;
  rge_read(a2, infile, infile, &v4->waiting, 1);
  if( save_game_version < 6.5 )
    v4->command_flag = 0;
  else
    rge_read(a2, infile, infile, &v4->command_flag, 1);
  v5 = (RGE_Action_List *)(*(int (__thiscall **)(RGE_Action_Object *))&v4->vfptr[1].gap4[44])(v4);
  v4->actions = v5;
  RGE_Action_List::load(v5, infile);
  return 1;
}
// 58EBCC: using guessed type float save_game_version;

//----- (004061A0) --------------------------------------------------------
void __thiscall RGE_Action_Object::create_action_list(RGE_Action_Object *this)
{
  RGE_Action_Object *v1; // esi@1
  RGE_Action_List *v2; // eax@1

  v1 = this;
  v2 = (RGE_Action_List *)operator new(0xCu);
  if( v2 )
    RGE_Action_List::RGE_Action_List(v2, v1);
}

//----- (00406200) --------------------------------------------------------
void __thiscall RGE_Action_Object::rehook(RGE_Action_Object *this)
{
  RGE_Action_Object *v1; // esi@1

  v1 = this;
  RGE_Static_Object::rehook((RGE_Static_Object *)&this->vfptr);
  RGE_Action_List::rehook(v1->actions);
}

//----- (00406220) --------------------------------------------------------
void __thiscall RGE_Action_Object::save(RGE_Action_Object *this, int outfile)
{
  RGE_Action_Object *v2; // esi@1

  v2 = this;
  RGE_Moving_Object::save((RGE_Moving_Object *)&this->vfptr, outfile);
  rge_write(outfile, &v2->waiting, 1);
  rge_write(outfile, &v2->command_flag, 1);
  RGE_Action_List::save(v2->actions, outfile);
}

//----- (00406270) --------------------------------------------------------
void __thiscall RGE_Action_Object::transform(RGE_Action_Object *this, RGE_Master_Static_Object *obj)
{
  RGE_Action_Object *v2; // esi@1

  v2 = this;
  RGE_Moving_Object::transform((RGE_Moving_Object *)&this->vfptr, obj);
  RGE_Action_List::delete_list(v2->actions);
}

//----- (00406290) --------------------------------------------------------
void __thiscall RGE_Action_Object::destroy_obj(RGE_Action_Object *this)
{
  RGE_Action_Object *v1; // esi@1

  v1 = this;
  RGE_Action_List::delete_list(this->actions);
  RGE_Static_Object::destroy_obj((RGE_Static_Object *)&v1->vfptr);
}

//----- (004062C0) --------------------------------------------------------
void __thiscall RGE_Action_Object::do_command(RGE_Action_Object *this, RGE_Static_Object *obj, float x, float y, float z)
{
  RGE_Action_Object *v5; // esi@1

  v5 = this;
  if( (RGE_Action_Object *)obj != this )
  {
    (*(void (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, _DWORD))&this->vfptr[1].gap4[12])(
      obj,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z),
      0);
    ++v5->command_flag;
  }
}

//----- (00406300) --------------------------------------------------------
void __thiscall RGE_Action_Object::move_to(RGE_Action_Object *this, RGE_Static_Object *obj, float x, float y, float z)
{
  RGE_Static_Object *v5; // edi@1
  RGE_Action_Object *v6; // esi@1
  RGE_Action_Move_To *v7; // eax@4
  RGE_Static_Object *v8; // eax@5
  RGE_Action_Move_To *v9; // eax@6
  UnitAIModule *v10; // ecx@9
  RGE_Static_Object *obja; // [sp+20h] [bp+4h]@9

  v5 = obj;
  v6 = this;
  if( (RGE_Action_Object *)obj == this || RGE_Action_List::action_move_to(this->actions, obj, x, y, z) )
    return;
  if( !obj )
  {
    v9 = (RGE_Action_Move_To *)operator new(0x44u);
    if( v9 )
    {
      RGE_Action_Move_To::RGE_Action_Move_To(v9, v6, x, y, z, 0.40000001, 0);
      goto LABEL_9;
    }
LABEL_8:
    v8 = 0;
    goto LABEL_9;
  }
  v7 = (RGE_Action_Move_To *)operator new(0x44u);
  if( !v7 )
    goto LABEL_8;
  RGE_Action_Move_To::RGE_Action_Move_To(v7, v6, obj, 0.40000001, 0);
LABEL_9:
  v10 = v6->unitAIValue;
  obja = v8;
  if( v10 )
  {
    UnitAIModule::setCurrentOrder(v10, 710);
    UnitAIModule::setCurrentAction(v6->unitAIValue, 610);
    if( v5 )
      UnitAIModule::setCurrentTarget(v6->unitAIValue, v5->id, v5->master_obj->object_group, x, y, z);
    else
      UnitAIModule::setCurrentTarget(v6->unitAIValue, -1, -1, x, y, z);
  }
  if( obja )
    (*(void (__thiscall **)(RGE_Action_Object *, RGE_Static_Object *))&v6->vfptr[1].gap4[28])(v6, obja);
  ++v6->command_flag;
}

//----- (00406430) --------------------------------------------------------
void __thiscall RGE_Action_Object::work(RGE_Action_Object *this, RGE_Static_Object *obj, float x, float y, float z)
{
  RGE_Action_Object *v5; // esi@1

  v5 = this;
  if( (RGE_Action_Object *)obj != this )
  {
    (*(void (__stdcall **)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, signed int))&this->vfptr[1].gap4[12])(
      obj,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z),
      1);
    ++v5->command_flag;
  }
}

//----- (00406470) --------------------------------------------------------
void __thiscall RGE_Action_Object::work2(RGE_Action_Object *this, RGE_Static_Object *obj, float x, float y, float z, char work_flag)
{
  RGE_Static_Object *v6; // ebp@1
  RGE_Action_Object *v7; // esi@1
  float v8; // edi@2
  int v9; // ebx@2
  RGE_Player *v10; // eax@4
  signed int v11; // ecx@4
  RGE_Master_Static_Object *v12; // edi@5
  RGE_Master_Static_Object *v13; // eax@6
  RGE_Task *v14; // eax@15
  RGE_Action *v15; // eax@18
  RGE_Action *v16; // eax@20
  RGE_Action *v17; // eax@21
  RGE_Action *v18; // eax@22
  RGE_Action *v19; // eax@23
  signed int v20; // eax@23
  int v21; // ebx@27
  UnitAIModule *v22; // ecx@32
  int v23; // eax@33
  int v24; // edi@33
  int skip; // [sp+34h] [bp-4h]@15
  RGE_Static_Object *obja; // [sp+3Ch] [bp+4h]@4
  RGE_Static_Object *objb; // [sp+3Ch] [bp+4h]@15

  v6 = obj;
  v7 = this;
  if( (RGE_Action_Object *)obj == this )
    return;
  v8 = z;
  v9 = (*(int (__stdcall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->master_obj[1].undead_sprite
                                                                                              + 4))(
         this,
         obj,
         LODWORD(x),
         LODWORD(y),
         LODWORD(z));
  if( v9 )
    goto LABEL_15;
  if( !LOBYTE(v7->master_obj[1].radius_y) )
    goto LABEL_15;
  v10 = v7->owner;
  v11 = 0;
  obja = 0;
  if( v10->master_object_num <= 0 )
    goto LABEL_15;
  while( 1 )
  {
    v12 = v10->master_objects[v11];
    if( !v12 )
      goto LABEL_11;
    v13 = v7->master_obj;
    if( v12->object_group != v13->object_group
      || v12->master_type != v13->master_type
      || LOBYTE(v12[1].radius_y) != LOBYTE(v13[1].radius_y) )
    {
      goto LABEL_11;
    }
    v9 = (*(int (__stdcall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12[1].undead_sprite
                                                                                                + 4))(
           v7,
           v6,
           LODWORD(x),
           LODWORD(y),
           LODWORD(z));
    if( v9 )
      break;
    v11 = (signed int)obja;
LABEL_11:
    v10 = v7->owner;
    obja = (RGE_Static_Object *)++v11;
    if( v11 >= v10->master_object_num )
      goto LABEL_14;
  }
  v7->vfptr->transform((RGE_Static_Object *)v7, v12);
LABEL_14:
  v8 = z;
LABEL_15:
  v14 = RGE_Action_List::get_task(v7->actions);
  skip = 0;
  objb = (RGE_Static_Object *)-1;
  if( v14 && (RGE_Task *)v9 == v14 && RGE_Action_List::action_work(v7->actions, v6, x, y, v8) )
  {
    v15 = RGE_Action_List::get_action(v7->actions);
    objb = (RGE_Static_Object *)v15->vfptr->type(v15);
    skip = 1;
  }
  if( RGE_Action_List::have_action(v7->actions) == 1
    && (v16 = RGE_Action_List::get_action(v7->actions), v16->vfptr->get_target_obj(v16) == v6)
    && (v17 = RGE_Action_List::get_action(v7->actions), v17->vfptr->type(v17) == 9)
    && (v18 = RGE_Action_List::get_action(v7->actions),
        ((int (__thiscall *)(RGE_Action *, RGE_Static_Object *, _DWORD, _DWORD, float))v18->vfptr->work)(
          v18,
          v6,
          LODWORD(x),
          LODWORD(y),
          COERCE_FLOAT(LODWORD(v8)))) )
  {
    v19 = RGE_Action_List::get_action(v7->actions);
    objb = (RGE_Static_Object *)v19->vfptr->type(v19);
    v20 = 1;
  }
  else
  {
    v20 = skip;
  }
  if( !v20 )
  {
    if( v9 )
      v21 = ((int (__stdcall *)(int, RGE_Static_Object *, _DWORD, _DWORD, float))v7->actions->vfptr->create_task_action)(
              v9,
              v6,
              LODWORD(x),
              LODWORD(y),
              COERCE_FLOAT(LODWORD(v8)));
    else
      v21 = 0;
    if( v21 )
    {
      objb = (RGE_Static_Object *)(*(int (__thiscall **)(int))(*(_DWORD *)v21 + 24))(v21);
      (*(void (__thiscall **)(RGE_Action_Object *, int))&v7->vfptr[1].gap4[28])(v7, v21);
    }
    else
    {
      objb = (RGE_Static_Object *)1;
      ((void (__thiscall *)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, float))v7->vfptr->move_to)(
        v7,
        v6,
        LODWORD(x),
        LODWORD(y),
        COERCE_FLOAT(LODWORD(v8)));
    }
  }
  v22 = v7->unitAIValue;
  if( v22 )
  {
    v23 = -1;
    v24 = -1;
    switch ( (signed __int16)objb )
    {
      case 9:
        v24 = 600;
        v23 = 700;
        break;
      case 101:
        v24 = 602;
        v23 = 702;
        break;
      case 3:
        v24 = 617;
        v23 = 717;
        break;
      case 4:
        v24 = 605;
        v23 = 705;
        break;
      case 5:
        v24 = 609;
        v23 = 709;
        break;
      case 1:
        v24 = 610;
        v23 = 710;
        break;
      case 110:
        v24 = 613;
        v23 = 713;
        break;
      case 12:
        v24 = 614;
        v23 = 714;
        break;
      case 111:
        v24 = 615;
        v23 = 715;
        break;
      case 104:
        v24 = 604;
        v23 = 704;
        break;
      case 105:
        v24 = 603;
        v23 = 703;
        break;
      case 106:
        v24 = 618;
        v23 = 718;
        break;
      default:
        break;
    }
    UnitAIModule::setCurrentOrder(v22, v23);
    UnitAIModule::setCurrentAction(v7->unitAIValue, v24);
    if( v6 )
      UnitAIModule::setCurrentTarget(v7->unitAIValue, v6->id, v6->master_obj->object_group, x, y, z);
    else
      UnitAIModule::setCurrentTarget(v7->unitAIValue, -1, -1, x, y, z);
    UnitAIModule::setTaskedByPlayer(v7->unitAIValue);
  }
}

//----- (00406840) --------------------------------------------------------
void __thiscall RGE_Action_Object::play_command_sound(RGE_Action_Object *this)
{
  ((void (*)(void))this->master_obj->vfptr->play_command_sound)();
}

//----- (00406850) --------------------------------------------------------
void __thiscall RGE_Action_Object::play_move_sound(RGE_Action_Object *this)
{
  ((void (*)(void))this->master_obj->vfptr->play_move_sound)();
}

//----- (00406860) --------------------------------------------------------
RGE_Master_Static_Object *__thiscall RGE_Action_Object::get_command_master(RGE_Action_Object *this, RGE_Static_Object *obj, float x, float y, float z)
{
  RGE_Static_Object *v5; // ebx@1
  RGE_Action_Object *v6; // edi@1
  RGE_Master_Static_Object *v7; // eax@2
  bool v8; // zf@3
  RGE_Master_Static_Object *result; // eax@3
  RGE_Player *v10; // eax@5
  signed int v11; // ecx@5
  RGE_Master_Static_Object *v12; // esi@6
  RGE_Master_Static_Object *v13; // eax@7
  RGE_Static_Object *obja; // [sp+28h] [bp+4h]@5

  v5 = obj;
  v6 = this;
  if( (RGE_Action_Object *)obj != this )
  {
    v7 = this->master_obj;
    if( LOBYTE(v7[1].radius_y) )
    {
      v8 = (*(int (__stdcall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7[1].undead_sprite
                                                                                                  + 4))(
             this,
             obj,
             LODWORD(x),
             LODWORD(y),
             LODWORD(z)) == 0;
      result = v6->master_obj;
      if( !v8 )
        return result;
      if( LOBYTE(result[1].radius_y) )
      {
        v10 = v6->owner;
        v11 = 0;
        obja = 0;
        if( v10->master_object_num > 0 )
        {
          while( 1 )
          {
            v12 = v10->master_objects[v11];
            if( v12 )
            {
              v13 = v6->master_obj;
              if( v12->object_group == v13->object_group
                && v12->master_type == v13->master_type
                && LOBYTE(v12[1].radius_y) == LOBYTE(v13[1].radius_y) )
              {
                if( (*(int (__stdcall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12[1].undead_sprite + 4))(
                       v6,
                       v5,
                       LODWORD(x),
                       LODWORD(y),
                       LODWORD(z)) )
                {
                  return v12;
                }
                v11 = (signed int)obja;
              }
            }
            v10 = v6->owner;
            obja = (RGE_Static_Object *)++v11;
            if( v11 >= v10->master_object_num )
              return v6->master_obj;
          }
        }
      }
    }
  }
  return v6->master_obj;
}

//----- (00406940) --------------------------------------------------------
void __thiscall RGE_Action_Object::set_task(RGE_Action_Object *this, __int16 task_id)
{
  RGE_Action_Object *v2; // esi@1
  RGE_Task *v3; // eax@1
  int v4; // eax@2

  v2 = this;
  v3 = RGE_Master_Action_Object::get_task((RGE_Master_Action_Object *)this->master_obj, task_id);
  if( v3 )
  {
    v4 = ((int (__stdcall *)(RGE_Task *, _DWORD, signed int, signed int, signed int))v2->actions->vfptr->create_task_action)(
           v3,
           0,
           -1082130432,
           -1082130432,
           -1082130432);
    if( v4 )
      (*(void (__thiscall **)(RGE_Action_Object *, int))&v2->vfptr[1].gap4[28])(v2, v4);
  }
}

//----- (00406990) --------------------------------------------------------
void __thiscall RGE_Action_Object::setTaskByTaskID(RGE_Action_Object *this, int t)
{
  RGE_Action_Object *v2; // esi@1
  RGE_Task *v3; // eax@1
  int v4; // eax@2

  v2 = this;
  v3 = RGE_Master_Action_Object::getTaskByTaskID((RGE_Master_Action_Object *)this->master_obj, t);
  if( v3 )
  {
    v4 = ((int (__stdcall *)(RGE_Task *, _DWORD, signed int, signed int, signed int))v2->actions->vfptr->create_task_action)(
           v3,
           0,
           -1082130432,
           -1082130432,
           -1082130432);
    if( v4 )
      (*(void (__thiscall **)(RGE_Action_Object *, int))&v2->vfptr[1].gap4[28])(v2, v4);
  }
}

//----- (004069E0) --------------------------------------------------------
void __thiscall RGE_Action_Object::set_action(RGE_Action_Object *this, RGE_Action *action)
{
  if( action )
    RGE_Action_List::add_action(this->actions, action);
}

//----- (00406A00) --------------------------------------------------------
void __thiscall RGE_Action_Object::set_only_action(RGE_Action_Object *this, RGE_Action *action)
{
  RGE_Action_Object *v2; // esi@1

  v2 = this;
  RGE_Action_List::delete_list(this->actions);
  if( action )
    RGE_Action_List::add_action(v2->actions, action);
}

//----- (00406A30) --------------------------------------------------------
void __thiscall RGE_Action_Object::set_end_action(RGE_Action_Object *this, RGE_Action *action)
{
  if( action )
    RGE_Action_List::add_action_at_end(this->actions, action);
}

//----- (00406A50) --------------------------------------------------------
void __thiscall RGE_Action_Object::stop(RGE_Action_Object *this)
{
  RGE_Action_Object *v1; // esi@1

  v1 = this;
  if( !RGE_Action_List::action_stop(this->actions) )
    RGE_Action_List::delete_list(v1->actions);
}

//----- (00406A70) --------------------------------------------------------
char __thiscall RGE_Action_Object::update(RGE_Action_Object *this)
{
  RGE_Action_Object *v1; // esi@1
  RGE_Action *v2; // eax@3
  signed int v3; // edi@3
  signed int v4; // ebx@3
  int v5; // eax@5
  RGE_Action_List *v6; // ecx@8
  char v7; // bl@8
  int v8; // eax@8
  char v10; // al@17

  v1 = this;
  if( actionFile )
  {
    if( RGE_Action_List::have_action(this->actions) )
    {
      v2 = RGE_Action_List::get_action(v1->actions);
      v3 = v2->vfptr->type(v2);
      v4 = RGE_Action_List::get_action(v1->actions)->state;
    }
    else
    {
      v3 = -1;
      v4 = -1;
    }
    v5 = v1->lastActionValue;
    if( v5 != v3 || v1->lastActionStateValue != v4 )
    {
      fprintf(actionFile, Format, v1->owner->world->world_time, v1->id, v5, v1->lastActionStateValue, v3, v4);
      v1->lastActionValue = v3;
      v1->lastActionStateValue = v4;
    }
  }
  LOBYTE(v8) = RGE_Animated_Object::update((RGE_Animated_Object *)&v1->vfptr);
  v6 = v1->actions;
  v7 = v8;
  LOBYTE(v8) = v1->object_state;
  if( (unsigned __int8)v8 <= 2u )
  {
    if( v6->list )
    {
      if( v1->inside_obj )
      {
        ((void (*)(void))v6->vfptr->inside_obj_update)();
        return v7;
      }
      v10 = ((int (*)(void))v6->vfptr->update)();
      if( v10 == 3 || v10 == 1 )
        RGE_Action_List::remove_action(v1->actions);
    }
    else if( (_BYTE)v8 == 2 )
    {
      LOWORD(v8) = *(_WORD *)&v1->master_obj[1].undead_flag;
      if( (_WORD)v8 != -1 )
      {
        (*(void (__thiscall **)(RGE_Action_Object *, int))&v1->vfptr[1].gap4[16])(v1, v8);
        return v7;
      }
    }
  }
  else if( v6->list )
  {
    RGE_Action_List::delete_list(v6);
    return v7;
  }
  return v7;
}

//----- (00406B90) --------------------------------------------------------
void __userpurge RGE_Action_Object::change_ownership(RGE_Action_Object *this@<ecx>, int a2@<ebp>, RGE_Player *new_owner)
{
  RGE_Action_Object *v3; // esi@1
  RGE_Static_ObjectVtbl *v4; // edi@1

  v3 = this;
  v4 = this->vfptr;
  ((void (*)(void))this->vfptr->stop)();
  RGE_Static_Object::change_ownership((RGE_Static_Object *)&v3->vfptr, a2, new_owner);
  (*(void (__thiscall **)(RGE_Action_Object *, _DWORD))&v4[1].gap4[28])(v3, 0);
}

//----- (00406BC0) --------------------------------------------------------
void __thiscall RGE_Action_Object::copy_obj(RGE_Action_Object *this, RGE_Master_Static_Object *source)
{
  RGE_Action_Object *v2; // esi@1

  v2 = this;
  ((void (__stdcall *)(_DWORD))this->actions->vfptr->copy_obj)(source);
  RGE_Moving_Object::copy_obj((RGE_Moving_Object *)&v2->vfptr, source);
}

//----- (00406BF0) --------------------------------------------------------
bool __thiscall RGE_Action_Object::have_action(RGE_Action_Object *this)
{
  return RGE_Action_List::have_action(this->actions) != 0;
}

//----- (00406C10) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Action_Object::get_target_obj(RGE_Action_Object *this)
{
  RGE_Action *v1; // eax@1
  RGE_Static_Object *result; // eax@2

  v1 = RGE_Action_List::get_action(this->actions);
  if( v1 )
    result = v1->vfptr->get_target_obj(v1);
  else
    result = 0;
  return result;
}

//----- (00406C30) --------------------------------------------------------
RGE_Task *__thiscall RGE_Action_Object::getTask(RGE_Action_Object *this, RGE_Static_Object *target, float targetX, float targetY, float targetZ)
{
  float v5; // ebp@1
  RGE_Action_Object *v6; // edi@1
  int v7; // ebx@1
  RGE_Player *v8; // eax@3
  signed int v9; // ecx@3
  RGE_Master_Static_Object *v10; // esi@4
  RGE_Master_Static_Object *v11; // eax@5
  float targetZa; // [sp+28h] [bp+10h]@3

  v5 = targetZ;
  v6 = this;
  v7 = (*(int (__stdcall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->master_obj[1].undead_sprite
                                                                                              + 4))(
         this,
         target,
         LODWORD(targetX),
         LODWORD(targetY),
         LODWORD(targetZ));
  if( v7 )
    return (RGE_Task *)v7;
  if( !LOBYTE(v6->master_obj[1].radius_y) )
    return (RGE_Task *)v7;
  v8 = v6->owner;
  v9 = 0;
  targetZa = 0.0;
  if( v8->master_object_num <= 0 )
    return (RGE_Task *)v7;
  while( 1 )
  {
    v10 = v8->master_objects[v9];
    if( !v10 )
      goto LABEL_10;
    v11 = v6->master_obj;
    if( v10->object_group != v11->object_group
      || v10->master_type != v11->master_type
      || LOBYTE(v10[1].radius_y) != LOBYTE(v11[1].radius_y) )
    {
      goto LABEL_10;
    }
    v7 = (*(int (__stdcall **)(RGE_Action_Object *, RGE_Static_Object *, _DWORD, _DWORD, float))(*(_DWORD *)v10[1].undead_sprite
                                                                                               + 4))(
           v6,
           target,
           LODWORD(targetX),
           LODWORD(targetY),
           COERCE_FLOAT(LODWORD(v5)));
    if( v7 )
      break;
    v9 = LODWORD(targetZa);
LABEL_10:
    v8 = v6->owner;
    ++v9;
    targetZa = *(float *)&v9;
    if( v9 >= v8->master_object_num )
      return (RGE_Task *)v7;
  }
  v6->vfptr->transform((RGE_Static_Object *)v6, v10);
  return (RGE_Task *)v7;
}

//----- (00406D00) --------------------------------------------------------
char __thiscall RGE_Action_Object::actionState(RGE_Action_Object *this)
{
  RGE_Action_Object *v1; // esi@1
  char result; // al@2

  v1 = this;
  if( RGE_Action_List::have_action(this->actions) == 1 )
    result = RGE_Action_List::get_action(v1->actions)->state;
  else
    result = 0;
  return result;
}

//----- (00406D30) --------------------------------------------------------
int __thiscall RGE_Action_Object::get_action_checksum(RGE_Action_Object *this)
{
  RGE_Action_List *v1; // ecx@1
  int v2; // esi@1
  RGE_Action *v3; // eax@2

  v1 = this->actions;
  v2 = 0;
  if( v1 )
  {
    v3 = RGE_Action_List::get_action(v1);
    if( v3 )
      v2 = v3->state + v3->action_type;
  }
  return v2;
}
