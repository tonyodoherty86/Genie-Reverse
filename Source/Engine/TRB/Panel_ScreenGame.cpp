
//----- (00493D60) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::TRIBE_Screen_Game(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    int v2; // eax@1
    signed int v3; // edi@1
    int *v4; // ebp@1
    TShape *v5; // eax@4
    TShape *v6; // eax@5
    TShape *v7; // eax@9
    TShape *v8; // eax@10
    TShape *v9; // eax@14
    TShape *v10; // eax@15
    signed int v11; // edi@19
    TShape **v12; // ebp@19
    TShape *v13; // eax@21
    TShape *v14; // eax@22
    TShape *v15; // eax@23
    RGE_Main_View *v16; // eax@29
    RGE_Main_View *v17; // edi@29
    RGE_View *v18; // ecx@30
    RGE_Player *v19; // eax@35
    TRIBE_Diamond_Map_View *v20; // eax@35
    RGE_Diamond_Map *v21; // eax@36
    RGE_Player *v22; // eax@41
    RGE_Font *v23; // ebp@41
    TRIBE_Panel_Inven *v24; // edi@41
    RGE_Game_World *v25; // eax@42
    TPanel *v26; // eax@42
    RGE_Font *v27; // edi@46
    TRIBE_Panel_Object *v28; // ebp@46
    RGE_Game_World *v29; // eax@47
    TPanel *v30; // eax@47
    signed int v31; // ebp@51
    TButtonPanel **v32; // edi@51
    TRIBE_Panel_Button *v33; // eax@52
    TShape *v34; // ecx@54
    int v35; // eax@56
    int *v36; // edi@61
    RGE_Base_GameVtbl *v37; // ebp@62
    int v38; // eax@62
    char *v39; // eax@62
    RGE_Font *v40; // edi@65
    TMessagePanel *v41; // eax@65
    TMessagePanel *v42; // eax@66
    TRIBE_Panel_Time *v43; // eax@76
    TRIBE_Panel_Time *v44; // eax@77
    TRIBE_Panel_Pop *v45; // eax@81
    TRIBE_Panel_Pop *v46; // eax@82
    signed int v47; // edi@86
    TRIBE_Panel_Time **v48; // ebp@86
    TRIBE_Panel_Time *v49; // eax@87
    TRIBE_Panel_Time *v50; // eax@88
    RGE_Font *v51; // edi@93
    TMessagePanel *v52; // eax@93
    TMessagePanel *v53; // eax@94
    TMessagePanel *v54; // eax@96
    TMessagePanel *v55; // eax@97
    TMessagePanel *v56; // eax@99
    TMessagePanel *v57; // eax@100
    TMessagePanel *v58; // eax@102
    TMessagePanel *v59; // eax@103
    TMessagePanel *v60; // eax@105
    TMessagePanel *v61; // eax@106
    TMessagePanel *v62; // eax@108
    TMessagePanel *v63; // eax@109
    TMessagePanel *v64; // ecx@111
    TMessagePanel *v65; // edx@113
    TMessagePanel *v66; // edx@115
    TMessagePanel *v67; // edx@117
    RGE_Font *v68; // ebp@127
    TMessagePanel **v69; // edi@127
    TMessagePanel *v70; // eax@128
    TMessagePanel *v71; // eax@129
    bool v72; // sf@134
    unsigned __int8 v73; // of@134
    RGE_Font *v74; // edi@135
    TTextPanel *v75; // eax@135
    TTextPanel *v76; // eax@136
    RGE_Font *v77; // edi@144
    TTextPanel *v78; // eax@144
    TTextPanel *v79; // eax@145
    TTextPanel *v80; // ecx@151
    int v81; // ebp@156
    signed int v82; // edi@157
    int v83; // ebp@165
    int v84; // edi@166
    TMessagePanel *v85; // eax@167
    int *v86; // eax@168
    int v87; // edx@170
    TRIBE_Main_View *v88; // ST110_4@170
    TDrawArea *v89; // ST10C_4@170
    TTextPanel **v90; // edi@174
    RGE_Font *v91; // edi@178
    TDigital **v92; // ebp@178
    RGE_Panel_Tool_Box *v93; // eax@178
    RGE_Panel_Tool_Box *v94; // eax@179
    TPanel **v95; // edi@183
    signed int v96; // ebp@183
    int v97; // ST124_4@185
    RGE_Game_World *v98; // eax@185
    TRIBE_Panel_Time *v99; // ecx@185
    TRIBE_Panel_Time **v100; // edi@185
    signed int v101; // ebp@185
    RGE_Font *font; // [sp+138h] [bp-21Ch]@51
    RGE_Font *fonta; // [sp+138h] [bp-21Ch]@61
    RGE_Font *fontb; // [sp+138h] [bp-21Ch]@127
    RGE_Font *fontc; // [sp+138h] [bp-21Ch]@156
    TDigital **num_game_players; // [sp+140h] [bp-214h]@51
    int num_game_playersa; // [sp+140h] [bp-214h]@162
    char str[512]; // [sp+148h] [bp-20Ch]@20
    int v109; // [sp+350h] [bp-4h]@1

    v1 = this;
    TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aGameScreen);
    v1->vfptr = (TPanelVtbl *)&TRIBE_Screen_Game::`vftable';
    displayPathingFlags = 0;
    allow_user_commands = do_fixed_update == 0;
    die_die_die = 0;
    v1->game_screen_pic = 0;
    v1->button_border1_pic = 0;
    v1->button_other_pic = 0;
    v1->button_border2_pic = 0;
    v1->button_border3_pic = 0;
    v1->button_cmd_pic = 0;
    v1->button_tech_pic = 0;
    v2 = (int)v1->button_bldg_pics;
    v1->button_unit_pic = 0;
    v1->more_cancel_pic = 0;
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 4) = 0;
    v109 = 0;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 12) = 0;
    *(_DWORD *)(v2 + 16) = 0;
    v1->main_view = 0;
    v1->map_view = 0;
    v1->inven_panel = 0;
    v1->object_panel = 0;
    v1->age_panel = 0;
    v1->fps_panel = 0;
    memset(v1->score_panel, 0, sizeof(v1->score_panel));
    v1->log_text = 0;
    v1->log_scrollbar = 0;
    memset(v1->button_panel, 0, sizeof(v1->button_panel));
    v1->text_line_panel = 0;
    v1->quit_message_panel = 0;
    v1->time_panel = 0;
    v1->pop_panel = 0;
    memset(v1->countdown_clock, 0, sizeof(v1->countdown_clock));
    v1->message_panel = 0;
    v1->message_panel2 = 0;
    v1->message_panel3 = 0;
    v1->message_panel4 = 0;
    v1->message_panel5 = 0;
    v1->message_panel6 = 0;
    memset(v1->chat_panel, 0, sizeof(v1->chat_panel));
    v1->tool_box = 0;
    v1->help_mode = 0;
    v1->cheat_code_entry = 0;
    v1->cheat_code_entry_str[0] = 0;
    v1->world = (TRIBE_World *)rge_base_game->world;
    v1->update_interval = rge_base_game->prog_info->update_interval;
    v1->last_update_time = debug_timeGetTime();
    v1->map_redraw_interval = 333;
    v1->last_map_redraw_time = debug_timeGetTime();
    v1->game_obj = 0;
    v1->tech_list = 0;
    v1->make_list = 0;
    v1->bldg_list = 0;
    v1->trade_list = 0;
    v1->item_cnt = 0;
    v1->start_item = 0;
    v1->last_item = -1;
    v1->terrain_sound_interval = 0;
    v1->last_terrain_sound_time = 0;
    v1->terrain_sound = 0;
    v1->terrain_playing = 0;
    v1->terrain_sound_start_time = 0;
    v1->anim_pal = 1;
    v1->anim_pal_interval = 0;
    v1->last_anim_pal_time = 0;
    v1->last_anim_pal_index = 0;
    v1->last_anim_pal_index2 = 0;
    v1->last_anim_pal_index3 = 0;
    v1->mouse_last_x = -1;
    v1->mouse_last_y = -1;
    v1->save_age = 0;
    v1->save_culture = -1;
    v1->save_screen_width = 0;
    v1->game_over_time = 0;
    v1->showing_game_over = 0;
    v1->chat_line = 0;
    v1->view_interval = 100;
    v1->last_view_time = debug_timeGetTime();
    v1->player_quit = 0;
    v1->view_town_center_hotkey = *TPanel::get_string(4159);
    v1->work_hotkey = 0;
    v1->move_hotkey = *TPanel::get_string(4170);
    v1->attack_hotkey = 0;
    v1->ungroup_hotkey = *TPanel::get_string(4154);
    v1->watch_hotkey = 65;
    v3 = 0;
    v4 = v1->select_building_hotkey;
    do
    {
        *v4 = *TPanel::get_string(v3++ + 4160);
        ++v4;
    }
    while ( v3 < 8 );
    v1->reset_after_update = 1;
    v1->score_interval = 3000;
    v1->last_score_time = debug_timeGetTime();
    v1->watch_mode = 0;
    v1->game_ended = 0;
    v1->game_over_sound = 0;
    v1->last_game_speed_change = 0;
    v1->last_pause_change = 0;
    if ( !TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, aScr6, 50056, 1) )
        goto LABEL_191;
    v5 = (TShape *)operator new(0x20u);
    LOBYTE(v109) = 1;
    if ( v5 )
        TShape::TShape(v5, aBtnunit_shp, 50730);
    else
        v6 = 0;
    LOBYTE(v109) = 0;
    v1->button_unit_pic = v6;
    if ( !v6 || !TShape::is_loaded(v6) )
        goto LABEL_191;
    v7 = (TShape *)operator new(0x20u);
    LOBYTE(v109) = 2;
    if ( v7 )
        TShape::TShape(v7, aBtntech_shp, 50729);
    else
        v8 = 0;
    LOBYTE(v109) = 0;
    v1->button_tech_pic = v8;
    if ( !v8 || !TShape::is_loaded(v8) )
        goto LABEL_191;
    v9 = (TShape *)operator new(0x20u);
    LOBYTE(v109) = 3;
    if ( v9 )
        TShape::TShape(v9, aBtncmd_shp, 50721);
    else
        v10 = 0;
    LOBYTE(v109) = 0;
    v1->button_cmd_pic = v10;
    if ( !v10 || !TShape::is_loaded(v10) )
        goto LABEL_191;
    v11 = 0;
    v12 = v1->button_bldg_pics;
    do
    {
        sprintf(str, aBtnbldgD_shp, v11);
        if ( v11 >= 4 )
        {
            v15 = (TShape *)operator new(0x20u);
            LOBYTE(v109) = 5;
            if ( !v15 )
            {
LABEL_25:
                v14 = 0;
                goto LABEL_26;
            }
            TShape::TShape(v15, str, 53005);
        }
        else
        {
            v13 = (TShape *)operator new(0x20u);
            LOBYTE(v109) = 4;
            if ( !v13 )
                goto LABEL_25;
            TShape::TShape(v13, str, v11 + 50704);
        }
LABEL_26:
        LOBYTE(v109) = 0;
        *v12 = v14;
        if ( !v14 || !TShape::is_loaded(v14) )
            goto LABEL_190;
        ++v11;
        ++v12;
    }
    while ( v11 < 5 );
    v16 = (RGE_Main_View *)operator new(0x380u);
    v17 = v16;
    LOBYTE(v109) = 6;
    if ( v16 )
    {
        RGE_Main_View::RGE_Main_View(v16);
        v17->vfptr = (TPanelVtbl *)&TRIBE_Main_View::`vftable';
        v18 = (RGE_View *)v17;
    }
    else
    {
        v18 = 0;
    }
    LOBYTE(v109) = 0;
    v1->main_view = (TRIBE_Main_View *)v18;
    if ( !v18 || v18->error_code )
    {
LABEL_190:
        v1->error_code = 1;
        return;
    }
    if ( RGE_View::setup(v18, v1->render_area, (TPanel *)&v1->vfptr, 0, 0, 0, 0, 0, 1, border_line_file) )
    {
        RGE_View::set_world((RGE_View *)&v1->main_view->vfptr, (RGE_Game_World *)&v1->world->vfptr);
        v19 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_View::set_player((RGE_View *)&v1->main_view->vfptr, v19);
        v20 = (TRIBE_Diamond_Map_View *)operator new(0x174u);
        LOBYTE(v109) = 7;
        if ( v20 )
            TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View(v20);
        else
            v21 = 0;
        LOBYTE(v109) = 0;
        v1->map_view = (TRIBE_Diamond_Map_View *)v21;
        if ( v21 )
        {
            if ( !v21->error_code
                && RGE_Diamond_Map::setup(
                         v21,
                         v1->render_area,
                         (TPanel *)&v1->vfptr,
                         0,
                         0,
                         0,
                         0,
                         0,
                         0,
                         rge_base_game->map_save_area) )
            {
                TPanel::set_help_info((TPanel *)&v1->map_view->vfptr, 20019, -1);
                RGE_Diamond_Map::set_world((RGE_Diamond_Map *)&v1->map_view->vfptr, (RGE_Game_World *)&v1->world->vfptr);
                RGE_Diamond_Map::set_bitmap((RGE_Diamond_Map *)&v1->map_view->vfptr, map_bmp, 50401);
                v22 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                RGE_Diamond_Map::set_player((RGE_Diamond_Map *)&v1->map_view->vfptr, v22);
                v1->map_view->main_view = (RGE_View *)&v1->main_view->vfptr;
                v23 = RGE_Base_Game::get_font(rge_base_game, 11);
                v24 = (TRIBE_Panel_Inven *)operator new(0x118u);
                LOBYTE(v109) = 8;
                if ( v24 )
                {
                    v25 = RGE_Base_Game::get_player(rge_base_game);
                    TRIBE_Panel_Inven::TRIBE_Panel_Inven(
                        v24,
                        v1->render_area,
                        (TPanel *)&v1->vfptr,
                        v23->font,
                        (TRIBE_Player *)v25);
                }
                else
                {
                    v26 = 0;
                }
                LOBYTE(v109) = 0;
                v1->inven_panel = (TRIBE_Panel_Inven *)v26;
                if ( v26 && !v26->error_code )
                {
                    TPanel::set_help_info(v26, 20005, -1);
                    v27 = RGE_Base_Game::get_font(rge_base_game, 7);
                    v28 = (TRIBE_Panel_Object *)operator new(0x214u);
                    LOBYTE(v109) = 9;
                    if ( v28 )
                    {
                        v29 = RGE_Base_Game::get_player(rge_base_game);
                        TRIBE_Panel_Object::TRIBE_Panel_Object(
                            v28,
                            v1->render_area,
                            (TPanel *)&v1->vfptr,
                            v27->font,
                            v27->font_wid,
                            v27->font_hgt,
                            v1->button_unit_pic,
                            v1->button_bldg_pics,
                            (TRIBE_Player *)v29);
                    }
                    else
                    {
                        v30 = 0;
                    }
                    LOBYTE(v109) = 0;
                    v1->object_panel = (TRIBE_Panel_Object *)v30;
                    if ( v30 )
                    {
                        if ( !v30->error_code )
                        {
                            TPanel::set_help_info(v30, 105400, 157100);
                            font = RGE_Base_Game::get_font(rge_base_game, 11);
                            num_game_players = RGE_Base_Game::get_sound(rge_base_game, 1);
                            v31 = 0;
                            v32 = (TButtonPanel **)v1->button_panel;
                            while ( 1 )
                            {
                                v33 = (TRIBE_Panel_Button *)operator new(0x3D4u);
                                LOBYTE(v109) = 10;
                                if ( v33 )
                                {
                                    v34 = v31 >= 12 ? v1->button_border2_pic : v1->button_border1_pic;
                                    TRIBE_Panel_Button::TRIBE_Panel_Button(
                                        v33,
                                        v1->render_area,
                                        (TPanel *)&v1->vfptr,
                                        (TDigital *)num_game_players,
                                        font->font,
                                        font->font_wid,
                                        font->font_hgt,
                                        v34);
                                }
                                else
                                {
                                    v35 = 0;
                                }
                                LOBYTE(v109) = 0;
                                *v32 = (TButtonPanel *)v35;
                                if ( !v35 || *(_DWORD *)(v35 + 216) )
                                    break;
                                TButtonPanel::set_text_color((TButtonPanel *)v35, 0, 0, 0xFFFFFFu);
                                TButtonPanel::set_sound_number(*v32, 1);
                                ++v31;
                                ++v32;
                                if ( v31 >= 17 )
                                {
                                    v36 = (int *)&v1->button_panel[12];
                                    TButtonPanel::set_id((TButtonPanel *)v1->button_panel[12], 0, 13, 0);
                                    TPanel::set_help_info((TPanel *)v1->button_panel[12], 120015, -1);
                                    TButtonPanel::set_id((TButtonPanel *)v1->button_panel[13], 0, 14, 0);
                                    TPanel::set_help_info((TPanel *)v1->button_panel[13], 120017, -1);
                                    TButtonPanel::set_id((TButtonPanel *)v1->button_panel[14], 0, 15, 0);
                                    TPanel::set_help_info((TPanel *)v1->button_panel[14], 120013, -1);
                                    TButtonPanel::set_id((TButtonPanel *)v1->button_panel[15], 0, 21, 0);
                                    TPanel::set_help_info((TPanel *)v1->button_panel[15], 120027, -1);
                                    TButtonPanel::set_id((TButtonPanel *)v1->button_panel[16], 0, 24, 0);
                                    TPanel::set_help_info((TPanel *)v1->button_panel[16], 120028, -1);
                                    fonta = (RGE_Font *)3;
                                    do
                                    {
                                        TButtonPanel::setDrawType(*v36, 3);
                                        *(_BYTE *)(*v36 + 704) = 3;
                                        v37 = rge_base_game->vfptr;
                                        v38 = TButtonPanel::get_id((TButtonPanel *)*v36);
                                        v39 = (char *)(*(int (__thiscall **)(RGE_Base_Game *, signed int, int, _DWORD, char *, signed int))&v37->gap28[0])(
                                                                        rge_base_game,
                                                                        102,
                                                                        v38,
                                                                        0,
                                                                        str,
                                                                        512);
                                        TButtonPanel::set_text((TButtonPanel *)*v36, 0, v39);
                                        TButtonPanel::set_bevel_info(
                                            (TButtonPanel *)*v36,
                                            3,
                                            v1->bevel_color1,
                                            v1->bevel_color2,
                                            v1->bevel_color3,
                                            v1->bevel_color4,
                                            v1->bevel_color5,
                                            v1->bevel_color6);
                                        ++v36;
                                        fonta = (RGE_Font *)((char *)fonta - 1);
                                    }
                                    while ( fonta );
                                    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 )
                                        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v1->button_panel[12] + 20))(0);
                                    TButtonPanel::setDrawType((int)v1->button_panel[15], 3);
                                    TButtonPanel::set_bevel_info(
                                        (TButtonPanel *)v1->button_panel[15],
                                        4,
                                        v1->bevel_color1,
                                        v1->bevel_color2,
                                        v1->bevel_color3,
                                        v1->bevel_color4,
                                        v1->bevel_color5,
                                        v1->bevel_color6);
                                    *((_BYTE *)v1->button_panel[15] + 704) = 3;
                                    TButtonPanel::set_text((TButtonPanel *)v1->button_panel[15], 0, 4009);
                                    TButtonPanel::setDrawType((int)v1->button_panel[16], 3);
                                    TButtonPanel::set_bevel_info(
                                        (TButtonPanel *)v1->button_panel[16],
                                        4,
                                        v1->bevel_color1,
                                        v1->bevel_color2,
                                        v1->bevel_color3,
                                        v1->bevel_color4,
                                        v1->bevel_color5,
                                        v1->bevel_color6);
                                    *((_BYTE *)v1->button_panel[16] + 704) = 3;
                                    TButtonPanel::set_text((TButtonPanel *)v1->button_panel[16], 0, 4131);
                                    TPanel::get_string(4132, str, 512);
                                    TRIBE_Panel_Button::set_text_msg(v1->button_panel[16], str);
                                    v40 = RGE_Base_Game::get_font(rge_base_game, 11);
                                    v41 = (TMessagePanel *)operator new(0x380u);
                                    LOBYTE(v109) = 11;
                                    if ( v41 )
                                        TMessagePanel::TMessagePanel(v41, v40->font, v40->font_wid, v40->font_hgt);
                                    else
                                        v42 = 0;
                                    LOBYTE(v109) = 0;
                                    v1->text_line_panel = v42;
                                    if ( !v42 || v42->error_code )
                                        goto LABEL_189;
                                    if ( !(*(int (__thiscall **)(TMessagePanel *, TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v42->vfptr->gap4[0])(
                                                    v42,
                                                    v1->render_area,
                                                    v1->main_view,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0) )
                                    {
                                        v1->error_code = 1;
                                        return;
                                    }
                                    TMessagePanel::set_justification(v1->text_line_panel, LeftJust, BottomJust, 1);
                                    v1->main_view->message_panel = v1->text_line_panel;
                                    TEasy_Panel::create_text(
                                        (TEasy_Panel *)&v1->vfptr,
                                        (TPanel *)&v1->main_view->vfptr,
                                        &v1->quit_message_panel,
                                        9006,
                                        0,
                                        0,
                                        600,
                                        60,
                                        11,
                                        1,
                                        1,
                                        0);
                                    if ( v1->quit_message_panel )
                                    {
                                        TTextPanel::set_text_color(v1->quit_message_panel, 0xFFFFFFu, 0);
                                        (*(void (__thiscall **)(TTextPanel *, _DWORD))&v1->quit_message_panel->vfptr->gap10[4])(
                                            v1->quit_message_panel,
                                            0);
                                    }
                                    TEasy_Panel::create_text(
                                        (TEasy_Panel *)&v1->vfptr,
                                        (TPanel *)&v1->main_view->vfptr,
                                        &v1->pause_text,
                                        9001,
                                        0,
                                        0,
                                        600,
                                        60,
                                        1,
                                        1,
                                        1,
                                        0);
                                    if ( v1->pause_text )
                                    {
                                        TTextPanel::set_text_color(v1->pause_text, 0xFFFFFFu, 0);
                                        (*(void (__thiscall **)(TTextPanel *, _DWORD))&v1->pause_text->vfptr->gap10[4])(v1->pause_text, 0);
                                    }
                                    v43 = (TRIBE_Panel_Time *)operator new(0x174u);
                                    LOBYTE(v109) = 12;
                                    if ( v43 )
                                        TRIBE_Panel_Time::TRIBE_Panel_Time(v43, v1->render_area, (TPanel *)&v1->main_view->vfptr);
                                    else
                                        v44 = 0;
                                    if ( (LOBYTE(v109) = 0, (v1->time_panel = v44) == 0)
                                        || v44->error_code
                                        || (((*(void (__thiscall **)(TRIBE_Panel_Time *, _DWORD))&v44->vfptr->gap10[4])(v44, 0),
                                                 v45 = (TRIBE_Panel_Pop *)operator new(0x164u),
                                                 LOBYTE(v109) = 13,
                                                 !v45) ? (v46 = 0) : TRIBE_Panel_Pop::TRIBE_Panel_Pop(
                                                                                             v45,
                                                                                             v1->render_area,
                                                                                             (TPanel *)&v1->main_view->vfptr),
                                                (LOBYTE(v109) = 0, (v1->pop_panel = v46) == 0) || v46->error_code) )
                                    {
LABEL_189:
                                        v1->error_code = 1;
                                        return;
                                    }
                                    (*(void (__thiscall **)(TRIBE_Panel_Pop *, _DWORD))&v46->vfptr->gap10[4])(v46, 0);
                                    v47 = 0;
                                    v48 = v1->countdown_clock;
                                    while ( 1 )
                                    {
                                        v49 = (TRIBE_Panel_Time *)operator new(0x174u);
                                        LOBYTE(v109) = 14;
                                        if ( v49 )
                                            TRIBE_Panel_Time::TRIBE_Panel_Time(v49, v1->render_area, (TPanel *)&v1->main_view->vfptr);
                                        else
                                            v50 = 0;
                                        LOBYTE(v109) = 0;
                                        *v48 = v50;
                                        if ( !v50 || v50->error_code )
                                            goto LABEL_190;
                                        (*(void (__thiscall **)(TRIBE_Panel_Time *, _DWORD))&v50->vfptr->gap10[4])(v50, 0);
                                        ++v47;
                                        ++v48;
                                        if ( v47 >= 10 )
                                        {
                                            RGE_Base_Game::get_sound(rge_base_game, 1);
                                            v51 = RGE_Base_Game::get_font(rge_base_game, 11);
                                            v52 = (TMessagePanel *)operator new(0x380u);
                                            LOBYTE(v109) = 15;
                                            if ( v52 )
                                                TMessagePanel::TMessagePanel(v52, v51->font, v51->font_wid, v51->font_hgt);
                                            else
                                                v53 = 0;
                                            LOBYTE(v109) = 0;
                                            v1->message_panel = v53;
                                            v54 = (TMessagePanel *)operator new(0x380u);
                                            LOBYTE(v109) = 16;
                                            if ( v54 )
                                                TMessagePanel::TMessagePanel(v54, v51->font, v51->font_wid, v51->font_hgt);
                                            else
                                                v55 = 0;
                                            LOBYTE(v109) = 0;
                                            v1->message_panel2 = v55;
                                            v56 = (TMessagePanel *)operator new(0x380u);
                                            LOBYTE(v109) = 17;
                                            if ( v56 )
                                                TMessagePanel::TMessagePanel(v56, v51->font, v51->font_wid, v51->font_hgt);
                                            else
                                                v57 = 0;
                                            LOBYTE(v109) = 0;
                                            v1->message_panel3 = v57;
                                            v58 = (TMessagePanel *)operator new(0x380u);
                                            LOBYTE(v109) = 18;
                                            if ( v58 )
                                                TMessagePanel::TMessagePanel(v58, v51->font, v51->font_wid, v51->font_hgt);
                                            else
                                                v59 = 0;
                                            LOBYTE(v109) = 0;
                                            v1->message_panel4 = v59;
                                            v60 = (TMessagePanel *)operator new(0x380u);
                                            LOBYTE(v109) = 19;
                                            if ( v60 )
                                                TMessagePanel::TMessagePanel(v60, v51->font, v51->font_wid, v51->font_hgt);
                                            else
                                                v61 = 0;
                                            LOBYTE(v109) = 0;
                                            v1->message_panel5 = v61;
                                            v62 = (TMessagePanel *)operator new(0x380u);
                                            LOBYTE(v109) = 20;
                                            if ( v62 )
                                                TMessagePanel::TMessagePanel(v62, v51->font, v51->font_wid, v51->font_hgt);
                                            else
                                                v63 = 0;
                                            v1->message_panel6 = v63;
                                            v64 = v1->message_panel;
                                            LOBYTE(v109) = 0;
                                            if ( !v64 )
                                                goto LABEL_189;
                                            if ( v64->error_code )
                                                goto LABEL_189;
                                            v65 = v1->message_panel2;
                                            if ( !v65 )
                                                goto LABEL_189;
                                            if ( v65->error_code )
                                                goto LABEL_189;
                                            v66 = v1->message_panel3;
                                            if ( !v66 )
                                                goto LABEL_189;
                                            if ( v66->error_code )
                                                goto LABEL_189;
                                            v67 = v1->message_panel4;
                                            if ( !v67
                                                || !v1->message_panel5
                                                || !v63
                                                || v67->error_code
                                                || !(*(int (__stdcall **)(TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v64->vfptr->gap4[0])(
                                                            v1->render_area,
                                                            v1->main_view,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            0)
                                                || !(*(int (__stdcall **)(TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v1->message_panel2->vfptr->gap4[0])(
                                                            v1->render_area,
                                                            v1->main_view,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            0)
                                                || !(*(int (__stdcall **)(TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v1->message_panel3->vfptr->gap4[0])(
                                                            v1->render_area,
                                                            v1->main_view,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            0)
                                                || !(*(int (__stdcall **)(TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v1->message_panel4->vfptr->gap4[0])(
                                                            v1->render_area,
                                                            v1->main_view,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            0)
                                                || !(*(int (__stdcall **)(TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v1->message_panel5->vfptr->gap4[0])(
                                                            v1->render_area,
                                                            v1->main_view,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            0)
                                                || !(*(int (__stdcall **)(TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v1->message_panel6->vfptr->gap4[0])(
                                                            v1->render_area,
                                                            v1->main_view,
                                                            0,
                                                            0,
                                                            0,
                                                            0,
                                                            0) )
                                            {
                                                goto LABEL_189;
                                            }
                                            v68 = RGE_Base_Game::get_font(rge_base_game, 11);
                                            fontb = 0;
                                            v69 = v1->chat_panel;
                                            while ( 1 )
                                            {
                                                v70 = (TMessagePanel *)operator new(0x380u);
                                                LOBYTE(v109) = 21;
                                                if ( v70 )
                                                    TMessagePanel::TMessagePanel(v70, v68->font, v68->font_wid, v68->font_hgt);
                                                else
                                                    v71 = 0;
                                                LOBYTE(v109) = 0;
                                                *v69 = v71;
                                                if ( !v71
                                                    || v71->error_code
                                                    || !(*(int (__thiscall **)(TMessagePanel *, TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v71->vfptr->gap4[0])(
                                                                v71,
                                                                v1->render_area,
                                                                v1->main_view,
                                                                0,
                                                                0,
                                                                0,
                                                                0,
                                                                0) )
                                                {
                                                    goto LABEL_190;
                                                }
                                                ++v69;
                                                v73 = __OFSUB__((char *)&fontb->font + 1, 8);
                                                v72 = (signed int)&fontb[-1].font_wid + 1 < 0;
                                                fontb = (RGE_Font *)((char *)fontb + 1);
                                                if ( !(v72 ^ v73) )
                                                {
                                                    v74 = RGE_Base_Game::get_font(rge_base_game, 11);
                                                    v75 = (TTextPanel *)operator new(0x188u);
                                                    LOBYTE(v109) = 22;
                                                    if ( v75 )
                                                        TTextPanel::TTextPanel(v75);
                                                    else
                                                        v76 = 0;
                                                    LOBYTE(v109) = 0;
                                                    v1->age_panel = v76;
                                                    if ( v76 && !v76->error_code )
                                                    {
                                                        if ( !TTextPanel::setup(
                                                                        v76,
                                                                        v1->render_area,
                                                                        (TPanel *)&v1->vfptr,
                                                                        0,
                                                                        0,
                                                                        0,
                                                                        0,
                                                                        v74->font,
                                                                        v74->font_wid,
                                                                        v74->font_hgt,
                                                                        0,
                                                                        0,
                                                                        0,
                                                                        0,
                                                                        0,
                                                                        0,
                                                                        0) )
                                                        {
                                                            v1->error_code = 1;
                                                            return;
                                                        }
                                                        TTextPanel::set_alignment(v1->age_panel, 0, 0);
                                                        TPanel::set_help_info((TPanel *)&v1->age_panel->vfptr, 20021, -1);
                                                        if ( do_color_log )
                                                            (*(void (__stdcall **)(_DWORD))&v1->age_panel->vfptr->gap10[4])(0);
                                                        v77 = RGE_Base_Game::get_font(rge_base_game, 10);
                                                        v78 = (TTextPanel *)operator new(0x188u);
                                                        LOBYTE(v109) = 23;
                                                        if ( v78 )
                                                            TTextPanel::TTextPanel(v78);
                                                        else
                                                            v79 = 0;
                                                        LOBYTE(v109) = 0;
                                                        v1->fps_panel = v79;
                                                        if ( v79 )
                                                        {
                                                            if ( !v79->error_code )
                                                            {
                                                                if ( !TTextPanel::setup(
                                                                                v79,
                                                                                v1->render_area,
                                                                                (TPanel *)&v1->vfptr,
                                                                                0,
                                                                                0,
                                                                                0,
                                                                                0,
                                                                                v77->font,
                                                                                v77->font_wid,
                                                                                v77->font_hgt,
                                                                                0,
                                                                                1,
                                                                                0,
                                                                                0,
                                                                                0,
                                                                                0,
                                                                                0) )
                                                                {
                                                                    v1->error_code = 1;
                                                                    return;
                                                                }
                                                                TTextPanel::set_alignment(v1->fps_panel, 0, AlignLeft);
                                                                v80 = v1->fps_panel;
                                                                if ( rge_base_game->do_show_timings )
                                                                {
                                                                    (*(void (__stdcall **)(signed int))&v80->vfptr->gap10[4])(1);
                                                                    (*(void (__stdcall **)(_DWORD))&v1->inven_panel->vfptr->gap10[4])(0);
                                                                    if ( !do_color_log )
                                                                        (*(void (__stdcall **)(_DWORD))&v1->age_panel->vfptr->gap10[4])(0);
                                                                }
                                                                else
                                                                {
                                                                    (*(void (__stdcall **)(_DWORD))&v80->vfptr->gap10[4])(0);
                                                                    (*(void (__stdcall **)(signed int))&v1->inven_panel->vfptr->gap10[4])(1);
                                                                    if ( !do_color_log )
                                                                        (*(void (__stdcall **)(signed int))&v1->age_panel->vfptr->gap10[4])(1);
                                                                }
                                                                v81 = 0;
                                                                fontc = RGE_Base_Game::get_font(rge_base_game, 11);
                                                                if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                                                {
                                                                    v82 = 1;
                                                                    do
                                                                    {
                                                                        if ( TCommunications_Handler::GetPlayerHumanity(comm, v82) == 2
                                                                            || TCommunications_Handler::GetPlayerHumanity(comm, v82) == 4 )
                                                                        {
                                                                            ++v81;
                                                                        }
                                                                        ++v82;
                                                                    }
                                                                    while ( v82 < 9 );
                                                                    num_game_playersa = v81;
                                                                    if ( !v81 )
                                                                        num_game_playersa = 1;
                                                                }
                                                                else
                                                                {
                                                                    num_game_playersa = v1->world->player_num - 1;
                                                                }
                                                                v83 = 0;
                                                                if ( num_game_playersa <= 0 )
                                                                {
LABEL_174:
                                                                    v90 = &v1->log_text;
                                                                    if ( !TEasy_Panel::create_text(
                                                                                    (TEasy_Panel *)&v1->vfptr,
                                                                                    (TPanel *)&v1->vfptr,
                                                                                    &v1->log_text,
                                                                                    message_in,
                                                                                    10,
                                                                                    300,
                                                                                    400,
                                                                                    96,
                                                                                    7,
                                                                                    0,
                                                                                    0,
                                                                                    0) )
                                                                    {
                                                                        v1->error_code = 1;
                                                                        return;
                                                                    }
                                                                    TTextPanel::set_back_pic(*v90, 0);
                                                                    TTextPanel::set_fill_back(*v90, 1, 0);
                                                                    TTextPanel::set_style(*v90, 0);
                                                                    TTextPanel::set_text_color(*v90, 0xFFFFFFu, 0);
                                                                    if ( !TEasy_Panel::create_auto_scrollbar(
                                                                                    (TEasy_Panel *)&v1->vfptr,
                                                                                    &v1->log_scrollbar,
                                                                                    *v90,
                                                                                    20) )
                                                                    {
                                                                        v1->error_code = 1;
                                                                        return;
                                                                    }
                                                                    TScrollBarPanel::set_bevel_info(v1->log_scrollbar, 1, 255, 255, 255, 255, 255, 255);
                                                                    TTextPanel::empty_list(*v90);
                                                                    (*(void (__stdcall **)(_DWORD))&(*v90)->vfptr->gap10[4])(0);
                                                                    v91 = RGE_Base_Game::get_font(rge_base_game, 7);
                                                                    v92 = RGE_Base_Game::get_sound(rge_base_game, 1);
                                                                    v93 = (RGE_Panel_Tool_Box *)operator new(0x120u);
                                                                    LOBYTE(v109) = 25;
                                                                    if ( v93 )
                                                                        RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(
                                                                            v93,
                                                                            v1->render_area,
                                                                            (TPanel *)&v1->vfptr,
                                                                            0,
                                                                            0,
                                                                            0,
                                                                            0,
                                                                            v91->font,
                                                                            v91->font_wid,
                                                                            v91->font_hgt,
                                                                            (TDigital *)v92,
                                                                            (TScreenPanel *)&v1->vfptr,
                                                                            (RGE_View *)&v1->main_view->vfptr,
                                                                            (RGE_Diamond_Map *)&v1->map_view->vfptr);
                                                                    else
                                                                        v94 = 0;
                                                                    LOBYTE(v109) = 0;
                                                                    v1->tool_box = v94;
                                                                    if ( v94 && !v94->error_code )
                                                                    {
                                                                        (*(void (__thiscall **)(RGE_Panel_Tool_Box *, _DWORD))&v94->vfptr->gap10[4])(v94, 0);
                                                                        v95 = (TPanel **)v1->button_panel;
                                                                        v96 = 17;
                                                                        do
                                                                        {
                                                                            TPanel::set_z_order(*v95, 1, 0);
                                                                            ++v95;
                                                                            --v96;
                                                                        }
                                                                        while ( v96 );
                                                                        TRIBE_Screen_Game::handle_size(v1, 0, 0, (int)v95, v1->pnl_wid, v1->pnl_hgt);
                                                                        TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->main_view->vfptr);
                                                                        v97 = HIWORD(RGE_Base_Game::get_player(rge_base_game)->master_players);
                                                                        v98 = RGE_Base_Game::get_player(rge_base_game);
                                                                        TRIBE_Screen_Game::player_changed(v1, HIWORD(v98->master_players), v97);
                                                                        v1->terrain_sound_interval = 20000;
                                                                        v1->last_terrain_sound_time = debug_timeGetTime();
                                                                        v1->anim_pal_interval = 200;
                                                                        v1->last_anim_pal_time = debug_timeGetTime();
                                                                        v1->last_anim_pal_index = 0;
                                                                        v1->last_anim_pal_index2 = 0;
                                                                        v1->last_anim_pal_index3 = 0;
                                                                        v1->anim_pal_table[0].green = 39;
                                                                        v1->anim_pal_table[1].red = 39;
                                                                        v1->anim_pal_table[5].red = 39;
                                                                        v1->anim_pal_table[6].green = 39;
                                                                        v99 = v1->time_panel;
                                                                        v1->anim_pal_table[0].red = 23;
                                                                        v1->anim_pal_table[0].blue = 124;
                                                                        v1->anim_pal_table[1].green = 63;
                                                                        v1->anim_pal_table[1].blue = -112;
                                                                        v1->anim_pal_table[2].red = 63;
                                                                        v1->anim_pal_table[2].green = 95;
                                                                        v1->anim_pal_table[2].blue = -97;
                                                                        v1->anim_pal_table[3].red = 87;
                                                                        v1->anim_pal_table[3].green = 123;
                                                                        v1->anim_pal_table[3].blue = -76;
                                                                        v1->anim_pal_table[4].red = 63;
                                                                        v1->anim_pal_table[4].green = 95;
                                                                        v1->anim_pal_table[4].blue = -96;
                                                                        v1->anim_pal_table[5].green = 63;
                                                                        v1->anim_pal_table[5].blue = -111;
                                                                        v1->anim_pal_table[6].red = 23;
                                                                        v1->anim_pal_table[6].blue = 123;
                                                                        TRIBE_Panel_Time::startup(v99);
                                                                        TRIBE_Panel_Time::set_clock_type(v1->time_panel, 0, 0);
                                                                        v100 = v1->countdown_clock;
                                                                        v101 = 10;
                                                                        do
                                                                        {
                                                                            TRIBE_Panel_Time::startup(*v100);
                                                                            TRIBE_Panel_Time::set_clock_type(*v100, 0, 0);
                                                                            ++v100;
                                                                            --v101;
                                                                        }
                                                                        while ( v101 );
                                                                        TRIBE_Screen_Game::reset_clocks(v1);
                                                                        TRIBE_Panel_Pop::startup(v1->pop_panel);
                                                                        TRIBE_Screen_Game::command_score(v1, v1->world->score_displayed);
                                                                        confirmed_close = 0;
                                                                        if ( RGE_Base_Game::check_prog_argument(rge_base_game, aPause) )
                                                                        {
                                                                            start_paused = 1;
                                                                            (*(void (__stdcall **)(signed int))&rge_base_game->vfptr->gap8[4])(6);
                                                                            rge_base_game->world->temp_pause = 1;
                                                                        }
                                                                        return;
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    v84 = (int)v1->score_panel;
                                                                    while ( 1 )
                                                                    {
                                                                        v85 = (TMessagePanel *)operator new(0x380u);
                                                                        LOBYTE(v109) = 24;
                                                                        if ( v85 )
                                                                            TMessagePanel::TMessagePanel(v85, fontc->font, fontc->font_wid, fontc->font_hgt);
                                                                        else
                                                                            v86 = 0;
                                                                        v87 = *v86;
                                                                        *(_DWORD *)v84 = v86;
                                                                        v88 = v1->main_view;
                                                                        v89 = v1->render_area;
                                                                        LOBYTE(v109) = 0;
                                                                        if ( !(*(int (__thiscall **)(int *, TDrawArea *, TRIBE_Main_View *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(v87 + 4))(
                                                                                        v86,
                                                                                        v89,
                                                                                        v88,
                                                                                        0,
                                                                                        0,
                                                                                        0,
                                                                                        0,
                                                                                        0)
                                                                            || !*(_DWORD *)v84
                                                                            || *(_DWORD *)(*(_DWORD *)v84 + 216) )
                                                                        {
                                                                            break;
                                                                        }
                                                                        ++v83;
                                                                        v84 += 4;
                                                                        if ( v83 >= num_game_playersa )
                                                                            goto LABEL_174;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    goto LABEL_190;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                goto LABEL_190;
            }
        }
    }
LABEL_191:
    v1->error_code = 1;
}

//----- (004954A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::~TRIBE_Screen_Game(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // edi@1
    TDigital *v2; // ecx@1
    TDigital *v3; // esi@4
    TShape *v4; // esi@11
    TShape *v5; // esi@13
    TShape *v6; // esi@15
    TShape *v7; // esi@17
    TShape *v8; // esi@19
    TShape *v9; // esi@21
    TShape *v10; // esi@23
    TShape *v11; // esi@25
    TShape **v12; // ebx@27
    signed int v13; // ebp@27
    TShape *v14; // esi@28
    TMessagePanel **v15; // esi@39
    signed int v16; // ebx@39
    TRIBE_Panel_Button **v17; // esi@43
    signed int v18; // ebx@43
    TTextPanel *v19; // ecx@47
    TTextPanel *v20; // ecx@49
    TMessagePanel **v21; // esi@51
    signed int v22; // ebx@51
    TTextPanel *v23; // ecx@55
    TScrollBarPanel *v24; // ecx@57
    TRIBE_Panel_Inven *v25; // ecx@59
    TRIBE_Panel_Object *v26; // ecx@61
    TTextPanel *v27; // ecx@63
    TMessagePanel *v28; // ecx@65
    TRIBE_Panel_Time *v29; // ecx@67
    TRIBE_Panel_Pop *v30; // ecx@69
    TRIBE_Panel_Time **v31; // esi@71
    signed int v32; // ebx@71
    TMessagePanel *v33; // ecx@75
    TMessagePanel *v34; // ecx@77
    TMessagePanel *v35; // ecx@79
    TMessagePanel *v36; // ecx@81
    TMessagePanel *v37; // ecx@83
    TMessagePanel *v38; // ecx@85
    RGE_Panel_Tool_Box *v39; // ecx@87
    TTextPanel *v40; // ecx@89
    TRIBE_Main_View *v41; // ecx@91
    TRIBE_Diamond_Map_View *v42; // ecx@93

    v1 = this;
    this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Game::`vftable';
    TPanelSystem::destroyPanel(&panel_system, aConfigDialog);
    v2 = v1->game_over_sound;
    if ( v2 )
    {
        if ( TDigital::is_playing(v2) )
            TDigital::stop(v1->game_over_sound);
        v3 = v1->game_over_sound;
        if ( v3 )
        {
            TDigital::~TDigital(v1->game_over_sound);
            operator delete(v3);
        }
        v1->game_over_sound = 0;
    }
    if ( v1->terrain_sound )
    {
        if ( v1->terrain_playing )
        {
            v1->terrain_playing = 0;
            RGE_Sound::stop(v1->terrain_sound);
        }
        v1->terrain_sound = 0;
    }
    v4 = v1->game_screen_pic;
    if ( v4 )
    {
        TShape::~TShape(v1->game_screen_pic);
        operator delete(v4);
        v1->game_screen_pic = 0;
    }
    v5 = v1->button_border1_pic;
    if ( v5 )
    {
        TShape::~TShape(v1->button_border1_pic);
        operator delete(v5);
        v1->button_border1_pic = 0;
    }
    v6 = v1->button_other_pic;
    if ( v6 )
    {
        TShape::~TShape(v1->button_other_pic);
        operator delete(v6);
        v1->button_other_pic = 0;
    }
    v7 = v1->button_border2_pic;
    if ( v7 )
    {
        TShape::~TShape(v1->button_border2_pic);
        operator delete(v7);
        v1->button_border2_pic = 0;
    }
    v8 = v1->button_border3_pic;
    if ( v8 )
    {
        TShape::~TShape(v1->button_border3_pic);
        operator delete(v8);
        v1->button_border3_pic = 0;
    }
    v9 = v1->button_cmd_pic;
    if ( v9 )
    {
        TShape::~TShape(v1->button_cmd_pic);
        operator delete(v9);
        v1->button_cmd_pic = 0;
    }
    v10 = v1->button_tech_pic;
    if ( v10 )
    {
        TShape::~TShape(v1->button_tech_pic);
        operator delete(v10);
        v1->button_tech_pic = 0;
    }
    v11 = v1->button_unit_pic;
    if ( v11 )
    {
        TShape::~TShape(v1->button_unit_pic);
        operator delete(v11);
        v1->button_unit_pic = 0;
    }
    v12 = v1->button_bldg_pics;
    v13 = 5;
    do
    {
        v14 = *v12;
        if ( *v12 )
        {
            TShape::~TShape(*v12);
            operator delete(v14);
            *v12 = 0;
        }
        ++v12;
        --v13;
    }
    while ( v13 );
    if ( v1->tech_list )
    {
        free(v1->tech_list);
        v1->tech_list = 0;
    }
    if ( v1->make_list )
    {
        free(v1->make_list);
        v1->make_list = 0;
    }
    if ( v1->bldg_list )
    {
        free(v1->bldg_list);
        v1->bldg_list = 0;
    }
    if ( v1->trade_list )
    {
        free(v1->trade_list);
        v1->trade_list = 0;
    }
    v15 = v1->chat_panel;
    v16 = 8;
    do
    {
        if ( *v15 )
        {
            ((void (__stdcall *)(_DWORD))(*v15)->vfptr->__vecDelDtor)(1);
            *v15 = 0;
        }
        ++v15;
        --v16;
    }
    while ( v16 );
    v17 = v1->button_panel;
    v18 = 17;
    do
    {
        if ( *v17 )
        {
            (**(void (__stdcall ***)(_DWORD))*v17)(1);
            *v17 = 0;
        }
        ++v17;
        --v18;
    }
    while ( v18 );
    v19 = v1->age_panel;
    if ( v19 )
    {
        ((void (__stdcall *)(_DWORD))v19->vfptr->__vecDelDtor)(1);
        v1->age_panel = 0;
    }
    v20 = v1->fps_panel;
    if ( v20 )
    {
        ((void (__stdcall *)(_DWORD))v20->vfptr->__vecDelDtor)(1);
        v1->fps_panel = 0;
    }
    v21 = v1->score_panel;
    v22 = 8;
    do
    {
        if ( *v21 )
        {
            ((void (__stdcall *)(_DWORD))(*v21)->vfptr->__vecDelDtor)(1);
            *v21 = 0;
        }
        ++v21;
        --v22;
    }
    while ( v22 );
    v23 = v1->log_text;
    if ( v23 )
    {
        ((void (__stdcall *)(_DWORD))v23->vfptr->__vecDelDtor)(1);
        v1->log_text = 0;
    }
    v24 = v1->log_scrollbar;
    if ( v24 )
    {
        ((void (__stdcall *)(_DWORD))v24->vfptr->__vecDelDtor)(1);
        v1->log_scrollbar = 0;
    }
    v25 = v1->inven_panel;
    if ( v25 )
    {
        ((void (__stdcall *)(_DWORD))v25->vfptr->__vecDelDtor)(1);
        v1->inven_panel = 0;
    }
    v26 = v1->object_panel;
    if ( v26 )
    {
        ((void (__stdcall *)(_DWORD))v26->vfptr->__vecDelDtor)(1);
        v1->object_panel = 0;
    }
    v27 = v1->quit_message_panel;
    if ( v27 )
    {
        ((void (__stdcall *)(_DWORD))v27->vfptr->__vecDelDtor)(1);
        v1->quit_message_panel = 0;
    }
    v28 = v1->text_line_panel;
    if ( v28 )
    {
        ((void (__stdcall *)(_DWORD))v28->vfptr->__vecDelDtor)(1);
        v1->text_line_panel = 0;
    }
    v29 = v1->time_panel;
    if ( v29 )
    {
        ((void (__stdcall *)(_DWORD))v29->vfptr->__vecDelDtor)(1);
        v1->time_panel = 0;
    }
    v30 = v1->pop_panel;
    if ( v30 )
    {
        ((void (__stdcall *)(_DWORD))v30->vfptr->__vecDelDtor)(1);
        v1->pop_panel = 0;
    }
    v31 = v1->countdown_clock;
    v32 = 10;
    do
    {
        if ( *v31 )
        {
            ((void (__stdcall *)(_DWORD))(*v31)->vfptr->__vecDelDtor)(1);
            *v31 = 0;
        }
        ++v31;
        --v32;
    }
    while ( v32 );
    v33 = v1->message_panel6;
    if ( v33 )
    {
        ((void (__stdcall *)(_DWORD))v33->vfptr->__vecDelDtor)(1);
        v1->message_panel6 = 0;
    }
    v34 = v1->message_panel5;
    if ( v34 )
    {
        ((void (__stdcall *)(_DWORD))v34->vfptr->__vecDelDtor)(1);
        v1->message_panel5 = 0;
    }
    v35 = v1->message_panel4;
    if ( v35 )
    {
        ((void (__stdcall *)(_DWORD))v35->vfptr->__vecDelDtor)(1);
        v1->message_panel4 = 0;
    }
    v36 = v1->message_panel3;
    if ( v36 )
    {
        ((void (__stdcall *)(_DWORD))v36->vfptr->__vecDelDtor)(1);
        v1->message_panel3 = 0;
    }
    v37 = v1->message_panel2;
    if ( v37 )
    {
        ((void (__stdcall *)(_DWORD))v37->vfptr->__vecDelDtor)(1);
        v1->message_panel2 = 0;
    }
    v38 = v1->message_panel;
    if ( v38 )
    {
        ((void (__stdcall *)(_DWORD))v38->vfptr->__vecDelDtor)(1);
        v1->message_panel = 0;
    }
    v39 = v1->tool_box;
    if ( v39 )
    {
        ((void (__stdcall *)(_DWORD))v39->vfptr->__vecDelDtor)(1);
        v1->tool_box = 0;
    }
    v40 = v1->pause_text;
    if ( v40 )
    {
        ((void (__stdcall *)(_DWORD))v40->vfptr->__vecDelDtor)(1);
        v1->pause_text = 0;
    }
    v41 = v1->main_view;
    if ( v41 )
    {
        ((void (__stdcall *)(_DWORD))v41->vfptr->__vecDelDtor)(1);
        v1->main_view = 0;
    }
    v42 = v1->map_view;
    if ( v42 )
    {
        ((void (__stdcall *)(_DWORD))v42->vfptr->__vecDelDtor)(1);
        v1->map_view = 0;
    }
    TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 572BB8: using guessed type int (__thiscall *TRIBE_Screen_Game::`vftable')(void *Memory, unsigned int __flags);

//----- (004959A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::set_redraw(TRIBE_Screen_Game *this, TPanel::RedrawMode redraw_mode)
{
    TPanel::set_redraw((TPanel *)&this->vfptr, redraw_mode);
}

//----- (004959B0) --------------------------------------------------------
void __stdcall TRIBE_Screen_Game::set_overlapped_redraw(TPanel *redraw_panel, TPanel *calling_panel, TPanel::RedrawMode redraw_mode)
{
    TPanel *v4; // eax@1
    int v5; // edx@2
    int v6; // ebp@2
    int v7; // edi@2
    int v8; // ecx@2
    int v9; // esi@2
    int v10; // eax@2
    int v11; // ebx@2
    int v12; // ecx@2
    bool v13; // sf@6
    unsigned __int8 v14; // of@6
    TPanel *dialog; // [sp+10h] [bp-24h]@1
    int this_rect_12; // [sp+30h] [bp-4h]@2

    v4 = TPanelSystem::modalPanel(&panel_system);
    dialog = v4;
    if ( !v4 )
        return;
    v5 = redraw_panel->clip_rect.left;
    v6 = redraw_panel->clip_rect.top;
    v7 = redraw_panel->clip_rect.right;
    this_rect_12 = redraw_panel->clip_rect.bottom;
    v8 = (int)&v4->clip_rect.left;
    v9 = v4->clip_rect.left;
    v10 = v4->clip_rect.top;
    v11 = *(_DWORD *)(v8 + 8);
    v12 = *(_DWORD *)(v8 + 12);
    if ( v9 >= v5 && v9 <= v7 || v11 >= v5 && v11 <= v7 )
        goto LABEL_8;
    v14 = __OFSUB__(v5, v9);
    v13 = v5 - v9 < 0;
    if ( v5 > v9 )
    {
        if ( v11 <= v7 )
        {
LABEL_14:
            v14 = __OFSUB__(v5, v9);
            v13 = v5 - v9 < 0;
            goto LABEL_15;
        }
LABEL_8:
        if ( v10 >= v6 && v10 <= this_rect_12 || v12 >= v6 && v12 <= this_rect_12 || v10 < v6 && v12 > this_rect_12 )
        {
LABEL_27:
            ((void (__stdcall *)(TPanel::RedrawMode))dialog->vfptr->set_redraw)(redraw_mode);
            return;
        }
        goto LABEL_14;
    }
LABEL_15:
    if ( (!(v13 ^ v14) && v5 <= v11 || v7 >= v9 && v7 <= v11 || v5 < v9 && v7 > v11)
        && (v6 >= v10 && v6 <= v12 || this_rect_12 >= v10 && this_rect_12 <= v12 || v6 < v10 && this_rect_12 > v12) )
    {
        goto LABEL_27;
    }
}

//----- (00495A90) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::set_map_buttons_redraw(TRIBE_Screen_Game *this, TPanel::RedrawMode redraw_mode)
{
    TRIBE_Screen_Game *v2; // esi@1

    v2 = this;
    if ( this->pnl_wid < 800 )
    {
        (*(void (__stdcall **)(TPanel::RedrawMode))(*(_DWORD *)this->button_panel[5] + 32))(redraw_mode);
        (*(void (__stdcall **)(TPanel::RedrawMode))(*(_DWORD *)v2->button_panel[11] + 32))(redraw_mode);
    }
    (*(void (__stdcall **)(TPanel::RedrawMode))(*(_DWORD *)v2->button_panel[15] + 32))(redraw_mode);
    (*(void (__stdcall **)(TPanel::RedrawMode))(*(_DWORD *)v2->button_panel[16] + 32))(redraw_mode);
}

//----- (00495AE0) --------------------------------------------------------
int __userpurge TRIBE_Screen_Game::handle_size@<eax>(TRIBE_Screen_Game *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int win_wid, int win_hgt)
{
    TRIBE_Screen_Game *v6; // esi@1
    int *v8; // edi@3
    TMessagePanel **v9; // ebx@3
    signed int v10; // ebp@3
    TMessagePanel *v11; // ecx@4
    TPanelVtbl *v12; // eax@5
    signed int v13; // eax@7
    RGE_Panel_Tool_Box *v14; // ecx@9
    int v15; // edi@12
    signed int v16; // ebp@13
    signed int v17; // ebx@13
    int v18; // eax@14
    bool v19; // zf@15
    TRIBE_Panel_Button *v20; // ecx@16
    RGE_Panel_Tool_Box *v21; // ecx@19
    int v22; // edi@22
    signed int v23; // ebp@23
    signed int v24; // ebx@23
    int v25; // eax@24
    TRIBE_Panel_Button *v26; // ecx@26
    signed __int16 v27; // ax@27
    RGE_Panel_Tool_Box *v28; // ecx@28
    int v29; // edi@31
    signed int v30; // ebp@32
    signed int v31; // ebx@32
    int v32; // eax@33
    TPanelVtbl *v33; // edx@36
    signed int v34; // ebx@36
    int v35; // edi@36
    signed int v36; // ebp@36
    TMessagePanel *v37; // ecx@38
    int v38; // eax@41
    signed int v39; // ebx@41
    int v40; // edi@41
    signed int v41; // ebp@41
    signed __int16 v42; // di@43
    TMessagePanel *v43; // ecx@44
    TMessagePanel *v44; // eax@46
    int *v45; // ebx@50
    int v46; // edi@50
    signed int v47; // ebp@50
    int v48; // ST3C0_4@54
    RGE_Game_World *v49; // eax@54
    int v50; // [sp+3D0h] [bp-24h]@0
    int save_score_active[8]; // [sp+3D4h] [bp-20h]@3
    signed int v52; // [sp+404h] [bp+10h]@12
    signed int v53; // [sp+404h] [bp+10h]@22
    signed int v54; // [sp+404h] [bp+10h]@31
    signed int v55; // [sp+408h] [bp+14h]@12
    signed int v56; // [sp+408h] [bp+14h]@22
    signed int v57; // [sp+408h] [bp+14h]@31

    v6 = this;
    TPanel::handle_size((TPanel *)&this->vfptr, win_wid, win_hgt);
    if ( !v6->main_view )
        return 0;
    (*(void (__stdcall **)(_DWORD, int, int, int))&v6->log_text->vfptr->gap10[4])(0, a2, a3, a4);
    (*(void (__stdcall **)(signed int))&v6->text_line_panel->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v6->message_panel->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v6->message_panel2->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v6->message_panel3->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v6->message_panel4->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v6->message_panel5->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v6->message_panel6->vfptr->gap10[4])(1);
    v8 = &save_score_active[3];
    v9 = v6->score_panel;
    v10 = 8;
    do
    {
        v11 = *v9;
        if ( *v9 )
        {
            v12 = v11->vfptr;
            *v8 = v11->active;
            (*(void (__stdcall **)(signed int))&v12->gap10[4])(1);
        }
        ++v8;
        ++v9;
        --v10;
    }
    while ( v10 );
    v13 = v6->pnl_wid;
    if ( v13 >= 1024 && v6->pnl_hgt >= 768 )
    {
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v6->pop_panel->vfptr->gap10[8])(
            7,
            432,
            4,
            4,
            4,
            160,
            160,
            20,
            20,
            0,
            0,
            0,
            0);
        v14 = v6->tool_box;
        if ( v14->active )
        {
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v14->vfptr->set_fixed_position)(0, 20, 1024, 30);
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v6->main_view->vfptr->set_fixed_position)(
                0,
                50,
                1024,
                592);
        }
        else
        {
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v6->main_view->vfptr->set_fixed_position)(
                0,
                20,
                1024,
                622);
        }
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->map_view->vfptr->set_fixed_position)(
            795,
            648,
            220,
            114);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->age_panel->vfptr->set_fixed_position)(
            270,
            2,
            492,
            16);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->fps_panel->vfptr->set_fixed_position)(
            2,
            2,
            280,
            16);
        ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v6->inven_panel->vfptr->set_fixed_position)(
            0,
            0,
            270,
            20);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->object_panel->vfptr->set_fixed_position)(
            5,
            649,
            127,
            114);
        v55 = 650;
        v15 = (int)v6->button_panel;
        v52 = 2;
        do
        {
            v16 = 136;
            v17 = 6;
            do
            {
                (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v15 + 28))(
                    v16,
                    v55,
                    54,
                    54);
                v18 = *(_DWORD *)v15;
                v15 += 4;
                v16 += 54;
                --v17;
                *(_BYTE *)(v18 + 704) = 0;
            }
            while ( v17 );
            v19 = v52 == 1;
            v55 += 58;
            --v52;
        }
        while ( !v19 );
        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, int, int, int, int))(*(_DWORD *)v6->button_panel[12]
                                                                                                                                                                                    + 28))(
            772,
            0,
            72,
            19,
            v50,
            save_score_active[0],
            save_score_active[1],
            save_score_active[2]);
        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[13] + 28))(
            844,
            0,
            108,
            19);
        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[14] + 28))(
            952,
            0,
            72,
            19);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v6->button_panel[15] + 28))(
            989,
            732,
            30,
            30);
        v20 = v6->button_panel[15];
        save_score_active[2] = 30;
        save_score_active[1] = 30;
        *((_BYTE *)v20 + 704) = 3;
        (*(void (__cdecl **)(signed int, signed int, int, int))(*(_DWORD *)v6->button_panel[16] + 28))(
            989,
            650,
            save_score_active[1],
            save_score_active[2]);
LABEL_27:
        *((_BYTE *)v6->button_panel[16] + 704) = 3;
        v6->more_cancel_pic = v6->button_cmd_pic;
        v6->more_frame = 11;
        v27 = 10;
        goto LABEL_36;
    }
    if ( v13 >= 800 && v6->pnl_hgt >= 600 )
    {
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v6->pop_panel->vfptr->gap10[8])(
            7,
            320,
            4,
            4,
            4,
            160,
            160,
            20,
            20,
            0,
            0,
            0,
            0);
        v21 = v6->tool_box;
        if ( v21->active )
        {
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v21->vfptr->set_fixed_position)(0, 20, 800, 30);
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v6->main_view->vfptr->set_fixed_position)(
                0,
                50,
                800,
                424);
        }
        else
        {
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v6->main_view->vfptr->set_fixed_position)(
                0,
                20,
                800,
                454);
        }
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->map_view->vfptr->set_fixed_position)(
            571,
            480,
            220,
            114);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->age_panel->vfptr->set_fixed_position)(
            270,
            2,
            268,
            16);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->fps_panel->vfptr->set_fixed_position)(
            2,
            2,
            280,
            16);
        ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v6->inven_panel->vfptr->set_fixed_position)(
            0,
            0,
            270,
            20);
        ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->object_panel->vfptr->set_fixed_position)(
            5,
            481,
            127,
            114);
        v56 = 482;
        v22 = (int)v6->button_panel;
        v53 = 2;
        do
        {
            v23 = 136;
            v24 = 6;
            do
            {
                (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v22 + 28))(
                    v23,
                    v56,
                    54,
                    54);
                v25 = *(_DWORD *)v22;
                v22 += 4;
                v23 += 54;
                --v24;
                *(_BYTE *)(v25 + 704) = 0;
            }
            while ( v24 );
            v19 = v53 == 1;
            v56 += 58;
            --v53;
        }
        while ( !v19 );
        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, int, int, int, int))(*(_DWORD *)v6->button_panel[12]
                                                                                                                                                                                    + 28))(
            548,
            0,
            72,
            19,
            v50,
            save_score_active[0],
            save_score_active[1],
            save_score_active[2]);
        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[13] + 28))(
            620,
            0,
            108,
            19);
        (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[14] + 28))(
            728,
            0,
            72,
            19);
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v6->button_panel[15] + 28))(
            765,
            564,
            30,
            30);
        v26 = v6->button_panel[15];
        save_score_active[2] = 30;
        save_score_active[1] = 30;
        *((_BYTE *)v26 + 704) = 3;
        (*(void (__cdecl **)(signed int, signed int, int, int))(*(_DWORD *)v6->button_panel[16] + 28))(
            765,
            482,
            save_score_active[1],
            save_score_active[2]);
        goto LABEL_27;
    }
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v6->pop_panel->vfptr->gap10[8])(
        7,
        240,
        4,
        4,
        4,
        160,
        160,
        20,
        20,
        0,
        0,
        0,
        0);
    v28 = v6->tool_box;
    if ( v28->active )
    {
        ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v28->vfptr->set_fixed_position)(0, 20, 640, 30);
        ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v6->main_view->vfptr->set_fixed_position)(
            0,
            50,
            640,
            304);
    }
    else
    {
        ((void (__stdcall *)(_DWORD, signed int, signed int, signed int))v6->main_view->vfptr->set_fixed_position)(
            0,
            20,
            640,
            334);
    }
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->map_view->vfptr->set_fixed_position)(
        411,
        362,
        220,
        114);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->age_panel->vfptr->set_fixed_position)(
        270,
        2,
        106,
        16);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->fps_panel->vfptr->set_fixed_position)(
        2,
        2,
        280,
        16);
    ((void (__stdcall *)(_DWORD, _DWORD, signed int, signed int))v6->inven_panel->vfptr->set_fixed_position)(
        0,
        0,
        270,
        20);
    ((void (__stdcall *)(signed int, signed int, signed int, signed int))v6->object_panel->vfptr->set_fixed_position)(
        5,
        361,
        127,
        114);
    v57 = 362;
    v29 = (int)v6->button_panel;
    v54 = 2;
    do
    {
        v30 = 136;
        v31 = 6;
        do
        {
            (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v29 + 28))(v30, v57, 54, 54);
            v32 = *(_DWORD *)v29;
            v29 += 4;
            v30 += 54;
            --v31;
            *(_BYTE *)(v32 + 704) = 0;
        }
        while ( v31 );
        v19 = v54 == 1;
        v57 += 58;
        --v54;
    }
    while ( !v19 );
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v6->button_panel[5] + 28))(
        406,
        362,
        102,
        53);
    *((_BYTE *)v6->button_panel[5] + 704) = 2;
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v6->button_panel[11] + 28))(
        406,
        443,
        102,
        53);
    *((_BYTE *)v6->button_panel[11] + 704) = 2;
    (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[12] + 28))(
        388,
        0,
        72,
        19);
    (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[13] + 28))(
        460,
        0,
        108,
        19);
    (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int))(*(_DWORD *)v6->button_panel[14] + 28))(
        568,
        0,
        72,
        19);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v6->button_panel[15] + 28))(
        605,
        444,
        30,
        30);
    *((_BYTE *)v6->button_panel[15] + 704) = 3;
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(*(_DWORD *)v6->button_panel[16] + 28))(
        605,
        362,
        30,
        30);
    *((_BYTE *)v6->button_panel[16] + 704) = 3;
    v6->more_cancel_pic = v6->button_other_pic;
    v6->more_frame = 0;
    v27 = 2;
LABEL_36:
    v33 = v6->pause_text->vfptr;
    v6->cancel_frame = v27;
    v6->unselect_frame = v27;
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v33->gap10[8])(
        2,
        4,
        4,
        4,
        4,
        600,
        600,
        60,
        60,
        0,
        0,
        0,
        0);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v6->time_panel->vfptr->gap10[8])(
        7,
        4,
        4,
        4,
        4,
        120,
        120,
        20,
        20,
        0,
        0,
        0,
        0);
    v34 = 4;
    v35 = (int)v6->countdown_clock;
    v36 = 10;
    do
    {
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v35 + 24))(
            9,
            4,
            v34,
            4,
            4,
            170,
            170,
            20,
            20,
            0,
            0,
            0,
            0);
        v35 += 4;
        v34 += 20;
        --v36;
    }
    while ( v36 );
    v37 = v6->text_line_panel;
    if ( v6->world->score_displayed )
        (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v37->vfptr->gap10[8])(
            8,
            4,
            0,
            184,
            4,
            0,
            0,
            34,
            34,
            0,
            0,
            0,
            0);
    else
        (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v37->vfptr->gap10[8])(
            8,
            4,
            0,
            4,
            4,
            0,
            0,
            34,
            34,
            0,
            0,
            0,
            0);
    v38 = TPanel::width((TPanel *)&v6->main_view->vfptr);
    (*(void (__stdcall **)(signed int, int, signed int, int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v6->quit_message_panel->vfptr->gap10[8])(
        7,
        (v38 - 500) / 2,
        8,
        (v38 - 500) / 2,
        8,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        0);
    (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v6->message_panel->vfptr->gap10[8])(
        8,
        4,
        0,
        4,
        0,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        v6->text_line_panel);
    (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v6->message_panel2->vfptr->gap10[8])(
        8,
        4,
        0,
        4,
        0,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        v6->message_panel);
    (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v6->message_panel3->vfptr->gap10[8])(
        8,
        4,
        0,
        4,
        0,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        v6->message_panel2);
    (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v6->message_panel4->vfptr->gap10[8])(
        8,
        4,
        0,
        4,
        0,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        v6->message_panel3);
    (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v6->message_panel5->vfptr->gap10[8])(
        8,
        4,
        0,
        4,
        0,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        v6->message_panel4);
    (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v6->message_panel6->vfptr->gap10[8])(
        8,
        4,
        0,
        4,
        0,
        0,
        0,
        20,
        20,
        0,
        0,
        0,
        v6->message_panel5);
    v39 = 34;
    v40 = (int)v6->chat_panel;
    v41 = 8;
    do
    {
        (*(void (__stdcall **)(signed int, signed int, signed int, signed int))(**(_DWORD **)v40 + 28))(4, v39, 620, 20);
        v40 += 4;
        v39 += 20;
        --v41;
    }
    while ( v41 );
    v42 = 7;
    do
    {
        v43 = v6->score_panel[v42];
        if ( v43 )
        {
            if ( v42 == 7 )
                v44 = 0;
            else
                v44 = v6->score_panel[v42 + 1];
            (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, TMessagePanel *))&v43->vfptr->gap10[8])(
                10,
                4,
                0,
                4,
                v42 != 7 ? 0 : 4,
                200,
                200,
                20,
                20,
                0,
                0,
                0,
                v44);
        }
        --v42;
    }
    while ( v42 >= 0 );
    (*(void (__cdecl **)(_DWORD))&v6->text_line_panel->vfptr->gap10[4])(0);
    (*(void (__cdecl **)(_DWORD))&v6->message_panel->vfptr->gap10[4])(0);
    (*(void (__cdecl **)(_DWORD))&v6->message_panel2->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v6->message_panel3->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v6->message_panel4->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v6->message_panel5->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v6->message_panel6->vfptr->gap10[4])(0);
    v45 = save_score_active;
    v46 = (int)v6->score_panel;
    v47 = 8;
    do
    {
        if ( *(_DWORD *)v46 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v46 + 20))(*v45);
        ++v45;
        v46 += 4;
        --v47;
    }
    while ( v47 );
    v48 = HIWORD(RGE_Base_Game::get_player(rge_base_game)->master_players);
    v49 = RGE_Base_Game::get_player(rge_base_game);
    TRIBE_Screen_Game::player_changed(v6, HIWORD(v49->master_players), v48);
    return 0;
}

//----- (00496550) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::handle_paint(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // edi@1
    TDrawArea *v2; // eax@1
    unsigned int v3; // ebx@6
    PanelNode *i; // esi@13
    TPanel *v5; // ecx@15
    unsigned int v6; // eax@20
    PanelNode *v7; // ebp@20
    unsigned int v8; // eax@20
    unsigned int v9; // eax@21
    TPanel *v10; // esi@21
    unsigned int v11; // ebx@21
    unsigned int v12; // eax@24
    int draw_all_children; // [sp+10h] [bp-8h]@9
    unsigned int other_time; // [sp+14h] [bp-4h]@20

    v1 = this;
    v2 = this->render_area;
    if ( v2 && this->visible && this->active && rge_base_game->prog_active && !IsIconic(v2->Wnd) )
    {
        v3 = debug_timeGetTime();
        if ( v1->need_redraw == 2
            || TPanel::get_focus((TPanel *)&v1->main_view->vfptr)
            || v1->curr_child == TPanelSystem::panel(&panel_system, aSendQuickMessa)
            || (draw_all_children = 0, v1->curr_child == TPanelSystem::panel(&panel_system, aHelpDialog)) )
        {
            draw_all_children = 1;
        }
        if ( v1->need_redraw )
        {
            if ( draw_all_children )
            {
                for ( i = v1->first_child_node; i; i = i->next_node )
                    ((void (__stdcall *)(TPanel::RedrawMode))i->panel->vfptr->set_redraw)(v1->need_redraw);
                v5 = v1->parent_panel;
                if ( v5 && v5->overlapping_children )
                    ((void (__stdcall *)(TRIBE_Screen_Game *, TRIBE_Screen_Game *, TPanel::RedrawMode))v5->vfptr->set_overlapped_redraw)(
                        v1,
                        v1,
                        v1->need_redraw);
                v1->vfptr->draw((TPanel *)v1);
            }
            v1->need_redraw = 0;
            v1->just_drawn = 1;
        }
        v6 = debug_timeGetTime();
        v7 = v1->first_child_node;
        v8 = v6 - v3;
        other_time = v8;
        if ( v7 )
        {
            do
            {
                v9 = debug_timeGetTime();
                v10 = v7->panel;
                v11 = v9;
                if ( draw_all_children || v10 == v1->curr_child )
                    v10->vfptr->handle_paint(v7->panel);
                v12 = debug_timeGetTime() - v11;
                if ( v10 != (TPanel *)v1->main_view && v10 != (TPanel *)v1->map_view )
                    other_time += v12;
                v7 = v7->next_node;
            }
            while ( v7 );
            v8 = other_time;
        }
        RGE_Base_Game::add_to_timing(rge_base_game, 17, v8);
        v1->just_drawn = 0;
    }
    return 0;
}

//----- (00496700) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::handle_idle(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // edi@1
    int v2; // esi@3
    int v3; // esi@12

    v1 = this;
    color_log(95, 95, 5);
    if ( !rge_base_game->input_enabled )
    {
        color_log(95, 76, 5);
        RGE_Base_Game::enable_input(rge_base_game);
    }
    color_log(95, 22, 5);
    v2 = rge_base_game->prog_mode;
    if ( (v2 == 4 || v2 == 6 || v2 == 5)
        && (TRIBE_Screen_Game *)TPanelSystem::currentPanel(&panel_system) == v1
        && TPanel::get_focus((TPanel *)&v1->main_view->vfptr) )
    {
        color_log(95, 69, 5);
        TRIBE_Screen_Game::handle_anim_pal(v1);
    }
    if ( v2 == 4 || v2 == 6 )
    {
        color_log(95, 50, 5);
        TRIBE_Screen_Game::handle_terrain_sound(v1);
        color_log(95, -70, 5);
        TRIBE_Screen_Game::handle_mouse_pointing_at(v1);
    }
    color_log(95, 36, 5);
    v3 = TPanel::handle_idle((TPanel *)&v1->vfptr);
    color_log(95, 95, 5);
    return v3;
}

//----- (00496800) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handle_game_update(TRIBE_Screen_Game *this)
{
    int v1; // ebx@1
    TRIBE_Screen_Game *v2; // esi@1
    unsigned int v3; // ebp@4
    unsigned int v4; // ebp@4
    unsigned int v5; // edi@5
    unsigned int v6; // edi@5
    unsigned int v7; // eax@7
    unsigned int v8; // edi@15
    char v9; // bl@16
    TRIBE_Main_View *v10; // ecx@20
    unsigned int v11; // eax@24
    TRIBE_World *v12; // ecx@24
    RGE_Game_World *v13; // eax@32
    TPanel *v14; // eax@39
    RGE_Game_World *v15; // eax@40
    TTextPanel *v16; // ecx@40
    RGE_Base_Game *v17; // ecx@43
    TDigital *v18; // edi@45
    TDigital *v19; // eax@48
    TDigital *v20; // eax@50
    TDigital *v21; // eax@49
    TRIBE_World *v22; // eax@63
    signed int v23; // ecx@63
    signed int v24; // edx@63
    int v25; // eax@64
    TRIBE_World *v26; // edx@67
    unsigned int v27; // eax@67
    unsigned int v28; // edi@68
    int v29; // edi@70
    unsigned int v30; // edi@73
    TMessagePanel *v31; // eax@76
    int num_updates; // [sp+10h] [bp-24h]@10
    unsigned int calc_game_time; // [sp+14h] [bp-20h]@1
    int update_counter; // [sp+18h] [bp-1Ch]@14
    int v35; // [sp+1Ch] [bp-18h]@2

    v1 = 0;
    v2 = this;
    calc_game_time = 0;
    color_log(36, 36, 5);
    if ( debug_timeGetTime() - v2->last_update_time >= v2->update_interval )
    {
        v35 = rge_base_game->prog_mode;
        if ( (unsigned __int8)rge_base_game->prog_mode != 6 )
        {
            color_log(36, 50, 5);
            if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
            {
                v3 = RGE_Base_Game::get_last_single_time(rge_base_game, 2);
                v4 = RGE_Base_Game::get_last_single_time(rge_base_game, 3) + v3;
                if ( !RGE_Base_Game::get_last_world_update_count(rge_base_game)
                    || (v5 = RGE_Base_Game::get_last_world_update_count(rge_base_game),
                            (v6 = RGE_Base_Game::get_last_time(rge_base_game, 1) / v5) == 0) )
                {
                    v6 = 1;
                }
                v7 = comm->Speed->PlayerAvgFramesMsec[TCommunications_Handler::WhoAmI(comm)];
                if ( !multi_updates || v7 < 0x43 || v7 > 0x7D || (num_updates = 2, (double)v6 / (double)(signed int)v4 > 2.0) )
                    num_updates = 1;
                RGE_Base_Game::set_last_single_time(rge_base_game, 2, 0);
                RGE_Base_Game::set_last_single_time(rge_base_game, 3, 0);
            }
            else
            {
                num_updates = 1;
            }
            update_counter = 0;
            if ( num_updates > 0 )
            {
                while ( 1 )
                {
                    color_log(36, 76, 5);
                    color_log(36, 36, 1);
                    v8 = debug_timeGetTime();
                    if ( start_paused )
                    {
                        v9 = 0;
                        (*(void (__stdcall **)(signed int))&rge_base_game->vfptr->gap8[4])(6);
                    }
                    else if ( v2->game_ended )
                    {
                        v9 = 1;
                    }
                    else
                    {
                        v9 = ((int (*)(void))v2->world->vfptr->update)();
                        if ( out_of_sync2 )
                            return;
                        if ( v9 == 1 )
                        {
                            v10 = v2->main_view;
                            v2->game_ended = 1;
                            (*(void (**)(void))&v10->vfptr[1].gap10[0])();
                            RGE_View::set_selection_area((RGE_View *)&v2->main_view->vfptr, -1, -1, -1, -1);
                            (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                            TRIBE_Screen_Game::command_unselect(v2);
                            if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                TRIBE_World::send_zone_score_info(v2->world);
                        }
                    }
                    if ( out_of_sync2 )
                        return;
                    v11 = debug_timeGetTime();
                    v12 = v2->world;
                    v2->last_update_time = v11;
                    if ( v12->world_time_delta )
                    {
                        RGE_Base_Game::add_to_timing(rge_base_game, 1, v11 - v8);
                        RGE_Base_Game::increment_world_update_count(rge_base_game);
                    }
                    color_log(36, -70, 1);
                    if ( v2->reset_after_update )
                    {
                        TRIBE_Screen_Game::reset_clocks(v2);
                        v2->reset_after_update = 0;
                    }
                    if ( v2->watch_mode )
                        TRIBE_Screen_Game::command_view_selected();
                    if ( v2->game_obj != *(RGE_Static_Object **)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num
                        || v2->sel_count != LOWORD(RGE_Base_Game::get_player(rge_base_game)[1].numberNegativeObjectsValue) )
                    {
                        v13 = RGE_Base_Game::get_player(rge_base_game);
                        TRIBE_Panel_Object::set_object(v2->object_panel, *(RGE_Static_Object **)&v13[1].sound_num);
                        TRIBE_Screen_Game::object_changed(v2);
                    }
                    color_log(36, 84, 5);
                    if ( !start_paused
                        && (v9 == 1 || v2->world->players[v2->world->curr_player]->game_status == 2 || v2->player_quit == 1) )
                    {
                        if ( (_BYTE)v35 != 5 )
                        {
                            color_log(36, 69, 5);
                            TRIBE_Screen_Game::command_cancel(v2);
                            TRIBE_Screen_Game::command_unselect(v2);
                            TMessagePanel::remove_message(v2->text_line_panel);
                            TMessagePanel::remove_message(v2->message_panel);
                            TMessagePanel::remove_message(v2->message_panel2);
                            TMessagePanel::remove_message(v2->message_panel3);
                            TMessagePanel::remove_message(v2->message_panel4);
                            TMessagePanel::remove_message(v2->message_panel5);
                            TMessagePanel::remove_message(v2->message_panel6);
                            (*(void (__stdcall **)(signed int))&rge_base_game->vfptr->gap8[4])(5);
                            if ( TPanelSystem::mouseOwner(&panel_system) )
                            {
                                v14 = TPanelSystem::mouseOwner(&panel_system);
                                TPanel::release_mouse(v14);
                            }
                            TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
                            TPanel::set_curr_child((TPanel *)&v2->vfptr, (TPanel *)&v2->main_view->vfptr);
                            TRIBE_Game::close_game_screens((TRIBE_Game *)rge_base_game, 0);
                            (*(void (__stdcall **)(signed int))&v2->pause_text->vfptr->gap10[4])(1);
                            v15 = RGE_Base_Game::get_player(rge_base_game);
                            v16 = v2->pause_text;
                            if ( LOBYTE(v15->sound_driver) == 1 )
                                (*(void (__stdcall **)(signed int))&v16->vfptr[1].gap4[0])(9004);
                            else
                                (*(void (__stdcall **)(signed int))&v16->vfptr[1].gap4[0])(9005);
                            ((void (__stdcall *)(signed int))v2->main_view->vfptr->set_redraw)(1);
                            v17 = rge_base_game;
                            if ( rge_base_game->prog_info->use_sound && rge_base_game->sound_system )
                            {
                                v18 = v2->game_over_sound;
                                if ( v18 )
                                {
                                    TDigital::~TDigital(v2->game_over_sound);
                                    operator delete(v18);
                                    v17 = rge_base_game;
                                }
                                if ( LOBYTE(RGE_Base_Game::get_player(v17)->sound_driver) == 1 )
                                {
                                    v19 = (TDigital *)operator new(0x3Cu);
                                    if ( v19 )
                                    {
                                        TDigital::TDigital(v19, rge_base_game->sound_system, aWon_wav, 50320);
                                        goto LABEL_54;
                                    }
                                }
                                else
                                {
                                    v20 = (TDigital *)operator new(0x3Cu);
                                    if ( v20 )
                                    {
                                        TDigital::TDigital(v20, rge_base_game->sound_system, aLost_wav, 50321);
                                        goto LABEL_54;
                                    }
                                }
                                v21 = 0;
LABEL_54:
                                v2->game_over_sound = v21;
                                if ( v21 )
                                {
                                    TDigital::load(v21, 0, -1);
                                    TDigital::play(v2->game_over_sound);
                                }
                            }
                            v2->game_over_time = debug_timeGetTime();
                            v2->showing_game_over = 1;
                            goto LABEL_67;
                        }
                        if ( v2->showing_game_over )
                        {
                            if ( debug_timeGetTime() - v2->game_over_time > 0x1388 )
                            {
                                color_log(36, 22, 5);
                                v2->showing_game_over = 0;
                                if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
                                {
                                    (*(void (**)(void))&v2->main_view->vfptr[1].gap10[0])();
                                    RGE_View::set_selection_area((RGE_View *)&v2->main_view->vfptr, -1, -1, -1, -1);
                                    (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
                                    TRIBE_Screen_Game::command_unselect(v2);
                                    TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
                                    goto LABEL_91;
                                }
                                if ( !RGE_Base_Game::get_paused(rge_base_game) )
                                    (*(void (__stdcall **)(_DWORD))&v2->pause_text->vfptr->gap10[4])(0);
                                RGE_Base_Game::set_map_visible(rge_base_game, 1);
                                RGE_Base_Game::set_map_fog(rge_base_game, 0);
                                ((void (__stdcall *)(signed int))v2->main_view->vfptr->set_redraw)(2);
                                ((void (__stdcall *)(signed int))v2->map_view->vfptr->set_redraw)(2);
                                (*(void (__stdcall **)(signed int))&v2->quit_message_panel->vfptr->gap10[4])(1);
                                (*(void (__stdcall **)(_DWORD))&v2->pop_panel->vfptr->gap10[4])(0);
                            }
                        }
                        else
                        {
                            v22 = v2->world;
                            v23 = 1;
                            v24 = v22->player_num;
                            if ( v24 > 1 )
                            {
                                v25 = (int)(v22->players + 1);
                                do
                                {
                                    if ( !*(_BYTE *)(*(_DWORD *)v25 + 128) )
                                        break;
                                    ++v23;
                                    v25 += 4;
                                }
                                while ( v23 < v24 );
                            }
                        }
                    }
LABEL_67:
                    v26 = v2->world;
                    v27 = v26->world_time_delta;
                    if ( v27 )
                    {
                        v28 = *(_DWORD *)&rge_base_game[1].timing_text[56];
                        if ( v28 )
                        {
                            if ( v26->world_time >= v28 )
                            {
                                RGE_Base_Game::close(rge_base_game);
                                goto LABEL_91;
                            }
                        }
                    }
                    v29 = v27 + calc_game_time;
                    calc_game_time += v27;
                    if ( ++update_counter >= num_updates )
                    {
                        v1 = v29;
                        break;
                    }
                }
            }
        }
        if ( (TRIBE_Screen_Game *)TPanelSystem::currentPanel(&panel_system) == v2 )
        {
            color_log(22, 76, 5);
            v30 = debug_timeGetTime();
            if ( v1 )
            {
                if ( (unsigned int)(signed __int64)*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                                                                                        + 24) != v2->save_age )
                    TRIBE_Screen_Game::age_changed(v2);
                v31 = v2->score_panel[0];
                if ( v31 && v31->active && v30 - v2->last_score_time >= v2->score_interval )
                {
                    TRIBE_Screen_Game::reset_score_display(v2);
                    v2->last_score_time = debug_timeGetTime();
                }
            }
            if ( TPanel::get_focus((TPanel *)&v2->main_view->vfptr)
                || v2->curr_child == TPanelSystem::panel(&panel_system, aSendQuickMessa)
                || v2->curr_child == TPanelSystem::panel(&panel_system, aHelpDialog) )
            {
                color_log(22, 84, 5);
                if ( v1 || v30 - v2->last_view_time >= v2->view_interval )
                {
                    ((void (__stdcall *)(_DWORD))v2->main_view->vfptr->set_redraw)(1);
                    v2->last_view_time = v30;
                }
                if ( v1 && v30 - v2->last_map_redraw_time >= v2->map_redraw_interval )
                {
                    ((void (__stdcall *)(signed int))v2->map_view->vfptr->set_redraw)(1);
                    v2->last_map_redraw_time = v30;
                }
                color_log(22, 36, 5);
                if ( v2->main_view->need_redraw )
                    RGE_Base_Game::draw_window(rge_base_game);
            }
        }
    }
LABEL_91:
    color_log(36, 95, 5);
}
// 586318: using guessed type int multi_updates;
// 62C564: using guessed type int out_of_sync2;
// 86BAD0: using guessed type int start_paused;

//----- (004970A0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::wnd_proc(TRIBE_Screen_Game *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
    signed int v5; // esi@1
    TRIBE_Screen_Game *v6; // ebx@1
    int v8; // edi@11
    int v9; // ebp@11
    int v10; // eax@11
    int v11; // eax@19

    v5 = msg;
    v6 = this;
    if ( msg == 260 && wParam == 121 && this->have_focus && this->curr_child == (TPanel *)this->main_view )
    {
        TRIBE_Screen_Game::command_menu(this);
        return 1;
    }
    if ( msg == 257 && this->have_focus && TPanel::get_focus((TPanel *)&this->main_view->vfptr) )
    {
        if ( wParam == 114 || wParam == 19 )
        {
            v8 = GetKeyState(18) < 0;
            v9 = GetKeyState(17) < 0;
            v10 = GetKeyState(16) < 0;
            if ( !v8 && !v9 && !v10 )
                TRIBE_Screen_Game::command_pause(v6);
            v5 = 257;
        }
        return TPanel::wnd_proc((TPanel *)&v6->vfptr, hwnd, v5, wParam, lParam);
    }
    if ( msg != 16 )
    {
        if ( msg == 520 )
            TRIBE_Game::goto_notification_loc((TRIBE_Game *)rge_base_game);
        return TPanel::wnd_proc((TPanel *)&v6->vfptr, hwnd, v5, wParam, lParam);
    }
    if ( confirmed_close )
        return TPanel::wnd_proc((TPanel *)&v6->vfptr, hwnd, v5, wParam, lParam);
    confirmed_close = 1;
    v11 = rge_base_game->prog_mode;
    if ( v11 != 5 && v11 != 4 && v11 != 6 && v11 != 7 )
        return TPanel::wnd_proc((TPanel *)&v6->vfptr, hwnd, v5, wParam, lParam);
    if ( IsIconic(v6->render_area->Wnd) )
        return TPanel::wnd_proc((TPanel *)&v6->vfptr, hwnd, v5, wParam, lParam);
    TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v6->vfptr, 3101, aCloseprogramdi, 450, 100);
    return 1;
}
// 86BACC: using guessed type int confirmed_close;

//----- (00497210) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::handle_mouse_down(TRIBE_Screen_Game *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
    TRIBE_Screen_Game *v6; // esi@1

    v6 = this;
    TMessagePanel::remove_message(this->message_panel);
    TMessagePanel::remove_message(v6->message_panel2);
    TMessagePanel::remove_message(v6->message_panel3);
    TMessagePanel::remove_message(v6->message_panel4);
    TMessagePanel::remove_message(v6->message_panel5);
    TMessagePanel::remove_message(v6->message_panel6);
    return TEasy_Panel::handle_mouse_down((TEasy_Panel *)&v6->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
}

//----- (00497280) --------------------------------------------------------
int __stdcall TRIBE_Screen_Game::handle_user_command(unsigned int wParam, int lParam)
{
    return TPanel::handle_user_command(wParam, lParam);
}

//----- (004972A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handle_pause(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    TTextPanel *v2; // ecx@1

    v1 = this;
    (*(void (__stdcall **)(signed int))&this->pause_text->vfptr[1].gap4[0])(9001);
    v2 = v1->pause_text;
    if ( !v2->active )
    {
        (*(void (__stdcall **)(signed int))&v2->vfptr->gap10[4])(1);
        ((void (__stdcall *)(signed int))v1->pause_text->vfptr->set_redraw)(1);
    }
    ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(1);
}

//----- (004972F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handle_resume(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    TTextPanel *v2; // ecx@1

    v1 = this;
    v2 = this->pause_text;
    if ( v2->active )
    {
        (*(void (__stdcall **)(_DWORD))&v2->vfptr->gap10[4])(0);
        ((void (__stdcall *)(signed int))v1->pause_text->vfptr->set_redraw)(1);
        ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(1);
    }
}

//----- (00497330) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handleChatReceived(TRIBE_Screen_Game *this, int line_no)
{
    TRIBE_Screen_Game *v2; // ebx@1
    const char *v3; // edi@1
    TRIBE_World *v4; // edx@1
    int v5; // eax@1
    char chat_msg[256]; // [sp+Ch] [bp-100h]@1

    v2 = this;
    v3 = TChat::GetChatMsg(chat, line_no);
    v4 = v2->world;
    strcpy(chat_msg, v3);
    TDebuggingLog::Log(L, aReceivedChat_U, v4->world_time, chat_msg);
    TMessagePanel::show_message(v2->chat_panel[v2->chat_line], ChatMessage, chat_msg, -1, 0, 0, 0, 0);
    v5 = v2->chat_line + 1;
    v2->chat_line = v5;
    if ( v5 >= 8 )
        v2->chat_line = 0;
}

//----- (004973F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::display_system_message(TRIBE_Screen_Game *this, char *msg)
{
    TRIBE_Screen_Game *v2; // esi@1
    int v3; // eax@1

    v2 = this;
    TMessagePanel::show_message(this->chat_panel[this->chat_line], ChatMessage, msg, -1, 0, 0, 0, 0);
    v3 = v2->chat_line + 1;
    v2->chat_line = v3;
    if ( v3 >= 8 )
        v2->chat_line = 0;
}

//----- (00497440) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::key_down_action(TRIBE_Screen_Game *this, int key, int count, int alt_key, int ctrl_key, int shift_key)
{
    TRIBE_Screen_Game *v6; // ebp@1
    RGE_Panel_Tool_Box *v7; // ecx@2
    int v8; // ebx@2
    int result; // eax@4
    int v10; // eax@18
    int v11; // eax@20
    int v12; // ecx@25
    RGE_Base_Game *v13; // ecx@77
    signed int v14; // edi@79
    int v15; // esi@80
    RGE_Game_World *v16; // eax@81
    TDigital **v17; // eax@84
    int v18; // eax@90
    int *v19; // edx@90
    int v20; // eax@93
    TribeSaveGameScreen *v21; // eax@109
    RGE_Game_World *v22; // eax@144
    RGE_Game_World *v23; // eax@146
    RGE_Game_World *v24; // eax@148
    int v25; // eax@151
    int v26; // edi@153
    int v27; // eax@157
    int v28; // eax@162
    int v29; // eax@167
    TribeSaveGameScreen::Mode v30; // [sp-Ch] [bp-22Ch]@110
    int game_over; // [sp+10h] [bp-210h]@5
    char str[512]; // [sp+14h] [bp-20Ch]@117
    int v33; // [sp+21Ch] [bp-4h]@109

    v6 = this;
    if ( TPanelSystem::modalPanel(&panel_system) )
        return 0;
    v7 = v6->tool_box;
    v8 = key;
    if ( v7->active
        && ((int (__stdcall *)(int, int, int, int, int))v7->vfptr->key_down_action)(
                 key,
                 count,
                 alt_key,
                 ctrl_key,
                 shift_key) )
    {
        return 1;
    }
    game_over = rge_base_game->prog_mode == 5;
    if ( ctrl_key && shift_key && alt_key )
    {
        if ( rge_base_game->prog_mode != 5 )
        {
            if ( key > 122 || key < 97 )
            {
                if ( (key > 90 || key < 65) && (key < 48 || key > 57) )
                    v8 = 0;
            }
            else
            {
                v8 = key - 32;
            }
            if ( v8 )
            {
                v10 = v6->cheat_code_entry;
                if ( v10 == 50 )
                {
                    v6->cheat_code_entry_str[50] = v8;
                    qmemcpy(v6->cheat_code_entry_str, &v6->cheat_code_entry_str[1], 0x33u);
                }
                else
                {
                    v6->cheat_code_entry_str[v10] = v8;
                    v11 = v6->cheat_code_entry + 1;
                    v6->cheat_code_entry = v11;
                    v6->cheat_code_entry_str[v11] = 0;
                }
                if ( ((int (__stdcall *)(_DWORD, char *))rge_base_game->vfptr->processCheatCode)(
                             v6->world->curr_player,
                             v6->cheat_code_entry_str) )
                {
                    v6->cheat_code_entry = 0;
                    v6->cheat_code_entry_str[0] = 0;
                    return 1;
                }
            }
        }
        return 1;
    }
    if ( RGE_Base_Game::gameDeveloperMode(rge_base_game) && TCommunications_Handler::IsHost(comm) )
    {
        v12 = ctrl_key;
        if ( !ctrl_key )
            goto LABEL_35;
        if ( shift_key && key >= 50 && key <= 56 )
        {
            TCommunications_Handler::Kick(comm, key - 48);
            return 1;
        }
    }
    else
    {
        v12 = ctrl_key;
    }
    if ( v12 && key >= 48 && key <= 57 )
    {
        TRIBE_Screen_Game::command_group_by_number(key - 48);
        return 1;
    }
LABEL_35:
    if ( shift_key )
    {
        switch ( key )
        {
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
                TRIBE_Screen_Game::command_select_group(v6, key - 48, 0);
                result = 1;
                break;
            case 112:
                TEasy_Panel::setup_popup_help((TEasy_Panel *)&v6->vfptr);
                result = 1;
                break;
            case 113:
                if ( game_over || !allow_user_commands )
                    return 1;
                TRIBE_Screen_Game::command_formation(0);
                result = 1;
                break;
            case 114:
                if ( game_over || !allow_user_commands )
                    return 1;
                TRIBE_Screen_Game::command_formation(1);
                result = 1;
                break;
            case 115:
                if ( game_over || !allow_user_commands )
                    return 1;
                TRIBE_Screen_Game::command_formation(2);
                result = 1;
                break;
            case 116:
                if ( game_over || !allow_user_commands )
                    return 1;
                TRIBE_Screen_Game::command_formation(3);
                result = 1;
                break;
            case 117:
                if ( game_over || !allow_user_commands )
                    return 1;
                TRIBE_Screen_Game::command_formation(4);
                result = 1;
                break;
            case 118:
                if ( game_over || !allow_user_commands )
                    return 1;
                TRIBE_Screen_Game::command_formation(5);
                result = 1;
                break;
            case 9:
                TRIBE_Screen_Game::command_tab_selected(0);
                result = 1;
                break;
            default:
                goto LABEL_58;
        }
        return result;
    }
LABEL_58:
    if ( alt_key )
    {
        switch ( key )
        {
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
                TRIBE_Screen_Game::command_select_group(v6, key, 1);
                TRIBE_Screen_Game::command_view_selected();
                result = 1;
                break;
            case 73:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                rge_base_game->display_selected_ids = rge_base_game->display_selected_ids == 0;
                result = 1;
                break;
            case 80:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                MapPathsDisplay = MapPathsDisplay == 0;
                result = 1;
                break;
            case 83:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                view_debug_spans = view_debug_spans == 0;
                result = 1;
                break;
            case 67:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                view_debug_redraw_all = 1;
                result = 1;
                break;
            case 79:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                view_debug_ObstructionMap = view_debug_ObstructionMap == 0;
                result = 1;
                break;
            case 65:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                view_debug_Objects = view_debug_Objects == 0;
                result = 1;
                break;
            case 88:
                if ( !RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                    return 1;
                view_debug_palette = view_debug_palette == 0;
                result = 1;
                break;
            default:
                return 0;
        }
        return result;
    }
    if ( v12 || RGE_Base_Game::get_paused(rge_base_game) )
    {
        v13 = rge_base_game;
    }
    else
    {
        v13 = rge_base_game;
        if ( rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1 )
        {
            v14 = 0;
            if ( v6->item_cnt > 0 )
            {
                v15 = 0;
                while ( 1 )
                {
                    v16 = RGE_Base_Game::get_player(v13);
                    if ( key == *TPanel::get_string(*(_DWORD *)(*(_DWORD *)(v16->sprite_update_index + 4 * v6->bldg_list[v15].id)
                                                                                                        + 160)) )
                        break;
                    v13 = rge_base_game;
                    ++v14;
                    ++v15;
                    if ( v14 >= v6->item_cnt )
                        goto LABEL_89;
                }
                v17 = RGE_Base_Game::get_sound(rge_base_game, 1);
                if ( v17 )
                    TDigital::play((TDigital *)v17);
                TRIBE_Screen_Game::command_building(v6, v6->bldg_list[v14].id);
                return 1;
            }
        }
    }
LABEL_89:
    if ( !ctrl_key )
    {
LABEL_93:
        v20 = v6->view_town_center_hotkey;
        if ( v20 && key == v20 )
        {
            TRIBE_Screen_Game::command_select_building(v6, 0);
            return 0;
        }
        if ( ctrl_key )
        {
            if ( RGE_Base_Game::gameDeveloperMode(v13) )
            {
                switch ( key )
                {
                    case 112:
                        TRIBE_Screen_Game::command_player(v6, 1);
                        return 1;
                    case 113:
                        TRIBE_Screen_Game::command_player(v6, 2);
                        return 1;
                    case 114:
                        TRIBE_Screen_Game::command_player(v6, 3);
                        return 1;
                    case 115:
                        TRIBE_Screen_Game::command_player(v6, 4);
                        return 1;
                    case 116:
                        TRIBE_Screen_Game::command_player(v6, 5);
                        return 1;
                    case 117:
                        TRIBE_Screen_Game::command_player(v6, 6);
                        return 1;
                    case 118:
                        TRIBE_Screen_Game::command_player(v6, 7);
                        return 1;
                    case 119:
                        TRIBE_Screen_Game::command_player(v6, 8);
                        return 1;
                    case 120:
                        TRIBE_Screen_Game::command_player(v6, 0);
                        return 1;
                    case 32:
                        TRIBE_Screen_Game::command_view_selected();
                        return 0;
                    case 69:
                        v21 = (TribeSaveGameScreen *)operator new(0x6A4u);
                        v33 = 0;
                        if ( !v21 )
                            goto LABEL_140;
                        v30 = 0;
                        goto LABEL_139;
                    case 70:
                        if ( allow_user_commands )
                            TRIBE_Screen_Game::command_add_attribute(0);
                        return 0;
                    case 71:
                        if ( allow_user_commands )
                            TRIBE_Screen_Game::command_add_attribute(3);
                        return 0;
                    case 73:
                        *(_DWORD *)&rge_base_game[1].work_dir[20] = *(_DWORD *)&rge_base_game[1].work_dir[20] == 0;
                        ((void (__stdcall *)(signed int))v6->object_panel->vfptr->set_redraw)(1);
                        return 0;
                    case 74:
                        TCommunications_Handler::TXDebugPing(comm);
                        return 0;
                    case 77:
                        sprintf(str, aWritingOutMemo, ++mem_file_num);
                        TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, str, 0, -1);
                        sprintf(str, aCMemD_txt, mem_file_num);
                        RGE_Base_Game::dump_memory_usage(rge_base_game, str);
                        TRIBE_Game::close_status_message();
                        return 0;
                    case 78:
                        if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
                            TRIBE_Game::restart_game((TRIBE_Game *)rge_base_game);
                        return 0;
                    case 79:
                        if ( rge_base_game->outline_type == 3 )
                        {
                            rge_base_game->outline_type = 2;
                            result = 1;
                        }
                        else
                        {
                            rge_base_game->outline_type = 3;
                            result = 1;
                        }
                        return result;
                    case 81:
                        if ( allow_user_commands )
                            TRIBE_Screen_Game::command_quick_build(v6);
                        return 0;
                    case 82:
                        ++View_Grid_Mode;
                        if ( RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                        {
                            if ( View_Grid_Mode <= 4 )
                                goto LABEL_130;
                        }
                        else if ( View_Grid_Mode <= 1 )
                        {
                            goto LABEL_130;
                        }
                        View_Grid_Mode = 0;
LABEL_130:
                        ((void (__stdcall *)(signed int))v6->main_view->vfptr->set_redraw)(2);
                        break;
                    case 83:
                        if ( allow_user_commands )
                            TRIBE_Screen_Game::command_add_attribute(2);
                        return 0;
                    case 84:
                        TRIBE_Screen_Game::command_tool_box(v6, ctrl_key);
                        return 0;
                    case 85:
                        if ( RGE_Base_Game::gameDeveloperMode(rge_base_game)
                            && RGE_Base_Game::check_prog_argument(rge_base_game, aAllowctrlu) )
                        {
                            TDebuggingLog::Log(L, aUserPressedCtr);
                            displayPathingFlags = displayPathingFlags == 0;
                        }
                        return 0;
                    case 86:
                        v21 = (TribeSaveGameScreen *)operator new(0x6A4u);
                        v33 = 1;
                        if ( v21 )
                        {
                            v30 = 1;
LABEL_139:
                            TribeSaveGameScreen::TribeSaveGameScreen(v21, v30, 0, 0);
                        }
LABEL_140:
                        v33 = -1;
                        TPanelSystem::setCurrentPanel(&panel_system, aSaveGameScreen, 0);
                        return 0;
                    case 87:
                        if ( allow_user_commands )
                            TRIBE_Screen_Game::command_add_attribute(1);
                        return 0;
                    case 88:
                        if ( allow_user_commands )
                        {
                            v22 = RGE_Base_Game::get_player(rge_base_game);
                            v22->vfptr->color_table_init(v22, 1);
                        }
                        return 0;
                    case 89:
                        if ( allow_user_commands )
                        {
                            v23 = RGE_Base_Game::get_player(rge_base_game);
                            v23->vfptr->color_table_init(v23, 2);
                        }
                        return 0;
                    case 90:
                        if ( allow_user_commands )
                        {
                            v24 = RGE_Base_Game::get_player(rge_base_game);
                            v24->vfptr->color_table_init(v24, 3);
                        }
                        return 0;
                    default:
                        return 0;
                }
            }
            return 0;
        }
        if ( v13->game_mode == 6 && v13->sub_game_mode == 1 )
        {
            v26 = game_over;
        }
        else
        {
            v25 = v6->work_hotkey;
            if ( v25 && key == v25 )
            {
                v26 = game_over;
                if ( !game_over )
                {
                    if ( allow_user_commands )
                        TRIBE_Screen_Game::command_work(v6);
                    return 0;
                }
            }
            else
            {
                v26 = game_over;
            }
            v27 = v6->move_hotkey;
            if ( v27 && key == v27 && !v26 )
            {
                if ( allow_user_commands )
                    TRIBE_Screen_Game::command_move(v6);
                return 0;
            }
            v28 = v6->attack_hotkey;
            if ( v28 && key == v28 && !v26 )
            {
                if ( allow_user_commands )
                    TRIBE_Screen_Game::command_attack(v6);
                return 0;
            }
            v29 = v6->ungroup_hotkey;
            if ( v29 && key == v29 )
            {
                TRIBE_Screen_Game::command_ungroup(v6);
                return 0;
            }
        }
        switch ( key )
        {
            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
                TRIBE_Screen_Game::command_select_group(v6, key - 48, 1);
                return 0;
            case 9:
                TRIBE_Screen_Game::command_tab_selected(1);
                return 1;
            case 115:
                TRIBE_Screen_Game::command_score(v6, v6->world->score_displayed == 0);
                break;
            case 116:
                TRIBE_Screen_Game::command_fps(v6);
                break;
            case 117:
                if ( RGE_Base_Game::gameDeveloperMode(v13) )
                    TRIBE_Screen_Game::command_visibility(v6);
                break;
            case 118:
                if ( RGE_Base_Game::gameDeveloperMode(v13) )
                    TRIBE_Screen_Game::command_fog_of_war(v6);
                break;
            case 119:
                if ( RGE_Base_Game::gameDeveloperMode(v13) )
                    TRIBE_Screen_Game::command_comm_info(v6);
                break;
            case 120:
                if ( RGE_Base_Game::gameDeveloperMode(v13) )
                    TRIBE_Screen_Game::command_ai_info(v6);
                break;
            case 122:
                if ( TRIBE_Panel_Time::get_clock_type(v6->time_panel) )
                {
                    TRIBE_Panel_Time::set_clock_type(v6->time_panel, 0, 0);
                    (*(void (__stdcall **)(_DWORD))&v6->pop_panel->vfptr->gap10[4])(0);
                }
                else
                {
                    TRIBE_Panel_Time::set_clock_type(v6->time_panel, 2, 0);
                    (*(void (__stdcall **)(signed int))&v6->pop_panel->vfptr->gap10[4])(1);
                }
                TRIBE_Screen_Game::reset_clocks(v6);
                ((void (__stdcall *)(signed int))v6->main_view->vfptr->set_redraw)(1);
                break;
            case 32:
                TRIBE_Screen_Game::command_view_selected();
                break;
            case 13:
                TRIBE_Screen_Game::command_quick_chat(v6);
                break;
            case 36:
                TRIBE_Game::goto_notification_loc((TRIBE_Game *)v13);
                break;
            case 46:
                if ( !v26 && allow_user_commands )
                    TRIBE_Screen_Game::command_cancel_building();
                break;
            default:
                return 0;
        }
        return 0;
    }
    v18 = 0;
    v19 = v6->select_building_hotkey;
    while ( key != *v19 )
    {
        ++v18;
        ++v19;
        if ( v18 >= 8 )
            goto LABEL_93;
    }
    TRIBE_Screen_Game::command_select_building(v6, v18);
    return 1;
}
// 58631C: using guessed type int allow_user_commands;
// 62E668: using guessed type int displayPathingFlags;
// 86B138: using guessed type int MapPathsDisplay;
// 87D7A0: using guessed type int view_debug_spans;
// 87D7A4: using guessed type int view_debug_redraw_all;
// 87D7A8: using guessed type int view_debug_ObstructionMap;
// 87D7AC: using guessed type int view_debug_Objects;
// 87D7B0: using guessed type int view_debug_palette;
// 87D7B4: using guessed type int View_Grid_Mode;

//----- (00498290) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::char_action(TRIBE_Screen_Game *this, int key, __int16 count)
{
    if ( key == 43 )
    {
LABEL_7:
        if ( allow_user_commands )
            TRIBE_Screen_Game::command_game_speed(this, 1);
        return 0;
    }
    if ( key != 45 )
    {
        if ( key != 61 )
            return 0;
        goto LABEL_7;
    }
    if ( allow_user_commands )
    {
        TRIBE_Screen_Game::command_game_speed(this, 0);
        return 0;
    }
    return 0;
}
// 58631C: using guessed type int allow_user_commands;

//----- (004982E0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Game::action(TRIBE_Screen_Game *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
    TRIBE_Screen_Game *v5; // esi@1
    RGE_Panel_Tool_Box *v6; // ecx@3
    signed int v7; // eax@9
    TPanel **v8; // ecx@9
    RGE_Base_Game *v9; // ecx@17
    RGE_Game_World *v10; // eax@30
    RGE_Game_World *v11; // esi@30
    RGE_Game_WorldVtbl *v12; // edi@30
    unsigned int v13; // eax@30
    TribeLoadSavedGameScreen *v14; // eax@33
    TRIBE_Screen_Game *v16; // [sp+Ch] [bp-10h]@1

    v5 = this;
    v16 = this;
    if ( !from_panel )
        return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, 0, action_in, action_val1, action_val2);
    v6 = this->tool_box;
    if ( (RGE_Panel_Tool_Box *)from_panel != v6
        && v6->active
        && ((int (__stdcall *)(TPanel *, int, unsigned int, unsigned int))v6->vfptr->action)(
                 from_panel,
                 action_in,
                 action_val1,
                 action_val2) )
    {
        return 1;
    }
    if ( action_in != 1 && action_in != 4 )
    {
LABEL_12:
        if ( from_panel == (TPanel *)v5->object_panel && action_in == 1 )
        {
            TRIBE_Screen_Game::object_changed(v5);
            return 1;
        }
        if ( TPanel::panelName(from_panel) )
        {
            if ( !strcmp(TPanel::panelName(from_panel), aRestartdialog) )
            {
                TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
                TPanelSystem::destroyPanel(&panel_system, aRestartdialog);
                v9 = rge_base_game;
                if ( !action_in )
                {
                    TRIBE_Game::restart_game((TRIBE_Game *)rge_base_game);
                    return 1;
                }
                goto LABEL_37;
            }
            if ( !strcmp(TPanel::panelName(from_panel), aQuitgamedialog) )
            {
                TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
                TPanelSystem::destroyPanel(&panel_system, aQuitgamedialog);
                if ( !action_in )
                {
                    TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
                    return 1;
                }
                goto LABEL_25;
            }
            if ( !strcmp(TPanel::panelName(from_panel), aCloseprogramdi) )
            {
                TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
                TPanelSystem::destroyPanel(&panel_system, aCloseprogramdi);
                if ( !action_in )
                {
                    RGE_Base_Game::close(rge_base_game);
                    return 1;
                }
LABEL_25:
                confirmed_close = 0;
                if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
                {
                    RGE_Base_Game::set_paused(rge_base_game, 0, 0);
                    return 1;
                }
                return 1;
            }
            if ( !strcmp(TPanel::panelName(from_panel), aResigndialog) )
            {
                TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
                TPanelSystem::destroyPanel(&panel_system, aResigndialog);
                if ( !action_in )
                {
                    v16->player_quit = 1;
                    v10 = RGE_Base_Game::get_player(rge_base_game);
                    v11 = v10;
                    v12 = v10->vfptr;
                    v13 = TCommunications_Handler::WhoAmI(comm);
                    v12->new_scenario(v11, (RGE_Player_Info *)v13, 0);
                    return 1;
                }
LABEL_36:
                v9 = rge_base_game;
LABEL_37:
                if ( RGE_Base_Game::singlePlayerGame(v9) == 1 && !rge_base_game->save_paused )
                    RGE_Base_Game::set_paused(rge_base_game, 0, 0);
                return 1;
            }
            if ( !strcmp(TPanel::panelName(from_panel), panel_title) )
            {
                TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
                TPanelSystem::destroyPanel(&panel_system, panel_title);
                if ( !action_in )
                {
                    v14 = (TribeLoadSavedGameScreen *)operator new(0x494u);
                    if ( v14 )
                        TribeLoadSavedGameScreen::TribeLoadSavedGameScreen(v14);
                    TPanelSystem::setCurrentPanel(&panel_system, aLoadSavedGameS, 0);
                    return 1;
                }
                goto LABEL_36;
            }
            v5 = v16;
        }
        return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, from_panel, action_in, action_val1, action_val2);
    }
    v7 = 0;
    v8 = (TPanel **)v5->button_panel;
    while ( from_panel != *v8 )
    {
        ++v7;
        ++v8;
        if ( v7 >= 17 )
            goto LABEL_12;
    }
    TRIBE_Screen_Game::do_button_action(v5, action_val1, action_val2, action_in == 4);
    return 1;
}
// 86BACC: using guessed type int confirmed_close;

//----- (004987A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::do_button_action(TRIBE_Screen_Game *this, int action_in, int action2_in, int right_btn)
{
    if ( allow_user_commands )
    {
        switch ( action_in )
        {
            case 1:
                TRIBE_Screen_Game::command_work(this);
                return;
            case 2:
                TRIBE_Screen_Game::command_move(this);
                return;
            case 3:
                TRIBE_Screen_Game::command_build(this);
                return;
            case 4:
                TRIBE_Screen_Game::command_trade(this);
                return;
            case 5:
                TRIBE_Screen_Game::command_stop();
                return;
            case 7:
                TRIBE_Screen_Game::command_unload(this);
                return;
            case 16:
                TRIBE_Screen_Game::command_trade_with(this, action2_in);
                return;
            case 17:
                TRIBE_Screen_Game::command_research(this, action2_in);
                return;
            case 18:
                TRIBE_Screen_Game::command_train(this, action2_in, right_btn != 0 ? -1 : 1);
                return;
            case 19:
                TRIBE_Screen_Game::command_building(this, action2_in);
                return;
            case 20:
                TRIBE_Screen_Game::command_cancel_building();
                return;
            case 22:
                TRIBE_Screen_Game::command_stand_ground();
                return;
            case 23:
                TRIBE_Screen_Game::command_attack_ground(this);
                return;
            case 25:
                TRIBE_Screen_Game::command_trade_attribute(0);
                return;
            case 26:
                TRIBE_Screen_Game::command_trade_attribute(1);
                return;
            case 27:
                TRIBE_Screen_Game::command_trade_attribute(2);
                return;
            case 28:
                TRIBE_Screen_Game::command_heal(this);
                return;
            case 29:
                TRIBE_Screen_Game::command_convert(this);
                return;
            case 30:
                TRIBE_Screen_Game::command_attack(this);
                return;
            case 31:
                TRIBE_Screen_Game::command_repair(this);
                return;
            case 32:
                TRIBE_Screen_Game::command_train(this, action2_in, 1);
                return;
            case 33:
                TRIBE_Screen_Game::command_train(this, action2_in, -1);
                return;
            case 6:
                goto LABEL_26;
            case 8:
                goto LABEL_27;
            case 9:
                goto LABEL_28;
            case 11:
                goto LABEL_29;
            case 12:
                goto LABEL_30;
            case 13:
                goto LABEL_31;
            case 14:
                goto LABEL_32;
            case 15:
                goto LABEL_33;
            case 21:
                goto LABEL_34;
            case 24:
                goto LABEL_35;
            default:
                return;
        }
    }
    else
    {
        switch ( action_in )
        {
            case 6:
LABEL_26:
                TRIBE_Screen_Game::command_unselect(this);
                break;
            case 8:
LABEL_27:
                TRIBE_Screen_Game::command_group();
                break;
            case 9:
LABEL_28:
                TRIBE_Screen_Game::command_ungroup(this);
                break;
            case 11:
LABEL_29:
                TRIBE_Screen_Game::command_cancel(this);
                break;
            case 12:
LABEL_30:
                TRIBE_Screen_Game::command_more(this);
                break;
            case 13:
LABEL_31:
                TRIBE_Screen_Game::command_chat(this);
                break;
            case 14:
LABEL_32:
                TRIBE_Screen_Game::command_diplomacy(this);
                break;
            case 15:
LABEL_33:
                TRIBE_Screen_Game::command_menu(this);
                break;
            case 21:
LABEL_34:
                TEasy_Panel::setup_popup_help((TEasy_Panel *)&this->vfptr);
                break;
            case 24:
LABEL_35:
                TRIBE_Screen_Game::command_score(this, this->world->score_displayed == 0);
                break;
            default:
                return;
        }
    }
}
// 58631C: using guessed type int allow_user_commands;

//----- (00498A10) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::game_mode_changed(TRIBE_Screen_Game *this, int old_mode, int new_mode)
{
    TRIBE_Screen_Game *v3; // esi@1
    RGE_Panel_Tool_Box *v4; // ecx@1

    v3 = this;
    v4 = this->tool_box;
    if ( v4 )
        RGE_Panel_Tool_Box::game_mode_changed(v4, old_mode, new_mode);
    if ( v3->button_panel[0] )
        TRIBE_Screen_Game::reset_buttons(v3);
}

//----- (00498A50) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::player_changed(TRIBE_Screen_Game *this, int old_player_id, int new_player_id)
{
    TRIBE_Screen_Game *v3; // esi@1
    RGE_Player *v4; // edi@1
    signed int v5; // eax@2
    int v6; // edx@4
    int v7; // ebx@4
    TShape *v8; // edi@18
    TShape *v9; // eax@21
    TShape *v10; // eax@22
    TShape *v11; // eax@23
    TShape *v12; // edi@26
    TShape *v13; // eax@29
    TShape *v14; // eax@30
    TShape *v15; // eax@31
    TShape *v16; // edi@34
    TShape *v17; // eax@37
    TShape *v18; // eax@38
    TShape *v19; // eax@39
    TShape *v20; // edi@42
    TShape *v21; // eax@45
    TShape *v22; // eax@46
    TShape *v23; // eax@47
    TShape *v24; // edi@50
    signed int v25; // eax@52
    int v26; // edi@55
    TShape *v27; // eax@64
    TShape *v28; // eax@65
    signed int v29; // eax@67
    TRIBE_Panel_Button **v30; // edx@67
    TShape *v31; // ecx@69
    TRIBE_Panel_Button *v32; // edi@71
    char str[512]; // [sp+14h] [bp-20Ch]@6
    int v34; // [sp+21Ch] [bp-4h]@21

    v3 = this;
    v4 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
    RGE_View::set_player((RGE_View *)&v3->main_view->vfptr, v4);
    RGE_Diamond_Map::set_player((RGE_Diamond_Map *)&v3->map_view->vfptr, v4);
    TRIBE_Panel_Inven::set_player(v3->inven_panel, (TRIBE_Player *)v4);
    TRIBE_Panel_Object::set_player(v3->object_panel, (TRIBE_Player *)v4);
    TRIBE_Screen_Game::game_mode_changed(v3, rge_base_game->game_mode, rge_base_game->game_mode);
    TRIBE_Screen_Game::object_changed(v3);
    TRIBE_Screen_Game::age_changed(v3);
    if ( !v4->id )
        goto LABEL_84;
    v5 = v4->culture;
    if ( v5 == v3->save_culture && v3->pnl_wid == v3->save_screen_width )
        goto LABEL_84;
    v6 = v3->pnl_wid;
    v7 = v4->culture;
    v3->save_culture = v5;
    v3->save_screen_width = v6;
    if ( v5 >= 5 )
        v7 = 0;
    sprintf(str, aDlg6_D, v7);
    if ( v7 == 4 )
    {
        TEasy_Panel::set_info_file((TEasy_Panel *)&v3->vfptr, str, 53000);
        TEasy_Panel::set_popup_info_file((TEasy_Panel *)&v3->vfptr, str, 53000);
    }
    else
    {
        TEasy_Panel::set_info_file((TEasy_Panel *)&v3->vfptr, str, v7 + 50006);
        TEasy_Panel::set_popup_info_file((TEasy_Panel *)&v3->vfptr, str, v7 + 50006);
    }
    sprintf(str, aBtn6_D, v7);
    if ( v7 == 4 )
        TEasy_Panel::set_button_pics((TEasy_Panel *)&v3->vfptr, str, 53004);
    else
        TEasy_Panel::set_button_pics((TEasy_Panel *)&v3->vfptr, str, v7 + 50605);
    switch ( v7 )
    {
        case 0:
            TEasy_Panel::set_bevel_colors((TEasy_Panel *)&v3->vfptr, 126, 109, 111, 111, -18, 56);
            break;
        case 1:
            TEasy_Panel::set_bevel_colors((TEasy_Panel *)&v3->vfptr, 114, 115, 116, 116, -73, -72);
            break;
        case 2:
            TEasy_Panel::set_bevel_colors((TEasy_Panel *)&v3->vfptr, -71, 119, 120, 120, 120, 121);
            break;
        case 3:
            TEasy_Panel::set_bevel_colors((TEasy_Panel *)&v3->vfptr, -118, -19, -18, -18, 56, -107);
            break;
        case 4:
            TEasy_Panel::set_bevel_colors((TEasy_Panel *)&v3->vfptr, 115, 116, 117, 117, 118, 119);
            break;
        default:
            break;
    }
    TButtonPanel::set_bevel_info(
        (TButtonPanel *)v3->button_panel[12],
        3,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    TButtonPanel::set_bevel_info(
        (TButtonPanel *)v3->button_panel[13],
        3,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    TButtonPanel::set_bevel_info(
        (TButtonPanel *)v3->button_panel[14],
        3,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    TButtonPanel::set_bevel_info(
        (TButtonPanel *)v3->button_panel[15],
        4,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    TButtonPanel::set_bevel_info(
        (TButtonPanel *)v3->button_panel[16],
        4,
        v3->bevel_color1,
        v3->bevel_color2,
        v3->bevel_color3,
        v3->bevel_color4,
        v3->bevel_color5,
        v3->bevel_color6);
    v8 = v3->button_border1_pic;
    if ( v8 )
    {
        TShape::~TShape(v3->button_border1_pic);
        operator delete(v8);
    }
    sprintf(str, aBtnbrdaD_shp, v7);
    if ( v7 == 4 )
    {
        v9 = (TShape *)operator new(0x20u);
        v34 = 0;
        if ( v9 )
        {
            TShape::TShape(v9, str, 53006);
            goto LABEL_26;
        }
    }
    else
    {
        v11 = (TShape *)operator new(0x20u);
        v34 = 1;
        if ( v11 )
        {
            TShape::TShape(v11, str, v7 + 50713);
            goto LABEL_26;
        }
    }
    v10 = 0;
LABEL_26:
    v12 = v3->button_other_pic;
    v34 = -1;
    v3->button_border1_pic = v10;
    if ( v12 )
    {
        TShape::~TShape(v12);
        operator delete(v12);
    }
    sprintf(str, aBtnothD_shp, v7);
    if ( v7 == 4 )
    {
        v13 = (TShape *)operator new(0x20u);
        v34 = 2;
        if ( v13 )
        {
            TShape::TShape(v13, str, 53009);
            goto LABEL_34;
        }
    }
    else
    {
        v15 = (TShape *)operator new(0x20u);
        v34 = 3;
        if ( v15 )
        {
            TShape::TShape(v15, str, v7 + 50725);
            goto LABEL_34;
        }
    }
    v14 = 0;
LABEL_34:
    v16 = v3->button_border2_pic;
    v34 = -1;
    v3->button_other_pic = v14;
    if ( v16 )
    {
        TShape::~TShape(v16);
        operator delete(v16);
    }
    sprintf(str, aBtnbrdbD_shp, v7);
    if ( v7 == 4 )
    {
        v17 = (TShape *)operator new(0x20u);
        v34 = 4;
        if ( v17 )
        {
            TShape::TShape(v17, str, 53007);
            goto LABEL_42;
        }
    }
    else
    {
        v19 = (TShape *)operator new(0x20u);
        v34 = 5;
        if ( v19 )
        {
            TShape::TShape(v19, str, v7 + 50717);
            goto LABEL_42;
        }
    }
    v18 = 0;
LABEL_42:
    v20 = v3->button_border3_pic;
    v34 = -1;
    v3->button_border2_pic = v18;
    if ( v20 )
    {
        TShape::~TShape(v20);
        operator delete(v20);
    }
    sprintf(str, aBtnbrdcD_shp, v7);
    if ( v7 != 4 )
    {
        v23 = (TShape *)operator new(0x20u);
        v34 = 7;
        if ( v23 )
        {
            TShape::TShape(v23, str, v7 + 50747);
            goto LABEL_50;
        }
LABEL_49:
        v22 = 0;
        goto LABEL_50;
    }
    v21 = (TShape *)operator new(0x20u);
    v34 = 6;
    if ( !v21 )
        goto LABEL_49;
    TShape::TShape(v21, str, 53008);
LABEL_50:
    v24 = v3->game_screen_pic;
    v34 = -1;
    v3->button_border3_pic = v22;
    if ( v24 )
    {
        TShape::~TShape(v24);
        operator delete(v24);
    }
    v25 = v3->pnl_wid;
    if ( v25 < 1024 || v3->pnl_hgt < 768 )
    {
        if ( v25 < 800 || v3->pnl_hgt < 600 )
        {
            sprintf(str, aGameaD_shp, v7);
            v26 = 53010;
            if ( v7 != 4 )
                v26 = v7 + 50733;
        }
        else
        {
            sprintf(str, aGamebD_shp, v7);
            if ( v7 == 4 )
                v26 = 53011;
            else
                v26 = v7 + 50737;
        }
    }
    else
    {
        sprintf(str, aGamecD_shp, v7);
        if ( v7 == 4 )
            v26 = 53012;
        else
            v26 = v7 + 50741;
    }
    v27 = (TShape *)operator new(0x20u);
    v34 = 8;
    if ( v27 )
        TShape::TShape(v27, str, v26);
    else
        v28 = 0;
    v3->game_screen_pic = v28;
    v34 = -1;
    v29 = 0;
    v30 = v3->button_panel;
    do
    {
        if ( v29 >= 12 )
            v31 = v3->button_border2_pic;
        else
            v31 = v3->button_border1_pic;
        v32 = *v30;
        ++v29;
        ++v30;
        *((_DWORD *)v32 + 177) = v31;
    }
    while ( v29 < 17 );
    if ( v3->pnl_wid < 800 || v3->pnl_hgt < 600 )
        v3->more_cancel_pic = v3->button_other_pic;
    else
        v3->more_cancel_pic = v3->button_cmd_pic;
    TButtonPanel::set_picture((TButtonPanel *)v3->button_panel[5], 0, v3->more_cancel_pic, v3->more_frame);
    if ( TButtonPanel::get_id((TButtonPanel *)v3->button_panel[11]) == 6 )
        TButtonPanel::set_picture((TButtonPanel *)v3->button_panel[11], 0, v3->more_cancel_pic, v3->unselect_frame);
    else
        TButtonPanel::set_picture((TButtonPanel *)v3->button_panel[11], 0, v3->more_cancel_pic, v3->cancel_frame);
    if ( v7 == 2 || v7 == 3 || v7 == 4 )
    {
        TRIBE_Panel_Inven::set_text_color(v3->inven_panel, 0xFFFFFFu, 0);
        TTextPanel::set_text_color(v3->age_panel, 0xFFFFFFu, 0);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[12], 0, 0xFFFFFFu, 0);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[13], 0, 0xFFFFFFu, 0);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[14], 0, 0xFFFFFFu, 0);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[15], 0, 0xFFFFFFu, 0);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[16], 0, 0xFFFFFFu, 0);
    }
    else
    {
        TRIBE_Panel_Inven::set_text_color(v3->inven_panel, 0, 0xFFFFFFu);
        TTextPanel::set_text_color(v3->age_panel, 0, 0xFFFFFFu);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[12], 0, 0, 0xFFFFFFu);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[13], 0, 0, 0xFFFFFFu);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[14], 0, 0, 0xFFFFFFu);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[15], 0, 0, 0xFFFFFFu);
        TButtonPanel::set_text_color((TButtonPanel *)v3->button_panel[16], 0, 0, 0xFFFFFFu);
    }
LABEL_84:
    TRIBE_Screen_Game::setup_buttons(v3);
    v3->vfptr->set_redraw((TPanel *)v3, RedrawNormal);
}

//----- (004992E0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::object_changed(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    int v2; // edi@1
    RGE_Base_Game *v3; // ecx@2
    int v4; // eax@4

    v1 = this;
    v2 = this->game_obj != *(RGE_Static_Object **)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num;
    v1->game_obj = *(RGE_Static_Object **)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num;
    v1->sel_count = RGE_Base_Game::get_player(rge_base_game)[1].numberNegativeObjectsValue;
    if ( v2 )
    {
        v3 = rge_base_game;
        if ( rge_base_game->game_mode == 21 )
        {
            (*(void (**)(void))&v1->main_view->vfptr[1].gap10[0])();
            RGE_View::set_selection_area((RGE_View *)&v1->main_view->vfptr, -1, -1, -1, -1);
            v3 = rge_base_game;
        }
        v4 = v3->game_mode;
        if ( (_BYTE)v4 != 1
            && (_BYTE)v4 != 18
            && (_BYTE)v4 != 14
            && (_BYTE)v4 != 2
            && (_BYTE)v4 != 3
            && (_BYTE)v4 != 8
            && (_BYTE)v4 != 9
            && (_BYTE)v4 != 10 )
        {
            (*(void (__stdcall **)(_DWORD, _DWORD))&v3->vfptr->gap8[8])(0, 0);
        }
    }
    TRIBE_Screen_Game::reset_buttons(v1);
}

//----- (004993B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::age_changed(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    signed __int64 v2; // rax@2
    char str[512]; // [sp+14h] [bp-200h]@2

    v1 = this;
    if ( this->age_panel )
    {
        v2 = (signed __int64)*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 24);
        v1->save_age = v2;
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
            101,
            v2,
            0,
            str,
            512);
        (*(void (__stdcall **)(char *))&v1->age_panel->vfptr[1].gap4[4])(str);
        ((void (__stdcall *)(signed int))v1->age_panel->vfptr->set_redraw)(1);
        switch ( v1->save_age )
        {
            case 1:
                TPanel::set_help_info((TPanel *)&v1->age_panel->vfptr, 4201, -1);
                break;
            case 2:
                TPanel::set_help_info((TPanel *)&v1->age_panel->vfptr, 4202, -1);
                break;
            case 3:
                TPanel::set_help_info((TPanel *)&v1->age_panel->vfptr, 4203, -1);
                break;
            case 4:
                TPanel::set_help_info((TPanel *)&v1->age_panel->vfptr, 4204, -1);
                break;
            default:
                return;
        }
    }
}

//----- (004994B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::show_timings(TRIBE_Screen_Game *this, char *str1, char *str2)
{
    TRIBE_Screen_Game *v3; // edi@1
    const char *v4; // eax@1

    v3 = this;
    v4 = TTextPanel::get_text(this->fps_panel);
    if ( !v4 || strcmp(v4, str2) )
        (*(void (__stdcall **)(char *))&v3->fps_panel->vfptr[1].gap4[4])(str2);
}

//----- (00499520) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::show_comm(TRIBE_Screen_Game *this, char *str, char *str2, char *str3, char *str4, char *str5, char *str6)
{
    TRIBE_Screen_Game *v7; // esi@1

    v7 = this;
    TMessagePanel::show_message(this->message_panel, DebugMessage, str, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel2, DebugMessage, str2, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel3, DebugMessage, str3, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel4, DebugMessage, str4, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel5, DebugMessage, str5, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel6, DebugMessage, str6, 86, 0, 0, 0, 0);
}

//----- (004995D0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::show_ai(TRIBE_Screen_Game *this, char *str, char *str2, char *str3, char *str4, char *str5, char *str6)
{
    TRIBE_Screen_Game *v7; // esi@1

    v7 = this;
    TMessagePanel::show_message(this->message_panel, DebugMessage, str, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel2, DebugMessage, str2, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel3, DebugMessage, str3, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel4, DebugMessage, str4, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel5, DebugMessage, str5, 86, 0, 0, 0, 0);
    TMessagePanel::show_message(v7->message_panel6, DebugMessage, str6, 86, 0, 0, 0, 0);
}

//----- (00499680) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::show_message(TRIBE_Screen_Game *this, TMessagePanel::MessageType message_type, char *str, char font_color_in, char back_color_in)
{
    TMessagePanel::show_message(this->message_panel, message_type, str, font_color_in, back_color_in, 0, 0, 0);
}

//----- (004996B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::reset_buttons(TRIBE_Screen_Game *this)
{
    this->start_item = 0;
    TRIBE_Screen_Game::setup_buttons(this);
}

//----- (004996C0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::setup_buttons(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@1
    signed int v3; // ecx@1
    int v4; // edi@2
    RGE_Static_Object *v5; // eax@3
    TRIBE_Player *v6; // edi@4
    int v7; // eax@6
    Item_Avail **v8; // ebx@8
    __int16 v9; // bp@8
    int v10; // edx@9
    __int16 *v11; // eax@9
    int v12; // edi@9
    int v13; // ebp@16
    RGE_Master_Static_Object *v14; // edi@16
    signed int v15; // ecx@16
    __int16 v16; // ax@24
    bool v17; // sf@25
    unsigned __int8 v18; // of@25
    char v19; // al@32
    __int16 v20; // cx@49
    signed int v21; // ebp@49
    __int16 v22; // dx@49
    RGE_Static_Object *v23; // eax@51
    RGE_Master_Static_Object *v24; // eax@52
    __int16 v25; // bx@58
    signed __int16 v26; // bx@70
    __int16 v27; // cx@70
    __int16 v28; // dx@70
    RGE_Static_Object *v29; // eax@72
    __int16 v30; // dx@87
    TRIBE_Building_Object *v31; // edi@89
    __int16 v32; // cx@91
    char v33; // al@93
    void **v34; // ebp@101
    TShape *v35; // ST00_4@103
    int v36; // ebx@105
    int v37; // ecx@105
    RGE_Master_Static_Object **v38; // eax@105
    int v39; // edx@105
    RGE_Master_Static_Object *v40; // edi@105
    __int16 v41; // cx@106
    Production_Queue_Record *v42; // eax@107
    int v43; // eax@114
    Item_Avail *v44; // edx@114
    TRIBE_Player *v45; // ebx@119
    __int16 v46; // di@125
    void *v47; // eax@128
    int v48; // eax@129
    float *v49; // eax@129
    float *v50; // ecx@129
    float *v51; // edx@129
    __int16 v52; // ax@130
    RGE_Base_GameVtbl *v53; // ebx@131
    int v54; // edi@131
    __int16 v55; // ax@131
    __int16 v56; // ax@131
    char v57; // al@131
    int v58; // eax@131
    char *v59; // ecx@131
    int v60; // ST2C_4@131
    int v61; // ebx@131
    char *v62; // ST20_4@131
    int v63; // eax@131
    bool v64; // bl@142
    __int16 v65; // bp@142
    RGE_Action_Object *v66; // ecx@144
    char v67; // al@145
    signed __int16 v68; // bp@159
    __int16 v69; // bx@170
    TShape *v70; // [sp-30h] [bp-474h]@28
    TShape *v71; // [sp-30h] [bp-474h]@36
    TShape *v72; // [sp-30h] [bp-474h]@45
    TShape *v73; // [sp-30h] [bp-474h]@63
    TShape *v74; // [sp-30h] [bp-474h]@165
    TShape *v75; // [sp-30h] [bp-474h]@175
    __int16 v76; // [sp-2Ch] [bp-470h]@28
    __int16 v77; // [sp-2Ch] [bp-470h]@36
    __int16 v78; // [sp-2Ch] [bp-470h]@45
    __int16 v79; // [sp-2Ch] [bp-470h]@63
    __int16 v80; // [sp-2Ch] [bp-470h]@78
    __int16 v81; // [sp-2Ch] [bp-470h]@165
    __int16 v82; // [sp-2Ch] [bp-470h]@175
    __int16 v83; // [sp-28h] [bp-46Ch]@28
    __int16 v84; // [sp-28h] [bp-46Ch]@36
    __int16 v85; // [sp-28h] [bp-46Ch]@45
    __int16 v86; // [sp-28h] [bp-46Ch]@63
    __int16 v87; // [sp-28h] [bp-46Ch]@78
    __int16 v88; // [sp-28h] [bp-46Ch]@165
    __int16 v89; // [sp-28h] [bp-46Ch]@175
    int v90; // [sp-24h] [bp-468h]@28
    int v91; // [sp-1Ch] [bp-460h]@36
    int v92; // [sp-1Ch] [bp-460h]@45
    int v93; // [sp-1Ch] [bp-460h]@63
    int v94; // [sp-1Ch] [bp-460h]@175
    TRIBE_Player *player; // [sp+10h] [bp-434h]@4
    __int16 playera; // [sp+10h] [bp-434h]@142
    int inv_3; // [sp+14h] [bp-430h]@8
    int inv_1; // [sp+18h] [bp-42Ch]@4
    int inv_amt_3; // [sp+1Ch] [bp-428h]@15
    int inv_amt_2; // [sp+20h] [bp-424h]@8
    TRIBE_Building_Object *inv_2; // [sp+24h] [bp-420h]@8
    int tech_cnt; // [sp+28h] [bp-41Ch]@101
    int v103; // [sp+2Ch] [bp-418h]@129
    int inv_amt_1; // [sp+30h] [bp-414h]@16
    int make_cnt; // [sp+34h] [bp-410h]@101
    __int16 progress; // [sp+3Ah] [bp-40Ah]@90
    int work_type; // [sp+3Ch] [bp-408h]@90
    __int16 work_target; // [sp+42h] [bp-402h]@90
    char name[512]; // [sp+44h] [bp-400h]@24
    char msg_str[512]; // [sp+244h] [bp-200h]@24

    v1 = this;
    this->item_cnt = 0;
    this->last_item = -1;
    v2 = (char *)this->button_panel;
    v3 = 12;
    do
    {
        v4 = *(_DWORD *)v2;
        v2 += 4;
        --v3;
        *(_DWORD *)(v4 + 976) = 0;
    }
    while ( v3 );
    v5 = v1->game_obj;
    v1->mouse_last_x = -1;
    v1->mouse_last_y = -1;
    if ( !v5 )
        goto LABEL_183;
    v6 = (TRIBE_Player *)RGE_Base_Game::get_player(rge_base_game);
    player = v6;
    inv_1 = v6->culture;
    if ( inv_1 > 5 )
        inv_1 = 0;
    v7 = rge_base_game->game_mode;
    if ( v7 == 6 && rge_base_game->sub_game_mode == 1 )
    {
        v8 = &v1->bldg_list;
        TRIBE_Player::interface_item_avail(v6, &v1->bldg_list, &v1->item_cnt, 118);
        v9 = v1->item_cnt;
        inv_3 = 0;
        inv_amt_2 = -1;
        inv_2 = (TRIBE_Building_Object *)-1;
        if ( v9 > 0 )
        {
            v10 = 0;
            v11 = &(*v8)->id;
            v12 = v9;
            do
            {
                if ( *v11 == 109 )
                {
                    inv_amt_2 = v10;
                }
                else if ( *v11 == 87 )
                {
                    inv_2 = (TRIBE_Building_Object *)v10;
                }
                ++v10;
                v11 += 20;
                --v12;
            }
            while ( v12 );
        }
        inv_amt_3 = 0;
        if ( v9 > 0 )
        {
            do
            {
                v13 = (signed __int16)inv_amt_3;
                v14 = player->master_objects[(*v8)[v13].id];
                v15 = v14[1].create_doppleganger_on_death;
                inv_amt_1 = v14[1].create_doppleganger_on_death;
                if ( (signed __int16)inv_amt_3 == inv_amt_2 && inv_2 == (TRIBE_Building_Object *)-1 )
                {
                    v15 = 6;
                    inv_amt_1 = 6;
                }
                if ( v1->start_item )
                {
                    if ( v15 >= 11 )
                    {
LABEL_24:
                        (*(void (__stdcall **)(_DWORD, char *, signed int))&rge_base_game->vfptr->gap8[24])(
                            v14->string_id,
                            name,
                            512);
                        TRIBE_Screen_Game::calc_text_msg(msg_str, &(*v8)[v13], 19, v14->string_id2);
                        v16 = TRIBE_Screen_Game::calc_button_loc(inv_amt_1);
                        TRIBE_Screen_Game::set_button(
                            v1,
                            v1->button_bldg_pics[inv_1],
                            v16,
                            (*v8)[v13].pict + HIWORD(v14[1].outline_radius_z),
                            19,
                            (*v8)[v13].id,
                            v14->string_id2 + 100000,
                            (*v8)[v13].help_page_id,
                            v14->hotkey_id,
                            player->color_table->table,
                            name,
                            msg_str,
                            0);
                        goto LABEL_25;
                    }
                    inv_3 = 1;
                }
                else
                {
                    if ( v15 <= 10 )
                        goto LABEL_24;
                    inv_3 = 1;
                }
LABEL_25:
                v18 = __OFSUB__(inv_amt_3 + 1, v1->item_cnt);
                v17 = (signed __int16)(inv_amt_3++ + 1 - v1->item_cnt) < 0;
            }
            while ( v17 ^ v18 );
        }
        if ( inv_3 )
            TRIBE_Screen_Game::set_button(v1, v1->more_cancel_pic, 5, v1->more_frame, 12, 0, 120023, -1, 0, 0, 0, 0, 0);
        v90 = 11;
        v83 = v1->cancel_frame;
        v76 = 11;
        v70 = v1->more_cancel_pic;
        goto LABEL_182;
    }
    if ( v7 || rge_base_game->prog_mode == 5 )
    {
        v30 = v1->cancel_frame;
        v90 = 11;
        goto LABEL_181;
    }
    if ( (TRIBE_Player *)v1->game_obj->owner != v6 )
        goto LABEL_169;
    v19 = RGE_Player::unit_level_selected((RGE_Player *)&v6->vfptr);
    if ( v19 == 3 )
    {
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 2, 3, 0, 120031, -1, 0, 0, 0, 0, 0);
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 1, 0, 31, 0, 120054, -1, 0, 0, 0, 0, 0);
        if ( TRIBE_Screen_Game::any_selected_have_action() )
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 2, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        if ( v6->sel_count > 1 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v91 = 20035;
            v84 = 8;
            v77 = 7;
            v71 = v1->button_cmd_pic;
LABEL_39:
            TRIBE_Screen_Game::set_button(v1, v71, v77, v84, 9, 0, v91, -1, 0, 0, 0, 0, 0);
            goto LABEL_169;
        }
        if ( v1->game_obj->selected_group )
        {
            v91 = 120035;
            v84 = 8;
            v77 = 6;
            v71 = v1->button_cmd_pic;
            goto LABEL_39;
        }
LABEL_169:
        v90 = 6;
        v83 = v1->unselect_frame;
        v76 = 11;
        v70 = v1->more_cancel_pic;
        goto LABEL_182;
    }
    if ( v19 == 9 )
    {
        if ( TRIBE_Screen_Game::any_selected_have_action() )
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        if ( v6->sel_count > 1 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v92 = 120035;
            v85 = 8;
            v78 = 7;
            v72 = v1->button_cmd_pic;
LABEL_86:
            TRIBE_Screen_Game::set_button(v1, v72, v78, v85, 9, 0, v92, -1, 0, 0, 0, 0, 0);
            goto LABEL_87;
        }
        if ( v1->game_obj->selected_group )
        {
LABEL_85:
            v92 = 120035;
            v85 = 8;
            v78 = 6;
            v72 = v1->button_cmd_pic;
            goto LABEL_86;
        }
LABEL_87:
        v30 = v1->unselect_frame;
        v90 = 6;
LABEL_181:
        v83 = v30;
        v76 = 11;
        v70 = v1->more_cancel_pic;
        goto LABEL_182;
    }
    if ( v19 == 4 )
    {
        v20 = 0;
        v21 = 1;
        v22 = 0;
        while ( v22 < v1->sel_count )
        {
            v23 = v6->sel_list[v20];
            if ( v23 )
            {
                v24 = v23->master_obj;
                if ( v24[1].attribute_type_held[1] == -1 || v24[1].construction_radius_y == 0.0 )
                {
                    v21 = 0;
                    break;
                }
                ++v22;
            }
            if ( ++v20 >= 25 )
                break;
        }
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 4, 22, 0, 120042, -1, 0, 0, 0, 0, 0);
        v25 = 1;
        if ( v21 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 1, 12, 23, 0, 120043, -1, 0, 0, 0, 0, 0);
            v25 = 2;
        }
        if ( TRIBE_Screen_Game::any_selected_have_action() )
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, v25, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        if ( v6->sel_count > 1 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v93 = 120035;
            v86 = 8;
            v79 = 7;
            v73 = v1->button_cmd_pic;
            goto LABEL_138;
        }
LABEL_136:
        if ( !v1->game_obj->selected_group )
        {
LABEL_139:
            v30 = v1->unselect_frame;
            v90 = 6;
            goto LABEL_181;
        }
        v93 = 120035;
        v86 = 8;
        v79 = 6;
        v73 = v1->button_cmd_pic;
LABEL_138:
        TRIBE_Screen_Game::set_button(v1, v73, v79, v86, 9, 0, v93, -1, 0, 0, 0, 0, 0);
        goto LABEL_139;
    }
    if ( v19 == 6 )
    {
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 13, 28, 0, 120049, -1, 0, 0, 0, 0, 0);
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 1, 14, 29, 0, 120050, -1, 0, 0, 0, 0, 0);
        if ( TRIBE_Screen_Game::any_selected_have_action() )
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 2, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        if ( v6->sel_count > 1 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v92 = 20035;
            v85 = 8;
            v78 = 7;
            v72 = v1->button_cmd_pic;
            goto LABEL_86;
        }
LABEL_84:
        if ( v1->game_obj->selected_group )
            goto LABEL_85;
        goto LABEL_87;
    }
    if ( v19 == 7 )
    {
        v26 = 0;
        v27 = 0;
        v28 = 0;
        while ( v28 < v6->sel_count )
        {
            v29 = v6->sel_list[v27];
            if ( v29 )
            {
                ++v28;
                if ( v29->objects->number_of_objects > 0 )
                {
                    TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 5, 7, 0, 120041, -1, 0, 0, 0, 0, 0);
                    v26 = 1;
                    break;
                }
            }
            if ( ++v27 >= 25 )
                break;
        }
        if ( TRIBE_Screen_Game::any_selected_have_action() )
        {
            v87 = 3;
            v80 = v26;
LABEL_163:
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, v80, v87, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
            goto LABEL_164;
        }
        goto LABEL_164;
    }
    if ( v19 == 5 )
    {
        TRIBE_Screen_Game::set_button(v1, v1->button_tech_pic, 1, 87, 25, 0, 107100, 157103, 0, 0, 0, 0, 0);
        TRIBE_Screen_Game::set_button(v1, v1->button_tech_pic, 2, 86, 26, 0, 107101, 157103, 0, 0, 0, 0, 0);
        TRIBE_Screen_Game::set_button(v1, v1->button_tech_pic, 3, 88, 27, 0, 107102, 157103, 0, 0, 0, 0, 0);
        if ( TRIBE_Screen_Game::any_selected_have_action() )
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        if ( v6->sel_count > 1 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v92 = 120035;
            v85 = 8;
            v78 = 7;
            v72 = v1->button_cmd_pic;
            goto LABEL_86;
        }
        goto LABEL_84;
    }
    if ( v19 != 2 || (v31 = (TRIBE_Building_Object *)v1->game_obj, inv_2 = v31, v31->master_obj->master_type != 80) )
    {
        v6 = player;
        if ( !v19 && player->sel_count > 1 )
        {
            v64 = 0;
            v65 = 0;
            LOBYTE(inv_1) = 1;
            playera = 0;
            while ( playera < v6->sel_count )
            {
                v66 = (RGE_Action_Object *)v6->sel_list[v65];
                if ( v66 )
                {
                    v67 = v66->master_obj->unit_level;
                    if ( v67 != 3 && v67 != 9 && v67 != 4 && v67 != 5 && v67 != 6 && v67 != 7 && v67 != 8 )
                    {
                        LOBYTE(inv_1) = 0;
                        break;
                    }
                    if ( !v64 )
                        v64 = RGE_Action_Object::have_action(v66);
                    ++playera;
                }
                if ( ++v65 >= 25 )
                    break;
            }
            if ( (_BYTE)inv_1 )
            {
                v68 = 0;
                if ( RGE_Player::is_group_selected((RGE_Player *)&v6->vfptr, 4) )
                {
                    v68 = 1;
                    TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 2, 3, 0, 120031, -1, 0, 0, 0, 0, 0);
                }
                if ( v64 )
                {
                    v87 = 3;
                    v80 = v68;
                    goto LABEL_163;
                }
LABEL_164:
                if ( v6->sel_count <= 1 )
                {
                    if ( !v1->game_obj->selected_group )
                        goto LABEL_169;
                    v88 = 8;
                    v81 = 6;
                    v74 = v1->button_cmd_pic;
                }
                else
                {
                    TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
                    v88 = 8;
                    v81 = 7;
                    v74 = v1->button_cmd_pic;
                }
                TRIBE_Screen_Game::set_button(v1, v74, v81, v88, 9, 0, 120035, -1, 0, 0, 0, 0, 0);
                goto LABEL_169;
            }
        }
        v69 = 0;
        if ( RGE_Player::is_group_selected((RGE_Player *)&v6->vfptr, 4) )
        {
            v69 = 1;
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 2, 3, 0, 120031, -1, 0, 0, 0, 0, 0);
        }
        if ( TRIBE_Screen_Game::any_selected_have_action() )
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, v69, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        if ( v6->sel_count <= 1 )
        {
            if ( !v1->game_obj->selected_group )
            {
LABEL_179:
                v90 = 11;
                v83 = v1->unselect_frame;
                v76 = 11;
                v70 = v1->more_cancel_pic;
                goto LABEL_182;
            }
            v94 = 120035;
            v89 = 8;
            v82 = 6;
            v75 = v1->button_cmd_pic;
        }
        else
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v94 = 20035;
            v89 = 8;
            v82 = 7;
            v75 = v1->button_cmd_pic;
        }
        TRIBE_Screen_Game::set_button(v1, v75, v82, v89, 9, 0, v94, -1, 0, 0, 0, 0, 0);
        goto LABEL_179;
    }
    TRIBE_Building_Object::work_status(v31, (__int16 *)&work_type, &work_target, &progress, name, 512);
    if ( progress == 100 )
    {
        v32 = 0;
        work_type = 0;
    }
    else
    {
        v32 = work_type;
    }
    v33 = v31->object_state;
    if ( (unsigned __int8)v33 < 2u )
    {
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 3, 20, 0, 120037, -1, 0, 0, 0, 0, 0);
        v90 = 6;
        v83 = v1->unselect_frame;
        v76 = 11;
        v70 = v1->more_cancel_pic;
LABEL_182:
        TRIBE_Screen_Game::set_button(v1, v70, v76, v83, v90, 0, 120025, -1, 0, 0, 0, 0, 0);
        goto LABEL_183;
    }
    if ( v33 != 2 )
    {
LABEL_100:
        v90 = 6;
        v83 = v1->unselect_frame;
        v76 = 11;
        v70 = v1->more_cancel_pic;
        goto LABEL_182;
    }
    if ( v32 == 103 || v32 == 102 && !production_queues_is_use )
    {
        TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 0, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
        goto LABEL_100;
    }
    v34 = (void **)&v1->tech_list;
    TRIBE_Player::interface_tech_avail(player, &v1->tech_list, (__int16 *)&tech_cnt, v1->game_obj->master_obj->id);
    TRIBE_Player::interface_item_avail(player, &v1->make_list, (__int16 *)&make_cnt, v1->game_obj->master_obj->id);
    LOBYTE(inv_1) = 0;
    v1->item_cnt = tech_cnt + make_cnt;
    if ( production_queues_is_use && v31->production_queue_count > 0 )
    {
        v35 = v1->button_cmd_pic;
        LOBYTE(inv_1) = 1;
        TRIBE_Screen_Game::set_button(v1, v35, 6, 3, 5, 0, 120029, -1, 0, 0, 0, 0, 0);
    }
    inv_amt_3 = 0;
    if ( (signed __int16)make_cnt <= 0 )
    {
        v45 = player;
    }
    else
    {
        do
        {
            v36 = (signed __int16)inv_amt_3;
            v37 = v1->make_list[v36].id;
            v38 = player->master_objects;
            v39 = 0;
            inv_amt_2 = 0;
            v40 = v38[v37];
            if ( !(_BYTE)inv_1 )
                goto LABEL_186;
            v41 = inv_2->production_queue_count;
            if ( v41 > 0 )
            {
                v42 = inv_2->production_queue;
                inv_3 = v41;
                do
                {
                    if ( v42->master_id == v40->id )
                        v39 += v42->unit_count;
                    ++v42;
                    --inv_3;
                }
                while ( inv_3 );
                inv_amt_2 = v39;
            }
            if ( !(_BYTE)inv_1 || v39 > 0 )
            {
LABEL_186:
                (*(void (__stdcall **)(_DWORD, char *, signed int))&rge_base_game->vfptr->gap8[24])(v40->string_id, name, 512);
                TRIBE_Screen_Game::calc_text_msg(msg_str, &v1->make_list[v36], 18, v40->string_id2);
                LOWORD(v43) = TRIBE_Screen_Game::calc_button_loc(v40[1].create_doppleganger_on_death);
                v44 = v1->make_list;
                inv_3 = v43;
                TRIBE_Screen_Game::set_button(
                    v1,
                    v1->button_unit_pic,
                    v43,
                    v44[v36].pict,
                    18,
                    v44[v36].id,
                    v40->string_id2 + 100000,
                    v44[v36].help_page_id,
                    v40->hotkey_id,
                    player->color_table->table,
                    name,
                    msg_str,
                    0);
                if ( inv_amt_2 > 0 && (_BYTE)inv_1 )
                {
                    TRIBE_Panel_Button::set_display_garrison(v1->button_panel[(signed __int16)inv_3], 1);
                    TRIBE_Panel_Button::set_garrison_number(v1->button_panel[(signed __int16)inv_3], inv_amt_2);
                }
                else
                {
                    TRIBE_Panel_Button::set_display_garrison(v1->button_panel[(signed __int16)inv_3], 0);
                }
            }
            ++inv_amt_3;
        }
        while ( (signed __int16)inv_amt_3 < (signed __int16)make_cnt );
        v45 = player;
        v31 = inv_2;
    }
    inv_amt_2 = 0;
    if ( !(_BYTE)inv_1 )
    {
        if ( v31->master_obj->id == 109
            && !(_WORD)tech_cnt
            && (signed int)(signed __int64)*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 24) < 4 )
        {
            v46 = (unsigned __int64)(signed __int64)*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                                                                                             + 24)
                    + 100;
            if ( TRIBE_Player_Tech::get_tech_state(v45->tech_tree, v46) != -1 )
            {
                if ( *v34 )
                    free(*v34);
                v47 = calloc(1u, 0x28u);
                *v34 = v47;
                if ( v47 )
                {
                    tech_cnt = 1;
                    TRIBE_Player_Tech::tech_cost(
                        v45->tech_tree,
                        v46,
                        (__int16 *)&inv_1,
                        (__int16 *)&inv_amt_1,
                        (__int16 *)&inv_2,
                        (__int16 *)&inv_amt_2,
                        (__int16 *)&inv_3,
                        (__int16 *)&inv_amt_3);
                    *((_WORD *)*v34 + 2) = v46;
                    v48 = v46;
                    *(_DWORD *)*v34 = v1->world->tech->tech_tree[v48].name;
                    *((_WORD *)*v34 + 3) = v1->world->tech->tech_tree[v48].icon;
                    *((_WORD *)*v34 + 4) = inv_1;
                    v49 = (float *)*v34;
                    v103 = (signed __int16)inv_amt_1;
                    v49[3] = (double)(signed __int16)inv_amt_1;
                    *((_WORD *)*v34 + 8) = (_WORD)inv_2;
                    v50 = (float *)*v34;
                    v103 = (signed __int16)inv_amt_2;
                    v50[5] = (double)(signed __int16)inv_amt_2;
                    *((_WORD *)*v34 + 12) = inv_3;
                    v51 = (float *)*v34;
                    v103 = (signed __int16)inv_amt_3;
                    v51[7] = (double)(signed __int16)inv_amt_3;
                    *((_DWORD *)*v34 + 8) = TRIBE_Player_Tech::get_help_message(v45->tech_tree, v46);
                    *((_DWORD *)*v34 + 9) = TRIBE_Player_Tech::get_help_page(v45->tech_tree, v46);
                    inv_amt_2 = 1;
                }
            }
        }
        v52 = 0;
        inv_amt_3 = 0;
        if ( (signed __int16)tech_cnt > 0 )
        {
            do
            {
                v53 = rge_base_game->vfptr;
                v54 = 40 * v52;
                v55 = TRIBE_Player_Tech::get_string_id(player->tech_tree, *(_WORD *)((char *)*v34 + v54 + 4));
                (*(void (__thiscall **)(RGE_Base_Game *, _DWORD, char *, signed int))&v53->gap8[24])(
                    rge_base_game,
                    v55,
                    name,
                    512);
                v56 = TRIBE_Player_Tech::get_string_id2(player->tech_tree, *(_WORD *)((char *)*v34 + v54 + 4));
                TRIBE_Screen_Game::calc_text_msg(msg_str, (Item_Avail *)((char *)*v34 + v54), 17, v56);
                v57 = TRIBE_Player_Tech::get_button_location(player->tech_tree, *(_WORD *)((char *)*v34 + v54 + 4));
                LOWORD(v58) = TRIBE_Screen_Game::calc_button_loc(v57);
                v59 = (char *)*v34;
                inv_3 = v58;
                v60 = inv_amt_2;
                v61 = (int)&v59[v54];
                v62 = player->color_table->table;
                v63 = TRIBE_Player_Tech::get_hotkey(player->tech_tree, *(_WORD *)((char *)*v34 + v54 + 4));
                TRIBE_Screen_Game::set_button(
                    v1,
                    v1->button_tech_pic,
                    inv_3,
                    *(_WORD *)(v61 + 6),
                    17,
                    *(_WORD *)(v61 + 4),
                    *(_DWORD *)(v61 + 32),
                    *(_DWORD *)(v61 + 36),
                    v63,
                    v62,
                    name,
                    msg_str,
                    v60);
                v52 = inv_amt_3++ + 1;
            }
            while ( (signed __int16)inv_amt_3 < (signed __int16)tech_cnt );
        }
        if ( (_WORD)make_cnt || (_WORD)tech_cnt )
            goto LABEL_139;
        if ( player->sel_count > 1 )
        {
            TRIBE_Screen_Game::set_button(v1, v1->button_cmd_pic, 6, 7, 8, 0, 120033, -1, 0, 0, 0, 0, 0);
            v93 = 20035;
            v86 = 8;
            v79 = 7;
            v73 = v1->button_cmd_pic;
            goto LABEL_138;
        }
        goto LABEL_136;
    }
LABEL_183:
    TRIBE_Screen_Game::disable_unused_buttons(v1);
}
// 586320: using guessed type unsigned __int8 production_queues_is_use;

//----- (0049A8A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::disable_unused_buttons(TRIBE_Screen_Game *this)
{
    TButtonPanel **v1; // esi@1
    signed int v2; // edi@1
    TButtonPanel *v3; // ecx@2

    v1 = (TButtonPanel **)this->button_panel;
    v2 = 12;
    do
    {
        v3 = *v1;
        if ( *((_DWORD *)*v1 + 244) )
        {
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v3 + 20))(1);
        }
        else
        {
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 20))(0);
            TButtonPanel::set_id(*v1, 0, 0, -1);
            TPanel::set_help_info((TPanel *)*v1, -1, -1);
        }
        ++v1;
        --v2;
    }
    while ( v2 );
}

//----- (0049A8F0) --------------------------------------------------------
char *__stdcall TRIBE_Screen_Game::calc_text_msg(char *msg_str, Item_Avail *item, int button_action_id, int message_string_id)
{
    __int16 v5; // ax@2
    __int16 v6; // ax@6
    __int16 v7; // ax@10
    char *result; // eax@20
    char inven_str[512]; // [sp+20h] [bp-C00h]@4
    char cost_str2[512]; // [sp+220h] [bp-A00h]@8
    char cost_str1[512]; // [sp+420h] [bp-800h]@4
    char cost_str[512]; // [sp+620h] [bp-600h]@1
    char cost_str3[512]; // [sp+820h] [bp-400h]@12
    char command_str[512]; // [sp+A20h] [bp-200h]@1

    (*(void (__stdcall **)(int, char *, signed int))&rge_base_game->vfptr->gap8[24])(message_string_id, command_str, 512);
    cost_str[0] = 0;
    if ( item )
    {
        v5 = item->inventory_item_1;
        if ( v5 == -1 || v5 > 3 )
        {
            cost_str1[0] = 0;
        }
        else
        {
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                100,
                v5,
                0,
                inven_str,
                512);
            sprintf(cost_str1, aSD_0, inven_str, (unsigned int)(signed __int64)item->inventory_cost_1);
        }
        v6 = item->inventory_item_2;
        if ( v6 == -1 || v6 > 3 )
        {
            cost_str2[0] = 0;
        }
        else
        {
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                100,
                v6,
                0,
                inven_str,
                512);
            sprintf(cost_str2, aSD_3, inven_str, (unsigned int)(signed __int64)item->inventory_cost_2);
        }
        v7 = item->inventory_item_3;
        if ( v7 == -1 || v7 > 3 )
        {
            cost_str3[0] = 0;
        }
        else
        {
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                100,
                v7,
                0,
                inven_str,
                512);
            sprintf(cost_str3, aSD_3, inven_str, (unsigned int)(signed __int64)item->inventory_cost_3);
        }
        if ( cost_str1[0] || cost_str2[0] || cost_str3[0] )
            sprintf(cost_str, aSSS, cost_str1, cost_str2, cost_str3);
    }
    if ( !command_str[0] )
        goto LABEL_26;
    if ( cost_str[0] )
    {
        sprintf(msg_str, aSS_9, command_str, cost_str);
        return msg_str;
    }
    if ( command_str[0] )
    {
        sprintf(msg_str, aS_2, command_str);
        result = msg_str;
    }
    else
    {
LABEL_26:
        result = msg_str;
        *msg_str = 0;
    }
    return result;
}

//----- (0049AB10) --------------------------------------------------------
__int16 __stdcall TRIBE_Screen_Game::calc_button_loc(char button_loc)
{
    __int16 result; // ax@3

    if ( (unsigned __int8)button_loc < 1u || (unsigned __int8)button_loc > 5u )
    {
        if ( (unsigned __int8)button_loc < 6u || (unsigned __int8)button_loc > 0xAu )
        {
            if ( (unsigned __int8)button_loc < 0xBu || (unsigned __int8)button_loc > 0xFu )
            {
                if ( (unsigned __int8)button_loc < 0x10u || (unsigned __int8)button_loc > 0x14u )
                    result = 0;
                else
                    result = (unsigned __int8)button_loc - 10;
            }
            else
            {
                result = (unsigned __int8)button_loc - 11;
            }
        }
        else
        {
            result = (unsigned __int8)button_loc;
        }
    }
    else
    {
        result = (unsigned __int8)button_loc - 1;
    }
    return result;
}

//----- (0049AB60) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::set_button(TRIBE_Screen_Game *this, TShape *buttons, __int16 button, __int16 pic_index, int id, int id2, int help_string_id, int help_page_id, int hotkey, char *color_table, char *text2, char *text_msg, int make_disabled)
{
    TRIBE_Panel_Button *v13; // esi@1
    int v14; // ecx@1
    signed int v15; // eax@12
    int v16; // edx@32
    char text1[512]; // [sp+14h] [bp-200h]@5

    v13 = this->button_panel[button];
    v14 = *((_DWORD *)v13 + 172);
    *((_DWORD *)v13 + 244) = 1;
    if ( v14 != make_disabled )
        TButtonPanel::set_disabled((TButtonPanel *)v13, make_disabled);
    if ( TButtonPanel::get_id((TButtonPanel *)v13) != id || TButtonPanel::get_id2((TButtonPanel *)v13) != id2 )
    {
        TButtonPanel::reset((TButtonPanel *)v13);
        TRIBE_Panel_Button::set_display_garrison(v13, 0);
        (*(void (__stdcall **)(signed int, int, int, char *, signed int))&rge_base_game->vfptr->gap28[0])(
            102,
            id,
            id2,
            text1,
            512);
        TButtonPanel::set_picture((TButtonPanel *)v13, 0, buttons, pic_index);
        TButtonPanel::set_id((TButtonPanel *)v13, 0, id, id2);
        *((_DWORD *)v13 + 178) = color_table;
        TButtonPanel::set_text((TButtonPanel *)v13, 0, text1, text2);
        TPanel::set_help_info((TPanel *)v13, help_string_id, help_page_id);
        if ( text_msg )
            TRIBE_Panel_Button::set_text_msg(v13, text_msg);
        else
            TRIBE_Panel_Button::set_text_msg(v13, text1);
        if ( id == 17 )
            *((_DWORD *)v13 + 179) = 2;
        else
            *((_DWORD *)v13 + 179) = 0;
        switch ( id )
        {
            case 3:
                v15 = 4151;
                break;
            case 5:
                v15 = 4152;
                break;
            case 8:
                v15 = 4153;
                break;
            case 9:
                v15 = 4154;
                break;
            case 12:
                v15 = 4155;
                break;
            case 22:
                v15 = 4157;
                break;
            case 23:
                v15 = 4158;
                break;
            case 28:
                v15 = 4168;
                break;
            case 29:
                v15 = 4169;
                break;
            case 1:
                v15 = 4171;
                break;
            case 2:
                v15 = 4170;
                break;
            case 30:
                v15 = 4172;
                break;
            case 31:
                v15 = 4173;
                break;
            case 7:
                v15 = 4174;
                break;
            default:
                v15 = hotkey;
                break;
        }
        if ( v15 )
            v15 = *TPanel::get_string(v15);
        if ( id == 6 || id == 11 )
            v15 = 27;
        v16 = *(_DWORD *)v13;
        *((_DWORD *)v13 + 166) = v15;
        *((_DWORD *)v13 + 167) = 0;
        (*(void (__thiscall **)(TRIBE_Panel_Button *, signed int))(v16 + 20))(v13, 1);
    }
}

//----- (0049ADA0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::reset_clocks(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    TRIBE_World *v2; // eax@1
    int v3; // ecx@1
    int v4; // edi@4
    signed int v5; // ebp@4
    TRIBE_Panel_Time *v6; // ecx@7
    RGE_Player *v7; // eax@8
    int v8; // ebx@10
    TRIBE_Panel_Time *v9; // ecx@18
    RGE_Player *v10; // eax@19
    int v11; // ebx@21
    TRIBE_Panel_Time *v12; // ecx@29
    TRIBE_Panel_Time **v13; // esi@32
    int v14; // edi@32
    TRIBE_Panel_Time *v15; // ecx@33
    signed int v16; // [sp+10h] [bp-10h]@5
    TRIBE_Panel_Time **v17; // [sp+14h] [bp-Ch]@5
    int found; // [sp+18h] [bp-8h]@9
    int founda; // [sp+18h] [bp-8h]@20
    int countdown_timer; // [sp+1Ch] [bp-4h]@6

    v1 = this;
    v2 = this->world;
    v3 = v2->victory_type;
    if ( v3 == 2 )
    {
        TRIBE_Panel_Time::set_clock_type(v1->countdown_clock[0], 3, 0);
    }
    else if ( !v3 )
    {
        v4 = 1;
        v5 = 0;
        if ( v2->player_num > 1 )
        {
            v16 = 1;
            v17 = v1->countdown_clock;
            do
            {
                RGE_Base_Game::get_countdown_timer(rge_base_game, v4, &countdown_timer);
                if ( countdown_timer > 0 )
                {
                    ++v5;
                    v6 = *v17;
                    ++v17;
                    TRIBE_Panel_Time::set_clock_type(v6, 4, v4);
                    if ( v5 > 9 )
                        break;
                }
                v7 = v1->world->players[v16];
                if ( *(_DWORD *)&v7[3].groups_used[70] != -1082130432 )
                {
                    found = 0;
                    if ( v7->allied_victory )
                    {
                        v8 = 1;
                        if ( v16 > 1 )
                        {
                            while ( RGE_Player::relation(v1->world->players[v16], v8)
                                     || RGE_Player::relation(v1->world->players[v8], v4)
                                     || !v1->world->players[v8]->allied_victory )
                            {
                                if ( ++v8 >= v4 )
                                    goto LABEL_17;
                            }
                            found = 1;
                        }
                    }
LABEL_17:
                    if ( !found )
                    {
                        ++v5;
                        v9 = *v17;
                        ++v17;
                        TRIBE_Panel_Time::set_clock_type(v9, 5, v4);
                        if ( v5 > 9 )
                            break;
                    }
                }
                v10 = v1->world->players[v16];
                if ( *(_DWORD *)&v10[3].groups_used[66] != -1082130432 )
                {
                    founda = 0;
                    if ( v10->allied_victory )
                    {
                        v11 = 1;
                        if ( v16 > 1 )
                        {
                            while ( RGE_Player::relation(v1->world->players[v16], v11)
                                     || RGE_Player::relation(v1->world->players[v11], v4)
                                     || !v1->world->players[v11]->allied_victory )
                            {
                                if ( ++v11 >= v4 )
                                    goto LABEL_28;
                            }
                            founda = 1;
                        }
                    }
LABEL_28:
                    if ( !founda )
                    {
                        ++v5;
                        v12 = *v17;
                        ++v17;
                        TRIBE_Panel_Time::set_clock_type(v12, 6, v4);
                        if ( v5 > 9 )
                            break;
                    }
                }
                ++v4;
                ++v16;
            }
            while ( v4 < v1->world->player_num );
        }
        if ( v5 < 10 )
        {
            v13 = &v1->countdown_clock[v5];
            v14 = 10 - v5;
            do
            {
                v15 = *v13;
                ++v13;
                TRIBE_Panel_Time::set_clock_type(v15, 0, 0);
                --v14;
            }
            while ( v14 );
        }
    }
}

//----- (0049B000) --------------------------------------------------------
int __cdecl scr_game_score_compare(void *arg1, void *arg2)
{
    int v2; // edx@1
    int v3; // esi@1
    int result; // eax@2
    int v5; // edx@5
    int v6; // esi@5
    int v7; // edx@9
    int v8; // esi@9
    int v9; // eax@13
    int v10; // ecx@13

    s1 = (PLAYER_SCORE *)arg2;
    s2 = (PLAYER_SCORE *)arg1;
    v2 = *((_DWORD *)arg2 + 4);
    v3 = *((_DWORD *)arg1 + 4);
    if ( v2 <= v3 )
    {
        if ( v2 >= v3 )
        {
            v5 = *((_DWORD *)arg2 + 2);
            v6 = *((_DWORD *)arg1 + 2);
            if ( v5 <= v6 )
            {
                if ( v5 >= v6 )
                {
                    v7 = *((_DWORD *)arg2 + 3);
                    v8 = *((_DWORD *)arg1 + 3);
                    if ( v7 <= v8 )
                    {
                        if ( v7 >= v8 )
                        {
                            v9 = *((_DWORD *)arg2 + 1);
                            v10 = *((_DWORD *)arg1 + 1);
                            if ( v9 <= v10 )
                                result = (v9 >= v10) - 1;
                            else
                                result = 1;
                        }
                        else
                        {
                            result = -1;
                        }
                    }
                    else
                    {
                        result = 1;
                    }
                }
                else
                {
                    result = -1;
                }
            }
            else
            {
                result = 1;
            }
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        result = 1;
    }
    return result;
}

//----- (0049B080) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::reset_score_display(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // ebp@1
    char *v2; // eax@1
    signed int v3; // edx@1
    int v4; // esi@3
    signed int v5; // edi@4
    int v6; // ebx@5
    TRIBE_World *v7; // eax@6
    TShape *v8; // eax@9
    TRIBE_World *v9; // ecx@9
    int v10; // ebp@10
    int v11; // esi@13
    TRIBE_World *v12; // eax@14
    int v13; // esi@16
    TRIBE_World *v14; // eax@17
    size_t v15; // eax@26
    unsigned int v16; // ebx@27
    PLAYER_SCORE *v17; // edi@27
    signed int v18; // ebp@27
    unsigned int v19; // ecx@30
    unsigned int v20; // eax@31
    PLAYER_SCORE *v21; // ebx@39
    int v22; // ST28_4@43
    int v23; // ST24_4@43
    char *v24; // eax@43
    RGE_Player *v25; // ecx@43
    char *v26; // esi@44
    unsigned int v27; // edi@44
    signed int v28; // ebp@54
    PLAYERHUMANITY v29; // eax@56
    RGE_Font *v30; // eax@60
    RGE_Font *v31; // ebp@62
    TShape *v32; // ebx@62
    unsigned int v33; // eax@64
    TShape *v34; // edx@65
    bool v35; // sf@70
    unsigned __int8 v36; // of@70
    int player_count; // [sp+10h] [bp-2D4h]@9
    PLAYER_SCORE *player_counta; // [sp+10h] [bp-2D4h]@39
    TRIBE_Screen_Game *v39; // [sp+14h] [bp-2D0h]@1
    signed int v40; // [sp+18h] [bp-2CCh]@11
    TMessagePanel **v41; // [sp+18h] [bp-2CCh]@39
    int team; // [sp+1Ch] [bp-2C8h]@3
    int i; // [sp+20h] [bp-2C4h]@3
    int icon_num2; // [sp+24h] [bp-2C0h]@7
    TShape *icon2; // [sp+28h] [bp-2BCh]@9
    int low_fps_player; // [sp+2Ch] [bp-2B8h]@9
    PLAYER_SCORE player_score[9]; // [sp+30h] [bp-2B4h]@1
    char str[512]; // [sp+E4h] [bp-200h]@43

    v1 = this;
    v39 = this;
    v2 = (char *)&player_score[0].player_id;
    v3 = 9;
    do
    {
        *((_DWORD *)v2 - 1) = 0;
        *(_DWORD *)v2 = 0;
        *((_DWORD *)v2 + 1) = 0;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 3) = 0;
        v2 += 20;
        --v3;
    }
    while ( v3 );
    team = 0;
    v4 = 1;
    i = 1;
    if ( RGE_Base_Game::numberPlayers(rge_base_game) >= 1 )
    {
        v5 = 20;
        do
        {
            v6 = RGE_Base_Game::playerID(rge_base_game, v4);
            if ( v6 )
            {
                v7 = v1->world;
                if ( v6 < v7->player_num )
                {
                    if ( !*(int *)((char *)&icon_num2 + v5) )
                        *(int *)((char *)&icon_num2 + v5) = ++team;
                    *(int *)((char *)&team + v5) = v4;
                    *(int *)((char *)&i + v5) = v6;
                    v8 = (TShape *)RGE_Victory_Conditions::get_victory_points(v7->players[v6]->victory_conditions);
                    v9 = v1->world;
                    *(TShape **)((char *)&icon2 + v5) = v8;
                    *(int *)((char *)&low_fps_player + v5) = (int)v8;
                    player_count = 1;
                    if ( v9->players[v6]->allied_victory )
                    {
                        v10 = 1;
                        if ( RGE_Base_Game::numberPlayers(rge_base_game) >= 1 )
                        {
                            v40 = 20;
                            do
                            {
                                if ( v10 != v4 )
                                {
                                    v11 = RGE_Base_Game::playerID(rge_base_game, v10);
                                    if ( v11 )
                                    {
                                        v12 = v39->world;
                                        if ( v11 < v12->player_num && !RGE_Player::relation(v12->players[v6], v11) )
                                        {
                                            v13 = v11;
                                            if ( !RGE_Player::relation(v39->world->players[v13], v6) )
                                            {
                                                v14 = v39->world;
                                                if ( v14->players[v13]->allied_victory )
                                                {
                                                    if ( !*(int *)((char *)&icon_num2 + v40) )
                                                        *(int *)((char *)&icon_num2 + v40) = *(int *)((char *)&icon_num2 + v5);
                                                    *(int *)((char *)&low_fps_player + v5) += RGE_Victory_Conditions::get_victory_points(v14->players[v13]->victory_conditions);
                                                    ++player_count;
                                                }
                                            }
                                        }
                                    }
                                    v4 = i;
                                }
                                ++v10;
                                v40 += 20;
                            }
                            while ( v10 <= RGE_Base_Game::numberPlayers(rge_base_game) );
                        }
                        v1 = v39;
                    }
                    *(int *)((char *)&low_fps_player + v5) /= player_count;
                }
            }
            i = ++v4;
            v5 += 20;
        }
        while ( v4 <= RGE_Base_Game::numberPlayers(rge_base_game) );
    }
    v15 = RGE_Base_Game::numberPlayers(rge_base_game);
    qsort(player_score, v15, 0x14u, (int (__cdecl *)(const void *, const void *))scr_game_score_compare);
    low_fps_player = 0;
    if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
    {
        v16 = 11;
        v17 = player_score;
        v18 = 8;
        do
        {
            if ( v17->player_id && TCommunications_Handler::GetPlayerHumanity(comm, v17->comm_id) == 2 )
            {
                v19 = comm->Speed->PlayerAvgFramesMsec[v17->comm_id];
                if ( v19 <= 0x3E7 )
                    v20 = v19 >= 0xA ? 0x3E8 / v19 : 100;
                else
                    v20 = 1;
                if ( v20 < v16 )
                {
                    low_fps_player = v17->comm_id;
                    v16 = v20;
                }
            }
            ++v17;
            --v18;
        }
        while ( v18 );
        v1 = v39;
    }
    v21 = player_score;
    i = 0;
    player_counta = player_score;
    v41 = v1->score_panel;
    do
    {
        if ( !*v41 )
            break;
        if ( v21->player_id )
        {
            v22 = v21->team_score;
            v23 = v21->player_score;
            v24 = TCommunications_Handler::GetPlayerName(comm, v21->comm_id);
            sprintf(str, aSDD_1, v24, v23, v22);
            v25 = v1->world->players[v21->player_id];
            switch ( v25->color_table->id )
            {
                case 0:
                    v26 = (char *)16711680;
                    v27 = 11776947;
                    goto LABEL_54;
                case 1:
                    v26 = (char *)2177478;
                    break;
                case 2:
                    v26 = (char *)0xFFFF;
                    break;
                case 3:
                    v26 = (char *)&loc_4F73A3;
                    break;
                case 4:
                    v26 = (char *)1013747;
                    break;
                case 5:
                    v26 = (char *)50944;
                    break;
                case 6:
                    v26 = (char *)&pathSystem.MGP_openPaths[14537].total + 2;
                    break;
                case 7:
                    v26 = (char *)11382016;
                    break;
                default:
                    v26 = (char *)0xFFFFFF;
                    break;
            }
            v27 = 0;
LABEL_54:
            v28 = 0;
            if ( v25->game_status == 2
                || RGE_Base_Game::multiplayerGame(rge_base_game)
                && (v29 = TCommunications_Handler::GetPlayerHumanity(comm, v21->comm_id), v29 != 2)
                && v29 != 4 )
            {
                v28 = 1;
            }
            if ( v28 )
                v30 = RGE_Base_Game::get_font(rge_base_game, 8);
            else
                v30 = RGE_Base_Game::get_font(rge_base_game, 11);
            v31 = v30;
            v32 = 0;
            icon2 = 0;
            team = 0;
            icon_num2 = 0;
            if ( RGE_Base_Game::multiplayerGame(rge_base_game)
                && TCommunications_Handler::GetPlayerHumanity(comm, player_counta->comm_id) == 2 )
            {
                v33 = RGE_Communications_Speed::GetPlayerLatency(comm->Speed, player_counta->comm_id);
                if ( player_counta->comm_id == low_fps_player )
                {
                    v34 = v39->button_pics;
                    icon_num2 = 17;
                    icon2 = v34;
                }
                if ( v33 >= 0x12C )
                {
                    v32 = v39->button_pics;
                    team = 20;
                    if ( v33 <= 0x3E8 )
                        team = 19;
                }
            }
            TMessagePanel::show_message2(
                *v41,
                RightInfoMessage,
                str,
                (unsigned int)v26,
                v27,
                v31->font,
                v31->font_wid,
                v31->font_hgt,
                v32,
                team,
                icon2,
                icon_num2);
            v21 = player_counta;
            v1 = v39;
        }
        else
        {
            (*(void (__stdcall **)(_DWORD))&(*v41)->vfptr->gap10[4])(0);
        }
        ++v21;
        v36 = __OFSUB__(i + 1, 8);
        v35 = i++ - 7 < 0;
        ++v41;
        player_counta = v21;
    }
    while ( v35 ^ v36 );
}

//----- (0049B560) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::draw(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // ebx@2
    TPanelVtbl *v3; // ebp@2
    TRIBE_Panel_Inven *v4; // eax@4
    int v5; // edi@4
    signed int v6; // eax@9
    int v7; // eax@20
    TPanelVtbl *v8; // edi@22
    signed int v9; // eax@24
    TDrawArea *v10; // [sp-20h] [bp-38h]@11
    int v11; // [sp-18h] [bp-30h]@11
    TDrawArea *v12; // [sp-18h] [bp-30h]@26
    char v13; // [sp-10h] [bp-28h]@11
    int v14; // [sp-10h] [bp-28h]@26
    char v15; // [sp-8h] [bp-20h]@26
    int save_clip_rect; // [sp+8h] [bp-10h]@2
    int save_clip_rect_4; // [sp+Ch] [bp-Ch]@2
    int save_clip_rect_8; // [sp+10h] [bp-8h]@2
    int save_clip_rect_12; // [sp+14h] [bp-4h]@2

    v1 = this;
    if ( do_color_log )
    {
        v2 = (char *)&this->clip_rect;
        v3 = this->vfptr;
        save_clip_rect = this->clip_rect.left;
        save_clip_rect_4 = this->clip_rect.top;
        save_clip_rect_8 = this->clip_rect.right;
        save_clip_rect_12 = this->clip_rect.bottom;
        ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
        if ( v1->inven_panel && TDrawArea::Lock(v1->render_area, aScr_gameDraw, 1) )
        {
            v4 = v1->inven_panel;
            v5 = v4->render_rect.bottom;
            TDrawArea::FillRect(v1->render_area, v4->render_rect.left, v4->render_rect.top, v4->render_rect.right, v5, 116);
            TDrawArea::Unlock(v1->render_area, aScr_gameDraw);
            if ( v1->clip_rect.top < v5 )
                v1->clip_rect.top = v5;
            TDrawArea::SetClipRect(v1->render_area, &v1->clip_rect);
        }
        if ( v1->game_screen_pic && TDrawArea::Lock(v1->render_area, aScr_gameDraw2, 1) )
        {
            v6 = v1->pnl_wid;
            if ( v6 < 1024 || v1->pnl_hgt < 768 )
            {
                if ( v6 < 800 || v1->pnl_hgt < 600 )
                {
                    TShape::shape_draw(v1->game_screen_pic, v1->render_area, 0, 0, 0, 0, 0);
                    v13 = 0;
                    v11 = 354;
                    v10 = v1->render_area;
                }
                else
                {
                    TShape::shape_draw(v1->game_screen_pic, v1->render_area, 0, 0, 0, 0, 0);
                    v13 = 0;
                    v11 = 474;
                    v10 = v1->render_area;
                }
            }
            else
            {
                TShape::shape_draw(v1->game_screen_pic, v1->render_area, 0, 0, 0, 0, 0);
                v13 = 0;
                v11 = 642;
                v10 = v1->render_area;
            }
            TShape::shape_draw(v1->game_screen_pic, v10, 0, v11, 1, v13, 0);
            TDrawArea::Unlock(v1->render_area, aScr_gameDraw2);
        }
        v3->draw_finish((TPanel *)v1);
        *(_DWORD *)v2 = save_clip_rect;
        v1->clip_rect.top = save_clip_rect_4;
        v1->clip_rect.right = save_clip_rect_8;
        v1->clip_rect.bottom = save_clip_rect_12;
        TDrawArea::SetClipRect(v1->render_area, &v1->clip_rect);
    }
    else
    {
        v7 = this->need_redraw == 2 || !this->game_screen_pic;
        v8 = this->vfptr;
        ((void (__stdcall *)(int))this->vfptr->draw_setup)(v7);
        if ( v1->game_screen_pic && TDrawArea::Lock(v1->render_area, aScr_gameDraw3, 1) )
        {
            v9 = v1->pnl_wid;
            if ( v9 < 1024 || v1->pnl_hgt < 768 )
            {
                if ( v9 < 800 || v1->pnl_hgt < 600 )
                {
                    TShape::shape_draw(v1->game_screen_pic, v1->render_area, 0, 0, 0, 0, 0);
                    v15 = 0;
                    v14 = 354;
                    v12 = v1->render_area;
                }
                else
                {
                    TShape::shape_draw(v1->game_screen_pic, v1->render_area, 0, 0, 0, 0, 0);
                    v15 = 0;
                    v14 = 474;
                    v12 = v1->render_area;
                }
            }
            else
            {
                TShape::shape_draw(v1->game_screen_pic, v1->render_area, 0, 0, 0, 0, 0);
                v15 = 0;
                v14 = 642;
                v12 = v1->render_area;
            }
            TShape::shape_draw(v1->game_screen_pic, v12, 0, v14, 1, v15, 0);
            TDrawArea::Unlock(v1->render_area, aScr_gameDraw3);
        }
        v8->draw_finish((TPanel *)v1);
    }
}
// 62C584: using guessed type unsigned __int8 do_color_log;

//----- (0049B830) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handle_anim_pal(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // ebp@1
    int v2; // esi@2
    char *v3; // eax@2
    int v4; // edi@3
    int v5; // ecx@3
    __int16 v6; // ax@6
    signed int v7; // [sp+4h] [bp-24h]@2
    unsigned int time; // [sp+8h] [bp-20h]@1
    tagPALETTEENTRY pal_entries[7]; // [sp+Ch] [bp-1Ch]@2

    v1 = this;
    time = debug_timeGetTime();
    if ( time - v1->last_anim_pal_time >= v1->anim_pal_interval )
    {
        v2 = *(_DWORD *)&v1->last_anim_pal_index;
        v3 = &pal_entries[0].peGreen;
        v7 = 7;
        do
        {
            v4 = (int)v1 + 2 * (signed __int16)v2 + (signed __int16)v2;
            v5 = (signed __int16)v2++ + 565;
            *(v3 - 1) = *(_BYTE *)(v4 + 1694);
            *v3 = *((_BYTE *)&v1->vfptr + 2 * v5 + v5);
            v3[1] = *(_BYTE *)(v4 + 1696);
            v3[2] = 0;
            if ( (_WORD)v2 == 7 )
                v2 = 0;
            v3 += 4;
            --v7;
        }
        while ( v7 );
        v6 = v1->last_anim_pal_index;
        if ( v6 )
            v1->last_anim_pal_index = v6 - 1;
        else
            v1->last_anim_pal_index = 6;
        TDrawSystem::ModifyPalette(v1->render_area->DrawSystem, 248, 7, pal_entries);
        v1->last_anim_pal_time = time;
    }
}

//----- (0049B910) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handle_terrain_sound(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // edi@1
    signed __int16 v2; // si@1
    unsigned int v3; // eax@4
    TRIBE_World *v4; // edx@11
    signed __int16 v5; // bx@11
    signed __int16 v6; // ax@11
    RGE_Map *v7; // edx@11
    signed __int16 v8; // bp@11
    char *v9; // ecx@12
    char *v10; // esi@19

    v1 = this;
    color_log(84, 22, 4);
    v2 = 0;
    if ( rge_base_game->prog_info->use_sound
        && rge_base_game->sound_system
        && !*(_DWORD *)&__S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[4] )
    {
        v3 = debug_timeGetTime();
        if ( v1->terrain_playing )
        {
            if ( v3 - v1->last_terrain_sound_time < 0x3E8 )
                return;
            v1->last_terrain_sound_time = v3;
            if ( !bPlaying )
                goto LABEL_9;
            if ( v3 - v1->terrain_sound_start_time >= 0x1770 )
            {
                TSound_Driver::stop_stream(rge_base_game->sound_system);
LABEL_9:
                v1->terrain_playing = 0;
                color_log(84, 95, 4);
                return;
            }
        }
        else
        {
            if ( v3 - v1->last_terrain_sound_time < v1->terrain_sound_interval )
                return;
            v4 = v1->world;
            v1->last_terrain_sound_time = v3;
            v5 = -1;
            v6 = 0;
            v7 = v4->map;
            v8 = v7->num_terrain;
            if ( v8 > 0 )
            {
                v9 = &v7->terrain_types[0].drawn;
                do
                {
                    if ( *(v9 - 69) && (unsigned __int8)*v9 > v2 && *(_DWORD *)(v9 - 33) )
                    {
                        v5 = v6;
                        v2 = (unsigned __int8)*v9;
                    }
                    ++v6;
                    v9 += 408;
                }
                while ( v6 < v8 );
            }
            if ( v5 != -1 )
            {
                v10 = RGE_Sound::get_file_name(v7->terrain_types[v5].sound);
                if ( v10 )
                {
                    color_log(84, 76, 4);
                    debug_timeGetTime();
                    TSound_Driver::stop_stream(rge_base_game->sound_system);
                    TSound_Driver::stream_file(rge_base_game->sound_system, v10, 0, 0);
                    color_log(84, 50, 4);
                    v1->terrain_playing = 1;
                    v1->terrain_sound_start_time = debug_timeGetTime();
                }
            }
        }
    }
    color_log(84, 95, 4);
}
// 86BAB4: using guessed type int bPlaying;

//----- (0049BAF0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::handle_mouse_pointing_at(TRIBE_Screen_Game *this)
{
    void *v1; // esi@1
    TRIBE_Screen_Game *v2; // edi@1
    int v3; // ecx@4
    int v4; // eax@4
    TRIBE_Main_View *v5; // edx@6
    signed __int16 v6; // bp@13
    signed __int16 v7; // bx@13
    TRIBE_Panel_Button *v8; // ecx@14
    __int16 row; // [sp+10h] [bp-10h]@12
    __int16 col; // [sp+12h] [bp-Eh]@12
    RGE_Tile *tile; // [sp+14h] [bp-Ch]@12
    tagPOINT point; // [sp+18h] [bp-8h]@4

    v1 = rge_base_game->prog_window;
    v2 = this;
    if ( GetForegroundWindow() == v1 )
    {
        if ( TPanel::get_focus((TPanel *)&v2->main_view->vfptr) )
        {
            if ( !TPanelSystem::modalPanel(&panel_system) )
            {
                RGE_Base_Game::get_mouse_pos(rge_base_game, &point);
                v3 = point.x;
                v4 = point.y;
                if ( point.x != v2->mouse_last_x || point.y != v2->mouse_last_y )
                {
                    v5 = v2->main_view;
                    v2->mouse_last_x = point.x;
                    v2->mouse_last_y = v4;
                    if ( !v5->UC_ObjectTouched )
                    {
                        TMessagePanel::remove_message(v2->text_line_panel);
                        v4 = point.y;
                        v3 = point.x;
                    }
                    if ( v3 >= 0
                        && v3 < v2->pnl_wid
                        && v4 >= 0
                        && v4 <= v2->pnl_hgt
                        && !RGE_Diamond_Map::pick_tile((RGE_Diamond_Map *)&v2->map_view->vfptr, v3, v4, &col, &row, &tile) )
                    {
                        v6 = -1;
                        v7 = 0;
                        while ( 1 )
                        {
                            v8 = v2->button_panel[v7];
                            if ( *((_DWORD *)v8 + 27) )
                            {
                                if ( TButtonPanel::get_id((TButtonPanel *)v8) != -1
                                    && (*(int (__stdcall **)(int, int))(*(_DWORD *)v2->button_panel[v7] + 228))(point.x, point.y) )
                                {
                                    break;
                                }
                            }
                            if ( ++v7 >= 17 )
                                goto LABEL_20;
                        }
                        v6 = v7;
LABEL_20:
                        if ( v6 != -1 )
                            TMessagePanel::show_message(v2->text_line_panel, 0, (char *)v2->button_panel[v6] + 720, -1, 0, 0, 0, 0);
                    }
                }
            }
        }
    }
}

//----- (0049BC60) --------------------------------------------------------
void __stdcall TRIBE_Screen_Game::command_add_attribute(int attr_id)
{
    RGE_Game_World *v2; // eax@3

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
        {
            v2 = RGE_Base_Game::get_player(rge_base_game);
            ((void (__thiscall *)(RGE_Game_World *, int, signed int))v2->vfptr->turn_sound_off)(v2, attr_id, 1148846080);
        }
    }
}

//----- (0049BCA0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_ai_info(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    TMessagePanel::remove_message(this->message_panel);
    TMessagePanel::remove_message(v1->message_panel2);
    TMessagePanel::remove_message(v1->message_panel3);
    TMessagePanel::remove_message(v1->message_panel4);
    TMessagePanel::remove_message(v1->message_panel5);
    TMessagePanel::remove_message(v1->message_panel6);
    if ( rge_base_game->do_show_ai )
    {
        rge_base_game->do_show_ai = 0;
    }
    else
    {
        rge_base_game->do_show_timings = 0;
        rge_base_game->do_show_comm = 0;
        rge_base_game->do_show_ai = 1;
    }
}

//----- (0049BD20) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_attack(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = TPanel::get_string(3042);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(103, 0);
    }
}

//----- (0049BD70) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_build(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        (*(void (__stdcall **)(signed int, signed int))&rge_base_game->vfptr->gap8[8])(6, 1);
        v1->start_item = 0;
        TRIBE_Screen_Game::setup_buttons(v1);
    }
}

//----- (0049BDB0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_building(TRIBE_Screen_Game *this, int id)
{
    TRIBE_Screen_Game *v2; // edi@1
    RGE_Game_World *v3; // eax@2
    __int16 attr; // [sp+12h] [bp-202h]@2
    char msg[512]; // [sp+14h] [bp-200h]@6

    v2 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v3 = RGE_Base_Game::get_player(rge_base_game);
        if ( TRIBE_Player::check_obj_cost((TRIBE_Player *)v3, id, &attr, 1.0, 0) )
        {
            rge_base_game->master_obj_id = id;
            if ( *(_BYTE *)(*(_DWORD *)(RGE_Base_Game::get_player(rge_base_game)->sprite_update_index + 4 * id) + 364) )
                (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(21, 0);
            else
                (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(7, 0);
        }
        else
        {
            (*(void (__stdcall **)(signed int, signed int, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                103,
                1,
                attr,
                msg,
                512);
            TMessagePanel::show_message(v2->message_panel, BadMessage, msg, 86, 0, 0, 0, 0);
        }
    }
}

//----- (0049BEA0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_cancel(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    RGE_Base_Game *v2; // ecx@4
    int v3; // eax@4

    v1 = this;
    if ( this->help_mode )
    {
        TEasy_Panel::clear_popup_help((TEasy_Panel *)&this->vfptr);
    }
    else if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = rge_base_game;
        v3 = rge_base_game->game_mode;
        if ( v3 )
        {
            if ( v3 == 21 )
            {
                (*(void (**)(void))&v1->main_view->vfptr[1].gap10[0])();
                RGE_View::set_selection_area((RGE_View *)&v1->main_view->vfptr, -1, -1, -1, -1);
                v2 = rge_base_game;
            }
            (*(void (__stdcall **)(_DWORD, _DWORD))&v2->vfptr->gap8[8])(0, 0);
        }
        else
        {
            TRIBE_Screen_Game::command_unselect(v1);
        }
    }
}

//----- (0049BF20) --------------------------------------------------------
void TRIBE_Screen_Game::command_cancel_building()
{
    RGE_Game_World *v1; // eax@2

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v1 = RGE_Base_Game::get_player(rge_base_game);
        TRIBE_Player::command_building_cancel((TRIBE_Player *)v1);
    }
}

//----- (0049BF50) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_chat(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@5
    TribeSendMessageDialog *v3; // eax@6

    v1 = this;
    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
    {
        TRIBE_Screen_Game::command_quick_chat(v1);
    }
    else if ( v1->game_ended || rge_base_game->prog_mode != 5 )
    {
        v3 = (TribeSendMessageDialog *)operator new(0x54Cu);
        if ( v3 )
            TribeSendMessageDialog::TribeSendMessageDialog(v3, (TScreenPanel *)&v1->vfptr);
    }
    else
    {
        v2 = TPanel::get_string(3070);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
    }
}

//----- (0049C010) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_quick_chat(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@3
    TribeSendQuickMessageDialog *v3; // eax@4

    v1 = this;
    if ( this->game_ended || rge_base_game->prog_mode != 5 )
    {
        v3 = (TribeSendQuickMessageDialog *)operator new(0x49Cu);
        if ( v3 )
            TribeSendQuickMessageDialog::TribeSendQuickMessageDialog(v3, (TScreenPanel *)&v1->vfptr, 0);
    }
    else
    {
        v2 = TPanel::get_string(3070);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
    }
}

//----- (0049C0B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_comm_info(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    rge_base_game->do_show_timings = 0;
    (*(void (__stdcall **)(_DWORD))&this->fps_panel->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(signed int))&v1->inven_panel->vfptr->gap10[4])(1);
    TMessagePanel::remove_message(v1->message_panel);
    TMessagePanel::remove_message(v1->message_panel2);
    TMessagePanel::remove_message(v1->message_panel3);
    TMessagePanel::remove_message(v1->message_panel4);
    TMessagePanel::remove_message(v1->message_panel5);
    TMessagePanel::remove_message(v1->message_panel6);
    if ( rge_base_game->do_show_comm )
    {
        rge_base_game->do_show_comm = 0;
    }
    else
    {
        rge_base_game->do_show_timings = 0;
        rge_base_game->do_show_ai = 0;
        rge_base_game->do_show_comm = 1;
    }
}

//----- (0049C160) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_convert(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = TPanel::get_string(3044);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(101, 0);
    }
}

//----- (0049C1B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_diplomacy(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    TribeDiplomacyDialog *v2; // eax@4

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 )
            RGE_Base_Game::set_paused(rge_base_game, 1, 1);
        v2 = (TribeDiplomacyDialog *)operator new(0x6B8u);
        if ( v2 )
            TribeDiplomacyDialog::TribeDiplomacyDialog(v2, (TScreenPanel *)&v1->vfptr);
    }
}

//----- (0049C230) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_fog_of_war(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
    {
        RGE_Base_Game::set_map_fog(rge_base_game, v1->world->map->fog_flag == 0);
        ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(2);
    }
}

//----- (0049C280) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_fps(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    if ( rge_base_game->do_show_timings )
    {
        if ( show_timing_max )
        {
            rge_base_game->do_show_timings = 0;
            (*(void (__stdcall **)(_DWORD))&this->fps_panel->vfptr->gap10[4])(0);
            (*(void (__stdcall **)(signed int))&v1->inven_panel->vfptr->gap10[4])(1);
        }
        else
        {
            show_timing_max = 1;
        }
    }
    else
    {
        show_timing_max = 0;
        rge_base_game->do_show_timings = 1;
        (*(void (__stdcall **)(signed int))&this->fps_panel->vfptr->gap10[4])(1);
        (*(void (__stdcall **)(_DWORD))&v1->inven_panel->vfptr->gap10[4])(0);
    }
}
// 86BDF4: using guessed type int show_timing_max;

//----- (0049C300) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_game_speed(TRIBE_Screen_Game *this, int increase_speed)
{
    TRIBE_Screen_Game *v2; // esi@1
    unsigned int v3; // edi@1
    double v4; // st7@4
    char *v5; // eax@29
    float new_speed; // [sp+8h] [bp-108h]@4
    float cur_speed; // [sp+Ch] [bp-104h]@4
    char msg[256]; // [sp+10h] [bp-100h]@29

    v2 = this;
    v3 = debug_timeGetTime();
    if ( v3 - v2->last_game_speed_change >= 0x3E8 || RGE_Base_Game::singlePlayerGame(rge_base_game) )
    {
        v2->last_game_speed_change = v3;
        if ( rge_base_game->prog_mode != 5 )
        {
            new_speed = 0.0;
            cur_speed = v2->world->game_speed;
            v4 = cur_speed;
            if ( increase_speed )
            {
                if ( v4 == 1.0 )
                {
                    new_speed = 1.5;
                }
                else if ( cur_speed == 1.5 )
                {
                    new_speed = 2.0;
                }
                else if ( RGE_Base_Game::singlePlayerGame(rge_base_game) && RGE_Base_Game::gameDeveloperMode(rge_base_game) )
                {
                    if ( cur_speed == 2.0 )
                    {
                        new_speed = 4.0;
                    }
                    else if ( cur_speed == 4.0 )
                    {
                        new_speed = 8.0;
                    }
                    else if ( cur_speed == 8.0 )
                    {
                        new_speed = 16.0;
                    }
                }
            }
            else if ( v4 == 16.0 )
            {
                new_speed = 8.0;
            }
            else if ( cur_speed == 8.0 )
            {
                new_speed = 4.0;
            }
            else if ( cur_speed == 4.0 )
            {
                new_speed = 2.0;
            }
            else if ( cur_speed == 2.0 )
            {
                new_speed = 1.5;
            }
            else if ( cur_speed == 1.5 )
            {
                new_speed = 1.0;
            }
            if ( new_speed != 0.0 )
            {
                if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                {
                    v5 = TPanel::get_string(3059);
                    sprintf(msg, v5);
                    TCommunications_Handler::SendChatMsgAll(comm, msg);
                }
                TRIBE_Command::command_game_speed((TRIBE_Command *)v2->world->commands, new_speed);
                if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
                    RGE_Base_Game::set_game_speed(rge_base_game, new_speed);
            }
        }
    }
}

//----- (0049C540) --------------------------------------------------------
void TRIBE_Screen_Game::command_group()
{
    RGE_Player *v1; // eax@2

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v1 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::group_objects(v1, -1);
    }
}

//----- (0049C570) --------------------------------------------------------
void __stdcall TRIBE_Screen_Game::command_group_by_number(int id)
{
    int v2; // eax@2
    int v3; // ST00_4@4
    RGE_Player *v4; // eax@4

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = id;
        if ( !id )
            v2 = 10;
        v3 = v2;
        v4 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::group_objects(v4, v3);
    }
}

//----- (0049C5B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_heal(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = TPanel::get_string(3043);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(102, 0);
    }
}

//----- (0049C600) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_repair(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = TPanel::get_string(3052);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(104, 0);
    }
}

//----- (0049C650) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_score(TRIBE_Screen_Game *this, int show)
{
    TRIBE_Screen_Game *v2; // edi@1
    signed int v3; // ebp@1
    char *v4; // esi@1
    TMessagePanel *v5; // ecx@7

    v2 = this;
    v3 = 8;
    v4 = (char *)this->score_panel;
    this->world->score_displayed = show;
    do
    {
        if ( *(_DWORD *)v4 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v4 + 20))(show);
        v4 += 4;
        --v3;
    }
    while ( v3 );
    if ( show )
        TRIBE_Screen_Game::reset_score_display(v2);
    v5 = v2->text_line_panel;
    if ( v2->world->score_displayed )
    {
        (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v5->vfptr->gap10[8])(
            8,
            4,
            0,
            184,
            4,
            0,
            0,
            34,
            34,
            0,
            0,
            0,
            0);
        ((void (__stdcall *)(signed int))v2->main_view->vfptr->set_redraw)(1);
    }
    else
    {
        (*(void (__stdcall **)(signed int, signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))&v5->vfptr->gap10[8])(
            8,
            4,
            0,
            4,
            4,
            0,
            0,
            34,
            34,
            0,
            0,
            0,
            0);
        ((void (__stdcall *)(_DWORD))v2->main_view->vfptr->set_redraw)(1);
    }
}

//----- (0049C710) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_select_group(TRIBE_Screen_Game *this, int id, int unsel_prior)
{
    TRIBE_Screen_Game *v3; // esi@1
    RGE_Player *v4; // eax@3
    int v5; // eax@4
    int v6; // ST00_4@6
    RGE_Player *v7; // eax@6

    v3 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        if ( unsel_prior )
        {
            v4 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::unselect_object(v4);
        }
        v5 = id;
        if ( !id )
            v5 = 10;
        v6 = v5;
        v7 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::select_group(v7, v6);
        ((void (__stdcall *)(signed int))v3->main_view->vfptr->set_redraw)(1);
    }
}

//----- (0049C770) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_menu(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    TribeMenuDialog *v2; // eax@5

    v1 = this;
    if ( rge_base_game->prog_mode == 6 )
        RGE_Command::do_commands(this->world->commands);
    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 )
        RGE_Base_Game::set_paused(rge_base_game, 1, 1);
    v2 = (TribeMenuDialog *)operator new(0x4BCu);
    if ( v2 )
        TribeMenuDialog::TribeMenuDialog(v2, (TScreenPanel *)&v1->vfptr);
}

//----- (0049C800) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_more(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    int v2; // eax@4

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        if ( rge_base_game->game_mode != 6 || rge_base_game->sub_game_mode != 1 )
        {
            if ( v1->last_item >= v1->item_cnt - 1 )
            {
                v1->start_item = 0;
                TRIBE_Screen_Game::setup_buttons(v1);
            }
            else
            {
                v1->start_item = v1->last_item + 1;
                TRIBE_Screen_Game::setup_buttons(v1);
            }
        }
        else
        {
            v2 = -(v1->start_item != 0);
            LOBYTE(v2) = v2 & 0xF6;
            v1->start_item = v2 + 10;
            TRIBE_Screen_Game::setup_buttons(v1);
        }
    }
}

//----- (0049C890) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_move(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    RGE_Player *v2; // eax@2
    char *v3; // eax@3
    __int16 list_num; // [sp+6h] [bp-6h]@2
    RGE_Static_Object **list; // [sp+8h] [bp-4h]@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        if ( RGE_Player::get_selected_objects_to_command(v2, &list, &list_num, -1, -1, -1, -1) )
        {
            free(list);
            v3 = TPanel::get_string(3040);
            TMessagePanel::show_message(v1->message_panel, BadMessage, v3, 50, 0, 0, 0, 0);
            (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(4, 0);
        }
    }
}

//----- (0049C920) --------------------------------------------------------
void TRIBE_Screen_Game::command_outline()
{
    char v1; // cl@1

    v1 = rge_base_game->outline_type;
    switch ( rge_base_game->outline_type )
    {
        case 0:
        case 3:
            rge_base_game->outline_type = 2;
            break;
        case 2:
            rge_base_game->outline_type = 1;
            break;
        case 1:
            v1 = 0;
            goto LABEL_5;
        default:
LABEL_5:
            rge_base_game->outline_type = v1;
            break;
    }
}

//----- (0049C970) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_pause(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    unsigned int v2; // edi@1
    char *v3; // eax@5
    char msg[256]; // [sp+8h] [bp-100h]@5

    v1 = this;
    v2 = debug_timeGetTime();
    if ( v2 - v1->last_pause_change >= 0x3E8 || RGE_Base_Game::singlePlayerGame(rge_base_game) )
    {
        v1->last_pause_change = v2;
        if ( rge_base_game->prog_mode != 5 )
        {
            if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
            {
                v3 = TPanel::get_string(3060);
                sprintf(msg, v3);
                TCommunications_Handler::SendChatMsgAll(comm, msg);
            }
            RGE_Base_Game::request_pause(rge_base_game);
        }
    }
}

//----- (0049CA10) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_player(TRIBE_Screen_Game *this, int id)
{
    TRIBE_Screen_Game *v2; // esi@1
    RGE_Player *v3; // eax@2
    RGE_Base_Game *v4; // ecx@2

    v2 = this;
    if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
    {
        v3 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(v3);
        ((void (__stdcall *)(signed int))v2->main_view->vfptr->set_redraw)(1);
        v4 = rge_base_game;
        if ( rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1 )
        {
            (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
            v4 = rge_base_game;
        }
        (*(void (__stdcall **)(int))&v4->vfptr->gap8[12])(id);
    }
}

//----- (0049CA80) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_quick_build(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
        TRIBE_Command::command_quick_build((TRIBE_Command *)v1->world->commands, rge_base_game->quick_build == 0);
}

//----- (0049CAC0) --------------------------------------------------------
void TRIBE_Screen_Game::command_quit()
{
    TCommunications_Handler::SendIResignMsg(comm);
    TCommunications_Handler::GameOver(comm);
    TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
}

//----- (0049CAF0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_research(TRIBE_Screen_Game *this, int id)
{
    TRIBE_Screen_Game *v2; // esi@1
    RGE_Game_World *v3; // eax@2
    RGE_Game_World *v4; // eax@3
    __int16 attr; // [sp+12h] [bp-202h]@2
    char msg[512]; // [sp+14h] [bp-200h]@4

    v2 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v3 = RGE_Base_Game::get_player(rge_base_game);
        if ( TRIBE_Player::check_tech_cost((TRIBE_Player *)v3, id, &attr) )
        {
            v4 = RGE_Base_Game::get_player(rge_base_game);
            TRIBE_Player::command_building_make_tech((TRIBE_Player *)v4, id);
        }
        else
        {
            (*(void (__stdcall **)(signed int, signed int, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                103,
                1,
                attr,
                msg,
                512);
            TMessagePanel::show_message(v2->message_panel, BadMessage, msg, 86, 0, 0, 0, 0);
        }
    }
}

//----- (0049CB90) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_save_game(TRIBE_Screen_Game *this)
{
    TribeSaveGameScreen *v1; // eax@3

    if ( rge_base_game->prog_mode == 6 )
        RGE_Command::do_commands(this->world->commands);
    v1 = (TribeSaveGameScreen *)operator new(0x6A4u);
    if ( v1 )
        TribeSaveGameScreen::TribeSaveGameScreen(v1, 0, 0, 0);
    TPanelSystem::setCurrentPanel(&panel_system, aSaveGameScreen, 0);
}

//----- (0049CC20) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_save_scenario(TRIBE_Screen_Game *this)
{
    TribeSaveGameScreen *v1; // eax@3

    if ( rge_base_game->prog_mode == 6 )
        RGE_Command::do_commands(this->world->commands);
    v1 = (TribeSaveGameScreen *)operator new(0x6A4u);
    if ( v1 )
        TribeSaveGameScreen::TribeSaveGameScreen(v1, SaveScenario, 0, 0);
    TPanelSystem::setCurrentPanel(&panel_system, aSaveGameScreen, 0);
}

//----- (0049CCB0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_select_building(TRIBE_Screen_Game *this, int id)
{
    TRIBE_Screen_Game *v2; // edi@1
    signed int v3; // esi@3
    RGE_Game_World *v4; // eax@15
    RGE_Static_Object *v5; // esi@15
    RGE_Player *v6; // eax@16
    RGE_Player *v7; // eax@16
    float v8; // ST04_4@16
    float v9; // ST00_4@16
    RGE_Player *v10; // eax@16
    __int16 v11; // ST04_2@16
    int v12; // ST00_4@16
    RGE_Player *v13; // eax@16
    RGE_Static_Object *v14; // [sp-4h] [bp-Ch]@13

    v2 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        switch ( id )
        {
            case 0:
                v3 = 109;
                goto LABEL_11;
            case 1:
                v3 = 12;
                goto LABEL_11;
            case 2:
                v3 = 45;
                goto LABEL_11;
            case 3:
                v3 = 87;
                goto LABEL_11;
            case 4:
                v3 = 49;
                goto LABEL_11;
            case 5:
                v3 = 101;
                goto LABEL_11;
            case 6:
                v3 = 104;
                goto LABEL_11;
            case 7:
                v3 = 0;
LABEL_11:
                if ( *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num
                    && *(_WORD *)(*(_DWORD *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num + 8) + 16) == v3 )
                {
                    v14 = *(RGE_Static_Object **)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num;
                }
                else
                {
                    v14 = 0;
                }
                v4 = RGE_Base_Game::get_player(rge_base_game);
                v5 = TRIBE_Player::find_obj((TRIBE_Player *)v4, v3, v14);
                if ( v5 )
                {
                    v6 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                    RGE_Player::unselect_object(v6);
                    v7 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                    RGE_Player::select_object(v7, v5);
                    v8 = v5->world_y;
                    v9 = v5->world_x;
                    v10 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                    RGE_Player::set_view_loc(v10, v9, v8);
                    v11 = (signed __int64)v5->world_y;
                    v12 = (signed __int64)v5->world_x;
                    v13 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                    RGE_Player::set_map_loc(v13, v12, v11);
                    ((void (__stdcall *)(signed int))v2->main_view->vfptr->set_redraw)(1);
                }
                break;
            default:
                return;
        }
    }
}

//----- (0049CE10) --------------------------------------------------------
void TRIBE_Screen_Game::command_stop()
{
    RGE_Game_World *v1; // eax@2

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v1 = RGE_Base_Game::get_player(rge_base_game);
        ((void (__thiscall *)(RGE_Game_World *))v1->vfptr->data_load)(v1);
    }
}

//----- (0049CE40) --------------------------------------------------------
void __usercall TRIBE_Screen_Game::command_tool_box(TRIBE_Screen_Game *this@<ecx>, int a2@<edi>)
{
    TRIBE_Screen_Game *v2; // esi@1
    RGE_Panel_Tool_Box *v3; // ecx@2
    TPanelVtbl *v4; // edi@5
    int v5; // ST08_4@5

    v2 = this;
    if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
    {
        v3 = v2->tool_box;
        if ( v3->active )
            (*(void (__stdcall **)(_DWORD, int))&v3->vfptr->gap10[4])(0, a2);
        else
            (*(void (__stdcall **)(signed int, int))&v3->vfptr->gap10[4])(1, a2);
        v4 = v2->vfptr;
        v5 = v2->pnl_hgt;
        ((void (__thiscall *)(TRIBE_Screen_Game *, int))v2->vfptr->handle_size)(v2, v2->pnl_wid);
        (*(void (__stdcall **)(_DWORD, _DWORD))&rge_base_game->vfptr->gap8[8])(0, 0);
        v4->set_redraw((TPanel *)v2, RedrawNormal);
    }
}
// 49CE40: could not find valid save-restore pair for edi

//----- (0049CEC0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_train(TRIBE_Screen_Game *this, int id, __int16 train_count)
{
    TRIBE_Screen_Game *v3; // edi@1
    RGE_Game_World *v4; // eax@4
    RGE_Game_World *v5; // eax@5
    __int16 attr; // [sp+12h] [bp-202h]@4
    char msg[512]; // [sp+14h] [bp-200h]@6

    v3 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        if ( production_queues_is_use )
        {
            TRIBE_Command::command_queue((TRIBE_Command *)v3->world->commands, v3->game_obj, id, train_count);
        }
        else
        {
            v4 = RGE_Base_Game::get_player(rge_base_game);
            if ( TRIBE_Player::check_obj_cost((TRIBE_Player *)v4, id, &attr, 1.0, 0) )
            {
                rge_base_game->master_obj_id = id;
                v5 = RGE_Base_Game::get_player(rge_base_game);
                TRIBE_Player::command_building_make_obj((TRIBE_Player *)v5, id);
            }
            else
            {
                (*(void (__stdcall **)(signed int, signed int, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                    103,
                    1,
                    attr,
                    msg,
                    512);
                TMessagePanel::show_message(v3->message_panel, BadMessage, msg, 86, 0, 0, 0, 0);
            }
        }
    }
}
// 586320: using guessed type unsigned __int8 production_queues_is_use;

//----- (0049CFB0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_ungroup(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    RGE_Player *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::ungroup_objects(v2);
        ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(1);
    }
}

//----- (0049CFF0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_unload(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = TPanel::get_string(3053);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(105, 0);
    }
}

//----- (0049D040) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_unselect(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    RGE_Player *v2; // eax@2
    RGE_Player *v3; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_object(v2);
        v3 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        RGE_Player::unselect_area(v3);
        ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(1);
    }
}

//----- (0049D090) --------------------------------------------------------
void TRIBE_Screen_Game::command_view_selected()
{
    int v1; // esi@2
    float v2; // ST04_4@3
    float v3; // ST00_4@3
    RGE_Player *v4; // eax@3
    __int16 v5; // ST04_2@3
    int v6; // ST00_4@3
    RGE_Player *v7; // eax@3

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v1 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)[1].sound_num;
        if ( v1 )
        {
            v2 = *(float *)(v1 + 60);
            v3 = *(float *)(v1 + 56);
            v4 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::set_view_loc(v4, v3, v2);
            v5 = (signed __int64)*(float *)(v1 + 60);
            v6 = (signed __int64)*(float *)(v1 + 56);
            v7 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::set_map_loc(v7, v6, v5);
        }
    }
}

//----- (0049D100) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_view_tribe(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // edi@1
    RGE_Game_World *v2; // eax@2
    RGE_Static_Object *v3; // esi@2
    RGE_Player *v4; // eax@3
    RGE_Player *v5; // eax@3
    float v6; // ST04_4@3
    float v7; // ST00_4@3
    RGE_Player *v8; // eax@3
    __int16 v9; // ST04_2@3
    int v10; // ST00_4@3
    RGE_Player *v11; // eax@3

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = RGE_Base_Game::get_player(rge_base_game);
        v3 = TRIBE_Player::find_obj((TRIBE_Player *)v2, 109, 0);
        if ( v3 )
        {
            v4 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::unselect_object(v4);
            v5 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::select_object(v5, v3);
            v6 = v3->world_y;
            v7 = v3->world_x;
            v8 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::set_view_loc(v8, v7, v6);
            v9 = (signed __int64)v3->world_y;
            v10 = (signed __int64)v3->world_x;
            v11 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            RGE_Player::set_map_loc(v11, v10, v9);
            ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(1);
        }
    }
}

//----- (0049D1B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_visibility(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1

    v1 = this;
    if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
    {
        RGE_Base_Game::set_map_visible(rge_base_game, v1->world->map->map_visible_flag == 0);
        ((void (__stdcall *)(signed int))v1->main_view->vfptr->set_redraw)(2);
        ((void (__stdcall *)(signed int))v1->map_view->vfptr->set_redraw)(2);
    }
}

//----- (0049D200) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_work(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    RGE_Player *v2; // eax@2
    char *v3; // eax@3
    __int16 list_num; // [sp+6h] [bp-6h]@2
    RGE_Static_Object **list; // [sp+8h] [bp-4h]@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
        if ( RGE_Player::get_selected_objects_to_command(v2, &list, &list_num, -1, -1, -1, -1) )
        {
            free(list);
            v3 = TPanel::get_string(3041);
            TMessagePanel::show_message(v1->message_panel, BadMessage, v3, 50, 0, 0, 0, 0);
            (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(5, 0);
        }
    }
}

//----- (0049D290) --------------------------------------------------------
void __stdcall TRIBE_Screen_Game::command_formation(int formationID)
{
    RGE_Game_World *v2; // eax@2

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = RGE_Base_Game::get_player(rge_base_game);
        ((void (__thiscall *)(RGE_Game_World *, int))v2->vfptr->update)(v2, formationID);
    }
}

//----- (0049D2C0) --------------------------------------------------------
void TRIBE_Screen_Game::command_stand_ground()
{
    RGE_Game_World *v1; // eax@2

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v1 = RGE_Base_Game::get_player(rge_base_game);
        v1->vfptr->get_game_state(v1);
    }
}

//----- (0049D2F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::command_attack_ground(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // esi@1
    char *v2; // eax@2

    v1 = this;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = TPanel::get_string(3045);
        TMessagePanel::show_message(v1->message_panel, BadMessage, v2, 50, 0, 0, 0, 0);
        (*(void (__stdcall **)(signed int, _DWORD))&rge_base_game->vfptr->gap8[8])(100, 0);
    }
}

//----- (0049D340) --------------------------------------------------------
void __stdcall TRIBE_Screen_Game::command_trade_attribute(int attribute)
{
    RGE_Game_World *v2; // eax@2

    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v2 = RGE_Base_Game::get_player(rge_base_game);
        TRIBE_Player::command_trade_attribute((TRIBE_Player *)v2, attribute);
    }
}

//----- (0049D370) --------------------------------------------------------
void __stdcall TRIBE_Screen_Game::command_tab_selected(int forward)
{
    RGE_Game_World *v2; // esi@1
    signed int v3; // edi@1
    int v4; // ebx@1
    __int16 v5; // bp@2
    __int16 v6; // cx@4
    __int16 v7; // dx@4
    int v8; // eax@6
    __int16 v9; // cx@16
    __int16 v10; // dx@16
    int v11; // eax@18

    v2 = RGE_Base_Game::get_player(rge_base_game);
    v3 = 0;
    v4 = 0;
    if ( !RGE_Base_Game::get_paused(rge_base_game) )
    {
        v5 = v2[1].numberNegativeObjectsValue;
        if ( v5 >= 2 )
        {
            if ( forward )
            {
                v6 = 0;
                v7 = 0;
                while ( v7 < v5 )
                {
                    v8 = *((_DWORD *)&v2[1].sounds + v6);
                    if ( v8 )
                    {
                        if ( v8 == *(_DWORD *)&v2[1].sound_num )
                        {
                            v3 = 1;
                        }
                        else
                        {
                            if ( v3 )
                            {
                                v4 = *((_DWORD *)&v2[1].sounds + v6);
                                break;
                            }
                            if ( !v4 )
                                v4 = *((_DWORD *)&v2[1].sounds + v6);
                        }
                        ++v7;
                    }
                    if ( ++v6 >= 25 )
                        break;
                }
            }
            else
            {
                v9 = 0;
                v10 = 0;
                do
                {
                    if ( v10 >= v5 )
                        break;
                    v11 = *((_DWORD *)&v2[1].sounds + v9);
                    if ( v11 )
                    {
                        if ( v11 == *(_DWORD *)&v2[1].sound_num )
                        {
                            if ( v4 )
                                goto LABEL_26;
                        }
                        else
                        {
                            v4 = *((_DWORD *)&v2[1].sounds + v9);
                        }
                        ++v10;
                    }
                    ++v9;
                }
                while ( v9 < 25 );
            }
            if ( v4 )
LABEL_26:
                *(_DWORD *)&v2[1].sound_num = v4;
        }
    }
}

//----- (0049D440) --------------------------------------------------------
int TRIBE_Screen_Game::any_selected_have_action()
{
    RGE_Game_World *v1; // ebp@1
    signed int v2; // edi@1
    signed int v3; // ebx@1
    RGE_Action_Object **v4; // esi@1
    RGE_Action_Object *v5; // ecx@3
    char v6; // al@4

    v1 = RGE_Base_Game::get_player(rge_base_game);
    v2 = 0;
    v3 = 0;
    v4 = (RGE_Action_Object **)&v1[1].sounds;
    while ( v3 < SLOWORD(v1[1].numberNegativeObjectsValue) )
    {
        v5 = *v4;
        if ( *v4 )
        {
            v6 = v5->master_obj->master_type;
            if ( (unsigned __int8)v6 >= 0x28u && (unsigned __int8)v6 <= 0x50u && RGE_Action_Object::have_action(v5) )
                return 1;
            ++v3;
        }
        ++v2;
        ++v4;
        if ( v2 >= 25 )
            return 0;
    }
    return 0;
}

//----- (0049D4B0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::set_focus(TRIBE_Screen_Game *this, int have_focus_in)
{
    TRIBE_Screen_Game *v2; // esi@1

    v2 = this;
    TScreenPanel::set_focus((TScreenPanel *)&this->vfptr, have_focus_in);
    if ( v2->have_focus )
        RGE_Base_Game::set_windows_mouse(rge_base_game, 0);
    else
        RGE_Base_Game::set_windows_mouse(rge_base_game, 1);
}

//----- (0049D4F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Game::stop_sound_system(TRIBE_Screen_Game *this)
{
    TRIBE_Screen_Game *v1; // edi@1
    TDigital *v2; // esi@1

    v1 = this;
    v2 = this->game_over_sound;
    if ( v2 )
    {
        TDigital::~TDigital(this->game_over_sound);
        operator delete(v2);
        v1->game_over_sound = 0;
    }
    TPanel::stop_sound_system((TPanel *)&v1->vfptr);
}
