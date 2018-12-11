#pragma once

/**
 * @file    Engine\TRB\Panel_Screen_ScenarioEditorMenu.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

#include <Panel_Screen.hpp>

class TRIBE_Screen_Sed_Menu : public TScreenPanel
{
public:

    TTextPanel *title;

    TButtonPanel *button[4],
                 *close_button;

    TRIBE_Screen_Sed_Menu();

    ~TRIBE_Screen_Sed_Menu();

    int handle_idle();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
