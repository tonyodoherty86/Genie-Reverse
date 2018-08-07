
/**
 * @file    Engine\TRB\DialogMessage.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TMessageDialog : public TDialogPanel
{
public:

    enum Type
    {
        OKDialog          = 0x00,
        OKCancelDialog    = 0x01,
        YesNoDialog       = 0x02,
        RetryAbortDialog  = 0x03,
        YesNoCancelDialog = 0x04,
    };
    char dlg_type;

    TTextPanel *text;

    TButtonPanel *button[3];

    TMessageDialog(char *name);

    ~TMessageDialog();

    int setup(
        TPanel *parent_panel_in,
        char *info_file_in,
        int info_id_in,
        int wid_in,
        int hgt_in,
        char dlg_type_in,
        char *text_in,
        int btn_wid_in,
        int btn_hgt_in);

    int setup(
        TPanel *parent_panel_in,
        char *info_file_in,
        int info_id_in,
        int wid_in,
        int hgt_in,
        char dlg_type_in,
        int text_id,
        int btn_wid_in,
        int btn_hgt_in);

    enum Action
    {
        OK     = 0x00,
        Cancel = 0x01,
        Other  = 0x02,
    };
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);

    int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);

    int handle_idle();
};
