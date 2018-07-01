
/**
 * @file    Engine\TRB\Action.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TRIBE_Action : public RGE_Action
{
public:

    TRIBE_Action(
        int infile,
        RGE_Action_Object *obj_in,
        bool do_setup);

    TRIBE_Action(
        RGE_Action_Object *obj_in,
        bool do_setup);

    ~TRIBE_Action();

    bool setup(
        int infile,
        RGE_Action_Object *obj_in);

    bool setup(
        RGE_Action_Object *obj_in);

    void create_action_list(
        RGE_Action_Object *obj_in);
};
