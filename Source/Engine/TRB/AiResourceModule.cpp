
/**
 * @file    Engine\TRB\AiResourceModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

//----- (004E6B40) --------------------------------------------------------
void __thiscall TribeResourceAIModule::TribeResourceAIModule(TribeResourceAIModule *this, void *pW, int playerID, int n, int iV, int minV, int maxV)
{
  TribeResourceAIModule *v7; // esi@1

  v7 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aResourceAi, 1007, playerID, pW);
  v7->md = 0;
  v7->numberResourcesValue = n;
  v7->vfptr = (AIModuleVtbl *)&TribeResourceAIModule::`vftable';
}
// 575638: using guessed type int (__thiscall *TribeResourceAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004E6B80) --------------------------------------------------------
TribeResourceAIModule *__thiscall TribeResourceAIModule::`vector deleting destructor'(TribeResourceAIModule *this, unsigned int __flags)
{
  TribeResourceAIModule *v2; // esi@1

  v2 = this;
  TribeResourceAIModule::~TribeResourceAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E6BA0) --------------------------------------------------------
void __userpurge TribeResourceAIModule::TribeResourceAIModule(TribeResourceAIModule *this@<ecx>, int a2@<ebp>, int a3@<edi>, int playerID, int infile)
{
  TribeResourceAIModule *v5; // esi@1

  v5 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aResai, 1007, playerID, 0);
  v5->md = 0;
  v5->vfptr = (AIModuleVtbl *)&TribeResourceAIModule::`vftable';
  rge_read(a2, a3, infile, &v5->numberResourcesValue, 4);
}
// 575638: using guessed type int (__thiscall *TribeResourceAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004E6C20) --------------------------------------------------------
void __thiscall TribeResourceAIModule::~TribeResourceAIModule(TribeResourceAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&TribeResourceAIModule::`vftable';
  AIModule::~AIModule((AIModule *)&this->vfptr);
}
// 575638: using guessed type int (__thiscall *TribeResourceAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004E6C30) --------------------------------------------------------
void __thiscall TribeResourceAIModule::setMainDecisionAI(TribeResourceAIModule *this, TribeMainDecisionAIModule *m)
{
  this->md = m;
}

//----- (004E6C40) --------------------------------------------------------
int __thiscall TribeResourceAIModule::save(TribeResourceAIModule *this, int outfile)
{
  rge_write(outfile, &this->numberResourcesValue, 4);
  return 1;
}

//----- (004E6C60) --------------------------------------------------------
int __thiscall TribeResourceAIModule::numberResources(TribeResourceAIModule *this)
{
  return this->numberResourcesValue;
}

//----- (004E6C70) --------------------------------------------------------
int __thiscall TribeResourceAIModule::resource(TribeResourceAIModule *this, int n)
{
  signed __int64 v2; // rax@3

  if ( n < 0 || n >= this->numberResourcesValue )
    LODWORD(v2) = -1;
  else
    v2 = (signed __int64)this->md->player->attributes[n];
  return v2;
}

//----- (004E6CA0) --------------------------------------------------------
int __thiscall TribeResourceAIModule::resourcesAvailable(TribeResourceAIModule *this, ResourceItem *ri)
{
  TribeResourceAIModule *v2; // ebx@1
  int result; // eax@2
  int v4; // esi@5
  float *v5; // ebp@6

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
        while ( 1 )
        {
          v5 = v2->md->player->attributes;
          if ( (double)ResourceItem::value(ri, v4) > v5[v4] )
            break;
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

//----- (004E6D40) --------------------------------------------------------
int __thiscall TribeResourceAIModule::unavailableResource(TribeResourceAIModule *this, ResourceItem *ri)
{
  TribeResourceAIModule *v2; // ebx@1
  int result; // eax@2
  int v4; // esi@4
  float *v5; // ebp@5

  v2 = this;
  if ( ri )
  {
    if ( this->numberResourcesValue != ResourceItem::number(ri) || (v4 = 0, ResourceItem::number(ri) <= 0) )
    {
      result = -1;
    }
    else
    {
      while ( 1 )
      {
        v5 = v2->md->player->attributes;
        if ( (double)ResourceItem::value(ri, v4) > v5[v4] )
          break;
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

//----- (004E6DD0) --------------------------------------------------------
char *__stdcall TribeResourceAIModule::resourceName(int i)
{
  char *result; // eax@2

  if ( i )
  {
    if ( i == 1 )
    {
      result = aWood;
    }
    else if ( i == 2 )
    {
      result = aStone;
    }
    else
    {
      result = aGold;
      if ( i != 3 )
        result = aUnknown;
    }
  }
  else
  {
    result = aFood;
  }
  return result;
}
