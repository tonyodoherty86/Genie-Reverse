
/**
 * @file    Engine\TRB\Triggers.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TRIBE_Triggers
{
public:

    RGE_Game_World *world;

    char flash_objectives;

    struct TRIBE_Trigger_Condition_Control *condition_controls;

    struct TRIBE_Trigger_Effect_Controls *effect_controls;

    class TRIBE_Trigger **list;

    int *triggers_order;

    int num_triggers,
        max_triggers;

    int counter;

    int obj_curr_order,
        obj_curr_index,
        obj_next_order;
};

struct TRIBE_Trigger_Condition_Data
{
    int
        Quantity,
        Resource,
        SetObject,
        NextObject,
        ObjectConstant,
        SourcePlayer,
        Technology,
        Timer,
        Trigger,
        AreaXFROM,
        AreaYFROM,
        AreaXTO,
        AreaYTO,
        ObjectGroup,
        ObjectType,
        AISignal;
};

struct TRIBE_Trigger_Effect_Data
{
    int
        AIScriptGoal,
        Quantity,
        Resource,
        Diplomacy,
        SetObjects,
        NextObject,
        ObjectConstant,
        SourcePlayer,
        TargetPlayer,
        Technology,
        StringTableID,
        SoundResourceID,
        Timer,
        Trigger,
        LocationX,
        LocationY,
        AreaXFROM,
        AreaYFROM,
        AreaXTO,
        AreaYTO,
        ObjectGroup,
        ObjectType,
        Number;
};

class TRIBE_Trigger
{
public:

    enum Sate
    {
        Disabled = 0,
        Ready    = 1,
        Running  = 2,
        Expired  = 3,
    }
    state;

    char loop;

    char obj_shown;

    int obj_order;

    char *obj_desc_text;

    int obj_desc_id = -1;

    char *name;

    TRIBE_Trigger_Condition_Data **conditions_list;

    int *conditions_order;

    int num_conditions;

    int max_conditions;

    TRIBE_Trigger_Effect_Data **effects_list;

    int *effects_order;

    int num_effects;

    int max_effects;

    int timer;

    TRIBE_Triggers *triggers;
};

class TRIBE_Trigger_Effect
{
public:

    TRIBE_Trigger_Effect_Controls *EffectControls;

    int type;

    int id;

    TRIBE_Trigger_Effect_Data data;

    int *selected_objects;

    char *text;

    char *sound;
};

struct TRIBE_Trigger_Condition_Check
{
    char
        Quantity,
        Resource,
        SetObject,
        NextObject,
        ObjectConstant,
        SourcePlayer,
        Technology,
        Timer,
        Trigger,
        AreaXFROM,
        AreaYFROM,
        AreaXTO,
        AreaYTO,
        ObjectGroup,
        ObjectType,
        AISignal;
};

struct TRIBE_Trigger_Effect_Check
{
    char
        AIScriptGoal,
        Quantity,
        Resource,
        Diplomacy,
        SetObjects,
        NextObject,
        ObjectConstant,
        SourcePlayer,
        TargetPlayer,
        Technology,
        StringTableID,
        SoundResourceID,
        Timer,
        Trigger,
        LocationX,
        LocationY,
        AreaXFROM,
        AreaYFROM,
        AreaXTO,
        AreaYTO,
        ObjectGroup,
        ObjectType,
        Number;
};

struct TRIBE_Trigger_Effect_Controls
{
    TRIBE_Trigger_Effect_Check *type[30];
};

struct TRIBE_Trigger_Condition
{
    TRIBE_Trigger_Condition_Control *ConditionControls;

    int type;

    int id;

    TRIBE_Trigger_Condition_Data data;
};

struct TRIBE_Trigger_Condition_Control
{
    TRIBE_Trigger_Condition_Check *type[20];
};
