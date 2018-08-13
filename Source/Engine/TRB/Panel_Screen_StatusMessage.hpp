
/**
 * @file    Engine\TRB\Panel_Screen_StatusMessage.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TRIBE_Screen_Status_Message : public TScreenPanel
{
public:

    TTextPanel *message;

    TRIBE_Screen_Status_Message(char *name, char *message_in, char *info_file_in, int info_id_in);
    TRIBE_Screen_Status_Message(char *name, int message_in, char *info_file_in, int info_id_in);

    ~TRIBE_Screen_Status_Message();

    void set_text(char *message_in);
    void set_text(int message_in);
};
