
//----- (005117C0) --------------------------------------------------------
void __thiscall TRIBE_Master_Player::TRIBE_Master_Player(TRIBE_Master_Player *this, _iobuf *infile)
{
  TRIBE_Master_Player *v2; // esi@1

  v2 = this;
  RGE_Master_Player::RGE_Master_Player((RGE_Master_Player *)&this->vfptr, infile);
  v2->vfptr = (RGE_Master_PlayerVtbl *)&TRIBE_Master_Player::`vftable';
  v2->type = 1;
}
// 576800: using guessed type int (__thiscall *TRIBE_Master_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (005117E0) --------------------------------------------------------
TRIBE_Master_Player *__thiscall TRIBE_Master_Player::`vector deleting destructor'(TRIBE_Master_Player *this, unsigned int __flags)
{
  TRIBE_Master_Player *v2; // esi@1

  v2 = this;
  TRIBE_Master_Player::~TRIBE_Master_Player(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00511800) --------------------------------------------------------
void __userpurge TRIBE_Master_Player::TRIBE_Master_Player(TRIBE_Master_Player *this@<ecx>, int a2@<ebp>, int infile)
{
  TRIBE_Master_Player *v3; // esi@1

  v3 = this;
  RGE_Master_Player::RGE_Master_Player((RGE_Master_Player *)&this->vfptr, a2, infile);
  v3->vfptr = (RGE_Master_PlayerVtbl *)&TRIBE_Master_Player::`vftable';
  v3->type = 1;
}
// 576800: using guessed type int (__thiscall *TRIBE_Master_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (00511820) --------------------------------------------------------
void __thiscall TRIBE_Master_Player::~TRIBE_Master_Player(TRIBE_Master_Player *this)
{
  this->vfptr = (RGE_Master_PlayerVtbl *)&TRIBE_Master_Player::`vftable';
  RGE_Master_Player::~RGE_Master_Player((RGE_Master_Player *)&this->vfptr);
}
// 576800: using guessed type int (__thiscall *TRIBE_Master_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (00511830) --------------------------------------------------------
void __userpurge TRIBE_Master_Player::load_master_object(TRIBE_Master_Player *this@<ecx>, int a2@<ebp>, int infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 index)
{
  TRIBE_Master_Player *v7; // esi@1
  TRIBE_Master_Tree_Object *v8; // eax@5
  RGE_Master_Static_Object *v9; // eax@6
  TRIBE_Master_Building_Object *v10; // eax@7
  RGE_Master_Static_Object *v11; // eax@8
  TRIBE_Master_Combat_Object *v12; // eax@10

  v7 = this;
  if ( obj_type == 70 )
  {
    v12 = (TRIBE_Master_Combat_Object *)operator new(0x164u);
    if ( v12 )
    {
      TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(v12, infile, sprites, sounds, 1);
      goto LABEL_13;
    }
LABEL_12:
    v9 = 0;
    goto LABEL_13;
  }
  if ( obj_type != 80 )
  {
    if ( obj_type != 90 )
    {
      RGE_Master_Player::load_master_object(
        (RGE_Master_Player *)&this->vfptr,
        a2,
        infile,
        obj_type,
        sprites,
        sounds,
        index);
      return;
    }
    v8 = (TRIBE_Master_Tree_Object *)operator new(0xB8u);
    if ( v8 )
    {
      TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(v8, infile, sprites, sounds, 1);
LABEL_13:
      v7->master_objects[index] = v9;
      return;
    }
    goto LABEL_12;
  }
  v10 = (TRIBE_Master_Building_Object *)operator new(0x17Cu);
  if ( v10 )
  {
    TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(v10, infile, sprites, sounds, 1);
    v7->master_objects[index] = v11;
  }
  else
  {
    v7->master_objects[index] = 0;
  }
}

//----- (00511990) --------------------------------------------------------
void __thiscall TRIBE_Master_Player::load_object(TRIBE_Master_Player *this, _iobuf *infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 index)
{
  TRIBE_Master_Player *v6; // edi@1
  TRIBE_Master_Tree_Object *v7; // eax@5
  __int16 v8; // si@5
  RGE_Master_Static_Object *v9; // eax@6
  TRIBE_Master_Building_Object *v10; // eax@7
  RGE_Master_Static_Object *v11; // eax@8
  TRIBE_Master_Combat_Object *v12; // eax@10

  v6 = this;
  if ( obj_type == 70 )
  {
    v12 = (TRIBE_Master_Combat_Object *)operator new(0x164u);
    v8 = index;
    if ( v12 )
    {
      TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(v12, infile, sprites, sounds, index, 1);
      goto LABEL_13;
    }
LABEL_12:
    v9 = 0;
    goto LABEL_13;
  }
  if ( obj_type != 80 )
  {
    if ( obj_type != 90 )
    {
      RGE_Master_Player::load_object((RGE_Master_Player *)&this->vfptr, infile, obj_type, sprites, sounds, index);
      return;
    }
    v7 = (TRIBE_Master_Tree_Object *)operator new(0xB8u);
    v8 = index;
    if ( v7 )
    {
      TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(v7, infile, sprites, sounds, index, 1);
LABEL_13:
      v6->master_objects[v8] = v9;
      return;
    }
    goto LABEL_12;
  }
  v10 = (TRIBE_Master_Building_Object *)operator new(0x17Cu);
  if ( v10 )
  {
    TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(v10, infile, sprites, sounds, index, 1);
    v6->master_objects[index] = v11;
  }
  else
  {
    v6->master_objects[index] = 0;
  }
}
