#pragma once

/**
 * @file    Engine\TRB\Panel_Screen_Wait.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

#include <Panel_Screen.hpp>

class TRIBE_Screen_Wait : public TScreenPanel
{
public:

    TTextPanel *message;

    TButtonPanel *cancel_button;
    TButtonPanel *close_button;

    TTextPanel *scenarioName;
    TTextPanel *settingText[20];

    TRIBE_Screen_Wait();

    ~TRIBE_Screen_Wait();

    void set_text(char *message_in);
    void set_text(int message_in);

    int action(TPanel *from_panel, int action_in, unsigned int val1, unsigned int val2);

    int handle_idle();
};
