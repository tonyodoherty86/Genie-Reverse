
/**
 * @file    Engine\RGE\AiBuildItem.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class BuildItem : public BaseItem
{
public:

    BuildItem *next,
              *prev;

    int buildCategoryValue = -1;

    int numberValue = 0;

    int priorityValue = 0;

    int progressValue = 0;

    int builtValue = 0;

    int buildAttemptsValue = 0;

    int buildFromValue = -1;

    int terrainSetValue = -1;

    int terrainAdjacencyValue[2] = {-1, -1};

    int placeOnElevationValue;

    int numberBuildsValue = 0;

    int buildCapValue = -1;

    int skipCyclesValue = 0;

    bool permanentSkipValue = false;

    BuildItem();

    BuildItem(
        int bc,
        int ti,
        int bi,
        int n,
        int p,
        int bf,
        char *name,
        float x,
        float y,
        float z,
        int tSet,
        int tOne,
        int tTwo,
        int pEle);

    BuildItem(BuildItem *bi);

    ~BuildItem();

    bool operator==(BuildItem *two);
    bool operator!=(BuildItem *two);
    bool operator<(BuildItem *two);
    bool operator>(BuildItem *two);

    int buildCategory();

    int number();

    int priority();

    int inProgress();

    int built();

    int buildAttempts();

    int buildFrom();

    int terrainSet();

    int terrainAdjacency(int v);
    int placeOnElevation();
    void setInProgress(int p);
    void setBuilt(int v);

    void setBuildAttempts(int v);
    void incrementBuildAttempts();
    void decrementBuildAttempts();

    int numberBuilds();
    void incrementNumberBuilds();
    void setNumberBuilds(int v);

    int buildCap();
    void setBuildCap(int v);

    int skipCycles();
    void incrementSkipCycles();
    void setSkipCycles(int v);

    char permanentSkip();
    void setPermanentSkip(char v);
};
