
/**
 * @file    Engine\TRB\DiamondMapView.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View
{
public:

    unsigned int last_attack_time;
    int flash_on;

    TRIBE_Diamond_Map_View();
};
