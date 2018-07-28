
/**
 * @file    Engine\TRB\AiTacticalModule.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004EA860) --------------------------------------------------------
void __thiscall TacticalAIGroup::TacticalAIGroup(TacticalAIGroup *this)
{
  TacticalAIGroup *v1; // esi@1
  int *v2; // eax@1
  signed int v3; // ecx@1

  v1 = this;
  this->idValue = -1;
  this->inUseValue = 0;
  this->typeValue = -1;
  this->subTypeValue = -1;
  this->numberUnitsValue = 0;
  this->desiredNumberUnitsValue = 0;
  this->commanderValue = -1;
  this->originalHitPointsValue = -1;
  this->originalUnitNumberValue = -1;
  this->actionValue = 0;
  this->targetValue = -1;
  this->targetTypeValue = -1;
  this->priorityValue = 0;
  this->waitCodeValue = -1;
  this->assistGroupIDValue = -1;
  this->assistGroupTypeValue = -1;
  this->consecutiveIdleUnitCountValue = 0;
  this->playNumberValue = -1;
  this->numberAttackWaypointsValue = 0;
  this->currentAttackWaypointValue = 0;
  this->consecutiveGatherAttemptsValue = 0;
  this->numberObjectsToDestroyValue = 0;
  this->objectsToDestroyOwnerValue = -1;
  this->objectsToDestroyCommanderZoneValue = -1;
  this->lastAttackRoundupTime = 0;
  this->lastAddedUnitTimeValue = 0;
  this->vfptr = (TacticalAIGroupVtbl *)&TacticalAIGroup::`vftable';
  TacticalAIGroup::setTargetLocation(this, -1.0, -1.0, -1.0);
  TacticalAIGroup::setGatherLocation(v1, -1.0, -1.0, -1.0);
  TacticalAIGroup::setRetreatLocation(v1, -1.0, -1.0, -1.0);
  TacticalAIGroup::setLocation(v1, -1.0, -1.0, -1.0);
  v2 = v1->unitsOriginalHitPointsValue;
  v3 = 40;
  do
  {
    *(v2 - 40) = -1;
    *v2 = -1;
    ++v2;
    --v3;
  }
  while ( v3 );
  memset(v1->objectsToDestroyValue, 0xFFu, sizeof(v1->objectsToDestroyValue));
}
// 5756D8: using guessed type int (__thiscall *TacticalAIGroup::`vftable')(void *Memory, unsigned int __flags);

//----- (004EA990) --------------------------------------------------------
TacticalAIGroup *__thiscall TacticalAIGroup::`vector deleting destructor'(TacticalAIGroup *this, unsigned int __flags)
{
  TacticalAIGroup *v2; // esi@1

  v2 = this;
  TacticalAIGroup::~TacticalAIGroup(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004EA9B0) --------------------------------------------------------
void __thiscall TacticalAIGroup::~TacticalAIGroup(TacticalAIGroup *this)
{
  this->vfptr = (TacticalAIGroupVtbl *)&TacticalAIGroup::`vftable';
}
// 5756D8: using guessed type int (__thiscall *TacticalAIGroup::`vftable')(void *Memory, unsigned int __flags);

//----- (004EA9C0) --------------------------------------------------------
int __userpurge TacticalAIGroup::load@<eax>(TacticalAIGroup *this@<ecx>, int a2@<ebp>, int infile)
{
  TacticalAIGroup *v3; // edi@1
  int *v4; // ebx@1
  int v5; // ebp@1

  v3 = this;
  rge_read(a2, (int)this, infile, &this->idValue, 4);
  rge_read(a2, (int)v3, infile, &v3->inUseValue, 4);
  v4 = v3->unitsOriginalHitPointsValue;
  v5 = 40;
  do
  {
    rge_read(v5, (int)v3, infile, v4 - 40, 4);
    rge_read(v5, (int)v3, infile, v4, 4);
    ++v4;
    --v5;
  }
  while ( v5 );
  rge_read(0, (int)v3, infile, &v3->numberUnitsValue, 4);
  rge_read(0, (int)v3, infile, &v3->desiredNumberUnitsValue, 4);
  rge_read(0, (int)v3, infile, &v3->commanderValue, 4);
  rge_read(0, (int)v3, infile, &v3->originalHitPointsValue, 4);
  rge_read(0, (int)v3, infile, &v3->originalUnitNumberValue, 4);
  rge_read(0, (int)v3, infile, &v3->locationValue, 16);
  rge_read(0, (int)v3, infile, &v3->actionValue, 4);
  rge_read(0, (int)v3, infile, &v3->targetValue, 4);
  rge_read(0, (int)v3, infile, &v3->targetTypeValue, 4);
  rge_read(0, (int)v3, infile, &v3->targetLocationValue, 16);
  rge_read(0, (int)v3, infile, &v3->gatherLocationValue, 16);
  rge_read(0, (int)v3, infile, &v3->retreatLocationValue, 16);
  rge_read(0, (int)v3, infile, &v3->priorityValue, 4);
  rge_read(0, (int)v3, infile, &v3->waitCodeValue, 4);
  rge_read(0, (int)v3, infile, &v3->assistGroupIDValue, 4);
  rge_read(0, (int)v3, infile, &v3->assistGroupTypeValue, 4);
  rge_read(0, (int)v3, infile, &v3->typeValue, 4);
  rge_read(0, (int)v3, infile, &v3->subTypeValue, 4);
  rge_read(0, (int)v3, infile, &v3->consecutiveIdleUnitCountValue, 4);
  rge_read(0, (int)v3, infile, &v3->numberAttackWaypointsValue, 1);
  rge_read(0, (int)v3, infile, &v3->currentAttackWaypointValue, 1);
  rge_read(0, (int)v3, infile, v3->attackWaypoints, 240);
  rge_read(0, (int)v3, infile, &v3->playNumberValue, 4);
  if ( save_game_version < 6.9400001 )
    v3->consecutiveGatherAttemptsValue = 0;
  else
    rge_read(0, (int)v3, infile, &v3->consecutiveGatherAttemptsValue, 1);
  if ( save_game_version >= 7.1300001 )
  {
    rge_read(0, (int)v3, infile, &v3->numberObjectsToDestroyValue, 4);
    rge_read(0, (int)v3, infile, v3->objectsToDestroyValue, 80);
    rge_read(0, (int)v3, infile, &v3->objectsToDestroyOwnerValue, 4);
    rge_read(0, (int)v3, infile, &v3->objectsToDestroyCommanderZoneValue, 4);
  }
  if ( save_game_version >= 7.1399999 )
    rge_read(0, (int)v3, infile, &v3->lastAttackRoundupTime, 4);
  if ( save_game_version >= 7.1999998 )
    rge_read(0, (int)&v3->lastAddedUnitTimeValue, infile, &v3->lastAddedUnitTimeValue, 4);
  return 1;
}
// 58EBCC: using guessed type float save_game_version;

//----- (004EACA0) --------------------------------------------------------
int __thiscall TacticalAIGroup::save(TacticalAIGroup *this, int outfile)
{
  TacticalAIGroup *v2; // edi@1
  int *v3; // ebx@1
  signed int v4; // ebp@1

  v2 = this;
  rge_write(outfile, &this->idValue, 4);
  rge_write(outfile, &v2->inUseValue, 4);
  v3 = v2->unitsOriginalHitPointsValue;
  v4 = 40;
  do
  {
    rge_write(outfile, v3 - 40, 4);
    rge_write(outfile, v3, 4);
    ++v3;
    --v4;
  }
  while ( v4 );
  rge_write(outfile, &v2->numberUnitsValue, 4);
  rge_write(outfile, &v2->desiredNumberUnitsValue, 4);
  rge_write(outfile, &v2->commanderValue, 4);
  rge_write(outfile, &v2->originalHitPointsValue, 4);
  rge_write(outfile, &v2->originalUnitNumberValue, 4);
  rge_write(outfile, &v2->locationValue, 16);
  rge_write(outfile, &v2->actionValue, 4);
  rge_write(outfile, &v2->targetValue, 4);
  rge_write(outfile, &v2->targetTypeValue, 4);
  rge_write(outfile, &v2->targetLocationValue, 16);
  rge_write(outfile, &v2->gatherLocationValue, 16);
  rge_write(outfile, &v2->retreatLocationValue, 16);
  rge_write(outfile, &v2->priorityValue, 4);
  rge_write(outfile, &v2->waitCodeValue, 4);
  rge_write(outfile, &v2->assistGroupIDValue, 4);
  rge_write(outfile, &v2->assistGroupTypeValue, 4);
  rge_write(outfile, &v2->typeValue, 4);
  rge_write(outfile, &v2->subTypeValue, 4);
  rge_write(outfile, &v2->consecutiveIdleUnitCountValue, 4);
  rge_write(outfile, &v2->numberAttackWaypointsValue, 1);
  rge_write(outfile, &v2->currentAttackWaypointValue, 1);
  rge_write(outfile, v2->attackWaypoints, 240);
  rge_write(outfile, &v2->playNumberValue, 4);
  rge_write(outfile, &v2->consecutiveGatherAttemptsValue, 1);
  rge_write(outfile, &v2->numberObjectsToDestroyValue, 4);
  rge_write(outfile, v2->objectsToDestroyValue, 80);
  rge_write(outfile, &v2->objectsToDestroyOwnerValue, 4);
  rge_write(outfile, &v2->objectsToDestroyCommanderZoneValue, 4);
  rge_write(outfile, &v2->lastAttackRoundupTime, 4);
  rge_write(outfile, &v2->lastAddedUnitTimeValue, 4);
  return 1;
}

//----- (004EAF20) --------------------------------------------------------
int __thiscall TacticalAIGroup::id(TacticalAIGroup *this)
{
  return this->idValue;
}

//----- (004EAF30) --------------------------------------------------------
void __thiscall TacticalAIGroup::setID(TacticalAIGroup *this, int v)
{
  this->idValue = v;
}

//----- (004EAF40) --------------------------------------------------------
int __thiscall TacticalAIGroup::inUse(TacticalAIGroup *this)
{
  return this->inUseValue;
}

//----- (004EAF50) --------------------------------------------------------
void __thiscall TacticalAIGroup::setInUse(TacticalAIGroup *this, int v)
{
  this->inUseValue = v;
}

//----- (004EAF60) --------------------------------------------------------
int __thiscall TacticalAIGroup::type(TacticalAIGroup *this)
{
  return this->typeValue;
}

//----- (004EAF70) --------------------------------------------------------
void __thiscall TacticalAIGroup::setType(TacticalAIGroup *this, int v)
{
  this->typeValue = v;
}

//----- (004EAF80) --------------------------------------------------------
int __thiscall TacticalAIGroup::subType(TacticalAIGroup *this)
{
  return this->subTypeValue;
}

//----- (004EAF90) --------------------------------------------------------
void __thiscall TacticalAIGroup::setSubType(TacticalAIGroup *this, int v)
{
  this->subTypeValue = v;
}

//----- (004EAFA0) --------------------------------------------------------
int __thiscall TacticalAIGroup::addUnit(TacticalAIGroup *this, int id, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // esi@1
  signed int v4; // eax@1
  char *v5; // ecx@1
  int result; // eax@4
  int v7; // eax@5

  v3 = this;
  v4 = 0;
  v5 = (char *)this->unitsValue;
  while ( *(_DWORD *)v5 != -1 )
  {
    ++v4;
    v5 += 4;
    if ( v4 >= 40 )
      return 0;
  }
  v3->unitsValue[v4] = id;
  v3->unitsOriginalHitPointsValue[v4] = -1;
  v7 = v3->commanderValue;
  ++v3->numberUnitsValue;
  if ( v7 != -1 )
    ((void (__stdcall *)(int, int, signed int))md->player->vfptr->command_add_to_group)(v7, id, 1082130432);
  result = 1;
  v3->lastAddedUnitTimeValue = md->player->world->world_time;
  return result;
}

//----- (004EB030) --------------------------------------------------------
int __thiscall TacticalAIGroup::removeUnit(TacticalAIGroup *this, int id, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // edi@1
  signed int v4; // esi@1
  char *v5; // eax@1
  int v7; // eax@5

  v3 = this;
  v4 = 0;
  v5 = (char *)this->unitsValue;
  while ( *(_DWORD *)v5 != id )
  {
    ++v4;
    v5 += 4;
    if ( v4 >= 40 )
      return 0;
  }
  v7 = this->commanderValue;
  if ( id == v7 )
  {
    TacticalAIGroup::setSpecificCommander(this, -1, md);
  }
  else if ( v7 != -1 )
  {
    ((void (__stdcall *)(int, int))md->player->vfptr->command_remove_from_group)(v7, id);
  }
  v3->unitsValue[v4] = -1;
  v3->unitsOriginalHitPointsValue[v4] = -1;
  --v3->numberUnitsValue;
  return 1;
}

//----- (004EB0C0) --------------------------------------------------------
int __thiscall TacticalAIGroup::removeUnitByIndex(TacticalAIGroup *this, int index, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // esi@1
  int v4; // eax@3
  int result; // eax@7

  v3 = this;
  if ( index < 0 || index >= 40 )
  {
    result = 0;
  }
  else
  {
    v4 = this->commanderValue;
    if ( this->unitsValue[index] == v4 )
    {
      TacticalAIGroup::setSpecificCommander(this, -1, md);
    }
    else if ( v4 != -1 )
    {
      ((void (__stdcall *)(int, int))md->player->vfptr->command_remove_from_group)(v4, this->unitsValue[index]);
    }
    v3->unitsValue[index] = -1;
    v3->unitsOriginalHitPointsValue[index] = -1;
    --v3->numberUnitsValue;
    result = 1;
  }
  return result;
}

//----- (004EB140) --------------------------------------------------------
void __thiscall TacticalAIGroup::removeUnits(TacticalAIGroup *this, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v2; // esi@1
  int *v3; // eax@1
  signed int v4; // ecx@1

  v2 = this;
  TacticalAIGroup::setSpecificCommander(this, -1, md);
  v2->numberUnitsValue = 0;
  v3 = v2->unitsOriginalHitPointsValue;
  v4 = 40;
  do
  {
    *(v3 - 40) = -1;
    *v3 = -1;
    ++v3;
    --v4;
  }
  while ( v4 );
}

//----- (004EB180) --------------------------------------------------------
int __thiscall TacticalAIGroup::removeExtraUnits(TacticalAIGroup *this, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v2; // esi@1
  int v3; // eax@1
  int v4; // ecx@1
  int v5; // edi@3
  int *v6; // ebx@4
  int result; // eax@9

  v2 = this;
  v3 = this->numberUnitsValue;
  v4 = this->desiredNumberUnitsValue;
  if ( v3 <= v4 || v3 <= 0 )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( v4 < v3 )
    {
      v6 = v2->unitsValue;
      do
      {
        if ( v5 >= 40 )
          break;
        if ( *v6 != -1 )
          TacticalAIGroup::removeUnitByIndex(v2, v5, md);
        ++v5;
        ++v6;
      }
      while ( v2->desiredNumberUnitsValue < v2->numberUnitsValue );
    }
    result = 1;
  }
  return result;
}

//----- (004EB1F0) --------------------------------------------------------
int __thiscall TacticalAIGroup::removeUnboardedUnits(TacticalAIGroup *this, TribeTacticalAIModule *t, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // edi@1
  char *v4; // esi@1
  RGE_Static_Object *v5; // eax@3
  int v6; // eax@5
  signed int v8; // [sp+10h] [bp-4h]@1

  v3 = this;
  v8 = 40;
  v4 = (char *)this->unitsValue;
  do
  {
    if ( *(_DWORD *)v4 != -1 )
    {
      v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *(_DWORD *)v4);
      if ( !v5 || !v5->inside_obj )
      {
        v6 = v3->commanderValue;
        if ( *(_DWORD *)v4 == v6 )
        {
          TacticalAIGroup::setSpecificCommander(v3, -1, md);
        }
        else if ( v6 != -1 )
        {
          ((void (__stdcall *)(int, _DWORD))md->player->vfptr->command_remove_from_group)(v6, *(_DWORD *)v4);
        }
        TribeTacticalAIModule::stopUnit(t, *(_DWORD *)v4, 100);
        *(_DWORD *)v4 = -1;
        *((_DWORD *)v4 + 40) = -1;
        --v3->numberUnitsValue;
      }
    }
    v4 += 4;
    --v8;
  }
  while ( v8 );
  return 1;
}

//----- (004EB290) --------------------------------------------------------
int __thiscall TacticalAIGroup::containsUnit(TacticalAIGroup *this, int id)
{
  signed int v2; // eax@1
  char *v3; // ecx@1

  v2 = 0;
  v3 = (char *)this->unitsValue;
  while ( *(_DWORD *)v3 != id )
  {
    ++v2;
    v3 += 4;
    if ( v2 >= 40 )
      return 0;
  }
  return 1;
}

//----- (004EB2C0) --------------------------------------------------------
int __thiscall TacticalAIGroup::numberUnits(TacticalAIGroup *this)
{
  return this->numberUnitsValue;
}

//----- (004EB2D0) --------------------------------------------------------
int __thiscall TacticalAIGroup::unit(TacticalAIGroup *this, int i)
{
  char *v2; // ebx@1
  signed int v3; // eax@1
  int v4; // edx@1
  char *v5; // ecx@1

  v2 = (char *)this->unitsValue;
  v3 = 0;
  v4 = -1;
  v5 = (char *)this->unitsValue;
  while ( v4 < i + 1 )
  {
    if ( *(_DWORD *)v5 != -1 )
      ++v4;
    if ( v4 == i )
      return *(_DWORD *)&v2[4 * v3];
    ++v3;
    v5 += 4;
    if ( v3 >= 40 )
      return -1;
  }
  return -1;
}

//----- (004EB320) --------------------------------------------------------
int __thiscall TacticalAIGroup::unitOriginalHitPoints(TacticalAIGroup *this, int i)
{
  signed int v2; // eax@1
  int v3; // esi@1
  char *v4; // edx@1

  v2 = 0;
  v3 = -1;
  v4 = (char *)this->unitsValue;
  while ( v3 < i + 1 )
  {
    if ( *(_DWORD *)v4 != -1 )
      ++v3;
    if ( v3 == i )
      return this->unitsOriginalHitPointsValue[v2];
    ++v2;
    v4 += 4;
    if ( v2 >= 40 )
      return -1;
  }
  return -1;
}

//----- (004EB370) --------------------------------------------------------
int __thiscall TacticalAIGroup::desiredNumberUnits(TacticalAIGroup *this)
{
  return this->desiredNumberUnitsValue;
}

//----- (004EB380) --------------------------------------------------------
void __thiscall TacticalAIGroup::setDesiredNumberUnits(TacticalAIGroup *this, int v)
{
  this->desiredNumberUnitsValue = v;
}

//----- (004EB390) --------------------------------------------------------
int __thiscall TacticalAIGroup::commander(TacticalAIGroup *this)
{
  return this->commanderValue;
}

//----- (004EB3A0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setSpecificCommander(TacticalAIGroup *this, int id, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // esi@1
  int v4; // eax@1
  int *v5; // ecx@4
  int v6; // edi@4
  int *v7; // edx@4
  signed int v8; // esi@4
  bool v9; // zf@5
  int temp[40]; // [sp+10h] [bp-A0h]@4

  v3 = this;
  v4 = this->commanderValue;
  if ( v4 != -1 )
    ((void (__stdcall *)(int))md->player->vfptr->command_destroy_group)(v4);
  v3->commanderValue = id;
  if ( id != -1 )
  {
    v5 = v3->unitsValue;
    v6 = 0;
    v7 = temp;
    v8 = 40;
    do
    {
      v9 = *v5 == -1;
      *v7 = *v5;
      if ( !v9 )
      {
        ++v6;
        ++v7;
      }
      ++v5;
      --v8;
    }
    while ( v8 );
    ((void (__stdcall *)(int, int *, int, signed int))md->player->vfptr->command_create_group)(id, temp, v6, 1082130432);
  }
}

//----- (004EB430) --------------------------------------------------------
int __thiscall TacticalAIGroup::currentHitPoints(TacticalAIGroup *this, TribeMainDecisionAIModule *md)
{
  int v2; // ebp@1
  int *v3; // esi@1
  signed int v4; // ebx@1
  RGE_Static_Object *v5; // eax@3

  v2 = 0;
  v3 = this->unitsValue;
  v4 = 40;
  do
  {
    if ( *v3 != -1 )
    {
      v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v3);
      if ( v5 )
        v2 += (signed __int64)v5->hp;
    }
    ++v3;
    --v4;
  }
  while ( v4 );
  return v2;
}

//----- (004EB470) --------------------------------------------------------
int __thiscall TacticalAIGroup::originalHitPoints(TacticalAIGroup *this)
{
  return this->originalHitPointsValue;
}

//----- (004EB480) --------------------------------------------------------
void __thiscall TacticalAIGroup::setOriginalHitPoints(TacticalAIGroup *this, int v)
{
  this->originalHitPointsValue = v;
}

//----- (004EB490) --------------------------------------------------------
int __thiscall TacticalAIGroup::originalUnitNumber(TacticalAIGroup *this)
{
  return this->originalUnitNumberValue;
}

//----- (004EB4A0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setOriginalUnitNumber(TacticalAIGroup *this, int v)
{
  this->originalUnitNumberValue = v;
}

//----- (004EB4B0) --------------------------------------------------------
Waypoint *__thiscall TacticalAIGroup::location(TacticalAIGroup *this)
{
  return &this->locationValue;
}

//----- (004EB4C0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setLocation(TacticalAIGroup *this, float x, float y, float z)
{
  this->locationValue.x = x;
  this->locationValue.y = y;
  this->locationValue.z = z;
}

//----- (004EB4F0) --------------------------------------------------------
int __thiscall TacticalAIGroup::action(TacticalAIGroup *this)
{
  return this->actionValue;
}

//----- (004EB500) --------------------------------------------------------
void __thiscall TacticalAIGroup::setAction(TacticalAIGroup *this, int v)
{
  this->actionValue = v;
}

//----- (004EB510) --------------------------------------------------------
int __thiscall TacticalAIGroup::target(TacticalAIGroup *this)
{
  return this->targetValue;
}

//----- (004EB520) --------------------------------------------------------
void __thiscall TacticalAIGroup::setTarget(TacticalAIGroup *this, int v)
{
  this->targetValue = v;
}

//----- (004EB530) --------------------------------------------------------
int __thiscall TacticalAIGroup::targetType(TacticalAIGroup *this)
{
  return this->targetTypeValue;
}

//----- (004EB540) --------------------------------------------------------
void __thiscall TacticalAIGroup::setTargetType(TacticalAIGroup *this, int v)
{
  this->targetTypeValue = v;
}

//----- (004EB550) --------------------------------------------------------
Waypoint *__thiscall TacticalAIGroup::targetLocation(TacticalAIGroup *this)
{
  return &this->targetLocationValue;
}

//----- (004EB560) --------------------------------------------------------
void __thiscall TacticalAIGroup::setAllLocations(TacticalAIGroup *this, float x, float y, float z)
{
  this->locationValue.x = x;
  this->locationValue.y = y;
  this->locationValue.z = z;
  this->gatherLocationValue.x = x;
  this->gatherLocationValue.y = y;
  this->gatherLocationValue.z = z;
  this->retreatLocationValue.x = x;
  this->retreatLocationValue.y = y;
  this->retreatLocationValue.z = z;
}

//----- (004EB5C0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setTargetLocation(TacticalAIGroup *this, float x, float y, float z)
{
  this->targetLocationValue.x = x;
  this->targetLocationValue.y = y;
  this->targetLocationValue.z = z;
}

//----- (004EB5F0) --------------------------------------------------------
Waypoint *__thiscall TacticalAIGroup::gatherLocation(TacticalAIGroup *this)
{
  return &this->gatherLocationValue;
}

//----- (004EB600) --------------------------------------------------------
void __thiscall TacticalAIGroup::setGatherLocation(TacticalAIGroup *this, float x, float y, float z)
{
  this->gatherLocationValue.x = x;
  this->gatherLocationValue.y = y;
  this->gatherLocationValue.z = z;
}

//----- (004EB630) --------------------------------------------------------
Waypoint *__thiscall TacticalAIGroup::retreatLocation(TacticalAIGroup *this)
{
  return &this->retreatLocationValue;
}

//----- (004EB640) --------------------------------------------------------
void __thiscall TacticalAIGroup::setRetreatLocation(TacticalAIGroup *this, float x, float y, float z)
{
  this->retreatLocationValue.x = x;
  this->retreatLocationValue.y = y;
  this->retreatLocationValue.z = z;
}

//----- (004EB670) --------------------------------------------------------
int __thiscall TacticalAIGroup::priority(TacticalAIGroup *this)
{
  return this->priorityValue;
}

//----- (004EB680) --------------------------------------------------------
void __thiscall TacticalAIGroup::setPriority(TacticalAIGroup *this, int v)
{
  this->priorityValue = v;
}

//----- (004EB690) --------------------------------------------------------
int __thiscall TacticalAIGroup::waitCode(TacticalAIGroup *this)
{
  return this->waitCodeValue;
}

//----- (004EB6A0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setWaitCode(TacticalAIGroup *this, int v)
{
  this->waitCodeValue = v;
}

//----- (004EB6B0) --------------------------------------------------------
int __thiscall TacticalAIGroup::assistGroupID(TacticalAIGroup *this)
{
  return this->assistGroupIDValue;
}

//----- (004EB6C0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setAssistGroupID(TacticalAIGroup *this, int v)
{
  this->assistGroupIDValue = v;
}

//----- (004EB6D0) --------------------------------------------------------
int __thiscall TacticalAIGroup::assistGroupType(TacticalAIGroup *this)
{
  return this->assistGroupTypeValue;
}

//----- (004EB6E0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setAssistGroupType(TacticalAIGroup *this, int v)
{
  this->assistGroupTypeValue = v;
}

//----- (004EB6F0) --------------------------------------------------------
int __thiscall TacticalAIGroup::task(TacticalAIGroup *this, TribeTacticalAIModule *t, TribeMainDecisionAIModule *md, int taskID, int resetOriginal, int overrideCurrentAction)
{
  TacticalAIGroup *v6; // esi@1
  TribeTacticalAIModule *v7; // edi@1
  int v8; // ecx@1
  int result; // eax@2
  int *v10; // ebp@7
  RGE_Static_Object *v11; // eax@9
  RGE_Static_Object *v12; // ebx@9
  signed __int64 v13; // rax@11
  bool v14; // sf@13
  unsigned __int8 v15; // of@13
  TribeTacticalAIModule *v16; // ecx@15
  char v17; // al@16
  RGE_Static_Object *v18; // eax@18
  RGE_Static_Object *v19; // ebp@18
  int *v20; // ebx@21
  RGE_Static_Object *v21; // eax@23
  RGE_Static_Object *v22; // ebp@23
  UnitAIModule *v23; // eax@28
  UnitAIModule *v24; // eax@29
  long double v25; // st7@33
  UnitAIModule *v26; // eax@36
  int v27; // eax@38
  int *v28; // ebp@42
  RGE_Static_Object *v29; // eax@44
  RGE_Static_Object *v30; // ebx@44
  long double v31; // st7@46
  int *v32; // ebp@54
  RGE_Static_Object *v33; // eax@56
  RGE_Static_Object *v34; // ebx@56
  signed __int64 v35; // rax@58
  UnitAIModule *v36; // eax@59
  UnitAIModule *v37; // eax@60
  int v38; // eax@60
  float range; // ST24_4@64
  TribeTacticalAIModule *v40; // edx@69
  int *v41; // ebp@70
  RGE_Static_Object *v42; // eax@72
  RGE_Static_Object *v43; // ebx@72
  signed __int64 v44; // rax@74
  UnitAIModule *v45; // eax@75
  UnitAIModule *v46; // eax@76
  int v47; // eax@76
  int v48; // eax@84
  int *v49; // ebp@86
  RGE_Static_Object *v50; // eax@88
  RGE_Static_Object *v51; // ebx@88
  UnitAIModule *v52; // eax@90
  int v53; // eax@90
  signed __int64 v54; // rax@90
  UnitAIModule *v55; // eax@91
  int v56; // eax@93
  RGE_Static_Object *v57; // ebx@95
  float v58; // edx@102
  int *v59; // ebp@106
  RGE_Static_Object *v60; // eax@108
  RGE_Static_Object *v61; // ebx@108
  UnitAIModule *v62; // eax@110
  int v63; // eax@110
  signed __int64 v64; // rax@110
  UnitAIModule *v65; // eax@112
  UnitAIModule *v66; // eax@113
  int v67; // eax@115
  RGE_Static_Object *v68; // ebx@117
  double v69; // st7@119
  TribeInformationAIModule *v70; // ebx@119
  double v71; // st7@119
  int v72; // eax@120
  float v73; // et1@120
  int v74; // ebx@120
  double v76; // st7@120
  unsigned __int8 v77; // c0@120
  unsigned __int8 v78; // c3@120
  int v79; // et1@123
  double v81; // st7@123
  unsigned __int8 v82; // c0@123
  unsigned __int8 v83; // c3@123
  float v84; // ST24_4@131
  int *v85; // eax@140
  int *v86; // ebp@140
  int *v87; // edx@142
  int *v88; // ecx@142
  signed int v89; // ebx@142
  int v90; // ecx@149
  int *v91; // ebp@150
  RGE_Static_Object *v92; // eax@152
  RGE_Static_Object *v93; // ebx@152
  signed __int64 v94; // rax@154
  UnitAIModule *v95; // eax@155
  UnitAIModule *v96; // eax@156
  int v97; // eax@156
  RGE_Static_Object *v98; // ST44_4@157
  float v99; // ST24_4@158
  float v100; // ST24_4@159
  int *v101; // ebp@164
  RGE_Static_Object *v102; // eax@166
  RGE_Static_Object *v103; // ebx@166
  signed __int64 v104; // rax@168
  UnitAIModule *v105; // eax@169
  UnitAIModule *v106; // eax@170
  int v107; // eax@170
  float v108; // ST24_4@173
  int v109; // ecx@178
  int *v110; // ebp@179
  RGE_Static_Object *v111; // eax@181
  RGE_Static_Object *v112; // ebx@181
  signed __int64 v113; // rax@183
  UnitAIModule *v114; // eax@184
  UnitAIModule *v115; // eax@185
  int v116; // eax@185
  float v117; // ST24_4@188
  int v118; // edx@193
  int *v119; // ebp@194
  RGE_Static_Object *v120; // eax@196
  RGE_Static_Object *v121; // ebx@196
  signed __int64 v122; // rax@198
  int v123; // edx@202
  int range_4; // [sp+Ch] [bp-30h]@82
  int range_4a; // [sp+Ch] [bp-30h]@157
  int range_4b; // [sp+Ch] [bp-30h]@171
  int range_4c; // [sp+Ch] [bp-30h]@186
  float gatherRange; // [sp+20h] [bp-1Ch]@31
  float gatherRangea; // [sp+20h] [bp-1Ch]@106
  int firstTime; // [sp+24h] [bp-18h]@19
  int firstTimea; // [sp+24h] [bp-18h]@106
  RGE_Static_Object *targetObj; // [sp+28h] [bp-14h]@18
  RGE_Static_Object *targetObja; // [sp+28h] [bp-14h]@54
  RGE_Static_Object *targetObjb; // [sp+28h] [bp-14h]@117
  XYPoint min; // [sp+2Ch] [bp-10h]@119
  XYPoint max; // [sp+34h] [bp-8h]@119
  TribeTacticalAIModule *ta; // [sp+40h] [bp+4h]@21
  TribeTacticalAIModule *tb; // [sp+40h] [bp+4h]@54
  TribeTacticalAIModule *tc; // [sp+40h] [bp+4h]@70
  TribeTacticalAIModule *td; // [sp+40h] [bp+4h]@86
  TribeTacticalAIModule *te; // [sp+40h] [bp+4h]@106
  TribeTacticalAIModule *tf; // [sp+40h] [bp+4h]@150
  TribeTacticalAIModule *tg; // [sp+40h] [bp+4h]@164
  TribeTacticalAIModule *th; // [sp+40h] [bp+4h]@179
  int taskIDa; // [sp+48h] [bp+Ch]@7
  int taskIDb; // [sp+48h] [bp+Ch]@54
  int taskIDc; // [sp+48h] [bp+Ch]@70
  int taskIDd; // [sp+48h] [bp+Ch]@86
  int taskIDe; // [sp+48h] [bp+Ch]@150
  int taskIDf; // [sp+48h] [bp+Ch]@164
  int taskIDg; // [sp+48h] [bp+Ch]@179
  int taskIDh; // [sp+48h] [bp+Ch]@194
  float oHP; // [sp+4Ch] [bp+10h]@33
  int oHPa; // [sp+4Ch] [bp+10h]@42
  int distance; // [sp+50h] [bp+14h]@7
  int distancea; // [sp+50h] [bp+14h]@194

  v6 = this;
  v7 = t;
  TribeTacticalAIModule::logGroupDebug(t, this->idValue, aEnteringTaskTa, taskID, resetOriginal, overrideCurrentAction);
  v8 = v6->commanderValue;
  if ( v8 == -1 )
  {
    TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aIDonTHaveAComm);
    result = 0;
  }
  else
  {
    if ( taskID != 9 && taskID != 14 )
      v6->consecutiveGatherAttemptsValue = 0;
    switch ( taskID )
    {
      case 0:
      case 1:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToStopMyU);
        taskIDa = 0;
        distance = 0;
        v10 = v6->unitsValue;
        do
        {
          if ( *v10 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aCheckingOnUnit, *v10);
            v11 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v10);
            v12 = v11;
            if ( v11 && RGE_Static_Object::unitAI(v11) )
            {
              v13 = (signed __int64)v12->hp;
              v10[40] = v13;
              taskIDa += v13;
              TribeTacticalAIModule::stopUnit(t, *v10, 100);
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aUnitDIsGoneRem, *v10);
              TacticalAIGroup::removeUnitByIndex(v6, distance, md);
            }
          }
          ++v10;
          v15 = __OFSUB__(distance + 1, 40);
          v14 = distance++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        v6->inUseValue = 0;
        if ( resetOriginal == 1 )
        {
          v16 = (TribeTacticalAIModule *)taskIDa;
          goto LABEL_193;
        }
        break;
      case 9:
      case 14:
        v17 = v6->consecutiveGatherAttemptsValue;
        if ( (unsigned __int8)v17 < 0xFFu )
          v6->consecutiveGatherAttemptsValue = v17 + 1;
        v18 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, v8);
        v19 = v18;
        targetObj = v18;
        if ( !v18 )
          goto LABEL_204;
        firstTime = (unsigned __int8)RGE_Static_Object::currentZone(v18);
        if ( firstTime != (unsigned __int8)RGE_Static_Object::lookupZone(
                                             v19,
                                             (signed __int64)v6->gatherLocationValue.x,
                                             (signed __int64)v6->gatherLocationValue.y) )
          TacticalAIGroup::setGatherLocation(v6, v19->world_x, v19->world_y, v19->world_z);
        ta = 0;
        v20 = v6->unitsValue;
        do
        {
          if ( *v20 != -1 )
          {
            v21 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v20);
            v22 = v21;
            if ( v21 && RGE_Static_Object::unitAI(v21) )
            {
              if ( (unsigned __int8)RGE_Static_Object::lookupZone(
                                      targetObj,
                                      (signed __int64)v22->world_x,
                                      (signed __int64)v22->world_y) == firstTime )
              {
                if ( overrideCurrentAction
                  || (v23 = RGE_Static_Object::unitAI(v22), UnitAIModule::currentAction(v23) == -1)
                  || (v24 = RGE_Static_Object::unitAI(v22), UnitAIModule::currentAction(v24) == 614) )
                {
                  if ( taskID == 14 )
                    gatherRange = 0.0;
                  else
                    gatherRange = (double)TribeTacticalAIModule::strategicNumber(v7, 41);
                  v25 = RGE_Static_Object::distance_to_position(
                          v22,
                          v6->gatherLocationValue.x,
                          v6->gatherLocationValue.y,
                          v6->gatherLocationValue.z)
                      - 1.0;
                  oHP = v25;
                  if ( v25 < 0.0 )
                    oHP = 0.0;
                  if ( oHP >= (double)gatherRange )
                  {
                    v27 = TribeTacticalAIModule::calculatePriority(v7, oHP);
                    TribeTacticalAIModule::groupGatherUnit(
                      v7,
                      *v20,
                      v6->commanderValue,
                      v6->gatherLocationValue.x,
                      v6->gatherLocationValue.y,
                      v6->gatherLocationValue.z,
                      gatherRange,
                      v27);
                  }
                  else
                  {
                    v26 = RGE_Static_Object::unitAI(v22);
                    if ( UnitAIModule::currentOrder(v26) != -1 )
                      TribeTacticalAIModule::stopUnit(v7, *v20, 100);
                  }
                }
              }
              else
              {
                TacticalAIGroup::removeUnitByIndex(v6, (int)ta, md);
              }
            }
            else
            {
              TacticalAIGroup::removeUnitByIndex(v6, (int)ta, md);
            }
          }
          ++v20;
          v15 = __OFSUB__((char *)&ta->vfptr + 1, 40);
          v14 = (signed int)&ta[-1].hitsByPlayer[3] + 1 < 0;
          ta = (TribeTacticalAIModule *)((char *)ta + 1);
        }
        while ( v14 ^ v15 );
        result = 1;
        break;
      case 3:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToRetreat);
        TribeTacticalAIModule::logGroupDebug(
          t,
          v6->idValue,
          aRetreatPositio,
          v6->retreatLocationValue.x,
          v6->retreatLocationValue.y);
        oHPa = 0;
        v28 = v6->unitsValue;
        do
        {
          if ( *v28 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aCheckingOnUnit, *v28);
            v29 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v28);
            v30 = v29;
            if ( v29 && RGE_Static_Object::unitAI(v29) )
            {
              v31 = RGE_Static_Object::distance_to_position(
                      v30,
                      v6->retreatLocationValue.x,
                      v6->retreatLocationValue.y,
                      v6->retreatLocationValue.z)
                  - 1.0;
              if ( v31 < 0.0 )
                v31 = 0.0;
              if ( v31 >= v30->master_obj->los * 0.33333334 )
              {
                TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aTaskingUnitDTo, *v28);
                TribeTacticalAIModule::moveUnit(t, *v28, v6->retreatLocationValue.x, v6->retreatLocationValue.y, 100);
              }
              else
              {
                TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aUnitDIsWithinA, *v28);
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aUnitDIsGoneRem, *v28);
              TacticalAIGroup::removeUnitByIndex(v6, oHPa, md);
            }
          }
          ++v28;
          v15 = __OFSUB__(oHPa + 1, 40);
          v14 = oHPa++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        break;
      case 7:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToSendMyU);
        tb = 0;
        taskIDb = 0;
        v32 = v6->unitsValue;
        targetObja = (RGE_Static_Object *)(debug_rand(aCMsdevWorkA_61, 943) % 100);
        do
        {
          if ( *v32 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v32);
            v33 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v32);
            v34 = v33;
            if ( v33 && RGE_Static_Object::unitAI(v33) )
            {
              v35 = (signed __int64)v34->hp;
              v32[40] = v35;
              tb = (TribeTacticalAIModule *)((char *)tb + v35);
              if ( overrideCurrentAction
                || (v36 = RGE_Static_Object::unitAI(v34), UnitAIModule::currentAction(v36) == -1) )
              {
                if ( *v32 == v6->commanderValue )
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsTheComm, *v32);
                  TribeTacticalAIModule::taskExplorer(v7, *v32, 0);
                }
                else if ( (signed int)targetObja >= TribeTacticalAIModule::strategicNumber(v7, 200) )
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsNotTh_1, *v32);
                  TribeTacticalAIModule::taskExplorer(v7, *v32, 0);
                }
                else
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsNotTheC, *v32);
                  range = v34->master_obj->los * 0.5;
                  TribeTacticalAIModule::taskDefender(v7, *v32, v6->commanderValue, range, 99);
                }
              }
              else
              {
                v37 = RGE_Static_Object::unitAI(v34);
                v38 = UnitAIModule::currentAction(v37);
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyWit, *v32, v38);
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v32);
              TacticalAIGroup::removeUnitByIndex(v6, taskIDb, md);
            }
          }
          ++v32;
          v15 = __OFSUB__(taskIDb + 1, 40);
          v14 = taskIDb++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        v6->inUseValue = 1;
        if ( resetOriginal == 1 )
        {
          v40 = tb;
          goto LABEL_178;
        }
        break;
      case 8:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToSendM_3);
        tc = 0;
        taskIDc = 0;
        v41 = v6->unitsValue;
        do
        {
          if ( *v41 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v41);
            v42 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v41);
            v43 = v42;
            if ( v42 && RGE_Static_Object::unitAI(v42) )
            {
              v44 = (signed __int64)v43->hp;
              v41[40] = v44;
              tc = (TribeTacticalAIModule *)((char *)tc + v44);
              if ( overrideCurrentAction
                || (v45 = RGE_Static_Object::unitAI(v43), UnitAIModule::currentAction(v45) == -1) )
              {
                TribeTacticalAIModule::taskExplorer(v7, *v41, 0);
              }
              else
              {
                v46 = RGE_Static_Object::unitAI(v43);
                v47 = UnitAIModule::currentAction(v46);
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyWit, *v41, v47);
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v41);
              TacticalAIGroup::removeUnitByIndex(v6, taskIDc, md);
            }
          }
          ++v41;
          v15 = __OFSUB__(taskIDc + 1, 40);
          v14 = taskIDc++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        v6->inUseValue = 1;
        if ( resetOriginal == 1 )
        {
          v16 = tc;
          goto LABEL_193;
        }
        break;
      case 20:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToSendM_5, v6->targetValue);
        TribeTacticalAIModule::logGroupDebug(
          t,
          v6->idValue,
          aTargetLocation,
          v6->targetLocationValue.x,
          v6->targetLocationValue.y);
        range_4 = (signed int)(md->player->world->world_time - v6->lastAttackRoundupTime) / 1000;
        if ( range_4 < 10 )
        {
          TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aWeVeOnlyWaited, range_4);
          goto LABEL_204;
        }
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aWeVeWaitedDSec, range_4);
        v48 = v6->playNumberValue;
        v6->lastAttackRoundupTime = md->player->world->world_time;
        if ( v48 == -1 )
        {
          td = 0;
          taskIDd = 0;
          v49 = v6->unitsValue;
          do
          {
            if ( *v49 != -1 )
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v49);
              v50 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v49);
              v51 = v50;
              if ( v50 && RGE_Static_Object::unitAI(v50) )
              {
                v52 = RGE_Static_Object::unitAI(v51);
                v53 = UnitAIModule::currentAction(v52);
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCurrentactionD, v53);
                v54 = (signed __int64)v51->hp;
                v49[40] = v54;
                td = (TribeTacticalAIModule *)((char *)td + v54);
                if ( overrideCurrentAction
                  || (v55 = RGE_Static_Object::unitAI(v51), UnitAIModule::currentAction(v55) == -1) )
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aGettingReadyTo, *v49, v6->subTypeValue);
                  v56 = v6->subTypeValue;
                  if ( v56 && v56 != 4 )
                  {
                    v57 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, v6->targetValue);
                    if ( v57 )
                    {
                      TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTaskingUnitD_1, *v49, v6->targetValue);
                      TribeTacticalAIModule::taskAttacker(
                        v7,
                        *v49,
                        v6->targetLocationValue.x,
                        v6->targetLocationValue.y,
                        v6->targetValue,
                        v57->owner->id,
                        v6->attackWaypoints,
                        v6->numberAttackWaypointsValue,
                        v6->commanderValue,
                        1);
                    }
                    else
                    {
                      TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTargetObjectIs);
                    }
                  }
                  else
                  {
                    TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTaskingUnitD_3, *v49, v6->targetValue);
                    TribeTacticalAIModule::taskDefender(v7, *v49, v6->targetValue, 2.0, 100);
                  }
                }
                else
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyW_2, *v49);
                }
              }
              else
              {
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v49);
                TacticalAIGroup::removeUnitByIndex(v6, taskIDd, md);
              }
            }
            ++v49;
            v15 = __OFSUB__(taskIDd + 1, 40);
            v14 = taskIDd++ - 39 < 0;
          }
          while ( v14 ^ v15 );
          result = 1;
          v6->inUseValue = 1;
          if ( resetOriginal == 1 )
          {
            v58 = *(float *)&td;
            goto LABEL_149;
          }
        }
        else
        {
          TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aCanTUseThisWit);
          result = 0;
        }
        break;
      case 2:
      case 21:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToSendM_4, v6->targetValue);
        TribeTacticalAIModule::logGroupDebug(
          t,
          v6->idValue,
          aTargetLocation,
          v6->targetLocationValue.x,
          v6->targetLocationValue.y);
        if ( v6->playNumberValue == -1 )
          TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aUsingNonPlayBa);
        else
          TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aUsingAttackWit, v6->playNumberValue);
        firstTimea = 1;
        gatherRangea = 0.0;
        te = 0;
        v59 = v6->unitsValue;
        v6->lastAttackRoundupTime = md->player->world->world_time;
        do
        {
          if ( *v59 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v59);
            v60 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v59);
            v61 = v60;
            if ( v60 && RGE_Static_Object::unitAI(v60) )
            {
              v62 = RGE_Static_Object::unitAI(v61);
              v63 = UnitAIModule::currentAction(v62);
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCurrentactionD, v63);
              v64 = (signed __int64)v61->hp;
              v59[40] = v64;
              LODWORD(gatherRangea) += v64;
              if ( v6->playNumberValue == -1 )
              {
                if ( overrideCurrentAction
                  || (v65 = RGE_Static_Object::unitAI(v61), UnitAIModule::currentAction(v65) != 600)
                  || (v66 = RGE_Static_Object::unitAI(v61), UnitAIModule::currentTargetType(v66) == 27) )
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aGettingReadyTo, *v59, v6->subTypeValue);
                  v67 = v6->subTypeValue;
                  if ( v67 && v67 != 4 )
                  {
                    v68 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, v6->targetValue);
                    targetObjb = v68;
                    if ( v68 )
                    {
                      if ( firstTimea == 1 )
                      {
                        TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aDoingFirstTime);
                        v69 = v6->targetLocationValue.y;
                        min.x = (unsigned __int64)(signed __int64)v6->targetLocationValue.x - 7;
                        min.y = (unsigned __int64)(signed __int64)v69 - 7;
                        v70 = &md->informationAI;
                        TribeInformationAIModule::mapBound(&md->informationAI, &min);
                        v71 = v6->targetLocationValue.y;
                        max.x = (unsigned __int64)(signed __int64)v6->targetLocationValue.x + 7;
                        max.y = (unsigned __int64)(signed __int64)v71 + 7;
                        TribeInformationAIModule::mapBound(&md->informationAI, &max);
                        if ( v6->numberAttackWaypointsValue >= 2u )
                        {
                          v72 = v6->numberAttackWaypointsValue - 2;
                          v73 = v6->attackWaypoints[v72].x;
                          v74 = (int)v6 + v72 * 16;
                          v76 = v6->attackWaypoints[v72].x;
                          if ( v77 | v78 )
                            max.x = (signed __int64)v76;
                          else
                            min.x = (signed __int64)v76;
                          v79 = *(_DWORD *)(v74 + 476);
                          v81 = *(float *)(v74 + 476);
                          if ( v82 | v83 )
                            max.y = (signed __int64)v81;
                          else
                            min.y = (signed __int64)v81;
                          v70 = &md->informationAI;
                        }
                        TribeInformationAIModule::storeAttackMemory(
                          v70,
                          0,
                          min.x,
                          min.y,
                          max.x,
                          max.y,
                          md->player->id,
                          targetObjb->owner->id,
                          0,
                          0,
                          md->player->world->world_time,
                          -1);
                        TribeTacticalAIModule::resetAttackSeparationTime(v7);
                        v68 = targetObjb;
                        firstTimea = 0;
                      }
                      TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTaskingUnitD_0, *v59, v6->targetValue);
                      if ( *v59 != v6->commanderValue
                        && TribeTacticalAIModule::importantGroupLeader(v7, v6->commanderValue)
                        && TribeTacticalAIModule::strategicNumber(v7, 121) )
                      {
                        TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTaskingAsADefe);
                        v84 = (double)TribeTacticalAIModule::strategicNumber(v7, 131);
                        TribeTacticalAIModule::taskDefender(v7, *v59, v6->commanderValue, v84, 99);
                      }
                      else
                      {
                        TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTaskingAsAStra);
                        if ( taskID == 21 )
                          TribeTacticalAIModule::moveUnit(
                            v7,
                            *v59,
                            v6->targetLocationValue.x,
                            v6->targetLocationValue.y,
                            100);
                        else
                          TribeTacticalAIModule::taskAttacker(
                            v7,
                            *v59,
                            v6->targetLocationValue.x,
                            v6->targetLocationValue.y,
                            v6->targetValue,
                            v68->owner->id,
                            v6->attackWaypoints,
                            v6->numberAttackWaypointsValue,
                            v6->commanderValue,
                            0);
                      }
                    }
                    else
                    {
                      TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTargetObjectIs);
                    }
                  }
                  else
                  {
                    TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aTaskingUnitD_3, *v59, v6->targetValue);
                    TribeTacticalAIModule::taskDefender(v7, *v59, v6->targetValue, 2.0, 100);
                  }
                }
                else
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyW_0, *v59);
                }
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v59);
              TacticalAIGroup::removeUnitByIndex(v6, (int)te, md);
            }
          }
          ++v59;
          v15 = __OFSUB__((char *)&te->vfptr + 1, 40);
          v14 = (signed int)&te[-1].hitsByPlayer[3] + 1 < 0;
          te = (TribeTacticalAIModule *)((char *)te + 1);
        }
        while ( v14 ^ v15 );
        if ( v6->playNumberValue == -1 )
        {
          result = 1;
          v6->inUseValue = 1;
          if ( resetOriginal == 1 )
          {
            v58 = gatherRangea;
LABEL_149:
            v90 = v6->numberUnitsValue;
            *(float *)&v6->originalHitPointsValue = v58;
            v6->originalUnitNumberValue = v90;
            v6->numberAttackWaypointsValue = 0;
          }
        }
        else
        {
          v85 = (int *)operator new(4 * v6->numberUnitsValue);
          v86 = v85;
          if ( v85 )
          {
            v87 = v85;
            v88 = v6->unitsValue;
            v89 = 40;
            do
            {
              if ( *v88 != -1 )
              {
                *v87 = *v88;
                ++v87;
              }
              ++v88;
              --v89;
            }
            while ( v89 );
            TribeTacticalAIModule::taskPlay(
              v7,
              v6->commanderValue,
              v85,
              v6->numberUnitsValue,
              v6->targetValue,
              v6->playNumberValue,
              v6->attackWaypoints,
              v6->numberAttackWaypointsValue);
            operator delete(v86);
            result = 0;
          }
          else
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aErrorAllocatin);
            result = 0;
          }
        }
        break;
      case 4:
        TribeTacticalAIModule::logGroupDebug(
          t,
          v6->idValue,
          aGoingToSendM_1,
          v6->targetValue,
          v6->targetLocationValue.x,
          v6->targetLocationValue.y);
        tf = 0;
        taskIDe = 0;
        v91 = v6->unitsValue;
        do
        {
          if ( *v91 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v91);
            v92 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v91);
            v93 = v92;
            if ( v92 && RGE_Static_Object::unitAI(v92) )
            {
              v94 = (signed __int64)v93->hp;
              v91[40] = v94;
              tf = (TribeTacticalAIModule *)((char *)tf + v94);
              if ( overrideCurrentAction
                || (v95 = RGE_Static_Object::unitAI(v93), UnitAIModule::currentAction(v95) == -1) )
              {
                *(float *)&v98 = RGE_Static_Object::distance_to_position(
                                   v93,
                                   v6->targetLocationValue.x,
                                   v6->targetLocationValue.y,
                                   v6->targetLocationValue.z);
                range_4a = TribeTacticalAIModule::calculatePriority(v7, *(float *)&v98);
                if ( v6->targetTypeValue == 109 )
                {
                  v99 = (double)TribeTacticalAIModule::strategicNumber(v7, 22);
                  TribeTacticalAIModule::taskDefender(v7, *v91, v6->targetValue, v99, range_4a);
                }
                else
                {
                  v100 = (double)TribeTacticalAIModule::strategicNumber(v7, 57);
                  TribeTacticalAIModule::taskDefender(v7, *v91, v6->targetValue, v100, range_4a);
                }
              }
              else
              {
                v96 = RGE_Static_Object::unitAI(v93);
                v97 = UnitAIModule::currentAction(v96);
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyWit, *v91, v97);
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v91);
              TacticalAIGroup::removeUnitByIndex(v6, taskIDe, md);
            }
          }
          ++v91;
          v15 = __OFSUB__(taskIDe + 1, 40);
          v14 = taskIDe++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        v6->inUseValue = 1;
        if ( resetOriginal == 1 )
        {
          v40 = tf;
          goto LABEL_178;
        }
        break;
      case 10:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToSendM_0);
        tg = 0;
        taskIDf = 0;
        v101 = v6->unitsValue;
        do
        {
          if ( *v101 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v101);
            v102 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v101);
            v103 = v102;
            if ( v102 && RGE_Static_Object::unitAI(v102) )
            {
              v104 = (signed __int64)v103->hp;
              v101[40] = v104;
              tg = (TribeTacticalAIModule *)((char *)tg + v104);
              if ( overrideCurrentAction
                || (v105 = RGE_Static_Object::unitAI(v103), UnitAIModule::currentAction(v105) == -1) )
              {
                range_4b = *v101;
                if ( *v101 == v6->commanderValue )
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsTheCo_2, range_4b);
                  TribeTacticalAIModule::taskWaterFisher(
                    v7,
                    *v101,
                    v6->targetValue,
                    v6->targetLocationValue.x,
                    v6->targetLocationValue.y);
                }
                else
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsNotTheC, range_4b);
                  v108 = v103->master_obj->los * 0.5;
                  TribeTacticalAIModule::taskDefender(v7, *v101, v6->commanderValue, v108, 99);
                }
              }
              else
              {
                v106 = RGE_Static_Object::unitAI(v103);
                v107 = UnitAIModule::currentAction(v106);
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyWit, *v101, v107);
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v101);
              TacticalAIGroup::removeUnitByIndex(v6, taskIDf, md);
            }
          }
          ++v101;
          v15 = __OFSUB__(taskIDf + 1, 40);
          v14 = taskIDf++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        v6->inUseValue = 1;
        if ( resetOriginal == 1 )
        {
          v40 = tg;
LABEL_178:
          v109 = v6->numberUnitsValue;
          v6->originalHitPointsValue = (int)v40;
          v6->originalUnitNumberValue = v109;
        }
        break;
      case 11:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToSendM_6);
        th = 0;
        taskIDg = 0;
        v110 = v6->unitsValue;
        do
        {
          if ( *v110 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aCheckingOnUnit, *v110);
            v111 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v110);
            v112 = v111;
            if ( v111 && RGE_Static_Object::unitAI(v111) )
            {
              v113 = (signed __int64)v112->hp;
              v110[40] = v113;
              th = (TribeTacticalAIModule *)((char *)th + v113);
              if ( overrideCurrentAction
                || (v114 = RGE_Static_Object::unitAI(v112), UnitAIModule::currentAction(v114) == -1) )
              {
                range_4c = *v110;
                if ( *v110 == v6->commanderValue )
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsTheCo_0, range_4c);
                  TribeTacticalAIModule::taskWaterTrader(v7, *v110, v6->targetValue);
                }
                else
                {
                  TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsNotTheC, range_4c);
                  v117 = v112->master_obj->los * 0.5;
                  TribeTacticalAIModule::taskDefender(v7, *v110, v6->commanderValue, v117, 99);
                }
              }
              else
              {
                v115 = RGE_Static_Object::unitAI(v112);
                v116 = UnitAIModule::currentAction(v115);
                TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsBusyWit, *v110, v116);
              }
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(v7, v6->idValue, aUnitDIsGoneRem, *v110);
              TacticalAIGroup::removeUnitByIndex(v6, taskIDg, md);
            }
          }
          ++v110;
          v15 = __OFSUB__(taskIDg + 1, 40);
          v14 = taskIDg++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        result = 1;
        v6->inUseValue = 1;
        if ( resetOriginal == 1 )
        {
          v16 = th;
LABEL_193:
          v118 = v6->numberUnitsValue;
          v6->originalHitPointsValue = (int)v16;
          v6->originalUnitNumberValue = v118;
        }
        break;
      case 5:
      case 6:
      case 12:
      case 19:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aGoingToAddUpTh);
        taskIDh = 0;
        distancea = 0;
        v119 = v6->unitsValue;
        do
        {
          if ( *v119 != -1 )
          {
            TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aCheckingOnUnit, *v119);
            v120 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v119);
            v121 = v120;
            if ( v120 && RGE_Static_Object::unitAI(v120) )
            {
              v122 = (signed __int64)v121->hp;
              v119[40] = v122;
              taskIDh += v122;
            }
            else
            {
              TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aUnitDIsGoneRem, *v119);
              TacticalAIGroup::removeUnitByIndex(v6, distancea, md);
            }
          }
          ++v119;
          v15 = __OFSUB__(distancea + 1, 40);
          v14 = distancea++ - 39 < 0;
        }
        while ( v14 ^ v15 );
        v6->inUseValue = 1;
        if ( resetOriginal != 1 )
          goto LABEL_204;
        v123 = v6->numberUnitsValue;
        v6->originalHitPointsValue = taskIDh;
        v6->originalUnitNumberValue = v123;
        result = 0;
        break;
      default:
        TribeTacticalAIModule::logGroupDebug(t, v6->idValue, aTaskIdDIsAnUnk, taskID);
LABEL_204:
        result = 0;
        break;
    }
  }
  return result;
}

//----- (004ECD80) --------------------------------------------------------
int __thiscall TacticalAIGroup::isGathered(TacticalAIGroup *this, TribeTacticalAIModule *t, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // edi@1
  int v4; // ebx@1
  int *v5; // ebp@1
  RGE_Static_Object *v6; // eax@3
  RGE_Static_Object *v7; // esi@3
  long double v8; // st7@5
  double v9; // st7@8
  float distance; // [sp+10h] [bp-8h]@5

  v3 = this;
  v4 = 0;
  v5 = this->unitsValue;
  while ( *v5 == -1 )
  {
LABEL_13:
    ++v4;
    ++v5;
    if ( v4 >= 40 )
      return 1;
  }
  v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v5);
  v7 = v6;
  if ( !v6 || !RGE_Static_Object::unitAI(v6) )
  {
    TacticalAIGroup::removeUnitByIndex(v3, v4, md);
    goto LABEL_13;
  }
  v8 = RGE_Static_Object::distance_to_position(
         v7,
         v3->gatherLocationValue.x,
         v3->gatherLocationValue.y,
         v3->gatherLocationValue.z)
     - 1.0;
  distance = v8;
  if ( v8 < 0.0 )
    distance = 0.0;
  if ( v3->typeValue == 109 )
    v9 = (double)TribeTacticalAIModule::strategicNumber(t, 23);
  else
    v9 = (double)TribeTacticalAIModule::strategicNumber(t, 41);
  if ( distance <= v9 )
    goto LABEL_13;
  return 0;
}

//----- (004ECE70) --------------------------------------------------------
int __thiscall TacticalAIGroup::isTightGathered(TacticalAIGroup *this, TribeTacticalAIModule *t, TribeMainDecisionAIModule *md)
{
  TacticalAIGroup *v3; // ebx@1
  int v4; // edi@1
  int *v5; // ebp@1
  RGE_Static_Object *v6; // eax@3
  RGE_Static_Object *v7; // esi@3
  long double v8; // st7@5

  v3 = this;
  v4 = 0;
  v5 = this->unitsValue;
  while ( *v5 == -1 )
  {
LABEL_10:
    ++v4;
    ++v5;
    if ( v4 >= 40 )
      return 1;
  }
  v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v5);
  v7 = v6;
  if ( !v6 || !RGE_Static_Object::unitAI(v6) )
  {
    TacticalAIGroup::removeUnitByIndex(v3, v4, md);
    goto LABEL_10;
  }
  v8 = RGE_Static_Object::distance_to_position(
         v7,
         v3->gatherLocationValue.x,
         v3->gatherLocationValue.y,
         v3->gatherLocationValue.z)
     - 2.0;
  if ( v8 < 0.0 )
    v8 = 0.0;
  if ( v8 <= 1.0 )
    goto LABEL_10;
  return 0;
}

//----- (004ECF10) --------------------------------------------------------
int __thiscall TacticalAIGroup::allUnitsIdle(TacticalAIGroup *this, TribeMainDecisionAIModule *md, int countAttackAsIdle)
{
  int v3; // edi@1
  int *v4; // ebp@1
  RGE_Static_Object *v5; // eax@3
  RGE_Static_Object *v6; // esi@3
  UnitAIModule *v7; // eax@7
  int v8; // eax@8
  UnitAIModule *v9; // eax@10
  UnitAIModule *v10; // eax@11
  TacticalAIGroup *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  v3 = 0;
  v4 = this->unitsValue;
  while ( *v4 == -1 )
  {
LABEL_14:
    ++v3;
    ++v4;
    if ( v3 >= 40 )
      return 1;
  }
  v5 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v4);
  v6 = v5;
  if ( !v5 || !RGE_Static_Object::unitAI(v5) )
  {
    TacticalAIGroup::removeUnitByIndex(v12, v3, md);
    goto LABEL_14;
  }
  if ( v6->master_obj->id == 125 )
    goto LABEL_14;
  if ( countAttackAsIdle == 1 )
  {
    v7 = RGE_Static_Object::unitAI(v6);
    if ( UnitAIModule::currentAction(v7) == 600 )
    {
      v8 = v12->typeValue;
      if ( v8 == 100 || v8 == 103 )
        goto LABEL_14;
    }
  }
  v9 = RGE_Static_Object::unitAI(v6);
  if ( UnitAIModule::currentAction(v9) == -1 )
    goto LABEL_14;
  v10 = RGE_Static_Object::unitAI(v6);
  if ( UnitAIModule::currentOrder(v10) == 701 )
    goto LABEL_14;
  return 0;
}

//----- (004ECFE0) --------------------------------------------------------
unsigned int __thiscall TacticalAIGroup::consecutiveIdleUnitCount(TacticalAIGroup *this)
{
  return this->consecutiveIdleUnitCountValue;
}

//----- (004ECFF0) --------------------------------------------------------
void __thiscall TacticalAIGroup::setConsecutiveIdleUnitCount(TacticalAIGroup *this, unsigned int v)
{
  this->consecutiveIdleUnitCountValue = v;
}

//----- (004ED000) --------------------------------------------------------
void __thiscall TacticalAIGroup::incrementConsecutiveIdleUnitCount(TacticalAIGroup *this, unsigned int v)
{
  this->consecutiveIdleUnitCountValue += v;
}

//----- (004ED020) --------------------------------------------------------
char __thiscall TacticalAIGroup::numberAttackWaypoints(TacticalAIGroup *this)
{
  return this->numberAttackWaypointsValue;
}

//----- (004ED030) --------------------------------------------------------
char __thiscall TacticalAIGroup::currentAttackWaypoint(TacticalAIGroup *this)
{
  return this->currentAttackWaypointValue;
}

//----- (004ED040) --------------------------------------------------------
void __thiscall TacticalAIGroup::setCurrentAttackWaypoint(TacticalAIGroup *this, char v)
{
  if ( (unsigned __int8)v < this->numberAttackWaypointsValue )
    this->currentAttackWaypointValue = v;
}

//----- (004ED060) --------------------------------------------------------
void __thiscall TacticalAIGroup::addAttackWaypoint(TacticalAIGroup *this, float x, float y)
{
  if ( this->numberAttackWaypointsValue < 0xEu )
  {
    this->attackWaypoints[this->numberAttackWaypointsValue].x = x;
    this->attackWaypoints[this->numberAttackWaypointsValue].y = y;
    (&this->vfptr)[4 * (this->numberAttackWaypointsValue++ + 30)] = (TacticalAIGroupVtbl *)1065353216;
  }
}

//----- (004ED0C0) --------------------------------------------------------
Waypoint *__thiscall TacticalAIGroup::attackWaypoint(TacticalAIGroup *this, char v)
{
  Waypoint *result; // eax@2

  if ( (unsigned __int8)v >= this->numberAttackWaypointsValue )
    result = 0;
  else
    result = &this->attackWaypoints[(unsigned __int8)v];
  return result;
}

//----- (004ED0F0) --------------------------------------------------------
int __thiscall TacticalAIGroup::firstIdleUnit(TacticalAIGroup *this, TribeMainDecisionAIModule *md)
{
  int *v2; // ebx@1
  int v3; // edi@1
  RGE_Static_Object *v4; // eax@3
  RGE_Static_Object *v5; // esi@3
  UnitAIModule *v6; // eax@5
  TacticalAIGroup *v8; // [sp+10h] [bp-8h]@1
  char *v9; // [sp+14h] [bp-4h]@1

  v2 = this->unitsValue;
  v8 = this;
  v3 = 0;
  v9 = (char *)this->unitsValue;
  while ( *v2 == -1 )
  {
LABEL_8:
    ++v3;
    ++v2;
    if ( v3 >= 40 )
      return -1;
  }
  v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&md->vfptr, *v2);
  v5 = v4;
  if ( !v4 || !RGE_Static_Object::unitAI(v4) )
  {
    TacticalAIGroup::removeUnitByIndex(v8, v3, md);
    goto LABEL_8;
  }
  v6 = RGE_Static_Object::unitAI(v5);
  if ( UnitAIModule::currentAction(v6) != -1 )
    goto LABEL_8;
  return *(_DWORD *)&v9[4 * v3];
}

//----- (004ED170) --------------------------------------------------------
int __thiscall TacticalAIGroup::objectToDestroy(TacticalAIGroup *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= 20 )
    result = -1;
  else
    result = this->objectsToDestroyValue[n];
  return result;
}

//----- (004ED190) --------------------------------------------------------
int __thiscall TacticalAIGroup::addObjectToDestroy(TacticalAIGroup *this, int id)
{
  int v2; // eax@1
  int result; // eax@2

  v2 = this->numberObjectsToDestroyValue;
  if ( v2 >= 19 )
  {
    result = 0;
  }
  else
  {
    this->objectsToDestroyValue[v2] = id;
    ++this->numberObjectsToDestroyValue;
    result = 1;
  }
  return result;
}

//----- (004ED1C0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::TribeTacticalAIModule(TribeTacticalAIModule *this, void *pW, int pID)
{
  TribeTacticalAIModule *v3; // esi@1
  int v4; // ebp@1
  int v5; // eax@1
  signed int v6; // ecx@1
  int v7; // eax@3
  signed int v8; // ecx@3

  v3 = this;
  TacticalAIModule::TacticalAIModule((TacticalAIModule *)&this->vfptr, pW, pID);
  v3->md = 0;
  v3->civilians.value = 0;
  v3->civilians.numberValue = 0;
  v3->civilians.desiredNumberValue = 0;
  v3->civilians.maximumSizeValue = 0;
  v3->civilianExplorers.value = 0;
  v3->civilianExplorers.numberValue = 0;
  v3->civilianExplorers.desiredNumberValue = 0;
  v3->civilianExplorers.maximumSizeValue = 0;
  v3->soldiers.value = 0;
  v3->soldiers.numberValue = 0;
  v3->soldiers.desiredNumberValue = 0;
  v3->soldiers.maximumSizeValue = 0;
  v3->ungroupedSoldiers.value = 0;
  v3->ungroupedSoldiers.numberValue = 0;
  v3->ungroupedSoldiers.desiredNumberValue = 0;
  v3->ungroupedSoldiers.maximumSizeValue = 0;
  v3->boats.value = 0;
  v3->boats.numberValue = 0;
  v3->boats.desiredNumberValue = 0;
  v3->boats.maximumSizeValue = 0;
  v3->warBoats.value = 0;
  v3->warBoats.numberValue = 0;
  v3->warBoats.desiredNumberValue = 0;
  v3->warBoats.maximumSizeValue = 0;
  v3->fishingBoats.value = 0;
  v3->fishingBoats.numberValue = 0;
  v3->fishingBoats.desiredNumberValue = 0;
  v3->fishingBoats.maximumSizeValue = 0;
  v3->tradeBoats.value = 0;
  v3->tradeBoats.numberValue = 0;
  v3->tradeBoats.desiredNumberValue = 0;
  v3->tradeBoats.maximumSizeValue = 0;
  v3->transportBoats.value = 0;
  v3->transportBoats.numberValue = 0;
  v3->transportBoats.desiredNumberValue = 0;
  v3->transportBoats.maximumSizeValue = 0;
  v3->artifacts.value = 0;
  v3->artifacts.numberValue = 0;
  v3->artifacts.desiredNumberValue = 0;
  v3->artifacts.maximumSizeValue = 0;
  v4 = (int)&v3->groups;
  v3->numberGatherersValue = 0;
  v3->desiredNumberGatherersValue = 0;
  TacticalAIGroup::TacticalAIGroup(&v3->groups);
  v3->groupIDValue = 0;
  v3->numberGroupsValue = 0;
  v3->lastGroupAttackTime = 0;
  v3->lastGroupRebalanceTime = 0;
  v3->lastAttackResponseTime = 0;
  v3->lastBoatAttackResponseTime = 0;
  v3->lastScalingUpdateValue = 0;
  v3->numberBuildUpdatesSkipped = 0;
  v3->randomizedAttackSeparationTime = 0;
  v3->playersToAttack.value = 0;
  v3->playersToAttack.numberValue = 0;
  v3->playersToAttack.desiredNumberValue = 0;
  v3->playersToAttack.maximumSizeValue = 0;
  v3->playersToDefend.value = 0;
  v3->playersToDefend.numberValue = 0;
  v3->playersToDefend.desiredNumberValue = 0;
  v3->playersToDefend.maximumSizeValue = 0;
  v3->workingArea.value = 0;
  v3->workingArea.numberValue = 0;
  v3->workingArea.desiredNumberValue = 0;
  v3->workingArea.maximumSizeValue = 0;
  v3->unitsTaskedThisUpdate.value = 0;
  v3->unitsTaskedThisUpdate.numberValue = 0;
  v3->unitsTaskedThisUpdate.desiredNumberValue = 0;
  v3->unitsTaskedThisUpdate.maximumSizeValue = 0;
  ResourceItem::ResourceItem(&v3->neededResources, 4);
  v3->attackEnabledValue = 0;
  v3->updateArea = 0;
  v3->firstNeededResourceUpdateDone = 0;
  v3->wonderInProgressValue = 0;
  v3->wonderBuiltValue = 0;
  v3->nextCivilianToTaskValue = -1;
  v3->nextIdleSoldierGroupToTaskValue = -1;
  v3->nextActiveSoldierGroupToTaskValue = -1;
  v3->builtFirstStoragePit = 0;
  v3->builtFirstGranary = 0;
  v3->lastBuildTime = 0;
  v3->lastAttackResponseBuildInsertionTime = 0;
  v3->lastCoopTributeDemandTime = 0;
  v3->lastCoopTributeGiftTime = 0;
  v3->lastCoopAttackDemandTime = 0;
  v3->zoomingToNextAge = 0;
  v3->lastUngroupedSoldierTaskTime = 0;
  v3->lastUpdateAreaTimeValue = -1;
  v3->averageUpdateAreaTimeValue = -1;
  v3->updateAreaAverageCount = 0;
  v3->updateAreaAverageTotal = 0;
  v3->vfptr = (AIModuleVtbl *)&TribeTacticalAIModule::`vftable';
  v5 = (int)v3->desiredGathererDistribution;
  v6 = 4;
  do
  {
    *(_DWORD *)(v5 + 16) = -1;
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 - 16) = 0;
    *(_DWORD *)(v5 + 32) = 0;
    *(_DWORD *)(v5 + 172) = 0;
    *(_DWORD *)(v5 + 188) = 0;
    v5 += 4;
    --v6;
  }
  while ( v6 );
  memset(v3->sn, 0xFFu, sizeof(v3->sn));
  memset(v3->hitsByPlayer, 0, sizeof(v3->hitsByPlayer));
  v7 = (int)&v3->gatherers[0].data1;
  v8 = 50;
  do
  {
    *(_DWORD *)(v7 - 4) = -1;
    *(_DWORD *)v7 = -1;
    *(_DWORD *)(v7 + 4) = -1;
    *(_DWORD *)(v7 + 8) = -1;
    *(_DWORD *)(v7 + 12) = -1;
    v7 += 24;
    --v8;
  }
  while ( v8 );
  v3->groups.next = (TacticalAIGroup *)v4;
  v3->groups.prev = (TacticalAIGroup *)v4;
  v3->placementStateValue.active = 0;
  v3->attackStateValue.active = 0;
}
// 575788: using guessed type int (__thiscall *TribeTacticalAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004ED4D0) --------------------------------------------------------
TribeTacticalAIModule *__thiscall TribeTacticalAIModule::`scalar deleting destructor'(TribeTacticalAIModule *this, unsigned int __flags)
{
  TribeTacticalAIModule *v2; // esi@1

  v2 = this;
  TribeTacticalAIModule::~TribeTacticalAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004ED4F0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::TribeTacticalAIModule(TribeTacticalAIModule *this, int pID, int infile)
{
  int v3; // ebp@1
  TribeTacticalAIModule *v4; // esi@1
  int *v5; // edi@1
  int v6; // ST00_4@1
  int v7; // ecx@2
  int v8; // eax@2
  int v9; // ebx@7
  int *v10; // edi@7
  int k; // eax@8
  int v12; // ecx@15
  int v13; // eax@15
  int v14; // ebx@20
  int *v15; // edi@20
  int l; // eax@21
  signed int v17; // ebx@29
  int v18; // ecx@30
  int v19; // edx@30
  int v20; // eax@30
  int v21; // ecx@30
  int v22; // edx@32
  int v23; // eax@32
  int v24; // ecx@32
  int v25; // ecx@34
  int v26; // eax@34
  int v27; // ebx@40
  int m; // eax@41
  int v29; // ecx@49
  int v30; // eax@49
  int v31; // ebx@55
  int n; // eax@56
  int v33; // ecx@63
  int v34; // eax@63
  int v35; // ebx@69
  int jj; // eax@70
  int v37; // ecx@77
  int v38; // eax@77
  int v39; // ebx@83
  int kk; // eax@84
  int v41; // ecx@91
  int v42; // eax@91
  int v43; // ebx@97
  int ll; // eax@98
  int v45; // ecx@105
  int v46; // eax@105
  int v47; // ebx@111
  int mm; // eax@112
  int v49; // ecx@119
  int v50; // eax@119
  int v51; // ebx@125
  int nn; // eax@126
  int v53; // ecx@134
  int v54; // eax@134
  int v55; // ebx@140
  int i1; // eax@141
  int v57; // ebp@147
  void *v58; // edi@147
  int *v59; // ebx@148
  int v60; // ecx@151
  int v61; // eax@151
  int v62; // ebx@157
  int i2; // eax@158
  int v64; // ecx@165
  int v65; // eax@165
  int v66; // ebx@171
  int i3; // eax@172
  int v68; // ecx@179
  int v69; // eax@179
  int v70; // ebx@185
  int i4; // eax@186
  int v72; // ecx@193
  int v73; // eax@193
  int v74; // ebx@199
  int i5; // eax@200
  int v76; // ebp@206
  int *v77; // edi@206
  signed int v78; // ebx@206
  int *v79; // edi@208
  signed int v80; // ebx@208
  int *v81; // edi@210
  signed int v82; // ebx@210
  int *v83; // edi@212
  signed int v84; // ebx@212
  int *v85; // edi@214
  signed int v86; // ebx@214
  int *v87; // edi@216
  signed int v88; // ebx@216
  signed int v89; // edi@218
  int *v90; // edi@220
  int v91; // ebx@220
  TacticalAIGroup *v92; // eax@221
  int i; // [sp+10h] [bp-30h]@1
  int ia; // [sp+10h] [bp-30h]@14
  int ib; // [sp+10h] [bp-30h]@33
  int ic; // [sp+10h] [bp-30h]@48
  int id; // [sp+10h] [bp-30h]@62
  int ie; // [sp+10h] [bp-30h]@76
  int if; // [sp+10h] [bp-30h]@90
  int ig; // [sp+10h] [bp-30h]@104
  int ih; // [sp+10h] [bp-30h]@118
  int ii; // [sp+10h] [bp-30h]@133
  int ij; // [sp+10h] [bp-30h]@150
  int ik; // [sp+10h] [bp-30h]@164
  int il; // [sp+10h] [bp-30h]@178
  int im; // [sp+10h] [bp-30h]@192
  int tempInt; // [sp+14h] [bp-2Ch]@2
  int j; // [sp+18h] [bp-28h]@2
  TribeTacticalAIModule *v109; // [sp+1Ch] [bp-24h]@1
  OldUnitData tempUD; // [sp+20h] [bp-20h]@30
  int v111; // [sp+30h] [bp-10h]@30
  int v112; // [sp+3Ch] [bp-4h]@1

  v3 = 0;
  v4 = this;
  v109 = this;
  TacticalAIModule::TacticalAIModule((TacticalAIModule *)&this->vfptr, 0, pID);
  v4->md = 0;
  v112 = 0;
  v4->civilians.value = 0;
  v4->civilians.numberValue = 0;
  v4->civilians.desiredNumberValue = 0;
  v4->civilians.maximumSizeValue = 0;
  v4->civilianExplorers.value = 0;
  v4->civilianExplorers.numberValue = 0;
  v4->civilianExplorers.desiredNumberValue = 0;
  v4->civilianExplorers.maximumSizeValue = 0;
  v4->soldiers.value = 0;
  v4->soldiers.numberValue = 0;
  v4->soldiers.desiredNumberValue = 0;
  v4->soldiers.maximumSizeValue = 0;
  v4->ungroupedSoldiers.value = 0;
  v4->ungroupedSoldiers.numberValue = 0;
  v4->ungroupedSoldiers.desiredNumberValue = 0;
  v4->ungroupedSoldiers.maximumSizeValue = 0;
  v4->boats.value = 0;
  v4->boats.numberValue = 0;
  v4->boats.desiredNumberValue = 0;
  v4->boats.maximumSizeValue = 0;
  v4->warBoats.value = 0;
  v4->warBoats.numberValue = 0;
  v4->warBoats.desiredNumberValue = 0;
  v4->warBoats.maximumSizeValue = 0;
  v4->fishingBoats.value = 0;
  v4->fishingBoats.numberValue = 0;
  v4->fishingBoats.desiredNumberValue = 0;
  v4->fishingBoats.maximumSizeValue = 0;
  v4->tradeBoats.value = 0;
  v4->tradeBoats.numberValue = 0;
  v4->tradeBoats.desiredNumberValue = 0;
  v4->tradeBoats.maximumSizeValue = 0;
  v4->transportBoats.value = 0;
  v4->transportBoats.numberValue = 0;
  v4->transportBoats.desiredNumberValue = 0;
  v4->transportBoats.maximumSizeValue = 0;
  v4->artifacts.value = 0;
  v4->artifacts.numberValue = 0;
  v4->artifacts.desiredNumberValue = 0;
  v4->artifacts.maximumSizeValue = 0;
  TacticalAIGroup::TacticalAIGroup(&v4->groups);
  v4->lastGroupRebalanceTime = 0;
  v4->playersToAttack.value = 0;
  v4->playersToAttack.numberValue = 0;
  v4->playersToAttack.desiredNumberValue = 0;
  v4->playersToAttack.maximumSizeValue = 0;
  v4->playersToDefend.value = 0;
  v4->playersToDefend.numberValue = 0;
  v4->playersToDefend.desiredNumberValue = 0;
  v4->playersToDefend.maximumSizeValue = 0;
  v4->workingArea.value = 0;
  v4->workingArea.numberValue = 0;
  v4->workingArea.desiredNumberValue = 0;
  v4->workingArea.maximumSizeValue = 0;
  v4->unitsTaskedThisUpdate.value = 0;
  v4->unitsTaskedThisUpdate.numberValue = 0;
  v4->unitsTaskedThisUpdate.desiredNumberValue = 0;
  v4->unitsTaskedThisUpdate.maximumSizeValue = 0;
  ResourceItem::ResourceItem(&v4->neededResources, 4);
  v4->groups.next = &v4->groups;
  v4->groups.prev = &v4->groups;
  v5 = (int *)infile;
  v6 = infile;
  LOBYTE(v112) = 16;
  v4->attackEnabledValue = 0;
  v4->updateArea = 0;
  v4->firstNeededResourceUpdateDone = 0;
  v4->wonderInProgressValue = 0;
  v4->wonderBuiltValue = 0;
  v4->nextCivilianToTaskValue = -1;
  v4->nextIdleSoldierGroupToTaskValue = -1;
  v4->nextActiveSoldierGroupToTaskValue = -1;
  v4->builtFirstStoragePit = 0;
  v4->builtFirstGranary = 0;
  v4->lastBuildTime = 0;
  v4->lastAttackResponseBuildInsertionTime = 0;
  v4->lastCoopTributeDemandTime = 0;
  v4->lastCoopTributeGiftTime = 0;
  v4->lastCoopAttackDemandTime = 0;
  v4->zoomingToNextAge = 0;
  v4->lastUngroupedSoldierTaskTime = 0;
  v4->lastUpdateAreaTimeValue = -1;
  v4->averageUpdateAreaTimeValue = -1;
  v4->updateAreaAverageCount = 0;
  v4->updateAreaAverageTotal = 0;
  v4->vfptr = (AIModuleVtbl *)&TribeTacticalAIModule::`vftable';
  rge_read(0, (int)v5, v6, &pID, 4);
  for ( i = 0; i < pID; ++i )
  {
    rge_read(0, (int)v5, (int)v5, &tempInt, 4);
    v7 = v4->civilians.numberValue;
    v8 = 0;
    for ( j = tempInt; v8 < v7; ++v8 )
    {
      if ( v8 >= v4->civilians.maximumSizeValue )
        break;
      if ( v4->civilians.value[v8] == tempInt )
        goto LABEL_13;
    }
    if ( v7 > v4->civilians.maximumSizeValue - 1 )
    {
      v9 = v7 + 1;
      v10 = (int *)operator new(4 * (v7 + 1));
      if ( v10 )
      {
        for ( k = 0; k < v4->civilians.maximumSizeValue; v10[k - 1] = v4->civilians.value[k - 1] )
        {
          if ( k >= v9 )
            break;
          ++k;
        }
        operator delete(v4->civilians.value);
        v4->civilians.value = v10;
        v4->civilians.maximumSizeValue = v9;
      }
    }
    v4->civilians.value[v4->civilians.numberValue++] = j;
LABEL_13:
    v5 = (int *)infile;
  }
  rge_read(0, (int)v5, (int)v5, &pID, 4);
  for ( ia = 0; ia < pID; ++ia )
  {
    rge_read(0, (int)v5, (int)v5, &tempInt, 4);
    v12 = v4->civilianExplorers.numberValue;
    v13 = 0;
    for ( j = tempInt; v13 < v12; ++v13 )
    {
      if ( v13 >= v4->civilianExplorers.maximumSizeValue )
        break;
      if ( v4->civilianExplorers.value[v13] == tempInt )
        goto LABEL_26;
    }
    if ( v12 > v4->civilianExplorers.maximumSizeValue - 1 )
    {
      v14 = v12 + 1;
      v15 = (int *)operator new(4 * (v12 + 1));
      if ( v15 )
      {
        for ( l = 0; l < v4->civilianExplorers.maximumSizeValue; v15[l - 1] = v4->civilianExplorers.value[l - 1] )
        {
          if ( l >= v14 )
            break;
          ++l;
        }
        operator delete(v4->civilianExplorers.value);
        v4->civilianExplorers.value = v15;
        v4->civilianExplorers.maximumSizeValue = v14;
      }
    }
    v4->civilianExplorers.value[v4->civilianExplorers.numberValue++] = j;
LABEL_26:
    v5 = (int *)infile;
  }
  rge_read(0, (int)v5, (int)v5, &v4->numberGatherersValue, 4);
  rge_read(0, (int)v5, (int)v5, &v4->desiredNumberGatherersValue, 4);
  if ( save_game_version < 7.1900001 )
  {
    v5 = &v4->gatherers[0].data1;
    v17 = 50;
    if ( save_game_version < 7.1700001 )
    {
      do
      {
        rge_read(0, (int)v5, infile, &tempUD, 16);
        v22 = tempUD.data1;
        v23 = tempUD.data2;
        *(v5 - 1) = tempUD.id;
        v24 = tempUD.data3;
        *v5 = v22;
        v5[1] = v23;
        v5[2] = v24;
        v5[3] = -1;
        v5[4] = 0;
        v5 += 6;
        --v17;
      }
      while ( v17 );
    }
    else
    {
      do
      {
        rge_read(0, (int)v5, infile, &tempUD, 20);
        v18 = tempUD.data1;
        v19 = tempUD.data2;
        *(v5 - 1) = tempUD.id;
        v20 = tempUD.data3;
        *v5 = v18;
        v21 = v111;
        v5[1] = v19;
        v5[2] = v20;
        v5[3] = v21;
        v5[4] = 0;
        v5 += 6;
        --v17;
      }
      while ( v17 );
    }
  }
  else
  {
    rge_read(0, (int)v5, (int)v5, v4->gatherers, 1200);
  }
  rge_read(0, (int)v5, infile, &pID, 4);
  for ( ib = 0; ib < pID; ++ib )
  {
    rge_read(0, (int)v5, infile, &tempInt, 4);
    v25 = v4->soldiers.numberValue;
    v26 = 0;
    j = tempInt;
    if ( v25 > 0 )
    {
      v5 = (int *)v4->soldiers.maximumSizeValue;
      do
      {
        if ( v26 >= (signed int)v5 )
          break;
        if ( v4->soldiers.value[v26] == tempInt )
          goto LABEL_46;
        ++v26;
      }
      while ( v26 < v25 );
    }
    if ( v25 > v4->soldiers.maximumSizeValue - 1 )
    {
      v27 = v25 + 1;
      v5 = (int *)operator new(4 * (v25 + 1));
      if ( v5 )
      {
        for ( m = 0; m < v4->soldiers.maximumSizeValue; v5[m - 1] = v4->soldiers.value[m - 1] )
        {
          if ( m >= v27 )
            break;
          ++m;
        }
        operator delete(v4->soldiers.value);
        v4->soldiers.value = v5;
        v4->soldiers.maximumSizeValue = v27;
      }
    }
    v4->soldiers.value[v4->soldiers.numberValue++] = j;
LABEL_46:
    ;
  }
  if ( save_game_version >= 2.3 )
  {
    rge_read(0, (int)v5, infile, &pID, 4);
    for ( ic = 0; ic < pID; ++ic )
    {
      rge_read(0, (int)v5, infile, &tempInt, 4);
      v29 = v4->ungroupedSoldiers.numberValue;
      v30 = 0;
      j = tempInt;
      if ( v29 > 0 )
      {
        v5 = (int *)v4->ungroupedSoldiers.maximumSizeValue;
        do
        {
          if ( v30 >= (signed int)v5 )
            break;
          if ( v4->ungroupedSoldiers.value[v30] == tempInt )
            goto LABEL_61;
          ++v30;
        }
        while ( v30 < v29 );
      }
      if ( v29 > v4->ungroupedSoldiers.maximumSizeValue - 1 )
      {
        v31 = v29 + 1;
        v5 = (int *)operator new(4 * (v29 + 1));
        if ( v5 )
        {
          for ( n = 0; n < v4->ungroupedSoldiers.maximumSizeValue; v5[n - 1] = v4->ungroupedSoldiers.value[n - 1] )
          {
            if ( n >= v31 )
              break;
            ++n;
          }
          operator delete(v4->ungroupedSoldiers.value);
          v4->ungroupedSoldiers.value = v5;
          v4->ungroupedSoldiers.maximumSizeValue = v31;
        }
      }
      v4->ungroupedSoldiers.value[v4->ungroupedSoldiers.numberValue++] = j;
LABEL_61:
      ;
    }
  }
  rge_read(0, (int)v5, infile, &pID, 4);
  for ( id = 0; id < pID; ++id )
  {
    rge_read(0, (int)v5, infile, &tempInt, 4);
    v33 = v4->boats.numberValue;
    v34 = 0;
    j = tempInt;
    if ( v33 > 0 )
    {
      v5 = (int *)v4->boats.maximumSizeValue;
      do
      {
        if ( v34 >= (signed int)v5 )
          break;
        if ( v4->boats.value[v34] == tempInt )
          goto LABEL_75;
        ++v34;
      }
      while ( v34 < v33 );
    }
    if ( v33 > v4->boats.maximumSizeValue - 1 )
    {
      v35 = v33 + 1;
      v5 = (int *)operator new(4 * (v33 + 1));
      if ( v5 )
      {
        for ( jj = 0; jj < v4->boats.maximumSizeValue; v5[jj - 1] = v4->boats.value[jj - 1] )
        {
          if ( jj >= v35 )
            break;
          ++jj;
        }
        operator delete(v4->boats.value);
        v4->boats.value = v5;
        v4->boats.maximumSizeValue = v35;
      }
    }
    v4->boats.value[v4->boats.numberValue++] = j;
LABEL_75:
    ;
  }
  rge_read(0, (int)v5, infile, &pID, 4);
  for ( ie = 0; ie < pID; ++ie )
  {
    rge_read(v3, (int)v5, infile, &tempInt, 4);
    v37 = v4->warBoats.numberValue;
    v38 = 0;
    v3 = tempInt;
    if ( v37 > 0 )
    {
      v5 = (int *)v4->warBoats.maximumSizeValue;
      do
      {
        if ( v38 >= (signed int)v5 )
          break;
        if ( v4->warBoats.value[v38] == tempInt )
          goto LABEL_89;
        ++v38;
      }
      while ( v38 < v37 );
    }
    if ( v37 > v4->warBoats.maximumSizeValue - 1 )
    {
      v39 = v37 + 1;
      v5 = (int *)operator new(4 * (v37 + 1));
      if ( v5 )
      {
        for ( kk = 0; kk < v4->warBoats.maximumSizeValue; v5[kk - 1] = v4->warBoats.value[kk - 1] )
        {
          if ( kk >= v39 )
            break;
          ++kk;
        }
        operator delete(v4->warBoats.value);
        v4->warBoats.value = v5;
        v4->warBoats.maximumSizeValue = v39;
      }
    }
    v4->warBoats.value[v4->warBoats.numberValue++] = v3;
LABEL_89:
    ;
  }
  rge_read(v3, (int)v5, infile, &pID, 4);
  for ( if = 0; if < pID; ++if )
  {
    rge_read(v3, (int)v5, infile, &tempInt, 4);
    v41 = v4->fishingBoats.numberValue;
    v42 = 0;
    v3 = tempInt;
    if ( v41 > 0 )
    {
      v5 = (int *)v4->fishingBoats.maximumSizeValue;
      do
      {
        if ( v42 >= (signed int)v5 )
          break;
        if ( v4->fishingBoats.value[v42] == tempInt )
          goto LABEL_103;
        ++v42;
      }
      while ( v42 < v41 );
    }
    if ( v41 > v4->fishingBoats.maximumSizeValue - 1 )
    {
      v43 = v41 + 1;
      v5 = (int *)operator new(4 * (v41 + 1));
      if ( v5 )
      {
        for ( ll = 0; ll < v4->fishingBoats.maximumSizeValue; v5[ll - 1] = v4->fishingBoats.value[ll - 1] )
        {
          if ( ll >= v43 )
            break;
          ++ll;
        }
        operator delete(v4->fishingBoats.value);
        v4->fishingBoats.value = v5;
        v4->fishingBoats.maximumSizeValue = v43;
      }
    }
    v4->fishingBoats.value[v4->fishingBoats.numberValue++] = v3;
LABEL_103:
    ;
  }
  rge_read(v3, (int)v5, infile, &pID, 4);
  for ( ig = 0; ig < pID; ++ig )
  {
    rge_read(v3, (int)v5, infile, &tempInt, 4);
    v45 = v4->tradeBoats.numberValue;
    v46 = 0;
    v3 = tempInt;
    if ( v45 > 0 )
    {
      v5 = (int *)v4->tradeBoats.maximumSizeValue;
      do
      {
        if ( v46 >= (signed int)v5 )
          break;
        if ( v4->tradeBoats.value[v46] == tempInt )
          goto LABEL_117;
        ++v46;
      }
      while ( v46 < v45 );
    }
    if ( v45 > v4->tradeBoats.maximumSizeValue - 1 )
    {
      v47 = v45 + 1;
      v5 = (int *)operator new(4 * (v45 + 1));
      if ( v5 )
      {
        for ( mm = 0; mm < v4->tradeBoats.maximumSizeValue; v5[mm - 1] = v4->tradeBoats.value[mm - 1] )
        {
          if ( mm >= v47 )
            break;
          ++mm;
        }
        operator delete(v4->tradeBoats.value);
        v4->tradeBoats.value = v5;
        v4->tradeBoats.maximumSizeValue = v47;
      }
    }
    v4->tradeBoats.value[v4->tradeBoats.numberValue++] = v3;
LABEL_117:
    ;
  }
  rge_read(v3, (int)v5, infile, &pID, 4);
  for ( ih = 0; ih < pID; ++ih )
  {
    rge_read(v3, (int)v5, infile, &tempInt, 4);
    v49 = v4->transportBoats.numberValue;
    v50 = 0;
    v3 = tempInt;
    if ( v49 > 0 )
    {
      v5 = (int *)v4->transportBoats.maximumSizeValue;
      do
      {
        if ( v50 >= (signed int)v5 )
          break;
        if ( v4->transportBoats.value[v50] == tempInt )
          goto LABEL_131;
        ++v50;
      }
      while ( v50 < v49 );
    }
    if ( v49 > v4->transportBoats.maximumSizeValue - 1 )
    {
      v51 = v49 + 1;
      v5 = (int *)operator new(4 * (v49 + 1));
      if ( v5 )
      {
        for ( nn = 0; nn < v4->transportBoats.maximumSizeValue; v5[nn - 1] = v4->transportBoats.value[nn - 1] )
        {
          if ( nn >= v51 )
            break;
          ++nn;
        }
        operator delete(v4->transportBoats.value);
        v4->transportBoats.value = v5;
        v4->transportBoats.maximumSizeValue = v51;
      }
    }
    v4->transportBoats.value[v4->transportBoats.numberValue++] = v3;
LABEL_131:
    ;
  }
  if ( save_game_version >= 1.4 )
  {
    rge_read(v3, (int)v5, infile, &pID, 4);
    for ( ii = 0; ii < pID; ++ii )
    {
      rge_read(v3, (int)v5, infile, &tempInt, 4);
      v53 = v4->artifacts.numberValue;
      v54 = 0;
      v3 = tempInt;
      if ( v53 > 0 )
      {
        v5 = (int *)v4->artifacts.maximumSizeValue;
        do
        {
          if ( v54 >= (signed int)v5 )
            break;
          if ( v4->artifacts.value[v54] == tempInt )
            goto LABEL_146;
          ++v54;
        }
        while ( v54 < v53 );
      }
      if ( v53 > v4->artifacts.maximumSizeValue - 1 )
      {
        v55 = v53 + 1;
        v5 = (int *)operator new(4 * (v53 + 1));
        if ( v5 )
        {
          for ( i1 = 0; i1 < v4->artifacts.maximumSizeValue; v5[i1 - 1] = v4->artifacts.value[i1 - 1] )
          {
            if ( i1 >= v55 )
              break;
            ++i1;
          }
          operator delete(v4->artifacts.value);
          v4->artifacts.value = v5;
          v4->artifacts.maximumSizeValue = v55;
        }
      }
      v4->artifacts.value[v4->artifacts.numberValue++] = v3;
LABEL_146:
      ;
    }
  }
  v57 = infile;
  rge_read(infile, (int)v5, infile, &pID, 4);
  v58 = 0;
  if ( pID > 0 )
  {
    v59 = v4->sn;
    do
    {
      rge_read(v57, (int)v58, v57, v59, 4);
      v58 = (char *)v58 + 1;
      ++v59;
    }
    while ( (signed int)v58 < pID );
  }
  rge_read(v57, (int)v58, v57, &pID, 4);
  for ( ij = 0; ij < pID; ++ij )
  {
    rge_read(v57, (int)v58, infile, &tempInt, 4);
    v60 = v4->playersToAttack.numberValue;
    v61 = 0;
    v57 = tempInt;
    if ( v60 > 0 )
    {
      v58 = (void *)v4->playersToAttack.maximumSizeValue;
      do
      {
        if ( v61 >= (signed int)v58 )
          break;
        if ( v4->playersToAttack.value[v61] == tempInt )
          goto LABEL_163;
        ++v61;
      }
      while ( v61 < v60 );
    }
    if ( v60 > v4->playersToAttack.maximumSizeValue - 1 )
    {
      v62 = v60 + 1;
      v58 = operator new(4 * (v60 + 1));
      if ( v58 )
      {
        for ( i2 = 0;
              i2 < v4->playersToAttack.maximumSizeValue;
              *((_DWORD *)v58 + i2 - 1) = v4->playersToAttack.value[i2 - 1] )
        {
          if ( i2 >= v62 )
            break;
          ++i2;
        }
        operator delete(v4->playersToAttack.value);
        v4->playersToAttack.value = (int *)v58;
        v4->playersToAttack.maximumSizeValue = v62;
      }
    }
    v4->playersToAttack.value[v4->playersToAttack.numberValue++] = v57;
LABEL_163:
    ;
  }
  rge_read(v57, (int)v58, infile, &pID, 4);
  for ( ik = 0; ik < pID; ++ik )
  {
    rge_read(v57, (int)v58, infile, &tempInt, 4);
    v64 = v4->playersToDefend.numberValue;
    v65 = 0;
    v57 = tempInt;
    if ( v64 > 0 )
    {
      v58 = (void *)v4->playersToDefend.maximumSizeValue;
      do
      {
        if ( v65 >= (signed int)v58 )
          break;
        if ( v4->playersToDefend.value[v65] == tempInt )
          goto LABEL_177;
        ++v65;
      }
      while ( v65 < v64 );
    }
    if ( v64 > v4->playersToDefend.maximumSizeValue - 1 )
    {
      v66 = v64 + 1;
      v58 = operator new(4 * (v64 + 1));
      if ( v58 )
      {
        for ( i3 = 0;
              i3 < v4->playersToDefend.maximumSizeValue;
              *((_DWORD *)v58 + i3 - 1) = v4->playersToDefend.value[i3 - 1] )
        {
          if ( i3 >= v66 )
            break;
          ++i3;
        }
        operator delete(v4->playersToDefend.value);
        v4->playersToDefend.value = (int *)v58;
        v4->playersToDefend.maximumSizeValue = v66;
      }
    }
    v4->playersToDefend.value[v4->playersToDefend.numberValue++] = v57;
LABEL_177:
    ;
  }
  rge_read(v57, (int)v58, infile, &pID, 4);
  for ( il = 0; il < pID; ++il )
  {
    rge_read(v57, (int)v58, infile, &tempInt, 4);
    v68 = v4->workingArea.numberValue;
    v69 = 0;
    v57 = tempInt;
    if ( v68 > 0 )
    {
      v58 = (void *)v4->workingArea.maximumSizeValue;
      do
      {
        if ( v69 >= (signed int)v58 )
          break;
        if ( v4->workingArea.value[v69] == tempInt )
          goto LABEL_191;
        ++v69;
      }
      while ( v69 < v68 );
    }
    if ( v68 > v4->workingArea.maximumSizeValue - 1 )
    {
      v70 = v68 + 1;
      v58 = operator new(4 * (v68 + 1));
      if ( v58 )
      {
        for ( i4 = 0; i4 < v4->workingArea.maximumSizeValue; *((_DWORD *)v58 + i4 - 1) = v4->workingArea.value[i4 - 1] )
        {
          if ( i4 >= v70 )
            break;
          ++i4;
        }
        operator delete(v4->workingArea.value);
        v4->workingArea.value = (int *)v58;
        v4->workingArea.maximumSizeValue = v70;
      }
    }
    v4->workingArea.value[v4->workingArea.numberValue++] = v57;
LABEL_191:
    ;
  }
  rge_read(v57, (int)v58, infile, &pID, 4);
  for ( im = 0; im < pID; ++im )
  {
    rge_read(v57, (int)v58, infile, &tempInt, 4);
    v72 = v4->unitsTaskedThisUpdate.numberValue;
    v73 = 0;
    v57 = tempInt;
    if ( v72 > 0 )
    {
      v58 = (void *)v4->unitsTaskedThisUpdate.maximumSizeValue;
      do
      {
        if ( v73 >= (signed int)v58 )
          break;
        if ( v4->unitsTaskedThisUpdate.value[v73] == tempInt )
          goto LABEL_205;
        ++v73;
      }
      while ( v73 < v72 );
    }
    if ( v72 > v4->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v74 = v72 + 1;
      v58 = operator new(4 * (v72 + 1));
      if ( v58 )
      {
        for ( i5 = 0;
              i5 < v4->unitsTaskedThisUpdate.maximumSizeValue;
              *((_DWORD *)v58 + i5 - 1) = v4->unitsTaskedThisUpdate.value[i5 - 1] )
        {
          if ( i5 >= v74 )
            break;
          ++i5;
        }
        operator delete(v4->unitsTaskedThisUpdate.value);
        v4->unitsTaskedThisUpdate.value = (int *)v58;
        v4->unitsTaskedThisUpdate.maximumSizeValue = v74;
      }
    }
    v4->unitsTaskedThisUpdate.value[v4->unitsTaskedThisUpdate.numberValue++] = v57;
LABEL_205:
    ;
  }
  v76 = infile;
  v77 = v4->actualGathererDistribution;
  v78 = 4;
  do
  {
    rge_read(v76, (int)v77, v76, v77, 4);
    ++v77;
    --v78;
  }
  while ( v78 );
  v79 = v4->desiredGathererDistribution;
  v80 = 4;
  do
  {
    rge_read(v76, (int)v79, v76, v79, 4);
    ++v79;
    --v80;
  }
  while ( v80 );
  v81 = v4->neededResourceValue;
  v82 = 4;
  do
  {
    rge_read(v76, (int)v81, v76, v81, 4);
    ++v81;
    --v82;
  }
  while ( v82 );
  v83 = v4->resourceDifferenceValue;
  v84 = 4;
  do
  {
    rge_read(v76, (int)v83, v76, v83, 4);
    ++v83;
    --v84;
  }
  while ( v84 );
  v85 = v4->numberStoragePitsBuilt;
  v86 = 4;
  do
  {
    rge_read(v76, (int)v85, v76, v85, 4);
    ++v85;
    --v86;
  }
  while ( v86 );
  v87 = v4->numberGranariesBuilt;
  v88 = 4;
  do
  {
    rge_read(v76, (int)v87, v76, v87, 4);
    ++v87;
    --v88;
  }
  while ( v88 );
  v89 = 0;
  do
  {
    rge_read(v76, v89, v76, &tempInt, 4);
    ResourceItem::setValue(&v4->neededResources, v89++, tempInt);
  }
  while ( v89 < 4 );
  rge_read(v76, v89, v76, &v4->groupIDValue, 4);
  v90 = &v4->numberGroupsValue;
  rge_read(v76, (int)&v4->numberGroupsValue, v76, &v4->numberGroupsValue, 4);
  v91 = 0;
  if ( v4->numberGroupsValue > 0 )
  {
    do
    {
      v92 = TribeTacticalAIModule::createGroup(v4, 0);
      if ( v92 )
        TacticalAIGroup::load(v92, v76, v76);
      ++v91;
    }
    while ( v91 < *v90 );
  }
  rge_read(v76, (int)v90, v76, &v4->lastGroupAttackTime, 4);
  if ( save_game_version >= 2.4000001 )
    rge_read(v76, (int)v90, v76, &v4->lastGroupRebalanceTime, 4);
  rge_read(v76, (int)v90, v76, &v4->lastAttackResponseTime, 4);
  rge_read(v76, (int)v90, v76, &v4->lastBoatAttackResponseTime, 4);
  rge_read(v76, (int)v90, v76, &v4->lastScalingUpdateValue, 4);
  rge_read(v76, (int)v90, v76, &v4->numberBuildUpdatesSkipped, 4);
  rge_read(v76, (int)v90, v76, &v4->randomizedAttackSeparationTime, 4);
  if ( save_game_version >= 2.2 )
    rge_read(v76, (int)v90, v76, &v4->attackEnabledValue, 4);
  rge_read(v76, (int)v90, v76, &v4->updateArea, 4);
  if ( save_game_version >= 6.0999999 )
  {
    rge_read(v76, (int)v90, v76, &v4->wonderInProgressValue, 4);
    rge_read(v76, (int)v90, v76, &v4->wonderBuiltValue, 4);
  }
  if ( save_game_version < 6.1999998 )
  {
    memset(&v4->placementStateValue, 0, sizeof(v4->placementStateValue));
    v90 = &v4->nextCivilianToTaskValue;
  }
  else
  {
    rge_read(v76, (int)v90, v76, &v4->placementStateValue, 304);
  }
  v4->placementStateValue.active = 0;
  if ( save_game_version >= 6.3000002 )
    rge_read(v76, (int)v90, v76, &v4->nextCivilianToTaskValue, 4);
  if ( save_game_version >= 6.4000001 )
  {
    rge_read(v76, (int)v90, v76, &v4->nextIdleSoldierGroupToTaskValue, 4);
    rge_read(v76, (int)v90, v76, &v4->nextActiveSoldierGroupToTaskValue, 4);
  }
  if ( save_game_version >= 6.9000001 )
  {
    rge_read(v76, (int)v90, v76, &v4->builtFirstStoragePit, 4);
    rge_read(v76, (int)v90, v76, &v4->builtFirstGranary, 4);
  }
  if ( save_game_version >= 6.9499998 )
  {
    rge_read(v76, (int)v90, v76, &v4->lastBuildTime, 4);
    rge_read(v76, (int)v90, v76, &v4->lastAttackResponseBuildInsertionTime, 4);
    rge_read(v76, (int)v90, v76, &v4->lastCoopTributeDemandTime, 4);
  }
  if ( save_game_version >= 7.1799998 )
    rge_read(v76, (int)v90, v76, &v4->lastCoopTributeGiftTime, 4);
  if ( save_game_version >= 6.96 )
    rge_read(v76, (int)v90, v76, &v4->zoomingToNextAge, 4);
  if ( save_game_version >= 6.98 )
    rge_read(v76, (int)v90, v76, &v4->lastCoopAttackDemandTime, 4);
  if ( save_game_version >= 6.993 )
    rge_read(v76, (int)v90, v76, &v4->lastUngroupedSoldierTaskTime, 4);
  if ( save_game_version < 7.04 )
  {
    memset(&v4->attackStateValue, 0, sizeof(v4->attackStateValue));
    v90 = v4->hitsByPlayer;
  }
  else
  {
    rge_read(v76, (int)v90, v76, &v4->attackStateValue, 44);
  }
  v4->attackStateValue.active = 0;
  if ( save_game_version < 7.1500001 )
    memset(v4->hitsByPlayer, 0, sizeof(v4->hitsByPlayer));
  else
    rge_read(v76, (int)v90, v76, v4->hitsByPlayer, 36);
}
// 575788: using guessed type int (__thiscall *TribeTacticalAIModule::`vftable')(void *Memory, unsigned int __flags);
// 58EBCC: using guessed type float save_game_version;

//----- (004EEB40) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::~TribeTacticalAIModule(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int *v2; // eax@1
  int *v3; // eax@3
  int *v4; // eax@5
  int *v5; // eax@7
  int *v6; // eax@9
  int *v7; // eax@11
  int *v8; // eax@13
  int *v9; // eax@15
  int *v10; // eax@17
  int *v11; // eax@19
  int *v12; // eax@21
  int *v13; // eax@23
  int *v14; // eax@25

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&TribeTacticalAIModule::`vftable';
  TribeTacticalAIModule::removeAllGroups(this, -1);
  ResourceItem::~ResourceItem(&v1->neededResources);
  v2 = v1->unitsTaskedThisUpdate.value;
  if ( v2 )
  {
    operator delete(v2);
    v1->unitsTaskedThisUpdate.value = 0;
  }
  v1->unitsTaskedThisUpdate.numberValue = 0;
  v1->unitsTaskedThisUpdate.desiredNumberValue = 0;
  v1->unitsTaskedThisUpdate.maximumSizeValue = 0;
  v3 = v1->workingArea.value;
  if ( v3 )
  {
    operator delete(v3);
    v1->workingArea.value = 0;
  }
  v1->workingArea.numberValue = 0;
  v1->workingArea.desiredNumberValue = 0;
  v1->workingArea.maximumSizeValue = 0;
  v4 = v1->playersToDefend.value;
  if ( v4 )
  {
    operator delete(v4);
    v1->playersToDefend.value = 0;
  }
  v1->playersToDefend.numberValue = 0;
  v1->playersToDefend.desiredNumberValue = 0;
  v1->playersToDefend.maximumSizeValue = 0;
  v5 = v1->playersToAttack.value;
  if ( v5 )
  {
    operator delete(v5);
    v1->playersToAttack.value = 0;
  }
  v1->playersToAttack.numberValue = 0;
  v1->playersToAttack.desiredNumberValue = 0;
  v1->playersToAttack.maximumSizeValue = 0;
  TacticalAIGroup::~TacticalAIGroup(&v1->groups);
  v6 = v1->artifacts.value;
  if ( v6 )
  {
    operator delete(v6);
    v1->artifacts.value = 0;
  }
  v1->artifacts.numberValue = 0;
  v1->artifacts.desiredNumberValue = 0;
  v1->artifacts.maximumSizeValue = 0;
  v7 = v1->transportBoats.value;
  if ( v7 )
  {
    operator delete(v7);
    v1->transportBoats.value = 0;
  }
  v1->transportBoats.numberValue = 0;
  v1->transportBoats.desiredNumberValue = 0;
  v1->transportBoats.maximumSizeValue = 0;
  v8 = v1->tradeBoats.value;
  if ( v8 )
  {
    operator delete(v8);
    v1->tradeBoats.value = 0;
  }
  v1->tradeBoats.numberValue = 0;
  v1->tradeBoats.desiredNumberValue = 0;
  v1->tradeBoats.maximumSizeValue = 0;
  v9 = v1->fishingBoats.value;
  if ( v9 )
  {
    operator delete(v9);
    v1->fishingBoats.value = 0;
  }
  v1->fishingBoats.numberValue = 0;
  v1->fishingBoats.desiredNumberValue = 0;
  v1->fishingBoats.maximumSizeValue = 0;
  v10 = v1->warBoats.value;
  if ( v10 )
  {
    operator delete(v10);
    v1->warBoats.value = 0;
  }
  v1->warBoats.numberValue = 0;
  v1->warBoats.desiredNumberValue = 0;
  v1->warBoats.maximumSizeValue = 0;
  v11 = v1->boats.value;
  if ( v11 )
  {
    operator delete(v11);
    v1->boats.value = 0;
  }
  v1->boats.numberValue = 0;
  v1->boats.desiredNumberValue = 0;
  v1->boats.maximumSizeValue = 0;
  v12 = v1->ungroupedSoldiers.value;
  if ( v12 )
  {
    operator delete(v12);
    v1->ungroupedSoldiers.value = 0;
  }
  v1->ungroupedSoldiers.numberValue = 0;
  v1->ungroupedSoldiers.desiredNumberValue = 0;
  v1->ungroupedSoldiers.maximumSizeValue = 0;
  v13 = v1->soldiers.value;
  if ( v13 )
  {
    operator delete(v13);
    v1->soldiers.value = 0;
  }
  v1->soldiers.numberValue = 0;
  v1->soldiers.desiredNumberValue = 0;
  v1->soldiers.maximumSizeValue = 0;
  v14 = v1->civilianExplorers.value;
  if ( v14 )
  {
    operator delete(v14);
    v1->civilianExplorers.value = 0;
  }
  v1->civilianExplorers.numberValue = 0;
  v1->civilianExplorers.desiredNumberValue = 0;
  v1->civilianExplorers.maximumSizeValue = 0;
  ManagedArray<int>::~ManagedArray<int>(&v1->civilians);
  TacticalAIModule::~TacticalAIModule((TacticalAIModule *)&v1->vfptr);
}
// 575788: using guessed type int (__thiscall *TribeTacticalAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004EEE40) --------------------------------------------------------
char *__thiscall TribeTacticalAIModule::updateAreaName(TribeTacticalAIModule *this)
{
  char *result; // eax@2

  switch ( this->updateArea )
  {
    case 0:
      result = aSetupSolgroups;
      break;
    case 1:
      result = aEvalCivdist;
      break;
    case 2:
      result = aTaskCivs;
      break;
    case 3:
      result = aSetupBoatgroup;
      break;
    case 4:
      result = aFillBoatgroups;
      break;
    case 5:
      result = aTaskBoats;
      break;
    case 6:
      result = aFillSolgroups;
      break;
    case 7:
      result = aTaskIdlesol;
      break;
    case 8:
      result = aTaskActsol;
      break;
    case 9:
      result = aPlaytasking;
      break;
    case 0xA:
      result = aTaskUngrpsol;
      break;
    case 0xB:
      result = aResearch;
      break;
    case 0xC:
      result = aTrain;
      break;
    case 0xD:
      result = aBldlstChange;
      break;
    case 0xE:
      result = aHelpBuild;
      break;
    case 0xF:
      result = aRepairBldg;
      break;
    case 0x10:
      result = aRepairWall;
      break;
    case 0x11:
      result = aBuild;
      break;
    case 0x12:
      result = aOpenBuilds;
      break;
    case 0x13:
      result = aOpenTasks;
      break;
    case 0x14:
      result = aFoodDropsite;
      break;
    case 0x15:
      result = aBldlstInsertio;
      break;
    default:
      result = aInvalid;
      break;
  }
  return result;
}

//----- (004EEF40) --------------------------------------------------------
int __userpurge TribeTacticalAIModule::update@<eax>(TribeTacticalAIModule *this@<ecx>, double a2@<st0>, int timeLimit)
{
  TribeTacticalAIModule *v3; // esi@1
  TribeMainDecisionAIModule *v4; // edx@1
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // eax@4
  int v8; // ecx@4
  int v9; // eax@6
  int v10; // ecx@8
  int v11; // eax@10
  int v12; // eax@14
  int v13; // eax@18
  int v14; // ebp@25
  int *v20; // edi@30
  signed int i; // eax@31
  int v22; // ebp@36
  int *v28; // edi@41
  signed int j; // eax@42
  int v30; // ebx@47
  int v31; // ecx@48
  int k; // eax@48
  int v33; // ebx@53
  int *v34; // edi@53
  int l; // eax@54
  TribeMainDecisionAIModule *v36; // eax@60
  int v37; // edi@60
  RGE_Player *v38; // ecx@60
  int mostHatedPlayer; // [sp+10h] [bp-8h]@25
  int mostLikedPlayer; // [sp+14h] [bp-4h]@25

  v3 = this;
  v4 = this->md;
  if ( v4->player->world->world_time - this->lastScalingUpdateValue > 60000 * this->sn[99] )
  {
    v5 = this->sn[94];
    v6 = v3->sn[26];
    v3->sn[26] = v5 + v6;
    if ( v5 + v6 < 0 )
      v3->sn[26] = 0;
    v7 = v3->sn[93];
    v8 = v3->sn[16];
    v3->sn[16] = v7 + v8;
    if ( v7 + v8 < 0 )
      v3->sn[16] = 0;
    v9 = v3->sn[26];
    if ( v3->sn[16] > v9 )
      v3->sn[16] = v9;
    v10 = v3->sn[16];
    if ( v9 < v10 )
      v3->sn[26] = v10;
    v11 = 2 * v3->sn[30];
    v3->sn[30] = v11;
    if ( v11 < 0 )
      v3->sn[30] = 0;
    if ( v3->sn[30] > 100 )
      v3->sn[30] = 100;
    v12 = 2 * v3->sn[31];
    v3->sn[31] = v12;
    if ( v12 < 0 )
      v3->sn[31] = 0;
    if ( v3->sn[31] > 100 )
      v3->sn[31] = 100;
    v13 = 2 * v3->sn[91];
    v3->sn[91] = v13;
    if ( v13 < 0 )
      v3->sn[91] = 0;
    if ( v3->sn[91] > 100 )
      v3->sn[91] = 100;
    v3->lastScalingUpdateValue = v4->player->world->world_time;
  }
  v3->unitsTaskedThisUpdate.numberValue = 0;
  v3->md->informationAI.farmsTaskedThisUpdate.numberValue = 0;
  if ( v3->md->player->world->world_time / 0x3E8 >= v3->sn[104] )
    TribeTacticalAIModule::enableAttack(v3, 2);
  v14 = DiplomacyAIModule::mostHated(&v3->md->diplomacyAI, v3->sn[124], v3->sn[128], v3->sn[188], v3->sn[195]);
  mostHatedPlayer = v14;
  mostLikedPlayer = DiplomacyAIModule::mostLiked(&v3->md->diplomacyAI, v3->sn[124], v3->sn[128]);
  v3->playersToAttack.numberValue = 0;
  if ( v3->playersToAttack.maximumSizeValue - 1 < 0 )
  {
    v20 = (int *)operator new(4u);
    if ( v20 )
    {
      for ( i = 0; i < v3->playersToAttack.maximumSizeValue; v20[i - 1] = v3->playersToAttack.value[i - 1] )
      {
        if ( i >= 1 )
          break;
        ++i;
      }
      operator delete(v3->playersToAttack.value);
      v3->playersToAttack.value = v20;
      v3->playersToAttack.maximumSizeValue = 1;
    }
  }
  v3->playersToAttack.value[v3->playersToAttack.numberValue++] = v14;
  v3->playersToDefend.numberValue = 0;
  v22 = v3->md->player->id;
  if ( v3->playersToDefend.maximumSizeValue - 1 < 0 )
  {
    v28 = (int *)operator new(4u);
    if ( v28 )
    {
      for ( j = 0; j < v3->playersToDefend.maximumSizeValue; v28[j - 1] = v3->playersToDefend.value[j - 1] )
      {
        if ( j >= 1 )
          break;
        ++j;
      }
      operator delete(v3->playersToDefend.value);
      v3->playersToDefend.value = v28;
      v3->playersToDefend.maximumSizeValue = 1;
    }
  }
  v3->playersToDefend.value[v3->playersToDefend.numberValue++] = v22;
  v30 = mostHatedPlayer;
  if ( mostHatedPlayer != mostLikedPlayer )
  {
    v31 = v3->playersToDefend.numberValue;
    for ( k = 0; k < v31; ++k )
    {
      if ( k >= v3->playersToDefend.maximumSizeValue )
        break;
      if ( v3->playersToDefend.value[k] == mostLikedPlayer )
        goto LABEL_60;
    }
    if ( v31 > v3->playersToDefend.maximumSizeValue - 1 )
    {
      v33 = v31 + 1;
      v34 = (int *)operator new(4 * (v31 + 1));
      if ( v34 )
      {
        for ( l = 0; l < v3->playersToDefend.maximumSizeValue; v34[l - 1] = v3->playersToDefend.value[l - 1] )
        {
          if ( l >= v33 )
            break;
          ++l;
        }
        operator delete(v3->playersToDefend.value);
        v3->playersToDefend.value = v34;
        v3->playersToDefend.maximumSizeValue = v33;
      }
      v30 = mostHatedPlayer;
    }
    v3->playersToDefend.value[v3->playersToDefend.numberValue++] = mostLikedPlayer;
  }
LABEL_60:
  v36 = v3->md;
  v37 = 1;
  v38 = v36->player;
  if ( v38->world->player_num > 1 )
  {
    do
    {
      if ( v37 != v38->id )
      {
        if ( v37 == v30 )
        {
          if ( !DiplomacyAIModule::isEnemy(&v36->diplomacyAI, v37)
            && DiplomacyAIModule::isChangeable(&v3->md->diplomacyAI, v37)
            && DiplomacyAIModule::stance(&v3->md->diplomacyAI, v37, 0) > 74 )
          {
            DiplomacyAIModule::setRelation(&v3->md->diplomacyAI, v37, 3);
          }
        }
        else if ( v37 == mostLikedPlayer )
        {
          if ( !DiplomacyAIModule::isAlly(&v36->diplomacyAI, v37)
            && DiplomacyAIModule::isChangeable(&v3->md->diplomacyAI, v37)
            && DiplomacyAIModule::stance(&v3->md->diplomacyAI, v37, 2) > 74 )
          {
            DiplomacyAIModule::setRelation(&v3->md->diplomacyAI, v37, 0);
          }
        }
        else if ( DiplomacyAIModule::stance(&v36->diplomacyAI, v37, 2) > v3->sn[29]
               && DiplomacyAIModule::isChangeable(&v3->md->diplomacyAI, v37) )
        {
          if ( !DiplomacyAIModule::isAlly(&v3->md->diplomacyAI, v37) )
            DiplomacyAIModule::setRelation(&v3->md->diplomacyAI, v37, 0);
        }
        else if ( !DiplomacyAIModule::isNeutral(&v3->md->diplomacyAI, v37)
               && DiplomacyAIModule::isChangeable(&v3->md->diplomacyAI, v37) )
        {
          DiplomacyAIModule::setRelation(&v3->md->diplomacyAI, v37, 1);
        }
      }
      v36 = v3->md;
      ++v37;
      v38 = v36->player;
    }
    while ( v37 < v38->world->player_num );
  }
  TribeTacticalAIModule::doSomething(v3, a2);
  v3->unitsTaskedThisUpdate.numberValue = 0;
  return 1;
}

//----- (004EF4D0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::setMainDecisionAI(TribeTacticalAIModule *this, TribeMainDecisionAIModule *m)
{
  this->md = m;
}

//----- (004EF4E0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::save(TribeTacticalAIModule *this, int outfile)
{
  int v2; // ebp@1
  TribeTacticalAIModule *v3; // esi@1
  int i; // edi@1
  int j; // edi@5
  int k; // edi@9
  int l; // edi@13
  int m; // ebx@17
  int *v9; // edi@19
  int n; // eax@20
  int ii; // ebx@25
  int *v12; // edi@27
  int jj; // eax@28
  int kk; // ebx@33
  int *v15; // edi@35
  int ll; // eax@36
  int mm; // ebx@41
  int *v18; // edi@43
  int nn; // eax@44
  int i1; // ebx@49
  int *v21; // edi@51
  int i2; // eax@52
  int i3; // ebx@57
  int *v24; // edi@59
  int i4; // eax@60
  int v26; // edi@65
  int *v27; // ebx@66
  int i5; // ebx@68
  int *v29; // edi@70
  int i6; // eax@71
  int i7; // ebx@76
  int *v32; // edi@78
  int i8; // eax@79
  int i9; // ebx@84
  int *v35; // edi@86
  int i10; // eax@87
  int i11; // ebx@92
  int v38; // ebp@94
  int *v39; // edi@94
  int i12; // eax@95
  int *v41; // edi@101
  signed int v42; // ebx@101
  int *v43; // edi@103
  signed int v44; // ebx@103
  int *v45; // edi@105
  signed int v46; // ebx@105
  int *v47; // edi@107
  signed int v48; // ebx@107
  int *v49; // edi@109
  signed int v50; // ebx@109
  int *v51; // edi@111
  signed int v52; // ebx@111
  int v53; // edi@113
  TacticalAIGroup *i13; // edi@115
  int tempInt; // [sp+10h] [bp-4h]@1

  v2 = outfile;
  v3 = this;
  tempInt = this->civilians.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i = 0; i < v3->civilians.numberValue; ++i )
  {
    if ( i > v3->civilians.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v3->civilians, i + 1);
    tempInt = v3->civilians.value[i];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->civilianExplorers.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( j = 0; j < v3->civilianExplorers.numberValue; ++j )
  {
    if ( j > v3->civilianExplorers.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v3->civilianExplorers, j + 1);
    tempInt = v3->civilianExplorers.value[j];
    rge_write(outfile, &tempInt, 4);
  }
  rge_write(outfile, &v3->numberGatherersValue, 4);
  rge_write(outfile, &v3->desiredNumberGatherersValue, 4);
  rge_write(outfile, v3->gatherers, 1200);
  tempInt = v3->soldiers.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( k = 0; k < v3->soldiers.numberValue; ++k )
  {
    if ( k > v3->soldiers.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v3->soldiers, k + 1);
    tempInt = v3->soldiers.value[k];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->ungroupedSoldiers.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( l = 0; l < v3->ungroupedSoldiers.numberValue; ++l )
  {
    if ( l > v3->ungroupedSoldiers.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v3->ungroupedSoldiers, l + 1);
    tempInt = v3->ungroupedSoldiers.value[l];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->boats.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( m = 0; m < v3->boats.numberValue; ++m )
  {
    if ( m > v3->boats.maximumSizeValue - 1 )
    {
      v9 = (int *)operator new(4 * m + 4);
      if ( v9 )
      {
        for ( n = 0; n < v3->boats.maximumSizeValue; v9[n - 1] = v3->boats.value[n - 1] )
        {
          if ( n >= m + 1 )
            break;
          ++n;
        }
        operator delete(v3->boats.value);
        v3->boats.value = v9;
        v3->boats.maximumSizeValue = m + 1;
      }
    }
    tempInt = v3->boats.value[m];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->warBoats.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( ii = 0; ii < v3->warBoats.numberValue; ++ii )
  {
    if ( ii > v3->warBoats.maximumSizeValue - 1 )
    {
      v12 = (int *)operator new(4 * ii + 4);
      if ( v12 )
      {
        for ( jj = 0; jj < v3->warBoats.maximumSizeValue; v12[jj - 1] = v3->warBoats.value[jj - 1] )
        {
          if ( jj >= ii + 1 )
            break;
          ++jj;
        }
        operator delete(v3->warBoats.value);
        v3->warBoats.value = v12;
        v3->warBoats.maximumSizeValue = ii + 1;
      }
    }
    tempInt = v3->warBoats.value[ii];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->fishingBoats.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( kk = 0; kk < v3->fishingBoats.numberValue; ++kk )
  {
    if ( kk > v3->fishingBoats.maximumSizeValue - 1 )
    {
      v15 = (int *)operator new(4 * kk + 4);
      if ( v15 )
      {
        for ( ll = 0; ll < v3->fishingBoats.maximumSizeValue; v15[ll - 1] = v3->fishingBoats.value[ll - 1] )
        {
          if ( ll >= kk + 1 )
            break;
          ++ll;
        }
        operator delete(v3->fishingBoats.value);
        v3->fishingBoats.value = v15;
        v3->fishingBoats.maximumSizeValue = kk + 1;
      }
    }
    tempInt = v3->fishingBoats.value[kk];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->tradeBoats.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( mm = 0; mm < v3->tradeBoats.numberValue; ++mm )
  {
    if ( mm > v3->tradeBoats.maximumSizeValue - 1 )
    {
      v18 = (int *)operator new(4 * mm + 4);
      if ( v18 )
      {
        for ( nn = 0; nn < v3->tradeBoats.maximumSizeValue; v18[nn - 1] = v3->tradeBoats.value[nn - 1] )
        {
          if ( nn >= mm + 1 )
            break;
          ++nn;
        }
        operator delete(v3->tradeBoats.value);
        v3->tradeBoats.value = v18;
        v3->tradeBoats.maximumSizeValue = mm + 1;
      }
    }
    tempInt = v3->tradeBoats.value[mm];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->transportBoats.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i1 = 0; i1 < v3->transportBoats.numberValue; ++i1 )
  {
    if ( i1 > v3->transportBoats.maximumSizeValue - 1 )
    {
      v21 = (int *)operator new(4 * i1 + 4);
      if ( v21 )
      {
        for ( i2 = 0; i2 < v3->transportBoats.maximumSizeValue; v21[i2 - 1] = v3->transportBoats.value[i2 - 1] )
        {
          if ( i2 >= i1 + 1 )
            break;
          ++i2;
        }
        operator delete(v3->transportBoats.value);
        v3->transportBoats.value = v21;
        v3->transportBoats.maximumSizeValue = i1 + 1;
      }
    }
    tempInt = v3->transportBoats.value[i1];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->artifacts.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i3 = 0; i3 < v3->artifacts.numberValue; ++i3 )
  {
    if ( i3 > v3->artifacts.maximumSizeValue - 1 )
    {
      v24 = (int *)operator new(4 * i3 + 4);
      if ( v24 )
      {
        for ( i4 = 0; i4 < v3->artifacts.maximumSizeValue; v24[i4 - 1] = v3->artifacts.value[i4 - 1] )
        {
          if ( i4 >= i3 + 1 )
            break;
          ++i4;
        }
        operator delete(v3->artifacts.value);
        v3->artifacts.value = v24;
        v3->artifacts.maximumSizeValue = i3 + 1;
      }
    }
    tempInt = v3->artifacts.value[i3];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = 226;
  rge_write(outfile, &tempInt, 4);
  v26 = 0;
  if ( tempInt > 0 )
  {
    v27 = v3->sn;
    do
    {
      rge_write(outfile, v27, 4);
      ++v26;
      ++v27;
    }
    while ( v26 < tempInt );
  }
  tempInt = v3->playersToAttack.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i5 = 0; i5 < v3->playersToAttack.numberValue; ++i5 )
  {
    if ( i5 > v3->playersToAttack.maximumSizeValue - 1 )
    {
      v29 = (int *)operator new(4 * i5 + 4);
      if ( v29 )
      {
        for ( i6 = 0; i6 < v3->playersToAttack.maximumSizeValue; v29[i6 - 1] = v3->playersToAttack.value[i6 - 1] )
        {
          if ( i6 >= i5 + 1 )
            break;
          ++i6;
        }
        operator delete(v3->playersToAttack.value);
        v3->playersToAttack.value = v29;
        v3->playersToAttack.maximumSizeValue = i5 + 1;
      }
    }
    tempInt = v3->playersToAttack.value[i5];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->playersToDefend.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i7 = 0; i7 < v3->playersToDefend.numberValue; ++i7 )
  {
    if ( i7 > v3->playersToDefend.maximumSizeValue - 1 )
    {
      v32 = (int *)operator new(4 * i7 + 4);
      if ( v32 )
      {
        for ( i8 = 0; i8 < v3->playersToDefend.maximumSizeValue; v32[i8 - 1] = v3->playersToDefend.value[i8 - 1] )
        {
          if ( i8 >= i7 + 1 )
            break;
          ++i8;
        }
        operator delete(v3->playersToDefend.value);
        v3->playersToDefend.value = v32;
        v3->playersToDefend.maximumSizeValue = i7 + 1;
      }
    }
    tempInt = v3->playersToDefend.value[i7];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->workingArea.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i9 = 0; i9 < v3->workingArea.numberValue; ++i9 )
  {
    if ( i9 > v3->workingArea.maximumSizeValue - 1 )
    {
      v35 = (int *)operator new(4 * i9 + 4);
      if ( v35 )
      {
        for ( i10 = 0; i10 < v3->workingArea.maximumSizeValue; v35[i10 - 1] = v3->workingArea.value[i10 - 1] )
        {
          if ( i10 >= i9 + 1 )
            break;
          ++i10;
        }
        operator delete(v3->workingArea.value);
        v3->workingArea.value = v35;
        v3->workingArea.maximumSizeValue = i9 + 1;
      }
    }
    tempInt = v3->workingArea.value[i9];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v3->unitsTaskedThisUpdate.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i11 = 0; i11 < v3->unitsTaskedThisUpdate.numberValue; ++i11 )
  {
    if ( i11 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v38 = i11 + 1;
      v39 = (int *)operator new(4 * i11 + 4);
      if ( v39 )
      {
        for ( i12 = 0;
              i12 < v3->unitsTaskedThisUpdate.maximumSizeValue;
              v39[i12 - 1] = v3->unitsTaskedThisUpdate.value[i12 - 1] )
        {
          if ( i12 >= v38 )
            break;
          ++i12;
        }
        operator delete(v3->unitsTaskedThisUpdate.value);
        v3->unitsTaskedThisUpdate.value = v39;
        v3->unitsTaskedThisUpdate.maximumSizeValue = v38;
      }
      v2 = outfile;
    }
    tempInt = v3->unitsTaskedThisUpdate.value[i11];
    rge_write(v2, &tempInt, 4);
  }
  v41 = v3->actualGathererDistribution;
  v42 = 4;
  do
  {
    rge_write(v2, v41, 4);
    ++v41;
    --v42;
  }
  while ( v42 );
  v43 = v3->desiredGathererDistribution;
  v44 = 4;
  do
  {
    rge_write(v2, v43, 4);
    ++v43;
    --v44;
  }
  while ( v44 );
  v45 = v3->neededResourceValue;
  v46 = 4;
  do
  {
    rge_write(v2, v45, 4);
    ++v45;
    --v46;
  }
  while ( v46 );
  v47 = v3->resourceDifferenceValue;
  v48 = 4;
  do
  {
    rge_write(v2, v47, 4);
    ++v47;
    --v48;
  }
  while ( v48 );
  v49 = v3->numberStoragePitsBuilt;
  v50 = 4;
  do
  {
    rge_write(v2, v49, 4);
    ++v49;
    --v50;
  }
  while ( v50 );
  v51 = v3->numberGranariesBuilt;
  v52 = 4;
  do
  {
    rge_write(v2, v51, 4);
    ++v51;
    --v52;
  }
  while ( v52 );
  v53 = 0;
  do
  {
    tempInt = ResourceItem::value(&v3->neededResources, v53);
    rge_write(v2, &tempInt, 4);
    ++v53;
  }
  while ( v53 < 4 );
  rge_write(v2, &v3->groupIDValue, 4);
  rge_write(v2, &v3->numberGroupsValue, 4);
  for ( i13 = v3->groups.next; i13 != &v3->groups; i13 = i13->next )
  {
    if ( !i13 )
      break;
    TacticalAIGroup::save(i13, v2);
  }
  rge_write(v2, &v3->lastGroupAttackTime, 4);
  rge_write(v2, &v3->lastGroupRebalanceTime, 4);
  rge_write(v2, &v3->lastAttackResponseTime, 4);
  rge_write(v2, &v3->lastBoatAttackResponseTime, 4);
  rge_write(v2, &v3->lastScalingUpdateValue, 4);
  rge_write(v2, &v3->numberBuildUpdatesSkipped, 4);
  rge_write(v2, &v3->randomizedAttackSeparationTime, 4);
  rge_write(v2, &v3->attackEnabledValue, 4);
  rge_write(v2, &v3->updateArea, 4);
  rge_write(v2, &v3->wonderInProgressValue, 4);
  rge_write(v2, &v3->wonderBuiltValue, 4);
  rge_write(v2, &v3->placementStateValue, 304);
  rge_write(v2, &v3->nextCivilianToTaskValue, 4);
  rge_write(v2, &v3->nextIdleSoldierGroupToTaskValue, 4);
  rge_write(v2, &v3->nextActiveSoldierGroupToTaskValue, 4);
  rge_write(v2, &v3->builtFirstStoragePit, 4);
  rge_write(v2, &v3->builtFirstGranary, 4);
  rge_write(v2, &v3->lastBuildTime, 4);
  rge_write(v2, &v3->lastAttackResponseBuildInsertionTime, 4);
  rge_write(v2, &v3->lastCoopTributeDemandTime, 4);
  rge_write(v2, &v3->lastCoopTributeGiftTime, 4);
  rge_write(v2, &v3->zoomingToNextAge, 4);
  rge_write(v2, &v3->lastCoopAttackDemandTime, 4);
  rge_write(v2, &v3->lastUngroupedSoldierTaskTime, 4);
  rge_write(v2, &v3->attackStateValue, 44);
  rge_write(v2, v3->hitsByPlayer, 36);
  return 1;
}

//----- (004F0190) --------------------------------------------------------
int __usercall TribeTacticalAIModule::doSomething@<eax>(TribeTacticalAIModule *this@<ecx>, double a2@<st0>)
{
  TribeTacticalAIModule *v2; // esi@1
  RGE_Game_World *v3; // edx@1
  unsigned int v4; // edi@1
  unsigned int v5; // ebp@1
  RGE_Static_Object *v6; // eax@31
  int v7; // eax@32
  BuildAIModule *v8; // ecx@34
  BuildItem *v9; // eax@36
  TribeMainDecisionAIModule *v10; // ecx@38
  float *v11; // eax@38
  BuildItem *v12; // eax@41
  BuildItem *v13; // eax@45
  char *v14; // eax@46
  RGE_Static_Object *v15; // eax@52
  RGE_Static_Object *v16; // edi@52
  RGE_Static_Object *v17; // eax@53
  int v18; // eax@55
  RGE_Static_Object *v19; // eax@63
  RGE_Static_Object *v20; // edi@65
  int v21; // eax@68
  RGE_Static_Object *v22; // eax@74
  RGE_Static_Object *v23; // edi@74
  int v24; // eax@77
  BuildItem *v25; // eax@84
  ConstructionItem *v26; // eax@88
  int v27; // edi@93
  int *v28; // ebp@93
  int v29; // eax@100
  unsigned int v30; // eax@102
  unsigned int v31; // ecx@102
  int v32; // eax@102
  signed int v33; // edx@102
  int v34; // edi@102
  unsigned int v35; // eax@107
  TribeMainDecisionAIModule *v37; // edi@108
  unsigned int v38; // edi@110
  int v39; // eax@110
  signed int v40; // ebp@110
  signed int v41; // edi@110
  TribeMainDecisionAIModule *v42; // eax@112
  int v43; // [sp+0h] [bp-138h]@0
  signed int v44; // [sp+4h] [bp-134h]@0
  char *v45; // [sp+8h] [bp-130h]@0
  int incUpdateArea; // [sp+10h] [bp-128h]@2
  unsigned int updateAreaStartTime; // [sp+14h] [bp-124h]@2
  unsigned int availableTime; // [sp+18h] [bp-120h]@1
  unsigned int startTime; // [sp+1Ch] [bp-11Ch]@1
  XYPoint point; // [sp+20h] [bp-118h]@68
  XYPoint v51; // [sp+28h] [bp-110h]@77
  XYPoint position; // [sp+30h] [bp-108h]@55
  char tempName[256]; // [sp+38h] [bp-100h]@46

  v2 = this;
  v3 = this->md->player->world;
  v4 = v3->availableComputerPlayerUpdateTime;
  availableTime = v3->availableComputerPlayerUpdateTime;
  v5 = debug_timeGetTime();
  startTime = v5;
  if ( v4 )
  {
    do
    {
      updateAreaStartTime = debug_timeGetTime();
      incUpdateArea = 1;
      switch ( v2->updateArea )
      {
        case 0:
          TribeTacticalAIModule::setupSoldierGroups(v2);
          goto LABEL_102;
        case 1:
          if ( v2->civilians.numberValue > 0 )
          {
            if ( !v2->firstNeededResourceUpdateDone )
            {
              v2->firstNeededResourceUpdateDone = 1;
              TribeTacticalAIModule::updateNeededResources(v2);
            }
            TribeTacticalAIModule::evaluateCivilianDistribution(v2);
          }
          goto LABEL_102;
        case 2:
          TribeTacticalAIModule::taskCivilians(v2, v5, v4);
          if ( v2->nextCivilianToTaskValue != -1 )
            incUpdateArea = 0;
          goto LABEL_102;
        case 3:
          if ( v2->boats.numberValue > 0 )
            TribeTacticalAIModule::setupBoatGroups(v2);
          goto LABEL_102;
        case 4:
          if ( v2->boats.numberValue > 0 )
            TribeTacticalAIModule::fillBoatGroups(v2, a2);
          goto LABEL_102;
        case 5:
          if ( v2->boats.numberValue > 0 )
            TribeTacticalAIModule::taskBoats(v2);
          goto LABEL_102;
        case 6:
          if ( v2->boats.numberValue > 0 || v2->soldiers.numberValue > 0 )
            TribeTacticalAIModule::fillSoldierGroups(v2, a2);
          goto LABEL_102;
        case 7:
          if ( v2->boats.numberValue > 0 || v2->soldiers.numberValue > 0 || v2->artifacts.numberValue > 0 )
          {
            TribeTacticalAIModule::taskIdleSoldiers(v2, v5, v4);
            if ( v2->nextIdleSoldierGroupToTaskValue != -1 )
              incUpdateArea = 0;
          }
          goto LABEL_102;
        case 8:
          if ( v2->boats.numberValue > 0 || v2->soldiers.numberValue > 0 || v2->artifacts.numberValue > 0 )
          {
            TribeTacticalAIModule::taskActiveSoldiers(v2, a2, v5, v4);
            if ( v2->nextActiveSoldierGroupToTaskValue != -1 )
              incUpdateArea = 0;
          }
          goto LABEL_102;
        case 9:
          if ( v2->soldiers.numberValue > 0 )
            TribeTacticalAIModule::playTaskSoldiers(v2, v5, v4);
          goto LABEL_102;
        case 0xA:
          v6 = MainDecisionAIModule::object(
                 (MainDecisionAIModule *)&v2->md->vfptr,
                 -1,
                 109,
                 -1,
                 -1,
                 -1,
                 -1,
                 -1,
                 -1,
                 -1,
                 -1);
          if ( v6 )
          {
            v7 = TribeInformationAIModule::withinXTilesOfObject(&v2->md->informationAI, v6, 20, 79, 199, 69, 278);
            if ( v7 != -1 )
              TribeTacticalAIModule::saveTheTown(v2, v7, v43, v44, v45);
          }
          goto LABEL_102;
        case 0xB:
          v8 = (BuildAIModule *)&v2->md->buildAI.vfptr;
          ++v2->numberBuildUpdatesSkipped;
          if ( BuildAIModule::buildListLength(v8) > 0 && v2->numberBuildUpdatesSkipped >= v2->sn[101] )
          {
            v9 = TribeBuildAIModule::nextBuildableItem(&v2->md->buildAI, 1);
            if ( v9 )
              TribeTacticalAIModule::taskResearch(v2, v9);
          }
          goto LABEL_102;
        case 0xC:
          v10 = v2->md;
          v11 = v10->player->attributes;
          a2 = v11[11];
          if ( a2 < v11[32]
            && BuildAIModule::buildListLength((BuildAIModule *)&v10->buildAI.vfptr) > 0
            && v2->numberBuildUpdatesSkipped >= v2->sn[101] )
          {
            v12 = TribeBuildAIModule::nextBuildableItem(&v2->md->buildAI, 2);
            if ( v12 )
              TribeTacticalAIModule::taskTrain(v2, v12);
          }
          goto LABEL_102;
        case 0xD:
          if ( BuildAIModule::buildListLength((BuildAIModule *)&v2->md->buildAI.vfptr) > 0
            && v2->numberBuildUpdatesSkipped >= v2->sn[101] )
          {
            v13 = TribeBuildAIModule::nextBuildableItem(&v2->md->buildAI, 3);
            if ( v13 )
            {
              v14 = BaseItem::name((BaseItem *)&v13->vfptr);
              sprintf(tempName, aS_bld, v14);
              ((void (__thiscall *)(int, char *, TRIBE_Player *))v2->md->buildAI.vfptr[1].setLogHistory)(
                (int)&v2->md->buildAI,
                tempName,
                v2->md->aiPlayer);
              TribeMainDecisionAIModule::updateBuildAIWithObjects(v2->md);
              TribeTacticalAIModule::updateNeededResources(v2);
            }
            v2->numberBuildUpdatesSkipped = 0;
          }
          goto LABEL_102;
        case 0xE:
          if ( TribeTacticalAIModule::initialExplorationSatisfied(v2)
            && (MainDecisionAIModule::numberObjectsWithAction((MainDecisionAIModule *)&v2->md->vfptr, 602) < v2->sn[4]
             || v2->wonderInProgressValue
             || v2->wonderBuiltValue) )
          {
            v15 = MainDecisionAIModule::object(
                    (MainDecisionAIModule *)&v2->md->vfptr,
                    -1,
                    -1,
                    -1,
                    -1,
                    -1,
                    -1,
                    -1,
                    -1,
                    0,
                    -1);
            v16 = v15;
            if ( v15 )
            {
              v17 = MainDecisionAIModule::object(
                      (MainDecisionAIModule *)&v2->md->vfptr,
                      -1,
                      -1,
                      -1,
                      602,
                      -1,
                      v15->id,
                      -1,
                      -1,
                      -1,
                      -1);
              if ( v2->wonderInProgressValue || !v17 )
              {
                a2 = v16->world_y;
                position.x = (signed __int64)v16->world_x;
                position.y = (signed __int64)a2;
                v18 = TribeTacticalAIModule::civilian(v2, &position, 1, 702, 718, 700, 0);
                if ( v18 != -1 && TribeTacticalAIModule::taskBuilder(v2, v18, v16) == (RGE_Static_Object *)1 )
                  v2->lastBuildTime = v2->md->player->world->world_time;
              }
            }
          }
          goto LABEL_102;
        case 0xF:
          if ( TribeTacticalAIModule::initialExplorationSatisfied(v2)
            && (MainDecisionAIModule::numberObjectsWithAction((MainDecisionAIModule *)&v2->md->vfptr, 602) < v2->sn[4]
             || v2->wonderInProgressValue
             || v2->wonderBuiltValue) )
          {
            v19 = v2->wonderBuiltValue == 1 ? MainDecisionAIModule::mostDamaged(
                                                (MainDecisionAIModule *)&v2->md->vfptr,
                                                3,
                                                276) : MainDecisionAIModule::mostDamaged(
                                                         (MainDecisionAIModule *)&v2->md->vfptr,
                                                         3,
                                                         -1);
            v20 = v19;
            if ( v19 )
            {
              if ( v19->object_state == 2
                && !MainDecisionAIModule::object(
                      (MainDecisionAIModule *)&v2->md->vfptr,
                      -1,
                      -1,
                      -1,
                      618,
                      -1,
                      v19->id,
                      -1,
                      -1,
                      -1,
                      -1) )
              {
                a2 = v20->world_y;
                point.x = (signed __int64)v20->world_x;
                point.y = (signed __int64)a2;
                v21 = TribeTacticalAIModule::civilian(v2, &point, 1, 702, 718, 700, 0);
                if ( v21 != -1 )
                  TribeTacticalAIModule::taskRepairer(v2, v21, v20);
              }
            }
          }
          goto LABEL_102;
        case 0x10:
          if ( TribeTacticalAIModule::initialExplorationSatisfied(v2)
            && (MainDecisionAIModule::numberObjectsWithAction((MainDecisionAIModule *)&v2->md->vfptr, 602) < v2->sn[4]
             || v2->wonderInProgressValue
             || v2->wonderBuiltValue) )
          {
            v22 = MainDecisionAIModule::mostDamaged((MainDecisionAIModule *)&v2->md->vfptr, 27, -1);
            v23 = v22;
            if ( v22 )
            {
              if ( v22->object_state == 2
                && !MainDecisionAIModule::object(
                      (MainDecisionAIModule *)&v2->md->vfptr,
                      -1,
                      -1,
                      -1,
                      618,
                      -1,
                      v22->id,
                      -1,
                      -1,
                      -1,
                      -1) )
              {
                a2 = v23->world_y;
                v51.x = (signed __int64)v23->world_x;
                v51.y = (signed __int64)a2;
                v24 = TribeTacticalAIModule::civilian(v2, &v51, 1, 702, 718, 700, 0);
                if ( v24 != -1 )
                  TribeTacticalAIModule::taskRepairer(v2, v24, v23);
              }
            }
          }
          goto LABEL_102;
        case 0x11:
          if ( TribeTacticalAIModule::initialExplorationSatisfied(v2)
            && (MainDecisionAIModule::numberObjectsWithAction((MainDecisionAIModule *)&v2->md->vfptr, 602) < v2->sn[4]
             || !v2->wonderInProgressValue && v2->wonderBuiltValue)
            && !v2->wonderInProgressValue )
          {
            v25 = TribeBuildAIModule::nextBuildableItem(&v2->md->buildAI, 0);
            if ( v25 )
            {
              if ( TribeTacticalAIModule::taskBuilder(v2, -1, v25, 0, v5) == 1 )
                v2->lastBuildTime = v2->md->player->world->world_time;
            }
          }
          goto LABEL_102;
        case 0x12:
          if ( v2->placementStateValue.active == 1 )
          {
            TribeConstructionAIModule::placeStructure(
              &v2->md->constructionAI,
              v2->placementStateValue.buildItem,
              v2->placementStateValue.builderID,
              &v2->placementStateValue,
              v5);
            if ( v26
              && TribeTacticalAIModule::taskBuilder(
                   v2,
                   v2->placementStateValue.builderID,
                   v2->placementStateValue.buildItem,
                   v26,
                   v5) == 1 )
            {
              v2->lastBuildTime = v2->md->player->world->world_time;
            }
            if ( v2->placementStateValue.active == 1 )
              incUpdateArea = 0;
          }
          goto LABEL_102;
        case 0x13:
          TribeTacticalAIModule::evaluateOpenTasks(v2, a2);
          v27 = 0;
          v28 = v2->resourceDifferenceValue;
          break;
        case 0x14:
          v29 = TribeInformationAIModule::closestDropsiteResID(&v2->md->informationAI, 0);
          if ( !MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v29) )
            TribeInformationAIModule::updateResourceDropsites(&v2->md->informationAI, 0);
          goto LABEL_102;
        case 0x15:
          TribeTacticalAIModule::evaluateBuildListInsertions(v2);
          v37 = v2->md;
          if ( (signed int)(v37->player->world->world_time - v2->lastBuildTime) / 60000 > 5 )
          {
            TribeBuildAIModule::unskipBuildList(&v37->buildAI, v2->builtFirstStoragePit, v2->builtFirstGranary);
            v2->lastBuildTime = v2->md->player->world->world_time;
          }
          v38 = debug_timeGetTime();
          RGE_Game_World::useComputerPlayerUpdateTime(v2->md->player->world, v38 - v5);
          v39 = v38 - updateAreaStartTime;
          v40 = v38 - updateAreaStartTime + v2->updateAreaAverageTotal;
          v41 = v2->updateAreaAverageCount + 1;
          v2->lastUpdateAreaTimeValue = v39;
          v2->updateAreaAverageTotal = v40;
          v2->updateAreaAverageCount = v41;
          if ( v41 >= 20 )
          {
            v2->updateAreaAverageTotal = 0;
            v2->updateAreaAverageCount = 0;
            v2->averageUpdateAreaTimeValue = v40 / v41;
          }
          v42 = v2->md;
          v2->updateArea = 0;
          RGE_Game_World::selectNextComputerPlayer(v42->player->world, 3);
          return 1;
        default:
          goto LABEL_102;
      }
      while ( *v28 <= 0 || *v28 + TribeResourceAIModule::resource(&v2->md->resourceAI, v27) >= 0 )
      {
        ++v27;
        ++v28;
        if ( v27 >= 4 )
          goto LABEL_99;
      }
      TribeTacticalAIModule::updateNeededResources(v2);
LABEL_99:
      TribeTacticalAIModule::checkForCoopTributeDemand(v2);
      TribeTacticalAIModule::checkForCoopTributeGift(v2);
      TribeTacticalAIModule::checkForASAPAgeResearch(v2);
      TribeTacticalAIModule::checkTradeBoats(v2);
      TribeTacticalAIModule::checkStaleAttackGroups(v2);
      v5 = startTime;
LABEL_102:
      v30 = debug_timeGetTime();
      v31 = v30;
      v32 = v30 - updateAreaStartTime;
      v33 = v32 + v2->updateAreaAverageTotal;
      v34 = v2->updateAreaAverageCount + 1;
      v2->lastUpdateAreaTimeValue = v32;
      v2->updateAreaAverageTotal = v33;
      v2->updateAreaAverageCount = v34;
      if ( v34 >= 20 )
      {
        v2->updateAreaAverageTotal = 0;
        v2->updateAreaAverageCount = 0;
        v2->averageUpdateAreaTimeValue = v33 / 20;
      }
      if ( incUpdateArea )
        ++v2->updateArea;
      v4 = availableTime;
    }
    while ( v31 - v5 < availableTime );
  }
  v35 = debug_timeGetTime();
  RGE_Game_World::useComputerPlayerUpdateTime(v2->md->player->world, v35 - v5);
  return 1;
}

//----- (004F0BC0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::clearArea(TribeTacticalAIModule *this, int id, float minX, float minY, float maxX, float maxY)
{
  TribeTacticalAIModule *v6; // ebp@1
  RGE_Static_Object *v7; // eax@2
  RGE_Static_Object *v8; // esi@2
  int (__thiscall *v9)(RGE_Static_Object *, float, float, int); // ebx@3
  signed int v10; // edi@3
  double v11; // st7@5
  int v12; // eax@6
  long double v13; // st7@14
  int result; // eax@19
  float tempX; // [sp+10h] [bp-14h]@3
  float tempY; // [sp+14h] [bp-10h]@3
  float bestDistance; // [sp+18h] [bp-Ch]@3
  float newY; // [sp+1Ch] [bp-8h]@3
  float newX; // [sp+20h] [bp-4h]@3

  v6 = this;
  if ( TribeTacticalAIModule::busyWithAction(this, id, -1) != 1 )
    goto LABEL_23;
  v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, id);
  v8 = v7;
  if ( !v7 )
    goto LABEL_23;
  newX = -1.0;
  newY = -1.0;
  bestDistance = -1.0;
  v9 = v7->vfptr->passableTile;
  tempX = -1.0;
  tempY = -1.0;
  v10 = 0;
  do
  {
    switch ( v10 )
    {
      case 0:
        v11 = minY - 2.0;
        tempX = minX - 2.0;
        goto LABEL_11;
      case 2:
        tempX = maxX - -2.0;
        v12 = ((int (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, signed int))v9)(
                v8,
                LODWORD(tempX),
                LODWORD(tempY),
                1);
        goto LABEL_13;
      case 4:
        v11 = maxY - -2.0;
        goto LABEL_11;
      case 1:
      case 5:
        tempX = (maxX + minX) * 0.5;
        v12 = ((int (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, signed int))v9)(
                v8,
                LODWORD(tempX),
                LODWORD(tempY),
                1);
        goto LABEL_13;
      case 6:
        tempX = minX - 2.0;
        v12 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v9)(v8, LODWORD(tempX), LODWORD(tempY), 1);
        goto LABEL_13;
      case 3:
      case 7:
        v11 = (maxY + minY) * 0.5;
LABEL_11:
        tempY = v11;
        break;
      default:
        break;
    }
    v12 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v9)(v8, LODWORD(tempX), LODWORD(tempY), 1);
LABEL_13:
    if ( v12 )
    {
      v13 = RGE_Static_Object::distance_to_position(v8, tempX, tempY, v8->world_z);
      if ( bestDistance == -1.0 || v13 < bestDistance )
      {
        bestDistance = v13;
        newX = tempX;
        newY = tempY;
      }
    }
    ++v10;
  }
  while ( v10 < 8 );
  if ( bestDistance != -1.0 )
  {
    TribeTacticalAIModule::moveUnit(v6, id, newX, newY, 100);
    result = 1;
  }
  else
  {
LABEL_23:
    result = 0;
  }
  return result;
}

//----- (004F0D70) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::addObject(TribeTacticalAIModule *this, RGE_Static_Object *bo)
{
  RGE_Static_Object *v2; // ebx@1
  TribeTacticalAIModule *v3; // ebp@1
  RGE_Master_Static_Object *v4; // ecx@1
  __int16 v5; // ax@1
  int v6; // ecx@2
  int v7; // edi@2
  ManagedArray<int> *v8; // esi@2
  int i; // eax@2
  int v10; // ecx@28
  int v11; // edi@28
  int **v12; // esi@28
  int k; // eax@28
  int v14; // ecx@36
  int v15; // edi@36
  ManagedArray<int> *v16; // esi@36
  int v17; // eax@36
  int v18; // edx@37
  int v19; // eax@47
  int v20; // eax@52
  int v21; // eax@57
  int j; // eax@60
  TribeTacticalAIModule *v23; // [sp+10h] [bp-4h]@1

  v2 = bo;
  v3 = this;
  v4 = bo->master_obj;
  v23 = v3;
  v5 = v4->object_group;
  if ( v5 == 4 )
  {
    v6 = v3->civilians.numberValue;
    v7 = bo->id;
    v8 = &v3->civilians;
    for ( i = 0; i < v6; ++i )
    {
      if ( i >= v3->civilians.maximumSizeValue )
        break;
      if ( v8->value[i] == v7 )
        return;
    }
    if ( v6 <= v3->civilians.maximumSizeValue - 1 )
      goto LABEL_66;
    goto LABEL_65;
  }
  if ( !v5
    || v5 == 24
    || v5 == 6
    || v5 == 25
    || v5 == 26
    || v5 == 12
    || v5 == 35
    || v5 == 23
    || v5 == 36
    || v5 == 28
    || v5 == 18
    || v5 == 13
    || v5 == 39 )
  {
    v6 = v3->soldiers.numberValue;
    v7 = bo->id;
    v8 = &v3->soldiers;
    for ( j = 0; j < v6; ++j )
    {
      if ( j >= v3->soldiers.maximumSizeValue )
        break;
      if ( v8->value[j] == v7 )
        return;
    }
    if ( v6 <= v3->soldiers.maximumSizeValue - 1 )
      goto LABEL_66;
LABEL_65:
    ManagedArray<int>::resize(v8, v6 + 1);
LABEL_66:
    v8->value[v8->numberValue++] = v7;
    return;
  }
  if ( v5 == 2 || v5 == 20 || v5 == 22 || v5 == 21 )
  {
    v10 = v3->boats.numberValue;
    v11 = bo->id;
    v12 = &v3->boats.value;
    for ( k = 0; k < v10; ++k )
    {
      if ( k >= v3->boats.maximumSizeValue )
        break;
      if ( (*v12)[k] == v11 )
        goto LABEL_35;
    }
    if ( v10 > v3->boats.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v3->boats, v10 + 1);
    (*v12)[v3->boats.numberValue++] = v11;
LABEL_35:
    if ( v2->master_obj->object_group == 2 )
    {
      v14 = v3->tradeBoats.numberValue;
      v15 = v2->id;
      v16 = &v3->tradeBoats;
      v17 = 0;
      if ( v14 > 0 )
      {
        v18 = v3->tradeBoats.maximumSizeValue;
        while ( v17 < v18 )
        {
          if ( v16->value[v17] == v15 )
          {
            v3 = v23;
            goto LABEL_45;
          }
          v3 = v23;
          if ( ++v17 >= v14 )
            break;
        }
      }
      if ( v14 > v16->maximumSizeValue - 1 )
        ManagedArray<int>::resize(v16, v14 + 1);
      v16->value[v16->numberValue++] = v15;
    }
LABEL_45:
    if ( v2->master_obj->object_group == 20 )
    {
      bo = (RGE_Static_Object *)v2->id;
      if ( ManagedArray<int>::contains(&v3->transportBoats, (const int *)&bo) != 1 )
      {
        v19 = v3->transportBoats.numberValue;
        if ( v19 > v3->transportBoats.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v3->transportBoats, v19 + 1);
        v3->transportBoats.value[v3->transportBoats.numberValue++] = (int)bo;
      }
    }
    if ( v2->master_obj->object_group == 22 )
    {
      bo = (RGE_Static_Object *)v2->id;
      if ( ManagedArray<int>::contains(&v3->warBoats, (const int *)&bo) != 1 )
      {
        v20 = v3->warBoats.numberValue;
        if ( v20 > v3->warBoats.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v3->warBoats, v20 + 1);
        v3->warBoats.value[v3->warBoats.numberValue++] = (int)bo;
      }
    }
    if ( v2->master_obj->object_group == 21 )
    {
      bo = (RGE_Static_Object *)v2->id;
      if ( ManagedArray<int>::contains(&v3->fishingBoats, (const int *)&bo) != 1 )
      {
        v21 = v3->fishingBoats.numberValue;
        if ( v21 > v3->fishingBoats.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v3->fishingBoats, v21 + 1);
        v3->fishingBoats.value[v3->fishingBoats.numberValue++] = (int)bo;
      }
    }
  }
  else if ( v4->id == 159 && RGE_Game_World::difficultyLevel(v3->md->player->world) < 4 )
  {
    ManagedArray<int>::add(&v3->artifacts, v2->id);
  }
}

//----- (004F1090) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::removeObject(TribeTacticalAIModule *this, int id)
{
  TribeTacticalAIModule *v2; // esi@1
  int v3; // ecx@1
  int v4; // edi@1
  int v5; // eax@1
  int v6; // ecx@5
  int v7; // eax@5
  int v8; // edx@10
  int v9; // eax@10
  int *v10; // ecx@11
  int v11; // eax@18
  int v12; // ecx@20
  int v13; // eax@20
  int v14; // edx@25
  int v15; // eax@25
  int *v16; // ecx@26
  int v17; // eax@33
  int v18; // ecx@35
  int v19; // eax@35
  int v20; // edx@40
  int v21; // eax@40
  int *v22; // ecx@41
  int v23; // eax@48
  ManagedArray<int> *v24; // edi@50
  int v25; // edx@59
  int v26; // eax@59
  int *v27; // ecx@60
  int v28; // eax@67

  v2 = this;
  TribeTacticalAIModule::removeFromTaskLists(this, id);
  v3 = v2->civilians.numberValue;
  v4 = id;
  v5 = 0;
  if ( v3 > 0 )
  {
    while ( v5 < v2->civilians.maximumSizeValue )
    {
      if ( v2->civilians.value[v5] == id )
      {
        v25 = v2->civilians.maximumSizeValue;
        v26 = 0;
        if ( v25 > 0 )
        {
          v27 = v2->civilians.value;
          do
          {
            if ( *v27 == id )
              break;
            ++v26;
            ++v27;
          }
          while ( v26 < v25 );
        }
        if ( v26 < v25 )
        {
          if ( v26 < v25 - 1 )
          {
            do
            {
              ++v26;
              v2->civilians.value[v26 - 1] = v2->civilians.value[v26];
            }
            while ( v26 < v2->civilians.maximumSizeValue - 1 );
            v4 = id;
          }
          v28 = v2->civilians.numberValue - 1;
          v2->civilians.numberValue = v28;
          if ( v28 < 0 )
          {
            v2->civilians.numberValue = 0;
            TribeTacticalAIModule::removeFromGroup(v2, v4);
            return;
          }
        }
        goto LABEL_58;
      }
      if ( ++v5 >= v3 )
        break;
    }
  }
  v6 = v2->soldiers.numberValue;
  v7 = 0;
  if ( v6 > 0 )
  {
    while ( v7 < v2->soldiers.maximumSizeValue )
    {
      if ( v2->soldiers.value[v7] == id )
      {
        v8 = v2->soldiers.maximumSizeValue;
        v9 = 0;
        if ( v8 > 0 )
        {
          v10 = v2->soldiers.value;
          do
          {
            if ( *v10 == id )
              break;
            ++v9;
            ++v10;
          }
          while ( v9 < v8 );
        }
        if ( v9 < v8 )
        {
          if ( v9 < v8 - 1 )
          {
            do
            {
              ++v9;
              v2->soldiers.value[v9 - 1] = v2->soldiers.value[v9];
            }
            while ( v9 < v2->soldiers.maximumSizeValue - 1 );
            v4 = id;
          }
          v11 = v2->soldiers.numberValue - 1;
          v2->soldiers.numberValue = v11;
          if ( v11 < 0 )
          {
            v2->soldiers.numberValue = 0;
            TribeTacticalAIModule::removeFromGroup(v2, v4);
            return;
          }
        }
        goto LABEL_58;
      }
      if ( ++v7 >= v6 )
        break;
    }
  }
  v12 = v2->boats.numberValue;
  v13 = 0;
  if ( v12 > 0 )
  {
    while ( v13 < v2->boats.maximumSizeValue )
    {
      if ( v2->boats.value[v13] == id )
      {
        v14 = v2->boats.maximumSizeValue;
        v15 = 0;
        if ( v14 > 0 )
        {
          v16 = v2->boats.value;
          do
          {
            if ( *v16 == id )
              break;
            ++v15;
            ++v16;
          }
          while ( v15 < v14 );
        }
        if ( v15 < v14 )
        {
          if ( v15 < v14 - 1 )
          {
            do
            {
              ++v15;
              v2->boats.value[v15 - 1] = v2->boats.value[v15];
            }
            while ( v15 < v2->boats.maximumSizeValue - 1 );
            v4 = id;
          }
          v17 = v2->boats.numberValue - 1;
          v2->boats.numberValue = v17;
          if ( v17 < 0 )
            v2->boats.numberValue = 0;
        }
        v18 = v2->warBoats.numberValue;
        v19 = 0;
        if ( v18 > 0 )
        {
          while ( v19 < v2->warBoats.maximumSizeValue )
          {
            if ( v2->warBoats.value[v19] == v4 )
            {
              v20 = v2->warBoats.maximumSizeValue;
              v21 = 0;
              if ( v20 > 0 )
              {
                v22 = v2->warBoats.value;
                do
                {
                  if ( *v22 == v4 )
                    break;
                  ++v21;
                  ++v22;
                }
                while ( v21 < v20 );
              }
              if ( v21 < v20 )
              {
                if ( v21 < v20 - 1 )
                {
                  do
                  {
                    ++v21;
                    v2->warBoats.value[v21 - 1] = v2->warBoats.value[v21];
                  }
                  while ( v21 < v2->warBoats.maximumSizeValue - 1 );
                  v4 = id;
                }
                v23 = v2->warBoats.numberValue - 1;
                v2->warBoats.numberValue = v23;
                if ( v23 < 0 )
                {
                  v2->warBoats.numberValue = 0;
                  TribeTacticalAIModule::removeFromGroup(v2, v4);
                  return;
                }
              }
              goto LABEL_58;
            }
            if ( ++v19 >= v18 )
              break;
          }
        }
        v24 = &v2->fishingBoats;
        if ( !ManagedArray<int>::contains(&v2->fishingBoats, &id) )
        {
          if ( ManagedArray<int>::contains(&v2->tradeBoats, &id) )
          {
            ManagedArray<int>::remove(&v2->tradeBoats, id);
          }
          else if ( ManagedArray<int>::contains(&v2->transportBoats, &id) )
          {
            ManagedArray<int>::remove(&v2->transportBoats, id);
          }
          goto LABEL_57;
        }
        goto LABEL_56;
      }
      if ( ++v13 >= v12 )
        break;
    }
  }
  v24 = &v2->artifacts;
  if ( ManagedArray<int>::contains(&v2->artifacts, &id) )
LABEL_56:
    ManagedArray<int>::remove(v24, id);
LABEL_57:
  v4 = id;
LABEL_58:
  TribeTacticalAIModule::removeFromGroup(v2, v4);
}

//----- (004F1390) --------------------------------------------------------
int __thiscall ManagedArray<int>::remove(ManagedArray<int> *this, int r)
{
  int v2; // esi@1
  int v3; // eax@1
  int *v4; // edx@2
  int result; // eax@6
  int v6; // eax@9

  v2 = this->maximumSizeValue;
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = this->value;
    do
    {
      if ( *v4 == r )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < v2 );
  }
  if ( v3 < v2 )
  {
    if ( v3 < v2 - 1 )
    {
      do
      {
        ++v3;
        this->value[v3 - 1] = this->value[v3];
      }
      while ( v3 < this->maximumSizeValue - 1 );
    }
    v6 = this->numberValue - 1;
    this->numberValue = v6;
    if ( v6 < 0 )
      this->numberValue = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F13F0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::evaluateCivilianDistribution(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int **v2; // edi@1
  int v3; // ebp@1
  int v4; // ebx@3
  signed int v5; // eax@3
  int v6; // eax@7
  int v7; // ecx@7
  int v8; // eax@9
  int v9; // eax@15
  int v10; // ecx@23
  int v11; // eax@23
  signed int v12; // ecx@26
  signed int v13; // eax@28
  int v14; // eax@31

  v1 = this;
  v2 = &this->playersToAttack.value;
  v3 = (signed __int64)(RGE_Visible_Map::percentExplored(this->md->player->visible) * 100.0);
  if ( v1->playersToAttack.maximumSizeValue - 1 < 0 )
    ManagedArray<int>::resize(&v1->playersToAttack, 1);
  v4 = TribeInformationAIModule::numberGameIDsOwnedBy(&v1->md->informationAI, -1, **v2);
  v5 = v1->civilians.numberValue;
  if ( v5 >= 3 )
  {
    if ( v1->civilians.maximumSizeValue - 1 < 0 )
      ManagedArray<int>::resize(&v1->civilians, 1);
    if ( TribeInformationAIModule::fullyExploredZone(&v1->md->informationAI, *v1->civilians.value) == 1 )
    {
      v1->civilianExplorers.desiredNumberValue = (signed __int64)ceil((double)v1->sn[0]
                                                                    * (double)v1->civilians.numberValue * 0.0099999998);
      v6 = TribeTacticalAIModule::numberSoldierExplorers(v1);
      v7 = v1->sn[18];
      if ( v1->civilianExplorers.desiredNumberValue + v6 > v7 )
        v1->civilianExplorers.desiredNumberValue = v7 - v6;
      v8 = v1->sn[3];
      if ( v8 != -1 && v1->civilianExplorers.desiredNumberValue > v8 )
        v1->civilianExplorers.desiredNumberValue = v8;
    }
    else
    {
      v1->civilianExplorers.desiredNumberValue = 0;
    }
    if ( v3 < v1->sn[32] || v4 <= v1->sn[145] )
    {
      if ( v3 < v1->sn[179] )
        goto LABEL_21;
      v9 = v1->civilianExplorers.desiredNumberValue / 2;
      if ( v9 <= 0 )
        v9 = 0;
    }
    else
    {
      v9 = v1->sn[35];
      if ( v1->civilianExplorers.desiredNumberValue <= v9 )
        goto LABEL_21;
    }
    v1->civilianExplorers.desiredNumberValue = v9;
LABEL_21:
    if ( v1->zoomingToNextAge == 1 )
      v1->civilianExplorers.desiredNumberValue = 0;
    v10 = v1->sn[5];
    v11 = v1->civilians.numberValue - v1->civilianExplorers.desiredNumberValue;
    v1->desiredNumberGatherersValue = v11;
    if ( v10 != -1 && v11 > v10 )
    {
      v1->desiredNumberGatherersValue = v10;
      TribeTacticalAIModule::displayCivilianDistribution(v1);
      TribeTacticalAIModule::updateGathererDistribution(v1);
      return;
    }
    goto LABEL_34;
  }
  v12 = 1;
  if ( v5 == 1 )
  {
    v1->desiredNumberGatherersValue = 0;
  }
  else
  {
    v13 = v1->sn[5];
    v1->desiredNumberGatherersValue = 1;
    if ( v13 != -1 && v13 < 1 )
      v1->desiredNumberGatherersValue = v13;
    v14 = v1->civilians.numberValue - v1->desiredNumberGatherersValue;
    v1->civilianExplorers.desiredNumberValue = v14;
    v12 = v1->sn[3];
    if ( v12 == -1 || v14 <= v12 )
      goto LABEL_34;
  }
  v1->civilianExplorers.desiredNumberValue = v12;
LABEL_34:
  TribeTacticalAIModule::displayCivilianDistribution(v1);
  TribeTacticalAIModule::updateGathererDistribution(v1);
}

//----- (004F1600) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskCivilians(TribeTacticalAIModule *this, unsigned int startTime, unsigned int availableTime)
{
  TribeTacticalAIModule *v3; // esi@1
  int result; // eax@2
  RGE_Static_Object *v5; // eax@5
  double v6; // st7@6
  int v7; // eax@6
  int v8; // ebx@8
  int *v9; // edi@10
  RGE_Static_Object *v10; // ecx@12
  int v11; // edx@15
  int v12; // ecx@15
  int v13; // eax@15
  bool v14; // zf@21
  bool v15; // sf@21
  unsigned __int8 v16; // of@21
  int v17; // ecx@23
  int **v18; // edi@23
  int i; // eax@23
  int k; // eax@30
  int *v21; // edi@33
  signed int l; // eax@34
  int v23; // eax@38
  int v24; // edi@38
  int v25; // ecx@38
  int *v26; // edx@39
  int v27; // eax@45
  RGE_Static_Object *v28; // eax@49
  double v29; // st7@50
  int v30; // eax@50
  int m; // ebp@59
  int v32; // ebx@61
  int *v33; // edi@61
  int n; // eax@62
  int v35; // ebx@69
  int *v36; // edi@71
  int ii; // eax@72
  int v38; // ecx@76
  int v39; // eax@76
  int *v40; // edi@81
  int kk; // eax@82
  int *v42; // edi@88
  int ll; // eax@89
  unsigned int v44; // ecx@94
  int *v45; // edi@96
  int mm; // eax@97
  int *v47; // edi@106
  int nn; // eax@107
  int *v49; // edi@114
  int jj; // eax@115
  int j; // [sp+10h] [bp-14h]@10
  int ja; // [sp+10h] [bp-14h]@69
  int newExplorer; // [sp+14h] [bp-10h]@8
  int newExplorera; // [sp+14h] [bp-10h]@69
  int taskedCount; // [sp+18h] [bp-Ch]@3
  XYPoint tcPosition; // [sp+1Ch] [bp-8h]@6

  v3 = this;
  if ( this->civilians.numberValue <= 0 )
  {
    this->nextCivilianToTaskValue = -1;
    return 0;
  }
  taskedCount = 0;
  if ( this->nextCivilianToTaskValue == -1 )
  {
    if ( this->civilianExplorers.numberValue < this->civilianExplorers.desiredNumberValue )
    {
      do
      {
        v5 = MainDecisionAIModule::object(
               (MainDecisionAIModule *)&v3->md->vfptr,
               -1,
               109,
               -1,
               -1,
               -1,
               -1,
               -1,
               -1,
               -1,
               -1);
        if ( v5 )
        {
          v6 = v5->world_y;
          tcPosition.x = (signed __int64)v5->world_x;
          tcPosition.y = (signed __int64)v6;
          v7 = TribeTacticalAIModule::idleCivilian(v3, -1, &tcPosition, 0);
        }
        else
        {
          v7 = TribeTacticalAIModule::idleCivilian(v3, -1);
        }
        v8 = v7;
        newExplorer = v7;
        if ( v7 == -1 )
        {
          if ( v3->desiredNumberGatherersValue >= v3->numberGatherersValue )
          {
LABEL_22:
            if ( v8 == -1 )
              break;
          }
          else
          {
            j = 3;
            v9 = &v3->neededResourceValue[3];
            while ( v8 == -1 )
            {
              v10 = MainDecisionAIModule::object(
                      (MainDecisionAIModule *)&v3->md->vfptr,
                      -1,
                      -1,
                      -1,
                      609,
                      605,
                      -1,
                      -1,
                      *v9,
                      -1,
                      0);
              if ( v10
                || (v10 = MainDecisionAIModule::object(
                            (MainDecisionAIModule *)&v3->md->vfptr,
                            -1,
                            -1,
                            -1,
                            613,
                            605,
                            -1,
                            -1,
                            *v9,
                            -1,
                            0)) != 0 )
              {
                if ( v10->attribute_amount_held == 0.0 )
                {
                  v11 = v3->civilianExplorers.numberValue;
                  v12 = v10->id;
                  v13 = 0;
                  if ( v11 > 0 )
                  {
                    while ( v13 < v3->civilianExplorers.maximumSizeValue )
                    {
                      if ( v3->civilianExplorers.value[v13] == v12 )
                      {
                        v8 = newExplorer;
                        goto LABEL_21;
                      }
                      if ( ++v13 >= v11 )
                        break;
                    }
                  }
                  v8 = v12;
                  newExplorer = v12;
                  TribeTacticalAIModule::removeGatherer(v3, v12);
                }
              }
LABEL_21:
              --v9;
              v16 = __OFSUB__(j - 1, -1);
              v14 = j == 0;
              v15 = j-- < 0;
              if ( (unsigned __int8)(v15 ^ v16) | v14 )
                goto LABEL_22;
            }
          }
        }
        v17 = v3->civilianExplorers.numberValue;
        v18 = &v3->civilianExplorers.value;
        for ( i = 0; i < v17; ++i )
        {
          if ( i >= v3->civilianExplorers.maximumSizeValue )
            break;
          if ( (*v18)[i] == v8 )
            goto LABEL_30;
        }
        if ( v17 > v3->civilianExplorers.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v3->civilianExplorers, v17 + 1);
        (*v18)[v3->civilianExplorers.numberValue++] = v8;
      }
      while ( v3->civilianExplorers.numberValue < v3->civilianExplorers.desiredNumberValue );
    }
LABEL_30:
    for ( k = v3->civilianExplorers.numberValue;
          k > v3->civilianExplorers.desiredNumberValue;
          k = v3->civilianExplorers.numberValue )
    {
      if ( k <= 0 )
        break;
      if ( v3->civilianExplorers.maximumSizeValue - 1 < 0 )
      {
        v21 = (int *)operator new(4u);
        if ( v21 )
        {
          for ( l = 0; l < v3->civilianExplorers.maximumSizeValue; v21[l - 1] = v3->civilianExplorers.value[l - 1] )
          {
            if ( l >= 1 )
              break;
            ++l;
          }
          operator delete(v3->civilianExplorers.value);
          v3->civilianExplorers.value = v21;
          v3->civilianExplorers.maximumSizeValue = 1;
        }
      }
      v23 = 0;
      v24 = *v3->civilianExplorers.value;
      v25 = v3->civilianExplorers.maximumSizeValue;
      if ( v25 > 0 )
      {
        v26 = v3->civilianExplorers.value;
        do
        {
          if ( *v26 == v24 )
            break;
          ++v23;
          ++v26;
        }
        while ( v23 < v25 );
      }
      if ( v23 < v25 )
      {
        if ( v23 < v25 - 1 )
        {
          do
          {
            ++v23;
            v3->civilianExplorers.value[v23 - 1] = v3->civilianExplorers.value[v23];
          }
          while ( v23 < v3->civilianExplorers.maximumSizeValue - 1 );
        }
        v27 = v3->civilianExplorers.numberValue - 1;
        v3->civilianExplorers.numberValue = v27;
        if ( v27 < 0 )
          v3->civilianExplorers.numberValue = 0;
      }
      TribeTacticalAIModule::stopUnit(v3, v24, 100);
    }
    if ( v3->numberGatherersValue < v3->desiredNumberGatherersValue )
    {
      do
      {
        v28 = MainDecisionAIModule::object(
                (MainDecisionAIModule *)&v3->md->vfptr,
                -1,
                109,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1);
        if ( v28 )
        {
          v29 = v28->world_y;
          tcPosition.x = (signed __int64)v28->world_x;
          tcPosition.y = (signed __int64)v29;
          v30 = TribeTacticalAIModule::idleCivilian(v3, -1, &tcPosition, 0);
        }
        else
        {
          v30 = TribeTacticalAIModule::idleCivilian(v3, -1);
        }
      }
      while ( v30 != -1
           && TribeTacticalAIModule::addGatherer(v3, v30)
           && v3->numberGatherersValue < v3->desiredNumberGatherersValue );
    }
    if ( v3->civilians.maximumSizeValue - 1 < 0 )
      ManagedArray<int>::resize(&v3->civilians, 1);
    v3->nextCivilianToTaskValue = *v3->civilians.value;
    if ( debug_timeGetTime() - startTime >= availableTime )
      return 0;
  }
  for ( m = 0; m < v3->civilians.numberValue; ++m )
  {
    if ( m > v3->civilians.maximumSizeValue - 1 )
    {
      v32 = m + 1;
      v33 = (int *)operator new(4 * m + 4);
      if ( v33 )
      {
        for ( n = 0; n < v3->civilians.maximumSizeValue; v33[n - 1] = v3->civilians.value[n - 1] )
        {
          if ( n >= v32 )
            break;
          ++n;
        }
        operator delete(v3->civilians.value);
        v3->civilians.value = v33;
        v3->civilians.maximumSizeValue = v32;
      }
    }
    if ( v3->nextCivilianToTaskValue == v3->civilians.value[m] )
      break;
  }
  if ( m >= v3->civilians.numberValue )
  {
LABEL_111:
    v3->nextCivilianToTaskValue = -1;
    return taskedCount;
  }
  v35 = m + 1;
  newExplorera = m + 1;
  ja = 4 * (m + 1);
  while ( 1 )
  {
    ++taskedCount;
    if ( m > v3->civilians.maximumSizeValue - 1 )
    {
      v36 = (int *)operator new(ja);
      if ( v36 )
      {
        for ( ii = 0; ii < v3->civilians.maximumSizeValue; v36[ii - 1] = v3->civilians.value[ii - 1] )
        {
          if ( ii >= v35 )
            break;
          ++ii;
        }
        operator delete(v3->civilians.value);
        v3->civilians.value = v36;
        v3->civilians.maximumSizeValue = v35;
      }
    }
    v38 = v3->civilianExplorers.numberValue;
    v39 = 0;
    if ( v38 > 0 )
    {
      while ( v39 < v3->civilianExplorers.maximumSizeValue )
      {
        if ( v3->civilianExplorers.value[v39] == v3->civilians.value[m] )
        {
          if ( m > v3->civilians.maximumSizeValue - 1 && (v49 = (int *)operator new(ja)) != 0 )
          {
            v35 = newExplorera;
            for ( jj = 0; jj < v3->civilians.maximumSizeValue; v49[jj - 1] = v3->civilians.value[jj - 1] )
            {
              if ( jj >= newExplorera )
                break;
              ++jj;
            }
            operator delete(v3->civilians.value);
            v3->civilians.value = v49;
            v3->civilians.maximumSizeValue = newExplorera;
          }
          else
          {
            v35 = newExplorera;
          }
          TribeTacticalAIModule::highLevelTaskExplorer(v3, v3->civilians.value[m], 1);
          goto LABEL_94;
        }
        v35 = newExplorera;
        if ( ++v39 >= v38 )
          break;
      }
    }
    if ( m > v3->civilians.maximumSizeValue - 1 )
    {
      v40 = (int *)operator new(ja);
      if ( v40 )
      {
        for ( kk = 0; kk < v3->civilians.maximumSizeValue; v40[kk - 1] = v3->civilians.value[kk - 1] )
        {
          if ( kk >= v35 )
            break;
          ++kk;
        }
        operator delete(v3->civilians.value);
        v3->civilians.value = v40;
        v3->civilians.maximumSizeValue = v35;
      }
    }
    if ( TribeTacticalAIModule::highLevelTaskGatherer(v3, v3->civilians.value[m], startTime) )
      break;
    if ( m > v3->civilians.maximumSizeValue - 1 )
    {
      v42 = (int *)operator new(ja);
      if ( v42 )
      {
        for ( ll = 0; ll < v3->civilians.maximumSizeValue; v42[ll - 1] = v3->civilians.value[ll - 1] )
        {
          if ( ll >= v35 )
            break;
          ++ll;
        }
        operator delete(v3->civilians.value);
        v3->civilians.value = v42;
        v3->civilians.maximumSizeValue = v35;
      }
    }
    TribeTacticalAIModule::addGatherer(v3, v3->civilians.value[m++]);
    newExplorera = ++v35;
    ja += 4;
LABEL_102:
    if ( m >= v3->civilians.numberValue )
      goto LABEL_111;
  }
LABEL_94:
  TribeTacticalAIModule::updateGathererDistribution(v3);
  ++m;
  ++v35;
  v44 = ja + 4;
  newExplorera = v35;
  ja += 4;
  if ( m >= v3->civilians.numberValue )
    goto LABEL_111;
  if ( m > v3->civilians.maximumSizeValue - 1 )
  {
    v45 = (int *)operator new(v44);
    if ( v45 )
    {
      for ( mm = 0; mm < v3->civilians.maximumSizeValue; v45[mm - 1] = v3->civilians.value[mm - 1] )
      {
        if ( mm >= v35 )
          break;
        ++mm;
      }
      operator delete(v3->civilians.value);
      v3->civilians.value = v45;
      v3->civilians.maximumSizeValue = v35;
    }
  }
  v3->nextCivilianToTaskValue = v3->civilians.value[m];
  if ( debug_timeGetTime() - startTime < availableTime )
    goto LABEL_102;
  if ( m <= 0 )
    return taskedCount;
  if ( m - 1 <= v3->civilians.maximumSizeValue - 1 )
    return taskedCount;
  v47 = (int *)operator new(4 * m);
  if ( !v47 )
    return taskedCount;
  for ( nn = 0; nn < v3->civilians.maximumSizeValue; v47[nn - 1] = v3->civilians.value[nn - 1] )
  {
    if ( nn >= m )
      break;
    ++nn;
  }
  operator delete(v3->civilians.value);
  result = taskedCount;
  v3->civilians.value = v47;
  v3->civilians.maximumSizeValue = m;
  return result;
}

//----- (004F1E10) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::taskIdleSoldiers(TribeTacticalAIModule *this, unsigned int startTime, unsigned int availableTime)
{
  TribeTacticalAIModule *v3; // ebx@1
  TacticalAIGroup *v4; // esi@1
  char *v5; // edi@2
  int v6; // edi@8
  int v7; // eax@15
  int v8; // edi@17
  int v9; // eax@18
  RGE_Static_Object *v10; // edi@18
  RGE_Static_Object *v11; // eax@18
  RGE_Static_Object *v12; // ebp@18
  int v13; // ebx@20
  int v14; // eax@21
  int v15; // eax@30
  int readyToTask; // [sp+10h] [bp-10h]@15
  int isGathered; // [sp+14h] [bp-Ch]@17
  TribeTacticalAIModule *t; // [sp+18h] [bp-8h]@1
  int v19; // [sp+1Ch] [bp-4h]@8

  v3 = this;
  v4 = this->groups.next;
  t = this;
  if ( this->nextIdleSoldierGroupToTaskValue != -1 )
  {
    v5 = (char *)&this->groups;
    if ( v4 != &this->groups )
    {
      do
      {
        if ( !v4 )
          break;
        if ( TacticalAIGroup::id(v4) == v3->nextIdleSoldierGroupToTaskValue )
          break;
        v4 = v4->next;
      }
      while ( (char *)v4 != v5 );
    }
    if ( TacticalAIGroup::id(v4) != v3->nextIdleSoldierGroupToTaskValue )
      v4 = v3->groups.next;
  }
  v6 = (int)&v3->groups;
  v19 = (int)&v3->groups;
  if ( v4 != &v3->groups )
  {
    while ( 1 )
    {
      if ( !v4 )
        goto LABEL_68;
      if ( TacticalAIGroup::type(v4) != 107
        && TacticalAIGroup::type(v4) != 108
        && TacticalAIGroup::type(v4) != 106
        && (!TacticalAIGroup::action(v4) || TacticalAIGroup::action(v4) == 1) )
      {
        break;
      }
      v4 = v4->next;
LABEL_67:
      if ( v4 == (TacticalAIGroup *)v6 )
        goto LABEL_68;
    }
    v7 = 1;
    readyToTask = 1;
    if ( v4->consecutiveGatherAttemptsValue <= 0xAu )
      v7 = TacticalAIGroup::isGathered(v4, v3, v3->md);
    isGathered = v7;
    v8 = TacticalAIGroup::desiredNumberUnits(v4);
    if ( v8 <= TacticalAIGroup::numberUnits(v4) )
    {
      if ( isGathered )
      {
        if ( TacticalAIGroup::allUnitsIdle(v4, v3->md, 1) )
        {
          if ( TacticalAIGroup::type(v4) != 102 && TacticalAIGroup::type(v4) != 105
            || (v15 = TacticalAIGroup::commander(v4),
                TribeInformationAIModule::fullyExploredZone(&v3->md->informationAI, v15)) )
          {
            if ( TacticalAIGroup::type(v4) == 100 || TacticalAIGroup::type(v4) == 103 )
            {
              if ( !TribeStrategyAIModule::currentVictoryCondition(&v3->md->strategyAI) )
              {
                if ( TribeTacticalAIModule::itemToCapture(v3) != -1 || TacticalAIGroup::type(v4) != 100 )
                  TacticalAIGroup::setSubType(v4, 0);
                else
                  readyToTask = 0;
              }
              if ( TribeStrategyAIModule::currentVictoryCondition(&v3->md->strategyAI) == 4 )
              {
                if ( TribeTacticalAIModule::itemToBringToArea(v3) != -1 || TacticalAIGroup::type(v4) != 100 )
                  TacticalAIGroup::setSubType(v4, 4);
                else
                  readyToTask = 0;
              }
            }
            else if ( (TacticalAIGroup::type(v4) == 101 || TacticalAIGroup::type(v4) == 104)
                   && !TribeTacticalAIModule::numberItemsToDefend(v3) )
            {
              readyToTask = 0;
            }
          }
          else
          {
            readyToTask = 0;
          }
        }
        else
        {
          readyToTask = 0;
        }
      }
      else
      {
        readyToTask = 0;
      }
    }
    else
    {
      v9 = TacticalAIGroup::commander(v4);
      v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v9);
      v11 = MainDecisionAIModule::object(
              (MainDecisionAIModule *)&v3->md->vfptr,
              -1,
              109,
              -1,
              -1,
              -1,
              -1,
              -1,
              -1,
              -1,
              -1);
      v12 = v11;
      if ( v10 && v11 )
      {
        v13 = (unsigned __int8)RGE_Static_Object::currentZone(v10);
        if ( v13 == (unsigned __int8)RGE_Static_Object::lookupZone(
                                       v10,
                                       (signed __int64)v12->world_x,
                                       (signed __int64)v12->world_y) )
        {
          v3 = t;
          readyToTask = 0;
        }
        else
        {
          v14 = TacticalAIGroup::numberUnits(v4);
          TacticalAIGroup::setDesiredNumberUnits(v4, v14);
          v3 = t;
        }
      }
      else
      {
        readyToTask = 0;
      }
    }
    if ( !readyToTask )
    {
      if ( !isGathered )
        TacticalAIGroup::task(v4, v3, v3->md, 9, 1, 0);
      goto LABEL_64;
    }
    if ( TacticalAIGroup::type(v4) != 102 && TacticalAIGroup::type(v4) != 105 )
    {
      if ( TacticalAIGroup::type(v4) != 100 && TacticalAIGroup::type(v4) != 103 )
      {
        if ( TacticalAIGroup::type(v4) == 101 || TacticalAIGroup::type(v4) == 104 )
        {
          TacticalAIGroup::setAction(v4, 4);
        }
        else if ( TacticalAIGroup::type(v4) == 109 )
        {
          TacticalAIGroup::setAction(v4, 19);
        }
        goto LABEL_64;
      }
      if ( TribeTacticalAIModule::numberItemsToAttack(v3) || TacticalAIGroup::type(v4) != 103 )
      {
        TacticalAIGroup::setAction(v4, 2);
        goto LABEL_64;
      }
      TacticalAIGroup::setType(v4, 105);
    }
    TacticalAIGroup::setAction(v4, 8);
LABEL_64:
    v4 = v4->next;
    v3->nextIdleSoldierGroupToTaskValue = TacticalAIGroup::id(v4);
    if ( debug_timeGetTime() - startTime >= availableTime )
      return;
    v6 = v19;
    goto LABEL_67;
  }
LABEL_68:
  v3->nextIdleSoldierGroupToTaskValue = -1;
}

//----- (004F21F0) --------------------------------------------------------
void __userpurge TribeTacticalAIModule::taskActiveSoldiers(TribeTacticalAIModule *this@<ecx>, double a2@<st0>, unsigned int startTime, unsigned int availableTime)
{
  TribeTacticalAIModule *v4; // edi@1
  TacticalAIGroup *v5; // esi@1
  char *v6; // ebx@2
  int v7; // ebx@8
  RGE_Static_Object *v8; // ebp@9
  ObjectMemory *v9; // ebp@18
  RGE_Static_Object *v10; // ebx@18
  MainDecisionAIModule *v11; // ebx@23
  int v12; // eax@27
  signed __int64 v13; // rax@29
  int v14; // ecx@29
  RGE_Static_Object *v15; // ebp@30
  int v16; // edx@30
  float v17; // edx@34
  float v18; // eax@34
  int v19; // eax@35
  int v20; // eax@37
  int v21; // edx@42
  int v22; // eax@42
  int v23; // edx@42
  int v24; // eax@42
  int v25; // ecx@43
  float v26; // ecx@45
  RGE_Static_Object *v27; // ecx@45
  double v28; // st7@45
  RGE_Static_Object *v29; // edx@45
  RGE_Static_Object *v30; // eax@46
  double v31; // st7@46
  float v32; // ecx@46
  RGE_Static_Object *v33; // ecx@46
  RGE_Static_Object *v34; // eax@46
  double v35; // st7@46
  float v36; // ecx@46
  RGE_Static_Object *v37; // ecx@46
  unsigned int v38; // ecx@53
  unsigned int v39; // ebp@53
  int v40; // eax@63
  int *v41; // ebp@65
  signed int m; // eax@66
  int v43; // eax@71
  signed int l; // eax@74
  int *v45; // ebp@78
  int v46; // eax@78
  int *v47; // ebp@80
  signed int k; // eax@81
  int *v49; // eax@85
  int v50; // ecx@85
  int v51; // eax@89
  int *v52; // eax@89
  int v53; // edx@91
  int v54; // eax@91
  RGE_Static_Object *v55; // edx@91
  int v56; // ecx@91
  int v57; // eax@91
  float v58; // ecx@96
  RGE_Static_Object *v59; // ecx@96
  double v60; // st7@96
  RGE_Static_Object *v61; // edx@96
  TribeMainDecisionAIModule *v62; // eax@98
  RGE_Static_Object *v63; // edx@100
  RGE_Static_Object *v64; // eax@100
  float v65; // ecx@107
  int v66; // ecx@107
  int v67; // edx@107
  int v68; // eax@107
  Path *v69; // eax@107
  char *v70; // ecx@111
  int v71; // eax@115
  RGE_Static_Object *v72; // eax@115
  TacticalAIGroup *v73; // ebx@117
  int v74; // eax@119
  int v75; // eax@119
  int v76; // eax@119
  int v77; // eax@120
  int v78; // eax@122
  RGE_Static_Object *v79; // eax@122
  int v80; // eax@126
  int v81; // ebp@126
  RGE_Static_Object *v82; // eax@126
  UnitAIModule *v83; // eax@128
  int v84; // eax@129
  int v85; // ebp@130
  int v86; // eax@135
  TacticalAIGroup *v87; // eax@135
  TacticalAIGroup *v88; // ebx@135
  int v89; // eax@136
  RGE_Static_Object *v90; // eax@136
  int v91; // eax@140
  RGE_Static_Object *v92; // eax@140
  int v93; // ebp@144
  float v94; // ebp@145
  int v95; // ebp@145
  int v96; // eax@148
  UnitAIModule *v97; // eax@149
  int v98; // eax@152
  UnitAIModule *v99; // eax@155
  UnitAIModule *v100; // eax@156
  int v101; // eax@157
  unsigned int v102; // ebp@160
  int v103; // eax@160
  int v104; // eax@162
  int v105; // ebp@163
  int v106; // ebp@164
  bool v107; // zf@164
  int v108; // ebp@164
  int v109; // eax@165
  RGE_Static_Object *v110; // eax@165
  float v111; // ecx@165
  RGE_Master_Static_Object *v112; // eax@166
  int v113; // eax@166
  int v114; // eax@170
  RGE_Static_Object *v115; // eax@170
  int v116; // eax@171
  RGE_Action_Object *v117; // eax@171
  RGE_Action_Object *v118; // ebx@171
  RGE_Static_Object *v119; // ebp@174
  int v120; // eax@175
  RGE_Static_Object *v121; // eax@175
  RGE_Static_Object *v122; // ebx@175
  int v123; // eax@179
  UnitAIModule *v124; // eax@182
  int v125; // ebp@182
  RGE_Static_ObjectVtbl *v126; // ebp@183
  Waypoint *v127; // eax@184
  int v128; // eax@184
  int v129; // eax@185
  RGE_Action_Object *v130; // ebx@189
  RGE_Static_Object *v131; // ebx@191
  int v132; // eax@191
  int v133; // eax@193
  TacticalAIGroup *v134; // eax@193
  TacticalAIGroup *v135; // ebx@193
  RGE_Static_Object *v136; // eax@194
  float v137; // ecx@195
  float v138; // edx@195
  int v139; // eax@195
  int v140; // eax@197
  RGE_Static_Object *v141; // eax@197
  RGE_Static_Object *v142; // ebx@197
  RGE_Static_ObjectVtbl *v143; // ebp@198
  TribeMainDecisionAIModule *v144; // eax@199
  char *v145; // eax@202
  char *v146; // ecx@205
  TribeMainDecisionAIModule *v147; // ebp@210
  unsigned int v148; // eax@210
  RGE_Player *v149; // ecx@210
  unsigned int v150; // ebx@210
  char *v151; // eax@212
  TribeMainDecisionAIModule *v152; // ebx@214
  int v153; // eax@219
  ObjectMemory *v154; // eax@219
  int v155; // eax@233
  RGE_Static_Object *v156; // ebp@233
  int v157; // eax@233
  int *v158; // ebx@234
  signed int i; // eax@235
  int *v160; // eax@239
  int v161; // ecx@239
  ObjectMemory *v162; // ebx@239
  RGE_Static_Object *v163; // eax@240
  MainDecisionAIModule *v164; // ecx@241
  int v165; // edx@245
  RGE_Static_ObjectVtbl *v166; // ebp@245
  float v167; // edx@245
  RGE_Static_Object *v168; // edx@246
  RGE_Static_Object *v169; // eax@246
  char *v170; // ecx@246
  float v171; // ecx@249
  RGE_Static_Object *v172; // ecx@249
  double v173; // st7@249
  RGE_Static_Object *v174; // edx@249
  char *v175; // ecx@252
  int v176; // ebp@256
  int v177; // eax@257
  int v178; // ebx@258
  int v179; // eax@259
  int v180; // eax@259
  int v181; // eax@263
  RGE_Static_Object *v182; // eax@263
  RGE_Static_Object *v183; // ebx@263
  TribeMainDecisionAIModule *v184; // ecx@268
  Waypoint *v185; // eax@270
  TribeStrategyAIModule *v186; // ecx@270
  Waypoint *v187; // eax@270
  float v188; // ecx@270
  int v189; // eax@275
  int *v190; // ebx@278
  signed int j; // eax@279
  int *v192; // edx@283
  int v193; // eax@283
  ObjectMemory *v194; // ebx@283
  int v195; // ecx@285
  int v196; // eax@285
  float v197; // edx@285
  int v198; // edx@285
  RGE_Static_ObjectVtbl *v199; // ebp@285
  RGE_Static_Object *v200; // edx@286
  RGE_Static_Object *v201; // eax@286
  char *v202; // ecx@286
  int v203; // ebx@287
  int v204; // eax@287
  int v205; // ebp@293
  int v206; // ebx@293
  int v207; // eax@297
  RGE_Static_Object *v208; // eax@297
  RGE_Static_Object *v209; // ebx@297
  int v210; // eax@306
  RGE_Static_Object *v211; // eax@306
  int v212; // eax@307
  int v213; // eax@308
  ObjectMemory *v214; // eax@308
  int v215; // ebx@314
  signed int v216; // ebx@314
  int v217; // ebx@314
  int v218; // ebp@314
  signed int v219; // ebp@314
  int v220; // eax@314
  int v221; // eax@335
  int v222; // eax@336
  RGE_Static_Object *v223; // eax@336
  int v224; // eax@339
  RGE_Static_Object *v225; // eax@339
  RGE_Static_Object *v226; // ebx@339
  RGE_Static_ObjectVtbl *v227; // ebp@341
  char *v228; // eax@344
  float v229; // [sp+3Ch] [bp-10Ch]@30
  float v230; // [sp+40h] [bp-108h]@30
  float v231; // [sp+44h] [bp-104h]@29
  unsigned __int64 v232; // [sp+48h] [bp-100h]@29
  float v233; // [sp+50h] [bp-F8h]@29
  signed int v234; // [sp+54h] [bp-F4h]@29
  char *v235; // [sp+58h] [bp-F0h]@29
  float x; // [sp+5Ch] [bp-ECh]@29
  float y; // [sp+60h] [bp-E8h]@29
  float z; // [sp+64h] [bp-E4h]@16
  int v239; // [sp+68h] [bp-E0h]@85
  TacticalAIGroup *v240; // [sp+6Ch] [bp-DCh]@85
  RGE_Static_Object *commanderObj; // [sp+78h] [bp-D0h]@25
  int allInsideTransport; // [sp+7Ch] [bp-CCh]@18
  int allOutsideTransport; // [sp+80h] [bp-C8h]@29
  RGE_Static_Object *unitObj; // [sp+84h] [bp-C4h]@107
  XYPoint stagingPoint; // [sp+88h] [bp-C0h]@160
  float v246; // [sp+90h] [bp-B8h]@42
  float v247; // [sp+94h] [bp-B4h]@42
  float v248; // [sp+98h] [bp-B0h]@42
  int targetZone; // [sp+9Ch] [bp-ACh]@93
  XYZPoint point; // [sp+A0h] [bp-A8h]@42
  float v251; // [sp+ACh] [bp-9Ch]@42
  int v252; // [sp+B0h] [bp-98h]@245
  char *v253; // [sp+B4h] [bp-94h]@91
  float v254; // [sp+B8h] [bp-90h]@29
  float v255; // [sp+BCh] [bp-8Ch]@29
  float v256; // [sp+C0h] [bp-88h]@29
  float v257; // [sp+C4h] [bp-84h]@93
  RGE_Action_Object *transportObject; // [sp+C8h] [bp-80h]@171
  float v259; // [sp+CCh] [bp-7Ch]@29
  float pathDistance; // [sp+D0h] [bp-78h]@91
  char v261; // [sp+D4h] [bp-74h]@42
  XYPoint commanderPoint; // [sp+D8h] [bp-70h]@117
  int v263; // [sp+E0h] [bp-68h]@285
  int v264; // [sp+E4h] [bp-64h]@285
  int v265; // [sp+E8h] [bp-60h]@285
  RGE_Static_Object *targetObj; // [sp+ECh] [bp-5Ch]@179
  Waypoint tAreaMin; // [sp+F0h] [bp-58h]@270
  Waypoint tAreaMax; // [sp+100h] [bp-48h]@270
  XYZPoint targetPoint; // [sp+110h] [bp-38h]@107
  float gatherY; // [sp+11Ch] [bp-2Ch]@95
  char v271; // [sp+120h] [bp-28h]@248
  XYPoint startPoint; // [sp+124h] [bp-24h]@160
  char v273; // [sp+12Ch] [bp-1Ch]@248
  char v274; // [sp+130h] [bp-18h]@32
  char v275; // [sp+134h] [bp-14h]@285
  char v276; // [sp+138h] [bp-10h]@44
  char v277; // [sp+13Ch] [bp-Ch]@32
  float gatherX; // [sp+140h] [bp-8h]@95
  char v279; // [sp+144h] [bp-4h]@44

  v4 = this;
  v5 = this->groups.next;
  if ( this->nextActiveSoldierGroupToTaskValue != -1 )
  {
    v6 = (char *)&this->groups;
    if ( v5 != &this->groups )
    {
      do
      {
        if ( *(float *)&v5 == 0.0 )
          break;
        if ( TacticalAIGroup::id(v5) == v4->nextActiveSoldierGroupToTaskValue )
          break;
        v5 = v5->next;
      }
      while ( (char *)v5 != v6 );
    }
    if ( TacticalAIGroup::id(v5) != v4->nextActiveSoldierGroupToTaskValue )
      v5 = v4->groups.next;
  }
  v7 = (int)&v4->groups;
  if ( v5 != &v4->groups )
  {
    while ( 1 )
    {
      v8 = 0;
      if ( *(float *)&v5 == 0.0 )
        goto LABEL_333;
      if ( TacticalAIGroup::type(v5) == 107
        || TacticalAIGroup::type(v5) == 108
        || TacticalAIGroup::type(v5) == 106
        || !TacticalAIGroup::action(v5)
        || TacticalAIGroup::action(v5) == 1 )
      {
        v5 = v5->next;
        goto LABEL_330;
      }
      if ( !TacticalAIGroup::allUnitsIdle(v5, v4->md, 1) )
      {
        z = *(float *)&v4->md->player->world->world_time;
        TacticalAIGroup::setConsecutiveIdleUnitCount(v5, LODWORD(z));
      }
      if ( !TacticalAIGroup::inUse(v5) )
        break;
      if ( TacticalAIGroup::action(v5) == 13 )
      {
        if ( TacticalAIGroup::waitCode(v5) != 200 )
          goto LABEL_301;
        if ( TacticalAIGroup::assistGroupID(v5) == -1 )
        {
          v71 = TacticalAIGroup::commander(v5);
          v72 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v71);
          if ( !v72 )
          {
            v4->attackStateValue.active = 0;
            goto ContinueLoop;
          }
          commanderPoint.x = (signed __int64)v72->world_x;
          a2 = v72->world_y;
          commanderPoint.y = (signed __int64)a2;
          v73 = TribeTacticalAIModule::bestGroup(v4, 106, 1, -1, &commanderPoint, -1);
          if ( !v73 )
          {
            v73 = TribeTacticalAIModule::bestGroup(v4, 106, 0, -1, &commanderPoint, -1);
            if ( !v73 )
            {
LABEL_133:
              TacticalAIGroup::setAssistGroupID(v5, -1);
              TacticalAIGroup::setAssistGroupType(v5, -1);
              v4->attackStateValue.active = 0;
              goto ContinueLoop;
            }
          }
          v74 = TacticalAIGroup::id(v73);
          TacticalAIGroup::setAssistGroupID(v5, v74);
          v75 = TacticalAIGroup::type(v73);
          TacticalAIGroup::setAssistGroupType(v5, v75);
          TacticalAIGroup::setAction(v73, 12);
          TacticalAIGroup::setInUse(v73, 1);
          v76 = TacticalAIGroup::id(v5);
          TacticalAIGroup::setAssistGroupID(v73, v76);
        }
        else
        {
          z = -6.8056469e38/*NaN*/;
          y = -6.8056469e38/*NaN*/;
          x = -6.8056469e38/*NaN*/;
          v77 = TacticalAIGroup::assistGroupID(v5);
          v73 = TribeTacticalAIModule::group(v4, v77, SLODWORD(x), SLODWORD(y), SLODWORD(z));
        }
        if ( !v73 )
          goto LABEL_133;
        v78 = TacticalAIGroup::commander(v73);
        v79 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v78);
        if ( v79 && v79->objects->number_of_objects >= v79->master_obj->obj_max )
        {
          TacticalAIGroup::setAction(v5, 15);
          v4->attackStateValue.active = 0;
        }
        else
        {
          allOutsideTransport = 0;
          allInsideTransport = 0;
          if ( TacticalAIGroup::numberUnits(v5) > 0 )
          {
            do
            {
              v80 = TacticalAIGroup::unit(v5, allInsideTransport);
              v81 = v80;
              v82 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v80);
              commanderObj = v82;
              if ( v82 )
              {
                if ( RGE_Static_Object::unitAI(v82) )
                {
                  v83 = RGE_Static_Object::unitAI(commanderObj);
                  if ( UnitAIModule::currentAction(v83) == -1 )
                  {
                    allOutsideTransport = 1;
                    v84 = TacticalAIGroup::commander(v73);
                    TribeTacticalAIModule::taskToEnter(v4, v81, v84);
                  }
                }
              }
              v85 = ++allInsideTransport;
            }
            while ( v85 < TacticalAIGroup::numberUnits(v5) );
          }
          if ( allOutsideTransport )
            goto LABEL_301;
          TacticalAIGroup::setAction(v5, 15);
          v4->attackStateValue.active = 0;
        }
      }
      else
      {
        if ( TacticalAIGroup::action(v5) == 15 )
        {
          z = -6.8056469e38/*NaN*/;
          y = -6.8056469e38/*NaN*/;
          x = -6.8056469e38/*NaN*/;
          v86 = TacticalAIGroup::assistGroupID(v5);
          v87 = TribeTacticalAIModule::group(v4, v86, SLODWORD(x), SLODWORD(y), SLODWORD(z));
          v88 = v87;
          if ( v87 )
          {
            v89 = TacticalAIGroup::commander(v87);
            v90 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v89);
            if ( v90 )
            {
              if ( v90->objects->number_of_objects >= v90->master_obj->obj_max )
              {
                z = *(float *)&v4->md;
                TacticalAIGroup::removeUnboardedUnits(v5, v4, (TribeMainDecisionAIModule *)LODWORD(z));
              }
              LOBYTE(targetZone) = -1;
              allOutsideTransport = 1;
              commanderObj = 0;
              if ( TacticalAIGroup::numberUnits(v5) > 0 )
              {
                do
                {
                  v91 = TacticalAIGroup::unit(v5, (int)v8);
                  v92 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v91);
                  allInsideTransport = (int)v92;
                  if ( v92 )
                  {
                    if ( RGE_Static_Object::unitAI(v92) )
                    {
                      v93 = TacticalAIGroup::unit(v5, (int)v8);
                      if ( v93 == TacticalAIGroup::commander(v5) )
                      {
                        LODWORD(v94) = (signed __int64)TacticalAIGroup::targetLocation(v5)->x;
                        a2 = TacticalAIGroup::targetLocation(v5)->y;
                        LODWORD(z) = (signed __int64)a2;
                        y = v94;
                        v95 = allInsideTransport;
                        LOBYTE(targetZone) = RGE_Static_Object::lookupZone(
                                               (RGE_Static_Object *)allInsideTransport,
                                               *(XYPoint *)&y);
                      }
                      else
                      {
                        v95 = allInsideTransport;
                      }
                      allInsideTransport = *(_DWORD *)(v95 + 32);
                      if ( allInsideTransport
                        && (v96 = TacticalAIGroup::commander(v88), *(_DWORD *)(allInsideTransport + 4) == v96)
                        && (v97 = RGE_Static_Object::unitAI((RGE_Static_Object *)v95),
                            UnitAIModule::currentAction(v97) != -1) )
                      {
                        TribeTacticalAIModule::stopUnit(v4, *(_DWORD *)(v95 + 4), 100);
                      }
                      else
                      {
                        allInsideTransport = *(_DWORD *)(v95 + 32);
                        if ( allInsideTransport
                          && (v98 = TacticalAIGroup::commander(v88), *(_DWORD *)(allInsideTransport + 4) != v98) )
                        {
                          TacticalAIGroup::removeUnit(v5, *(_DWORD *)(v95 + 4), v4->md);
                        }
                        else if ( !*(_DWORD *)(v95 + 32) )
                        {
                          allOutsideTransport = 0;
                          v99 = RGE_Static_Object::unitAI((RGE_Static_Object *)v95);
                          if ( UnitAIModule::currentOrder(v99) != 700 )
                          {
                            v100 = RGE_Static_Object::unitAI((RGE_Static_Object *)v95);
                            if ( UnitAIModule::currentOrder(v100) != 717 )
                            {
                              z = COERCE_FLOAT(TacticalAIGroup::commander(v88));
                              v101 = TacticalAIGroup::unit(v5, (int)commanderObj);
                              TribeTacticalAIModule::taskToEnter(v4, v101, SLODWORD(z));
                            }
                          }
                        }
                      }
                    }
                    else
                    {
                      AIModule::logCommonHistory((AIModule *)&v4->vfptr, aUnitDHasInvali);
                    }
                  }
                  else
                  {
                    AIModule::logCommonHistory((AIModule *)&v4->vfptr, aUnitDIsInvalid);
                  }
                  commanderObj = (RGE_Static_Object *)((char *)commanderObj + 1);
                  v8 = commanderObj;
                }
                while ( (signed int)v8 < TacticalAIGroup::numberUnits(v5) );
              }
              if ( allOutsideTransport )
              {
                v102 = (signed __int64)TacticalAIGroup::targetLocation(v5)->x;
                startPoint.y = (signed __int64)TacticalAIGroup::targetLocation(v5)->y;
                z = COERCE_FLOAT(TacticalAIGroup::commander(v5));
                LODWORD(y) = 15;
                v103 = TacticalAIGroup::target(v5);
                if ( !TribeInformationAIModule::findStagingPoint(
                        &v4->md->informationAI,
                        (XYPoint)__PAIR__(startPoint.y, v102),
                        &stagingPoint,
                        1,
                        1,
                        v103,
                        SLODWORD(y),
                        SLODWORD(z)) )
                {
                  stagingPoint.x = (signed __int64)TacticalAIGroup::targetLocation(v5)->x;
                  stagingPoint.y = (signed __int64)TacticalAIGroup::targetLocation(v5)->y;
                }
                z = (double)stagingPoint.y - -0.5;
                y = (double)stagingPoint.x - -0.5;
                v104 = TacticalAIGroup::commander(v88);
                TribeTacticalAIModule::taskTransporter(v4, v104, y, z);
                y = (double)stagingPoint.y;
                a2 = (double)stagingPoint.x;
                x = a2;
                TacticalAIGroup::setTargetLocation(v88, x, y, -1.0);
                TacticalAIGroup::setAction(v88, 12);
                TacticalAIGroup::setTargetType(v88, (unsigned __int8)targetZone);
                TacticalAIGroup::setAction(v5, 16);
                TacticalAIGroup::task(v5, v4, v4->md, 22, 0, 1);
                if ( TacticalAIGroup::numberUnits(v88) > 1 )
                {
                  v105 = 0;
                  for ( allInsideTransport = 0; v105 < TacticalAIGroup::numberUnits(v88); allInsideTransport = v105 )
                  {
                    v106 = TacticalAIGroup::unit(v88, v105);
                    v107 = v106 == TacticalAIGroup::commander(v88);
                    v108 = allInsideTransport;
                    if ( !v107 )
                    {
                      v109 = TacticalAIGroup::unit(v88, allInsideTransport);
                      v110 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v109);
                      if ( v110 )
                      {
                        v112 = v110->master_obj;
                        LODWORD(z) = 99;
                        y = v111;
                        a2 = v112->los * 0.5;
                        y = a2;
                        x = COERCE_FLOAT(TacticalAIGroup::commander(v88));
                        v113 = TacticalAIGroup::unit(v88, v108);
                        TribeTacticalAIModule::taskDefender(v4, v113, SLODWORD(x), y, SLODWORD(z));
                      }
                    }
                    v105 = v108 + 1;
                  }
                }
              }
              goto LABEL_321;
            }
          }
LABEL_206:
          TacticalAIGroup::setTarget(v5, -1);
          z = -6.8056469e38/*NaN*/;
          v5->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::setTargetType(v5, SLODWORD(z));
          TacticalAIGroup::setAction(v5, 1);
          TacticalAIGroup::setInUse(v5, 0);
          v4->attackStateValue.active = 0;
          goto ContinueLoop;
        }
        if ( TacticalAIGroup::action(v5) == 16 )
        {
          z = -6.8056469e38/*NaN*/;
          y = -6.8056469e38/*NaN*/;
          x = -6.8056469e38/*NaN*/;
          v114 = TacticalAIGroup::assistGroupID(v5);
          v115 = (RGE_Static_Object *)TribeTacticalAIModule::group(v4, v114, SLODWORD(x), SLODWORD(y), SLODWORD(z));
          unitObj = v115;
          if ( !v115 )
            goto LABEL_206;
          v116 = TacticalAIGroup::commander((TacticalAIGroup *)v115);
          *(float *)&v117 = COERCE_FLOAT(MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v116));
          v118 = v117;
          transportObject = v117;
          if ( *(float *)&v117 == 0.0
            || !RGE_Static_Object::unitAI((RGE_Static_Object *)&v117->vfptr)
            || v118->owner->id != v4->md->player->id )
          {
            goto LABEL_206;
          }
          v119 = 0;
          allOutsideTransport = 1;
          allInsideTransport = 1;
          commanderObj = 0;
          if ( TacticalAIGroup::numberUnits(v5) > 0 )
          {
            do
            {
              v120 = TacticalAIGroup::unit(v5, (int)v119);
              v121 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v120);
              v122 = v121;
              if ( v121 && RGE_Static_Object::unitAI(v121) )
              {
                if ( v122->inside_obj )
                {
                  allOutsideTransport = 0;
                }
                else
                {
                  allInsideTransport = 0;
                  v123 = TacticalAIGroup::target(v5);
                  targetObj = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v123);
                  if ( TacticalAIGroup::type(v5) == 100 && targetObj )
                  {
                    if ( RGE_Static_Object::unitAI(v122) )
                    {
                      v124 = RGE_Static_Object::unitAI(v122);
                      v125 = UnitAIModule::currentTarget(v124);
                      if ( v125 == TacticalAIGroup::target(v5)
                        || (v126 = v122->vfptr,
                            z = -6.8056469e38/*NaN*/,
                            y = -6.8056469e38/*NaN*/,
                            LODWORD(x) = 1,
                            v235 = 0,
                            ((void (__thiscall *)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))v126->weaponRange)(
                              v122,
                              0,
                              1,
                              -1,
                              -1),
                            z = a2,
                            y = COERCE_FLOAT(TacticalAIGroup::target(v5)),
                            (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v126->pause + 1))(
                              v122,
                              LODWORD(y),
                              LODWORD(z)) != 1) )
                      {
                        v119 = commanderObj;
                      }
                      else
                      {
                        z = 0.0;
                        y = -6.8056469e38/*NaN*/;
                        x = 0.0;
                        v235 = 0;
                        v234 = -1;
                        v233 = COERCE_FLOAT(TacticalAIGroup::target(v5));
                        HIDWORD(v232) = LODWORD(TacticalAIGroup::targetLocation(v5)->y);
                        v127 = TacticalAIGroup::targetLocation(v5);
                        v119 = commanderObj;
                        *(float *)&v232 = v127->x;
                        v128 = TacticalAIGroup::unit(v5, (int)commanderObj);
                        TribeTacticalAIModule::taskAttacker(
                          v4,
                          v128,
                          *(float *)&v232,
                          *((float *)&v232 + 1),
                          SLODWORD(v233),
                          v234,
                          (Waypoint *)v235,
                          SLODWORD(x),
                          SLODWORD(y),
                          SLODWORD(z));
                      }
                    }
                  }
                  else
                  {
                    LODWORD(z) = 100;
                    v129 = TacticalAIGroup::unit(v5, (int)v119);
                    TribeTacticalAIModule::stopUnit(v4, v129, SLODWORD(z));
                  }
                }
              }
              v119 = (RGE_Static_Object *)((char *)v119 + 1);
              commanderObj = v119;
            }
            while ( (signed int)v119 < TacticalAIGroup::numberUnits(v5) );
          }
          if ( allInsideTransport == 1 )
          {
            v130 = transportObject;
            if ( !RGE_Action_List::have_action(transportObject->actions)
              || RGE_Action_List::get_action(v130->actions)->state == 2 )
            {
              v131 = unitObj;
              z = TacticalAIGroup::targetLocation((TacticalAIGroup *)unitObj)->y - -0.5;
              a2 = TacticalAIGroup::targetLocation((TacticalAIGroup *)v131)->x - -0.5;
              y = a2;
              v132 = TacticalAIGroup::commander((TacticalAIGroup *)v131);
              TribeTacticalAIModule::taskTransporter(v4, v132, y, z);
              TacticalAIGroup::setAction((TacticalAIGroup *)v131, 12);
            }
            goto LABEL_321;
          }
          if ( !allOutsideTransport )
            goto LABEL_321;
          z = -6.8056469e38/*NaN*/;
          y = -6.8056469e38/*NaN*/;
          x = -6.8056469e38/*NaN*/;
          v133 = TacticalAIGroup::assistGroupID(v5);
          v134 = TribeTacticalAIModule::group(v4, v133, SLODWORD(x), SLODWORD(y), SLODWORD(z));
          v135 = v134;
          if ( v134 )
          {
            TacticalAIGroup::setTarget(v134, -1);
            TacticalAIGroup::setTargetType(v135, -1);
            TacticalAIGroup::setAction(v135, 1);
            TacticalAIGroup::setInUse(v135, 0);
            z = -6.8056469e38/*NaN*/;
            y = -6.8056469e38/*NaN*/;
            v136 = MainDecisionAIModule::object(
                     (MainDecisionAIModule *)&v4->md->vfptr,
                     -1,
                     109,
                     -1,
                     -1,
                     -1,
                     -1,
                     -1,
                     -1,
                     -1,
                     -1);
            if ( v136 )
            {
              v137 = v136->world_y;
              v138 = v136->world_x;
              LODWORD(z) = 50;
              y = v137;
              x = v138;
              v139 = TacticalAIGroup::commander(v135);
              TribeTacticalAIModule::moveUnit(v4, v139, x, y, SLODWORD(z));
            }
          }
          if ( TacticalAIGroup::type(v5) == 100 )
          {
            v140 = TacticalAIGroup::commander(v5);
            v141 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v140);
            v142 = v141;
            if ( !v141
              || (v143 = v141->vfptr,
                  z = -6.8056469e38/*NaN*/,
                  y = -6.8056469e38/*NaN*/,
                  LODWORD(x) = 1,
                  v235 = 0,
                  ((void (__thiscall *)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))v143->weaponRange)(
                    v141,
                    0,
                    1,
                    -1,
                    -1),
                  z = a2,
                  y = COERCE_FLOAT(TacticalAIGroup::target(v5)),
                  (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v143->pause + 1))(
                    v142,
                    LODWORD(y),
                    LODWORD(z)) != 1) )
            {
              TacticalAIGroup::setInUse(v5, 1);
              TacticalAIGroup::setAction(v5, 7);
              v145 = (char *)v4->md;
              LODWORD(z) = 1;
              y = 0.0;
              LODWORD(x) = 7;
              v235 = v145;
              goto LABEL_320;
            }
            v144 = v4->md;
            v4->lastGroupAttackTime = v144->player->world->world_time;
            if ( v4->sn[71] == 1 )
              v4->lastAttackResponseTime = v144->player->world->world_time;
            LODWORD(z) = 2;
LABEL_317:
            TacticalAIGroup::setAction(v5, SLODWORD(z));
LABEL_318:
            z = 0.0;
            LODWORD(y) = 1;
            x = COERCE_FLOAT(TacticalAIGroup::action(v5));
LABEL_319:
            v235 = (char *)v4->md;
            goto LABEL_320;
          }
          if ( TacticalAIGroup::type(v5) == 101 || TacticalAIGroup::type(v5) == 109 )
          {
            z = TacticalAIGroup::targetLocation(v5)->z;
            y = TacticalAIGroup::targetLocation(v5)->y;
            x = TacticalAIGroup::targetLocation(v5)->x;
            TacticalAIGroup::setGatherLocation(v5, x, y, z);
            TacticalAIGroup::setInUse(v5, 0);
            TacticalAIGroup::setAction(v5, 1);
            v146 = (char *)v4->md;
            LODWORD(z) = 1;
            LODWORD(y) = 1;
            LODWORD(x) = 1;
            v235 = v146;
            goto LABEL_320;
          }
        }
        if ( TacticalAIGroup::action(v5) == 12 )
          goto LABEL_321;
        if ( TacticalAIGroup::action(v5) == 19 )
        {
          if ( !TacticalAIGroup::isGathered(v5, v4, v4->md) )
          {
            v147 = v4->md;
            v148 = TacticalAIGroup::consecutiveIdleUnitCount(v5);
            v149 = v147->player;
            LODWORD(z) = 1;
            y = *(float *)&v147;
            v150 = (v149->world->world_time - v148) / 0x3E8;
            if ( TacticalAIGroup::allUnitsIdle(v5, v147, 1) == 1 && v150 > 5 )
            {
              TacticalAIGroup::setConsecutiveIdleUnitCount(v5, v4->md->player->world->world_time);
              v151 = (char *)v4->md;
              z = 0.0;
              LODWORD(y) = 1;
              LODWORD(x) = 9;
              v235 = v151;
              goto LABEL_320;
            }
          }
          goto LABEL_321;
        }
        if ( TacticalAIGroup::action(v5) != 3 )
          goto LABEL_347;
        v152 = v4->md;
        if ( (v152->player->world->world_time - TacticalAIGroup::consecutiveIdleUnitCount(v5)) / 0x3E8 > v4->sn[76] )
        {
          TacticalAIGroup::setInUse(v5, 0);
          TacticalAIGroup::setAction(v5, 1);
          TacticalAIGroup::setTarget(v5, -1);
          z = -6.8056469e38/*NaN*/;
          v5->numberObjectsToDestroyValue = 0;
          TacticalAIGroup::setTargetType(v5, SLODWORD(z));
          TacticalAIGroup::setTargetLocation(v5, -1.0, -1.0, -1.0);
          v4->attackStateValue.active = 0;
          goto ContinueLoop;
        }
        if ( TacticalAIGroup::isGathered(v5, v4, v152) )
        {
          TacticalAIGroup::setAction(v5, 1);
          TacticalAIGroup::setInUse(v5, 0);
          if ( TacticalAIGroup::type(v5) == 101 || TacticalAIGroup::type(v5) == 104 )
          {
            v153 = TacticalAIGroup::target(v5);
            v154 = TribeInformationAIModule::objectMemory(&v4->md->informationAI, v153);
            if ( v154 )
              v154->attackAttempts = 0;
          }
          if ( BuildAIModule::buildListLength((BuildAIModule *)&v4->md->buildAI.vfptr)
            || (TacticalAIGroup::type(v5) != 100 || TribeTacticalAIModule::numberGroups(v4, 100, -1) <= 1)
            && TacticalAIGroup::type(v5) == 100 )
          {
            goto LABEL_311;
          }
          if ( TacticalAIGroup::type(v5) == 102 )
          {
            --v4->sn[42];
          }
          else if ( TacticalAIGroup::type(v5) == 101 )
          {
            --v4->sn[38];
          }
          else if ( TacticalAIGroup::type(v5) == 100 )
          {
            --v4->sn[36];
          }
          TacticalAIGroup::removeUnits(v5, v4->md);
          TacticalAIGroup::setAction(v5, 0);
          v4->attackStateValue.active = 0;
        }
        else
        {
LABEL_347:
          if ( TacticalAIGroup::action(v5) == 7 )
          {
            v155 = TacticalAIGroup::commander(v5);
            v156 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v155);
            v157 = v4->playersToAttack.maximumSizeValue - 1;
            commanderObj = v156;
            if ( v157 < 0 )
            {
              v158 = (int *)operator new(4u);
              if ( v158 )
              {
                for ( i = 0; i < v4->playersToAttack.maximumSizeValue; v158[i - 1] = v4->playersToAttack.value[i - 1] )
                {
                  if ( i >= 1 )
                    break;
                  ++i;
                }
                operator delete(v4->playersToAttack.value);
                v4->playersToAttack.value = v158;
                v4->playersToAttack.maximumSizeValue = 1;
              }
            }
            v160 = v4->playersToAttack.value;
            z = *(float *)&startTime;
            v161 = *v160;
            LODWORD(y) = (char *)v4 + 4012;
            x = *(float *)&v5;
            v235 = (char *)v161;
            v162 = TribeInformationAIModule::objectToAttackByGroup(
                     &v4->md->informationAI,
                     a2,
                     v161,
                     v5,
                     &v4->attackStateValue,
                     startTime,
                     v239,
                     v240);
            if ( v4->attackStateValue.active == 1 )
            {
LABEL_332:
              v4->nextActiveSoldierGroupToTaskValue = TacticalAIGroup::id(v5);
              return;
            }
            v163 = 0;
            if ( v162 )
            {
              v164 = (MainDecisionAIModule *)&v4->md->vfptr;
              z = *(float *)&v162->id;
              v163 = MainDecisionAIModule::object(v164, SLODWORD(z));
            }
            if ( v156 && v162 && v163 )
            {
              v165 = v162->z;
              v252 = v162->y;
              v253 = (char *)v165;
              v166 = commanderObj->vfptr;
              LODWORD(v251) = v162->x;
              LODWORD(v167) = v162->owner;
              allInsideTransport = (int)v166->weaponRange;
              LODWORD(z) = 27;
              y = v167;
              ((void (__stdcall *)(int, float *, signed int, _DWORD, signed int))allInsideTransport)(
                v162->id,
                &v257,
                1,
                LODWORD(v167),
                27);
              z = a2;
              v235 = (char *)LODWORD(v256);
              x = v257;
              y = *(float *)&transportObject;
              if ( ((int (__thiscall *)(int, float, float, RGE_Action_Object *, _DWORD))v166->canPath)(
                     stagingPoint.y,
                     COERCE_FLOAT(LODWORD(v256)),
                     COERCE_FLOAT(LODWORD(v257)),
                     transportObject,
                     LODWORD(z)) == 1 )
              {
                TacticalAIGroup::setAction(v5, 2);
                TacticalAIGroup::setTarget(v5, v162->id);
                TacticalAIGroup::setTargetType(v5, v162->type);
                v168 = (RGE_Static_Object *)v162->y;
                LODWORD(z) = v162->z;
                unitObj = v168;
                v169 = (RGE_Static_Object *)v162->x;
                z = (double)SLODWORD(z);
                unitObj = v169;
                y = (double)(signed int)v168;
                a2 = (double)(signed int)v169;
                x = a2;
                TacticalAIGroup::setTargetLocation(v5, x, y, z);
                TacticalAIGroup::setInUse(v5, 1);
                v170 = (char *)v4->md;
                LODWORD(z) = 1;
                y = 0.0;
                LODWORD(x) = 2;
                v235 = v170;
                goto LABEL_320;
              }
              ((void (__thiscall *)(RGE_Static_Object *, int, float *, signed int, signed int, signed int, _DWORD, signed int))allInsideTransport)(
                commanderObj,
                v162->id,
                &v257,
                1,
                22,
                1,
                v162->owner,
                27);
              z = a2;
              v235 = (char *)transportObject;
              x = v259;
              y = pathDistance;
              if ( ((int (__thiscall *)(int, RGE_Action_Object *, float, _DWORD, _DWORD))v166->canPathWithAdditionalPassability)(
                     LODWORD(v247),
                     transportObject,
                     COERCE_FLOAT(LODWORD(v259)),
                     LODWORD(pathDistance),
                     LODWORD(z)) == 1 )
              {
                z = COERCE_FLOAT(&v271);
                y = COERCE_FLOAT(&v273);
                LODWORD(x) = 2;
                if ( v166->findFirstTerrainAlongExceptionPath(commanderObj, 2, (float *)&v273, (float *)&v271) == 1 )
                {
                  z = 0.0;
                  LODWORD(y) = 1;
                  TacticalAIGroup::task(v5, v4, v4->md, 14, 1, 0);
                  TacticalAIGroup::setAction(v5, 13);
                  TacticalAIGroup::setTarget(v5, v162->id);
                  TacticalAIGroup::setTargetType(v5, v162->type);
                  z = v171;
                  v172 = (RGE_Static_Object *)v162->y;
                  unitObj = (RGE_Static_Object *)v162->z;
                  v173 = (double)(signed int)unitObj;
                  unitObj = v172;
                  v174 = (RGE_Static_Object *)v162->x;
                  z = v173;
                  unitObj = v174;
                  y = (double)(signed int)v172;
                  a2 = (double)(signed int)v174;
LABEL_250:
                  x = a2;
                  TacticalAIGroup::setTargetLocation(v5, x, y, z);
                  TacticalAIGroup::setInUse(v5, 1);
                  TacticalAIGroup::setWaitCode(v5, 200);
                  v5->playNumberValue = -1;
                  goto LABEL_321;
                }
              }
            }
            if ( (v4->md->player->world->world_time - TacticalAIGroup::consecutiveIdleUnitCount(v5)) / 0x3E8 > 4 * v4->sn[88] )
            {
              TacticalAIGroup::setAction(v5, 7);
              v175 = (char *)v4->md;
              LODWORD(z) = 1;
              y = 0.0;
              LODWORD(x) = 7;
              v235 = v175;
              goto LABEL_320;
            }
          }
          if ( TacticalAIGroup::action(v5) == 2 && v5->playNumberValue == -1 )
          {
            if ( v4->sn[91] < 100 )
            {
              v176 = 0;
              while ( v176 < TacticalAIGroup::numberUnits(v5) )
              {
                v177 = TacticalAIGroup::unit(v5, v176);
                unitObj = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v177);
                if ( unitObj
                  && (v178 = TacticalAIGroup::unitOriginalHitPoints(v5, v176),
                      a2 = unitObj->hp,
                      (signed int)(100 * (v178 - (unsigned __int64)(signed __int64)a2))
                    / TacticalAIGroup::unitOriginalHitPoints(v5, v176) > v4->sn[91]) )
                {
                  LODWORD(z) = 100;
                  y = TacticalAIGroup::retreatLocation(v5)->y;
                  x = TacticalAIGroup::retreatLocation(v5)->x;
                  v179 = TacticalAIGroup::unit(v5, v176);
                  TribeTacticalAIModule::moveUnit(v4, v179, x, y, SLODWORD(z));
                  z = *(float *)&v4->md;
                  v180 = TacticalAIGroup::unit(v5, v176);
                  TacticalAIGroup::removeUnit(v5, v180, (TribeMainDecisionAIModule *)LODWORD(z));
                  if ( !TacticalAIGroup::numberUnits(v5) )
                    break;
                }
                else
                {
                  ++v176;
                }
              }
            }
            v181 = TacticalAIGroup::target(v5);
            v182 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v181);
            v183 = v182;
            if ( !v182 || v182->object_state > 2u )
            {
              if ( v4->sn[49] == 2 )
              {
                TacticalAIGroup::setAction(v5, 1);
                TacticalAIGroup::setTarget(v5, -1);
                z = -6.8056469e38/*NaN*/;
                v5->numberObjectsToDestroyValue = 0;
                TacticalAIGroup::setTargetType(v5, SLODWORD(z));
                TacticalAIGroup::setTargetLocation(v5, -1.0, -1.0, -1.0);
                z = 0.0;
                LODWORD(y) = 1;
                x = COERCE_FLOAT(TacticalAIGroup::action(v5));
                v235 = (char *)v4->md;
                goto LABEL_320;
              }
              v189 = TacticalAIGroup::commander(v5);
              commanderObj = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v189);
              if ( commanderObj )
              {
                if ( v4->playersToAttack.maximumSizeValue - 1 < 0 )
                {
                  v190 = (int *)operator new(4u);
                  if ( v190 )
                  {
                    for ( j = 0; j < v4->playersToAttack.maximumSizeValue; v190[j - 1] = v4->playersToAttack.value[j - 1] )
                    {
                      if ( j >= 1 )
                        break;
                      ++j;
                    }
                    operator delete(v4->playersToAttack.value);
                    v4->playersToAttack.value = v190;
                    v4->playersToAttack.maximumSizeValue = 1;
                  }
                }
                v192 = v4->playersToAttack.value;
                z = *(float *)&startTime;
                v193 = *v192;
                LODWORD(y) = (char *)v4 + 4012;
                v194 = TribeInformationAIModule::objectToAttackByGroup(
                         &v4->md->informationAI,
                         a2,
                         v193,
                         v5,
                         &v4->attackStateValue,
                         startTime,
                         v239,
                         v240);
                if ( v4->attackStateValue.active == 1 )
                  goto LABEL_332;
                if ( !v194
                  || (v195 = v194->x,
                      v264 = v194->y,
                      v196 = v194->z,
                      LODWORD(v197) = v194->owner,
                      v263 = v195,
                      v265 = v196,
                      LODWORD(z) = 27,
                      y = v197,
                      v198 = v194->id,
                      v199 = commanderObj->vfptr,
                      LODWORD(x) = 1,
                      v235 = &v275,
                      v234 = v198,
                      ((void (__stdcall *)(int, char *, signed int, _DWORD, signed int))v199->weaponRange)(
                        v198,
                        &v275,
                        1,
                        LODWORD(y),
                        27),
                      z = a2,
                      v235 = (char *)LODWORD(tAreaMin.y),
                      x = tAreaMin.z,
                      y = *(float *)&tAreaMin.facetToNextWaypoint,
                      ((int (__thiscall *)(int, _DWORD, _DWORD, _DWORD, _DWORD))v199->canPath)(
                        stagingPoint.y,
                        LODWORD(tAreaMin.y),
                        LODWORD(tAreaMin.z),
                        *(_DWORD *)&tAreaMin.facetToNextWaypoint,
                        LODWORD(z)) != 1) )
                {
                  v203 = TacticalAIGroup::targetType(v5);
                  TacticalAIGroup::setInUse(v5, 0);
                  TacticalAIGroup::setAction(v5, 1);
                  TacticalAIGroup::setTarget(v5, -1);
                  z = -6.8056469e38/*NaN*/;
                  v5->numberObjectsToDestroyValue = 0;
                  TacticalAIGroup::setTargetType(v5, SLODWORD(z));
                  TacticalAIGroup::setTargetLocation(v5, -1.0, -1.0, -1.0);
                  v204 = v4->sn[49];
                  if ( v204 )
                  {
                    if ( v204 == 3 && v203 != 126 && v203 != 89 )
                    {
                      if ( v4->sn[135] == 1 )
                      {
                        v205 = v4->sn[136];
                        v206 = (signed __int64)commanderObj->world_y;
                        a2 = commanderObj->world_x;
                        LODWORD(z) = v205 + v206;
                        LODWORD(y) = (unsigned __int64)(signed __int64)a2 + v205;
                        TribeInformationAIModule::blotExploredMap(
                          &v4->md->informationAI,
                          (unsigned __int64)(signed __int64)a2 - v205,
                          v206 - v205,
                          SLODWORD(y),
                          v205 + v206);
                      }
                      TacticalAIGroup::setInUse(v5, 1);
                      TacticalAIGroup::setAction(v5, 7);
                      LODWORD(z) = 1;
                      y = 0.0;
                      LODWORD(x) = 7;
                      goto LABEL_319;
                    }
                  }
                  else
                  {
                    TacticalAIGroup::setGatherLocation(
                      v5,
                      commanderObj->world_x,
                      commanderObj->world_y,
                      commanderObj->world_z);
                  }
                  goto LABEL_321;
                }
                TacticalAIGroup::setTarget(v5, v194->id);
                TacticalAIGroup::setTargetType(v5, v194->type);
                v200 = (RGE_Static_Object *)v194->y;
                LODWORD(z) = v194->z;
                unitObj = v200;
                v201 = (RGE_Static_Object *)v194->x;
                z = (double)SLODWORD(z);
                unitObj = v201;
                y = (double)(signed int)v200;
                a2 = (double)(signed int)v201;
                x = a2;
                TacticalAIGroup::setTargetLocation(v5, x, y, z);
                TacticalAIGroup::setInUse(v5, 1);
                v202 = (char *)v4->md;
                z = 0.0;
                y = 0.0;
                LODWORD(x) = 2;
                v235 = v202;
LABEL_320:
                TacticalAIGroup::task(v5, v4, (TribeMainDecisionAIModule *)v235, SLODWORD(x), SLODWORD(y), SLODWORD(z));
                goto LABEL_321;
              }
              v4->attackStateValue.active = 0;
              goto ContinueLoop;
            }
            if ( TacticalAIGroup::subType(v5) == -1 )
            {
              v221 = (*(int (__stdcall **)(_DWORD))&v4->md->player->vfptr->gap4[24])(v183->owner->id);
              z = 0.0;
              if ( v221 )
              {
                TacticalAIGroup::setInUse(v5, SLODWORD(z));
                TacticalAIGroup::setAction(v5, 1);
                TacticalAIGroup::setTarget(v5, -1);
                TacticalAIGroup::setTargetType(v5, -1);
                TacticalAIGroup::setTargetLocation(v5, -1.0, -1.0, -1.0);
                v5->numberObjectsToDestroyValue = 0;
                v222 = TacticalAIGroup::commander(v5);
                v223 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v222);
                if ( v223 )
                  TacticalAIGroup::setGatherLocation(v5, v223->world_x, v223->world_y, v223->world_z);
                goto LABEL_321;
              }
              if ( TacticalAIGroup::allUnitsIdle(v5, v4->md, SLODWORD(z)) == 1 )
              {
                v224 = TacticalAIGroup::commander(v5);
                v225 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v224);
                v226 = v225;
                if ( !v225 )
                {
                  v4->attackStateValue.active = 0;
                  goto ContinueLoop;
                }
                v227 = v225->vfptr;
                z = -6.8056469e38/*NaN*/;
                y = -6.8056469e38/*NaN*/;
                LODWORD(x) = 1;
                v235 = 0;
                ((void (__thiscall *)(RGE_Static_Object *, _DWORD, signed int, signed int, signed int))v227->weaponRange)(
                  v225,
                  0,
                  1,
                  -1,
                  -1);
                z = a2;
                y = COERCE_FLOAT(TacticalAIGroup::target(v5));
                if ( (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v227->pause + 1))(
                       v226,
                       LODWORD(y),
                       LODWORD(z)) == 1 )
                {
                  LODWORD(z) = 1;
                  y = 0.0;
                  LODWORD(x) = 20;
                  goto LABEL_319;
                }
                TacticalAIGroup::setGatherLocation(v5, v226->world_x, v226->world_y, v226->world_z);
                TacticalAIGroup::setInUse(v5, 0);
                TacticalAIGroup::setAction(v5, 1);
                TacticalAIGroup::setTarget(v5, -1);
                TacticalAIGroup::setTargetType(v5, -1);
                z = -1.0;
                y = -1.0;
                x = -1.0;
                v5->numberObjectsToDestroyValue = 0;
                TacticalAIGroup::setTargetLocation(v5, x, y, z);
                goto LABEL_321;
              }
              v228 = (char *)v4->md;
              LODWORD(z) = 1;
              y = 0.0;
              LODWORD(x) = 20;
              v235 = v228;
              goto LABEL_320;
            }
            if ( TacticalAIGroup::subType(v5) )
            {
              if ( TacticalAIGroup::subType(v5) == 4 )
              {
                v184 = v4->md;
                if ( v183->owner->id == v184->player->id )
                {
                  if ( TribeMainDecisionAIModule::isMoveable(v184, v183->id) )
                  {
                    TacticalAIGroup::addUnit(v5, v183->id, v4->md);
                    v185 = TribeStrategyAIModule::targetPoint1(&v4->md->strategyAI);
                    tAreaMin.x = v185->x;
                    tAreaMin.y = v185->y;
                    tAreaMin.z = v185->z;
                    v186 = &v4->md->strategyAI;
                    *(_DWORD *)&tAreaMin.facetToNextWaypoint = *(_DWORD *)&v185->facetToNextWaypoint;
                    v187 = TribeStrategyAIModule::targetPoint2(v186);
                    v188 = v187->x;
                    z = 0.0;
                    tAreaMax.x = v188;
                    tAreaMax.y = v187->y;
                    tAreaMax.z = v187->z;
                    *(_DWORD *)&tAreaMax.facetToNextWaypoint = *(_DWORD *)&v187->facetToNextWaypoint;
                    TacticalAIGroup::setInUse(v5, 0);
                    TacticalAIGroup::setAction(v5, 1);
                    TacticalAIGroup::setTarget(v5, -1);
                    z = -6.8056469e38/*NaN*/;
                    v5->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setTargetType(v5, SLODWORD(z));
                    TacticalAIGroup::setTargetLocation(v5, -1.0, -1.0, -1.0);
                    z = (tAreaMax.z + tAreaMin.z) * 0.5;
                    y = (tAreaMax.y + tAreaMin.y) * 0.5;
                    a2 = (tAreaMax.x + tAreaMin.x) * 0.5;
                    x = a2;
                    TacticalAIGroup::setGatherLocation(v5, x, y, z);
                  }
                }
              }
            }
            if ( (v4->md->player->world->world_time - TacticalAIGroup::consecutiveIdleUnitCount(v5)) / 0x3E8 > v4->sn[76] )
            {
              TacticalAIGroup::setInUse(v5, 0);
              TacticalAIGroup::setAction(v5, 1);
              TacticalAIGroup::setTarget(v5, -1);
              TacticalAIGroup::setTargetType(v5, -1);
              TacticalAIGroup::setTargetLocation(v5, -1.0, -1.0, -1.0);
              v5->numberObjectsToDestroyValue = 0;
              v4->attackStateValue.active = 0;
              goto ContinueLoop;
            }
          }
          if ( TacticalAIGroup::action(v5) != 2 || v5->playNumberValue == -1 )
          {
            if ( TacticalAIGroup::action(v5) != 4 )
              goto LABEL_312;
            if ( TacticalAIGroup::allUnitsIdle(v5, v4->md, 1) == 1 && !TacticalAIGroup::isGathered(v5, v4, v4->md) )
            {
              z = 0.0;
              LODWORD(y) = 1;
              LODWORD(x) = 9;
              goto LABEL_319;
            }
            v210 = TacticalAIGroup::target(v5);
            v211 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v210);
            if ( v211 )
            {
              LODWORD(z) = v211->master_obj->object_group;
              y = COERCE_FLOAT(TacticalAIGroup::targetType(v5));
              v212 = TacticalAIGroup::commander(v5);
              if ( !TribeInformationAIModule::higherPriorityObjectToDefend(
                      &v4->md->informationAI,
                      v212,
                      SLODWORD(y),
                      SLODWORD(z)) )
              {
LABEL_312:
                if ( TacticalAIGroup::action(v5) == 3 )
                  goto ContinueLoop;
                if ( TacticalAIGroup::action(v5) == 13 )
                  goto ContinueLoop;
                v215 = TacticalAIGroup::currentHitPoints(v5, v4->md);
                v216 = 100 * (TacticalAIGroup::originalHitPoints(v5) - v215);
                v217 = v216 / TacticalAIGroup::originalHitPoints(v5);
                v218 = TacticalAIGroup::numberUnits(v5);
                v219 = 100 * (TacticalAIGroup::originalUnitNumber(v5) - v218);
                v220 = v219 / TacticalAIGroup::originalUnitNumber(v5);
                if ( v217 <= v4->sn[30] && v220 <= v4->sn[31] )
                  goto ContinueLoop;
                LODWORD(z) = 3;
                goto LABEL_317;
              }
              v213 = TacticalAIGroup::target(v5);
              v214 = TribeInformationAIModule::objectMemory(&v4->md->informationAI, v213);
              if ( v214 )
                v214->attackAttempts = 0;
            }
            TacticalAIGroup::setAction(v5, 1);
            TacticalAIGroup::setInUse(v5, 0);
LABEL_311:
            v4->attackStateValue.active = 0;
            goto ContinueLoop;
          }
          v207 = TacticalAIGroup::commander(v5);
          v208 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v207);
          v209 = v208;
          if ( !v208 || !RGE_Static_Object::unitAI(v208) || RGE_Static_Object::unitAI(v209)->playStatus )
          {
LABEL_301:
            v4->attackStateValue.active = 0;
            goto ContinueLoop;
          }
          v5->playNumberValue = -1;
          v4->attackStateValue.active = 0;
        }
      }
ContinueLoop:
      if ( v4->attackStateValue.active )
        return;
      v5 = v5->next;
      v7 = (int)&v4->groups;
      if ( v5 == &v4->groups || *(float *)&v5 == 0.0 )
        v4->nextActiveSoldierGroupToTaskValue = -1;
      else
        v4->nextActiveSoldierGroupToTaskValue = TacticalAIGroup::id(v5);
      LODWORD(z) = 5374;
      y = COERCE_FLOAT(aCMsdevWorkA_61);
      if ( debug_timeGetTime() - startTime >= availableTime )
        return;
LABEL_330:
      if ( v5 == (TacticalAIGroup *)v7 )
        goto LABEL_333;
    }
    v9 = 0;
    v10 = 0;
    allInsideTransport = 1;
    if ( TacticalAIGroup::type(v5) != 100 && TacticalAIGroup::type(v5) != 103 )
    {
      if ( TacticalAIGroup::type(v5) == 101 || TacticalAIGroup::type(v5) == 104 )
      {
        v19 = TacticalAIGroup::commander(v5);
        v9 = TribeInformationAIModule::objectToDefend(&v4->md->informationAI, v19);
        if ( !v9 )
        {
          TacticalAIGroup::setAction(v5, 1);
          goto LABEL_321;
        }
        v20 = TacticalAIGroup::commander(v5);
        v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v20);
        if ( !v10 )
        {
          TacticalAIGroup::setAction(v5, 1);
          goto LABEL_321;
        }
        if ( v9->type == 109 )
          a2 = (double)v4->sn[22];
        else
          a2 = (double)v4->sn[57];
        *(float *)&commanderObj = a2;
        v21 = v9->y;
        LODWORD(v246) = v9->x;
        v22 = v9->z;
        z = -6.8056469e38/*NaN*/;
        v247 = *(float *)&v21;
        v23 = v9->id;
        y = -6.8056469e38/*NaN*/;
        v248 = *(float *)&v22;
        v24 = (int)v10->vfptr;
        LODWORD(x) = 1;
        v235 = &v261;
        v234 = v23;
        allOutsideTransport = v24;
        (*(void (__thiscall **)(RGE_Static_Object *, int, char *, signed int, signed int, signed int))(v24 + 268))(
          v10,
          v23,
          &v261,
          1,
          -1,
          -1);
        z = a2;
        v235 = (char *)point.y;
        x = *(float *)&point.z;
        y = v251;
        if ( !(*(int (__thiscall **)(RGE_Static_Object *, int, int, float, _DWORD))(LODWORD(v247) + 408))(
                v10,
                point.y,
                point.z,
                COERCE_FLOAT(LODWORD(v251)),
                LODWORD(z)) )
        {
          v25 = v9->id;
          z = -6.8056469e38/*NaN*/;
          y = -6.8056469e38/*NaN*/;
          LODWORD(x) = 1;
          v235 = (char *)22;
          v234 = 1;
          v233 = COERCE_FLOAT(&v261);
          v232 = __PAIR__(v25, (unsigned int)commanderObj);
          v229 = v246;
          v230 = v247;
          v231 = v248;
          if ( (*(int (__thiscall **)(RGE_Static_Object *, int, int, int, RGE_Static_Object *, int, char *, signed int, signed int, signed int, signed int, signed int))(allOutsideTransport + 420))(
                 v10,
                 LODWORD(v246),
                 LODWORD(v247),
                 LODWORD(v248),
                 commanderObj,
                 v25,
                 &v261,
                 1,
                 22,
                 1,
                 -1,
                 -1) )
          {
            z = COERCE_FLOAT(&v279);
            y = COERCE_FLOAT(&v276);
            LODWORD(x) = 2;
            if ( (*(int (__thiscall **)(RGE_Static_Object *, signed int, char *, char *))(allOutsideTransport + 424))(
                   v10,
                   2,
                   &v276,
                   &v279) == 1 )
            {
              z = 0.0;
              v9->attackAttempts = 1;
              LODWORD(y) = 1;
              TacticalAIGroup::task(v5, v4, v4->md, 14, 1, SLODWORD(z));
              TacticalAIGroup::setAction(v5, 13);
              TacticalAIGroup::setTarget(v5, v9->id);
              TacticalAIGroup::setTargetType(v5, v9->type);
              z = v26;
              v27 = (RGE_Static_Object *)v9->y;
              commanderObj = (RGE_Static_Object *)v9->z;
              v28 = (double)(signed int)commanderObj;
              commanderObj = v27;
              v29 = (RGE_Static_Object *)v9->x;
              z = v28;
              commanderObj = v29;
              y = (double)(signed int)v27;
              a2 = (double)(signed int)v29;
              x = a2;
              TacticalAIGroup::setTargetLocation(v5, x, y, z);
              TacticalAIGroup::setInUse(v5, 1);
              TacticalAIGroup::setWaitCode(v5, 200);
              goto LABEL_321;
            }
          }
          goto LABEL_90;
        }
        z = *(float *)&v9->id;
        v9->attackAttempts = 1;
        TacticalAIGroup::setTarget(v5, SLODWORD(z));
        TacticalAIGroup::setTargetType(v5, v9->type);
        v30 = (RGE_Static_Object *)v9->y;
        commanderObj = (RGE_Static_Object *)v9->z;
        v31 = (double)(signed int)commanderObj;
        commanderObj = v30;
        z = v31;
        y = v32;
        v33 = (RGE_Static_Object *)v9->x;
        y = (double)(signed int)v30;
        commanderObj = v33;
        x = (double)(signed int)v33;
        TacticalAIGroup::setTargetLocation(v5, x, y, z);
        v34 = (RGE_Static_Object *)v9->y;
        commanderObj = (RGE_Static_Object *)v9->z;
        v35 = (double)(signed int)commanderObj;
        commanderObj = v34;
        z = v35;
        y = v36;
        v37 = (RGE_Static_Object *)v9->x;
        y = (double)(signed int)v34;
        commanderObj = v37;
        a2 = (double)(signed int)v37;
        x = a2;
      }
      else
      {
        if ( TacticalAIGroup::type(v5) != 109 )
          goto LABEL_101;
        v11 = (MainDecisionAIModule *)&v4->md->vfptr;
        if ( (v11->player->world->world_time - TacticalAIGroup::consecutiveIdleUnitCount(v5)) / 0x3E8 < 0x3C )
        {
          TacticalAIGroup::setAction(v5, 1);
          goto LABEL_321;
        }
        commanderObj = MainDecisionAIModule::object(v11, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
        if ( !commanderObj )
        {
          TacticalAIGroup::setAction(v5, 1);
          goto LABEL_321;
        }
        v12 = TacticalAIGroup::commander(v5);
        v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v12);
        if ( !v10 )
        {
          TacticalAIGroup::setAction(v5, 1);
          goto LABEL_321;
        }
        LODWORD(v254) = (signed __int64)commanderObj->world_x;
        LODWORD(v255) = (signed __int64)commanderObj->world_y;
        v13 = (signed __int64)commanderObj->world_z;
        v14 = (int)v10->vfptr;
        z = -6.8056469e38/*NaN*/;
        a2 = (double)v4->sn[23];
        allOutsideTransport = v14;
        y = -6.8056469e38/*NaN*/;
        LODWORD(x) = 1;
        v235 = (char *)&v259;
        v234 = commanderObj->id;
        v256 = *(float *)&v13;
        v233 = a2;
        v231 = v254;
        v232 = __PAIR__(v13, LODWORD(v255));
        if ( !(*(int (__thiscall **)(RGE_Static_Object *, float, float, _DWORD, _DWORD, signed int, int *, signed int, signed int, signed int))(v14 + 408))(
                v10,
                COERCE_FLOAT(LODWORD(v254)),
                COERCE_FLOAT(LODWORD(v255)),
                v13,
                LODWORD(v233),
                v234,
                (int *)&v259,
                1,
                -1,
                -1) )
        {
          v15 = commanderObj;
          z = -6.8056469e38/*NaN*/;
          a2 = (double)v4->sn[23];
          v16 = commanderObj->id;
          y = -6.8056469e38/*NaN*/;
          LODWORD(x) = 1;
          v235 = (char *)22;
          v234 = 1;
          v233 = COERCE_FLOAT(&v259);
          HIDWORD(v232) = v16;
          *(float *)&v232 = a2;
          v229 = v254;
          v230 = v255;
          v231 = v256;
          if ( !(*(int (__thiscall **)(RGE_Static_Object *, float, float, float, _DWORD, int, int *, signed int, signed int, signed int, signed int, signed int))(allOutsideTransport + 420))(
                  v10,
                  COERCE_FLOAT(LODWORD(v254)),
                  COERCE_FLOAT(LODWORD(v255)),
                  COERCE_FLOAT(LODWORD(v256)),
                  v232,
                  v16,
                  (int *)&v259,
                  1,
                  22,
                  1,
                  -1,
                  -1) )
          {
            TacticalAIGroup::setConsecutiveIdleUnitCount(v5, v4->md->player->world->world_time);
            TacticalAIGroup::setAction(v5, 1);
            goto LABEL_321;
          }
          z = COERCE_FLOAT(&v274);
          y = COERCE_FLOAT(&v277);
          LODWORD(x) = 2;
          if ( (*(int (__thiscall **)(RGE_Static_Object *, signed int, char *, char *))(allOutsideTransport + 424))(
                 v10,
                 2,
                 &v277,
                 &v274) == 1 )
          {
            TacticalAIGroup::task(v5, v4, v4->md, 14, 1, 0);
            TacticalAIGroup::setAction(v5, 13);
            TacticalAIGroup::setTarget(v5, v15->id);
            TacticalAIGroup::setTargetType(v5, v15->type);
            TacticalAIGroup::setTargetLocation(v5, v15->world_x, v15->world_y, v15->world_z);
            TacticalAIGroup::setInUse(v5, 1);
            TacticalAIGroup::setWaitCode(v5, 200);
            goto LABEL_321;
          }
LABEL_90:
          TacticalAIGroup::setAction(v5, 1);
          goto LABEL_321;
        }
        TacticalAIGroup::setTarget(v5, commanderObj->id);
        TacticalAIGroup::setTargetType(v5, commanderObj->type);
        TacticalAIGroup::setTargetLocation(v5, commanderObj->world_x, commanderObj->world_y, commanderObj->world_z);
        v17 = commanderObj->world_y;
        v18 = commanderObj->world_x;
        z = commanderObj->world_z;
        y = v17;
        x = v18;
      }
      TacticalAIGroup::setGatherLocation(v5, x, y, z);
      TacticalAIGroup::setInUse(v5, 1);
      goto LABEL_101;
    }
    if ( !v4->attackEnabledValue )
    {
      v4->attackStateValue.active = 0;
      goto ContinueLoop;
    }
    if ( v4->sn[162] && TacticalAIGroup::type(v5) != 103 )
    {
      v9 = TribeInformationAIModule::objectMemory(&v4->md->informationAI, v0);
LABEL_89:
      v51 = TacticalAIGroup::commander(v5);
      v52 = (int *)MainDecisionAIModule::object((MainDecisionAIModule *)&v4->md->vfptr, v51);
      v10 = (RGE_Static_Object *)v52;
      if ( !v52 )
        goto LABEL_90;
      v53 = v9->x;
      point.y = v9->y;
      v54 = *v52;
      point.x = v53;
      v55 = *(RGE_Static_Object **)(v54 + 268);
      v56 = v9->z;
      allOutsideTransport = v54;
      v57 = v9->owner;
      point.z = v56;
      LODWORD(z) = 27;
      commanderObj = v55;
      ((void (__thiscall *)(RGE_Static_Object *, int, float *, signed int, int, signed int))v55)(
        v10,
        v9->id,
        &pathDistance,
        1,
        v57,
        27);
      z = a2;
      v235 = v253;
      x = v254;
      y = v255;
      if ( (*(int (__thiscall **)(RGE_Static_Object *, int, float, float, _DWORD))(LODWORD(v247) + 408))(
             v10,
             (int)v253,
             COERCE_FLOAT(LODWORD(v254)),
             COERCE_FLOAT(LODWORD(v255)),
             LODWORD(z)) )
      {
        v62 = v4->md;
        v4->lastGroupAttackTime = v62->player->world->world_time;
        if ( v4->sn[71] == 1 )
          v4->lastAttackResponseTime = v62->player->world->world_time;
        TacticalAIGroup::setTarget(v5, v9->id);
        TacticalAIGroup::setTargetType(v5, v9->type);
        v63 = (RGE_Static_Object *)v9->y;
        LODWORD(z) = v9->z;
        commanderObj = v63;
        v64 = (RGE_Static_Object *)v9->x;
        z = (double)SLODWORD(z);
        commanderObj = v64;
        y = (double)(signed int)v63;
        a2 = (double)(signed int)v64;
        x = a2;
        TacticalAIGroup::setTargetLocation(v5, x, y, z);
        TacticalAIGroup::setInUse(v5, 1);
        TribeTacticalAIModule::checkForCoopAttack(v4, v9->owner, v9->x, v9->y);
LABEL_101:
        if ( TribeStrategyAIModule::currentVictoryCondition(&v4->md->strategyAI) == 11
          && (TacticalAIGroup::type(v5) == 100 || TacticalAIGroup::type(v5) == 103)
          && v4->sn[103] == 1 )
        {
          if ( v9 )
          {
            if ( v10 )
            {
              TribeInformationAIModule::addEnemyInfluences(&v4->md->informationAI, v9->owner, v9->id);
              LODWORD(v65) = v9->owner;
              z = *(float *)&v9->id;
              y = v65;
              TribeInformationAIModule::addPriorAttackInfluences(&v4->md->informationAI, SLODWORD(v65), SLODWORD(z));
              v66 = v9->id;
              v67 = v9->x;
              targetPoint.y = v9->y;
              v68 = (int)v10->vfptr;
              z = *(float *)&v66;
              targetPoint.x = v67;
              targetPoint.z = 1;
              allOutsideTransport = v68;
              (*(void (__thiscall **)(RGE_Static_Object *, int))(v68 + 268))(v10, v66);
              z = a2;
              y = COERCE_FLOAT((XYZPoint *)((char *)&targetPoint + 4));
              v69 = (Path *)(*(int (__thiscall **)(RGE_Static_Object *, int *, _DWORD))&unitObj[3].curr_damage_percent)(
                              v10,
                              &targetPoint.y,
                              LODWORD(z));
              if ( v69 )
                TribeTacticalAIModule::stuffAvoidancePath(v5, v69);
            }
          }
        }
        if ( !allInsideTransport && TacticalAIGroup::action(v5) == 2 )
        {
          v70 = (char *)v4->md;
          z = 0.0;
          LODWORD(y) = 1;
          LODWORD(x) = 21;
          v235 = v70;
          goto LABEL_320;
        }
        goto LABEL_318;
      }
      if ( TacticalAIGroup::type(v5) == 103 )
        goto LABEL_97;
      ((void (__thiscall *)(RGE_Static_Object *, int, float *, signed int, signed int, signed int, _DWORD, signed int))commanderObj)(
        v10,
        v9->id,
        &pathDistance,
        1,
        22,
        1,
        v9->owner,
        27);
      z = a2;
      v235 = (char *)LODWORD(v255);
      x = v256;
      y = v257;
      if ( (*(int (__thiscall **)(RGE_Static_Object *, float, float, float, _DWORD))(targetZone + 420))(
             v10,
             COERCE_FLOAT(LODWORD(v255)),
             COERCE_FLOAT(LODWORD(v256)),
             COERCE_FLOAT(LODWORD(v257)),
             LODWORD(z)) )
      {
        z = COERCE_FLOAT(&gatherY);
        y = COERCE_FLOAT(&gatherX);
        LODWORD(x) = 2;
        if ( (*(int (__thiscall **)(RGE_Static_Object *, signed int, float *, float *))(allOutsideTransport + 424))(
               v10,
               2,
               &gatherX,
               &gatherY) == 1 )
        {
          z = 0.0;
          LODWORD(y) = 1;
          TacticalAIGroup::task(v5, v4, v4->md, 14, 1, 0);
          TacticalAIGroup::setAction(v5, 13);
          TacticalAIGroup::setTarget(v5, v9->id);
          TacticalAIGroup::setTargetType(v5, v9->type);
          z = v58;
          v59 = (RGE_Static_Object *)v9->y;
          commanderObj = (RGE_Static_Object *)v9->z;
          v60 = (double)(signed int)commanderObj;
          commanderObj = v59;
          v61 = (RGE_Static_Object *)v9->x;
          z = v60;
          commanderObj = v61;
          y = (double)(signed int)v59;
          a2 = (double)(signed int)v61;
          goto LABEL_250;
        }
LABEL_97:
        TacticalAIGroup::setAction(v5, 1);
        v5->playNumberValue = -1;
LABEL_321:
        v4->attackStateValue.active = 0;
        goto ContinueLoop;
      }
      LODWORD(z) = 1;
      v5->numberObjectsToDestroyValue = 0;
      TacticalAIGroup::setAction(v5, SLODWORD(z));
      v5->playNumberValue = -1;
      v4->attackStateValue.active = 0;
      goto ContinueLoop;
    }
    v38 = v4->lastGroupAttackTime;
    v39 = (v4->md->player->world->world_time - v38) / 0x3E8;
    if ( v38 && v4->sn[47] == 2 && v39 && v39 < TribeTacticalAIModule::attackLimiterTime(v4, 46) )
    {
      v4->attackStateValue.active = 0;
      goto ContinueLoop;
    }
    if ( v4->lastGroupAttackTime && v4->sn[47] == 1 && v39 < TribeTacticalAIModule::attackLimiterTime(v4, 46) )
    {
      v4->attackStateValue.active = 0;
      goto ContinueLoop;
    }
    if ( TribeStrategyAIModule::currentVictoryCondition(&v4->md->strategyAI) )
    {
      if ( TribeStrategyAIModule::currentVictoryCondition(&v4->md->strategyAI) != 4 )
      {
        if ( v4->playersToAttack.maximumSizeValue - 1 < 0 )
        {
          v47 = (int *)operator new(4u);
          if ( v47 )
          {
            for ( k = 0; k < v4->playersToAttack.maximumSizeValue; v47[k - 1] = v4->playersToAttack.value[k - 1] )
            {
              if ( k >= 1 )
                break;
              ++k;
            }
            operator delete(v4->playersToAttack.value);
            v4->playersToAttack.value = v47;
            v4->playersToAttack.maximumSizeValue = 1;
          }
        }
        v49 = v4->playersToAttack.value;
        z = *(float *)&startTime;
        v50 = *v49;
        LODWORD(y) = (char *)v4 + 4012;
        x = *(float *)&v5;
        v235 = (char *)v50;
        v9 = TribeInformationAIModule::objectToAttackByGroup(
               &v4->md->informationAI,
               a2,
               v50,
               v5,
               &v4->attackStateValue,
               startTime,
               v239,
               v240);
        if ( v4->attackStateValue.active == 1 )
          goto LABEL_332;
LABEL_86:
        if ( !v9 )
        {
          TacticalAIGroup::setAction(v5, 1);
          v4->attackStateValue.active = 0;
          goto ContinueLoop;
        }
        goto LABEL_88;
      }
      v43 = TribeTacticalAIModule::itemToBringToArea(v4);
      v9 = TribeInformationAIModule::objectMemory(&v4->md->informationAI, v43);
      if ( !v9 )
      {
        if ( v4->playersToAttack.maximumSizeValue - 1 >= 0 )
          goto LABEL_78;
        v41 = (int *)operator new(4u);
        if ( !v41 )
          goto LABEL_78;
        for ( l = 0; l < v4->playersToAttack.maximumSizeValue; v41[l - 1] = v4->playersToAttack.value[l - 1] )
        {
          if ( l >= 1 )
            break;
          ++l;
        }
        goto LABEL_77;
      }
    }
    else
    {
      v40 = TribeTacticalAIModule::itemToCapture(v4);
      v9 = TribeInformationAIModule::objectMemory(&v4->md->informationAI, v40);
      if ( !v9 )
      {
        if ( v4->playersToAttack.maximumSizeValue - 1 >= 0 )
          goto LABEL_78;
        v41 = (int *)operator new(4u);
        if ( !v41 )
          goto LABEL_78;
        for ( m = 0; m < v4->playersToAttack.maximumSizeValue; v41[m - 1] = v4->playersToAttack.value[m - 1] )
        {
          if ( m >= 1 )
            break;
          ++m;
        }
LABEL_77:
        operator delete(v4->playersToAttack.value);
        v4->playersToAttack.value = v41;
        v4->playersToAttack.maximumSizeValue = 1;
LABEL_78:
        v45 = v4->playersToAttack.value;
        z = COERCE_FLOAT(&allInsideTransport);
        v46 = TacticalAIGroup::commander(v5);
        v9 = TribeInformationAIModule::objectToAttack(&v4->md->informationAI, *v45, 1, 1, v46, (int *)LODWORD(z));
        goto LABEL_86;
      }
    }
LABEL_88:
    ++v9->attackAttempts;
    goto LABEL_89;
  }
LABEL_333:
  v4->nextActiveSoldierGroupToTaskValue = -1;
}

//----- (004F4760) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::playTaskSoldiers(TribeTacticalAIModule *this, unsigned int startTime, unsigned int availableTime)
{
  TribeTacticalAIModule *v3; // esi@1
  int v4; // ebx@2
  int v5; // ebp@2
  int v6; // ebx@5
  int *v7; // edi@5
  int i; // eax@6
  TacticalAIGroup *v9; // eax@10
  int v10; // ebx@13
  int *v11; // edi@13
  int j; // eax@14
  int v13; // edx@22
  int *v14; // edi@23
  signed int k; // eax@24
  RGE_Static_Object *v16; // ebx@29
  TacticalAIGroup *v17; // eax@30
  TacticalAIGroup *v18; // edi@30
  int v19; // ebp@31
  int countUnplayedSoldiers; // [sp+10h] [bp-1A4h]@2
  int *countUnplayedSoldiersa; // [sp+10h] [bp-1A4h]@32
  ObjectMemory *target; // [sp+14h] [bp-1A0h]@3
  ObjectMemory *targeta; // [sp+14h] [bp-1A0h]@28
  int numberPlayUnits; // [sp+18h] [bp-19Ch]@22
  int playCommander; // [sp+1Ch] [bp-198h]@22
  int playToRun; // [sp+20h] [bp-194h]@22
  int unplayedSoldiers[50]; // [sp+24h] [bp-190h]@3
  int playUnits[50]; // [sp+ECh] [bp-C8h]@28

  v3 = this;
  if ( this->sn[162] )
  {
    v4 = 0;
    v5 = 0;
    countUnplayedSoldiers = 0;
    if ( this->soldiers.numberValue > 0 )
    {
      target = (ObjectMemory *)unplayedSoldiers;
      do
      {
        if ( v5 > v3->soldiers.maximumSizeValue - 1 )
        {
          v6 = v5 + 1;
          v7 = (int *)operator new(4 * v5 + 4);
          if ( v7 )
          {
            for ( i = 0; i < v3->soldiers.maximumSizeValue; v7[i - 1] = v3->soldiers.value[i - 1] )
            {
              if ( i >= v6 )
                break;
              ++i;
            }
            operator delete(v3->soldiers.value);
            v3->soldiers.value = v7;
            v3->soldiers.maximumSizeValue = v6;
          }
        }
        v9 = TribeTacticalAIModule::groupUnitIsIn(v3, v3->soldiers.value[v5]);
        if ( !v9 || TacticalAIGroup::type(v9) != 100 )
        {
          if ( v5 > v3->soldiers.maximumSizeValue - 1 )
          {
            v10 = v5 + 1;
            v11 = (int *)operator new(4 * v5 + 4);
            if ( v11 )
            {
              for ( j = 0; j < v3->soldiers.maximumSizeValue; v11[j - 1] = v3->soldiers.value[j - 1] )
              {
                if ( j >= v10 )
                  break;
                ++j;
              }
              operator delete(v3->soldiers.value);
              v3->soldiers.value = v11;
              v3->soldiers.maximumSizeValue = v10;
            }
          }
          ++countUnplayedSoldiers;
          target->id = v3->soldiers.value[v5];
          target = (ObjectMemory *)((char *)target + 4);
        }
        ++v5;
      }
      while ( v5 < v3->soldiers.numberValue );
      v4 = countUnplayedSoldiers;
    }
    if ( v4 )
    {
      v13 = v3->playersToAttack.maximumSizeValue - 1;
      playToRun = -1;
      numberPlayUnits = 0;
      playCommander = -1;
      if ( v13 < 0 )
      {
        v14 = (int *)operator new(4u);
        if ( v14 )
        {
          for ( k = 0; k < v3->playersToAttack.maximumSizeValue; v14[k - 1] = v3->playersToAttack.value[k - 1] )
          {
            if ( k >= 1 )
              break;
            ++k;
          }
          operator delete(v3->playersToAttack.value);
          v3->playersToAttack.value = v14;
          v3->playersToAttack.maximumSizeValue = 1;
        }
      }
      targeta = TribeInformationAIModule::objectToAttackWithPlay(
                  &v3->md->informationAI,
                  *v3->playersToAttack.value,
                  unplayedSoldiers,
                  v4,
                  &playToRun,
                  playUnits,
                  &numberPlayUnits,
                  &playCommander);
      if ( targeta )
      {
        v16 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, playCommander);
        if ( v16 )
        {
          v17 = TribeTacticalAIModule::createGroup(v3, 1);
          v18 = v17;
          if ( v17 )
          {
            TacticalAIGroup::setType(v17, 100);
            TacticalAIGroup::setDesiredNumberUnits(v18, numberPlayUnits);
            v19 = 0;
            if ( numberPlayUnits > 0 )
            {
              countUnplayedSoldiersa = playUnits;
              do
              {
                TacticalAIGroup::addUnit(v18, *countUnplayedSoldiersa, v3->md);
                ++v19;
                ++countUnplayedSoldiersa;
              }
              while ( v19 < numberPlayUnits );
            }
            TacticalAIGroup::setSpecificCommander(v18, playCommander, v3->md);
            TacticalAIGroup::setLocation(v18, v16->world_x, v16->world_y, v16->world_z);
            TacticalAIGroup::setGatherLocation(v18, v16->world_x, v16->world_y, v16->world_z);
            TacticalAIGroup::setRetreatLocation(v18, v16->world_x, v16->world_y, v16->world_z);
            TacticalAIGroup::setTarget(v18, targeta->id);
            v18->playNumberValue = playToRun;
            TacticalAIGroup::setAction(v18, 2);
            TacticalAIGroup::setInUse(v18, 1);
            TacticalAIGroup::task(v18, v3, v3->md, 2, 1, 1);
          }
        }
      }
    }
  }
}

//----- (004F4AA0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::taskUngroupedSoldiers(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // ebp@1
  TribeMainDecisionAIModule *v2; // ecx@1
  RGE_Static_Object *v3; // eax@2
  int v4; // ebx@3
  void **v5; // esi@4
  int v6; // ecx@10
  int v7; // eax@10
  int *v8; // edx@11
  int v9; // eax@17
  int **v10; // edi@24
  int v11; // eax@24
  _DWORD *v12; // ebx@29
  int j; // eax@30
  int v14; // eax@35
  int v15; // edx@35
  int v16; // ecx@35
  float y; // ST1C_4@46
  float x; // ST18_4@46
  int i; // [sp+1Ch] [bp-1Ch]@3
  int v20; // [sp+20h] [bp-18h]@29
  int v21; // [sp+20h] [bp-18h]@35
  RGE_Static_Object *soldierObj; // [sp+24h] [bp-14h]@21
  XYPoint centerPoint; // [sp+28h] [bp-10h]@3
  XYPoint gatherPoint; // [sp+30h] [bp-8h]@43

  v1 = this;
  v2 = this->md;
  if ( (v2->player->world->world_time - v1->lastUngroupedSoldierTaskTime) / 0x3E8 >= 0x3C )
  {
    v1->lastUngroupedSoldierTaskTime = v2->player->world->world_time;
    v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    if ( v3 )
    {
      centerPoint.x = (signed __int64)v3->world_x;
      centerPoint.y = (signed __int64)v3->world_y;
      v4 = 0;
      i = 0;
      if ( v1->soldiers.numberValue > 0 )
      {
        v5 = (void **)&v1->soldiers.value;
        do
        {
          if ( v4 > v1->soldiers.maximumSizeValue - 1 )
            ManagedArray<int>::resize(&v1->soldiers, v4 + 1);
          if ( TribeTacticalAIModule::groupUnitIsIn(v1, *((_DWORD *)*v5 + v4)) )
          {
            if ( v4 > v1->soldiers.maximumSizeValue - 1 )
              ManagedArray<int>::resize(&v1->soldiers, v4 + 1);
            v6 = v1->ungroupedSoldiers.maximumSizeValue;
            v7 = 0;
            if ( v6 > 0 )
            {
              v8 = v1->ungroupedSoldiers.value;
              do
              {
                if ( *v8 == *((_DWORD *)*v5 + v4) )
                  break;
                ++v7;
                ++v8;
              }
              while ( v7 < v6 );
            }
            if ( v7 < v6 )
            {
              if ( v7 < v6 - 1 )
              {
                do
                {
                  ++v7;
                  v1->ungroupedSoldiers.value[v7 - 1] = v1->ungroupedSoldiers.value[v7];
                }
                while ( v7 < v1->ungroupedSoldiers.maximumSizeValue - 1 );
              }
              v9 = v1->ungroupedSoldiers.numberValue - 1;
              v1->ungroupedSoldiers.numberValue = v9;
              if ( v9 < 0 )
                v1->ungroupedSoldiers.numberValue = 0;
            }
          }
          else
          {
            if ( v4 > v1->soldiers.maximumSizeValue - 1 )
              ManagedArray<int>::resize(&v1->soldiers, v4 + 1);
            soldierObj = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, *((_DWORD *)*v5 + v4));
            if ( soldierObj )
            {
              if ( v4 > v1->soldiers.maximumSizeValue - 1 )
                ManagedArray<int>::resize(&v1->soldiers, v4 + 1);
              v10 = &v1->ungroupedSoldiers.value;
              v11 = 0;
              if ( v1->ungroupedSoldiers.numberValue > 0 )
              {
                while ( v11 < v1->ungroupedSoldiers.maximumSizeValue )
                {
                  if ( (*v10)[v11] == *((_DWORD *)*v5 + v4) )
                  {
                    v4 = i;
                    goto LABEL_48;
                  }
                  v4 = i;
                  if ( ++v11 >= v1->ungroupedSoldiers.numberValue )
                    break;
                }
              }
              if ( v4 > v1->soldiers.maximumSizeValue - 1 )
              {
                v20 = v4 + 1;
                v12 = operator new(4 * v4 + 4);
                if ( v12 )
                {
                  for ( j = 0; j < v1->soldiers.maximumSizeValue; v12[j - 1] = *((_DWORD *)*v5 + j - 1) )
                  {
                    if ( j >= v20 )
                      break;
                    ++j;
                  }
                  operator delete(*v5);
                  *v5 = v12;
                  v1->soldiers.maximumSizeValue = v20;
                }
                v4 = i;
              }
              v14 = 0;
              v15 = *((_DWORD *)*v5 + v4);
              v16 = v1->ungroupedSoldiers.numberValue;
              v21 = *((_DWORD *)*v5 + v4);
              if ( v16 > 0 )
              {
                while ( v14 < v1->ungroupedSoldiers.maximumSizeValue )
                {
                  if ( (*v10)[v14] == v15 )
                  {
                    v4 = i;
                    goto LABEL_43;
                  }
                  v4 = i;
                  if ( ++v14 >= v16 )
                    break;
                }
              }
              if ( v16 > v1->ungroupedSoldiers.maximumSizeValue - 1 )
              {
                ManagedArray<int>::resize(&v1->ungroupedSoldiers, v16 + 1);
                v15 = v21;
              }
              (*v10)[v1->ungroupedSoldiers.numberValue++] = v15;
LABEL_43:
              if ( TribeInformationAIModule::findGatherPosition(
                     &v1->md->informationAI,
                     &centerPoint,
                     1,
                     1,
                     v1->sn[22],
                     v1->sn[72],
                     soldierObj,
                     &gatherPoint) == 1 )
              {
                if ( v4 > v1->soldiers.maximumSizeValue - 1 )
                  ManagedArray<int>::resize(&v1->soldiers, v4 + 1);
                y = (double)gatherPoint.y;
                x = (double)gatherPoint.x;
                TribeTacticalAIModule::moveUnit(v1, *((_DWORD *)*v5 + v4), x, y, 50);
              }
            }
          }
LABEL_48:
          i = ++v4;
        }
        while ( v4 < v1->soldiers.numberValue );
      }
    }
  }
}

//----- (004F4D90) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::taskBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // ebx@1
  TacticalAIGroup *v2; // esi@1
  char *v3; // eax@1
  signed int v4; // edi@11
  int v5; // ebp@11
  TacticalAIGroup *v6; // esi@27
  int v7; // eax@39
  RGE_Static_Object *v8; // edi@39
  int v9; // ebp@41
  int v10; // eax@42
  int v11; // eax@44
  TribeMainDecisionAIModule *v12; // ecx@44
  double v13; // st7@44
  RGE_Static_ObjectVtbl *v14; // edx@44
  int v15; // eax@45
  int v16; // ecx@48
  int v17; // edx@48
  bool v18; // sf@50
  unsigned __int8 v19; // of@50
  RGE_Static_Object *v20; // eax@51
  RGE_Static_Object *v21; // edi@51
  float v22; // eax@53
  float v23; // ecx@53
  int v24; // eax@54
  int v25; // eax@55
  int v26; // eax@57
  RGE_Static_Object *v27; // ebp@57
  int v28; // eax@59
  ObjectMemory *v29; // eax@59
  float v30; // edi@59
  int v31; // eax@60
  int v32; // ecx@62
  int v33; // edx@62
  int v34; // eax@62
  RGE_Static_ObjectVtbl *v35; // edx@62
  float v36; // ecx@64
  int v37; // ecx@64
  double v38; // st7@64
  int v39; // edx@64
  signed int v40; // ebp@68
  int v41; // eax@69
  int v42; // eax@73
  int v43; // eax@75
  RGE_Static_Object *v44; // eax@75
  RGE_Static_Object *v45; // edi@75
  UnitAIModule *v46; // eax@77
  int v47; // eax@78
  int v48; // eax@80
  RGE_Static_Object *v49; // edi@80
  float v50; // eax@81
  float *v51; // edx@81
  int v52; // eax@83
  int v53; // eax@85
  RGE_Static_Object *v54; // eax@85
  RGE_Static_Object *v55; // edi@85
  UnitAIModule *v56; // eax@87
  int v57; // eax@90
  int v58; // eax@92
  RGE_Static_Object *v59; // eax@92
  RGE_Static_Object *v60; // ebp@92
  UnitAIModule *v61; // eax@94
  RGE_Action *v62; // eax@97
  ObjectMemory *v63; // eax@97
  ObjectMemory *v64; // edi@97
  int v65; // eax@98
  int v66; // ecx@99
  int v67; // edx@99
  int v68; // eax@99
  RGE_Static_ObjectVtbl *v69; // edx@99
  float v70; // ecx@101
  int v71; // ecx@101
  double v72; // st7@101
  int v73; // edx@101
  XYZPoint v74; // [sp+Ch] [bp-94h]@45
  int v75; // [sp+18h] [bp-88h]@45
  float *v76; // [sp+1Ch] [bp-84h]@45
  float *v77; // [sp+20h] [bp-80h]@44
  float x; // [sp+24h] [bp-7Ch]@44
  float y; // [sp+28h] [bp-78h]@44
  float z; // [sp+2Ch] [bp-74h]@20
  int numExclusions; // [sp+40h] [bp-60h]@11
  float rXPos; // [sp+44h] [bp-5Ch]@44
  float rYPos; // [sp+48h] [bp-58h]@44
  int dropsiteID; // [sp+4Ch] [bp-54h]@41
  int *v85; // [sp+50h] [bp-50h]@43
  int a; // [sp+54h] [bp-4Ch]@43
  float roYPos; // [sp+58h] [bp-48h]@73
  float roXPos; // [sp+5Ch] [bp-44h]@73
  float pathDistance; // [sp+60h] [bp-40h]@62
  char v90; // [sp+64h] [bp-3Ch]@99
  XYZPoint point; // [sp+68h] [bp-38h]@44
  int v92; // [sp+78h] [bp-28h]@62
  int v93; // [sp+7Ch] [bp-24h]@62
  int v94; // [sp+84h] [bp-1Ch]@99
  int v95; // [sp+88h] [bp-18h]@99
  int exclusions[5]; // [sp+8Ch] [bp-14h]@43

  v1 = this;
  v2 = this->groups.next;
  v3 = (char *)&this->groups;
  if ( v2 != &this->groups )
  {
    do
    {
      if ( !v2 )
        break;
      if ( TacticalAIGroup::type(v2) != 100
        && TacticalAIGroup::type(v2) != 101
        && TacticalAIGroup::type(v2) != 102
        && TacticalAIGroup::type(v2) != 103
        && TacticalAIGroup::type(v2) != 104
        && TacticalAIGroup::type(v2) != 105
        && (!TacticalAIGroup::action(v2) || TacticalAIGroup::action(v2) == 1) )
      {
        v4 = 1;
        *(float *)&numExclusions = COERCE_FLOAT(TacticalAIGroup::isGathered(v2, v1, v1->md));
        v5 = TacticalAIGroup::numberUnits(v2);
        if ( TacticalAIGroup::desiredNumberUnits(v2) > v5
          || *(float *)&numExclusions == 0.0 && TacticalAIGroup::numberUnits(v2) > 1
          || !TacticalAIGroup::allUnitsIdle(v2, v1->md, 1) )
        {
          v4 = 0;
        }
        if ( !v4 )
        {
          if ( *(float *)&numExclusions == 0.0 )
            TacticalAIGroup::task(v2, v1, v1->md, 9, 1, 0);
          goto LABEL_26;
        }
        if ( TacticalAIGroup::type(v2) == 107 )
        {
          LODWORD(z) = 10;
LABEL_25:
          TacticalAIGroup::setAction(v2, SLODWORD(z));
          goto LABEL_26;
        }
        if ( TacticalAIGroup::type(v2) == 108 )
        {
          LODWORD(z) = 11;
          goto LABEL_25;
        }
        if ( TacticalAIGroup::type(v2) == 106 )
        {
          LODWORD(z) = 1;
          goto LABEL_25;
        }
      }
LABEL_26:
      v2 = v2->next;
      v3 = (char *)&v1->groups;
    }
    while ( v2 != &v1->groups );
  }
  v6 = v1->groups.next;
  if ( (char *)v6 != v3 )
  {
    do
    {
      if ( !v6 )
        return;
      if ( TacticalAIGroup::type(v6) != 100
        && TacticalAIGroup::type(v6) != 101
        && TacticalAIGroup::type(v6) != 102
        && TacticalAIGroup::type(v6) != 103
        && TacticalAIGroup::type(v6) != 104
        && TacticalAIGroup::type(v6) != 105
        && TacticalAIGroup::action(v6)
        && TacticalAIGroup::action(v6) != 1 )
      {
        if ( TacticalAIGroup::inUse(v6) )
        {
          if ( TacticalAIGroup::action(v6) != 8 )
            goto LABEL_107;
          v40 = 0;
          if ( TacticalAIGroup::type(v6) == 108 )
          {
            v41 = TacticalAIGroup::commander(v6);
            if ( TribeInformationAIModule::objectToTradeWith(&v1->md->informationAI, v41) )
              v40 = 1;
          }
          if ( TacticalAIGroup::type(v6) == 107 )
          {
            if ( TribeTacticalAIModule::numberWaterExplorers(v1) <= 1 )
            {
              v43 = TacticalAIGroup::commander(v6);
              v44 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v43);
              v45 = v44;
              if ( v44 )
              {
                if ( RGE_Static_Object::unitAI(v44) )
                {
                  v46 = RGE_Static_Object::unitAI(v45);
                  if ( UnitAIModule::currentOrder(v46) != 705 )
                  {
                    TacticalAIGroup::setAction(v6, 8);
                    z = 0.0;
                    LODWORD(y) = 1;
                    v47 = TacticalAIGroup::action(v6);
                    TacticalAIGroup::task(v6, v1, v1->md, v47, SLODWORD(y), SLODWORD(z));
                    TacticalAIGroup::setInUse(v6, 1);
                  }
                }
              }
            }
            else
            {
              z = 0.0;
              y = 0.0;
              x = COERCE_FLOAT(&a);
              v77 = &roYPos;
              v76 = &roXPos;
              roXPos = 0.0;
              roYPos = 0.0;
              a = -1;
              v42 = TacticalAIGroup::commander(v6);
              if ( TribeInformationAIModule::gameIDOfResourceObject(
                     &v1->md->informationAI,
                     0,
                     v42,
                     v76,
                     v77,
                     (int *)LODWORD(x),
                     (int *)LODWORD(y),
                     SLODWORD(z)) != -1 )
                v40 = 1;
            }
          }
          if ( v40 != 1 )
          {
LABEL_107:
            if ( TacticalAIGroup::action(v6) == 10 )
            {
              v52 = TacticalAIGroup::target(v6);
              if ( !MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v52) )
              {
                TacticalAIGroup::setInUse(v6, 0);
                TacticalAIGroup::setAction(v6, 1);
                TacticalAIGroup::setTarget(v6, -1);
                TacticalAIGroup::setTargetType(v6, -1);
                TacticalAIGroup::setTargetLocation(v6, -1.0, -1.0, -1.0);
                v6->numberObjectsToDestroyValue = 0;
                goto LABEL_104;
              }
              v53 = TacticalAIGroup::commander(v6);
              v54 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v53);
              v55 = v54;
              if ( v54 )
              {
                if ( RGE_Static_Object::unitAI(v54) )
                {
                  v56 = RGE_Static_Object::unitAI(v55);
                  if ( UnitAIModule::currentAction(v56) == -1 )
                  {
                    TacticalAIGroup::setInUse(v6, 0);
                    TacticalAIGroup::setAction(v6, 1);
                    TacticalAIGroup::setTarget(v6, -1);
                    z = -6.8056469e38/*NaN*/;
                    v6->numberObjectsToDestroyValue = 0;
                    TacticalAIGroup::setTargetType(v6, SLODWORD(z));
                    TacticalAIGroup::setTargetLocation(v6, -1.0, -1.0, -1.0);
                    v6 = v6->next;
                  }
                }
              }
            }
            if ( TacticalAIGroup::action(v6) == 11 )
            {
              v57 = TacticalAIGroup::target(v6);
              if ( MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v57) )
              {
                v58 = TacticalAIGroup::commander(v6);
                v59 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v58);
                v60 = v59;
                if ( !v59 || !RGE_Static_Object::unitAI(v59) )
                  goto LABEL_104;
                v61 = RGE_Static_Object::unitAI(v60);
                if ( UnitAIModule::currentAction(v61) != -1 )
                {
                  if ( !RGE_Action_Object::have_action((RGE_Action_Object *)v60) )
                    goto LABEL_104;
                  v62 = RGE_Action_List::get_action((RGE_Action_List *)v60[2].unitAIValue);
                  v63 = TribeInformationAIModule::objectToTradeWith(&v1->md->informationAI, v62->target2ID);
                  v64 = v63;
                  if ( !v63 )
                    goto LABEL_104;
                  a = v63->id;
                  v65 = TacticalAIGroup::target(v6);
                  if ( a == v65 )
                    goto LABEL_104;
                  z = -6.8056469e38/*NaN*/;
                  v66 = v64->z;
                  y = -6.8056469e38/*NaN*/;
                  v95 = v66;
                  LODWORD(x) = 1;
                  v77 = (float *)&v90;
                  v67 = v64->y;
                  v76 = (float *)a;
                  v75 = 1065353216;
                  v68 = v64->x;
                  v94 = v67;
                  v69 = v60->vfptr;
                  v74.x = v68;
                  v74.y = v94;
                  v74.z = v66;
                  if ( ((int (__thiscall *)(RGE_Static_Object *, int, int, int, signed int, int, char *, signed int, signed int, signed int))v69->canPath)(
                         v60,
                         v68,
                         v94,
                         v66,
                         1065353216,
                         a,
                         &v90,
                         1,
                         -1,
                         -1) )
                  {
                    TacticalAIGroup::setTarget(v6, v64->id);
                    TacticalAIGroup::setTargetType(v6, v64->type);
                    z = v70;
                    v71 = v64->y;
                    a = v64->z;
                    v72 = (double)a;
                    a = v71;
                    v73 = v64->x;
                    z = v72;
                    a = v73;
                    y = (double)v71;
                    x = (double)v73;
                    TacticalAIGroup::setTargetLocation(v6, x, y, z);
                    TacticalAIGroup::setInUse(v6, 1);
                    LODWORD(z) = 1;
                    goto LABEL_102;
                  }
LABEL_100:
                  TacticalAIGroup::setAction(v6, 1);
                  goto LABEL_104;
                }
                TacticalAIGroup::setInUse(v6, 0);
                TacticalAIGroup::setAction(v6, 1);
                TacticalAIGroup::setTarget(v6, -1);
                z = -6.8056469e38/*NaN*/;
                v6->numberObjectsToDestroyValue = 0;
                TacticalAIGroup::setTargetType(v6, SLODWORD(z));
                TacticalAIGroup::setTargetLocation(v6, -1.0, -1.0, -1.0);
                v6 = v6->next;
              }
              else
              {
                TacticalAIGroup::setInUse(v6, 0);
                TacticalAIGroup::setAction(v6, 1);
                TacticalAIGroup::setTarget(v6, -1);
                z = -6.8056469e38/*NaN*/;
                v6->numberObjectsToDestroyValue = 0;
                TacticalAIGroup::setTargetType(v6, SLODWORD(z));
                TacticalAIGroup::setTargetLocation(v6, -1.0, -1.0, -1.0);
              }
            }
          }
          else
          {
            v48 = TacticalAIGroup::commander(v6);
            v49 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v48);
            if ( v49 )
            {
              TacticalAIGroup::setInUse(v6, 0);
              TacticalAIGroup::setAction(v6, 1);
              TacticalAIGroup::setTarget(v6, -1);
              z = -6.8056469e38/*NaN*/;
              v6->numberObjectsToDestroyValue = 0;
              TacticalAIGroup::setTargetType(v6, SLODWORD(z));
              TacticalAIGroup::setTargetLocation(v6, -1.0, -1.0, -1.0);
              TacticalAIGroup::setGatherLocation(v6, v49->world_x, v49->world_y, v49->world_z);
              z = 0.0;
              LODWORD(y) = 1;
              v50 = COERCE_FLOAT(TacticalAIGroup::action(v6));
              v51 = (float *)v1->md;
              x = v50;
              v77 = v51;
              goto LABEL_103;
            }
          }
        }
        else if ( TacticalAIGroup::type(v6) == 107 )
        {
          v7 = TacticalAIGroup::commander(v6);
          v8 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v7);
          if ( v8 )
          {
            v9 = -1;
            *(float *)&numExclusions = 0.0;
            dropsiteID = -1;
            if ( TribeTacticalAIModule::numberWaterExplorers(v1) > 0 )
            {
              v10 = TacticalAIGroup::commander(v6);
              if ( TribeInformationAIModule::fullyExploredZone(&v1->md->informationAI, v10) == 1 )
              {
                a = 0;
                v85 = exclusions;
                do
                {
                  z = *(float *)&numExclusions;
                  y = COERCE_FLOAT(exclusions);
                  x = COERCE_FLOAT(&dropsiteID);
                  v11 = v8->id;
                  v77 = &rYPos;
                  v12 = v1->md;
                  rXPos = 0.0;
                  rYPos = 0.0;
                  v9 = TribeInformationAIModule::gameIDOfResourceObject(
                         &v12->informationAI,
                         0,
                         v11,
                         &rXPos,
                         &rYPos,
                         &dropsiteID,
                         exclusions,
                         numExclusions);
                  point.x = (signed __int64)rXPos;
                  v13 = v8->world_z;
                  point.y = (signed __int64)rYPos;
                  v14 = v8->vfptr;
                  point.z = (signed __int64)v13;
                  z = -6.8056469e38/*NaN*/;
                  y = -6.8056469e38/*NaN*/;
                  LODWORD(x) = 1;
                  v77 = 0;
                  if ( dropsiteID == -1 )
                  {
                    v76 = (float *)v9;
                    v75 = 1065353216;
                    v74 = point;
                    v15 = ((int (__thiscall *)(RGE_Static_Object *, int, int, int, signed int, int, float *, _DWORD, _DWORD, _DWORD))v14->canPath)(
                            v8,
                            point.x,
                            point.y,
                            point.z,
                            1065353216,
                            v9,
                            v77,
                            LODWORD(x),
                            LODWORD(y),
                            LODWORD(z));
                  }
                  else
                  {
                    v76 = (float *)1065353216;
                    v75 = dropsiteID;
                    v74.z = v9;
                    v15 = ((int (__thiscall *)(RGE_Static_Object *, int, int, signed int, float *, _DWORD, _DWORD, _DWORD))v14->canBidirectionPath)(
                            v8,
                            v9,
                            dropsiteID,
                            1065353216,
                            v77,
                            LODWORD(x),
                            LODWORD(y),
                            LODWORD(z));
                  }
                  if ( !v15 )
                  {
                    v16 = (int)v85;
                    v17 = numExclusions + 1;
                    *v85 = v9;
                    numExclusions = v17;
                    v85 = (int *)(v16 + 4);
                  }
                  if ( v15 == 1 )
                    break;
                  v19 = __OFSUB__(a + 1, 5);
                  v18 = a++ - 4 < 0;
                }
                while ( v18 ^ v19 );
              }
            }
            v20 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v9);
            v21 = v20;
            if ( v9 >= 0 && v20 )
            {
              TacticalAIGroup::setTarget(v6, v9);
              TacticalAIGroup::setTargetType(v6, v21->master_obj->id);
              v22 = v21->world_y;
              v23 = v21->world_x;
              z = v21->world_z;
              y = v22;
              x = v23;
              goto LABEL_65;
            }
            v24 = TacticalAIGroup::commander(v6);
            if ( TribeInformationAIModule::fullyExploredZone(&v1->md->informationAI, v24) != 1 )
              goto LABEL_100;
            TacticalAIGroup::setAction(v6, 8);
            z = 0.0;
            LODWORD(y) = 1;
            v25 = TacticalAIGroup::action(v6);
            TacticalAIGroup::task(v6, v1, v1->md, v25, SLODWORD(y), SLODWORD(z));
            TacticalAIGroup::setInUse(v6, 1);
          }
          else
          {
            TacticalAIGroup::setAction(v6, 1);
          }
        }
        else
        {
          if ( TacticalAIGroup::type(v6) != 108 )
            goto LABEL_66;
          v26 = TacticalAIGroup::commander(v6);
          v27 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v26);
          if ( v27 )
          {
            v28 = TacticalAIGroup::commander(v6);
            v29 = TribeInformationAIModule::objectToTradeWith(&v1->md->informationAI, v28);
            v30 = *(float *)&v29;
            if ( v29 )
            {
              z = -6.8056469e38/*NaN*/;
              v32 = v29->y;
              y = -6.8056469e38/*NaN*/;
              v92 = v32;
              LODWORD(x) = 1;
              v77 = &pathDistance;
              v33 = v29->z;
              v76 = (float *)v29->id;
              v75 = 1065353216;
              v34 = v29->x;
              v93 = v33;
              v35 = v27->vfptr;
              v74.x = v34;
              v74.y = v32;
              v74.z = v93;
              if ( ((int (__thiscall *)(RGE_Static_Object *, int, int, int, signed int, float *, float *, signed int, signed int, signed int))v35->canPath)(
                     v27,
                     v34,
                     v32,
                     v93,
                     1065353216,
                     v76,
                     &pathDistance,
                     1,
                     -1,
                     -1) )
              {
                TacticalAIGroup::setTarget(v6, *(_DWORD *)LODWORD(v30));
                TacticalAIGroup::setTargetType(v6, *(_WORD *)(LODWORD(v30) + 4));
                z = v36;
                v37 = *(_BYTE *)(LODWORD(v30) + 9);
                a = *(_BYTE *)(LODWORD(v30) + 10);
                v38 = (double)a;
                a = v37;
                v39 = *(_BYTE *)(LODWORD(v30) + 8);
                z = v38;
                a = v39;
                y = (double)v37;
                x = (double)v39;
LABEL_65:
                TacticalAIGroup::setTargetLocation(v6, x, y, z);
                TacticalAIGroup::setInUse(v6, 1);
LABEL_66:
                z = 0.0;
LABEL_102:
                LODWORD(y) = 1;
                x = COERCE_FLOAT(TacticalAIGroup::action(v6));
                v77 = (float *)v1->md;
LABEL_103:
                TacticalAIGroup::task(v6, v1, (TribeMainDecisionAIModule *)v77, SLODWORD(x), SLODWORD(y), SLODWORD(z));
                goto LABEL_104;
              }
              TacticalAIGroup::setAction(v6, 1);
            }
            else
            {
              v31 = TacticalAIGroup::commander(v6);
              if ( TribeInformationAIModule::fullyExploredZone(&v1->md->informationAI, v31) != 1 )
                goto LABEL_100;
              TacticalAIGroup::setAction(v6, 8);
              z = v30;
              LODWORD(y) = 1;
              x = COERCE_FLOAT(TacticalAIGroup::action(v6));
              TacticalAIGroup::task(v6, v1, v1->md, SLODWORD(x), SLODWORD(y), SLODWORD(z));
              TacticalAIGroup::setInUse(v6, 1);
            }
          }
          else
          {
            TacticalAIGroup::setAction(v6, 1);
          }
        }
      }
LABEL_104:
      v6 = v6->next;
    }
    while ( v6 != &v1->groups );
  }
}

//----- (004F57C0) --------------------------------------------------------
void __usercall TribeTacticalAIModule::evaluateOpenTasks(TribeTacticalAIModule *this@<ecx>, double a2@<st0>)
{
  TribeTacticalAIModule *v2; // esi@1
  int v3; // ebx@1
  void **v4; // edi@2
  RGE_Static_Object *v5; // eax@6
  RGE_Static_Object *v6; // ebp@6
  int j; // eax@10
  RGE_Static_ObjectVtbl *v8; // ebx@14
  RGE_Static_Object *v9; // eax@18
  int v10; // ebx@20
  _DWORD *v11; // ebp@20
  int l; // eax@21
  int **v13; // ebp@25
  int v14; // eax@25
  int v15; // ebx@25
  int v16; // ecx@25
  int v17; // ebx@33
  _DWORD *v18; // ebp@33
  int k; // eax@34
  UnitAIModule *v20; // eax@39
  UnitAIModule *v21; // eax@40
  int v22; // eax@40
  RGE_Static_Object *v23; // eax@40
  int m; // ebx@47
  int v25; // ebp@49
  int *v26; // edi@49
  int n; // eax@50
  RGE_Static_Object *v28; // eax@54
  int v29; // ebp@58
  int *v30; // edi@58
  int ii; // eax@59
  int jj; // ebx@65
  int v33; // ebp@67
  int *v34; // edi@67
  int kk; // eax@68
  RGE_Static_Object *v36; // eax@72
  int v37; // ebp@76
  int *v38; // edi@76
  int ll; // eax@77
  int mm; // ebx@83
  int v41; // ebp@85
  int *v42; // edi@85
  int nn; // eax@86
  RGE_Static_Object *v44; // eax@90
  int v45; // ebp@94
  int *v46; // edi@94
  int i1; // eax@95
  TacticalAIGroup *i2; // edi@101
  int v49; // eax@105
  TacticalAIGroup *v50; // ebx@105
  int v51; // eax@107
  RGE_Static_Object *v52; // eax@107
  int v53; // eax@110
  RGE_Static_Object *v54; // eax@110
  int v55; // [sp-8h] [bp-28h]@38
  int i; // [sp+10h] [bp-10h]@1
  int v57; // [sp+14h] [bp-Ch]@6

  v2 = this;
  v3 = 0;
  i = 0;
  if ( this->civilians.numberValue > 0 )
  {
    v4 = (void **)&this->civilians.value;
    while ( 1 )
    {
      if ( v3 > v2->civilians.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v2->civilians, v3 + 1);
      v57 = 4 * v3;
      v5 = RGE_Game_World::object(v2->md->player->world, *((_DWORD *)*v4 + v3));
      v6 = v5;
      if ( v5 && RGE_Static_Object::unitAI(v5) )
      {
        if ( i > v2->civilians.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v2->civilians, i + 1);
        for ( j = 0; j < v2->unitsTaskedThisUpdate.numberValue; ++j )
        {
          if ( j >= v2->unitsTaskedThisUpdate.maximumSizeValue )
            break;
          if ( v2->unitsTaskedThisUpdate.value[j] == *(_DWORD *)((char *)*v4 + v57) )
            goto LABEL_46;
        }
        v8 = v6->vfptr;
        v6->vfptr->getSpeed(v6);
        if ( a2 != 0.0
          || (a2 = v6->attribute_amount_held, a2 <= 0.0)
          || v8->waitingToMove(v6)
          || (unsigned __int8)v8->actionState(v6) > 2u )
        {
          v20 = RGE_Static_Object::unitAI(v6);
          if ( UnitAIModule::currentOrder(v20) == 700 )
          {
            v21 = RGE_Static_Object::unitAI(v6);
            v22 = UnitAIModule::currentTarget(v21);
            v23 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v22);
            if ( !v23 || v23->object_state > 2u )
            {
              if ( i > v2->civilians.maximumSizeValue - 1 )
                ManagedArray<int>::resize(&v2->civilians, i + 1);
              v55 = *(_DWORD *)((char *)*v4 + v57);
              goto LABEL_45;
            }
          }
        }
        else
        {
          v9 = TribeInformationAIModule::findClosestReturnDropsite(&v2->md->informationAI, v6);
          if ( !v9 )
          {
            if ( i > v2->civilians.maximumSizeValue - 1 )
            {
              v17 = i + 1;
              v18 = operator new(v57 + 4);
              if ( v18 )
              {
                for ( k = 0; k < v2->civilians.maximumSizeValue; v18[k - 1] = *((_DWORD *)*v4 + k - 1) )
                {
                  if ( k >= v17 )
                    break;
                  ++k;
                }
                operator delete(*v4);
                *v4 = v18;
                v2->civilians.maximumSizeValue = v17;
              }
            }
            v55 = *(_DWORD *)((char *)*v4 + v57);
LABEL_45:
            TribeTacticalAIModule::stopUnit(v2, v55, 100);
            goto LABEL_46;
          }
          ((void (__stdcall *)(RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD))v2->md->player->vfptr->sendGameOrder)(
            v6,
            v9,
            LODWORD(v9->world_x),
            LODWORD(v9->world_y));
          if ( i > v2->civilians.maximumSizeValue - 1 )
          {
            v10 = i + 1;
            v11 = operator new(v57 + 4);
            if ( v11 )
            {
              for ( l = 0; l < v2->civilians.maximumSizeValue; v11[l - 1] = *((_DWORD *)*v4 + l - 1) )
              {
                if ( l >= v10 )
                  break;
                ++l;
              }
              operator delete(*v4);
              *v4 = v11;
              v2->civilians.maximumSizeValue = v10;
            }
          }
          v13 = &v2->unitsTaskedThisUpdate.value;
          v14 = 0;
          v15 = *(_DWORD *)((char *)*v4 + v57);
          v16 = v2->unitsTaskedThisUpdate.numberValue;
          if ( v16 > 0 )
          {
            do
            {
              if ( v14 >= v2->unitsTaskedThisUpdate.maximumSizeValue )
                break;
              if ( (*v13)[v14] == v15 )
                goto LABEL_46;
              ++v14;
            }
            while ( v14 < v16 );
          }
          if ( v16 > v2->unitsTaskedThisUpdate.maximumSizeValue - 1 )
            ManagedArray<int>::resize(&v2->unitsTaskedThisUpdate, v16 + 1);
          (*v13)[v2->unitsTaskedThisUpdate.numberValue++] = v15;
        }
      }
LABEL_46:
      if ( ++i >= v2->civilians.numberValue )
        break;
      v3 = i;
    }
  }
  for ( m = 0; m < v2->civilians.numberValue; ++m )
  {
    if ( m > v2->civilians.maximumSizeValue - 1 )
    {
      v25 = m + 1;
      v26 = (int *)operator new(4 * m + 4);
      if ( v26 )
      {
        for ( n = 0; n < v2->civilians.maximumSizeValue; v26[n - 1] = v2->civilians.value[n - 1] )
        {
          if ( n >= v25 )
            break;
          ++n;
        }
        operator delete(v2->civilians.value);
        v2->civilians.value = v26;
        v2->civilians.maximumSizeValue = v25;
      }
    }
    v28 = RGE_Game_World::object(v2->md->player->world, v2->civilians.value[m]);
    if ( !v28 || v28->hp < 1.0 || !RGE_Static_Object::unitAI(v28) )
    {
      if ( m > v2->civilians.maximumSizeValue - 1 )
      {
        v29 = m + 1;
        v30 = (int *)operator new(4 * m + 4);
        if ( v30 )
        {
          for ( ii = 0; ii < v2->civilians.maximumSizeValue; v30[ii - 1] = v2->civilians.value[ii - 1] )
          {
            if ( ii >= v29 )
              break;
            ++ii;
          }
          operator delete(v2->civilians.value);
          v2->civilians.value = v30;
          v2->civilians.maximumSizeValue = v29;
        }
      }
      TribeTacticalAIModule::removeObject(v2, v2->civilians.value[m]);
    }
  }
  for ( jj = 0; jj < v2->soldiers.numberValue; ++jj )
  {
    if ( jj > v2->soldiers.maximumSizeValue - 1 )
    {
      v33 = jj + 1;
      v34 = (int *)operator new(4 * jj + 4);
      if ( v34 )
      {
        for ( kk = 0; kk < v2->soldiers.maximumSizeValue; v34[kk - 1] = v2->soldiers.value[kk - 1] )
        {
          if ( kk >= v33 )
            break;
          ++kk;
        }
        operator delete(v2->soldiers.value);
        v2->soldiers.value = v34;
        v2->soldiers.maximumSizeValue = v33;
      }
    }
    v36 = RGE_Game_World::object(v2->md->player->world, v2->soldiers.value[jj]);
    if ( !v36 || v36->hp < 1.0 || !RGE_Static_Object::unitAI(v36) )
    {
      if ( jj > v2->soldiers.maximumSizeValue - 1 )
      {
        v37 = jj + 1;
        v38 = (int *)operator new(4 * jj + 4);
        if ( v38 )
        {
          for ( ll = 0; ll < v2->soldiers.maximumSizeValue; v38[ll - 1] = v2->soldiers.value[ll - 1] )
          {
            if ( ll >= v37 )
              break;
            ++ll;
          }
          operator delete(v2->soldiers.value);
          v2->soldiers.value = v38;
          v2->soldiers.maximumSizeValue = v37;
        }
      }
      TribeTacticalAIModule::removeObject(v2, v2->soldiers.value[jj]);
    }
  }
  for ( mm = 0; mm < v2->boats.numberValue; ++mm )
  {
    if ( mm > v2->boats.maximumSizeValue - 1 )
    {
      v41 = mm + 1;
      v42 = (int *)operator new(4 * mm + 4);
      if ( v42 )
      {
        for ( nn = 0; nn < v2->boats.maximumSizeValue; v42[nn - 1] = v2->boats.value[nn - 1] )
        {
          if ( nn >= v41 )
            break;
          ++nn;
        }
        operator delete(v2->boats.value);
        v2->boats.value = v42;
        v2->boats.maximumSizeValue = v41;
      }
    }
    v44 = RGE_Game_World::object(v2->md->player->world, v2->boats.value[mm]);
    if ( !v44 || v44->hp < 1.0 || !RGE_Static_Object::unitAI(v44) )
    {
      if ( mm > v2->boats.maximumSizeValue - 1 )
      {
        v45 = mm + 1;
        v46 = (int *)operator new(4 * mm + 4);
        if ( v46 )
        {
          for ( i1 = 0; i1 < v2->boats.maximumSizeValue; v46[i1 - 1] = v2->boats.value[i1 - 1] )
          {
            if ( i1 >= v45 )
              break;
            ++i1;
          }
          operator delete(v2->boats.value);
          v2->boats.value = v46;
          v2->boats.maximumSizeValue = v45;
        }
      }
      TribeTacticalAIModule::removeObject(v2, v2->boats.value[mm]);
    }
  }
  for ( i2 = v2->groups.next; i2 != &v2->groups; i2 = i2->next )
  {
    if ( !i2 )
      break;
    if ( TacticalAIGroup::type(i2) == 106 && TacticalAIGroup::action(i2) == 12 )
    {
      v49 = TacticalAIGroup::assistGroupID(i2);
      v50 = TribeTacticalAIModule::group(v2, v49, -1, -1, -1);
      if ( TacticalAIGroup::assistGroupID(i2) != -1 && v50 )
      {
        v51 = TacticalAIGroup::commander(i2);
        v52 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v51);
        if ( v52 )
        {
          if ( v52->vfptr->actionState(v52) == 2 && TacticalAIGroup::action(v50) == 16 )
          {
            v53 = TacticalAIGroup::commander(v50);
            v54 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v53);
            if ( v54 )
            {
              if ( v54->objects->number_of_objects > 0 )
                TacticalAIGroup::setAction(v50, 15);
            }
          }
        }
      }
      else
      {
        TacticalAIGroup::setAction(i2, 1);
        TacticalAIGroup::setTarget(i2, -1);
        TacticalAIGroup::setTargetType(i2, -1);
        TacticalAIGroup::setTargetLocation(i2, -1.0, -1.0, -1.0);
        TacticalAIGroup::setGatherLocation(i2, -1.0, -1.0, -1.0);
        TacticalAIGroup::setRetreatLocation(i2, -1.0, -1.0, -1.0);
        TacticalAIGroup::setInUse(i2, 0);
        TacticalAIGroup::setWaitCode(i2, -1);
        i2->playNumberValue = -1;
      }
    }
  }
}

//----- (004F5FB0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::evaluateBuildListInsertions(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  TribeMainDecisionAIModule *v2; // eax@4
  TribeMainDecisionAIModule *v3; // eax@11
  int v4; // ecx@15
  TribeMainDecisionAIModule *v5; // edi@16

  v1 = this;
  if ( this->sn[205] != 1 )
    goto LABEL_21;
  if ( BuildAIModule::haveBuildList((BuildAIModule *)&this->md->buildAI.vfptr) )
  {
    if ( !v1->builtFirstStoragePit )
    {
      v2 = v1->md;
      if ( v2->informationAI.numberFoundForestTilesValue >= v1->sn[169] )
      {
        TribeBuildAIModule::insert(&v2->buildAI, 103, 1, 0);
        v1->builtFirstStoragePit = 1;
      }
    }
  }
  if ( v1->sn[205] != 1
    || !BuildAIModule::haveBuildList((BuildAIModule *)&v1->md->buildAI.vfptr)
    || v1->builtFirstGranary
    || v1->builtFirstStoragePit != 1 && TribeResourceAIModule::resource(&v1->md->resourceAI, 1) < 250
    || (v3 = v1->md, v3->informationAI.closestDropsiteValue[0] == -1) )
  {
LABEL_21:
    if ( v1->builtFirstGranary == 1 )
      TribeTacticalAIModule::checkForBuildInsertion(v1, 68, 1, 0);
  }
  else
  {
    TribeBuildAIModule::insert(&v3->buildAI, 68, 1, 1);
    v1->builtFirstGranary = 1;
  }
  v4 = v1->sn[175];
  if ( v4 != -1 )
  {
    v5 = v1->md;
    if ( v1->sn[176] <= v5->player->world->world_time / 0xEA60 )
    {
      TribeBuildAIModule::insert(&v5->buildAI, v4, 1, 0);
      v1->sn[175] = -1;
    }
  }
  TribeTacticalAIModule::checkForBuildInsertion(v1, 50, 1, 0);
  TribeTacticalAIModule::checkForBuildInsertion(v1, 79, 1, 0);
}

//----- (004F6100) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberCivilians(TribeTacticalAIModule *this)
{
  return this->civilians.numberValue;
}

//----- (004F6110) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberCivilianExplorers(TribeTacticalAIModule *this)
{
  return this->civilianExplorers.numberValue;
}

//----- (004F6120) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberGatherers(TribeTacticalAIModule *this)
{
  return this->numberGatherersValue;
}

//----- (004F6130) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::desiredNumberCivilianExplorers(TribeTacticalAIModule *this)
{
  return this->civilianExplorers.desiredNumberValue;
}

//----- (004F6140) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::desiredNumberGatherers(TribeTacticalAIModule *this)
{
  return this->desiredNumberGatherersValue;
}

//----- (004F6150) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberSoldiers(TribeTacticalAIModule *this)
{
  return this->soldiers.numberValue;
}

//----- (004F6160) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberSoldierExplorers(TribeTacticalAIModule *this)
{
  return TribeTacticalAIModule::numberUnitsInGroups(this, 102);
}

//----- (004F6170) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberBoats(TribeTacticalAIModule *this)
{
  return this->boats.numberValue;
}

//----- (004F6180) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::neededResource(TribeTacticalAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= 4 )
    result = -1;
  else
    result = this->neededResourceValue[n];
  return result;
}

//----- (004F61A0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::neededResourceAmount(TribeTacticalAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= 4 )
    result = -1;
  else
    result = ResourceItem::value(&this->neededResources, this->neededResourceValue[n]);
  return result;
}

//----- (004F61D0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::detask(TribeTacticalAIModule *this, int uid)
{
  TribeTacticalAIModule *v2; // esi@1

  v2 = this;
  if ( uid == -1 )
  {
    AIModule::logCommonHistory((AIModule *)&this->vfptr, aErrorDetasking, -1);
  }
  else
  {
    TribeTacticalAIModule::removeFromTaskLists(this, uid);
    TribeTacticalAIModule::stopUnit(v2, uid, 100);
  }
}

//----- (004F6210) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::strategicNumber(TribeTacticalAIModule *this, int sNum)
{
  int result; // eax@3

  if ( sNum < 0 || sNum >= 226 )
    result = -1;
  else
    result = this->sn[sNum];
  return result;
}

//----- (004F6230) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::setStrategicNumber(TribeTacticalAIModule *this, int sNum, int v)
{
  if ( sNum >= 0 && sNum < 226 )
  {
    this->sn[sNum] = v;
    if ( sNum == 117
      || sNum == 120
      || sNum == 119
      || sNum == 118
      || sNum == 156
      || sNum == 157
      || sNum == 158
      || sNum == 159 )
    {
      if ( v >= 0 )
      {
        if ( v > 100 )
          this->sn[sNum] = 100;
      }
      else
      {
        this->sn[sNum] = 0;
      }
    }
    if ( sNum == 105 )
      TribeInformationAIModule::setSaveLearnInformation(&this->md->informationAI, v);
  }
}

//----- (004F62C0) --------------------------------------------------------
void __userpurge TribeTacticalAIModule::notify(TribeTacticalAIModule *this@<ecx>, int callerID, int recipientID, int mType, int p1, int p2, int p3, int a8, int a9)
{
  TribeTacticalAIModule *v9; // esi@1
  RGE_Static_Object *v10; // eax@1
  RGE_Static_Object *v11; // ebx@7
  TribeMainDecisionAIModule *v12; // eax@8
  RGE_Static_Object *v13; // ecx@9
  __int16 v14; // ax@12
  int v15; // eax@14
  int v16; // ecx@16
  int v17; // eax@16
  UnitAIModule *v18; // eax@21
  int v19; // edx@28
  bool v20; // zf@28
  RGE_PlayerVtbl *v21; // edx@28
  char *v22; // eax@30
  RGE_Player *v23; // ecx@36
  unsigned int v24; // ecx@42
  unsigned int v25; // edi@43
  TribeMainDecisionAIModule *v26; // ecx@44
  char *v27; // ecx@45
  TacticalAIGroup *v28; // edi@46
  char *v29; // edx@47
  int v30; // eax@49
  RGE_Static_Object *v31; // ebp@49
  double v32; // st7@50
  signed __int64 v33; // rax@50
  double v34; // st7@50
  TribeMainDecisionAIModule *v35; // eax@51
  RGE_Static_Object *v36; // edi@53
  signed __int64 v37; // rax@53
  double v38; // st6@54
  double v39; // st7@54
  int v40; // edi@56
  int v41; // eax@56
  TribeMainDecisionAIModule *v42; // ecx@56
  int v43; // edi@56
  unsigned int v44; // ebp@56
  int v45; // ebp@62
  int *v46; // edi@62
  int ll; // eax@63
  int v48; // ecx@68
  int v49; // edx@68
  int v50; // eax@68
  int v51; // ebp@73
  int *v52; // edi@73
  int mm; // eax@74
  double v54; // st7@82
  TribeMainDecisionAIModule *v55; // ecx@83
  BOOL v56; // eax@83
  int v57; // ebp@84
  int v58; // ebp@85
  double v59; // st7@87
  RGE_Player *v60; // ecx@87
  int v61; // ebp@91
  int v62; // ebp@96
  int *v63; // edi@96
  int m; // eax@97
  RGE_Static_Object *v65; // eax@102
  RGE_Static_Object *v66; // edi@102
  UnitAIModule *v67; // eax@104
  UnitAIModule *v68; // eax@105
  UnitAIModule *v69; // eax@106
  UnitAIModule *v70; // eax@107
  int v71; // eax@107
  TribeMainDecisionAIModule *v72; // ecx@107
  int *v73; // ebp@109
  signed int n; // eax@110
  int *v75; // ebp@117
  int ii; // eax@118
  UnitAIModule *v77; // eax@123
  double v78; // st7@124
  signed __int64 v79; // rax@124
  double v80; // st7@124
  RGE_Static_ObjectVtbl *v81; // ebp@124
  RGE_Static_Object *v82; // eax@125
  int v83; // ebp@126
  int *v84; // edi@126
  int jj; // eax@127
  RGE_Player *v86; // ecx@132
  int v87; // edx@132
  int v88; // ecx@132
  TribeMainDecisionAIModule *v89; // eax@133
  int v90; // ebp@135
  UnitAIModule *v91; // eax@136
  double v92; // st7@138
  signed __int64 v93; // rax@138
  double v94; // st7@138
  signed __int64 v95; // rax@138
  RGE_Static_ObjectVtbl *v96; // ebp@138
  RGE_Static_Object *v97; // eax@139
  int v98; // ebp@140
  int *v99; // edi@140
  int kk; // eax@141
  RGE_Player *v101; // ecx@146
  int v102; // edx@146
  int v103; // ecx@146
  TribeMainDecisionAIModule *v104; // ecx@150
  ObjectMemory *v105; // eax@151
  int v106; // eax@154
  int v107; // ebp@156
  int v108; // ebx@159
  int *v109; // edi@159
  int i; // eax@160
  RGE_Static_Object *v111; // eax@164
  RGE_Static_Object *v112; // edi@164
  int v113; // ebx@168
  int *v114; // edi@168
  int j; // eax@169
  int v116; // ebx@175
  int *v117; // edi@175
  int k; // eax@176
  int v119; // ecx@183
  int l; // eax@183
  int v121; // [sp+10h] [bp-50h]@50
  int v122; // [sp+14h] [bp-4Ch]@50
  char *v123; // [sp+18h] [bp-48h]@4
  XYPoint *v124; // [sp+1Ch] [bp-44h]@4
  signed int v125; // [sp+20h] [bp-40h]@14
  signed int v126; // [sp+24h] [bp-3Ch]@14
  int numberToRespond; // [sp+30h] [bp-30h]@56
  RGE_Static_Object *targetObj; // [sp+34h] [bp-2Ch]@53
  unsigned int entryTime; // [sp+38h] [bp-28h]@4
  RGE_Static_Object *callerObject; // [sp+3Ch] [bp-24h]@1
  XYPoint attackPoint; // [sp+40h] [bp-20h]@44
  XYZPoint point; // [sp+48h] [bp-18h]@50
  int v133; // [sp+54h] [bp-Ch]@138
  int v134; // [sp+58h] [bp-8h]@138
  int v135; // [sp+5Ch] [bp-4h]@50
  void *retaddr; // [sp+60h] [bp+0h]@50
  int callerIDa; // [sp+64h] [bp+4h]@156
  RGE_Static_Object *mTypea; // [sp+6Ch] [bp+Ch]@9
  int mTypeb; // [sp+6Ch] [bp+Ch]@68
  int mTypec; // [sp+6Ch] [bp+Ch]@90
  int mTyped; // [sp+6Ch] [bp+Ch]@154
  RGE_Static_Object *attackedUnitc; // [sp+70h] [bp+10h]@54
  RGE_Static_Object *attackedUnit; // [sp+70h] [bp+10h]@60
  RGE_Static_Object *attackedUnita; // [sp+70h] [bp+10h]@90
  int *attackedUnitb; // [sp+70h] [bp+10h]@153

  v9 = this;
  v10 = RGE_Game_World::object(this->md->aiPlayer->world, callerID);
  callerObject = v10;
  if ( mType != 114 && mType != 116 && !v10 )
    return;
  v124 = (XYPoint *)6404;
  v123 = aCMsdevWorkA_61;
  entryTime = debug_timeGetTime();
  if ( mType == 114 || mType == 116 )
  {
    v104 = v9->md;
    *(float *)&v124 = -6.8056469e38/*NaN*/;
    if ( mType == 114 )
      v105 = TribeInformationAIModule::artifactToCapture(&v104->informationAI, (int)v124);
    else
      v105 = TribeInformationAIModule::ruinToCapture(&v104->informationAI, (int)v124);
    attackedUnitb = (int *)v105;
    if ( v105 )
    {
      v106 = TribeTacticalAIModule::numberSoldiersWithPriority(v9, 100, -1, 1);
      mTyped = 3;
      if ( v106 <= 3 )
        mTyped = v106;
      v107 = 0;
      for ( callerIDa = 0; v107 < v9->workingArea.numberValue; ++v107 )
      {
        if ( callerIDa >= mTyped )
          break;
        if ( v107 > v9->workingArea.maximumSizeValue - 1 )
        {
          v108 = v107 + 1;
          v109 = (int *)operator new(4 * v107 + 4);
          if ( v109 )
          {
            for ( i = 0; i < v9->workingArea.maximumSizeValue; v109[i - 1] = v9->workingArea.value[i - 1] )
            {
              if ( i >= v108 )
                break;
              ++i;
            }
            operator delete(v9->workingArea.value);
            v9->workingArea.value = v109;
            v9->workingArea.maximumSizeValue = v108;
          }
        }
        v111 = RGE_Game_World::object(v9->md->aiPlayer->world, v9->workingArea.value[v107]);
        v112 = v111;
        if ( v111
          && RGE_Static_Object::unitAI(v111)
          && (*((int (__thiscall **)(RGE_Static_Object *, int, signed int, _DWORD, signed int, signed int, signed int))&v112->vfptr->pause
              + 1))(
               v112,
               *attackedUnitb,
               0x40000000,
               0,
               1,
               -1,
               -1) )
        {
          if ( v107 > v9->workingArea.maximumSizeValue - 1 )
          {
            v113 = v107 + 1;
            v114 = (int *)operator new(4 * v107 + 4);
            if ( v114 )
            {
              for ( j = 0; j < v9->workingArea.maximumSizeValue; v114[j - 1] = v9->workingArea.value[j - 1] )
              {
                if ( j >= v113 )
                  break;
                ++j;
              }
              operator delete(v9->workingArea.value);
              v9->workingArea.value = v114;
              v9->workingArea.maximumSizeValue = v113;
            }
          }
          if ( TribeTacticalAIModule::taskDefender(v9, v9->workingArea.value[v107], *attackedUnitb, 2.0, 100) == 1 )
          {
            if ( v107 > v9->workingArea.maximumSizeValue - 1 )
            {
              v116 = v107 + 1;
              v117 = (int *)operator new(4 * v107 + 4);
              if ( v117 )
              {
                for ( k = 0; k < v9->workingArea.maximumSizeValue; v117[k - 1] = v9->workingArea.value[k - 1] )
                {
                  if ( k >= v116 )
                    break;
                  ++k;
                }
                operator delete(v9->workingArea.value);
                v9->workingArea.value = v117;
                v9->workingArea.maximumSizeValue = v116;
              }
            }
            TribeTacticalAIModule::removeFromGroup(v9, v9->workingArea.value[v107]);
            ++callerIDa;
          }
        }
      }
    }
    return;
  }
  if ( mType != 513 )
    return;
  v11 = RGE_Game_World::object(v9->md->aiPlayer->world, p1);
  if ( !v11 )
    return;
  v12 = v9->md;
  if ( v11->owner->id == v12->player->id )
    return;
  v13 = RGE_Game_World::object(v12->aiPlayer->world, callerID);
  mTypea = v13;
  if ( !v13 )
    return;
  if ( !v11->owner->id )
  {
    if ( !v9->zoomingToNextAge || (v14 = v11->master_obj->id, v14 != 126) && v14 != 89 )
    {
      LOBYTE(v15) = TribeTacticalAIModule::dealWithGAIAAttacker(v9, v11, v13, v125, v126);
      if ( v15 == 1 )
        return;
    }
  }
  if ( v11->owner->id )
  {
    v16 = v9->civilians.numberValue;
    v17 = 0;
    if ( v16 > 0 )
    {
      while ( v17 < v9->civilians.maximumSizeValue )
      {
        if ( v9->civilians.value[v17] == callerID )
        {
          v119 = v9->civilianExplorers.numberValue;
          for ( l = 0; l < v119; ++l )
          {
            if ( l >= v9->civilianExplorers.maximumSizeValue )
              break;
            if ( v9->civilianExplorers.value[l] == callerID )
              goto LABEL_20;
          }
          if ( RGE_Game_World::difficultyLevel(v9->md->player->world) == 3 )
          {
            v9->sn[104] -= 2;
            goto LABEL_27;
          }
          if ( RGE_Game_World::difficultyLevel(v9->md->player->world) == 4 )
          {
            --v9->sn[104];
            goto LABEL_27;
          }
          goto LABEL_26;
        }
        if ( ++v17 >= v16 )
          break;
      }
    }
LABEL_20:
    if ( RGE_Static_Object::unitAI(mTypea) )
    {
      v18 = RGE_Static_Object::unitAI(mTypea);
      if ( UnitAIModule::currentOrder(v18) != 705 )
      {
        if ( RGE_Game_World::difficultyLevel(v9->md->player->world) == 3 )
        {
          v9->sn[104] -= 2;
        }
        else if ( RGE_Game_World::difficultyLevel(v9->md->player->world) == 4 )
        {
          --v9->sn[104];
        }
        else
        {
LABEL_26:
          TribeTacticalAIModule::enableAttack(&v9->md->tacticalAI, 3);
        }
LABEL_27:
        TribeTacticalAIModule::checkForAttackResponseBuildInsertions(v9, v11->owner->id);
      }
    }
  }
  v19 = v11->owner->id;
  ++v9->hitsByPlayer[v19];
  v20 = RGE_Player::computerPlayer(v11->owner) == 0;
  v21 = v9->md->player->vfptr;
  v124 = (XYPoint *)v11->owner->id;
  if ( v20 )
  {
    if ( (*(int (__stdcall **)(XYPoint *))&v21->gap4[24])(v124) == 1 )
    {
      v22 = (char *)v11->owner->id;
      if ( v9->hitsByPlayer[(_DWORD)v22] >= v9->sn[221] && v9->sn[215] == 1 )
      {
        v124 = (XYPoint *)1;
        v123 = v22;
LABEL_37:
        DiplomacyAIModule::setChangeable(&v9->md->diplomacyAI, (int)v123, (char)v124);
        DiplomacyAIModule::setStance(&v9->md->diplomacyAI, v11->owner->id, 0, 100);
        DiplomacyAIModule::setRelation(&v9->md->diplomacyAI, v11->owner->id, 3);
        DiplomacyAIModule::setChangeable(&v9->md->diplomacyAI, v11->owner->id, 0);
        goto LABEL_38;
      }
    }
    DiplomacyAIModule::changeStance(&v9->md->diplomacyAI, v11->owner->id, 2, v9->sn[178]);
    DiplomacyAIModule::changeStance(&v9->md->diplomacyAI, v11->owner->id, 0, v9->sn[178]);
  }
  else if ( (*(int (__stdcall **)(XYPoint *))&v21->gap4[24])(v124) == 1
         && (*(int (__stdcall **)(_DWORD))&v9->md->player->world->players[v11->owner->id]->vfptr->gap4[20])(v9->md->player->id) == 1 )
  {
    v23 = v11->owner;
    v124 = (XYPoint *)1;
    v123 = (char *)v23->id;
    goto LABEL_37;
  }
LABEL_38:
  if ( v9->sn[124] > 0 && v9->sn[128] == v11->owner->id && v9->sn[133] == 1 )
    TribeMainDecisionAIModule::revokeTributeAlliance(v9->md);
  TribeInformationAIModule::storeAttackMemory(
    &v9->md->informationAI,
    0,
    (signed __int64)mTypea->world_x,
    (signed __int64)mTypea->world_y,
    v11->owner->id,
    v9->md->player->id,
    0,
    0,
    v9->md->player->world->world_time,
    -1);
  v24 = v9->lastAttackResponseTime;
  if ( !v24
    || (v25 = (v9->md->player->world->world_time - v24) / 0x3E8, v25 >= TribeTacticalAIModule::attackLimiterTime(v9, 48)) )
  {
    attackPoint.x = (signed __int64)v11->world_x;
    v26 = v9->md;
    attackPoint.y = (signed __int64)v11->world_y;
    if ( TribeInformationAIModule::isBoat(v11) == 1 )
    {
      v27 = (char *)v9->sn[20];
      *(float *)&v124 = COERCE_FLOAT(&attackPoint);
      v123 = v27;
    }
    else
    {
      v28 = TribeTacticalAIModule::readyAndIdleGroup(v9, 100, v9->sn[20], &attackPoint);
      if ( v28 )
      {
LABEL_49:
        v30 = TacticalAIGroup::commander(v28);
        v31 = RGE_Game_World::object(v9->md->player->world, v30);
        if ( v31 )
        {
          v32 = v11->world_y;
          point.x = (signed __int64)v11->world_x;
          v33 = (signed __int64)v32;
          v34 = v11->world_z;
          point.y = v33;
          HIDWORD(v33) = v11->id;
          *(float *)&v124 = -6.8056469e38/*NaN*/;
          v123 = (char *)-1;
          point.z = (signed __int64)v34;
          ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, signed int, signed int, signed int))v31->vfptr->weaponRange)(
            v31,
            HIDWORD(v33),
            0,
            1,
            -1,
            -1);
          *(float *)&v124 = v34;
          v121 = v135;
          v122 = (int)retaddr;
          v123 = (char *)callerID;
          if ( (*(int (__thiscall **)(RGE_Static_Object *, int, void *, int, XYPoint *))(a9 + 408))(
                 v31,
                 v135,
                 retaddr,
                 callerID,
                 v124) == 1 )
          {
            TacticalAIGroup::setTarget(v28, p1);
            TacticalAIGroup::setTargetType(v28, v11->master_obj->id);
            TacticalAIGroup::setTargetLocation(v28, v11->world_x, v11->world_y, v11->world_z);
            TacticalAIGroup::setAction(v28, 2);
            TacticalAIGroup::task(v28, v9, v9->md, 2, 1, 0);
            v35 = v9->md;
            v9->lastAttackResponseTime = v35->player->world->world_time;
            if ( v9->sn[71] == 1 )
              v9->lastGroupAttackTime = v35->player->world->world_time;
            return;
          }
        }
LABEL_53:
        *(float *)&v124 = -6.8056469e38/*NaN*/;
        v123 = (char *)-1;
        v36 = MainDecisionAIModule::object(
                (MainDecisionAIModule *)&v9->md->vfptr,
                -1,
                109,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1);
        LODWORD(v37) = 1000;
        targetObj = v36;
        if ( v36 )
        {
          v38 = v36->world_x - v11->world_x;
          v39 = v36->world_y - v11->world_y;
          *(float *)&attackedUnitc = v38;
          v37 = (signed __int64)sqrt(v38 * *(float *)&attackedUnitc + v39 * v39);
        }
        if ( (signed int)v37 >= 20 )
        {
          v55 = v9->md;
          v56 = TribeInformationAIModule::isBoat(v11);
          *(float *)&v124 = -6.8056469e38/*NaN*/;
          if ( v56 == 1 )
          {
            v57 = TribeTacticalAIModule::numberWarshipsWithPriority(v9, v9->sn[20], (int)v124);
          }
          else
          {
            v58 = TribeTacticalAIModule::numberWarshipsWithPriority(v9, v9->sn[20], (int)v124);
            v57 = TribeTacticalAIModule::numberSoldiersWithPriority(v9, v9->sn[20], -1, 0) + v58;
          }
          numberToRespond = v57 * v9->sn[19] / 100;
          if ( v36 )
          {
            v59 = v36->world_x;
            v124 = (XYPoint *)(signed __int64)v36->world_y;
            v60 = v11->owner;
            v123 = (char *)(signed __int64)v59;
            v122 = v60->id;
LABEL_90:
            TribeTacticalAIModule::checkForCoopAttack(v9, v122, (int)v123, (int)v124);
            mTypec = 0;
            attackedUnita = 0;
            if ( v9->workingArea.numberValue <= 0 )
              return;
            v61 = 0;
            while ( 1 )
            {
              if ( mTypec >= numberToRespond )
                return;
              if ( v61 > 1 )
              {
                v124 = (XYPoint *)6740;
                v123 = aCMsdevWorkA_61;
                if ( debug_timeGetTime() - entryTime > 0xA )
                  return;
              }
              if ( v61 > v9->workingArea.maximumSizeValue - 1 )
              {
                v62 = (int)&attackedUnita->vfptr + 1;
                v63 = (int *)operator new(4 * (_DWORD)attackedUnita + 4);
                if ( v63 )
                {
                  for ( m = 0; m < v9->workingArea.maximumSizeValue; v63[m - 1] = v9->workingArea.value[m - 1] )
                  {
                    if ( m >= v62 )
                      break;
                    ++m;
                  }
                  operator delete(v9->workingArea.value);
                  v9->workingArea.value = v63;
                  v9->workingArea.maximumSizeValue = v62;
                }
                v61 = (int)attackedUnita;
              }
              v65 = RGE_Game_World::object(v9->md->aiPlayer->world, v9->workingArea.value[v61]);
              v66 = v65;
              if ( v65 )
              {
                if ( RGE_Static_Object::unitAI(v65) )
                  break;
              }
LABEL_148:
              v61 = (int)&attackedUnita->vfptr + 1;
              attackedUnita = (RGE_Static_Object *)((char *)attackedUnita + 1);
              if ( (signed int)attackedUnita >= v9->workingArea.numberValue )
                return;
            }
            v67 = RGE_Static_Object::unitAI(v66);
            if ( UnitAIModule::currentAction(v67) == 600 )
            {
              v68 = RGE_Static_Object::unitAI(v66);
              if ( UnitAIModule::currentTarget(v68) != -1 )
              {
                v69 = RGE_Static_Object::unitAI(v66);
                if ( UnitAIModule::currentTarget(v69) == v11->id )
                {
LABEL_147:
                  ++mTypec;
                  goto LABEL_148;
                }
                v70 = RGE_Static_Object::unitAI(v66);
                v71 = UnitAIModule::currentTarget(v70);
                v72 = v9->md;
                v124 = (XYPoint *)v71;
                *(float *)&targetObj = COERCE_FLOAT(RGE_Game_World::object(v72->player->world, v71));
                if ( *(float *)&targetObj != 0.0 )
                {
                  if ( v9->playersToAttack.maximumSizeValue - 1 < 0 )
                  {
                    v73 = (int *)operator new(4u);
                    if ( v73 )
                    {
                      for ( n = 0; n < v9->playersToAttack.maximumSizeValue; v73[n - 1] = v9->playersToAttack.value[n - 1] )
                      {
                        if ( n >= 1 )
                          break;
                        ++n;
                      }
                      operator delete(v9->playersToAttack.value);
                      v9->playersToAttack.value = v73;
                      v9->playersToAttack.maximumSizeValue = 1;
                    }
                  }
                  if ( targetObj->owner->id == *v9->playersToAttack.value )
                    goto LABEL_148;
                  v61 = (int)attackedUnita;
                }
              }
            }
            if ( v61 > v9->workingArea.maximumSizeValue - 1 )
            {
              v75 = (int *)operator new(4 * (_DWORD)attackedUnita + 4);
              if ( v75 )
              {
                for ( ii = 0; ii < v9->workingArea.maximumSizeValue; v75[ii - 1] = v9->workingArea.value[ii - 1] )
                {
                  if ( ii >= (signed int)&attackedUnita->vfptr + 1 )
                    break;
                  ++ii;
                }
                operator delete(v9->workingArea.value);
                v9->workingArea.value = v75;
                v9->workingArea.maximumSizeValue = (int)&attackedUnita->vfptr + 1;
              }
            }
            if ( v9->workingArea.value[(_DWORD)attackedUnita] == callerID )
            {
              v77 = RGE_Static_Object::unitAI(v66);
              if ( UnitAIModule::currentOrderPriority(v77) == 100 )
                goto LABEL_148;
              v78 = v11->world_y;
              point.x = (signed __int64)v11->world_x;
              v79 = (signed __int64)v78;
              v80 = v11->world_z;
              point.y = v79;
              HIDWORD(v79) = v11->id;
              v81 = v66->vfptr;
              *(float *)&v124 = -6.8056469e38/*NaN*/;
              v123 = (char *)-1;
              v122 = 1;
              v121 = 0;
              point.z = (signed __int64)v80;
              ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, signed int, signed int, signed int))v81->weaponRange)(
                v66,
                HIDWORD(v79),
                0,
                1,
                -1,
                -1);
              *(float *)&v124 = v80;
              v121 = v135;
              v122 = (int)retaddr;
              v123 = (char *)callerID;
              if ( !((int (__thiscall *)(RGE_Static_Object *, int, void *, int, XYPoint *))v81->canPath)(
                      v66,
                      v135,
                      retaddr,
                      callerID,
                      v124) )
                goto LABEL_148;
              v82 = attackedUnita;
              if ( (signed int)attackedUnita > v9->workingArea.maximumSizeValue - 1 )
              {
                v83 = (int)&attackedUnita->vfptr + 1;
                v84 = (int *)operator new(4 * (_DWORD)attackedUnita + 4);
                if ( v84 )
                {
                  for ( jj = 0; jj < v9->workingArea.maximumSizeValue; v84[jj - 1] = v9->workingArea.value[jj - 1] )
                  {
                    if ( jj >= v83 )
                      break;
                    ++jj;
                  }
                  operator delete(v9->workingArea.value);
                  v9->workingArea.value = v84;
                  v9->workingArea.maximumSizeValue = v83;
                }
                v82 = attackedUnita;
              }
              v86 = v11->owner;
              *(float *)&v124 = 0.0;
              v123 = (char *)-1;
              v122 = 0;
              v87 = v86->id;
              v88 = v11->id;
              v121 = 0;
              if ( TribeTacticalAIModule::taskAttacker(
                     v9,
                     v9->workingArea.value[(_DWORD)v82],
                     v11->world_x,
                     v11->world_y,
                     v88,
                     v87,
                     0,
                     0,
                     -1,
                     0) != 1 )
                goto LABEL_148;
              v89 = v9->md;
              v9->lastAttackResponseTime = v89->player->world->world_time;
              if ( v9->sn[71] == 1 )
                v9->lastGroupAttackTime = v89->player->world->world_time;
            }
            else
            {
              *(float *)&targetObj = RGE_Static_Object::distance_to_object(callerObject, v66);
              v90 = TribeTacticalAIModule::calculatePriority(v9, *(float *)&targetObj);
              if ( (double)v9->sn[20] <= *(float *)&targetObj )
                goto LABEL_148;
              v91 = RGE_Static_Object::unitAI(v66);
              if ( UnitAIModule::currentOrderPriority(v91) >= v90 )
                goto LABEL_148;
              if ( v90 <= 0 )
                goto LABEL_148;
              v92 = v11->world_y;
              v133 = (signed __int64)v11->world_x;
              v93 = (signed __int64)v92;
              v94 = v11->world_z;
              v134 = v93;
              v95 = (signed __int64)v94;
              v96 = v66->vfptr;
              *(float *)&v124 = -6.8056469e38/*NaN*/;
              v135 = (signed __int64)v94;
              LODWORD(v95) = v11->id;
              v123 = (char *)-1;
              v122 = 1;
              v121 = 0;
              ((void (__fastcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int))v96->weaponRange)(
                v66,
                HIDWORD(v95),
                v95,
                0,
                1,
                -1,
                -1);
              *(float *)&v124 = v94;
              v121 = recipientID;
              v122 = mTypec;
              v123 = (char *)attackedUnita;
              if ( !((int (__thiscall *)(RGE_Static_Object *, int, int, RGE_Static_Object *, XYPoint *))v96->canPath)(
                      v66,
                      recipientID,
                      mTypec,
                      attackedUnita,
                      v124) )
                goto LABEL_148;
              v97 = attackedUnita;
              if ( (signed int)attackedUnita > v9->workingArea.maximumSizeValue - 1 )
              {
                v98 = (int)&attackedUnita->vfptr + 1;
                v99 = (int *)operator new(4 * (_DWORD)attackedUnita + 4);
                if ( v99 )
                {
                  for ( kk = 0; kk < v9->workingArea.maximumSizeValue; v99[kk - 1] = v9->workingArea.value[kk - 1] )
                  {
                    if ( kk >= v98 )
                      break;
                    ++kk;
                  }
                  operator delete(v9->workingArea.value);
                  v9->workingArea.value = v99;
                  v9->workingArea.maximumSizeValue = v98;
                }
                v97 = attackedUnita;
              }
              v101 = v11->owner;
              *(float *)&v124 = 0.0;
              v123 = (char *)-1;
              v122 = 0;
              v102 = v101->id;
              v103 = v11->id;
              v121 = 0;
              if ( TribeTacticalAIModule::taskAttacker(
                     v9,
                     v9->workingArea.value[(_DWORD)v97],
                     v11->world_x,
                     v11->world_y,
                     v103,
                     v102,
                     0,
                     0,
                     -1,
                     0) != 1 )
                goto LABEL_148;
            }
            goto LABEL_147;
          }
          v54 = v11->world_x;
          v124 = (XYPoint *)(signed __int64)v11->world_y;
        }
        else
        {
          v40 = TribeTacticalAIModule::numberWarshipsWithPriority(v9, 100, -1);
          v41 = TribeTacticalAIModule::numberSoldiersWithPriority(v9, 100, -1, 0);
          v42 = v9->md;
          v43 = v41 + v40;
          numberToRespond = v43;
          v44 = v42->player->world->world_time / 0x3E8;
          if ( !v43 && !TribeInformationAIModule::isBoat(v11) && v9->sn[225] == 1 && v44 < v9->sn[104] )
          {
            attackedUnit = 0;
            if ( v9->civilians.numberValue > 0 )
            {
              do
              {
                if ( v43 > v9->civilians.maximumSizeValue - 1 )
                {
                  v45 = v43 + 1;
                  v46 = (int *)operator new(4 * v43 + 4);
                  if ( v46 )
                  {
                    for ( ll = 0; ll < v9->civilians.maximumSizeValue; v46[ll - 1] = v9->civilians.value[ll - 1] )
                    {
                      if ( ll >= v45 )
                        break;
                      ++ll;
                    }
                    operator delete(v9->civilians.value);
                    v9->civilians.value = v46;
                    v9->civilians.maximumSizeValue = v45;
                  }
                  v43 = (int)attackedUnit;
                }
                v48 = v9->workingArea.numberValue;
                v49 = v9->civilians.value[v43];
                v50 = 0;
                for ( mTypeb = v9->civilians.value[v43]; v50 < v48; ++v50 )
                {
                  if ( v50 >= v9->workingArea.maximumSizeValue )
                    break;
                  if ( v9->workingArea.value[v50] == v49 )
                    goto LABEL_80;
                }
                if ( v48 > v9->workingArea.maximumSizeValue - 1 )
                {
                  v51 = v48 + 1;
                  v52 = (int *)operator new(4 * (v48 + 1));
                  if ( v52 )
                  {
                    for ( mm = 0; mm < v9->workingArea.maximumSizeValue; v52[mm - 1] = v9->workingArea.value[mm - 1] )
                    {
                      if ( mm >= v51 )
                        break;
                      ++mm;
                    }
                    operator delete(v9->workingArea.value);
                    v9->workingArea.value = v52;
                    v9->workingArea.maximumSizeValue = v51;
                  }
                  v49 = mTypeb;
                  v43 = (int)attackedUnit;
                }
                v9->workingArea.value[v9->workingArea.numberValue++] = v49;
LABEL_80:
                attackedUnit = (RGE_Static_Object *)++v43;
              }
              while ( v43 < v9->civilians.numberValue );
            }
            numberToRespond = v9->civilians.numberValue;
          }
          v54 = targetObj->world_x;
          v124 = (XYPoint *)(signed __int64)targetObj->world_y;
        }
        v123 = (char *)(signed __int64)v54;
        v122 = v11->owner->id;
        goto LABEL_90;
      }
      v29 = (char *)v9->sn[20];
      *(float *)&v124 = COERCE_FLOAT(&attackPoint);
      v123 = v29;
    }
    v28 = TribeTacticalAIModule::readyAndIdleGroup(v9, 103, (int)v123, v124);
    if ( !v28 )
      goto LABEL_53;
    goto LABEL_49;
  }
}

//----- (004F7350) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberIdleSoldiers(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  RGE_Static_Object *v6; // eax@8
  RGE_Static_Object *v7; // edi@8
  UnitAIModule *v8; // eax@10
  int v9; // ebx@12
  int *v10; // edi@12
  int k; // eax@13
  int v12; // eax@17
  int v13; // ebp@17
  int v14; // ecx@17
  int v15; // ebx@22
  int *v16; // edi@22
  int l; // eax@23
  int count; // [sp+8h] [bp-Ch]@1
  int v20; // [sp+Ch] [bp-8h]@8
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  count = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->soldiers.numberValue; i = v2 )
  {
    if ( v2 > v1->soldiers.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->soldiers.maximumSizeValue; v4[j - 1] = v1->soldiers.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->soldiers.value);
        v1->soldiers.value = v4;
        v1->soldiers.maximumSizeValue = v3;
      }
    }
    v20 = v2;
    v6 = RGE_Game_World::object(v1->md->aiPlayer->world, v1->soldiers.value[v2]);
    v7 = v6;
    if ( v6 )
    {
      if ( RGE_Static_Object::unitAI(v6) )
      {
        v8 = RGE_Static_Object::unitAI(v7);
        if ( UnitAIModule::currentAction(v8) == -1 )
        {
          if ( v2 > v1->soldiers.maximumSizeValue - 1 )
          {
            v9 = v2 + 1;
            v10 = (int *)operator new(v20 * 4 + 4);
            if ( v10 )
            {
              for ( k = 0; k < v1->soldiers.maximumSizeValue; v10[k - 1] = v1->soldiers.value[k - 1] )
              {
                if ( k >= v9 )
                  break;
                ++k;
              }
              operator delete(v1->soldiers.value);
              v1->soldiers.value = v10;
              v1->soldiers.maximumSizeValue = v9;
            }
          }
          v12 = 0;
          v13 = v1->soldiers.value[v20];
          v14 = v1->workingArea.numberValue;
          if ( v14 > 0 )
          {
            do
            {
              if ( v12 >= v1->workingArea.maximumSizeValue )
                break;
              if ( v1->workingArea.value[v12] == v13 )
                goto LABEL_28;
              ++v12;
            }
            while ( v12 < v14 );
          }
          if ( v14 > v1->workingArea.maximumSizeValue - 1 )
          {
            v15 = v14 + 1;
            v16 = (int *)operator new(4 * (v14 + 1));
            if ( v16 )
            {
              for ( l = 0; l < v1->workingArea.maximumSizeValue; v16[l - 1] = v1->workingArea.value[l - 1] )
              {
                if ( l >= v15 )
                  break;
                ++l;
              }
              operator delete(v1->workingArea.value);
              v1->workingArea.value = v16;
              v1->workingArea.maximumSizeValue = v15;
            }
          }
          v1->workingArea.value[v1->workingArea.numberValue++] = v13;
LABEL_28:
          v2 = i;
          ++count;
        }
      }
    }
    ++v2;
  }
  return count;
}

//----- (004F7590) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberSoldiersWithPriority(TribeTacticalAIModule *this, int priority, int flag, int zeroWorkingArea)
{
  TribeTacticalAIModule *v4; // ebx@1
  int v5; // edi@1
  ManagedArray<int> *v6; // esi@4
  int v7; // ebp@8
  RGE_Static_Object *v8; // eax@8
  RGE_Static_Object *v9; // edi@8
  int v10; // ecx@12
  int i; // eax@12
  UnitAIModule *v12; // eax@17
  UnitAIModule *v13; // eax@18
  int v14; // ecx@21
  int v15; // ebx@21
  ManagedArray<int> *v16; // edi@21
  int k; // eax@21
  UnitAIModule *v18; // eax@27
  UnitAIModule *v19; // eax@28
  int v20; // eax@31
  UnitAIModule *v22; // eax@42
  UnitAIModule *v23; // eax@43
  int v24; // ebx@45
  int *v25; // edi@45
  int j; // eax@46
  int v27; // eax@52
  TribeTacticalAIModule *v28; // [sp+10h] [bp-Ch]@1
  int count; // [sp+14h] [bp-8h]@1
  int r; // [sp+18h] [bp-4h]@51
  int zeroWorkingAreaa; // [sp+28h] [bp+Ch]@3

  v4 = this;
  v5 = 0;
  v28 = this;
  count = 0;
  if ( zeroWorkingArea == 1 )
    this->workingArea.numberValue = 0;
  zeroWorkingAreaa = 0;
  if ( this->soldiers.numberValue > 0 )
  {
    v6 = &this->soldiers;
    while ( 1 )
    {
      if ( v5 > v6->maximumSizeValue - 1 )
        ManagedArray<int>::resize(v6, v5 + 1);
      v7 = v5;
      v8 = RGE_Game_World::object(v4->md->aiPlayer->world, v6->value[v5]);
      v9 = v8;
      if ( v8 && RGE_Static_Object::unitAI(v8) )
      {
        if ( zeroWorkingAreaa > v6->maximumSizeValue - 1 )
          ManagedArray<int>::resize(v6, zeroWorkingAreaa + 1);
        v10 = v4->unitsTaskedThisUpdate.numberValue;
        for ( i = 0; i < v10; ++i )
        {
          if ( i >= v4->unitsTaskedThisUpdate.maximumSizeValue )
            break;
          if ( v4->unitsTaskedThisUpdate.value[i] == v6->value[v7] )
            goto LABEL_39;
          v4 = v28;
        }
        if ( flag >= 0 )
        {
          if ( flag <= 0 )
          {
            v22 = RGE_Static_Object::unitAI(v9);
            if ( UnitAIModule::currentAction(v22) != -1 )
            {
              v23 = RGE_Static_Object::unitAI(v9);
              if ( UnitAIModule::currentOrderPriority(v23) == priority )
              {
                if ( zeroWorkingAreaa > v6->maximumSizeValue - 1 )
                {
                  v24 = zeroWorkingAreaa + 1;
                  v25 = (int *)operator new(v7 * 4 + 4);
                  if ( v25 )
                  {
                    for ( j = 0; j < v6->maximumSizeValue; v25[j - 1] = v6->value[j - 1] )
                    {
                      if ( j >= v24 )
                        break;
                      ++j;
                    }
                    operator delete(v6->value);
                    v6->value = v25;
                    v6->maximumSizeValue = v24;
                  }
                  v4 = v28;
                }
                r = v6->value[v7];
                if ( ManagedArray<int>::contains(&v4->workingArea, &r) != 1 )
                {
                  v27 = v4->workingArea.numberValue;
                  if ( v27 > v4->workingArea.maximumSizeValue - 1 )
                    ManagedArray<int>::resize(&v4->workingArea, v27 + 1);
                  v4->workingArea.value[v4->workingArea.numberValue++] = r;
                }
                ++count;
              }
            }
            goto LABEL_40;
          }
          v18 = RGE_Static_Object::unitAI(v9);
          if ( UnitAIModule::currentAction(v18) == -1 )
            goto LABEL_40;
          v19 = RGE_Static_Object::unitAI(v9);
          if ( UnitAIModule::currentOrderPriority(v19) <= priority )
            goto LABEL_40;
          if ( zeroWorkingAreaa > v6->maximumSizeValue - 1 )
            ManagedArray<int>::resize(v6, zeroWorkingAreaa + 1);
          v15 = v6->value[v7];
          v16 = &v28->workingArea;
          v20 = 0;
          v14 = v28->workingArea.numberValue;
          if ( v14 > 0 )
          {
            do
            {
              if ( v20 >= v28->workingArea.maximumSizeValue )
                break;
              if ( v16->value[v20] == v15 )
                goto LABEL_38;
              ++v20;
            }
            while ( v20 < v14 );
          }
        }
        else
        {
          v12 = RGE_Static_Object::unitAI(v9);
          if ( UnitAIModule::currentAction(v12) != -1 )
          {
            v13 = RGE_Static_Object::unitAI(v9);
            if ( UnitAIModule::currentOrderPriority(v13) >= priority )
              goto LABEL_40;
          }
          if ( zeroWorkingAreaa > v6->maximumSizeValue - 1 )
            ManagedArray<int>::resize(v6, zeroWorkingAreaa + 1);
          v14 = v28->workingArea.numberValue;
          v15 = v6->value[v7];
          v16 = &v28->workingArea;
          for ( k = 0; k < v14; ++k )
          {
            if ( k >= v28->workingArea.maximumSizeValue )
              break;
            if ( v16->value[k] == v15 )
              goto LABEL_38;
          }
        }
        if ( v14 > v16->maximumSizeValue - 1 )
          ManagedArray<int>::resize(v16, v14 + 1);
        v16->value[v16->numberValue++] = v15;
LABEL_38:
        ++count;
LABEL_39:
        v4 = v28;
      }
LABEL_40:
      if ( ++zeroWorkingAreaa >= v4->soldiers.numberValue )
        return count;
      v5 = zeroWorkingAreaa;
    }
  }
  return count;
}

//----- (004F7870) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberWarshipsWithPriority(TribeTacticalAIModule *this, int priority, int flag)
{
  TribeTacticalAIModule *v3; // ebp@1
  int v4; // ebx@1
  int v5; // eax@1
  char *v6; // esi@2
  int v7; // edx@5
  TribeMainDecisionAIModule *v8; // ecx@5
  RGE_Static_Object *v9; // eax@5
  RGE_Static_Object *v10; // edi@5
  int v11; // eax@9
  UnitAIModule *v12; // eax@14
  UnitAIModule *v13; // eax@15
  int v14; // edi@18
  int v15; // eax@19
  int v16; // edx@21
  int v17; // eax@21
  int v18; // ecx@21
  UnitAIModule *v19; // eax@23
  UnitAIModule *v20; // eax@24
  int v21; // eax@28
  UnitAIModule *v22; // eax@31
  UnitAIModule *v23; // eax@32
  int v24; // eax@36
  int v25; // esi@44
  ManagedArray<int> *v26; // edi@45
  int v27; // ebx@49
  RGE_Static_Object *v28; // eax@49
  RGE_Static_Object *v29; // esi@49
  int v30; // ecx@53
  int v31; // eax@53
  __int16 v32; // ax@57
  UnitAIModule *v33; // eax@60
  UnitAIModule *v34; // eax@61
  int v35; // ecx@64
  ManagedArray<int> *v36; // esi@64
  int v37; // eax@64
  int j; // ebx@64
  UnitAIModule *v39; // eax@70
  UnitAIModule *v40; // eax@71
  int v41; // eax@74
  UnitAIModule *v42; // eax@81
  UnitAIModule *v43; // eax@82
  int v44; // eax@86
  int count; // [sp+10h] [bp-10h]@1
  int i; // [sp+14h] [bp-Ch]@1
  int ia; // [sp+14h] [bp-Ch]@44
  int r; // [sp+18h] [bp-8h]@5
  TribeTacticalAIModule *v50; // [sp+1Ch] [bp-4h]@1

  v3 = this;
  v4 = 0;
  this->workingArea.numberValue = 0;
  v5 = this->warBoats.numberValue;
  v50 = this;
  count = 0;
  i = 0;
  if ( v5 > 0 )
  {
    v6 = (char *)&this->warBoats;
    while ( 1 )
    {
      if ( v4 > v3->warBoats.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->warBoats, v4 + 1);
      v7 = *(_DWORD *)v6;
      v8 = v3->md;
      r = 4 * v4;
      v9 = RGE_Game_World::object(v8->aiPlayer->world, *(_DWORD *)(v7 + 4 * v4));
      v10 = v9;
      if ( !v9 || !RGE_Static_Object::unitAI(v9) )
        goto LABEL_43;
      if ( v4 > v3->warBoats.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->warBoats, v4 + 1);
      v11 = 0;
      if ( v3->unitsTaskedThisUpdate.numberValue > 0 )
      {
        while ( v11 < v3->unitsTaskedThisUpdate.maximumSizeValue )
        {
          if ( v3->unitsTaskedThisUpdate.value[v11] == *(_DWORD *)(*(_DWORD *)v6 + r) )
          {
            v4 = i;
            goto LABEL_43;
          }
          v4 = i;
          if ( ++v11 >= v3->unitsTaskedThisUpdate.numberValue )
            break;
        }
      }
      if ( flag >= 0 )
        break;
      v12 = RGE_Static_Object::unitAI(v10);
      if ( UnitAIModule::currentAction(v12) != -1 )
      {
        v13 = RGE_Static_Object::unitAI(v10);
        if ( UnitAIModule::currentOrderPriority(v13) >= priority )
          goto LABEL_43;
      }
      if ( v4 > v3->warBoats.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->warBoats, v4 + 1);
      v14 = (int)&v3->workingArea;
      r = *(_DWORD *)(*(_DWORD *)v6 + r);
      if ( ManagedArray<int>::contains(&v3->workingArea, &r) != 1 )
      {
        v15 = v3->workingArea.numberValue;
        if ( v15 > v3->workingArea.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v3->workingArea, v15 + 1);
        v16 = v3->workingArea.numberValue;
        v17 = *(_DWORD *)v14;
        v18 = r;
        goto LABEL_39;
      }
LABEL_41:
      ++count;
LABEL_43:
      i = ++v4;
      if ( v4 >= v3->warBoats.numberValue )
        goto LABEL_44;
    }
    if ( flag <= 0 )
    {
      v22 = RGE_Static_Object::unitAI(v10);
      if ( UnitAIModule::currentAction(v22) == -1 )
        goto LABEL_43;
      v23 = RGE_Static_Object::unitAI(v10);
      if ( UnitAIModule::currentOrderPriority(v23) != priority )
        goto LABEL_43;
      if ( v4 > v3->warBoats.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->warBoats, v4 + 1);
      v14 = (int)&v3->workingArea;
      r = *(_DWORD *)(*(_DWORD *)v6 + r);
      if ( ManagedArray<int>::contains(&v3->workingArea, &r) == 1 )
        goto LABEL_41;
      v24 = v3->workingArea.numberValue;
      if ( v24 > v3->workingArea.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->workingArea, v24 + 1);
      v16 = v3->workingArea.numberValue;
      v17 = *(_DWORD *)v14;
      v18 = r;
LABEL_39:
      *(_DWORD *)(v17 + 4 * v16) = v18;
    }
    else
    {
      v19 = RGE_Static_Object::unitAI(v10);
      if ( UnitAIModule::currentAction(v19) == -1 )
        goto LABEL_43;
      v20 = RGE_Static_Object::unitAI(v10);
      if ( UnitAIModule::currentOrderPriority(v20) <= priority )
        goto LABEL_43;
      if ( v4 > v3->warBoats.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->warBoats, v4 + 1);
      v14 = (int)&v3->workingArea;
      r = *(_DWORD *)(*(_DWORD *)v6 + r);
      if ( ManagedArray<int>::contains(&v3->workingArea, &r) == 1 )
        goto LABEL_41;
      v21 = v3->workingArea.numberValue;
      if ( v21 > v3->workingArea.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v3->workingArea, v21 + 1);
      *(_DWORD *)(*(_DWORD *)v14 + 4 * v3->workingArea.numberValue) = r;
    }
    ++*(_DWORD *)(v14 + 4);
    goto LABEL_41;
  }
LABEL_44:
  v25 = 0;
  ia = 0;
  if ( v3->soldiers.numberValue > 0 )
  {
    v26 = &v3->soldiers;
    while ( 1 )
    {
      if ( v25 > v26->maximumSizeValue - 1 )
        ManagedArray<int>::resize(v26, v25 + 1);
      v27 = v25;
      v28 = RGE_Game_World::object(v3->md->aiPlayer->world, v26->value[v25]);
      v29 = v28;
      if ( v28 && RGE_Static_Object::unitAI(v28) )
      {
        if ( ia > v26->maximumSizeValue - 1 )
          ManagedArray<int>::resize(v26, ia + 1);
        v30 = v3->unitsTaskedThisUpdate.numberValue;
        v31 = 0;
        if ( v30 > 0 )
        {
          while ( v31 < v3->unitsTaskedThisUpdate.maximumSizeValue )
          {
            if ( v3->unitsTaskedThisUpdate.value[v31] == v26->value[v27] )
            {
              v3 = v50;
              goto LABEL_92;
            }
            v3 = v50;
            if ( ++v31 >= v30 )
              break;
          }
        }
        v32 = v29->master_obj->object_group;
        if ( v32 == 18 || v32 == 13 )
        {
          if ( flag >= 0 )
          {
            if ( flag <= 0 )
            {
              v42 = RGE_Static_Object::unitAI(v29);
              if ( UnitAIModule::currentAction(v42) != -1 )
              {
                v43 = RGE_Static_Object::unitAI(v29);
                if ( UnitAIModule::currentOrderPriority(v43) == priority )
                {
                  if ( ia > v26->maximumSizeValue - 1 )
                    ManagedArray<int>::resize(v26, ia + 1);
                  v36 = &v3->workingArea;
                  r = v26->value[v27];
                  if ( ManagedArray<int>::contains(&v3->workingArea, &r) != 1 )
                  {
                    v44 = v3->workingArea.numberValue;
                    if ( v44 > v3->workingArea.maximumSizeValue - 1 )
                      ManagedArray<int>::resize(&v3->workingArea, v44 + 1);
                    v36->value[v3->workingArea.numberValue] = r;
LABEL_89:
                    ++v36->numberValue;
                  }
LABEL_90:
                  ++count;
                  goto LABEL_92;
                }
              }
            }
            else
            {
              v39 = RGE_Static_Object::unitAI(v29);
              if ( UnitAIModule::currentAction(v39) != -1 )
              {
                v40 = RGE_Static_Object::unitAI(v29);
                if ( UnitAIModule::currentOrderPriority(v40) > priority )
                {
                  if ( ia > v26->maximumSizeValue - 1 )
                    ManagedArray<int>::resize(v26, ia + 1);
                  v35 = v3->workingArea.numberValue;
                  v36 = &v3->workingArea;
                  v41 = 0;
                  for ( j = v26->value[v27]; v41 < v35; ++v41 )
                  {
                    if ( v41 >= v3->workingArea.maximumSizeValue )
                      break;
                    if ( v36->value[v41] == j )
                      goto LABEL_90;
                  }
                  goto LABEL_78;
                }
              }
            }
          }
          else
          {
            v33 = RGE_Static_Object::unitAI(v29);
            if ( UnitAIModule::currentAction(v33) == -1
              || (v34 = RGE_Static_Object::unitAI(v29), UnitAIModule::currentOrderPriority(v34) < priority) )
            {
              if ( ia > v26->maximumSizeValue - 1 )
                ManagedArray<int>::resize(v26, ia + 1);
              v35 = v3->workingArea.numberValue;
              v36 = &v3->workingArea;
              v37 = 0;
              for ( j = v26->value[v27]; v37 < v35; ++v37 )
              {
                if ( v37 >= v3->workingArea.maximumSizeValue )
                  break;
                if ( v36->value[v37] == j )
                  goto LABEL_90;
              }
LABEL_78:
              if ( v35 > v36->maximumSizeValue - 1 )
                ManagedArray<int>::resize(v36, v35 + 1);
              v36->value[v36->numberValue] = j;
              goto LABEL_89;
            }
          }
        }
      }
LABEL_92:
      if ( ++ia >= v3->soldiers.numberValue )
        return count;
      v25 = ia;
    }
  }
  return count;
}

//----- (004F7D90) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::idleSoldier(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebx@1
  int v3; // ebp@3
  int *v4; // edi@3
  int i; // eax@4
  RGE_Static_Object *v6; // eax@8
  RGE_Static_Object *v7; // edi@8
  UnitAIModule *v8; // eax@10
  int result; // eax@12

  v1 = this;
  v2 = 0;
  if ( this->soldiers.numberValue <= 0 )
  {
    result = -1;
  }
  else
  {
    while ( 1 )
    {
      if ( v2 > v1->soldiers.maximumSizeValue - 1 )
      {
        v3 = v2 + 1;
        v4 = (int *)operator new(4 * v2 + 4);
        if ( v4 )
        {
          for ( i = 0; i < v1->soldiers.maximumSizeValue; v4[i - 1] = v1->soldiers.value[i - 1] )
          {
            if ( i >= v3 )
              break;
            ++i;
          }
          operator delete(v1->soldiers.value);
          v1->soldiers.value = v4;
          v1->soldiers.maximumSizeValue = v3;
        }
      }
      v6 = RGE_Game_World::object(v1->md->player->world, v1->soldiers.value[v2]);
      v7 = v6;
      if ( v6 )
      {
        if ( RGE_Static_Object::unitAI(v6) )
        {
          v8 = RGE_Static_Object::unitAI(v7);
          if ( UnitAIModule::currentAction(v8) == -1 )
            break;
        }
      }
      if ( ++v2 >= v1->soldiers.numberValue )
        return -1;
    }
    result = v7->id;
  }
  return result;
}

//----- (004F7E80) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::idleCivilian(TribeTacticalAIModule *this, int checkGroup)
{
  TribeTacticalAIModule *v2; // edi@1
  int v3; // ebx@1
  char *v4; // esi@2
  int v5; // ecx@5
  int l; // eax@5
  RGE_Static_Object *v7; // eax@11
  RGE_Static_Object *v8; // ebp@11
  int m; // eax@18
  UnitAIModule *v10; // eax@22
  UnitAIModule *v11; // eax@23
  int v12; // ebx@25
  void **v13; // esi@26
  int v14; // ecx@29
  int i; // eax@29
  RGE_Static_Object *v16; // eax@35
  int v17; // ebp@45
  _DWORD *v18; // ebx@45
  int j; // eax@46
  int v20; // ecx@51
  int k; // eax@51
  UnitAIModule *v22; // eax@55
  UnitAIModule *v23; // eax@56
  RGE_Static_Object *unitObj; // [sp+10h] [bp-8h]@11
  RGE_Static_Object *unitObja; // [sp+10h] [bp-8h]@25
  RGE_Static_Object *v27; // [sp+14h] [bp-4h]@35

  v2 = this;
  v3 = 0;
  if ( this->civilians.numberValue <= 0 )
  {
LABEL_25:
    v12 = 0;
    unitObja = 0;
    if ( v2->civilians.numberValue <= 0 )
      return -1;
    v13 = (void **)&v2->civilians.value;
    while ( 1 )
    {
      if ( v12 > v2->civilians.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v2->civilians, v12 + 1);
      v14 = v2->unitsTaskedThisUpdate.numberValue;
      for ( i = 0; i < v14; ++i )
      {
        if ( i >= v2->unitsTaskedThisUpdate.maximumSizeValue )
          break;
        if ( v2->unitsTaskedThisUpdate.value[i] == *((_DWORD *)*v13 + v12) )
          goto LABEL_57;
      }
      if ( v12 > v2->civilians.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v2->civilians, v12 + 1);
      v16 = RGE_Game_World::object(v2->md->player->world, *((_DWORD *)*v13 + v12));
      v27 = v16;
      if ( v16 )
      {
        if ( RGE_Static_Object::unitAI(v16) )
        {
          if ( !checkGroup )
            goto LABEL_55;
          if ( checkGroup == 3 )
            break;
          if ( v12 > v2->civilians.maximumSizeValue - 1 )
            ManagedArray<int>::resize(&v2->civilians, v12 + 1);
          if ( !TribeTacticalAIModule::isGatherer(v2, *((_DWORD *)*v13 + v12)) )
            break;
        }
      }
LABEL_57:
      unitObja = (RGE_Static_Object *)++v12;
      if ( v12 >= v2->civilians.numberValue )
        return -1;
    }
    if ( checkGroup && checkGroup != 1 )
    {
      if ( v12 > v2->civilians.maximumSizeValue - 1 )
      {
        v17 = v12 + 1;
        v18 = operator new(4 * v12 + 4);
        if ( v18 )
        {
          for ( j = 0; j < v2->civilians.maximumSizeValue; v18[j - 1] = *((_DWORD *)*v13 + j - 1) )
          {
            if ( j >= v17 )
              break;
            ++j;
          }
          operator delete(*v13);
          *v13 = v18;
          v2->civilians.maximumSizeValue = v17;
        }
        v12 = (int)unitObja;
      }
      v20 = v2->civilianExplorers.numberValue;
      for ( k = 0; k < v20; ++k )
      {
        if ( k >= v2->civilianExplorers.maximumSizeValue )
          break;
        if ( v2->civilianExplorers.value[k] == *((_DWORD *)*v13 + v12) )
          goto LABEL_57;
      }
    }
LABEL_55:
    v8 = v27;
    v22 = RGE_Static_Object::unitAI(v27);
    if ( UnitAIModule::currentAction(v22) == -1 )
    {
      v23 = RGE_Static_Object::unitAI(v27);
      if ( UnitAIModule::currentOrder(v23) == -1 )
        return v8->id;
    }
    goto LABEL_57;
  }
  v4 = (char *)&this->civilians;
  while ( 1 )
  {
    if ( v3 > v2->civilians.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v2->civilians, v3 + 1);
    v5 = v2->unitsTaskedThisUpdate.numberValue;
    for ( l = 0; l < v5; ++l )
    {
      if ( l >= v2->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v2->unitsTaskedThisUpdate.value[l] == *(_DWORD *)(*(_DWORD *)v4 + 4 * v3) )
        goto LABEL_24;
    }
    if ( v3 > v2->civilians.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v2->civilians, v3 + 1);
    v7 = RGE_Game_World::object(v2->md->player->world, *(_DWORD *)(*(_DWORD *)v4 + 4 * v3));
    v8 = v7;
    unitObj = v7;
    if ( v7 )
    {
      if ( RGE_Static_Object::unitAI(v7) )
      {
        if ( v3 > v2->civilians.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v2->civilians, v3 + 1);
        if ( !TribeTacticalAIModule::isGatherer(v2, *(_DWORD *)(*(_DWORD *)v4 + 4 * v3)) )
        {
          if ( v3 > v2->civilians.maximumSizeValue - 1 )
            ManagedArray<int>::resize(&v2->civilians, v3 + 1);
          for ( m = 0; m < v2->civilianExplorers.numberValue; ++m )
          {
            if ( m >= v2->civilianExplorers.maximumSizeValue )
              break;
            if ( v2->civilianExplorers.value[m] == *(_DWORD *)(*(_DWORD *)v4 + 4 * v3) )
              goto LABEL_24;
            v8 = unitObj;
          }
          v10 = RGE_Static_Object::unitAI(v8);
          if ( UnitAIModule::currentAction(v10) == -1 )
          {
            v11 = RGE_Static_Object::unitAI(v8);
            if ( UnitAIModule::currentOrder(v11) == -1 )
              return v8->id;
          }
        }
      }
    }
LABEL_24:
    if ( ++v3 >= v2->civilians.numberValue )
      goto LABEL_25;
  }
}

//----- (004F81A0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::idleCivilian(TribeTacticalAIModule *this, int checkGroup, XYPoint *point, int closestToPoint)
{
  TribeTacticalAIModule *v4; // ebx@1
  int v5; // edi@1
  char *v6; // esi@2
  int v7; // ecx@5
  int m; // eax@5
  RGE_Static_Object *v9; // eax@11
  RGE_Static_Object *v10; // ebp@11
  int n; // eax@18
  UnitAIModule *v12; // eax@22
  UnitAIModule *v13; // eax@23
  int v14; // ebp@25
  void **v15; // esi@26
  int v16; // ecx@29
  int i; // eax@29
  _DWORD *v18; // edi@34
  int j; // eax@35
  RGE_Static_Object *v20; // eax@39
  RGE_Static_Object *v21; // edi@39
  int v22; // eax@41
  int v23; // ebp@44
  _DWORD *v24; // edi@44
  int k; // eax@45
  int l; // eax@56
  UnitAIModule *v27; // eax@60
  UnitAIModule *v28; // eax@61
  float y; // ST04_4@62
  float x; // ST00_4@62
  long double v31; // st7@62
  float bestUnitDistance; // [sp+1Ch] [bp-10h]@1
  RGE_Static_Object *unitObj; // [sp+20h] [bp-Ch]@11
  RGE_Static_Object *unitObja; // [sp+20h] [bp-Ch]@25
  int bestUnitID; // [sp+24h] [bp-8h]@1
  RGE_Static_Object *v37; // [sp+28h] [bp-4h]@39

  v4 = this;
  v5 = 0;
  bestUnitID = -1;
  bestUnitDistance = 0.0;
  if ( this->civilians.numberValue <= 0 )
  {
LABEL_25:
    v14 = 0;
    unitObja = 0;
    if ( v4->civilians.numberValue <= 0 )
      return bestUnitID;
    v15 = (void **)&v4->civilians.value;
    while ( 1 )
    {
      if ( v14 > v4->civilians.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v4->civilians, v14 + 1);
      v16 = v4->unitsTaskedThisUpdate.numberValue;
      for ( i = 0; i < v16; ++i )
      {
        if ( i >= v4->unitsTaskedThisUpdate.maximumSizeValue )
          break;
        if ( v4->unitsTaskedThisUpdate.value[i] == *((_DWORD *)*v15 + v14) )
          goto LABEL_69;
      }
      if ( v14 > v4->civilians.maximumSizeValue - 1 )
      {
        v18 = operator new(4 * v14 + 4);
        if ( v18 )
        {
          for ( j = 0; j < v4->civilians.maximumSizeValue; v18[j - 1] = *((_DWORD *)*v15 + j - 1) )
          {
            if ( j >= v14 + 1 )
              break;
            ++j;
          }
          operator delete(*v15);
          *v15 = v18;
          v4->civilians.maximumSizeValue = v14 + 1;
        }
      }
      v20 = RGE_Game_World::object(v4->md->player->world, *((_DWORD *)*v15 + v14));
      v21 = v20;
      v37 = v20;
      if ( !v20 || !RGE_Static_Object::unitAI(v20) )
        goto LABEL_69;
      v22 = checkGroup;
      if ( checkGroup )
      {
        if ( checkGroup != 3 )
        {
          if ( v14 > v4->civilians.maximumSizeValue - 1 )
          {
            v23 = v14 + 1;
            v24 = operator new(4 * (_DWORD)unitObja + 4);
            if ( v24 )
            {
              for ( k = 0; k < v4->civilians.maximumSizeValue; v24[k - 1] = *((_DWORD *)*v15 + k - 1) )
              {
                if ( k >= v23 )
                  break;
                ++k;
              }
              operator delete(*v15);
              *v15 = v24;
              v4->civilians.maximumSizeValue = v23;
            }
            v21 = v37;
            v14 = (int)unitObja;
          }
          if ( TribeTacticalAIModule::isGatherer(v4, *((_DWORD *)*v15 + v14)) )
            goto LABEL_69;
          v22 = checkGroup;
        }
        if ( v22 && v22 != 1 )
        {
          if ( v14 > v4->civilians.maximumSizeValue - 1 )
            ManagedArray<int>::resize(&v4->civilians, v14 + 1);
          for ( l = 0; l < v4->civilianExplorers.numberValue; ++l )
          {
            if ( l >= v4->civilianExplorers.maximumSizeValue )
              break;
            if ( v4->civilianExplorers.value[l] == *((_DWORD *)*v15 + v14) )
              goto LABEL_69;
          }
        }
      }
      v27 = RGE_Static_Object::unitAI(v21);
      if ( UnitAIModule::currentAction(v27) == -1 )
      {
        v28 = RGE_Static_Object::unitAI(v21);
        if ( UnitAIModule::currentOrder(v28) == -1 )
        {
          y = (double)point->y;
          x = (double)point->x;
          v31 = RGE_Static_Object::distance_to_position(v21, x, y, v21->world_z);
          if ( bestUnitID == -1 )
          {
            bestUnitDistance = v31;
            bestUnitID = v21->id;
          }
          else if ( closestToPoint == 1 && bestUnitDistance > v31 || !closestToPoint && bestUnitDistance < v31 )
          {
            bestUnitDistance = v31;
            bestUnitID = v21->id;
          }
        }
      }
LABEL_69:
      unitObja = (RGE_Static_Object *)++v14;
      if ( v14 >= v4->civilians.numberValue )
        return bestUnitID;
    }
  }
  v6 = (char *)&this->civilians;
  while ( 1 )
  {
    if ( v5 > v4->civilians.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v4->civilians, v5 + 1);
    v7 = v4->unitsTaskedThisUpdate.numberValue;
    for ( m = 0; m < v7; ++m )
    {
      if ( m >= v4->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v4->unitsTaskedThisUpdate.value[m] == *(_DWORD *)(*(_DWORD *)v6 + 4 * v5) )
        goto LABEL_24;
    }
    if ( v5 > v4->civilians.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v4->civilians, v5 + 1);
    v9 = RGE_Game_World::object(v4->md->player->world, *(_DWORD *)(*(_DWORD *)v6 + 4 * v5));
    v10 = v9;
    unitObj = v9;
    if ( v9 )
    {
      if ( RGE_Static_Object::unitAI(v9) )
      {
        if ( v5 > v4->civilians.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v4->civilians, v5 + 1);
        if ( !TribeTacticalAIModule::isGatherer(v4, *(_DWORD *)(*(_DWORD *)v6 + 4 * v5)) )
        {
          if ( v5 > v4->civilians.maximumSizeValue - 1 )
            ManagedArray<int>::resize(&v4->civilians, v5 + 1);
          for ( n = 0; n < v4->civilianExplorers.numberValue; ++n )
          {
            if ( n >= v4->civilianExplorers.maximumSizeValue )
              break;
            if ( v4->civilianExplorers.value[n] == *(_DWORD *)(*(_DWORD *)v6 + 4 * v5) )
              goto LABEL_24;
            v10 = unitObj;
          }
          v12 = RGE_Static_Object::unitAI(v10);
          if ( UnitAIModule::currentAction(v12) == -1 )
          {
            v13 = RGE_Static_Object::unitAI(v10);
            if ( UnitAIModule::currentOrder(v13) == -1 )
              return v10->id;
          }
        }
      }
    }
LABEL_24:
    if ( ++v5 >= v4->civilians.numberValue )
      goto LABEL_25;
  }
}

//----- (004F8570) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::civilian(TribeTacticalAIModule *this, XYPoint *point, int closestToPoint, int a1, int a2, int a3, int useFarmers)
{
  TribeTacticalAIModule *v7; // esi@1
  int v8; // ebp@1
  int v9; // ebx@3
  int *v10; // edi@3
  int i; // eax@4
  int v12; // ecx@8
  int j; // eax@8
  int v14; // ebx@13
  int *v15; // edi@13
  int k; // eax@14
  RGE_Static_Object *v17; // eax@18
  RGE_Static_Object *v18; // edi@18
  UnitAIModule *v19; // eax@22
  UnitAIModule *v20; // eax@23
  UnitAIModule *v21; // eax@24
  float y; // ST04_4@25
  float x; // ST00_4@25
  long double v24; // st7@25
  float bestUnitDistance; // [sp+1Ch] [bp-8h]@1
  int bestUnitID; // [sp+20h] [bp-4h]@1

  v7 = this;
  v8 = 0;
  bestUnitID = -1;
  for ( bestUnitDistance = 0.0; v8 < v7->civilians.numberValue; ++v8 )
  {
    if ( v8 > v7->civilians.maximumSizeValue - 1 )
    {
      v9 = v8 + 1;
      v10 = (int *)operator new(4 * v8 + 4);
      if ( v10 )
      {
        for ( i = 0; i < v7->civilians.maximumSizeValue; v10[i - 1] = v7->civilians.value[i - 1] )
        {
          if ( i >= v9 )
            break;
          ++i;
        }
        operator delete(v7->civilians.value);
        v7->civilians.value = v10;
        v7->civilians.maximumSizeValue = v9;
      }
    }
    v12 = v7->unitsTaskedThisUpdate.numberValue;
    for ( j = 0; j < v12; ++j )
    {
      if ( j >= v7->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v7->unitsTaskedThisUpdate.value[j] == v7->civilians.value[v8] )
        goto LABEL_32;
    }
    if ( v8 > v7->civilians.maximumSizeValue - 1 )
    {
      v14 = v8 + 1;
      v15 = (int *)operator new(4 * v8 + 4);
      if ( v15 )
      {
        for ( k = 0; k < v7->civilians.maximumSizeValue; v15[k - 1] = v7->civilians.value[k - 1] )
        {
          if ( k >= v14 )
            break;
          ++k;
        }
        operator delete(v7->civilians.value);
        v7->civilians.value = v15;
        v7->civilians.maximumSizeValue = v14;
      }
    }
    v17 = RGE_Game_World::object(v7->md->player->world, v7->civilians.value[v8]);
    v18 = v17;
    if ( v17 && RGE_Static_Object::unitAI(v17) && (useFarmers || v18->master_obj->id != 259) )
    {
      v19 = RGE_Static_Object::unitAI(v18);
      if ( UnitAIModule::currentOrder(v19) != a1 )
      {
        v20 = RGE_Static_Object::unitAI(v18);
        if ( UnitAIModule::currentOrder(v20) != a2 )
        {
          v21 = RGE_Static_Object::unitAI(v18);
          if ( UnitAIModule::currentOrder(v21) != a3 )
          {
            y = (double)point->y;
            x = (double)point->x;
            v24 = RGE_Static_Object::distance_to_position(v18, x, y, v18->world_z);
            if ( bestUnitID == -1 )
            {
              bestUnitDistance = v24;
              bestUnitID = v18->id;
            }
            else if ( closestToPoint == 1 && bestUnitDistance > v24 || !closestToPoint && bestUnitDistance < v24 )
            {
              bestUnitDistance = v24;
              bestUnitID = v18->id;
            }
          }
        }
      }
    }
LABEL_32:
    ;
  }
  return bestUnitID;
}

//----- (004F87B0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::unit(TribeTacticalAIModule *this, int action, int target, int targetType)
{
  TribeTacticalAIModule *v4; // esi@1
  int v5; // ebp@1
  void **v6; // edi@2
  _DWORD *v7; // ebx@4
  int m; // eax@5
  UnitAIModule *v9; // eax@12
  UnitAIModule *v10; // eax@14
  UnitAIModule *v11; // eax@16
  int v12; // ebp@18
  int v13; // ebx@20
  int *v14; // edi@20
  int k; // eax@21
  UnitAIModule *v16; // eax@28
  UnitAIModule *v17; // eax@30
  UnitAIModule *v18; // eax@32
  int v19; // ebx@36
  int *v20; // edi@36
  int l; // eax@37
  int result; // eax@41
  int v23; // ebp@42
  int v24; // ebx@44
  int *v25; // edi@44
  int i; // eax@45
  UnitAIModule *v27; // eax@52
  UnitAIModule *v28; // eax@54
  UnitAIModule *v29; // eax@56
  int v30; // ebx@60
  int *v31; // edi@60
  int j; // eax@61

  v4 = this;
  v5 = 0;
  if ( this->civilians.numberValue <= 0 )
  {
LABEL_18:
    v12 = 0;
    if ( v4->soldiers.numberValue <= 0 )
    {
LABEL_42:
      v23 = 0;
      if ( v4->boats.numberValue <= 0 )
      {
        result = -1;
      }
      else
      {
        while ( 1 )
        {
          if ( v23 > v4->boats.maximumSizeValue - 1 )
          {
            v24 = v23 + 1;
            v25 = (int *)operator new(4 * v23 + 4);
            if ( v25 )
            {
              for ( i = 0; i < v4->boats.maximumSizeValue; v25[i - 1] = v4->boats.value[i - 1] )
              {
                if ( i >= v24 )
                  break;
                ++i;
              }
              operator delete(v4->boats.value);
              v4->boats.value = v25;
              v4->boats.maximumSizeValue = v24;
            }
          }
          if ( !RGE_Game_World::object(v4->md->aiPlayer->world, v4->boats.value[v23]) && !RGE_Static_Object::unitAI(0) )
          {
            if ( action == -1 || (v27 = RGE_Static_Object::unitAI(0), UnitAIModule::currentAction(v27) == action) )
            {
              if ( target == -1 || (v28 = RGE_Static_Object::unitAI(0), UnitAIModule::currentTarget(v28) == target) )
              {
                if ( targetType == -1 )
                  break;
                v29 = RGE_Static_Object::unitAI(0);
                if ( UnitAIModule::currentTargetType(v29) == targetType )
                  break;
              }
            }
          }
          if ( ++v23 >= v4->boats.numberValue )
            return -1;
        }
        if ( v23 > v4->boats.maximumSizeValue - 1 )
        {
          v30 = v23 + 1;
          v31 = (int *)operator new(4 * (v23 + 1));
          if ( v31 )
          {
            for ( j = 0; j < v4->boats.maximumSizeValue; v31[j - 1] = v4->boats.value[j - 1] )
            {
              if ( j >= v30 )
                break;
              ++j;
            }
            operator delete(v4->boats.value);
            v4->boats.value = v31;
            v4->boats.maximumSizeValue = v30;
          }
        }
        result = v4->boats.value[v23];
      }
    }
    else
    {
      while ( 1 )
      {
        if ( v12 > v4->soldiers.maximumSizeValue - 1 )
        {
          v13 = v12 + 1;
          v14 = (int *)operator new(4 * v12 + 4);
          if ( v14 )
          {
            for ( k = 0; k < v4->soldiers.maximumSizeValue; v14[k - 1] = v4->soldiers.value[k - 1] )
            {
              if ( k >= v13 )
                break;
              ++k;
            }
            operator delete(v4->soldiers.value);
            v4->soldiers.value = v14;
            v4->soldiers.maximumSizeValue = v13;
          }
        }
        if ( !RGE_Game_World::object(v4->md->aiPlayer->world, v4->soldiers.value[v12]) && !RGE_Static_Object::unitAI(0) )
        {
          if ( action == -1 || (v16 = RGE_Static_Object::unitAI(0), UnitAIModule::currentAction(v16) == action) )
          {
            if ( target == -1 || (v17 = RGE_Static_Object::unitAI(0), UnitAIModule::currentTarget(v17) == target) )
            {
              if ( targetType == -1 )
                break;
              v18 = RGE_Static_Object::unitAI(0);
              if ( UnitAIModule::currentTargetType(v18) == targetType )
                break;
            }
          }
        }
        if ( ++v12 >= v4->soldiers.numberValue )
          goto LABEL_42;
      }
      if ( v12 > v4->soldiers.maximumSizeValue - 1 )
      {
        v19 = v12 + 1;
        v20 = (int *)operator new(4 * (v12 + 1));
        if ( v20 )
        {
          for ( l = 0; l < v4->soldiers.maximumSizeValue; v20[l - 1] = v4->soldiers.value[l - 1] )
          {
            if ( l >= v19 )
              break;
            ++l;
          }
          operator delete(v4->soldiers.value);
          v4->soldiers.value = v20;
          v4->soldiers.maximumSizeValue = v19;
        }
      }
      result = v4->soldiers.value[v12];
    }
  }
  else
  {
    v6 = (void **)&this->civilians.value;
    while ( 1 )
    {
      if ( v5 > v4->civilians.maximumSizeValue - 1 )
      {
        v7 = operator new(4 * v5 + 4);
        if ( v7 )
        {
          for ( m = 0; m < v4->civilians.maximumSizeValue; v7[m - 1] = *((_DWORD *)*v6 + m - 1) )
          {
            if ( m >= v5 + 1 )
              break;
            ++m;
          }
          operator delete(*v6);
          *v6 = v7;
          v4->civilians.maximumSizeValue = v5 + 1;
        }
      }
      if ( !RGE_Game_World::object(v4->md->aiPlayer->world, *((_DWORD *)*v6 + v5)) && !RGE_Static_Object::unitAI(0) )
      {
        if ( action == -1 || (v9 = RGE_Static_Object::unitAI(0), UnitAIModule::currentAction(v9) == action) )
        {
          if ( target == -1 || (v10 = RGE_Static_Object::unitAI(0), UnitAIModule::currentTarget(v10) == target) )
          {
            if ( targetType == -1 )
              break;
            v11 = RGE_Static_Object::unitAI(0);
            if ( UnitAIModule::currentTargetType(v11) == targetType )
              break;
          }
        }
      }
      if ( ++v5 >= v4->civilians.numberValue )
        goto LABEL_18;
    }
    if ( v5 > v4->civilians.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v4->civilians, v5 + 1);
    result = *((_DWORD *)*v6 + v5);
  }
  return result;
}

//----- (004F8BE0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::busyWithAction(TribeTacticalAIModule *this, int id, int a)
{
  RGE_Static_Object *v3; // eax@1
  RGE_Static_Object *v4; // esi@1
  UnitAIModule *v5; // eax@3
  int result; // eax@4

  v3 = RGE_Game_World::object(this->md->aiPlayer->world, id);
  v4 = v3;
  result = 0;
  if ( v3 )
  {
    if ( RGE_Static_Object::unitAI(v3) )
    {
      v5 = RGE_Static_Object::unitAI(v4);
      if ( UnitAIModule::currentAction(v5) == a )
        result = 1;
    }
  }
  return result;
}

//----- (004F8C40) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::updateNeededResources(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // edi@1
  signed int v2; // esi@1
  int *v3; // ebx@1
  int v4; // ebp@2
  int v5; // eax@2
  int v6; // ebx@4
  int v7; // ebp@4
  int v8; // esi@4
  signed int v9; // eax@20
  int *v10; // edx@20
  int *v11; // ecx@20
  int *v12; // edx@27
  signed int v13; // eax@27
  int v14; // ecx@28
  int v15; // esi@28
  signed int v16; // [sp+10h] [bp-34h]@3
  int assignedResource[4]; // [sp+14h] [bp-30h]@1
  int tempNeededResource[4]; // [sp+24h] [bp-20h]@1
  int tempResourceDifference[4]; // [sp+34h] [bp-10h]@1

  v1 = this;
  TribeBuildAIModule::mostNeededResource(&this->md->buildAI, &this->neededResources, this->sn[147]);
  v2 = 0;
  tempResourceDifference[0] = -1;
  tempNeededResource[0] = -1;
  assignedResource[0] = 0;
  tempResourceDifference[1] = -1;
  tempNeededResource[1] = -1;
  assignedResource[1] = 0;
  tempResourceDifference[2] = -1;
  tempNeededResource[2] = -1;
  assignedResource[2] = 0;
  v3 = v1->resourceDifferenceValue;
  tempResourceDifference[3] = -1;
  tempNeededResource[3] = -1;
  assignedResource[3] = 0;
  do
  {
    v4 = TribeResourceAIModule::resource(&v1->md->resourceAI, v2);
    v5 = ResourceItem::value(&v1->neededResources, v2++);
    *v3 = v4 - v5;
    ++v3;
  }
  while ( v2 < 4 );
  v16 = 0;
  do
  {
    v6 = -1;
    v7 = 0x7FFFFFFF;
    v8 = 0;
    do
    {
      if ( (v8 || TribeResourceAIModule::resource(&v1->md->resourceAI, 0) < v1->sn[190])
        && (v8 != 1 || TribeResourceAIModule::resource(&v1->md->resourceAI, 1) < v1->sn[191])
        && (v8 != 3 || TribeResourceAIModule::resource(&v1->md->resourceAI, 3) < v1->sn[193])
        && (v8 != 2 || TribeResourceAIModule::resource(&v1->md->resourceAI, 2) < v1->sn[192])
        && ResourceItem::value(&v1->neededResources, v8) > 0
        && (v6 == -1 || v1->resourceDifferenceValue[v8] < v7)
        && !assignedResource[v8] )
      {
        v7 = v1->resourceDifferenceValue[v8];
        v6 = v8;
      }
      ++v8;
    }
    while ( v8 < 4 );
    if ( v6 == -1 )
    {
      v9 = 0;
      v10 = assignedResource;
      v11 = v1->resourceDifferenceValue;
      do
      {
        if ( (v6 == -1 || *v11 < v7) && !*v10 )
        {
          v7 = *v11;
          v6 = v9;
        }
        ++v9;
        ++v10;
        ++v11;
      }
      while ( v9 < 4 );
    }
    assignedResource[v6] = 1;
    tempNeededResource[v16] = v6;
    tempResourceDifference[v16] = v7;
    ++v16;
  }
  while ( v16 < 4 );
  v12 = v1->neededResourceValue;
  v13 = 0;
  do
  {
    v14 = tempNeededResource[v13];
    v15 = tempResourceDifference[v13];
    *v12 = v14;
    ++v13;
    ++v12;
    v1->resourceDifferenceValue[v14] = v15;
  }
  while ( v13 < 4 );
}

//----- (004F8E20) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::updateGathererDistribution(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  char *v2; // ebx@2
  RGE_Static_Object *v3; // eax@3
  RGE_Static_Object *v4; // edi@3
  UnitAIModule *v5; // eax@5
  int v6; // eax@5
  signed int v7; // ebp@5
  UnitAIModule *v8; // eax@5
  int v9; // ecx@8
  int v10; // edi@8
  int v11; // eax@8
  int v12; // ecx@18
  int j; // eax@18
  int *v14; // edi@25
  int v15; // ecx@25
  signed int v16; // ebx@25
  TribeMainDecisionAIModule *v17; // eax@28
  int v18; // eax@31
  int v19; // edx@31
  int v20; // eax@32
  int v21; // eax@44
  int v22; // edx@44
  int v23; // eax@45
  int v24; // eax@51
  int v25; // edx@55
  int v26; // eax@55
  int v27; // ecx@56
  int v28; // eax@57
  signed __int64 v29; // rax@63
  unsigned int v30; // ecx@63
  int v31; // edi@66
  int v32; // ecx@66
  int v33; // edx@66
  int v34; // ecx@66
  unsigned int v35; // edx@66
  signed int v36; // ecx@66
  int v37; // eax@67
  int *v38; // ecx@67
  signed int v39; // edx@67
  int v40; // ebp@68
  int v41; // edx@69
  int v42; // ebp@69
  signed int v43; // ebx@69
  int *v44; // ecx@69
  signed int v45; // edi@69
  int *v46; // edi@74
  int v47; // ecx@75
  bool v48; // zf@75
  int v49; // eax@76
  int *v50; // ecx@76
  signed int v51; // edx@76
  int v52; // ebp@77
  signed int v53; // ecx@78
  int v54; // ebx@79
  int v55; // eax@81
  int gSTT; // [sp+10h] [bp-Ch]@5
  int gAction; // [sp+14h] [bp-8h]@5
  int i; // [sp+18h] [bp-4h]@1
  int ia; // [sp+18h] [bp-4h]@74

  v1 = this;
  this->actualGathererDistribution[0] = 0;
  this->actualGathererDistribution[1] = 0;
  i = 0;
  this->actualGathererDistribution[2] = 0;
  this->actualGathererDistribution[3] = 0;
  if ( this->numberGatherersValue > 0 )
  {
    v2 = (char *)&this->gatherers[0].data1;
    do
    {
      v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, *((_DWORD *)v2 - 1));
      v4 = v3;
      if ( v3 && RGE_Static_Object::unitAI(v3) )
      {
        v5 = RGE_Static_Object::unitAI(v4);
        v6 = UnitAIModule::currentAction(v5);
        v7 = *(_DWORD *)v2;
        gAction = v6;
        gSTT = *(_DWORD *)v2;
        v8 = RGE_Static_Object::unitAI(v4);
        *((_DWORD *)v2 + 3) = UnitAIModule::currentTarget(v8);
        if ( gAction == 609 && v4->master_obj->id == 259 )
        {
          if ( !v7 )
            goto LABEL_15;
          v9 = v1->unitsTaskedThisUpdate.numberValue;
          v10 = v4->id;
          v11 = 0;
          if ( v9 > 0 )
          {
            while ( v11 < v1->unitsTaskedThisUpdate.maximumSizeValue )
            {
              if ( v1->unitsTaskedThisUpdate.value[v11] == v10 )
              {
                v7 = gSTT;
                goto LABEL_14;
              }
              v7 = gSTT;
              if ( ++v11 >= v9 )
                break;
            }
          }
          *(_DWORD *)v2 = 0;
        }
LABEL_14:
        if ( v7 >= 0 )
        {
LABEL_15:
          if ( v7 <= 3 )
          {
            if ( gAction == 609 || gAction == 613 )
            {
LABEL_23:
              ++v1->actualGathererDistribution[v7];
            }
            else
            {
              v12 = v1->unitsTaskedThisUpdate.numberValue;
              for ( j = 0; j < v12; ++j )
              {
                if ( j >= v1->unitsTaskedThisUpdate.maximumSizeValue )
                  break;
                if ( v1->unitsTaskedThisUpdate.value[j] == *((_DWORD *)v2 - 1) )
                  goto LABEL_23;
              }
            }
          }
          goto LABEL_24;
        }
      }
LABEL_24:
      v2 += 24;
      ++i;
    }
    while ( i < v1->numberGatherersValue );
  }
  v14 = v1->desiredGathererDistribution;
  v15 = (int)v1->desiredGathererDistribution;
  v16 = 0;
  *(_DWORD *)v15 = 0;
  *(_DWORD *)(v15 + 4) = 0;
  *(_DWORD *)(v15 + 8) = 0;
  *(_DWORD *)(v15 + 12) = 0;
  if ( TribeTacticalAIModule::inAge(v1, 1) )
  {
    if ( v1->sn[181] == 1 )
    {
      if ( TribeBuildAIModule::readyToResearch(&v1->md->buildAI, 2, 1) )
      {
        v17 = v1->md;
        if ( v17->informationAI.closestDropsiteValue[0] != -1
          && (TribeResourceAIModule::resource(&v17->resourceAI, 1) > 120 || v1->builtFirstGranary == 1) )
        {
          v18 = v1->numberGatherersValue;
          *v14 = v1->desiredNumberGatherersValue;
          v19 = 0;
          if ( v18 > 0 )
          {
            v20 = (int)&v1->gatherers[0].data1;
            do
            {
              if ( *(_DWORD *)v20 && *(_DWORD *)v20 != -1 )
                *(_DWORD *)(v20 + 4) = 5;
              ++v19;
              v20 += 24;
            }
            while ( v19 < v1->numberGatherersValue );
          }
          v1->zoomingToNextAge = 1;
          v16 = 1;
          goto LABEL_65;
        }
      }
LABEL_51:
      v24 = v1->desiredNumberGatherersValue;
      v1->zoomingToNextAge = 0;
      v1->desiredGathererDistribution[1] = v24;
      v16 = 1;
      goto LABEL_65;
    }
LABEL_64:
    v1->zoomingToNextAge = 0;
    goto LABEL_65;
  }
  if ( TribeTacticalAIModule::inAge(v1, 2) )
  {
    if ( v1->sn[182] != 1 )
      goto LABEL_64;
    if ( !TribeBuildAIModule::readyToResearch(&v1->md->buildAI, 3, 1)
      || TribeResourceAIModule::resource(&v1->md->resourceAI, 1) <= 240
      && (TribeResourceAIModule::resource(&v1->md->resourceAI, 1) <= 120
       || v1->md->informationAI.closestDropsiteValue[0] >= 20) )
    {
      goto LABEL_51;
    }
    v21 = v1->numberGatherersValue;
    *v14 = v1->desiredNumberGatherersValue;
    v22 = 0;
    if ( v21 > 0 )
    {
      v23 = (int)&v1->gatherers[0].data1;
      do
      {
        if ( *(_DWORD *)v23 && *(_DWORD *)v23 != -1 )
          *(_DWORD *)(v23 + 4) = 5;
        ++v22;
        v23 += 24;
      }
      while ( v22 < v1->numberGatherersValue );
    }
    v1->zoomingToNextAge = 1;
    v16 = 1;
  }
  else
  {
    if ( !TribeTacticalAIModule::inAge(v1, 3) )
      goto LABEL_65;
    if ( v1->sn[183] != 1 )
      goto LABEL_64;
    if ( TribeBuildAIModule::readyToResearch(&v1->md->buildAI, 4, 1) )
    {
      v25 = 0;
      v26 = v1->desiredNumberGatherersValue / 2;
      *v14 = v26;
      v1->desiredGathererDistribution[3] = v26;
      if ( v1->numberGatherersValue > 0 )
      {
        v27 = (int)&v1->gatherers[0].data1;
        do
        {
          v28 = *(_DWORD *)v27;
          if ( *(_DWORD *)v27 && v28 != 3 && v28 != -1 )
            *(_DWORD *)(v27 + 4) = 5;
          ++v25;
          v27 += 24;
        }
        while ( v25 < v1->numberGatherersValue );
      }
      v1->zoomingToNextAge = 1;
      v16 = 1;
    }
    else
    {
      v29 = 1431655766i64 * v1->desiredNumberGatherersValue;
      v30 = (unsigned __int64)(1431655766i64 * v1->desiredNumberGatherersValue) >> 32;
      v1->zoomingToNextAge = 0;
      HIDWORD(v29) += v30 >> 31;
      v16 = 1;
      *v14 = HIDWORD(v29);
      v1->desiredGathererDistribution[3] = HIDWORD(v29);
      v1->desiredGathererDistribution[1] = HIDWORD(v29);
    }
  }
LABEL_65:
  if ( !v16 )
  {
    v31 = v1->desiredNumberGatherersValue;
    v32 = v1->sn[118];
    v1->desiredGathererDistribution[2] = v31 * (v1->sn[158] + v1->sn[119]) / 100;
    v33 = v31 * (v1->sn[159] + v32) / 100;
    v34 = v1->sn[120];
    v1->desiredGathererDistribution[3] = v33;
    v35 = (unsigned __int64)(1374389535i64 * v31 * (v1->sn[157] + v34)) >> 32;
    v36 = v31 * (v1->sn[156] + v1->sn[117]);
    v1->desiredGathererDistribution[1] = (v35 >> 31) + ((signed int)v35 >> 5);
    v1->desiredGathererDistribution[0] = v36 / 100;
  }
  v37 = 0;
  v38 = v1->desiredGathererDistribution;
  v39 = 4;
  do
  {
    v40 = *v38;
    ++v38;
    v37 += v40;
    --v39;
  }
  while ( v39 );
  v41 = 0;
  v42 = v1->desiredNumberGatherersValue - v37;
  v43 = 0;
  v44 = v1->resourceDifferenceValue;
  v45 = 4;
  do
  {
    if ( *v44 < 0 )
    {
      v43 -= *v44;
      ++v41;
    }
    ++v44;
    --v45;
  }
  while ( v45 );
  if ( v41 > 0 )
  {
    v46 = v1->neededResourceValue;
    ia = v41;
    do
    {
      v47 = *v46;
      ++v46;
      v48 = ia == 1;
      v1->desiredGathererDistribution[v47] -= v42 * v1->resourceDifferenceValue[v47] / v43;
      --ia;
    }
    while ( !v48 );
  }
  v49 = 0;
  v50 = v1->desiredGathererDistribution;
  v51 = 4;
  do
  {
    v52 = *v50;
    ++v50;
    v49 += v52;
    --v51;
  }
  while ( v51 );
  v53 = v1->desiredNumberGatherersValue - v49;
  if ( v53 > 0 )
  {
    v54 = v53 / 2;
    if ( (((unsigned __int64)v53 >> 32) ^ abs(v53) & 1) - ((unsigned __int64)v53 >> 32) == 1 )
      ++v54;
    v55 = v53 / 2 + v1->desiredGathererDistribution[1];
    v1->desiredGathererDistribution[0] += v54;
    v1->desiredGathererDistribution[1] = v55;
  }
}

//----- (004F9380) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::stopUnit(TribeTacticalAIModule *this, int uID, int priority)
{
  ((void (__stdcall *)(_DWORD, int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, int))this->md->player->vfptr->sendUnitAIOrder)(
    this->md->player->id,
    uID,
    706,
    -1,
    -1,
    -1082130432,
    -1082130432,
    -1082130432,
    -1082130432,
    1,
    0,
    priority);
  return 1;
}

//----- (004F93D0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::moveUnit(TribeTacticalAIModule *this, int uID, float x, float y, int priority)
{
  ((void (__stdcall *)(_DWORD, int, signed int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, int))this->md->player->vfptr->sendUnitAIOrder)(
    this->md->player->id,
    uID,
    710,
    -1,
    -1,
    LODWORD(x),
    LODWORD(y),
    1065353216,
    1065353216,
    1,
    0,
    priority);
  return 1;
}

//----- (004F9420) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::groupGatherUnit(TribeTacticalAIModule *this, int uID, int tID, float x, float y, float z, float range, int priority)
{
  ((void (__stdcall *)(_DWORD, int, signed int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, signed int, _DWORD, int))this->md->player->vfptr->sendUnitAIOrder)(
    this->md->player->id,
    uID,
    724,
    tID,
    -1,
    LODWORD(x),
    LODWORD(y),
    LODWORD(z),
    LODWORD(range),
    1,
    0,
    priority);
  return 1;
}

//----- (004F9470) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::highLevelTaskExplorer(TribeTacticalAIModule *this, int unitID, int civilian)
{
  TribeTacticalAIModule *v3; // edi@1
  RGE_Static_Object *v4; // eax@1
  RGE_Static_Object *v5; // esi@1
  UnitAIModule *v6; // eax@3
  UnitAIModule *v8; // eax@5
  UnitAIModule *v9; // eax@6
  UnitAIModule *v10; // eax@7
  UnitAIModule *v11; // eax@10
  UnitAIModule *v12; // eax@11
  UnitAIModule *v13; // eax@12
  UnitAIModule *v14; // eax@13

  v3 = this;
  v4 = RGE_Game_World::object(this->md->player->world, unitID);
  v5 = v4;
  if ( v4 && RGE_Static_Object::unitAI(v4) )
  {
    v6 = RGE_Static_Object::unitAI(v5);
    if ( UnitAIModule::currentAction(v6) == 600 )
      return 1;
    v8 = RGE_Static_Object::unitAI(v5);
    if ( UnitAIModule::currentAction(v8) == 602 )
      return 1;
    v9 = RGE_Static_Object::unitAI(v5);
    if ( UnitAIModule::currentAction(v9) == 618 )
      return 1;
    v10 = RGE_Static_Object::unitAI(v5);
    if ( UnitAIModule::currentAction(v10) == 605 )
      return 1;
    if ( v5->attribute_amount_held <= 0.0 )
    {
      v11 = RGE_Static_Object::unitAI(v5);
      if ( UnitAIModule::currentOrder(v11) != 710
        || (v12 = RGE_Static_Object::unitAI(v5), UnitAIModule::currentOrderPriority(v12) != 100) )
      {
        v13 = RGE_Static_Object::unitAI(v5);
        if ( UnitAIModule::currentOrder(v13) != 702 )
        {
          v14 = RGE_Static_Object::unitAI(v5);
          if ( UnitAIModule::hasOrderOnQueue(v14, 705) != 1 )
            return TribeTacticalAIModule::taskExplorer(v3, unitID, civilian) != 0;
        }
      }
    }
  }
  return 0;
}

//----- (004F95B0) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::highLevelTaskGatherer(TribeTacticalAIModule *this, int unitID, unsigned int startTime)
{
  TribeTacticalAIModule *v3; // esi@1
  int v4; // edi@1
  int v5; // ecx@1
  UnitData *v6; // eax@2
  unsigned int v7; // eax@6
  int v8; // ebp@6
  RGE_Static_Object *result; // eax@7
  RGE_Static_Object *v10; // eax@8
  RGE_Static_Object *v11; // ebx@8
  UnitAIModule *v12; // eax@10
  UnitAIModule *v13; // eax@12
  UnitAIModule *v14; // eax@13
  UnitAIModule *v15; // eax@20
  UnitAIModule *v16; // eax@21
  UnitAIModule *v17; // eax@22
  AIModuleVtbl **v18; // edi@24
  UnitAIModule *v19; // eax@25
  int v20; // eax@27
  int *v21; // eax@29
  RGE_Static_Object *v22; // edi@29
  int v23; // ebx@29
  UnitAIModule *v24; // eax@33
  UnitAIModule *v25; // eax@34
  int v26; // ST00_4@35
  int v27; // eax@43
  int v28; // ecx@50
  int v29; // [sp-14h] [bp-3Ch]@43
  int v30; // [sp-10h] [bp-38h]@43
  unsigned int v31; // [sp-8h] [bp-30h]@43
  int v32; // [sp+10h] [bp-18h]@29
  RGE_Static_Object *gathererObj; // [sp+14h] [bp-14h]@8
  int triedTasking[4]; // [sp+18h] [bp-10h]@1
  int unitIDc; // [sp+2Ch] [bp+4h]@17
  int unitIDa; // [sp+2Ch] [bp+4h]@17
  int *unitIDb; // [sp+2Ch] [bp+4h]@29

  v3 = this;
  v4 = 0;
  v5 = this->numberGatherersValue;
  triedTasking[0] = 0;
  triedTasking[1] = 0;
  triedTasking[2] = 0;
  triedTasking[3] = 0;
  if ( v5 > 0 )
  {
    v6 = v3->gatherers;
    do
    {
      if ( v6->id == unitID )
        break;
      ++v4;
      ++v6;
    }
    while ( v4 < v5 );
  }
  if ( v4 >= v5 )
    goto LABEL_59;
  v7 = debug_timeGetTime();
  v8 = (int)v3 + 24 * v4;
  if ( v7 - v3->gatherers[v4].lastTaskTime < 0x1388 )
    return (RGE_Static_Object *)1;
  *(_DWORD *)(v8 + 1328) = v7;
  v10 = RGE_Game_World::object(v3->md->player->world, unitID);
  v11 = v10;
  gathererObj = v10;
  if ( v10 && RGE_Static_Object::unitAI(v10) )
  {
    v12 = RGE_Static_Object::unitAI(v11);
    if ( UnitAIModule::currentAction(v12) == 600 )
      return (RGE_Static_Object *)1;
    v13 = RGE_Static_Object::unitAI(v11);
    if ( UnitAIModule::currentAction(v13) == 602 )
      goto LABEL_55;
    v14 = RGE_Static_Object::unitAI(v11);
    if ( UnitAIModule::currentAction(v14) == 618 )
      goto LABEL_55;
    if ( v11->attribute_amount_held > 0.0 )
      return (RGE_Static_Object *)1;
    if ( TribeTacticalAIModule::isFarmer(v11) == 1 )
    {
      unitIDc = v3->civilians.numberValue;
      unitIDa = unitIDc - TribeTacticalAIModule::numberFarmers(v3);
      if ( TribeResourceAIModule::resource(&v3->md->resourceAI, 0) < 1000 && unitIDa > 3 )
        return (RGE_Static_Object *)1;
    }
    v15 = RGE_Static_Object::unitAI(v11);
    if ( UnitAIModule::currentOrder(v15) == 710
      && (v16 = RGE_Static_Object::unitAI(v11), UnitAIModule::currentOrderPriority(v16) == 100) )
    {
LABEL_55:
      result = (RGE_Static_Object *)1;
    }
    else
    {
      v17 = RGE_Static_Object::unitAI(v11);
      if ( UnitAIModule::currentOrder(v17) == 702 )
        return (RGE_Static_Object *)1;
      v18 = &v3->vfptr + 6 * (v4 + 55);
      if ( *(_DWORD *)(v8 + 1316) <= (signed int)*v18 )
      {
LABEL_29:
        v21 = v3->desiredGathererDistribution;
        v22 = 0;
        v23 = 0;
        unitIDb = triedTasking;
        v32 = (int)v3->desiredGathererDistribution;
        do
        {
          if ( *unitIDb != 1 && *(v21 - 4) < *v21 )
          {
            if ( *(_DWORD *)(v8 + 1312) == v23 )
            {
              v24 = RGE_Static_Object::unitAI(gathererObj);
              if ( UnitAIModule::currentAction(v24) == 613 )
                goto LABEL_55;
              v25 = RGE_Static_Object::unitAI(gathererObj);
              if ( UnitAIModule::currentAction(v25) == 609 )
                goto LABEL_55;
            }
            v26 = *(_DWORD *)(v8 + 1308);
            *unitIDb = 1;
            v22 = TribeTacticalAIModule::taskGatherer(v3, v26, v23, 0, startTime, 0);
            if ( v22 == (RGE_Static_Object *)1 )
              goto LABEL_55;
            v21 = (int *)v32;
          }
          ++v23;
          ++v21;
          v32 = (int)v21;
          ++unitIDb;
        }
        while ( v23 < 4 );
        if ( TribeTacticalAIModule::inAge(v3, 1) && v3->sn[181] == 1
          || TribeTacticalAIModule::inAge(v3, 2) && v3->sn[182] == 1 && !triedTasking[0] )
        {
          v27 = *(_DWORD *)(v8 + 1308);
          v31 = startTime;
          v30 = 0;
          triedTasking[0] = 1;
          v29 = v27;
        }
        else
        {
          if ( !TribeTacticalAIModule::inAge(v3, 3) || v3->sn[183] != 1 )
            goto LABEL_52;
          if ( !triedTasking[0] )
          {
            v22 = TribeTacticalAIModule::taskGatherer(v3, *(_DWORD *)(v8 + 1308), 0, 1, startTime, 0);
            triedTasking[0] = 1;
          }
          if ( triedTasking[3] )
            goto LABEL_52;
          if ( v22 )
            return (RGE_Static_Object *)1;
          v28 = *(_DWORD *)(v8 + 1308);
          v31 = startTime;
          v30 = 3;
          triedTasking[3] = 1;
          v29 = v28;
        }
        v22 = TribeTacticalAIModule::taskGatherer(v3, v29, v30, 1, v31, 0);
LABEL_52:
        if ( !v22 )
          TribeTacticalAIModule::taskGatherer(v3, *(_DWORD *)(v8 + 1308), -1, 1, startTime, triedTasking);
        return (RGE_Static_Object *)1;
      }
      v19 = RGE_Static_Object::unitAI(v11);
      if ( UnitAIModule::currentAction(v19) != -1 )
        return (RGE_Static_Object *)1;
      v20 = *(_DWORD *)(v8 + 1312);
      triedTasking[v20] = 1;
      result = TribeTacticalAIModule::taskGatherer(v3, *(_DWORD *)(v8 + 1308), v20, 0, startTime, 0);
      if ( result != (RGE_Static_Object *)1 )
      {
        *(_DWORD *)(v8 + 1312) = -1;
        *(_DWORD *)(v8 + 1316) = -1;
        *v18 = (AIModuleVtbl *)-1;
        goto LABEL_29;
      }
    }
  }
  else
  {
LABEL_59:
    result = 0;
  }
  return result;
}

//----- (004F99B0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskPlay(TribeTacticalAIModule *this, int commander, int *groupUnits, int groupCount, int target, int play, Waypoint *path, int pathLength)
{
  Waypoint *v8; // edi@1
  TribeTacticalAIModule *v9; // esi@1
  int v10; // ebx@2
  int v11; // ecx@4
  int i; // eax@4
  int v13; // ebx@9
  int *v14; // edi@9
  int j; // eax@10

  v8 = path;
  v9 = this;
  if ( path )
  {
    v10 = pathLength;
    if ( pathLength > 0 )
    {
      do
      {
        TribeTacticalAIModule::addWaypoint(v9, commander, (signed __int64)v8->x, (signed __int64)v8->y);
        ++v8;
        --v10;
      }
      while ( v10 );
    }
  }
  v11 = v9->unitsTaskedThisUpdate.numberValue;
  for ( i = 0; i < v11; ++i )
  {
    if ( i >= v9->unitsTaskedThisUpdate.maximumSizeValue )
      break;
    if ( v9->unitsTaskedThisUpdate.value[i] == commander )
      goto LABEL_15;
  }
  if ( v11 > v9->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v13 = v11 + 1;
    v14 = (int *)operator new(4 * (v11 + 1));
    if ( v14 )
    {
      for ( j = 0; j < v9->unitsTaskedThisUpdate.maximumSizeValue; v14[j - 1] = v9->unitsTaskedThisUpdate.value[j - 1] )
      {
        if ( j >= v13 )
          break;
        ++j;
      }
      operator delete(v9->unitsTaskedThisUpdate.value);
      v9->unitsTaskedThisUpdate.value = v14;
      v9->unitsTaskedThisUpdate.maximumSizeValue = v13;
    }
  }
  v9->unitsTaskedThisUpdate.value[v9->unitsTaskedThisUpdate.numberValue++] = commander;
LABEL_15:
  (*((void (__stdcall **)(int, int *, int, int, int))&v9->md->player->vfptr->processAddWaypointCommand + 1))(
    commander,
    groupUnits,
    groupCount,
    target,
    play);
  return 1;
}

//----- (004F9AD0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskBuilder(TribeTacticalAIModule *this, int builder, BuildItem *newBuilding, ConstructionItem *ci, unsigned int startTime)
{
  TribeTacticalAIModule *v5; // esi@1
  ConstructionItem *v6; // ebp@3
  ConstructionItem *v7; // eax@4
  RGE_Static_Object *v8; // eax@8
  RGE_Static_Object *v9; // edi@8
  int v10; // ebx@10
  int v11; // ebp@10
  BuildItem *v13; // ebx@13
  int v14; // ecx@13
  int v15; // eax@13
  int *v16; // edx@14
  int v17; // ebp@15
  int v18; // eax@22
  int v19; // ecx@24
  int i; // eax@24
  int v21; // ebx@29
  int *v22; // edi@29
  int j; // eax@30
  int v24; // ST2C_4@37
  float v25; // ST28_4@37
  float v26; // ST24_4@37
  int v27; // eax@37
  XYPoint position; // [sp+40h] [bp-8h]@7
  int buildera; // [sp+4Ch] [bp+4h]@37

  v5 = this;
  if ( !newBuilding )
  {
    newBuilding = TribeBuildAIModule::nextBuildableItem(&this->md->buildAI, 0);
    if ( !newBuilding )
      return 0;
  }
  v6 = ci;
  if ( ci )
    goto LABEL_6;
  TribeConstructionAIModule::placeStructure(
    &v5->md->constructionAI,
    newBuilding,
    builder,
    &v5->placementStateValue,
    startTime);
  ci = v7;
  if ( !v7 )
    return 0;
  v6 = v7;
LABEL_6:
  if ( builder == -1 )
  {
    position.x = (signed __int64)BaseItem::x((BaseItem *)&v6->vfptr);
    position.y = (signed __int64)BaseItem::y((BaseItem *)&v6->vfptr);
    builder = TribeTacticalAIModule::civilian(v5, &position, 1, 702, 718, 700, 0);
  }
  v8 = RGE_Game_World::object(v5->md->player->world, builder);
  v9 = v8;
  if ( !v8 || !RGE_Static_Object::unitAI(v8) )
  {
    if ( v6 )
      v6->vfptr->__vecDelDtor((BaseItem *)v6, 1u);
    return 0;
  }
  v10 = (signed __int64)BaseItem::x((BaseItem *)&v6->vfptr);
  v11 = (signed __int64)BaseItem::y((BaseItem *)&v6->vfptr);
  if ( !((int (__thiscall *)(RGE_Static_Object *, int, int, _DWORD, signed int, signed int, _DWORD, signed int, signed int, signed int))v9->vfptr->canPath)(
          v9,
          v10,
          v11,
          (signed __int64)v9->world_z,
          0x40000000,
          -1,
          0,
          1,
          -1,
          -1) )
  {
    if ( ci )
    {
      ((void (__stdcall *)(signed int))ci->vfptr->__vecDelDtor)(1);
      return 0;
    }
    return 0;
  }
  v13 = newBuilding;
  BuildItem::setInProgress(newBuilding, 1);
  BuildItem::setBuilt(newBuilding, 0);
  v14 = v5->civilianExplorers.maximumSizeValue;
  v15 = 0;
  if ( v14 <= 0 )
  {
    v17 = builder;
  }
  else
  {
    v16 = v5->civilianExplorers.value;
    do
    {
      v17 = builder;
      if ( *v16 == builder )
        break;
      ++v15;
      ++v16;
    }
    while ( v15 < v14 );
  }
  if ( v15 < v14 )
  {
    if ( v15 < v14 - 1 )
    {
      do
      {
        ++v15;
        v5->civilianExplorers.value[v15 - 1] = v5->civilianExplorers.value[v15];
      }
      while ( v15 < v5->civilianExplorers.maximumSizeValue - 1 );
    }
    v18 = v5->civilianExplorers.numberValue - 1;
    v5->civilianExplorers.numberValue = v18;
    if ( v18 < 0 )
      v5->civilianExplorers.numberValue = 0;
  }
  v19 = v5->unitsTaskedThisUpdate.numberValue;
  for ( i = 0; i < v19; ++i )
  {
    if ( i >= v5->unitsTaskedThisUpdate.maximumSizeValue )
      break;
    if ( v5->unitsTaskedThisUpdate.value[i] == v17 )
      goto LABEL_35;
  }
  if ( v19 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v21 = v19 + 1;
    v22 = (int *)operator new(4 * (v19 + 1));
    if ( v22 )
    {
      for ( j = 0; j < v5->unitsTaskedThisUpdate.maximumSizeValue; v22[j - 1] = v5->unitsTaskedThisUpdate.value[j - 1] )
      {
        if ( j >= v21 )
          break;
        ++j;
      }
      operator delete(v5->unitsTaskedThisUpdate.value);
      v5->unitsTaskedThisUpdate.value = v22;
      v5->unitsTaskedThisUpdate.maximumSizeValue = v21;
    }
  }
  v13 = newBuilding;
  v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = v17;
LABEL_35:
  if ( BaseItem::typeID((BaseItem *)&ci->vfptr) == 276 )
    v5->wonderInProgressValue = 1;
  buildera = (int)v5->md->aiPlayer->vfptr;
  v24 = BaseItem::uniqueID((BaseItem *)&v13->vfptr);
  v25 = BaseItem::y((BaseItem *)&ci->vfptr);
  v26 = BaseItem::x((BaseItem *)&ci->vfptr);
  v27 = BaseItem::typeID((BaseItem *)&ci->vfptr);
  (*(void (__thiscall **)(TRIBE_Player *, int, int, _DWORD, _DWORD, int))(buildera + 252))(
    v5->md->aiPlayer,
    v17,
    v27,
    LODWORD(v26),
    LODWORD(v25),
    v24);
  if ( ci )
    ci->vfptr->__vecDelDtor((BaseItem *)ci, 1u);
  return 1;
}

//----- (004F9E00) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::taskBuilder(TribeTacticalAIModule *this, int builder, RGE_Static_Object *building)
{
  TribeTacticalAIModule *v3; // esi@1
  RGE_Static_Object *result; // eax@1
  RGE_Static_Object *v5; // edi@2
  int v6; // ebx@2
  int v7; // ebp@2
  signed __int64 v8; // rax@2
  int v9; // ecx@9
  int i; // eax@9
  int v11; // ebp@14
  int *v12; // ebx@14
  int j; // eax@15
  int v14; // eax@20
  RGE_Static_Object *builderObj; // [sp+24h] [bp-4h]@1
  RGE_Static_Object *buildinga; // [sp+30h] [bp+8h]@20

  v3 = this;
  result = RGE_Game_World::object(this->md->player->world, builder);
  builderObj = result;
  if ( !result )
    return result;
  v5 = building;
  v6 = (signed __int64)building->world_x;
  v7 = (signed __int64)building->world_y;
  v8 = (signed __int64)building->world_z;
  if ( building )
  {
    if ( !((int (__thiscall *)(RGE_Static_Object *, int, int, _DWORD, signed int, int, _DWORD, signed int, signed int, signed int))builderObj->vfptr->canPath)(
            builderObj,
            v6,
            v7,
            v8,
            1065353216,
            building->id,
            0,
            1,
            -1,
            -1) )
    {
      if ( building->master_obj->id != 276 )
        TribeTacticalAIModule::deleteUnit(v3, building->id);
      return 0;
    }
  }
  else
  {
    result = (RGE_Static_Object *)((int (__thiscall *)(RGE_Static_Object *, int, int, _DWORD, signed int, signed int, _DWORD, signed int, signed int, signed int))builderObj->vfptr->canPath)(
                                    builderObj,
                                    v6,
                                    v7,
                                    v8,
                                    1065353216,
                                    -1,
                                    0,
                                    1,
                                    -1,
                                    -1);
    if ( !result )
      return result;
  }
  v9 = v3->unitsTaskedThisUpdate.numberValue;
  for ( i = 0; i < v9; ++i )
  {
    if ( i >= v3->unitsTaskedThisUpdate.maximumSizeValue )
      break;
    if ( v3->unitsTaskedThisUpdate.value[i] == builder )
      goto LABEL_20;
  }
  if ( v9 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v11 = v9 + 1;
    v12 = (int *)operator new(4 * (v9 + 1));
    if ( v12 )
    {
      for ( j = 0; j < v3->unitsTaskedThisUpdate.maximumSizeValue; v12[j - 1] = v3->unitsTaskedThisUpdate.value[j - 1] )
      {
        if ( j >= v11 )
          break;
        ++j;
      }
      operator delete(v3->unitsTaskedThisUpdate.value);
      v3->unitsTaskedThisUpdate.value = v12;
      v3->unitsTaskedThisUpdate.maximumSizeValue = v11;
    }
  }
  v3->unitsTaskedThisUpdate.value[v3->unitsTaskedThisUpdate.numberValue++] = builder;
LABEL_20:
  *(float *)&buildinga = RGE_Static_Object::distance_to_object(building, builderObj);
  v14 = TribeTacticalAIModule::calculatePriority(v3, *(float *)&buildinga);
  ((void (__stdcall *)(_DWORD, int, signed int, int, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, int))v3->md->player->vfptr->sendUnitAIOrder)(
    v3->md->player->id,
    builder,
    702,
    v5->id,
    v3->md->player->id,
    LODWORD(v5->world_x),
    LODWORD(v5->world_y),
    LODWORD(v5->world_z),
    1065353216,
    1,
    1,
    v14);
  return (RGE_Static_Object *)1;
}

//----- (004FA000) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::taskRepairer(TribeTacticalAIModule *this, int builder, RGE_Static_Object *building)
{
  TribeTacticalAIModule *v3; // esi@1
  int v4; // edi@1
  RGE_Static_Object *result; // eax@1
  RGE_Static_Object *v6; // ebp@1
  int v7; // ecx@3
  int i; // eax@3
  int v9; // ebp@8
  int *v10; // edi@8
  int j; // eax@9
  int v12; // eax@15
  RGE_Static_Object *builderObj; // [sp+18h] [bp-4h]@1
  int buildera; // [sp+20h] [bp+4h]@15

  v3 = this;
  v4 = builder;
  result = RGE_Game_World::object(this->md->player->world, builder);
  v6 = result;
  builderObj = result;
  if ( result )
  {
    result = (RGE_Static_Object *)(*((int (__thiscall **)(RGE_Static_Object *, int, signed int, _DWORD, signed int, signed int, signed int))&result->vfptr->pause
                                   + 1))(
                                    result,
                                    building->id,
                                    1065353216,
                                    0,
                                    1,
                                    -1,
                                    -1);
    if ( result )
    {
      v7 = v3->unitsTaskedThisUpdate.numberValue;
      for ( i = 0; i < v7; ++i )
      {
        if ( i >= v3->unitsTaskedThisUpdate.maximumSizeValue )
          break;
        if ( v3->unitsTaskedThisUpdate.value[i] == builder )
          goto LABEL_15;
      }
      if ( v7 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
      {
        v9 = v7 + 1;
        v10 = (int *)operator new(4 * (v7 + 1));
        if ( v10 )
        {
          for ( j = 0; j < v3->unitsTaskedThisUpdate.maximumSizeValue; v10[j - 1] = v3->unitsTaskedThisUpdate.value[j - 1] )
          {
            if ( j >= v9 )
              break;
            ++j;
          }
          operator delete(v3->unitsTaskedThisUpdate.value);
          v3->unitsTaskedThisUpdate.value = v10;
          v3->unitsTaskedThisUpdate.maximumSizeValue = v9;
        }
        v6 = builderObj;
        v4 = builder;
      }
      v3->unitsTaskedThisUpdate.value[v3->unitsTaskedThisUpdate.numberValue++] = v4;
LABEL_15:
      *(float *)&buildera = RGE_Static_Object::distance_to_object(building, v6);
      v12 = TribeTacticalAIModule::calculatePriority(v3, *(float *)&buildera);
      ((void (__stdcall *)(_DWORD, int, signed int, int, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, int))v3->md->player->vfptr->sendUnitAIOrder)(
        v3->md->player->id,
        v4,
        718,
        building->id,
        v3->md->player->id,
        LODWORD(building->world_x),
        LODWORD(building->world_y),
        LODWORD(building->world_z),
        1065353216,
        1,
        0,
        v12);
      result = (RGE_Static_Object *)1;
    }
  }
  return result;
}

//----- (004FA170) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::taskGatherer(TribeTacticalAIModule *this, int id, int resourceType, int limitedTaskLimit, unsigned int startTime, int *triedTasking)
{
  TribeTacticalAIModule *v6; // esi@1
  RGE_Static_Object *result; // eax@1
  RGE_Static_Object *v8; // ebx@1
  UnitData *v9; // eax@2
  int v10; // ebp@4
  int v11; // edi@6
  int *v12; // eax@7
  int *v13; // ebx@7
  TribeInformationAIModule *v14; // ecx@10
  bool v15; // sf@12
  unsigned __int8 v16; // of@12
  RGE_Static_ObjectVtbl *v17; // edx@14
  TribeInformationAIModule *v18; // ecx@20
  RGE_Static_ObjectVtbl *v19; // edx@21
  int v20; // eax@22
  int v21; // edx@28
  RGE_Static_Object *v22; // ebx@31
  RGE_Master_Static_Object *v23; // eax@36
  int v24; // eax@37
  signed __int64 v25; // rax@39
  TribeMainDecisionAIModule *v26; // ebx@40
  __int16 v27; // ax@43
  int v28; // eax@46
  int v29; // eax@53
  signed __int64 v30; // rax@55
  int v31; // edx@59
  int v32; // eax@59
  int *v33; // ecx@60
  int v34; // ebx@60
  int v35; // eax@68
  int v36; // eax@72
  int v37; // ecx@72
  int v38; // ebp@77
  int *v39; // ebx@77
  int i; // eax@78
  signed __int64 v41; // rax@84
  signed int v42; // ecx@95
  int v43; // ecx@100
  int v44; // ebp@103
  int v45; // esi@103
  int v46; // eax@103
  int v47; // ecx@103
  int v48; // ebx@108
  _DWORD *v49; // edi@108
  int j; // eax@109
  int v51; // [sp+0h] [bp-4Ch]@42
  int numStoragePits; // [sp+1Ch] [bp-30h]@6
  RGE_Static_Object *gathererObj; // [sp+20h] [bp-2Ch]@1
  float rYPos; // [sp+24h] [bp-28h]@6
  float rXPos; // [sp+28h] [bp-24h]@6
  int dropsiteID; // [sp+2Ch] [bp-20h]@10
  int numUnbuiltStoragePits; // [sp+30h] [bp-1Ch]@19
  int maximumResourceDistance; // [sp+34h] [bp-18h]@39
  int exclusions[5]; // [sp+38h] [bp-14h]@10
  int *triedTaskinga; // [sp+60h] [bp+14h]@19
  int *triedTaskingb; // [sp+60h] [bp+14h]@31

  v6 = this;
  result = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, id);
  v8 = result;
  gathererObj = result;
  if ( !result )
    return result;
  v9 = TribeTacticalAIModule::gatherer(v6, id);
  if ( v9 && v9->data2 > v9->data3 )
  {
    v10 = v9->data1;
    resourceType = v9->data1;
  }
  else
  {
    v10 = resourceType;
  }
  v11 = -1;
  rXPos = 0.0;
  rYPos = 0.0;
  numStoragePits = 0;
  if ( v10 == -1 )
  {
    numStoragePits = 0;
    v12 = triedTasking;
    v13 = v6->neededResourceValue;
    while ( 1 )
    {
      v10 = *v13;
      resourceType = *v13;
      if ( !v12 || v12[v10] != 1 )
      {
        v14 = &v6->md->informationAI;
        dropsiteID = -1;
        v11 = TribeInformationAIModule::gameIDOfResourceObject(v14, v10, id, &rXPos, &rYPos, &dropsiteID, exclusions, 0);
        if ( v11 != -1 )
        {
          v17 = gathererObj->vfptr;
          if ( dropsiteID == -1 )
            (*((void (__stdcall **)(int, signed int, _DWORD, signed int, signed int, signed int))&v17->pause + 1))(
              v11,
              1065353216,
              0,
              1,
              -1,
              -1);
          else
            ((void (__stdcall *)(int, int, signed int, _DWORD, signed int, signed int, signed int))v17->canBidirectionPath)(
              v11,
              dropsiteID,
              1065353216,
              0,
              1,
              -1,
              -1);
LABEL_17:
          if ( v11 == -1 )
            return 0;
LABEL_31:
          result = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, v11);
          v22 = result;
          triedTaskingb = (int *)result;
          if ( result )
          {
            if ( v6->sn[205] != 1 )
              goto LABEL_59;
            if ( v10 || v6->builtFirstGranary != 1 )
            {
              if ( v6->builtFirstStoragePit != 1 )
                goto LABEL_59;
              if ( v6->builtFirstGranary != 1 )
                goto LABEL_59;
              numStoragePits = 0;
              numUnbuiltStoragePits = 0;
              v29 = TribeTacticalAIModule::numberAvailableStoragePits(v6, &numStoragePits, &numUnbuiltStoragePits, v10);
              if ( numUnbuiltStoragePits )
                goto LABEL_59;
              if ( v29 <= 0 )
                goto LABEL_59;
              maximumResourceDistance = v6->sn[v22->attribute_type_held + 163];
              v30 = (signed __int64)RGE_Static_Object::distance_to_object(gathererObj, v22);
              if ( (signed int)v30 <= maximumResourceDistance )
              {
                if ( numStoragePits )
                  goto LABEL_59;
              }
            }
            else
            {
              if ( v6->builtFirstStoragePit != 1 )
                goto LABEL_59;
              v23 = result->master_obj;
              if ( v23->id == 59 )
              {
                numStoragePits = 0;
                numUnbuiltStoragePits = 0;
                v24 = TribeTacticalAIModule::numberAvailableGranaries(v6, &numStoragePits, &numUnbuiltStoragePits);
                if ( !numUnbuiltStoragePits && v24 > 0 )
                {
                  maximumResourceDistance = v6->sn[163];
                  v25 = (signed __int64)RGE_Static_Object::distance_to_object(gathererObj, v22);
                  if ( (signed int)v25 > maximumResourceDistance )
                  {
                    v26 = v6->md;
                    if ( v26->informationAI.closestDropsiteValue[0] != -1
                      && TribeInformationAIModule::acceptablePotentialDropsiteArea(
                           &v26->informationAI,
                           (signed __int64)*((float *)triedTaskingb + 14),
                           (signed __int64)*((float *)triedTaskingb + 15)) == 1 )
                    {
                      v51 = 68;
                      goto LABEL_58;
                    }
                  }
                }
                goto LABEL_59;
              }
              v27 = v23->object_group;
              if ( v27 == 31 )
                goto LABEL_59;
              if ( v27 == 5 )
                goto LABEL_59;
              if ( v27 == 33 )
                goto LABEL_59;
              numStoragePits = 0;
              numUnbuiltStoragePits = 0;
              v28 = TribeTacticalAIModule::numberAvailableStoragePits(v6, &numStoragePits, &numUnbuiltStoragePits, 0);
              if ( numUnbuiltStoragePits
                || v28 <= 0
                || (signed int)(signed __int64)RGE_Static_Object::distance_to_object(gathererObj, v22) <= 15
                && numStoragePits )
              {
                goto LABEL_59;
              }
            }
            v51 = 103;
LABEL_58:
            TribeBuildAIModule::insert(&v6->md->buildAI, v51, 1, -1);
LABEL_59:
            v31 = v6->civilianExplorers.maximumSizeValue;
            v32 = 0;
            if ( v31 <= 0 )
            {
              v34 = id;
            }
            else
            {
              v33 = v6->civilianExplorers.value;
              v34 = id;
              do
              {
                if ( *v33 == id )
                  break;
                ++v32;
                ++v33;
              }
              while ( v32 < v31 );
            }
            if ( v32 < v31 )
            {
              if ( v32 < v31 - 1 )
              {
                do
                {
                  ++v32;
                  v6->civilianExplorers.value[v32 - 1] = v6->civilianExplorers.value[v32];
                }
                while ( v32 < v6->civilianExplorers.maximumSizeValue - 1 );
              }
              v35 = v6->civilianExplorers.numberValue - 1;
              v6->civilianExplorers.numberValue = v35;
              if ( v35 < 0 )
                v6->civilianExplorers.numberValue = 0;
            }
            numUnbuiltStoragePits = (int)TribeTacticalAIModule::addGatherer(v6, v34);
            if ( numUnbuiltStoragePits )
            {
              v36 = 0;
              ++v6->actualGathererDistribution[v10];
              v37 = v6->unitsTaskedThisUpdate.numberValue;
              if ( v37 > 0 )
              {
                do
                {
                  if ( v36 >= v6->unitsTaskedThisUpdate.maximumSizeValue )
                    break;
                  if ( v6->unitsTaskedThisUpdate.value[v36] == id )
                    goto LABEL_84;
                  ++v36;
                }
                while ( v36 < v37 );
              }
              if ( v37 > v6->unitsTaskedThisUpdate.maximumSizeValue - 1 )
              {
                v38 = v37 + 1;
                v39 = (int *)operator new(4 * (v37 + 1));
                if ( v39 )
                {
                  for ( i = 0;
                        i < v6->unitsTaskedThisUpdate.maximumSizeValue;
                        v39[i - 1] = v6->unitsTaskedThisUpdate.value[i - 1] )
                  {
                    if ( i >= v38 )
                      break;
                    ++i;
                  }
                  operator delete(v6->unitsTaskedThisUpdate.value);
                  v6->unitsTaskedThisUpdate.value = v39;
                  v6->unitsTaskedThisUpdate.maximumSizeValue = v38;
                }
                v10 = resourceType;
              }
              v6->unitsTaskedThisUpdate.value[v6->unitsTaskedThisUpdate.numberValue++] = id;
LABEL_84:
              *(_DWORD *)(numUnbuiltStoragePits + 4) = v10;
              LODWORD(v41) = TribeTacticalAIModule::requiredGatherAmount(v6, v10);
              if ( limitedTaskLimit == 1 )
              {
                LODWORD(v41) = 10;
              }
              else
              {
                if ( v6->sn[203] == 1 )
                {
                  if ( *(_WORD *)(triedTaskingb[2] + 16) == 59 )
                  {
                    v41 = (signed __int64)*((float *)triedTaskingb + 17);
                  }
                  else
                  {
                    switch ( v10 )
                    {
                      case 1:
                        LODWORD(v41) = 75;
                        break;
                      case 3:
                        LODWORD(v41) = 50;
                        break;
                      case 2:
                        LODWORD(v41) = 50;
                        break;
                    }
                  }
                }
                else
                {
                  v42 = v6->sn[148];
                  if ( (signed int)v41 < v42 || (v42 = v6->sn[149], (signed int)v41 > v42) )
                    LODWORD(v41) = v42;
                }
                if ( v6->zoomingToNextAge == 1 )
                  LODWORD(v41) = 20;
              }
              v43 = numUnbuiltStoragePits;
              *(_DWORD *)(numUnbuiltStoragePits + 8) = v41;
              *(_DWORD *)(v43 + 12) = 0;
              ((void (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD))v6->md->aiPlayer->vfptr[1].loadAIInformation)(
                id,
                v11,
                *(_WORD *)(triedTaskingb[3] + 74),
                LODWORD(rXPos),
                LODWORD(rYPos));
              if ( *(_WORD *)(triedTaskingb[2] + 16) == 48 )
                TribeTacticalAIModule::taskElephantGatherers(v6, id, v6->sn[204] - 1, v11);
              if ( *(_WORD *)(triedTaskingb[2] + 16) == 50 )
              {
                v44 = triedTaskingb[1];
                v45 = (int)&v6->md->informationAI.farmsTaskedThisUpdate;
                v46 = 0;
                v47 = *(_DWORD *)(v45 + 4);
                if ( v47 > 0 )
                {
                  do
                  {
                    if ( v46 >= *(_DWORD *)(v45 + 12) )
                      break;
                    if ( *(_DWORD *)(*(_DWORD *)v45 + 4 * v46) == v44 )
                      goto LABEL_114;
                    ++v46;
                  }
                  while ( v46 < v47 );
                }
                if ( v47 > *(_DWORD *)(v45 + 12) - 1 )
                {
                  v48 = v47 + 1;
                  v49 = operator new(4 * (v47 + 1));
                  if ( v49 )
                  {
                    for ( j = 0; j < *(_DWORD *)(v45 + 12); v49[j - 1] = *(_DWORD *)(*(_DWORD *)v45 + 4 * j - 4) )
                    {
                      if ( j >= v48 )
                        break;
                      ++j;
                    }
                    operator delete(*(void **)v45);
                    *(_DWORD *)v45 = v49;
                    *(_DWORD *)(v45 + 12) = v48;
                  }
                }
                *(_DWORD *)(*(_DWORD *)v45 + 4 * (*(_DWORD *)(v45 + 4))++) = v44;
              }
LABEL_114:
              result = (RGE_Static_Object *)1;
            }
            else
            {
LABEL_71:
              result = 0;
            }
          }
          return result;
        }
        v12 = triedTasking;
      }
      ++v13;
      v16 = __OFSUB__(numStoragePits + 1, 4);
      v15 = numStoragePits++ - 3 < 0;
      if ( !(v15 ^ v16) )
        goto LABEL_17;
    }
  }
  numUnbuiltStoragePits = 0;
  triedTaskinga = exclusions;
  do
  {
    v18 = &v6->md->informationAI;
    dropsiteID = -1;
    v11 = TribeInformationAIModule::gameIDOfResourceObject(
            v18,
            v10,
            id,
            &rXPos,
            &rYPos,
            &dropsiteID,
            exclusions,
            numStoragePits);
    if ( v11 == -1 )
      goto LABEL_71;
    v19 = v8->vfptr;
    if ( dropsiteID == -1 )
      v20 = (*((int (__thiscall **)(RGE_Static_Object *, int, signed int, _DWORD, signed int, signed int, signed int))&v19->pause
             + 1))(
              v8,
              v11,
              1065353216,
              0,
              1,
              -1,
              -1);
    else
      v20 = ((int (__thiscall *)(RGE_Static_Object *, int, int, signed int, _DWORD, signed int, signed int, signed int))v19->canBidirectionPath)(
              v8,
              v11,
              dropsiteID,
              1065353216,
              0,
              1,
              -1,
              -1);
    if ( v20 )
      break;
    if ( v10 )
      TribeInformationAIModule::setResourceObjectValid(&v6->md->informationAI, v10, v11, 15);
    else
      TribeInformationAIModule::setResourceObjectValid(&v6->md->informationAI, 0, v11, 2);
    v21 = numStoragePits + 1;
    *triedTaskinga = v11;
    ++triedTaskinga;
    v11 = -1;
    v16 = __OFSUB__(numUnbuiltStoragePits + 1, 3);
    v15 = numUnbuiltStoragePits - 2 < 0;
    numStoragePits = v21;
    ++numUnbuiltStoragePits;
  }
  while ( v15 ^ v16 );
  if ( v11 >= 0 )
    goto LABEL_31;
  return 0;
}

//----- (004FA820) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskExplorer(TribeTacticalAIModule *this, int eID, int civilian)
{
  int v3; // eax@1
  TribeTacticalAIModule *v4; // esi@1
  int v5; // ecx@1
  int v6; // ebx@6
  int *v7; // edi@6
  int i; // eax@7
  RGE_Static_Object *v9; // eax@13
  float y; // ST08_4@14
  float x; // ST04_4@14
  int v13; // [sp+8h] [bp-1Ch]@13
  XYPoint targetPoint; // [sp+1Ch] [bp-8h]@13

  v3 = 0;
  v4 = this;
  v5 = this->unitsTaskedThisUpdate.numberValue;
  if ( v5 > 0 )
  {
    do
    {
      if ( v3 >= v4->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v4->unitsTaskedThisUpdate.value[v3] == eID )
        goto LABEL_12;
      ++v3;
    }
    while ( v3 < v5 );
  }
  if ( v5 > v4->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v6 = v5 + 1;
    v7 = (int *)operator new(4 * (v5 + 1));
    if ( v7 )
    {
      for ( i = 0; i < v4->unitsTaskedThisUpdate.maximumSizeValue; v7[i - 1] = v4->unitsTaskedThisUpdate.value[i - 1] )
      {
        if ( i >= v6 )
          break;
        ++i;
      }
      operator delete(v4->unitsTaskedThisUpdate.value);
      v4->unitsTaskedThisUpdate.value = v7;
      v4->unitsTaskedThisUpdate.maximumSizeValue = v6;
    }
  }
  v4->unitsTaskedThisUpdate.value[v4->unitsTaskedThisUpdate.numberValue++] = eID;
LABEL_12:
  if ( civilian == 1 )
  {
    v9 = TribeTacticalAIModule::unexploredArea(v4, eID, &targetPoint);
    v13 = 1;
    if ( v9 == (RGE_Static_Object *)1 )
    {
      y = (double)targetPoint.y;
      x = (double)targetPoint.x;
      return TribeTacticalAIModule::taskExplorer(v4, eID, x, y, 1);
    }
  }
  else
  {
    v13 = 0;
  }
  return TribeTacticalAIModule::taskExplorer(v4, eID, -1.0, -1.0, v13);
}

//----- (004FA940) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskExplorer(TribeTacticalAIModule *this, int eID, float x, float y)
{
  int v4; // eax@1
  TribeTacticalAIModule *v5; // esi@1
  int v6; // ecx@1
  int v7; // ebx@6
  int *v8; // edi@6
  int i; // eax@7
  int v10; // ecx@12
  int v11; // eax@12
  int result; // eax@16
  float v13; // ST08_4@18
  float v14; // ST04_4@18
  XYPoint targetPoint; // [sp+1Ch] [bp-8h]@17

  v4 = 0;
  v5 = this;
  v6 = this->unitsTaskedThisUpdate.numberValue;
  if ( v6 > 0 )
  {
    do
    {
      if ( v4 >= v5->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v5->unitsTaskedThisUpdate.value[v4] == eID )
        goto LABEL_12;
      ++v4;
    }
    while ( v4 < v6 );
  }
  if ( v6 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v7 = v6 + 1;
    v8 = (int *)operator new(4 * (v6 + 1));
    if ( v8 )
    {
      for ( i = 0; i < v5->unitsTaskedThisUpdate.maximumSizeValue; v8[i - 1] = v5->unitsTaskedThisUpdate.value[i - 1] )
      {
        if ( i >= v7 )
          break;
        ++i;
      }
      operator delete(v5->unitsTaskedThisUpdate.value);
      v5->unitsTaskedThisUpdate.value = v8;
      v5->unitsTaskedThisUpdate.maximumSizeValue = v7;
    }
  }
  v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = eID;
LABEL_12:
  v10 = v5->civilians.numberValue;
  v11 = 0;
  if ( v10 > 0 )
  {
    while ( v11 < v5->civilians.maximumSizeValue )
    {
      if ( v5->civilians.value[v11] == eID )
      {
        if ( TribeTacticalAIModule::unexploredArea(v5, eID, &targetPoint) == (RGE_Static_Object *)1 )
        {
          v13 = (double)targetPoint.y;
          v14 = (double)targetPoint.x;
          result = TribeTacticalAIModule::taskExplorer(v5, eID, v14, v13, 1);
        }
        else
        {
          result = TribeTacticalAIModule::taskExplorer(v5, eID, x, y, 1);
        }
        return result;
      }
      if ( ++v11 >= v10 )
        return TribeTacticalAIModule::taskExplorer(v5, eID, x, y, 0);
    }
  }
  return TribeTacticalAIModule::taskExplorer(v5, eID, x, y, 0);
}

//----- (004FAAA0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskExplorer(TribeTacticalAIModule *this, int eID, float x, float y, int civilian)
{
  TribeTacticalAIModule *v5; // esi@1
  int v6; // eax@1
  int v7; // ecx@1
  int v8; // ebx@6
  int *v9; // edi@6
  int i; // eax@7
  int v11; // ecx@13
  int j; // eax@13
  int v13; // ecx@17
  int k; // eax@17
  int v15; // ebx@22
  int *v16; // edi@22
  int l; // eax@23

  v5 = this;
  v6 = 0;
  v7 = this->unitsTaskedThisUpdate.numberValue;
  if ( v7 > 0 )
  {
    do
    {
      if ( v6 >= v5->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v5->unitsTaskedThisUpdate.value[v6] == eID )
        goto LABEL_12;
      ++v6;
    }
    while ( v6 < v7 );
  }
  if ( v7 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v8 = v7 + 1;
    v9 = (int *)operator new(4 * (v7 + 1));
    if ( v9 )
    {
      for ( i = 0; i < v5->unitsTaskedThisUpdate.maximumSizeValue; v9[i - 1] = v5->unitsTaskedThisUpdate.value[i - 1] )
      {
        if ( i >= v8 )
          break;
        ++i;
      }
      operator delete(v5->unitsTaskedThisUpdate.value);
      v5->unitsTaskedThisUpdate.value = v9;
      v5->unitsTaskedThisUpdate.maximumSizeValue = v8;
    }
  }
  v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = eID;
LABEL_12:
  if ( civilian == 1 )
  {
    v11 = v5->civilianExplorers.numberValue;
    for ( j = 0; j < v11; ++j )
    {
      if ( j >= v5->civilianExplorers.maximumSizeValue )
        break;
      if ( v5->civilianExplorers.value[j] == eID )
        goto LABEL_28;
    }
    v13 = v5->civilianExplorers.numberValue;
    for ( k = 0; k < v13; ++k )
    {
      if ( k >= v5->civilianExplorers.maximumSizeValue )
        break;
      if ( v5->civilianExplorers.value[k] == eID )
        goto LABEL_28;
    }
    if ( v13 > v5->civilianExplorers.maximumSizeValue - 1 )
    {
      v15 = v13 + 1;
      v16 = (int *)operator new(4 * (v13 + 1));
      if ( v16 )
      {
        for ( l = 0; l < v5->civilianExplorers.maximumSizeValue; v16[l - 1] = v5->civilianExplorers.value[l - 1] )
        {
          if ( l >= v15 )
            break;
          ++l;
        }
        operator delete(v5->civilianExplorers.value);
        v5->civilianExplorers.value = v16;
        v5->civilianExplorers.maximumSizeValue = v15;
      }
    }
    v5->civilianExplorers.value[v5->civilianExplorers.numberValue++] = eID;
LABEL_28:
    TribeTacticalAIModule::removeGatherer(v5, eID);
  }
  ((void (__stdcall *)(_DWORD, int, signed int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, signed int))v5->md->player->vfptr->sendUnitAIOrder)(
    v5->md->player->id,
    eID,
    705,
    -1,
    -1,
    LODWORD(x),
    LODWORD(y),
    -1082130432,
    1065353216,
    1,
    0,
    1);
  return 1;
}

//----- (004FAC90) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskFollower(TribeTacticalAIModule *this, int uID, int tID, float range, int priority)
{
  TribeTacticalAIModule *v5; // esi@1
  int v6; // eax@1
  int v7; // ecx@1
  int v8; // ebx@6
  int *v9; // edi@6
  int i; // eax@7

  v5 = this;
  v6 = 0;
  v7 = this->unitsTaskedThisUpdate.numberValue;
  if ( v7 > 0 )
  {
    do
    {
      if ( v6 >= v5->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v5->unitsTaskedThisUpdate.value[v6] == uID )
        goto LABEL_12;
      ++v6;
    }
    while ( v6 < v7 );
  }
  if ( v7 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v8 = v7 + 1;
    v9 = (int *)operator new(4 * (v7 + 1));
    if ( v9 )
    {
      for ( i = 0; i < v5->unitsTaskedThisUpdate.maximumSizeValue; v9[i - 1] = v5->unitsTaskedThisUpdate.value[i - 1] )
      {
        if ( i >= v8 )
          break;
        ++i;
      }
      operator delete(v5->unitsTaskedThisUpdate.value);
      v5->unitsTaskedThisUpdate.value = v9;
      v5->unitsTaskedThisUpdate.maximumSizeValue = v8;
    }
  }
  v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = uID;
LABEL_12:
  ((void (__stdcall *)(_DWORD, int, signed int, int, signed int, signed int, signed int, signed int, _DWORD, signed int, _DWORD, int))v5->md->player->vfptr->sendUnitAIOrder)(
    v5->md->player->id,
    uID,
    712,
    tID,
    -1,
    -1082130432,
    -1082130432,
    -1082130432,
    LODWORD(range),
    1,
    0,
    priority);
  return 1;
}

//----- (004FADA0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskDefender(TribeTacticalAIModule *this, int uID, int tID, float range, int priority)
{
  TribeTacticalAIModule *v5; // esi@1
  int v6; // eax@1
  int v7; // ecx@1
  int v8; // ebx@6
  int *v9; // edi@6
  int i; // eax@7

  v5 = this;
  v6 = 0;
  v7 = this->unitsTaskedThisUpdate.numberValue;
  if ( v7 > 0 )
  {
    do
    {
      if ( v6 >= v5->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v5->unitsTaskedThisUpdate.value[v6] == uID )
        goto LABEL_12;
      ++v6;
    }
    while ( v6 < v7 );
  }
  if ( v7 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v8 = v7 + 1;
    v9 = (int *)operator new(4 * (v7 + 1));
    if ( v9 )
    {
      for ( i = 0; i < v5->unitsTaskedThisUpdate.maximumSizeValue; v9[i - 1] = v5->unitsTaskedThisUpdate.value[i - 1] )
      {
        if ( i >= v8 )
          break;
        ++i;
      }
      operator delete(v5->unitsTaskedThisUpdate.value);
      v5->unitsTaskedThisUpdate.value = v9;
      v5->unitsTaskedThisUpdate.maximumSizeValue = v8;
    }
  }
  v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = uID;
LABEL_12:
  ((void (__stdcall *)(_DWORD, int, signed int, int, signed int, signed int, signed int, signed int, _DWORD, signed int, _DWORD, int))v5->md->player->vfptr->sendUnitAIOrder)(
    v5->md->player->id,
    uID,
    701,
    tID,
    -1,
    -1082130432,
    -1082130432,
    -1082130432,
    LODWORD(range),
    1,
    0,
    priority);
  return 1;
}

//----- (004FAEB0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskWaterExplorer(TribeTacticalAIModule *this, int explorer)
{
  TribeTacticalAIModule *v2; // esi@1
  int result; // eax@2
  int v4; // ecx@3
  int i; // eax@3
  int v6; // ebx@8
  int *v7; // edi@8
  int j; // eax@9

  v2 = this;
  if ( explorer == -1 )
  {
    result = 0;
  }
  else
  {
    v4 = this->unitsTaskedThisUpdate.numberValue;
    for ( i = 0; i < v4; ++i )
    {
      if ( i >= v2->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v2->unitsTaskedThisUpdate.value[i] == explorer )
        goto LABEL_14;
    }
    if ( v4 > v2->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v6 = v4 + 1;
      v7 = (int *)operator new(4 * (v4 + 1));
      if ( v7 )
      {
        for ( j = 0; j < v2->unitsTaskedThisUpdate.maximumSizeValue; v7[j - 1] = v2->unitsTaskedThisUpdate.value[j - 1] )
        {
          if ( j >= v6 )
            break;
          ++j;
        }
        operator delete(v2->unitsTaskedThisUpdate.value);
        v2->unitsTaskedThisUpdate.value = v7;
        v2->unitsTaskedThisUpdate.maximumSizeValue = v6;
      }
    }
    v2->unitsTaskedThisUpdate.value[v2->unitsTaskedThisUpdate.numberValue++] = explorer;
LABEL_14:
    ((void (__stdcall *)(_DWORD, int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v2->md->player->vfptr->sendUnitAIOrder)(
      v2->md->player->id,
      explorer,
      705,
      -1,
      -1,
      -1082130432,
      -1082130432,
      -1082130432,
      1065353216,
      1,
      0,
      1);
    result = 1;
  }
  return result;
}

//----- (004FAFC0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskWaterTrader(TribeTacticalAIModule *this, int unitID, int targetID)
{
  TribeTacticalAIModule *v3; // esi@1
  RGE_Static_Object *v4; // eax@1
  RGE_Static_Object *v5; // edi@1
  RGE_Static_Object *v6; // eax@3
  int v7; // ecx@5
  int i; // eax@5
  int v9; // ebx@10
  int *v10; // edi@10
  int j; // eax@11
  int result; // eax@16
  RGE_Static_Object *targetObj; // [sp+24h] [bp-4h]@3

  v3 = this;
  v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID);
  v5 = v4;
  if ( unitID != -1
    && v4
    && (v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, targetID), (targetObj = v6) != 0)
    && ((int (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, signed int, int, _DWORD, signed int, signed int, signed int))v5->vfptr->canPath)(
         v5,
         (signed __int64)v6->world_x,
         (signed __int64)v6->world_y,
         (signed __int64)v6->world_z,
         0x40000000,
         targetID,
         0,
         1,
         -1,
         -1) )
  {
    v7 = v3->unitsTaskedThisUpdate.numberValue;
    for ( i = 0; i < v7; ++i )
    {
      if ( i >= v3->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v3->unitsTaskedThisUpdate.value[i] == unitID )
        goto LABEL_16;
    }
    if ( v7 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v9 = v7 + 1;
      v10 = (int *)operator new(4 * (v7 + 1));
      if ( v10 )
      {
        for ( j = 0; j < v3->unitsTaskedThisUpdate.maximumSizeValue; v10[j - 1] = v3->unitsTaskedThisUpdate.value[j - 1] )
        {
          if ( j >= v9 )
            break;
          ++j;
        }
        operator delete(v3->unitsTaskedThisUpdate.value);
        v3->unitsTaskedThisUpdate.value = v10;
        v3->unitsTaskedThisUpdate.maximumSizeValue = v9;
      }
    }
    v3->unitsTaskedThisUpdate.value[v3->unitsTaskedThisUpdate.numberValue++] = unitID;
LABEL_16:
    ((void (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD))v3->md->aiPlayer->vfptr[1].loadAIInformation)(
      unitID,
      targetID,
      targetObj->owner->id,
      LODWORD(targetObj->world_x),
      LODWORD(targetObj->world_y));
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FB160) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskWaterFisher(TribeTacticalAIModule *this, int unitID, int targetID, float x, float y)
{
  TribeTacticalAIModule *v5; // esi@1
  RGE_Static_Object *v6; // eax@1
  RGE_Static_Object *v7; // edi@1
  signed __int64 v8; // rax@3
  int v9; // ecx@4
  int v10; // eax@4
  int v11; // ebp@5
  int v12; // ebx@12
  int *v13; // edi@12
  int i; // eax@13
  RGE_PlayerVtbl **v15; // ecx@18
  RGE_PlayerVtbl *v16; // eax@18
  int result; // eax@18
  int v18; // [sp-10h] [bp-30h]@3
  signed int v19; // [sp-Ch] [bp-2Ch]@3
  signed int v20; // [sp-8h] [bp-28h]@3
  signed int v21; // [sp-4h] [bp-24h]@3
  int v22; // [sp+0h] [bp-20h]@3
  signed int v23; // [sp+4h] [bp-1Ch]@3
  float v24; // [sp+8h] [bp-18h]@3
  float v25; // [sp+Ch] [bp-14h]@3

  v5 = this;
  v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID);
  v7 = v6;
  if ( unitID != -1
    && v6
    && (v8 = (signed __int64)y,
        v25 = -6.8056469e38/*NaN*/,
        v24 = -6.8056469e38/*NaN*/,
        v23 = 1,
        HIDWORD(v8) = v7->vfptr,
        v22 = 0,
        v21 = -1,
        v20 = 1065353216,
        v18 = (signed __int64)y,
        v19 = 1,
        (*(int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, signed int, signed int, signed int))(HIDWORD(v8) + 408))(
          v7,
          (signed __int64)x,
          v8,
          1,
          1065353216,
          -1,
          0,
          1,
          -1,
          -1)) )
  {
    v9 = v5->unitsTaskedThisUpdate.numberValue;
    v10 = 0;
    if ( v9 <= 0 )
    {
      v11 = unitID;
    }
    else
    {
      v11 = unitID;
      do
      {
        if ( v10 >= v5->unitsTaskedThisUpdate.maximumSizeValue )
          break;
        if ( v5->unitsTaskedThisUpdate.value[v10] == unitID )
          goto LABEL_18;
        ++v10;
      }
      while ( v10 < v9 );
    }
    if ( v9 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v12 = v9 + 1;
      v13 = (int *)operator new(4 * (v9 + 1));
      if ( v13 )
      {
        for ( i = 0; i < v5->unitsTaskedThisUpdate.maximumSizeValue; v13[i - 1] = v5->unitsTaskedThisUpdate.value[i - 1] )
        {
          if ( i >= v12 )
            break;
          ++i;
        }
        operator delete(v5->unitsTaskedThisUpdate.value);
        v5->unitsTaskedThisUpdate.value = v13;
        v5->unitsTaskedThisUpdate.maximumSizeValue = v12;
      }
    }
    v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = v11;
LABEL_18:
    v15 = &v5->md->aiPlayer->vfptr;
    v25 = y;
    v16 = *v15;
    v24 = x;
    v23 = 0;
    v22 = targetID;
    v21 = v11;
    ((void (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD))v16[1].loadAIInformation)(
      v11,
      targetID,
      0,
      LODWORD(x),
      LODWORD(y));
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FB2D0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskAttacker(TribeTacticalAIModule *this, int soldierID, float xLocation, float yLocation, int targetID, int targetOwner, Waypoint *path, int pathLength, int commanderID, int idleAttackRoundup)
{
  TribeTacticalAIModule *v10; // esi@1
  RGE_Static_Object *v11; // eax@2
  RGE_Static_Object *v12; // ebp@2
  Waypoint *v13; // edi@4
  int v14; // ebx@5
  RGE_Static_Object *v15; // eax@8
  long double v16; // st7@9
  int v17; // eax@9
  TribeMainDecisionAIModule *v18; // ecx@9
  RGE_Player *v19; // ebx@9
  float v20; // ST20_4@9
  int v21; // ebp@9
  int v22; // eax@10
  int v23; // ecx@11
  int i; // eax@11
  int v25; // ebx@16
  int *v26; // edi@16
  int j; // eax@17
  int targetIDa; // [sp+3Ch] [bp+10h]@10
  Waypoint *patha; // [sp+44h] [bp+18h]@9
  Waypoint *pathb; // [sp+44h] [bp+18h]@9

  v10 = this;
  if ( soldierID == -1 )
    return 0;
  v11 = RGE_Game_World::object(this->md->player->world, soldierID);
  v12 = v11;
  if ( !v11 || !RGE_Static_Object::unitAI(v11) )
    return 0;
  v13 = path;
  if ( path )
  {
    v14 = pathLength;
    if ( pathLength > 0 )
    {
      do
      {
        TribeTacticalAIModule::addWaypoint(v10, soldierID, (signed __int64)v13->x, (signed __int64)v13->y);
        ++v13;
        --v14;
      }
      while ( v14 );
    }
  }
  if ( targetID == -1 )
  {
    *(float *)&targetIDa = RGE_Static_Object::distance_to_position(v12, xLocation, yLocation, 1.0);
    v22 = TribeTacticalAIModule::calculatePriority(v10, *(float *)&targetIDa);
    v21 = soldierID;
    TribeTacticalAIModule::moveUnit(v10, soldierID, xLocation, yLocation, v22);
    goto LABEL_11;
  }
  v15 = RGE_Game_World::object(v10->md->player->world, targetID);
  if ( !v15 )
    return 0;
  v16 = RGE_Static_Object::distance_to_object(v12, v15);
  *(float *)&patha = v16;
  v17 = TribeTacticalAIModule::calculatePriority(v10, *(float *)&patha);
  v18 = v10->md;
  v19 = v18->player;
  pathb = (Waypoint *)v18->player->vfptr;
  ((void (__thiscall *)(RGE_Static_Object *, signed int, _DWORD, int))v12->vfptr->weaponRange)(v12, 1, 0, v17);
  v20 = v16;
  (*(void (__thiscall **)(RGE_Player *, _DWORD, int, signed int, int, int, int, Waypoint *, signed int, _DWORD))(idleAttackRoundup + 48))(
    v19,
    v19->id,
    targetID,
    idleAttackRoundup != 1 ? 700 : 729,
    pathLength,
    commanderID,
    targetOwner,
    pathb,
    1065353216,
    LODWORD(v20));
  v21 = soldierID;
LABEL_11:
  v23 = v10->unitsTaskedThisUpdate.numberValue;
  for ( i = 0; i < v23; ++i )
  {
    if ( i >= v10->unitsTaskedThisUpdate.maximumSizeValue )
      break;
    if ( v10->unitsTaskedThisUpdate.value[i] == v21 )
      return 1;
  }
  if ( v23 > v10->unitsTaskedThisUpdate.maximumSizeValue - 1 )
  {
    v25 = v23 + 1;
    v26 = (int *)operator new(4 * (v23 + 1));
    if ( v26 )
    {
      for ( j = 0; j < v10->unitsTaskedThisUpdate.maximumSizeValue; v26[j - 1] = v10->unitsTaskedThisUpdate.value[j - 1] )
      {
        if ( j >= v25 )
          break;
        ++j;
      }
      operator delete(v10->unitsTaskedThisUpdate.value);
      v10->unitsTaskedThisUpdate.value = v26;
      v10->unitsTaskedThisUpdate.maximumSizeValue = v25;
    }
  }
  v10->unitsTaskedThisUpdate.value[v10->unitsTaskedThisUpdate.numberValue++] = v21;
  return 1;
}

//----- (004FB500) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskDefender(TribeTacticalAIModule *this, int defender, int targetID)
{
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aErrorUnusedTas, defender, targetID);
  return 0;
}

//----- (004FB520) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskDefender(TribeTacticalAIModule *this, int defender, float x, float y)
{
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aErrorUnusedT_1, defender, x, y);
  return 0;
}

//----- (004FB550) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskTrain(TribeTacticalAIModule *this, BuildItem *trainItem)
{
  BuildItem *v2; // ebx@1
  TribeTacticalAIModule *v3; // esi@1
  int result; // eax@2
  int v5; // eax@3
  RGE_Static_Object *v6; // eax@3
  void *v7; // edi@3
  int v8; // ST14_4@5
  int v9; // ST10_4@5
  int v10; // eax@5
  int v11; // ecx@5
  int v12; // edx@5
  int v13; // eax@5
  int v14; // ebp@10
  int *v15; // edi@10
  int j; // eax@11
  RGE_PlayerVtbl *v17; // ebp@17
  int v18; // ST14_4@17
  int v19; // ST10_4@17
  int v20; // eax@17
  int v21; // ST14_4@18
  int v22; // eax@18
  int i; // [sp+10h] [bp-4h]@5
  BuildItem *trainItema; // [sp+18h] [bp+4h]@3

  v2 = trainItem;
  v3 = this;
  if ( trainItem )
  {
    v5 = BuildItem::buildFrom(trainItem);
    v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, -1, v5, -1, 619, 620, 2);
    v7 = v6;
    trainItema = (BuildItem *)v6;
    if ( v6 && RGE_Static_Object::unitAI(v6) )
    {
      v8 = *((_DWORD *)v7 + 1);
      v9 = BaseItem::uniqueID((BaseItem *)&v2->vfptr);
      v10 = BaseItem::typeID((BaseItem *)&v2->vfptr);
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aTrainingIdDUni, v10, v9, v8);
      BuildItem::setInProgress(v2, 1);
      BuildItem::setBuilt(v2, 0);
      v11 = v3->unitsTaskedThisUpdate.numberValue;
      v12 = *((_DWORD *)v7 + 1);
      v13 = 0;
      for ( i = *((_DWORD *)v7 + 1); v13 < v11; ++v13 )
      {
        if ( v13 >= v3->unitsTaskedThisUpdate.maximumSizeValue )
          break;
        if ( v3->unitsTaskedThisUpdate.value[v13] == v12 )
          goto LABEL_17;
      }
      if ( v11 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
      {
        v14 = v11 + 1;
        v15 = (int *)operator new(4 * (v11 + 1));
        if ( v15 )
        {
          for ( j = 0; j < v3->unitsTaskedThisUpdate.maximumSizeValue; v15[j - 1] = v3->unitsTaskedThisUpdate.value[j - 1] )
          {
            if ( j >= v14 )
              break;
            ++j;
          }
          operator delete(v3->unitsTaskedThisUpdate.value);
          v3->unitsTaskedThisUpdate.value = v15;
          v3->unitsTaskedThisUpdate.maximumSizeValue = v14;
        }
        v7 = trainItema;
        v12 = i;
      }
      v3->unitsTaskedThisUpdate.value[v3->unitsTaskedThisUpdate.numberValue++] = v12;
LABEL_17:
      v17 = v3->md->aiPlayer->vfptr;
      v18 = BaseItem::uniqueID((BaseItem *)&v2->vfptr);
      v19 = *((_DWORD *)v7 + 1);
      v20 = BaseItem::typeID((BaseItem *)&v2->vfptr);
      (*(void (__thiscall **)(TRIBE_Player *, int, int, int))&v17[1].gap4[12])(v3->md->aiPlayer, v20, v19, v18);
      result = 1;
    }
    else
    {
      v21 = BaseItem::uniqueID((BaseItem *)&v2->vfptr);
      v22 = BaseItem::typeID((BaseItem *)&v2->vfptr);
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aCouldNotFindAB, v22, v21);
      result = 0;
    }
  }
  else
  {
    AIModule::logCommonHistory((AIModule *)&this->vfptr, aInvalidTasktra);
    result = 0;
  }
  return result;
}

//----- (004FB710) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskResearch(TribeTacticalAIModule *this, BuildItem *researchItem)
{
  BuildItem *v2; // ebx@1
  TribeTacticalAIModule *v3; // esi@1
  int result; // eax@2
  int v5; // eax@3
  RGE_Static_Object *v6; // eax@3
  void *v7; // edi@3
  int v8; // ST14_4@5
  int v9; // ST10_4@5
  int v10; // eax@5
  int v11; // ecx@5
  int v12; // edx@5
  int v13; // eax@5
  int v14; // ebp@10
  int *v15; // edi@10
  int j; // eax@11
  RGE_PlayerVtbl *v17; // ebp@17
  int v18; // ST14_4@17
  int v19; // ST10_4@17
  int v20; // eax@17
  int v21; // ST14_4@18
  int v22; // eax@18
  int i; // [sp+10h] [bp-4h]@5
  BuildItem *researchItema; // [sp+18h] [bp+4h]@3

  v2 = researchItem;
  v3 = this;
  if ( researchItem )
  {
    v5 = BuildItem::buildFrom(researchItem);
    v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, -1, v5, -1, 619, 620, 2);
    v7 = v6;
    researchItema = (BuildItem *)v6;
    if ( v6 && RGE_Static_Object::unitAI(v6) )
    {
      v8 = *((_DWORD *)v7 + 1);
      v9 = BaseItem::uniqueID((BaseItem *)&v2->vfptr);
      v10 = BaseItem::typeID((BaseItem *)&v2->vfptr);
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aResearchingIdD, v10, v9, v8);
      BuildItem::setInProgress(v2, 1);
      BuildItem::setBuilt(v2, 0);
      v11 = v3->unitsTaskedThisUpdate.numberValue;
      v12 = *((_DWORD *)v7 + 1);
      v13 = 0;
      for ( i = *((_DWORD *)v7 + 1); v13 < v11; ++v13 )
      {
        if ( v13 >= v3->unitsTaskedThisUpdate.maximumSizeValue )
          break;
        if ( v3->unitsTaskedThisUpdate.value[v13] == v12 )
          goto LABEL_17;
      }
      if ( v11 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
      {
        v14 = v11 + 1;
        v15 = (int *)operator new(4 * (v11 + 1));
        if ( v15 )
        {
          for ( j = 0; j < v3->unitsTaskedThisUpdate.maximumSizeValue; v15[j - 1] = v3->unitsTaskedThisUpdate.value[j - 1] )
          {
            if ( j >= v14 )
              break;
            ++j;
          }
          operator delete(v3->unitsTaskedThisUpdate.value);
          v3->unitsTaskedThisUpdate.value = v15;
          v3->unitsTaskedThisUpdate.maximumSizeValue = v14;
        }
        v7 = researchItema;
        v12 = i;
      }
      v3->unitsTaskedThisUpdate.value[v3->unitsTaskedThisUpdate.numberValue++] = v12;
LABEL_17:
      v17 = v3->md->aiPlayer->vfptr;
      v18 = BaseItem::uniqueID((BaseItem *)&v2->vfptr);
      v19 = *((_DWORD *)v7 + 1);
      v20 = BaseItem::typeID((BaseItem *)&v2->vfptr);
      (*(void (__thiscall **)(TRIBE_Player *, int, int, int))&v17[1].gap4[24])(v3->md->aiPlayer, v20, v19, v18);
      result = 1;
    }
    else
    {
      v21 = BaseItem::uniqueID((BaseItem *)&v2->vfptr);
      v22 = BaseItem::typeID((BaseItem *)&v2->vfptr);
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aCouldNotFind_1, v22, v21);
      result = 0;
    }
  }
  else
  {
    AIModule::logCommonHistory((AIModule *)&this->vfptr, aInvalidTaskres);
    result = 0;
  }
  return result;
}

//----- (004FB8D0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskToEnter(TribeTacticalAIModule *this, int unitID, int targetID)
{
  TribeTacticalAIModule *v3; // esi@1
  int result; // eax@2
  int v5; // ecx@3
  int i; // eax@3
  int v7; // ebx@8
  int *v8; // edi@8
  int j; // eax@9

  v3 = this;
  if ( unitID == -1 )
  {
    result = 0;
  }
  else
  {
    v5 = this->unitsTaskedThisUpdate.numberValue;
    for ( i = 0; i < v5; ++i )
    {
      if ( i >= v3->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v3->unitsTaskedThisUpdate.value[i] == unitID )
        goto LABEL_14;
    }
    if ( v5 > v3->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v7 = v5 + 1;
      v8 = (int *)operator new(4 * (v5 + 1));
      if ( v8 )
      {
        for ( j = 0; j < v3->unitsTaskedThisUpdate.maximumSizeValue; v8[j - 1] = v3->unitsTaskedThisUpdate.value[j - 1] )
        {
          if ( j >= v7 )
            break;
          ++j;
        }
        operator delete(v3->unitsTaskedThisUpdate.value);
        v3->unitsTaskedThisUpdate.value = v8;
        v3->unitsTaskedThisUpdate.maximumSizeValue = v7;
      }
    }
    v3->unitsTaskedThisUpdate.value[v3->unitsTaskedThisUpdate.numberValue++] = unitID;
LABEL_14:
    ((void (__stdcall *)(_DWORD, int, signed int, int, _DWORD, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v3->md->player->vfptr->sendUnitAIOrder)(
      v3->md->player->id,
      unitID,
      717,
      targetID,
      v3->md->player->id,
      -1082130432,
      -1082130432,
      -1082130432,
      1065353216,
      1,
      0,
      100);
    result = 1;
  }
  return result;
}

//----- (004FB9E0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::taskTransporter(TribeTacticalAIModule *this, int unitID, float x, float y)
{
  int v4; // ebp@1
  TribeTacticalAIModule *v5; // esi@1
  RGE_Static_Object *v6; // eax@1
  int v7; // eax@3
  int v8; // ecx@3
  int i; // eax@3
  int v10; // ebx@8
  int *v11; // edi@8
  int j; // eax@9
  int result; // eax@14
  int unitIDb; // [sp+14h] [bp+4h]@3
  int unitIDa; // [sp+14h] [bp+4h]@3

  v4 = unitID;
  v5 = this;
  v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID);
  if ( unitID != -1 && v6 )
  {
    *(float *)&unitIDb = RGE_Static_Object::distance_to_position(v6, x, y, 1.0);
    v7 = TribeTacticalAIModule::calculatePriority(v5, *(float *)&unitIDb);
    v8 = v5->unitsTaskedThisUpdate.numberValue;
    unitIDa = v7;
    for ( i = 0; i < v8; ++i )
    {
      if ( i >= v5->unitsTaskedThisUpdate.maximumSizeValue )
        break;
      if ( v5->unitsTaskedThisUpdate.value[i] == v4 )
        goto LABEL_14;
    }
    if ( v8 > v5->unitsTaskedThisUpdate.maximumSizeValue - 1 )
    {
      v10 = v8 + 1;
      v11 = (int *)operator new(4 * (v8 + 1));
      if ( v11 )
      {
        for ( j = 0; j < v5->unitsTaskedThisUpdate.maximumSizeValue; v11[j - 1] = v5->unitsTaskedThisUpdate.value[j - 1] )
        {
          if ( j >= v10 )
            break;
          ++j;
        }
        operator delete(v5->unitsTaskedThisUpdate.value);
        v5->unitsTaskedThisUpdate.value = v11;
        v5->unitsTaskedThisUpdate.maximumSizeValue = v10;
      }
    }
    v5->unitsTaskedThisUpdate.value[v5->unitsTaskedThisUpdate.numberValue++] = v4;
LABEL_14:
    ((void (__stdcall *)(_DWORD, int, signed int, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, int))v5->md->player->vfptr->sendUnitAIOrder)(
      v5->md->player->id,
      v4,
      714,
      -1,
      v5->md->player->id,
      LODWORD(x),
      LODWORD(y),
      1065353216,
      1065353216,
      1,
      0,
      unitIDa);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FBB30) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::removeFromTaskLists(TribeTacticalAIModule *this, int gID)
{
  TribeTacticalAIModule *v2; // esi@1
  int v3; // eax@1
  int v4; // edx@1
  int *v5; // ecx@2
  int v6; // eax@8
  RGE_Static_Object *v7; // eax@10
  RGE_Static_Object *v8; // edi@10
  UnitAIModule *v9; // eax@12
  UnitAIModule *v10; // eax@13
  UnitData *v11; // eax@14
  int *v12; // eax@15

  v2 = this;
  v3 = 0;
  v4 = this->civilianExplorers.maximumSizeValue;
  if ( v4 > 0 )
  {
    v5 = this->civilianExplorers.value;
    do
    {
      if ( *v5 == gID )
        break;
      ++v3;
      ++v5;
    }
    while ( v3 < v4 );
  }
  if ( v3 < v4 )
  {
    if ( v3 < v4 - 1 )
    {
      do
      {
        ++v3;
        v2->civilianExplorers.value[v3 - 1] = v2->civilianExplorers.value[v3];
      }
      while ( v3 < v2->civilianExplorers.maximumSizeValue - 1 );
    }
    v6 = v2->civilianExplorers.numberValue - 1;
    v2->civilianExplorers.numberValue = v6;
    if ( v6 < 0 )
      v2->civilianExplorers.numberValue = 0;
  }
  TribeTacticalAIModule::removeGatherer(v2, gID);
  v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, gID);
  v8 = v7;
  if ( v7 )
  {
    if ( RGE_Static_Object::unitAI(v7) )
    {
      v9 = RGE_Static_Object::unitAI(v8);
      if ( UnitAIModule::currentAction(v9) == 609
        || (v10 = RGE_Static_Object::unitAI(v8), UnitAIModule::currentAction(v10) == 613) )
      {
        v11 = TribeTacticalAIModule::gatherer(v2, gID);
        if ( v11 )
        {
          v12 = &v2->actualGathererDistribution[v11->data1];
          --*v12;
        }
      }
    }
  }
}

//----- (004FBC10) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::calculatePriority(TribeTacticalAIModule *this, float distance)
{
  signed __int64 v2; // rax@1

  v2 = (signed __int64)((double)this->sn[34] / distance);
  if ( (signed int)v2 > 99 )
    LODWORD(v2) = 99;
  return v2;
}

//----- (004FBC30) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::setupSoldierGroups(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ecx@1
  TacticalAIGroup *v3; // ebx@1
  int v4; // ebp@1
  int v5; // eax@4
  int v6; // edi@4
  int v7; // eax@4
  int *v8; // edx@5
  TacticalAIGroup *v9; // ebx@16
  int v10; // eax@19
  int v11; // edi@19
  int v12; // eax@19
  int *v13; // edx@20
  int v14; // ebx@30
  int *v15; // edi@31
  int k; // eax@32
  int *v17; // edi@38
  signed int l; // eax@39
  int v19; // ebx@47
  int *v20; // edi@47
  int m; // eax@48
  int v22; // eax@52
  int v23; // ebx@52
  int v24; // ecx@53
  int *v25; // edx@54
  int v26; // eax@61
  int v27; // ebp@61
  int v28; // ecx@62
  int *v29; // edx@63
  int v30; // eax@69
  TacticalAIGroup *v31; // eax@71
  TacticalAIGroup *v32; // edi@71
  int v33; // ecx@72
  int v34; // eax@72
  int *v35; // edx@73
  int v36; // eax@79
  int v37; // ebx@83
  int v38; // edi@85
  int v39; // ecx@86
  signed __int64 v40; // rax@89
  signed int v41; // ecx@89
  int v42; // eax@91
  int v43; // eax@93
  int v44; // ecx@94
  int v45; // eax@96
  int v46; // ebp@102
  int v47; // ebx@102
  TacticalAIGroup *v48; // edi@103
  int v49; // edx@110
  int n; // edi@114
  TacticalAIGroup *v51; // eax@115
  int v52; // eax@117
  int v53; // ebx@118
  int ii; // ebp@118
  TacticalAIGroup *v55; // edi@119
  TacticalAIGroup *v56; // eax@126
  int v57; // eax@127
  TacticalAIGroup *v58; // eax@129
  TacticalAIGroup *v59; // edi@129
  TacticalAIGroup *v60; // eax@132
  int v61; // eax@133
  int numPotentialAGroups; // [sp+18h] [bp-38h]@83
  int newArtifact; // [sp+1Ch] [bp-34h]@52
  int newArtifacta; // [sp+1Ch] [bp-34h]@82
  int i; // [sp+20h] [bp-30h]@29
  int ia; // [sp+20h] [bp-30h]@82
  int numAGroups; // [sp+24h] [bp-2Ch]@45
  int numDGroups; // [sp+28h] [bp-28h]@45
  int numEGroups; // [sp+2Ch] [bp-24h]@45
  int v70; // [sp+30h] [bp-20h]@88
  ManagedArray<int> groupsToRemove; // [sp+34h] [bp-1Ch]@1
  int j; // [sp+4Ch] [bp-4h]@1

  v1 = this;
  v2 = 0;
  groupsToRemove.value = 0;
  groupsToRemove.numberValue = 0;
  groupsToRemove.desiredNumberValue = 0;
  groupsToRemove.maximumSizeValue = 0;
  v3 = v1->groups.next;
  v4 = (int)&v1->groups;
  for ( j = 0; v3 != (TacticalAIGroup *)v4; v3 = v3->next )
  {
    if ( !v3 )
      break;
    if ( TacticalAIGroup::numberUnits(v3) )
    {
      v2 = groupsToRemove.numberValue;
    }
    else
    {
      v5 = TacticalAIGroup::id(v3);
      v2 = groupsToRemove.numberValue;
      v6 = v5;
      v7 = 0;
      if ( groupsToRemove.numberValue > 0 )
      {
        v8 = groupsToRemove.value;
        do
        {
          if ( v7 >= groupsToRemove.maximumSizeValue )
            break;
          if ( *v8 == v6 )
            goto LABEL_13;
          ++v7;
          ++v8;
        }
        while ( v7 < groupsToRemove.numberValue );
      }
      if ( groupsToRemove.numberValue > groupsToRemove.maximumSizeValue - 1 )
      {
        ManagedArray<int>::resize(&groupsToRemove, groupsToRemove.numberValue + 1);
        v2 = groupsToRemove.numberValue;
      }
      groupsToRemove.value[v2] = v6;
      v2 = groupsToRemove.numberValue++ + 1;
    }
LABEL_13:
    ;
  }
  if ( (v1->md->player->world->world_time - v1->lastGroupAttackTime) / 0x3E8 > 0x258
    && (v1->md->player->world->world_time - v1->lastGroupRebalanceTime) / 0x3E8 > 0x258 )
  {
    v9 = v1->groups.next;
    for ( v1->lastGroupRebalanceTime = v1->md->player->world->world_time; v9 != (TacticalAIGroup *)v4; v9 = v9->next )
    {
      if ( !v9 )
        break;
      if ( TacticalAIGroup::type(v9) == 100 )
      {
        v10 = TacticalAIGroup::id(v9);
        v2 = groupsToRemove.numberValue;
        v11 = v10;
        v12 = 0;
        if ( groupsToRemove.numberValue > 0 )
        {
          v13 = groupsToRemove.value;
          do
          {
            if ( v12 >= groupsToRemove.maximumSizeValue )
              break;
            if ( *v13 == v11 )
              goto LABEL_28;
            ++v12;
            ++v13;
          }
          while ( v12 < groupsToRemove.numberValue );
        }
        if ( groupsToRemove.numberValue > groupsToRemove.maximumSizeValue - 1 )
        {
          ManagedArray<int>::resize(&groupsToRemove, groupsToRemove.numberValue + 1);
          v2 = groupsToRemove.numberValue;
        }
        groupsToRemove.value[v2] = v11;
        v2 = groupsToRemove.numberValue++ + 1;
      }
      else
      {
        v2 = groupsToRemove.numberValue;
      }
LABEL_28:
      ;
    }
  }
  i = 0;
  if ( v2 > 0 )
  {
    do
    {
      v14 = i;
      if ( i > groupsToRemove.maximumSizeValue - 1 )
      {
        v15 = (int *)operator new(4 * i + 4);
        if ( v15 )
        {
          for ( k = 0; k < groupsToRemove.maximumSizeValue; v15[k - 1] = groupsToRemove.value[k - 1] )
          {
            if ( k >= i + 1 )
              break;
            ++k;
          }
          operator delete(groupsToRemove.value);
          groupsToRemove.value = v15;
          groupsToRemove.maximumSizeValue = i + 1;
        }
      }
      TribeTacticalAIModule::removeGroup(v1, groupsToRemove.value[i++]);
    }
    while ( v14 + 1 < groupsToRemove.numberValue );
  }
  if ( v1->soldiers.maximumSizeValue - 1 < 0 )
  {
    v17 = (int *)operator new(4u);
    if ( v17 )
    {
      for ( l = 0; l < v1->soldiers.maximumSizeValue; v17[l - 1] = v1->soldiers.value[l - 1] )
      {
        if ( l >= 1 )
          break;
        ++l;
      }
      operator delete(v1->soldiers.value);
      v1->soldiers.value = v17;
      v1->soldiers.maximumSizeValue = 1;
    }
  }
  if ( !TribeInformationAIModule::fullyExploredZone(&v1->md->informationAI, *v1->soldiers.value) )
  {
    TribeTacticalAIModule::removeAllGroups(v1, 102);
    TribeTacticalAIModule::setStrategicNumber(v1, 42, 0);
  }
  numAGroups = TribeTacticalAIModule::numberGroups(v1, 100, -1);
  numDGroups = TribeTacticalAIModule::numberGroups(v1, 101, -1);
  numEGroups = TribeTacticalAIModule::numberGroups(v1, 102, -1);
  TribeTacticalAIModule::numberGroups(v1, 109, -1);
  TribeTacticalAIModule::numberUngroupedArtifacts(v1);
  while ( v1->workingArea.numberValue > 0 )
  {
    if ( i > v1->workingArea.maximumSizeValue - 1 )
    {
      v19 = i + 1;
      v20 = (int *)operator new(4 * (i + 1));
      if ( v20 )
      {
        for ( m = 0; m < v1->workingArea.maximumSizeValue; v20[m - 1] = v1->workingArea.value[m - 1] )
        {
          if ( m >= v19 )
            break;
          ++m;
        }
        operator delete(v1->workingArea.value);
        v1->workingArea.value = v20;
        v1->workingArea.maximumSizeValue = v19;
      }
    }
    newArtifact = v1->workingArea.value[i];
    v22 = (int)MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, newArtifact);
    v23 = v22;
    if ( v22 )
    {
      v26 = (int)MainDecisionAIModule::object(
                   (MainDecisionAIModule *)&v1->md->vfptr,
                   -1,
                   109,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1);
      v27 = v26;
      if ( v26 )
      {
        v31 = TribeTacticalAIModule::createGroup(v1, 1);
        v32 = v31;
        if ( !v31 )
          break;
        TacticalAIGroup::setType(v31, 109);
        TacticalAIGroup::setDesiredNumberUnits(v32, 1);
        TacticalAIGroup::addUnit(v32, newArtifact, v1->md);
        TacticalAIGroup::setSpecificCommander(v32, newArtifact, v1->md);
        TacticalAIGroup::setLocation(v32, *(float *)(v23 + 56), *(float *)(v23 + 60), *(float *)(v23 + 64));
        TacticalAIGroup::setGatherLocation(v32, *(float *)(v23 + 56), *(float *)(v23 + 60), *(float *)(v23 + 64));
        TacticalAIGroup::setRetreatLocation(v32, *(float *)(v27 + 56), *(float *)(v27 + 60), *(float *)(v27 + 64));
        v33 = v1->workingArea.maximumSizeValue;
        v34 = 0;
        if ( v33 > 0 )
        {
          v35 = v1->workingArea.value;
          do
          {
            if ( *v35 == newArtifact )
              break;
            ++v34;
            ++v35;
          }
          while ( v34 < v33 );
        }
        if ( v34 >= v33 )
          continue;
        if ( v34 < v33 - 1 )
        {
          do
          {
            ++v34;
            v1->workingArea.value[v34 - 1] = v1->workingArea.value[v34];
          }
          while ( v34 < v1->workingArea.maximumSizeValue - 1 );
        }
        v36 = v1->workingArea.numberValue - 1;
        v1->workingArea.numberValue = v36;
        if ( v36 >= 0 )
          continue;
LABEL_80:
        v1->workingArea.numberValue = 0;
        continue;
      }
      v28 = v1->workingArea.maximumSizeValue;
      if ( v28 > 0 )
      {
        v29 = v1->workingArea.value;
        do
        {
          if ( *v29 == newArtifact )
            break;
          ++v26;
          ++v29;
        }
        while ( v26 < v28 );
      }
      if ( v26 >= v28 )
        continue;
      if ( v26 < v28 - 1 )
      {
        do
        {
          ++v26;
          v1->workingArea.value[v26 - 1] = v1->workingArea.value[v26];
        }
        while ( v26 < v1->workingArea.maximumSizeValue - 1 );
      }
    }
    else
    {
      v24 = v1->workingArea.maximumSizeValue;
      if ( v24 > 0 )
      {
        v25 = v1->workingArea.value;
        do
        {
          if ( *v25 == newArtifact )
            break;
          ++v22;
          ++v25;
        }
        while ( v22 < v24 );
      }
      if ( v22 >= v24 )
        continue;
      if ( v22 < v24 - 1 )
      {
        do
        {
          ++v22;
          v1->workingArea.value[v22 - 1] = v1->workingArea.value[v22];
        }
        while ( v22 < v1->workingArea.maximumSizeValue - 1 );
      }
    }
    v30 = v1->workingArea.numberValue - 1;
    v1->workingArea.numberValue = v30;
    if ( v30 < 0 )
      goto LABEL_80;
  }
  newArtifacta = 0;
  ia = 0;
  if ( v1->sn[40] )
  {
    v42 = v1->soldiers.numberValue;
    v37 = v1->soldiers.numberValue;
    if ( v42 >= v1->sn[36] )
      v37 = v1->sn[36];
    v43 = v42 - v37;
    numPotentialAGroups = v37;
    if ( v43 > 0 )
    {
      v44 = v1->sn[38];
      if ( v43 < v44 )
        v44 = v43;
      v45 = v43 - v44;
      newArtifacta = v44;
      if ( v45 > 0 )
      {
        v41 = v1->sn[42];
        ia = v45;
        if ( v45 >= v41 )
          goto LABEL_98;
      }
    }
  }
  else
  {
    v37 = (signed __int64)ceil((double)v1->soldiers.numberValue / (double)v1->sn[16]);
    numPotentialAGroups = v37;
    if ( v37 > v1->sn[36] )
    {
      v37 = v1->sn[36];
      numPotentialAGroups = v1->sn[36];
    }
    v38 = v1->sn[16] * v37;
    if ( v1->soldiers.numberValue - v38 > 0 )
    {
      v39 = (signed __int64)ceil((double)(v1->soldiers.numberValue - v38) / (double)v1->sn[25]);
      newArtifacta = v39;
      if ( v39 > v1->sn[38] )
      {
        v39 = v1->sn[38];
        newArtifacta = v1->sn[38];
      }
      v70 = v1->soldiers.numberValue - v1->sn[25] * v39 - v38;
      if ( v70 > 0 )
      {
        v40 = (signed __int64)ceil((double)v70 / (double)v1->sn[43]);
        v41 = v1->sn[42];
        ia = v40;
        if ( (signed int)v40 > v41 )
        {
LABEL_98:
          ia = v41;
          goto LABEL_99;
        }
      }
    }
  }
LABEL_99:
  if ( v1->sn[162] == 1 )
  {
    v37 = 0;
    numPotentialAGroups = 0;
  }
  if ( numAGroups < v37 )
  {
    v46 = numDGroups;
    v47 = numAGroups;
    while ( 1 )
    {
      v48 = 0;
      if ( v46 > 0 )
      {
        v48 = TribeTacticalAIModule::group(v1, -1, 101, -1, -1);
        if ( v48 )
        {
          --v46;
        }
        else
        {
          v48 = TribeTacticalAIModule::group(v1, -1, 102, -1, -1);
          if ( !v48 )
            goto LABEL_109;
          --numEGroups;
        }
      }
      if ( !v48 )
      {
LABEL_109:
        v48 = TribeTacticalAIModule::createGroup(v1, 1);
        if ( !v48 )
          goto LABEL_113;
      }
      TacticalAIGroup::setType(v48, 100);
      TacticalAIGroup::setTarget(v48, -1);
      TacticalAIGroup::setTargetType(v48, -1);
      TacticalAIGroup::setAction(v48, 1);
      TacticalAIGroup::setInUse(v48, 0);
      v49 = v1->sn[16] + debug_rand(aCMsdevWorkA_61, 9568) % (v1->sn[98] + 1);
      if ( v49 > v1->sn[26] )
        v49 = v1->sn[26];
      TacticalAIGroup::setDesiredNumberUnits(v48, v49);
      if ( ++v47 >= numPotentialAGroups )
      {
LABEL_113:
        numAGroups = v47;
        numDGroups = v46;
        break;
      }
    }
  }
  for ( n = numAGroups; n > numPotentialAGroups; --n )
  {
    v51 = TribeTacticalAIModule::group(v1, -1, 100, 0, -1);
    if ( !v51 )
    {
      v51 = TribeTacticalAIModule::group(v1, -1, 100, 1, -1);
      if ( !v51 )
        break;
    }
    v52 = TacticalAIGroup::id(v51);
    TribeTacticalAIModule::removeGroup(v1, v52);
  }
  v53 = numDGroups;
  for ( ii = numEGroups; v53 < newArtifacta; ++v53 )
  {
    v55 = 0;
    if ( ii > 0 )
    {
      v55 = TribeTacticalAIModule::group(v1, -1, 102, -1, -1);
      if ( !v55 )
        goto LABEL_123;
      --ii;
    }
    if ( !v55 )
    {
LABEL_123:
      v55 = TribeTacticalAIModule::createGroup(v1, 1);
      if ( !v55 )
        break;
    }
    TacticalAIGroup::setType(v55, 101);
    TacticalAIGroup::setTarget(v55, -1);
    TacticalAIGroup::setTargetType(v55, -1);
    TacticalAIGroup::setAction(v55, 1);
    TacticalAIGroup::setInUse(v55, 0);
    TacticalAIGroup::setDesiredNumberUnits(v55, v1->sn[25]);
  }
  while ( v53 > newArtifacta )
  {
    v56 = TribeTacticalAIModule::group(v1, -1, 101, -1, -1);
    if ( !v56 )
      break;
    v57 = TacticalAIGroup::id(v56);
    TribeTacticalAIModule::removeGroup(v1, v57);
    --v53;
  }
  for ( ; ii < ia; ++ii )
  {
    v58 = TribeTacticalAIModule::createGroup(v1, 1);
    v59 = v58;
    if ( !v58 )
      break;
    TacticalAIGroup::setType(v58, 102);
    TacticalAIGroup::setDesiredNumberUnits(v59, v1->sn[43]);
  }
  for ( ; ii > ia; --ii )
  {
    v60 = TribeTacticalAIModule::group(v1, -1, 102, -1, -1);
    if ( !v60 )
      break;
    v61 = TacticalAIGroup::id(v60);
    TribeTacticalAIModule::removeGroup(v1, v61);
  }
  j = -1;
  if ( groupsToRemove.value )
    operator delete(groupsToRemove.value);
}

//----- (004FC500) --------------------------------------------------------
void __usercall TribeTacticalAIModule::fillSoldierGroups(TribeTacticalAIModule *this@<ecx>, double a2@<st0>)
{
  TribeTacticalAIModule *v2; // esi@1
  TacticalAIGroup *i; // edi@1
  int v4; // ebx@7
  int v5; // eax@8
  int v6; // ebx@14
  TacticalAIGroup *v7; // ebp@20
  int v8; // edi@24
  int v9; // eax@28
  RGE_Static_Object *v10; // eax@28
  int v11; // edi@30
  int v12; // ebx@30
  int l; // ebx@31
  int v14; // ebp@33
  int *v15; // edi@33
  int m; // eax@34
  RGE_Static_Object *v17; // eax@39
  int v18; // ebp@42
  int *v19; // edi@42
  int n; // eax@43
  int v21; // edi@50
  int v22; // ebx@51
  int v23; // ebp@53
  int *v24; // edi@53
  int j; // eax@54
  RGE_Static_Object *v26; // eax@59
  RGE_Static_Object *v27; // edi@59
  float v28; // ST08_4@61
  float v29; // ST04_4@61
  Waypoint *v30; // eax@61
  int v31; // ebp@64
  int *v32; // edi@64
  int k; // eax@65
  int v34; // ecx@72
  int v35; // eax@72
  int *v36; // edx@73
  int v37; // eax@79
  int v38; // edi@81
  int v39; // edi@82
  int v40; // edi@84
  int v41; // ebx@84
  int kk; // ebp@85
  int v43; // ebx@87
  int *v44; // edi@87
  int ll; // eax@88
  RGE_Static_Object *v46; // eax@92
  int v47; // ebx@95
  int *v48; // edi@95
  int mm; // eax@96
  int v50; // ebx@101
  int *v51; // edi@101
  int nn; // eax@102
  int v53; // edi@109
  int v54; // edi@110
  int v55; // ebx@110
  int v56; // ebp@112
  int *v57; // edi@112
  int ii; // eax@113
  RGE_Static_Object *v59; // eax@117
  RGE_Static_Object *v60; // edi@117
  float v61; // ST08_4@119
  float v62; // ST04_4@119
  Waypoint *v63; // eax@119
  int v64; // ebp@122
  int *v65; // edi@122
  int jj; // eax@123
  int v67; // ecx@131
  int v68; // eax@131
  int *v69; // edx@132
  int v70; // eax@138
  int v71; // edi@140
  bool v72; // zf@143
  bool v73; // sf@143
  unsigned __int8 v74; // of@143
  int v75; // ebx@145
  int v76; // ebp@149
  int *v77; // edi@149
  int i1; // eax@150
  RGE_Static_Object *v79; // eax@154
  char v80; // al@155
  TacticalAIGroup *v81; // edi@155
  int v82; // ebp@155
  int v83; // ebx@155
  int v84; // eax@161
  RGE_Static_Object *v85; // eax@161
  int v86; // ebp@163
  int v87; // ebp@166
  int v88; // ebp@166
  TacticalAIGroup *v89; // ebx@170
  int v90; // ebp@172
  int *v91; // edi@172
  int i2; // eax@173
  TacticalAIGroup *v93; // edi@178
  int v94; // eax@192
  RGE_Static_Object *v95; // eax@192
  int v96; // ebx@194
  int v97; // eax@194
  int v98; // ebp@200
  int *v99; // edi@200
  int i3; // eax@201
  char unitZone; // [sp+13h] [bp-1Dh]@155
  TacticalAIGroup *temp; // [sp+14h] [bp-1Ch]@20
  TacticalAIGroup *tempa; // [sp+14h] [bp-1Ch]@145
  TacticalAIGroup *bestGroup; // [sp+18h] [bp-18h]@28
  TacticalAIGroup *bestGroupa; // [sp+18h] [bp-18h]@155
  TacticalAIGroup *bestGroupb; // [sp+18h] [bp-18h]@178
  float bestDistance; // [sp+1Ch] [bp-14h]@51
  float v108; // [sp+20h] [bp-10h]@110
  int a; // [sp+24h] [bp-Ch]@19
  float unitDistance; // [sp+28h] [bp-8h]@61
  float unitDistancea; // [sp+28h] [bp-8h]@110
  signed int bestGroupDifference; // [sp+2Ch] [bp-4h]@51
  int bestGroupDifferencea; // [sp+2Ch] [bp-4h]@119
  int bestGroupDifferenceb; // [sp+2Ch] [bp-4h]@178

  v2 = this;
  TribeTacticalAIModule::numberUngroupedSoldiers(this);
  TribeTacticalAIModule::numberExtraGroupedSoldiers(v2);
  for ( i = v2->groups.next; i != &v2->groups; i = i->next )
  {
    if ( !i )
      break;
    if ( (TacticalAIGroup::type(i) == 100 || TacticalAIGroup::type(i) == 101 || TacticalAIGroup::type(i) == 102)
      && TacticalAIGroup::commander(i) == -1 )
    {
      v4 = TribeTacticalAIModule::numberUngroupedSoldiers(v2);
      if ( TacticalAIGroup::numberUnits(i) > 0 )
      {
        v5 = TribeTacticalAIModule::selectBestCommander(v2, a2, i);
        TacticalAIGroup::setSpecificCommander(i, v5, v2->md);
        if ( TacticalAIGroup::action(i) && TacticalAIGroup::action(i) != 1 )
          continue;
LABEL_16:
        TribeTacticalAIModule::setAllGroupLocations(v2, i);
        continue;
      }
      if ( !v4 )
        TribeTacticalAIModule::numberExtraGroupedSoldiers(v2);
      if ( !v2->workingArea.numberValue )
        return;
      v6 = TribeTacticalAIModule::selectBestCommander(v2, a2, &v2->workingArea);
      TacticalAIGroup::addUnit(i, v6, v2->md);
      TacticalAIGroup::setSpecificCommander(i, v6, v2->md);
      if ( !TacticalAIGroup::action(i) || TacticalAIGroup::action(i) == 1 )
        goto LABEL_16;
    }
  }
  if ( !v2->sn[40] )
  {
    a = 100;
    do
    {
      v7 = v2->groups.next;
      for ( temp = v2->groups.next; v7 != &v2->groups; temp = v7 )
      {
        if ( !v7 )
          break;
        if ( TacticalAIGroup::type(v7) == a )
        {
          v8 = TacticalAIGroup::desiredNumberUnits(v7);
          if ( TacticalAIGroup::numberUnits(v7) < v8 )
          {
            if ( TacticalAIGroup::inUse(v7) == 1 )
            {
              v7 = v7->next;
            }
            else
            {
              bestGroup = (TacticalAIGroup *)-1;
              v9 = TacticalAIGroup::commander(v7);
              v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v9);
              if ( v10 )
                bestGroup = (TacticalAIGroup *)(unsigned __int8)RGE_Static_Object::currentZone(v10);
              v11 = TribeTacticalAIModule::numberUngroupedSoldiers(v2);
              v12 = TacticalAIGroup::desiredNumberUnits(v7);
              if ( v11 > v12 - TacticalAIGroup::numberUnits(v7) )
              {
                v21 = TacticalAIGroup::desiredNumberUnits(v7);
                if ( TacticalAIGroup::numberUnits(v7) < v21 )
                {
                  do
                  {
                    v22 = 0;
                    bestGroupDifference = -1;
                    for ( bestDistance = -1.0; v22 < v2->workingArea.numberValue; ++v22 )
                    {
                      if ( v22 > v2->workingArea.maximumSizeValue - 1 )
                      {
                        v23 = v22 + 1;
                        v24 = (int *)operator new(4 * v22 + 4);
                        if ( v24 )
                        {
                          for ( j = 0; j < v2->workingArea.maximumSizeValue; v24[j - 1] = v2->workingArea.value[j - 1] )
                          {
                            if ( j >= v23 )
                              break;
                            ++j;
                          }
                          operator delete(v2->workingArea.value);
                          v2->workingArea.value = v24;
                          v2->workingArea.maximumSizeValue = v23;
                        }
                        v7 = temp;
                      }
                      v26 = MainDecisionAIModule::object(
                              (MainDecisionAIModule *)&v2->md->vfptr,
                              v2->workingArea.value[v22]);
                      v27 = v26;
                      if ( v26 )
                      {
                        if ( bestGroup == (TacticalAIGroup *)(unsigned __int8)RGE_Static_Object::currentZone(v26) )
                        {
                          v28 = TacticalAIGroup::gatherLocation(v7)->z;
                          v29 = TacticalAIGroup::gatherLocation(v7)->y;
                          v30 = TacticalAIGroup::gatherLocation(v7);
                          unitDistance = RGE_Static_Object::distance_to_position(v27, v30->x, v29, v28);
                          if ( bestDistance == -1.0 || unitDistance < (double)bestDistance )
                          {
                            if ( v22 > v2->workingArea.maximumSizeValue - 1 )
                            {
                              v31 = v22 + 1;
                              v32 = (int *)operator new(4 * v22 + 4);
                              if ( v32 )
                              {
                                for ( k = 0; k < v2->workingArea.maximumSizeValue; v32[k - 1] = v2->workingArea.value[k - 1] )
                                {
                                  if ( k >= v31 )
                                    break;
                                  ++k;
                                }
                                operator delete(v2->workingArea.value);
                                v2->workingArea.value = v32;
                                v2->workingArea.maximumSizeValue = v31;
                              }
                            }
                            v7 = temp;
                            bestDistance = unitDistance;
                            bestGroupDifference = v2->workingArea.value[v22];
                          }
                        }
                      }
                    }
                    if ( bestGroupDifference == -1 )
                      break;
                    TacticalAIGroup::addUnit(v7, bestGroupDifference, v2->md);
                    v34 = v2->workingArea.maximumSizeValue;
                    v35 = 0;
                    if ( v34 > 0 )
                    {
                      v36 = v2->workingArea.value;
                      do
                      {
                        if ( *v36 == bestGroupDifference )
                          break;
                        ++v35;
                        ++v36;
                      }
                      while ( v35 < v34 );
                    }
                    if ( v35 < v34 )
                    {
                      if ( v35 < v34 - 1 )
                      {
                        do
                        {
                          ++v35;
                          v2->workingArea.value[v35 - 1] = v2->workingArea.value[v35];
                        }
                        while ( v35 < v2->workingArea.maximumSizeValue - 1 );
                      }
                      v37 = v2->workingArea.numberValue - 1;
                      v2->workingArea.numberValue = v37;
                      if ( v37 < 0 )
                        v2->workingArea.numberValue = 0;
                    }
                    v38 = TacticalAIGroup::desiredNumberUnits(v7);
                  }
                  while ( TacticalAIGroup::numberUnits(v7) < v38 );
                }
              }
              else
              {
                for ( l = 0; l < v2->workingArea.numberValue; ++l )
                {
                  if ( l > v2->workingArea.maximumSizeValue - 1 )
                  {
                    v14 = l + 1;
                    v15 = (int *)operator new(4 * l + 4);
                    if ( v15 )
                    {
                      for ( m = 0; m < v2->workingArea.maximumSizeValue; v15[m - 1] = v2->workingArea.value[m - 1] )
                      {
                        if ( m >= v14 )
                          break;
                        ++m;
                      }
                      operator delete(v2->workingArea.value);
                      v2->workingArea.value = v15;
                      v2->workingArea.maximumSizeValue = v14;
                    }
                    v7 = temp;
                  }
                  v17 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v2->workingArea.value[l]);
                  if ( v17 && bestGroup == (TacticalAIGroup *)(unsigned __int8)RGE_Static_Object::currentZone(v17) )
                  {
                    if ( l > v2->workingArea.maximumSizeValue - 1 )
                    {
                      v18 = l + 1;
                      v19 = (int *)operator new(4 * l + 4);
                      if ( v19 )
                      {
                        for ( n = 0; n < v2->workingArea.maximumSizeValue; v19[n - 1] = v2->workingArea.value[n - 1] )
                        {
                          if ( n >= v18 )
                            break;
                          ++n;
                        }
                        operator delete(v2->workingArea.value);
                        v2->workingArea.value = v19;
                        v2->workingArea.maximumSizeValue = v18;
                      }
                    }
                    TacticalAIGroup::addUnit(temp, v2->workingArea.value[l], v2->md);
                    v7 = temp;
                  }
                }
              }
              v39 = TacticalAIGroup::desiredNumberUnits(v7);
              if ( TacticalAIGroup::numberUnits(v7) < v39 )
              {
                v40 = TribeTacticalAIModule::numberExtraGroupedSoldiers(v2);
                v41 = TacticalAIGroup::desiredNumberUnits(v7);
                if ( v40 > v41 - TacticalAIGroup::numberUnits(v7) )
                {
                  v53 = TacticalAIGroup::desiredNumberUnits(v7);
                  if ( TacticalAIGroup::numberUnits(v7) < v53 )
                  {
                    do
                    {
                      v54 = -1;
                      v55 = 0;
                      unitDistancea = -6.8056469e38/*NaN*/;
                      v108 = -1.0;
                      if ( v2->workingArea.numberValue > 0 )
                      {
                        do
                        {
                          if ( v55 > v2->workingArea.maximumSizeValue - 1 )
                          {
                            v56 = v55 + 1;
                            v57 = (int *)operator new(4 * v55 + 4);
                            if ( v57 )
                            {
                              for ( ii = 0;
                                    ii < v2->workingArea.maximumSizeValue;
                                    v57[ii - 1] = v2->workingArea.value[ii - 1] )
                              {
                                if ( ii >= v56 )
                                  break;
                                ++ii;
                              }
                              operator delete(v2->workingArea.value);
                              v2->workingArea.value = v57;
                              v2->workingArea.maximumSizeValue = v56;
                            }
                          }
                          v59 = MainDecisionAIModule::object(
                                  (MainDecisionAIModule *)&v2->md->vfptr,
                                  v2->workingArea.value[v55]);
                          v60 = v59;
                          if ( v59 )
                          {
                            if ( bestGroup == (TacticalAIGroup *)(unsigned __int8)RGE_Static_Object::currentZone(v59) )
                            {
                              v61 = TacticalAIGroup::gatherLocation(temp)->z;
                              v62 = TacticalAIGroup::gatherLocation(temp)->y;
                              v63 = TacticalAIGroup::gatherLocation(temp);
                              *(float *)&bestGroupDifferencea = RGE_Static_Object::distance_to_position(
                                                                  v60,
                                                                  v63->x,
                                                                  v62,
                                                                  v61);
                              if ( v108 == -1.0 || *(float *)&bestGroupDifferencea < (double)v108 )
                              {
                                if ( v55 > v2->workingArea.maximumSizeValue - 1 )
                                {
                                  v64 = v55 + 1;
                                  v65 = (int *)operator new(4 * v55 + 4);
                                  if ( v65 )
                                  {
                                    for ( jj = 0;
                                          jj < v2->workingArea.maximumSizeValue;
                                          v65[jj - 1] = v2->workingArea.value[jj - 1] )
                                    {
                                      if ( jj >= v64 )
                                        break;
                                      ++jj;
                                    }
                                    operator delete(v2->workingArea.value);
                                    v2->workingArea.value = v65;
                                    v2->workingArea.maximumSizeValue = v64;
                                  }
                                }
                                v108 = *(float *)&bestGroupDifferencea;
                                unitDistancea = *(float *)&v2->workingArea.value[v55];
                              }
                            }
                          }
                          ++v55;
                        }
                        while ( v55 < v2->workingArea.numberValue );
                        v7 = temp;
                        v54 = LODWORD(unitDistancea);
                      }
                      if ( v54 == -1 )
                        break;
                      TribeTacticalAIModule::removeFromGroup(v2, v54);
                      TacticalAIGroup::addUnit(v7, v54, v2->md);
                      v67 = v2->workingArea.maximumSizeValue;
                      v68 = 0;
                      if ( v67 > 0 )
                      {
                        v69 = v2->workingArea.value;
                        do
                        {
                          if ( *v69 == v54 )
                            break;
                          ++v68;
                          ++v69;
                        }
                        while ( v68 < v67 );
                      }
                      if ( v68 < v67 )
                      {
                        if ( v68 < v67 - 1 )
                        {
                          do
                          {
                            ++v68;
                            v2->workingArea.value[v68 - 1] = v2->workingArea.value[v68];
                          }
                          while ( v68 < v2->workingArea.maximumSizeValue - 1 );
                        }
                        v70 = v2->workingArea.numberValue - 1;
                        v2->workingArea.numberValue = v70;
                        if ( v70 < 0 )
                          v2->workingArea.numberValue = 0;
                      }
                      v71 = TacticalAIGroup::desiredNumberUnits(v7);
                    }
                    while ( TacticalAIGroup::numberUnits(v7) < v71 );
                  }
                }
                else
                {
                  for ( kk = 0; kk < v2->workingArea.numberValue; ++kk )
                  {
                    if ( kk > v2->workingArea.maximumSizeValue - 1 )
                    {
                      v43 = kk + 1;
                      v44 = (int *)operator new(4 * kk + 4);
                      if ( v44 )
                      {
                        for ( ll = 0; ll < v2->workingArea.maximumSizeValue; v44[ll - 1] = v2->workingArea.value[ll - 1] )
                        {
                          if ( ll >= v43 )
                            break;
                          ++ll;
                        }
                        operator delete(v2->workingArea.value);
                        v2->workingArea.value = v44;
                        v2->workingArea.maximumSizeValue = v43;
                      }
                    }
                    v46 = MainDecisionAIModule::object(
                            (MainDecisionAIModule *)&v2->md->vfptr,
                            v2->workingArea.value[kk]);
                    if ( v46 && bestGroup == (TacticalAIGroup *)(unsigned __int8)RGE_Static_Object::currentZone(v46) )
                    {
                      if ( kk > v2->workingArea.maximumSizeValue - 1 )
                      {
                        v47 = kk + 1;
                        v48 = (int *)operator new(4 * kk + 4);
                        if ( v48 )
                        {
                          for ( mm = 0; mm < v2->workingArea.maximumSizeValue; v48[mm - 1] = v2->workingArea.value[mm - 1] )
                          {
                            if ( mm >= v47 )
                              break;
                            ++mm;
                          }
                          operator delete(v2->workingArea.value);
                          v2->workingArea.value = v48;
                          v2->workingArea.maximumSizeValue = v47;
                        }
                      }
                      TribeTacticalAIModule::removeFromGroup(v2, v2->workingArea.value[kk]);
                      if ( kk > v2->workingArea.maximumSizeValue - 1 )
                      {
                        v50 = kk + 1;
                        v51 = (int *)operator new(4 * kk + 4);
                        if ( v51 )
                        {
                          for ( nn = 0; nn < v2->workingArea.maximumSizeValue; v51[nn - 1] = v2->workingArea.value[nn - 1] )
                          {
                            if ( nn >= v50 )
                              break;
                            ++nn;
                          }
                          operator delete(v2->workingArea.value);
                          v2->workingArea.value = v51;
                          v2->workingArea.maximumSizeValue = v50;
                        }
                      }
                      TacticalAIGroup::addUnit(temp, v2->workingArea.value[kk], v2->md);
                    }
                  }
                }
                v7 = temp->next;
              }
              else
              {
                v7 = v7->next;
              }
            }
          }
          else
          {
            v7 = v7->next;
          }
        }
        else
        {
          v7 = v7->next;
        }
      }
      v74 = __OFSUB__(a + 1, 102);
      v72 = a == 101;
      v73 = a++ - 101 < 0;
    }
    while ( (unsigned __int8)(v73 ^ v74) | v72 );
  }
  if ( TribeTacticalAIModule::numberUngroupedSoldiers(v2) )
  {
    v75 = 0;
    tempa = 0;
    if ( v2->workingArea.numberValue > 0 )
    {
      while ( 1 )
      {
        if ( v75 > v2->workingArea.maximumSizeValue - 1 )
        {
          v76 = v75 + 1;
          v77 = (int *)operator new(4 * v75 + 4);
          if ( v77 )
          {
            for ( i1 = 0; i1 < v2->workingArea.maximumSizeValue; v77[i1 - 1] = v2->workingArea.value[i1 - 1] )
            {
              if ( i1 >= v76 )
                break;
              ++i1;
            }
            operator delete(v2->workingArea.value);
            v2->workingArea.value = v77;
            v2->workingArea.maximumSizeValue = v76;
          }
        }
        v79 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v2->workingArea.value[v75]);
        if ( v79 )
        {
          v80 = RGE_Static_Object::currentZone(v79);
          v81 = v2->groups.next;
          v82 = (int)&v2->groups;
          v83 = 0;
          unitZone = v80;
          for ( bestGroupa = 0; v81 != &v2->groups; v82 = (int)&v2->groups )
          {
            if ( !v81 )
              break;
            if ( (TacticalAIGroup::type(v81) == 100
               || TacticalAIGroup::type(v81) == 101
               || TacticalAIGroup::type(v81) == 102)
              && TacticalAIGroup::inUse(v81) != 1 )
            {
              v84 = TacticalAIGroup::commander(v81);
              v85 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v84);
              if ( v85 )
              {
                if ( unitZone == RGE_Static_Object::currentZone(v85) )
                {
                  v86 = TacticalAIGroup::desiredNumberUnits(v81);
                  if ( TacticalAIGroup::numberUnits(v81) < v86
                    && (TacticalAIGroup::action(v81) == 1 || !TacticalAIGroup::action(v81)) )
                  {
                    v87 = TacticalAIGroup::desiredNumberUnits(v81);
                    v88 = v87 - TacticalAIGroup::numberUnits(v81);
                    if ( !bestGroupa || v88 > v83 )
                    {
                      bestGroupa = v81;
                      v83 = v88;
                    }
                  }
                }
              }
            }
            v81 = v81->next;
          }
          v89 = 0;
          if ( bestGroupa )
          {
            if ( (signed int)tempa > v2->workingArea.maximumSizeValue - 1 )
            {
              v90 = (int)&tempa->vfptr + 1;
              v91 = (int *)operator new(4 * (_DWORD)tempa + 4);
              if ( v91 )
              {
                for ( i2 = 0; i2 < v2->workingArea.maximumSizeValue; v91[i2 - 1] = v2->workingArea.value[i2 - 1] )
                {
                  if ( i2 >= v90 )
                    break;
                  ++i2;
                }
                operator delete(v2->workingArea.value);
                v2->workingArea.value = v91;
                v2->workingArea.maximumSizeValue = v90;
              }
            }
            TacticalAIGroup::addUnit(bestGroupa, v2->workingArea.value[(_DWORD)tempa], v2->md);
          }
          else
          {
            v93 = v2->groups.next;
            bestGroupb = 0;
            for ( bestGroupDifferenceb = 0; v93 != (TacticalAIGroup *)v82; v93 = v93->next )
            {
              if ( !v93 )
                break;
              if ( (TacticalAIGroup::type(v93) == 100
                 || TacticalAIGroup::type(v93) == 101
                 || TacticalAIGroup::type(v93) == 102)
                && TacticalAIGroup::inUse(v93) != 1
                && (TacticalAIGroup::action(v93) == 1 || !TacticalAIGroup::action(v93))
                && (TacticalAIGroup::type(v93) != 100 || TacticalAIGroup::numberUnits(v93) < v2->sn[26])
                && (TacticalAIGroup::type(v93) != 101 || TacticalAIGroup::numberUnits(v93) < v2->sn[28])
                && (TacticalAIGroup::type(v93) != 102 || TacticalAIGroup::numberUnits(v93) < v2->sn[44]) )
              {
                v94 = TacticalAIGroup::commander(v93);
                v95 = MainDecisionAIModule::object((MainDecisionAIModule *)&v2->md->vfptr, v94);
                if ( v95 )
                {
                  if ( RGE_Static_Object::currentZone(v95) == unitZone )
                  {
                    v96 = TacticalAIGroup::desiredNumberUnits(v93);
                    v97 = TacticalAIGroup::numberUnits(v93) - v96;
                    v89 = bestGroupb;
                    if ( !bestGroupb || v97 < bestGroupDifferenceb )
                    {
                      v89 = v93;
                      bestGroupDifferenceb = v97;
                      bestGroupb = v93;
                    }
                  }
                }
              }
            }
            if ( !v89 )
              return;
            if ( (signed int)tempa > v2->workingArea.maximumSizeValue - 1 )
            {
              v98 = (int)&tempa->vfptr + 1;
              v99 = (int *)operator new(4 * (_DWORD)tempa + 4);
              if ( v99 )
              {
                for ( i3 = 0; i3 < v2->workingArea.maximumSizeValue; v99[i3 - 1] = v2->workingArea.value[i3 - 1] )
                {
                  if ( i3 >= v98 )
                    break;
                  ++i3;
                }
                operator delete(v2->workingArea.value);
                v2->workingArea.value = v99;
                v2->workingArea.maximumSizeValue = v98;
              }
            }
            TacticalAIGroup::addUnit(v89, v2->workingArea.value[(_DWORD)tempa], v2->md);
          }
        }
        tempa = (TacticalAIGroup *)((char *)tempa + 1);
        if ( (signed int)tempa >= v2->workingArea.numberValue )
          return;
        v75 = (int)tempa;
      }
    }
  }
}

//----- (004FD2F0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUngroupedSoldiers(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  int v6; // edi@8
  int v7; // ebx@10
  int *v8; // edi@10
  int k; // eax@11
  int v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ebx@21
  int *v14; // edi@21
  int l; // eax@22
  int rNum; // [sp+8h] [bp-Ch]@1
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  rNum = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->soldiers.numberValue; i = v2 )
  {
    if ( v2 > v1->soldiers.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->soldiers.maximumSizeValue; v4[j - 1] = v1->soldiers.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->soldiers.value);
        v1->soldiers.value = v4;
        v1->soldiers.maximumSizeValue = v3;
      }
    }
    v6 = v2;
    if ( !TribeTacticalAIModule::groupUnitIsIn(v1, v1->soldiers.value[v2]) )
    {
      if ( v2 > v1->soldiers.maximumSizeValue - 1 )
      {
        v7 = v2 + 1;
        v8 = (int *)operator new(v6 * 4 + 4);
        if ( v8 )
        {
          for ( k = 0; k < v1->soldiers.maximumSizeValue; v8[k - 1] = v1->soldiers.value[k - 1] )
          {
            if ( k >= v7 )
              break;
            ++k;
          }
          operator delete(v1->soldiers.value);
          v1->soldiers.value = v8;
          v1->soldiers.maximumSizeValue = v7;
        }
        v6 = v2;
      }
      v10 = 0;
      v11 = v1->soldiers.value[v6];
      v12 = v1->workingArea.numberValue;
      if ( v12 > 0 )
      {
        do
        {
          if ( v10 >= v1->workingArea.maximumSizeValue )
            break;
          if ( v1->workingArea.value[v10] == v11 )
            goto LABEL_27;
          ++v10;
        }
        while ( v10 < v12 );
      }
      if ( v12 > v1->workingArea.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * (v12 + 1));
        if ( v14 )
        {
          for ( l = 0; l < v1->workingArea.maximumSizeValue; v14[l - 1] = v1->workingArea.value[l - 1] )
          {
            if ( l >= v13 )
              break;
            ++l;
          }
          operator delete(v1->workingArea.value);
          v1->workingArea.value = v14;
          v1->workingArea.maximumSizeValue = v13;
        }
      }
      v1->workingArea.value[v1->workingArea.numberValue++] = v11;
LABEL_27:
      v2 = i;
      ++rNum;
    }
    ++v2;
  }
  return rNum;
}

//----- (004FD4F0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberExtraGroupedSoldiers(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  TacticalAIGroup *v2; // ebx@1
  int v3; // edi@8
  int v4; // edi@9
  int v5; // ebp@11
  int v6; // eax@12
  int v7; // ecx@12
  int v8; // edx@12
  int v9; // eax@12
  int v10; // ebp@17
  int *v11; // edi@17
  int k; // eax@18
  int j; // [sp+10h] [bp-10h]@9
  int tempCount; // [sp+14h] [bp-Ch]@9
  int rNum; // [sp+18h] [bp-8h]@1
  int i; // [sp+1Ch] [bp-4h]@12

  v1 = this;
  rNum = 0;
  this->workingArea.numberValue = 0;
  v2 = this->groups.next;
  if ( v2 != &this->groups )
  {
    do
    {
      if ( !v2 )
        break;
      if ( (TacticalAIGroup::type(v2) == 100 || TacticalAIGroup::type(v2) == 101 || TacticalAIGroup::type(v2) == 102)
        && (TacticalAIGroup::action(v2) == 1 || !TacticalAIGroup::action(v2)) )
      {
        v3 = TacticalAIGroup::desiredNumberUnits(v2);
        if ( TacticalAIGroup::numberUnits(v2) > v3 )
        {
          v4 = 0;
          tempCount = TacticalAIGroup::numberUnits(v2);
          for ( j = 0; tempCount > TacticalAIGroup::desiredNumberUnits(v2); j = ++v4 )
          {
            if ( v4 >= TacticalAIGroup::numberUnits(v2) )
              break;
            v5 = TacticalAIGroup::unit(v2, v4);
            if ( v5 != TacticalAIGroup::commander(v2) )
            {
              --tempCount;
              v6 = TacticalAIGroup::unit(v2, v4);
              v7 = v1->workingArea.numberValue;
              v8 = v6;
              v9 = 0;
              for ( i = v8; v9 < v7; ++v9 )
              {
                if ( v9 >= v1->workingArea.maximumSizeValue )
                  break;
                if ( v1->workingArea.value[v9] == v8 )
                  goto LABEL_24;
              }
              if ( v7 > v1->workingArea.maximumSizeValue - 1 )
              {
                v10 = v7 + 1;
                v11 = (int *)operator new(4 * (v7 + 1));
                if ( v11 )
                {
                  for ( k = 0; k < v1->workingArea.maximumSizeValue; v11[k - 1] = v1->workingArea.value[k - 1] )
                  {
                    if ( k >= v10 )
                      break;
                    ++k;
                  }
                  operator delete(v1->workingArea.value);
                  v1->workingArea.value = v11;
                  v1->workingArea.maximumSizeValue = v10;
                }
                v8 = i;
                v4 = j;
              }
              v1->workingArea.value[v1->workingArea.numberValue++] = v8;
LABEL_24:
              ++rNum;
            }
          }
        }
      }
      v2 = v2->next;
    }
    while ( v2 != &v1->groups );
  }
  return rNum;
}

//----- (004FD6D0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUngroupedArtifacts(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  int v6; // edi@8
  int v7; // ebx@10
  int *v8; // edi@10
  int k; // eax@11
  int v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ebx@21
  int *v14; // edi@21
  int l; // eax@22
  int rNum; // [sp+8h] [bp-Ch]@1
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  rNum = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->artifacts.numberValue; i = v2 )
  {
    if ( v2 > v1->artifacts.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->artifacts.maximumSizeValue; v4[j - 1] = v1->artifacts.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->artifacts.value);
        v1->artifacts.value = v4;
        v1->artifacts.maximumSizeValue = v3;
      }
    }
    v6 = v2;
    if ( !TribeTacticalAIModule::groupUnitIsIn(v1, v1->artifacts.value[v2]) )
    {
      if ( v2 > v1->artifacts.maximumSizeValue - 1 )
      {
        v7 = v2 + 1;
        v8 = (int *)operator new(v6 * 4 + 4);
        if ( v8 )
        {
          for ( k = 0; k < v1->artifacts.maximumSizeValue; v8[k - 1] = v1->artifacts.value[k - 1] )
          {
            if ( k >= v7 )
              break;
            ++k;
          }
          operator delete(v1->artifacts.value);
          v1->artifacts.value = v8;
          v1->artifacts.maximumSizeValue = v7;
        }
        v6 = v2;
      }
      v10 = 0;
      v11 = v1->artifacts.value[v6];
      v12 = v1->workingArea.numberValue;
      if ( v12 > 0 )
      {
        do
        {
          if ( v10 >= v1->workingArea.maximumSizeValue )
            break;
          if ( v1->workingArea.value[v10] == v11 )
            goto LABEL_27;
          ++v10;
        }
        while ( v10 < v12 );
      }
      if ( v12 > v1->workingArea.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * (v12 + 1));
        if ( v14 )
        {
          for ( l = 0; l < v1->workingArea.maximumSizeValue; v14[l - 1] = v1->workingArea.value[l - 1] )
          {
            if ( l >= v13 )
              break;
            ++l;
          }
          operator delete(v1->workingArea.value);
          v1->workingArea.value = v14;
          v1->workingArea.maximumSizeValue = v13;
        }
      }
      v1->workingArea.value[v1->workingArea.numberValue++] = v11;
LABEL_27:
      v2 = i;
      ++rNum;
    }
    ++v2;
  }
  return rNum;
}

//----- (004FD8D0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::displaySoldierGroups(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // edi@1
  TacticalAIGroup *i; // esi@1
  int v3; // ST40_4@8
  int v4; // ST3C_4@8
  int v5; // ST40_4@10
  int v6; // ST3C_4@10
  int v7; // ST40_4@12
  int v8; // ST3C_4@12
  int v9; // ST40_4@14
  int v10; // ST3C_4@14
  int v11; // ST40_4@15
  int v12; // ST3C_4@15
  int v13; // ST38_4@15
  int v14; // ST34_4@15
  int v15; // eax@15
  int v16; // eax@15
  RGE_Static_Object *v17; // ebx@15
  int v18; // ST40_4@16
  int v19; // ST3C_4@16
  int v20; // ST38_4@16
  int v21; // ST34_4@16
  char *v22; // ST30_4@16
  int v23; // eax@16
  int v24; // ST40_4@17
  int v25; // ST3C_4@17
  int v26; // ST38_4@17
  int v27; // ST34_4@17
  int v28; // eax@17
  unsigned int v29; // ST40_4@18
  int v30; // ST3C_4@18
  int v31; // eax@18
  double v32; // ST3C_8@18
  Waypoint *v33; // eax@18
  double v34; // ST3C_8@18
  Waypoint *v35; // eax@18
  double v36; // ST3C_8@18
  Waypoint *v37; // eax@18
  double v38; // ST3C_8@18
  double v39; // st7@18
  int v40; // eax@18
  int v41; // ebx@19
  int v42; // eax@20
  RGE_Static_Object *v43; // eax@20
  int v44; // eax@21
  char *v45; // ST40_4@22
  int v46; // eax@22
  int j; // ebp@24
  int v48; // eax@25
  RGE_Static_Object *v49; // eax@25
  RGE_Static_Object *v50; // ebx@25
  UnitAIModule *v51; // eax@29
  double v52; // ST3C_8@29
  UnitAIModule *v53; // eax@29
  double v54; // ST34_8@29
  double v55; // ST2C_8@29
  double v56; // ST24_8@29
  UnitAIModule *v57; // eax@29
  int v58; // ST20_4@29
  UnitAIModule *v59; // eax@29
  int v60; // ST1C_4@29
  UnitAIModule *v61; // eax@29
  int v62; // ST18_4@29
  UnitAIModule *v63; // eax@29
  int v64; // ST14_4@29
  int v65; // ST10_4@29
  char *v66; // ST0C_4@29
  int v67; // eax@29
  UnitAIModule *v68; // eax@29
  UnitAIModule *v69; // eax@30
  int v70; // eax@30
  RGE_Static_Object *v71; // eax@30
  signed int v72; // ebx@35
  double v73; // ST3C_8@36
  double v74; // st7@36
  char v75; // al@37

  v1 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aSoldierGroups);
  for ( i = v1->groups.next; i != &v1->groups; i = i->next )
  {
    if ( !i )
      break;
    if ( TacticalAIGroup::type(i) == 100
      || TacticalAIGroup::type(i) == 101
      || TacticalAIGroup::type(i) == 102
      || TacticalAIGroup::type(i) == 109 )
    {
      if ( TacticalAIGroup::type(i) == 100 )
      {
        v3 = TacticalAIGroup::type(i);
        v4 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDAttack, v4, v3);
      }
      else if ( TacticalAIGroup::type(i) == 101 )
      {
        v5 = TacticalAIGroup::type(i);
        v6 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDDefend, v6, v5);
      }
      else if ( TacticalAIGroup::type(i) == 102 )
      {
        v7 = TacticalAIGroup::type(i);
        v8 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDExplor, v8, v7);
      }
      else if ( TacticalAIGroup::type(i) == 109 )
      {
        v9 = TacticalAIGroup::type(i);
        v10 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDArtifa, v10, v9);
      }
      v11 = TacticalAIGroup::inUse(i);
      v12 = TacticalAIGroup::action(i);
      v13 = TacticalAIGroup::originalUnitNumber(i);
      v14 = TacticalAIGroup::desiredNumberUnits(i);
      v15 = TacticalAIGroup::numberUnits(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aNumunitsDDesnu, v15, v14, v13, v12, v11);
      v16 = TacticalAIGroup::target(i);
      v17 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v16);
      if ( v17 )
      {
        v18 = TacticalAIGroup::waitCode(i);
        v19 = TacticalAIGroup::originalHitPoints(i);
        v20 = TacticalAIGroup::currentHitPoints(i, v1->md);
        v21 = TacticalAIGroup::commander(i);
        v22 = v17->master_obj->name;
        v23 = TacticalAIGroup::target(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aTargetDSComman, v23, v22, v21, v20, v19, v18);
      }
      else
      {
        v24 = TacticalAIGroup::waitCode(i);
        v25 = TacticalAIGroup::originalHitPoints(i);
        v26 = TacticalAIGroup::currentHitPoints(i, v1->md);
        v27 = TacticalAIGroup::commander(i);
        v28 = TacticalAIGroup::target(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aTargetDCommand, v28, v27, v26, v25, v24);
      }
      v29 = TacticalAIGroup::consecutiveIdleUnitCount(i);
      v30 = TacticalAIGroup::assistGroupType(i);
      v31 = TacticalAIGroup::assistGroupID(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aAssistgroupidD, v31, v30, v29);
      v32 = TacticalAIGroup::location(i)->y;
      v33 = TacticalAIGroup::location(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aLocationFF_, v33->x, v32);
      v34 = TacticalAIGroup::gatherLocation(i)->y;
      v35 = TacticalAIGroup::gatherLocation(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGatherLocation, v35->x, v34);
      v36 = TacticalAIGroup::retreatLocation(i)->y;
      v37 = TacticalAIGroup::retreatLocation(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aRetreatLocatio, v37->x, v36);
      v38 = TacticalAIGroup::targetLocation(i)->y;
      v39 = TacticalAIGroup::targetLocation(i)->x;
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aTargetLocation, v39, v38);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aPlayD_, i->playNumberValue);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aNumberobjectst, i->numberObjectsToDestroyValue);
      v40 = i->numberObjectsToDestroyValue;
      if ( v40 > 0 )
      {
        v41 = 0;
        if ( v40 > 0 )
        {
          do
          {
            v42 = TacticalAIGroup::objectToDestroy(i, v41);
            v43 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v42);
            if ( v43 )
            {
              v45 = v43->master_obj->name;
              v46 = TacticalAIGroup::objectToDestroy(i, v41);
              AIModule::logCommonHistory((AIModule *)&v1->vfptr, aObjecttodest_1, v41, v46, v45);
            }
            else
            {
              v44 = TacticalAIGroup::objectToDestroy(i, v41);
              AIModule::logCommonHistory((AIModule *)&v1->vfptr, aObjecttodestro, v41, v44);
            }
            ++v41;
          }
          while ( v41 < i->numberObjectsToDestroyValue );
        }
      }
      for ( j = 0; j < TacticalAIGroup::numberUnits(i); ++j )
      {
        v48 = TacticalAIGroup::unit(i, j);
        v49 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v48);
        v50 = v49;
        if ( v49 )
        {
          if ( RGE_Static_Object::unitAI(v49) )
          {
            v51 = RGE_Static_Object::unitAI(v50);
            v52 = UnitAIModule::currentTargetY(v51);
            v53 = RGE_Static_Object::unitAI(v50);
            v54 = UnitAIModule::currentTargetX(v53);
            v55 = v50->world_y;
            v56 = v50->world_x;
            v57 = RGE_Static_Object::unitAI(v50);
            v58 = UnitAIModule::currentOrderPriority(v57);
            v59 = RGE_Static_Object::unitAI(v50);
            v60 = UnitAIModule::currentOrder(v59);
            v61 = RGE_Static_Object::unitAI(v50);
            v62 = UnitAIModule::currentTarget(v61);
            v63 = RGE_Static_Object::unitAI(v50);
            v64 = UnitAIModule::currentAction(v63);
            v65 = v50->object_state;
            v66 = v50->master_obj->name;
            v67 = TacticalAIGroup::unit(i, j);
            AIModule::logCommonHistory(
              (AIModule *)&v1->vfptr,
              aUnitDSStateDAc,
              v67,
              v66,
              v65,
              v64,
              v62,
              v60,
              v58,
              v56,
              v55,
              v54,
              v52);
            v68 = RGE_Static_Object::unitAI(v50);
            if ( UnitAIModule::currentTarget(v68) != -1 )
            {
              v69 = RGE_Static_Object::unitAI(v50);
              v70 = UnitAIModule::currentTarget(v69);
              v71 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v70);
              if ( v71 )
                AIModule::logCommonHistory(
                  (AIModule *)&v1->vfptr,
                  aTargetSOwnerD_,
                  v71->master_obj->name,
                  v71->owner->id);
            }
          }
          else
          {
            AIModule::logCommonHistory((AIModule *)&v1->vfptr, aUnitDHasInvali);
          }
        }
        else
        {
          AIModule::logCommonHistory((AIModule *)&v1->vfptr, aUnitDIsInvalid);
        }
      }
      if ( TacticalAIGroup::numberAttackWaypoints(i) )
      {
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aWaypoints);
        v72 = 0;
        if ( TacticalAIGroup::numberAttackWaypoints(i) )
        {
          do
          {
            v73 = TacticalAIGroup::attackWaypoint(i, v72)->y;
            v74 = TacticalAIGroup::attackWaypoint(i, v72)->x;
            AIModule::logCommonHistory((AIModule *)&v1->vfptr, aFF_, v74, v73);
            ++v72;
          }
          while ( v72 < (unsigned __int8)TacticalAIGroup::numberAttackWaypoints(i) );
        }
        v75 = TacticalAIGroup::currentAttackWaypoint(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aCurrentWaypoin, (unsigned __int8)v75);
      }
      else
      {
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aNoWaypoints_);
      }
    }
  }
}

//----- (004FDE00) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::setupBoatGroups(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ecx@1
  TacticalAIGroup *v3; // edi@1
  int v4; // eax@8
  int v5; // ebx@8
  int v6; // eax@8
  int *v7; // edx@9
  int v8; // ebx@20
  int *v9; // edi@21
  int j; // eax@22
  int v11; // ebx@29
  int *v12; // edi@29
  int k; // eax@30
  int v14; // ebp@34
  int v15; // eax@34
  int v16; // edi@34
  int v17; // ecx@35
  int *v18; // edx@36
  int v19; // eax@42
  TacticalAIGroup *v20; // eax@44
  TacticalAIGroup *v21; // ebx@44
  int v22; // ecx@45
  int v23; // eax@45
  int *v24; // edx@46
  int v25; // eax@52
  int v26; // ebx@57
  int *v27; // edi@57
  int l; // eax@58
  int v29; // ebp@62
  int v30; // eax@62
  int v31; // edi@62
  int v32; // ecx@63
  int *v33; // edx@64
  int v34; // eax@70
  TacticalAIGroup *v35; // eax@72
  TacticalAIGroup *v36; // ebx@72
  int v37; // ecx@73
  int v38; // eax@73
  int *v39; // edx@74
  int v40; // eax@80
  int v41; // ebx@85
  int *v42; // edi@85
  int m; // eax@86
  int v44; // ebp@90
  int v45; // eax@90
  int v46; // edi@90
  int v47; // ecx@91
  int *v48; // edx@92
  int v49; // eax@98
  TacticalAIGroup *v50; // eax@100
  TacticalAIGroup *v51; // ebx@100
  int v52; // ecx@101
  int v53; // eax@101
  int *v54; // edx@102
  int v55; // eax@108
  int *v56; // edi@112
  signed int n; // eax@113
  int v58; // ebp@120
  int v59; // edi@122
  int v60; // ecx@123
  int v61; // eax@128
  int v62; // eax@130
  int v63; // ecx@131
  int v64; // eax@133
  int v65; // ebx@136
  int v66; // ebp@136
  TacticalAIGroup *v67; // edi@137
  TacticalAIGroup *v68; // eax@146
  int v69; // eax@148
  TacticalAIGroup *v70; // edi@150
  TacticalAIGroup *v71; // eax@157
  int v72; // eax@158
  int v73; // ebx@159
  bool v74; // zf@159
  bool v75; // sf@159
  unsigned __int8 v76; // of@159
  TacticalAIGroup *v77; // eax@160
  TacticalAIGroup *v78; // edi@160
  TacticalAIGroup *v79; // eax@164
  int v80; // eax@165
  int i; // [sp+18h] [bp-38h]@19
  int ia; // [sp+18h] [bp-38h]@119
  int numEGroups; // [sp+1Ch] [bp-34h]@27
  int numPotentialAGroups; // [sp+20h] [bp-30h]@120
  int numPotentialEGroups; // [sp+24h] [bp-2Ch]@119
  int numDGroups; // [sp+28h] [bp-28h]@27
  int v87; // [sp+2Ch] [bp-24h]@125
  int numAGroups; // [sp+30h] [bp-20h]@27
  ManagedArray<int> groupsToRemove; // [sp+34h] [bp-1Ch]@1
  int v90; // [sp+4Ch] [bp-4h]@1

  v1 = this;
  v2 = 0;
  groupsToRemove.value = 0;
  groupsToRemove.numberValue = 0;
  groupsToRemove.desiredNumberValue = 0;
  groupsToRemove.maximumSizeValue = 0;
  v3 = v1->groups.next;
  v90 = 0;
  while ( v3 != &v1->groups )
  {
    if ( !v3 )
      break;
    if ( TacticalAIGroup::type(v3) == 103 || TacticalAIGroup::type(v3) == 104 || TacticalAIGroup::type(v3) == 105 )
    {
      if ( TacticalAIGroup::numberUnits(v3) )
      {
        v2 = groupsToRemove.numberValue;
      }
      else
      {
        v4 = TacticalAIGroup::id(v3);
        v2 = groupsToRemove.numberValue;
        v5 = v4;
        v6 = 0;
        if ( groupsToRemove.numberValue > 0 )
        {
          v7 = groupsToRemove.value;
          do
          {
            if ( v6 >= groupsToRemove.maximumSizeValue )
              break;
            if ( *v7 == v5 )
              goto LABEL_17;
            ++v6;
            ++v7;
          }
          while ( v6 < groupsToRemove.numberValue );
        }
        if ( groupsToRemove.numberValue > groupsToRemove.maximumSizeValue - 1 )
        {
          ManagedArray<int>::resize(&groupsToRemove, groupsToRemove.numberValue + 1);
          v2 = groupsToRemove.numberValue;
        }
        groupsToRemove.value[v2] = v5;
        v2 = groupsToRemove.numberValue++ + 1;
      }
LABEL_17:
      v3 = v3->next;
    }
    else
    {
      v3 = v3->next;
      v2 = groupsToRemove.numberValue;
    }
  }
  i = 0;
  if ( v2 > 0 )
  {
    do
    {
      v8 = i;
      if ( i > groupsToRemove.maximumSizeValue - 1 )
      {
        v9 = (int *)operator new(4 * i + 4);
        if ( v9 )
        {
          for ( j = 0; j < groupsToRemove.maximumSizeValue; v9[j - 1] = groupsToRemove.value[j - 1] )
          {
            if ( j >= i + 1 )
              break;
            ++j;
          }
          operator delete(groupsToRemove.value);
          groupsToRemove.value = v9;
          groupsToRemove.maximumSizeValue = i + 1;
        }
      }
      TribeTacticalAIModule::removeGroup(v1, groupsToRemove.value[i++]);
    }
    while ( v8 + 1 < groupsToRemove.numberValue );
  }
  numAGroups = TribeTacticalAIModule::numberGroups(v1, 103, -1);
  numDGroups = TribeTacticalAIModule::numberGroups(v1, 104, -1);
  numEGroups = TribeTacticalAIModule::numberGroups(v1, 105, -1);
  TribeTacticalAIModule::numberGroups(v1, 107, -1);
  TribeTacticalAIModule::numberGroups(v1, 108, -1);
  TribeTacticalAIModule::numberGroups(v1, 106, -1);
  TribeTacticalAIModule::numberUngroupedFishingBoats(v1);
  while ( v1->workingArea.numberValue > 0 )
  {
    if ( i > v1->workingArea.maximumSizeValue - 1 )
    {
      v11 = i + 1;
      v12 = (int *)operator new(4 * (i + 1));
      if ( v12 )
      {
        for ( k = 0; k < v1->workingArea.maximumSizeValue; v12[k - 1] = v1->workingArea.value[k - 1] )
        {
          if ( k >= v11 )
            break;
          ++k;
        }
        operator delete(v1->workingArea.value);
        v1->workingArea.value = v12;
        v1->workingArea.maximumSizeValue = v11;
      }
    }
    v14 = v1->workingArea.value[i];
    v15 = (int)MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v14);
    v16 = v15;
    if ( v15 )
    {
      v20 = TribeTacticalAIModule::createGroup(v1, 1);
      v21 = v20;
      if ( !v20 )
        break;
      TacticalAIGroup::setType(v20, 107);
      TacticalAIGroup::setDesiredNumberUnits(v21, v1->sn[65] + 1);
      TacticalAIGroup::addUnit(v21, v14, v1->md);
      TacticalAIGroup::setSpecificCommander(v21, v14, v1->md);
      TacticalAIGroup::setLocation(v21, *(float *)(v16 + 56), *(float *)(v16 + 60), *(float *)(v16 + 64));
      TacticalAIGroup::setGatherLocation(v21, *(float *)(v16 + 56), *(float *)(v16 + 60), *(float *)(v16 + 64));
      TacticalAIGroup::setRetreatLocation(v21, *(float *)(v16 + 56), *(float *)(v16 + 60), *(float *)(v16 + 64));
      v22 = v1->workingArea.maximumSizeValue;
      v23 = 0;
      if ( v22 > 0 )
      {
        v24 = v1->workingArea.value;
        do
        {
          if ( *v24 == v14 )
            break;
          ++v23;
          ++v24;
        }
        while ( v23 < v22 );
      }
      if ( v23 >= v22 )
        continue;
      if ( v23 < v22 - 1 )
      {
        do
        {
          ++v23;
          v1->workingArea.value[v23 - 1] = v1->workingArea.value[v23];
        }
        while ( v23 < v1->workingArea.maximumSizeValue - 1 );
      }
      v25 = v1->workingArea.numberValue - 1;
      v1->workingArea.numberValue = v25;
      if ( v25 >= 0 )
        continue;
    }
    else
    {
      v17 = v1->workingArea.maximumSizeValue;
      if ( v17 > 0 )
      {
        v18 = v1->workingArea.value;
        do
        {
          if ( *v18 == v14 )
            break;
          ++v15;
          ++v18;
        }
        while ( v15 < v17 );
      }
      if ( v15 >= v17 )
        continue;
      if ( v15 < v17 - 1 )
      {
        do
        {
          ++v15;
          v1->workingArea.value[v15 - 1] = v1->workingArea.value[v15];
        }
        while ( v15 < v1->workingArea.maximumSizeValue - 1 );
      }
      v19 = v1->workingArea.numberValue - 1;
      v1->workingArea.numberValue = v19;
      if ( v19 >= 0 )
        continue;
    }
    v1->workingArea.numberValue = 0;
  }
  TribeTacticalAIModule::numberUngroupedTradeBoats(v1);
  while ( v1->workingArea.numberValue > 0 )
  {
    if ( i > v1->workingArea.maximumSizeValue - 1 )
    {
      v26 = i + 1;
      v27 = (int *)operator new(4 * (i + 1));
      if ( v27 )
      {
        for ( l = 0; l < v1->workingArea.maximumSizeValue; v27[l - 1] = v1->workingArea.value[l - 1] )
        {
          if ( l >= v26 )
            break;
          ++l;
        }
        operator delete(v1->workingArea.value);
        v1->workingArea.value = v27;
        v1->workingArea.maximumSizeValue = v26;
      }
    }
    v29 = v1->workingArea.value[i];
    v30 = (int)MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->workingArea.value[i]);
    v31 = v30;
    if ( v30 )
    {
      v35 = TribeTacticalAIModule::createGroup(v1, 1);
      v36 = v35;
      if ( !v35 )
        break;
      TacticalAIGroup::setType(v35, 108);
      TacticalAIGroup::setDesiredNumberUnits(v36, v1->sn[64] + 1);
      TacticalAIGroup::addUnit(v36, v29, v1->md);
      TacticalAIGroup::setSpecificCommander(v36, v29, v1->md);
      TacticalAIGroup::setLocation(v36, *(float *)(v31 + 56), *(float *)(v31 + 60), *(float *)(v31 + 64));
      TacticalAIGroup::setGatherLocation(v36, *(float *)(v31 + 56), *(float *)(v31 + 60), *(float *)(v31 + 64));
      TacticalAIGroup::setRetreatLocation(v36, *(float *)(v31 + 56), *(float *)(v31 + 60), *(float *)(v31 + 64));
      v37 = v1->workingArea.maximumSizeValue;
      v38 = 0;
      if ( v37 > 0 )
      {
        v39 = v1->workingArea.value;
        do
        {
          if ( *v39 == v29 )
            break;
          ++v38;
          ++v39;
        }
        while ( v38 < v37 );
      }
      if ( v38 >= v37 )
        continue;
      if ( v38 < v37 - 1 )
      {
        do
        {
          ++v38;
          v1->workingArea.value[v38 - 1] = v1->workingArea.value[v38];
        }
        while ( v38 < v1->workingArea.maximumSizeValue - 1 );
      }
      v40 = v1->workingArea.numberValue - 1;
      v1->workingArea.numberValue = v40;
      if ( v40 >= 0 )
        continue;
    }
    else
    {
      v32 = v1->workingArea.maximumSizeValue;
      if ( v32 > 0 )
      {
        v33 = v1->workingArea.value;
        do
        {
          if ( *v33 == v29 )
            break;
          ++v30;
          ++v33;
        }
        while ( v30 < v32 );
      }
      if ( v30 >= v32 )
        continue;
      if ( v30 < v32 - 1 )
      {
        do
        {
          ++v30;
          v1->workingArea.value[v30 - 1] = v1->workingArea.value[v30];
        }
        while ( v30 < v1->workingArea.maximumSizeValue - 1 );
      }
      v34 = v1->workingArea.numberValue - 1;
      v1->workingArea.numberValue = v34;
      if ( v34 >= 0 )
        continue;
    }
    v1->workingArea.numberValue = 0;
  }
  TribeTacticalAIModule::numberUngroupedTransportBoats(v1);
  while ( v1->workingArea.numberValue > 0 )
  {
    if ( i > v1->workingArea.maximumSizeValue - 1 )
    {
      v41 = i + 1;
      v42 = (int *)operator new(4 * (i + 1));
      if ( v42 )
      {
        for ( m = 0; m < v1->workingArea.maximumSizeValue; v42[m - 1] = v1->workingArea.value[m - 1] )
        {
          if ( m >= v41 )
            break;
          ++m;
        }
        operator delete(v1->workingArea.value);
        v1->workingArea.value = v42;
        v1->workingArea.maximumSizeValue = v41;
      }
    }
    v44 = v1->workingArea.value[i];
    v45 = (int)MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->workingArea.value[i]);
    v46 = v45;
    if ( v45 )
    {
      v50 = TribeTacticalAIModule::createGroup(v1, 1);
      v51 = v50;
      if ( !v50 )
        break;
      TacticalAIGroup::setType(v50, 106);
      TacticalAIGroup::setDesiredNumberUnits(v51, v1->sn[66] + 1);
      TacticalAIGroup::addUnit(v51, v44, v1->md);
      TacticalAIGroup::setSpecificCommander(v51, v44, v1->md);
      TacticalAIGroup::setLocation(v51, *(float *)(v46 + 56), *(float *)(v46 + 60), *(float *)(v46 + 64));
      TacticalAIGroup::setGatherLocation(v51, *(float *)(v46 + 56), *(float *)(v46 + 60), *(float *)(v46 + 64));
      TacticalAIGroup::setRetreatLocation(v51, *(float *)(v46 + 56), *(float *)(v46 + 60), *(float *)(v46 + 64));
      v52 = v1->workingArea.maximumSizeValue;
      v53 = 0;
      if ( v52 > 0 )
      {
        v54 = v1->workingArea.value;
        do
        {
          if ( *v54 == v44 )
            break;
          ++v53;
          ++v54;
        }
        while ( v53 < v52 );
      }
      if ( v53 >= v52 )
        continue;
      if ( v53 < v52 - 1 )
      {
        do
        {
          ++v53;
          v1->workingArea.value[v53 - 1] = v1->workingArea.value[v53];
        }
        while ( v53 < v1->workingArea.maximumSizeValue - 1 );
      }
      v55 = v1->workingArea.numberValue - 1;
      v1->workingArea.numberValue = v55;
      if ( v55 >= 0 )
        continue;
    }
    else
    {
      v47 = v1->workingArea.maximumSizeValue;
      if ( v47 > 0 )
      {
        v48 = v1->workingArea.value;
        do
        {
          if ( *v48 == v44 )
            break;
          ++v45;
          ++v48;
        }
        while ( v45 < v47 );
      }
      if ( v45 >= v47 )
        continue;
      if ( v45 < v47 - 1 )
      {
        do
        {
          ++v45;
          v1->workingArea.value[v45 - 1] = v1->workingArea.value[v45];
        }
        while ( v45 < v1->workingArea.maximumSizeValue - 1 );
      }
      v49 = v1->workingArea.numberValue - 1;
      v1->workingArea.numberValue = v49;
      if ( v49 >= 0 )
        continue;
    }
    v1->workingArea.numberValue = 0;
  }
  if ( v1->boats.maximumSizeValue - 1 < 0 )
  {
    v56 = (int *)operator new(4u);
    if ( v56 )
    {
      for ( n = 0; n < v1->boats.maximumSizeValue; v56[n - 1] = v1->boats.value[n - 1] )
      {
        if ( n >= 1 )
          break;
        ++n;
      }
      operator delete(v1->boats.value);
      v1->boats.value = v56;
      v1->boats.maximumSizeValue = 1;
    }
  }
  if ( !TribeInformationAIModule::fullyExploredZone(&v1->md->informationAI, *v1->boats.value) )
  {
    TribeTacticalAIModule::removeAllGroups(v1, 105);
    TribeTacticalAIModule::setStrategicNumber(v1, 61, 0);
  }
  ia = 0;
  numPotentialEGroups = 0;
  if ( v1->sn[40] )
  {
    v61 = v1->warBoats.numberValue;
    v58 = v1->warBoats.numberValue;
    if ( v61 >= v1->sn[58] )
      v58 = v1->sn[58];
    v62 = v61 - v58;
    numPotentialAGroups = v58;
    if ( v62 > 0 )
    {
      v63 = v1->sn[67];
      if ( v62 < v63 )
        v63 = v62;
      v64 = v62 - v63;
      ia = v63;
      if ( v64 > 0 )
      {
        numPotentialEGroups = v64;
        if ( v64 >= v1->sn[61] )
          numPotentialEGroups = v1->sn[61];
      }
    }
  }
  else
  {
    v58 = (signed __int64)ceil((double)v1->warBoats.numberValue / (double)v1->sn[59]);
    numPotentialAGroups = v58;
    if ( v58 > v1->sn[58] )
    {
      v58 = v1->sn[58];
      numPotentialAGroups = v1->sn[58];
    }
    v59 = v1->sn[59] * v58;
    if ( v1->warBoats.numberValue - v59 > 0 )
    {
      v60 = (signed __int64)ceil((double)(v1->warBoats.numberValue - v59) / (double)v1->sn[68]);
      ia = v60;
      if ( v60 > v1->sn[67] )
      {
        v60 = v1->sn[67];
        ia = v1->sn[67];
      }
      v87 = v1->warBoats.numberValue - v59 - v1->sn[68] * v60;
      if ( v87 > 0 )
      {
        numPotentialEGroups = (signed __int64)ceil((double)v87 / (double)v1->sn[62]);
        if ( numPotentialEGroups > v1->sn[61] )
          numPotentialEGroups = v1->sn[61];
      }
    }
  }
  v65 = numAGroups;
  v76 = __OFSUB__(numAGroups, v58);
  v75 = numAGroups - v58 < 0;
  v66 = numDGroups;
  if ( v75 ^ v76 )
  {
    do
    {
      v67 = 0;
      if ( v66 > 0 )
      {
        v67 = TribeTacticalAIModule::group(v1, -1, 104, -1, -1);
        if ( v67 )
        {
          --v66;
        }
        else
        {
          v67 = TribeTacticalAIModule::group(v1, -1, 105, -1, -1);
          if ( !v67 )
            goto LABEL_143;
          --numEGroups;
        }
      }
      if ( !v67 )
      {
LABEL_143:
        v67 = TribeTacticalAIModule::createGroup(v1, 1);
        if ( !v67 )
          break;
      }
      TacticalAIGroup::setType(v67, 103);
      TacticalAIGroup::setTarget(v67, -1);
      TacticalAIGroup::setTargetType(v67, -1);
      TacticalAIGroup::setAction(v67, 1);
      TacticalAIGroup::setInUse(v67, 0);
      TacticalAIGroup::setDesiredNumberUnits(v67, v1->sn[59]);
      ++v65;
    }
    while ( v65 < numPotentialAGroups );
  }
  while ( v65 > numPotentialAGroups )
  {
    v68 = TribeTacticalAIModule::group(v1, -1, 103, 0, -1);
    if ( !v68 )
    {
      v68 = TribeTacticalAIModule::group(v1, -1, 103, 1, -1);
      if ( !v68 )
        break;
    }
    v69 = TacticalAIGroup::id(v68);
    TribeTacticalAIModule::removeGroup(v1, v69);
    --v65;
  }
  for ( ; v66 < ia; ++v66 )
  {
    v70 = 0;
    if ( numEGroups > 0 )
    {
      v70 = TribeTacticalAIModule::group(v1, -1, 105, -1, -1);
      if ( !v70 )
        goto LABEL_154;
      --numEGroups;
    }
    if ( !v70 )
    {
LABEL_154:
      v70 = TribeTacticalAIModule::createGroup(v1, 1);
      if ( !v70 )
        break;
    }
    TacticalAIGroup::setType(v70, 104);
    TacticalAIGroup::setTarget(v70, -1);
    TacticalAIGroup::setTargetType(v70, -1);
    TacticalAIGroup::setAction(v70, 1);
    TacticalAIGroup::setInUse(v70, 0);
    TacticalAIGroup::setDesiredNumberUnits(v70, v1->sn[68]);
  }
  while ( v66 > ia )
  {
    v71 = TribeTacticalAIModule::group(v1, -1, 104, -1, -1);
    if ( !v71 )
      break;
    v72 = TacticalAIGroup::id(v71);
    TribeTacticalAIModule::removeGroup(v1, v72);
    --v66;
  }
  v73 = numEGroups;
  v76 = __OFSUB__(numEGroups, numPotentialEGroups);
  v74 = numEGroups == numPotentialEGroups;
  v75 = numEGroups - numPotentialEGroups < 0;
  if ( numEGroups < numPotentialEGroups )
  {
    do
    {
      v77 = TribeTacticalAIModule::createGroup(v1, 1);
      v78 = v77;
      if ( !v77 )
        break;
      TacticalAIGroup::setType(v77, 105);
      TacticalAIGroup::setDesiredNumberUnits(v78, v1->sn[62]);
      ++v73;
    }
    while ( v73 < numPotentialEGroups );
    v76 = __OFSUB__(v73, numPotentialEGroups);
    v74 = v73 == numPotentialEGroups;
    v75 = v73 - numPotentialEGroups < 0;
  }
  if ( !((unsigned __int8)(v75 ^ v76) | v74) )
  {
    do
    {
      v79 = TribeTacticalAIModule::group(v1, -1, 105, -1, -1);
      if ( !v79 )
        break;
      v80 = TacticalAIGroup::id(v79);
      TribeTacticalAIModule::removeGroup(v1, v80);
      --v73;
    }
    while ( v73 > numPotentialEGroups );
  }
  v90 = -1;
  if ( groupsToRemove.value )
    operator delete(groupsToRemove.value);
}

//----- (004FE950) --------------------------------------------------------
void __usercall TribeTacticalAIModule::fillBoatGroups(TribeTacticalAIModule *this@<ecx>, double a2@<st0>)
{
  TribeTacticalAIModule *v2; // esi@1
  TacticalAIGroup *v3; // edi@1
  int i; // ebp@1
  int v5; // ebx@7
  int v6; // eax@8
  int v7; // ebx@14
  TacticalAIGroup *v8; // edi@20
  int v9; // ebx@24
  int v10; // ebx@26
  int v11; // ebp@26
  int l; // ebx@27
  int v13; // ebp@29
  int *v14; // edi@29
  int m; // eax@30
  int v16; // ebx@36
  int v17; // ebp@37
  int v18; // ebx@37
  int v19; // ebp@39
  int *v20; // edi@39
  int j; // eax@40
  RGE_Static_Object *v22; // edi@44
  float v23; // ST08_4@45
  float v24; // ST04_4@45
  Waypoint *v25; // eax@45
  int v26; // ebp@48
  int *v27; // edi@48
  int k; // eax@49
  TacticalAIGroup *v29; // edi@55
  int v30; // ecx@58
  int v31; // eax@58
  int *v32; // edx@59
  int v33; // eax@65
  int v34; // ebx@67
  int v35; // ebx@68
  int v36; // ebx@70
  int v37; // ebp@70
  int jj; // ebx@71
  int v39; // ebp@73
  int *v40; // edi@73
  int kk; // eax@74
  int v42; // ebp@79
  int *v43; // edi@79
  int ll; // eax@80
  int v45; // ebx@86
  int v46; // ebp@87
  int v47; // ebx@87
  int v48; // ebp@89
  int *v49; // edi@89
  int n; // eax@90
  RGE_Static_Object *v51; // edi@94
  float v52; // ST08_4@95
  float v53; // ST04_4@95
  Waypoint *v54; // eax@95
  int v55; // ebp@98
  int *v56; // edi@98
  int ii; // eax@99
  TacticalAIGroup *v58; // edi@105
  int v59; // ecx@108
  int v60; // eax@108
  int *v61; // edx@109
  int v62; // eax@115
  int v63; // ebx@117
  bool v64; // zf@121
  bool v65; // sf@121
  unsigned __int8 v66; // of@121
  TacticalAIGroup *v67; // edi@124
  int v68; // ebp@124
  int v69; // ebx@124
  int v70; // ebp@132
  int v71; // ebp@135
  int v72; // eax@135
  int v73; // ebp@140
  int v74; // ebx@141
  int *v75; // edi@141
  int mm; // eax@142
  TacticalAIGroup *v77; // edi@147
  int v78; // ebx@163
  int v79; // ebx@163
  int v80; // ebx@169
  int *v81; // edi@169
  int nn; // eax@170
  TacticalAIGroup *bestGroup; // [sp+10h] [bp-18h]@20
  TacticalAIGroup *bestGroupa; // [sp+10h] [bp-18h]@124
  TacticalAIGroup *bestGroupb; // [sp+10h] [bp-18h]@147
  float bestDistance; // [sp+14h] [bp-14h]@37
  int bestDistancea; // [sp+14h] [bp-14h]@123
  float v88; // [sp+18h] [bp-10h]@87
  int a; // [sp+1Ch] [bp-Ch]@19
  float unitDistance; // [sp+20h] [bp-8h]@45
  float unitDistancea; // [sp+20h] [bp-8h]@87
  int bestGroupDifference; // [sp+24h] [bp-4h]@37
  int bestGroupDifferencea; // [sp+24h] [bp-4h]@95
  int bestGroupDifferenceb; // [sp+24h] [bp-4h]@147

  v2 = this;
  TribeTacticalAIModule::numberUngroupedWarBoats(this);
  TribeTacticalAIModule::numberExtraGroupedWarBoats(v2);
  v3 = v2->groups.next;
  for ( i = (int)&v2->groups; v3 != (TacticalAIGroup *)i; v3 = v3->next )
  {
    if ( !v3 )
      break;
    if ( (TacticalAIGroup::type(v3) == 103 || TacticalAIGroup::type(v3) == 104 || TacticalAIGroup::type(v3) == 105)
      && TacticalAIGroup::commander(v3) == -1 )
    {
      v5 = TribeTacticalAIModule::numberUngroupedWarBoats(v2);
      if ( TacticalAIGroup::numberUnits(v3) > 0 )
      {
        v6 = TribeTacticalAIModule::selectBestCommander(v2, a2, v3);
        TacticalAIGroup::setSpecificCommander(v3, v6, v2->md);
        if ( TacticalAIGroup::action(v3) && TacticalAIGroup::action(v3) != 1 )
          continue;
LABEL_16:
        TribeTacticalAIModule::setAllGroupLocations(v2, v3);
        continue;
      }
      if ( !v5 )
        TribeTacticalAIModule::numberExtraGroupedWarBoats(v2);
      if ( !v2->workingArea.numberValue )
        return;
      v7 = TribeTacticalAIModule::selectBestCommander(v2, a2, &v2->workingArea);
      TacticalAIGroup::addUnit(v3, v7, v2->md);
      TacticalAIGroup::setSpecificCommander(v3, v7, v2->md);
      if ( !TacticalAIGroup::action(v3) || TacticalAIGroup::action(v3) == 1 )
        goto LABEL_16;
    }
  }
  if ( !v2->sn[40] )
  {
    a = 103;
    do
    {
      v8 = v2->groups.next;
      bestGroup = v2->groups.next;
      if ( v8 != (TacticalAIGroup *)i )
      {
        do
        {
          if ( !v8 )
            break;
          if ( TacticalAIGroup::type(v8) == a )
          {
            v9 = TacticalAIGroup::desiredNumberUnits(v8);
            if ( TacticalAIGroup::numberUnits(v8) < v9 )
            {
              v10 = TribeTacticalAIModule::numberUngroupedWarBoats(v2);
              v11 = TacticalAIGroup::desiredNumberUnits(v8);
              if ( v10 > v11 - TacticalAIGroup::numberUnits(v8) )
              {
                v16 = TacticalAIGroup::desiredNumberUnits(v8);
                if ( TacticalAIGroup::numberUnits(v8) < v16 )
                {
                  do
                  {
                    v17 = -1;
                    v18 = 0;
                    bestGroupDifference = -1;
                    bestDistance = -1.0;
                    if ( v2->workingArea.numberValue <= 0 )
                    {
                      v29 = bestGroup;
                    }
                    else
                    {
                      do
                      {
                        if ( v18 > v2->workingArea.maximumSizeValue - 1 )
                        {
                          v19 = v18 + 1;
                          v20 = (int *)operator new(4 * v18 + 4);
                          if ( v20 )
                          {
                            for ( j = 0; j < v2->workingArea.maximumSizeValue; v20[j - 1] = v2->workingArea.value[j - 1] )
                            {
                              if ( j >= v19 )
                                break;
                              ++j;
                            }
                            operator delete(v2->workingArea.value);
                            v2->workingArea.value = v20;
                            v2->workingArea.maximumSizeValue = v19;
                          }
                        }
                        v22 = MainDecisionAIModule::object(
                                (MainDecisionAIModule *)&v2->md->vfptr,
                                v2->workingArea.value[v18]);
                        if ( v22 )
                        {
                          v23 = TacticalAIGroup::gatherLocation(bestGroup)->z;
                          v24 = TacticalAIGroup::gatherLocation(bestGroup)->y;
                          v25 = TacticalAIGroup::gatherLocation(bestGroup);
                          unitDistance = RGE_Static_Object::distance_to_position(v22, v25->x, v24, v23);
                          if ( bestDistance == -1.0 || unitDistance < (double)bestDistance )
                          {
                            if ( v18 > v2->workingArea.maximumSizeValue - 1 )
                            {
                              v26 = v18 + 1;
                              v27 = (int *)operator new(4 * v18 + 4);
                              if ( v27 )
                              {
                                for ( k = 0; k < v2->workingArea.maximumSizeValue; v27[k - 1] = v2->workingArea.value[k - 1] )
                                {
                                  if ( k >= v26 )
                                    break;
                                  ++k;
                                }
                                operator delete(v2->workingArea.value);
                                v2->workingArea.value = v27;
                                v2->workingArea.maximumSizeValue = v26;
                              }
                            }
                            bestDistance = unitDistance;
                            bestGroupDifference = v2->workingArea.value[v18];
                          }
                        }
                        ++v18;
                      }
                      while ( v18 < v2->workingArea.numberValue );
                      v29 = bestGroup;
                      v17 = bestGroupDifference;
                    }
                    if ( v17 == -1 )
                      break;
                    TacticalAIGroup::addUnit(v29, v17, v2->md);
                    v30 = v2->workingArea.maximumSizeValue;
                    v31 = 0;
                    if ( v30 > 0 )
                    {
                      v32 = v2->workingArea.value;
                      do
                      {
                        if ( *v32 == v17 )
                          break;
                        ++v31;
                        ++v32;
                      }
                      while ( v31 < v30 );
                    }
                    if ( v31 < v30 )
                    {
                      if ( v31 < v30 - 1 )
                      {
                        do
                        {
                          ++v31;
                          v2->workingArea.value[v31 - 1] = v2->workingArea.value[v31];
                        }
                        while ( v31 < v2->workingArea.maximumSizeValue - 1 );
                      }
                      v33 = v2->workingArea.numberValue - 1;
                      v2->workingArea.numberValue = v33;
                      if ( v33 < 0 )
                        v2->workingArea.numberValue = 0;
                    }
                    v34 = TacticalAIGroup::desiredNumberUnits(v29);
                  }
                  while ( TacticalAIGroup::numberUnits(v29) < v34 );
                }
              }
              else
              {
                for ( l = 0; l < v2->workingArea.numberValue; ++l )
                {
                  if ( l > v2->workingArea.maximumSizeValue - 1 )
                  {
                    v13 = l + 1;
                    v14 = (int *)operator new(4 * l + 4);
                    if ( v14 )
                    {
                      for ( m = 0; m < v2->workingArea.maximumSizeValue; v14[m - 1] = v2->workingArea.value[m - 1] )
                      {
                        if ( m >= v13 )
                          break;
                        ++m;
                      }
                      operator delete(v2->workingArea.value);
                      v2->workingArea.value = v14;
                      v2->workingArea.maximumSizeValue = v13;
                    }
                  }
                  TacticalAIGroup::addUnit(bestGroup, v2->workingArea.value[l], v2->md);
                }
              }
              v35 = TacticalAIGroup::desiredNumberUnits(bestGroup);
              if ( TacticalAIGroup::numberUnits(bestGroup) < v35 )
              {
                v36 = TribeTacticalAIModule::numberExtraGroupedWarBoats(v2);
                v37 = TacticalAIGroup::desiredNumberUnits(bestGroup);
                if ( v36 > v37 - TacticalAIGroup::numberUnits(bestGroup) )
                {
                  v45 = TacticalAIGroup::desiredNumberUnits(bestGroup);
                  if ( TacticalAIGroup::numberUnits(bestGroup) < v45 )
                  {
                    do
                    {
                      v46 = -1;
                      v47 = 0;
                      unitDistancea = -6.8056469e38/*NaN*/;
                      v88 = -1.0;
                      if ( v2->workingArea.numberValue <= 0 )
                      {
                        v58 = bestGroup;
                      }
                      else
                      {
                        do
                        {
                          if ( v47 > v2->workingArea.maximumSizeValue - 1 )
                          {
                            v48 = v47 + 1;
                            v49 = (int *)operator new(4 * v47 + 4);
                            if ( v49 )
                            {
                              for ( n = 0; n < v2->workingArea.maximumSizeValue; v49[n - 1] = v2->workingArea.value[n - 1] )
                              {
                                if ( n >= v48 )
                                  break;
                                ++n;
                              }
                              operator delete(v2->workingArea.value);
                              v2->workingArea.value = v49;
                              v2->workingArea.maximumSizeValue = v48;
                            }
                          }
                          v51 = MainDecisionAIModule::object(
                                  (MainDecisionAIModule *)&v2->md->vfptr,
                                  v2->workingArea.value[v47]);
                          if ( v51 )
                          {
                            v52 = TacticalAIGroup::gatherLocation(bestGroup)->z;
                            v53 = TacticalAIGroup::gatherLocation(bestGroup)->y;
                            v54 = TacticalAIGroup::gatherLocation(bestGroup);
                            *(float *)&bestGroupDifferencea = RGE_Static_Object::distance_to_position(
                                                                v51,
                                                                v54->x,
                                                                v53,
                                                                v52);
                            if ( v88 == -1.0 || *(float *)&bestGroupDifferencea < (double)v88 )
                            {
                              if ( v47 > v2->workingArea.maximumSizeValue - 1 )
                              {
                                v55 = v47 + 1;
                                v56 = (int *)operator new(4 * v47 + 4);
                                if ( v56 )
                                {
                                  for ( ii = 0;
                                        ii < v2->workingArea.maximumSizeValue;
                                        v56[ii - 1] = v2->workingArea.value[ii - 1] )
                                  {
                                    if ( ii >= v55 )
                                      break;
                                    ++ii;
                                  }
                                  operator delete(v2->workingArea.value);
                                  v2->workingArea.value = v56;
                                  v2->workingArea.maximumSizeValue = v55;
                                }
                              }
                              v88 = *(float *)&bestGroupDifferencea;
                              unitDistancea = *(float *)&v2->workingArea.value[v47];
                            }
                          }
                          ++v47;
                        }
                        while ( v47 < v2->workingArea.numberValue );
                        v58 = bestGroup;
                        v46 = LODWORD(unitDistancea);
                      }
                      if ( v46 == -1 )
                        break;
                      TribeTacticalAIModule::removeFromGroup(v2, v46);
                      TacticalAIGroup::addUnit(v58, v46, v2->md);
                      v59 = v2->workingArea.maximumSizeValue;
                      v60 = 0;
                      if ( v59 > 0 )
                      {
                        v61 = v2->workingArea.value;
                        do
                        {
                          if ( *v61 == v46 )
                            break;
                          ++v60;
                          ++v61;
                        }
                        while ( v60 < v59 );
                      }
                      if ( v60 < v59 )
                      {
                        if ( v60 < v59 - 1 )
                        {
                          do
                          {
                            ++v60;
                            v2->workingArea.value[v60 - 1] = v2->workingArea.value[v60];
                          }
                          while ( v60 < v2->workingArea.maximumSizeValue - 1 );
                        }
                        v62 = v2->workingArea.numberValue - 1;
                        v2->workingArea.numberValue = v62;
                        if ( v62 < 0 )
                          v2->workingArea.numberValue = 0;
                      }
                      v63 = TacticalAIGroup::desiredNumberUnits(v58);
                    }
                    while ( TacticalAIGroup::numberUnits(v58) < v63 );
                  }
                }
                else
                {
                  for ( jj = 0; jj < v2->workingArea.numberValue; ++jj )
                  {
                    if ( jj > v2->workingArea.maximumSizeValue - 1 )
                    {
                      v39 = jj + 1;
                      v40 = (int *)operator new(4 * jj + 4);
                      if ( v40 )
                      {
                        for ( kk = 0; kk < v2->workingArea.maximumSizeValue; v40[kk - 1] = v2->workingArea.value[kk - 1] )
                        {
                          if ( kk >= v39 )
                            break;
                          ++kk;
                        }
                        operator delete(v2->workingArea.value);
                        v2->workingArea.value = v40;
                        v2->workingArea.maximumSizeValue = v39;
                      }
                    }
                    TribeTacticalAIModule::removeFromGroup(v2, v2->workingArea.value[jj]);
                    if ( jj > v2->workingArea.maximumSizeValue - 1 )
                    {
                      v42 = jj + 1;
                      v43 = (int *)operator new(4 * jj + 4);
                      if ( v43 )
                      {
                        for ( ll = 0; ll < v2->workingArea.maximumSizeValue; v43[ll - 1] = v2->workingArea.value[ll - 1] )
                        {
                          if ( ll >= v42 )
                            break;
                          ++ll;
                        }
                        operator delete(v2->workingArea.value);
                        v2->workingArea.value = v43;
                        v2->workingArea.maximumSizeValue = v42;
                      }
                    }
                    TacticalAIGroup::addUnit(bestGroup, v2->workingArea.value[jj], v2->md);
                  }
                }
                bestGroup = bestGroup->next;
              }
              else
              {
                bestGroup = bestGroup->next;
              }
              v8 = bestGroup;
            }
            else
            {
              v8 = v8->next;
              bestGroup = v8;
            }
          }
          else
          {
            v8 = v8->next;
            bestGroup = v8;
          }
          i = (int)&v2->groups;
        }
        while ( v8 != &v2->groups );
      }
      v66 = __OFSUB__(a + 1, 106);
      v64 = a == 105;
      v65 = a++ - 105 < 0;
    }
    while ( (unsigned __int8)(v65 ^ v66) | v64 );
  }
  if ( TribeTacticalAIModule::numberUngroupedWarBoats(v2) )
  {
    bestDistancea = 0;
    if ( v2->workingArea.numberValue > 0 )
    {
      do
      {
        v67 = v2->groups.next;
        v68 = (int)&v2->groups;
        v69 = 0;
        for ( bestGroupa = 0; v67 != &v2->groups; v68 = (int)&v2->groups )
        {
          if ( !v67 )
            break;
          if ( TacticalAIGroup::type(v67) == 103
            || TacticalAIGroup::type(v67) == 104
            || TacticalAIGroup::type(v67) == 105
            || TacticalAIGroup::type(v67) == 106
            || TacticalAIGroup::type(v67) == 107
            || TacticalAIGroup::type(v67) == 108 )
          {
            v70 = TacticalAIGroup::numberUnits(v67);
            if ( v70 < TacticalAIGroup::desiredNumberUnits(v67)
              && (TacticalAIGroup::action(v67) == 1 || !TacticalAIGroup::action(v67)) )
            {
              v71 = TacticalAIGroup::numberUnits(v67);
              v72 = TacticalAIGroup::desiredNumberUnits(v67) - v71;
              if ( !bestGroupa || v72 > v69 )
              {
                bestGroupa = v67;
                v69 = v72;
              }
            }
          }
          v67 = v67->next;
        }
        if ( bestGroupa )
        {
          v73 = bestDistancea;
          if ( bestDistancea > v2->workingArea.maximumSizeValue - 1 )
          {
            v74 = bestDistancea + 1;
            v75 = (int *)operator new(4 * bestDistancea + 4);
            if ( v75 )
            {
              for ( mm = 0; mm < v2->workingArea.maximumSizeValue; v75[mm - 1] = v2->workingArea.value[mm - 1] )
              {
                if ( mm >= v74 )
                  break;
                ++mm;
              }
              operator delete(v2->workingArea.value);
              v2->workingArea.value = v75;
              v2->workingArea.maximumSizeValue = v74;
            }
          }
          TacticalAIGroup::addUnit(bestGroupa, v2->workingArea.value[bestDistancea], v2->md);
        }
        else
        {
          v77 = v2->groups.next;
          bestGroupb = 0;
          for ( bestGroupDifferenceb = 0; v77 != (TacticalAIGroup *)v68; v77 = v77->next )
          {
            if ( !v77 )
              break;
            if ( (TacticalAIGroup::type(v77) == 103
               || TacticalAIGroup::type(v77) == 104
               || TacticalAIGroup::type(v77) == 105
               || TacticalAIGroup::type(v77) == 106
               || TacticalAIGroup::type(v77) == 107
               || TacticalAIGroup::type(v77) == 108)
              && (TacticalAIGroup::action(v77) == 1 || !TacticalAIGroup::action(v77))
              && (TacticalAIGroup::type(v77) != 103 || TacticalAIGroup::numberUnits(v77) < v2->sn[60])
              && (TacticalAIGroup::type(v77) != 104 || TacticalAIGroup::numberUnits(v77) < v2->sn[69])
              && (TacticalAIGroup::type(v77) != 105 || TacticalAIGroup::numberUnits(v77) < v2->sn[63]) )
            {
              v78 = TacticalAIGroup::numberUnits(v77);
              v79 = v78 - TacticalAIGroup::desiredNumberUnits(v77);
              if ( !bestGroupb || v79 < bestGroupDifferenceb )
              {
                bestGroupb = v77;
                bestGroupDifferenceb = v79;
              }
            }
          }
          if ( !bestGroupb )
            return;
          if ( bestDistancea > v2->workingArea.maximumSizeValue - 1 )
          {
            v80 = bestDistancea + 1;
            v81 = (int *)operator new(4 * bestDistancea + 4);
            if ( v81 )
            {
              for ( nn = 0; nn < v2->workingArea.maximumSizeValue; v81[nn - 1] = v2->workingArea.value[nn - 1] )
              {
                if ( nn >= v80 )
                  break;
                ++nn;
              }
              operator delete(v2->workingArea.value);
              v2->workingArea.value = v81;
              v2->workingArea.maximumSizeValue = v80;
            }
          }
          TacticalAIGroup::addUnit(bestGroupb, v2->workingArea.value[bestDistancea], v2->md);
          v73 = bestDistancea;
        }
        bestDistancea = v73 + 1;
      }
      while ( v73 + 1 < v2->workingArea.numberValue );
    }
  }
}

//----- (004FF4E0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUngroupedWarBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  int v6; // edi@8
  int v7; // ebx@10
  int *v8; // edi@10
  int k; // eax@11
  int v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ebx@21
  int *v14; // edi@21
  int l; // eax@22
  int rNum; // [sp+8h] [bp-Ch]@1
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  rNum = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->boats.numberValue; i = v2 )
  {
    if ( v2 > v1->boats.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->boats.maximumSizeValue; v4[j - 1] = v1->boats.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->boats.value);
        v1->boats.value = v4;
        v1->boats.maximumSizeValue = v3;
      }
    }
    v6 = v2;
    if ( !TribeTacticalAIModule::groupUnitIsIn(v1, v1->boats.value[v2]) )
    {
      if ( v2 > v1->boats.maximumSizeValue - 1 )
      {
        v7 = v2 + 1;
        v8 = (int *)operator new(v6 * 4 + 4);
        if ( v8 )
        {
          for ( k = 0; k < v1->boats.maximumSizeValue; v8[k - 1] = v1->boats.value[k - 1] )
          {
            if ( k >= v7 )
              break;
            ++k;
          }
          operator delete(v1->boats.value);
          v1->boats.value = v8;
          v1->boats.maximumSizeValue = v7;
        }
        v6 = v2;
      }
      v10 = 0;
      v11 = v1->boats.value[v6];
      v12 = v1->workingArea.numberValue;
      if ( v12 > 0 )
      {
        do
        {
          if ( v10 >= v1->workingArea.maximumSizeValue )
            break;
          if ( v1->workingArea.value[v10] == v11 )
            goto LABEL_27;
          ++v10;
        }
        while ( v10 < v12 );
      }
      if ( v12 > v1->workingArea.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * (v12 + 1));
        if ( v14 )
        {
          for ( l = 0; l < v1->workingArea.maximumSizeValue; v14[l - 1] = v1->workingArea.value[l - 1] )
          {
            if ( l >= v13 )
              break;
            ++l;
          }
          operator delete(v1->workingArea.value);
          v1->workingArea.value = v14;
          v1->workingArea.maximumSizeValue = v13;
        }
      }
      v1->workingArea.value[v1->workingArea.numberValue++] = v11;
LABEL_27:
      v2 = i;
      ++rNum;
    }
    ++v2;
  }
  return rNum;
}

//----- (004FF6E0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberExtraGroupedWarBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  TacticalAIGroup *v2; // ebx@1
  int v3; // edi@11
  int v4; // edi@12
  int v5; // ebp@14
  int v6; // eax@15
  int v7; // ecx@15
  int v8; // edx@15
  int v9; // eax@15
  int v10; // ebp@20
  int *v11; // edi@20
  int k; // eax@21
  int j; // [sp+10h] [bp-10h]@12
  int tempCount; // [sp+14h] [bp-Ch]@12
  int rNum; // [sp+18h] [bp-8h]@1
  int i; // [sp+1Ch] [bp-4h]@15

  v1 = this;
  rNum = 0;
  this->workingArea.numberValue = 0;
  v2 = this->groups.next;
  if ( v2 != &this->groups )
  {
    do
    {
      if ( !v2 )
        break;
      if ( (TacticalAIGroup::type(v2) == 103
         || TacticalAIGroup::type(v2) == 104
         || TacticalAIGroup::type(v2) == 105
         || TacticalAIGroup::type(v2) == 106
         || TacticalAIGroup::type(v2) == 107
         || TacticalAIGroup::type(v2) == 108)
        && (TacticalAIGroup::action(v2) == 1 || !TacticalAIGroup::action(v2)) )
      {
        v3 = TacticalAIGroup::numberUnits(v2);
        if ( v3 > TacticalAIGroup::desiredNumberUnits(v2) )
        {
          v4 = 0;
          tempCount = TacticalAIGroup::numberUnits(v2);
          for ( j = 0; tempCount > TacticalAIGroup::desiredNumberUnits(v2); j = ++v4 )
          {
            if ( v4 >= TacticalAIGroup::numberUnits(v2) )
              break;
            v5 = TacticalAIGroup::unit(v2, v4);
            if ( v5 != TacticalAIGroup::commander(v2) )
            {
              --tempCount;
              v6 = TacticalAIGroup::unit(v2, v4);
              v7 = v1->workingArea.numberValue;
              v8 = v6;
              v9 = 0;
              for ( i = v8; v9 < v7; ++v9 )
              {
                if ( v9 >= v1->workingArea.maximumSizeValue )
                  break;
                if ( v1->workingArea.value[v9] == v8 )
                  goto LABEL_27;
              }
              if ( v7 > v1->workingArea.maximumSizeValue - 1 )
              {
                v10 = v7 + 1;
                v11 = (int *)operator new(4 * (v7 + 1));
                if ( v11 )
                {
                  for ( k = 0; k < v1->workingArea.maximumSizeValue; v11[k - 1] = v1->workingArea.value[k - 1] )
                  {
                    if ( k >= v10 )
                      break;
                    ++k;
                  }
                  operator delete(v1->workingArea.value);
                  v1->workingArea.value = v11;
                  v1->workingArea.maximumSizeValue = v10;
                }
                v8 = i;
                v4 = j;
              }
              v1->workingArea.value[v1->workingArea.numberValue++] = v8;
LABEL_27:
              ++rNum;
            }
          }
        }
      }
      v2 = v2->next;
    }
    while ( v2 != &v1->groups );
  }
  return rNum;
}

//----- (004FF8E0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUngroupedFishingBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  int v6; // edi@8
  int v7; // ebx@10
  int *v8; // edi@10
  int k; // eax@11
  int v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ebx@21
  int *v14; // edi@21
  int l; // eax@22
  int rNum; // [sp+8h] [bp-Ch]@1
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  rNum = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->fishingBoats.numberValue; i = v2 )
  {
    if ( v2 > v1->fishingBoats.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->fishingBoats.maximumSizeValue; v4[j - 1] = v1->fishingBoats.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->fishingBoats.value);
        v1->fishingBoats.value = v4;
        v1->fishingBoats.maximumSizeValue = v3;
      }
    }
    v6 = v2;
    if ( !TribeTacticalAIModule::groupUnitIsIn(v1, v1->fishingBoats.value[v2]) )
    {
      if ( v2 > v1->fishingBoats.maximumSizeValue - 1 )
      {
        v7 = v2 + 1;
        v8 = (int *)operator new(v6 * 4 + 4);
        if ( v8 )
        {
          for ( k = 0; k < v1->fishingBoats.maximumSizeValue; v8[k - 1] = v1->fishingBoats.value[k - 1] )
          {
            if ( k >= v7 )
              break;
            ++k;
          }
          operator delete(v1->fishingBoats.value);
          v1->fishingBoats.value = v8;
          v1->fishingBoats.maximumSizeValue = v7;
        }
        v6 = v2;
      }
      v10 = 0;
      v11 = v1->fishingBoats.value[v6];
      v12 = v1->workingArea.numberValue;
      if ( v12 > 0 )
      {
        do
        {
          if ( v10 >= v1->workingArea.maximumSizeValue )
            break;
          if ( v1->workingArea.value[v10] == v11 )
            goto LABEL_27;
          ++v10;
        }
        while ( v10 < v12 );
      }
      if ( v12 > v1->workingArea.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * (v12 + 1));
        if ( v14 )
        {
          for ( l = 0; l < v1->workingArea.maximumSizeValue; v14[l - 1] = v1->workingArea.value[l - 1] )
          {
            if ( l >= v13 )
              break;
            ++l;
          }
          operator delete(v1->workingArea.value);
          v1->workingArea.value = v14;
          v1->workingArea.maximumSizeValue = v13;
        }
      }
      v1->workingArea.value[v1->workingArea.numberValue++] = v11;
LABEL_27:
      v2 = i;
      ++rNum;
    }
    ++v2;
  }
  return rNum;
}

//----- (004FFAE0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUngroupedTradeBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  int v6; // edi@8
  int v7; // ebx@10
  int *v8; // edi@10
  int k; // eax@11
  int v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ebx@21
  int *v14; // edi@21
  int l; // eax@22
  int rNum; // [sp+8h] [bp-Ch]@1
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  rNum = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->tradeBoats.numberValue; i = v2 )
  {
    if ( v2 > v1->tradeBoats.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->tradeBoats.maximumSizeValue; v4[j - 1] = v1->tradeBoats.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->tradeBoats.value);
        v1->tradeBoats.value = v4;
        v1->tradeBoats.maximumSizeValue = v3;
      }
    }
    v6 = v2;
    if ( !TribeTacticalAIModule::groupUnitIsIn(v1, v1->tradeBoats.value[v2]) )
    {
      if ( v2 > v1->tradeBoats.maximumSizeValue - 1 )
      {
        v7 = v2 + 1;
        v8 = (int *)operator new(v6 * 4 + 4);
        if ( v8 )
        {
          for ( k = 0; k < v1->tradeBoats.maximumSizeValue; v8[k - 1] = v1->tradeBoats.value[k - 1] )
          {
            if ( k >= v7 )
              break;
            ++k;
          }
          operator delete(v1->tradeBoats.value);
          v1->tradeBoats.value = v8;
          v1->tradeBoats.maximumSizeValue = v7;
        }
        v6 = v2;
      }
      v10 = 0;
      v11 = v1->tradeBoats.value[v6];
      v12 = v1->workingArea.numberValue;
      if ( v12 > 0 )
      {
        do
        {
          if ( v10 >= v1->workingArea.maximumSizeValue )
            break;
          if ( v1->workingArea.value[v10] == v11 )
            goto LABEL_27;
          ++v10;
        }
        while ( v10 < v12 );
      }
      if ( v12 > v1->workingArea.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * (v12 + 1));
        if ( v14 )
        {
          for ( l = 0; l < v1->workingArea.maximumSizeValue; v14[l - 1] = v1->workingArea.value[l - 1] )
          {
            if ( l >= v13 )
              break;
            ++l;
          }
          operator delete(v1->workingArea.value);
          v1->workingArea.value = v14;
          v1->workingArea.maximumSizeValue = v13;
        }
      }
      v1->workingArea.value[v1->workingArea.numberValue++] = v11;
LABEL_27:
      v2 = i;
      ++rNum;
    }
    ++v2;
  }
  return rNum;
}

//----- (004FFCE0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUngroupedTransportBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  int v6; // edi@8
  int v7; // ebx@10
  int *v8; // edi@10
  int k; // eax@11
  int v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ebx@21
  int *v14; // edi@21
  int l; // eax@22
  int rNum; // [sp+8h] [bp-Ch]@1
  int i; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  rNum = 0;
  i = 0;
  for ( this->workingArea.numberValue = 0; v2 < v1->transportBoats.numberValue; i = v2 )
  {
    if ( v2 > v1->transportBoats.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->transportBoats.maximumSizeValue; v4[j - 1] = v1->transportBoats.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->transportBoats.value);
        v1->transportBoats.value = v4;
        v1->transportBoats.maximumSizeValue = v3;
      }
    }
    v6 = v2;
    if ( !TribeTacticalAIModule::groupUnitIsIn(v1, v1->transportBoats.value[v2]) )
    {
      if ( v2 > v1->transportBoats.maximumSizeValue - 1 )
      {
        v7 = v2 + 1;
        v8 = (int *)operator new(v6 * 4 + 4);
        if ( v8 )
        {
          for ( k = 0; k < v1->transportBoats.maximumSizeValue; v8[k - 1] = v1->transportBoats.value[k - 1] )
          {
            if ( k >= v7 )
              break;
            ++k;
          }
          operator delete(v1->transportBoats.value);
          v1->transportBoats.value = v8;
          v1->transportBoats.maximumSizeValue = v7;
        }
        v6 = v2;
      }
      v10 = 0;
      v11 = v1->transportBoats.value[v6];
      v12 = v1->workingArea.numberValue;
      if ( v12 > 0 )
      {
        do
        {
          if ( v10 >= v1->workingArea.maximumSizeValue )
            break;
          if ( v1->workingArea.value[v10] == v11 )
            goto LABEL_27;
          ++v10;
        }
        while ( v10 < v12 );
      }
      if ( v12 > v1->workingArea.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * (v12 + 1));
        if ( v14 )
        {
          for ( l = 0; l < v1->workingArea.maximumSizeValue; v14[l - 1] = v1->workingArea.value[l - 1] )
          {
            if ( l >= v13 )
              break;
            ++l;
          }
          operator delete(v1->workingArea.value);
          v1->workingArea.value = v14;
          v1->workingArea.maximumSizeValue = v13;
        }
      }
      v1->workingArea.value[v1->workingArea.numberValue++] = v11;
LABEL_27:
      v2 = i;
      ++rNum;
    }
    ++v2;
  }
  return rNum;
}

//----- (004FFEE0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::displayBoatGroups(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // edi@1
  TacticalAIGroup *i; // esi@1
  int v3; // ST2C_4@10
  int v4; // ST28_4@10
  int v5; // ST2C_4@12
  int v6; // ST28_4@12
  int v7; // ST2C_4@14
  int v8; // ST28_4@14
  int v9; // ST2C_4@16
  int v10; // ST28_4@16
  int v11; // ST2C_4@18
  int v12; // ST28_4@18
  int v13; // ST2C_4@20
  int v14; // ST28_4@20
  int v15; // ST2C_4@21
  int v16; // ST28_4@21
  int v17; // ST24_4@21
  int v18; // ST20_4@21
  int v19; // eax@21
  int v20; // ST2C_4@21
  int v21; // ST28_4@21
  int v22; // ST24_4@21
  int v23; // ST20_4@21
  int v24; // eax@21
  double v25; // ST28_8@21
  Waypoint *v26; // eax@21
  double v27; // ST28_8@21
  Waypoint *v28; // eax@21
  double v29; // ST28_8@21
  Waypoint *v30; // eax@21
  double v31; // ST28_8@21
  double v32; // st7@21
  int j; // ebp@21
  int v34; // eax@22
  int v35; // eax@22
  RGE_Static_Object *v36; // eax@22
  RGE_Static_Object *v37; // ebx@22
  double v38; // ST28_8@26
  double v39; // ST20_8@26
  UnitAIModule *v40; // eax@26
  int v41; // ST1C_4@26
  UnitAIModule *v42; // eax@26
  int v43; // ST18_4@26
  UnitAIModule *v44; // eax@26
  int v45; // ST14_4@26
  UnitAIModule *v46; // eax@26
  int v47; // ST10_4@26
  int v48; // ST0C_4@26
  int v49; // eax@26

  v1 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aBoatGroups);
  for ( i = v1->groups.next; i != &v1->groups; i = i->next )
  {
    if ( !i )
      break;
    if ( TacticalAIGroup::type(i) == 103
      || TacticalAIGroup::type(i) == 104
      || TacticalAIGroup::type(i) == 105
      || TacticalAIGroup::type(i) == 107
      || TacticalAIGroup::type(i) == 108
      || TacticalAIGroup::type(i) == 106 )
    {
      if ( TacticalAIGroup::type(i) == 103 )
      {
        v3 = TacticalAIGroup::type(i);
        v4 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDAttack, v4, v3);
      }
      else if ( TacticalAIGroup::type(i) == 104 )
      {
        v5 = TacticalAIGroup::type(i);
        v6 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDDefend, v6, v5);
      }
      else if ( TacticalAIGroup::type(i) == 105 )
      {
        v7 = TacticalAIGroup::type(i);
        v8 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDExplor, v8, v7);
      }
      else if ( TacticalAIGroup::type(i) == 107 )
      {
        v9 = TacticalAIGroup::type(i);
        v10 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDFishin, v10, v9);
      }
      else if ( TacticalAIGroup::type(i) == 108 )
      {
        v11 = TacticalAIGroup::type(i);
        v12 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDTradeG, v12, v11);
      }
      else if ( TacticalAIGroup::type(i) == 106 )
      {
        v13 = TacticalAIGroup::type(i);
        v14 = TacticalAIGroup::id(i);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGroupIdDTransp, v14, v13);
      }
      v15 = TacticalAIGroup::inUse(i);
      v16 = TacticalAIGroup::action(i);
      v17 = TacticalAIGroup::originalUnitNumber(i);
      v18 = TacticalAIGroup::desiredNumberUnits(i);
      v19 = TacticalAIGroup::numberUnits(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aNumunitsDDesnu, v19, v18, v17, v16, v15);
      v20 = TacticalAIGroup::assistGroupID(i);
      v21 = TacticalAIGroup::originalHitPoints(i);
      v22 = TacticalAIGroup::currentHitPoints(i, v1->md);
      v23 = TacticalAIGroup::commander(i);
      v24 = TacticalAIGroup::target(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aTargetDComma_1, v24, v23, v22, v21, v20);
      v25 = TacticalAIGroup::location(i)->y;
      v26 = TacticalAIGroup::location(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aLocationFF_, v26->x, v25);
      v27 = TacticalAIGroup::gatherLocation(i)->y;
      v28 = TacticalAIGroup::gatherLocation(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aGatherLocation, v28->x, v27);
      v29 = TacticalAIGroup::retreatLocation(i)->y;
      v30 = TacticalAIGroup::retreatLocation(i);
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aRetreatLocatio, v30->x, v29);
      v31 = TacticalAIGroup::targetLocation(i)->y;
      v32 = TacticalAIGroup::targetLocation(i)->x;
      AIModule::logCommonHistory((AIModule *)&v1->vfptr, aTargetLocation, v32, v31);
      for ( j = 0; j < TacticalAIGroup::numberUnits(i); ++j )
      {
        v34 = TacticalAIGroup::unit(i, j);
        AIModule::logCommonHistory((AIModule *)&v1->vfptr, aUnitD_, v34);
        v35 = TacticalAIGroup::unit(i, j);
        v36 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v35);
        v37 = v36;
        if ( v36 )
        {
          if ( RGE_Static_Object::unitAI(v36) )
          {
            v38 = v37->world_y;
            v39 = v37->world_x;
            v40 = RGE_Static_Object::unitAI(v37);
            v41 = UnitAIModule::currentOrderPriority(v40);
            v42 = RGE_Static_Object::unitAI(v37);
            v43 = UnitAIModule::currentOrder(v42);
            v44 = RGE_Static_Object::unitAI(v37);
            v45 = UnitAIModule::currentTarget(v44);
            v46 = RGE_Static_Object::unitAI(v37);
            v47 = UnitAIModule::currentAction(v46);
            v48 = v37->object_state;
            v49 = TacticalAIGroup::unit(i, j);
            AIModule::logCommonHistory((AIModule *)&v1->vfptr, aUnitDStateDAct, v49, v48, v47, v45, v43, v41, v39, v38);
          }
          else
          {
            AIModule::logCommonHistory((AIModule *)&v1->vfptr, aUnitDHasInvali);
          }
        }
        else
        {
          AIModule::logCommonHistory((AIModule *)&v1->vfptr, aUnitDIsInvalid);
        }
      }
    }
  }
}

//----- (00500260) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::createGroup(TribeTacticalAIModule *this, int initID)
{
  TribeTacticalAIModule *v2; // edi@1
  TacticalAIGroup *v3; // eax@1
  TacticalAIGroup *v4; // eax@2
  TacticalAIGroup *v5; // esi@2
  TacticalAIGroup *result; // eax@5
  TacticalAIGroup *v7; // eax@6
  int v8; // ST00_4@7

  v2 = this;
  v3 = (TacticalAIGroup *)operator new(0x330u);
  if ( v3 )
  {
    TacticalAIGroup::TacticalAIGroup(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( v5 )
  {
    v5->next = &v2->groups;
    v7 = v2->groups.prev;
    v5->prev = v7;
    v7->next = v5;
    v2->groups.prev = v5;
    if ( initID == 1 )
    {
      v8 = v2->groupIDValue;
      v2->groupIDValue = v8 + 1;
      TacticalAIGroup::setID(v5, v8);
      ++v2->numberGroupsValue;
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00500320) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::removeGroup(TribeTacticalAIModule *this, int gID)
{
  TribeTacticalAIModule *v2; // ebp@1
  TacticalAIGroup *v3; // esi@1
  char *v4; // edi@1

  v2 = this;
  v3 = this->groups.next;
  v4 = (char *)&this->groups;
  if ( v3 != &this->groups )
  {
    while ( v3 )
    {
      if ( TacticalAIGroup::id(v3) == gID )
      {
        v3->prev->next = v3->next;
        v3->next->prev = v3->prev;
        if ( v3 )
          v3->vfptr->__vecDelDtor(v3, 1u);
        --v2->numberGroupsValue;
        return 1;
      }
      v3 = v3->next;
      if ( (char *)v3 == v4 )
        return 0;
    }
  }
  return 0;
}

//----- (005003A0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::removeAllGroups(TribeTacticalAIModule *this, int tID)
{
  TribeTacticalAIModule *v2; // ebx@1
  TacticalAIGroup *v3; // esi@1
  TacticalAIGroup *v4; // edi@5

  v2 = this;
  v3 = this->groups.next;
  if ( v3 != &this->groups )
  {
    do
    {
      if ( !v3 )
        break;
      if ( TacticalAIGroup::type(v3) == tID || tID == -1 )
      {
        v3->prev->next = v3->next;
        v3->next->prev = v3->prev;
        v4 = v3->prev;
        v3->vfptr->__vecDelDtor(v3, 1u);
        v3 = v4;
        --v2->numberGroupsValue;
      }
      v3 = v3->next;
    }
    while ( v3 != &v2->groups );
  }
  return 1;
}

//----- (00500420) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::group(TribeTacticalAIModule *this, int gID, int type, int action, int targetID)
{
  TacticalAIGroup *v5; // esi@1
  char *v7; // [sp+10h] [bp-4h]@1

  v5 = this->groups.next;
  v7 = (char *)&this->groups;
  if ( v5 != &this->groups )
  {
    while ( v5 )
    {
      if ( (gID == -1 || TacticalAIGroup::id(v5) == gID)
        && (type == -1 || TacticalAIGroup::type(v5) == type)
        && (action == -1 || TacticalAIGroup::action(v5) == action)
        && (targetID == -1 || TacticalAIGroup::target(v5) == targetID) )
      {
        return v5;
      }
      v5 = v5->next;
      if ( (char *)v5 == v7 )
        return 0;
    }
  }
  return 0;
}

//----- (005004C0) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::bestGroup(TribeTacticalAIModule *this, int type, int action, int distance, XYPoint *point, int zone)
{
  TacticalAIGroup *v6; // edi@1
  XYPoint *v7; // ebp@2
  signed int v8; // ebx@9
  TacticalAIGroup *v9; // esi@9
  int v10; // ebp@12
  int v11; // eax@17
  RGE_Static_Object *v12; // eax@17
  int v13; // esi@19
  int v14; // esi@19
  int v15; // ebx@19
  signed __int64 v16; // rax@19
  TribeTacticalAIModule *v18; // [sp+10h] [bp-14h]@1
  int bGValue; // [sp+14h] [bp-10h]@1
  char *v20; // [sp+18h] [bp-Ch]@1
  TacticalAIGroup *bG; // [sp+1Ch] [bp-8h]@1

  v6 = this->groups.next;
  v18 = this;
  bG = 0;
  bGValue = -1;
  v20 = (char *)&this->groups;
  if ( v6 != &this->groups )
  {
    v7 = point;
    do
    {
      if ( !v6 )
        break;
      if ( (type == -1 || TacticalAIGroup::type(v6) == type) && (action == -1 || TacticalAIGroup::action(v6) == action) )
      {
        if ( type != 106 )
          goto LABEL_28;
        v8 = 1;
        v9 = v18->groups.next;
        if ( (char *)v9 != v20 )
        {
          do
          {
            if ( !v9 )
              break;
            if ( !v8 )
              goto LABEL_24;
            v10 = TacticalAIGroup::id(v6);
            if ( TacticalAIGroup::assistGroupID(v9) == v10 )
              v8 = 0;
            v9 = v9->next;
            v7 = point;
            v20 = (char *)&v18->groups;
          }
          while ( v9 != &v18->groups );
        }
        if ( v8 )
        {
LABEL_28:
          if ( zone == -1
            || (v11 = TacticalAIGroup::commander(v6),
                (v12 = MainDecisionAIModule::object((MainDecisionAIModule *)&v18->md->vfptr, v11)) != 0)
            && (unsigned __int8)RGE_Static_Object::currentZone(v12) == zone )
          {
            if ( (v13 = v7->y - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v6)->y,
                  v14 = (v7->y - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v6)->y) * v13,
                  v15 = v7->x - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v6)->x,
                  v16 = (signed __int64)sqrt((double)(signed int)((v7->x
                                                                 - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v6)->x)
                                                                * v15
                                                                + v14)),
                  (signed int)v16 < distance)
              && bGValue == -1
              || distance == -1
              || (signed int)v16 < bGValue )
            {
              bG = v6;
              bGValue = v16;
            }
          }
        }
      }
LABEL_24:
      v6 = v6->next;
    }
    while ( (char *)v6 != v20 );
  }
  return bG;
}

//----- (00500670) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::readyAndIdleGroup(TribeTacticalAIModule *this, int type, int distance, XYPoint *point)
{
  TribeTacticalAIModule *v4; // ebx@1
  TacticalAIGroup *v5; // esi@1
  int v6; // ebp@5
  int v7; // ebx@8
  int v8; // ebx@8
  int v9; // ebp@8
  signed __int64 v10; // rax@8
  int bGValue; // [sp+10h] [bp-Ch]@1
  TribeTacticalAIModule *v13; // [sp+14h] [bp-8h]@1
  TacticalAIGroup *bG; // [sp+18h] [bp-4h]@1

  v4 = this;
  v5 = this->groups.next;
  v13 = this;
  bG = 0;
  bGValue = -1;
  if ( v5 != &this->groups )
  {
    do
    {
      if ( !v5 )
        break;
      if ( type == -1 || TacticalAIGroup::type(v5) == type )
      {
        v6 = TacticalAIGroup::desiredNumberUnits(v5);
        if ( v6 <= TacticalAIGroup::numberUnits(v5)
          && TacticalAIGroup::isGathered(v5, v4, v4->md)
          && TacticalAIGroup::allUnitsIdle(v5, v4->md, 1) )
        {
          v7 = point->y - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v5)->y;
          v8 = (point->y - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v5)->y) * v7;
          v9 = point->x - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v5)->x;
          v10 = (signed __int64)sqrt((double)(signed int)((point->x
                                                         - (unsigned __int64)(signed __int64)TacticalAIGroup::gatherLocation(v5)->x)
                                                        * v9
                                                        + v8));
          if ( (signed int)v10 < distance && bGValue == -1 || (signed int)v10 < bGValue )
          {
            bG = v5;
            bGValue = v10;
          }
          v4 = v13;
        }
      }
      v5 = v5->next;
    }
    while ( v5 != &v4->groups );
  }
  return bG;
}

//----- (005007B0) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::addToGroup(TribeTacticalAIModule *this, int uID, int gID)
{
  TribeTacticalAIModule *v3; // esi@1
  TacticalAIGroup *result; // eax@1

  v3 = this;
  result = TribeTacticalAIModule::group(this, gID, -1, -1, -1);
  if ( result )
    result = (TacticalAIGroup *)TacticalAIGroup::addUnit(result, uID, v3->md);
  return result;
}

//----- (005007F0) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::removeFromGroup(TribeTacticalAIModule *this, int uID, int gID)
{
  TribeTacticalAIModule *v3; // edi@1
  TacticalAIGroup *result; // eax@1
  TacticalAIGroup *v5; // esi@1
  TacticalAIGroup *v6; // ebp@2

  v3 = this;
  result = TribeTacticalAIModule::group(this, gID, -1, -1, -1);
  v5 = result;
  if ( result )
  {
    v6 = (TacticalAIGroup *)TacticalAIGroup::removeUnit(result, uID, v3->md);
    if ( !TacticalAIGroup::numberUnits(v5) )
      TribeTacticalAIModule::removeGroup(v3, gID);
    result = v6;
  }
  return result;
}

//----- (00500850) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::removeFromGroup(TribeTacticalAIModule *this, int uID)
{
  TribeTacticalAIModule *v2; // edi@1
  TacticalAIGroup *result; // eax@1
  TacticalAIGroup *v4; // esi@1
  TacticalAIGroup *v5; // ebx@2
  int v6; // eax@3

  v2 = this;
  result = TribeTacticalAIModule::groupUnitIsIn(this, uID);
  v4 = result;
  if ( result )
  {
    v5 = (TacticalAIGroup *)TacticalAIGroup::removeUnit(result, uID, v2->md);
    if ( !TacticalAIGroup::numberUnits(v4) )
    {
      v6 = TacticalAIGroup::id(v4);
      TribeTacticalAIModule::removeGroup(v2, v6);
    }
    result = v5;
  }
  return result;
}

//----- (005008A0) --------------------------------------------------------
TacticalAIGroup *__thiscall TribeTacticalAIModule::groupUnitIsIn(TribeTacticalAIModule *this, int uID)
{
  TacticalAIGroup *v2; // esi@1
  char *v3; // ebx@1

  v2 = this->groups.next;
  v3 = (char *)&this->groups;
  if ( v2 != &this->groups )
  {
    while ( v2 )
    {
      if ( TacticalAIGroup::containsUnit(v2, uID) == 1 )
        return v2;
      v2 = v2->next;
      if ( (char *)v2 == v3 )
        return 0;
    }
  }
  return 0;
}

//----- (005008F0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberGroups(TribeTacticalAIModule *this, int type, int action)
{
  TacticalAIGroup *v3; // esi@1
  char *v4; // ebp@1
  int rVal; // [sp+10h] [bp-4h]@1

  v3 = this->groups.next;
  v4 = (char *)&this->groups;
  rVal = 0;
  if ( v3 != &this->groups )
  {
    do
    {
      if ( !v3 )
        break;
      if ( (type == -1 || TacticalAIGroup::type(v3) == type) && (action == -1 || TacticalAIGroup::action(v3) == action) )
        ++rVal;
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
  }
  return rVal;
}

//----- (00500950) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberUnitsInGroups(TribeTacticalAIModule *this, int type)
{
  TacticalAIGroup *v2; // esi@1
  char *v3; // ebx@1
  int v4; // ebp@1

  v2 = this->groups.next;
  v3 = (char *)&this->groups;
  v4 = 0;
  if ( v2 != &this->groups )
  {
    do
    {
      if ( !v2 )
        break;
      if ( type == -1 || TacticalAIGroup::type(v2) == type )
        v4 += TacticalAIGroup::numberUnits(v2);
      v2 = v2->next;
    }
    while ( (char *)v2 != v3 );
  }
  return v4;
}

//----- (005009A0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberItemsToAttack(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int *v2; // edi@2
  signed int i; // eax@3

  v1 = this;
  if ( this->playersToAttack.maximumSizeValue - 1 < 0 )
  {
    v2 = (int *)operator new(4u);
    if ( v2 )
    {
      for ( i = 0; i < v1->playersToAttack.maximumSizeValue; v2[i - 1] = v1->playersToAttack.value[i - 1] )
      {
        if ( i >= 1 )
          break;
        ++i;
      }
      operator delete(v1->playersToAttack.value);
      v1->playersToAttack.value = v2;
      v1->playersToAttack.maximumSizeValue = 1;
    }
  }
  return TribeInformationAIModule::numberGameIDsOwnedBy(&v1->md->informationAI, -1, *v1->playersToAttack.value);
}

//----- (00500A30) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::itemToCapture(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // edi@2
  int result; // eax@3

  v1 = this;
  if ( TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI)
    || (v2 = TribeStrategyAIModule::targetID(&v1->md->strategyAI), TribeTacticalAIModule::group(v1, -1, -1, -1, v2)) )
  {
    result = -1;
  }
  else
  {
    result = v2;
  }
  return result;
}

//----- (00500A80) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::itemToBringToArea(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // edi@2
  int result; // eax@3

  v1 = this;
  if ( TribeStrategyAIModule::currentVictoryCondition(&this->md->strategyAI) != 4
    || (v2 = TribeStrategyAIModule::secondTargetID(&v1->md->strategyAI), TribeTacticalAIModule::group(
                                                                           v1,
                                                                           -1,
                                                                           -1,
                                                                           -1,
                                                                           v2)) )
  {
    result = -1;
  }
  else
  {
    result = v2;
  }
  return result;
}

//----- (00500AD0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberItemsToDefend(TribeTacticalAIModule *this)
{
  return TribeInformationAIModule::numberItemsToDefend(&this->md->informationAI);
}

//----- (00500AF0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::attackLimiterTime(TribeTacticalAIModule *this, int snType)
{
  int result; // eax@2
  signed int v3; // ecx@2

  if ( this->sn[71] == 1 )
  {
    result = this->randomizedAttackSeparationTime;
    v3 = this->sn[48];
    if ( result >= v3 )
      result = v3;
  }
  else if ( snType == 46 )
  {
    result = this->randomizedAttackSeparationTime;
  }
  else
  {
    result = this->sn[48];
  }
  return result;
}

//----- (00500B30) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::resetAttackSeparationTime(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  signed int v2; // eax@1

  v1 = this;
  v2 = this->sn[102];
  if ( v2 <= 0 )
    this->randomizedAttackSeparationTime = this->sn[46];
  else
    this->randomizedAttackSeparationTime = this->sn[46] - v2 / 2 + debug_rand(aCMsdevWorkA_61, 11573) % v2;
  if ( v1->randomizedAttackSeparationTime < 0 )
    v1->randomizedAttackSeparationTime = 0;
}

//----- (00500BA0) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::setGatherLocation(TribeTacticalAIModule *this, TacticalAIGroup *g)
{
  TacticalAIGroup *v2; // ebp@1
  TribeTacticalAIModule *v3; // esi@1
  int v4; // eax@1
  RGE_Static_Object *result; // eax@1
  RGE_Static_Object *v6; // ebx@1
  int v7; // ecx@7
  int v8; // edx@7
  int v9; // ST1C_4@7
  int v10; // ST18_4@7
  int v11; // eax@7
  float v12; // ST20_4@8
  float v13; // ST1C_4@8
  XYPoint centerPoint; // [sp+1Ch] [bp-10h]@7
  XYPoint gatherPoint; // [sp+24h] [bp-8h]@7
  TacticalAIGroup *ga; // [sp+30h] [bp+4h]@4

  v2 = g;
  v3 = this;
  v4 = TacticalAIGroup::commander(g);
  result = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v4);
  v6 = result;
  if ( result )
  {
    if ( TacticalAIGroup::type(g) == 100
      || TacticalAIGroup::type(g) == 101
      || (ga = 0, TacticalAIGroup::type(v2) == 102) )
    {
      ga = (TacticalAIGroup *)1;
    }
    result = MainDecisionAIModule::object(
               (MainDecisionAIModule *)&v3->md->vfptr,
               -1,
               109,
               -1,
               -1,
               -1,
               -1,
               -1,
               -1,
               -1,
               -1);
    if ( result )
    {
      centerPoint.x = (signed __int64)result->world_x;
      v7 = v3->sn[72];
      v8 = v3->sn[22];
      centerPoint.y = (signed __int64)result->world_y;
      v9 = v7;
      v10 = v8;
      v11 = TacticalAIGroup::desiredNumberUnits(v2);
      if ( TribeInformationAIModule::findGatherPosition(
             &v3->md->informationAI,
             &centerPoint,
             v11,
             (int)ga,
             v10,
             v9,
             v6,
             &gatherPoint) == 1 )
      {
        v12 = (double)gatherPoint.y;
        v13 = (double)gatherPoint.x;
        TacticalAIGroup::setGatherLocation(v2, v13, v12, v6->world_z);
      }
      else
      {
        TacticalAIGroup::setGatherLocation(v2, v6->world_x, v6->world_y, v6->world_z);
      }
      result = (RGE_Static_Object *)1;
    }
  }
  return result;
}

//----- (00500CC0) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::setAllGroupLocations(TribeTacticalAIModule *this, TacticalAIGroup *g)
{
  TacticalAIGroup *v2; // ebp@1
  TribeTacticalAIModule *v3; // esi@1
  int v4; // eax@1
  RGE_Static_Object *result; // eax@1
  RGE_Static_Object *v6; // ebx@1
  RGE_Static_Object *v7; // eax@6
  double v8; // st7@7
  int v9; // ecx@7
  int v10; // edx@7
  int v11; // ST1C_4@7
  int v12; // ST18_4@7
  int v13; // eax@7
  float v14; // ST20_4@8
  float v15; // ST1C_4@8
  XYPoint centerPoint; // [sp+1Ch] [bp-10h]@7
  XYPoint gatherPoint; // [sp+24h] [bp-8h]@7
  TacticalAIGroup *ga; // [sp+30h] [bp+4h]@4

  v2 = g;
  v3 = this;
  v4 = TacticalAIGroup::commander(g);
  result = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v4);
  v6 = result;
  if ( result )
  {
    if ( TacticalAIGroup::type(g) == 100
      || TacticalAIGroup::type(g) == 101
      || (ga = 0, TacticalAIGroup::type(v2) == 102) )
    {
      ga = (TacticalAIGroup *)1;
    }
    v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    if ( v7
      && (v8 = v7->world_y,
          centerPoint.x = (signed __int64)v7->world_x,
          v9 = v3->sn[72],
          v10 = v3->sn[22],
          centerPoint.y = (signed __int64)v8,
          v11 = v9,
          v12 = v10,
          v13 = TacticalAIGroup::desiredNumberUnits(v2),
          TribeInformationAIModule::findGatherPosition(
            &v3->md->informationAI,
            &centerPoint,
            v13,
            (int)ga,
            v12,
            v11,
            v6,
            &gatherPoint) == 1) )
    {
      v14 = (double)gatherPoint.y;
      v15 = (double)gatherPoint.x;
      TacticalAIGroup::setAllLocations(v2, v15, v14, v6->world_z);
    }
    else
    {
      TacticalAIGroup::setAllLocations(v2, v6->world_x, v6->world_y, v6->world_z);
    }
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (00500DE0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::setGroupInfluences(TribeTacticalAIModule *this, InfluenceMap *iMap)
{
  InfluenceMap *v2; // ebx@1
  TribeTacticalAIModule *v3; // esi@1
  TacticalAIGroup *v4; // edi@1
  char *v5; // ebp@1
  int v6; // eax@4
  TribeMainDecisionAIModule *v7; // ecx@4
  signed int clearDistance; // ST24_4@4
  double v9; // st7@4
  TribeMainDecisionAIModule *v10; // ecx@4
  double v11; // st7@4
  TribeMainDecisionAIModule *v12; // ecx@4
  int i; // ebp@6
  int *v14; // edi@8
  int j; // eax@9
  RGE_Static_Object *v16; // eax@13
  RGE_Static_Object *v17; // edi@13
  TribeInformationAIModule *v18; // ecx@14
  TribeMainDecisionAIModule *v19; // ecx@14
  TribeMainDecisionAIModule *v20; // ecx@14
  TribeInformationAIModule *v21; // ecx@14
  TribeMainDecisionAIModule *v22; // ecx@14
  XYPoint max; // [sp+14h] [bp-10h]@4
  XYPoint min; // [sp+1Ch] [bp-8h]@4
  InfluenceMap *iMapa; // [sp+28h] [bp+4h]@4
  InfluenceMap *iMapb; // [sp+28h] [bp+4h]@4
  InfluenceMap *iMapc; // [sp+28h] [bp+4h]@14

  v2 = iMap;
  v3 = this;
  v4 = this->groups.next;
  v5 = (char *)&this->groups;
  if ( v4 != &this->groups )
  {
    do
    {
      if ( !v4 )
        break;
      if ( TacticalAIGroup::gatherLocation(v4)->x != -1.0 )
      {
        v6 = TacticalAIGroup::desiredNumberUnits(v4);
        v7 = v3->md;
        clearDistance = TribeInformationAIModule::groupInfluenceDimension(v6);
        *(float *)&iMapa = (double)(clearDistance / 2);
        min.x = (signed __int64)(TacticalAIGroup::gatherLocation(v4)->x - *(float *)&iMapa);
        v9 = TacticalAIGroup::gatherLocation(v4)->y - *(float *)&iMapa;
        v10 = v3->md;
        min.y = (signed __int64)v9;
        TribeInformationAIModule::mapBound(&v10->informationAI, &min);
        max.x = (signed __int64)(TacticalAIGroup::gatherLocation(v4)->x + *(float *)&iMapa);
        max.y = (signed __int64)(TacticalAIGroup::gatherLocation(v4)->y + *(float *)&iMapa);
        TribeInformationAIModule::mapBound(&v3->md->informationAI, &max);
        InfluenceMap::setValue(v2, min.x, min.y, max.x, max.y, -1);
        *(float *)&iMapb = (double)clearDistance;
        min.x = (signed __int64)(TacticalAIGroup::gatherLocation(v4)->x - *(float *)&iMapb);
        v11 = TacticalAIGroup::gatherLocation(v4)->y - *(float *)&iMapb;
        v12 = v3->md;
        min.y = (signed __int64)v11;
        TribeInformationAIModule::mapBound(&v12->informationAI, &min);
        max.x = (signed __int64)(TacticalAIGroup::gatherLocation(v4)->x + *(float *)&iMapb);
        max.y = (signed __int64)(TacticalAIGroup::gatherLocation(v4)->y + *(float *)&iMapb);
        TribeInformationAIModule::mapBound(&v3->md->informationAI, &max);
        InfluenceMap::decrementValue(v2, min.x, min.y, max.x, max.y, 10);
      }
      v4 = v4->next;
    }
    while ( (char *)v4 != v5 );
  }
  for ( i = 0; i < v3->ungroupedSoldiers.numberValue; ++i )
  {
    if ( i > v3->ungroupedSoldiers.maximumSizeValue - 1 )
    {
      v14 = (int *)operator new(4 * i + 4);
      if ( v14 )
      {
        for ( j = 0; j < v3->ungroupedSoldiers.maximumSizeValue; v14[j - 1] = v3->ungroupedSoldiers.value[j - 1] )
        {
          if ( j >= i + 1 )
            break;
          ++j;
        }
        operator delete(v3->ungroupedSoldiers.value);
        v3->ungroupedSoldiers.value = v14;
        v3->ungroupedSoldiers.maximumSizeValue = i + 1;
      }
    }
    v16 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v3->ungroupedSoldiers.value[i]);
    v17 = v16;
    if ( v16 )
    {
      max.x = (signed __int64)v16->world_x;
      v18 = &v3->md->informationAI;
      max.y = (signed __int64)v16->world_y;
      TribeInformationAIModule::mapBound(v18, &max);
      min.x = (signed __int64)v17->world_x;
      v19 = v3->md;
      min.y = (signed __int64)v17->world_y;
      TribeInformationAIModule::mapBound(&v19->informationAI, &min);
      InfluenceMap::setValue(v2, max.x, max.y, min.x, min.y, -1);
      v20 = v3->md;
      *(float *)&iMapc = (double)TribeInformationAIModule::groupInfluenceDimension(1);
      max.x = (signed __int64)(v17->world_x - *(float *)&iMapc);
      v21 = &v3->md->informationAI;
      max.y = (signed __int64)(v17->world_y - *(float *)&iMapc);
      TribeInformationAIModule::mapBound(v21, &max);
      min.x = (signed __int64)(*(float *)&iMapc + v17->world_x);
      v22 = v3->md;
      min.y = (signed __int64)(*(float *)&iMapc + v17->world_y);
      TribeInformationAIModule::mapBound(&v22->informationAI, &min);
      InfluenceMap::decrementValue(v2, max.x, max.y, min.x, min.y, 10);
    }
  }
}

//----- (00501190) --------------------------------------------------------
int __userpurge TribeTacticalAIModule::selectBestCommander@<eax>(TribeTacticalAIModule *this@<ecx>, double a2@<st0>, TacticalAIGroup *temp)
{
  TribeTacticalAIModule *v3; // esi@1
  signed int v4; // ebx@1
  int v5; // edi@1
  int v6; // eax@4
  RGE_Static_Object *v7; // eax@4
  signed int v8; // esi@9
  int v9; // eax@9
  int bestUnit; // [sp+10h] [bp-8h]@1
  TribeTacticalAIModule *v12; // [sp+14h] [bp-4h]@1

  v3 = this;
  v4 = -1;
  v12 = this;
  bestUnit = -1;
  v5 = 0;
  if ( TacticalAIGroup::numberUnits(temp) > 0 )
  {
    while ( 1 )
    {
      v6 = TacticalAIGroup::unit(temp, v5);
      v7 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, v6);
      if ( v7 && v7->master_obj->id != 125 )
      {
        if ( v3->sn[75] == 2 )
          v7->vfptr->weaponRange(v7);
        else
          a2 = v7->hp;
        v8 = (signed __int64)a2;
        v9 = v12->sn[75];
        if ( v9 == 1 || v9 == 3 )
        {
          if ( v4 == -1 || v8 < v4 )
          {
LABEL_16:
            bestUnit = TacticalAIGroup::unit(temp, v5);
            v4 = (signed __int64)a2;
            goto LABEL_17;
          }
        }
        else if ( v4 == -1 || v8 > v4 )
        {
          goto LABEL_16;
        }
      }
LABEL_17:
      if ( ++v5 >= TacticalAIGroup::numberUnits(temp) )
        return bestUnit;
      v3 = v12;
    }
  }
  return bestUnit;
}

//----- (00501260) --------------------------------------------------------
int __userpurge TribeTacticalAIModule::selectBestCommander@<eax>(TribeTacticalAIModule *this@<ecx>, double a2@<st0>, ManagedArray<int> *temp)
{
  ManagedArray<int> *v3; // esi@1
  signed int v4; // ebp@1
  int v5; // edi@1
  int v6; // ebx@3
  int *v7; // edi@3
  int j; // eax@4
  RGE_Static_Object *v9; // eax@9
  int v10; // eax@14
  int v11; // ebx@19
  int *v12; // edi@19
  int l; // eax@20
  int v14; // ebx@29
  int *v15; // edi@29
  int k; // eax@30
  int i; // [sp+Ch] [bp-Ch]@1
  int bestUnit; // [sp+10h] [bp-8h]@1
  TribeTacticalAIModule *v20; // [sp+14h] [bp-4h]@1
  ManagedArray<int> *tempa; // [sp+1Ch] [bp+4h]@14

  v3 = temp;
  v4 = -1;
  v5 = 0;
  v20 = this;
  bestUnit = -1;
  for ( i = 0; v5 < v3->numberValue; i = ++v5 )
  {
    if ( v5 > v3->maximumSizeValue - 1 )
    {
      v6 = v5 + 1;
      v7 = (int *)operator new(4 * v5 + 4);
      if ( v7 )
      {
        for ( j = 0; j < v3->maximumSizeValue; v7[j - 1] = v3->value[j - 1] )
        {
          if ( j >= v6 )
            break;
          ++j;
        }
        operator delete(v3->value);
        v3->value = v7;
        v3->maximumSizeValue = v6;
      }
      v5 = i;
    }
    v9 = MainDecisionAIModule::object((MainDecisionAIModule *)&v20->md->vfptr, v3->value[v5]);
    if ( !v9 || v9->master_obj->id == 125 )
      continue;
    if ( v20->sn[75] == 2 )
      v9->vfptr->weaponRange(v9);
    else
      a2 = v9->hp;
    tempa = (ManagedArray<int> *)(signed __int64)a2;
    v10 = v20->sn[75];
    if ( v10 == 1 || v10 == 3 )
    {
      if ( v4 != -1 && (signed int)tempa >= v4 )
        continue;
      if ( v5 > v3->maximumSizeValue - 1 )
      {
        v14 = v5 + 1;
        v15 = (int *)operator new(4 * v5 + 4);
        if ( v15 )
        {
          for ( k = 0; k < v3->maximumSizeValue; v15[k - 1] = v3->value[k - 1] )
          {
            if ( k >= v14 )
              break;
            ++k;
          }
          operator delete(v3->value);
          v3->value = v15;
          v3->maximumSizeValue = v14;
        }
        v5 = i;
      }
      bestUnit = v3->value[v5];
    }
    else
    {
      if ( v4 != -1 && (signed int)tempa <= v4 )
        continue;
      if ( v5 > v3->maximumSizeValue - 1 )
      {
        v11 = v5 + 1;
        v12 = (int *)operator new(4 * v5 + 4);
        if ( v12 )
        {
          for ( l = 0; l < v3->maximumSizeValue; v12[l - 1] = v3->value[l - 1] )
          {
            if ( l >= v11 )
              break;
            ++l;
          }
          operator delete(v3->value);
          v3->value = v12;
          v3->maximumSizeValue = v11;
        }
        v5 = i;
      }
      bestUnit = v3->value[v5];
    }
    v4 = (signed __int64)a2;
  }
  return bestUnit;
}

//----- (00501430) --------------------------------------------------------
bool __userpurge TribeTacticalAIModule::dealWithGAIAAttacker@<al>(TribeTacticalAIModule *this@<ecx>, RGE_Static_Object *attacker, RGE_Static_Object *victim, signed int a4, signed int a5)
{
  RGE_Static_Object *v5; // esi@1
  TribeTacticalAIModule *v6; // edi@1
  int v7; // edx@3
  int i; // eax@3
  double v9; // st7@7
  int v10; // ebx@7
  RGE_Static_Object *v11; // edi@11
  double v12; // st7@12
  signed __int64 v13; // rax@12
  double v14; // st7@12
  RGE_Static_ObjectVtbl *v15; // ebp@12
  RGE_Player *v16; // edx@13
  int v17; // ecx@13
  TribeTacticalAIModule *v18; // edi@13
  int v19; // eax@13
  float v20; // edx@13
  bool result; // al@14
  RGE_Static_Object *v22; // [sp+8h] [bp-38h]@12
  signed int v23; // [sp+Ch] [bp-34h]@12
  signed int v24; // [sp+10h] [bp-30h]@12
  float v25; // [sp+14h] [bp-2Ch]@12
  TribeTacticalAIModule *v26; // [sp+28h] [bp-18h]@1
  XYPoint vPosition; // [sp+2Ch] [bp-14h]@7
  XYZPoint point; // [sp+34h] [bp-Ch]@12
  RGE_Static_Object *attackera; // [sp+44h] [bp+4h]@7

  v5 = attacker;
  v6 = this;
  v26 = this;
  if ( attacker && victim )
  {
    v7 = this->civilianExplorers.numberValue;
    for ( i = 0; i < v7; ++i )
    {
      if ( i >= this->civilianExplorers.maximumSizeValue )
        break;
      if ( this->civilianExplorers.value[i] == victim->id )
        goto LABEL_15;
    }
    attackera = 0;
    v9 = victim->world_y;
    vPosition.x = (signed __int64)victim->world_x;
    vPosition.y = (signed __int64)v9;
    v10 = TribeTacticalAIModule::civilian(this, &vPosition, 1, 700, 713, 713, 1);
    if ( v10 != -1 )
    {
      while ( (signed int)attackera < v6->sn[100] )
      {
        v11 = MainDecisionAIModule::object((MainDecisionAIModule *)&v6->md->vfptr, v10);
        if ( !v11 )
          break;
        v12 = v5->world_y;
        point.x = (signed __int64)v5->world_x;
        v13 = (signed __int64)v12;
        v14 = v5->world_z;
        point.y = v13;
        HIDWORD(v13) = v5->id;
        v15 = v11->vfptr;
        v25 = -6.8056469e38/*NaN*/;
        v24 = -1;
        v23 = 1;
        v22 = 0;
        point.z = (signed __int64)v14;
        ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, signed int, signed int, signed int))v15->weaponRange)(
          v11,
          HIDWORD(v13),
          0,
          1,
          -1,
          -1);
        v25 = v14;
        v22 = victim;
        v23 = a4;
        v24 = a5;
        if ( !((int (__thiscall *)(RGE_Static_Object *, RGE_Static_Object *, signed int, signed int, _DWORD))v15->canPath)(
                v11,
                victim,
                a4,
                a5,
                LODWORD(v25)) )
          break;
        v16 = v5->owner;
        v17 = v5->id;
        v18 = v26;
        v25 = 0.0;
        v19 = v16->id;
        v20 = v5->world_y;
        v24 = -1;
        v23 = 0;
        v22 = 0;
        TribeTacticalAIModule::taskAttacker(v26, v10, v5->world_x, v20, v17, v19, 0, 0, -1, 0);
        attackera = (RGE_Static_Object *)((char *)attackera + 1);
        v10 = TribeTacticalAIModule::civilian(v18, &vPosition, 1, 700, 713, 713, 1);
        if ( v10 == -1 )
          break;
        v6 = v26;
      }
    }
    result = (signed int)attackera > 0;
  }
  else
  {
LABEL_15:
    result = 0;
  }
  return result;
}

//----- (005015E0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::addWaypoint(TribeTacticalAIModule *this, int recipient, int x, char y)
{
  TribeMainDecisionAIModule *v4; // eax@1

  v4 = this->md;
  BYTE1(x) = y;
  BYTE2(x) = 1;
  ((void (__stdcall *)(int, _DWORD *, signed int))v4->player->vfptr->sendAddWaypointCommand)(recipient, &x, 1);
}

//----- (00501620) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::importantGroupLeader(TribeTacticalAIModule *this, int cID)
{
  RGE_Static_Object *result; // eax@1
  __int16 v3; // ax@2

  result = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, cID);
  if ( result )
  {
    v3 = result->master_obj->object_group;
    result = (RGE_Static_Object *)(v3 == 18 || v3 == 13);
  }
  return result;
}

//----- (00501660) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::enableAttack(TribeTacticalAIModule *this, int type)
{
  int v2; // eax@2

  if ( this->attackEnabledValue != 1 )
  {
    v2 = this->sn[134];
    if ( !v2 || v2 == type )
      this->attackEnabledValue = 1;
  }
}

//----- (00501690) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTacticalAIModule::unexploredArea(TribeTacticalAIModule *this, int uID, XYPoint *rPoint)
{
  TribeTacticalAIModule *v3; // ebp@1
  RGE_Static_Object *result; // eax@1
  XYPoint *v5; // esi@2
  RGE_Static_Object *v6; // ebx@2
  int v7; // ecx@2
  int v8; // edx@2
  int v9; // edi@3
  signed __int64 v10; // rax@4
  int v11; // eax@5
  int v12; // eax@8
  int v13; // eax@9
  int v14; // edi@17
  float y; // ST20_4@20
  float x; // ST1C_4@20
  long double v17; // st7@20
  bool v18; // sf@23
  unsigned __int8 v19; // of@23
  char unitZone; // [sp+1Fh] [bp-11h]@2
  float bestDistance; // [sp+20h] [bp-10h]@2
  RGE_Static_Object *unit; // [sp+24h] [bp-Ch]@1
  signed int bestPoint; // [sp+28h] [bp-8h]@2
  signed int bestPoint_4; // [sp+2Ch] [bp-4h]@2
  XYPoint *rPointa; // [sp+38h] [bp+8h]@3

  v3 = this;
  result = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, uID);
  unit = result;
  if ( result )
  {
    unitZone = RGE_Static_Object::currentZone(result);
    v5 = rPoint;
    v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->md->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    v7 = -1;
    v8 = -1;
    bestDistance = -1.0;
    bestPoint = -1;
    bestPoint_4 = -1;
    if ( v6 )
    {
      v9 = 0;
      rPointa = 0;
      do
      {
        v5->x = (signed __int64)v6->world_x;
        v10 = (signed __int64)v6->world_y;
        v5->y = v10;
        switch ( v9 )
        {
          case 0:
            v11 = v5->y;
            v5->x -= 10;
            v5->y = v11 - 10;
            break;
          case 2:
            LODWORD(v10) = v5->y;
            v5->x += 10;
            goto LABEL_7;
          case 1:
LABEL_7:
            v5->y = v10 - 10;
            break;
          case 3:
            v12 = v5->x + 10;
            goto LABEL_13;
          case 4:
            v13 = v5->y;
            v5->x += 10;
            v5->y = v13 + 10;
            break;
          case 6:
            LODWORD(v10) = v5->y;
            v5->x -= 10;
            goto LABEL_11;
          case 5:
LABEL_11:
            v5->y = v10 + 10;
            break;
          case 7:
            v12 = v5->x - 10;
LABEL_13:
            v5->x = v12;
            break;
          default:
            break;
        }
        if ( v5->x >= 0 && v5->y >= 0 && v5->x < TribeInformationAIModule::mapXSize(&v3->md->informationAI) )
        {
          v14 = v5->y;
          if ( v14 < TribeInformationAIModule::mapYSize(&v3->md->informationAI)
            && TribeInformationAIModule::tileUncovered(&v3->md->informationAI, v5->x, v14) != 1
            && unitZone == RGE_Static_Object::lookupZone(unit, v5->x, v5->y) )
          {
            y = (double)v5->y;
            x = (double)v5->x;
            v17 = RGE_Static_Object::distance_to_position(unit, x, y, unit->world_z);
            if ( bestDistance == -1.0 || v17 < bestDistance )
            {
              bestDistance = v17;
              bestPoint = v5->x;
              bestPoint_4 = v5->y;
            }
          }
        }
        v9 = (int)&rPointa->x + 1;
        v19 = __OFSUB__((char *)&rPointa->x + 1, 8);
        v18 = (signed int)&rPointa[-1].x + 1 < 0;
        rPointa = (XYPoint *)((char *)rPointa + 1);
      }
      while ( v18 ^ v19 );
      v8 = bestPoint_4;
      v7 = bestPoint;
    }
    if ( bestDistance == -1.0 )
    {
      result = (RGE_Static_Object *)(TribeInformationAIModule::unexploredPlayerLocation(&v3->md->informationAI, uID, v5) != 0);
    }
    else
    {
      v5->x = v7;
      v5->y = v8;
      TribeInformationAIModule::setTileExplored(&v3->md->informationAI, v7, v8);
      result = (RGE_Static_Object *)1;
    }
  }
  return result;
}

//----- (005018F0) --------------------------------------------------------
UnitData *__thiscall TribeTacticalAIModule::gatherer(TribeTacticalAIModule *this, int id)
{
  signed int v2; // eax@1
  char *v3; // edx@1

  v2 = 0;
  v3 = (char *)this->gatherers;
  while ( *(_DWORD *)v3 != id )
  {
    ++v2;
    v3 += 24;
    if ( v2 >= 50 )
      return 0;
  }
  return &this->gatherers[v2];
}

//----- (00501920) --------------------------------------------------------
UnitData *__thiscall TribeTacticalAIModule::addGatherer(TribeTacticalAIModule *this, int id)
{
  UnitData *result; // eax@2
  signed int v3; // edi@3
  signed int v4; // eax@3
  char *v5; // esi@3
  char *v6; // edx@11

  if ( id == -1 )
  {
    AIModule::logCommonHistory((AIModule *)&this->vfptr, aErrorAddingGat);
    result = 0;
  }
  else
  {
    v3 = -1;
    v4 = 0;
    v5 = (char *)this->gatherers;
    do
    {
      if ( *(_DWORD *)v5 != -1 || v3 != -1 )
      {
        if ( *(_DWORD *)v5 == id )
          return &this->gatherers[v4];
      }
      else
      {
        v3 = v4;
      }
      ++v4;
      v5 += 24;
    }
    while ( v4 < 50 );
    if ( v3 == -1 )
    {
      result = 0;
    }
    else
    {
      v6 = (char *)this + 24 * v3;
      result = (UnitData *)(v6 + 1308);
      *((_DWORD *)v6 + 327) = id;
      *((_DWORD *)v6 + 331) = -1;
      *((_DWORD *)v6 + 332) = 0;
      ++this->numberGatherersValue;
    }
  }
  return result;
}

//----- (005019C0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::removeGatherer(TribeTacticalAIModule *this, int id)
{
  int result; // eax@2
  signed int v3; // edx@3
  char *v4; // eax@3
  char *v5; // edi@7
  int v6; // eax@7
  int v7; // ecx@8

  if ( id == -1 )
  {
    AIModule::logCommonHistory((AIModule *)&this->vfptr, aErrorRemovingG);
    result = 0;
  }
  else
  {
    v3 = 0;
    v4 = (char *)this->gatherers;
    while ( *(_DWORD *)v4 != id )
    {
      ++v3;
      v4 += 24;
      if ( v3 >= 50 )
        return 0;
    }
    v5 = (char *)this + 24 * v3;
    v6 = (int)(v5 + 1312);
    *((_DWORD *)v5 + 327) = -1;
    *((_DWORD *)v5 + 328) = -1;
    *((_DWORD *)v5 + 329) = -1;
    *((_DWORD *)&this->vfptr + 6 * (v3 + 55)) = -1;
    *((_DWORD *)v5 + 331) = -1;
    --this->numberGatherersValue;
    for ( ; v3 < 49; v6 += 24 )
    {
      v7 = *(_DWORD *)(v6 + 20);
      if ( v7 == -1 )
        break;
      *(_DWORD *)(v6 - 4) = v7;
      *(_DWORD *)v6 = *(_DWORD *)(v6 + 24);
      *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 28);
      *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 32);
      *(_DWORD *)(v6 + 12) = *(_DWORD *)(v6 + 36);
      *(_DWORD *)(v6 + 20) = -1;
      *(_DWORD *)(v6 + 24) = -1;
      *(_DWORD *)(v6 + 28) = -1;
      *(_DWORD *)(v6 + 32) = -1;
      *(_DWORD *)(v6 + 36) = -1;
      ++v3;
    }
    result = 1;
  }
  return result;
}

//----- (00501A80) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::isGatherer(TribeTacticalAIModule *this, int id)
{
  signed int v2; // eax@1
  char *v3; // ecx@1

  v2 = 0;
  v3 = (char *)this->gatherers;
  while ( *(_DWORD *)v3 != id )
  {
    ++v2;
    v3 += 24;
    if ( v2 >= 50 )
      return 0;
  }
  return 1;
}

//----- (00501AB0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::requiredGatherAmount(TribeTacticalAIModule *this, int rType)
{
  int result; // eax@2

  if ( this->desiredGathererDistribution[rType] )
    result = ResourceItem::value(&this->neededResources, rType) / this->desiredGathererDistribution[rType];
  else
    result = this->sn[148];
  return result;
}

//----- (00501AF0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::trackUnitGather(TribeTacticalAIModule *this, int unitID, int attributeID, int amount)
{
  TribeTacticalAIModule *v4; // esi@1
  UnitData *v5; // eax@4

  v4 = this;
  if ( this->resourceDifferenceValue[attributeID] < 0
    && this->resourceDifferenceValue[attributeID] + TribeResourceAIModule::resource(&this->md->resourceAI, attributeID) > 0 )
  {
    TribeTacticalAIModule::updateNeededResources(v4);
  }
  v5 = TribeTacticalAIModule::gatherer(v4, unitID);
  if ( v5 )
  {
    if ( v5->data1 == attributeID )
      v5->data3 += amount;
  }
}

//----- (00501B50) --------------------------------------------------------
BOOL __thiscall TribeTacticalAIModule::deleteUnit(TribeTacticalAIModule *this, int unitID)
{
  TribeTacticalAIModule *v2; // esi@1
  RGE_Static_Object *v3; // eax@1

  v2 = this;
  v3 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, unitID);
  return v3 && TRIBE_Player::command_delete_object(v2->md->aiPlayer, v3) == 1;
}

//----- (00501B90) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberAvailableStoragePits(TribeTacticalAIModule *this, int *numStoragePits, int *numUnbuiltStoragePits, int rType)
{
  TribeTacticalAIModule *v4; // esi@1
  int v5; // eax@1
  int result; // eax@2
  int v7; // ebx@5
  TribeMainDecisionAIModule *v8; // edi@6
  signed __int64 v9; // rax@6
  int v10; // esi@8
  int v11; // eax@8

  v4 = this;
  v5 = BuildAIModule::numberUnbuiltItemsOfType((BuildAIModule *)&this->md->buildAI.vfptr, 103, 0);
  *numUnbuiltStoragePits = v5;
  if ( v5 <= 0 )
  {
    if ( v4->sn[rType + 190] > TribeResourceAIModule::resource(&v4->md->resourceAI, rType) )
    {
      v7 = v4->sn[150];
      if ( v7 == -1 )
      {
        *numStoragePits = BuildAIModule::numberItemsOfType((BuildAIModule *)&v4->md->buildAI.vfptr, 103, 0);
        result = TribeInformationAIModule::numberAvailableStoragePits(&v4->md->informationAI, rType);
      }
      else
      {
        v8 = v4->md;
        v9 = (signed __int64)v8->player->attributes[6];
        if ( !(_DWORD)v9 )
          LODWORD(v9) = 1;
        v10 = v7 * v9;
        v11 = BuildAIModule::numberItemsOfType((BuildAIModule *)&v8->buildAI.vfptr, 103, 0);
        *numStoragePits = v11;
        result = (v10 - v11) & ((v10 - v11 < 0) - 1);
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00501C70) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberAvailableGranaries(TribeTacticalAIModule *this, int *numGranaries, int *numUnbuiltGranaries)
{
  TribeTacticalAIModule *v3; // esi@1
  int v4; // eax@1
  int result; // eax@2
  int v6; // eax@6

  v3 = this;
  v4 = BuildAIModule::numberUnbuiltItemsOfType((BuildAIModule *)&this->md->buildAI.vfptr, 68, 0);
  *numUnbuiltGranaries = v4;
  if ( v4 <= 0 )
  {
    if ( v3->sn[190] > TribeResourceAIModule::resource(&v3->md->resourceAI, 0) )
    {
      if ( v3->sn[151] == -1
        || (v6 = BuildAIModule::numberItemsOfType((BuildAIModule *)&v3->md->buildAI.vfptr, 68, 0),
            *numGranaries = v6,
            v6 < v3->sn[151]) )
      {
        *numGranaries = BuildAIModule::numberItemsOfType((BuildAIModule *)&v3->md->buildAI.vfptr, 68, 0);
        result = TribeInformationAIModule::numberAvailableGranaries(&v3->md->informationAI);
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00501D20) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::initialExplorationSatisfied(TribeTacticalAIModule *this)
{
  int result; // eax@2

  if ( this->sn[167] > 0 )
    result = (signed int)(signed __int64)(RGE_Visible_Map::percentExplored(this->md->player->visible) * 100.0) >= this->sn[167];
  else
    result = 1;
  return result;
}

//----- (00501D70) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkForBuildInsertion(TribeTacticalAIModule *this, int type, int number, int position)
{
  TribeTacticalAIModule *v4; // esi@1
  int v5; // edi@5
  int v6; // eax@6
  ResourceItem *v7; // ecx@8
  int v8; // eax@18
  TribeMainDecisionAIModule *v9; // eax@20
  int v10; // edi@24
  int v11; // eax@25
  int numUnbuiltGranaries; // [sp+Ch] [bp-84h]@18
  int numGranaries; // [sp+10h] [bp-80h]@18
  ResourceItem itemCost; // [sp+14h] [bp-7Ch]@5
  int i; // [sp+8Ch] [bp-4h]@5

  v4 = this;
  if ( type == 50 )
  {
    if ( this->sn[206] == 1 && TribeTacticalAIModule::inAge(this, 4) )
    {
      ResourceItem::ResourceItem(&itemCost, 4);
      v10 = 0;
      for ( i = 0; v10 < number; ++v10 )
      {
        v11 = ResourceItem::value(&itemCost, v10);
        ResourceItem::setValue(&itemCost, v10, number * v11);
      }
      TRIBE_Player::objectCost(v4->md->aiPlayer, 50, -1, &itemCost, 1);
      if ( TribeResourceAIModule::resourcesAvailable(&v4->md->resourceAI, &itemCost)
        && TRIBE_Player::objectAvailable(v4->md->aiPlayer, 50)
        && TribeBuildAIModule::allBuilt(&v4->md->buildAI, 0, 0)
        && ((int (__thiscall *)(int, signed int, _DWORD))v4->md->buildAI.vfptr[1].toggleLogHistory)(
             (int)&v4->md->buildAI,
             50,
             0) < v4->sn[220] )
      {
        TribeBuildAIModule::insert(&v4->md->buildAI, 50, number, position);
      }
      i = -1;
      v7 = &itemCost;
      goto LABEL_32;
    }
  }
  else if ( type == 68 )
  {
    if ( this->sn[205] == 1 && this->md->informationAI.closestDropsiteValue[0] != -1 )
    {
      numGranaries = 0;
      numUnbuiltGranaries = 0;
      v8 = TribeTacticalAIModule::numberAvailableGranaries(this, &numGranaries, &numUnbuiltGranaries);
      if ( numUnbuiltGranaries <= 0 && v8 > 0 )
      {
        v9 = v4->md;
        if ( v4->sn[163] < v9->informationAI.closestDropsiteValue[0] )
          TribeBuildAIModule::insert(&v9->buildAI, 68, number, position);
      }
    }
  }
  else if ( type == 79 && this->sn[207] == 1 )
  {
    ResourceItem::ResourceItem(&itemCost, 4);
    v5 = 0;
    for ( i = 1; v5 < number; ++v5 )
    {
      v6 = ResourceItem::value(&itemCost, v5);
      ResourceItem::setValue(&itemCost, v5, number * v6);
    }
    TRIBE_Player::objectCost(v4->md->aiPlayer, 79, -1, &itemCost, 1);
    if ( TribeResourceAIModule::resourcesAvailable(&v4->md->resourceAI, &itemCost) )
    {
      if ( TRIBE_Player::objectAvailable(v4->md->aiPlayer, 79) )
      {
        if ( TribeBuildAIModule::allBuilt(&v4->md->buildAI, 0, 0) )
        {
          if ( ((int (__thiscall *)(TribeBuildAIModule *, signed int, _DWORD))v4->md->buildAI.vfptr[1].toggleLogHistory)(
                 &v4->md->buildAI,
                 79,
                 0) < v4->sn[222] )
          {
            TribeBuildAIModule::insert(&v4->md->buildAI, 79, number, position);
            i = -1;
            v7 = &itemCost;
          }
          else
          {
            i = -1;
            v7 = &itemCost;
          }
        }
        else
        {
          i = -1;
          v7 = &itemCost;
        }
      }
      else
      {
        i = -1;
        v7 = &itemCost;
      }
    }
    else
    {
      i = -1;
      v7 = &itemCost;
    }
LABEL_32:
    ResourceItem::~ResourceItem(v7);
    return;
  }
}

//----- (005020A0) --------------------------------------------------------
int __stdcall TribeTacticalAIModule::isFarmer(RGE_Static_Object *temp)
{
  UnitAIModule *v2; // eax@4
  UnitAIModule *v3; // eax@5
  int result; // eax@6

  result = 0;
  if ( temp )
  {
    if ( RGE_Static_Object::unitAI(temp) )
    {
      if ( temp->master_obj->id == 259 )
      {
        v2 = RGE_Static_Object::unitAI(temp);
        if ( UnitAIModule::currentAction(v2) == 609
          || (v3 = RGE_Static_Object::unitAI(temp), UnitAIModule::currentAction(v3) == 610) )
        {
          result = 1;
        }
      }
    }
  }
  return result;
}

//----- (00502100) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberFarmers(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebx@1
  int v3; // ebp@3
  int *v4; // edi@3
  int i; // eax@4
  RGE_Static_Object *v6; // eax@8
  RGE_Static_Object *v7; // edi@8
  UnitAIModule *v8; // eax@11
  UnitAIModule *v9; // eax@12
  int rVal; // [sp+8h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  for ( rVal = 0; v2 < v1->civilians.numberValue; ++v2 )
  {
    if ( v2 > v1->civilians.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( i = 0; i < v1->civilians.maximumSizeValue; v4[i - 1] = v1->civilians.value[i - 1] )
        {
          if ( i >= v3 )
            break;
          ++i;
        }
        operator delete(v1->civilians.value);
        v1->civilians.value = v4;
        v1->civilians.maximumSizeValue = v3;
      }
    }
    v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->civilians.value[v2]);
    v7 = v6;
    if ( v6 )
    {
      if ( RGE_Static_Object::unitAI(v6) )
      {
        if ( v7->master_obj->id == 259 )
        {
          v8 = RGE_Static_Object::unitAI(v7);
          if ( UnitAIModule::currentAction(v8) == 609
            || (v9 = RGE_Static_Object::unitAI(v7), UnitAIModule::currentAction(v9) == 610) )
          {
            ++rVal;
          }
        }
      }
    }
  }
  return rVal;
}

//----- (00502200) --------------------------------------------------------
BOOL __thiscall TribeTacticalAIModule::inAge(TribeTacticalAIModule *this, int age)
{
  return (unsigned __int64)(signed __int64)this->md->player->attributes[6] == age;
}

//----- (00502230) --------------------------------------------------------
void __stdcall TribeTacticalAIModule::stuffAvoidancePath(TacticalAIGroup *group, Path *path)
{
  Path *v3; // esi@1
  long double v4; // st7@1
  signed int v5; // edi@3
  int v6; // ebx@5
  float v7; // ST04_4@10
  Waypoint *v8; // eax@10
  float divisionLength; // [sp+10h] [bp-4h]@1
  Path *patha; // [sp+1Ch] [bp+8h]@3

  v3 = path;
  v4 = Path::length(path) * 0.2;
  divisionLength = v4;
  if ( v4 < 10.0 )
    divisionLength = 10.0;
  Path::initToStart(path);
  *(float *)&patha = Path::distanceToNextWaypoint(path);
  Path::moveToNextWaypoint(v3);
  v5 = 0;
  if ( Path::numberOfWaypoints(v3) <= 5 )
    v5 = 1;
  v6 = 1;
  while ( v6 < Path::numberOfWaypoints(v3) - 1 )
  {
    if ( (v5 || *(float *)&patha >= (double)divisionLength) && (v5 != 1 || *(float *)&patha >= 5.0) )
    {
      v7 = Path::currentWaypoint(v3)->y;
      v8 = Path::currentWaypoint(v3);
      TacticalAIGroup::addAttackWaypoint(group, v8->x, v7);
    }
    ++v6;
    *(float *)&patha = Path::distanceToNextWaypoint(v3) + *(float *)&patha;
    Path::moveToNextWaypoint(v3);
  }
}

//----- (00502310) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkForAttackResponseBuildInsertions(TribeTacticalAIModule *this, int playerID)
{
  TribeTacticalAIModule *v2; // ebx@1
  TribeMainDecisionAIModule *v3; // ecx@1
  RGE_Static_Object *v4; // eax@2
  int v5; // edi@2
  int v6; // eax@3
  signed int v7; // ebp@3
  int v8; // eax@6
  int v9; // esi@14
  TRIBE_Player *v10; // ecx@30
  int i; // [sp+10h] [bp-84h]@6
  int insertedUnit; // [sp+14h] [bp-80h]@6
  ResourceItem itemCost; // [sp+18h] [bp-7Ch]@30
  int v14; // [sp+90h] [bp-4h]@30

  v2 = this;
  v3 = this->md;
  if ( (signed int)(v3->player->world->world_time - v2->lastAttackResponseBuildInsertionTime) / 1000 >= 180 )
  {
    v2->lastAttackResponseBuildInsertionTime = v3->player->world->world_time;
    v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&v3->vfptr, -1, 109, -1, -1, -1, -1, -1, -1, -1, -1);
    v5 = 0;
    if ( v4 )
    {
      v6 = TribeInformationAIModule::numberUnitsWithinXTiles(
             &v2->md->informationAI,
             playerID,
             (signed __int64)v4->world_x,
             (signed __int64)v4->world_y,
             20)
         - v2->soldiers.numberValue;
      v7 = v6;
      if ( v6 > 0 )
      {
        if ( v6 > 5 )
          v7 = 5;
        v8 = 0;
        i = 0;
        insertedUnit = 0;
        if ( v7 > 0 )
        {
          while ( 1 )
          {
            switch ( v8 )
            {
              case 0:
                if ( TribeResourceAIModule::resource(&v2->md->resourceAI, 2) >= 150 && v2->civilians.numberValue > 2 )
                {
                  TribeBuildAIModule::insert(&v2->md->buildAI, 79, 1, 0);
                  v7 -= 2;
                }
                i = 1;
                goto LABEL_35;
              case 1:
                v9 = 37;
                goto LABEL_25;
              case 2:
                v9 = 75;
                v5 = 12;
                goto LABEL_26;
              case 3:
                v9 = 93;
                goto LABEL_26;
              case 4:
                v9 = 39;
                v5 = 87;
                goto LABEL_26;
              case 5:
                v9 = 73;
                v5 = 12;
                goto LABEL_26;
              case 6:
                v9 = 5;
                v5 = 87;
                goto LABEL_26;
              case 7:
                v9 = 299;
                goto LABEL_25;
              case 8:
                v9 = 4;
                v5 = 87;
                goto LABEL_26;
              case 9:
                v9 = 125;
                v5 = 104;
                goto LABEL_26;
              case 10:
                v9 = 41;
                v5 = 87;
                goto LABEL_26;
              case 11:
                v9 = 40;
LABEL_25:
                v5 = 101;
LABEL_26:
                if ( TRIBE_Player::objectAvailable(v2->md->aiPlayer, v9) )
                {
                  if ( MainDecisionAIModule::object(
                         (MainDecisionAIModule *)&v2->md->vfptr,
                         -1,
                         v5,
                         -1,
                         -1,
                         -1,
                         -1,
                         -1,
                         -1,
                         -1,
                         -1) )
                  {
                    ResourceItem::ResourceItem(&itemCost, 4);
                    v10 = v2->md->aiPlayer;
                    v14 = 0;
                    TRIBE_Player::objectCost(v10, v9, -1, &itemCost, 1);
                    if ( TribeResourceAIModule::resourcesAvailable(&v2->md->resourceAI, &itemCost) == 1 )
                    {
                      TribeBuildAIModule::insert(&v2->md->buildAI, v9, 1, 0);
                      --v7;
                      insertedUnit = 1;
                    }
                    v14 = -1;
                    ++i;
                    ResourceItem::~ResourceItem(&itemCost);
                  }
                  else
                  {
                    ++i;
                  }
                }
                else
                {
                  ++i;
                }
                goto LABEL_35;
              default:
                if ( insertedUnit != 1 )
                  return;
                i = 1;
                insertedUnit = 0;
LABEL_35:
                v5 = 0;
                if ( v7 <= 0 )
                  return;
                v8 = i;
                break;
            }
          }
        }
      }
    }
  }
}

//----- (00502600) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkForCoopTributeDemand(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // ebp@1
  int v2; // ebx@1
  TribeMainDecisionAIModule *v3; // esi@2
  TRIBE_World *v4; // edi@3
  signed int v5; // esi@4
  signed int k; // ebx@4
  int v7; // edx@10
  signed int v8; // ebx@10
  RGE_Player *v9; // esi@11
  int v10; // esi@16
  int v11; // ebx@27
  RGE_Player *v12; // esi@29
  __int16 v13; // bx@33
  __int16 v14; // ax@33
  signed __int64 v15; // rax@36
  bool v16; // sf@42
  unsigned __int8 v17; // of@42
  int amountDemandable; // [sp+18h] [bp-18h]@16
  int tempRand; // [sp+1Ch] [bp-14h]@10
  int *tempRanda; // [sp+1Ch] [bp-14h]@16
  TRIBE_World *world; // [sp+20h] [bp-10h]@3
  int i; // [sp+24h] [bp-Ch]@27
  int j; // [sp+28h] [bp-8h]@16
  RGE_PlayerVtbl *v24; // [sp+2Ch] [bp-4h]@32

  v1 = this;
  v2 = this->sn[186];
  if ( v2 != -1 )
  {
    v3 = this->md;
    if ( (signed int)(v3->player->world->world_time - this->lastCoopTributeDemandTime) / 1000 >= v2 )
    {
      this->lastCoopTributeDemandTime = v3->player->world->world_time;
      v4 = (TRIBE_World *)v3->player->world;
      world = v4;
      if ( v4->controllingComputerPlayer == -1 )
      {
        v5 = 1;
        for ( k = 0; v5 < v4->player_num; ++v5 )
        {
          if ( RGE_Player::computerPlayer(v4->players[v5]) == 1 )
            ++k;
        }
        if ( k == 1 )
        {
          v4->controllingComputerPlayer = v1->md->player->id;
        }
        else
        {
          v7 = debug_rand(aCMsdevWorkA_61, 12784) % k;
          v8 = 1;
          for ( tempRand = v7 + 1; v8 < v4->player_num; ++v8 )
          {
            v9 = v4->players[v8];
            if ( RGE_Player::computerPlayer(v4->players[v8]) == 1 && !--tempRand )
              v4->controllingComputerPlayer = v9->id;
          }
        }
      }
      if ( v4->controllingComputerPlayer == LOBYTE(v1->md->player->id) )
      {
        v10 = (int)v1->neededResourceValue;
        amountDemandable = v1->sn[187];
        j = 0;
        tempRanda = v1->neededResourceValue;
        do
        {
          if ( amountDemandable <= 0 )
            break;
          if ( (*(_DWORD *)v10 || TribeResourceAIModule::resource(&v1->md->resourceAI, 0) < v1->sn[190])
            && (*(_DWORD *)v10 != 1 || TribeResourceAIModule::resource(&v1->md->resourceAI, 1) < v1->sn[191])
            && (*(_DWORD *)v10 != 3 || TribeResourceAIModule::resource(&v1->md->resourceAI, 3) < v1->sn[193])
            && (*(_DWORD *)v10 != 2 || TribeResourceAIModule::resource(&v1->md->resourceAI, 2) < v1->sn[192])
            && *(_DWORD *)(v10 + 16) < 0 )
          {
            v11 = 1;
            for ( i = 1; i < v4->player_num; v11 = i++ + 1 )
            {
              if ( amountDemandable <= 0 )
                break;
              v12 = v4->players[v11];
              if ( v12->id != v1->md->player->id )
              {
                if ( RGE_Player::computerPlayer(v12) )
                {
                  if ( (*(int (__stdcall **)(int))&v1->md->player->vfptr->gap4[24])(v11) )
                  {
                    v24 = v12->vfptr;
                    if ( (*(int (__thiscall **)(RGE_Player *, _DWORD))&v12->vfptr->gap4[24])(v12, v1->md->player->id) )
                    {
                      if ( (v13 = v1->md->player->id, v14 = v12->id, v13 < v14) && v14 != v4->controllingComputerPlayer
                        || v13 == v4->controllingComputerPlayer )
                      {
                        v15 = (signed __int64)v12->attributes[*tempRanda];
                        if ( (signed int)v15 > 50 )
                        {
                          if ( (signed int)v15 > amountDemandable )
                            LODWORD(v15) = amountDemandable;
                          amountDemandable -= v15;
                          v24->sendAICommand(v12, v13, 1, *tempRanda, v15, 0);
                        }
                        v4 = world;
                      }
                    }
                  }
                }
              }
              v10 = (int)tempRanda;
            }
          }
          v10 += 4;
          tempRanda = (int *)v10;
          v17 = __OFSUB__(j + 1, 4);
          v16 = j++ - 3 < 0;
        }
        while ( v16 ^ v17 );
      }
    }
  }
}

//----- (00502920) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkForCoopTributeGift(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // ebp@1
  TribeMainDecisionAIModule *v2; // esi@3
  TRIBE_World *v3; // ebx@4
  signed int v4; // esi@5
  signed int k; // edi@5
  int v6; // edx@11
  signed int v7; // edi@11
  RGE_Player *v8; // esi@12
  int v9; // esi@16
  signed int v10; // edi@18
  RGE_Player *v11; // esi@19
  RGE_PlayerVtbl *v12; // ebx@22
  float *v13; // edi@23
  float tributeAmount; // ST3C_4@32
  int bestCP; // [sp+20h] [bp-1Ch]@18
  int j; // [sp+24h] [bp-18h]@16
  int *v17; // [sp+28h] [bp-14h]@16
  TRIBE_World *world; // [sp+2Ch] [bp-10h]@4
  int i; // [sp+30h] [bp-Ch]@11
  int ia; // [sp+30h] [bp-Ch]@18
  float bestCPValue; // [sp+34h] [bp-8h]@18

  v1 = this;
  if ( this->sn[186] != -1 )
  {
    if ( RGE_Object_List::find_by_master_id(this->md->aiPlayer->objects, 84, -1.0, -1.0, 0, 2, 0) )
    {
      v2 = v1->md;
      if ( (signed int)(v2->player->world->world_time - v1->lastCoopTributeGiftTime) / 1000 >= v1->sn[186] )
      {
        v1->lastCoopTributeGiftTime = v2->player->world->world_time;
        v3 = (TRIBE_World *)v2->player->world;
        world = v3;
        if ( v3->controllingComputerPlayer == -1 )
        {
          v4 = 1;
          for ( k = 0; v4 < v3->player_num; ++v4 )
          {
            if ( RGE_Player::computerPlayer(v3->players[v4]) == 1 )
              ++k;
          }
          if ( k == 1 )
          {
            v3->controllingComputerPlayer = v1->md->player->id;
          }
          else
          {
            v6 = debug_rand(aCMsdevWorkA_61, 12917) % k;
            v7 = 1;
            for ( i = v6 + 1; v7 < v3->player_num; ++v7 )
            {
              v8 = v3->players[v7];
              if ( RGE_Player::computerPlayer(v8) == 1 && !--i )
                v3->controllingComputerPlayer = v8->id;
            }
          }
        }
        v9 = 0;
        j = 0;
        v17 = &v1->sn[190];
        do
        {
          if ( TribeResourceAIModule::resource(&v1->md->resourceAI, v9) > *v17 )
          {
            v10 = 1;
            bestCP = -1;
            bestCPValue = 0.0;
            ia = 1;
            if ( v3->player_num > 1 )
            {
              do
              {
                v11 = v3->players[v10];
                if ( v11->id != v1->md->player->id
                  && RGE_Player::computerPlayer(v11)
                  && (*(int (__stdcall **)(signed int))&v1->md->player->vfptr->gap4[24])(v10) )
                {
                  v12 = v11->vfptr;
                  if ( (*(int (__thiscall **)(RGE_Player *, _DWORD))&v11->vfptr->gap4[24])(v11, v1->md->player->id) )
                  {
                    v13 = &v11->attributes[j];
                    if ( (double)v12->strategicNumber(v11, j + 190) > *v13
                      && (bestCP == -1 || *v13 < (double)bestCPValue) )
                    {
                      bestCP = v11->id;
                      bestCPValue = *v13;
                    }
                    v10 = ia;
                  }
                  v3 = world;
                }
                ia = ++v10;
              }
              while ( v10 < v3->player_num );
              v9 = j;
            }
            if ( bestCP != -1 )
            {
              tributeAmount = (double)(TribeResourceAIModule::resource(&v1->md->resourceAI, v9) - *v17);
              ((void (__stdcall *)(int, int, _DWORD, _DWORD))v1->md->aiPlayer->vfptr[1].__vecDelDtor)(
                bestCP,
                v9,
                LODWORD(tributeAmount),
                v1->md->aiPlayer->attributes[46]);
            }
          }
          j = ++v9;
          ++v17;
        }
        while ( v9 < 4 );
      }
    }
  }
}

//----- (00502BF0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkForASAPAgeResearch(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  BuildItem *v2; // eax@5
  BuildItem *v3; // eax@18

  v1 = this;
  if ( TribeTacticalAIModule::inAge(this, 1)
    && v1->sn[181] == 1
    && TribeBuildAIModule::readyToResearch(&v1->md->buildAI, 2, 1)
    && TribeResourceAIModule::resource(&v1->md->resourceAI, 0) >= 500 )
  {
    v2 = TribeBuildAIModule::buildItem(&v1->md->buildAI, 101, 1, 4);
    if ( v2 )
    {
LABEL_12:
      TribeTacticalAIModule::taskResearch(v1, v2);
      goto LABEL_13;
    }
  }
  else if ( TribeTacticalAIModule::inAge(v1, 2) )
  {
    if ( v1->sn[182] == 1 )
    {
      if ( TribeBuildAIModule::readyToResearch(&v1->md->buildAI, 3, 1) )
      {
        if ( TribeResourceAIModule::resource(&v1->md->resourceAI, 0) >= 800 )
        {
          v2 = TribeBuildAIModule::buildItem(&v1->md->buildAI, 102, 1, 4);
          if ( v2 )
            goto LABEL_12;
        }
      }
    }
  }
LABEL_13:
  if ( TribeTacticalAIModule::inAge(v1, 3)
    && v1->sn[183] == 1
    && TribeBuildAIModule::readyToResearch(&v1->md->buildAI, 4, 1)
    && TribeResourceAIModule::resource(&v1->md->resourceAI, 0) >= 900
    && TribeResourceAIModule::resource(&v1->md->resourceAI, 3) >= 700 )
  {
    v3 = TribeBuildAIModule::buildItem(&v1->md->buildAI, 103, 1, 4);
    if ( v3 )
      TribeTacticalAIModule::taskResearch(v1, v3);
  }
}

//----- (00502D50) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkForCoopAttack(TribeTacticalAIModule *this, int playerToAttack, int x, int y)
{
  TribeTacticalAIModule *v4; // ebp@1
  TribeMainDecisionAIModule *v5; // esi@2
  RGE_Game_World *v6; // edi@3
  signed int v7; // esi@4
  signed int i; // ebx@4
  int v9; // edx@10
  signed int v10; // ebx@10
  RGE_Player *v11; // esi@11
  signed int v12; // ebx@15
  RGE_Player *v13; // esi@16
  RGE_PlayerVtbl *v14; // ebx@19
  __int16 v15; // cx@20
  __int16 v16; // ax@20
  int tempRand; // [sp+1Ch] [bp-4h]@10
  int tempRanda; // [sp+1Ch] [bp-4h]@15

  v4 = this;
  if ( this->sn[196] == 1 )
  {
    v5 = this->md;
    if ( (signed int)(v5->player->world->world_time - this->lastCoopAttackDemandTime) / 1000 >= this->sn[197] )
    {
      this->lastCoopAttackDemandTime = v5->player->world->world_time;
      v6 = v5->player->world;
      if ( BYTE1(v6[1].game_speed) == -1 )
      {
        v7 = 1;
        for ( i = 0; v7 < v6->player_num; ++v7 )
        {
          if ( RGE_Player::computerPlayer(v6->players[v7]) == 1 )
            ++i;
        }
        if ( i == 1 )
        {
          BYTE1(v6[1].game_speed) = v4->md->player->id;
        }
        else
        {
          v9 = debug_rand(aCMsdevWorkA_61, 13041) % i;
          v10 = 1;
          for ( tempRand = v9 + 1; v10 < v6->player_num; ++v10 )
          {
            v11 = v6->players[v10];
            if ( RGE_Player::computerPlayer(v6->players[v10]) == 1 && !--tempRand )
              BYTE1(v6[1].game_speed) = v11->id;
          }
        }
      }
      v12 = 1;
      for ( tempRanda = 1; v12 < v6->player_num; tempRanda = ++v12 )
      {
        v13 = v6->players[v12];
        if ( v13->id != v4->md->player->id
          && RGE_Player::computerPlayer(v13)
          && (*(int (__stdcall **)(signed int))&v4->md->player->vfptr->gap4[24])(v12) )
        {
          v14 = v13->vfptr;
          if ( (*(int (__thiscall **)(RGE_Player *, _DWORD))&v13->vfptr->gap4[24])(v13, v4->md->player->id) )
          {
            if ( (v15 = v13->id, v16 = v4->md->player->id, v16 < v15) && v15 != BYTE1(v6[1].game_speed)
              || v16 == BYTE1(v6[1].game_speed) )
            {
              v14->sendAICommand(v13, v16, 2, playerToAttack, x, y);
            }
          }
          v12 = tempRanda;
        }
      }
    }
  }
}

//----- (00502F30) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::processCoopAttack(TribeTacticalAIModule *this, int caller, int playerToAttack, int x, int y)
{
  TribeTacticalAIModule *v5; // edi@1
  int result; // eax@2
  TacticalAIGroup *v7; // esi@3
  int i; // edi@3
  int v9; // ebx@7
  int v10; // eax@8

  v5 = this;
  if ( this->attackEnabledValue )
  {
    DiplomacyAIModule::setStance(&this->md->diplomacyAI, playerToAttack, 0, 100);
    v7 = v5->groups.next;
    for ( i = (int)&v5->groups; v7 != (TacticalAIGroup *)i; v7 = v7->next )
    {
      if ( !v7 )
        break;
      if ( TacticalAIGroup::type(v7) == 100 || TacticalAIGroup::type(v7) == 103 )
      {
        v9 = TacticalAIGroup::numberUnits(v7);
        if ( TacticalAIGroup::desiredNumberUnits(v7) > v9 )
        {
          v10 = TacticalAIGroup::numberUnits(v7);
          TacticalAIGroup::setDesiredNumberUnits(v7, v10);
        }
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00502FC0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::resourceDifference(TribeTacticalAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n > 3 )
    result = -1;
  else
    result = this->resourceDifferenceValue[this->neededResourceValue[n]];
  return result;
}

//----- (00502FF0) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::actualGathererCount(TribeTacticalAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n > 3 )
    result = -1;
  else
    result = this->actualGathererDistribution[this->neededResourceValue[n]];
  return result;
}

//----- (00503020) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::actualGathererCountByRealResourceID(TribeTacticalAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n > 3 )
    result = -1;
  else
    result = this->actualGathererDistribution[n];
  return result;
}

//----- (00503040) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::desiredGathererCount(TribeTacticalAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n > 3 )
    result = -1;
  else
    result = this->desiredGathererDistribution[this->neededResourceValue[n]];
  return result;
}

//----- (00503070) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::taskElephantGatherers(TribeTacticalAIModule *this, int mainHunterID, int numberToTask, int targetID)
{
  TribeTacticalAIModule *v4; // edi@1
  int v5; // ecx@2
  int v6; // esi@3
  int v7; // ebp@4
  int v8; // ebx@4
  int v9; // edi@5
  int v10; // eax@6
  int *v11; // edx@7
  RGE_Static_Object *v12; // eax@11
  RGE_Static_Object *v13; // esi@11
  long double v14; // st7@14
  int v15; // eax@21
  int *v16; // edx@22
  int v17; // edi@27
  int *v18; // esi@27
  int i; // eax@28
  int *v20; // eax@35
  TribeTacticalAIModule *v21; // [sp+14h] [bp-2Ch]@1
  signed int bestValueID; // [sp+18h] [bp-28h]@4
  RGE_Static_Object *targetObject; // [sp+1Ch] [bp-24h]@1
  int count; // [sp+20h] [bp-20h]@2
  ManagedArray<int> alreadyTasked; // [sp+24h] [bp-1Ch]@2
  int v26; // [sp+3Ch] [bp-4h]@2
  float mainHunterIDa; // [sp+44h] [bp+4h]@4

  v4 = this;
  v21 = this;
  targetObject = MainDecisionAIModule::object((MainDecisionAIModule *)&this->md->vfptr, targetID);
  if ( targetObject )
  {
    alreadyTasked.value = 0;
    alreadyTasked.numberValue = 0;
    alreadyTasked.desiredNumberValue = 0;
    alreadyTasked.maximumSizeValue = 0;
    v26 = 0;
    ManagedArray<int>::resize(&alreadyTasked, 1);
    count = 0;
    alreadyTasked.value[alreadyTasked.numberValue] = mainHunterID;
    v5 = alreadyTasked.numberValue++ + 1;
    if ( numberToTask <= 0 )
    {
LABEL_35:
      v20 = alreadyTasked.value;
      v26 = -1;
      if ( !alreadyTasked.value )
        return;
      goto LABEL_36;
    }
    v6 = alreadyTasked.maximumSizeValue;
    while ( 1 )
    {
      v7 = -1;
      v8 = 0;
      mainHunterIDa = -1.0;
      bestValueID = -1;
      if ( v4->numberGatherersValue > 0 )
      {
        v9 = (int)v4->gatherers;
        do
        {
          v10 = 0;
          if ( v5 > 0 )
          {
            v11 = alreadyTasked.value;
            do
            {
              if ( v10 >= v6 )
                break;
              if ( *v11 == *(_DWORD *)v9 )
                goto LABEL_18;
              ++v10;
              ++v11;
            }
            while ( v10 < v5 );
          }
          v12 = MainDecisionAIModule::object((MainDecisionAIModule *)&v21->md->vfptr, *(_DWORD *)v9);
          v13 = v12;
          if ( v12 )
          {
            if ( RGE_Static_Object::unitAI(v12) )
            {
              if ( !*(_DWORD *)(v9 + 4) )
              {
                v14 = RGE_Static_Object::distance_to_object(v13, targetObject);
                if ( mainHunterIDa == -1.0 || mainHunterIDa > v14 )
                {
                  mainHunterIDa = v14;
                  bestValueID = *(_DWORD *)v9;
                }
              }
            }
          }
          v5 = alreadyTasked.numberValue;
          v6 = alreadyTasked.maximumSizeValue;
LABEL_18:
          ++v8;
          v9 += 24;
        }
        while ( v8 < v21->numberGatherersValue );
        v7 = bestValueID;
        v4 = v21;
      }
      if ( v7 == -1 )
        break;
      ((void (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD))v4->md->aiPlayer->vfptr[1].loadAIInformation)(
        v7,
        targetID,
        0,
        LODWORD(targetObject->world_x),
        LODWORD(targetObject->world_y));
      v5 = alreadyTasked.numberValue;
      v6 = alreadyTasked.maximumSizeValue;
      v15 = 0;
      if ( alreadyTasked.numberValue > 0 )
      {
        v16 = alreadyTasked.value;
        do
        {
          if ( v15 >= alreadyTasked.maximumSizeValue )
            break;
          if ( *v16 == v7 )
            goto LABEL_34;
          ++v15;
          ++v16;
        }
        while ( v15 < alreadyTasked.numberValue );
      }
      if ( alreadyTasked.numberValue > alreadyTasked.maximumSizeValue - 1 )
      {
        v17 = alreadyTasked.numberValue + 1;
        v18 = (int *)operator new(4 * (alreadyTasked.numberValue + 1));
        if ( v18 )
        {
          for ( i = 0; i < alreadyTasked.maximumSizeValue; v18[i - 1] = alreadyTasked.value[i - 1] )
          {
            if ( i >= v17 )
              break;
            ++i;
          }
          operator delete(alreadyTasked.value);
          alreadyTasked.value = v18;
          alreadyTasked.maximumSizeValue = v17;
        }
        v5 = alreadyTasked.numberValue;
        v4 = v21;
      }
      alreadyTasked.value[v5] = v7;
      v6 = alreadyTasked.maximumSizeValue;
      v5 = alreadyTasked.numberValue++ + 1;
LABEL_34:
      if ( ++count >= numberToTask )
        goto LABEL_35;
    }
    v20 = alreadyTasked.value;
    v26 = -1;
    if ( alreadyTasked.value )
    {
LABEL_36:
      operator delete(v20);
      return;
    }
  }
}

//----- (005032E0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkTradeBoats(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // esi@1
  int v2; // ebp@1
  int v3; // ebx@3
  int *v4; // edi@3
  int j; // eax@4
  RGE_Static_Object *v6; // eax@8
  int v7; // edi@9
  int v8; // ebp@10
  int v9; // eax@15
  int v10; // ebx@16
  int *v11; // edi@16
  int k; // eax@17
  int i; // [sp+8h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->tradeBoats.numberValue; i = v2 )
  {
    if ( v2 > v1->tradeBoats.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->tradeBoats.maximumSizeValue; v4[j - 1] = v1->tradeBoats.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->tradeBoats.value);
        v1->tradeBoats.value = v4;
        v1->tradeBoats.maximumSizeValue = v3;
      }
    }
    v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->md->vfptr, v1->tradeBoats.value[v2]);
    if ( v6 )
    {
      v7 = v6->attribute_type_held;
      if ( TribeResourceAIModule::resource(&v1->md->resourceAI, v7) < v1->sn[216] )
      {
        v8 = 2;
        while ( v8 == v7 || TribeResourceAIModule::resource(&v1->md->resourceAI, v8) < v1->sn[216] )
        {
          if ( --v8 < 0 )
            goto LABEL_23;
        }
        v9 = i;
        if ( i > v1->tradeBoats.maximumSizeValue - 1 )
        {
          v10 = i + 1;
          v11 = (int *)operator new(4 * i + 4);
          if ( v11 )
          {
            for ( k = 0; k < v1->tradeBoats.maximumSizeValue; v11[k - 1] = v1->tradeBoats.value[k - 1] )
            {
              if ( k >= v10 )
                break;
              ++k;
            }
            operator delete(v1->tradeBoats.value);
            v1->tradeBoats.value = v11;
            v1->tradeBoats.maximumSizeValue = v10;
          }
          v9 = i;
        }
        TRIBE_Player::command_trade_attribute(v1->md->aiPlayer, v1->tradeBoats.value[v9], v8);
LABEL_23:
        v2 = i;
      }
    }
    ++v2;
  }
}

//----- (00503480) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberGatherersWithTarget(TribeTacticalAIModule *this, int targetID)
{
  int v2; // edx@1
  int result; // eax@1
  char *v4; // ecx@2

  v2 = this->numberGatherersValue;
  result = 0;
  if ( v2 > 0 )
  {
    v4 = (char *)&this->gatherers[0].target;
    do
    {
      if ( *(_DWORD *)v4 == targetID )
        ++result;
      v4 += 24;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

//----- (005034B0) --------------------------------------------------------
void __thiscall TribeTacticalAIModule::checkStaleAttackGroups(TribeTacticalAIModule *this)
{
  TribeTacticalAIModule *v1; // ebx@1
  TacticalAIGroup *v2; // esi@2
  char *v3; // ebp@2
  int v4; // ST14_4@6
  int v5; // edi@6
  signed __int64 v6; // rax@9
  int v7; // eax@10

  v1 = this;
  if ( this->attackEnabledValue )
  {
    v2 = this->groups.next;
    v3 = (char *)&this->groups;
    if ( v2 != &this->groups )
    {
      do
      {
        if ( !v2 )
          break;
        if ( TacticalAIGroup::type(v2) == 100 && TacticalAIGroup::inUse(v2) != 1 )
        {
          v4 = TacticalAIGroup::numberUnits(v2);
          v5 = TacticalAIGroup::desiredNumberUnits(v2) - v4;
          if ( v5 > 0 )
          {
            if ( v5 > 5 )
              v5 = 5;
            v6 = 1172812403i64 * (v1->md->player->world->world_time - v2->lastAddedUnitTimeValue);
            if ( (signed int)((HIDWORD(v6) >> 31) + (SHIDWORD(v6) >> 14)) >= v5 )
            {
              v7 = TacticalAIGroup::numberUnits(v2);
              TacticalAIGroup::setDesiredNumberUnits(v2, v7);
            }
          }
        }
        v2 = v2->next;
      }
      while ( (char *)v2 != v3 );
    }
  }
}

//----- (00503580) --------------------------------------------------------
int __thiscall TribeTacticalAIModule::numberWaterExplorers(TribeTacticalAIModule *this)
{
  TacticalAIGroup *v1; // esi@1
  char *v2; // edi@1
  int v3; // ebx@1

  v1 = this->groups.next;
  v2 = (char *)&this->groups;
  v3 = 0;
  if ( v1 != &this->groups )
  {
    do
    {
      if ( !v1 )
        break;
      if ( (TacticalAIGroup::type(v1) == 103
         || TacticalAIGroup::type(v1) == 104
         || TacticalAIGroup::type(v1) == 105
         || TacticalAIGroup::type(v1) == 106
         || TacticalAIGroup::type(v1) == 107
         || TacticalAIGroup::type(v1) == 108)
        && TacticalAIGroup::action(v1) == 8 )
      {
        ++v3;
      }
      v1 = v1->next;
    }
    while ( (char *)v1 != v2 );
  }
  return v3;
}

//----- (00503600) --------------------------------------------------------
void __userpurge TribeTacticalAIModule::saveTheTown(TribeTacticalAIModule *this@<ecx>, int idToKill, int a3, signed int a4, char *a5)
{
  TribeTacticalAIModule *v5; // esi@1
  unsigned int v6; // eax@1
  MainDecisionAIModule *v7; // ecx@1
  RGE_Static_Object *v8; // eax@1
  RGE_Static_Object *v9; // edi@1
  int v10; // edx@2
  TacticalAIGroup *v11; // ebx@2
  int v12; // eax@4
  int *v13; // ebp@4
  double v14; // st7@5
  signed __int64 v15; // rax@5
  double v16; // st7@5
  int v17; // eax@7
  int v18; // ebx@7
  int v19; // ebp@14
  int *v20; // ebx@14
  int j; // eax@15
  RGE_Static_Object *v22; // eax@20
  RGE_Static_Object *v23; // ebx@20
  UnitAIModule *v24; // eax@22
  UnitAIModule *v25; // eax@23
  UnitAIModule *v26; // eax@24
  UnitAIModule *v27; // eax@25
  int v28; // eax@25
  TribeMainDecisionAIModule *v29; // edx@25
  int *v30; // ebp@27
  signed int k; // eax@28
  double v32; // st7@34
  signed __int64 v33; // rax@34
  double v34; // st7@34
  int v35; // ecx@34
  RGE_Static_ObjectVtbl *v36; // ebp@34
  int v37; // eax@35
  int v38; // ebp@36
  int *v39; // ebx@36
  int l; // eax@37
  RGE_Player *v41; // ecx@42
  int v42; // edx@42
  int v43; // ecx@42
  int v44; // ecx@44
  int m; // ebp@45
  RGE_Static_Object *v46; // ebx@47
  double v47; // st7@48
  signed __int64 v48; // rax@48
  double v49; // st7@48
  RGE_Player *v50; // eax@49
  int v51; // ecx@49
  float v52; // eax@49
  int v53; // [sp+2Ch] [bp-44h]@34
  signed int v54; // [sp+30h] [bp-40h]@5
  char *v55; // [sp+34h] [bp-3Ch]@1
  signed int v56; // [sp+38h] [bp-38h]@1
  int i; // [sp+4Ch] [bp-24h]@7
  int count; // [sp+50h] [bp-20h]@5
  unsigned int entryTime; // [sp+54h] [bp-1Ch]@1
  RGE_Static_Object *targetObj; // [sp+58h] [bp-18h]@25
  XYPoint objPosition; // [sp+5Ch] [bp-14h]@2
  XYZPoint point; // [sp+64h] [bp-Ch]@5

  v56 = 13344;
  v5 = this;
  v55 = aCMsdevWorkA_61;
  v6 = debug_timeGetTime();
  v7 = (MainDecisionAIModule *)&v5->md->vfptr;
  entryTime = v6;
  v8 = MainDecisionAIModule::object(v7, idToKill);
  v9 = v8;
  if ( v8 )
  {
    objPosition.x = (signed __int64)v8->world_x;
    v10 = v5->sn[20];
    objPosition.y = (signed __int64)v8->world_y;
    v11 = TribeTacticalAIModule::readyAndIdleGroup(v5, 100, v10, &objPosition);
    if ( v11 || (v11 = TribeTacticalAIModule::readyAndIdleGroup(v5, 103, v5->sn[20], &objPosition)) != 0 )
    {
      v12 = TacticalAIGroup::commander(v11);
      v13 = (int *)RGE_Game_World::object(v5->md->player->world, v12);
      if ( v13 )
      {
        v14 = v9->world_y;
        point.x = (signed __int64)v9->world_x;
        v15 = (signed __int64)v14;
        v16 = v9->world_z;
        point.y = v15;
        *(float *)&v56 = -6.8056469e38/*NaN*/;
        v55 = (char *)-1;
        v54 = 1;
        point.z = (signed __int64)v16;
        count = *v13;
        (*(void (__fastcall **)(int *, _DWORD, int, _DWORD, signed int, signed int, signed int))(count + 268))(
          v13,
          (unsigned __int64)(signed __int64)v16 >> 32,
          idToKill,
          0,
          1,
          -1,
          -1);
        *(float *)&v56 = v16;
        if ( (*(int (__thiscall **)(int *, int, signed int, char *, signed int))(point.x + 408))(v13, a3, a4, a5, v56) == 1 )
        {
          TacticalAIGroup::setTarget(v11, idToKill);
          TacticalAIGroup::setTargetType(v11, v9->master_obj->id);
          TacticalAIGroup::setTargetLocation(v11, v9->world_x, v9->world_y, v9->world_z);
          TacticalAIGroup::setAction(v11, 2);
          TacticalAIGroup::task(v11, v5, v5->md, 2, 1, 0);
          return;
        }
      }
    }
    v17 = v5->soldiers.numberValue;
    v18 = 0;
    count = 0;
    i = 0;
    if ( v17 > 0 )
    {
      while ( 1 )
      {
        if ( count >= 6 )
          break;
        if ( v18 > 1 )
        {
          v56 = 13383;
          v55 = aCMsdevWorkA_61;
          if ( debug_timeGetTime() - entryTime > 0xA )
            return;
        }
        if ( v18 > v5->soldiers.maximumSizeValue - 1 )
        {
          v19 = v18 + 1;
          v20 = (int *)operator new(4 * v18 + 4);
          if ( v20 )
          {
            for ( j = 0; j < v5->soldiers.maximumSizeValue; v20[j - 1] = v5->soldiers.value[j - 1] )
            {
              if ( j >= v19 )
                break;
              ++j;
            }
            operator delete(v5->soldiers.value);
            v5->soldiers.value = v20;
            v5->soldiers.maximumSizeValue = v19;
          }
          v18 = i;
        }
        v22 = RGE_Game_World::object(v5->md->aiPlayer->world, v5->soldiers.value[v18]);
        v23 = v22;
        if ( v22 && RGE_Static_Object::unitAI(v22) )
        {
          v24 = RGE_Static_Object::unitAI(v23);
          if ( UnitAIModule::currentAction(v24) != 600 )
            goto LABEL_52;
          v25 = RGE_Static_Object::unitAI(v23);
          if ( UnitAIModule::currentTarget(v25) == -1 )
            goto LABEL_52;
          v26 = RGE_Static_Object::unitAI(v23);
          if ( UnitAIModule::currentTarget(v26) == v9->id )
            goto LABEL_43;
          v27 = RGE_Static_Object::unitAI(v23);
          *(float *)&v28 = COERCE_FLOAT(UnitAIModule::currentTarget(v27));
          v29 = v5->md;
          v56 = v28;
          targetObj = RGE_Game_World::object(v29->player->world, v28);
          if ( !targetObj )
            goto LABEL_52;
          if ( v5->playersToAttack.maximumSizeValue - 1 < 0 )
          {
            v30 = (int *)operator new(4u);
            if ( v30 )
            {
              for ( k = 0; k < v5->playersToAttack.maximumSizeValue; v30[k - 1] = v5->playersToAttack.value[k - 1] )
              {
                if ( k >= 1 )
                  break;
                ++k;
              }
              operator delete(v5->playersToAttack.value);
              v5->playersToAttack.value = v30;
              v5->playersToAttack.maximumSizeValue = 1;
            }
          }
          if ( targetObj->owner->id != *v5->playersToAttack.value )
          {
LABEL_52:
            if ( RGE_Static_Object::distance_to_object(v23, v9) < 25.0 )
            {
              v32 = v9->world_y;
              point.x = (signed __int64)v9->world_x;
              v33 = (signed __int64)v32;
              v34 = v9->world_z;
              point.y = v33;
              v35 = v9->id;
              v36 = v23->vfptr;
              *(float *)&v56 = -6.8056469e38/*NaN*/;
              v55 = (char *)-1;
              v54 = 1;
              v53 = 0;
              point.z = (signed __int64)v34;
              ((void (__fastcall *)(RGE_Static_Object *, _DWORD, int, _DWORD, signed int, signed int, signed int))v36->weaponRange)(
                v23,
                (unsigned __int64)(signed __int64)v34 >> 32,
                v35,
                0,
                1,
                -1,
                -1);
              *(float *)&v56 = v34;
              v53 = a3;
              v54 = a4;
              v55 = a5;
              if ( ((int (__thiscall *)(RGE_Static_Object *, int, signed int, char *, signed int))v36->canPath)(
                     v23,
                     a3,
                     a4,
                     a5,
                     v56) )
              {
                v37 = i;
                if ( i > v5->soldiers.maximumSizeValue - 1 )
                {
                  v38 = i + 1;
                  v39 = (int *)operator new(4 * i + 4);
                  if ( v39 )
                  {
                    for ( l = 0; l < v5->soldiers.maximumSizeValue; v39[l - 1] = v5->soldiers.value[l - 1] )
                    {
                      if ( l >= v38 )
                        break;
                      ++l;
                    }
                    operator delete(v5->soldiers.value);
                    v5->soldiers.value = v39;
                    v5->soldiers.maximumSizeValue = v38;
                  }
                  v37 = i;
                }
                v41 = v9->owner;
                *(float *)&v56 = 0.0;
                v55 = (char *)-1;
                v54 = 0;
                v42 = v41->id;
                v43 = v9->id;
                v53 = 0;
                if ( TribeTacticalAIModule::taskAttacker(
                       v5,
                       v5->soldiers.value[v37],
                       v9->world_x,
                       v9->world_y,
                       v43,
                       v42,
                       0,
                       0,
                       -1,
                       0) == 1 )
                {
LABEL_43:
                  ++count;
                  goto LABEL_44;
                }
              }
            }
          }
        }
LABEL_44:
        v44 = v5->soldiers.numberValue;
        if ( ++i >= v44 )
          break;
        v18 = i;
      }
    }
    for ( m = TribeTacticalAIModule::civilian(v5, &objPosition, 1, 700, -1000, -1000, 1);
          m != -1;
          m = TribeTacticalAIModule::civilian(v5, &objPosition, 1, 700, 713, 713, 1) )
    {
      if ( count >= 6 )
        break;
      v46 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, m);
      if ( !v46 )
        break;
      v47 = v9->world_y;
      point.x = (signed __int64)v9->world_x;
      v48 = (signed __int64)v47;
      v49 = v9->world_z;
      point.y = v48;
      *(float *)&v56 = -6.8056469e38/*NaN*/;
      v55 = (char *)-1;
      point.z = (signed __int64)v49;
      LODWORD(v48) = v46->vfptr;
      v54 = 1;
      v53 = 0;
      targetObj = (RGE_Static_Object *)v48;
      (*(void (__thiscall **)(RGE_Static_Object *, int, _DWORD, signed int, signed int, signed int))(v48 + 268))(
        v46,
        idToKill,
        0,
        1,
        -1,
        -1);
      *(float *)&v56 = v49;
      v53 = a3;
      v54 = a4;
      v55 = a5;
      if ( !(*(int (__thiscall **)(RGE_Static_Object *, int, signed int, char *, signed int))(point.z + 408))(
              v46,
              a3,
              a4,
              a5,
              v56) )
        break;
      v50 = v9->owner;
      *(float *)&v56 = 0.0;
      v55 = (char *)-1;
      v51 = v50->id;
      v52 = v9->world_y;
      v54 = 0;
      v53 = 0;
      TribeTacticalAIModule::taskAttacker(v5, m, v9->world_x, v52, idToKill, v51, 0, 0, -1, 0);
      ++count;
    }
  }
}
