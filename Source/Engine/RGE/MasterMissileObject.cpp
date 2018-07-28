
//----- (00451440) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object *this, RGE_Master_Missile_Object *other_object, int do_setup)
{
  RGE_Master_Missile_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    (RGE_Master_Combat_Object *)&this->vfptr,
    (RGE_Master_Combat_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Missile_Object::`vftable';
  if ( do_setup )
    RGE_Master_Missile_Object::setup(v3, other_object);
}
// 570560: using guessed type int (__thiscall *RGE_Master_Missile_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004514A0) --------------------------------------------------------
RGE_Master_Missile_Object *__thiscall RGE_Master_Missile_Object::`vector deleting destructor'(RGE_Master_Missile_Object *this, unsigned int __flags)
{
  RGE_Master_Missile_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Missile_Object::~RGE_Master_Missile_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004514C0) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  RGE_Master_Missile_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    (RGE_Master_Combat_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Missile_Object::`vftable';
  if ( do_setup )
    RGE_Master_Missile_Object::setup(v5, infile, infile, sprites, sounds);
}
// 570560: using guessed type int (__thiscall *RGE_Master_Missile_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451530) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  RGE_Master_Missile_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    (RGE_Master_Combat_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Missile_Object::`vftable';
  if ( do_setup )
    RGE_Master_Missile_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 570560: using guessed type int (__thiscall *RGE_Master_Missile_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (004515B0) --------------------------------------------------------
int __thiscall RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object *this, RGE_Master_Missile_Object *other_object)
{
  RGE_Master_Missile_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Combat_Object::setup(
    (RGE_Master_Combat_Object *)&this->vfptr,
    (RGE_Master_Combat_Object *)&other_object->vfptr);
  v2->master_type = 60;
  v2->missile_type = other_object->missile_type;
  v2->targetting_type = other_object->targetting_type;
  v2->missile_hit_info = other_object->missile_hit_info;
  v2->missile_die_info = other_object->missile_die_info;
  v2->area_effect_specials = other_object->area_effect_specials;
  v2->ballistics_ratio = other_object->ballistics_ratio;
  return 1;
}

//----- (00451620) --------------------------------------------------------
int __userpurge RGE_Master_Missile_Object::setup@<eax>(RGE_Master_Missile_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Master_Missile_Object *v5; // esi@1
  int v6; // edi@1

  v5 = this;
  v6 = infile;
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)&this->vfptr, infile, sprites, sounds);
  v5->master_type = 60;
  rge_read(a2, v6, v6, &v5->missile_type, 1);
  rge_read(a2, v6, v6, &v5->targetting_type, 1);
  rge_read(a2, v6, v6, &v5->missile_hit_info, 1);
  rge_read(a2, v6, v6, &v5->missile_die_info, 1);
  rge_read(a2, v6, v6, &v5->area_effect_specials, 1);
  rge_read(a2, v6, v6, &v5->ballistics_ratio, 4);
  return 1;
}

//----- (004516C0) --------------------------------------------------------
int __thiscall RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  RGE_Master_Missile_Object *v5; // esi@1
  _iobuf *v6; // edi@1
  char v7; // cl@1
  char v8; // dl@1
  char v9; // al@1
  char v10; // cl@1
  __int16 temp_missile_type; // [sp+Ah] [bp-2h]@1

  v5 = this;
  v6 = infile;
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  v5->recyclable = 1;
  v5->master_type = 60;
  fscanf(v6, aHdHdHdHdHdF, &temp_missile_type, &in_id, &sounds, &sprites, &infile, &v5->ballistics_ratio);
  v7 = (char)sounds;
  v8 = (char)sprites;
  v5->targetting_type = in_id;
  v9 = (char)infile;
  v5->missile_hit_info = v7;
  v10 = temp_missile_type;
  v5->missile_die_info = v8;
  v5->area_effect_specials = v9;
  v5->missile_type = v10;
  return 1;
}

//----- (00451760) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::~RGE_Master_Missile_Object(RGE_Master_Missile_Object *this)
{
  this->vfptr = (RGE_Master_Static_ObjectVtbl *)&RGE_Master_Missile_Object::`vftable';
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object((RGE_Master_Combat_Object *)&this->vfptr);
}
// 570560: using guessed type int (__thiscall *RGE_Master_Missile_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (00451770) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::make_new_obj(RGE_Master_Missile_Object *this, RGE_Player *owner, float x, float y, float z)
{
  RGE_Master_Missile_Object *v5; // edi@1
  RGE_Static_Object *v6; // eax@2
  RGE_Missile_Object *v7; // eax@4

  v5 = this;
  if ( this->recyclable && (v6 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
  {
    (*(void (__thiscall **)(RGE_Static_Object *, RGE_Master_Missile_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[0])(
      v6,
      v5,
      owner,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z));
  }
  else
  {
    v7 = (RGE_Missile_Object *)operator new(0x1C8u);
    if ( v7 )
      RGE_Missile_Object::RGE_Missile_Object(v7, (RGE_Master_Combat_Object *)&v5->vfptr, owner, x, y, z, 1);
  }
}

//----- (00451840) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::make_new_master(RGE_Master_Missile_Object *this)
{
  RGE_Master_Missile_Object *v1; // esi@1
  RGE_Master_Missile_Object *v2; // eax@1

  v1 = this;
  v2 = (RGE_Master_Missile_Object *)operator new(0x154u);
  if ( v2 )
    RGE_Master_Missile_Object::RGE_Master_Missile_Object(v2, v1, 1);
}

//----- (004518B0) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::copy_obj(RGE_Master_Missile_Object *this, RGE_Master_Static_Object *source)
{
  RGE_Master_Missile_Object *v2; // esi@1

  v2 = this;
  RGE_Master_Combat_Object::copy_obj((RGE_Master_Combat_Object *)&this->vfptr, source);
  v2->missile_type = source[1].map_color;
  v2->targetting_type = source[1].attack_reaction;
  v2->missile_hit_info = source[1].convert_terrain_flag;
  v2->missile_die_info = source[1].damage_sprite_num;
  v2->area_effect_specials = (char)source[1].damage_sprites;
  LODWORD(v2->ballistics_ratio) = source[1].help_string_id;
}

//----- (00451910) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::modify(RGE_Master_Missile_Object *this, float amount, char flag)
{
  if ( flag == 19 )
    this->targetting_type = (signed __int64)amount;
  RGE_Master_Combat_Object::modify((RGE_Master_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (00451940) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::modify_delta(RGE_Master_Missile_Object *this, float amount, char flag)
{
  if ( flag == 19 )
    this->targetting_type = (signed __int64)amount;
  RGE_Master_Combat_Object::modify_delta((RGE_Master_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (00451970) --------------------------------------------------------
void __thiscall RGE_Master_Missile_Object::modify_percent(RGE_Master_Missile_Object *this, float amount, char flag)
{
  if ( flag == 19 )
    this->targetting_type = (signed __int64)amount;
  RGE_Master_Combat_Object::modify_percent((RGE_Master_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (004519A0) --------------------------------------------------------
void __fastcall RGE_Master_Missile_Object::save(RGE_Master_Missile_Object *this, int a2, int outfile)
{
  RGE_Master_Missile_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Combat_Object::save((RGE_Master_Combat_Object *)&this->vfptr, a2, outfile);
  rge_write(outfile, &v3->missile_type, 1);
  rge_write(outfile, &v3->targetting_type, 1);
  rge_write(outfile, &v3->missile_hit_info, 1);
  rge_write(outfile, &v3->missile_die_info, 1);
  rge_write(outfile, &v3->area_effect_specials, 1);
  rge_write(outfile, &v3->ballistics_ratio, 4);
}
