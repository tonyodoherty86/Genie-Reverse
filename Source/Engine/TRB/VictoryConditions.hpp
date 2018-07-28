
/**
 * @file    Engine\TRB\VictoryConditions.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions
{
public:

    TRIBE_Victory_Conditions(RGE_Player *in_player, int infile, int *player_id_hash, char version_control);
    TRIBE_Victory_Conditions(RGE_Player *in_Player);

    ~TRIBE_Victory_Conditions();

    void handle_condition(RGE_Victory_Entry *node);
    void handle_tech(RGE_Victory_Entry *node);

    char add_tech(char v_group, int tech_id);
};
