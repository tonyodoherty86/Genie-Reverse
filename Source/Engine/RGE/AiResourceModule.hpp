#pragma once

/**
 * @file    Engine\RGE\AiResourceModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#include "AiModule.hpp"
class ResourceItem;

class ResourceAIModule : public AIModule
{
public:

    MainDecisionAIModule *md;

    int numberResourcesValue;
    int *resourceValue;

    int *minValue,
        *maxValue;

    int **resourceTypesValue;
    int *numberResourceTypesValue;

    ResourceAIModule(void *pW, int playerID, int n, int iV, int minV, int maxV);

    ~ResourceAIModule();

    int processMessage(AIModuleMessage *m);
    int update(int timeLimit);
    void setMainDecisionAI(MainDecisionAIModule *m);
    int numberResources();
    int resource(int n);
    int resourcesAvailable(ResourceItem *ri);
    int unavailableResource(ResourceItem *ri);
    int minValueOfResource(int n);
    int maxValueOfResource(int n);
    void setResource(int n, int v);
    void setResources(ResourceItem *ri);
    void incrementResource(int n, int v);
    void incrementResources(ResourceItem *ri);
    void decrementResource(int n, int v);
    void decrementResources(ResourceItem *ri);
    void setResourceMin(int n, int v);
    void setResourceMax(int n, int v);
    int filterOutMessage(AIModuleMessage *m);
    void addResourceType(int r, int t);
    int isResourceType(int r, int t);
    int numberResourceTypes(int r);
    int lowestResourceType();
};
