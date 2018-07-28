
//----- (0050E040) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(TRIBE_Master_Building_Object *this, TRIBE_Master_Building_Object *other_object, int do_setup)
{
  TRIBE_Master_Building_Object *v3; // esi@1

  v3 = this;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    (TRIBE_Master_Combat_Object *)&this->vfptr,
    (TRIBE_Master_Combat_Object *)&other_object->vfptr,
    0);
  v3->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Building_Object::`vftable';
  if ( do_setup )
    TRIBE_Master_Building_Object::setup(v3, other_object);
}
// 576700: using guessed type int (__thiscall *TRIBE_Master_Building_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050E0A0) --------------------------------------------------------
TRIBE_Master_Building_Object *__thiscall TRIBE_Master_Building_Object::`scalar deleting destructor'(TRIBE_Master_Building_Object *this, unsigned int __flags)
{
  TRIBE_Master_Building_Object *v2; // esi@1

  v2 = this;
  TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0050E0C0) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(TRIBE_Master_Building_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup)
{
  TRIBE_Master_Building_Object *v5; // esi@1

  v5 = this;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    (TRIBE_Master_Combat_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    0);
  v5->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Building_Object::`vftable';
  if ( do_setup )
    TRIBE_Master_Building_Object::setup(v5, infile, sprites, sounds);
}
// 576700: using guessed type int (__thiscall *TRIBE_Master_Building_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050E130) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(TRIBE_Master_Building_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup)
{
  TRIBE_Master_Building_Object *v6; // esi@1

  v6 = this;
  TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(
    (TRIBE_Master_Combat_Object *)&this->vfptr,
    infile,
    sprites,
    sounds,
    in_id,
    0);
  v6->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Building_Object::`vftable';
  if ( do_setup )
    TRIBE_Master_Building_Object::setup(v6, infile, sprites, sounds, in_id);
}
// 576700: using guessed type int (__thiscall *TRIBE_Master_Building_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050E1B0) --------------------------------------------------------
int __thiscall TRIBE_Master_Building_Object::setup(TRIBE_Master_Building_Object *this, TRIBE_Master_Building_Object *other_object)
{
  TRIBE_Master_Building_Object *v2; // esi@1

  v2 = this;
  TRIBE_Master_Combat_Object::setup(
    (TRIBE_Master_Combat_Object *)&this->vfptr,
    (TRIBE_Master_Combat_Object *)&other_object->vfptr);
  v2->master_type = 80;
  v2->construction_sprite = other_object->construction_sprite;
  v2->building_connect_flag = other_object->building_connect_flag;
  v2->building_facet = other_object->building_facet;
  v2->build_and_go_away = other_object->build_and_go_away;
  v2->on_build_make_obj = other_object->on_build_make_obj;
  v2->on_build_make_tile = other_object->on_build_make_tile;
  v2->on_build_make_overlay = other_object->on_build_make_overlay;
  v2->on_build_make_tech = other_object->on_build_make_tech;
  v2->construction_sound = other_object->construction_sound;
  return 1;
}

//----- (0050E250) --------------------------------------------------------
int __thiscall TRIBE_Master_Building_Object::setup(TRIBE_Master_Building_Object *this, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Sprite **v4; // ebx@1
  RGE_Sound **v5; // ebp@1
  int v6; // edi@1
  TRIBE_Master_Building_Object *v7; // esi@1
  RGE_Sprite *v8; // ebx@2
  __int16 v9; // ax@4
  int result; // eax@5

  v4 = sprites;
  v5 = sounds;
  v6 = infile;
  v7 = this;
  TRIBE_Master_Combat_Object::setup((TRIBE_Master_Combat_Object *)&this->vfptr, infile, sprites, sounds);
  v7->master_type = 80;
  rge_read((int)v5, v6, v6, &sounds, 2);
  rge_read((int)v5, v6, v6, &v7->building_connect_flag, 1);
  rge_read((int)v5, v6, v6, &v7->building_facet, 2);
  rge_read((int)v5, v6, v6, &v7->build_and_go_away, 1);
  rge_read((int)v5, v6, v6, &v7->on_build_make_obj, 2);
  rge_read((int)v5, v6, v6, &v7->on_build_make_tile, 2);
  rge_read((int)v5, v6, v6, &v7->on_build_make_overlay, 2);
  rge_read((int)v5, v6, v6, &v7->on_build_make_tech, 2);
  rge_read((int)v5, v6, v6, &sprites, 2);
  if ( (signed __int16)sounds <= -1 )
    v8 = 0;
  else
    v8 = v4[(signed __int16)sounds];
  v9 = (signed __int16)sprites;
  v7->construction_sprite = v8;
  if ( v9 <= -1 )
  {
    v7->construction_sound = 0;
    result = 1;
  }
  else
  {
    v7->construction_sound = v5[v9];
    result = 1;
  }
  return result;
}

//----- (0050E360) --------------------------------------------------------
int __thiscall TRIBE_Master_Building_Object::setup(TRIBE_Master_Building_Object *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id)
{
  RGE_Sprite **v5; // ebx@1
  RGE_Sound **v6; // ebp@1
  _iobuf *v7; // edi@1
  TRIBE_Master_Building_Object *v8; // esi@1
  __int16 v9; // ax@1
  char v10; // dl@1
  bool v11; // zf@1
  bool v12; // sf@1
  unsigned __int8 v13; // of@1
  RGE_Sprite *v14; // ebx@2
  __int16 v15; // ax@4
  int result; // eax@5

  v5 = sprites;
  v6 = sounds;
  v7 = infile;
  v8 = this;
  TRIBE_Master_Combat_Object::setup((TRIBE_Master_Combat_Object *)&this->vfptr, infile, sprites, sounds, in_id);
  v8->master_type = 80;
  fscanf(
    v7,
    aHdHdHdHdHdHdHd,
    &sprites,
    &in_id,
    &v8->building_facet,
    &sounds,
    &v8->on_build_make_obj,
    &v8->on_build_make_tile,
    &v8->on_build_make_overlay,
    &v8->on_build_make_tech,
    &infile);
  v9 = (signed __int16)sprites;
  v10 = (char)sounds;
  v13 = __OFSUB__((_WORD)sprites, -1);
  v11 = (_WORD)sprites == -1;
  v12 = (signed __int16)((_WORD)sprites + 1) < 0;
  v8->building_connect_flag = in_id;
  v8->build_and_go_away = v10;
  if ( (unsigned __int8)(v12 ^ v13) | v11 )
    v14 = 0;
  else
    v14 = v5[v9];
  v15 = (signed __int16)infile;
  v8->construction_sprite = v14;
  if ( v15 <= -1 )
  {
    v8->construction_sound = 0;
    result = 1;
  }
  else
  {
    v8->construction_sound = v6[v15];
    result = 1;
  }
  return result;
}

//----- (0050E430) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::~TRIBE_Master_Building_Object(TRIBE_Master_Building_Object *this)
{
  this->vfptr = (RGE_Master_Static_ObjectVtbl *)&TRIBE_Master_Building_Object::`vftable';
  TRIBE_Master_Combat_Object::~TRIBE_Master_Combat_Object((TRIBE_Master_Combat_Object *)&this->vfptr);
}
// 576700: using guessed type int (__thiscall *TRIBE_Master_Building_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0050E440) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::copy_obj(TRIBE_Master_Building_Object *this, RGE_Master_Static_Object *source)
{
  TRIBE_Master_Building_Object *v2; // esi@1

  v2 = this;
  TRIBE_Master_Combat_Object::copy_obj((TRIBE_Master_Combat_Object *)&this->vfptr, source);
  v2->construction_sprite = (RGE_Sprite *)LODWORD(source[1].outline_radius_y);
  v2->construction_sound = (RGE_Sound *)LODWORD(source[1].outline_radius_x);
  v2->building_connect_flag = LOBYTE(source[1].outline_radius_z);
  v2->building_facet = HIWORD(source[1].outline_radius_z);
  v2->build_and_go_away = (char)source[2].vfptr;
  v2->on_build_make_obj = HIWORD(source[2].vfptr);
  v2->on_build_make_tile = *(_WORD *)&source[2].master_type;
  v2->on_build_make_overlay = *((_WORD *)&source[2].master_type + 1);
  v2->on_build_make_tech = (__int16)source[2].name;
}

//----- (0050E4D0) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::modify(TRIBE_Master_Building_Object *this, float amount, char flag)
{
  if ( flag == 17 )
    this->building_facet = (signed __int64)amount;
  else
    TRIBE_Master_Combat_Object::modify((TRIBE_Master_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (0050E500) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::modify_delta(TRIBE_Master_Building_Object *this, float amount, char flag)
{
  if ( flag == 17 )
    this->building_facet += (signed __int64)amount;
  else
    TRIBE_Master_Combat_Object::modify_delta((TRIBE_Master_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (0050E530) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::modify_percent(TRIBE_Master_Building_Object *this, float amount, char flag)
{
  TRIBE_Master_Combat_Object::modify_percent((TRIBE_Master_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (0050E550) --------------------------------------------------------
void __fastcall TRIBE_Master_Building_Object::save(TRIBE_Master_Building_Object *this, int a2, int outfile)
{
  int v3; // edi@1
  TRIBE_Master_Building_Object *v4; // esi@1
  int v5; // eax@1
  signed int v6; // ecx@1
  RGE_Sound *v7; // eax@4
  int sound_num; // [sp+8h] [bp-4h]@6

  v3 = outfile;
  v4 = this;
  TRIBE_Master_Combat_Object::save((TRIBE_Master_Combat_Object *)&this->vfptr, a2, outfile);
  v5 = (int)v4->construction_sprite;
  v6 = -1;
  if ( v5 )
  {
    LOWORD(v5) = *(_WORD *)(v5 + 114);
    outfile = v5;
  }
  else
  {
    outfile = -1;
  }
  v7 = v4->construction_sound;
  if ( v7 )
    LOWORD(v6) = v7->id;
  sound_num = v6;
  rge_write(v3, &outfile, 2);
  rge_write(v3, &v4->building_connect_flag, 1);
  rge_write(v3, &v4->building_facet, 2);
  rge_write(v3, &v4->build_and_go_away, 1);
  rge_write(v3, &v4->on_build_make_obj, 2);
  rge_write(v3, &v4->on_build_make_tile, 2);
  rge_write(v3, &v4->on_build_make_overlay, 2);
  rge_write(v3, &v4->on_build_make_tech, 2);
  rge_write(v3, &sound_num, 2);
}

//----- (0050E630) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::make_new_obj(TRIBE_Master_Building_Object *this, RGE_Player *owner, float x, float y, float z, int uID)
{
  TRIBE_Master_Building_Object *v6; // esi@1
  TRIBE_Building_Object *v7; // eax@1

  v6 = this;
  v7 = (TRIBE_Building_Object *)operator new(0x204u);
  if ( v7 )
    TRIBE_Building_Object::TRIBE_Building_Object(v7, v6, owner, x, y, z, uID, 1);
}

//----- (0050E6B0) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::make_new_obj(TRIBE_Master_Building_Object *this, RGE_Player *owner, float x, float y, float z)
{
  TRIBE_Master_Building_Object *v5; // esi@1
  TRIBE_Building_Object *v6; // eax@1

  v5 = this;
  v6 = (TRIBE_Building_Object *)operator new(0x204u);
  if ( v6 )
    TRIBE_Building_Object::TRIBE_Building_Object(v6, v5, owner, x, y, z, 1);
}

//----- (0050E730) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::make_new_master(TRIBE_Master_Building_Object *this)
{
  TRIBE_Master_Building_Object *v1; // esi@1
  TRIBE_Master_Building_Object *v2; // eax@1

  v1 = this;
  v2 = (TRIBE_Master_Building_Object *)operator new(0x17Cu);
  if ( v2 )
    TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(v2, v1, 1);
}

//----- (0050E7A0) --------------------------------------------------------
void __thiscall TRIBE_Master_Building_Object::draw(TRIBE_Master_Building_Object *this, TDrawArea *render_area, __int16 x, __int16 y, RGE_Color_Table *player_color, int facet, int frame, int draw_frame, char frame_color)
{
  TRIBE_Master_Building_Object *v9; // edx@1
  RGE_Sprite *v10; // ecx@1
  __int16 v11; // di@3
  __int16 v12; // bx@3
  int v13; // esi@3
  RGE_Game_World *v14; // edx@8
  RGE_Map *v15; // ebp@8
  int v16; // [sp-24h] [bp-44h]@4
  int v17; // [sp-1Ch] [bp-3Ch]@4
  int v18; // [sp-18h] [bp-38h]@4
  int v19; // [sp-14h] [bp-34h]@4
  int v20; // [sp-10h] [bp-30h]@4
  RGE_Color_Table *v21; // [sp-Ch] [bp-2Ch]@4
  TDrawArea *v22; // [sp-8h] [bp-28h]@4
  char v23; // [sp-4h] [bp-24h]@3
  __int16 y1; // [sp+10h] [bp-10h]@8
  __int16 x1; // [sp+12h] [bp-Eh]@8
  float rx1; // [sp+14h] [bp-Ch]@8
  float ry1; // [sp+18h] [bp-8h]@8
  float ya; // [sp+1Ch] [bp-4h]@1

  v9 = this;
  v10 = this->sprite;
  ya = *(float *)&v9;
  if ( v10 )
  {
    if ( v9->building_connect_flag )
    {
      v11 = y;
      v12 = x;
      v23 = 0;
      v13 = y;
      if ( facet )
      {
        v22 = render_area;
        v21 = player_color;
        v20 = y;
        v19 = x;
        v18 = y;
        v17 = x;
        v16 = facet - 1;
      }
      else
      {
        v22 = render_area;
        v21 = player_color;
        v20 = y;
        v19 = x;
        v18 = y;
        v17 = x;
        v16 = 2;
      }
    }
    else
    {
      v11 = y;
      v12 = x;
      v23 = 0;
      v13 = y;
      v22 = render_area;
      v21 = player_color;
      v20 = y;
      v19 = x;
      v18 = y;
      v17 = x;
      v16 = v9->building_facet;
    }
    RGE_Sprite::draw(v10, v16, 0, v17, v18, v19, v20, v21, v22, v23);
    if ( draw_frame )
    {
      v14 = rge_base_game->world;
      rx1 = *(float *)(LODWORD(ya) + 48);
      v15 = v14->map;
      ry1 = *(float *)(LODWORD(ya) + 52);
      ya = -ry1;
      RGE_Map::get_point(v15, &x1, &y1, rx1, ya, 0.0, v12, v11);
      RGE_Map::get_point(v15, (__int16 *)&draw_frame, (__int16 *)&facet, rx1, ry1, 0.0, v12, v11);
      rx1 = -rx1;
      RGE_Map::get_point(v15, (__int16 *)&player_color, (__int16 *)&render_area, rx1, ry1, 0.0, v12, v11);
      RGE_Map::get_point(v15, &x, &y, rx1, ya, 0.0, v12, v11);
      DClipInfo_List::AddGDINode(
        SDI_List,
        1,
        v13,
        x1,
        y1,
        (signed __int16)draw_frame,
        (signed __int16)facet,
        (signed __int16)player_color,
        (signed __int16)render_area,
        x,
        y,
        10,
        (unsigned __int8)frame_color,
        SDI_Object_ID);
    }
  }
}

//----- (0050E950) --------------------------------------------------------
char __thiscall TRIBE_Master_Building_Object::alignment(TRIBE_Master_Building_Object *this, float *col, float *row, RGE_Game_World *world, char center_flag)
{
  return RGE_Master_Static_Object::alignment((RGE_Master_Static_Object *)&this->vfptr, col, row, world, 1);
}
