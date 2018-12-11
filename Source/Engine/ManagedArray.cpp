#include "ManagedArray.hpp"

//----- (00408D20) --------------------------------------------------------
void ManagedArray<int>::~ManagedArray<int>(ManagedArray<int> *this)
{
  ManagedArray<int> *v1; // esi@1

  v1 = this;
  if( this->value )
  {
    operator delete(this->value);
    v1->value = 0;
  }
  v1->numberValue = 0;
  v1->desiredNumberValue = 0;
  v1->maximumSizeValue = 0;
}

//----- (004147A0) --------------------------------------------------------
int *__thiscall ManagedArray<int>::resize(ManagedArray<int> *this, int s)
{
  ManagedArray<int> *v2; // esi@1
  int *result; // eax@1
  int *v4; // edi@1
  int i; // eax@2

  v2 = this;
  result = (int *)operator new(4 * s);
  v4 = result;
  if( result )
  {
    for( i = 0; i < v2->maximumSizeValue; v4[i - 1] = v2->value[i - 1] )
    {
      if( i >= s )
        break;
      ++i;
    }
    operator delete(v2->value);
    v2->value = v4;
    v2->maximumSizeValue = s;
    result = (int *)1;
  }
  return result;
}

//----- (004DE980) --------------------------------------------------------
int __thiscall ManagedArray<int>::contains(ManagedArray<int> *this, const int *r)
{
  int v2; // edx@1
  int v3; // eax@1

  v2 = this->numberValue;
  v3 = 0;
  if( v2 > 0 )
  {
    while( v3 < this->maximumSizeValue )
    {
      if( this->value[v3] == *r )
        return 1;
      if( ++v3 >= v2 )
        return 0;
    }
  }
  return 0;
}

//----- (004DE9D0) --------------------------------------------------------
int __thiscall ManagedArray<int>::add(ManagedArray<int> *this, int r)
{
  ManagedArray<int> *v2; // esi@1
  int v3; // eax@1
  int v4; // ecx@1
  int v5; // ebx@6
  int *v6; // edi@6
  int i; // eax@7

  v2 = this;
  v3 = 0;
  v4 = this->numberValue;
  if( v4 > 0 )
  {
    while( v3 < v2->maximumSizeValue )
    {
      if( v2->value[v3] == r )
        return 0;
      if( ++v3 >= v4 )
        break;
    }
  }
  if( v4 > v2->maximumSizeValue - 1 )
  {
    v5 = v4 + 1;
    v6 = (int *)operator new(4 * (v4 + 1));
    if( v6 )
    {
      for( i = 0; i < v2->maximumSizeValue; v6[i - 1] = v2->value[i - 1] )
      {
        if( i >= v5 )
          break;
        ++i;
      }
      operator delete(v2->value);
      v2->value = v6;
      v2->maximumSizeValue = v5;
    }
  }
  v2->value[v2->numberValue++] = r;
  return 1;
}

//----- (004EA750) --------------------------------------------------------
int *__thiscall ManagedArray<int>::operator[](ManagedArray<int> *this, int v)
{
  ManagedArray<int> *v2; // esi@1
  int v3; // ebx@2
  int *v4; // edi@2
  int i; // eax@3

  v2 = this;
  if( v > this->maximumSizeValue - 1 )
  {
    v3 = v + 1;
    v4 = (int *)operator new(4 * (v + 1));
    if( v4 )
    {
      for( i = 0; i < v2->maximumSizeValue; v4[i - 1] = v2->value[i - 1] )
      {
        if( i >= v3 )
          break;
        ++i;
      }
      operator delete(v2->value);
      v2->value = v4;
      v2->maximumSizeValue = v3;
    }
  }
  return &v2->value[v];
}

//----- (004F1390) --------------------------------------------------------
int __thiscall ManagedArray<int>::remove(ManagedArray<int> *this, int r)
{
  int v2; // esi@1
  int v3; // eax@1
  int *v4; // edx@2
  int result; // eax@6
  int v6; // eax@9

  v2 = this->maximumSizeValue;
  v3 = 0;
  if( v2 > 0 )
  {
    v4 = this->value;
    do
    {
      if( *v4 == r )
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
        this->value[v3 - 1] = this->value[v3];
      }
      while( v3 < this->maximumSizeValue - 1 );
    }
    v6 = this->numberValue - 1;
    this->numberValue = v6;
    if( v6 < 0 )
      this->numberValue = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
