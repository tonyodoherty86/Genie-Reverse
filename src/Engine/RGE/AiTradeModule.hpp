
/**
 * @file    Engine\RGE\AiTradeModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class TradeAIModule : public AIModule
{
public:

    MainDecisionAIModule *md;

    TradeAIModule(void *pW, int playerID);
    TradeAIModule(int playerID, int infile);

    ~TradeAIModule();

    void setMainDecisionAI(MainDecisionAIModule *m);

    int save(int outfile);
};
