
/**
 * @file    Engine\RGE\AiDiplomacyModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class DiplomacyAIModule : public AIModule
{
public:

    MainDecisionAIModule *md;

    int dislikeTable[10];
    int likeTable[10];
    char changeableTable[10];

    DiplomacyAIModule(void *pW, int playerID);
    DiplomacyAIModule(int playerID, int infile);

    ~DiplomacyAIModule();

    void setMainDecisionAI(MainDecisionAIModule *m);
    int update(int timeLimit);
    int save(int outfile);
    int stance(int playerID, int likeType);
    void changeStance(int playerID, int likeType, int delta);
    void setStance(int playerID, int likeType, int value);
    int isDisliked(int playerID);
    int isAmbivalent(int playerID);
    int isLiked(int playerID);
    int isChangeable(int playerID);
    void setChangeable(int playerID, char v);
    int mostHated(int tributeOn, int tributePlayer, int attackWinningPlayer, int attackWinningPlayerFactor);
    int mostLiked(int tributeOn, int tributePlayer);
    int isEnemy(int playerID);
    int isNeutral(int playerID);
    int isAlly(int playerID);
    int isAlliedWithMe(int playerID);
    void setRelation(int playerID, int newRelation);
};
