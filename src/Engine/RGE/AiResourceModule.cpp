
/**
 * @file    Engine\RGE\AiResourceModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00412310) --------------------------------------------------------
void __thiscall ResourceAIModule::ResourceAIModule(ResourceAIModule *this, void *pW, int playerID, int n, int iV, int minV, int maxV)
{
  ResourceAIModule *v7; // esi@1
  int *v8; // eax@1
  unsigned int v9; // ST0C_4@1
  int *v10; // eax@1
  unsigned int v11; // ST0C_4@1
  int *v12; // eax@1
  int v13; // ecx@1
  int v14; // eax@1

  v7 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aResourceAi, 1007, playerID, pW);
  v7->md = 0;
  v7->numberResourcesValue = n;
  v7->vfptr = (AIModuleVtbl *)&ResourceAIModule::`vftable';
  v7->resourceValue = (int *)operator new(4 * n);
  v8 = (int *)operator new(4 * v7->numberResourcesValue);
  v9 = 4 * v7->numberResourcesValue;
  v7->minValue = v8;
  v10 = (int *)operator new(v9);
  v11 = 4 * v7->numberResourcesValue;
  v7->maxValue = v10;
  v7->resourceTypesValue = (int **)operator new(v11);
  v12 = (int *)operator new(4 * v7->numberResourcesValue);
  v13 = v7->numberResourcesValue;
  v7->numberResourceTypesValue = v12;
  v14 = 0;
  if ( v13 > 0 )
  {
    do
    {
      v7->resourceValue[++v14 - 1] = iV;
      v7->minValue[v14 - 1] = minV;
      v7->maxValue[v14 - 1] = maxV;
      v7->numberResourceTypesValue[v14 - 1] = 0;
      v7->resourceTypesValue[v14 - 1] = 0;
    }
    while ( v14 < v7->numberResourcesValue );
  }
}
// 56E9D8: using guessed type int (__thiscall *ResourceAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00412460) --------------------------------------------------------
ResourceAIModule *__thiscall ResourceAIModule::`vector deleting destructor'(ResourceAIModule *this, unsigned int __flags)
{
  ResourceAIModule *v2; // esi@1

  v2 = this;
  ResourceAIModule::~ResourceAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00412540) --------------------------------------------------------
int __stdcall ResourceAIModule::processMessage(AIModuleMessage *m)
{
  return 0;
}

//----- (00412550) --------------------------------------------------------
int __stdcall ResourceAIModule::update(int timeLimit)
{
  return 0;
}

//----- (00412570) --------------------------------------------------------
void __thiscall ResourceAIModule::setMainDecisionAI(ResourceAIModule *this, MainDecisionAIModule *m)
{
  this->md = m;
}

//----- (00412580) --------------------------------------------------------
int __thiscall ResourceAIModule::numberResources(ResourceAIModule *this)
{
  return this->numberResourcesValue;
}

//----- (00412590) --------------------------------------------------------
int __thiscall ResourceAIModule::resource(ResourceAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= this->numberResourcesValue )
    result = -1;
  else
    result = this->resourceValue[n];
  return result;
}

//----- (004125C0) --------------------------------------------------------
int __thiscall ResourceAIModule::resourcesAvailable(ResourceAIModule *this, ResourceItem *ri)
{
  ResourceAIModule *v2; // ebx@1
  int result; // eax@2
  int v4; // esi@5

  v2 = this;
  if ( ri )
  {
    if ( this->numberResourcesValue == ResourceItem::number(ri) )
    {
      v4 = 0;
      if ( ResourceItem::number(ri) <= 0 )
      {
        result = 1;
      }
      else
      {
        while ( v2->resourceValue[v4] >= ResourceItem::value(ri, v4) )
        {
          if ( ++v4 >= ResourceItem::number(ri) )
            return 1;
        }
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00412640) --------------------------------------------------------
int __thiscall ResourceAIModule::unavailableResource(ResourceAIModule *this, ResourceItem *ri)
{
  ResourceAIModule *v2; // ebx@1
  int result; // eax@2
  int v4; // esi@4

  v2 = this;
  if ( ri )
  {
    if ( this->numberResourcesValue != ResourceItem::number(ri) || (v4 = 0, ResourceItem::number(ri) <= 0) )
    {
      result = -1;
    }
    else
    {
      while ( v2->resourceValue[v4] >= ResourceItem::value(ri, v4) )
      {
        if ( ++v4 >= ResourceItem::number(ri) )
          return -1;
      }
      result = v4;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004126B0) --------------------------------------------------------
int __thiscall ResourceAIModule::minValueOfResource(ResourceAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= this->numberResourcesValue )
    result = -1;
  else
    result = this->minValue[n];
  return result;
}

//----- (004126E0) --------------------------------------------------------
int __thiscall ResourceAIModule::maxValueOfResource(ResourceAIModule *this, int n)
{
  int result; // eax@3

  if ( n < 0 || n >= this->numberResourcesValue )
    result = -1;
  else
    result = this->maxValue[n];
  return result;
}

//----- (00412710) --------------------------------------------------------
void __thiscall ResourceAIModule::setResource(ResourceAIModule *this, int n, int v)
{
  ResourceAIModule *v3; // esi@1

  v3 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aSetresourceNDV, n, v);
  if ( n >= 0 && n < v3->numberResourcesValue )
  {
    v3->resourceValue[n] = v;
    AIModule::logCommonHistory((AIModule *)&v3->vfptr, aSetresourceRDD, n, v3->resourceValue[n]);
  }
}

//----- (00412770) --------------------------------------------------------
void __thiscall ResourceAIModule::setResources(ResourceAIModule *this, ResourceItem *ri)
{
  ResourceAIModule *v2; // ebx@1
  int i; // esi@3
  int v4; // eax@4

  v2 = this;
  if ( ri )
  {
    if ( this->numberResourcesValue == ResourceItem::number(ri) )
    {
      for ( i = 0; i < ResourceItem::number(ri); ++i )
      {
        v4 = ResourceItem::value(ri, i);
        ResourceAIModule::setResource(v2, i, v4);
      }
    }
  }
}

//----- (004127C0) --------------------------------------------------------
void __thiscall ResourceAIModule::incrementResource(ResourceAIModule *this, int n, int v)
{
  ResourceAIModule *v3; // esi@1

  v3 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aIncrementresou, n, v);
  if ( n >= 0 && n < v3->numberResourcesValue )
  {
    v3->resourceValue[n] += v;
    if ( v )
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aIncrementres_1, n, v3->resourceValue[n]);
  }
}

//----- (00412820) --------------------------------------------------------
void __thiscall ResourceAIModule::incrementResources(ResourceAIModule *this, ResourceItem *ri)
{
  ResourceAIModule *v2; // ebx@1
  int i; // esi@3
  int v4; // eax@4

  v2 = this;
  if ( ri )
  {
    if ( this->numberResourcesValue == ResourceItem::number(ri) )
    {
      for ( i = 0; i < ResourceItem::number(ri); ++i )
      {
        v4 = ResourceItem::value(ri, i);
        ResourceAIModule::incrementResource(v2, i, v4);
      }
    }
  }
}

//----- (00412870) --------------------------------------------------------
void __thiscall ResourceAIModule::decrementResource(ResourceAIModule *this, int n, int v)
{
  ResourceAIModule *v3; // esi@1

  v3 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aDecrementresou, n, v);
  if ( n >= 0 && n < v3->numberResourcesValue )
  {
    v3->resourceValue[n] -= v;
    if ( v )
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aDecrementres_1, n, v3->resourceValue[n]);
  }
}

//----- (004128D0) --------------------------------------------------------
void __thiscall ResourceAIModule::decrementResources(ResourceAIModule *this, ResourceItem *ri)
{
  ResourceAIModule *v2; // ebx@1
  int i; // esi@3
  int v4; // eax@4

  v2 = this;
  if ( ri )
  {
    if ( this->numberResourcesValue == ResourceItem::number(ri) )
    {
      for ( i = 0; i < ResourceItem::number(ri); ++i )
      {
        v4 = ResourceItem::value(ri, i);
        ResourceAIModule::decrementResource(v2, i, v4);
      }
    }
  }
}

//----- (00412920) --------------------------------------------------------
void __thiscall ResourceAIModule::setResourceMin(ResourceAIModule *this, int n, int v)
{
  if ( n >= 0 && n < this->numberResourcesValue )
    this->minValue[n] = v;
}

//----- (00412940) --------------------------------------------------------
void __thiscall ResourceAIModule::setResourceMax(ResourceAIModule *this, int n, int v)
{
  if ( n >= 0 && n < this->numberResourcesValue )
    this->maxValue[n] = v;
}

//----- (00412960) --------------------------------------------------------
int __stdcall ResourceAIModule::filterOutMessage(AIModuleMessage *m)
{
  return AIModule::filterOutMessage(m);
}

//----- (00412970) --------------------------------------------------------
void __thiscall ResourceAIModule::addResourceType(ResourceAIModule *this, int r, int t)
{
  ResourceAIModule *v3; // esi@1
  int v4; // edi@1
  int *v5; // ebx@1
  int i; // eax@1

  v3 = this;
  v4 = r;
  v5 = (int *)operator new(4 * this->numberResourceTypesValue[r] + 4);
  for ( i = 0; i < v3->numberResourceTypesValue[v4]; v5[i - 1] = v3->resourceTypesValue[v4][i - 1] )
    ++i;
  v5[i] = t;
  if ( v3->resourceTypesValue[v4] )
    operator delete(v3->resourceTypesValue[v4]);
  v3->resourceTypesValue[v4] = v5;
  ++v3->numberResourceTypesValue[v4];
}

//----- (00412A10) --------------------------------------------------------
int __thiscall ResourceAIModule::isResourceType(ResourceAIModule *this, int r, int t)
{
  ResourceAIModule *v3; // esi@1
  int v4; // edi@1
  int v5; // ebx@1
  int *v6; // eax@2
  int result; // eax@5

  v3 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aEnteringIsreso, r, t);
  v4 = r;
  AIModule::logCommonHistory((AIModule *)&v3->vfptr, aThereAreDResou, v3->numberResourceTypesValue[r], r);
  v5 = 0;
  if ( v3->numberResourceTypesValue[r] <= 0 )
  {
LABEL_5:
    AIModule::logCommonHistory((AIModule *)&v3->vfptr, aNoMatchReturni);
    result = 0;
  }
  else
  {
    v6 = v3->resourceTypesValue[v4];
    while ( 1 )
    {
      AIModule::logCommonHistory((AIModule *)&v3->vfptr, aCheckingAgains, v6[v5]);
      v6 = v3->resourceTypesValue[v4];
      if ( v6[v5] == t )
        break;
      if ( ++v5 >= v3->numberResourceTypesValue[v4] )
        goto LABEL_5;
    }
    AIModule::logCommonHistory((AIModule *)&v3->vfptr, aMatchReturning);
    result = 1;
  }
  return result;
}

//----- (00412AD0) --------------------------------------------------------
int __thiscall ResourceAIModule::numberResourceTypes(ResourceAIModule *this, int r)
{
  return this->numberResourceTypesValue[r];
}

//----- (00412AE0) --------------------------------------------------------
int ResourceAIModule::lowestResourceType()
{
  return 1;
}
