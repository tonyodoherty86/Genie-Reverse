
//----- (0045C450) --------------------------------------------------------
void __thiscall RGE_Moving_Object::RGE_Moving_Object(RGE_Moving_Object *this, RGE_Master_Moving_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  RGE_Moving_Object *v7; // esi@1

  v7 = this;
  RGE_Animated_Object::RGE_Animated_Object(
    (RGE_Animated_Object *)&this->vfptr,
    (RGE_Master_Animated_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z,
    0);
  Path::Path(&v7->pathValue, 10);
  Path::Path(&v7->exceptionPathValue, 10);
  v7->rangeStatusValue = 2;
  v7->currentTerrainException1 = -1;
  v7->currentTerrainException2 = -1;
  v7->storePathInExceptionPath = 0;
  v7->waitingToMoveValue = 0;
  v7->numberWaitDelays = 0;
  v7->userDefinedWaypoints = 0;
  v7->numberUserDefinedWaypointsValue = 0;
  v7->maxUserDefinedWaypointsValue = 0;
  v7->finalUserDefinedWaypoint = 0;
  v7->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Moving_Object::`vftable';
  LODWORD(v7->startValue.x) = 0;
  LODWORD(v7->startValue.y) = 0;
  LODWORD(v7->startValue.z) = 0;
  RGE_Moving_Object::setGoal(v7, 0.0, 0.0, 0.0);
  LODWORD(v7->turnTimer) = 0;
  v7->lastFacet = -1;
  v7->lastFacet2 = -1;
  LODWORD(v7->collisionAvoidanceDistance) = 0;
  LODWORD(v7->actionRange) = 0;
  v7->targetIDValue = -1;
  LODWORD(v7->targetRadiusX) = 0;
  LODWORD(v7->targetRadiusY) = 0;
  v7->continueCounter = 0;
  LODWORD(v7->closestDistanceToWaypoint) = 1203982336;
  if( do_setup )
    RGE_Moving_Object::setup(v7, tobj, obj_owner, x, y, z);
}
// 570948: using guessed type int (__thiscall *RGE_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0045C5A0) --------------------------------------------------------
RGE_Moving_Object *__thiscall RGE_Moving_Object::`vector deleting destructor'(RGE_Moving_Object *this, unsigned int __flags)
{
  RGE_Moving_Object *v2; // esi@1

  v2 = this;
  RGE_Moving_Object::~RGE_Moving_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0045C5C0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::RGE_Moving_Object(RGE_Moving_Object *this, int infile, RGE_Game_World *gworld, int do_setup)
{
  RGE_Moving_Object *v4; // esi@1

  v4 = this;
  RGE_Animated_Object::RGE_Animated_Object((RGE_Animated_Object *)&this->vfptr, (int)gworld, infile, gworld, 0);
  Path::Path(&v4->pathValue, 10);
  Path::Path(&v4->exceptionPathValue, 10);
  v4->rangeStatusValue = 2;
  v4->currentTerrainException1 = -1;
  v4->currentTerrainException2 = -1;
  v4->storePathInExceptionPath = 0;
  v4->waitingToMoveValue = 0;
  v4->numberWaitDelays = 0;
  v4->userDefinedWaypoints = 0;
  v4->numberUserDefinedWaypointsValue = 0;
  v4->maxUserDefinedWaypointsValue = 0;
  v4->finalUserDefinedWaypoint = 0;
  v4->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Moving_Object::`vftable';
  LODWORD(v4->startValue.x) = 0;
  LODWORD(v4->startValue.y) = 0;
  LODWORD(v4->startValue.z) = 0;
  RGE_Moving_Object::setGoal(v4, 0.0, 0.0, 0.0);
  LODWORD(v4->turnTimer) = 0;
  v4->lastFacet = -1;
  v4->lastFacet2 = -1;
  LODWORD(v4->collisionAvoidanceDistance) = 0;
  LODWORD(v4->actionRange) = 0;
  v4->targetIDValue = -1;
  LODWORD(v4->targetRadiusX) = 0;
  LODWORD(v4->targetRadiusY) = 0;
  v4->continueCounter = 0;
  LODWORD(v4->closestDistanceToWaypoint) = 1203982336;
  if( do_setup )
    RGE_Moving_Object::setup(v4, (int)gworld, infile, gworld);
}
// 570948: using guessed type int (__thiscall *RGE_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0045C700) --------------------------------------------------------
void __thiscall RGE_Moving_Object::~RGE_Moving_Object(RGE_Moving_Object *this)
{
  RGE_Moving_Object *v1; // esi@1
  XYZBYTEPoint *v2; // eax@1

  v1 = this;
  this->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Moving_Object::`vftable';
  v2 = this->userDefinedWaypoints;
  if( v2 )
  {
    operator delete(v2);
    v1->userDefinedWaypoints = 0;
  }
  Path::~Path(&v1->exceptionPathValue);
  Path::~Path(&v1->pathValue);
  RGE_Static_Object::~RGE_Static_Object((RGE_Static_Object *)&v1->vfptr);
}
// 570948: using guessed type int (__thiscall *RGE_Moving_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0045C790) --------------------------------------------------------
void __thiscall RGE_Moving_Object::recycle_in_to_game(RGE_Moving_Object *this, RGE_Master_Static_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Moving_Object *v6; // esi@1
  RGE_Sprite *v7; // eax@1
  int v8; // edi@4
  double v9; // st7@4
  Path p; // [sp+Ch] [bp-40h]@1
  int v11; // [sp+48h] [bp-4h]@1
  float ya; // [sp+5Ch] [bp+10h]@4

  v6 = this;
  Path::Path(&p, 10);
  v11 = 0;
  Path::operator=(&v6->pathValue, &p);
  v11 = -1;
  Path::~Path(&p);
  v6->rangeStatusValue = 2;
  v6->currentTerrainException1 = -1;
  v6->currentTerrainException2 = -1;
  v6->storePathInExceptionPath = 0;
  v6->waitingToMoveValue = 0;
  v6->numberWaitDelays = 0;
  LODWORD(v6->startValue.x) = 0;
  LODWORD(v6->startValue.y) = 0;
  LODWORD(v6->startValue.z) = 0;
  RGE_Moving_Object::setGoal(v6, 0.0, 0.0, 0.0);
  v6->lastFacet = -1;
  v6->lastFacet2 = -1;
  LODWORD(v6->turnTimer) = 0;
  LODWORD(v6->collisionAvoidanceDistance) = 0;
  LODWORD(v6->actionRange) = 0;
  v6->targetIDValue = -1;
  LODWORD(v6->targetRadiusX) = 0;
  LODWORD(v6->targetRadiusY) = 0;
  v6->continueCounter = 0;
  LODWORD(v6->closestDistanceToWaypoint) = 1203982336;
  RGE_Animated_Object::recycle_in_to_game((RGE_Animated_Object *)&v6->vfptr, tobj, obj_owner, x, y, z);
  v7 = v6->sprite;
  LODWORD(v6->velocity_x) = 0;
  LODWORD(v6->velocity_y) = 0;
  LODWORD(v6->velocity_z) = 0;
  LODWORD(v6->angle) = 0;
  LODWORD(v6->turn_towards_time) = 0;
  LODWORD(v6->trail_remainder) = 0;
  if( v7 && v7->flag & 2 && v7->facet_num > 1 )
  {
    v8 = v7->facet_num;
    LODWORD(ya) = v7->facet_num;
    v9 = (double)(v8 * debug_rand(aCMsdevWorkA_24, 197) / 0x7FFF) * (6.2831853 / (double)SLODWORD(ya));
    v6->angle = v9;
    if( v9 >= 0.0 )
    {
      if( v9 > 6.2831855 )
        v6->angle = v9 - 6.2831855;
    }
    else
    {
      v6->angle = v9 - -6.2831855;
    }
  }
  RGE_Moving_Object::set_angle(v6);
}

//----- (0045C970) --------------------------------------------------------
int __thiscall RGE_Moving_Object::setup(RGE_Moving_Object *this, RGE_Master_Moving_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Moving_Object *v6; // esi@1
  RGE_Sprite *v7; // ecx@1
  int v8; // edi@4
  double v9; // st7@4
  int result; // eax@5
  float ya; // [sp+18h] [bp+10h]@4

  v6 = this;
  RGE_Animated_Object::setup(
    (RGE_Animated_Object *)&this->vfptr,
    (RGE_Master_Animated_Object *)&tobj->vfptr,
    obj_owner,
    x,
    y,
    z);
  v7 = v6->sprite;
  v6->type = 30;
  LODWORD(v6->velocity_x) = 0;
  LODWORD(v6->velocity_y) = 0;
  LODWORD(v6->velocity_z) = 0;
  LODWORD(v6->angle) = 0;
  LODWORD(v6->turn_towards_time) = 0;
  LODWORD(v6->trail_remainder) = 0;
  if( !v7 || !(v7->flag & 2) || v7->facet_num <= 1 )
    goto LABEL_11;
  v8 = v7->facet_num;
  LODWORD(ya) = v7->facet_num;
  v9 = (double)(v8 * debug_rand(aCMsdevWorkA_24, 222) / 0x7FFF) * (6.2831853 / (double)SLODWORD(ya));
  v6->angle = v9;
  if( v9 < 0.0 )
  {
    v6->angle = v9 - -6.2831855;
    RGE_Moving_Object::set_angle(v6);
    return 1;
  }
  if( v9 > 6.2831855 )
  {
    v6->angle = v9 - 6.2831855;
    RGE_Moving_Object::set_angle(v6);
    result = 1;
  }
  else
  {
LABEL_11:
    RGE_Moving_Object::set_angle(v6);
    result = 1;
  }
  return result;
}

//----- (0045CAA0) --------------------------------------------------------
int __userpurge RGE_Moving_Object::setup@<eax>(RGE_Moving_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  int v4; // edi@1
  RGE_Moving_Object *v5; // esi@1
  int v6; // ebx@1
  Waypoint v7; // ST00_16@3
  int v8; // ebp@4
  int v9; // ebx@4
  int *v10; // ebp@6
  int v11; // ebx@6
  bool v12; // sf@8
  unsigned __int8 v13; // of@8
  int result; // eax@16
  int currentWaypoint; // [sp+10h] [bp-14h]@4
  Waypoint temp; // [sp+14h] [bp-10h]@3

  v4 = infile;
  v5 = this;
  RGE_Animated_Object::setup((RGE_Animated_Object *)&this->vfptr, a2, infile, gworld);
  v5->type = 30;
  rge_read(a2, v4, v4, &v5->trail_remainder, 4);
  rge_read(a2, v4, v4, &v5->velocity_x, 4);
  rge_read(a2, v4, v4, &v5->velocity_y, 4);
  rge_read(a2, v4, v4, &v5->velocity_z, 4);
  rge_read(a2, v4, v4, &v5->angle, 4);
  rge_read(a2, v4, v4, &v5->turn_towards_time, 4);
  rge_read(a2, v4, v4, &infile, 4);
  v6 = 0;
  if( infile > 0 )
  {
    a2 = (int)&v5->pathValue;
    do
    {
      rge_read(a2, v4, v4, &temp, 16);
      *(_QWORD *)&v7.x = *(_QWORD *)&temp.x;
      *(_QWORD *)&v7.z = *(_QWORD *)&temp.z;
      Path::insertAtEnd(&v5->pathValue, v7);
      ++v6;
    }
    while( v6 < infile );
  }
  rge_read(a2, v4, v4, &currentWaypoint, 4);
  v8 = (int)&v5->pathValue;
  v9 = 0;
  Path::initToStart(&v5->pathValue);
  if( currentWaypoint > 0 )
  {
    do
    {
      Path::moveToNextWaypoint(&v5->pathValue);
      ++v9;
    }
    while( v9 < currentWaypoint );
  }
  rge_read(v8, v4, v4, &v5->startValue, 16);
  rge_read(v8, v4, v4, &v5->goalValue, 16);
  rge_read(v8, v4, v4, &v5->turnTimer, 4);
  rge_read(v8, v4, v4, &v5->collisionAvoidanceDistance, 4);
  rge_read(v8, v4, v4, &v5->actionRange, 4);
  rge_read(v8, v4, v4, &v5->targetIDValue, 4);
  rge_read(v8, v4, v4, &v5->targetRadiusX, 4);
  rge_read(v8, v4, v4, &v5->targetRadiusY, 4);
  rge_read(v8, v4, v4, &v5->continueCounter, 4);
  rge_read(v8, v4, v4, &v5->rangeStatusValue, 4);
  rge_read(v8, v4, v4, &v5->waitingToMoveValue, 1);
  rge_read(v8, v4, v4, &v5->numberWaitDelays, 1);
  v10 = &v5->numberUserDefinedWaypointsValue;
  rge_read((int)&v5->numberUserDefinedWaypointsValue, v4, v4, &v5->numberUserDefinedWaypointsValue, 4);
  rge_read((int)&v5->numberUserDefinedWaypointsValue, v4, v4, &v5->maxUserDefinedWaypointsValue, 4);
  v5->userDefinedWaypoints = (XYZBYTEPoint *)operator new(3 * v5->maxUserDefinedWaypointsValue);
  v11 = 0;
  if( v5->numberUserDefinedWaypointsValue > 0 )
  {
    gworld = 0;
    do
    {
      rge_read((int)v10, v4, v4, (char *)v5->userDefinedWaypoints + (unsigned int)gworld, 3);
      v13 = __OFSUB__(++v11, *v10);
      v12 = v11 - *v10 < 0;
      gworld = (RGE_Game_World *)((char *)gworld + 3);
    }
    while( v12 ^ v13 );
  }
  rge_read((int)v10, v4, v4, &v5->finalUserDefinedWaypoint, 1);
  if( save_game_version < 1.3 )
  {
    v5->minInitialPointValue.x = -1;
    v5->minInitialPointValue.y = -1;
    v5->maxInitialPointValue.x = -1;
    v5->maxInitialPointValue.y = -1;
  }
  else
  {
    rge_read((int)v10, v4, v4, &v5->minInitialPointValue, 8);
    rge_read((int)v10, v4, v4, &v5->maxInitialPointValue, 8);
  }
  if( save_game_version < 7.2199998 )
  {
    LODWORD(v5->closestDistanceToWaypoint) = 1203982336;
    v5->lastFacet = -1;
  }
  else
  {
    rge_read((int)v10, v4, v4, &v5->closestDistanceToWaypoint, 4);
    rge_read((int)v10, v4, v4, &v5->lastFacet, 1);
  }
  if( save_game_version < 7.23 )
  {
    v5->lastFacet2 = -1;
    result = 1;
  }
  else
  {
    rge_read((int)v10, v4, v4, &v5->lastFacet2, 1);
    result = 1;
  }
  return result;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0045CE00) --------------------------------------------------------
void __thiscall RGE_Moving_Object::save(RGE_Moving_Object *this, int outfile)
{
  int v2; // esi@1
  RGE_Moving_Object *v3; // edi@1
  int i; // ebx@1
  Waypoint *v5; // eax@2
  int v6; // ebx@3
  int v7; // ebp@4
  int currentWaypoint; // [sp+10h] [bp-4h]@3

  v2 = outfile;
  v3 = this;
  RGE_Animated_Object::save((RGE_Animated_Object *)&this->vfptr, outfile);
  rge_write(v2, &v3->trail_remainder, 4);
  rge_write(v2, &v3->velocity_x, 4);
  rge_write(v2, &v3->velocity_y, 4);
  rge_write(v2, &v3->velocity_z, 4);
  rge_write(v2, &v3->angle, 4);
  rge_write(v2, &v3->turn_towards_time, 4);
  outfile = Path::numberOfWaypoints(&v3->pathValue);
  rge_write(v2, &outfile, 4);
  for( i = 0; i < outfile; ++i )
  {
    v5 = Path::waypoint(&v3->pathValue, i);
    rge_write(v2, v5, 16);
  }
  currentWaypoint = Path::currentWaypointNumber(&v3->pathValue);
  rge_write(v2, &currentWaypoint, 4);
  rge_write(v2, &v3->startValue, 16);
  rge_write(v2, &v3->goalValue, 16);
  rge_write(v2, &v3->turnTimer, 4);
  rge_write(v2, &v3->collisionAvoidanceDistance, 4);
  rge_write(v2, &v3->actionRange, 4);
  rge_write(v2, &v3->targetIDValue, 4);
  rge_write(v2, &v3->targetRadiusX, 4);
  rge_write(v2, &v3->targetRadiusY, 4);
  rge_write(v2, &v3->continueCounter, 4);
  rge_write(v2, &v3->rangeStatusValue, 4);
  rge_write(v2, &v3->waitingToMoveValue, 1);
  rge_write(v2, &v3->numberWaitDelays, 1);
  rge_write(v2, &v3->numberUserDefinedWaypointsValue, 4);
  rge_write(v2, &v3->maxUserDefinedWaypointsValue, 4);
  v6 = 0;
  if( v3->numberUserDefinedWaypointsValue > 0 )
  {
    v7 = 0;
    do
    {
      rge_write(v2, &v3->userDefinedWaypoints[v7], 3);
      ++v6;
      ++v7;
    }
    while( v6 < v3->numberUserDefinedWaypointsValue );
  }
  rge_write(v2, &v3->finalUserDefinedWaypoint, 1);
  rge_write(v2, &v3->minInitialPointValue, 8);
  rge_write(v2, &v3->maxInitialPointValue, 8);
  rge_write(v2, &v3->closestDistanceToWaypoint, 4);
  rge_write(v2, &v3->lastFacet, 1);
  rge_write(v2, &v3->lastFacet2, 1);
}

//----- (0045D080) --------------------------------------------------------
void __thiscall RGE_Moving_Object::new_sprite(RGE_Moving_Object *this, RGE_Sprite *nsprite)
{
  RGE_Sprite *v2; // eax@1
  RGE_Moving_Object *v3; // esi@1
  RGE_Sprite *v4; // ecx@3

  v2 = nsprite;
  v3 = this;
  if( !nsprite )
    v2 = this->master_obj->sprite;
  v4 = this->sprite;
  if( v4 != v2 )
  {
    v3->old_sprite = v4;
    RGE_Static_Object::new_sprite((RGE_Static_Object *)&v3->vfptr, v2);
    RGE_Moving_Object::set_angle(v3);
  }
}

//----- (0045D0B0) --------------------------------------------------------
RGE_Static_Object *__thiscall RGE_Moving_Object::spawn_death_obj(RGE_Moving_Object *this)
{
  RGE_Moving_Object *v1; // edi@1
  RGE_Static_Object *v2; // eax@1
  RGE_Static_Object *v3; // esi@1

  v1 = this;
  v2 = RGE_Static_Object::spawn_death_obj((RGE_Static_Object *)&this->vfptr);
  v3 = v2;
  if( v2 && v2->master_obj->master_type >= 0x1Eu )
    ((void (__thiscall *)(RGE_Static_Object *, _DWORD))v2->vfptr->new_angle)(v2, LODWORD(v1->angle));
  return v3;
}

//----- (0045D0E0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::transform(RGE_Moving_Object *this, RGE_Master_Static_Object *obj)
{
  RGE_Moving_Object *v2; // esi@1

  v2 = this;
  RGE_Animated_Object::transform((RGE_Animated_Object *)&this->vfptr, obj);
  LODWORD(v2->velocity_x) = 0;
  LODWORD(v2->velocity_y) = 0;
  LODWORD(v2->velocity_z) = 0;
  LODWORD(v2->collisionAvoidanceDistance) = 0;
  LODWORD(v2->turnTimer) = 0;
  LODWORD(v2->turn_towards_time) = 0;
  RGE_Moving_Object::set_angle(v2);
}

//----- (0045D120) --------------------------------------------------------
bool __thiscall RGE_Moving_Object::is_moving(RGE_Moving_Object *this)
{
  return this->speed > 0.0;
}

//----- (0045D140) --------------------------------------------------------
void __thiscall RGE_Moving_Object::stop_moving(RGE_Moving_Object *this)
{
  LODWORD(this->speed) = 0;
}

//----- (0045D150) --------------------------------------------------------
double __thiscall RGE_Moving_Object::angle_to_object(RGE_Moving_Object *this, RGE_Static_Object *to_object, float x, float y)
{
  RGE_Sprite *v4; // eax@1
  __int16 v5; // dx@3
  double v6; // st7@5
  double v7; // st6@5
  double v8; // st7@7
  double v9; // st7@9
  double result; // st7@13

  v4 = this->sprite;
  if( v4 && v4->flag & 2 && (v5 = v4->facet_num, v5 > 0) )
  {
    if( to_object )
    {
      v6 = to_object->world_y;
      v7 = to_object->world_x;
    }
    else
    {
      v6 = y;
      v7 = x;
    }
    v8 = atan2(v7 - this->world_x, v6 - this->world_y);
    if( v8 < 0.0 )
      v8 = v8 - -6.2831855;
    v9 = v8 - this->angle;
    if( v9 > 3.14159265 )
      v9 = v9 - 6.2831855;
    if( v9 < -3.14159265 )
      v9 = v9 - -6.2831855;
    result = v9 * ((double)v5 * 0.15915494);
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (0045D1F0) --------------------------------------------------------
char __thiscall RGE_Moving_Object::turn_towards(RGE_Moving_Object *this, RGE_Static_Object *obj, float x, float y)
{
  float v4; // ebx@1
  float v5; // edi@1
  RGE_Moving_Object *v6; // esi@1
  double v7; // st7@1
  double v9; // st7@4
  double v10; // st7@6
  float v11; // et1@8
  double v13; // st7@8
  char v14; // c0@8
  double v15; // st7@9
  double v16; // st7@13
  float xa; // [sp+20h] [bp+8h]@4
  float world_time; // [sp+24h] [bp+Ch]@1

  v4 = x;
  v5 = y;
  v6 = this;
  v7 = RGE_Moving_Object::angle_to_object(this, obj, x, y);
  world_time = v7;
  if( v7 <= 0.5 && world_time >= -0.5 )
    return 1;
  v9 = (double)v6->owner->world->world_time * 0.001;
  xa = v9;
  if( v9 - v6->turn_towards_time < *(float *)&v6->master_obj[1].string_id )
    return 0;
  if( world_time >= 0.0 )
    v10 = 6.2831853 / (double)v6->sprite->facet_num + v6->angle;
  else
    v10 = v6->angle - 6.2831853 / (double)v6->sprite->facet_num;
  v6->angle = v10;
  v11 = v6->angle;
  v13 = v6->angle;
  if( v14 )
  {
    v15 = v13 - -6.2831855;
LABEL_12:
    v6->angle = v15;
    goto LABEL_13;
  }
  if( v13 > 6.2831855 )
  {
    v15 = v6->angle - 6.2831855;
    goto LABEL_12;
  }
LABEL_13:
  RGE_Moving_Object::set_angle(v6);
  v6->turn_towards_time = xa;
  v16 = RGE_Moving_Object::angle_to_object(v6, obj, v4, v5);
  if( v16 <= 0.5 && v16 >= -0.5 )
    return 1;
  return 0;
}

//----- (0045D360) --------------------------------------------------------
void __thiscall RGE_Moving_Object::set_angle(RGE_Moving_Object *this)
{
  RGE_Sprite *v1; // eax@1
  __int16 v2; // ax@3
  double v3; // st7@4
  float v4; // [sp+4h] [bp-4h]@4

  v1 = this->sprite;
  if( v1 && v1->flag & 2 && (v2 = v1->facet_num, v2 > 0) )
  {
    v4 = (double)v2;
    v3 = (this->angle - 0.78539819) * v4 * 0.15915494 - -0.5;
    if( v3 < 0.0 )
      v3 = v3 + v4;
    this->facet = (signed __int64)v3;
  }
  else
  {
    this->facet = 0;
  }
}

//----- (0045D3D0) --------------------------------------------------------
double __thiscall RGE_Moving_Object::teleport(RGE_Moving_Object *this, float x, float y, float z)
{
  RGE_Moving_Object *v4; // esi@1
  RGE_Master_Static_Object *v5; // eax@1
  RGE_Player *v6; // ecx@3
  RGE_Master_Static_Object *v7; // edi@3
  double v8; // st7@6
  double v9; // st6@6
  long double v10; // st5@6
  signed __int64 v11; // rax@6
  float v12; // ST3C_4@11
  float dy; // ST40_4@11
  RGE_Static_Object *(__thiscall *v14)(RGE_Master_Static_Object *, RGE_Player *, float, float, float); // ebx@8
  int v15; // eax@9
  bool v16; // zf@11
  int v17; // eax@14
  float dz; // [sp+14h] [bp-24h]@6
  float dza; // [sp+14h] [bp-24h]@7
  float v21; // [sp+18h] [bp-20h]@7
  float tx; // [sp+1Ch] [bp-1Ch]@7
  float ty; // [sp+20h] [bp-18h]@7
  float tz; // [sp+24h] [bp-14h]@7
  float d; // [sp+28h] [bp-10h]@6
  int v26; // [sp+2Ch] [bp-Ch]@8

  v4 = this;
  v5 = this->master_obj;
  if( LOBYTE(v5[1].object_group) )
  {
    if( this->tile )
    {
      v6 = this->owner;
      v7 = v6->master_objects[v5[1].copy_id];
      if( v7 )
      {
        if( LOBYTE(v5[1].object_group) == 1 )
        {
          v17 = ((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))v7->vfptr->make_new_obj)(
                  v7,
                  v6,
                  LODWORD(v4->world_x),
                  LODWORD(v4->world_y),
                  LODWORD(v4->world_z));
          if( *(_WORD *)(*(_DWORD *)(v17 + 8) + 16) > 30 )
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v17 + 180))(v17, LODWORD(v4->angle));
        }
        else if( LOBYTE(v5[1].object_group) == 2 )
        {
          v8 = x - v4->world_x;
          v9 = y - v4->world_y;
          dz = z - v4->world_z;
          v10 = sqrt(v8 * v8 + v9 * v9 + dz * dz) + v4->trail_remainder;
          d = v10;
          v11 = (signed __int64)(v10 / *(float *)&v5[1].sprite);
          if( (signed __int16)v11 <= 0 )
          {
            v4->trail_remainder = d + v4->trail_remainder;
          }
          else
          {
            ty = v4->world_y;
            v21 = (double)(signed __int16)v11;
            tx = v4->world_x;
            tz = v4->world_z;
            dza = dz / v21;
            if( (signed __int16)v11 > 0 )
            {
              v26 = (signed __int16)v11;
              v14 = v7->vfptr->make_new_obj;
              do
              {
                v15 = ((int (__thiscall *)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))v14)(
                        v7,
                        v4->owner,
                        LODWORD(tx),
                        LODWORD(ty),
                        LODWORD(tz));
                if( *(_WORD *)(*(_DWORD *)(v15 + 8) + 16) > 30 )
                  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v15 + 180))(v15, LODWORD(v4->angle));
                v12 = v8 / v21;
                tx = tx + v12;
                dy = v9 / v21;
                ty = ty + dy;
                v16 = v26 == 1;
                tz = tz + dza;
                --v26;
              }
              while( !v16 );
            }
            v4->trail_remainder = d - *(float *)&v4->master_obj[1].sprite * v21;
          }
        }
      }
    }
  }
  return RGE_Static_Object::teleport((RGE_Static_Object *)&v4->vfptr, x, y, z);
}

//----- (0045D5C0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::set_velocity(RGE_Moving_Object *this, float x, float y, float z)
{
  this->velocity_x = x;
  this->velocity_y = y;
  this->velocity_z = z;
}

//----- (0045D5F0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::new_angle(RGE_Moving_Object *this, float new_angle)
{
  this->angle = new_angle;
  RGE_Moving_Object::set_angle(this);
}

//----- (0045D610) --------------------------------------------------------
Path *__thiscall RGE_Moving_Object::getPath(RGE_Moving_Object *this)
{
  return &this->pathValue;
}

//----- (0045D620) --------------------------------------------------------
char __thiscall RGE_Moving_Object::facetToNextWaypoint(RGE_Moving_Object *this)
{
  Path *v1; // esi@1
  char result; // al@2

  v1 = &this->pathValue;
  if( Path::currentWaypoint(&this->pathValue) )
    result = Path::currentWaypoint(v1)->facetToNextWaypoint;
  else
    result = -1;
  return result;
}

//----- (0045D650) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setGoal(RGE_Moving_Object *this, float gX, float gY, float gZ)
{
  this->goalValue.x = gX;
  this->goalValue.y = gY;
  this->goalValue.z = gZ;
}

//----- (0045D680) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setActionRange(RGE_Moving_Object *this, float r)
{
  this->actionRange = r;
}

//----- (0045D690) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setTargetID(RGE_Moving_Object *this, int tid)
{
  this->targetIDValue = tid;
}

//----- (0045D6A0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setTargetRadius(RGE_Moving_Object *this, float x, float y)
{
  this->targetRadiusX = x;
  this->targetRadiusY = y;
}

//----- (0045D6C0) --------------------------------------------------------
signed int __thiscall RGE_Moving_Object::findPath(RGE_Moving_Object *this)
{
  RGE_Moving_Object *v1; // esi@1
  signed int result; // eax@2
  RGE_Static_ObjectVtbl *v3; // edx@4
  RGE_Static_ObjectVtbl *v4; // edi@7
  XYZBYTEPoint *v5; // eax@11
  int v6; // ebx@13
  int v7; // ebp@14
  double newY; // ST34_8@15
  double v9; // st7@15
  float v10; // ST34_4@19
  float v11; // ST30_4@19
  double v12; // ST54_8@20
  double v13; // ST54_8@21
  float newY_4; // ST38_4@22
  float v15; // ST34_4@22
  float v16; // ST30_4@22
  int v17; // ebx@23
  int v18; // ebp@26
  RGE_Player *v19; // ebx@27
  int v20; // ebp@27
  float v21; // ST34_4@27
  Waypoint *v22; // eax@27
  int v23; // ST54_4@27
  int v24; // [sp-10h] [bp-54h]@11
  int v25; // [sp-Ch] [bp-50h]@11
  RGE_Moving_Object *v26; // [sp-8h] [bp-4Ch]@11
  float v27; // [sp-4h] [bp-48h]@11
  int v28; // [sp+0h] [bp-44h]@11
  signed __int64 v29; // [sp+4h] [bp-40h]@11
  signed __int64 v30; // [sp+Ch] [bp-38h]@11
  double v31; // [sp+14h] [bp-30h]@11
  int v32; // [sp+34h] [bp-10h]@25
  int v33; // [sp+38h] [bp-Ch]@26

  v1 = this;
  if( this->master_obj->radius_z > 0.0 )
  {
    if(  __thiscall `vcall'{456,{flat}} )
    {
      if( RGE_Player::availablePathingAttempts(this->owner, this->numberWaitDelays) )
      {
        RGE_Player::incrementPathingAttempts(v1->owner);
        v4 = v1->vfptr;
        v1->numberWaitDelays = 0;
        v4->setWaitingToMove((RGE_Static_Object *)v1, 0);
        if( RGE_Player::computerPlayer(v1->owner) )
          v1->continueCounter = v1->numberUserDefinedWaypointsValue + 15;
        else
          v1->continueCounter = v1->numberUserDefinedWaypointsValue + 25;
        v1->startValue.x = v1->world_x;
        v1->startValue.y = v1->world_y;
        v1->startValue.z = v1->world_z;
        LODWORD(v1->closestDistanceToWaypoint) = 1203982336;
        PathingSystem::incrementInitialPaths(&pathSystem);
        if( v1->numberUserDefinedWaypointsValue <= 0 )
        {
          *(_QWORD *)&v31 = 4294967297i64;
          v30 = 4294967297i64;
          v29 = 1i64;
          v28 = v1->targetIDValue;
          v27 = v1->actionRange;
          v26 = v1;
          v25 = (signed __int64)v1->goalValue.y;
          v24 = (signed __int64)v1->goalValue.x;
        }
        else
        {
          v5 = v1->userDefinedWaypoints;
          *(_QWORD *)&v31 = 4294967297i64;
          v30 = 4294967297i64;
          v29 = 1i64;
          v28 = v1->targetIDValue;
          v27 = v1->actionRange;
          v26 = v1;
          v25 = v5->y;
          v24 = v5->x;
        }
        v6 = PathingSystem::findTilePath(
               &pathSystem,
               (signed __int64)v1->startValue.x,
               (signed __int64)v1->startValue.y,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               (float *)HIDWORD(v29),
               v30,
               SHIDWORD(v30),
               SLODWORD(v31),
               SHIDWORD(v31),
               -1,
               -1);
        if( actionFile )
        {
          fprintf(
            actionFile,
            aTLdUidDFp1S6_2,
            v1->owner->world->world_time,
            v1->id,
            v1->startValue.x,
            v1->startValue.y,
            v1->goalValue.x,
            v1->goalValue.y);
          Path::initToStart(&v1->pathValue);
          v7 = 0;
          while( v7 < Path::numberOfWaypoints(&v1->pathValue) )
          {
            newY = Path::currentWaypoint(&v1->pathValue)->y;
            v9 = Path::currentWaypoint(&v1->pathValue)->x;
            fprintf(actionFile, aWpD6_2f6_2f, v7++, v9, newY);
            Path::moveToNextWaypoint(&v1->pathValue);
          }
          fprintf(actionFile, a_);
          Path::initToStart(&v1->pathValue);
          Path::moveToNextWaypoint(&v1->pathValue);
        }
        if( v6
          || Path::numberOfWaypoints(&v1->pathValue) != 1
          || (v10 = floor(v1->world_y) - -0.5,
              v11 = floor(v1->world_x) - -0.5,
              !PathingSystem::passable(&pathSystem, v1, v11, v10, 1))
          || (v12 = v1->world_x, v12 - floor(v12) == 0.5) && (v13 = v1->world_y, v13 - floor(v13) == 0.5) )
        {
          Path::setTimeStamp(&v1->pathValue, v1->owner->world->world_time);
          v17 = displayPathObjectID;
          if( displayPathingFlags && v1->selected & 1 )
          {
            Path::initToStart(&v1->pathValue);
            v32 = 0;
            if( Path::numberOfWaypoints(&v1->pathValue) > 0 )
            {
              v18 = 4 * v17;
              v33 = v17;
              do
              {
                v19 = v1->owner;
                v20 = **(_DWORD **)((char *)v19->master_objects + v18);
                v21 = Path::currentWaypoint(&v1->pathValue)->y;
                v22 = Path::currentWaypoint(&v1->pathValue);
                v23 = v20;
                v18 = v33 * 4;
                (*(void (__thiscall **)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, float, signed int))(v23 + 24))(
                  v19->master_objects[v33],
                  v19,
                  LODWORD(v22->x),
                  COERCE_FLOAT(LODWORD(v21)),
                  1065353216);
                ++v32;
                Path::moveToNextWaypoint(&v1->pathValue);
              }
              while( v32 < Path::numberOfWaypoints(&v1->pathValue) );
            }
            Path::initToStart(&v1->pathValue);
            Path::moveToNextWaypoint(&v1->pathValue);
          }
          Path::initToStart(&v1->pathValue);
          Path::moveToNextWaypoint(&v1->pathValue);
          result = 0;
        }
        else
        {
          newY_4 = v1->world_z;
          v15 = floor(v1->world_y) - -0.5;
          v16 = floor(v1->world_x) - -0.5;
          (*(void (__stdcall **)(_DWORD, _DWORD, float))&v4->gap4[48])(
            LODWORD(v16),
            LODWORD(v15),
            COERCE_FLOAT(LODWORD(newY_4)));
          result = 2;
        }
      }
      else
      {
        ++v1->numberWaitDelays;
        result = 2;
      }
    }
    else
    {
      v3 = this->vfptr;
      this->pathingGroupMembers.numberValue = (int) __thiscall `vcall'{456,{flat}};
      v3->setWaitingToMove((RGE_Static_Object *)this, (char) __thiscall `vcall'{456,{flat}});
      result = 1;
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->setWaitingToMove)(0);
    v1->startValue.x = v1->world_x;
    v1->startValue.y = v1->world_y;
    v1->startValue.z = v1->world_z;
    v1->pathingGroupMembers.numberValue = 0;
    Path::setTimeStamp(&v1->pathValue, v1->owner->world->world_time);
    Path::killPath(&v1->pathValue);
    Path::insertAtCurrent(&v1->pathValue, &v1->goalValue);
    Path::insertAtCurrent(&v1->pathValue, &v1->startValue);
    Path::initToStart(&v1->pathValue);
    Path::moveToNextWaypoint(&v1->pathValue);
    LODWORD(v1->closestDistanceToWaypoint) = 1203982336;
    result = 0;
  }
  return result;
}
// 584C58: using guessed type int displayPathObjectID;
// 62E668: using guessed type int displayPathingFlags;

//----- (0045DB90) --------------------------------------------------------
int __thiscall RGE_Moving_Object::doMove(RGE_Moving_Object *this)
{
  RGE_Moving_Object *v1; // esi@1
  RGE_Static_ObjectVtbl *v2; // ebx@1
  double v3; // st7@1
  double v4; // st6@1
  RGE_Master_Static_Object *v5; // eax@5
  double v6; // st5@5
  double v7; // st7@5
  double v8; // st4@9
  unsigned __int8 v10; // c0@9
  unsigned __int8 v11; // c3@9
  float v12; // ST64_4@14
  double v13; // st6@14
  float v14; // ST60_4@14
  long double v15; // st7@14
  int result; // eax@17
  int v17; // eax@18
  int v18; // ebp@27
  float v19; // ST64_4@28
  double v20; // st6@28
  double v21; // st5@28
  float v22; // ST64_4@28
  float newY; // ST40_4@29
  Waypoint *v24; // eax@29
  float newY_4; // ST44_4@30
  float v26; // ST40_4@30
  Waypoint *v27; // eax@30
  char v28; // bl@35
  void (__thiscall *v29)(RGE_Static_Object *, int); // ebx@41
  XYZBYTEPoint *v30; // eax@43
  double v31; // st6@43
  double v32; // rt2@43
  float v33; // ST64_4@43
  int v34; // edx@46
  signed int v35; // ecx@47
  XYZBYTEPoint *v36; // eax@52
  int v37; // ebx@54
  int v38; // ebp@55
  double v39; // ST40_8@56
  double v40; // st7@56
  float v41; // ST40_4@60
  float v42; // ST3C_4@60
  double v43; // ST68_8@61
  double v44; // ST68_8@62
  float v45; // ST44_4@63
  float v46; // ST40_4@63
  float v47; // ST3C_4@63
  int v48; // ebx@64
  int v49; // ebx@67
  RGE_Player *v50; // ebp@68
  int v51; // ebx@68
  float v52; // ST40_4@68
  Waypoint *v53; // eax@68
  int v54; // ST68_4@68
  signed int v55; // ecx@71
  float v56; // ST44_4@75
  Waypoint *v57; // eax@75
  int v58; // eax@75
  signed int v59; // ebp@83
  void (__thiscall *v60)(RGE_Static_Object *, int); // ebx@83
  XYZBYTEPoint *v61; // eax@85
  double v62; // st6@85
  double v63; // rt0@85
  float v64; // ST64_4@85
  char v65; // al@89
  XYZBYTEPoint *v66; // eax@91
  int v67; // ebx@93
  int v68; // ebp@94
  double v69; // ST40_8@95
  double v70; // st7@95
  float v71; // ST40_4@99
  float v72; // ST3C_4@99
  double v73; // ST68_8@100
  double v74; // ST68_8@101
  signed int v75; // eax@102
  float v76; // ST44_4@104
  float v77; // ST40_4@104
  float v78; // ST3C_4@104
  int v79; // ebx@105
  int v80; // ebx@108
  RGE_Player *v81; // ebp@109
  int v82; // ebx@109
  float v83; // ST40_4@109
  Waypoint *v84; // eax@109
  int v85; // ST60_4@109
  signed int v86; // ecx@112
  signed int v87; // ecx@115
  signed int v88; // eax@118
  int v89; // [sp+14h] [bp-5Ch]@52
  int v90; // [sp+14h] [bp-5Ch]@91
  int v91; // [sp+18h] [bp-58h]@52
  int v92; // [sp+18h] [bp-58h]@91
  RGE_Moving_Object *v93; // [sp+1Ch] [bp-54h]@52
  RGE_Moving_Object *v94; // [sp+1Ch] [bp-54h]@91
  float v95; // [sp+20h] [bp-50h]@52
  float v96; // [sp+20h] [bp-50h]@91
  int v97; // [sp+24h] [bp-4Ch]@52
  int v98; // [sp+24h] [bp-4Ch]@91
  signed __int64 v99; // [sp+30h] [bp-40h]@52
  signed __int64 v100; // [sp+30h] [bp-40h]@91
  double v101; // [sp+38h] [bp-38h]@52
  double v102; // [sp+38h] [bp-38h]@91
  RGE_Static_ObjectVtbl *v103; // [sp+58h] [bp-18h]@1
  float distanceToGoal; // [sp+5Ch] [bp-14h]@5
  float distanceToGoala; // [sp+5Ch] [bp-14h]@9
  float distanceToGoalb; // [sp+5Ch] [bp-14h]@67
  float dY; // [sp+60h] [bp-10h]@27
  float dY_4; // [sp+64h] [bp-Ch]@33
  int dY_4a; // [sp+64h] [bp-Ch]@66
  int dY_4b; // [sp+64h] [bp-Ch]@107
  int v111; // [sp+68h] [bp-8h]@108

  v1 = this;
  v2 = this->vfptr;
  v103 = this->vfptr;
  ((void (__stdcall *)(_DWORD))this->vfptr->setWaitingToMove)(0);
  v3 = v1->goalValue.x - v1->world_x;
  v4 = v1->goalValue.y - v1->world_y;
  if( v3 < 0.0 )
    v3 = -v3;
  if( v4 < 0.0 )
    v4 = -v4;
  v5 = v1->master_obj;
  v6 = v3 - (v1->targetRadiusX + v5->radius_x);
  v7 = v4 - (v1->targetRadiusY + v5->radius_y);
  distanceToGoal = v6;
  if( v6 < 0.0 )
    distanceToGoal = 0.0;
  if( v7 < 0.0 )
    v7 = 0.0;
  v8 = v1->actionRange;
  distanceToGoala = sqrt(distanceToGoal * distanceToGoal + v7 * v7);
  if( !(v10 | v11) && distanceToGoala <= (double)v1->actionRange )
  {
    LODWORD(v1->speed) = 0;
LABEL_76:
    v1->rangeStatusValue = 1;
    v2->removeAllUserDefinedWaypoints((RGE_Static_Object *)v1, 0);
    v1->pathingGroupMembers.numberValue = 0;
    return 2;
  }
  if( distanceToGoala < 0.5 )
  {
    if( Path::currentWaypoint(&v1->pathValue) )
    {
      v12 = Path::currentWaypoint(&v1->pathValue)->x - v1->world_x;
      v13 = Path::currentWaypoint(&v1->pathValue)->y - v1->world_y;
      v14 = v13;
      v15 = sqrt(v12 * v12 + v13 * v14);
    }
    else
    {
      v15 = distanceToGoala;
    }
    if( v15 == 0.0 )
    {
      v1->pathingGroupMembers.numberValue = 0;
      return 2;
    }
    v17 = RGE_Moving_Object::doTrivialMove(v1, v1->goalValue.x, v1->goalValue.y);
    if( v17 == 5 )
      goto LABEL_76;
    if( !v17 )
    {
      v1->rangeStatusValue = 2;
      return 1;
    }
    if( v17 == 1 || v17 == 6 )
    {
LABEL_80:
      LODWORD(v1->speed) = 0;
      v1->rangeStatusValue = 2;
      return 1;
    }
    if( v17 == 2 || v17 == 3 || v17 == 4 )
    {
      LODWORD(v1->speed) = 0;
      goto LABEL_76;
    }
  }
  v18 = 1;
  dY = sqrt(v1->master_obj->radius_x * v1->master_obj->radius_x + v1->master_obj->radius_y * v1->master_obj->radius_y);
  if( Path::currentWaypoint(&v1->pathValue) )
  {
    v19 = Path::currentWaypoint(&v1->pathValue)->x - v1->world_x;
    v20 = Path::currentWaypoint(&v1->pathValue)->y - v1->world_y;
    v21 = v19;
    v22 = v20;
    if( sqrt(v21 * v21 + v20 * v22) == 0.0 )
    {
      newY = Path::currentWaypoint(&v1->pathValue)->y;
      v24 = Path::currentWaypoint(&v1->pathValue);
      if( PathingSystem::passable(&pathSystem, v1, v24->x, newY, 1) )
      {
        newY_4 = Path::currentWaypoint(&v1->pathValue)->z;
        v26 = Path::currentWaypoint(&v1->pathValue)->y;
        v27 = Path::currentWaypoint(&v1->pathValue);
        (*(void (__thiscall **)(RGE_Moving_Object *, _DWORD, float, float))&v2->gap4[48])(
          v1,
          LODWORD(v27->x),
          COERCE_FLOAT(LODWORD(v26)),
          COERCE_FLOAT(LODWORD(newY_4)));
      }
      v18 = Path::moveToNextWaypoint(&v1->pathValue);
      LODWORD(v1->closestDistanceToWaypoint) = 1203982336;
    }
  }
  else
  {
    v18 = 0;
  }
  dY_4 = 0.0;
  if( v1->numberUserDefinedWaypointsValue > 1 && distanceToGoala > 4.0 )
  {
    v28 = RGE_Static_Object::lookupZone(
            (RGE_Static_Object *)&v1->vfptr,
            v1->userDefinedWaypoints->x,
            v1->userDefinedWaypoints->y);
    if( v28 == RGE_Static_Object::lookupZone(
                  (RGE_Static_Object *)&v1->vfptr,
                  v1->userDefinedWaypoints[1].x,
                  v1->userDefinedWaypoints[1].y) )
      dY_4 = 3.0;
    v2 = v103;
  }
  if( v18 )
  {
    if( !Path::currentWaypoint(&v1->pathValue) )
      goto LABEL_122;
LABEL_74:
    v56 = Path::currentWaypoint(&v1->pathValue)->y;
    v57 = Path::currentWaypoint(&v1->pathValue);
    v58 = RGE_Moving_Object::doTrivialMove(v1, v57->x, v56);
    if( v58 == 5 )
      goto LABEL_76;
    if( !v58 )
    {
      v1->rangeStatusValue = 2;
      return 1;
    }
    if( v58 == 1 )
      goto LABEL_80;
    if( v58 == 2 )
    {
      if( Path::moveToNextWaypoint(&v1->pathValue) )
      {
LABEL_114:
        v1->rangeStatusValue = 2;
        return 1;
      }
      v59 = 0;
      v60 = v103->removeUserDefinedWaypoint;
      while( 1 )
      {
        v60((RGE_Static_Object *)&v1->vfptr, 0);
        if( v1->numberUserDefinedWaypointsValue <= 0 )
          break;
        v61 = v1->userDefinedWaypoints;
        v62 = (double)v61->y - v1->world_y;
        v63 = (double)v61->x - v1->world_x;
        v64 = v62;
        if( dY + v1->actionRange - -0.30000001 < sqrt(v63 * v63 + v62 * v64) )
          v59 = 1;
        if( v59 )
        {
          if( !RGE_Player::availablePathingAttempts(v1->owner, v1->numberWaitDelays) )
          {
            v65 = v1->numberWaitDelays;
            LODWORD(v1->speed) = 0;
            v1->numberWaitDelays = v65 + 1;
            return 1;
          }
          RGE_Player::incrementPathingAttempts(v1->owner);
          v1->startValue.x = v1->world_x;
          v1->startValue.y = v1->world_y;
          v1->startValue.z = v1->world_z;
          v1->numberWaitDelays = 0;
          PathingSystem::incrementContinuePaths(&pathSystem);
          if( v1->numberUserDefinedWaypointsValue <= 0 )
          {
            *(_QWORD *)&v102 = 4294967297i64;
            v100 = 4294967297i64;
            v98 = v1->targetIDValue;
            v96 = v1->actionRange;
            v94 = v1;
            v92 = (signed __int64)v1->goalValue.y;
            v90 = (signed __int64)v1->goalValue.x;
          }
          else
          {
            v66 = v1->userDefinedWaypoints;
            *(_QWORD *)&v102 = 4294967297i64;
            v100 = 4294967297i64;
            v98 = v1->targetIDValue;
            v96 = v1->actionRange;
            v94 = v1;
            v92 = v66->y;
            v90 = v66->x;
          }
          v67 = PathingSystem::findTilePath(
                  &pathSystem,
                  (signed __int64)v1->startValue.x,
                  (signed __int64)v1->startValue.y,
                  v90,
                  v92,
                  v94,
                  v96,
                  v98,
                  1,
                  0,
                  v100,
                  SHIDWORD(v100),
                  SLODWORD(v102),
                  SHIDWORD(v102),
                  -1,
                  -1);
          v1->pathingGroupMembers.numberValue = 0;
          if( actionFile )
          {
            fprintf(
              actionFile,
              aTLdUidDFp1S6_2,
              v1->owner->world->world_time,
              v1->id,
              v1->startValue.x,
              v1->startValue.y,
              v1->goalValue.x,
              v1->goalValue.y);
            Path::initToStart(&v1->pathValue);
            v68 = 0;
            while( v68 < Path::numberOfWaypoints(&v1->pathValue) )
            {
              v69 = Path::currentWaypoint(&v1->pathValue)->y;
              v70 = Path::currentWaypoint(&v1->pathValue)->x;
              fprintf(actionFile, aWpD6_2f6_2f, v68++, v70, v69);
              Path::moveToNextWaypoint(&v1->pathValue);
            }
            fprintf(actionFile, a_);
            Path::initToStart(&v1->pathValue);
            Path::moveToNextWaypoint(&v1->pathValue);
          }
          if( !v67 && Path::numberOfWaypoints(&v1->pathValue) == 1 )
          {
            v71 = floor(v1->world_y) - -0.5;
            v72 = floor(v1->world_x) - -0.5;
            if( PathingSystem::passable(&pathSystem, v1, v72, v71, 1) )
            {
              v73 = v1->world_x;
              if( v73 - floor(v73) == 0.5 )
              {
                v74 = v1->world_y;
                if( v74 - floor(v74) == 0.5 )
                {
                  v75 = v1->numberUserDefinedWaypointsValue;
                  LODWORD(v1->speed) = 0;
                  v1->rangeStatusValue = 2;
                  if( v75 <= 1 )
                    return 0;
                  v1->continueCounter += 5;
                  return 1;
                }
              }
              v76 = v1->world_z;
              v77 = floor(v1->world_y) - -0.5;
              v78 = floor(v1->world_x) - -0.5;
              (*(void (__stdcall **)(_DWORD, _DWORD, float))&v103->gap4[48])(
                LODWORD(v78),
                LODWORD(v77),
                COERCE_FLOAT(LODWORD(v76)));
            }
          }
          v79 = displayPathObjectID;
          if( displayPathingFlags && v1->selected & 1 )
          {
            Path::initToStart(&v1->pathValue);
            dY_4b = 0;
            if( Path::numberOfWaypoints(&v1->pathValue) > 0 )
            {
              v80 = 4 * v79;
              v111 = v80;
              do
              {
                v81 = v1->owner;
                v82 = **(_DWORD **)((char *)v81->master_objects + v80);
                v83 = Path::currentWaypoint(&v1->pathValue)->y;
                v84 = Path::currentWaypoint(&v1->pathValue);
                v85 = v82;
                v80 = v111;
                (*(void (__thiscall **)(_DWORD, RGE_Player *, _DWORD, float, signed int))(v85 + 24))(
                  *(RGE_Master_Static_Object **)((char *)v81->master_objects + v111),
                  v81,
                  LODWORD(v84->x),
                  COERCE_FLOAT(LODWORD(v83)),
                  1065353216);
                ++dY_4b;
                Path::moveToNextWaypoint(&v1->pathValue);
              }
              while( dY_4b < Path::numberOfWaypoints(&v1->pathValue) );
            }
            Path::initToStart(&v1->pathValue);
            Path::moveToNextWaypoint(&v1->pathValue);
          }
          Path::initToStart(&v1->pathValue);
          if( Path::moveToNextWaypoint(&v1->pathValue) )
            goto LABEL_114;
          v86 = v1->numberUserDefinedWaypointsValue;
          LODWORD(v1->speed) = 0;
          result = 1;
          v1->rangeStatusValue = 2;
          if( v86 <= 1 )
            return 0;
          v1->continueCounter += 5;
          return result;
        }
      }
    }
    else
    {
LABEL_122:
      v87 = v1->numberUserDefinedWaypointsValue;
      result = 1;
      LODWORD(v1->speed) = 0;
      v1->rangeStatusValue = 2;
      if( v87 > 1 )
      {
        v1->continueCounter += 5;
        return result;
      }
    }
    return 0;
  }
  if( distanceToGoala <= dY_4 + dY + v1->actionRange )
  {
    LODWORD(v1->speed) = 0;
    v1->rangeStatusValue = 1;
    v2->removeAllUserDefinedWaypoints((RGE_Static_Object *)v1, 0);
    v1->pathingGroupMembers.numberValue = 0;
    return 2;
  }
  v29 = v103->removeUserDefinedWaypoint;
  do
  {
    v29((RGE_Static_Object *)&v1->vfptr, 0);
    if( v1->numberUserDefinedWaypointsValue <= 0 )
      return 0;
    v30 = v1->userDefinedWaypoints;
    v31 = (double)v30->y - v1->world_y;
    v32 = (double)v30->x - v1->world_x;
    v33 = v31;
    if( dY + v1->actionRange - -0.30000001 < sqrt(v32 * v32 + v31 * v33) )
      v18 = 1;
  }
  while( !v18 );
  v34 = v1->continueCounter - 1;
  v1->continueCounter = v34;
  if( v34 <= 0 )
  {
    v35 = v1->numberUserDefinedWaypointsValue;
    LODWORD(v1->speed) = 0;
    v1->rangeStatusValue = 2;
    if( v35 <= 1 )
      return 0;
    v1->continueCounter = v34 + 5;
    return 1;
  }
  if( !RGE_Player::availablePathingAttempts(v1->owner, v1->numberWaitDelays) )
  {
    LODWORD(v1->speed) = 0;
    ++v1->numberWaitDelays;
    return 1;
  }
  RGE_Player::incrementPathingAttempts(v1->owner);
  v1->startValue.x = v1->world_x;
  v1->startValue.y = v1->world_y;
  v1->startValue.z = v1->world_z;
  v1->numberWaitDelays = 0;
  PathingSystem::incrementContinuePaths(&pathSystem);
  if( v1->numberUserDefinedWaypointsValue <= 0 )
  {
    *(_QWORD *)&v101 = 4294967297i64;
    v99 = 4294967297i64;
    v97 = v1->targetIDValue;
    v95 = v1->actionRange;
    v93 = v1;
    v91 = (signed __int64)v1->goalValue.y;
    v89 = (signed __int64)v1->goalValue.x;
  }
  else
  {
    v36 = v1->userDefinedWaypoints;
    *(_QWORD *)&v101 = 4294967297i64;
    v99 = 4294967297i64;
    v97 = v1->targetIDValue;
    v95 = v1->actionRange;
    v93 = v1;
    v91 = v36->y;
    v89 = v36->x;
  }
  v37 = PathingSystem::findTilePath(
          &pathSystem,
          (signed __int64)v1->startValue.x,
          (signed __int64)v1->startValue.y,
          v89,
          v91,
          v93,
          v95,
          v97,
          1,
          0,
          v99,
          SHIDWORD(v99),
          SLODWORD(v101),
          SHIDWORD(v101),
          -1,
          -1);
  v1->pathingGroupMembers.numberValue = 0;
  if( actionFile )
  {
    fprintf(
      actionFile,
      aTLdUidDFp1S6_2,
      v1->owner->world->world_time,
      v1->id,
      v1->startValue.x,
      v1->startValue.y,
      v1->goalValue.x,
      v1->goalValue.y);
    Path::initToStart(&v1->pathValue);
    v38 = 0;
    while( v38 < Path::numberOfWaypoints(&v1->pathValue) )
    {
      v39 = Path::currentWaypoint(&v1->pathValue)->y;
      v40 = Path::currentWaypoint(&v1->pathValue)->x;
      fprintf(actionFile, aWpD6_2f6_2f, v38++, v40, v39);
      Path::moveToNextWaypoint(&v1->pathValue);
    }
    fprintf(actionFile, a_);
    Path::initToStart(&v1->pathValue);
    Path::moveToNextWaypoint(&v1->pathValue);
  }
  if( v37 || Path::numberOfWaypoints(&v1->pathValue) != 1 )
  {
LABEL_64:
    v48 = displayPathObjectID;
    if( displayPathingFlags && v1->selected & 1 )
    {
      Path::initToStart(&v1->pathValue);
      dY_4a = 0;
      if( Path::numberOfWaypoints(&v1->pathValue) > 0 )
      {
        v49 = 4 * v48;
        distanceToGoalb = *(float *)&v49;
        do
        {
          v50 = v1->owner;
          v51 = **(_DWORD **)((char *)v50->master_objects + v49);
          v52 = Path::currentWaypoint(&v1->pathValue)->y;
          v53 = Path::currentWaypoint(&v1->pathValue);
          v54 = v51;
          *(float *)&v49 = distanceToGoalb;
          (*(void (__thiscall **)(_DWORD, RGE_Player *, _DWORD, float, signed int))(v54 + 24))(
            *(RGE_Master_Static_Object **)((char *)v50->master_objects + LODWORD(distanceToGoalb)),
            v50,
            LODWORD(v53->x),
            COERCE_FLOAT(LODWORD(v52)),
            1065353216);
          ++dY_4a;
          Path::moveToNextWaypoint(&v1->pathValue);
        }
        while( dY_4a < Path::numberOfWaypoints(&v1->pathValue) );
      }
      Path::initToStart(&v1->pathValue);
      Path::moveToNextWaypoint(&v1->pathValue);
    }
    Path::initToStart(&v1->pathValue);
    if( Path::moveToNextWaypoint(&v1->pathValue) )
    {
      v2 = v103;
      LODWORD(v1->closestDistanceToWaypoint) = 1203982336;
      goto LABEL_74;
    }
    v55 = v1->numberUserDefinedWaypointsValue;
    result = 1;
    LODWORD(v1->speed) = 0;
    v1->rangeStatusValue = 2;
    if( v55 <= 1 )
      return 0;
    v1->continueCounter += 5;
    return result;
  }
  v41 = floor(v1->world_y) - -0.5;
  v42 = floor(v1->world_x) - -0.5;
  if( PathingSystem::passable(&pathSystem, v1, v42, v41, 1) )
  {
    v43 = v1->world_x;
    if( v43 - floor(v43) != 0.5 || (v44 = v1->world_y, v44 - floor(v44) != 0.5) )
    {
      v45 = v1->world_z;
      v46 = floor(v1->world_y) - -0.5;
      v47 = floor(v1->world_x) - -0.5;
      (*(void (__stdcall **)(_DWORD, _DWORD, float))&v103->gap4[48])(
        LODWORD(v47),
        LODWORD(v46),
        COERCE_FLOAT(LODWORD(v45)));
      goto LABEL_64;
    }
  }
  v88 = v1->numberUserDefinedWaypointsValue;
  LODWORD(v1->speed) = 0;
  v1->rangeStatusValue = 2;
  if( v88 <= 1 )
    return 0;
  v1->continueCounter += 5;
  return 1;
}
// 584C58: using guessed type int displayPathObjectID;
// 62E668: using guessed type int displayPathingFlags;

//----- (0045E970) --------------------------------------------------------
int __thiscall RGE_Moving_Object::doTrivialMove(RGE_Moving_Object *this, float x, float y)
{
  RGE_Moving_Object *v3; // esi@1
  signed int v4; // edx@1
  double v5; // st7@1
  RGE_Sprite *v6; // ecx@2
  RGE_Player *v7; // ecx@6
  unsigned __int8 v9; // c0@7
  unsigned __int8 v10; // c3@7
  int result; // eax@8
  RGE_Sprite *v12; // eax@14
  signed int v13; // edi@15
  long double v14; // st7@18
  double v15; // st7@20
  char v17; // c0@20
  int v18; // ST38_4@24
  float *v19; // edi@24
  double v20; // st7@25
  double v22; // st6@28
  double v23; // st7@28
  char v24; // c0@28
  double v25; // rt0@29
  double v26; // st6@29
  double v27; // st6@29
  double v28; // rt1@30
  double v29; // st6@30
  RGE_Master_Static_Object *v30; // edx@32
  int v31; // ecx@32
  long double v32; // rt2@32
  long double v33; // st6@32
  long double v34; // rtt@32
  double v35; // st7@32
  long double v36; // st4@32
  double v37; // st6@32
  float v38; // ST4C_4@32
  long double v39; // rt2@32
  long double v40; // st4@32
  double v41; // st5@32
  int v42; // ebx@32
  unsigned __int8 v44; // c0@32
  unsigned __int8 v45; // c3@32
  int v46; // edx@37
  double v47; // st6@37
  int v48; // edx@38
  double v49; // st7@39
  float v50; // ST34_4@39
  float v51; // ST30_4@39
  RGE_Static_ObjectVtbl *v52; // ebx@40
  float v53; // ST38_4@40
  float v54; // ST34_4@40
  float v55; // ST30_4@40
  RGE_Static_Object *v56; // eax@42
  RGE_Master_Static_Object *v57; // ecx@43
  double v58; // st7@43
  double v59; // st6@43
  double v60; // st5@43
  double v61; // rt2@43
  double v62; // rtt@43
  double v63; // st6@43
  float v64; // ST4C_4@43
  double v65; // st5@43
  long double v66; // rt2@43
  long double v67; // st5@43
  long double v68; // st6@43
  int v69; // eax@47
  XYZBYTEPoint *v70; // eax@52
  int v71; // ebx@55
  double v72; // ST34_8@56
  double v73; // st7@56
  float v74; // ST34_4@60
  float v75; // ST30_4@60
  double v76; // st7@61
  double v77; // st7@62
  RGE_Static_ObjectVtbl *v78; // edi@64
  float v79; // ST38_4@64
  float v80; // ST34_4@64
  float v81; // ST30_4@64
  int v82; // ebx@65
  int v83; // ebx@68
  float v84; // ST4C_4@69
  float v85; // ebx@69
  float v86; // ST34_4@69
  float v87; // ST30_4@69
  float v88; // ST2C_4@69
  int v89; // eax@69
  float v90; // ST4C_4@69
  int v91; // eax@69
  int v92; // eax@73
  Path *v93; // ecx@73
  long double v94; // st7@74
  Waypoint *v95; // ebx@75
  Waypoint *v96; // edi@75
  double v97; // st6@76
  float *v98; // edi@76
  double v100; // st7@76
  unsigned __int8 v101; // c0@76
  unsigned __int8 v102; // c3@76
  double v104; // st6@80
  double v105; // st7@80
  char v106; // c0@80
  double v107; // rtt@81
  double v108; // st6@81
  double v109; // st6@81
  double v110; // rt0@82
  double v111; // st6@82
  long double v112; // rt1@84
  long double v113; // st6@84
  double v114; // st5@84
  double v115; // st7@84
  float v116; // ST4C_4@84
  float v117; // eax@84
  float v118; // edx@84
  double v119; // st7@84
  double v120; // st7@88
  double v121; // st5@93
  double v122; // st7@93
  long double v123; // st6@93
  long double v124; // st5@93
  char v125; // al@95
  float v126; // ST34_4@98
  Waypoint *v127; // eax@98
  RGE_Static_ObjectVtbl *v128; // ebx@99
  float v129; // ST38_4@99
  float v130; // ST34_4@99
  Waypoint *v131; // eax@99
  float v132; // ST38_4@101
  double v133; // st6@102
  RGE_Static_ObjectVtbl *v134; // edx@102
  float v135; // ST38_4@102
  double v136; // st7@103
  double v137; // st6@103
  char v138; // dl@103
  char v140; // c0@103
  RGE_Sprite *v141; // ecx@107
  RGE_Tile *v142; // eax@111
  int v143; // [sp-4h] [bp-6Ch]@52
  int v144; // [sp+0h] [bp-68h]@52
  RGE_Moving_Object *v145; // [sp+4h] [bp-64h]@52
  float v146; // [sp+8h] [bp-60h]@52
  int v147; // [sp+Ch] [bp-5Ch]@52
  signed __int64 v148; // [sp+18h] [bp-50h]@52
  double v149; // [sp+20h] [bp-48h]@52
  double v150; // [sp+28h] [bp-40h]@52
  int numFacets_4; // [sp+3Ch] [bp-2Ch]@17
  float targetDY; // [sp+40h] [bp-28h]@18
  float targetDYa; // [sp+40h] [bp-28h]@74
  float targetDYb; // [sp+40h] [bp-28h]@103
  float newAngle; // [sp+44h] [bp-24h]@20
  float distanceToCover; // [sp+48h] [bp-20h]@6
  float targetDX; // [sp+4Ch] [bp-1Ch]@32
  float newY; // [sp+50h] [bp-18h]@32
  double curDistance; // [sp+54h] [bp-14h]@1
  float dY; // [sp+5Ch] [bp-Ch]@24
  double v161; // [sp+60h] [bp-8h]@61

  v3 = this;
  v4 = 1;
  v5 = this->speed;
  HIDWORD(curDistance) = 1;
  if( v5 == 0.0 )
  {
    v6 = this->sprite;
    v4 = 0;
    HIDWORD(curDistance) = 0;
    if( v6 && v6->base_speed > 0.0 )
      v3->speed = *(float *)&v3->master_obj[1].vfptr * v6->base_speed;
    else
      LODWORD(v3->speed) = v3->master_obj[1].vfptr;
  }
  v7 = v3->owner;
  distanceToCover = v7->world->world_time_delta_seconds * v3->speed;
  if( v3->collisionAvoidanceDistance > 0.0 )
  {
    v3->collisionAvoidanceDistance = v3->collisionAvoidanceDistance - distanceToCover;
    if( !(v9 | v10) )
    {
      LODWORD(v3->speed) = 0;
      return 0;
    }
    LODWORD(v3->collisionAvoidanceDistance) = -1082130432;
  }
  if( *(float *)&v3->master_obj[1].string_id > 0.0 )
  {
    if( v3->turnTimer >= 0.0 )
      v3->turnTimer = v3->turnTimer - v7->world->world_time_delta_seconds;
    else
      LODWORD(v3->turnTimer) = 0;
  }
  v12 = v3->sprite;
  if( v12 )
    v13 = v12->facet_num;
  else
    v13 = 8;
  numFacets_4 = v13;
  if( v4 == 1 )
  {
    v14 = y - v3->world_y;
    targetDY = x - v3->world_x;
  }
  else
  {
    targetDY = x - (floor(v3->world_x) - -0.5);
    v14 = y - (floor(v3->world_y) - -0.5);
  }
  newAngle = atan2(targetDY, v14);
  RGE_Moving_Object::boundAngle(&newAngle, -1);
  v15 = newAngle - v3->angle;
  if( v17 )
  {
    do
      v15 = v15 - -6.2831855;
    while( v15 < -3.14159265 );
  }
  for( ; v15 > 3.14159265; v15 = v15 - 6.2831855 )
    ;
  v18 = v13;
  v19 = &v3->angle;
  dY = (double)numFacets_4;
  *(float *)&curDistance = v15 * dY * 0.15915494;
  RGE_Moving_Object::boundAngle(&v3->angle, v18);
  if( v3->turnTimer <= 0.0 )
  {
    v20 = *(float *)&curDistance;
    do
    {
      if( v20 <= 0.8 && v20 >= -0.8 )
        break;
      v3->turnTimer = *(float *)&v3->master_obj[1].string_id + v3->turnTimer;
      v22 = v20;
      v23 = (double)numFacets_4;
      if( v24 )
      {
        v25 = v22 - -1.0;
        v26 = v23;
        v20 = v25;
        v27 = *v19 - 6.2831853 / v26;
      }
      else
      {
        v28 = v22 - 1.0;
        v29 = v23;
        v20 = v28;
        v27 = 6.2831853 / v29 + *v19;
      }
      *v19 = v27;
    }
    while( v3->turnTimer <= 0.0 );
  }
  RGE_Moving_Object::boundAngle(&v3->angle, numFacets_4);
  RGE_Moving_Object::set_angle(v3);
  v30 = v3->master_obj;
  v31 = 1;
  v32 = cos(*v19);
  v33 = sin(*v19);
  *(float *)&curDistance = v33;
  v34 = v33;
  v35 = v3->world_x;
  v36 = v32 * distanceToCover;
  v37 = v3->world_y;
  v38 = v36;
  v39 = v36;
  v40 = v34 * distanceToCover;
  targetDX = v40;
  v3->velocity_x = v39;
  v3->velocity_y = v40;
  v41 = v30->radius_z;
  *(float *)&curDistance = v35 + v38;
  v42 = LODWORD(curDistance);
  newY = v37 + targetDX;
  if( !(v44 | v45) )
    v31 = PathingSystem::passable(&pathSystem, v3, *(float *)&curDistance, newY, 1);
  if( !v31 )
  {
    if( v3->collisionAvoidanceDistance == 0.0 )
    {
      if( v3->speed <= 0.0 )
      {
        v48 = debug_rand(aCMsdevWorkA_24, 1745) % 6;
        LODWORD(v3->speed) = 0;
        result = 0;
        dY = *(float *)&v48;
        v3->collisionAvoidanceDistance = (double)v48 * 0.1 - -0.5;
      }
      else
      {
        v46 = debug_rand(aCMsdevWorkA_24, 1743) % 6;
        result = 0;
        dY = *(float *)&v46;
        v47 = -0.5 / v3->speed;
        LODWORD(v3->speed) = 0;
        v3->collisionAvoidanceDistance = (double)v46 * 0.1 - v47;
      }
      return result;
    }
    v49 = v3->world_y;
    LODWORD(v3->collisionAvoidanceDistance) = 0;
    v50 = floor(v49) - -0.5;
    v51 = floor(v3->world_x) - -0.5;
    if( PathingSystem::passable(&pathSystem, v3, v51, v50, 1) )
    {
      v52 = v3->vfptr;
      v53 = v3->world_z;
      v54 = floor(v3->world_y) - -0.5;
      v55 = floor(v3->world_x) - -0.5;
      (*(void (__stdcall **)(_DWORD, _DWORD, float))&v52->gap4[48])(
        LODWORD(v55),
        LODWORD(v54),
        COERCE_FLOAT(LODWORD(v53)));
    }
    if( v3->targetIDValue != -1 )
    {
      v56 = RGE_Game_World::object(v3->owner->world, v3->targetIDValue);
      if( v56 )
      {
        v57 = v3->master_obj;
        v58 = v57->radius_y;
        v59 = v56->world_x;
        v60 = v56->world_y;
        targetDX = v57->radius_x;
        v61 = v59 - v3->world_x;
        v62 = v60 - v3->world_y;
        v63 = targetDX * targetDX;
        targetDX = v61;
        v64 = v62;
        v65 = v61 * targetDX;
        v66 = sqrt(v63 + v58 * v58);
        targetDX = v66;
        v67 = sqrt(v65 + v62 * v64);
        v68 = v66 + v3->actionRange;
        targetDX = v67;
        if( v68 - -0.30000001 > v67 )
          return 5;
      }
    }
    if( !PathingSystem::passable(&pathSystem, v3, x, y, 1) )
      return 2;
    v69 = v3->continueCounter - 1;
    v3->continueCounter = v69;
    if( v69 <= 0 )
      return 4;
    if( !RGE_Player::availablePathingAttempts(v3->owner, v3->numberWaitDelays) )
    {
      ++v3->numberWaitDelays;
      return 1;
    }
    RGE_Player::incrementPathingAttempts(v3->owner);
    v3->startValue.x = v3->world_x;
    v3->startValue.y = v3->world_y;
    v3->startValue.z = v3->world_z;
    v3->numberWaitDelays = 0;
    PathingSystem::incrementContinuePaths(&pathSystem);
    if( v3->numberUserDefinedWaypointsValue <= 0 )
    {
      v150 = -3.595386269724631e308/*NaN*/;
      *(_QWORD *)&v149 = 4294967297i64;
      v148 = 4294967297i64;
      v147 = v3->targetIDValue;
      v146 = v3->actionRange;
      v145 = v3;
      v144 = (signed __int64)v3->goalValue.y;
      v143 = (signed __int64)v3->goalValue.x;
    }
    else
    {
      v70 = v3->userDefinedWaypoints;
      v150 = -3.595386269724631e308/*NaN*/;
      *(_QWORD *)&v149 = 4294967297i64;
      v148 = 4294967297i64;
      v147 = v3->targetIDValue;
      v146 = v3->actionRange;
      v145 = v3;
      v144 = v70->y;
      v143 = v70->x;
    }
    targetDX = COERCE_FLOAT(PathingSystem::findTilePath(&pathSystem, (signed __int64)v3->startValue.x, (signed __int64)v3->startValue.y, v143, v144, v145, v146, v147, 1, 0, v148, SHIDWORD(v148), SLODWORD(v149), SHIDWORD(v149), SLODWORD(v150), SHIDWORD(v150)));
    if( actionFile )
    {
      fprintf(
        actionFile,
        aTLdUidDFp1S6_2,
        v3->owner->world->world_time,
        v3->id,
        v3->startValue.x,
        v3->startValue.y,
        v3->goalValue.x,
        v3->goalValue.y);
      Path::initToStart(&v3->pathValue);
      v71 = 0;
      while( v71 < Path::numberOfWaypoints(&v3->pathValue) )
      {
        v72 = Path::currentWaypoint(&v3->pathValue)->y;
        v73 = Path::currentWaypoint(&v3->pathValue)->x;
        fprintf(actionFile, aWpD6_2f6_2f, v71++, v73, v72);
        Path::moveToNextWaypoint(&v3->pathValue);
      }
      fprintf(actionFile, a_);
      Path::initToStart(&v3->pathValue);
      Path::moveToNextWaypoint(&v3->pathValue);
    }
    if( targetDX == 0.0 && Path::numberOfWaypoints(&v3->pathValue) == 1 )
    {
      v74 = floor(v3->world_y) - -0.5;
      v75 = floor(v3->world_x) - -0.5;
      if( PathingSystem::passable(&pathSystem, v3, v75, v74, 1) )
      {
        v161 = v3->world_x;
        v76 = floor(v161);
        if( v161 - v76 == 0.5 )
        {
          v161 = v3->world_y;
          v77 = floor(v161);
          if( v161 - v77 == 0.5 )
            return 4;
        }
        v78 = v3->vfptr;
        v79 = v3->world_z;
        v80 = floor(v3->world_y) - -0.5;
        v81 = floor(v3->world_x) - -0.5;
        (*(void (__stdcall **)(_DWORD, _DWORD, float))&v78->gap4[48])(
          LODWORD(v81),
          LODWORD(v80),
          COERCE_FLOAT(LODWORD(v79)));
      }
    }
    v82 = displayPathObjectID;
    if( displayPathingFlags && v3->selected & 1 )
    {
      Path::initToStart(&v3->pathValue);
      targetDX = 0.0;
      if( Path::numberOfWaypoints(&v3->pathValue) > 0 )
      {
        v83 = 4 * v82;
        LODWORD(v161) = v83;
        do
        {
          v84 = *(float *)&v3->owner;
          v85 = **(float **)(*(_DWORD *)(LODWORD(v84) + 36) + v83);
          v86 = Path::currentWaypoint(&v3->pathValue)->y;
          v87 = Path::currentWaypoint(&v3->pathValue)->x;
          v88 = v84;
          v89 = *(_DWORD *)(LODWORD(v84) + 36);
          v90 = v85;
          v83 = LODWORD(v161);
          (*(void (__thiscall **)(_DWORD, float, float, float, signed int))(LODWORD(v90) + 24))(
            *(_DWORD *)(v89 + LODWORD(v161)),
            COERCE_FLOAT(LODWORD(v88)),
            COERCE_FLOAT(LODWORD(v87)),
            COERCE_FLOAT(LODWORD(v86)),
            1065353216);
          ++LODWORD(targetDX);
          Path::moveToNextWaypoint(&v3->pathValue);
          v91 = Path::numberOfWaypoints(&v3->pathValue);
        }
        while( SLODWORD(targetDX) < v91 );
      }
      Path::initToStart(&v3->pathValue);
      Path::moveToNextWaypoint(&v3->pathValue);
    }
    Path::initToStart(&v3->pathValue);
    if( !Path::moveToNextWaypoint(&v3->pathValue) )
      return 4;
    v92 = HIDWORD(curDistance);
    LODWORD(v3->closestDistanceToWaypoint) = 1203982336;
    v93 = &v3->pathValue;
    if( v92 == 1 )
    {
      targetDYa = Path::currentWaypoint(v93)->x - v3->world_x;
      v94 = Path::currentWaypoint(&v3->pathValue)->y - v3->world_y;
    }
    else
    {
      v95 = Path::currentWaypoint(v93);
      targetDYa = v95->x - (floor(v3->world_x) - -0.5);
      v96 = Path::currentWaypoint(&v3->pathValue);
      v94 = v96->y - (floor(v3->world_y) - -0.5);
    }
    newAngle = atan2(targetDYa, v94);
    RGE_Moving_Object::boundAngle(&newAngle, -1);
    v97 = v3->turnTimer;
    v98 = &v3->angle;
    v100 = (newAngle - v3->angle) * dY * 0.15915494;
    if( !(v101 | v102) )
    {
      LODWORD(v3->speed) = 0;
      return 0;
    }
    do
    {
      if( v100 <= 0.9 && v100 >= -0.9 )
        break;
      v3->turnTimer = *(float *)&v3->master_obj[1].string_id + v3->turnTimer;
      v104 = v100;
      v105 = (double)numFacets_4;
      if( v106 )
      {
        v107 = v104 - -1.0;
        v108 = v105;
        v100 = v107;
        v109 = *v98 - 6.2831853 / v108;
      }
      else
      {
        v110 = v104 - 1.0;
        v111 = v105;
        v100 = v110;
        v109 = 6.2831853 / v111 + *v98;
      }
      *v98 = v109;
    }
    while( v3->turnTimer <= 0.0 );
    RGE_Moving_Object::boundAngle(&v3->angle, numFacets_4);
    RGE_Moving_Object::set_angle(v3);
    v112 = sin(*v98);
    v113 = cos(*v98);
    *(float *)&v161 = v113;
    v114 = v3->world_y;
    v115 = v3->world_x;
    targetDX = v112 * distanceToCover;
    v116 = v113 * distanceToCover;
    dY = v114 + targetDX;
    v117 = dY;
    dY = v115 + v116;
    newY = v117;
    v118 = dY;
    v119 = targetDX;
    v3->velocity_x = v116;
    v3->velocity_y = v119;
    *(float *)&curDistance = v118;
    if( !PathingSystem::passable(&pathSystem, v3, v118, v117, 1) )
    {
      if( RGE_Player::computerPlayer(v3->owner) == 1 )
      {
        result = 4;
      }
      else
      {
        if( v3->speed <= 0.0 )
        {
          LODWORD(v161) = debug_rand(aCMsdevWorkA_24, 2005) % 6;
          v120 = (double)SLODWORD(v161) * 0.1 - -0.5;
        }
        else
        {
          LODWORD(v161) = debug_rand(aCMsdevWorkA_24, 2003) % 6;
          v120 = (double)SLODWORD(v161) * 0.1 - -0.5 / v3->speed;
        }
        v3->collisionAvoidanceDistance = v120;
        LODWORD(v3->speed) = 0;
        result = 0;
      }
      return result;
    }
    v42 = LODWORD(curDistance);
  }
  HIDWORD(curDistance) = LODWORD(v3->world_z);
  if( Path::currentWaypoint(&v3->pathValue) )
  {
    targetDX = Path::currentWaypoint(&v3->pathValue)->x - v3->world_x;
    v121 = Path::currentWaypoint(&v3->pathValue)->y - v3->world_y;
    dY = v121;
    *(float *)&curDistance = sqrt(targetDX * targetDX + v121 * dY);
    targetDX = Path::currentWaypoint(&v3->pathValue)->x - (v3->world_x + v3->velocity_x);
    v122 = Path::currentWaypoint(&v3->pathValue)->y - (v3->world_y + v3->velocity_y);
    v161 = targetDX;
    v123 = v3->closestDistanceToWaypoint;
    v124 = sqrt(targetDX * targetDX + v122 * v122);
    *(float *)&v161 = v124;
    if( (v123 >= v124 || *(float *)&curDistance >= 0.25)
      && ((v125 = v3->lastFacet2, v125 != v3->facet) || v125 == v3->lastFacet || *(float *)&curDistance >= 0.5) )
    {
      v132 = v3->velocity_z + v3->world_z;
      (*(void (__thiscall **)(RGE_Moving_Object *, int, _DWORD, _DWORD))&v3->vfptr->gap4[48])(
        v3,
        v42,
        LODWORD(newY),
        LODWORD(v132));
    }
    else
    {
      v126 = Path::currentWaypoint(&v3->pathValue)->y;
      v127 = Path::currentWaypoint(&v3->pathValue);
      if( !PathingSystem::passable(&pathSystem, v3, v127->x, v126, 1) )
        return 2;
      v128 = v3->vfptr;
      v129 = Path::currentWaypoint(&v3->pathValue)->z;
      v130 = Path::currentWaypoint(&v3->pathValue)->y;
      v131 = Path::currentWaypoint(&v3->pathValue);
      (*(void (__thiscall **)(RGE_Moving_Object *, _DWORD, float, float))&v128->gap4[48])(
        v3,
        LODWORD(v131->x),
        COERCE_FLOAT(LODWORD(v130)),
        COERCE_FLOAT(LODWORD(v129)));
    }
  }
  else
  {
    v133 = y - newY;
    dY = v133;
    v161 = x - *(float *)&curDistance;
    v134 = v3->vfptr;
    v135 = v3->velocity_z + v3->world_z;
    *(float *)&curDistance = sqrt(v161 * v161 + v133 * dY);
    (*(void (__thiscall **)(RGE_Moving_Object *, int, _DWORD, _DWORD))&v134->gap4[48])(
      v3,
      v42,
      LODWORD(newY),
      LODWORD(v135));
  }
  v136 = *((float *)&curDistance + 1) - v3->world_z;
  v137 = *(float *)&curDistance;
  v138 = v3->lastFacet;
  targetDYb = 1.0;
  v3->lastFacet = v3->facet;
  v3->lastFacet2 = v138;
  v3->closestDistanceToWaypoint = v137;
  if( v140 )
  {
    targetDYb = 0.89999998;
  }
  else if( v136 <= 0.02 )
  {
    v141 = v3->sprite;
    if( v141 && v141->base_speed > 0.0 )
      v3->speed = *(float *)&v3->master_obj[1].vfptr * v141->base_speed;
    else
      LODWORD(v3->speed) = v3->master_obj[1].vfptr;
  }
  else
  {
    targetDYb = 1.03;
  }
  v142 = v3->tile;
  if( v142 )
    targetDYb = RGE_Static_Object::get_terrain_speed((RGE_Static_Object *)&v3->vfptr, *((_BYTE *)v142 + 5) & 0x1F)
              * targetDYb;
  if( targetDYb > 0.0 )
    v3->speed = targetDYb * v3->speed;
  return 0;
}
// 584C58: using guessed type int displayPathObjectID;
// 62E668: using guessed type int displayPathingFlags;

//----- (0045F7F0) --------------------------------------------------------
int __thiscall RGE_Moving_Object::passableTile(RGE_Moving_Object *this, float x, float y, int aiCheck)
{
  PathingSystem *v4; // ecx@1
  RGE_Moving_Object *v6; // [sp-10h] [bp-10h]@1

  v6 = this;
  v4 = &aiPathSystem;
  if( !aiCheck )
    v4 = &pathSystem;
  return PathingSystem::passable(v4, v6, x, y, 1);
}

//----- (0045F820) --------------------------------------------------------
int __thiscall RGE_Moving_Object::canPath(RGE_Moving_Object *this, XYZPoint p, float aRange, int targetID, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID)
{
  int v8; // ebx@1
  RGE_Moving_Object *v9; // esi@1
  RGE_Game_World *v10; // eax@3
  RGE_Map *v11; // ecx@3
  RGE_Zone_Map *v12; // edi@7
  int result; // eax@11

  v8 = p.x;
  v9 = this;
  if( p.x < 0 )
    goto LABEL_16;
  if( p.y < 0 )
    goto LABEL_16;
  v10 = this->owner->world;
  v11 = v10->map;
  if( p.x >= v11->map_width || p.y >= v11->map_height )
    goto LABEL_16;
  if( v9->zoneMapIndex == -1 )
    RGE_Zone_Map_List::get_zone_map(
      v11->map_zones,
      v10->terrains[v9->master_obj->terrain],
      v10->terrain_size,
      &v9->zoneMapIndex);
  v12 = RGE_Zone_Map_List::get_zone_map(v9->owner->world->map->map_zones, v9->zoneMapIndex);
  if( v12
    && ((p.x = (unsigned __int8)RGE_Zone_Map::get_zone_info(
                                  v12,
                                  (signed __int64)v9->world_x,
                                  (signed __int64)v9->world_y),
         (unsigned __int8)RGE_Zone_Map::get_zone_info(v12, v8, p.y) == p.x)
     || RGE_Zone_Map::withinRange(
          v12,
          (XYPoint)__PAIR__((signed __int64)v9->world_y, (unsigned int)(signed __int64)v9->world_x),
          (XYPoint)__PAIR__(p.y, v8),
          aRange)) )
  {
    if( aiCheck )
    {
      PathingSystem::incrementCanPaths(&aiPathSystem);
      result = PathingSystem::findTilePath(
                 &aiPathSystem,
                 (signed __int64)v9->world_x,
                 (signed __int64)v9->world_y,
                 v8,
                 p.y,
                 v9,
                 aRange,
                 targetID,
                 0,
                 pathDistance,
                 1,
                 1,
                 1,
                 1,
                 unobstructiblePlayerID,
                 unobstructibleGroupID);
    }
    else
    {
      PathingSystem::incrementCanPaths(&pathSystem);
      result = PathingSystem::findTilePath(
                 &pathSystem,
                 (signed __int64)v9->world_x,
                 (signed __int64)v9->world_y,
                 v8,
                 p.y,
                 v9,
                 aRange,
                 targetID,
                 0,
                 pathDistance,
                 1,
                 1,
                 1,
                 1,
                 unobstructiblePlayerID,
                 unobstructibleGroupID);
    }
  }
  else
  {
LABEL_16:
    result = 0;
  }
  return result;
}

//----- (0045F9D0) --------------------------------------------------------
RGE_Zone_Map *__thiscall RGE_Moving_Object::canPath(RGE_Moving_Object *this, int targetID, float aRange, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID)
{
  RGE_Moving_Object *v7; // esi@1
  RGE_Zone_Map *result; // eax@1
  RGE_Zone_Map *v9; // edi@1
  RGE_Zone_Map *v10; // ebx@4
  int v11; // ebp@5
  XYPoint ST4C_8_6; // ST4C_8@6

  v7 = this;
  result = (RGE_Zone_Map *)RGE_Game_World::object(this->owner->world, targetID);
  v9 = result;
  if( result )
  {
    if( v7->zoneMapIndex == -1 )
      RGE_Zone_Map_List::get_zone_map(
        v7->owner->world->map->map_zones,
        v7->owner->world->terrains[v7->master_obj->terrain],
        v7->owner->world->terrain_size,
        &v7->zoneMapIndex);
    result = RGE_Zone_Map_List::get_zone_map(v7->owner->world->map->map_zones, v7->zoneMapIndex);
    v10 = result;
    if( result )
    {
      v11 = (unsigned __int8)RGE_Zone_Map::get_zone_info(
                               result,
                               (signed __int64)v7->world_x,
                               (signed __int64)v7->world_y);
      if( (unsigned __int8)RGE_Zone_Map::get_zone_info(
                              v10,
                              (signed __int64)*(float *)&v9->numberTilesInZoneValue[14],
                              (signed __int64)*(float *)&v9->numberTilesInZoneValue[15]) == v11
        || (ST4C_8_6.x = (signed __int64)v7->world_x,
            ST4C_8_6.y = (signed __int64)v7->world_y,
            (result = (RGE_Zone_Map *)RGE_Zone_Map::withinRange(
                                        v10,
                                        ST4C_8_6,
                                        (XYPoint)__PAIR__(
                                                   (signed __int64)*(float *)&v9->numberTilesInZoneValue[15],
                                                   (unsigned int)(signed __int64)*(float *)&v9->numberTilesInZoneValue[14]),
                                        aRange)) != 0) )
      {
        if( aiCheck )
        {
          PathingSystem::incrementCanPaths(&aiPathSystem);
          result = (RGE_Zone_Map *)PathingSystem::findTilePath(
                                     &aiPathSystem,
                                     (signed __int64)v7->world_x,
                                     (signed __int64)v7->world_y,
                                     (signed __int64)*(float *)&v9->numberTilesInZoneValue[14],
                                     (signed __int64)*(float *)&v9->numberTilesInZoneValue[15],
                                     v7,
                                     aRange,
                                     targetID,
                                     0,
                                     pathDistance,
                                     1,
                                     1,
                                     1,
                                     1,
                                     unobstructiblePlayerID,
                                     unobstructibleGroupID);
        }
        else
        {
          PathingSystem::incrementCanPaths(&pathSystem);
          result = (RGE_Zone_Map *)PathingSystem::findTilePath(
                                     &pathSystem,
                                     (signed __int64)v7->world_x,
                                     (signed __int64)v7->world_y,
                                     (signed __int64)*(float *)&v9->numberTilesInZoneValue[14],
                                     (signed __int64)*(float *)&v9->numberTilesInZoneValue[15],
                                     v7,
                                     aRange,
                                     targetID,
                                     0,
                                     pathDistance,
                                     1,
                                     1,
                                     1,
                                     1,
                                     unobstructiblePlayerID,
                                     unobstructibleGroupID);
        }
      }
    }
  }
  return result;
}

//----- (0045FBC0) --------------------------------------------------------
int __thiscall RGE_Moving_Object::canBidirectionPath(RGE_Moving_Object *this, int targetID, int targetID2, float aRange, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID)
{
  RGE_Moving_Object *v8; // esi@1
  RGE_Static_Object *v9; // edi@1
  RGE_Static_Object *v10; // eax@1
  RGE_Static_Object *v11; // ebx@1
  RGE_Zone_Map *v12; // ebp@5
  int start; // ST4C_4@6
  XYPoint v14; // ST4C_8@7
  int result; // eax@9
  int v16; // ST0C_4@11
  int v17; // ST08_4@11
  int v18; // ST04_4@11
  double v19; // st7@11
  int v20; // ST0C_4@14
  int v21; // ST08_4@14
  int v22; // ST04_4@14
  double v23; // st7@14

  v8 = this;
  v9 = RGE_Game_World::object(this->owner->world, targetID);
  v10 = RGE_Game_World::object(v8->owner->world, targetID2);
  v11 = v10;
  if( !v9 || !v10 )
    goto LABEL_18;
  if( v8->zoneMapIndex == -1 )
    RGE_Zone_Map_List::get_zone_map(
      v8->owner->world->map->map_zones,
      v8->owner->world->terrains[v8->master_obj->terrain],
      v8->owner->world->terrain_size,
      &v8->zoneMapIndex);
  v12 = RGE_Zone_Map_List::get_zone_map(v8->owner->world->map->map_zones, v8->zoneMapIndex);
  if( v12
    && ((start = (unsigned __int8)RGE_Zone_Map::get_zone_info(
                                    v12,
                                    (signed __int64)v8->world_x,
                                    (signed __int64)v8->world_y),
         (unsigned __int8)RGE_Zone_Map::get_zone_info(v12, (signed __int64)v9->world_x, (signed __int64)v9->world_y) == start)
     || (v14.x = (signed __int64)v8->world_x,
         v14.y = (signed __int64)v8->world_y,
         RGE_Zone_Map::withinRange(
           v12,
           v14,
           (XYPoint)__PAIR__((signed __int64)v9->world_y, (unsigned int)(signed __int64)v9->world_x),
           aRange))) )
  {
    v8->storePathInExceptionPath = 1;
    if( aiCheck )
    {
      PathingSystem::incrementCanPaths(&aiPathSystem);
      result = PathingSystem::findTilePath(
                 &aiPathSystem,
                 (signed __int64)v8->world_x,
                 (signed __int64)v8->world_y,
                 (signed __int64)v9->world_x,
                 (signed __int64)v9->world_y,
                 v8,
                 aRange,
                 targetID,
                 1,
                 pathDistance,
                 1,
                 1,
                 1,
                 1,
                 unobstructiblePlayerID,
                 unobstructibleGroupID);
      if( result )
      {
        v16 = (signed __int64)v11->world_y;
        v17 = (signed __int64)v11->world_x;
        v18 = (signed __int64)Path::lastWaypoint(&v8->exceptionPathValue)->y;
        v19 = Path::lastWaypoint(&v8->exceptionPathValue)->x;
        result = PathingSystem::findTilePath(
                   &aiPathSystem,
                   (signed __int64)v19,
                   v18,
                   v17,
                   v16,
                   v8,
                   aRange,
                   targetID2,
                   0,
                   pathDistance,
                   1,
                   1,
                   1,
                   1,
                   unobstructiblePlayerID,
                   unobstructibleGroupID);
        v8->storePathInExceptionPath = 0;
      }
      else
      {
        v8->storePathInExceptionPath = 0;
      }
    }
    else
    {
      PathingSystem::incrementCanPaths(&pathSystem);
      result = PathingSystem::findTilePath(
                 &pathSystem,
                 (signed __int64)v8->world_x,
                 (signed __int64)v8->world_y,
                 (signed __int64)v9->world_x,
                 (signed __int64)v9->world_y,
                 v8,
                 aRange,
                 targetID,
                 1,
                 pathDistance,
                 1,
                 1,
                 1,
                 1,
                 unobstructiblePlayerID,
                 unobstructibleGroupID);
      if( result )
      {
        v20 = (signed __int64)v11->world_y;
        v21 = (signed __int64)v11->world_x;
        v22 = (signed __int64)Path::lastWaypoint(&v8->exceptionPathValue)->y;
        v23 = Path::lastWaypoint(&v8->exceptionPathValue)->x;
        result = PathingSystem::findTilePath(
                   &pathSystem,
                   (signed __int64)v23,
                   v22,
                   v21,
                   v20,
                   v8,
                   aRange,
                   targetID2,
                   0,
                   pathDistance,
                   1,
                   1,
                   1,
                   1,
                   unobstructiblePlayerID,
                   unobstructibleGroupID);
        v8->storePathInExceptionPath = 0;
      }
      else
      {
        v8->storePathInExceptionPath = 0;
      }
    }
  }
  else
  {
LABEL_18:
    result = 0;
  }
  return result;
}

//----- (0045FED0) --------------------------------------------------------
RGE_Zone_Map *__thiscall RGE_Moving_Object::canPathWithObstructions(RGE_Moving_Object *this, int targetID, float aRange, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID, ManagedArray<int> *obstructions)
{
  RGE_Moving_Object *v8; // esi@1
  RGE_Zone_Map *result; // eax@1
  RGE_Zone_Map *v10; // edi@1
  RGE_Zone_Map *v11; // ebp@4
  int v12; // ebx@5
  XYPoint ST4C_8_6; // ST4C_8@6
  RGE_Zone_Map *v14; // edi@8

  v8 = this;
  result = (RGE_Zone_Map *)RGE_Game_World::object(this->owner->world, targetID);
  v10 = result;
  if( result )
  {
    if( v8->zoneMapIndex == -1 )
      RGE_Zone_Map_List::get_zone_map(
        v8->owner->world->map->map_zones,
        v8->owner->world->terrains[v8->master_obj->terrain],
        v8->owner->world->terrain_size,
        &v8->zoneMapIndex);
    result = RGE_Zone_Map_List::get_zone_map(v8->owner->world->map->map_zones, v8->zoneMapIndex);
    v11 = result;
    if( result )
    {
      v12 = (unsigned __int8)RGE_Zone_Map::get_zone_info(
                               result,
                               (signed __int64)v8->world_x,
                               (signed __int64)v8->world_y);
      if( (unsigned __int8)RGE_Zone_Map::get_zone_info(
                              v11,
                              (signed __int64)*(float *)&v10->numberTilesInZoneValue[14],
                              (signed __int64)*(float *)&v10->numberTilesInZoneValue[15]) == v12
        || (ST4C_8_6.x = (signed __int64)v8->world_x,
            ST4C_8_6.y = (signed __int64)v8->world_y,
            (result = (RGE_Zone_Map *)RGE_Zone_Map::withinRange(
                                        v11,
                                        ST4C_8_6,
                                        (XYPoint)__PAIR__(
                                                   (signed __int64)*(float *)&v10->numberTilesInZoneValue[15],
                                                   (unsigned int)(signed __int64)*(float *)&v10->numberTilesInZoneValue[14]),
                                        aRange)) != 0) )
      {
        v8->storePathInExceptionPath = 1;
        if( aiCheck )
        {
          PathingSystem::incrementCanPaths(&aiPathSystem);
          v14 = (RGE_Zone_Map *)PathingSystem::findTilePath(
                                  &aiPathSystem,
                                  (signed __int64)v8->world_x,
                                  (signed __int64)v8->world_y,
                                  (signed __int64)*(float *)&v10->numberTilesInZoneValue[14],
                                  (signed __int64)*(float *)&v10->numberTilesInZoneValue[15],
                                  v8,
                                  aRange,
                                  targetID,
                                  1,
                                  pathDistance,
                                  1,
                                  1,
                                  1,
                                  1,
                                  unobstructiblePlayerID,
                                  unobstructibleGroupID);
          if( unobstructibleGroupID != -1 )
            PathingSystem::copyUnobstructibles(&aiPathSystem, obstructions);
        }
        else
        {
          PathingSystem::incrementCanPaths(&pathSystem);
          v14 = (RGE_Zone_Map *)PathingSystem::findTilePath(
                                  &pathSystem,
                                  (signed __int64)v8->world_x,
                                  (signed __int64)v8->world_y,
                                  (signed __int64)*(float *)&v10->numberTilesInZoneValue[14],
                                  (signed __int64)*(float *)&v10->numberTilesInZoneValue[15],
                                  v8,
                                  aRange,
                                  targetID,
                                  1,
                                  pathDistance,
                                  1,
                                  1,
                                  1,
                                  1,
                                  unobstructiblePlayerID,
                                  unobstructibleGroupID);
          if( unobstructibleGroupID != -1 )
            PathingSystem::copyUnobstructibles(&pathSystem, obstructions);
        }
        result = v14;
        v8->storePathInExceptionPath = 0;
      }
    }
  }
  return result;
}

//----- (004600F0) --------------------------------------------------------
int __thiscall RGE_Moving_Object::canPathWithAdditionalPassability(RGE_Moving_Object *this, XYZPoint p, float aRange, int targetID, float *pathDistance, int eTerrain1, int eTerrain2, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID)
{
  RGE_Moving_Object *v10; // esi@1
  RGE_Map *v11; // eax@3
  PathingSystem *v12; // ecx@6
  int result; // eax@8
  int v14; // [sp-3Ch] [bp-48h]@6
  int v15; // [sp-38h] [bp-44h]@6
  int v16; // [sp-34h] [bp-40h]@6
  int v17; // [sp-30h] [bp-3Ch]@6
  RGE_Moving_Object *v18; // [sp-2Ch] [bp-38h]@6
  float v19; // [sp-28h] [bp-34h]@6
  int v20; // [sp-24h] [bp-30h]@6
  float *v21; // [sp-1Ch] [bp-28h]@6
  int v22; // [sp-8h] [bp-14h]@6
  int v23; // [sp-4h] [bp-10h]@6

  v10 = this;
  if( p.x < 0 || p.y < 0 || (v11 = this->owner->world->map, p.x >= v11->map_width) || p.y >= v11->map_height )
  {
    result = 0;
  }
  else
  {
    this->currentTerrainException2 = eTerrain2;
    this->currentTerrainException1 = eTerrain1;
    this->storePathInExceptionPath = 1;
    if( aiCheck )
    {
      PathingSystem::incrementCanPaths(&aiPathSystem);
      v23 = unobstructibleGroupID;
      v22 = unobstructiblePlayerID;
      v21 = pathDistance;
      v20 = targetID;
      v19 = aRange;
      v18 = v10;
      v17 = p.y;
      v16 = p.x;
      v15 = (signed __int64)v10->world_y;
      v14 = (signed __int64)v10->world_x;
      v12 = &aiPathSystem;
    }
    else
    {
      PathingSystem::incrementCanPaths(&pathSystem);
      v23 = unobstructibleGroupID;
      v22 = unobstructiblePlayerID;
      v21 = pathDistance;
      v20 = targetID;
      v19 = aRange;
      v18 = v10;
      v17 = p.y;
      v16 = p.x;
      v15 = (signed __int64)v10->world_y;
      v14 = (signed __int64)v10->world_x;
      v12 = &pathSystem;
    }
    result = PathingSystem::findTilePath(v12, v14, v15, v16, v17, v18, v19, v20, 1, v21, 1, 1, 1, 1, v22, v23);
    v10->storePathInExceptionPath = 0;
    v10->currentTerrainException1 = -1;
    v10->currentTerrainException2 = -1;
  }
  return result;
}

//----- (00460210) --------------------------------------------------------
int __thiscall RGE_Moving_Object::findFirstTerrainAlongExceptionPath(RGE_Moving_Object *this, int eTerrain, float *rX, float *rY)
{
  RGE_Moving_Object *v4; // ebx@1
  Path *v5; // esi@1
  int (__thiscall *v6)(RGE_Static_Object *, XYPoint *, XYPoint *, XYPoint *, int, int, int); // ebp@5
  int result; // eax@10
  double v8; // st7@11
  int i; // [sp+18h] [bp-1Ch]@4
  XYPoint p1; // [sp+1Ch] [bp-18h]@3
  XYPoint p2; // [sp+24h] [bp-10h]@4
  XYPoint rVal; // [sp+2Ch] [bp-8h]@6

  v4 = this;
  v5 = &this->exceptionPathValue;
  if( Path::numberOfWaypoints(&this->exceptionPathValue) < 2 )
    return 0;
  Path::initToStart(v5);
  if( !Path::currentWaypoint(v5) )
    return 0;
  p1.x = (signed __int64)Path::currentWaypoint(v5)->x;
  p1.y = (signed __int64)Path::currentWaypoint(v5)->y;
  Path::moveToNextWaypoint(v5);
  if( !Path::currentWaypoint(v5) )
    return 0;
  p2.x = (signed __int64)Path::currentWaypoint(v5)->x;
  p2.y = (signed __int64)Path::currentWaypoint(v5)->y;
  i = 1;
  if( Path::numberOfWaypoints(v5) <= 1 )
  {
LABEL_9:
    *(_DWORD *)rX = -1082130432;
    *(_DWORD *)rY = -1082130432;
    return 0;
  }
  v6 = v4->vfptr->firstTileAlongLine;
  while( v6((RGE_Static_Object *)&v4->vfptr, &p1, &p2, &rVal, eTerrain, eTerrain, 1) != 1 )
  {
    p1.x = (signed __int64)Path::currentWaypoint(v5)->x;
    p1.y = (signed __int64)Path::currentWaypoint(v5)->y;
    Path::moveToNextWaypoint(v5);
    if( !Path::currentWaypoint(v5) )
      return 0;
    p2.x = (signed __int64)Path::currentWaypoint(v5)->x;
    p2.y = (signed __int64)Path::currentWaypoint(v5)->y;
    if( ++i >= Path::numberOfWaypoints(v5) )
      goto LABEL_9;
  }
  v8 = (double)rVal.x - -0.5;
  result = 1;
  *rX = v8;
  *rY = v8;
  return result;
}

//----- (004603B0) --------------------------------------------------------
int __thiscall RGE_Moving_Object::canLinePath(RGE_Moving_Object *this, XYPoint *s, XYPoint *d, float range, XYPoint *rPoint, int aiCheck)
{
  RGE_Moving_Object *v6; // ebx@1
  long double v7; // st7@1
  long double v8; // st6@1
  int v10; // eax@5
  long double v11; // st5@7
  double v12; // st7@7
  signed int v13; // ebp@7
  double v14; // st6@8
  int v15; // esi@8
  signed __int64 v16; // rax@8
  double v17; // st6@11
  double v18; // st7@11
  float v19; // ST28_4@11
  int yTile; // [sp+Ch] [bp-1Ch]@1
  float yTilea; // [sp+Ch] [bp-1Ch]@7
  int numSteps; // [sp+10h] [bp-18h]@5
  int priorY; // [sp+14h] [bp-14h]@7
  int i; // [sp+1Ch] [bp-Ch]@7
  float xStep; // [sp+20h] [bp-8h]@7
  float yStep; // [sp+24h] [bp-4h]@7
  XYPoint *sa; // [sp+2Ch] [bp+4h]@7

  v6 = this;
  v7 = (double)(d->x - s->x);
  yTile = s->y;
  v8 = (double)(d->y - yTile);
  if( v7 == 0.0 && v8 == 0.0 )
    return 0;
  if( fabs(v7) >= fabs(v8) )
  {
    v10 = 2 * abs((signed __int64)v7);
    numSteps = v10;
  }
  else
  {
    v10 = 2 * abs((signed __int64)v8);
    numSteps = v10;
  }
  v11 = v7;
  v12 = (double)numSteps;
  v13 = -999;
  i = 0;
  priorY = -999;
  xStep = v11 / v12;
  yStep = v8 / v12;
  *(float *)&sa = (double)s->x;
  yTilea = (double)yTile;
  if( v10 > 0 )
  {
    while( 1 )
    {
      v14 = *(float *)&sa + xStep;
      *(float *)&sa = v14;
      yTilea = yTilea + yStep;
      v15 = (signed __int64)v14;
      v16 = (signed __int64)yTilea;
      if( v15 != v13 || (_DWORD)v16 != priorY )
      {
        v13 = (signed __int64)v14;
        priorY = (signed __int64)yTilea;
        if( !((int (__thiscall *)(RGE_Moving_Object *, XYPoint *, float, int))v6->vfptr->passableTile)(
                v6,
                sa,
                COERCE_FLOAT(LODWORD(yTilea)),
                aiCheck) )
        {
          rPoint->x = v15;
          rPoint->y = (signed __int64)yTilea;
          return 0;
        }
        v17 = (double)d->x - *(float *)&sa;
        v18 = (double)d->y - yTilea;
        v19 = v17;
        if( sqrt(v17 * v19 + v18 * v18) <= range )
          return 1;
      }
      if( ++i >= numSteps )
        return 1;
    }
  }
  return 1;
}

//----- (00460570) --------------------------------------------------------
int __thiscall RGE_Moving_Object::canLinePath(RGE_Moving_Object *this, int sX, int sY, int dX, int dY, float range, int aiCheck)
{
  RGE_Moving_Object *v7; // ebx@1
  long double v8; // st7@1
  long double v9; // st6@1
  int v11; // eax@5
  long double v12; // st5@7
  double v13; // st7@7
  signed int v14; // edi@7
  signed int v15; // ebp@7
  float xStep; // ST28_4@8
  double v17; // st6@8
  signed __int64 v18; // rax@8
  double v19; // st6@11
  float v20; // ST20_4@11
  int numSteps; // [sp+Ch] [bp-14h]@5
  int i; // [sp+14h] [bp-Ch]@7
  float yStep; // [sp+1Ch] [bp-4h]@7
  int sXa; // [sp+24h] [bp+4h]@7
  float xTile; // [sp+28h] [bp+8h]@7

  v7 = this;
  v8 = (double)(dX - sX);
  v9 = (double)(dY - sY);
  if( v8 == 0.0 && v9 == 0.0 )
    return 0;
  if( fabs(v8) >= fabs(v9) )
  {
    v11 = 2 * abs((signed __int64)v8);
    numSteps = v11;
  }
  else
  {
    v11 = 2 * abs((signed __int64)v9);
    numSteps = v11;
  }
  v12 = v8;
  v13 = (double)numSteps;
  v14 = -999;
  i = 0;
  v15 = -999;
  yStep = v9 / v13;
  *(float *)&sXa = (double)sX;
  xTile = (double)sY;
  if( v11 > 0 )
  {
    while( 1 )
    {
      xStep = v12 / v13;
      v17 = *(float *)&sXa + xStep;
      *(float *)&sXa = v17;
      xTile = xTile + yStep;
      v18 = (signed __int64)xTile;
      if( (unsigned int)(signed __int64)v17 != v14 || (_DWORD)v18 != v15 )
      {
        v15 = v18;
        v14 = (signed __int64)v17;
        if( !((int (__thiscall *)(RGE_Moving_Object *, int, float, int))v7->vfptr->passableTile)(
                v7,
                sXa,
                COERCE_FLOAT(LODWORD(xTile)),
                aiCheck) )
          return 0;
        v19 = (double)dX - *(float *)&sXa;
        v20 = v19;
        if( sqrt(v19 * v20 + ((double)dY - xTile) * ((double)dY - xTile)) <= range )
          return 1;
      }
      if( ++i >= numSteps )
        return 1;
    }
  }
  return 1;
}

//----- (00460710) --------------------------------------------------------
int __thiscall RGE_Moving_Object::firstTileAlongLine(RGE_Moving_Object *this, XYPoint *s, XYPoint *d, XYPoint *rPoint, int tType1, int tType2, int checkPassability)
{
  long double v7; // st7@1
  long double v8; // st6@1
  int result; // eax@3
  int v10; // eax@5
  long double v11; // st5@7
  double v12; // st7@7
  long double v13; // rtt@7
  long double v14; // st5@7
  signed int v15; // ebx@7
  signed int v16; // ebp@7
  float yStep; // ST28_4@8
  double v18; // st6@8
  int v19; // esi@8
  signed __int64 v20; // rax@8
  int v21; // eax@10
  int numSteps; // [sp+10h] [bp-1Ch]@5
  int i; // [sp+14h] [bp-18h]@7
  float xStep; // [sp+18h] [bp-14h]@7
  RGE_Map *map; // [sp+20h] [bp-Ch]@7
  RGE_Moving_Object *v26; // [sp+28h] [bp-4h]@1
  XYPoint *sa; // [sp+30h] [bp+4h]@7
  float yTile; // [sp+34h] [bp+8h]@7

  v7 = (double)(d->x - s->x);
  v26 = this;
  v8 = (double)(d->y - s->y);
  if( v7 != 0.0 || v8 != 0.0 )
  {
    if( fabs(v7) >= fabs(v8) )
    {
      v10 = 2 * abs((signed __int64)v7);
      numSteps = v10;
    }
    else
    {
      v10 = 2 * abs((signed __int64)v8);
      numSteps = v10;
    }
    v11 = v7;
    v12 = (double)numSteps;
    v13 = v11 / v12;
    v14 = v8;
    v15 = -999;
    v16 = -999;
    i = 0;
    map = this->owner->world->map;
    xStep = v13;
    yTile = (double)s->x;
    *(float *)&sa = (double)s->y;
    if( v10 <= 0 )
    {
      result = 0;
    }
    else
    {
      while( 1 )
      {
        v18 = yTile + xStep;
        yTile = v18;
        yStep = v14 / v12;
        *(float *)&sa = *(float *)&sa + yStep;
        v19 = (signed __int64)v18;
        v20 = (signed __int64)*(float *)&sa;
        if( v19 != v15 || (_DWORD)v20 != v16 )
        {
          v15 = (signed __int64)v18;
          v16 = (signed __int64)*(float *)&sa;
          v21 = RGE_Map::get_terrain(map, v19, v20);
          if( (v21 == tType1 || v21 == tType2)
            && checkPassability == 1
            && ((int (__stdcall *)(float, XYPoint *, _DWORD))v26->vfptr->passableTile)(
                 COERCE_FLOAT(LODWORD(yTile)),
                 sa,
                 0) == 1 )
          {
            break;
          }
        }
        if( ++i >= numSteps )
          return 0;
      }
      rPoint->x = v19;
      rPoint->y = (signed __int64)*(float *)&sa;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004608D0) --------------------------------------------------------
double __thiscall RGE_Moving_Object::maximumSpeed(RGE_Moving_Object *this)
{
  RGE_Sprite *v1; // edx@1
  double result; // st7@3

  v1 = this->sprite;
  if( v1 && v1->base_speed > 0.0 )
    result = *(float *)&this->master_obj[1].vfptr * v1->base_speed;
  else
    result = *(float *)&this->master_obj[1].vfptr;
  return result;
}

//----- (00460900) --------------------------------------------------------
char __thiscall RGE_Moving_Object::waitingToMove(RGE_Moving_Object *this)
{
  RGE_Moving_Object *v1; // esi@1
  int v2; // eax@1
  char result; // al@3

  v1 = this;
  v2 = (unsigned __int8)((int (*)(void))this->vfptr->actionState)();
  if( v2 == 6 || v2 == 7 )
    result = 0;
  else
    result = v1->waitingToMoveValue;
  return result;
}

//----- (00460930) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setWaitingToMove(RGE_Moving_Object *this, char w)
{
  this->waitingToMoveValue = w;
}

//----- (00460940) --------------------------------------------------------
XYZBYTEPoint *__thiscall RGE_Moving_Object::userDefinedWaypoint(RGE_Moving_Object *this, int v)
{
  XYZBYTEPoint *result; // eax@3

  if( v < 0 || v >= this->numberUserDefinedWaypointsValue )
    result = 0;
  else
    result = &this->userDefinedWaypoints[v];
  return result;
}

//----- (00460970) --------------------------------------------------------
int __thiscall RGE_Moving_Object::addUserDefinedWaypoint(RGE_Moving_Object *this, XYZBYTEPoint *p, int stopObject)
{
  RGE_Moving_Object *v3; // esi@1
  int v4; // ecx@3
  int v5; // eax@3
  char *v6; // ebp@7
  int v8; // eax@9
  int v9; // ecx@10
  int v10; // edi@10
  char v11; // dl@11
  int v12; // ecx@12
  char *v13; // ecx@13

  v3 = this;
  if( this->finalUserDefinedWaypoint == 1 )
  {
    ((void (__stdcall *)(int))this->vfptr->removeAllUserDefinedWaypoints)(stopObject);
    v3->finalUserDefinedWaypoint = 0;
  }
  v4 = v3->maxUserDefinedWaypointsValue;
  v5 = v3->numberUserDefinedWaypointsValue;
  if( v4 <= v5 )
  {
    if( v4 )
    {
      v6 = (char *)operator new(6 * v4);
      if( !v6 )
        return 0;
      v8 = 0;
      if( v3->numberUserDefinedWaypointsValue > 0 )
      {
        v9 = 0;
        v10 = (int)(v6 + 2);
        do
        {
          ++v8;
          v10 += 3;
          v11 = v3->userDefinedWaypoints[v9].x;
          ++v9;
          *(_BYTE *)(v10 - 5) = v11;
          *(_BYTE *)(v10 - 4) = *((_BYTE *)&v3->userDefinedWaypoints[v9] - 2);
          *(_BYTE *)(v10 - 3) = *((_BYTE *)&v3->userDefinedWaypoints[v9] - 1);
        }
        while( v8 < v3->numberUserDefinedWaypointsValue );
      }
      v12 = 2 * v3->maxUserDefinedWaypointsValue;
      v3->maxUserDefinedWaypointsValue = v12;
      if( v8 < v12 )
      {
        v13 = &v6[2 * v8 + 2] + v8;
        do
        {
          *(v13 - 2) = 0;
          *(v13 - 1) = 0;
          *v13 = 0;
          ++v8;
          v13 += 3;
        }
        while( v8 < v3->maxUserDefinedWaypointsValue );
      }
      operator delete(v3->userDefinedWaypoints);
      v3->userDefinedWaypoints = (XYZBYTEPoint *)v6;
    }
    else
    {
      v3->userDefinedWaypoints = (XYZBYTEPoint *)operator new(0xFu);
      v3->maxUserDefinedWaypointsValue = 5;
      v3->numberUserDefinedWaypointsValue = 0;
    }
    v3->userDefinedWaypoints[v3->numberUserDefinedWaypointsValue].x = p->x;
    v3->userDefinedWaypoints[v3->numberUserDefinedWaypointsValue].y = p->y;
    v3->userDefinedWaypoints[v3->numberUserDefinedWaypointsValue].z = p->z;
  }
  else
  {
    v3->userDefinedWaypoints[v5].x = p->x;
    v3->userDefinedWaypoints[v3->numberUserDefinedWaypointsValue].y = p->y;
    v3->userDefinedWaypoints[v3->numberUserDefinedWaypointsValue].z = p->z;
  }
  ++v3->numberUserDefinedWaypointsValue;
  return 1;
}

//----- (00460B20) --------------------------------------------------------
void __thiscall RGE_Moving_Object::removeAllUserDefinedWaypoints(RGE_Moving_Object *this, int stopObject)
{
  RGE_Moving_Object *v2; // esi@1

  v2 = this;
  this->numberUserDefinedWaypointsValue = 0;
  if( stopObject == 1 && this->unitAIValue )
  {
    if( actionFile )
      fprintf(actionFile, aDCallStopobjec, this->id, aCMsdevWorkA_24, 2905);
    ((void (__stdcall *)(_DWORD))v2->unitAIValue->vfptr->stopObject)(0);
  }
}

//----- (00460B70) --------------------------------------------------------
void __thiscall RGE_Moving_Object::removeUserDefinedWaypoint(RGE_Moving_Object *this, int v)
{
  int v2; // eax@2
  int i; // edi@3
  int v4; // eax@7

  if( v >= 0 )
  {
    v2 = this->numberUserDefinedWaypointsValue;
    if( v < v2 )
    {
      for( i = 0; i < v2; ++i )
      {
        if( i >= v )
          break;
      }
      if( i < v2 )
      {
        v4 = i;
        do
        {
          if( v4 * 3 )
          {
            this->userDefinedWaypoints[v4 - 1].x = this->userDefinedWaypoints[v4].x;
            *((_BYTE *)&this->userDefinedWaypoints[v4] - 2) = this->userDefinedWaypoints[v4].y;
            *((_BYTE *)&this->userDefinedWaypoints[v4] - 1) = this->userDefinedWaypoints[v4].z;
          }
          ++i;
          ++v4;
        }
        while( i < this->numberUserDefinedWaypointsValue );
      }
      --this->numberUserDefinedWaypointsValue;
    }
  }
}

//----- (00460BF0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setFinalUserDefinedWaypoint(RGE_Moving_Object *this)
{
  this->finalUserDefinedWaypoint = 1;
}

//----- (00460C00) --------------------------------------------------------
Path *__thiscall RGE_Moving_Object::findAvoidancePath(RGE_Moving_Object *this, XYZPoint *goalPoint, float aRange, int targetID)
{
  RGE_Moving_Object *v4; // esi@1
  int *v5; // edi@1
  RGE_Zone_Map *v6; // ebx@3
  int v7; // ebp@3
  Path *result; // eax@4
  double v9; // st7@5

  v4 = this;
  v5 = &this->zoneMapIndex;
  if( this->zoneMapIndex == -1 )
    RGE_Zone_Map_List::get_zone_map(
      this->owner->world->map->map_zones,
      this->owner->world->terrains[this->master_obj->terrain],
      this->owner->world->terrain_size,
      &this->zoneMapIndex);
  v6 = RGE_Zone_Map_List::get_zone_map(v4->owner->world->map->map_zones, *v5);
  v7 = (unsigned __int8)RGE_Zone_Map::get_zone_info(v6, (signed __int64)v4->world_x, (signed __int64)v4->world_y);
  if( (unsigned __int8)RGE_Zone_Map::get_zone_info(v6, goalPoint->x, goalPoint->y) == v7
    || (result = (Path *)RGE_Zone_Map::withinRange(
                           v6,
                           (XYPoint)__PAIR__((signed __int64)v4->world_y, (unsigned int)(signed __int64)v4->world_x),
                           *(XYPoint *)&goalPoint->x,
                           aRange)) != 0 )
  {
    v9 = v4->world_y;
    v4->storePathInExceptionPath = 1;
    PathingSystem::findTilePath(
      &aiPathSystem,
      (signed __int64)v4->world_x,
      (signed __int64)v9,
      goalPoint->x,
      goalPoint->y,
      v4,
      aRange,
      targetID,
      1,
      0,
      0,
      1,
      1,
      1,
      -1,
      -1);
    v4->storePathInExceptionPath = 0;
    PathingSystem::initMisc(&aiPathSystem, 0);
    result = &v4->exceptionPathValue;
  }
  return result;
}

//----- (00460D30) --------------------------------------------------------
void __thiscall RGE_Moving_Object::setInitialPoints(RGE_Moving_Object *this, XYPoint *min, XYPoint *max)
{
  this->minInitialPointValue = *min;
  this->maxInitialPointValue = *max;
}

//----- (00460D60) --------------------------------------------------------
void __thiscall RGE_Moving_Object::copy_obj(RGE_Moving_Object *this, RGE_Master_Static_Object *source2)
{
  RGE_Moving_Object *v2; // esi@1
  char *v3; // edx@1
  RGE_Master_Static_Object *v4; // eax@1
  RGE_Sprite *v5; // ecx@1

  v2 = this;
  v3 = 0;
  v4 = this->master_obj;
  v5 = this->sprite;
  if( v5 == *(RGE_Sprite **)&v4[1].master_type )
  {
    v3 = *(char **)&source2[1].master_type;
  }
  else if( v5 == (RGE_Sprite *)v4[1].name )
  {
    v3 = source2[1].name;
  }
  if( v3 )
    (*(void (__thiscall **)(RGE_Moving_Object *, char *))&v2->vfptr->gap4[52])(v2, v3);
  RGE_Static_Object::copy_obj((RGE_Static_Object *)&v2->vfptr, source2);
}

//----- (00460DB0) --------------------------------------------------------
void __stdcall RGE_Moving_Object::boundAngle(float *x, int numFacets)
{
  float *v3; // esi@1
  double v5; // st7@1
  char v6; // c0@1
  unsigned __int8 v8; // c0@5
  unsigned __int8 v9; // c3@5
  int v10; // edx@6
  int v11; // ecx@9
  double v12; // st7@10
  double v13; // st7@16
  int i; // [sp+4h] [bp-4h]@9
  float *xa; // [sp+Ch] [bp+4h]@7
  signed int bestDifference; // [sp+10h] [bp+8h]@9

  v3 = x;
  v5 = *x;
  if( v6 )
  {
    do
      v5 = v5 - -6.2831855;
    while( v5 < 0.0 );
    *x = v5;
  }
  else if( v5 > 6.2831855 )
  {
    do
      *x = *x - 6.2831855;
    while( !(v8 | v9) );
  }
  v10 = numFacets;
  if( numFacets != -1 )
  {
    *(float *)&xa = 0.78539819;
    if( numFacets != 8 )
      *(float *)&xa = 0.39269909;
    v11 = 0;
    bestDifference = -1;
    for( i = 0; v11 <= v10; i = ++v11 )
    {
      v12 = *v3 - (double)i * *(float *)&xa;
      if( v12 < 0.0 )
        v12 = -v12;
      if( v12 < *(float *)&xa )
      {
        *(float *)&xa = v12;
        bestDifference = v11;
      }
      if( *(float *)&xa < 0.1 )
        break;
    }
    v13 = (double)bestDifference;
    if( v10 == 8 )
      *v3 = v13 * 0.78539819;
    else
      *v3 = v13 * 0.39269909;
  }
}

//----- (00460EB0) --------------------------------------------------------
void __thiscall RGE_Moving_Object::rotate(RGE_Moving_Object *this, int amount)
{
  double v2; // st7@1
  char v4; // c0@1
  int amounta; // [sp+4h] [bp+4h]@1
  int amountb; // [sp+4h] [bp+4h]@6

  v2 = (double)amount * 6.2831853 / (double)this->sprite->facet_num + this->angle;
  *(float *)&amounta = v2;
  if( v4 )
  {
    do
      v2 = v2 - -6.2831855;
    while( v2 < 0.0 );
    *(float *)&amounta = v2;
  }
  if( v2 < 6.2831853 )
  {
    ((void (__stdcall *)(int))this->vfptr->new_angle)(amounta);
  }
  else
  {
    do
      v2 = v2 - 6.2831855;
    while( v2 >= 6.2831853 );
    *(float *)&amountb = v2;
    ((void (__stdcall *)(int))this->vfptr->new_angle)(amountb);
  }
}

//----- (00460F40) --------------------------------------------------------
signed __int64 __thiscall RGE_Moving_Object::get_waypoint_checksum(RGE_Moving_Object *this)
{
  Path *v1; // esi@1
  int v2; // ebx@1
  int v3; // edi@1
  Waypoint *v4; // ebp@2
  float temp; // [sp+Ch] [bp-4h]@1

  v1 = &this->pathValue;
  temp = 0.0;
  v2 = Path::currentWaypointNumber(&this->pathValue);
  Path::initToStart(v1);
  v3 = 0;
  while( v3 < Path::numberOfWaypoints(v1) )
  {
    v4 = Path::currentWaypoint(v1);
    ++v3;
    temp = v4->y + Path::currentWaypoint(v1)->x + temp;
    Path::moveToNextWaypoint(v1);
  }
  Path::setCurrentWaypointNumber(v1, v2);
  return (signed __int64)temp;
}

//----- (00460FC0) --------------------------------------------------------
int __thiscall  __thiscall `vcall'{456,{flat}}(RGE_Moving_Object *this)
{
  return ((int (*)(void))this->vfptr->numberUserDefinedWaypoints)();
}

//----- (00405F50) --------------------------------------------------------
double __thiscall RGE_Moving_Object::getAngle(RGE_Moving_Object *this)
{
  return this->angle;
}

//----- (00405F60) --------------------------------------------------------
int __thiscall RGE_Moving_Object::numberUserDefinedWaypoints(RGE_Moving_Object *this)
{
  return this->numberUserDefinedWaypointsValue;
}
