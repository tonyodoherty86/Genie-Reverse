
//----- (0042F930) --------------------------------------------------------
void __thiscall RGE_Combat_Object::RGE_Combat_Object(RGE_Combat_Object *this, RGE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  RGE_Combat_Object *v7; // esi@1

  v7 = this;
  RGE_Action_Object::RGE_Action_Object(
    (RGE_Action_Object *)&this->vfptr,
    (RGE_Master_Action_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v7->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Combat_Object::`vftable';
  if ( do_setup )
    RGE_Combat_Object::setup(v7, tobj, obj_owner, x, y, z);
}
// 56F258: using guessed type int (__thiscall *RGE_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0042F9C0) --------------------------------------------------------
RGE_Combat_Object *__thiscall RGE_Combat_Object::`scalar deleting destructor'(RGE_Combat_Object *this, unsigned int __flags)
{
  RGE_Combat_Object *v2; // esi@1

  v2 = this;
  RGE_Combat_Object::~RGE_Combat_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0042F9E0) --------------------------------------------------------
void __userpurge RGE_Combat_Object::RGE_Combat_Object(RGE_Combat_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
  RGE_Combat_Object *v5; // esi@1

  v5 = this;
  RGE_Action_Object::RGE_Action_Object((RGE_Action_Object *)&this->vfptr, a2, infile, gworld, 0);
  v5->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Combat_Object::`vftable';
  if ( do_setup )
    RGE_Combat_Object::setup(v5, a2, infile, gworld);
}
// 56F258: using guessed type int (__thiscall *RGE_Combat_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0042FB40) --------------------------------------------------------
int __thiscall RGE_Combat_Object::setup(RGE_Combat_Object *this, RGE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Combat_Object *v6; // esi@1
  RGE_Master_Static_Object *v7; // edx@1
  int result; // eax@1

  v6 = this;
  memset(this->VUR_Ptrs, 0, sizeof(this->VUR_Ptrs));
  this->Unified_Map_Value = 0;
  RGE_Action_Object::setup(
    (RGE_Action_Object *)&this->vfptr,
    (RGE_Master_Action_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z);
  v7 = v6->master_obj;
  v6->type = 50;
  result = 1;
  v6->attack_timer = *(float *)&v7[1].movement_type;
  v6->capture_flag = 0;
  return result;
}

//----- (0042FBA0) --------------------------------------------------------
int __userpurge RGE_Combat_Object::setup@<eax>(RGE_Combat_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  RGE_Combat_Object *v4; // esi@1

  v4 = this;
  memset(this->VUR_Ptrs, 0, sizeof(this->VUR_Ptrs));
  this->Unified_Map_Value = 0;
  RGE_Action_Object::setup((RGE_Action_Object *)&this->vfptr, a2, infile, gworld);
  v4->type = 50;
  rge_read(a2, infile, infile, &v4->attack_timer, 4);
  if ( save_game_version >= 2.01 )
    rge_read(a2, infile, infile, &v4->capture_flag, 1);
  return 1;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0042FC10) --------------------------------------------------------
void __thiscall RGE_Combat_Object::save(RGE_Combat_Object *this, int outfile)
{
  RGE_Combat_Object *v2; // esi@1

  v2 = this;
  RGE_Action_Object::save((RGE_Action_Object *)&this->vfptr, outfile);
  rge_write(outfile, &v2->attack_timer, 4);
  rge_write(outfile, &v2->capture_flag, 1);
}

//----- (0042FC50) --------------------------------------------------------
void __thiscall RGE_Combat_Object::stop(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1

  v1 = this;
  RGE_Action_Object::stop((RGE_Action_Object *)&this->vfptr);
  if ( v1->unitAIValue )
  {
    if ( actionFile )
      fprintf(actionFile, aDCallStopobjec, v1->id, aCMsdevWorkA_11, 171);
    ((void (__stdcall *)(signed int))v1->unitAIValue->vfptr->stopObject)(1);
  }
}

//----- (0042FC90) --------------------------------------------------------
double __stdcall RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object *target)
{
  return 1.0;
}

//----- (0042FCA0) --------------------------------------------------------
char __thiscall RGE_Combat_Object::area_attack(RGE_Combat_Object *this, float x, float y, float z, RGE_Combat_Object *attacker, RGE_Static_Object *ignore_object)
{
  RGE_Combat_Object *v6; // esi@1
  double v7; // st7@1
  char result; // al@2
  signed __int16 v9; // di@3
  int v10; // eax@3
  int v11; // ebp@14
  RGE_Object_Node *i; // ebx@15
  RGE_Static_Object *v13; // edi@16
  RGE_Master_Static_Object *v14; // ecx@17
  double v15; // st7@19
  char v17; // c0@19
  double v18; // st6@23
  double v19; // st7@24
  double v20; // st6@27
  float v21; // ST24_4@31
  bool v22; // zf@34
  float attack_modifier; // [sp+Ch] [bp-24h]@19
  int x0; // [sp+10h] [bp-20h]@3
  int x1; // [sp+14h] [bp-1Ch]@3
  int v26; // [sp+18h] [bp-18h]@12
  float ry; // [sp+1Ch] [bp-14h]@23
  int v28; // [sp+20h] [bp-10h]@14
  int v29; // [sp+24h] [bp-Ch]@12
  RGE_Map *map; // [sp+28h] [bp-8h]@1
  float r2; // [sp+2Ch] [bp-4h]@1

  v6 = this;
  v7 = this->master_obj[1].construction_radius_y;
  map = this->owner->world->map;
  r2 = v7 * v7;
  if ( v7 > 0.0 )
  {
    x0 = (unsigned __int64)(signed __int64)(x - v7) - 2;
    x1 = (unsigned __int64)(signed __int64)(v7 + x) + 2;
    v9 = (unsigned __int64)(signed __int64)(y - v7) - 2;
    v10 = (unsigned __int64)(signed __int64)(v7 + y) + 2;
    if ( (signed __int16)x0 < 0 )
      LOWORD(x0) = 0;
    if ( (signed __int16)x1 > (signed __int16)(LOWORD(map->map_width) - 1) + 1 )
      LOWORD(x1) = map->map_width;
    if ( v9 < 0 )
      v9 = 0;
    if ( (signed __int16)v10 > (signed __int16)(LOWORD(map->map_height) - 1) + 1 )
      LOWORD(v10) = map->map_height;
    if ( v9 < (signed __int16)v10 )
    {
      v26 = v9;
      v29 = (signed __int16)v10 - v9;
      do
      {
        if ( (signed __int16)x0 < (signed __int16)x1 )
        {
          v11 = (signed __int16)x0;
          v28 = (signed __int16)x1 - (signed __int16)x0;
          do
          {
            for ( i = map->map_row_offset[v26][v11].objects.list; i; i = i->next )
            {
              v13 = i->node;
              if ( (RGE_Combat_Object *)i->node != v6 )
              {
                v14 = v13->master_obj;
                if ( (unsigned __int8)v14->area_effect_object_level >= v6->master_obj[1].elevation_flag
                  && v13 != ignore_object )
                {
                  v15 = v13->world_x - x;
                  attack_modifier = v13->world_y - y;
                  if ( v17 )
                    v15 = -v15;
                  if ( attack_modifier < 0.0 )
                    attack_modifier = -attack_modifier;
                  v18 = v14->radius_x;
                  ry = v14->radius_y;
                  if ( v15 <= v18 )
                    v19 = 0.0;
                  else
                    v19 = v15 - v18;
                  if ( attack_modifier <= (double)ry )
                    v20 = 0.0;
                  else
                    v20 = attack_modifier - ry;
                  if ( r2 > v19 * v19 + v20 * v20
                    && (signed __int16)(100 * debug_rand(aCMsdevWorkA_11, 250) / 0x7FFF) <= v6->master_obj[1].attribute_type_held[2] )
                  {
                    v6->vfptr->calc_attack_modifier((RGE_Static_Object *)v6, v13);
                    v21 = v19;
                    ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, RGE_Player *, RGE_Combat_Object *))v13->vfptr->damage)(
                      v13,
                      v6->master_obj[1].portrait_pict,
                      *(_DWORD *)&v6->master_obj[1].tile_req1,
                      LODWORD(v21),
                      v6->owner,
                      attacker);
                  }
                }
              }
            }
            ++v11;
            --v28;
          }
          while ( v28 );
        }
        v22 = v29 == 1;
        ++v26;
        --v29;
      }
      while ( !v22 );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042FF50) --------------------------------------------------------
char __thiscall RGE_Combat_Object::attack(RGE_Combat_Object *this, RGE_Static_Object *target, RGE_Combat_Object *attacker)
{
  RGE_Static_Object *v3; // edi@1
  RGE_Combat_Object *v4; // esi@1
  RGE_Master_Static_Object *v6; // eax@3
  __int16 v7; // cx@3
  long double v8; // rt2@4
  long double v9; // st3@4
  float c; // ST24_4@4
  float v11; // ST14_4@4
  float v12; // ST10_4@4
  float v13; // ST0C_4@4
  RGE_Missile_Object *v14; // eax@4
  RGE_Static_Object *targeta; // [sp+20h] [bp+4h]@4
  RGE_Static_Object *targetb; // [sp+20h] [bp+4h]@4

  v3 = target;
  v4 = this;
  if ( !target )
    return 0;
  v6 = this->master_obj;
  v7 = v6[1].attribute_type_held[1];
  if ( v7 < 0 )
  {
    ((void (__thiscall *)(RGE_Combat_Object *, RGE_Static_Object *, RGE_Combat_Object *, _DWORD, _DWORD, _DWORD))v4->vfptr[1].remove_overlay_sprite)(
      v4,
      target,
      attacker,
      LODWORD(v4->world_x),
      LODWORD(v4->world_y),
      LODWORD(v4->world_z));
  }
  else
  {
    v8 = cos(v4->angle);
    v9 = sin(v4->angle);
    c = v8;
    *(float *)&targeta = v9;
    v11 = v4->world_z + *(float *)&v6[1].attribute_max_amount;
    v12 = v9 * v6[1].attribute_amount_held[2] + v8 * v6[1].attribute_amount_held[1] + v4->world_y;
    v13 = -*(float *)&targeta * v6[1].attribute_amount_held[1] + c * v6[1].attribute_amount_held[2] + v4->world_x;
    *(float *)&targetb = sqrt(v6->radius_x * v6->radius_x + v6->radius_y * v6->radius_y)
                       + v6[1].construction_radius_x
                       - -6.0;
    v14 = (RGE_Missile_Object *)((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v4->owner->master_objects[v7]->vfptr->make_new_obj)(
                                  v4->owner,
                                  LODWORD(v13),
                                  LODWORD(v12),
                                  LODWORD(v11));
    RGE_Missile_Object::init_missile(v14, attacker, v3, *(float *)&targetb);
    v4->vfptr->notify((RGE_Static_Object *)v4, v4->id, v4->id, 512, 600, v3->id, 0);
    if ( v4->master_obj[1].construction_radius_x > 1.0 && RGE_Player::computerPlayer(v3->owner) == 1 )
    {
      ((void (__fastcall *)(RGE_Static_Object *, _DWORD, int, int, signed int, int, _DWORD, _DWORD))v3->vfptr->notify)(
        v3,
        (unsigned __int64)(signed __int64)v3->hp >> 32,
        v4->id,
        v3->id,
        527,
        v4->id,
        (signed __int64)v3->hp,
        v3->master_obj->hp);
      return 1;
    }
  }
  return 1;
}

//----- (004300F0) --------------------------------------------------------
char __thiscall RGE_Combat_Object::attack(RGE_Combat_Object *this, float target_x, float target_y, float target_z, RGE_Combat_Object *attacker)
{
  RGE_Combat_Object *v5; // esi@1
  RGE_Master_Static_Object *v6; // eax@1
  __int16 v7; // cx@1
  long double v8; // rt2@2
  long double v9; // st3@2
  float c; // ST28_4@2
  float s; // ST24_4@2
  float v12; // ST14_4@2
  float v13; // ST10_4@2
  float v14; // ST0C_4@2
  float v15; // ST28_4@2
  RGE_Missile_Object *v16; // eax@2
  char result; // al@2

  v5 = this;
  v6 = this->master_obj;
  v7 = v6[1].attribute_type_held[1];
  if ( v7 < 0 )
  {
    result = 0;
  }
  else
  {
    v8 = cos(v5->angle);
    v9 = sin(v5->angle);
    c = v8;
    s = v9;
    v12 = v5->world_z + *(float *)&v6[1].attribute_max_amount;
    v13 = v8 * v6[1].attribute_amount_held[1] + v9 * v6[1].attribute_amount_held[2] + v5->world_y;
    v14 = -s * v6[1].attribute_amount_held[1] + c * v6[1].attribute_amount_held[2] + v5->world_x;
    v15 = sqrt(v6->radius_x * v6->radius_x + v6->radius_y * v6->radius_y) + v6[1].construction_radius_x - -6.0;
    v16 = (RGE_Missile_Object *)((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v5->owner->master_objects[v7]->vfptr->make_new_obj)(
                                  v5->owner,
                                  LODWORD(v14),
                                  LODWORD(v13),
                                  LODWORD(v12));
    RGE_Missile_Object::init_missile(v16, attacker, target_x, target_y, target_z, v15);
    v5->vfptr->notify((RGE_Static_Object *)v5, v5->id, v5->id, 512, 600, -1, 0);
    result = 1;
  }
  return result;
}

//----- (00430230) --------------------------------------------------------
char __thiscall RGE_Combat_Object::do_attack(RGE_Combat_Object *this, RGE_Static_Object *target, RGE_Combat_Object *attacker, float x, float y, float z)
{
  RGE_Static_Object *v6; // edi@1
  RGE_Combat_Object *v7; // esi@1
  char result; // al@2
  double v9; // st7@3
  RGE_Static_ObjectVtbl *v10; // ebx@5
  RGE_Static_Object *targeta; // [sp+1Ch] [bp+4h]@6

  v6 = target;
  v7 = this;
  if ( target )
  {
    v9 = this->master_obj[1].construction_radius_y;
    if ( v9 <= 0.0 )
    {
      v10 = this->vfptr;
      ((void (__stdcall *)(int, int, signed int, signed int, int, _DWORD))this->vfptr->notify)(
        this->id,
        this->id,
        512,
        600,
        target->id,
        0);
      if ( 100 * debug_rand(aCMsdevWorkA_11, 379) / 0x7FFF <= v7->master_obj[1].attribute_type_held[2] )
      {
        v10->calc_attack_modifier((RGE_Static_Object *)v7, target);
        *(float *)&targeta = v9;
        ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, RGE_Static_Object *, RGE_Player *, RGE_Combat_Object *))v6->vfptr->damage)(
          v6,
          v7->master_obj[1].portrait_pict,
          *(_DWORD *)&v7->master_obj[1].tile_req1,
          targeta,
          v7->owner,
          attacker);
      }
      result = 1;
    }
    else
    {
      (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, RGE_Combat_Object *, _DWORD))&this->vfptr[1].gap4[48])(
        LODWORD(x),
        LODWORD(y),
        LODWORD(z),
        attacker,
        0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00430320) --------------------------------------------------------
void __userpurge RGE_Combat_Object::damage(RGE_Combat_Object *this@<ecx>, double a2@<st0>, int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject)
{
  RGE_Combat_Object *v7; // esi@1
  RGE_Static_ObjectVtbl *v8; // ebx@1
  double v9; // st7@1

  v7 = this;
  v8 = this->vfptr;
  ((void (__stdcall *)(int, RGE_Armor_Weapon_Info *, _DWORD, RGE_Player *, RGE_Static_Object *))this->vfptr->calculateDamage)(
    weapon_num,
    damage,
    LODWORD(attack_modifier),
    attacking_player,
    attackingObject);
  v9 = v7->hp - a2;
  v7->hp = v9;
  if ( attackingObject )
    ((void (__fastcall *)(RGE_Combat_Object *, _DWORD, int, int, signed int, int, _DWORD, _DWORD))v8->notify)(
      v7,
      (unsigned __int64)(signed __int64)v9 >> 32,
      attackingObject->id,
      v7->id,
      500,
      attackingObject->id,
      (signed __int64)v9,
      v7->master_obj->hp);
  if ( v7->hp < 1.0 )
    LODWORD(v7->hp) = 0;
}

//----- (004303A0) --------------------------------------------------------
double __thiscall RGE_Combat_Object::calculateDamage(RGE_Combat_Object *this, int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject)
{
  RGE_Master_Static_Object *v6; // eax@1
  double v7; // st7@1
  __int16 v8; // dx@1
  int v9; // ebp@1
  int v10; // edi@1
  RGE_Tile *v11; // esi@2
  double v12; // st6@4
  RGE_Armor_Weapon_Info *v13; // esi@5
  int v14; // eax@7
  int v15; // ecx@7
  double v16; // st5@11
  int v18; // [sp+10h] [bp-4h]@5
  int weapon_numa; // [sp+18h] [bp+4h]@6
  int tot_armor; // [sp+1Ch] [bp+8h]@5

  v6 = this->master_obj;
  v7 = 1.0;
  v8 = v6[1].center_tile_req1;
  v9 = *(_DWORD *)&v6[1].button_pict;
  v10 = *(_WORD *)&v6[1].sort_number;
  if ( v8 >= 0 )
  {
    v11 = this->tile;
    if ( v11 )
      v7 = this->owner->world->terrains[v8][*((_BYTE *)v11 + 5) & 0x1F];
  }
  v12 = 0.0;
  if ( weapon_num > 0 )
  {
    v13 = damage;
    tot_armor = weapon_num;
    v18 = LOBYTE(v6[1].death_spawn_obj_id);
    do
    {
      weapon_numa = v18;
      if ( v10 > 0 )
      {
        v14 = v9;
        v15 = v10;
        do
        {
          if ( *(_WORD *)v14 == v13->type )
            weapon_numa = *(_WORD *)(v14 + 2);
          v14 += 4;
          --v15;
        }
        while ( v15 );
      }
      v16 = ((double)v13->value - (double)weapon_numa) * v7 * attack_modifier;
      if ( v16 > 0.0 )
        v12 = v12 + v16;
      ++v13;
      --tot_armor;
    }
    while ( tot_armor );
  }
  return v12;
}

//----- (00430480) --------------------------------------------------------
bool __thiscall RGE_Combat_Object::can_attack(RGE_Combat_Object *this)
{
  return this->attack_timer <= 0.0;
}

//----- (004304A0) --------------------------------------------------------
void __thiscall RGE_Combat_Object::reset_attack_timer(RGE_Combat_Object *this)
{
  this->attack_timer = *(float *)&this->master_obj[1].movement_type;
}

//----- (004304B0) --------------------------------------------------------
void __thiscall RGE_Combat_Object::get_armor(RGE_Combat_Object *this, __int16 *cur_armor_in, __int16 *orig_armor_in)
{
  RGE_Master_Static_Object *v3; // eax@1
  signed int i; // edx@1
  __int16 v5; // ax@2

  *cur_armor_in = LOBYTE(this->master_obj[1].death_spawn_obj_id);
  v3 = this->master_obj;
  for ( i = 0; i < *(_WORD *)&v3[1].sort_number; ++i )
  {
    v5 = *(_WORD *)(*(_DWORD *)&v3[1].button_pict + 4 * i + 2);
    if ( v5 > *cur_armor_in )
      *cur_armor_in = v5;
    v3 = this->master_obj;
  }
  *orig_armor_in = LOWORD(this->master_obj[1].multiple_attribute_mod);
}

//----- (00430510) --------------------------------------------------------
void __thiscall RGE_Combat_Object::get_weapon(RGE_Combat_Object *this, __int16 *cur_weapon_in, __int16 *orig_weapon_in)
{
  signed int v3; // edx@1
  RGE_Master_Static_Object *v4; // eax@1
  __int16 v5; // ax@2

  v3 = 0;
  *cur_weapon_in = 0;
  v4 = this->master_obj;
  if ( v4[1].portrait_pict > 0 )
  {
    do
    {
      v5 = *(_WORD *)(*(_DWORD *)&v4[1].tile_req1 + 4 * v3 + 2);
      if ( v5 > *cur_weapon_in )
        *cur_weapon_in = v5;
      v4 = this->master_obj;
      ++v3;
    }
    while ( v3 < v4[1].portrait_pict );
  }
  *orig_weapon_in = HIWORD(this->master_obj[1].multiple_attribute_mod);
}

//----- (00430570) --------------------------------------------------------
void __thiscall RGE_Combat_Object::get_weapon_range(RGE_Combat_Object *this, float *cur_weapon_range_in, float *orig_weapon_range_in)
{
  *cur_weapon_range_in = this->master_obj[1].construction_radius_x;
  *orig_weapon_range_in = *(float *)&this->master_obj[1].attribute_flag[0];
}

//----- (004305A0) --------------------------------------------------------
void __thiscall RGE_Combat_Object::get_speed_of_attack(RGE_Combat_Object *this, float *cur_speed_of_attack_in, float *orig_speed_of_attack_in)
{
  *cur_speed_of_attack_in = *(float *)&this->master_obj[1].movement_type;
  *orig_speed_of_attack_in = *(float *)&this->master_obj[1].combat_level;
}

//----- (004305D0) --------------------------------------------------------
void __thiscall RGE_Combat_Object::release_being_worked_on(RGE_Combat_Object *this, RGE_Static_Object *caller)
{
  RGE_Combat_Object *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  RGE_Animated_Object::release_being_worked_on((RGE_Animated_Object *)&this->vfptr, caller);
  v3 = caller->id;
  if ( v3 >= 0 )
    v2->vfptr->notify((RGE_Static_Object *)v2, v3, v2->id, 699, caller->master_obj->object_group, 0, 0);
}

//----- (00430610) --------------------------------------------------------
void __thiscall RGE_Combat_Object::enter_obj(RGE_Combat_Object *this, RGE_Static_Object *target)
{
  RGE_Combat_Object *v2; // esi@1
  int v3; // edi@2

  v2 = this;
  RGE_Static_Object::enter_obj((RGE_Static_Object *)&this->vfptr, target);
  if ( v2->inside_obj )
  {
    v3 = v2->id;
    if ( v3 >= 0 )
    {
      Visible_Unit_Manager::Update_Unit_Info(
        VisibleUnitManager,
        v3,
        v2->owner->id,
        (signed __int64)v2->world_x,
        (signed __int64)v2->world_y,
        v2->master_obj->object_group,
        v2->Unified_Map_Value,
        0,
        v2->VUR_Ptrs);
      v2->Unified_Map_Value = 0;
    }
  }
}

//----- (00430680) --------------------------------------------------------
char __thiscall RGE_Combat_Object::update(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1
  double v2; // st7@1
  char v4; // c0@2
  char v5; // al@4
  int v6; // ebx@4
  int v7; // ebp@6
  signed __int64 v8; // rax@6
  unsigned int v9; // ecx@6
  unsigned int v10; // edi@6
  RGE_Player *v11; // eax@8
  signed int v12; // ecx@8
  RGE_Game_World *v13; // ebx@8
  signed int v14; // edx@8
  int v15; // eax@9
  int v16; // edi@15
  unsigned int v17; // eax@20
  char returnResult; // [sp+13h] [bp-5h]@4

  v1 = this;
  v2 = this->attack_timer;
  if ( v2 > 0.0 )
  {
    v2 = this->attack_timer - this->owner->world->world_time_delta_seconds;
    this->attack_timer = v2;
    if ( v4 )
      LODWORD(this->attack_timer) = 0;
  }
  v5 = RGE_Action_Object::update((RGE_Action_Object *)&this->vfptr);
  v6 = v1->id;
  returnResult = v5;
  if ( v6 >= 0 && !v1->inside_obj )
  {
    v2 = v1->world_y;
    v7 = (signed __int64)v1->world_x;
    v8 = (signed __int64)v2;
    v9 = v1->Unified_Map_Value;
    v10 = (unsigned int)(&unified_map_offsets)[(unsigned int)(signed __int64)v2][v7];
    v1->Unified_Map_Value = v10;
    if ( v10 != v9 )
    {
      Visible_Unit_Manager::Update_Unit_Info(
        VisibleUnitManager,
        v6,
        v1->owner->id,
        v7,
        v8,
        v1->master_obj->object_group,
        v9,
        v10,
        v1->VUR_Ptrs);
      if ( v1->capture_flag )
      {
        v11 = v1->owner;
        v12 = 1;
        v13 = v11->world;
        v14 = v13->player_num;
        if ( v14 <= 1 )
        {
LABEL_13:
          v12 = -1;
        }
        else
        {
          v15 = v11->id;
          while ( v12 == v15 || !((1 << v12) & v10) )
          {
            if ( ++v12 >= v14 )
              goto LABEL_13;
          }
        }
        if ( v12 >= 0 )
        {
          v16 = v12;
          if ( !RGE_Player::computerPlayer(v13->players[v12]) )
          {
            v1->vfptr->change_ownership((RGE_Static_Object *)v1, v1->owner->world->players[v16]);
            if ( v1->capture_flag == 1 )
              v1->capture_flag = 0;
          }
        }
      }
    }
  }
  if ( v1->unitAIValue && RGE_Game_World::is_player_turn(v1->owner->world, v1->owner->id) )
  {
    v17 = RGE_Game_World::get_accum_time_delta(v1->owner->world, v1->owner->id);
    UnitAIModule::update(v1->unitAIValue, v2, v17);
  }
  return returnResult;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (00430810) --------------------------------------------------------
void __thiscall RGE_Combat_Object::copy_obj(RGE_Combat_Object *this, RGE_Master_Static_Object *source2)
{
  RGE_Combat_Object *v2; // esi@1
  RGE_Sound *v3; // eax@1

  v2 = this;
  v3 = 0;
  if ( this->sprite == (RGE_Sprite *)this->master_obj[1].death_sound )
    v3 = source2[1].death_sound;
  if ( v3 )
    (*(void (__thiscall **)(RGE_Combat_Object *, RGE_Sound *))&this->vfptr->gap4[52])(this, v3);
  RGE_Action_Object::copy_obj((RGE_Action_Object *)&v2->vfptr, source2);
}

//----- (00430850) --------------------------------------------------------
void __thiscall RGE_Combat_Object::notify(RGE_Combat_Object *this, int caller, int recipient, int mType, int p1, int p2, int p3)
{
  RGE_Combat_Object *v7; // eax@1
  UnitAIModule *v8; // ecx@2
  RGE_Combat_Object *v9; // [sp+18h] [bp-4h]@1

  v7 = this;
  v9 = this;
  if ( this->object_state == 2 )
  {
    v8 = this->unitAIValue;
    if ( v8 )
    {
      if ( (*(int (__stdcall **)(int, int, int, int, int, int))&v8->vfptr->gap4[16])(
             caller,
             recipient,
             mType,
             p1,
             p2,
             p3) )
      {
        return;
      }
      v7 = v9;
    }
    if ( mType != 699 )
      ((void (__stdcall *)(int, int, int, int, int, int))v7->owner->vfptr->notify)(caller, recipient, mType, p1, p2, p3);
  }
}

//----- (004308C0) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Combat_Object::attack(RGE_Combat_Object *this, int targetID, int unconditional)
{
  RGE_Combat_Object *v3; // esi@1
  RGE_Static_Object *result; // eax@1
  int v5; // edi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@6
  RGE_Action *v9; // eax@8
  RGE_Action *v10; // eax@9
  RGE_Action *v11; // eax@10
  RGE_Master_Static_Object **v12; // ecx@12
  RGE_Action_Attack *v13; // eax@14
  int v14; // eax@15
  int v15; // edi@15

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 9)
      && (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 7) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v9 = RGE_Action_List::get_action(v3->actions), (int)v9->vfptr->get_target_obj(v9) != v5)
        || (v10 = RGE_Action_List::get_action(v3->actions), v10->vfptr->type(v10) != 9) )
      {
        if ( v3->master_obj->object_group == 4 )
        {
          v12 = v3->owner->master_objects;
          if ( v12[83] )
            v3->vfptr->transform((RGE_Static_Object *)v3, v12[83]);
        }
        v13 = (RGE_Action_Attack *)operator new(0x5Cu);
        if ( v13 )
        {
          RGE_Action_Attack::RGE_Action_Attack(
            v13,
            (RGE_Action_Object *)&v3->vfptr,
            (RGE_Static_Object *)v5,
            0,
            0,
            0,
            v3->master_obj[1].construction_radius_x,
            v3->master_obj[1].attribute_rot,
            v3->master_obj[1].attribute_type_held[1],
            HIWORD(v3->master_obj[1].attribute_amount_held[0]));
          v15 = v14;
        }
        else
        {
          v15 = 0;
        }
        if ( !v15 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(RGE_Combat_Object *, int))&v3->vfptr[1].gap4[28])(v3, v15);
      }
      else
      {
        v11 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v11->vfptr->work)(
          v11,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (00430A90) --------------------------------------------------------
int __thiscall RGE_Combat_Object::attack(RGE_Combat_Object *this, float x, float y, float z, int unconditional)
{
  RGE_Combat_Object *v5; // esi@1
  RGE_Action *v6; // eax@3
  RGE_Action *v7; // eax@4
  RGE_Action *v8; // eax@5
  RGE_Action *v9; // eax@6
  RGE_Action *v10; // eax@7
  RGE_Action_Attack *v11; // eax@8
  int v12; // eax@9
  int v13; // edi@9

  v5 = this;
  if ( unconditional
    || RGE_Action_List::have_action(this->actions) != 1
    || (v6 = RGE_Action_List::get_action(v5->actions), RGE_Action::targetX(v6) != x)
    || (v7 = RGE_Action_List::get_action(v5->actions), RGE_Action::targetX(v7) != y)
    || (v8 = RGE_Action_List::get_action(v5->actions), RGE_Action::targetX(v8) != z)
    || (v9 = RGE_Action_List::get_action(v5->actions), v9->vfptr->type(v9) != 9)
    && (v10 = RGE_Action_List::get_action(v5->actions), v10->vfptr->type(v10) != 7) )
  {
    v11 = (RGE_Action_Attack *)operator new(0x5Cu);
    if ( v11 )
    {
      RGE_Action_Attack::RGE_Action_Attack(
        v11,
        (RGE_Action_Object *)&v5->vfptr,
        x,
        y,
        z,
        0,
        0,
        0,
        v5->master_obj[1].construction_radius_x,
        v5->master_obj[1].attribute_rot,
        v5->master_obj[1].attribute_type_held[1],
        HIWORD(v5->master_obj[1].attribute_amount_held[0]));
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    if ( !v13 )
      return 0;
    RGE_Action_List::delete_list(v5->actions);
    (*(void (__thiscall **)(RGE_Combat_Object *, int))&v5->vfptr[1].gap4[28])(v5, v13);
  }
  return 1;
}

//----- (00430C10) --------------------------------------------------------
int __thiscall RGE_Combat_Object::moveTo(RGE_Combat_Object *this, int targetID, int unconditional)
{
  return (*(int (__stdcall **)(int, signed int, int))&this->vfptr->gap154[4])(targetID, 1065353216, unconditional);
}

//----- (00430C30) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Combat_Object::moveTo(RGE_Combat_Object *this, int targetID, float minRange, int unconditional)
{
  RGE_Combat_Object *v4; // esi@1
  RGE_Static_Object *result; // eax@1
  RGE_Static_Object *v6; // ebx@1
  RGE_Action *v7; // eax@4
  RGE_Action *v8; // eax@5
  RGE_Master_Static_Object *v9; // eax@6
  RGE_Sprite *v10; // edi@6
  RGE_Action_Move_To *v11; // eax@8
  int v12; // eax@9
  int v13; // edi@9

  v4 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v6 = result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v4->actions) != 1
      || (v7 = RGE_Action_List::get_action(v4->actions), v7->vfptr->get_target_obj(v7) != v6)
      || (v8 = RGE_Action_List::get_action(v4->actions), v8->vfptr->type(v8) != 1) )
    {
      v9 = v4->master_obj;
      v10 = (RGE_Sprite *)v9[1].name;
      if ( !v9[1].name )
        v10 = *(RGE_Sprite **)&v9[1].master_type;
      v11 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v11 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(v11, (RGE_Action_Object *)&v4->vfptr, v6, minRange, v10);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      if ( !v13 )
        return 0;
      RGE_Action_List::delete_list(v4->actions);
      (*(void (__thiscall **)(RGE_Combat_Object *, int))&v4->vfptr[1].gap4[28])(v4, v13);
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (00430D50) --------------------------------------------------------
int __thiscall RGE_Combat_Object::moveTo(RGE_Combat_Object *this, float x, float y, float z, float minRange, int unconditional)
{
  RGE_Combat_Object *v6; // esi@1
  RGE_Action *v7; // eax@3
  RGE_Action *v8; // eax@4
  RGE_Action *v9; // eax@5
  RGE_Action *v10; // eax@6
  RGE_Action *v11; // eax@8
  RGE_Master_Static_Object *v12; // eax@9
  RGE_Sprite *v13; // edi@9
  RGE_Action_Move_To *v14; // eax@11
  int v15; // eax@12
  int v16; // edi@12

  v6 = this;
  if ( unconditional
    || RGE_Action_List::have_action(this->actions) != 1
    || (v7 = RGE_Action_List::get_action(v6->actions), RGE_Action::targetX(v7) != x)
    || (v8 = RGE_Action_List::get_action(v6->actions), RGE_Action::targetY(v8) != y)
    || (v9 = RGE_Action_List::get_action(v6->actions), RGE_Action::targetZ(v9) != z)
    || (v10 = RGE_Action_List::get_action(v6->actions), v10->vfptr->type(v10) != 1) )
  {
    if ( RGE_Action_List::have_action(v6->actions) != 1
      || (v11 = RGE_Action_List::get_action(v6->actions),
          ((int (__thiscall *)(RGE_Action *, RGE_Combat_Object *, _DWORD, _DWORD, _DWORD))v11->vfptr->move_to)(
            v11,
            v6,
            LODWORD(x),
            LODWORD(y),
            LODWORD(z)) != 1) )
    {
      v12 = v6->master_obj;
      v13 = (RGE_Sprite *)v12[1].name;
      if ( !v13 )
        v13 = *(RGE_Sprite **)&v12[1].master_type;
      v14 = (RGE_Action_Move_To *)operator new(0x44u);
      if ( v14 )
      {
        RGE_Action_Move_To::RGE_Action_Move_To(v14, (RGE_Action_Object *)&v6->vfptr, x, y, z, minRange, v13);
        v16 = v15;
      }
      else
      {
        v16 = 0;
      }
      if ( !v16 )
        return 0;
      RGE_Action_List::delete_list(v6->actions);
      (*(void (__thiscall **)(RGE_Combat_Object *, int))&v6->vfptr[1].gap4[28])(v6, v16);
    }
  }
  return 1;
}

//----- (00430EC0) --------------------------------------------------------
int __stdcall RGE_Combat_Object::moveAwayFrom(int targetID, int unconditional)
{
  return 0;
}

//----- (00430ED0) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Combat_Object::gather(RGE_Combat_Object *this, int targetID, int unconditional)
{
  RGE_Combat_Object *v3; // edi@1
  RGE_Static_Object *result; // eax@1
  int v5; // esi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Action *v8; // eax@7
  RGE_Action *v9; // eax@8
  RGE_Static_ObjectVtbl *v10; // ebp@9
  RGE_Task *v11; // ebx@9
  RGE_Action_Gather *v12; // eax@10
  int v13; // eax@11
  int v14; // esi@11

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 5) )
    {
      if ( RGE_Action_List::have_action(v3->actions) != 1
        || (v8 = RGE_Action_List::get_action(v3->actions), v8->vfptr->type(v8) != 5) )
      {
        v10 = v3->vfptr;
        result = (RGE_Static_Object *)(*(int (__thiscall **)(RGE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                        v3,
                                        v5,
                                        *(_DWORD *)(v5 + 56),
                                        *(_DWORD *)(v5 + 60),
                                        *(_DWORD *)(v5 + 64));
        v11 = (RGE_Task *)result;
        if ( !result )
          return result;
        v12 = (RGE_Action_Gather *)operator new(0x44u);
        if ( v12 )
        {
          RGE_Action_Gather::RGE_Action_Gather(v12, (RGE_Action_Object *)&v3->vfptr, v11, (RGE_Static_Object *)v5);
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        if ( !v14 )
          return 0;
        RGE_Action_List::delete_list(v3->actions);
        (*(void (__thiscall **)(RGE_Combat_Object *, int))&v10[1].gap4[28])(v3, v14);
      }
      else
      {
        v9 = RGE_Action_List::get_action(v3->actions);
        ((void (__thiscall *)(RGE_Action *, int, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
          v9,
          v5,
          *(_DWORD *)(v5 + 56),
          *(_DWORD *)(v5 + 60),
          *(_DWORD *)(v5 + 64));
      }
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (00431020) --------------------------------------------------------
int __thiscall RGE_Combat_Object::explore(RGE_Combat_Object *this, int tX, int tY, int unconditional)
{
  RGE_Combat_Object *v4; // esi@1
  RGE_Action *v5; // eax@3
  RGE_Action *v6; // eax@5
  RGE_Action *v7; // eax@6
  float y; // ST0C_4@6
  float x; // ST08_4@6
  RGE_Action_Explore *v10; // eax@7
  float v11; // ST0C_4@8
  float v12; // ST08_4@8
  int v13; // eax@8
  int v14; // edi@8

  v4 = this;
  if ( unconditional
    || RGE_Action_List::have_action(this->actions) != 1
    || (v5 = RGE_Action_List::get_action(v4->actions), v5->vfptr->type(v5) != 4) )
  {
    if ( RGE_Action_List::have_action(v4->actions) != 1
      || (v6 = RGE_Action_List::get_action(v4->actions), v6->vfptr->type(v6) != 4) )
    {
      v10 = (RGE_Action_Explore *)operator new(0x40u);
      if ( v10 )
      {
        v11 = (double)tY;
        v12 = (double)tX;
        RGE_Action_Explore::RGE_Action_Explore(v10, (RGE_Action_Object *)&v4->vfptr, 0, v12, v11, v4->world_z);
        v14 = v13;
      }
      else
      {
        v14 = 0;
      }
      if ( !v14 )
        return 0;
      RGE_Action_List::delete_list(v4->actions);
      (*(void (__thiscall **)(RGE_Combat_Object *, int))&v4->vfptr[1].gap4[28])(v4, v14);
    }
    else
    {
      v7 = RGE_Action_List::get_action(v4->actions);
      y = (double)tY;
      x = (double)tX;
      ((void (__thiscall *)(RGE_Action *, _DWORD, _DWORD, _DWORD, _DWORD))v7->vfptr->work)(
        v7,
        0,
        LODWORD(x),
        LODWORD(y),
        LODWORD(v4->world_z));
    }
  }
  return 1;
}

//----- (00431150) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Combat_Object::enter(RGE_Combat_Object *this, int targetID, int unconditional)
{
  RGE_Combat_Object *v3; // esi@1
  RGE_Static_Object *result; // eax@1
  int v5; // edi@1
  RGE_Action *v6; // eax@4
  RGE_Action *v7; // eax@5
  RGE_Static_ObjectVtbl *v8; // ebp@6
  RGE_Task *v9; // ebx@6
  RGE_Action_Enter *v10; // eax@7
  int v11; // eax@8
  int v12; // edi@8

  v3 = this;
  result = RGE_Game_World::object(this->owner->world, targetID);
  v5 = (int)result;
  if ( result )
  {
    if ( unconditional
      || RGE_Action_List::have_action(v3->actions) != 1
      || (v6 = RGE_Action_List::get_action(v3->actions), (int)v6->vfptr->get_target_obj(v6) != v5)
      || (v7 = RGE_Action_List::get_action(v3->actions), v7->vfptr->type(v7) != 3) )
    {
      v8 = v3->vfptr;
      result = (RGE_Static_Object *)(*(int (__thiscall **)(RGE_Combat_Object *, int, _DWORD, _DWORD, _DWORD))&v3->vfptr[1].gap4[36])(
                                      v3,
                                      v5,
                                      *(_DWORD *)(v5 + 56),
                                      *(_DWORD *)(v5 + 60),
                                      *(_DWORD *)(v5 + 64));
      v9 = (RGE_Task *)result;
      if ( !result )
        return result;
      v10 = (RGE_Action_Enter *)operator new(0x40u);
      if ( v10 )
      {
        RGE_Action_Enter::RGE_Action_Enter(v10, (RGE_Action_Object *)&v3->vfptr, v9, (RGE_Static_Object *)v5);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( !v12 )
        return 0;
      RGE_Action_List::delete_list(v3->actions);
      (*(void (__thiscall **)(RGE_Combat_Object *, int))&v8[1].gap4[28])(v3, v12);
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (00431250) --------------------------------------------------------
int __thiscall RGE_Combat_Object::transport(RGE_Combat_Object *this, float tX, float tY, float tZ, int unconditional)
{
  RGE_Combat_Object *v5; // esi@1
  RGE_Action *v6; // eax@2
  RGE_Action *v7; // eax@3
  RGE_Action_Transport *v8; // eax@4
  RGE_Action *v9; // edi@4
  RGE_Action *v10; // eax@5

  v5 = this;
  if ( RGE_Action_List::have_action(this->actions) != 1
    || (v6 = RGE_Action_List::get_action(v5->actions), v6->vfptr->type(v6) != 12) )
  {
    v8 = (RGE_Action_Transport *)operator new(0x40u);
    v9 = 0;
    if ( v8 )
    {
      RGE_Action_Transport::RGE_Action_Transport(v8, (RGE_Action_Object *)&v5->vfptr, 0, tX, tY, tZ);
      v9 = v10;
    }
    if ( !v9 )
      return 0;
    RGE_Action_List::delete_list(v5->actions);
    (*(void (__thiscall **)(RGE_Combat_Object *, RGE_Action *))&v5->vfptr[1].gap4[28])(v5, v9);
    ((void (__thiscall *)(RGE_Action *, RGE_Combat_Object *, _DWORD, _DWORD, _DWORD))v9->vfptr->work)(
      v9,
      v5,
      LODWORD(tX),
      LODWORD(tY),
      LODWORD(tZ));
  }
  else
  {
    v7 = RGE_Action_List::get_action(v5->actions);
    ((void (__thiscall *)(RGE_Action *, RGE_Combat_Object *, _DWORD, _DWORD, _DWORD))v7->vfptr->work)(
      v7,
      0,
      LODWORD(tX),
      LODWORD(tY),
      LODWORD(tZ));
  }
  return 1;
}

//----- (00431340) --------------------------------------------------------
int __thiscall RGE_Combat_Object::unload(RGE_Combat_Object *this, int unconditional, float x, float y, float z)
{
  RGE_Combat_Object *v5; // esi@1
  RGE_Action *v6; // eax@2
  RGE_Action *v7; // eax@3
  RGE_Action_Transport *v8; // eax@4
  RGE_Action *v9; // eax@5
  RGE_Action *v10; // edi@5

  v5 = this;
  if ( RGE_Action_List::have_action(this->actions) != 1
    || (v6 = RGE_Action_List::get_action(v5->actions), v6->vfptr->type(v6) != 12) )
  {
    v8 = (RGE_Action_Transport *)operator new(0x40u);
    if ( v8 )
    {
      RGE_Action_Transport::RGE_Action_Transport(
        v8,
        (RGE_Action_Object *)&v5->vfptr,
        0,
        v5->world_x,
        v5->world_y,
        v5->world_z);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( !v10 )
      return 0;
    RGE_Action_List::delete_list(v5->actions);
    (*(void (__thiscall **)(RGE_Combat_Object *, RGE_Action *))&v5->vfptr[1].gap4[28])(v5, v10);
    ((void (__thiscall *)(RGE_Action *, RGE_Combat_Object *, _DWORD, _DWORD, _DWORD))v10->vfptr->work)(
      v10,
      v5,
      LODWORD(x),
      LODWORD(y),
      LODWORD(z));
  }
  else
  {
    v7 = RGE_Action_List::get_action(v5->actions);
    ((void (__thiscall *)(RGE_Action *, RGE_Combat_Object *, _DWORD, _DWORD, _DWORD))v7->vfptr->work)(
      v7,
      v5,
      LODWORD(v5->world_x),
      LODWORD(v5->world_y),
      LODWORD(v5->world_z));
  }
  return 1;
}

//----- (00431440) --------------------------------------------------------
int __thiscall RGE_Combat_Object::stopAction(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1

  v1 = this;
  RGE_Action_List::delete_list(this->actions);
  (*(void (__thiscall **)(RGE_Combat_Object *, RGE_Sprite *))&v1->vfptr->gap4[52])(v1, v1->master_obj->sprite);
  return 1;
}

//----- (00431470) --------------------------------------------------------
int __thiscall RGE_Combat_Object::pause(RGE_Combat_Object *this)
{
  (*(void (__stdcall **)(RGE_Sprite *))&this->vfptr->gap4[52])(this->master_obj->sprite);
  return 1;
}

//----- (00431490) --------------------------------------------------------
double __thiscall RGE_Combat_Object::rateOfFire(RGE_Combat_Object *this)
{
  return *(float *)&this->master_obj[1].movement_type;
}

//----- (004314A0) --------------------------------------------------------
double __thiscall RGE_Combat_Object::damageCapability(RGE_Combat_Object *this)
{
  RGE_Master_Static_Object *v1; // eax@1
  double result; // st7@1
  int v3; // edx@1
  _WORD *v4; // ecx@2
  double v5; // st6@3

  v1 = this->master_obj;
  result = 0.0;
  v3 = v1[1].portrait_pict;
  if ( v3 > 0 )
  {
    v4 = (_WORD *)(*(_DWORD *)&v1[1].tile_req1 + 2);
    do
    {
      v5 = (double)*v4;
      if ( v5 > 0.0 )
        result = result + v5;
      v4 += 2;
      --v3;
    }
    while ( v3 );
  }
  return result;
}

//----- (004314F0) --------------------------------------------------------
double __userpurge RGE_Combat_Object::damageCapability@<st0>(RGE_Combat_Object *this@<ecx>, double result@<st0>, RGE_Static_Object *attackingUnit)
{
  RGE_Static_Object *v3; // esi@1
  RGE_Combat_Object *v4; // edi@1
  RGE_Static_Object *attackingUnita; // [sp+Ch] [bp+4h]@1

  v3 = attackingUnit;
  v4 = this;
  attackingUnit->vfptr->calc_attack_modifier(attackingUnit, (RGE_Static_Object *)this);
  *(float *)&attackingUnita = result;
  ((void (__thiscall *)(RGE_Combat_Object *, _DWORD, _DWORD, RGE_Static_Object *, RGE_Player *, RGE_Static_Object *))v4->vfptr->calculateDamage)(
    v4,
    v3->master_obj[1].portrait_pict,
    *(_DWORD *)&v3->master_obj[1].tile_req1,
    attackingUnita,
    v3->owner,
    v3);
  return result;
}

//----- (00431530) --------------------------------------------------------
BOOL __thiscall RGE_Combat_Object::inAttackRange(RGE_Combat_Object *this, RGE_Static_Object *target)
{
  RGE_Combat_Object *v2; // esi@1
  RGE_Master_Static_Object *v3; // eax@1
  double v4; // st7@1
  float radiusDistance; // ST08_4@1
  RGE_Static_Object *v6; // ST00_4@1
  RGE_Static_Object *targeta; // [sp+Ch] [bp+4h]@1

  v2 = this;
  v3 = this->master_obj;
  v4 = v3->radius_y;
  radiusDistance = sqrt(v3->radius_x * v3->radius_x + v4 * v4);
  ((void (*)(void))this->vfptr->weaponRange)();
  v6 = target;
  *(float *)&targeta = v4 + radiusDistance - -0.30000001;
  return RGE_Static_Object::distance_to_object((RGE_Static_Object *)&v2->vfptr, v6) <= *(float *)&targeta;
}

//----- (004315A0) --------------------------------------------------------
double __thiscall RGE_Combat_Object::weaponRange(RGE_Combat_Object *this)
{
  return this->master_obj[1].construction_radius_x;
}

//----- (004315B0) --------------------------------------------------------
double __thiscall RGE_Combat_Object::minimumWeaponRange(RGE_Combat_Object *this)
{
  return this->master_obj[1].attribute_rot;
}

//----- (004315C0) --------------------------------------------------------
int __thiscall RGE_Combat_Object::currentTargetID(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1
  RGE_Action *v2; // eax@2
  RGE_Action *v3; // eax@3
  int result; // eax@3

  v1 = this;
  if ( RGE_Action_List::have_action(this->actions) == 1
    && (v2 = RGE_Action_List::get_action(v1->actions), (int)v2->vfptr->get_target_obj(v2)) )
  {
    v3 = RGE_Action_List::get_action(v1->actions);
    result = *(_DWORD *)((int)v3->vfptr->get_target_obj(v3) + 4);
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (00431610) --------------------------------------------------------
double __thiscall RGE_Combat_Object::currentTargetX(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1
  RGE_Action *v2; // eax@2
  double result; // st7@2

  v1 = this;
  if ( RGE_Action_List::have_action(this->actions) == 1 )
  {
    v2 = RGE_Action_List::get_action(v1->actions);
    result = RGE_Action::targetX(v2);
  }
  else
  {
    result = -1.0;
  }
  return result;
}

//----- (00431640) --------------------------------------------------------
double __thiscall RGE_Combat_Object::currentTargetY(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1
  RGE_Action *v2; // eax@2
  double result; // st7@2

  v1 = this;
  if ( RGE_Action_List::have_action(this->actions) == 1 )
  {
    v2 = RGE_Action_List::get_action(v1->actions);
    result = RGE_Action::targetY(v2);
  }
  else
  {
    result = -1.0;
  }
  return result;
}

//----- (00431670) --------------------------------------------------------
double __thiscall RGE_Combat_Object::currentTargetZ(RGE_Combat_Object *this)
{
  RGE_Combat_Object *v1; // esi@1
  RGE_Action *v2; // eax@2
  double result; // st7@2

  v1 = this;
  if ( RGE_Action_List::have_action(this->actions) == 1 )
  {
    v2 = RGE_Action_List::get_action(v1->actions);
    result = RGE_Action::targetZ(v2);
  }
  else
  {
    result = -1.0;
  }
  return result;
}

//----- (004316A0) --------------------------------------------------------
double __thiscall RGE_Combat_Object::teleport(RGE_Combat_Object *this, float x, float y, float z)
{
  RGE_Combat_Object *v4; // esi@1
  int v5; // edi@1
  int v6; // ebp@1
  double result; // st7@1
  int v8; // ebx@2
  signed __int64 v9; // rax@2
  VISIBLE_UNIT_REC **v10; // edx@4
  signed int v11; // esi@4
  VISIBLE_UNIT_REC *v12; // ecx@5

  v4 = this;
  v5 = (signed __int64)this->world_x;
  v6 = (signed __int64)this->world_y;
  result = RGE_Moving_Object::teleport((RGE_Moving_Object *)&this->vfptr, x, y, z);
  if ( v4->id >= 0 )
  {
    v8 = (signed __int64)v4->world_x;
    v9 = (signed __int64)v4->world_y;
    if ( v8 != v5 || (_DWORD)v9 != v6 )
    {
      v10 = v4->VUR_Ptrs;
      v11 = 9;
      do
      {
        v12 = *v10;
        if ( *v10 )
        {
          v12->pos_x = v8;
          v12->pos_y = v9;
        }
        ++v10;
        --v11;
      }
      while ( v11 );
    }
  }
  return result;
}
