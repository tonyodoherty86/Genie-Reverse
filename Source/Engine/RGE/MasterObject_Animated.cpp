
RGE_Master_Animated_Object::RGE_Master_Animated_Object( RGE_Master_Animated_Object *other_object, int do_setup = true )
{
    RGE_Master_Static_Object::RGE_Master_Static_Object(other_object, false);

    if( do_setup ){
        this->setup(other_object);
    }
}

RGE_Master_Animated_Object::RGE_Master_Animated_Object(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds,
    bool do_setup = true )
{
    RGE_Master_Static_Object::RGE_Master_Static_Object(
        infile,
        sprites,
        sounds,
        false);

    if( do_setup ){
        RGE_Master_Animated_Object::setup(infile, sprites, sounds);
    }
}

bool RGE_Master_Animated_Object::setup( RGE_Master_Animated_Object *other_object )
{
    RGE_Master_Static_Object::setup(other_object);

    this->speed = other_object->speed;

    return true;
}

bool RGE_Master_Animated_Object::setup( int infile, RGE_Sprite **sprites, RGE_Sound **sounds )
{
    RGE_Master_Static_Object::setup(infile, sprites, sounds);

    rge_read(infile, &this->speed, 4);

    return true;
}

RGE_Master_Animated_Object::~RGE_Master_Animated_Object()
{
    RGE_Master_Static_Object::~RGE_Master_Static_Object();
}

RGE_Static_Object *RGE_Master_Animated_Object::make_new_obj( RGE_Player *owner, float x, float y, float z )
{
    if( this->recyclable ){
        if( RGE_Static_Object *obj = owner->world->recycle_object_in_to_game(this->master_type) ){
            obj->recycle_into_game(this, owner, x, y, z);
            return obj;
        }
    }
    return new RGE_Animated_Object(this, owner, x, y, z);
}

RGE_Master_Static_Object *RGE_Master_Animated_Object::make_new_master()
{
    return new RGE_Master_Animated_Object(this);
}

void RGE_Master_Animated_Object::copy_obj( RGE_Master_Static_Object *source )
{
    RGE_Master_Static_Object::copy_obj(source);

    this->speed = source->speed;
}

void RGE_Master_Animated_Object::modify( float amount, char flag )
{
    switch( flag ){

    case 5:
        this->speed = amount;
        break;

    default:
        RGE_Master_Static_Object::modify(amount, flag);
    }
}

void RGE_Master_Animated_Object::modify_delta( float amount, char flag )
{
    switch( flag ){

    case 5:
        this->speed += amount;
        break;

    default:
        RGE_Master_Static_Object::modify_delta(amount, flag);
    }
}

void RGE_Master_Animated_Object::modify_percent( float amount, char flag )
{
    switch( flag ){

    case 5:
        this->speed *= amount;
        break;

    default:
        RGE_Master_Static_Object::modify_percent(amount, flag);
    }
}

void RGE_Master_Animated_Object::save(int outfile)
{
    RGE_Master_Static_Object::save(outfile);

    rge_write(outfile, &this->speed, 4);
}
