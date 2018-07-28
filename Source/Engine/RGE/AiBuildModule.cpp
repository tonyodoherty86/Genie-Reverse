
//----- (004086B0) --------------------------------------------------------
void __thiscall BuildAIModule::BuildAIModule(BuildAIModule *this, void *pW, int playerID)
{
  BuildAIModule *v3; // ebx@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, n, 1001, playerID, pW);
  BuildItem::BuildItem(&v3->buildList);
  v3->buildListLengthValue = 0;
  v3->numberItemsIntoBuildListValue = 0;
  v3->typesToIgnore.value = 0;
  v3->typesToIgnore.numberValue = 0;
  v3->typesToIgnore.desiredNumberValue = 0;
  v3->typesToIgnore.maximumSizeValue = 0;
  v3->vfptr = (AIModuleVtbl *)&BuildAIModule::`vftable';
  v3->buildList.next = &v3->buildList;
  v3->buildList.prev = &v3->buildList;
  strcpy(v3->buildListNameValue, message_in);
  strcpy(v3->lastBuildItemRequestedValue, aNone_3);
  strcpy(v3->currentBuildItemRequestedValue, aNone_3);
  strcpy(v3->nextBuildItemRequestedValue, aNone_3);
}
// 56E738: using guessed type int (__thiscall *BuildAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004087F0) --------------------------------------------------------
int __stdcall AIModule::loadState(char *__formal)
{
  return 0;
}

//----- (00408800) --------------------------------------------------------
int __stdcall AIModule::saveState(char *__formal)
{
  return 0;
}

//----- (00408810) --------------------------------------------------------
int __stdcall AIModule::gleanState(int __formal)
{
  return 0;
}

//----- (00408820) --------------------------------------------------------
BuildAIModule *__thiscall BuildAIModule::`vector deleting destructor'(BuildAIModule *this, unsigned int __flags)
{
  BuildAIModule *v2; // esi@1

  v2 = this;
  BuildAIModule::~BuildAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00408840) --------------------------------------------------------
void __thiscall BuildAIModule::BuildAIModule(BuildAIModule *this, int playerID, int infile)
{
  int v3; // edi@1
  BuildAIModule *v4; // ebx@1
  int v5; // ebp@1
  BuildItem *v6; // eax@7
  BuildItem *v7; // eax@8
  BuildItem *v8; // esi@8
  BuildItem *v9; // eax@10
  int v10; // eax@10
  int tempInt; // [sp+10h] [bp-178h]@1
  int buildCap; // [sp+14h] [bp-174h]@5
  int builtValue; // [sp+18h] [bp-170h]@5
  int inProgressValue; // [sp+1Ch] [bp-16Ch]@5
  int buildAttemptsValue; // [sp+20h] [bp-168h]@5
  int terrainAdjOne; // [sp+24h] [bp-164h]@5
  int skipValue; // [sp+28h] [bp-160h]@5
  float zSize; // [sp+2Ch] [bp-15Ch]@5
  int gameID; // [sp+30h] [bp-158h]@5
  float xSize; // [sp+34h] [bp-154h]@5
  float x; // [sp+38h] [bp-150h]@5
  int uniqueID; // [sp+3Ch] [bp-14Ch]@5
  float y; // [sp+40h] [bp-148h]@5
  int buildCategory; // [sp+44h] [bp-144h]@5
  float z; // [sp+48h] [bp-140h]@5
  int terrainAdjTwo; // [sp+4Ch] [bp-13Ch]@5
  int numberBuilds; // [sp+50h] [bp-138h]@5
  float ySize; // [sp+54h] [bp-134h]@5
  int numberSkipCycles; // [sp+58h] [bp-130h]@7
  int typeID; // [sp+5Ch] [bp-12Ch]@5
  int permanentSkip; // [sp+60h] [bp-128h]@7
  int terrainSet; // [sp+64h] [bp-124h]@5
  int placeOnElevation; // [sp+68h] [bp-120h]@5
  int buildFrom; // [sp+6Ch] [bp-11Ch]@5
  BuildAIModule *v35; // [sp+70h] [bp-118h]@1
  BuildItem *v36; // [sp+74h] [bp-114h]@7
  char name[257]; // [sp+78h] [bp-110h]@5
  int v38; // [sp+184h] [bp-4h]@1

  v3 = 0;
  v4 = this;
  v35 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, n, 1001, playerID, 0);
  v38 = 0;
  BuildItem::BuildItem(&v4->buildList);
  v4->numberItemsIntoBuildListValue = 0;
  v4->buildListLengthValue = 0;
  v4->typesToIgnore.value = 0;
  v4->typesToIgnore.numberValue = 0;
  v4->typesToIgnore.desiredNumberValue = 0;
  v4->typesToIgnore.maximumSizeValue = 0;
  v5 = infile;
  LOBYTE(v38) = 2;
  v4->vfptr = (AIModuleVtbl *)&BuildAIModule::`vftable';
  v4->buildList.next = &v4->buildList;
  v4->buildList.prev = &v4->buildList;
  rge_read(infile, 0, infile, &v4->buildListLengthValue, 4);
  rge_read(v5, 0, v5, &tempInt, 4);
  rge_read(v5, 0, v5, v4->buildListNameValue, tempInt);
  v4->buildListNameValue[tempInt] = 0;
  rge_read(v5, 0, v5, &tempInt, 4);
  rge_read(v5, 0, v5, v4->lastBuildItemRequestedValue, tempInt);
  v4->lastBuildItemRequestedValue[tempInt] = 0;
  rge_read(v5, 0, v5, &tempInt, 4);
  rge_read(v5, 0, v5, v4->currentBuildItemRequestedValue, tempInt);
  v4->currentBuildItemRequestedValue[tempInt] = 0;
  if ( save_game_version < 3.0999999 )
  {
    strcpy(v4->nextBuildItemRequestedValue, aNone_3);
    v3 = 0;
  }
  else
  {
    rge_read(infile, 0, infile, &tempInt, 4);
    rge_read(infile, 0, infile, v4->nextBuildItemRequestedValue, tempInt);
    v4->nextBuildItemRequestedValue[tempInt] = 0;
  }
  rge_read(infile, 0, infile, &v4->numberItemsIntoBuildListValue, 4);
  if ( v4->buildListLengthValue > 0 )
  {
    do
    {
      rge_read(infile, v3, infile, &tempInt, 4);
      rge_read(infile, v3, infile, name, tempInt);
      name[tempInt] = 0;
      rge_read(infile, v3, infile, &typeID, 4);
      rge_read(infile, v3, infile, &gameID, 4);
      rge_read(infile, v3, infile, &uniqueID, 4);
      rge_read(infile, v3, infile, &x, 4);
      rge_read(infile, v3, infile, &y, 4);
      rge_read(infile, v3, infile, &z, 4);
      rge_read(infile, v3, infile, &xSize, 4);
      rge_read(infile, v3, infile, &ySize, 4);
      rge_read(infile, v3, infile, &zSize, 4);
      rge_read(infile, v3, infile, &skipValue, 4);
      rge_read(infile, v3, infile, &buildCategory, 4);
      rge_read(infile, v3, infile, &inProgressValue, 4);
      rge_read(infile, v3, infile, &builtValue, 4);
      rge_read(infile, v3, infile, &buildAttemptsValue, 4);
      rge_read(infile, v3, infile, &buildFrom, 4);
      rge_read(infile, v3, infile, &terrainSet, 4);
      rge_read(infile, v3, infile, &terrainAdjOne, 4);
      rge_read(infile, v3, infile, &terrainAdjTwo, 4);
      rge_read(infile, v3, infile, &placeOnElevation, 4);
      rge_read(infile, v3, infile, &numberBuilds, 4);
      buildCap = -1;
      if ( save_game_version >= 2.2 )
        rge_read(infile, v3, infile, &buildCap, 4);
      rge_read(infile, v3, infile, &numberSkipCycles, 4);
      rge_read(infile, v3, infile, &permanentSkip, 1);
      v6 = (BuildItem *)operator new(0xB0u);
      v36 = v6;
      LOBYTE(v38) = 3;
      if ( v6 )
      {
        BuildItem::BuildItem(
          v6,
          buildCategory,
          typeID,
          uniqueID,
          1,
          0,
          buildFrom,
          name,
          xSize,
          ySize,
          zSize,
          terrainSet,
          terrainAdjOne,
          terrainAdjTwo,
          placeOnElevation);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      LOBYTE(v38) = 2;
      BuildItem::setBuilt(v8, builtValue);
      BuildItem::setInProgress(v8, inProgressValue);
      BuildItem::setBuildAttempts(v8, buildAttemptsValue);
      BaseItem::setSkip((BaseItem *)&v8->vfptr, skipValue);
      BaseItem::setGameID((BaseItem *)&v8->vfptr, gameID);
      BaseItem::setX((BaseItem *)&v8->vfptr, x);
      BaseItem::setY((BaseItem *)&v8->vfptr, y);
      BaseItem::setZ((BaseItem *)&v8->vfptr, z);
      BuildItem::setNumberBuilds(v8, numberBuilds);
      BuildItem::setBuildCap(v8, buildCap);
      BuildItem::setSkipCycles(v8, numberSkipCycles);
      BuildItem::setPermanentSkip(v8, permanentSkip);
      ++v3;
      v8->next = &v4->buildList;
      v9 = v4->buildList.prev;
      v8->prev = v9;
      v9->next = v8;
      v10 = v4->buildListLengthValue;
      v4->buildList.prev = v8;
    }
    while ( v3 < v10 );
  }
}
// 56E738: using guessed type int (__thiscall *BuildAIModule::`vftable')(void *Memory, unsigned int __flags);
// 58EBCC: using guessed type float save_game_version;

//----- (00408D20) --------------------------------------------------------
void __thiscall ManagedArray<int>::~ManagedArray<int>(ManagedArray<int> *this)
{
  ManagedArray<int> *v1; // esi@1

  v1 = this;
  if ( this->value )
  {
    operator delete(this->value);
    v1->value = 0;
  }
  v1->numberValue = 0;
  v1->desiredNumberValue = 0;
  v1->maximumSizeValue = 0;
}

//----- (00408D50) --------------------------------------------------------
void __thiscall BuildAIModule::~BuildAIModule(BuildAIModule *this)
{
  BuildAIModule *v1; // esi@1
  int *v2; // eax@3

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&BuildAIModule::`vftable';
  if ( this->buildListLengthValue > 0 )
    BuildAIModule::removeOldList(this);
  v2 = v1->typesToIgnore.value;
  if ( v2 )
  {
    operator delete(v2);
    v1->typesToIgnore.value = 0;
  }
  v1->typesToIgnore.numberValue = 0;
  v1->typesToIgnore.desiredNumberValue = 0;
  v1->typesToIgnore.maximumSizeValue = 0;
  BuildItem::~BuildItem(&v1->buildList);
  AIModule::~AIModule((AIModule *)&v1->vfptr);
}
// 56E738: using guessed type int (__thiscall *BuildAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00408DF0) --------------------------------------------------------
int __thiscall BuildAIModule::save(BuildAIModule *this, int outfile)
{
  BuildAIModule *v2; // ebx@1
  BaseItem *v3; // ebx@1
  bool v4; // zf@1
  int tempInt; // [sp+10h] [bp-118h]@1
  float tempFloat; // [sp+14h] [bp-114h]@3
  int tempBOOL; // [sp+18h] [bp-110h]@3
  char tempBYTE; // [sp+1Fh] [bp-109h]@3
  BuildAIModule *v10; // [sp+20h] [bp-108h]@1
  char tempString[257]; // [sp+24h] [bp-104h]@1

  v2 = this;
  v10 = this;
  rge_write(outfile, &this->buildListLengthValue, 4);
  strcpy(tempString, v2->buildListNameValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  strcpy(tempString, v2->lastBuildItemRequestedValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  strcpy(tempString, v2->currentBuildItemRequestedValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  strcpy(tempString, v2->nextBuildItemRequestedValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  rge_write(outfile, &v2->numberItemsIntoBuildListValue, 4);
  v3 = (BaseItem *)&v2->buildList.next->vfptr;
  v4 = (BuildItem *)v3 == &v10->buildList;
  v10 = (BuildAIModule *)((char *)v10 + 240);
  if ( !v4 )
  {
    do
    {
      if ( !v3 )
        break;
      strcpy(tempString, BaseItem::name(v3));
      tempInt = strlen(tempString);
      rge_write(outfile, &tempInt, 4);
      rge_write(outfile, tempString, strlen(tempString));
      tempInt = BaseItem::typeID(v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BaseItem::gameID(v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BaseItem::uniqueID(v3);
      rge_write(outfile, &tempInt, 4);
      tempFloat = BaseItem::x(v3);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::y(v3);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::z(v3);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::xSize(v3);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::ySize(v3);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::zSize(v3);
      rge_write(outfile, &tempFloat, 4);
      tempBOOL = BaseItem::skip(v3);
      rge_write(outfile, &tempBOOL, 4);
      tempInt = BuildItem::buildCategory((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempBOOL = BuildItem::inProgress((BuildItem *)v3);
      rge_write(outfile, &tempBOOL, 4);
      tempBOOL = BuildItem::built((BuildItem *)v3);
      rge_write(outfile, &tempBOOL, 4);
      tempInt = BuildItem::buildAttempts((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BuildItem::buildFrom((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BuildItem::terrainSet((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BuildItem::terrainAdjacency((BuildItem *)v3, 1);
      rge_write(outfile, &tempInt, 4);
      tempInt = BuildItem::terrainAdjacency((BuildItem *)v3, 2);
      rge_write(outfile, &tempInt, 4);
      tempBOOL = BuildItem::placeOnElevation((BuildItem *)v3);
      rge_write(outfile, &tempBOOL, 4);
      tempInt = BuildItem::numberBuilds((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BuildItem::buildCap((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempInt = BuildItem::skipCycles((BuildItem *)v3);
      rge_write(outfile, &tempInt, 4);
      tempBYTE = BuildItem::permanentSkip((BuildItem *)v3);
      rge_write(outfile, &tempBYTE, 1);
      v3 = (BaseItem *)v3[1].vfptr;
    }
    while ( (BuildAIModule *)v3 != v10 );
  }
  return 1;
}

//----- (004092F0) --------------------------------------------------------
void __thiscall BuildAIModule::displayBuildList(BuildAIModule *this)
{
  BuildAIModule *v1; // edi@1
  BuildItem *i; // esi@1
  int v3; // ST38_4@4
  int v4; // ST34_4@4
  int v5; // ST30_4@4
  int v6; // ST2C_4@4
  int v7; // ST28_4@4
  int v8; // ST24_4@4
  int v9; // ST20_4@4
  int v10; // ST1C_4@4
  int v11; // ST18_4@4
  int v12; // ST14_4@4
  int v13; // ST10_4@4
  char *v14; // ST0C_4@4
  int v15; // ST08_4@4
  int v16; // ST38_4@5
  int v17; // ST34_4@5
  int v18; // ST30_4@5
  int v19; // ST2C_4@5
  int v20; // ST28_4@5
  int v21; // ST24_4@5
  int v22; // ST20_4@5
  int v23; // ST1C_4@5
  int v24; // ST18_4@5
  int v25; // ST14_4@5
  int v26; // ST10_4@5
  char *v27; // ST0C_4@5
  int v28; // ST08_4@5

  v1 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, textIn, this->buildListNameValue);
  for ( i = v1->buildList.next; i != &v1->buildList; i = i->next )
  {
    if ( !i )
      break;
    if ( BuildItem::built(i) == 1 )
    {
      v3 = BuildItem::skipCycles(i);
      v4 = (unsigned __int8)BuildItem::permanentSkip(i);
      v5 = BuildItem::buildFrom(i);
      v6 = BuildItem::buildCap(i);
      v7 = BuildItem::numberBuilds(i);
      v8 = BaseItem::skip((BaseItem *)&i->vfptr);
      v9 = BuildItem::buildAttempts(i);
      v10 = BuildItem::inProgress(i);
      v11 = BaseItem::uniqueID((BaseItem *)&i->vfptr);
      v12 = BuildItem::buildCategory(i);
      v13 = BaseItem::gameID((BaseItem *)&i->vfptr);
      v14 = BaseItem::name((BaseItem *)&i->vfptr);
      v15 = BaseItem::typeID((BaseItem *)&i->vfptr);
      AIModule::logCommonHistory(
        (AIModule *)&v1->vfptr,
        aBltType4d20sGi,
        v15,
        v14,
        v13,
        v12,
        v11,
        v10,
        v9,
        v8,
        v7,
        v6,
        v5,
        v4,
        v3);
    }
    else
    {
      v16 = BuildItem::skipCycles(i);
      v17 = (unsigned __int8)BuildItem::permanentSkip(i);
      v18 = BuildItem::buildFrom(i);
      v19 = BuildItem::buildCap(i);
      v20 = BuildItem::numberBuilds(i);
      v21 = BaseItem::skip((BaseItem *)&i->vfptr);
      v22 = BuildItem::buildAttempts(i);
      v23 = BuildItem::inProgress(i);
      v24 = BaseItem::uniqueID((BaseItem *)&i->vfptr);
      v25 = BuildItem::buildCategory(i);
      v26 = BaseItem::gameID((BaseItem *)&i->vfptr);
      v27 = BaseItem::name((BaseItem *)&i->vfptr);
      v28 = BaseItem::typeID((BaseItem *)&i->vfptr);
      AIModule::logCommonHistory(
        (AIModule *)&v1->vfptr,
        aType4d20sGid4d,
        v28,
        v27,
        v26,
        v25,
        v24,
        v23,
        v22,
        v21,
        v20,
        v19,
        v18,
        v17,
        v16);
    }
  }
}

//----- (00409430) --------------------------------------------------------
int __thiscall BuildAIModule::loadBuildList(BuildAIModule *this, char *lName, RGE_Player *player)
{
  BuildAIModule *v3; // ebp@1
  const char *v4; // edi@1
  char *v5; // esi@2
  _iobuf *v6; // edi@4
  int v8; // edi@12
  int v9; // ecx@22
  int v10; // eax@22
  RGE_Master_Static_Object *v11; // eax@30
  double v12; // st7@31
  int v13; // ebx@33
  BuildItem *v14; // eax@34
  BuildItem *v15; // esi@34
  BuildItem *v16; // eax@35
  int v17; // ecx@36
  BuildItem *v18; // eax@36
  bool v19; // sf@36
  unsigned __int8 v20; // of@36
  char commentTemp2; // [sp+11h] [bp-173h]@9
  char buildCategoryAsChar; // [sp+12h] [bp-172h]@11
  char commentTemp1; // [sp+13h] [bp-171h]@9
  float ySize; // [sp+14h] [bp-170h]@9
  char *Str; // [sp+18h] [bp-16Ch]@1
  float xSize; // [sp+1Ch] [bp-168h]@9
  int buildCap; // [sp+20h] [bp-164h]@9
  int typeID; // [sp+24h] [bp-160h]@11
  int quantity; // [sp+28h] [bp-15Ch]@11
  int buildFrom; // [sp+2Ch] [bp-158h]@11
  _iobuf *fileIn; // [sp+30h] [bp-154h]@4
  BuildItem *v32; // [sp+34h] [bp-150h]@34
  char name[64]; // [sp+38h] [bp-14Ch]@11
  char temp[256]; // [sp+78h] [bp-10Ch]@4
  int v35; // [sp+180h] [bp-4h]@34

  v3 = this;
  v4 = this->buildListNameValue;
  Str = this->buildListNameValue;
  strncpy(this->buildListNameValue, lName, 0x3Fu);
  if ( !strcmp(v4, aNone_2) || (v5 = Str) == 0 || strlen(Str) == 0 )
  {
    if ( !Str )
      strcpy(0, aNull);
    AIModule::logCommonHistory((AIModule *)&v3->vfptr, aThereIsNoBuild);
  }
  else
  {
    AIModule::logCommonHistory((AIModule *)&v3->vfptr, aTryingToLoadBu, lName);
    sprintf(temp, aS_2, Str);
    v6 = fopen(temp, Mode);
    fileIn = v6;
    if ( !v6 )
    {
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aICannotDoItCap);
      return 0;
    }
    AIModule::logCommonHistory((AIModule *)&v3->vfptr, aFileOpenSucces);
    if ( v3->buildListLengthValue > 0 )
      BuildAIModule::removeOldList(v3);
    v3->buildListLengthValue = 0;
    if ( fgets(temp, 256, v6) )
    {
      do
      {
        xSize = 1.5;
        ySize = 1.5;
        buildCap = -1;
        sscanf(temp, aCC, &commentTemp1, &commentTemp2);
        if ( commentTemp1 != 47 || commentTemp2 != 47 )
        {
          sscanf(temp, aCDSDD, &buildCategoryAsChar, &typeID, name, &quantity, &buildFrom);
          switch ( buildCategoryAsChar )
          {
            case 66:
              v8 = 0;
              goto LABEL_21;
            case 65:
              v8 = 0;
              sscanf(temp, aCDSDDD, &buildCap);
              goto LABEL_21;
            case 82:
              v8 = 1;
              goto LABEL_21;
            case 67:
              v8 = 4;
              goto LABEL_21;
            case 85:
              v8 = 2;
              goto LABEL_21;
            case 84:
              v8 = 2;
              sscanf(temp, aCDSDDD, &buildCap);
              goto LABEL_21;
            case 76:
              v8 = 3;
              goto LABEL_21;
            case 69:
              v8 = 5;
              goto LABEL_21;
            case 71:
              v8 = 6;
LABEL_21:
              if ( v8 )
                goto LABEL_26;
              v9 = v3->typesToIgnore.numberValue;
              v10 = 0;
              if ( v9 <= 0 )
                goto LABEL_26;
              break;
            default:
              goto LABEL_37;
          }
          do
          {
            if ( v10 >= v3->typesToIgnore.maximumSizeValue )
              break;
            if ( v3->typesToIgnore.value[v10] == typeID )
              goto LABEL_37;
            ++v10;
          }
          while ( v10 < v9 );
LABEL_26:
          if ( v8 && v8 != 2
            || typeID < 0
            || typeID >= player->master_object_num
            || (v11 = player->master_objects[typeID]) == 0 )
          {
            v12 = xSize;
          }
          else
          {
            v12 = v11->radius_x;
            ySize = v11->radius_y;
          }
          v13 = 0;
          xSize = v12 + v12;
          ySize = ySize + ySize;
          if ( quantity > 0 )
          {
            do
            {
              v14 = (BuildItem *)operator new(0xB0u);
              v32 = v14;
              v15 = 0;
              v35 = 0;
              if ( v14 )
              {
                BuildItem::BuildItem(
                  v14,
                  v8,
                  typeID,
                  v3->buildListLengthValue,
                  1,
                  0,
                  buildFrom,
                  name,
                  xSize,
                  ySize,
                  0.0,
                  -1,
                  -1,
                  -1,
                  0);
                v15 = v16;
              }
              v17 = v3->buildListLengthValue + 1;
              v35 = -1;
              v3->buildListLengthValue = v17;
              v15->next = &v3->buildList;
              v18 = v3->buildList.prev;
              v15->prev = v18;
              v18->next = v15;
              BuildItem::setBuildCap(v15, buildCap);
              v20 = __OFSUB__(++v13, quantity);
              v19 = v13 - quantity < 0;
              v3->buildList.prev = v15;
            }
            while ( v19 ^ v20 );
          }
        }
LABEL_37:
        v6 = fileIn;
      }
      while ( fgets(temp, 256, fileIn) );
      v5 = Str;
    }
    fclose(v6);
    if ( strstr(v5, SubStr) )
      _unlink(v5);
  }
  return 1;
}

//----- (004098A0) --------------------------------------------------------
int __thiscall BuildAIModule::buildListLength(BuildAIModule *this)
{
  return this->buildListLengthValue;
}

//----- (004098B0) --------------------------------------------------------
char *__thiscall BuildAIModule::buildListName(BuildAIModule *this)
{
  return this->buildListNameValue;
}

//----- (004098C0) --------------------------------------------------------
BOOL __thiscall BuildAIModule::haveBuildList(BuildAIModule *this)
{
  return this != (BuildAIModule *)-420
      && strcmp(this->buildListNameValue, aNone_2)
      && strcmp(this->buildListNameValue, aNull);
}

//----- (00409950) --------------------------------------------------------
int __thiscall BuildAIModule::insertItem(BuildAIModule *this, RGE_Player *player, int typeID, int quantity, int buildCategory, int buildFrom, int buildCap, int insertAfterItemNumber)
{
  BuildAIModule *v8; // ebx@1
  int result; // eax@2
  BuildItem *v10; // edi@3
  char *v11; // ecx@3
  int v12; // eax@3
  RGE_Master_Static_Object *v13; // eax@7
  RGE_Master_Static_Object *v14; // eax@8
  int v15; // ebx@12
  int v16; // ebp@12
  BuildItem *v17; // eax@13
  BuildItem *v18; // esi@13
  BuildItem *v19; // eax@14
  BuildItem *v20; // eax@16
  char *v21; // [sp-Ch] [bp-70h]@9
  const char *v22; // [sp-8h] [bp-6Ch]@9
  BuildAIModule *v23; // [sp+10h] [bp-54h]@1
  char name[64]; // [sp+18h] [bp-4Ch]@8
  int v25; // [sp+60h] [bp-4h]@13
  RGE_Player *playera; // [sp+68h] [bp+4h]@8
  float insertAfterItemNumbera; // [sp+80h] [bp+1Ch]@8

  v8 = this;
  v23 = this;
  if ( insertAfterItemNumber > this->buildListLengthValue )
    return 0;
  v10 = this->buildList.next;
  v11 = (char *)&this->buildList;
  v12 = 0;
  if ( v10 != &v8->buildList )
  {
    do
    {
      if ( v12 >= insertAfterItemNumber )
        break;
      v10 = v10->next;
      ++v12;
    }
    while ( (char *)v10 != v11 );
  }
  if ( buildCategory == 6 )
  {
    v22 = Source;
    v21 = name;
  }
  else
  {
    v13 = player->master_objects[typeID];
    if ( v13 )
    {
      strncpy(name, v13->name, 0x3Fu);
      v14 = player->master_objects[typeID];
      *(float *)&playera = v14->radius_x + v14->radius_x;
      insertAfterItemNumbera = v14->radius_y + v14->radius_y;
      goto LABEL_12;
    }
    v22 = aAddedbuildlist;
    v21 = name;
  }
  strncpy(v21, v22, 0x3Fu);
  *(float *)&playera = 3.0;
  insertAfterItemNumbera = 3.0;
LABEL_12:
  v15 = v8->buildListLengthValue;
  v16 = 0;
  if ( quantity <= 0 )
  {
LABEL_17:
    result = 1;
  }
  else
  {
    while ( 1 )
    {
      v17 = (BuildItem *)operator new(0xB0u);
      v18 = 0;
      v25 = 0;
      if ( v17 )
      {
        BuildItem::BuildItem(
          v17,
          buildCategory,
          typeID,
          v15,
          1,
          0,
          buildFrom,
          name,
          *(float *)&playera,
          insertAfterItemNumbera,
          1.0,
          -1,
          -1,
          -1,
          0);
        v18 = v19;
      }
      v25 = -1;
      if ( !v18 )
        break;
      BuildItem::setBuilt(v18, 0);
      BuildItem::setInProgress(v18, 0);
      BuildItem::setBuildAttempts(v18, 0);
      BaseItem::setSkip((BaseItem *)&v18->vfptr, 0);
      BaseItem::setGameID((BaseItem *)&v18->vfptr, -1);
      BaseItem::setX((BaseItem *)&v18->vfptr, -1.0);
      BaseItem::setY((BaseItem *)&v18->vfptr, -1.0);
      BaseItem::setZ((BaseItem *)&v18->vfptr, -1.0);
      BuildItem::setNumberBuilds(v18, 0);
      BuildItem::setBuildCap(v18, buildCap);
      BuildItem::setSkipCycles(v18, 0);
      BuildItem::setPermanentSkip(v18, 0);
      v18->prev = v10;
      v20 = v10->next;
      v18->next = v20;
      ++v15;
      v20->prev = v18;
      v10->next = v18;
      ++v16;
      ++v23->buildListLengthValue;
      if ( v16 >= quantity )
        goto LABEL_17;
    }
    result = 0;
  }
  return result;
}

//----- (00409B70) --------------------------------------------------------
int __thiscall BuildAIModule::numberItemsBuilt(BuildAIModule *this)
{
  BuildItem *v1; // esi@1
  char *v2; // edi@1
  int v3; // ebx@1

  v1 = this->buildList.next;
  v2 = (char *)&this->buildList;
  v3 = 0;
  if ( v1 != &this->buildList )
  {
    do
    {
      if ( !v1 )
        break;
      if ( BuildItem::built(v1) == 1 )
        ++v3;
      v1 = v1->next;
    }
    while ( (char *)v1 != v2 );
  }
  return v3;
}

//----- (00409BB0) --------------------------------------------------------
int __thiscall BuildAIModule::numberItemsInProgress(BuildAIModule *this)
{
  BuildItem *v1; // esi@1
  char *v2; // edi@1
  int v3; // ebx@1

  v1 = this->buildList.next;
  v2 = (char *)&this->buildList;
  v3 = 0;
  if ( v1 != &this->buildList )
  {
    do
    {
      if ( !v1 )
        break;
      if ( BuildItem::inProgress(v1) == 1 )
        ++v3;
      v1 = v1->next;
    }
    while ( (char *)v1 != v2 );
  }
  return v3;
}

//----- (00409BF0) --------------------------------------------------------
int __thiscall BuildAIModule::numberItemsBuiltOrInProgress(BuildAIModule *this)
{
  BuildItem *v1; // esi@1
  char *v2; // edi@1
  int v3; // ebx@1

  v1 = this->buildList.next;
  v2 = (char *)&this->buildList;
  v3 = 0;
  if ( v1 != &this->buildList )
  {
    do
    {
      if ( !v1 )
        break;
      if ( BuildItem::inProgress(v1) == 1 || BuildItem::built(v1) == 1 )
        ++v3;
      v1 = v1->next;
    }
    while ( (char *)v1 != v2 );
  }
  return v3;
}

//----- (00409C30) --------------------------------------------------------
int __thiscall BuildAIModule::numberItemsIntoBuildList(BuildAIModule *this)
{
  return this->numberItemsIntoBuildListValue;
}

//----- (00409C40) --------------------------------------------------------
char *__thiscall BuildAIModule::lastBuildItemRequested(BuildAIModule *this)
{
  return this->lastBuildItemRequestedValue;
}

//----- (00409C50) --------------------------------------------------------
char *__thiscall BuildAIModule::currentBuildItemRequested(BuildAIModule *this)
{
  return this->currentBuildItemRequestedValue;
}

//----- (00409C60) --------------------------------------------------------
char *__thiscall BuildAIModule::nextBuildItemRequested(BuildAIModule *this)
{
  return this->nextBuildItemRequestedValue;
}

//----- (00409C70) --------------------------------------------------------
int __thiscall BuildAIModule::numberItemsOfType(BuildAIModule *this, int type, int category)
{
  BuildItem *v3; // esi@1
  char *v4; // edi@1
  int count; // [sp+10h] [bp-4h]@1

  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  count = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 )
        break;
      if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == type && BuildItem::buildCategory(v3) == category )
        ++count;
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
  }
  return count;
}

//----- (00409CD0) --------------------------------------------------------
int __thiscall BuildAIModule::numberBuiltItemsOfType(BuildAIModule *this, int type, int category)
{
  BuildItem *v3; // esi@1
  char *v4; // edi@1
  int count; // [sp+10h] [bp-4h]@1

  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  count = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 )
        break;
      if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == type
        && BuildItem::buildCategory(v3) == category
        && BuildItem::built(v3) == 1 )
      {
        ++count;
      }
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
  }
  return count;
}

//----- (00409D40) --------------------------------------------------------
int __thiscall BuildAIModule::numberUnbuiltItemsOfType(BuildAIModule *this, int type, int category)
{
  BuildItem *v3; // esi@1
  char *v4; // edi@1
  int count; // [sp+10h] [bp-4h]@1

  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  count = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 )
        break;
      if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == type
        && BuildItem::buildCategory(v3) == category
        && !BuildItem::built(v3) )
      {
        ++count;
      }
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
  }
  return count;
}

//----- (00409DB0) --------------------------------------------------------
int __thiscall BuildAIModule::numberBuiltOrInProgressItemsOfType(BuildAIModule *this, int type, int category)
{
  BuildItem *v3; // esi@1
  char *v4; // edi@1
  int count; // [sp+10h] [bp-4h]@1

  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  count = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 )
        break;
      if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == type
        && BuildItem::buildCategory(v3) == category
        && (BuildItem::built(v3) == 1 || BuildItem::inProgress(v3) == 1) )
      {
        ++count;
      }
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
  }
  return count;
}

//----- (00409E20) --------------------------------------------------------
int __thiscall BuildAIModule::numberInProgressItemsOfType(BuildAIModule *this, int type, int category)
{
  BuildItem *v3; // esi@1
  char *v4; // edi@1
  int count; // [sp+10h] [bp-4h]@1

  v3 = this->buildList.next;
  v4 = (char *)&this->buildList;
  count = 0;
  if ( v3 != &this->buildList )
  {
    do
    {
      if ( !v3 )
        break;
      if ( BaseItem::typeID((BaseItem *)&v3->vfptr) == type
        && BuildItem::buildCategory(v3) == category
        && BuildItem::inProgress(v3) == 1 )
      {
        ++count;
      }
      v3 = v3->next;
    }
    while ( (char *)v3 != v4 );
  }
  return count;
}

//----- (00409E90) --------------------------------------------------------
void __thiscall BuildAIModule::removeOldList(BuildAIModule *this)
{
  BuildAIModule *v1; // ebx@1
  BuildItem *v2; // ecx@1
  int v3; // edi@1
  BuildItem *v4; // esi@3

  v1 = this;
  v2 = this->buildList.next;
  v3 = (int)&v1->buildList;
  if ( v2 != &v1->buildList )
  {
    do
    {
      if ( !v2 )
        break;
      v4 = v2->next;
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      v2 = v4;
    }
    while ( v4 != (BuildItem *)v3 );
  }
  v1->buildList.next = (BuildItem *)v3;
  v1->buildList.prev = (BuildItem *)v3;
  v1->buildListLengthValue = 0;
}

//----- (00409EE0) --------------------------------------------------------
BuildItem *__thiscall BuildAIModule::anyBuildListItem(BuildAIModule *this, int id, int checkBuilt, int buildStatus)
{
  BuildItem *v4; // esi@1
  char *v5; // ebx@1

  v4 = this->buildList.next;
  v5 = (char *)&this->buildList;
  if ( v4 != &this->buildList )
  {
    while ( v4 )
    {
      if ( BaseItem::typeID((BaseItem *)&v4->vfptr) == id
        && (!checkBuilt || checkBuilt == 1 && BuildItem::built(v4) == buildStatus) )
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

//----- (00409F50) --------------------------------------------------------
BuildItem *__thiscall BuildAIModule::specificBuildListItem(BuildAIModule *this, int id)
{
  BuildItem *v2; // esi@1
  char *v3; // edi@1

  v2 = this->buildList.next;
  v3 = (char *)&this->buildList;
  if ( v2 != &this->buildList )
  {
    while ( v2 )
    {
      if ( BaseItem::uniqueID((BaseItem *)&v2->vfptr) == id )
        return v2;
      v2 = v2->next;
      if ( (char *)v2 == v3 )
        return 0;
    }
  }
  return 0;
}
