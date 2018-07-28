
/**
 * @file    Engine\RGE\AiResourceItem.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00411EC0) --------------------------------------------------------
void __thiscall ResourceItem::ResourceItem(ResourceItem *this)
{
  signed int v1; // esi@1
  char *v2; // edx@1

  v1 = 8;
  this->next = 0;
  this->prev = 0;
  this->numberValue = 0;
  this->vfptr = (ResourceItemVtbl *)&ResourceItem::`vftable';
  v2 = (char *)this->sortedValue;
  do
  {
    *((_DWORD *)v2 - 8) = -1;
    *(_DWORD *)v2 = -1;
    *((_DWORD *)v2 + 8) = -1;
    v2 += 4;
    --v1;
  }
  while ( v1 );
}
// 56E9D0: using guessed type int (__thiscall *ResourceItem::`vftable')(void *Memory, unsigned int __flags);

//----- (00411EF0) --------------------------------------------------------
ResourceItem *__thiscall ResourceItem::`scalar deleting destructor'(ResourceItem *this, unsigned int __flags)
{
  ResourceItem *v2; // esi@1

  v2 = this;
  ResourceItem::~ResourceItem(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00411F10) --------------------------------------------------------
void __thiscall ResourceItem::ResourceItem(ResourceItem *this, int n)
{
  int v2; // esi@1
  char *v3; // edx@2
  char *v4; // edx@6
  int v5; // ecx@6

  v2 = 0;
  this->next = 0;
  this->prev = 0;
  this->numberValue = n;
  this->vfptr = (ResourceItemVtbl *)&ResourceItem::`vftable';
  if ( n <= 0 )
  {
LABEL_5:
    if ( v2 < 8 )
    {
      v4 = (char *)&this->sortedValue[v2];
      v5 = 8 - v2;
      do
      {
        *((_DWORD *)v4 - 8) = -1;
        *(_DWORD *)v4 = -1;
        *((_DWORD *)v4 + 8) = -1;
        v4 += 4;
        --v5;
      }
      while ( v5 );
    }
  }
  else
  {
    v3 = (char *)this->sortedValue;
    while ( v2 < 8 )
    {
      *((_DWORD *)v3 - 8) = 0;
      *(_DWORD *)v3 = -1;
      *((_DWORD *)v3 + 8) = -1;
      ++v2;
      v3 += 4;
      if ( v2 >= this->numberValue )
        goto LABEL_5;
    }
  }
}
// 56E9D0: using guessed type int (__thiscall *ResourceItem::`vftable')(void *Memory, unsigned int __flags);

//----- (00411F80) --------------------------------------------------------
void __thiscall ResourceItem::ResourceItem(ResourceItem *this, int n, int *v)
{
  ResourceItem *v3; // eax@1
  signed int v4; // esi@1
  int *v5; // ecx@2
  int v6; // edx@2
  int v7; // edx@6
  int v8; // ecx@6

  v3 = this;
  v4 = 0;
  this->next = 0;
  this->prev = 0;
  this->numberValue = n;
  this->vfptr = (ResourceItemVtbl *)&ResourceItem::`vftable';
  if ( n <= 0 )
  {
LABEL_5:
    if ( v4 < 8 )
    {
      v7 = (int)&v3->sortedValue[v4];
      v8 = 8 - v4;
      do
      {
        *(_DWORD *)(v7 - 32) = -1;
        *(_DWORD *)v7 = -1;
        *(_DWORD *)(v7 + 32) = -1;
        v7 += 4;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = v;
    v6 = (int)v3->sortedValue;
    while ( v4 < 8 )
    {
      ++v4;
      *(_DWORD *)(v6 - 32) = *v5;
      *(_DWORD *)v6 = -1;
      *(_DWORD *)(v6 + 32) = -1;
      ++v5;
      v6 += 4;
      if ( v4 >= v3->numberValue )
        goto LABEL_5;
    }
  }
}
// 56E9D0: using guessed type int (__thiscall *ResourceItem::`vftable')(void *Memory, unsigned int __flags);

//----- (00411FF0) --------------------------------------------------------
void __thiscall ResourceItem::ResourceItem(ResourceItem *this, ResourceItem *ri)
{
  int v2; // edi@1
  int v3; // edx@1
  char *v4; // esi@2
  char *v5; // edx@2

  v2 = 0;
  this->next = 0;
  this->prev = 0;
  v3 = ri->numberValue;
  this->vfptr = (ResourceItemVtbl *)&ResourceItem::`vftable';
  this->numberValue = v3;
  if ( v3 > 0 )
  {
    v4 = (char *)ri->sortedIndexValue;
    v5 = (char *)this->valueValue;
    do
    {
      if ( v2 >= 8 )
        break;
      ++v2;
      *(_DWORD *)v5 = *(_DWORD *)&v5[(char *)ri - (char *)this];
      *((_DWORD *)v5 + 8) = *((_DWORD *)v4 - 8);
      *((_DWORD *)v5 + 16) = *(_DWORD *)v4;
      v5 += 4;
      v4 += 4;
    }
    while ( v2 < this->numberValue );
  }
}
// 56E9D0: using guessed type int (__thiscall *ResourceItem::`vftable')(void *Memory, unsigned int __flags);

//----- (00412050) --------------------------------------------------------
void __thiscall ResourceItem::ResourceItem(ResourceItem *this, ResourceItem *ri)
{
  int v2; // edi@1
  int v3; // edx@1
  char *v4; // esi@2
  char *v5; // edx@2

  v2 = 0;
  this->next = 0;
  this->prev = 0;
  v3 = ri->numberValue;
  this->vfptr = (ResourceItemVtbl *)&ResourceItem::`vftable';
  this->numberValue = v3;
  if ( v3 > 0 )
  {
    v4 = (char *)ri->sortedIndexValue;
    v5 = (char *)this->valueValue;
    do
    {
      if ( v2 >= 8 )
        break;
      ++v2;
      *(_DWORD *)v5 = *(_DWORD *)&v5[(char *)ri - (char *)this];
      *((_DWORD *)v5 + 8) = *((_DWORD *)v4 - 8);
      *((_DWORD *)v5 + 16) = *(_DWORD *)v4;
      v5 += 4;
      v4 += 4;
    }
    while ( v2 < this->numberValue );
  }
}
// 56E9D0: using guessed type int (__thiscall *ResourceItem::`vftable')(void *Memory, unsigned int __flags);

//----- (004120B0) --------------------------------------------------------
void __thiscall ResourceItem::~ResourceItem(ResourceItem *this)
{
  this->vfptr = (ResourceItemVtbl *)&ResourceItem::`vftable';
}
// 56E9D0: using guessed type int (__thiscall *ResourceItem::`vftable')(void *Memory, unsigned int __flags);

//----- (004120C0) --------------------------------------------------------
ResourceItem *__thiscall ResourceItem::operator+=(ResourceItem *this, ResourceItem *ri)
{
  ResourceItem *result; // eax@1
  int v3; // edx@1
  int v4; // esi@2
  char *v5; // edx@3

  result = this;
  v3 = this->numberValue;
  if ( v3 == ri->numberValue )
  {
    v4 = 0;
    if ( v3 > 0 )
    {
      v5 = (char *)this->valueValue;
      do
      {
        ++v4;
        *(_DWORD *)v5 += *(_DWORD *)&v5[(char *)ri - (char *)this];
        v5 += 4;
      }
      while ( v4 < this->numberValue );
    }
  }
  return result;
}

//----- (00412100) --------------------------------------------------------
int __cdecl operator==(ResourceItem *one, ResourceItem *two)
{
  int v2; // edx@1
  int v3; // ecx@2
  char *v4; // eax@3

  v2 = one->numberValue;
  if ( v2 == two->numberValue )
  {
    v3 = 0;
    if ( v2 <= 0 )
      return 1;
    v4 = (char *)one->valueValue;
    while ( *(_DWORD *)v4 == *(_DWORD *)&v4[(char *)two - (char *)one] )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        return 1;
    }
  }
  return 0;
}

//----- (00412140) --------------------------------------------------------
int __cdecl operator!=(ResourceItem *one, ResourceItem *two)
{
  int v2; // edx@1
  int v3; // ecx@2
  char *v4; // eax@3

  v2 = one->numberValue;
  if ( v2 == two->numberValue )
  {
    v3 = 0;
    if ( v2 <= 0 )
      return 0;
    v4 = (char *)one->valueValue;
    while ( *(_DWORD *)v4 == *(_DWORD *)&v4[(char *)two - (char *)one] )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        return 0;
    }
  }
  return 1;
}

//----- (00412180) --------------------------------------------------------
int __thiscall ResourceItem::value(ResourceItem *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= this->numberValue )
    result = -1;
  else
    result = this->valueValue[n];
  return result;
}

//----- (004121A0) --------------------------------------------------------
void __thiscall ResourceItem::setValue(ResourceItem *this, int n, int v)
{
  if ( n >= 0 && n < this->numberValue )
    this->valueValue[n] = v;
}

//----- (004121C0) --------------------------------------------------------
void __thiscall ResourceItem::incrementValue(ResourceItem *this, int n, int v)
{
  if ( n >= 0 && n < this->numberValue )
    this->valueValue[n] += v;
}

//----- (004121E0) --------------------------------------------------------
void __thiscall ResourceItem::setAllValues(ResourceItem *this, int v)
{
  memset32(this->valueValue, v, 8u);
}

//----- (00412200) --------------------------------------------------------
int __thiscall ResourceItem::number(ResourceItem *this)
{
  return this->numberValue;
}

//----- (00412210) --------------------------------------------------------
int __thiscall ResourceItem::largestValueIndex(ResourceItem *this, int num)
{
  ResourceItem *v2; // esi@1
  int result; // eax@3

  v2 = this;
  if ( this->numberValue < num || ResourceItem::sortLarge(this) != 1 )
    result = -1;
  else
    result = v2->sortedValue[num + 7];
  return result;
}

//----- (00412240) --------------------------------------------------------
int __thiscall ResourceItem::sortLarge(ResourceItem *this)
{
  int v1; // edx@1
  char *v2; // eax@2
  int v3; // edi@4
  int v4; // ebx@4
  char *v5; // esi@5
  int v6; // eax@6
  int v7; // edx@6
  int v8; // ebx@7
  int v9; // edi@13
  int v10; // edi@13
  _DWORD *v12; // [sp+10h] [bp-10h]@7
  int i; // [sp+14h] [bp-Ch]@4
  int v14; // [sp+1Ch] [bp-4h]@6

  v1 = 0;
  if ( this->numberValue > 0 )
  {
    v2 = (char *)this->sortedValue;
    do
    {
      *(_DWORD *)v2 = *((_DWORD *)v2 - 8);
      *((_DWORD *)v2 + 8) = v1++;
      v2 += 4;
    }
    while ( v1 < this->numberValue );
  }
  v3 = this->numberValue;
  v4 = 0;
  i = 0;
  if ( v3 > 0 )
  {
    v5 = (char *)this->sortedValue;
    do
    {
      v6 = v4 + 1;
      v7 = v4;
      v14 = v4 + 1;
      if ( v4 + 1 < v3 )
      {
        v8 = (int)&v5[-44 - (_DWORD)this];
        v12 = v5 + 4;
        do
        {
          if ( *v12 > *(int *)((char *)this->sortedValue + v8) )
          {
            v7 = v6;
            v8 = 4 * v6;
          }
          ++v6;
          ++v12;
        }
        while ( v6 < v3 );
        v6 = v14;
        v4 = i;
      }
      if ( v7 != v4 )
      {
        v9 = *(_DWORD *)v5;
        *(_DWORD *)v5 = this->sortedValue[v7];
        this->sortedValue[v7] = v9;
        v10 = *((_DWORD *)v5 + 8);
        *((_DWORD *)v5 + 8) = this->sortedIndexValue[v7];
        this->sortedIndexValue[v7] = v10;
      }
      v3 = this->numberValue;
      v4 = v6;
      v5 += 4;
      i = v6;
    }
    while ( v6 < v3 );
  }
  return 1;
}
