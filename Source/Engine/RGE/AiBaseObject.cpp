
//----- (00409FA0) --------------------------------------------------------
void __thiscall BaseObject::BaseObject(BaseObject *this)
{
  this->next = 0;
  this->prev = 0;
  this->numberGroupsValue = 0;
  this->groupIDValue = 0;
  this->categoryIDValue = -1;
  this->typeIDValue = -1;
  this->gameIDValue = -1;
  LODWORD(this->xPositionValue) = -1082130432;
  LODWORD(this->yPositionValue) = -1082130432;
  LODWORD(this->zPositionValue) = -1082130432;
  LODWORD(this->xSizeValue) = -1082130432;
  LODWORD(this->ySizeValue) = -1082130432;
  LODWORD(this->zSizeValue) = -1082130432;
  this->hitPointValue = 0;
  this->minHitPointValue = 0;
  this->maxHitPointValue = 0;
  this->busyValue = 0;
  this->currentTaskValue = -1;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  LODWORD(this->currentTargetXPositionValue) = 0;
  LODWORD(this->currentTargetYPositionValue) = 0;
  LODWORD(this->currentTargetZPositionValue) = 0;
  this->vfptr = (BaseObjectVtbl *)BaseObject::`vftable';
  strcpy(this->nameValue, message_in);
}
// 56E798: using guessed type int (__thiscall *BaseObject::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040A040) --------------------------------------------------------
BaseObject *__thiscall BaseObject::`scalar deleting destructor'(BaseObject *this, unsigned int __flags)
{
  BaseObject *v2; // esi@1

  v2 = this;
  BaseObject::~BaseObject(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040A060) --------------------------------------------------------
void __thiscall BaseObject::BaseObject(BaseObject *this, int gri, int ci, int ti, int gi, char *nm, float xs, float ys, float zs, float xp, float yp, float zp, int hp, int minp, int maxp)
{
  BaseObject *v15; // esi@1
  int *v16; // eax@1

  v15 = this;
  this->categoryIDValue = ci;
  this->typeIDValue = ti;
  this->gameIDValue = gi;
  this->xPositionValue = xp;
  this->yPositionValue = yp;
  this->zPositionValue = zp;
  this->xSizeValue = xs;
  this->ySizeValue = ys;
  this->zSizeValue = zs;
  this->hitPointValue = hp;
  this->minHitPointValue = minp;
  this->next = 0;
  this->prev = 0;
  this->numberGroupsValue = 1;
  this->maxHitPointValue = maxp;
  this->busyValue = 0;
  this->currentTaskValue = -1;
  this->currentTargetValue = -1;
  this->currentTargetTypeValue = -1;
  LODWORD(this->currentTargetXPositionValue) = 0;
  LODWORD(this->currentTargetYPositionValue) = 0;
  LODWORD(this->currentTargetZPositionValue) = 0;
  this->vfptr = (BaseObjectVtbl *)BaseObject::`vftable';
  v16 = (int *)operator new(4u);
  v15->groupIDValue = v16;
  *v16 = gri;
  strncpy(v15->nameValue, nm, 0x3Fu);
}
// 56E798: using guessed type int (__thiscall *BaseObject::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040A130) --------------------------------------------------------
void __thiscall BaseObject::BaseObject(BaseObject *this, BaseObject *bo)
{
  BaseObject *v2; // esi@1
  int v3; // edx@1
  float v4; // ecx@1
  int *v5; // eax@1
  int v6; // ecx@1
  int v7; // eax@1

  v2 = this;
  this->next = 0;
  this->prev = 0;
  this->numberGroupsValue = bo->numberGroupsValue;
  this->categoryIDValue = bo->categoryIDValue;
  this->typeIDValue = bo->typeIDValue;
  this->gameIDValue = bo->gameIDValue;
  this->xPositionValue = bo->xPositionValue;
  this->yPositionValue = bo->yPositionValue;
  this->zPositionValue = bo->zPositionValue;
  this->xSizeValue = bo->xSizeValue;
  this->ySizeValue = bo->ySizeValue;
  this->zSizeValue = bo->zSizeValue;
  this->hitPointValue = bo->hitPointValue;
  this->minHitPointValue = bo->minHitPointValue;
  this->maxHitPointValue = bo->maxHitPointValue;
  this->busyValue = bo->busyValue;
  this->currentTaskValue = bo->currentTaskValue;
  this->currentTargetValue = bo->currentTargetValue;
  this->currentTargetTypeValue = bo->currentTargetTypeValue;
  this->currentTargetXPositionValue = bo->currentTargetXPositionValue;
  v3 = this->numberGroupsValue;
  this->currentTargetYPositionValue = bo->currentTargetYPositionValue;
  v4 = bo->currentTargetZPositionValue;
  v2->vfptr = (BaseObjectVtbl *)BaseObject::`vftable';
  v2->currentTargetZPositionValue = v4;
  v5 = (int *)operator new(4 * v3);
  v6 = v2->numberGroupsValue;
  v2->groupIDValue = v5;
  v7 = 0;
  if( v6 > 0 )
  {
    do
    {
      v2->groupIDValue[v7] = bo->groupIDValue[v7];
      ++v7;
    }
    while( v7 < v2->numberGroupsValue );
  }
  strncpy(v2->nameValue, bo->nameValue, 0x3Fu);
}
// 56E798: using guessed type int (__thiscall *BaseObject::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040A240) --------------------------------------------------------
void __thiscall BaseObject::BaseObject(BaseObject *this, BaseObject *bo)
{
  BaseObject *v2; // esi@1
  int v3; // edx@1
  float v4; // ecx@1
  int *v5; // eax@1
  int v6; // ecx@1
  int v7; // eax@1

  v2 = this;
  this->next = 0;
  this->prev = 0;
  this->numberGroupsValue = bo->numberGroupsValue;
  this->categoryIDValue = bo->categoryIDValue;
  this->typeIDValue = bo->typeIDValue;
  this->gameIDValue = bo->gameIDValue;
  this->xPositionValue = bo->xPositionValue;
  this->yPositionValue = bo->yPositionValue;
  this->zPositionValue = bo->zPositionValue;
  this->xSizeValue = bo->xSizeValue;
  this->ySizeValue = bo->ySizeValue;
  this->zSizeValue = bo->zSizeValue;
  this->hitPointValue = bo->hitPointValue;
  this->minHitPointValue = bo->minHitPointValue;
  this->maxHitPointValue = bo->maxHitPointValue;
  this->busyValue = bo->busyValue;
  this->currentTaskValue = bo->currentTaskValue;
  this->currentTargetValue = bo->currentTargetValue;
  this->currentTargetTypeValue = bo->currentTargetTypeValue;
  this->currentTargetXPositionValue = bo->currentTargetXPositionValue;
  v3 = this->numberGroupsValue;
  this->currentTargetYPositionValue = bo->currentTargetYPositionValue;
  v4 = bo->currentTargetZPositionValue;
  v2->vfptr = (BaseObjectVtbl *)BaseObject::`vftable';
  v2->currentTargetZPositionValue = v4;
  v5 = (int *)operator new(4 * v3);
  v6 = v2->numberGroupsValue;
  v2->groupIDValue = v5;
  v7 = 0;
  if( v6 > 0 )
  {
    do
    {
      v2->groupIDValue[v7] = bo->groupIDValue[v7];
      ++v7;
    }
    while( v7 < v2->numberGroupsValue );
  }
  strncpy(v2->nameValue, bo->nameValue, 0x3Fu);
}
// 56E798: using guessed type int (__thiscall *BaseObject::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040A350) --------------------------------------------------------
void __thiscall BaseObject::~BaseObject(BaseObject *this)
{
  int *v1; // eax@1

  v1 = this->groupIDValue;
  this->vfptr = (BaseObjectVtbl *)BaseObject::`vftable';
  operator delete(v1);
}
// 56E798: using guessed type int (__thiscall *BaseObject::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040A370) --------------------------------------------------------
BOOL __cdecl operator==(BaseObject *one, BaseObject *two)
{
  return one->gameIDValue == two->gameIDValue;
}

//----- (0040A390) --------------------------------------------------------
BOOL __cdecl operator!=(BaseObject *one, BaseObject *two)
{
  return one->gameIDValue != two->gameIDValue;
}

//----- (0040A3B0) --------------------------------------------------------
BOOL __cdecl operator<(BaseObject *one, BaseObject *two)
{
  return one->gameIDValue < two->gameIDValue;
}

//----- (0040A3D0) --------------------------------------------------------
bool __cdecl operator>(BaseObject *one, BaseObject *two)
{
  return one->gameIDValue > two->gameIDValue;
}

//----- (0040A3F0) --------------------------------------------------------
int __thiscall BaseObject::numberGroups(BaseObject *this)
{
  return this->numberGroupsValue;
}

//----- (0040A400) --------------------------------------------------------
int __thiscall BaseObject::groupID(BaseObject *this, int v)
{
  int *v2; // edx@1
  int result; // eax@4

  v2 = this->groupIDValue;
  if( v2 && v >= 0 && v < this->numberGroupsValue )
    result = v2[v];
  else
    result = -1;
  return result;
}

//----- (0040A420) --------------------------------------------------------
int __thiscall BaseObject::inGroup(BaseObject *this, int v)
{
  int v2; // edx@1
  int v3; // eax@1
  int *v4; // ecx@2
  int result; // eax@5

  v2 = this->numberGroupsValue;
  v3 = 0;
  if( v2 <= 0 )
  {
    result = 0;
  }
  else
  {
    v4 = this->groupIDValue;
    while( *v4 != v )
    {
      ++v3;
      ++v4;
      if( v3 >= v2 )
        return 0;
    }
    result = 1;
  }
  return result;
}

//----- (0040A460) --------------------------------------------------------
int *__thiscall BaseObject::addGroup(BaseObject *this, int v)
{
  BaseObject *v2; // esi@1
  int *result; // eax@2
  int *v4; // edi@3
  int i; // eax@4
  int *v6; // ST00_4@6

  v2 = this;
  if( BaseObject::inGroup(this, v) )
  {
    result = 0;
  }
  else
  {
    result = (int *)operator new(4 * v2->numberGroupsValue + 4);
    v4 = result;
    if( result )
    {
      for( i = 0; i < v2->numberGroupsValue; v4[i - 1] = v2->groupIDValue[i - 1] )
        ++i;
      v4[v2->numberGroupsValue] = v;
      v6 = v2->groupIDValue;
      ++v2->numberGroupsValue;
      operator delete(v6);
      v2->groupIDValue = v4;
      result = (int *)1;
    }
  }
  return result;
}

//----- (0040A4E0) --------------------------------------------------------
int *__thiscall BaseObject::removeGroup(BaseObject *this, int v)
{
  BaseObject *v2; // esi@1
  int *result; // eax@1
  int *v4; // ebx@2
  int v5; // ecx@3
  int *v6; // edx@4
  int v7; // eax@5
  int *v8; // ST00_4@8

  v2 = this;
  result = (int *)BaseObject::inGroup(this, v);
  if( result )
  {
    result = (int *)operator new(4 * v2->numberGroupsValue - 4);
    v4 = result;
    if( result )
    {
      v5 = 0;
      if( v2->numberGroupsValue > 0 )
      {
        v6 = result;
        do
        {
          v7 = v2->groupIDValue[v5];
          if( v7 != v )
          {
            *v6 = v7;
            ++v6;
          }
          ++v5;
        }
        while( v5 < v2->numberGroupsValue );
      }
      v8 = v2->groupIDValue;
      --v2->numberGroupsValue;
      operator delete(v8);
      v2->groupIDValue = v4;
      result = (int *)1;
    }
  }
  return result;
}

//----- (0040A560) --------------------------------------------------------
int __thiscall BaseObject::categoryID(BaseObject *this)
{
  return this->categoryIDValue;
}

//----- (0040A570) --------------------------------------------------------
int __thiscall BaseObject::typeID(BaseObject *this)
{
  return this->typeIDValue;
}

//----- (0040A580) --------------------------------------------------------
int *__thiscall BaseObject::gameID(BaseObject *this)
{
  return &this->gameIDValue;
}

//----- (0040A590) --------------------------------------------------------
char *__thiscall BaseObject::name(BaseObject *this)
{
  return this->nameValue;
}

//----- (0040A5A0) --------------------------------------------------------
double __thiscall BaseObject::xPosition(BaseObject *this)
{
  return this->xPositionValue;
}

//----- (0040A5B0) --------------------------------------------------------
double __thiscall BaseObject::yPosition(BaseObject *this)
{
  return this->yPositionValue;
}

//----- (0040A5C0) --------------------------------------------------------
double __thiscall BaseObject::zPosition(BaseObject *this)
{
  return this->zPositionValue;
}

//----- (0040A5D0) --------------------------------------------------------
double __thiscall BaseObject::xSize(BaseObject *this)
{
  return this->xSizeValue;
}

//----- (0040A5E0) --------------------------------------------------------
double __thiscall BaseObject::ySize(BaseObject *this)
{
  return this->ySizeValue;
}

//----- (0040A5F0) --------------------------------------------------------
double __thiscall BaseObject::zSize(BaseObject *this)
{
  return this->zSizeValue;
}

//----- (0040A600) --------------------------------------------------------
int __thiscall BaseObject::hitPoints(BaseObject *this)
{
  return this->hitPointValue;
}

//----- (0040A610) --------------------------------------------------------
int __thiscall BaseObject::minHitPoints(BaseObject *this)
{
  return this->minHitPointValue;
}

//----- (0040A620) --------------------------------------------------------
int __thiscall BaseObject::maxHitPoints(BaseObject *this)
{
  return this->maxHitPointValue;
}

//----- (0040A630) --------------------------------------------------------
int __thiscall BaseObject::busy(BaseObject *this)
{
  return this->busyValue;
}

//----- (0040A640) --------------------------------------------------------
int __thiscall BaseObject::currentTask(BaseObject *this)
{
  return this->currentTaskValue;
}

//----- (0040A650) --------------------------------------------------------
int __thiscall BaseObject::currentTarget(BaseObject *this)
{
  return this->currentTargetValue;
}

//----- (0040A660) --------------------------------------------------------
int __thiscall BaseObject::currentTargetType(BaseObject *this)
{
  return this->currentTargetTypeValue;
}

//----- (0040A670) --------------------------------------------------------
double __thiscall BaseObject::currentTargetXPosition(BaseObject *this)
{
  return this->currentTargetXPositionValue;
}

//----- (0040A680) --------------------------------------------------------
double __thiscall BaseObject::currentTargetYPosition(BaseObject *this)
{
  return this->currentTargetYPositionValue;
}

//----- (0040A690) --------------------------------------------------------
double __thiscall BaseObject::currentTargetZPosition(BaseObject *this)
{
  return this->currentTargetZPositionValue;
}

//----- (0040A6A0) --------------------------------------------------------
void __thiscall BaseObject::setXPosition(BaseObject *this, float v)
{
  this->xPositionValue = v;
}

//----- (0040A6B0) --------------------------------------------------------
void __thiscall BaseObject::setYPosition(BaseObject *this, float v)
{
  this->yPositionValue = v;
}

//----- (0040A6C0) --------------------------------------------------------
void __thiscall BaseObject::setZPosition(BaseObject *this, float v)
{
  this->zPositionValue = v;
}

//----- (0040A6D0) --------------------------------------------------------
void __thiscall BaseObject::setXSize(BaseObject *this, float v)
{
  this->xSizeValue = v;
}

//----- (0040A6E0) --------------------------------------------------------
void __thiscall BaseObject::setYSize(BaseObject *this, float v)
{
  this->ySizeValue = v;
}

//----- (0040A6F0) --------------------------------------------------------
void __thiscall BaseObject::setZSize(BaseObject *this, float v)
{
  this->zSizeValue = v;
}

//----- (0040A700) --------------------------------------------------------
void __thiscall BaseObject::setHitPoints(BaseObject *this, int v)
{
  this->hitPointValue = v;
}

//----- (0040A710) --------------------------------------------------------
void __thiscall BaseObject::incrementHitPoints(BaseObject *this, int v)
{
  this->hitPointValue += v;
}

//----- (0040A720) --------------------------------------------------------
void __thiscall BaseObject::decrementHitPoints(BaseObject *this, int v)
{
  this->hitPointValue -= v;
}

//----- (0040A730) --------------------------------------------------------
void __thiscall BaseObject::setMinHitPoints(BaseObject *this, int v)
{
  this->minHitPointValue = v;
}

//----- (0040A740) --------------------------------------------------------
void __thiscall BaseObject::incrementMinHitPoints(BaseObject *this, int v)
{
  this->minHitPointValue += v;
}

//----- (0040A750) --------------------------------------------------------
void __thiscall BaseObject::decrementMinHitPoints(BaseObject *this, int v)
{
  this->minHitPointValue -= v;
}

//----- (0040A760) --------------------------------------------------------
void __thiscall BaseObject::setMaxHitPoints(BaseObject *this, int v)
{
  this->maxHitPointValue = v;
}

//----- (0040A770) --------------------------------------------------------
void __thiscall BaseObject::incrementMaxHitPoints(BaseObject *this, int v)
{
  this->maxHitPointValue += v;
}

//----- (0040A790) --------------------------------------------------------
void __thiscall BaseObject::decrementMaxHitPoints(BaseObject *this, int v)
{
  this->maxHitPointValue -= v;
}

//----- (0040A7B0) --------------------------------------------------------
void __thiscall BaseObject::setBusy(BaseObject *this, int v)
{
  this->busyValue = v;
}

//----- (0040A7C0) --------------------------------------------------------
void __thiscall BaseObject::setCurrentTask(BaseObject *this, int v)
{
  this->currentTaskValue = v;
}

//----- (0040A7D0) --------------------------------------------------------
void __thiscall BaseObject::setCurrentTarget(BaseObject *this, int v)
{
  this->currentTargetValue = v;
}

//----- (0040A7E0) --------------------------------------------------------
void __thiscall BaseObject::setCurrentTargetType(BaseObject *this, int v)
{
  this->currentTargetTypeValue = v;
}

//----- (0040A7F0) --------------------------------------------------------
void __thiscall BaseObject::setCurrentTargetPosition(BaseObject *this, float x, float y, float z)
{
  this->currentTargetXPositionValue = x;
  this->currentTargetYPositionValue = y;
  this->currentTargetZPositionValue = z;
}
