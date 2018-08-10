void __thiscall THelpDialog::THelpDialog(THelpDialog *this, TEasy_Panel *parentPanel, char *in_parent_panel, int help_string_id, int in_help_page_id, int x, int y); // idb
THelpDialog *__thiscall THelpDialog::`vector deleting destructor'(THelpDialog *this, unsigned int __flags);
void __thiscall THelpDialog::THelpDialog(THelpDialog *this, TEasy_Panel *parentPanel, char *in_parent_panel, char *in_help_string, int in_help_page_id, int x, int y); // idb
void __thiscall THelpDialog::~THelpDialog(THelpDialog *this); // idb
void __thiscall THelpDialog::setup_help(THelpDialog *this, TEasy_Panel *parentPanel, char *in_parent_panel, char *help_string, int in_help_page_id, int mouse_x, int mouse_y); // idb
int __thiscall THelpDialog::action(THelpDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2); // idb
int __thiscall THelpDialog::handle_mouse_down(THelpDialog *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
