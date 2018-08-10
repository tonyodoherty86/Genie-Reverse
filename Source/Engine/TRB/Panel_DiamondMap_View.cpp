
/**
 * @file    Engine\TRB\Panel_DiamondMap_View.cpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

void TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View()
{
    RGE_Diamond_Map_View::RGE_Diamond_Map_View();

    this->last_attack_time = 0;
    this->flash_on = 0;
}

void TRIBE_Diamond_Map_View::set_redraw( TPanel::RedrawMode redraw_mode )
{
    this->set_redraw(redraw_mode);

    if ( redraw_mode && this->visible && this->active ){
        this->parent_panel->set_map_buttons_redraw(redraw_mode);
    }
}

void TRIBE_Diamond_Map_View::draw_objects()
{
    unsigned int v2 = debug_timeGetTime();
    if ( v2 - this->last_attack_time >= 0x14D )
    {
        this->flash_on = this->flash_on == 0;
        this->last_attack_time = v2;
    }
    RGE_Diamond_Map::draw_objects();
}

void TRIBE_Diamond_Map_View::draw_object(
    short col,
    short row,
    char color,
    short size,
    RGE_Static_Object *game_obj)
{
    if ( this->draw_objects_mode == 4 ){
        color = this->flash_on != 0 ? 86 : -1;
    }
    this->draw_object(col, row, color, size, game_obj);
}
