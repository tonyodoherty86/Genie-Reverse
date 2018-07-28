
/**
 * @file    Engine\RGE\AiBaseItem.cpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

void BaseItem::BaseItem()
{
    strcpy(this->nameValue, message_in);
}

void BaseItem::BaseItem(
    int tid,
    int gid,
    int uid,
    char *n,
    float x,
    float y,
    float z,
    float xs,
    float ys,
    float zs)
{
    this->typeIDValue   = tid;
    this->gameIDValue   = gid;
    this->xValue        = x;
    this->yValue        = y;
    this->uniqueIDValue = uid;
    this->xSizeValue    = xs;
    this->ySizeValue    = ys;
    this->zValue        = z;
    this->zSizeValue    = zs;
    strncpy(this->nameValue, n, sizeof(BaseItem::nameValue) - 1);
}

void BaseItem::BaseItem(BaseItem *bi)
{
    this->typeIDValue   = bi->typeIDValue;
    this->gameIDValue   = bi->gameIDValue;
    this->uniqueIDValue = bi->uniqueIDValue;
    this->xValue        = bi->xValue;
    this->yValue        = bi->yValue;
    this->zValue        = bi->zValue;
    this->xSizeValue    = bi->xSizeValue;
    this->ySizeValue    = bi->ySizeValue;
    this->zSizeValue    = bi->zSizeValue;
    this->skipValue     = bi->skipValue;
    strcpy(this->nameValue, bi->nameValue);
}

bool operator==(BaseItem *two)
{
    return this->gameIDValue == two->gameIDValue &&
           this->xValue == two->xValue &&
           this->yValue == two->yValue;
}

bool operator!=(BaseItem *two)
{
    return operator==(this, two) == false;
}

bool operator<(BaseItem *two)
{
    return this->gameIDValue < two->gameIDValue;
}

bool operator>(BaseItem *two)
{
    return this->gameIDValue > two->gameIDValue;
}

int BaseItem::typeID()
{
    return this->typeIDValue;
}

int BaseItem::gameID()
{
    return this->gameIDValue;
}

int BaseItem::uniqueID()
{
    return this->uniqueIDValue;
}

char *BaseItem::name()
{
    return this->nameValue;
}

double BaseItem::x()
{
    return this->xValue;
}

double BaseItem::y()
{
    return this->yValue;
}

double BaseItem::z()
{
    return this->zValue;
}

double BaseItem::xSize()
{
    return this->xSizeValue;
}

double BaseItem::ySize()
{
    return this->ySizeValue;
}

double BaseItem::zSize()
{
    return this->zSizeValue;
}

int BaseItem::skip()
{
    return this->skipValue;
}

void BaseItem::setTypeID(int v)
{
    this->typeIDValue = v;
}

void BaseItem::setGameID(int v)
{
    this->gameIDValue = v;
}

void BaseItem::setUniqueID(int v)
{
    this->uniqueIDValue = v;
}

void BaseItem::setName(char *n)
{
    strncpy(this->nameValue, n, sizeof(BaseItem::nameValue) - 1);
}

void BaseItem::setX(float v)
{
    this->xValue = v;
}

void BaseItem::setY(float v)
{
    this->yValue = v;
}

void BaseItem::setZ(float v)
{
    this->zValue = v;
}

void BaseItem::setXSize(float v)
{
    this->xSizeValue = v;
}

void BaseItem::setYSize(float v)
{
    this->ySizeValue = v;
}

void BaseItem::setZSize(float v)
{
    this->zSizeValue = v;
}

void BaseItem::setSkip(int v)
{
    this->skipValue = v;
}
