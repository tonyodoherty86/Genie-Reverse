
/**
 * @file    Engine\RGE\MasterPlayer.hpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

RGE_Master_Player::RGE_Master_Player(int infile)
{
    rge_read(infile, this->name, 20);

    rge_read(infile, &this->attribute_num, 2);

    rge_read(infile, &this->tribe_effect, 2);

    if( this->attribute_num > 0 ){
        this->attributes = new float[this->attribute_num];
        rge_read(infile, this->attributes, 4 * this->attribute_num);
    }else{
        this->attributes = nullptr;
    }

    rge_read(infile, &this->culture, 1);
}

RGE_Master_Player::~RGE_Master_Player()
{
    if( this->attribute_num > 0 &&
        this->attributes ){
        free(this->attributes);
        this->attributes = nullptr;
        this->attribute_num = 0;
    }
    if( this->master_object_num > 0 &&
        this->master_objects ){

        for( int master_id = 0; master_id < this->master_object_num; master_id++ ){
            if( this->master_objects[master_id] ){
                delete this->master_objects[master_id];
                this->master_objects[master_id] = nullptr;
            }
        }
        free(this->master_objects);
        this->master_objects = nullptr;
        this->master_object_num = 0;
    }
}

void RGE_Master_Player::finish_init(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds)
{
    rge_read(infile, &this->master_object_num, 2);

    if( this->master_object_num > 0 ){

        this->master_objects = (RGE_Master_Static_Object **)calloc(this->master_object_num, 4);

        rge_read(infile, this->master_objects, 4 * this->master_object_num);

        for( int master_id = 0; master_id < this->master_object_num; master_id++ ){

            if( this->master_objects[master_id] ){

                char master_type;
                rge_read(infile, &master_type, 1);

                this->load_master_object(
                    infile,
                    master_type,
                    sprites,
                    sounds,
                    master_id);
            }else{
                this->master_objects[master_id] = nullptr;
            }
        }
    }else{
        this->master_objects = nullptr;
    }
}

void RGE_Master_Player::load_master_object(
    int infile,
    char obj_type,
    RGE_Sprite **sprites,
    RGE_Sound **sounds,
    short index)
{
    switch ( obj_type ){

    case RGE_STATIC_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Static_Object(infile, sprites, sounds, true);
        break;

    case RGE_ANIMATED_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Animated_Object(infile, sprites, sounds, true);
        break;

    case RGE_DOPPLEGANGER_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Doppleganger_Object(infile, sprites, sounds, true);
        break;

    case RGE_MOVING_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Moving_Object(infile, sprites, sounds, true);
        break;

    case RGE_ACTION_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Action_Object(infile, sprites, sounds, true);
        break;

    case RGE_COMBAT_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Combat_Object(infile, sprites, sounds, true);
        break;

    case RGE_MISSILE_OBJECT_TYPE:
        this->master_objects[index] = new RGE_Master_Missile_Object(infile, sprites, sounds, true);
        break;
    }
}

void RGE_Master_Player::create_master_object_space(
    short count)
{
    this->master_object_num = count;
    if( count > 0 ){
        this->master_objects = (RGE_Master_Static_Object **)calloc(count, 4u);
    }
}

void RGE_Master_Player::save(
    int outfile)
{
    rge_write(outfile, &this->type, 1);

    rge_write(outfile, this->name, sizeof(RGE_Master_Player::name));

    rge_write(outfile, &this->attribute_num, 2);

    rge_write(outfile, &this->tribe_effect, 2);

    if( this->attribute_num > 0 ){
        rge_write(outfile, this->attributes, 4 * this->attribute_num);
    }
    rge_write(outfile, &this->culture, 1);

    rge_write(outfile, &this->master_object_num, 2);

    if( this->master_object_num > 0 ){

        rge_write(outfile, this->master_objects, 4 * this->master_object_num);

        for( int master_id = 0; master_id < this->master_object_num; master_id++ ){
            this->master_objects[master_id]->save(outfile);
        }
    }
}
