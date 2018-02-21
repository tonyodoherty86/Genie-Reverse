
/**
 * @file    Engine\RGE\Action.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Action
{
public:

	// 4
	short action_type;
	// 8
	RGE_Action_Object *obj;
	// 12
	char state;
	// 16
    RGE_Static_Object *target_obj;
	// 20
    RGE_Static_Object *target_obj2;
	// 24
	int targetID = -1;
	// 28
	int target2ID = -1;
	// 32, 36, 40
	float target_x,
	      target_y,
	      target_z;
	// 44
	float timer;
	// 48
	RGE_Task *task; // short TaskId = -1;
	// 52
	void *sub_actions;
	// 56
	RGE_Sprite *sprite; // short SpriteId = -1;
	// 60
	char subActionValue;
	// 61
	char target_moved;
	// 64

    RGE_Action(int infile, RGE_Action_Object *obj_in, int do_setup);
    RGE_Action(RGE_Action_Object *obj_in, int do_setup);

    ~RGE_Action();

    int setup(int infile, RGE_Action_Object *obj_in);
    int setup(RGE_Action_Object *obj_in);

    void create_action_list(RGE_Action_Object *obj_in);

    void rehook();

    void save(int outfile);

    short type();

    int stop();
    int move_to(RGE_Static_Object *obj_in, float x, float y, float z);
    int work(RGE_Static_Object *obj_in, float x, float y, float z);
    char attack_response(RGE_Static_Object *obj_in);
    char relation_response(int player_id, char relation);

    void set_state(char new_state);

    char inside_obj_update();
    char idle_update();
    char update();

    void set_target_obj(RGE_Static_Object *new_obj);
    void set_target_obj2(RGE_Static_Object *new_obj);

    void copy_obj(RGE_Master_Action_Object *source);

    void get_state_name(char *state_name);

    double targetX(),
           targetY(),
           targetZ();

    char subAction();
    void setSubAction(char v);

    RGE_Static_Object *get_target_obj();
    RGE_Static_Object *get_target_obj2();
};
