
/**
 * @file    Engine\TRB\Triggers.hpp
 * @author  Yvan Burrie
 * @date    2018/08/03
 * @version 1.0
 */

class TRIBE_Triggers
{
public:

    RGE_Game_World *world;

    char flash_objectives;

    ConditionControlsHeader *condition_controls;

    TRIBE_Trigger_Effect_Controls *effect_controls;

    TRIBE_Trigger **list;

    int *triggers_order;

    int num_triggers,
        max_triggers;

    int counter;

    int obj_curr_order,
        obj_curr_index,
        obj_next_order;
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
    int state;

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

struct TRIBE_Trigger_Effect_Data
{
    int AIScriptGoal,
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

struct TRIBE_Trigger_Condition
{
    ConditionControlsHeader *ConditionControls;

    int type;

    int id;

    TRIBE_Trigger_Condition_Data data;
};

struct ConditionControlsData
{
    char Quantity,
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

struct ConditionControlsHeader
{
    ConditionControlsData *type[20];
};

struct TRIBE_Trigger_Condition_Data
{
    int Quantity,
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
