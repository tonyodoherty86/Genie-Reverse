#pragma once

#include "Panel_ListDialog.hpp"

void __thiscall TListDialog::TListDialog(TListDialog *this, char *name); // idb
TListDialog *__thiscall TListDialog::`scalar deleting destructor'(TListDialog *this, unsigned int __flags);
void __thiscall TListDialog::~TListDialog(TListDialog *this); // idb
int __thiscall TListDialog::setup(TListDialog *this, TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, int title_x_in, int title_y_in, int title_wid_in, int title_hgt_in, char *title_in, int list_x_in, int list_y_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, __int16 list_id_in, int ok_btn_x_in, int cancel_btn_x_in, int btn_y_in, int btn_wid_in, int btn_hgt_in);
int __thiscall TListDialog::setup(TListDialog *this, TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, int title_x_in, int title_y_in, int title_wid_in, int title_hgt_in, int title_string_id, int list_x_in, int list_y_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, __int16 list_id_in, int ok_btn_x_in, int cancel_btn_x_in, int btn_y_in, int btn_wid_in, int btn_hgt_in);
int __stdcall TListDialog::key_down_action(int key, __int16 count, int alt_key, int ctrl_key, int shift_key);
int __thiscall TListDialog::action(TListDialog *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2); // idb
__int16 __thiscall TListDialog::get_list_id(TListDialog *this); // idb
char *__thiscall TListDialog::get_list_name(TListDialog *this); // idb
