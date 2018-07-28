
//----- (0040A820) --------------------------------------------------------
void __thiscall ConstructionItem::ConstructionItem(ConstructionItem *this)
{
  ConstructionItem *v1; // esi@1

  v1 = this;
  BaseItem::BaseItem((BaseItem *)&this->vfptr);
  v1->vfptr = (BaseItemVtbl *)ConstructionItem::`vftable';
  v1->next = 0;
  v1->prev = 0;
  v1->inProgressValue = 0;
  v1->builtValue = 0;
  v1->buildAttemptsValue = 0;
}
// 56E79C: using guessed type int (__thiscall *ConstructionItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040A850) --------------------------------------------------------
ConstructionItem *__thiscall ConstructionItem::`vector deleting destructor'(ConstructionItem *this, unsigned int __flags)
{
  ConstructionItem *v2; // esi@1

  v2 = this;
  ConstructionItem::~ConstructionItem(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040A870) --------------------------------------------------------
void __thiscall ConstructionItem::ConstructionItem(ConstructionItem *this, float x, float y, float z, float xs, float ys, float zs, int ti, char *n)
{
  ConstructionItem *v9; // esi@1

  v9 = this;
  BaseItem::BaseItem((BaseItem *)&this->vfptr, ti, -1, -1, n, x, y, z, xs, ys, zs);
  v9->vfptr = (BaseItemVtbl *)ConstructionItem::`vftable';
  v9->next = 0;
  v9->prev = 0;
  v9->inProgressValue = 0;
  v9->builtValue = 0;
  v9->buildAttemptsValue = 0;
}
// 56E79C: using guessed type int (__thiscall *ConstructionItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040A8D0) --------------------------------------------------------
void __thiscall ConstructionItem::ConstructionItem(ConstructionItem *this, ConstructionItem *ci)
{
  ConstructionItem *v2; // esi@1

  v2 = this;
  BaseItem::BaseItem((BaseItem *)&this->vfptr, (BaseItem *)&ci->vfptr);
  v2->next = 0;
  v2->prev = 0;
  v2->inProgressValue = ci->inProgressValue;
  v2->builtValue = ci->builtValue;
  v2->buildAttemptsValue = ci->buildAttemptsValue;
  v2->vfptr = (BaseItemVtbl *)ConstructionItem::`vftable';
}
// 56E79C: using guessed type int (__thiscall *ConstructionItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040A910) --------------------------------------------------------
void __thiscall ConstructionItem::ConstructionItem(ConstructionItem *this, ConstructionItem *ci)
{
  ConstructionItem *v2; // esi@1

  v2 = this;
  BaseItem::BaseItem((BaseItem *)&this->vfptr, (BaseItem *)&ci->vfptr);
  v2->next = 0;
  v2->prev = 0;
  v2->inProgressValue = ci->inProgressValue;
  v2->builtValue = ci->builtValue;
  v2->buildAttemptsValue = ci->buildAttemptsValue;
  v2->vfptr = (BaseItemVtbl *)ConstructionItem::`vftable';
}
// 56E79C: using guessed type int (__thiscall *ConstructionItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040A950) --------------------------------------------------------
void __thiscall ConstructionItem::~ConstructionItem(ConstructionItem *this)
{
  this->vfptr = (BaseItemVtbl *)ConstructionItem::`vftable';
  BaseItem::~BaseItem((BaseItem *)&this->vfptr);
}
// 56E79C: using guessed type int (__thiscall *ConstructionItem::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040A960) --------------------------------------------------------
BOOL __cdecl operator==(ConstructionItem *one, ConstructionItem *two)
{
  return one->xValue == two->xValue && one->yValue == two->yValue;
}

//----- (0040A990) --------------------------------------------------------
BOOL __cdecl operator!=(ConstructionItem *one, ConstructionItem *two)
{
  return one->xValue != two->xValue || one->yValue != two->yValue;
}

//----- (0040A9C0) --------------------------------------------------------
BOOL __cdecl operator<(ConstructionItem *one, ConstructionItem *two)
{
  return one->typeIDValue < two->typeIDValue;
}

//----- (0040A9E0) --------------------------------------------------------
bool __cdecl operator>(ConstructionItem *one, ConstructionItem *two)
{
  return one->typeIDValue > two->typeIDValue;
}

//----- (0040AA00) --------------------------------------------------------
int __thiscall ConstructionItem::inProgress(ConstructionItem *this)
{
  return this->inProgressValue;
}

//----- (0040AA10) --------------------------------------------------------
int __thiscall ConstructionItem::built(ConstructionItem *this)
{
  return this->builtValue;
}

//----- (0040AA20) --------------------------------------------------------
int __thiscall ConstructionItem::buildAttempts(ConstructionItem *this)
{
  return this->buildAttemptsValue;
}

//----- (0040AA30) --------------------------------------------------------
void __thiscall ConstructionItem::setInProgress(ConstructionItem *this, int p)
{
  this->inProgressValue = p;
}

//----- (0040AA40) --------------------------------------------------------
void __thiscall ConstructionItem::setBuilt(ConstructionItem *this, int b)
{
  this->builtValue = b;
}

//----- (0040AA50) --------------------------------------------------------
void __thiscall ConstructionItem::incrementBuildAttempts(ConstructionItem *this)
{
  ++this->buildAttemptsValue;
}

//----- (0040AA60) --------------------------------------------------------
void __thiscall ConstructionItem::decrementBuildAttempts(ConstructionItem *this)
{
  int v1; // eax@1

  v1 = this->buildAttemptsValue - 1;
  this->buildAttemptsValue = v1;
  if( v1 < 0 )
    this->buildAttemptsValue = 0;
}

//----- (0040AA80) --------------------------------------------------------
void __thiscall ConstructionItem::setBuildAttempts(ConstructionItem *this, int v)
{
  this->buildAttemptsValue = v;
}
