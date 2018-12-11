#pragma once

#include "AiBuildModule.hpp"
#include "AiConstructionModule.hpp"
#include "AiInformationModule.hpp"
#include "AiResourceModule.hpp"
#include "AiStrategyModule.hpp"
#include "AiTacticalModule.hpp"

#include <RGE/AiDiplomacyModule.hpp>
#include <RGE/AiEmotionalModule.hpp>
#include <RGE/AiMainDecisionModule.hpp>
#include <RGE/AiTradeModule.hpp>

/**
 * @file    Engine\TRB\AiMainDecisionModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TribeMainDecisionAIModule : public MainDecisionAIModule
{
public:

    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    TribeTacticalAIModule tacticalAI;
    TradeAIModule tradeAI;

    TRIBE_Player *aiPlayer;

    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;

    time_t lastDiplomacyUpdateTime,
                 lastTacticalUpdateTime,
                 lastTributeChatTime,
                 tributeChatTimeout;

    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;

    int tributeGiven[RGE_PLAYERS_COUNT];

    TribeMainDecisionAIModule(
        void *pW,
        int playerID,
        char *playerName,
        TRIBE_Player *aiP,
        char *buildListName,
        char *cityPlanName,
        char *ruleSetName);

    TribeMainDecisionAIModule(
        int playerID,
        char *playerName,
        TRIBE_Player *aiP,
        int infile);

    ~TribeMainDecisionAIModule();

    void setLogHistory(int v);
    int update(int timeLimit);
    int save(int outfile);
    void kick(int m);
    RGE_Static_Object *addObject(RGE_Static_Object *bo);
    int removeObject(int id);
    int objectGroupThatCanPerformAction(int a);
    int canPerformAction(int id, int a);
    void detask(int uID);
    int isMoveable(int o);
    void updateBuildAIWithObjects();
    void tributeNotify(int playerID, int resourceID, int amount);
    void revokeTributeAlliance();
    void setTributeChat();
    int processAICommand(int caller, int mType, int p1, int p2, int p3);
    int currentScore(int playerID);
};
