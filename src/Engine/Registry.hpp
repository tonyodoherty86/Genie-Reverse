
/**
 * @file    Engine\Registry.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TRegistry
{
public:

    void *ghMachineKey;
    void *ghUserKey;
    void *ghMachineKeyRead;
    unsigned int gdwDisp;
    char Data[255];
};
