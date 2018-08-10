
/**
 * @file    Engine\TRB\Panel_Inventory.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TRIBE_Panel_Inven : public TPanel
{
public:

    TShape *pics;

    TRIBE_Player *player;

    short save_attr_num;
    short *save_attr;

    time_t idle_time;

    unsigned int idle_interval;

    void *font;

    unsigned int font_color;
    unsigned int back_color;

    TRIBE_Panel_Inven(TDrawArea *render_area_in, TPanel *parent_panel_in, void *font_in, TRIBE_Player *player_in);

    set_text_color(unsigned int font_color_in, unsigned int back_color_in);

    ~TRIBE_Panel_Inven();

    int handle_idle();

    void set_player(TRIBE_Player *player_in);

    void save_info();

    char get_help_info(char **string, int *page, int x, int y);
};
