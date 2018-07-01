
/**
 * @file    Engine\RGE\AiBuildItem.cpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#include "AiBuildItem.hpp"

BuildItem::BuildItem()
{
    BaseItem::BaseItem();
}

BuildItem::BuildItem(
    int bc,
    int ti,
    int bi,
    int n,
    int p,
    int bf,
    char *name,
    float x,
    float y,
    float z,
    int tSet,
    int tOne,
    int tTwo,
    int pEle)
{
    BaseItem::BaseItem(
        ti,
        -1,
        bi,
        name,
        -1.0, -1.0, -1.0,
        x, y, z);

    this->buildCategoryValue       = bc;
    this->numberValue              = n;
    this->priorityValue            = p;
    this->buildFromValue           = bf;
    this->terrainSetValue          = tSet;
    this->placeOnElevationValue    = pEle;
    this->terrainAdjacencyValue[0] = tOne;
    this->terrainAdjacencyValue[1] = tTwo;
}

BuildItem::BuildItem(BuildItem *bi)
{
    BaseItem::BaseItem((BaseItem *)&this->vfptr, (BaseItem *)&bi->vfptr);

    this->buildCategoryValue       = bi->buildCategoryValue;
    this->numberValue              = bi->numberValue;
    this->priorityValue            = bi->priorityValue;
    this->progressValue            = bi->progressValue;
    this->builtValue               = bi->progressValue;
    this->buildAttemptsValue       = bi->buildAttemptsValue;
    this->buildFromValue           = bi->buildFromValue;
    this->terrainSetValue          = bi->terrainSetValue;
    this->placeOnElevationValue    = bi->placeOnElevationValue;
    this->terrainAdjacencyValue[0] = bi->terrainAdjacencyValue[0];
    this->terrainAdjacencyValue[1] = bi->terrainAdjacencyValue[1];
}

BuildItem::BuildItem(BuildItem *bi)
{
    BaseItem::BaseItem((BaseItem *)&this->vfptr, (BaseItem *)&bi->vfptr);

    this->buildCategoryValue       = bi->buildCategoryValue;
    this->numberValue              = bi->numberValue;
    this->priorityValue            = bi->priorityValue;
    this->progressValue            = bi->progressValue;
    this->builtValue               = bi->progressValue;
    this->buildAttemptsValue       = bi->buildAttemptsValue;
    this->buildFromValue           = bi->buildFromValue;
    this->terrainSetValue          = bi->terrainSetValue;
    this->placeOnElevationValue    = bi->placeOnElevationValue;
    this->terrainAdjacencyValue[0] = bi->terrainAdjacencyValue[0];
    this->terrainAdjacencyValue[1] = bi->terrainAdjacencyValue[1];
}

BuildItem::~BuildItem()
{
    this->~BaseItem();
}

bool operator==(BuildItem *two)
{
    return one->typeIDValue == two->typeIDValue;
}

bool operator!=(BuildItem *two)
{
    return one->typeIDValue != two->typeIDValue;
}

bool operator<(BuildItem *two)
{
    return one->typeIDValue < two->typeIDValue;
}

bool operator>(BuildItem *two)
{
    return one->typeIDValue > two->typeIDValue;
}

int BuildItem::buildCategory()
{
    return this->buildCategoryValue;
}

int BuildItem::number()
{
    return this->numberValue;
}

int BuildItem::priority()
{
    return this->priorityValue;
}

int BuildItem::inProgress()
{
    return this->progressValue;
}

int BuildItem::built()
{
    return this->builtValue;
}

int BuildItem::buildAttempts()
{
    return this->buildAttemptsValue;
}

int BuildItem::buildFrom()
{
    return this->buildFromValue;
}

int BuildItem::terrainSet()
{
    return this->terrainSetValue;
}

int BuildItem::terrainAdjacency(int v)
{
    if( v < 1 || v > 2 ){
        return -1;
    }else{
        return *(&this->terrainSetValue + v);
    }
}

int BuildItem::placeOnElevation()
{
    return this->placeOnElevationValue;
}

void BuildItem::setInProgress(int p)
{
    this->progressValue = p;
}

void BuildItem::setBuilt(int v)
{
    this->builtValue = v;
}

void BuildItem::setBuildAttempts(int v)
{
    this->buildAttemptsValue = v;
}

void BuildItem::incrementBuildAttempts()
{
    this->buildAttemptsValue++;
}

void BuildItem::decrementBuildAttempts()
{
    if( --this->buildAttemptsValue < 0 ){
        this->buildAttemptsValue = 0;
    }
}

int BuildItem::numberBuilds()
{
    return this->numberBuildsValue;
}

void BuildItem::incrementNumberBuilds()
{
    this->numberBuildsValue++;
}

void BuildItem::setNumberBuilds(int v)
{
    this->numberBuildsValue = v;
}

int BuildItem::buildCap()
{
    return this->buildCapValue;
}

void BuildItem::setBuildCap(int v)
{
    this->buildCapValue = v;
}

int BuildItem::skipCycles()
{
    return this->skipCyclesValue;
}

void BuildItem::incrementSkipCycles()
{
    this->skipCyclesValue++;
}

void BuildItem::setSkipCycles(int v)
{
    this->skipCyclesValue = v;
}

bool BuildItem::permanentSkip()
{
    return this->permanentSkipValue;
}

void BuildItem::setPermanentSkip(bool v)
{
    this->permanentSkipValue = v;
}
