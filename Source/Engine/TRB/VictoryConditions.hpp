#include <RGE/VictoryConditions.hpp>

#pragma once

/**
 * @file    Engine\TRB\VictoryConditions.hpp
 * @author  Yvan Burrie
 * @date    2018/07/30
 * @version 1.0
 */

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions
{
public:

    void handle_condition( RGE_Victory_Entry *node );
    void handle_tech( RGE_Victory_Entry *node );

    char add_tech( char v_group, int tech_id );
};
