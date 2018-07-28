
//----- (0046E4B0) --------------------------------------------------------
void __thiscall RGE_Player::RGE_Player(RGE_Player *this, int infile, RGE_Game_World *gworld, char this_id)
{
  RGE_Player *v4; // esi@1
  char *v5; // ebx@1
  int v6; // eax@1
  RGE_Doppleganger_Creator *v7; // eax@1
  RGE_Doppleganger_Creator *v8; // eax@2
  RGE_Game_World *v9; // eax@4
  char *v10; // eax@4
  RGE_Game_World *v11; // edx@4
  char *v12; // eax@8
  int v13; // ecx@8
  __int16 *v14; // ebp@10
  float *v15; // eax@11
  int v16; // ecx@11
  __int16 index; // [sp+12h] [bp-16h]@7
  int table; // [sp+14h] [bp-14h]@13
  RGE_Player *v19; // [sp+18h] [bp-10h]@1
  int v20; // [sp+24h] [bp-4h]@1

  v4 = this;
  v5 = (char *)&this->pathingAttemptCapValue;
  v19 = this;
  this->computerPlayerValue = 0;
  this->pathingAttemptCapValue = 5;
  this->pathingDelayCapValue = 10;
  RGE_Tile_List::RGE_Tile_List(&this->tile_list, 400);
  v20 = 0;
  RGE_Tile_List::RGE_Tile_List(&v4->diam_tile_list, 400);
  v4->vfptr = (RGE_PlayerVtbl *)&RGE_Player::`vftable';
  v6 = pathingCapValue;
  v4->id = (unsigned __int8)this_id;
  *(_DWORD *)v5 = v6;
  v4->world = gworld;
  RGE_Player::reset_selected(v4);
  v7 = (RGE_Doppleganger_Creator *)operator new(0x1Cu);
  LOBYTE(v20) = 2;
  if ( v7 )
    RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(v7, v4, 100);
  else
    v8 = 0;
  v4->doppleganger_creator = v8;
  v9 = v4->world;
  LOBYTE(v20) = 1;
  v10 = (char *)calloc(1u, v9->player_num);
  v11 = v4->world;
  v4->relations = v10;
  rge_read(0, infile, infile, v10, v11->player_num);
  rge_read(0, infile, infile, v4->unitDiplomacy, 36);
  if ( save_game_version < 4.0100002 )
    v4->allied_LOS_Enable = 0;
  else
    rge_read(0, infile, infile, &v4->allied_LOS_Enable, 4);
  rge_read(0, infile, infile, &v4->allied_victory, 1);
  rge_read(0, infile, infile, &index, 2);
  if ( index <= 0 )
  {
    v4->name = 0;
  }
  else
  {
    v12 = (char *)calloc(index, 1u);
    v13 = index;
    v4->name = v12;
    rge_read(0, infile, infile, v12, v13);
  }
  v14 = &v4->attribute_num;
  rge_read((int)&v4->attribute_num, infile, infile, &v4->attribute_num, 2);
  if ( v4->attribute_num <= 0 )
  {
    v4->attributes = 0;
  }
  else
  {
    v15 = (float *)calloc(v4->attribute_num, 4u);
    v16 = *v14;
    v4->attributes = v15;
    rge_read((int)v14, infile, infile, v15, 4 * v16);
  }
  rge_read((int)v14, infile, infile, &v4->view_x, 4);
  rge_read((int)v14, infile, infile, &v4->view_y, 4);
  rge_read((int)v14, infile, infile, &v4->map_x, 2);
  rge_read((int)v14, infile, infile, &v4->map_y, 2);
  rge_read((int)v14, infile, infile, &v4->culture, 1);
  rge_read((int)v14, infile, infile, &v4->master_player_id, 1);
  rge_read((int)v14, infile, infile, &v4->game_status, 1);
  rge_read((int)v14, infile, infile, &v4->resigned, 1);
  rge_read((int)v14, infile, infile, &table, 1);
  RGE_Player::set_color_table(v4, table);
  rge_read((int)v14, infile, infile, v5, 4);
  rge_read((int)v14, infile, infile, &v4->pathingDelayCapValue, 4);
  v4->checksum_created_this_update = 0;
  v4->checksum = 0;
}
// 570ED0: using guessed type int (__thiscall *RGE_Player::`vftable')(void *Memory, unsigned int __flags);
// 57F9F8: using guessed type int pathingCapValue;
// 58EBCC: using guessed type float save_game_version;

//----- (0046E750) --------------------------------------------------------
RGE_Player *__thiscall RGE_Player::`vector deleting destructor'(RGE_Player *this, unsigned int __flags)
{
  RGE_Player *v2; // esi@1

  v2 = this;
  RGE_Player::~RGE_Player(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0046E770) --------------------------------------------------------
void __thiscall RGE_Player::RGE_Player(RGE_Player *this, RGE_Game_World *gworld, RGE_Master_Player *prototype, char this_id, char *new_name, char m_player_id, char flag)
{
  RGE_Player *v7; // ebp@1
  __int16 v8; // si@1
  __int16 v9; // cx@3
  __int16 v10; // ax@10
  RGE_Master_Static_Object **v11; // eax@11
  __int16 v12; // di@11
  bool v13; // zf@11
  bool v14; // sf@11
  int v15; // esi@12
  RGE_Master_Static_Object *v16; // ecx@12
  RGE_Object_List *v17; // eax@17
  RGE_Object_List *v18; // eax@18
  RGE_Object_List *v19; // eax@20
  RGE_Object_List *v20; // eax@21
  RGE_Object_List *v21; // eax@23
  RGE_Object_List *v22; // eax@24
  RGE_Visible_Map *v23; // eax@26
  RGE_Visible_Map *v24; // eax@27
  RGE_Doppleganger_Creator *v25; // eax@30
  RGE_Doppleganger_Creator *v26; // eax@31
  __int16 v27; // ax@33
  float *v28; // eax@34
  unsigned int v29; // ecx@34
  RGE_Game_World *v30; // edx@36
  RGE_Map *v31; // ecx@36
  float y; // ST04_4@36
  float x; // ST00_4@36
  int v34; // eax@36

  v7 = this;
  v8 = 0;
  this->computerPlayerValue = 0;
  this->pathingAttemptCapValue = 5;
  this->pathingDelayCapValue = 10;
  RGE_Tile_List::RGE_Tile_List(&this->tile_list, 400);
  RGE_Tile_List::RGE_Tile_List(&v7->diam_tile_list, 400);
  v7->vfptr = (RGE_PlayerVtbl *)&RGE_Player::`vftable';
  v7->pathingAttemptCapValue = pathingCapValue;
  v7->master_player_id = m_player_id;
  v7->type = 0;
  v7->world = gworld;
  v7->id = (unsigned __int8)this_id;
  RGE_Player::reset_selected(v7);
  v7->name = 0;
  if ( new_name )
    getstring(&v7->name, new_name);
  v7->relations = (char *)calloc(1u, v7->world->player_num);
  memset(v7->unitDiplomacy, 0xFFu, sizeof(v7->unitDiplomacy));
  v9 = 0;
  if ( v7->world->player_num > 0 )
  {
    do
    {
      v7->relations[v9] = 1;
      if ( v9 == v7->id )
      {
        v7->unitDiplomacy[v9] = 1;
      }
      else if ( v9 )
      {
        v7->unitDiplomacy[v9] = 3;
      }
      else
      {
        v7->unitDiplomacy[0] = 0;
      }
      ++v9;
    }
    while ( v9 < v7->world->player_num );
  }
  v7->mutualExploredMask = 0;
  v7->mutualVisibleMask = 0;
  v7->nonMutualVisibleMask = 0;
  v7->allied_LOS_Enable = 0;
  v7->allied_victory = 0;
  v10 = prototype->master_object_num;
  v7->master_object_num = v10;
  if ( v10 > 0 )
  {
    v11 = (RGE_Master_Static_Object **)calloc(v10, 4u);
    v12 = 0;
    v13 = v7->master_object_num == 0;
    v14 = v7->master_object_num < 0;
    v7->master_objects = v11;
    if ( !v14 && !v13 )
    {
      do
      {
        v15 = v12;
        v16 = prototype->master_objects[v15];
        if ( v16 )
          v7->master_objects[v15] = (RGE_Master_Static_Object *)((int (*)(void))v16->vfptr->make_new_master)();
        ++v12;
      }
      while ( v12 < v7->master_object_num );
      v8 = 0;
    }
  }
  if ( flag )
  {
    v17 = (RGE_Object_List *)operator new(0xCu);
    if ( v17 )
      RGE_Object_List::RGE_Object_List(v17);
    else
      v18 = 0;
    v7->objects = v18;
    v19 = (RGE_Object_List *)operator new(0xCu);
    if ( v19 )
      RGE_Object_List::RGE_Object_List(v19);
    else
      v20 = 0;
    v7->sleeping_objects = v20;
    v21 = (RGE_Object_List *)operator new(0xCu);
    if ( v21 )
      RGE_Object_List::RGE_Object_List(v21);
    else
      v22 = 0;
    v7->doppleganger_objects = v22;
    RGE_Player::new_victory(v7);
    v23 = (RGE_Visible_Map *)operator new(0x38u);
    if ( v23 )
    {
      RGE_Visible_Map::RGE_Visible_Map(v23, gworld->map, v7);
      v7->visible = v24;
    }
    else
    {
      v7->visible = 0;
    }
  }
  else
  {
    v7->objects = 0;
    v7->sleeping_objects = 0;
    v7->doppleganger_objects = 0;
    v7->victory_conditions = 0;
    v7->visible = 0;
  }
  v25 = (RGE_Doppleganger_Creator *)operator new(0x1Cu);
  if ( v25 )
    RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(v25, v7, 100);
  else
    v26 = 0;
  v7->doppleganger_creator = v26;
  v27 = prototype->attribute_num;
  v7->attribute_num = v27;
  if ( v27 <= v8 )
  {
    v7->attributes = 0;
  }
  else
  {
    v28 = (float *)calloc(v27, 4u);
    v29 = 4 * v7->attribute_num;
    v7->attributes = v28;
    qmemcpy(v28, prototype->attributes, v29);
  }
  v30 = v7->world;
  v7->culture = prototype->culture;
  v31 = v30->map;
  y = (double)(v31->map_height / 2);
  x = (double)(v31->map_width / 2);
  RGE_Player::set_view_loc(v7, x, y);
  RGE_Player::set_map_loc(v7, v7->world->map->map_width / 2, v7->world->map->map_height / 2);
  v7->game_status = 0;
  v7->resigned = 0;
  v7->color_table = 0;
  v34 = prototype->tribe_effect;
  v7->tribe_effect = v34;
  if ( flag && v34 >= 0 )
  {
    LOWORD(v34) = v7->tribe_effect;
    ((void (__stdcall *)(int, RGE_Player *))v7->world->effects->vfptr->do_effect)(v34, v7);
  }
  v7->checksum = 0;
  v7->checksum_created_this_update = 0;
}
// 570ED0: using guessed type int (__thiscall *RGE_Player::`vftable')(void *Memory, unsigned int __flags);
// 57F9F8: using guessed type int pathingCapValue;

//----- (0046EB00) --------------------------------------------------------
void __thiscall RGE_Player::~RGE_Player(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  RGE_Object_List *v2; // edi@1
  RGE_Object_List *v3; // edi@3
  RGE_Object_List *v4; // edi@5
  RGE_Victory_Conditions *v5; // edi@7
  __int16 v6; // ax@9
  __int16 v7; // di@10
  RGE_Master_Static_Object *v8; // ecx@11
  RGE_Visible_Map *v9; // edi@15
  RGE_Doppleganger_Creator *v10; // edi@17
  Visible_Resource_Manager *v11; // edi@19

  v1 = this;
  this->vfptr = (RGE_PlayerVtbl *)&RGE_Player::`vftable';
  v2 = this->objects;
  if ( v2 )
  {
    RGE_Object_List::~RGE_Object_List(v2);
    operator delete(v2);
  }
  v3 = v1->sleeping_objects;
  if ( v3 )
  {
    RGE_Object_List::~RGE_Object_List(v1->sleeping_objects);
    operator delete(v3);
  }
  v4 = v1->doppleganger_objects;
  if ( v4 )
  {
    RGE_Object_List::~RGE_Object_List(v1->doppleganger_objects);
    operator delete(v4);
  }
  v5 = v1->victory_conditions;
  if ( v5 )
  {
    RGE_Victory_Conditions::~RGE_Victory_Conditions(v1->victory_conditions);
    operator delete(v5);
  }
  free(v1->relations);
  v6 = v1->master_object_num;
  v1->relations = 0;
  if ( v6 > 0 )
  {
    v7 = 0;
    if ( v6 > 0 )
    {
      do
      {
        v8 = v1->master_objects[v7];
        if ( v8 )
          ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
        ++v7;
      }
      while ( v7 < v1->master_object_num );
    }
    free(v1->master_objects);
    v1->master_objects = 0;
    v1->master_object_num = 0;
  }
  v9 = v1->visible;
  if ( v9 )
  {
    RGE_Visible_Map::~RGE_Visible_Map(v1->visible);
    operator delete(v9);
  }
  v10 = v1->doppleganger_creator;
  if ( v10 )
  {
    RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator(v1->doppleganger_creator);
    operator delete(v10);
  }
  v11 = v1->VR_List;
  if ( v11 )
  {
    Visible_Resource_Manager::~Visible_Resource_Manager(v1->VR_List);
    operator delete(v11);
  }
  if ( v1->name )
  {
    free(v1->name);
    v1->name = 0;
  }
  if ( v1->attribute_num > 0 )
  {
    free(v1->attributes);
    v1->attribute_num = 0;
  }
  RGE_Tile_List::~RGE_Tile_List(&v1->diam_tile_list);
  RGE_Tile_List::~RGE_Tile_List(&v1->tile_list);
}
// 570ED0: using guessed type int (__thiscall *RGE_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (0046ECB0) --------------------------------------------------------
int __stdcall RGE_Player::strategicNumber(int __formal)
{
  return -1;
}

//----- (0046ECC0) --------------------------------------------------------
int __stdcall RGE_Player::sendAICommand(int __formal, int a3, int a4, int a5, int a6)
{
  return 0;
}

//----- (0046ECD0) --------------------------------------------------------
int __stdcall RGE_Player::objectCostByType(int __formal)
{
  return -1;
}

//----- (0046ECE0) --------------------------------------------------------
void __thiscall RGE_Player::set_game_status(RGE_Player *this, char new_status)
{
  char v2; // dl@2

  if ( new_status != this->game_status )
  {
    v2 = this->resigned;
    if ( !v2 || new_status == 2 )
    {
      this->game_status = new_status;
      if ( new_status == 2 && !v2 )
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
          6,
          this->id,
          0,
          0,
          0);
    }
  }
}

//----- (0046ED50) --------------------------------------------------------
void __thiscall RGE_Player::do_resign(RGE_Player *this, int dropped)
{
  RGE_Player *v2; // esi@1
  RGE_PlayerVtbl *v3; // eax@1
  char v4; // bl@1

  v2 = this;
  v3 = this->vfptr;
  v4 = this->resigned;
  this->resigned = 1;
  (*(void (__stdcall **)(signed int))&v3->gap4[0])(2);
  if ( !v4 )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
      5,
      v2->id,
      dropped,
      0,
      0);
}

//----- (0046ED90) --------------------------------------------------------
char __thiscall RGE_Player::get_resigned(RGE_Player *this)
{
  return this->resigned;
}

//----- (0046EDA0) --------------------------------------------------------
char *__stdcall RGE_Player::aiStatus(int sNum)
{
  return 0;
}

//----- (0046EDB0) --------------------------------------------------------
int __thiscall RGE_Player::computerPlayer(RGE_Player *this)
{
  return this->computerPlayerValue;
}

//----- (0046EDC0) --------------------------------------------------------
BOOL __thiscall RGE_Player::isEnemy(RGE_Player *this, int playerNum)
{
  return playerNum != this->id
      && playerNum > 0
      && playerNum < this->world->player_num
      && this->relations[playerNum] == 3;
}

//----- (0046EE00) --------------------------------------------------------
int __thiscall RGE_Player::isAlly(RGE_Player *this, int playerNum)
{
  int result; // eax@2

  if ( playerNum == this->id )
    result = 1;
  else
    result = playerNum > 0 && playerNum < this->world->player_num && !this->relations[playerNum];
  return result;
}

//----- (0046EE40) --------------------------------------------------------
BOOL __thiscall RGE_Player::isNeutral(RGE_Player *this, int playerNum)
{
  return playerNum != this->id
      && playerNum > 0
      && playerNum < this->world->player_num
      && this->relations[playerNum] == 1;
}

//----- (0046EE80) --------------------------------------------------------
int __thiscall RGE_Player::isAllNeutral(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  signed int v2; // edi@1
  int result; // eax@5

  v1 = this;
  v2 = 1;
  if ( this->world->player_num <= 1 )
  {
    result = 1;
  }
  else
  {
    while ( v2 == v1->id || v1->vfptr->isNeutral(v1, v2) )
    {
      if ( ++v2 >= v1->world->player_num )
        return 1;
    }
    result = 0;
  }
  return result;
}

//----- (0046EEF0) --------------------------------------------------------
void __thiscall RGE_Player::sendUnitAIOrder(RGE_Player *this, int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority)
{
  RGE_Command::command_ai_order(
    this->world->commands,
    issuer,
    issuer,
    recipient,
    orderType,
    target,
    targetOwner,
    targetX,
    targetY,
    targetZ,
    range,
    immediate,
    inFront,
    priority);
}

//----- (0046EF40) --------------------------------------------------------
void __thiscall RGE_Player::processAIOrder(RGE_Player *this, int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority)
{
  RGE_Static_Object *v13; // eax@1
  RGE_Static_Object *v14; // esi@1
  UnitAIModule *v15; // eax@3

  v13 = RGE_Game_World::object(this->world, recipient);
  v14 = v13;
  if ( v13 )
  {
    if ( RGE_Static_Object::unitAI(v13) )
    {
      v15 = RGE_Static_Object::unitAI(v14);
      (*(void (__thiscall **)(UnitAIModule *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))&v15->vfptr->gap4[12])(
        v15,
        issuer,
        orderType,
        target,
        targetOwner,
        LODWORD(targetX),
        LODWORD(targetY),
        LODWORD(targetZ),
        LODWORD(range),
        immediate,
        inFront,
        priority);
    }
  }
}

//----- (0046EFB0) --------------------------------------------------------
void __thiscall RGE_Player::sendGameOrder(RGE_Player *this, RGE_Static_Object *unit, RGE_Static_Object *target, float targetX, float targetY)
{
  RGE_Command::command_order(this->world->commands, &unit, 1, target, targetX, targetY);
}

//----- (0046EFE0) --------------------------------------------------------
void __thiscall RGE_Player::sendAddWaypointCommand(RGE_Player *this, int recipient, XYZBYTEPoint *waypoint, int numWaypoints)
{
  RGE_Command::command_add_waypoint(this->world->commands, this->id, recipient, waypoint, numWaypoints);
}

//----- (0046F010) --------------------------------------------------------
void __thiscall RGE_Player::processAddWaypointCommand(RGE_Player *this, int recipient, XYZBYTEPoint *waypoint, int numWaypoints)
{
  RGE_Static_Object *v4; // eax@1
  RGE_Static_Object *v5; // edi@1
  int v6; // ebx@2
  XYZBYTEPoint *v7; // esi@3
  int (__thiscall *v8)(RGE_Static_Object *, XYZBYTEPoint *, int); // ebp@3

  v4 = RGE_Game_World::object(this->world, recipient);
  v5 = v4;
  if ( v4 )
  {
    v6 = numWaypoints;
    if ( numWaypoints > 0 )
    {
      v7 = waypoint;
      v8 = v4->vfptr->addUserDefinedWaypoint;
      do
      {
        v8(v5, v7, 1);
        ++v7;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (0046F050) --------------------------------------------------------
void __thiscall RGE_Player::sendPlayCommand(RGE_Player *this, int recipient, int target, int playID)
{
  RGE_Player *v4; // esi@1
  RGE_PlayerVtbl *v5; // ebp@1
  int v6; // edi@3
  int *v7; // ecx@3
  int v8; // edx@3
  signed int v9; // ebx@3
  int selectedUnits[25]; // [sp+10h] [bp-64h]@3

  v4 = this;
  v5 = this->vfptr;
  ((void (__stdcall *)(int))this->vfptr->command_destroy_group)(recipient);
  if ( AIPlayBook::play(v4->world->playbook, playID) )
  {
    v6 = 0;
    v7 = selectedUnits;
    v8 = (int)v4->sel_list;
    v9 = 25;
    do
    {
      if ( *(_DWORD *)v8 )
      {
        ++v6;
        *v7 = *(_DWORD *)(*(_DWORD *)v8 + 4);
        ++v7;
      }
      v8 += 4;
      --v9;
    }
    while ( v9 );
    if ( v6 )
    {
      ((void (__fastcall *)(RGE_Player *, int, int, int *, int, signed int))v5->command_create_group)(
        v4,
        v8,
        recipient,
        selectedUnits,
        v6,
        0x40000000);
      ((void (__thiscall *)(RGE_Player *, _DWORD, int, signed int, int, int, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v5->sendUnitAIOrder)(
        v4,
        v4->id,
        recipient,
        726,
        target,
        playID,
        -1082130432,
        -1082130432,
        -1082130432,
        -1082130432,
        1,
        0,
        100);
    }
  }
  else
  {
    ((void (__thiscall *)(RGE_Player *, _DWORD, int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v5->sendUnitAIOrder)(
      v4,
      v4->id,
      recipient,
      727,
      -1,
      -1,
      -1082130432,
      -1082130432,
      -1082130432,
      -1082130432,
      1,
      0,
      100);
  }
}

//----- (0046F140) --------------------------------------------------------
void __thiscall RGE_Player::sendPlayCommand(RGE_Player *this, int recipient, int *groupUnits, int groupCount, int target, int playID)
{
  RGE_Player *v6; // esi@1
  RGE_PlayerVtbl *v7; // edi@1

  v6 = this;
  v7 = this->vfptr;
  ((void (__stdcall *)(_DWORD))this->vfptr->command_destroy_group)(recipient);
  if ( AIPlayBook::play(v6->world->playbook, playID) )
  {
    if ( groupCount )
    {
      ((void (__thiscall *)(RGE_Player *, int, int *, int, signed int))v7->command_create_group)(
        v6,
        recipient,
        groupUnits,
        groupCount,
        0x40000000);
      ((void (__thiscall *)(RGE_Player *, _DWORD, int, signed int, int, int, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v7->sendUnitAIOrder)(
        v6,
        v6->id,
        recipient,
        726,
        target,
        playID,
        -1082130432,
        -1082130432,
        -1082130432,
        -1082130432,
        1,
        0,
        100);
    }
  }
  else
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v7->sendUnitAIOrder)(
      v6,
      v6->id,
      recipient,
      727,
      -1,
      -1,
      -1082130432,
      -1082130432,
      -1082130432,
      -1082130432,
      1,
      0,
      100);
  }
}

//----- (0046F200) --------------------------------------------------------
int __thiscall RGE_Player::pathingAttemptCap(RGE_Player *this)
{
  return this->pathingAttemptCapValue;
}

//----- (0046F210) --------------------------------------------------------
void __thiscall RGE_Player::setPathingAttemptCap(RGE_Player *this, int v)
{
  this->pathingAttemptCapValue = v;
}

//----- (0046F220) --------------------------------------------------------
int __thiscall RGE_Player::pathingDelayCap(RGE_Player *this)
{
  return this->pathingDelayCapValue;
}

//----- (0046F230) --------------------------------------------------------
void __thiscall RGE_Player::setPathingDelayCap(RGE_Player *this, int v)
{
  this->pathingDelayCapValue = v;
}

//----- (0046F240) --------------------------------------------------------
int __thiscall RGE_Player::currentUpdatePathingAttempts(RGE_Player *this)
{
  return this->currentUpdatePathingAttemptsValue;
}

//----- (0046F250) --------------------------------------------------------
int __thiscall RGE_Player::availablePathingAttempts(RGE_Player *this, int numWaitDelays)
{
  int v2; // eax@1
  int result; // eax@3
  int v4; // eax@4

  v2 = this->pathingDelayCapValue;
  if ( v2 == -1 || numWaitDelays <= v2 )
  {
    v4 = this->pathingAttemptCapValue;
    if ( v4 == -1 )
      result = 1;
    else
      result = this->currentUpdatePathingAttemptsValue < v4;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0046F290) --------------------------------------------------------
void __thiscall RGE_Player::incrementPathingAttempts(RGE_Player *this)
{
  ++this->currentUpdatePathingAttemptsValue;
}

//----- (0046F2A0) --------------------------------------------------------
void RGE_Player::sendChatMessage(RGE_Player *this, int playerID, int copySelf, char *textIn, ...)
{
  int i; // esi@2
  int j; // esi@8
  int v6; // eax@9
  unsigned int v7; // ecx@9
  char textOut[1025]; // [sp+Ch] [bp-404h]@1
  va_list va; // [sp+424h] [bp+14h]@1

  va_start(va, textIn);
  vsprintf(textOut, textIn, va);
  if ( strlen(textOut) != 0 )
  {
    for ( i = 1; i <= RGE_Base_Game::numberPlayers(rge_base_game); ++i )
    {
      if ( RGE_Base_Game::playerID(rge_base_game, i) == playerID )
        TCommunications_Handler::SendChatMsg(this->world->commands->com_hand, this->id, i, textOut);
    }
    if ( copySelf == 1 && playerID != this->id )
    {
      for ( j = 1; j <= RGE_Base_Game::numberPlayers(rge_base_game); ++j )
      {
        v6 = RGE_Base_Game::playerID(rge_base_game, j);
        v7 = this->id;
        if ( v6 == v7 )
          TCommunications_Handler::SendChatMsg(this->world->commands->com_hand, v7, j, textOut);
      }
    }
  }
}

//----- (0046F3A0) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Player::make_scenario_obj(RGE_Player *this, float world_x, float world_y, float world_z, __int16 master_id, char state, float new_angle)
{
  int v7; // esi@1
  RGE_Master_Static_Object *v8; // eax@1

  v7 = 0;
  v8 = this->master_objects[master_id];
  if ( v8 )
  {
    v7 = ((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))v8->vfptr->make_new_obj)(
           v8,
           this,
           LODWORD(world_x),
           LODWORD(world_y),
           LODWORD(world_z));
    if ( (unsigned __int8)state >= 7u )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 104))(v7);
      return (RGE_Static_Object *)v7;
    }
    if ( (unsigned __int8)state > 2u )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 108))(v7);
      return (RGE_Static_Object *)v7;
    }
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 180))(v7, LODWORD(new_angle));
  }
  return (RGE_Static_Object *)v7;
}

//----- (0046F420) --------------------------------------------------------
void __userpurge RGE_Player::scenario_load(RGE_Player *this@<ecx>, char *a2@<edi>, int infile, int *player_id_hash, float version)
{
  RGE_Player *v5; // esi@1
  int v6; // ebp@2
  int v7; // ebx@6
  int v8; // eax@6
  int v9; // edi@18
  bool v10; // zf@18
  bool v11; // sf@18
  int *v12; // ecx@24
  int v13; // eax@24
  int v14; // eax@26
  RGE_Victory_Conditions *v15; // edi@38
  char temp_byte; // [sp+1h] [bp-9h]@16
  __int16 count; // [sp+2h] [bp-8h]@2
  __int16 player_count; // [sp+4h] [bp-6h]@20
  int has_team; // [sp+6h] [bp-4h]@6

  v5 = this;
  if ( version <= 1.05 )
  {
    v6 = infile;
    rge_read(infile, (int)a2, infile, &count, 2);
    if ( count > 0 )
    {
      a2 = (char *)calloc(count, 1u);
      rge_read(v6, (int)a2, v6, a2, count);
      if ( v5->name )
        free(a2);
      else
        v5->name = a2;
    }
    rge_read(v6, (int)a2, v6, &v5->view_x, 4);
    rge_read(v6, (int)a2, v6, &v5->view_y, 4);
    rge_read(v6, (int)a2, v6, &v5->map_x, 2);
    rge_read(v6, (int)a2, v6, &v5->map_y, 2);
    v7 = 0;
    v8 = rge_base_game->prog_mode;
    has_team = 0;
    if ( v8 != 7 )
    {
      a2 = (char *)1;
      while ( RGE_Base_Game::playerID(rge_base_game, (int)a2) != v5->id
           || TCommunications_Handler::GetPlayerHumanity(comm, (unsigned int)a2) != 2
           && TCommunications_Handler::GetPlayerHumanity(comm, (unsigned int)a2) != 4 )
      {
        if ( (signed int)++a2 >= 9 )
          goto LABEL_15;
      }
      if ( RGE_Base_Game::playerTeam(rge_base_game, (int)--a2) > 1 )
      {
        v7 = 1;
        has_team = 1;
      }
    }
LABEL_15:
    if ( version > 1.0 )
    {
      rge_read(v6, (int)a2, v6, &temp_byte, 1);
      if ( !v7 )
        v5->allied_victory = temp_byte;
    }
    v9 = 0;
    v10 = v5->attribute_num == 0;
    v11 = v5->attribute_num < 0;
    v5->allied_LOS_Enable = 0;
    if ( !v11 && !v10 )
      rge_read(v6, 0, v6, v5->attributes, 116);
    rge_read(v6, 0, v6, &player_count, 2);
    if ( player_count > 0 )
    {
      while ( 1 )
      {
        rge_read(v6, v9, v6, &infile, 1);
        if ( !v7 )
        {
          v12 = &player_id_hash[(signed __int16)v9];
          v13 = *v12;
          if ( *v12 < v5->world->player_num && v13 >= 0 )
          {
            v5->relations[v13] = infile;
            v14 = *v12;
            if ( *v12 )
            {
              if ( (_WORD)v9 == v5->id )
              {
                v5->unitDiplomacy[v14] = 1;
              }
              else if ( (_BYTE)infile )
              {
                if ( (_BYTE)infile == 1 )
                  v5->unitDiplomacy[v14] = 3;
                else
                  v5->unitDiplomacy[v14] = 4;
              }
              else
              {
                v5->unitDiplomacy[v14] = 2;
              }
            }
            else
            {
              v5->unitDiplomacy[0] = 0;
            }
          }
        }
        if ( (signed __int16)++v9 >= player_count )
          break;
        v7 = has_team;
      }
    }
    if ( version > 1.08 )
      rge_read(v6, v9, v6, v5->unitDiplomacy, 36);
    v15 = v5->victory_conditions;
    if ( v15 )
    {
      RGE_Victory_Conditions::~RGE_Victory_Conditions(v5->victory_conditions);
      operator delete(v15);
    }
    v5->vfptr->load_victory(v5, v6, player_id_hash, 0);
  }
}

//----- (0046F6B0) --------------------------------------------------------
void __thiscall RGE_Player::scenario_postsave(RGE_Player *this, int outfile)
{
  RGE_Player *v2; // esi@1
  unsigned int count; // [sp+8h] [bp-4h]@1

  v2 = this;
  count = strlen(this->name) + 1;
  rge_write(outfile, &count, 2);
  rge_write(outfile, v2->name, (signed __int16)count);
  rge_write(outfile, &v2->view_x, 4);
  rge_write(outfile, &v2->view_y, 4);
  rge_write(outfile, &v2->map_x, 2);
  rge_write(outfile, &v2->map_y, 2);
  rge_write(outfile, &v2->allied_victory, 1);
  rge_write(outfile, &v2->world->player_num, 2);
  rge_write(outfile, v2->relations, v2->world->player_num);
  rge_write(outfile, v2->unitDiplomacy, 36);
  ((void (__stdcall *)(int))v2->victory_conditions->vfptr->save)(outfile);
}

//----- (0046F7A0) --------------------------------------------------------
void __userpurge RGE_Player::scenario_postload(RGE_Player *this@<ecx>, char *a2@<edi>, int infile, int *player_id_hash, float version)
{
  int v5; // ebp@1
  RGE_Player *v6; // esi@1
  bool v7; // c0@17
  bool v8; // c3@17
  int v9; // edi@20
  int *v10; // ebx@20
  __int16 v11; // ax@23
  RGE_Victory_Conditions *v12; // edi@39
  char temp_byte; // [sp+13h] [bp-9h]@15
  __int16 count; // [sp+14h] [bp-8h]@1
  __int16 player_count; // [sp+16h] [bp-6h]@20
  int has_team; // [sp+18h] [bp-4h]@5

  v5 = infile;
  v6 = this;
  rge_read(infile, (int)a2, infile, &count, 2);
  if ( count > 0 )
  {
    a2 = (char *)calloc(count, 1u);
    rge_read(v5, (int)a2, v5, a2, count);
    if ( v6->name )
      free(a2);
    else
      v6->name = a2;
  }
  rge_read(v5, (int)a2, v5, &v6->view_x, 4);
  rge_read(v5, (int)a2, v5, &v6->view_y, 4);
  rge_read(v5, (int)a2, v5, &v6->map_x, 2);
  rge_read(v5, (int)a2, v5, &v6->map_y, 2);
  has_team = 0;
  if ( rge_base_game->prog_mode != 7 )
  {
    a2 = (char *)1;
    while ( RGE_Base_Game::playerID(rge_base_game, (int)a2) != v6->id
         || TCommunications_Handler::GetPlayerHumanity(comm, (unsigned int)a2) != 2
         && TCommunications_Handler::GetPlayerHumanity(comm, (unsigned int)a2) != 4 )
    {
      if ( (signed int)++a2 >= 9 )
        goto LABEL_14;
    }
    if ( RGE_Base_Game::playerTeam(rge_base_game, (int)--a2) > 1 )
      has_team = 1;
  }
LABEL_14:
  if ( version > 1.0 )
  {
    rge_read(v5, (int)a2, v5, &temp_byte, 1);
    if ( !has_team )
      v6->allied_victory = temp_byte;
  }
  v7 = version < 1.06;
  v8 = version == 1.06;
  v6->allied_LOS_Enable = 0;
  if ( (v7 || v8) && v6->attribute_num > 0 )
    rge_read(v5, (int)a2, v5, v6->attributes, 116);
  rge_read(v5, (int)a2, v5, &player_count, 2);
  v9 = 0;
  v10 = player_id_hash;
  if ( player_count > 0 )
  {
    do
    {
      rge_read(v5, v9, v5, &infile, 1);
      if ( !has_team )
      {
        v11 = v10 ? LOWORD(v10[(signed __int16)v9]) : (_WORD)v9;
        if ( v11 < v6->world->player_num && v11 >= 0 )
        {
          v6->relations[v11] = infile;
          if ( v11 )
          {
            if ( v11 == v6->id )
            {
              v6->unitDiplomacy[v11] = 1;
            }
            else if ( (_BYTE)infile )
            {
              if ( (_BYTE)infile == 1 )
                v6->unitDiplomacy[v11] = 3;
              else
                v6->unitDiplomacy[v11] = 4;
            }
            else
            {
              v6->unitDiplomacy[v11] = 2;
            }
          }
          else
          {
            v6->unitDiplomacy[0] = 0;
          }
        }
      }
      v10 = player_id_hash;
      ++v9;
    }
    while ( (signed __int16)v9 < player_count );
  }
  if ( version >= 1.08 )
    rge_read(v5, v9, v5, v6->unitDiplomacy, 36);
  v12 = v6->victory_conditions;
  if ( v12 )
  {
    RGE_Victory_Conditions::~RGE_Victory_Conditions(v6->victory_conditions);
    operator delete(v12);
  }
  if ( version < 1.09 )
    v6->vfptr->load_victory(v6, v5, v10, 0);
  else
    v6->vfptr->load_victory(v6, v5, v10, 1);
}

//----- (0046FA60) --------------------------------------------------------
void __userpurge RGE_Player::load(RGE_Player *this@<ecx>, int a2@<edi>, int infile)
{
  int v3; // ebx@1
  RGE_Player *v4; // esi@1
  char *v5; // ebp@1
  int v6; // edi@1
  RGE_Master_Static_Object **v7; // eax@2
  int v8; // ecx@2
  RGE_Visible_Map *v9; // eax@8
  RGE_Visible_Map *v10; // eax@9
  Visible_Resource_Manager *v11; // eax@11
  Visible_Resource_Manager *v12; // eax@12
  RGE_Object_List *v13; // eax@14
  RGE_Object_List *v14; // eax@15
  RGE_Game_World *v15; // ecx@17
  RGE_Object_List *v16; // eax@17
  RGE_Object_List *v17; // eax@18
  RGE_Object_List *v18; // eax@20
  RGE_Object_List *v19; // eax@21
  RGE_Object_List *v20; // ecx@23
  RGE_Game_World *v21; // ST10_4@23

  v3 = infile;
  v4 = this;
  v5 = (char *)&this->master_object_num;
  rge_read((int)&this->master_object_num, a2, infile, &this->master_object_num, 2);
  v6 = 0;
  if ( *(_WORD *)v5 <= 0 )
  {
    v4->master_objects = 0;
  }
  else
  {
    v7 = (RGE_Master_Static_Object **)calloc(*(_WORD *)v5, 4u);
    v8 = *(_WORD *)v5;
    v4->master_objects = v7;
    rge_read((int)v5, 0, v3, v7, 4 * v8);
    if ( *(_WORD *)v5 > 0 )
    {
      do
      {
        if ( v4->master_objects[(signed __int16)v6] )
        {
          rge_read((int)v5, v6, v3, &infile, 1);
          RGE_Player::load_master_object(v4, (int)v5, v3, v6, infile, v4->world->sprites, v4->world->sounds);
        }
        ++v6;
      }
      while ( (signed __int16)v6 < *(_WORD *)v5 );
    }
  }
  v9 = (RGE_Visible_Map *)operator new(0x38u);
  if ( v9 )
    RGE_Visible_Map::RGE_Visible_Map(v9, v6, v3, v4->world);
  else
    v10 = 0;
  v4->visible = v10;
  v11 = (Visible_Resource_Manager *)operator new(0x14u);
  if ( v11 )
    Visible_Resource_Manager::Visible_Resource_Manager(v11, v3, v4);
  else
    v12 = 0;
  v4->VR_List = v12;
  v13 = (RGE_Object_List *)operator new(0xCu);
  if ( v13 )
    RGE_Object_List::RGE_Object_List(v13);
  else
    v14 = 0;
  v15 = v4->world;
  v4->objects = v14;
  RGE_Object_List::load_list(v14, (int)v5, v3, v15);
  v16 = (RGE_Object_List *)operator new(0xCu);
  if ( v16 )
    RGE_Object_List::RGE_Object_List(v16);
  else
    v17 = 0;
  v4->sleeping_objects = v17;
  v18 = (RGE_Object_List *)operator new(0xCu);
  if ( v18 )
    RGE_Object_List::RGE_Object_List(v18);
  else
    v19 = 0;
  v20 = v4->sleeping_objects;
  v21 = v4->world;
  v4->doppleganger_objects = v19;
  RGE_Object_List::load_list(v20, (int)v5, v3, v21);
  if ( save_game_version >= 7.0900002 )
    RGE_Object_List::load_list(v4->doppleganger_objects, (int)v5, v3, v4->world);
}
// 58EBCC: using guessed type float save_game_version;

//----- (0046FC40) --------------------------------------------------------
void __userpurge RGE_Player::load_master_object(RGE_Player *this@<ecx>, int a2@<ebp>, int infile, __int16 index, char type, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Player *v7; // esi@1
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
  switch ( type )
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

//----- (0046FF00) --------------------------------------------------------
void __thiscall RGE_Player::load_info(RGE_Player *this, int infile)
{
  RGE_Player *v2; // esi@1

  v2 = this;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr->load_victory)(infile, 0, 1);
  RGE_Object_List::rehook_list(v2->objects);
  RGE_Object_List::rehook_list(v2->sleeping_objects);
  RGE_Object_List::rehook_list(v2->doppleganger_objects);
}

//----- (0046FF40) --------------------------------------------------------
int __thiscall RGE_Player::get_checksum(RGE_Player *this)
{
  RGE_Player *v1; // esi@1

  v1 = this;
  if ( !this->checksum_created_this_update )
    RGE_Player::create_checksum(this);
  return v1->checksum;
}

//----- (0046FF60) --------------------------------------------------------
char __thiscall RGE_Player::get_checksums(RGE_Player *this, int *new_checksum, int *new_position_checksum, int *new_action_checksum)
{
  RGE_Player *v4; // esi@1
  char result; // al@3

  v4 = this;
  if ( !this->checksum_created_this_update )
    RGE_Player::create_checksum(this);
  *new_checksum = v4->checksum;
  *new_position_checksum = v4->position_checksum;
  result = 1;
  *new_action_checksum = v4->action_checksum;
  return result;
}

//----- (0046FF90) --------------------------------------------------------
int __thiscall RGE_Player::create_checksum(RGE_Player *this)
{
  RGE_Player *v1; // ebx@1
  RGE_Object_List *v2; // eax@1
  int v3; // esi@1
  int v4; // ebp@1
  int v5; // esi@1
  float *v6; // edi@2
  signed __int64 v7; // rax@3
  bool v8; // zf@3
  RGE_Object_Node *i; // edi@4
  int v10; // ebp@5
  int v11; // esi@6
  int num3; // [sp+10h] [bp-18h]@1
  int num1; // [sp+14h] [bp-14h]@1
  float temp_position_checksum; // [sp+18h] [bp-10h]@1
  int v16; // [sp+1Ch] [bp-Ch]@2
  int num2; // [sp+20h] [bp-8h]@1

  v1 = this;
  v2 = this->sleeping_objects;
  v3 = this->id;
  this->checksum_created_this_update = 1;
  this->action_checksum = 0;
  v4 = 0;
  v5 = this->doppleganger_objects->number_of_objects + v2->number_of_objects + v3;
  num1 = 0;
  num2 = 0;
  num3 = 0;
  temp_position_checksum = 0.0;
  if ( this->attribute_num > 0 )
  {
    v6 = this->attributes;
    v16 = this->attribute_num;
    do
    {
      v7 = (signed __int64)*v6;
      ++v6;
      v8 = v16 == 1;
      num1 += v7;
      --v16;
    }
    while ( !v8 );
  }
  for ( i = this->objects->list; i; i = i->next )
  {
    v10 = num2
        + i->node->master_obj->id
        + (unsigned __int64)(signed __int64)i->node->attribute_amount_held
        + i->node->object_state;
    v4 = i->node->vfptr->get_waypoint_checksum(i->node) + v10;
    num2 = v4;
    ++num3;
    temp_position_checksum = i->node->world_z + i->node->world_x + temp_position_checksum + i->node->world_y;
    v1->action_checksum += ((int (*)(void))i->node->vfptr->get_action_checksum)();
  }
  v11 = num1 + ((v4 + ((num3 + (v5 << 8)) << 8)) << 8);
  v1->checksum = v11;
  v1->position_checksum = (signed __int64)temp_position_checksum;
  return v11;
}

//----- (004700B0) --------------------------------------------------------
void __thiscall RGE_Player::new_attribute_num(RGE_Player *this, __int16 attribute, float amount)
{
  if ( attribute >= 0 && attribute < this->attribute_num )
    this->attributes[attribute] = amount;
}

//----- (004700D0) --------------------------------------------------------
void __thiscall RGE_Player::add_attribute_num(RGE_Player *this, __int16 attribute, float amount, char earned)
{
  if ( attribute >= 0 && attribute < this->attribute_num )
    this->attributes[attribute] = amount + this->attributes[attribute];
}

//----- (00470100) --------------------------------------------------------
void __thiscall RGE_Player::make_available(RGE_Player *this, __int16 obj_category, char on_off_flag)
{
  RGE_Master_Static_Object *v3; // ecx@1

  v3 = this->master_objects[obj_category];
  if ( v3 )
    RGE_Master_Static_Object::make_available(v3, on_off_flag);
}

//----- (00470120) --------------------------------------------------------
void __thiscall RGE_Player::update(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  RGE_Object_List *v2; // ecx@3
  Visible_Resource_Manager *v3; // ecx@5

  v1 = this;
  if ( MouseSystem )
    TMousePointer::Poll(MouseSystem);
  v2 = v1->objects;
  v1->currentUpdatePathingAttemptsValue = 0;
  RGE_Object_List::update(v2);
  RGE_Player::update_selected(v1);
  if ( RGE_Victory_Conditions::update(v1->victory_conditions) == 1 )
    (*(void (__thiscall **)(RGE_Player *, signed int))&v1->vfptr->gap4[0])(v1, 2);
  v3 = v1->VR_List;
  v1->checksum_created_this_update = 0;
  if ( v3 )
    Visible_Resource_Manager::Process_New_Tiles(v3, &v1->tile_list);
}

//----- (00470180) --------------------------------------------------------
void __thiscall RGE_Player::update_dopplegangers(RGE_Player *this)
{
  RGE_Player *v1; // esi@1

  v1 = this;
  if ( MouseSystem )
    TMousePointer::Poll(MouseSystem);
  RGE_Object_List::update(v1->doppleganger_objects);
  RGE_Doppleganger_Creator::perform_doppleganger_checks(v1->doppleganger_creator);
}

//----- (004701B0) --------------------------------------------------------
void __thiscall RGE_Player::save(RGE_Player *this, int outfile)
{
  RGE_Player *v2; // esi@1
  __int16 v3; // di@3
  RGE_Color_Table *v4; // eax@5
  char table; // [sp+Fh] [bp-5h]@6
  unsigned int index; // [sp+10h] [bp-4h]@1

  v2 = this;
  color_log(50, 50, 3);
  rge_write(outfile, &v2->type, 1);
  rge_write(outfile, v2->relations, v2->world->player_num);
  rge_write(outfile, v2->unitDiplomacy, 36);
  rge_write(outfile, &v2->allied_LOS_Enable, 4);
  rge_write(outfile, &v2->allied_victory, 1);
  index = strlen(v2->name) + 1;
  rge_write(outfile, &index, 2);
  if ( (signed __int16)index > 0 )
    rge_write(outfile, v2->name, (signed __int16)index);
  rge_write(outfile, &v2->attribute_num, 2);
  v3 = v2->attribute_num;
  if ( v3 > 0 )
    rge_write(outfile, v2->attributes, 4 * v3);
  rge_write(outfile, &v2->view_x, 4);
  rge_write(outfile, &v2->view_y, 4);
  rge_write(outfile, &v2->map_x, 2);
  rge_write(outfile, &v2->map_y, 2);
  rge_write(outfile, &v2->culture, 1);
  rge_write(outfile, &v2->master_player_id, 1);
  rge_write(outfile, &v2->game_status, 1);
  rge_write(outfile, &v2->resigned, 1);
  v4 = v2->color_table;
  if ( v4 )
    table = v4->id;
  else
    table = 0;
  rge_write(outfile, &table, 1);
  rge_write(outfile, &v2->pathingAttemptCapValue, 4);
  rge_write(outfile, &v2->pathingDelayCapValue, 4);
  color_log(50, 95, 3);
}

//----- (00470380) --------------------------------------------------------
void __thiscall RGE_Player::save2(RGE_Player *this, int outfile)
{
  RGE_Player *v2; // esi@1
  int v3; // ebx@1
  __int16 *v4; // ebp@1
  signed int v5; // edi@2
  __int16 v6; // di@4
  RGE_Master_Static_Object *v7; // ecx@5

  v2 = this;
  color_log(76, 76, 4);
  v3 = outfile;
  v4 = &v2->master_object_num;
  rge_write(outfile, &v2->master_object_num, 2);
  if ( v2->master_object_num > 0 )
  {
    v5 = 0;
    if ( v2->master_object_num > 0 )
    {
      do
      {
        outfile = (int)v2->master_objects[v5];
        outfile = outfile != 0;
        rge_write(v3, &outfile, 4);
        ++v5;
      }
      while ( v5 < *v4 );
    }
    v6 = 0;
    if ( *v4 > 0 )
    {
      do
      {
        v7 = v2->master_objects[v6];
        if ( v7 )
          ((void (__stdcall *)(int))v7->vfptr->save)(v3);
        ++v6;
      }
      while ( v6 < *v4 );
    }
  }
  color_log(76, 36, 4);
  RGE_Visible_Map::save(v2->visible, v3);
  Visible_Resource_Manager::save(v2->VR_List, v3);
  color_log(76, 22, 4);
  RGE_Object_List::save(v2->objects, v3);
  color_log(76, 50, 4);
  RGE_Object_List::save(v2->sleeping_objects, v3);
  color_log(76, 50, 4);
  RGE_Object_List::save(v2->doppleganger_objects, v3);
  color_log(76, 95, 4);
}

//----- (00470490) --------------------------------------------------------
void __thiscall RGE_Player::save_info(RGE_Player *this, int outfile)
{
  ((void (__stdcall *)(_DWORD))this->victory_conditions->vfptr->save)(outfile);
}

//----- (004704A0) --------------------------------------------------------
void __thiscall RGE_Player::set_map_loc(RGE_Player *this, __int16 x, __int16 y)
{
  this->map_x = x;
  this->map_y = y;
}

//----- (004704C0) --------------------------------------------------------
void __thiscall RGE_Player::set_view_loc(RGE_Player *this, float x, float y)
{
  double v3; // st7@3
  double v4; // st7@7

  this->view_x = x;
  this->view_y = y;
  if ( x >= 0.0 )
  {
    v3 = (double)(this->world->map->map_width - 1);
    if ( x > v3 )
      this->view_x = v3;
  }
  else
  {
    LODWORD(this->view_x) = 0;
  }
  if ( y >= 0.0 )
  {
    v4 = (double)(this->world->map->map_height - 1);
    if ( y > v4 )
      this->view_y = v4;
  }
  else
  {
    LODWORD(this->view_y) = 0;
  }
}

//----- (00470580) --------------------------------------------------------
void __thiscall RGE_Player::destroy_objects(RGE_Player *this)
{
  RGE_Object_Node *i; // esi@1

  for ( i = this->objects->list; i; i = i->next )
    ((void (*)(void))i->node->vfptr->destroy_obj)();
}

//----- (004705A0) --------------------------------------------------------
void __thiscall RGE_Player::set_color_table(RGE_Player *this, char new_table)
{
  this->color_table = this->world->color_tables[(unsigned __int8)new_table];
}

//----- (004705C0) --------------------------------------------------------
void __thiscall RGE_Player::victory_if_game_on(RGE_Player *this)
{
  if ( !this->game_status )
    (*(void (__stdcall **)(_DWORD))&this->vfptr->gap4[0])(1);
}

//----- (004705E0) --------------------------------------------------------
void __thiscall RGE_Player::loss_if_game_on(RGE_Player *this)
{
  if ( !this->game_status )
    (*(void (__stdcall **)(_DWORD))&this->vfptr->gap4[0])(2);
}

//----- (00470600) --------------------------------------------------------
void __thiscall RGE_Player::win_game_now(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  int i; // edi@1
  RGE_Player *v3; // ecx@6

  v1 = this;
  RGE_Player::victory_if_game_on(this);
  for ( i = 1; i < v1->world->player_num; ++i )
  {
    if ( i != v1->id )
    {
      if ( !v1->allied_victory
        || RGE_Player::relation(v1, i)
        || RGE_Player::relation(v1->world->players[i], v1->id)
        || (v3 = v1->world->players[i], !v3->allied_victory) )
      {
        RGE_Player::loss_if_game_on(v1->world->players[i]);
      }
      else
      {
        RGE_Player::victory_if_game_on(v3);
      }
    }
  }
}

//----- (00470690) --------------------------------------------------------
bool __thiscall RGE_Player::check_victory_conditions(RGE_Player *this)
{
  bool result; // al@2

  if ( this->game_status == 2 )
    result = 1;
  else
    result = RGE_Victory_Conditions::victory_achieved(this->victory_conditions);
  return result;
}

//----- (004706B0) --------------------------------------------------------
char __thiscall RGE_Player::check_ally_group(RGE_Player *this, int *count)
{
  int *v2; // ebp@1
  RGE_Player *v3; // esi@1
  char v4; // bl@1
  RGE_Game_World *v5; // eax@2
  signed int v6; // edi@2
  int *counta; // [sp+14h] [bp+4h]@1

  v2 = count;
  v3 = this;
  v4 = 1;
  counta = (int *)*count;
  if ( this->game_status != 2 )
  {
    *v2 = 0;
    v5 = this->world;
    v6 = 1;
    if ( v5->player_num > 1 )
    {
      while ( v3->relations[v6]
           || !RGE_Player::relation(v5->players[v6], v3->id) && v3->world->players[v6]->allied_victory )
      {
        ++v6;
        ++*v2;
        v5 = v3->world;
        if ( v6 >= v5->player_num )
          goto LABEL_9;
      }
      v4 = 0;
    }
  }
LABEL_9:
  if ( (signed int)counta >= 0 && (int *)*v2 != counta )
    v4 = 0;
  return v4;
}

//----- (00470750) --------------------------------------------------------
char __thiscall RGE_Player::check_victory(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  char v2; // bl@3
  RGE_Game_World *v3; // eax@4
  signed int v4; // edi@4
  RGE_Game_World *v5; // eax@13
  signed int v6; // edi@13
  int count; // [sp+Ch] [bp-4h]@1

  v1 = this;
  count = -1;
  if ( this->game_status != 2 && RGE_Victory_Conditions::victory_achieved(this->victory_conditions) )
  {
    v2 = 0;
    if ( v1->allied_victory )
    {
      v3 = v1->world;
      v4 = 1;
      if ( v3->player_num > 1 )
      {
        while ( v4 != v1->id && v1->relations[v4] || RGE_Player::check_ally_group(v3->players[v4], &count) )
        {
          v3 = v1->world;
          if ( ++v4 >= v3->player_num )
            goto LABEL_11;
        }
        v2 = 1;
      }
LABEL_11:
      if ( v1->allied_victory )
      {
        if ( v2 )
          return v1->game_status;
        v5 = v1->world;
        v6 = 1;
        if ( v5->player_num > 1 )
        {
          while ( v1->relations[v6] || RGE_Player::check_victory_conditions(v5->players[v6]) )
          {
            v5 = v1->world;
            if ( ++v6 >= v5->player_num )
              goto LABEL_19;
          }
          v2 = 1;
        }
      }
    }
LABEL_19:
    if ( !v2 )
    {
      (*(void (__thiscall **)(RGE_Player *, signed int))&v1->vfptr->gap4[0])(v1, 1);
      v1->world->game_end_condition = 2;
    }
  }
  return v1->game_status;
}

//----- (00470840) --------------------------------------------------------
void __thiscall RGE_Player::modify_tobj(RGE_Player *this, __int16 obj_id, __int16 group, float amount, int flag)
{
  RGE_Player *v5; // ebx@1
  unsigned int v6; // edi@2
  RGE_Object_List *v7; // eax@3
  RGE_Object_Node *j; // esi@4
  int v9; // ecx@10
  int v10; // esi@11
  RGE_Master_Static_Object *v11; // eax@11
  RGE_Object_List *v12; // eax@13
  RGE_Object_Node *i; // edi@14
  int obj_ida; // [sp+14h] [bp+4h]@10

  v5 = this;
  if ( obj_id < 0 )
  {
    if ( group >= 0 )
    {
      v9 = 0;
      obj_ida = 0;
      if ( v5->master_object_num > 0 )
      {
        do
        {
          v10 = (signed __int16)v9;
          v11 = v5->master_objects[v10];
          if ( v11 && v11->object_group == group )
          {
            v12 = v5->objects;
            if ( v12 )
            {
              for ( i = v12->list; i; i = i->next )
              {
                if ( i->node->master_obj == v5->master_objects[v10] )
                  ((void (__stdcall *)(_DWORD, int))i->node->vfptr->modify)(LODWORD(amount), flag);
              }
            }
            ((void (__stdcall *)(_DWORD, int))v5->master_objects[v10]->vfptr->modify)(LODWORD(amount), flag);
            v9 = obj_ida;
          }
          obj_ida = ++v9;
        }
        while ( (signed __int16)v9 < v5->master_object_num );
      }
    }
  }
  else
  {
    v6 = obj_id;
    if ( this->master_objects[v6] )
    {
      v7 = this->objects;
      if ( v7 )
      {
        for ( j = v7->list; j; j = j->next )
        {
          if ( j->node->master_obj == v5->master_objects[v6] )
            ((void (__stdcall *)(_DWORD, int))j->node->vfptr->modify)(LODWORD(amount), flag);
        }
      }
      ((void (__stdcall *)(_DWORD, int))v5->master_objects[v6]->vfptr->modify)(LODWORD(amount), flag);
    }
  }
}

//----- (00470940) --------------------------------------------------------
void __thiscall RGE_Player::modify_tobj_delta(RGE_Player *this, __int16 obj_id, __int16 group, float amount, int flag)
{
  RGE_Player *v5; // ebx@1
  unsigned int v6; // edi@2
  RGE_Object_List *v7; // eax@3
  RGE_Object_Node *j; // esi@4
  int v9; // ecx@10
  int v10; // esi@11
  RGE_Master_Static_Object *v11; // eax@11
  RGE_Object_List *v12; // eax@13
  RGE_Object_Node *i; // edi@14
  int obj_ida; // [sp+14h] [bp+4h]@10

  v5 = this;
  if ( obj_id < 0 )
  {
    if ( group >= 0 )
    {
      v9 = 0;
      obj_ida = 0;
      if ( v5->master_object_num > 0 )
      {
        do
        {
          v10 = (signed __int16)v9;
          v11 = v5->master_objects[v10];
          if ( v11 && v11->object_group == group )
          {
            v12 = v5->objects;
            if ( v12 )
            {
              for ( i = v12->list; i; i = i->next )
              {
                if ( i->node->master_obj == v5->master_objects[v10] )
                  ((void (__stdcall *)(_DWORD, int))i->node->vfptr->modify_delta)(LODWORD(amount), flag);
              }
            }
            ((void (__stdcall *)(_DWORD, int))v5->master_objects[v10]->vfptr->modify_delta)(LODWORD(amount), flag);
            v9 = obj_ida;
          }
          obj_ida = ++v9;
        }
        while ( (signed __int16)v9 < v5->master_object_num );
      }
    }
  }
  else
  {
    v6 = obj_id;
    if ( this->master_objects[v6] )
    {
      v7 = this->objects;
      if ( v7 )
      {
        for ( j = v7->list; j; j = j->next )
        {
          if ( j->node->master_obj == v5->master_objects[v6] )
            ((void (__stdcall *)(_DWORD, int))j->node->vfptr->modify_delta)(LODWORD(amount), flag);
        }
      }
      ((void (__stdcall *)(_DWORD, int))v5->master_objects[v6]->vfptr->modify_delta)(LODWORD(amount), flag);
    }
  }
}

//----- (00470A40) --------------------------------------------------------
void __thiscall RGE_Player::modify_tobj_percent(RGE_Player *this, __int16 obj_id, __int16 group, float amount, int flag)
{
  RGE_Player *v5; // ebx@1
  unsigned int v6; // edi@2
  RGE_Object_List *v7; // eax@3
  RGE_Object_Node *j; // esi@4
  int v9; // ecx@10
  int v10; // esi@11
  RGE_Master_Static_Object *v11; // eax@11
  RGE_Object_List *v12; // eax@13
  RGE_Object_Node *i; // edi@14
  int obj_ida; // [sp+14h] [bp+4h]@10

  v5 = this;
  if ( obj_id < 0 )
  {
    if ( group >= 0 )
    {
      v9 = 0;
      obj_ida = 0;
      if ( v5->master_object_num > 0 )
      {
        do
        {
          v10 = (signed __int16)v9;
          v11 = v5->master_objects[v10];
          if ( v11 && v11->object_group == group )
          {
            v12 = v5->objects;
            if ( v12 )
            {
              for ( i = v12->list; i; i = i->next )
              {
                if ( i->node->master_obj == v5->master_objects[v10] )
                  ((void (__stdcall *)(_DWORD, int))i->node->vfptr->modify_percent)(LODWORD(amount), flag);
              }
            }
            ((void (__stdcall *)(_DWORD, int))v5->master_objects[v10]->vfptr->modify_percent)(LODWORD(amount), flag);
            v9 = obj_ida;
          }
          obj_ida = ++v9;
        }
        while ( (signed __int16)v9 < v5->master_object_num );
      }
    }
  }
  else
  {
    v6 = obj_id;
    if ( this->master_objects[v6] )
    {
      v7 = this->objects;
      if ( v7 )
      {
        for ( j = v7->list; j; j = j->next )
        {
          if ( j->node->master_obj == v5->master_objects[v6] )
            ((void (__stdcall *)(_DWORD, int))j->node->vfptr->modify_percent)(LODWORD(amount), flag);
        }
      }
      ((void (__stdcall *)(_DWORD, int))v5->master_objects[v6]->vfptr->modify_percent)(LODWORD(amount), flag);
    }
  }
}

//----- (00470B40) --------------------------------------------------------
void __thiscall RGE_Player::copy_obj(RGE_Player *this, __int16 dest, __int16 source)
{
  RGE_Player *v3; // ebx@1
  RGE_Master_Static_Object **v4; // eax@1
  int v5; // edi@1
  int v6; // ebp@2
  RGE_Object_List *v7; // eax@3
  RGE_Object_Node *i; // esi@4
  RGE_Master_Static_Object **v9; // eax@5

  v3 = this;
  v4 = this->master_objects;
  v5 = dest;
  if ( v4[v5] )
  {
    v6 = source;
    if ( v4[v6] )
    {
      v7 = this->objects;
      if ( v7 )
      {
        for ( i = v7->list; i; i = i->next )
        {
          v9 = v3->master_objects;
          if ( i->node->master_obj == v9[v5] )
            ((void (__stdcall *)(_DWORD))i->node->vfptr->copy_obj)(v9[v6]);
        }
      }
      (*((void (__stdcall **)(_DWORD))&v3->master_objects[v5]->vfptr->__vecDelDtor + 1))(v3->master_objects[v6]);
    }
  }
}

//----- (00470BB0) --------------------------------------------------------
void __thiscall RGE_Player::set_allied_victory(RGE_Player *this, char flag)
{
  this->allied_victory = flag;
}

//----- (00470BC0) --------------------------------------------------------
char __thiscall RGE_Player::get_allied_victory(RGE_Player *this)
{
  return this->allied_victory;
}

//----- (00470BD0) --------------------------------------------------------
char __thiscall RGE_Player::relation(RGE_Player *this, int player_id)
{
  return this->relations[player_id];
}

//----- (00470BE0) --------------------------------------------------------
void __thiscall RGE_Player::set_relation(RGE_Player *this, int player_id, int relation)
{
  RGE_Object_Node *i; // esi@10

  this->relations[player_id] = relation;
  if ( player_id )
  {
    if ( player_id == this->id )
    {
      this->unitDiplomacy[player_id] = 1;
    }
    else if ( (_BYTE)relation )
    {
      if ( (_BYTE)relation == 1 )
        this->unitDiplomacy[player_id] = 3;
      else
        this->unitDiplomacy[player_id] = 4;
    }
    else
    {
      this->unitDiplomacy[player_id] = 2;
    }
  }
  else
  {
    this->unitDiplomacy[0] = 0;
  }
  for ( i = this->objects->list; i; i = i->next )
    ((void (__stdcall *)(int, _DWORD))i->node->vfptr->notify_of_relation)(player_id, relation);
}

//----- (00470C70) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Player::make_new_object(RGE_Player *this, int obj_id, float x, float y, float z, int build_all_the_way)
{
  RGE_Master_Static_Object *v6; // eax@2
  RGE_Static_Object *result; // eax@3

  if ( obj_id >= 0 && (v6 = this->master_objects[obj_id]) != 0 )
    result = (RGE_Static_Object *)((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))v6->vfptr->make_new_obj)(
                                    v6,
                                    this,
                                    LODWORD(x),
                                    LODWORD(y),
                                    LODWORD(z));
  else
    result = 0;
  return result;
}

//----- (00470CB0) --------------------------------------------------------
void __thiscall RGE_Player::reset_selected(RGE_Player *this)
{
  char *v1; // edi@1

  this->selected_start_col = -1;
  this->selected_start_row = -1;
  this->selected_end_col = -1;
  this->selected_end_row = -1;
  this->replacement_terrain = -1;
  this->replacement_overlay = -1;
  this->replacement_overlay_shape = -1;
  this->sel_count = 0;
  this->selected_obj = 0;
  memset(this->sel_list, 0, sizeof(this->sel_list));
  memset(this->groups_used, 0, 0x7Cu);
  v1 = &this->groups_used[124];
  *(_WORD *)v1 = 0;
  v1[2] = 0;
}

//----- (00470D20) --------------------------------------------------------
int __thiscall RGE_Player::select_object(RGE_Player *this, RGE_Static_Object *obj)
{
  RGE_Player *v2; // edi@1
  int result; // eax@1
  char v4; // bl@2
  RGE_Object_Node *i; // esi@3
  RGE_Static_Object *v6; // eax@4

  v2 = this;
  result = RGE_Player::select_one_object(this, obj, 1);
  if ( result )
  {
    v4 = obj->selected_group;
    if ( (unsigned __int8)v4 > 0xAu )
    {
      for ( i = v2->objects->list; i; i = i->next )
      {
        v6 = i->node;
        if ( i->node != obj && v6->selected_group == v4 && !RGE_Player::select_one_object(v2, v6, 0) )
          break;
      }
    }
    v2->selected_obj = obj;
    result = 1;
  }
  return result;
}

//----- (00470D80) --------------------------------------------------------
int __thiscall RGE_Player::select_one_object(RGE_Player *this, RGE_Static_Object *obj, int play_sound)
{
  RGE_Player *v3; // eax@1
  __int16 v4; // dx@1
  __int16 v5; // si@2
  __int16 v6; // cx@4
  RGE_Sound *v7; // ecx@11
  RGE_Player *v8; // edx@12
  int result; // eax@15

  v3 = this;
  v4 = this->sel_count;
  if ( v4 >= 25 )
    goto LABEL_19;
  v5 = -1;
  if ( this->sel_list[v4] )
  {
    v6 = 0;
    if ( v4 > 0 )
    {
      while ( v3->sel_list[v6] )
      {
        if ( ++v6 >= v4 )
          goto LABEL_9;
      }
      v5 = v6;
    }
  }
  else
  {
    v5 = this->sel_count;
  }
LABEL_9:
  if ( v5 == -1 )
  {
LABEL_19:
    result = 0;
  }
  else
  {
    v3->sel_list[v5] = obj;
    ++v3->sel_count;
    v3->selected_obj = obj;
    obj->selected = 1;
    if ( play_sound )
    {
      v7 = obj->master_obj->selected_sound;
      if ( v7 )
      {
        v8 = obj->owner;
        if ( v8 == v3 || !v8->id )
          RGE_Sound::play(v7, 1);
      }
    }
    result = 1;
  }
  return result;
}

//----- (00470E30) --------------------------------------------------------
void __thiscall RGE_Player::unselect_object(RGE_Player *this)
{
  __int16 v1; // si@2
  __int16 v2; // di@2
  RGE_Static_Object *v3; // edx@4

  if ( this->sel_count > 0 )
  {
    v1 = 0;
    this->selected_obj = 0;
    v2 = 0;
    do
    {
      if ( v2 >= this->sel_count )
        break;
      v3 = this->sel_list[v1];
      if ( v3 )
      {
        v3->selected = 0;
        ++v2;
        this->sel_list[v1] = 0;
      }
      ++v1;
    }
    while ( v1 < 25 );
    this->sel_count = 0;
  }
}

//----- (00470E80) --------------------------------------------------------
void __thiscall RGE_Player::unselect_one_object(RGE_Player *this, RGE_Static_Object *obj)
{
  __int16 v2; // di@1
  __int16 v3; // dx@2
  __int16 v4; // si@2
  RGE_Static_Object *v5; // eax@4

  v2 = this->sel_count;
  if ( v2 > 0 )
  {
    v3 = 0;
    v4 = 0;
    while ( v4 < v2 )
    {
      v5 = this->sel_list[v3];
      if ( v5 )
      {
        if ( v5 == obj )
        {
          RGE_Player::unselect_one_object(this, v3);
          return;
        }
        ++v4;
      }
      if ( ++v3 >= 25 )
        return;
    }
  }
}

//----- (00470ED0) --------------------------------------------------------
void __thiscall RGE_Player::unselect_one_object(RGE_Player *this, __int16 index)
{
  RGE_Static_Object *v2; // esi@1
  int v3; // edx@2
  RGE_Static_Object *v4; // edx@5
  __int16 v5; // ax@5
  __int16 v6; // ax@7

  v2 = this->sel_list[index];
  if ( v2 )
  {
    v2->selected = 0;
    v3 = this->sel_count;
    if ( index < v3 - 1 )
    {
      this->sel_list[index] = (RGE_Static_Object *)*((_DWORD *)&this->selected_obj + v3);
      *((_DWORD *)&this->selected_obj + this->sel_count) = 0;
    }
    else
    {
      this->sel_list[index] = 0;
    }
    v4 = this->selected_obj;
    v5 = --this->sel_count;
    if ( v4 == v2 )
    {
      this->selected_obj = 0;
      if ( v5 > 0 )
      {
        v6 = 0;
        while ( !this->sel_list[v6] )
        {
          if ( ++v6 >= 25 )
            return;
        }
        this->selected_obj = this->sel_list[v6];
      }
    }
  }
}

//----- (00470F80) --------------------------------------------------------
int __thiscall RGE_Player::group_objects(RGE_Player *this, int id)
{
  RGE_Player *v2; // edx@1
  signed __int16 v4; // ax@4
  char v5; // bl@7
  RGE_Object_Node *i; // ecx@10
  signed __int16 v7; // ax@15
  RGE_Object_Node *j; // eax@22
  __int16 v9; // si@26
  __int16 v10; // di@26
  RGE_Static_Object *v11; // eax@28
  char ida; // [sp+10h] [bp+4h]@11

  v2 = this;
  if ( !this->sel_count )
    return 0;
  if ( id == -1 )
  {
    v4 = 11;
    while ( this->groups_used[v4] )
    {
      if ( ++v4 >= 127 )
      {
        v5 = -1;
        goto LABEL_9;
      }
    }
    v5 = v4;
    this->groups_used[v4] = 1;
LABEL_9:
    if ( v4 == 127 )
    {
      memset(&this->groups_used[1], 0, 0x7Cu);
      *(_WORD *)&this->groups_used[125] = 0;
      for ( i = this->objects->list; i; i = i->next )
      {
        v5 = i->node->selected_group;
        ida = i->node->selected_group;
        if ( v5 && !v2->groups_used[(unsigned __int8)ida] )
          v2->groups_used[(unsigned __int8)ida] = 1;
      }
      v7 = 1;
      while ( v2->groups_used[v7] )
      {
        if ( ++v7 >= 127 )
          goto LABEL_20;
      }
      v5 = v7;
      v2->groups_used[v7] = 1;
LABEL_20:
      if ( v7 == 127 )
        return 0;
    }
  }
  else
  {
    v5 = id;
    for ( j = this->objects->list; j; j = j->next )
    {
      if ( j->node->selected_group == (_BYTE)id )
        j->node->selected_group = 0;
    }
  }
  v9 = 0;
  v10 = 0;
  do
  {
    if ( v10 >= v2->sel_count )
      break;
    v11 = v2->sel_list[v9];
    if ( v11 )
    {
      if ( v11->owner == v2 )
      {
        ++v10;
        v11->selected_group = v5;
      }
    }
    ++v9;
  }
  while ( v9 < 25 );
  return 1;
}

//----- (004710C0) --------------------------------------------------------
BOOL __thiscall RGE_Player::select_group(RGE_Player *this, int id)
{
  RGE_Player *v2; // edi@1
  signed int v3; // ebp@1
  RGE_Object_Node *i; // esi@1
  RGE_Static_Object *v5; // eax@2

  v2 = this;
  v3 = 1;
  for ( i = this->objects->list; i; i = i->next )
  {
    v5 = i->node;
    if ( i->node->selected_group == (_BYTE)id )
    {
      if ( v3 )
      {
        if ( !RGE_Player::select_one_object(v2, v5, 1) )
          return v3 == 0;
        v3 = 0;
      }
      else if ( !RGE_Player::select_one_object(v2, v5, 0) )
      {
        return v3 == 0;
      }
    }
  }
  return v3 == 0;
}

//----- (00471120) --------------------------------------------------------
int __thiscall RGE_Player::own_selected(RGE_Player *this)
{
  __int16 v1; // dx@1
  __int16 v2; // si@1
  RGE_Static_Object *v3; // eax@3

  v1 = 0;
  v2 = 0;
  while ( v2 < this->sel_count )
  {
    v3 = this->sel_list[v1];
    if ( v3 )
    {
      ++v2;
      if ( v3->owner == this )
        return 1;
    }
    if ( ++v1 >= 25 )
      return 0;
  }
  return 0;
}

//----- (00471170) --------------------------------------------------------
int __thiscall RGE_Player::is_category_selected(RGE_Player *this, __int16 object_category)
{
  __int16 v2; // dx@1
  __int16 v3; // si@1
  RGE_Static_Object *v4; // eax@3

  v2 = 0;
  v3 = 0;
  while ( v3 < this->sel_count )
  {
    v4 = this->sel_list[v2];
    if ( v4 )
    {
      ++v3;
      if ( v4->master_obj->id == object_category )
        return 1;
    }
    if ( ++v2 >= 25 )
      return 0;
  }
  return 0;
}

//----- (004711D0) --------------------------------------------------------
int __thiscall RGE_Player::is_group_selected(RGE_Player *this, __int16 object_group)
{
  __int16 v2; // dx@1
  __int16 v3; // si@1
  RGE_Static_Object *v4; // eax@3

  v2 = 0;
  v3 = 0;
  while ( v3 < this->sel_count )
  {
    v4 = this->sel_list[v2];
    if ( v4 )
    {
      ++v3;
      if ( v4->master_obj->object_group == object_group )
        return 1;
    }
    if ( ++v2 >= 25 )
      return 0;
  }
  return 0;
}

//----- (00471230) --------------------------------------------------------
char __thiscall RGE_Player::unit_level_selected(RGE_Player *this)
{
  char result; // al@1
  __int16 v2; // si@1
  __int16 v3; // di@1
  RGE_Static_Object *v4; // edx@3

  result = 0;
  v2 = 0;
  v3 = 0;
  while ( v3 < this->sel_count )
  {
    v4 = this->sel_list[v2];
    if ( v4 )
    {
      if ( v3 && v4->master_obj->unit_level != result )
        return 0;
      ++v3;
      result = v4->master_obj->unit_level;
    }
    if ( ++v2 >= 25 )
      return result;
  }
  return result;
}

//----- (00471290) --------------------------------------------------------
int __usercall RGE_Player::get_select_level@<eax>(RGE_Player *this@<ecx>, RGE_Static_Object *a2@<eax>)
{
  unsigned __int8 v2; // bl@1
  __int16 v3; // dx@1
  __int16 v4; // si@1
  int select_level; // [sp+Ch] [bp-4h]@0

  v2 = -1;
  v3 = 0;
  v4 = 0;
  do
  {
    if ( v4 >= this->sel_count )
      break;
    a2 = this->sel_list[v3];
    if ( a2 )
    {
      a2 = (RGE_Static_Object *)a2->master_obj;
      LOBYTE(a2) = BYTE1(a2[1].id);
      if ( (unsigned __int8)a2 < v2 )
        v2 = (unsigned __int8)a2;
      ++v4;
    }
    ++v3;
  }
  while ( v3 < 25 );
  LOBYTE(select_level) = v2;
  LOBYTE(a2) = v2 == -1;
  return select_level & (unsigned int)(&a2[-1].underAttackValue + 1);
}

//----- (004712F0) --------------------------------------------------------
char __thiscall RGE_Player::get_selected_objects_to_command(RGE_Player *this, RGE_Static_Object ***list_in, __int16 *list_num_in, int min_select_level, __int16 object_group, __int16 object_id, __int16 unit_level)
{
  RGE_Player *v7; // esi@1
  signed int v8; // ebp@1
  __int16 v9; // bx@1
  __int16 v10; // ax@1
  char result; // al@2
  RGE_Static_Object **v12; // edi@5
  RGE_Static_Object *v13; // edx@7
  RGE_Master_Static_Object *v14; // ecx@10
  char v15; // cl@18
  int v16; // ecx@20
  int j; // [sp+10h] [bp-8h]@5
  RGE_Static_Object **list; // [sp+14h] [bp-4h]@3

  v7 = this;
  v8 = 0;
  *list_in = 0;
  v9 = 0;
  *list_num_in = 0;
  v10 = this->sel_count;
  if ( v10 )
  {
    list = (RGE_Static_Object **)calloc(4u, v10);
    if ( (_WORD)min_select_level == -1 )
      min_select_level = 4;
    j = 0;
    v12 = v7->sel_list;
    do
    {
      if ( j >= v7->sel_count )
        break;
      v13 = *v12;
      if ( *v12 )
      {
        if ( v13->object_state == 2 && v13->owner == v7 )
        {
          v14 = v13->master_obj;
          if ( (v14->select_level >= (signed __int16)min_select_level || !v7->id)
            && (object_group == -1 || v14->object_group == (unsigned __int8)object_group)
            && (object_id == -1 || v14->id == (unsigned __int8)object_id)
            && (unit_level == -1 || v14->unit_level == (_BYTE)unit_level) )
          {
            v15 = v14->master_type;
            if ( (unsigned __int8)v15 >= 0x28u && v15 != 90 )
            {
              v16 = v9++;
              list[v16] = v13;
            }
          }
        }
        ++j;
      }
      ++v8;
      ++v12;
    }
    while ( v8 < 25 );
    if ( v9 )
    {
      *list_in = list;
      *list_num_in = v9;
      result = 1;
    }
    else
    {
      free(list);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00471430) --------------------------------------------------------
void __thiscall RGE_Player::update_selected(RGE_Player *this)
{
  __int16 v1; // si@1
  RGE_Player *v2; // edi@1
  __int16 v3; // bp@1
  RGE_Static_Object *v4; // eax@3

  v1 = 0;
  v2 = this;
  v3 = 0;
  do
  {
    if ( v3 >= v2->sel_count )
      break;
    v4 = v2->sel_list[v1];
    if ( v4 )
    {
      if ( v4->object_state >= 7u || v4->inside_obj )
        RGE_Player::unselect_one_object(v2, v1);
      else
        ++v3;
    }
    ++v1;
  }
  while ( v1 < 25 );
}

//----- (00471480) --------------------------------------------------------
void __thiscall RGE_Player::select_area(RGE_Player *this, __int16 col1, __int16 row1, __int16 col2, __int16 row2)
{
  this->selected_start_col = col1;
  this->selected_start_row = row1;
  this->selected_end_col = col2;
  this->selected_end_row = row2;
}

//----- (004714C0) --------------------------------------------------------
void __thiscall RGE_Player::unselect_area(RGE_Player *this)
{
  this->selected_start_col = -1;
  this->selected_start_row = -1;
  this->selected_end_col = -1;
  this->selected_end_row = -1;
}

//----- (004714E0) --------------------------------------------------------
void __thiscall RGE_Player::ungroup_objects(RGE_Player *this)
{
  signed int v1; // esi@1
  signed int v2; // edi@1
  char *v3; // edx@1

  v1 = 0;
  v2 = 0;
  v3 = (char *)this->sel_list;
  do
  {
    if ( v2 >= this->sel_count )
      break;
    if ( *(_DWORD *)v3 )
    {
      ++v2;
      *(_BYTE *)(*(_DWORD *)v3 + 55) = 0;
    }
    ++v1;
    v3 += 4;
  }
  while ( v1 < 25 );
}

//----- (00471530) --------------------------------------------------------
int __stdcall RGE_Player::get_mouse_pointer_action_vars(int Obj_id, int *newFacet, int *text_id)
{
  *newFacet = 0;
  *text_id = 0;
  return 0;
}

//----- (00471550) --------------------------------------------------------
char __thiscall RGE_Player::command_make_move(RGE_Player *this, RGE_Static_Object *obj, float x, float y)
{
  RGE_Player *v4; // esi@1
  char result; // al@2
  RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
  int list_num; // [sp+8h] [bp-4h]@1

  v4 = this;
  if ( RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&list_num, -1, -1, -1, -1) )
  {
    ((void (*)(void))(*list)->vfptr->play_move_sound)();
    RGE_Command::command_move(v4->world->commands, list, list_num, obj, x, y);
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004715D0) --------------------------------------------------------
char __thiscall RGE_Player::command_make_work(RGE_Player *this, RGE_Static_Object *obj, float x, float y)
{
  RGE_Player *v4; // ebx@1
  int v5; // eax@2
  signed int v6; // edi@5
  void (__thiscall *v7)(RGE_Player *, int, int, int, int, int, float, float, float, float, int, int, int); // ebp@6
  float v8; // ST20_4@7
  char result; // al@8
  RGE_Static_Object **list; // [sp+40h] [bp-8h]@1
  int list_num; // [sp+44h] [bp-4h]@1

  v4 = this;
  if ( RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&list_num, -1, -1, -1, -1) )
  {
    v5 = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*list)->vfptr->get_command_master)(
           obj,
           LODWORD(x),
           LODWORD(y),
           0);
    if ( v5 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 44))(v5);
    RGE_Command::command_work(v4->world->commands, list, list_num, obj, x, y);
    if ( obj )
    {
      v6 = 0;
      if ( (signed __int16)list_num > 0 )
      {
        v7 = v4->vfptr->sendUnitAIOrder;
        do
        {
          v8 = obj->master_obj->los * 0.5;
          ((void (__thiscall *)(RGE_Player *, _DWORD, int, signed int, int, _DWORD, _DWORD, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int))v7)(
            v4,
            v4->id,
            list[v6++]->id,
            701,
            obj->id,
            obj->owner->id,
            LODWORD(obj->world_x),
            LODWORD(obj->world_y),
            1065353216,
            LODWORD(v8),
            0,
            0,
            100);
        }
        while ( v6 < (signed __int16)list_num );
      }
    }
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004716D0) --------------------------------------------------------
char __thiscall RGE_Player::command_make_do(RGE_Player *this, RGE_Static_Object *obj, float x, float y)
{
  RGE_Player *v4; // ebp@1
  int v5; // eax@2
  char result; // al@4
  RGE_Static_Object **list; // [sp+10h] [bp-8h]@1
  int list_num; // [sp+14h] [bp-4h]@1

  v4 = this;
  if ( RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&list_num, -1, -1, -1, -1) )
  {
    v5 = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*list)->vfptr->get_command_master)(
           obj,
           LODWORD(x),
           LODWORD(y),
           0);
    if ( v5 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 44))(v5);
    RGE_Command::command_order(v4->world->commands, list, list_num, obj, x, y);
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00471760) --------------------------------------------------------
char __thiscall RGE_Player::command_stop(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  char result; // al@2
  RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
  int list_num; // [sp+8h] [bp-4h]@1

  v1 = this;
  if ( RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&list_num, 3, -1, -1, -1) )
  {
    ((void (*)(void))(*list)->vfptr->play_command_sound)();
    RGE_Command::command_stop(v1->world->commands, list, list_num);
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004717D0) --------------------------------------------------------
char __thiscall RGE_Player::command_place_object(RGE_Player *this, __int16 obj_id, float x, float y, float z)
{
  char result; // al@3

  if ( obj_id != -1 && this->master_objects[obj_id] )
  {
    RGE_Command::command_create(this->world->commands, obj_id, this->id, x, y, z);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00471820) --------------------------------------------------------
char __thiscall RGE_Player::command_add_attribute(RGE_Player *this, int attr_id, float attr_amount)
{
  char result; // al@3

  if ( attr_id == -1 || attr_amount == 0.0 )
  {
    result = 0;
  }
  else
  {
    RGE_Command::command_add_attribute(this->world->commands, this->id, attr_id, attr_amount);
    result = 1;
  }
  return result;
}

//----- (00471860) --------------------------------------------------------
char __thiscall RGE_Player::command_give_attribute(RGE_Player *this, int to_player_id, int attr_id, float attr_amount)
{
  char result; // al@4

  if ( attr_id == -1 || attr_amount == 0.0 || attr_amount > (double)this->attributes[attr_id] )
  {
    result = 0;
  }
  else
  {
    ((void (__thiscall *)(RGE_Command *, _DWORD, int, int, _DWORD))this->world->commands->vfptr->command_give_attribute)(
      this->world->commands,
      this->id,
      to_player_id,
      attr_id,
      LODWORD(attr_amount));
    result = 1;
  }
  return result;
}

//----- (004718C0) --------------------------------------------------------
char __thiscall RGE_Player::command_formation(RGE_Player *this, int formationID)
{
  int v2; // edi@1
  RGE_Player *v3; // esi@1
  char result; // al@4
  RGE_Static_Object **list; // [sp+8h] [bp-4h]@3

  v2 = formationID;
  v3 = this;
  if ( formationID >= 0
    && formationID <= 5
    && RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&formationID, -1, -1, -1, -1) )
  {
    ((void (*)(void))(*list)->vfptr->play_command_sound)();
    RGE_Command::command_formation(v3->world->commands, list, (signed __int16)formationID, v2);
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00471940) --------------------------------------------------------
char __thiscall RGE_Player::command_stand_ground(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  char result; // al@2
  RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
  int listNum; // [sp+8h] [bp-4h]@1

  v1 = this;
  if ( RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&listNum, -1, -1, -1, -1) )
  {
    ((void (*)(void))(*list)->vfptr->play_command_sound)();
    RGE_Command::command_group_ai_order(
      v1->world->commands,
      v1->id,
      v1->id,
      list,
      listNum,
      725,
      -1,
      -1,
      -1.0,
      -1.0,
      -1.0,
      1.0,
      1,
      0,
      100);
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004719D0) --------------------------------------------------------
char __thiscall RGE_Player::command_create_group(RGE_Player *this, int commander, int *groupList, int groupLength, float range)
{
  RGE_Command::command_create_group(this->world->commands, this->id, commander, groupList, groupLength, range);
  return 1;
}

//----- (00471A00) --------------------------------------------------------
char __thiscall RGE_Player::command_add_to_group(RGE_Player *this, int commander, int unitID, float range)
{
  RGE_Command::command_add_to_group(this->world->commands, this->id, commander, unitID, range);
  return 1;
}

//----- (00471A30) --------------------------------------------------------
char __thiscall RGE_Player::command_remove_from_group(RGE_Player *this, int commander, int unitID)
{
  RGE_Command::command_remove_from_group(this->world->commands, this->id, commander, unitID);
  return 1;
}

//----- (00471A50) --------------------------------------------------------
char __thiscall RGE_Player::command_destroy_group(RGE_Player *this, int unitID)
{
  RGE_Command::command_destroy_group(this->world->commands, this->id, unitID);
  return 1;
}

//----- (00471A70) --------------------------------------------------------
char __thiscall RGE_Player::command_resign(RGE_Player *this, int comm_player_id, int dropped)
{
  char result; // al@2

  if ( this->game_status )
  {
    result = 0;
  }
  else
  {
    RGE_Command::command_resign(this->world->commands, this->id, comm_player_id, dropped);
    result = 1;
  }
  return result;
}

//----- (00471AA0) --------------------------------------------------------
char __thiscall RGE_Player::command_add_waypoint(RGE_Player *this, float x, float y, float z)
{
  RGE_Player *v4; // esi@1
  char result; // al@2
  RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
  int list_num; // [sp+8h] [bp-4h]@1

  v4 = this;
  if ( RGE_Player::get_selected_objects_to_command(this, &list, (__int16 *)&list_num, -1, -1, -1, -1) )
  {
    ((void (*)(void))(*list)->vfptr->play_command_sound)();
    RGE_Command::command_group_waypoint(v4->world->commands, list, list_num, (signed __int64)x, (signed __int64)y);
    free(list);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00471B20) --------------------------------------------------------
RGE_Object_Node *__thiscall RGE_Player::addObject(RGE_Player *this, RGE_Static_Object *obj, int sleep_flag, int dopple_flag)
{
  RGE_Player *v4; // esi@1
  RGE_Static_Object *v5; // edi@2
  RGE_Object_List *v6; // ecx@4
  RGE_Object_Node *v7; // eax@2
  RGE_Object_Node *v8; // ebx@7

  v4 = this;
  if ( sleep_flag )
  {
    v5 = obj;
    v7 = RGE_Object_List::add_node(this->sleeping_objects, obj);
  }
  else
  {
    v5 = obj;
    if ( dopple_flag )
      v6 = this->doppleganger_objects;
    else
      v6 = this->objects;
    v7 = RGE_Object_List::add_node(v6, obj);
  }
  v8 = v7;
  ((void (__stdcall *)(RGE_Static_Object *))v4->world->vfptr->addObject)(v5);
  return v8;
}

//----- (00471B70) --------------------------------------------------------
void __thiscall RGE_Player::removeObject(RGE_Player *this, RGE_Static_Object *obj, int sleep_flag, int dopple_flag, RGE_Object_Node *node)
{
  RGE_Player *v5; // esi@1
  RGE_Static_Object *v6; // edi@2

  v5 = this;
  if ( sleep_flag )
  {
    v6 = obj;
    RGE_Object_List::remove_node(this->sleeping_objects, obj, node);
  }
  else if ( dopple_flag )
  {
    v6 = obj;
    RGE_Object_List::remove_node(this->doppleganger_objects, obj, node);
  }
  else
  {
    v6 = obj;
    RGE_Object_List::remove_node(this->objects, obj, node);
  }
  ((void (__stdcall *)(_DWORD))v5->world->vfptr->removeObject)(v6->id);
}

//----- (00471BF0) --------------------------------------------------------
void __thiscall RGE_Player::set_map_visible(RGE_Player *this)
{
  RGE_Visible_Map::set_all(this->visible, 1);
}

//----- (00471C00) --------------------------------------------------------
void __thiscall RGE_Player::remake_visible_map(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  RGE_Visible_Map *v2; // edi@1
  RGE_Visible_Map *v3; // eax@3
  RGE_Visible_Map *v4; // eax@4

  v1 = this;
  v2 = this->visible;
  if ( v2 )
  {
    RGE_Visible_Map::~RGE_Visible_Map(this->visible);
    operator delete(v2);
  }
  v3 = (RGE_Visible_Map *)operator new(0x38u);
  if ( v3 )
  {
    RGE_Visible_Map::RGE_Visible_Map(v3, v1->world->map, v1);
    v1->visible = v4;
  }
  else
  {
    v1->visible = 0;
  }
}

//----- (00471C90) --------------------------------------------------------
void __userpurge RGE_Player::load_victory(RGE_Player *this@<ecx>, int a2@<ebp>, int a3@<edi>, int infile, int *player_id_hash, char version_control)
{
  RGE_Player *v6; // esi@1
  RGE_Victory_Conditions *v7; // eax@1
  RGE_Victory_Conditions *v8; // eax@2

  v6 = this;
  v7 = (RGE_Victory_Conditions *)operator new(0x20u);
  if ( v7 )
    RGE_Victory_Conditions::RGE_Victory_Conditions(v7, a2, a3, v6, infile, player_id_hash, version_control);
  else
    v8 = 0;
  v6->victory_conditions = v8;
}

//----- (00471D00) --------------------------------------------------------
void __thiscall RGE_Player::new_victory(RGE_Player *this)
{
  RGE_Player *v1; // esi@1
  RGE_Victory_Conditions *v2; // eax@1
  RGE_Victory_Conditions *v3; // eax@2

  v1 = this;
  v2 = (RGE_Victory_Conditions *)operator new(0x20u);
  if ( v2 )
  {
    RGE_Victory_Conditions::RGE_Victory_Conditions(v2, v1);
    v1->victory_conditions = v3;
  }
  else
  {
    v1->victory_conditions = 0;
  }
}

//----- (00471D70) --------------------------------------------------------
void __thiscall RGE_Tile_List::add_node(RGE_Tile_List *this, int col, int row)
{
  RGE_Tile_List *v3; // ebx@1
  RGE_Tile_List_Node *v4; // ebp@2
  int v5; // ecx@2
  int v6; // eax@3

  v3 = this;
  if ( this->num_active >= this->list_size )
  {
    v4 = (RGE_Tile_List_Node *)calloc(2 * this->list_size, 8u);
    qmemcpy(v4, v3->list, 8 * v3->list_size);
    free(v3->list);
    v5 = v3->list_size;
    v3->list = v4;
    v3->list_size = 2 * v5;
  }
  v3->list[v3->num_active].col = col;
  v3->list[v3->num_active].row = row;
  v6 = v3->new_count + 1;
  ++v3->num_active;
  v3->new_count = v6;
}

//----- (00471DF0) --------------------------------------------------------
void __thiscall RGE_Tile_List::del_list(RGE_Tile_List *this)
{
  RGE_Tile_List *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = this->collapse_list;
  this->num_active = 0;
  this->new_count = 0;
  if ( v2 )
  {
    free(this->list);
    v1->list_size = 8;
    v1->list = (RGE_Tile_List_Node *)calloc(8u, 8u);
    v1->collapse_list = 0;
  }
}

//----- (00471E40) --------------------------------------------------------
void __thiscall RGE_Tile_List::RGE_Tile_List(RGE_Tile_List *this, int Initial_Size)
{
  RGE_Tile_List *v2; // esi@1

  v2 = this;
  this->list = (RGE_Tile_List_Node *)calloc(Initial_Size, 8u);
  v2->list_size = Initial_Size;
  v2->num_active = 0;
  v2->new_count = 0;
  v2->collapse_list = 0;
}

//----- (00471E70) --------------------------------------------------------
void __thiscall RGE_Tile_List::~RGE_Tile_List(RGE_Tile_List *this)
{
  if ( this->list )
    free(this->list);
}

//----- (00471E90) --------------------------------------------------------
void __thiscall RGE_Tile_List::get_list_info(RGE_Tile_List *this, RGE_Tile_List_Node **theList, int *list_size)
{
  *theList = this->list;
  *list_size = this->num_active;
}

//----- (00471EB0) --------------------------------------------------------
int __thiscall RGE_Tile_List::get_new_count(RGE_Tile_List *this)
{
  int result; // eax@1

  result = this->new_count;
  this->new_count = 0;
  return result;
}