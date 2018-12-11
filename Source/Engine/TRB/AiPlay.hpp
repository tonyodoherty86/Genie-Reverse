#pragma once

#include <RGE/AiPlay.hpp>
class RGE_Static_Object;

/**
 * @file    Engine\TRB\AiPlay.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

class TribeAIPlayBook : public AIPlayBook
{
public:

    TribeAIPlayBook();

    ~TribeAIPlayBook();

    int convertTargetNameToIntType(char *t);
    int convertTargetCharacteristicNameToIntType(char *t);
    int convertUnitNameToIntType(char *t);
    int convertUnitToIntType(RGE_Static_Object *obj);
};
