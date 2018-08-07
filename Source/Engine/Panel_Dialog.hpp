
/**
 * @file    Engine\TRB\DialogPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TDialogPanel : public TEasy_Panel
{
public:

    void *dlg_wnd;
    TPanel *save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    TDialogPanel(char *panel_name_in);

    ~TDialogPanel();

    int setup(TDrawArea *render_area_in, TPanel *parent_in, int wid_in, int hgt_in, char *info_file_name, int resource_file_id, int allow_shadow_area_in);
    int setup(TDrawArea *render_area_in, TPanel *parent_in, int wid_in, int hgt_in, int color_in, int allow_shadow_area_in);

    void set_focus(int have_focus_in);
};
