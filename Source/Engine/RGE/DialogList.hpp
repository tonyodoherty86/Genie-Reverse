
/**
 * @file    Engine\RGE\DialogList.hpp
 * @author  Yvan Burrie
 * @date    2018/08/07
 * @version 1.0
 */

class RGE_Dialog_List : public TListDialog
{
    int list_type;

    short list_size;
    short list_line;

    rdlg_list_info *list_info;

    char **list_text;


    RGE_Dialog_List( char *name );

    ~RGE_Dialog_List();

    int setup(
        TScreenPanel *parent_screen,
        char *info_file_in,
        int info_id_in,
        int list_type_in,
        char *title_in );

    short get_list_id();

    RGE_Player *create_list();
    RGE_Player *create_object_list();

    void sort_list();

    void calc_list_line();

    short get_cur_id();
};

int rdlg_list_compare(void *arg1, void *arg2);
