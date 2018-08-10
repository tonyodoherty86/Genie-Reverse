
/**
 * @file    Engine\RGE\AiPlay.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class AIPlayGroup
{
public:

    char minValue[6],
         maxValue[6];

    AIPlayGroup();

    char minimum(int n);
    void setMinimum(int n, int v);

    char maximum(int n);
    void setMaximum(int n, int v);

    void initialize();
};

class AIPlayPhaseCommand
{
public:

    char groupValue;
    char typeValue;

    int value1Value,
        value2Value,
        value3Value;

    AIPlayPhaseCommand();
    AIPlayPhaseCommand(char g, char t, int v1, int v2, int v3);
    AIPlayPhaseCommand(char g, char *t, int v1, int v2, int v3);

    char *nameType();

    static signed int convertToIntType(char *t);
    static char *convertToNameType(char t);
};

class AIPlayPhaseTrigger
{
public:

    char typeValue;

    int value1Value,
        value2Value;

    char phaseValue;
    char nextPhaseValue;
    int randomnessValue;

    AIPlayPhaseTrigger();
    AIPlayPhaseTrigger(char t, int v1, int v2, char p, char n, int r);
    AIPlayPhaseTrigger(char *t, int v1, int v2, char p, char n, int r);

    char *nameType();

    static signed int convertToIntType(char *t);
    static char *convertToNameType(char t);
};

class AIPlayPhase
{
public:

    AIPlayPhaseCommand commands[5];

    AIPlayPhaseTrigger triggers[3];

    AIPlayPhase();

    AIPlayPhaseCommand *command(int v);

    AIPlayPhase *trigger(int v);

    int addCommand(AIPlayPhaseCommand *c);
    int addTrigger(AIPlayPhaseTrigger *t);

    void initialize();
};

class XYZ
{
public:

    int xValue,
        yValue,
        zValue;

    XYZ();
    XYZ(int a, int b, int c);

    void rotateXYByFacet(XYZ *refPoint, XYZ *rPoint, char facet);

    bool operator==(XYZ *two);
    bool operator!=(XYZ *two);

    XYZ *operator+(XYZ *result);
    XYZ *operator-(XYZ *result);
};

#define RGE_AI_PLAY_STATUS_ORIGINAL_HIT_POINTS_COUNT 5

class AIPlayStatus
{
public:

    struct GroupingStruct
    {
        int id;
        char groupID;
        char type;
    }
    groupings[50];

    int playNumberValue;
    int targetValue;

    XYZ originalPointValue;
    int originalHitPointsValue[RGE_AI_PLAY_STATUS_ORIGINAL_HIT_POINTS_COUNT];

    char currentPhaseValue;
    int savedAttackerValue;
    unsigned int lastPhaseChangeTimeValue;
    char deviationValue;

    AIPlayStatus();

    int originalHitPoints(int n);
    void setOriginalHitPoints(int n, int v);
    int numberInPlay();
    int numberInGroup(int n);
    int numberOfTypeInGroup(int n, int type);
    char group(int uID);
    int addGrouping(int uID, char gID, char type);
    int removeGrouping(int uID);
    void zeroAllGroupings();
    void copyUnits(int *array, int *count);
    void load(int infile);
    void save(int outfile);
    void copy(AIPlayStatus *ps);
    void removeDeadUnits(int gID, RGE_Game_World *world);
    void resetHitPoints(int gID, RGE_Game_World *world);
};

class AIPlay
{
public:

    char nameValue[65];

    char minimumNumberUnitsValue,
         maximumNumberUnitsValue;

    char typeValue;
    char targetTypeValue[5];
    char targetCharacteristicValue[5];
    char powerValue;
    char overflowValue;
    char intelligenceValue;
    char deathPercentageValue;
    char numberGroupsValue;

    AIPlayGroup groups[5];

    AIPlayPhase phases[10];

    AIPlay();

    void setName(char *n);
    int humanPlay();
    char *typeName();

    char targetType(int n);
    int isTargetType(char v);
    int addTargetType(char v);

    char targetCharacteristic(int n);
    int isTargetCharacteristic(char v);
    int addTargetCharacteristic(char v);
    int gatherTolerance(int groupID, int phaseID);

    AIPlayGroup *group(int n);
    AIPlayPhase *phase(int n);
    AIPlay *fillGroups(AIPlayStatus *playStatus, int *groupMembers, int numberGroupMembers, RGE_Game_World *world);
    int groupGivenCommandOnPhase(int gID, int cType, int pID);

    static signed int convertToIntType(char *t);
    static char *convertToNameType(char t);

    int locationsOnMap(int targetX, int targetY, int mapXSize, int mapYSize);
};

class AIPlayBook
{
public:

    int numberPlaysValue;

    char nameValue[65];

    AIPlay *plays;

    AIPlayBook();

    ~AIPlayBook();

    int loadPlays(char *filename);

    AIPlay *play(int n);
    AIPlay *play(char *name);
    int playNumber(char *name);

    static int convertTargetNameToIntType(char *t);
    static int convertTargetCharacteristicNameToIntType(char *t);
    static int convertUnitNameToIntType(char *t);
    static int convertUnitToIntType(RGE_Static_Object *obj);
};
