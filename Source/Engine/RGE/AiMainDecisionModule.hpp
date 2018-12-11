#pragma once

class RGE_Player;
class RGE_Static_Object;

#include "AiModule.hpp"

#include <ManagedArray.hpp>

/**
 * @file    Engine\RGE\AiMainDecisionModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class MainDecisionAIModule : public AIModule
{
public:

    RGE_Player *player;

    ManagedArray/*<int>*/ objects;

    MainDecisionAIModule(void *pW, int playerID, RGE_Player *plyr);
    MainDecisionAIModule(RGE_Player *i, int playerID, RGE_Player *plyr, int infile);

    ~MainDecisionAIModule();

    void setLogHistory(int v);

    int save(int outfile);

    RGE_Static_Object *addObject(RGE_Static_Object *obj);

    int removeObject(int id);
    int numberObjects();
    int numberObjectsWithAction(int aid);
    int numberObjectsWithGroup(int gid);
    int numberObjectsWithActionAndTarget(int action, int target);
    int numberObjectsWithTargetType(int tt);
    int numberObjectsWithActionAndTargetType(int action, int tt);

    RGE_Static_Object *object(int id);
    RGE_Static_Object *object(int gameID, int typeID, int groupID, int currentAction, int canPerformActionID, int targetID, int targetType, int secondaryTargetType, int objectState, int maxAttributeAmount);
    RGE_Static_Object *object(int gameID, int typeID, int groupID, int action1, int action2, int objectState);

    int objectGroupThatCanPerformAction(int a);
    int canPerformAction(int id, int t);
    int numberBusyObjects();

    RGE_Static_Object *mostDamaged(int oGroup, int oType);
};
