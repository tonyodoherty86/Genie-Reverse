#pragma once

/**
 * @file    Engine\TRB\ScreenJoin.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include <Panel_Screen.hpp>

class TribeJoinScreen : public TScreenPanel
{
public:

    int startedSession;

    int listFilled;

    TTextPanel *title,
               *listTitle;

    TListPanel *list;

    TScrollBarPanel *scrollbar;

    TButtonPanel *joinButton,
                 *createButton,
                 *cancelButton,
                 *refreshButton,
                 *close_button;

    int game_count,
        waitingToStart;

    time_t joinTime;

    TribeJoinScreen();

    ~TribeJoinScreen();

    int handle_idle();

    int handle_user_command( WPARAM wParam, LPARAM lParam );

    void fillList();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
