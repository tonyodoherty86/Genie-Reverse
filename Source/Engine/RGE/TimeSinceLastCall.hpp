#pragma once

/**
 * @file    Engine\RGE\TimeSinceLastCall.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class RGE_TimeSinceLastCall
{
public:

    char TBuff[255];
    unsigned int lowTSLC;
    unsigned int highTSLC;
    unsigned int TSLC;
    unsigned int aTSLC[101];
    int Offset;
    unsigned int LastCall;
    unsigned int FirstCall;
    unsigned int Now;
    unsigned int cps;

    RGE_TimeSinceLastCall();

    ~RGE_TimeSinceLastCall();

    unsigned int GetAvg(int duration);
    unsigned int Get();
    unsigned int Set();
    void Skip();
    RGE_TimeSinceLastCall *GetAvgInfo(int duration);
    RGE_TimeSinceLastCall *GetHiLoMaxInfo(int duration);
    RGE_TimeSinceLastCall *GetHiLoInfo(int duration);
    unsigned int CPS();
    unsigned int GetFirstCall();
    RGE_TimeSinceLastCall *GetElapsedFirstCall();
    void Test();
};
