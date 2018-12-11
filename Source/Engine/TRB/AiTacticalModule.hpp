#pragma once

#include "AiConstructionModule.hpp"

#include <RGE/AiResourceItem.hpp>
#include <RGE/AiTacticalModule.hpp>
#include <RGE/Path.hpp>
#include <ManagedArray.hpp>
#include <ctime>

/**
 * @file    Engine\TRB\AiTacticalModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TribeTacticalAIModule;
class TribeMainDecisionAIModule;
class InfluenceMap;

class TacticalAIGroup
{
public:

    TacticalAIGroup *next,
                    *prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int unitsValue[40];
    int unitsOriginalHitPointsValue[40];
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;
    Waypoint locationValue;
    int actionValue;
    int targetValue;
    int targetTypeValue;

    Waypoint targetLocationValue,
             gatherLocationValue,
             retreatLocationValue;

    int priorityValue;
    int waitCodeValue;
    int assistGroupIDValue;
    int assistGroupTypeValue;
    unsigned int consecutiveIdleUnitCountValue;
    int playNumberValue;
    char numberAttackWaypointsValue;
    char currentAttackWaypointValue;
    Waypoint attackWaypoints[15];
    char consecutiveGatherAttemptsValue;
    int numberObjectsToDestroyValue;
    int objectsToDestroyValue[20];
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;

    time_t lastAttackRoundupTime,
           lastAddedUnitTimeValue;

    TacticalAIGroup();

    ~TacticalAIGroup();

    int load(int infile);

    int save(int outfile);

    int id();
    void setID(int v);
    int inUse();
    void setInUse(int v);
    int type();
    void setType(int v);
    int subType();
    void setSubType(int v);
    int addUnit(int id, TribeMainDecisionAIModule *md);
    int removeUnit(int id, TribeMainDecisionAIModule *md);
    int removeUnitByIndex(int index, TribeMainDecisionAIModule *md);
    void removeUnits(TribeMainDecisionAIModule *md);
    int removeExtraUnits(TribeMainDecisionAIModule *md);
    int removeUnboardedUnits(TribeTacticalAIModule *t, TribeMainDecisionAIModule *md);
    int containsUnit(int id);
    int numberUnits();
    int unit(int i);
    int unitOriginalHitPoints(int i);
    int desiredNumberUnits();
    void setDesiredNumberUnits(int v);
    int commander();
    void setSpecificCommander(int id, TribeMainDecisionAIModule *md);
    int currentHitPoints(TribeMainDecisionAIModule *md);
    int originalHitPoints();
    void setOriginalHitPoints(int v);
    int originalUnitNumber();
    void setOriginalUnitNumber(int v);
    Waypoint *location();
    void setLocation(float x, float y, float z);
    int action();
    void setAction(int v);
    int target();
    void setTarget(int v);
    int targetType();
    void setTargetType(int v);
    Waypoint *targetLocation();
    void setAllLocations(float x, float y, float z);
    void setTargetLocation(float x, float y, float z);
    Waypoint *gatherLocation();
    void setGatherLocation(float x, float y, float z);
    Waypoint *retreatLocation();
    void setRetreatLocation(float x, float y, float z);
    int priority();
    void setPriority(int v);
    int waitCode();
    void setWaitCode(int v);
    int assistGroupID();
    void setAssistGroupID(int v);
    int assistGroupType();
    void setAssistGroupType(int v);
    int task(TribeTacticalAIModule *t, TribeMainDecisionAIModule *md, int taskID, int resetOriginal, int overrideCurrentAction);
    int isGathered(TribeTacticalAIModule *t, TribeMainDecisionAIModule *md);
    int isTightGathered(TribeTacticalAIModule *t, TribeMainDecisionAIModule *md);
    int allUnitsIdle(TribeMainDecisionAIModule *md, int countAttackAsIdle);
    unsigned int consecutiveIdleUnitCount();
    void setConsecutiveIdleUnitCount(unsigned int v);
    void incrementConsecutiveIdleUnitCount(unsigned int v);
    char numberAttackWaypoints();
    char currentAttackWaypoint();
    void setCurrentAttackWaypoint(char v);
    void addAttackWaypoint(float x, float y);
    Waypoint *attackWaypoint(char v);
    int firstIdleUnit(TribeMainDecisionAIModule *md);
    int objectToDestroy(int n);
    int addObjectToDestroy(int id);
};

struct UnitData
{
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    time_t lastTaskTime;
};

struct AttackState
{
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    char phase;
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};

class TribeTacticalAIModule : public TacticalAIModule
{
public:

    TribeMainDecisionAIModule *md;

    ManagedArray/*<int>*/ civilians;
    ManagedArray/*<int>*/ civilianExplorers;
    ManagedArray/*<int>*/ soldiers;
    ManagedArray/*<int>*/ ungroupedSoldiers;
    ManagedArray/*<int>*/ boats;
    ManagedArray/*<int>*/ warBoats;
    ManagedArray/*<int>*/ fishingBoats;
    ManagedArray/*<int>*/ tradeBoats;
    ManagedArray/*<int>*/ transportBoats;
    ManagedArray/*<int>*/ artifacts;

    int sn[226];
    UnitData gatherers[50];
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;

    time_t lastGroupAttackTime,
           lastGroupRebalanceTime,
           lastAttackResponseTime,
           lastBoatAttackResponseTime,
           lastScalingUpdateValue;

    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;

    ManagedArray/*<int>*/ playersToAttack;
    ManagedArray/*<int>*/ playersToDefend;
    ManagedArray/*<int>*/ workingArea;
    ManagedArray/*<int>*/ unitsTaskedThisUpdate;

    int actualGathererDistribution[4];
    int desiredGathererDistribution[4];
    int neededResourceValue[4];
    int resourceDifferenceValue[4];
    ResourceItem neededResources;
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int numberStoragePitsBuilt[4];
    int numberGranariesBuilt[4];
    int wonderInProgressValue;
    int wonderBuiltValue;
    PlacementState placementStateValue;
    int nextCivilianToTaskValue;
    int nextIdleSoldierGroupToTaskValue;
    int nextActiveSoldierGroupToTaskValue;
    int builtFirstStoragePit;
    int builtFirstGranary;

    unsigned int lastBuildTime;
    unsigned int lastAttackResponseBuildInsertionTime;
    unsigned int lastCoopTributeDemandTime;
    unsigned int lastCoopTributeGiftTime;
    unsigned int lastCoopAttackDemandTime;

    int zoomingToNextAge;

    unsigned int lastUngroupedSoldierTaskTime;

    AttackState attackStateValue;

    int hitsByPlayer[RGE_PLAYERS_COUNT];

    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int updateAreaAverageCount;
    int updateAreaAverageTotal;

    TribeTacticalAIModule(void *pW, int pID);

    TribeTacticalAIModule(int pID, int infile);

    ~TribeTacticalAIModule();

    char *updateAreaName();

    bool update(int timeLimit);

    void setMainDecisionAI(TribeMainDecisionAIModule *m);

    int save(int outfile);

    void logGroupDebug(int gID, char *textIn, ...);
    int doSomething();
    int clearArea(int id, float minX, float minY, float maxX, float maxY);
    void addObject(RGE_Static_Object *bo);
    void removeObject(int id);
    void evaluateCivilianDistribution();
    int taskCivilians(unsigned int startTime, unsigned int availableTime);
    void taskIdleSoldiers(unsigned int startTime, unsigned int availableTime);
    void taskActiveSoldiers(unsigned int startTime, unsigned int availableTime);
    void playTaskSoldiers(unsigned int startTime, unsigned int availableTime);
    void taskUngroupedSoldiers();
    void taskBoats();
    void evaluateOpenTasks();
    void evaluateBuildListInsertions();
    int numberCivilians();
    int numberCivilianExplorers();
    int numberGatherers();
    int desiredNumberCivilianExplorers();
    int desiredNumberGatherers();
    int numberSoldiers();
    int numberSoldierExplorers();
    int numberBoats();
    int neededResource(int n);
    int neededResourceAmount(int n);
    void detask(int uid);
    int strategicNumber(int sNum);
    void setStrategicNumber(int sNum, int v);
    void notify(int callerID, int recipientID, int mType, int p1, int p2, int p3, int a8, int a9);
    int numberIdleSoldiers();
    int numberSoldiersWithPriority(int priority, int flag, int zeroWorkingArea);
    int numberWarshipsWithPriority(int priority, int flag);
    int idleSoldier();
    int idleCivilian(int checkGroup);
    int idleCivilian(int checkGroup, XYPoint *point, int closestToPoint);
    int civilian(XYPoint *point, int closestToPoint, int a1, int a2, int a3, int useFarmers);
    int unit(int action, int target, int targetType);
    int busyWithAction(int id, int a);
    void displayCivilianDistribution();
    void updateNeededResources();
    void updateGathererDistribution();
    int stopUnit(int uID, int priority);
    int moveUnit(int uID, float x, float y, int priority);
    int groupGatherUnit(int uID, int tID, float x, float y, float z, float range, int priority);
    int highLevelTaskExplorer(int unitID, int civilian);
    RGE_Static_Object *highLevelTaskGatherer(int unitID, unsigned int startTime);
    int taskPlay(int commander, int *groupUnits, int groupCount, int target, int play, Waypoint *path, int pathLength);
    int taskBuilder(int builder, BuildItem *newBuilding, ConstructionItem *ci, unsigned int startTime);
    RGE_Static_Object *taskBuilder(int builder, RGE_Static_Object *building);
    RGE_Static_Object *taskRepairer(int builder, RGE_Static_Object *building);
    RGE_Static_Object *taskGatherer(int id, int resourceType, int limitedTaskLimit, unsigned int startTime, int *triedTasking);
    int taskExplorer(int eID, int civilian);
    int taskExplorer(int eID, float x, float y);
    int taskExplorer(int eID, float x, float y, int civilian);
    int taskFollower(int uID, int tID, float range, int priority);
    int taskDefender(int uID, int tID, float range, int priority);
    int taskWaterExplorer(int explorer);
    int taskWaterTrader(int unitID, int targetID);
    int taskWaterFisher(int unitID, int targetID, float x, float y);

    int taskAttacker(
        int soldierID,
        float xLocation,
        float yLocation,
        int targetID,
        int targetOwner,
        Waypoint *path,
        int pathLength,
        int commanderID,
        int idleAttackRoundup);

    int taskDefender(int defender, int targetID);
    int taskDefender(int defender, float x, float y);
    int taskTrain(BuildItem *trainItem);
    int taskResearch(BuildItem *researchItem);
    int taskToEnter(int unitID, int targetID);
    int taskTransporter(int unitID, float x, float y);
    void removeFromTaskLists(int gID);
    int calculatePriority(float distance);
    void setupSoldierGroups();
    void fillSoldierGroups();
    int numberUngroupedSoldiers();
    int numberExtraGroupedSoldiers();
    int numberUngroupedArtifacts();
    void displaySoldierGroups();
    void setupBoatGroups();
    void fillBoatGroups();
    int numberUngroupedWarBoats();
    int numberExtraGroupedWarBoats();
    int numberUngroupedFishingBoats();
    int numberUngroupedTradeBoats();
    int numberUngroupedTransportBoats();
    void displayBoatGroups();
    TacticalAIGroup *createGroup(int initID);
    int removeGroup(int gID);
    int removeAllGroups(int tID);
    TacticalAIGroup *group(int gID, int type, int action, int targetID);
    TacticalAIGroup *bestGroup(int type, int action, int distance, XYPoint *point, int zone);
    TacticalAIGroup *readyAndIdleGroup(int type, int distance, XYPoint *point);
    TacticalAIGroup *addToGroup(int uID, int gID);
    TacticalAIGroup *removeFromGroup(int uID, int gID);
    TacticalAIGroup *removeFromGroup(int uID);
    TacticalAIGroup *groupUnitIsIn(int uID);
    int numberGroups(int type, int action);
    int numberUnitsInGroups(int type);
    int numberItemsToAttack();
    int itemToCapture();
    int itemToBringToArea();
    int numberItemsToDefend();
    int attackLimiterTime(int snType);
    void resetAttackSeparationTime();
    RGE_Static_Object *setGatherLocation(TacticalAIGroup *g);
    RGE_Static_Object *setAllGroupLocations(TacticalAIGroup *g);
    void setGroupInfluences(InfluenceMap *iMap);
    int selectBestCommander(TacticalAIGroup *temp);
    int selectBestCommander(ManagedArray/*<int>*/ *temp);
    bool dealWithGAIAAttacker(RGE_Static_Object *attacker, RGE_Static_Object *victim, signed int a4, signed int a5);
    void addWaypoint(int recipient, int x, char y);
    RGE_Static_Object *importantGroupLeader(int cID);
    void enableAttack(int type);
    RGE_Static_Object *unexploredArea(int uID, XYPoint *rPoint);
    UnitData *gatherer(int id);
    UnitData *addGatherer(int id);
    int removeGatherer(int id);
    int isGatherer(int id);
    int requiredGatherAmount(int rType);
    void trackUnitGather(int unitID, int attributeID, int amount);
    int deleteUnit(int unitID);
    int numberAvailableStoragePits(int *numStoragePits, int *numUnbuiltStoragePits, int rType);
    int numberAvailableGranaries(int *numGranaries, int *numUnbuiltGranaries);
    int initialExplorationSatisfied();
    void checkForBuildInsertion(int type, int number, int position);
    int isFarmer(RGE_Static_Object *temp);
    int numberFarmers();
    int inAge(int age);
    void stuffAvoidancePath(TacticalAIGroup *group, Path *path);
    void checkForAttackResponseBuildInsertions(int playerID);
    void checkForCoopTributeDemand();
    void checkForCoopTributeGift();
    void checkForASAPAgeResearch();
    void checkForCoopAttack(int playerToAttack, int x, int y);
    int processCoopAttack(int caller, int playerToAttack, int x, int y);
    int resourceDifference(int n);
    int actualGathererCount(int n);
    int actualGathererCountByRealResourceID(int n);
    int desiredGathererCount(int n);
    void taskElephantGatherers(int mainHunterID, int numberToTask, int targetID);
    void checkTradeBoats();
    int numberGatherersWithTarget(int targetID);
    void checkStaleAttackGroups();
    int numberWaterExplorers();
    void saveTheTown(int idToKill, int a3, signed int a4, char *a5);
};
