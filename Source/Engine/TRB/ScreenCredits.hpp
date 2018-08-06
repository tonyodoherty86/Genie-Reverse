
/**
 * @file    Engine\TRB\ScreenCredits.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

//typedef TDropDownPanel::DropdownMode TRIBE_Credits_Screen::ScreenMode;

class TRIBE_Credits_Screen : public TScreenPanel
{
public:

    TScrollTextPanel *text_panel;

    int text_set;

    int picture_set;

    time_t last_picture_time,
           last_pause_time;

    /**
     * todo: TDropDownPanel::ScreenMode
     */
    int mode;

    PALETTEENTRY color_table[256], color;

    TShape *back_pics[7];

    int first_draw,
        text_done;

    TRIBE_Credits_Screen();

    ~TRIBE_Credits_Screen();

    int handle_mouse_down( char mouse_button_in, int x, int y, int ctrl_key, int shift_key );

    int handle_idle();

    void draw();

    int key_down_action( int key, short count, int alt_key, int ctrl_key, int shift_key );

    int action( TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2 );

    void close_screen();
};
