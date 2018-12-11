#pragma once

#include <RGE/AiModule.hpp>

class ResourceItem;

/**
 * @file    Engine\TRB\AiResourceModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TribeResourceAIModule : public AIModule
{
public:

    TribeMainDecisionAIModule *md;

    int numberResourcesValue;

    TribeResourceAIModule(void *pW, int playerID, int n, int iV, int minV, int maxV);

    TribeResourceAIModule(int playerID, int infile);

    ~TribeResourceAIModule();

    void setMainDecisionAI(TribeMainDecisionAIModule *m);
    int save(int outfile);
    int numberResources();
    int resource(int n);
    int resourcesAvailable(ResourceItem *ri);
    int unavailableResource(ResourceItem *ri);
    char *resourceName(int i);
};
