
/**
 * @file    Engine\RGE\AiUnitModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

struct OrderEvent;
struct NotifyEvent;

class UnitAIModule
{
public:

    RGE_Static_Object *objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    OrderEvent *orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    NotifyEvent *notifyQueueValue;
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXValue;
    float currentTargetYValue;
    float currentTargetZValue;
    float desiredTargetDistanceValue;
    int defendTargetValue;
    int lastOrderValue;
    int lastActionValue;
    int lastTargetValue;
    int lastTargetTypeValue;
    ManagedArray/*<int>*/ attackingUnitsValue;
    Waypoint waypointQueue[8];
    int waypointQueueSizeValue;
    unsigned int lastUpdateTimeValue;
    unsigned int idleTimerValue;
    unsigned int adjustedIdleTimeoutValue;
    unsigned int idleTimeoutValue;
    unsigned int secondaryTimerValue;
    unsigned int lookAroundTimerValue;
    unsigned int lookAroundTimeoutValue;
    Waypoint lastWorldPositionValue;
    float defenseBufferValue;
    int *importantObjects;
    int numberImportantObjects;
    AIPlayStatus *playStatus;
    char stopAfterTargetKilledValue;

    UnitAIModule(RGE_Static_Object *o, int iQS);

    ~UnitAIModule();

    void save(int outfile);

    void load(int infile);

    RGE_Player *owner();
    RGE_Static_Object *object();
    int objectID();
    int objectCategory();
    int mood();
    unsigned int lastUpdateTime();
    unsigned int idleTimer();
    unsigned int idleTimeout();
    unsigned int secondaryTimer();
    double defenseBuffer();
    int canConvert(int a2);
    void setDefenseBuffer(float v);
    int orderQueueSize();
    OrderEvent *orderQueueElement(int v);
    void purgeOrderQueue();
    int currentOrder();
    void setCurrentOrder(int v);
    int currentOrderPriority();
    void setCurrentOrderPriority(int v);
    int currentAction();
    void setCurrentAction(int v);
    int currentTarget();
    int currentTargetType();
    double currentTargetX();
    double currentTargetY();
    double currentTargetZ();
    int lastAction();
    int lastOrder();
    int lastTarget();
    int lastTargetType();
    double desiredTargetDistance();
    int attackingUnitID(int v);
    int numberAttackingUnits();
    int update(unsigned int uTime);
    void updateGroup(unsigned int uTime);
    int selectNewPlayPhase(int newPhase, int pickup);
    int order(int issuer, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority);
    void *notify(int callerID, int recipientID, int mType, int p1, int p2, int p3);
    int notifyCommander(NotifyEvent *nEvent);
    int notifyCommander(int callerID, int recipientID, int mType, int p1, int p2, int p3);
    void search();
    static bool importantWhenDead(int objectType);
    int retryableOrder(int orderType);
    int actionRequiresLiveTarget(int aID);
    int bestUnitToAttack(int allowWallAttacks, int quickCheck, float *threatSlot);
    int mostDangerousEnemy(float *threatSlot);
    int weakestEnemy(float *threatSlot);
    int closestAttacker(float *threatSlot);
    int closestObject(int objectGroup, int desiredRelation, int objectState, int objectType, int *threatSlot);
    int closestResourceObject(int resourceType, int *dSlot);
    int closestUndiscoveredTile(int *tX, int *tY, int checkWaypointQueue);
    static Waypoint *waypoint(int i);
    int waypointQueueSize();
    int addToWaypointQueue(int x, int y);
    int inWaypointQueue(int x, int y);
    void clearWaypointQueue();
    int canAttackUnit(RGE_Static_Object *target);
    int canAttackUnitAtNeutrality(int uID);
    int stopObject(int checkOrderAndAction);
    int attackObject(int targetID, int unconditional);
    int attackRoundupObject(int targetID);
    int huntObject(int targetID, int unconditional);
    int convertObject(int targetID, int unconditional);
    int healObject(int targetID, int unconditional);
    int gatherObject(int targetID, int unconditional);
    int repairObject(int targetID, int unconditional);
    int buildObject(int targetID, int unconditional);
    int tradeWithObject(int targetID, int unconditional);
    int explore(int tX, int tY, int unconditional);
    int enterObject(int targetID, int unconditional);
    int transportObject(float tX, float tY, float tZ, int unconditional);
    int unload(int unconditional, float x, float y);
    int moveTo(int targetID, int unconditional);
    int moveTo(int targetID, float minimumRange, int unconditional);
    int moveTo(float targetX, float targetY, float targetZ, float range, int unconditional);
    int evasiveMoveTo(float targetX, float targetY, float targetZ, int unconditional);
    int intelligentEvasiveMoveTo(float targetX, float targetY, float targetZ, int goCloser, int unconditional);
    int runAwayFromAttackers(int unconditional);
    RGE_Static_Object *followObject(int targetID, float desiredDistance, int unconditional);
    RGE_Static_Object *defendObject(int targetID, float desiredDistance, int unconditional);
    int defendPosition(float targetX, float targetY, float desiredDistance, int unconditional);
    int seekAndDestroy(int targetID, int tX, int tY, int unconditional);
    int exploreAndDestroy(int tX, int tY, int unconditional);
    void removeCurrentTarget();
    void setCurrentTarget(int o, float x, float y, float z);
    void setCurrentTarget(int o, int t, float x, float y, float z);
    int importantObject(int unitType);
    int isEnemyOwner(int oID);
    int isAllyOwner(int oID);
    int isNeutralOwner(int oID);
    char visibleStatus(RGE_Visible_Map *vMap, int x, int y);
    void setAdjustedIdleTimeout();
    void setTaskedByPlayer();
    static int convertToLOSResourceType(int type);
    void setPlayStatus(AIPlayStatus *ps);
    void lookAround();
    int hasOrderOnQueue(int orderNumber);
    void askForHelp(int unitToAttack, int a3, int a4, int a5);

    int processOrder(OrderEvent *oEvent, int orderNumber);
    int processNotify(NotifyEvent *nEvent, unsigned int uTime, int tileY, int a6, void *a7);
    void processGroupNotify(NotifyEvent *nEvent);
    int processIdle(int doSearch);
    int processMisc();
    int processRetryableOrder();

    void *addToOrderQueue(OrderEvent *oEvent, int inFront);
    void *addToOrderQueue(int issuer, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int inFront, int priority);
    void *addToNotifyQueue(NotifyEvent *nEvent);
    void *addToNotifyQueue(int callerID, int recipientID, int mType, int p1, int p2, int p3);

    void purgeNotifyQueue(unsigned int uTime);

    RGE_Static_Object *lookupObject(int id);

    void logDebug(char *textIn, ...);
};

struct OrderEvent
{
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;

    float targetX,
          targetY,
          targetZ;

    float range;
};

struct NotifyEvent
{
    int caller;
    int recipient;
    int mType;

    int p1,
        p2,
        p3;
};
