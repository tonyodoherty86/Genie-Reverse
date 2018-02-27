
/**
 * @file    Engine\CommServices.cpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TCommunications_Services
{
public:

    SPs Service[100];

    int ServiceCount;

    TCommunications_Services();

    ~TCommunications_Services();

    int GetServiceCount();
    int IncServiceCount();
    char *GetServiceName(int id);
    int SetServiceName(int id, char *Text);
    GUID *GetServiceGUID(GUID *result, int i);
    void EnumServiceGUID(int id, GUID *gid);
    int GetServiceActive(int id);
    void SetServiceActive(int id, int state);
};

int DPEnumCallback(GUID *pid, char *szName, unsigned int major_ver, unsigned int minor_ver, void *lpx);
