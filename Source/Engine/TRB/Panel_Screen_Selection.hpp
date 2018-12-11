#pragma once

/**
 * @file    Engine\TRB\Panel_Screen_Selection.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

#include <Panel_Screen.hpp>

class TribeSelectTribeScreen : public TScreenPanel
{
    TPicturePanel *background;

    TTextPanel *title;

    TTextPanel *tribeText;

    TButtonPanel *tribeButton[9],
                 *okButton,
                 *cancelButton;

    char **screenText;

    int numLines;

    TribeSelectTribeScreen();

    ~TribeSelectTribeScreen();

    int action(TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2);

    void fillTribeText(int t);

    char *tribeName(int i);
};
