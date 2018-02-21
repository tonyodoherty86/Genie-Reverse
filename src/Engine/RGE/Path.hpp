
/**
 * @file    Engine\RGE\Path.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

struct XYPoint
{
    int x;
    int y;
};

struct XYFloatPoint
{
    float x;
    float y;
};

struct XYZPoint
{
    int x;
    int y;
    int z;
};

class PathingSystem
{
public:

    struct BYTEPoint
    {
        char x;
        char y;
    };

    struct FloatHeap
    {
        char x;
        char y;
        float total;
    };

    struct MGP_FloatHeap
    {
        char x;
        char y;
        unsigned __int16 next;
        int total;
    };

    int xSizeValue, ySizeValue;
    char facetValue[255][255];
    int MGP_costValue[255][255];
    PathingSystem::MGP_FloatHeap MGP_openPaths[65026];
    char obstructionValue[1020][255];
    char miscValue[255][255];
    int numberOpenPathsValue;
    PathingSystem::MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;

    class RGE_Map *mapValue;
    class RGE_Game_World *worldValue;
    class RGE_Moving_Object *currentObject;

    int currentObjectInObMap,
        currentTargetID;

    float *currentTerrainTable;

    float currentXOffset,
          currentYOffset;

    int currentTerrainException1,
        currentTerrainException2;

    /* TODO */
    ManagedArray//<int>
        initialCollidingObjects;

    int startOfPath;
    int checkTerrainOnFirstPass;

    XYPoint initialTile,
            minTarget,
            maxTarget,
            minInitialPosition,
            maxInitialPosition;

    float averageNumWaypoints,
          averagePathLength,
          averagePathIterations;

    int numAttempts,
        numFails,
        numSuccesses,
        numInitialPathsValue,
        numContinuePathsValue,
        numCanPathsValue;

    int MGP_closestTargetDistance;

    float averageClosestTargetDistance,
          averageSuccessTime,
          averageFailTime;

    char CurrentFacetMask;

    int currentUnobstructibleGroupID,
        currentUnobstructiblePlayerID;
    ManagedArray//<int>
        currentUnobstructibles;

    int aiPS;

    PathingSystem(int x, int y, int aiPSInit, RGE_Map *map, RGE_Game_World *world);

    ~PathingSystem();

    int initialize(int x, int y, RGE_Map *map, RGE_Game_World *world);

    void printToFile(char *filename);

    char lookupMisc(int x, int y);
    void setMisc(int x, int y, char v);
    void initMisc(char v);
    void zeroObstructionMap();
    unsigned int obstruction(int x, int y);
    void incrementObstruction(int x, int y);
    void decrementObstruction(int x, int y);

    int findTilePath(int startX, int startY, int goalX, int goalY, RGE_Moving_Object *unit, float actionRange, int cTargetID, int copyPathWhenDone, float *pathLength, int checkPathingIterations, int checkTerrainFirstTime, int checkCollisions, int stepSize, int unobstructiblePlayerID, int unobstructibleGroupID);

    void incrementInitialPaths();
    void incrementContinuePaths();
    void incrementCanPaths();

    int passable(RGE_Moving_Object *obj, float newX, float newY, int checkTerrain);

    int checksum();

    void printState(RGE_Moving_Object *unit);

    int copyPath(int stepSize);
    void copyUnobstructibles(ManagedArray/*<int>*/ *d);
};

struct XYZBYTEPoint
{
    char x;
    char y;
    char z;
};

struct Waypoint
{
    float x;
    float y;
    float z;
    char facetToNextWaypoint;
};

struct Path
{
    unsigned int timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint *pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    Path(int v);

    ~Path();

    Path *operator+(Path *result/*, Path *__$ReturnUdt*/);
    Path *operator=(Path *p);
    int operator==(Path *p);

    int insertAtCurrent(Waypoint *w);
    int insertAtEnd(Waypoint w);
    int contains(Waypoint *w);

    void killPath();
    int maxNumberOfWaypoints();
    int numberOfWaypoints();
    unsigned int timeStamp();
    void setTimeStamp(unsigned int v);
    long double length();

    Waypoint *start();
    Waypoint *goal();
    Waypoint *waypoint(int w);
    Waypoint *currentWaypoint();
    int currentWaypointNumber();
    void setCurrentWaypointNumber(int v);
    Waypoint *nextWaypoint();
    Waypoint *previousWaypoint();
    Waypoint *firstWaypoint();
    Waypoint *lastWaypoint();

    void initToStart();
    void initToEnd();

    int moveToNextWaypoint();
    int moveToLastWaypoint();

    long double distanceToNextWaypoint();
};
