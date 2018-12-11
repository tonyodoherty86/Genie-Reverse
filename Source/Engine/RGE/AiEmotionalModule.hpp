#pragma once

#include "AiModule.hpp"

/**
 * @file    Engine\RGE\AiEmotionalModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class EmotionalAIModule : public AIModule
{
public:

    MainDecisionAIModule *md;

    int stateValue[6];
    char stateNameValue[6][30];

    EmotionalAIModule(void *pW, int playerID);
    EmotionalAIModule(int playerID, int infile);

    ~EmotionalAIModule();

    void setMainDecisionAI(MainDecisionAIModule *m);
    int save(int outfile);
    char *stateName(int s);
    int state(int s);
    void setState(int s, int value);
    void incrementState(int s, int delta);
    void decrementState(int s, int delta);
    int overallState();
    void setOverallState(int s);

    int defaultState();
};
