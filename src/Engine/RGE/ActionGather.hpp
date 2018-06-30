
/**
 * @file    Engine\RGE\ActionGather.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

class RGE_Action_Gather : public RGE_Action
{
public:

    /**
     * Offset: 64.
     */
    int targetType = -1;

    /**
     * Offset: 68, 69.
     */
	char number_stops = 0,
	     current_stop = 0;

    /**
     * Offset: 72.
     */
	float time_per_stop = 0.0;

    /**
     * Offset: 76.
     */
	unsigned int current_stop_time = 0;

    /**
     * Offset: 80, 81.
     */
	unsigned char last_stop_x = 0,
                  last_stop_y = 0;

    /**
     * Offset: 82.
     */
	bool depositing = false;

    /**
     * Offset: 84, 88.
     */
	float deposit_x = -1.0,
	      deposit_y = -1.0;

    RGE_Action_Gather(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Gather(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    RGE_Action_Gather(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~RGE_Action_Gather();

    void save(
        int outfile);

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();

    RGE_Sprite *get_move_sprite();
    RGE_Sprite *get_wait_sprite();

    int stop();

    int move_to(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);

    int work(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);
};
