#pragma once

/**
 * @file    Engine\RGE\PathSystem.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

#include "Path.hpp"
#include <ManagedArray.hpp>

class PathingSystem
{
public:

    struct BYTEPoint
    {
        char x, y;
    };

    struct FloatHeap
    {
        char x, y;

        float total;
    };

    struct MGP_FloatHeap
    {
        char x, y;

        unsigned short next;

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

    ManagedArray /*<int>*/ currentUnobstructibles;

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

    int findTilePath(int startX,
                     int startY,
                     int goalX,
                     int goalY,
                     RGE_Moving_Object *unit,
                     float actionRange,
                     int cTargetID,
                     int copyPathWhenDone,
                     float *pathLength,
                     int checkPathingIterations,
                     int checkTerrainFirstTime,
                     int checkCollisions,
                     int stepSize,
                     int unobstructiblePlayerID,
                     int unobstructibleGroupID);

    void incrementInitialPaths();
    void incrementContinuePaths();
    void incrementCanPaths();

    int passable(RGE_Moving_Object *obj, float newX, float newY, int checkTerrain);

    int checksum();

    void printState(RGE_Moving_Object *unit);

    int copyPath(int stepSize);
    void copyUnobstructibles(ManagedArray/*<int>*/ *d);
};
