
//----- (0044F070) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object *this, RGE_Master_Action_Object *other_object, int do_setup)
{
  RGE_Master_Action_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    (RGE_Master_Moving_Object *)&this->vfptr,
    (RGE_Master_Moving_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Action_Object::`vftable';
  if( do_setup )
    RGE_Master_Action_Object::setup(v3, other_object);
}
// 570448: using guessed type int (__thiscall *RGE_Master_Action_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044F0D0) --------------------------------------------------------
RGE_Master_Action_Object *__thiscall RGE_Master_Action_Object::`vector deleting destructor'(RGE_Master_Action_Object *this, unsigned int __flags)
{
  RGE_Master_Action_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Action_Object::~RGE_Master_Action_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0044F0F0) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  RGE_Master_Action_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    (RGE_Master_Moving_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Action_Object::`vftable';
  if( do_setup )
    RGE_Master_Action_Object::setup(v5, infile, sprites, sounds);
}
// 570448: using guessed type int (__thiscall *RGE_Master_Action_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044F160) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::RGE_Master_Action_Object(RGE_Master_Action_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  RGE_Master_Action_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Moving_Object::RGE_Master_Moving_Object(
    (RGE_Master_Moving_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Action_Object::`vftable';
  if( do_setup )
    RGE_Master_Action_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 570448: using guessed type int (__thiscall *RGE_Master_Action_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044F1E0) --------------------------------------------------------
int __thiscall RGE_Master_Action_Object::setup(RGE_Master_Action_Object *this, RGE_Master_Action_Object *other_object)
{
  RGE_Master_Action_Object *v2; // esi@1
  RGE_Master_Static_ObjectVtbl *v3; // eax@1
  RGE_Task_List *v4; // eax@1

  v2 = this;
  RGE_Master_Moving_Object::setup(
    (RGE_Master_Moving_Object *)&this->vfptr,
    (RGE_Master_Moving_Object *)&other_object->vfptr);
  v2->master_type = 40;
  v2->default_task = other_object->default_task;
  v2->search_radius = other_object->search_radius;
  v2->work_rate = other_object->work_rate;
  v2->drop_site = other_object->drop_site;
  v2->backup_drop_site = other_object->backup_drop_site;
  v2->task_by_group = other_object->task_by_group;
  v2->command_sound = other_object->command_sound;
  v3 = v2->vfptr;
  v2->move_sound = other_object->move_sound;
  v2->run_pattern = other_object->run_pattern;
  v4 = (RGE_Task_List *)((int (__thiscall *)(RGE_Master_Action_Object *))v3[1].__vecDelDtor)(v2);
  v2->tasks = v4;
  RGE_Task_List::copy(v4, other_object->tasks);
  return 1;
}

//----- (0044F290) --------------------------------------------------------
int __thiscall RGE_Master_Action_Object::setup(RGE_Master_Action_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Sound **v4; // ebx@1
  RGE_Sprite **v5; // ebp@1
  int v6; // edi@1
  RGE_Master_Action_Object *v7; // esi@1
  RGE_Sound *v8; // eax@5
  RGE_Sound *v9; // eax@8
  RGE_Task_List *v10; // eax@10

  v4 = sounds;
  v5 = sprites;
  v6 = infile;
  v7 = this;
  RGE_Master_Moving_Object::setup((RGE_Master_Moving_Object *)&this->vfptr, (int)sprites, infile, sprites, sounds);
  v7->master_type = 40;
  rge_read((int)v5, v6, v6, &v7->default_task, 2);
  rge_read((int)v5, v6, v6, &v7->search_radius, 4);
  rge_read((int)v5, v6, v6, &v7->work_rate, 4);
  rge_read((int)v5, v6, v6, &v7->drop_site, 2);
  rge_read((int)v5, v6, v6, &v7->backup_drop_site, 2);
  rge_read((int)v5, v6, v6, &v7->task_by_group, 1);
  rge_read((int)v5, v6, v6, &sounds, 2);
  if( save_game_version < 6.9200001 )
    sprites = (RGE_Sprite **)sounds;
  else
    rge_read((int)v5, infile, infile, &sprites, 2);
  rge_read((int)v5, infile, infile, &v7->run_pattern, 1);
  if( (signed __int16)sounds < 0 )
    v8 = 0;
  else
    v8 = v4[(signed __int16)sounds];
  v7->command_sound = v8;
  if( (signed __int16)sprites < 0 )
    v9 = 0;
  else
    v9 = v4[(signed __int16)sprites];
  v7->move_sound = v9;
  v10 = (RGE_Task_List *)((int (__thiscall *)(RGE_Master_Action_Object *))v7->vfptr[1].__vecDelDtor)(v7);
  v7->tasks = v10;
  RGE_Task_List::load(v10, infile, infile, v5, v4);
  return 1;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0044F3C0) --------------------------------------------------------
int __thiscall RGE_Master_Action_Object::setup(RGE_Master_Action_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  _iobuf *v5; // ebx@1
  RGE_Sprite **v6; // ebp@1
  RGE_Sound **v7; // edi@1
  RGE_Master_Action_Object *v8; // esi@1
  char v9; // cl@1
  __int16 v10; // ax@1
  RGE_Sound *v11; // eax@2
  RGE_Sound *v12; // eax@5
  RGE_Master_Static_ObjectVtbl *v13; // edx@7
  RGE_Task_List *v14; // eax@7
  RGE_Task_List *v15; // edx@7
  int v16; // eax@7
  int v17; // ecx@7
  RGE_Task **v18; // edx@8

  v5 = infile;
  v6 = sprites;
  v7 = sounds;
  v8 = this;
  RGE_Master_Moving_Object::setup((RGE_Master_Moving_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  v8->master_type = 40;
  fscanf(
    v5,
    aFFHdHdHdHdHdHd,
    &v8->search_radius,
    &v8->work_rate,
    &v8->drop_site,
    &v8->backup_drop_site,
    &in_id,
    &sprites,
    &infile,
    &sounds);
  v9 = (char)sounds;
  v8->task_by_group = in_id;
  v10 = (signed __int16)sprites;
  v8->run_pattern = v9;
  if( v10 < 0 )
    v11 = 0;
  else
    v11 = v7[v10];
  v8->command_sound = v11;
  if( (signed __int16)infile < 0 )
    v12 = 0;
  else
    v12 = v7[(signed __int16)infile];
  v13 = v8->vfptr;
  v8->move_sound = v12;
  v14 = (RGE_Task_List *)((int (__thiscall *)(RGE_Master_Action_Object *))v13[1].__vecDelDtor)(v8);
  v8->tasks = v14;
  RGE_Task_List::load(v14, v5, v6, v7);
  v15 = v8->tasks;
  v8->default_task = -1;
  v16 = 0;
  v17 = v15->list_num;
  if( v17 > 0 )
  {
    v18 = v15->list;
    while( !(*v18)->is_default )
    {
      ++v16;
      ++v18;
      if( v16 >= v17 )
        return 1;
    }
    v8->default_task = v16;
  }
  return 1;
}

//----- (0044F5A0) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::make_new_obj(RGE_Master_Action_Object *this, RGE_Player *owner, float x, float y, float z)
{
  RGE_Master_Action_Object *v5; // edi@1
  RGE_Static_Object *v6; // eax@2
  RGE_Action_Object *v7; // eax@4

  v5 = this;
  if( this->recyclable && (v6 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
  {
    (*(void (__thiscall **)(RGE_Static_Object *, RGE_Master_Action_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[0])(
      v6,
      v5,
      owner,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z));
  }
  else
  {
    v7 = (RGE_Action_Object *)operator new(0x194u);
    if( v7 )
      RGE_Action_Object::RGE_Action_Object(v7, v5, owner, x, y, z, 1);
  }
}

//----- (0044F670) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::make_new_master(RGE_Master_Action_Object *this)
{
  RGE_Master_Action_Object *v1; // esi@1
  RGE_Master_Action_Object *v2; // eax@1

  v1 = this;
  v2 = (RGE_Master_Action_Object *)operator new(0xFCu);
  if( v2 )
    RGE_Master_Action_Object::RGE_Master_Action_Object(v2, v1, 1);
}

//----- (0044F6E0) --------------------------------------------------------
RGE_Task *__thiscall RGE_Master_Action_Object::get_task(RGE_Master_Action_Object *this, __int16 task_id)
{
  RGE_Task_List *v2; // eax@2
  RGE_Task *result; // eax@3

  if( task_id == -1 || (v2 = this->tasks, task_id >= v2->list_num) )
    result = 0;
  else
    result = v2->list[task_id];
  return result;
}

//----- (0044F710) --------------------------------------------------------
RGE_Task *__thiscall RGE_Master_Action_Object::getTaskByTaskID(RGE_Master_Action_Object *this, int t)
{
  RGE_Task_List *v2; // ecx@2
  int v3; // eax@2
  int v4; // edx@2
  RGE_Task **v5; // edi@3
  RGE_Task **v6; // ecx@3
  RGE_Task *result; // eax@6

  if( t == -1 || (v2 = this->tasks, v3 = 0, v4 = v2->list_num, v4 <= 0) )
  {
    result = 0;
  }
  else
  {
    v5 = v2->list;
    v6 = v2->list;
    while( t != (*v6)->action_type )
    {
      ++v3;
      ++v6;
      if( v3 >= v4 )
        return 0;
    }
    result = v5[v3];
  }
  return result;
}

//----- (0044F760) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::copy_obj(RGE_Master_Action_Object *this, RGE_Master_Static_Object *source)
{
  RGE_Master_Action_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Moving_Object::copy_obj((RGE_Master_Moving_Object *)&this->vfptr, source);
  v2->default_task = *(_WORD *)&source[1].undead_flag;
  v2->search_radius = source[1].los;
  v2->work_rate = *(float *)&source[1].obj_max;
  v2->drop_site = LOWORD(source[1].radius_x);
  v2->backup_drop_site = HIWORD(source[1].radius_x);
  v2->task_by_group = LOBYTE(source[1].radius_y);
  v2->command_sound = (RGE_Sound *)LODWORD(source[1].radius_z);
  v2->move_sound = source[1].selected_sound;
  RGE_Task_List::copy(v2->tasks, (RGE_Task_List *)source[1].undead_sprite);
}

//----- (0044F7F0) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::modify(RGE_Master_Action_Object *this, float amount, char flag)
{
  if( flag == 13 )
    this->work_rate = amount;
  else
    RGE_Master_Moving_Object::modify((RGE_Master_Moving_Object *)&this->vfptr, amount, flag);
}

//----- (0044F820) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::modify_delta(RGE_Master_Action_Object *this, float amount, char flag)
{
  if( flag == 13 )
    this->work_rate = amount + this->work_rate;
  else
    RGE_Master_Moving_Object::modify_delta((RGE_Master_Moving_Object *)&this->vfptr, amount, flag);
}

//----- (0044F850) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::modify_percent(RGE_Master_Action_Object *this, float amount, char flag)
{
  if( flag == 13 )
    this->work_rate = amount * this->work_rate;
  else
    RGE_Master_Moving_Object::modify_percent((RGE_Master_Moving_Object *)&this->vfptr, amount, flag);
}

//----- (0044F880) --------------------------------------------------------
void __fastcall RGE_Master_Action_Object::save(RGE_Master_Action_Object *this, int a2, int outfile)
{
  RGE_Master_Action_Object *v3; // esi@1
  int v4; // ecx@1
  int v5; // eax@1
  RGE_Sound *v6; // eax@3
  int command_sound_num; // [sp+8h] [bp-8h]@1
  int move_sound_num; // [sp+Ch] [bp-4h]@1

  v3 = this;
  command_sound_num = -1;
  move_sound_num = -1;
  RGE_Master_Moving_Object::save((RGE_Master_Moving_Object *)&this->vfptr, a2, outfile);
  v5 = (int)&v3->command_sound->play_at_update_count;
  if( v5 )
  {
    LOWORD(v5) = *(_WORD *)(v5 + 12);
    command_sound_num = v5;
  }
  v6 = v3->move_sound;
  if( v6 )
  {
    LOWORD(v4) = v6->id;
    move_sound_num = v4;
  }
  rge_write(outfile, &v3->default_task, 2);
  rge_write(outfile, &v3->search_radius, 4);
  rge_write(outfile, &v3->work_rate, 4);
  rge_write(outfile, &v3->drop_site, 2);
  rge_write(outfile, &v3->backup_drop_site, 2);
  rge_write(outfile, &v3->task_by_group, 1);
  rge_write(outfile, &command_sound_num, 2);
  rge_write(outfile, &move_sound_num, 2);
  rge_write(outfile, &v3->run_pattern, 1);
  RGE_Task_List::save(v3->tasks, outfile);
}

//----- (0044F980) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::play_command_sound(RGE_Master_Action_Object *this)
{
  RGE_Sound *v1; // ecx@1

  v1 = this->command_sound;
  if( v1 )
    RGE_Sound::play(v1, 1);
}

//----- (0044F9A0) --------------------------------------------------------
void __thiscall RGE_Master_Action_Object::play_move_sound(RGE_Master_Action_Object *this)
{
  RGE_Sound *v1; // ecx@1

  v1 = this->move_sound;
  if( v1 )
    RGE_Sound::play(v1, 1);
}

//----- (0044F9C0) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object *this, RGE_Master_Animated_Object *other_object, int do_setup)
{
  RGE_Master_Animated_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Static_Object::RGE_Master_Static_Object(
    (RGE_Master_Static_Object *)&this->vfptr,
    (RGE_Master_Static_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Animated_Object::`vftable';
  if( do_setup )
    RGE_Master_Animated_Object::setup(v3, other_object);
}
// 570488: using guessed type int (__thiscall *RGE_Master_Animated_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044FA20) --------------------------------------------------------
RGE_Master_Animated_Object *__thiscall RGE_Master_Animated_Object::`vector deleting destructor'(RGE_Master_Animated_Object *this, unsigned int __flags)
{
  RGE_Master_Animated_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0044FA40) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  RGE_Master_Animated_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Static_Object::RGE_Master_Static_Object(
    (RGE_Master_Static_Object *)&this->vfptr,
    infile,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Animated_Object::`vftable';
  if( do_setup )
    RGE_Master_Animated_Object::setup(v5, infile, infile, sprites, sounds);
}
// 570488: using guessed type int (__thiscall *RGE_Master_Animated_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044FAB0) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  RGE_Master_Animated_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Static_Object::RGE_Master_Static_Object(
    (RGE_Master_Static_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Animated_Object::`vftable';
  if( do_setup )
    RGE_Master_Animated_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 570488: using guessed type int (__thiscall *RGE_Master_Animated_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044FB30) --------------------------------------------------------
int __thiscall RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object *this, RGE_Master_Animated_Object *other_object)
{
  RGE_Master_Animated_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Static_Object::setup(
    (RGE_Master_Static_Object *)&this->vfptr,
    (RGE_Master_Static_Object *)&other_object->vfptr);
  v2->master_type = 20;
  v2->speed = other_object->speed;
  return 1;
}

//----- (0044FB60) --------------------------------------------------------
int __userpurge RGE_Master_Animated_Object::setup@<eax>(RGE_Master_Animated_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Master_Animated_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)&this->vfptr, a2, infile, sprites, sounds);
  v5->master_type = 20;
  rge_read(a2, infile, infile, &v5->speed, 4);
  return 1;
}

//----- (0044FBA0) --------------------------------------------------------
int __thiscall RGE_Master_Animated_Object::setup(RGE_Master_Animated_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  RGE_Master_Animated_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Static_Object::setup((RGE_Master_Static_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  v5->master_type = 20;
  fscanf(infile, asc_584888, &v5->speed);
  return 1;
}

//----- (0044FBF0) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::~RGE_Master_Animated_Object(RGE_Master_Animated_Object *this)
{
  this->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Animated_Object::`vftable';
  RGE_Master_Static_Object::~RGE_Master_Static_Object((RGE_Master_Static_Object *)&this->vfptr);
}
// 570488: using guessed type int (__thiscall *RGE_Master_Animated_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0044FC00) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::make_new_obj(RGE_Master_Animated_Object *this, RGE_Player *owner, float x, float y, float z)
{
  RGE_Master_Animated_Object *v5; // edi@1
  RGE_Static_Object *v6; // eax@2
  RGE_Animated_Object *v7; // eax@4

  v5 = this;
  if( this->recyclable && (v6 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
  {
    (*(void (__thiscall **)(RGE_Static_Object *, RGE_Master_Animated_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[0])(
      v6,
      v5,
      owner,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z));
  }
  else
  {
    v7 = (RGE_Animated_Object *)operator new(0x8Cu);
    if( v7 )
      RGE_Animated_Object::RGE_Animated_Object(v7, v5, owner, x, y, z, 1);
  }
}

//----- (0044FCD0) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::make_new_master(RGE_Master_Animated_Object *this)
{
  RGE_Master_Animated_Object *v1; // esi@1
  RGE_Master_Animated_Object *v2; // eax@1

  v1 = this;
  v2 = (RGE_Master_Animated_Object *)operator new(0xBCu);
  if( v2 )
    RGE_Master_Animated_Object::RGE_Master_Animated_Object(v2, v1, 1);
}

//----- (0044FD40) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::copy_obj(RGE_Master_Animated_Object *this, RGE_Master_Static_Object *source)
{
  RGE_Master_Animated_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Static_Object::copy_obj((RGE_Master_Static_Object *)&this->vfptr, source);
  LODWORD(v2->speed) = source[1].vfptr;
}

//----- (0044FD60) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::modify(RGE_Master_Animated_Object *this, float amount, char flag)
{
  if( flag == 5 )
    this->speed = amount;
  else
    RGE_Master_Static_Object::modify((RGE_Master_Static_Object *)&this->vfptr, amount, flag);
}

//----- (0044FD90) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::modify_delta(RGE_Master_Animated_Object *this, float amount, char flag)
{
  if( flag == 5 )
    this->speed = amount + this->speed;
  else
    RGE_Master_Static_Object::modify_delta((RGE_Master_Static_Object *)&this->vfptr, amount, flag);
}

//----- (0044FDC0) --------------------------------------------------------
void __thiscall RGE_Master_Animated_Object::modify_percent(RGE_Master_Animated_Object *this, float amount, char flag)
{
  if( flag == 5 )
    this->speed = amount * this->speed;
  else
    RGE_Master_Static_Object::modify_percent((RGE_Master_Static_Object *)&this->vfptr, amount, flag);
}

//----- (0044FDF0) --------------------------------------------------------
void __fastcall RGE_Master_Animated_Object::save(RGE_Master_Animated_Object *this, int a2, int outfile)
{
  RGE_Master_Animated_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Static_Object::save((RGE_Master_Static_Object *)&this->vfptr, a2, outfile);
  rge_write(outfile, &v3->speed, 4);
}
