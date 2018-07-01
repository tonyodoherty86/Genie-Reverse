void __thiscall TribeHuntedAnimalUnitAIModule::TribeHuntedAnimalUnitAIModule(TribeHuntedAnimalUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeHuntedAnimalUnitAIModule *__thiscall TribeHuntedAnimalUnitAIModule::`vector deleting destructor'(TribeHuntedAnimalUnitAIModule *this, unsigned int __flags);
void __thiscall TribeHuntedAnimalUnitAIModule::~TribeHuntedAnimalUnitAIModule(TribeHuntedAnimalUnitAIModule *this); // idb
// int __userpurge TribeHuntedAnimalUnitAIModule::processNotify@<eax>(TribeHuntedAnimalUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
// int __userpurge TribeHuntedAnimalUnitAIModule::processIdle@<eax>(TribeHuntedAnimalUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch);
void __thiscall TribePreditorUnitAIModule::TribePreditorUnitAIModule(TribePreditorUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribePreditorUnitAIModule *__thiscall TribePreditorUnitAIModule::`scalar deleting destructor'(TribePreditorUnitAIModule *this, unsigned int __flags);
void __thiscall TribePreditorUnitAIModule::~TribePreditorUnitAIModule(TribePreditorUnitAIModule *this); // idb
int __stdcall TribePreditorUnitAIModule::canAttackUnitAtNeutrality(int oType);
// int __userpurge TribePreditorUnitAIModule::processNotify@<eax>(TribePreditorUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
void __thiscall TribeElephantUnitAIModule::TribeElephantUnitAIModule(TribeElephantUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeElephantUnitAIModule *__thiscall TribeElephantUnitAIModule::`scalar deleting destructor'(TribeElephantUnitAIModule *this, unsigned int __flags);
void __thiscall TribeElephantUnitAIModule::~TribeElephantUnitAIModule(TribeElephantUnitAIModule *this); // idb
// int __userpurge TribeElephantUnitAIModule::processNotify@<eax>(TribeElephantUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
int __stdcall TribeElephantUnitAIModule::processIdle(int doSearch);
void __thiscall TribeLionUnitAIModule::TribeLionUnitAIModule(TribeLionUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeLionUnitAIModule *__thiscall TribeLionUnitAIModule::`scalar deleting destructor'(TribeLionUnitAIModule *this, unsigned int __flags);
void __thiscall TribeLionUnitAIModule::~TribeLionUnitAIModule(TribeLionUnitAIModule *this); // idb
int __stdcall TribeLionUnitAIModule::canAttackUnitAtNeutrality(int oType);
// int __userpurge TribeLionUnitAIModule::processNotify@<eax>(TribeLionUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
int __thiscall TribeLionUnitAIModule::processIdle(TribeLionUnitAIModule *this, int doSearch); // idb
void __thiscall TribeRangedUnitAIModule::TribeRangedUnitAIModule(TribeRangedUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeRangedUnitAIModule *__thiscall TribeRangedUnitAIModule::`vector deleting destructor'(TribeRangedUnitAIModule *this, unsigned int __flags);
void __thiscall TribeRangedUnitAIModule::~TribeRangedUnitAIModule(TribeRangedUnitAIModule *this); // idb
// int __userpurge TribeRangedUnitAIModule::processNotify@<eax>(TribeRangedUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
void __thiscall TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(TribeRangedUnitAIModule2 *this, RGE_Static_Object *o, int iQS); // idb
TribeRangedUnitAIModule2 *__thiscall TribeRangedUnitAIModule2::`vector deleting destructor'(TribeRangedUnitAIModule2 *this, unsigned int __flags);
void __thiscall TribeRangedUnitAIModule2::~TribeRangedUnitAIModule2(TribeRangedUnitAIModule2 *this); // idb
// int __userpurge TribeRangedUnitAIModule2::processNotify@<eax>(TribeRangedUnitAIModule2 *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
void __thiscall TribeCivilianUnitAIModule::TribeCivilianUnitAIModule(TribeCivilianUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeCivilianUnitAIModule *__thiscall TribeCivilianUnitAIModule::`vector deleting destructor'(TribeCivilianUnitAIModule *this, unsigned int __flags);
void __thiscall TribeCivilianUnitAIModule::~TribeCivilianUnitAIModule(TribeCivilianUnitAIModule *this); // idb
BOOL __stdcall TribeCivilianUnitAIModule::importantWhenDead(int objectType);
RGE_Static_Object *__thiscall TribeCivilianUnitAIModule::attackObject(TribeCivilianUnitAIModule *this, int targetID, int unconditional);
RGE_Static_Object *__stdcall TribeCivilianUnitAIModule::canAttackUnit(RGE_Static_Object *unit);
int __stdcall TribeCivilianUnitAIModule::canAttackUnitAtNeutrality(int oType);
BOOL __stdcall TribeCivilianUnitAIModule::retryableOrder(int orderType);
int __stdcall TribeCivilianUnitAIModule::convertToLOSResourceType(int oType);
// int __userpurge TribeCivilianUnitAIModule::processNotify@<eax>(TribeCivilianUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
int __stdcall TribeCivilianUnitAIModule::processIdle(int doSearch);
int TribeCivilianUnitAIModule::processMisc();
void __thiscall TribePriestUnitAIModule::TribePriestUnitAIModule(TribePriestUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribePriestUnitAIModule *__thiscall TribePriestUnitAIModule::`scalar deleting destructor'(TribePriestUnitAIModule *this, unsigned int __flags);
void __thiscall TribePriestUnitAIModule::~TribePriestUnitAIModule(TribePriestUnitAIModule *this); // idb
// int __userpurge TribePriestUnitAIModule::attackObject@<eax>(TribePriestUnitAIModule *this@<ecx>, double a2@<st0>, int targetID, int unconditional);
BOOL __stdcall TribePriestUnitAIModule::retryableOrder(int orderType);
int __thiscall TribePriestUnitAIModule::canConvert(TribePriestUnitAIModule *this, int targetID); // idb
int __thiscall TribePriestUnitAIModule::canAttackUnit(TribePriestUnitAIModule *this, RGE_Static_Object *unit); // idb
int __thiscall TribePriestUnitAIModule::bestUnitToHeal(TribePriestUnitAIModule *this, int idleHeal, float *allyDistance); // idb
int __thiscall TribePriestUnitAIModule::bestUnitToConvert(TribePriestUnitAIModule *this, float *distance); // idb
// int __userpurge TribePriestUnitAIModule::processNotify@<eax>(TribePriestUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
int __thiscall TribePriestUnitAIModule::processIdle(TribePriestUnitAIModule *this, int doSearch); // idb
int __thiscall TribePriestUnitAIModule::processMisc(TribePriestUnitAIModule *this); // idb
void __thiscall TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(TribeTradeShipUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeTradeShipUnitAIModule *__thiscall TribeTradeShipUnitAIModule::`vector deleting destructor'(TribeTradeShipUnitAIModule *this, unsigned int __flags);
void __thiscall TribeTradeShipUnitAIModule::~TribeTradeShipUnitAIModule(TribeTradeShipUnitAIModule *this); // idb
// int __userpurge TribeTradeShipUnitAIModule::processNotify@<eax>(TribeTradeShipUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
// int __userpurge TribeTradeShipUnitAIModule::processIdle@<eax>(TribeTradeShipUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch);
void __thiscall TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(TribeTransportShipUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeTransportShipUnitAIModule *__thiscall TribeTransportShipUnitAIModule::`scalar deleting destructor'(TribeTransportShipUnitAIModule *this, unsigned int __flags);
void __thiscall TribeTransportShipUnitAIModule::~TribeTransportShipUnitAIModule(TribeTransportShipUnitAIModule *this); // idb
// int __userpurge TribeTransportShipUnitAIModule::processNotify@<eax>(TribeTransportShipUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
// int __userpurge TribeTransportShipUnitAIModule::processIdle@<eax>(TribeTransportShipUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch);
void __thiscall TribeFishingShipUnitAIModule::TribeFishingShipUnitAIModule(TribeFishingShipUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeFishingShipUnitAIModule *__thiscall TribeFishingShipUnitAIModule::`scalar deleting destructor'(TribeFishingShipUnitAIModule *this, unsigned int __flags);
void __thiscall TribeFishingShipUnitAIModule::~TribeFishingShipUnitAIModule(TribeFishingShipUnitAIModule *this); // idb
BOOL __stdcall TribeFishingShipUnitAIModule::importantWhenDead(int objectType);
int __stdcall TribeFishingShipUnitAIModule::convertToLOSResourceType(int oType);
// int __userpurge TribeFishingShipUnitAIModule::processNotify@<eax>(TribeFishingShipUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
// int __userpurge TribeFishingShipUnitAIModule::processIdle@<eax>(TribeFishingShipUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch);
void __thiscall TribeSoldierUnitAIModule::TribeSoldierUnitAIModule(TribeSoldierUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeSoldierUnitAIModule *__thiscall TribeSoldierUnitAIModule::`vector deleting destructor'(TribeSoldierUnitAIModule *this, unsigned int __flags);
void __thiscall TribeSoldierUnitAIModule::~TribeSoldierUnitAIModule(TribeSoldierUnitAIModule *this); // idb
RGE_Static_Object *__stdcall TribeSoldierUnitAIModule::canAttackUnit(RGE_Static_Object *unit);
BOOL __stdcall TribeSoldierUnitAIModule::canAttackUnitAtNeutrality(int oType);
// int __userpurge TribeSoldierUnitAIModule::processNotify@<eax>(TribeSoldierUnitAIModule *this@<ecx>, double a2@<st0>, NotifyEvent *nEvent, unsigned int uTime);
// int __userpurge TribeSoldierUnitAIModule::processIdle@<eax>(TribeSoldierUnitAIModule *this@<ecx>, double a2@<st0>, int doSearch);
void __thiscall TribeArtifactUnitAIModule::TribeArtifactUnitAIModule(TribeArtifactUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeArtifactUnitAIModule *__thiscall TribeArtifactUnitAIModule::`scalar deleting destructor'(TribeArtifactUnitAIModule *this, unsigned int __flags);
void __thiscall TribeArtifactUnitAIModule::~TribeArtifactUnitAIModule(TribeArtifactUnitAIModule *this); // idb
int __thiscall TribeArtifactUnitAIModule::processNotify(TribeArtifactUnitAIModule *this, NotifyEvent *nEvent, unsigned int uTime); // idb
int __thiscall TribeArtifactUnitAIModule::processIdle(TribeArtifactUnitAIModule *this, int doSearch); // idb
int __thiscall TribeArtifactUnitAIModule::processMisc(TribeArtifactUnitAIModule *this); // idb
void __thiscall TribeTowerUnitAIModule::TribeTowerUnitAIModule(TribeTowerUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeTowerUnitAIModule *__thiscall TribeTowerUnitAIModule::`vector deleting destructor'(TribeTowerUnitAIModule *this, unsigned int __flags);
void __thiscall TribeTowerUnitAIModule::~TribeTowerUnitAIModule(TribeTowerUnitAIModule *this); // idb
RGE_Static_Object *__thiscall TribeTowerUnitAIModule::canAttackUnit(TribeTowerUnitAIModule *this, RGE_Static_Object *unit);
BOOL __stdcall TribeTowerUnitAIModule::canAttackUnitAtNeutrality(int oType);
void __thiscall TribeBuildingUnitAIModule::TribeBuildingUnitAIModule(TribeBuildingUnitAIModule *this, RGE_Static_Object *o, int iQS); // idb
TribeBuildingUnitAIModule *__thiscall TribeBuildingUnitAIModule::`scalar deleting destructor'(TribeBuildingUnitAIModule *this, unsigned int __flags);
void __thiscall TribeBuildingUnitAIModule::~TribeBuildingUnitAIModule(TribeBuildingUnitAIModule *this); // idb
int __thiscall TribeBuildingUnitAIModule::processNotify(TribeBuildingUnitAIModule *this, NotifyEvent *nEvent, unsigned int uTime); // idb
int __stdcall TribeBuildingUnitAIModule::processIdle(int doSearch);
