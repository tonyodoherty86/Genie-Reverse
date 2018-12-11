#pragma once

/**
 * @file    Engine\TRB\MasterPlayer.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#include <RGE/MasterPlayer.hpp>

class TRIBE_Master_Player : public RGE_Master_Player
{
public:

    TRIBE_Master_Player(_iobuf *infile);
    TRIBE_Master_Player(int infile);

    ~TRIBE_Master_Player();

    void load_master_object(int infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, short index);
    void load_object(_iobuf *infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, short index);
};
