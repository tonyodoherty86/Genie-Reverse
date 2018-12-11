#pragma once

/**
 * @file    Engine\Registry.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TRegistry
{
public:

    void *ghMachineKey,
         *ghUserKey,
         *ghMachineKeyRead;

    unsigned int gdwDisp;
    char Data[255];

    TRegistry(char *Key);

    ~TRegistry();

    int RegSet(int UseUserKey, char *lptszName, char *lpData, unsigned int dwSize);
    int RegSetInt(int UseUserKey, char *lptszName, int Value);
    int RegSetAscii(int UseUserKey, char *lptszName, char *lpData, unsigned int dwSize);
    char *RegGetAscii(int UseUserKey, char *lptszName);
    int RegGet(int UseUserKey, char *lptszName, char *lpData, unsigned int *lpdwDataSize);
    char *RegGetInt(int UseUserKey, char *lptszName);
};
