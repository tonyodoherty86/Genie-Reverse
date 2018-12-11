#pragma once

/**
 * @file    Engine\TRB\DialogHelp.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include "Panel_Dialog.hpp"

class THelpDialog : public TDialogPanel
{
public:

    int help_page_id;
    char parent_panel[256];
    TTextPanel *title;
    TTextPanel *list;
    TButtonPanel *ok_button;
    TButtonPanel *encyclopedia_button;

    THelpDialog(TEasy_Panel *parentPanel, char *in_parent_panel, int help_string_id, int in_help_page_id, int x, int y);
    THelpDialog(TEasy_Panel *parentPanel, char *in_parent_panel, char *in_help_string, int in_help_page_id, int x, int y);
    ~THelpDialog();
    void setup_help(TEasy_Panel *parentPanel, char *in_parent_panel, char *help_string, int in_help_page_id, int mouse_x, int mouse_y);
    int action(TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2);
    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
};
