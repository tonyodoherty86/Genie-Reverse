
/**
 * @file    Engine\TRB\Effects.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

class TRIBE_Effects : public RGE_Effects
{
public:

    TRIBE_Effects(
        int infile);

    TRIBE_Effects(
        char *effect_file);

    ~TRIBE_Effects();

    void do_effect(
        short current_effect,
        TRIBE_Player *player);

    void do_tech_effect(
        short current_effect,
        TRIBE_Player *player);
};
