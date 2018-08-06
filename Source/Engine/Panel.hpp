
/**
 * @file    Engine\Panel.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TPanel
{
public:

    TPanel *previousPanelValue,
           *previousModalPanelValue;

    int pnl_x,
        pnl_y,
        pnl_wid,
        pnl_hgt;

    char *panelNameValue;

    TDrawArea *render_area;

    RECT clip_rect;

    enum PositionMode
    {
        PositionFixed       = 0x00,
        PositionVariable    = 0x01,
        PositionCentered    = 0x02,
        PositionLeft        = 0x03,
        PositionTop         = 0x04,
        PositionRight       = 0x05,
        PositionBottom      = 0x06,
        PositionLeftTop     = 0x07,
        PositionLeftBottom  = 0x08,
        PositionRightTop    = 0x09,
        PositionRightBottom = 0x0A,
    }
    position_mode;

    enum RedrawMode
    {
        RedrawNone   = 0x00,
        RedrawNormal = 0x01,
        RedrawFull   = 0x02,
    }
    need_redraw;

    TPanel *curr_child,
           *parent_panel,
           *left_panel,
           *top_panel,
           *right_panel,
           *bottom_panel;

    struct PanelNode *node,
                     *first_child_node,
                     *last_child_node;

    TPanel *tab_prev_panel,
           *tab_next_panel;

    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void *clip_rgn;

    RECT render_rect;

    int left_border;
    int top_border;
    int right_border;
    int bottom_border;

    int min_wid,
        max_wid,
        min_hgt,
        max_hgt;

    int mouse_hold_interval,
        mouse_move_tolerance,
        mouse_down_x,
        mouse_down_y,
        mouse_down_ctrl,
        mouse_down_shift;

    time_t mouse_down_time;

    int error_code;

    enum ZOrder
    {
        ZOrderPosition = 0x00,
        ZOrderTop      = 0x01,
        ZOrderBottom   = 0x02,
    };
    int z_order;

    int display_changed_count;

    int help_string_id;
    int help_page_id;

    enum MouseAction
    {
        MouseActionNone = 0x00,
        MouseActionDown = 0x01,
        MouseActionHold = 0x02,
        MouseActionMove = 0x03,
    };
    char mouse_action;
    enum MouseButton
    {
        MouseButtonNone  = 0x00,
        LeftMouseButton  = 0x01,
        RightMouseButton = 0x02,
    };
    char mouse_down_button;
    char panel_type;
    char color;
    char fill_in_background;
    char clip_to_parent;
    char draw_rect2_flag;
    char need_restore;

    static int mouse_move_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_left_hold_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_left_move_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_right_down_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_right_hold_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_right_move_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_right_up_action(int x, int y, int ctrl_key, int shift_key);
    static int mouse_right_dbl_click_action(int x, int y, int ctrl_key, int shift_key);

    static int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);

    static int char_action(int key, short count);
};

struct PanelNode
{
    TPanel *panel;
    PanelNode *prev_node;
    PanelNode *next_node;
};

class TPanelSystem
{
public:

    TPanel *mouseOwnerValue;
    TPanel *keyboardOwnerValue;
    TPanel *modalPanelValue;
    TPanel *currentPanelValue;
    PanelNode *panelListValue;
    int numberActivePanelsValue;
    TPanel *prevCurrentChildValue;
    void *palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    int palette_id[10];
    unsigned int Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    unsigned int save_back_color;
    unsigned int save_text_color;

    TPanelSystem();

    ~TPanelSystem();

    TPanel *currentPanel(),
           *previousPanel(),
           *mouseOwner(),
           *keyboardOwner(),
           *modalPanel(),
           *panel( char *n );

    int numberActivePanels();
    PanelNode *addPanel(TPanel *p, int makeCurrent, int makeModal);
    char *removePanel(char *n);
    int setCurrentPanel(char *n, int makeModal);
    TPanel *restorePreviousPanel(int destroyOldCurrentPanel);
    void setMouseOwner(TPanel *p);
    void setKeyboardOwner(TPanel *p);
    void setModalPanel(TPanel *p);
    void setCurrentPanelModal();
    TPanel *restorePreviousModalPanel();
    char *destroyPanel(char *n);
    int inSystem(char *n);
    int inSystem(TPanel *p);
    PanelNode *setup();
    PanelNode *findPanelNode(char *n);
    void setCurrentPanel(TPanel *p, int makeModal);
    void *get_palette(char *file_name, int res_id);
    void release_palette(void *pal);
    void DisableIME();
    void EnableIME();
    int IsIMEEnabled();
    void TurnIMEOn();
    void TurnIMEOff();
    int IsIMEOn();
    int GetInputEnabled();
    void EnableInput();
    void DisableInput();
    void stop_sound_system();
    int restart_sound_system();
    void restore_system_colors();
    void set_restore();
};
