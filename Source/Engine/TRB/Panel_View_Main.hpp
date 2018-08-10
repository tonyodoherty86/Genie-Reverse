
/**
 * @file    Engine\TRB\Panel_View_Main.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TRIBE_Main_View : public RGE_Main_View
{
public:

    void draw_multi_object_outline();
    int draw_wall_outline(int col, int row, TRIBE_Master_Building_Object *master_bldg, int facet);
    int command_place_object(int x, int y, int reset_mode);
    int command_place_multi_object(int x1, int y1, int x2, int y2, int reset_mode);
    void place_line_of_walls(TRIBE_Player *player, TRIBE_Master_Building_Object *master_obj, int x1, int y1, int x2, int y2);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_up_action(int x, int y, int ctrl_key, int shift_key);
    int pick_through_fog(RGE_Static_Object *obj);
    int pick_weight(RGE_Static_Object *obj, int confidence);
    int command_make_do(int x, int y, int work_on_tile, short action_type);
    int mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key);
};
