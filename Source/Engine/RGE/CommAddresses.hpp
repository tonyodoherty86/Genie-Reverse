#pragma once

/**
 * @file    Engine\RGE\CommAddresses.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

#include "IDA.h"

class TCommunications_Handler;

class RGE_Communications_Addresses
{
public:

    TCommunications_Handler *comm;
    WSAData wsaData;
    char hostname[128];
    int Status;
    unsigned int AddressesAvailable;
    unsigned int AliasesAvailable;
    class IPAD *pIPAD;

    RGE_Communications_Addresses(TCommunications_Handler *CommIn);

    ~RGE_Communications_Addresses();

    char *GetHostName();
    void *SetIPAliases(char *sz);
    char *GetAddress(unsigned int Num);
    char *GetAlias(unsigned int Num);
    unsigned int *SetIPAddresses(char *sz);
    void EraseInformation();
};

class IPAD
{
public:

    char DottedIPAddress[32];
    char Alias[128];

    IPAD();
    ~IPAD();
};
