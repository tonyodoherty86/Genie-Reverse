
/**
 * @file    Engine\TRB\AiCombatRule.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

class CombatRuleSystem
{
public:

    char ratingValue[2500];

    int loadRules(
        char *rName);

    int bestUnitTypeToAttack(
        int tType);

    int bestUnitTypeToDefendAgainst(
        int tType);
};
