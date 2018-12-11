#pragma once

/**
 * @file    Engine\RGE\AiBaseItem.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class BaseItem
{
public:

    int typeIDValue = -1;

    int gameIDValue = -1;

    int uniqueIDValue = -1;

    char nameValue[64];

    float xValue,
          yValue,
          zValue;

    float xSizeValue,
          ySizeValue,
          zSizeValue;

    int skipValue = 0;

    BaseItem();
    BaseItem(int tid, int gid, int uid, char *n, float x, float y, float z, float xs, float ys, float zs);
    BaseItem(BaseItem *bi);

    bool operator==(BaseItem *two);
    bool operator!=(BaseItem *two);
    bool operator<(BaseItem *two);
    bool operator>(BaseItem *two);

    int typeID();
    int gameID();
    int uniqueID();
    char *name();

    double x();
    double y();
    double z();
    double xSize();
    double ySize();
    double zSize();

    int skip();

    void setTypeID(int v);
    void setGameID(int v);
    void setUniqueID(int v);
    void setName(char *n);
    void setX(float v);
    void setY(float v);
    void setZ(float v);
    void setXSize(float v);
    void setYSize(float v);
    void setZSize(float v);
    void setSkip(int v);
};
