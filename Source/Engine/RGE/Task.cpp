
/**
 * @file    Engine\RGE\Task.cpp
 * @author  Yvan Burrie
 * @date    2018/07/06
 * @version 1.0
 */

RGE_Task::RGE_Task(
    short id_in)
{
    this->id = id_in;
}

void RGE_Task::copy(
    RGE_Task *other_task)
{
    this->is_default        = other_task->is_default;
    this->action_type       = other_task->action_type;
    this->object_group      = other_task->object_group;
    this->object_id         = other_task->object_id;
    this->terrain_id        = other_task->terrain_id;
    this->attribute_type    = other_task->attribute_type;
    this->attribute_type2   = other_task->attribute_type2;
    this->attribute_type3   = other_task->attribute_type3;
    this->attribute_type4   = other_task->attribute_type4;
    this->work_val1         = other_task->work_val1;
    this->work_val2         = other_task->work_val2;
    this->work_range        = other_task->work_range;
    this->search_flag       = other_task->search_flag;
    this->search_wait_time  = other_task->search_wait_time;
    this->combat_level      = other_task->combat_level;
    this->combat_level_flag = other_task->combat_level_flag;
    this->work_flag         = other_task->work_flag;
    this->work_flag2        = other_task->work_flag2;
    this->owner_type        = other_task->owner_type;
    this->holding_attr      = other_task->holding_attr;
    this->state_building    = other_task->state_building;
    this->move_sprite       = other_task->move_sprite;
    this->work_sprite       = other_task->work_sprite;
    this->work_sprite2      = other_task->work_sprite2;
    this->carry_sprite      = other_task->carry_sprite;
    this->work_sound        = other_task->work_sound;
    this->work_sound2       = other_task->work_sound2;
}

void RGE_Task::load(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds)
{
    short sprite_id = -1;
    short sound_id  = -1;

    rge_read(infile, &this->id, 2);

    rge_read(infile, &this->is_default, 1);

    rge_read(infile, &this->action_type, 2);

    rge_read(infile, &this->object_group, 2);
    rge_read(infile, &this->object_id, 2);

    rge_read(infile, &this->terrain_id, 2);

    rge_read(infile, &this->attribute_type, 2);
    rge_read(infile, &this->attribute_type2, 2);
    rge_read(infile, &this->attribute_type3, 2);
    rge_read(infile, &this->attribute_type4, 2);

    rge_read(infile, &this->work_val1, 4);
    rge_read(infile, &this->work_val2, 4);
    rge_read(infile, &this->work_range, 4);

    rge_read(infile, &this->search_flag, 1);
    rge_read(infile, &this->search_wait_time, 4);

    rge_read(infile, &this->combat_level, 1);
    rge_read(infile, &this->combat_level_flag, 1);

    rge_read(infile, &this->work_flag, 2);
    rge_read(infile, &this->work_flag2, 2);

    rge_read(infile, &this->owner_type, 1);
    rge_read(infile, &this->holding_attr, 1);
    rge_read(infile, &this->state_building, 1);

    rge_read(infile, &sprite_id, 2);
    if( sprite_id != -1 ){
        this->move_sprite = sprites[sprite_id];
    }else{
        this->move_sprite = nullptr;
    }

    rge_read(infile, &sprite_id, 2);
    if( sprite_id != -1 ){
        this->work_sprite = sprites[sprite_id];
    }else{
        this->work_sprite = nullptr;
    }

    rge_read(infile, &sprite_id, 2);
    if( sprite_id != -1 ){
        this->work_sprite2 = sprites[sprite_id];
    }else{
        this->work_sprite2 = nullptr;
    }

    rge_read(infile, &sprite_id, 2);
    if( sprite_id != -1 ){
        this->carry_sprite = sprites[sprite_id];
    }else{
        this->carry_sprite = nullptr;
    }

    rge_read(infile, &sound_id, 2);
    if( sound_id != -1 ){
        this->work_sound = sounds[sound_id];
    }else{
        this->work_sound = nullptr;
    }

    rge_read(infile, &sound_id, 2);
    if( sound_id != -1 ){
        this->work_sound2 = sounds[sound_id];
    }else{
        this->work_sound2 = nullptr;
    }
}

void RGE_Task::save(
    int outfile)
{
    short sprite_id = -1;
    short sound_id  = -1;

    rge_write(outfile, this->task_type, 2);

    rge_write(outfile, &this->id, 2);

    rge_write(outfile, &this->is_default, 1);

    rge_write(outfile, &this->action_type, 2);

    rge_write(outfile, &this->object_group, 2);
    rge_write(outfile, &this->object_id, 2);

    rge_write(outfile, &this->terrain_id, 2);

    rge_write(outfile, &this->attribute_type, 2);
    rge_write(outfile, &this->attribute_type2, 2);
    rge_write(outfile, &this->attribute_type3, 2);
    rge_write(outfile, &this->attribute_type4, 2);

    rge_write(outfile, &this->work_val1, 4);
    rge_write(outfile, &this->work_val2, 4);
    rge_write(outfile, &this->work_range, 4);

    rge_write(outfile, &this->search_flag, 1);
    rge_write(outfile, &this->search_wait_time, 4);

    rge_write(outfile, &this->combat_level, 1);
    rge_write(outfile, &this->combat_level_flag, 1);

    rge_write(outfile, &this->work_flag, 2);
    rge_write(outfile, &this->work_flag2, 2);

    rge_write(outfile, &this->owner_type, 1);
    rge_write(outfile, &this->holding_attr, 1);
    rge_write(outfile, &this->state_building, 1);

    if( this->move_sprite ){
        sprite_id = this->move_sprite->id
    }else{
        sprite_id = -1;
    }
    rge_write(outfile, &sprite_id, 2);

    if( this->work_sprite ){
        sprite_id = this->work_sprite->id
    }else{
        sprite_id = -1;
    }
    rge_write(outfile, &sprite_id, 2);

    if( this->work_sprite2 ){
        sprite_id = this->work_sprite2->id
    }else{
        sprite_id = -1;
    }
    rge_write(outfile, &sprite_id, 2);

    if( this->carry_sprite ){
        sprite_id = this->carry_sprite->id
    }else{
        sprite_id = -1;
    }
    rge_write(outfile, &sprite_id, 2);

    if( this->work_sound ){
        sound_id = this->work_sound->id
    }else{
        sound_id = -1;
    }
    rge_write(outfile, &sound_id, 2);

    if( this->work_sound2 ){
        sound_id = this->work_sound2->id
    }else{
        sound_id = -1;
    }
    rge_write(outfile, &sound_id, 2);
}
