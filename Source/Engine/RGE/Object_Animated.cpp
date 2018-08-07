
/**
 * @file    Engine\RGE\AnimatedObject.cpp
 * @author  Yvan Burrie
 * @date    2018/07/08
 * @version 1.0
 */

RGE_Animated_Object::RGE_Animated_Object(
    RGE_Master_Animated_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z,
    bool do_setup)
{
    RGE_Static_Object::RGE_Static_Object(
        &tobj,
        obj_owner,
        x,
        y,
        z,
        false);

    if( do_setup ){
        RGE_Animated_Object::setup(
            tobj,
            obj_owner,
            x,
            y,
            z);
    }
}

RGE_Animated_Object::RGE_Animated_Object(
    int infile,
    RGE_Game_World *gworld,
    bool do_setup)
{
    RGE_Static_Object::RGE_Static_Object(
        infile,
        gworld,
        false);

    if( do_setup ){
        RGE_Animated_Object::setup(
            infile,
            gworld);
    }
}

void RGE_Animated_Object::recycle_in_to_game(
    RGE_Master_Static_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z)
{
    RGE_Static_Object::recycle_in_to_game(
        tobj,
        obj_owner,
        x,
        y,
        z);

    this->speed = 0.0;

    RGE_Static_Object::set_sleep_flag(0);
}

bool RGE_Animated_Object::setup(
    RGE_Master_Animated_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z)
{
    bool update = RGE_Static_Object::setup(
        &tobj,
        obj_owner,
        x,
        y,
        z);

    this->speed = 0.0;

    RGE_Static_Object::set_sleep_flag(0);

    return update;
}

bool RGE_Animated_Object::setup(
    int infile,
    RGE_Game_World *gworld)
{
    RGE_Static_Object::setup(infile, gworld);

    rge_read(infile, &this->speed, 4);

    return true;
}

bool RGE_Animated_Object::update()
{
    bool update = RGE_Static_Object::update();

    switch( this->object_state ){

    case 3:
        if( this->master_obj->death_sprite ){
            this->set_object_state(4);
        }else{
            this->set_object_state(5);
        }
        break;

    case 4:
        if( this->sprite_list->is_animating(this->sprite) != true ){
            this->object_state = 5;
            this->speed = 0.0;
        }
        break;
    }

    this->sprite_list->update(
        this->owner->world->world_time_delta_seconds,
        this->speed);

    return update;
}

void RGE_Animated_Object::save(
    int outfile)
{
    RGE_Static_Object::save(
        outfile);

    rge_write(outfile, &this->speed, 4);
}

void RGE_Animated_Object::transform(
    RGE_Master_Static_Object *obj)
{
    RGE_Static_Object::transform(obj);
}

void RGE_Animated_Object::set_being_worked_on(
    RGE_Action_Object *work_obj,
    short action_type,
    char attack_flag)
{
    RGE_Static_Object::set_being_worked_on(
        work_obj,
        action_type,
        attack_flag);
}

void RGE_Animated_Object::release_being_worked_on(
    RGE_Static_Object *caller)
{
    RGE_Static_Object::release_being_worked_on(caller);

    RGE_Static_Object::set_sleep_flag(0);
}

double RGE_Animated_Object::getSpeed()
{
    return this->speed;
}
