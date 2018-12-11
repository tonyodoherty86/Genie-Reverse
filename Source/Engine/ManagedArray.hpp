#pragma once

/**
 * @file    Engine\ManagedArray.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class ManagedArray//<int>/* TODO: make this a template */
{
public:

    int *value;

    int numberValue;

    int desiredNumberValue;

    int maximumSizeValue;

    int *resize(int s);

    int contains(const int *r);

    int add(int r);

    int *operator[](int v);

    int remove(int r);
};
