
/**
 * @file    Engine\RGE\AiResearchModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00411670) --------------------------------------------------------
void __thiscall ResearchAIModule::ResearchAIModule(ResearchAIModule *this, void *pW, int playerID)
{
  ResearchAIModule *v3; // ebx@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aResearchAi, 1006, playerID, pW);
  v3->md = 0;
  TechnologyItem::TechnologyItem(&v3->techTree);
  v3->techTreeLengthValue = 0;
  v3->vfptr = (AIModuleVtbl *)&ResearchAIModule::`vftable';
  v3->techTree.next = &v3->techTree;
  v3->techTree.prev = &v3->techTree;
  strcpy(v3->techTreeNameValue, message_in);
}
// 56E988: using guessed type int (__thiscall *ResearchAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00411720) --------------------------------------------------------
ResearchAIModule *__thiscall ResearchAIModule::`scalar deleting destructor'(ResearchAIModule *this, unsigned int __flags)
{
  ResearchAIModule *v2; // esi@1

  v2 = this;
  ResearchAIModule::~ResearchAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00411740) --------------------------------------------------------
void __thiscall ResearchAIModule::ResearchAIModule(ResearchAIModule *this, int playerID, int infile)
{
  ResearchAIModule *v3; // esi@1
  TechnologyItem *v4; // edi@1
  int v5; // ebp@1
  int *v6; // edi@2
  signed int v7; // ebx@2
  TechnologyItem *v8; // eax@5
  TechnologyItem *v9; // ecx@7
  int v10; // ecx@7
  ResourceItem v11; // [sp-70h] [bp-228h]@5
  int v12; // [sp-Ch] [bp-1C4h]@1
  int *v13; // [sp-8h] [bp-1C0h]@1
  int v14; // [sp-4h] [bp-1BCh]@1
  int tempInt; // [sp+10h] [bp-1A8h]@1
  int i; // [sp+14h] [bp-1A4h]@1
  int typeID; // [sp+18h] [bp-1A0h]@2
  TechnologyItem *v18; // [sp+1Ch] [bp-19Ch]@4
  ResearchAIModule *v19; // [sp+20h] [bp-198h]@1
  ResourceItem *v20; // [sp+24h] [bp-194h]@5
  int rc[4]; // [sp+28h] [bp-190h]@2
  ResourceItem newRCost; // [sp+38h] [bp-180h]@4
  char name[257]; // [sp+A8h] [bp-110h]@2
  int v24; // [sp+1B4h] [bp-4h]@1

  v3 = this;
  v19 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aResearchAi, 1006, playerID, 0);
  v4 = &v3->techTree;
  v24 = 0;
  v3->md = 0;
  TechnologyItem::TechnologyItem(&v3->techTree);
  v14 = 4;
  v13 = &v3->techTreeLengthValue;
  LOBYTE(v24) = 1;
  *v13 = 0;
  v5 = infile;
  v12 = infile;
  v3->vfptr = (AIModuleVtbl *)&ResearchAIModule::`vftable';
  v3->techTree.next = &v3->techTree;
  v3->techTree.prev = &v3->techTree;
  rge_read(infile, (int)&v3->techTree, v12, v13, v14);
  rge_read(v5, (int)&v3->techTree, v5, &tempInt, 4);
  rge_read(v5, (int)&v3->techTree, v5, v3->techTreeNameValue, tempInt);
  i = 0;
  v3->techTreeNameValue[tempInt] = 0;
  if ( v3->techTreeLengthValue > 0 )
  {
    do
    {
      rge_read(infile, (int)v4, infile, &tempInt, 4);
      rge_read(infile, (int)v4, infile, name, tempInt);
      v14 = 4;
      v13 = &typeID;
      v12 = infile;
      name[tempInt] = 0;
      rge_read(infile, (int)v4, v12, v13, v14);
      v6 = rc;
      v7 = 4;
      do
      {
        rge_read(infile, (int)v6, infile, &tempInt, 4);
        *v6 = tempInt;
        ++v6;
        --v7;
      }
      while ( v7 );
      ResourceItem::ResourceItem(&newRCost, 4, rc);
      LOBYTE(v24) = 2;
      v4 = (TechnologyItem *)operator new(0x54u);
      v18 = v4;
      LOBYTE(v24) = 3;
      if ( v4 )
      {
        v20 = &v11;
        ResourceItem::ResourceItem(&v11, &newRCost);
        TechnologyItem::TechnologyItem(v4, typeID, name, v11);
      }
      else
      {
        v8 = 0;
      }
      LOBYTE(v24) = 1;
      v8->next = &v3->techTree;
      v9 = v3->techTree.prev;
      v8->prev = v9;
      v9->next = v8;
      v3->techTree.prev = v8;
      ResourceItem::~ResourceItem(&newRCost);
      v10 = v3->techTreeLengthValue;
      ++i;
    }
    while ( i < v10 );
  }
}
// 56E988: using guessed type int (__thiscall *ResearchAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00411940) --------------------------------------------------------
void __thiscall ResearchAIModule::~ResearchAIModule(ResearchAIModule *this)
{
  ResearchAIModule *v1; // esi@1

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&ResearchAIModule::`vftable';
  if ( this->techTreeLengthValue > 0 )
    ResearchAIModule::removeOldTechTree(this);
  TechnologyItem::~TechnologyItem(&v1->techTree);
  AIModule::~AIModule((AIModule *)&v1->vfptr);
}
// 56E988: using guessed type int (__thiscall *ResearchAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004119B0) --------------------------------------------------------
void __thiscall ResearchAIModule::setMainDecisionAI(ResearchAIModule *this, MainDecisionAIModule *m)
{
  this->md = m;
}

//----- (004119C0) --------------------------------------------------------
int __thiscall ResearchAIModule::save(ResearchAIModule *this, int outfile)
{
  ResearchAIModule *v2; // ebp@1
  TechnologyItem *v3; // ebp@1
  bool v4; // zf@1
  ResourceItem *v5; // edi@3
  int v6; // esi@3
  int tempInt; // [sp+10h] [bp-10Ch]@1
  ResearchAIModule *v9; // [sp+14h] [bp-108h]@1
  char tempString[257]; // [sp+18h] [bp-104h]@1

  v2 = this;
  v9 = this;
  rge_write(outfile, &this->techTreeLengthValue, 4);
  strcpy(tempString, v2->techTreeNameValue);
  tempInt = strlen(tempString);
  rge_write(outfile, &tempInt, 4);
  rge_write(outfile, tempString, strlen(tempString));
  v3 = v2->techTree.next;
  v4 = v3 == &v9->techTree;
  v9 = (ResearchAIModule *)((char *)v9 + 244);
  if ( !v4 )
  {
    do
    {
      if ( !v3 )
        break;
      strcpy(tempString, TechnologyItem::name(v3));
      tempInt = strlen(tempString);
      rge_write(outfile, &tempInt, 4);
      rge_write(outfile, tempString, tempInt);
      tempInt = TechnologyItem::id(v3);
      rge_write(outfile, &tempInt, 4);
      v5 = TechnologyItem::resourceCost(v3);
      v6 = 0;
      do
      {
        tempInt = ResourceItem::value(v5, v6);
        rge_write(outfile, &tempInt, 4);
        ++v6;
      }
      while ( v6 < 4 );
      v3 = v3->next;
    }
    while ( (ResearchAIModule *)v3 != v9 );
  }
  return 1;
}

//----- (00411B40) --------------------------------------------------------
TechnologyItem *__thiscall ResearchAIModule::resourceCost(ResearchAIModule *this, int id)
{
  TechnologyItem *result; // eax@1

  result = ResearchAIModule::item(this, id);
  if ( result )
    result = (TechnologyItem *)TechnologyItem::resourceCost(result);
  return result;
}

//----- (00411B60) --------------------------------------------------------
int __stdcall ResearchAIModule::buildable(BuildItem *bi)
{
  return 1;
}

//----- (00411B80) --------------------------------------------------------
FILE *__thiscall ResearchAIModule::loadTechnologyTree(ResearchAIModule *this, char *lName)
{
  ResearchAIModule *v2; // ebp@1
  const char *v3; // ebx@3
  FILE *result; // eax@5
  FILE *v5; // edi@5
  TechnologyItem *v6; // esi@7
  TechnologyItem *v7; // eax@8
  TechnologyItem *v8; // ecx@10
  int v9; // edx@10
  ResourceItem v10; // [sp-70h] [bp-25Ch]@8
  int *v11; // [sp-18h] [bp-204h]@7
  char *v12; // [sp-14h] [bp-200h]@7
  int *v13; // [sp-10h] [bp-1FCh]@7
  int *v14; // [sp-Ch] [bp-1F8h]@7
  int *v15; // [sp-8h] [bp-1F4h]@7
  int *v16; // [sp-4h] [bp-1F0h]@7
  char *v17; // [sp+10h] [bp-1DCh]@3
  int id; // [sp+14h] [bp-1D8h]@7
  int rc[4]; // [sp+18h] [bp-1D4h]@7
  ResourceItem *v20; // [sp+28h] [bp-1C4h]@8
  TechnologyItem *v21; // [sp+2Ch] [bp-1C0h]@7
  char name[64]; // [sp+30h] [bp-1BCh]@7
  ResourceItem newRCost; // [sp+70h] [bp-17Ch]@7
  char temp[256]; // [sp+E0h] [bp-10Ch]@5
  int v25; // [sp+1E8h] [bp-4h]@7

  v2 = this;
  if ( this->techTreeLengthValue > 0 )
    ResearchAIModule::removeOldTechTree(this);
  v3 = v2->techTreeNameValue;
  v17 = v2->techTreeNameValue;
  strcpy(v2->techTreeNameValue, lName);
  if ( !strcmp(v2->techTreeNameValue, aNone_2) )
  {
    if ( v2 != (ResearchAIModule *)-332 )
    {
LABEL_16:
      AIModule::logCommonHistory((AIModule *)&v2->vfptr, aThereIsNoTechT);
      return (FILE *)1;
    }
LABEL_15:
    strcpy(0, aNull);
    goto LABEL_16;
  }
  if ( v2 == (ResearchAIModule *)-332 )
    goto LABEL_15;
  AIModule::logCommonHistory((AIModule *)&v2->vfptr, aLoadingTechTre, lName);
  sprintf(temp, aS_2, v2->techTreeNameValue);
  result = fopen(temp, Mode);
  v5 = result;
  if ( !result )
    return result;
  if ( fgets(temp, 256, result) )
  {
    do
    {
      v16 = &rc[3];
      v15 = &rc[2];
      v14 = &rc[1];
      v13 = rc;
      v12 = name;
      v11 = &id;
      sscanf(temp, aCDSDDDDDDDDDDD, &id, name, rc, &rc[1], &rc[2], &rc[3]);
      ResourceItem::ResourceItem(&newRCost, 4, rc);
      v25 = 0;
      v6 = (TechnologyItem *)operator new(0x54u);
      v21 = v6;
      LOBYTE(v25) = 1;
      if ( v6 )
      {
        v20 = &v10;
        ResourceItem::ResourceItem(&v10, &newRCost);
        TechnologyItem::TechnologyItem(v6, id, name, v10);
      }
      else
      {
        v7 = 0;
      }
      v7->next = &v2->techTree;
      v8 = v2->techTree.prev;
      v7->prev = v8;
      v25 = -1;
      v8->next = v7;
      v9 = v2->techTreeLengthValue + 1;
      v2->techTree.prev = v7;
      v2->techTreeLengthValue = v9;
      ResourceItem::~ResourceItem(&newRCost);
    }
    while ( fgets(temp, 256, v5) );
    v3 = v17;
  }
  fclose(v5);
  if ( strstr(v3, SubStr) )
    _unlink(v3);
  return (FILE *)1;
}

//----- (00411E00) --------------------------------------------------------
int __thiscall ResearchAIModule::numberTechnologyItems(ResearchAIModule *this)
{
  return this->techTreeLengthValue;
}

//----- (00411E10) --------------------------------------------------------
char *__thiscall ResearchAIModule::technologyTreeName(ResearchAIModule *this)
{
  return this->techTreeNameValue;
}

//----- (00411E20) --------------------------------------------------------
void __thiscall ResearchAIModule::removeOldTechTree(ResearchAIModule *this)
{
  ResearchAIModule *v1; // ebx@1
  TechnologyItem *v2; // ecx@1
  int v3; // edi@1
  TechnologyItem *v4; // esi@3

  v1 = this;
  v2 = this->techTree.next;
  v3 = (int)&v1->techTree;
  if ( v2 != &v1->techTree )
  {
    do
    {
      if ( !v2 )
        break;
      v4 = v2->next;
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      v2 = v4;
    }
    while ( v4 != (TechnologyItem *)v3 );
  }
  v1->techTree.next = (TechnologyItem *)v3;
  v1->techTree.prev = (TechnologyItem *)v3;
  v1->techTreeLengthValue = 0;
}

//----- (00411E70) --------------------------------------------------------
TechnologyItem *__thiscall ResearchAIModule::item(ResearchAIModule *this, int id)
{
  TechnologyItem *v2; // esi@1
  char *v3; // edi@1

  v2 = this->techTree.next;
  v3 = (char *)&this->techTree;
  if ( v2 != &this->techTree )
  {
    while ( v2 )
    {
      if ( TechnologyItem::id(v2) == id )
        return v2;
      v2 = v2->next;
      if ( (char *)v2 == v3 )
        return 0;
    }
  }
  return 0;
}
