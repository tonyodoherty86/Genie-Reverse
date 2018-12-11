#pragma once

/**
 * @file    Engine\TRB\AiConstructionModule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

#include <RGE/AiConstructionModule.hpp>
#include <RGE/Path.hpp>

struct PlacementState;
class TribeMainDecisionAIModule;
class BuildItem;
class RGE_Static_Object;
class ConstructionItem;

class TribeConstructionAIModule : public ConstructionAIModule
{
public:

    TribeMainDecisionAIModule *md;

    TribeConstructionAIModule(void *pW, int pID);

    TribeConstructionAIModule(int pID, int infile);

    ~TribeConstructionAIModule();

    void setMainDecisionAI(TribeMainDecisionAIModule *m);

    int canPlace(BuildItem *bi);
    void placeStructure(BuildItem *bi, int builder, PlacementState *placementState, unsigned int startTime);
    void placeDock(BuildItem *bi);
    void setBuilt(RGE_Static_Object *bo, int v);

    ConstructionItem *compare(ConstructionItem *one, ConstructionItem *two);
};

struct PlacementState
{
    int buildingTypeID;
    float buildingSize;
    char buildingName[256];
    int builderID;
    int minimumDistance,
        maximumDistance;
    int active;
    XYPoint bestPoint;
    int bestPointValue;
    int iterationX;
    int randomInfluence;
    BuildItem *buildItem;
};
