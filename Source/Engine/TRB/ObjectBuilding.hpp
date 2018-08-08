
//----- (004C7F50) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Building_Object *this, TRIBE_Master_Building_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int uID, int do_setup)
{
  TRIBE_Building_Object *v8; // esi@1
  RGE_Master_Static_Object *v9; // eax@3

  v8 = this;
  TRIBE_Combat_Object::TRIBE_Combat_Object(
    (TRIBE_Combat_Object *)&this->vfptr,
    (TRIBE_Master_Combat_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v8->unique_build_id = uID;
  v8->production_queue = 0;
  v8->production_queue_size = 0;
  v8->production_queue_count = 0;
  v8->production_queue_enabled = 1;
  v8->production_queue_actions = 0;
  v8->production_queue_change_flag = 0;
  v8->production_queue_auto_paused = 0;
  v8->production_queue_need_attr = -1;
  v8->DoppleInstalled = 0;
  v8->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Building_Object::`vftable';
  if ( do_setup )
    TRIBE_Building_Object::setup(v8, tobj, obj_owner, x, y, z);
  v9 = v8->master_obj;
  if ( v9->id == 276 )
    RGE_Action_Object::set_task((RGE_Action_Object *)&v8->vfptr, *(_WORD *)&v9[1].undead_flag);
  v8->DoppleInstalled = RGE_Doppleganger_Creator::add_doppleganger_check(
                          v8->owner->doppleganger_creator,
                          (RGE_Static_Object *)&v8->vfptr,
                          (unsigned int *)&(&unified_map_offsets)[(unsigned int)(signed __int64)v8->world_y][(unsigned __int64)(signed __int64)v8->world_x]);
  v8->PriorMap1 = 0;
  v8->PriorMap2 = 0;
  v8->PriorMap3 = 0;
  v8->PriorTurn1 = 0;
  v8->PriorTurn2 = 0;
  v8->PriorTurn3 = 0;
}
// 574778: using guessed type int (__thiscall *TRIBE_Building_Object::`vftable')(void *Memory, unsigned int __flags);
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (004C8090) --------------------------------------------------------
TRIBE_Building_Object *__thiscall TRIBE_Building_Object::`scalar deleting destructor'(TRIBE_Building_Object *this, unsigned int __flags)
{
  TRIBE_Building_Object *v2; // esi@1

  v2 = this;
  TRIBE_Building_Object::~TRIBE_Building_Object(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004C80B0) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Building_Object *this, TRIBE_Master_Building_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  TRIBE_Building_Object *v7; // esi@1

  v7 = this;
  TRIBE_Combat_Object::TRIBE_Combat_Object(
    (TRIBE_Combat_Object *)&this->vfptr,
    (TRIBE_Master_Combat_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  v7->production_queue_need_attr = -1;
  v7->unique_build_id = -1;
  v7->production_queue = 0;
  v7->production_queue_size = 0;
  v7->production_queue_count = 0;
  v7->production_queue_enabled = 1;
  v7->production_queue_actions = 0;
  v7->production_queue_change_flag = 0;
  v7->production_queue_auto_paused = 0;
  v7->DoppleInstalled = 0;
  v7->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Building_Object::`vftable';
  if ( do_setup )
    TRIBE_Building_Object::setup(v7, tobj, obj_owner, x, y, z);
  v7->DoppleInstalled = RGE_Doppleganger_Creator::add_doppleganger_check(
                          v7->owner->doppleganger_creator,
                          (RGE_Static_Object *)&v7->vfptr,
                          (unsigned int *)&(&unified_map_offsets)[(unsigned int)(signed __int64)v7->world_y][(unsigned __int64)(signed __int64)v7->world_x]);
  v7->PriorMap1 = 0;
  v7->PriorMap2 = 0;
  v7->PriorMap3 = 0;
  v7->PriorTurn1 = 0;
  v7->PriorTurn2 = 0;
  v7->PriorTurn3 = 0;
}
// 574778: using guessed type int (__thiscall *TRIBE_Building_Object::`vftable')(void *Memory, unsigned int __flags);
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (004C81D0) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Building_Object *this, int infile, RGE_Game_World *gworld, int do_setup)
{
  TRIBE_Building_Object *v4; // esi@1

  v4 = this;
  TRIBE_Combat_Object::TRIBE_Combat_Object((TRIBE_Combat_Object *)&this->vfptr, infile, infile, gworld, 0);
  v4->production_queue = 0;
  v4->production_queue_size = 0;
  v4->production_queue_count = 0;
  v4->production_queue_enabled = 1;
  v4->production_queue_actions = 0;
  v4->production_queue_change_flag = 0;
  v4->production_queue_auto_paused = 0;
  v4->production_queue_need_attr = -1;
  v4->DoppleInstalled = 0;
  v4->vfptr = (RGE_Static_ObjectVtbl *)&TRIBE_Building_Object::`vftable';
  if ( do_setup )
    TRIBE_Building_Object::setup(v4, infile, infile, gworld);
  v4->DoppleInstalled = RGE_Doppleganger_Creator::add_doppleganger_check(
                          v4->owner->doppleganger_creator,
                          (RGE_Static_Object *)&v4->vfptr,
                          (unsigned int *)&(&unified_map_offsets)[(unsigned int)(signed __int64)v4->world_y][(unsigned __int64)(signed __int64)v4->world_x]);
}
// 574778: using guessed type int (__thiscall *TRIBE_Building_Object::`vftable')(void *Memory, unsigned int __flags);
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (004C8370) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::recycle_out_of_game(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1
  RGE_Action_List *v2; // ecx@1

  v1 = this;
  v2 = this->production_queue_actions;
  if ( v2 )
    RGE_Action_List::delete_list(v2);
  if ( v1->production_queue )
  {
    free(v1->production_queue);
    v1->production_queue = 0;
    v1->production_queue_size = 0;
    v1->production_queue_count = 0;
    v1->production_queue_enabled = 1;
    v1->production_queue_change_flag = 0;
    v1->production_queue_auto_paused = 0;
    v1->production_queue_need_attr = -1;
  }
  RGE_Action_Object::recycle_out_of_game((RGE_Action_Object *)&v1->vfptr);
}

//----- (004C83E0) --------------------------------------------------------
int __thiscall TRIBE_Building_Object::setup(TRIBE_Building_Object *this, TRIBE_Master_Building_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  TRIBE_Building_Object *v6; // esi@1
  RGE_Static_ObjectVtbl *v7; // edi@1
  RGE_Master_Static_Object *v8; // eax@1
  RGE_Master_Static_Object *v9; // eax@3
  float v10; // edx@3

  v6 = this;
  this->built = 0;
  TRIBE_Combat_Object::setup(
    (TRIBE_Combat_Object *)&this->vfptr,
    (TRIBE_Master_Combat_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z);
  v7 = v6->vfptr;
  v6->type = 80;
  v7->set_object_state((RGE_Static_Object *)v6, 0);
  v8 = v6->master_obj;
  if ( SHIWORD(v8[1].hotkey_id) > 0 )
    (*(void (__thiscall **)(TRIBE_Building_Object *, _DWORD))&v7->gap4[52])(v6, LODWORD(v8[1].outline_radius_y));
  v9 = v6->master_obj;
  LODWORD(v6->build_pts) = 0;
  LODWORD(v6->hp) = 1065353216;
  v6->facet = BYTE2(v9[1].outline_radius_z);
  v10 = v6->world_y;
  v6->culture = obj_owner->culture;
  TRIBE_World::check_destructables((TRIBE_World *)v6->owner->world, v6->owner->id, v9->id, v6->world_x, v10, 0);
  v6->production_queue_actions = (RGE_Action_List *)(*(int (__thiscall **)(TRIBE_Building_Object *))&v7[1].gap4[44])(v6);
  return 1;
}

//----- (004C8490) --------------------------------------------------------
int __userpurge TRIBE_Building_Object::setup@<eax>(TRIBE_Building_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  TRIBE_Building_Object *v4; // edi@1
  __int16 *v5; // esi@2
  Production_Queue_Record *v6; // eax@3
  bool v7; // zf@3
  bool v8; // sf@3
  int v9; // esi@4

  v4 = this;
  TRIBE_Combat_Object::setup((TRIBE_Combat_Object *)&this->vfptr, a2, infile, gworld);
  v4->type = 80;
  rge_read(a2, (int)v4, infile, &v4->built, 1);
  rge_read(a2, (int)v4, infile, &v4->build_pts, 4);
  rge_read(a2, (int)v4, infile, &v4->unique_build_id, 4);
  rge_read(a2, (int)v4, infile, &v4->culture, 1);
  v4->production_queue_actions = (RGE_Action_List *)(*(int (__thiscall **)(TRIBE_Building_Object *))&v4->vfptr[1].gap4[44])(v4);
  if ( save_game_version >= 7.21 )
  {
    v5 = &v4->production_queue_size;
    rge_read(a2, (int)v4, infile, &v4->production_queue_size, 2);
    if ( v4->production_queue_size > 0 )
    {
      v6 = (Production_Queue_Record *)calloc(v4->production_queue_size, 4u);
      a2 = 0;
      v7 = *v5 == 0;
      v8 = *v5 < 0;
      v4->production_queue = v6;
      if ( !v8 && !v7 )
      {
        do
        {
          v9 = (signed __int16)a2;
          rge_read(a2, (int)v4, infile, &v4->production_queue[v9], 2);
          rge_read(a2++, (int)v4, infile, &v4->production_queue[v9].unit_count, 2);
        }
        while ( (signed __int16)a2 < v4->production_queue_size );
      }
    }
    rge_read(a2, (int)v4, infile, &v4->production_queue_count, 2);
    rge_read(a2, (int)v4, infile, &v4->production_queue_enabled, 1);
    RGE_Action_List::load(v4->production_queue_actions, infile);
  }
  return 1;
}
// 58EBCC: using guessed type float save_game_version;

//----- (004C85D0) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::take_building_attribute_from_owner(TRIBE_Building_Object *this)
{
  int v1; // edi@1
  signed int v2; // ebp@1
  signed int v3; // esi@1
  RGE_Master_Static_Object *v4; // eax@2
  __int16 v5; // dx@3
  float v6; // ST04_4@4
  TRIBE_Building_Object *v7; // [sp+18h] [bp-4h]@1

  v7 = this;
  v1 = 0;
  v2 = 106;
  v3 = 112;
  do
  {
    v4 = this->master_obj;
    if ( v4->attribute_flag[v1] >= 4u )
    {
      v5 = *(_WORD *)((char *)&v4->vfptr + v2);
      if ( v5 >= 0 )
      {
        v6 = -*(float *)((char *)&v4->vfptr + v3);
        ((void (__stdcall *)(__int16, _DWORD, _DWORD))this->owner->vfptr->add_attribute_num)(v5, LODWORD(v6), 0);
        this = v7;
      }
    }
    v3 += 4;
    ++v1;
    v2 += 2;
  }
  while ( v3 < 124 );
}

//----- (004C8630) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::give_building_attribute_to_owner(TRIBE_Building_Object *this)
{
  int v1; // edi@1
  signed int v2; // ebp@1
  signed int v3; // esi@1
  RGE_Master_Static_Object *v4; // eax@2
  __int16 v5; // dx@3
  TRIBE_Building_Object *v6; // [sp+10h] [bp-4h]@1

  v6 = this;
  v1 = 0;
  v2 = 106;
  v3 = 112;
  do
  {
    v4 = this->master_obj;
    if ( v4->attribute_flag[v1] >= 4u )
    {
      v5 = *(_WORD *)((char *)&v4->vfptr + v2);
      if ( v5 >= 0 )
      {
        ((void (__stdcall *)(__int16, _DWORD, _DWORD))this->owner->vfptr->add_attribute_num)(
          v5,
          *(RGE_Master_Static_ObjectVtbl **)((char *)&v4->vfptr + v3),
          0);
        this = v6;
      }
    }
    v3 += 4;
    ++v1;
    v2 += 2;
  }
  while ( v3 < 124 );
}

//----- (004C8690) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::destroy_obj(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1

  v1 = this;
  ((void (*)(void))this->vfptr[1].damage)();
  RGE_Action_Object::destroy_obj((RGE_Action_Object *)&v1->vfptr);
  RGE_Doppleganger_Creator::remove_doppleganger_check(v1->owner->doppleganger_creator, (RGE_Static_Object *)&v1->vfptr);
  v1->DoppleInstalled = 0;
}

//----- (004C86C0) --------------------------------------------------------
char __thiscall TRIBE_Building_Object::heal(TRIBE_Building_Object *this, float healing)
{
  TRIBE_Building_Object *v2; // esi@1
  RGE_Master_Static_Object *v3; // ecx@1
  double v4; // st7@1
  double v5; // st6@1
  float modifier; // ST04_4@3
  char result; // al@4
  float healinga; // [sp+14h] [bp+4h]@1

  v2 = this;
  v3 = this->master_obj;
  v4 = (double)v3->hp;
  v5 = healing * v4 / (double)HIWORD(v3[1].hotkey_id);
  healinga = v5;
  if ( v5 + v2->hp > v4 )
    healinga = v4 - v2->hp;
  modifier = healinga / (double)(2 * v3->hp);
  if ( TRIBE_Player::pay_obj_cost((TRIBE_Player *)v2->owner, v3->id, modifier, 0) )
    result = TRIBE_Combat_Object::heal((TRIBE_Combat_Object *)&v2->vfptr, healinga);
  else
    result = 2;
  return result;
}

//----- (004C8740) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::set_object_state(TRIBE_Building_Object *this, char new_object_state)
{
  TRIBE_Building_Object *v2; // esi@1
  int v3; // eax@2
  int v4; // ebp@2
  unsigned int v5; // edi@2
  RGE_Sound *v6; // ecx@2
  RGE_Static_ObjectVtbl *v7; // edi@5
  RGE_Master_Static_Object *v8; // eax@7
  __int16 v9; // cx@9
  RGE_Master_Static_Object *v10; // edi@11
  RGE_Game_World *v11; // ebp@12
  RGE_Master_Static_Object *v12; // edi@12
  __int16 v13; // ax@13
  char v14; // bl@18
  __int16 v15; // ax@22

  v2 = this;
  if ( new_object_state == 2 )
  {
    this->build_pts = (double)HIWORD(this->master_obj[1].hotkey_id);
    v3 = debug_rand(aCMsdevWorkA_36, 299);
    v4 = debug_random_on;
    debug_random_on = 0;
    v5 = v3;
    v6 = (RGE_Sound *)LODWORD(v2->master_obj[1].outline_radius_x);
    if ( v6 && v2->owner->id == v2->owner->world->curr_player )
      RGE_Sound::play(v6, 1);
    debug_random_on = v4;
    debug_srand(aCMsdevWorkA_36, 309, v5);
    v7 = v2->vfptr;
    v2->built = 1;
    ((void (__thiscall *)(TRIBE_Building_Object *))v7[1].calculateDamage)(v2);
    if ( LOBYTE(v2->master_obj[2].vfptr) )
    {
      v7->die_die_die((RGE_Static_Object *)v2);
    }
    else
    {
      v7->unexplore_terrain((RGE_Static_Object *)v2, v2->owner, 1, -1);
      v7->explore_terrain((RGE_Static_Object *)v2, v2->owner, 0, -1);
      (*(void (__thiscall **)(TRIBE_Building_Object *, RGE_Sprite *))&v7->gap4[52])(v2, v2->master_obj->sprite);
      v8 = v2->master_obj;
      v2->facet = BYTE2(v8[1].outline_radius_z);
      if ( LOBYTE(v8[1].outline_radius_z) )
        TRIBE_Building_Object::connect(v2);
    }
    v9 = HIWORD(v2->master_obj[2].vfptr);
    if ( v9 > -1 )
      ((void (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v2->owner->master_objects[v9]->vfptr->make_new_obj)(
        v2->owner,
        LODWORD(v2->world_x),
        LODWORD(v2->world_y),
        LODWORD(v2->world_z));
    v10 = v2->master_obj;
    if ( *(_WORD *)&v10[2].master_type > -1 )
    {
      v11 = v2->owner->world;
      RGE_Map::set_terrain(
        v11->map,
        *v11->players,
        v11,
        (signed __int64)(v2->world_x - v10->construction_radius_x),
        (signed __int64)(v2->world_y - v10->construction_radius_y),
        (signed __int64)(v10->construction_radius_x + v2->world_x - 0.001),
        (signed __int64)(v10->construction_radius_y + v2->world_y - 0.001),
        v10[2].master_type,
        1,
        0);
      v12 = v2->master_obj;
      RGE_Map::request_redraw(
        v2->owner->world->map,
        (signed __int16)(signed __int64)(v2->world_x - v12->construction_radius_x) - 1,
        (signed __int16)(signed __int64)(v2->world_y - v12->construction_radius_y) - 1,
        (signed __int16)(signed __int64)(v12->construction_radius_x + v2->world_x - 0.001) + 1,
        (signed __int16)(signed __int64)(v12->construction_radius_y + v2->world_y - 0.001) + 1,
        0);
    }
    v13 = (__int16)v2->master_obj[2].name;
    if ( v13 > -1 )
      TRIBE_Player_Tech::do_tech((TRIBE_Player_Tech *)v2->owner[1].vfptr, v13);
    rge_base_game->vfptr->notification(
      rge_base_game,
      105,
      v2->owner->id,
      v2->master_obj->id,
      (signed __int64)v2->world_x,
      (signed __int64)v2->world_y);
    (*(void (__stdcall **)(TRIBE_Building_Object *, int))&v2->owner->vfptr[1].gap4[8])(v2, v2->unique_build_id);
  }
  if ( new_object_state != 3 || v2->object_state != 2 )
  {
    v14 = 0;
  }
  else
  {
    ((void (__thiscall *)(TRIBE_Building_Object *))v2->vfptr[1].damage)(v2);
    RGE_Doppleganger_Creator::remove_doppleganger_check(
      v2->owner->doppleganger_creator,
      (RGE_Static_Object *)&v2->vfptr);
    v2->DoppleInstalled = 0;
    v14 = 1;
  }
  RGE_Static_Object::set_object_state((RGE_Static_Object *)&v2->vfptr, new_object_state);
  if ( v14 && !RGE_Object_List::find_by_master_id(v2->owner->objects, v2->master_obj->id, -1.0, -1.0, 1, 2, 0) )
  {
    v15 = (__int16)v2->master_obj[2].name;
    if ( v15 > -1 )
      TRIBE_Player_Tech::undo_tech((TRIBE_Player_Tech *)v2->owner[1].vfptr, v15);
    TRIBE_Player_Tech::undo_tech((TRIBE_Player_Tech *)v2->owner[1].vfptr, 74);
    TRIBE_Player_Tech::undo_tech((TRIBE_Player_Tech *)v2->owner[1].vfptr, 75);
    TRIBE_Player_Tech::undo_tech((TRIBE_Player_Tech *)v2->owner[1].vfptr, 76);
  }
}
// 62C4D4: using guessed type int debug_random_on;

//----- (004C8A60) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::rehook(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1

  v1 = this;
  RGE_Action_Object::rehook((RGE_Action_Object *)&this->vfptr);
  RGE_Action_List::rehook(v1->production_queue_actions);
}

//----- (004C8A80) --------------------------------------------------------
char __thiscall TRIBE_Building_Object::update(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1
  RGE_Master_Static_Object *v2; // ebx@2
  signed __int64 v3; // rax@2
  unsigned int v4; // edx@7
  int v5; // eax@7
  int v6; // ecx@7
  char v7; // bl@7
  char result; // al@8

  v1 = this;
  if ( !this->object_state )
  {
    v2 = this->master_obj;
    v3 = (signed __int64)((double)this->sprite->facet_num * this->build_pts / (double)HIWORD(v2[1].hotkey_id));
    if ( (unsigned __int8)v3 < this->sprite->facet_num && (_BYTE)v3 != this->facet )
      this->facet = v3;
    if ( (double)HIWORD(v2[1].hotkey_id) <= this->build_pts )
      this->vfptr->set_object_state((RGE_Static_Object *)this, 2);
  }
  v4 = v1->PriorMap1;
  v5 = v1->PriorTurn2;
  v1->PriorMap3 = v1->PriorMap2;
  v6 = v1->PriorTurn1;
  v1->PriorMap2 = v4;
  v1->PriorTurn3 = v5;
  v1->PriorTurn2 = v6;
  v1->PriorTurn1 = world_update_counter;
  v7 = TRIBE_Combat_Object::update((TRIBE_Combat_Object *)&v1->vfptr);
  if ( v1->object_state <= 2u )
  {
    TRIBE_Building_Object::update_production_queue(v1, v7);
    v1->PriorMap1 = v1->Unified_Map_Value;
    result = v7;
  }
  else
  {
    TRIBE_Building_Object::empty_production_queue(v1);
    v1->PriorMap1 = v1->Unified_Map_Value;
    result = v7;
  }
  return result;
}
// 886C10: using guessed type __int32 world_update_counter;

//----- (004C8B80) --------------------------------------------------------
int __thiscall TRIBE_Building_Object::explore_terrain(TRIBE_Building_Object *this, RGE_Player *whos, char explore_type, int Override_LOS)
{
  int result; // eax@2

  if ( this->built )
    result = RGE_Static_Object::explore_terrain((RGE_Static_Object *)&this->vfptr, whos, explore_type, Override_LOS);
  else
    result = RGE_Static_Object::explore_terrain((RGE_Static_Object *)&this->vfptr, whos, 1, Override_LOS);
  return result;
}

//----- (004C8BC0) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::save(TRIBE_Building_Object *this, int outfile)
{
  TRIBE_Building_Object *v2; // edi@1
  __int16 v3; // si@1
  __int16 v4; // bp@2
  int v5; // esi@3

  v2 = this;
  TRIBE_Combat_Object::save((TRIBE_Combat_Object *)&this->vfptr, outfile);
  rge_write(outfile, &v2->built, 1);
  rge_write(outfile, &v2->build_pts, 4);
  rge_write(outfile, &v2->unique_build_id, 4);
  rge_write(outfile, &v2->culture, 1);
  rge_write(outfile, &v2->production_queue_size, 2);
  v3 = v2->production_queue_size;
  if ( v3 > 0 )
  {
    v4 = 0;
    if ( v3 > 0 )
    {
      do
      {
        v5 = v4;
        rge_write(outfile, &v2->production_queue[v5], 2);
        rge_write(outfile, &v2->production_queue[v5].unit_count, 2);
        ++v4;
      }
      while ( v4 < v2->production_queue_size );
    }
  }
  rge_write(outfile, &v2->production_queue_count, 2);
  rge_write(outfile, &v2->production_queue_enabled, 1);
  RGE_Action_List::save(v2->production_queue_actions, outfile);
}

//----- (004C8CB0) --------------------------------------------------------
void __userpurge TRIBE_Building_Object::change_ownership(TRIBE_Building_Object *this@<ecx>, int a2@<ebp>, RGE_Player *new_owner)
{
  TRIBE_Building_Object *v3; // esi@1
  char v4; // bl@1
  signed int v5; // edi@2
  RGE_Master_Static_Object *v6; // eax@3
  __int16 v7; // dx@4
  float v8; // ST20_4@5
  RGE_Player *v9; // ecx@11
  Production_Queue_Record *v10; // ecx@12
  __int16 v11; // cx@16
  __int16 v12; // ax@18
  int v13; // ebp@21
  signed int v14; // edi@21
  RGE_Master_Static_Object *v15; // eax@22
  int v16; // edx@23
  signed int v17; // [sp+38h] [bp-4h]@2
  RGE_Player *new_ownera; // [sp+40h] [bp+4h]@21

  v3 = this;
  v4 = 2;
  if ( this->object_state == 2 )
  {
    a2 = 0;
    v17 = 106;
    v5 = 112;
    do
    {
      v6 = v3->master_obj;
      if ( v6->attribute_flag[a2] >= 4u )
      {
        v7 = *(_WORD *)((char *)&v6->vfptr + v17);
        if ( v7 >= 0 )
        {
          v8 = -*(float *)((char *)&v6->vfptr + v5);
          ((void (__stdcall *)(__int16, _DWORD, _DWORD))v3->owner->vfptr->add_attribute_num)(v7, LODWORD(v8), 0);
          v4 = 2;
        }
      }
      v5 += 4;
      ++a2;
      v17 += 2;
    }
    while ( v5 < 124 );
  }
  if ( !v3->object_state )
    v3->vfptr->unexplore_terrain((RGE_Static_Object *)v3, v3->owner, 1, -1);
  if ( v3->production_queue_count > 0 )
  {
    if ( v3->production_queue_need_attr == 4 )
    {
      v9 = v3->owner;
      v3->production_queue_need_attr = -1;
      --*((_DWORD *)&rge_base_game[1].prog_window + v9->id);
    }
    v10 = v3->production_queue;
    v3->production_queue_count = 1;
    v10->unit_count = 1;
  }
  RGE_Action_List::delete_list(v3->actions);
  TRIBE_Combat_Object::change_ownership((TRIBE_Combat_Object *)&v3->vfptr, a2, new_owner);
  if ( !v3->object_state )
    v3->vfptr->explore_terrain((RGE_Static_Object *)v3, v3->owner, 1, -1);
  if ( v3->object_state == v4 )
  {
    v11 = HIWORD(v3->master_obj[2].vfptr);
    if ( v11 > -1 )
      ((void (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v3->owner->master_objects[v11]->vfptr->make_new_obj)(
        v3->owner,
        LODWORD(v3->world_x),
        LODWORD(v3->world_y),
        LODWORD(v3->world_z));
    v12 = (__int16)v3->master_obj[2].name;
    if ( v12 > -1 )
      TRIBE_Player_Tech::do_tech((TRIBE_Player_Tech *)v3->owner[1].vfptr, v12);
    if ( v3->object_state == v4 )
    {
      v13 = 0;
      new_ownera = (RGE_Player *)106;
      v14 = 112;
      do
      {
        v15 = v3->master_obj;
        if ( v15->attribute_flag[v13] >= 4u )
        {
          HIWORD(v16) = HIWORD(new_ownera);
          LOWORD(v16) = *(_WORD *)((char *)&v15->vfptr + (_DWORD)new_ownera);
          if ( (signed __int16)v16 >= 0 )
            ((void (__stdcall *)(int, _DWORD, _DWORD))v3->owner->vfptr->add_attribute_num)(
              v16,
              *(RGE_Master_Static_ObjectVtbl **)((char *)&v15->vfptr + v14),
              0);
        }
        v14 += 4;
        ++v13;
        new_ownera = (RGE_Player *)((char *)new_ownera + 2);
      }
      while ( v14 < 124 );
    }
  }
}

//----- (004C8E60) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::modify(TRIBE_Building_Object *this, float amount, char flag)
{
  if ( flag == 17 )
    this->facet = (signed __int64)amount;
  else
    TRIBE_Combat_Object::modify((TRIBE_Combat_Object *)&this->vfptr, amount, flag);
}

//----- (004C8E90) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::transform(TRIBE_Building_Object *this, TRIBE_Master_Building_Object *obj)
{
  TRIBE_Building_Object *v2; // esi@1
  RGE_Master_Static_Object *v3; // eax@1

  v2 = this;
  TRIBE_Combat_Object::transform((TRIBE_Combat_Object *)&this->vfptr, (RGE_Master_Static_Object *)&obj->vfptr);
  v3 = v2->master_obj;
  v2->object_state = 0;
  if ( SHIWORD(v3[1].hotkey_id) > 0 )
    (*(void (__thiscall **)(TRIBE_Building_Object *, RGE_Sprite *))&v2->vfptr->gap4[52])(v2, obj->construction_sprite);
  LODWORD(v2->build_pts) = 0;
}

//----- (004C8ED0) --------------------------------------------------------
int __thiscall TRIBE_Building_Object::check(TRIBE_Building_Object *this, TRIBE_Building_Object **checks)
{
  TRIBE_Building_Object *v2; // esi@1
  RGE_Map *v3; // edi@1
  __int16 v4; // bp@1
  TRIBE_Building_Object *v5; // eax@2
  TRIBE_Building_Object **v6; // ebx@2
  RGE_Static_Object *v7; // eax@8
  RGE_Static_Object *v8; // eax@13
  RGE_Static_Object *v9; // eax@18
  int counter; // [sp+10h] [bp-10h]@1
  int x; // [sp+14h] [bp-Ch]@1
  signed __int16 w; // [sp+18h] [bp-8h]@1
  __int16 h; // [sp+1Ch] [bp-4h]@1

  v2 = this;
  v3 = this->owner->world->map;
  x = (signed __int64)this->world_x;
  v4 = (signed __int64)this->world_y;
  counter = 0;
  w = LOWORD(v3->map_width) - 1;
  h = LOWORD(v3->map_height) - 1;
  if ( v4 <= 0 )
  {
    v6 = checks;
  }
  else
  {
    v5 = (TRIBE_Building_Object *)RGE_Object_List::find_by_master_id(
                                    &v3->map_row_offset[v4 - 1][(signed __int16)(signed __int64)this->world_x].objects,
                                    this->master_obj->id,
                                    -1.0,
                                    -1.0,
                                    0,
                                    0,
                                    0);
    v6 = checks;
    *checks = v5;
    if ( !v5 )
      goto LABEL_7;
    if ( v5->owner == v2->owner )
    {
      counter = 1;
      goto LABEL_7;
    }
  }
  *v6 = 0;
LABEL_7:
  if ( (signed __int16)x <= 0 )
    goto LABEL_11;
  v7 = RGE_Object_List::find_by_master_id(
         (RGE_Object_List *)&v3->map_row_offset[v4][(signed __int16)x] - 1,
         v2->master_obj->id,
         -1.0,
         -1.0,
         0,
         0,
         0);
  v6[1] = (TRIBE_Building_Object *)v7;
  if ( v7 )
  {
    if ( v7->owner == v2->owner )
    {
      ++counter;
      goto LABEL_12;
    }
LABEL_11:
    v6[1] = 0;
  }
LABEL_12:
  if ( (signed __int16)x >= w )
    goto LABEL_25;
  v8 = RGE_Object_List::find_by_master_id(
         &v3->map_row_offset[v4][(signed __int16)x + 1].objects,
         v2->master_obj->id,
         -1.0,
         -1.0,
         0,
         0,
         0);
  v6[2] = (TRIBE_Building_Object *)v8;
  if ( !v8 )
    goto LABEL_17;
  if ( v8->owner != v2->owner )
LABEL_25:
    v6[2] = 0;
  else
    ++counter;
LABEL_17:
  if ( v4 >= h )
  {
LABEL_21:
    v6[3] = 0;
    return counter;
  }
  v9 = RGE_Object_List::find_by_master_id(
         &v3->map_row_offset[v4 + 1][(signed __int16)x].objects,
         v2->master_obj->id,
         -1.0,
         -1.0,
         0,
         0,
         0);
  v6[3] = (TRIBE_Building_Object *)v9;
  if ( v9 )
  {
    if ( v9->owner == v2->owner )
      return counter + 1;
    goto LABEL_21;
  }
  return counter;
}

//----- (004C90B0) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::connect(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1
  RGE_Sprite *v2; // eax@1
  TRIBE_Building_Object *v3; // eax@3
  TRIBE_Building_Object *v4; // ecx@3
  signed int v5; // edx@7
  TRIBE_Building_Object *checks[4]; // [sp+8h] [bp-10h]@3

  v1 = this;
  v2 = this->sprite;
  if ( !v2 )
    return;
  if ( v2->facet_num != 3 )
  {
    this->facet = 0;
    return;
  }
  RGE_Moving_Object::set_angle((RGE_Moving_Object *)&this->vfptr);
  TRIBE_Building_Object::check(v1, checks);
  v3 = checks[0];
  v4 = checks[1];
  if ( checks[0] && checks[3] )
  {
    if ( checks[1] )
      goto LABEL_9;
    if ( !checks[2] )
    {
      LOBYTE(v4) = v1->facet;
      v5 = 1;
LABEL_14:
      RGE_Moving_Object::rotate((RGE_Moving_Object *)&v1->vfptr, v5 - (_DWORD)v4);
      goto LABEL_15;
    }
  }
  if ( !checks[1] )
  {
LABEL_13:
    v5 = 2;
    v4 = (TRIBE_Building_Object *)v1->facet;
    goto LABEL_14;
  }
LABEL_9:
  if ( !checks[2] || checks[0] || checks[3] )
    goto LABEL_13;
  LOBYTE(v3) = v1->facet;
  RGE_Moving_Object::rotate((RGE_Moving_Object *)&v1->vfptr, -(signed int)v3);
LABEL_15:
  if ( checks[0] )
    TRIBE_Building_Object::connect2(checks[0]);
  if ( checks[1] )
    TRIBE_Building_Object::connect2(checks[1]);
  if ( checks[2] )
    TRIBE_Building_Object::connect2(checks[2]);
  if ( checks[3] )
    TRIBE_Building_Object::connect2(checks[3]);
}

//----- (004C9180) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::connect2(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1
  RGE_Sprite *v2; // eax@1
  TRIBE_Building_Object *v3; // eax@3
  TRIBE_Building_Object *v4; // ecx@3
  TRIBE_Building_Object *checks[4]; // [sp+8h] [bp-10h]@3

  v1 = this;
  v2 = this->sprite;
  if ( v2 )
  {
    if ( v2->facet_num == 3 )
    {
      TRIBE_Building_Object::check(this, checks);
      v3 = checks[0];
      v4 = checks[1];
      if ( checks[0] && checks[3] )
      {
        if ( checks[1] )
          goto LABEL_9;
        if ( !checks[2] )
        {
          LOBYTE(v4) = v1->facet;
          RGE_Moving_Object::rotate((RGE_Moving_Object *)&v1->vfptr, 1 - (_DWORD)v4);
          return;
        }
      }
      if ( !checks[1] )
      {
LABEL_13:
        RGE_Moving_Object::rotate((RGE_Moving_Object *)&v1->vfptr, 2 - v1->facet);
        return;
      }
LABEL_9:
      if ( checks[2] && !checks[0] && !checks[3] )
      {
        LOBYTE(v3) = v1->facet;
        RGE_Moving_Object::rotate((RGE_Moving_Object *)&v1->vfptr, -(signed int)v3);
        return;
      }
      goto LABEL_13;
    }
    this->facet = 0;
  }
}

//----- (004C9230) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::lay_down_impassable_terrain(TRIBE_Building_Object *this)
{
  RGE_Master_Static_Object *v1; // edi@1
  signed __int16 v2; // bx@2
  signed __int64 v3; // rax@2
  int v4; // ebp@11
  int v5; // ebx@11
  int v6; // esi@13
  int v7; // edi@13
  int v8; // ecx@14
  char v9; // al@14
  char v10; // al@17
  int tx2; // [sp+10h] [bp-Ch]@2
  int tx1; // [sp+14h] [bp-8h]@2
  RGE_Map *map; // [sp+18h] [bp-4h]@1

  v1 = this->master_obj;
  map = this->owner->world->map;
  if ( *(_WORD *)&v1[2].master_type <= -1 )
  {
    tx1 = (signed __int64)(this->world_x - v1->radius_x);
    tx2 = (signed __int64)(v1->radius_x + this->world_x - 0.0099999998);
    v2 = (signed __int64)(this->world_y - v1->radius_y);
    v3 = (signed __int64)(v1->radius_y + this->world_y - 0.0099999998);
    if ( (signed __int16)(signed __int64)(this->world_x - v1->radius_x) < 0 )
      LOWORD(tx1) = 0;
    if ( v2 < 0 )
      v2 = 0;
    if ( (signed __int16)tx2 >= map->map_width )
      LOWORD(tx2) = LOWORD(map->map_width) - 1;
    if ( (signed __int16)v3 >= map->map_height )
      LOWORD(v3) = LOWORD(map->map_height) - 1;
    if ( v2 <= (signed __int16)v3 )
    {
      v4 = v2;
      v5 = (signed __int16)v3 - v2 + 1;
      while ( (signed __int16)tx1 > (signed __int16)tx2 )
      {
LABEL_22:
        ++v4;
        if ( !--v5 )
          return;
      }
      v6 = (signed __int16)tx1;
      v7 = (signed __int16)tx2 - (signed __int16)tx1 + 1;
      while ( 1 )
      {
        v8 = (int)&map->map_row_offset[v4][v6].screen_xpos;
        v9 = *(_BYTE *)(v8 + 5);
        if ( !(*(_BYTE *)(v8 + 5) & 0x1F) )
        {
          v10 = v9 & 0xF0 | 0x10;
          goto LABEL_20;
        }
        if ( (*(_BYTE *)(v8 + 5) & 0x1F) == 1 )
          break;
        if ( (*(_BYTE *)(v8 + 5) & 0x1F) == 6 )
        {
          v10 = v9 & 0xEE | 0xE;
LABEL_20:
          *(_BYTE *)(v8 + 5) = v10;
        }
        ++v6;
        if ( !--v7 )
          goto LABEL_22;
      }
      v10 = v9 & 0xEF | 0xF;
      goto LABEL_20;
    }
  }
}

//----- (004C9360) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::lay_down_passable_terrain(TRIBE_Building_Object *this)
{
  RGE_Master_Static_Object *v1; // edi@1
  signed __int16 v2; // bx@2
  signed __int64 v3; // rax@2
  int v4; // ebp@11
  int v5; // ebx@11
  int v6; // esi@13
  int v7; // edi@13
  int v8; // ecx@14
  char v9; // al@14
  char v10; // al@17
  int tx2; // [sp+10h] [bp-Ch]@2
  int tx1; // [sp+14h] [bp-8h]@2
  RGE_Map *map; // [sp+18h] [bp-4h]@1

  v1 = this->master_obj;
  map = this->owner->world->map;
  if ( *(_WORD *)&v1[2].master_type <= -1 )
  {
    tx1 = (signed __int64)(this->world_x - v1->radius_x);
    tx2 = (signed __int64)(v1->radius_x + this->world_x - 0.0099999998);
    v2 = (signed __int64)(this->world_y - v1->radius_y);
    v3 = (signed __int64)(v1->radius_y + this->world_y - 0.0099999998);
    if ( (signed __int16)(signed __int64)(this->world_x - v1->radius_x) < 0 )
      LOWORD(tx1) = 0;
    if ( v2 < 0 )
      v2 = 0;
    if ( (signed __int16)tx2 >= map->map_width )
      LOWORD(tx2) = LOWORD(map->map_width) - 1;
    if ( (signed __int16)v3 >= map->map_height )
      LOWORD(v3) = LOWORD(map->map_height) - 1;
    if ( v2 <= (signed __int16)v3 )
    {
      v4 = v2;
      v5 = (signed __int16)v3 - v2 + 1;
      while ( (signed __int16)tx1 > (signed __int16)tx2 )
      {
LABEL_22:
        ++v4;
        if ( !--v5 )
          return;
      }
      v6 = (signed __int16)tx1;
      v7 = (signed __int16)tx2 - (signed __int16)tx1 + 1;
      while ( 1 )
      {
        v8 = (int)&map->map_row_offset[v4][v6].screen_xpos;
        v9 = *(_BYTE *)(v8 + 5);
        if ( (*(_BYTE *)(v8 + 5) & 0x1F) == 14 )
        {
          v10 = v9 & 0xE6 | 6;
          goto LABEL_20;
        }
        if ( (*(_BYTE *)(v8 + 5) & 0x1F) == 15 )
          break;
        if ( (*(_BYTE *)(v8 + 5) & 0x1F) == 16 )
        {
          v10 = v9 & 0xE0;
LABEL_20:
          *(_BYTE *)(v8 + 5) = v10;
        }
        ++v6;
        if ( !--v7 )
          goto LABEL_22;
      }
      v10 = v9 & 0xE1 | 1;
      goto LABEL_20;
    }
  }
}

//----- (004C9480) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::cancel_object(TRIBE_Building_Object *this)
{
  if ( this->object_state >= 2u )
    TRIBE_Combat_Object::cancel_object((TRIBE_Combat_Object *)&this->vfptr);
  else
    TRIBE_Building_Object::cancel_build(this);
}

//----- (004C9490) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::cancel_build(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // edi@1
  double v2; // st7@5
  signed int v3; // esi@9
  RGE_Master_Static_Object *v4; // eax@10
  __int16 v5; // dx@10
  float v6; // ST04_4@12
  float percent; // [sp+14h] [bp-8h]@5

  v1 = this;
  if ( this->selected & 1 )
    RGE_Player::unselect_one_object(this->owner, (RGE_Static_Object *)&this->vfptr);
  if ( v1->object_state >= 2u || v1->hp <= 0.0 )
  {
    percent = 0.0;
  }
  else
  {
    v2 = (double)HIWORD(v1->master_obj[1].hotkey_id);
    percent = (v2 - v1->build_pts) / v2 * 0.5;
  }
  if ( percent > 1.0 )
    percent = 1.0;
  v3 = 0;
  do
  {
    v4 = v1->master_obj;
    v5 = *(_WORD *)(&v4[1].map_color + v3);
    if ( v5 >= 0 && *((_BYTE *)&v4[1].damage_sprites + v3) )
    {
      v6 = (double)*(_WORD *)(&v4[1].convert_terrain_flag + v3) * percent;
      ((void (__stdcall *)(__int16, _DWORD, _DWORD))v1->owner->vfptr->add_attribute_num)(v5, LODWORD(v6), 0);
    }
    v3 += 6;
  }
  while ( v3 < 18 );
  LODWORD(v1->hp) = 0;
}

//----- (004C9560) --------------------------------------------------------
char __thiscall TRIBE_Building_Object::build(TRIBE_Building_Object *this, float build_amount)
{
  RGE_Master_Static_Object *v2; // edx@2
  double v3; // st7@2
  double v4; // st7@4
  double v5; // st6@4
  double v6; // st7@4
  double v7; // st7@6
  char result; // al@7

  if ( this->object_state )
  {
    result = 1;
  }
  else
  {
    v2 = this->master_obj;
    v3 = (double)HIWORD(v2[1].hotkey_id);
    if ( build_amount + this->build_pts > v3 )
      build_amount = v3 - this->build_pts;
    v4 = (double)v2->hp * build_amount / v3 + this->hp;
    this->hp = v4;
    v5 = v4;
    v6 = (double)v2->hp;
    if ( v5 > v6 )
      this->hp = v6;
    v7 = build_amount + this->build_pts;
    this->build_pts = v7;
    if ( v7 < (double)HIWORD(v2[1].hotkey_id) )
    {
      result = 0;
    }
    else
    {
      ((void (__stdcall *)(signed int))this->vfptr->set_object_state)(2);
      result = 1;
    }
  }
  return result;
}

//----- (004C9620) --------------------------------------------------------
int __thiscall TRIBE_Building_Object::work_status(TRIBE_Building_Object *this, __int16 *work_type, __int16 *work_target, __int16 *progress, char *name, __int16 name_size)
{
  TRIBE_Action_Make_Tech *v6; // ecx@1
  __int16 *v7; // eax@2
  int v8; // eax@4
  int result; // eax@8

  v6 = (TRIBE_Action_Make_Tech *)RGE_Action_List::get_action(this->actions);
  if ( v6 )
  {
    v7 = work_type;
    *work_type = v6->action_type;
  }
  else
  {
    v7 = work_type;
    *work_type = 0;
  }
  v8 = *v7 - 102;
  if ( v8 )
  {
    if ( v8 == 1 )
    {
      TRIBE_Action_Make_Tech::get_info(v6, work_target, progress, name, name_size);
      result = 1;
    }
    else
    {
      *work_target = -1;
      *progress = 0;
      if ( name )
        *name = 0;
      result = 0;
    }
  }
  else
  {
    TRIBE_Action_Make_Obj::get_info((TRIBE_Action_Make_Obj *)v6, work_target, progress, name, name_size);
    result = 1;
  }
  return result;
}

//----- (004C96C0) --------------------------------------------------------
__int16 __thiscall TRIBE_Building_Object::get_construction_progress(TRIBE_Building_Object *this)
{
  signed __int64 v1; // rax@2
  __int16 v2; // ax@3

  if ( this->object_state )
  {
    LOWORD(v1) = 100;
  }
  else
  {
    v2 = HIWORD(this->master_obj[1].hotkey_id);
    if ( v2 )
      v1 = (signed __int64)(this->build_pts / (double)v2 * 100.0);
    else
      LOWORD(v1) = 100;
  }
  return v1;
}

//----- (004C9710) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::copy_obj(TRIBE_Building_Object *this, RGE_Master_Static_Object *source)
{
  TRIBE_Building_Object *v2; // esi@1

  v2 = this;
  if ( this->sprite == (RGE_Sprite *)LODWORD(this->master_obj[1].outline_radius_y) )
    (*(void (__thiscall **)(TRIBE_Building_Object *, _DWORD))&this->vfptr->gap4[52])(
      this,
      LODWORD(source[1].outline_radius_y));
  RGE_Combat_Object::copy_obj((RGE_Combat_Object *)&v2->vfptr, source);
  if ( LOBYTE(v2->master_obj[1].outline_radius_z) )
    TRIBE_Building_Object::connect(v2);
}

//----- (004C9770) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::damage(TRIBE_Building_Object *this, int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attacking_object)
{
  TRIBE_Building_Object *v6; // edi@1
  double v7; // st7@1
  RGE_Master_Static_Object *v8; // ecx@2
  __int16 v9; // ax@2
  __int16 v10; // cx@6
  double v11; // st7@12
  float temp_hp; // [sp+Ch] [bp-4h]@1

  v6 = this;
  v7 = this->hp;
  temp_hp = this->hp;
  if ( v7 <= 0.0 )
    return;
  RGE_Combat_Object::damage(
    (RGE_Combat_Object *)&this->vfptr,
    v7,
    weapon_num,
    damage,
    attack_modifier,
    attacking_player,
    attacking_object);
  v8 = attacking_object->master_obj;
  v9 = v8->object_group;
  if ( v9
    && v9 != 23
    && v9 != 36
    && v9 != 26
    && (v10 = v8->id, v10 != 79)
    && v10 != 69
    && v10 != 199
    && v10 != 383
    && v10 != 380 )
  {
    if ( temp_hp - v6->hp >= 1.0 )
      goto LABEL_16;
    v11 = temp_hp - 1.0;
  }
  else
  {
    if ( temp_hp - v6->hp >= 0.1 )
      goto LABEL_16;
    v11 = temp_hp - 0.1;
  }
  v6->hp = v11;
LABEL_16:
  if ( v6->owner->id > 0 && v6->hp < 1.0 )
    ((void (__thiscall *)(RGE_Player *, signed int, signed int, _DWORD))attacking_player->vfptr->add_attribute_num)(
      attacking_player,
      43,
      1065353216,
      0);
}

//----- (004C9870) --------------------------------------------------------
void __userpurge TRIBE_Building_Object::add_to_production_queue(TRIBE_Building_Object *this@<ecx>, int a2@<ebx>, __int16 master_id, __int16 unit_count)
{
  TRIBE_Building_Object *v4; // esi@1
  __int16 v5; // di@1
  __int16 v6; // ax@1
  int v7; // ebx@3
  int v8; // ebp@3
  RGE_Player *v9; // edx@9
  __int16 v10; // ax@14
  char *v11; // ebx@15
  int v12; // ecx@17
  int v13; // eax@18
  int v14; // ebp@21
  int v15; // ebx@21
  bool v16; // zf@21
  bool v17; // sf@21
  char v18; // al@26
  char queue_changed; // [sp+15h] [bp-1h]@1

  v4 = this;
  v5 = master_id;
  v6 = this->production_queue_count;
  queue_changed = 0;
  if ( v6 <= 0 || this->production_queue[v6 - 1].master_id != master_id )
  {
    if ( v6 > 0 )
    {
      do
        TRIBE_Building_Object::remove_from_production_queue(v4, a2, v4->production_queue->master_id, 1);
      while ( v4->production_queue_count > 0 );
    }
    if ( !TRIBE_Player::check_obj_cost((TRIBE_Player *)v4->owner, v5, &master_id, 1.0, 1) )
    {
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        125,
        v4->owner->id,
        master_id,
        0,
        0);
      return;
    }
    v10 = v4->production_queue_size;
    if ( v4->production_queue_count == v10 )
    {
      v11 = (char *)calloc(v10 + 10, 4u);
      if ( !v11 )
        return;
      if ( v4->production_queue )
      {
        v12 = 0;
        if ( v4->production_queue_size > 0 )
        {
          do
          {
            v13 = (signed __int16)v12++;
            *(_WORD *)&v11[v13 * 4] = v4->production_queue[v13].master_id;
            *(_WORD *)&v11[v13 * 4 + 2] = v4->production_queue[v13].unit_count;
          }
          while ( (signed __int16)v12 < v4->production_queue_size );
        }
        free(v4->production_queue);
      }
      v4->production_queue_size += 10;
      v4->production_queue = (Production_Queue_Record *)v11;
    }
    v14 = unit_count;
    v15 = 0;
    v16 = unit_count == 0;
    v17 = unit_count < 0;
    v4->production_queue[v4->production_queue_count].unit_count = 0;
    if ( !v17 && !v16 )
    {
      while ( TRIBE_Player::check_obj_cost((TRIBE_Player *)v4->owner, v5, &master_id, 1.0, 1) )
      {
        TRIBE_Player::pay_obj_cost((TRIBE_Player *)v4->owner, v5, 1.0, 1);
        ++v4->production_queue[v4->production_queue_count].unit_count;
        if ( ++v15 >= v14 )
          goto LABEL_26;
      }
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        125,
        v4->owner->id,
        master_id,
        0,
        0);
    }
LABEL_26:
    v4->production_queue[v4->production_queue_count].master_id = v5;
    v18 = v4->production_queue_change_flag;
    ++v4->production_queue_count;
    v4->production_queue_change_flag = v18 + 1;
    ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
      124,
      v4->owner->id,
      0,
      0,
      0);
  }
  else
  {
    v7 = unit_count;
    v8 = 0;
    if ( unit_count > 0 )
    {
      while ( TRIBE_Player::check_obj_cost((TRIBE_Player *)v4->owner, v5, &master_id, 1.0, 1) )
      {
        TRIBE_Player::pay_obj_cost((TRIBE_Player *)v4->owner, v5, 1.0, 1);
        ++*((_WORD *)&v4->production_queue[v4->production_queue_count] - 1);
        ++v8;
        queue_changed = 1;
        if ( v8 >= v7 )
          goto LABEL_8;
      }
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        125,
        v4->owner->id,
        master_id,
        0,
        0);
    }
LABEL_8:
    if ( queue_changed == 1 )
    {
      v9 = v4->owner;
      ++v4->production_queue_change_flag;
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        124,
        v9->id,
        0,
        0,
        0);
    }
  }
}

//----- (004C9B10) --------------------------------------------------------
void __userpurge TRIBE_Building_Object::remove_from_production_queue(TRIBE_Building_Object *this@<ecx>, int a2@<ebx>, __int16 master_id, __int16 unit_count)
{
  TRIBE_Building_Object *v4; // esi@1
  int v5; // ebx@2
  Production_Queue_Record *v6; // eax@3
  __int16 v7; // cx@7
  int v8; // edi@7
  int v9; // ebp@7
  __int16 v10; // ax@7
  Production_Queue_Record *v11; // eax@12
  int i; // eax@13
  int v13; // ecx@14
  __int16 v14; // ax@16
  char *v15; // eax@18

  v4 = this;
  LOWORD(a2) = this->production_queue_count;
  if ( (_WORD)a2 )
  {
    v5 = a2 - 1;
    if ( (signed __int16)v5 >= 0 )
    {
      v6 = this->production_queue;
      while ( v6[(signed __int16)v5].master_id != master_id )
      {
        if ( (signed __int16)--v5 < 0 )
          goto LABEL_21;
      }
      v7 = unit_count;
      v8 = (signed __int16)v5;
      v9 = unit_count;
      v10 = v6[v8].unit_count;
      if ( v10 <= unit_count )
        v9 = v10;
      if ( v9 > 0 )
      {
        do
        {
          TRIBE_Player::reimburse_obj_cost((TRIBE_Player *)v4->owner, master_id);
          --v9;
        }
        while ( v9 );
        v7 = unit_count;
      }
      v4->production_queue[v8].unit_count -= v7;
      v11 = v4->production_queue;
      ++v4->production_queue_change_flag;
      if ( v11[v8].unit_count <= 0 )
      {
        --v4->production_queue_count;
        for ( i = v5;
              (signed __int16)i < v4->production_queue_count;
              v4->production_queue[v13].unit_count = v4->production_queue[v13 + 1].unit_count )
        {
          v13 = (signed __int16)i++;
          v4->production_queue[v13].master_id = v4->production_queue[v13 + 1].master_id;
        }
        if ( !(_WORD)v5 )
        {
          v14 = v4->production_queue_need_attr;
          if ( v14 != -1 )
          {
            if ( v14 == 4 )
            {
              v15 = (char *)(&rge_base_game[1].prog_window + v4->owner->id);
              --*(_DWORD *)v15;
            }
            v4->production_queue_need_attr = -1;
          }
          RGE_Action_List::action_stop(v4->production_queue_actions);
          RGE_Action_List::delete_list(v4->production_queue_actions);
        }
      }
    }
LABEL_21:
    ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
      124,
      v4->owner->id,
      0,
      0,
      0);
  }
}

//----- (004C9C80) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::advance_production_queue(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // eax@1
  signed int i; // ecx@3
  Production_Queue_Record *v3; // edx@4
  __int16 v4; // si@4
  int v5; // edx@4

  v1 = this;
  if ( this->production_queue_count )
  {
    --this->production_queue->unit_count;
    ++this->production_queue_change_flag;
    if ( this->production_queue->unit_count <= 0 )
    {
      --this->production_queue_count;
      for ( i = 0; i < v1->production_queue_count; *(_WORD *)(v5 + 2) = v4 )
      {
        v1->production_queue[i].master_id = v1->production_queue[i + 1].master_id;
        v3 = v1->production_queue;
        v4 = v3[i + 1].unit_count;
        v5 = (int)&v3[i++];
      }
    }
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
      124,
      v1->owner->id,
      0,
      0,
      0);
  }
}

//----- (004C9D20) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::empty_production_queue(TRIBE_Building_Object *this)
{
  TRIBE_Building_Object *v1; // esi@1
  __int16 v2; // ax@1
  char *v3; // eax@3
  RGE_Action_List *v4; // ecx@5

  v1 = this;
  v2 = this->production_queue_need_attr;
  if ( v2 != -1 )
  {
    if ( v2 == 4 )
    {
      v3 = (char *)(&rge_base_game[1].prog_window + this->owner->id);
      --*(_DWORD *)v3;
    }
    this->production_queue_need_attr = -1;
  }
  v4 = this->production_queue_actions;
  v1->production_queue_count = 0;
  RGE_Action_List::delete_list(v4);
  ++v1->production_queue_change_flag;
}

//----- (004C9D90) --------------------------------------------------------
void __thiscall TRIBE_Building_Object::enable_production_queue(TRIBE_Building_Object *this, int enabled)
{
  this->production_queue_enabled = enabled;
}

//----- (004C9DA0) --------------------------------------------------------
void __usercall TRIBE_Building_Object::update_production_queue(TRIBE_Building_Object *this@<ecx>, int a2@<ebx>)
{
  TRIBE_Building_Object *v2; // esi@1
  RGE_Player *v3; // edx@10
  float *v4; // ecx@10
  char *v5; // eax@12
  char *v6; // eax@15
  TRIBE_Action_Make_Obj *v7; // eax@16
  RGE_Action *v8; // eax@17
  char v9; // al@21
  RGE_Player *v10; // eax@26
  char *v11; // eax@26
  char *v12; // eax@29
  __int16 work_type; // [sp+Ah] [bp-16h]@3
  __int16 progress; // [sp+Ch] [bp-14h]@3
  __int16 work_target; // [sp+Eh] [bp-12h]@3
  TRIBE_Action_Make_Obj *v16; // [sp+10h] [bp-10h]@16
  int v17; // [sp+1Ch] [bp-4h]@16

  v2 = this;
  if ( this->production_queue_enabled && this->production_queue_count )
  {
    if ( TRIBE_Building_Object::work_status(this, &work_type, &work_target, &progress, 0, 0)
      && (work_type == 102 || work_type == 103) )
    {
      while ( v2->production_queue_count > 0 )
        TRIBE_Building_Object::remove_from_production_queue(v2, a2, v2->production_queue->master_id, -1);
      return;
    }
    if ( v2->production_queue_actions->list )
      goto LABEL_21;
    v3 = v2->owner;
    v4 = v3->attributes;
    if ( v4[11] >= (double)v4[32] )
    {
      if ( v2->production_queue_need_attr != 32 )
      {
        v2->production_queue_need_attr = 32;
        ((void (__stdcall *)(signed int, _DWORD, signed int, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
          125,
          v3->id,
          32,
          0,
          0);
        v5 = (char *)(&rge_base_game[1].prog_window + v2->owner->id);
        ++*(_DWORD *)v5;
      }
      return;
    }
    if ( v4[4] > 0.0 )
    {
      if ( v2->production_queue_need_attr == 4 )
      {
        v6 = (char *)(&rge_base_game[1].prog_window + v3->id);
        --*(_DWORD *)v6;
      }
      v2->production_queue_need_attr = -1;
      v7 = (TRIBE_Action_Make_Obj *)operator new(0x50u);
      v16 = v7;
      v17 = 0;
      if ( v7 )
        TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(
          v7,
          (RGE_Action_Object *)&v2->vfptr,
          v2->production_queue->master_id,
          -1,
          1);
      else
        v8 = 0;
      v17 = -1;
      if ( v8 )
        RGE_Action_List::add_action(v2->production_queue_actions, v8);
LABEL_21:
      v9 = ((int (*)(void))v2->production_queue_actions->vfptr->update)();
      if ( v9 == 3 || v9 == 2 || v9 == 1 )
      {
        RGE_Action_List::remove_action(v2->production_queue_actions);
        TRIBE_Building_Object::advance_production_queue(v2);
      }
      return;
    }
    if ( v2->production_queue_need_attr != 4 )
    {
      v2->production_queue_need_attr = 4;
      ((void (__stdcall *)(signed int, _DWORD, signed int, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        125,
        v3->id,
        4,
        0,
        0);
      v12 = (char *)(&rge_base_game[1].prog_window + v2->owner->id);
      ++*(_DWORD *)v12;
    }
  }
  else if ( this->production_queue_need_attr == 4 )
  {
    v10 = this->owner;
    this->production_queue_need_attr = -1;
    v11 = (char *)(&rge_base_game[1].prog_window + v10->id);
    --*(_DWORD *)v11;
  }
}

//----- (004CA030) --------------------------------------------------------
int __thiscall TRIBE_Building_Object::production_queue_status(TRIBE_Building_Object *this, __int16 *master_id, __int16 *progress)
{
  TRIBE_Building_Object *v3; // esi@1
  TRIBE_Action_Make_Obj *v4; // eax@1
  int result; // eax@3

  v3 = this;
  *master_id = -1;
  *progress = 0;
  v4 = (TRIBE_Action_Make_Obj *)RGE_Action_List::get_action(this->production_queue_actions);
  if ( v4 && v4->action_type == 102 )
  {
    TRIBE_Action_Make_Obj::get_info(v4, master_id, progress, 0, 0);
    result = 1;
  }
  else if ( v3->production_queue_count <= 0 )
  {
    result = 0;
  }
  else
  {
    result = 1;
    *master_id = v3->production_queue->master_id;
    *progress = 0;
  }
  return result;
}

//----- (004CA0B0) --------------------------------------------------------
void __usercall TRIBE_Building_Object::stop(TRIBE_Building_Object *this@<ecx>, int a2@<ebx>)
{
  TRIBE_Building_Object *v2; // esi@1

  v2 = this;
  RGE_Combat_Object::stop((RGE_Combat_Object *)&this->vfptr);
  while ( v2->production_queue_count > 0 )
    TRIBE_Building_Object::remove_from_production_queue(v2, a2, v2->production_queue->master_id, 1);
}
