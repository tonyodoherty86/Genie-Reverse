
/**
 * @file    Engine\RGE\AiBuildModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class BuildAIModule : public AIModule
{
public:

    BuildItem buildList;

    int buildListLengthValue;
    char buildListNameValue[257];
    char lastBuildItemRequestedValue[257];
    char currentBuildItemRequestedValue[257];
    char nextBuildItemRequestedValue[257];
    int numberItemsIntoBuildListValue;

    ManagedArray/*<int>*/ typesToIgnore;

    BuildAIModule(void *pW, int playerID);

    int loadState(char *__formal);
    int saveState(char *__formal);
    int gleanState(int __formal);

    BuildAIModule(int playerID, int infile);

    //void ManagedArray<int>::~ManagedArray<int>(ManagedArray<int> *this);

    ~BuildAIModule();

    int save(int outfile);

    void displayBuildList();
    int loadBuildList(char *lName, RGE_Player *player);
    int buildListLength();
    char *buildListName();
    int haveBuildList();
    int insertItem(RGE_Player *player, int typeID, int quantity, int buildCategory, int buildFrom, int buildCap, int insertAfterItemNumber);
    int numberItemsBuilt();
    int numberItemsInProgress();
    int numberItemsBuiltOrInProgress();
    int numberItemsIntoBuildList();
    char *lastBuildItemRequested();
    char *currentBuildItemRequested();
    char *nextBuildItemRequested();
    int numberItemsOfType(int type, int category);
    int numberBuiltItemsOfType(int type, int category);
    int numberUnbuiltItemsOfType(int type, int category);
    int numberBuiltOrInProgressItemsOfType(int type, int category);
    int numberInProgressItemsOfType(int type, int category);
    void removeOldList();
    BuildItem *anyBuildListItem(int id, int checkBuilt, int buildStatus);
    BuildItem *specificBuildListItem(int id);
};
