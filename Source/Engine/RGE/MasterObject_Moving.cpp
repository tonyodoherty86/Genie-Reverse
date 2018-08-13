
RGE_Master_Moving_Object::RGE_Master_Moving_Object( RGE_Master_Moving_Object *other_object, int do_setup = true )
{
    RGE_Master_Animated_Object::RGE_Master_Animated_Object(other_object, false);

    if( do_setup ){
        RGE_Master_Moving_Object::setup(other_object);
    }
}

RGE_Master_Moving_Object::RGE_Master_Moving_Object( int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup = true )
{
    RGE_Master_Animated_Object::RGE_Master_Animated_Object(
        infile,
        sprites,
        sounds,
        false);

    if( do_setup ){
        RGE_Master_Moving_Object::setup(infile, sprites, sounds);
    }
}

bool RGE_Master_Moving_Object::setup( RGE_Master_Moving_Object *other_object )
{
    RGE_Master_Animated_Object::setup(other_object);

    this->move_sprite       = other_object->move_sprite;
    this->run_sprite        = other_object->run_sprite;
    this->turn_speed        = other_object->turn_speed;
    this->size_class        = other_object->size_class;
    this->obj_trail_id      = other_object->obj_trail_id;
    this->obj_trail_options = other_object->obj_trail_options;
    this->obj_trail_spacing = other_object->obj_trail_spacing;
    this->move_algorithem   = other_object->move_algorithem;

    return true;
}

bool RGE_Master_Moving_Object::setup( int infile, RGE_Sprite **sprites, RGE_Sound **sounds )
{
    short sprite1_id = -1,
          sprite2_id = -1;

    RGE_Master_Animated_Object::setup(infile, sprites, sounds);

    rge_read(infile, &sprite1_id, 2);
    rge_read(infile, &sprite2_id, 2);
    rge_read(infile, &this->turn_speed, 4);
    rge_read(infile, &this->size_class, 1);
    rge_read(infile, &this->obj_trail_id, 2);
    rge_read(infile, &this->obj_trail_options, 1);
    rge_read(infile, &this->obj_trail_spacing, 4);
    rge_read(infile, &this->move_algorithem, 1);

    if( sprite1_id >= 0 ){
        this->move_sprite = sprites[sprite1_id];
    }else{
        this->move_sprite = nullptr;
    }

    if( sprite2_id >= 0 ){
        this->run_sprite = sprites[sprite2_id];
    }else{
        this->run_sprite = nullptr;
    }

    return true;
}

RGE_Master_Moving_Object::~RGE_Master_Moving_Object()
{
    RGE_Master_Animated_Object::~RGE_Master_Animated_Object();
}

void RGE_Master_Moving_Object::make_new_obj( RGE_Player *owner, float x, float y, float z )
{
    RGE_Master_Moving_Object *v5; // edi@1
    RGE_Static_Object *v6; // eax@2
    RGE_Moving_Object *v7; // eax@4

    v5 = this;
    if( this->recyclable && (v6 = RGE_Game_World::recycle_object_in_to_game(owner->world, this->master_type)) != 0 )
    {
        (*(void (**)(RGE_Static_Object *, RGE_Master_Moving_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))&v6->vfptr->gap4[0])(
            v6,
            v5,
            owner,
            LODWORD(x),
            LODWORD(y),
            LODWORD(z));
    }
    else
    {
        v7 = (RGE_Moving_Object *)operator new(0x180u);
        if( v7 )
            RGE_Moving_Object::RGE_Moving_Object(v7, v5, owner, x, y, z, 1);
    }
}

RGE_Master_Moving_Object *RGE_Master_Moving_Object::make_new_master()
{
    return new RGE_Master_Moving_Object(this);
}

void RGE_Master_Moving_Object::copy_obj( RGE_Master_Static_Object *source )
{
    RGE_Master_Moving_Object *v2; // esi@1

    v2 = this;

    RGE_Master_Animated_Object::copy_obj(source);

    v2->move_sprite = *(RGE_Sprite **)&source[1].master_type;
    v2->run_sprite = (RGE_Sprite *)source[1].name;
    v2->turn_speed = *(float *)&source[1].string_id;
    v2->size_class = source[1].id;
    v2->obj_trail_id = source[1].copy_id;
    v2->obj_trail_options = source[1].object_group;
    LODWORD(v2->obj_trail_spacing) = source[1].sprite;
    v2->move_algorithem = (char)source[1].death_sprite;
}

//----- (00451FB0) --------------------------------------------------------
void RGE_Master_Moving_Object::modify( float amount, char flag )
{
    if( flag == 6 )
        this->turn_speed = amount;
    else
        RGE_Master_Animated_Object::modify(amount, flag);
}

//----- (00451FE0) --------------------------------------------------------
void RGE_Master_Moving_Object::modify_delta( float amount, char flag )
{
    if( flag == 6 )
        this->turn_speed = amount + this->turn_speed;
    else
        RGE_Master_Animated_Object::modify_delta(amount, flag);
}

//----- (00452010) --------------------------------------------------------
void RGE_Master_Moving_Object::modify_percent( float amount, char flag )
{
    if( flag == 6 )
        this->turn_speed = amount * this->turn_speed;
    else
        RGE_Master_Animated_Object::modify_percent(amount, flag);
}

//----- (00452040) --------------------------------------------------------
void RGE_Master_Moving_Object::save( int outfile )
{
    RGE_Master_Moving_Object *v3; // edi@1
    signed int v4; // ecx@1
    int v5; // eax@1
    RGE_Sprite *v6; // eax@4
    int temp_move_sprite; // [sp+8h] [bp-8h]@2
    int temp_run_sprite; // [sp+Ch] [bp-4h]@6

    v3 = this;
    v4 = -1;
    v5 = (int)v3->move_sprite;
    if( v5 )
    {
        LOWORD(v5) = *(_WORD *)(v5 + 114);
        temp_move_sprite = v5;
    }
    else
    {
        temp_move_sprite = -1;
    }
    v6 = v3->run_sprite;
    if( v6 )
        LOWORD(v4) = v6->id;
    temp_run_sprite = v4;

    RGE_Master_Animated_Object::save(outfile);

    rge_write(outfile, &temp_move_sprite, 2);
    rge_write(outfile, &temp_run_sprite, 2);
    rge_write(outfile, &v3->turn_speed, 4);
    rge_write(outfile, &v3->size_class, 1);
    rge_write(outfile, &v3->obj_trail_id, 2);
    rge_write(outfile, &v3->obj_trail_options, 1);
    rge_write(outfile, &v3->obj_trail_spacing, 4);
    rge_write(outfile, &v3->move_algorithem, 1);
}
