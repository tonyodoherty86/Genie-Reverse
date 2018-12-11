#pragma once

/**
 * @file    Engine\DropDownButtonPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include "Panel_Button.hpp"

class TDropDownButtonPanel : public TButtonPanel
{
public:

    TDropDownPanel *drop_down_panel;

    TDropDownButtonPanel(TDropDownPanel *drop_down_panel_in);

    ~TDropDownButtonPanel();

    int handle_mouse_move( int x, int y, int ctrl_key, int shift_key );
};
