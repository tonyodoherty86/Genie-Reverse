
/**
 * @file    Engine\RGE\Panel_Time.hpp
 * @author  Yvan Burrie
 * @date    2018/08/07
 * @version 1.0
 */

class RGE_Panel_Time : public TPanel
{
public:

    void *font;

    int game_time,
        last_game_time,
        old_time,
        real_time;

    RGE_Panel_Time(TDrawArea *draw_area_in, TPanel *parent_in, void *font_in);

    ~RGE_Panel_Time();

    void draw();

    int handle_idle();
};
