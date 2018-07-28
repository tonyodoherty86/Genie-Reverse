
/**
 * @file    Engine\RGE\AiTechnologyItem.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00412BB0) --------------------------------------------------------
void __thiscall TechnologyItem::TechnologyItem(TechnologyItem *this)
{
  this->next = 0;
  this->prev = 0;
  this->idValue = 0;
  this->resourceCostValue = 0;
  this->vfptr = (TechnologyItemVtbl *)TechnologyItem::`vftable';
  strcpy(this->nameValue, message_in);
}
// 56EA94: using guessed type int (__thiscall *TechnologyItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (00412C00) --------------------------------------------------------
TechnologyItem *__thiscall TechnologyItem::`scalar deleting destructor'(TechnologyItem *this, unsigned int __flags)
{
  TechnologyItem *v2; // esi@1

  v2 = this;
  TechnologyItem::~TechnologyItem(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00412C20) --------------------------------------------------------
void __thiscall TechnologyItem::TechnologyItem(TechnologyItem *this, int i, char *n, ResourceItem r)
{
  TechnologyItem *v4; // ebx@1
  ResourceItem *v5; // eax@1
  ResourceItem *v6; // eax@2

  v4 = this;
  this->next = 0;
  this->prev = 0;
  this->idValue = i;
  this->vfptr = (TechnologyItemVtbl *)TechnologyItem::`vftable';
  v5 = (ResourceItem *)operator new(0x70u);
  if ( v5 )
    ResourceItem::ResourceItem(v5, &r);
  else
    v6 = 0;
  v4->resourceCostValue = v6;
  strcpy(v4->nameValue, n);
  ResourceItem::~ResourceItem(&r);
}
// 56EA94: using guessed type int (__thiscall *TechnologyItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (00412CD0) --------------------------------------------------------
void __thiscall TechnologyItem::TechnologyItem(TechnologyItem *this, TechnologyItem *ti)
{
  TechnologyItem *v2; // ebx@1
  int v3; // eax@1
  ResourceItem *v4; // eax@1
  ResourceItem *v5; // eax@2

  v2 = this;
  this->next = 0;
  this->prev = 0;
  v3 = ti->idValue;
  this->vfptr = (TechnologyItemVtbl *)TechnologyItem::`vftable';
  this->idValue = v3;
  v4 = (ResourceItem *)operator new(0x70u);
  if ( v4 )
    ResourceItem::ResourceItem(v4, ti->resourceCostValue);
  else
    v5 = 0;
  v2->resourceCostValue = v5;
  strcpy(v2->nameValue, ti->nameValue);
}
// 56EA94: using guessed type int (__thiscall *TechnologyItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (00412D70) --------------------------------------------------------
void __thiscall TechnologyItem::~TechnologyItem(TechnologyItem *this)
{
  ResourceItem *v1; // ecx@1

  this->vfptr = (TechnologyItemVtbl *)TechnologyItem::`vftable';
  v1 = this->resourceCostValue;
  if ( v1 )
    ((void (__stdcall *)(_DWORD))v1->vfptr->__vecDelDtor)(1);
}
// 56EA94: using guessed type int (__thiscall *TechnologyItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (00412D90) --------------------------------------------------------
BOOL __cdecl operator==(TechnologyItem *one, TechnologyItem *two)
{
  return one->idValue == two->idValue;
}

//----- (00412DB0) --------------------------------------------------------
BOOL __cdecl operator!=(TechnologyItem *one, TechnologyItem *two)
{
  return one->idValue != two->idValue;
}

//----- (00412DD0) --------------------------------------------------------
BOOL __cdecl operator<(TechnologyItem *one, TechnologyItem *two)
{
  return one->idValue < two->idValue;
}

//----- (00412DF0) --------------------------------------------------------
bool __cdecl operator>(TechnologyItem *one, TechnologyItem *two)
{
  return one->idValue > two->idValue;
}

//----- (00412E10) --------------------------------------------------------
int __thiscall TechnologyItem::id(TechnologyItem *this)
{
  return this->idValue;
}

//----- (00412E20) --------------------------------------------------------
char *__thiscall TechnologyItem::name(TechnologyItem *this)
{
  return this->nameValue;
}

//----- (00412E30) --------------------------------------------------------
ResourceItem *__thiscall TechnologyItem::resourceCost(TechnologyItem *this)
{
  return this->resourceCostValue;
}
