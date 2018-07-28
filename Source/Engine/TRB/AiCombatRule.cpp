
/**
 * @file    Engine\TRB\AiCombatRule.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

int CombatRuleSystem::loadRules(char *rName)
{
    char *v2; // ebx@1
    CombatRuleSystem *v3; // ebp@1
    FILE *v4; // esi@3
    int result; // eax@14
    char commentTemp1; // [sp+12h] [bp-10Eh]@5
    char commentTemp2; // [sp+13h] [bp-10Dh]@5
    int unitIndex; // [sp+14h] [bp-10Ch]@7
    int rating; // [sp+18h] [bp-108h]@7
    int targetUnitType; // [sp+1Ch] [bp-104h]@7
    char temp[256]; // [sp+20h] [bp-100h]@3

    v2 = rName;
    v3 = this;
    if ( strcmp(rName, aNone_2) && rName && (sprintf(temp, aS_2, rName), (v4 = fopen(temp, Mode)) != 0) )
    {
        memset(v3->ratingValue, 0x32u, sizeof(v3->ratingValue));
        if ( fgets(temp, 256, v4) )
        {
            do
            {
                sscanf(temp, aCC_1, &commentTemp1, &commentTemp2);
                if ( commentTemp1 != 47 || commentTemp2 != 47 )
                {
                    sscanf(temp, aDDD, &unitIndex, &targetUnitType, &rating);
                    if ( unitIndex >= 0 && unitIndex < 50 )
                        *(&v3->ratingValue[50 * unitIndex] + targetUnitType) = rating;
                }
            }
            while ( fgets(temp, 256, v4) );
            v2 = rName;
        }
        fclose(v4);
        if ( strstr(v2, SubStr) )
            _unlink(v2);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int CombatRuleSystem::bestUnitTypeToAttack(int tType)
{
    return -1;
}

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int tType)
{
    return -1;
}
