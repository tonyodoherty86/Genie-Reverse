
/**
 * @file    Engine\RGE\AiBaseObject.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class BaseObject
{
public:

    BaseObject *next,
               *prev;

    int numberGroupsValue;
    int *groupIDValue;
    int categoryIDValue;
    int typeIDValue;
    int gameIDValue;

    char nameValue[64];

    float xPositionValue,
          yPositionValue,
          zPositionValue;

    float xSizeValue,
          ySizeValue,
          zSizeValue;

    int hitPointValue;
    int minHitPointValue;
    int maxHitPointValue;
    int busyValue;
    int currentTaskValue;
    int currentTargetValue;
    int currentTargetTypeValue;

    float currentTargetXPositionValue,
          currentTargetYPositionValue,
          currentTargetZPositionValue;

    BaseObject();
    BaseObject(int gri, int ci, int ti, int gi, char *nm, float xs, float ys, float zs, float xp, float yp, float zp, int hp, int minp, int maxp);
    BaseObject(BaseObject *bo);

    ~BaseObject();

    bool operator==(BaseObject *two);
    bool operator!=(BaseObject *two);
    bool operator<(BaseObject *two);
    bool operator>(BaseObject *two);

    int numberGroups();
    int groupID(int v);
    int inGroup(int v);
    int *addGroup(int v);
    int *removeGroup(int v);
    int categoryID();
    int typeID();
    int *gameID();
    char *name();
    double xPosition();
    double yPosition();
    double zPosition();
    double xSize();
    double ySize();
    double zSize();
    int hitPoints();
    int minHitPoints();
    int maxHitPoints();
    int busy();
    int currentTask();
    int currentTarget();
    int currentTargetType();
    double currentTargetXPosition();
    double currentTargetYPosition();
    double currentTargetZPosition();
    void setXPosition(float v);
    void setYPosition(float v);
    void setZPosition(float v);
    void setXSize(float v);
    void setYSize(float v);
    void setZSize(float v);
    void setHitPoints(int v);
    void incrementHitPoints(int v);
    void decrementHitPoints(int v);
    void setMinHitPoints(int v);
    void incrementMinHitPoints(int v);
    void decrementMinHitPoints(int v);
    void setMaxHitPoints(int v);
    void incrementMaxHitPoints(int v);
    void decrementMaxHitPoints(int v);
    void setBusy(int v);
    void setCurrentTask(int v);
    void setCurrentTarget(int v);
    void setCurrentTargetType(int v);
    void setCurrentTargetPosition(float x, float y, float z);
};
