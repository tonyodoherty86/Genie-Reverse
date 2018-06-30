
/**
 * @file    Engine\RGE\AiConstructionItem.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class ConstructionItem
{
public:

    ConstructionItem();
    ConstructionItem(float x, float y, float z, float xs, float ys, float zs, int ti, char *n);
    ConstructionItem(ConstructionItem *ci);

    ~ConstructionItem();

    bool operator==(ConstructionItem *two);
    bool operator!=(ConstructionItem *two);
    bool operator<(ConstructionItem *two);
    bool operator>(ConstructionItem *two);

    int inProgress();
    int built();
    int buildAttempts();
    void setInProgress(int p);
    void setBuilt(int b);
    void incrementBuildAttempts();
    void decrementBuildAttempts();
    void setBuildAttempts(int v);
};
