
/**
 * @file    Engine\TRB\DiamondMapView.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View
{
public:

    unsigned int last_attack_time;

    int flash_on;

    TRIBE_Diamond_Map_View();

    ~TRIBE_Diamond_Map_View();

    void set_redraw(TPanel::RedrawMode redraw_mode);

    void draw_objects();
    void draw_object(short col, short row, char color, short size, RGE_Static_Object *game_obj);
};
