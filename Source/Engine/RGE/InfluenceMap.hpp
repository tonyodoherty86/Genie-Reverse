
/**
 * @file    Engine\RGE\InfluenceMap.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class InfluenceMap
{
public:

    int xSizeValue,
        ySizeValue;

    int xReferencePointValue,
        yReferencePointValue;

    char *valueValue;
    char **rowValue;

    int coverageCountValue;
    int connectionCountValue;

    char unchangeableLimitValue;

    InfluenceMap(int x, int y, char initialValue);
    InfluenceMap(int infile);

    ~InfluenceMap();

    int initialize(char initialValue);

    void save(int outfile);

    void load(int infile);

    void printToFile(char *filename);

    void setReferencePoint(int x, int y);

    int lookupValue(int x, int y);
    int setValue(int x, int y, char v);
    int setValue(int minX, int minY, int maxX, int maxY, char v);
    int incrementValue(int x, int y, char v);
    int incrementValue(int minX, int minY, int maxX, int maxY, char v);
    int decrementValue(int x, int y, char v);
    int decrementValue(int minX, int minY, int maxX, int maxY, char v);

    int setCoverageCount(XYPoint *min, XYPoint *max, int valueLevel);
    int setConnectionCount(XYPoint *min, XYPoint *max, int valueLevel, int countOrthogonalEdgesAsConnections, int countDiagonalEdgesAsConnections, int countDiagonalConnections);

    int coverageIncluding(XYPoint *min, XYPoint *max, char valueLevel, char newValueLevel);
    int connectionsIncluding(XYPoint *min, XYPoint *max, char valueLevel, char newValueLevel, int countOrthogonalEdgesAsConnections, int countDiagonalEdgesAsConnections, int countDiagonalConnections);

    void setUnchangeableLimit(char uL);

    int maxValue();
};
