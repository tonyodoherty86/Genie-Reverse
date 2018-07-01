
//----- (00460FD0) --------------------------------------------------------
void __thiscall RGE_Master_Player::RGE_Master_Player(RGE_Master_Player *this, _iobuf *infile)
{
  _iobuf *v2; // ebp@1
  RGE_Master_Player *v3; // esi@1
  char *v4; // edi@1
  _iobuf *v5; // ST00_4@1
  __int16 v6; // di@1
  int v7; // edi@4
  __int16 temp_index; // [sp+10h] [bp-8h]@5
  __int16 temp_culture; // [sp+12h] [bp-6h]@6
  float temp_amount; // [sp+14h] [bp-4h]@5

  v2 = infile;
  v3 = this;
  v4 = (char *)&this->attribute_num;
  v5 = infile;
  this->vfptr = (RGE_Master_PlayerVtbl *)&RGE_Master_Player::`vftable';
  this->type = 0;
  fscanf(v5, aSHdHd, this->name, &this->tribe_effect, &this->attribute_num);
  v6 = *(_WORD *)v4;
  if ( v6 <= 0 )
    v3->attributes = 0;
  else
    v3->attributes = (float *)calloc(v6, 4u);
  fscanf(v2, aHd, &infile);
  v7 = 0;
  if ( (signed __int16)infile > 0 )
  {
    do
    {
      fscanf(v2, aHdF, &temp_index, &temp_amount);
      ++v7;
      v3->attributes[temp_index] = temp_amount;
    }
    while ( (signed __int16)v7 < (signed __int16)infile );
  }
  fscanf(v2, aHd, &temp_culture);
  v3->culture = temp_culture;
  v3->master_object_num = 0;
  v3->master_objects = 0;
}
// 570C08: using guessed type int (__thiscall *RGE_Master_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (004610A0) --------------------------------------------------------
RGE_Master_Player *__thiscall RGE_Master_Player::`scalar deleting destructor'(RGE_Master_Player *this, unsigned int __flags)
{
  RGE_Master_Player *v2; // esi@1

  v2 = this;
  RGE_Master_Player::~RGE_Master_Player(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004610C0) --------------------------------------------------------
void __userpurge RGE_Master_Player::RGE_Master_Player(RGE_Master_Player *this@<ecx>, int a2@<ebp>, int infile)
{
  RGE_Master_Player *v3; // esi@1
  int v4; // edi@1
  float *v5; // eax@2
  int v6; // ecx@2

  v3 = this;
  v4 = infile;
  this->vfptr = (RGE_Master_PlayerVtbl *)&RGE_Master_Player::`vftable';
  rge_read(a2, infile, infile, this->name, 20);
  rge_read(a2, v4, v4, &v3->attribute_num, 2);
  rge_read(a2, v4, v4, &v3->tribe_effect, 2);
  if ( v3->attribute_num <= 0 )
  {
    v3->attributes = 0;
  }
  else
  {
    v5 = (float *)calloc(v3->attribute_num, 4u);
    v6 = v3->attribute_num;
    v3->attributes = v5;
    rge_read(a2, infile, infile, v5, 4 * v6);
  }
  rge_read(a2, infile, infile, &v3->culture, 1);
}
// 570C08: using guessed type int (__thiscall *RGE_Master_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (00461150) --------------------------------------------------------
void __thiscall RGE_Master_Player::~RGE_Master_Player(RGE_Master_Player *this)
{
  RGE_Master_Player *v1; // edi@1
  bool v2; // zf@1
  bool v3; // sf@1
  __int16 v4; // ax@4
  __int16 v5; // bx@6
  int v6; // esi@7
  RGE_Master_Static_Object *v7; // ecx@7

  v1 = this;
  v2 = this->attribute_num == 0;
  v3 = this->attribute_num < 0;
  this->vfptr = (RGE_Master_PlayerVtbl *)&RGE_Master_Player::`vftable';
  if ( !v3 && !v2 && this->attributes )
  {
    free(this->attributes);
    v1->attributes = 0;
    v1->attribute_num = 0;
  }
  v4 = v1->master_object_num;
  if ( v4 > 0 && v1->master_objects )
  {
    v5 = 0;
    if ( v4 > 0 )
    {
      do
      {
        v6 = v5;
        v7 = v1->master_objects[v6];
        if ( v7 )
        {
          ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
          v1->master_objects[v6] = 0;
        }
        ++v5;
      }
      while ( v5 < v1->master_object_num );
    }
    free(v1->master_objects);
    v1->master_objects = 0;
    v1->master_object_num = 0;
  }
}
// 570C08: using guessed type int (__thiscall *RGE_Master_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (004611D0) --------------------------------------------------------
void __userpurge RGE_Master_Player::finish_init(RGE_Master_Player *this@<ecx>, int a2@<edi>, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  int v5; // ebx@1
  RGE_Master_Player *v6; // esi@1
  char *v7; // ebp@1
  int v8; // edi@1
  RGE_Master_Static_Object **v9; // eax@2
  int v10; // ecx@2

  v5 = infile;
  v6 = this;
  v7 = (char *)&this->master_object_num;
  rge_read((int)&this->master_object_num, a2, infile, &this->master_object_num, 2);
  v8 = 0;
  if ( *(_WORD *)v7 <= 0 )
  {
    v6->master_objects = 0;
  }
  else
  {
    v9 = (RGE_Master_Static_Object **)calloc(*(_WORD *)v7, 4u);
    v10 = *(_WORD *)v7;
    v6->master_objects = v9;
    rge_read((int)v7, 0, v5, v9, 4 * v10);
    if ( *(_WORD *)v7 > 0 )
    {
      do
      {
        if ( v6->master_objects[(signed __int16)v8] )
        {
          rge_read((int)v7, v8, v5, &infile, 1);
          v6->vfptr->load_master_object(v6, v5, infile, sprites, sounds, v8);
        }
        ++v8;
      }
      while ( (signed __int16)v8 < *(_WORD *)v7 );
    }
  }
}

//----- (00461270) --------------------------------------------------------
void __userpurge RGE_Master_Player::load_master_object(RGE_Master_Player *this@<ecx>, int a2@<ebp>, int infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 index)
{
  RGE_Master_Player *v7; // esi@1
  RGE_Master_Static_Object *v8; // eax@2
  RGE_Master_Static_Object *v9; // eax@3
  RGE_Master_Animated_Object *v10; // eax@4
  RGE_Master_Static_Object *v11; // eax@5
  RGE_Master_Moving_Object *v12; // eax@6
  RGE_Master_Missile_Object *v13; // eax@8
  RGE_Master_Static_Object *v14; // eax@9
  RGE_Master_Action_Object *v15; // eax@10
  RGE_Master_Combat_Object *v16; // eax@12
  RGE_Master_Static_Object *v17; // eax@13
  RGE_Master_Doppleganger_Object *v18; // eax@15

  v7 = this;
  switch ( obj_type )
  {
    case 0xA:
      v8 = (RGE_Master_Static_Object *)operator new(0xB8u);
      if ( !v8 )
        goto LABEL_17;
      RGE_Master_Static_Object::RGE_Master_Static_Object(v8, a2, infile, sprites, sounds, 1);
      goto LABEL_18;
    case 0x14:
      v10 = (RGE_Master_Animated_Object *)operator new(0xBCu);
      if ( !v10 )
        goto LABEL_14;
      RGE_Master_Animated_Object::RGE_Master_Animated_Object(v10, infile, sprites, sounds, 1);
      v7->master_objects[index] = v11;
      return;
    case 0x1E:
      v12 = (RGE_Master_Moving_Object *)operator new(0xD8u);
      if ( !v12 )
        goto LABEL_17;
      RGE_Master_Moving_Object::RGE_Master_Moving_Object(v12, infile, sprites, sounds, 1);
      goto LABEL_18;
    case 0x3C:
      v13 = (RGE_Master_Missile_Object *)operator new(0x154u);
      if ( !v13 )
        goto LABEL_14;
      RGE_Master_Missile_Object::RGE_Master_Missile_Object(v13, infile, sprites, sounds, 1);
      v7->master_objects[index] = v14;
      return;
    case 0x28:
      v15 = (RGE_Master_Action_Object *)operator new(0xFCu);
      if ( !v15 )
        goto LABEL_17;
      RGE_Master_Action_Object::RGE_Master_Action_Object(v15, infile, sprites, sounds, 1);
      goto LABEL_18;
    case 0x32:
      v16 = (RGE_Master_Combat_Object *)operator new(0x148u);
      if ( v16 )
      {
        RGE_Master_Combat_Object::RGE_Master_Combat_Object(v16, infile, sprites, sounds, 1);
        v7->master_objects[index] = v17;
      }
      else
      {
LABEL_14:
        v7->master_objects[index] = 0;
      }
      break;
    case 0x19:
      v18 = (RGE_Master_Doppleganger_Object *)operator new(0xBCu);
      if ( v18 )
        RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(v18, infile, sprites, sounds, 1);
      else
LABEL_17:
        v9 = 0;
LABEL_18:
      v7->master_objects[index] = v9;
      break;
    default:
      return;
  }
}

//----- (00461530) --------------------------------------------------------
void __thiscall RGE_Master_Player::create_master_object_space(RGE_Master_Player *this, __int16 count)
{
  this->master_object_num = count;
  if ( count > 0 )
    this->master_objects = (RGE_Master_Static_Object **)calloc(count, 4u);
}

//----- (00461560) --------------------------------------------------------
void __thiscall RGE_Master_Player::load_object(RGE_Master_Player *this, _iobuf *infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 index)
{
  RGE_Master_Player *v6; // edi@1
  RGE_Master_Static_Object *v7; // eax@2
  __int16 v8; // si@2
  RGE_Master_Static_Object *v9; // eax@3
  RGE_Master_Animated_Object *v10; // eax@4
  __int16 v11; // si@4
  RGE_Master_Static_Object *v12; // eax@5
  RGE_Master_Moving_Object *v13; // eax@6
  RGE_Master_Missile_Object *v14; // eax@8
  RGE_Master_Static_Object *v15; // eax@9
  RGE_Master_Action_Object *v16; // eax@10
  RGE_Master_Combat_Object *v17; // eax@12
  RGE_Master_Static_Object *v18; // eax@13
  RGE_Master_Doppleganger_Object *v19; // eax@15

  v6 = this;
  switch ( obj_type )
  {
    case 0xA:
      v7 = (RGE_Master_Static_Object *)operator new(0xB8u);
      v8 = index;
      if ( !v7 )
        goto LABEL_17;
      RGE_Master_Static_Object::RGE_Master_Static_Object(v7, infile, sprites, sounds, index, 1);
      goto LABEL_18;
    case 0x14:
      v10 = (RGE_Master_Animated_Object *)operator new(0xBCu);
      v11 = index;
      if ( !v10 )
        goto LABEL_14;
      RGE_Master_Animated_Object::RGE_Master_Animated_Object(v10, infile, sprites, sounds, index, 1);
      v6->master_objects[index] = v12;
      return;
    case 0x1E:
      v13 = (RGE_Master_Moving_Object *)operator new(0xD8u);
      v8 = index;
      if ( !v13 )
        goto LABEL_17;
      RGE_Master_Moving_Object::RGE_Master_Moving_Object(v13, infile, sprites, sounds, index, 1);
      goto LABEL_18;
    case 0x3C:
      v14 = (RGE_Master_Missile_Object *)operator new(0x154u);
      v11 = index;
      if ( !v14 )
        goto LABEL_14;
      RGE_Master_Missile_Object::RGE_Master_Missile_Object(v14, infile, sprites, sounds, index, 1);
      v6->master_objects[index] = v15;
      return;
    case 0x28:
      v16 = (RGE_Master_Action_Object *)operator new(0xFCu);
      v8 = index;
      if ( !v16 )
        goto LABEL_17;
      RGE_Master_Action_Object::RGE_Master_Action_Object(v16, infile, sprites, sounds, index, 1);
      goto LABEL_18;
    case 0x32:
      v17 = (RGE_Master_Combat_Object *)operator new(0x148u);
      v11 = index;
      if ( v17 )
      {
        RGE_Master_Combat_Object::RGE_Master_Combat_Object(v17, infile, sprites, sounds, index, 1);
        v6->master_objects[index] = v18;
      }
      else
      {
LABEL_14:
        v6->master_objects[v11] = 0;
      }
      break;
    case 0x19:
      v19 = (RGE_Master_Doppleganger_Object *)operator new(0xBCu);
      v8 = index;
      if ( v19 )
        RGE_Master_Doppleganger_Object::RGE_Master_Doppleganger_Object(v19, infile, sprites, sounds, index, 1);
      else
LABEL_17:
        v9 = 0;
LABEL_18:
      v6->master_objects[v8] = v9;
      break;
    default:
      return;
  }
}

//----- (00461840) --------------------------------------------------------
void __thiscall RGE_Master_Player::save(RGE_Master_Player *this, int outfile)
{
  RGE_Master_Player *v2; // esi@1
  __int16 v3; // bx@1
  __int16 *v4; // ebp@3
  __int16 v5; // bx@4
  RGE_Master_Static_Object *v6; // ecx@5

  v2 = this;
  rge_write(outfile, &this->type, 1);
  rge_write(outfile, v2->name, 20);
  rge_write(outfile, &v2->attribute_num, 2);
  rge_write(outfile, &v2->tribe_effect, 2);
  v3 = v2->attribute_num;
  if ( v3 > 0 )
    rge_write(outfile, v2->attributes, 4 * v3);
  rge_write(outfile, &v2->culture, 1);
  v4 = &v2->master_object_num;
  rge_write(outfile, &v2->master_object_num, 2);
  if ( v2->master_object_num > 0 )
  {
    rge_write(outfile, v2->master_objects, 4 * v2->master_object_num);
    v5 = 0;
    if ( *v4 > 0 )
    {
      do
      {
        v6 = v2->master_objects[v5];
        if ( v6 )
          ((void (__stdcall *)(int))v6->vfptr->save)(outfile);
        ++v5;
      }
      while ( v5 < *v4 );
    }
  }
}
