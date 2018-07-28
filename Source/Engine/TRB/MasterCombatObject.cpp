
//----- (0050E970) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object *this, TRIBE_Master_Combat_Object *other_object, int do_setup)
{
  TRIBE_Master_Combat_Object *v3; // esi@1

  v3 = this;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    (RGE_Master_Combat_Object *)&this->vfptr,
    (RGE_Master_Combat_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Combat_Object::`vftable';
  if( do_setup )
    TRIBE_Master_Combat_Object::setup(v3, other_object);
}
// 576740: using guessed type int (__thiscall *TRIBE_Master_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050E9D0) --------------------------------------------------------
TRIBE_Master_Combat_Object *__thiscall TRIBE_Master_Combat_Object::`scalar deleting destructor'(TRIBE_Master_Combat_Object *this, unsigned int __flags)
{
  TRIBE_Master_Combat_Object *v2; // esi@1

  v2 = this;
  TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0050E9F0) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  TRIBE_Master_Combat_Object *v5; // esi@1

  v5 = this;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    (RGE_Master_Combat_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Combat_Object::`vftable';
  if( do_setup )
    TRIBE_Master_Combat_Object::setup(v5, infile, sprites, sounds);
}
// 576740: using guessed type int (__thiscall *TRIBE_Master_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050EA60) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  TRIBE_Master_Combat_Object *v6; // esi@1

  v6 = this;
  RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    (RGE_Master_Combat_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Combat_Object::`vftable';
  if( do_setup )
    TRIBE_Master_Combat_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 576740: using guessed type int (__thiscall *TRIBE_Master_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050EAE0) --------------------------------------------------------
int __thiscall TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object *this, TRIBE_Master_Combat_Object *other_object)
{
  TRIBE_Master_Combat_Object *v2; // esi@1
  int v3; // eax@1
  signed int v4; // edx@1
  char *v5; // edi@2
  int v6; // ebx@2

  v2 = this;
  RGE_Master_Combat_Object::setup(
    (RGE_Master_Combat_Object *)&this->vfptr,
    (RGE_Master_Combat_Object *)&other_object->vfptr);
  v2->master_type = 70;
  v3 = (int)v2->build_inventory;
  v4 = 3;
  do
  {
    v5 = (char *)((char *)other_object - (char *)v2 + v3);
    v6 = v3;
    v3 += 6;
    --v4;
    *(_DWORD *)v6 = *(_DWORD *)v5;
    *(_WORD *)(v6 + 4) = *((_WORD *)v5 + 2);
  }
  while( v4 );
  v2->build_pts_required = other_object->build_pts_required;
  v2->id_of_building_obj = other_object->id_of_building_obj;
  v2->button_location = other_object->button_location;
  v2->orig_pierce_armor = other_object->orig_pierce_armor;
  return 1;
}

//----- (0050EB60) --------------------------------------------------------
int __thiscall TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  TRIBE_Master_Combat_Object *v4; // esi@1
  Attribute_Cost *v5; // edi@1
  int v6; // ebp@1
  int result; // eax@4
  int v8; // edx@5
  RGE_Armor_Weapon_Info *v9; // eax@6
  int v10; // edi@6
  __int16 v11; // cx@8
  RGE_Armor_Weapon_Info *v12; // eax@12
  __int16 v13; // cx@14

  v4 = this;
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)&this->vfptr, infile, sprites, sounds);
  v4->master_type = 70;
  v5 = v4->build_inventory;
  v6 = 3;
  do
  {
    rge_read(v6, (int)v5, infile, v5, 6);
    ++v5;
    --v6;
  }
  while( v6 );
  rge_read(0, (int)v5, infile, &v4->build_pts_required, 2);
  rge_read(0, (int)v5, infile, &v4->id_of_building_obj, 2);
  rge_read(0, (int)v5, infile, &v4->button_location, 1);
  if( save_game_version < 7.0100002 )
  {
    v8 = v4->armor_num;
    v4->orig_pierce_armor = 0;
    if( v8 > 0 )
    {
      v9 = v4->armor;
      v10 = v8;
      do
      {
        if( v9->type == 3 )
        {
          v11 = v9->value;
          if( v11 > v4->orig_pierce_armor )
            v4->orig_pierce_armor = v11;
        }
        ++v9;
        --v10;
      }
      while( v10 );
    }
    v4->orig_armor = v4->base_armor;
    if( v8 > 0 )
    {
      v12 = v4->armor;
      do
      {
        if( v12->type != 3 )
        {
          v13 = v12->value;
          if( v13 > v4->orig_armor )
            v4->orig_armor = v13;
        }
        ++v12;
        --v8;
      }
      while( v8 );
    }
    result = 1;
  }
  else
  {
    rge_read(0, (int)v5, infile, &v4->orig_pierce_armor, 2);
    result = 1;
  }
  return result;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0050EC90) --------------------------------------------------------
int __thiscall TRIBE_Master_Combat_Object::setup(TRIBE_Master_Combat_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  TRIBE_Master_Combat_Object *v5; // edi@1
  int v6; // esi@1
  signed int v7; // ebp@1
  int v8; // edx@3
  RGE_Armor_Weapon_Info *v9; // eax@4
  int v10; // esi@4
  __int16 v11; // cx@6
  RGE_Armor_Weapon_Info *v12; // eax@10
  __int16 v13; // cx@12

  v5 = this;
  RGE_Master_Combat_Object::setup((RGE_Master_Combat_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  v5->master_type = 70;
  v6 = (int)v5->build_inventory;
  v7 = 3;
  do
  {
    fscanf(infile, aHdHdHd, v6, v6 + 2, &in_id);
    *(_BYTE *)(v6 + 4) = in_id;
    v6 += 6;
    --v7;
  }
  while( v7 );
  fscanf(infile, aHdHdHd, &v5->build_pts_required, &v5->id_of_building_obj, &sounds);
  v8 = v5->armor_num;
  v5->button_location = (char)sounds;
  v5->orig_pierce_armor = 0;
  if( v8 > 0 )
  {
    v9 = v5->armor;
    v10 = v8;
    do
    {
      if( v9->type == 3 )
      {
        v11 = v9->value;
        if( v11 > v5->orig_pierce_armor )
          v5->orig_pierce_armor = v11;
      }
      ++v9;
      --v10;
    }
    while( v10 );
  }
  v5->orig_armor = v5->base_armor;
  if( v8 > 0 )
  {
    v12 = v5->armor;
    do
    {
      if( v12->type != 3 )
      {
        v13 = v12->value;
        if( v13 > v5->orig_armor )
          v5->orig_armor = v13;
      }
      ++v12;
      --v8;
    }
    while( v8 );
  }
  return 1;
}

//----- (0050EDA0) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object *this)
{
  this->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Combat_Object::`vftable';
  RGE_Master_Combat_Object::~RGE_Master_Combat_Object((RGE_Master_Combat_Object *)&this->vfptr);
}
// 576740: using guessed type int (__thiscall *TRIBE_Master_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050EDB0) --------------------------------------------------------
RGE_Task_List *TRIBE_Master_Combat_Object::create_task_list()
{
  RGE_Task_List *v1; // eax@1
  RGE_Task_List *v2; // esi@1
  RGE_Task_List *v3; // ST08_4@1
  RGE_Task_List *result; // eax@1

  v1 = (RGE_Task_List *)operator new(0xCu);
  v2 = v1;
  v3 = v1;
  result = 0;
  if( v3 )
  {
    RGE_Task_List::RGE_Task_List(v2);
    v2->vfptr = (RGE_Task_ListVtbl *)&TRIBE_Task_List::`vftable';
    result = v2;
  }
  return result;
}
// 576780: using guessed type struct RGE_Task *(__thiscall *TRIBE_Task_List::`vftable')(RGE_Task_List *this, __int16 task_type, __int16);

//----- (0050EE00) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::copy_obj(TRIBE_Master_Combat_Object *this, RGE_Master_Static_Object *source)
{
  TRIBE_Master_Combat_Object *v2; // esi@1
  int v3; // eax@1
  signed int v4; // edx@1
  char *v5; // edi@2
  int v6; // ebx@2

  v2 = this;
  RGE_Master_Combat_Object::copy_obj((RGE_Master_Combat_Object *)&this->vfptr, source);
  v3 = (int)v2->build_inventory;
  v4 = 3;
  do
  {
    v5 = (char *)((char *)source - (char *)v2 + v3);
    v6 = v3;
    v3 += 6;
    --v4;
    *(_DWORD *)v6 = *(_DWORD *)v5;
    *(_WORD *)(v6 + 4) = *((_WORD *)v5 + 2);
  }
  while( v4 );
  v2->build_pts_required = HIWORD(source[1].hotkey_id);
  v2->id_of_building_obj = *(_WORD *)&source[1].recyclable;
  v2->button_location = source[1].create_doppleganger_on_death;
  v2->orig_pierce_armor = *(_WORD *)&source[1].draw_flag;
}

//----- (0050EE80) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::modify(TRIBE_Master_Combat_Object *this, float amount, char flag)
{
  char *v3; // esi@4
  signed int v4; // ebx@4
  char *v5; // esi@8
  char *v6; // edi@8
  float *v7; // ecx@8
  char *v8; // eax@8
  signed int v9; // edx@8
  float *v10; // ecx@12
  char *v11; // eax@12
  signed int v12; // edx@12
  float *v13; // ecx@16
  char *v14; // eax@16
  signed int v15; // edx@16
  char *v16; // esi@21
  signed int v17; // edi@21

  if( flag == 100 )
  {
    v16 = (char *)&this->build_inventory[0].amount;
    v17 = 3;
    do
    {
      if( v16[2] )
        *(_WORD *)v16 = (signed __int64)amount;
      v16 += 6;
      --v17;
    }
    while( v17 );
  }
  else if( flag == 101 )
  {
    v3 = (char *)&this->build_inventory[0].amount;
    v4 = 3;
    do
    {
      if( !v3[2] )
        *(_WORD *)v3 = (signed __int64)-amount;
      v3 += 6;
      --v4;
    }
    while( v4 );
    v5 = (char *)this->attribute_amount_held;
    v6 = (char *)this->attribute_type_held;
    v7 = this->attribute_amount_held;
    v8 = v6;
    v9 = 3;
    do
    {
      if( *(_WORD *)v8 == 4 )
        *v7 = amount;
      v8 += 2;
      ++v7;
      --v9;
    }
    while( v9 );
    v10 = (float *)v5;
    v11 = v6;
    v12 = 3;
    do
    {
      if( *(_WORD *)v11 == 11 )
        *v10 = -amount;
      v11 += 2;
      ++v10;
      --v12;
    }
    while( v12 );
    v13 = (float *)v5;
    v14 = v6;
    v15 = 3;
    do
    {
      if( *(_WORD *)v14 == 19 )
        *v13 = -amount;
      v14 += 2;
      ++v13;
      --v15;
    }
    while( v15 );
  }
  else
  {
    RGE_Master_Combat_Object::modify((RGE_Master_Combat_Object *)&this->vfptr, amount, flag);
  }
}

//----- (0050EF70) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::modify_delta(TRIBE_Master_Combat_Object *this, float amount, char flag)
{
  char *v3; // esi@3
  signed int v4; // edi@3

  if( flag == 100 )
  {
    v3 = (char *)&this->build_inventory[0].amount;
    v4 = 3;
    do
    {
      if( v3[2] )
        *(_WORD *)v3 += (signed __int64)amount;
      v3 += 6;
      --v4;
    }
    while( v4 );
  }
  else
  {
    RGE_Master_Combat_Object::modify_delta((RGE_Master_Combat_Object *)&this->vfptr, amount, flag);
  }
}

//----- (0050EFC0) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::modify_percent(TRIBE_Master_Combat_Object *this, float amount, char flag)
{
  char *v3; // esi@3
  signed int v4; // edi@3

  if( flag == 100 )
  {
    v3 = (char *)&this->build_inventory[0].amount;
    v4 = 3;
    do
    {
      if( v3[2] )
        *(_WORD *)v3 = (signed __int64)((double)*(_WORD *)v3 * amount);
      v3 += 6;
      --v4;
    }
    while( v4 );
  }
  else
  {
    RGE_Master_Combat_Object::modify_percent((RGE_Master_Combat_Object *)&this->vfptr, amount, flag);
  }
}

//----- (0050F010) --------------------------------------------------------
void __fastcall TRIBE_Master_Combat_Object::save(TRIBE_Master_Combat_Object *this, int a2, int outfile)
{
  TRIBE_Master_Combat_Object *v3; // ebp@1
  Attribute_Cost *v4; // esi@1
  signed int v5; // ebx@1

  v3 = this;
  RGE_Master_Combat_Object::save((RGE_Master_Combat_Object *)&this->vfptr, a2, outfile);
  v4 = v3->build_inventory;
  v5 = 3;
  do
  {
    rge_write(outfile, v4, 6);
    ++v4;
    --v5;
  }
  while( v5 );
  rge_write(outfile, &v3->build_pts_required, 2);
  rge_write(outfile, &v3->id_of_building_obj, 2);
  rge_write(outfile, &v3->button_location, 1);
  rge_write(outfile, &v3->orig_pierce_armor, 2);
}

//----- (0050F090) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::make_new_obj(TRIBE_Master_Combat_Object *this, RGE_Player *owner, float x, float y, float z)
{
  TRIBE_Master_Combat_Object *v5; // esi@1
  TRIBE_Combat_Object *v6; // eax@1

  v5 = this;
  v6 = (TRIBE_Combat_Object *)operator new(0x1C8u);
  if( v6 )
    TRIBE_Combat_Object::TRIBE_Combat_Object(v6, v5, owner, x, y, z, 1);
}

//----- (0050F110) --------------------------------------------------------
void __thiscall TRIBE_Master_Combat_Object::make_new_master(TRIBE_Master_Combat_Object *this)
{
  TRIBE_Master_Combat_Object *v1; // esi@1
  TRIBE_Master_Combat_Object *v2; // eax@1

  v1 = this;
  v2 = (TRIBE_Master_Combat_Object *)operator new(0x164u);
  if( v2 )
    TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(v2, v1, 1);
}
