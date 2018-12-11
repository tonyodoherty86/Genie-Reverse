#pragma once

/**
 * @file    Engine\RGE\AnimatedObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

#ifndef RGE_ANIMATED_OBJECT_TYPE
    #define RGE_ANIMATED_OBJECT_TYPE 20
#endif

#include "Object_Static.hpp"

class RGE_Animated_Object : public RGE_Static_Object
{
public:

    char type = RGE_ANIMATED_OBJECT_TYPE;

    float speed;

    double getSpeed();
};
