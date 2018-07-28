
/**
 * @file    Engine\RGE\AiMainDecisionModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (0040CDF0) --------------------------------------------------------
void __thiscall MainDecisionAIModule::MainDecisionAIModule(MainDecisionAIModule *this, void *pW, int playerID, RGE_Player *plyr)
{
  MainDecisionAIModule *v4; // esi@1

  v4 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aMainDecisionAi, 1000, playerID, pW);
  v4->player = plyr;
  v4->objects.value = 0;
  v4->objects.numberValue = 0;
  v4->objects.desiredNumberValue = 0;
  v4->objects.maximumSizeValue = 0;
  v4->vfptr = (AIModuleVtbl *)&MainDecisionAIModule::`vftable';
}
// 56E8D8: using guessed type int (__thiscall *MainDecisionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040CE70) --------------------------------------------------------
MainDecisionAIModule *__thiscall MainDecisionAIModule::`scalar deleting destructor'(MainDecisionAIModule *this, unsigned int __flags)
{
  MainDecisionAIModule *v2; // esi@1

  v2 = this;
  MainDecisionAIModule::~MainDecisionAIModule(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040CE90) --------------------------------------------------------
void __userpurge MainDecisionAIModule::MainDecisionAIModule(MainDecisionAIModule *this@<ecx>, RGE_Player *i@<ebp>, int playerID, RGE_Player *plyr, int infile)
{
  MainDecisionAIModule *v5; // esi@1
  int v6; // ST08_4@1
  int v7; // ecx@2
  int v8; // eax@2
  int v9; // ebx@7
  int *v10; // edi@7
  int j; // eax@8
  int numberUnits; // [sp+8h] [bp-14h]@1
  MainDecisionAIModule *v13; // [sp+Ch] [bp-10h]@1
  int v14; // [sp+18h] [bp-4h]@1
  int playerIDa; // [sp+20h] [bp+4h]@1

  v5 = this;
  v13 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aMainDecisionAi, 1000, playerID, 0);
  v14 = 0;
  v5->player = plyr;
  v5->objects.value = 0;
  v5->objects.numberValue = 0;
  v5->objects.desiredNumberValue = 0;
  v5->objects.maximumSizeValue = 0;
  v6 = infile;
  LOBYTE(v14) = 1;
  v5->vfptr = (AIModuleVtbl *)&MainDecisionAIModule::`vftable';
  rge_read((int)i, 0, v6, &numberUnits, 4);
  for( playerIDa = 0; playerIDa < numberUnits; ++playerIDa )
  {
    rge_read((int)i, 0, infile, &plyr, 4);
    v7 = v5->objects.numberValue;
    v8 = 0;
    for( i = plyr; v8 < v7; ++v8 )
    {
      if( v8 >= v5->objects.maximumSizeValue )
        break;
      if( (RGE_Player *)v5->objects.value[v8] == plyr )
        goto LABEL_13;
    }
    if( v7 > v5->objects.maximumSizeValue - 1 )
    {
      v9 = v7 + 1;
      v10 = (int *)operator new(4 * (v7 + 1));
      if( v10 )
      {
        for( j = 0; j < v5->objects.maximumSizeValue; v10[j - 1] = v5->objects.value[j - 1] )
        {
          if( j >= v9 )
            break;
          ++j;
        }
        operator delete(v5->objects.value);
        v5->objects.value = v10;
        v5->objects.maximumSizeValue = v9;
      }
    }
    v5->objects.value[v5->objects.numberValue++] = (int)i;
LABEL_13:
    ;
  }
}
// 56E8D8: using guessed type int (__thiscall *MainDecisionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040D020) --------------------------------------------------------
void __thiscall MainDecisionAIModule::~MainDecisionAIModule(MainDecisionAIModule *this)
{
  MainDecisionAIModule *v1; // esi@1
  int *v2; // eax@1

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&MainDecisionAIModule::`vftable';
  v2 = this->objects.value;
  if( v2 )
  {
    operator delete(v2);
    v1->objects.value = 0;
  }
  v1->objects.numberValue = 0;
  v1->objects.desiredNumberValue = 0;
  v1->objects.maximumSizeValue = 0;
  AIModule::~AIModule((AIModule *)&v1->vfptr);
}
// 56E8D8: using guessed type int (__thiscall *MainDecisionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040D0A0) --------------------------------------------------------
int __thiscall MainDecisionAIModule::save(MainDecisionAIModule *this, int outfile)
{
  MainDecisionAIModule *v2; // esi@1
  int i; // ebx@1
  int v4; // ebp@3
  int *v5; // edi@3
  int j; // eax@4
  int tempInt; // [sp+8h] [bp-4h]@1

  v2 = this;
  tempInt = this->objects.numberValue;
  rge_write(outfile, &tempInt, 4);
  for( i = 0; i < v2->objects.numberValue; ++i )
  {
    if( i > v2->objects.maximumSizeValue - 1 )
    {
      v4 = i + 1;
      v5 = (int *)operator new(4 * i + 4);
      if( v5 )
      {
        for( j = 0; j < v2->objects.maximumSizeValue; v5[j - 1] = v2->objects.value[j - 1] )
        {
          if( j >= v4 )
            break;
          ++j;
        }
        operator delete(v2->objects.value);
        v2->objects.value = v5;
        v2->objects.maximumSizeValue = v4;
      }
    }
    tempInt = v2->objects.value[i];
    rge_write(outfile, &tempInt, 4);
  }
  return 1;
}

//----- (0040D180) --------------------------------------------------------
RGE_Static_Object *__thiscall MainDecisionAIModule::addObject(MainDecisionAIModule *this, RGE_Static_Object *obj)
{
  RGE_Static_Object *result; // eax@1
  MainDecisionAIModule *v3; // esi@1
  int v4; // ecx@2
  int v5; // ebp@2
  int i; // eax@2
  int v7; // ebx@7
  int *v8; // edi@7
  int j; // eax@8

  result = obj;
  v3 = this;
  if( obj )
  {
    v4 = this->objects.numberValue;
    v5 = obj->id;
    for( i = 0; i < v4; ++i )
    {
      if( i >= v3->objects.maximumSizeValue )
        break;
      if( v3->objects.value[i] == v5 )
        goto LABEL_13;
    }
    if( v4 > v3->objects.maximumSizeValue - 1 )
    {
      v7 = v4 + 1;
      v8 = (int *)operator new(4 * (v4 + 1));
      if( v8 )
      {
        for( j = 0; j < v3->objects.maximumSizeValue; v8[j - 1] = v3->objects.value[j - 1] )
        {
          if( j >= v7 )
            break;
          ++j;
        }
        operator delete(v3->objects.value);
        v3->objects.value = v8;
        v3->objects.maximumSizeValue = v7;
      }
    }
    v3->objects.value[v3->objects.numberValue++] = v5;
LABEL_13:
    result = (RGE_Static_Object *)1;
  }
  return result;
}

//----- (0040D250) --------------------------------------------------------
int __thiscall MainDecisionAIModule::removeObject(MainDecisionAIModule *this, int id)
{
  int v2; // esi@1
  int v3; // eax@1
  int *v4; // edx@2
  int result; // eax@6
  int v6; // eax@9

  v2 = this->objects.maximumSizeValue;
  v3 = 0;
  if( v2 > 0 )
  {
    v4 = this->objects.value;
    do
    {
      if( *v4 == id )
        break;
      ++v3;
      ++v4;
    }
    while( v3 < v2 );
  }
  if( v3 < v2 )
  {
    if( v3 < v2 - 1 )
    {
      do
      {
        ++v3;
        this->objects.value[v3 - 1] = this->objects.value[v3];
      }
      while( v3 < this->objects.maximumSizeValue - 1 );
    }
    v6 = this->objects.numberValue - 1;
    this->objects.numberValue = v6;
    if( v6 < 0 )
      this->objects.numberValue = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040D2C0) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberObjects(MainDecisionAIModule *this)
{
  return this->objects.numberValue;
}

//----- (0040D2D0) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberObjectsWithAction(MainDecisionAIModule *this, int aid)
{
  MainDecisionAIModule *v2; // esi@1
  int v3; // ebx@1
  int v4; // ebp@3
  int *v5; // edi@3
  int i; // eax@4
  RGE_Static_Object *v7; // eax@8
  RGE_Static_Object *v8; // edi@8
  UnitAIModule *v9; // eax@10
  int count; // [sp+8h] [bp-4h]@1

  v2 = this;
  v3 = 0;
  for( count = 0; v3 < v2->objects.numberValue; ++v3 )
  {
    if( v3 > v2->objects.maximumSizeValue - 1 )
    {
      v4 = v3 + 1;
      v5 = (int *)operator new(4 * v3 + 4);
      if( v5 )
      {
        for( i = 0; i < v2->objects.maximumSizeValue; v5[i - 1] = v2->objects.value[i - 1] )
        {
          if( i >= v4 )
            break;
          ++i;
        }
        operator delete(v2->objects.value);
        v2->objects.value = v5;
        v2->objects.maximumSizeValue = v4;
      }
    }
    v7 = RGE_Game_World::object(v2->player->world, v2->objects.value[v3]);
    v8 = v7;
    if( v7 )
    {
      if( RGE_Static_Object::unitAI(v7) )
      {
        v9 = RGE_Static_Object::unitAI(v8);
        if( UnitAIModule::currentAction(v9) == aid )
          ++count;
      }
    }
  }
  return count;
}

//----- (0040D3B0) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberObjectsWithGroup(MainDecisionAIModule *this, int gid)
{
  MainDecisionAIModule *v2; // esi@1
  int v3; // ebx@1
  int v4; // ebp@3
  int *v5; // edi@3
  int i; // eax@4
  RGE_Static_Object *v7; // eax@8
  int count; // [sp+8h] [bp-4h]@1

  v2 = this;
  v3 = 0;
  for( count = 0; v3 < v2->objects.numberValue; ++v3 )
  {
    if( v3 > v2->objects.maximumSizeValue - 1 )
    {
      v4 = v3 + 1;
      v5 = (int *)operator new(4 * v3 + 4);
      if( v5 )
      {
        for( i = 0; i < v2->objects.maximumSizeValue; v5[i - 1] = v2->objects.value[i - 1] )
        {
          if( i >= v4 )
            break;
          ++i;
        }
        operator delete(v2->objects.value);
        v2->objects.value = v5;
        v2->objects.maximumSizeValue = v4;
      }
    }
    v7 = RGE_Game_World::object(v2->player->world, v2->objects.value[v3]);
    if( v7 && v7->master_obj->object_group == gid )
      ++count;
  }
  return count;
}

//----- (0040D480) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberObjectsWithActionAndTarget(MainDecisionAIModule *this, int action, int target)
{
  MainDecisionAIModule *v3; // esi@1
  int v4; // ebx@1
  int v5; // ebp@3
  int *v6; // edi@3
  int i; // eax@4
  RGE_Static_Object *v8; // eax@8
  RGE_Static_Object *v9; // edi@8
  UnitAIModule *v10; // eax@10
  UnitAIModule *v11; // eax@11
  int count; // [sp+8h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  for( count = 0; v4 < v3->objects.numberValue; ++v4 )
  {
    if( v4 > v3->objects.maximumSizeValue - 1 )
    {
      v5 = v4 + 1;
      v6 = (int *)operator new(4 * v4 + 4);
      if( v6 )
      {
        for( i = 0; i < v3->objects.maximumSizeValue; v6[i - 1] = v3->objects.value[i - 1] )
        {
          if( i >= v5 )
            break;
          ++i;
        }
        operator delete(v3->objects.value);
        v3->objects.value = v6;
        v3->objects.maximumSizeValue = v5;
      }
    }
    v8 = RGE_Game_World::object(v3->player->world, v3->objects.value[v4]);
    v9 = v8;
    if( v8 )
    {
      if( RGE_Static_Object::unitAI(v8) )
      {
        v10 = RGE_Static_Object::unitAI(v9);
        if( UnitAIModule::currentAction(v10) == action )
        {
          v11 = RGE_Static_Object::unitAI(v9);
          if( UnitAIModule::currentTarget(v11) == target )
            ++count;
        }
      }
    }
  }
  return count;
}

//----- (0040D580) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberObjectsWithTargetType(MainDecisionAIModule *this, int tt)
{
  MainDecisionAIModule *v2; // esi@1
  int v3; // ebx@1
  int v4; // ebp@3
  int *v5; // edi@3
  int i; // eax@4
  RGE_Static_Object *v7; // eax@8
  RGE_Static_Object *v8; // edi@8
  UnitAIModule *v9; // eax@10
  int count; // [sp+8h] [bp-4h]@1

  v2 = this;
  v3 = 0;
  for( count = 0; v3 < v2->objects.numberValue; ++v3 )
  {
    if( v3 > v2->objects.maximumSizeValue - 1 )
    {
      v4 = v3 + 1;
      v5 = (int *)operator new(4 * v3 + 4);
      if( v5 )
      {
        for( i = 0; i < v2->objects.maximumSizeValue; v5[i - 1] = v2->objects.value[i - 1] )
        {
          if( i >= v4 )
            break;
          ++i;
        }
        operator delete(v2->objects.value);
        v2->objects.value = v5;
        v2->objects.maximumSizeValue = v4;
      }
    }
    v7 = RGE_Game_World::object(v2->player->world, v2->objects.value[v3]);
    v8 = v7;
    if( v7 )
    {
      if( RGE_Static_Object::unitAI(v7) )
      {
        v9 = RGE_Static_Object::unitAI(v8);
        if( UnitAIModule::currentTargetType(v9) == tt )
          ++count;
      }
    }
  }
  return count;
}

//----- (0040D660) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberObjectsWithActionAndTargetType(MainDecisionAIModule *this, int action, int tt)
{
  MainDecisionAIModule *v3; // esi@1
  int v4; // ebx@1
  int v5; // ebp@3
  int *v6; // edi@3
  int i; // eax@4
  RGE_Static_Object *v8; // eax@8
  RGE_Static_Object *v9; // edi@8
  UnitAIModule *v10; // eax@10
  UnitAIModule *v11; // eax@11
  int count; // [sp+8h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  for( count = 0; v4 < v3->objects.numberValue; ++v4 )
  {
    if( v4 > v3->objects.maximumSizeValue - 1 )
    {
      v5 = v4 + 1;
      v6 = (int *)operator new(4 * v4 + 4);
      if( v6 )
      {
        for( i = 0; i < v3->objects.maximumSizeValue; v6[i - 1] = v3->objects.value[i - 1] )
        {
          if( i >= v5 )
            break;
          ++i;
        }
        operator delete(v3->objects.value);
        v3->objects.value = v6;
        v3->objects.maximumSizeValue = v5;
      }
    }
    v8 = RGE_Game_World::object(v3->player->world, v3->objects.value[v4]);
    v9 = v8;
    if( v8 )
    {
      if( RGE_Static_Object::unitAI(v8) )
      {
        v10 = RGE_Static_Object::unitAI(v9);
        if( UnitAIModule::currentAction(v10) == action )
        {
          v11 = RGE_Static_Object::unitAI(v9);
          if( UnitAIModule::currentTargetType(v11) == tt )
            ++count;
        }
      }
    }
  }
  return count;
}

//----- (0040D760) --------------------------------------------------------
RGE_Static_Object *__thiscall MainDecisionAIModule::object(MainDecisionAIModule *this, int id)
{
  return RGE_Game_World::object(this->player->world, id);
}

//----- (0040D780) --------------------------------------------------------
RGE_Static_Object *__thiscall MainDecisionAIModule::object(MainDecisionAIModule *this, int gameID, int typeID, int groupID, int currentAction, int canPerformActionID, int targetID, int targetType, int secondaryTargetType, int objectState, int maxAttributeAmount)
{
  MainDecisionAIModule *v11; // esi@1
  int v12; // ebp@1
  int v13; // ebx@5
  int *v14; // edi@5
  int j; // eax@6
  RGE_Static_Object *v16; // eax@10
  RGE_Static_Object *v17; // ebp@10
  UnitAIModule *v18; // eax@19
  int v19; // ebx@22
  int *v20; // edi@22
  int k; // eax@23
  UnitAIModule *v22; // eax@29
  UnitAIModule *v23; // eax@31
  RGE_Static_Object *result; // eax@37
  int i; // [sp+10h] [bp-4h]@1

  v11 = this;
  v12 = 0;
  i = 0;
  if( this->objects.numberValue <= 0 )
  {
    result = 0;
  }
  else
  {
    while( 1 )
    {
      if( v12 > v11->objects.maximumSizeValue - 1 )
      {
        v13 = v12 + 1;
        v14 = (int *)operator new(4 * v12 + 4);
        if( v14 )
        {
          for( j = 0; j < v11->objects.maximumSizeValue; v14[j - 1] = v11->objects.value[j - 1] )
          {
            if( j >= v13 )
              break;
            ++j;
          }
          operator delete(v11->objects.value);
          v11->objects.value = v14;
          v11->objects.maximumSizeValue = v13;
        }
      }
      v16 = RGE_Game_World::object(v11->player->world, v11->objects.value[v12]);
      v17 = v16;
      if( v16 )
      {
        if( RGE_Static_Object::unitAI(v16)
          && (gameID == -1 || v17->id == gameID)
          && (typeID == -1 || v17->master_obj->id == typeID)
          && (groupID == -1 || v17->master_obj->object_group == groupID) )
        {
          if( currentAction == -1
            || (v18 = RGE_Static_Object::unitAI(v17), UnitAIModule::currentAction(v18) == currentAction) )
          {
            if( canPerformActionID == -1 )
              goto LABEL_42;
            if( i > v11->objects.maximumSizeValue - 1 )
            {
              v19 = i + 1;
              v20 = (int *)operator new(4 * i + 4);
              if( v20 )
              {
                for( k = 0; k < v11->objects.maximumSizeValue; v20[k - 1] = v11->objects.value[k - 1] )
                {
                  if( k >= v19 )
                    break;
                  ++k;
                }
                operator delete(v11->objects.value);
                v11->objects.value = v20;
                v11->objects.maximumSizeValue = v19;
              }
            }
            if( ((int (__thiscall *)(MainDecisionAIModule *, int, int))v11->vfptr[1].setHistoryFilename)(
                   v11,
                   v11->objects.value[i],
                   canPerformActionID) )
            {
LABEL_42:
              if( targetID == -1
                || (v22 = RGE_Static_Object::unitAI(v17), UnitAIModule::currentTarget(v22) == targetID) )
              {
                if( targetType == -1
                  || (v23 = RGE_Static_Object::unitAI(v17), UnitAIModule::currentTargetType(v23) == targetType) )
                {
                  if( (objectState == -1 || v17->object_state == objectState)
                    && (maxAttributeAmount == -1 || (double)maxAttributeAmount >= v17->attribute_amount_held) )
                  {
                    break;
                  }
                }
              }
            }
          }
        }
      }
      if( ++i >= v11->objects.numberValue )
        return 0;
      v12 = i;
    }
    result = v17;
  }
  return result;
}

//----- (0040D9D0) --------------------------------------------------------
RGE_Static_Object *__thiscall MainDecisionAIModule::object(MainDecisionAIModule *this, int gameID, int typeID, int groupID, int action1, int action2, int objectState)
{
  MainDecisionAIModule *v7; // esi@1
  int v8; // ebp@1
  int v9; // ebx@3
  int *v10; // edi@3
  int i; // eax@4
  RGE_Static_Object *v12; // eax@8
  RGE_Static_Object *v13; // edi@8
  UnitAIModule *v14; // eax@16
  UnitAIModule *v15; // eax@17
  RGE_Static_Object *result; // eax@21

  v7 = this;
  v8 = 0;
  if( this->objects.numberValue <= 0 )
  {
    result = 0;
  }
  else
  {
    while( 1 )
    {
      if( v8 > v7->objects.maximumSizeValue - 1 )
      {
        v9 = v8 + 1;
        v10 = (int *)operator new(4 * v8 + 4);
        if( v10 )
        {
          for( i = 0; i < v7->objects.maximumSizeValue; v10[i - 1] = v7->objects.value[i - 1] )
          {
            if( i >= v9 )
              break;
            ++i;
          }
          operator delete(v7->objects.value);
          v7->objects.value = v10;
          v7->objects.maximumSizeValue = v9;
        }
      }
      v12 = RGE_Game_World::object(v7->player->world, v7->objects.value[v8]);
      v13 = v12;
      if( v12 )
      {
        if( RGE_Static_Object::unitAI(v12)
          && (gameID == -1 || v13->id == gameID)
          && (typeID == -1 || v13->master_obj->id == typeID)
          && (groupID == -1 || v13->master_obj->object_group == groupID) )
        {
          v14 = RGE_Static_Object::unitAI(v13);
          if( UnitAIModule::currentAction(v14) != action1 )
          {
            v15 = RGE_Static_Object::unitAI(v13);
            if( UnitAIModule::currentAction(v15) != action2 && (objectState == -1 || v13->object_state == objectState) )
              break;
          }
        }
      }
      if( ++v8 >= v7->objects.numberValue )
        return 0;
    }
    result = v13;
  }
  return result;
}

//----- (0040DB20) --------------------------------------------------------
int __thiscall MainDecisionAIModule::objectGroupThatCanPerformAction(MainDecisionAIModule *this, int a)
{
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aErrorDIsAnUnre, a);
  return -1;
}

//----- (0040DB40) --------------------------------------------------------
int __stdcall MainDecisionAIModule::canPerformAction(int id, int t)
{
  return 0;
}

//----- (0040DB50) --------------------------------------------------------
int __thiscall MainDecisionAIModule::numberBusyObjects(MainDecisionAIModule *this)
{
  MainDecisionAIModule *v1; // esi@1
  int v2; // ebx@1
  int v3; // ebp@3
  int *v4; // edi@3
  int i; // eax@4
  RGE_Static_Object *v6; // eax@8
  RGE_Static_Object *v7; // edi@8
  UnitAIModule *v8; // eax@10
  int count; // [sp+8h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  for( count = 0; v2 < v1->objects.numberValue; ++v2 )
  {
    if( v2 > v1->objects.maximumSizeValue - 1 )
    {
      v3 = v2 + 1;
      v4 = (int *)operator new(4 * v2 + 4);
      if( v4 )
      {
        for( i = 0; i < v1->objects.maximumSizeValue; v4[i - 1] = v1->objects.value[i - 1] )
        {
          if( i >= v3 )
            break;
          ++i;
        }
        operator delete(v1->objects.value);
        v1->objects.value = v4;
        v1->objects.maximumSizeValue = v3;
      }
    }
    v6 = RGE_Game_World::object(v1->player->world, v1->objects.value[v2]);
    v7 = v6;
    if( v6 )
    {
      if( RGE_Static_Object::unitAI(v6) )
      {
        v8 = RGE_Static_Object::unitAI(v7);
        if( UnitAIModule::currentAction(v8) == -1 )
          ++count;
      }
    }
  }
  return count;
}

//----- (0040DC30) --------------------------------------------------------
RGE_Static_Object *__thiscall MainDecisionAIModule::mostDamaged(MainDecisionAIModule *this, int oGroup, int oType)
{
  MainDecisionAIModule *v3; // edi@1
  int v4; // ebp@1
  int v5; // ebx@3
  int *v6; // esi@3
  int i; // eax@4
  RGE_Static_Object *v8; // eax@8
  RGE_Static_Object *v9; // esi@8
  RGE_Master_Static_Object *v10; // eax@11
  int damagePercentage; // [sp+8h] [bp-Ch]@1
  RGE_Static_Object *mDB; // [sp+Ch] [bp-8h]@1

  v3 = this;
  v4 = 0;
  mDB = 0;
  for( damagePercentage = 0; v4 < v3->objects.numberValue; ++v4 )
  {
    if( v4 > v3->objects.maximumSizeValue - 1 )
    {
      v5 = v4 + 1;
      v6 = (int *)operator new(4 * v4 + 4);
      if( v6 )
      {
        for( i = 0; i < v3->objects.maximumSizeValue; v6[i - 1] = v3->objects.value[i - 1] )
        {
          if( i >= v5 )
            break;
          ++i;
        }
        operator delete(v3->objects.value);
        v3->objects.value = v6;
        v3->objects.maximumSizeValue = v5;
      }
    }
    v8 = RGE_Game_World::object(v3->player->world, v3->objects.value[v4]);
    v9 = v8;
    if( v8 )
    {
      if( RGE_Static_Object::unitAI(v8) )
      {
        if( v9->object_state )
        {
          v10 = v9->master_obj;
          if( v10->object_group == oGroup
            && (double)v10->hp > v9->hp
            && v9->vfptr->canRepair(v9) == 1
            && (oType == -1 || oType == v9->master_obj->id)
            && (signed int)(100 * (unsigned __int64)(signed __int64)((double)v9->master_obj->hp - v9->hp))
             / v9->master_obj->hp > damagePercentage )
          {
            mDB = v9;
            damagePercentage = (signed int)(100 * (unsigned __int64)(signed __int64)((double)v9->master_obj->hp - v9->hp))
                             / v9->master_obj->hp;
          }
        }
      }
    }
  }
  return mDB;
}
