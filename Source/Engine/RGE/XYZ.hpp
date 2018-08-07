
/**
 * @file    Engine\RGE\XYZ.hpp
 * @author  Yvan Burrie
 * @date    2018/08/07
 * @version 1.0
 */

class XYZ
{
public:

    int xValue,
        yValue,
        zValue;

    XYZ();

    XYZ( int a, int b, int c );

    int operator==(XYZ *one, XYZ *two);
    int operator!=(XYZ *one, XYZ *two);
    XYZ *operator+(XYZ *result, XYZ *__$ReturnUdt);
    XYZ *operator-(XYZ *result, XYZ *__$ReturnUdt);

    void rotateXYByFacet( XYZ *refPoint, XYZ *rPoint, char facet );
};
