
/**
 * @file    Engine\TRB\AiStrategyModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class VictoryConditionRuleSystem
{
public:

    int sn[226];

    VictoryConditionRuleSystem();

    ~VictoryConditionRuleSystem();

    int loadRules(char *rName);
    void setRule(int ruleIndex, int ruleValue);
    int rule(int ruleIndex);
    int evaluateAsInProgress(TRIBE_Player *p, int ruleNumber);
    int evaluateAsNonInProgress(TRIBE_Player *p, int ruleNumber);
    int execute(TRIBE_Player *p, int vcNumber, int ruleNumber);
    int stopExecution(TRIBE_Player *p, int ruleNumber);
    void modifyForDifficultyLevel(int dL);
};

class TribeStrategyAIModule : public StrategyAIModule
{
public:

    TribeMainDecisionAIModule *md;

    int currentVictoryConditionValue;
    char ruleSetNameValue[257];
    int targetIDValue;
    int targetTypeValue;
    int secondTargetIDValue;
    int secondTargetTypeValue;

    Waypoint targetPoint1Value,
             targetPoint2Value;

    int targetAttributeValue;
    int targetNumberValue;
    int victoryConditionChangeTimeout;

    ManagedArray/*<int>*/
        vcRuleSet,
        executingRules,
        idleRules;

    VictoryConditionRuleSystem vcRules;

    int difficultyLevel;

    TribeStrategyAIModule(void *pW, int playerID);

    TribeStrategyAIModule(int playerID, int infile);
    ~TribeStrategyAIModule();

    bool update(int timeLimit);

    void setMainDecisionAI(TribeMainDecisionAIModule *m);

    int save(int outfile);

    char *ruleSetName();
    char *loadRules(char *rName);
    void setRule(int ruleIndex, int value);
    int rule(int ruleIndex);
    void setDifficultyLevel(int difficultyLevel);
    int currentVictoryCondition();
    int targetID();
    int targetType();
    int secondTargetID();
    int secondTargetType();
    Waypoint *targetPoint1();
    Waypoint *targetPoint2();
    int targetAttribute();
    int targetNumber();
    void setVictoryCondition(int vcNumber);
    int isRuleExecuting(int ruleNumber);
    int isRuleIdle(int ruleNumber);
};
