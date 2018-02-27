
/**
 * @file    Engine\TRB\Effects.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Effects : public RGE_Effects
{
public:

    TRIBE_Effects(int infile);

    ~TRIBE_Effects();

    TRIBE_Effects(char *effect_file);

    void do_effect(short current_effect, RGE_Player *player);
    void do_tech_effect(short current_effect, RGE_Player *player);
};
