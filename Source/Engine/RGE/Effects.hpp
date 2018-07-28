
/**
 * @file    Engine\RGE\Effects.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class RGE_Effects
{
public:

    struct RGE_Effect *effects;
    int effect_num;

    RGE_Effects(int infile);
    RGE_Effects(char *effect_file);

    ~RGE_Effects();

    void save(int outfile);

    void do_effect(short current_effect, RGE_Player *player);
};

#define RGE_EFFECT_NAME_LENGTH 31

struct RGE_Effect
{
    short id;

    char name[RGE_EFFECT_NAME_LENGTH];

    short string_table_id;

    short effect_list_num;
    struct RGE_Effect_Command *effect_list;
};

struct RGE_Effect_Command
{
    char command;

    short change_num1,
          change_num2,
          change_num3;

    float change_amount;
};
