
/**
 * @file    Engine\TRB\Triggers.cpp
 * @author  Yvan Burrie
 * @date    2018/08/03
 * @version 1.0
 */

TRIBE_Trigger *TRIBE_Trigger::TRIBE_Trigger( TRIBE_Triggers *triggers )
{
    this->triggers = triggers;
}

TRIBE_Trigger *TRIBE_Trigger::TRIBE_Trigger( int infile, int triggers )
{
    int *num_effects; // ebp@1
    char *looping; // ebx@1
    TRIBE_Triggers *trigger_header; // eax@1
    char *obj_desc_text; // eax@4
    int obj_desc_size; // edx@4
    char *name_text; // eax@6
    int name_size; // ecx@6
    int effect_id; // ebx@9
    bool zero_conditions_or_effects; // zf@9
    bool invalid_condition_or_effect; // sf@9
    TRIBE_Trigger_Effect_Controls *effect_controls; // eax@11
    TRIBE_Trigger_Effect *effect_header_handle; // eax@11
    int j; // ebx@15
    int i; // eax@18
    int *num_conditions; // ebx@20
    int condition_id; // ebp@22
    ConditionControlsHeader *condition_controls; // eax@24
    TRIBE_Trigger_Condition *condition_data_handle; // eax@24
    int l; // ebp@28
    int k; // eax@31
    TRIBE_Trigger_Effect *effect_header; // [sp+20h] [bp+4h]@10
    TRIBE_Trigger_Condition *condition_data; // [sp+20h] [bp+4h]@23

    num_effects = &this->num_effects;
    looping = &this->loop;

    trigger_header = triggers;

    this->triggers = trigger_header;

    rge_read(infile, &this->state, 4);

    rge_read(infile, &this->loop, 1);

    rge_read(infile, &this->obj_desc_id, 4);
    rge_read(infile, &this->obj_shown, 1);
    rge_read(infile, &this->obj_order, 4);

    if( TRIGGERS_SYSTEM_VERSION >= 1.6 ){
        rge_read(infile, &this->timer, 4);
    }

    rge_read(infile, &triggers, 4);
    if( triggers > 0 ){
        obj_desc_text = calloc(1u, triggers);
        obj_desc_size = triggers;
        this->obj_desc_text = obj_desc_text;
        rge_read(infile, obj_desc_text, obj_desc_size);
    }

    rge_read(infile, &triggers, 4);
    if( triggers > 0 ){
        name_text = calloc(1u, triggers);
        name_size = triggers;
        this->name = name_text;
        rge_read(infile, name_text, name_size);
    }

    rge_read(infile, num_effects, 4);
    if( *num_effects > 0 ){
        this->effects_list = void[num_effects];
        this->effects_order = void[num_effects];
    }
    effect_id = 0;
    zero_conditions_or_effects = *num_effects == 0;
    invalid_condition_or_effect = *num_effects < 0;
    this->max_effects = *num_effects;
    if( !invalid_condition_or_effect && !zero_conditions_or_effects )
    {
        do
        {
            effect_header = operator new(116u);
            if( effect_header )
            {
                effect_controls = GetEffectControls(this->triggers);
                effect_header_handle = TRIBE_Trigger_Effect::TRIBE_Trigger_Effect(
                                                                 effect_header,
                                                                 infile,
                                                                 effect_controls,
                                                                 effect_id);
            }
            else
            {
                effect_header_handle = 0;
            }
            this->effects_list[effect_id] = effect_header_handle;

            effect_id++;
        }
        while ( effect_id < num_effects );
    }

    if( TRIGGERS_SYSTEM_VERSION < 1.3 ){

        for( i = 0; i < num_effects; i++ ){
            this->effects_order[i] = i;
        }
    }else{

        for( j = 0; j < *num_effects; j++ ){
            rge_read(infile, &this->effects_order[j], 4);
        }
    }
    num_conditions = &this->num_conditions;

    rge_read(infile, &this->num_conditions, 4);
    if( this->num_conditions > 0 ){
        this->conditions_list = operator new(4 * this->num_conditions);
        this->conditions_order = operator new(4 * *num_conditions);
    }
    condition_id = 0;
    zero_conditions_or_effects = *num_conditions == 0;
    invalid_condition_or_effect = *num_conditions < 0;
    this->max_conditions = *num_conditions;
    if( !invalid_condition_or_effect && !zero_conditions_or_effects )
    {
        do
        {
            condition_data = operator new(76u);
            if( condition_data )
            {
                condition_controls = TPanel::previousModalPanel(this->triggers);
                condition_data_handle = TRIBE_Trigger_Condition::TRIBE_Trigger_Condition(
                                                                    condition_data,
                                                                    infile,
                                                                    condition_controls,
                                                                    condition_id);
            }
            else
            {
                condition_data_handle = 0;
            }
            this->conditions_list[++condition_id - 1] = condition_data_handle;
        }
        while ( condition_id < *num_conditions );
    }

    if( TRIGGERS_SYSTEM_VERSION < 1.3 ){
        for( k = 0; k < *num_conditions; ++k ){
            this->conditions_order[k] = k;
        }
    }else{
        for( l = 0; l < *num_conditions; ++l ){
            rge_read(infile, &this->conditions_order[l], 4);
        }
    }
}

TRIBE_Trigger::~TRIBE_Trigger()
{
    if( this->obj_desc_text ){
        free(this->obj_desc_text);
    }

    if( this->name ){
        free(this->name);
    }

    while( this->num_effects > 0 ){
        this->del_effect(0);
    }

    if( this->max_effects > 0 ){
        delete this->effects_list;
        delete this->effects_order;
    }

    while( this->num_conditions > 0 ){
        this->del_condition(0);
    }

    if( this->max_conditions > 0 ){
        delete this->conditions_list;
        delete this->conditions_order;
    }
}

void TRIBE_Trigger::save( int outfile )
{
    int _hFile; // ebx@1
    TRIBE_Trigger *_this; // esi@1
    const char *trigger_desc; // edi@1
    int effect; // ebp@1
    const char *trigger_name; // edi@6
    int *num_effects; // edi@11
    int i; // ebp@13
    int *num_conditions; // edi@15
    int condition; // ebp@15
    int j; // ebp@17

    _hFile = outfile;
    _this = this;

    rge_write(outfile, &this->state, 4);
    rge_write(outfile, &this->loop, 1);
    rge_write(outfile, &this->obj_desc_id, 4);
    rge_write(outfile, &this->obj_shown, 1);
    rge_write(outfile, &this->obj_order, 4);
    rge_write(outfile, &this->timer, 4);

    trigger_desc = _this->obj_desc_text;
    effect = 0;

    if( trigger_desc ){
        outfile = strlen(trigger_desc);
        outfile++;
    }else{
        outfile = nullptr;
    }
    rge_write(outfile, &outfile, 4);
    if( outfile > 0 )
        rge_write(outfile, _this->obj_desc_text, outfile);
    trigger_name = _this->name;
    if( trigger_name )
    {
        outfile = strlen(trigger_name);
        ++outfile;
    }
    else
    {
        outfile = 0;
    }
    rge_write(outfile, &outfile, 4);
    if( outfile > 0 )
        rge_write(outfile, _this->name, outfile);
    num_effects = &_this->num_effects;
    rge_write(outfile, &_this->num_effects, 4);
    if( this->num_effects > 0 ){
        do
            TRIBE_Trigger_Effect::save(_this->effects_list[effect++], _hFile);
        while ( effect < *num_effects );
    }
    for( i = 0; i < *num_effects; ++i )
        rge_write(outfile, &_this->effects_order[i], 4);
    num_conditions = &_this->num_conditions;
    rge_write(outfile, &_this->num_conditions, 4);
    condition = 0;
    if( this->num_conditions > 0 ){
        do
            TRIBE_Trigger_Condition::save(&_this->conditions_list[condition++]->Quantity, _hFile);
        while ( condition < *num_conditions );
    }
    for( j = 0; j < *num_conditions; ++j )
        rge_write(outfile, &_this->conditions_order[j], 4);
}

void TRIBE_Trigger::run( int Timer )
{
    int num_conditions; // eax@2
    int condition; // edi@2
    int cond_result; // eax@3
    char objective; // al@7
    int effect; // edi@11
    char looping; // al@13
    char _objective; // al@14

    if( this->state == 1 )
    {
        num_conditions = this->num_conditions;
        condition = 0;
        this->timer += Timer;
        if( num_conditions > 0 )
        {
            do
            {
                cond_result = TRIBE_Trigger_Condition::run(this->conditions_list[condition], this->timer, this->triggers->world);
                if( !cond_result )
                    break;
                if( cond_result == 2 )
                {
                    objective = this->obj_shown;
                    this->state = 3;
                    if( objective && !this->triggers->flash_objectives )
                    {
                        (*(rge_base_game->vfptr + 17))(138, -1, -1, -1, 0);
                        this->triggers->flash_objectives = 1;
                    }
                    break;
                }
                ++condition;
            }
            while ( condition < this->num_conditions );
        }
        if( condition == this->num_conditions )
        {
            for( effect = 0; effect < this->num_effects; ++effect )
                TRIBE_Trigger_Effect::run(this->effects_list[effect], this->triggers->world);
            looping = this->loop;
            this->timer = 0;
            if( !looping )
            {
                _objective = this->obj_shown;
                this->state = 2;
                if( _objective )
                {
                    if( !this->triggers->flash_objectives )
                    {
                        (*(rge_base_game->vfptr + 17))(138, -1, -1, -1, 0);
                        this->triggers->flash_objectives = 1;
                    }
                }
            }
        }
    }
}

//----- (00438D10) --------------------------------------------------------
TRIBE_Trigger_Condition *TRIBE_Trigger::new_condition(int a2)
{
    TRIBE_Trigger *v2; // ebx@1
    TRIBE_Trigger_Condition *v3; // esi@1
    int v4; // ST08_4@2
    ConditionControlsHeader *v5; // eax@2
    TRIBE_Trigger_Condition *v6; // esi@2
    TRIBE_Trigger_Condition_Data **v7; // ebp@6
    int *v8; // eax@6
    int v9; // ecx@6
    int v10; // ecx@8
    int v11; // edx@8
    TRIBE_Trigger_Condition *v13; // [sp+Ch] [bp-14h]@2
    int *v14; // [sp+10h] [bp-10h]@6

    v2 = this;
    v3 = operator new(0x4Cu);
    if( v3 )
    {
        v4 = v2->num_conditions;
        v5 = TPanel::previousModalPanel(v2->triggers);
        v6 = TRIBE_Trigger_Condition::TRIBE_Trigger_Condition(v3, v5, v4);
        v13 = v6;
    }
    else
    {
        v13 = 0;
        v6 = 0;
    }
    if( v6 )
    {
        if( v2->num_conditions >= v2->max_conditions )
        {
            do
            {
                v7 = operator new(4 * v2->max_conditions + 40);
                v8 = operator new(4 * v2->max_conditions + 40);
                v9 = v2->max_conditions;
                v14 = v8;
                if( v9 > 0 )
                {
                    qmemcpy(v7, v2->conditions_list, 4 * v9);
                    qmemcpy(v8, v2->conditions_order, 4 * v2->max_conditions);
                    operator delete(v2->conditions_list);
                    operator delete(v2->conditions_order);
                    v6 = v13;
                    v8 = v14;
                }
                v10 = v2->num_conditions;
                v11 = v2->max_conditions + 10;
                v2->conditions_order = v8;
                v2->conditions_list = v7;
                v2->max_conditions = v11;
            }
            while ( v10 >= v11 );
        }
        v2->conditions_list[v2->num_conditions] = v6;
        v2->conditions_order[v2->num_conditions] = v2->num_conditions;
        ++v2->num_conditions;
    }
    return v6;
}

//----- (00438E50) --------------------------------------------------------
TRIBE_Trigger_Condition_Data *TRIBE_Trigger::get_condition(int index)
{
    TRIBE_Trigger_Condition_Data *result; // eax@3

    if( index >= this->num_conditions || index < 0 )
        result = 0;
    else
        result = this->conditions_list[index];
    return result;
}

//----- (00438E70) --------------------------------------------------------
bool TRIBE_Trigger::del_condition(int index)
{
    TRIBE_Trigger *v2; // esi@1
    TRIBE_Trigger_Condition_Data **v3; // eax@3
    TRIBE_Trigger_Condition_Data *v4; // edi@3
    int i; // eax@5
    int v6; // ecx@7
    int v7; // edx@7
    int v8; // eax@7
    int *v9; // edi@8
    int v10; // edx@15
    int v11; // eax@15
    int v12; // edx@15
    int *v13; // eax@16
    int v14; // ecx@16
    int *v15; // eax@16
    bool result; // al@19

    v2 = this;
    if( index >= this->num_conditions || index < 0 )
    {
        result = 0;
    }
    else
    {
        v3 = this->conditions_list;
        v4 = v3[index];
        if( v4 )
        {
            TRIBE_Screen_Game::command_trade(v3[index]);
            operator delete(v4);
        }
        for( i = index; i < v2->num_conditions; v2->conditions_list[i - 1] = v2->conditions_list[i] )
            ++i;
        v6 = v2->num_conditions;
        v7 = 0;
        v8 = v2->num_conditions;
        if( v6 > 0 )
        {
            v9 = v2->conditions_order;
            while ( *v9 != index )
            {
                ++v7;
                ++v9;
                if( v7 >= v6 )
                    goto LABEL_13;
            }
            v8 = v7;
        }
LABEL_13:
        if( v8 < v6 )
        {
            do
            {
                ++v8;
                v2->conditions_order[v8 - 1] = v2->conditions_order[v8];
            }
            while ( v8 < v2->num_conditions );
        }
        v10 = v2->num_conditions - 1;
        v2->num_conditions = v10;
        v11 = v10;
        v12 = 0;
        if( v11 > 0 )
        {
            do
            {
                v13 = v2->conditions_order;
                v14 = v13[v12];
                v15 = &v13[v12];
                if( v14 >= index )
                    *v15 = v14 - 1;
                ++v12;
            }
            while ( v12 < v2->num_conditions );
        }
        result = 1;
    }
    return result;
}

//----- (00438F30) --------------------------------------------------------
char *TPanel::panelName(TPanel *this)
{
    return this->panelNameValue;
}

//----- (00438F40) --------------------------------------------------------
bool TRIBE_Trigger::set_condition_order(int index, int order)
{
    int v3; // edx@1
    int v4; // esi@2
    int v5; // edi@6
    int *v6; // esi@7
    int v7; // ebx@7
    int *v8; // esi@7
    int v10; // edi@10

    v3 = index;
    if( index < 0 )
        return 0;
    v4 = this->num_conditions;
    if( index >= v4 || order < 0 || order >= v4 )
        return 0;
    if( order < index )
    {
        v5 = this->conditions_order[index];
        if( index > order )
        {
            do
            {
                v6 = this->conditions_order;
                v7 = v6[v3 - 1];
                v8 = &v6[v3--];
                *v8 = v7;
            }
            while ( v3 > order );
        }
        this->conditions_order[order] = v5;
        return 1;
    }
    if( order <= index )
        return 0;
    v10 = this->conditions_order[index];
    if( index < order )
    {
        do
        {
            ++v3;
            this->conditions_order[v3 - 1] = this->conditions_order[v3];
        }
        while ( v3 < order );
    }
    this->conditions_order[order] = v10;
    return 1;
}

//----- (00438FD0) --------------------------------------------------------
int TRIBE_Trigger::num_effects()
{
    return this->num_effects;
}

//----- (00438FE0) --------------------------------------------------------
TRIBE_Trigger_Effect *TRIBE_Trigger::new_effect(int a2)
{
    TRIBE_Trigger *v2; // ebx@1
    TRIBE_Trigger_Effect *v3; // esi@1
    int v4; // ST08_4@2
    TRIBE_Trigger_Effect_Controls *v5; // eax@2
    TRIBE_Trigger_Effect *v6; // esi@2
    TRIBE_Trigger_Effect_Data **v7; // ebp@6
    int *v8; // eax@6
    int v9; // ecx@6
    int v10; // ecx@8
    int v11; // edx@8
    TRIBE_Trigger_Effect *v13; // [sp+Ch] [bp-14h]@2
    int *v14; // [sp+10h] [bp-10h]@6

    v2 = this;
    v3 = operator new(0x74u);
    if( v3 )
    {
        v4 = v2->num_effects;
        v5 = GetEffectControls(v2->triggers);
        v6 = TRIBE_Trigger_Effect::TRIBE_Trigger_Effect(v3, v5, v4);
        v13 = v6;
    }
    else
    {
        v13 = 0;
        v6 = 0;
    }
    if( v6 )
    {
        if( v2->num_effects >= v2->max_effects )
        {
            do
            {
                v7 = operator new(4 * v2->max_effects + 40);
                v8 = operator new(4 * v2->max_effects + 40);
                v9 = v2->max_effects;
                v14 = v8;
                if( v9 > 0 )
                {
                    qmemcpy(v7, v2->effects_list, 4 * v9);
                    qmemcpy(v8, v2->effects_order, 4 * v2->max_effects);
                    operator delete(v2->effects_list);
                    operator delete(v2->effects_order);
                    v6 = v13;
                    v8 = v14;
                }
                v10 = v2->num_effects;
                v11 = v2->max_effects + 10;
                v2->effects_order = v8;
                v2->effects_list = v7;
                v2->max_effects = v11;
            }
            while ( v10 >= v11 );
        }
        v2->effects_list[v2->num_effects] = v6;
        v2->effects_order[v2->num_effects] = v2->num_effects;
        ++v2->num_effects;
    }
    return v6;
}

//----- (00439120) --------------------------------------------------------
TRIBE_Trigger_Effect_Data *TRIBE_Trigger::get_effect(int index)
{
    TRIBE_Trigger_Effect_Data *result; // eax@3

    if( index >= this->num_effects || index < 0 )
        result = 0;
    else
        result = this->effects_list[index];
    return result;
}

//----- (00439140) --------------------------------------------------------
bool TRIBE_Trigger::del_effect(int index)
{
    TRIBE_Trigger *v2; // esi@1
    TRIBE_Trigger_Effect_Data **v3; // eax@3
    TRIBE_Trigger_Effect_Data *v4; // edi@3
    int i; // eax@5
    int v6; // ecx@7
    int v7; // edx@7
    int v8; // eax@7
    int *v9; // edi@8
    int v10; // edx@15
    int v11; // eax@15
    int v12; // edx@15
    int *v13; // eax@16
    int v14; // ecx@16
    int *v15; // eax@16
    bool result; // al@19

    v2 = this;
    if( index >= this->num_effects || index < 0 )
    {
        result = 0;
    }
    else
    {
        v3 = this->effects_list;
        v4 = v3[index];
        if( v4 )
        {
            TRIBE_Trigger_Effect::~TRIBE_Trigger_Effect(v3[index]);
            operator delete(v4);
        }
        for( i = index; i < v2->num_effects; v2->effects_list[i - 1] = v2->effects_list[i] )
            ++i;
        v6 = v2->num_effects;
        v7 = 0;
        v8 = v2->num_effects;
        if( v6 > 0 )
        {
            v9 = v2->effects_order;
            while ( *v9 != index )
            {
                ++v7;
                ++v9;
                if( v7 >= v6 )
                    goto LABEL_13;
            }
            v8 = v7;
        }
LABEL_13:
        if( v8 < v6 )
        {
            do
            {
                ++v8;
                v2->effects_order[v8 - 1] = v2->effects_order[v8];
            }
            while ( v8 < v2->num_effects );
        }
        v10 = v2->num_effects - 1;
        v2->num_effects = v10;
        v11 = v10;
        v12 = 0;
        if( v11 > 0 )
        {
            do
            {
                v13 = v2->effects_order;
                v14 = v13[v12];
                v15 = &v13[v12];
                if( v14 >= index )
                    *v15 = v14 - 1;
                ++v12;
            }
            while ( v12 < v2->num_effects );
        }
        result = 1;
    }
    return result;
}

//----- (00439200) --------------------------------------------------------
int *TRIBE_Trigger::get_effects_order()
{
    return this->effects_order;
}

//----- (00439210) --------------------------------------------------------
signed int sub_439210(int a2, int a3)
{
    int v3; // edx@1
    int v4; // esi@2
    int v5; // edi@6
    int *v6; // esi@7
    int v7; // ebx@7
    int *v8; // esi@7
    int v10; // edi@10

    v3 = a2;
    if( a2 < 0 )
        return 0;
    v4 = this->num_effects;
    if( a2 >= v4 || a3 < 0 || a3 >= v4 )
        return 0;
    if( a3 < a2 )
    {
        v5 = this->effects_order[a2];
        if( a2 > a3 )
        {
            do
            {
                v6 = this->effects_order;
                v7 = v6[v3 - 1];
                v8 = &v6[v3--];
                *v8 = v7;
            }
            while ( v3 > a3 );
        }
        this->effects_order[a3] = v5;
        return 1;
    }
    if( a3 <= a2 )
        return 0;
    v10 = this->effects_order[a2];
    if( a2 < a3 )
    {
        do
        {
            ++v3;
            this->effects_order[v3 - 1] = this->effects_order[v3];
        }
        while ( v3 < a3 );
    }
    this->effects_order[a3] = v10;
    return 1;
}

//----- (004392A0) --------------------------------------------------------
void TRIBE_Trigger::set_name(char *a2)
{
    getstring(&this->name, a2);
}

//----- (004392C0) --------------------------------------------------------
char TRIBE_Trigger::set_objectives_shown(char shown)
{
    char result; // al@1

    result = shown;
    this->obj_shown = shown;
    return result;
}

//----- (004392D0) --------------------------------------------------------
void TPanelSystem::setKeyboardOwner(TPanelSystem *this, TPanel *p)
{
    this->modalPanelValue = p;
}

//----- (004392E0) --------------------------------------------------------
int TRIBE_Trigger::set_objectives(char *text, int string_id)
{
    TRIBE_Trigger *v3; // esi@1
    int result; // eax@1

    v3 = this;
    getstring(&this->obj_desc_text, text);
    v3->obj_desc_id = string_id;
    return result;
}

//----- (00439300) --------------------------------------------------------
void TRIBE_Trigger::set_state(int state)
{
    TRIBE_Trigger *_this; // esi@1

    _this = this;
    if( this->state != state )
    {
        this->state = state;
        if( this->obj_shown )
        {
            if( !this->triggers->flash_objectives )
            {
                (*(rge_base_game->vfptr + 17))(138, -1, -1, -1, 0);
                _this->triggers->flash_objectives = 1;
            }
        }
    }
}

//----- (00439350) --------------------------------------------------------
char TRIBE_Trigger::set_loop(char loop)
{
    char result; // al@1

    result = loop;
    this->loop = loop;
    return result;
}

//----- (00439360) --------------------------------------------------------
int TRIBE_Trigger::get_name(int *out)
{
    int result; // eax@1

    result = this->name;
    *out = result;
    return result;
}

//----- (00439370) --------------------------------------------------------
char TRIBE_Trigger::is_objectives_shown()
{
    return this->obj_shown;
}

//----- (00439380) --------------------------------------------------------
TPanel *TPanel::previousModalPanel(TPanel *this)
{
    return this->previousModalPanelValue;
}

//----- (00439390) --------------------------------------------------------
int TRIBE_Trigger::get_objectives(char **text, int *string_id)
{
    int result; // eax@1

    *text = this->obj_desc_text;
    result = this->obj_desc_id;
    *string_id = result;
    return result;
}

//----- (004393B0) --------------------------------------------------------
int TRIBE_Trigger::get_state()
{
    return this->state;
}

//----- (004393C0) --------------------------------------------------------
char TRIBE_Trigger::is_loop()
{
    return this->loop;
}

//----- (004393D0) --------------------------------------------------------
int sub_4393D0(int a2)
{
    TRIBE_Trigger *_this; // edi@1
    int effect_id; // esi@1
    int result; // eax@1

    _this = this;
    effect_id = 0;
    result = this->num_effects;
    if( result > 0 )
    {
        do
        {
            sub_4383E0(_this->effects_list[effect_id], a2);
            result = _this->num_effects;
            ++effect_id;
        }
        while ( effect_id < result );
    }
    return result;
}

//----- (00439400) --------------------------------------------------------
bool TRIBE_Trigger::valid()
{
    int num_effects; // eax@1
    int effect; // edi@4
    int condition; // edi@7

    num_effects = this->num_effects;
    if( !num_effects && !this->num_conditions )
        return 0;
    effect = 0;
    if( num_effects > 0 )
    {
        while ( TRIBE_Trigger_Effect::valid(this->effects_list[effect], this->triggers->world, 0, 0, 0, 0, 0) )
        {
            if( ++effect >= this->num_effects )
                goto LABEL_7;
        }
        return 0;
    }
LABEL_7:
    condition = 0;
    if( this->num_conditions > 0 )
    {
        while ( TRIBE_Trigger_Condition::valid(this->conditions_list[condition], this->triggers->world, 0, 0, 0) )
        {
            if( ++condition >= this->num_conditions )
                return 1;
        }
        return 0;
    }
    return 1;
}

//----- (00439480) --------------------------------------------------------
TRIBE_Triggers *AllocTrigSec(void *game_world)
{
    TRIBE_Triggers *result; // eax@1

    this->world = game_world;
    this->list = 0;
    this->triggers_order = 0;
    this->num_triggers = 0;
    this->max_triggers = 0;
    this->condition_controls = 0;
    this->effect_controls = 0;
    this->counter = 0;
    this->flash_objectives = 0;
    AllocCondEffectMods(this);
    result = this;
    *&TRIGGERS_SYSTEM_VERSION = 1.6;
    return result;
}

//----- (004394D0) --------------------------------------------------------
TRIBE_Triggers *ReadTrigSec( int infile, RGE_Game_World *world )
{
    int *num_triggers; // edi@1
    char *flash_objectives; // ebx@1
    int trigger_id; // ebx@5
    bool zero_triggers; // zf@5
    bool negative_triggers; // sf@5
    TRIBE_Trigger *trigger_data; // eax@6
    TRIBE_Trigger *trigger_data_handle; // eax@7
    int j; // ebx@11
    int i; // eax@14

    num_triggers = &this->num_triggers;
    flash_objectives = &this->flash_objectives;
    this->world = world;
    this->max_triggers = 0;
    this->list = 0;
    this->triggers_order = 0;
    this->num_triggers = 0;
    this->condition_controls = 0;
    this->effect_controls = 0;
    this->counter = 0;
    this->flash_objectives = 0;
    AllocCondEffectMods(this);
    rge_read(infile, &TRIGGERS_SYSTEM_VERSION, 8);
    if( TRIGGERS_SYSTEM_VERSION >= 1.5 )
        rge_read(infile, flash_objectives, 1);
    rge_read(infile, num_triggers, 4);
    if( *num_triggers > 0 )
    {
        this->list = operator new(4 * *num_triggers);
        this->triggers_order = operator new(4 * *num_triggers);
    }
    trigger_id = 0;
    zero_triggers = *num_triggers == 0;
    negative_triggers = *num_triggers < 0;
    this->max_triggers = *num_triggers;
    if( !negative_triggers && !zero_triggers )
    {
        do
        {
            trigger_data = operator new(64u);
            if( trigger_data )
                trigger_data_handle = TRIBE_Trigger::TRIBE_Trigger(trigger_data, infile, this);
            else
                trigger_data_handle = 0;
            this->list[++trigger_id - 1] = trigger_data_handle;
        }
        while ( trigger_id < *num_triggers );
    }
    if( TRIGGERS_SYSTEM_VERSION < 1.4 ){
        for( i = 0; i < *num_triggers; ++i )
            this->triggers_order[i] = i;
    }else{
        for( j = 0; j < *num_triggers; ++j )
            rge_read(infile, &this->triggers_order[j], 4);
    }

    return this;
}

//----- (00439630) --------------------------------------------------------
void DeallocTrigSec( int TrigSecBuff )
{
    int _TrigSecBuff; // esi@1
    signed int condition; // edi@1
    signed int effect; // edi@3

    _TrigSecBuff = TrigSecBuff;
    condition = 0;
    do
    {
        operator delete(*(*(_TrigSecBuff + 8) + condition));
        condition += 4;
    }
    while ( condition < 80 );
    operator delete(*(_TrigSecBuff + 8));
    effect = 0;
    do
    {
        operator delete(*(*(_TrigSecBuff + 12) + effect));
        effect += 4;
    }
    while ( effect < 120 );
    operator delete(*(_TrigSecBuff + 12));
    while ( *(_TrigSecBuff + 24) > 0 )
        DeallocateTrigger(_TrigSecBuff, 0);
    if( *(_TrigSecBuff + 28) > 0 )
    {
        operator delete(*(_TrigSecBuff + 16));
        operator delete(*(_TrigSecBuff + 20));
    }
}

//----- (004396C0) --------------------------------------------------------
void WriteTrigSec(int outfile)
{
    int *num_triggers; // esi@1
    int trigger_id; // ebp@1
    int i; // ebp@3

    TRIGGERS_SYSTEM_VERSION = 1.6;
    rge_write(outfile, &TRIGGERS_SYSTEM_VERSION, 8);

    rge_write(outfile, &this->flash_objectives, 1);

    num_triggers = &this->num_triggers;
    rge_write(outfile, &this->num_triggers, 4);
    trigger_id = 0;
    if( this->num_triggers > 0 )
    {
        do
            TRIBE_Trigger::save(this->list[trigger_id++], outfile);
        while ( trigger_id < *num_triggers );
    }
    for( i = 0; i < *num_triggers; ++i )
        rge_write(outfile, &this->triggers_order[i], 4);
}

//----- (00439750) --------------------------------------------------------
void RunTrigSec()
{
    double sleep; // st7@1
    bool equal; // c0@1
    bool less; // c3@1
    int timer; // ebx@2
    int num_triggers; // eax@2
    int trigger; // edi@2

    sleep = *&this->world->numberObjectsValue + *&this->counter;
    *&this->counter = sleep;                                            // sleep += time_frame
    if( !equal && !less )                                                // sleep > 1.0
    {
        timer = sleep;
        num_triggers = this->num_triggers;
        trigger = 0;
        *&this->counter = sleep - timer;                        // sleep = 0
        if( num_triggers > 0 )
        {
            do
                TRIBE_Trigger::run(this->list[trigger++], timer);
            while ( trigger < this->num_triggers );
        }
    }
}

//----- (004397C0) --------------------------------------------------------
void AllocCondEffectMods()
{
    int i; // edi@1
    int condition_control; // eax@2
    int j; // edi@5
    int effect_control; // eax@6

    this->condition_controls = operator new(80u); // 20 conditions * sizeof(int)
    this->effect_controls = operator new(120u);     // 30 effects * sizeof(int)
    i = 0;
    do
    {
        this->condition_controls->type[i] = operator new(16u);
        condition_control = 0;
        do
            *(this->condition_controls->type[i] + ++condition_control - 1) = 0;
        while ( condition_control < 16 );
        ++i;
    }
    while ( i < 20 );
    j = 0;
    do
    {
        this->effect_controls->type[j] = operator new(23u);
        effect_control = 0;
        do
            *(this->effect_controls->type[j] + ++effect_control - 1) = 0;
        while ( effect_control < 23 );
        ++j;
    }
    while ( j < 30 );
    this->condition_controls->type[1]->SetObject = 1;
    this->condition_controls->type[1]->AreaXFROM = 1;
    this->condition_controls->type[1]->AreaYFROM = 1;
    this->condition_controls->type[1]->AreaXTO = 1;
    this->condition_controls->type[1]->AreaYTO = 1;
    this->condition_controls->type[2]->SetObject = 1;
    this->condition_controls->type[2]->NextObject = 1;
    this->condition_controls->type[3]->ObjectConstant = 2;
    this->condition_controls->type[3]->ObjectGroup = 2;
    this->condition_controls->type[3]->ObjectType = 2;
    this->condition_controls->type[3]->Quantity = 1;
    this->condition_controls->type[3]->SourcePlayer = 1;
    this->condition_controls->type[4]->ObjectConstant = 2;
    this->condition_controls->type[4]->ObjectGroup = 2;
    this->condition_controls->type[4]->ObjectType = 2;
    this->condition_controls->type[4]->Quantity = 1;
    this->condition_controls->type[4]->SourcePlayer = 1;
    this->condition_controls->type[5]->SourcePlayer = 1;
    this->condition_controls->type[5]->ObjectConstant = 2;
    this->condition_controls->type[5]->ObjectGroup = 2;
    this->condition_controls->type[5]->ObjectType = 2;
    this->condition_controls->type[5]->Quantity = 1;
    this->condition_controls->type[5]->AreaXFROM = 1;
    this->condition_controls->type[5]->AreaYFROM = 1;
    this->condition_controls->type[5]->AreaXTO = 1;
    this->condition_controls->type[5]->AreaYTO = 1;
    this->condition_controls->type[6]->SetObject = 1;
    this->condition_controls->type[7]->SetObject = 1;
    this->condition_controls->type[7]->SourcePlayer = 1;
    this->condition_controls->type[8]->Resource = 1;
    this->condition_controls->type[8]->Quantity = 1;
    this->condition_controls->type[8]->SourcePlayer = 1;
    this->condition_controls->type[9]->Technology = 1;
    this->condition_controls->type[9]->SourcePlayer = 1;
    this->condition_controls->type[10]->Timer = 1;
    this->condition_controls->type[11]->SetObject = 1;
    this->condition_controls->type[12]->AISignal = 1;
    this->condition_controls->type[13]->SourcePlayer = 1;
    this->condition_controls->type[14]->SetObject = 1;
    this->condition_controls->type[14]->NextObject = 2;
    this->condition_controls->type[14]->ObjectConstant = 2;
    this->condition_controls->type[14]->ObjectGroup = 2;
    this->condition_controls->type[14]->ObjectType = 2;
    this->condition_controls->type[15]->SetObject = 1;
    this->condition_controls->type[16]->SetObject = 1;
    this->condition_controls->type[17]->Technology = 1;
    this->condition_controls->type[17]->SourcePlayer = 1;
    this->condition_controls->type[18]->SetObject = 1;
    this->condition_controls->type[18]->Quantity = 1;
    this->condition_controls->type[19]->Quantity = 1;
    this->effect_controls->type[1]->SourcePlayer = 1;
    this->effect_controls->type[1]->TargetPlayer = 1;
    this->effect_controls->type[1]->Diplomacy = 1;
    this->effect_controls->type[2]->SourcePlayer = 1;
    this->effect_controls->type[2]->Technology = 1;
    this->effect_controls->type[3]->SourcePlayer = 1;
    this->effect_controls->type[3]->StringTableID = 2;
    this->effect_controls->type[3]->SoundResourceID = 2;
    this->effect_controls->type[20]->StringTableID = 2;
    this->effect_controls->type[20]->SoundResourceID = 2;
    this->effect_controls->type[20]->Timer = 1;
    this->effect_controls->type[20]->Number = 2;
    this->effect_controls->type[21]->Number = 2;
    this->effect_controls->type[4]->SourcePlayer = 1;
    this->effect_controls->type[4]->SoundResourceID = 1;
    this->effect_controls->type[5]->SourcePlayer = 1;
    this->effect_controls->type[5]->TargetPlayer = 1;
    this->effect_controls->type[5]->Resource = 1;
    this->effect_controls->type[5]->Quantity = 1;
    this->effect_controls->type[6]->SetObjects = 1;
    this->effect_controls->type[7]->SetObjects = 1;
    this->effect_controls->type[8]->Trigger = 1;
    this->effect_controls->type[9]->Trigger = 1;
    this->effect_controls->type[10]->SourcePlayer = 1;
    this->effect_controls->type[10]->AIScriptGoal = 1;
    this->effect_controls->type[11]->SourcePlayer = 1;
    this->effect_controls->type[11]->ObjectConstant = 1;
    this->effect_controls->type[11]->LocationX = 1;
    this->effect_controls->type[11]->LocationY = 1;
    this->effect_controls->type[12]->SetObjects = 2;
    this->effect_controls->type[12]->SourcePlayer = 2;
    this->effect_controls->type[12]->AreaXFROM = 2;
    this->effect_controls->type[12]->AreaYFROM = 2;
    this->effect_controls->type[12]->AreaXTO = 2;
    this->effect_controls->type[12]->AreaYTO = 2;
    this->effect_controls->type[12]->ObjectConstant = 2;
    this->effect_controls->type[12]->ObjectGroup = 2;
    this->effect_controls->type[12]->ObjectType = 2;
    this->effect_controls->type[12]->NextObject = 2;
    this->effect_controls->type[12]->LocationX = 2;
    this->effect_controls->type[12]->LocationY = 2;
    this->effect_controls->type[13]->SourcePlayer = 1;
    this->effect_controls->type[14]->SetObjects = 2;
    this->effect_controls->type[14]->SourcePlayer = 2;
    this->effect_controls->type[14]->AreaXFROM = 2;
    this->effect_controls->type[14]->AreaYFROM = 2;
    this->effect_controls->type[14]->AreaXTO = 2;
    this->effect_controls->type[14]->AreaYTO = 2;
    this->effect_controls->type[14]->ObjectConstant = 2;
    this->effect_controls->type[14]->ObjectGroup = 2;
    this->effect_controls->type[14]->ObjectType = 2;
    this->effect_controls->type[15]->SetObjects = 2;
    this->effect_controls->type[15]->SourcePlayer = 2;
    this->effect_controls->type[15]->AreaXFROM = 2;
    this->effect_controls->type[15]->AreaYFROM = 2;
    this->effect_controls->type[15]->AreaXTO = 2;
    this->effect_controls->type[15]->AreaYTO = 2;
    this->effect_controls->type[15]->ObjectConstant = 2;
    this->effect_controls->type[15]->ObjectGroup = 2;
    this->effect_controls->type[15]->ObjectType = 2;
    this->effect_controls->type[16]->LocationX = 1;
    this->effect_controls->type[16]->LocationY = 1;
    this->effect_controls->type[16]->SourcePlayer = 1;
    this->effect_controls->type[17]->SetObjects = 2;
    this->effect_controls->type[17]->LocationX = 1;
    this->effect_controls->type[17]->LocationY = 1;
    this->effect_controls->type[17]->SourcePlayer = 2;
    this->effect_controls->type[17]->AreaXFROM = 2;
    this->effect_controls->type[17]->AreaYFROM = 2;
    this->effect_controls->type[17]->AreaXTO = 2;
    this->effect_controls->type[17]->AreaYTO = 2;
    this->effect_controls->type[17]->ObjectConstant = 2;
    this->effect_controls->type[17]->ObjectGroup = 2;
    this->effect_controls->type[17]->ObjectType = 2;
    this->effect_controls->type[18]->SetObjects = 2;
    this->effect_controls->type[18]->TargetPlayer = 1;
    this->effect_controls->type[18]->SourcePlayer = 2;
    this->effect_controls->type[18]->AreaXFROM = 2;
    this->effect_controls->type[18]->AreaYFROM = 2;
    this->effect_controls->type[18]->AreaXTO = 2;
    this->effect_controls->type[18]->AreaYTO = 2;
    this->effect_controls->type[18]->ObjectConstant = 2;
    this->effect_controls->type[18]->ObjectGroup = 2;
    this->effect_controls->type[18]->ObjectType = 2;
    this->effect_controls->type[19]->SetObjects = 2;
    this->effect_controls->type[19]->LocationX = 2;
    this->effect_controls->type[19]->LocationY = 2;
    this->effect_controls->type[22]->SetObjects = 2;
    this->effect_controls->type[22]->SourcePlayer = 2;
    this->effect_controls->type[22]->AreaXFROM = 2;
    this->effect_controls->type[22]->AreaYFROM = 2;
    this->effect_controls->type[22]->AreaXTO = 2;
    this->effect_controls->type[22]->AreaYTO = 2;
    this->effect_controls->type[22]->ObjectConstant = 2;
    this->effect_controls->type[22]->ObjectGroup = 2;
    this->effect_controls->type[22]->ObjectType = 2;
    this->effect_controls->type[24]->SetObjects = 2;
    this->effect_controls->type[24]->SourcePlayer = 2;
    this->effect_controls->type[24]->AreaXFROM = 2;
    this->effect_controls->type[24]->AreaYFROM = 2;
    this->effect_controls->type[24]->AreaXTO = 2;
    this->effect_controls->type[24]->AreaYTO = 2;
    this->effect_controls->type[24]->ObjectConstant = 2;
    this->effect_controls->type[24]->ObjectGroup = 2;
    this->effect_controls->type[24]->ObjectType = 2;
    this->effect_controls->type[24]->Quantity = 2;
    this->effect_controls->type[25]->SourcePlayer = 1;
    this->effect_controls->type[25]->ObjectConstant = 1;
    this->effect_controls->type[25]->LocationX = 1;
    this->effect_controls->type[25]->LocationY = 1;
    this->effect_controls->type[26]->SetObjects = 1;
    this->effect_controls->type[26]->StringTableID = 1;
    this->effect_controls->type[27]->SetObjects = 2;
    this->effect_controls->type[27]->SourcePlayer = 2;
    this->effect_controls->type[27]->AreaXFROM = 2;
    this->effect_controls->type[27]->AreaYFROM = 2;
    this->effect_controls->type[27]->AreaXTO = 2;
    this->effect_controls->type[27]->AreaYTO = 2;
    this->effect_controls->type[27]->ObjectConstant = 2;
    this->effect_controls->type[27]->ObjectGroup = 2;
    this->effect_controls->type[27]->ObjectType = 2;
    this->effect_controls->type[27]->Quantity = 1;
    this->effect_controls->type[28]->SetObjects = 2;
    this->effect_controls->type[28]->SourcePlayer = 2;
    this->effect_controls->type[28]->AreaXFROM = 2;
    this->effect_controls->type[28]->AreaYFROM = 2;
    this->effect_controls->type[28]->AreaXTO = 2;
    this->effect_controls->type[28]->AreaYTO = 2;
    this->effect_controls->type[28]->ObjectConstant = 2;
    this->effect_controls->type[28]->ObjectGroup = 2;
    this->effect_controls->type[28]->ObjectType = 2;
    this->effect_controls->type[28]->Quantity = 1;
    this->effect_controls->type[29]->SetObjects = 2;
    this->effect_controls->type[29]->SourcePlayer = 2;
    this->effect_controls->type[29]->AreaXFROM = 2;
    this->effect_controls->type[29]->AreaYFROM = 2;
    this->effect_controls->type[29]->AreaXTO = 2;
    this->effect_controls->type[29]->AreaYTO = 2;
    this->effect_controls->type[29]->ObjectConstant = 2;
    this->effect_controls->type[29]->ObjectGroup = 2;
    this->effect_controls->type[29]->ObjectType = 2;
}

//----- (00439EF0) --------------------------------------------------------
int GetTriggerCount()
{
    return this->num_triggers;
}

//----- (00439F00) --------------------------------------------------------
TRIBE_Trigger *sub_439F00()
{
    TRIBE_Triggers *v1; // ebx@1
    TRIBE_Trigger *v2; // eax@1
    TRIBE_Trigger *v3; // esi@2
    TRIBE_Trigger **v4; // ebp@4
    int *v5; // eax@4
    int v6; // ecx@4
    int v7; // ecx@6
    int v8; // edx@6
    TRIBE_Trigger *result; // eax@8
    int *v10; // [sp+8h] [bp-8h]@4
    TRIBE_Trigger *v11; // [sp+Ch] [bp-4h]@2

    v1 = this;
    v2 = operator new(0x40u);
    if( v2 )
    {
        v3 = TRIBE_Trigger::TRIBE_Trigger(v2, v1);
        v11 = v3;
        if( v3 )
        {
            if( v1->num_triggers >= v1->max_triggers )
            {
                do
                {
                    v4 = operator new(4 * v1->max_triggers + 40);
                    v5 = operator new(4 * v1->max_triggers + 40);
                    v6 = v1->max_triggers;
                    v10 = v5;
                    if( v6 > 0 )
                    {
                        qmemcpy(v4, v1->list, 4 * v6);
                        qmemcpy(v5, v1->triggers_order, 4 * v1->max_triggers);
                        operator delete(v1->list);
                        operator delete(v1->triggers_order);
                        v5 = v10;
                        v3 = v11;
                    }
                    v7 = v1->num_triggers;
                    v8 = v1->max_triggers + 10;
                    v1->triggers_order = v5;
                    v1->list = v4;
                    v1->max_triggers = v8;
                }
                while ( v7 >= v8 );
            }
            v1->list[v1->num_triggers] = v3;
            v1->triggers_order[v1->num_triggers] = v1->num_triggers;
            ++v1->num_triggers;
        }
        result = v3;
    }
    else
    {
        result = 0;
    }
    return result;
}

TRIBE_Trigger *GetTrigger(int id)
{
    TRIBE_Trigger *result; // eax@3

    if( id >= this->num_triggers || id < 0 )
        result = 0;
    else
        result = this->list[id];
    return result;
}

void DeallocateTrigger( int hTrigSec, int trigger )
{
    int _hTrigSec; // esi@1
    int hTrigger; // eax@3
    void *trigger_id; // edi@3
    int i; // eax@5
    int _num_triggers; // ecx@7
    int _trigger; // edx@7
    int __num_triggers; // eax@7
    _DWORD *trigger_orderid; // edi@8
    int v10; // edx@15
    int v11; // eax@15
    int v12; // edx@15
    int v13; // eax@16
    int v14; // ecx@16
    _DWORD *v15; // eax@16
    int j; // edi@19

    _hTrigSec = hTrigSec;
    if( trigger < *(hTrigSec + 24) && trigger >= 0 )
    {
        hTrigger = *(hTrigSec + 16);
        trigger_id = *(hTrigger + 4 * trigger);
        if( trigger_id )
        {
            TRIBE_Trigger::~TRIBE_Trigger(*(hTrigger + 4 * trigger));
            operator delete(trigger_id);
        }
        for( i = trigger; i < *(_hTrigSec + 24); *(*(_hTrigSec + 16) + 4 * i - 4) = *(*(_hTrigSec + 16) + 4 * i) )
            ++i;
        _num_triggers = *(_hTrigSec + 24);
        _trigger = 0;
        __num_triggers = *(_hTrigSec + 24);
        if( _num_triggers > 0 )
        {
            trigger_orderid = *(_hTrigSec + 20);
            while ( *trigger_orderid != trigger )
            {
                ++_trigger;
                ++trigger_orderid;
                if( _trigger >= _num_triggers )
                    goto LABEL_13;
            }
            __num_triggers = _trigger;
        }
LABEL_13:
        if( __num_triggers < _num_triggers )
        {
            do
            {
                ++__num_triggers;
                *(*(_hTrigSec + 20) + 4 * __num_triggers - 4) = *(*(_hTrigSec + 20) + 4 * __num_triggers);
            }
            while ( __num_triggers < *(_hTrigSec + 24) );
        }
        v10 = *(_hTrigSec + 24) - 1;
        *(_hTrigSec + 24) = v10;
        v11 = v10;
        v12 = 0;
        if( v11 > 0 )
        {
            do
            {
                v13 = *(_hTrigSec + 20);
                v14 = *(v13 + 4 * v12);
                v15 = (v13 + 4 * v12);
                if( v14 >= trigger )
                    *v15 = v14 - 1;
                ++v12;
            }
            while ( v12 < *(_hTrigSec + 24) );
        }
        for( j = 0; j < *(_hTrigSec + 24); ++j )
            sub_4393D0(*(*(_hTrigSec + 16) + 4 * j), trigger);
    }
}

int *GetTriggerOrderList()
{
    return this->triggers_order;
}

signed int sub_43A100(int this, int a2, int a3)
{
    int v3; // edx@1
    int v4; // esi@2
    int v5; // edi@6
    int v6; // esi@7
    int v7; // ebx@7
    _DWORD *v8; // esi@7
    int v10; // edi@10

    v3 = a2;
    if( a2 < 0 )
        return 0;
    v4 = *(this + 24);
    if( a2 >= v4 || a3 < 0 || a3 >= v4 )
        return 0;
    if( a3 < a2 )
    {
        v5 = *(*(this + 20) + 4 * a2);
        if( a2 > a3 )
        {
            do
            {
                v6 = *(this + 20);
                v7 = *(v6 + 4 * v3 - 4);
                v8 = (v6 + 4 * v3--);
                *v8 = v7;
            }
            while ( v3 > a3 );
        }
        *(*(this + 20) + 4 * a3) = v5;
        return 1;
    }
    if( a3 <= a2 )
        return 0;
    v10 = *(*(this + 20) + 4 * a2);
    if( a2 < a3 )
    {
        do
        {
            ++v3;
            *(*(this + 20) + 4 * v3 - 4) = *(*(this + 20) + 4 * v3);
        }
        while ( v3 < a3 );
    }
    *(*(this + 20) + 4 * a3) = v10;
    return 1;
}

TRIBE_Triggers *sub_43A190()
{
    this->obj_next_order = 999999;
    this->obj_curr_order = 0;
    this->obj_curr_index = 0;
}

char **sub_43A1A0(bool *a2)
{
    TRIBE_Triggers *i; // esi@1
    TRIBE_Trigger *trigger; // edi@3
    int num_triggers; // ecx@10
    int v5; // eax@10
    int v6; // eax@11
    char **result; // eax@13
    int *obj_desc_id; // [sp+8h] [bp-8h]@13
    char *obj_desc_text; // [sp+Ch] [bp-4h]@13

    for( i = this; i->obj_curr_index >= i->num_triggers; i->obj_curr_index = 0 )
    {
LABEL_11:
        v6 = i->obj_next_order;
        if( v6 == 999999 )
            return 0;
        i->obj_curr_order = v6;
        i->obj_next_order = 999999;
    }
    while ( 1 )
    {
        trigger = GetTrigger(i, i->obj_curr_index);
        if( TRIBE_Trigger::is_objectives_shown(trigger) )
        {
            if( TRIBE_Trigger::get_state(trigger) == 1 || TRIBE_Trigger::get_state(trigger) == 2 )
                break;
        }
LABEL_10:
        num_triggers = i->num_triggers;
        v5 = i->obj_curr_index + 1;
        i->obj_curr_index = v5;
        if( v5 >= num_triggers )
            goto LABEL_11;
    }
    if( TPanel::previousModalPanel(trigger) != i->obj_curr_order )
    {
        if( TPanel::previousModalPanel(trigger) > i->obj_curr_order
            && TPanel::previousModalPanel(trigger) < i->obj_next_order )
        {
            i->obj_next_order = TPanel::previousModalPanel(trigger);
        }
        goto LABEL_10;
    }
    *a2 = TRIBE_Trigger::get_state(trigger) == 2;
    TRIBE_Trigger::get_objectives(trigger, &obj_desc_text, &obj_desc_id);
    result = (*(rge_base_game->vfptr + 9))(obj_desc_id);
    ++i->obj_curr_index;
    if( !result || !*result )
        result = obj_desc_text;
    return result;
}
