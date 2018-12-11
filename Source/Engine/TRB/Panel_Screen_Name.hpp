#pragma once

/**
 * @file    Engine\TRB\Panel_Screen_Name.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

#include <Panel_Screen.hpp>

class TRIBE_Screen_Name : public TScreenPanel
{
public:

    TTextPanel *title;
    TTextPanel *name_text;

    TListPanel *name_list;

    TScrollBarPanel *name_scrollbar;

    TButtonPanel *new_button,
                 *remove_button,
                 *ok_button,
                 *cancel_button,
                 *close_button;

    int started_input;

    TRIBE_Screen_Name();

    ~TRIBE_Screen_Name();

    void init_vars();

    void get_player_names();

    void setup_tab_order();

    int handle_idle();

    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);
};
