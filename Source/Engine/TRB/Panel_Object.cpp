
/**
 * @file    Engine\TRB\Panel_Object.cpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TRIBE_Panel_Object : public TPanel
{
public:

    void *font;

    int font_wid,
        font_hgt;

    TShape *health_pic,
           *item_pic,
           *unit_pics,
           **bldg_pics;

    TRIBE_Player *player;

    RGE_Static_Object *game_obj;

    time_t idle_time,
           idle_interval;

    char mode;

    RGE_Master_Static_Object *save_obj_type;

    RGE_Sprite *save_sprite;

    short save_attr_type;
    float save_attr_amount;
    char save_object_state;
    float save_build_pts;

    RGE_Object_Node *save_list;

    short save_number_of_objects;
    char save_can_debark;
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    char save_facet;
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    char save_selected_group;
    RGE_Player *save_owner;
    int save_age;
    char save_have_action;
    int save_score[9];
    int save_farm_amt;

    TRIBE_Panel_Object(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        TShape *unit_pics_in,
        TShape **bldg_pics_in,
        TRIBE_Player *player_in);

    ~TRIBE_Panel_Object();

    void set_player(TRIBE_Player *player_in);
    void set_object(RGE_Static_Object *game_obj_in);
    void set_mode(char mode_in);
    char get_mode();

    void draw();
    void draw_score();
    void draw_item(int row, int pic_index, TRIBE_Panel_Object::ValueType val_type, int val1, int val2);

    int handle_idle();

    void save_object_info();

    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
};
