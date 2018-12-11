#pragma once

#include <Panel_Screen.hpp>

/**
 * @file    Engine\TRB\ScreenAchievements.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TribeAchievementsScreen : public TScreenPanel
{
    int end_game_flag;

    int current_mode;

    int size;

    TTextPanel *title,
               *summary_text,
               *instruction,
               *win_loss_text,
               *time,
               *title_bar[7],
               *achievement_choice[5],
               *statistics[RGE_PLAYERS_COUNT - 1][7],
               *player_names[RGE_PLAYERS_COUNT - 1];

    TScrollBarPanel *summary_text_bar,
                    *instruction_bar,
                    *win_loss_text_bar;

    TButtonPanel *okButton,
                 *backButton,
                 *backButton2,
                 *timelineButton,
                 *aftermathButton,
                 *restartButton,
                 *close_button;

    TShape *win_decal;

    Time_Line_Panel *time_line;

    TribeAchievementsScreen( char *titleText, int end_flag );

    ~TribeAchievementsScreen();

    void set_mode( int new_mode );

    void draw();

    int handle_mouse_down( int mouse_button_in, int x, int y, int ctrl_key, int shift_key );

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );

    int handle_idle();

    int wnd_proc( HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
};
