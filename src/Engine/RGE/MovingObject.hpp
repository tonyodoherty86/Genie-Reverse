
/**
 * @file    Engine\RGE\MovingObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

#ifndef RGE_MOVING_OBJECT_TYPE
    #define RGE_MOVING_OBJECT_TYPE 30
#endif

class RGE_Moving_Object : public RGE_Animated_Object
{
public:

    char type = RGE_MOVING_OBJECT_TYPE;

    float trail_remainder;

    float velocity_x,
          velocity_y,
          velocity_z;

    float angle;

    float turn_towards_time;

    Path pathValue,
         exceptionPathValue;

    Waypoint startValue,
             goalValue;

    float turnTimer;

    float collisionAvoidanceDistance;

    float actionRange;

    int targetIDValue;

    float targetRadiusX,
          targetRadiusY;

    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;

    char storePathInExceptionPath;
    char waitingToMoveValue;
    char numberWaitDelays;

    XYPoint minInitialPointValue,
            maxInitialPointValue;

    XYZBYTEPoint *userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    char finalUserDefinedWaypoint;
    float closestDistanceToWaypoint;

    char lastFacet,
         lastFacet2;

    enum PathResult
    {
        PathFound           = 0x00,
        NoPathFound         = 0x01,
        WaitingOnPathingCap = 0x02,
    };

    RGE_Moving_Object(
        RGE_Master_Moving_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z,
        bool do_setup);

    RGE_Moving_Object(
        int infile,
        RGE_Game_World *gworld,
        bool do_setup);

    ~RGE_Moving_Object();

    void recycle_in_to_game(
        RGE_Master_Static_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z);

    bool setup(
        RGE_Master_Moving_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z);

    bool setup(
        int infile,
        RGE_Game_World *gworld);

    void save(
        int outfile);

    void new_sprite(RGE_Sprite *nsprite);

    RGE_Static_Object *spawn_death_obj();

    void transform(RGE_Master_Static_Object *obj);

    bool is_moving();
    void stop_moving();
    double angle_to_object(RGE_Static_Object *to_object, float x, float y);
    char turn_towards(RGE_Static_Object *obj, float x, float y);
    void set_angle();
    double teleport(float x, float y, float z);
    void set_velocity(float x, float y, float z);
    void new_angle(float new_angle);
    Path *getPath();
    char facetToNextWaypoint();
    void setGoal(float gX, float gY, float gZ);
    void setActionRange(float r);
    void setTargetID(int tid);
    void setTargetRadius(float x, float y);
    signed int findPath();
    int doMove();
    int doTrivialMove(float x, float y);
    int passableTile(float x, float y, int aiCheck);
    int canPath(XYZPoint p, float aRange, int targetID, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID);
    RGE_Zone_Map *canPath(int targetID, float aRange, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID);
    int canBidirectionPath(int targetID, int targetID2, float aRange, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID);
    RGE_Zone_Map *canPathWithObstructions(int targetID, float aRange, float *pathDistance, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID, ManagedArray/*<int>*/ *obstructions);
    int canPathWithAdditionalPassability(XYZPoint p, float aRange, int targetID, float *pathDistance, int eTerrain1, int eTerrain2, int aiCheck, int unobstructiblePlayerID, int unobstructibleGroupID);
    int findFirstTerrainAlongExceptionPath(int eTerrain, float *rX, float *rY);
    int canLinePath(XYPoint *s, XYPoint *d, float range, XYPoint *rPoint, int aiCheck);
    int canLinePath(int sX, int sY, int dX, int dY, float range, int aiCheck);
    int firstTileAlongLine(XYPoint *s, XYPoint *d, XYPoint *rPoint, int tType1, int tType2, int checkPassability);
    double maximumSpeed();
    char waitingToMove();
    void setWaitingToMove(char w);
    XYZBYTEPoint *userDefinedWaypoint(int v);
    int addUserDefinedWaypoint(XYZBYTEPoint *p, int stopObject);
    void removeAllUserDefinedWaypoints(int stopObject);
    void removeUserDefinedWaypoint(int v);
    void setFinalUserDefinedWaypoint();
    Path *findAvoidancePath(XYZPoint *goalPoint, float aRange, int targetID);
    void setInitialPoints(XYPoint *min, XYPoint *max);
    void copy_obj(RGE_Master_Static_Object *source2);
    static void boundAngle(float *x, int numFacets);
    void rotate(int amount);
    signed __int64 get_waypoint_checksum();
    //int __thiscall  __thiscall `vcall'{456,{flat}}(); // TODO: what the hell is this ?
    double getAngle();
    int numberUserDefinedWaypoints();
};
