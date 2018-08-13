
/**
 * @file    Engine\RGE\View.cpp
 * @author  Yvan Burrie
 * @date    2018/07/29
 * @version 1.0
 */

RGE_View::RGE_View()
{
    TPanel::TPanel();

    this->set_selection_area(-1, -1, -1, -1);

    this->DispSel_List = new DisplaySelectedObjRec;
}

RGE_View::~RGE_View()
{
    RGE_View *v1; // esi@1
    TShape *v2; // edi@1
    TSpan_List_Manager *v3; // edi@7
    TSpan_List_Manager *v4; // edi@9
    TSpan_List_Manager *v5; // edi@11
    DClipInfo_List *v6; // edi@21
    DClipInfo_List *v7; // edi@23
    void **v8; // edi@25
    signed int v9; // ebx@25

    if( this->border_line_shape ){
        delete this->border_line_shape;
        this->border_line_shape = nullptr;
    }

    this->delete_surfaces();

    if( this->red_pen ){
        DeleteObject(this->red_pen);
        this->red_pen = nullptr;
    }

    if( this->RenderOffsets ){
        free(this->RenderOffsets);
    }

    if( this->Terrain_Clip_Mask ){
        delete this->Terrain_Clip_Mask;
    }

    if( this->Terrain_Fog_Clip_Mask ){
        delete this->Terrain_Fog_Clip_Mask;
    }

    if( this->Master_Clip_Mask ){
        delete this->Master_Clip_Mask;
    }
    if( this->Tile_Edge_Tables )
        free(this->Tile_Edge_Tables);
    if( this->Black_Edge_Tables )
        free(this->Black_Edge_Tables);
    if( this->Float_Scroll_Offsets )
        free(this->Float_Scroll_Offsets);
    if( this->Blit_Queue )
        free(this->Blit_Queue);
    v6 = this->prior_objs;
    if( v6 )
    {
        DClipInfo_List::~DClipInfo_List(this->prior_objs);
        operator delete(v6);
    }
    v7 = this->futur_objs;
    if( v7 )
    {
        DClipInfo_List::~DClipInfo_List(this->futur_objs);
        operator delete(v7);
    }
    v8 = (void **)this->pick_lists;
    v9 = 5;
    do
    {
        if( *v8 )
            free(*v8);
        ++v8;
        --v9;
    }
    while( v9 );

    if( MouseSystem ){
        MouseSystem->set_game_mode(0);
        MouseSystem->set_game_enable(0);
    }

    if( this->DispSel_List ){
        free(this->DispSel_List);
    }

    this->reset_overlay_sprites();

    TPanel::~TPanel(();
    TPanel::~TPanel(();
}

int RGE_View::setup(
    TDrawArea *render_area_in,
    TPanel *parent_panel_in,
    int x_in,
    int y_in,
    int wid_in,
    int hgt_in,
    int color_in,
    int calc_draw_count_in,
    char *border_line_file )
{
    RGE_View *v10; // esi@1
    TShape *v11; // eax@1
    TShape *v12; // eax@2
    int *v13; // esi@4
    signed int v14; // edi@4
    char str[260]; // [sp+10h] [bp-110h]@1
    int v17; // [sp+11Ch] [bp-4h]@1

    v10 = this;
    TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, color_in);
    v10->cur_render_area = 0;
    v10->calc_draw_count = calc_draw_count_in;
    v10->start_scr_col = 0;
    v10->start_scr_row = 0;
    v10->start_map_col = 0;
    v10->start_map_row = 0;
    LODWORD(v10->last_view_x) = -971228160;
    LODWORD(v10->last_view_y) = -971228160;
    v10->function_mode = 0;
    v10->white_pen = GetStockObject(6);
    v10->red_pen = CreatePen(0, 1, 0xFFu);
    v10->hollow_brush = GetStockObject(5);
    sprintf(str, aS_shp, border_line_file);
    v11 = (TShape *)operator new(0x20u);
    v17 = 0;
    if( v11 )
        TShape::TShape(v11, str, -1);
    else
        v12 = 0;
    v17 = -1;
    v10->border_line_shape = v12;
    RGE_View::Init_Tile_Edge_Tables(v10);
    v13 = v10->pick_list_size;
    v14 = 5;
    do
    {
        *(v13 - 5) = (int)calloc(0x40u, 0x14u);
        *v13 = 0;
        ++v13;
        --v14;
    }
    while( v14 );
    return 1;
}

//----- (00533AC0) --------------------------------------------------------
void RGE_View::set_focus(int have_focus_in)
{
    RGE_View *v2; // esi@1

    v2 = this;
    TPanel::set_focus((TPanel *)&this->vfptr, have_focus_in);
    if( MouseSystem )
        TMousePointer::set_game_enable(MouseSystem, v2->have_focus);
}

//----- (00533AF0) --------------------------------------------------------
void RGE_View::Init_Tile_Edge_Tables()
{
    RGE_View *v1; // ebp@1
    int v2; // eax@1
    int v3; // esi@1
    __int32 v4; // edi@2
    Tile_FogEdge_Table **v5; // edx@2
    signed int v6; // eax@2
    Tile_FogEdge_Table **v7; // ecx@3
    signed int v8; // edi@4
    signed int v9; // esi@5
    Tile_FogEdge_Table *v10; // eax@5
    VSpanMiniList *v11; // ecx@8
    int v12; // eax@12
    int v13; // esi@12
    __int32 v14; // edi@13
    Tile_BlackEdge_Table **v15; // esi@13
    signed int v16; // eax@13
    Tile_BlackEdge_Table **v17; // ecx@14
    signed int v18; // edi@15
    VSpanMiniList **v19; // eax@16
    signed int v20; // edx@16
    char *v21; // ebp@21
    signed int v22; // eax@21
    signed int v23; // edi@22
    signed int v24; // eax@41
    int v25; // esi@43
    int v26; // edx@43
    int v27; // edi@43
    int v28; // ebx@43
    int y; // [sp+18h] [bp-10h]@21
    char *v30; // [sp+24h] [bp-4h]@21

    v1 = this;
    v2 = _open(aData2Tileedge_, 0x8000);
    v3 = v2;
    if( v2 != -1 )
    {
        lseek(v2, 0, 2);
        v4 = _tell(v3);
        v1->Tile_Edge_Tables = (Tile_FogEdge_Table **)calloc(1u, v4);
        lseek(v3, 0, 0);
        read(v3, v1->Tile_Edge_Tables, v4);
        _close(v3);
        v5 = v1->Tile_Edge_Tables;
        v6 = 0;
        do
        {
            v7 = &v1->Tile_Edge_Tables[v6];
            ++v6;
            *v7 = (Tile_FogEdge_Table *)((char *)*v7 + (_DWORD)v5);
        }
        while( v6 < 17 );
        v8 = 0;
        do
        {
            v9 = 47;
            v10 = v1->Tile_Edge_Tables[v8];
            do
            {
                if( v10->normal_draw )
                    v10->normal_draw = (VSpanMiniList *)((char *)v10->normal_draw + (unsigned int)v5);
                v11 = v10->fog_draw;
                if( v11 )
                    v10->fog_draw = (VSpanMiniList *)((char *)v11 + (_DWORD)v5);
                ++v10;
                --v9;
            }
            while( v9 );
            ++v8;
        }
        while( v8 < 17 );
    }
    v12 = _open(aData2Blkedge_d, 0x8000);
    v13 = v12;
    if( v12 != -1 )
    {
        lseek(v12, 0, 2);
        v14 = _tell(v13);
        v1->Black_Edge_Tables = (Tile_BlackEdge_Table **)calloc(1u, v14);
        lseek(v13, 0, 0);
        read(v13, v1->Black_Edge_Tables, v14);
        _close(v13);
        v15 = v1->Black_Edge_Tables;
        v16 = 0;
        do
        {
            v17 = &v1->Black_Edge_Tables[v16];
            ++v16;
            *v17 = (Tile_BlackEdge_Table *)((char *)*v17 + (_DWORD)v15);
        }
        while( v16 < 17 );
        v18 = 0;
        do
        {
            v19 = &v1->Black_Edge_Tables[v18]->black_UNdraw;
            v20 = 47;
            do
            {
                if( *v19 )
                    *v19 = (VSpanMiniList *)((char *)*v19 + (_DWORD)v15);
                ++v19;
                --v20;
            }
            while( v20 );
            ++v18;
        }
        while( v18 < 17 );
    }
    v21 = v1->EdgeNumber;
    memset(v21, 0xFFu, 0x100u);
    v22 = 0;
    v30 = v21;
    y = 0;
    do
    {
        v23 = 1;
        if( (v22 & 0x80) == -128 && ((v22 & 1) == 1 || (v22 & 8) == 8) )
            v23 = 0;
        if( (v22 & 0x40) == 64 && ((v22 & 4) == 4 || (v22 & 8) == 8) )
            v23 = 0;
        if( (v22 & 0x20) == 32 && ((v22 & 2) == 2 || (v22 & 4) == 4) )
            v23 = 0;
        if( (v22 & 0x10) == 16 && ((v22 & 1) == 1 || (v22 & 2) == 2) )
            v23 = 0;
        if( v23 )
            v21[v22] = y++;
        ++v22;
    }
    while( v22 < 256 );
    v24 = 0;
    do
    {
        if( v21[v24] == -1 )
        {
            v25 = v24 & 1;
            v26 = v24 & 2;
            v27 = v24 & 4;
            v28 = v24 & 8;
            if( v24 & 0x80 )
            {
                v28 = 0;
                v25 = 0;
            }
            if( v24 & 0x40 )
            {
                v28 = 0;
                v27 = 0;
            }
            if( v24 & 0x20 )
            {
                v27 = 0;
                v26 = 0;
            }
            if( v24 & 0x10 )
            {
                v26 = 0;
                v25 = 0;
            }
            v21 = v30;
            v30[v24] = v30[v25 | v26 | v27 | v28 | v24 & 0x10 | v24 & 0x20 | v24 & 0x40 | v24 & 0x80];
        }
        ++v24;
    }
    while( v24 < 256 );
}

//----- (00533E10) --------------------------------------------------------
void RGE_View::update_display_selected_objects()
{
    RGE_View *v1; // esi@1
    unsigned int v2; // eax@1
    int v3; // ebp@1
    int v4; // ebx@2
    int v5; // ecx@3
    RGE_Static_Object *v6; // edx@4
    unsigned int v7; // edi@6

    v1 = this;
    v2 = debug_timeGetTime();
    v3 = 0;
    if( v1->DispSel_List_Max > 0 )
    {
        v4 = 0;
        do
        {
            v5 = (int)&v1->DispSel_List[v4].active;
            if( *(_DWORD *)v5 )
            {
                v6 = v1->world->objectsValue[*(_DWORD *)(v5 + 4)];
                if( v6 )
                {
                    v7 = v2 - *(_DWORD *)(v5 + 8);
                    if( v7 <= *(_DWORD *)(v5 + 12) )
                    {
                        if( !(v7 & 0x100) )
                        {
                            v6->selected |= *(_BYTE *)(v5 + 16);
                            goto LABEL_9;
                        }
                    }
                    else
                    {
                        *(_DWORD *)v5 = 0;
                        --v1->DispSel_List_Size;
                    }
                    v6->selected &= ~*(_BYTE *)(v5 + 16);
                }
                else
                {
                    *(_DWORD *)v5 = 0;
                    --v1->DispSel_List_Size;
                }
            }
LABEL_9:
            ++v3;
            ++v4;
        }
        while( v3 < v1->DispSel_List_Max );
    }
}

void RGE_View::display_object_selection(
    int id,
    int duration,
    int select_type,
    int reset_type)
{
    RGE_View *v5; // esi@1
    signed int v6; // ebx@1
    int v7; // edx@1
    int v8; // ebp@2
    int v9; // edi@2
    int v10; // ecx@2
    int v11; // eax@3

    v5 = this;
    v6 = 0;
    v7 = 0;
    if( this->DispSel_List_Max <= 0 )
    {
        v9 = reset_type;
    }
    else
    {
        v8 = reset_type;
        v9 = reset_type;
        v10 = 0;
        do
        {
            v11 = (int)&v5->DispSel_List[v10].active;
            if( *(_DWORD *)v11 )
            {
                if( v8 && *(_DWORD *)(v11 + 16) == v8 )
                {
                    *(_DWORD *)(v11 + 8) -= *(_DWORD *)(v11 + 12);
                    v8 = reset_type;
                }
            }
            else
            {
                v6 = 1;
                v9 = (int)&v5->DispSel_List[v10].active;
            }
            ++v7;
            ++v10;
        }
        while( v7 < v5->DispSel_List_Max );
    }
    if( v6 )
    {
        *(_DWORD *)v9 = 1;
        *(_DWORD *)(v9 + 4) = id;
        *(_DWORD *)(v9 + 8) = debug_timeGetTime();
        *(_DWORD *)(v9 + 12) = duration;
        *(_DWORD *)(v9 + 16) = select_type;
        ++v5->DispSel_List_Size;
    }
}

void RGE_View::set_rect(
    int x_in,
    int y_in,
    int wid_in,
    int hgt_in)
{
    TPanel::set_rect(x_in, y_in, wid_in, hgt_in);

    this->calc_draw_vars();
    this->create_surfaces();

    this->last_view_x = RGE_VIEW_LAST_VIEW_VALUE;
    this->last_view_y = RGE_VIEW_LAST_VIEW_VALUE;

    if( this->Terrain_Clip_Mask ){
        delete this->Terrain_Clip_Mask;
    }
    if( this->Terrain_Fog_Clip_Mask ){
        delete this->Terrain_Fog_Clip_Mask;
    }
    if( this->Master_Clip_Mask ){
        delete this->Master_Clip_Mask;
    }
    this->Terrain_Clip_Mask     = new TSpan_List_Manager(wid_in, hgt_in);
    this->Terrain_Fog_Clip_Mask = new TSpan_List_Manager(wid_in, hgt_in);
    this->Master_Clip_Mask      = new TSpan_List_Manager(wid_in, hgt_in);

    if( MouseSystem &&
        wid_in > 0 &&
        hgt_in > 0 ){

        MouseSystem->set_game_window(
            x_in,
            y_in,
            x_in + wid_in,
            y_in + hgt_in);

        MouseSystem->set_game_mode(1);
    }

    this->set_redraw(RedrawFull);
}

void RGE_View::delete_surfaces()
{
    if( this->save_area1 ){
        delete this->save_area1;
        this->save_area1 = nullptr;
    }
}

int RGE_View::create_surfaces()
{
    RGE_View *v1; // esi@1
    int result; // eax@3
    TDrawArea *v3; // eax@5
    TDrawArea *v4; // eax@6
    TDrawArea *v5; // ecx@10
    int v6; // eax@11
    TDrawArea *v7; // ecx@12
    DClipInfo_List *v8; // edi@12
    DClipInfo_List *v9; // edi@14
    int v10; // edi@16
    DClipInfo_List *v11; // eax@16
    DClipInfo_List *v12; // eax@17
    DClipInfo_List *v13; // eax@19
    DClipInfo_List *v14; // eax@20
    int v15; // ecx@22

    v1 = this;
    if( this->pnl_wid || this->pnl_hgt )
    {
        if( !this->save_area1 )
        {
            v3 = (TDrawArea *)operator new(0x100u);
            if( v3 )
                TDrawArea::TDrawArea(v3, aTerrainBuffer, 0);
            else
                v4 = 0;
            v1->save_area1 = v4;
            if( v4 )
                TDrawArea::Init(v4, v1->render_area->DrawSystem, v1->pnl_wid, v1->pnl_hgt, 1, 0);
        }
        v5 = v1->save_area1;
        if( v5 )
        {
            v6 = v1->pnl_hgt;
            if( v6 > 0 )
            {
                TDrawArea::SetSize(v5, v1->pnl_wid, v6, 1);
                v7 = v1->save_area1;
                v1->Float_X_Delta = 0;
                v1->Float_Y_Delta = 0;
                TDrawArea::SetFloatOffsets(v7, 0, 0);
                v8 = v1->prior_objs;
                if( v8 )
                {
                    DClipInfo_List::~DClipInfo_List(v1->prior_objs);
                    operator delete(v8);
                }
                v9 = v1->futur_objs;
                if( v9 )
                {
                    DClipInfo_List::~DClipInfo_List(v1->futur_objs);
                    operator delete(v9);
                }
                v10 = v1->pnl_hgt + 450;
                v11 = (DClipInfo_List *)operator new(0x70u);
                if( v11 )
                    DClipInfo_List::DClipInfo_List(v11, 2 * v10, v10, 64, -200, v1->pnl_hgt + 249, 40);
                else
                    v12 = 0;
                v1->prior_objs = v12;
                v13 = (DClipInfo_List *)operator new(0x70u);
                if( v13 )
                    DClipInfo_List::DClipInfo_List(v13, 2 * v10, v10, 64, -200, v1->pnl_hgt + 249, 40);
                else
                    v14 = 0;
                v15 = v1->pnl_wid;
                v1->futur_objs = v14;
                DClipInfo_List::SetDrawRegion(v1->prior_objs, 0, 0, v15 - 1, v1->pnl_hgt - 1);
                DClipInfo_List::SetDrawRegion(v1->futur_objs, 0, 0, v1->pnl_wid - 1, v1->pnl_hgt - 1);
            }
        }
        result = v1->save_area1 != 0;
    }
    else
    {
        result = 1;
    }
    return result;
}

//----- (00534340) --------------------------------------------------------
void RGE_View::calc_draw_vars()
{
    short v1; // ax@2
    short v2; // bx@3
    int v3; // esi@4
    int v4; // edi@4
    short v5; // ax@4
    short v6; // bx@4
    signed int v7; // kr00_4@4

    if( this->visible && (v1 = this->tile_wid) != 0 && (v2 = this->tile_hgt) != 0 )
    {
        v3 = this->pnl_wid;
        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
        v4 = this->pnl_hgt;
        this->max_col_num = v3 / v1;
        v5 = v4 / v2;
        v6 = LOWORD(this->render_rect.left) - this->tile_half_wid;
        this->max_row_num = v5;
        v7 = v3;
        LOWORD(v3) = LOWORD(this->render_rect.top) - this->tile_half_hgt;
        this->center_scr_col = v7 / 2 + v6;
        this->center_scr_row = v4 / 2 + v3;
    }
    else
    {
        this->max_row_num = 0;
        this->max_col_num = 0;
        this->center_scr_col = 0;
        this->center_scr_row = 0;
        this->center_map_col = 0;
        this->center_map_row = 0;
        this->center_scr_col_offset = 0;
        this->center_scr_row_offset = 0;
    }
}

//----- (00534420) --------------------------------------------------------
void RGE_View::set_redraw(TPanel::RedrawMode redraw_mode)
{
    RGE_View *v2; // esi@1

    v2 = this;
    TPanel::set_redraw((TPanel *)&this->vfptr, redraw_mode);
    if( redraw_mode == 2 )
        v2->render_terrain_mode = 0;
}

//----- (00534440) --------------------------------------------------------
void RGE_View::set_world(RGE_Game_World *world_in)
{
    RGE_View *v2; // esi@1
    RGE_Map *v3; // ecx@2
    RGE_Map *v4; // eax@2

    v2 = this;
    this->world = world_in;
    if( world_in )
    {
        v3 = world_in->map;
        v2->map = v3;
        RGE_Map::coordinate_map(v3);
        v4 = v2->map;
        v2->tile_wid = v4->tile_width;
        v2->tile_hgt = v4->tile_height;
        v2->tile_half_wid = v4->tile_half_width;
        v2->tile_half_hgt = v4->tile_half_height;
        v2->elev_hgt = v4->elev_height;
        RGE_View::calc_draw_vars(v2);
    }
    else
    {
        this->map = 0;
        this->tile_wid = 0;
        this->tile_hgt = 0;
        this->tile_half_wid = 0;
        this->tile_half_hgt = 0;
        this->elev_hgt = 0;
        RGE_View::calc_draw_vars(this);
    }
}

//----- (00534500) --------------------------------------------------------
void RGE_View::set_player(RGE_Player *player_in)
{
    TPanelVtbl *v2; // edx@1

    v2 = this->vfptr;
    this->player = player_in;
    LODWORD(this->last_view_x) = -971228160;
    LODWORD(this->last_view_y) = -971228160;
    ((void (__stdcall *)(signed int))v2->set_redraw)(2);
}

//----- (00534530) --------------------------------------------------------
void RGE_View::set_selection_area(int sel_col1_in, int sel_row1_in, int sel_col2_in, int sel_row2_in)
{
    RGE_View *v5; // esi@1
    RGE_Map *v6; // ecx@1
    RGE_Map *v7; // ecx@4

    v5 = this;
    v6 = this->map;
    if( v6 && rge_base_game->game_mode != 21 )
        RGE_Map::request_redraw(v6, v5->sel_col1, v5->sel_row1, v5->sel_col2, v5->sel_row2, 0);
    v7 = v5->map;
    v5->sel_col1 = sel_col1_in;
    v5->sel_row1 = sel_row1_in;
    v5->sel_col2 = sel_col2_in;
    v5->sel_row2 = sel_row2_in;
    if( v7 && rge_base_game->game_mode != 21 )
        RGE_Map::request_redraw(v7, sel_col1_in, sel_row1_in, sel_col2_in, sel_row2_in, 16);
    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
}

//----- (005345D0) --------------------------------------------------------
int RGE_View::get_selection_area(int *sel_col1_in, int *sel_row1_in, int *sel_col2_in, int *sel_row2_in, int fix_coords)
{
    int v6; // edx@1
    int v7; // eax@1
    int result; // eax@5
    int v9; // edx@8
    int v10; // edx@12
    int v11; // edx@16
    int v12; // ecx@20
    int v13; // eax@23
    int v14; // ecx@23
    int v15; // esi@23
    int v16; // edx@23
    int v17; // ebx@23
    int v18; // edi@25

    *sel_col1_in = this->sel_col1;
    *sel_row1_in = this->sel_row1;
    *sel_col2_in = this->sel_col2;
    v6 = this->sel_row2;
    *sel_row2_in = v6;
    v7 = *sel_col1_in;
    if( *sel_col1_in != -1 || *sel_row1_in != -1 || *sel_col2_in != -1 || v6 != -1 )
    {
        if( v7 >= 0 )
        {
            v9 = this->map->map_width;
            if( v7 >= v9 )
                *sel_col1_in = v9 - 1;
        }
        else
        {
            *sel_col1_in = 0;
        }
        if( *sel_row1_in >= 0 )
        {
            v10 = this->map->map_height;
            if( *sel_row1_in >= v10 )
                *sel_row1_in = v10 - 1;
        }
        else
        {
            *sel_row1_in = 0;
        }
        if( *sel_col2_in >= 0 )
        {
            v11 = this->map->map_width;
            if( *sel_col2_in >= v11 )
                *sel_col2_in = v11 - 1;
        }
        else
        {
            *sel_col2_in = 0;
        }
        if( *sel_row2_in >= 0 )
        {
            v12 = this->map->map_height;
            if( *sel_row2_in >= v12 )
                *sel_row2_in = v12 - 1;
        }
        else
        {
            *sel_row2_in = 0;
        }
        if( fix_coords )
        {
            v13 = *sel_col1_in;
            v14 = *sel_col2_in;
            v15 = *sel_row2_in;
            v16 = *sel_row1_in;
            v17 = *sel_col1_in;
            if( *sel_col1_in >= *sel_col2_in )
                v17 = *sel_col2_in;
            *sel_col1_in = v17;
            v18 = v16;
            if( v16 >= v15 )
                v18 = v15;
            *sel_row1_in = v18;
            if( v13 <= v14 )
                v13 = v14;
            *sel_col2_in = v13;
            if( v16 <= v15 )
                v16 = v15;
            *sel_row2_in = v16;
        }
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (005346F0) --------------------------------------------------------
void RGE_View::CreateBlitQueue(RECT *src_rect, RECT *dest_rect, int xDelta, int yDelta)
{
    RGE_View *v5; // esi@1
    RECT *v6; // edx@3
    int v7; // ebx@3
    int v8; // eax@5
    int v9; // edi@6
    int v10; // edi@7
    int v11; // eax@7
    int v12; // edx@7
    int v13; // ebx@9
    int v14; // ecx@11
    int v15; // edi@15
    int v16; // ebp@15
    int v17; // ebx@15
    Blit_Queue_Entry *v18; // eax@29
    Blit_Queue_Entry *v19; // eax@31
    int v20; // eax@33
    int v21; // ecx@34
    int v22; // ecx@43
    int v23; // edx@43
    int yd; // [sp+10h] [bp-34h]@16
    signed int vBlits; // [sp+14h] [bp-30h]@11
    int One_Blit; // [sp+18h] [bp-2Ch]@1
    int blt_deltaY; // [sp+1Ch] [bp-28h]@0
    int blt_deltaX; // [sp+20h] [bp-24h]@0
    int v29; // [sp+24h] [bp-20h]@5
    int v30; // [sp+2Ch] [bp-18h]@6
    int blt_src; // [sp+34h] [bp-10h]@0
    int blt_src_4; // [sp+38h] [bp-Ch]@0
    int blt_src_8; // [sp+3Ch] [bp-8h]@0
    int blt_src_12; // [sp+40h] [bp-4h]@0
    RECT *dest_recta; // [sp+4Ch] [bp+8h]@33

    v5 = this;
    One_Blit = 0;
    if( !xDelta && !yDelta )
        return;
    v6 = src_rect;
    v7 = src_rect->top;
    if( v7 <= dest_rect->bottom && src_rect->left <= dest_rect->right )
    {
        v8 = src_rect->bottom;
        v29 = v8;
        if( v8 >= dest_rect->top )
        {
            v9 = src_rect->right;
            v30 = v9;
            if( v9 >= dest_rect->left )
            {
                v10 = v9 - src_rect->left + 1;
                v11 = v8 - v7 + 1;
                v12 = yDelta;
                if( yDelta < 0 )
                    v12 = -yDelta;
                v13 = xDelta;
                if( xDelta < 0 )
                    v13 = -xDelta;
                v14 = 9999;
                vBlits = 9999;
                if( yDelta )
                    vBlits = (v12 + v11 - 1) / v12;
                v6 = src_rect;
                if( xDelta )
                {
                    v6 = src_rect;
                    v14 = (v13 + v10 - 1) / v13;
                }
                blt_src = v6->left;
                v15 = v6->top;
                v16 = v6->right;
                v17 = v6->bottom;
                blt_deltaX = 0;
                blt_deltaY = 0;
                if( vBlits >= v14 )
                {
                    yd = v14;
                    blt_deltaX = xDelta;
                    if( xDelta >= 0 )
                        v16 = xDelta + src_rect->left - 1;
                    else
                        blt_src = xDelta + v30 + 1;
                }
                else
                {
                    yd = vBlits;
                    blt_deltaY = yDelta;
                    if( yDelta >= 0 )
                        v17 = yDelta + src_rect->top - 1;
                    else
                        v15 = yDelta + v29 + 1;
                }
                goto CBQ_One;
            }
            v6 = src_rect;
        }
    }
    v16 = blt_src_8;
    v17 = blt_src_12;
    v15 = blt_src_4;
    One_Blit = 1;
    yd = 1;
CBQ_One:
    if( yd > v5->Blt_Queue_Allocated )
    {
        if( v5->Blit_Queue )
        {
            free(v5->Blit_Queue);
            v6 = src_rect;
        }
        v5->Blit_Queue = 0;
    }
    if( !v5->Blit_Queue )
    {
        v18 = (Blit_Queue_Entry *)calloc(yd, 0x20u);
        v5->Blt_Queue_Allocated = yd;
        v6 = src_rect;
        v5->Blit_Queue = v18;
    }
    if( One_Blit )
    {
        v19 = v5->Blit_Queue;
        v19->src.left = v6->left;
        v19->src.top = v6->top;
        v19->src.right = v6->right;
        v19->src.bottom = v6->bottom;
        v5->Blit_Queue->dest = *dest_rect;
    }
    else if( yd > 0 )
    {
        v20 = 0;
        dest_recta = (RECT *)yd;
        do
        {
            v21 = (int)&v5->Blit_Queue[v20].src.left;
            *(_DWORD *)v21 = blt_src;
            *(_DWORD *)(v21 + 4) = v15;
            *(_DWORD *)(v21 + 8) = v16;
            *(_DWORD *)(v21 + 12) = v17;
            v5->Blit_Queue[v20].dest.top = v15 - yDelta;
            v5->Blit_Queue[v20].dest.left = blt_src - xDelta;
            v5->Blit_Queue[v20].dest.bottom = v17 - yDelta;
            v5->Blit_Queue[v20].dest.right = v16 - xDelta;
            v15 += blt_deltaY;
            v17 += blt_deltaY;
            v16 += blt_deltaX;
            blt_src += blt_deltaX;
            if( v15 < src_rect->top )
                v15 = src_rect->top;
            if( blt_src < src_rect->left )
                blt_src = src_rect->left;
            if( v16 > src_rect->right )
                v16 = src_rect->right;
            if( v17 > src_rect->bottom )
                v17 = src_rect->bottom;
            ++v20;
            dest_recta = (RECT *)((char *)dest_recta - 1);
        }
        while( dest_recta );
    }
    v22 = v5->render_rect.left;
    v23 = v5->render_rect.top;
    v5->Queued_Blits = 1;
    v5->Blit_Queue_Size = yd;
    v5->Current_Blit = -1;
    v5->Blit_Offset_X = v22;
    v5->Blit_Offset_Y = v23;
}

//----- (00534A00) --------------------------------------------------------
void RGE_View::ProcessQueuedBlit(int WaitIfBusy)
{
    RGE_View *v2; // esi@1
    Blit_Queue_Entry *v3; // ecx@4
    int v4; // edi@4
    int v5; // eax@7
    int v6; // ecx@7
    int v7; // edx@7
    RECT src; // [sp+Ch] [bp-10h]@7

    v2 = this;
    if( this->Queued_Blits
        && (WaitIfBusy
         || !((int (__stdcall *)(_DWORD, _DWORD))this->render_area->DrawSurface->vfptr[4].AddRef)(
                     this->render_area->DrawSurface,
                     1)) )
    {
        v3 = v2->Blit_Queue;
        v4 = v2->Current_Blit + 1;
        v2->Current_Blit = v4;
        if( !v3
            || v4 < 0
            || v4 >= v2->Blit_Queue_Size
            || (v5 = (int)&v3[v4].src.left,
                    v6 = v2->Blit_Offset_Y,
                    src.top = v6 + *(_DWORD *)(v5 + 4),
                    v7 = v2->Blit_Offset_X,
                    src.left = *(_DWORD *)v5 + v2->Blit_Offset_X,
                    src.bottom = *(_DWORD *)(v5 + 12) + v6 + 1,
                    src.right = *(_DWORD *)(v5 + 8) + v7 + 1,
                    ((void (__stdcall *)(_DWORD, int, int, _DWORD, RECT *, signed int))v2->render_area->DrawSurface->vfptr[2].AddRef)(
                        v2->render_area->DrawSurface,
                        v7 + *(_DWORD *)(v5 + 16),
                        v6 + *(_DWORD *)(v5 + 20),
                        v2->render_area->DrawSurface,
                        &src,
                        16),
                    v2->Current_Blit + 1 >= v2->Blit_Queue_Size) )
        {
            v2->Queued_Blits = 0;
        }
    }
}

//----- (00534AE0) --------------------------------------------------------
void RGE_View::draw()
{
    RGE_View *v1; // ebp@1
    TPanelVtbl *v2; // esi@7
    short v3; // si@8
    int v4; // edx@8
    int v5; // ebx@8
    int v6; // esi@13
    short v7; // dx@13
    int v8; // ecx@15
    int v9; // edi@15
    int v10; // edi@15
    int v11; // edi@18
    unsigned int v12; // edi@22
    int v13; // ebx@23
    int v14; // edi@24
    unsigned int v15; // edi@26
    int v16; // esi@28
    int v17; // ecx@28
    TDrawArea *v18; // ecx@33
    TDrawArea *v19; // ecx@40
    int v20; // eax@40
    TDrawArea *v21; // ecx@42
    int v22; // esi@42
    TDrawArea *v23; // eax@47
    int v24; // ecx@47
    int v25; // eax@50
    bool v26; // sf@50
    int v27; // eax@50
    TDrawArea *v28; // ecx@52
    int v29; // eax@52
    int v30; // edx@52
    int v31; // eax@55
    int v32; // ebx@56
    int v33; // eax@60
    int v34; // eax@63
    int v35; // eax@63
    int v36; // eax@69
    int v37; // eax@69
    int v38; // ecx@73
    int v39; // eax@74
    int v40; // eax@76
    int v41; // ecx@76
    int v42; // edx@76
    int v43; // eax@76
    int v44; // ecx@76
    int v45; // ecx@79
    int v46; // edx@79
    int v47; // eax@79
    int v48; // ecx@79
    int v49; // edx@79
    int v50; // eax@84
    TDrawArea *v51; // ecx@89
    int v52; // ecx@91
    int v53; // edx@91
    int v54; // eax@91
    int v55; // ecx@91
    int v56; // edx@91
    short old_start_map_row; // [sp+10h] [bp-54h]@8
    int old_start_map_rowa; // [sp+10h] [bp-54h]@15
    short old_start_scr_col; // [sp+14h] [bp-50h]@8
    short old_start_scr_row; // [sp+18h] [bp-4Ch]@8
    short old_map_scr_y_offset; // [sp+1Ch] [bp-48h]@8
    short old_map_scr_y_offseta; // [sp+1Ch] [bp-48h]@13
    TPanelVtbl *v63; // [sp+20h] [bp-44h]@8
    RECT clip_rect2; // [sp+24h] [bp-40h]@58
    RECT new_rect; // [sp+34h] [bp-30h]@15
    RECT old_rect; // [sp+44h] [bp-20h]@15
    RECT clip_rect1; // [sp+54h] [bp-10h]@56

    v1 = this;
    tiles_drawn = 0;
    if( view_debug_redraw_all )
    {
        this->render_terrain_mode = 0;
        view_debug_redraw_all = 0;
    }
    if( view_debug_ObstructionMap || view_debug_palette )
        this->render_terrain_mode = 0;
    if( this->world )
    {
        v3 = this->start_map_col;
        old_start_scr_row = this->start_scr_row;
        old_start_map_row = this->start_map_row;
        old_start_scr_col = this->start_scr_col;
        TSpan_List_Manager::ResetAll(this->Terrain_Clip_Mask);
        TSpan_List_Manager::ResetAll(v1->Terrain_Fog_Clip_Mask);
        TSpan_List_Manager::ResetAll(v1->Master_Clip_Mask);
        v4 = v1->map_scr_y_offset;
        v5 = v1->map_scr_x_offset;
        v1->Use_Rect2 = 0;
        v1->Limited_Render_Rect = 0;
        old_map_scr_y_offset = v4;
        RGE_View::update(v1);
        v63 = v1->vfptr;
        v1->vfptr->draw_setup((TPanel *)v1, 0);
        if( v1->render_terrain_mode == 1
            && (v1->start_map_col != v3
             || v1->start_map_row != old_start_map_row
             || v1->start_scr_col != old_start_scr_col
             || v1->start_scr_row != old_start_scr_row) )
        {
            LOWORD(v6) = LOWORD(v1->map_scr_y_offset) - old_map_scr_y_offset;
            v7 = LOWORD(v1->map_scr_x_offset) - v5;
            old_map_scr_y_offseta = LOWORD(v1->map_scr_y_offset) - old_map_scr_y_offset;
            if( LOWORD(v1->map_scr_x_offset) != (_WORD)v5 || (_WORD)v6 )
            {
                v8 = v1->pnl_wid;
                old_rect.left = 0;
                old_rect.top = 0;
                v9 = v1->pnl_hgt;
                old_start_map_rowa = v9;
                old_rect.right = v8 - 1;
                v6 = (signed short)v6;
                v10 = v9 - 1;
                new_rect.right = v7 + v8 - 1;
                old_rect.bottom = v10;
                new_rect.left = v7;
                new_rect.top = (signed short)v6;
                new_rect.bottom = v10 + (signed short)v6;
                if( v10 + (signed short)v6 < 0 || new_rect.right < 0 || v10 < v6 || (v11 = v7, old_rect.right < v7) )
                {
                    v1->render_terrain_mode = 0;
                }
                else
                {
                    if( v7 & 7 )
                    {
                        if( v7 <= 0 )
                            v11 = v7 + 7;
                        v12 = (v11 & 0xFFFFFFF8) - v7;
                        v7 += v12;
                        v1->map_scr_x_offset += v12;
                    }
                    LOWORD(v13) = old_map_scr_y_offseta;
                    if( old_map_scr_y_offseta & 7 )
                    {
                        v14 = v6;
                        if( old_map_scr_y_offseta <= 0 )
                            v14 = v6 + 7;
                        v15 = (v14 & 0xFFFFFFF8) - v6;
                        LOWORD(v13) = v15 + old_map_scr_y_offseta;
                        v1->map_scr_y_offset += v15;
                    }
                    if( v7 < 0 )
                    {
                        v16 = v7;
                        old_rect.left = 0;
                        old_rect.right = v7 + v8 - 1;
                        new_rect.left = -v7;
                        v17 = v8 - 1;
                    }
                    else
                    {
                        v16 = v7;
                        old_rect.left = v7;
                        old_rect.right = v8 - 1;
                        new_rect.left = 0;
                        v17 = v8 - v7 - 1;
                    }
                    new_rect.right = v17;
                    if( (signed short)v13 < 0 )
                    {
                        old_rect.top = 0;
                        v13 = (signed short)v13;
                        old_rect.bottom = (signed short)v13 + old_start_map_rowa - 1;
                        new_rect.top = -(signed short)v13;
                        new_rect.bottom = old_start_map_rowa - 1;
                    }
                    else
                    {
                        v13 = (signed short)v13;
                        old_rect.top = (signed short)v13;
                        old_rect.bottom = old_start_map_rowa - 1;
                        new_rect.top = 0;
                        new_rect.bottom = old_start_map_rowa - (signed short)v13 - 1;
                    }
                    v18 = v1->render_area;
                    if( v18->DrawSystem->DrawType != 1 && v18->UsingVidMem )
                    {
                        RGE_View::CreateBlitQueue(v1, &old_rect, &new_rect, v16, v13);
                        if( MouseSystem )
                            TMousePointer::Poll(MouseSystem);
                        if( v1->Queued_Blits )
                            RGE_View::ProcessQueuedBlit(v1, 0);
                    }
                    else
                    {
                        TDrawArea::OverlayMemCopy(v18, &old_rect, &new_rect, v16, v13, v1->render_rect.left, v1->render_rect.top);
                        v1->Queued_Blits = 0;
                    }
                    DClipInfo_List::Scroll(v1->prior_objs, v16, v13);
                    v19 = v1->save_area1;
                    v20 = v16 + v1->Float_X_Delta;
                    v1->Float_X_Delta = v20;
                    if( v20 < v19->Width )
                    {
                        if( v20 < 0 && TDrawArea::Lock(v19, aViewDraw2, 1) )
                        {
                            v23 = v1->save_area1;
                            v24 = v1->Float_Y_Delta - 1;
                            v1->Float_X_Delta += v23->Width;
                            v1->Float_Y_Delta = v24;
                            if( v24 < 0 )
                                v1->Float_Y_Delta = v23->Height - 1;
                            qmemcpy(
                                (char *)v23->DisplayOffsets[v23->Height - 1] + v23->Width,
                                *(const void **)v23->DisplayOffsets,
                                v1->Float_X_Delta);
                            TDrawArea::Unlock(v1->save_area1, aViewDraw3);
                        }
                    }
                    else if( TDrawArea::Lock(v19, aViewDraw, 1) )
                    {
                        qmemcpy(
                            *v1->save_area1->DisplayOffsets,
                            (char *)v1->save_area1->DisplayOffsets[v1->save_area1->Height - 1] + v1->save_area1->Width,
                            v1->Float_X_Delta - v16);
                        v21 = v1->save_area1;
                        v22 = v1->Float_Y_Delta + 1;
                        v1->Float_X_Delta -= v21->Width;
                        v1->Float_Y_Delta = v22;
                        if( v22 >= v21->Height )
                            v1->Float_Y_Delta = 0;
                        TDrawArea::Unlock(v21, aViewDraw);
                    }
                    v25 = v1->Float_Y_Delta;
                    v26 = v13 + v25 < 0;
                    v27 = v13 + v25;
                    v1->Float_Y_Delta = v27;
                    if( v26 )
                        v1->Float_Y_Delta = v27 + v1->save_area1->Height;
                    v28 = v1->save_area1;
                    v29 = v1->Float_Y_Delta;
                    v30 = v28->Height;
                    if( v29 >= v30 )
                        v1->Float_Y_Delta = v29 - v30;
                    TDrawArea::SetFloatOffsets(v28, v1->Float_X_Delta, v1->Float_Y_Delta);
                    if( new_rect.left || (v31 = v1->pnl_wid - 1, new_rect.right != v31) )
                    {
                        if( new_rect.left )
                        {
                            v36 = v1->pnl_hgt;
                            v32 = 0;
                            clip_rect1.right = new_rect.left - 1;
                            v37 = v36 - 1;
                            clip_rect1.left = 0;
                            clip_rect1.top = 0;
                            clip_rect1.bottom = v37;
                            if( new_rect.top || new_rect.bottom != v37 )
                            {
                                clip_rect2.left = new_rect.left;
                                if( new_rect.top )
                                {
                                    v39 = v1->pnl_wid;
                                    clip_rect2.top = 0;
                                    clip_rect2.right = v39 - 1;
                                    clip_rect2.bottom = new_rect.top - 1;
                                }
                                else
                                {
                                    v38 = v1->pnl_wid - 1;
                                    clip_rect2.top = new_rect.bottom + 1;
                                    clip_rect2.right = v38;
                                    clip_rect2.bottom = v37;
                                }
                            }
                            else
                            {
                                clip_rect2.left = -1;
                            }
                        }
                        else
                        {
                            v34 = v1->pnl_hgt;
                            clip_rect1.right = v1->pnl_wid - 1;
                            v32 = new_rect.right + 1;
                            v35 = v34 - 1;
                            clip_rect1.left = new_rect.right + 1;
                            clip_rect1.top = 0;
                            clip_rect1.bottom = v35;
                            if( new_rect.top || new_rect.bottom != v35 )
                            {
                                clip_rect2.left = 0;
                                if( new_rect.top )
                                {
                                    clip_rect2.top = 0;
                                    clip_rect2.right = new_rect.right;
                                    clip_rect2.bottom = new_rect.top - 1;
                                }
                                else
                                {
                                    clip_rect2.right = new_rect.right;
                                    clip_rect2.top = new_rect.bottom + 1;
                                    clip_rect2.bottom = v35;
                                }
                            }
                            else
                            {
                                clip_rect2.left = -1;
                            }
                        }
                    }
                    else
                    {
                        v32 = -1;
                        clip_rect1.left = -1;
                        if( new_rect.top || new_rect.bottom != v1->pnl_hgt - 1 )
                        {
                            clip_rect2.left = 0;
                            if( new_rect.top )
                            {
                                clip_rect2.top = 0;
                                clip_rect2.right = v31;
                                clip_rect2.bottom = new_rect.top - 1;
                            }
                            else
                            {
                                clip_rect2.right = v31;
                                v33 = v1->pnl_hgt - 1;
                                clip_rect2.top = new_rect.bottom + 1;
                                clip_rect2.bottom = v33;
                            }
                        }
                        else
                        {
                            clip_rect2.left = -1;
                        }
                    }
                    if( v32 != -1 )
                    {
                        TDrawArea::PtrClear(v1->save_area1, &clip_rect1, 0);
                        v40 = clip_rect1.left;
                        v41 = clip_rect1.top;
                        v42 = (int)&v1->Render_Rect1.left;
                        v1->Limited_Render_Rect = 1;
                        *(_DWORD *)v42 = v40;
                        v43 = clip_rect1.right;
                        *(_DWORD *)(v42 + 4) = v41;
                        v44 = clip_rect1.bottom;
                        *(_DWORD *)(v42 + 8) = v43;
                        *(_DWORD *)(v42 + 12) = v44;
                    }
                    if( clip_rect2.left != -1 )
                    {
                        TDrawArea::PtrClear(v1->save_area1, &clip_rect2, 0);
                        if( clip_rect1.left == -1 )
                        {
                            v52 = clip_rect2.left;
                            v53 = clip_rect2.top;
                            v54 = (int)&v1->Render_Rect1.left;
                            v1->Limited_Render_Rect = 1;
                            *(_DWORD *)v54 = v52;
                            v55 = clip_rect2.right;
                            *(_DWORD *)(v54 + 4) = v53;
                            v56 = clip_rect2.bottom;
                            *(_DWORD *)(v54 + 8) = v55;
                            *(_DWORD *)(v54 + 12) = v56;
                        }
                        else
                        {
                            v45 = clip_rect2.left;
                            v46 = clip_rect2.top;
                            v47 = (int)&v1->Render_Rect2.left;
                            v1->Use_Rect2 = 1;
                            *(_DWORD *)v47 = v45;
                            v48 = clip_rect2.right;
                            *(_DWORD *)(v47 + 4) = v46;
                            v49 = clip_rect2.bottom;
                            *(_DWORD *)(v47 + 8) = v48;
                            *(_DWORD *)(v47 + 12) = v49;
                        }
                    }
                }
            }
        }
        if( MouseSystem )
            TMousePointer::Poll(MouseSystem);
        if( v1->Queued_Blits )
            RGE_View::ProcessQueuedBlit(v1, 0);
        v50 = rge_base_game->game_mode;
        if( v50 >= 9 && (v50 <= 10 || v50 == 19) )
            RGE_View::draw_paint_brush(v1);
        if( !v1->render_terrain_mode )
        {
            v51 = v1->save_area1;
            v1->Float_X_Delta = 0;
            v1->Float_Y_Delta = 0;
            TDrawArea::SetFloatOffsets(v51, 0, 0);
            TDrawArea::PtrClear(v1->save_area1, &v1->save_area1->ClipRect, 0);
        }
        RGE_View::draw_view(v1, 10, v1->save_area1);
        v1->render_terrain_mode = 1;
        v63->draw_finish((TPanel *)v1);
        ++frame_count;
    }
    else
    {
        v2 = this->vfptr;
        ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
        TDrawArea::Clear(v1->render_area, &v1->clip_rect, v1->color);
        v2->draw_finish((TPanel *)v1);
    }
}
// 87D7A4: using guessed type int view_debug_redraw_all;
// 87D7A8: using guessed type int view_debug_ObstructionMap;
// 87D7B0: using guessed type int view_debug_palette;
// 87D7B8: using guessed type __int32 frame_count;
// 87D7BC: using guessed type __int32 tiles_drawn;

//----- (00535210) --------------------------------------------------------
void RGE_View::update()
{
    RGE_View *v1; // esi@1
    RGE_Player *v2; // ebx@1
    signed __int64 v3; // rax@4
    short v4; // di@4
    short v5; // bp@4
    double v6; // st7@4
    double v7; // st6@4
    float v8; // ecx@4
    __int64 v9; // rax@4
    float col_adj; // ST14_4@4
    double v11; // st7@4
    double v12; // st6@4
    int v13; // ebx@4
    double v14; // st5@4
    short v15; // bp@4
    int v16; // ST14_4@4
    double v17; // st5@4
    double v18; // st6@4
    int v19; // ebx@4
    short v20; // ST18_2@4
    int v21; // ebp@4
    int v22; // ebx@4
    __int64 v23; // rax@4

    v1 = this;
    v2 = this->player;
    if( v2 && (v2->view_x != this->last_view_x || v2->view_y != this->last_view_y) )
    {
        this->center_map_col = (signed __int64)v2->view_x;
        v3 = (signed __int64)v2->view_y;
        v4 = this->center_map_col;
        this->center_map_row = v3;
        v5 = this->render_rect.top;
        v6 = v2->view_x - (double)v4;
        v7 = v2->view_y - (double)(signed short)v3;
        this->last_view_x = v2->view_x;
        v8 = v2->view_y;
        LOWORD(v2) = v1->render_rect.left;
        v9 = v1->pnl_wid;
        col_adj = v7;
        v1->last_view_y = v8;
        v11 = v6 * 0.5;
        LOWORD(v2) = (((signed int)v9 - HIDWORD(v9)) >> 1) + (_WORD)v2;
        v12 = col_adj * 0.5;
        LOWORD(v8) = v1->tile_half_wid;
        v13 = (int)v2 - LODWORD(v8);
        v14 = (double)v1->tile_wid;
        LOWORD(v8) = v1->tile_half_hgt;
        v1->center_scr_col = v13;
        v15 = v1->pnl_hgt / 2 + v5 - LOWORD(v8);
        v1->center_scr_row = v15;
        v16 = -(signed int)(signed __int64)(v12 * v14 + v11 * v14);
        v17 = v12;
        v18 = (double)v1->tile_hgt;
        HIDWORD(v9) = v1->map;
        LODWORD(v9) = -(*(_DWORD *)&v1->tile_half_hgt + (unsigned __int64)(signed __int64)(v17 * v18 - v11 * v18));
        v19 = v16 + v13;
        v1->center_scr_col = v19;
        v20 = v9 + v15;
        v1->center_scr_row = v9 + v15;
        v21 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v9) + 36236) + 4 * v1->center_map_row) + 24 * v4;
        HIDWORD(v9) = v1->elev_hgt;
        v1->map_scr_x_offset = *(_WORD *)v21 - (signed short)v19;
        v1->map_scr_y_offset = *(_WORD *)(v21 + 2) + ((unsigned int)*(_BYTE *)(v21 + 5) >> 5) * HIDWORD(v9) - v20;
        LOWORD(v21) = v1->tile_half_hgt;
        v1->center_scr_col_offset = v16 + v1->tile_half_wid * (v1->center_map_row + v4);
        WORD2(v9) = v9 + v21 * (v1->center_map_row - v4);
        v1->start_map_row = v1->center_map_row;
        v1->center_scr_row_offset = WORD2(v9);
        LODWORD(v9) = v1->max_col_num / 2 + 2;
        v1->start_map_row -= v9;
        v22 = v19 - 2 * *(_DWORD *)&v1->tile_half_wid * v9;
        v1->start_map_col = v4 - v9;
        v23 = v1->max_row_num;
        v1->start_scr_col = v22;
        LODWORD(v23) = (((signed int)v23 - HIDWORD(v23)) >> 1) + 1;
        v1->start_map_col += v23;
        v1->start_map_row -= v23;
        v1->start_scr_row = v20 - 2 * v21 * v23;
    }
}

//----- (00535480) --------------------------------------------------------
void RGE_View::draw_view(char function_mode_in, TDrawArea *draw_area_in)
{
    TDrawArea *v3; // eax@1
    RGE_View *v4; // esi@1
    TDrawArea *v5; // ecx@3
    int v6; // ebx@4
    int v7; // eax@4
    int v8; // edi@4
    int v9; // ebp@4
    int v10; // edx@4
    int v11; // eax@4
    RECT v12; // ST14_16@8
    int v13; // ecx@12
    int v14; // eax@12
    int v15; // ebp@12
    int v16; // edx@12
    int v17; // ecx@12
    int v18; // eax@12
    int save_render_rect; // [sp+10h] [bp-10h]@0
    int save_render_rect_4; // [sp+14h] [bp-Ch]@0
    int save_render_rect_8; // [sp+18h] [bp-8h]@0
    int save_render_rect_12; // [sp+1Ch] [bp-4h]@0

    v3 = draw_area_in;
    v4 = this;
    if( !draw_area_in )
        v3 = this->render_area;
    this->cur_render_area = v3;
    v5 = v3;
    if( v3 == v4->save_area1 )
    {
        v6 = v4->render_rect.left;
        v8 = v4->render_rect.top;
        v9 = v4->render_rect.bottom;
        save_render_rect_8 = v4->render_rect.right;
        v7 = v4->render_rect.right;
        v4->render_rect.left = 0;
        v4->start_scr_col -= v6;
        v4->start_scr_row -= v8;
        v4->render_rect.right = v7 - v6;
        v4->render_rect.top = 0;
        v10 = v4->map_scr_x_offset;
        v4->render_rect.bottom = v9 - v8;
        v11 = v4->map_scr_y_offset;
        v4->map_scr_x_offset = v6 + v10;
        v4->map_scr_y_offset = v8 + v11;
    }
    else
    {
        v9 = save_render_rect_12;
        v8 = save_render_rect_4;
        v6 = save_render_rect;
    }
    if( TDrawArea::Lock(v5, aViewDraw_view, 1) )
    {
        if( function_mode_in == 10 )
        {
            *(_QWORD *)&v12.left = __PAIR__(v8, v6);
            *(_QWORD *)&v12.right = __PAIR__(v9, save_render_rect_8);
            RGE_View::view_function_terrain(v4, 10, v12);
        }
        else
        {
            RGE_View::view_function(v4, function_mode_in, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        TDrawArea::Unlock(v4->cur_render_area, aViewDraw_view);
    }
    if( v4->cur_render_area == v4->save_area1 )
    {
        v13 = v4->render_rect.right;
        v14 = v4->render_rect.bottom;
        v15 = v4->render_rect.left;
        v16 = v4->render_rect.top;
        v4->start_scr_col += v6;
        v4->start_scr_row += v8;
        v4->render_rect.right = v6 + v13;
        v17 = v4->map_scr_x_offset;
        v4->render_rect.bottom = v8 + v14;
        v18 = v4->map_scr_y_offset - v8;
        v4->render_rect.left = v6 + v15;
        v4->render_rect.top = v8 + v16;
        v4->map_scr_x_offset = v17 - v6;
        v4->map_scr_y_offset = v18;
    }
    v4->cur_render_area = 0;
}

//----- (00535610) --------------------------------------------------------
void RGE_View::draw_object_outline()
{
    RGE_View *v1; // edi@1
    short v2; // si@1
    RGE_Master_Static_Object *v3; // esi@2
    int v4; // ebx@3
    int v5; // edx@5
    RGE_Master_Static_ObjectVtbl *v6; // ebx@8
    int v7; // edx@9
    int v8; // ST18_4@9
    float v9; // ST0C_4@9
    float v10; // ST08_4@9
    RGE_Game_World *v11; // eax@9
    char v12; // cl@9
    unsigned int v13; // eax@11
    int v14; // eax@12
    int v15; // eax@14
    int v16; // ebp@15
    int v17; // edx@16
    RGE_Static_Object *v18; // eax@21
    TDrawArea *v19; // [sp+8h] [bp-6Ch]@22
    int v20; // [sp+Ch] [bp-68h]@22
    int v21; // [sp+10h] [bp-64h]@22
    unsigned int v22; // [sp+14h] [bp-60h]@22
    int v23; // [sp+18h] [bp-5Ch]@22
    int v24; // [sp+20h] [bp-54h]@22
    int v25; // [sp+24h] [bp-50h]@22
    short x1; // [sp+38h] [bp-3Ch]@9
    short y2; // [sp+3Ah] [bp-3Ah]@9
    short x4; // [sp+3Ch] [bp-38h]@9
    short y3; // [sp+3Eh] [bp-36h]@9
    short x2; // [sp+40h] [bp-34h]@9
    short y1; // [sp+42h] [bp-32h]@9
    int scr_x; // [sp+44h] [bp-30h]@8
    int frame_color; // [sp+48h] [bp-2Ch]@17
    int scr_y; // [sp+4Ch] [bp-28h]@8
    float x3; // [sp+50h] [bp-24h]@9
    float y4; // [sp+54h] [bp-20h]@9
    POINT point; // [sp+58h] [bp-1Ch]@3
    RGE_Pick_Info pick_info; // [sp+60h] [bp-14h]@7

    v1 = this;
    v2 = rge_base_game->master_obj_id;
    if( v2 != -1 )
    {
        v3 = *(RGE_Master_Static_Object **)(RGE_Base_Game::get_player(rge_base_game)->sprite_update_index + 4 * v2);
        if( v3 )
        {
            RGE_Base_Game::get_mouse_pos(rge_base_game, &point);
            v4 = v1->render_rect.left;
            if( point.x >= v4 && point.x <= v1->render_rect.right )
            {
                v5 = v1->render_rect.top;
                if( point.y >= v5
                    && point.y <= v1->render_rect.bottom
                    && (unsigned __int8)RGE_View::pick(v1, 40, 0, point.x - v4, point.y - v5, &pick_info, 0) == 51 )
                {
                    v6 = v3->vfptr;
                    v3->vfptr->alignment(v3, (float *)&pick_info, &pick_info.y, v1->world, 0);
                    if( RGE_View::get_tile_screen_coords(
                                 v1,
                                 (signed __int64)pick_info.x,
                                 (signed __int64)pick_info.y,
                                 (short *)&scr_x,
                                 (short *)&scr_y,
                                 1) )
                    {
                        RGE_Master_Static_Object::alignment_box(
                            v3,
                            v1->world,
                            pick_info.x,
                            pick_info.y,
                            &x1,
                            &y1,
                            &x2,
                            &y2,
                            (short *)&x3,
                            &y3,
                            &x4,
                            (short *)&y4);
                        LOBYTE(v7) = v3->elevation_flag;
                        v8 = v7;
                        v9 = pick_info.y;
                        v10 = pick_info.x;
                        v11 = RGE_Base_Game::get_player(rge_base_game);
                        v12 = v6->check_placement(
                                        v3,
                                        (RGE_Player *)v11,
                                        COERCE_FLOAT(LODWORD(v10)),
                                        COERCE_FLOAT(LODWORD(v9)),
                                        0,
                                        1,
                                        v8,
                                        0,
                                        1,
                                        1,
                                        1);
                        fog_next_shape = 1;
                        if( v12 )
                        {
                            v13 = (v1->world->world_time >> 7) & 7;
                            if( v13 >= 4 )
                                v14 = 44 - v13;
                            else
                                v14 = v13 + 36;
                            v15 = 16 * v14;
                            LOBYTE(v15) = v15 | 9;
                            fog_next_shape = v15;
                        }
                        else
                        {
                            fog_next_shape = 5;
                        }
                        scr_x += LODWORD(x3) + (x1 - SLOWORD(x3)) / 2;
                        v16 = LODWORD(y4) + (y2 - SLOWORD(y4)) / 2 + scr_y;
                        scr_y += LODWORD(y4) + (y2 - SLOWORD(y4)) / 2;
                        if( v3->sprite )
                        {
                            SDI_Draw_Line = (signed short)v16;
                            v17 = v3->draw_flag & 1;
                            if( v12 )
                                LOBYTE(frame_color) = -105;
                            else
                                LOBYTE(frame_color) = v3->draw_color;
                            if( rge_base_game->game_mode == 8 && rge_base_game->sub_game_mode == 1 && (v18 = v1->movable_object) != 0 )
                            {
                                v25 = frame_color;
                                v24 = v17;
                                v23 = v18->facet;
                                v22 = (unsigned int)v18->owner->color_table;
                                v21 = v16;
                                v20 = scr_x;
                                v19 = v1->render_area;
                            }
                            else
                            {
                                v25 = frame_color;
                                v24 = v17;
                                v23 = 0;
                                v22 = RGE_Base_Game::get_player(rge_base_game)[1].world_time;
                                v21 = scr_y;
                                v20 = scr_x;
                                v19 = v1->render_area;
                            }
                            v6->draw(v3, v19, v20, v21, (RGE_Color_Table *)v22, v23, 0, v24, v25);
                        }
                        fog_next_shape = 0;
                    }
                }
            }
        }
    }
}

//----- (005358B0) --------------------------------------------------------
void RGE_View::draw_paint_brush()
{
    RGE_View *v1; // edi@1
    short v2; // bx@7
    POINT point; // [sp+8h] [bp-1Ch]@1
    RGE_Pick_Info pick_info; // [sp+10h] [bp-14h]@5

    v1 = this;
    RGE_View::set_selection_area(this, -1, -1, -1, -1);
    RGE_Base_Game::get_mouse_pos(rge_base_game, &point);
    if( point.x >= v1->render_rect.left
        && point.x <= v1->render_rect.right
        && point.y >= v1->render_rect.top
        && point.y <= v1->render_rect.bottom
        && (unsigned __int8)RGE_View::pick(v1, 40, 0, point.x, point.y, &pick_info, 0) == 51 )
    {
        if( rge_base_game->game_mode == 19 )
        {
            pick_info.x = 1.0 - (double)(signed int)(-3 * (unsigned __int64)(signed __int64)(pick_info.x * 0.33333334));
            v2 = 3;
            pick_info.y = 1.0 - (double)(signed int)(-3 * (unsigned __int64)(signed __int64)(pick_info.y * 0.33333334));
        }
        else
        {
            v2 = rge_base_game->brush_size;
        }
        RGE_View::set_selection_area(
            v1,
            (unsigned __int64)(signed __int64)pick_info.x - (v2 >> 1),
            (unsigned __int64)(signed __int64)pick_info.y - (v2 >> 1),
            (unsigned __int64)(signed __int64)pick_info.x + (v2 >> 1),
            (unsigned __int64)(signed __int64)pick_info.y + (v2 >> 1));
    }
}

//----- (005359E0) --------------------------------------------------------
int RGE_View::pick(char pick_mode_in, char select_level, int x, int y, RGE_Pick_Info *pick_info, RGE_Static_Object *last_picked_object)
{
    char v7; // al@1
    RGE_Pick_Info *v8; // esi@1
    RGE_Pick_Info *v9; // edi@1
    int result; // eax@1
    POINT start_mouse_pos; // [sp+8h] [bp-10h]@1
    POINT mouse_pos; // [sp+10h] [bp-8h]@1

    v7 = pick_mode_in;
    *(_DWORD *)&pick_mode_in = pick_mode_in != 40 ? (unsigned int)last_picked_object : 0;
    mouse_pos.y = y;
    start_mouse_pos.y = y;
    v8 = pick_info;
    mouse_pos.x = x;
    start_mouse_pos.x = x;
    v9 = pick_info;
    LODWORD(pick_info->x) = 0;
    LODWORD(v9->y) = 0;
    *(_DWORD *)&v9->scr_x = 0;
    v9->object = 0;
    v9->tile = 0;
    result = RGE_View::view_function(
                         this,
                         v7,
                         select_level,
                         &mouse_pos,
                         &start_mouse_pos,
                         (void **)&pick_mode_in,
                         &v9->x,
                         &v9->y,
                         &v9->scr_x,
                         &v9->scr_y);
    if( (_BYTE)result == 52 )
    {
        v8->object = (RGE_Static_Object *)pick_mode_in;
    }
    else if( (_BYTE)result == 51 )
    {
        v8->tile = (RGE_Tile *)pick_mode_in;
    }
    return result;
}

//----- (00535A80) --------------------------------------------------------
char RGE_View::pick_multi(char select_level, int x1, int y1, int x2, int y2)
{
    RGE_View *v6; // edi@1
    int v7; // ebx@1
    int v8; // esi@1
    int v9; // ebp@1
    _DWORD *v10; // ebx@2
    RGE_Static_Object *v11; // eax@4
    char result; // al@11
    signed int v13; // ecx@12
    signed int v14; // eax@12
    int v15; // edx@12
    int v16; // edx@16
    int v17; // eax@19
    RGE_Static_Object *v18; // ecx@20
    int v19; // ebx@20
    void *v20; // ebp@21
    RGE_Static_Object *v21; // esi@23
    int v22; // eax@29
    int picked_any; // [sp+10h] [bp-4h]@1
    int y1a; // [sp+20h] [bp+Ch]@21
    int x2a; // [sp+24h] [bp+10h]@20

    v6 = this;
    v7 = y1;
    v8 = 0;
    picked_any = 0;
    v9 = RGE_View::pick_multi_objects(this, x1, y1, x2, y2, 10, 20, this->player->id, select_level, 1);
    if( v9 > 0 )
    {
        v10 = &Picked_Objects;
        do
        {
            if( *v10 != -1 )
            {
                v11 = v6->world->objectsValue[*v10];
                if( v11 )
                {
                    if( v11->object_state < 7u )
                    {
                        if( !RGE_Player::select_one_object(v6->player, v11, 0) )
                            break;
                        picked_any = 1;
                    }
                }
            }
            ++v8;
            v10 += 3;
        }
        while( v8 < v9 );
        v7 = y1;
    }
    if( picked_any )
    {
        result = 1;
    }
    else
    {
        v13 = x2 - x1;
        v14 = y2 - v7;
        v15 = x2 - x1;
        if( x2 - x1 >= y2 - v7 )
            v15 = y2 - v7;
        if( v15 >= 50 )
        {
            v16 = 50;
        }
        else if( v13 >= v14 )
        {
            v16 = y2 - v7;
        }
        else
        {
            v16 = x2 - x1;
        }
        v17 = RGE_View::pick_objects(v6, x1 + v13 / 2, v7 + v14 / 2, 10, 20, v16, 4, 1);
        if( !v17 )
            goto LABEL_41;
        v18 = 0;
        v19 = 0;
        x2a = 0;
        if( v17 > 0 )
        {
            v20 = &Picked_Objects;
            y1a = v17;
            do
            {
                if( *(_DWORD *)v20 >= 0 )
                {
                    v21 = v6->world->objectsValue[*(_DWORD *)v20];
                    if( v21 )
                    {
                        if( v21->object_state < 7u
                            && v21->master_obj->select_level >= 2u
                            && (v6->map->map_visible_flag
                             || (int)v6->vfptr[1].__vecDelDtor((TPanel *)v6, (unsigned int)v21)
                             || RGE_Visible_Map::get_visible(
                                        v6->player->visible,
                                        (signed __int64)v21->world_x,
                                        (signed __int64)v21->world_y) == 15) )
                        {
                            v22 = (*(int (**)(RGE_View *, RGE_Static_Object *, _DWORD))&v6->vfptr[1].gap4[0])(
                                            v6,
                                            v21,
                                            *((_WORD *)v20 + 2));
                            if( v21->owner == v6->player )
                                v22 += 5;
                            if( v22 > v19 )
                            {
                                x2a = (int)v21;
                                v19 = v22;
                            }
                        }
                    }
                }
                v20 = (char *)v20 + 12;
                --y1a;
            }
            while( y1a );
            v18 = (RGE_Static_Object *)x2a;
        }
        if( v18 && RGE_Player::select_one_object(v6->player, v18, 0) )
            result = 1;
        else
LABEL_41:
            result = 0;
    }
    return result;
}

//----- (00535C70) --------------------------------------------------------
int RGE_View::pick(char function_mode_in, char select_level, POINT *mouse_pos, POINT *start_mouse_pos, void **picked_item, float *item_x, float *item_y, short *item_scr_x, short *item_scr_y)
{
    return RGE_View::view_function(
                     this,
                     function_mode_in,
                     select_level,
                     mouse_pos,
                     start_mouse_pos,
                     picked_item,
                     item_x,
                     item_y,
                     item_scr_x,
                     item_scr_y);
}

//----- (00535CB0) --------------------------------------------------------
int __stdcall RGE_View::pick_through_fog(RGE_Static_Object *obj)
{
    return 0;
}

//----- (00535CC0) --------------------------------------------------------
int RGE_View::pick_weight(RGE_Static_Object *obj, int confidence)
{
    RGE_Static_Object *v3; // eax@1
    int v4; // edx@3
    int result; // eax@5
    char obja; // [sp+4h] [bp+4h]@1

    v3 = obj;
    obja = obj->master_obj->select_level;
    v4 = this->UC_ObjectTouched && this->UC_TouchedObj == v3->id;
    result = 0;
    if( obja != 2 )
    {
        if( obja != 3 )
        {
            if( obja == 4 )
            {
                if( v4 )
                {
                    result = 5;
                }
                else if( confidence == 1 || confidence == 2 )
                {
                    result = 4;
                }
                else
                {
                    result = (confidence == 3) + 2;
                }
            }
            else
            {
                result = 1;
            }
            return result;
        }
        if( v4 )
            return 5;
        if( confidence != 1 )
        {
            if( confidence == 2 )
                result = 3;
            return result;
        }
        return 3;
    }
    if( v4 )
        return 5;
    if( confidence == 1 || confidence == 2 )
        return 3;
    if( confidence == 3 )
        result = 2;
    return result;
}

//----- (00535DA0) --------------------------------------------------------
int RGE_View::get_tile_screen_coords(short find_col, short find_row, short *scr_x, short *scr_y, int drop)
{
    RGE_Map *v6; // esi@6
    int v7; // edx@9
    char v8; // bl@10
    int v9; // esi@10
    int result; // eax@21

    if( scr_x )
        *scr_x = 0;
    if( scr_y )
        *scr_y = 0;
    if( find_col >= 0
        && (v6 = this->map, find_col < v6->map_width)
        && find_row >= 0
        && find_row < v6->map_height
        && (v7 = (int)&v6->map_row_offset[find_row][find_col].screen_xpos) != 0 )
    {
        v8 = *(_BYTE *)(v7 + 4);
        v9 = *(_WORD *)(v7 + 2) + v6->tilesizes[*(_BYTE *)(v7 + 4)].y_delta - this->map_scr_y_offset;
        if( drop )
        {
            if( v8 )
                v9 += this->elev_hgt / 2;
            if( v8 == 6 )
                LOWORD(v9) = v9 - this->elev_hgt;
            if( v8 == 5 )
                LOWORD(v9) = v9 - this->elev_hgt;
            if( v8 == 3 )
                LOWORD(v9) = v9 - this->elev_hgt;
            if( v8 == 11 )
                LOWORD(v9) = v9 - this->elev_hgt;
        }
        result = 1;
        *scr_x = *(_WORD *)v7 - LOWORD(this->map_scr_x_offset);
        *scr_y = v9;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00535EB0) --------------------------------------------------------
void RGE_View::get_center_screen_pos(short *scr_x, short *scr_y)
{
    *scr_x = this->center_scr_row;
    *scr_y = this->center_scr_col;
}

//----- (00535ED0) --------------------------------------------------------
void RGE_View::get_start_coords(short *map_col, short *map_row, short *scr_x, short *scr_y)
{
    if( map_col )
        *map_col = this->start_map_col;
    if( map_row )
        *map_row = this->start_map_row;
    if( scr_x )
        *scr_x = this->start_scr_col;
    if( scr_y )
        *scr_y = this->start_scr_row;
}

//----- (00535F20) --------------------------------------------------------
void RGE_View::get_center_coords(short *map_col, short *map_row, short *scr_x, short *scr_y)
{
    if( map_col )
        *map_col = this->center_map_col;
    if( map_row )
        *map_row = this->center_map_row;
    if( scr_x )
        *scr_x = this->center_scr_col;
    if( scr_y )
        *scr_y = this->center_scr_row;
}

//----- (00535F70) --------------------------------------------------------
void RGE_View::get_tile_sizes(short *wid, short *hgt, short *half_wid, short *half_hgt)
{
    if( wid )
        *wid = this->tile_wid;
    if( hgt )
        *hgt = this->tile_hgt;
    if( half_wid )
        *half_wid = this->tile_half_wid;
    if( half_hgt )
        *half_hgt = this->tile_half_hgt;
}

//----- (00535FC0) --------------------------------------------------------
void RGE_View::get_max_size(short *col_num, short *row_num)
{
    *col_num = this->max_col_num;
    *row_num = this->max_row_num;
}

//----- (00535FE0) --------------------------------------------------------
int RGE_View::view_function(char function_mode_in, char function_parm_in, POINT *mouse_pos, POINT *start_mouse_pos, void **picked_item, float *item_x, float *item_y, short *item_scr_x, short *item_scr_y)
{
    RGE_View *v10; // esi@1
    RGE_Map *v11; // ecx@3
    int v12; // edx@3
    int v13; // eax@4
    int v14; // ecx@5
    int result; // eax@5
    void **v16; // ebp@5
    double v17; // st7@12
    int v18; // edx@22
    int v19; // ecx@22
    short v20; // ax@25
    int v21; // ebp@27
    char v22; // cl@29
    RGE_Visible_Map *v23; // ecx@33
    int v24; // ebx@35
    int v25; // edi@35
    char v26; // al@35
    char v27; // cl@47
    int v28; // ebx@54
    RGE_Map *v29; // edi@58
    int v30; // eax@65
    char v31; // cl@67
    RGE_Static_Object *v32; // edi@85
    RGE_Static_Object *v33; // eax@85
    float *v34; // edi@88
    float *v35; // ebx@88
    char v36; // al@89
    double v37; // st7@98
    char v38; // al@102
    RGE_Map *v39; // edi@105
    unsigned __int8 v40; // bl@105
    short v41; // ax@105
    char v42; // al@115
    TDrawArea *v43; // eax@125
    TDrawArea *v44; // eax@127
    char v45; // al@128
    bool v46; // sf@139
    unsigned __int8 v47; // of@139
    RGE_Map *v48; // ecx@153
    int v49; // edx@153
    int v50; // eax@154
    char v51; // al@155
    char visible; // [sp+13h] [bp-75h]@35
    int screen_col; // [sp+14h] [bp-74h]@22
    short map_row; // [sp+18h] [bp-70h]@22
    RGE_Tile *map_col; // [sp+1Ch] [bp-6Ch]@22
    int start_scr_col2; // [sp+20h] [bp-68h]@0
    int start_scr_row2; // [sp+24h] [bp-64h]@0
    int cur_col_num; // [sp+28h] [bp-60h]@21
    char picked_type; // [sp+2Ch] [bp-5Ch]@5
    char fog_flag; // [sp+30h] [bp-58h]@83
    bool fog_flaga; // [sp+30h] [bp-58h]@122
    RGE_Tile *tile; // [sp+34h] [bp-54h]@52
    RGE_Tile *start_map_col2; // [sp+38h] [bp-50h]@0
    int start_map_row2; // [sp+3Ch] [bp-4Ch]@0
    char direction; // [sp+40h] [bp-48h]@21
    short tile_screen_row; // [sp+44h] [bp-44h]@54
    RGE_Static_Object *last_picked_obj; // [sp+48h] [bp-40h]@0
    int terrain_type; // [sp+4Ch] [bp-3Ch]@0
    unsigned __int8 tile_type; // [sp+50h] [bp-38h]@52
    int col_num; // [sp+54h] [bp-34h]@22
    int row_num; // [sp+58h] [bp-30h]@21
    int calc_sel_col1; // [sp+5Ch] [bp-2Ch]@20
    int calc_sel_col2; // [sp+60h] [bp-28h]@20
    int calc_sel_row1; // [sp+64h] [bp-24h]@20
    int calc_sel_row2; // [sp+68h] [bp-20h]@20
    RGE_Static_Object *orig_picked_obj; // [sp+6Ch] [bp-1Ch]@17
    int find_col; // [sp+70h] [bp-18h]@12
    int find_row; // [sp+74h] [bp-14h]@12
    int max_col_num2; // [sp+78h] [bp-10h]@21
    int max_row_num2; // [sp+7Ch] [bp-Ch]@21
    int list_size; // [sp+80h] [bp-8h]@5
    RGE_Tile_List_Node *list; // [sp+84h] [bp-4h]@5

    v10 = this;
    this->function_mode = function_mode_in;
    this->function_parm = function_parm_in;
    if( function_mode_in == 10 )
    {
        if( this->calc_draw_count )
        {
            v11 = this->map;
            v12 = 0;
            if( v11->num_terrain > 0 )
            {
                do
                {
                    v13 = 17 * (signed short)v12++;
                    v11->terrain_types[24 * v13 / 0x198u].drawn = 0;
                    v11 = v10->map;
                }
                while( (signed short)v12 < v11->num_terrain );
            }
        }
    }
    RGE_Tile_List::get_list_info(&v10->player->tile_list, &list, &list_size);
    LOBYTE(result) = v10->function_mode;
    v16 = picked_item;
    picked_type = 50;
    if( (_BYTE)result == 40 )
        goto LABEL_11;
    if( (_BYTE)result != 60 )
    {
        if( (_BYTE)result != 41 && (_BYTE)result != 42 && (_BYTE)result != 43 && (_BYTE)result != 44 )
            goto LABEL_19;
LABEL_11:
        if( (_BYTE)result != 60 )
            goto LABEL_13;
    }
    v17 = *item_y;
    find_col = (signed __int64)*item_x;
    find_row = (signed __int64)v17;
LABEL_13:
    HIWORD(result) = HIWORD(item_scr_x);
    HIWORD(v14) = HIWORD(item_scr_y);
    *(_DWORD *)item_x = 0;
    *(_DWORD *)item_y = 0;
    *item_scr_x = 0;
    *item_scr_y = 0;
    LOBYTE(result) = v10->function_mode;
    if( (_BYTE)result == 41 || (_BYTE)result == 42 || (_BYTE)result == 43 || (_BYTE)result == 44 )
        orig_picked_obj = (RGE_Static_Object *)*picked_item;
    *picked_item = 0;
    last_picked_obj = 0;
LABEL_19:
    if( v10->function_mode != 14
        || (result = RGE_View::get_selection_area(v10, &calc_sel_col1, &calc_sel_row1, &calc_sel_col2, &calc_sel_row2, 1)) != 0 )
    {
        LOWORD(start_scr_col2) = v10->start_scr_col;
        LOWORD(start_map_col2) = v10->start_map_col;
        LOWORD(start_map_row2) = v10->start_map_row;
        LOWORD(result) = v10->max_row_num + 6;
        LOWORD(v14) = v10->max_col_num + 4;
        LOWORD(start_scr_row2) = v10->start_scr_row;
        max_col_num2 = v14;
        max_row_num2 = 2 * result;
        cur_col_num = v14;
        direction = 4;
        row_num = 0;
        if( (signed short)(2 * result) > 0 )
        {
            do
            {
                HIWORD(v18) = HIWORD(start_scr_col2);
                HIWORD(v19) = HIWORD(start_map_row2);
                screen_col = start_scr_col2;
                map_col = start_map_col2;
                map_row = start_map_row2;
                col_num = 0;
                if( (signed short)cur_col_num > 0 )
                {
                    do
                    {
                        v18 = (int)map_col;
                        if( (signed short)map_col < 0
                            || (v19 = (int)v10->map, (signed int)(signed short)map_col >= *(_DWORD *)(v19 + 8)) )
                        {
                            v20 = map_row;
                        }
                        else
                        {
                            v20 = map_row;
                            if( map_row >= 0 && (signed int)map_row < *(_DWORD *)(v19 + 12) )
                            {
                                v21 = 1;
                                goto LABEL_32;
                            }
                        }
                        v22 = v10->function_mode;
                        v21 = 0;
                        if( v22 != 40 )
                        {
                            if( v22 != 42 )
                                goto LABEL_139;
                            v18 = (int)map_col;
                            v20 = map_row;
                        }
LABEL_32:
                        if( !v21 )
                            goto LABEL_171;
                        v23 = v10->player->visible;
                        if( !v23 || v10->map->map_visible_flag )
                        {
                            v24 = v20;
                            v25 = (signed short)v18;
                            visible = RGE_Visible_Map::get_visible(v23, (signed short)v18, v20);
                            if( !visible )
                                visible = -128;
                        }
                        else
                        {
                            v24 = v20;
                            v25 = (signed short)v18;
                            v26 = RGE_Visible_Map::get_visible(v23, (signed short)v18, v20);
                            LOBYTE(v19) = v10->function_mode;
                            visible = v26;
                            if( (_BYTE)v19 == 30 || (_BYTE)v19 == 31 )
                                visible = 15;
                        }
                        if( v10->function_mode == 11 )
                        {
                            v18 = (int)&v10->map->map_row_offset[v24]->screen_xpos;
                            v19 = v18 + 24 * v25;
                            if( *(_BYTE *)(v18 + 24 * v25 + 9) == *(_BYTE *)(v19 + 7) )
LABEL_171:
                                visible = 0;
                        }
                        if( visible != 15 && visible != -128 )
                            visible = 0;
                        if( !visible )
                        {
                            v27 = v10->function_mode;
                            if( v27 != 14 && v27 != 40 && v27 != 60 && v27 != 42 )
                                goto LABEL_139;
                        }
                        if( v21 )
                        {
                            v19 = 3 * (signed short)map_col;
                            v18 = (int)&v10->map->map_row_offset[map_row]->screen_xpos;
                            v21 = v18 + 24 * (signed short)map_col;
                            tile_type = *(_BYTE *)(v18 + 24 * (signed short)map_col + 4);
                            tile = (RGE_Tile *)v21;
                            LOBYTE(v19) = *(_BYTE *)(v21 + 5) >> 5;
                        }
                        else
                        {
                            tile = 0;
                            tile_type = 0;
                            LOBYTE(v19) = 0;
                        }
                        LOWORD(v18) = v10->elev_hgt;
                        LOWORD(v19) = (unsigned __int8)v19;
                        v28 = start_scr_row2 - v18 * v19;
                        v19 = tile_type;
                        tile_screen_row = v28;
                        switch( tile_type )
                        {
                            case 2u:
                            case 6u:
                            case 8u:
                            case 0xAu:
                            case 0xEu:
                            case 0xFu:
                            case 0x10u:
                                LOWORD(v28) = v28 - v18;
                                tile_screen_row = v28;
                                break;
                            default:
                                break;
                        }
                        v30 = 1;
                        if( (signed short)screen_col <= v10->render_rect.right )
                        {
                            v18 = v10->render_rect.bottom;
                            v28 = (signed short)v28;
                            if( (signed short)v28 <= v18 )
                            {
                                v29 = v10->map;
                                v18 = (signed short)screen_col + *((_WORD *)&v29->vfptr + 3 * (tile_type + 4));
                                if( v18 > v10->render_rect.left )
                                {
                                    v19 = v28 + v29->tilesizes[tile_type].height;
                                    if( v19 > v10->render_rect.top
                                        && (v10->function_mode != 14
                                         || (signed short)map_col >= calc_sel_col1
                                         && (signed short)map_col <= calc_sel_col2
                                         && map_row >= calc_sel_row1
                                         && map_row <= calc_sel_row2) )
                                    {
                                        v30 = 0;
                                    }
                                }
                            }
                        }
                        v31 = v10->function_mode;
                        if( v31 != 10 && v31 != 30 && v31 != 31 && v31 != 32 && v31 != 21 && v31 != 11 && v31 != 14 )
                        {
                            if( visible != 15 && visible != -128 || v31 != 41 && v31 != 42 && v31 != 43 && v31 != 44 )
                                goto LABEL_88;
                            fog_flag = visible != 15 && (visible != -128 || v10->map->fog_flag) ? 1 : 0;
                            v32 = orig_picked_obj;
                            v33 = RGE_View::hit_object(
                                            v10,
                                            (RGE_Tile *)v21,
                                            screen_col,
                                            start_scr_row2,
                                            (short)map_col,
                                            map_row,
                                            mouse_pos,
                                            start_mouse_pos,
                                            item_scr_x,
                                            item_scr_y,
                                            orig_picked_obj,
                                            fog_flag);
                            if( !v33 )
                                goto LABEL_88;
                            if( v10->function_mode == 44 )
                            {
                                picked_type = 52;
                                goto LABEL_88;
                            }
                            if( v32 && v33 == v32 && picked_type == 52 )
                            {
                                *picked_item = last_picked_obj;
                                return 52;
                            }
                            HIWORD(v19) = HIWORD(last_picked_obj);
                            if( last_picked_obj
                                && (v18 = (int)last_picked_obj->master_obj,
                                        (unsigned __int8)v33->master_obj->select_level < *(_BYTE *)(v18 + 141))
                                && (last_picked_obj != v32 || v33 == v32) )
                            {
LABEL_88:
                                v34 = item_y;
                                v35 = item_x;
                            }
                            else
                            {
                                v35 = item_x;
                                v19 = LODWORD(v33->world_x);
                                v34 = item_y;
                                last_picked_obj = v33;
                                *(_DWORD *)item_x = v19;
                                v18 = LODWORD(v33->world_y);
                                *(_DWORD *)item_y = v18;
                                picked_type = 52;
                            }
                            v36 = v10->function_mode;
                            if( v36 == 40 || v36 == 42 && picked_type == 50 )
                            {
                                if( RGE_View::hit_tile(
                                             v10,
                                             map_col,
                                             (RGE_Tile *)v21,
                                             screen_col,
                                             tile_screen_row,
                                             (short)map_col,
                                             map_row,
                                             mouse_pos) )
                                {
                                    if( v21 )
                                    {
                                        RGE_Map::tile_map_coords(
                                            v10->map,
                                            LOWORD(mouse_pos->x) - screen_col,
                                            LOWORD(mouse_pos->y) - tile_screen_row,
                                            (RGE_Tile *)v21,
                                            v35,
                                            v34);
                                        v19 = (signed short)map_col;
                                        *v35 = (double)(signed short)map_col + *v35;
                                        v37 = (double)map_row + *v34;
                                    }
                                    else
                                    {
                                        v19 = map_row;
                                        *v35 = (double)(signed short)map_col;
                                        v37 = (double)map_row;
                                    }
                                    *v34 = v37;
                                    *item_scr_x = screen_col;
                                    HIWORD(v18) = HIWORD(item_scr_y);
                                    picked_type = 51;
                                    *item_scr_y = tile_screen_row;
                                    *picked_item = (void *)v21;
                                }
                            }
                            else if( v36 == 60 )
                            {
                                HIWORD(v19) = HIWORD(map_col);
                                if( (_WORD)map_col == (_WORD)find_col && map_row == (_WORD)find_row )
                                {
                                    *v35 = (double)(signed short)map_col;
                                    max_row_num2 = map_row;
                                    *v34 = (double)map_row;
                                    *item_scr_x = screen_col;
                                    *item_scr_y = tile_screen_row;
                                    result = 51;
                                    *picked_item = (void *)v21;
                                    return result;
                                }
                            }
                            goto LABEL_139;
                        }
                        if( !v30 )
                        {
                            v38 = v10->function_mode;
                            if( v38 == 10 || v38 == 11 || v38 == 14 )
                            {
                                v39 = v10->map;
                                v40 = *(_BYTE *)(v21 + 5) & 0x1F;
                                LOBYTE(terrain_type) = *(_BYTE *)(v21 + 5) & 0x1F;
                                v18 = terrain_type;
                                v19 = 51 * (unsigned __int8)terrain_type;
                                v41 = v39->terrain_types[(unsigned __int8)terrain_type].terrain_to_draw;
                                if( v41 != -1 )
                                {
                                    v40 = v39->terrain_types[(unsigned __int8)terrain_type].terrain_to_draw;
                                    LOBYTE(terrain_type) = v39->terrain_types[(unsigned __int8)terrain_type].terrain_to_draw;
                                    v18 = terrain_type;
                                }
                                if( v10->function_mode == 10 && v10->calc_draw_count && v40 < v39->num_terrain )
                                {
                                    v18 = (unsigned __int8)v18;
                                    v19 = 51 * (unsigned __int8)v18;
                                    ++v39->terrain_types[v18].drawn;
                                }
                                if( v10->function_mode == 11 )
                                    *(_BYTE *)(v21 + 7) = *(_BYTE *)(v21 + 9);
                            }
                        }
                        if( visible != 15 && visible != -128 )
                            goto LABEL_139;
                        v42 = v10->function_mode;
                        if( v42 != 30 && v42 != 31 && v42 != 32 && v42 != 21 )
                            goto LABEL_139;
                        fog_flaga = visible != 15 && (visible != -128 || (v19 = (int)v10->map, *(_BYTE *)(v19 + 36281)));
                        if( v42 == 30 )
                        {
                            v10->cur_render_area->CurSpanList = v10->Terrain_Fog_Clip_Mask;
                            fog_next_shape = 1;
                            RGE_Object_List::shadow_draw(
                                &tile->objects,
                                v10->cur_render_area,
                                screen_col,
                                start_scr_row2,
                                1,
                                fog_flaga);
                            v10->cur_render_area->CurSpanList = v10->Terrain_Clip_Mask;
                            fog_next_shape = 0;
                            RGE_Object_List::shadow_draw(
                                &tile->objects,
                                v10->cur_render_area,
                                screen_col,
                                start_scr_row2,
                                1,
                                fog_flaga);
                            v43 = v10->cur_render_area;
                            v21 = (int)tile;
                            v18 = (int)v43->SpanList;
                            v43->CurSpanList = (TSpan_List_Manager *)v18;
                        }
                        if( v10->function_mode == 31 )
                        {
                            v10->cur_render_area->CurSpanList = v10->Terrain_Fog_Clip_Mask;
                            fog_next_shape = 1;
                            RGE_Object_List::shadow_draw(
                                &tile->objects,
                                v10->cur_render_area,
                                screen_col,
                                start_scr_row2,
                                10,
                                fog_flaga);
                            v10->cur_render_area->CurSpanList = v10->Terrain_Clip_Mask;
                            fog_next_shape = 0;
                            RGE_Object_List::shadow_draw(
                                &tile->objects,
                                v10->cur_render_area,
                                screen_col,
                                start_scr_row2,
                                10,
                                fog_flaga);
                            v44 = v10->cur_render_area;
                            v21 = (int)tile;
                            v19 = (int)v44->SpanList;
                            v44->CurSpanList = (TSpan_List_Manager *)v19;
                        }
                        v45 = v10->function_mode;
                        if( v45 == 32 )
                        {
                            if( v10->map->fog_flag && visible == -128 )
                                fog_next_shape = 1;
                            RGE_Object_List::shadow_draw(
                                (RGE_Object_List *)(v21 + 12),
                                v10->cur_render_area,
                                screen_col,
                                start_scr_row2,
                                0,
                                fog_flaga);
LABEL_138:
                            fog_next_shape = 0;
                            goto LABEL_139;
                        }
                        if( v45 == 21 )
                        {
                            if( v10->map->fog_flag && visible == -128 )
                                fog_next_shape = 1;
                            RGE_Object_List::normal_draw(
                                (RGE_Object_List *)(v21 + 12),
                                v10->cur_render_area,
                                screen_col,
                                start_scr_row2,
                                fog_flaga);
                            goto LABEL_138;
                        }
LABEL_139:
                        LOWORD(v19) = v10->tile_wid;
                        screen_col += v19;
                        v47 = __OFSUB__(col_num + 1, (_WORD)cur_col_num);
                        v46 = (signed short)(col_num + 1 - cur_col_num) < 0;
                        map_col = (RGE_Tile *)((char *)map_col + 1);
                        ++map_row;
                        ++col_num;
                    }
                    while( v46 ^ v47 );
                }
                if( direction == 1 && (_WORD)cur_col_num == (_WORD)max_col_num2 )
                    direction = 2;
                switch( direction )
                {
                    case 1:
                        LOWORD(start_scr_col2) = start_scr_col2 - v10->tile_half_wid;
                        ++cur_col_num;
                        start_map_col2 = (RGE_Tile *)((char *)start_map_col2 - 1);
                        break;
                    case 2:
                        v18 = cur_col_num-- - 1;
                        LOWORD(v18) = v10->tile_half_wid;
                        start_scr_col2 += v18;
                        ++start_map_row2;
                        break;
                    case 3:
                        direction = 4;
                        LOWORD(start_scr_col2) = start_scr_col2 - v10->tile_half_wid;
                        start_map_col2 = (RGE_Tile *)((char *)start_map_col2 - 1);
                        break;
                    case 4:
                        LOWORD(v19) = v10->tile_half_wid;
                        v18 = v19 + start_scr_col2;
                        start_scr_col2 += v19;
                        ++start_map_row2;
                        direction = 3;
                        break;
                    default:
                        break;
                }
                LOWORD(v18) = v10->tile_half_hgt;
                start_scr_row2 += v18;
                ++row_num;
            }
            while( (signed short)row_num < (signed short)max_row_num2 );
            v16 = picked_item;
        }
        if( v10->function_mode == 10 )
        {
            v48 = v10->map;
            v49 = 0;
            if( v48->num_terrain > 0 )
            {
                do
                {
                    v50 = 17 * (signed short)v49++;
                    v48->terrain_types[24 * v50 / 0x198u].frame_changed = 0;
                    v48 = v10->map;
                }
                while( (signed short)v49 < v48->num_terrain );
            }
        }
        v51 = v10->function_mode;
        if( (v51 == 41 || v51 == 42 || v51 == 43) && picked_type == 52 )
            *v16 = last_picked_obj;
        result = (unsigned __int8)picked_type;
    }
    return result;
}

int Clip_draw;
int Clip_remove;

int RGE_View::view_function_terrain( char function_mode_in, RECT save_render_rect )
{
    RGE_View *v3; // ebp@1
    int v4; // ebx@1
    int v5; // edx@3
    int v6; // ecx@3
    int v7; // esi@3
    RGE_Map *v8; // eax@3
    int v9; // edx@3
    RGE_Map *v10; // eax@3
    signed int v11; // ecx@3
    int v12; // edx@4
    RGE_Player *v13; // eax@6
    unsigned int v14; // ecx@6
    unsigned int v15; // edx@6
    DClipInfo_List *v16; // eax@6
    DClipInfo_List *v17; // ecx@6
    RGE_Map *v18; // edx@7
    int v19; // edi@10
    int v20; // esi@13
    RGE_Map *v21; // eax@21
    RGE_Tile *v22; // ecx@21
    int v23; // esi@21
    int v24; // ebx@21
    unsigned __int32 *v25; // ecx@21
    char v26; // al@34
    int v27; // eax@52
    int v28; // eax@61
    VSpanMiniList **v29; // edi@61
    RGE_Map *v30; // ecx@61
    int v31; // eax@62
    VSpanMiniList *v32; // eax@74
    int v33; // ecx@74
    VSpanMiniList *v34; // edx@75
    int v35; // eax@80
    short v36; // di@98
    short v37; // ax@108
    char v38; // dl@110
    char v39; // cl@110
    int v40; // edx@110
    int v41; // eax@110
    short v42; // ax@113
    int v43; // eax@116
    bool v44; // sf@124
    unsigned __int8 v45; // of@124
    int v46; // eax@136
    int v47; // eax@143
    Ov_Sprite_Draw_Rec *v48; // esi@143
    char v49; // bl@144
    unsigned int v50; // ecx@145
    int v51; // eax@147
    unsigned int v52; // edi@149
    TShape *v53; // ecx@150
    int v54; // eax@151
    unsigned int v55; // eax@153
    int v56; // ecx@155
    Ov_Sprite_Draw_Rec **v57; // eax@157
    Ov_Sprite_Draw_Rec *v58; // edi@163
    int v59; // edi@168
    DClipInfo_List *v60; // eax@168
    DClipInfo_Node *i; // eax@169
    DClipInfo_List *v62; // edx@170
    int v63; // ecx@170
    DClipInfo_Node *v64; // esi@170
    signed int v65; // ebx@175
    DClipInfo_Node *j; // esi@177
    TSpan_List_Manager *v67; // eax@179
    Shape_Info *v68; // edi@179
    TSpan_List_Manager *v69; // eax@179
    TMousePointer *v70; // ecx@182
    unsigned int v71; // esi@187
    bool v72; // zf@188
    int v73; // eax@188
    int v74; // eax@189
    int v75; // ecx@191
    RGE_PlayerVtbl **v76; // ecx@192
    RGE_PlayerVtbl *v77; // edx@192
    TMessagePanel *v78; // ecx@196
    PanelNode *k; // ebx@203
    TPanel *v80; // edi@204
    int v81; // edx@206
    int v82; // eax@206
    DClipInfo_Node *v83; // eax@210
    DClipInfo_List *v84; // ecx@211
    int v85; // edx@211
    TDrawArea *v86; // eax@217
    int n; // esi@217
    int l; // esi@222
    int m; // esi@226
    DClipInfo_List *v90; // eax@228
    int v91; // ecx@228
    DClipInfo_Node **v92; // eax@229
    DClipInfo_Node *v93; // esi@229
    DClipInfo_Node *v94; // edx@231
    int v95; // ecx@231
    int v96; // eax@231
    unsigned int v97; // eax@231
    DClipInfo_Node **v98; // eax@244
    DClipInfo_Node *v99; // esi@244
    int v100; // eax@246
    DClipInfo_Node *v101; // edx@247
    int v102; // ecx@247
    unsigned int v103; // eax@247
    TSpan_List_Manager *v104; // edx@261
    TDrawArea *v105; // ecx@261
    TSpan_List_Manager *v106; // eax@261
    signed int v107; // eax@261
    int v108; // esi@262
    signed int v109; // ebx@264
    int v110; // edi@264
    TDrawArea *v111; // ecx@278
    int v112; // esi@278
    __int32 ii; // edi@278
    int v114; // edi@281
    short v115; // bx@282
    char v116; // al@282
    int v117; // esi@282
    DClipInfo_List *v118; // edx@286
    char v120; // [sp+13h] [bp-10Dh]@142
    char y; // [sp+14h] [bp-10Ch]@108
    char ya; // [sp+14h] [bp-10Ch]@113
    int yb; // [sp+14h] [bp-10Ch]@228
    char yc; // [sp+14h] [bp-10Ch]@281
    DClipInfo_Node *LDI; // [sp+18h] [bp-108h]@6
    DClipInfo_Node *LDIa; // [sp+18h] [bp-108h]@229
    DClipInfo_Node *LDIb; // [sp+18h] [bp-108h]@244
    char MapVis; // [sp+1Ch] [bp-104h]@22
    int map_row; // [sp+20h] [bp-100h]@10
    int screen_row; // [sp+24h] [bp-FCh]@21
    int newFacet; // [sp+28h] [bp-F8h]@9
    int text_id; // [sp+2Ch] [bp-F4h]@3
    int black_tile_mask_num; // [sp+30h] [bp-F0h]@34
    int screen_row2; // [sp+34h] [bp-ECh]@21
    int tile_mask_num; // [sp+38h] [bp-E8h]@34
    VSpanMiniList *black_draw_data; // [sp+3Ch] [bp-E4h]@21
    int fog_draw; // [sp+40h] [bp-E0h]@75
    int clip_to; // [sp+44h] [bp-DCh]@34
    int Map_Width; // [sp+48h] [bp-D8h]@3
    int map_col; // [sp+4Ch] [bp-D4h]@10
    int Map_Height; // [sp+50h] [bp-D0h]@3
    int black_draw; // [sp+54h] [bp-CCh]@61
    int rect2; // [sp+58h] [bp-C8h]@34
    int Full_Visibility; // [sp+5Ch] [bp-C4h]@7
    unsigned int TileVisibleMask; // [sp+60h] [bp-C0h]@6
    VSpanMiniList *fog_draw_data; // [sp+64h] [bp-BCh]@74
    int start_map_x; // [sp+68h] [bp-B8h]@3
    int col_num; // [sp+6Ch] [bp-B4h]@16
    VSpanMiniList *normal_draw_data; // [sp+70h] [bp-B0h]@74
    int cols_2_scan; // [sp+74h] [bp-ACh]@3
    unsigned int TileFoggedMask; // [sp+78h] [bp-A8h]@6
    int v152; // [sp+7Ch] [bp-A4h]@13
    int rows_2_scan; // [sp+80h] [bp-A0h]@3
    int theObj; // [sp+84h] [bp-9Ch]@188
    POINT CPoint; // [sp+88h] [bp-98h]@187
    RECT panel_rect; // [sp+90h] [bp-90h]@206
    char pText[128]; // [sp+A0h] [bp-80h]@195

    v3 = this;
    v4 = 0;
    if( this->DispSel_List_Size > 0 )
        RGE_View::update_display_selected_objects(this);
    v5 = this->max_row_num;
    v6 = this->start_map_row;
    start_map_x = this->start_map_col;
    text_id = v6;
    v7 = 2 * v5 + 12;
    cols_2_scan = this->max_col_num + 5;
    v8 = this->map;
    rows_2_scan = 2 * v5 + 12;
    v9 = v8->map_height;
    Map_Width = v8->map_width;
    this->function_mode = function_mode_in;
    v10 = this->map;
    v11 = 0;
    Map_Height = v9;
    if( v10->num_terrain > 0 )
    {
        v12 = 0;
        do
        {
            v10->terrain_types[v12].drawn = 0;
            v10 = this->map;
            ++v11;
            ++v12;
        }
        while( v11 < v10->num_terrain );
    }
    v13 = this->player;
    v14 = v13->mutualExploredMask;
    v15 = v13->mutualVisibleMask;
    v16 = this->futur_objs;
    TileFoggedMask = v14;
    SDI_List = v16;
    v17 = this->futur_objs;
    TileVisibleMask = v15;
    DClipInfo_List::ReclaimAllNodes(v17);
    LDI = (DClipInfo_Node *)-1;
    if( !this->player->visible || (v18 = this->map, Full_Visibility = 0, v18->map_visible_flag) )
        Full_Visibility = 1;
    newFacet = 0;
    if( v7 > 0 )
    {
        while( 1 )
        {
            v19 = start_map_x;
            map_col = start_map_x;
            map_row = text_id;
            if( (v4 & 3) == 3 && MouseSystem )
                TMousePointer::Poll(MouseSystem);
            v20 = v4 & 1;
            v152 = v4 & 1;
            if( v20 == 1 && this->Queued_Blits )
                RGE_View::ProcessQueuedBlit(v3, 0);
            col_num = 0;
            if( cols_2_scan > 0 )
                break;
LABEL_126:
            if( v20 == 1 )
                ++text_id;
            else
                --start_map_x;
            newFacet = ++v4;
            if( v4 >= rows_2_scan )
                goto LABEL_130;
        }
        while( 1 )
        {
            if( map_row >= 0 && v19 >= 0 )
            {
                if( map_row < Map_Height && v19 < Map_Width )
                {
                    v21 = this->map;
                    v22 = v21->map_row_offset[map_row];
                    v23 = (int)&v22[v19].screen_xpos;
                    v24 = v22[v19].screen_xpos - this->map_scr_x_offset;
                    screen_row = *(_WORD *)(v23 + 2) - this->map_scr_y_offset;
                    black_draw_data = (VSpanMiniList *)(v24 + this->tile_wid);
                    screen_row2 = screen_row + v21->tilesizes[*(_BYTE *)(v23 + 4)].height;
                    v25 = (&unified_map_offsets)[map_row][v19];
                    if( TileVisibleMask & (unsigned int)v25 )
                    {
                        MapVis = 15;
LABEL_27:
                        if( v24 <= this->render_rect.right
                            && screen_row <= this->render_rect.bottom
                            && (signed int)black_draw_data > this->render_rect.left
                            && screen_row2 > this->render_rect.top )
                        {
                            if( this->calc_draw_count && (*(_BYTE *)(v23 + 5) & 0x1F) < v21->num_terrain )
                                ++v21->terrain_types[*(_BYTE *)(v23 + 5) & 0x1F].drawn;
                            tile_mask_num = -1;
                            black_tile_mask_num = -1;
                            v26 = this->render_terrain_mode;
                            clip_to = 0;
                            rect2 = 0;
                            if( v26
                                && *(_BYTE *)(v23 + 7) == MapVis
                                && (MapVis != 15
                                 || (this->map->fog_flag ? (tile_mask_num = RGE_View::get_tile_mask_num(
                                                                                                                        v3,
                                                                                                                        v19,
                                                                                                                        map_row,
                                                                                                                        Map_Width,
                                                                                                                        Map_Height,
                                                                                                                        TileVisibleMask)) : (tile_mask_num = 0),
                                         *(_BYTE *)(v23 + 8) == tile_mask_num))
                                && (MapVis != 15 && MapVis != -128
                                 || (!Full_Visibility ? (black_tile_mask_num = RGE_View::get_tile_mask_num(
                                                                                                                                 v3,
                                                                                                                                 v19,
                                                                                                                                 map_row,
                                                                                                                                 Map_Width,
                                                                                                                                 Map_Height,
                                                                                                                                 TileFoggedMask)) : (black_tile_mask_num = 0),
                                         *(_BYTE *)(v23 + 11) == black_tile_mask_num)) )
                            {
                                if( this->Limited_Render_Rect )
                                {
                                    if( this->Use_Rect2 )
                                    {
                                        if( v24 > this->Render_Rect2.right
                                            || (signed int)black_draw_data < this->Render_Rect2.left
                                            || screen_row > this->Render_Rect2.bottom
                                            || (v27 = this->Render_Rect2.top, rect2 = 1, screen_row2 < v27) )
                                        {
                                            rect2 = 0;
                                        }
                                    }
                                    if( v24 <= this->Render_Rect1.right
                                        && (signed int)black_draw_data >= this->Render_Rect1.left
                                        && screen_row <= this->Render_Rect1.bottom
                                        && screen_row2 >= this->Render_Rect1.top )
                                    {
                                        clip_to = 1;
                                        goto draw_this_tile;
                                    }
                                    if( rect2 )
                                    {
                                        rect2 = 0;
                                        clip_to = 2;
                                        goto draw_this_tile;
                                    }
                                }
                            }
                            else
                            {
draw_this_tile:
                                v28 = *(_BYTE *)(v23 + 4);
                                v29 = &this->Tile_Edge_Tables[v28]->normal_draw;
                                v30 = this->map;
                                black_draw = (int)this->Black_Edge_Tables[v28];
                                if( v30->fog_flag )
                                {
                                    v31 = 0;
                                }
                                else
                                {
                                    v31 = 0;
                                    tile_mask_num = 0;
                                }
                                if( Full_Visibility )
                                    black_tile_mask_num = 0;
                                if( tile_mask_num == -1 )
                                {
                                    if( MapVis == 15 )
                                    {
                                        tile_mask_num = RGE_View::get_tile_mask_num(
                                                                            v3,
                                                                            map_col,
                                                                            map_row,
                                                                            Map_Width,
                                                                            Map_Height,
                                                                            TileVisibleMask);
                                        v31 = 0;
                                    }
                                    else
                                    {
                                        tile_mask_num = 0;
                                    }
                                }
                                if( black_tile_mask_num == -1 )
                                {
                                    if( MapVis )
                                        v31 = RGE_View::get_tile_mask_num(v3, map_col, map_row, Map_Width, Map_Height, TileFoggedMask);
                                    black_tile_mask_num = v31;
                                }
                                v32 = v29[2 * tile_mask_num + 1];
                                normal_draw_data = v29[2 * tile_mask_num];
                                fog_draw_data = v32;
                                v33 = *(_DWORD *)(black_draw + 4 * black_tile_mask_num);
                                black_draw_data = *(VSpanMiniList **)(black_draw + 4 * black_tile_mask_num);
                                if( MapVis == -128 )
                                {
                                    v34 = *v29;
                                    fog_draw = 1;
                                    screen_row2 = 0;
                                    fog_draw_data = v34;
                                }
                                else
                                {
                                    screen_row2 = normal_draw_data != 0;
                                    fog_draw = v32 != 0;
                                }
                                if( black_tile_mask_num <= 0 || (black_draw = 1, !v33) )
                                    black_draw = 0;
                                v35 = clip_to;
                                if( (DClipInfo_Node *)clip_to != LDI )
                                {
                                    if( !clip_to )
                                    {
                                        TSpan_List_Manager::SetSpanRegions(
                                            this->Terrain_Clip_Mask,
                                            this->render_rect.left,
                                            this->render_rect.top,
                                            this->render_rect.right,
                                            this->render_rect.bottom);
                                        TSpan_List_Manager::SetSpanRegions(
                                            this->Terrain_Fog_Clip_Mask,
                                            this->render_rect.left,
                                            this->render_rect.top,
                                            this->render_rect.right,
                                            this->render_rect.bottom);
                                        v35 = 0;
                                    }
                                    if( v35 == 1 )
                                    {
                                        TSpan_List_Manager::SetSpanRegions(
                                            this->Terrain_Clip_Mask,
                                            this->Render_Rect1.left,
                                            this->Render_Rect1.top,
                                            this->Render_Rect1.right,
                                            this->Render_Rect1.bottom);
                                        TSpan_List_Manager::SetSpanRegions(
                                            this->Terrain_Fog_Clip_Mask,
                                            this->Render_Rect1.left,
                                            this->Render_Rect1.top,
                                            this->Render_Rect1.right,
                                            this->Render_Rect1.bottom);
                                        v35 = clip_to;
                                    }
                                    if( v35 == 2 )
                                    {
                                        TSpan_List_Manager::SetSpanRegions(
                                            this->Terrain_Clip_Mask,
                                            this->Render_Rect2.left,
                                            this->Render_Rect2.top,
                                            this->Render_Rect2.right,
                                            this->Render_Rect2.bottom);
                                        TSpan_List_Manager::SetSpanRegions(
                                            this->Terrain_Fog_Clip_Mask,
                                            this->Render_Rect2.left,
                                            this->Render_Rect2.top,
                                            this->Render_Rect2.right,
                                            this->Render_Rect2.bottom);
                                        v35 = clip_to;
                                    }
                                    LDI = (DClipInfo_Node *)v35;
                                }
                                if( screen_row2 )
                                    TSpan_List_Manager::AddMiniList(this->Terrain_Clip_Mask, normal_draw_data, v24, screen_row);
                                if( fog_draw )
                                    TSpan_List_Manager::AddMiniList(this->Terrain_Fog_Clip_Mask, fog_draw_data, v24, screen_row);
                                if( black_draw )
                                {
                                    if( screen_row2 )
                                        TSpan_List_Manager::SubtractMiniList(this->Terrain_Clip_Mask, black_draw_data, v24, screen_row);
                                    if( fog_draw )
                                        TSpan_List_Manager::SubtractMiniList(this->Terrain_Fog_Clip_Mask, black_draw_data, v24, screen_row);
                                }
                                if( rect2 )
                                {
                                    TSpan_List_Manager::SetSpanRegions(
                                        this->Terrain_Clip_Mask,
                                        this->Render_Rect2.left,
                                        this->Render_Rect2.top,
                                        this->Render_Rect2.right,
                                        this->Render_Rect2.bottom);
                                    TSpan_List_Manager::SetSpanRegions(
                                        this->Terrain_Fog_Clip_Mask,
                                        this->Render_Rect2.left,
                                        this->Render_Rect2.top,
                                        this->Render_Rect2.right,
                                        this->Render_Rect2.bottom);
                                    v36 = screen_row;
                                    LDI = (DClipInfo_Node *)2;
                                    if( screen_row2 )
                                        TSpan_List_Manager::AddMiniList(this->Terrain_Clip_Mask, normal_draw_data, v24, screen_row);
                                    if( fog_draw )
                                        TSpan_List_Manager::AddMiniList(this->Terrain_Fog_Clip_Mask, fog_draw_data, v24, screen_row);
                                    if( black_draw )
                                    {
                                        if( screen_row2 )
                                            TSpan_List_Manager::SubtractMiniList(this->Terrain_Clip_Mask, black_draw_data, v24, screen_row);
                                        if( fog_draw )
                                            TSpan_List_Manager::SubtractMiniList(this->Terrain_Fog_Clip_Mask, black_draw_data, v24, screen_row);
                                    }
                                }
                                else
                                {
                                    v36 = screen_row;
                                }
                                y = *(_BYTE *)(v23 + 5) & 0x1F;
                                v37 = this->map->terrain_types[(unsigned __int8)y].terrain_to_draw;
                                if( v37 != -1 )
                                    y = this->map->terrain_types[(unsigned __int8)y].terrain_to_draw;
                                v38 = tile_mask_num;
                                *(_BYTE *)(v23 + 11) = black_tile_mask_num;
                                v39 = *(_BYTE *)(v23 + 10);
                                *(_BYTE *)(v23 + 8) = v38;
                                v40 = fog_draw;
                                *(_BYTE *)(v23 + 7) = MapVis;
                                *(_BYTE *)(v23 + 9) = MapVis;
                                v41 = screen_row2;
                                *(_BYTE *)(v23 + 10) = v39 & 0xBF;
                                RGE_View::draw_tile(v3, (RGE_Tile *)v23, y, v24, v36, map_col, map_row, MapVis, v41, v40);
                                v19 = map_col;
                                ++tiles_drawn;
                            }
                        }
                    }
                    else
                    {
                        if( (unsigned int)v25 & TileFoggedMask || Full_Visibility )
                        {
                            MapVis = v21->fog_flag != 0 ? -128 : 15;
                            goto LABEL_27;
                        }
                        MapVis = 0;
                        *(_BYTE *)(v23 + 7) = 0;
                    }
                    if( v23 && (*(_BYTE *)(v23 + 10) & 0x40) == 64 )
                    {
                        ya = *(_BYTE *)(v23 + 5) & 0x1F;
                        v42 = this->map->terrain_types[(unsigned __int8)ya].terrain_to_draw;
                        if( v42 != -1 )
                            ya = this->map->terrain_types[(unsigned __int8)ya].terrain_to_draw;
                        RGE_View::draw_tile(v3, (RGE_Tile *)v23, ya, v24, screen_row, v19, map_row, MapVis, 1, 1);
                        *(_BYTE *)(v23 + 10) &= 0xBFu;
                    }
                    HIWORD(v43) = HIWORD(view_debug_Objects);
                    if( !view_debug_Objects && v23 )
                    {
                        SDI_Capture_Info = 1;
                        if( !MapVis )
                            DClipInfo_List::SetCaptureLevel(this->futur_objs, 0, 5);
                        if( MapVis != 15 )
                            fog_next_shape = 1;
                        LOWORD(v43) = this->tile_half_hgt * (unsigned __int8)(*(_BYTE *)(v23 + 5) >> 5);
                        RGE_Object_List::draw((RGE_Object_List *)(v23 + 12), this->save_area1, v24, screen_row + v43, MapVis == -128);
                        DClipInfo_List::SetCaptureLevel(this->futur_objs, 0, 40);
                        fog_next_shape = 0;
                        SDI_Capture_Info = 0;
                    }
                    goto SkipCol;
                }
                col_num = cols_2_scan;
            }
            SkipCol:
            ++v19;
            v45 = __OFSUB__(col_num + 1, cols_2_scan);
            v44 = col_num + 1 - cols_2_scan < 0;
            map_col = v19;
            ++map_row;
            ++col_num;
            if( !(v44 ^ v45) )
            {
                v20 = v152;
                v4 = newFacet;
                goto LABEL_126;
            }
        }
    }

    LABEL_130:
    while( this->Queued_Blits ){
        this->ProcessQueuedBlit(1);
    }

    if( MouseSystem ){
        MouseSystem->Poll();
    }

    this->render_rect.left   += save_render_rect.left;
    this->render_rect.top    += save_render_rect.top;
    this->render_rect.right  += save_render_rect.left;
    this->render_rect.bottom += save_render_rect.top;

    SDI_Capture_Info = 1;

    if( this->scroll_action == 2 ){

        this->futur_objs->AddGDINode(
            4,
            20,
            this->mouse_down_x - save_render_rect.left,
            this->mouse_down_y - save_render_rect.top,
            this->mouse_last_x - save_render_rect.left,
            this->mouse_last_y - save_render_rect.top,
            0,
            0,
            0,
            0,
            40,
            255,
            0);
    }

    if( rge_base_game->game_mode == 1 ||
        rge_base_game->game_mode > 6 &&
        rge_base_game->game_mode <= 8 ){
        this->draw_object_outline();
    }
    if( rge_base_game->game_mode == 21 ){
        (*(void (**)(RGE_View *))&this->vfptr[1].gap10[8])();
    }
    v120 = 0;

    if( this->extra_sprites ){

        v48 = this->extra_sprites;
        newFacet = debug_timeGetTime();
        while( v48 ){
            v49 = 0;
            if( v48->theShape )
            {
                v50 = v48->LastDrawTime;
                if( v50 )
                {
                    v51 = v48->displayfunction;
                    if( v51 == 1 || v51 == 2 )
                    {
                        v52 = newFacet - v50;
                        if( newFacet - v50 >= v48->DrawTimeInterval )
                        {
                            do
                            {
                                v53 = v48->theShape;
                                if( ++v48->thefacet >= TShape::shape_count(v53) )
                                {
                                    v54 = v48->displayfunction;
                                    v48->thefacet = 0;
                                    if( v54 == 2 )
                                    {
                                        v49 = 1;
                                        v120 = 1;
                                    }
                                }
                                v55 = v48->DrawTimeInterval;
                                v52 -= v55;
                                v48->LastDrawTime += v55;
                            }
                            while( v52 >= v55 );
                        }
                    }
                }
                else
                {
                    v48->LastDrawTime = newFacet;
                }
                if( v49 )
                {
LABEL_157:
                    v57 = &v48->prev->next;
                    if( v57 )
                        *v57 = v48->next;
                    if( v48->next )
                        v48->next->prev = v48->prev;
                    if( !v48->prev )
                        this->extra_sprites = v48->next;
                    v58 = v48->next;
                    operator delete(v48);
                    v48 = v58;
                    continue;
                }
                v56 = v48->drawLevel;
                SDI_Object_ID = -1;
                SDI_Draw_Level = v56;
                v48->theShape->shape_draw(
                    this->render_area,
                    v48->world_x - this->map_scr_x_offset,
                    v48->world_y - this->map_scr_y_offset,
                    v48->thefacet,
                    v48->flags,
                    v48->colortable);
            }
            if( v49 )
                goto LABEL_157;
            v48 = v48->next;
        }
    }

    if( v120 ){
        this->reset_cyclic_overlay_sprites();
    }

    v59 = 0;

    SDI_Capture_Info = 0;

    this->render_rect.left   -= save_render_rect.left;
    this->render_rect.top    -= save_render_rect.top;
    this->render_rect.right  -= save_render_rect.left;
    this->render_rect.bottom -= save_render_rect.top;

    v60 = this->futur_objs;
    if( v60->YLine_Size > 0 )
    {
        do
        {
            for( i = v60->Draw_Clip_Nodes[v59]; i; i = i->Next )
            {
                v62 = this->futur_objs;
                v63 = i->Draw_Level;
                v64 = v62->Draw_Level_Tail[v63];
                if( v64 )
                    v64->NextOnLevel = i;
                else
                    v62->Draw_Level_Head[v63] = i;
                this->futur_objs->Draw_Level_Tail[v63] = i;
            }
            v60 = this->futur_objs;
            ++v59;
        }
        while( v59 < v60->YLine_Size );
    }

    Clip_draw   = 0;
    Clip_remove = 0;

    if( LDI ){

        this->Terrain_Clip_Mask->SetSpanRegions(
            this->render_rect.left,
            this->render_rect.top,
            this->render_rect.right,
            this->render_rect.bottom);

        this->Terrain_Fog_Clip_Mask->SetSpanRegions(
            this->render_rect.left,
            this->render_rect.top,
            this->render_rect.right,
            this->render_rect.bottom);
    }

    v65 = 0;
    do{
        for( j = this->futur_objs->Draw_Level_Head[v65]; j; j = j->NextOnLevel ){
            if( !j->Node_Type ){

                ASMSet_Surface_Info(
                    this->save_area1->CurDisplayOffsets,
                    this->Terrain_Clip_Mask->Line_Head_Ptrs,
                    this->Terrain_Clip_Mask->Line_Tail_Ptrs,
                    this->Terrain_Clip_Mask->Min_Span_Px,
                    this->Terrain_Clip_Mask->Min_Line,
                    this->Terrain_Clip_Mask->Max_Span_Px,
                    this->Terrain_Clip_Mask->Max_Line);

                ASMSet_Color_Xform(
                    j->Xform_Mask);

                ASMSet_Xlate_Table(
                    j->Color_Table);

                v68 = j->Shape;
                ASMDraw_Sprite(
                    j->Shape_Base,
                    j->Draw_X,
                    j->Draw_Y,
                    j->Shape->Width,
                    j->Shape->Height,
                    j->Shape->Shape_Data_Offsets,
                    j->Shape->Shape_Outline_Offset,
                    j->Draw_Flag & 0xFE);

                v69 = this->Terrain_Fog_Clip_Mask;
                ASMSet_Surface_Info(
                    this->save_area1->CurDisplayOffsets,
                    this->Terrain_Fog_Clip_Mask->Line_Head_Ptrs,
                    this->Terrain_Fog_Clip_Mask->Line_Tail_Ptrs,
                    this->Terrain_Fog_Clip_Mask->Min_Span_Px,
                    this->Terrain_Fog_Clip_Mask->Min_Line,
                    this->Terrain_Fog_Clip_Mask->Max_Span_Px,
                    this->Terrain_Fog_Clip_Mask->Max_Line);

                ASMDraw_Sprite(
                    j->Shape_Base,
                    j->Draw_X,
                    j->Draw_Y,
                    j->Shape->Width,
                    j->Shape->Height,
                    j->Shape->Shape_Data_Offsets,
                    j->Shape->Shape_Outline_Offset,
                    j->Draw_Flag | 1);
            }
        }
        ++v65;
    }
    while( v65 <= 5 );

    if( MouseSystem ){
        MouseSystem->Poll();
    }

    if( rge_base_game->prog_mode == 4 &&
        this->have_focus &&
        MouseSystem->get_game_enable() ){

        v71 = debug_timeGetTime();
        if( RGE_View::Get_Cursor_Position(v3, &CPoint, -save_render_rect.left, -save_render_rect.top) )
        {
            v72 = RGE_View::pick_touched_object(v3, this->futur_objs, CPoint.x, CPoint.y, 10, 40, &theObj) == 1;
            v73 = this->UC_ObjectTouched;
            if( v72 )
            {
                v72 = v73 == 0;
                v74 = theObj;
                if( !v72 && this->UC_TouchedObj == theObj )
                    goto no_mouse_process;
                v75 = this->UC_TouchedObj;
                this->UC_ObjectTouched = 1;
                if( v75 == v74 )
                    goto no_mouse_process;
                v76 = &this->player->vfptr;
                this->UC_StartTime = v71;
                this->UC_TouchedObj = v74;
                v77 = *v76;
                newFacet = 0;
                text_id = 0;
                if( ((int (__stdcall *)(int, int *, int *))v77->get_mouse_pointer_action_vars)(v74, &newFacet, &text_id) == 1 )
                {
                    TMousePointer::set_game_facet(MouseSystem, newFacet);
                    if( this->message_panel && rge_base_game->rollover )
                    {
                        TPanel::get_string(text_id, pText, 127);
                        TMessagePanel::show_message(this->message_panel, 0, pText, 112, 0, 0, 0, 0);
                    }
                    goto no_mouse_process;
                }
                TMousePointer::set_game_facet(MouseSystem, 0);
                v78 = this->message_panel;
                if( !v78 || !rge_base_game->rollover )
                    goto no_mouse_process;
            }
            else
            {
                if( !v73 )
                    goto no_mouse_process;
                this->UC_ObjectTouched = 0;
                this->UC_TouchedObj = 2147483648;
                TMousePointer::set_game_facet(MouseSystem, 0);
                v78 = this->message_panel;
                if( !v78 || !rge_base_game->rollover )
                    goto no_mouse_process;
            }
            TMessagePanel::remove_message(v78);
            goto no_mouse_process;
        }
    }

    no_mouse_process:
    for( k = this->first_child_node; k; k = k->next_node )
    {
        v80 = k->panel;
        if( k->panel->active && v80->need_redraw )
        {
            v80->vfptr->get_true_render_rect(v80, &panel_rect);
            v81 = panel_rect.top - save_render_rect.top;
            v82 = panel_rect.left - save_render_rect.left;
            if( panel_rect.left - save_render_rect.left < 0 )
                v82 = 0;
            if( v81 < 0 )
                v81 = 0;
            v83 = DClipInfo_List::AddGDINode(
                            this->futur_objs,
                            3,
                            panel_rect.bottom - save_render_rect.top,
                            v82,
                            v81,
                            panel_rect.right - save_render_rect.left,
                            panel_rect.bottom - save_render_rect.top,
                            0,
                            0,
                            0,
                            0,
                            30,
                            v80->display_changed_count,
                            0);
            if( v83 )
            {
                v84 = this->futur_objs;
                v85 = *((_DWORD *)v84->Draw_Level_Tail + 30);
                if( v85 )
                    *(_DWORD *)(v85 + 4) = v83;
                else
                    *((_DWORD *)v84->Draw_Level_Head + 30) = v83;
                *((_DWORD *)this->futur_objs->Draw_Level_Tail + 30) = v83;
            }
        }
    }

    if( this->render_terrain_mode ){

        this->Master_Clip_Mask->Merge_n_Align(this->Terrain_Clip_Mask, this->Terrain_Fog_Clip_Mask);

        if( this->Limited_Render_Rect ){

            if( this->Render_Rect1.left >= 0 ){
                for( l = this->Render_Rect1.top; l <= this->Render_Rect1.bottom; ++l )
                    TSpan_List_Manager::AddSpan(this->Master_Clip_Mask, this->Render_Rect1.left, this->Render_Rect1.right, l);
            }
            if( this->Use_Rect2 ){
                if( this->Render_Rect2.left >= 0 )
                {
                    for( m = this->Render_Rect2.top; m <= this->Render_Rect2.bottom; ++m )
                        TSpan_List_Manager::AddSpan(this->Master_Clip_Mask, this->Render_Rect2.left, this->Render_Rect2.right, m);
                }
            }
        }
        v90 = this->futur_objs;
        v91 = 0;
        for( yb = 0; v91 < v90->YLine_Size; yb = v91 )
        {
            v92 = v90->Draw_Clip_Nodes;
            v93 = v92[v91];
            for( LDIa = v92[v91]; v93; LDIa = v93 )
            {
                if( v93->Draw_Level > 5 )
                {
                    v94 = this->prior_objs->Draw_Clip_Nodes[v91];
                    v95 = 1;
                    v96 = v93->Node_Type != 0 ? 0x10 : 0;
                    text_id = 1;
                    v97 = v96 + 36;
                    if( v94 )
                    {
                        while( memcmp(&v93->Shape, &v94->Shape, v97) )
                        {
                            v94 = v94->Next;
                            if( !v94 )
                            {
                                v95 = text_id;
                                goto LABEL_238;
                            }
                            v93 = LDIa;
                        }
                        v95 = 0;
                        ++Clip_remove;
                        v94->Node_Type = -1;
LABEL_238:
                        v93 = LDIa;
                    }
                    if( v95 )
                    {
                        if( v93->Node_Type )
                        {
                            RGE_View::Add_GDI_Clip_Mask(v93, this->Master_Clip_Mask);
                        }
                        else
                        {
                            TSpan_List_Manager::AddShape_Align(
                                this->Master_Clip_Mask,
                                v93->Shape_Base,
                                v93->Shape,
                                v93->Draw_X,
                                v93->Draw_Y,
                                (v93->Draw_Flag & 2) == 2);
                            ++Clip_draw;
                        }
                    }
                }
                v93 = v93->Next;
                v91 = yb;
            }
            v98 = this->prior_objs->Draw_Clip_Nodes;
            v99 = v98[v91];
            for( LDIb = v98[v91]; v99; LDIb = v99 )
            {
                if( v99->Draw_Level > 5 )
                {
                    v100 = v99->Node_Type;
                    if( v100 != -1 )
                    {
                        v101 = this->futur_objs->Draw_Clip_Nodes[v91];
                        v102 = 1;
                        v103 = v100 != 0 ? 52 : 36;
                        text_id = 1;
                        if( v101 )
                        {
                            while( memcmp(&v101->Shape, &v99->Shape, v103) )
                            {
                                v101 = v101->Next;
                                if( !v101 )
                                {
                                    v102 = text_id;
                                    goto LABEL_254;
                                }
                                v99 = LDIb;
                            }
                            v102 = 0;
LABEL_254:
                            v99 = LDIb;
                        }
                        if( v102 ){
                            if( v99->Node_Type ){
                                v99->Add_GDI_Clip_Mask(this->Master_Clip_Mask);
                            }else{
                                this->Master_Clip_Mask->AddShape_Align(
                                    v99->Shape_Base,
                                    v99->Shape,
                                    v99->Draw_X,
                                    v99->Draw_Y,
                                    (v99->Draw_Flag & 2) == 2);

                                Clip_draw++;
                            }
                        }
                    }
                }
                v99 = v99->Next;
                v91 = yb;
            }
            v90 = this->futur_objs;
            ++v91;
        }
    }else{
        for( n = 0; n < this->save_area1->Height; n++ ){

            this->Master_Clip_Mask->AddSpan(0, this->save_area1->Width - 1, n);
        }
        this->prior_objs->ReclaimAllNodes();
    }

    this->render_rect.left   += save_render_rect.left;
    this->render_rect.top    += save_render_rect.top;
    this->render_rect.right  += save_render_rect.left;
    this->render_rect.bottom += save_render_rect.top;

    this->save_area1->PtrSpanCopy(
        this->render_area,
        this->render_rect.left,
        this->render_rect.top,
        &this->save_area1->ClipRect,
        (char **)this->Master_Clip_Mask->Line_Head_Ptrs);

    this->Update_Render_Pointers();

    this->render_rect.left   -= save_render_rect.left;
    this->render_rect.top    -= save_render_rect.top;
    this->render_rect.right  -= save_render_rect.left;
    this->render_rect.bottom -= save_render_rect.top;

    ASMSet_Surface_Info(
        this->RenderOffsets,
        this->Master_Clip_Mask->Line_Head_Ptrs,
        this->Master_Clip_Mask->Line_Tail_Ptrs,
        this->Master_Clip_Mask->Min_Span_Px,
        this->Master_Clip_Mask->Min_Line,
        this->Master_Clip_Mask->Max_Span_Px,
        this->Master_Clip_Mask->Max_Line);

    this->render_area->CurSpanList = this->Master_Clip_Mask;

    v107 = 24;
    newFacet = 24;
    do{
        if( v108 = *(int *)((char *)this->futur_objs->Draw_Level_Head + v107) ){
            do{
                if( *(_DWORD *)(v108 + 44) ){

                    v108->Draw_GDI_Object(this->render_area);

                }else{

                    bool v109 = false;

                    if( v110 = *(_DWORD *)(v108 + 28) & 0xFFC ) {

                        if( (v110 & 4) == 4 ){

                            ASMSet_Shadowing(
                                0x00FFFFFF,
                                0x00000000,
                                0xFFFF00FF,
                                0x00000000);
                        }

                        if( (v110 & 8) == 8 ){

                            ASMSet_Shadowing(
                                0xFF00FF00,
                                (v110 >> 4) & 0xFF | (((v110 >> 4) & 0xFF) << 16),
                                0x00FF00FF,
                                ((v110 >> 4) & 0xFF | (((v110 >> 4) & 0xFF) << 16)) << 8);
                        }

                        v109 = true;
                    }

                    ASMSet_Color_Xform(
                        v108->Xform_Mask);

                    ASMSet_Xlate_Table(
                        v108->Color_Table);

                    ASMDraw_Sprite(
                        v108->Shape_Base,
                        v108->Draw_X,
                        v108->Draw_Y,
                        v108->Shape->Width,
                        v108->Shape->Height,
                        v108->Shape->Shape_Data_Offsets,
                        v108->Shape->Shape_Outline_Offset,
                        v108->Draw_Flag & 0x03);

                    if( v109 ){

                        ASMSet_Shadowing(
                            0x00FF00FF,
                            0x00000000,
                            0xFF00FF00,
                            0x00000000);
                    }
#if ENGINE_AOC
                    if ( v108[1].Next ){

                        v126 = 0;
                        v112 = this->futur_objs[1].Zone_Size_Ptrs;
                        v113 = v108->Draw_Level;
                        v148 = v108->Draw_Y + v111->Hotspot_Y;
                        v147 = v113;
                        if ( v112 > 0 )
                        {
                            do
                            {
                                v114 = sub_4DBAB0(v108[1].Next, v108[1].NextOnLevel);
                                sub_6341A0(v114, v108->Draw_X, v108->Draw_Y);
                                v115 = *&this->futur_objs->Select_Box[2 * v126];

                                if ( v115 ){

                                    v116 = v115->Shape;

                                    if ( v115->Draw_Y + v116->Hotspot_Y <= v148 && v115->Draw_Level <= v147 ){

                                        sub_632940(v115[1].Object_ID, v115[1].Object_ID);

                                        sub_6341E0(
                                            v115->Shape_Base,
                                            v115->Draw_X,
                                            v115->Draw_Y,
                                            v116->Width,
                                            v116->Height,
                                            v116->Shape_Data_Offsets,
                                            v116->Shape_Outline_Offset,
                                            v115->Draw_Flag & 3);
                                    }
                                }
                                ++v126;
                            }
                            while ( v126 < this->futur_objs[1].Zone_Size_Ptrs );
                        }
                    }
#endif // ENGINE_AOC
                }
                v108 = v108->NextOnLevel;

            }while( v108 );

            v107 = newFacet;
        }
        v107 += 4;
        newFacet = v107;
    }
    while( v107 <= 160 );

#if ENGINE_ROR

    if( view_debug_spans ){

        if( this->render_terrain_mode )
        {
            v111 = this->render_area;
            v112 = 0;
            for( ii = frame_count % 220 + 16; v112 < v111->Height; ++v112 )
            {
                TDrawArea::DrawLine(0, v112, v111->Width - 1, v112, ii);
                v111 = this->render_area;
            }
        }
    }

    if( view_debug_palette ){

        yc = 0;
        v114 = 32;
        do
        {
            v115 = 0;
            v116 = 16 * yc;
            v117 = 0;
            while( 1 )
            {
                TDrawArea::FillRect(this->render_area, v117, v114, v117 + 31, v114 + 15, v116 + v115);
                v117 += 32;
                ++v115;
                if( v117 >= 512 )
                    break;
                v116 = 16 * yc;
            }
            v114 += 16;
            ++yc;
        }
        while( v114 < 288 );
    }

#endif // ENGINE_ROR

    this->render_area->Unlock("view::view_function_terrain");
    this->render_area->CurSpanList = this->render_area->SpanList;

    DClipInfo_List *temp_futur_objs = this->futur_objs;
    this->futur_objs = this->prior_objs;
    this->prior_objs = temp_futur_objs;

    return 0;
}

void RGE_View::Update_Render_Pointers()
{
    RGE_View *v1; // esi@1
    char *v2; // eax@1
    int v3; // edi@3
    int i; // eax@10

    v1 = this;
    v2 = this->render_area->Bits;
    if( this->LastRenderBits != v2 || this->LastRenderSize != this->render_rect.bottom - this->render_rect.top + 1 )
    {
        v3 = this->render_rect.bottom - this->render_rect.top + 1;
        if( v3 > 0 )
        {
            if( v2 )
            {
                if( v3 != this->LastRenderSize || !this->RenderOffsets )
                {
                    if( this->RenderOffsets )
                        free(this->RenderOffsets);
                    v1->RenderOffsets = (void **)malloc(4 * v3);
                    v1->LastRenderSize = v3;
                }
                for( i = 0; i < v3; ++i )
                    v1->RenderOffsets[i] = (char *)v1->render_area->DisplayOffsets[v1->render_rect.top + i] + v1->render_rect.left;
            }
        }
    }
}

//----- (00538280) --------------------------------------------------------
void __stdcall RGE_View::Add_GDI_Clip_Mask(DClipInfo_Node *SDI, TSpan_List_Manager *Clip_Mask)
{
    DClipInfo_Node *v3; // esi@1
    int v4; // eax@1
    TSpan_List_Manager *v5; // ebx@3
    int v6; // edi@5
    int v7; // ebp@5
    int v8; // eax@5
    int v9; // ecx@5
    int v10; // edx@6
    DClipInfo_Node *v11; // eax@11
    int v12; // ecx@11
    DClipInfo_Node *v13; // edi@13
    int v14; // ebp@13
    int v15; // eax@13
    int v16; // edi@13
    int v17; // ecx@13
    int v18; // eax@13
    int i; // esi@15
    int xr2; // [sp+10h] [bp-8h]@13
    int xl2; // [sp+14h] [bp-4h]@13
    DClipInfo_Node *SDIa; // [sp+1Ch] [bp+4h]@5
    DClipInfo_Node *SDIb; // [sp+1Ch] [bp+4h]@13
    int xr; // [sp+20h] [bp+8h]@5
    int xra; // [sp+20h] [bp+8h]@13

    v3 = SDI;
    v4 = SDI->Node_Type;
    if( v4 == 1 )
    {
        TSpan_List_Manager::AddLine_Align(Clip_Mask, SDI->x1, SDI->y1, SDI->x2, SDI->y2);
        TSpan_List_Manager::AddLine_Align(Clip_Mask, SDI->x2, SDI->y2, SDI->x3, SDI->y3);
        TSpan_List_Manager::AddLine_Align(Clip_Mask, SDI->x3, SDI->y3, SDI->x4, SDI->y4);
        TSpan_List_Manager::AddLine_Align(Clip_Mask, SDI->x4, SDI->y4, SDI->x1, SDI->y1);
    }
    else
    {
        v5 = Clip_Mask;
        if( v4 == 2 || v4 == 3 )
        {
            v8 = SDI->x1;
            v6 = SDI->y1;
            v7 = SDI->y2;
            LOBYTE(v8) = v8 & 0xFC;
            v9 = SDI->x2 | 3;
            xr = v8;
            SDIa = (DClipInfo_Node *)(SDI->x2 | 3);
            if( v6 <= v7 || (v10 = v6, v6 = v7, v7 = v10, v6 <= v10) )
            {
                while( 1 )
                {
                    TSpan_List_Manager::AddSpan(v5, v8, v9, v6++);
                    if( v6 > v7 )
                        break;
                    v9 = (int)SDIa;
                    v8 = xr;
                }
            }
        }
        if( v3->Node_Type == 4 )
        {
            v11 = (DClipInfo_Node *)v3->x1;
            v12 = v3->x2;
            if( (signed int)v11 > v12 )
            {
                v11 = (DClipInfo_Node *)v3->x2;
                v12 = v3->x1;
            }
            v13 = v11;
            LOBYTE(v11) = (unsigned __int8)v11 | 3;
            v14 = v3->y2;
            SDIb = v11;
            v15 = v12;
            LOBYTE(v15) = v12 & 0xFC;
            v16 = (unsigned int)v13 & 0xFFFFFFFC;
            xl2 = v15;
            v17 = v12 | 3;
            v18 = v3->y1;
            xr2 = v17;
            xra = v3->y1;
            if( v18 > v14 )
            {
                xra = v3->y2;
                v14 = v3->y1;
                v18 = v3->y2;
            }
            TSpan_List_Manager::AddSpan(v5, v16, v17, v18);
            TSpan_List_Manager::AddSpan(v5, v16, xr2, v14);
            for( i = xra + 1; i < v14; ++i )
            {
                TSpan_List_Manager::AddSpan(v5, v16, (int)SDIb, i);
                TSpan_List_Manager::AddSpan(v5, xl2, xr2, i);
            }
        }
    }
}

//----- (00538420) --------------------------------------------------------
void __stdcall RGE_View::Draw_GDI_Object(DClipInfo_Node *SDI, TDrawArea *render_area)
{
    int v3; // eax@1
    int i; // edi@4

    v3 = SDI->Node_Type;
    if( v3 == 1 )
    {
        TDrawArea::DrawLine(SDI->x1, SDI->y1, SDI->x2, SDI->y2, SDI->Draw_Flag);
        TDrawArea::DrawLine(SDI->x2, SDI->y2, SDI->x3, SDI->y3, SDI->Draw_Flag);
        TDrawArea::DrawLine(SDI->x3, SDI->y3, SDI->x4, SDI->y4, SDI->Draw_Flag);
        TDrawArea::DrawLine(SDI->x4, SDI->y4, SDI->x1, SDI->y1, SDI->Draw_Flag);
    }
    else
    {
        if( v3 == 2 )
        {
            for( i = SDI->y1; i <= SDI->y2; ++i )
            {
                if( SDI->y3 )
                    TDrawArea::DrawLine(SDI->x1, i, SDI->x3, i, 74);
                if( SDI->y4 )
                    TDrawArea::DrawLine(SDI->x4, i, SDI->x2, i, -105);
            }
        }
        if( SDI->Node_Type == 4 )
        {
            TDrawArea::DrawLine(SDI->x1, SDI->y1, SDI->x2, SDI->y1, -1);
            TDrawArea::DrawLine(SDI->x1, SDI->y2, SDI->x2, SDI->y2, -1);
            TDrawArea::DrawLine(SDI->x1, SDI->y1, SDI->x1, SDI->y2, -1);
            TDrawArea::DrawLine(SDI->x2, SDI->y1, SDI->x2, SDI->y2, -1);
        }
    }
}

//----- (00538590) --------------------------------------------------------
int RGE_View::get_tile_mask_num(int map_col, int map_row, int map_width, int map_height, unsigned int VisibleMask)
{
    signed int v6; // ecx@1
    int v7; // ebp@5
    int v8; // edi@5
    unsigned __int32 **v9; // ebx@7
    int v10; // eax@7
    int v11; // edx@9
    int v12; // ebp@24
    int v13; // edi@30
    RGE_View *v15; // [sp+10h] [bp-4h]@1

    v15 = this;
    v6 = 0;
    if( map_col <= 0 || map_row <= 0 || map_col >= map_width - 1 || map_row >= map_height - 1 )
    {
        if( map_col > 0 && !(VisibleMask & (unsigned int)(&unified_map_offsets)[map_row][map_col - 1]) )
            v6 = 16;
        v12 = map_width - 1;
        if( map_col < map_width - 1 && !(VisibleMask & (unsigned int)(&unified_map_offsets)[map_row][map_col + 1]) )
            v6 |= 0x40u;
        if( map_row > 0 && !(VisibleMask & *(_DWORD *)(dword_886804[map_row] + 4 * map_col)) )
            LOBYTE(v6) = v6 | 0x80;
        v13 = map_height - 1;
        if( map_row < map_height - 1 && !(VisibleMask & *(_DWORD *)(dword_88680C[map_row] + 4 * map_col)) )
            v6 |= 0x20u;
        if( map_col > 0 )
        {
            if( map_row > 0 && !(VisibleMask & *(_DWORD *)(dword_886804[map_row] + 4 * map_col - 4)) )
                v6 |= 1u;
            if( map_col > 0 && map_row < v13 && !(VisibleMask & *(_DWORD *)(dword_88680C[map_row] + 4 * map_col - 4)) )
                v6 |= 2u;
        }
        if( map_col < v12 )
        {
            if( map_row > 0 && !(VisibleMask & *(_DWORD *)(dword_886804[map_row] + 4 * map_col + 4)) )
                v6 |= 8u;
            if( map_col < v12 && map_row < v13 && !(VisibleMask & *(_DWORD *)(dword_88680C[map_row] + 4 * map_col + 4)) )
                v6 |= 4u;
        }
    }
    else
    {
        v7 = dword_886804[map_row];
        v8 = 4 * map_col;
        if( !(VisibleMask & *(_DWORD *)(v7 + 4 * map_col)) )
            v6 = 128;
        v9 = (&unified_map_offsets)[map_row];
        v10 = 4 * map_col + 4;
        if( !(VisibleMask & *(unsigned int *)((char *)v9 + v10)) )
            v6 |= 0x40u;
        v11 = dword_88680C[map_row];
        if( !(VisibleMask & *(_DWORD *)(v11 + v8)) )
            v6 |= 0x20u;
        if( !(VisibleMask & (unsigned int)v9[v8 / 4u - 1]) )
            v6 |= 0x10u;
        if( !(VisibleMask & *(_DWORD *)(v10 + v7)) )
            v6 |= 8u;
        if( !(VisibleMask & *(_DWORD *)(v11 + v10)) )
            v6 |= 4u;
        if( !(VisibleMask & *(_DWORD *)(v11 + v8 - 4)) )
            v6 |= 2u;
        if( !(VisibleMask & *(_DWORD *)(v7 + v8 - 4)) )
            v6 |= 1u;
    }
    return v15->EdgeNumber[v6];
}
// 886804: using guessed type int dword_886804[];
// 886808: using guessed type unsigned __int32 **unified_map_offsets;
// 88680C: using guessed type int dword_88680C[];

//----- (00538710) --------------------------------------------------------
int RGE_View::draw_tile(RGE_Tile *tile, char terrain_type, short x, short y, short map_col, short map_row, char visible, int norm_draw, int fog_draw)
{
    RGE_View *v10; // esi@1
    RGE_Map *v11; // edx@1
    unsigned __int8 v12; // al@3
    int v13; // edi@4
    TShape *v14; // edi@18
    short v15; // ax@18
    int result; // eax@21
    short v17; // cx@23
    int v18; // eax@25
    RGE_Map *v19; // eax@26
    RGE_Tile *v20; // edx@27
    int v21; // eax@30
    TShape *v22; // edi@30
    short v23; // ax@32
    int v24; // eax@45
    RGE_Map *v25; // esi@46
    RGE_Tile *v26; // edx@47
    char draw_attribute; // [sp+10h] [bp-28h]@1
    int draw_border; // [sp+14h] [bp-24h]@3
    int draw_terrain; // [sp+18h] [bp-20h]@3
    char border_type; // [sp+1Ch] [bp-1Ch]@3
    int top_index; // [sp+20h] [bp-18h]@9
    int left_index; // [sp+24h] [bp-14h]@9
    int right_index; // [sp+28h] [bp-10h]@9
    int bottom_index; // [sp+2Ch] [bp-Ch]@9
    int retval; // [sp+30h] [bp-8h]@3
    unsigned int v36; // [sp+34h] [bp-4h]@2

    v10 = this;
    draw_attribute = tile->draw_attribute;
    v11 = this->map;
    if( (unsigned __int8)terrain_type < v11->num_terrain
        && (v36 = 408 * (unsigned __int8)terrain_type, v11->terrain_types[(unsigned __int8)terrain_type].loaded) )
    {
        draw_terrain = 1;
        retval = 0;
        draw_border = 0;
        v12 = *((_BYTE *)tile + 6);
        border_type = *((_BYTE *)tile + 6) & 0xF;
        if( border_type )
        {
            v13 = (unsigned __int8)border_type;
            if( v11->border_types[v13].loaded )
            {
                if( v11->border_types[v13].shape )
                {
                    if( v11->border_types[v13].border_style )
                    {
                        if( RGE_View::get_border_edge_pictures(
                                     this,
                                     border_type,
                                     tile->tile_type,
                                     v12 >> 4,
                                     map_col,
                                     map_row,
                                     &top_index,
                                     &right_index,
                                     &left_index,
                                     &bottom_index) )
                        {
                            draw_border = 1;
                            draw_terrain = 1;
                        }
                    }
                    else if( RGE_View::get_border_picture(this, border_type, tile->tile_type, v12 >> 4, map_col, map_row) != -1 )
                    {
                        draw_border = 1;
                        draw_terrain = v10->map->border_types[v13].draw_tile;
                    }
                }
            }
        }
        if( View_Grid_Mode > 0
            && !(draw_attribute & 0xDF)
            && (((unsigned __int8)(map_row / View_Grid_Mode) + (unsigned __int8)(map_col / View_Grid_Mode)) & 1) == 1 )
        {
            draw_attribute |= 0x20u;
        }
        if( view_debug_ObstructionMap )
            draw_border = 0;
        if( draw_terrain )
        {
            v14 = v10->map->terrain_types[v36 / 0x198].shape;
            v15 = RGE_View::get_tile_picture(v10, terrain_type, tile->tile_type, map_col, map_row);
            if( v14 && v15 != -1 )
            {
                if( view_debug_ObstructionMap )
                {
                    RGE_View::draw_terrain_obstruction_map(v10, x, y, v14, v15, map_col, map_row);
                    return 1;
                }
                RGE_View::draw_terrain_shape(v10, x, y, v14, v15, visible, draw_attribute, norm_draw, fog_draw);
                retval = 1;
            }
            v17 = map_col;
            if( !draw_border )
            {
                if( map_col > 0 )
                {
                    v18 = (int)&v10->map->map_row_offset[map_row][map_col - 1].screen_xpos;
                    *(_BYTE *)(v18 + 10) |= 0x40u;
                }
                v19 = v10->map;
                if( map_row < v19->map_height - 1 )
                {
                    v20 = v19->map_row_offset[map_row + 1];
                    v20[map_col].draw_attribute |= 0x40u;
                }
            }
        }
        else
        {
            v17 = map_col;
        }
        if( draw_border )
        {
            v21 = (int)v10->map + 1440 * (unsigned __int8)border_type;
            v22 = *(TShape **)(v21 + 13228);
            if( v22 )
            {
                if( *(_WORD *)(v21 + 14634) )
                {
                    if( RGE_View::get_border_edge_pictures(
                                 v10,
                                 border_type,
                                 tile->tile_type,
                                 *((_BYTE *)tile + 6) >> 4,
                                 v17,
                                 map_row,
                                 &top_index,
                                 &right_index,
                                 &left_index,
                                 &bottom_index) )
                    {
                        if( top_index != -1 )
                            RGE_View::draw_terrain_shape(v10, x, y, v22, top_index, visible, draw_attribute, norm_draw, fog_draw);
                        if( left_index != -1 )
                            RGE_View::draw_terrain_shape(v10, x, y, v22, left_index, visible, draw_attribute, norm_draw, fog_draw);
                        if( right_index != -1 )
                            RGE_View::draw_terrain_shape(v10, x, y, v22, right_index, visible, draw_attribute, norm_draw, fog_draw);
                        if( bottom_index != -1 )
                            RGE_View::draw_terrain_shape(v10, x, y, v22, bottom_index, visible, draw_attribute, norm_draw, fog_draw);
                    }
                }
                else
                {
                    v23 = RGE_View::get_border_picture(v10, border_type, tile->tile_type, *((_BYTE *)tile + 6) >> 4, v17, map_row);
                    if( v23 != -1 )
                        RGE_View::draw_terrain_shape(v10, x, y, v22, v23, visible, draw_attribute, norm_draw, fog_draw);
                }
                v17 = map_col;
            }
            if( v17 > 0 )
            {
                v24 = (int)&v10->map->map_row_offset[map_row][v17 - 1].screen_xpos;
                *(_BYTE *)(v24 + 10) |= 0x40u;
            }
            v25 = v10->map;
            if( map_row < v25->map_height - 1 )
            {
                v26 = v25->map_row_offset[map_row + 1];
                v26[v17].draw_attribute |= 0x40u;
            }
        }
        result = retval;
    }
    else
    {
        result = 0;
    }
    return result;
}
// 87D7A8: using guessed type int view_debug_ObstructionMap;
// 87D7B4: using guessed type int View_Grid_Mode;

//----- (00538B80) --------------------------------------------------------
void RGE_View::draw_terrain_shape(int x, int y, TShape *shape, int index, char visible, char draw_attribute, int draw_normal, int draw_fog)
{
    RGE_View *v9; // esi@1
    Shape_Info *v10; // edx@1
    int v11; // ebp@1
    char v12; // al@1
    int v13; // edi@1

    v9 = this;
    v10 = shape->shape_info;
    v11 = y - v10[index].Hotspot_Y;
    v12 = draw_attribute;
    v13 = x - v10[index].Hotspot_X;
    if( (draw_attribute & 0x10) == 16 )
    {
        fog_next_shape = 1;
        ASMSet_Shadowing(16711935, 671098880, -16711936, 2621480);
        TShape::shape_draw(shape, v9->cur_render_area, v13, v11, index, 0, 0);
        ASMSet_Shadowing(16711935, 0, -16711936, 0);
        fog_next_shape = 0;
    }
    else
    {
        if( (draw_attribute & 0x20) == 32 )
        {
            ASMSet_Shadowing(16711935, 1442862592, -16711936, (int)&loc_560053 + 3);
            v12 = draw_attribute;
        }
        if( (v12 & 0x80) == -128 )
        {
            ASMSet_Shadowing(16711935, 268439552 * (v12 & 0xF) + 67109888, -16711936, 268439552 * (v12 & 0xF) + 67109888);
            v12 = draw_attribute;
        }
        if( v9->map->fog_flag && visible == -128 )
            fog_next_shape = 1;
        if( draw_fog )
        {
            v9->cur_render_area->CurSpanList = v9->Terrain_Fog_Clip_Mask;
            fog_next_shape = 1;
            TShape::shape_draw(shape, v9->cur_render_area, x, y, index, 0, 0);
            v12 = draw_attribute;
            fog_next_shape = 0;
        }
        if( v12 & 0xA0 )
            fog_next_shape = 1;
        if( draw_normal )
        {
            v9->cur_render_area->CurSpanList = v9->Terrain_Clip_Mask;
            TShape::shape_draw(shape, v9->cur_render_area, x, y, index, 0, 0);
        }
        v9->cur_render_area->CurSpanList = v9->cur_render_area->SpanList;
        ASMSet_Shadowing(16711935, 0, -16711936, 0);
        fog_next_shape = 0;
    }
}

//----- (00538D60) --------------------------------------------------------
void RGE_View::draw_terrain_obstruction_map(int x, int y, TShape *shape, int index, int TileX, int TileY)
{
    RGE_View *v7; // ebp@1
    int v8; // eax@1
    signed int v9; // esi@3
    int v10; // edi@3
    int v11; // ebx@3
    int v12; // eax@4
    bool v13; // sf@7
    unsigned __int8 v14; // of@7
    int TileX4; // [sp+10h] [bp-4h]@1
    TShape *shapea; // [sp+20h] [bp+Ch]@1
    TShape *group_num_shape; // [sp+24h] [bp+10h]@3
    int TileXa; // [sp+28h] [bp+14h]@1
    int yl; // [sp+2Ch] [bp+18h]@1

    v7 = this;
    TileX4 = 4 * TileX;
    yl = 4 * TileY;
    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    TShape::shape_draw(shape, this->cur_render_area, x, y, index, 0, 0);
    shapea = (TShape *)RGE_Base_Game::get_shape(rge_base_game, 0);
    v8 = 0;
    for( TileXa = 0; ; v8 = TileXa )
    {
        v9 = 0;
        v10 = 8 * v8;
        v11 = 4 * v8;
        group_num_shape = (TShape *)(v8 + yl);
        do
        {
            v12 = (unsigned __int8)PathingSystem::obstruction(&pathSystem, v9 + TileX4, (int)group_num_shape);
            if( v12 > 0 )
                TShape::shape_draw(shapea, v7->cur_render_area, x + v10 + 2, y + v11 + 13, v12 - 1, 0, 0);
            ++v9;
            v10 += 8;
            v11 -= 4;
        }
        while( v9 < 4 );
        v14 = __OFSUB__(TileXa + 1, 4);
        v13 = TileXa++ - 3 < 0;
        if( !(v13 ^ v14) )
            break;
    }
}

//----- (00538E60) --------------------------------------------------------
BOOL RGE_View::Get_Cursor_Position(POINT *Point, int adjustX, int adjustY)
{
    RGE_View *v4; // edi@1
    TDrawArea *v5; // eax@1
    int v6; // eax@4
    int v7; // edx@6
    int v8; // ecx@6
    int v9; // edx@6

    v4 = this;
    GetCursorPos(Point);
    v5 = v4->render_area;
    if( v5->DrawSystem->ScreenMode == 1 )
    {
        ScreenToClient(v5->Wnd, Point);
        if( Point->x > 0x7FFF )
            Point->x -= 0x10000;
        v6 = Point->y;
        if( v6 > 0x7FFF )
            Point->y = v6 - 0x10000;
    }
    v7 = Point->y;
    v8 = adjustX + Point->x;
    Point->x = v8;
    v9 = adjustY + v7;
    Point->y = v9;
    return v8 >= v4->render_rect.left
            && v8 <= v4->render_rect.right
            && v9 >= v4->render_rect.top
            && v9 <= v4->render_rect.bottom;
}

//----- (00538F00) --------------------------------------------------------
int RGE_View::Pick_Tile(int x, int y, int *Tile_X, int *Tile_Y)
{
    RGE_View *v5; // ebx@1
    RGE_Map *v6; // eax@1
    int v7; // edx@1
    int v8; // esi@1
    signed int v9; // eax@1
    signed int v10; // ebp@1
    int *v11; // ecx@2
    int result; // eax@2
    signed int v13; // ecx@3
    int *v14; // ecx@4
    int v15; // esi@5
    int v16; // eax@5
    int v17; // edi@5
    int v18; // esi@5
    int i; // edi@5
    int bx1; // [sp+14h] [bp-4h]@1

    v5 = this;
    v6 = this->map;
    v7 = v6->map_width;
    v8 = v6->map_height;
    v9 = x + this->map_scr_x_offset - this->render_rect.left;
    v10 = y + this->map_scr_y_offset - this->render_rect.top;
    bx1 = v8;
    if( v9 >= 0 )
    {
        v13 = this->tile_wid;
        if( v9 < v13 * v7 )
        {
            v15 = v9 / v13;
            v16 = v10 / v5->tile_hgt;
            v17 = v15;
            v18 = v16 + v15;
            for( i = v17 - v16; i < 0 || v18 >= v7; ++i )
                --v18;
            while( i >= bx1 || v18 < 0 )
            {
                ++v18;
                --i;
            }
            Tile_X = (int *)1;
            do
            {
                RGE_View::get_tile_bounding_coords(v5, v18, i, &bx1, (int *)&Tile_Y, &y, &x);
                if( v10 >= (signed int)Tile_Y )
                {
                    if( v10 <= x )
                    {
                        Tile_X = 0;
                    }
                    else
                    {
                        --v18;
                        ++i;
                    }
                }
                else
                {
                    ++v18;
                    --i;
                }
            }
            while( Tile_X );
            result = 0;
            v5->tile_half_hgt = 0;
            v5->tile_half_wid = 0;
        }
        else
        {
            v14 = Tile_Y;
            *Tile_X = v7 + 1;
            *v14 = v8 + 1;
            result = 0;
        }
    }
    else
    {
        v11 = Tile_Y;
        *Tile_X = -1;
        *v11 = -1;
        result = 0;
    }
    return result;
}

//----- (00539030) --------------------------------------------------------
void RGE_View::get_tile_bounding_coords(int Tile_X, int Tile_Y, int *bx1, int *by1, int *bx2, int *by2)
{
    RGE_Tile *v7; // edx@1
    int v8; // esi@1
    int v9; // eax@1
    int v10; // edx@1

    v7 = this->map->map_row_offset[Tile_Y];
    v8 = v7[Tile_X].screen_xpos;
    v9 = (int)&v7[Tile_X].screen_xpos;
    v10 = *(_BYTE *)(v9 + 4);
    *bx1 = v8;
    *bx2 = *((_WORD *)&this->map->vfptr + 3 * (v10 + 4)) + v8 - 1;
    *by1 = *(_WORD *)(v9 + 2) - this->tile_half_hgt;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;
    *by2 = this->map->tilesizes[v10].height + *by1 - 1;
}

//----- (005390D0) --------------------------------------------------------
int RGE_View::pick_objects(int Xpos, int Ypos, int min_level, int max_level, int range, int max_confidence, int ignoreNeg)
{
    int v8; // edx@2
    int v9; // edi@2
    int v10; // ebp@3
    int v11; // esi@5
    char *v12; // eax@13
    RGE_SPick_Info *v13; // esi@14
    DClipInfo_Node *i; // edi@15
    int v15; // ebx@16
    int v16; // edx@19
    int v17; // eax@19
    int v18; // eax@28
    int v19; // eax@30
    int v20; // edx@37
    signed int v21; // ecx@37
    RGE_SPick_Info *v22; // eax@37
    RGE_SPick_Info **v23; // ebp@37
    int v24; // ebp@52
    RGE_SPick_Info *v25; // ecx@56
    RGE_SPick_Info *v26; // ecx@58
    int v27; // ebp@62
    RGE_SPick_Info *v28; // eax@62
    int v29; // eax@64
    RGE_SPick_Info **v30; // edx@68
    RGE_SPick_Info *v31; // eax@68
    RGE_SPick_Info *v32; // ecx@71
    RGE_SPick_Info *v33; // ecx@74
    int v34; // edx@81
    signed int v35; // edi@81
    RGE_SPick_Info **v36; // esi@81
    RGE_SPick_Info *v37; // ecx@82
    int v38; // eax@83
    int result; // eax@87
    RGE_View *v40; // [sp+10h] [bp-54h]@1
    int hotY; // [sp+14h] [bp-50h]@37
    int l; // [sp+18h] [bp-4Ch]@13
    int obj_id; // [sp+1Ch] [bp-48h]@37
    int z; // [sp+20h] [bp-44h]@0
    RGE_SPick_Info *head[5]; // [sp+28h] [bp-3Ch]@13
    RGE_SPick_Info *tail[5]; // [sp+3Ch] [bp-28h]@13
    RGE_SPick_Info *freep[5]; // [sp+50h] [bp-14h]@13
    int Xposa; // [sp+68h] [bp+4h]@13
    int Yposa; // [sp+6Ch] [bp+8h]@13
    int max_levela; // [sp+74h] [bp+10h]@37

    v40 = this;
    if( range < 0
        || (v8 = max_level, v9 = min_level, max_level < min_level)
        || (v10 = this->render_rect.left, Xpos < v10)
        || Xpos > this->render_rect.right
        || (v11 = this->render_rect.top, Ypos < v11)
        || Ypos > this->render_rect.bottom
        || min_level > 40
        || max_level < 0 )
    {
        result = 0;
    }
    else
    {
        if( min_level < 0 )
        {
            v9 = 0;
            min_level = 0;
        }
        if( max_level > 40 )
            v8 = 40;
        Yposa = Ypos - v11;
        v12 = (char *)&this->pick_list_size[1];
        freep[1] = 0;
        Xposa = Xpos - v10;
        freep[2] = 0;
        l = v8;
        freep[3] = 0;
        freep[4] = 0;
        tail[1] = 0;
        tail[2] = 0;
        tail[3] = 0;
        tail[4] = 0;
        head[1] = 0;
        head[2] = 0;
        head[3] = 0;
        head[4] = 0;
        *(_DWORD *)v12 = 0;
        *((_DWORD *)v12 + 1) = 0;
        *((_DWORD *)v12 + 2) = 0;
        *((_DWORD *)v12 + 3) = 0;
        if( v8 >= v9 )
        {
            v13 = (RGE_SPick_Info *)Yposa;
            do
            {
                for( i = v40->prior_objs->Draw_Level_Head[l]; i; i = i->NextOnLevel )
                {
                    v15 = 0;
                    if( !i->Node_Type && (!ignoreNeg || i->Object_ID >= 0) )
                    {
                        v16 = i->y1;
                        v17 = i->x2;
                        if( Xposa < i->x1 - range || Yposa < i->y1 - range || Xposa > v17 + range || Yposa > range + i->y2 )
                        {
                            v15 = 0;
                        }
                        else
                        {
                            v15 = 4;
                            if( Xposa >= i->x1 && Yposa >= v16 && Xposa <= v17 && Yposa <= i->y2 )
                            {
                                v15 = 3;
                                if( (i->Draw_Flag & 2) == 2 )
                                    v18 = RGE_View::sprite_check(i->Shape_Base, i->Shape, v17 - Xposa, Yposa - v16);
                                else
                                    v18 = RGE_View::sprite_check(i->Shape_Base, i->Shape, Xposa - i->x1, Yposa - v16);
                                v19 = v18 - 1;
                                if( v19 )
                                {
                                    if( v19 == 1 )
                                        v15 = 1;
                                }
                                else
                                {
                                    v15 = 2;
                                }
                            }
                        }
                    }
                    if( v15 && v15 <= max_confidence )
                    {
                        v20 = i->Object_ID;
                        hotY = i->y3;
                        v21 = 1;
                        obj_id = i->Object_ID;
                        max_levela = 1;
                        v22 = 0;
                        v23 = &head[1];
                        while( !v22 )
                        {
                            v13 = *v23;
                            if( *v23 )
                            {
                                while( v13->object_id != v20 )
                                {
                                    v13 = v13->next;
                                    if( !v13 )
                                        goto LABEL_45;
                                }
                                v22 = v13;
                                z = v21;
                            }
LABEL_45:
                            ++v21;
                            ++v23;
                            if( v21 >= 5 )
                            {
                                if( !v22 )
                                    goto LABEL_61;
                                break;
                            }
                            v20 = i->Object_ID;
                        }
                        if( z < v15 || z == v15 && hotY < v22->draw_level )
                            max_levela = 0;
                        if( max_levela )
                        {
                            v24 = z;
                            if( head[z] == v22 )
                                head[v24] = v22->next;
                            if( tail[v24] == v22 )
                                tail[v24] = v22->prev;
                            v25 = v22->next;
                            if( v25 )
                                v25->prev = v22->prev;
                            v26 = v22->prev;
                            if( v26 )
                                v26->next = v22->next;
                            v22->next = freep[v24];
                            v22->prev = 0;
                            freep[v24] = v22;
                        }
LABEL_61:
                        if( max_levela )
                        {
                            v27 = v15;
                            v28 = freep[v15];
                            if( v28 )
                            {
                                v13 = freep[v15];
                                freep[v27] = v28->next;
                            }
                            else
                            {
                                v29 = v40->pick_list_size[v15];
                                if( v29 == 64 )
                                {
                                    max_levela = 0;
                                }
                                else
                                {
                                    v13 = &v40->pick_lists[v15][v29];
                                    v40->pick_list_size[v15] = v29 + 1;
                                }
                            }
                            if( max_levela )
                            {
                                v13->object_id = obj_id;
                                v13->confidence = v15;
                                v13->draw_level = hotY;
                                v13->draw_x = i->Draw_X;
                                v30 = &head[v27];
                                v13->draw_y = i->Draw_Y;
                                v31 = head[v27];
                                v13->next = 0;
                                v13->prev = 0;
                                if( v31 )
                                {
                                    while( hotY < v31->draw_level )
                                    {
                                        v32 = v31->next;
                                        if( !v32 )
                                        {
                                            v31->next = v13;
                                            v13->prev = v31;
                                            goto LABEL_78;
                                        }
                                        v31 = v31->next;
                                        if( !v32 )
                                            goto LABEL_79;
                                    }
                                    v13->next = v31;
                                    v33 = v31->prev;
                                    v13->prev = v33;
                                    if( v33 )
                                    {
                                        v13->prev->next = v13;
                                        v31->prev = v13;
                                    }
                                    else
                                    {
                                        *v30 = v13;
                                        v31->prev = v13;
                                    }
                                }
                                else
                                {
                                    *v30 = v13;
LABEL_78:
                                    tail[v27] = v13;
                                }
                            }
                        }
                    }
LABEL_79:
                    ;
                }
                --l;
            }
            while( l >= min_level );
        }
        v34 = 0;
        v35 = 1;
        v36 = &head[1];
        while( 1 )
        {
            v37 = *v36;
            if( *v36 )
                break;
LABEL_86:
            ++v35;
            ++v36;
            if( v35 > 4 )
                return v34;
        }
        v38 = 12 * v34 + 8901796;
        while( 1 )
        {
            ++v34;
            *(_DWORD *)(v38 - 4) = v37->object_id;
            *(_WORD *)v38 = v37->confidence;
            *(_WORD *)(v38 + 2) = v37->draw_level;
            *(_WORD *)(v38 + 4) = v37->draw_x;
            *(_WORD *)(v38 + 6) = v37->draw_y;
            v38 += 12;
            if( v38 >= (signed int)&view_debug_redraw_all )
                break;
            v37 = v37->next;
            if( !v37 )
                goto LABEL_86;
        }
        result = 64;
    }
    return result;
}
// 87D7A4: using guessed type int view_debug_redraw_all;

//----- (00539510) --------------------------------------------------------
int __stdcall RGE_View::sprite_check(char *Shape_Base, Shape_Info *Shape, int check_x, int check_y)
{
    int v5; // ebx@3
    char *v6; // eax@6
    int v7; // ecx@6
    char *v8; // eax@9
    unsigned __int8 v9; // dl@11
    unsigned int v10; // edx@12
    int v11; // esi@14
    int v12; // eax@14
    int v13; // edx@17
    unsigned int v14; // edx@18
    unsigned int v15; // edx@22
    unsigned int v16; // edx@26
    int result; // eax@30
    unsigned __int8 Shapea; // [sp+18h] [bp+8h]@11

    if( Shape
        && check_x >= 0
        && (v5 = Shape->Width, check_x < v5)
        && check_y >= 0
        && check_y < Shape->Height
        && (v6 = &Shape_Base[Shape->Shape_Outline_Offset], v7 = *(_WORD *)&v6[4 * check_y], v7 >= 0)
        && check_x >= v7
        && check_x <= v5 - *(_WORD *)&v6[4 * check_y + 2] )
    {
        v8 = &Shape_Base[*(_DWORD *)(&Shape_Base[4 * check_y] + Shape->Shape_Data_Offsets)];
        if( v7 < v5 )
        {
            while( 1 )
            {
                if( check_x < v7 )
                    break;
                v9 = *v8++;
                Shapea = v9;
                switch( v9 & 0xF )
                {
                    case 0:
                    case 4:
                    case 8:
                    case 0xC:
                        v10 = (unsigned int)v9 >> 2;
                        v7 += v10;
                        if( check_x < v7 )
                            return 2;
                        v8 += v10;
                        goto LABEL_29;
                    case 2:
                        v11 = (unsigned __int8)*v8 | 16 * v9;
                        v12 = (int)(v8 + 1);
                        v7 += v11;
                        if( check_x < v7 )
                            return 2;
                        v8 = (char *)(v11 + v12);
                        goto LABEL_29;
                    case 1:
                    case 5:
                    case 9:
                    case 0xD:
                        v7 += (unsigned int)v9 >> 2;
                        goto LABEL_29;
                    case 3:
                        v13 = (unsigned __int8)*v8++;
                        v7 += v13 | 16 * Shapea;
                        goto LABEL_29;
                    case 6:
                        v14 = (unsigned int)v9 >> 4;
                        if( !((unsigned int)Shapea >> 4) )
                            v14 = (unsigned __int8)*v8++;
                        v7 += v14;
                        if( check_x < v7 )
                            return 2;
                        v8 += v14;
                        goto LABEL_29;
                    case 7:
                    case 0xA:
                        v15 = (unsigned int)v9 >> 4;
                        if( !((unsigned int)Shapea >> 4) )
                            v15 = (unsigned __int8)*v8++;
                        v7 += v15;
                        if( check_x < v7 )
                            return 2;
                        ++v8;
                        goto LABEL_29;
                    case 0xB:
                        v16 = (unsigned int)v9 >> 4;
                        if( !((unsigned int)Shapea >> 4) )
                            v16 = (unsigned __int8)*v8++;
                        v7 += v16;
                        if( check_x < v7 )
                            return 2;
LABEL_29:
                        if( v7 >= v5 )
                            return 1;
                        break;
                    case 0xE:
                    case 0xF:
                        goto LABEL_33;
                    default:
                        goto LABEL_32;
                }
            }
        }
LABEL_32:
        result = 1;
    }
    else
    {
LABEL_33:
        result = 0;
    }
    return result;
}

//----- (005396F0) --------------------------------------------------------
int RGE_View::pick_multi_objects(int Xpos1, int Ypos1, int Xpos2, int Ypos2, int min_level, int max_level, int player, char select_level, int ignoreNeg)
{
    RGE_View *v10; // ebx@1
    int v11; // ebp@1
    int v12; // esi@1
    int v13; // edi@3
    int v14; // ecx@5
    int v15; // edx@6
    int v16; // eax@11
    DClipInfo_Node *v17; // esi@12
    int v18; // edi@13
    signed int v19; // eax@14
    RGE_Static_Object *v20; // edx@20
    signed int v21; // ecx@26
    int v22; // edx@27
    _DWORD *v23; // ebx@28
    int v24; // edx@32
    int result; // eax@40
    int num_picked; // [sp+10h] [bp-Ch]@1
    RGE_View *v27; // [sp+14h] [bp-8h]@1
    int z; // [sp+18h] [bp-4h]@11
    int Xpos1a; // [sp+20h] [bp+4h]@11
    int Ypos1a; // [sp+24h] [bp+8h]@11
    int Xpos2a; // [sp+28h] [bp+Ch]@11
    int Ypos2a; // [sp+2Ch] [bp+10h]@11

    v10 = this;
    v11 = 0;
    v12 = this->render_rect.left;
    v27 = this;
    num_picked = 0;
    if( Xpos2 < v12
        || Xpos1 > this->render_rect.right
        || (v13 = this->render_rect.top, Ypos2 < v13)
        || Ypos1 > this->render_rect.bottom
        || (v14 = min_level, min_level > 40)
        || (v15 = max_level, max_level < 0) )
    {
        result = 0;
    }
    else
    {
        if( min_level < 0 )
        {
            v14 = 0;
            min_level = 0;
        }
        if( max_level > 40 )
            v15 = 40;
        Xpos1a = Xpos1 - v12;
        Xpos2a = Xpos2 - v12;
        Ypos2a = Ypos2 - v13;
        v16 = v15;
        Ypos1a = Ypos1 - v13;
        z = v15;
        if( v15 < v14 )
        {
LABEL_40:
            result = v11;
        }
        else
        {
            while( 1 )
            {
                v17 = v10->prior_objs->Draw_Level_Head[v16];
                if( v17 )
                    break;
LABEL_39:
                z = --v16;
                if( v16 < v14 )
                    goto LABEL_40;
            }
            v18 = 12 * v11 + 8901796;
            while( 1 )
            {
                v19 = 0;
                if( !v17->Node_Type )
                {
                    max_level = v17->Object_ID;
                    if( v17->Object_ID >= 0 && Xpos1a <= v17->x2 && Xpos2a >= v17->x1 && Ypos1a <= v17->y2 && Ypos2a >= v17->y1 )
                    {
                        v20 = v27->world->objectsValue[max_level];
                        if( (player == -1 || v20->owner->id == player)
                            && v20->object_state == 2
                            && v20->master_obj->select_level >= (unsigned __int8)select_level )
                        {
                            v19 = 1;
                        }
                    }
                }
                if( v19 )
                {
                    v21 = 1;
                    if( v18 > (signed int)word_87D4A4 )
                    {
                        v22 = 0;
                        if( v18 > (signed int)word_87D4A4 )
                        {
                            v23 = &Picked_Objects;
                            while( *v23 != max_level )
                            {
                                ++v22;
                                v23 += 3;
                                if( v22 >= num_picked )
                                    goto LABEL_34;
                            }
                            v24 = 3 * v22;
                            v21 = 0;
                            if( word_87D4A4[2 * v24] > v19 )
                                word_87D4A4[2 * v24] = v19;
                        }
                    }
LABEL_34:
                    if( v21 )
                    {
                        *(_DWORD *)(v18 - 4) = max_level;
                        *(_WORD *)v18 = v19;
                        *(_WORD *)(v18 + 2) = v19;
                        *(_WORD *)(v18 + 4) = v17->Draw_X;
                        *(_WORD *)(v18 + 6) = v17->Draw_Y;
                        v18 += 12;
                        ++num_picked;
                    }
                    if( v18 >= (signed int)&view_debug_redraw_all )
                        break;
                }
                v17 = v17->NextOnLevel;
                if( !v17 )
                {
                    v14 = min_level;
                    v16 = z;
                    v10 = v27;
                    v11 = num_picked;
                    goto LABEL_39;
                }
            }
            result = 64;
        }
    }
    return result;
}
// 87D4A4: using guessed type short word_87D4A4[];
// 87D7A4: using guessed type int view_debug_redraw_all;

//----- (00539930) --------------------------------------------------------
int RGE_View::pick_touched_object(DClipInfo_List *obj_list, int Xpos, int Ypos, int min_level, int max_level, int *touched_object_id)
{
    int v7; // eax@1
    int v8; // ebx@4
    int v9; // ecx@12
    DClipInfo_Node *v10; // esi@13
    int v11; // ecx@15
    int result; // eax@22
    int Yposa; // [sp+1Ch] [bp+Ch]@12
    int max_levela; // [sp+24h] [bp+14h]@12

    *touched_object_id = 0;
    v7 = max_level;
    if( max_level < min_level )
        goto LABEL_24;
    if( Xpos < this->render_rect.left )
        goto LABEL_24;
    if( Xpos > this->render_rect.right )
        goto LABEL_24;
    v8 = Ypos;
    if( Ypos < this->render_rect.top || Ypos > this->render_rect.bottom || min_level > 40 || max_level < 0 )
        goto LABEL_24;
    if( min_level < 0 )
        min_level = 0;
    if( max_level > 40 )
        v7 = 40;
    v9 = v7;
    max_levela = 0;
    Yposa = v7;
    if( v7 < min_level )
    {
LABEL_24:
        result = 0;
    }
    else
    {
        while( 1 )
        {
            v10 = obj_list->Draw_Level_Head[v9];
            if( v10 )
            {
                do
                {
                    if( !v10->Node_Type )
                    {
                        v11 = v10->y1;
                        if( (v10->Draw_Flag & 2) == 2 )
                        {
                            if( RGE_View::sprite_check(v10->Shape_Base, v10->Shape, v10->x2 - Xpos, v8 - v11) == 2 )
                            {
                                max_levela = 1;
                                *touched_object_id = v10->Object_ID;
                            }
                        }
                        else if( RGE_View::sprite_check(v10->Shape_Base, v10->Shape, Xpos - v10->x1, v8 - v11) == 2 )
                        {
                            max_levela = 1;
                            *touched_object_id = v10->Object_ID;
                        }
                    }
                    v10 = v10->NextOnLevel;
                }
                while( v10 );
                v9 = Yposa;
            }
            result = 1;
            if( max_levela == 1 )
                break;
            Yposa = --v9;
            if( v9 < min_level )
                goto LABEL_24;
        }
    }
    return result;
}

//----- (00539AA0) --------------------------------------------------------
short RGE_View::get_tile_picture(char terrain_type, char tile_type, short map_col, short map_row)
{
    RGE_Map *v5; // ecx@1
    int v6; // edx@1
    short result; // ax@2
    int v8; // eax@3
    short v9; // si@3
    int v10; // edi@3
    int v11; // ecx@5
    unsigned __int8 v12; // al@6
    unsigned __int8 v13; // bl@6
    char terrain_typea; // [sp+14h] [bp+4h]@6
    unsigned __int8 rows; // [sp+18h] [bp+8h]@6

    v5 = this->map;
    v6 = (int)&v5->terrain_types[(unsigned __int8)terrain_type].loaded;
    if( v5->terrain_types[(unsigned __int8)terrain_type].shape )
    {
        v8 = 3 * (unsigned __int8)tile_type;
        v9 = *(_WORD *)(v6 + 6 * (unsigned __int8)tile_type + 70);
        v10 = v6 + 6 * (unsigned __int8)tile_type + 70;
        if( v9 )
        {
            v11 = 0;
            if( v9 > 1 )
            {
                v12 = *(_BYTE *)(v6 + 186);
                v13 = *(_BYTE *)(v6 + 188);
                terrain_typea = *(_BYTE *)(v6 + 186);
                rows = *(_BYTE *)(v6 + 188);
                if( v12 > 1u || v13 > 1u )
                {
                    if( v12 )
                    {
                        v11 = (unsigned __int8)terrain_typea;
                        v8 = map_row / (signed int)(unsigned __int8)terrain_typea;
                        v6 = map_row % (signed int)(unsigned __int8)terrain_typea;
                        LOBYTE(v11) = map_row % (unsigned __int8)terrain_typea;
                    }
                    else
                    {
                        LOBYTE(v11) = 0;
                    }
                    if( v13 )
                    {
                        v8 = map_col / (signed int)rows;
                        v6 = map_col % (signed int)rows;
                    }
                    else
                    {
                        LOBYTE(v6) = 0;
                    }
                    LOWORD(v11) = (unsigned __int8)v11;
                    LOWORD(v8) = v13;
                    LOWORD(v6) = (unsigned __int8)v6;
                    v11 = v6 + v8 * v11;
                }
            }
            if( (signed short)v11 > v9 - 1 )
                LOWORD(v11) = 0;
            result = *(_WORD *)(v10 + 4) + v11 * *(_WORD *)(v10 + 2);
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        result = -1;
    }
    return result;
}

//----- (00539B90) --------------------------------------------------------
short RGE_View::get_border_picture(char border_type, char tile_type, char border_shape, short map_col, short map_row)
{
    char *v6; // ecx@1
    short result; // ax@2
    int v8; // eax@3
    signed short v9; // si@3
    int v10; // edi@3
    short v11; // dx@5
    short v12; // cx@6

    v6 = &this->map->border_types[(unsigned __int8)border_type].loaded;
    if( *((_DWORD *)v6 + 8) )
    {
        v8 = (unsigned __int8)border_shape + 12 * (unsigned __int8)tile_type + 10;
        v9 = *(_WORD *)&v6[6 * v8];
        v10 = (int)&v6[6 * v8];
        if( v9 )
        {
            v11 = 0;
            if( v9 > 1 )
            {
                v12 = *((_WORD *)v6 + 719);
                if( (v12 || border_shape != 11 && border_shape != 12) && (v12 != 1 || border_shape != 3 && border_shape != 2) )
                {
                    if( (v12 || border_shape != 9 && border_shape != 10) && (v12 != 1 || border_shape != 1 && border_shape != 4) )
                        v11 = 0;
                    else
                        v11 = map_col % v9;
                }
                else
                {
                    v11 = map_row % v9;
                }
            }
            if( v11 > v9 - 1 )
                v11 = 0;
            result = *(_WORD *)(v10 + 4) + v11 * *(_WORD *)(v10 + 2);
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        result = -1;
    }
    return result;
}

//----- (00539C80) --------------------------------------------------------
int RGE_View::get_border_edge_pictures(char border_type, char tile_type, char border_shape, short map_col, short map_row, int *top_index, int *right_index, int *left_index, int *bottom_index)
{
    RGE_View *v10; // esi@1
    char v11; // al@2
    int v12; // ecx@4
    int v13; // ecx@6
    int v14; // ecx@8
    int result; // eax@11

    v10 = this;
    *top_index = -1;
    *left_index = -1;
    *right_index = -1;
    *bottom_index = -1;
    if( this->map->border_types[(unsigned __int8)border_type].shape && (v11 = border_shape) != 0 )
    {
        if( border_shape & 1 )
        {
            v12 = RGE_View::get_border_picture(this, border_type, tile_type, 1, map_col, map_row);
            v11 = border_shape;
            *top_index = v12;
        }
        if( v11 & 2 )
        {
            v13 = RGE_View::get_border_picture(v10, border_type, tile_type, 4, map_col, map_row);
            v11 = border_shape;
            *bottom_index = v13;
        }
        if( v11 & 4 )
        {
            v14 = RGE_View::get_border_picture(v10, border_type, tile_type, 3, map_col, map_row);
            v11 = border_shape;
            *left_index = v14;
        }
        if( v11 & 8 )
            *right_index = RGE_View::get_border_picture(v10, border_type, tile_type, 2, map_col, map_row);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int RGE_View::hit_tile(
    RGE_Tile *a2,
    RGE_Tile *tile,
    short x,
    short y,
    short map_col,
    short map_row,
    POINT *mouse_pos )
{
    short v8; // bp@1
    char v9; // al@2
    int v10; // eax@5
    RGE_Map *v11; // ecx@5
    int v12; // edx@6
    int v13; // edi@7
    TShape *v14; // esi@10
    short v15; // ax@10
    int v16; // ecx@12
    RGE_View *v18; // [sp+10h] [bp-4h]@1
    RGE_Tile *tilea; // [sp+18h] [bp+4h]@2

    v8 = 0;
    v18 = this;
    if( tile )
    {
        LOWORD(a2) = tile->tile_type;
        v9 = *((_BYTE *)tile + 5);
        tilea = a2;
        v8 = v9 & 0x1F;
    }
    else
    {
        tilea = 0;
        LOWORD(a2) = 0;
    }
    if( mouse_pos->x >= x )
    {
        v10 = (signed short)a2;
        v11 = this->map;
        if( mouse_pos->x < x + (signed int)*((_WORD *)&v11->vfptr + 3 * ((signed short)a2 + 4)) )
        {
            v12 = mouse_pos->y;
            if( v12 >= y )
            {
                v13 = v10;
                if( v12 < y + v11->tilesizes[v10].height )
                {
                    if( v8 >= v11->num_terrain )
                        return 1;
                    if( !v11->terrain_types[v8].loaded )
                        return 1;
                    v14 = v11->terrain_types[v8].shape;
                    v15 = RGE_View::get_tile_picture(v18, v8, (char)tilea, map_col, map_row);
                    if( !v14 || v15 == -1 )
                        return 1;
                    v16 = mouse_pos->y;
                    if( v16 < y + v18->map->tilesizes[v13].height && TShape::shape_check(v14, mouse_pos->x - x, v16 - y, v15) )
                        return 1;
                }
            }
        }
    }
    return 0;
}

RGE_Static_Object *RGE_View::hit_object(
    RGE_Tile *tile,
    short x,
    short y,
    short map_col,
    short map_row,
    POINT *mouse_pos,
    POINT *start_mouse_pos,
    short *item_scr_x,
    short *item_scr_y,
    RGE_Static_Object *orig_picked_obj,
    char fog_flag = 0 )
{
    POINT *v12; // ebx@3
    int v13; // edi@3
    int v14; // ebp@3
    RGE_Static_Object *v15; // esi@4
    char v16; // al@9
    RGE_Static_Object *v17; // ecx@19
    RGE_Player *v18; // eax@23
    RGE_Object_Node *v19; // esi@33
    short max_x; // [sp+12h] [bp-1Ah]@28
    RGE_Static_Object *picked_obj; // [sp+14h] [bp-18h]@1
    RGE_View *v23; // [sp+18h] [bp-14h]@1
    RGE_Object_Node *temp; // [sp+1Ch] [bp-10h]@2
    RGE_Object_Node *save_list; // [sp+20h] [bp-Ch]@2
    int min_x; // [sp+24h] [bp-8h]@28
    int min_y; // [sp+28h] [bp-4h]@28

    v23 = this;
    picked_obj = 0;
    if( tile != (RGE_Tile *)-12 )
    {
        save_list = RGE_Object_List::sort(&tile->objects);
        temp = save_list;
        if( save_list )
        {
            v12 = mouse_pos;
            v13 = y;
            v14 = x;
            do
            {
                v15 = temp->node;
                if( !temp->node )
                    break;
                if( v15->object_state < 7u
                    && (!fog_flag || v15->master_obj->fog_flag)
                    && (unsigned __int8)v15->master_obj->select_level >= v23->function_parm )
                {
                    v16 = v23->function_mode;
                    if( v16 == 43 || v16 == 44 )
                    {
                        if( v15->owner != v23->player )
                            goto LABEL_31;
                        if( v16 == 44 )
                        {
                            if( RGE_Static_Object::box_hit_test(
                                         v15,
                                         v14,
                                         v13,
                                         start_mouse_pos->x,
                                         start_mouse_pos->y,
                                         v12->x,
                                         v12->y) )
                            {
                                if( !RGE_Player::select_one_object(v23->player, v15, 0) )
                                    break;
                                picked_obj = v15;
                            }
                            goto LABEL_31;
                        }
                    }
                    if( RGE_Static_Object::hit_test(v15, v14, v13, v14, v13, v12->x, v12->y, 5) )
                    {
                        if( orig_picked_obj && v15 == orig_picked_obj )
                        {
                            v17 = picked_obj;
                            if( picked_obj )
                                return picked_obj;
                        }
                        else
                        {
                            v17 = picked_obj;
                        }
                        if( !v17 )
                        {
LABEL_28:
                            picked_obj = v15;
                            if( !RGE_Static_Object::get_frame(v15, (short *)&min_x, (short *)&min_y, &max_x, (short *)&tile) )
                            {
                                min_x = 0;
                                min_y = 0;
                            }
                            *item_scr_x = v14 + min_x + v15->screen_x_offset;
                            *item_scr_y = v13 + min_y + v15->screen_y_offset;
                            goto LABEL_31;
                        }
                        v18 = v23->player;
                        if( v15->owner != v18 )
                        {
                            if( v17->owner == v18 )
                                goto LABEL_31;
                            v17 = picked_obj;
                        }
                        if( !v17 || (unsigned __int8)v15->master_obj->select_level >= v17->master_obj->select_level )
                            goto LABEL_28;
                    }
                }
LABEL_31:
                temp = temp->next;
            }
            while( temp );
        }
        if( save_list )
        {
            do
            {
                v19 = save_list->next;
                free(save_list);
                save_list = v19;
            }
            while( v19 );
        }
    }
    return picked_obj;
}

int RGE_View::start_scroll_view(
    char scroll_action_in,
    int x,
    int y,
    int ctrl_key,
    int shift_key )
{
    char v6; // bl@1
    RGE_View *v7; // esi@1
    int result; // eax@3
    double v9; // st7@6
    TPanelVtbl *v10; // ebx@6
    char v11; // al@8
    char v12; // al@19
    float v13; // ST20_4@22
    float v14; // ST1C_4@22
    RGE_Pick_Info pick_info; // [sp+34h] [bp-14h]@2

    v6 = scroll_action_in;
    v7 = this;
    if( scroll_action_in == 3 )
    {
        if( (unsigned __int8)RGE_View::pick(this, 40, 0, x, y, &pick_info, 0) != 51 )
            return 0;
        RGE_View::set_selection_area(
            v7,
            (signed __int64)pick_info.x,
            (signed __int64)pick_info.y,
            (signed __int64)pick_info.x,
            (signed __int64)pick_info.y);
    }
    else if( scroll_action_in == 9 )
    {
        RGE_View::pick(this, 40, 0, x, y, &pick_info, 0);
        v9 = pick_info.y;
        v7->real_old_map_col = (signed __int64)pick_info.x;
        v10 = v7->vfptr;
        v7->real_old_map_row = (signed __int64)v9;
        result = (*(int (__fastcall **)(RGE_View *, _DWORD, int, int, int, int, signed int))&v10[1].gap10[4])(
                             v7,
                             (unsigned __int64)(signed __int64)v9 >> 32,
                             x,
                             y,
                             x,
                             y,
                             1);
        if( !result )
            return result;
        v10->set_redraw((TPanel *)v7, RedrawNormal);
        v6 = 9;
    }
    v7->scroll_action = v6;
    v7->mouse_last_x = x;
    v7->mouse_down_x = x;
    v7->mouse_last_y = y;
    v7->mouse_down_y = y;
    TPanel::capture_mouse((TPanel *)&v7->vfptr);
    v11 = v7->scroll_action;
    if( v11 == 1 || v11 == 2 || v11 == 6 || v11 == 7 || v11 == 8 )
        RGE_Base_Game::mouse_off(rge_base_game);
    if( v7->scroll_action == 2 )
    {
        if( !shift_key && !ctrl_key )
            RGE_Player::unselect_object(v7->player);
        v7->vfptr->set_redraw((TPanel *)v7, RedrawNormal);
    }
    v12 = v7->scroll_action;
    if( v12 != 6 && v12 != 8 || (unsigned __int8)RGE_View::pick(v7, 40, 0, x, y, &pick_info, 0) != 51 )
    {
        result = 0;
    }
    else
    {
        v13 = pick_info.y - -0.5;
        v14 = pick_info.x - -0.5;
        RGE_Player::set_view_loc(v7->player, v14, v13);
        v7->vfptr->set_redraw((TPanel *)v7, RedrawNormal);
        result = 1;
    }
    return result;
}

int RGE_View::handle_scroll_view( int x, int y )
{
    int v3; // ebx@1
    RGE_View *v4; // esi@1
    int v5; // edi@1
    int *v6; // ebp@1
    int result; // eax@3
    RGE_Player *v8; // edx@4
    char v9; // al@4
    int v10; // ST10_4@6
    float v11; // ST14_4@8
    float v12; // ST10_4@8
    RGE_Player *v13; // ecx@9
    int v14; // ecx@13
    int v15; // eax@13
    signed __int64 v16; // rax@16
    int v17; // eax@17
    signed __int64 v18; // rax@20
    TPanelVtbl *v19; // edx@23
    int v20; // eax@24
    TDrawArea *v21; // edx@24
    int v22; // eax@24
    TPanelVtbl *v23; // edx@24
    int v24; // ecx@25
    int v25; // eax@25
    RGE_Player *v26; // ecx@28
    double v27; // st7@28
    float v28; // ST14_4@28
    float v29; // ST10_4@28
    int v30; // eax@29
    RGE_Player *v31; // ecx@32
    double v32; // st7@32
    float v33; // ST14_4@32
    float v34; // ST10_4@32
    int v35; // eax@36
    TDrawArea *v36; // edx@36
    int v37; // ecx@36
    RGE_Player *v38; // ecx@37
    signed int v39; // ebp@44
    int v40; // ecx@55
    int v41; // eax@55
    double v42; // st6@59
    float v43; // ST14_4@59
    float v44; // ST10_4@59
    int v45; // ecx@60
    int v46; // eax@60
    RGE_Player *v47; // ecx@64
    double v48; // st6@64
    float v49; // ST14_4@64
    float v50; // ST10_4@64
    int v51; // edx@68
    TDrawArea *v52; // ecx@68
    int v53; // eax@68
    char v54; // al@70
    RGE_Static_Object *v55; // eax@77
    RGE_Active_Sprite_List *v56; // ecx@77
    char v57; // al@78
    RGE_Sprite *v58; // eax@79
    TPanelVtbl *v59; // ebp@86
    RGE_Player *v60; // ecx@87
    float save_view_y; // [sp+20h] [bp-24h]@4
    int save_mouse_last_x; // [sp+24h] [bp-20h]@1
    int save_mouse_last_xa; // [sp+24h] [bp-20h]@65
    POINT point; // [sp+28h] [bp-1Ch]@24
    RGE_Pick_Info pick_info; // [sp+30h] [bp-14h]@7
    TPanelVtbl *xa; // [sp+48h] [bp+4h]@6
    int xb; // [sp+48h] [bp+4h]@25
    int xc; // [sp+48h] [bp+4h]@60
    int xd; // [sp+48h] [bp+4h]@65
    int change; // [sp+4Ch] [bp+8h]@4

    v3 = x;
    v4 = this;
    v5 = y;
    v6 = &this->mouse_last_x;
    save_mouse_last_x = this->mouse_last_x;
    if( x != this->mouse_last_x || y != this->mouse_last_y )
    {
        v8 = this->player;
        change = SLODWORD(v8->view_x);
        v9 = this->scroll_action;
        save_view_y = v8->view_y;
        switch( v9 )
        {
            case 2:
                *v6 = x;
                this->mouse_last_y = v5;
                TPanel::bound_point((TPanel *)&this->vfptr, v6, &this->mouse_last_y);
                v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
                result = 0;
                break;
            case 6:
                v10 = x;
                xa = this->vfptr;
                if( this->vfptr->is_inside((TPanel *)this, v10, v5)
                    && (unsigned __int8)RGE_View::pick(v4, 40, 0, v3, v5, &pick_info, 0) == 51 )
                {
                    v11 = pick_info.y - -0.5;
                    v12 = pick_info.x - -0.5;
                    RGE_Player::set_view_loc(v4->player, v12, v11);
                }
                v13 = v4->player;
                *v6 = v3;
                v4->mouse_last_y = v5;
                if( *(float *)&change != v13->view_x || save_view_y != v13->view_y )
                {
                    xa->set_redraw((TPanel *)v4, RedrawNormal);
                    result = 1;
                }
                else
                {
                    result = 0;
                }
                break;
            case 7:
                v14 = this->mouse_last_y;
                v15 = v5 - v14;
                if( v5 != v14 && v15 < 100 && v15 > -100 )
                {
                    v16 = (signed __int64)((double)(v5 - v14) * 0.5);
                    v4->player->map_y += v16;
                    v4->player->map_x -= v16;
                }
                v17 = x - *v6;
                if( x != *v6 && v17 < 100 && v17 > -100 )
                {
                    v18 = (signed __int64)((double)(x - *v6) * 0.5);
                    v4->player->map_y += v18;
                    v4->player->map_x += v18;
                }
                if( abs(v5 - v4->mouse_down_y) > 8 || abs(x - v4->mouse_down_x) > 8 )
                {
                    v20 = v4->mouse_down_x;
                    v21 = v4->render_area;
                    point.y = v4->mouse_down_y;
                    point.x = v20;
                    ClientToScreen(v21->Wnd, &point);
                    SetCursorPos(point.x, point.y);
                    v22 = v4->mouse_down_x;
                    v23 = v4->vfptr;
                    v4->mouse_last_y = v4->mouse_down_y;
                    *v6 = v22;
                    v23->set_redraw((TPanel *)v4, RedrawNormal);
                    result = 1;
                }
                else
                {
                    v19 = v4->vfptr;
                    *v6 = x;
                    v4->mouse_last_y = v5;
                    v19->set_redraw((TPanel *)v4, RedrawNormal);
                    result = 1;
                }
                break;
            case 8:
                v24 = this->mouse_last_y;
                v25 = v5 - v24;
                xb = v5 - v24;
                if( v5 != v24 && v25 < 100 && v25 > -100 )
                {
                    v26 = v4->player;
                    v27 = (double)(signed int)(signed __int64)((double)xb * 0.5);
                    v28 = v26->view_y + v27;
                    v29 = v26->view_x - v27;
                    RGE_Player::set_view_loc(v26, v29, v28);
                }
                v30 = v3 - *v6;
                if( v3 != *v6 && v30 < 100 && v30 > -100 )
                {
                    v31 = v4->player;
                    v32 = (double)(signed int)(signed __int64)((double)(v3 - *v6) * 0.5);
                    v33 = v31->view_y + v32;
                    v34 = v31->view_x + v32;
                    RGE_Player::set_view_loc(v31, v34, v33);
                }
                if( abs(v5 - v4->mouse_down_y) > 8 || abs(v3 - v4->mouse_down_x) > 8 )
                {
                    v35 = v4->mouse_down_x;
                    v36 = v4->render_area;
                    point.y = v4->mouse_down_y;
                    point.x = v35;
                    ClientToScreen(v36->Wnd, &point);
                    SetCursorPos(point.x, point.y);
                    v37 = v4->mouse_down_y;
                    *v6 = v4->mouse_down_x;
                    v4->mouse_last_y = v37;
                }
                else
                {
                    *v6 = v3;
                    v4->mouse_last_y = v5;
                }
                v38 = v4->player;
                if( *(float *)&change != v38->view_x || save_view_y != v38->view_y )
                {
                    v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
                    result = 1;
                }
                else
                {
                    result = 0;
                }
                break;
            default:
                if( v9 == 3 || v9 == 4 || v9 == 9 )
                    v39 = x < this->clip_rect.left + 64 && x < save_mouse_last_x
                         || x > this->clip_rect.right - 64 && x > save_mouse_last_x
                         || v5 < this->clip_rect.top + 32 && v5 < this->mouse_last_y
                         || v5 > this->clip_rect.bottom - 32 && v5 > this->mouse_last_y;
                else
                    v39 = 1;
                v40 = this->mouse_last_y;
                v41 = v5 - v40;
                if( v5 != v40 && v41 < 200 && v41 > -200 && v39 )
                {
                    v42 = (double)(v5 - v40) * 0.0625;
                    v43 = v8->view_y + v42;
                    v44 = v8->view_x - v42;
                    RGE_Player::set_view_loc(v8, v44, v43);
                }
                v45 = v4->mouse_last_x;
                v46 = x - v45;
                xc = x - v45;
                if( v3 != v45 && v46 < 200 && v46 > -200 && v39 )
                {
                    v47 = v4->player;
                    v48 = (double)xc * 0.0625;
                    v49 = v47->view_y + v48;
                    v50 = v47->view_x + v48;
                    RGE_Player::set_view_loc(v47, v50, v49);
                }
                save_mouse_last_xa = v4->mouse_last_x;
                xd = v4->mouse_last_y;
                v4->mouse_last_x = v3;
                v4->mouse_last_y = v5;
                if( v39 )
                {
                    if( abs(v5 - v4->mouse_down_y) > 8 || abs(v3 - v4->mouse_down_x) > 8 )
                    {
                        v51 = v4->mouse_down_x;
                        point.y = v4->mouse_down_y;
                        v52 = v4->render_area;
                        point.x = v51;
                        ClientToScreen(v52->Wnd, &point);
                        SetCursorPos(point.x, point.y);
                        v53 = v4->mouse_down_y;
                        v4->mouse_last_x = v4->mouse_down_x;
                        v4->mouse_last_y = v53;
                    }
                }
                else
                {
                    v4->mouse_down_x = v3;
                    v4->mouse_down_y = v5;
                }
                v54 = v4->scroll_action;
                switch( v54 )
                {
                    case 3:
                        if( (unsigned __int8)RGE_View::pick(v4, 40, 0, v3, v5, &pick_info, 0) == 51 && v4->player )
                            RGE_View::set_selection_area(
                                v4,
                                v4->sel_col1,
                                v4->sel_row1,
                                (signed __int64)pick_info.x,
                                (signed __int64)pick_info.y);
                        break;
                    case 4:
                        if( v4->player->selected_obj && (unsigned __int8)RGE_View::pick(v4, 40, 0, v3, v5, &pick_info, 0) == 51 )
                        {
                            (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))&v4->player->selected_obj->vfptr->gap4[48])(
                                LODWORD(pick_info.x),
                                LODWORD(pick_info.y),
                                0);
                            v55 = v4->player->selected_obj;
                            v56 = v55->sprite_list;
                            if( v56 )
                            {
                                v57 = RGE_Active_Sprite_List::get_lowest_draw_level(v56);
                            }
                            else
                            {
                                v58 = v55->sprite;
                                if( v58 )
                                    v57 = RGE_Sprite::get_lowest_draw_level(v58);
                                else
                                    v57 = 20;
                            }
                            if( v57 )
                                v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
                            else
                                v4->vfptr->set_redraw((TPanel *)v4, RedrawFull);
                        }
                        break;
                    case 9:
                        v59 = v4->vfptr;
                        (*(void (**)(RGE_View *, int, int, int, int, signed int))&v4->vfptr[1].gap10[4])(
                            v4,
                            save_mouse_last_xa,
                            xd,
                            v3,
                            v5,
                            2);
                        v59->set_redraw((TPanel *)v4, RedrawNormal);
                        break;
                }
                v60 = v4->player;
                if( *(float *)&change != v60->view_x || save_view_y != v60->view_y )
                {
                    v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
                    result = 1;
                }
                else
                {
                    result = 0;
                }
                break;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

void RGE_View::end_scroll_view()
{
    RGE_View *v1; // esi@1
    int v2; // edi@3
    int v3; // ebx@3
    int v4; // ecx@5
    int v5; // eax@6
    int v6; // edx@9
    TDrawArea *v7; // ecx@9
    TPanelVtbl *v8; // edi@10
    char v9; // al@11
    POINT point; // [sp+Ch] [bp-8h]@9

    v1 = this;
    switch( this->scroll_action ){
        case 2:
            if( this->mouse_down_x <= this->mouse_last_x )
            {
                v2 = this->mouse_down_x;
                v3 = this->mouse_last_x;
            }
            else
            {
                v2 = this->mouse_last_x;
                v3 = this->mouse_down_x;
            }
            v4 = this->mouse_down_y;
            if( v4 <= v1->mouse_last_y )
            {
                v5 = v1->mouse_down_y;
                v4 = v1->mouse_last_y;
            }
            else
            {
                v5 = v1->mouse_last_y;
            }
            RGE_View::pick_multi(v1, 4, v2, v5, v3, v4);
            v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
            break;
        case 1:
        case 6:
        case 7:
        case 8:
            v6 = this->mouse_down_y;
            point.x = this->mouse_down_x;
            v7 = this->render_area;
            point.y = v6;
            ClientToScreen(v7->Wnd, &point);
            SetCursorPos(point.x, point.y);
            break;
        case 9:
            v8 = this->vfptr;
            (*(void (**)(RGE_View *, int, int, int, int, _DWORD))&this->vfptr[1].gap10[4])(
                this,
                this->mouse_down_x,
                this->mouse_down_y,
                this->mouse_down_x,
                this->mouse_down_y,
                0);
            v8->set_redraw((TPanel *)v1, RedrawNormal);
            break;
        default:
            break;
    }
    v9 = v1->scroll_action;
    if( v9 == 1 || v9 == 2 || v9 == 6 || v9 == 7 || v9 == 8 )
        RGE_Base_Game::mouse_on(rge_base_game);
    TPanel::release_mouse((TPanel *)&v1->vfptr);
    v1->scroll_action = 0;
}

int RGE_View::do_paint(
    int old_x,
    int old_y,
    int new_x,
    int new_y,
    int up_down )
{
    RGE_Pick_Info pick_info;

    if( this->pick(40, 0, new_x, new_y, &pick_info, 0) != 51 ){
        return false;
    }

    int v8 = (signed __int64)pick_info.x;
    int v9 = (signed __int64)pick_info.y;

    this->pick(40, 0, old_x, old_y, &pick_info, 0);

    switch( rge_base_game->game_mode ){

    case 9:

        if( up_down &&
            rge_base_game->terrain_id != -1 ){
            this->map->do_terrain_brush_stroke(
                this->real_old_map_col,
                this->real_old_map_row,
                v8,
                v9,
                rge_base_game->brush_size,
                rge_base_game->terrain_id);
        }
        break;

    case 0xA:

        if( up_down &&
            rge_base_game->elevation_height != -1 ){
            this->map->do_elevation_brush_stroke(
                this->real_old_map_col,
                this->real_old_map_row,
                v8,
                v9,
                rge_base_game->brush_size,
                rge_base_game->elevation_height);
        }
        break;

    case 0x13:

        if( rge_base_game->sub_game_mode == 1 ){
            this->map->do_cliff_brush_stroke(
                this->real_old_map_col,
                this->real_old_map_row,
                v8,
                v9,
                0,
                1);
        }else{
            this->map->do_cliff_brush_stroke(
                this->real_old_map_col,
                this->real_old_map_row,
                v8,
                v9,
                0,
                0);
        }
        this->set_redraw(RedrawFull);
        break;
    }

    this->real_old_map_row = v9;
    this->real_old_map_col = v8;

    return true;
}

void RGE_View::reset_overlay_sprites()
{
    if( this->extra_sprites ){
        do{
            Ov_Sprite_Draw_Rec *v3 = this->extra_sprites->next;
            delete this->extra_sprites;
            this->extra_sprites = v3;
        }
        while( v3 );
    }
    this->extra_sprites = nullptr;
}

void RGE_View::reset_cyclic_overlay_sprites()
{
    RGE_View *v1; // edi@1
    Ov_Sprite_Draw_Rec *v2; // eax@1
    Ov_Sprite_Draw_Rec **v3; // ecx@3
    Ov_Sprite_Draw_Rec *v4; // esi@9

    v1 = this;
    v2 = this->extra_sprites;
    while( v2 )
    {
        if( v2->displayfunction == 1 )
        {
            v3 = &v2->prev->next;
            if( v3 )
                *v3 = v2->next;
            if( v2->next )
                v2->next->prev = v2->prev;
            if( !v2->prev )
                v1->extra_sprites = v2->next;
            v4 = v2->next;
            operator delete(v2);
            v2 = v4;
        }
        else
        {
            v2 = v2->next;
        }
    }
}

void RGE_View::add_overlay_sprite(
    TShape *theShape,
    int facet,
    int x,
    int y,
    int flags,
    int drawlevel,
    char *colorTable,
    int dispFunc,
    unsigned int DrawInterval )
{
    if( Ov_Sprite_Draw_Rec *OvSpriteDrawRec = new Ov_Sprite_Draw_Rec ){

        OvSpriteDrawRec->theShape         = theShape;
        OvSpriteDrawRec->thefacet         = facet;
        OvSpriteDrawRec->world_x          = x;
        OvSpriteDrawRec->world_y          = y;
        OvSpriteDrawRec->flags            = flags;
        OvSpriteDrawRec->drawLevel        = drawlevel;
        OvSpriteDrawRec->colortable       = colorTable;
        OvSpriteDrawRec->displayfunction  = dispFunc;
        OvSpriteDrawRec->DrawTimeInterval = DrawInterval;
        OvSpriteDrawRec->LastDrawTime     = 0;
        OvSpriteDrawRec->prev             = nullptr;
        OvSpriteDrawRec->next             = this->extra_sprites;

        if( this->extra_sprites ){
            this->extra_sprites->prev = OvSpriteDrawRec;
        }
        this->extra_sprites = OvSpriteDrawRec;
    }
}

bool RGE_View::Object_Was_Displayed( int ObjectID, char InFogOK )
{
    if( DClipInfo_Node *v3 = DClipInfo_List::LocateIDbyDrawLevel(this->prior_objs, ObjectID, 6, 40, 0) ){
        return InFogOK || !(v3->Draw_Flag & 1);
    }else{
        return false;
    }
}
