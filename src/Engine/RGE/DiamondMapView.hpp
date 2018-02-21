
/**
 * @file    Engine\RGE\DiamondMapView.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class RGE_Diamond_Map_View : public RGE_Diamond_Map
{
public:

    RGE_Diamond_Map_View();

    ~RGE_Diamond_Map_View();

    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_up_action(int x, int y, int ctrl_key, int shift_key);

    void draw();

    int command_make_do(int x, int y);
    int command_make_move(int x, int y);
    int command_make_work(int x, int y);
};
