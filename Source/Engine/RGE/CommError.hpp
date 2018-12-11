#pragma once

/**
 * @file    Engine\RGE\CommError.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

#include "IDA.h"
#include "CommHandler.hpp"

class RGE_Comm_Error
{
public:

    HWND *HostHWND;

    int LastReportedError;

    RGE_Comm_Error(HWND *Host);

    void NotifyWindowParam(COMMMESSAGES msg, LPARAM lparam);

    ~RGE_Comm_Error();

    void ShowReturn(int hr, char *Text);
};
