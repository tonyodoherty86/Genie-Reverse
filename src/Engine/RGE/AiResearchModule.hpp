
/**
 * @file    Engine\RGE\AiResearchModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class ResearchAIModule : public AIModule
{
public:

    MainDecisionAIModule *md;

    TechnologyItem techTree;

    int techTreeLengthValue;

    char techTreeNameValue[257];

    ResearchAIModule(void *pW, int playerID);
    ResearchAIModule(int playerID, int infile);

    ~ResearchAIModule();

    void setMainDecisionAI(MainDecisionAIModule *m);
    int save(int outfile);
    TechnologyItem *resourceCost(int id);
    int buildable(BuildItem *bi);

    FILE *loadTechnologyTree(char *lName);

    int numberTechnologyItems();
    char *technologyTreeName();
    void removeOldTechTree();

    TechnologyItem *item(int id);
};
