
/**
 * @file    Engine\TRB\Technology.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TRIBE_Tech
{
public:

    TRIBE_Tech(int handle, int a4);
    TRIBE_Tech(char *Filename);

    ~TRIBE_Tech();

    char do_tech(short a2, RGE_Player *player);

    void save(int);

    int get_help_message(short a2);
    int get_help_page(short a2);
    int get_hotkey(short a2);
};

class TRIBE_Player_Tech
{
public:

    TRIBE_Player_Tech(int handle, int a4, int a5, int a6);
    TRIBE_Player_Tech(TRIBE_Tech *a2, RGE_Player *a3, char a4);

    ~TRIBE_Player_Tech();

    short get_tech_state(short);
    char undo_tech(short a2);
    char do_tech(short a2);
    char research(short a2, float a3);
    void tech_cost(short, short *, short *, short *, short *, short *, short *);
    char check_tech_cost(short a2, short *a3);
    char start_research(short a2, unsigned char a3, short *a4);
    char cancel_research(short a2, unsigned char a3);
    char check_for_new_tech();
    void save(int);
    short get_progress(short);
    char *get_name(short);
    short get_string_id(short);
    short get_string_id2(short);
    char get_button_location(short a2);
    void do_rev_tech(short);
    char rev_tech(short a2);
    void disable(short);
    void enable(short);
    int get_help_message(short a2);
    int get_help_page(short a2);
    int get_hotkey(short a2);
};
