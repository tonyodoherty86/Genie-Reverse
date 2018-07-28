
RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object *other_object, bool do_setup)
{
    RGE_Master_Combat_Object::RGE_Master_Combat_Object(
        (RGE_Master_Combat_Object *)&other_object->vfptr,
        false);
    
    if( do_setup ){
        this->setup(other_object);
    }
}

RGE_Master_Missile_Object::RGE_Master_Missile_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, bool do_setup)
{
    RGE_Master_Combat_Object::RGE_Master_Combat_Object(
        infile,
        sprites,
        sounds,
        false);
    
    if( do_setup ){
        RGE_Master_Missile_Object::setup(infile, sprites, sounds);
    }
}

bool RGE_Master_Missile_Object::setup(RGE_Master_Missile_Object *other_object)
{
    RGE_Master_Combat_Object::setup(
        other_object);
    
    this->missile_type         = other_object->missile_type;
    this->targetting_type      = other_object->targetting_type;
    this->missile_hit_info     = other_object->missile_hit_info;
    this->missile_die_info     = other_object->missile_die_info;
    this->area_effect_specials = other_object->area_effect_specials;
    this->ballistics_ratio     = other_object->ballistics_ratio;
    
    return true;
}

bool RGE_Master_Missile_Object::setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
    RGE_Master_Combat_Object::setup(infile, sprites, sounds);
    
    rge_read(infile, &this->missile_type, 1);
    rge_read(infile, &this->targetting_type, 1);
    rge_read(infile, &this->missile_hit_info, 1);
    rge_read(infile, &this->missile_die_info, 1);
    rge_read(infile, &this->area_effect_specials, 1);
    rge_read(infile, &this->ballistics_ratio, 4);
    
    return true;
}

RGE_Master_Missile_Object::~RGE_Master_Missile_Object()
{
    RGE_Master_Combat_Object::~RGE_Master_Combat_Object();
}

void __thiscall RGE_Master_Missile_Object::make_new_obj(RGE_Player *owner, float x, float y, float z)
{
    RGE_Static_Object *v6;

    if( this->recyclable && (v6 = owner->world->recycle_object_in_to_game(this->master_type)) != nullptr ){
        v6->recycle_in_to_game(
            this,
            owner,
            x,
            y,
            z);
        return v6;
    }
    return RGE_Missile_Object::RGE_Missile_Object(this, owner, x, y, z, 1);
}

void RGE_Master_Missile_Object::make_new_master()
{
    return new RGE_Master_Missile_Object::RGE_Master_Missile_Object(this, true);
}

void RGE_Master_Missile_Object::copy_obj(RGE_Master_Missile_Object *source)
{
    this->missile_type         = source->missile_type;
    this->targetting_type      = source->targetting_type;
    this->missile_hit_info     = source->missile_hit_info;
    this->missile_die_info     = source->missile_die_info;
    this->area_effect_specials = source->area_effect_specials;
    this->ballistics_ratio     = source->ballistics_ratio;
}

void RGE_Master_Missile_Object::modify(float amount, char flag)
{
    switch( flag ){
    
    case 19:
        this->targetting_type = (double)amount;
        break;
    default:
        RGE_Master_Combat_Object::modify(amount, flag);
}

void RGE_Master_Missile_Object::modify_delta(float amount, char flag)
{
    if( flag == 19 )
        this->targetting_type = (signed __int64)amount;
    RGE_Master_Combat_Object::modify_delta(amount, flag);
}

void RGE_Master_Missile_Object::modify_percent(float amount, char flag)
{
    if( flag == 19 )
        this->targetting_type = (signed __int64)amount;
    RGE_Master_Combat_Object::modify_percent(amount, flag);
}

void RGE_Master_Missile_Object::save(int outfile)
{
    RGE_Master_Combat_Object::save(outfile);
    
    rge_write(outfile, &this->missile_type, 1);
    rge_write(outfile, &this->targetting_type, 1);
    rge_write(outfile, &this->missile_hit_info, 1);
    rge_write(outfile, &this->missile_die_info, 1);
    rge_write(outfile, &this->area_effect_specials, 1);
    rge_write(outfile, &this->ballistics_ratio, 4);
}
