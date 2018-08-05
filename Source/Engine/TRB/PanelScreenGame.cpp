
void TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View()
{
    RGE_Diamond_Map_View::RGE_Diamond_Map_View();

    this->last_attack_time = 0;
    this->flash_on = 0;
}

void TRIBE_Diamond_Map_View::set_redraw( TPanel::RedrawMode redraw_mode )
{
    this->set_redraw(redraw_mode);

    if ( redraw_mode && this->visible && this->active ){
        this->parent_panel->set_map_buttons_redraw(redraw_mode);
    }
}

void TRIBE_Diamond_Map_View::draw_objects()
{
    TRIBE_Diamond_Map_View *v1; // esi@1
    unsigned int v2; // eax@1

    v1 = this;
    v2 = debug_timeGetTime();
    if ( v2 - v1->last_attack_time >= 0x14D )
    {
        v1->flash_on = v1->flash_on == 0;
        v1->last_attack_time = v2;
    }
    RGE_Diamond_Map::draw_objects((RGE_Diamond_Map *)&v1->vfptr);
}

//----- (0052CAB0) --------------------------------------------------------
void TRIBE_Diamond_Map_View::draw_object(short col, short row, char color, short size, RGE_Static_Object *game_obj)
{
    if ( this->draw_objects_mode == 4 )
        color = this->flash_on != 0 ? 86 : -1;
    RGE_Diamond_Map::draw_object((RGE_Diamond_Map *)&this->vfptr, col, row, color, size, game_obj);
}

//----- (0052CAF0) --------------------------------------------------------
void TRIBE_Main_View::draw_multi_object_outline(TRIBE_Main_View *this)
{
    short v1; // ax@1
    TRIBE_Main_View *v2; // ebp@1
    int v3; // ebx@6
    int v4; // ecx@6
    int v5; // edi@6
    int v6; // esi@8
    int v7; // eax@8
    TRIBE_Master_Building_Object *v8; // ebx@11
    int v9; // esi@11
    int v10; // edi@11
    int v11; // esi@15
    TRIBE_Master_Building_Object *v12; // edi@16
    TRIBE_Master_Building_Object *v13; // ebx@20
    int v14; // esi@20
    int v15; // edi@20
    int v16; // esi@23
    TRIBE_Master_Building_Object *v17; // edi@24
    int v18; // esi@29
    int v19; // eax@32
    int v20; // edi@38
    int v21; // esi@39
    int v22; // eax@43
    int v23; // esi@47
    int v24; // ebx@48
    int v25; // edi@48
    int v26; // eax@51
    int v27; // ebx@56
    int v28; // edi@56
    int v29; // eax@59
    int v30; // esi@64
    int v31; // eax@69
    int v32; // eax@77
    int v33; // edi@83
    int v34; // esi@84
    int v35; // ebx@84
    int v36; // eax@87
    int v37; // esi@91
    int v38; // edi@92
    int v39; // eax@96
    int v40; // esi@100
    int v41; // eax@105
    int v42; // esi@110
    int v43; // eax@114
    int calc_row2; // [sp+10h] [bp-48h]@3
    TRIBE_Master_Building_Object *master_bldg; // [sp+14h] [bp-44h]@2
    int end_col; // [sp+18h] [bp-40h]@32
    int end_row; // [sp+1Ch] [bp-3Ch]@29
    int calc_col1; // [sp+20h] [bp-38h]@3
    int start_col; // [sp+24h] [bp-34h]@32
    int calc_col2; // [sp+28h] [bp-30h]@3
    int main_row; // [sp+2Ch] [bp-2Ch]@8
    int main_col; // [sp+30h] [bp-28h]@8
    int calc_row1; // [sp+34h] [bp-24h]@3
    int start_row; // [sp+38h] [bp-20h]@29
    tagPOINT point; // [sp+3Ch] [bp-1Ch]@4
    RGE_Pick_Info pick_info; // [sp+44h] [bp-14h]@5

    v1 = rge_base_game->master_obj_id;
    v2 = this;
    if ( v1 != -1 )
    {
        master_bldg = (TRIBE_Master_Building_Object *)this->player->master_objects[v1];
        if ( master_bldg )
        {
            TDrawArea::SetClipRect(this->render_area, &this->clip_rect);
            if ( RGE_View::get_selection_area((RGE_View *)&v2->vfptr, &calc_col1, &calc_row1, &calc_col2, &calc_row2, 0) )
            {
                v4 = calc_row1;
                v3 = calc_col1;
                v5 = calc_col2;
            }
            else
            {
                RGE_Base_Game::get_mouse_pos(rge_base_game, &point);
                if ( !v2->vfptr->is_inside((TPanel *)v2, point.x, point.y)
                    || RGE_Main_View::pick1(
                             (RGE_Main_View *)&v2->vfptr,
                             40,
                             0,
                             point.x - v2->render_rect.left,
                             point.y - v2->render_rect.top,
                             &pick_info,
                             0,
                             1) != 51 )
                {
                    return;
                }
                RGE_Main_View::fixup_pick_info((RGE_Main_View *)&v2->vfptr, &pick_info);
                v3 = (signed __int64)pick_info.x;
                calc_col1 = (signed __int64)pick_info.x;
                v4 = (signed __int64)pick_info.y;
                v5 = (signed __int64)pick_info.x;
                calc_row1 = (signed __int64)pick_info.y;
                calc_col2 = (signed __int64)pick_info.x;
                calc_row2 = (signed __int64)pick_info.y;
            }
            main_col = -1;
            main_row = -1;
            v6 = abs(calc_row2 - v4);
            v7 = abs(v5 - v3);
            if ( v6 == v7 )
            {
                if ( v5 < v3 )
                {
                    if ( calc_row2 < v4 )
                    {
                        v8 = master_bldg;
                        v9 = v5;
                        v10 = calc_row2;
                        do
                            TRIBE_Main_View::draw_wall_outline(v2, v9++, v10++, v8, 2);
                        while ( v9 <= calc_col1 );
                        TDrawArea::SetClipRect(v2->render_area, 0);
                        return;
                    }
                    if ( v5 < v3 )
                    {
                        v11 = v4;
                        if ( v3 >= v5 )
                        {
                            v12 = master_bldg;
                            do
                                TRIBE_Main_View::draw_wall_outline(v2, v3--, v11++, v12, 2);
                            while ( v3 >= calc_col2 );
                            TDrawArea::SetClipRect(v2->render_area, 0);
                            return;
                        }
                        goto LABEL_117;
                    }
                }
                if ( calc_row2 >= v4 )
                {
                    v16 = v4;
                    if ( v3 > v5 )
                        goto LABEL_117;
                    v17 = master_bldg;
                    do
                        TRIBE_Main_View::draw_wall_outline(v2, v3++, v16++, v17, 2);
                    while ( v3 <= calc_col2 );
                    TDrawArea::SetClipRect(v2->render_area, 0);
                }
                else
                {
                    v13 = master_bldg;
                    v14 = v5;
                    v15 = calc_row2;
                    do
                        TRIBE_Main_View::draw_wall_outline(v2, v14--, v15++, v13, 2);
                    while ( v14 >= calc_col1 );
                    TDrawArea::SetClipRect(v2->render_area, 0);
                }
            }
            else if ( v6 < v7 )
            {
                main_row = v4;
                if ( v5 <= v3 )
                {
                    start_col = v3;
                    end_col = v5;
                }
                else
                {
                    start_col = v5;
                    end_col = v3;
                }
                if ( v4 >= calc_row2 )
                {
                    if ( v4 <= calc_row2 )
                    {
                        v32 = start_row;
                    }
                    else
                    {
                        v32 = calc_row2;
                        main_col = v5;
                        start_row = calc_row2;
                        end_row = v4 - 1;
                    }
                }
                else
                {
                    v32 = v4 + 1;
                    main_col = v5;
                    start_row = v4 + 1;
                    end_row = calc_row2;
                }
                if ( main_col == -1 || v32 > v4 )
                {
                    v40 = start_col;
                    if ( start_col >= end_col )
                    {
                        while ( 1 )
                        {
                            v41 = v40 == v3 || v40 == v5 ? 2 : 0;
                            TRIBE_Main_View::draw_wall_outline(v2, v40--, main_row, master_bldg, v41);
                            if ( v40 < end_col )
                                break;
                            v3 = calc_col1;
                            v5 = calc_col2;
                        }
                        v4 = calc_row1;
                    }
                    if ( main_col != -1 )
                    {
                        v42 = start_row;
                        if ( start_row <= end_row )
                        {
                            while ( 1 )
                            {
                                if ( v42 == v4 || (v43 = 1, v42 == calc_row2) )
                                    v43 = 2;
                                TRIBE_Main_View::draw_wall_outline(v2, main_col, v42++, master_bldg, v43);
                                if ( v42 > end_row )
                                    break;
                                v4 = calc_row1;
                            }
                        }
                    }
                    goto LABEL_117;
                }
                v33 = v32;
                if ( v32 <= end_row )
                {
                    v34 = main_col;
                    v35 = end_row;
                    while ( 1 )
                    {
                        if ( v33 == v4 || (v36 = 1, v33 == calc_row2) )
                            v36 = 2;
                        TRIBE_Main_View::draw_wall_outline(v2, v34, v33++, master_bldg, v36);
                        if ( v33 > v35 )
                            break;
                        v4 = calc_row1;
                    }
                    v3 = calc_col1;
                }
                v37 = start_col;
                if ( start_col < end_col )
                {
LABEL_117:
                    TDrawArea::SetClipRect(v2->render_area, 0);
                    return;
                }
                v38 = end_col;
                while ( 1 )
                {
                    v39 = v37 == v3 || v37 == calc_col2 ? 2 : 0;
                    TRIBE_Main_View::draw_wall_outline(v2, v37--, main_row, master_bldg, v39);
                    if ( v37 < v38 )
                        break;
                    v3 = calc_col1;
                }
                TDrawArea::SetClipRect(v2->render_area, 0);
            }
            else
            {
                main_col = v3;
                if ( calc_row2 <= v4 )
                {
                    start_row = calc_row2;
                    end_row = v4;
                    v18 = calc_row2;
                }
                else
                {
                    v18 = v4;
                    end_row = calc_row2;
                    start_row = v4;
                }
                if ( v3 >= v5 )
                {
                    if ( v3 <= v5 )
                    {
                        v19 = start_col;
                    }
                    else
                    {
                        main_row = calc_row2;
                        v19 = v3 - 1;
                        start_col = v3 - 1;
                        end_col = v5;
                    }
                }
                else
                {
                    main_row = calc_row2;
                    v19 = v5;
                    start_col = v5;
                    end_col = v3 + 1;
                }
                if ( main_row == -1 || v19 < v3 )
                {
                    if ( v18 <= end_row )
                    {
                        v27 = main_col;
                        v28 = end_row;
                        while ( 1 )
                        {
                            if ( v18 == v4 || (v29 = 1, v18 == calc_row2) )
                                v29 = 2;
                            TRIBE_Main_View::draw_wall_outline(v2, v27, v18++, master_bldg, v29);
                            if ( v18 > v28 )
                                break;
                            v4 = calc_row1;
                        }
                        v3 = calc_col1;
                        v5 = calc_col2;
                    }
                    if ( main_row == -1 )
                        goto LABEL_117;
                    v30 = start_col;
                    if ( start_col < end_col )
                        goto LABEL_117;
                    while ( 1 )
                    {
                        v31 = v30 == v3 || v30 == v5 ? 2 : 0;
                        TRIBE_Main_View::draw_wall_outline(v2, v30--, main_row, master_bldg, v31);
                        if ( v30 < end_col )
                            break;
                        v3 = calc_col1;
                        v5 = calc_col2;
                    }
                    TDrawArea::SetClipRect(v2->render_area, 0);
                }
                else
                {
                    v20 = v19;
                    if ( v19 >= end_col )
                    {
                        v21 = end_col;
                        while ( 1 )
                        {
                            v22 = v20 == v3 || v20 == calc_col2 ? 2 : 0;
                            TRIBE_Main_View::draw_wall_outline(v2, v20--, main_row, master_bldg, v22);
                            if ( v20 < v21 )
                                break;
                            v3 = calc_col1;
                        }
                        v4 = calc_row1;
                    }
                    v23 = start_row;
                    if ( start_row > end_row )
                        goto LABEL_117;
                    v24 = main_col;
                    v25 = end_row;
                    while ( 1 )
                    {
                        if ( v23 == v4 || (v26 = 1, v23 == calc_row2) )
                            v26 = 2;
                        TRIBE_Main_View::draw_wall_outline(v2, v24, v23++, master_bldg, v26);
                        if ( v23 > v25 )
                            break;
                        v4 = calc_row1;
                    }
                    TDrawArea::SetClipRect(v2->render_area, 0);
                }
            }
        }
    }
}

//----- (0052D060) --------------------------------------------------------
int TRIBE_Main_View::draw_wall_outline(int col, int row, TRIBE_Master_Building_Object *master_bldg, int facet)
{
    TRIBE_Main_View *v5; // edi@1
    int v6; // edx@2
    RGE_Master_Static_ObjectVtbl *v7; // ebx@2
    unsigned int v8; // eax@4
    int v9; // eax@5
    int v10; // eax@7
    RGE_Game_World *v11; // eax@9
    short x1; // [sp+28h] [bp-1Ch]@2
    short y2; // [sp+2Ah] [bp-1Ah]@2
    int x4; // [sp+2Ch] [bp-18h]@2
    short x2; // [sp+30h] [bp-14h]@2
    short y1; // [sp+32h] [bp-12h]@2
    int scr_y; // [sp+34h] [bp-10h]@1
    int scr_x; // [sp+38h] [bp-Ch]@1
    int x3; // [sp+3Ch] [bp-8h]@2
    int y4; // [sp+40h] [bp-4h]@2
    int cola; // [sp+48h] [bp+4h]@2
    float world_x; // [sp+4Ch] [bp+8h]@2

    v5 = this;
    if ( RGE_View::get_tile_screen_coords((RGE_View *)&this->vfptr, col, row, (short *)&scr_x, (short *)&scr_y, 0) )
    {
        *(float *)&cola = (double)col - -0.5;
        world_x = (double)row - -0.5;
        RGE_Master_Static_Object::alignment_box(
            (RGE_Master_Static_Object *)&master_bldg->vfptr,
            v5->world,
            *(float *)&cola,
            world_x,
            &x1,
            &y1,
            &x2,
            &y2,
            (short *)&x3,
            (short *)&x4 + 1,
            (short *)&x4,
            (short *)&y4);
        LOBYTE(v6) = master_bldg->elevation_flag;
        v7 = master_bldg->vfptr;
        if ( (unsigned __int8)((int (*)(TRIBE_Master_Building_Object *, RGE_Player *, int, _DWORD, _DWORD, signed int, int, _DWORD, signed int, signed int, signed int))master_bldg->vfptr->check_placement)(
                                                        master_bldg,
                                                        v5->player,
                                                        cola,
                                                        LODWORD(world_x),
                                                        0,
                                                        1,
                                                        v6,
                                                        0,
                                                        1,
                                                        1,
                                                        1) )
        {
            v8 = (v5->world->world_time >> 7) & 7;
            if ( v8 >= 4 )
                v9 = 44 - v8;
            else
                v9 = v8 + 36;
            v10 = 16 * v9;
            LOBYTE(v10) = v10 | 9;
            fog_next_shape = v10;
        }
        else
        {
            fog_next_shape = 5;
        }
        if ( master_bldg->sprite )
        {
            scr_x += x3 + (x1 - (signed short)x3) / 2;
            scr_y += y4 + (y2 - (signed short)y4) / 2;
            SDI_Draw_Line = (signed short)scr_y;
            v11 = RGE_Base_Game::get_player(rge_base_game);
            v7->draw(
                (RGE_Master_Static_Object *)master_bldg,
                v5->render_area,
                scr_x,
                scr_y,
                (RGE_Color_Table *)v11[1].world_time,
                facet + 1,
                0,
                0,
                0);
        }
    }
    fog_next_shape = 0;
    return 1;
}

//----- (0052D1F0) --------------------------------------------------------
int TRIBE_Main_View::command_place_object(int x, int y, int reset_mode)
{
    TRIBE_Main_View *v4; // edi@1
    int result; // eax@3
    int v6; // ebp@5
    RGE_Master_Static_Object *v7; // esi@6
    RGE_Master_Static_ObjectVtbl *v8; // ebx@7
    int v9; // ecx@7
    RGE_Pick_Info pick_info; // [sp+40h] [bp-14h]@4

    v4 = this;
    if ( !allow_user_commands )
        goto LABEL_16;
    if ( rge_base_game->game_mode != 7 )
        return RGE_Main_View::command_place_object((RGE_Main_View *)&this->vfptr, x, y, 1);
    if ( RGE_Main_View::pick1((RGE_Main_View *)&this->vfptr, 40, 0, x, y, &pick_info, 0, 1) != 51 )
        goto LABEL_16;
    RGE_Main_View::fixup_pick_info((RGE_Main_View *)&v4->vfptr, &pick_info);
    v6 = rge_base_game->master_obj_id;
    if ( v6 == -1 )
        goto LABEL_16;
    v7 = v4->player->master_objects[v6];
    if ( !v7 )
        goto LABEL_16;
    v8 = v7->vfptr;
    v7->vfptr->alignment(v7, (float *)&pick_info, &pick_info.y, v4->world, 0);
    LOBYTE(v9) = v7->elevation_flag;
    if ( (unsigned __int8)((int (*)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD, signed int, int, _DWORD, signed int, signed int, signed int))v8->check_placement)(
                                                    v7,
                                                    v4->player,
                                                    LODWORD(pick_info.x),
                                                    LODWORD(pick_info.y),
                                                    0,
                                                    1,
                                                    v9,
                                                    0,
                                                    1,
                                                    1,
                                                    1) )
        goto LABEL_16;
    if ( reset_mode || v6 == 109 )
        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
    if ( TRIBE_Player::command_make_building((TRIBE_Player *)v4->player, v6, pick_info.x, pick_info.y) )
        result = 1;
    else
LABEL_16:
        result = 0;
    return result;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0052D320) --------------------------------------------------------
int TRIBE_Main_View::command_place_multi_object(int x1, int y1, int x2, int y2, int reset_mode)
{
    signed int v6; // edi@1
    TRIBE_Main_View *v7; // esi@1
    RGE_Base_Game *v9; // edx@3
    short v10; // ax@3
    int v11; // edi@6
    int v12; // eax@6
    TRIBE_Player *v13; // ecx@19
    int y2a; // [sp+18h] [bp+10h]@6
    TRIBE_Master_Building_Object *reset_modea; // [sp+1Ch] [bp+14h]@5

    v6 = 0;
    v7 = this;
    if ( !allow_user_commands )
        return 0;
    v9 = rge_base_game;
    v10 = rge_base_game->master_obj_id;
    if ( rge_base_game->prog_mode != 7 )
    {
        if ( v10 != -1 )
        {
            v13 = (TRIBE_Player *)this->player;
            if ( v13->master_objects[v10] )
            {
                if ( TRIBE_Player::command_make_wall(v13, v10, x1, y1, x2, y2) )
                    v6 = 1;
                v9 = rge_base_game;
            }
        }
        if ( reset_mode )
            (*(void (**)(RGE_Base_Game *, _DWORD, _DWORD))&v9->vfptr->gap8[8])(v9, 0, 0);
        goto LABEL_25;
    }
    if ( v10 != -1 )
    {
        reset_modea = (TRIBE_Master_Building_Object *)this->player->master_objects[v10];
        if ( reset_modea )
        {
            v11 = y2;
            y2a = abs(y2 - y1);
            v12 = abs(x2 - x1);
            if ( y2a == v12 )
            {
                TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)this->player, reset_modea, x1, y1, x2, v11);
LABEL_17:
                v6 = 1;
                goto LABEL_25;
            }
            if ( y2a < v12 )
            {
                TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)this->player, reset_modea, x1, y1, x2, y1);
                if ( y1 >= v11 )
                {
                    if ( y1 > v11 )
                        TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)v7->player, reset_modea, x2, y1 - 1, x2, v11);
                    goto LABEL_17;
                }
                TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)v7->player, reset_modea, x2, y1 + 1, x2, v11);
                v6 = 1;
            }
            else
            {
                TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)this->player, reset_modea, x1, y1, x1, v11);
                if ( x1 >= x2 )
                {
                    if ( x1 <= x2 )
                        goto LABEL_17;
                    TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)v7->player, reset_modea, x1 - 1, v11, x2, v11);
                    v6 = 1;
                }
                else
                {
                    TRIBE_Main_View::place_line_of_walls((TRIBE_Player *)v7->player, reset_modea, x1 + 1, v11, x2, v11);
                    v6 = 1;
                }
            }
        }
    }
LABEL_25:
    RGE_View::set_selection_area((RGE_View *)&v7->vfptr, -1, -1, -1, -1);
    v7->vfptr->set_redraw((TPanel *)v7, RedrawNormal);
    return v6;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0052D4F0) --------------------------------------------------------
void __stdcall TRIBE_Main_View::place_line_of_walls(TRIBE_Player *player, TRIBE_Master_Building_Object *master_obj, int x1, int y1, int x2, int y2)
{
    int v7; // ecx@1
    TRIBE_Master_Building_Object *v8; // esi@7
    TRIBE_Player *v9; // edi@7
    int x_skip; // [sp+3Ch] [bp-Ch]@2
    int y_skip; // [sp+40h] [bp-8h]@5
    char (*v12)(RGE_Master_Static_Object *, RGE_Player *, float, float, int *, char, char, char, char, char, char); // [sp+44h] [bp-4h]@7
    TRIBE_Player *playera; // [sp+4Ch] [bp+4h]@8
    float world_x; // [sp+50h] [bp+8h]@8
    int world_y; // [sp+54h] [bp+Ch]@7
    int y; // [sp+58h] [bp+10h]@7

    v7 = x1;
    if ( x1 == x2 )
        x_skip = 0;
    else
        x_skip = x2 <= x1 ? -1 : 1;
    if ( y1 == y2 )
        y_skip = 0;
    else
        y_skip = y2 <= y1 ? -1 : 1;
    v8 = master_obj;
    v9 = player;
    world_y = y1;
    y = v7;
    v12 = master_obj->vfptr->check_placement;
    while ( 1 )
    {
        *(float *)&playera = (double)y - -0.5;
        world_x = (double)world_y - -0.5;
        if ( !(unsigned __int8)((int (*)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _BYTE, _DWORD, _DWORD, _DWORD, _DWORD))v12)(
                                                         v8,
                                                         v9,
                                                         playera,
                                                         LODWORD(world_x),
                                                         0,
                                                         1,
                                                         v8->elevation_flag,
                                                         0,
                                                         1,
                                                         1,
                                                         1) )
            ((void (*)(TRIBE_Player *, _DWORD, TRIBE_Player *, float, _DWORD, signed int))v9->vfptr->make_new_object)(
                v9,
                v8->id,
                playera,
                COERCE_FLOAT(LODWORD(world_x)),
                0,
                1);
        if ( y == x2 && world_y == y2 )
            break;
        y += x_skip;
        world_y += y_skip;
    }
}

//----- (0052D600) --------------------------------------------------------
int TRIBE_Main_View::mouse_left_up_action(int x, int y, int ctrl_key, int shift_key)
{
    TRIBE_Main_View *v5; // esi@1
    int v6; // eax@1
    int result; // eax@5
    char v8; // al@8
    char v9; // al@13
    char v10; // al@20
    char v11; // al@25
    char v12; // al@29
    RGE_Static_Object *v13; // eax@31
    RGE_Static_Object *v14; // edi@31
    char v15; // al@34
    RGE_Pick_Info pick_info; // [sp+Ch] [bp-14h]@10

    v5 = this;
    v6 = rge_base_game->prog_mode;
    if ( v6 == 4 || v6 == 6 || v6 == 7 || v6 == 5 )
    {
        if ( RGE_Base_Game::get_paused(rge_base_game) )
        {
LABEL_19:
            result = RGE_Main_View::mouse_left_up_action((RGE_Main_View *)&v5->vfptr, x, y, ctrl_key, shift_key);
        }
        else
        {
            switch ( rge_base_game->game_mode )
            {
                case 0x64:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v8 = v5->mouse_action;
                    if ( v8 != 1 && v8 != 2 )
                        goto LABEL_18;
                    if ( RGE_Main_View::pick1((RGE_Main_View *)&v5->vfptr, 40, 0, x, y, &pick_info, 0, 1) != 51 )
                        goto LABEL_23;
                    RGE_Main_View::fixup_pick_info((RGE_Main_View *)&v5->vfptr, &pick_info);
                    if ( !TRIBE_Player::command_attack_ground((TRIBE_Player *)v5->player, pick_info.x, pick_info.y) )
                        goto LABEL_23;
                    RGE_Main_View::reset_display_object_selection((RGE_Main_View *)&v5->vfptr, 2);
                    RGE_View::add_overlay_sprite(
                        (RGE_View *)&v5->vfptr,
                        rge_base_game->shapes[2],
                        0,
                        x + v5->map_scr_x_offset,
                        y + v5->map_scr_y_offset,
                        0,
                        15,
                        0,
                        2,
                        0x7Du);
                    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
                    goto LABEL_24;
                case 0x66:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v9 = v5->mouse_action;
                    if ( v9 != 1 && v9 != 2 )
                        goto LABEL_18;
                    if ( !((int (*)(TRIBE_Main_View *, int, int, _DWORD, signed int))v5->vfptr[1].set_redraw)(
                                    v5,
                                    x,
                                    y,
                                    0,
                                    105) )
                        goto LABEL_16;
                    goto LABEL_17;
                case 0x65:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v10 = v5->mouse_action;
                    if ( v10 != 1 && v10 != 2 )
                        goto LABEL_18;
                    if ( !((int (*)(TRIBE_Main_View *, int, int, _DWORD, signed int))v5->vfptr[1].set_redraw)(
                                    v5,
                                    x,
                                    y,
                                    0,
                                    104) )
LABEL_23:
                        RGE_Base_Game::play_sound(rge_base_game, 3);
LABEL_24:
                    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                    return 1;
                case 0x67:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v11 = v5->mouse_action;
                    if ( v11 != 1 && v11 != 2 )
                        goto LABEL_18;
                    if ( !((int (*)(TRIBE_Main_View *, int, int, _DWORD, signed int))v5->vfptr[1].set_redraw)(
                                    v5,
                                    x,
                                    y,
                                    0,
                                    7) )
                        goto LABEL_16;
                    goto LABEL_17;
                case 0x68:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v12 = v5->mouse_action;
                    if ( v12 != 1 && v12 != 2 )
                        goto LABEL_18;
                    v13 = RGE_Main_View::pick_best_target((RGE_Main_View *)&v5->vfptr, x, y, 0, -1);
                    v14 = v13;
                    if ( !v13 || !TRIBE_Player::command_make_repair((TRIBE_Player *)v5->player, v13) )
                        goto LABEL_16;
                    RGE_View::display_object_selection((RGE_View *)&v5->vfptr, v14->id, 1500, 2, 2);
                    RGE_View::reset_overlay_sprites((RGE_View *)&v5->vfptr);
                    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
                    goto LABEL_17;
                case 0x69:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v15 = v5->mouse_action;
                    if ( v15 == 1 || v15 == 2 )
                    {
                        if ( RGE_Main_View::pick1((RGE_Main_View *)&v5->vfptr, 40, 0, x, y, &pick_info, 0, 1) == 51
                            && (RGE_Main_View::fixup_pick_info((RGE_Main_View *)&v5->vfptr, &pick_info),
                                    TRIBE_Player::command_make_unload((TRIBE_Player *)v5->player, pick_info.x, pick_info.y)) )
                        {
                            RGE_Main_View::reset_display_object_selection((RGE_Main_View *)&v5->vfptr, 2);
                            RGE_View::add_overlay_sprite(
                                (RGE_View *)&v5->vfptr,
                                rge_base_game->shapes[2],
                                0,
                                x + v5->map_scr_x_offset,
                                y + v5->map_scr_y_offset,
                                0,
                                15,
                                0,
                                2,
                                0x7Du);
                            v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
                        }
                        else
                        {
LABEL_16:
                            RGE_Base_Game::play_sound(rge_base_game, 3);
                        }
LABEL_17:
                        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                    }
LABEL_18:
                    result = 1;
                    break;
                default:
                    goto LABEL_19;
            }
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0052D970) --------------------------------------------------------
int TRIBE_Main_View::mouse_right_up_action(int x, int y, int ctrl_key, int shift_key)
{
    TRIBE_Main_View *v5; // esi@1
    int v6; // eax@1
    int result; // eax@5
    char v8; // al@8
    char v9; // al@13
    char v10; // al@20
    char v11; // al@25
    char v12; // al@29
    RGE_Static_Object *v13; // eax@31
    RGE_Static_Object *v14; // edi@31
    char v15; // al@34
    RGE_Pick_Info pick_info; // [sp+Ch] [bp-14h]@10

    v5 = this;
    v6 = rge_base_game->prog_mode;
    if ( v6 == 4 || v6 == 6 || v6 == 7 || v6 == 5 )
    {
        if ( RGE_Base_Game::get_paused(rge_base_game) )
        {
LABEL_19:
            result = RGE_Main_View::mouse_right_up_action((RGE_Main_View *)&v5->vfptr, x, y, ctrl_key, shift_key);
        }
        else
        {
            switch ( rge_base_game->game_mode )
            {
                case 0x64:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v8 = v5->mouse_action;
                    if ( v8 != 1 && v8 != 2 )
                        goto LABEL_18;
                    if ( RGE_Main_View::pick1((RGE_Main_View *)&v5->vfptr, 40, 0, x, y, &pick_info, 0, 1) != 51 )
                        goto LABEL_23;
                    RGE_Main_View::fixup_pick_info((RGE_Main_View *)&v5->vfptr, &pick_info);
                    if ( !TRIBE_Player::command_attack_ground((TRIBE_Player *)v5->player, pick_info.x, pick_info.y) )
                        goto LABEL_23;
                    RGE_Main_View::reset_display_object_selection((RGE_Main_View *)&v5->vfptr, 2);
                    RGE_View::add_overlay_sprite(
                        (RGE_View *)&v5->vfptr,
                        rge_base_game->shapes[2],
                        0,
                        x + v5->map_scr_x_offset,
                        y + v5->map_scr_y_offset,
                        0,
                        15,
                        0,
                        2,
                        0x7Du);
                    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
                    goto LABEL_24;
                case 0x66:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v9 = v5->mouse_action;
                    if ( v9 != 1 && v9 != 2 )
                        goto LABEL_18;
                    if ( !((int (*)(TRIBE_Main_View *, int, int, _DWORD, signed int))v5->vfptr[1].set_redraw)(
                                    v5,
                                    x,
                                    y,
                                    0,
                                    105) )
                        goto LABEL_16;
                    goto LABEL_17;
                case 0x65:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v10 = v5->mouse_action;
                    if ( v10 != 1 && v10 != 2 )
                        goto LABEL_18;
                    if ( !((int (*)(TRIBE_Main_View *, int, int, _DWORD, signed int))v5->vfptr[1].set_redraw)(
                                    v5,
                                    x,
                                    y,
                                    0,
                                    104) )
LABEL_23:
                        RGE_Base_Game::play_sound(rge_base_game, 3);
LABEL_24:
                    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                    return 1;
                case 0x67:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v11 = v5->mouse_action;
                    if ( v11 != 1 && v11 != 2 )
                        goto LABEL_18;
                    if ( !((int (*)(TRIBE_Main_View *, int, int, _DWORD, signed int))v5->vfptr[1].set_redraw)(
                                    v5,
                                    x,
                                    y,
                                    0,
                                    7) )
                        goto LABEL_16;
                    goto LABEL_17;
                case 0x68:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v12 = v5->mouse_action;
                    if ( v12 != 1 && v12 != 2 )
                        goto LABEL_18;
                    v13 = RGE_Main_View::pick_best_target((RGE_Main_View *)&v5->vfptr, x, y, 0, -1);
                    v14 = v13;
                    if ( !v13 || !TRIBE_Player::command_make_repair((TRIBE_Player *)v5->player, v13) )
                        goto LABEL_16;
                    RGE_View::display_object_selection((RGE_View *)&v5->vfptr, v14->id, 1500, 2, 2);
                    RGE_View::reset_overlay_sprites((RGE_View *)&v5->vfptr);
                    v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
                    goto LABEL_17;
                case 0x69:
                    TPanel::release_mouse((TPanel *)&v5->vfptr);
                    v15 = v5->mouse_action;
                    if ( v15 == 1 || v15 == 2 )
                    {
                        if ( RGE_Main_View::pick1((RGE_Main_View *)&v5->vfptr, 40, 0, x, y, &pick_info, 0, 1) == 51
                            && (RGE_Main_View::fixup_pick_info((RGE_Main_View *)&v5->vfptr, &pick_info),
                                    TRIBE_Player::command_make_unload((TRIBE_Player *)v5->player, pick_info.x, pick_info.y)) )
                        {
                            RGE_Main_View::reset_display_object_selection((RGE_Main_View *)&v5->vfptr, 2);
                            RGE_View::add_overlay_sprite(
                                (RGE_View *)&v5->vfptr,
                                rge_base_game->shapes[2],
                                0,
                                x + v5->map_scr_x_offset,
                                y + v5->map_scr_y_offset,
                                0,
                                15,
                                0,
                                2,
                                0x7Du);
                            v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
                        }
                        else
                        {
LABEL_16:
                            RGE_Base_Game::play_sound(rge_base_game, 3);
                        }
LABEL_17:
                        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                    }
LABEL_18:
                    result = 1;
                    break;
                default:
                    goto LABEL_19;
            }
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0052DCE0) --------------------------------------------------------
int __stdcall TRIBE_Main_View::pick_through_fog(RGE_Static_Object *obj)
{
    int result; // eax@3

    if ( obj && obj->master_obj->id == 45 )
        result = 1;
    else
        result = RGE_View::pick_through_fog(obj);
    return result;
}

//----- (0052DD10) --------------------------------------------------------
int TRIBE_Main_View::pick_weight(RGE_Static_Object *obj, int confidence)
{
    RGE_Static_Object *v3; // esi@1
    RGE_Master_Static_Object *v4; // eax@1
    char v5; // dl@1
    short v6; // ax@1
    int v7; // edx@8
    int result; // eax@10
    char obja; // [sp+8h] [bp+4h]@1

    v3 = obj;
    v4 = obj->master_obj;
    v5 = v4->select_level;
    v6 = v4->id;
    obja = v5;
    if ( v6 == 79 || v6 == 199 || v6 == 69 || v6 == 278 )
        obja = 3;
    v7 = this->UC_ObjectTouched && this->UC_TouchedObj == v3->id;
    result = 0;
    if ( obja != 2 )
    {
        if ( obja != 3 )
        {
            if ( obja == 4 )
            {
                if ( v7 )
                {
                    result = 5;
                }
                else if ( confidence == 1 || confidence == 2 )
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
        if ( v7 )
            return 5;
        if ( confidence != 1 && confidence != 2 )
        {
            if ( confidence == 3 && v3->object_state < 2u )
                result = 2;
            return result;
        }
        return 3;
    }
    if ( v7 )
        return 5;
    if ( confidence == 1 || confidence == 2 )
        return 3;
    if ( confidence == 3 )
        result = 2;
    return result;
}

//----- (0052DE20) --------------------------------------------------------
int TRIBE_Main_View::command_make_do(int x, int y, int work_on_tile, short action_type)
{
    return RGE_Main_View::command_make_do((RGE_Main_View *)&this->vfptr, x, y, work_on_tile, action_type);
}

//----- (0052DE40) --------------------------------------------------------
int TRIBE_Main_View::mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key)
{
    TRIBE_Main_View *v5; // edi@1
    RGE_Static_Object *v6; // eax@2
    RGE_Player *v7; // ecx@3
    RGE_Master_Static_Object *v8; // eax@7
    short v9; // bx@7
    RGE_Object_Node *i; // ebp@9
    RGE_Static_Object *v11; // esi@10
    RGE_Master_Static_Object *v12; // eax@10
    int result; // eax@15
    RGE_Pick_Info pick_info; // [sp+10h] [bp-14h]@1
    char ya; // [sp+2Ch] [bp+8h]@7

    v5 = this;
    if ( RGE_Main_View::pick1((RGE_Main_View *)&this->vfptr, 41, 1, x, y, &pick_info, 0, 1) != 52
        || (v6 = pick_info.object, pick_info.object->master_obj->select_level != 4)
        || (v7 = v5->player, pick_info.object->owner != v7) )
    {
        result = 0;
    }
    else
    {
        if ( !ctrl_key && !shift_key )
        {
            RGE_Player::unselect_object(v7);
            v6 = pick_info.object;
        }
        RGE_Player::select_one_object(v5->player, v6, 0);
        v8 = pick_info.object->master_obj;
        v9 = v8->id;
        ya = v8->unit_level;
        if ( ya != 3 )
            ya = -1;
        for ( i = v5->player->objects->list; i; i = i->next )
        {
            v11 = i->node;
            v12 = i->node->master_obj;
            if ( (v12->id == v9 || v12->unit_level == ya)
                && RGE_View::Object_Was_Displayed((RGE_View *)&v5->vfptr, v11->id, 0) )
            {
                RGE_Player::select_one_object(v5->player, v11, 0);
            }
        }
        RGE_Player::select_one_object(v5->player, pick_info.object, 0);
        result = 1;
    }
    return result;
}
