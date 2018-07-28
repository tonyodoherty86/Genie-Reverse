
/**
 * @file    Engine\RGE\DopplegangerCreator.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Doppleganger_Creator
{
public:

    RGE_Player *owner;

    int allocated_size;
    int active_size;

    RGE_Static_Object **Objects;

    unsigned int **Map_Addresses;
    unsigned int *Last_Map_Value;

    int *Object_ids;

    RGE_Doppleganger_Creator(RGE_Player *player, int initial_size);

    ~RGE_Doppleganger_Creator();

    int add_doppleganger_check(RGE_Static_Object *theObj, unsigned int *UMV_addr);
    int remove_doppleganger_check(RGE_Static_Object *theObj);
    void perform_doppleganger_checks();
    void expand_allocations(int grow_size);
};
