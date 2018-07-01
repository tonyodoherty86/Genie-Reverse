
//----- (00451A20) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(RGE_Master_Moving_Object *this, RGE_Master_Moving_Object *other_object, int do_setup)
{
  RGE_Master_Moving_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    (RGE_Master_Animated_Object *)&this->vfptr,
    (RGE_Master_Animated_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Moving_Object::`vftable';
  if ( do_setup )
    RGE_Master_Moving_Object::setup(v3, other_object);
}
// 5705A0: using guessed type int (__thiscall *RGE_Master_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451A80) --------------------------------------------------------
RGE_Master_Moving_Object *__thiscall RGE_Master_Moving_Object::`scalar deleting destructor'(RGE_Master_Moving_Object *this, unsigned int __flags)
{
  RGE_Master_Moving_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Moving_Object::~RGE_Master_Moving_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00451AA0) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(RGE_Master_Moving_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  RGE_Master_Moving_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    (RGE_Master_Animated_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Moving_Object::`vftable';
  if ( do_setup )
    RGE_Master_Moving_Object::setup(v5, infile, infile, sprites, sounds);
}
// 5705A0: using guessed type int (__thiscall *RGE_Master_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451B10) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::RGE_Master_Moving_Object(RGE_Master_Moving_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  RGE_Master_Moving_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    (RGE_Master_Animated_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Moving_Object::`vftable';
  if ( do_setup )
    RGE_Master_Moving_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 5705A0: using guessed type int (__thiscall *RGE_Master_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451B90) --------------------------------------------------------
int __thiscall RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object *this, RGE_Master_Moving_Object *other_object)
{
  RGE_Master_Moving_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Animated_Object::setup(
    (RGE_Master_Animated_Object *)&this->vfptr,
    (RGE_Master_Animated_Object *)&other_object->vfptr);
  v2->master_type = 30;
  v2->move_sprite = other_object->move_sprite;
  v2->run_sprite = other_object->run_sprite;
  v2->turn_speed = other_object->turn_speed;
  v2->size_class = other_object->size_class;
  v2->obj_trail_id = other_object->obj_trail_id;
  v2->obj_trail_options = other_object->obj_trail_options;
  v2->obj_trail_spacing = other_object->obj_trail_spacing;
  v2->move_algorithem = other_object->move_algorithem;
  return 1;
}

//----- (00451C10) --------------------------------------------------------
int __userpurge RGE_Master_Moving_Object::setup@<eax>(RGE_Master_Moving_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Sprite **v5; // ebx@1
  int v6; // edi@1
  RGE_Master_Moving_Object *v7; // esi@1
  RGE_Sprite *v8; // eax@2
  int result; // eax@5

  v5 = sprites;
  v6 = infile;
  v7 = this;
  RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object *)&this->vfptr, a2, infile, sprites, sounds);
  v7->master_type = 30;
  rge_read(a2, v6, v6, &sounds, 2);
  rge_read(a2, v6, v6, &sprites, 2);
  rge_read(a2, v6, v6, &v7->turn_speed, 4);
  rge_read(a2, v6, v6, &v7->size_class, 1);
  rge_read(a2, v6, v6, &v7->obj_trail_id, 2);
  rge_read(a2, v6, v6, &v7->obj_trail_options, 1);
  rge_read(a2, v6, v6, &v7->obj_trail_spacing, 4);
  rge_read(a2, v6, v6, &v7->move_algorithem, 1);
  if ( (signed __int16)sounds < 0 )
    v8 = 0;
  else
    v8 = v5[(signed __int16)sounds];
  v7->move_sprite = v8;
  if ( (signed __int16)sprites < 0 )
  {
    v7->run_sprite = 0;
    result = 1;
  }
  else
  {
    result = 1;
    v7->run_sprite = v5[(signed __int16)sprites];
  }
  return result;
}

//----- (00451D10) --------------------------------------------------------
int __thiscall RGE_Master_Moving_Object::setup(RGE_Master_Moving_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  RGE_Sprite **v5; // ebx@1
  RGE_Master_Moving_Object *v6; // esi@1
  _iobuf *v7; // edi@1
  char v8; // cl@1
  char v9; // dl@1
  __int16 v10; // ax@1
  bool v11; // sf@1
  RGE_Sprite *v12; // eax@2
  int result; // eax@5
  __int16 temp_run_sprite; // [sp+Eh] [bp-2h]@1

  v5 = sprites;
  v6 = this;
  v7 = infile;
  RGE_Master_Animated_Object::setup((RGE_Master_Animated_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  v6->master_type = 30;
  fscanf(
    v7,
    aHdHdFHdHdHdFHd,
    &infile,
    &temp_run_sprite,
    &v6->turn_speed,
    &in_id,
    &v6->obj_trail_id,
    &sprites,
    &v6->obj_trail_spacing,
    &sounds);
  v8 = in_id;
  v9 = (char)sounds;
  v6->obj_trail_options = (char)sprites;
  v10 = (signed __int16)infile;
  v11 = (signed __int16)infile < 0;
  v6->size_class = v8;
  v6->move_algorithem = v9;
  if ( v11 )
    v12 = 0;
  else
    v12 = v5[v10];
  v6->move_sprite = v12;
  if ( temp_run_sprite < 0 )
  {
    v6->run_sprite = 0;
    result = 1;
  }
  else
  {
    result = 1;
    v6->run_sprite = v5[temp_run_sprite];
  }
  return result;
}

//----- (00451DE0) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::~RGE_Master_Moving_Object(RGE_Master_Moving_Object *this)
{
  this->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Moving_Object::`vftable';
  RGE_Master_Animated_Object::~RGE_Master_Animated_Object((RGE_Master_Animated_Object *)&this->vfptr);
}
// 5705A0: using guessed type int (__thiscall *RGE_Master_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451DF0) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::make_new_obj(RGE_Master_Moving_Object *this, RGE_Player *owner, float x, float y, float z)
{
  RGE_Master_Moving_Object *v5; // edi@1
  RGE_Static_Object *v6; // eax@2
  RGE_Moving_Object *v7; // eax@4

  v5 = this;
  if ( this->recyclable && (v6 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
  {
    (*(void (__thiscall **)(RGE_Static_Object *, RGE_Master_Moving_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[0])(
      v6,
      v5,
      owner,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z));
  }
  else
  {
    v7 = (RGE_Moving_Object *)operator new(0x180u);
    if ( v7 )
      RGE_Moving_Object::RGE_Moving_Object(v7, v5, owner, x, y, z, 1);
  }
}

//----- (00451EC0) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::make_new_master(RGE_Master_Moving_Object *this)
{
  RGE_Master_Moving_Object *v1; // esi@1
  RGE_Master_Moving_Object *v2; // eax@1

  v1 = this;
  v2 = (RGE_Master_Moving_Object *)operator new(0xD8u);
  if ( v2 )
    RGE_Master_Moving_Object::RGE_Master_Moving_Object(v2, v1, 1);
}

//----- (00451F30) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::copy_obj(RGE_Master_Moving_Object *this, RGE_Master_Static_Object *source)
{
  RGE_Master_Moving_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Animated_Object::copy_obj((RGE_Master_Animated_Object *)&this->vfptr, source);
  v2->move_sprite = *(RGE_Sprite **)&source[1].master_type;
  v2->run_sprite = (RGE_Sprite *)source[1].name;
  v2->turn_speed = *(float *)&source[1].string_id;
  v2->size_class = source[1].id;
  v2->obj_trail_id = source[1].copy_id;
  v2->obj_trail_options = source[1].object_group;
  LODWORD(v2->obj_trail_spacing) = source[1].sprite;
  v2->move_algorithem = (char)source[1].death_sprite;
}

//----- (00451FB0) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::modify(RGE_Master_Moving_Object *this, float amount, char flag)
{
  if ( flag == 6 )
    this->turn_speed = amount;
  else
    RGE_Master_Animated_Object::modify((RGE_Master_Animated_Object *)&this->vfptr, amount, flag);
}

//----- (00451FE0) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::modify_delta(RGE_Master_Moving_Object *this, float amount, char flag)
{
  if ( flag == 6 )
    this->turn_speed = amount + this->turn_speed;
  else
    RGE_Master_Animated_Object::modify_delta((RGE_Master_Animated_Object *)&this->vfptr, amount, flag);
}

//----- (00452010) --------------------------------------------------------
void __thiscall RGE_Master_Moving_Object::modify_percent(RGE_Master_Moving_Object *this, float amount, char flag)
{
  if ( flag == 6 )
    this->turn_speed = amount * this->turn_speed;
  else
    RGE_Master_Animated_Object::modify_percent((RGE_Master_Animated_Object *)&this->vfptr, amount, flag);
}

//----- (00452040) --------------------------------------------------------
void __fastcall RGE_Master_Moving_Object::save(RGE_Master_Moving_Object *this, int a2, int outfile)
{
  RGE_Master_Moving_Object *v3; // edi@1
  signed int v4; // ecx@1
  int v5; // eax@1
  RGE_Sprite *v6; // eax@4
  int temp_move_sprite; // [sp+8h] [bp-8h]@2
  int temp_run_sprite; // [sp+Ch] [bp-4h]@6

  v3 = this;
  v4 = -1;
  v5 = (int)v3->move_sprite;
  if ( v5 )
  {
    LOWORD(v5) = *(_WORD *)(v5 + 114);
    temp_move_sprite = v5;
  }
  else
  {
    temp_move_sprite = -1;
  }
  v6 = v3->run_sprite;
  if ( v6 )
    LOWORD(v4) = v6->id;
  temp_run_sprite = v4;
  RGE_Master_Animated_Object::save((RGE_Master_Animated_Object *)&v3->vfptr, a2, outfile);
  rge_write(outfile, &temp_move_sprite, 2);
  rge_write(outfile, &temp_run_sprite, 2);
  rge_write(outfile, &v3->turn_speed, 4);
  rge_write(outfile, &v3->size_class, 1);
  rge_write(outfile, &v3->obj_trail_id, 2);
  rge_write(outfile, &v3->obj_trail_options, 1);
  rge_write(outfile, &v3->obj_trail_spacing, 4);
  rge_write(outfile, &v3->move_algorithem, 1);
}
