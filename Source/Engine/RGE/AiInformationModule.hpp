#pragma once

#include "AiModule.hpp"

/**
 * @file    Engine\RGE\AiInformationModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class InformationAIModule : public AIModule
{
public:

    InformationAIModule(void *pW, int playerID);

    ~InformationAIModule();
};
