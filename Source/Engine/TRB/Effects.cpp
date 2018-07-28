
/**
 * @file        Engine\TRB\Effects.cpp
 * @author    Yvan Burrie
 * @date        2018/06/26
 * @version 1.0
 */

void TRIBE_Effects::TRIBE_Effects(int infile)
{
    RGE_Effects::RGE_Effects(infile);
}

void TRIBE_Effects::TRIBE_Effects(char *effect_file)
{
    RGE_Effects::RGE_Effects(effect_file);
}

void TRIBE_Effects::do_effect(short current_effect, RGE_Player *player)
{
    RGE_Effect *v3; // esi@2
    signed int v4; // ebx@3
    int v5; // edi@4
    int v6; // eax@5
    TRIBE_Effects *v7; // [sp+4h] [bp-4h]@1

    v7 = this;
    if( current_effect < this->effect_num )
    {
        v3 = &this->effects[current_effect];
        if( v3 )
        {
            v4 = 0;
            if( v3->effect_list_num > 0 )
            {
                v5 = 0;
                do
                {
                    v6 = (int)&v3->effect_list[v5].command;
                    if( *(_BYTE *)v6 != 101 && *(_BYTE *)v6 == 102 )
                        TRIBE_Player::tech_abling((TRIBE_Player *)player, (signed __int64)*(float *)(v6 + 8), 0);
                    ++v4;
                    ++v5;
                }
                while ( v4 < v3->effect_list_num );
                this = v7;
            }
            RGE_Effects::do_effect((RGE_Effects *)&this->vfptr, current_effect, player);
        }
    }
}

void TRIBE_Effects::do_tech_effect(short current_effect, TRIBE_Player *player)
{
    for( int i = 0; i < this->effects[current_effect]->effect_list_num; i++ ){
        RGE_Effect_Command *effect_command = this->effects[current_effect]->effect_list[i].command;
        if( effect_command->command != 101 &&
            effect_command->command == 102 ){
            player->tech_abling((int)effect_command->change_amount, 0);
        }
    }
}
