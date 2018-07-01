
/**
 * @file    Engine\TRB\AiInformationModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

struct QuadrantLog
{
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

class TribeInformationAIModule : public InformationAIModule
{
public:

    ManagedArray/*<int>*/ farmsTaskedThisUpdate;

    TribeMainDecisionAIModule *md;

    int mapXSizeValue,
        mapYSizeValue;

    int lastUpdateRowValue;

    int maxImportantObjectMemory;

    struct ObjectMemory *importantObjectMemory;

    ManagedArray/*<int>*/ importantObjects;
    ManagedArray/*<int>*/ importantUnits;
    ManagedArray/*<int>*/ importantMiscs;
    ManagedArray/*<int>*/ itemsToDefend;
    InfluenceMap pathMap;
    ManagedArray/*<int>*/ playerObjects;
    ManagedArray/*<int>*/ playerBuildings;

    XYPoint lastWallPosition,
            lastWallPosition2;

    int numberGatesValue;
    XYPoint minGatePosition[4],
            maxGatePosition[4];
    int maxBuildingLots;
    struct BuildingLot *buildingLots;
    int maxAttackMemories;
    struct AttackMemory *attackMemories;
    int saveLearnInformationValue;
    char learnFileName[256];
    char fullyExploredZoneValue[255];
    QuadrantLog quadrantLog[4][4];
    int **resourceTypesValue;
    int *numberResourceTypesValue;
    struct ResourceMemory *resources[4];
    int numResources[4];
    int maxResources[4];
    int dropsitesByAge[4][4];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];
    int numberFoundForestTilesValue;
    int playHistory[16000];
    int unitHistory[11];
    char unitHistoryFilename[256];

    TribeInformationAIModule(void *pW, int pID);

    TribeInformationAIModule(int pID, int infile);

    ~TribeInformationAIModule();

    int initialize();

    bool update(int timeLimit);

    void setMainDecisionAI(TribeMainDecisionAIModule *m);

    int save(int outfile);

    void blotExploredMap(int minX, int minY, int maxX, int maxY);
    RGE_Static_Object *closestUnexploredTile(int uID, float cX, float cY, float *uX, float *uY);
    int fullyExploredZone(int id);
    void setFullyExploredZone(int id, int v);
    int tileUncovered(int x, int y);
    void setTileExplored(int x, int y);
    int ownerOfGameID(int id);
    int gameIDOfResourceObject(int rType, int gathererID, float *roXPos, float *roYPos, int *dropsiteID, int *exclusions, int numExclusions);
    int gameIDsOfObjectType(int oType, int **objects, int **owners, int ownerNumber);
    int gameIDsOwnedBy(int oType, int **objects, int ownerNumber);
    int numberGameIDsOwnedBy(int oType, int ownerNumber);
    void placeDock(BuildItem *bi, float cX, float cY, int centerType, int edgeType);
    int numberDocksInZone(int zone, RGE_Zone_Map *zoneMap);
    int closestDockDistance(int x, int y);
    int hasAdjacentTileType(int x, int y, int aType);
    int mapXSize();
    int mapYSize();
    void addEnemyInfluences(int ownerID, int targetID);
    void addPriorAttackInfluences(int ownerID, int targetID);
    ObjectMemory *objectMemory(int id);
    ObjectMemory *addObjectMemory(RGE_Static_Object *oObj);
    ObjectMemory *addObjectMemory(int id, short type, short group, char x, char y, char z, char ownerID, short hitPoints, int attackAttempts, char kills, float damageCapability, float rateOfFire, float weaponRange, RGE_Static_Object *object);
    int addImportantObject(RGE_Static_Object *oObj, int addedFromAlliedCP);
    int addImportantObject(int oID);
    int importantObject(int oType);
    bool importantUnit(int oType);
    bool importantResource(int oType);
    bool importantMisc(int oType);
    bool isBuilding(RGE_Static_Object *obj);
    int isUnitBuilding(RGE_Static_Object *obj);
    bool isBoat(RGE_Static_Object *obj);
    bool isWall(RGE_Static_Object *obj);
    bool isTower(RGE_Static_Object *obj);
    RGE_Static_Object *isBoatAccessible(RGE_Static_Object *unit, int target);
    int isLandAccessible(RGE_Static_Object *unit, int target);
    int influenceCanPlaceStructure(BuildItem *bi);
    void influencePlaceStructure(BuildItem *bi, int builderID, int alternateType, float alternateSize, char *alternateName, int alternateMinD, int alternateMaxD, int alternateX, int alternateY, PlacementState *placementState, unsigned int startTime);
    void addObject(RGE_Static_Object *obj);
    void removeObject(int objID);
    ObjectMemory *objectToAttackWithPlay(int ownerID, int *soldiers, int numSoldiers, int *playToRun, int *playUnits, int *numberPlayUnits, int *playCommander);
    ObjectMemory *objectToAttack(int ownerID, int ignoreSiegeTargets, int ignoreBoatTargets, int unitID, int *validAttack);
    ObjectMemory *objectToAttackByGroup(int ownerID, TacticalAIGroup *group, AttackState *attackState, unsigned int startTime, int a7, TacticalAIGroup *a8);
    ObjectMemory *objectToAttackByGroup2(int ownerID, int *soldiers, int numberSoldiers);
    ObjectMemory *objectToDefend(int unitID);
    ObjectMemory *higherPriorityObjectToDefend(int unitID, int oType, int oGroup);
    int defendPriority(int oType, int oGroup);
    int checkDefend(RGE_Static_Object *o);
    int numberItemsToDefend();
    ObjectMemory *objectToTradeWith(int unitID);
    int findGatherPosition(XYPoint *centerPoint, int num, int landTroops, int desiredDistance, int maximumDistanceVariation, RGE_Static_Object *testUnit, XYPoint *rPoint);
    void setupInfluenceMap(int placementType, int buildingType, XYPoint *centerPoint, XYPoint *minArea, XYPoint *maxArea);
    int mapBound(XYPoint *p);
    int groupInfluenceDimension(int num);
    ObjectMemory *findObjectMemoryLimits(ObjectMemory *result, int __$ReturnUdt, int ownerID, int *unitID, int *numberNonSiegeTargets);
    int isNextTo(XYPoint *one, XYPoint *two, int countDiagonal);
    int facetTo(XYPoint *one, XYPoint *two);
    int placementCode(int typeID);
    void storeLot(int typeID, char x, char y, char status);
    void removeLot(int typeID, char x, char y, char newStatus);
    BuildingLot *availableLot(int typeID);
    int invalidLot(int typeID, char x, char y);
    int undesirableLot(int typeID, char x, char y, int overlapSize);
    void setupWalls(int x, int y, int minDistance, int maxDistance, int pattern, int numberGates, int gateSize, int townWalls);
    int insideGate(int numGates, int x, int y);
    int storeAttackMemory(char type, char x1, char y1, char attackingOwner, char targetOwner, short kills, char success, unsigned int timeStamp, int play);
    int storeAttackMemory(char type, char x1, char y1, char x2, char y2, char attackingOwner, char targetOwner, short kills, char success, unsigned int timeStamp, int play);
    void removeAttackMemory(int id);
    AttackMemory *attackMemory(int id);
    void loadLearnInfo(char *name);
    void setSaveLearnInformation(int v);
    int unexploredPlayerLocation(int uID, XYPoint *rPoint);
    int numberUnitsWithinXTiles(int playerID, int x, int y, int numTiles);
    int withinXTilesOfAttackOnPlayer(RGE_Static_Object *obj, int numTiles, int victimID);
    int withinXTilesOfEnemyTowncenter(RGE_Static_Object *obj, int distance);
    int withinXTilesOfObject(RGE_Static_Object *obj, int distance, int oT1, int oT2, int oT3, int oT4);
    RGE_Static_Object *findStagingPoint(XYPoint startPoint, XYPoint *rPoint, int useTransport, int landTerrainRequired, int targetID, int stageDistance, int unitID);
    int setupLOSMap(int ownerID, int x, int y);
    int setupAttackMap(int ownerID, int x, int y);
    void addResourceType(int r, int t);
    int resourceType(int r, int t);
    ResourceMemory *addResourceObject(RGE_Static_Object *obj);
    double findClosestDropsite(RGE_Static_Object *resourceObj, int countTownCenter, int *dropsiteID);
    RGE_Static_Object *findClosestReturnDropsite(RGE_Static_Object *unitObj);
    void updateAllResourceDropsites();
    void updateResourceDropsites(int rType);
    int setResourceObjectValid(int rType, int id, int newValid);
    int numberStoragePits();
    int numberGranaries();
    double amountForageBushesInXTiles(int x, int y, int distance);
    double amountResourceTypesInXTiles(int type, int x, int y, int distance);
    double damagePerSecond(int id, int x, int y);
    int costToLoseUnit(int id);
    int benefitToKillUnit(int id);
    int inRangeOfUnits(int playerID, int x, int y, int useJustRange);
    ObjectMemory *wonderToAttack(int playerID);
    ObjectMemory *ruinToCapture(int playerID);
    ObjectMemory *artifactToCapture(int playerID);
    int resourceTypeToPlaceDropsiteBy(int dropsiteType);
    int dropsitesWithinRequiredDistance(int *numDS, int rType, int maxDistance);
    int numberAvailableStoragePits(int rType);
    int numberAvailableGranaries();
    void lookAtMap();
    double damageInflictedPerSecond(TacticalAIGroup *group, RGE_Static_Object *obj);
    double damageInflictedPerSecond(int *group, int groupSize, RGE_Static_Object *obj);
    double timeToBeKilled(TacticalAIGroup *group, RGE_Static_Object *obj);
    double timeToBeKilled(int *group, int groupSize, RGE_Static_Object *obj);
    int closestDropsiteResID(int rType);
    int calculatePlayVariation(int playID);
    int convertUnitToIntType(RGE_Static_Object *obj);
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int *rVal1, int *rVal2);
    void unitsThatAreLeastBuilt(int *rVal1, int *rVal2);
    int acceptablePotentialDropsiteArea(int x, int y);
    int percentTilesExploredInPositionQuadrant(int x, int y);
};

struct ObjectMemory
{
    int id;
    short type;
    short group;
    char x, y, z;
    char owner;
    short hitPoints;
    int attackAttempts;
    char kills;
    float damageCapability;
    float rateOfFire;
    float range;
};

struct BuildingLot
{
    int typeID;
    char status;
    char x, y;
};

struct AttackMemory
{
    int id;
    char type;
    char minX;
    char minY;
    char maxX;
    char maxY;
    char attackingOwner;
    char targetOwner;
    short kills;
    char success;
    unsigned int timeStamp;
    int play;
};

struct ResourceMemory
{
    int id;
    char x, y;
    char gatherAttempts;
    int gatherValue;
    char valid;
    char gone;
    char dropDistance;
    char resourceType;
    int dropsiteID;
};
