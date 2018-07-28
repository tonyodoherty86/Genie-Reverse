
/**
 * @file    Engine\TRB\AiUnitModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

class TribeHuntedAnimalUnitAIModule : public UnitAIModule
{
public:

    TribeHuntedAnimalUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeHuntedAnimalUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribePreditorUnitAIModule : public UnitAIModule
{
public:

    TribePreditorUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribePreditorUnitAIModule();

    int canAttackUnitAtNeutrality(int oType);
    int processNotify(NotifyEvent *nEvent, time_t uTime);
};

class TribeElephantUnitAIModule : public UnitAIModule
{
public:

    TribeElephantUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeElephantUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribeLionUnitAIModule : public UnitAIModule
{
public:

    TribeLionUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeLionUnitAIModule();

    int canAttackUnitAtNeutrality(int oType);
    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribeRangedUnitAIModule : public UnitAIModule
{
public:

    TribeRangedUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeRangedUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
};

class TribeRangedUnitAIModule2 : public UnitAIModule
{
public:

    TribeRangedUnitAIModule2(RGE_Static_Object *o, int iQS);

    ~TribeRangedUnitAIModule2();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
};

class TribeCivilianUnitAIModule : public UnitAIModule
{
public:

    TribeCivilianUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeCivilianUnitAIModule();

    bool importantWhenDead(int objectType);
    RGE_Static_Object *attackObject(int targetID, int unconditional);
    RGE_Static_Object *canAttackUnit(RGE_Static_Object *unit);
    int canAttackUnitAtNeutrality(int oType);
    bool retryableOrder(int orderType);
    int convertToLOSResourceType(int oType);
    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
    int processMisc();
};

class TribePriestUnitAIModule : public UnitAIModule
{
public:

    TribePriestUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribePriestUnitAIModule();

    int attackObject(int targetID, int unconditional);
    bool retryableOrder(int orderType);
    int canConvert(int targetID);
    int canAttackUnit(RGE_Static_Object *unit);
    int bestUnitToHeal(int idleHeal, float *allyDistance);
    int bestUnitToConvert(float *distance);
    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
    int processMisc();
};

class TribeTradeShipUnitAIModule : public UnitAIModule
{
public:

    TribeTradeShipUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeTradeShipUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribeTransportShipUnitAIModule : public UnitAIModule
{
public:

    TribeTransportShipUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeTransportShipUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribeFishingShipUnitAIModule : public UnitAIModule
{
public:

    TribeFishingShipUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeFishingShipUnitAIModule();

    bool importantWhenDead(int objectType);
    int convertToLOSResourceType(int oType);
    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribeSoldierUnitAIModule : public UnitAIModule
{
public:

    TribeSoldierUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeSoldierUnitAIModule();

    RGE_Static_Object *canAttackUnit(RGE_Static_Object *unit);
    bool canAttackUnitAtNeutrality(int oType);
    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};

class TribeArtifactUnitAIModule : public UnitAIModule
{
public:

    TribeArtifactUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeArtifactUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
    int processMisc();
};

class TribeTowerUnitAIModule : public UnitAIModule
{
public:

    TribeTowerUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeTowerUnitAIModule();

    RGE_Static_Object *canAttackUnit(RGE_Static_Object *unit);
    bool canAttackUnitAtNeutrality(int oType);
};

class TribeBuildingUnitAIModule : public UnitAIModule
{
public:

    TribeBuildingUnitAIModule(RGE_Static_Object *o, int iQS);

    ~TribeBuildingUnitAIModule();

    int processNotify(NotifyEvent *nEvent, time_t uTime);
    int processIdle(int doSearch);
};
