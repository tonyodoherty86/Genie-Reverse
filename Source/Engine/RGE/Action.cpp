
/**
 * @file    Engine\RGE\Action.cpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

RGE_Action::RGE_Action(int infile, RGE_Action_Object *obj_in, bool do_setup)
{
    if( do_setup ){
        this->setup(infile, obj_in);
    }
}

RGE_Action::RGE_Action(RGE_Action_Object *obj_in, bool do_setup)
{
    if( do_setup ){
        this->setup(obj_in);
    }
}

RGE_Action::~RGE_Action()
{
    this->set_target_obj(nullptr);
    this->set_target_obj2(nullptr);

    if( this->sub_actions ){
        delete this->sub_actions;
    }
}

bool RGE_Action::setup(int infile, RGE_Action_Object *obj_in)
{
    int long_val;
    short short_val;

    this->action_type = 0;
    this->obj = obj_in;
    this->sub_actions = this->create_action_list(obj_in);// TODO

    rge_read(infile, &this->state, 1);

    rge_read(infile, &long_val, 4);
    if( long_val == (RGE_Action_Object *)-1 ){
        this->target_obj = nullptr;
    }else{
        this->target_obj = (RGE_Static_Object *)long_val;
    }

    rge_read(infile, &obj_in, 4);
    if( obj_in == (RGE_Action_Object *)-1 ){
        this->target_obj2 = nullptr;
    }else{
        this->target_obj2 = (RGE_Static_Object *)obj_in;
    }

    rge_read(infile, &this->targetID, 4);
    rge_read(infile, &this->target2ID, 4);

    rge_read(infile, &this->target_x, 4);
    rge_read(infile, &this->target_y, 4);
    rge_read(infile, &this->target_z, 4);

    rge_read(infile, &this->timer, 4);

    rge_read(infile, &short_val, 2);
    if( short_val != -1 ){
        this->task = this->obj->master_obj->tasks->list[short_val];
    }else{
        this->task = nullptr;
    }

    rge_read(infile, &this->sub_action_value, 1);

    this->sub_actions->load(infile);

    rge_read(infile, &short_val, 2);
    this->sprite = this->obj->get_sprite_pointer(short_val);

    return true;
}

bool RGE_Action::setup(RGE_Action_Object *obj_in)
{
    this->action_type = 0;

    this->obj = obj_in;

    this->state = 0;

    this->target_obj = 0;
    this->target_obj2 = 0;

    this->target_x = 0.0;
    this->target_y = 0.0;
    this->target_z = 0.0;

    this->timer = 0.0;

    this->task = nullptr;

    this->sub_actions = this->create_action_list(obj_in);

    this->sprite = nullptr;

    this->sub_action_value = 0;

    return true;
}

RGE_Action_List *RGE_Action::create_action_list()
{
    return new RGE_Action_List(this->obj);
}

RGE_Action_List *RGE_Action::create_action_list(RGE_Action_Object *obj_in)
{
    return new RGE_Action_List(obj_in);
}

void RGE_Action::rehook()
{
    if( this->target_obj ){
        this->target_obj = this->obj->get_object_pointer(this->target_obj);
        if( this->target_obj ){
            this->targetID = this->target_obj->id;
        }
    }
    if( this->target_obj2 ){
        this->target_obj2 = this->obj->get_object_pointer(this->target_obj2);
        if( this->target_obj2 )
            this->target2ID = this->target_obj2->id;
    }
    if( this->sub_actions ){
        this->sub_actions->rehook();
    }
}

void RGE_Action::save(int outfile)
{
    int long_val;
    short short_val;

    rge_write(outfile, &this->action_type, 2);

    rge_write(outfile, &this->state, 1);

    if( this->target_obj ){
        long_val = this->target_objid;
    }else{
        long_val = -1;
    }
    rge_write(outfile, &long_val, 4);

    if( this->target_obj2 ){
        long_val = this->target_obj2->id;
    }else{
        long_val = -1;
    }
    rge_write(outfile, &long_val, 4);

    rge_write(outfile, &this->targetID, 4);
    rge_write(outfile, &this->target2ID, 4);

    rge_write(outfile, &this->target_x, 4);
    rge_write(outfile, &this->target_y, 4);
    rge_write(outfile, &this->target_z, 4);

    rge_write(outfile, &this->timer, 4);

    if( this->task->task_type ){
        short_val = this->task->id;
    }else{
        short_val = -1;
    }
    rge_write(outfile, &short_val, 2);

    rge_write(outfile, &this->sub_action_value, 1);

    this->sub_actions->save(outfile);

    if( this->sprite ){
        short_val = this->sprite->id;
    }else{
        short_val = -1;
    }
    rge_write(outfile, &short_val, 2);
}

short RGE_Action::type()
{
    return this->action_type;
}

int RGE_Action::stop()
{
    return 0;
}

int RGE_Action::move_to(RGE_Static_Object *obj_in, float x, float y, float z)
{
    return 0;
}

int RGE_Action::work(RGE_Static_Object *obj_in, float x, float y, float z)
{
    return 0;
}

char RGE_Action::attack_response(RGE_Static_Object *obj_in)
{
    return 0;
}

char RGE_Action::relation_response(int player_id, char relation)
{
    return 0;
}

void RGE_Action::set_state(char new_state)
{
    this->state = new_state;
}

bool RGE_Action::inside_obj_update()
{
    if( this->target_obj &&
        this->target_obj->object_state >= 7u ){
        this->set_target_obj(nullptr);
    }
    if( this->target_obj2 &&
        this->target_obj2->object_state >= 7u ){
        this->set_target_obj2(nullptr);
    }
    return true;
}

bool RGE_Action::idle_update()
{
    if( this->target_obj &&
        this->target_obj->object_state >= 7u ){
        this->set_target_obj(nullptr);
    }
    if( this->target_obj2 &&
        this->target_obj2->object_state >= 7u ){
        this->set_target_obj2(nullptr);
    }
    return true;
}

bool RGE_Action::update()
{
    if( this->target_obj &&
        this->target_obj->object_state >= 7u ){
        this->set_target_obj(nullptr);
    }
    if( this->target_obj2 &&
        this->target_obj2->object_state >= 7u ){
        this->set_target_obj2(nullptr);
    }
    if( this->sub_actions->list ){
        return this->sub_actions->update();
    }else{
        return this->state == 1;
    }
}

void RGE_Action::set_target_obj(RGE_Static_Object *new_obj)
{
    RGE_Static_Object *v4;
    if( this->target_obj && this->target_obj != new_obj && v4 = this->obj->owner->world->object(this->targetID) ){
        v4->release_being_worked_on((RGE_Static_Object *)this->obj);
    }
    if( this->target_obj != new_obj ){
        this->target_obj = new_obj;
        if( new_obj ){
            LOWORD(this) = this->action_type;
            this->targetID = new_obj->id;
            new_obj->set_being_worked_on(this->obj, (short)this, 0);
        }else{
            this->targetID = -1;
        }
    }
}

void RGE_Action::set_target_obj2(RGE_Static_Object *new_obj)
{
    if( this->target_obj2 &&
        this->target_obj2 != new_obj ){
        if( RGE_Static_Object *v4 = this->obj->owner->world->object(this->target2ID) ){
            v4->release_being_worked_on(this->obj);
        }
    }
    if( this->target_obj2 != new_obj ){
        this->target_obj2 = new_obj;
        if( new_obj ){
            LOWORD(this) = this->action_type;
            RGE_Static_ObjectVtbl *v5 = new_obj->vfptr;
            this->target2ID = new_obj->id;
            v5->set_being_worked_on(new_obj, this->obj, (short)this, 0);
        }else{
            this->target2ID = -1;
        }
    }
}

void RGE_Action::copy_obj(RGE_Master_Action_Object *source)
{
    RGE_Action *v2; // edi@1
    RGE_Task *v3; // ecx@1
    RGE_Task_List *v4; // eax@2
    RGE_Task **v5; // ebp@3
    int v6; // esi@3
    short v7; // cx@4
    int v8; // eax@4
    RGE_Task *v9; // eax@8
    RGE_Action_Object *v10; // ecx@8
    RGE_Sprite *v11; // edx@8
    RGE_Sprite *v12; // eax@14
    RGE_Sprite *new_sprite; // [sp+10h] [bp-4h]@1

    v2 = this;
    new_sprite = 0;
    v3 = this->task;
    if( this->task && (v4 = source->tasks) != 0 ){
        v5 = source->tasks->list;
        v6 = v4->list_num - 1;
        if( v6 >= 0 ){
            v7 = this->task->action_type;
            v8 = (int)&v5[v6];
            do
            {
                if( *(_WORD *)(*(_DWORD *)v8 + 6) == v7 )
                    break;
                --v6;
                v8 -= 4;
            }
            while( v6 >= 0 );
        }
        if( v6 >= 0 ){
            v9 = v5[v6];
            v10 = v2->obj;
            v11 = v10->sprite;
            if( v11 == v9->move_sprite )
            {
                new_sprite = v9->move_sprite;
            }
            else if( v11 == v9->work_sprite )
            {
                new_sprite = v9->work_sprite;
            }
            else if( v11 == v9->work_sprite2 )
            {
                new_sprite = v9->work_sprite2;
            }
            else
            {
                v12 = v9->carry_sprite;
                if( v11 == v12 )
                    new_sprite = v12;
            }
            if( new_sprite )
                (*(void (__stdcall **)(RGE_Sprite *))&v10->vfptr->gap4[52])(new_sprite);
            v2->vfptr->copy_obj_sprites(v2, source, v2->task, v5[v6]);
            ((void (__stdcall *)(RGE_Master_Action_Object *, _DWORD, _DWORD))v2->sub_actions->vfptr->copy_obj_sprites)(
                    source,
                    v2->task,
                    v5[v6]);
            v2->task = v5[v6];
        }
    }else{
        this->copy_obj_sprites(source, 0, 0);
        this->sub_actions->copy_obj_sprites)(source, 0, 0);
    }
}

void RGE_Action::get_state_name(char *state_name)
{
    const char *v2; // edi@2
    const char *v3; // edi@3

    switch( this->state ){
        case 0:
            v2 = aNone_3;
            goto LABEL_20;
        case 1:
            v3 = aDone;
            goto LABEL_18;
        case 2:
            v2 = aWait;
            goto LABEL_20;
        case 3:
            v3 = aSearch;
            goto LABEL_18;
        case 4:
            v2 = aGoto;
            goto LABEL_20;
        case 5:
            v3 = aGoto2;
            goto LABEL_18;
        case 6:
            v2 = aWork;
            goto LABEL_20;
        case 7:
            v3 = aWork2;
            goto LABEL_18;
        case 8:
            v2 = aReturn;
            goto LABEL_20;
        case 9:
            v3 = aTurn;
            goto LABEL_18;
        case 0xA:
            v2 = aDelay;
            goto LABEL_20;
        case 0xB:
            v3 = aMove;
            goto LABEL_18;
        case 0xC:
            v2 = aAttack;
            goto LABEL_20;
        case 0xD:
            v3 = aFailed;
            goto LABEL_18;
        case 0xE:
            v2 = aInvalidated;
            goto LABEL_20;
        case 0xF:
            v3 = aMovenosearch;
        LABEL_18:
            strcpy(state_name, v3);
            break;
        default:
            v2 = aUnknown;
        LABEL_20:
            strcpy(state_name, v2);
            break;
    }
}

double RGE_Action::targetX()
{
    return this->target_x;
}

double RGE_Action::targetY()
{
    return this->target_y;
}

double RGE_Action::targetZ()
{
    return this->target_z;
}

char RGE_Action::subAction()
{
    return this->sub_action_value;
}

void RGE_Action::setSubAction(char v)
{
    this->sub_action_value = v;
}
