#pragma once

#include "Panel_Easy.hpp"


/**
 * @file    Engine\Panel_Screen.hpp
 * @author  Yvan Burrie
 * @date    2018/08/07
 * @version 1.0
 */

class TScreenPanel : public TEasy_Panel
{
public:

    TScreenPanel();

    TScreenPanel( char *name );

    ~TScreenPanel();

    int setup(
        TDrawArea *render_area_in,
        char *info_file_name,
        int resource_file_id,
        int allow_shadow_area_in );

    int setup(
        TDrawArea *render_area_in,
        char *palette_file,
        int pal_res_id,
        char color_in,
        int allow_shadow_area_in );

    void draw();

    int handle_paint();

    void set_focus( int have_focus_in );
};
