#pragma once

/**
 * @file    Engine\TRB\DialogMessage.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include "Panel_Dialog.hpp"

class TListDialog : public TDialogPanel
{
public:

    TTextPanel *title;
    TListPanel *list;
    TScrollBarPanel *scroll_bar;
    TButtonPanel *ok_btn;
    TButtonPanel *cancel_btn;
    short list_id;
    char *list_name;

    TListDialog(char *name);

    ~TListDialog();

    int setup(TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, int title_x_in, int title_y_in, int title_wid_in, int title_hgt_in, char *title_in, int list_x_in, int list_y_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, short list_id_in, int ok_btn_x_in, int cancel_btn_x_in, int btn_y_in, int btn_wid_in, int btn_hgt_in);
    int setup(TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, int title_x_in, int title_y_in, int title_wid_in, int title_hgt_in, int title_string_id, int list_x_in, int list_y_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, short list_id_in, int ok_btn_x_in, int cancel_btn_x_in, int btn_y_in, int btn_wid_in, int btn_hgt_in);
    int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);
    short get_list_id();
    char *get_list_name();
};
