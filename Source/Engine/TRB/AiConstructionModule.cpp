
/**
 * @file    Engine\TRB\AiConstructionModule.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D5E60) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::TribeConstructionAIModule(TribeConstructionAIModule *this, void *pW, int pID)
{
  TribeConstructionAIModule *v3; // esi@1

  v3 = this;
  ConstructionAIModule::ConstructionAIModule((ConstructionAIModule *)&this->vfptr, pW, pID);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&TribeConstructionAIModule::`vftable';
}
// 5754A0: using guessed type int (__thiscall *TribeConstructionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D5E90) --------------------------------------------------------
TribeConstructionAIModule *__thiscall TribeConstructionAIModule::`vector deleting destructor'(TribeConstructionAIModule *this, unsigned int __flags)
{
  TribeConstructionAIModule *v2; // esi@1

  v2 = this;
  TribeConstructionAIModule::~TribeConstructionAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D5EB0) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::TribeConstructionAIModule(TribeConstructionAIModule *this, int pID, int infile)
{
  TribeConstructionAIModule *v3; // esi@1

  v3 = this;
  ConstructionAIModule::ConstructionAIModule((ConstructionAIModule *)&this->vfptr, pID, infile);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&TribeConstructionAIModule::`vftable';
}
// 5754A0: using guessed type int (__thiscall *TribeConstructionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D5EE0) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::~TribeConstructionAIModule(TribeConstructionAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&TribeConstructionAIModule::`vftable';
  ConstructionAIModule::~ConstructionAIModule((ConstructionAIModule *)&this->vfptr);
}
// 5754A0: using guessed type int (__thiscall *TribeConstructionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004D5EF0) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::setMainDecisionAI(TribeConstructionAIModule *this, TribeMainDecisionAIModule *m)
{
  this->md = m;
}

//----- (004D5F00) --------------------------------------------------------
int __thiscall TribeConstructionAIModule::canPlace(TribeConstructionAIModule *this, BuildItem *bi)
{
  TribeConstructionAIModule *v2; // edi@1
  BaseItem *v4; // esi@9
  int v5; // edi@9
  int v6; // ebp@11
  float v7; // ST14_4@12
  float v8; // ST14_4@13
  TribeMainDecisionAIModule *v9; // ecx@22
  BuildItem *v10; // [sp-4h] [bp-A4h]@20
  ConstructionItem tempLots; // [sp+14h] [bp-8Ch]@9
  int v12; // [sp+9Ch] [bp-4h]@9

  v2 = this;
  if ( this->xReferencePointValue <= 0.0
    || this->yReferencePointValue <= 0.0
    || (double)this->mapXSizeValue <= this->xReferencePointValue
    || (double)this->mapYSizeValue <= this->yReferencePointValue )
  {
    v10 = bi;
    goto LABEL_22;
  }
  if ( BaseItem::typeID((BaseItem *)&bi->vfptr) == 45 )
    return 1;
  if ( useInfluencePlacement == 1 || !v2->numberConstructionLotsValue )
  {
    v10 = bi;
LABEL_22:
    v9 = v2->md;
    return TribeInformationAIModule::influenceCanPlaceStructure(v10);
  }
  ConstructionItem::ConstructionItem(&tempLots);
  v4 = (BaseItem *)&v2->constructionLots.next->vfptr;
  v5 = (int)&v2->constructionLots;
  v12 = 0;
  tempLots.next = &tempLots;
  tempLots.prev = &tempLots;
  if ( v4 != (BaseItem *)v5 )
  {
    while ( v4 )
    {
      v6 = BaseItem::typeID(v4);
      if ( v6 == BaseItem::typeID((BaseItem *)&bi->vfptr)
        || (v7 = BaseItem::xSize(v4), BaseItem::xSize((BaseItem *)&bi->vfptr) == v7)
        && (v8 = BaseItem::ySize(v4), BaseItem::ySize((BaseItem *)&bi->vfptr) == v8)
        && BaseItem::typeID(v4) == -1 )
      {
        if ( !ConstructionItem::built((ConstructionItem *)v4) && !ConstructionItem::inProgress((ConstructionItem *)v4) )
        {
          v12 = -1;
          ConstructionItem::~ConstructionItem(&tempLots);
          return 1;
        }
      }
      v4 = (BaseItem *)v4[1].vfptr;
      if ( v4 == (BaseItem *)v5 )
        break;
    }
  }
  v12 = -1;
  ConstructionItem::~ConstructionItem(&tempLots);
  return 0;
}
// 62C510: using guessed type int useInfluencePlacement;

//----- (004D60E0) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::placeStructure(TribeConstructionAIModule *this, BuildItem *bi, int builder, PlacementState *placementState, unsigned int startTime)
{
  TribeConstructionAIModule *v5; // ebx@1
  BuildItem *v6; // ebp@5
  ConstructionItem *v7; // eax@6
  ConstructionItem *v8; // esi@6
  ConstructionItem *v9; // eax@7
  RGE_Static_Object *v10; // eax@20
  BaseItem *v11; // edi@22
  int v12; // esi@24
  int v13; // ST40_4@26
  int v14; // ST40_4@27
  int v15; // ST40_4@30
  int v16; // esi@30
  int v17; // ST40_4@30
  signed __int64 v18; // rax@30
  int v19; // ebp@30
  int v20; // ebx@30
  int v21; // ebp@34
  int v22; // esi@35
  float v23; // ST24_4@38
  float v24; // ST20_4@38
  ConstructionItem *v25; // eax@41
  ConstructionItem *v26; // eax@42
  int v27; // eax@51
  ConstructionItem *v28; // edi@56
  ConstructionItem *v29; // esi@56
  int v30; // ebp@59
  ConstructionItem *v31; // eax@65
  float v32; // ST28_4@66
  float v33; // ST24_4@66
  ConstructionItem *v34; // esi@66
  int v35; // eax@66
  BaseItem *v36; // edi@66
  ConstructionItem *v37; // eax@66
  BaseItem *v38; // eax@67
  int v39; // eax@68
  ConstructionItem *v40; // ecx@68
  ConstructionItem *v41; // esi@70
  BuildItem *v42; // [sp-18h] [bp-F4h]@72
  int v43; // [sp-14h] [bp-F0h]@72
  PlacementState *x; // [sp+Ch] [bp-D0h]@72
  unsigned int y; // [sp+10h] [bp-CCh]@72
  char builderZone; // [sp+27h] [bp-B5h]@20
  int maxX; // [sp+28h] [bp-B4h]@30
  TribeConstructionAIModule *v48; // [sp+2Ch] [bp-B0h]@1
  int minBuildAttempts; // [sp+30h] [bp-ACh]@22
  int k; // [sp+34h] [bp-A8h]@22
  int numberTempLots; // [sp+38h] [bp-A4h]@22
  int j; // [sp+3Ch] [bp-A0h]@35
  int i; // [sp+40h] [bp-9Ch]@34
  int minY; // [sp+44h] [bp-98h]@30
  RGE_Static_Object *protoBuilder; // [sp+48h] [bp-94h]@19
  RGE_Static_Object *builderObj; // [sp+4Ch] [bp-90h]@20
  ConstructionItem tempLots; // [sp+50h] [bp-8Ch]@22
  int v58; // [sp+D8h] [bp-4h]@7

  v5 = this;
  v48 = this;
  if ( this->xReferencePointValue <= 0.0
    || this->yReferencePointValue <= 0.0
    || (double)this->mapXSizeValue <= this->xReferencePointValue
    || (double)this->mapYSizeValue <= this->yReferencePointValue )
  {
    y = startTime;
    x = placementState;
    v43 = builder;
    v42 = bi;
    goto LABEL_74;
  }
  v6 = bi;
  if ( BaseItem::typeID((BaseItem *)&bi->vfptr) == 45 )
  {
    TribeConstructionAIModule::placeDock(v5, bi);
    v8 = v7;
    if ( v7 )
    {
      v9 = (ConstructionItem *)operator new(0x80u);
      v58 = 0;
      if ( v9 )
        ConstructionItem::ConstructionItem(v9, v8);
    }
    return;
  }
  if ( BaseItem::typeID((BaseItem *)&bi->vfptr) == 103
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 68
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 79
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 199
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 69
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 72
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 117
    || BaseItem::typeID((BaseItem *)&bi->vfptr) == 155
    || useInfluencePlacement == 1
    || !v5->numberConstructionLotsValue )
  {
    y = startTime;
    x = placementState;
    v43 = builder;
    v42 = bi;
LABEL_74:
    TribeInformationAIModule::influencePlaceStructure(
      &v5->md->informationAI,
      v42,
      v43,
      -1,
      0.0,
      0,
      -1,
      -1,
      -1,
      -1,
      x,
      y);
    return;
  }
  protoBuilder = MainDecisionAIModule::object(
                   (MainDecisionAIModule *)&v5->md->vfptr,
                   -1,
                   -1,
                   4,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1,
                   -1);
  if ( protoBuilder )
  {
    v10 = MainDecisionAIModule::object((MainDecisionAIModule *)&v5->md->vfptr, builder);
    builderObj = v10;
    builderZone = 0;
    if ( v10 )
      builderZone = RGE_Static_Object::currentZone(v10);
    ConstructionItem::ConstructionItem(&tempLots);
    v11 = (BaseItem *)&v5->constructionLots.next->vfptr;
    v58 = 1;
    tempLots.next = &tempLots;
    tempLots.prev = &tempLots;
    numberTempLots = 0;
    minBuildAttempts = -1;
    for ( k = (int)&v5->constructionLots; v11 != (BaseItem *)k; v11 = (BaseItem *)v11[1].vfptr )
    {
      if ( !v11 )
        break;
      v12 = BaseItem::typeID((BaseItem *)&v6->vfptr);
      if ( BaseItem::typeID(v11) == v12 || BaseItem::typeID(v11) == -1 )
      {
        *(float *)&v13 = BaseItem::xSize(v11);
        if ( BaseItem::xSize((BaseItem *)&v6->vfptr) == *(float *)&v13 )
        {
          *(float *)&v14 = BaseItem::ySize(v11);
          if ( BaseItem::ySize((BaseItem *)&v6->vfptr) == *(float *)&v14
            && ConstructionItem::built((ConstructionItem *)v11) != 1
            && ConstructionItem::inProgress((ConstructionItem *)v11) != 1 )
          {
            *(float *)&v15 = BaseItem::x(v11);
            v16 = (signed __int64)(*(float *)&v15 - BaseItem::xSize(v11));
            *(float *)&v17 = BaseItem::y(v11);
            minY = (signed __int64)(*(float *)&v17 - BaseItem::ySize(v11));
            v18 = (signed __int64)BaseItem::xSize(v11);
            v19 = v16 + v18;
            maxX = v16 + v18;
            v20 = minY + (unsigned __int64)(signed __int64)BaseItem::ySize(v11);
            if ( v16 >= 0 && minY >= 0 && v19 < v48->mapXSizeValue && v20 < v48->mapYSizeValue )
            {
              v21 = v16;
              i = v16;
              if ( v16 >= maxX )
              {
LABEL_41:
                v25 = (ConstructionItem *)operator new(0x80u);
                LOBYTE(v58) = 2;
                if ( v25 )
                  ConstructionItem::ConstructionItem(v25, (ConstructionItem *)v11);
                else
                  v26 = 0;
                v26->next = &tempLots;
                v26->prev = tempLots.prev;
                LOBYTE(v58) = 1;
                tempLots.prev->next = v26;
                tempLots.prev = v26;
                ++numberTempLots;
                if ( minBuildAttempts == -1
                  || minBuildAttempts > ConstructionItem::buildAttempts((ConstructionItem *)v11) )
                {
                  minBuildAttempts = ConstructionItem::buildAttempts((ConstructionItem *)v11);
                }
              }
              else
              {
                while ( 1 )
                {
                  v22 = minY;
                  j = minY;
                  if ( minY < v20 )
                    break;
LABEL_40:
                  i = ++v21;
                  if ( v21 >= maxX )
                    goto LABEL_41;
                }
                while ( !builderObj || RGE_Static_Object::lookupZone(builderObj, v21, v22) == builderZone )
                {
                  v23 = (double)j - -0.5;
                  v24 = (double)i - -0.5;
                  if ( !((int (__stdcall *)(_DWORD, _DWORD, signed int))protoBuilder->vfptr->passableTile)(
                          LODWORD(v24),
                          LODWORD(v23),
                          1) )
                    break;
                  j = ++v22;
                  if ( v22 >= v20 )
                    goto LABEL_40;
                }
              }
            }
            v6 = bi;
            v5 = v48;
          }
        }
      }
    }
    if ( (minBuildAttempts >= 2 || minBuildAttempts == -1)
      && (TribeInformationAIModule::influencePlaceStructure(
            &v5->md->informationAI,
            v6,
            builder,
            -1,
            0.0,
            0,
            -1,
            -1,
            -1,
            -1,
            placementState,
            startTime),
          v27) )
    {
      v58 = -1;
      ConstructionItem::~ConstructionItem(&tempLots);
    }
    else if ( numberTempLots )
    {
      v28 = tempLots.next;
      v29 = tempLots.next->next;
      if ( BaseItem::typeID((BaseItem *)&v6->vfptr) == 72 )
      {
        for ( ; v29 != &tempLots; v6 = bi )
        {
          if ( !v29 )
            break;
          v30 = ConstructionItem::buildAttempts(v28);
          if ( v30 > ConstructionItem::buildAttempts(v29) + 5 )
            v28 = v29;
          v29 = v29->next;
        }
      }
      else
      {
        for ( ; v29 != &tempLots; v28 = v31 )
        {
          if ( !v29 )
            break;
          v31 = TribeConstructionAIModule::compare(v28, v29);
          v29 = v29->next;
        }
      }
      v32 = BaseItem::y((BaseItem *)&v28->vfptr);
      v33 = BaseItem::x((BaseItem *)&v28->vfptr);
      v34 = ConstructionAIModule::lot((ConstructionAIModule *)&v5->vfptr, v33, v32);
      ConstructionItem::setInProgress(v34, 1);
      ConstructionItem::incrementBuildAttempts(v34);
      v35 = BaseItem::uniqueID((BaseItem *)&v6->vfptr);
      BaseItem::setUniqueID((BaseItem *)&v34->vfptr, v35);
      v36 = 0;
      v5->lastPlacementReturnCodeValue = 0;
      v37 = (ConstructionItem *)operator new(0x80u);
      LOBYTE(v58) = 3;
      if ( v37 )
      {
        ConstructionItem::ConstructionItem(v37, v34);
        v36 = v38;
      }
      LOBYTE(v58) = 1;
      v39 = BaseItem::typeID((BaseItem *)&v6->vfptr);
      BaseItem::setTypeID(v36, v39);
      v40 = tempLots.next;
      if ( tempLots.next != &tempLots )
      {
        do
        {
          if ( !v40 )
            break;
          v41 = v40->next;
          ((void (__stdcall *)(signed int))v40->vfptr->__vecDelDtor)(1);
          v40 = v41;
        }
        while ( v41 != &tempLots );
      }
      v58 = -1;
      ConstructionItem::~ConstructionItem(&tempLots);
    }
    else
    {
      v5->lastPlacementReturnCodeValue = 5;
      v58 = -1;
      ConstructionItem::~ConstructionItem(&tempLots);
    }
  }
}
// 62C510: using guessed type int useInfluencePlacement;

//----- (004D6780) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::placeDock(TribeConstructionAIModule *this, BuildItem *bi)
{
  TribeConstructionAIModule *v2; // esi@1
  ConstructionItem *v3; // eax@1
  ConstructionItem *v4; // ecx@2
  int v5; // ecx@2

  v2 = this;
  TribeInformationAIModule::placeDock(
    &this->md->informationAI,
    bi,
    this->xReferencePointValue,
    this->yReferencePointValue,
    1,
    2);
  if ( v3 )
  {
    v3->next = &v2->randomConstructionLots;
    v4 = v2->randomConstructionLots.prev;
    v3->prev = v4;
    v4->next = v3;
    v5 = v2->numberRandomConstructionLotsValue + 1;
    v2->randomConstructionLots.prev = v3;
    v2->numberRandomConstructionLotsValue = v5;
    v2->lastPlacementReturnCodeValue = 0;
  }
  else
  {
    v2->lastPlacementReturnCodeValue = 5;
  }
}

//----- (004D6800) --------------------------------------------------------
void __thiscall TribeConstructionAIModule::setBuilt(TribeConstructionAIModule *this, RGE_Static_Object *bo, int v)
{
  TribeConstructionAIModule *v3; // ebp@1
  ConstructionItem *v4; // esi@1
  char *v5; // ebx@1

  v3 = this;
  v4 = this->constructionLots.next;
  v5 = (char *)&this->constructionLots;
  if ( v4 != &this->constructionLots )
  {
    while ( v4 )
    {
      if ( BaseItem::typeID((BaseItem *)&v4->vfptr) == bo->master_obj->id
        && BaseItem::x((BaseItem *)&v4->vfptr) == bo->world_x
        && BaseItem::y((BaseItem *)&v4->vfptr) == bo->world_y )
      {
        ConstructionItem::setBuilt(v4, v);
        return;
      }
      v4 = v4->next;
      if ( (char *)v4 == v5 )
        break;
    }
  }
  TribeInformationAIModule::storeLot(
    &v3->md->informationAI,
    bo->master_obj->id,
    (signed __int64)bo->world_x,
    (signed __int64)bo->world_y,
    1);
}

//----- (004D68A0) --------------------------------------------------------
ConstructionItem *__stdcall TribeConstructionAIModule::compare(ConstructionItem *one, ConstructionItem *two)
{
  int v3; // ebx@1
  int v4; // eax@1
  bool v5; // zf@1
  bool v6; // sf@1
  unsigned __int8 v7; // of@1
  ConstructionItem *result; // eax@1

  v3 = ConstructionItem::buildAttempts(one);
  v4 = ConstructionItem::buildAttempts(two);
  v7 = __OFSUB__(v3, v4);
  v5 = v3 == v4;
  v6 = v3 - v4 < 0;
  result = two;
  if ( (unsigned __int8)(v6 ^ v7) | v5 )
    result = one;
  return result;
}
