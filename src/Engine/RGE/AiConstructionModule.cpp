
//----- (0040AA90) --------------------------------------------------------
void __thiscall ConstructionAIModule::ConstructionAIModule(ConstructionAIModule *this, void *pW, int playerID)
{
  ConstructionAIModule *v3; // ebx@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aConai, 1002, playerID, pW);
  v3->numberConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(&v3->constructionLots);
  v3->numberRandomConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(&v3->randomConstructionLots);
  LODWORD(v3->xReferencePointValue) = -1082130432;
  LODWORD(v3->yReferencePointValue) = -1082130432;
  LODWORD(v3->zReferencePointValue) = -1082130432;
  v3->randomConstructionLots.next = &v3->randomConstructionLots;
  v3->randomConstructionLots.prev = &v3->randomConstructionLots;
  v3->mapXSizeValue = -1;
  v3->mapYSizeValue = -1;
  v3->lastPlacementReturnCodeValue = 0;
  v3->vfptr = (AIModuleVtbl *)&ConstructionAIModule::`vftable';
  v3->constructionLots.next = &v3->constructionLots;
  v3->constructionLots.prev = &v3->constructionLots;
  strcpy(v3->constructionPlanNameValue, message_in);
}
// 56E7A0: using guessed type int (__thiscall *ConstructionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040AB90) --------------------------------------------------------
ConstructionAIModule *__thiscall ConstructionAIModule::`scalar deleting destructor'(ConstructionAIModule *this, unsigned int __flags)
{
  ConstructionAIModule *v2; // esi@1

  v2 = this;
  ConstructionAIModule::~ConstructionAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040ABB0) --------------------------------------------------------
void __thiscall ConstructionAIModule::ConstructionAIModule(ConstructionAIModule *this, int playerID, int infile)
{
  ConstructionAIModule *v3; // edi@1
  int *v4; // ebx@1
  ConstructionItem *v5; // ebp@1
  bool v6; // zf@1
  bool v7; // sf@1
  ConstructionItem *v8; // eax@2
  ConstructionItem *v9; // eax@3
  ConstructionItem *v10; // eax@5
  int v11; // eax@5
  unsigned __int8 v12; // of@5
  ConstructionItem *v13; // ebp@6
  int v14; // ebx@6
  ConstructionItem *v15; // eax@7
  ConstructionItem *v16; // eax@8
  ConstructionItem *v17; // eax@10
  int v18; // eax@10
  int tempInt; // [sp+10h] [bp-154h]@1
  float x; // [sp+14h] [bp-150h]@2
  int inProgressValue; // [sp+18h] [bp-14Ch]@2
  int builtValue; // [sp+1Ch] [bp-148h]@2
  float zSize; // [sp+20h] [bp-144h]@2
  int buildAttemptsValue; // [sp+24h] [bp-140h]@2
  float xSize; // [sp+28h] [bp-13Ch]@2
  int gameID; // [sp+2Ch] [bp-138h]@2
  float y; // [sp+30h] [bp-134h]@2
  int uniqueID; // [sp+34h] [bp-130h]@2
  int typeID; // [sp+38h] [bp-12Ch]@2
  int skipValue; // [sp+3Ch] [bp-128h]@2
  float z; // [sp+40h] [bp-124h]@2
  float ySize; // [sp+44h] [bp-120h]@2
  int i; // [sp+48h] [bp-11Ch]@1
  ConstructionItem *v34; // [sp+4Ch] [bp-118h]@2
  ConstructionAIModule *v35; // [sp+50h] [bp-114h]@1
  char name[257]; // [sp+54h] [bp-110h]@2
  int v37; // [sp+160h] [bp-4h]@1

  v3 = this;
  v35 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aConai, 1002, playerID, 0);
  v4 = &v3->numberConstructionLotsValue;
  v37 = 0;
  v3->numberConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(&v3->constructionLots);
  v5 = &v3->randomConstructionLots;
  v3->numberRandomConstructionLotsValue = 0;
  ConstructionItem::ConstructionItem(&v3->randomConstructionLots);
  v3->constructionLots.next = &v3->constructionLots;
  v3->constructionLots.prev = &v3->constructionLots;
  LOBYTE(v37) = 2;
  LODWORD(v3->xReferencePointValue) = -1082130432;
  LODWORD(v3->yReferencePointValue) = -1082130432;
  LODWORD(v3->zReferencePointValue) = -1082130432;
  v3->mapXSizeValue = -1;
  v3->mapYSizeValue = -1;
  v3->lastPlacementReturnCodeValue = 0;
  v3->vfptr = (AIModuleVtbl *)&ConstructionAIModule::`vftable';
  v3->randomConstructionLots.next = &v3->randomConstructionLots;
  v3->randomConstructionLots.prev = &v3->randomConstructionLots;
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &v3->numberConstructionLotsValue, 4);
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &tempInt, 4);
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, v3->constructionPlanNameValue, tempInt);
  v3->constructionPlanNameValue[tempInt] = 0;
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &v3->xReferencePointValue, 4);
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &v3->yReferencePointValue, 4);
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &v3->zReferencePointValue, 4);
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &v3->mapXSizeValue, 4);
  rge_read((int)&v3->randomConstructionLots, (int)v3, infile, &v3->mapYSizeValue, 4);
  v6 = v3->numberConstructionLotsValue == 0;
  v7 = v3->numberConstructionLotsValue < 0;
  i = 0;
  if ( !v7 && !v6 )
  {
    do
    {
      rge_read((int)v5, (int)v3, infile, &tempInt, 4);
      rge_read((int)v5, (int)v3, infile, name, tempInt);
      name[tempInt] = 0;
      rge_read((int)v5, (int)v3, infile, &typeID, 4);
      rge_read((int)v5, (int)v3, infile, &gameID, 4);
      rge_read((int)v5, (int)v3, infile, &uniqueID, 4);
      rge_read((int)v5, (int)v3, infile, &x, 4);
      rge_read((int)v5, (int)v3, infile, &y, 4);
      rge_read((int)v5, (int)v3, infile, &z, 4);
      rge_read((int)v5, (int)v3, infile, &xSize, 4);
      rge_read((int)v5, (int)v3, infile, &ySize, 4);
      rge_read((int)v5, (int)v3, infile, &zSize, 4);
      rge_read((int)v5, (int)v3, infile, &skipValue, 4);
      rge_read((int)v5, (int)v3, infile, &inProgressValue, 4);
      rge_read((int)v5, (int)v3, infile, &builtValue, 4);
      rge_read((int)v5, (int)v3, infile, &buildAttemptsValue, 4);
      v8 = (ConstructionItem *)operator new(0x80u);
      v34 = v8;
      LOBYTE(v37) = 3;
      if ( v8 )
      {
        ConstructionItem::ConstructionItem(v8, x, y, z, xSize, ySize, zSize, typeID, name);
        v5 = v9;
      }
      else
      {
        v5 = 0;
      }
      LOBYTE(v37) = 2;
      ConstructionItem::setInProgress(v5, inProgressValue);
      ConstructionItem::setBuilt(v5, builtValue);
      ConstructionItem::setBuildAttempts(v5, buildAttemptsValue);
      BaseItem::setGameID((BaseItem *)&v5->vfptr, gameID);
      BaseItem::setUniqueID((BaseItem *)&v5->vfptr, uniqueID);
      BaseItem::setSkip((BaseItem *)&v5->vfptr, skipValue);
      v5->next = &v3->constructionLots;
      v10 = v3->constructionLots.prev;
      v5->prev = v10;
      v10->next = v5;
      v11 = i + 1;
      v12 = __OFSUB__(i + 1, *v4);
      v7 = i + 1 - *v4 < 0;
      v3->constructionLots.prev = v5;
      i = v11;
    }
    while ( v7 ^ v12 );
  }
  v13 = (ConstructionItem *)&v3->numberRandomConstructionLotsValue;
  rge_read((int)&v3->numberRandomConstructionLotsValue, (int)v3, infile, &v3->numberRandomConstructionLotsValue, 4);
  v14 = 0;
  if ( v3->numberRandomConstructionLotsValue > 0 )
  {
    do
    {
      rge_read((int)v13, (int)v3, infile, &tempInt, 4);
      rge_read((int)v13, (int)v3, infile, name, tempInt);
      name[tempInt] = 0;
      rge_read((int)v13, (int)v3, infile, &skipValue, 4);
      rge_read((int)v13, (int)v3, infile, &ySize, 4);
      rge_read((int)v13, (int)v3, infile, &zSize, 4);
      rge_read((int)v13, (int)v3, infile, &x, 4);
      rge_read((int)v13, (int)v3, infile, &inProgressValue, 4);
      rge_read((int)v13, (int)v3, infile, &builtValue, 4);
      rge_read((int)v13, (int)v3, infile, &buildAttemptsValue, 4);
      rge_read((int)v13, (int)v3, infile, &gameID, 4);
      rge_read((int)v13, (int)v3, infile, &uniqueID, 4);
      rge_read((int)v13, (int)v3, infile, &typeID, 4);
      rge_read((int)v13, (int)v3, infile, &y, 4);
      rge_read((int)v13, (int)v3, infile, &z, 4);
      rge_read((int)v13, (int)v3, infile, &xSize, 4);
      v15 = (ConstructionItem *)operator new(0x80u);
      v34 = v15;
      LOBYTE(v37) = 4;
      if ( v15 )
      {
        ConstructionItem::ConstructionItem(
          v15,
          x,
          *(float *)&inProgressValue,
          *(float *)&builtValue,
          *(float *)&buildAttemptsValue,
          *(float *)&gameID,
          *(float *)&uniqueID,
          skipValue,
          name);
        v13 = v16;
      }
      else
      {
        v13 = 0;
      }
      LOBYTE(v37) = 2;
      ConstructionItem::setInProgress(v13, SLODWORD(y));
      ConstructionItem::setBuilt(v13, SLODWORD(z));
      ConstructionItem::setBuildAttempts(v13, SLODWORD(xSize));
      BaseItem::setGameID((BaseItem *)&v13->vfptr, SLODWORD(ySize));
      BaseItem::setUniqueID((BaseItem *)&v13->vfptr, SLODWORD(zSize));
      BaseItem::setSkip((BaseItem *)&v13->vfptr, typeID);
      ++v14;
      v13->next = &v3->randomConstructionLots;
      v17 = v3->randomConstructionLots.prev;
      v13->prev = v17;
      v17->next = v13;
      v18 = v3->numberRandomConstructionLotsValue;
      v3->randomConstructionLots.prev = v13;
    }
    while ( v14 < v18 );
  }
}
// 56E7A0: using guessed type int (__thiscall *ConstructionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040B120) --------------------------------------------------------
void __thiscall ConstructionAIModule::~ConstructionAIModule(ConstructionAIModule *this)
{
  ConstructionAIModule *v1; // esi@1

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&ConstructionAIModule::`vftable';
  if ( this->numberConstructionLotsValue > 0 )
    ConstructionAIModule::removeOldLots(this);
  ConstructionItem::~ConstructionItem(&v1->randomConstructionLots);
  ConstructionItem::~ConstructionItem(&v1->constructionLots);
  AIModule::~AIModule((AIModule *)&v1->vfptr);
}
// 56E7A0: using guessed type int (__thiscall *ConstructionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040B1A0) --------------------------------------------------------
int __thiscall ConstructionAIModule::save(ConstructionAIModule *this, int outfile)
{
  ConstructionAIModule *v2; // ebp@1
  BaseItem *v3; // ebp@1
  ConstructionAIModule *v4; // esi@4
  BaseItem *v5; // ebp@4
  int tempInt; // [sp+10h] [bp-118h]@1
  float tempFloat; // [sp+14h] [bp-114h]@3
  int tempBOOL; // [sp+18h] [bp-110h]@3
  ConstructionItem *v10; // [sp+1Ch] [bp-10Ch]@1
  ConstructionAIModule *v11; // [sp+20h] [bp-108h]@1
  char tempString[257]; // [sp+24h] [bp-104h]@1

  v2 = this;
  v11 = this;
  rge_write(outfile, &this->numberConstructionLotsValue, 4);
  strcpy(tempString, v2->constructionPlanNameValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  rge_write(outfile, &v2->xReferencePointValue, 4);
  rge_write(outfile, &v2->yReferencePointValue, 4);
  rge_write(outfile, &v2->zReferencePointValue, 4);
  rge_write(outfile, &v2->mapXSizeValue, 4);
  rge_write(outfile, &v2->mapYSizeValue, 4);
  v3 = (BaseItem *)&v2->constructionLots.next->vfptr;
  v10 = &v11->constructionLots;
  if ( (ConstructionItem *)v3 != &v11->constructionLots )
  {
    do
    {
      if ( !v3 )
        break;
      strcpy(tempString, BaseItem::name(v3));
      tempInt = strlen(tempString);
      rge_write(outfile, &tempInt, 4);
      rge_write(outfile, tempString, tempInt);
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
      tempBOOL = ConstructionItem::inProgress((ConstructionItem *)v3);
      rge_write(outfile, &tempBOOL, 4);
      tempBOOL = ConstructionItem::built((ConstructionItem *)v3);
      rge_write(outfile, &tempBOOL, 4);
      tempInt = ConstructionItem::buildAttempts((ConstructionItem *)v3);
      rge_write(outfile, &tempInt, 4);
      v3 = (BaseItem *)v3[1].vfptr;
    }
    while ( (ConstructionItem *)v3 != v10 );
  }
  v4 = v11;
  rge_write(outfile, &v11->numberRandomConstructionLotsValue, 4);
  v5 = (BaseItem *)&v4->randomConstructionLots.next->vfptr;
  v10 = &v4->randomConstructionLots;
  if ( (ConstructionItem *)v5 != &v4->randomConstructionLots )
  {
    do
    {
      if ( !v5 )
        break;
      strcpy(tempString, BaseItem::name(v5));
      tempInt = strlen(tempString);
      rge_write(outfile, &tempInt, 4);
      rge_write(outfile, tempString, tempInt);
      tempInt = BaseItem::typeID(v5);
      rge_write(outfile, &tempInt, 4);
      tempInt = BaseItem::gameID(v5);
      rge_write(outfile, &tempInt, 4);
      tempInt = BaseItem::uniqueID(v5);
      rge_write(outfile, &tempInt, 4);
      tempFloat = BaseItem::x(v5);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::y(v5);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::z(v5);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::xSize(v5);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::ySize(v5);
      rge_write(outfile, &tempFloat, 4);
      tempFloat = BaseItem::zSize(v5);
      rge_write(outfile, &tempFloat, 4);
      tempBOOL = BaseItem::skip(v5);
      rge_write(outfile, &tempBOOL, 4);
      tempBOOL = ConstructionItem::inProgress((ConstructionItem *)v5);
      rge_write(outfile, &tempBOOL, 4);
      tempBOOL = ConstructionItem::built((ConstructionItem *)v5);
      rge_write(outfile, &tempBOOL, 4);
      tempInt = ConstructionItem::buildAttempts((ConstructionItem *)v5);
      rge_write(outfile, &tempInt, 4);
      v5 = (BaseItem *)v5[1].vfptr;
    }
    while ( (ConstructionItem *)v5 != v10 );
  }
  return 1;
}

//----- (0040B690) --------------------------------------------------------
FILE *__thiscall ConstructionAIModule::loadConstructionPlan(ConstructionAIModule *this, char *pName, int mXSize, int mYSize, float xRef, float yRef, float zRef)
{
  ConstructionAIModule *v7; // ebp@1
  const char *v8; // ebx@3
  FILE *result; // eax@5
  FILE *v10; // esi@5
  ConstructionItem *v11; // eax@10
  ConstructionItem *v12; // eax@11
  ConstructionItem *v13; // ecx@13
  char commentTemp1; // [sp+12h] [bp-172h]@7
  char commentTemp2; // [sp+13h] [bp-171h]@7
  float y; // [sp+14h] [bp-170h]@9
  float x; // [sp+18h] [bp-16Ch]@9
  float z; // [sp+1Ch] [bp-168h]@9
  float zSize; // [sp+20h] [bp-164h]@9
  char *v20; // [sp+24h] [bp-160h]@3
  int id; // [sp+28h] [bp-15Ch]@9
  float xSize; // [sp+2Ch] [bp-158h]@9
  float ySize; // [sp+30h] [bp-154h]@9
  ConstructionItem *v24; // [sp+34h] [bp-150h]@10
  char name[64]; // [sp+38h] [bp-14Ch]@9
  char temp[256]; // [sp+78h] [bp-10Ch]@5
  int v27; // [sp+180h] [bp-4h]@10

  v7 = this;
  ConstructionAIModule::setReferencePoint(this, mXSize, mYSize, xRef, yRef, zRef);
  if ( v7->numberConstructionLotsValue > 0 )
    ConstructionAIModule::removeOldLots(v7);
  v8 = v7->constructionPlanNameValue;
  v20 = v7->constructionPlanNameValue;
  strncpy(v7->constructionPlanNameValue, pName, 0x3Fu);
  if ( !strcmp(v7->constructionPlanNameValue, aNone_2) )
  {
    if ( v7 != (ConstructionAIModule *)-504 )
    {
LABEL_20:
      AIModule::logCommonHistory((AIModule *)&v7->vfptr, aThereIsNoConst);
      return (FILE *)1;
    }
LABEL_19:
    strcpy(0, aNull);
    goto LABEL_20;
  }
  if ( v7 == (ConstructionAIModule *)-504 )
    goto LABEL_19;
  AIModule::logCommonHistory((AIModule *)&v7->vfptr, aLoadingConstru, pName);
  sprintf(temp, aS_2, v7->constructionPlanNameValue);
  result = fopen(temp, Mode);
  v10 = result;
  if ( !result )
    return result;
  if ( fgets(temp, 256, result) )
  {
    do
    {
      sscanf(temp, aCC, &commentTemp1, &commentTemp2);
      if ( commentTemp1 != 47 || commentTemp2 != 47 )
      {
        sscanf(temp, aFFFFFFDS, &x, &y, &z, &xSize, &ySize, &zSize, &id, name);
        x = v7->xReferencePointValue + x;
        y = v7->yReferencePointValue + y;
        z = v7->zReferencePointValue + z;
        if ( !ConstructionAIModule::lot(v7, x, y) )
        {
          v11 = (ConstructionItem *)operator new(0x80u);
          v24 = v11;
          v27 = 0;
          if ( v11 )
            ConstructionItem::ConstructionItem(v11, x, y, z, xSize, ySize, zSize, id, name);
          else
            v12 = 0;
          v27 = -1;
          v12->next = &v7->constructionLots;
          v13 = v7->constructionLots.prev;
          v12->prev = v13;
          v13->next = v12;
          v7->constructionLots.prev = v12;
          ++v7->numberConstructionLotsValue;
        }
      }
    }
    while ( fgets(temp, 256, v10) );
    v8 = v20;
  }
  fclose(v10);
  if ( strstr(v8, SubStr) )
    _unlink(v8);
  return (FILE *)1;
}

//----- (0040B970) --------------------------------------------------------
char *__thiscall ConstructionAIModule::constructionPlanName(ConstructionAIModule *this)
{
  return this->constructionPlanNameValue;
}

//----- (0040B980) --------------------------------------------------------
void __thiscall ConstructionAIModule::setReferencePoint(ConstructionAIModule *this, int mXSize, int mYSize, float x, float y, float z)
{
  ConstructionAIModule *v6; // ebx@1
  ConstructionItem *v7; // esi@5
  float v; // ST00_4@7
  float v9; // ST00_4@7
  float v10; // ST00_4@7
  ConstructionItem *v11; // edi@12
  int mXSizea; // [sp+18h] [bp+4h]@7
  int mXSizeb; // [sp+18h] [bp+4h]@8
  int mXSizec; // [sp+18h] [bp+4h]@9
  int mXSized; // [sp+18h] [bp+4h]@10

  v6 = this;
  this->mapXSizeValue = mXSize;
  this->yReferencePointValue = y;
  this->mapYSizeValue = mYSize;
  this->xReferencePointValue = x;
  this->zReferencePointValue = z;
  if ( x <= 0.0 || y <= 0.0 || (double)mXSize <= x || (double)mYSize <= y )
  {
    ConstructionAIModule::removeOldLots(this);
  }
  else
  {
    v7 = this->constructionLots.next;
    if ( v7 != &this->constructionLots )
    {
      do
      {
        if ( !v7 )
          break;
        v = BaseItem::x((BaseItem *)&v7->vfptr) + x;
        BaseItem::setX((BaseItem *)&v7->vfptr, v);
        v9 = BaseItem::y((BaseItem *)&v7->vfptr) + y;
        BaseItem::setY((BaseItem *)&v7->vfptr, v9);
        v10 = BaseItem::z((BaseItem *)&v7->vfptr) + z;
        BaseItem::setZ((BaseItem *)&v7->vfptr, v10);
        *(float *)&mXSizea = BaseItem::x((BaseItem *)&v7->vfptr);
        if ( *(float *)&mXSizea - BaseItem::xSize((BaseItem *)&v7->vfptr) * 0.5 < 0.0
          || (*(float *)&mXSizeb = BaseItem::y((BaseItem *)&v7->vfptr),
              *(float *)&mXSizeb - BaseItem::ySize((BaseItem *)&v7->vfptr) * 0.5 < 0.0)
          || (*(float *)&mXSizec = BaseItem::x((BaseItem *)&v7->vfptr),
              (double)(v6->mapXSizeValue - 1) < *(float *)&mXSizec - BaseItem::xSize((BaseItem *)&v7->vfptr) * -0.5)
          || (*(float *)&mXSized = BaseItem::y((BaseItem *)&v7->vfptr),
              (double)(v6->mapYSizeValue - 1) < *(float *)&mXSized - BaseItem::ySize((BaseItem *)&v7->vfptr) * -0.5) )
        {
          --v6->numberConstructionLotsValue;
          v11 = v7->next;
          v7->prev->next = v11;
          v7->next->prev = v7->prev;
          v7->vfptr->__vecDelDtor((BaseItem *)v7, 1u);
          v7 = v11;
        }
        else
        {
          v7 = v7->next;
        }
      }
      while ( v7 != &v6->constructionLots );
    }
  }
}

//----- (0040BB70) --------------------------------------------------------
double __thiscall ConstructionAIModule::xReferencePoint(ConstructionAIModule *this)
{
  return this->xReferencePointValue;
}

//----- (0040BB80) --------------------------------------------------------
double __thiscall ConstructionAIModule::yReferencePoint(ConstructionAIModule *this)
{
  return this->yReferencePointValue;
}

//----- (0040BB90) --------------------------------------------------------
ConstructionItem *__stdcall ConstructionAIModule::placeStructure(BuildItem *bi)
{
  return 0;
}

//----- (0040BBA0) --------------------------------------------------------
ConstructionAIModule::PlacementResult __thiscall ConstructionAIModule::lastPlacementReturnCode(ConstructionAIModule *this)
{
  return this->lastPlacementReturnCodeValue;
}

//----- (0040BBB0) --------------------------------------------------------
void __thiscall ConstructionAIModule::setBuilt(ConstructionAIModule *this, ConstructionItem *ci, int v)
{
  ConstructionItem *v3; // esi@1
  char *v4; // edi@1

  v3 = this->constructionLots.next;
  v4 = (char *)&this->constructionLots;
  if ( v3 != &this->constructionLots )
  {
    while ( v3 )
    {
      if ( operator==(v3, ci) )
      {
        ConstructionItem::setBuilt(v3, v);
        return;
      }
      v3 = v3->next;
      if ( (char *)v3 == v4 )
        return;
    }
  }
}

//----- (0040BC00) --------------------------------------------------------
int __thiscall ConstructionAIModule::unplaceStructure(ConstructionAIModule *this, ConstructionItem *ci, int decBA)
{
  ConstructionItem *v3; // esi@1
  char *v4; // edi@1
  int v6; // edi@6

  v3 = this->constructionLots.next;
  v4 = (char *)&this->constructionLots;
  if ( v3 != &this->constructionLots )
  {
    while ( v3 )
    {
      if ( operator==(v3, ci) )
      {
        ConstructionItem::setInProgress(v3, 0);
        ConstructionItem::setBuilt(v3, 0);
        v6 = BaseItem::uniqueID((BaseItem *)&v3->vfptr);
        BaseItem::setUniqueID((BaseItem *)&v3->vfptr, -1);
        if ( decBA == 1 )
          ConstructionItem::decrementBuildAttempts(v3);
        return v6;
      }
      v3 = v3->next;
      if ( (char *)v3 == v4 )
        return -1;
    }
  }
  return -1;
}

//----- (0040BC80) --------------------------------------------------------
int __thiscall ConstructionAIModule::unplaceStructure(ConstructionAIModule *this, float x, float y, int decBA)
{
  ConstructionItem *v4; // esi@1
  char *v5; // edi@1
  int v7; // edi@7

  v4 = this->constructionLots.next;
  v5 = (char *)&this->constructionLots;
  if ( v4 != &this->constructionLots )
  {
    while ( v4 )
    {
      if ( BaseItem::x((BaseItem *)&v4->vfptr) == x && BaseItem::y((BaseItem *)&v4->vfptr) == y )
      {
        ConstructionItem::setInProgress(v4, 0);
        ConstructionItem::setBuilt(v4, 0);
        v7 = BaseItem::uniqueID((BaseItem *)&v4->vfptr);
        BaseItem::setUniqueID((BaseItem *)&v4->vfptr, -1);
        if ( decBA == 1 )
          ConstructionItem::decrementBuildAttempts(v4);
        return v7;
      }
      v4 = v4->next;
      if ( (char *)v4 == v5 )
        return -1;
    }
  }
  return -1;
}

//----- (0040BD10) --------------------------------------------------------
void __thiscall ConstructionAIModule::decrementBuildAttempts(ConstructionAIModule *this, float x, float y, int n)
{
  ConstructionItem *v4; // esi@1
  int v5; // edi@2

  v4 = ConstructionAIModule::lot(this, x, y);
  if ( v4 )
  {
    v5 = n;
    if ( n > 0 )
    {
      do
      {
        ConstructionItem::decrementBuildAttempts(v4);
        --v5;
      }
      while ( v5 );
    }
  }
}

//----- (0040BD40) --------------------------------------------------------
void __thiscall ConstructionAIModule::incrementBuildAttempts(ConstructionAIModule *this, float x, float y, int n)
{
  ConstructionItem *v4; // esi@1
  int v5; // edi@2

  v4 = ConstructionAIModule::lot(this, x, y);
  if ( v4 )
  {
    v5 = n;
    if ( n > 0 )
    {
      do
      {
        ConstructionItem::incrementBuildAttempts(v4);
        --v5;
      }
      while ( v5 );
    }
  }
}

//----- (0040BD70) --------------------------------------------------------
ConstructionItem *__thiscall ConstructionAIModule::lot(ConstructionAIModule *this, float x, float y)
{
  ConstructionAIModule *v3; // ebx@1
  ConstructionItem *v4; // esi@1
  char *v5; // edi@1

  v3 = this;
  v4 = this->constructionLots.next;
  v5 = (char *)&this->constructionLots;
  if ( v4 != &this->constructionLots )
  {
    while ( v4 )
    {
      if ( BaseItem::x((BaseItem *)&v4->vfptr) == x && BaseItem::y((BaseItem *)&v4->vfptr) == y )
        return v4;
      v4 = v4->next;
      if ( (char *)v4 == v5 )
        break;
    }
  }
  v4 = v3->randomConstructionLots.next;
  if ( v4 != &v3->randomConstructionLots )
  {
    while ( v4 )
    {
      if ( BaseItem::x((BaseItem *)&v4->vfptr) == x && BaseItem::y((BaseItem *)&v4->vfptr) == y )
        return v4;
      v4 = v4->next;
      if ( v4 == &v3->randomConstructionLots )
        return 0;
    }
  }
  return 0;
}

//----- (0040BE10) --------------------------------------------------------
ConstructionItem *__thiscall ConstructionAIModule::randomLot(ConstructionAIModule *this, float x, float y)
{
  ConstructionItem *v3; // esi@1
  char *v4; // edi@1

  v3 = this->randomConstructionLots.next;
  v4 = (char *)&this->randomConstructionLots;
  if ( v3 != &this->randomConstructionLots )
  {
    while ( v3 )
    {
      if ( BaseItem::x((BaseItem *)&v3->vfptr) == x && BaseItem::y((BaseItem *)&v3->vfptr) == y )
        return v3;
      v3 = v3->next;
      if ( (char *)v3 == v4 )
        return 0;
    }
  }
  return 0;
}

//----- (0040BE70) --------------------------------------------------------
void __thiscall ConstructionAIModule::removeOldLots(ConstructionAIModule *this)
{
  ConstructionAIModule *v1; // ebx@1
  ConstructionItem *v2; // ecx@1
  int v3; // edi@1
  ConstructionItem *v4; // esi@3

  v1 = this;
  v2 = this->constructionLots.next;
  v3 = (int)&v1->constructionLots;
  if ( v2 != &v1->constructionLots )
  {
    do
    {
      if ( !v2 )
        break;
      v4 = v2->next;
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      v2 = v4;
    }
    while ( v4 != (ConstructionItem *)v3 );
  }
  v1->constructionLots.next = (ConstructionItem *)v3;
  v1->constructionLots.prev = (ConstructionItem *)v3;
  v1->numberConstructionLotsValue = 0;
}
