
/**
 * @file    Engine\RGE\AiConstructionModule.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class ConstructionAIModule : public AIModule
{
public:

    int numberConstructionLotsValue;
    ConstructionItem constructionLots;

    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;

    char constructionPlanNameValue[257];

    float xReferencePointValue,
          yReferencePointValue,
          zReferencePointValue;

    int mapXSizeValue,
        mapYSizeValue;

    enum PlacementResult
    {
        PlacementOk               = 0x00,
        PlacementOnImpassableTile = 0x01,
        PlacementObstructed       = 0x02,
        PlacementUnknownObject    = 0x03,
        PlacementFailed           = 0x04,
        PlacementFailedNoLot      = 0x05,
    }
    lastPlacementReturnCodeValue;

    ConstructionAIModule(void *pW, int playerID);
    ConstructionAIModule(int playerID, int infile);

    ~ConstructionAIModule();

    int save(int outfile);

    FILE *loadConstructionPlan(char *pName, int mXSize, int mYSize, float xRef, float yRef, float zRef);

    char *constructionPlanName();
    void setReferencePoint(int mXSize, int mYSize, float x, float y, float z);
    double xReferencePoint();
    double yReferencePoint();
    ConstructionItem *__stdcall placeStructure(BuildItem *bi);
    PlacementResult lastPlacementReturnCode();
    void setBuilt(ConstructionItem *ci, int v);
    int unplaceStructure(ConstructionItem *ci, int decBA);
    int unplaceStructure(float x, float y, int decBA);

    void decrementBuildAttempts(float x, float y, int n);
    void incrementBuildAttempts(float x, float y, int n);

    ConstructionItem *lot(float x, float y);
    ConstructionItem *randomLot(float x, float y);

    void removeOldLots();
};
