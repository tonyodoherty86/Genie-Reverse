#pragma once

class TCommunications_Handler;

/**
 * @file    Engine\RGE\CommSync.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class RGE_Communications_Synchronize
{
public:

    TCommunications_Handler *Comm;

    unsigned int CheckTime;
    unsigned int CheckTurn;

    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    unsigned int Offset;
    int DoChecksums;
    unsigned int LastWorldRandom;
    unsigned int GameWorldChecksum;

    struct CHECKSUMARRAY
    {
        unsigned int PlayerNo;
        unsigned int WTime;
        unsigned int WTurn;
        int cs1;
        int cs2;
        int cs3;
        int cs4;
        int cs5;
        unsigned int Random;
    }
    Check[55];

    RGE_Communications_Synchronize(TCommunications_Handler *c);

    ~RGE_Communications_Synchronize();

    int Add(unsigned int player, unsigned int worldtime, unsigned int worldturn, unsigned int worldrandom, int cs1, int cs2, int cs3, int cs4, int cs5);
    int ValidateChecksums(unsigned int player, unsigned int worldtime, unsigned int worldturn, unsigned int worldrandom, int cs1, int cs2, int cs3, int cs4, int cs5);
    signed int DoChecksum(unsigned int turn);
    void SetLastWorldRandom(unsigned int lwr);
    void LogChecksums(unsigned int player, unsigned int worldtime, unsigned int worldturn, int cs1, int cs2, int cs3, int cs4, int cs5, unsigned int random);
    void EnableSyncChecking(int Status);
    void SetStopOnFail(int Status);
    void SetDialogOnFail(int Status);
    void SendChatMsgsAtChecksum(int Status);
    int IsPlayerOutOfSync(unsigned int pnum, unsigned int worldturn);
};
