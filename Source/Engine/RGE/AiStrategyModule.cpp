
/**
 * @file    Engine\RGE\AiStrategyModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

StrategyAIModule::StrategyAIModule(void *pW, int playerID)
{
    AIModule::AIModule(aStrategyAi, 1008, playerID, pW);
}
