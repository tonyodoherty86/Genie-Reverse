
/**
 * @file    Engine\TRB\AiStrategyModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

//----- (004E9100) --------------------------------------------------------
void __thiscall TribeStrategyAIModule::TribeStrategyAIModule(TribeStrategyAIModule *this, void *pW, int playerID)
{
  TribeStrategyAIModule *v3; // ebx@1

  v3 = this;
  StrategyAIModule::StrategyAIModule((StrategyAIModule *)&this->vfptr, pW, playerID);
  v3->md = 0;
  v3->currentVictoryConditionValue = -1;
  v3->targetIDValue = -1;
  v3->targetTypeValue = -1;
  v3->secondTargetIDValue = -1;
  v3->secondTargetTypeValue = -1;
  v3->targetAttributeValue = -1;
  v3->targetNumberValue = -1;
  v3->victoryConditionChangeTimeout = 0;
  v3->vcRuleSet.value = 0;
  v3->vcRuleSet.numberValue = 0;
  v3->vcRuleSet.desiredNumberValue = 0;
  v3->vcRuleSet.maximumSizeValue = 0;
  v3->executingRules.value = 0;
  v3->executingRules.numberValue = 0;
  v3->executingRules.desiredNumberValue = 0;
  v3->executingRules.maximumSizeValue = 0;
  v3->idleRules.value = 0;
  v3->idleRules.numberValue = 0;
  v3->idleRules.desiredNumberValue = 0;
  v3->idleRules.maximumSizeValue = 0;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem(&v3->vcRules);
  LODWORD(v3->targetPoint1Value.x) = -1082130432;
  LODWORD(v3->targetPoint1Value.y) = -1082130432;
  LODWORD(v3->targetPoint1Value.z) = -1082130432;
  LODWORD(v3->targetPoint2Value.x) = -1082130432;
  LODWORD(v3->targetPoint2Value.y) = -1082130432;
  LODWORD(v3->targetPoint2Value.z) = -1082130432;
  v3->difficultyLevel = 0;
  v3->vfptr = (AIModuleVtbl *)&TribeStrategyAIModule::`vftable';
  strcpy(v3->ruleSetNameValue, message_in);
}
// 575698: using guessed type int (__thiscall *TribeStrategyAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004E9240) --------------------------------------------------------
TribeStrategyAIModule *__thiscall TribeStrategyAIModule::`vector deleting destructor'(TribeStrategyAIModule *this, unsigned int __flags)
{
  TribeStrategyAIModule *v2; // esi@1

  v2 = this;
  TribeStrategyAIModule::~TribeStrategyAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E9260) --------------------------------------------------------
void __userpurge TribeStrategyAIModule::TribeStrategyAIModule(TribeStrategyAIModule *this@<ecx>, int a2@<ebp>, int playerID, int infile)
{
  TribeStrategyAIModule *v4; // esi@1
  int *v5; // edi@1
  int v6; // ebx@1
  int v7; // ST00_4@1
  int v8; // ebp@3
  int v9; // ecx@4
  int v10; // eax@4
  int j; // eax@11
  int v12; // ecx@18
  int v13; // eax@18
  int k; // eax@25
  int v15; // ecx@34
  int v16; // eax@34
  int v17; // ebx@34
  int l; // eax@41
  int i; // [sp+10h] [bp-1Ch]@3
  int ia; // [sp+10h] [bp-1Ch]@17
  int ib; // [sp+10h] [bp-1Ch]@31
  int tempIntNum; // [sp+14h] [bp-18h]@3
  int v23; // [sp+18h] [bp-14h]@4
  TribeStrategyAIModule *v24; // [sp+1Ch] [bp-10h]@1
  int v25; // [sp+28h] [bp-4h]@1

  v4 = this;
  v24 = this;
  StrategyAIModule::StrategyAIModule((StrategyAIModule *)&this->vfptr, 0, playerID);
  v4->md = 0;
  v25 = 0;
  v4->vcRuleSet.value = 0;
  v4->vcRuleSet.numberValue = 0;
  v4->vcRuleSet.desiredNumberValue = 0;
  v4->vcRuleSet.maximumSizeValue = 0;
  v4->executingRules.value = 0;
  v4->executingRules.numberValue = 0;
  v4->executingRules.desiredNumberValue = 0;
  v4->executingRules.maximumSizeValue = 0;
  v4->idleRules.value = 0;
  v4->idleRules.numberValue = 0;
  v4->idleRules.desiredNumberValue = 0;
  v4->idleRules.maximumSizeValue = 0;
  VictoryConditionRuleSystem::VictoryConditionRuleSystem(&v4->vcRules);
  v5 = &v4->difficultyLevel;
  v4->difficultyLevel = 0;
  v6 = infile;
  v7 = infile;
  LOBYTE(v25) = 4;
  v4->vfptr = (AIModuleVtbl *)&TribeStrategyAIModule::`vftable';
  rge_read(a2, (int)&v4->difficultyLevel, v7, &v4->currentVictoryConditionValue, 4);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->targetIDValue, 4);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->secondTargetIDValue, 4);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->secondTargetTypeValue, 4);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->targetPoint1Value, 16);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->targetPoint2Value, 16);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->targetAttributeValue, 4);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->targetNumberValue, 4);
  rge_read(a2, (int)&v4->difficultyLevel, v6, &v4->victoryConditionChangeTimeout, 4);
  if ( save_game_version >= 1.5 )
    rge_read(a2, (int)v5, v6, &v4->difficultyLevel, 4);
  rge_read(a2, (int)v5, v6, &playerID, 4);
  v8 = (int)v4->ruleSetNameValue;
  rge_read((int)v4->ruleSetNameValue, (int)v5, v6, v4->ruleSetNameValue, playerID);
  v4->ruleSetNameValue[playerID] = 0;
  TribeStrategyAIModule::loadRules(v4, v4->ruleSetNameValue);
  TribeStrategyAIModule::setDifficultyLevel(v4, *v5);
  rge_read((int)v4->ruleSetNameValue, (int)v5, v6, &tempIntNum, 4);
  for ( i = 0; i < tempIntNum; ++i )
  {
    rge_read(v8, (int)v5, v6, &playerID, 4);
    v9 = v4->vcRuleSet.numberValue;
    v10 = 0;
    v23 = playerID;
    if ( v9 > 0 )
    {
      v5 = (int *)v4->vcRuleSet.maximumSizeValue;
      do
      {
        if ( v10 >= (signed int)v5 )
          break;
        v8 = (int)v4->vcRuleSet.value;
        if ( *(_DWORD *)(v8 + 4 * v10) == playerID )
          goto LABEL_16;
        ++v10;
      }
      while ( v10 < v9 );
    }
    if ( v9 > v4->vcRuleSet.maximumSizeValue - 1 )
    {
      v8 = v9 + 1;
      v5 = (int *)operator new(4 * (v9 + 1));
      if ( v5 )
      {
        for ( j = 0; j < v4->vcRuleSet.maximumSizeValue; v5[j - 1] = v4->vcRuleSet.value[j - 1] )
        {
          if ( j >= v8 )
            break;
          ++j;
        }
        operator delete(v4->vcRuleSet.value);
        v4->vcRuleSet.value = v5;
        v4->vcRuleSet.maximumSizeValue = v8;
      }
    }
    v4->vcRuleSet.value[v4->vcRuleSet.numberValue++] = v23;
LABEL_16:
    ;
  }
  rge_read(v8, (int)v5, v6, &tempIntNum, 4);
  for ( ia = 0; ia < tempIntNum; ++ia )
  {
    rge_read(v8, (int)v5, v6, &playerID, 4);
    v12 = v4->executingRules.numberValue;
    v13 = 0;
    v23 = playerID;
    if ( v12 > 0 )
    {
      v5 = (int *)v4->executingRules.maximumSizeValue;
      do
      {
        if ( v13 >= (signed int)v5 )
          break;
        v8 = (int)v4->executingRules.value;
        if ( *(_DWORD *)(v8 + 4 * v13) == playerID )
          goto LABEL_30;
        ++v13;
      }
      while ( v13 < v12 );
    }
    if ( v12 > v4->executingRules.maximumSizeValue - 1 )
    {
      v8 = v12 + 1;
      v5 = (int *)operator new(4 * (v12 + 1));
      if ( v5 )
      {
        for ( k = 0; k < v4->executingRules.maximumSizeValue; v5[k - 1] = v4->executingRules.value[k - 1] )
        {
          if ( k >= v8 )
            break;
          ++k;
        }
        operator delete(v4->executingRules.value);
        v4->executingRules.value = v5;
        v4->executingRules.maximumSizeValue = v8;
      }
    }
    v4->executingRules.value[v4->executingRules.numberValue++] = v23;
LABEL_30:
    ;
  }
  rge_read(v8, (int)v5, v6, &tempIntNum, 4);
  ib = 0;
  if ( tempIntNum > 0 )
  {
    while ( 1 )
    {
      rge_read(v8, (int)v5, v6, &playerID, 4);
      v15 = v4->idleRules.numberValue;
      v16 = 0;
      v17 = playerID;
      if ( v15 > 0 )
      {
        v5 = (int *)v4->idleRules.maximumSizeValue;
        do
        {
          if ( v16 >= (signed int)v5 )
            break;
          v8 = (int)v4->idleRules.value;
          if ( *(_DWORD *)(v8 + 4 * v16) == playerID )
            goto LABEL_46;
          ++v16;
        }
        while ( v16 < v15 );
      }
      if ( v15 > v4->idleRules.maximumSizeValue - 1 )
      {
        v8 = v15 + 1;
        v5 = (int *)operator new(4 * (v15 + 1));
        if ( v5 )
        {
          for ( l = 0; l < v4->idleRules.maximumSizeValue; v5[l - 1] = v4->idleRules.value[l - 1] )
          {
            if ( l >= v8 )
              break;
            ++l;
          }
          operator delete(v4->idleRules.value);
          v4->idleRules.value = v5;
          v4->idleRules.maximumSizeValue = v8;
        }
      }
      v4->idleRules.value[v4->idleRules.numberValue++] = v17;
LABEL_46:
      if ( ++ib >= tempIntNum )
        break;
      v6 = infile;
    }
  }
}
// 575698: using guessed type int (__thiscall *TribeStrategyAIModule::`vftable')(void *Memory, unsigned int __flags);
// 58EBCC: using guessed type float save_game_version;

//----- (004E9730) --------------------------------------------------------
void __thiscall TribeStrategyAIModule::~TribeStrategyAIModule(TribeStrategyAIModule *this)
{
  TribeStrategyAIModule *v1; // esi@1
  int *v2; // eax@1
  int *v3; // eax@3
  int *v4; // eax@5

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&TribeStrategyAIModule::`vftable';
  VictoryConditionRuleSystem::~VictoryConditionRuleSystem(&this->vcRules);
  v2 = v1->idleRules.value;
  if ( v2 )
  {
    operator delete(v2);
    v1->idleRules.value = 0;
  }
  v1->idleRules.numberValue = 0;
  v1->idleRules.desiredNumberValue = 0;
  v1->idleRules.maximumSizeValue = 0;
  v3 = v1->executingRules.value;
  if ( v3 )
  {
    operator delete(v3);
    v1->executingRules.value = 0;
  }
  v1->executingRules.numberValue = 0;
  v1->executingRules.desiredNumberValue = 0;
  v1->executingRules.maximumSizeValue = 0;
  v4 = v1->vcRuleSet.value;
  if ( v4 )
  {
    operator delete(v4);
    v1->vcRuleSet.value = 0;
  }
  v1->vcRuleSet.numberValue = 0;
  v1->vcRuleSet.desiredNumberValue = 0;
  v1->vcRuleSet.maximumSizeValue = 0;
  StrategyAIModule::~StrategyAIModule((StrategyAIModule *)&v1->vfptr);
}
// 575698: using guessed type int (__thiscall *TribeStrategyAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004E9820) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::update(TribeStrategyAIModule *this, int timeLimit)
{
  TribeStrategyAIModule *v2; // esi@1
  int v3; // ebp@1
  int v4; // eax@1
  TribeMainDecisionAIModule *v5; // eax@2
  int v6; // edi@2
  RGE_Victory_Entry *v7; // eax@2
  RGE_Static_Object *v8; // ecx@3
  RGE_Static_Object *v9; // ecx@5
  int v10; // edi@10
  int v11; // ebx@10
  void **v12; // edi@11
  _DWORD *v13; // ebx@16
  int i; // eax@17
  int v15; // ecx@26
  int j; // eax@26
  int v17; // edx@33
  int v18; // eax@33
  int *v19; // ecx@34
  int v20; // eax@40
  int v21; // ebx@42
  int v22; // ebp@42
  void **v23; // edi@43
  _DWORD *v24; // ebx@45
  int k; // eax@46
  int v26; // ebx@50
  int v27; // edx@58
  int v28; // eax@58
  int *v29; // ecx@59
  int v30; // eax@65
  int v31; // ecx@67
  int l; // eax@67
  int m; // ebx@74
  int v34; // ebp@76
  int *v35; // edi@76
  int n; // eax@77
  int v37; // ebp@83
  int *v38; // edi@83
  int ii; // eax@84
  int worstRuleResult; // [sp+10h] [bp-8h]@10
  int worstRuleResulta; // [sp+10h] [bp-8h]@42
  int result; // [sp+14h] [bp-4h]@14
  int resulta; // [sp+14h] [bp-4h]@42

  v2 = this;
  v3 = 0;
  v4 = this->victoryConditionChangeTimeout + 1;
  this->victoryConditionChangeTimeout = v4;
  if ( v4 >= 0 )
  {
    v5 = this->md;
    this->victoryConditionChangeTimeout = 0;
    v6 = 11;
    v7 = RGE_Victory_Conditions::condition_raw_info(v5->player->victory_conditions, 0);
    if ( v7 )
    {
      v8 = v7->target_obj;
      v6 = v7->command;
      if ( v8 )
      {
        v2->targetIDValue = v8->id;
        v2->targetTypeValue = v7->target_obj->master_obj->id;
      }
      v9 = v7->this_obj;
      if ( v9 )
      {
        v2->secondTargetIDValue = v9->id;
        v2->secondTargetTypeValue = v7->this_obj->master_obj->id;
      }
      v2->targetPoint1Value.x = v7->x0;
      v2->targetPoint1Value.y = v7->y0;
      LODWORD(v2->targetPoint1Value.z) = 1065353216;
      v2->targetPoint2Value.x = v7->x1;
      v2->targetPoint2Value.y = v7->y1;
      LODWORD(v2->targetPoint2Value.z) = 1065353216;
      v2->targetAttributeValue = v7->number;
      v2->targetNumberValue = v7->count;
    }
    if ( v6 != v2->currentVictoryConditionValue )
      TribeStrategyAIModule::setVictoryCondition(v2, v6);
  }
  v10 = -1;
  v11 = 0;
  worstRuleResult = -1;
  if ( v2->idleRules.numberValue > 0 )
  {
    v12 = (void **)&v2->idleRules.value;
    do
    {
      if ( v3 > v2->idleRules.maximumSizeValue - 1 )
        ManagedArray<int>::resize(&v2->idleRules, v3 + 1);
      result = VictoryConditionRuleSystem::evaluateAsNonInProgress(v2->md->aiPlayer, *((_DWORD *)*v12 + v3));
      if ( result > v11 )
      {
        if ( v3 > v2->idleRules.maximumSizeValue - 1 )
        {
          v13 = operator new(4 * v3 + 4);
          if ( v13 )
          {
            for ( i = 0; i < v2->idleRules.maximumSizeValue; v13[i - 1] = *((_DWORD *)*v12 + i - 1) )
            {
              if ( i >= v3 + 1 )
                break;
              ++i;
            }
            operator delete(*v12);
            *v12 = v13;
            v2->idleRules.maximumSizeValue = v3 + 1;
          }
        }
        v11 = result;
        worstRuleResult = *((_DWORD *)*v12 + v3);
      }
      ++v3;
    }
    while ( v3 < v2->idleRules.numberValue );
    v10 = worstRuleResult;
  }
  if ( v10 != -1
    && VictoryConditionRuleSystem::execute(&v2->vcRules, v2->md->aiPlayer, v2->currentVictoryConditionValue, v10) == 1 )
  {
    v15 = v2->executingRules.numberValue;
    for ( j = 0; j < v15; ++j )
    {
      if ( j >= v2->executingRules.maximumSizeValue )
        break;
      if ( v2->executingRules.value[j] == v10 )
        goto LABEL_33;
    }
    if ( v15 > v2->executingRules.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v2->executingRules, v15 + 1);
    v2->executingRules.value[v2->executingRules.numberValue++] = v10;
LABEL_33:
    v17 = v2->idleRules.maximumSizeValue;
    v18 = 0;
    if ( v17 > 0 )
    {
      v19 = v2->idleRules.value;
      do
      {
        if ( *v19 == v10 )
          break;
        ++v18;
        ++v19;
      }
      while ( v18 < v17 );
    }
    if ( v18 < v17 )
    {
      if ( v18 < v17 - 1 )
      {
        do
        {
          ++v18;
          v2->idleRules.value[v18 - 1] = v2->idleRules.value[v18];
        }
        while ( v18 < v2->idleRules.maximumSizeValue - 1 );
      }
      v20 = v2->idleRules.numberValue - 1;
      v2->idleRules.numberValue = v20;
      if ( v20 < 0 )
        v2->idleRules.numberValue = 0;
    }
  }
  v21 = -1;
  v22 = 0;
  resulta = -1;
  worstRuleResulta = 101;
  if ( v2->executingRules.numberValue > 0 )
  {
    v23 = (void **)&v2->executingRules.value;
    do
    {
      if ( v22 > v2->executingRules.maximumSizeValue - 1 )
      {
        v24 = operator new(4 * v22 + 4);
        if ( v24 )
        {
          for ( k = 0; k < v2->executingRules.maximumSizeValue; v24[k - 1] = *((_DWORD *)*v23 + k - 1) )
          {
            if ( k >= v22 + 1 )
              break;
            ++k;
          }
          operator delete(*v23);
          *v23 = v24;
          v2->executingRules.maximumSizeValue = v22 + 1;
        }
      }
      v26 = VictoryConditionRuleSystem::evaluateAsInProgress(v2->md->aiPlayer, *((_DWORD *)*v23 + v22));
      if ( v26 < worstRuleResulta )
      {
        if ( v22 > v2->executingRules.maximumSizeValue - 1 )
          ManagedArray<int>::resize(&v2->executingRules, v22 + 1);
        worstRuleResulta = v26;
        resulta = *((_DWORD *)*v23 + v22);
      }
      ++v22;
    }
    while ( v22 < v2->executingRules.numberValue );
    v21 = resulta;
  }
  if ( v21 != -1 && VictoryConditionRuleSystem::stopExecution(v2->md->aiPlayer, v21) == 1 )
  {
    v27 = v2->executingRules.maximumSizeValue;
    v28 = 0;
    if ( v27 > 0 )
    {
      v29 = v2->executingRules.value;
      do
      {
        if ( *v29 == v21 )
          break;
        ++v28;
        ++v29;
      }
      while ( v28 < v27 );
    }
    if ( v28 < v27 )
    {
      if ( v28 < v27 - 1 )
      {
        do
        {
          ++v28;
          v2->executingRules.value[v28 - 1] = v2->executingRules.value[v28];
        }
        while ( v28 < v2->executingRules.maximumSizeValue - 1 );
      }
      v30 = v2->executingRules.numberValue - 1;
      v2->executingRules.numberValue = v30;
      if ( v30 < 0 )
        v2->executingRules.numberValue = 0;
    }
    v31 = v2->idleRules.numberValue;
    for ( l = 0; l < v31; ++l )
    {
      if ( l >= v2->idleRules.maximumSizeValue )
        break;
      if ( v2->idleRules.value[l] == v21 )
        goto LABEL_74;
    }
    if ( v31 > v2->idleRules.maximumSizeValue - 1 )
      ManagedArray<int>::resize(&v2->idleRules, v31 + 1);
    v2->idleRules.value[v2->idleRules.numberValue++] = v21;
  }
LABEL_74:
  for ( m = 0; m < v2->vcRuleSet.numberValue; ++m )
  {
    if ( m > v2->vcRuleSet.maximumSizeValue - 1 )
    {
      v34 = m + 1;
      v35 = (int *)operator new(4 * m + 4);
      if ( v35 )
      {
        for ( n = 0; n < v2->vcRuleSet.maximumSizeValue; v35[n - 1] = v2->vcRuleSet.value[n - 1] )
        {
          if ( n >= v34 )
            break;
          ++n;
        }
        operator delete(v2->vcRuleSet.value);
        v2->vcRuleSet.value = v35;
        v2->vcRuleSet.maximumSizeValue = v34;
      }
    }
    if ( VictoryConditionRuleSystem::evaluateAsNonInProgress(v2->md->aiPlayer, v2->vcRuleSet.value[m]) == -1 )
    {
      if ( m > v2->vcRuleSet.maximumSizeValue - 1 )
      {
        v37 = m + 1;
        v38 = (int *)operator new(4 * m + 4);
        if ( v38 )
        {
          for ( ii = 0; ii < v2->vcRuleSet.maximumSizeValue; v38[ii - 1] = v2->vcRuleSet.value[ii - 1] )
          {
            if ( ii >= v37 )
              break;
            ++ii;
          }
          operator delete(v2->vcRuleSet.value);
          v2->vcRuleSet.value = v38;
          v2->vcRuleSet.maximumSizeValue = v37;
        }
      }
      VictoryConditionRuleSystem::execute(
        &v2->vcRules,
        v2->md->aiPlayer,
        v2->currentVictoryConditionValue,
        v2->vcRuleSet.value[m]);
    }
  }
  return 1;
}

//----- (004E9D90) --------------------------------------------------------
void __thiscall TribeStrategyAIModule::setMainDecisionAI(TribeStrategyAIModule *this, TribeMainDecisionAIModule *m)
{
  this->md = m;
}

//----- (004E9DA0) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::save(TribeStrategyAIModule *this, int outfile)
{
  TribeStrategyAIModule *v2; // ebx@1
  int v3; // ebp@1
  int i; // edi@1
  int *v5; // esi@3
  int j; // eax@4
  int k; // edi@9
  int *v8; // esi@11
  int l; // eax@12
  int m; // edi@17
  int v11; // ebp@19
  int *v12; // esi@19
  int n; // eax@20
  int tempInt; // [sp+10h] [bp-108h]@1
  char tempString[257]; // [sp+14h] [bp-104h]@1

  v2 = this;
  v3 = outfile;
  rge_write(outfile, &this->currentVictoryConditionValue, 4);
  rge_write(outfile, &v2->targetIDValue, 4);
  rge_write(outfile, &v2->secondTargetIDValue, 4);
  rge_write(outfile, &v2->secondTargetTypeValue, 4);
  rge_write(outfile, &v2->targetPoint1Value, 16);
  rge_write(outfile, &v2->targetPoint2Value, 16);
  rge_write(outfile, &v2->targetAttributeValue, 4);
  rge_write(outfile, &v2->targetNumberValue, 4);
  rge_write(outfile, &v2->victoryConditionChangeTimeout, 4);
  rge_write(outfile, &v2->difficultyLevel, 4);
  strcpy(tempString, v2->ruleSetNameValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  tempInt = v2->vcRuleSet.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( i = 0; i < v2->vcRuleSet.numberValue; ++i )
  {
    if ( i > v2->vcRuleSet.maximumSizeValue - 1 )
    {
      v5 = (int *)operator new(4 * i + 4);
      if ( v5 )
      {
        for ( j = 0; j < v2->vcRuleSet.maximumSizeValue; v5[j - 1] = v2->vcRuleSet.value[j - 1] )
        {
          if ( j >= i + 1 )
            break;
          ++j;
        }
        operator delete(v2->vcRuleSet.value);
        v2->vcRuleSet.value = v5;
        v2->vcRuleSet.maximumSizeValue = i + 1;
      }
    }
    tempInt = v2->vcRuleSet.value[i];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v2->executingRules.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( k = 0; k < v2->executingRules.numberValue; ++k )
  {
    if ( k > v2->executingRules.maximumSizeValue - 1 )
    {
      v8 = (int *)operator new(4 * k + 4);
      if ( v8 )
      {
        for ( l = 0; l < v2->executingRules.maximumSizeValue; v8[l - 1] = v2->executingRules.value[l - 1] )
        {
          if ( l >= k + 1 )
            break;
          ++l;
        }
        operator delete(v2->executingRules.value);
        v2->executingRules.value = v8;
        v2->executingRules.maximumSizeValue = k + 1;
      }
    }
    tempInt = v2->executingRules.value[k];
    rge_write(outfile, &tempInt, 4);
  }
  tempInt = v2->idleRules.numberValue;
  rge_write(outfile, &tempInt, 4);
  for ( m = 0; m < v2->idleRules.numberValue; ++m )
  {
    if ( m > v2->idleRules.maximumSizeValue - 1 )
    {
      v11 = m + 1;
      v12 = (int *)operator new(4 * m + 4);
      if ( v12 )
      {
        for ( n = 0; n < v2->idleRules.maximumSizeValue; v12[n - 1] = v2->idleRules.value[n - 1] )
        {
          if ( n >= v11 )
            break;
          ++n;
        }
        operator delete(v2->idleRules.value);
        v2->idleRules.value = v12;
        v2->idleRules.maximumSizeValue = v11;
      }
      v3 = outfile;
    }
    tempInt = v2->idleRules.value[m];
    rge_write(v3, &tempInt, 4);
  }
  return 1;
}

//----- (004EA130) --------------------------------------------------------
char *__thiscall TribeStrategyAIModule::ruleSetName(TribeStrategyAIModule *this)
{
  return this->ruleSetNameValue;
}

//----- (004EA140) --------------------------------------------------------
char *__thiscall TribeStrategyAIModule::loadRules(TribeStrategyAIModule *this, char *rName)
{
  char *result; // eax@1
  TribeStrategyAIModule *v3; // edi@1

  result = rName;
  v3 = this;
  if ( rName )
  {
    strncpy(this->ruleSetNameValue, rName, 0xFFu);
    result = (char *)VictoryConditionRuleSystem::loadRules(&v3->vcRules, v3->ruleSetNameValue);
  }
  return result;
}

//----- (004EA180) --------------------------------------------------------
void __thiscall TribeStrategyAIModule::setRule(TribeStrategyAIModule *this, int ruleIndex, int value)
{
  TribeStrategyAIModule *v3; // esi@1

  v3 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aSettingSnDToD_, ruleIndex, value);
  VictoryConditionRuleSystem::setRule(&v3->vcRules, ruleIndex, value);
}

//----- (004EA1B0) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::rule(TribeStrategyAIModule *this, int ruleIndex)
{
  return VictoryConditionRuleSystem::rule(&this->vcRules, ruleIndex);
}

//----- (004EA1D0) --------------------------------------------------------
void __thiscall TribeStrategyAIModule::setDifficultyLevel(TribeStrategyAIModule *this, int difficultyLevel)
{
  VictoryConditionRuleSystem::modifyForDifficultyLevel(&this->vcRules, difficultyLevel);
}

//----- (004EA1F0) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::currentVictoryCondition(TribeStrategyAIModule *this)
{
  return this->currentVictoryConditionValue;
}

//----- (004EA200) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::targetID(TribeStrategyAIModule *this)
{
  return this->targetIDValue;
}

//----- (004EA210) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::targetType(TribeStrategyAIModule *this)
{
  return this->targetTypeValue;
}

//----- (004EA220) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::secondTargetID(TribeStrategyAIModule *this)
{
  return this->secondTargetIDValue;
}

//----- (004EA230) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::secondTargetType(TribeStrategyAIModule *this)
{
  return this->secondTargetTypeValue;
}

//----- (004EA240) --------------------------------------------------------
Waypoint *__thiscall TribeStrategyAIModule::targetPoint1(TribeStrategyAIModule *this)
{
  return &this->targetPoint1Value;
}

//----- (004EA250) --------------------------------------------------------
Waypoint *__thiscall TribeStrategyAIModule::targetPoint2(TribeStrategyAIModule *this)
{
  return &this->targetPoint2Value;
}

//----- (004EA260) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::targetAttribute(TribeStrategyAIModule *this)
{
  return this->targetAttributeValue;
}

//----- (004EA270) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::targetNumber(TribeStrategyAIModule *this)
{
  return this->targetNumberValue;
}

//----- (004EA280) --------------------------------------------------------
void __thiscall TribeStrategyAIModule::setVictoryCondition(TribeStrategyAIModule *this, int vcNumber)
{
  TribeStrategyAIModule *v2; // ebx@1
  ManagedArray<int> *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@2
  int v6; // eax@6
  int v7; // eax@10
  int v8; // eax@14
  int v9; // eax@18
  int v10; // eax@22
  int v11; // eax@26
  int v12; // eax@30
  int v13; // eax@34
  int v14; // eax@38
  int v15; // eax@42
  int v16; // eax@46
  int v17; // eax@50
  int *v18; // eax@54
  int *v19; // eax@55
  int *v20; // eax@56
  int v21; // ST08_4@57

  v2 = this;
  v3 = &this->vcRuleSet;
  v4 = 0;
  this->currentVictoryConditionValue = vcNumber;
  this->vcRuleSet.numberValue = 0;
  vcNumber = 1;
  if ( ManagedArray<int>::contains(&this->vcRuleSet, &vcNumber) != 1 )
  {
    v5 = v3->numberValue;
    if ( v5 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v5 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 2;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v6 = v3->numberValue;
    if ( v6 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v6 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 12;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v7 = v3->numberValue;
    if ( v7 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v7 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 13;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v8 = v3->numberValue;
    if ( v8 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v8 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 14;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v9 = v3->numberValue;
    if ( v9 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v9 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 16;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v10 = v3->numberValue;
    if ( v10 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v10 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 17;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v11 = v3->numberValue;
    if ( v11 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v11 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 18;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v12 = v3->numberValue;
    if ( v12 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v12 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 21;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v13 = v3->numberValue;
    if ( v13 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v13 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 22;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v14 = v3->numberValue;
    if ( v14 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v14 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 23;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v15 = v3->numberValue;
    if ( v15 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v15 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 24;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v16 = v3->numberValue;
    if ( v16 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v16 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  vcNumber = 25;
  if ( ManagedArray<int>::contains(v3, &vcNumber) != 1 )
  {
    v17 = v3->numberValue;
    if ( v17 > v3->maximumSizeValue - 1 )
      ManagedArray<int>::resize(v3, v17 + 1);
    v3->value[v3->numberValue++] = vcNumber;
  }
  ManagedArray<int>::add(v3, 26);
  ManagedArray<int>::add(v3, 27);
  ManagedArray<int>::add(v3, 28);
  ManagedArray<int>::add(v3, 29);
  ManagedArray<int>::add(v3, 30);
  ManagedArray<int>::add(v3, 31);
  ManagedArray<int>::add(v3, 32);
  ManagedArray<int>::add(v3, 33);
  ManagedArray<int>::add(v3, 34);
  ManagedArray<int>::add(v3, 35);
  ManagedArray<int>::add(v3, 36);
  ManagedArray<int>::add(v3, 37);
  ManagedArray<int>::add(v3, 38);
  ManagedArray<int>::add(v3, 39);
  ManagedArray<int>::add(v3, 40);
  ManagedArray<int>::add(v3, 41);
  ManagedArray<int>::add(v3, 42);
  ManagedArray<int>::add(v3, 43);
  ManagedArray<int>::add(v3, 44);
  ManagedArray<int>::add(v3, 45);
  ManagedArray<int>::add(v3, 46);
  ManagedArray<int>::add(v3, 47);
  ManagedArray<int>::add(v3, 48);
  ManagedArray<int>::add(v3, 49);
  if ( v2->vcRuleSet.numberValue > 0 )
  {
    do
    {
      v18 = ManagedArray<int>::operator[](v3, v4);
      if ( VictoryConditionRuleSystem::evaluateAsNonInProgress(v2->md->aiPlayer, *v18) == -2 )
      {
        v19 = ManagedArray<int>::operator[](v3, v4);
        if ( VictoryConditionRuleSystem::execute(&v2->vcRules, v2->md->aiPlayer, v2->currentVictoryConditionValue, *v19) == 1 )
        {
          v20 = ManagedArray<int>::operator[](v3, v4);
          ManagedArray<int>::add(&v2->executingRules, *v20);
        }
        else
        {
          v21 = *ManagedArray<int>::operator[](v3, v4);
          ManagedArray<int>::add(&v2->idleRules, v21);
        }
      }
      ++v4;
    }
    while ( v4 < v2->vcRuleSet.numberValue );
  }
}

//----- (004EA750) --------------------------------------------------------
int *__thiscall ManagedArray<int>::operator[](ManagedArray<int> *this, int v)
{
  ManagedArray<int> *v2; // esi@1
  int v3; // ebx@2
  int *v4; // edi@2
  int i; // eax@3

  v2 = this;
  if ( v > this->maximumSizeValue - 1 )
  {
    v3 = v + 1;
    v4 = (int *)operator new(4 * (v + 1));
    if ( v4 )
    {
      for ( i = 0; i < v2->maximumSizeValue; v4[i - 1] = v2->value[i - 1] )
      {
        if ( i >= v3 )
          break;
        ++i;
      }
      operator delete(v2->value);
      v2->value = v4;
      v2->maximumSizeValue = v3;
    }
  }
  return &v2->value[v];
}

//----- (004EA7C0) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::isRuleExecuting(TribeStrategyAIModule *this, int ruleNumber)
{
  int v2; // edx@1
  int v3; // eax@1

  v2 = this->executingRules.numberValue;
  v3 = 0;
  if ( v2 > 0 )
  {
    while ( v3 < this->executingRules.maximumSizeValue )
    {
      if ( this->executingRules.value[v3] == ruleNumber )
        return 1;
      if ( ++v3 >= v2 )
        return 0;
    }
  }
  return 0;
}

//----- (004EA810) --------------------------------------------------------
int __thiscall TribeStrategyAIModule::isRuleIdle(TribeStrategyAIModule *this, int ruleNumber)
{
  int v2; // edx@1
  int v3; // eax@1

  v2 = this->idleRules.numberValue;
  v3 = 0;
  if ( v2 > 0 )
  {
    while ( v3 < this->idleRules.maximumSizeValue )
    {
      if ( this->idleRules.value[v3] == ruleNumber )
        return 1;
      if ( ++v3 >= v2 )
        return 0;
    }
  }
  return 0;
}

//----- (004E6E10) --------------------------------------------------------
void __thiscall VictoryConditionRuleSystem::VictoryConditionRuleSystem(VictoryConditionRuleSystem *this)
{
  this->vfptr = (VictoryConditionRuleSystemVtbl *)&VictoryConditionRuleSystem::`vftable';
  this->sn[0] = 34;
  this->sn[1] = 0;
  this->sn[2] = 66;
  this->sn[3] = 2;
  this->sn[4] = 2;
  this->sn[5] = -1;
  this->sn[6] = -1;
  this->sn[7] = -1;
  this->sn[8] = -1;
  this->sn[9] = -1;
  this->sn[10] = -1;
  this->sn[11] = -1;
  this->sn[12] = -1;
  this->sn[13] = -1;
  this->sn[14] = -1;
  this->sn[15] = -1;
  this->sn[16] = 4;
  this->sn[17] = -1;
  this->sn[18] = 4;
  this->sn[19] = 50;
  this->sn[20] = 50;
  this->sn[21] = -1;
  this->sn[22] = 12;
  this->sn[23] = 10;
  this->sn[24] = 75;
  this->sn[25] = 1;
  this->sn[26] = 10;
  this->sn[27] = -1;
  this->sn[28] = 4;
  this->sn[29] = 85;
  this->sn[30] = 70;
  this->sn[31] = 75;
  this->sn[32] = 100;
  this->sn[33] = -1;
  this->sn[34] = 50;
  this->sn[35] = 0;
  this->sn[36] = 3;
  this->sn[37] = 0;
  this->sn[38] = 0;
  this->sn[39] = 0;
  this->sn[40] = 0;
  this->sn[41] = 4;
  this->sn[42] = 0;
  this->sn[43] = 1;
  this->sn[44] = 3;
  this->sn[45] = 0;
  this->sn[46] = 30;
  this->sn[47] = 1;
  this->sn[48] = 30;
  this->sn[49] = 3;
  this->sn[50] = 0;
  this->sn[51] = 0;
  this->sn[52] = 0;
  this->sn[53] = 0;
  this->sn[54] = 0;
  this->sn[55] = 0;
  this->sn[56] = 7;
  this->sn[57] = 3;
  this->sn[58] = 2;
  this->sn[59] = 1;
  this->sn[60] = 5;
  this->sn[61] = 1;
  this->sn[62] = 1;
  this->sn[63] = 2;
  this->sn[64] = 0;
  this->sn[65] = 0;
  this->sn[66] = 0;
  this->sn[67] = 0;
  this->sn[68] = 0;
  this->sn[69] = 0;
  this->sn[70] = 0;
  this->sn[71] = 1;
  this->sn[72] = 2;
  this->sn[73] = 12;
  this->sn[74] = 20;
  this->sn[75] = 3;
  this->sn[76] = 15;
  this->sn[77] = 50;
  this->sn[78] = 0;
  this->sn[79] = 0;
  this->sn[80] = 0;
  this->sn[81] = 0;
  this->sn[82] = 0;
  this->sn[83] = 0;
  this->sn[84] = 4;
  this->sn[85] = 2;
  this->sn[86] = 25;
  this->sn[87] = 100;
  this->sn[88] = 3;
  this->sn[89] = -25;
  this->sn[90] = 0;
  this->sn[91] = 100;
  this->sn[92] = 5;
  this->sn[93] = 1;
  this->sn[94] = 0;
  this->sn[95] = 0;
  this->sn[96] = 0;
  this->sn[97] = 0;
  this->sn[98] = 1;
  this->sn[99] = 10;
  this->sn[100] = 3;
  this->sn[101] = 1;
  this->sn[102] = 15;
  this->sn[103] = 0;
  this->sn[104] = 0;
  this->sn[105] = 0;
  this->sn[106] = -1;
  this->sn[107] = -1;
  this->sn[108] = -1;
  this->sn[109] = 0;
  this->sn[110] = 0;
  this->sn[111] = 0;
  this->sn[112] = 300;
  this->sn[113] = 0;
  this->sn[114] = 25;
  this->sn[115] = 10;
  this->sn[116] = 10;
  this->sn[117] = 0;
  this->sn[118] = 0;
  this->sn[119] = 0;
  this->sn[120] = 0;
  this->sn[121] = 0;
  this->sn[122] = 100;
  this->sn[123] = 0;
  this->sn[124] = 0;
  this->sn[125] = 0;
  this->sn[126] = 0;
  this->sn[127] = 0;
  this->sn[128] = -1;
  this->sn[129] = 0;
  this->sn[130] = 0;
  this->sn[131] = 3;
  this->sn[132] = 0;
  this->sn[133] = 0;
  this->sn[134] = 0;
  this->sn[135] = 1;
  this->sn[136] = 15;
  this->sn[137] = 0;
  this->sn[138] = 0;
  this->sn[139] = 0;
  this->sn[140] = 0;
  this->sn[141] = 0;
  this->sn[142] = 0;
  this->sn[143] = 1;
  this->sn[144] = 0;
  this->sn[145] = 10;
  this->sn[146] = 50;
  this->sn[147] = 10;
  this->sn[148] = 20;
  this->sn[149] = 40;
  this->sn[150] = -1;
  this->sn[151] = 3;
  this->sn[152] = 0;
  this->sn[153] = -1;
  this->sn[154] = -1;
  this->sn[155] = 10;
  this->sn[156] = 0;
  this->sn[157] = 0;
  this->sn[158] = 0;
  this->sn[159] = 0;
  this->sn[160] = 50;
  this->sn[161] = 2;
  this->sn[162] = 0;
  this->sn[163] = 7;
  this->sn[164] = 10;
  this->sn[165] = 25;
  this->sn[166] = 7;
  this->sn[167] = 2;
  this->sn[168] = 50;
  this->sn[169] = 10;
  this->sn[170] = 200;
  this->sn[171] = 250;
  this->sn[172] = 150;
  this->sn[173] = 200;
  this->sn[174] = 2;
  this->sn[175] = -1;
  this->sn[176] = 0;
  this->sn[177] = -1;
  this->sn[178] = 10;
  this->sn[179] = 30;
  this->sn[180] = 1;
  this->sn[181] = 1;
  this->sn[182] = 0;
  this->sn[183] = 0;
  this->sn[184] = 20;
  this->sn[185] = 50;
  this->sn[186] = 0;
  this->sn[187] = 0;
  this->sn[188] = 1;
  this->sn[189] = 50;
  this->sn[190] = 3000;
  this->sn[191] = 2000;
  this->sn[192] = 1500;
  this->sn[193] = 3000;
  this->sn[194] = 1;
  this->sn[195] = 25;
  this->sn[199] = 25;
  this->sn[202] = 25;
  this->sn[196] = 1;
  this->sn[197] = 120;
  this->sn[198] = 50;
  this->sn[200] = 50;
  this->sn[201] = 0;
  this->sn[203] = 1;
  this->sn[204] = 5;
  this->sn[205] = 1;
  this->sn[206] = 1;
  this->sn[207] = 1;
  this->sn[208] = 0;
  this->sn[209] = 0;
  this->sn[210] = 0;
  this->sn[211] = 1;
  this->sn[212] = 0;
  this->sn[213] = 0;
  this->sn[214] = 0;
  this->sn[215] = 1;
  this->sn[216] = 50;
  this->sn[217] = 0;
  this->sn[218] = 100;
  this->sn[219] = 100;
  this->sn[220] = 8;
  this->sn[221] = 3;
  this->sn[222] = 10;
  this->sn[223] = 0;
  this->sn[224] = 0;
  this->sn[225] = 1;
}
// 575678: using guessed type int (__thiscall *VictoryConditionRuleSystem::`vftable')(void *Memory, unsigned int __flags);

//----- (004E7410) --------------------------------------------------------
VictoryConditionRuleSystem *__thiscall VictoryConditionRuleSystem::`scalar deleting destructor'(VictoryConditionRuleSystem *this, unsigned int __flags)
{
  VictoryConditionRuleSystem *v2; // esi@1

  v2 = this;
  VictoryConditionRuleSystem::~VictoryConditionRuleSystem(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E7430) --------------------------------------------------------
void __thiscall VictoryConditionRuleSystem::~VictoryConditionRuleSystem(VictoryConditionRuleSystem *this)
{
  this->vfptr = (VictoryConditionRuleSystemVtbl *)&VictoryConditionRuleSystem::`vftable';
}
// 575678: using guessed type int (__thiscall *VictoryConditionRuleSystem::`vftable')(void *Memory, unsigned int __flags);

//----- (004E7440) --------------------------------------------------------
int __thiscall VictoryConditionRuleSystem::loadRules(VictoryConditionRuleSystem *this, char *rName)
{
  VictoryConditionRuleSystem *v2; // ebx@1
  FILE *v3; // eax@4
  FILE *v4; // esi@4
  int result; // eax@20
  char commentTemp1; // [sp+12h] [bp-10Ah]@6
  char commentTemp2; // [sp+13h] [bp-109h]@6
  int ruleIndex; // [sp+14h] [bp-108h]@14
  int ruleValue; // [sp+18h] [bp-104h]@14
  char temp[256]; // [sp+1Ch] [bp-100h]@4

  v2 = this;
  if ( strcmp(rName, aNone_2)
    && rName
    && strlen(rName) != 0
    && (sprintf(temp, aS_2, rName), v3 = fopen(temp, Mode), (v4 = v3) != 0) )
  {
    if ( fgets(temp, 256, v3) )
    {
      do
      {
        sscanf(temp, aCC, &commentTemp1, &commentTemp2);
        if ( (commentTemp1 != 47 || commentTemp2 != 47)
          && (commentTemp1 != 68 || commentTemp2 != 69)
          && (commentTemp1 != 86 || commentTemp2 != 67) )
        {
          if ( commentTemp1 == 69 && commentTemp2 == 78 )
            break;
          sscanf(temp, aDD_4, &ruleIndex, &ruleValue);
          if ( ruleIndex >= 0 && ruleIndex < 226 )
            v2->sn[ruleIndex] = ruleValue;
        }
      }
      while ( fgets(temp, 256, v4) );
    }
    fclose(v4);
    if ( strstr(rName, SubStr) )
      _unlink(rName);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004E75D0) --------------------------------------------------------
void __thiscall VictoryConditionRuleSystem::setRule(VictoryConditionRuleSystem *this, int ruleIndex, int ruleValue)
{
  if ( ruleIndex >= 0 && ruleIndex < 226 )
    this->sn[ruleIndex] = ruleValue;
}

//----- (004E75F0) --------------------------------------------------------
int __thiscall VictoryConditionRuleSystem::rule(VictoryConditionRuleSystem *this, int ruleIndex)
{
  int result; // eax@3

  if ( ruleIndex < 0 || ruleIndex >= 226 )
    result = -1;
  else
    result = this->sn[ruleIndex];
  return result;
}

//----- (004E7610) --------------------------------------------------------
int __stdcall VictoryConditionRuleSystem::evaluateAsInProgress(TRIBE_Player *p, int ruleNumber)
{
  return 0;
}

//----- (004E7620) --------------------------------------------------------
int __stdcall VictoryConditionRuleSystem::evaluateAsNonInProgress(TRIBE_Player *p, int ruleNumber)
{
  int result; // eax@2

  switch ( ruleNumber )
  {
    case 1:
    case 2:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
      result = -2;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (004E7690) --------------------------------------------------------
int __thiscall VictoryConditionRuleSystem::execute(VictoryConditionRuleSystem *this, TRIBE_Player *p, int vcNumber, int ruleNumber)
{
  VictoryConditionRuleSystem *v4; // esi@1
  TRIBE_Player *v5; // edi@4
  int result; // eax@42
  int v7; // [sp-8h] [bp-10h]@4
  int v8; // [sp-4h] [bp-Ch]@4

  v4 = this;
  if ( vcNumber < 0 || vcNumber >= 13 )
  {
LABEL_43:
    result = 0;
  }
  else
  {
    switch ( ruleNumber )
    {
      case 1:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 0, this->sn[0]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 1, v4->sn[1]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 2, v4->sn[2]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 3, v4->sn[3]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 4, v4->sn[4]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 5, v4->sn[5]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 35, v4->sn[35]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 100, v4->sn[100]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 225, v4->sn[225]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 117, v4->sn[117]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 118, v4->sn[118]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 119, v4->sn[119]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 120, v4->sn[120]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 156, v4->sn[156]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 159, v4->sn[159]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 158, v4->sn[158]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 157, v4->sn[157]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 160, v4->sn[160]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 142, v4->sn[142]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 148, v4->sn[148]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 149, v4->sn[149]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 203, v4->sn[203]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 163, v4->sn[163]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 164, v4->sn[164]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 166, v4->sn[166]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 165, v4->sn[165]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 167, v4->sn[167]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 179, v4->sn[179]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 180, v4->sn[180]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 205, v4->sn[205]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 207, v4->sn[207]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 206, v4->sn[206]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 220, v4->sn[220]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 222, v4->sn[222]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 208, v4->sn[208]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 209, v4->sn[209]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 210, v4->sn[210]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 211, v4->sn[211]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 223, v4->sn[223]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 212, v4->sn[212]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 213, v4->sn[213]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 214, v4->sn[214]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 224, v4->sn[224]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 169, v4->sn[169]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 170, v4->sn[170]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 171, v4->sn[171]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 172, v4->sn[172]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 173, v4->sn[173]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 190, v4->sn[190]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 191, v4->sn[191]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 192, v4->sn[192]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 193, v4->sn[193]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 174, v4->sn[174]);
        v8 = v4->sn[204];
        v7 = 204;
        break;
      case 2:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 16, this->sn[16]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 26, v4->sn[26]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 36, v4->sn[36]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 37, v4->sn[37]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 93, v4->sn[93]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 94, v4->sn[94]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 98, v4->sn[98]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 121, v4->sn[121]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 131, v4->sn[131]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 143, v4->sn[143]);
        v8 = v4->sn[162];
        v7 = 162;
        break;
      case 12:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 18, this->sn[18]);
        goto LABEL_42;
      case 13:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 19, this->sn[19]);
        goto LABEL_42;
      case 14:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 20, this->sn[20]);
        goto LABEL_42;
      case 16:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 22, this->sn[22]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 72, v4->sn[72]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 57, v4->sn[57]);
        v8 = v4->sn[92];
        v7 = 92;
        break;
      case 17:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 23, this->sn[23]);
        goto LABEL_42;
      case 18:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 24, this->sn[24]);
        goto LABEL_42;
      case 21:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 25, this->sn[25]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 28, v4->sn[28]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 38, v4->sn[38]);
        v8 = v4->sn[39];
        v7 = 39;
        break;
      case 22:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 29, this->sn[29]);
        goto LABEL_42;
      case 23:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 32, this->sn[32]);
        v8 = v4->sn[145];
        v7 = 145;
        break;
      case 24:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 34, this->sn[34]);
        goto LABEL_42;
      case 25:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 40, this->sn[40]);
        v8 = v4->sn[75];
        v7 = 75;
        break;
      case 26:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 41, this->sn[41]);
        goto LABEL_42;
      case 27:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 43, this->sn[43]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 44, v4->sn[44]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 42, v4->sn[42]);
        v8 = v4->sn[45];
        v7 = 45;
        break;
      case 28:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 30, this->sn[30]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 31, v4->sn[31]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 91, v4->sn[91]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 95, v4->sn[95]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 96, v4->sn[96]);
        v8 = v4->sn[97];
        v7 = 97;
        break;
      case 29:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 46, this->sn[46]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 102, v4->sn[102]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 47, v4->sn[47]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 103, v4->sn[103]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 104, v4->sn[104]);
        v8 = v4->sn[134];
        v7 = 134;
        break;
      case 30:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 48, this->sn[48]);
        goto LABEL_42;
      case 31:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 49, this->sn[49]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 135, v4->sn[135]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 136, v4->sn[136]);
        v8 = v4->sn[200];
        v7 = 200;
        break;
      case 32:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 50, this->sn[50]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 51, v4->sn[51]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 52, v4->sn[52]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 53, v4->sn[53]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 54, v4->sn[54]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 55, v4->sn[55]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 56, v4->sn[56]);
        v8 = v4->sn[70];
        v7 = 70;
        break;
      case 33:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 58, this->sn[58]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 59, v4->sn[59]);
        v8 = v4->sn[60];
        v7 = 60;
        break;
      case 34:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 61, this->sn[61]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 62, v4->sn[62]);
        v8 = v4->sn[63];
        v7 = 63;
        break;
      case 35:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 64, this->sn[64]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 65, v4->sn[65]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 66, v4->sn[66]);
        v8 = v4->sn[216];
        v7 = 216;
        break;
      case 36:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 67, this->sn[67]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 68, v4->sn[68]);
        v8 = v4->sn[69];
        v7 = 69;
        break;
      case 37:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 71, this->sn[71]);
        goto LABEL_42;
      case 38:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 73, this->sn[73]);
        v8 = v4->sn[74];
        v7 = 74;
        break;
      case 39:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 76, this->sn[76]);
        goto LABEL_42;
      case 40:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 77, this->sn[77]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 78, v4->sn[78]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 79, v4->sn[79]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 80, v4->sn[80]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 81, v4->sn[81]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 82, v4->sn[82]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 83, v4->sn[83]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 89, v4->sn[89]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 90, v4->sn[90]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 106, v4->sn[106]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 107, v4->sn[107]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 108, v4->sn[108]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 109, v4->sn[109]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 110, v4->sn[110]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 111, v4->sn[111]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 122, v4->sn[122]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 123, v4->sn[123]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 144, v4->sn[144]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 184, v4->sn[184]);
        v8 = v4->sn[185];
        v7 = 185;
        break;
      case 41:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 84, this->sn[84]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 85, v4->sn[85]);
        v8 = v4->sn[137];
        v7 = 137;
        break;
      case 42:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 86, this->sn[86]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 87, v4->sn[87]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 202, v4->sn[202]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 150, v4->sn[150]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 151, v4->sn[151]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 152, v4->sn[152]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 161, v4->sn[161]);
        v8 = v4->sn[168];
        v7 = 168;
        break;
      case 43:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 88, this->sn[88]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 101, v4->sn[101]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 155, v4->sn[155]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 175, v4->sn[175]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 176, v4->sn[176]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 177, v4->sn[177]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 181, v4->sn[181]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 182, v4->sn[182]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 183, v4->sn[183]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 186, v4->sn[186]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 187, v4->sn[187]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 194, v4->sn[194]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 196, v4->sn[196]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 197, v4->sn[197]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 188, v4->sn[188]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 195, v4->sn[195]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 189, v4->sn[189]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 198, v4->sn[198]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 199, v4->sn[199]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 215, v4->sn[215]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 217, v4->sn[217]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 218, v4->sn[218]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 219, v4->sn[219]);
        v8 = v4->sn[221];
        v7 = 221;
        break;
      case 44:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 99, this->sn[99]);
        goto LABEL_42;
      case 45:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 105, this->sn[105]);
        goto LABEL_42;
      case 46:
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 112, this->sn[112]);
        goto LABEL_42;
      case 47:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 113, this->sn[113]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 114, v4->sn[114]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 115, v4->sn[115]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 116, v4->sn[116]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 146, v4->sn[146]);
        v8 = v4->sn[147];
        v7 = 147;
        break;
      case 48:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 124, this->sn[124]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 125, v4->sn[125]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 126, v4->sn[126]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 127, v4->sn[127]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 128, v4->sn[128]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 129, v4->sn[129]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 130, v4->sn[130]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 132, v4->sn[132]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 133, v4->sn[133]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 178, v4->sn[178]);
        v8 = v4->sn[201];
        v7 = 201;
        break;
      case 49:
        v5 = p;
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 138, this->sn[138]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 139, v4->sn[139]);
        TribeTacticalAIModule::setStrategicNumber(&p->playerAI->tacticalAI, 140, v4->sn[140]);
        v8 = v4->sn[141];
        v7 = 141;
        break;
      default:
        goto LABEL_43;
    }
    TribeTacticalAIModule::setStrategicNumber(&v5->playerAI->tacticalAI, v7, v8);
LABEL_42:
    result = 1;
  }
  return result;
}

//----- (004E8D10) --------------------------------------------------------
int __stdcall VictoryConditionRuleSystem::stopExecution(TRIBE_Player *p, int ruleNumber)
{
  return 0;
}

//----- (004E8D20) --------------------------------------------------------
void __thiscall VictoryConditionRuleSystem::modifyForDifficultyLevel(VictoryConditionRuleSystem *this, int dL)
{
  VictoryConditionRuleSystem *v2; // esi@1
  signed int v3; // ebx@2
  signed int v4; // edi@2
  signed int v5; // ebp@2
  signed __int64 v6; // rax@9
  signed __int64 v7; // rax@12
  signed __int64 v8; // rax@15
  int v9; // edx@17
  signed int v10; // eax@17
  signed __int64 v11; // rax@18
  signed __int64 v12; // rax@21
  signed __int64 v13; // rax@24
  signed __int64 v14; // rax@27
  signed __int64 v15; // rax@30
  signed __int64 v16; // rax@33
  signed __int64 v17; // rax@36
  signed __int64 v18; // rax@39
  signed __int64 v19; // rax@42
  signed __int64 v20; // rax@45
  signed __int64 v21; // rax@48
  float scale1; // [sp+10h] [bp-Ch]@2
  float scale3; // [sp+14h] [bp-8h]@2
  signed int v24; // [sp+18h] [bp-4h]@23

  v2 = this;
  if ( dL )
  {
    v3 = 0;
    v4 = 0;
    v5 = 0;
    scale1 = 1.0;
    scale3 = 1.0;
    switch ( dL )
    {
      case 1:
        if ( RGE_Base_Game::scenarioGame(rge_base_game) == 1 )
        {
          scale1 = 0.80000001;
          v3 = 30;
          scale3 = 0.80000001;
          v4 = 120;
          v5 = 1;
        }
        goto LABEL_8;
      case 2:
        scale1 = 0.60000002;
        v3 = 60;
        scale3 = 0.60000002;
        v4 = 240;
        v5 = 2;
        goto LABEL_8;
      case 3:
        scale1 = 0.40000001;
        v3 = 90;
        scale3 = 0.40000001;
        v5 = 3;
        v4 = RGE_Base_Game::scenarioGame(rge_base_game) != 1 ? 900 : 360;
        goto LABEL_8;
      case 4:
        scale1 = 0.2;
        v3 = 120;
        scale3 = 0.2;
        v5 = 4;
        v4 = RGE_Base_Game::scenarioGame(rge_base_game) != 1 ? 1260 : 480;
LABEL_8:
        if ( v2->sn[36] > 0 )
        {
          v6 = (signed __int64)((double)v2->sn[36] * scale1);
          v2->sn[36] = v6;
          if ( !(_DWORD)v6 )
            v2->sn[36] = 1;
        }
        if ( v2->sn[16] > 0 )
        {
          v7 = (signed __int64)((double)v2->sn[16] * scale1);
          v2->sn[16] = v7;
          if ( !(_DWORD)v7 )
            v2->sn[16] = 1;
        }
        if ( v2->sn[26] > 0 )
        {
          v8 = (signed __int64)((double)v2->sn[26] * scale1);
          v2->sn[26] = v8;
          if ( !(_DWORD)v8 )
            v2->sn[26] = 1;
        }
        v9 = v3 + v2->sn[48];
        v2->sn[46] += v3;
        v10 = v2->sn[19];
        v2->sn[48] = v9;
        if ( v10 > 0 )
        {
          v11 = (signed __int64)((double)v10 * scale3);
          v2->sn[19] = v11;
          if ( !(_DWORD)v11 )
            v2->sn[19] = 1;
        }
        if ( v2->sn[20] > 0 )
        {
          v12 = (signed __int64)((double)v2->sn[20] * scale3);
          v2->sn[20] = v12;
          if ( !(_DWORD)v12 )
            v2->sn[20] = 1;
        }
        v24 = v2->sn[25];
        v2->sn[104] += v4;
        if ( v24 > 0 )
        {
          v13 = (signed __int64)((double)v24 * scale1);
          v2->sn[25] = v13;
          if ( !(_DWORD)v13 )
            v2->sn[25] = 1;
        }
        if ( v2->sn[28] > 0 )
        {
          v14 = (signed __int64)((double)v2->sn[28] * scale1);
          v2->sn[28] = v14;
          if ( !(_DWORD)v14 )
            v2->sn[28] = 1;
        }
        if ( v2->sn[38] > 0 )
        {
          v15 = (signed __int64)((double)v2->sn[38] * scale1);
          v2->sn[38] = v15;
          if ( !(_DWORD)v15 )
            v2->sn[38] = 1;
        }
        if ( v2->sn[58] > 0 )
        {
          v16 = (signed __int64)((double)v2->sn[58] * scale1);
          v2->sn[58] = v16;
          if ( !(_DWORD)v16 )
            v2->sn[58] = 1;
        }
        if ( v2->sn[59] > 0 )
        {
          v17 = (signed __int64)((double)v2->sn[59] * scale1);
          v2->sn[59] = v17;
          if ( !(_DWORD)v17 )
            v2->sn[59] = 1;
        }
        if ( v2->sn[60] > 0 )
        {
          v18 = (signed __int64)((double)v2->sn[60] * scale1);
          v2->sn[60] = v18;
          if ( !(_DWORD)v18 )
            v2->sn[60] = 1;
        }
        if ( v2->sn[67] > 0 )
        {
          v19 = (signed __int64)((double)v2->sn[67] * scale1);
          v2->sn[67] = v19;
          if ( !(_DWORD)v19 )
            v2->sn[67] = 1;
        }
        if ( v2->sn[68] > 0 )
        {
          v20 = (signed __int64)((double)v2->sn[68] * scale1);
          v2->sn[68] = v20;
          if ( !(_DWORD)v20 )
            v2->sn[68] = 1;
        }
        if ( v2->sn[69] > 0 )
        {
          v21 = (signed __int64)((double)v2->sn[69] * scale1);
          v2->sn[69] = v21;
          if ( !(_DWORD)v21 )
            v2->sn[69] = 1;
        }
        v2->sn[88] += v5;
        v2->sn[103] = dL <= 3;
        break;
      default:
        return;
    }
  }
}
