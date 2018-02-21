
/**
 * @file    Engine\RGE\View.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_View : public TPanel
{
public:

    TDrawArea *cur_render_area;
    int calc_draw_count;

    RGE_Game_World *world;
    RGE_Player *player;
    RGE_Map *map;

    short tile_wid;
    short tile_hgt;
    short tile_half_wid;
    short tile_half_hgt;
    short elev_hgt;

    short render_rect_wid;
    short render_rect_hgt;

    short max_col_num;
    short max_row_num;

    short center_scr_col;
    short center_scr_row;
    short center_scr_col_offset;
    short center_scr_row_offset;
    short center_map_col;
    short center_map_row;

    short start_scr_col;
    short start_scr_row;
    short start_map_col;
    short start_map_row;

    int map_scr_x_offset;
    int map_scr_y_offset;

    float last_view_x;
    float last_view_y;

    char function_mode;
    char function_parm;

    char render_terrain_mode;

    int sel_col1;
    int sel_row1;
    int sel_col2;
    int sel_row2;

    short save_paint_terrain;

    void *white_pen;
    void *red_pen;
    void *hollow_brush;

    TShape *border_line_shape;

    char scroll_action;

    int mouse_last_x;
    int mouse_last_y;

    RGE_Static_Object *movable_object;

    TSpan_List_Manager *Terrain_Clip_Mask;
    TSpan_List_Manager *Terrain_Fog_Clip_Mask;
    TSpan_List_Manager *Master_Clip_Mask;

    struct Tile_FogEdge_Table **Tile_Edge_Tables;
    struct Tile_BlackEdge_Table **Black_Edge_Tables;

    RECT OverlaidPanel;
    int OverlaidPanelActive;

    char EdgeNumber[256];

    int Limited_Render_Rect;
    int Use_Rect2;
    RECT Render_Rect1;
    RECT Render_Rect2;

    void **Float_Scroll_Offsets;
    int Float_Scroll_Offsets_Sz;
    int Float_X_Delta;
    int Float_Y_Delta;

    int Queued_Blits;
    struct Blit_Queue_Entry *Blit_Queue;
    int Blit_Queue_Size;
    int Blt_Queue_Allocated;
    int Current_Blit;
    int Blit_Offset_X;
    int Blit_Offset_Y;

    int real_old_map_col;
    int real_old_map_row;

    struct RGE_SPick_Info *pick_lists[5];
    int pick_list_size[5];

    TDrawArea *save_area1;

    char *LastRenderBits;
    void **RenderOffsets;
    int LastRenderSize;

    DClipInfo_List *prior_objs;
    DClipInfo_List *futur_objs;

    int UC_ObjectTouched;
    int UC_TouchedObj;
    unsigned int UC_StartTime;
    unsigned int UC_ElapsedTime;

    TMessagePanel *message_panel;

    struct Ov_Sprite_Draw_Rec *extra_sprites;

    struct DisplaySelectedObjRec *DispSel_List;

    int DispSel_List_Size;
    int DispSel_List_Max;
};

struct Tile_FogEdge_Table
{
    VSpanMiniList *normal_draw;
    VSpanMiniList *fog_draw;
};

struct Tile_BlackEdge_Table
{
    VSpanMiniList *black_UNdraw;
};

struct Blit_Queue_Entry
{
    RECT src;
    RECT dest;
};

struct RGE_SPick_Info
{
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;

    RGE_SPick_Info *next;
    RGE_SPick_Info *prev;
};

struct Ov_Sprite_Draw_Rec
{
    Ov_Sprite_Draw_Rec *next;
    Ov_Sprite_Draw_Rec *prev;
    TShape *theShape;
    int thefacet;
    int world_x;
    int world_y;
    int flags;
    int drawLevel;
    int displayfunction;
    unsigned int LastDrawTime;
    unsigned int DrawTimeInterval;
    char *colortable;
};

struct DisplaySelectedObjRec
{
    int active;
    int id;
    unsigned int start_time;
    unsigned int duration;
    int select_type;
};
