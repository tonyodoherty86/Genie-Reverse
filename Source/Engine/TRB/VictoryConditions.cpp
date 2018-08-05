
/**
 * @file    Engine\TRB\VictoryConditions.cpp
 * @author  Yvan Burrie
 * @date    2018/08/03
 * @version 1.0
 */

void TRIBE_Victory_Conditions::handle_condition( RGE_Victory_Entry *node )
{
    switch( node->command ){

    case 100:/* TODO */
        this->handle_tech(node);
        break;

    default:
        RGE_Victory_Conditions::handle_condition(node);
    }
}

void TRIBE_Victory_Conditions::handle_tech( RGE_Victory_Entry *node )
{
    if( this->player &&
        node->state == 0 &&
        this->get_tech_state(node->count) == 3 ){

        node->state = 2;
    }
}

char TRIBE_Victory_Conditions::add_tech( char v_group, int tech_id )
{
    if( RGE_Victory_Entry *entry = this->add(v_group, 0) ){
        entry->command = 100;
        entry->count = tech_id;
        return true;
    }else{
        return false;
    }
}
