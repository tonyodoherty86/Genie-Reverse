
/**
 * @file    Engine\RGE\ActionList.cpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

RGE_Action_List::RGE_Action_List(RGE_Action_Object *obj_in)
{
    this->obj = obj_in;
}

RGE_Action_List::~RGE_Action_List()
{
    this->delete_list();
}

void RGE_Action_List::load(int infile)
{
    RGE_Action_List *v2; // edi@1
    _DWORD *v3; // ebx@3
    int v4; // esi@5
    _DWORD *v5; // eax@5
    int action_type; // [sp+10h] [bp-4h]@4

    v2 = this;
    if( this->list ){
        this->delete_list();
    }

    for( int v3 = 0; 1; ){

        rge_read(infile, &action_type, 2);

        if( action_type == 0 ){
            break;
        }

        v4 = this->create_action(infile, action_type);

        v5 = calloc(1u, 8u);
        *v5 = v4;
        v5[1] = 0;
        if( v3 )
        {
            v3[1] = v5;
            v3 = v5;
        }else{
            this->list = (RGE_Action_Node *)v5;
            v3 = v5;
        }
    }
}

void RGE_Action_List::rehook()
{
    for( RGE_Action_Node *i = this->list; i; i = i->next ){
        i->action->rehook();
    }
}

void RGE_Action_List::save(int outfile)
{
    int i; // edi@1

    RGE_Action_Node *v2 = this->list;
    for( i = outfile; v2; v2 = v2->next ){
        v2->action->save(i);
    }
    outfile = 0;
    rge_write(i, &outfile, 2);
}

void RGE_Action_List::delete_list()
{
    for( RGE_Action_List *i = this; i->list; ){
        i->remove_action();
    }
}

void RGE_Action_List::create_action(
    int infile,
    short action_type)
{
    RGE_Action_List *v4; // esi@1
    RGE_Action_Attack *v5; // eax@2
    RGE_Action_Bird *v6; // eax@4
    RGE_Action_Explore *v7; // eax@6
    RGE_Action_Gather *v8; // eax@8
    RGE_Action_Missile *v9; // eax@10
    RGE_Action_Move_To *v10; // eax@12
    RGE_Action_Make *v11; // eax@14

    v4 = this;
    switch ( action_type )
    {
        case 9:
            v5 = (RGE_Action_Attack *)operator new(0x5Cu);
            if( v5 )
                RGE_Action_Attack::RGE_Action_Attack(v5, a2, infile, v4->obj);
            break;
        case 10:
            v6 = (RGE_Action_Bird *)operator new(0x40u);
            if( v6 )
                RGE_Action_Bird::RGE_Action_Bird(v6, a2, infile, v4->obj);
            break;
        case 4:
            v7 = (RGE_Action_Explore *)operator new(0x40u);
            if( v7 )
                RGE_Action_Explore::RGE_Action_Explore(v7, a2, infile, v4->obj);
            break;
        case 5:
            v8 = (RGE_Action_Gather *)operator new(0x44u);
            if( v8 )
                RGE_Action_Gather::RGE_Action_Gather(v8, a2, infile, v4->obj);
            break;
        case 8:
            v9 = (RGE_Action_Missile *)operator new(0x54u);
            if( v9 )
                RGE_Action_Missile::RGE_Action_Missile(v9, a2, infile, v4->obj);
            break;
        case 1:
            v10 = (RGE_Action_Move_To *)operator new(0x44u);
            if( v10 )
                RGE_Action_Move_To::RGE_Action_Move_To(v10, a2, infile, v4->obj);
            break;
        case 21:
            v11 = (RGE_Action_Make *)operator new(0x40u);
            if( v11 )
                RGE_Action_Make::RGE_Action_Make(v11, a2, infile, v4->obj);
            break;
        default:
            return;
    }
}

void RGE_Action_List::create_task_action(
    RGE_Task *task,
    RGE_Static_Object *target_obj,
    float target_x,
    float target_y,
    float target_z)
{
    RGE_Action_List *v6; // edi@1
    RGE_Action_Bird *v7; // eax@2
    UnitAIModule *v8; // eax@5
    UnitAIModule *v9; // eax@8
    RGE_Action_Attack *v10; // eax@10
    RGE_Action_Attack *v11; // eax@12
    RGE_Action_Explore *v12; // eax@14
    RGE_Action_Gather *v13; // eax@17
    RGE_Action_Gather *v14; // eax@19
    RGE_Action_Make *v15; // eax@21
    signed int v16; // [sp-10h] [bp-2Ch]@6
    float v17; // [sp-Ch] [bp-28h]@6
    float v18; // [sp-8h] [bp-24h]@6
    float v19; // [sp-4h] [bp-20h]@6

    v6 = this;
    switch ( task->action_type )
    {
        case 10:
            v7 = (RGE_Action_Bird *)operator new(0x40u);
            if( v7 )
                RGE_Action_Bird::RGE_Action_Bird(v7, v6->obj, task, target_x, target_y, target_z);
            break;
        case 7:
            if( RGE_Static_Object::unitAI((RGE_Static_Object *)&this->obj->vfptr) )
            {
                v8 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v6->obj->vfptr);
                UnitAIModule::setCurrentAction(v8, 600);
                if( target_obj )
                {
                    v19 = target_obj->world_z;
                    v18 = target_obj->world_y;
                    v17 = target_obj->world_x;
                    v16 = target_obj->id;
                }
                else
                {
                    v19 = target_z;
                    v18 = target_y;
                    v17 = target_x;
                    v16 = -1;
                }
                v9 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v6->obj->vfptr);
                UnitAIModule::setCurrentTarget(v9, v16, v17, v18, v19);
            }
            if( target_obj )
            {
                v10 = (RGE_Action_Attack *)operator new(0x5Cu);
                if( v10 )
                    RGE_Action_Attack::RGE_Action_Attack(
                        v10,
                        v6->obj,
                        target_obj,
                        task->move_sprite,
                        task->work_sprite,
                        0,
                        task->work_range,
                        v6->obj->master_obj[1].attribute_rot,
                        v6->obj->master_obj[1].attribute_type_held[1],
                        HIWORD(v6->obj->master_obj[1].attribute_amount_held[0]));
            }
            else
            {
                v11 = (RGE_Action_Attack *)operator new(0x5Cu);
                if( v11 )
                    RGE_Action_Attack::RGE_Action_Attack(
                        v11,
                        v6->obj,
                        target_x,
                        target_y,
                        target_z,
                        task->move_sprite,
                        task->work_sprite,
                        0,
                        task->work_range,
                        v6->obj->master_obj[1].attribute_rot,
                        v6->obj->master_obj[1].attribute_type_held[1],
                        HIWORD(v6->obj->master_obj[1].attribute_amount_held[0]));
            }
            break;
        case 4:
            v12 = (RGE_Action_Explore *)operator new(0x40u);
            if( v12 )
                RGE_Action_Explore::RGE_Action_Explore(v12, v6->obj, task, target_x, target_y, target_z);
            break;
        case 5:
            if( target_obj )
            {
                v13 = (RGE_Action_Gather *)operator new(0x44u);
                if( v13 )
                    RGE_Action_Gather::RGE_Action_Gather(v13, v6->obj, task, target_obj);
            }
            else
            {
                v14 = (RGE_Action_Gather *)operator new(0x44u);
                if( v14 )
                    RGE_Action_Gather::RGE_Action_Gather(v14, v6->obj, task, target_x, target_y, target_z);
            }
            break;
        case 21:
            v15 = (RGE_Action_Make *)operator new(0x40u);
            if( v15 )
                RGE_Action_Make::RGE_Action_Make(v15, v6->obj, task);
            break;
        default:
            return;
    }
}

bool RGE_Action_List::inside_obj_update()
{
    RGE_Action_List *v1; // edi@1
    RGE_Action_Node *v2; // eax@1
    char result; // al@2
    char v4; // bl@3
    RGE_Action_Node *i; // esi@3

    v1 = this;
    v2 = this->list;
    if( v2 )
    {
        v4 = ((int (*)(void))v2->action->vfptr->inside_obj_update)();
        for( i = v1->list->next; i; i = i->next )
            ((void (*)(void))i->action->vfptr->idle_update)();
        if( v4 == 1 )
            RGE_Action_List::remove_action(v1);
        result = v4;
    }
    else
    {
        result = 1;
    }
    return result;
}

bool RGE_Action_List::update()
{
    RGE_Action_List *v1; // edi@1
    RGE_Action_Node *v2; // eax@1
    char result; // al@2
    char v4; // bl@3
    RGE_Action_Node *v5; // eax@3
    RGE_Action_Node *i; // esi@4

    v1 = this;
    v2 = this->list;
    if( v2 )
    {
        v4 = ((int (*)(void))v2->action->vfptr->update)();
        v5 = v1->list;
        if( v5 )
        {
            for( i = v5->next; i; i = i->next )
                ((void (*)(void))i->action->vfptr->idle_update)();
            if( v4 == 1 )
                RGE_Action_List::remove_action(v1);
        }
        result = v4;
    }
    else
    {
        result = 1;
    }
    return result;
}

void RGE_Action_List::add_action(RGE_Action *action)
{
    if( this->obj->object_state <= 2u )
    {
        RGE_Action_Node *v3 = new RGE_Action_Node;
        v3->action = action;
        v3->next = this->list;
        this->list = v3;
        action->first_in_stack(true);
    }else if( action ){
        delete action;
    }
}

void RGE_Action_List::add_action_at_end(RGE_Action *action)
{
    RGE_Action_List *v2; // esi@1
    RGE_Action_Node *v3; // eax@4
    RGE_Action_Node *v4; // edx@4
    RGE_Action_Node *v5; // esi@5

    v2 = this;
    if( this->obj->object_state <= 2u )
    {
        v3 = (RGE_Action_Node *)calloc(1u, 8u);
        v3->next = 0;
        v3->action = action;
        v4 = v2->list;
        if( v4 )
        {
            while( 1 )
            {
                v5 = v4->next;
                if( !v5 )
                    break;
                v4 = v4->next;
                if( !v5 )
                {
                    ((void (__stdcall *)(_DWORD))action->vfptr->first_in_stack)(1);
                    return;
                }
            }
            v4->next = v3;
            ((void (__stdcall *)(_DWORD))action->vfptr->first_in_stack)(1);
        }
        else
        {
            v2->list = v3;
            ((void (__stdcall *)(_DWORD))action->vfptr->first_in_stack)(1);
        }
    }
    else if( action )
    {
        ((void (__stdcall *)(_DWORD))action->vfptr->__vecDelDtor)(1);
    }
}

void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action *action)
{
    RGE_Action_List *v2; // esi@1
    RGE_Action_Node *v3; // eax@4
    RGE_Action *v4; // ebx@4
    RGE_Action_Node *v5; // ecx@4
    RGE_Action **v6; // eax@4
    RGE_Action *v7; // edi@5
    __int16 (*v8)(RGE_Action *); // ebp@5
    RGE_Action_Node *v9; // edi@6
    RGE_Action **v10; // eax@7
    RGE_Action *v11; // esi@8
    RGE_ActionVtbl *v12; // edx@11
    RGE_Action_Node *node; // [sp+10h] [bp-4h]@4
    __int16 actiona; // [sp+18h] [bp+4h]@5
    __int16 actionb; // [sp+18h] [bp+4h]@8

    v2 = this;
    if( this->obj->object_state > 2u )
    {
        if( action )
            ((void (__stdcall *)(_DWORD))action->vfptr->__vecDelDtor)(1);
        return;
    }
    v3 = (RGE_Action_Node *)calloc(1u, 8u);
    v4 = action;
    v5 = v3;
    node = v3;
    v3->action = action;
    v6 = &v2->list->action;
    if( !v6 )
        goto LABEL_13;
    v7 = *v6;
    v8 = action->vfptr->type;
    actiona = v8(action);
    if( (unsigned __int16)v7->vfptr->type(v7) != actiona )
    {
        v5 = node;
LABEL_13:
        v5->next = v2->list;
        v2->list = v5;
        goto LABEL_14;
    }
    v9 = v2->list;
    if( !v9 )
    {
LABEL_14:
        v4->vfptr->first_in_stack(v4, 1);
        return;
    }
    while( 1 )
    {
        v10 = &v9->next->action;
        if( !v10 )
            break;
        v11 = *v10;
        actionb = v8(v4);
        if( (unsigned __int16)v11->vfptr->type(v11) != actionb )
            break;
        v9 = v9->next;
        if( !v9 )
        {
            v4->vfptr->first_in_stack(v4, 1);
            return;
        }
    }
    node->next = v9->next;
    v12 = v4->vfptr;
    v9->next = node;
    v12->first_in_stack(v4, 1);
}

void RGE_Action_List::remove_action()
{
    RGE_Action_List *v1; // edi@1
    RGE_Action_Node *v2; // esi@1
    RGE_Action **v3; // eax@4

    v1 = this;
    v2 = this->list;
    if( v2 )
    {
        this->list = v2->next;
        if( v2->action )
            ((void (__stdcall *)(_DWORD))v2->action->vfptr->__vecDelDtor)(1);
        free(v2);
        v3 = &v1->list->action;
        if( v3 )
        {
            if( v1->obj->object_state < 3u )
                (*v3)->vfptr->first_in_stack(*v3, 0);
        }
    }
}

bool RGE_Action_List::have_action()
{
    return this->list != nullptr;
}

int RGE_Action_List::action_stop()
{
    if( this->list ){
        return this->list->action->stop();
    }
}

int RGE_Action_List::action_move_to(RGE_Static_Object *obj_in, float x, float y, float z)
{
    RGE_Action_Node *v5; // eax@1
    int result; // eax@2

    v5 = this->list;
    if( v5 )
        result = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v5->action->vfptr->move_to)(
                             obj_in,
                             LODWORD(x),
                             LODWORD(y),
                             LODWORD(z));
    else
        result = 0;
    return result;
}

int RGE_Action_List::action_work(RGE_Static_Object *obj_in, float x, float y, float z)
{
    RGE_Action_Node *v5; // eax@1
    int result; // eax@2

    v5 = this->list;
    if( v5 )
        result = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v5->action->vfptr->work)(
                             obj_in,
                             LODWORD(x),
                             LODWORD(y),
                             LODWORD(z));
    else
        result = 0;
    return result;
}

int RGE_Action_List::attack_response(RGE_Static_Object *attacker)
{
    RGE_Action_Node *v2; // eax@1
    int result; // eax@2

    v2 = this->list;
    if( v2 )
        result = (unsigned __int8)((int (__stdcall *)(RGE_Static_Object *))v2->action->vfptr->attack_response)(attacker);
    else
        result = 0;
    return result;
}

int RGE_Action_List::relation_response(int player_id, int relation)
{
    if( this->list ){
        return this->list->action->relation_response(player_id, relation);
    }
}

RGE_Action *RGE_Action_List::get_action()
{
    RGE_Action_Node *v1; // eax@1
    RGE_Action *result; // eax@2

    v1 = this->list;
    if( v1 )
        result = v1->action;
    else
        result = 0;
    return result;
}

RGE_Task *RGE_Action_List::get_task()
{
    RGE_Action_Node *v1; // eax@1
    RGE_Task *result; // eax@2

    v1 = this->list;
    if( v1 )
        result = v1->action->task;
    else
        result = 0;
    return result;
}

void RGE_Action_List::copy_obj(RGE_Master_Action_Object *source)
{
    RGE_Action_Node *i; // esi@1

    for( i = this->list; i; i = i->next )
        ((void (__stdcall *)(RGE_Master_Action_Object *))i->action->vfptr->copy_obj)(source);
}

void RGE_Action_List::copy_obj_sprites(RGE_Master_Action_Object *source, RGE_Task *task, RGE_Task *new_task)
{
    RGE_Action_Node *i; // esi@1

    for( i = this->list; i; i = i->next )
        ((void (__stdcall *)(RGE_Master_Action_Object *, RGE_Task *, RGE_Task *))i->action->vfptr->copy_obj_sprites)(
            source,
            task,
            new_task);
}

void RGE_Action_List::get_action_name(char *action_name)
{
    RGE_Action_Node *v2; // eax@1
    const char *v3; // edi@2
    const char *v4; // edi@5

    v2 = this->list;
    if( v2 )
    {
        switch ( v2->action->action_type )
        {
            case 9:
                v3 = aAttack;
                break;
            case 10:
                v4 = aBird;
                goto LABEL_12;
            case 4:
                v3 = aExplore_1;
                break;
            case 5:
                v4 = aGather;
                goto LABEL_12;
            case 8:
                v3 = aMissile;
                break;
            case 1:
                v4 = aMoveto;
                goto LABEL_12;
            case 20:
                v3 = aRunaway;
                break;
            case 21:
                v4 = aMake;
LABEL_12:
                strcpy(action_name, v4);
                return;
            default:
                v3 = aUnknown;
                break;
        }
    }
    else
    {
        v3 = aNone_3;
    }
    strcpy(action_name, v3);
}
