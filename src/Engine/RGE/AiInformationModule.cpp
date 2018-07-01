
/**
 * @file    Engine\RGE\AiInformationModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (0040CD90) --------------------------------------------------------
void __thiscall InformationAIModule::InformationAIModule(InformationAIModule *this, void *pW, int playerID)
{
  InformationAIModule *v3; // esi@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aInfai, 1005, playerID, pW);
  v3->vfptr = (AIModuleVtbl *)&InformationAIModule::`vftable';
}
// 56E898: using guessed type int (__thiscall *InformationAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040CDC0) --------------------------------------------------------
InformationAIModule *__thiscall InformationAIModule::`vector deleting destructor'(InformationAIModule *this, unsigned int __flags)
{
  InformationAIModule *v2; // esi@1

  v2 = this;
  InformationAIModule::~InformationAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040CDE0) --------------------------------------------------------
void __thiscall InformationAIModule::~InformationAIModule(InformationAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&InformationAIModule::`vftable';
  AIModule::~AIModule((AIModule *)&this->vfptr);
}
// 56E898: using guessed type int (__thiscall *InformationAIModule::`vftable')(void *Memory, unsigned int __flags);
