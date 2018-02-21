
/**
 * @file    Engine\RGE\DiamondMap.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Diamond_Map : TPanel
{
public:
    class RGE_Game_World *world;
    class RGE_Player *player;
    class RGE_Map *map;

    int all_visible;
    int render_all;
    int mouse_last_x;
    int mouse_last_y;
    int repos_mouse;

    RECT view_rect;

    class RGE_Player *last_player;
    class RGE_Map_Image_Line *map_image_lines;
    class RGE_Map_Tile_Row *map_tile_rows;

    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;

    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;

    short map_tile_draw_hgt;
    short map_tile_draw_wid;

    short view_col;
    short view_row;

    class RGE_View *main_view;

    int scrolling;
    char fog_color;
    int draw_objects_mode;
    unsigned int cur_player_bit;

    int own_save_area;
    class TDrawArea *save_area;

    RGE_Diamond_Map();
    ~RGE_Diamond_Map();

    int setup(TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, int color_in, int all_visible_in, TDrawArea *save_area_in);

    int set_bitmap(char *map_bmp, int res_id);
    void set_world(RGE_Game_World *world_in);
    void set_player(RGE_Player *player_in);
    void set_redraw(TPanel::RedrawMode redraw_mode);

    void delete_surfaces();
    void create_surfaces();

    void draw();

    void clear_image();
    void copy_image();

    void draw_all_tiles();
    void draw_explored_tiles();
    void draw_tile(int col, int row, int fog, short override_color);
    void draw_selected_area();
    void draw_objects();
    void draw_visible_object(RGE_Static_Object *game_obj, char color1, char color2);
    void draw_object(short col, short row, char color, short size, RGE_Static_Object *game_obj);
    void draw_clipped_horz_line(short x, short y, short len, char color, RGE_Map_Image_Line *image_line);
    void draw_view_rect();

    int pick_tile(int x, int y, short *col, short *row, RGE_Tile **tile);

    int handle_size(HWND win_wid, int win_hgt);

    void start_scroll_view(int x, int y);
    void handle_scroll_view(int x, int y);
    void end_scroll_view();
    int is_inside(int x, int y);
};
