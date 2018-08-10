
/**
 * @file    Engine\TRB\Panel_Object_ScenarioEditor.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object
{
public:

    RGE_Master_Static_Object *master_game_obj;

    int master_culture_id;

    TRIBE_Scenario_Editor_Panel_Object(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        TShape *unit_pics_in,
        TShape **bldg_pics_in,
        TRIBE_Player *player_in);

    ~TRIBE_Scenario_Editor_Panel_Object();

    void set_master_info(RGE_Master_Static_Object *master_game_object_in, TRIBE_Player *master_player_in);

    void draw();
    void draw_item(int row, int pic_index, TRIBE_Panel_Object::ValueType val_type, int val1, int val2);

    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);

    int get_pierce_armor();
};
