
/**
 * @file    Engine\MousePointer.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TMousePointer
{
public:

    int custom_draw;
    TDrawArea *render_area;
    TDrawArea *save_area;
    TDrawArea *primary_area;
    int Num_Cursors;
    int Max_Cursors;
    TDrawArea *cursors[16];
    TShape *Cursor_Shape;
    int Mouse_Mode;
    int Max_CX;
    int Max_CY;
    int cWidth;
    int cHeight;
    int gWidth;
    int gHeight;
    int mouse_x;
    int mouse_y;
    int save_x;
    int save_y;
    int facet;
    int game_facet;
    int next_facet;
    int last_facet;
    int d_top;
    int d_left;
    int d_bottom;
    int d_right;
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;
    int save_area_valid;

    RECT save_rect;
    RECT mouse_rect;
    RECT cursor_rect;
    RECT new_save_rect;
    RECT restore_rect;
    RECT game_window;

    IDirectDrawSurface *restoreSurface;
    IDirectDrawSurface *renderSurface;
    IDirectDrawSurface *PrimarySurface;

    int active;
    int drawn;
    int Shutdown;
    int Setup;
    int GameMode;
    int GameEnabled;
    int MouseOnScreen;
    unsigned int LastDrawTime;
    int LastddError;
    char cursor_file[260];
    int cursor_file_id;

    TMousePointer(int MouseModeIn);

    ~TMousePointer();

    int Shutdown_Mouse();
    int Restore_Mouse(TDrawArea *render_area_in);
    int setup(int custom_draw_in, TDrawArea *render_area_in, char *cursor_file_name, int cursor_resId, int maxCursors_in);
    void set_game_mode(int mode);
    void set_game_enable(int enable);
    int get_game_enable();
    int in_game_mode();
    void set_game_window(int Left, int Top, int Right, int Bottom);
    int LoadCursors(char *cursor_file_name, int resId, int Reload);
    void delete_surfaces();
    DrawAreaNode *create_surfaces();
    int update_mouse_position();

    void draw(int dMode);

    void erase();

    void set_facet(int facet_in);
    void set_game_facet(int facet_in);

    void off();
    void on();
    void reset();
    void center();
    void Poll();

    static int GetDDBltError(int theError);
};

struct MouseClickInfo
{
    int object_group;
    int self_action;
    int self_text_id;
    int gaia_action;
    int gaia_text_id;
    int ally_action;
    int ally_text_id;
    int neutral_action;
    int neutral_text_id;
    int enemy_action;
    int enemy_text_id;
};
