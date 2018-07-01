
/**
 * @file    Engine\TRB\ActionMakeObj.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

class TRIBE_Action_Make_Obj : public RGE_Action
{
public:

    short obj_id;

    float work_done;

    int unique_id;

    bool pre_paid;

    TRIBE_Action_Make_Obj(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Make_Obj(
        RGE_Action_Object *obj_in,
        short id,
        int uniqueID,
        bool paid);

    ~TRIBE_Action_Make_Obj();

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    char place_obj(RGE_Static_Object **rObj);

    int stop();

    void get_info(
        short *id,
        short *progress,
        char *name,
        short name_size);
};
