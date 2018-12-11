#pragma once

/**
 * @file    Engine\RGE\AiResourceItem.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

class ResourceItem
{
    ResourceItem *next,
                 *prev;

    int valueValue[8];
    int sortedValue[8];
    int sortedIndexValue[8];
    int numberValue;

    ResourceItem();
    ResourceItem(int n);
    ResourceItem(int n, int *v);
    ResourceItem(ResourceItem *ri);

    ~ResourceItem();

    ResourceItem *operator+=(ResourceItem *ri);
    int operator ==(ResourceItem *two);
    int operator !=(ResourceItem *two);

    int value(int n);
    void setValue(int n, int v);
    void incrementValue(int n, int v);
    void setAllValues(int v);
    int number();
    int largestValueIndex(int num);
    int sortLarge();
};
