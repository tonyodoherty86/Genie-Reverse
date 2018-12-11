#pragma once

/**
 * @file    Engine\PicturePanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

#include "Panel.hpp"

class TPicture;

class TPicturePanel : public TPanel
{
public:

    char pic_name[12];

    int res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;

    enum PictureType
    {
        Picture = 0x00,
        Shape   = 0x01,
    }
    pic_type;

    TPicture *pic;

    TShape *shape;
};
