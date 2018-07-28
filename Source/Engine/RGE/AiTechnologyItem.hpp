
/**
 * @file    Engine\RGE\AiTechnologyItem.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class TechnologyItem
{
public:

    TechnologyItem *next,
                   *prev;

    int idValue;

    char nameValue[64];

    ResourceItem *resourceCostValue;

    TechnologyItem();
    TechnologyItem(int i, char *n, ResourceItem r);
    TechnologyItem(TechnologyItem *ti);

    ~TechnologyItem();

    bool operator==(TechnologyItem *two);
    bool operator!=(TechnologyItem *two);
    bool operator<(TechnologyItem *two);
    bool operator>(TechnologyItem *two);

    int id();

    char *name();

    ResourceItem *resourceCost();
};
