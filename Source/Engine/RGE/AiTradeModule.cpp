
/**
 * @file    Engine\RGE\AiTradeModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00412E40) --------------------------------------------------------
void __thiscall TradeAIModule::TradeAIModule(TradeAIModule *this, void *pW, int playerID)
{
  TradeAIModule *v3; // esi@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aTradeAi, 1010, playerID, pW);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&TradeAIModule::`vftable';
}
// 56EA98: using guessed type int (__thiscall *TradeAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00412E80) --------------------------------------------------------
TradeAIModule *__thiscall TradeAIModule::`scalar deleting destructor'(TradeAIModule *this, unsigned int __flags)
{
  TradeAIModule *v2; // esi@1

  v2 = this;
  TradeAIModule::~TradeAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00412EA0) --------------------------------------------------------
void __thiscall TradeAIModule::TradeAIModule(TradeAIModule *this, int playerID, int infile)
{
  TradeAIModule *v3; // esi@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aTradeAi, 1010, playerID, 0);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&TradeAIModule::`vftable';
}
// 56EA98: using guessed type int (__thiscall *TradeAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00412ED0) --------------------------------------------------------
void __thiscall TradeAIModule::~TradeAIModule(TradeAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&TradeAIModule::`vftable';
  AIModule::~AIModule((AIModule *)&this->vfptr);
}
// 56EA98: using guessed type int (__thiscall *TradeAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (00412EE0) --------------------------------------------------------
void __thiscall TradeAIModule::setMainDecisionAI(TradeAIModule *this, MainDecisionAIModule *m)
{
  this->md = m;
}

//----- (00412EF0) --------------------------------------------------------
int __stdcall TradeAIModule::save(int outfile)
{
  return 1;
}
