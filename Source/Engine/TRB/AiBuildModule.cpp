
/**
 * @file    Engine\TRB\AiBuildModule.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D3A80) --------------------------------------------------------
void __thiscall TribeBuildAIModule::TribeBuildAIModule(TribeBuildAIModule *this, void *pW, int pID)
{
  TribeBuildAIModule *v3; // esi@1

  v3 = this;
  BuildAIModule::BuildAIModule((BuildAIModule *)&this->vfptr, pW, pID);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&TribeBuildAIModule::`vftable';
}
// 575440: using guessed type int (__thiscall *TribeBuildAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D3AB0) --------------------------------------------------------
TribeBuildAIModule *__thiscall TribeBuildAIModule::`vector deleting destructor'(TribeBuildAIModule *this, unsigned int __flags)
{
  TribeBuildAIModule *v2; // esi@1

  v2 = this;
  TribeBuildAIModule::~TribeBuildAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D3AD0) --------------------------------------------------------
void __thiscall TribeBuildAIModule::TribeBuildAIModule(TribeBuildAIModule *this, int pID, int infile)
{
  TribeBuildAIModule *v3; // esi@1

  v3 = this;
  BuildAIModule::BuildAIModule((BuildAIModule *)&this->vfptr, pID, infile);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&TribeBuildAIModule::`vftable';
}
// 575440: using guessed type int (__thiscall *TribeBuildAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D3B00) --------------------------------------------------------
void __thiscall TribeBuildAIModule::~TribeBuildAIModule(TribeBuildAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&TribeBuildAIModule::`vftable';
  BuildAIModule::~BuildAIModule((BuildAIModule *)&this->vfptr);
}
// 575440: using guessed type int (__thiscall *TribeBuildAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D3B10) --------------------------------------------------------
void __thiscall TribeBuildAIModule::setMainDecisionAI(TribeBuildAIModule *this, TribeMainDecisionAIModule *m)
{
  this->md = m;
}

//----- (004D3B20) --------------------------------------------------------
int __thiscall TribeBuildAIModule::loadBuildList(TribeBuildAIModule *this, char *lName, RGE_Player *player)
{
  TribeBuildAIModule *v3; // esi@1
  int v4; // eax@1
  int v5; // ecx@1
  int v6; // ebx@6
  int *v7; // edi@6
  int i; // eax@7
  int v9; // ecx@12
  int j; // eax@12
  int v11; // ebx@17
  int *v12; // edi@17
  int k; // eax@18
  int v14; // ecx@23
  int l; // eax@23
  int v16; // ebx@28
  int *v17; // edi@28
  int m; // eax@29

  v3 = this;
  v4 = 0;
  v5 = this->typesToIgnore.numberValue;
  if ( v5 > 0 )
  {
    do
    {
      if ( v4 >= v3->typesToIgnore.maximumSizeValue )
        break;
      if ( v3->typesToIgnore.value[v4] == 70 )
        goto LABEL_12;
      ++v4;
    }
    while ( v4 < v5 );
  }
  if ( v5 > v3->typesToIgnore.maximumSizeValue - 1 )
  {
    v6 = v5 + 1;
    v7 = (int *)operator new(4 * (v5 + 1));
    if ( v7 )
    {
      for ( i = 0; i < v3->typesToIgnore.maximumSizeValue; v7[i - 1] = v3->typesToIgnore.value[i - 1] )
      {
        if ( i >= v6 )
          break;
        ++i;
      }
      operator delete(v3->typesToIgnore.value);
      v3->typesToIgnore.value = v7;
      v3->typesToIgnore.maximumSizeValue = v6;
    }
  }
  v3->typesToIgnore.value[v3->typesToIgnore.numberValue++] = 70;
LABEL_12:
  v9 = v3->typesToIgnore.numberValue;
  for ( j = 0; j < v9; ++j )
  {
    if ( j >= v3->typesToIgnore.maximumSizeValue )
      break;
    if ( v3->typesToIgnore.value[j] == 103 )
      goto LABEL_23;
  }
  if ( v9 > v3->typesToIgnore.maximumSizeValue - 1 )
  {
    v11 = v9 + 1;
    v12 = (int *)operator new(4 * (v9 + 1));
    if ( v12 )
    {
      for ( k = 0; k < v3->typesToIgnore.maximumSizeValue; v12[k - 1] = v3->typesToIgnore.value[k - 1] )
      {
        if ( k >= v11 )
          break;
        ++k;
      }
      operator delete(v3->typesToIgnore.value);
      v3->typesToIgnore.value = v12;
      v3->typesToIgnore.maximumSizeValue = v11;
    }
  }
  v3->typesToIgnore.value[v3->typesToIgnore.numberValue++] = 103;
LABEL_23:
  v14 = v3->typesToIgnore.numberValue;
  for ( l = 0; l < v14; ++l )
  {
    if ( l >= v3->typesToIgnore.maximumSizeValue )
      break;
    if ( v3->typesToIgnore.value[l] == 68 )
      return BuildAIModule::loadBuildList((BuildAIModule *)&v3->vfptr, lName, player);
  }
  if ( v14 > v3->typesToIgnore.maximumSizeValue - 1 )
  {
    v16 = v14 + 1;
    v17 = (int *)operator new(4 * (v14 + 1));
    if ( v17 )
    {
      for ( m = 0; m < v3->typesToIgnore.maximumSizeValue; v17[m - 1] = v3->typesToIgnore.value[m - 1] )
      {
        if ( m >= v16 )
          break;
        ++m;
      }
      operator delete(v3->typesToIgnore.value);
      v3->typesToIgnore.value = v17;
      v3->typesToIgnore.maximumSizeValue = v16;
    }
  }
  v3->typesToIgnore.value[v3->typesToIgnore.numberValue++] = 68;
  return BuildAIModule::loadBuildList((BuildAIModule *)&v3->vfptr, lName, player);
}

//----- (004D3D60) --------------------------------------------------------
void __thiscall TribeBuildAIModule::initialize(TribeBuildAIModule *this)
{
  TribeBuildAIModule *v1; // edi@1
  signed int v2; // ebp@1
  BuildItem *v3; // esi@1
  char *v4; // ebx@1
  signed int v5; // ecx@35
  int v6; // ebx@36
  int v7; // esi@41
  signed int v8; // ebp@41
  signed int v9; // ecx@45
  int v10; // ebx@47
  int v11; // esi@52
  signed int v12; // ebp@52
  int v13; // ecx@56
  signed int v14; // esi@57
  int v15; // ebx@57
  int v16; // esi@62
  int v17; // ebp@62
  int v18; // esi@69
  int v19; // ebp@69
  int v20; // ecx@71
  signed int v21; // eax@71
  signed int v22; // ecx@71
  int v23; // eax@73
  int v24; // ebx@73
  int v25; // esi@74
  signed int v26; // ebp@74
  BuildItem *v27; // esi@85
  signed int v28; // ebp@85
  int v29; // ebx@85
  int v30; // eax@94
  int v31; // eax@100
  int v32; // ebx@100
  BaseItem *v33; // ebp@101
  int v34; // esi@101
  int v35; // eax@108
  int v36; // eax@109
  signed int v37; // ebx@111
  int v38; // esi@111
  signed int v39; // esi@114
  int v40; // eax@115
  int requiredPop; // [sp+10h] [bp-A8h]@1
  int requiredPopa; // [sp+10h] [bp-A8h]@85
  int requiredPopb; // [sp+10h] [bp-A8h]@102
  int bronzeAgeIndex; // [sp+14h] [bp-A4h]@1
  int count; // [sp+18h] [bp-A0h]@1
  int counta; // [sp+18h] [bp-A0h]@110
  int divisionSize; // [sp+1Ch] [bp-9Ch]@1
  int divisionSizea; // [sp+1Ch] [bp-9Ch]@100
  int ironAgeIndex; // [sp+20h] [bp-98h]@1
  int totalPercentage; // [sp+24h] [bp-94h]@1
  int totalPercentagea; // [sp+24h] [bp-94h]@100
  int dockCount; // [sp+28h] [bp-90h]@1
  int transportCount; // [sp+2Ch] [bp-8Ch]@1
  int fishingBoatCount; // [sp+30h] [bp-88h]@1
  int toolAgeIndex; // [sp+34h] [bp-84h]@1
  int warshipCount; // [sp+38h] [bp-80h]@1
  ResourceItem resourceCount; // [sp+3Ch] [bp-7Ch]@101
  int v58; // [sp+B4h] [bp-4h]@101

  v1 = this;
  v2 = -1;
  requiredPop = 0;
  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  dockCount = 0;
  fishingBoatCount = 0;
  transportCount = 0;
  warshipCount = 0;
  toolAgeIndex = -1;
  bronzeAgeIndex = -1;
  ironAgeIndex = -1;
  divisionSize = 0;
  count = 0;
  totalPercentage = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 )
        break;
      if ( BuildItem::buildCategory(v3) )
      {
        if ( BuildItem::buildCategory(v3) == 2 )
        {
          if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 13 )
          {
            ++fishingBoatCount;
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 17 || BaseItem::typeID((BaseItem *)&v3->vfptr) == 18 )
          {
            ++transportCount;
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 19 || BaseItem::typeID((BaseItem *)&v3->vfptr) == 250 )
          {
            ++warshipCount;
          }
        }
        else if ( BuildItem::buildCategory(v3) == 1 || BuildItem::buildCategory(v3) == 4 )
        {
          if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 101 )
          {
            toolAgeIndex = BaseItem::uniqueID((BaseItem *)&v3->vfptr);
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 102 )
          {
            v2 = BaseItem::uniqueID((BaseItem *)&v3->vfptr);
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 103 )
          {
            ironAgeIndex = BaseItem::uniqueID((BaseItem *)&v3->vfptr);
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 5 )
          {
            divisionSize = 1;
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 7 )
          {
            count = 1;
          }
          else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 8 )
          {
            totalPercentage = 1;
          }
        }
      }
      else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 70 )
      {
        ++requiredPop;
      }
      else if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 45 )
      {
        ++dockCount;
      }
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
    bronzeAgeIndex = v2;
  }
  if ( dockCount < TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 212)
    && TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 208) == 1 )
  {
    v5 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 212) - dockCount;
    if ( v2 == -1 )
      v6 = toolAgeIndex == -1 ? 10 : toolAgeIndex / v5;
    else
      v6 = v2 / v5;
    if ( v5 > 0 )
    {
      v7 = v6;
      v8 = v5;
      do
      {
        TribeBuildAIModule::insert(v1, 45, -1, v7);
        v7 += v6;
        --v8;
      }
      while ( v8 );
    }
  }
  if ( fishingBoatCount < TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 213)
    && TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 209) == 1 )
  {
    v9 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 213) - fishingBoatCount;
    if ( v9 > 0 )
    {
      if ( bronzeAgeIndex == -1 )
        v10 = toolAgeIndex == -1 ? 10 : toolAgeIndex / v9;
      else
        v10 = bronzeAgeIndex / v9;
      if ( v9 > 0 )
      {
        v11 = v10;
        v12 = v9;
        do
        {
          TribeBuildAIModule::insert(v1, 13, -1, v11);
          v11 += v10;
          --v12;
        }
        while ( v12 );
      }
    }
  }
  if ( transportCount < TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 214)
    && TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 210) == 1 )
  {
    v13 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 214) - transportCount;
    if ( toolAgeIndex == -1 )
    {
      if ( bronzeAgeIndex == -1 )
      {
        v15 = 10;
        v14 = 0;
      }
      else
      {
        v14 = -1;
        v15 = (v1->buildListLengthValue - bronzeAgeIndex) / (2 * v13);
      }
    }
    else
    {
      v14 = bronzeAgeIndex;
      v15 = (v1->buildListLengthValue - toolAgeIndex) / (2 * v13);
    }
    if ( v13 > 0 )
    {
      v16 = v15 + v14;
      v17 = v13;
      do
      {
        TribeBuildAIModule::insert(v1, 17, -1, v16);
        v16 += v15;
        --v17;
      }
      while ( v17 );
    }
    if ( !totalPercentage && ironAgeIndex != -1 )
      TribeBuildAIModule::insertResearch(v1, 8, ironAgeIndex + 2);
  }
  if ( warshipCount < TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 224)
    && TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 223) == 1 )
  {
    v18 = ironAgeIndex;
    v19 = bronzeAgeIndex;
    if ( ironAgeIndex != -1 || bronzeAgeIndex != -1 )
    {
      v20 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 224);
      v21 = ironAgeIndex;
      v22 = v20 - warshipCount;
      if ( ironAgeIndex == -1 )
        v21 = bronzeAgeIndex;
      v23 = v21 / v22;
      v24 = v23;
      if ( v22 > 0 )
      {
        v25 = v23;
        v26 = v22;
        do
        {
          TribeBuildAIModule::insertResearch(v1, 19, v25);
          v25 += v24;
          --v26;
        }
        while ( v26 );
        v18 = ironAgeIndex;
        v19 = bronzeAgeIndex;
      }
      if ( !divisionSize && v19 != -1 )
        TribeBuildAIModule::insertResearch(v1, 5, v19 + 5);
      if ( !count && v18 != -1 )
        TribeBuildAIModule::insertResearch(v1, 7, v18 + 5);
    }
  }
  if ( !requiredPop && TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 180) == 1 )
  {
    v27 = v1->buildList.next;
    v28 = 0;
    v29 = 0;
    for ( requiredPopa = 0; v27 != &v1->buildList; ++v28 )
    {
      if ( !v27 )
        break;
      if ( !BuildItem::buildCategory(v27) && BaseItem::typeID((BaseItem *)&v27->vfptr) == 109 )
        v29 += 4;
      if ( BuildItem::buildCategory(v27) == 2 )
        ++requiredPopa;
      if ( requiredPopa > v29 )
      {
        v30 = v28 <= 1 ? TribeBuildAIModule::insert(v1, 70, -1, 1) : TribeBuildAIModule::insert(v1, 70, -1, v28 - 1);
        if ( v30 == 1 )
          v29 += 4;
      }
      if ( v29 > TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 152) + 50 )
        break;
      v27 = v27->next;
    }
  }
  totalPercentagea = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 160);
  v31 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 155);
  v32 = v31 + 4;
  divisionSizea = v31 + 4;
  if ( totalPercentagea )
  {
    v33 = (BaseItem *)&v1->buildList.next->vfptr;
    ResourceItem::ResourceItem(&resourceCount, 4);
    v34 = 0;
    v58 = 0;
    ResourceItem::setAllValues(&resourceCount, 0);
    if ( (BuildItem *)v33 != &v1->buildList )
    {
      requiredPopb = 0;
      do
      {
        if ( !v33 )
          break;
        if ( BuildItem::buildCategory((BuildItem *)v33) == 6 )
        {
          v33 = (BaseItem *)v33[1].vfptr;
          ++v34;
        }
        else
        {
          if ( BuildItem::buildCategory((BuildItem *)v33) == 1 || BuildItem::buildCategory((BuildItem *)v33) == 4 )
          {
            v36 = BaseItem::typeID(v33);
            TRIBE_Player::researchCost(v1->md->aiPlayer, v36, -1, &resourceCount, 1);
          }
          else
          {
            v35 = BaseItem::typeID(v33);
            TRIBE_Player::objectCost(v1->md->aiPlayer, v35, -1, &resourceCount, 1);
          }
          counta = v34 + 1;
          if ( v34 + 1 >= v32 )
          {
            v37 = 0;
            v38 = 0;
            do
              v37 += ResourceItem::value(&resourceCount, v38++);
            while ( v38 < 4 );
            if ( v37 > 0 )
            {
              v39 = 0;
              do
              {
                v40 = ResourceItem::value(&resourceCount, v39);
                TribeBuildAIModule::insertGathererPercentage(v1, v39++, totalPercentagea * v40 / v37, requiredPopb);
              }
              while ( v39 < 4 );
              ResourceItem::setAllValues(&resourceCount, 0);
              counta = 0;
              requiredPopb += divisionSizea;
            }
          }
          v33 = (BaseItem *)v33[1].vfptr;
          v34 = counta;
          v32 = divisionSizea;
        }
      }
      while ( (BuildItem *)v33 != &v1->buildList );
    }
    v58 = -1;
    ResourceItem::~ResourceItem(&resourceCount);
  }
}

//----- (004D4460) --------------------------------------------------------
void __thiscall TribeBuildAIModule::skipNextBuildListItem(TribeBuildAIModule *this)
{
  TribeBuildAIModule *v1; // edi@1
  BuildItem *v2; // esi@1
  char *v3; // ebx@1
  int v4; // ebp@6
  int v5; // eax@10
  int v6; // edi@10

  v1 = this;
  v2 = this->buildList.next;
  v3 = (char *)&this->buildList;
  if ( v2 != &this->buildList )
  {
    while ( v2 )
    {
      if ( !BuildItem::built(v2) && !BuildItem::inProgress(v2) && BaseItem::skip((BaseItem *)&v2->vfptr) != 1 )
      {
        v4 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 177);
        if ( BaseItem::typeID((BaseItem *)&v2->vfptr) != v4 || BuildItem::buildCategory(v2) )
        {
          v5 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 114);
          BuildItem::setBuildAttempts(v2, v5);
          BaseItem::setSkip((BaseItem *)&v2->vfptr, 1);
          BuildItem::incrementSkipCycles(v2);
          v6 = TribeTacticalAIModule::strategicNumber(&v1->md->tacticalAI, 146);
          if ( BuildItem::skipCycles(v2) == v6 )
            BuildItem::setPermanentSkip(v2, 1);
          return;
        }
      }
      v2 = v2->next;
      if ( (char *)v2 == v3 )
        return;
    }
  }
}

//----- (004D4540) --------------------------------------------------------
BuildItem *__thiscall TribeBuildAIModule::nextBuildableItem(TribeBuildAIModule *this, int category)
{
  TribeBuildAIModule *v2; // edi@1
  void (__thiscall *v3)(AIModule *); // esi@1
  int v4; // eax@1
  BuildItem *v5; // esi@1
  int v6; // eax@6
  int v7; // eax@7
  signed int v8; // ebp@14
  int v9; // ebx@14
  int v10; // ST24_4@48
  int v11; // eax@48
  int v12; // ebx@52
  int v13; // eax@56
  ResourceItem *v14; // ecx@61
  const char *v15; // eax@64
  const char *v16; // eax@64
  const char *v18; // eax@65
  const char *v19; // eax@65
  int v20; // eax@69
  int v21; // eax@69
  int v22; // eax@82
  float *v23; // eax@83
  int v24; // ebx@93
  int v25; // ebx@98
  int v26; // eax@103
  int v27; // eax@104
  int v28; // eax@108
  int v29; // eax@110
  int v30; // eax@112
  int v31; // eax@113
  RGE_Static_Object *v32; // eax@117
  int v33; // eax@118
  int count; // [sp+18h] [bp-100h]@1
  int numGranaries; // [sp+1Ch] [bp-FCh]@1
  int numStoragePits; // [sp+20h] [bp-F8h]@1
  int realCount; // [sp+24h] [bp-F4h]@1
  int numHouses; // [sp+28h] [bp-F0h]@1
  ResourceItem itemCost; // [sp+2Ch] [bp-ECh]@65
  ResourceItem ri; // [sp+9Ch] [bp-7Ch]@61
  int v41; // [sp+114h] [bp-4h]@61

  v2 = this;
  v3 = this->vfptr[1].toggleLogHistory;
  numStoragePits = ((int (__stdcall *)(signed int, _DWORD))v3)(103, 0);
  numGranaries = ((int (__thiscall *)(TribeBuildAIModule *, signed int, _DWORD))v3)(v2, 68, 0);
  v4 = ((int (__thiscall *)(TribeBuildAIModule *, signed int, _DWORD))v3)(v2, 70, 0);
  v5 = v2->buildList.next;
  numHouses = v4;
  realCount = 0;
  count = 0;
  if ( TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 115) >= 0 )
  {
    while ( 1 )
    {
      if ( v5 == &v2->buildList || !v5 )
        return 0;
      if ( BuildItem::buildCategory(v5) == 1 || BuildItem::buildCategory(v5) == 4 )
      {
        v6 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        if ( TribeBuildAIModule::isAgeResearch(v6) == 1 )
        {
          v7 = BaseItem::typeID((BaseItem *)&v5->vfptr);
          switch ( (unsigned __int8)TRIBE_Player::researchState(v2->md->aiPlayer, v7) )
          {
            case 0u:
            case 1u:
              BuildItem::setBuilt(v5, 0);
              goto LABEL_11;
            case 2u:
              BuildItem::setBuilt(v5, 0);
              BuildItem::setInProgress(v5, 1);
              break;
            case 3u:
              BuildItem::setBuilt(v5, 1);
LABEL_11:
              BuildItem::setInProgress(v5, 0);
              break;
            default:
              break;
          }
        }
      }
      if ( BuildItem::built(v5) || BuildItem::inProgress(v5) )
        goto LABEL_58;
      ++realCount;
      v8 = 1;
      v9 = TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 161);
      if ( v9 == 1 && !numGranaries && !numStoragePits )
        v8 = 0;
      if ( v9 == 2 && TribeResourceAIModule::resource(&v2->md->resourceAI, 1) < 250 && !numStoragePits )
        v8 = 0;
      if ( v9 == 3 && !numGranaries )
        v8 = 0;
      if ( v9 == 4 && (!numGranaries || !numStoragePits) )
        v8 = 0;
      if ( !category
        && (!v8
         && !BuildItem::buildCategory(v5)
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 70
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 109
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 103
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 68
         || !BuildItem::buildCategory(v5)
         && (!numGranaries || !numStoragePits)
         && numHouses >= TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 174)
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 109
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 103
         && BaseItem::typeID((BaseItem *)&v5->vfptr) != 68) )
      {
        goto LABEL_58;
      }
      if ( BuildItem::buildCategory(v5) == 5 && !count )
        break;
      if ( BuildItem::buildCategory(v5) == 6 )
      {
        if ( count < 1 )
        {
          v10 = BuildItem::buildFrom(v5);
          v11 = BaseItem::typeID((BaseItem *)&v5->vfptr);
          TribeTacticalAIModule::setStrategicNumber(&v2->md->tacticalAI, v11 + 156, v10);
LABEL_57:
          BuildItem::setInProgress(v5, 0);
          BuildItem::setBuilt(v5, 1);
        }
LABEL_58:
        v5 = v5->next;
        goto LABEL_59;
      }
      if ( category == 3 && count > 0 )
        return 0;
      if ( BuildItem::buildCap(v5) != -1 )
      {
        v12 = BuildItem::buildCap(v5);
        if ( BuildItem::numberBuilds(v5) > v12 )
          goto LABEL_58;
      }
      if ( category == 1 && (BuildItem::buildCategory(v5) == 1 || BuildItem::buildCategory(v5) == 4) )
      {
        v13 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        if ( !TRIBE_Player::researchEverAvailable(v2->md->aiPlayer, v13) )
          goto LABEL_57;
      }
      if ( BuildItem::buildCategory(v5) == 4 )
      {
        ResourceItem::ResourceItem(&ri, 4);
        v41 = 0;
        v20 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        TRIBE_Player::researchCost(v2->md->aiPlayer, v20, -1, &ri, 1);
        v21 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        if ( !TRIBE_Player::researchAvailable(v2->md->aiPlayer, v21)
          || !TribeResourceAIModule::resourcesAvailable(&v2->md->resourceAI, &ri) )
        {
          v41 = -1;
          v14 = &ri;
LABEL_62:
          ResourceItem::~ResourceItem(v14);
          return 0;
        }
        v41 = -1;
        v14 = &ri;
        if ( category != 1 )
          goto LABEL_62;
        ResourceItem::~ResourceItem(&ri);
      }
      if ( BaseItem::skip((BaseItem *)&v5->vfptr) == 1 && BuildItem::buildAttempts(v5) > 0
        || BuildItem::permanentSkip(v5) )
      {
        BuildItem::decrementBuildAttempts(v5);
        goto LABEL_58;
      }
      if ( BaseItem::skip((BaseItem *)&v5->vfptr) == 1 && BuildItem::buildAttempts(v5) <= 0 )
      {
        BaseItem::setSkip((BaseItem *)&v5->vfptr, 0);
        if ( !BuildItem::buildCategory(v5)
          && (BaseItem::typeID((BaseItem *)&v5->vfptr) == 103 || BaseItem::typeID((BaseItem *)&v5->vfptr) == 68) )
        {
          v22 = TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 114);
          BuildItem::setBuildAttempts(v5, v22 - 1);
        }
      }
      v23 = v2->md->player->attributes;
      if ( v23[11] < (double)v23[32] || BuildItem::buildCategory(v5) != 2 )
        ++count;
      if ( category == 1 )
      {
        if ( BuildItem::buildCategory(v5) != 1 && BuildItem::buildCategory(v5) != 4 )
          goto LABEL_58;
      }
      else if ( category != BuildItem::buildCategory(v5) )
      {
        goto LABEL_58;
      }
      if ( category == 3 && BuildItem::buildCategory(v5) != 3 )
      {
LABEL_63:
        BuildItem::setBuildAttempts(v5, 0);
        return 0;
      }
      BuildItem::incrementBuildAttempts(v5);
      v24 = BuildItem::buildAttempts(v5);
      if ( v24 > TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 114)
        && !BaseItem::skip((BaseItem *)&v5->vfptr)
        && !BuildItem::permanentSkip(v5) )
      {
        if ( category == 1 && BuildItem::buildCategory(v5) == 4 )
          goto LABEL_63;
        v25 = TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 177);
        if ( BaseItem::typeID((BaseItem *)&v5->vfptr) != v25 || BuildItem::buildCategory(v5) )
        {
          BaseItem::setSkip((BaseItem *)&v5->vfptr, 1);
          if ( BuildItem::buildCategory(v5)
            || BaseItem::typeID((BaseItem *)&v5->vfptr) != 103 && BaseItem::typeID((BaseItem *)&v5->vfptr) != 68 )
          {
            v27 = TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 114);
            BuildItem::setBuildAttempts(v5, v27);
          }
          else
          {
            v26 = TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 114);
            BuildItem::setBuildAttempts(v5, 6 * v26);
          }
          goto LABEL_58;
        }
      }
      if ( category == 3 && BuildItem::buildCategory(v5) == 3 )
      {
        v15 = BaseItem::name((BaseItem *)&v5->vfptr);
        strncpy(v2->currentBuildItemRequestedValue, v15, 0x3Fu);
        v2->numberItemsIntoBuildListValue = BaseItem::uniqueID((BaseItem *)&v5->vfptr);
        v16 = BaseItem::name((BaseItem *)&v5->next->vfptr);
        strncpy(v2->nextBuildItemRequestedValue, v16, 0x3Fu);
        v2->numberItemsIntoBuildListValue = BaseItem::uniqueID((BaseItem *)&v5->vfptr);
        return v5;
      }
      if ( category == 1 )
      {
        v28 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        if ( !TRIBE_Player::researchAvailable(v2->md->aiPlayer, v28) )
          goto LABEL_58;
      }
      else
      {
        v29 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        if ( !TRIBE_Player::objectAvailable(v2->md->aiPlayer, v29) )
          goto LABEL_58;
      }
      ResourceItem::ResourceItem(&itemCost, 4);
      v41 = 1;
      if ( category == 1 )
      {
        v30 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        TRIBE_Player::researchCost(v2->md->aiPlayer, v30, -1, &itemCost, 1);
      }
      else
      {
        v31 = BaseItem::typeID((BaseItem *)&v5->vfptr);
        TRIBE_Player::objectCost(v2->md->aiPlayer, v31, -1, &itemCost, 1);
      }
      if ( TribeResourceAIModule::resourcesAvailable(&v2->md->resourceAI, &itemCost) )
      {
        if ( category == 2 || category == 1 )
        {
          v33 = BuildItem::buildFrom(v5);
          v32 = MainDecisionAIModule::object(
                  (MainDecisionAIModule *)&v2->md->vfptr,
                  -1,
                  v33,
                  -1,
                  -1,
                  -1,
                  -1,
                  -1,
                  -1,
                  2,
                  -1);
        }
        else
        {
          v32 = (RGE_Static_Object *)TribeConstructionAIModule::canPlace(&v2->md->constructionAI, v5);
        }
        if ( v32 )
        {
          v18 = BaseItem::name((BaseItem *)&v5->vfptr);
          strncpy(v2->currentBuildItemRequestedValue, v18, 0x3Fu);
          v2->numberItemsIntoBuildListValue = BaseItem::uniqueID((BaseItem *)&v5->vfptr);
          v19 = BaseItem::name((BaseItem *)&v5->next->vfptr);
          strncpy(v2->nextBuildItemRequestedValue, v19, 0x3Fu);
          v2->numberItemsIntoBuildListValue = BaseItem::uniqueID((BaseItem *)&v5->vfptr);
          v41 = -1;
          ResourceItem::~ResourceItem(&itemCost);
          return v5;
        }
      }
      v5 = v5->next;
      v41 = -1;
      ResourceItem::~ResourceItem(&itemCost);
LABEL_59:
      if ( count > TribeTacticalAIModule::strategicNumber(&v2->md->tacticalAI, 115) )
        return 0;
    }
    TribeTacticalAIModule::enableAttack(&v2->md->tacticalAI, 1);
    goto LABEL_57;
  }
  return 0;
}

//----- (004D4DB0) --------------------------------------------------------
int __thiscall TribeBuildAIModule::nextBuildListItemCategory(TribeBuildAIModule *this)
{
  BuildItem *v1; // esi@1
  char *v2; // edi@1

  v1 = this->buildList.next;
  v2 = (char *)&this->buildList;
  if ( v1 != &this->buildList )
  {
    while ( v1 )
    {
      if ( !BuildItem::built(v1)
        && !BuildItem::inProgress(v1)
        && BaseItem::skip((BaseItem *)&v1->vfptr) != 1
        && !BuildItem::permanentSkip(v1) )
      {
        return BuildItem::buildCategory(v1);
      }
      v1 = v1->next;
      if ( (char *)v1 == v2 )
        return 0;
    }
  }
  return 0;
}

//----- (004D4E10) --------------------------------------------------------
int __thiscall TribeBuildAIModule::blockingResource(TribeBuildAIModule *this)
{
  TribeBuildAIModule *v1; // ebx@1
  BuildItem *v2; // esi@1
  char *v3; // edi@1
  int v4; // eax@12
  int v5; // eax@13
  int v6; // esi@15
  ResourceItem itemCost; // [sp+Ch] [bp-7Ch]@10
  int v9; // [sp+84h] [bp-4h]@10

  v1 = this;
  v2 = this->buildList.next;
  v3 = (char *)&this->buildList;
  if ( v2 != &this->buildList )
  {
    do
    {
      if ( !v2
        || !BuildItem::built(v2)
        && !BuildItem::inProgress(v2)
        && BaseItem::skip((BaseItem *)&v2->vfptr) != 1
        && !BuildItem::permanentSkip(v2) )
      {
        break;
      }
      v2 = v2->next;
    }
    while ( (char *)v2 != v3 );
    if ( (char *)v2 != v3 && v2 )
    {
      ResourceItem::ResourceItem(&itemCost, 4);
      v9 = 0;
      if ( BuildItem::buildCategory(v2) == 1 || BuildItem::buildCategory(v2) == 4 )
      {
        v5 = BaseItem::typeID((BaseItem *)&v2->vfptr);
        TRIBE_Player::researchCost(v1->md->aiPlayer, v5, -1, &itemCost, 1);
      }
      else
      {
        v4 = BaseItem::typeID((BaseItem *)&v2->vfptr);
        TRIBE_Player::objectCost(v1->md->aiPlayer, v4, -1, &itemCost, 1);
      }
      if ( !TribeResourceAIModule::resourcesAvailable(&v1->md->resourceAI, &itemCost) )
      {
        v6 = TribeResourceAIModule::unavailableResource(&v1->md->resourceAI, &itemCost);
        v9 = -1;
        ResourceItem::~ResourceItem(&itemCost);
        return v6;
      }
      v9 = -1;
      ResourceItem::~ResourceItem(&itemCost);
    }
  }
  return -1;
}

//----- (004D4F80) --------------------------------------------------------
ResourceItem *__thiscall TribeBuildAIModule::mostNeededResource(TribeBuildAIModule *this, ResourceItem *itemCost, int countNum)
{
  ResourceItem *v3; // ebx@1
  TribeBuildAIModule *v4; // edi@1
  BaseItem *v5; // esi@1
  int v6; // ebp@7
  int v7; // eax@10
  int v8; // eax@11
  ResourceItem *itemCosta; // [sp+14h] [bp+4h]@1

  v3 = itemCost;
  v4 = this;
  ResourceItem::setAllValues(itemCost, 0);
  v5 = (BaseItem *)&v4->buildList.next->vfptr;
  for ( itemCosta = 0; (BuildItem *)v5 != &v4->buildList; v5 = (BaseItem *)v5[1].vfptr )
  {
    if ( !v5 )
      break;
    if ( !BuildItem::built((BuildItem *)v5)
      && !BuildItem::inProgress((BuildItem *)v5)
      && BuildItem::buildCategory((BuildItem *)v5) != 6 )
    {
      if ( BuildItem::buildCap((BuildItem *)v5) == -1
        || (v6 = BuildItem::numberBuilds((BuildItem *)v5), v6 <= BuildItem::buildCap((BuildItem *)v5)) )
      {
        if ( BuildItem::buildCategory((BuildItem *)v5) == 1 || BuildItem::buildCategory((BuildItem *)v5) == 4 )
        {
          v8 = BaseItem::typeID(v5);
          TRIBE_Player::researchCost(v4->md->aiPlayer, v8, -1, v3, 1);
        }
        else
        {
          v7 = BaseItem::typeID(v5);
          TRIBE_Player::objectCost(v4->md->aiPlayer, v7, -1, v3, 1);
        }
        itemCosta = (ResourceItem *)((char *)itemCosta + 1);
        if ( itemCosta == (ResourceItem *)countNum )
          break;
      }
    }
  }
  return itemCosta;
}

//----- (004D5090) --------------------------------------------------------
int __thiscall TribeBuildAIModule::addItem(TribeBuildAIModule *this, RGE_Static_Object *newItem, int gameStarted)
{
  TribeBuildAIModule *v3; // ebp@1
  TribeMainDecisionAIModule *v4; // ecx@1
  BaseItem *v5; // esi@4

  v3 = this;
  v4 = this->md;
  if ( TribeInformationAIModule::isBuilding(newItem) )
    TribeConstructionAIModule::setBuilt(&v3->md->constructionAI, newItem, 1);
  if ( !gameStarted )
  {
    v5 = (BaseItem *)&v3->buildList.next->vfptr;
    if ( (BuildItem *)v5 != &v3->buildList )
    {
      while ( v5 )
      {
        if ( BaseItem::typeID(v5) == newItem->master_obj->id && !BuildItem::built((BuildItem *)v5) )
        {
          BaseItem::setGameID(v5, newItem->id);
          BuildItem::setInProgress((BuildItem *)v5, 0);
          BuildItem::setBuilt((BuildItem *)v5, 1);
          BuildItem::incrementNumberBuilds((BuildItem *)v5);
          if ( BaseItem::typeID(v5) == 276 )
            v3->md->tacticalAI.wonderBuiltValue = 1;
          return 1;
        }
        v5 = (BaseItem *)v5[1].vfptr;
        if ( (BuildItem *)v5 == &v3->buildList )
          return 0;
      }
    }
  }
  return 0;
}

//----- (004D5170) --------------------------------------------------------
int __thiscall TribeBuildAIModule::addBuiltItem(TribeBuildAIModule *this, RGE_Static_Object *newItem, int buildID)
{
  TribeBuildAIModule *v3; // edi@1
  signed int v4; // ebx@1
  BuildItem *v5; // esi@1
  const char *v6; // eax@10

  v3 = this;
  v4 = 0;
  v5 = this->buildList.next;
  if ( v5 != &this->buildList )
  {
    do
    {
      if ( !v5 || v4 )
        break;
      if ( BaseItem::typeID((BaseItem *)&v5->vfptr) != newItem->master_obj->id
        || BuildItem::built(v5)
        || buildID == -1
        || BaseItem::uniqueID((BaseItem *)&v5->vfptr) != buildID )
      {
        v5 = v5->next;
      }
      else
      {
        BuildItem::setInProgress(v5, 0);
        v4 = 1;
        BuildItem::setBuilt(v5, 1);
        BaseItem::setGameID((BaseItem *)&v5->vfptr, newItem->id);
        BuildItem::incrementNumberBuilds(v5);
        if ( BaseItem::typeID((BaseItem *)&v5->vfptr) == 276 )
          v3->md->tacticalAI.wonderBuiltValue = 1;
        v6 = BaseItem::name((BaseItem *)&v5->vfptr);
        strncpy(v3->lastBuildItemRequestedValue, v6, 0x3Fu);
        v3->numberItemsIntoBuildListValue = BaseItem::uniqueID((BaseItem *)&v5->vfptr);
      }
    }
    while ( v5 != &v3->buildList );
  }
  TribeTacticalAIModule::updateNeededResources(&v3->md->tacticalAI);
  return 1;
}

//----- (004D5270) --------------------------------------------------------
int __thiscall TribeBuildAIModule::removeBuiltItem(TribeBuildAIModule *this, int id)
{
  TribeBuildAIModule *v2; // ebx@1
  BuildItem *v3; // esi@1
  char *v4; // ebp@1
  signed int v5; // edi@1

  v2 = this;
  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  v5 = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 || v5 )
        break;
      if ( BaseItem::gameID((BaseItem *)&v3->vfptr) != id || BuildItem::built(v3) != 1 )
      {
        v3 = v3->next;
      }
      else
      {
        BuildItem::setInProgress(v3, 0);
        BuildItem::setBuilt(v3, 0);
        BaseItem::setGameID((BaseItem *)&v3->vfptr, -1);
        BuildItem::setBuildAttempts(v3, 0);
        if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == 276 )
          v2->md->tacticalAI.wonderBuiltValue = 0;
        v5 = 1;
      }
    }
    while ( (char *)v3 != v4 );
  }
  TribeTacticalAIModule::updateNeededResources(&v2->md->tacticalAI);
  return 1;
}

//----- (004D5310) --------------------------------------------------------
int __thiscall TribeBuildAIModule::cancelBuildItem(TribeBuildAIModule *this, int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID)
{
  TribeBuildAIModule *v8; // esi@1
  signed int v9; // edi@3
  ConstructionItem *v10; // eax@10
  BaseItem *v11; // edi@10
  float maxY; // ST10_4@11
  float maxX; // ST0C_4@11
  float minY; // ST08_4@11
  float minX; // ST04_4@11
  float v16; // ST10_4@12
  float v17; // ST0C_4@12
  float v18; // ST08_4@12
  float v19; // ST04_4@12
  BuildItem *v20; // eax@14
  BaseItem *v21; // edi@14
  int v22; // eax@15
  char newLotStatus; // [sp+20h] [bp-4h]@3
  int reasona; // [sp+28h] [bp+4h]@11
  int reasonb; // [sp+28h] [bp+4h]@11
  int reasonc; // [sp+28h] [bp+4h]@11
  int reasond; // [sp+28h] [bp+4h]@11
  int builderIDa; // [sp+40h] [bp+1Ch]@3

  v8 = this;
  if ( builderID != -1 )
    TribeMainDecisionAIModule::detask(this->md, builderID);
  v9 = 0;
  builderIDa = 0;
  newLotStatus = 2;
  switch ( reason + 1 )
  {
    case 0:
      builderIDa = 1;
      v9 = 0;
      newLotStatus = 0;
      break;
    case 9:
      v9 = 1;
      builderIDa = 1;
      break;
    default:
      builderIDa = 1;
      v9 = 0;
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      break;
  }
  if ( MainDecisionAIModule::object((MainDecisionAIModule *)&v8->md->vfptr, blockerID) && v9 == 1 )
  {
    if ( TribeMainDecisionAIModule::isMoveable(v8->md, blockerID) == 1 )
    {
      v10 = ConstructionAIModule::lot((ConstructionAIModule *)&v8->md->constructionAI.vfptr, x, y);
      v11 = (BaseItem *)v10;
      if ( v10 )
      {
        *(float *)&reasona = BaseItem::y((BaseItem *)&v10->vfptr);
        maxY = *(float *)&reasona - BaseItem::ySize(v11) * -0.5;
        *(float *)&reasonb = BaseItem::x(v11);
        maxX = *(float *)&reasonb - BaseItem::xSize(v11) * -0.5;
        *(float *)&reasonc = BaseItem::y(v11);
        minY = *(float *)&reasonc - BaseItem::ySize(v11) * 0.5;
        *(float *)&reasond = BaseItem::x(v11);
        minX = *(float *)&reasond - BaseItem::xSize(v11) * 0.5;
        TribeTacticalAIModule::clearArea(&v8->md->tacticalAI, blockerID, minX, minY, maxX, maxY);
      }
      else
      {
        v16 = y - -2.0;
        v17 = x - -2.0;
        v18 = y - 2.0;
        v19 = x - 2.0;
        TribeTacticalAIModule::clearArea(&v8->md->tacticalAI, blockerID, v19, v18, v17, v16);
      }
    }
    else
    {
      ((void (__thiscall *)(int, _DWORD, _DWORD, signed int))v8->md->constructionAI.vfptr[1].toggleLogCommonHistory)(
        (int)&v8->md->constructionAI,
        LODWORD(x),
        LODWORD(y),
        10);
    }
  }
  ((void (__thiscall *)(int, _DWORD, _DWORD, int))v8->md->constructionAI.vfptr[1].setHistoryFilename)(
    (int)&v8->md->constructionAI,
    LODWORD(x),
    LODWORD(y),
    builderIDa);
  v20 = BuildAIModule::specificBuildListItem((BuildAIModule *)&v8->vfptr, uniqueID);
  v21 = (BaseItem *)v20;
  if ( v20 )
  {
    BuildItem::setInProgress(v20, 0);
    v22 = BaseItem::typeID(v21);
    TribeInformationAIModule::removeLot(&v8->md->informationAI, v22, (signed __int64)x, (signed __int64)y, newLotStatus);
    if ( BaseItem::typeID(v21) == 276 )
      v8->md->tacticalAI.wonderInProgressValue = 0;
  }
  return 1;
}

//----- (004D5590) --------------------------------------------------------
int __thiscall TribeBuildAIModule::addTrainedUnit(TribeBuildAIModule *this, int uType, int location, int uniqueID, int gameID)
{
  TribeBuildAIModule *v5; // edi@1
  BuildItem *v6; // eax@1
  BuildItem *v7; // esi@1

  v5 = this;
  v6 = BuildAIModule::specificBuildListItem((BuildAIModule *)&this->vfptr, uniqueID);
  v7 = v6;
  if ( v6 )
  {
    BuildItem::setInProgress(v6, 0);
    BuildItem::setBuilt(v7, 1);
    BaseItem::setGameID((BaseItem *)&v7->vfptr, gameID);
    BuildItem::incrementNumberBuilds(v7);
  }
  TribeMainDecisionAIModule::detask(v5->md, location);
  TribeTacticalAIModule::updateNeededResources(&v5->md->tacticalAI);
  return 1;
}

//----- (004D5600) --------------------------------------------------------
int __thiscall TribeBuildAIModule::cancelTrainUnit(TribeBuildAIModule *this, int reason, int uType, int location, int uniqueID)
{
  TribeBuildAIModule *v5; // esi@1
  BuildItem *v6; // eax@1
  BuildItem *v7; // edi@1
  int v8; // eax@2
  int result; // eax@2

  v5 = this;
  AIModule::logCommonHistory(
    (AIModule *)&this->vfptr,
    aCancelingTrain,
    this->md->player->world->world_time,
    uType,
    location);
  v6 = BuildAIModule::specificBuildListItem((BuildAIModule *)&v5->vfptr, uniqueID);
  v7 = v6;
  if ( v6 )
  {
    v8 = BaseItem::uniqueID((BaseItem *)&v6->vfptr);
    AIModule::logCommonHistory((AIModule *)&v5->vfptr, aSettingBuildIt, v8);
    BuildItem::setInProgress(v7, 0);
    (*(void (__thiscall **)(TribeBuildAIModule *))&v5->vfptr[1].gap4[0])(v5);
    result = 1;
  }
  else
  {
    AIModule::logCommonHistory((AIModule *)&v5->vfptr, aErrorInvalidBu);
    (*(void (__thiscall **)(TribeBuildAIModule *))&v5->vfptr[1].gap4[0])(v5);
    result = 1;
  }
  return result;
}

//----- (004D5690) --------------------------------------------------------
int __thiscall TribeBuildAIModule::addResearch(TribeBuildAIModule *this, int uType, int location, int uniqueID)
{
  TribeBuildAIModule *v4; // edi@1
  BuildItem *v5; // eax@1
  BuildItem *v6; // esi@1

  v4 = this;
  v5 = BuildAIModule::specificBuildListItem((BuildAIModule *)&this->vfptr, uniqueID);
  v6 = v5;
  if ( v5 )
  {
    BuildItem::setInProgress(v5, 0);
    BuildItem::setBuilt(v6, 1);
    BuildItem::incrementNumberBuilds(v6);
  }
  TribeMainDecisionAIModule::detask(v4->md, location);
  TribeTacticalAIModule::updateNeededResources(&v4->md->tacticalAI);
  return 1;
}

//----- (004D56F0) --------------------------------------------------------
int __thiscall TribeBuildAIModule::cancelResearch(TribeBuildAIModule *this, int reason, int rType, int location, int uniqueID)
{
  TribeBuildAIModule *v5; // esi@1
  BuildItem *v6; // eax@1
  BuildItem *v7; // edi@1
  int v8; // eax@2
  int result; // eax@2

  v5 = this;
  AIModule::logCommonHistory(
    (AIModule *)&this->vfptr,
    aCancelingResea,
    this->md->player->world->world_time,
    rType,
    location);
  v6 = BuildAIModule::specificBuildListItem((BuildAIModule *)&v5->vfptr, uniqueID);
  v7 = v6;
  if ( v6 )
  {
    v8 = BaseItem::uniqueID((BaseItem *)&v6->vfptr);
    AIModule::logCommonHistory((AIModule *)&v5->vfptr, aSettingBuildIt, v8);
    BuildItem::setInProgress(v7, 0);
    (*(void (__thiscall **)(TribeBuildAIModule *))&v5->vfptr[1].gap4[0])(v5);
    result = 1;
  }
  else
  {
    AIModule::logCommonHistory((AIModule *)&v5->vfptr, aErrorInvalidBu);
    (*(void (__thiscall **)(TribeBuildAIModule *))&v5->vfptr[1].gap4[0])(v5);
    result = 1;
  }
  return result;
}

//----- (004D5780) --------------------------------------------------------
BOOL __stdcall TribeBuildAIModule::isAgeResearch(int rID)
{
  return rID == 101 || rID == 102 || rID == 103;
}

//----- (004D57A0) --------------------------------------------------------
int __thiscall TribeBuildAIModule::insert(TribeBuildAIModule *this, int typeID, int buildCap, int insertionPoint)
{
  int v4; // eax@1
  int result; // eax@5
  int v6; // ebp@12
  BuildItem *v7; // esi@23
  char *v8; // ebx@23
  int v9; // edi@23
  signed int buildCategory; // [sp+10h] [bp-8h]@12
  TribeBuildAIModule *v11; // [sp+14h] [bp-4h]@1

  v4 = typeID;
  v11 = this;
  if ( typeID > 11 )
  {
    if ( typeID <= 25 )
    {
      if ( typeID == 25 )
      {
LABEL_12:
        v6 = 87;
        buildCategory = 2;
        goto LABEL_22;
      }
      switch ( typeID )
      {
        case 13:
        case 15:
        case 17:
        case 18:
        case 19:
          goto LABEL_20;
        default:
          return 0;
      }
      return 0;
    }
    if ( typeID > 70 )
    {
      switch ( typeID )
      {
        case 83:
          v6 = 109;
          buildCategory = 2;
          goto LABEL_22;
        case 73:
        case 75:
          v6 = 12;
          buildCategory = 2;
          goto LABEL_22;
        case 93:
          v6 = 0;
          buildCategory = 2;
          goto LABEL_22;
        case 125:
          v6 = 104;
          buildCategory = 2;
          goto LABEL_22;
        case 299:
LABEL_19:
          v6 = 101;
          buildCategory = 2;
          goto LABEL_22;
        case 250:
LABEL_20:
          v6 = 45;
          buildCategory = 2;
          goto LABEL_22;
        case 79:
        case 103:
        case 199:
        case 276:
        case 278:
          goto LABEL_21;
        default:
          return 0;
      }
      return 0;
    }
    if ( typeID < 68 )
    {
      switch ( typeID )
      {
        case 39:
        case 41:
          goto LABEL_12;
        case 35:
        case 36:
          goto LABEL_13;
        case 37:
        case 40:
        case 46:
          goto LABEL_19;
        case 45:
        case 49:
        case 50:
          goto LABEL_21;
        default:
          return 0;
      }
      return 0;
    }
LABEL_21:
    v6 = -1;
    buildCategory = 0;
  }
  else
  {
    if ( typeID != 11 )
    {
      if ( typeID >= 4 )
      {
        if ( typeID > 5 )
          return 0;
        goto LABEL_12;
      }
      return 0;
    }
LABEL_13:
    v6 = 49;
    buildCategory = 2;
  }
LABEL_22:
  if ( insertionPoint == -1 )
  {
    v7 = this->buildList.next;
    v8 = (char *)&this->buildList;
    v9 = 0;
    if ( v7 != &this->buildList )
    {
      while ( v7 )
      {
        if ( BuildItem::built(v7) != 1 || (v7 = v7->next, ++v9, (char *)v7 == v8) )
        {
          v4 = typeID;
          break;
        }
        v4 = typeID;
      }
    }
    result = BuildAIModule::insertItem(
               (BuildAIModule *)&v11->vfptr,
               v11->md->player,
               v4,
               1,
               buildCategory,
               v6,
               buildCap,
               v9);
  }
  else
  {
    result = BuildAIModule::insertItem(
               (BuildAIModule *)&this->vfptr,
               this->md->player,
               typeID,
               1,
               buildCategory,
               v6,
               buildCap,
               insertionPoint);
  }
  return result;
}

//----- (004D5AD0) --------------------------------------------------------
int __thiscall TribeBuildAIModule::insertResearch(TribeBuildAIModule *this, int typeID, int insertionPoint)
{
  TribeBuildAIModule *v3; // ebx@1
  int result; // eax@4
  BuildItem *v5; // esi@6
  char *v6; // edi@6
  int v7; // ebp@6

  v3 = this;
  if ( typeID == 5 || typeID > 6 && typeID <= 8 )
  {
    if ( insertionPoint == -1 )
    {
      v5 = this->buildList.next;
      v6 = (char *)&this->buildList;
      v7 = 0;
      if ( v5 != &this->buildList )
      {
        do
        {
          if ( !v5 )
            break;
          if ( BuildItem::built(v5) != 1 )
            break;
          v5 = v5->next;
          ++v7;
        }
        while ( (char *)v5 != v6 );
      }
      result = BuildAIModule::insertItem((BuildAIModule *)&v3->vfptr, v3->md->player, typeID, 1, 1, 45, 1, v7);
    }
    else
    {
      result = BuildAIModule::insertItem(
                 (BuildAIModule *)&this->vfptr,
                 this->md->player,
                 typeID,
                 1,
                 1,
                 45,
                 1,
                 insertionPoint);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004D5B80) --------------------------------------------------------
int __thiscall TribeBuildAIModule::insertGathererPercentage(TribeBuildAIModule *this, int rType, int percentage, int insertionPoint)
{
  return BuildAIModule::insertItem(
           (BuildAIModule *)&this->vfptr,
           this->md->player,
           rType,
           1,
           6,
           percentage,
           1,
           insertionPoint);
}

//----- (004D5BB0) --------------------------------------------------------
int __thiscall TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(TribeBuildAIModule *this, int type, int category)
{
  TribeBuildAIModule *v3; // edi@1
  int v4; // eax@4
  TribeMainDecisionAIModule *v5; // ecx@4
  int result; // eax@5

  v3 = this;
  if ( category || type != 103 && type != 68 )
  {
    result = BuildAIModule::numberBuiltOrInProgressItemsOfType((BuildAIModule *)&this->vfptr, type, category);
  }
  else
  {
    v4 = BuildAIModule::numberInProgressItemsOfType((BuildAIModule *)&this->vfptr, type, 0);
    v5 = v3->md;
    if ( type == 103 )
      result = TribeInformationAIModule::numberStoragePits(&v5->informationAI) + v4;
    else
      result = TribeInformationAIModule::numberGranaries(&v5->informationAI) + v4;
  }
  return result;
}

//----- (004D5C20) --------------------------------------------------------
int __thiscall TribeBuildAIModule::allBuilt(TribeBuildAIModule *this, int category1, int category2)
{
  BuildItem *v3; // esi@1
  char *v4; // edi@1

  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  if ( v3 != &this->buildList )
  {
    while ( v3 )
    {
      if ( (BuildItem::buildCategory(v3) == category1 || BuildItem::buildCategory(v3) == category2)
        && !BuildItem::built(v3)
        && !BuildItem::inProgress(v3) )
      {
        return 0;
      }
      v3 = v3->next;
      if ( (char *)v3 == v4 )
        return 1;
    }
  }
  return 1;
}

//----- (004D5CA0) --------------------------------------------------------
BOOL __thiscall TribeBuildAIModule::readyToResearch(TribeBuildAIModule *this, int id, int ageResearch)
{
  TribeBuildAIModule *v3; // esi@1
  char v4; // al@3

  v3 = this;
  if ( ageResearch == 1 )
  {
    if ( id == 2 )
      v4 = TRIBE_Player::researchState(this->md->aiPlayer, 101);
    else
      v4 = id;
    if ( id == 3 )
      v4 = TRIBE_Player::researchState(v3->md->aiPlayer, 102);
    if ( id == 4 )
      return (unsigned __int8)TRIBE_Player::researchState(v3->md->aiPlayer, 103) == 1;
  }
  else
  {
    v4 = TRIBE_Player::researchState(this->md->aiPlayer, id);
  }
  return v4 == 1;
}

//----- (004D5D40) --------------------------------------------------------
void __thiscall TribeBuildAIModule::unskipBuildList(TribeBuildAIModule *this, int builtSP, int builtG)
{
  TribeBuildAIModule *v3; // edi@1
  void (__thiscall *v4)(AIModule *); // esi@1
  int v5; // ebx@1
  int v6; // eax@1
  BaseItem *v7; // esi@1
  int v8; // edi@1
  int i; // ebp@1

  v3 = this;
  v4 = this->vfptr[1].toggleLogHistory;
  v5 = ((int (__stdcall *)(_DWORD, _DWORD))v4)(103, 0);
  v6 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD))v4)(v3, 68, 0);
  v7 = (BaseItem *)&v3->buildList.next->vfptr;
  v8 = (int)&v3->buildList;
  for ( i = v6; v7 != (BaseItem *)v8; v7 = (BaseItem *)v7[1].vfptr )
  {
    if ( !v7 )
      break;
    if ( BuildItem::built((BuildItem *)v7) != 1
      && BuildItem::inProgress((BuildItem *)v7) != 1
      && (v5 <= 0 || BaseItem::typeID(v7) != 103)
      && (i <= 0 || BaseItem::typeID(v7) != 68) )
    {
      BaseItem::setSkip(v7, 0);
      BuildItem::setBuildAttempts((BuildItem *)v7, 0);
      BuildItem::setSkipCycles((BuildItem *)v7, 0);
      BuildItem::setPermanentSkip((BuildItem *)v7, 0);
    }
  }
}

//----- (004D5DE0) --------------------------------------------------------
BuildItem *__thiscall TribeBuildAIModule::buildItem(TribeBuildAIModule *this, int typeID, int category1, int category2)
{
  BuildItem *v4; // esi@1
  char *v5; // edi@1

  v4 = this->buildList.next;
  v5 = (char *)&this->buildList;
  if ( v4 != &this->buildList )
  {
    while ( v4 )
    {
      if ( !BuildItem::built(v4)
        && !BuildItem::inProgress(v4)
        && BaseItem::typeID((BaseItem *)&v4->vfptr) == typeID
        && (BuildItem::buildCategory(v4) == category1 || BuildItem::buildCategory(v4) == category2) )
      {
        return v4;
      }
      v4 = v4->next;
      if ( (char *)v4 == v5 )
        return 0;
    }
  }
  return 0;
}
