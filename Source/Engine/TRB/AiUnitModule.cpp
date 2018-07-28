
//----- (00503BB0) --------------------------------------------------------
void __thiscall TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(TribeHuntedAnimalUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeHuntedAnimalUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeHuntedAnimalUnitAIModule::`vftable';
  v3->numberImportantObjects = 16;
  v4 = (int *)operator new(0x40u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 0;
    v3->importantObjects[1] = 4;
    v3->importantObjects[2] = 26;
    v3->importantObjects[3] = 24;
    v3->importantObjects[4] = 6;
    v3->importantObjects[5] = 25;
    v3->importantObjects[6] = 17;
    v3->importantObjects[7] = 10;
    v3->importantObjects[8] = 12;
    v3->importantObjects[9] = 35;
    v3->importantObjects[10] = 23;
    v3->importantObjects[11] = 36;
    v3->importantObjects[12] = 28;
    v3->importantObjects[13] = 18;
    v3->importantObjects[14] = 13;
    v3->importantObjects[15] = 39;
  }
  v3->idleTimeoutValue = 4000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)&v3->vfptr);
}
// 5757D0: using guessed type int (__thiscall *TribeHuntedAnimalUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00503D00) --------------------------------------------------------
TribeHuntedAnimalUnitAIModule *__thiscall TribeHuntedAnimalUnitAIModule::`vector deleting destructor'(TribeHuntedAnimalUnitAIModule *this, unsigned int __flags)
{
  TribeHuntedAnimalUnitAIModule *v2; // esi@1

  v2 = this;
  TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00503D30) --------------------------------------------------------
int __userpurge TribeHuntedAnimalUnitAIModule::processNotify@<eax>(TribeHuntedAnimalUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeHuntedAnimalUnitAIModule *v4; // esi@1
  int result; // eax@3
  int v6; // ebp@7
  int v7; // ecx@7
  int i; // eax@7
  int v9; // ebx@12
  int *v10; // edi@12
  int j; // eax@13
  int v12; // [sp+0h] [bp-10h]@0
  int v13; // [sp+4h] [bp-Ch]@0
  _DWORD *v14; // [sp+8h] [bp-8h]@0

  v4 = this;
  if ( nEvent->mType == 500 )
  {
    if ( nEvent->p2 > 0 )
    {
      v6 = nEvent->caller;
      v7 = this->attackingUnitsValue.numberValue;
      for ( i = 0; i < v7; ++i )
      {
        if ( i >= v4->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v4->attackingUnitsValue.value[i] == v6 )
          goto LABEL_18;
      }
      if ( v7 > v4->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v9 = v7 + 1;
        v10 = (int *)operator new(4 * (v7 + 1));
        if ( v10 )
        {
          for ( j = 0; j < v4->attackingUnitsValue.maximumSizeValue; v10[j - 1] = v4->attackingUnitsValue.value[j - 1] )
          {
            if ( j >= v9 )
              break;
            ++j;
          }
          operator delete(v4->attackingUnitsValue.value);
          v4->attackingUnitsValue.value = v10;
          v4->attackingUnitsValue.maximumSizeValue = v9;
        }
      }
      v4->attackingUnitsValue.value[v4->attackingUnitsValue.numberValue++] = v6;
LABEL_18:
      ((void (__stdcall *)(signed int))v4->objectValue->vfptr->setUnderAttack)(1);
      v4->vfptr->runAwayFromAttackers((UnitAIModule *)v4, 1);
      result = 3;
    }
    else
    {
      UnitAIModule::purgeNotifyQueue((UnitAIModule *)&this->vfptr, uTime);
      result = 4;
    }
  }
  else if ( nEvent->mType == 527 )
  {
    result = 2;
  }
  else
  {
    result = UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v12, v13, v14);
  }
  return result;
}

//----- (00503E30) --------------------------------------------------------
int __userpurge TribeHuntedAnimalUnitAIModule::processIdle@<eax>(TribeHuntedAnimalUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch)
{
  TribeHuntedAnimalUnitAIModule *v3; // esi@1
  UnitAIModuleVtbl *v4; // ebx@1
  int v5; // eax@1
  RGE_Static_Object *v6; // edi@2
  RGE_Static_Object *v7; // eax@3
  double v8; // rt1@3
  double v9; // st5@3
  double v10; // st6@3
  float xDiff; // ST34_4@3
  float yDiff; // ST30_4@3
  double v13; // st7@3
  double v14; // st4@3
  double v15; // st3@3
  double v16; // st6@3
  float v17; // ST30_4@3
  float v18; // ST34_4@3
  float v19; // ST18_4@3
  float v20; // ST14_4@3
  int result; // eax@3

  v3 = this;
  v4 = this->vfptr;
  v5 = ((int (__stdcall *)(signed int, signed int, signed int, signed int, _DWORD))this->vfptr->closestObject)(
         -1,
         -1,
         -1,
         -1,
         0);
  if ( v5 != -1 && (v6 = RGE_Game_World::object(v3->objectValue->owner->world, v5)) != 0 )
  {
    ((void (*)(void))v3->objectValue->vfptr->maximumSpeed)();
    v7 = v3->objectValue;
    v8 = v6->world_y - v7->world_y;
    v9 = v6->world_x - v7->world_x;
    v10 = a2 * 3.0;
    xDiff = v9;
    yDiff = v8;
    v13 = yDiff;
    v14 = v8 * yDiff;
    v15 = v10;
    v16 = xDiff;
    v17 = v15;
    v18 = sqrt(v9 * xDiff + v14);
    v19 = v7->world_y - v13 / v18 * v17;
    v20 = v7->world_x - v16 / v18 * v17;
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v4->evasiveMoveTo)(
      LODWORD(v20),
      LODWORD(v19),
      LODWORD(v7->world_z),
      1);
    result = 6;
  }
  else
  {
    result = 5;
  }
  return result;
}

//----- (00503F20) --------------------------------------------------------
void __thiscall TribePreditorUnitAIModule::TribePreditorUnitAIModule(TribePreditorUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribePreditorUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribePreditorUnitAIModule::`vftable';
  v3->numberImportantObjects = 17;
  v4 = (int *)operator new(0x44u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 29;
    v3->importantObjects[1] = 9;
    v3->importantObjects[2] = 0;
    v3->importantObjects[3] = 4;
    v3->importantObjects[4] = 26;
    v3->importantObjects[5] = 24;
    v3->importantObjects[6] = 6;
    v3->importantObjects[7] = 25;
    v3->importantObjects[8] = 17;
    v3->importantObjects[9] = 13;
    v3->importantObjects[10] = 12;
    v3->importantObjects[11] = 35;
    v3->importantObjects[12] = 23;
    v3->importantObjects[13] = 36;
    v3->importantObjects[14] = 28;
    v3->importantObjects[15] = 18;
    v3->importantObjects[16] = 39;
  }
}
// 5758E8: using guessed type int (__thiscall *TribePreditorUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00504070) --------------------------------------------------------
TribePreditorUnitAIModule *__thiscall TribePreditorUnitAIModule::`scalar deleting destructor'(TribePreditorUnitAIModule *this, unsigned int __flags)
{
  TribePreditorUnitAIModule *v2; // esi@1

  v2 = this;
  TribePreditorUnitAIModule::~TribePreditorUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (005040A0) --------------------------------------------------------
int __stdcall TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int oType)
{
  return 1;
}

//----- (005040B0) --------------------------------------------------------
int __userpurge TribePreditorUnitAIModule::processNotify@<eax>(TribePreditorUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribePreditorUnitAIModule *v4; // esi@1
  RGE_Static_Object *v5; // eax@2
  RGE_Static_Object *v7; // eax@6
  signed int v8; // eax@7
  UnitAIModuleVtbl *v9; // edi@10
  int v10; // [sp+0h] [bp-Ch]@0
  int v11; // [sp+4h] [bp-8h]@0
  _DWORD *v12; // [sp+8h] [bp-4h]@0

  v4 = this;
  if ( nEvent->mType == 508 )
  {
    v5 = RGE_Game_World::object(this->objectValue->owner->world, this->currentTargetValue);
    if ( v5 )
    {
      a2 = RGE_Static_Object::distance_to_object(v4->objectValue, v5);
      if ( a2 <= v4->objectValue->master_obj->los )
      {
        v4->vfptr->attackObject((UnitAIModule *)v4, v4->currentTargetValue, 1);
        return 3;
      }
    }
    UnitAIModule::removeCurrentTarget((UnitAIModule *)&v4->vfptr);
    if ( actionFile )
    {
      v7 = v4->objectValue;
      if ( v7 )
        v8 = v7->id;
      else
        v8 = -1;
      fprintf(actionFile, aDCallStopobjec, v8, aCMsdevWorkA_48, 250);
    }
    v9 = v4->vfptr;
    v4->vfptr->stopObject((UnitAIModule *)v4, 1);
    ((void (__thiscall *)(TribePreditorUnitAIModule *, NotifyEvent *))v9->notifyCommander)(v4, nEvent);
  }
  return UnitAIModule::processNotify((UnitAIModule *)&v4->vfptr, a2, nEvent, uTime, v10, v11, v12);
}

//----- (00504170) --------------------------------------------------------
void __thiscall TribeElephantUnitAIModule::TribeElephantUnitAIModule(TribeElephantUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeElephantUnitAIModule *v3; // esi@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeElephantUnitAIModule::`vftable';
}
// 5759C8: using guessed type int (__thiscall *TribeElephantUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00504190) --------------------------------------------------------
TribeElephantUnitAIModule *__thiscall TribeElephantUnitAIModule::`scalar deleting destructor'(TribeElephantUnitAIModule *this, unsigned int __flags)
{
  TribeElephantUnitAIModule *v2; // esi@1

  v2 = this;
  TribeElephantUnitAIModule::~TribeElephantUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (005041C0) --------------------------------------------------------
int __userpurge TribeElephantUnitAIModule::processNotify@<eax>(TribeElephantUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeElephantUnitAIModule *v4; // esi@1
  int result; // eax@3
  int v6; // ebp@7
  int v7; // ecx@7
  int i; // eax@7
  int v9; // ebx@12
  int *v10; // edi@12
  int j; // eax@13
  UnitAIModuleVtbl *v12; // edi@18
  int v13; // eax@18
  int v14; // [sp+0h] [bp-10h]@0
  int v15; // [sp+4h] [bp-Ch]@0
  _DWORD *v16; // [sp+8h] [bp-8h]@0

  v4 = this;
  if ( nEvent->mType == 500 )
  {
    if ( nEvent->p2 > 0 )
    {
      v6 = nEvent->caller;
      v7 = this->attackingUnitsValue.numberValue;
      for ( i = 0; i < v7; ++i )
      {
        if ( i >= v4->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v4->attackingUnitsValue.value[i] == v6 )
          goto LABEL_18;
      }
      if ( v7 > v4->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v9 = v7 + 1;
        v10 = (int *)operator new(4 * (v7 + 1));
        if ( v10 )
        {
          for ( j = 0; j < v4->attackingUnitsValue.maximumSizeValue; v10[j - 1] = v4->attackingUnitsValue.value[j - 1] )
          {
            if ( j >= v9 )
              break;
            ++j;
          }
          operator delete(v4->attackingUnitsValue.value);
          v4->attackingUnitsValue.value = v10;
          v4->attackingUnitsValue.maximumSizeValue = v9;
        }
      }
      v4->attackingUnitsValue.value[v4->attackingUnitsValue.numberValue++] = v6;
LABEL_18:
      ((void (__stdcall *)(signed int))v4->objectValue->vfptr->setUnderAttack)(1);
      v12 = v4->vfptr;
      v13 = v4->vfptr->closestAttacker((UnitAIModule *)v4, 0);
      v12->attackObject((UnitAIModule *)v4, v13, 0);
      result = 3;
    }
    else
    {
      UnitAIModule::purgeNotifyQueue((UnitAIModule *)&this->vfptr, uTime);
      result = 4;
    }
  }
  else if ( nEvent->mType == 527 )
  {
    result = 2;
  }
  else
  {
    result = UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v14, v15, v16);
  }
  return result;
}

//----- (005042D0) --------------------------------------------------------
int __stdcall TribeElephantUnitAIModule::processIdle(int doSearch)
{
  return 5;
}

//----- (005042E0) --------------------------------------------------------
void __thiscall TribeLionUnitAIModule::TribeLionUnitAIModule(TribeLionUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeLionUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeLionUnitAIModule::`vftable';
  v3->numberImportantObjects = 17;
  v4 = (int *)operator new(0x44u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 29;
    v3->importantObjects[1] = 9;
    v3->importantObjects[2] = 0;
    v3->importantObjects[3] = 4;
    v3->importantObjects[4] = 26;
    v3->importantObjects[5] = 24;
    v3->importantObjects[6] = 6;
    v3->importantObjects[7] = 25;
    v3->importantObjects[8] = 17;
    v3->importantObjects[9] = 13;
    v3->importantObjects[10] = 12;
    v3->importantObjects[11] = 35;
    v3->importantObjects[12] = 23;
    v3->importantObjects[13] = 36;
    v3->importantObjects[14] = 28;
    v3->importantObjects[15] = 18;
    v3->importantObjects[16] = 39;
  }
  v3->idleTimeoutValue = 6000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)&v3->vfptr);
}
// 575AA8: using guessed type int (__thiscall *TribeLionUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00504440) --------------------------------------------------------
TribeLionUnitAIModule *__thiscall TribeLionUnitAIModule::`scalar deleting destructor'(TribeLionUnitAIModule *this, unsigned int __flags)
{
  TribeLionUnitAIModule *v2; // esi@1

  v2 = this;
  TribeLionUnitAIModule::~TribeLionUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00504470) --------------------------------------------------------
int __stdcall TribeLionUnitAIModule::canAttackUnitAtNeutrality(int oType)
{
  return 1;
}

//----- (00504480) --------------------------------------------------------
int __userpurge TribeLionUnitAIModule::processNotify@<eax>(TribeLionUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeLionUnitAIModule *v4; // esi@1
  RGE_Static_Object *v5; // eax@3
  int result; // eax@5
  RGE_Static_Object *v7; // eax@7
  signed int v8; // eax@8
  UnitAIModuleVtbl *v9; // edi@11
  RGE_Static_Object *v10; // eax@18
  signed int v11; // eax@19
  int v12; // [sp+0h] [bp-Ch]@0
  int v13; // [sp+4h] [bp-8h]@0
  _DWORD *v14; // [sp+8h] [bp-4h]@0

  v4 = this;
  if ( nEvent->mType == 506 )
  {
    if ( nEvent->p1 == 600 )
    {
      if ( RGE_Base_Game::scenarioGame(rge_base_game) != 1 || RGE_Base_Game::singlePlayerGame(rge_base_game) != 1 )
        v4->idleTimeoutValue = 25000;
      else
        v4->idleTimeoutValue = 5000 * (RGE_Game_World::difficultyLevel(v4->objectValue->owner->world) + 3);
      UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)&v4->vfptr);
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&v4->vfptr);
      if ( actionFile )
      {
        v10 = v4->objectValue;
        if ( v10 )
          v11 = v10->id;
        else
          v11 = -1;
        fprintf(actionFile, aDCallStopobjec, v11, aCMsdevWorkA_48, 401);
      }
      v4->vfptr->stopObject((UnitAIModule *)v4, 1);
    }
    return UnitAIModule::processNotify((UnitAIModule *)&v4->vfptr, a2, nEvent, uTime, v12, v13, v14);
  }
  if ( nEvent->mType != 508 )
    return UnitAIModule::processNotify((UnitAIModule *)&v4->vfptr, a2, nEvent, uTime, v12, v13, v14);
  v5 = RGE_Game_World::object(this->objectValue->owner->world, this->currentTargetValue);
  if ( v5 && (a2 = RGE_Static_Object::distance_to_object(v4->objectValue, v5), a2 <= v4->objectValue->master_obj->los) )
  {
    v4->vfptr->attackObject((UnitAIModule *)v4, v4->currentTargetValue, 1);
    result = 3;
  }
  else
  {
    UnitAIModule::removeCurrentTarget((UnitAIModule *)&v4->vfptr);
    if ( actionFile )
    {
      v7 = v4->objectValue;
      if ( v7 )
        v8 = v7->id;
      else
        v8 = -1;
      fprintf(actionFile, aDCallStopobjec, v8, aCMsdevWorkA_48, 428);
    }
    v9 = v4->vfptr;
    v4->vfptr->stopObject((UnitAIModule *)v4, 1);
    ((void (__thiscall *)(TribeLionUnitAIModule *, NotifyEvent *))v9->notifyCommander)(v4, nEvent);
    result = UnitAIModule::processNotify((UnitAIModule *)&v4->vfptr, a2, nEvent, uTime, v12, v13, v14);
  }
  return result;
}

//----- (00504600) --------------------------------------------------------
int __thiscall TribeLionUnitAIModule::processIdle(TribeLionUnitAIModule *this, int doSearch)
{
  TribeLionUnitAIModule *v2; // esi@1
  UnitAIModuleVtbl *v3; // ebx@1
  int v4; // eax@1
  int v5; // edi@1
  RGE_Static_Object *v6; // eax@1
  int v7; // ebp@3
  double v8; // st7@7
  RGE_Static_Object *v9; // ecx@9
  double v10; // st7@9
  int result; // eax@13
  float maxReactDistance; // [sp+14h] [bp-8h]@9
  RGE_Static_Object *newTarget; // [sp+18h] [bp-4h]@1

  v2 = this;
  this->idleTimeoutValue = 6000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)&this->vfptr);
  v3 = v2->vfptr;
  v4 = v2->vfptr->closestObject((UnitAIModule *)v2, -1, -1, -1, -1, 0);
  v5 = v4;
  v6 = UnitAIModule::lookupObject((UnitAIModule *)&v2->vfptr, v4);
  newTarget = v6;
  if ( v5 == -1 || !v6 )
    goto LABEL_17;
  v7 = RGE_Game_World::difficultyLevel(v2->objectValue->owner->world);
  if ( RGE_Base_Game::scenarioGame(rge_base_game) != 1 || RGE_Base_Game::singlePlayerGame(rge_base_game) != 1 || v7 < 3 )
  {
    v9 = v2->objectValue;
    maxReactDistance = v9->master_obj->los + v9->master_obj->los;
  }
  else
  {
    v8 = v7 == 3 ? 0.75 : 0.5;
    v9 = v2->objectValue;
    v10 = v8 * v9->master_obj->los;
    maxReactDistance = v10;
    if ( v10 < 1.0 )
      maxReactDistance = 1.0;
  }
  if ( RGE_Static_Object::distance_to_object(v9, newTarget) <= maxReactDistance )
  {
    v3->attackObject((UnitAIModule *)v2, v5, 0);
    result = 6;
  }
  else
  {
LABEL_17:
    result = 5;
  }
  return result;
}

//----- (00504700) --------------------------------------------------------
void __thiscall TribeRangedUnitAIModule::TribeRangedUnitAIModule(TribeRangedUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeRangedUnitAIModule *v3; // esi@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeRangedUnitAIModule::`vftable';
}
// 575B88: using guessed type int (__thiscall *TribeRangedUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00504720) --------------------------------------------------------
TribeRangedUnitAIModule *__thiscall TribeRangedUnitAIModule::`vector deleting destructor'(TribeRangedUnitAIModule *this, unsigned int __flags)
{
  TribeRangedUnitAIModule *v2; // esi@1

  v2 = this;
  TribeRangedUnitAIModule::~TribeRangedUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00504750) --------------------------------------------------------
int __userpurge TribeRangedUnitAIModule::processNotify@<eax>(TribeRangedUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeRangedUnitAIModule *v4; // esi@1
  int result; // eax@2
  RGE_Static_Object *v6; // eax@4
  RGE_Static_Object *v7; // ebx@4
  UnitAIModuleVtbl *v8; // ebp@6
  RGE_Static_Object *v9; // edi@6
  RGE_Static_Object *v10; // eax@6
  double v11; // st7@6
  double v12; // st6@6
  double v13; // st5@6
  float v14; // ST30_4@6
  float v15; // ST2C_4@6
  int v16; // [sp+3Ch] [bp-10h]@0
  int v17; // [sp+40h] [bp-Ch]@0
  _DWORD *v18; // [sp+44h] [bp-8h]@0
  NotifyEvent *nEventa; // [sp+50h] [bp+4h]@6
  NotifyEvent *nEventb; // [sp+50h] [bp+4h]@6

  v4 = this;
  if ( nEvent->mType == 512 )
  {
    if ( this->currentActionValue == 600
      && (v6 = RGE_Game_World::object(this->objectValue->owner->world, this->currentTargetValue), (v7 = v6) != 0)
      && (v6->vfptr->getSpeed(v6), a2 != 0.0) )
    {
      v8 = v4->vfptr;
      (*(void (__thiscall **)(TribeRangedUnitAIModule *, int, signed int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, signed int, int))&v4->vfptr->gap4[12])(
        v4,
        v4->objectValue->id,
        700,
        v4->currentTargetValue,
        -1,
        LODWORD(v4->currentTargetXValue),
        LODWORD(v4->currentTargetYValue),
        LODWORD(v4->currentTargetZValue),
        LODWORD(v4->desiredTargetDistanceValue),
        0,
        1,
        v4->currentOrderPriorityValue);
      v9 = v4->objectValue;
      v9->vfptr->rateOfFire(v9);
      *(float *)&nEventa = a2;
      v9->vfptr->maximumSpeed(v9);
      v10 = v4->objectValue;
      v11 = a2 * *(float *)&nEventa * 3.0;
      v12 = v7->world_x - v10->world_x;
      v13 = v7->world_y - v10->world_y;
      *(float *)&nEventb = sqrt(v12 * v12 + v13 * v13);
      v14 = v10->world_y - v13 / *(float *)&nEventb * v11;
      v15 = v10->world_x - v12 / *(float *)&nEventb * v11;
      ((void (__thiscall *)(TribeRangedUnitAIModule *, _DWORD, _DWORD, _DWORD, signed int))v8->evasiveMoveTo)(
        v4,
        LODWORD(v15),
        LODWORD(v14),
        LODWORD(v10->world_z),
        1);
      result = 3;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v16, v17, v18);
  }
  return result;
}

//----- (00504880) --------------------------------------------------------
void __thiscall TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(TribeRangedUnitAIModule2 *this, RGE_Static_Object *o, int iQS)
{
  TribeRangedUnitAIModule2 *v3; // esi@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeRangedUnitAIModule2::`vftable';
}
// 575C68: using guessed type int (__thiscall *TribeRangedUnitAIModule2::`vftable')(void *Memory, unsigned int __flags);

//----- (005048A0) --------------------------------------------------------
TribeRangedUnitAIModule2 *__thiscall TribeRangedUnitAIModule2::`vector deleting destructor'(TribeRangedUnitAIModule2 *this, unsigned int __flags)
{
  TribeRangedUnitAIModule2 *v2; // esi@1

  v2 = this;
  TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (005048D0) --------------------------------------------------------
int __userpurge TribeRangedUnitAIModule2::processNotify@<eax>(TribeRangedUnitAIModule2 *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeRangedUnitAIModule2 *v4; // esi@1
  int result; // eax@2
  RGE_Static_Object *v6; // eax@4
  RGE_Static_Object *v7; // ebx@4
  UnitAIModuleVtbl *v8; // ebp@6
  RGE_Static_Object *v9; // edi@6
  RGE_Static_Object *v10; // eax@6
  double v11; // st7@6
  int v12; // eax@6
  int v13; // ebp@7
  int v14; // ebx@9
  int *v15; // edi@9
  int i; // eax@10
  int v17; // ebx@16
  int *v18; // edi@16
  int j; // eax@17
  RGE_Static_Object *v20; // eax@21
  RGE_Static_Object *v21; // ecx@22
  RGE_Static_Object *v22; // eax@25
  long double v23; // st7@25
  float v24; // ST30_4@25
  float v25; // ST2C_4@25
  int v26; // [sp+3Ch] [bp-18h]@0
  int v27; // [sp+40h] [bp-14h]@0
  _DWORD *v28; // [sp+44h] [bp-10h]@0
  float evasiveMoveDistance; // [sp+4Ch] [bp-8h]@6
  UnitAIModuleVtbl *v30; // [sp+50h] [bp-4h]@6
  NotifyEvent *nEventb; // [sp+58h] [bp+4h]@6
  NotifyEvent *nEventa; // [sp+58h] [bp+4h]@6
  float yDiff; // [sp+5Ch] [bp+8h]@6

  v4 = this;
  if ( nEvent->mType == 512 )
  {
    if ( this->currentActionValue == 600
      && (v6 = RGE_Game_World::object(this->objectValue->owner->world, this->currentTargetValue), (v7 = v6) != 0)
      && (v6->vfptr->getSpeed(v6), a2 != 0.0) )
    {
      v8 = v4->vfptr;
      v30 = v4->vfptr;
      (*(void (__thiscall **)(TribeRangedUnitAIModule2 *, int, signed int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, signed int, int))&v4->vfptr->gap4[12])(
        v4,
        v4->objectValue->id,
        700,
        v4->currentTargetValue,
        -1,
        LODWORD(v4->currentTargetXValue),
        LODWORD(v4->currentTargetYValue),
        LODWORD(v4->currentTargetZValue),
        LODWORD(v4->desiredTargetDistanceValue),
        0,
        1,
        v4->currentOrderPriorityValue);
      v9 = v4->objectValue;
      v9->vfptr->rateOfFire(v9);
      *(float *)&nEventb = a2;
      v9->vfptr->maximumSpeed(v9);
      v10 = v4->objectValue;
      evasiveMoveDistance = a2 * *(float *)&nEventb * 3.0;
      yDiff = v7->world_x - v10->world_x;
      v11 = v7->world_y - v10->world_y;
      v12 = v4->attackingUnitsValue.numberValue;
      *(float *)&nEventa = v11;
      if ( v12 > 0 )
      {
        v13 = 0;
        if ( v12 > 0 )
        {
          do
          {
            if ( v13 > v4->attackingUnitsValue.maximumSizeValue - 1 )
            {
              v14 = v13 + 1;
              v15 = (int *)operator new(4 * v13 + 4);
              if ( v15 )
              {
                for ( i = 0; i < v4->attackingUnitsValue.maximumSizeValue; v15[i - 1] = v4->attackingUnitsValue.value[i - 1] )
                {
                  if ( i >= v14 )
                    break;
                  ++i;
                }
                operator delete(v4->attackingUnitsValue.value);
                v4->attackingUnitsValue.value = v15;
                v4->attackingUnitsValue.maximumSizeValue = v14;
              }
            }
            if ( v4->attackingUnitsValue.value[v13] != v4->currentTargetValue )
            {
              if ( v13 > v4->attackingUnitsValue.maximumSizeValue - 1 )
              {
                v17 = v13 + 1;
                v18 = (int *)operator new(4 * v13 + 4);
                if ( v18 )
                {
                  for ( j = 0;
                        j < v4->attackingUnitsValue.maximumSizeValue;
                        v18[j - 1] = v4->attackingUnitsValue.value[j - 1] )
                  {
                    if ( j >= v17 )
                      break;
                    ++j;
                  }
                  operator delete(v4->attackingUnitsValue.value);
                  v4->attackingUnitsValue.value = v18;
                  v4->attackingUnitsValue.maximumSizeValue = v17;
                }
              }
              v20 = RGE_Game_World::object(v4->objectValue->owner->world, v4->attackingUnitsValue.value[v13]);
              if ( v20 )
              {
                v21 = v4->objectValue;
                yDiff = v20->world_x - v21->world_x + yDiff;
                *(float *)&nEventa = v20->world_y - v21->world_y + *(float *)&nEventa;
              }
            }
            ++v13;
          }
          while ( v13 < v4->attackingUnitsValue.numberValue );
        }
        v8 = v30;
      }
      v22 = v4->objectValue;
      v23 = sqrt(yDiff * yDiff + *(float *)&nEventa * *(float *)&nEventa);
      v24 = v22->world_y - *(float *)&nEventa / v23 * evasiveMoveDistance;
      v25 = v22->world_x - yDiff / v23 * evasiveMoveDistance;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v8->evasiveMoveTo)(
        LODWORD(v25),
        LODWORD(v24),
        LODWORD(v22->world_z),
        1);
      result = 3;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v26, v27, v28);
  }
  return result;
}

//----- (00504B60) --------------------------------------------------------
void __thiscall TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(TribeCivilianUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeCivilianUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeCivilianUnitAIModule::`vftable';
  v3->numberImportantObjects = 11;
  v4 = (int *)operator new(0x2Cu);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 3;
    v3->importantObjects[1] = 7;
    v3->importantObjects[2] = 8;
    v3->importantObjects[3] = 9;
    v3->importantObjects[4] = 10;
    v3->importantObjects[5] = 15;
    v3->importantObjects[6] = 17;
    v3->importantObjects[7] = 18;
    v3->importantObjects[8] = 32;
    v3->importantObjects[9] = 33;
    v3->importantObjects[10] = 27;
  }
}
// 575D48: using guessed type int (__thiscall *TribeCivilianUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00504C60) --------------------------------------------------------
TribeCivilianUnitAIModule *__thiscall TribeCivilianUnitAIModule::`vector deleting destructor'(TribeCivilianUnitAIModule *this, unsigned int __flags)
{
  TribeCivilianUnitAIModule *v2; // esi@1

  v2 = this;
  TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00504C90) --------------------------------------------------------
BOOL __stdcall TribeCivilianUnitAIModule::importantWhenDead(int objectType)
{
  return objectType == 7
      || objectType == 9
      || objectType == 10
      || objectType == 15
      || objectType == 8
      || objectType == 32;
}

//----- (00504CC0) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeCivilianUnitAIModule::attackObject(TribeCivilianUnitAIModule *this, int targetID, int unconditional)
{
  TribeCivilianUnitAIModule *v3; // esi@1
  RGE_Static_Object *result; // eax@1
  int v5; // eax@2

  v3 = this;
  result = RGE_Game_World::object(this->objectValue->owner->world, targetID);
  if ( result )
  {
    v5 = result->master_obj->object_group;
    if ( v5 == 9 || v5 == 10 || v5 == 15 )
      result = (RGE_Static_Object *)v3->vfptr->huntObject((UnitAIModule *)v3, targetID, unconditional);
    else
      result = (RGE_Static_Object *)UnitAIModule::attackObject((UnitAIModule *)&v3->vfptr, targetID, unconditional);
  }
  return result;
}

//----- (00504D20) --------------------------------------------------------
RGE_Static_Object *__stdcall TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object *unit)
{
  RGE_Static_Object *result; // eax@1

  result = unit;
  if ( unit )
    result = (RGE_Static_Object *)(unit->master_obj->object_group != 1);
  return result;
}

//----- (00504D40) --------------------------------------------------------
int __stdcall TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int oType)
{
  return 0;
}

//----- (00504D50) --------------------------------------------------------
BOOL __stdcall TribeCivilianUnitAIModule::retryableOrder(int orderType)
{
  return orderType == 705 || orderType == 709 || orderType == 713;
}

//----- (00504D80) --------------------------------------------------------
int __stdcall TribeCivilianUnitAIModule::convertToLOSResourceType(int oType)
{
  int result; // eax@2

  switch ( oType )
  {
    case 7:
      result = 1;
      break;
    case 32:
      result = 4;
      break;
    case 8:
      result = 3;
      break;
    case 15:
      result = 0;
      break;
    case 5:
    case 31:
    case 33:
      result = 2;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}

//----- (00504E10) --------------------------------------------------------
int __userpurge TribeCivilianUnitAIModule::processNotify@<eax>(TribeCivilianUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  NotifyEvent *v4; // ebx@1
  TribeCivilianUnitAIModule *v5; // esi@1
  int result; // eax@3
  RGE_Static_Object *v7; // edi@6
  int v8; // ST28_4@6
  int v9; // ecx@14
  int i; // eax@14
  int v11; // ecx@21
  int v12; // ebp@21
  int j; // eax@21
  int v14; // ebx@26
  int *v15; // edi@26
  int k; // eax@27
  char v17; // al@33
  int v18; // ecx@33
  UnitAIModuleVtbl *v19; // edi@44
  UnitAIModuleVtbl *v20; // edi@48
  RGE_Static_Object *v21; // eax@49
  signed int v22; // eax@50
  RGE_Static_Object *v23; // eax@56
  signed int v24; // eax@57
  UnitAIModuleVtbl *v25; // edi@59
  RGE_Static_Object *v26; // eax@62
  signed int v27; // eax@63
  UnitAIModuleVtbl *v28; // edi@65
  int v29; // eax@66
  int v30; // ebx@67
  RGE_Static_Object *v31; // eax@70
  signed int v32; // eax@71
  UnitAIModuleVtbl *v33; // edi@74
  UnitAIModuleVtbl *v34; // edi@75
  int v35; // eax@75
  int v36; // eax@76
  RGE_Static_Object *v37; // eax@82
  signed int v38; // eax@83
  RGE_Static_Object *v39; // eax@89
  int v40; // ebx@93
  RGE_Static_Object *v41; // eax@96
  signed int v42; // eax@97
  UnitAIModuleVtbl *v43; // edi@100
  int v44; // eax@101
  int v45; // eax@102
  RGE_Static_Object *v46; // eax@110
  RGE_Static_Object *v47; // eax@115
  signed int v48; // eax@116
  RGE_Static_Object *v49; // ecx@120
  float v50; // et1@120
  double v52; // st7@120
  unsigned __int8 v53; // c0@120
  unsigned __int8 v54; // c3@120
  double v55; // st7@121
  float v56; // et1@123
  double v58; // st7@123
  unsigned __int8 v59; // c0@123
  unsigned __int8 v60; // c3@123
  double v61; // st7@124
  UnitAIModuleVtbl *v62; // ebp@128
  int (__thiscall *v63)(UnitAIModule *, int, int, int, int, int *); // ebx@128
  int v64; // edi@128
  int v65; // eax@130
  RGE_Static_Object *v66; // eax@136
  RGE_Static_Object *v67; // eax@143
  signed int v68; // eax@144
  RGE_Static_Object *v69; // eax@150
  signed int v70; // eax@151
  RGE_Static_Object *v71; // eax@158
  signed int v72; // eax@159
  UnitAIModuleVtbl *v73; // edi@162
  int v74; // [sp+Ch] [bp-14h]@0
  int v75; // [sp+10h] [bp-10h]@0
  _DWORD *v76; // [sp+14h] [bp-Ch]@0
  int tileX; // [sp+1Ch] [bp-4h]@6
  NotifyEvent *nEventa; // [sp+24h] [bp+4h]@33

  v4 = nEvent;
  v5 = this;
  switch ( nEvent->mType )
  {
    case 0x20F:
      if ( RGE_Game_World::difficultyLevel(this->objectValue->owner->world) < 3 )
        goto LABEL_4;
      return 2;
    case 0x1F4:
LABEL_4:
      if ( nEvent->p2 <= 0 )
      {
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v5->objectValue->owner->vfptr->notify)(
          v5->objectValue->id,
          v5->objectValue->id,
          521,
          nEvent->caller,
          0,
          0);
        UnitAIModule::purgeNotifyQueue((UnitAIModule *)&v5->vfptr, uTime);
        return 4;
      }
      *(float *)&v7 = COERCE_FLOAT(UnitAIModule::lookupObject((UnitAIModule *)&v5->vfptr, nEvent->caller));
      v8 = v5->currentTargetValue;
      uTime = (unsigned int)v7;
      *(float *)&tileX = COERCE_FLOAT(UnitAIModule::lookupObject((UnitAIModule *)&v5->vfptr, v8));
      if ( *(float *)&v7 == 0.0 )
        return 2;
      if ( RGE_Player::computerPlayer(v5->objectValue->owner) != 1 )
      {
        if ( v5->attackingUnitsValue.numberValue )
          goto LABEL_14;
        goto LABEL_13;
      }
      if ( v7->owner->id || v7->id != v5->currentTargetValue )
LABEL_13:
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v5->objectValue->owner->vfptr->notify)(
          v5->objectValue->id,
          v5->objectValue->id,
          513,
          nEvent->caller,
          0,
          0);
LABEL_14:
      v9 = v5->attackingUnitsValue.numberValue;
      for ( i = 0; i < v9; ++i )
      {
        if ( i >= v5->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v5->attackingUnitsValue.value[i] == nEvent->caller )
          goto LABEL_21;
      }
      if ( !RGE_Player::computerPlayer(v5->objectValue->owner) && v5->currentTargetValue != nEvent->caller )
        UnitAIModule::askForHelp((UnitAIModule *)&v5->vfptr, nEvent->caller, v74, v75, (int)v76);
LABEL_21:
      v11 = v5->attackingUnitsValue.numberValue;
      v12 = nEvent->caller;
      for ( j = 0; j < v11; ++j )
      {
        if ( j >= v5->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v5->attackingUnitsValue.value[j] == v12 )
          goto LABEL_33;
      }
      if ( v11 > v5->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v14 = v11 + 1;
        v15 = (int *)operator new(4 * (v11 + 1));
        if ( v15 )
        {
          for ( k = 0; k < v5->attackingUnitsValue.maximumSizeValue; v15[k - 1] = v5->attackingUnitsValue.value[k - 1] )
          {
            if ( k >= v14 )
              break;
            ++k;
          }
          operator delete(v5->attackingUnitsValue.value);
          v5->attackingUnitsValue.value = v15;
          v5->attackingUnitsValue.maximumSizeValue = v14;
        }
        v4 = nEvent;
      }
      v5->attackingUnitsValue.value[v5->attackingUnitsValue.numberValue++] = v12;
LABEL_33:
      ((void (__stdcall *)(signed int))v5->objectValue->vfptr->setUnderAttack)(1);
      ((void (*)(void))v5->objectValue->vfptr->getSpeed)();
      *(float *)&nEventa = a2;
      v17 = ((int (*)(void))v5->objectValue->vfptr->actionState)();
      v18 = v5->currentOrderValue;
      if ( v18 == 710 && *(float *)&nEventa > 0.0
        || v18 == 700
        || v18 == 713
        && v17 == 12
        && *(float *)&tileX != 0.0
        && *(_WORD *)(*(_DWORD *)(tileX + 8) + 20) == 10
        && !*(_WORD *)(*(_DWORD *)(uTime + 12) + 74)
        || v18 == 718 )
      {
        return 2;
      }
      if ( *(_WORD *)(*(_DWORD *)(uTime + 12) + 74) )
      {
        if ( v5->currentActionValue == 610 && *(float *)&nEventa != 0.0 )
          return 3;
        v20 = v5->vfptr;
        (*(void (__thiscall **)(TribeCivilianUnitAIModule *, int, int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))&v5->vfptr->gap4[12])(
          v5,
          v5->objectValue->id,
          v18,
          v5->currentTargetValue,
          -1,
          LODWORD(v5->currentTargetXValue),
          LODWORD(v5->currentTargetYValue),
          LODWORD(v5->currentTargetZValue),
          LODWORD(v5->desiredTargetDistanceValue),
          0,
          0,
          v5->currentOrderPriorityValue);
        if ( actionFile )
        {
          v21 = v5->objectValue;
          if ( v21 )
            v22 = v21->id;
          else
            v22 = -1;
          fprintf(actionFile, aDCallStopobjec, v22, aCMsdevWorkA_48, 922);
        }
        v20->stopObject((UnitAIModule *)v5, 1);
        v20->runAwayFromAttackers((UnitAIModule *)v5, 1);
        result = 3;
      }
      else if ( v18 == -1 )
      {
        v5->vfptr->attackObject((UnitAIModule *)v5, v4->caller, 1);
        result = 3;
      }
      else
      {
        v19 = v5->vfptr;
        (*(void (__thiscall **)(TribeCivilianUnitAIModule *, int, int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))&v5->vfptr->gap4[12])(
          v5,
          v5->objectValue->id,
          v18,
          v5->currentTargetValue,
          -1,
          LODWORD(v5->currentTargetXValue),
          LODWORD(v5->currentTargetYValue),
          LODWORD(v5->currentTargetZValue),
          LODWORD(v5->desiredTargetDistanceValue),
          0,
          0,
          v5->currentOrderPriorityValue);
        v5->currentOrderValue = 700;
        v5->currentOrderPriorityValue = 100;
        v19->attackObject((UnitAIModule *)v5, v4->caller, 1);
        v5->stopAfterTargetKilledValue = 1;
        result = 3;
      }
      return result;
    case 0x1FA:
      if ( this->currentActionValue != nEvent->p1 )
        return 2;
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
      if ( !actionFile )
        goto LABEL_162;
      v23 = v5->objectValue;
      if ( v23 )
        v24 = v23->id;
      else
        v24 = -1;
      fprintf(actionFile, aDCallStopobjec, v24, aCMsdevWorkA_48, 938);
      v25 = v5->vfptr;
      v5->vfptr->stopObject((UnitAIModule *)v5, 1);
      ((void (__thiscall *)(TribeCivilianUnitAIModule *, NotifyEvent *))v25->notifyCommander)(v5, nEvent);
      return 2;
    case 0x1F9:
      if ( this->currentActionValue != nEvent->p1 )
        return 2;
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
      if ( !actionFile )
        goto LABEL_162;
      v26 = v5->objectValue;
      if ( v26 )
        v27 = v26->id;
      else
        v27 = -1;
      fprintf(actionFile, aDCallStopobjec, v27, aCMsdevWorkA_48, 953);
      v28 = v5->vfptr;
      v5->vfptr->stopObject((UnitAIModule *)v5, 1);
      ((void (__thiscall *)(TribeCivilianUnitAIModule *, NotifyEvent *))v28->notifyCommander)(v5, nEvent);
      return 2;
    case 0x1FB:
    case 0x202:
      v29 = this->currentActionValue;
      if ( v29 == 613 )
      {
        v30 = this->currentTargetTypeValue;
        if ( v30 == -1 )
        {
          v30 = this->lastTargetTypeValue;
          if ( v30 == -1 )
          {
            UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
            if ( actionFile )
            {
              v31 = v5->objectValue;
              if ( v31 )
                v32 = v31->id;
              else
                v32 = -1;
              fprintf(actionFile, aDCallStopobjec, v32, aCMsdevWorkA_48, 979);
            }
            v33 = v5->vfptr;
            v5->vfptr->stopObject((UnitAIModule *)v5, 1);
            ((void (__thiscall *)(TribeCivilianUnitAIModule *, NotifyEvent *))v33->notifyCommander)(v5, nEvent);
            return 2;
          }
        }
        v34 = this->vfptr;
        v35 = this->vfptr->convertToLOSResourceType((UnitAIModule *)this, v30);
        v74 = 0;
        if ( v35 == -1 )
          v36 = ((int (__thiscall *)(TribeCivilianUnitAIModule *, int, signed int, signed int, signed int))v34->closestObject)(
                  v5,
                  v30,
                  -1,
                  -1,
                  -1);
        else
          v36 = ((int (__thiscall *)(TribeCivilianUnitAIModule *, int))v34->closestResourceObject)(v5, v35);
        if ( v36 != -1 )
        {
          if ( v34->huntObject((UnitAIModule *)v5, v36, 1) == 1 )
            return 3;
          UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
          if ( actionFile )
          {
            v37 = v5->objectValue;
            if ( v37 )
              v38 = v37->id;
            else
              v38 = -1;
            fprintf(actionFile, aDCallStopobjec, v38, aCMsdevWorkA_48, 1014);
          }
          ((void (__thiscall *)(TribeCivilianUnitAIModule *, signed int, _DWORD))v34->stopObject)(v5, 1, 0);
          goto LABEL_155;
        }
        if ( RGE_Player::computerPlayer(v5->objectValue->owner) != 1 )
          goto LABEL_156;
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
        if ( actionFile )
        {
          v39 = v5->objectValue;
          if ( v39 )
            fprintf(actionFile, aDCallStopobjec, v39->id, aCMsdevWorkA_48, 1039);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 1039);
        }
        goto LABEL_154;
      }
      if ( v29 == 609 )
      {
        v40 = this->currentTargetTypeValue;
        if ( v40 == -1 )
        {
          v40 = this->lastTargetTypeValue;
          if ( v40 == -1 )
          {
            UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
            if ( actionFile )
            {
              v41 = v5->objectValue;
              if ( v41 )
                v42 = v41->id;
              else
                v42 = -1;
              fprintf(actionFile, aDCallStopobjec, v42, aCMsdevWorkA_48, 1057);
            }
            v43 = v5->vfptr;
            v5->vfptr->stopObject((UnitAIModule *)v5, 1);
            ((void (__thiscall *)(TribeCivilianUnitAIModule *, NotifyEvent *))v43->notifyCommander)(v5, nEvent);
            return 2;
          }
        }
        v34 = this->vfptr;
        v44 = this->vfptr->convertToLOSResourceType((UnitAIModule *)this, v40);
        if ( v44 == -1 )
        {
          if ( nEvent->p2 == 50 )
            v45 = v34->closestObject((UnitAIModule *)v5, v40, -1, 2, 50, 0);
          else
            v45 = v34->closestObject((UnitAIModule *)v5, v40, -1, -1, -1, 0);
        }
        else
        {
          v45 = v34->closestResourceObject((UnitAIModule *)v5, v44, 0);
        }
        if ( v45 != -1 )
        {
          if ( v34->gatherObject((UnitAIModule *)v5, v45, 1) == 1 )
            return 3;
          UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
          if ( actionFile )
          {
            v46 = v5->objectValue;
            if ( v46 )
              fprintf(actionFile, aDCallStopobjec, v46->id, aCMsdevWorkA_48, 1094);
            else
              fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 1094);
          }
          goto LABEL_154;
        }
        if ( RGE_Player::computerPlayer(v5->objectValue->owner) == 1 )
        {
          UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
          if ( actionFile )
          {
            v47 = v5->objectValue;
            if ( v47 )
              v48 = v47->id;
            else
              v48 = -1;
            fprintf(actionFile, aDCallStopobjec, v48, aCMsdevWorkA_48, 1107);
            v34->stopObject((UnitAIModule *)v5, 1);
            goto LABEL_155;
          }
          goto LABEL_147;
        }
        if ( nEvent->p2 == 50 )
        {
          v49 = v5->objectValue;
          v50 = v49->world_x;
          v52 = v49->world_x;
          if ( v53 | v54 )
            v55 = v52 - -2.5;
          else
            v55 = v52 - 2.5;
          *(float *)&tileX = v55;
          v56 = v49->world_y;
          v58 = v49->world_y;
          if ( v59 | v60 )
            v61 = v58 - -2.5;
          else
            v61 = v58 - 2.5;
          *(float *)&uTime = v61;
          ((void (__thiscall *)(TribeCivilianUnitAIModule *, int, unsigned int, _DWORD, signed int))v34->evasiveMoveTo)(
            v5,
            tileX,
            uTime,
            LODWORD(v49->world_z),
            1);
        }
      }
      else
      {
        if ( v29 != 602 )
        {
          if ( v29 != 605 )
            goto LABEL_156;
          v34 = this->vfptr;
          if ( this->vfptr->closestUndiscoveredTile((UnitAIModule *)this, &tileX, (int *)&uTime, 1) != 1 )
          {
            UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
            if ( actionFile )
            {
              v69 = v5->objectValue;
              if ( v69 )
                v70 = v69->id;
              else
                v70 = -1;
              fprintf(actionFile, aDCallStopobjec, v70, aCMsdevWorkA_48, 1219);
            }
LABEL_154:
            ((void (__thiscall *)(TribeCivilianUnitAIModule *, signed int, int))v34->stopObject)(v5, 1, v74);
            goto LABEL_155;
          }
          UnitAIModule::addToWaypointQueue((UnitAIModule *)&v5->vfptr, tileX, uTime);
          if ( v34->explore((UnitAIModule *)v5, tileX, uTime, 1) )
            return 3;
          UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
          if ( actionFile )
          {
            v67 = v5->objectValue;
            if ( v67 )
              v68 = v67->id;
            else
              v68 = -1;
            fprintf(actionFile, aDCallStopobjec, v68, aCMsdevWorkA_48, 1204);
          }
LABEL_147:
          v34->stopObject((UnitAIModule *)v5, 1);
LABEL_155:
          ((void (__thiscall *)(TribeCivilianUnitAIModule *))v34->notifyCommander)(v5);
          goto LABEL_156;
        }
        v62 = this->vfptr;
        v63 = this->vfptr->closestObject;
        v64 = v63((UnitAIModule *)&this->vfptr, this->currentTargetTypeValue, 3, 0, -1, 0);
        if ( v64 == -1
          && (v5->currentTargetTypeValue != 27 ? (v65 = v63((UnitAIModule *)&v5->vfptr, 27, 3, 0, -1, 0)) : (v65 = v63((UnitAIModule *)&v5->vfptr, 3, 3, 0, -1, 0)),
              v64 = v65,
              v65 == -1)
          || (*((int (__stdcall **)(int, signed int, _DWORD, _DWORD, signed int, signed int))&v5->objectValue->vfptr->pause
              + 1))(
               v64,
               1065353216,
               0,
               0,
               -1,
               -1) != 1 )
        {
          v66 = UnitAIModule::lookupObject((UnitAIModule *)&v5->vfptr, v5->currentTargetValue);
          if ( !v66 || RGE_Static_Object::distance_to_object(v5->objectValue, v66) > 1.0 )
            (*(void (__thiscall **)(TribeCivilianUnitAIModule *, _DWORD, _DWORD, _DWORD, signed int, signed int))&v62->gap90[0])(
              v5,
              LODWORD(v5->currentTargetXValue),
              LODWORD(v5->currentTargetYValue),
              LODWORD(v5->currentTargetZValue),
              1065353216,
              1);
        }
        else if ( v62->buildObject((UnitAIModule *)v5, v64, 1) == 1 )
        {
          return 3;
        }
      }
LABEL_156:
      v4 = nEvent;
      if ( nEvent->mType != 514 )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
        if ( actionFile )
        {
          v71 = v5->objectValue;
          if ( v71 )
            v72 = v71->id;
          else
            v72 = -1;
          fprintf(actionFile, aDCallStopobjec, v72, aCMsdevWorkA_48, 1228);
        }
LABEL_162:
        v73 = v5->vfptr;
        v5->vfptr->stopObject((UnitAIModule *)v5, 1);
        ((void (__thiscall *)(TribeCivilianUnitAIModule *, NotifyEvent *))v73->notifyCommander)(v5, v4);
      }
      return 2;
    default:
      return UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v74, v75, v76);
  }
}

//----- (00505800) --------------------------------------------------------
int __stdcall TribeCivilianUnitAIModule::processIdle(int doSearch)
{
  return 5;
}

//----- (00505810) --------------------------------------------------------
int TribeCivilianUnitAIModule::processMisc()
{
  return 9;
}

//----- (00505820) --------------------------------------------------------
void __thiscall TribePriestUnitAIModule::TribePriestUnitAIModule(TribePriestUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribePriestUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribePriestUnitAIModule::`vftable';
  v3->numberImportantObjects = 17;
  v4 = (int *)operator new(0x44u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 3;
    v3->importantObjects[1] = 0;
    v3->importantObjects[2] = 4;
    v3->importantObjects[3] = 26;
    v3->importantObjects[4] = 24;
    v3->importantObjects[5] = 6;
    v3->importantObjects[6] = 25;
    v3->importantObjects[7] = 17;
    v3->importantObjects[8] = 10;
    v3->importantObjects[9] = 12;
    v3->importantObjects[10] = 35;
    v3->importantObjects[11] = 23;
    v3->importantObjects[12] = 36;
    v3->importantObjects[13] = 28;
    v3->importantObjects[14] = 18;
    v3->importantObjects[15] = 13;
    v3->importantObjects[16] = 39;
  }
}
// 575E28: using guessed type int (__thiscall *TribePriestUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00505970) --------------------------------------------------------
TribePriestUnitAIModule *__thiscall TribePriestUnitAIModule::`scalar deleting destructor'(TribePriestUnitAIModule *this, unsigned int __flags)
{
  TribePriestUnitAIModule *v2; // esi@1

  v2 = this;
  TribePriestUnitAIModule::~TribePriestUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (005059A0) --------------------------------------------------------
int __userpurge TribePriestUnitAIModule::attackObject@<eax>(TribePriestUnitAIModule *this@<ecx>, double a2@<st0>, int targetID, int unconditional)
{
  TribePriestUnitAIModule *v4; // esi@1
  UnitAIModuleVtbl *v5; // edi@1
  float v6; // ST08_4@4
  int result; // eax@4

  v4 = this;
  v5 = this->vfptr;
  if ( ((int (__stdcall *)(int))this->vfptr->canConvert)(targetID) )
  {
    result = v5->convertObject((UnitAIModule *)v4, targetID, unconditional);
  }
  else if ( v4->currentOrderValue == -1 && RGE_Player::computerPlayer(v4->objectValue->owner) )
  {
    ((void (__stdcall *)(int))v4->objectValue->vfptr->weaponRange)(unconditional);
    v6 = a2;
    result = (*(int (__thiscall **)(TribePriestUnitAIModule *, int, _DWORD))&v5->gap90[4])(v4, targetID, LODWORD(v6));
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00505A10) --------------------------------------------------------
BOOL __stdcall TribePriestUnitAIModule::retryableOrder(int orderType)
{
  return orderType == 704 || orderType == 703;
}

//----- (00505A30) --------------------------------------------------------
int __thiscall TribePriestUnitAIModule::canConvert(TribePriestUnitAIModule *this, int targetID)
{
  TribePriestUnitAIModule *v2; // esi@1
  RGE_Static_Object *v3; // ecx@1
  RGE_Static_Object *v4; // eax@2
  RGE_Master_Static_Object *v5; // eax@3
  int v6; // ecx@3
  __int16 v7; // ax@3
  int result; // eax@14

  v2 = this;
  v3 = this->objectValue;
  result = v3->attribute_amount_held >= 100.0
        && (v4 = RGE_Game_World::object(v3->owner->world, targetID)) != 0
        && (v5 = v4->master_obj, v6 = v5->object_group, v7 = v5->id, v7 != 109)
        && v6 != 27
        && v7 != 159
        && v7 != 276
        && v7 != 158
        && v7 != 163
        && v6 != 30
        && (v6 != 18 || v2->objectValue->owner->attributes[27] > 0.0)
        && (v6 != 3 || v2->objectValue->owner->attributes[28] > 0.0);
  return result;
}

//----- (00505AE0) --------------------------------------------------------
int __thiscall TribePriestUnitAIModule::canAttackUnit(TribePriestUnitAIModule *this, RGE_Static_Object *unit)
{
  int result; // eax@2

  if ( unit )
    result = ((int (__stdcall *)(int))this->vfptr->canConvert)(unit->id);
  else
    result = 0;
  return result;
}

//----- (00505B00) --------------------------------------------------------
int __thiscall TribePriestUnitAIModule::bestUnitToHeal(TribePriestUnitAIModule *this, int idleHeal, float *allyDistance)
{
  TribePriestUnitAIModule *v3; // ebp@1
  int result; // eax@1
  int v5; // edx@4
  int v6; // ecx@5
  char *v7; // esi@6
  int v8; // ebx@7
  RGE_Static_Object *v9; // eax@8
  RGE_Static_Object *v10; // edi@8
  RGE_Master_Static_Object *v11; // eax@9
  RGE_Static_Object *v12; // ecx@14
  double v13; // st7@17
  double v14; // st6@17
  bool v15; // zf@24
  bool v16; // sf@24
  unsigned __int8 v17; // of@24
  int allyToHealID; // [sp+18h] [bp-1Ch]@1
  int maxLimit; // [sp+1Ch] [bp-18h]@1
  float allyNeed; // [sp+20h] [bp-14h]@1
  int i; // [sp+24h] [bp-10h]@5
  int a; // [sp+28h] [bp-Ch]@3
  int v23; // [sp+2Ch] [bp-8h]@4

  v3 = this;
  ((void (*)(void))this->vfptr->search)();
  result = -1;
  allyToHealID = -1;
  allyNeed = 0.0;
  maxLimit = 2;
  if ( !v3->objectValue->owner->id )
    maxLimit = 4;
  a = 1;
  if ( maxLimit < 1 )
  {
LABEL_25:
    result = -1;
  }
  else
  {
    v5 = 0;
    v23 = 0;
    while ( 1 )
    {
      v6 = 0;
      i = 0;
      if ( *(int *)((char *)&dword_87D7CC + v5) > 0 )
      {
        v7 = (char *)&dword_87D7E4 + v5;
        do
        {
          v8 = 8 * v6;
          if ( *(_DWORD *)(8 * v6 + *(_DWORD *)v7) != v3->objectValue->id )
          {
            v9 = UnitAIModule::lookupObject((UnitAIModule *)&v3->vfptr, *(_DWORD *)(v8 + *(_DWORD *)v7));
            v10 = v9;
            if ( v9 )
            {
              v11 = v9->master_obj;
              if ( v11->object_group != 3
                && (double)v11->hp > v10->hp
                && v10->object_state < 3u
                && (idleHeal || *(_BYTE *)(v8 + *(_DWORD *)v7 + 4) <= 4u) )
              {
                v12 = v3->objectValue;
                if ( v12->owner->id || *(_BYTE *)(v8 + *(_DWORD *)v7 + 4) <= 2u )
                {
                  if ( (*((int (__stdcall **)(_DWORD, signed int, _DWORD, _DWORD, signed int, signed int))&v12->vfptr->pause
                        + 1))(
                         *(_DWORD *)(v8 + *(_DWORD *)v7),
                         1065353216,
                         0,
                         0,
                         -1,
                         -1) )
                  {
                    v13 = (double)*(_BYTE *)(v8 + *(_DWORD *)v7 + 4);
                    v14 = (double)v10->master_obj->hp - v10->hp / v13;
                    if ( allyToHealID == -1 || v14 < allyNeed )
                    {
                      allyNeed = v14;
                      allyToHealID = v10->id;
                      if ( allyDistance )
                        *allyDistance = v13;
                    }
                  }
                }
              }
            }
          }
          v5 = v23;
          v6 = i + 1;
          i = v6;
        }
        while ( v6 < *(int *)((char *)&dword_87D7CC + v23) );
        result = allyToHealID;
      }
      if ( result != -1 )
        break;
      v5 += 4;
      v17 = __OFSUB__(a + 1, maxLimit);
      v15 = a + 1 == maxLimit;
      v16 = a++ + 1 - maxLimit < 0;
      v23 = v5;
      if ( !((unsigned __int8)(v16 ^ v17) | v15) )
        goto LABEL_25;
    }
  }
  return result;
}
// 87D7CC: using guessed type int dword_87D7CC;
// 87D7E4: using guessed type int dword_87D7E4;

//----- (00505CC0) --------------------------------------------------------
int __thiscall TribePriestUnitAIModule::bestUnitToConvert(TribePriestUnitAIModule *this, float *distance)
{
  TribePriestUnitAIModule *v2; // edi@1
  signed int v3; // ebp@1
  int v4; // eax@1
  int v5; // ebx@2
  RGE_Static_Object *v6; // eax@3
  RGE_Static_Object *v7; // esi@3
  double v8; // st7@6
  double v9; // st6@8
  float targetValue; // [sp+8h] [bp-Ch]@1
  int i; // [sp+Ch] [bp-8h]@1

  v2 = this;
  ((void (*)(void))this->vfptr->search)();
  v3 = -1;
  v4 = 0;
  targetValue = 0.0;
  for ( i = 0; i < dword_87D7D8[0]; ++i )
  {
    v5 = 8 * v4;
    if ( (*(int (__stdcall **)(_DWORD))&v2->objectValue->owner->vfptr->gap4[20])(*(_BYTE *)(dword_87D7F0[0] + 8 * v4 + 5)) )
    {
      v6 = UnitAIModule::lookupObject((UnitAIModule *)&v2->vfptr, *(_DWORD *)(dword_87D7F0[0] + v5));
      v7 = v6;
      if ( v6 )
      {
        if ( v6->object_state < 3u && v2->vfptr->canConvert((UnitAIModule *)v2, v6->id) )
        {
          v8 = (double)*(_BYTE *)(dword_87D7F0[0] + v5 + 4);
          if ( v8 < 1.0 )
            v8 = 1.0;
          v9 = (double)v7->master_obj->hp / v8;
          if ( v3 == -1 || v9 > targetValue )
          {
            v3 = v7->id;
            targetValue = v9;
            if ( distance )
              *distance = v8;
          }
        }
      }
    }
    v4 = i + 1;
  }
  return v3;
}
// 87D7D8: using guessed type int dword_87D7D8[];
// 87D7F0: using guessed type int dword_87D7F0[];

//----- (00505DD0) --------------------------------------------------------
int __userpurge TribePriestUnitAIModule::processNotify@<eax>(TribePriestUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribePriestUnitAIModule *v4; // esi@1
  RGE_Static_Object *v5; // eax@5
  signed int v6; // eax@6
  UnitAIModuleVtbl *v7; // edi@9
  int v8; // eax@10
  UnitAIModuleVtbl *v9; // edi@11
  int v10; // eax@11
  int result; // eax@13
  UnitAIModuleVtbl *v12; // edi@15
  int v13; // eax@15
  RGE_Static_Object *v14; // eax@19
  signed int v15; // eax@20
  RGE_Static_Object *v16; // eax@25
  RGE_Static_Object *v17; // eax@29
  signed int v18; // eax@30
  UnitAIModuleVtbl *v19; // edi@33
  int v20; // [sp+0h] [bp-Ch]@0
  int v21; // [sp+4h] [bp-8h]@0
  _DWORD *v22; // [sp+8h] [bp-4h]@0

  v4 = this;
  switch ( nEvent->mType )
  {
    case 0x1F9:
    case 0x1FB:
    case 0x202:
      if ( RGE_Player::computerPlayer(this->objectValue->owner) || v4->currentActionValue != 604 )
      {
        v8 = v4->currentActionValue;
        if ( v8 == 604 )
        {
          v9 = v4->vfptr;
          v10 = (*(int (__thiscall **)(TribePriestUnitAIModule *, _DWORD))&v4->vfptr[1].gap4[0])(v4, 0);
          if ( v10 != -1 && v9->convertObject((UnitAIModule *)v4, v10, 1) == 1 )
            return 3;
        }
        else if ( v8 == 603 )
        {
          v12 = v4->vfptr;
          v13 = ((int (__thiscall *)(TribePriestUnitAIModule *, _DWORD, _DWORD))v4->vfptr[1].__vecDelDtor)(v4, 0, 0);
          if ( v13 != -1 && v12->healObject((UnitAIModule *)v4, v13, 1) == 1 )
            return 3;
        }
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v4->vfptr);
        if ( actionFile )
        {
          v14 = v4->objectValue;
          if ( v14 )
            v15 = v14->id;
          else
            v15 = -1;
          fprintf(actionFile, aDCallStopobjec, v15, aCMsdevWorkA_48, 1653);
        }
        v7 = v4->vfptr;
        v4->vfptr->stopObject((UnitAIModule *)v4, 0);
      }
      else
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v4->vfptr);
        if ( actionFile )
        {
          v5 = v4->objectValue;
          if ( v5 )
            v6 = v5->id;
          else
            v6 = -1;
          fprintf(actionFile, aDCallStopobjec, v6, aCMsdevWorkA_48, 1595);
        }
        v7 = v4->vfptr;
        v4->vfptr->stopObject((UnitAIModule *)v4, 1);
      }
      ((void (__thiscall *)(TribePriestUnitAIModule *, NotifyEvent *))v7->notifyCommander)(v4, nEvent);
      result = 2;
      break;
    case 0x1FC:
      v16 = UnitAIModule::lookupObject((UnitAIModule *)&this->vfptr, this->currentTargetValue);
      if ( !v16
        || (a2 = v16->world_x,
            UnitAIModule::visibleStatus(
              (UnitAIModule *)&v4->vfptr,
              v4->objectValue->owner->visible,
              (signed __int64)a2,
              (signed __int64)v16->world_y) != 15) )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v4->vfptr);
        if ( actionFile )
        {
          v17 = v4->objectValue;
          if ( v17 )
            v18 = v17->id;
          else
            v18 = -1;
          fprintf(actionFile, aDCallStopobjec, v18, aCMsdevWorkA_48, 1679);
        }
        v19 = v4->vfptr;
        v4->vfptr->stopObject((UnitAIModule *)v4, 1);
        ((void (__thiscall *)(TribePriestUnitAIModule *, NotifyEvent *))v19->notifyCommander)(v4, nEvent);
        goto LABEL_34;
      }
      result = 2;
      break;
    default:
LABEL_34:
      result = UnitAIModule::processNotify((UnitAIModule *)&v4->vfptr, a2, nEvent, uTime, v20, v21, v22);
      break;
  }
  return result;
}

//----- (00505FD0) --------------------------------------------------------
int __thiscall TribePriestUnitAIModule::processIdle(TribePriestUnitAIModule *this, int doSearch)
{
  TribePriestUnitAIModule *v2; // esi@1
  int result; // eax@2
  int v4; // edi@3
  int v5; // edx@3
  UnitAIModuleVtbl *v6; // edi@5
  int v7; // eax@5
  UnitAIModuleVtbl *v8; // edi@7
  int v9; // eax@7
  RGE_Static_Object *v10; // eax@8
  RGE_Static_Object *v11; // ecx@9
  double v12; // st6@9
  double v13; // st7@9
  RGE_Static_ObjectVtbl *v14; // edx@9
  long double v15; // st7@9
  long double v16; // st7@9
  RGE_Static_Object *v17; // eax@11
  float v18; // ST18_4@11
  float v19; // ST14_4@11
  float yDiff; // [sp+2Ch] [bp-Ch]@9
  float xDiff; // [sp+30h] [bp-8h]@9
  float distanceDiff; // [sp+34h] [bp-4h]@5

  v2 = this;
  if ( !RGE_Player::computerPlayer(this->objectValue->owner) )
    goto LABEL_15;
  result = UnitAIModule::processIdle((UnitAIModule *)&v2->vfptr, 1);
  if ( result == 6 )
    return result;
  v4 = dword_87D7D8[0];
  v5 = debug_rand(aCMsdevWorkA_48, 1708) % (v4 + 2);
  if ( v4 > 0 && v5 > v4 )
  {
    v6 = v2->vfptr;
    v7 = ((int (__thiscall *)(TribePriestUnitAIModule *, signed int, float *))v2->vfptr[1].__vecDelDtor)(
           v2,
           1,
           &distanceDiff);
    if ( v7 != -1 )
    {
      v6->healObject((UnitAIModule *)v2, v7, 0);
      return 6;
    }
  }
  v8 = v2->vfptr;
  v9 = ((int (__fastcall *)(TribePriestUnitAIModule *, int, signed int, signed int, signed int, signed int, _DWORD))v2->vfptr->closestObject)(
         v2,
         v5,
         -1,
         2,
         -1,
         -1,
         0);
  if ( v9 != -1 && (v10 = RGE_Game_World::object(v2->objectValue->owner->world, v9)) != 0 )
  {
    v11 = v2->objectValue;
    v12 = v10->world_x - v11->world_x;
    v13 = v10->world_y - v11->world_y;
    v14 = v11->vfptr;
    xDiff = v12;
    yDiff = v13;
    v15 = sqrt(v12 * xDiff + v13 * yDiff);
    distanceDiff = v15;
    ((void (*)(void))v14->weaponRange)();
    v16 = v15 - distanceDiff;
    if ( v16 > 0.0 )
    {
      v17 = v2->objectValue;
      v18 = v17->world_y - yDiff / distanceDiff * v16;
      v19 = v17->world_x - xDiff / distanceDiff * v16;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v8->evasiveMoveTo)(
        LODWORD(v19),
        LODWORD(v18),
        LODWORD(v17->world_z),
        1);
      result = 6;
    }
    else
    {
      result = 5;
    }
  }
  else
  {
LABEL_15:
    result = 5;
  }
  return result;
}
// 87D7D8: using guessed type int dword_87D7D8[];

//----- (00506140) --------------------------------------------------------
int __thiscall TribePriestUnitAIModule::processMisc(TribePriestUnitAIModule *this)
{
  TribePriestUnitAIModule *v1; // esi@1
  RGE_Static_Object *v2; // edi@2
  UnitAIModuleVtbl *v3; // edi@5
  int v4; // eax@5
  int v5; // ebx@5
  int v6; // ecx@6
  int v7; // eax@7
  RGE_Static_Object *v8; // eax@9
  signed int v9; // eax@10
  bool v10; // zf@14
  int result; // eax@14

  v1 = this;
  if ( RGE_Player::computerPlayer(this->objectValue->owner) != 1 )
    goto LABEL_18;
  v2 = v1->objectValue;
  if ( v2->attribute_amount_held < 100.0
    || RGE_Action_List::have_action((RGE_Action_List *)v2[2].unitAIValue) == 1
    && RGE_Action_List::get_action((RGE_Action_List *)v2[2].unitAIValue)->state == 7 )
  {
    goto LABEL_18;
  }
  v3 = v1->vfptr;
  v4 = v1->vfptr->bestUnitToAttack((UnitAIModule *)v1, 1, 1, 0);
  v5 = v4;
  if ( v4 == -1 )
    goto LABEL_18;
  v6 = v1->currentTargetValue;
  if ( v6 == v4 )
    goto LABEL_18;
  v7 = v1->currentOrderValue;
  if ( v7 != -1 )
  {
    (*(void (__thiscall **)(TribePriestUnitAIModule *, int, int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))&v3->gap4[12])(
      v1,
      v1->objectValue->id,
      v7,
      v6,
      -1,
      LODWORD(v1->currentTargetXValue),
      LODWORD(v1->currentTargetYValue),
      LODWORD(v1->currentTargetZValue),
      LODWORD(v1->desiredTargetDistanceValue),
      0,
      0,
      v1->currentOrderPriorityValue);
    if ( actionFile )
    {
      v8 = v1->objectValue;
      if ( v8 )
        v9 = v8->id;
      else
        v9 = -1;
      fprintf(actionFile, aDCallStopobjec, v9, aCMsdevWorkA_48, 1784);
    }
    v3->stopObject((UnitAIModule *)v1, 1);
  }
  v10 = v3->attackObject((UnitAIModule *)v1, v5, 1) == 1;
  result = 10;
  if ( !v10 )
LABEL_18:
    result = 9;
  return result;
}

//----- (00506240) --------------------------------------------------------
void __thiscall TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(TribeTradeShipUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeTradeShipUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeTradeShipUnitAIModule::`vftable';
  v3->numberImportantObjects = 5;
  v4 = (int *)operator new(0x14u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 3;
    v3->importantObjects[1] = 22;
    v3->importantObjects[2] = 20;
    v3->importantObjects[3] = 2;
    v3->importantObjects[4] = 21;
  }
}
// 575F10: using guessed type int (__thiscall *TribeTradeShipUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (005062F0) --------------------------------------------------------
TribeTradeShipUnitAIModule *__thiscall TribeTradeShipUnitAIModule::`vector deleting destructor'(TribeTradeShipUnitAIModule *this, unsigned int __flags)
{
  TribeTradeShipUnitAIModule *v2; // esi@1

  v2 = this;
  TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00506320) --------------------------------------------------------
int __userpurge TribeTradeShipUnitAIModule::processNotify@<eax>(TribeTradeShipUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  NotifyEvent *v4; // ebp@1
  TribeTradeShipUnitAIModule *v5; // esi@1
  int result; // eax@4
  int v7; // eax@5
  UnitAIModuleVtbl *v8; // ebx@6
  int (__thiscall *v9)(UnitAIModule *, int, int, int, int, int *); // edi@6
  int v10; // eax@6
  int v11; // eax@9
  UnitAIModuleVtbl *v12; // edi@13
  RGE_Static_Object *v13; // eax@16
  RGE_Static_Object *v14; // eax@20
  signed int v15; // eax@21
  RGE_Static_Object *v16; // eax@26
  signed int v17; // eax@27
  UnitAIModuleVtbl *v18; // edi@30
  int v19; // ecx@36
  int i; // eax@36
  int v21; // ecx@43
  int v22; // ebp@43
  int j; // eax@43
  int v24; // ebx@48
  int *v25; // edi@48
  int k; // eax@49
  UnitAIModuleVtbl *v27; // edi@58
  RGE_Static_Object *v28; // eax@59
  signed int v29; // eax@60
  int v30; // [sp+0h] [bp-10h]@0
  int v31; // [sp+4h] [bp-Ch]@0
  _DWORD *v32; // [sp+8h] [bp-8h]@0

  v4 = nEvent;
  v5 = this;
  if ( nEvent->mType != 500 )
  {
    if ( nEvent->mType != 514 )
    {
      if ( nEvent->mType != 527 )
        return UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v30, v31, v32);
      goto LABEL_31;
    }
    v7 = this->currentActionValue;
    if ( v7 == 615 )
    {
      v8 = this->vfptr;
      v9 = this->vfptr->closestObject;
      v10 = ((int (__stdcall *)(signed int, _DWORD, signed int, signed int, _DWORD))v9)(-1, 0, 2, 45, 0);
      if ( v10 != -1 && v8->tradeWithObject((UnitAIModule *)v5, v10, 1) == 1 )
        return 6;
      v11 = v9((UnitAIModule *)&v5->vfptr, -1, 1, 2, 45, 0);
      if ( v11 != -1 && v8->tradeWithObject((UnitAIModule *)v5, v11, 1) == 1 )
        return 6;
      goto LABEL_25;
    }
    if ( v7 == 605 )
    {
      v12 = this->vfptr;
      if ( ((int (__stdcall *)(NotifyEvent **, unsigned int *, signed int))this->vfptr->closestUndiscoveredTile)(
             &nEvent,
             &uTime,
             1) != 1 )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
        if ( actionFile )
        {
          v14 = v5->objectValue;
          if ( v14 )
            v15 = v14->id;
          else
            v15 = -1;
          fprintf(actionFile, aDCallStopobjec, v15, aCMsdevWorkA_48, 1960);
        }
        goto LABEL_24;
      }
      UnitAIModule::addToWaypointQueue((UnitAIModule *)&v5->vfptr, (int)nEvent, uTime);
      if ( !v12->explore((UnitAIModule *)v5, (int)nEvent, uTime, 1) )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
        if ( actionFile )
        {
          v13 = v5->objectValue;
          if ( v13 )
            fprintf(actionFile, aDCallStopobjec, v13->id, aCMsdevWorkA_48, 1948);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 1948);
        }
LABEL_24:
        v12->stopObject((UnitAIModule *)v5, 1);
        ((void (__thiscall *)(TribeTradeShipUnitAIModule *, NotifyEvent *))v12->notifyCommander)(v5, v4);
        goto LABEL_25;
      }
    }
LABEL_25:
    UnitAIModule::removeCurrentTarget((UnitAIModule *)&v5->vfptr);
    if ( actionFile )
    {
      v16 = v5->objectValue;
      if ( v16 )
        v17 = v16->id;
      else
        v17 = -1;
      fprintf(actionFile, aDCallStopobjec, v17, aCMsdevWorkA_48, 1968);
    }
    v18 = v5->vfptr;
    v5->vfptr->stopObject((UnitAIModule *)v5, 1);
    ((void (__thiscall *)(TribeTradeShipUnitAIModule *, NotifyEvent *))v18->notifyCommander)(v5, v4);
    return 2;
  }
LABEL_31:
  if ( nEvent->p2 > 0 )
  {
    if ( !this->attackingUnitsValue.numberValue || RGE_Player::computerPlayer(this->objectValue->owner) == 1 )
      ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v5->objectValue->owner->vfptr->notify)(
        v5->objectValue->id,
        v5->objectValue->id,
        513,
        v4->caller,
        0,
        0);
    v19 = v5->attackingUnitsValue.numberValue;
    for ( i = 0; i < v19; ++i )
    {
      if ( i >= v5->attackingUnitsValue.maximumSizeValue )
        break;
      if ( v5->attackingUnitsValue.value[i] == v4->caller )
        goto LABEL_43;
    }
    if ( !RGE_Player::computerPlayer(v5->objectValue->owner) && v5->currentTargetValue != v4->caller )
      UnitAIModule::askForHelp((UnitAIModule *)&v5->vfptr, v4->caller, v30, v31, (int)v32);
LABEL_43:
    v21 = v5->attackingUnitsValue.numberValue;
    v22 = v4->caller;
    for ( j = 0; j < v21; ++j )
    {
      if ( j >= v5->attackingUnitsValue.maximumSizeValue )
        break;
      if ( v5->attackingUnitsValue.value[j] == v22 )
        goto LABEL_54;
    }
    if ( v21 > v5->attackingUnitsValue.maximumSizeValue - 1 )
    {
      v24 = v21 + 1;
      v25 = (int *)operator new(4 * (v21 + 1));
      if ( v25 )
      {
        for ( k = 0; k < v5->attackingUnitsValue.maximumSizeValue; v25[k - 1] = v5->attackingUnitsValue.value[k - 1] )
        {
          if ( k >= v24 )
            break;
          ++k;
        }
        operator delete(v5->attackingUnitsValue.value);
        v5->attackingUnitsValue.value = v25;
        v5->attackingUnitsValue.maximumSizeValue = v24;
      }
    }
    v5->attackingUnitsValue.value[v5->attackingUnitsValue.numberValue++] = v22;
LABEL_54:
    ((void (__stdcall *)(signed int))v5->objectValue->vfptr->setUnderAttack)(1);
    if ( RGE_Player::computerPlayer(v5->objectValue->owner) || v5->currentOrderValue == -1 )
    {
      if ( v5->currentActionValue != 610 )
      {
        v27 = v5->vfptr;
        (*(void (__thiscall **)(TribeTradeShipUnitAIModule *, int, int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))&v5->vfptr->gap4[12])(
          v5,
          v5->objectValue->id,
          v5->currentOrderValue,
          v5->currentTargetValue,
          -1,
          LODWORD(v5->currentTargetXValue),
          LODWORD(v5->currentTargetYValue),
          LODWORD(v5->currentTargetZValue),
          LODWORD(v5->desiredTargetDistanceValue),
          0,
          0,
          v5->currentOrderPriorityValue);
        if ( actionFile )
        {
          v28 = v5->objectValue;
          if ( v28 )
            v29 = v28->id;
          else
            v29 = -1;
          fprintf(actionFile, aDCallStopobjec, v29, aCMsdevWorkA_48, 1889);
        }
        v27->stopObject((UnitAIModule *)v5, 1);
      }
      v5->vfptr->runAwayFromAttackers((UnitAIModule *)v5, 1);
      result = 3;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))this->objectValue->owner->vfptr->notify)(
      this->objectValue->id,
      this->objectValue->id,
      521,
      nEvent->caller,
      0,
      0);
    UnitAIModule::purgeNotifyQueue((UnitAIModule *)&v5->vfptr, uTime);
    result = 4;
  }
  return result;
}

//----- (005066D0) --------------------------------------------------------
int __userpurge TribeTradeShipUnitAIModule::processIdle@<eax>(TribeTradeShipUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch)
{
  TribeTradeShipUnitAIModule *v3; // esi@1
  UnitAIModuleVtbl *v4; // ebx@2
  int v5; // eax@2
  RGE_Static_Object *v6; // edi@3
  RGE_Static_Object *v7; // eax@4
  double v8; // rt1@4
  double v9; // st5@4
  double v10; // st6@4
  float xDiff; // ST34_4@4
  float yDiff; // ST30_4@4
  double v13; // st7@4
  double v14; // st4@4
  double v15; // st3@4
  double v16; // st6@4
  float v17; // ST30_4@4
  float v18; // ST34_4@4
  float v19; // ST18_4@4
  float v20; // ST14_4@4
  int result; // eax@4

  v3 = this;
  if ( RGE_Player::computerPlayer(this->objectValue->owner)
    && (v4 = v3->vfptr, v5 = v3->vfptr->closestObject((UnitAIModule *)v3, -1, -1, -1, -1, 0), v5 != -1)
    && (v6 = RGE_Game_World::object(v3->objectValue->owner->world, v5)) != 0 )
  {
    ((void (*)(void))v3->objectValue->vfptr->maximumSpeed)();
    v7 = v3->objectValue;
    v8 = v6->world_y - v7->world_y;
    v9 = v6->world_x - v7->world_x;
    v10 = a2 * 7.0;
    xDiff = v9;
    yDiff = v8;
    v13 = yDiff;
    v14 = v8 * yDiff;
    v15 = v10;
    v16 = xDiff;
    v17 = v15;
    v18 = sqrt(v9 * xDiff + v14);
    v19 = v7->world_y - v13 / v18 * v17;
    v20 = v7->world_x - v16 / v18 * v17;
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v4->evasiveMoveTo)(
      LODWORD(v20),
      LODWORD(v19),
      LODWORD(v7->world_z),
      1);
    result = 6;
  }
  else
  {
    result = 5;
  }
  return result;
}

//----- (005067D0) --------------------------------------------------------
void __thiscall TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(TribeTransportShipUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeTransportShipUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeTransportShipUnitAIModule::`vftable';
  v3->numberImportantObjects = 5;
  v4 = (int *)operator new(0x14u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 3;
    v3->importantObjects[1] = 22;
    v3->importantObjects[2] = 20;
    v3->importantObjects[3] = 2;
    v3->importantObjects[4] = 21;
  }
}
// 575FF0: using guessed type int (__thiscall *TribeTransportShipUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00506880) --------------------------------------------------------
TribeTransportShipUnitAIModule *__thiscall TribeTransportShipUnitAIModule::`scalar deleting destructor'(TribeTransportShipUnitAIModule *this, unsigned int __flags)
{
  TribeTransportShipUnitAIModule *v2; // esi@1

  v2 = this;
  TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (005068B0) --------------------------------------------------------
int __userpurge TribeTransportShipUnitAIModule::processNotify@<eax>(TribeTransportShipUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeTransportShipUnitAIModule *v4; // esi@1
  int result; // eax@3
  int v6; // ecx@9
  int i; // eax@9
  int v8; // ecx@16
  int v9; // edi@16
  int j; // eax@16
  int v11; // ebp@21
  int *v12; // ebx@21
  int k; // eax@22
  RGE_Static_Object *v14; // edi@29
  int v15; // [sp+0h] [bp-10h]@0
  int v16; // [sp+4h] [bp-Ch]@0
  _DWORD *v17; // [sp+8h] [bp-8h]@0

  v4 = this;
  if ( nEvent->mType == 500 || nEvent->mType == 527 )
  {
    if ( nEvent->p2 > 0 )
    {
      if ( !this->attackingUnitsValue.numberValue || RGE_Player::computerPlayer(this->objectValue->owner) == 1 )
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v4->objectValue->owner->vfptr->notify)(
          v4->objectValue->id,
          v4->objectValue->id,
          513,
          nEvent->caller,
          0,
          0);
      v6 = v4->attackingUnitsValue.numberValue;
      for ( i = 0; i < v6; ++i )
      {
        if ( i >= v4->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v4->attackingUnitsValue.value[i] == nEvent->caller )
          goto LABEL_16;
      }
      if ( !RGE_Player::computerPlayer(v4->objectValue->owner) && v4->currentTargetValue != nEvent->caller )
        UnitAIModule::askForHelp((UnitAIModule *)&v4->vfptr, nEvent->caller, v15, v16, (int)v17);
LABEL_16:
      v8 = v4->attackingUnitsValue.numberValue;
      v9 = nEvent->caller;
      for ( j = 0; j < v8; ++j )
      {
        if ( j >= v4->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v4->attackingUnitsValue.value[j] == v9 )
          goto LABEL_27;
      }
      if ( v8 > v4->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v11 = v8 + 1;
        v12 = (int *)operator new(4 * (v8 + 1));
        if ( v12 )
        {
          for ( k = 0; k < v4->attackingUnitsValue.maximumSizeValue; v12[k - 1] = v4->attackingUnitsValue.value[k - 1] )
          {
            if ( k >= v11 )
              break;
            ++k;
          }
          operator delete(v4->attackingUnitsValue.value);
          v4->attackingUnitsValue.value = v12;
          v4->attackingUnitsValue.maximumSizeValue = v11;
        }
      }
      v4->attackingUnitsValue.value[v4->attackingUnitsValue.numberValue++] = v9;
LABEL_27:
      ((void (__stdcall *)(signed int))v4->objectValue->vfptr->setUnderAttack)(1);
      if ( v4->currentOrderValue == -1 )
      {
        v14 = v4->objectValue;
        if ( !RGE_Action_List::have_action((RGE_Action_List *)v14[2].unitAIValue)
          || RGE_Action_List::get_action((RGE_Action_List *)v14[2].unitAIValue)->state == 2 )
        {
          v4->vfptr->runAwayFromAttackers((UnitAIModule *)v4, 1);
        }
        result = 3;
      }
      else
      {
        result = 2;
      }
    }
    else
    {
      ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))this->objectValue->owner->vfptr->notify)(
        this->objectValue->id,
        this->objectValue->id,
        521,
        nEvent->caller,
        0,
        0);
      UnitAIModule::purgeNotifyQueue((UnitAIModule *)&v4->vfptr, uTime);
      result = 4;
    }
  }
  else
  {
    result = UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v15, v16, v17);
  }
  return result;
}

//----- (00506A70) --------------------------------------------------------
int __userpurge TribeTransportShipUnitAIModule::processIdle@<eax>(TribeTransportShipUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch)
{
  TribeTransportShipUnitAIModule *v3; // esi@1
  UnitAIModuleVtbl *v4; // ebx@2
  int v5; // eax@2
  RGE_Static_Object *v6; // edi@3
  RGE_Static_Object *v7; // eax@4
  double v8; // rt1@4
  double v9; // st5@4
  double v10; // st6@4
  float xDiff; // ST34_4@4
  float yDiff; // ST30_4@4
  double v13; // st7@4
  double v14; // st4@4
  double v15; // st3@4
  double v16; // st6@4
  float v17; // ST30_4@4
  float v18; // ST34_4@4
  float v19; // ST18_4@4
  float v20; // ST14_4@4
  int result; // eax@4

  v3 = this;
  if ( RGE_Player::computerPlayer(this->objectValue->owner)
    && (v4 = v3->vfptr, v5 = v3->vfptr->closestObject((UnitAIModule *)v3, -1, -1, -1, -1, 0), v5 != -1)
    && (v6 = RGE_Game_World::object(v3->objectValue->owner->world, v5)) != 0 )
  {
    ((void (*)(void))v3->objectValue->vfptr->maximumSpeed)();
    v7 = v3->objectValue;
    v8 = v6->world_y - v7->world_y;
    v9 = v6->world_x - v7->world_x;
    v10 = a2 * 7.0;
    xDiff = v9;
    yDiff = v8;
    v13 = yDiff;
    v14 = v8 * yDiff;
    v15 = v10;
    v16 = xDiff;
    v17 = v15;
    v18 = sqrt(v9 * xDiff + v14);
    v19 = v7->world_y - v13 / v18 * v17;
    v20 = v7->world_x - v16 / v18 * v17;
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v4->evasiveMoveTo)(
      LODWORD(v20),
      LODWORD(v19),
      LODWORD(v7->world_z),
      1);
    result = 6;
  }
  else
  {
    result = 5;
  }
  return result;
}

//----- (00506B70) --------------------------------------------------------
void __thiscall TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(TribeFishingShipUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeFishingShipUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeFishingShipUnitAIModule::`vftable';
  v3->numberImportantObjects = 8;
  v4 = (int *)operator new(0x20u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 3;
    v3->importantObjects[1] = 22;
    v3->importantObjects[2] = 20;
    v3->importantObjects[3] = 2;
    v3->importantObjects[4] = 21;
    v3->importantObjects[5] = 5;
    v3->importantObjects[6] = 31;
    v3->importantObjects[7] = 33;
  }
}
// 5760D0: using guessed type int (__thiscall *TribeFishingShipUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00506C40) --------------------------------------------------------
TribeFishingShipUnitAIModule *__thiscall TribeFishingShipUnitAIModule::`scalar deleting destructor'(TribeFishingShipUnitAIModule *this, unsigned int __flags)
{
  TribeFishingShipUnitAIModule *v2; // esi@1

  v2 = this;
  TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00506C70) --------------------------------------------------------
BOOL __stdcall TribeFishingShipUnitAIModule::importantWhenDead(int objectType)
{
  return objectType == 31 || objectType == 5;
}

//----- (00506C90) --------------------------------------------------------
int __stdcall TribeFishingShipUnitAIModule::convertToLOSResourceType(int oType)
{
  int result; // eax@4

  if ( oType == 31 || oType == 5 || oType == 33 )
    result = 2;
  else
    result = -1;
  return result;
}

//----- (00506CC0) --------------------------------------------------------
int __userpurge TribeFishingShipUnitAIModule::processNotify@<eax>(TribeFishingShipUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeFishingShipUnitAIModule *v4; // esi@1
  int result; // eax@3
  int v6; // ecx@9
  int i; // eax@9
  int v8; // ecx@16
  int v9; // edi@16
  int j; // eax@16
  int v11; // ebp@21
  int *v12; // ebx@21
  int k; // eax@22
  UnitAIModuleVtbl *v14; // edi@31
  RGE_Static_Object *v15; // eax@32
  signed int v16; // eax@33
  int v17; // [sp+0h] [bp-10h]@0
  int v18; // [sp+4h] [bp-Ch]@0
  _DWORD *v19; // [sp+8h] [bp-8h]@0

  v4 = this;
  if ( nEvent->mType == 500 || nEvent->mType == 527 )
  {
    if ( nEvent->p2 > 0 )
    {
      if ( !this->attackingUnitsValue.numberValue || RGE_Player::computerPlayer(this->objectValue->owner) == 1 )
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v4->objectValue->owner->vfptr->notify)(
          v4->objectValue->id,
          v4->objectValue->id,
          513,
          nEvent->caller,
          0,
          0);
      v6 = v4->attackingUnitsValue.numberValue;
      for ( i = 0; i < v6; ++i )
      {
        if ( i >= v4->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v4->attackingUnitsValue.value[i] == nEvent->caller )
          goto LABEL_16;
      }
      if ( !RGE_Player::computerPlayer(v4->objectValue->owner) && v4->currentTargetValue != nEvent->caller )
        UnitAIModule::askForHelp((UnitAIModule *)&v4->vfptr, nEvent->caller, v17, v18, (int)v19);
LABEL_16:
      v8 = v4->attackingUnitsValue.numberValue;
      v9 = nEvent->caller;
      for ( j = 0; j < v8; ++j )
      {
        if ( j >= v4->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v4->attackingUnitsValue.value[j] == v9 )
          goto LABEL_27;
      }
      if ( v8 > v4->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v11 = v8 + 1;
        v12 = (int *)operator new(4 * (v8 + 1));
        if ( v12 )
        {
          for ( k = 0; k < v4->attackingUnitsValue.maximumSizeValue; v12[k - 1] = v4->attackingUnitsValue.value[k - 1] )
          {
            if ( k >= v11 )
              break;
            ++k;
          }
          operator delete(v4->attackingUnitsValue.value);
          v4->attackingUnitsValue.value = v12;
          v4->attackingUnitsValue.maximumSizeValue = v11;
        }
      }
      v4->attackingUnitsValue.value[v4->attackingUnitsValue.numberValue++] = v9;
LABEL_27:
      ((void (__stdcall *)(signed int))v4->objectValue->vfptr->setUnderAttack)(1);
      if ( RGE_Player::computerPlayer(v4->objectValue->owner) || v4->currentOrderValue == -1 )
      {
        if ( v4->currentActionValue != 610 )
        {
          v14 = v4->vfptr;
          (*(void (__thiscall **)(TribeFishingShipUnitAIModule *, int, int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))&v4->vfptr->gap4[12])(
            v4,
            v4->objectValue->id,
            v4->currentOrderValue,
            v4->currentTargetValue,
            -1,
            LODWORD(v4->currentTargetXValue),
            LODWORD(v4->currentTargetYValue),
            LODWORD(v4->currentTargetZValue),
            LODWORD(v4->desiredTargetDistanceValue),
            0,
            0,
            v4->currentOrderPriorityValue);
          if ( actionFile )
          {
            v15 = v4->objectValue;
            if ( v15 )
              v16 = v15->id;
            else
              v16 = -1;
            fprintf(actionFile, aDCallStopobjec, v16, aCMsdevWorkA_48, 2260);
          }
          v14->stopObject((UnitAIModule *)v4, 1);
        }
        v4->vfptr->runAwayFromAttackers((UnitAIModule *)v4, 1);
        result = 3;
      }
      else
      {
        result = 2;
      }
    }
    else
    {
      ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))this->objectValue->owner->vfptr->notify)(
        this->objectValue->id,
        this->objectValue->id,
        521,
        nEvent->caller,
        0,
        0);
      UnitAIModule::purgeNotifyQueue((UnitAIModule *)&v4->vfptr, uTime);
      result = 4;
    }
  }
  else
  {
    result = UnitAIModule::processNotify((UnitAIModule *)&this->vfptr, a2, nEvent, uTime, v17, v18, v19);
  }
  return result;
}

//----- (00506EE0) --------------------------------------------------------
int __userpurge TribeFishingShipUnitAIModule::processIdle@<eax>(TribeFishingShipUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch)
{
  TribeFishingShipUnitAIModule *v3; // esi@1
  UnitAIModuleVtbl *v4; // ebx@2
  int v5; // eax@2
  RGE_Static_Object *v6; // edi@3
  RGE_Static_Object *v7; // eax@4
  double v8; // rt1@4
  double v9; // st5@4
  double v10; // st6@4
  float xDiff; // ST34_4@4
  float yDiff; // ST30_4@4
  double v13; // st7@4
  double v14; // st4@4
  double v15; // st3@4
  double v16; // st6@4
  float v17; // ST30_4@4
  float v18; // ST34_4@4
  float v19; // ST18_4@4
  float v20; // ST14_4@4
  int result; // eax@4

  v3 = this;
  if ( RGE_Player::computerPlayer(this->objectValue->owner)
    && (v4 = v3->vfptr, v5 = v3->vfptr->closestObject((UnitAIModule *)v3, -1, -1, -1, -1, 0), v5 != -1)
    && (v6 = RGE_Game_World::object(v3->objectValue->owner->world, v5)) != 0 )
  {
    ((void (*)(void))v3->objectValue->vfptr->maximumSpeed)();
    v7 = v3->objectValue;
    v8 = v6->world_y - v7->world_y;
    v9 = v6->world_x - v7->world_x;
    v10 = a2 * 7.0;
    xDiff = v9;
    yDiff = v8;
    v13 = yDiff;
    v14 = v8 * yDiff;
    v15 = v10;
    v16 = xDiff;
    v17 = v15;
    v18 = sqrt(v9 * xDiff + v14);
    v19 = v7->world_y - v13 / v18 * v17;
    v20 = v7->world_x - v16 / v18 * v17;
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v4->evasiveMoveTo)(
      LODWORD(v20),
      LODWORD(v19),
      LODWORD(v7->world_z),
      1);
    result = 6;
  }
  else
  {
    result = 5;
  }
  return result;
}

//----- (00506FE0) --------------------------------------------------------
void __thiscall TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(TribeSoldierUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeSoldierUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeSoldierUnitAIModule::`vftable';
  v3->numberImportantObjects = 21;
  v4 = (int *)operator new(0x54u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 0;
    v3->importantObjects[1] = 3;
    v3->importantObjects[2] = 4;
    v3->importantObjects[3] = 26;
    v3->importantObjects[4] = 24;
    v3->importantObjects[5] = 6;
    v3->importantObjects[6] = 35;
    v3->importantObjects[7] = 25;
    v3->importantObjects[8] = 17;
    v3->importantObjects[9] = 12;
    v3->importantObjects[10] = 23;
    v3->importantObjects[11] = 36;
    v3->importantObjects[12] = 28;
    v3->importantObjects[13] = 18;
    v3->importantObjects[14] = 13;
    v3->importantObjects[15] = 27;
    v3->importantObjects[16] = 22;
    v3->importantObjects[17] = 20;
    v3->importantObjects[18] = 2;
    v3->importantObjects[19] = 21;
    v3->importantObjects[20] = 39;
  }
  v3->idleTimeoutValue = 1500;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)&v3->vfptr);
}
// 5761B0: using guessed type int (__thiscall *TribeSoldierUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00507170) --------------------------------------------------------
TribeSoldierUnitAIModule *__thiscall TribeSoldierUnitAIModule::`vector deleting destructor'(TribeSoldierUnitAIModule *this, unsigned int __flags)
{
  TribeSoldierUnitAIModule *v2; // esi@1

  v2 = this;
  TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (005071A0) --------------------------------------------------------
RGE_Static_Object *__stdcall TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object *unit)
{
  RGE_Static_Object *result; // eax@1

  result = unit;
  if ( unit )
    result = (RGE_Static_Object *)(unit->master_obj->object_group != 1);
  return result;
}

//----- (005071C0) --------------------------------------------------------
BOOL __stdcall TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int oType)
{
  return oType != 3 && oType != 27 && oType != 4 && oType != 21 && oType != 2 && oType != 20;
}

//----- (005071F0) --------------------------------------------------------
int __userpurge TribeSoldierUnitAIModule::processNotify@<eax>(TribeSoldierUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime)
{
  NotifyEvent *v4; // ebx@1
  TribeSoldierUnitAIModule *v5; // esi@1
  RGE_Static_Object *v6; // eax@4
  __int16 v7; // ax@5
  int v8; // eax@8
  RGE_Static_Object *v9; // edi@10
  int v10; // eax@10
  double v11; // st7@10
  double v13; // st7@11
  unsigned __int8 v14; // c0@11
  unsigned __int8 v15; // c3@11
  double v16; // st7@12
  RGE_Static_Object *v17; // edi@15
  int v18; // eax@15
  double v20; // st7@16
  unsigned __int8 v21; // c0@16
  unsigned __int8 v22; // c3@16
  RGE_Static_Object *v24; // eax@24
  RGE_Static_Object *v25; // edi@26
  RGE_Static_Object *v26; // eax@28
  double v27; // st7@28
  UnitAIModuleVtbl *v28; // edi@28
  int v29; // eax@28
  int v30; // ebp@29
  int v31; // ebx@31
  int *v32; // edi@31
  int i; // eax@32
  int v34; // ebx@38
  int *v35; // edi@38
  int j; // eax@39
  RGE_Static_Object *v37; // eax@43
  RGE_Static_Object *v38; // ecx@44
  RGE_Static_Object *v39; // eax@47
  long double v40; // st7@47
  float v41; // ST30_4@47
  float v42; // ST2C_4@47
  int v43; // [sp+40h] [bp-18h]@0
  int v44; // [sp+44h] [bp-14h]@0
  _DWORD *v45; // [sp+48h] [bp-10h]@0
  float evasiveMoveDistance; // [sp+50h] [bp-8h]@10
  float evasiveMoveDistancea; // [sp+50h] [bp-8h]@27
  UnitAIModuleVtbl *v48; // [sp+54h] [bp-4h]@28
  NotifyEvent *nEventa; // [sp+5Ch] [bp+4h]@15
  NotifyEvent *nEventc; // [sp+5Ch] [bp+4h]@27
  NotifyEvent *nEventb; // [sp+5Ch] [bp+4h]@28
  float yDiff; // [sp+60h] [bp+8h]@28

  v4 = nEvent;
  v5 = this;
  if ( nEvent->mType != 512 )
  {
    if ( nEvent->mType == 527 )
    {
      if ( RGE_Player::computerPlayer(this->objectValue->owner) )
      {
        v6 = RGE_Game_World::object(v5->objectValue->owner->world, nEvent->caller);
        if ( v6 )
        {
          v7 = v6->master_obj->id;
          if ( (v7 == 35 || v7 == 36) && v5->currentActionValue != -1 )
          {
            v8 = v5->currentOrderValue;
            if ( v8 != -1 )
              (*(void (__thiscall **)(TribeSoldierUnitAIModule *, int, int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int))&v5->vfptr->gap4[12])(
                v5,
                v5->objectValue->id,
                v8,
                v5->currentTargetValue,
                -1,
                LODWORD(v5->currentTargetXValue),
                LODWORD(v5->currentTargetYValue),
                LODWORD(v5->currentTargetZValue),
                LODWORD(v5->desiredTargetDistanceValue),
                0,
                0,
                v5->currentOrderPriorityValue);
            v9 = v5->objectValue;
            v10 = debug_rand(aCMsdevWorkA_48, 2428);
            v11 = (double)(signed int)((((unsigned __int64)v10 >> 32) ^ abs(v10) & 7) - ((unsigned __int64)v10 >> 32))
                + v9->world_x
                - 4.0;
            evasiveMoveDistance = v11;
            if ( v11 == v9->world_x )
            {
              v13 = evasiveMoveDistance;
              if ( v14 | v15 )
                v16 = v13 - -2.0;
              else
                v16 = v13 - 2.0;
              evasiveMoveDistance = v16;
            }
            v17 = v5->objectValue;
            v18 = debug_rand(aCMsdevWorkA_48, 2435);
            a2 = (double)(signed int)((((unsigned __int64)v18 >> 32) ^ abs(v18) & 7) - ((unsigned __int64)v18 >> 32))
               + v17->world_y
               - 4.0;
            *(float *)&nEventa = a2;
            if ( a2 == v17->world_y )
            {
              v20 = *(float *)&nEventa;
              if ( v21 | v22 )
                a2 = v20 - -2.0;
              else
                a2 = v20 - 2.0;
              *(float *)&nEventa = a2;
            }
            if ( ((int (__thiscall *)(TribeSoldierUnitAIModule *, float, NotifyEvent *, _DWORD, signed int, signed int))v5->vfptr->intelligentEvasiveMoveTo)(
                   v5,
                   COERCE_FLOAT(LODWORD(evasiveMoveDistance)),
                   nEventa,
                   LODWORD(v17->world_z),
                   1,
                   1) == 1 )
            {
              taskedThisUpdate = 1;
              return 3;
            }
          }
        }
      }
    }
    return UnitAIModule::processNotify((UnitAIModule *)&v5->vfptr, a2, v4, uTime, v43, v44, v45);
  }
  if ( RGE_Player::computerPlayer(this->objectValue->owner) )
  {
    ((void (*)(void))v5->objectValue->vfptr->weaponRange)();
    if ( a2 >= 1.0 )
    {
      v24 = v5->objectValue;
      if ( v24->master_obj->object_group != 26 )
      {
        if ( v5->currentActionValue != 600 )
          return 2;
        v25 = RGE_Game_World::object(v24->owner->world, v5->currentTargetValue);
        if ( v25 )
        {
          ((void (*)(void))v5->objectValue->vfptr->weaponRange)();
          *(float *)&nEventc = a2;
          a2 = *(float *)&nEventc - RGE_Static_Object::distance_to_object(v5->objectValue, v25);
          evasiveMoveDistancea = a2;
          if ( a2 >= 1.0 )
          {
            v26 = v5->objectValue;
            yDiff = v25->world_x - v26->world_x;
            v27 = v25->world_y;
            v28 = v5->vfptr;
            *(float *)&nEventb = v27 - v26->world_y;
            v48 = v5->vfptr;
            (*(void (__thiscall **)(TribeSoldierUnitAIModule *, int, signed int, int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, signed int, int))&v5->vfptr->gap4[12])(
              v5,
              v26->id,
              700,
              v5->currentTargetValue,
              -1,
              LODWORD(v5->currentTargetXValue),
              LODWORD(v5->currentTargetYValue),
              LODWORD(v5->currentTargetZValue),
              LODWORD(v5->desiredTargetDistanceValue),
              0,
              1,
              v5->currentOrderPriorityValue);
            v29 = v5->attackingUnitsValue.numberValue;
            if ( v29 > 0 )
            {
              v30 = 0;
              if ( v29 > 0 )
              {
                do
                {
                  if ( v30 > v5->attackingUnitsValue.maximumSizeValue - 1 )
                  {
                    v31 = v30 + 1;
                    v32 = (int *)operator new(4 * v30 + 4);
                    if ( v32 )
                    {
                      for ( i = 0;
                            i < v5->attackingUnitsValue.maximumSizeValue;
                            v32[i - 1] = v5->attackingUnitsValue.value[i - 1] )
                      {
                        if ( i >= v31 )
                          break;
                        ++i;
                      }
                      operator delete(v5->attackingUnitsValue.value);
                      v5->attackingUnitsValue.value = v32;
                      v5->attackingUnitsValue.maximumSizeValue = v31;
                    }
                  }
                  if ( v5->attackingUnitsValue.value[v30] != v5->currentTargetValue )
                  {
                    if ( v30 > v5->attackingUnitsValue.maximumSizeValue - 1 )
                    {
                      v34 = v30 + 1;
                      v35 = (int *)operator new(4 * v30 + 4);
                      if ( v35 )
                      {
                        for ( j = 0;
                              j < v5->attackingUnitsValue.maximumSizeValue;
                              v35[j - 1] = v5->attackingUnitsValue.value[j - 1] )
                        {
                          if ( j >= v34 )
                            break;
                          ++j;
                        }
                        operator delete(v5->attackingUnitsValue.value);
                        v5->attackingUnitsValue.value = v35;
                        v5->attackingUnitsValue.maximumSizeValue = v34;
                      }
                    }
                    v37 = RGE_Game_World::object(v5->objectValue->owner->world, v5->attackingUnitsValue.value[v30]);
                    if ( v37 )
                    {
                      v38 = v5->objectValue;
                      yDiff = v37->world_x - v38->world_x + yDiff;
                      *(float *)&nEventb = v37->world_y - v38->world_y + *(float *)&nEventb;
                    }
                  }
                  ++v30;
                }
                while ( v30 < v5->attackingUnitsValue.numberValue );
                v28 = v48;
              }
            }
            v39 = v5->objectValue;
            v40 = sqrt(yDiff * yDiff + *(float *)&nEventb * *(float *)&nEventb);
            v41 = v39->world_y - *(float *)&nEventb / v40 * evasiveMoveDistancea;
            v42 = v39->world_x - yDiff / v40 * evasiveMoveDistancea;
            if ( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, signed int))v28->intelligentEvasiveMoveTo)(
                   LODWORD(v42),
                   LODWORD(v41),
                   LODWORD(v39->world_z),
                   0,
                   1) == 1 )
              return 3;
            return 2;
          }
        }
      }
    }
  }
  return UnitAIModule::processNotify((UnitAIModule *)&v5->vfptr, a2, v4, uTime, v43, v44, v45);
}
// 592A48: using guessed type int taskedThisUpdate;

//----- (00507640) --------------------------------------------------------
int __userpurge TribeSoldierUnitAIModule::processIdle@<eax>(TribeSoldierUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch)
{
  TribeSoldierUnitAIModule *v3; // esi@1
  int result; // eax@3
  RGE_Player *v5; // ecx@4
  __int16 v6; // ax@8
  UnitAIModuleVtbl *v7; // ebx@11
  int v8; // eax@11
  int v9; // eax@15
  int v10; // eax@21
  int v11; // eax@23
  RGE_Static_Object *v12; // edi@24
  RGE_Static_Object *v13; // eax@25
  double v14; // rt1@25
  double v15; // st5@25
  double v16; // st6@25
  float xDiff; // ST44_4@25
  double v18; // st5@25
  double v19; // st7@25
  double v20; // st3@25
  double v21; // st6@25
  float v22; // ST44_4@25
  float v23; // ST2C_4@25
  float v24; // ST28_4@25
  int doSearcha; // [sp+4Ch] [bp+4h]@25
  int doSearchb; // [sp+4Ch] [bp+4h]@25

  v3 = this;
  if ( doSearch == 1 && ((int (*)(void))this->vfptr->processRetryableOrder)() == 8 )
    return 6;
  v5 = v3->objectValue->owner;
  if ( !v5->id || !RGE_Player::computerPlayer(v5) && v3->objectValue->master_obj->id == 299 )
    goto LABEL_29;
  if ( v3->currentOrderValue == 725 )
  {
    v6 = v3->objectValue->master_obj->id;
    if ( v6 == 35 || v6 == 36 || v6 == 250 )
      goto LABEL_29;
  }
  v7 = v3->vfptr;
  v8 = v3->vfptr->bestUnitToAttack((UnitAIModule *)v3, 1, 0, 0);
  if ( v8 != -1 && v7->attackObject((UnitAIModule *)v3, v8, 1) == 1 )
    return 6;
  if ( RGE_Player::computerPlayer(v3->objectValue->owner)
    && (LOBYTE(v9) = RGE_Static_Object::inGroup(v3->objectValue), v9 != 1)
    && ((RGE_Game_World::difficultyLevel(v3->objectValue->owner->world), RGE_Base_Game::scenarioGame(rge_base_game) != 1)
     || RGE_Base_Game::singlePlayerGame(rge_base_game) != 1
     || ((int (__stdcall *)(signed int))v3->objectValue->owner->vfptr->strategicNumber)(143))
    && (RGE_Base_Game::singlePlayerGame(rge_base_game) != 1
     || ((int (__stdcall *)(signed int))v3->objectValue->owner->vfptr->strategicNumber)(143))
    && (v10 = v3->currentOrderValue, v10 != 701)
    && v10 != 725
    && (v11 = v7->closestObject((UnitAIModule *)v3, -1, -1, -1, -1, 0), v11 != -1)
    && (v12 = RGE_Game_World::object(v3->objectValue->owner->world, v11)) != 0 )
  {
    ((void (*)(void))v3->objectValue->vfptr->maximumSpeed)();
    v13 = v3->objectValue;
    v14 = v12->world_y - v13->world_y;
    v15 = v12->world_x - v13->world_x;
    v16 = a2 * 3.0;
    xDiff = v15;
    *(float *)&doSearcha = v14;
    v18 = v15 * xDiff;
    v19 = *(float *)&doSearcha;
    v20 = v16;
    v21 = xDiff;
    v22 = v20;
    *(float *)&doSearchb = sqrt(v18 + v14 * *(float *)&doSearcha);
    v23 = v13->world_y - v19 / *(float *)&doSearchb * v22;
    v24 = v13->world_x - v21 / *(float *)&doSearchb * v22;
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, signed int))v7->evasiveMoveTo)(
      LODWORD(v24),
      LODWORD(v23),
      LODWORD(v13->world_z),
      1);
    result = 6;
  }
  else
  {
LABEL_29:
    result = 5;
  }
  return result;
}

//----- (00507880) --------------------------------------------------------
void __thiscall TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(TribeArtifactUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeArtifactUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeArtifactUnitAIModule::`vftable';
  v3->numberImportantObjects = 19;
  v4 = (int *)operator new(0x4Cu);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 0;
    v3->importantObjects[1] = 4;
    v3->importantObjects[2] = 26;
    v3->importantObjects[3] = 24;
    v3->importantObjects[4] = 6;
    v3->importantObjects[5] = 35;
    v3->importantObjects[6] = 25;
    v3->importantObjects[7] = 17;
    v3->importantObjects[8] = 12;
    v3->importantObjects[9] = 23;
    v3->importantObjects[10] = 36;
    v3->importantObjects[11] = 28;
    v3->importantObjects[12] = 18;
    v3->importantObjects[13] = 13;
    v3->importantObjects[14] = 22;
    v3->importantObjects[15] = 20;
    v3->importantObjects[16] = 2;
    v3->importantObjects[17] = 21;
    v3->importantObjects[18] = 39;
  }
  v3->idleTimeoutValue = 5000;
  UnitAIModule::setAdjustedIdleTimeout((UnitAIModule *)&v3->vfptr);
}
// 576290: using guessed type int (__thiscall *TribeArtifactUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00507A00) --------------------------------------------------------
TribeArtifactUnitAIModule *__thiscall TribeArtifactUnitAIModule::`scalar deleting destructor'(TribeArtifactUnitAIModule *this, unsigned int __flags)
{
  TribeArtifactUnitAIModule *v2; // esi@1

  v2 = this;
  TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00507A30) --------------------------------------------------------
int __thiscall TribeArtifactUnitAIModule::processNotify(TribeArtifactUnitAIModule *this, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeArtifactUnitAIModule *v3; // esi@1
  RGE_Static_Object *v4; // eax@2
  RGE_Static_Object *v5; // eax@5
  int v6; // eax@8
  RGE_Static_Object *v7; // eax@11
  RGE_Static_Object *v8; // eax@17
  int v9; // eax@20
  RGE_Static_Object *v10; // eax@23
  RGE_Static_Object *v11; // eax@29
  int v12; // eax@32
  RGE_Static_Object *v13; // eax@35
  RGE_Static_Object *v14; // eax@41
  int v15; // ecx@44
  int v16; // ebp@44
  int v17; // eax@44
  int v18; // ebx@49
  int *v19; // edi@49
  int i; // eax@50
  RGE_Static_Object *v22; // eax@57
  signed int v23; // eax@58
  UnitAIModuleVtbl *v24; // edi@61

  v3 = this;
  switch ( nEvent->mType )
  {
    case 0x1FC:
      v4 = RGE_Game_World::object(this->objectValue->owner->world, this->currentTargetValue);
      if ( v4
        && RGE_Visible_Map::get_visible(
             v3->objectValue->owner->visible,
             (signed __int64)v4->world_x,
             (signed __int64)v4->world_y) == 15 )
      {
        return 2;
      }
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&v3->vfptr);
      if ( actionFile )
      {
        v5 = v3->objectValue;
        if ( v5 )
          fprintf(actionFile, aDCallStopobjec, v5->id, aCMsdevWorkA_48, 2719);
        else
          fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2719);
      }
      goto LABEL_61;
    case 0x1FA:
      v6 = this->currentOrderValue;
      if ( v6 == -1 )
        goto LABEL_15;
      if ( this->currentActionValue + 100 == v6 )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
        if ( actionFile )
        {
          v7 = v3->objectValue;
          if ( v7 )
            fprintf(actionFile, aDCallStopobjec, v7->id, aCMsdevWorkA_48, 2734);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2734);
        }
        goto LABEL_61;
      }
      if ( v6 != -1 )
        return 2;
LABEL_15:
      if ( this->currentActionValue != nEvent->p1 )
        return 2;
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
      if ( actionFile )
      {
        v8 = v3->objectValue;
        if ( v8 )
          fprintf(actionFile, aDCallStopobjec, v8->id, aCMsdevWorkA_48, 2743);
        else
          fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2743);
      }
      goto LABEL_61;
    case 0x1F9:
      v9 = this->currentOrderValue;
      if ( v9 == -1 )
        goto LABEL_27;
      if ( this->currentActionValue + 100 == v9 )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
        if ( actionFile )
        {
          v10 = v3->objectValue;
          if ( v10 )
            fprintf(actionFile, aDCallStopobjec, v10->id, aCMsdevWorkA_48, 2758);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2758);
        }
        goto LABEL_61;
      }
      if ( v9 != -1 )
        return 2;
LABEL_27:
      if ( this->currentActionValue != nEvent->p1 )
        return 2;
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
      if ( actionFile )
      {
        v11 = v3->objectValue;
        if ( v11 )
          fprintf(actionFile, aDCallStopobjec, v11->id, aCMsdevWorkA_48, 2767);
        else
          fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2767);
      }
      goto LABEL_61;
    case 0x1FB:
      v12 = this->currentOrderValue;
      if ( v12 == -1 )
        goto LABEL_39;
      if ( this->currentActionValue + 100 == v12 )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
        if ( actionFile )
        {
          v13 = v3->objectValue;
          if ( v13 )
            fprintf(actionFile, aDCallStopobjec, v13->id, aCMsdevWorkA_48, 2782);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2782);
        }
LABEL_61:
        v24 = v3->vfptr;
        v3->vfptr->stopObject((UnitAIModule *)v3, 1);
        ((void (__thiscall *)(TribeArtifactUnitAIModule *, NotifyEvent *))v24->notifyCommander)(v3, nEvent);
        return 2;
      }
      if ( v12 != -1 )
        return 2;
LABEL_39:
      if ( this->currentActionValue == nEvent->p1 )
      {
        UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
        if ( actionFile )
        {
          v14 = v3->objectValue;
          if ( v14 )
            fprintf(actionFile, aDCallStopobjec, v14->id, aCMsdevWorkA_48, 2791);
          else
            fprintf(actionFile, aDCallStopobjec, -1, aCMsdevWorkA_48, 2791);
        }
        goto LABEL_61;
      }
      return 2;
    case 0x258:
      v15 = this->attackingUnitsValue.numberValue;
      v16 = nEvent->caller;
      v17 = 0;
      if ( v15 <= 0 )
        goto LABEL_48;
      do
      {
        if ( v17 >= v3->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v3->attackingUnitsValue.value[v17] == v16 )
          goto LABEL_55;
        ++v17;
      }
      while ( v17 < v15 );
LABEL_48:
      if ( v15 > v3->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v18 = v15 + 1;
        v19 = (int *)operator new(4 * (v15 + 1));
        if ( v19 )
        {
          for ( i = 0; i < v3->attackingUnitsValue.maximumSizeValue; v19[i - 1] = v3->attackingUnitsValue.value[i - 1] )
          {
            if ( i >= v18 )
              break;
            ++i;
          }
          operator delete(v3->attackingUnitsValue.value);
          v3->attackingUnitsValue.value = v19;
          v3->attackingUnitsValue.maximumSizeValue = v18;
        }
      }
      v3->attackingUnitsValue.value[v3->attackingUnitsValue.numberValue++] = v16;
LABEL_55:
      ((void (__stdcall *)(signed int))v3->objectValue->vfptr->setUnderAttack)(1);
      return 2;
    default:
      UnitAIModule::removeCurrentTarget((UnitAIModule *)&this->vfptr);
      if ( actionFile )
      {
        v22 = v3->objectValue;
        if ( v22 )
          v23 = v22->id;
        else
          v23 = -1;
        fprintf(actionFile, aDCallStopobjec, v23, aCMsdevWorkA_48, 2847);
      }
      goto LABEL_61;
    case 0x1F4:
    case 0x1F6:
    case 0x1F7:
    case 0x1F8:
    case 0x1FD:
    case 0x1FE:
    case 0x1FF:
    case 0x200:
    case 0x202:
    case 0x203:
    case 0x20B:
    case 0x20F:
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
    case 0x2BB:
      return 2;
  }
}

//----- (00507E90) --------------------------------------------------------
int __thiscall TribeArtifactUnitAIModule::processIdle(TribeArtifactUnitAIModule *this, int doSearch)
{
  TribeArtifactUnitAIModule *v2; // esi@1
  int v3; // eax@1
  RGE_Static_Object *v4; // eax@3
  RGE_Static_Object *v5; // ecx@4
  RGE_Player *v6; // eax@4
  int result; // eax@5

  v2 = this;
  v3 = ((int (__stdcall *)(signed int, signed int, signed int, signed int, _DWORD))this->vfptr->closestObject)(
         -1,
         -1,
         -1,
         -1,
         0);
  if ( numberDifferentPlayerObjectsVisible <= 1
    && v3 != -1
    && (v4 = RGE_Game_World::object(v2->objectValue->owner->world, v3)) != 0
    && (v5 = v2->objectValue, v6 = v4->owner, v5->owner != v6) )
  {
    ((void (__stdcall *)(RGE_Player *))v5->vfptr->change_ownership)(v6);
    result = 6;
  }
  else
  {
    result = 5;
  }
  return result;
}
// 592A54: using guessed type int numberDifferentPlayerObjectsVisible;

//----- (00507EF0) --------------------------------------------------------
int __thiscall TribeArtifactUnitAIModule::processMisc(TribeArtifactUnitAIModule *this)
{
  TribeArtifactUnitAIModule *v1; // esi@1
  UnitAIModuleVtbl *v2; // edi@1
  RGE_Static_Object *v3; // eax@3
  signed int v4; // eax@4
  int result; // eax@7

  v1 = this;
  v2 = this->vfptr;
  if ( ((int (__stdcall *)(signed int))this->vfptr->processIdle)(1) == 6 )
  {
    UnitAIModule::removeCurrentTarget((UnitAIModule *)&v1->vfptr);
    if ( actionFile )
    {
      v3 = v1->objectValue;
      if ( v3 )
        v4 = v3->id;
      else
        v4 = -1;
      fprintf(actionFile, aDCallStopobjec, v4, aCMsdevWorkA_48, 2912);
    }
    v2->stopObject((UnitAIModule *)v1, 1);
    v1->idleTimerValue = 0;
    result = 10;
  }
  else
  {
    result = 9;
  }
  return result;
}

//----- (00507F60) --------------------------------------------------------
void __thiscall TribeTowerUnitAIModule::TribeTowerUnitAIModule(TribeTowerUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeTowerUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeTowerUnitAIModule::`vftable';
  v3->numberImportantObjects = 21;
  v4 = (int *)operator new(0x54u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 0;
    v3->importantObjects[1] = 3;
    v3->importantObjects[2] = 4;
    v3->importantObjects[3] = 26;
    v3->importantObjects[4] = 24;
    v3->importantObjects[5] = 6;
    v3->importantObjects[6] = 35;
    v3->importantObjects[7] = 25;
    v3->importantObjects[8] = 17;
    v3->importantObjects[9] = 12;
    v3->importantObjects[10] = 23;
    v3->importantObjects[11] = 36;
    v3->importantObjects[12] = 28;
    v3->importantObjects[13] = 18;
    v3->importantObjects[14] = 13;
    v3->importantObjects[15] = 27;
    v3->importantObjects[16] = 22;
    v3->importantObjects[17] = 20;
    v3->importantObjects[18] = 2;
    v3->importantObjects[19] = 21;
    v3->importantObjects[20] = 39;
  }
}
// 576370: using guessed type int (__thiscall *TribeTowerUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (005080E0) --------------------------------------------------------
TribeTowerUnitAIModule *__thiscall TribeTowerUnitAIModule::`vector deleting destructor'(TribeTowerUnitAIModule *this, unsigned int __flags)
{
  TribeTowerUnitAIModule *v2; // esi@1

  v2 = this;
  TribeTowerUnitAIModule::~TribeTowerUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00508110) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeTowerUnitAIModule::canAttackUnit(TribeTowerUnitAIModule *this, RGE_Static_Object *unit)
{
  RGE_Static_Object *result; // eax@1

  result = unit;
  if ( unit )
  {
    if ( unit->master_obj->object_group == 1 )
      result = 0;
    else
      result = (RGE_Static_Object *)(this->objectValue->object_state >= 2u);
  }
  return result;
}

//----- (00508140) --------------------------------------------------------
BOOL __stdcall TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int oType)
{
  return oType != 3 && oType != 27 && oType != 4 && oType != 21 && oType != 2;
}

//----- (00508170) --------------------------------------------------------
void __thiscall TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(TribeBuildingUnitAIModule *this, RGE_Static_Object *o, int iQS)
{
  TribeBuildingUnitAIModule *v3; // esi@1
  int *v4; // eax@1

  v3 = this;
  UnitAIModule::UnitAIModule((UnitAIModule *)&this->vfptr, o, iQS);
  v3->vfptr = (UnitAIModuleVtbl *)&TribeBuildingUnitAIModule::`vftable';
  v3->numberImportantObjects = 21;
  v4 = (int *)operator new(0x54u);
  v3->importantObjects = v4;
  if ( v4 )
  {
    *v4 = 0;
    v3->importantObjects[1] = 3;
    v3->importantObjects[2] = 4;
    v3->importantObjects[3] = 26;
    v3->importantObjects[4] = 24;
    v3->importantObjects[5] = 6;
    v3->importantObjects[6] = 35;
    v3->importantObjects[7] = 25;
    v3->importantObjects[8] = 17;
    v3->importantObjects[9] = 12;
    v3->importantObjects[10] = 23;
    v3->importantObjects[11] = 36;
    v3->importantObjects[12] = 28;
    v3->importantObjects[13] = 18;
    v3->importantObjects[14] = 13;
    v3->importantObjects[15] = 27;
    v3->importantObjects[16] = 22;
    v3->importantObjects[17] = 20;
    v3->importantObjects[18] = 2;
    v3->importantObjects[19] = 21;
    v3->importantObjects[20] = 39;
  }
}
// 576450: using guessed type int (__thiscall *TribeBuildingUnitAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (005082F0) --------------------------------------------------------
TribeBuildingUnitAIModule *__thiscall TribeBuildingUnitAIModule::`scalar deleting destructor'(TribeBuildingUnitAIModule *this, unsigned int __flags)
{
  TribeBuildingUnitAIModule *v2; // esi@1

  v2 = this;
  TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00508320) --------------------------------------------------------
int __thiscall TribeBuildingUnitAIModule::processNotify(TribeBuildingUnitAIModule *this, NotifyEvent *nEvent, unsigned int uTime)
{
  TribeBuildingUnitAIModule *v3; // esi@1
  int result; // eax@3
  int v5; // ecx@7
  int **v6; // edi@7
  int i; // eax@7
  int v8; // ecx@14
  int v9; // ebx@14
  int j; // eax@14
  int v11; // ecx@21
  int v12; // ebx@21
  int k; // eax@21
  int v14; // ebp@26
  int *v15; // edi@26
  int l; // eax@27
  int v17; // ecx@33
  int v18; // eax@33
  int v19; // ecx@38
  int v20; // eax@38
  int *v21; // edx@39
  int v22; // eax@45
  int v23; // [sp+0h] [bp-10h]@0
  int v24; // [sp+4h] [bp-Ch]@0
  int v25; // [sp+8h] [bp-8h]@0

  v3 = this;
  switch ( nEvent->mType )
  {
    case 0x1F4:
      if ( nEvent->p2 > 0 )
      {
        if ( !this->attackingUnitsValue.numberValue || RGE_Player::computerPlayer(this->objectValue->owner) == 1 )
          ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))v3->objectValue->owner->vfptr->notify)(
            v3->objectValue->id,
            v3->objectValue->id,
            513,
            nEvent->caller,
            0,
            0);
        v5 = v3->attackingUnitsValue.numberValue;
        v6 = &v3->attackingUnitsValue.value;
        for ( i = 0; i < v5; ++i )
        {
          if ( i >= v3->attackingUnitsValue.maximumSizeValue )
            break;
          if ( (*v6)[i] == nEvent->caller )
            goto LABEL_14;
        }
        if ( !RGE_Player::computerPlayer(v3->objectValue->owner) && v3->currentTargetValue != nEvent->caller )
          UnitAIModule::askForHelp((UnitAIModule *)&v3->vfptr, nEvent->caller, v23, v24, v25);
LABEL_14:
        v8 = v3->attackingUnitsValue.numberValue;
        v9 = nEvent->caller;
        for ( j = 0; j < v8; ++j )
        {
          if ( j >= v3->attackingUnitsValue.maximumSizeValue )
            break;
          if ( (*v6)[j] == v9 )
            goto LABEL_32;
        }
        if ( v8 > v3->attackingUnitsValue.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v3->attackingUnitsValue, v8 + 1);
        (*v6)[v3->attackingUnitsValue.numberValue++] = v9;
        ((void (__stdcall *)(signed int))v3->objectValue->vfptr->setUnderAttack)(1);
        result = 2;
      }
      else
      {
        ((void (__stdcall *)(int, int, signed int, int, _DWORD, _DWORD))this->objectValue->owner->vfptr->notify)(
          this->objectValue->id,
          this->objectValue->id,
          521,
          nEvent->caller,
          0,
          0);
        UnitAIModule::purgeNotifyQueue((UnitAIModule *)&v3->vfptr, uTime);
        result = 4;
      }
      break;
    case 0x258:
      v11 = this->attackingUnitsValue.numberValue;
      v12 = nEvent->caller;
      for ( k = 0; k < v11; ++k )
      {
        if ( k >= v3->attackingUnitsValue.maximumSizeValue )
          break;
        if ( v3->attackingUnitsValue.value[k] == v12 )
          goto LABEL_32;
      }
      if ( v11 > v3->attackingUnitsValue.maximumSizeValue - 1 )
      {
        v14 = v11 + 1;
        v15 = (int *)operator new(4 * (v11 + 1));
        if ( v15 )
        {
          for ( l = 0; l < v3->attackingUnitsValue.maximumSizeValue; v15[l - 1] = v3->attackingUnitsValue.value[l - 1] )
          {
            if ( l >= v14 )
              break;
            ++l;
          }
          operator delete(v3->attackingUnitsValue.value);
          v3->attackingUnitsValue.value = v15;
          v3->attackingUnitsValue.maximumSizeValue = v14;
        }
      }
      v3->attackingUnitsValue.value[v3->attackingUnitsValue.numberValue++] = v12;
LABEL_32:
      ((void (__stdcall *)(signed int))v3->objectValue->vfptr->setUnderAttack)(1);
      result = 2;
      break;
    case 0x2BB:
      v17 = this->attackingUnitsValue.numberValue;
      v18 = 0;
      if ( v17 <= 0 )
        goto LABEL_47;
      do
      {
        if ( v18 >= v3->attackingUnitsValue.maximumSizeValue )
          goto LABEL_47;
        if ( v3->attackingUnitsValue.value[v18] == nEvent->caller )
        {
          v19 = v3->attackingUnitsValue.maximumSizeValue;
          v20 = 0;
          if ( v19 > 0 )
          {
            v21 = v3->attackingUnitsValue.value;
            do
            {
              if ( *v21 == nEvent->caller )
                break;
              ++v20;
              ++v21;
            }
            while ( v20 < v19 );
          }
          if ( v20 < v19 )
          {
            if ( v20 < v19 - 1 )
            {
              do
              {
                ++v20;
                v3->attackingUnitsValue.value[v20 - 1] = v3->attackingUnitsValue.value[v20];
              }
              while ( v20 < v3->attackingUnitsValue.maximumSizeValue - 1 );
            }
            v22 = v3->attackingUnitsValue.numberValue - 1;
            v3->attackingUnitsValue.numberValue = v22;
            if ( v22 < 0 )
              v3->attackingUnitsValue.numberValue = 0;
          }
          goto LABEL_47;
        }
        ++v18;
      }
      while ( v18 < v17 );
      result = 2;
      break;
    default:
LABEL_47:
      result = 2;
      break;
  }
  return result;
}

//----- (00508660) --------------------------------------------------------
int __stdcall TribeBuildingUnitAIModule::processIdle(int doSearch)
{
  return 5;
}
