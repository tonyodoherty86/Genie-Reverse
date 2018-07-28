
/**
 * @file    Engine\RGE\AiPlay.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (0040E930) --------------------------------------------------------
void __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(AIPlayPhaseCommand *this)
{
  this->groupValue = 0;
  this->typeValue = 0;
  this->value1Value = 0;
  this->value2Value = 0;
  this->value3Value = 0;
}

//----- (0040E950) --------------------------------------------------------
void __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(AIPlayPhaseCommand *this, char g, char t, int v1, int v2, int v3)
{
  this->groupValue = g;
  this->typeValue = t;
  this->value1Value = v1;
  this->value2Value = v2;
  this->value3Value = v3;
}

//----- (0040E980) --------------------------------------------------------
void __thiscall AIPlayPhaseCommand::AIPlayPhaseCommand(AIPlayPhaseCommand *this, char g, char *t, int v1, int v2, int v3)
{
  AIPlayPhaseCommand *v6; // esi@1

  v6 = this;
  this->groupValue = g;
  this->typeValue = AIPlayPhaseCommand::convertToIntType(t);
  v6->value2Value = v2;
  v6->value1Value = v1;
  v6->value3Value = v3;
}

//----- (0040E9C0) --------------------------------------------------------
char *__thiscall AIPlayPhaseCommand::nameType(AIPlayPhaseCommand *this)
{
  return AIPlayPhaseCommand::convertToNameType(this->typeValue);
}

//----- (0040E9D0) --------------------------------------------------------
signed int __stdcall AIPlayPhaseCommand::convertToIntType(char *t)
{
  signed int result; // eax@2

  if( !strcmp(t, aMove) )
  {
    result = 1;
  }
  else if( !strcmp(t, aAttack) )
  {
    result = 2;
  }
  else if( !strcmp(t, aAttacksavedtar) )
  {
    result = 3;
  }
  else if( !strcmp(t, aRetreat) )
  {
    result = 4;
  }
  else if( !strcmp(t, aHeal) )
  {
    result = 5;
  }
  else if( !strcmp(t, aResethitpoints) )
  {
    result = 6;
  }
  else if( !strcmp(t, aResetalivecoun) )
  {
    result = 7;
  }
  else if( !strcmp(t, aWait) )
  {
    result = 8;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040EBF0) --------------------------------------------------------
char *__stdcall AIPlayPhaseCommand::convertToNameType(char t)
{
  char *result; // eax@2

  switch ( t )
  {
    case 1:
      result = aMove;
      break;
    case 2:
      result = aAttack;
      break;
    case 3:
      result = aAttacksavedtar;
      break;
    case 4:
      result = aRetreat;
      break;
    case 5:
      result = aHeal;
      break;
    case 6:
      result = aResethitpoints;
      break;
    case 7:
      result = aResetalivecoun;
      break;
    case 8:
      result = aWait;
      break;
    default:
      result = aInvalid;
      break;
  }
  return result;
}

//----- (0040EC70) --------------------------------------------------------
void __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(AIPlayPhaseTrigger *this)
{
  this->typeValue = 0;
  this->value1Value = -1;
  this->value2Value = -1;
  this->phaseValue = 0;
  this->nextPhaseValue = 0;
}

//----- (0040EC90) --------------------------------------------------------
void __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(AIPlayPhaseTrigger *this, char t, int v1, int v2, char p, char n, int r)
{
  this->typeValue = t;
  this->value1Value = v1;
  this->value2Value = v2;
  this->phaseValue = p;
  this->nextPhaseValue = n;
  this->randomnessValue = r;
}

//----- (0040ECC0) --------------------------------------------------------
void __thiscall AIPlayPhaseTrigger::AIPlayPhaseTrigger(AIPlayPhaseTrigger *this, char *t, int v1, int v2, char p, char n, int r)
{
  AIPlayPhaseTrigger *v7; // esi@1

  v7 = this;
  this->typeValue = AIPlayPhaseTrigger::convertToIntType(t);
  v7->value1Value = v1;
  v7->value2Value = v2;
  v7->phaseValue = p;
  v7->nextPhaseValue = n;
  v7->randomnessValue = r;
}

//----- (0040ED00) --------------------------------------------------------
char *__thiscall AIPlayPhaseTrigger::nameType(AIPlayPhaseTrigger *this)
{
  return AIPlayPhaseTrigger::convertToNameType(this->typeValue);
}

//----- (0040ED10) --------------------------------------------------------
signed int __stdcall AIPlayPhaseTrigger::convertToIntType(char *t)
{
  signed int result; // eax@2

  if( !strcmp(t, aGather) )
  {
    result = 1;
  }
  else if( !strcmp(t, aDeath) )
  {
    result = 2;
  }
  else if( !strcmp(t, aHealthlost) )
  {
    result = 3;
  }
  else if( !strcmp(t, aDamagetogroup) )
  {
    result = 4;
  }
  else if( !strcmp(t, aDamagetoanygro) )
  {
    result = 5;
  }
  else if( !strcmp(t, aLevel1enemysig) )
  {
    result = 6;
  }
  else if( !strcmp(t, aLevel2enemysig) )
  {
    result = 7;
  }
  else if( !strcmp(t, aDeathofgroup) )
  {
    result = 8;
  }
  else if( !strcmp(t, aHealofgroup) )
  {
    result = 9;
  }
  else if( !strcmp(t, aImmediate) )
  {
    result = 10;
  }
  else if( !strcmp(t, aTime) )
  {
    result = 11;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040EFF0) --------------------------------------------------------
char *__stdcall AIPlayPhaseTrigger::convertToNameType(char t)
{
  char *result; // eax@2

  switch ( t )
  {
    case 1:
      result = aGather;
      break;
    case 2:
      result = aDeath;
      break;
    case 3:
      result = aHealthlost;
      break;
    case 4:
      result = aDamagetogroup;
      break;
    case 5:
      result = aDamagetoanygro;
      break;
    case 6:
      result = aLevel1enemysig;
      break;
    case 7:
      result = aLevel2enemysig;
      break;
    case 8:
      result = aDeathofgroup;
      break;
    case 9:
      result = aHealofgroup;
      break;
    case 0xA:
      result = aImmediate;
      break;
    case 0xB:
      result = aTime;
      break;
    default:
      result = aInvalid;
      break;
  }
  return result;
}

//----- (0040F0A0) --------------------------------------------------------
void __thiscall AIPlayPhase::AIPlayPhase(AIPlayPhase *this)
{
  AIPlayPhase *v1; // ebx@1
  AIPlayPhase *v2; // esi@1
  signed int v3; // edi@1
  AIPlayPhaseTrigger *v4; // esi@3
  signed int v5; // edi@3

  v1 = this;
  v2 = this;
  v3 = 5;
  do
  {
    AIPlayPhaseCommand::AIPlayPhaseCommand(v2->commands);
    v2 = (AIPlayPhase *)((char *)v2 + 16);
    --v3;
  }
  while( v3 );
  v4 = v1->triggers;
  v5 = 3;
  do
  {
    AIPlayPhaseTrigger::AIPlayPhaseTrigger(v4);
    ++v4;
    --v5;
  }
  while( v5 );
  AIPlayPhase::initialize(v1);
}

//----- (0040F0E0) --------------------------------------------------------
void __stdcall `vector constructor iterator'(void *__t, unsigned int __s, int __n, void (__thiscall *__f)(void *))
{
  char *v4; // esi@2
  int v5; // edi@2

  if( __n - 1 >= 0 )
  {
    v4 = (char *)__t;
    v5 = __n;
    do
    {
      __f(v4);
      v4 += __s;
      --v5;
    }
    while( v5 );
  }
}

//----- (0040F110) --------------------------------------------------------
AIPlayPhaseCommand *__thiscall AIPlayPhase::command(AIPlayPhase *this, int v)
{
  AIPlayPhaseCommand *result; // eax@3

  if( v < 0 || v >= 5 )
    result = 0;
  else
    result = &this->commands[v];
  return result;
}

//----- (0040F130) --------------------------------------------------------
AIPlayPhase *__thiscall AIPlayPhase::trigger(AIPlayPhase *this, int v)
{
  AIPlayPhase *result; // eax@3

  if( v < 0 || v >= 3 )
    result = 0;
  else
    result = (AIPlayPhase *)((char *)this + 20 * (v + 4));
  return result;
}

//----- (0040F150) --------------------------------------------------------
int __thiscall AIPlayPhase::addCommand(AIPlayPhase *this, AIPlayPhaseCommand *c)
{
  signed int v2; // eax@1
  char *v3; // edx@1
  char *v5; // eax@5

  v2 = 0;
  v3 = &this->commands[0].typeValue;
  while( *v3 )
  {
    ++v2;
    v3 += 16;
    if( v2 >= 5 )
      return 0;
  }
  v5 = (char *)this + 16 * v2;
  *v5 = c->groupValue;
  v5[1] = c->typeValue;
  *((_DWORD *)v5 + 1) = c->value1Value;
  *((_DWORD *)v5 + 2) = c->value2Value;
  *((_DWORD *)v5 + 3) = c->value3Value;
  return 1;
}

//----- (0040F1A0) --------------------------------------------------------
int __thiscall AIPlayPhase::addTrigger(AIPlayPhase *this, AIPlayPhaseTrigger *t)
{
  AIPlayPhase *v2; // esi@1
  signed int v3; // eax@1
  char *v4; // edx@1
  int v6; // ecx@5
  int v7; // eax@5

  v2 = this;
  v3 = 0;
  v4 = (char *)this->triggers;
  while( *v4 )
  {
    ++v3;
    v4 += 20;
    if( v3 >= 3 )
      return 0;
  }
  v6 = 5 * (v3 + 4);
  v7 = (int)v2 + 20 * v3;
  *(&v2->commands[0].groupValue + 4 * v6) = t->typeValue;
  *(_DWORD *)(v7 + 84) = t->value1Value;
  *(_DWORD *)(v7 + 88) = t->value2Value;
  *(_BYTE *)(v7 + 92) = t->phaseValue;
  *(_BYTE *)(v7 + 93) = t->nextPhaseValue;
  *(_DWORD *)(v7 + 96) = t->randomnessValue;
  return 1;
}

//----- (0040F200) --------------------------------------------------------
void __thiscall AIPlayPhase::initialize(AIPlayPhase *this)
{
  char *v1; // eax@1
  signed int v2; // edx@1
  char *v3; // eax@3
  signed int v4; // ecx@3

  v1 = &this->commands[0].typeValue;
  v2 = 5;
  do
  {
    *v1 = 0;
    v1 += 16;
    --v2;
  }
  while( v2 );
  v3 = (char *)this->triggers;
  v4 = 3;
  do
  {
    *v3 = 0;
    v3 += 20;
    --v4;
  }
  while( v4 );
}

//----- (0040F230) --------------------------------------------------------
void __thiscall AIPlayGroup::AIPlayGroup(AIPlayGroup *this)
{
  AIPlayGroup::initialize(this);
}

//----- (0040F240) --------------------------------------------------------
char __thiscall AIPlayGroup::minimum(AIPlayGroup *this, int n)
{
  char result; // al@3

  if( n < 0 || n >= 6 )
    result = 0;
  else
    result = this->minValue[n];
  return result;
}

//----- (0040F260) --------------------------------------------------------
void __thiscall AIPlayGroup::setMinimum(AIPlayGroup *this, int n, int v)
{
  if( n >= 0 && n < 6 )
    this->minValue[n] = v;
}

//----- (0040F280) --------------------------------------------------------
char __thiscall AIPlayGroup::maximum(AIPlayGroup *this, int n)
{
  char result; // al@3

  if( n < 0 || n >= 6 )
    result = -1;
  else
    result = this->maxValue[n];
  return result;
}

//----- (0040F2A0) --------------------------------------------------------
void __thiscall AIPlayGroup::setMaximum(AIPlayGroup *this, int n, int v)
{
  if( n >= 0 && n < 6 )
    this->maxValue[n] = v;
}

//----- (0040F2C0) --------------------------------------------------------
void __thiscall AIPlayGroup::initialize(AIPlayGroup *this)
{
  char *v1; // eax@1

  v1 = this->maxValue;
  do
  {
    *(v1 - 6) = 0;
    *v1++ = -2;
  }
  while( (signed int)&v1[-6 - (_DWORD)this] < 6 );
}

//----- (0040F2E0) --------------------------------------------------------
void __thiscall AIPlay::AIPlay(AIPlay *this)
{
  AIPlay *v1; // esi@1
  AIPlayGroup *v2; // edi@1
  signed int v3; // ebp@1
  AIPlayPhase *v4; // edi@3
  signed int v5; // ebp@3
  char *v6; // eax@5

  v1 = this;
  this->minimumNumberUnitsValue = 1;
  this->typeValue = 1;
  this->overflowValue = 1;
  this->maximumNumberUnitsValue = -1;
  this->powerValue = 0;
  this->intelligenceValue = 50;
  this->deathPercentageValue = 50;
  v2 = this->groups;
  v3 = 5;
  do
  {
    AIPlayGroup::AIPlayGroup(v2);
    ++v2;
    --v3;
  }
  while( v3 );
  v4 = v1->phases;
  v5 = 10;
  do
  {
    AIPlayPhase::AIPlayPhase(v4);
    ++v4;
    --v5;
  }
  while( v5 );
  v6 = v1->targetCharacteristicValue;
  do
  {
    *(v6 - 5) = 5;
    *v6++ = 5;
  }
  while( (signed int)&v6[-73 - (_DWORD)v1] < 5 );
}

//----- (0040F360) --------------------------------------------------------
void __thiscall AIPlay::setName(AIPlay *this, char *n)
{
  if( n )
    strncpy(this->nameValue, n, 0x40u);
}

//----- (0040F380) --------------------------------------------------------
BOOL __thiscall AIPlay::humanPlay(AIPlay *this)
{
  return this->nameValue[0] == 72 && this->nameValue[1] == 80;
}

//----- (0040F3A0) --------------------------------------------------------
char *__thiscall AIPlay::typeName(AIPlay *this)
{
  return AIPlay::convertToNameType(this->typeValue);
}

//----- (0040F3B0) --------------------------------------------------------
char __thiscall AIPlay::targetType(AIPlay *this, int n)
{
  char result; // al@3

  if( n < 0 || n >= 5 )
    result = 0;
  else
    result = this->targetTypeValue[n];
  return result;
}

//----- (0040F3D0) --------------------------------------------------------
int __thiscall AIPlay::isTargetType(AIPlay *this, char v)
{
  int v2; // eax@1

  v2 = 0;
  while( this->targetTypeValue[v2] != v )
  {
    if( ++v2 >= 5 )
      return 0;
  }
  return 1;
}

//----- (0040F3F0) --------------------------------------------------------
int __thiscall AIPlay::addTargetType(AIPlay *this, char v)
{
  int v2; // edx@1
  char v3; // al@2

  v2 = 0;
  while( 1 )
  {
    v3 = this->targetTypeValue[v2];
    if( !v3 || v3 == 5 )
      break;
    if( ++v2 >= 5 )
      return 0;
  }
  this->targetTypeValue[v2] = v;
  return 1;
}

//----- (0040F420) --------------------------------------------------------
char __thiscall AIPlay::targetCharacteristic(AIPlay *this, int n)
{
  char result; // al@3

  if( n < 0 || n >= 5 )
    result = 0;
  else
    result = this->targetCharacteristicValue[n];
  return result;
}

//----- (0040F440) --------------------------------------------------------
int __thiscall AIPlay::isTargetCharacteristic(AIPlay *this, char v)
{
  int v2; // eax@1

  v2 = 0;
  while( this->targetCharacteristicValue[v2] != v )
  {
    if( ++v2 >= 5 )
      return 0;
  }
  return 1;
}

//----- (0040F460) --------------------------------------------------------
int __thiscall AIPlay::addTargetCharacteristic(AIPlay *this, char v)
{
  int v2; // edx@1
  char v3; // al@2

  v2 = 0;
  while( 1 )
  {
    v3 = this->targetCharacteristicValue[v2];
    if( !v3 || v3 == 5 )
      break;
    if( ++v2 >= 5 )
      return 0;
  }
  this->targetCharacteristicValue[v2] = v;
  return 1;
}

//----- (0040F490) --------------------------------------------------------
int __thiscall AIPlay::gatherTolerance(AIPlay *this, int groupID, int phaseID)
{
  AIPlayPhase *v3; // edi@1
  int v4; // esi@2
  AIPlayPhase *v5; // eax@3
  int result; // eax@6

  v3 = AIPlay::phase(this, phaseID);
  if( v3 )
  {
    v4 = 0;
    while( 1 )
    {
      v5 = AIPlayPhase::trigger(v3, v4);
      if( v5 )
      {
        if( v5->commands[0].groupValue == 1 )
          break;
      }
      if( ++v4 >= 3 )
        return 2;
    }
    result = v5->commands[0].value1Value;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (0040F4E0) --------------------------------------------------------
AIPlayGroup *__thiscall AIPlay::group(AIPlay *this, int n)
{
  AIPlayGroup *result; // eax@3

  if( n < 0 || n >= 5 )
    result = 0;
  else
    result = &this->groups[n];
  return result;
}

//----- (0040F500) --------------------------------------------------------
AIPlayPhase *__thiscall AIPlay::phase(AIPlay *this, int n)
{
  AIPlayPhase *result; // eax@3

  if( n < 0 || n >= 10 )
    result = 0;
  else
    result = &this->phases[n];
  return result;
}

//----- (0040F530) --------------------------------------------------------
AIPlay *__thiscall AIPlay::fillGroups(AIPlay *this, AIPlayStatus *playStatus, int *groupMembers, int numberGroupMembers, RGE_Game_World *world)
{
  AIPlay *result; // eax@1
  int *v6; // esi@3
  RGE_Static_Object *v7; // eax@4
  int v8; // eax@5
  int v9; // edx@7
  int v10; // edi@7
  int v11; // eax@10
  AIPlayGroup *v12; // eax@11
  char k; // al@12
  int v14; // ebx@15
  int v15; // edi@15
  int v16; // eax@17
  char v17; // bl@19
  bool v18; // sf@23
  unsigned __int8 v19; // of@23
  int v20; // ecx@28
  char v21; // al@29
  signed int v22; // edi@30
  int v23; // esi@30
  AIPlayGroup *v24; // ebx@31
  unsigned __int8 v25; // ST1F_1@32
  char v26; // bl@40
  int v27; // esi@44
  AIPlayGroup *v28; // ebx@45
  unsigned __int8 v29; // ST1F_1@46
  char v30; // bl@51
  int v31; // edi@54
  AIPlayGroup *v32; // eax@55
  int v33; // ebx@56
  int v34; // esi@58
  int v35; // eax@58
  AIPlay *play; // [sp+14h] [bp-4F4h]@1
  int deviation; // [sp+18h] [bp-4F0h]@3
  int *deviationa; // [sp+18h] [bp-4F0h]@12
  int (*deviationb)[50]; // [sp+18h] [bp-4F0h]@25
  int deviationc; // [sp+18h] [bp-4F0h]@54
  int j; // [sp+1Ch] [bp-4ECh]@12
  int *ja; // [sp+1Ch] [bp-4ECh]@27
  int i; // [sp+20h] [bp-4E8h]@10
  int ia; // [sp+20h] [bp-4E8h]@25
  int v45; // [sp+24h] [bp-4E4h]@12
  int *v46; // [sp+24h] [bp-4E4h]@25
  AIPlay *rVal; // [sp+28h] [bp-4E0h]@2
  int minUnits; // [sp+2Ch] [bp-4DCh]@14
  int minUnitsa; // [sp+2Ch] [bp-4DCh]@28
  int smallestGroupSize; // [sp+30h] [bp-4D8h]@19
  int smallestGroupSizea; // [sp+30h] [bp-4D8h]@30
  AIPlayGroup *a; // [sp+34h] [bp-4D4h]@11
  int aa; // [sp+34h] [bp-4D4h]@26
  int l; // [sp+38h] [bp-4D0h]@15
  int v55; // [sp+38h] [bp-4D0h]@26
  AIPlayGroup *group; // [sp+3Ch] [bp-4CCh]@1
  AIPlayGroup *groupa; // [sp+3Ch] [bp-4CCh]@55
  int unitsByTypeCount[6]; // [sp+40h] [bp-4C8h]@2
  int unitsByType[6][50]; // [sp+58h] [bp-4B0h]@7

  group = (AIPlayGroup *)this;
  result = AIPlayBook::play(world->playbook, playStatus->playNumberValue);
  play = result;
  if( !result )
    return result;
  rVal = (AIPlay *)1;
  memset(unitsByTypeCount, 0, sizeof(unitsByTypeCount));
  if( numberGroupMembers > 0 )
  {
    v6 = groupMembers;
    deviation = numberGroupMembers;
    do
    {
      v7 = RGE_Game_World::object(world, *v6);
      if( v7
        && (v8 = ((int (__stdcall *)(RGE_Static_Object *))world->playbook->vfptr->convertUnitToIntType)(v7), v8 >= 0)
        && v8 < 6 )
      {
        v9 = unitsByTypeCount[v8];
        v10 = *v6;
        unitsByTypeCount[v8] = v9 + 1;
        unitsByType[0][v9 + 50 * v8] = v10;
      }
      else
      {
        rVal = 0;
      }
      ++v6;
      --deviation;
    }
    while( deviation );
  }
  v11 = 0;
  i = 0;
  if( play->numberGroupsValue )
  {
    do
    {
      v12 = AIPlay::group(play, v11);
      a = v12;
      if( !v12 )
        return 0;
      j = 0;
      v45 = 0;
      deviationa = unitsByTypeCount;
      for( k = AIPlayGroup::minimum(v12, 0); ; k = AIPlayGroup::minimum(a, j) )
      {
        minUnits = (unsigned __int8)k;
        if( k )
        {
          v14 = 0;
          v15 = 0;
          for( l = *deviationa; v15 < l; ++v15 )
          {
            if( v14 >= minUnits )
              break;
            v16 = unitsByType[0][v15 + v45];
            if( v16 != -1 )
            {
              if( AIPlayStatus::addGrouping(playStatus, v16, i, j) == 1 )
              {
                smallestGroupSize = v14 + 1;
                v17 = play->maximumNumberUnitsValue;
                unitsByType[0][v15 + v45] = -1;
                if( (unsigned __int8)AIPlayStatus::numberInPlay(playStatus) == v17 )
                  goto CountDeviation;
                v14 = smallestGroupSize;
              }
              else
              {
                rVal = 0;
              }
            }
          }
        }
        v19 = __OFSUB__(v45 + 50, 300);
        v18 = v45 - 250 < 0;
        ++j;
        v45 += 50;
        ++deviationa;
        if( !(v18 ^ v19) )
          break;
      }
      v11 = i + 1;
      i = v11;
    }
    while( v11 < play->numberGroupsValue );
  }
  ia = 0;
  v46 = unitsByTypeCount;
  deviationb = unitsByType;
  while( 1 )
  {
    aa = 0;
    v55 = *v46;
    if( *v46 > 0 )
      break;
LABEL_53:
    v19 = __OFSUB__(ia + 1, 6);
    v18 = ia++ - 5 < 0;
    ++deviationb;
    ++v46;
    if( !(v18 ^ v19) )
      goto CountDeviation;
  }
  ja = (int *)deviationb;
  while( 1 )
  {
    v20 = *ja;
    minUnitsa = *ja;
    if( *ja == -1 )
      goto LABEL_52;
    v21 = group[6].maxValue[1];
    if( v21 == 1 )
    {
      v22 = -1;
      v23 = 0;
      smallestGroupSizea = 0;
      if( play->numberGroupsValue )
      {
        do
        {
          v24 = AIPlay::group(play, v23);
          if( v24 )
          {
            v25 = AIPlayStatus::numberOfTypeInGroup(playStatus, v23, ia);
            if( (unsigned __int8)AIPlayGroup::maximum(v24, ia) > v25
              && (v22 == -1 || smallestGroupSizea > (unsigned __int8)AIPlayStatus::numberInGroup(playStatus, v23)) )
            {
              v22 = v23;
              smallestGroupSizea = (unsigned __int8)AIPlayStatus::numberInGroup(playStatus, v23);
            }
          }
          ++v23;
        }
        while( v23 < play->numberGroupsValue );
        v20 = minUnitsa;
      }
      if( v22 != -1 )
      {
        if( AIPlayStatus::addGrouping(playStatus, v20, v22, ia) != 1 )
        {
          rVal = 0;
          goto LABEL_52;
        }
        v26 = play->maximumNumberUnitsValue;
        *ja = -1;
        if( (unsigned __int8)AIPlayStatus::numberInPlay(playStatus) == v26 )
          goto CountDeviation;
      }
      goto LABEL_52;
    }
    if( v21 == 2 )
    {
      v27 = 0;
      if( play->numberGroupsValue )
        break;
    }
LABEL_52:
    v19 = __OFSUB__(aa + 1, v55);
    v18 = aa++ + 1 - v55 < 0;
    ++ja;
    if( !(v18 ^ v19) )
      goto LABEL_53;
  }
  while( 1 )
  {
    v28 = AIPlay::group(play, v27);
    if( !v28 )
      goto LABEL_49;
    v29 = AIPlayStatus::numberOfTypeInGroup(playStatus, v27, ia);
    if( (unsigned __int8)AIPlayGroup::maximum(v28, ia) <= v29 )
      goto LABEL_49;
    if( AIPlayStatus::addGrouping(playStatus, minUnitsa, v27, ia) == 1 )
      break;
    rVal = 0;
LABEL_49:
    if( ++v27 >= play->numberGroupsValue )
      goto LABEL_52;
  }
  v30 = play->maximumNumberUnitsValue;
  *ja = -1;
  if( (unsigned __int8)AIPlayStatus::numberInPlay(playStatus) != v30 )
    goto LABEL_52;
CountDeviation:
  v31 = 0;
  deviationc = 0;
  if( play->numberGroupsValue )
  {
    do
    {
      v32 = AIPlay::group(play, v31);
      groupa = v32;
      if( v32 )
      {
        v33 = 0;
        while( 1 )
        {
          v34 = (unsigned __int8)AIPlayGroup::minimum(v32, v33);
          v35 = (unsigned __int8)AIPlayStatus::numberOfTypeInGroup(playStatus, v31, v33);
          if( v34 > v35 )
            deviationc += v34 - v35;
          if( ++v33 >= 6 )
            break;
          v32 = groupa;
        }
      }
      ++v31;
    }
    while( v31 < play->numberGroupsValue );
  }
  result = rVal;
  playStatus->deviationValue = deviationc;
  return result;
}

//----- (0040F9B0) --------------------------------------------------------
int __thiscall AIPlay::groupGivenCommandOnPhase(AIPlay *this, int gID, int cType, int pID)
{
  int v4; // esi@5
  AIPlayPhase *v5; // edi@5
  int result; // eax@9

  if( gID < 0 || gID >= 5 || pID < 0 || pID >= 10 )
  {
    result = -1;
  }
  else
  {
    v4 = 0;
    v5 = &this->phases[pID];
    while( AIPlayPhase::command(v5, v4)->groupValue != gID || AIPlayPhase::command(v5, v4)->typeValue != cType )
    {
      if( ++v4 >= 5 )
        return -1;
    }
    result = v4;
  }
  return result;
}

//----- (0040FA40) --------------------------------------------------------
signed int __stdcall AIPlay::convertToIntType(char *t)
{
  signed int result; // eax@2

  if( !strcmp(t, aAttack) )
  {
    result = 1;
  }
  else if( !strcmp(t, aAnnoy) )
  {
    result = 2;
  }
  else if( !strcmp(t, aFlank) )
  {
    result = 3;
  }
  else if( !strcmp(t, aRecon) )
  {
    result = 4;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040FB60) --------------------------------------------------------
char *__stdcall AIPlay::convertToNameType(char t)
{
  char *result; // eax@2

  switch ( t )
  {
    case 1:
      result = aAttack;
      break;
    case 2:
      result = aAnnoy;
      break;
    case 3:
      result = aFlank;
      break;
    case 4:
      result = aRecon;
      break;
    default:
      result = aInvalid;
      break;
  }
  return result;
}

//----- (0040FBB0) --------------------------------------------------------
int __thiscall AIPlay::locationsOnMap(AIPlay *this, int targetX, int targetY, int mapXSize, int mapYSize)
{
  AIPlayPhase *v5; // edi@1
  int v6; // esi@2
  AIPlayPhaseCommand *v7; // eax@3
  int v8; // ecx@4
  int v9; // eax@4
  bool v10; // sf@9
  unsigned __int8 v11; // of@9
  int p; // [sp+10h] [bp-4h]@1

  p = 0;
  v5 = this->phases;
  while( 2 )
  {
    v6 = 0;
    do
    {
      v7 = AIPlayPhase::command(v5, v6);
      if( v7->typeValue == 1 )
      {
        v8 = targetX + v7->value1Value;
        v9 = targetY + v7->value2Value;
        if( v8 < 0 || v9 < 0 || v8 >= mapXSize || v9 >= mapYSize )
          return 0;
      }
      ++v6;
    }
    while( v6 < 5 );
    ++v5;
    v11 = __OFSUB__(p + 1, 10);
    v10 = p++ - 9 < 0;
    if( v10 ^ v11 )
      continue;
    break;
  }
  return 1;
}

//----- (0040FC30) --------------------------------------------------------
void __thiscall AIPlayStatus::AIPlayStatus(AIPlayStatus *this)
{
  AIPlayStatus *v1; // esi@1
  char *v2; // eax@1
  signed int v3; // ecx@1

  v1 = this;
  this->playNumberValue = -1;
  this->targetValue = -1;
  XYZ::XYZ(&this->originalPointValue, 0, 0, 0);
  v1->currentPhaseValue = -3;
  v1->savedAttackerValue = -1;
  v1->lastPhaseChangeTimeValue = 0;
  v1->deviationValue = 0;
  v2 = &v1->groupings[0].type;
  v3 = 50;
  do
  {
    *(_DWORD *)(v2 - 5) = -1;
    *(v2 - 1) = -1;
    *v2 = -1;
    v2 += 8;
    --v3;
  }
  while( v3 );
  v1->originalHitPointsValue[0] = -1;
  v1->originalHitPointsValue[1] = -1;
  v1->originalHitPointsValue[2] = -1;
  v1->originalHitPointsValue[3] = -1;
  v1->originalHitPointsValue[4] = -1;
}

//----- (0040FCB0) --------------------------------------------------------
int __thiscall AIPlayStatus::originalHitPoints(AIPlayStatus *this, int n)
{
  int result; // eax@3

  if( n < 0 || n >= 5 )
    result = -1;
  else
    result = this->originalHitPointsValue[n];
  return result;
}

//----- (0040FCD0) --------------------------------------------------------
void __thiscall AIPlayStatus::setOriginalHitPoints(AIPlayStatus *this, int n, int v)
{
  if( n >= 0 && n < 5 )
    this->originalHitPointsValue[n] = v;
}

//----- (0040FCF0) --------------------------------------------------------
int __thiscall AIPlayStatus::numberInPlay(AIPlayStatus *this)
{
  int result; // eax@1
  signed int v2; // edx@1

  LOBYTE(result) = 0;
  v2 = 50;
  do
  {
    if( this->groupings[0].id != -1 )
      LOBYTE(result) = result + 1;
    this = (AIPlayStatus *)((char *)this + 8);
    --v2;
  }
  while( v2 );
  return result;
}

//----- (0040FD10) --------------------------------------------------------
int __thiscall AIPlayStatus::numberInGroup(AIPlayStatus *this, int n)
{
  int result; // eax@1
  signed int v3; // edx@1

  LOBYTE(result) = 0;
  v3 = 50;
  do
  {
    if( this->groupings[0].id != -1 && this->groupings[0].groupID == n )
      LOBYTE(result) = result + 1;
    this = (AIPlayStatus *)((char *)this + 8);
    --v3;
  }
  while( v3 );
  return result;
}

//----- (0040FD40) --------------------------------------------------------
int __thiscall AIPlayStatus::numberOfTypeInGroup(AIPlayStatus *this, int n, int type)
{
  int result; // eax@1
  char *v4; // ecx@1
  signed int v5; // edx@1

  LOBYTE(result) = 0;
  v4 = &this->groupings[0].type;
  v5 = 50;
  do
  {
    if( *(_DWORD *)(v4 - 5) != -1 && (unsigned __int8)*(v4 - 1) == n && (unsigned __int8)*v4 == type )
      LOBYTE(result) = result + 1;
    v4 += 8;
    --v5;
  }
  while( v5 );
  return result;
}

//----- (0040FD80) --------------------------------------------------------
char __thiscall AIPlayStatus::group(AIPlayStatus *this, int uID)
{
  signed int v2; // eax@2
  AIPlayStatus *v3; // edx@2
  char result; // al@5

  if( uID < 0 )
  {
    result = -1;
  }
  else
  {
    v2 = 0;
    v3 = this;
    while( v3->groupings[0].id != uID )
    {
      ++v2;
      v3 = (AIPlayStatus *)((char *)v3 + 8);
      if( v2 >= 50 )
        return -1;
    }
    result = this->groupings[v2].groupID;
  }
  return result;
}

//----- (0040FDB0) --------------------------------------------------------
int __thiscall AIPlayStatus::addGrouping(AIPlayStatus *this, int uID, char gID, char type)
{
  signed int v4; // eax@1
  AIPlayStatus *v5; // edx@1

  v4 = 0;
  v5 = this;
  while( v5->groupings[0].id != -1 )
  {
    ++v4;
    v5 = (AIPlayStatus *)((char *)v5 + 8);
    if( v4 >= 50 )
      return 0;
  }
  this->groupings[v4].id = uID;
  this->groupings[v4].groupID = gID;
  this->groupings[v4].type = type;
  return 1;
}

//----- (0040FDF0) --------------------------------------------------------
int __thiscall AIPlayStatus::removeGrouping(AIPlayStatus *this, int uID)
{
  signed int v2; // eax@1
  AIPlayStatus *v3; // edx@1

  v2 = 0;
  v3 = this;
  while( v3->groupings[0].id != uID )
  {
    ++v2;
    v3 = (AIPlayStatus *)((char *)v3 + 8);
    if( v2 >= 50 )
      return 0;
  }
  this->groupings[v2].id = -1;
  this->groupings[v2].groupID = -1;
  this->groupings[v2].type = -1;
  return 1;
}

//----- (0040FE30) --------------------------------------------------------
void __thiscall AIPlayStatus::zeroAllGroupings(AIPlayStatus *this)
{
  char *v1; // eax@1
  signed int v2; // ecx@1

  v1 = &this->groupings[0].type;
  v2 = 50;
  do
  {
    *(_DWORD *)(v1 - 5) = -1;
    *(v1 - 1) = -1;
    *v1 = -1;
    v1 += 8;
    --v2;
  }
  while( v2 );
}

//----- (0040FE50) --------------------------------------------------------
void __thiscall AIPlayStatus::copyUnits(AIPlayStatus *this, int *array, int *count)
{
  signed int v3; // esi@1

  *count = 0;
  v3 = 50;
  do
  {
    if( this->groupings[0].id != -1 )
      array[(*count)++] = this->groupings[0].id;
    this = (AIPlayStatus *)((char *)this + 8);
    --v3;
  }
  while( v3 );
}

//----- (0040FE90) --------------------------------------------------------
void __userpurge AIPlayStatus::load(AIPlayStatus *this@<ecx>, int a2@<ebp>, int infile)
{
  AIPlayStatus *v3; // esi@1
  int v4; // edi@1

  v3 = this;
  v4 = infile;
  rge_read(a2, infile, infile, &this->playNumberValue, 4);
  rge_read(a2, v4, v4, &v3->targetValue, 4);
  rge_read(a2, v4, v4, &infile, 4);
  v3->originalPointValue.xValue = infile;
  rge_read(a2, v4, v4, &infile, 4);
  v3->originalPointValue.yValue = infile;
  rge_read(a2, v4, v4, &infile, 4);
  v3->originalPointValue.zValue = infile;
  rge_read(a2, v4, v4, v3->originalHitPointsValue, 20);
  rge_read(a2, v4, v4, &v3->currentPhaseValue, 1);
  rge_read(a2, v4, v4, v3, 400);
  rge_read(a2, v4, v4, &v3->savedAttackerValue, 4);
  rge_read(a2, v4, v4, &v3->lastPhaseChangeTimeValue, 4);
}

//----- (0040FF70) --------------------------------------------------------
void __thiscall AIPlayStatus::save(AIPlayStatus *this, int outfile)
{
  AIPlayStatus *v2; // esi@1
  int v3; // edi@1

  v2 = this;
  v3 = outfile;
  rge_write(outfile, &this->playNumberValue, 4);
  rge_write(v3, &v2->targetValue, 4);
  outfile = v2->originalPointValue.xValue;
  rge_write(v3, &outfile, 4);
  outfile = v2->originalPointValue.yValue;
  rge_write(v3, &outfile, 4);
  outfile = v2->originalPointValue.zValue;
  rge_write(v3, &outfile, 4);
  rge_write(v3, v2->originalHitPointsValue, 20);
  rge_write(v3, &v2->currentPhaseValue, 1);
  rge_write(v3, v2, 400);
  rge_write(v3, &v2->savedAttackerValue, 4);
  rge_write(v3, &v2->lastPhaseChangeTimeValue, 4);
}

//----- (00410050) --------------------------------------------------------
void __thiscall AIPlayStatus::copy(AIPlayStatus *this, AIPlayStatus *ps)
{
  signed int v2; // ebp@1
  int v3; // eax@1
  int v4; // esi@1
  AIPlayStatus *v5; // esi@1
  char *v6; // eax@1
  signed int v7; // edi@1
  int v8; // edx@2
  char *v9; // eax@3
  signed int v10; // ecx@3

  v2 = 50;
  this->playNumberValue = ps->playNumberValue;
  this->targetValue = ps->targetValue;
  v3 = ps->originalPointValue.zValue;
  v4 = ps->originalPointValue.yValue;
  this->originalPointValue.xValue = ps->originalPointValue.xValue;
  this->originalPointValue.yValue = v4;
  this->originalPointValue.zValue = v3;
  this->currentPhaseValue = ps->currentPhaseValue;
  this->savedAttackerValue = ps->savedAttackerValue;
  this->lastPhaseChangeTimeValue = ps->lastPhaseChangeTimeValue;
  v5 = ps;
  v6 = &this->groupings[0].groupID;
  v7 = (char *)ps - (char *)this;
  do
  {
    v8 = v5->groupings[0].id;
    v5 = (AIPlayStatus *)((char *)v5 + 8);
    *((_DWORD *)v6 - 1) = v8;
    *v6 = v6[v7];
    v6[1] = *(&v5[-1].deviationValue + 1);
    v6 += 8;
    --v2;
  }
  while( v2 );
  v9 = (char *)this->originalHitPointsValue;
  v10 = 5;
  do
  {
    *(_DWORD *)v9 = *(_DWORD *)&v9[v7];
    v9 += 4;
    --v10;
  }
  while( v10 );
}

//----- (00410100) --------------------------------------------------------
void __thiscall AIPlayStatus::removeDeadUnits(AIPlayStatus *this, int gID, RGE_Game_World *world)
{
  AIPlayStatus *v3; // esi@1
  signed int v4; // ebp@1
  RGE_Static_Object *v5; // eax@3

  v3 = this;
  v4 = 50;
  do
  {
    if( v3->groupings[0].id != -1 )
    {
      v5 = RGE_Game_World::object(world, v3->groupings[0].id);
      if( !v5 || v5->object_state > 2u )
      {
        v3->groupings[0].id = -1;
        v3->groupings[0].groupID = -1;
        v3->groupings[0].type = -1;
      }
    }
    v3 = (AIPlayStatus *)((char *)v3 + 8);
    --v4;
  }
  while( v4 );
}

//----- (00410150) --------------------------------------------------------
void __thiscall AIPlayStatus::resetHitPoints(AIPlayStatus *this, int gID, RGE_Game_World *world)
{
  int v3; // ebp@1
  AIPlayStatus *v4; // esi@1
  signed int v5; // ebx@1
  RGE_Static_Object *v6; // eax@4
  AIPlayStatus *v7; // [sp+10h] [bp-4h]@1

  v7 = this;
  v3 = 0;
  v4 = this;
  v5 = 50;
  do
  {
    if( v4->groupings[0].id != -1 && v4->groupings[0].groupID == gID )
    {
      v6 = RGE_Game_World::object(world, v4->groupings[0].id);
      if( v6 )
        v3 += (signed __int64)v6->hp;
    }
    v4 = (AIPlayStatus *)((char *)v4 + 8);
    --v5;
  }
  while( v5 );
  AIPlayStatus::setOriginalHitPoints(v7, gID, v3);
}

//----- (004101B0) --------------------------------------------------------
void __thiscall AIPlayBook::AIPlayBook(AIPlayBook *this)
{
  this->numberPlaysValue = 0;
  this->plays = 0;
  this->vfptr = (AIPlayBookVtbl *)&AIPlayBook::`vftable';
}
// 56E970: using guessed type int (__thiscall *AIPlayBook::`vftable')(void *Memory, unsigned int __flags);

//----- (004101D0) --------------------------------------------------------
AIPlayBook *__thiscall AIPlayBook::`vector deleting destructor'(AIPlayBook *this, unsigned int __flags)
{
  AIPlayBook *v2; // esi@1

  v2 = this;
  AIPlayBook::~AIPlayBook(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004101F0) --------------------------------------------------------
void __thiscall AIPlayBook::~AIPlayBook(AIPlayBook *this)
{
  AIPlayBook *v1; // esi@1
  AIPlay *v2; // eax@1

  v1 = this;
  v2 = this->plays;
  this->vfptr = (AIPlayBookVtbl *)&AIPlayBook::`vftable';
  if( v2 )
  {
    this->numberPlaysValue = 0;
    operator delete(v2);
    v1->plays = 0;
  }
}
// 56E970: using guessed type int (__thiscall *AIPlayBook::`vftable')(void *Memory, unsigned int __flags);

//----- (00410220) --------------------------------------------------------
int __thiscall AIPlayBook::loadPlays(AIPlayBook *this, char *filename)
{
  AIPlayBook *v2; // ebx@1
  _iobuf *v3; // ebp@3
  int v4; // edi@13
  AIPlayPhase *v5; // eax@13
  AIPlayPhase *v6; // ebp@13
  AIPlay *v7; // eax@13
  AIPlay *v8; // esi@14
  signed int v9; // ebp@18
  int v10; // ecx@25
  int v11; // edx@25
  char v12; // al@26
  int v13; // edx@27
  int v14; // ecx@27
  bool v15; // zf@27
  int v16; // eax@27
  char *v17; // edx@27
  int v18; // edx@30
  int v19; // esi@36
  int v20; // eax@68
  int v21; // eax@72
  int v22; // ecx@79
  int v23; // edi@82
  int v24; // esi@84
  AIPlayGroup *v25; // eax@84
  AIPlayGroup *v26; // eax@87
  AIPlayPhase *v27; // esi@99
  char v28; // di@103
  AIPlayPhase *v29; // esi@103
  char v30; // di@107
  AIPlayPhase *v31; // esi@107
  int v32; // edx@110
  AIPlay *v33; // esi@110
  int v34; // ebp@110
  int v35; // esi@113
  int v36; // edi@114
  char v37; // al@115
  char v38; // al@115
  AIPlay *v39; // eax@116
  int v40; // edi@117
  signed int v41; // edi@117
  char v42; // al@118
  char v43; // al@118
  bool v44; // sf@119
  unsigned __int8 v45; // of@119
  int v46; // edi@121
  AIPlayPhaseCommand *v47; // eax@122
  AIPlayPhaseCommand *v48; // edi@122
  int v49; // edi@126
  AIPlayPhaseTrigger *v50; // eax@127
  char *v52; // edx@134
  const char *v53; // edi@134
  int v54; // [sp-8h] [bp-3CCh]@84
  int v55; // [sp-8h] [bp-3CCh]@87
  int v56; // [sp-4h] [bp-3C8h]@84
  signed int v57; // [sp-4h] [bp-3C8h]@87
  int temp3; // [sp+10h] [bp-3B4h]@21
  int temp4; // [sp+14h] [bp-3B0h]@21
  char commentTemp2; // [sp+1Bh] [bp-3A9h]@21
  int currentPhase; // [sp+1Ch] [bp-3A8h]@18
  char commentTemp1; // [sp+23h] [bp-3A1h]@21
  int j; // [sp+24h] [bp-3A0h]@116
  AIPlayPhase *curPhase; // [sp+28h] [bp-39Ch]@117
  int a; // [sp+2Ch] [bp-398h]@117
  int currentPlay; // [sp+30h] [bp-394h]@18
  AIPlayPhase *refPhase; // [sp+34h] [bp-390h]@13
  int temp5; // [sp+38h] [bp-38Ch]@21
  int i; // [sp+3Ch] [bp-388h]@113
  int temp8; // [sp+40h] [bp-384h]@21
  int temp7; // [sp+44h] [bp-380h]@21
  _iobuf *fileIn; // [sp+48h] [bp-37Ch]@3
  XYZ rotatedPoint; // [sp+4Ch] [bp-378h]@124
  XYZ originalPoint; // [sp+58h] [bp-36Ch]@124
  XYZ origin; // [sp+64h] [bp-360h]@124
  char temp2[256]; // [sp+70h] [bp-354h]@8
  AIPlayPhaseCommand command; // [sp+170h] [bp-254h]@99
  AIPlayPhaseCommand newCommand; // [sp+180h] [bp-244h]@124
  char temp[256]; // [sp+190h] [bp-234h]@3
  AIPlayPhaseTrigger trigger; // [sp+290h] [bp-134h]@103
  AIPlayPhaseTrigger t; // [sp+2A4h] [bp-120h]@107
  char temp6[256]; // [sp+2B8h] [bp-10Ch]@21
  int v83; // [sp+3C0h] [bp-4h]@13

  v2 = this;
  if( !filename )
    goto LABEL_134;
  if( !strcmp(filename, aNone_2) )
  {
    if( filename )
    {
      v52 = v2->nameValue;
      v53 = aNone_2;
      goto LABEL_136;
    }
LABEL_134:
    v52 = v2->nameValue;
    v53 = aNull;
LABEL_136:
    strcpy(v52, v53);
    return 0;
  }
  strncpy(v2->nameValue, filename, 0x40u);
  sprintf(temp, aS_2, v2->nameValue);
  v3 = fopen(temp, Mode);
  fileIn = v3;
  if( v3 )
  {
    if( v2->plays )
    {
      operator delete(v2->plays);
      v2->plays = 0;
    }
    v2->numberPlaysValue = 0;
    while( fgets(temp, 256, v3) )
    {
      if( strlen(temp) != 0 )
      {
        sscanf(temp, aS, temp2);
        if( !strcmp(aPlay, temp2) )
          v2->numberPlaysValue += 8;
      }
    }
    if( v2->numberPlaysValue > 16000 )
      v2->numberPlaysValue = 16000;
    v4 = v2->numberPlaysValue;
    v5 = (AIPlayPhase *)operator new(1544 * v4);
    v6 = v5;
    refPhase = v5;
    v7 = 0;
    v83 = 0;
    if( refPhase )
    {
      v8 = (AIPlay *)v6;
      if( v4 - 1 >= 0 )
      {
        do
        {
          AIPlay::AIPlay(v8);
          ++v8;
          --v4;
        }
        while( v4 );
      }
      v7 = (AIPlay *)v6;
    }
    v83 = -1;
    v2->plays = v7;
    if( v7 )
    {
      rewind(fileIn);
      v9 = -1;
      currentPlay = -1;
      currentPhase = -1;
      while( 1 )
      {
        if( !fgets(temp, 256, fileIn) )
        {
LABEL_132:
          fclose(fileIn);
          return 1;
        }
        if( strlen(temp) != 0 )
        {
          strcpy(temp2, message_in);
          strcpy(temp6, message_in);
          temp3 = 0;
          temp4 = 0;
          temp5 = 0;
          temp7 = 0;
          temp8 = 0;
          if( sscanf(temp, aCC, &commentTemp1, &commentTemp2) != -1 && (commentTemp1 != 47 || commentTemp2 != 47) )
          {
            sscanf(temp, aS, temp2);
            if( !strcmp(temp2, aPlay) )
            {
              v10 = 0;
              v11 = 0;
              if( temp[0] != 34 )
              {
                do
                {
                  v12 = temp[v11++ + 1];
                  ++v10;
                }
                while( v12 != 34 );
              }
              v13 = v11 + 1;
              v14 = v10 + 1;
              v15 = temp[v13] == 34;
              v16 = v14;
              v17 = &temp[v13];
              temp3 = v14;
              temp4 = v14;
              if( !v15 )
              {
                do
                {
                  ++v17;
                  ++v16;
                }
                while( *v17 != 34 );
                temp4 = v16;
              }
              v18 = 0;
              if( v14 < v16 )
              {
                v18 = v16 - v14;
                qmemcpy(temp2, &temp[v14], v16 - v14);
              }
              ++v9;
              temp2[v18] = 0;
              currentPlay = v9;
              if( v9 >= 16000 )
                goto LABEL_132;
              AIPlay::setName(&v2->plays[v9], temp2);
            }
            else if( !strcmp(temp2, aPlaytype) && v9 != -1 )
            {
              sscanf(temp, aSS_3, temp2);
              v19 = (int)&v2->plays[v9];
              *(_BYTE *)(v19 + 67) = AIPlay::convertToIntType(temp2);
            }
            else if( !strcmp(temp2, aMinunits) && v9 != -1 )
            {
              sscanf(temp, aSD, &temp3);
              v2->plays[v9].minimumNumberUnitsValue = temp3;
            }
            else if( !strcmp(temp2, aMaxunits) && v9 != -1 )
            {
              sscanf(temp, aSD, &temp3);
              v2->plays[v9].maximumNumberUnitsValue = temp3;
            }
            else if( !strcmp(temp2, aPower) && v9 != -1 )
            {
              sscanf(temp, aSD, &temp3);
              v2->plays[v9].powerValue = temp3;
            }
            else if( !strcmp(temp2, aOverflow) && v9 != -1 )
            {
              sscanf(temp, aSS_3, temp2);
              if( !strcmp(temp2, aBalance) )
              {
                v2->plays[v9].overflowValue = 1;
              }
              else if( !strcmp(temp2, aFirstgroup) )
              {
                v2->plays[v9].overflowValue = 2;
              }
            }
            else if( !strcmp(temp2, aDeathpercentag) && v9 != -1 )
            {
              sscanf(temp, aSD, &temp3);
              if( temp3 >= 0 )
              {
                if( temp3 <= 100 )
                  v2->plays[v9].deathPercentageValue = temp3;
                else
                  v2->plays[v9].deathPercentageValue = 100;
              }
              else
              {
                v2->plays[v9].deathPercentageValue = 0;
              }
            }
            else if( !strcmp(temp2, aIntelligence) && v9 != -1 )
            {
              sscanf(temp, aSD, &temp3);
              if( temp3 >= 0 )
              {
                if( temp3 <= 100 )
                  v2->plays[v9].intelligenceValue = temp3;
                else
                  v2->plays[v9].intelligenceValue = 100;
              }
              else
              {
                v2->plays[v9].intelligenceValue = 0;
              }
            }
            else if( !strcmp(temp2, aTargetchar) && v9 != -1 )
            {
              sscanf(temp, aSS_3, temp6);
              v20 = v2->vfptr->convertTargetCharacteristicNameToIntType(v2, temp6);
              if( v20 )
                AIPlay::addTargetCharacteristic(&v2->plays[v9], v20);
            }
            else if( !strcmp(temp2, aTargettype) && v9 != -1 )
            {
              sscanf(temp, aSS_3, temp6);
              v21 = v2->vfptr->convertTargetNameToIntType(v2, temp6);
              if( v21 )
                AIPlay::addTargetType(&v2->plays[v9], v21);
            }
            else if( !strcmp(temp2, aNumbergroups) && v9 != -1 )
            {
              sscanf(temp, aSD, &temp3);
              v2->plays[v9].numberGroupsValue = temp3;
            }
            else
            {
              if( strcmp(temp2, aGroup) || v9 == -1 )
              {
                v22 = currentPhase;
LABEL_91:
                if( !strcmp(temp2, aPhase) && v9 != -1 )
                {
                  sscanf(temp, aSD, &temp3);
                  currentPhase = temp3;
                }
                else if( !strcmp(temp2, aGroup) && v9 != -1 && v22 != -1 )
                {
                  sscanf(temp, aSDSDDD, &temp3, temp6, &temp4, &temp5, &temp7);
                  if( temp3 >= 0 && temp3 < 5 )
                  {
                    v27 = AIPlay::phase(&v2->plays[v9], currentPhase);
                    AIPlayPhaseCommand::AIPlayPhaseCommand(&command, temp3, temp6, temp4, temp5, temp7);
                    AIPlayPhase::addCommand(v27, &command);
                  }
                }
                else if( !strcmp(temp2, aTrigger) && v9 != -1 && v22 != -1 )
                {
                  sscanf(temp, aSDSDD_1, &temp3, temp6, &temp4, &temp8);
                  v28 = currentPhase;
                  v29 = AIPlay::phase(&v2->plays[v9], currentPhase);
                  AIPlayPhaseTrigger::AIPlayPhaseTrigger(&trigger, temp6, temp4, temp8, v28, temp3, 0);
                  AIPlayPhase::addTrigger(v29, &trigger);
                }
                else if( !strcmp(temp2, aRtrigger) && v9 != -1 && v22 != -1 )
                {
                  sscanf(temp, aSDSDDD, &temp3, temp6, &temp4, &temp8, &temp7);
                  v30 = currentPhase;
                  v31 = AIPlay::phase(&v2->plays[v9], currentPhase);
                  AIPlayPhaseTrigger::AIPlayPhaseTrigger(&t, temp6, temp4, temp8, v30, temp3, temp7);
                  AIPlayPhase::addTrigger(v31, &t);
                }
                else if( !strcmp(temp2, aEndplay) && v9 != -1 )
                {
                  v32 = currentPlay;
                  v33 = v2->plays;
                  currentPhase = -1;
                  v34 = currentPlay;
                  refPhase = (AIPlayPhase *)strcpy(temp2, v33[currentPlay].nameValue);
                  if( temp2[0] != 72 || temp2[1] != 80 )
                  {
                    i = 1;
                    v35 = v34 * 1544;
                    currentPlay = v32 + 7;
                    do
                    {
                      sprintf(temp2, aSfD, &v2->plays[v34], i);
                      v35 += 1544;
                      AIPlay::setName((AIPlay *)((char *)v2->plays + v35), temp2);
                      v36 = 0;
                      *(&v2->plays->typeValue + v35) = v2->plays[v34].typeValue;
                      *(&v2->plays->minimumNumberUnitsValue + v35) = v2->plays[v34].minimumNumberUnitsValue;
                      *(&v2->plays->maximumNumberUnitsValue + v35) = v2->plays[v34].maximumNumberUnitsValue;
                      *(&v2->plays->powerValue + v35) = v2->plays[v34].powerValue;
                      *(&v2->plays->overflowValue + v35) = v2->plays[v34].overflowValue;
                      *(&v2->plays->deathPercentageValue + v35) = v2->plays[v34].deathPercentageValue;
                      *(&v2->plays->intelligenceValue + v35) = v2->plays[v34].intelligenceValue;
                      do
                      {
                        v37 = AIPlay::targetType(&v2->plays[v34], v36);
                        AIPlay::addTargetType((AIPlay *)((char *)v2->plays + v35), v37);
                        v38 = AIPlay::targetCharacteristic(&v2->plays[v34], v36);
                        AIPlay::addTargetCharacteristic((AIPlay *)((char *)v2->plays + v35), v38);
                        ++v36;
                      }
                      while( v36 < 5 );
                      v39 = v2->plays;
                      j = 0;
                      *(&v39->numberGroupsValue + v35) = v39[v34].numberGroupsValue;
                      do
                      {
                        v40 = j;
                        curPhase = (AIPlayPhase *)AIPlay::group(&v2->plays[v34], j);
                        a = (int)AIPlay::group((AIPlay *)((char *)v2->plays + v35), v40);
                        v41 = 0;
                        do
                        {
                          v42 = AIPlayGroup::minimum((AIPlayGroup *)curPhase, v41);
                          AIPlayGroup::setMinimum((AIPlayGroup *)a, v41, (unsigned __int8)v42);
                          v43 = AIPlayGroup::maximum((AIPlayGroup *)curPhase, v41);
                          AIPlayGroup::setMaximum((AIPlayGroup *)a, v41++, (unsigned __int8)v43);
                        }
                        while( v41 < 6 );
                        v45 = __OFSUB__(j + 1, 5);
                        v44 = j++ - 4 < 0;
                      }
                      while( v44 ^ v45 );
                      j = 0;
                      do
                      {
                        v46 = j;
                        refPhase = AIPlay::phase(&v2->plays[v34], j);
                        curPhase = AIPlay::phase((AIPlay *)((char *)v2->plays + v35), v46);
                        a = 0;
                        do
                        {
                          v47 = AIPlayPhase::command(refPhase, a);
                          v48 = v47;
                          if( v47->typeValue == 1 )
                          {
                            XYZ::XYZ(&origin, 0, 0, 0);
                            XYZ::XYZ(&rotatedPoint);
                            XYZ::XYZ(&originalPoint, v48->value1Value, v48->value2Value, v48->value3Value);
                            XYZ::rotateXYByFacet(&originalPoint, &origin, &rotatedPoint, i);
                            AIPlayPhaseCommand::AIPlayPhaseCommand(
                              &newCommand,
                              v48->groupValue,
                              v48->typeValue,
                              rotatedPoint.xValue,
                              rotatedPoint.yValue,
                              rotatedPoint.zValue);
                            AIPlayPhase::addCommand(curPhase, &newCommand);
                          }
                          else
                          {
                            AIPlayPhase::addCommand(curPhase, v47);
                          }
                          v45 = __OFSUB__(a + 1, 5);
                          v44 = a++ - 4 < 0;
                        }
                        while( v44 ^ v45 );
                        v49 = 0;
                        do
                        {
                          v50 = (AIPlayPhaseTrigger *)AIPlayPhase::trigger(refPhase, v49);
                          AIPlayPhase::addTrigger(curPhase, v50);
                          ++v49;
                        }
                        while( v49 < 3 );
                        v45 = __OFSUB__(j + 1, 10);
                        v44 = j++ - 9 < 0;
                      }
                      while( v44 ^ v45 );
                      v45 = __OFSUB__(i + 1, 8);
                      v44 = i++ - 7 < 0;
                    }
                    while( v44 ^ v45 );
                  }
                  else
                  {
                    v2->numberPlaysValue -= 7;
                  }
                  v9 = currentPlay;
                }
                goto LABEL_131;
              }
              v22 = currentPhase;
              if( currentPhase != -1 )
                goto LABEL_91;
              sscanf(temp, aSDSDD, &temp3, temp6, &temp4, &temp5);
              if( temp3 >= 0 && temp3 < 5 )
              {
                v23 = v2->vfptr->convertUnitNameToIntType(v2, temp6);
                if( v23 != -1 )
                {
                  if( temp5 < 0 )
                  {
                    v56 = 0;
                    v54 = v23;
                    v24 = v9;
                    v25 = AIPlay::group(&v2->plays[v9], temp3);
                  }
                  else
                  {
                    v56 = temp4;
                    v54 = v23;
                    v24 = v9;
                    v25 = AIPlay::group(&v2->plays[v9], temp3);
                  }
                  AIPlayGroup::setMinimum(v25, v54, v56);
                  if( temp5 > 50 )
                  {
                    v57 = 50;
                    v55 = v23;
                    v26 = AIPlay::group(&v2->plays[v24], temp3);
                  }
                  else
                  {
                    v57 = temp5;
                    v55 = v23;
                    v26 = AIPlay::group(&v2->plays[v24], temp3);
                  }
                  AIPlayGroup::setMaximum(v26, v55, v57);
                }
              }
            }
          }
        }
LABEL_131:
        if( v9 >= 16000 )
          goto LABEL_132;
      }
    }
  }
  return 0;
}

//----- (00411340) --------------------------------------------------------
AIPlay *__thiscall AIPlayBook::play(AIPlayBook *this, int n)
{
  AIPlay *v2; // edx@1
  AIPlay *result; // eax@4

  v2 = this->plays;
  if( v2 && n >= 0 && n < this->numberPlaysValue )
    result = &v2[n];
  else
    result = 0;
  return result;
}

//----- (00411370) --------------------------------------------------------
AIPlay *__thiscall AIPlayBook::play(AIPlayBook *this, char *name)
{
  AIPlay *v2; // edi@1
  int v3; // edx@2
  int v4; // ebp@2
  AIPlay *result; // eax@5

  v2 = this->plays;
  if( v2 && (v3 = this->numberPlaysValue, v4 = 0, v3 > 0) )
  {
    while( strcmp(v2->nameValue, name) )
    {
      ++v4;
      ++v2;
      if( v4 >= v3 )
        return 0;
    }
    result = &this->plays[v4];
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00411400) --------------------------------------------------------
int __thiscall AIPlayBook::playNumber(AIPlayBook *this, char *name)
{
  int v2; // eax@2
  int v3; // ebp@2
  AIPlay *v4; // edi@3
  int result; // eax@6

  if( this->plays && (v2 = this->numberPlaysValue, v3 = 0, v2 > 0) )
  {
    v4 = this->plays;
    while( strcmp(v4->nameValue, name) )
    {
      ++v3;
      ++v4;
      if( v3 >= v2 )
        return -1;
    }
    result = v3;
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (00411480) --------------------------------------------------------
int __stdcall AIPlayBook::convertTargetNameToIntType(char *t)
{
  int result; // eax@2

  if( !strcmp(t, aAny) )
    result = 5;
  else
    result = 0;
  return result;
}

//----- (004114E0) --------------------------------------------------------
int __stdcall AIPlayBook::convertTargetCharacteristicNameToIntType(char *t)
{
  int result; // eax@2

  if( !strcmp(t, aStationary) )
  {
    result = 1;
  }
  else if( !strcmp(t, aMoving) )
  {
    result = 2;
  }
  else if( !strcmp(t, aSlow) )
  {
    result = 3;
  }
  else if( !strcmp(t, aFast) )
  {
    result = 4;
  }
  else if( !strcmp(t, aAny) )
  {
    result = 5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00411650) --------------------------------------------------------
int __stdcall AIPlayBook::convertUnitNameToIntType(char *t)
{
  return -1;
}

//----- (00411660) --------------------------------------------------------
int __stdcall AIPlayBook::convertUnitToIntType(RGE_Static_Object *obj)
{
  return -1;
}
