
/**
 * @file    Engine\RGE\AiUnitModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00412F00) --------------------------------------------------------
void __thiscall UnitAIModule::UnitAIModule(UnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  UnitAIModule *v3; // esi@1

  v3 = this;
  this->objectValue = o;
  this->moodValue = -1;
  this->objectCategoryValue = -1;
  this->orderQueueSizeValue = 0;
  this->orderQueueMaxSizeValue = iQS;
  this->notifyQueueSizeValue = 0;
  this->notifyQueueMaxSizeValue = iQS;
  this->currentOrderValue = -1;
  this->currentOrderPriorityValue = -1;
  this->currentActionValue = -1;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  LODWORD(this->currentTargetXValue) = -1082130432;
  LODWORD(this->currentTargetYValue) = -1082130432;
  LODWORD(this->currentTargetZValue) = -1082130432;
  LODWORD(this->desiredTargetDistanceValue) = 0x40000000;
  this->defendTargetValue = -1;
  this->lastOrderValue = -1;
  this->lastActionValue = -1;
  this->lastTargetValue = -1;
  this->lastTargetTypeValue = -1;
  this->attackingUnitsValue.value = 0;
  this->attackingUnitsValue.numberValue = 0;
  this->attackingUnitsValue.desiredNumberValue = 0;
  this->attackingUnitsValue.maximumSizeValue = 10;
  this->attackingUnitsValue.value = (int *)operator new(0x28u);
  v3->waypointQueueSizeValue = 0;
  v3->lastUpdateTimeValue = 0;
  v3->idleTimerValue = 0;
  v3->idleTimeoutValue = 3000;
  v3->secondaryTimerValue = 0;
  v3->lookAroundTimerValue = 0;
  v3->lookAroundTimeoutValue = 1000;
  LODWORD(v3->defenseBufferValue) = 1065353216;
  v3->importantObjects = 0;
  v3->numberImportantObjects = 0;
  v3->playStatus = 0;
  v3->stopAfterTargetKilledValue = 0;
  v3->vfptr = (UnitAIModuleVtbl *)&UnitAIModule::`vftable';
  if( o )
  {
    v3->objectCategoryValue = o->master_obj->object_group;
    v3->defenseBufferValue = o->master_obj->los;
  }
  v3->orderQueueValue = (OrderEvent *)operator new(36 * v3->orderQueueMaxSizeValue);
  v3->notifyQueueValue = (NotifyEvent *)operator new(24 * v3->notifyQueueMaxSizeValue);
  LODWORD(v3->lastWorldPositionValue.x) = -1082130432;
  LODWORD(v3->lastWorldPositionValue.y) = -1082130432;
  LODWORD(v3->lastWorldPositionValue.z) = -1082130432;
  UnitAIModule::setAdjustedIdleTimeout(v3);
}
// 56EAD8: using guessed type int (__thiscall *UnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00413070) --------------------------------------------------------
UnitAIModule *__thiscall UnitAIModule::`vector deleting destructor'(UnitAIModule *this, unsigned int __flags)
{
  UnitAIModule *v2; // esi@1

  v2 = this;
  UnitAIModule::~UnitAIModule(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00413150) --------------------------------------------------------
void __thiscall UnitAIModule::save(UnitAIModule *this, int outfile)
{
  UnitAIModule *v2; // esi@1
  int v3; // edi@1
  int v4; // ebx@1
  int v5; // ebp@2
  int v6; // ebx@4
  int v7; // ebp@5
  int i; // ebp@7
  int *v9; // ebx@9
  int j; // eax@10

  v2 = this;
  v3 = outfile;
  rge_write(outfile, &this->moodValue, 4);
  rge_write(v3, &v2->currentOrderValue, 4);
  rge_write(v3, &v2->currentOrderPriorityValue, 4);
  rge_write(v3, &v2->currentActionValue, 4);
  rge_write(v3, &v2->currentTargetValue, 4);
  rge_write(v3, &v2->currentTargetTypeValue, 4);
  rge_write(v3, &v2->currentTargetXValue, 4);
  rge_write(v3, &v2->currentTargetYValue, 4);
  rge_write(v3, &v2->currentTargetZValue, 4);
  rge_write(v3, &v2->desiredTargetDistanceValue, 4);
  rge_write(v3, &v2->lastActionValue, 4);
  rge_write(v3, &v2->lastOrderValue, 4);
  rge_write(v3, &v2->lastTargetValue, 4);
  rge_write(v3, &v2->lastTargetTypeValue, 4);
  rge_write(v3, &v2->lastUpdateTimeValue, 4);
  rge_write(v3, &v2->idleTimerValue, 4);
  rge_write(v3, &v2->idleTimeoutValue, 4);
  rge_write(v3, &v2->adjustedIdleTimeoutValue, 4);
  rge_write(v3, &v2->secondaryTimerValue, 4);
  rge_write(v3, &v2->lookAroundTimerValue, 4);
  rge_write(v3, &v2->lookAroundTimeoutValue, 4);
  rge_write(v3, &v2->defendTargetValue, 4);
  rge_write(v3, &v2->defenseBufferValue, 4);
  rge_write(v3, &v2->lastWorldPositionValue, 16);
  rge_write(v3, &v2->orderQueueSizeValue, 4);
  v4 = 0;
  if( v2->orderQueueSizeValue > 0 )
  {
    v5 = 0;
    do
    {
      rge_write(v3, &v2->orderQueueValue[v5], 36);
      ++v4;
      ++v5;
    }
    while( v4 < v2->orderQueueSizeValue );
  }
  rge_write(v3, &v2->notifyQueueSizeValue, 4);
  v6 = 0;
  if( v2->notifyQueueSizeValue > 0 )
  {
    v7 = 0;
    do
    {
      rge_write(v3, &v2->notifyQueueValue[v7], 24);
      ++v6;
      ++v7;
    }
    while( v6 < v2->notifyQueueSizeValue );
  }
  outfile = v2->attackingUnitsValue.numberValue;
  rge_write(v3, &outfile, 4);
  for( i = 0; i < v2->attackingUnitsValue.numberValue; ++i )
  {
    if( i > v2->attackingUnitsValue.maximumSizeValue - 1 )
    {
      v9 = (int *)operator new(4 * i + 4);
      if( v9 )
      {
        for( j = 0; j < v2->attackingUnitsValue.maximumSizeValue; v9[j - 1] = v2->attackingUnitsValue.value[j - 1] )
        {
          if( j >= i + 1 )
            break;
          ++j;
        }
        operator delete(v2->attackingUnitsValue.value);
        v2->attackingUnitsValue.value = v9;
        v2->attackingUnitsValue.maximumSizeValue = i + 1;
      }
    }
    outfile = v2->attackingUnitsValue.value[i];
    rge_write(v3, &outfile, 4);
  }
  if( v2->playStatus )
  {
    outfile = 1;
    rge_write(v3, &outfile, 4);
    AIPlayStatus::save(v2->playStatus, v3);
  }
  else
  {
    outfile = 0;
    rge_write(v3, &outfile, 4);
  }
  rge_write(v3, &v2->stopAfterTargetKilledValue, 1);
}

//----- (00413450) --------------------------------------------------------
void __userpurge UnitAIModule::load(UnitAIModule *this@<ecx>, int a2@<ebp>, int infile)
{
  UnitAIModule *v3; // esi@1
  int v4; // edi@1
  int j; // ebx@4
  int k; // ebx@6
  int v7; // ecx@9
  int v8; // eax@9
  int *v9; // ebx@14
  int m; // eax@15
  AIPlayStatus *v11; // eax@22
  AIPlayStatus *v12; // eax@23
  int numberNotifies; // [sp+10h] [bp-48h]@6
  int i; // [sp+14h] [bp-44h]@8
  int numberUnits; // [sp+18h] [bp-40h]@8
  AIPlayStatus *data; // [sp+1Ch] [bp-3Ch]@9
  AIPlayStatus *l; // [sp+20h] [bp-38h]@9
  int tempInt; // [sp+24h] [bp-34h]@21
  NotifyEvent tempNotify; // [sp+28h] [bp-30h]@5
  int v20; // [sp+54h] [bp-4h]@22

  v3 = this;
  v4 = infile;
  rge_read(a2, infile, infile, &this->moodValue, 4);
  rge_read(a2, v4, v4, &v3->currentOrderValue, 4);
  rge_read(a2, v4, v4, &v3->currentOrderPriorityValue, 4);
  rge_read(a2, v4, v4, &v3->currentActionValue, 4);
  rge_read(a2, v4, v4, &v3->currentTargetValue, 4);
  rge_read(a2, v4, v4, &v3->currentTargetTypeValue, 4);
  rge_read(a2, v4, v4, &v3->currentTargetXValue, 4);
  rge_read(a2, v4, v4, &v3->currentTargetYValue, 4);
  rge_read(a2, v4, v4, &v3->currentTargetZValue, 4);
  rge_read(a2, v4, v4, &v3->desiredTargetDistanceValue, 4);
  rge_read(a2, v4, v4, &v3->lastActionValue, 4);
  rge_read(a2, v4, v4, &v3->lastOrderValue, 4);
  rge_read(a2, v4, v4, &v3->lastTargetValue, 4);
  rge_read(a2, v4, v4, &v3->lastTargetTypeValue, 4);
  rge_read(a2, v4, v4, &v3->lastUpdateTimeValue, 4);
  rge_read(a2, v4, v4, &v3->idleTimerValue, 4);
  rge_read(a2, v4, v4, &v3->idleTimeoutValue, 4);
  rge_read(a2, v4, v4, &v3->adjustedIdleTimeoutValue, 4);
  rge_read(a2, v4, v4, &v3->secondaryTimerValue, 4);
  if( save_game_version < 6.9299998 )
  {
    v3->lookAroundTimerValue = 0;
    v3->lookAroundTimeoutValue = 1000;
  }
  else
  {
    rge_read(a2, v4, v4, &v3->lookAroundTimerValue, 4);
    rge_read(a2, v4, v4, &v3->lookAroundTimeoutValue, 4);
  }
  rge_read(a2, v4, v4, &v3->defendTargetValue, 4);
  rge_read(a2, v4, v4, &v3->defenseBufferValue, 4);
  rge_read(a2, v4, v4, &v3->lastWorldPositionValue, 16);
  rge_read(a2, v4, v4, &infile, 4);
  for( j = 0; j < infile; ++j )
  {
    rge_read(a2, v4, v4, &tempNotify, 36);
    UnitAIModule::addToOrderQueue(v3, (OrderEvent *)&tempNotify, 0);
  }
  rge_read(a2, v4, v4, &numberNotifies, 4);
  for( k = 0; k < numberNotifies; ++k )
  {
    rge_read(a2, v4, v4, &tempNotify, 24);
    UnitAIModule::addToNotifyQueue(v3, &tempNotify);
  }
  rge_read(a2, v4, v4, &numberUnits, 4);
  for( i = 0; i < numberUnits; ++i )
  {
    rge_read(a2, v4, v4, &data, 4);
    v7 = v3->attackingUnitsValue.numberValue;
    v8 = 0;
    for( l = data; v8 < v7; ++v8 )
    {
      if( v8 >= v3->attackingUnitsValue.maximumSizeValue )
        break;
      a2 = (int)v3->attackingUnitsValue.value;
      if( *(AIPlayStatus **)(a2 + 4 * v8) == data )
        goto LABEL_20;
    }
    if( v7 > v3->attackingUnitsValue.maximumSizeValue - 1 )
    {
      a2 = v7 + 1;
      v9 = (int *)operator new(4 * (v7 + 1));
      if( v9 )
      {
        for( m = 0; m < v3->attackingUnitsValue.maximumSizeValue; v9[m - 1] = v3->attackingUnitsValue.value[m - 1] )
        {
          if( m >= a2 )
            break;
          ++m;
        }
        operator delete(v3->attackingUnitsValue.value);
        v3->attackingUnitsValue.value = v9;
        v3->attackingUnitsValue.maximumSizeValue = a2;
      }
    }
    v3->attackingUnitsValue.value[v3->attackingUnitsValue.numberValue++] = (int)l;
LABEL_20:
    ;
  }
  rge_read(a2, v4, v4, &tempInt, 4);
  if( tempInt == 1 )
  {
    v11 = (AIPlayStatus *)operator new(0x1C8u);
    l = v11;
    v20 = 0;
    if( v11 )
      AIPlayStatus::AIPlayStatus(v11);
    else
      v12 = 0;
    v20 = -1;
    v3->playStatus = v12;
    AIPlayStatus::load(v12, a2, v4);
  }
  if( save_game_version >= 7.02 )
    rge_read(a2, v4, v4, &v3->stopAfterTargetKilledValue, 1);
}
// 58EBCC: using guessed type float save_game_version;

//----- (00413810) --------------------------------------------------------
RGE_Player *__thiscall UnitAIModule::owner(UnitAIModule *this)
{
  return this->objectValue->owner;
}

//----- (00413820) --------------------------------------------------------
RGE_Static_Object *__thiscall UnitAIModule::object(UnitAIModule *this)
{
  return this->objectValue;
}

//----- (00413830) --------------------------------------------------------
int __thiscall UnitAIModule::objectID(UnitAIModule *this)
{
  return this->objectValue->id;
}

//----- (00413840) --------------------------------------------------------
int __thiscall UnitAIModule::objectCategory(UnitAIModule *this)
{
  return this->objectCategoryValue;
}

//----- (00413850) --------------------------------------------------------
int __thiscall UnitAIModule::mood(UnitAIModule *this)
{
  return this->moodValue;
}

//----- (00413860) --------------------------------------------------------
unsigned int __thiscall UnitAIModule::lastUpdateTime(UnitAIModule *this)
{
  return this->lastUpdateTimeValue;
}

//----- (00413870) --------------------------------------------------------
unsigned int __thiscall UnitAIModule::idleTimer(UnitAIModule *this)
{
  return this->idleTimerValue;
}

//----- (00413880) --------------------------------------------------------
unsigned int __thiscall UnitAIModule::idleTimeout(UnitAIModule *this)
{
  return this->idleTimeoutValue;
}

//----- (00413890) --------------------------------------------------------
unsigned int __thiscall UnitAIModule::secondaryTimer(UnitAIModule *this)
{
  return this->secondaryTimerValue;
}

//----- (004138A0) --------------------------------------------------------
double __thiscall UnitAIModule::defenseBuffer(UnitAIModule *this)
{
  return this->defenseBufferValue;
}

//----- (004138B0) --------------------------------------------------------
int __stdcall UnitAIModule::canConvert(int __formal)
{
  return 0;
}

//----- (004138C0) --------------------------------------------------------
void __thiscall UnitAIModule::setDefenseBuffer(UnitAIModule *this, float v)
{
  this->defenseBufferValue = v;
}

//----- (004138D0) --------------------------------------------------------
int __thiscall UnitAIModule::orderQueueSize(UnitAIModule *this)
{
  return this->orderQueueSizeValue;
}

//----- (004138E0) --------------------------------------------------------
OrderEvent *__thiscall UnitAIModule::orderQueueElement(UnitAIModule *this, int v)
{
  OrderEvent *v2; // eax@3
  OrderEvent *result; // eax@4

  if( v >= 0 && v < this->orderQueueSizeValue && (v2 = this->orderQueueValue) != 0 )
    result = &v2[v];
  else
    result = 0;
  return result;
}

//----- (00413910) --------------------------------------------------------
void __thiscall UnitAIModule::purgeOrderQueue(UnitAIModule *this)
{
  this->orderQueueSizeValue = 0;
}

//----- (00413920) --------------------------------------------------------
int __thiscall UnitAIModule::currentOrder(UnitAIModule *this)
{
  return this->currentOrderValue;
}

//----- (00413930) --------------------------------------------------------
void __thiscall UnitAIModule::setCurrentOrder(UnitAIModule *this, int v)
{
  this->lastOrderValue = this->currentOrderValue;
  this->currentOrderValue = v;
}

//----- (00413940) --------------------------------------------------------
int __thiscall UnitAIModule::currentOrderPriority(UnitAIModule *this)
{
  return this->currentOrderPriorityValue;
}

//----- (00413950) --------------------------------------------------------
void __thiscall UnitAIModule::setCurrentOrderPriority(UnitAIModule *this, int v)
{
  this->currentOrderPriorityValue = v;
}

//----- (00413960) --------------------------------------------------------
int __thiscall UnitAIModule::currentAction(UnitAIModule *this)
{
  return this->currentActionValue;
}

//----- (00413970) --------------------------------------------------------
void __thiscall UnitAIModule::setCurrentAction(UnitAIModule *this, int v)
{
  this->lastActionValue = this->currentActionValue;
  this->currentActionValue = v;
}

//----- (00413980) --------------------------------------------------------
int __thiscall UnitAIModule::currentTarget(UnitAIModule *this)
{
  return this->currentTargetValue;
}

//----- (00413990) --------------------------------------------------------
int __thiscall UnitAIModule::currentTargetType(UnitAIModule *this)
{
  return this->currentTargetTypeValue;
}

//----- (004139A0) --------------------------------------------------------
double __thiscall UnitAIModule::currentTargetX(UnitAIModule *this)
{
  return this->currentTargetXValue;
}

//----- (004139B0) --------------------------------------------------------
double __thiscall UnitAIModule::currentTargetY(UnitAIModule *this)
{
  return this->currentTargetYValue;
}

//----- (004139C0) --------------------------------------------------------
double __thiscall UnitAIModule::currentTargetZ(UnitAIModule *this)
{
  return this->currentTargetZValue;
}

//----- (004139D0) --------------------------------------------------------
int __thiscall UnitAIModule::lastAction(UnitAIModule *this)
{
  return this->lastActionValue;
}

//----- (004139E0) --------------------------------------------------------
int __thiscall UnitAIModule::lastOrder(UnitAIModule *this)
{
  return this->lastOrderValue;
}

//----- (004139F0) --------------------------------------------------------
int __thiscall UnitAIModule::lastTarget(UnitAIModule *this)
{
  return this->lastTargetValue;
}

//----- (00413A00) --------------------------------------------------------
int __thiscall UnitAIModule::lastTargetType(UnitAIModule *this)
{
  return this->lastTargetTypeValue;
}

//----- (00413A10) --------------------------------------------------------
double __thiscall UnitAIModule::desiredTargetDistance(UnitAIModule *this)
{
  return this->desiredTargetDistanceValue;
}

//----- (00413A20) --------------------------------------------------------
int __thiscall UnitAIModule::attackingUnitID(UnitAIModule *this, int v)
{
  UnitAIModule *v2; // esi@1
  int v3; // ebx@4
  int *v4; // edi@4
  int i; // eax@5
  int result; // eax@9

  v2 = this;
  if( v < 0 || v >= this->attackingUnitsValue.numberValue )
  {
    result = -1;
  }
  else
  {
    if( v > this->attackingUnitsValue.maximumSizeValue - 1 )
    {
      v3 = v + 1;
      v4 = (int *)operator new(4 * (v + 1));
      if( v4 )
      {
        for( i = 0; i < v2->attackingUnitsValue.maximumSizeValue; v4[i - 1] = v2->attackingUnitsValue.value[i - 1] )
        {
          if( i >= v3 )
            break;
          ++i;
        }
        operator delete(v2->attackingUnitsValue.value);
        v2->attackingUnitsValue.value = v4;
        v2->attackingUnitsValue.maximumSizeValue = v3;
      }
    }
    result = v2->attackingUnitsValue.value[v];
  }
  return result;
}

//----- (00413AA0) --------------------------------------------------------
int __thiscall UnitAIModule::numberAttackingUnits(UnitAIModule *this)
{
  return this->attackingUnitsValue.numberValue;
}

//----- (00413AB0) --------------------------------------------------------
int __userpurge UnitAIModule::update@<eax>(UnitAIModule *this@<ecx>, double a2@<st0>, unsigned int uTime)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // eax@6
  RGE_Static_Object *v5; // ebx@6
  int v6; // eax@7
  RGE_Static_Object *v7; // eax@9
  signed int v8; // eax@10
  UnitAIModuleVtbl *v9; // edi@16
  int v10; // eax@17
  bool v11; // zf@18
  int v12; // eax@18
  float v13; // ST10_4@20
  RGE_Static_Object *v14; // eax@22
  int v15; // ecx@25
  RGE_Static_Object *v16; // eax@29
  signed int v17; // eax@30
  signed int v18; // eax@35
  signed __int64 v19; // rax@37
  int v20; // ebp@43
  int v21; // ebx@45
  int *v22; // edi@45
  int i; // eax@46
  RGE_Static_Object *v24; // eax@50
  RGE_Static_Object *v25; // edi@50
  UnitAIModule *v26; // eax@53
  int v27; // ebx@57
  int *v28; // edi@57
  int j; // eax@58
  int v30; // ecx@62
  int v31; // ebp@62
  int v32; // eax@62
  int *v33; // edx@63
  int v34; // eax@69
  RGE_Static_Object *v35; // eax@71
  unsigned int v36; // ebp@71
  int v37; // ebx@71
  unsigned int v38; // edi@71
  float v39; // edx@71
  unsigned int v40; // ecx@71
  int v41; // eax@71
  unsigned int v42; // edx@71
  int v43; // edi@72
  int v44; // eax@73
  RGE_Static_Object *v45; // eax@79
  int v46; // edx@79
  int v48; // edi@84
  int v49; // ebp@85
  int (__thiscall *v50)(UnitAIModule *, OrderEvent *, int); // ebx@85
  UnitAIModuleVtbl *v51; // edi@88
  int haveGameAction; // [sp+24h] [bp-4h]@2
  int (__thiscall *uTimea)(UnitAIModule *, NotifyEvent *, unsigned int); // [sp+2Ch] [bp+4h]@72

  v3 = this;
  if( this->objectValue->object_state > 2u )
    return 1;
  taskedThisUpdate = 0;
  searchedThisUpdate = 0;
  numberVisibleObjects = 0;
  numberDifferentPlayerObjectsVisible = 0;
  haveGameAction = RGE_Action_List::have_action((RGE_Action_List *)this->objectValue[2].unitAIValue);
  if( !haveGameAction && (unsigned __int8)((int (*)(void))v3->objectValue->vfptr->waitingToMove)() == 1 )
    ((void (__stdcall *)(_DWORD))v3->objectValue->vfptr->setWaitingToMove)(0);
  if( v3->currentTargetValue != -1 )
  {
    v4 = UnitAIModule::lookupObject(v3, v3->currentTargetValue);
    v5 = v4;
    if( !v4 )
    {
      v6 = v3->currentActionValue;
      v3->currentTargetValue = -1;
      if( v6 == 600 )
      {
        UnitAIModule::removeCurrentTarget(v3);
        if( actionFile )
        {
          v7 = v3->objectValue;
          if( v7 )
            v8 = v7->id;
          else
            v8 = -1;
          fprintf(actionFile, aDCallStopobjec, v8, aCMsdevWorkA_43, 774);
        }
        v3->vfptr->stopObject(v3, 1);
        v3->idleTimerValue = v3->idleTimeoutValue;
      }
      goto LABEL_40;
    }
    if( v3->objectValue->object_state != 2 )
      goto LABEL_34;
    if( v4->object_state <= 2u )
      goto LABEL_34;
    v9 = v3->vfptr;
    if( v3->vfptr->actionRequiresLiveTarget(v3, v3->currentActionValue) != 1 )
      goto LABEL_34;
    v10 = v3->currentActionValue;
    v3->stopAfterTargetKilledValue = 0;
    if( v10 == 600 )
    {
      v11 = v9->processIdle(v3, 0) == 5;
      v12 = v3->currentOrderValue;
      if( !v11 )
      {
        if( v12 != 725 )
        {
          v3->lastOrderValue = v12;
          v3->currentOrderValue = -1;
          v3->currentOrderPriorityValue = -1;
        }
        goto LABEL_34;
      }
      if( v12 != 725 )
      {
        ((void (__stdcall *)(signed int))v3->objectValue->vfptr->weaponRange)(1);
        v13 = a2;
        if( !(*(int (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD))&v9->gap90[0])(
                v3,
                LODWORD(v3->currentTargetXValue),
                LODWORD(v3->currentTargetYValue),
                LODWORD(v3->currentTargetZValue),
                LODWORD(v13)) )
        {
          UnitAIModule::removeCurrentTarget(v3);
          if( actionFile )
          {
            v14 = v3->objectValue;
            if( v14 )
              fprintf(actionFile, aDCallStopobjec, v14->id, aCMsdevWorkA_43, 821);
            else
              fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_43, 821);
          }
LABEL_33:
          v9->stopObject(v3, 1);
          goto LABEL_34;
        }
        v15 = v3->currentOrderValue;
        v3->currentOrderValue = -1;
        v3->lastOrderValue = v15;
        v3->currentOrderPriorityValue = -1;
      }
LABEL_34:
      if( RGE_Player::computerPlayer(v3->objectValue->owner) == 1 )
      {
        v18 = v3->currentOrderPriorityValue;
        if( v18 != -1 && v18 < 100 )
        {
          v19 = (signed __int64)(100.0 / RGE_Static_Object::distance_to_object(v3->objectValue, v5));
          if( (signed int)v19 > 99 )
            LODWORD(v19) = 99;
          v3->currentOrderPriorityValue = v19;
        }
      }
      goto LABEL_40;
    }
    UnitAIModule::removeCurrentTarget(v3);
    if( actionFile )
    {
      v16 = v3->objectValue;
      if( v16 )
        v17 = v16->id;
      else
        v17 = -1;
      fprintf(actionFile, aDCallStopobjec, v17, aCMsdevWorkA_43, 854);
    }
    goto LABEL_33;
  }
LABEL_40:
  if( v3->attackingUnitsValue.numberValue || !(unsigned __int8)((int (*)(void))v3->objectValue->vfptr->underAttack)() )
  {
    v20 = 0;
    if( v3->attackingUnitsValue.numberValue > 0 )
    {
      while( 1 )
      {
        if( v20 > v3->attackingUnitsValue.maximumSizeValue - 1 )
        {
          v21 = v20 + 1;
          v22 = (int *)operator new(4 * v20 + 4);
          if( v22 )
          {
            for( i = 0; i < v3->attackingUnitsValue.maximumSizeValue; v22[i - 1] = v3->attackingUnitsValue.value[i - 1] )
            {
              if( i >= v21 )
                break;
              ++i;
            }
            operator delete(v3->attackingUnitsValue.value);
            v3->attackingUnitsValue.value = v22;
            v3->attackingUnitsValue.maximumSizeValue = v21;
          }
        }
        v24 = UnitAIModule::lookupObject(v3, v3->attackingUnitsValue.value[v20]);
        v25 = v24;
        if( !v24 )
          break;
        if( !RGE_Static_Object::unitAI(v24) )
          break;
        if( v25->object_state > 2u )
          break;
        v26 = RGE_Static_Object::unitAI(v25);
        if( UnitAIModule::currentTarget(v26) != v3->objectValue->id )
          break;
        if( ++v20 >= v3->attackingUnitsValue.numberValue )
          goto LABEL_71;
      }
      if( v20 > v3->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v27 = v20 + 1;
        v28 = (int *)operator new(4 * (v20 + 1));
        if( v28 )
        {
          for( j = 0; j < v3->attackingUnitsValue.maximumSizeValue; v28[j - 1] = v3->attackingUnitsValue.value[j - 1] )
          {
            if( j >= v27 )
              break;
            ++j;
          }
          operator delete(v3->attackingUnitsValue.value);
          v3->attackingUnitsValue.value = v28;
          v3->attackingUnitsValue.maximumSizeValue = v27;
        }
      }
      v30 = v3->attackingUnitsValue.maximumSizeValue;
      v31 = v3->attackingUnitsValue.value[v20];
      v32 = 0;
      if( v30 > 0 )
      {
        v33 = v3->attackingUnitsValue.value;
        do
        {
          if( *v33 == v31 )
            break;
          ++v32;
          ++v33;
        }
        while( v32 < v30 );
      }
      if( v32 < v30 )
      {
        if( v32 < v30 - 1 )
        {
          do
          {
            ++v32;
            v3->attackingUnitsValue.value[v32 - 1] = v3->attackingUnitsValue.value[v32];
          }
          while( v32 < v3->attackingUnitsValue.maximumSizeValue - 1 );
        }
        v34 = v3->attackingUnitsValue.numberValue - 1;
        v3->attackingUnitsValue.numberValue = v34;
        if( v34 < 0 )
          v3->attackingUnitsValue.numberValue = 0;
      }
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->objectValue->vfptr->setUnderAttack)(0);
  }
LABEL_71:
  v35 = v3->objectValue;
  v36 = uTime;
  v37 = 0;
  v38 = uTime + v3->idleTimerValue;
  v3->lastWorldPositionValue.x = v35->world_x;
  v3->lastWorldPositionValue.y = v35->world_y;
  v39 = v35->world_z;
  v40 = v3->lookAroundTimerValue;
  v41 = v3->notifyQueueSizeValue;
  v3->lastWorldPositionValue.z = v39;
  v42 = uTime + v3->secondaryTimerValue;
  v3->idleTimerValue = v38;
  v3->secondaryTimerValue = v42;
  v3->lookAroundTimerValue = uTime + v40;
  if( v41 <= 0 )
  {
LABEL_76:
    UnitAIModule::purgeNotifyQueue(v3, v36);
    if( !haveGameAction )
    {
      switch ( v3->currentActionValue )
      {
        case 0x258:
        case 0x261:
        case 0x262:
        case 0x265:
        case 0x26B:
        case 0x26C:
          v3->currentActionValue = -1;
          break;
        default:
          break;
      }
    }
    v45 = v3->objectValue;
    v46 = v3->currentOrderValue;
    if( v45->object_state > 2u )
      return 0;
    if( v45->groupCommanderValue == v45->id )
      UnitAIModule::updateGroup(v3, v36);
    if( v3->currentActionValue == -1 )
    {
      v48 = 0;
      if( v3->orderQueueSizeValue > 0 )
      {
        v49 = 0;
        v50 = v3->vfptr->processOrder;
        do
        {
          if( v50(v3, &v3->orderQueueValue[v49], v48) == 1 )
            break;
          ++v48;
          ++v49;
        }
        while( v48 < v3->orderQueueSizeValue );
      }
    }
    v51 = v3->vfptr;
    v3->vfptr->processMisc(v3);
    if( v3->idleTimerValue > v3->adjustedIdleTimeoutValue )
    {
      if( v3->currentActionValue != -1 )
        goto LABEL_94;
      if( v3->currentTargetValue == -1 )
      {
        v3->idleTimerValue = 0;
        v51->processIdle(v3, 1);
        goto LABEL_95;
      }
    }
    if( v3->currentActionValue == -1 && v3->currentTargetValue == -1 )
    {
LABEL_95:
      if( RGE_Player::computerPlayer(v3->objectValue->owner) == 1
        && v3->lookAroundTimerValue > v3->lookAroundTimeoutValue )
      {
        UnitAIModule::lookAround(v3);
      }
      return 1;
    }
LABEL_94:
    v3->idleTimerValue = 0;
    goto LABEL_95;
  }
  v43 = 0;
  uTimea = v3->vfptr->processNotify;
  while( 1 )
  {
    v44 = uTimea(v3, &v3->notifyQueueValue[v43], v36);
    if( v44 == 4 )
      break;
    if( v44 != 3 )
    {
      ++v37;
      ++v43;
      if( v37 < v3->notifyQueueSizeValue )
        continue;
    }
    goto LABEL_76;
  }
  UnitAIModule::purgeNotifyQueue(v3, v36);
  return 0;
}
// 592A48: using guessed type int taskedThisUpdate;
// 592A4C: using guessed type int searchedThisUpdate;
// 592A50: using guessed type int numberVisibleObjects;
// 592A54: using guessed type int numberDifferentPlayerObjectsVisible;

//----- (00414040) --------------------------------------------------------
void __thiscall UnitAIModule::updateGroup(UnitAIModule *this, unsigned int uTime)
{
  UnitAIModule *v2; // esi@1
  AIPlayStatus *v3; // eax@1
  AIPlay *v4; // edi@2
  int v5; // eax@4
  RGE_Static_Object *v6; // edi@4
  int v7; // ebx@4
  int v8; // ebp@4
  int v9; // ecx@6
  int v10; // edi@6
  _DWORD *v11; // ebx@7
  int j; // eax@8
  RGE_Static_Object *v13; // eax@12
  ManagedArray<int> *v14; // edi@13
  RGE_Static_Object *v15; // eax@15
  RGE_Static_Object *v16; // edi@15
  UnitAIModule *v17; // eax@17
  AIPlayStatus *v18; // ecx@22
  RGE_Static_Object *v19; // edi@23
  int v20; // ebp@23
  int v21; // eax@23
  int *v22; // ebx@26
  int k; // eax@27
  RGE_Static_Object *v24; // ebx@31
  int v25; // edi@32
  int (__thiscall *v26)(RGE_Static_Object *, XYZBYTEPoint *, int); // ebp@33
  int v27; // eax@34
  int *v28; // edi@38
  RGE_Static_Object *v29; // ebp@39
  int *v30; // ebx@39
  bool v31; // zf@39
  int v32; // edi@40
  int *v33; // ebx@40
  AIPlayPhase *v34; // eax@43
  int v35; // ecx@44
  AIPlayPhase *v36; // eax@46
  AIPlayPhase *v37; // ebx@46
  signed int v38; // edi@46
  int v39; // ebp@49
  int v40; // eax@51
  AIPlayPhaseCommand *v41; // ebx@52
  signed int v42; // edi@52
  int v43; // eax@54
  RGE_Static_Object *v44; // eax@55
  float gatherDistance; // ST38_4@56
  float z; // ST14_4@56
  float y; // ST10_4@56
  float x; // ST0C_4@56
  signed int v49; // ebx@61
  signed int v50; // edi@61
  int v51; // eax@62
  RGE_Static_Object *v52; // eax@63
  int v53; // ebx@70
  signed int v54; // edi@70
  int v55; // eax@71
  RGE_Static_Object *v56; // eax@72
  int v57; // edi@75
  int v58; // ebx@75
  signed int v59; // ebp@77
  int v60; // eax@79
  RGE_Static_Object *v61; // eax@80
  signed int v62; // ebx@85
  int v63; // eax@87
  RGE_Static_Object *v64; // eax@88
  bool v65; // sf@98
  unsigned __int8 v66; // of@98
  int triggerSatisfied; // [sp+28h] [bp-FCh]@23
  int triggerSatisfieda; // [sp+28h] [bp-FCh]@48
  int deadCount; // [sp+2Ch] [bp-F8h]@4
  int *deadCounta; // [sp+2Ch] [bp-F8h]@24
  int deadCountb; // [sp+2Ch] [bp-F8h]@38
  int deadCountc; // [sp+2Ch] [bp-F8h]@61
  AIPlayPhaseTrigger *trigger; // [sp+30h] [bp-F4h]@23
  AIPlayPhaseTrigger *triggera; // [sp+30h] [bp-F4h]@46
  AIPlay *play; // [sp+34h] [bp-F0h]@2
  AIPlayPhase *phase; // [sp+3Ch] [bp-E8h]@43
  RGE_Static_Object *target; // [sp+40h] [bp-E4h]@3
  int i; // [sp+44h] [bp-E0h]@44
  int totalHitPoints[5]; // [sp+48h] [bp-DCh]@23
  int groupList[50]; // [sp+5Ch] [bp-C8h]@24

  v2 = this;
  v3 = this->playStatus;
  if( v3 )
  {
    v4 = AIPlayBook::play(this->objectValue->owner->world->playbook, v3->playNumberValue);
    play = v4;
    if( v4 )
    {
      target = UnitAIModule::lookupObject(v2, v2->playStatus->targetValue);
      if( !target )
      {
        v5 = v2->vfptr->bestUnitToAttack(v2, 1, 0, 0);
        v6 = v2->objectValue;
        v7 = v5;
        v8 = 0;
        deadCount = v5;
        if( v6->groupMembers.numberValue <= 0 )
        {
LABEL_20:
          if( v7 == -1 )
          {
            operator delete(v2->playStatus);
            v2->playStatus = 0;
            return;
          }
        }
        else
        {
          while( v7 == -1 )
          {
            v9 = v6->groupMembers.maximumSizeValue;
            v10 = (int)&v6->groupMembers;
            if( v8 > v9 - 1 )
            {
              v11 = operator new(4 * v8 + 4);
              if( v11 )
              {
                for( j = 0; j < *(_DWORD *)(v10 + 12); v11[j - 1] = *(_DWORD *)(*(_DWORD *)v10 + 4 * j - 4) )
                {
                  if( j >= v8 + 1 )
                    break;
                  ++j;
                }
                operator delete(*(void **)v10);
                *(_DWORD *)v10 = v11;
                *(_DWORD *)(v10 + 12) = v8 + 1;
              }
            }
            v13 = v2->objectValue;
            if( *(_DWORD *)(*(_DWORD *)v10 + 4 * v8) == v13->id )
              goto LABEL_104;
            v14 = &v13->groupMembers;
            if( v8 > v13->groupMembers.maximumSizeValue - 1 )
              ManagedArray<int>::resize(v14, v8 + 1);
            v15 = UnitAIModule::lookupObject(v2, v14->value[v8]);
            v16 = v15;
            if( v15 && RGE_Static_Object::unitAI(v15) )
            {
              v17 = RGE_Static_Object::unitAI(v16);
              v7 = v17->vfptr->bestUnitToAttack(v17, 1, 0, 0);
              deadCount = v7;
            }
            else
            {
LABEL_104:
              v7 = deadCount;
            }
            v6 = v2->objectValue;
            if( ++v8 >= v6->groupMembers.numberValue )
              goto LABEL_20;
          }
        }
        v2->playStatus->targetValue = v7;
        UnitAIModule::selectNewPlayPhase(v2, v2->playStatus->currentPhaseValue, 0);
        v4 = play;
        target = UnitAIModule::lookupObject(v2, v7);
      }
      v18 = v2->playStatus;
      if( v18->currentPhaseValue == -3 )
      {
        v19 = v2->objectValue;
        totalHitPoints[0] = 0;
        v20 = 0;
        v21 = v19->groupMembers.numberValue;
        totalHitPoints[1] = 0;
        totalHitPoints[2] = 0;
        totalHitPoints[3] = 0;
        trigger = 0;
        totalHitPoints[4] = 0;
        triggerSatisfied = 0;
        if( v21 > 0 )
        {
          deadCounta = groupList;
          do
          {
            if( v20 > v19->groupMembers.maximumSizeValue - 1 )
            {
              v22 = (int *)operator new(4 * v20 + 4);
              if( v22 )
              {
                for( k = 0; k < v19->groupMembers.maximumSizeValue; v22[k - 1] = v19->groupMembers.value[k - 1] )
                {
                  if( k >= v20 + 1 )
                    break;
                  ++k;
                }
                operator delete(v19->groupMembers.value);
                v19->groupMembers.value = v22;
                v19->groupMembers.maximumSizeValue = v20 + 1;
              }
            }
            v24 = UnitAIModule::lookupObject(v2, v19->groupMembers.value[v20]);
            if( v24 )
            {
              *deadCounta = v24->id;
              trigger = (AIPlayPhaseTrigger *)((char *)trigger + 1);
              ++deadCounta;
              v25 = 0;
              if( ((int (*)(void))v2->objectValue->vfptr->numberUserDefinedWaypoints)() > 0 )
              {
                v26 = v24->vfptr->addUserDefinedWaypoint;
                do
                {
                  v27 = ((int (__stdcall *)(int, signed int))v2->objectValue->vfptr->userDefinedWaypoint)(v25, 1);
                  ((void (__thiscall *)(RGE_Static_Object *, int))v26)(v24, v27);
                  ++v25;
                }
                while( v25 < ((int (*)(void))v2->objectValue->vfptr->numberUserDefinedWaypoints)() );
                v20 = triggerSatisfied;
              }
            }
            v19 = v2->objectValue;
            triggerSatisfied = ++v20;
          }
          while( v20 < v19->groupMembers.numberValue );
        }
        v2->playStatus->lastPhaseChangeTimeValue = v2->objectValue->owner->world->world_time;
        AIPlay::fillGroups(play, v2->playStatus, groupList, (int)trigger, v2->objectValue->owner->world);
        if( (signed int)trigger > 0 )
        {
          v28 = groupList;
          deadCountb = (int)trigger;
          do
          {
            v29 = UnitAIModule::lookupObject(v2, *v28);
            v30 = &totalHitPoints[(unsigned __int8)AIPlayStatus::group(v2->playStatus, *v28)];
            ++v28;
            v31 = deadCountb == 1;
            *v30 += (signed __int64)v29->hp;
            --deadCountb;
          }
          while( !v31 );
        }
        v32 = 0;
        v33 = totalHitPoints;
        do
        {
          AIPlayStatus::setOriginalHitPoints(v2->playStatus, v32++, *v33);
          ++v33;
        }
        while( v32 < 5 );
        UnitAIModule::selectNewPlayPhase(v2, 0, 0);
      }
      else
      {
        v34 = AIPlay::phase(v4, v18->currentPhaseValue);
        phase = v34;
        if( v34 )
        {
          v35 = 0;
          i = 0;
          while( 1 )
          {
            v36 = AIPlayPhase::trigger(v34, v35);
            v37 = v36;
            v38 = 0;
            triggera = (AIPlayPhaseTrigger *)v36;
            if( v36 )
            {
              if( v36->commands[0].groupValue )
              {
                triggerSatisfieda = 0;
                switch ( v36->commands[0].groupValue )
                {
                  case 1:
                    triggerSatisfieda = 1;
                    v39 = 0;
                    do
                    {
                      if( !triggerSatisfieda )
                        break;
                      v40 = AIPlay::groupGivenCommandOnPhase(play, v39, 1, v2->playStatus->currentPhaseValue);
                      if( v40 != -1 )
                      {
                        v41 = AIPlayPhase::command(phase, v40);
                        v42 = 0;
                        do
                        {
                          if( !triggerSatisfieda )
                            break;
                          v43 = (int)v2->playStatus + v42;
                          if( *(_BYTE *)(v43 + 4) == v39 )
                          {
                            v44 = UnitAIModule::lookupObject(v2, *(_DWORD *)v43);
                            if( v44 )
                            {
                              gatherDistance = *(float *)&v41->value2Value;
                              z = (double)SLODWORD(gatherDistance) + target->world_z;
                              y = (double)SLODWORD(gatherDistance) + target->world_y;
                              x = (double)v41->value1Value + target->world_x;
                              if( RGE_Static_Object::distance_to_position(v44, x, y, z) > (double)triggera->value1Value )
                                triggerSatisfieda = 0;
                            }
                          }
                          v42 += 8;
                        }
                        while( v42 < 400 );
                      }
                      ++v39;
                    }
                    while( v39 < 5 );
                    break;
                  case 2:
                    v49 = 0;
                    v50 = 0;
                    deadCountc = 0;
                    do
                    {
                      v51 = (int)v2->playStatus + v50;
                      if( *(_BYTE *)(v51 + 4) == triggera->value1Value )
                      {
                        ++v49;
                        v52 = UnitAIModule::lookupObject(v2, *(_DWORD *)v51);
                        if( !v52 || v52->object_state > 2u )
                          ++deadCountc;
                      }
                      v50 += 8;
                    }
                    while( v50 < 400 );
                    if( !v49 )
                      goto LABEL_94;
                    if( triggera->value2Value <= 100 * deadCountc / v49 )
                      triggerSatisfieda = 1;
                    break;
                  case 3:
                    v53 = 0;
                    v54 = 0;
                    do
                    {
                      v55 = (int)v2->playStatus + v54;
                      if( *(_BYTE *)(v55 + 4) == triggera->value1Value )
                      {
                        v56 = UnitAIModule::lookupObject(v2, *(_DWORD *)v55);
                        if( v56 )
                          v53 += (signed __int64)v56->hp;
                      }
                      v54 += 8;
                    }
                    while( v54 < 400 );
                    v57 = AIPlayStatus::originalHitPoints(v2->playStatus, triggera->value1Value) - v53;
                    v58 = triggera->value2Value;
                    if( v58 <= 100 * v57 / AIPlayStatus::originalHitPoints(v2->playStatus, triggera->value1Value) )
                      triggerSatisfieda = 1;
                    break;
                  case 8:
                    v59 = 1;
                    do
                    {
                      if( !v59 )
                        break;
                      v60 = (int)v2->playStatus + v38;
                      if( *(_BYTE *)(v60 + 4) == v37->commands[0].value1Value )
                      {
                        v61 = UnitAIModule::lookupObject(v2, *(_DWORD *)v60);
                        if( v61 )
                        {
                          if( v61->object_state == 2 )
                            v59 = 0;
                        }
                      }
                      v38 += 8;
                    }
                    while( v38 < 400 );
                    triggerSatisfieda = v59;
                    break;
                  case 9:
                    triggerSatisfieda = 1;
                    v62 = 0;
                    do
                    {
                      if( !triggerSatisfieda )
                        break;
                      v63 = (int)v2->playStatus + v62;
                      if( *(_BYTE *)(v63 + 4) == triggera->value1Value )
                      {
                        v64 = UnitAIModule::lookupObject(v2, *(_DWORD *)v63);
                        if( v64 )
                        {
                          if( (signed __int64)v64->hp < v64->master_obj->hp )
                            triggerSatisfieda = 0;
                        }
                      }
                      v62 += 8;
                    }
                    while( v62 < 400 );
                    break;
                  case 0xB:
                    if( (signed int)(v2->objectValue->owner->world->world_time
                                    - v2->playStatus->lastPhaseChangeTimeValue)
                       / 1000 > v36->commands[0].value1Value )
                      goto LABEL_94;
                    break;
                  case 0xA:
LABEL_94:
                    triggerSatisfieda = 1;
                    break;
                  default:
                    break;
                }
                if( triggerSatisfieda == 1 && UnitAIModule::selectNewPlayPhase(v2, triggera->nextPhaseValue, 0) == 1 )
                  break;
              }
            }
            v35 = i + 1;
            v66 = __OFSUB__(i + 1, 3);
            v65 = i++ - 2 < 0;
            if( !(v65 ^ v66) )
            {
              UnitAIModule::selectNewPlayPhase(v2, v2->playStatus->currentPhaseValue, 1);
              return;
            }
            v34 = phase;
          }
        }
      }
    }
  }
}

//----- (004147A0) --------------------------------------------------------
int *__thiscall ManagedArray<int>::resize(ManagedArray<int> *this, int s)
{
  ManagedArray<int> *v2; // esi@1
  int *result; // eax@1
  int *v4; // edi@1
  int i; // eax@2

  v2 = this;
  result = (int *)operator new(4 * s);
  v4 = result;
  if( result )
  {
    for( i = 0; i < v2->maximumSizeValue; v4[i - 1] = v2->value[i - 1] )
    {
      if( i >= s )
        break;
      ++i;
    }
    operator delete(v2->value);
    v2->value = v4;
    v2->maximumSizeValue = s;
    result = (int *)1;
  }
  return result;
}

//----- (00414800) --------------------------------------------------------
int __thiscall UnitAIModule::selectNewPlayPhase(UnitAIModule *this, int newPhase, int pickup)
{
  UnitAIModule *v3; // esi@1
  int v4; // ebp@1
  AIPlayStatus *v5; // eax@1
  AIPlay *v7; // eax@3
  AIPlayPhase *v8; // edi@7
  RGE_Static_Object *v9; // ebx@9
  AIPlayPhaseCommand *v10; // eax@13
  AIPlayPhaseCommand *v11; // edi@13
  char v12; // al@14
  int v13; // eax@18
  RGE_Static_Object *v14; // eax@22
  int v15; // ecx@22
  int **v16; // ebp@25
  RGE_Static_Object *v17; // eax@27
  RGE_Static_Object *v18; // ebp@27
  UnitAIModule *v19; // eax@31
  float z; // ST28_4@33
  float y; // ST24_4@33
  float x; // ST20_4@33
  RGE_Static_Object *member; // ST58_4@34
  signed int v24; // ST40_4@34
  UnitAIModule *v25; // eax@34
  UnitAIModuleVtbl *v26; // edx@34
  AIPlayStatus *v27; // eax@37
  int v28; // ST5C_4@37
  int v29; // ST60_4@37
  signed int v30; // edx@37
  signed int v31; // ST64_4@37
  signed int v32; // ST68_4@37
  signed int v33; // ST6C_4@37
  signed int v34; // ST74_4@37
  int v35; // ST70_4@37
  int v36; // ST78_4@37
  int v37; // ST7C_4@37
  int v38; // eax@38
  int v39; // eax@39
  RGE_Static_Object *v40; // eax@40
  bool v41; // sf@43
  unsigned __int8 v42; // of@43
  signed int v43; // ST40_4@48
  RGE_Static_Object *v44; // ST58_4@48
  signed int v45; // [sp-Ch] [bp-7Ch]@34
  signed int v46; // [sp-8h] [bp-78h]@34
  signed int v47; // [sp-4h] [bp-74h]@34
  float v48; // [sp+0h] [bp-70h]@34
  float v49; // [sp+4h] [bp-6Ch]@34
  float v50; // [sp+8h] [bp-68h]@34
  int a; // [sp+2Ch] [bp-44h]@22
  int v52; // [sp+30h] [bp-40h]@38
  RGE_Static_Object *target; // [sp+34h] [bp-3Ch]@9
  int i; // [sp+38h] [bp-38h]@11
  AIPlayPhase *phase; // [sp+3Ch] [bp-34h]@7
  AIPlay *play; // [sp+44h] [bp-2Ch]@3
  char newPhaseb; // [sp+74h] [bp+4h]@29
  int newPhasec; // [sp+74h] [bp+4h]@33
  int newPhased; // [sp+74h] [bp+4h]@34
  int newPhasee; // [sp+74h] [bp+4h]@36
  int newPhasea; // [sp+74h] [bp+4h]@38
  int newPhasef; // [sp+74h] [bp+4h]@48

  v3 = this;
  v4 = 0;
  v5 = this->playStatus;
  if( !v5 )
    return 0;
  v7 = AIPlayBook::play(this->objectValue->owner->world->playbook, v5->playNumberValue);
  play = v7;
  if( !v7 )
    return 0;
  if( newPhase == 254 )
  {
    operator delete(v3->playStatus);
    v3->playStatus = 0;
    return 1;
  }
  v8 = AIPlay::phase(v7, newPhase);
  phase = v8;
  if( !v8 )
    return 0;
  v9 = UnitAIModule::lookupObject(v3, v3->playStatus->targetValue);
  target = v9;
  if( !v9 )
    return 0;
  i = 0;
  v3->playStatus->currentPhaseValue = newPhase;
  while( 2 )
  {
    v10 = AIPlayPhase::command(v8, v4);
    v11 = v10;
    if( !v10 )
      goto LABEL_52;
    v12 = v10->typeValue;
    if( !v12 )
      goto LABEL_52;
    if( (v12 == 6 || v12 == 7) && !pickup )
    {
      v13 = (unsigned __int8)v12 - 6;
      if( v13 )
      {
        if( v13 == 1 )
          AIPlayStatus::removeDeadUnits(v3->playStatus, v11->groupValue, v3->objectValue->owner->world);
      }
      else
      {
        AIPlayStatus::resetHitPoints(v3->playStatus, v11->groupValue, v3->objectValue->owner->world);
      }
      goto LABEL_52;
    }
    v14 = v3->objectValue;
    v15 = 0;
    a = 0;
    if( v14->groupMembers.numberValue <= 0 )
      goto LABEL_52;
    while( 2 )
    {
      v16 = &v14->groupMembers.value;
      if( v15 > v14->groupMembers.maximumSizeValue - 1 )
      {
        ManagedArray<int>::resize(&v14->groupMembers, v15 + 1);
        v15 = a;
      }
      v17 = UnitAIModule::lookupObject(v3, (*v16)[v15]);
      v18 = v17;
      if( !v17 )
        goto LABEL_50;
      if( !RGE_Static_Object::unitAI(v17) )
        goto LABEL_50;
      newPhaseb = v11->groupValue;
      if( AIPlayStatus::group(v3->playStatus, v18->id) != newPhaseb )
        goto LABEL_50;
      if( pickup == 1 )
      {
        v19 = RGE_Static_Object::unitAI(v18);
        if( UnitAIModule::currentAction(v19) != -1 )
          goto LABEL_50;
      }
      switch ( v11->typeValue )
      {
        case 1:
          z = (double)v11->value3Value + v9->world_z;
          y = (double)v11->value2Value + v9->world_y;
          x = (double)v11->value1Value + v9->world_x;
          newPhasec = (signed __int64)RGE_Static_Object::distance_to_position(v18, x, y, z);
          if( newPhasec > AIPlay::gatherTolerance(play, v11->groupValue, v3->playStatus->currentPhaseValue) )
          {
            member = (RGE_Static_Object *)v11->value1Value;
            newPhased = v11->value3Value;
            v24 = v11->value2Value;
            v25 = RGE_Static_Object::unitAI(v18);
            v26 = v25->vfptr;
            v50 = (double)newPhased + v9->world_z;
            v49 = (double)v24 + v9->world_y;
            v48 = (double)(signed int)member + v9->world_x;
            v47 = -1;
            v46 = -1;
            v45 = 710;
            goto LABEL_49;
          }
          goto LABEL_50;
        case 2:
          v25 = RGE_Static_Object::unitAI(v18);
          v26 = v25->vfptr;
          v50 = -1.0;
          v49 = -1.0;
          v48 = -1.0;
          v47 = v9->owner->id;
          v46 = v9->id;
          v45 = 700;
          goto LABEL_49;
        case 3:
          newPhasee = v3->playStatus->savedAttackerValue;
          v25 = RGE_Static_Object::unitAI(v18);
          v26 = v25->vfptr;
          v50 = -1.0;
          v49 = -1.0;
          v48 = -1.0;
          v47 = -1;
          v46 = newPhasee;
          v45 = 700;
          goto LABEL_49;
        case 4:
          v27 = v3->playStatus;
          v28 = v27->originalPointValue.xValue;
          v29 = v27->originalPointValue.yValue;
          v30 = v27->originalPointValue.zValue;
          v27 = (AIPlayStatus *)((char *)v27 + 408);
          v31 = v30;
          v32 = v27->groupings[0].id;
          v33 = *(_DWORD *)&v27->groupings[0].groupID;
          v34 = v27->groupings[0].id;
          v35 = v27->groupings[1].id;
          v36 = *(_DWORD *)&v27->groupings[0].groupID;
          v37 = v27->groupings[1].id;
          v25 = RGE_Static_Object::unitAI(v18);
          v26 = v25->vfptr;
          v50 = (double)v31;
          v49 = (double)v33;
          v48 = (double)v34;
          v47 = -1;
          v46 = -1;
          v45 = 710;
          goto LABEL_49;
        case 5:
          v38 = 0;
          newPhasea = -1;
          v52 = 0;
          break;
        case 8:
          v43 = v11->value1Value;
          newPhasef = v11->value3Value;
          v44 = (RGE_Static_Object *)v11->value2Value;
          v25 = RGE_Static_Object::unitAI(v18);
          v26 = v25->vfptr;
          v50 = (double)newPhasef + v9->world_z;
          v49 = (double)(signed int)v44 + v9->world_y;
          v48 = (double)v43 + v9->world_x;
          v47 = -1;
          v46 = -1;
          v45 = 728;
          goto LABEL_49;
        default:
          goto LABEL_50;
      }
      while( 1 )
      {
        v39 = (int)v3->playStatus + v38;
        if( *(_BYTE *)(v39 + 4) != v11->value1Value )
          goto LABEL_43;
        v40 = UnitAIModule::lookupObject(v3, *(_DWORD *)v39);
        if( !v40 )
          goto LABEL_43;
        if( (signed int)((unsigned __int64)(signed __int64)v40->hp + 1) < v40->master_obj->hp )
          break;
        v9 = target;
LABEL_43:
        v38 = v52 + 8;
        v42 = __OFSUB__(v52 + 8, 400);
        v41 = v52 - 392 < 0;
        v52 += 8;
        if( !(v41 ^ v42) )
          goto LABEL_46;
      }
      v9 = target;
      newPhasea = v40->id;
LABEL_46:
      if( newPhasea != -1 )
      {
        v25 = RGE_Static_Object::unitAI(v18);
        v26 = v25->vfptr;
        v50 = -1.0;
        v49 = -1.0;
        v48 = -1.0;
        v47 = -1;
        v46 = newPhasea;
        v45 = 703;
LABEL_49:
        (*(void (__thiscall **)(UnitAIModule *, int, signed int, signed int, signed int, float, float, float, signed int, signed int, _DWORD, signed int))&v26->gap4[12])(
          v25,
          v3->objectValue->id,
          v45,
          v46,
          v47,
          COERCE_FLOAT(LODWORD(v48)),
          COERCE_FLOAT(LODWORD(v49)),
          COERCE_FLOAT(LODWORD(v50)),
          1065353216,
          1,
          0,
          100);
      }
LABEL_50:
      v14 = v3->objectValue;
      if( ++a < v14->groupMembers.numberValue )
      {
        v15 = a;
        continue;
      }
      break;
    }
    v4 = i;
LABEL_52:
    i = ++v4;
    if( v4 < 5 )
    {
      v8 = phase;
      continue;
    }
    return 1;
  }
}

//----- (00414D40) --------------------------------------------------------
int __thiscall UnitAIModule::order(UnitAIModule *this, int issuer, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority)
{
  UnitAIModule *v12; // esi@1
  RGE_Static_Object *v13; // eax@1
  RGE_Static_Object *v15; // eax@8
  signed int v16; // eax@9

  v12 = this;
  v13 = this->objectValue;
  if( v13->object_state <= 2u )
  {
    if( !immediate )
    {
      UnitAIModule::addToOrderQueue(
        this,
        issuer,
        orderType,
        target,
        targetOwner,
        targetX,
        targetY,
        targetZ,
        range,
        inFront,
        priority);
      return 1;
    }
    if( inFront == 1 )
      UnitAIModule::addToOrderQueue(
        this,
        v13->id,
        this->currentOrderValue,
        this->currentTargetValue,
        -1,
        this->currentTargetXValue,
        this->currentTargetYValue,
        this->currentTargetZValue,
        this->desiredTargetDistanceValue,
        1,
        this->currentOrderPriorityValue);
    UnitAIModule::addToOrderQueue(
      v12,
      issuer,
      orderType,
      target,
      targetOwner,
      targetX,
      targetY,
      targetZ,
      range,
      1,
      priority);
    if( orderType != 729 )
    {
      UnitAIModule::removeCurrentTarget(v12);
      if( actionFile )
      {
        v15 = v12->objectValue;
        if( v15 )
          v16 = v15->id;
        else
          v16 = -1;
        fprintf(actionFile, aDCallStopobjec, v16, aCMsdevWorkA_43, 1779);
      }
      v12->vfptr->stopObject(v12, 1);
    }
    UnitAIModule::purgeNotifyQueue(v12, 0);
    v12->vfptr->processOrder(v12, v12->orderQueueValue, 0);
  }
  return 1;
}

//----- (00414E80) --------------------------------------------------------
void *__thiscall UnitAIModule::notify(UnitAIModule *this, int callerID, int recipientID, int mType, int p1, int p2, int p3)
{
  void *result; // eax@2
  int v8; // edx@4
  int v9; // eax@4
  int v10; // eax@14

  if( this->objectValue->object_state != 2 )
    return 0;
  if( mType == 699 )
  {
    v8 = this->attackingUnitsValue.numberValue;
    v9 = 0;
    if( v8 > 0 )
    {
      while( v9 < this->attackingUnitsValue.maximumSizeValue )
      {
        if( this->attackingUnitsValue.value[v9] == callerID )
          goto LABEL_9;
        if( ++v9 >= v8 )
          return 0;
      }
    }
    return 0;
  }
LABEL_9:
  if( mType == 507 && p1 != this->currentActionValue )
    return 0;
  if( mType != 506 || p1 != 610 || (v10 = this->currentActionValue, v10 == 610) || v10 == 616 )
    result = UnitAIModule::addToNotifyQueue(this, callerID, recipientID, mType, p1, p2, p3);
  else
    result = (void *)1;
  return result;
}

//----- (00414F40) --------------------------------------------------------
int __thiscall UnitAIModule::notifyCommander(UnitAIModule *this, NotifyEvent *nEvent)
{
  return (*(int (__stdcall **)(int, int, int, int, int, int))&this->vfptr->gap4[20])(
           nEvent->caller,
           nEvent->recipient,
           nEvent->mType,
           nEvent->p1,
           nEvent->p2,
           nEvent->p3);
}

//----- (00414F70) --------------------------------------------------------
int __thiscall UnitAIModule::notifyCommander(UnitAIModule *this, int callerID, int recipientID, int mType, int p1, int p2, int p3)
{
  UnitAIModule *v7; // esi@1
  int v8; // eax@1
  int v9; // edi@1
  RGE_Static_Object *v10; // eax@2
  RGE_Static_Object *v11; // eax@4
  UnitAIModule *v12; // eax@6
  NotifyEvent nEvent; // [sp+10h] [bp-18h]@2
  RGE_Static_Object *p3a; // [sp+40h] [bp+18h]@4

  v7 = this;
  LOBYTE(v8) = RGE_Static_Object::inGroup(this->objectValue);
  v9 = p3;
  if( v8 == 1 )
  {
    nEvent.caller = callerID;
    v10 = v7->objectValue;
    nEvent.recipient = recipientID;
    nEvent.mType = mType;
    nEvent.p1 = p1;
    nEvent.p2 = p2;
    nEvent.p3 = p3;
    if( v10->id == v10->groupCommanderValue )
    {
      v7->vfptr->processGroupNotify(v7, &nEvent);
    }
    else
    {
      v11 = UnitAIModule::lookupObject(v7, v10->groupCommanderValue);
      p3a = v11;
      if( v11 && RGE_Static_Object::unitAI(v11) )
      {
        v12 = RGE_Static_Object::unitAI(p3a);
        v12->vfptr->processGroupNotify(v12, &nEvent);
      }
    }
  }
  ((void (__stdcall *)(int, int, int, int, int, int))v7->objectValue->owner->vfptr->notify)(
    callerID,
    recipientID,
    mType,
    p1,
    p2,
    v9);
  return 1;
}

//----- (00415040) --------------------------------------------------------
void __thiscall UnitAIModule::search(UnitAIModule *this)
{
  UnitAIModule *v1; // esi@1
  RGE_Static_Object *v2; // eax@5
  RGE_Static_Object *v3; // edi@5
  signed __int64 v4; // rax@7
  RGE_Master_Static_Object *v5; // ebx@8
  RGE_Player *v6; // ecx@10
  int v7; // [sp-10h] [bp-1Ch]@7
  int *v8; // [sp-Ch] [bp-18h]@7
  int v9; // [sp-8h] [bp-14h]@7
  int *v10; // [sp-4h] [bp-10h]@7

  v1 = this;
  if( searchedThisUpdate != 1 )
  {
    searchedThisUpdate = 1;
    if( this->importantObjects )
    {
      if( this->currentOrderValue == 701
        && this->defendTargetValue != -1
        && (v2 = UnitAIModule::lookupObject(this, this->defendTargetValue), (v3 = v2) != 0)
        && RGE_Static_Object::unitAI(v2) )
      {
        v10 = v1->objectValue->owner->unitDiplomacy;
        v9 = v1->numberImportantObjects;
        v8 = v1->importantObjects;
        v7 = v3->owner->id;
        v4 = (signed __int64)v3->master_obj->los;
      }
      else
      {
        v3 = v1->objectValue;
        v5 = v3->master_obj;
        v4 = (signed __int64)v5->los;
        if( v5->id == 118 )
          LODWORD(v4) = 2 * v4;
        v6 = v3->owner;
        v10 = v6->unitDiplomacy;
        v9 = v1->numberImportantObjects;
        v8 = v1->importantObjects;
        v7 = v6->id;
      }
      numberVisibleObjects = Visible_Unit_Manager::GetVisibleUnits(
                               VisibleUnitManager,
                               (signed __int64)v3->world_x,
                               (signed __int64)v3->world_y,
                               v4,
                               v7,
                               v8,
                               v9,
                               v10);
    }
  }
}
// 592A4C: using guessed type int searchedThisUpdate;
// 592A50: using guessed type int numberVisibleObjects;

//----- (00415120) --------------------------------------------------------
BOOL __stdcall UnitAIModule::importantWhenDead(int objectType)
{
  return objectType == 7
      || objectType == 9
      || objectType == 10
      || objectType == 15
      || objectType == 8
      || objectType == 32;
}

//----- (00415150) --------------------------------------------------------
int __stdcall UnitAIModule::retryableOrder(int orderType)
{
  return 0;
}

//----- (00415160) --------------------------------------------------------
BOOL __thiscall UnitAIModule::actionRequiresLiveTarget(UnitAIModule *this, int aID)
{
  return this->stopAfterTargetKilledValue == 1
      || aID == 600
      || aID == 601
      || aID == 603
      || aID == 604
      || aID == 618
      || aID == 612;
}

//----- (004151B0) --------------------------------------------------------
int __thiscall UnitAIModule::bestUnitToAttack(UnitAIModule *this, int allowWallAttacks, int quickCheck, float *threatSlot)
{
  UnitAIModule *v4; // edi@1
  int v5; // esi@1
  RGE_Player *v6; // ecx@7
  RGE_Player *v7; // ecx@10
  RGE_Static_Object *v8; // esi@15
  long double v9; // st7@15
  int v10; // eax@18
  RGE_Static_Object *v11; // eax@19
  signed int v12; // ebp@22
  signed int j; // ebx@23
  RGE_Static_Object *v14; // eax@24
  RGE_Static_Object *v15; // esi@24
  __int16 v16; // ax@33
  RGE_Static_Object *v17; // eax@56
  RGE_Static_Object *v18; // esi@56
  char v19; // al@57
  RGE_Static_Object *v20; // ecx@60
  RGE_Static_ObjectVtbl *v21; // esi@60
  float v22; // ST54_4@60
  RGE_Static_Object *v23; // eax@61
  RGE_Static_Object *v24; // esi@61
  int result; // eax@65
  float v26; // ST68_4@66
  double v27; // st7@66
  RGE_Static_Object *v28; // eax@80
  RGE_Static_Object *v29; // ecx@83
  RGE_Static_ObjectVtbl *v30; // esi@83
  float v31; // ST54_4@83
  signed int v32; // ebx@85
  signed int v33; // ebp@86
  RGE_Static_Object *v34; // eax@87
  RGE_Static_Object *v35; // esi@87
  __int16 v36; // ax@96
  long double v37; // st7@101
  float v38; // ST9C_4@101
  RGE_Static_ObjectVtbl *v39; // ebp@107
  float v40; // ST54_4@107
  int v41; // eax@107
  double v42; // st7@110
  double v43; // st6@110
  struct VISIBLE_UNIT_REC **v44; // ecx@112
  unsigned __int8 v45; // al@112
  int *v46; // edx@112
  int v47; // ecx@116
  float largestThreat; // [sp+68h] [bp-38h]@18
  int numberMovingTargets; // [sp+6Ch] [bp-34h]@22
  int numberDamagingUnits; // [sp+70h] [bp-30h]@22
  int largestThreatIsBuilding; // [sp+74h] [bp-2Ch]@18
  int i; // [sp+78h] [bp-28h]@38
  int ia; // [sp+78h] [bp-28h]@68
  int ib; // [sp+78h] [bp-28h]@86
  RGE_Game_World *world; // [sp+7Ch] [bp-24h]@18
  UnitAIModuleVtbl *v56; // [sp+80h] [bp-20h]@1
  int maxReactDistance; // [sp+84h] [bp-1Ch]@15
  int modifier; // [sp+88h] [bp-18h]@12
  int modifiera; // [sp+88h] [bp-18h]@18
  int numberNonCurrentTargets; // [sp+8Ch] [bp-14h]@22
  int currentTargetIsWall; // [sp+90h] [bp-10h]@18
  int numberObjectsInRange; // [sp+94h] [bp-Ch]@22
  float closestEnemyDistance; // [sp+98h] [bp-8h]@22
  float (__thiscall *closestEnemyDistancea)(RGE_Static_Object *, RGE_Static_Object *); // [sp+98h] [bp-8h]@66
  int enemyDistance; // [sp+9Ch] [bp-4h]@22
  float enemyDistancea; // [sp+9Ch] [bp-4h]@108

  v4 = this;
  v56 = this->vfptr;
  ((void (*)(void))this->vfptr->search)();
  v5 = RGE_Game_World::difficultyLevel(v4->objectValue->owner->world);
  if( (RGE_Base_Game::scenarioGame(rge_base_game) != 1
     || RGE_Base_Game::singlePlayerGame(rge_base_game) != 1
     || v5 < 3
     || v4->objectValue->owner->id == 1)
    && (RGE_Base_Game::singlePlayerGame(rge_base_game) != 1
     || v5 < 3
     || (v6 = v4->objectValue->owner, v6->type != 3)
     || ((int (__stdcall *)(signed int))v6->vfptr->strategicNumber)(219) == 100
     && ((int (__stdcall *)(signed int))v4->objectValue->owner->vfptr->strategicNumber)(218) == 100) )
  {
    v8 = v4->objectValue;
    v9 = v8->master_obj->los;
    maxReactDistance = 2 * (unsigned __int64)(signed __int64)v9;
  }
  else
  {
    v7 = v4->objectValue->owner;
    if( v7->id <= 1 )
    {
      modifier = v5 != 3 ? 50 : 75;
    }
    else if( v5 == 3 )
    {
      modifier = ((int (__stdcall *)(signed int))v7->vfptr->strategicNumber)(219);
    }
    else
    {
      modifier = ((int (__stdcall *)(signed int))v7->vfptr->strategicNumber)(218);
    }
    v8 = v4->objectValue;
    v9 = (double)modifier * v8->master_obj->los * 0.0099999998;
    maxReactDistance = (signed __int64)v9;
    if( maxReactDistance < 1 )
      maxReactDistance = 1;
  }
  modifiera = -1;
  v10 = v4->currentTargetValue;
  largestThreat = 0.0;
  largestThreatIsBuilding = 0;
  world = v8->owner->world;
  currentTargetIsWall = 0;
  if( v10 != -1 )
  {
    v11 = UnitAIModule::lookupObject(v4, v10);
    if( v11 )
    {
      if( v11->master_obj->object_group == 27 )
        currentTargetIsWall = 1;
    }
  }
  enemyDistance = -1;
  numberMovingTargets = 0;
  numberDamagingUnits = 0;
  numberNonCurrentTargets = 0;
  closestEnemyDistance = 100000.0;
  numberObjectsInRange = 0;
  v12 = 4;
  do
  {
    for( j = 0; j < (signed int)(&VisibleUnitList_Size)[v12]; ++j )
    {
      v14 = RGE_Game_World::object(world, (int)(&VisibleUnitList)[v12][2 * j]);
      v15 = v14;
      if( v14
        && v14->object_state <= 2u
        && (*(int (__stdcall **)(_DWORD))&v4->objectValue->owner->vfptr->gap4[24])(v14->owner->id) != 1
        && !v15->inside_obj
        && (allowWallAttacks && currentTargetIsWall || v15->master_obj->object_group != 27) )
      {
        if( v15->master_obj->object_group != 3
          || (v9 = v15->hp, v9 > 1.0)
          || (v16 = v4->objectValue->master_obj->id, v16 != 35) && v16 != 36 )
        {
          if( v56->canAttackUnit(v4, v15)
            && (v12 != 3 || v56->canAttackUnitAtNeutrality(v4, v15->master_obj->object_group)) )
          {
            v9 = RGE_Static_Object::distance_to_object(v4->objectValue, v15);
            *(float *)&i = v9;
            ((void (*)(void))v4->objectValue->vfptr->minimumWeaponRange)();
            if( v9 <= *(float *)&i && maxReactDistance >= SLOBYTE((&VisibleUnitList)[v12][2 * j + 1]) )
            {
              if( v15->id != v4->currentTargetValue )
                ++numberNonCurrentTargets;
              if( v15->master_obj->object_group != 3 )
                ++numberMovingTargets;
              ((void (__thiscall *)(RGE_Static_Object *))v15->vfptr->damageCapability)(v15);
              if( v9 > 0.0 )
                ++numberDamagingUnits;
              if( v15->master_obj->object_group != 3 )
              {
                ((void (*)(void))v4->objectValue->vfptr->weaponRange)();
                if( v9 - -1.0 > *(float *)&i )
                  ++numberObjectsInRange;
                v9 = *(float *)&i;
                if( *(float *)&i < (double)closestEnemyDistance )
                {
                  closestEnemyDistance = *(float *)&i;
                  enemyDistance = v15->id;
                }
              }
            }
          }
        }
      }
    }
    --v12;
  }
  while( v12 >= 2 );
  if( v4->currentTargetValue == -1 )
    goto LABEL_79;
  if( quickCheck )
    goto LABEL_79;
  if( v4->currentActionValue != 600 )
    goto LABEL_79;
  v17 = UnitAIModule::lookupObject(v4, v4->currentTargetValue);
  v18 = v17;
  if( !v17 )
    goto LABEL_79;
  v9 = v17->world_x;
  v19 = UnitAIModule::visibleStatus(
          v4,
          v4->objectValue->owner->visible,
          (signed __int64)v9,
          (signed __int64)v17->world_y);
  if( numberNonCurrentTargets )
  {
    if( v19 != 15 )
      goto LABEL_79;
    if( ((int (__stdcall *)(RGE_Static_Object *))v4->objectValue->vfptr->inAttackRange)(v18) != 1 )
    {
      v20 = v4->objectValue;
      v21 = v20->vfptr;
      ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v20->vfptr->weaponRange)(0, 0, -1, -1);
      v22 = v9;
      if( (*((int (__thiscall **)(RGE_Static_Object *, int, _DWORD))&v21->pause + 1))(
             v4->objectValue,
             v4->currentTargetValue,
             LODWORD(v22)) != 1 )
        goto LABEL_79;
    }
  }
  v23 = RGE_Game_World::object(world, v4->currentTargetValue);
  v24 = v23;
  if( !v23
    || v23->object_state != 2
    || (*(int (__stdcall **)(_DWORD))&v4->objectValue->owner->vfptr->gap4[24])(v23->owner->id) )
  {
    goto LABEL_79;
  }
  if( v24->master_obj->id == 276 )
    return v24->id;
  modifiera = v4->currentTargetValue;
  closestEnemyDistancea = v24->vfptr->damageCapability;
  ((void (__thiscall *)(RGE_Static_Object *))closestEnemyDistancea)(v24);
  v26 = v9 * 50.0;
  largestThreat = (double)((int (__stdcall *)(RGE_Master_Static_Object *))v24->master_obj->vfptr->calc_base_damage_ability)(v4->objectValue->master_obj)
                * 100.0
                + v26;
  v27 = v24->hp;
  if( v27 > 0.0 )
    largestThreat = largestThreat / v27;
  *(float *)&ia = RGE_Static_Object::distance_to_object(v24, v4->objectValue);
  v9 = *(float *)&ia;
  if( numberMovingTargets >= 2 )
  {
    if( *(float *)&ia == 0.0 )
      goto LABEL_74;
    v9 = largestThreat / ((double)numberMovingTargets * *(float *)&ia * 0.5);
  }
  else
  {
    if( *(float *)&ia == 0.0 )
      goto LABEL_74;
    v9 = largestThreat / *(float *)&ia;
  }
  largestThreat = v9;
LABEL_74:
  if( v24->master_obj->object_group == 3 )
  {
    largestThreatIsBuilding = 1;
  }
  else
  {
    largestThreatIsBuilding = 0;
    ++numberMovingTargets;
  }
  ((void (__thiscall *)(RGE_Static_Object *))closestEnemyDistancea)(v24);
  if( v9 > 0.0 )
    ++numberDamagingUnits;
  if( numberMovingTargets <= 1 )
    goto LABEL_129;
  v28 = RGE_Game_World::object(world, enemyDistance);
  if( !v28 )
    goto LABEL_129;
LABEL_79:
  if( ((int (__stdcall *)(RGE_Static_Object *))v4->objectValue->vfptr->inAttackRange)(v28) == 1 )
    return enemyDistance;
  v29 = v4->objectValue;
  v30 = v29->vfptr;
  ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v29->vfptr->weaponRange)(0, 0, -1, -1);
  v31 = v9;
  if( (*((int (__thiscall **)(RGE_Static_Object *, int, _DWORD))&v30->pause + 1))(
         v4->objectValue,
         enemyDistance,
         LODWORD(v31)) == 1 )
  {
    result = enemyDistance;
  }
  else
  {
LABEL_129:
    v32 = 4;
    do
    {
      v33 = 0;
      for( ib = 0; v33 < (signed int)(&VisibleUnitList_Size)[v32]; ib = v33 )
      {
        v34 = RGE_Game_World::object(world, (int)(&VisibleUnitList)[v32][2 * v33]);
        v35 = v34;
        if( v34
          && v34->object_state <= 2u
          && (*(int (__stdcall **)(_DWORD))&v4->objectValue->owner->vfptr->gap4[24])(v34->owner->id) != 1
          && !v35->inside_obj
          && (allowWallAttacks && currentTargetIsWall || v35->master_obj->object_group != 27) )
        {
          if( v35->master_obj->object_group != 3
            || v35->hp > 1.0
            || (v36 = v4->objectValue->master_obj->id, v36 != 35) && v36 != 36 )
          {
            if( v56->canAttackUnit(v4, v35)
              && (v32 != 3 || v56->canAttackUnitAtNeutrality(v4, v35->master_obj->object_group)) )
            {
              v37 = RGE_Static_Object::distance_to_object(v4->objectValue, v35);
              v38 = v37;
              ((void (*)(void))v4->objectValue->vfptr->minimumWeaponRange)();
              if( v37 <= v38
                && maxReactDistance >= SLOBYTE((&VisibleUnitList)[v32][2 * v33 + 1])
                && (quickCheck != 1 || ((int (__stdcall *)(_DWORD))v4->objectValue->vfptr->inAttackRange)(v35)) )
              {
                if( quickCheck
                  || ((int (__stdcall *)(RGE_Static_Object *))v4->objectValue->vfptr->inAttackRange)(v35)
                  || (v39 = v4->objectValue->vfptr,
                      ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v39->weaponRange)(0, 0, -1, -1),
                      v40 = v37,
                      v41 = (*((int (__thiscall **)(RGE_Static_Object *, struct VISIBLE_UNIT_REC *, _DWORD))&v39->pause
                             + 1))(
                              v4->objectValue,
                              (&VisibleUnitList)[v32][2 * modifiera],
                              LODWORD(v40)),
                      v33 = ib,
                      v41) )
                {
                  ((void (__thiscall *)(RGE_Static_Object *))v35->vfptr->damageCapability)(v35);
                  enemyDistancea = v37 * 50.0;
                  if( numberDamagingUnits <= 0 || enemyDistancea != 0.0 )
                  {
                    v42 = (double)((int (__stdcall *)(RGE_Master_Static_Object *))v35->master_obj->vfptr->calc_base_damage_ability)(v4->objectValue->master_obj)
                        * 100.0
                        + enemyDistancea;
                    v43 = v35->hp;
                    if( v43 > 0.0 )
                      v42 = v42 / v43;
                    v44 = (&VisibleUnitList)[v32];
                    v45 = (unsigned __int8)v44[2 * v33 + 1];
                    v46 = (int *)&v44[2 * v33];
                    if( v45 )
                      v42 = v42 / (double)v45;
                    if( numberMovingTargets > 1 )
                      v42 = v42
                          / (double)(LOBYTE(v44[2 * v33 + 1]) * LOBYTE(v44[2 * v33 + 1]) * LOBYTE(v44[2 * v33 + 1]));
                    v47 = v35->master_obj->object_group;
                    if( modifiera == -1
                      || (largestThreatIsBuilding || v47 != 3)
                      && (modifiera == -1 || largestThreatIsBuilding == 1 && v47 != 3 || v42 > largestThreat) )
                    {
                      largestThreat = v42;
                      modifiera = *v46;
                      largestThreatIsBuilding = v47 == 3;
                    }
                  }
                }
              }
            }
          }
        }
        ++v33;
      }
      --v32;
    }
    while( v32 >= 2 );
    result = modifiera;
  }
  return result;
}
// 87D7C8: using guessed type int *VisibleUnitList_Size;
// 87D7E0: using guessed type struct VISIBLE_UNIT_REC **VisibleUnitList;

//----- (00415A10) --------------------------------------------------------
int __userpurge UnitAIModule::mostDangerousEnemy@<eax>(UnitAIModule *this@<ecx>, double a2@<st0>, float *threatSlot)
{
  UnitAIModule *v3; // esi@1
  signed int v4; // ebp@1
  int v5; // eax@1
  RGE_Static_Object *v6; // eax@2
  RGE_Static_Object *v7; // ecx@3
  RGE_Master_Static_Object *v8; // ebx@3
  RGE_Static_ObjectVtbl *v9; // edi@3
  float v10; // ST0C_4@3
  int i; // [sp+20h] [bp-8h]@1
  float largestThreat; // [sp+24h] [bp-4h]@1

  v3 = this;
  ((void (__usercall *)(double@<st0>))this->vfptr->search)(a2);
  v4 = -1;
  v5 = 0;
  largestThreat = 0.0;
  for( i = 0; i < dword_87D7D8[0]; ++i )
  {
    v6 = UnitAIModule::lookupObject(v3, *(_DWORD *)(dword_87D7F0[0] + 8 * v5));
    if( v6 )
    {
      v7 = v3->objectValue;
      v8 = v6->master_obj;
      v9 = v7->vfptr;
      ((void (__stdcall *)(RGE_Static_Object *, RGE_Player *, RGE_Static_Object *))v7->vfptr->calc_attack_modifier)(
        v6,
        v6->owner,
        v6);
      v10 = a2;
      ((void (__thiscall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v9->calculateDamage)(
        v3->objectValue,
        v8[1].portrait_pict,
        *(_DWORD *)&v8[1].tile_req1,
        LODWORD(v10));
      if( v4 == -1 || a2 > largestThreat )
      {
        largestThreat = a2;
        v4 = *(_DWORD *)(dword_87D7F0[0] + 8 * i);
      }
    }
    v5 = i + 1;
  }
  if( threatSlot )
    *threatSlot = largestThreat;
  return v4;
}
// 87D7D8: using guessed type int dword_87D7D8[];
// 87D7F0: using guessed type int dword_87D7F0[];

//----- (00415AD0) --------------------------------------------------------
int __thiscall UnitAIModule::weakestEnemy(UnitAIModule *this, float *threatSlot)
{
  UnitAIModule *v2; // edi@1
  signed int v3; // ebx@1
  int v4; // esi@1
  int v5; // edx@2
  RGE_Static_Object *v6; // eax@3
  float smallestHP; // [sp+Ch] [bp-4h]@1

  v2 = this;
  ((void (*)(void))this->vfptr->search)();
  v3 = -1;
  v4 = 0;
  smallestHP = 0.0;
  if( dword_87D7D8[0] > 0 )
  {
    v5 = dword_87D7F0[0];
    do
    {
      v6 = UnitAIModule::lookupObject(v2, *(_DWORD *)(v5 + 8 * v4));
      v5 = dword_87D7F0[0];
      if( v6 && (v3 == -1 || v6->hp < (double)smallestHP) )
      {
        v3 = *(_DWORD *)(dword_87D7F0[0] + 8 * v4);
        smallestHP = v6->hp;
      }
      ++v4;
    }
    while( v4 < dword_87D7D8[0] );
  }
  if( threatSlot )
    *threatSlot = smallestHP;
  return v3;
}
// 87D7D8: using guessed type int dword_87D7D8[];
// 87D7F0: using guessed type int dword_87D7F0[];

//----- (00415B50) --------------------------------------------------------
int __thiscall UnitAIModule::closestAttacker(UnitAIModule *this, float *threatSlot)
{
  UnitAIModule *v2; // esi@1
  int v3; // ebp@1
  int v4; // ebx@3
  int *v5; // edi@3
  int i; // eax@4
  RGE_Static_Object *v7; // eax@8
  int v8; // ebx@12
  int *v9; // edi@12
  int j; // eax@13
  float largestThreat; // [sp+10h] [bp-Ch]@1
  int largestThreatID; // [sp+14h] [bp-8h]@1
  float attackThreat; // [sp+18h] [bp-4h]@9

  v2 = this;
  v3 = 0;
  largestThreatID = -1;
  for( largestThreat = 0.0; v3 < v2->attackingUnitsValue.numberValue; ++v3 )
  {
    if( v3 > v2->attackingUnitsValue.maximumSizeValue - 1 )
    {
      v4 = v3 + 1;
      v5 = (int *)operator new(4 * v3 + 4);
      if( v5 )
      {
        for( i = 0; i < v2->attackingUnitsValue.maximumSizeValue; v5[i - 1] = v2->attackingUnitsValue.value[i - 1] )
        {
          if( i >= v4 )
            break;
          ++i;
        }
        operator delete(v2->attackingUnitsValue.value);
        v2->attackingUnitsValue.value = v5;
        v2->attackingUnitsValue.maximumSizeValue = v4;
      }
    }
    v7 = RGE_Game_World::object(v2->objectValue->owner->world, v2->attackingUnitsValue.value[v3]);
    if( v7 )
    {
      attackThreat = RGE_Static_Object::distance_to_object(v2->objectValue, v7);
      if( largestThreatID == -1 || attackThreat < (double)largestThreat )
      {
        if( v3 > v2->attackingUnitsValue.maximumSizeValue - 1 )
        {
          v8 = v3 + 1;
          v9 = (int *)operator new(4 * v3 + 4);
          if( v9 )
          {
            for( j = 0; j < v2->attackingUnitsValue.maximumSizeValue; v9[j - 1] = v2->attackingUnitsValue.value[j - 1] )
            {
              if( j >= v8 )
                break;
              ++j;
            }
            operator delete(v2->attackingUnitsValue.value);
            v2->attackingUnitsValue.value = v9;
            v2->attackingUnitsValue.maximumSizeValue = v8;
          }
        }
        largestThreat = attackThreat;
        largestThreatID = v2->attackingUnitsValue.value[v3];
      }
    }
  }
  if( threatSlot )
    *threatSlot = largestThreat;
  return largestThreatID;
}

//----- (00415CA0) --------------------------------------------------------
int __thiscall UnitAIModule::closestObject(UnitAIModule *this, int objectGroup, int desiredRelation, int objectState, int objectType, int *threatSlot)
{
  signed int v6; // edi@1
  signed int v7; // ebx@2
  struct VISIBLE_UNIT_REC ***v8; // esi@3
  int v9; // eax@4
  RGE_Static_Object *v10; // ecx@4
  RGE_Static_Object *v11; // eax@5
  int v12; // edx@27
  int *v13; // eax@27
  signed int v14; // ecx@27
  float closestDistance; // [sp+10h] [bp-30h]@1
  int closestObjectID; // [sp+14h] [bp-2Ch]@1
  UnitAIModule *v18; // [sp+18h] [bp-28h]@1
  int objectsOfPlayer[9]; // [sp+1Ch] [bp-24h]@1

  v18 = this;
  ((void (*)(void))this->vfptr->search)();
  memset(objectsOfPlayer, 0, sizeof(objectsOfPlayer));
  closestObjectID = -1;
  closestDistance = -1.0;
  v6 = 0;
  do
  {
    v7 = 0;
    if( (signed int)(&VisibleUnitList_Size)[v6] > 0 )
    {
      v8 = &(&VisibleUnitList)[v6];
      do
      {
        v9 = (int)&(*v8)[2 * v7];
        objectsOfPlayer[*(_BYTE *)(v9 + 5)] = 1;
        v10 = v18->objectValue;
        if( v10->id != *(_DWORD *)v9 )
        {
          v11 = RGE_Game_World::object(v10->owner->world, (int)(*v8)[2 * v7]);
          if( v11 )
          {
            if( v11->object_state < 7u
              && (desiredRelation || v6 == 2 || v6 == 1)
              && (desiredRelation != 2 || v6 == 4)
              && (desiredRelation != 3 || v6 == 1)
              && (desiredRelation != 1 || v6 == 3)
              && (objectGroup == -1 || v11->master_obj->object_group == objectGroup)
              && (objectType == -1 || v11->master_obj->id == objectType)
              && (objectState == -1 || v11->object_state == objectState)
              && (closestObjectID == -1 || (double)LOBYTE((*v8)[2 * v7 + 1]) < closestDistance) )
            {
              closestObjectID = (int)&(*v8)[2 * v7]->object_id;
              closestDistance = (double)LOBYTE((*v8)[2 * v7 + 1]);
            }
          }
        }
        ++v7;
      }
      while( v7 < (signed int)(&VisibleUnitList_Size)[v6] );
    }
    ++v6;
  }
  while( v6 <= 4 );
  v12 = 0;
  v13 = &objectsOfPlayer[1];
  numberDifferentPlayerObjectsVisible = 0;
  v14 = 8;
  do
  {
    if( *v13 == 1 )
      ++v12;
    ++v13;
    --v14;
  }
  while( v14 );
  numberDifferentPlayerObjectsVisible = v12;
  if( threatSlot )
    *threatSlot = (signed __int64)closestDistance;
  return closestObjectID;
}
// 592A54: using guessed type int numberDifferentPlayerObjectsVisible;
// 87D7C8: using guessed type int *VisibleUnitList_Size;
// 87D7E0: using guessed type struct VISIBLE_UNIT_REC **VisibleUnitList;

//----- (00415E50) --------------------------------------------------------
int __thiscall UnitAIModule::closestResourceObject(UnitAIModule *this, int resourceType, int *dSlot)
{
  UnitAIModule *v3; // ebx@1
  int v4; // edi@1
  RGE_Static_Object *v5; // esi@2
  int excludeList_364; // ST16C_4@2
  VISIBLE_RESOURCE_REC *v7; // esi@2
  RGE_Static_Object *v8; // ecx@3
  int excList; // [sp+190h] [bp+0h]@1

  v3 = this;
  memset32(&excList, 2147483648, 0x64u);
  v4 = 0;
  do
  {
    v5 = v3->objectValue;
    excludeList_364 = (unsigned __int8)RGE_Static_Object::currentZone(v3->objectValue);
    v7 = Visible_Resource_Manager::Get_Closest_Resource(
           v5->owner->VR_List,
           (signed __int64)v5->world_x,
           (signed __int64)v5->world_y,
           excludeList_364,
           resourceType,
           &excList,
           v4);
    if( v7 )
    {
      v8 = v3->objectValue;
      if( v8->master_obj->los - -5.0 >= (double)v7->distance )
        continue;
    }
    return -1;
    if( (*((int (__stdcall **)(int, signed int, _DWORD, _DWORD, signed int, signed int))&v8->vfptr->pause + 1))(
           v7->object_id,
           1065353216,
           0,
           0,
           -1,
           -1) == 1 )
      break;
    ++v4;
    excList = v7->object_id;
  }
  while( v4 < 100 );
  if( dSlot )
    *dSlot = v7->distance;
  return v7->object_id;
}

//----- (00415F40) --------------------------------------------------------
int __thiscall UnitAIModule::closestUndiscoveredTile(UnitAIModule *this, int *tX, int *tY, int checkWaypointQueue)
{
  UnitAIModule *v4; // ebp@1
  RGE_Static_Object *v5; // esi@4
  double v6; // st7@4
  int v7; // ebx@4
  signed __int64 v8; // rax@4
  RGE_Player *v9; // esi@4
  int v10; // edi@4
  RGE_Map *v11; // eax@4
  int v12; // eax@10
  int v13; // edi@13
  float v14; // ST1C_4@16
  float v15; // ST18_4@16
  int v16; // esi@19
  int v17; // ST48_4@20
  int *v18; // eax@23
  RGE_Static_Object *v19; // ebp@27
  float v20; // ST0C_4@27
  int result; // eax@27
  char currentZone; // [sp+37h] [bp-29h]@12
  int lowX; // [sp+38h] [bp-28h]@4
  int highX; // [sp+3Ch] [bp-24h]@4
  int highY; // [sp+40h] [bp-20h]@4
  int distance; // [sp+44h] [bp-1Ch]@4
  int i; // [sp+48h] [bp-18h]@13
  int searchRadius; // [sp+4Ch] [bp-14h]@12
  RGE_Visible_Map *vMap; // [sp+50h] [bp-10h]@4
  int currX; // [sp+54h] [bp-Ch]@4
  int currY; // [sp+58h] [bp-8h]@4
  int randSelect; // [sp+5Ch] [bp-4h]@12

  v4 = this;
  if( this->currentOrderValue == 705
    && LODWORD(this->currentTargetXValue) != -1082130432
    && LODWORD(this->currentTargetYValue) != -1082130432 )
  {
    goto LABEL_31;
  }
  v5 = this->objectValue;
  distance = -1;
  currX = (signed __int64)v5->world_x;
  currY = (signed __int64)v5->world_y;
  v6 = (double)(signed int)((unsigned __int64)(signed __int64)v5->master_obj->los + 3);
  lowX = (signed __int64)(v5->world_x - v6);
  highX = (signed __int64)(v6 + v5->world_x);
  v7 = (signed __int64)(v5->world_y - v6);
  v8 = (signed __int64)(v6 + v5->world_y);
  v9 = v5->owner;
  v10 = v8;
  highY = v8;
  vMap = v9->visible;
  v11 = v9->world->map;
  if( lowX < 0 )
    lowX = 0;
  if( highX > v11->map_width - 1 )
    highX = v11->map_width - 1;
  if( v7 < 0 )
    v7 = 0;
  v12 = v11->map_height - 1;
  if( v10 > v12 )
  {
    highY = v12;
    v10 = v12;
  }
  randSelect = debug_rand(aCMsdevWorkA_43, 2862) % 3;
  currentZone = RGE_Static_Object::currentZone(v4->objectValue);
  searchRadius = v7;
  if( v7 <= v10 )
  {
    do
    {
      v13 = lowX;
      for( i = lowX; v13 <= highX; i = v13 )
      {
        if( !UnitAIModule::visibleStatus(v4, vMap, v13, v7)
          && currentZone == RGE_Static_Object::lookupZone(v4->objectValue, v13, v7) )
        {
          v14 = (double)searchRadius;
          v15 = (double)i;
          if( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v4->objectValue->vfptr->passableTile)(
                 LODWORD(v15),
                 LODWORD(v14),
                 0) )
          {
            if( !checkWaypointQueue || !UnitAIModule::inWaypointQueue(v4, v13, v7) )
            {
              v16 = (v7 - currY) * (v7 - currY) + (v13 - currX) * (v13 - currX);
              if( LODWORD(v4->currentTargetXValue) != -1082130432 )
              {
                v17 = v13 - (unsigned __int64)(signed __int64)v4->currentTargetXValue;
                v16 += (v7 - (unsigned __int64)(signed __int64)v4->currentTargetYValue)
                     * (v7 - (unsigned __int64)(signed __int64)v4->currentTargetYValue)
                     + v17 * v17;
              }
              if( distance == -1 || distance + randSelect > v16 )
              {
                v18 = tY;
                distance = v16;
                *tX = v13;
                *v18 = v7;
              }
            }
          }
        }
        ++v13;
      }
      searchRadius = ++v7;
    }
    while( v7 <= highY );
  }
  if( distance == -1 )
  {
LABEL_31:
    result = 0;
  }
  else
  {
    v19 = v4->objectValue;
    v20 = v19->master_obj->los - 1.0;
    result = ((int (__thiscall *)(RGE_Static_Object *, int, int, _DWORD, _DWORD, signed int, int **, _DWORD, signed int, signed int))v19->vfptr->canPath)(
               v19,
               *tX,
               *tY,
               (signed __int64)v19->world_z,
               LODWORD(v20),
               -1,
               &tX,
               0,
               -1,
               -1);
  }
  return result;
}

//----- (004161D0) --------------------------------------------------------
Waypoint *__stdcall UnitAIModule::waypoint(int i)
{
  return 0;
}

//----- (004161E0) --------------------------------------------------------
int __thiscall UnitAIModule::waypointQueueSize(UnitAIModule *this)
{
  return this->waypointQueueSizeValue;
}

//----- (004161F0) --------------------------------------------------------
int __thiscall UnitAIModule::addToWaypointQueue(UnitAIModule *this, int x, int y)
{
  if( this->waypointQueueSizeValue >= 8 )
    this->waypointQueueSizeValue = 0;
  *((float *)&this->vfptr + 4 * (this->waypointQueueSizeValue + 7)) = (double)x;
  this->waypointQueue[this->waypointQueueSizeValue++].y = (double)y;
  return 1;
}

//----- (00416240) --------------------------------------------------------
int __thiscall UnitAIModule::inWaypointQueue(UnitAIModule *this, int x, int y)
{
  int v3; // esi@1
  int v4; // edx@1
  float *v5; // ecx@2
  int result; // eax@6
  int xa; // [sp+8h] [bp+4h]@2

  v3 = this->waypointQueueSizeValue;
  v4 = 0;
  if( v3 <= 0 )
  {
    result = 0;
  }
  else
  {
    v5 = &this->waypointQueue[0].y;
    *(float *)&xa = (double)x;
    while( *(v5 - 1) != *(float *)&xa || (double)y != *v5 )
    {
      ++v4;
      v5 += 4;
      if( v4 >= v3 )
        return 0;
    }
    result = 1;
  }
  return result;
}

//----- (00416290) --------------------------------------------------------
void __thiscall UnitAIModule::clearWaypointQueue(UnitAIModule *this)
{
  this->waypointQueueSizeValue = 0;
}

//----- (004162A0) --------------------------------------------------------
int __stdcall UnitAIModule::canAttackUnit(RGE_Static_Object *target)
{
  return 1;
}

//----- (004162B0) --------------------------------------------------------
int __stdcall UnitAIModule::canAttackUnitAtNeutrality(int uID)
{
  return 1;
}

//----- (004162C0) --------------------------------------------------------
int __thiscall UnitAIModule::stopObject(UnitAIModule *this, int checkOrderAndAction)
{
  UnitAIModule *v2; // esi@1
  int v3; // eax@3
  int v4; // ecx@5

  v2 = this;
  if( actionFile )
    fprintf(
      actionFile,
      aTLdUDSoCoaaD_,
      this->objectValue->owner->world->world_time,
      this->objectValue->id,
      checkOrderAndAction);
  v3 = v2->currentActionValue;
  v2->lastActionValue = v3;
  if( !checkOrderAndAction || v3 + 100 == v2->currentOrderValue )
  {
    v4 = v2->currentOrderValue;
    v2->currentOrderValue = -1;
    v2->lastOrderValue = v4;
    v2->currentOrderPriorityValue = -1;
  }
  ((void (*)(void))v2->objectValue->vfptr->stopAction)();
  v2->currentActionValue = -1;
  return 1;
}

//----- (00416340) --------------------------------------------------------
int __thiscall UnitAIModule::attackObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // eax@3
  RGE_Static_Object *v5; // edi@3
  int result; // eax@6

  v3 = this;
  if( (unconditional || this->currentActionValue == -1)
    && (v4 = RGE_Game_World::object(this->objectValue->owner->world, targetID), (v5 = v4) != 0)
    && v3->vfptr->canAttackUnit(v3, v4)
    && ((int (__stdcall *)(int, int))v3->objectValue->vfptr->attack)(targetID, unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v3, 600);
    UnitAIModule::setCurrentTarget(v3, targetID, v5->world_x, v5->world_y, v5->world_z);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004163C0) --------------------------------------------------------
int __userpurge UnitAIModule::attackRoundupObject@<eax>(UnitAIModule *this@<ecx>, double a2@<st0>, int targetID)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // eax@2
  RGE_Static_Object *v5; // ebp@2
  RGE_Static_Object *v6; // ecx@5
  RGE_Static_ObjectVtbl *v7; // edi@5
  float v8; // ST14_4@5
  int result; // eax@7

  v3 = this;
  if( this->currentTargetValue != targetID
    && (v4 = RGE_Game_World::object(this->objectValue->owner->world, targetID), (v5 = v4) != 0)
    && v3->vfptr->canAttackUnit(v3, v4)
    && (v3->currentActionValue == -1
     || (v6 = v3->objectValue,
         v7 = v6->vfptr,
         ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v6->vfptr->weaponRange)(0, 0, -1, -1),
         v8 = a2,
         (*((int (__thiscall **)(RGE_Static_Object *, int, _DWORD))&v7->pause + 1))(
           v3->objectValue,
           targetID,
           LODWORD(v8))))
    && ((int (__stdcall *)(int, signed int))v3->objectValue->vfptr->attack)(targetID, 1) == 1 )
  {
    UnitAIModule::setCurrentAction(v3, 600);
    UnitAIModule::setCurrentTarget(v3, targetID, v5->world_x, v5->world_y, v5->world_z);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416470) --------------------------------------------------------
int __thiscall UnitAIModule::huntObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // eax@4
  signed int v5; // eax@5
  RGE_Static_Object *v6; // edi@9
  int result; // eax@10

  v3 = this;
  if( !unconditional && this->currentActionValue == 613 )
    goto LABEL_15;
  if( actionFile )
  {
    v4 = this->objectValue;
    if( v4 )
      v5 = v4->id;
    else
      v5 = -1;
    fprintf(actionFile, aDCallStopobjec, v5, aCMsdevWorkA_43, 3144);
  }
  v3->vfptr->stopObject(v3, 1);
  if( ((int (__stdcall *)(int, int))v3->objectValue->vfptr->hunt)(targetID, unconditional) == 1 )
  {
    v6 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 613);
    if( v6 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v6->master_obj->object_group, v6->world_x, v6->world_y, v6->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
LABEL_15:
    result = 0;
  }
  return result;
}

//----- (00416550) --------------------------------------------------------
int __thiscall UnitAIModule::convertObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue != 604)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->convert)(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 604);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->master_obj->object_group, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004165F0) --------------------------------------------------------
int __thiscall UnitAIModule::healObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue != 603)
    && (*(int (__stdcall **)(int, int))&this->objectValue->vfptr->gap88[0])(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 603);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->master_obj->object_group, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416690) --------------------------------------------------------
int __thiscall UnitAIModule::gatherObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue != 609)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->gather)(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 609);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->master_obj->object_group, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416730) --------------------------------------------------------
int __thiscall UnitAIModule::repairObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue != 618)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->repair)(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 618);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->master_obj->object_group, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004167D0) --------------------------------------------------------
int __thiscall UnitAIModule::buildObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue != 602)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->build)(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 602);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->master_obj->object_group, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416870) --------------------------------------------------------
int __thiscall UnitAIModule::tradeWithObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue != 615)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->trade)(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 615);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->master_obj->object_group, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416910) --------------------------------------------------------
int __thiscall UnitAIModule::explore(UnitAIModule *this, int tX, int tY, int unconditional)
{
  UnitAIModule *v4; // esi@1
  float y; // ST10_4@4
  float x; // ST0C_4@4
  int result; // eax@4

  v4 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(int, int, int))this->objectValue->vfptr->explore)(tX, tY, unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v4, 605);
    y = (double)tY;
    x = (double)tX;
    UnitAIModule::setCurrentTarget(v4, -1, x, y, 1.0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416980) --------------------------------------------------------
int __thiscall UnitAIModule::enterObject(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  int result; // eax@4

  v3 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->enter)(targetID, unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v3, 617);
    UnitAIModule::setCurrentTarget(v3, targetID, -1.0, -1.0, -1.0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004169E0) --------------------------------------------------------
int __thiscall UnitAIModule::transportObject(UnitAIModule *this, float tX, float tY, float tZ, int unconditional)
{
  UnitAIModule *v5; // esi@1
  int result; // eax@4

  v5 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, int))this->objectValue->vfptr->transport)(
         LODWORD(tX),
         LODWORD(tY),
         LODWORD(tZ),
         unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v5, 614);
    UnitAIModule::setCurrentTarget(v5, -1, tX, tY, tZ);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416A50) --------------------------------------------------------
int __thiscall UnitAIModule::unload(UnitAIModule *this, int unconditional, float x, float y)
{
  UnitAIModule *v4; // esi@1
  RGE_Static_Object *v5; // edi@4
  int result; // eax@5

  v4 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(int, _DWORD, _DWORD, _DWORD))this->objectValue->vfptr->unload)(
         unconditional,
         LODWORD(x),
         LODWORD(y),
         LODWORD(this->objectValue->world_z)) == 1 )
  {
    v5 = v4->objectValue;
    UnitAIModule::setCurrentAction(v4, 621);
    if( v5 )
    {
      UnitAIModule::setCurrentTarget(
        v4,
        v4->objectValue->id,
        v5->master_obj->object_group,
        v5->world_x,
        v5->world_y,
        v5->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v4, v4->objectValue->id, -1, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416AF0) --------------------------------------------------------
int __thiscall UnitAIModule::moveTo(UnitAIModule *this, int targetID, int unconditional)
{
  UnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@4
  int result; // eax@5

  v3 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->moveTo)(targetID, unconditional) == 1 )
  {
    v4 = RGE_Game_World::object(v3->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v3, 610);
    if( v4 )
    {
      UnitAIModule::setCurrentTarget(v3, targetID, v4->world_x, v4->world_y, v4->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v3, targetID, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416B80) --------------------------------------------------------
int __thiscall UnitAIModule::moveTo(UnitAIModule *this, int targetID, float minimumRange, int unconditional)
{
  UnitAIModule *v4; // esi@1
  RGE_Static_Object *v5; // edi@4
  int result; // eax@5

  v4 = this;
  if( (unconditional || this->currentActionValue == -1)
    && (*(int (__stdcall **)(int, _DWORD, int))&this->objectValue->vfptr->gap154[4])(
         targetID,
         LODWORD(minimumRange),
         unconditional) == 1 )
  {
    v5 = RGE_Game_World::object(v4->objectValue->owner->world, targetID);
    UnitAIModule::setCurrentAction(v4, 610);
    if( v5 )
    {
      UnitAIModule::setCurrentTarget(v4, targetID, v5->world_x, v5->world_y, v5->world_z);
      result = 1;
    }
    else
    {
      UnitAIModule::setCurrentTarget(v4, targetID, 0.0, 0.0, 0.0);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416C10) --------------------------------------------------------
int __thiscall UnitAIModule::moveTo(UnitAIModule *this, float targetX, float targetY, float targetZ, float range, int unconditional)
{
  UnitAIModule *v6; // esi@1
  int result; // eax@4

  v6 = this;
  if( (unconditional || this->currentActionValue == -1)
    && (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int))&this->objectValue->vfptr->gap154[0])(
         LODWORD(targetX),
         LODWORD(targetY),
         LODWORD(targetZ),
         LODWORD(range),
         unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v6, 610);
    UnitAIModule::setCurrentTarget(v6, -1, targetX, targetY, targetZ);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00416C80) --------------------------------------------------------
int __thiscall UnitAIModule::evasiveMoveTo(UnitAIModule *this, float targetX, float targetY, float targetZ, int unconditional)
{
  UnitAIModule *v5; // ebp@1
  double v6; // st7@5
  double v7; // st7@9
  int v8; // ebx@11
  float v9; // esi@12
  float v10; // edi@12
  double v11; // st7@14
  double v12; // st7@17
  double v13; // st7@21
  double v14; // st7@25
  int result; // eax@30

  v5 = this;
  if( !unconditional && this->currentActionValue != -1 )
    goto LABEL_34;
  if( targetX >= 0.0 )
  {
    v6 = (double)this->objectValue->owner->world->map->map_width;
    if( targetX >= v6 )
      targetX = v6 - 1.0;
  }
  else
  {
    targetX = 0.0;
  }
  if( targetY >= 0.0 )
  {
    v7 = (double)this->objectValue->owner->world->map->map_height;
    if( targetY >= v7 )
      targetY = v7 - 1.0;
  }
  else
  {
    targetY = 0.0;
  }
  v8 = 0;
  while( 1 )
  {
    v9 = targetY;
    v10 = targetX;
    if( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v5->objectValue->vfptr->passableTile)(
           LODWORD(targetX),
           LODWORD(targetY),
           0) == 1 )
      break;
    if( (char)debug_rand(aCMsdevWorkA_43, 3487) % -2 )
      v11 = (double)(unsigned __int8)((char)debug_rand(aCMsdevWorkA_43, 3488) % -4) + targetX;
    else
      v11 = targetX - (double)(unsigned __int8)((char)debug_rand(aCMsdevWorkA_43, 3490) % -4);
    targetX = v11;
    if( (char)debug_rand(aCMsdevWorkA_43, 3491) % -2 )
      v12 = (double)(unsigned __int8)((char)debug_rand(aCMsdevWorkA_43, 3492) % -4) + targetY;
    else
      v12 = targetY - (double)(unsigned __int8)((char)debug_rand(aCMsdevWorkA_43, 3494) % -4);
    targetY = v12;
    if( targetX >= 0.0 )
    {
      v13 = (double)v5->objectValue->owner->world->map->map_width;
      if( targetX >= v13 )
        targetX = v13 - 1.0;
    }
    else
    {
      targetX = 0.0;
    }
    if( targetY >= 0.0 )
    {
      v14 = (double)v5->objectValue->owner->world->map->map_height;
      if( targetY >= v14 )
        targetY = v14 - 1.0;
    }
    else
    {
      targetY = 0.0;
    }
    if( ++v8 >= 5 )
    {
      v9 = targetY;
      v10 = targetX;
      break;
    }
  }
  if( (*(int (__stdcall **)(float, float, _DWORD, _DWORD, int))&v5->objectValue->vfptr->gap154[0])(
         COERCE_FLOAT(LODWORD(v10)),
         COERCE_FLOAT(LODWORD(v9)),
         LODWORD(targetZ),
         0,
         unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v5, 610);
    UnitAIModule::setCurrentTarget(v5, -1, v10, v9, targetZ);
    result = 1;
  }
  else
  {
LABEL_34:
    result = 0;
  }
  return result;
}

//----- (00416F30) --------------------------------------------------------
int __thiscall UnitAIModule::intelligentEvasiveMoveTo(UnitAIModule *this, float targetX, float targetY, float targetZ, int goCloser, int unconditional)
{
  UnitAIModule *v6; // ebp@1
  double v7; // st7@5
  double v8; // st7@9
  int v9; // esi@11
  RGE_Static_Object *v10; // ebx@11
  int v11; // edi@11
  signed __int64 v12; // rax@11
  int v13; // ebx@12
  int v14; // ebx@13
  int v15; // eax@19
  int v16; // eax@24
  RGE_Static_Object *v17; // ecx@28
  long double v18; // st7@28
  RGE_Static_ObjectVtbl **v19; // ecx@30
  RGE_Static_ObjectVtbl *v20; // eax@30
  RGE_Static_ObjectVtbl **v21; // ecx@32
  RGE_Static_ObjectVtbl *v22; // eax@32
  int result; // eax@33
  int v24; // [sp+14h] [bp-48h]@30
  int v25; // [sp+18h] [bp-44h]@30
  int v26; // [sp+1Ch] [bp-40h]@30
  signed int v27; // [sp+20h] [bp-3Ch]@30
  float v28; // [sp+24h] [bp-38h]@30
  float v29; // [sp+28h] [bp-34h]@30
  float x; // [sp+2Ch] [bp-30h]@11
  float y; // [sp+30h] [bp-2Ch]@11
  int v32; // [sp+34h] [bp-28h]@11
  float baseDistance; // [sp+48h] [bp-14h]@12
  int facet; // [sp+4Ch] [bp-10h]@13
  XYZPoint point; // [sp+50h] [bp-Ch]@11

  v6 = this;
  if( !unconditional && this->currentActionValue != -1 )
    goto LABEL_34;
  if( targetX >= 0.0 )
  {
    v7 = (double)this->objectValue->owner->world->map->map_width;
    if( targetX >= v7 )
      targetX = v7 - 1.0;
  }
  else
  {
    targetX = 0.0;
  }
  if( targetY >= 0.0 )
  {
    v8 = (double)this->objectValue->owner->world->map->map_height;
    if( targetY >= v8 )
      targetY = v8 - 1.0;
  }
  else
  {
    targetY = 0.0;
  }
  v9 = (signed __int64)targetX;
  point.x = v9;
  v10 = this->objectValue;
  v11 = (signed __int64)targetY;
  point.y = v11;
  v12 = (signed __int64)v10->world_z;
  v32 = -1;
  y = -6.8056469e38/*NaN*/;
  x = 0.0;
  HIDWORD(v12) = v10->vfptr;
  point.z = v12;
  if( !(*(int (__thiscall **)(RGE_Static_Object *, int, int, _DWORD, signed int, signed int, _DWORD, _DWORD, signed int, signed int))(HIDWORD(v12) + 408))(
          v10,
          v9,
          v11,
          v12,
          1065353216,
          -1,
          0,
          0,
          -1,
          -1) )
  {
    v13 = -1;
    baseDistance = RGE_Static_Object::distance_to_position(v6->objectValue, targetX, targetY, v6->objectValue->world_z);
    while( 1 )
    {
      v14 = v13 + 1;
      facet = v14;
      switch ( v14 )
      {
        case 0:
          v9 -= 2;
          point.x = v9;
          goto LABEL_15;
        case 7:
LABEL_15:
          v11 -= 2;
          goto LABEL_16;
        case 1:
        case 2:
          v9 += 2;
          point.x = v9;
          break;
        case 3:
        case 4:
          v11 += 2;
LABEL_16:
          point.y = v11;
          break;
        case 5:
        case 6:
          v9 -= 2;
          point.x = v9;
          break;
        default:
          goto LABEL_34;
      }
      if( v9 >= 0 )
      {
        v15 = v6->objectValue->owner->world->map->map_width;
        if( v9 < v15 )
          goto LABEL_22;
        v9 = v15 - 1;
      }
      else
      {
        v9 = 0;
      }
      point.x = v9;
LABEL_22:
      if( v11 >= 0 )
      {
        v16 = v6->objectValue->owner->world->map->map_height;
        if( v11 < v16 )
          goto LABEL_27;
        v11 = v16 - 1;
      }
      else
      {
        v11 = 0;
      }
      point.y = v11;
LABEL_27:
      if( goCloser
        || (v17 = v6->objectValue,
            v32 = LODWORD(v17->world_z),
            y = (double)point.y - -0.5,
            x = (double)point.x - -0.5,
            v18 = RGE_Static_Object::distance_to_position(v17, x, y, *(float *)&v32),
            v18 >= baseDistance) )
      {
        v19 = &v6->objectValue->vfptr;
        v32 = -1;
        y = -6.8056469e38/*NaN*/;
        x = 0.0;
        v20 = *v19;
        v29 = 0.0;
        v28 = -6.8056469e38/*NaN*/;
        v27 = 1065353216;
        v24 = v9;
        v25 = v11;
        v26 = point.z;
        if( ((int (__stdcall *)(int, int, int, signed int, signed int, _DWORD, _DWORD, signed int, signed int))v20->canPath)(
               v9,
               v11,
               point.z,
               1065353216,
               -1,
               0,
               0,
               -1,
               -1) == 1 )
          break;
        v13 = facet;
      }
      else
      {
        v13 = v14 + 1;
      }
    }
  }
  v21 = &v6->objectValue->vfptr;
  v32 = unconditional;
  v22 = *v21;
  y = 0.5;
  x = targetZ;
  v29 = (double)point.y - -0.5;
  v28 = (double)point.x - -0.5;
  if( (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, signed int, int))&v22->gap154[0])(
         LODWORD(v28),
         LODWORD(v29),
         LODWORD(targetZ),
         1056964608,
         unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v6, 610);
    UnitAIModule::setCurrentTarget(v6, -1, targetX, targetY, targetZ);
    result = 1;
  }
  else
  {
LABEL_34:
    result = 0;
  }
  return result;
}

//----- (004171F0) --------------------------------------------------------
int __userpurge UnitAIModule::runAwayFromAttackers@<eax>(UnitAIModule *this@<ecx>, double a2@<st0>, int unconditional)
{
  UnitAIModule *v3; // esi@1
  int result; // eax@3
  int v5; // ebx@4
  int v6; // ebp@6
  int *v7; // edi@6
  int i; // eax@7
  RGE_Static_Object *v9; // eax@11
  RGE_Static_Object *v10; // ecx@12
  double v11; // st6@14
  RGE_Static_Object *v12; // eax@14
  double v13; // rt1@14
  double v14; // st6@14
  float v15; // ST04_4@14
  float v16; // ST00_4@14
  float xDiff; // [sp+20h] [bp-4h]@4
  float unconditionala; // [sp+28h] [bp+4h]@4
  int unconditionalb; // [sp+28h] [bp+4h]@14
  int unconditionalc; // [sp+28h] [bp+4h]@14

  v3 = this;
  if( unconditional || this->currentActionValue == -1 )
  {
    v5 = 0;
    xDiff = 0.0;
    unconditionala = 0.0;
    if( this->attackingUnitsValue.numberValue > 0 )
    {
      do
      {
        if( v5 > v3->attackingUnitsValue.maximumSizeValue - 1 )
        {
          v6 = v5 + 1;
          v7 = (int *)operator new(4 * v5 + 4);
          if( v7 )
          {
            for( i = 0; i < v3->attackingUnitsValue.maximumSizeValue; v7[i - 1] = v3->attackingUnitsValue.value[i - 1] )
            {
              if( i >= v6 )
                break;
              ++i;
            }
            operator delete(v3->attackingUnitsValue.value);
            v3->attackingUnitsValue.value = v7;
            v3->attackingUnitsValue.maximumSizeValue = v6;
          }
        }
        v9 = RGE_Game_World::object(v3->objectValue->owner->world, v3->attackingUnitsValue.value[v5]);
        if( v9 )
        {
          v10 = v3->objectValue;
          a2 = v9->world_y - v10->world_y + unconditionala;
          xDiff = v9->world_x - v10->world_x + xDiff;
          unconditionala = a2;
        }
        ++v5;
      }
      while( v5 < v3->attackingUnitsValue.numberValue );
    }
    ((void (*)(void))v3->objectValue->vfptr->maximumSpeed)();
    v11 = unconditionala;
    v12 = v3->objectValue;
    *(float *)&unconditionalb = sqrt(xDiff * xDiff + unconditionala * unconditionala);
    v13 = v11 / *(float *)&unconditionalb;
    v14 = xDiff / *(float *)&unconditionalb;
    *(float *)&unconditionalc = a2 * 4.0;
    v15 = v12->world_y - v13 * *(float *)&unconditionalc;
    v16 = v12->world_x - v14 * *(float *)&unconditionalc;
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v3->vfptr->evasiveMoveTo)(
               LODWORD(v16),
               LODWORD(v15),
               LODWORD(v12->world_z),
               1);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00417360) --------------------------------------------------------
RGE_Static_Object *__thiscall UnitAIModule::followObject(UnitAIModule *this, int targetID, float desiredDistance, int unconditional)
{
  UnitAIModule *v4; // edi@1
  RGE_Static_Object *result; // eax@3
  int v6; // esi@4

  v4 = this;
  if( unconditional || this->currentActionValue == -1 )
  {
    result = RGE_Game_World::object(this->objectValue->owner->world, targetID);
    v6 = (int)result;
    if( result )
    {
      UnitAIModule::setCurrentAction(v4, 612);
      UnitAIModule::setCurrentTarget(v4, targetID, *(float *)(v6 + 56), *(float *)(v6 + 60), *(float *)(v6 + 64));
      result = (RGE_Static_Object *)1;
      v4->desiredTargetDistanceValue = desiredDistance;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004173D0) --------------------------------------------------------
RGE_Static_Object *__thiscall UnitAIModule::defendObject(UnitAIModule *this, int targetID, float desiredDistance, int unconditional)
{
  UnitAIModule *v4; // esi@1
  RGE_Static_Object *result; // eax@3
  int v6; // edi@4

  v4 = this;
  if( unconditional || this->currentActionValue == -1 )
  {
    result = RGE_Game_World::object(this->objectValue->owner->world, targetID);
    v6 = (int)result;
    if( result )
    {
      UnitAIModule::setCurrentAction(v4, 601);
      UnitAIModule::setCurrentTarget(v4, targetID, *(float *)(v6 + 56), *(float *)(v6 + 60), *(float *)(v6 + 64));
      v4->defendTargetValue = targetID;
      v4->desiredTargetDistanceValue = desiredDistance;
      result = (RGE_Static_Object *)1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00417440) --------------------------------------------------------
int __thiscall UnitAIModule::defendPosition(UnitAIModule *this, float targetX, float targetY, float desiredDistance, int unconditional)
{
  UnitAIModule *v5; // esi@1
  int result; // eax@3

  v5 = this;
  if( unconditional || this->currentActionValue == -1 )
  {
    UnitAIModule::setCurrentAction(this, 601);
    UnitAIModule::setCurrentTarget(v5, -1, targetX, targetY, v5->objectValue->world_z);
    v5->defendTargetValue = -1;
    v5->desiredTargetDistanceValue = desiredDistance;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004174A0) --------------------------------------------------------
int __thiscall UnitAIModule::seekAndDestroy(UnitAIModule *this, int targetID, int tX, int tY, int unconditional)
{
  UnitAIModule *v5; // esi@1
  float y; // ST0C_4@4
  float x; // ST08_4@4
  int result; // eax@4

  v5 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(int, int))this->objectValue->vfptr->attack)(targetID, unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v5, 622);
    y = (double)tY;
    x = (double)tX;
    UnitAIModule::setCurrentTarget(v5, targetID, x, y, 1.0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00417510) --------------------------------------------------------
int __thiscall UnitAIModule::exploreAndDestroy(UnitAIModule *this, int tX, int tY, int unconditional)
{
  UnitAIModule *v4; // esi@1
  float y; // ST10_4@4
  float x; // ST0C_4@4
  int result; // eax@4

  v4 = this;
  if( (unconditional || this->currentActionValue == -1)
    && ((int (__stdcall *)(int, int, int))this->objectValue->vfptr->explore)(tX, tY, unconditional) == 1 )
  {
    UnitAIModule::setCurrentAction(v4, 623);
    y = (double)tY;
    x = (double)tX;
    UnitAIModule::setCurrentTarget(v4, -1, x, y, 1.0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00417580) --------------------------------------------------------
void __thiscall UnitAIModule::removeCurrentTarget(UnitAIModule *this)
{
  int v1; // edx@1

  v1 = this->currentTargetTypeValue;
  this->lastTargetValue = this->currentTargetValue;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  this->lastTargetTypeValue = v1;
  LODWORD(this->currentTargetXValue) = -1082130432;
  LODWORD(this->currentTargetYValue) = -1082130432;
  LODWORD(this->currentTargetZValue) = -1082130432;
}

//----- (004175B0) --------------------------------------------------------
void __thiscall UnitAIModule::setCurrentTarget(UnitAIModule *this, int o, float x, float y, float z)
{
  UnitAIModule *v5; // esi@1
  int v6; // eax@1
  int v7; // ecx@1
  RGE_Static_Object *v8; // eax@1
  RGE_Static_Object *v9; // eax@1

  v5 = this;
  v6 = this->currentTargetValue;
  v7 = this->currentTargetTypeValue;
  v5->lastTargetValue = v6;
  v5->lastTargetTypeValue = v7;
  v5->currentTargetValue = o;
  v5->currentTargetXValue = x;
  v8 = v5->objectValue;
  v5->currentTargetYValue = y;
  v5->currentTargetZValue = z;
  v9 = RGE_Game_World::object(v8->owner->world, o);
  if( v9 )
    v5->currentTargetTypeValue = v9->master_obj->object_group;
}

//----- (00417600) --------------------------------------------------------
void __thiscall UnitAIModule::setCurrentTarget(UnitAIModule *this, int o, int t, float x, float y, float z)
{
  int v6; // edx@1

  v6 = this->currentTargetTypeValue;
  this->lastTargetValue = this->currentTargetValue;
  this->lastTargetTypeValue = v6;
  this->currentTargetValue = o;
  this->currentTargetTypeValue = t;
  this->currentTargetXValue = x;
  this->currentTargetYValue = y;
  this->currentTargetZValue = z;
}

//----- (00417640) --------------------------------------------------------
int __thiscall UnitAIModule::importantObject(UnitAIModule *this, int unitType)
{
  int v2; // edx@1
  int v3; // eax@1
  int *v4; // ecx@2
  int result; // eax@5

  v2 = this->numberImportantObjects;
  v3 = 0;
  if( v2 <= 0 )
  {
    result = 0;
  }
  else
  {
    v4 = this->importantObjects;
    while( *v4 != unitType )
    {
      ++v3;
      ++v4;
      if( v3 >= v2 )
        return 0;
    }
    result = 1;
  }
  return result;
}

//----- (00417680) --------------------------------------------------------
int __thiscall UnitAIModule::isEnemyOwner(UnitAIModule *this, int oID)
{
  RGE_Player *v2; // eax@1
  int result; // eax@2

  v2 = this->objectValue->owner;
  if( v2->id == oID )
    result = 0;
  else
    result = v2->relations[oID] == 3;
  return result;
}

//----- (004176B0) --------------------------------------------------------
int __thiscall UnitAIModule::isAllyOwner(UnitAIModule *this, int oID)
{
  RGE_Player *v2; // eax@1
  int v3; // edx@1
  int result; // eax@2

  v2 = this->objectValue->owner;
  v3 = v2->id;
  if( v3 == oID )
    result = 1;
  else
    result = !v2->relations[oID] && !v2->world->players[oID]->relations[v3];
  return result;
}

//----- (00417700) --------------------------------------------------------
int __thiscall UnitAIModule::isNeutralOwner(UnitAIModule *this, int oID)
{
  RGE_Player *v2; // eax@1
  int result; // eax@2

  v2 = this->objectValue->owner;
  if( v2->id == oID )
    result = 0;
  else
    result = v2->relations[oID] == 1;
  return result;
}

//----- (00417730) --------------------------------------------------------
char __thiscall UnitAIModule::visibleStatus(UnitAIModule *this, RGE_Visible_Map *vMap, int x, int y)
{
  RGE_Player *v4; // ecx@1
  unsigned __int32 *v5; // eax@1
  char result; // al@2

  v4 = this->objectValue->owner;
  v5 = (&unified_map_offsets)[y][x];
  if( (unsigned int)v5 & v4->mutualVisibleMask )
    result = 15;
  else
    result = ((unsigned int)v5 & v4->mutualExploredMask) != 0 ? 0x80 : 0;
  return result;
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (00417770) --------------------------------------------------------
void __thiscall UnitAIModule::setAdjustedIdleTimeout(UnitAIModule *this)
{
  unsigned int v1; // esi@1

  v1 = this->idleTimeoutValue;
  this->adjustedIdleTimeoutValue = (3 * v1 >> 2) + debug_rand(aCMsdevWorkA_43, 3916) % (v1 >> 1);
}

//----- (004177B0) --------------------------------------------------------
void __thiscall UnitAIModule::setTaskedByPlayer(UnitAIModule *this)
{
  UnitAIModule::purgeNotifyQueue(this, 0);
}

//----- (004177C0) --------------------------------------------------------
int __stdcall UnitAIModule::convertToLOSResourceType(int type)
{
  return -1;
}

//----- (004177D0) --------------------------------------------------------
void __thiscall UnitAIModule::setPlayStatus(UnitAIModule *this, AIPlayStatus *ps)
{
  UnitAIModule *v2; // esi@1
  AIPlayStatus *v3; // eax@2
  AIPlayStatus *v4; // eax@3
  AIPlayStatus *v5; // ecx@6

  v2 = this;
  if( !this->playStatus )
  {
    v3 = (AIPlayStatus *)operator new(0x1C8u);
    if( v3 )
      AIPlayStatus::AIPlayStatus(v3);
    else
      v4 = 0;
    v2->playStatus = v4;
  }
  v5 = v2->playStatus;
  if( v5 )
  {
    if( ps )
      AIPlayStatus::copy(v5, ps);
  }
}

//----- (00417860) --------------------------------------------------------
void __thiscall UnitAIModule::lookAround(UnitAIModule *this)
{
  UnitAIModule *v1; // ebp@1
  RGE_Static_Object *v2; // eax@1
  signed int v3; // esi@1
  int v4; // ebx@1
  RGE_Player *v5; // eax@1
  int i; // edi@2
  RGE_Static_Object *v7; // eax@3
  RGE_Game_World *world; // [sp+10h] [bp-8h]@1
  int ownerID; // [sp+14h] [bp-4h]@1

  v1 = this;
  ((void (*)(void))this->vfptr->search)();
  v2 = v1->objectValue;
  v3 = 0;
  v4 = v2->id;
  v5 = v2->owner;
  ownerID = v5->id;
  world = v5->world;
  do
  {
    for( i = 0; i < dword_87D7D8[v3]; ++i )
    {
      v7 = RGE_Game_World::object(world, *(_DWORD *)(dword_87D7F0[v3] + 8 * i));
      if( v7 && v7->object_state <= 2u )
        ((void (__stdcall *)(_DWORD, int, signed int, _DWORD, _DWORD, _DWORD))v1->objectValue->owner->vfptr->notify)(
          v4,
          ownerID,
          525,
          v7->id,
          0,
          0);
    }
    --v3;
  }
  while( v3 > -2 );
  v1->lookAroundTimerValue = 0;
  v1->lookAroundTimeoutValue = debug_rand(aCMsdevWorkA_43, 3986) % 1000 + 4000;
}
// 87D7D8: using guessed type int dword_87D7D8[];
// 87D7F0: using guessed type int dword_87D7F0[];

//----- (00417920) --------------------------------------------------------
int __thiscall UnitAIModule::hasOrderOnQueue(UnitAIModule *this, int orderNumber)
{
  int v2; // edx@1
  int v3; // eax@1
  char *v4; // ecx@2
  int result; // eax@5

  v2 = this->orderQueueSizeValue;
  v3 = 0;
  if( v2 <= 0 )
  {
    result = 0;
  }
  else
  {
    v4 = (char *)&this->orderQueueValue->orderType;
    while( *(_DWORD *)v4 != orderNumber )
    {
      ++v3;
      v4 += 36;
      if( v3 >= v2 )
        return 0;
    }
    result = 1;
  }
  return result;
}

//----- (00417960) --------------------------------------------------------
void __userpurge UnitAIModule::askForHelp(UnitAIModule *this@<ecx>, int unitToAttack, int a3, int a4, int a5)
{
  UnitAIModule *v5; // edi@1
  RGE_Static_Object *v6; // ebp@1
  signed int v7; // ebx@2
  RGE_Static_Object *v8; // eax@5
  RGE_Static_Object *v9; // esi@5
  RGE_Player *v10; // ecx@7
  __int16 v11; // ax@9
  __int16 v12; // ax@16
  long double v13; // st7@18
  UnitAIModule *v14; // eax@19
  UnitAIModule *v15; // eax@20
  UnitAIModule *v16; // eax@21
  UnitAIModule *v17; // edi@22
  float v18; // ST38_4@22
  UnitAIModuleVtbl *v19; // ebx@22
  float v20; // ST1C_4@22
  int i; // [sp+30h] [bp-10h]@3
  signed int v22; // [sp+34h] [bp-Ch]@2
  UnitAIModule *v23; // [sp+3Ch] [bp-4h]@1

  v5 = this;
  v23 = this;
  v6 = UnitAIModule::lookupObject(this, unitToAttack);
  if( v6 )
  {
    v5->vfptr->search(v5);
    v7 = 0;
    v22 = 0;
    do
    {
      for( i = 0; i < *(int *)((char *)&dword_87D7CC + v7); ++i )
      {
        if( v5->objectValue->id != *(_DWORD *)(8 * i + *(int *)((char *)&dword_87D7E4 + v7)) )
        {
          v8 = UnitAIModule::lookupObject(v5, *(_DWORD *)(8 * i + *(int *)((char *)&dword_87D7E4 + v7)));
          v9 = v8;
          if( v8 )
          {
            if( RGE_Static_Object::unitAI(v8) )
            {
              v10 = v9->owner;
              if( v10 )
              {
                if( v9->object_state <= 2u )
                {
                  v11 = v9->master_obj->object_group;
                  if( v11 != 1 && v11 != 3 && v11 != 4 && v11 != 21 && v11 != 18 && v11 != 20 && v11 != 27 )
                  {
                    v12 = v5->objectValue->owner->id;
                    if( v10->id == v12 || (*(int (__stdcall **)(_DWORD))&v10->vfptr->gap4[24])(v12) )
                    {
                      v13 = RGE_Static_Object::distance_to_object(v5->objectValue, v9);
                      if( v13 <= 3.0 )
                      {
                        v14 = RGE_Static_Object::unitAI(v9);
                        if( UnitAIModule::currentAction(v14) == -1 )
                        {
                          v15 = RGE_Static_Object::unitAI(v9);
                          if( UnitAIModule::currentOrder(v15) == -1 )
                          {
                            v16 = RGE_Static_Object::unitAI(v9);
                            if( UnitAIModule::orderQueueSize(v16) <= 0 )
                            {
                              v17 = RGE_Static_Object::unitAI(v9);
                              v18 = v6->world_y;
                              v19 = v17->vfptr;
                              ((void (__thiscall *)(RGE_Static_Object *, signed int, _DWORD, signed int))v9->vfptr->weaponRange)(
                                v9,
                                1,
                                0,
                                50);
                              v20 = v13;
                              (*(void (__thiscall **)(UnitAIModule *, _DWORD, signed int, int, _DWORD, _DWORD, int, int, _DWORD))&v19->gap4[12])(
                                v17,
                                v9->owner->id,
                                700,
                                a5,
                                v6->owner->id,
                                LODWORD(v6->world_x),
                                unitToAttack,
                                unitToAttack,
                                LODWORD(v20));
                              v5 = v23;
                              v7 = v22;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v7 += 4;
      v22 = v7;
    }
    while( v7 <= 4 );
  }
}
// 87D7CC: using guessed type int dword_87D7CC;
// 87D7E4: using guessed type int dword_87D7E4;

//----- (00417B50) --------------------------------------------------------
BOOL __thiscall UnitAIModule::processOrder(UnitAIModule *this, OrderEvent *oEvent, int orderNumber)
{
  signed int v3; // ebx@1
  UnitAIModule *v4; // esi@1
  AIPlayStatus *v5; // eax@6
  AIPlayStatus *v6; // eax@7
  int v7; // ST24_4@12
  AIPlayStatus *v8; // ebp@12
  signed __int64 v9; // rax@12
  RGE_Static_Object *v10; // ebp@13
  int v11; // ST24_4@13
  signed __int64 v12; // rax@13
  AIPlayStatus *v13; // ecx@13
  RGE_Static_Object *v14; // eax@17
  signed int v15; // eax@18
  int v16; // eax@21
  int v17; // eax@24
  UnitAIModuleVtbl *v18; // edx@24
  RGE_Static_Object *v19; // eax@38
  signed int v20; // eax@39
  int v21; // eax@51
  int v22; // eax@52
  int v23; // ecx@62
  int v24; // edx@64
  int v25; // eax@65
  int v26; // ecx@66

  v3 = 0;
  v4 = this;
  switch ( oEvent->orderType )
  {
    case 0x2D6:
      v3 = 1;
      if( AIPlayBook::play(this->objectValue->owner->world->playbook, oEvent->targetOwner) )
      {
        if( v4->playStatus )
          operator delete(v4->playStatus);
        v5 = (AIPlayStatus *)operator new(0x1C8u);
        if( v5 )
          AIPlayStatus::AIPlayStatus(v5);
        else
          v6 = 0;
        v4->playStatus = v6;
        if( v6 )
        {
          v6->playNumberValue = oEvent->targetOwner;
          v4->playStatus->targetValue = oEvent->target;
          if( LODWORD(oEvent->targetX) == -1082130432 )
          {
            v10 = v4->objectValue;
            v11 = (signed __int64)v10->world_z;
            v12 = (signed __int64)v10->world_x;
            v13 = v4->playStatus;
            HIDWORD(v12) = (signed __int64)v10->world_y;
            *(_QWORD *)&v13->originalPointValue.xValue = v12;
            v13->originalPointValue.zValue = v11;
          }
          else
          {
            v7 = (signed __int64)oEvent->targetZ;
            v8 = v4->playStatus;
            v9 = (signed __int64)oEvent->targetX;
            HIDWORD(v9) = (signed __int64)oEvent->targetY;
            *(_QWORD *)&v8->originalPointValue.xValue = v9;
            v8->originalPointValue.zValue = v7;
          }
        }
        else
        {
          v3 = 0;
        }
      }
      else
      {
        v3 = 0;
      }
      break;
    case 0x2D7:
      if( !this->playStatus )
        goto LABEL_43;
      operator delete(this->playStatus);
      v4->playStatus = 0;
      v3 = 1;
      break;
    case 0x2C2:
      UnitAIModule::removeCurrentTarget(this);
      if( !actionFile )
        goto LABEL_42;
      v14 = v4->objectValue;
      if( v14 )
        v15 = v14->id;
      else
        v15 = -1;
      fprintf(actionFile, aDCallStopobjec, v15, aCMsdevWorkA_43, 4189);
      v4->vfptr->stopObject(v4, 1);
      v3 = 1;
      break;
    case 0x2C6:
      v16 = (*(int (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD, signed int))&this->vfptr->gap90[0])(
              this,
              LODWORD(oEvent->targetX),
              LODWORD(oEvent->targetY),
              LODWORD(oEvent->targetZ),
              LODWORD(oEvent->range),
              1);
      goto LABEL_49;
    case 0x2BC:
      v16 = this->vfptr->attackObject(this, oEvent->target, 1);
      goto LABEL_49;
    case 0x2D9:
      v16 = ((int (__stdcall *)(int))this->vfptr->attackRoundupObject)(oEvent->target);
      goto LABEL_49;
    case 0x2BD:
      v17 = oEvent->target;
      v18 = this->vfptr;
      if( v17 == -1 )
        v16 = ((int (__thiscall *)(UnitAIModule *, _DWORD, _DWORD, _DWORD, signed int))v18->defendPosition)(
                this,
                LODWORD(oEvent->targetX),
                LODWORD(oEvent->targetY),
                LODWORD(oEvent->range),
                1);
      else
        v16 = ((int (__stdcall *)(int, _DWORD, signed int))v18->defendObject)(v17, LODWORD(oEvent->range), 1);
      goto LABEL_49;
    case 0x2CE:
      v16 = ((int (__stdcall *)(int, signed int))this->vfptr->repairObject)(oEvent->target, 1);
      goto LABEL_49;
    case 0x2D1:
      v16 = ((int (__thiscall *)(UnitAIModule *, signed int, _DWORD, _DWORD))this->vfptr->unload)(
              this,
              1,
              LODWORD(oEvent->targetX),
              LODWORD(oEvent->targetY));
      goto LABEL_49;
    case 0x2D2:
      v16 = ((int (__stdcall *)(int, _DWORD, _DWORD, signed int))this->vfptr->seekAndDestroy)(
              oEvent->target,
              (signed __int64)oEvent->targetX,
              (signed __int64)oEvent->targetY,
              1);
      goto LABEL_49;
    case 0x2D3:
      v16 = ((int (__fastcall *)(UnitAIModule *, _DWORD, _DWORD, _DWORD, signed int))this->vfptr->exploreAndDestroy)(
              this,
              (unsigned __int64)(signed __int64)oEvent->targetX >> 32,
              (signed __int64)oEvent->targetX,
              (signed __int64)oEvent->targetY,
              1);
      goto LABEL_49;
    case 0x2C1:
      v16 = ((int (__fastcall *)(UnitAIModule *, _DWORD, _DWORD, _DWORD, signed int))this->vfptr->explore)(
              this,
              (unsigned __int64)(signed __int64)oEvent->targetX >> 32,
              (signed __int64)oEvent->targetX,
              (signed __int64)oEvent->targetY,
              1);
      goto LABEL_49;
    case 0x2BE:
      v16 = this->vfptr->buildObject(this, oEvent->target, 1);
      goto LABEL_49;
    case 0x2D4:
      v16 = (*(int (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD, signed int))&this->vfptr->gap90[0])(
              this,
              LODWORD(oEvent->targetX),
              LODWORD(oEvent->targetY),
              LODWORD(oEvent->targetZ),
              LODWORD(oEvent->range),
              1);
      goto LABEL_49;
    case 0x2C8:
      v16 = ((int (__thiscall *)(UnitAIModule *, int, _DWORD, signed int))this->vfptr->followObject)(
              this,
              oEvent->target,
              LODWORD(oEvent->range),
              1);
      goto LABEL_49;
    case 0x2CD:
      v16 = ((int (__stdcall *)(int, signed int))this->vfptr->enterObject)(oEvent->target, 1);
      goto LABEL_49;
    case 0x2CA:
      v16 = ((int (__thiscall *)(UnitAIModule *, _DWORD, _DWORD, _DWORD, signed int))this->vfptr->transportObject)(
              this,
              LODWORD(oEvent->targetX),
              LODWORD(oEvent->targetY),
              LODWORD(oEvent->targetZ),
              1);
      goto LABEL_49;
    case 0x2D5:
      UnitAIModule::removeCurrentTarget(this);
      if( actionFile )
      {
        v19 = v4->objectValue;
        if( v19 )
          v20 = v19->id;
        else
          v20 = -1;
        fprintf(actionFile, aDCallStopobjec, v20, aCMsdevWorkA_43, 4329);
      }
LABEL_42:
      v4->vfptr->stopObject(v4, 1);
LABEL_43:
      v3 = 1;
      break;
    case 0x2BF:
      v16 = this->vfptr->healObject(this, oEvent->target, 1);
      goto LABEL_49;
    case 0x2C0:
      v16 = ((int (__stdcall *)(int, signed int))this->vfptr->convertObject)(oEvent->target, 1);
      goto LABEL_49;
    case 0x2D8:
      v3 = 1;
      this->currentActionValue = 628;
      this->currentOrderValue = 728;
      break;
    case 0x2C5:
      v16 = ((int (__stdcall *)(int, signed int))this->vfptr->gatherObject)(oEvent->target, 1);
      goto LABEL_49;
    case 0x2C9:
      v16 = ((int (__stdcall *)(int, signed int))this->vfptr->huntObject)(oEvent->target, 1);
LABEL_49:
      v3 = v16;
      break;
    default:
      break;
  }
  if( v3 == 1 )
  {
    v21 = oEvent->orderType;
    if( v21 == 706 )
    {
      v22 = -1;
      v4->currentOrderValue = -1;
    }
    else
    {
      if( v21 == 729 )
      {
        v4->currentOrderValue = 700;
      }
      else if( v21 != 700 || v4->objectValue->master_obj->id != 125 )
      {
        v4->currentOrderValue = v21;
      }
      else
      {
        v4->currentOrderValue = -1;
        v4->currentTargetValue = -1;
      }
      v22 = oEvent->priority;
    }
    v4->currentOrderPriorityValue = v22;
  }
  if( orderNumber >= 0 )
  {
    v23 = v4->orderQueueSizeValue;
    if( orderNumber < v23 )
    {
      if( v4->orderQueueValue )
      {
        v24 = orderNumber;
        if( orderNumber < v23 - 1 )
        {
          v25 = orderNumber;
          do
          {
            v4->orderQueueValue[v25].issuer = v4->orderQueueValue[v25 + 1].issuer;
            v4->orderQueueValue[v25].orderType = v4->orderQueueValue[v25 + 1].orderType;
            v4->orderQueueValue[v25].priority = v4->orderQueueValue[v25 + 1].priority;
            v4->orderQueueValue[v25].target = v4->orderQueueValue[v25 + 1].target;
            v4->orderQueueValue[v25].targetOwner = v4->orderQueueValue[v25 + 1].targetOwner;
            v4->orderQueueValue[v25].targetX = v4->orderQueueValue[v25 + 1].targetX;
            v4->orderQueueValue[v25].targetY = v4->orderQueueValue[v25 + 1].targetY;
            v26 = (int)&v4->orderQueueValue[v25].issuer;
            ++v24;
            ++v25;
            *(_DWORD *)(v26 + 28) = *(_DWORD *)(v26 + 64);
          }
          while( v24 < v4->orderQueueSizeValue - 1 );
        }
        --v4->orderQueueSizeValue;
      }
    }
  }
  return v3 == 1;
}

//----- (004180C0) --------------------------------------------------------
int __userpurge UnitAIModule::processNotify@<eax>(UnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime, int tileY, int a6, _DWORD *a7)
{
  NotifyEvent *v7; // ebp@1
  UnitAIModule *v8; // esi@1
  int result; // eax@3
  int v10; // ecx@7
  int v11; // eax@7
  int v12; // ecx@14
  int v13; // ebx@14
  int i; // eax@14
  int v15; // ebp@19
  int *v16; // edi@19
  int j; // eax@20
  int v18; // eax@26
  RGE_Static_Object *v19; // eax@30
  RGE_Static_Object *v20; // edi@30
  RGE_Static_Object *v21; // ebp@35
  RGE_Static_Object *v22; // ecx@40
  RGE_Static_ObjectVtbl *v23; // edi@40
  float v24; // ST6C_4@40
  RGE_Master_Static_Object *v25; // eax@46
  __int16 v26; // cx@46
  __int16 v27; // ax@48
  RGE_Static_Object *v28; // ecx@54
  RGE_Static_ObjectVtbl *v29; // edi@54
  float v30; // ST6C_4@54
  RGE_Static_Object *v31; // ecx@65
  RGE_Static_ObjectVtbl *v32; // ebx@65
  float v33; // ST6C_4@65
  double v34; // st7@74
  RGE_Static_Object *v35; // ecx@76
  RGE_Static_ObjectVtbl *v36; // edi@76
  float v37; // ST6C_4@76
  RGE_Static_Object *v38; // eax@78
  RGE_Static_Object *v39; // edi@78
  char v40; // al@79
  unsigned int v41; // eax@81
  UnitAIModuleVtbl *v42; // edi@81
  int v43; // eax@81
  int v44; // eax@87
  RGE_Static_Object *v45; // eax@89
  int v46; // eax@92
  UnitAIModuleVtbl *v47; // edi@94
  float v48; // ST68_4@97
  RGE_Static_Object *v49; // eax@99
  signed int v50; // eax@100
  int v51; // edx@103
  RGE_Static_Object *v52; // eax@105
  signed int v53; // eax@106
  RGE_Static_Object *v54; // eax@113
  signed int v55; // eax@114
  RGE_Static_Object *v56; // eax@120
  signed int v57; // eax@121
  RGE_Static_Object *v58; // eax@127
  signed int v59; // eax@128
  RGE_Static_Object *v60; // eax@138
  signed int v61; // eax@139
  int v62; // eax@142
  UnitAIModuleVtbl *v63; // edi@144
  float v64; // ST68_4@147
  RGE_Static_Object *v65; // eax@149
  signed int v66; // eax@150
  RGE_Static_Object *v67; // eax@154
  signed int v68; // eax@155
  RGE_Static_Object *v69; // eax@161
  RGE_Static_Object *v70; // eax@167
  RGE_Static_Object *v71; // eax@173
  signed int v72; // eax@174
  UnitAIModuleVtbl *v73; // edi@176
  RGE_Static_Object *v74; // eax@183
  signed int v75; // eax@184
  int v76; // eax@187
  float v77; // ST68_4@192
  RGE_Static_Object *v78; // eax@194
  signed int v79; // eax@195
  int v80; // ecx@198
  RGE_Static_Object *v81; // eax@200
  signed int v82; // eax@201
  RGE_Static_Object *v83; // eax@208
  RGE_Static_Object *v84; // eax@214
  RGE_Static_Object *v85; // eax@220
  signed int v86; // eax@221
  RGE_Static_Object *v87; // eax@231
  signed int v88; // eax@232
  int v89; // ebp@235
  int v90; // ebx@238
  UnitAIModuleVtbl *v91; // edi@240
  int v92; // eax@240
  int v93; // eax@241
  RGE_Static_Object *v94; // eax@247
  signed int v95; // eax@248
  RGE_Static_Object *v96; // eax@252
  signed int v97; // eax@253
  RGE_Static_Object *v98; // eax@260
  signed int v99; // eax@261
  RGE_Static_Object *v100; // eax@268
  signed int v101; // eax@269
  RGE_Static_Object *v102; // eax@274
  signed int v103; // eax@275
  RGE_Static_Object *v104; // edx@278
  RGE_Static_Object *v105; // eax@278
  RGE_Static_Object *v106; // eax@281
  signed int v107; // eax@282
  int v108; // ecx@286
  int v109; // ebp@286
  int v110; // eax@286
  int v111; // ebx@291
  int *v112; // edi@291
  int k; // eax@292
  int v114; // ecx@298
  int v115; // eax@298
  int v116; // ecx@303
  int v117; // eax@303
  int *v118; // edx@304
  int v119; // eax@310
  RGE_Static_Object *v120; // eax@313
  signed int v121; // eax@314
  int v122; // [sp+70h] [bp-1Ch]@0
  int v123; // [sp+74h] [bp-18h]@0
  int v124; // [sp+78h] [bp-14h]@0
  UnitAIModuleVtbl *v125; // [sp+80h] [bp-Ch]@2
  int tileX; // [sp+84h] [bp-8h]@59
  float lastTargetXValue; // [sp+88h] [bp-4h]@62
  NotifyEvent *nEventa; // [sp+90h] [bp+4h]@81

  v7 = nEvent;
  v8 = this;
  switch ( nEvent->mType )
  {
    case 0x1F4:
    case 0x20F:
      v125 = this->vfptr;
      ((void (__thiscall *)(UnitAIModule *, NotifyEvent *))this->vfptr->notifyCommander)(this, nEvent);
      if( nEvent->p2 <= 0 )
      {
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v8->objectValue->owner->vfptr->notify)(
          v8->objectValue->id,
          v8->objectValue->id,
          521,
          nEvent->caller,
          0,
          0);
        UnitAIModule::purgeNotifyQueue(v8, uTime);
        return 4;
      }
      if( !v8->attackingUnitsValue.numberValue || RGE_Player::computerPlayer(v8->objectValue->owner) == 1 )
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v8->objectValue->owner->vfptr->notify)(
          v8->objectValue->id,
          v8->objectValue->id,
          513,
          nEvent->caller,
          0,
          0);
      v10 = v8->attackingUnitsValue.numberValue;
      v11 = 0;
      if( v10 <= 0 )
        goto LABEL_11;
      do
      {
        if( v11 >= v8->attackingUnitsValue.maximumSizeValue )
          break;
        if( v8->attackingUnitsValue.value[v11] == nEvent->caller )
          goto LABEL_14;
        ++v11;
      }
      while( v11 < v10 );
LABEL_11:
      if( !RGE_Player::computerPlayer(v8->objectValue->owner) && v8->currentTargetValue != nEvent->caller )
        UnitAIModule::askForHelp(v8, nEvent->caller, v122, v123, v124);
LABEL_14:
      v12 = v8->attackingUnitsValue.numberValue;
      v13 = nEvent->caller;
      for( i = 0; i < v12; ++i )
      {
        if( i >= v8->attackingUnitsValue.maximumSizeValue )
          break;
        if( v8->attackingUnitsValue.value[i] == v13 )
          goto LABEL_26;
      }
      if( v12 > v8->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v15 = v12 + 1;
        v16 = (int *)operator new(4 * (v12 + 1));
        if( v16 )
        {
          for( j = 0; j < v8->attackingUnitsValue.maximumSizeValue; v16[j - 1] = v8->attackingUnitsValue.value[j - 1] )
          {
            if( j >= v15 )
              break;
            ++j;
          }
          operator delete(v8->attackingUnitsValue.value);
          v8->attackingUnitsValue.value = v16;
          v8->attackingUnitsValue.maximumSizeValue = v15;
        }
        v7 = nEvent;
      }
      v8->attackingUnitsValue.value[v8->attackingUnitsValue.numberValue++] = v13;
LABEL_26:
      ((void (__stdcall *)(signed int))v8->objectValue->vfptr->setUnderAttack)(1);
      v18 = v8->currentOrderValue;
      if( v18 != 725 && v18 != -1 && !RGE_Player::computerPlayer(v8->objectValue->owner) )
        return 2;
      if( v8->currentOrderValue == 725 )
        return 2;
      v19 = UnitAIModule::lookupObject(v8, v7->caller);
      v20 = v19;
      if( !v19 || v19->owner->id == v8->objectValue->owner->id )
        return 2;
      if( v8->currentActionValue != 603 || v125->runAwayFromAttackers(v8, 1) != 1 )
      {
        v21 = 0;
        if( v8->currentTargetValue != -1 )
          v21 = UnitAIModule::lookupObject(v8, v8->currentTargetValue);
        if( v21 )
        {
          v25 = v21->master_obj;
          v26 = v25->object_group;
          if( v26 != 3 && v26 != 27
            || (v27 = v25->id, v27 == 79)
            || v27 == 199
            || v27 == 69
            || RGE_Player::computerPlayer(v8->objectValue->owner) )
          {
            if( RGE_Player::computerPlayer(v8->objectValue->owner) != 1 || v21->master_obj->id == 276 )
              return 2;
            tileX = (int)v21->vfptr;
            (*(void (__thiscall **)(RGE_Static_Object *))(tileX + 264))(v21);
            if( a2 == 0.0 )
            {
              *(float *)&uTime = 0.0;
            }
            else
            {
              (*((void (__stdcall **)(RGE_Static_Object *))&v8->objectValue->vfptr->rateOfFire + 1))(v21);
              *(float *)&uTime = a2;
            }
            lastTargetXValue = *(float *)&v125->canAttackUnit;
            if( ((int (__thiscall *)(UnitAIModule *, RGE_Static_Object *))LODWORD(lastTargetXValue))(v8, v20) == 1 )
            {
              a2 = *(float *)&uTime;
              if( *(float *)&uTime == 0.0 )
              {
                if( ((int (__stdcall *)(RGE_Static_Object *))v8->objectValue->vfptr->inAttackRange)(v20) == 1
                  || (v31 = v8->objectValue,
                      v32 = v31->vfptr,
                      ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v31->vfptr->weaponRange)(
                        0,
                        0,
                        -1,
                        -1),
                      v33 = a2,
                      (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v32->pause + 1))(
                        v8->objectValue,
                        *a7,
                        LODWORD(v33)) == 1) )
                {
                  v125->attackObject(v8, nEvent->caller, 1);
                }
              }
            }
            (*(void (__thiscall **)(RGE_Static_Object *, RGE_Static_Object *))(tileX + 260))(v21, v8->objectValue);
            *(float *)&tileX = a2 <= 0.0 ? 25000.0 : (float)(v21->hp / a2);
            (*((void (__thiscall **)(RGE_Static_Object *, RGE_Static_Object *))&v20->vfptr->rateOfFire + 1))(
              v20,
              v8->objectValue);
            *(float *)&uTime = a2 <= 0.0 ? 25000.0 : (float)(v20->hp / a2);
            if( ((int (__thiscall *)(UnitAIModule *, RGE_Static_Object *))LODWORD(lastTargetXValue))(v8, v20) != 1 )
              return 2;
            v34 = *(float *)&uTime;
            if( *(float *)&uTime >= (double)*(float *)&tileX )
              return 2;
            if( ((int (__stdcall *)(RGE_Static_Object *))v8->objectValue->vfptr->inAttackRange)(v20) != 1 )
            {
              v35 = v8->objectValue;
              v36 = v35->vfptr;
              ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v35->vfptr->weaponRange)(0, 0, -1, -1);
              v37 = v34;
              if( (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v36->pause + 1))(
                     v8->objectValue,
                     *a7,
                     LODWORD(v37)) != 1 )
                return 2;
            }
            v125->attackObject(v8, nEvent->caller, 1);
            result = 2;
          }
          else if( v125->canAttackUnit(v8, v20) != 1
                 || ((int (__stdcall *)(_DWORD))v8->objectValue->vfptr->inAttackRange)(v20) != 1
                 && (v28 = v8->objectValue,
                     v29 = v28->vfptr,
                     ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v28->vfptr->weaponRange)(0, 0, -1, -1),
                     v30 = a2,
                     (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v29->pause + 1))(
                       v8->objectValue,
                       *a7,
                       LODWORD(v30)) != 1) )
          {
            v125->runAwayFromAttackers(v8, 1);
            result = 3;
          }
          else
          {
            v125->attackObject(v8, nEvent->caller, 1);
            result = 3;
          }
        }
        else if( v125->canAttackUnit(v8, v20) != 1
               || ((int (__stdcall *)(_DWORD))v8->objectValue->vfptr->inAttackRange)(v20) != 1
               && (v22 = v8->objectValue,
                   v23 = v22->vfptr,
                   ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v22->vfptr->weaponRange)(0, 0, -1, -1),
                   v24 = a2,
                   (*((int (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD))&v23->pause + 1))(
                     v8->objectValue,
                     *a7,
                     LODWORD(v24)) != 1) )
        {
          if( v8->currentActionValue == 610 )
            goto LABEL_266;
          v125->runAwayFromAttackers(v8, 1);
          result = 3;
        }
        else
        {
          if( v125->attackObject(v8, nEvent->caller, 1) != 1 || v8->currentOrderValue == 700 )
            goto LABEL_266;
          v8->currentOrderValue = -1;
          result = 3;
        }
      }
      else
      {
        result = 3;
      }
      return result;
    case 0x1FC:
      v38 = UnitAIModule::lookupObject(this, this->currentTargetValue);
      v39 = v38;
      if( !v38 )
        goto LABEL_88;
      v40 = UnitAIModule::visibleStatus(
              v8,
              v8->objectValue->owner->visible,
              (signed __int64)v38->world_x,
              (signed __int64)v38->world_y);
      if( !v39->owner->id || v40 == 15 )
        return 2;
      v41 = LODWORD(v8->currentTargetYValue);
      v42 = v8->vfptr;
      nEventa = (NotifyEvent *)LODWORD(v8->currentTargetZValue);
      lastTargetXValue = v8->currentTargetXValue;
      uTime = v41;
      v43 = v42->bestUnitToAttack(v8, 1, 0, 0);
      if( v43 == -1 || v43 == v8->currentTargetValue || v42->attackObject(v8, v43, 1) != 1 )
      {
        if( RGE_Player::computerPlayer(v8->objectValue->owner)
          || (*(int (__thiscall **)(UnitAIModule *, _DWORD, unsigned int, NotifyEvent *, _DWORD, signed int))&v42->gap90[0])(
               v8,
               LODWORD(lastTargetXValue),
               uTime,
               nEventa,
               0,
               1) != 1 )
        {
LABEL_88:
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v45 = v8->objectValue;
            if( v45 )
              fprintf(actionFile, aDCallStopobjec, v45->id, aCMsdevWorkA_43, 4713);
            else
              fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_43, 4713);
          }
          goto LABEL_317;
        }
        v44 = v8->currentOrderValue;
        v8->currentOrderValue = -1;
        v8->lastOrderValue = v44;
        v8->currentOrderPriorityValue = -1;
        result = 3;
      }
      else
      {
        v8->currentOrderValue = -1;
        result = 3;
      }
      return result;
    case 0x1FA:
      v46 = this->currentOrderValue;
      if( v46 == 700 && nEvent->p1 == 600 )
      {
        v47 = this->vfptr;
        if( ((int (__fastcall *)(UnitAIModule *, signed int, _DWORD))this->vfptr->processIdle)(this, 600, 0) != 5 )
          return 2;
        if( v8->currentOrderValue != 725 && RGE_Player::computerPlayer(v8->objectValue->owner) )
        {
          v48 = v8->desiredTargetDistanceValue - -2.0;
          if( (*(int (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD, signed int))&v47->gap90[0])(
                 v8,
                 LODWORD(v8->currentTargetXValue),
                 LODWORD(v8->currentTargetYValue),
                 LODWORD(v8->currentTargetZValue),
                 LODWORD(v48),
                 1) )
          {
            v51 = v8->currentOrderValue;
            v8->currentOrderValue = -1;
            v8->currentOrderPriorityValue = -1;
            v8->lastOrderValue = v51;
            return 2;
          }
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v49 = v8->objectValue;
            if( v49 )
              v50 = v49->id;
            else
              v50 = -1;
            fprintf(actionFile, aDCallStopobjec, v50, aCMsdevWorkA_43, 4763);
            v47->stopObject(v8, 0);
            return 2;
          }
        }
        else
        {
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v52 = v8->objectValue;
            if( v52 )
              v53 = v52->id;
            else
              v53 = -1;
            fprintf(actionFile, aDCallStopobjec, v53, aCMsdevWorkA_43, 4747);
          }
        }
        v47->stopObject(v8, 0);
        return 2;
      }
      if( v46 == -1 )
        goto LABEL_118;
      if( this->currentActionValue + 100 == v46 )
      {
        UnitAIModule::removeCurrentTarget(this);
        if( !actionFile )
          goto LABEL_285;
        v54 = v8->objectValue;
        if( v54 )
          v55 = v54->id;
        else
          v55 = -1;
        fprintf(actionFile, aDCallStopobjec, v55, aCMsdevWorkA_43, 4783);
        v8->vfptr->stopObject(v8, 1);
        return 2;
      }
      if( v46 != -1 )
        goto LABEL_124;
LABEL_118:
      if( this->currentActionValue == nEvent->p1 )
      {
        UnitAIModule::removeCurrentTarget(this);
        if( !actionFile )
          goto LABEL_285;
        v56 = v8->objectValue;
        if( v56 )
          v57 = v56->id;
        else
          v57 = -1;
        fprintf(actionFile, aDCallStopobjec, v57, aCMsdevWorkA_43, 4791);
        v8->vfptr->stopObject(v8, 1);
        result = 2;
      }
      else
      {
LABEL_124:
        if( v46 != 724 || nEvent->p1 != 610 )
        {
          if( v46 != 701 || nEvent->p1 != 610 )
          {
            if( v46 != 725 || nEvent->p1 != 600 )
              return 2;
            UnitAIModule::removeCurrentTarget(this);
            if( !actionFile )
              goto LABEL_285;
            v60 = v8->objectValue;
            if( v60 )
              v61 = v60->id;
            else
              v61 = -1;
            fprintf(actionFile, aDCallStopobjec, v61, aCMsdevWorkA_43, 4813);
            v8->vfptr->stopObject(v8, 1);
            result = 2;
          }
          else
          {
            UnitAIModule::setCurrentAction(this, -1);
            result = 2;
          }
        }
        else
        {
          UnitAIModule::removeCurrentTarget(this);
          if( actionFile )
          {
            v58 = v8->objectValue;
            if( v58 )
              v59 = v58->id;
            else
              v59 = -1;
            fprintf(actionFile, aDCallStopobjec, v59, aCMsdevWorkA_43, 4800);
          }
          v8->vfptr->stopObject(v8, 0);
          result = 2;
        }
      }
      return result;
    case 0x1F9:
      v62 = this->currentOrderValue;
      if( v62 != 700 || nEvent->p1 != 600 )
      {
        if( v62 == -1 )
          goto LABEL_322;
        if( this->currentActionValue + 100 == v62 )
        {
          UnitAIModule::removeCurrentTarget(this);
          if( actionFile )
          {
            v69 = v8->objectValue;
            if( v69 )
              fprintf(actionFile, aDCallStopobjec, v69->id, aCMsdevWorkA_43, 4868);
            else
              fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_43, 4868);
          }
          goto LABEL_317;
        }
        if( v62 == -1 )
        {
LABEL_322:
          if( this->currentActionValue == nEvent->p1 )
          {
            UnitAIModule::removeCurrentTarget(this);
            if( actionFile )
            {
              v70 = v8->objectValue;
              if( v70 )
                fprintf(actionFile, aDCallStopobjec, v70->id, aCMsdevWorkA_43, 4877);
              else
                fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_43, 4877);
            }
            goto LABEL_317;
          }
        }
        if( v62 == 724 && nEvent->p1 == 610 )
        {
          UnitAIModule::removeCurrentTarget(this);
          if( !actionFile )
            goto LABEL_224;
          v71 = v8->objectValue;
          if( v71 )
            v72 = v71->id;
          else
            v72 = -1;
          fprintf(actionFile, aDCallStopobjec, v72, aCMsdevWorkA_43, 4887);
          v73 = v8->vfptr;
          v8->vfptr->stopObject(v8, 0);
          goto LABEL_318;
        }
        if( v62 != 701 || nEvent->p1 != 610 )
        {
          if( v62 != 725 || nEvent->p1 != 600 )
            return 2;
          UnitAIModule::removeCurrentTarget(this);
          if( !actionFile )
            goto LABEL_285;
          v74 = v8->objectValue;
          if( v74 )
            v75 = v74->id;
          else
            v75 = -1;
          fprintf(actionFile, aDCallStopobjec, v75, aCMsdevWorkA_43, 4901);
          v8->vfptr->stopObject(v8, 1);
          result = 2;
        }
        else
        {
          UnitAIModule::setCurrentAction(this, -1);
          result = 2;
        }
      }
      else
      {
        v63 = this->vfptr;
        if( ((int (__fastcall *)(UnitAIModule *, signed int, _DWORD))this->vfptr->processIdle)(this, 600, 0) != 5 )
          return 2;
        if( v8->currentOrderValue != 725 && RGE_Player::computerPlayer(v8->objectValue->owner) )
        {
          v64 = v8->desiredTargetDistanceValue - -2.0;
          if( (*(int (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD, signed int))&v63->gap90[0])(
                 v8,
                 LODWORD(v8->currentTargetXValue),
                 LODWORD(v8->currentTargetYValue),
                 LODWORD(v8->currentTargetZValue),
                 LODWORD(v64),
                 1) )
          {
            goto LABEL_198;
          }
          UnitAIModule::removeCurrentTarget(v8);
          if( !actionFile )
            goto LABEL_204;
          v65 = v8->objectValue;
          if( v65 )
            v66 = v65->id;
          else
            v66 = -1;
          fprintf(actionFile, aDCallStopobjec, v66, aCMsdevWorkA_43, 4851);
          v63->stopObject(v8, 1);
          result = 2;
        }
        else
        {
          UnitAIModule::removeCurrentTarget(v8);
          if( !actionFile )
            goto LABEL_204;
          v67 = v8->objectValue;
          if( v67 )
            v68 = v67->id;
          else
            v68 = -1;
          fprintf(actionFile, aDCallStopobjec, v68, aCMsdevWorkA_43, 4841);
          v63->stopObject(v8, 1);
          result = 2;
        }
      }
      return result;
    case 0x1FB:
      v76 = this->currentOrderValue;
      if( v76 == 700 && nEvent->p1 == 600 )
      {
        v63 = this->vfptr;
        if( ((int (__fastcall *)(_DWORD, _DWORD, _DWORD))this->vfptr->processIdle)(this, 600, 0) != 5 )
          return 2;
        if( v8->currentOrderValue != 725 && RGE_Player::computerPlayer(v8->objectValue->owner) )
        {
          v77 = v8->desiredTargetDistanceValue - -2.0;
          if( (*(int (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD, signed int))&v63->gap90[0])(
                 v8,
                 LODWORD(v8->currentTargetXValue),
                 LODWORD(v8->currentTargetYValue),
                 LODWORD(v8->currentTargetZValue),
                 LODWORD(v77),
                 1) )
          {
LABEL_198:
            v80 = v8->currentOrderValue;
            v8->currentOrderValue = -1;
            v8->currentOrderPriorityValue = -1;
            v8->lastOrderValue = v80;
            return 2;
          }
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v78 = v8->objectValue;
            if( v78 )
              v79 = v78->id;
            else
              v79 = -1;
            fprintf(actionFile, aDCallStopobjec, v79, aCMsdevWorkA_43, 4939);
            v63->stopObject(v8, 1);
            return 2;
          }
        }
        else
        {
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v81 = v8->objectValue;
            if( v81 )
              v82 = v81->id;
            else
              v82 = -1;
            fprintf(actionFile, aDCallStopobjec, v82, aCMsdevWorkA_43, 4929);
          }
        }
LABEL_204:
        v63->stopObject(v8, 1);
        return 2;
      }
      if( v76 == -1 )
        goto LABEL_323;
      if( this->currentActionValue + 100 == v76 )
      {
        UnitAIModule::removeCurrentTarget(this);
        if( actionFile )
        {
          v83 = v8->objectValue;
          if( v83 )
            fprintf(actionFile, aDCallStopobjec, v83->id, aCMsdevWorkA_43, 4956);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_43, 4956);
        }
        goto LABEL_317;
      }
      if( v76 == -1 )
      {
LABEL_323:
        if( this->currentActionValue == nEvent->p1 )
        {
          UnitAIModule::removeCurrentTarget(this);
          if( actionFile )
          {
            v84 = v8->objectValue;
            if( v84 )
              fprintf(actionFile, aDCallStopobjec, v84->id, aCMsdevWorkA_43, 4965);
            else
              fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_43, 4965);
          }
          goto LABEL_317;
        }
      }
      if( v76 == 724 && nEvent->p1 == 610 )
      {
        UnitAIModule::removeCurrentTarget(this);
        if( actionFile )
        {
          v85 = v8->objectValue;
          if( v85 )
            v86 = v85->id;
          else
            v86 = -1;
          fprintf(actionFile, aDCallStopobjec, v86, aCMsdevWorkA_43, 4975);
        }
LABEL_224:
        v73 = v8->vfptr;
        v8->vfptr->stopObject(v8, 0);
        goto LABEL_318;
      }
      if( v76 != 701 || nEvent->p1 != 610 )
      {
        if( v76 != 725 || nEvent->p1 != 600 )
          return 2;
        UnitAIModule::removeCurrentTarget(this);
        if( !actionFile )
          goto LABEL_285;
        v87 = v8->objectValue;
        if( v87 )
          v88 = v87->id;
        else
          v88 = -1;
        fprintf(actionFile, aDCallStopobjec, v88, aCMsdevWorkA_43, 4989);
        v8->vfptr->stopObject(v8, 1);
        result = 2;
      }
      else
      {
        UnitAIModule::setCurrentAction(this, -1);
        result = 2;
      }
      return result;
    case 0x202:
      v89 = this->currentActionValue;
      if( v89 == 605 || v89 == 623 )
      {
        v91 = this->vfptr;
        if( this->vfptr->closestUndiscoveredTile(this, &tileX, (int *)&uTime, 1) != 1 )
        {
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v100 = v8->objectValue;
            if( v100 )
              v101 = v100->id;
            else
              v101 = -1;
            fprintf(actionFile, aDCallStopobjec, v101, aCMsdevWorkA_43, 5030);
          }
          goto LABEL_272;
        }
        UnitAIModule::addToWaypointQueue(v8, tileX, uTime);
        if( !v91->explore(v8, tileX, uTime, 1) )
        {
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v98 = v8->objectValue;
            if( v98 )
              v99 = v98->id;
            else
              v99 = -1;
            fprintf(actionFile, aDCallStopobjec, v99, aCMsdevWorkA_43, 5014);
          }
          v91->stopObject(v8, 1);
          ((void (__thiscall *)(UnitAIModule *, NotifyEvent *))v91->notifyCommander)(v8, nEvent);
        }
        v8->currentActionValue = v89;
LABEL_266:
        result = 3;
      }
      else
      {
        if( v89 != 609 )
          return 2;
        v90 = this->currentTargetTypeValue;
        if( v90 == -1 )
          v90 = this->lastTargetTypeValue;
        v91 = this->vfptr;
        v92 = this->vfptr->convertToLOSResourceType(this, v90);
        if( v92 == -1 )
          v93 = ((int (__thiscall *)(UnitAIModule *, int, signed int, signed int, signed int))v91->closestObject)(
                  v8,
                  v90,
                  -1,
                  -1,
                  -1);
        else
          v93 = ((int (__thiscall *)(UnitAIModule *, int))v91->closestResourceObject)(v8, v92);
        if( v93 != -1 )
        {
          if( v91->gatherObject(v8, v93, 1) == 1 )
            return 3;
          UnitAIModule::removeCurrentTarget(v8);
          if( actionFile )
          {
            v94 = v8->objectValue;
            if( v94 )
              v95 = v94->id;
            else
              v95 = -1;
            fprintf(actionFile, aDCallStopobjec, v95, aCMsdevWorkA_43, 5070);
            v91->stopObject(v8, 1);
            ((void (__thiscall *)(UnitAIModule *, NotifyEvent *))v91->notifyCommander)(v8, nEvent);
            return 2;
          }
LABEL_272:
          v91->stopObject(v8, 1);
          ((void (__thiscall *)(UnitAIModule *, NotifyEvent *))v91->notifyCommander)(v8, nEvent);
          return 2;
        }
        UnitAIModule::removeCurrentTarget(v8);
        if( actionFile )
        {
          v96 = v8->objectValue;
          if( v96 )
            v97 = v96->id;
          else
            v97 = -1;
          fprintf(actionFile, aDCallStopobjec, v97, aCMsdevWorkA_43, 5082);
        }
        v91->stopObject(v8, 1);
        ((void (__thiscall *)(_DWORD, _DWORD))v91->notifyCommander)(v8, nEvent);
        result = 2;
      }
      return result;
    case 0x20B:
      ((void (*)(void))this->objectValue->vfptr->stopAction)();
      UnitAIModule::removeCurrentTarget(v8);
      if( actionFile )
      {
        v102 = v8->objectValue;
        if( v102 )
          v103 = v102->id;
        else
          v103 = -1;
        fprintf(actionFile, aDCallStopobjec, v103, aCMsdevWorkA_43, 5095);
      }
      v8->vfptr->stopObject(v8, 1);
      UnitAIModule::purgeNotifyQueue(v8, uTime);
      v104 = v8->objectValue;
      v8->orderQueueSizeValue = 0;
      v105 = UnitAIModule::lookupObject(v8, v104->groupCommanderValue);
      if( !v105 )
        return 2;
      RGE_Static_Object::commanderRemoveFromGroup(v105, v8->objectValue->id);
      return 2;
    case 0x1FE:
      ((void (*)(void))this->objectValue->vfptr->stopAction)();
      UnitAIModule::removeCurrentTarget(v8);
      if( actionFile )
      {
        v106 = v8->objectValue;
        if( v106 )
          v107 = v106->id;
        else
          v107 = -1;
        fprintf(actionFile, aDCallStopobjec, v107, aCMsdevWorkA_43, 5113);
      }
LABEL_285:
      v8->vfptr->stopObject(v8, 1);
      return 2;
    case 0x258:
      v108 = this->attackingUnitsValue.numberValue;
      v109 = nEvent->caller;
      v110 = 0;
      if( v108 <= 0 )
        goto LABEL_290;
      do
      {
        if( v110 >= v8->attackingUnitsValue.maximumSizeValue )
          break;
        if( v8->attackingUnitsValue.value[v110] == v109 )
          goto LABEL_297;
        ++v110;
      }
      while( v110 < v108 );
LABEL_290:
      if( v108 > v8->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v111 = v108 + 1;
        v112 = (int *)operator new(4 * (v108 + 1));
        if( v112 )
        {
          for( k = 0; k < v8->attackingUnitsValue.maximumSizeValue; v112[k - 1] = v8->attackingUnitsValue.value[k - 1] )
          {
            if( k >= v111 )
              break;
            ++k;
          }
          operator delete(v8->attackingUnitsValue.value);
          v8->attackingUnitsValue.value = v112;
          v8->attackingUnitsValue.maximumSizeValue = v111;
        }
      }
      v8->attackingUnitsValue.value[v8->attackingUnitsValue.numberValue++] = v109;
LABEL_297:
      ((void (__stdcall *)(signed int))v8->objectValue->vfptr->setUnderAttack)(1);
      return 2;
    case 0x2BB:
      v114 = this->attackingUnitsValue.numberValue;
      v115 = 0;
      if( v114 <= 0 )
        return 2;
      while( 1 )
      {
        if( v115 >= v8->attackingUnitsValue.maximumSizeValue )
          return 2;
        if( v8->attackingUnitsValue.value[v115] == nEvent->caller )
          break;
        if( ++v115 >= v114 )
          return 2;
      }
      v116 = v8->attackingUnitsValue.maximumSizeValue;
      v117 = 0;
      if( v116 > 0 )
      {
        v118 = v8->attackingUnitsValue.value;
        do
        {
          if( *v118 == nEvent->caller )
            break;
          ++v117;
          ++v118;
        }
        while( v117 < v116 );
      }
      if( v117 >= v116 )
        return 2;
      if( v117 < v116 - 1 )
      {
        do
        {
          ++v117;
          v8->attackingUnitsValue.value[v117 - 1] = v8->attackingUnitsValue.value[v117];
        }
        while( v117 < v8->attackingUnitsValue.maximumSizeValue - 1 );
      }
      v119 = v8->attackingUnitsValue.numberValue - 1;
      v8->attackingUnitsValue.numberValue = v119;
      if( v119 >= 0 )
        return 2;
      v8->attackingUnitsValue.numberValue = 0;
      return 2;
    default:
      UnitAIModule::removeCurrentTarget(this);
      if( actionFile )
      {
        v120 = v8->objectValue;
        if( v120 )
          v121 = v120->id;
        else
          v121 = -1;
        fprintf(actionFile, aDCallStopobjec, v121, aCMsdevWorkA_43, 5177);
      }
LABEL_317:
      v73 = v8->vfptr;
      v8->vfptr->stopObject(v8, 1);
LABEL_318:
      ((void (__thiscall *)(UnitAIModule *, NotifyEvent *))v73->notifyCommander)(v8, v7);
      return 2;
    case 0x1F6:
    case 0x1F7:
    case 0x1F8:
    case 0x1FD:
    case 0x1FF:
    case 0x200:
    case 0x203:
    case 0x259:
    case 0x25A:
    case 0x25B:
    case 0x25C:
    case 0x25D:
    case 0x25E:
    case 0x25F:
    case 0x260:
    case 0x261:
    case 0x262:
    case 0x265:
    case 0x266:
    case 0x267:
    case 0x268:
    case 0x269:
      return 2;
  }
}

//----- (00419510) --------------------------------------------------------
void __thiscall UnitAIModule::processGroupNotify(UnitAIModule *this, NotifyEvent *nEvent)
{
  UnitAIModule *v2; // ebx@1
  AIPlayStatus *v3; // eax@1
  AIPlay *v4; // eax@2
  AIPlayPhase *v5; // ecx@3
  int v6; // ebp@5
  AIPlayPhase *v7; // eax@7
  AIPlayPhase *v8; // esi@7
  char v9; // al@8
  int v10; // edi@11
  AIPlayPhase *phase; // [sp+4h] [bp-4h]@3

  v2 = this;
  v3 = this->playStatus;
  if( v3 )
  {
    v4 = AIPlayBook::play(this->objectValue->owner->world->playbook, v3->playNumberValue);
    if( v4 )
    {
      v5 = AIPlay::phase(v4, v2->playStatus->currentPhaseValue);
      phase = v5;
      if( v5 )
      {
        if( nEvent->mType == 500 )
        {
          v2->playStatus->savedAttackerValue = nEvent->caller;
          v6 = 0;
          while( 1 )
          {
            v7 = AIPlayPhase::trigger(v5, v6);
            v8 = v7;
            if( v7 )
            {
              v9 = v7->commands[0].groupValue;
              if( v8->commands[0].groupValue )
              {
                if( v9 == 5
                  || v9 == 4
                  && (v10 = v8->commands[0].value1Value,
                      v10 == (unsigned __int8)AIPlayStatus::group(v2->playStatus, nEvent->recipient)) )
                {
                  UnitAIModule::selectNewPlayPhase(v2, BYTE1(v8->commands[0].value3Value), 0);
                }
              }
            }
            if( ++v6 >= 3 )
              break;
            v5 = phase;
          }
        }
      }
    }
  }
}

//----- (004195F0) --------------------------------------------------------
int __thiscall UnitAIModule::processIdle(UnitAIModule *this, int doSearch)
{
  UnitAIModule *v2; // esi@1
  int result; // eax@3
  UnitAIModuleVtbl *v4; // edi@4
  int v5; // eax@4
  bool v6; // zf@5

  v2 = this;
  if( doSearch != 1 || ((int (*)(void))this->vfptr->processRetryableOrder)() != 8 )
  {
    v4 = v2->vfptr;
    v5 = v2->vfptr->bestUnitToAttack(v2, 1, 0, 0);
    if( v5 == -1 || (v6 = v4->attackObject(v2, v5, 1) == 1, result = 6, !v6) )
      result = 5;
  }
  else
  {
    result = 6;
  }
  return result;
}

//----- (00419650) --------------------------------------------------------
int __usercall UnitAIModule::processMisc@<eax>(UnitAIModule *this@<ecx>, double a2@<st0>)
{
  UnitAIModule *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // eax@8
  float v8; // ecx@8
  RGE_Static_Object *v9; // eax@9
  RGE_Static_Object *v10; // eax@12
  signed int v11; // eax@13
  int result; // eax@15
  double v13; // st7@17
  float v14; // edx@27
  float v15; // edx@27
  RGE_Static_Object *v16; // ecx@27
  long double v17; // st7@27
  float v18; // ecx@29
  int v19; // eax@30
  UnitAIModuleVtbl *v20; // edx@30
  float v21; // edi@33
  RGE_Static_Object *v22; // eax@34
  RGE_Static_Object *v23; // eax@36
  signed int v24; // eax@37
  RGE_Static_Object *v25; // eax@46
  signed int v26; // eax@47
  int v27; // eax@51
  float v28; // eax@55
  RGE_Static_Object *v29; // ecx@55
  long double v30; // st7@55
  int v31; // eax@58
  int v32; // edi@61
  signed __int64 v33; // rax@61
  RGE_Static_ObjectVtbl **v34; // ecx@61
  RGE_Static_ObjectVtbl *v35; // ebp@61
  char *v36; // ecx@62
  float v37; // edx@62
  UnitAIModuleVtbl *v38; // eax@62
  float v39; // ecx@62
  float v40; // edx@62
  UnitAIModule *v41; // eax@65
  int v42; // eax@65
  RGE_Static_Object *v43; // eax@72
  UnitAIModuleVtbl *v44; // ebp@74
  int v45; // eax@74
  int v46; // ebx@74
  RGE_Static_Object *v47; // eax@74
  RGE_Static_Object *v48; // edi@74
  RGE_Master_Static_Object *v49; // ecx@77
  __int16 v50; // ax@77
  __int16 v51; // ax@80
  float v52; // eax@82
  float v53; // edx@82
  RGE_Static_Object *v54; // ecx@82
  float v55; // ecx@82
  float v56; // edx@84
  float v57; // eax@84
  RGE_Static_Object *v58; // ecx@84
  float v59; // ecx@84
  int v60; // [sp-8h] [bp-38h]@61
  int v61; // [sp-4h] [bp-34h]@61
  signed int v62; // [sp+0h] [bp-30h]@61
  float v63; // [sp+4h] [bp-2Ch]@61
  signed int v64; // [sp+8h] [bp-28h]@61
  float v65; // [sp+Ch] [bp-24h]@61
  signed int v66; // [sp+10h] [bp-20h]@15
  char *v67; // [sp+14h] [bp-1Ch]@15
  RGE_Static_Object *v68; // [sp+18h] [bp-18h]@15
  float yDiff; // [sp+2Ch] [bp-4h]@20

  v2 = this;
  v3 = this->currentOrderValue;
  if( v3 == -1 )
  {
    v4 = this->currentActionValue;
    if( v4 == -1 )
      v3 = -1;
    else
      v3 = v4 + 100;
  }
  v5 = v3 - 700;
  if( !v5 )
  {
    if( taskedThisUpdate != 1 )
    {
      if( RGE_Player::computerPlayer(this->objectValue->owner) )
      {
        if( (unsigned __int8)((int (*)(void))v2->objectValue->vfptr->can_attack)() )
        {
          *(float *)&v43 = COERCE_FLOAT(UnitAIModule::lookupObject(v2, v2->currentTargetValue));
          yDiff = *(float *)&v43;
          if( *(float *)&v43 == 0.0 || v43->master_obj->id != 276 )
          {
            v44 = v2->vfptr;
            v45 = v2->vfptr->bestUnitToAttack(v2, 0, 0, 0);
            v46 = v45;
            v47 = UnitAIModule::lookupObject(v2, v45);
            v48 = v47;
            if( v46 != -1 && v47 && v46 != v2->currentTargetValue )
            {
              v49 = v47->master_obj;
              v50 = v49->object_group;
              if( v50 == 3 || v50 == 27 )
              {
                if( v49->id == 276 )
                {
                  ((void (__stdcall *)(signed int, _DWORD, int))v2->objectValue->vfptr->weaponRange)(
                    1,
                    0,
                    v2->currentOrderPriorityValue);
                  v56 = v48->world_y;
                  v57 = v48->world_x;
                  v68 = v58;
                  v59 = v48->world_z;
                  *(float *)&v68 = a2;
                  (*(void (__thiscall **)(UnitAIModule *, int, signed int, int, _DWORD, float, float, float, RGE_Static_Object *))&v44->gap4[12])(
                    v2,
                    v2->objectValue->id,
                    700,
                    v46,
                    v48->owner->id,
                    COERCE_FLOAT(LODWORD(v57)),
                    COERCE_FLOAT(LODWORD(v56)),
                    COERCE_FLOAT(LODWORD(v59)),
                    v68);
                }
              }
              else if( yDiff == 0.0 || (v51 = *(_WORD *)(*(_DWORD *)(LODWORD(yDiff) + 8) + 20), v51 == 3) || v51 == 27 )
              {
                ((void (__stdcall *)(signed int, _DWORD, int))v2->objectValue->vfptr->weaponRange)(
                  1,
                  0,
                  v2->currentOrderPriorityValue);
                v52 = v48->world_z;
                v53 = v48->world_x;
                v68 = v54;
                v55 = v48->world_y;
                *(float *)&v68 = a2;
                (*(void (__thiscall **)(UnitAIModule *, int, signed int, int, _DWORD, float, float, float, RGE_Static_Object *))&v44->gap4[12])(
                  v2,
                  v2->objectValue->id,
                  700,
                  v46,
                  v48->owner->id,
                  COERCE_FLOAT(LODWORD(v53)),
                  COERCE_FLOAT(LODWORD(v55)),
                  COERCE_FLOAT(LODWORD(v52)),
                  v68);
                return 9;
              }
            }
          }
        }
      }
    }
    return 9;
  }
  v6 = v5 - 1;
  if( v6 )
  {
    if( v6 == 11 )
    {
      v7 = this->currentTargetValue;
      v8 = 0.0;
      if( v7 != -1 )
      {
        *(float *)&v9 = COERCE_FLOAT(UnitAIModule::lookupObject(v2, v2->currentTargetValue));
        v8 = *(float *)&v9;
        if( *(float *)&v9 == 0.0 || v9->object_state > 2u )
        {
          v2->defendTargetValue = -1;
          UnitAIModule::removeCurrentTarget(v2);
          if( actionFile )
          {
            v10 = v2->objectValue;
            if( v10 )
              v11 = v10->id;
            else
              v11 = -1;
            v68 = (RGE_Static_Object *)5506;
            v67 = aCMsdevWorkA_43;
            v66 = v11;
            fprintf(actionFile, aDCallStopobjec, v11, aCMsdevWorkA_43, 5506);
            v2->vfptr->stopObject(v2, 1);
            v2->currentOrderValue = -1;
            return 9;
          }
LABEL_50:
          v2->vfptr->stopObject(v2, 1);
          v2->currentOrderValue = -1;
          return 9;
        }
      }
      if( v8 == 0.0 )
        v13 = -10.0;
      else
        v13 = *(float *)(LODWORD(v8) + 56) - v2->currentTargetXValue;
      if( v8 == 0.0 )
        yDiff = -10.0;
      else
        yDiff = *(float *)(LODWORD(v8) + 60) - v2->currentTargetYValue;
      if( v13 < -1.0 || v13 > 1.0 || yDiff < -1.0 || yDiff > 1.0 )
      {
        if( v2->currentTargetValue == -1 )
        {
          v17 = RGE_Static_Object::distance_to_position(
                  v2->objectValue,
                  v2->currentTargetXValue,
                  v2->currentTargetYValue,
                  v2->objectValue->world_z);
        }
        else
        {
          v14 = *(float *)(LODWORD(v8) + 56);
          *(float *)&v68 = v8;
          v2->currentTargetXValue = v14;
          v2->currentTargetYValue = *(float *)(LODWORD(v8) + 60);
          v15 = *(float *)(LODWORD(v8) + 64);
          v16 = v2->objectValue;
          v2->currentTargetZValue = v15;
          v17 = RGE_Static_Object::distance_to_object(v16, v68);
        }
        v18 = v2->desiredTargetDistanceValue;
        yDiff = v2->desiredTargetDistanceValue;
        if( v17 > yDiff )
        {
          v19 = v2->currentTargetValue;
          v20 = v2->vfptr;
          v68 = (RGE_Static_Object *)1;
          if( v19 == -1 )
          {
            (*(void (__thiscall **)(UnitAIModule *, _DWORD, _DWORD, _DWORD, _DWORD, RGE_Static_Object *))&v20->gap90[0])(
              v2,
              LODWORD(v2->currentTargetXValue),
              LODWORD(v2->currentTargetYValue),
              LODWORD(v2->currentTargetZValue),
              LODWORD(yDiff),
              v68);
            result = 10;
          }
          else
          {
            (*(void (__thiscall **)(UnitAIModule *, int, float, RGE_Static_Object *))&v20->gap90[4])(
              v2,
              v19,
              COERCE_FLOAT(LODWORD(v18)),
              v68);
            result = 10;
          }
          return result;
        }
      }
    }
    return 9;
  }
  v21 = 0.0;
  if( this->defendTargetValue == -1 )
  {
LABEL_51:
    v27 = v2->currentActionValue;
    if( v27 != 600
      && (v27 != 610 || ((int (*)(void))v2->objectValue->vfptr->currentTargetID)() != v2->defendTargetValue) )
    {
      if( v2->defendTargetValue == -1 )
      {
        v30 = RGE_Static_Object::distance_to_position(
                v2->objectValue,
                v2->currentTargetXValue,
                v2->currentTargetYValue,
                v2->objectValue->world_z);
      }
      else
      {
        v28 = *(float *)(LODWORD(v21) + 56);
        *(float *)&v68 = v21;
        v2->currentTargetXValue = v28;
        v2->currentTargetYValue = *(float *)(LODWORD(v21) + 60);
        v29 = v2->objectValue;
        v2->currentTargetZValue = *(float *)(LODWORD(v21) + 64);
        v30 = RGE_Static_Object::distance_to_object(v29, v68);
      }
      yDiff = v2->desiredTargetDistanceValue;
      if( v30 <= yDiff - -1.0 )
      {
        if( v21 == 0.0 || !RGE_Static_Object::unitAI((RGE_Static_Object *)LODWORD(v21)) )
          return 9;
        v41 = RGE_Static_Object::unitAI((RGE_Static_Object *)LODWORD(v21));
        v42 = v41->vfptr->closestAttacker(v41, 0);
        if( v42 != -1 )
        {
          v2->vfptr->attackObject(v2, v42, 1);
          return 10;
        }
        if( v2->vfptr->processIdle(v2, 0) != 6 )
          return 9;
      }
      else
      {
        v31 = v2->defendTargetValue;
        if( v31 == -1 )
        {
          v32 = (signed __int64)v2->currentTargetXValue;
          v33 = (signed __int64)v2->currentTargetYValue;
          *(float *)&v68 = -6.8056469e38/*NaN*/;
          v67 = (char *)-1;
          v34 = &v2->objectValue->vfptr;
          v66 = 0;
          v65 = 0.0;
          v64 = -1;
          v35 = *v34;
          v63 = yDiff;
          v60 = v32;
          v61 = v33;
          v62 = -1;
          if( ((int (__stdcall *)(int, _DWORD, signed int, _DWORD, signed int, _DWORD, _DWORD, signed int, signed int))v35->canPath)(
                 v32,
                 v33,
                 -1,
                 LODWORD(yDiff),
                 -1,
                 0,
                 0,
                 -1,
                 -1) == 1 )
          {
            v36 = (char *)LODWORD(v2->desiredTargetDistanceValue);
            v37 = v2->currentTargetZValue;
            v38 = v2->vfptr;
            v68 = (RGE_Static_Object *)1;
            v67 = v36;
            v39 = v2->currentTargetYValue;
            v66 = LODWORD(v37);
            v40 = v2->currentTargetXValue;
            v65 = v39;
            v64 = LODWORD(v40);
            (*(void (__thiscall **)(UnitAIModule *, float, float, signed int, char *, signed int))&v38->gap90[0])(
              v2,
              COERCE_FLOAT(LODWORD(v40)),
              COERCE_FLOAT(LODWORD(v39)),
              v66,
              v67,
              1);
            return 10;
          }
        }
        else if( (*((int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int))&v2->objectValue->vfptr->pause
                   + 1))(
                    v31,
                    LODWORD(yDiff),
                    0,
                    0,
                    -1,
                    -1) == 1 )
        {
          (*(void (__thiscall **)(UnitAIModule *, int, _DWORD, signed int))&v2->vfptr->gap90[4])(
            v2,
            v2->defendTargetValue,
            LODWORD(v2->desiredTargetDistanceValue),
            1);
          return 10;
        }
      }
      return 10;
    }
    return 9;
  }
  *(float *)&v22 = COERCE_FLOAT(UnitAIModule::lookupObject(this, this->defendTargetValue));
  v21 = *(float *)&v22;
  if( *(float *)&v22 != 0.0 )
  {
    if( LODWORD(v2->currentTargetXValue) == -1082130432 )
    {
      v2->currentTargetXValue = v22->world_x;
      v2->currentTargetYValue = v22->world_y;
    }
    if( v22->object_state > 2u && v22->owner->id )
    {
      v2->defendTargetValue = -1;
      UnitAIModule::removeCurrentTarget(v2);
      if( actionFile )
      {
        v25 = v2->objectValue;
        if( v25 )
          v26 = v25->id;
        else
          v26 = -1;
        v68 = (RGE_Static_Object *)5593;
        v67 = aCMsdevWorkA_43;
        v66 = v26;
        fprintf(actionFile, aDCallStopobjec, v26, aCMsdevWorkA_43, 5593);
      }
      goto LABEL_50;
    }
    goto LABEL_51;
  }
  v2->defendTargetValue = -1;
  UnitAIModule::removeCurrentTarget(v2);
  if( actionFile )
  {
    v23 = v2->objectValue;
    if( v23 )
      v24 = v23->id;
    else
      v24 = -1;
    v68 = (RGE_Static_Object *)5568;
    v67 = aCMsdevWorkA_43;
    v66 = v24;
    fprintf(actionFile, aDCallStopobjec, v24, aCMsdevWorkA_43, 5568);
  }
  v2->vfptr->stopObject(v2, 1);
  v2->currentOrderValue = -1;
  return 9;
}
// 592A48: using guessed type int taskedThisUpdate;

//----- (00419BC0) --------------------------------------------------------
int __thiscall UnitAIModule::processRetryableOrder(UnitAIModule *this)
{
  UnitAIModule *v1; // esi@1
  UnitAIModuleVtbl *v2; // edi@1
  int v3; // eax@2

  v1 = this;
  v2 = this->vfptr;
  if( ((int (__stdcall *)(int))this->vfptr->retryableOrder)(this->lastOrderValue) == 1 )
  {
    v3 = v2->closestObject(v1, v1->lastTargetTypeValue, -1, -1, -1, 0);
    if( v3 != -1 )
    {
      if( v1->lastOrderValue == 709 )
        return 8 - (v2->gatherObject(v1, v3, 0) != 1);
      if( v1->lastOrderValue == 713 )
        return 8 - (v2->huntObject(v1, v3, 0) != 1);
    }
  }
  return 7;
}

//----- (00419C30) --------------------------------------------------------
void *__thiscall UnitAIModule::addToOrderQueue(UnitAIModule *this, OrderEvent *oEvent, int inFront)
{
  return UnitAIModule::addToOrderQueue(
           this,
           oEvent->issuer,
           oEvent->orderType,
           oEvent->target,
           oEvent->targetOwner,
           oEvent->targetX,
           oEvent->targetY,
           oEvent->targetZ,
           oEvent->range,
           inFront,
           oEvent->priority);
}

//----- (00419C70) --------------------------------------------------------
void *__thiscall UnitAIModule::addToOrderQueue(UnitAIModule *this, int issuer, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int inFront, int priority)
{
  UnitAIModule *v11; // esi@1
  int v12; // eax@1
  void *result; // eax@2
  int v14; // edi@2
  int v15; // edx@3
  int v16; // eax@4
  int v17; // ecx@4
  int v18; // ebx@5
  int v19; // ecx@8
  int v20; // eax@10
  int v21; // edx@11
  int v22; // eax@12
  int v23; // ecx@13

  v11 = this;
  v12 = this->orderQueueMaxSizeValue;
  if( v12 == this->orderQueueSizeValue )
  {
    result = operator new(72 * v12);
    v14 = (int)result;
    if( !result )
      return result;
    v15 = 0;
    if( v11->orderQueueSizeValue > 0 )
    {
      v16 = 0;
      v17 = v14 + 8;
      do
      {
        ++v15;
        v17 += 36;
        v18 = v11->orderQueueValue[v16].issuer;
        ++v16;
        *(_DWORD *)(v17 - 44) = v18;
        *(_DWORD *)(v17 - 40) = *((_DWORD *)&v11->orderQueueValue[v16] - 8);
        *(_DWORD *)(v17 - 36) = *((_DWORD *)&v11->orderQueueValue[v16] - 7);
        *(_DWORD *)(v17 - 32) = *((_DWORD *)&v11->orderQueueValue[v16] - 6);
        *(_DWORD *)(v17 - 28) = *((_DWORD *)&v11->orderQueueValue[v16] - 5);
        *(_DWORD *)(v17 - 24) = *((_DWORD *)&v11->orderQueueValue[v16] - 4);
        *(_DWORD *)(v17 - 20) = *((_DWORD *)&v11->orderQueueValue[v16] - 3);
        *(_DWORD *)(v17 - 16) = *((_DWORD *)&v11->orderQueueValue[v16] - 2);
        *(_DWORD *)(v17 - 12) = *((_DWORD *)&v11->orderQueueValue[v16] - 1);
      }
      while( v15 < v11->orderQueueSizeValue );
    }
    if( v11->orderQueueValue )
      operator delete(v11->orderQueueValue);
    v19 = v11->orderQueueMaxSizeValue;
    v11->orderQueueValue = (OrderEvent *)v14;
    v11->orderQueueMaxSizeValue = 2 * v19;
  }
  if( inFront && (v20 = v11->orderQueueSizeValue) != 0 )
  {
    v21 = 0;
    if( v20 > 0 )
    {
      v22 = 0;
      do
      {
        v11->orderQueueValue[v22 + 1].issuer = v11->orderQueueValue[v22].issuer;
        v11->orderQueueValue[v22 + 1].orderType = v11->orderQueueValue[v22].orderType;
        v11->orderQueueValue[v22 + 1].priority = v11->orderQueueValue[v22].priority;
        v11->orderQueueValue[v22 + 1].target = v11->orderQueueValue[v22].target;
        v11->orderQueueValue[v22 + 1].targetOwner = v11->orderQueueValue[v22].targetOwner;
        v11->orderQueueValue[v22 + 1].targetX = v11->orderQueueValue[v22].targetX;
        v11->orderQueueValue[v22 + 1].targetY = v11->orderQueueValue[v22].targetY;
        v11->orderQueueValue[v22 + 1].targetZ = v11->orderQueueValue[v22].targetZ;
        v23 = (int)&v11->orderQueueValue[v22].issuer;
        ++v21;
        ++v22;
        *(_DWORD *)(v23 + 68) = *(_DWORD *)(v23 + 32);
      }
      while( v21 < v11->orderQueueSizeValue );
    }
    v11->orderQueueValue->issuer = issuer;
    v11->orderQueueValue->orderType = orderType;
    v11->orderQueueValue->priority = priority;
    v11->orderQueueValue->target = target;
    v11->orderQueueValue->targetOwner = targetOwner;
    v11->orderQueueValue->targetX = targetX;
    v11->orderQueueValue->targetY = targetY;
    v11->orderQueueValue->targetZ = targetZ;
    v11->orderQueueValue->range = range;
    ++v11->orderQueueSizeValue;
    result = (void *)1;
  }
  else
  {
    v11->orderQueueValue[v11->orderQueueSizeValue].issuer = issuer;
    v11->orderQueueValue[v11->orderQueueSizeValue].orderType = orderType;
    v11->orderQueueValue[v11->orderQueueSizeValue].priority = priority;
    v11->orderQueueValue[v11->orderQueueSizeValue].target = target;
    v11->orderQueueValue[v11->orderQueueSizeValue].targetOwner = targetOwner;
    v11->orderQueueValue[v11->orderQueueSizeValue].targetX = targetX;
    v11->orderQueueValue[v11->orderQueueSizeValue].targetY = targetY;
    v11->orderQueueValue[v11->orderQueueSizeValue].targetZ = targetZ;
    v11->orderQueueValue[v11->orderQueueSizeValue++].range = range;
    result = (void *)1;
  }
  return result;
}

//----- (00419ED0) --------------------------------------------------------
void *__thiscall UnitAIModule::addToNotifyQueue(UnitAIModule *this, NotifyEvent *nEvent)
{
  return UnitAIModule::addToNotifyQueue(
           this,
           nEvent->caller,
           nEvent->recipient,
           nEvent->mType,
           nEvent->p1,
           nEvent->p2,
           nEvent->p3);
}

//----- (00419F00) --------------------------------------------------------
void *__thiscall UnitAIModule::addToNotifyQueue(UnitAIModule *this, int callerID, int recipientID, int mType, int p1, int p2, int p3)
{
  UnitAIModule *v7; // esi@1
  int v8; // eax@1
  void *result; // eax@2
  int v10; // edi@2
  int v11; // edx@3
  int v12; // eax@4
  int v13; // ecx@4
  int v14; // ebx@5
  int v15; // ecx@8

  v7 = this;
  v8 = this->notifyQueueMaxSizeValue;
  if( v8 == this->notifyQueueSizeValue )
  {
    result = operator new(48 * v8);
    v10 = (int)result;
    if( !result )
      return result;
    v11 = 0;
    if( v7->notifyQueueSizeValue > 0 )
    {
      v12 = 0;
      v13 = v10 + 8;
      do
      {
        ++v11;
        v13 += 24;
        v14 = v7->notifyQueueValue[v12].caller;
        ++v12;
        *(_DWORD *)(v13 - 32) = v14;
        *(_DWORD *)(v13 - 28) = *((_DWORD *)&v7->notifyQueueValue[v12] - 5);
        *(_DWORD *)(v13 - 24) = *((_DWORD *)&v7->notifyQueueValue[v12] - 4);
        *(_DWORD *)(v13 - 20) = *((_DWORD *)&v7->notifyQueueValue[v12] - 3);
        *(_DWORD *)(v13 - 16) = *((_DWORD *)&v7->notifyQueueValue[v12] - 2);
        *(_DWORD *)(v13 - 12) = *((_DWORD *)&v7->notifyQueueValue[v12] - 1);
      }
      while( v11 < v7->notifyQueueSizeValue );
    }
    if( v7->notifyQueueValue )
      operator delete(v7->notifyQueueValue);
    v15 = v7->notifyQueueMaxSizeValue;
    v7->notifyQueueValue = (NotifyEvent *)v10;
    v7->notifyQueueMaxSizeValue = 2 * v15;
  }
  v7->notifyQueueValue[v7->notifyQueueSizeValue].caller = callerID;
  v7->notifyQueueValue[v7->notifyQueueSizeValue].recipient = recipientID;
  v7->notifyQueueValue[v7->notifyQueueSizeValue].mType = mType;
  v7->notifyQueueValue[v7->notifyQueueSizeValue].p1 = p1;
  v7->notifyQueueValue[v7->notifyQueueSizeValue].p2 = p2;
  v7->notifyQueueValue[v7->notifyQueueSizeValue++].p3 = p3;
  return (void *)1;
}

//----- (0041A020) --------------------------------------------------------
void __thiscall UnitAIModule::purgeNotifyQueue(UnitAIModule *this, unsigned int uTime)
{
  UnitAIModule *v2; // esi@1
  int v3; // edi@1
  int v4; // ebx@1
  char *v5; // ecx@2
  int v6; // eax@5
  RGE_Static_Object *v7; // eax@12
  signed int v8; // eax@13

  v2 = this;
  v3 = 0;
  v4 = this->notifyQueueSizeValue;
  if( v4 > 0 )
  {
    v5 = (char *)&this->notifyQueueValue->p1;
    while( 1 )
    {
      if( *((_DWORD *)v5 - 1) == 506 )
      {
        if( *(_DWORD *)v5 != 610 || (v6 = v2->currentActionValue, v6 == 610) || v6 == 616 )
        {
          if( v2->currentOrderValue == -1 && v2->currentActionValue == *(_DWORD *)v5 )
            break;
        }
      }
      ++v3;
      v5 += 24;
      if( v3 >= v4 )
        goto LABEL_17;
    }
    UnitAIModule::removeCurrentTarget(v2);
    if( actionFile )
    {
      v7 = v2->objectValue;
      if( v7 )
        v8 = v7->id;
      else
        v8 = -1;
      fprintf(actionFile, aDCallStopobjec, v8, aCMsdevWorkA_43, 5902);
    }
    v2->vfptr->stopObject(v2, 1);
  }
LABEL_17:
  v2->notifyQueueSizeValue = 0;
  v2->lastUpdateTimeValue = uTime;
}

//----- (0041A0D0) --------------------------------------------------------
RGE_Static_Object *__thiscall UnitAIModule::lookupObject(UnitAIModule *this, int id)
{
  RGE_Static_Object *v2; // eax@1
  RGE_Player *v3; // eax@2
  RGE_Game_World *v4; // eax@3
  RGE_Static_Object *result; // eax@4

  v2 = this->objectValue;
  if( v2 && (v3 = v2->owner) != 0 && (v4 = v3->world) != 0 )
    result = RGE_Game_World::object(v4, id);
  else
    result = 0;
  return result;
}

//----- (0041A100) --------------------------------------------------------
void UnitAIModule::logDebug(UnitAIModule *this, char *textIn, ...)
{
  char textOut[1024]; // [sp+4h] [bp-400h]@2
  va_list va; // [sp+410h] [bp+Ch]@1

  va_start(va, textIn);
  if( this->objectValue )
  {
    vsprintf(textOut, textIn, va);
    ((void (__cdecl *)(_DWORD, _DWORD))this->objectValue->vfptr->logDebug)(this->objectValue, textOut);
  }
}
