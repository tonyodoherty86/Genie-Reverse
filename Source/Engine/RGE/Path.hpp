#pragma once

/**
 * @file    Engine\RGE\Path.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

struct XYPoint
{
    int x, y;
};

struct XYFloatPoint
{
    float x, y;
};

struct XYZPoint
{
    int x, y, z;
};

struct XYZBYTEPoint
{
    char x, y, z;
};

struct Waypoint
{
    float x, y, z;

    char facetToNextWaypoint;
};

class Path
{
public:

    unsigned int timeStampValue;

    Waypoint startValue,
             goalValue;

    Waypoint *pathValue;

    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    Path(int v);

    ~Path();

    Path *operator+(Path *result);
    Path *operator=(Path *p);
    bool operator==(Path *p);

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
