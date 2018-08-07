
/**
 * @file    Engine\TRB\PanelDropDown.cpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

TDropDownPanel::TDropDownPanel()
{
    TPanel::TPanel();

    this->panel_type = 6;
    this->draw_val_rect = 1;
}

TDropDownPanel::~TDropDownPanel()
{
    this->btn_panel  ->delete_panel();
    this->list_panel ->delete_panel();
    this->scbar_panel->delete_panel();
    this->val_panel  ->delete_panel();

    TPanel::~TPanel();
}

void TDropDownPanel::setup(
    TDrawArea *render_area_in,
    TPanel *parent_panel_in,
    void *font_in,
    int font_wid_in,
    int font_hgt_in,
    int fill_back_in,
    char back_color_in,
    int outline_in,
    int outline_color_in,
    int x_in,
    int y_in,
    int wid_in,
    int hgt_in,
    short val_len_in,
    short val_num_in,
    int btn_wid_in,
    int btn_hgt_in,
    char *btn_pic_in,
    int list_wid_in,
    int list_hgt_in,
    char **list_in,
    int list_num_lines_in,
    int scbar_wid_in,
    char *scbar_back_pic_in,
    char *scbar_up_pic_in,
    char *scbar_down_pic_in,
    char *scbar_tab_pic_in,
    int scbar_arrow_hgt_in,
    int scbar_tab_hgt_in )
{
    TDropDownPanel *v30; // esi@1
    TTextPanel *v31; // eax@1
    TTextPanel *v32; // eax@2
    TDropDownButtonPanel *v33; // eax@6
    TPanel *v34; // eax@7
    TListPanel *v35; // eax@11
    TTextPanel *v36; // eax@12
    TScrollBarPanel *v37; // eax@16
    TScrollBarPanel *v38; // eax@17

    v30 = this;
    this->val_num = val_num_in;
    this->btn_wid = btn_wid_in;
    this->btn_hgt = btn_hgt_in;
    this->list_wid = list_wid_in;
    this->list_hgt = list_hgt_in;
    this->scbar_wid = scbar_wid_in;
    this->scbar_arrow_hgt = scbar_arrow_hgt_in;
    this->scbar_tab_hgt = scbar_tab_hgt_in;
    this->val_wid = wid_in - btn_wid_in - 1;
    this->val_hgt = hgt_in;
    this->outline_color = (unsigned __int8)outline_color_in;
    this->font_hgt = font_hgt_in;
    TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
    v31 = (TTextPanel *)operator new(0x188u);
    if( v31 )
        TTextPanel::TTextPanel(v31);
    else
        v32 = 0;
    v30->val_panel = v32;
    if( v32
        && TTextPanel::setup(
                 v32,
                 render_area_in,
                 (TPanel *)&v30->vfptr,
                 0,
                 0,
                 v30->val_wid,
                 v30->val_hgt,
                 font_in,
                 font_wid_in,
                 font_hgt_in,
                 0,
                 fill_back_in,
                 back_color_in,
                 outline_in,
                 outline_color_in,
                 val_len_in,
                 list_in[v30->val_num]) )
    {
        TTextPanel::set_alignment(v30->val_panel, 0, AlignLeft);
        v33 = (TDropDownButtonPanel *)operator new(0x2BCu);
        if( v33 )
            TDropDownButtonPanel::TDropDownButtonPanel(v33, v30);
        else
            v34 = 0;
        v30->btn_panel = (TButtonPanel *)v34;
        if( v34
            && TButtonPanel::setup(
                     v34,
                     render_area_in,
                     (TPanel *)&v30->vfptr,
                     0,
                     0,
                     v30->btn_wid,
                     v30->btn_hgt,
                     (TPanel *)6,
                     0,
                     (TPanel *)1,
                     0) )
        {
            v35 = (TListPanel *)operator new(0x1A0u);
            if( v35 )
                TListPanel::TListPanel(v35);
            else
                v36 = 0;
            v30->list_panel = (TListPanel *)v36;
            if( v36 )
            {
                if( TTextPanel::setup(
                             v36,
                             render_area_in,
                             (TPanel *)&v30->vfptr,
                             0,
                             0,
                             v30->list_wid,
                             v30->list_hgt,
                             font_in,
                             font_wid_in,
                             font_hgt_in,
                             0,
                             fill_back_in,
                             back_color_in,
                             outline_in,
                             outline_color_in,
                             val_len_in,
                             list_in,
                             list_num_lines_in) )
                {
                    TListPanel::set_auto_track(v30->list_panel, 1);
                    (*(void (__stdcall **)(_DWORD))&v30->list_panel->vfptr->gap10[4])(0);
                    TTextPanel::setCurrentLineNumber((TTextPanel *)&v30->list_panel->vfptr, v30->val_num);
                    v37 = (TScrollBarPanel *)operator new(0x1C4u);
                    if( v37 )
                        TScrollBarPanel::TScrollBarPanel(v37);
                    else
                        v38 = 0;
                    v30->scbar_panel = v38;
                    if( v38 )
                    {
                        if( TScrollBarPanel::setup(
                                     v38,
                                     v30->render_area,
                                     (TPanel *)&v30->vfptr,
                                     0,
                                     0,
                                     v30->scbar_wid,
                                     v30->list_hgt,
                                     message_in,
                                     message_in,
                                     message_in,
                                     message_in,
                                     v30->scbar_arrow_hgt,
                                     v30->scbar_tab_hgt,
                                     (TPanel *)&v30->list_panel->vfptr,
                                     (signed short)list_num_lines_in,
                                     0) )
                        {
                            TTextPanel::set_scrollbar((TTextPanel *)&v30->list_panel->vfptr, v30->scbar_panel, 0);
                            (*(void (__stdcall **)(_DWORD))&v30->scbar_panel->vfptr->gap10[4])(0);
                            TDropDownPanel::set_mode(v30, font_hgt_in, outline_color_in, (int)render_area_in, ModeValue);
                        }
                    }
                }
            }
        }
    }
}

int TDropDownPanel::handle_mouse_down(
    int mouse_button_in,
    int x,
    int y,
    int ctrl_key,
    int shift_key )
{
    if( this->tab_stop ){

        if( this->parent_panel ){
            this->parent_panel->set_curr_child(this);
        }
    }

    if( v6->mode != 2
        || ((v8 = ((int (__stdcall *)(int, int))v6->list_panel->vfptr->is_inside)(x, y), v9 = v6->scbar_panel, v10 = v8, !v9) ? (v11 = 0) : (v11 = ((int (__stdcall *)(int, int))v9->vfptr->is_inside)(x, y)),
                v10 || v11) ){
        return TPanel::handle_mouse_down(mouse_button_in, x, y, ctrl_key, shift_key);

    }else{

        this->set_mode(ModeValue);
        this->set_line(this->val_num);

        return true;
    }
}

int TDropDownPanel::handle_mouse_move(
    int x,
    int y,
    int ctrl_key,
    int shift_key )
{
    return TPanel::handle_mouse_move(
        x,
        y,
        ctrl_key,
        shift_key);
}

int TDropDownPanel::handle_mouse_up(
    int mouse_button_in,
    int x,
    int y,
    int ctrl_key,
    int shift_key )
{
    return TPanel::handle_mouse_up(
        mouse_button_in,
        x,
        y,
        ctrl_key,
        shift_key);
}

int TDropDownPanel::handle_key_down(
    int key,
    int count,
    int alt_key,
    int ctrl_key,
    int shift_key )
{
    int result; // eax@5

    if( this->have_focus &&
        (
            key == 40 ||
            key == 38
        ) &&
        this->mode == TDropDownPanel::DropdownMode::ModeValue ){

        this->set_mode(ModeList);

        return true;
    }else{
        return TPanel::handle_key_down(
            key,
            count,
            alt_key,
            ctrl_key,
            shift_key);
    }
}

int TDropDownPanel::action(
    TPanel *from_panel,
    int action_in,
    unsigned int action_val1,
    unsigned int action_val2 )
{
    int v5; // ebp@1
    TDropDownPanel *v6; // esi@1
    TListPanel *v7; // ecx@5
    int *v8; // eax@8
    int v9; // ebp@8
    char *v10; // eax@8
    TPanel *v11; // ecx@8

    v5 = action_in;
    v6 = this;
    if( from_panel == (TPanel *)this->btn_panel )
    {
        if( action_in == 2 && this->mode == 1 )
            TDropDownPanel::set_mode(this, (int)from_panel, 2, action_val1, ModeList);
    }
    else
    {
        v7 = this->list_panel;
        if( (TListPanel *)from_panel == v7 && (action_in == 3 || action_in == 2) )
        {
            v8 = (int *)v6->val_panel;
            v6->val_num = action_val1;
            v9 = *v8;
            v10 = TTextPanel::get_text((TTextPanel *)&v7->vfptr, (signed short)action_val1);
            (*(void (__thiscall **)(TTextPanel *, char *))(v9 + 232))(v6->val_panel, v10);
            TDropDownPanel::set_mode(v6, (int)from_panel, v9, action_val1, ModeValue);
            v11 = v6->parent_panel;
            if( v11 )
                ((void (__stdcall *)(TDropDownPanel *, _DWORD, _DWORD, _DWORD))v11->vfptr->action)(v6, 0, 0, 0);
            v5 = action_in;
        }
    }
    return TPanel::action(from_panel, v5, action_val1, action_val2);
}

void TDropDownPanel::set_rect(
    int x_in,
    int y_in,
    int wid_in,
    int hgt_in )
{
    this->set_rect(
        x_in,
        y_in,
        wid_in,
        hgt_in);

    switch( this->mode ){

    case TDropDownPanel::DropdownMode::ModeValue:

        this->val_wid = this->pnl_wid - this->btn_wid - 1;
        this->val_hgt = this->pnl_hgt;
        this->set_mode(TDropDownPanel::DropdownMode::ModeNone);
        this->set_mode(ModeValue);

        break;

    case TDropDownPanel::DropdownMode::ModeList:

        this->list_wid = this->pnl_wid;
        this->list_hgt = this->pnl_hgt - this->val_hgt - 1;
        this->set_mode(ModeValue);
        this->set_mode(ModeList);

        break;
    }
}

void TDropDownPanel::set_val_text_color( unsigned int text_color1_in, unsigned int text_color2_in )
{
    if( this->val_panel ){
        this->val_panel->set_text_color(text_color1_in, text_color2_in);
    }
}

void TDropDownPanel::set_draw_style( TDropDownPanel::DrawStyle draw_style_in )
{
    this->draw_style = draw_style_in;

    if( this->val_panel ){
        TDropDownPanel::DropdownMode temp_mode = this->mode;
        this->mode = TDropDownPanel::DropdownMode::ModeNone;
        this->set_mode(temp_mode);
    }
}

void TDropDownPanel::set_draw_val_rect( int draw_val_rect_in )
{
    this->draw_val_rect = draw_val_rect_in;

    if( this->val_panel ){
        this->val_panel->set_outline(draw_val_rect_in, this->outline_color);
        this->set_redraw(RedrawNormal);
    }
}

void TDropDownPanel::set_bevel_info(
    int bevel_type_in,
    int c1,
    int c2,
    int c3,
    int c4,
    int c5,
    int c6 )
{
    int v8; // ebp@1
    TDropDownPanel *this; // esi@1
    TTextPanel *v10; // ecx@1
    signed int v11; // eax@3
    TListPanel *v12; // ecx@9
    signed int v13; // eax@11
    TScrollBarPanel *v14; // ecx@17
    int v15; // eax@19
    TButtonPanel *v16; // ecx@25
    int v17; // eax@27

    v8 = c1;
    this = this;
    v10 = this->val_panel;
    if( v10 )
    {
        switch ( bevel_type_in ){
            case 1:
                v11 = 1;
                break;
            case 2:
                v11 = 5;
                break;
            case 3:
                v11 = 6;
                break;
            case 4:
                v11 = 7;
                break;
            default:
                v11 = 0;
                break;
        }
        v8 = c1;
        ((void (__stdcall *)(signed int, int, int, int, int, int, int))v10->vfptr[1].set_rect)(v11, c1, c2, c3, c4, c5, c6);
    }
    v12 = this->list_panel;
    if( v12 )
    {
        switch ( bevel_type_in ){
            case 1:
                v13 = 1;
                break;
            case 2:
                v13 = 2;
                break;
            case 3:
                v13 = 3;
                break;
            case 4:
                v13 = 4;
                break;
            default:
                v13 = 0;
                break;
        }
        v8 = c1;
        ((void (__stdcall *)(signed int, int, int, int, int, int, int))v12->vfptr[1].set_rect)(v13, c1, c2, c3, c4, c5, c6);
    }
    v14 = this->scbar_panel;
    if( v14 )
    {
        switch ( bevel_type_in ){
            case 1:
                v15 = 1;
                break;
            case 2:
                v15 = 2;
                break;
            case 3:
                v15 = 3;
                break;
            case 4:
                v15 = 4;
                break;
            default:
                v15 = 0;
                break;
        }
        TScrollBarPanel::set_bevel_info(v14, v15, v8, c2, c3, c4, c5, c6);
    }
    v16 = this->btn_panel;
    if( v16 )
    {
        switch ( bevel_type_in ){
            case 1:
                v17 = 1;
                break;
            case 2:
                v17 = 2;
                break;
            case 3:
                v17 = 3;
                break;
            case 4:
                v17 = 4;
                break;
            default:
                v17 = 0;
                break;
        }
        TButtonPanel::set_bevel_info(v16, v17, v8, c2, c3, c4, c5, c6);
    }
}

void TDropDownPanel::set_buttons(
    TShape *button_shape_in,
    int btn_frame_in,
    int scbar_back_frame_in,
    int scbar_up_frame_in,
    int scbar_down_frame_in,
    int scbar_tab_frame_in )
{
    if( this->btn_panel ){
        if( button_shape_in ){
            this->btn_panel->set_picture(0, button_shape_in, btn_frame_in);
        }else{
            this->btn_panel->set_picture(0, 0, -1);
        }
    }

    if( this->scbar_panel ){
        this->scbar_panel->set_buttons(
            button_shape_in,
            scbar_back_frame_in,
            scbar_up_frame_in,
            scbar_down_frame_in,
            scbar_tab_frame_in);
    }
}

void TDropDownPanel::set_mode( TDropDownPanel::DropdownMode mode_in )
{
    TDropDownPanel *v5; // esi@1
    TPanel *v6; // ecx@2
    int v7; // eax@3
    int v8; // ebp@3
    int v9; // eax@3
    int v10; // ebx@3
    int v11; // edi@3
    int v12; // eax@3
    TDrawArea *v13; // eax@4
    TDropDownPanel::DropdownMode v14; // ecx@5
    TPanel *v15; // ecx@7
    TPanel *v16; // ecx@8
    int v17; // eax@15
    int v18; // edx@15
    void *v19; // ebx@15
    TPanelVtbl *v20; // edi@15
    char v21; // dl@17
    TPanelVtbl *v22; // edi@17
    int v23; // ecx@17
    int v24; // eax@17
    int v25; // ST1E4_4@18
    int v26; // ST1E0_4@18
    int v27; // ST1E4_4@19
    int v28; // ST1E0_4@19
    TPanel *v29; // ecx@20
    TPanel *v30; // ecx@26
    TTextPanel *v31; // ecx@29
    int v32; // edi@29
    int v33; // edi@30
    int v34; // ebx@31
    int v35; // edi@32
    int v36; // eax@32
    TScrollBarPanel *v37; // ecx@32
    int v38; // eax@36
    int v39; // edx@36
    void *v40; // ebx@36
    TPanelVtbl *v41; // edi@36
    int v42; // ebx@38
    int v43; // edi@38
    int v44; // ST1DC_4@38
    void (__thiscall *v45)(TPanel *, int, int, int, int); // eax@38
    int v46; // ST1D4_4@38
    int v47; // ST1D0_4@38
    int v48; // ebp@38
    int v49; // ebp@39
    int v50; // ebp@39
    int v51; // eax@39
    TPanelVtbl *v52; // edx@41
    int v53; // ST1DC_4@41
    int v54; // ST1D8_4@41
    TTextPanel *v55; // ecx@41
    int v56; // edi@41
    int v57; // edi@42
    int v58; // ebx@43
    int v59; // ebx@45
    int v60; // eax@48
    int v61; // edx@48
    TButtonPanel *v62; // ebp@48
    TPanelVtbl *v63; // ebx@48
    TTextPanel *v64; // ebp@49
    int v65; // eax@51
    TPanelVtbl *v66; // edx@51
    TTextPanel *v67; // ecx@51
    int v68; // edi@51
    int v69; // edi@52
    int v70; // ebp@53
    int v71; // edi@54
    int v72; // ebp@55
    TPanel *v73; // ecx@59
    int v74; // [sp+1DCh] [bp-20h]@2
    int v75; // [sp+1E0h] [bp-1Ch]@2
    int v76; // [sp+1E0h] [bp-1Ch]@38
    int v77; // [sp+1E4h] [bp-18h]@2
    void *v78; // [sp+1E4h] [bp-18h]@38
    int v79; // [sp+1E8h] [bp-14h]@0
    int parent_y; // [sp+1ECh] [bp-10h]@3
    int parent_x; // [sp+1F0h] [bp-Ch]@3
    TDropDownPanel::DropdownMode save_mode; // [sp+1F4h] [bp-8h]@5
    void (__thiscall *calc_wid)(TPanel *, int, int, int, int); // [sp+1F8h] [bp-4h]@38
    int retaddr; // [sp+1FCh] [bp+0h]@38

    v5 = this;
    if( mode_in != this->mode )
    {
        v6 = this->parent_panel;
        v77 = a4;
        v75 = a3;
        v74 = a2;
        if( v6 )
        {
            v7 = TPanel::xPosition(v6);
            v8 = v7;
            parent_x = v7;
            v9 = TPanel::yPosition(v5->parent_panel);
            v10 = v9;
            parent_y = v9;
            v11 = TPanel::width(v5->parent_panel);
            v12 = TPanel::height(v5->parent_panel);
        }
        else
        {
            v13 = v5->render_area;
            parent_x = 0;
            parent_y = 0;
            v8 = 0;
            v11 = v13->Width;
            v12 = v13->Height;
            v10 = 0;
        }
        v14 = v5->mode;
        v5->mode = 0;
        save_mode = v14;
        if( mode_in == 1 )
        {
            if( v14 == 2 )
            {
                v15 = v5->parent_panel;
                if( v15 )
                {
                    v16 = v15->parent_panel;
                    if( v16 )
                    {
                        if( v5->clip_rect.left < v8
                            || v5->clip_rect.top < v10
                            || v5->clip_rect.right > v11 + v8 - 1
                            || v5->clip_rect.bottom > v12 + v10 - 1 )
                        {
                            ((void (__stdcall *)(signed int))v16->vfptr->set_redraw)(2);
                        }
                    }
                }
            }
            (*(void (__stdcall **)(_DWORD, int, int, int))&v5->list_panel->vfptr->gap10[4])(0, v74, v75, v77);
            (*(void (__stdcall **)(_DWORD))&v5->scbar_panel->vfptr->gap10[4])(0);
            if( v5->draw_style == 1 )
            {
                (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))(*(_DWORD *)v5->btn_panel + 24))(
                    7,
                    0,
                    0,
                    1,
                    0,
                    v5->btn_wid,
                    v5->btn_wid,
                    v5->btn_hgt,
                    v5->btn_hgt,
                    0,
                    0,
                    0,
                    0,
                    v79,
                    parent_y,
                    parent_x);
                v17 = v5->val_hgt;
                v18 = v5->val_wid;
                v19 = v5->btn_panel;
                v20 = v5->val_panel->vfptr;
            }
            else
            {
                (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))&v5->val_panel->vfptr->gap10[8])(
                    7,
                    0,
                    0,
                    1,
                    0,
                    v5->val_wid,
                    v5->val_wid,
                    v5->val_hgt,
                    v5->val_hgt,
                    0,
                    0,
                    0,
                    0,
                    v79,
                    parent_y,
                    parent_x);
                v17 = v5->btn_hgt;
                v18 = v5->btn_wid;
                v19 = v5->val_panel;
                v20 = *(TPanelVtbl **)v5->btn_panel;
            }
            (*(void (__stdcall **)(signed int, signed int, _DWORD, _DWORD, _DWORD, int, int, int, int, void *, _DWORD, _DWORD))&v20->gap10[8])(
                7,
                1,
                0,
                0,
                0,
                v18,
                v18,
                v17,
                v17,
                v19,
                0,
                0);
            v21 = v5->list_is_above;
            v22 = v5->vfptr;
            v23 = v5->val_wid + v5->btn_wid + 1;
            v24 = v5->val_hgt;
            v5->clip_to_parent = 1;
            if( v21 )
            {
                v25 = v5->pnl_hgt + v5->pnl_y - v24 - 1;
                v26 = v5->pnl_x - v8;
                ((void (__thiscall *)(TDropDownPanel *))v22->set_fixed_position)(v5);
                v5->list_is_above = 0;
            }
            else
            {
                v27 = v5->pnl_y - 1;
                v28 = v5->pnl_x - v8;
                ((void (__thiscall *)(TDropDownPanel *))v22->set_fixed_position)(v5);
            }
            v29 = v5->parent_panel;
            if( v29 )
                ((void (__cdecl *)(signed int))v29->vfptr->set_redraw)(1);
            else
                ((void (__thiscall *)(TDropDownPanel *))v22->set_redraw)(v5);
            TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->val_panel->vfptr);
            if( save_mode == 2 )
            {
                if( !TPanelSystem::restorePreviousModalPanel(&panel_system) )
                    TPanelSystem::setModalPanel(&panel_system, 0);
                v30 = v5->parent_panel;
                if( v30 )
                {
                    ((void (__stdcall *)(TDropDownPanel *, signed int, _DWORD, _DWORD))v30->vfptr->action)(v5, 2, 0, 0);
                    v5->mode = 1;
                    return;
                }
            }
        }
        else if( mode_in == 2 )
        {
            (*(void (__stdcall **)(signed int, int, int, int))&v5->list_panel->vfptr->gap10[4])(1, v74, v75, v77);
            v31 = (TTextPanel *)&v5->list_panel->vfptr;
            v32 = v31->spacer_size;
            if( v32 )
            {
                v34 = v31->border_size;
                v5->list_hgt = (v5->font_hgt + 2 * v32 + 1) * TTextPanel::numberLines(v31) + 2 * v34;
            }
            else
            {
                v33 = v31->border_size;
                v5->list_hgt = (v5->font_hgt + 2) * TTextPanel::numberLines(v31) + 2 * v33;
            }
            ((void (__stdcall *)(_DWORD, _DWORD, int, int))v5->list_panel->vfptr->set_fixed_position)(
                0,
                0,
                v5->list_wid,
                v5->list_hgt);
            v35 = TTextPanel::numberLines((TTextPanel *)&v5->list_panel->vfptr);
            v36 = TTextPanel::numberDrawLines((TTextPanel *)&v5->list_panel->vfptr);
            v37 = v5->scbar_panel;
            if( v35 <= v36 )
                (*(void (__stdcall **)(_DWORD))&v37->vfptr->gap10[4])(0);
            else
                (*(void (__stdcall **)(signed int))&v37->vfptr->gap10[4])(1);
            if( v5->draw_style == 1 )
            {
                (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))(*(_DWORD *)v5->btn_panel + 24))(
                    7,
                    0,
                    0,
                    1,
                    0,
                    v5->btn_wid,
                    v5->btn_wid,
                    v5->btn_hgt,
                    v5->btn_hgt,
                    0,
                    0,
                    0,
                    0,
                    v79,
                    parent_y,
                    parent_x);
                v38 = v5->val_hgt;
                v39 = v5->val_wid;
                v40 = v5->btn_panel;
                v41 = v5->val_panel->vfptr;
            }
            else
            {
                (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))&v5->val_panel->vfptr->gap10[8])(
                    7,
                    0,
                    0,
                    1,
                    0,
                    v5->val_wid,
                    v5->val_wid,
                    v5->val_hgt,
                    v5->val_hgt,
                    0,
                    0,
                    0,
                    0,
                    v79,
                    parent_y,
                    parent_x);
                v38 = v5->btn_hgt;
                v39 = v5->btn_wid;
                v40 = v5->val_panel;
                v41 = *(TPanelVtbl **)v5->btn_panel;
            }
            v78 = v40;
            v76 = v38;
            (*(void (__stdcall **)(signed int, signed int, _DWORD, _DWORD, _DWORD, int, int, int))&v41->gap10[8])(
                7,
                1,
                0,
                0,
                0,
                v39,
                v39,
                v38);
            (*(void (__stdcall **)(signed int, signed int, signed int, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, TTextPanel *, _DWORD, _DWORD))&v5->scbar_panel->vfptr->gap10[8])(
                10,
                1,
                1,
                0,
                0,
                v5->scbar_wid,
                v5->scbar_wid,
                0,
                0,
                0,
                v5->val_panel,
                0,
                0);
            (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *, TScrollBarPanel *, _DWORD))&v5->list_panel->vfptr->gap10[8])(
                8,
                0,
                1,
                1,
                0,
                0,
                0,
                0,
                0,
                0,
                v5->val_panel,
                v5->scbar_panel,
                0);
            v42 = v5->list_wid;
            v43 = v5->list_hgt + v5->val_hgt + 1;
            v44 = v5->list_hgt + v5->val_hgt + 1;
            v45 = v5->vfptr->set_fixed_position;
            v46 = v5->pnl_y;
            v47 = v5->pnl_x - v8;
            v5->clip_to_parent = 0;
            retaddr = v42;
            calc_wid = v45;
            v45((TPanel *)&v5->vfptr, v47, v46, v42, v44);
            v48 = TPanel::yPosition((TPanel *)&v5->list_panel->vfptr);
            if( TPanel::height((TPanel *)&v5->list_panel->vfptr) + v48 > v5->render_area->Height - 4 )
            {
                v49 = TPanel::yPosition((TPanel *)&v5->list_panel->vfptr);
                v50 = 4 - v5->render_area->Height + TPanel::height((TPanel *)&v5->list_panel->vfptr) + v49;
                v51 = 4 - v5->pnl_y + TPanel::height((TPanel *)&v5->list_panel->vfptr);
                if( v51 >= v50 )
                {
                    v65 = v5->list_hgt - v50;
                    v66 = v5->list_panel->vfptr;
                    v5->list_hgt = v65;
                    ((void (__stdcall *)(_DWORD, _DWORD, int, int, int, void *))v66->set_fixed_position)(
                        0,
                        0,
                        v5->list_wid,
                        v65,
                        v76,
                        v78);
                    v67 = (TTextPanel *)&v5->list_panel->vfptr;
                    v68 = v67->spacer_size;
                    if( v68 )
                    {
                        v70 = v67->border_size;
                        v5->list_hgt = (v5->font_hgt + 2 * v68 + 1) * TTextPanel::numberDrawLines(v67) + 2 * v70;
                    }
                    else
                    {
                        v69 = v67->border_size;
                        v5->list_hgt = (v5->font_hgt + 2) * TTextPanel::numberDrawLines(v67) + 2 * v69;
                    }
                    v71 = v5->list_hgt + v5->val_hgt + 1;
                    if( !v5->scbar_panel->active )
                    {
                        ((void (__stdcall *)(_DWORD, _DWORD, int, int))v5->list_panel->vfptr->set_fixed_position)(
                            0,
                            0,
                            v5->list_wid,
                            v5->list_hgt);
                        v72 = TTextPanel::numberLines((TTextPanel *)&v5->list_panel->vfptr);
                        if( v72 > TTextPanel::numberDrawLines((TTextPanel *)&v5->list_panel->vfptr) )
                            (*(void (__stdcall **)(signed int))&v5->scbar_panel->vfptr->gap10[4])(1);
                        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *, TScrollBarPanel *, _DWORD))&v5->list_panel->vfptr->gap10[8])(
                            8,
                            0,
                            1,
                            1,
                            0,
                            0,
                            0,
                            0,
                            0,
                            0,
                            v5->val_panel,
                            v5->scbar_panel,
                            0);
                    }
                    ((void (__thiscall *)(TDropDownPanel *, int, int))v2)(v5, v5->pnl_x - retaddr, v5->pnl_y - (_DWORD)calc_wid);
                }
                else
                {
                    if( v51 > 0 )
                    {
                        v52 = v5->list_panel->vfptr;
                        v53 = v5->list_hgt - v51;
                        v54 = v5->list_wid;
                        v5->list_hgt = v53;
                        ((void (__stdcall *)(_DWORD, _DWORD, int, int))v52->set_fixed_position)(0, 0, v54, v53);
                        v55 = (TTextPanel *)&v5->list_panel->vfptr;
                        v56 = v55->spacer_size;
                        if( v56 )
                        {
                            v58 = v55->border_size;
                            v5->list_hgt = (v5->font_hgt + 2 * v56 + 1) * TTextPanel::numberDrawLines(v55) + 2 * v58;
                        }
                        else
                        {
                            v57 = v55->border_size;
                            v5->list_hgt = (v5->font_hgt + 2) * TTextPanel::numberDrawLines(v55) + 2 * v57;
                        }
                        v43 = v5->list_hgt + v5->val_hgt + 1;
                        if( !v5->scbar_panel->active )
                        {
                            ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v5->list_panel->vfptr->set_fixed_position)(
                                0,
                                0,
                                v5->list_wid,
                                v5->list_hgt);
                            v59 = TTextPanel::numberLines((TTextPanel *)&v5->list_panel->vfptr);
                            if( v59 > TTextPanel::numberDrawLines((TTextPanel *)&v5->list_panel->vfptr) )
                                (*(void (__stdcall **)(signed int))&v5->scbar_panel->vfptr->gap10[4])(1);
                        }
                    }
                    if( v5->draw_style == 1 )
                    {
                        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, void *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5->btn_panel + 24))(
                            8,
                            0,
                            0,
                            1,
                            0,
                            v5->btn_wid,
                            v5->btn_wid,
                            v5->btn_hgt,
                            v5->btn_hgt,
                            0,
                            0,
                            0,
                            0,
                            v76,
                            v78,
                            0,
                            0,
                            0);
                        v60 = v5->val_hgt;
                        v61 = v5->val_wid;
                        v62 = v5->btn_panel;
                        v63 = v5->val_panel->vfptr;
                    }
                    else
                    {
                        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, void *, _DWORD, _DWORD, _DWORD))&v5->val_panel->vfptr->gap10[8])(
                            8,
                            0,
                            0,
                            1,
                            0,
                            v5->val_wid,
                            v5->val_wid,
                            v5->val_hgt,
                            v5->val_hgt,
                            0,
                            0,
                            0,
                            0,
                            v76,
                            v78,
                            0,
                            0,
                            0);
                        v60 = v5->btn_hgt;
                        v61 = v5->btn_wid;
                        v64 = v5->val_panel;
                        v63 = *(TPanelVtbl **)v5->btn_panel;
                    }
                    (*(void (__stdcall **)(signed int, signed int, _DWORD, _DWORD, _DWORD, int, int, int))&v63->gap10[8])(
                        8,
                        1,
                        0,
                        0,
                        0,
                        v61,
                        v61,
                        v60);
                    (*(void (__stdcall **)(signed int, signed int, signed int, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *))&v5->scbar_panel->vfptr->gap10[8])(
                        9,
                        1,
                        1,
                        0,
                        0,
                        v5->scbar_wid,
                        v5->scbar_wid,
                        0,
                        0,
                        0,
                        0,
                        0,
                        v5->val_panel);
                    (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TScrollBarPanel *, TTextPanel *))&v5->list_panel->vfptr->gap10[8])(
                        7,
                        0,
                        1,
                        1,
                        0,
                        0,
                        0,
                        0,
                        0,
                        0,
                        0,
                        v5->scbar_panel,
                        v5->val_panel);
                    calc_wid((TPanel *)&v5->vfptr, v5->pnl_x - save_mode, v5->pnl_y + v5->val_hgt - v43, retaddr, v43);
                    v5->list_is_above = 1;
                }
            }
            ((void (__thiscall *)(TDropDownPanel *))v5->vfptr->set_redraw)(v5);
            TPanel::set_z_order((TPanel *)&v5->vfptr, 1, 0);
            TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->list_panel->vfptr);
            TPanelSystem::setModalPanel(&panel_system, (TPanel *)&v5->vfptr);
            v73 = v5->parent_panel;
            if( v73 )
                ((void (__stdcall *)(TDropDownPanel *, signed int, _DWORD, _DWORD))v73->vfptr->action)(v5, 1, 0, 0);
        }
        v5->mode = mode_in;
    }
}

int TDropDownPanel::numberLines()
{
    TListPanel *v1; // ecx@1
    int result; // eax@2

    v1 = this->list_panel;
    if( v1 )
        result = TTextPanel::numberLines((TTextPanel *)&v1->vfptr);
    else
        result = 0;
    return result;
}

int TDropDownPanel::currentLineNumber()
{
    TListPanel *v1; // ecx@1
    int result; // eax@2

    v1 = this->list_panel;
    if( v1 )
        result = TTextPanel::currentLineNumber((TTextPanel *)&v1->vfptr);
    else
        result = 0;
    return result;
}

void TDropDownPanel::setCurrentLineNumber( int line_num_in )
{
    this->set_line(line_num_in);
}

void TDropDownPanel::setCurrentLineId( int id_in )
{
    TDropDownPanel *v2; // esi@1
    TListPanel *v3; // ecx@1
    short v4; // ax@2
    TPanelVtbl **v5; // ecx@2
    TPanelVtbl *v6; // edi@3
    char *v7; // eax@3

    v3 = this->list_panel;
    if( this->list_panel ){
        TTextPanel::set_line_by_id((TTextPanel *)&this->list_panel->vfptr, id_in);
        v4 = TTextPanel::get_line((TTextPanel *)&this->list_panel->vfptr);
        v5 = &this->val_panel->vfptr;
        this->val_num = v4;
        if( v5 )
        {
            v6 = *v5;
            v7 = TTextPanel::get_text((TTextPanel *)&this->list_panel->vfptr, v4);
            (*(void (__thiscall **)(TTextPanel *, char *))&v6[1].gap4[4])(this->val_panel, v7);
        }
    }
}

char *TDropDownPanel::currentLine()
{
    if( this->list_panel ){
        return this->currentLine();
    }else{
        return 0;
    }
}

void TDropDownPanel::set_tab_order( TPanel *prev_panel, TPanel *next_panel )
{
    this->set_tab_order(prev_panel, next_panel);

    if( this->val_panel ){
        (*((void (__stdcall **)(_DWORD, _DWORD))&this->val_panel->vfptr->set_focus + 1))(0, 0);
    }
}

void TDropDownPanel::set_sorted( int sorted_in )
{
    if( this->list_panel ){
        this->list_panel->sorted = sorted_in;
    }
}

int TDropDownPanel::get_sorted()
{
    if( this->list_panel ){
        return this->list_panel->sorted;
    }else{
        return 0;
    }
}

void TDropDownPanel::set_line( int line_in )
{
    this->val_num = line_in;

    if( this->list_panel ){
        this->list_panel->set_line(line_in);
        TPanelVtbl **v4 = &this->val_panel->vfptr;
        if( v4 ){
            TPanelVtbl *v5 = *v4;
            (*(void (__thiscall **)(TTextPanel *, char *))&v5[1].gap4[4])(this->val_panel, this->list_panel::get_text(line_in));
        }
    }
}

void *TDropDownPanel::append_line( char *text_in, int id_in )
{
    if( this->list_panel ){
        return this->list_panel->append_line(text_in, id_in);
    }else{
        return 0;
    }
}

void *TDropDownPanel::append_line( int string_id_in, int id_in )
{
    if( this->list_panel ){
        return this->list_panel->append_line(string_id_in, id_in);
    }else{
        return 0;
    }
}

void *TDropDownPanel::insert_line( int line_in, char *text_in, int id_in )
{
    if( this->list_panel ){
        return this->list_panel->insert_line(line_in, text_in, id_in);
    }else{
        return 0;
    }
}

void *TDropDownPanel::insert_line( int line_in, int string_id_in, int id_in )
{
    if( this->list_panel ){
        return this->list_panel->insert_line(line_in, string_id_in, id_in);
    }else{
        return 0;
    }
}

int TDropDownPanel::delete_line( int line_in )
{
    if( this->list_panel ){
        return this->list_panel->delete_line(line_in);
    }else{
        return 0;
    }
}

int TDropDownPanel::get_line()
{
    if( this->list_panel ){
        return this->list_panel->get_line();
    }else{
        return 0;
    }
}

int TDropDownPanel::get_line( int id_in )
{
    if( this->list_panel ){
        return this->list_panel->get_line(id_in);
    }else{
        return 0;
    }
}

int TDropDownPanel::get_line( char *text_in )
{
    if( this->list_panel ){
        return this->get_line(text_in);
    }else{
        return 0;
    }
}

char *TDropDownPanel::TDropDownPanel::get_text()
{
    if( this->list_panel ){
        return this->get_text();
    }else{
        return 0;
    }
}

char *TDropDownPanel::get_text( int line_in )
{
    if( this->list_panel ){
        result = this->get_text(line_in);
    }else{
        return 0;
    }
}

int TDropDownPanel::get_id()
{
    if( this->list_panel ){
        return this->get_id();
    }else{
        return 0;
    }
}

int TDropDownPanel::get_id( int line_in )
{
    if( this->list_panel ){
        return this->get_id(line_in);
    }else{
        return 0;
    }
}

void TDropDownPanel::empty_list()
{
    if( this->list_panel ){
        this->empty_list();
    }
}
