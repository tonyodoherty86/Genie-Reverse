
RGE_Master_Action_Object::RGE_Master_Action_Object( RGE_Master_Action_Object *other_object, int do_setup = true )
{
    RGE_Master_Moving_Object::RGE_Master_Moving_Object(other_object, false);

    if( do_setup ){
        this->setup(other_object);
    }
}

RGE_Master_Action_Object::RGE_Master_Action_Object( int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup = true )
{
    RGE_Master_Moving_Object::RGE_Master_Moving_Object(
        infile,
        sprites,
        sounds,
        false);

    if( do_setup ){
        this->setup(infile, sprites, sounds);
    }
}

bool RGE_Master_Action_Object::setup( RGE_Master_Action_Object *other_object )
{
    RGE_Master_Moving_Object::setup(other_object);

    this->default_task     = other_object->default_task;
    this->search_radius    = other_object->search_radius;
    this->work_rate        = other_object->work_rate;
    this->drop_site        = other_object->drop_site;
    this->backup_drop_site = other_object->backup_drop_site;
    this->task_by_group    = other_object->task_by_group;
    this->command_sound    = other_object->command_sound;
    this->move_sound       = other_object->move_sound;
    this->run_pattern      = other_object->run_pattern;

    this->tasks = new RGE_Task_List;
    this->tasks->copy(other_object->tasks);

    return true;
}

bool RGE_Master_Action_Object::setup( int infile, RGE_Sprite **sprites, RGE_Sound **sounds )
{
    short command_sound_id = -1,
          move_sound_id    = -1;

    RGE_Master_Moving_Object::setup(infile, sprites, sounds);

    rge_read(infile, &this->default_task, 2);
    rge_read(infile, &this->search_radius, 4);
    rge_read(infile, &this->work_rate, 4);
    rge_read(infile, &this->drop_site, 2);
    rge_read(infile, &this->backup_drop_site, 2);
    rge_read(infile, &this->task_by_group, 1);
    rge_read(infile, &command_sound_id, 2);

    if( save_game_version >= 6.92 ){
        rge_read(infile, &move_sound_id, 2);
    }

    rge_read(infile, &this->run_pattern, 1);

    if( command_sound_id >= 0 ){
        this->command_sound = sounds[command_sound_id];
    }else{
        this->command_sound = nullptr;
    }

    if( move_sound_id >= 0 ){
        this->move_sound = sounds[move_sound_id];
    }else{
        this->move_sound = nullptr;
    }

    this->tasks = new RGE_Task_List;
    this->tasks->load(infile, sprites, sounds);

    return true;
}

void RGE_Master_Action_Object::make_new_obj( RGE_Player *owner, float x, float y, float z )
{
    RGE_Master_Action_Object *v5; // edi@1
    RGE_Static_Object *v6; // eax@2
    RGE_Action_Object *v7; // eax@4

    v5 = this;
    if( this->recyclable && (v6 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
    {
        (*(void (**)(RGE_Static_Object *, RGE_Master_Action_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[0])(
            v6,
            v5,
            owner,
            LODWORD(x),
            LODWORD(y),
            LODWORD(z));
    }
    else
    {
        v7 = (RGE_Action_Object *)operator new(0x194u);
        if( v7 )
            RGE_Action_Object::RGE_Action_Object(v7, v5, owner, x, y, z, 1);
    }
}

void RGE_Master_Action_Object::make_new_master()
{
    RGE_Master_Action_Object *v1; // esi@1
    RGE_Master_Action_Object *v2; // eax@1

    v1 = this;
    v2 = (RGE_Master_Action_Object *)operator new(0xFCu);
    if( v2 )
        RGE_Master_Action_Object::RGE_Master_Action_Object(v2, v1, 1);
}

RGE_Task *RGE_Master_Action_Object::get_task( short task_id )
{
    RGE_Task_List *v2; // eax@2
    RGE_Task *result; // eax@3

    if( task_id == -1 || (v2 = this->tasks, task_id >= v2->list_num) )
        result = 0;
    else
        result = v2->list[task_id];
    return result;
}

RGE_Task *RGE_Master_Action_Object::getTaskByTaskID( int t )
{
    RGE_Task_List *v2; // ecx@2
    int v3; // eax@2
    int v4; // edx@2
    RGE_Task **v5; // edi@3
    RGE_Task **v6; // ecx@3
    RGE_Task *result; // eax@6

    if( t == -1 || (v2 = this->tasks, v3 = 0, v4 = v2->list_num, v4 <= 0) )
    {
        result = 0;
    }
    else
    {
        v5 = v2->list;
        v6 = v2->list;
        while( t != (*v6)->action_type )
        {
            ++v3;
            ++v6;
            if( v3 >= v4 )
                return 0;
        }
        result = v5[v3];
    }
    return result;
}

void RGE_Master_Action_Object::copy_obj( RGE_Master_Static_Object *source )
{
    RGE_Master_Action_Object *v2; // esi@1

    v2 = this;
    RGE_Master_Moving_Object::copy_obj(source);
    v2->default_task = *(_WORD *)&source[1].undead_flag;
    v2->search_radius = source[1].los;
    v2->work_rate = *(float *)&source[1].obj_max;
    v2->drop_site = LOWORD(source[1].radius_x);
    v2->backup_drop_site = HIWORD(source[1].radius_x);
    v2->task_by_group = LOBYTE(source[1].radius_y);
    v2->command_sound = (RGE_Sound *)LODWORD(source[1].radius_z);
    v2->move_sound = source[1].selected_sound;
    RGE_Task_List::copy(v2->tasks, (RGE_Task_List *)source[1].undead_sprite);
}

void RGE_Master_Action_Object::modify(float amount, char flag)
{
    if( flag == 13 )
        this->work_rate = amount;
    else
        RGE_Master_Moving_Object::modify(amount, flag);
}

void RGE_Master_Action_Object::modify_delta(float amount, char flag)
{
    if( flag == 13 )
        this->work_rate = amount + this->work_rate;
    else
        RGE_Master_Moving_Object::modify_delta(amount, flag);
}

void RGE_Master_Action_Object::modify_percent(float amount, char flag)
{
    if( flag == 13 )
        this->work_rate = amount * this->work_rate;
    else
        RGE_Master_Moving_Object::modify_percent(amount, flag);
}

void RGE_Master_Action_Object::save( int outfile )
{
    RGE_Master_Moving_Object::save(outfile);

    rge_write(outfile, &this->default_task, 2);
    rge_write(outfile, &this->search_radius, 4);
    rge_write(outfile, &this->work_rate, 4);
    rge_write(outfile, &this->drop_site, 2);
    rge_write(outfile, &this->backup_drop_site, 2);
    rge_write(outfile, &this->task_by_group, 1);

    short command_sound_num = -1;
    if( this->command_sound ){
        command_sound_num = this->command_sound->id;
    }
    rge_write(outfile, &command_sound_num, 2);

    short move_sound_num = -1;
    if( this->move_sound ){
        move_sound_num = this->move_sound->id;
    }
    rge_write(outfile, &move_sound_num, 2);

    rge_write(outfile, &this->run_pattern, 1);

    this->tasks->save(outfile);
}

void RGE_Master_Action_Object::play_command_sound()
{
    if( this->command_sound ){
        this->command_sound->play(true);
    }
}

void RGE_Master_Action_Object::play_move_sound()
{
    if( this->move_sound ){
        this->move_sound->play(true);
    }
}
