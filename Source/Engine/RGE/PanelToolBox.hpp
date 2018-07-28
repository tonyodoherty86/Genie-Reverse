
/**
 * @file    Engine\TRB\PanelToolBox.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

class RGE_Panel_Tool_Box : public TPanel
{
public:

    TScreenPanel *screen_panel;

    RGE_View *view;

    RGE_Diamond_Map *map;

    TButtonPanel *game_mode_button,
                 *object_mode_button,
                 *delete_mode_button,
                 *move_mode_button,
                 *terrain_mode_button,
                 *elevation_mode_button,
                 *command_button;

    TPanel *dialog;

    RGE_Panel_Tool_Box(
        TDrawArea *draw_area_in,
        TPanel *parent_in,
        int x, int y, int wid, int hgt,
        void *font,
        int font_wid, int font_hgt,
        TDigital *sound,
        TScreenPanel *screen_panel_in,
        RGE_View *view_in,
        RGE_Diamond_Map *map_in);

    ~RGE_Panel_Tool_Box();

    int action(
        TPanel *from_panel,
        int action_in,
        unsigned int action_val1,
        unsigned int action_val2);

    int key_down_action(
        int key,
        short count,
        int alt_key,
        int ctrl_key,
        int shift_key);

    void game_mode_changed(
        int old_mode,
        int new_mode);

    void draw();
};
