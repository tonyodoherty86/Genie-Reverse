#pragma once

#include <RGE/AiBuildModule.hpp>
class TribeMainDecisionAIModule;
class BuildItem;
class RGE_Player;
class ResourceItem;
class RGE_Static_Object;


/**
 * @file    Engine\TRB\AiBuildModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TribeBuildAIModule : public BuildAIModule
{
public:

    TribeMainDecisionAIModule *md;

    TribeBuildAIModule(void *pW, int pID);

    TribeBuildAIModule(int pID, int infile);

    ~TribeBuildAIModule();

    void setMainDecisionAI(TribeMainDecisionAIModule *m);
    int loadBuildList(char *lName, RGE_Player *player);
    void initialize();
    void skipNextBuildListItem();
    BuildItem *nextBuildableItem(int category);
    int nextBuildListItemCategory();
    int blockingResource();
    ResourceItem *mostNeededResource(ResourceItem *itemCost, int countNum);
    int addItem(RGE_Static_Object *newItem, int gameStarted);
    int addBuiltItem(RGE_Static_Object *newItem, int buildID);
    int removeBuiltItem(int id);
    int cancelBuildItem(int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID);
    int addTrainedUnit(int uType, int location, int uniqueID, int gameID);
    int cancelTrainUnit(int reason, int uType, int location, int uniqueID);
    int addResearch(int uType, int location, int uniqueID);
    int cancelResearch(int reason, int rType, int location, int uniqueID);
    bool isAgeResearch(int rID);
    int insert(int typeID, int buildCap, int insertionPoint);
    int insertResearch(int typeID, int insertionPoint);
    int insertGathererPercentage(int rType, int percentage, int insertionPoint);
    int numberBuiltOrInProgressItemsOfType(int type, int category);
    int allBuilt(int category1, int category2);
    int readyToResearch(int id, int ageResearch);
    void unskipBuildList(int builtSP, int builtG);
    BuildItem *buildItem(int typeID, int category1, int category2);
};
