#pragma once

/**
 * @file    Engine\TRB\Panel_Dialog_Name.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

#include <Panel_Dialog.hpp>

class TRIBE_Dialog_Name : public TDialogPanel
{
public:

    TTextPanel *title;
    TTextPanel *name_text;

    TEditPanel *name_input;

    TButtonPanel *ok_button,
                 *cancel_button;

    TRIBE_Dialog_Name(TScreenPanel *parent_panel_in);

    ~TRIBE_Dialog_Name();

    int action(
        TPanel *from_panel,
        int action_in,
        unsigned int action_val1,
        unsigned int action_val2);

    int wnd_proc(
        HWND *hWnd,
        unsigned int msg,
        WPARAM wParam,
        LPARAM lParam);
};
