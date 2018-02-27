
/**
 * @file    Engine\RGE\BaseGame.cpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

void RGE_Base_Game::RGE_Base_Game(RGE_Prog_Info *prog_info_in, int do_setup)
{
    do_draw_log = 0;
    safe_draw_log = 0;
    draw_log_name = 0;
    draw_log = 0;

    this->setVersion(1.0);
#if ENGINE_ROR
    this->setScenarioGame(0);
    this->setCampaignGame(0);
#endif
    this->setSavedGame(0);
    this->setSinglePlayerGame(1);
    this->setMultiplayerGame(0);
    this->setMapSize(96, 96, 8);
    this->setAllowCheatCodes(0);
    this->setCheatNotification(1);
    this->setFullVisibility(0);
    this->setFogOfWar(1);
#if ENGINE_AOC
    this->setGameSpeed(1069547520);
    this->setMPGameSpeed(1069547520);
    this->lockSpeedOff(game);
    this->lockTeamsOff(game);
#elif ENGINE_ROR
    this->setColoredChat(1);
#endif
    this->setGameDeveloperMode(0);
    this->setDifficulty(0);
    int i = 0;
    do
    {
        this->setPlayerCDAndVersion(i, 0);
        this->setPlayerHasCD(i, 0);
        this->setPlayerVersion(i, 0);
        this->setPlayerTeam(i, 1);
    }
    while( ++i < RGE_PLAYERS_COUNT );

    this->setPathFinding(0);
    this->setMpPathFinding(0);
    this->setNumberPlayers(4);
    this->setScenarioName(message_in);

    rge_base_game = this;

    this->prog_info = prog_info_in;
    this->prog_window = 0;
    this->prog_ready = 0;
    this->prog_active = 1;
    this->prog_palette = 0;
    this->window_style = 0;
    StringTable = 0;
    this->screen_saver_enabled = 0;
    this->error_code = 0;
    this->is_timer = 0;
    this->draw_system = 0;
    this->draw_area = 0;
    this->outline_type = 2;
    this->custom_mouse = 0;
    this->shapes = 0;
    this->sound_system = 0;
    this->music_system = 0;
    this->sound_num = 0;
    this->sounds = 0;
    this->save_music_type = 0;
    this->save_music_track_from = 0;
    this->save_music_track_to = 0;
    this->save_music_cur_track = 0;
    this->save_music_file[0] = 0;
    this->save_music_loop = 0;
    this->save_music_pos = 0;
    this->comm_handler = 0;
    this->debugLog = 0;
    this->log_comm = 0;
    this->comm_syncstop = 0;
    this->comm_syncmsg = 0;
    this->comm_stepmode = 0;
    this->comm_speed = 1;
    this->comm_droppackets = 0;
    this->registry = 0;
    this->prog_mode = 0;
    this->game_mode = 0;
    this->sub_game_mode = 0;
    this->paused = 0;
    this->mouse_pointer = 0;
    this->erase_mouse = 0;
    this->mouse_blit_sync = 0;
    this->is_mouse_on = 1;
    this->windows_mouse = 1;
    this->mouse_cursor = LoadCursorA(0, (LPCSTR)0x7F00);
    this->font_num = 0;
    this->fonts = 0;
    GetCurrentDirectoryA(0x105u, this->work_dir);
    strcpy(this->string_dll_name, aLanguage_dll);
    this->master_obj_id = -1;
    this->terrain_id = -1;
    this->elevation_height = -1;
    this->world = 0;
    this->render_all = 1;
    this->brush_size = 1;
    this->timing_text[0] = 0;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    this->last_view_time = 0;
    this = (int)&this->timings[0].last_time;
    int v6 = RGE_GAME_TIMINGS_COUNTER;
    do
    {
        *(_DWORD *)(v5 - 4) = 0;
        *(_DWORD *)v5 = 0;
        *(_DWORD *)(v5 + 4) = 0;
        *(_DWORD *)(v5 + 16) = 0;
        *(_DWORD *)(v5 + 20) = 0;
        *(_DWORD *)(v5 + 24) = 0;
        *(_DWORD *)(v5 + 8) = 0;
        *(_DWORD *)(v5 + 12) = 0;
        v5 += 32;
    }
    while( --v6 );
    this->do_show_timings = 0;
    this->do_show_comm = 0;
    this->do_show_ai = 0;
    this->save_check_for_cd = 1;

    /* Debugging-Log System */
    L = 0;

    AppWnd = 0;
    AppInst = this->prog_info->instance;
    chat = 0;
    comm = 0;
    Regs = 0;
    sound_driver = 0;
    driveInfo = 0;
    this->scenario_info = 0;
    int j = 0;
    do
    {
        this->resigned[j] = 0;
        this->playerIDValue[j] = 0;
    }
    while( ++j < RGE_PLAYERS_COUNT );
    this->auto_paused = 0;
    this->rollover = 1;
    this->map_save_area = 0;
    this->game_speed = -1.0;
    this->single_player_difficulty = 2;
    if( this->setup_registry() )
    {
        Regs = this->registry;
        this->setup_debugging_log();
        if( v10 )
        {
            L = this->debugLog;
            if( do_setup && !this->setup() && !this->error_code )
                this->error_code = 1;

            this->display_selected_ids = 0;
        }
        else
        {
            this->error_code = 15;
        }
    }
    else
    {
        this->error_code = 14;
    }
}

int RGE_Base_Game::setup()
{
    RGE_Base_Game *v1; // esi@1
    unsigned int v2; // eax@1
    char *v3; // eax@1
    char *v4; // eax@13
    char *v5; // eax@19
    char *v6; // eax@21
    char *v7; // eax@24
    char *v8; // eax@27
    RGE_Base_GameVtbl *v9; // edi@33
    int v10; // eax@45
    int v11; // eax@57
    DriveInformation *v12; // eax@82
    void *v13; // eax@83
    void *v14; // ST08_4@88
    UINT_PTR v15; // eax@88
    TRegistry *v16; // ecx@88
    char *v17; // eax@89
    RGE_Game_Info *v18; // eax@89
    RGE_Game_Info *v19; // eax@90
    int v20; // edi@91
    RGE_Game_Info *v21; // eax@95
    RGE_Scenario_File_Info *v22; // eax@99
    RGE_Scenario_File_Info *v23; // eax@100
    int v24; // esi@104
    unsigned int DXPlatform; // [sp+14h] [bp-3D8h]@51
    unsigned int DXVersion; // [sp+18h] [bp-3D4h]@17
    _MEMORYSTATUS ms; // [sp+1Ch] [bp-3D0h]@37
    char filename[260]; // [sp+3Ch] [bp-3B0h]@89
    char s[256]; // [sp+140h] [bp-2ACh]@105
    struct _OFSTRUCT ReOpenBuff; // [sp+240h] [bp-1ACh]@105
    _finddata_t file_info; // [sp+2C8h] [bp-124h]@31
    int v33; // [sp+3E8h] [bp-4h]@82

    v1 = this;
    v2 = debug_timeGetTime();
    debug_srand(aCMsdevWorkA_51, 522, v2);
    v3 = TRegistry::RegGetInt(v1->registry, 1, tszName);
    if( (signed int)v3 > 800 )
    {
        if( v3 == (char *)1024 )
        {
            v1->prog_info->main_wid = 1024;
            v1->prog_info->main_hgt = 768;
        }
        else if( v3 == (char *)1280 )
        {
            v1->prog_info->main_wid = 1280;
            v1->prog_info->main_hgt = 1024;
        }
    }
    else if( v3 == (char *)800 )
    {
        v1->prog_info->main_wid = 800;
        v1->prog_info->main_hgt = 600;
    }
    else if( v3 == (char *)640 )
    {
        v1->prog_info->main_wid = 640;
        v1->prog_info->main_hgt = 480;
    }
    v1->rollover = TRegistry::RegGetInt(v1->registry, 1, aRolloverText) != (char *)2;
    v4 = TRegistry::RegGetInt(v1->registry, 1, aMouseStyle);
    if( v4 == (char *)2 )
    {
        v1->prog_info->interface_style = 2;
    }
    else if( v4 == (char *)1 )
    {
        v1->prog_info->interface_style = 1;
    }
    DXVersion = (unsigned int)TRegistry::RegGetInt(v1->registry, 1, aGameSpeed);
    if( DXVersion != -1 )
        v1->game_speed = (double)(signed int)DXVersion * 0.1;
    v5 = TRegistry::RegGetInt(v1->registry, 1, aDifficulty);
    if( v5 != (char *)-1 )
        v1->single_player_difficulty = (int)v5;
    v6 = TRegistry::RegGetInt(v1->registry, 1, aPathFinding);
    if( (signed int)v6 >= 1 && (signed int)v6 <= 3 )
        RGE_Base_Game::setPathFinding(v1, (_BYTE)v6 - 1);
    v7 = TRegistry::RegGetInt(v1->registry, 1, aMpPathFinding);
    if( (signed int)v7 >= 1 && (signed int)v7 <= 3 )
        RGE_Base_Game::setMpPathFinding(v1, (_BYTE)v7 - 1);
    v8 = TRegistry::RegGetInt(v1->registry, 1, aScrollSpeed);
    if( v8 != (char *)-1 && (signed int)v8 >= 10 && (signed int)v8 <= 200 )
    {
        v1->prog_info->mouse_scroll_interval = (unsigned int)v8;
        v1->prog_info->key_scroll_interval = (unsigned int)v8;
    }
    if( _findfirst(aEmpires_exe, &file_info) == -1 )
    {
        v1->error_code = 23;
        return 0;
    }
    v9 = v1->vfptr;
    if( !v1->vfptr->setup_cmd_options(v1) )
    {
        v1->error_code = 2;
        return 0;
    }
    StringTable = LoadLibraryA(v1->string_dll_name);
    if( !StringTable )
    {
        v1->error_code = 1;
        return 0;
    }
    GlobalMemoryStatus(&ms);
    if( (ms.dwAvailPhys < 0x1400000 || ms.dwAvailPageFile < 0xA00000)
        && (ms.dwAvailPhys < 0xA00000 || ms.dwAvailPageFile < 0x1400000)
        && ms.dwAvailPageFile < 0x1E00000 )
    {
        v1->error_code = 22;
        return 0;
    }
    v9->set_interface_messages(v1);
    if( debugActions == 1 )
        actionFile = fopen(aCAoeact_txt, aW_1);
    if( v1->prog_info->check_expiration )
    {
        LOBYTE(v10) = RGE_Base_Game::check_expiration(v1);
        if( !v10 )
        {
            v1->error_code = 3;
            return 0;
        }
    }
    if( v1->prog_info->check_multi_copies && !RGE_Base_Game::check_multi_copies(v1) )
    {
        v1->error_code = 4;
        return 0;
    }
    if( !RGE_Base_Game::check_prog_argument(v1, argument) )
    {
        GetDXVersion(&DXVersion, &DXPlatform);
        if( DXVersion < 0x501 )
        {
            v1->error_code = 20;
            return 0;
        }
    }
    SystemParametersInfoA(0x10u, 0, &v1->screen_saver_enabled, 0);
    if( v1->screen_saver_enabled )
        SystemParametersInfoA(0x11u, 0, 0, 2u);
    SystemParametersInfoA(0x53u, 0, &v1->low_power_enabled, 0);
    if( v1->low_power_enabled )
        SystemParametersInfoA(0x55u, 0, 0, 2u);
    LOBYTE(v11) = RGE_Base_Game::check_for_cd(v1, 0);
    v1->save_check_for_cd = v11;
    if( !v9->setup_class(v1) )
    {
        v1->error_code = 5;
        return 0;
    }
    if( !v9->setup_main_window(v1) )
    {
        v1->error_code = 6;
        return 0;
    }
    if( !v9->setup_graphics_system(v1) )
    {
        if( !v1->error_code )
            v1->error_code = 7;
        return 0;
    }
    if( !v9->setup_palette(v1) )
    {
        v1->error_code = 17;
        return 0;
    }
    if( !v9->setup_shapes(v1) )
    {
        v1->error_code = 7;
        return 0;
    }
    if( !v9->setup_map_save_area(v1) )
    {
        v1->error_code = 7;
        return 0;
    }
    if( !v9->setup_mouse(v1) )
    {
        v1->error_code = 8;
        return 0;
    }
    if( !v9->setup_sound_system(v1) )
    {
        v1->error_code = 10;
        return 0;
    }
    if( !v9->setup_chat(v1) )
    {
        v1->error_code = 16;
        return 0;
    }
    if( !v9->setup_comm(v1) )
    {
        v1->error_code = 9;
        return 0;
    }
    if( !v9->setup_fonts(v1) )
    {
        v1->error_code = 11;
        return 0;
    }
    if( !v9->setup_sounds(v1) )
    {
        v1->error_code = 12;
        return 0;
    }
    v12 = (DriveInformation *)operator new(0x274u);
    DXPlatform = (unsigned int)v12;
    v33 = 0;
    if( v12 )
        DriveInformation::DriveInformation(v12);
    else
        v13 = 0;
    driveInfo = v13;
    v33 = -1;
    if( !v13 )
        return 0;
    if( !v9->setup_blank_screen(v1) )
    {
        v1->error_code = 13;
        return 0;
    }
    (*(void (__thiscall **)(RGE_Base_Game *, _DWORD))&v9->gap8[4])(v1, 0);
    v9->setup_timings(v1);
    v9->handle_size(v1, v1->prog_window, 0, 0, 0);
    v14 = v1->prog_window;
    v1->prog_ready = 1;
    ShowWindow(v14, 5);
    SetFocus(v1->prog_window);
    RGE_Base_Game::mouse_on(v1);
    v15 = SetTimer(v1->prog_window, 1u, 0x32u, 0);
    v16 = v1->registry;
    v1->is_timer = v15;
    if( (signed int)TRegistry::RegGetInt(v16, 0, aGameFileNumber) < 0 )
    {
        v20 = 0;
        while( 1 )
        {
            sprintf(filename, aGameD_nfo, v20);
            if( _findfirst(filename, &file_info) == -1 )
                break;
            if( ++v20 >= 9999 )
                goto LABEL_99;
        }
        TRegistry::RegSetInt(v1->registry, 0, aGameFileNumber, v20);
        v21 = (RGE_Game_Info *)operator new(0x118u);
        DXPlatform = (unsigned int)v21;
        v33 = 2;
        if( v21 )
        {
            RGE_Game_Info::RGE_Game_Info(v21, filename);
            goto LABEL_98;
        }
    }
    else
    {
        v17 = TRegistry::RegGetInt(v1->registry, 0, aGameFileNumber);
        sprintf(filename, aGameD_nfo, v17);
        v18 = (RGE_Game_Info *)operator new(0x118u);
        DXPlatform = (unsigned int)v18;
        v33 = 1;
        if( v18 )
        {
            RGE_Game_Info::RGE_Game_Info(v18, filename);
            goto LABEL_98;
        }
    }
    v19 = 0;
LABEL_98:
    v33 = -1;
    v1->player_game_info = v19;
LABEL_99:
    sprintf(filename, aSscenario_inf, v1->prog_info->scenario_dir);
    v22 = (RGE_Scenario_File_Info *)operator new(0x10Cu);
    DXPlatform = (unsigned int)v22;
    v33 = 3;
    if( v22 )
        RGE_Scenario_File_Info::RGE_Scenario_File_Info(v22, filename);
    else
        v23 = 0;
    v1->scenario_info = v23;
    v33 = -1;
    if( do_draw_log )
    {
        if( draw_log_name )
        {
            draw_log = fopen(&draw_log_name, aW_1);
        }
        else
        {
            v24 = 0;
            while( 1 )
            {
                sprintf(s, aDrawlogD_txt, v24);
                if( OpenFile(s, &ReOpenBuff, 0x4000u) == -1 )
                    break;
                if( ++v24 >= 1000 )
                    goto LABEL_110;
            }
            draw_log = fopen(s, aW_1);
            strcpy(&draw_log_name, s);
        }
    }
LABEL_110:
    if( do_fps_log )
    {
        fps_log = fopen(aCFps_txt, aW_1);
        if( !fps_log )
            do_fps_log = 0;
    }
    return 1;
}

void RGE_Base_Game::set_prog_mode(int new_mode)
{
    this->prog_mode = new_mode;
}

TPanel *RGE_Base_Game::get_view_panel()
{
    return 0;
}

TPanel *RGE_Base_Game::get_map_panel()
{
    return 0;
}

void RGE_Base_Game::~RGE_Base_Game()
{
    RGE_Base_Game *v1; // esi@1
    TDrawSystem *v2; // eax@4
    char v3; // al@9
    char v4; // al@9
    RGE_Scenario_File_Info *v5; // edi@15
    char *v6; // eax@19
    RGE_Game_Info *v7; // edi@20
    RGE_Game_World *v8; // ecx@23
    TDrawArea *v9; // edi@25
    TMousePointer *v10; // edi@27
    TCommunications_Handler *v11; // edi@31
    TChat *v12; // edi@33
    signed int v13; // ebp@36
    int v14; // edi@37
    TDrawSystem *v15; // edi@42
    TRegistry *v16; // edi@50
    HWND v17; // eax@57
    TDebuggingLog *v18; // edi@62
    signed int i; // ebp@65
    TShape **v20; // eax@66
    TShape *v21; // edi@66

    if( do_debug_random && !wrote_debug_random_log )
    {
        debug_random_write();
        dump_vismap_log();
    }
    if( this->draw_system )
        this->registry->RegSetInt(1, tszName, this->draw_system->ScreenWidth);

    this->registry->RegSetInt(1, aRolloverText, 2 - (this->rollover != 0));

    if( this->prog_info->interface_style == 2 )
        this->registry->RegSetInt(1, aMouseStyle, 2);
    else
        this->registry->RegSetInt(1, aMouseStyle, 1);

    this->registry->RegSetInt(1, aGameSpeed, (signed __int64)(this->game_speed * 10.0));
    this->registry->RegSetInt(1, aDifficulty, this->single_player_difficulty);
    this->registry->RegSetInt(1, aPathFinding, (unsigned __int8)this->pathFinding() + 1);
    this->registry->RegSetInt(1, aMpPathFinding, (unsigned __int8)this->mpPathFinding() + 1);
    this->registry->RegSetInt(1, aScrollSpeed, this->prog_info->mouse_scroll_interval);

    if( actionFile )
    {
        fclose(actionFile);
        actionFile = 0;
    }
    if( fps_log )
    {
        fclose(fps_log);
        fps_log = 0;
    }
    if( draw_log )
    {
        fclose(draw_log);
        draw_log = 0;
    }
    if( this->scenario_info )
    {
        delete this->scenario_info;
    }
    if( this->player_game_info )
    {
        if( this->registry->RegGetInt(0, aGameFileNumber) >= 0 )
        {
            char filename[13];
            char *v6 = this->registry->RegGetInt(0, aGameFileNumber);
            sprintf(filename, aGameD_nfo, v6);
            this->player_game_info->save(filename);
        }
        if( this->player_game_info )
        {
            delete this->player_game_info;
        }
        this->player_game_info = 0;
    }
    this->prog_mode = 0;

    if( this->world )
    {
        delete this->world;
    }
    if( this->map_save_area )
    {
        delete this->map_save_area;
    }
    if( this->mouse_pointer )
    {
        delete this->mouse_pointer;
    }
    if( driveInfo )
    {
        delete driveInfo;
    }
    if( this->comm_handler )
    {
        delete this->comm_handler;
    }
    if( chat )
    {
        delete chat;
    }
    if( this->fonts )
    {
        int v13 = 0;
        if( this->font_num > 0 )
        {
            int v14 = 0;
            do
            {
                if( this->fonts[v14].font )
                    DeleteObject(this->fonts[v14].font);

                v14++;
            }
            while( ++v13 < this->font_num );
        }
        free(this->fonts);
    }
    this->stop_sound_system();

    &panel_system->destroyPanel(name);

    if( this->draw_system )
    {
        delete this->draw_system;

        this->draw_system = 0;
        this->draw_area = 0;
    }
    if( this->screen_saver_enabled )
        SystemParametersInfo(
            SPI_GETBEEP|SPI_GETSCREENSAVEACTIVE,
            1u, 0, SPIF_SENDCHANGE);

    if( this->low_power_enabled )
        SystemParametersInfo(
            SPI_GETBEEP|SPI_SETMOUSE|SPI_GETSCREENSAVEACTIVE|SPI_GETSOUNDSENTRY,
            1u, 0, SPIF_SENDCHANGE);

    if( this->prog_palette )
    {
        &panel_system->release_palette(this->prog_palette);
        this->prog_palette = 0;
    }
    if( this->registry )
    {
        delete this->registry;
    }
    if( this->prog_mutex )
    {
        CloseHandle(this->prog_mutex);
        this->prog_mutex = 0;
    }
    rge_base_game = 0;

    if( this->prog_window )
        DestroyWindow(this->prog_window);

    char str[256];
    RGE_Base_Game::get_string(1003, str, sizeof(str));
    if( str[0] )
    {
        HWND v17 = FindWindowA(ClassName, str);
        if( v17 )
            SendMessageA(v17, 0x10u, 0, 0);/* TODO */
    }
    if( StringTable && StringTable != this->prog_info->instance )
    {
        FreeLibrary(StringTable);
        StringTable = 0;
    }
    if( this->debugLog )
    {
        delete this->debugLog;
    }
    if( this->shapes )
    {
        for( int i = 0; i < this->shape_num; i++ )
        {
            if( this->shapes[i] )
            {
                delete this->shapes[i];
            }
        }
        free(this->shapes);
    }
}

int RGE_Base_Game::processCheatCode(int a2, char *a3)
{
    return 0;
}

int RGE_Base_Game::handle_message(MSG *msg)
{
    return 1;
}

int RGE_Base_Game::action_update()
{
    return 1;
}

int RGE_Base_Game::action_mouse_move(int x, int y, int left_btn, int right_btn, int ctrl_key, int shift_key)
{
    return 1;
}

int RGE_Base_Game::action_key_down(unsigned int key, int repeat_count, int ctrl_key, int alt_key, int shift_key)
{
    return 1;
}

int RGE_Base_Game::action_user_command(unsigned int val1, unsigned int val2)
{
    return 1;
}

int RGE_Base_Game::action_command(unsigned int val1, unsigned int val2)
{
    return 1;
}

int RGE_Base_Game::action_music_done()
{
    return 1;
}

int RGE_Base_Game::action_activate()
{
    return 1;
}

int RGE_Base_Game::action_deactivate()
{
    return 1;
}

int RGE_Base_Game::action_init_menu()
{
    return 1;
}

int RGE_Base_Game::action_exit_menu()
{
    return 1;
}

int RGE_Base_Game::action_size()
{
    return 1;
}

int RGE_Base_Game::action_close()
{
    return 1;
}

void RGE_Base_Game::reset_timings()
{
    char *v1; // eax@1
    signed int v2; // ecx@1

    v1 = (char *)&this->timings[0].last_time;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;
    v2 = 30;
    do
    {
        *((_DWORD *)v1 - 1) = 0;
        *(_DWORD *)v1 = 0;
        *((_DWORD *)v1 + 1) = 0;
        *((_DWORD *)v1 + 4) = 0;
        *((_DWORD *)v1 + 5) = 0;
        *((_DWORD *)v1 + 6) = 0;
        v1 += 32;
        --v2;
    }
    while( v2 );
}

void RGE_Base_Game::add_to_timing(int id, unsigned int time)
{
    char *v3; // eax@1
    char *v4; // eax@1

    v3 = (char *)this + 32 * id;
    *((_DWORD *)v3 + 330) += time;
    *((_DWORD *)v3 + 335) = time;
    v4 = (char *)this + 32 * (id + 42);
    if( time > *(_DWORD *)v4 )
        *(_DWORD *)v4 = time;
}

void RGE_Base_Game::increment_world_update_count()
{
    this->world_update_count++;
}

void RGE_Base_Game::increment_view_update_count()
{
    this->view_update_count++;
}

void RGE_Base_Game::set_last_single_time(int id, unsigned int time)
{
    this->timings[id].last_single_time = time;
}

unsigned int RGE_Base_Game::get_last_time(int id)
{
    return this->timings[id].last_time;
}

unsigned int RGE_Base_Game::get_last_single_time(int id)
{
    return this->timings[id].last_single_time;
}

unsigned int RGE_Base_Game::get_accum_time(int id)
{
    return this->timings[id].accum_time;
}

unsigned int RGE_Base_Game::get_max_time(int id)
{
    return this->timings[id].max_time;
}

unsigned int RGE_Base_Game::get_last_max_time(int id)
{
    return this->timings[id].last_max_time;
}

unsigned int RGE_Base_Game::get_last_world_update_count()
{
    return this->last_world_update_count;
}

unsigned int RGE_Base_Game::get_last_view_update_count()
{
    return this->last_view_update_count;
}

unsigned int RGE_Base_Game::get_world_update_count()
{
    return this->world_update_count;
}

unsigned int RGE_Base_Game::get_view_update_count()
{
    return this->view_update_count;
}

int RGE_Base_Game::get_error_code()
{
    return this->error_code;
}

char *RGE_Base_Game::get_string(int text_id)
{
    (*(void (__stdcall **)(int, char *, signed int))&this->vfptr->gap8[24])(text_id, temp_getstring, 512);
    return temp_getstring;
}

char *RGE_Base_Game::get_string(int string_id, char *str, int max_len)
{
    if( !LoadStringA(StringTable, string_id, str, max_len) )
        *str = 0;
    str[max_len - 1] = 0;
    return str;
}

char *RGE_Base_Game::get_string(int string_type, int id, char *str, int max_len)
{
    return (char *)(*(int (__stdcall **)(int, int, _DWORD, char *, int))&this->vfptr->gap28[0])(
                                     string_type,
                                     id,
                                     0,
                                     str,
                                     max_len);
}

//----- (0041CA10) --------------------------------------------------------
char *RGE_Base_Game::get_string2(int string_type, int id, int id2, char *str, int max_len)
{
    char *result; // eax@1

    result = str;
    *str = 0;
    if( string_type == 1 )
    {
        switch( id )
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 14:
            case 15:
                result = (char *)(*(int (__stdcall **)(signed int, char *, int))&this->vfptr->gap8[24])(2002, str, max_len);
                break;
            case 7:
            case 8:
            case 11:
            case 13:
            case 17:
                result = (char *)(*(int (__stdcall **)(signed int, char *, int))&this->vfptr->gap8[24])(2003, str, max_len);
                break;
            case 19:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2011, str, max_len);
                break;
            case 9:
            case 16:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2005, str, max_len);
                break;
            case 10:
            case 12:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2004, str, max_len);
                break;
            case 18:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2012, str, max_len);
                break;
            case 20:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2013, str, max_len);
                break;
            case 21:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2014, str, max_len);
                break;
            case 22:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2015, str, max_len);
                break;
            case 23:
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2016, str, max_len);
                break;
            default:
                goto LABEL_15;
        }
    }
    else if( string_type == 2 )
    {
        result = (char *)(*(int (__stdcall **)(int, char *, int))&this->vfptr->gap8[24])(id, str, max_len);
    }
    else
    {
LABEL_15:
        str[max_len - 1] = 0;
    }
    return result;
}

RGE_Scenario *RGE_Base_Game::get_scenario_info(char *scenario_file, int from_campaign)
{
    int header_size;
    int version;
    int obj_id;

    char temp_name[300];
    sprintf(temp_name, aSS, this->prog_info->scenario_dir, scenario_file);

    if( from_campaign )
    {
        handle = this->player_game_info->open_scenario();
    }
    else
    {
        if( !scenario_file )
            return NULL;

        handle = rge_open(temp_name, 0x8000);
    }
    if( handle == -1 )
        return NULL;

    rge_read_uncompressed(handle, &version, 4);

    rge_read_uncompressed(handle, &header_size, 4);
    if( header_size > 0 )
    {
        void *header_data = malloc(header_size);
        if( !header_data )
        {
            rge_close(handle);
            return NULL;
        }
        rge_read_uncompressed(handle, header_data, header_size);

        free(header_data);
    }
    rge_read(handle, &obj_id, 4);

    RGE_Scenario *scenario = this->new_scenario_info(handle);

    rge_close(handle);

    return scenario;
}

RGE_Scenario_Header *RGE_Base_Game::get_scenario_header(char *scenario_file, int from_campaign)
{
    RGE_Base_Game *v3; // edi@1
    int v4; // eax@2
    RGE_Scenario_Header *result; // eax@4
    int v6; // esi@6
    RGE_Scenario_Header *v7; // ebx@8
    int version; // [sp+Ch] [bp-130h]@8
    char temp_name[300]; // [sp+10h] [bp-12Ch]@1

    v3 = this;
    sprintf(temp_name, aSS, this->prog_info->scenario_dir, scenario_file);
    if( from_campaign )
    {
        v4 = RGE_Game_Info::open_scenario(v3->player_game_info);
    }
    else
    {
        if( !scenario_file )
            return 0;
        v4 = rge_open(temp_name, 0x8000);
    }
    v6 = v4;
    if( v4 == -1 )
        return NULL;

    rge_read_uncompressed(v4, &version, 4);
    v7 = 0;
    if( version == *(_DWORD *)a1_03
        || version == *(_DWORD *)a1_04
        || version == *(_DWORD *)a1_05
        || version == *(_DWORD *)a1_06
        || version == *(_DWORD *)a1_07
        || version == *(_DWORD *)a1_08
        || version == *(_DWORD *)a1_09
        || version == *(_DWORD *)a1_10
        || version == *(_DWORD *)a1_11 )
    {
        v7 = this->new_scenario_header((RGE_Scenario *)v6);
    }
    rge_close(v6);

    return v7;
}

void RGE_Base_Game::write_scenario_header(int outfile)
{
    int v2; // eax@1
    RGE_Scenario_Header *v3; // esi@1
    int header_size; // [sp+4h] [bp-4h]@3

    v2 = (*(int (__stdcall **)(RGE_Scenario *))&this->vfptr->gap34[0])(this->world->scenario);
    v3 = (RGE_Scenario_Header *)v2;
    if( v2 )
    {
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 4))(v2, outfile);
        RGE_Scenario_Header::~RGE_Scenario_Header(v3);
        operator delete(v3);
    }
    else
    {
        header_size = 0;
        rge_write_uncompressed(outfile, &header_size, 4);
    }
}

void RGE_Base_Game::new_scenario_header(int infile)
{
    return new RGE_Scenario_Header(infile);
}

void RGE_Base_Game::new_scenario_header(RGE_Scenario *scenario_info)
{
    return new RGE_Scenario_Header(scenario_info);
}

void RGE_Base_Game::new_scenario_info(int infile)
{
    return new RGE_Scenario(infile, 0);
}

void RGE_Base_Game::get_campaign_info(int *campaign, int *campaign_player, int *campaign_scenario)
{
    *campaign          = this->player_game_info->get_current_campaign();
    *campaign_player   = this->player_game_info->get_current_player();
    *campaign_scenario = this->player_game_info->get_current_scenario();
}

bool RGE_Base_Game::set_campaign_info(int campaign, int campaign_player, int campaign_scenario)
{
    return
        this->player_game_info->set_current_campaign(campaign) &&
        this->player_game_info->set_current_person(campaign_player) &&
        this->player_game_info->set_current_scenario(campaign_scenario);
}

void RGE_Base_Game::set_campaign_win()
{
    this->player_game_info->notify_of_scenario_complete();
}

unsigned int RGE_Base_Game::run()
{
    MSG msg;

    while( 1 )
    {
        while( this->prog_active )
        {
            if( this->prog_mode != 4 &&
                this->prog_mode != 2 )
                break;

            if( this->comm_handler &&
                this->comm_handler->IsPaused() )
                    break;

            if( PeekMessageA(&msg, 0, 0, 0, 1u) )
            {
                if( msg.message == 18 )
                    return msg.wParam;

                if( this->handle_message(&msg) )
                {
                    TranslateMessage(&msg);
                    DispatchMessageA(&msg);
                }
            }
            else
            {
                this->handle_idle();
            }
        }
        if( !GetMessageA(&msg, 0, 0, 0) )
            break;

        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    return msg.wParam;
}

int RGE_Base_Game::setup_cmd_options()
{
    unsigned __int8 *v2; // eax@27
    unsigned __int8 *v3; // esi@30
    unsigned __int8 *v4; // eax@34
    unsigned __int8 *v5; // esi@37
    unsigned __int8 *v6; // eax@141
    unsigned __int8 *v7; // esi@144
    unsigned __int8 *v8; // eax@148
    unsigned __int8 *v9; // esi@151
    unsigned __int8 *v10; // eax@183
    unsigned __int8 *v11; // esi@186
    unsigned __int8 *v12; // eax@190
    unsigned __int8 *v13; // esi@193
    unsigned __int8 *v14; // eax@196
    unsigned __int8 *v15; // esi@199
    unsigned __int8 *v16; // eax@203
    unsigned __int8 *v17; // esi@206
    unsigned __int8 *v18; // eax@210
    unsigned __int8 *v19; // esi@213
    unsigned __int8 *v20; // eax@217
    unsigned __int8 *v21; // esi@220
    unsigned __int8 *v22; // eax@224
    unsigned __int8 *v23; // esi@227
    unsigned __int8 *v24; // eax@234
    unsigned __int8 *v25; // esi@237
    unsigned __int8 *v26; // eax@262
    unsigned __int8 *v27; // esi@265
    unsigned __int8 *v28; // eax@269
    unsigned __int8 *v29; // esi@272

    char cmd_line[256];
    char temp_str[256];

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFFu);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);

    if( strstr(cmd_line, aNostartup) ||
        strstr(cmd_line, aNoStartup) ||
        strstr(cmd_line, aNo_startup) )
        this->prog_info->skip_startup = 1;

    if( strstr(cmd_line, aSystemmemory) ||
        strstr(cmd_line, aSystemMemory) ||
        strstr(cmd_line, aSystem_memory) )
        this->prog_info->use_sys_mem = 1;

    if( strstr(cmd_line, aMidimusic) ||
        strstr(cmd_line, aMidiMusic) ||
        strstr(cmd_line, aMidi_music) )
    {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 1;
        this->prog_info->use_wave_music = 0;
    }
    if( strstr(cmd_line, aMsync) )
        this->mouse_blit_sync = 1;

    DDSys_CanColorFill = strstr(cmd_line, aMfill) == 0;

    if( strstr(cmd_line, aNosound) ||
        strstr(cmd_line, aNoSound) ||
        strstr(cmd_line, aNo_sound) )
        this->prog_info->use_sound = 0;

    if( strstr(cmd_line, a640) )
    {
        this->prog_info->main_wid = 640;
        this->prog_info->main_hgt = 480;
    }
    if( strstr(cmd_line, a800) )
    {
        this->prog_info->main_wid = 800;
        this->prog_info->main_hgt = 600;
    }
    if( strstr(cmd_line, a1024) )
    {
        this->prog_info->main_wid = 1024;
        this->prog_info->main_hgt = 768;
    }
    if( strstr(cmd_line, aAllcp) )
    {
        all_cp = 1;
        do_run_log = 1;
        this->comm_speed = 0;
        do_debug_timeGetTime = 1;
        debug_timeGetTime_interval = 10;
        do_fixed_update = 1;
        fixed_update_time = 20;
    }
    v2 = _mbsstr((const unsigned __int8 *)cmd_line, aResend1);
    if( v2 )
    {
        for( ; *v2 != 61; v2 = _mbsninc(v2, 1u) )
            ;
        v3 = _mbsninc(v2, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v3); v3 = _mbsninc(v3, 1u) )
        {
            if( !*v3 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v3, 1u);
        }
        resend_adj1 = atol(temp_str);
    }
    v4 = _mbsstr((const unsigned __int8 *)cmd_line, aResend2);
    if( v4 )
    {
        for( ; *v4 != 61; v4 = _mbsninc(v4, 1u) )
            ;
        v5 = _mbsninc(v4, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v5); v5 = _mbsninc(v5, 1u) )
        {
            if( !*v5 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v5, 1u);
        }
        resend_adj2 = atol(temp_str);
    }
    if( strstr(cmd_line, aNomouse) ||
        strstr(cmd_line, aNoMouse) )
        this->custom_mouse = 0;

    if( strstr(cmd_line, aWing) )
    {
        this->prog_info->full_screen = 0;
        this->prog_info->use_dir_draw = 0;
    }
    if( strstr(cmd_line, aDirectdraw) ||
        strstr(cmd_line, aDirectDraw) )
        this->prog_info->use_dir_draw = 1;

    if( strstr(cmd_line, aFullscreen) ||
        strstr(cmd_line, aFullScreen) ||
        strstr(cmd_line, aFull_screen) )
    {
        this->prog_info->full_screen = 1;
        this->prog_info->use_dir_draw = 1;
    }
    if( strstr(cmd_line, aVideomemory) ||
        strstr(cmd_line, aVideoMemory) ||
        strstr(cmd_line, aVideo_memory) )
        this->prog_info->use_sys_mem = 0;

    if( strstr(cmd_line, aStreammusic) ||
        strstr(cmd_line, aStreamMusic) ||
        strstr(cmd_line, aStream_music) )
    {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 1;
    }
    if( strstr(cmd_line, aImamusic) ||
        strstr(cmd_line, aImaMusic) ||
        strstr(cmd_line, aIma_music) )
    {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 0;
        this->prog_info->use_ima = 1;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }
    if( strstr(cmd_line, aFastview) ||
        strstr(cmd_line, aFastView) ||
        strstr(cmd_line, aFast_view) )
        this->prog_info->fast_view = 1;

    if( strstr(cmd_line, aSlowview) ||
        strstr(cmd_line, aSlowView) ||
        strstr(cmd_line, aSlow_view) )
        this->prog_info->fast_view = 0;

    if( strstr(cmd_line, aOnebutton) ||
        strstr(cmd_line, aOneButton) ||
        strstr(cmd_line, aOne_button) )
        this->prog_info->interface_style = 1;

    if( strstr(cmd_line, aTwobutton) ||
        strstr(cmd_line, aTwoButton) ||
        strstr(cmd_line, aTwo_button) )
        this->prog_info->interface_style = 2;

    if( strstr(cmd_line, aRunlog) )
        do_run_log = 1;

    if( strstr(cmd_line, aSyncmsg) )
        this->comm_syncmsg = 1;

    if( strstr(cmd_line, aDroppackets) )
        this->comm_droppackets = 1;

    if( strstr(cmd_line, aNocommspeed) )
        this->comm_speed = 0;

    if( strstr(cmd_line, aSyncstop) )
        this->comm_syncstop = 1;

    if( strstr(cmd_line, aStepmode) )
        this->comm_stepmode = 1;

    if( strstr(cmd_line, aSquareoutline) ||
        strstr(cmd_line, aSquareOutline) ||
        strstr(cmd_line, aSquare_outline) )
        this->outline_type = 0;

    if( strstr(cmd_line, aCubeoutline) ||
        strstr(cmd_line, aCubeOutline) ||
        strstr(cmd_line, aCube_outline) )
        this->outline_type = 1;

    if( strstr(cmd_line, aGroundoutline) ||
        strstr(cmd_line, aGroundOutline) ||
        strstr(cmd_line, aGround_outline) )
        this->outline_type = 2;

    if( strstr(cmd_line, aEdgeoutline) ||
        strstr(cmd_line, aEdgeOutline) ||
        strstr(cmd_line, aEdge_outline) )
        this->outline_type = 3;

    if( strstr(cmd_line, aCustommouse) ||
        strstr(cmd_line, aCustomMouse) ||
        strstr(cmd_line, aCustom_mouse) )
        this->custom_mouse = 1;

    if( strstr(cmd_line, aNocp) )
        useComputerPlayers = 0;

    if( strstr(cmd_line, aLogai) )
        startLoggingAI = 1;

    if( strstr(cmd_line, aNologstatus) )
        logStatusOn = 0;

    if( strstr(cmd_line, aDologstatus) )
        logStatusOn = 1;

    if( strstr(cmd_line, aNoaicheat) )
        allowAIToCheat = 0;

    if( strstr(cmd_line, aNochatcheatcod) )
        chatCheatCodes = 0;

    if( strstr(cmd_line, aLogupdatechang) )
        logUpdateChanges = 1;

    if( strstr(cmd_line, aUip) )
        useInfluencePlacement = 1;

    if( strstr(cmd_line, aAllgrass) )
        all_grassland_on = 1;

    if( strstr(cmd_line, aAllcp) )
        all_cp = 1;

    if( strstr(cmd_line, aAllcp1) )
        all_cp = 2;

    if( strstr(cmd_line, aNopathlimit) )
        numberPathingIterations = -1;

    if( strstr(cmd_line, aUnp) )
        useNewPathing = -1;

    if( strstr(cmd_line, aColorlog) )
        do_color_log = 1;

    v6 = _mbsstr((const unsigned __int8 *)cmd_line, aLogai_1);
    if( v6 )
    {
        for( ; *v6 != 61; v6 = _mbsninc(v6, 1u) )
            ;
        v7 = _mbsninc(v6, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v7); v7 = _mbsninc(v7, 1u) )
        {
            if( !*v7 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v7, 1u);
        }
        specificAIPlayerToLog = atol(temp_str);
    }
    v8 = _mbsstr((const unsigned __int8 *)cmd_line, aLogdebug);
    if( v8 )
    {
        for( ; *v8 != 61; v8 = _mbsninc(v8, 1u) )
            ;
        v9 = _mbsninc(v8, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v9); v9 = _mbsninc(v9, 1u) )
        {
            if( !*v9 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v9, 1u);
        }
        logDebugID = atol(temp_str);
    }
    if( strstr(cmd_line, aNopathcap) )
        pathingCapValue = -1;

    if( strstr(cmd_line, aGamecd) )
        force_cd = 1;

    if( strstr(cmd_line, a1280) )
    {
        this->prog_info->main_wid = 1280;
        this->prog_info->main_hgt = 1024;
    }
    if( strstr(cmd_line, aLogfps) ||
        strstr(cmd_line, aLogFps) ||
        strstr(cmd_line, aLog_fps) )
        do_fps_log = 1;

    if( strstr(cmd_line, aDderrorlog) )
    {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 1;
    }
    if( strstr(cmd_line, aDdlog) )
    {
        Sys_DDLOG_Enable = 1;
        Sys_DDLOG_ErrorOn = 0;
    }
    if( strstr(cmd_line, aDdflushlog) )
        DDlogAutoFlush = 1;

    if( strstr(cmd_line, aDdnoflushlog) )
        DDlogAutoFlush = 0;

    if( strstr(cmd_line, aDdlocklog) )
        debug_log_lock = 1;

    if( strstr(cmd_line, aLograndom) )
        do_debug_random = 1;

    if( strstr(cmd_line, aFixedupdate) )
    {
        do_debug_timeGetTime = 1;
        do_fixed_update = 1;
    }
    if( strstr(cmd_line, aLogaction) )
        debugActions = 1;

    if( strstr(cmd_line, aRes_warn) )
        RESFILE_Set_Missing_Flag(1);
    v10 = _mbsstr((const unsigned __int8 *)cmd_line, aScenarios);
    if( v10 )
    {
        for( ; *v10 != 61; v10 = _mbsninc(v10, 1u) )
            ;
        v11 = _mbsninc(v10, 1u);
        for( this->prog_info->scenario_dir[0] = 0; !_ismbcspace(*v11); v11 = _mbsninc(v11, 1u) )
        {
            if( !*v11 )
                break;
            _mbsncat((unsigned __int8 *)this->prog_info->scenario_dir, v11, 1u);
        }
        _mbsncat((unsigned __int8 *)this->prog_info->scenario_dir, (const unsigned __int8 *)SubBlock, 1u);
    }
    v12 = _mbsstr((const unsigned __int8 *)cmd_line, aWorld);
    if( v12 )
    {
        for( ; *v12 != 61; v12 = _mbsninc(v12, 1u) )
            ;
        v13 = _mbsninc(v12, 1u);
        for( this->prog_info->world_db_file[0] = 0; !_ismbcspace(*v13); v13 = _mbsninc(v13, 1u) )
        {
            if( !*v13 )
                break;
            _mbsncat((unsigned __int8 *)this->prog_info->world_db_file, v13, 1u);
        }
    }
    v14 = _mbsstr((const unsigned __int8 *)cmd_line, aFixedupdate_1);
    if( v14 )
    {
        do_debug_timeGetTime = 1;
        for( do_fixed_update = 1; *v14 != 61; v14 = _mbsninc(v14, 1u) )
            ;
        v15 = _mbsninc(v14, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v15); v15 = _mbsninc(v15, 1u) )
        {
            if( !*v15 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v15, 1u);
        }
        fixed_update_time = atol(temp_str);
    }
    v16 = _mbsstr((const unsigned __int8 *)cmd_line, aAispeed);
    if( v16 )
    {
        do_debug_timeGetTime = 1;
        for( do_fixed_update = 1; *v16 != 61; v16 = _mbsninc(v16, 1u) )
            ;
        v17 = _mbsninc(v16, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v17); v17 = _mbsninc(v17, 1u) )
        {
            if( !*v17 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v17, 1u);
        }
        debug_timeGetTime_interval = atol(temp_str);
    }
    v18 = _mbsstr((const unsigned __int8 *)cmd_line, aRandomgame);
    if( v18 )
    {
        for( ; *v18 != 61; v18 = _mbsninc(v18, 1u) )
            ;
        v19 = _mbsninc(v18, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v19); v19 = _mbsninc(v19, 1u) )
        {
            if( !*v19 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v19, 1u);
        }
        this->random_game_seed = atol(temp_str);
    }
    v20 = _mbsstr((const unsigned __int8 *)cmd_line, aRandommap_1);
    if( v20 )
    {
        for( ; *v20 != 61; v20 = _mbsninc(v20, 1u) )
            ;
        v21 = _mbsninc(v20, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v21); v21 = _mbsninc(v21, 1u) )
        {
            if( !*v21 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v21, 1u);
        }
        this->random_map_seed = atol(temp_str);
    }
    v22 = _mbsstr((const unsigned __int8 *)cmd_line, aDrawlog);
    if( v22 )
    {
        for( ; *v22 != 61; v22 = _mbsninc(v22, 1u) )
            ;
        v23 = _mbsninc(v22, 1u);
        for( draw_log_name = 0; !_ismbcspace(*v23); v23 = _mbsninc(v23, 1u) )
        {
            if( !*v23 )
                break;
            _mbsncat((unsigned __int8 *)&draw_log_name, v23, 1u);
        }
    }
    if( strstr(cmd_line, aDrawlog_1) )
        do_draw_log = 1;

    if( strstr(cmd_line, aSafedrawlog) )
        safe_draw_log = 1;

    v24 = _mbsstr((const unsigned __int8 *)cmd_line, aData_1);
    if( v24 )
    {
        for( ; *v24 != 61; v24 = _mbsninc(v24, 1u) )
            ;
        v25 = _mbsninc(v24, 1u);
        for( this->prog_info->game_data_file[0] = 0; !_ismbcspace(*v25); v25 = _mbsninc(v25, 1u) )
        {
            if( !*v25 )
                break;
            _mbsncat((unsigned __int8 *)this->prog_info->game_data_file, v25, 1u);
        }
    }
    if( strstr(cmd_line, aCdaudio) ||
        strstr(cmd_line, aCdAudio) ||
        strstr(cmd_line, aCd_audio) )
    {
        this->prog_info->use_music = 1;
        this->prog_info->use_cd_audio = 1;
        this->prog_info->use_ima = 0;
        this->prog_info->use_midi = 0;
        this->prog_info->use_wave_music = 0;
    }
    if( strstr(cmd_line, aWindow) )
        this->prog_info->full_screen = 0;

    if( strstr(cmd_line, aFilefirst) ||
        strstr(cmd_line, aFileFirst) ||
        strstr(cmd_line, aFile_first) )
    {
        shape_file_first = 1;
        sound_file_first = 1;
    }
    if( strstr(cmd_line, aLogcomm) ||
        strstr(cmd_line, aLogComm) ||
        strstr(cmd_line, aLog_comm) )
    {
        this->log_comm = 1;

        if( L )
        {
            L->LogFile(1);
            L->LogTimestamp(1);
        }
    }
    if( strstr(cmd_line, aLogoutput) ||
        strstr(cmd_line, aLogOutput) ||
        strstr(cmd_line, aLog_output) )
    {
        log_output = 1;

        if( L )
            L->LogOutput(1);
    }
    if( strstr(cmd_line, aDeveloper) )
        this->setGameDeveloperMode(1);

    v26 = _mbsstr((const unsigned __int8 *)cmd_line, aSpeed1);
    if( v26 )
    {
        for( ; *v26 != 61; v26 = _mbsninc(v26, 1u) )
            ;
        v27 = _mbsninc(v26, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v27); v27 = _mbsninc(v27, 1u) )
        {
            if( !*v27 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v27, 1u);
        }
        speed_val1 = atol(temp_str);
    }
    v28 = _mbsstr((const unsigned __int8 *)cmd_line, aSpeed2);
    if( v28 )
    {
        for( ; *v28 != 61; v28 = _mbsninc(v28, 1u) )
            ;
        v29 = _mbsninc(v28, 1u);
        for( temp_str[0] = 0; !_ismbcspace(*v29); v29 = _mbsninc(v29, 1u) )
        {
            if( !*v29 )
                break;
            _mbsncat((unsigned __int8 *)temp_str, v29, 1u);
        }
        speed_val2 = atol(temp_str);
    }
    if( !this->prog_info->use_sound
        || strstr(cmd_line, aNomusic)
        || strstr(cmd_line, aNoMusic)
        || strstr(cmd_line, aNo_music) )
    {
        this->prog_info->use_music = 0;
    }
    if( this->prog_info->use_dir_draw == 1 &&
        this->prog_info->full_screen == 1 )
        this->custom_mouse = 1;

    if( strstr(cmd_line, aNormalmouse) || strstr(cmd_line, aNormalMouse) || strstr(cmd_line, aNormal_mouse) )
        this->custom_mouse = 0;

    return true;
}
// 57F9E4: using guessed type __int32 fixed_update_time;
// 57F9E8: using guessed type int debug_timeGetTime_interval;
// 57F9EC: using guessed type int useComputerPlayers;
// 57F9F0: using guessed type int allowAIToCheat;
// 57F9F4: using guessed type int numberPathingIterations;
// 57F9F8: using guessed type int pathingCapValue;
// 57F9FC: using guessed type int specificAIPlayerToLog;
// 57FA00: using guessed type int logDebugID;
// 57FA04: using guessed type int chatCheatCodes;
// 58454C: using guessed type int DDSys_CanColorFill;
// 584550: using guessed type int DDlogAutoFlush;
// 592A5C: using guessed type int safe_draw_log;
// 62C498: using guessed type int do_draw_log;
// 62C4C8: using guessed type int debugActions;
// 62C4D0: using guessed type int do_debug_random;
// 62C4E0: using guessed type int do_fixed_update;
// 62C4E4: using guessed type int do_debug_timeGetTime;
// 62C4F4: using guessed type int do_run_log;
// 62C50C: using guessed type int startLoggingAI;
// 62C510: using guessed type int useInfluencePlacement;
// 62C514: using guessed type int all_grassland_on;
// 62C518: using guessed type int useNewPathing;
// 62C51C: using guessed type int all_cp;
// 62C520: using guessed type int force_cd;
// 62C524: using guessed type int logStatusOn;
// 62C528: using guessed type int logUpdateChanges;
// 62C52C: using guessed type int do_fps_log;
// 62C584: using guessed type unsigned __int8 do_color_log;
// 62CF08: using guessed type int resend_adj1;
// 62CF0C: using guessed type int resend_adj2;
// 62E640: using guessed type int Sys_DDLOG_Enable;
// 62E644: using guessed type int Sys_DDLOG_ErrorOn;
// 62E648: using guessed type int debug_log_lock;
// 86BBFC: using guessed type unsigned __int8 shape_file_first;
// 86BC00: using guessed type unsigned __int8 sound_file_first;

int RGE_Base_Game::setup_class()
{
    WNDCLASSA cls;

    if( this->prog_info->prev_instance )
        return true;

    cls.hCursor = 0;
    cls.lpszMenuName = message_in;
    if( this->prog_info->menu_name[0] )
        cls.lpszMenuName = this->prog_info->menu_name;
    cls.hIcon = LoadIconA(this->prog_info->instance, this->prog_info->icon_name);
    cls.lpszClassName = (char *)this->prog_info;
    cls.hbrBackground = 0;
    cls.hInstance = this->prog_info->instance;
    cls.style = 11;
    cls.lpfnWndProc = rge_base_game_wnd_proc;
    cls.cbWndExtra = 0;
    cls.cbClsExtra = 0;

    return NULL != RegisterClassA(&cls);
}

int rge_base_game_wnd_proc(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    if( rge_base_game )
        return (*(int (__stdcall **)(RGE_Base_Game *, void *, unsigned int, unsigned int, int))&rge_base_game->vfptr->gap8[0])(
                             rge_base_game,
                             wnd,
                             msg,
                             wparam,
                             lparam);
    else
        return true;
}

bool RGE_Base_Game::setup_main_window()
{
    DWORD wnd_style;

    int screen_w,
        screen_h;

    HINSTANCE *inst;

    RECT win_rect,
         client_rect;

    metrics_x = GetSystemMetrics(SM_CXSCREEN);
    metrics_y = GetSystemMetrics(SM_CYSCREEN);

    if( this->prog_info->full_screen ||
        metrics_x == this->prog_info->main_wid &&
        metrics_y == this->prog_info->main_hgt )
    {
        inst = this->prog_info->instance;
        screen_h = metrics_y;
        screen_w = metrics_x;
        wnd_style = WS_SYSMENU|WS_POPUP|WS_CLIPCHILDREN;
        title = this->prog_info->prog_title;
    }
    else
    {
        inst = this->prog_info->instance;
        screen_h = this->prog_info->main_hgt;
        screen_w = this->prog_info->main_wid;
        wnd_style = WS_SYSMENU|WS_CAPTION|WS_GROUP|WS_CLIPCHILDREN;
        title = this->prog_info->prog_title;
    }
    this->prog_window = CreateWindowExA(
        0,
        this->prog_info->prog_name,
        title,
        wnd_style,
        0,
        0,
        screen_w,
        screen_h,
        0,
        0,
        inst,
        0);

    if( this->prog_window == NULL )
        return false;

    GetWindowRect(this->prog_window, &win_rect);
    GetClientRect(this->prog_window, &client_rect);

    if( client_rect.right != this->prog_info->main_wid ||
        client_rect.bottom != this->prog_info->main_hgt )
        SetWindowPos(
            this->prog_window,
            0,
            win_rect.left,
            win_rect.top,
            this->prog_info->main_wid + win_rect.right - win_rect.left - client_rect.right,
            win_rect.bottom + this->prog_info->main_hgt - win_rect.top - client_rect.bottom,
            0);

    if( this->prog_info->full_screen )
    {
        ShowWindow(this->prog_window, this->prog_info->show_wnd_flag);
        UpdateWindow(this->prog_window);
        SetFocus(this->prog_window);
    }
    AppWnd = this->prog_window;
    &panel_system->DisableIME();

    return true;
}

//----- (0041E920) --------------------------------------------------------
void RGE_Base_Game::setup_graphics_system()
{
    RGE_Base_Game *v1; // esi@1
    HDC v2; // edi@2
    int v3; // ebx@2
    RGE_Prog_Info *v4; // eax@4
    unsigned int v5; // ebp@4
    TDrawSystem *v6; // eax@4
    TDrawSystem *v7; // eax@5
    int v8; // eax@21
    TDrawArea *v9; // ecx@23
    char draw_mode; // [sp+10h] [bp-18h]@4
    char draw_type; // [sp+14h] [bp-14h]@4

    v1 = this;
    if( this->prog_info->use_dir_draw )
    {
        v2 = GetDC(0);
        v3 = GetDeviceCaps(v2, 12);
        ReleaseDC(0, v2);
        if( v3 < 8 )
        {
            this->error_code = 19;
            return;
        }
    }
    v4 = this->prog_info;
    draw_type = (v4->use_dir_draw != 0) + 1;
    draw_mode = (v4->full_screen != 0) + 1;
    v5 = v4->use_sys_mem != 0;
    v6 = (TDrawSystem *)operator new(0x47Cu);
    if( v6 )
        TDrawSystem::TDrawSystem(v6);
    else
        v7 = 0;
    this->draw_system = v7;
    if( v7 )
    {
        TDrawSystem::CheckAvailModes(v7, this->prog_info->full_screen);
        if( TDrawSystem::IsModeAvail(this->draw_system, this->prog_info->main_wid, 0, 8) )
            goto LABEL_21;
        if( this->prog_info->main_wid != 640 && TDrawSystem::IsModeAvail(this->draw_system, 640, 0, 8) )
        {
            this->prog_info->main_wid = 640;
            this->prog_info->main_hgt = 480;
            goto LABEL_21;
        }
        if( this->prog_info->main_wid != 800 && TDrawSystem::IsModeAvail(this->draw_system, 800, 0, 8) )
        {
            this->prog_info->main_wid = 800;
            this->prog_info->main_hgt = 600;
            goto LABEL_21;
        }
        if( this->prog_info->main_wid != 1024 && TDrawSystem::IsModeAvail(this->draw_system, 1024, 0, 8) )
        {
            this->prog_info->main_wid = 1024;
            this->prog_info->main_hgt = 768;
            goto LABEL_21;
        }
        if( this->prog_info->main_wid != 1280 && TDrawSystem::IsModeAvail(this->draw_system, 1024, 0, 8) )
        {
            this->prog_info->main_wid = 1280;
            this->prog_info->main_hgt = 1024;
LABEL_21:
            TDrawSystem::Init(
                this->draw_system,
                this->prog_info->instance,
                this->prog_window,
                this->prog_palette,
                draw_type,
                draw_mode,
                this->prog_info->main_wid,
                this->prog_info->main_hgt,
                v5);
            if( v8 )
            {
                TPanelSystem::release_palette(&panel_system, this->prog_palette);
                this->prog_palette = TPanelSystem::get_palette(&panel_system, this->prog_info->pal_file, 50500);
                v9 = this->draw_system->DrawArea;
                this->draw_area = v9;
                TDrawArea::Clear(v9, 0, 0);
                TDrawSystem::Paint(this->draw_system, 0);
            }
            return;
        }
    }
}

bool RGE_Base_Game::setup_palette()
{
    return NULL != this->prog_palette = &panel_system->get_palette(this->prog_info->pal_file, 50500);
}

void RGE_Base_Game::setup_mouse()
{
    RGE_Base_Game *v1; // esi@1
    char *v2; // eax@1
    int v3; // edi@3
    TMousePointer *v4; // eax@4
    TMousePointer *v5; // eax@5
    int custom_type; // [sp+8h] [bp-10h]@0

    v1 = this;
    v2 = TRegistry::RegGetInt(this->registry, 0, aCustomMouse_1);
    if( v2 == (char *)-1 )
    {
        TRegistry::RegSetInt(this->registry, 0, aCustomMouse_1, 0);
LABEL_3:
        v3 = 0;
        goto LABEL_4;
    }
    if( v2 == (char *)1 )
    {
        v3 = 1;
    }
    else
    {
        if( v2 != (char *)2 )
            goto LABEL_3;
        v3 = custom_type;
        this->custom_mouse = 0;
    }
LABEL_4:
    v4 = (TMousePointer *)operator new(0x254u);
    if( v4 )
        TMousePointer::TMousePointer(v4, v3);
    else
        v5 = 0;
    this->mouse_pointer = v5;
    if( v5 )
    {
        if( TMousePointer::setup(v5, this->custom_mouse, this->draw_area, this->prog_info->cursor_file, 51000, 10) )
            RGE_Base_Game::mouse_off(v1);
    }
}

bool RGE_Base_Game::setup_chat()
{
    return NULL != chat = new TChat(this->prog_window);
}

//----- (0041ED70) --------------------------------------------------------
BOOL RGE_Base_Game::setup_registry()
{
    RGE_Base_Game *v1; // esi@1
    TRegistry *v2; // eax@1
    TRegistry *v3; // eax@2

    v1 = this;
    v2 = (TRegistry *)operator new(0x110u);
    if( v2 )
        TRegistry::TRegistry(v2, this->prog_info->registry_key);
    else
        v3 = 0;
    this->registry = v3;
    return v3 != 0;
}

//----- (0041EDE0) --------------------------------------------------------
void RGE_Base_Game::setup_debugging_log()
{
    RGE_Base_Game *v1; // esi@1
    TDebuggingLog *v2; // eax@1
    TDebuggingLog *v3; // eax@2

    v1 = this;
    v2 = (TDebuggingLog *)operator new(0x7B0u);
    if( v2 )
        TDebuggingLog::TDebuggingLog(v2);
    else
        v3 = 0;
    this->debugLog = v3;
    if( v3 )
    {
        TDebuggingLog::LogFile(v3, this->log_comm);
        TDebuggingLog::LogOutput(this->debugLog, log_output);
        TDebuggingLog::LogTimestamp(this->debugLog, 1);
    }
}

//----- (0041EE90) --------------------------------------------------------
void RGE_Base_Game::setup_comm()
{
    RGE_Base_Game *v1; // esi@1
    TCommunications_Handler *v2; // eax@1
    RGE_Prog_Info *v3; // edx@2
    _GUID v4; // ST0C_16@2
    TCommunications_Handler *v5; // eax@2
    RGE_Game_World *v6; // ecx@5

    v1 = this;
    v2 = (TCommunications_Handler *)operator new(0x1774u);
    if( v2 )
    {
        v3 = this->prog_info;
        *(_QWORD *)&v4.x = *(_QWORD *)&v3->game_guid.x;
        *(_QWORD *)&v4.c[0] = *(_QWORD *)&v3->game_guid.c[0];
        TCommunications_Handler::TCommunications_Handler(v2, this->prog_window, v3->max_players, chat, v4);
    }
    else
    {
        v5 = 0;
    }
    this->comm_handler = v5;
    if( v5 )
    {
        TCommunications_Handler::StopIfSyncFail(v5, this->comm_syncstop);
        TCommunications_Handler::ShowSyncChatMsgs(this->comm_handler, this->comm_syncmsg);
        TCommunications_Handler::SetStepMode(this->comm_handler, this->comm_stepmode);
        TCommunications_Handler::SetSpeedControl(this->comm_handler, this->comm_speed);
        TCommunications_Handler::DropPacketsIntentionally(this->comm_handler, this->comm_droppackets);
        comm = this->comm_handler;
        v6 = this->world;
        if( v6 )
            RGE_Game_World::reset_communications(v6, this->comm_handler);
        if( speed_val1 )
            TCommunications_Handler::SetSpeedV1(this->comm_handler, speed_val1);
        if( speed_val2 )
            TCommunications_Handler::SetSpeedV1(this->comm_handler, speed_val2);
    }
}

int RGE_Base_Game::reset_comm()
{
    if( this->comm_handler )
    {
        delete this->comm_handler;

        comm = 0;
    }
    return this->setup_comm();
}

//----- (0041F030) --------------------------------------------------------
int RGE_Base_Game::setup_sound_system()
{
    RGE_Base_Game *v1; // esi@1
    int v2; // edi@1
    TSound_Driver *v3; // eax@2
    TSound_Driver *v4; // eax@3
    TSound_Driver *v5; // ebx@7
    char *v6; // eax@10

    v1 = this;
    v2 = 0;
    if( !this->prog_info->use_sound )
    {
LABEL_13:
        v1->vfptr->setup_music_system(v1);
        return 1;
    }
    v3 = (TSound_Driver *)operator new(0x69Cu);
    if( v3 )
        TSound_Driver::TSound_Driver(v3, v1->prog_window, v1->prog_info->sounds_dir);
    else
        v4 = 0;
    v1->sound_system = v4;
    if( !v4 || TSound_Driver::driver_active(v4) )
    {
        sound_driver = v1->sound_system;
        v6 = TRegistry::RegGetInt(v1->registry, 1, aSoundVolume);
        if( v6 != (char *)-1 )
            v2 = -(signed int)v6;
        TSound_Driver::set_volume(v1->sound_system, v2, 1);
        goto LABEL_13;
    }
    v5 = v1->sound_system;
    if( v5 )
    {
        TSound_Driver::~TSound_Driver(v1->sound_system);
        operator delete(v5);
    }
    v1->sound_system = 0;
    return 1;
}

//----- (0041F110) --------------------------------------------------------
int RGE_Base_Game::setup_music_system()
{
    RGE_Base_Game *v1; // esi@1
    int v2; // edi@2
    char *v3; // eax@2
    TMusic_System *v4; // edi@5
    RGE_Prog_Info *v5; // eax@8
    char v6; // bl@9
    TMusic_System *v7; // eax@15
    TMusic_System *v8; // eax@16
    TMusic_System *v9; // esi@25
    char music_path[260]; // [sp+14h] [bp-110h]@15
    int v12; // [sp+120h] [bp-4h]@15

    v1 = this;
    if( this->prog_info->use_music )
    {
        v2 = -5000;
        v3 = TRegistry::RegGetInt(this->registry, 1, aMusicVolume);
        if( v3 != (char *)-1 )
            v2 = -(signed int)v3;
        if( v2 > -9900 )
        {
            if( !this->music_system )
            {
                v5 = this->prog_info;
                if( v5->use_cd_audio )
                {
                    v6 = 1;
                }
                else if( v5->use_midi )
                {
                    v6 = 2;
                }
                else if( v5->use_ima )
                {
                    v6 = 4;
                }
                else
                {
                    v6 = v5->use_wave_music != 0 ? 3 : 1;
                }
                sprintf(music_path, aSS_4, this->work_dir, v5->sounds_dir);
                v7 = (TMusic_System *)operator new(0x3F8u);
                v12 = 0;
                if( v7 )
                    TMusic_System::TMusic_System(v7, v6, this->prog_info->instance, this->prog_window, this->sound_system, music_path);
                else
                    v8 = 0;
                v12 = -1;
                this->music_system = v8;
                if( v8
                    && v6 == 1
                    && !this->prog_info->use_cd_audio
                    && (!v8->device_open || v8->track_count < 2)
                    && !TMusic_System::set_music_type(v8, 2) )
                {
                    TMusic_System::set_music_type(this->music_system, 3);
                }
                v9 = this->music_system;
                if( v9 )
                    TMusic_System::set_volume(v9, v2, 1);
            }
        }
        else
        {
            this->prog_info->use_music = 0;

            if( this->music_system )
            {
                delete this->music_system;
            }
        }
    }
    return 1;
}

//----- (0041F2D0) --------------------------------------------------------
TShape **RGE_Base_Game::setup_shapes()
{
    RGE_Base_Game *v1; // esi@1
    TShape **result; // eax@1
    signed int i; // eax@2
    TShape *v4; // eax@4
    TShape *v5; // eax@5
    TShape *v6; // eax@7
    int v7; // eax@8
    TShape *v8; // eax@10
    int v9; // eax@11

    v1 = this;
    this->shape_num = 3;
    result = (TShape **)calloc(3u, 4u);
    this->shapes = result;
    if( result )
    {
        for( i = 0; i < this->shape_num; this->shapes[++i - 1] = 0 )
            ;
        v4 = (TShape *)operator new(0x20u);
        if( v4 )
            TShape::TShape(v4, filename, 50403);
        else
            v5 = 0;
        *this->shapes = v5;
        v6 = (TShape *)operator new(0x20u);
        if( v6 )
            TShape::TShape(v6, aWaypoint_shp, 50404);
        else
            v7 = 0;
        *((_DWORD *)this->shapes + 1) = v7;
        v8 = (TShape *)operator new(0x20u);
        if( v8 )
            TShape::TShape(v8, aMoveto_shp, 50405);
        else
            v9 = 0;
        *((_DWORD *)this->shapes + 2) = v9;
        result = (TShape **)1;
    }
    return result;
}

//----- (0041F400) --------------------------------------------------------
TDigital **RGE_Base_Game::setup_sounds()
{
    RGE_Base_Game *v1; // esi@1
    TDigital **result; // eax@1
    signed int i; // eax@2
    TDigital *v4; // eax@4
    TDigital *v5; // eax@5
    TDigital *v6; // eax@7
    int v7; // eax@8
    TDigital *v8; // eax@10
    int v9; // eax@11
    signed int v10; // edi@13
    TDigital *v11; // ecx@14

    v1 = this;
    this->sound_num = 3;
    result = (TDigital **)calloc(3u, 4u);
    this->sounds = result;
    if( result )
    {
        for( i = 0; i < this->sound_num; this->sounds[++i - 1] = 0 )
            ;
        v4 = (TDigital *)operator new(0x3Cu);
        if( v4 )
            TDigital::TDigital(v4, this->sound_system, file_name, 50300);
        else
            v5 = 0;
        *this->sounds = v5;
        v6 = (TDigital *)operator new(0x3Cu);
        if( v6 )
            TDigital::TDigital(v6, this->sound_system, aButton2_wav, 50301);
        else
            v7 = 0;
        *((_DWORD *)this->sounds + 1) = v7;
        v8 = (TDigital *)operator new(0x3Cu);
        if( v8 )
            TDigital::TDigital(v8, this->sound_system, aChatrcvd_wav, 50302);
        else
            v9 = 0;
        v10 = 0;
        for( *((_DWORD *)this->sounds + 2) = v9; v10 < this->sound_num; ++v10 )
        {
            v11 = this->sounds[v10];
            if( v11 )
                TDigital::load(v11, 0, -1);
        }
        result = (TDigital **)1;
    }
    return result;
}

//----- (0041F560) --------------------------------------------------------
RGE_Font *RGE_Base_Game::setup_fonts()
{
    RGE_Base_Game *v1; // edi@1
    RGE_Font *result; // eax@1
    RGE_Font *v3; // ebx@2
    int v4; // ebp@3
    void *v5; // esi@5
    HGDIOBJ v6; // ebp@16
    int v7; // eax@16
    int i; // [sp+10h] [bp-40h]@3
    int v9; // [sp+14h] [bp-3Ch]@4
    tagTEXTMETRICA tm; // [sp+18h] [bp-38h]@16

    v1 = this;
    this->font_num = 12;
    result = (RGE_Font *)calloc(0xCu, 0xCu);
    this->fonts = result;
    if( result )
    {
        result = (RGE_Font *)TDrawArea::GetDc(this->draw_area, caller_name);
        v3 = result;
        if( result )
        {
            v4 = 0;
            i = 0;
            if( this->font_num > 0 )
            {
                do
                {
                    v9 = (signed short)v4;
                    switch( (signed short)v4 )
                    {
                        case 0:
                            v5 = RGE_Base_Game::make_font(v1, v3, 110, 0);
                            break;
                        case 1:
                            v5 = RGE_Base_Game::make_font(v1, v3, 113, 0);
                            break;
                        case 4:
                            v5 = RGE_Base_Game::make_font(v1, v3, 116, 0);
                            break;
                        case 6:
                            v5 = RGE_Base_Game::make_font(v1, v3, 131, 0);
                            break;
                        case 7:
                            v5 = RGE_Base_Game::make_font(v1, v3, 119, 0);
                            break;
                        case 8:
                            v5 = RGE_Base_Game::make_font(v1, v3, 128, 1);
                            break;
                        case 9:
                            v5 = RGE_Base_Game::make_font(v1, v3, 122, 0);
                            break;
                        case 10:
                            v5 = RGE_Base_Game::make_font(v1, v3, 125, 0);
                            break;
                        case 11:
                            v5 = RGE_Base_Game::make_font(v1, v3, 128, 0);
                            break;
                        default:
                            v5 = 0;
                            break;
                    }
                    if( v5 )
                    {
                        v6 = SelectObject(v3, v5);
                        GetTextMetricsA(v3, &tm);
                        v7 = v9;
                        this->fonts[v7].font = v5;
                        this->fonts[v7].font_wid = tm.tmAveCharWidth;
                        this->fonts[v7].font_hgt = tm.tmExternalLeading + tm.tmHeight;
                        SelectObject(v3, v6);
                        v4 = i;
                    }
                    i = ++v4;
                }
                while( (signed short)v4 < this->font_num );
            }
            TDrawArea::ReleaseDc(this->draw_area, caller_name);
            result = (RGE_Font *)1;
        }
    }
    return result;
}

void RGE_Base_Game::setup_blank_screen()
{
    TScreenPanel *screen_panel;

    if( screen_panel = new TScreenPanel(name) &&
        screen_panel->setup(this->draw_area, 0, -1, 0) )
    {
        &panel_system, name->setCurrentPanel(0);

        this->set_render_all();

        SendMessageA(this->prog_window, 0xFu, 0, 0);
    }
}

void RGE_Base_Game::setup_timings()
{
    this->timings[1].include_in_total = 1;
    this->timings[2].include_in_total = 1;
    this->timings[3].include_in_total = 1;
    this->timings[10].include_in_total = 1;
    this->timings[13].include_in_total = 1;
    this->timings[0].is_summary = 1;
    this->timings[4].is_summary = 1;
}

void RGE_Base_Game::stop_sound_system()
{
    RGE_Base_Game *v1; // esi@1
    RGE_Game_World *v2; // eax@3
    signed int i; // edi@4
    signed int j; // ebx@7
    TDigital **v5; // edx@8
    TDigital *v6; // edi@8
    TSound_Driver *v7; // ecx@12
    int v8; // eax@13
    TSound_Driver *v9; // edi@13

    v1 = this;
    if( chat )
        TChat::StopSoundSystem(chat);
    TPanelSystem::stop_sound_system(&panel_system);
    v2 = this->world;
    if( v2 )
    {
        for( i = 0; i < v2->sound_num; ++i )
        {
            RGE_Sound::restart_sound(v2->sounds[i], 0);
            v2 = this->world;
        }
    }
    if( this->sounds )
    {
        for( j = 0; j < this->sound_num; ++j )
        {
            v5 = this->sounds;
            v6 = v5[j];
            if( v6 )
            {
                TDigital::~TDigital(v5[j]);
                operator delete(v6);
            }
        }
        free(this->sounds);
        this->sounds = 0;
    }
    this->vfptr->shutdown_music_system(v1);
    v7 = this->sound_system;
    if( v7 )
    {
        v8 = TSound_Driver::get_volume(v7);
        TRegistry::RegSetInt(this->registry, 1, aSoundVolume, -v8);
        v9 = this->sound_system;
        if( v9 )
        {
            TSound_Driver::~TSound_Driver(this->sound_system);
            operator delete(v9);
        }
        this->sound_system = 0;
        sound_driver = 0;
    }
}

int RGE_Base_Game::restart_sound_system()
{
    RGE_Base_Game *v1; // edi@1
    RGE_Base_GameVtbl *v2; // ebx@2
    int result; // eax@2
    RGE_Game_World *v4; // eax@4
    signed int i; // esi@5

    v1 = this;
    if( this->sound_system )
        return 1;
    v2 = this->vfptr;
    result = ((int (*)(void))this->vfptr->setup_sound_system)();
    if( result )
    {
        result = v2->setup_sounds(v1);
        if( result )
        {
            v4 = this->world;
            if( v4 )
            {
                for( i = 0; i < v4->sound_num; ++i )
                {
                    RGE_Sound::restart_sound(v4->sounds[i], this->sound_system);
                    v4 = this->world;
                }
            }
            TPanelSystem::restart_sound_system(&panel_system);
            if( chat )
                TChat::RestartSoundSystem(chat, this->sound_system);
            v2->restart_music_system(v1);
            return 1;
        }
    }
    return result;
}

void RGE_Base_Game::stop_music_system()
{
    if( this->music_system )
    {
        this->music_system->get_play_info(
            &this->save_music_type,
            &this->save_music_track_from,
            &this->save_music_track_to,
            &this->save_music_cur_track,
            this->save_music_file,
            &this->save_music_loop,
            &this->save_music_pos);

        this->music_system->stop_track();
    }
}

int RGE_Base_Game::restart_music_system()
{
    RGE_Base_Game *v1; // eax@1
    TMusic_System *v2; // ecx@1
    int result; // eax@2
    int v4; // edx@3
    int v5; // esi@7

    v1 = this;
    v2 = this->music_system;
    if( !v2 )
        return 1;
    v4 = this->save_music_track_from;
    if( !v4 )
        goto LABEL_14;
    if( v4 == this->save_music_track_to )
    {
        TMusic_System::play_track(v2, v4, this->save_music_loop, this->save_music_pos);
        return 1;
    }
    if( v4 && (v5 = this->save_music_track_to) != 0 )
    {
        TMusic_System::play_tracks(v2, v4, v5, this->save_music_loop, this->save_music_cur_track, this->save_music_pos);
        result = 1;
    }
    else
    {
LABEL_14:
        if( this->save_music_file[0] )
            TMusic_System::play_file(v2, this->save_music_file, this->save_music_loop, this->save_music_pos);
        result = 1;
    }
    return result;
}

void RGE_Base_Game::shutdown_music_system()
{
    if( this->music_system )
    {
        this->stop_music_system)();

        this->registry->RegSetInt(1, aMusicVolume, -this->music_system->volume);

        if( this->music_system )
            delete this->music_system;
    }
}

void *RGE_Base_Game::make_font(void *dc, int string_id, int strike_out)
{
    RGE_Base_Game *v4; // esi@1
    void (__stdcall *v5)(int, char *, signed int); // edi@1
    void *result; // eax@2
    int v7; // ebp@3
    bool v8; // zf@4
    int v9; // eax@4
    char style[10]; // [sp+24h] [bp-118h]@3
    char point_size_str[10]; // [sp+30h] [bp-10Ch]@3
    char face_name[256]; // [sp+3Ch] [bp-100h]@1

    v4 = this;
    v5 = *(void (__stdcall **)(int, char *, signed int))&this->vfptr->gap8[24];
    v5(string_id, face_name, 256);
    if( face_name[0] )
    {
        ((void (__thiscall *)(RGE_Base_Game *, int, char *, signed int))v5)(v4, string_id + 1, point_size_str, 10);
        v7 = atoi(point_size_str);
        ((void (__thiscall *)(RGE_Base_Game *, int, char *, signed int))v5)(v4, string_id + 2, style, 10);
        if( strstr(style, aB_0) || (v8 = strstr(style, aB) == 0, v9 = 400, !v8) )
            v9 = 700;
        result = RGE_Base_Game::make_font(v4, dc, face_name, v7, v9, strike_out);
    }
    else
    {
        result = 0;
    }
    return result;
}

void *RGE_Base_Game::make_font(void *dc, char *face_name, int point_size, int wgt, int strike_out)
{
    char v6; // bl@1
    tagLOGFONTA logfont; // [sp+Ch] [bp-13Ch]@1
    char str[256]; // [sp+48h] [bp-100h]@1

    (*(void (__stdcall **)(signed int, char *, signed int))&this->vfptr->gap8[24])(101, str, 256);
    v6 = atoi(str);
    memset(&logfont, 0, sizeof(logfont));
    logfont.lfHeight = -MulDiv(point_size, 96, 72);
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfItalic = 0;
    logfont.lfUnderline = 0;
    logfont.lfOutPrecision = 0;
    logfont.lfClipPrecision = 0;
    logfont.lfStrikeOut = strike_out;
    logfont.lfQuality = 2;
    logfont.lfPitchAndFamily = 2;
    logfont.lfWeight = wgt;
    logfont.lfCharSet = v6;
    strcpy(logfont.lfFaceName, face_name);
    return CreateFontIndirectA(&logfont);
}

char RGE_Base_Game::check_for_cd(int num_players)
{
    RGE_Base_Game *v2; // ebx@1
    char *v3; // eax@2
    int v4; // ebp@4
    int v5; // esi@4
    int v6; // edi@5
    char *v7; // esi@12
    unsigned int vol_ser_num; // [sp+10h] [bp-20Ch]@15
    unsigned int file_sys_flags; // [sp+14h] [bp-208h]@15
    unsigned int max_comp_len; // [sp+18h] [bp-204h]@15
    char vol_name[256]; // [sp+1Ch] [bp-200h]@15
    char file_sys_name[256]; // [sp+11Ch] [bp-100h]@15

    v2 = this;
    if( this->prog_info->verify_cd )
    {
        if( num_players <= 0 )
        {
            if( force_cd )
            {
                LOBYTE(v3) = 1;
            }
            else
            {
                v3 = TRegistry::RegGetAscii(this->registry, 0, aCdpath);
                v7 = v3;
                if( v3 )
                {
                    if( GetDriveTypeA(v3) == 5 )
                    {
                        v3 = (char *)GetVolumeInformationA(
                                                     v7,
                                                     vol_name,
                                                     0x100u,
                                                     &vol_ser_num,
                                                     &max_comp_len,
                                                     &file_sys_flags,
                                                     file_sys_name,
                                                     0x100u);
                        if( v3 )
                            v3 = (char *)(_strcmpi(vol_name, v2->prog_info->vol_name) == 0);
                    }
                    else
                    {
                        LOBYTE(v3) = 0;
                    }
                }
            }
        }
        else
        {
            v4 = 0;
            v5 = 0;
            do
            {
                v6 = v5 + 1;
                if( TCommunications_Handler::GetPlayerHumanity(v2->comm_handler, v5 + 1) == 2
                    && RGE_Base_Game::playerHasCD(v2, v5) )
                {
                    ++v4;
                }
                ++v5;
            }
            while( v6 < 9 );
            LOBYTE(v3) = num_players <= v4 * v2->prog_info->max_players_per_cd;
        }
    }
    else
    {
        LOBYTE(v3) = 1;
    }
    return (unsigned int)v3;
}

bool RGE_Base_Game::check_expiration()
{
    RGE_Prog_Info *v1; // eax@1
    int v2; // esi@1
    int cur_date; // [sp+8h] [bp-28h]@1
    tm kill_def; // [sp+Ch] [bp-24h]@1

    memset(&kill_def, 0, sizeof(kill_def));
    v1 = this->prog_info;
    kill_def.tm_mon = v1->expire_month - 1;
    kill_def.tm_mday = v1->expire_day;
    kill_def.tm_year = v1->expire_year;
    v2 = mktime(&kill_def);
    time(&cur_date);
    return cur_date <= v2;
}

int RGE_Base_Game::check_multi_copies()
{
    RGE_Base_Game *v1; // esi@1
    HWND v2; // edi@2
    void *v3; // esi@4
    HWND v5; // eax@8
    void *v6; // esi@12

    v1 = this;
    this->prog_mutex = CreateMutexA(0, 1, this->prog_info->prog_name);
    if( GetLastError() != 183 )
    {
        v6 = v1->prog_mutex;
        if( v6 )
            ReleaseMutex(v6);
        return 1;
    }
    v2 = FindWindowA(v1->prog_info->prog_name, v1->prog_info->prog_title);
    if( v2 )
    {
        if( RGE_Base_Game::check_prog_argument(v1, aLobby) )
        {
            SendMessageA(v2, 0x10u, 0, 0);
            v3 = v1->prog_mutex;
            if( v3 )
            {
                ReleaseMutex(v3);
                return 1;
            }
            return 1;
        }
        if( IsIconic(v2) )
            ShowWindow(v2, 1);
        SetForegroundWindow(v2);
        v5 = GetLastActivePopup(v2);
        BringWindowToTop(v5);
    }
    if( v1->prog_mutex )
    {
        ReleaseMutex(v1->prog_mutex);
        CloseHandle(v1->prog_mutex);
        v1->prog_mutex = 0;
    }
    return 0;
}

int RGE_Base_Game::check_paint()
{
    RGE_Base_Game *v1; // esi@1
    int result; // eax@2
    int v3; // eax@9
    int v4; // eax@10
    tagRECT update_rect; // [sp+8h] [bp-10h]@6

    v1 = this;
    if( !this->prog_ready )
    {
        RGE_Base_Game::clear_window(this);
        ValidateRect(v1->prog_window, 0);
        return 0;
    }
    if( IsIconic(this->prog_window) )
    {
        ValidateRect(v1->prog_window, 0);
        return 0;
    }
    if( v1->prog_active )
    {
        v3 = (unsigned __int8)TDrawSystem::CheckSurfaces(v1->draw_system) - 1;
        if( v3 )
        {
            v4 = v3 - 1;
            if( v4 )
            {
                if( v4 == 1 )
                {
                    ValidateRect(v1->prog_window, 0);
                    DestroyWindow(v1->prog_window);
                    return 0;
                }
            }
            else
            {
                TDrawSystem::ClearRestored(v1->draw_system);
                RGE_Base_Game::set_render_all(v1);
            }
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        if( GetUpdateRect(v1->prog_window, &update_rect, 0) )
            TDrawSystem::Paint(v1->draw_system, &update_rect);
        ValidateRect(v1->prog_window, 0);
        result = 0;
    }
    return result;
}

void RGE_Base_Game::clear_window()
{
    RGE_Base_Game *v1; // edi@1
    void *v2; // eax@1
    HDC v3; // esi@2
    HGDIOBJ v4; // eax@2
    tagRECT rect; // [sp+4h] [bp-10h]@2

    v1 = this;
    v2 = this->prog_window;
    if( v2 )
    {
        v3 = GetDC(v2);
        GetClientRect(v1->prog_window, &rect);
        v4 = GetStockObject(4);
        FillRect(v3, &rect, v4);
        ReleaseDC(v1->prog_window, v3);
    }
}

void RGE_Base_Game::create_world()
{
    return new RGE_Game_World();
}

void RGE_Base_Game::close()
{
    SendMessageA(this->prog_window, 0x10u, 0, 0);
}

bool RGE_Base_Game::create_dialog(TPanel **dialog_ptr, TPanel *new_dialog)
{
    *dialog_ptr = 0;

    if( new_dialog == NULL )
    {
        return false;
    }
    else if( new_dialog->error_code )
    {
        delete new_dialog;
        return false;
    }
    else
    {
        *dialog_ptr = new_dialog;
        return true;
    }
}

void RGE_Base_Game::delete_dialog(TPanel **dialog_ptr)
{
    if( *dialog_ptr )
    {
        delete *dialog_ptr;
        *dialog_ptr = 0;
    }
}

void RGE_Base_Game::set_game_mode(int new_mode, int new_sub_mode)
{
    this->game_mode = new_mode;
    this->sub_game_mode = new_sub_mode;
}

void RGE_Base_Game::set_player(short new_player_id)
{
    RGE_Game_World *v2; // eax@1

    v2 = this->world;
    if( v2 )
    {
        if( new_player_id < v2->player_num )
        {
            v2->curr_player = new_player_id;
            RGE_Map::clear_map_view_info(this->world->map);
        }
    }
}

//----- (00420180) --------------------------------------------------------
int RGE_Base_Game::get_paused()
{
    int result; // eax@2

    if( this->prog_mode == 7 )
        result = 0;
    else
        result = TCommunications_Handler::IsPaused(this->comm_handler);
    return result;
}

//----- (004201A0) --------------------------------------------------------
RGE_Font *RGE_Base_Game::get_font(int font_id)
{
    RGE_Font *v2; // ecx@1
    RGE_Font *result; // eax@2

    v2 = this->fonts;
    if( v2 )
        result = &v2[font_id];
    else
        result = 0;
    return result;
}

//----- (004201C0) --------------------------------------------------------
TShape **RGE_Base_Game::get_shape(int shape_id)
{
    TShape **result; // eax@1

    result = this->shapes;
    if( result )
        result = (TShape **)result[shape_id];
    return result;
}

//----- (004201E0) --------------------------------------------------------
TDigital **RGE_Base_Game::get_sound(int sound_id)
{
    TDigital **result; // eax@1

    result = this->sounds;
    if( result )
        result = (TDigital **)result[sound_id];
    return result;
}

//----- (00420200) --------------------------------------------------------
void RGE_Base_Game::request_pause()
{
    RGE_Base_Game *v1; // esi@1
    RGE_Game_World *v2; // esi@1

    v1 = this;
    TCommunications_Handler::TogglePauseGame(this->comm_handler);
    v2 = v1->world;
    if( v2 )
        v2->temp_pause = 1;
}

//----- (00420220) --------------------------------------------------------
void RGE_Base_Game::set_paused(int paused_in, int non_user_pause_in)
{
    RGE_Base_Game *v3; // esi@1
    int v4; // eax@1

    v3 = this;
    v4 = RGE_Base_Game::get_paused(this);
    v3->save_paused = v4;
    if( paused_in != v4 )
    {
        if( paused_in )
        {
            v3->non_user_pause = non_user_pause_in;
            RGE_Base_Game::request_pause(v3);
        }
        else
        {
            v3->non_user_pause = 0;
            RGE_Base_Game::request_pause(v3);
        }
    }
}

//----- (00420270) --------------------------------------------------------
void __stdcall RGE_Base_Game::get_mouse_info(unsigned int wparam, int lparam, tagPOINT *point, int *left_btn, int *right_btn, int *ctrl_key, int *shift_key)
{
    signed int v8; // ecx@1

    v8 = (unsigned int)lparam >> 16;
    point->x = (unsigned short)lparam;
    point->y = (unsigned int)lparam >> 16;
    if( (signed int)(unsigned short)lparam > 60000 )
        point->x = (unsigned short)lparam - 0x10000;
    if( v8 > 60000 )
        point->y = v8 - 0x10000;
    *left_btn = wparam & 1;
    *right_btn = wparam & 2;
    *ctrl_key = wparam & 8;
    *shift_key = wparam & 4;
}

//----- (004202E0) --------------------------------------------------------
void RGE_Base_Game::get_mouse_pos(tagPOINT *point)
{
    RGE_Base_Game *v2; // edi@1
    int v3; // eax@4

    v2 = this;
    GetCursorPos(point);
    if( !v2->prog_info->full_screen )
    {
        ScreenToClient(v2->prog_window, point);
        if( point->x > 60000 )
            point->x -= 0x10000;
        v3 = point->y;
        if( v3 > 60000 )
            point->y = v3 - 0x10000;
    }
}

//----- (00420330) --------------------------------------------------------
RGE_Game_World *RGE_Base_Game::get_player()
{
    RGE_Game_World *result; // eax@1
    short v2; // cx@2
    short v3; // dx@4

    result = this->world;
    if( result )
    {
        v2 = result->player_num;
        if( v2 )
        {
            v3 = result->curr_player;
            if( v3 < v2 )
                result = (RGE_Game_World *)result->players[v3];
            else
                result = 0;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (00420360) --------------------------------------------------------
void RGE_Base_Game::draw_window()
{
    UpdateWindow(this->prog_window);
}

//----- (00420370) --------------------------------------------------------
void RGE_Base_Game::mouse_on()
{
    RGE_Base_Game *v1; // esi@1

    v1 = this;
    if( !this->is_mouse_on )
    {
        if( !this->custom_mouse || this->windows_mouse )
        {
            SetCursor(this->mouse_cursor);
            SetClassLongA(v1->prog_window, -12, (LONG)v1->mouse_cursor);
            v1->is_mouse_on = 1;
        }
        else
        {
            TMousePointer::on(this->mouse_pointer);
            v1->is_mouse_on = 1;
        }
    }
}

//----- (004203E0) --------------------------------------------------------
void RGE_Base_Game::mouse_off()
{
    RGE_Base_Game *v1; // esi@1

    v1 = this;
    if( this->is_mouse_on )
    {
        if( !this->custom_mouse || this->windows_mouse )
        {
            SetCursor(0);
            SetClassLongA(v1->prog_window, -12, 0);
            v1->is_mouse_on = 0;
        }
        else
        {
            TMousePointer::off(this->mouse_pointer);
            v1->is_mouse_on = 0;
        }
    }
}

//----- (00420440) --------------------------------------------------------
void RGE_Base_Game::set_windows_mouse(int val)
{
    RGE_Base_Game *v2; // esi@1
    int v3; // eax@1
    TMousePointer *v4; // ecx@6

    v2 = this;
    v3 = this->custom_mouse;
    if( v3 )
        this->windows_mouse = val;
    else
        this->windows_mouse = 1;
    if( !v3 || this->windows_mouse )
    {
        TMousePointer::off(this->mouse_pointer);
        if( v2->is_mouse_on )
        {
            SetCursor(v2->mouse_cursor);
            SetClassLongA(v2->prog_window, -12, (LONG)v2->mouse_cursor);
        }
        else
        {
            SetCursor(0);
            SetClassLongA(v2->prog_window, -12, 0);
        }
    }
    else
    {
        SetCursor(0);
        SetClassLongA(v2->prog_window, -12, 0);
        v4 = v2->mouse_pointer;
        if( v2->is_mouse_on )
            TMousePointer::on(v4);
        else
            TMousePointer::off(v4);
    }
}

//----- (00420500) --------------------------------------------------------
void RGE_Base_Game::set_mouse_cursor(void *val)
{
    RGE_Base_Game *v2; // esi@1

    v2 = this;
    this->mouse_cursor = val;
    if( val )
        last_mouse_cursor = val;
    if( this->is_mouse_on && (!this->custom_mouse || this->windows_mouse) )
    {
        SetCursor(this->mouse_cursor);
        SetClassLongA(v2->prog_window, -12, (LONG)v2->mouse_cursor);
    }
}
// 62C54C: using guessed type void *last_mouse_cursor;

//----- (00420560) --------------------------------------------------------
void RGE_Base_Game::set_mouse_facet(int facet)
{
    TMousePointer::set_facet(this->mouse_pointer, facet);
}

//----- (00420580) --------------------------------------------------------
int __stdcall enum_wnd_proc(void *hwnd, int lParam)
{
    char wnd_title[256]; // [sp+0h] [bp-100h]@1

    GetWindowTextA(hwnd, wnd_title, 255);
    return 1;
}

//----- (004205B0) --------------------------------------------------------
int __stdcall enum_child_proc(void *hwnd, int lParam)
{
    char wnd_title[256]; // [sp+0h] [bp-100h]@1

    GetWindowTextA(hwnd, wnd_title, 255);
    return 1;
}

//----- (004205E0) --------------------------------------------------------
int __stdcall enum_thread_proc(void *hwnd, int lParam)
{
    char wnd_title[256]; // [sp+0h] [bp-100h]@1

    GetWindowTextA(hwnd, wnd_title, 255);
    return 1;
}

//----- (00420610) --------------------------------------------------------
int __stdcall close_thread_windows(void *hwnd, int lParam)
{
    if( hwnd != AppWnd && GetParent(hwnd) != AppWnd )
        SendMessageA(hwnd, 0x10u, 0, 0);
    return 1;
}

//----- (00420650) --------------------------------------------------------
int __stdcall close_child_windows(void *hwnd, int lParam)
{
    char str[256]; // [sp+Ch] [bp-100h]@1

    str[0] = 0;
    GetWindowTextA(hwnd, str, 255);
    if( strcmp(str, aLocateSession) )
        SendMessageA(hwnd, 0x10u, 0, 0);
    return 1;
}

//----- (004206D0) --------------------------------------------------------
RGE_Base_Game *__stdcall RGE_Base_Game::wnd_proc(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // esi@4
    void *v6; // ebx@4
    unsigned int v7; // edi@4
    void *v8; // ebp@4
    TSound_Driver *v9; // ecx@4
    TMusic_System *v10; // ecx@6
    TPanel *v11; // eax@9
    RGE_Base_Game *result; // eax@20
    int v13; // eax@25
    unsigned int v14; // ecx@25
    TDrawSystem *v15; // ecx@45
    TDrawSystem *v16; // ecx@48
    TMousePointer *v17; // ecx@55
    TPanel *v18; // eax@71
    RGE_Base_GameVtbl *v19; // edx@115
    LRESULT v20; // esi@120
    int mouse_down; // [sp+30h] [bp-4h]@1
    RGE_Base_Game *thisa; // [sp+38h] [bp+4h]@8
    int fActive; // [sp+3Ch] [bp+8h]@115
    unsigned int wparama; // [sp+44h] [bp+10h]@26
    int lparama; // [sp+48h] [bp+14h]@25

    color_log(36, 36, 3);
    mouse_down = 0;
    if( msg >= 0x201 && msg <= 0x206 )
    {
        mouse_down = 1;
        color_log(76, 76, 4);
    }
    v5 = this;
    v6 = (void *)lparam;
    v7 = wparam;
    v8 = wnd;
    v9 = this->sound_system;
    if( v9 )
        TSound_Driver::handle_messages(v9, wnd, msg, wparam, lparam);
    color_log(36, 22, 3);
    v10 = this->music_system;
    if( v10 )
        TMusic_System::handle_messages(v10, wnd, msg, wparam, lparam);
    color_log(36, 76, 3);
    thisa = 0;
    if( TPanelSystem::currentPanel(&panel_system) )
    {
        color_log(36, 50, 3);
        v11 = TPanelSystem::currentPanel(&panel_system);
        thisa = (RGE_Base_Game *)v11->vfptr->wnd_proc(v11, wnd, msg, wparam, lparam);
        if( thisa )
        {
            if( msg != 512 && msg != 275 )
                goto LABEL_95;
        }
    }
    color_log(36, 69, 3);
    if( msg <= 5 )
    {
        if( msg == 5 )
        {
            if( !system_ignore_size_messages )
            {
                color_log(50, -70, 3);
                if( !v5->vfptr->handle_size(v5, wnd, 5u, wparam, lparam) )
                {
                    if( mouse_down )
                    {
                        color_log(76, 95, 4);
                        color_log(36, 95, 3);
                        return thisa;
                    }
                    goto LABEL_114;
                }
            }
        }
        else if( msg == 2 )
        {
            color_log(50, -70, 3);
            if( !v5->vfptr->handle_destroy(v5, wnd, 2u, wparam, lparam) )
                goto LABEL_112;
        }
        goto LABEL_120;
    }
    if( msg <= 0xF )
    {
        if( msg != 15 )
        {
            if( msg == 6 && v5->prog_ready )
            {
                v13 = (unsigned short)wparam;
                v14 = wparam >> 16;
                lparama = wparam >> 16;
                if( !(_WORD)wparam )
                {
                    wparama = GetWindowThreadProcessId(v5->prog_window, 0);
                    if( GetWindowThreadProcessId(v6, 0) == wparama )
                        save_active_wnd = v6;
                    v8 = wnd;
                    v13 = (unsigned short)v7;
                    v14 = lparama;
                }
                if( v8 == v5->prog_window && v13 && v14 && save_active_wnd )
                    save_active_wnd = 0;
            }
            goto LABEL_120;
        }
        color_log(50, 69, 3);
        if( !v5->vfptr->handle_paint(v5, wnd, 15u, wparam, lparam) )
        {
LABEL_95:
            if( mouse_down )
            {
                color_log(76, 95, 4);
                color_log(36, 95, 3);
                return thisa;
            }
            goto LABEL_114;
        }
        goto LABEL_120;
    }
    if( msg <= 0x1C )
    {
        if( msg == 28 )
        {
            if( v5->prog_ready )
            {
                if( wparam == 1 )
                {
                    if( sound_deactivated )
                    {
                        SetCursor(0);
                        SetClassLongA(v5->prog_window, -12, 0);
                        if( v5->prog_mode != 1 )
                            v5->vfptr->restart_sound_system(v5);
                        sound_deactivated = 0;
                        v15 = v5->draw_system;
                        if( v15 )
                        {
                            TDrawSystem::CheckSurfaces(v15);
                            TDrawSystem::ClearRestored(v5->draw_system);
                            RGE_Base_Game::set_render_all(v5);
                        }
                        if( v5->prog_mode != 1 )
                        {
                            v16 = v5->draw_system;
                            if( v16 )
                            {
                                TDrawSystem::ClearPrimarySurface(v16);
                                TDrawSystem::ModifyPalette(v5->draw_system, 0, 256, v5->draw_system->palette);
                            }
                            RGE_Base_Game::set_render_all(v5);
                            InvalidateRect(v5->prog_window, 0, 1);
                            do_restore_palette = 10;
                            restore_palette_timer = debug_timeGetTime();
                            restore_mouse_after_paint = 1;
                        }
                    }
                }
                else if( !sound_deactivated )
                {
                    SetClassLongA(v5->prog_window, -12, 0);
                    if( v5->prog_mode != 1 )
                        v5->vfptr->stop_sound_system(v5);
                    sound_deactivated = 1;
                    if( v5->prog_mode != 1 )
                    {
                        v17 = v5->mouse_pointer;
                        if( v17 )
                            TMousePointer::Shutdown_Mouse(v17);
                    }
                }
            }
            color_log(50, 84, 3);
            if( v5->vfptr->handle_activate(v5, wnd, 28u, wparam, lparam) )
                goto LABEL_120;
            goto LABEL_95;
        }
        if( msg != 16 )
        {
LABEL_120:
            color_log(84, 36, 3);
            v20 = DefWindowProcA(v8, msg, v7, (LPARAM)v6);
            if( mouse_down )
                color_log(76, 95, 4);
            color_log(36, 95, 3);
            return (RGE_Base_Game *)v20;
        }
LABEL_106:
        color_log(50, -70, 3);
        if( !v5->vfptr->handle_close(v5, wnd, msg, wparam, lparam) )
        {
            if( mouse_down )
            {
                color_log(76, 95, 4);
                color_log(36, 95, 3);
                return thisa;
            }
            goto LABEL_114;
        }
        goto LABEL_120;
    }
    if( msg <= 0x104 )
    {
        if( msg == 260 )
        {
            color_log(36, -70, 3);
            if( !v5->vfptr->handle_key_down(v5, wnd, 260u, wparam, lparam) )
                goto LABEL_95;
        }
        else if( msg == 256 )
        {
            color_log(36, -70, 3);
            if( !v5->vfptr->handle_key_down(v5, wnd, 256u, wparam, lparam) )
                goto LABEL_95;
        }
        goto LABEL_120;
    }
    if( msg <= 0x111 )
    {
        if( msg != 273 )
        {
            if( msg == 261 && wparam == 18 && TPanelSystem::currentPanel(&panel_system) )
            {
                v18 = TPanelSystem::currentPanel(&panel_system);
                v18->vfptr->handle_reactivate(v18);
            }
            goto LABEL_120;
        }
        color_log(50, 22, 3);
        if( !v5->vfptr->handle_command(v5, wnd, 273u, wparam, lparam) )
            goto LABEL_95;
        goto LABEL_120;
    }
    if( msg <= 0x200 )
    {
        if( msg == 512 )
        {
            color_log(36, 84, 3);
            if( v5->vfptr->handle_mouse_move(v5, wnd, 512u, wparam, lparam) )
            {
                if( MouseCursorInChildContol )
                {
                    if( v5->windows_mouse )
                    {
                        SetCursor(v5->mouse_cursor);
                        MouseCursorInChildContol = 0;
                    }
                    else
                    {
                        SetCursor(0);
                        SetClassLongA(v5->prog_window, -12, 0);
                        RGE_Base_Game::mouse_on(v5);
                        MouseCursorInChildContol = 0;
                    }
                }
                goto LABEL_120;
            }
            goto LABEL_95;
        }
        if( msg == 274 )
        {
            if( wparam == 61696 )
            {
                if( v5->prog_info->full_screen )
                {
                    result = (RGE_Base_Game *)IsIconic(v5->prog_window);
                    if( !result )
                        return result;
                }
            }
            goto LABEL_120;
        }
        if( msg == 275 )
        {
            v5->vfptr->handle_idle(v5);
        }
        else if( msg == 278 )
        {
            color_log(50, -70, 3);
            if( !v5->vfptr->handle_init_menu(v5, wnd, 278u, wparam, lparam) )
                goto LABEL_95;
        }
        goto LABEL_120;
    }
    if( msg <= 0x218 )
    {
        if( msg == 536 )
        {
            if( !wparam )
                return (RGE_Base_Game *)1112363332;
            goto LABEL_120;
        }
        if( msg == 530 )
        {
            color_log(50, -70, 3);
            if( !v5->vfptr->handle_exit_menu(v5, wnd, 530u, wparam, lparam) )
                goto LABEL_95;
        }
        goto LABEL_120;
    }
    if( msg <= 0x3B9 )
    {
        if( msg != 953 )
        {
            if( msg != 783 )
            {
                if( msg == 785 )
                {
                    color_log(50, -70, 3);
                    if( !v5->vfptr->handle_palette_changed(v5, wnd, 785u, wparam, lparam) )
                        goto LABEL_112;
                }
                goto LABEL_120;
            }
            color_log(50, -70, 3);
            if( v5->vfptr->handle_query_new_palette(v5, wnd, 783u, wparam, lparam) )
                goto LABEL_106;
LABEL_112:
            if( mouse_down )
                color_log(76, 95, 4);
LABEL_114:
            color_log(36, 95, 3);
            return thisa;
        }
LABEL_111:
        color_log(50, 76, 3);
        if( v5->vfptr->handle_music_done(v5, wnd, msg, wparam, lparam) )
            goto LABEL_120;
        goto LABEL_112;
    }
    if( msg != 1024 )
    {
        if( msg != 1280 )
            goto LABEL_120;
        goto LABEL_111;
    }
    color_log(50, 36, 3);
    v19 = v5->vfptr;
    fActive = debug_timeGetTime_on;
    debug_timeGetTime_on = 0;
    if( v19->handle_user_command(v5, v8, 1024u, wparam, lparam) )
    {
        debug_timeGetTime_on = fActive;
        goto LABEL_120;
    }
    if( mouse_down )
        color_log(76, 95, 4);
    color_log(36, 95, 3);
    debug_timeGetTime_on = fActive;
    return thisa;
}
// 62C4C4: using guessed type int MouseCursorInChildContol;
// 62C4E8: using guessed type int debug_timeGetTime_on;
// 62C504: using guessed type int do_restore_palette;
// 62C508: using guessed type unsigned __int32 restore_palette_timer;
// 62C55C: using guessed type int restore_mouse_after_paint;
// 62C570: using guessed type void *save_active_wnd;
// 62E63C: using guessed type int system_ignore_size_messages;

//----- (00420F60) --------------------------------------------------------
int RGE_Base_Game::handle_idle()
{
    RGE_Base_Game *v1; // esi@1
    unsigned __int32 v2; // edi@5
    TDrawSystem *v3; // ecx@8
    TPanel *v4; // eax@14
    int result; // eax@22

    v1 = this;
    if( this->prog_ready && this->prog_window )
    {
        color_log(22, 22, 2);
        if( do_restore_palette && v1->prog_active )
        {
            v2 = 250;
            if( do_restore_palette > 5 )
                v2 = 500;
            if( debug_timeGetTime() - restore_palette_timer >= v2 )
            {
                v3 = v1->draw_system;
                if( v3 )
                    TDrawSystem::ModifyPalette(v3, 0, 256, v3->palette);
                --do_restore_palette;
                restore_palette_timer = debug_timeGetTime();
            }
        }
        color_log(50, 50, 5);
        if( v1->sound_system )
        {
            color_log(22, -70, 2);
            TSound_Driver::handle_messages(v1->sound_system, v1->prog_window, 0x113u, 0, 0);
        }
        if( TPanelSystem::currentPanel(&panel_system) )
        {
            color_log(22, 69, 2);
            v4 = TPanelSystem::currentPanel(&panel_system);
            v4->vfptr->handle_idle(v4);
        }
        if( v1->comm_handler && RGE_Base_Game::multiplayerGame(v1) )
        {
            color_log(69, 69, 1);
            TCommunications_Handler::ReceiveGameMessages(v1->comm_handler);
            color_log(69, 95, 1);
        }
        if( v1->do_show_comm )
        {
            color_log(22, 50, 2);
            v1->vfptr->show_comm(v1);
        }
        if( v1->do_show_ai )
        {
            color_log(22, 36, 2);
            v1->vfptr->show_ai(v1);
        }
        color_log(50, 95, 5);
        color_log(22, 95, 2);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}
// 62C504: using guessed type int do_restore_palette;
// 62C508: using guessed type unsigned __int32 restore_palette_timer;

//----- (00421110) --------------------------------------------------------
int RGE_Base_Game::handle_mouse_move(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // esi@1
    int result; // eax@2
    RGE_Base_GameVtbl *v7; // edi@8
    int shift_key; // [sp+4h] [bp-18h]@8
    int ctrl_key; // [sp+8h] [bp-14h]@8
    int right_btn; // [sp+Ch] [bp-10h]@8
    int left_btn; // [sp+10h] [bp-Ch]@8
    tagPOINT point; // [sp+14h] [bp-8h]@8

    v5 = this;
    if( this->prog_ready )
    {
        if( this->custom_mouse && !this->windows_mouse )
        {
            if( TMousePointer::in_game_mode(this->mouse_pointer) )
                TMousePointer::Poll(v5->mouse_pointer);
            else
                TMousePointer::draw(v5->mouse_pointer, 0);
        }
        RGE_Base_Game::get_mouse_info(wparam, lparam, &point, &left_btn, &right_btn, &ctrl_key, &shift_key);
        v7 = v5->vfptr;
        v5->vfptr->action_mouse_move(v5, point.x, point.y, left_btn, right_btn, ctrl_key, shift_key);
        v7->handle_idle(v5);
        result = 1;
    }
    else
    {
        result = 1;
    }
    return result;
}

//----- (004211D0) --------------------------------------------------------
int RGE_Base_Game::handle_key_down(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // edi@1
    int result; // eax@2
    unsigned int v7; // ecx@5

    v5 = this;
    if( !this->prog_ready )
        return 1;
    key = wparam;
    repeat_count = (unsigned short)lparam;
    ctrl_key = GetKeyState(17) < 0;
    alt_key = GetKeyState(18) < 0;
    shift_key = GetKeyState(16) < 0;
    if( wnd == v5->prog_window && msg == 260 )
    {
        v7 = key;
        if( key != 18 && key != 32 && key != 121 || !v5->prog_info->full_screen )
            goto LABEL_11;
        result = IsIconic(v5->prog_window);
        if( !result )
            return result;
    }
    v7 = key;
LABEL_11:
    if( ctrl_key && v7 == 123 )
    {
        TDrawArea::take_snapshot(v5->draw_system->DrawArea, filespec, &snapshot_number);
        result = 0;
    }
    else
    {
        result = v5->vfptr->action_key_down(v5, v7, repeat_count, ctrl_key, alt_key, shift_key) != 0;
    }
    return result;
}

//----- (004212E0) --------------------------------------------------------
BOOL RGE_Base_Game::handle_user_command(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // esi@1
    RGE_Player *v6; // eax@4
    RGE_Player *v7; // eax@6
    RGE_Game_World *v8; // ecx@9
    RGE_Game_World *v9; // ecx@11

    v5 = this;
    if( TCommunications_Handler::MultiplayerGameStart(this->comm_handler) && !out_of_sync )
    {
        if( wparam == 6067 )
        {
            v6 = v5->world->players[RGE_Base_Game::playerID(v5, lparam)];
            v6->vfptr->command_resign(v6, lparam, 1);
        }
        else if( wparam == 6068 )
        {
            v7 = v5->world->players[RGE_Base_Game::playerID(v5, lparam)];
            v7->vfptr->command_resign(v7, lparam, 0);
        }
    }
    if( wparam == 6050 )
    {
        v9 = v5->world;
        if( v9 )
            ((void (__stdcall *)(signed int))v9->vfptr->pause)(1);
    }
    else if( wparam == 6051 )
    {
        v8 = v5->world;
        if( v8 )
            ((void (__stdcall *)(_DWORD))v8->vfptr->pause)(0);
    }
    return v5->vfptr->action_user_command(v5, wparam, lparam) != 0;
}
// 62C560: using guessed type int out_of_sync;

//----- (004213A0) --------------------------------------------------------
BOOL RGE_Base_Game::handle_command(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    return ((int (__stdcall *)(unsigned int, int))this->vfptr->action_command)(wparam, lparam) != 0;
}

//----- (004213C0) --------------------------------------------------------
BOOL RGE_Base_Game::handle_music_done(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    return ((int (*)(void))this->vfptr->action_music_done)() != 0;
}

//----- (004213E0) --------------------------------------------------------
int RGE_Base_Game::handle_paint(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // esi@1
    unsigned int v6; // edi@1
    int v7; // ebp@1
    unsigned int v8; // eax@1
    int result; // eax@2
    int v10; // eax@3
    TDrawSystem *v11; // eax@6
    int v12; // ebp@9
    unsigned int v13; // edi@9
    int v14; // ebp@10
    unsigned int v15; // ebp@14
    TSound_Driver *v16; // edi@14
    unsigned int v17; // eax@16
    unsigned int v18; // ebp@16
    unsigned int v19; // edi@21
    unsigned int v20; // ebp@21
    TPanel *v21; // eax@23
    TPanel *v22; // eax@24
    int v23; // eax@27
    unsigned int v24; // eax@31
    unsigned int v25; // ebp@31
    unsigned int v26; // eax@34
    unsigned int v27; // edi@34
    unsigned int v28; // eax@34
    unsigned int v29; // edi@34
    TMousePointer *v30; // ecx@37

    v5 = this;
    color_log(50, 50, 4);
    v6 = debug_timeGetTime();
    v7 = RGE_Base_Game::check_paint(v5);
    v8 = debug_timeGetTime();
    RGE_Base_Game::add_to_timing(v5, 5, v8 - v6);
    if( v7 )
    {
        v10 = v5->prog_mode;
        if( v10 == 4 || v10 == 6 || v10 == 7 )
        {
            v11 = v5->draw_system;
            if( v11->DrawType != 1 )
            {
                if( v5->custom_mouse )
                {
                    if( v5->mouse_blit_sync )
                    {
                        v12 = ((int (__stdcall *)(IDirectDrawSurface *, signed int))v11->PrimarySurface->vfptr[4].AddRef)(
                                        v11->PrimarySurface,
                                        1);
                        v13 = debug_timeGetTime() + 100;
                        if( v12 == -2005532132 )
                        {
                            while( 1 )
                            {
                                v14 = ((int (__stdcall *)(IDirectDrawSurface *, signed int))v5->draw_system->PrimarySurface->vfptr[4].AddRef)(
                                                v5->draw_system->PrimarySurface,
                                                1);
                                if( debug_timeGetTime() > v13 )
                                    break;
                                if( v14 != -2005532132 )
                                    goto LABEL_14;
                            }
                            v5->mouse_blit_sync = 0;
                        }
                    }
                }
            }
        }
LABEL_14:
        color_log(50, -70, 4);
        v15 = debug_timeGetTime();
        v16 = rge_base_game->sound_system;
        if( v16 )
        {
            TSound_Driver::play_list(rge_base_game->sound_system);
            TSound_Driver::reset_play_list(v16);
        }
        v17 = debug_timeGetTime();
        RGE_Base_Game::add_to_timing(v5, 10, v17 - v15);
        v18 = debug_timeGetTime();
        if( v5->erase_mouse )
        {
            color_log(50, 76, 4);
            if( !v5->render_all && v5->custom_mouse )
                TMousePointer::erase(v5->mouse_pointer);
            v5->erase_mouse = 0;
        }
        v19 = debug_timeGetTime() - v18;
        v20 = debug_timeGetTime();
        color_log(50, 22, 4);
        if( TPanelSystem::currentPanel(&panel_system) )
        {
            color_log(22, 22, 1);
            if( v5->render_all )
            {
                v21 = TPanelSystem::currentPanel(&panel_system);
                v21->vfptr->set_redraw(v21, RedrawFull);
            }
            v22 = TPanelSystem::currentPanel(&panel_system);
            v22->vfptr->handle_paint(v22);
            color_log(22, 95, 1);
        }
        else
        {
            RGE_Base_Game::clear_window(v5);
        }
        color_log(50, 36, 4);
        if( do_show )
        {
            do_show = 0;
            v23 = v5->prog_mode;
            if( v23 == 4 || v23 == 5 )
            {
                if( v5->do_show_timings )
                    v5->vfptr->show_timings(v5);
            }
        }
        v24 = debug_timeGetTime();
        RGE_Base_Game::add_to_timing(v5, 2, v24 - v20);
        v25 = debug_timeGetTime();
        color_log(50, 84, 4);
        if( v5->custom_mouse && !v5->windows_mouse )
        {
            TMousePointer::draw(v5->mouse_pointer, 1);
            v5->erase_mouse = 1;
        }
        v26 = debug_timeGetTime();
        RGE_Base_Game::add_to_timing(v5, 8, v26 - v25 + v19);
        v27 = debug_timeGetTime();
        color_log(50, 69, 4);
        TDrawSystem::Paint(v5->draw_system, 0);
        ValidateRect(v5->prog_window, 0);
        ValidateRect(v5->prog_window, 0);
        v5->render_all = 0;
        v28 = debug_timeGetTime();
        RGE_Base_Game::add_to_timing(v5, 3, v28 - v27);
        color_log(50, 95, 4);
        ++v5->frame_count;
        v29 = debug_timeGetTime();
        if( v29 - start_wait_time >= 0x3E8 )
        {
            v5->vfptr->calc_timings(v5);
            start_wait_time = v29;
            do_show = 1;
        }
        if( restore_mouse_after_paint )
        {
            v30 = v5->mouse_pointer;
            if( v30 )
            {
                TMousePointer::Restore_Mouse(v30, v5->draw_area);
                if( v5->is_mouse_on )
                {
                    if( !v5->custom_mouse || v5->windows_mouse )
                    {
                        SetCursor(v5->mouse_cursor);
                        SetClassLongA(v5->prog_window, -12, (LONG)v5->mouse_cursor);
                    }
                    else
                    {
                        TMousePointer::on(v5->mouse_pointer);
                        TMousePointer::draw(v5->mouse_pointer, 1);
                    }
                }
                InvalidateRect(wnd, 0, 0);
            }
            restore_mouse_after_paint = 0;
        }
        result = 1;
    }
    else
    {
        color_log(50, 95, 4);
        result = 0;
    }
    return result;
}
// 62C55C: using guessed type int restore_mouse_after_paint;

//----- (00421830) --------------------------------------------------------
int RGE_Base_Game::handle_activate(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // esi@1
    int v6; // eax@4
    TPanel *v7; // eax@11
    int result; // eax@12

    v5 = this;
    if( wparam )
        this->prog_active = 1;
    else
        this->prog_active = 0;
    v6 = this->prog_mode;
    if( this->prog_active )
    {
        if( (v6 == 4 || v6 == 6 || v6 == 7) && this->auto_paused == 1 )
        {
            this->auto_paused = 0;
            RGE_Base_Game::set_paused(this, 0, 0);
        }
        if( TPanelSystem::currentPanel(&panel_system) )
        {
            v7 = TPanelSystem::currentPanel(&panel_system);
            v7->vfptr->handle_reactivate(v7);
        }
        v5->vfptr->action_activate(v5);
        result = 1;
    }
    else
    {
        if( (v6 == 4 || v6 == 6 || v6 == 7) && RGE_Base_Game::singlePlayerGame(this) == 1 && !RGE_Base_Game::get_paused(v5) )
        {
            v5->auto_paused = 1;
            RGE_Base_Game::set_paused(v5, 1, 0);
        }
        v5->vfptr->action_deactivate(v5);
        result = 1;
    }
    return result;
}

//----- (00421910) --------------------------------------------------------
BOOL RGE_Base_Game::handle_init_menu(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    return ((int (*)(void))this->vfptr->action_init_menu)() != 0;
}

//----- (00421930) --------------------------------------------------------
BOOL RGE_Base_Game::handle_exit_menu(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    return ((int (*)(void))this->vfptr->action_exit_menu)() != 0;
}

//----- (00421950) --------------------------------------------------------
unsigned int RGE_Base_Game::handle_size(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    unsigned int result; // eax@1
    RGE_Base_Game *v6; // esi@1
    TDrawSystem *v7; // ecx@2
    TDrawSystem *v8; // eax@3
    int v9; // eax@4
    TPanel *v10; // eax@7

    result = wparam;
    v6 = this;
    if( wparam != 1 )
    {
        v7 = this->draw_system;
        if( v7 )
        {
            TDrawSystem::HandleSize(v7, wnd, msg, wparam, lparam);
            v8 = v6->draw_system;
            if( v8 )
            {
                v9 = v8->ScreenWidth;
                if( v9 )
                {
                    v6->prog_info->main_wid = v9;
                    v6->prog_info->main_hgt = v6->draw_system->ScreenHeight;
                }
            }
            if( TPanelSystem::currentPanel(&panel_system) )
            {
                v10 = TPanelSystem::currentPanel(&panel_system);
                v10->vfptr->handle_size(v10, v6->prog_info->main_wid, v6->prog_info->main_hgt);
            }
        }
        v6->vfptr->action_size(v6);
        result = 1;
    }
    return result;
}

//----- (004219F0) --------------------------------------------------------
int RGE_Base_Game::handle_palette_changed(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // esi@1
    TDrawSystem *v6; // ecx@1
    TDrawSystem *v7; // ecx@4

    v5 = this;
    v6 = this->draw_system;
    if( v6 )
        TDrawSystem::HandlePaletteChanged(v6, wnd, msg, wparam, lparam);
    if( (void *)wparam != wnd )
    {
        v7 = v5->draw_system;
        if( v7->DrawType != 1 && v7->ScreenMode != 1 && v7 )
        {
            if( v5->prog_mode != 1 )
            {
                TDrawSystem::ModifyPalette(v7, 0, 256, v7->palette);
                return 1;
            }
        }
        else
        {
            v5->vfptr->handle_query_new_palette(v5, wnd, msg, wparam, lparam);
        }
    }
    return 1;
}

//----- (00421A80) --------------------------------------------------------
int RGE_Base_Game::handle_query_new_palette(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
    RGE_Base_Game *v5; // ebp@1
    TDrawSystem *v6; // eax@1
    int result; // eax@4
    HDC v8; // esi@5
    TEasy_Panel *v9; // edi@6
    void *v10; // eax@7
    UINT v11; // edi@10
    TDrawSystem *v12; // ecx@12

    v5 = this;
    v6 = this->draw_system;
    if( v6 && v6->DrawType != 1 && v6->ScreenMode != 1 )
    {
        InvalidateRect(wnd, 0, 0);
        return TDrawSystem::HandleQueryNewPalette(v5->draw_system, wnd, msg, wparam, lparam);
    }
    v8 = GetDC(wnd);
    if( TPanelSystem::currentPanel(&panel_system) )
    {
        v9 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
        if( TEasy_Panel::get_palette(v9) )
        {
            v10 = TEasy_Panel::get_palette(v9);
LABEL_9:
            SelectPalette(v8, v10, 0);
            goto LABEL_10;
        }
    }
    else
    {
        v10 = v5->prog_palette;
        if( v10 )
            goto LABEL_9;
    }
LABEL_10:
    v11 = RealizePalette(v8);
    ReleaseDC(wnd, v8);
    if( v11 )
        InvalidateRect(wnd, 0, 0);
    v12 = v5->draw_system;
    if( v12 )
        result = TDrawSystem::HandleQueryNewPalette(v12, wnd, msg, wparam, lparam);
    else
        result = 1;
    return result;
}

//----- (00421B70) --------------------------------------------------------
int RGE_Base_Game::handle_close(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    RGE_Base_Game *v5; // esi@1
    int result; // eax@1
    TDrawArea *v7; // ecx@2

    v5 = this;
    result = ((int (*)(void))this->vfptr->action_close)();
    if( result )
    {
        v7 = v5->draw_area;
        if( v7 )
        {
            if( v5->draw_system )
            {
                TDrawArea::Clear(v7, 0, 0);
                TDrawSystem::Paint(v5->draw_system, 0);
            }
        }
        result = 1;
    }
    return result;
}

bool RGE_Base_Game::handle_destroy(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    this->prog_ready = 0;

    if( this->is_timer )
        KillTimer(this->prog_window, 1u);

    this->prog_window = 0;

    PostQuitMessage(0);

    return true;
}

void RGE_Base_Game::calc_timings()
{
    RGE_Base_Game *v1; // esi@1
    unsigned int v2; // ebx@1
    char *v3; // edi@1
    signed int v4; // ebp@1
    unsigned int v5; // eax@9
    unsigned int v6; // ecx@9
    unsigned int v7; // edx@12
    unsigned int v8; // edi@12
    unsigned int v9; // eax@12
    unsigned int v10; // edi@16
    unsigned int v11; // edi@17
    unsigned int v12; // edi@21
    unsigned int v13; // edi@22
    unsigned int v14; // edi@26
    unsigned int v15; // ecx@27
    RGE_Game_World *v16; // eax@32
    int v17; // edi@32
    int v18; // ebx@32
    signed int v19; // edx@32
    int *v20; // ecx@33
    int v21; // edx@33
    int v22; // eax@34
    unsigned int v23; // ecx@35
    int v24; // eax@54
    RGE_Player *v25; // edx@56
    unsigned int v26; // edx@57
    unsigned int v27; // eax@57
    int v28; // [sp+10h] [bp-18h]@36
    int v29; // [sp+14h] [bp-14h]@39
    unsigned int v30; // [sp+18h] [bp-10h]@42
    int v31; // [sp+1Ch] [bp-Ch]@45
    int v32; // [sp+20h] [bp-8h]@48
    int v33; // [sp+24h] [bp-4h]@51

    v1 = this;
    v2 = 0;
    v3 = (char *)this->timings;
    v4 = 30;
    do
    {
        if( !*((_DWORD *)v3 + 4) )
        {
            *((_DWORD *)v3 + 1) = *(_DWORD *)v3;
            *((_DWORD *)v3 + 7) = *((_DWORD *)v3 + 6);
            *(_DWORD *)v3 = 0;
            *((_DWORD *)v3 + 6) = 0;
            *((_DWORD *)v3 + 2) = debug_timeGetTime();
            if( *((_DWORD *)v3 + 3) )
                v2 += *((_DWORD *)v3 + 1);
        }
        v3 += 32;
        --v4;
    }
    while( v4 );
    if( v1->timings[0].start_time )
        v1->timings[0].last_time = debug_timeGetTime() - v1->timings[0].start_time;
    else
        v1->timings[0].last_time = v2;
    v5 = debug_timeGetTime();
    v6 = v1->timings[0].last_time;
    v1->timings[0].start_time = v5;
    if( v6 <= v2 )
        v1->timings[4].last_time = 0;
    else
        v1->timings[4].last_time = v6 - v2;
    v7 = v1->timings[6].last_time;
    v8 = v1->timings[7].last_time;
    v9 = v1->timings[2].last_time;
    if( v9 <= v8 + v7 )
        v1->timings[9].last_time = 0;
    else
        v1->timings[9].last_time = v9 - v7 - v8;
    if( v6 && (v10 = v1->frame_count) != 0 && (v7 = v6 % v10, (v11 = v6 / v10) != 0) )
    {
        v7 = 0x3E8 % v11;
        v1->fps = 0x3E8 / v11;
    }
    else
    {
        v1->fps = 1000;
    }
    if( v6 && (v12 = v1->view_update_count) != 0 && (v7 = v6 % v12, (v13 = v6 / v12) != 0) )
    {
        v7 = 0x3E8 % v13;
        v1->view_update_fps = 0x3E8 / v13;
    }
    else
    {
        v1->view_update_fps = 0;
    }
    if( v6 && (v14 = v1->world_update_count) != 0 && (v7 = v6 % v14, (v15 = v6 / v14) != 0) )
    {
        v7 = 0x3E8 % v15;
        v1->world_update_fps = 0x3E8 / v15;
    }
    else
    {
        v1->world_update_fps = 0;
    }
    ((void (__fastcall *)(RGE_Base_Game *, unsigned int))v1->vfptr->calc_timing_text)(v1, v7);
    if( do_fps_log && v1->prog_mode == 4 )
    {
        v16 = v1->world;
        v17 = 0;
        v18 = 0;
        v19 = v16->player_num;
        if( v19 > 1 )
        {
            v20 = (int *)(v16->players + 1);
            v21 = v19 - 1;
            do
            {
                v22 = *v20;
                ++v20;
                v17 += *(_WORD *)(*(_DWORD *)(v22 + 40) + 8);
                v18 += *(_WORD *)(*(_DWORD *)(v22 + 44) + 8);
                --v21;
            }
            while( v21 );
        }
        v23 = v1->world_update_count;
        if( v23 )
            v28 = v1->timings[4].last_time / v23;
        else
            v28 = 0;
        if( v23 )
            v29 = v1->timings[13].last_time / v23;
        else
            v29 = 0;
        if( v23 )
            v30 = (v1->timings[12].last_time + v1->timings[10].last_time) / v23;
        else
            v30 = 0;
        if( v23 )
            v31 = v1->timings[1].last_time / v23;
        else
            v31 = 0;
        if( v23 )
            v32 = v1->timings[3].last_time / v23;
        else
            v32 = 0;
        if( v23 )
            v33 = v1->timings[7].last_time / v23;
        else
            v33 = 0;
        if( v23 )
            v24 = v1->timings[6].last_time / v23;
        else
            v24 = 0;
        v25 = *v1->world->players;
        fprintf(
            fps_log,
            aLuLdLdLdLdDDDD,
            v1->world->world_time,
            start_mem_total,
            start_mem_high,
            cur_mem_total,
            cur_mem_high,
            v25->objects->number_of_objects,
            v25->sleeping_objects->number_of_objects,
            v17,
            v18,
            v23,
            v1->view_update_count,
            v1->world_update_fps,
            v1->view_update_fps,
            v24,
            v1->timings[6].last_max_time,
            v33,
            v1->timings[7].last_max_time,
            v32,
            v1->timings[3].last_max_time,
            v31,
            v1->timings[1].last_max_time,
            v30,
            v1->timings[12].last_max_time + v1->timings[10].last_max_time,
            v29,
            v1->timings[13].last_max_time,
            v28,
            v1->timings[4].last_max_time,
            0,
            -1,
            -1);
        fflush(fps_log);
    }
    v26 = v1->world_update_count;
    v27 = v1->view_update_count;
    v1->last_frame_count = v1->frame_count;
    v1->last_world_update_count = v26;
    v1->last_view_update_count = v27;
    v1->frame_count = 0;
    v1->world_update_count = 0;
    v1->view_update_count = 0;
}

void RGE_Base_Game::calc_timing_text()
{
    unsigned int frames_count = this->frame_count;
    if( frames_count == 0 )
        frames_count = 1;

    sprintf(
        this->timing_text,
        aFpsLuRendLuVie,
        *((DWORD *)v3 + 70),
        *((DWORD *)v3 + 90) / frame_count,
        *((DWORD *)v3 + 122) / frame_count,
        *((DWORD *)v3 + 130) / frame_count,
        *((DWORD *)v3 + 98) / frame_count,
        *((DWORD *)v3 + 82) / frame_count,
        *((DWORD *)v3 + 154) / frame_count,
        *((DWORD *)v3 + 178) / frame_count,
        *((DWORD *)v3 + 106) / frame_count,
        this->timings[0].last_time / frame_count);
}

void RGE_Base_Game::show_timings()
{
    SetWindowTextA(this->prog_window, this->timing_text);
}

void RGE_Base_Game::show_comm()
{
    char str[256];

    sprintf(str, aS_2, this->comm_handler->GetCommInfo(1));

    SetWindowTextA(this->prog_window, str);
}

void RGE_Base_Game::show_ai()
{
    char str[256];

    sprintf(str, aNoAiInformatio, this->world->curr_player);

    SetWindowTextA(this->prog_window, str);
}

void RGE_Base_Game::send_game_options()
{
    if( this->comm_handler )
        this->comm_handler->SetMyGameOptions((char *)&this->rge_game_options, 0xA8u);
}

void RGE_Base_Game::receive_game_options()
{
    unsigned int size;

    if( this->comm_handler )
    {
        size = 0;

        if( char *option = this->comm_handler->GetMyGameOptions(&size); )
        {
            if( size == 168 )
                this->set_game_options((RGE_Base_Game::RGE_Game_Options *)option);
        }
    }
}

void RGE_Base_Game::set_game_options(RGE_Base_Game::RGE_Game_Options *options)
{
    this->setVersion(          options->versionValue);
    this->setScenarioGame(     options->scenarioGameValue);
    this->setScenarioName(     options->scenarioNameValue);
    this->setSinglePlayerGame( options->singlePlayerGameValue);
    this->setMultiplayerGame(  options->multiplayerGameValue);
    this->setMapSize(          options->mapXSizeValue,
                               options->mapYSizeValue,
                               options->mapZSizeValue);
    this->setAllowCheatCodes(  options->allowCheatCodesValue);
    this->setCheatNotification(options->cheatNotificationValue);
    this->setFullVisibility(   options->fullVisibilityValue);
    this->setFogOfWar(         options->fogOfWarValue);
    this->setColoredChat(      options->coloredChatValue);
    this->setNumberPlayers(    options->numberPlayersValue);
    this->setGameDeveloperMode(options->gameDeveloperModeValue);
    this->setDifficulty(       options->difficultyValue);
    this->setMpPathFinding(    options->mpPathFindingValue);
    int i = 0;
    do
    {
        this->setPlayerCDAndVersion(i, options->playerCDAndVersionValue[i]);
        this->setPlayerTeam(        i, options->playerTeamValue[i]);
    }
    while( ++i < RGE_PLAYERS_COUNT );
}

void RGE_Base_Game::get_game_options(RGE_Base_Game::RGE_Game_Options *options)
{
    options->versionValue           = this->version();
    options->scenarioGameValue      = this->scenarioGame();
    strcpy(options->scenarioNameValue, this->scenarioName());
    options->singlePlayerGameValue  = this->singlePlayerGame();
    options->multiplayerGameValue   = this->multiplayerGame();
    options->mapXSizeValue          = this->mapXSize();
    options->mapYSizeValue          = this->mapYSize();
    options->mapZSizeValue          = this->mapZSize();
    options->allowCheatCodesValue   = this->allowCheatCodes();
    options->cheatNotificationValue = this->cheatNotification();
    options->fullVisibilityValue    = this->fullVisibility();
    options->fogOfWarValue          = this->fogOfWar();
    options->coloredChatValue       = this->coloredChat();
    options->numberPlayersValue     = this->numberPlayers();
    options->gameDeveloperModeValue = this->gameDeveloperMode();
    options->difficultyValue        = this->difficulty();
    options->mpPathFindingValue     = this->mpPathFinding();
    int i = 0;
    do
    {
        options->playerCDAndVersionValue[i] = this->playerCDAndVersion(i);
        options->playerTeamValue[i]         = this->playerTeam(i);
    }
    while( ++i < RGE_PLAYERS_COUNT );
}

double RGE_Base_Game::version()
{
    return this->rge_game_options.versionValue;
}

int RGE_Base_Game::scenarioGame()
{
    return this->rge_game_options.scenarioGameValue;
}

bool RGE_Base_Game::randomGame()
{
    return this->rge_game_options.scenarioGameValue == 0;
}

int RGE_Base_Game::campaignGame()
{
    return this->campaignGameValue;
}

int RGE_Base_Game::savedGame()
{
    return this->savedGameValue;
}

char *RGE_Base_Game::scenarioName()
{
    return this->rge_game_options.scenarioNameValue;
}

int RGE_Base_Game::singlePlayerGame()
{
    return this->rge_game_options.singlePlayerGameValue;
}

int RGE_Base_Game::multiplayerGame()
{
    return this->rge_game_options.multiplayerGameValue;
}

int RGE_Base_Game::mapXSize()
{
    return this->rge_game_options.mapXSizeValue;
}

int RGE_Base_Game::mapYSize()
{
    return this->rge_game_options.mapYSizeValue;
}

int RGE_Base_Game::mapZSize()
{
    return this->rge_game_options.mapZSizeValue;
}

int RGE_Base_Game::allowCheatCodes()
{
    return this->rge_game_options.allowCheatCodesValue;
}

int RGE_Base_Game::cheatNotification()
{
    return this->rge_game_options.cheatNotificationValue;
}

int RGE_Base_Game::fullVisibility()
{
    return this->rge_game_options.fullVisibilityValue;
}

int RGE_Base_Game::fogOfWar()
{
    return this->rge_game_options.fogOfWarValue;
}

int RGE_Base_Game::coloredChat()
{
    return this->rge_game_options.coloredChatValue;
}

int RGE_Base_Game::gameDeveloperMode()
{
    return this->rge_game_options.gameDeveloperModeValue;
}

int RGE_Base_Game::playerHasCD(int player_num)
{
    return this->rge_game_options.playerCDAndVersionValue[player_num] & 1;
}

unsigned int RGE_Base_Game::playerVersion(int player_num)
{
    return (unsigned int)this->rge_game_options.playerCDAndVersionValue[player_num] >> 1;
}

char *RGE_Base_Game::playerVersionString(int player_num)
{
    switch( this->playerVersion(player_num) )
    {
        case 0u:
            return message_in;

        case 1u:
            return a1_0;

        case 2u:
            return a1_0a;

        case 3u:
            return a1_0b;

        case 4u:
            return a1_0c;

        case 5u:
            return a1_0d;

        case 6u:
            return a1_0e;

        case 7u:
            return a1_1;

        case 8u:
            return a1_1a;

        case 9u:
            return a1_1b;

        case 0xAu:
            return a1_1c;

        case 0xBu:
            return a1_2;

        case 0xCu:
            return a1_2a;

        case 0xDu:
            return a1_2b;

        case 0xEu:
            return a1_2c;

        case 0xFu:
            return a1_3;

        case 0x10u:
            return a1_3a;

        case 0x11u:
            return a1_3b;

        case 0x12u:
            return a1_3c;

        case 0x13u:
            return a1_4;

        case 0x14u:
            return a1_4a;

        case 0x15u:
            return a1_4b;

        case 0x16u:
            return a1_4c;

        default:
            return a1_x;
    }
}

char RGE_Base_Game::playerCDAndVersion(int player_num)
{
    return this->rge_game_options.playerCDAndVersionValue[player_num];
}

int RGE_Base_Game::difficulty()
{
    return this->rge_game_options.difficultyValue;
}

int RGE_Base_Game::numberPlayers()
{
    return this->rge_game_options.numberPlayersValue;
}

int RGE_Base_Game::playerTeam(int player_num)
{
    return this->rge_game_options.playerTeamValue[player_num];
}

char RGE_Base_Game::pathFinding()
{
    return this->pathFindingValue;
}

char RGE_Base_Game::mpPathFinding()
{
    return this->rge_game_options.mpPathFindingValue;
}

char *RGE_Base_Game::gameSummary()
{
    temp[0] = 0;
    return temp;
}

void RGE_Base_Game::find_campaigns()
{
    RGE_Game_Info::find_campaigns(this->player_game_info);
}

void RGE_Base_Game::setScenarioGame(int v)
{
    this->rge_game_options.scenarioGameValue = v;
}

void RGE_Base_Game::setVersion(float val)
{
    this->rge_game_options.versionValue = val;
}

void RGE_Base_Game::setScenarioName(char *n)
{
    strncpy(this->rge_game_options.scenarioNameValue, n, 0x80u);
    this->rge_game_options.scenarioNameValue[127] = 0;
}

void RGE_Base_Game::setCampaignGame(int v)
{
    this->campaignGameValue = v;
}

void RGE_Base_Game::setSavedGame(int v)
{
    this->savedGameValue = v;
}

void RGE_Base_Game::setSinglePlayerGame(int v)
{
    this->rge_game_options.singlePlayerGameValue = v;
    this->rge_game_options.multiplayerGameValue = v == 0;
}

void RGE_Base_Game::setMultiplayerGame(int v)
{
    this->rge_game_options.multiplayerGameValue = v;
    this->rge_game_options.singlePlayerGameValue = v == 0;
}

void RGE_Base_Game::setMapSize(int x, int y, int z)
{
    this->rge_game_options.mapXSizeValue = x;
    this->rge_game_options.mapYSizeValue = y;
    this->rge_game_options.mapZSizeValue = z;
}

void RGE_Base_Game::setAllowCheatCodes(int v)
{
    this->rge_game_options.allowCheatCodesValue = v;
}

void RGE_Base_Game::setCheatNotification(int v)
{
    this->rge_game_options.cheatNotificationValue = v;
}

void RGE_Base_Game::setFullVisibility(int v)
{
    this->rge_game_options.fullVisibilityValue = v;
}

void RGE_Base_Game::setFogOfWar(int v)
{
    this->rge_game_options.fogOfWarValue = v;
}

void RGE_Base_Game::setColoredChat(int v)
{
    this->rge_game_options.coloredChatValue = v;
}

void RGE_Base_Game::setNumberPlayers(int v)
{
    this->rge_game_options.numberPlayersValue = v;
}

void RGE_Base_Game::setGameDeveloperMode(int v)
{
    this->rge_game_options.gameDeveloperModeValue = v;
}

void RGE_Base_Game::setPlayerHasCD(int player_num, int has_cd)
{
    this->rge_game_options.playerCDAndVersionValue[player_num] = has_cd | this->rge_game_options.playerCDAndVersionValue[player_num] & 0xFE;
}

void RGE_Base_Game::setPlayerVersion(int player_num, char player_version)
{
    this->rge_game_options.playerCDAndVersionValue[player_num] = this->rge_game_options.playerCDAndVersionValue[player_num] & 1 | 2 * player_version;
}

void RGE_Base_Game::setPlayerCDAndVersion(int player_num, char val)
{
    this->rge_game_options.playerCDAndVersionValue[player_num] = val;
}

void RGE_Base_Game::setDifficulty(int difficulty)
{
    this->rge_game_options.difficultyValue = difficulty;
}

void RGE_Base_Game::setPlayerTeam(int player_num, int team)
{
    this->rge_game_options.playerTeamValue[player_num] = team;
}

void RGE_Base_Game::setPathFinding(char val)
{
    this->pathFindingValue = val;
}

void RGE_Base_Game::setMpPathFinding(char val)
{
    this->rge_game_options.mpPathFindingValue = val;
}

void RGE_Base_Game::set_map_visible(char flag)
{
    if( this->world )
        this->world->set_map_visible(flag);
}

void RGE_Base_Game::set_map_fog(char flag)
{
    if( this->world )
        this->world->set_map_fog(flag);
}

void RGE_Base_Game::turn_world_sound_off()
{
    this->world->turn_sound_off();
}

int RGE_Base_Game::campaign_open_scenario()
{
    return this->player_game_info->open_scenario();
}

int RGE_Base_Game::GetChecksum(int player_id)
{
    if( this->world == NULL )
        return 0;

    if( player_id < 0 )
        return this->world->players[this->world->curr_player]->get_checksum();

    if( player_id < this->world->player_num )
        return this->world->players[player_id]->get_checksum();
    else
        return 0;
}

char RGE_Base_Game::GetWorldChecksums(int *new_checksum, int *new_position_checksum, int *new_action_checksum)
{
    signed int v4; // esi@1
    RGE_Game_World *v5; // eax@1
    int v6; // eax@3
    char result; // al@4
    int checksum1; // [sp+10h] [bp-10h]@1
    int checksum2; // [sp+14h] [bp-Ch]@1
    int checksum3; // [sp+18h] [bp-8h]@1
    RGE_Base_Game *v11; // [sp+1Ch] [bp-4h]@1

    v4 = 0;
    v11 = this;
    checksum1 = 0;
    *new_checksum = 0;
    *new_position_checksum = 0;
    *new_action_checksum = 0;
    v5 = this->world;
    checksum2 = 0;
    checksum3 = 0;
    if( v5 )
    {
        if( v5->player_num > 0 )
        {
            do
            {
                RGE_Player::get_checksums(v5->players[v4], &checksum1, &checksum2, &checksum3);
                v6 = (int)v11;
                *new_checksum += checksum1;
                *new_position_checksum += checksum2;
                ++v4;
                *new_action_checksum += checksum3;
                v5 = *(RGE_Game_World **)(v6 + 1012);
            }
            while( v4 < v5->player_num );
        }
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int RGE_Base_Game::GetWorldChecksum()
{
    if( this->world == NULL )
        return 0;

    int v2 = 0;
    for( int i = 0; i < this->world->player_num; i++ )
    {
        v2 += this->world->players[i]->get_checksum();
    }
    return v2;
}

void RGE_Base_Game::disable_input()
{
    RGE_Base_Game *v1; // esi@1
    HCURSOR v2; // eax@2
    void *v3; // eax@3

    v1 = this;
    if( this->is_mouse_on )
    {
        v2 = LoadCursorA(0, (LPCSTR)0x7F02);
        RGE_Base_Game::set_mouse_cursor(v1, v2);
    }
    TPanelSystem::DisableInput(&panel_system);
    v3 = v1->input_disabled_window;
    v1->input_enabled = 0;
    if( v3 )
    {
        if( GetCapture() )
            ReleaseCapture();
        SetCapture(v1->input_disabled_window);
    }
}

void RGE_Base_Game::enable_input()
{
    RGE_Base_Game *v1; // esi@1
    int v2; // eax@4
    HCURSOR v3; // eax@5

    v1 = this;
    if( this->input_disabled_window && GetCapture() )
        ReleaseCapture();
    TPanelSystem::EnableInput(&panel_system);
    v2 = v1->is_mouse_on;
    v1->input_enabled = 1;
    if( v2 )
    {
        v3 = LoadCursorA(0, (LPCSTR)0x7F00);
        RGE_Base_Game::set_mouse_cursor(v1, v3);
    }
}

void RGE_Base_Game::set_screen_size(int wid, int hgt)
{
    RGE_Base_Game *v3; // esi@1
    int v4; // ebp@1
    TDrawArea *v5; // eax@1
    int v6; // edi@1
    TDrawSystem *v7; // eax@3
    HDC v8; // eax@6
    void *v9; // ebx@6
    void *v10; // ST10_4@12
    void *v11; // ST10_4@13
    tagRECT win_rect; // [sp+10h] [bp-20h]@14
    tagRECT client_rect; // [sp+20h] [bp-10h]@14
    int wida; // [sp+34h] [bp+4h]@6
    int horz_res; // [sp+38h] [bp+8h]@6

    v3 = this;
    v4 = hgt;
    v5 = this->draw_area;
    v6 = wid;
    if( v5->Width != wid || v5->Height != hgt )
    {
        v7 = this->draw_system;
        if( v7->DrawType != 2 || v7->ScreenMode != 2 )
        {
            wida = 0;
            horz_res = 0;
            v8 = CreateICA(pszDriver, 0, 0, 0);
            v9 = v8;
            if( v8 )
            {
                wida = GetDeviceCaps(v8, 8);
                horz_res = GetDeviceCaps(v9, 10);
                DeleteDC(v9);
            }
            if( v6 <= wida && v4 <= horz_res )
            {
                if( wida != v6 || horz_res != v4 )
                {
                    v11 = v3->prog_window;
                    v3->window_style = 315228160;
                    SetWindowLongA(v11, -20, 315228160);
                    SetWindowLongA(v3->prog_window, -16, v3->window_style);
                }
                else
                {
                    v10 = v3->prog_window;
                    v3->window_style = -1844969472;
                    SetWindowLongA(v10, -16, -1844969472);
                    SetWindowLongA(v3->prog_window, -20, v3->window_style);
                }
                SetWindowPos(v3->prog_window, 0, 0, 0, v6, v4, 0);
                GetWindowRect(v3->prog_window, &win_rect);
                GetClientRect(v3->prog_window, &client_rect);
                if( client_rect.right != v6 || client_rect.bottom != v4 )
                    SetWindowPos(
                        v3->prog_window,
                        0,
                        win_rect.left,
                        win_rect.top,
                        win_rect.right + v6 - win_rect.left - client_rect.right,
                        win_rect.bottom + v4 - win_rect.top - client_rect.bottom,
                        0);
            }
        }
        else
        {
            SetCursor(0);
            SetClassLongA(v3->prog_window, -12, 0);
            TMousePointer::Shutdown_Mouse(v3->mouse_pointer);
            TDrawSystem::SetDisplaySize(v3->draw_system, wid, hgt, 8);
            TDrawSystem::CheckSurfaces(v3->draw_system);
            TDrawSystem::ClearRestored(v3->draw_system);
            RGE_Base_Game::set_render_all(v3);
            restore_mouse_after_paint = 1;
        }
    }
}

bool RGE_Base_Game::check_prog_argument(char *argument)
{
    char cmd_line[256];

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFFu);

    cmd_line[255] = 0;

    CharUpperA(cmd_line);

    return strstr(cmd_line, argument) != 0;
}

RGE_Scenario_Header *RGE_Base_Game::get_scenario_checksum(char *scenario_file)
{
    RGE_Scenario_Header *result; // eax@1
    RGE_Scenario_Header *v3; // esi@1
    RGE_Scenario_Header *v4; // edi@2

    result = RGE_Base_Game::get_scenario_header(this, scenario_file, 0);
    v3 = result;
    if( result )
    {
        v4 = (RGE_Scenario_Header *)result->checksum;
        RGE_Scenario_Header::~RGE_Scenario_Header(result);
        operator delete(v3);
        result = v4;
    }
    return result;
}

bool RGE_Base_Game::check_scenario_checksum(char *scenario, int checksum)
{
    RGE_Scenario_Header *header = this->get_scenario_checksum(scenario);

    return header && header == (RGE_Scenario_Header *)checksum;
}

int RGE_Base_Game::playerID(int player_index)
{
    return this->playerIDValue[player_index];
}

void RGE_Base_Game::setPlayerID(int player_index, int player_id)
{
    this->playerIDValue[player_index] = player_id;
}

void RGE_Base_Game::reset_countdown_timer(int in_countdown_player_id)
{
    this->countdown_timer[in_countdown_player_id] = -1;
}

void RGE_Base_Game::set_countdown_timer(int in_countdown_player_id, int in_countdown_timer)
{
    int timer = this->countdown_timer[in_countdown_player_id];

    if( timer > in_countdown_timer ||
        timer < 0 )
        this->countdown_timer[in_countdown_player_id] = in_countdown_timer;
}

void RGE_Base_Game::get_countdown_timer(int out_countdown_player_id, int *out_countdown_timer)
{
    *out_countdown_timer = this->countdown_timer[out_countdown_player_id];
}

bool RGE_Base_Game::play_video(char *file_name)
{
    return false;
}

bool RGE_Base_Game::play_sound(int sound_id)
{
    TDigital *digital;

    if( this->sounds &&
        digital = this->sounds[sound_id] )
    {
        if( digital->is_playing() )
            return true;
        else
            return digital->play();
    }
    else
    {
        return false;
    }
}

#if ENGINE_AOC
bool play_sound(int sound_id, int volume_in, short loop_count);
{
    TDigital *digital;

    if( this->sounds &&
        digital = this->sounds[sound_id] )
    {
        digital->set_volume(volume_in);

        digital->set_loop(loop_count);
    }
    else
    {
        return false;
    }
}
#endif

double RGE_Base_Game::get_game_speed()
{
    return this->game_speed;
}

void RGE_Base_Game::set_game_speed(float val)
{
    this->game_speed = val;
}

int RGE_Base_Game::get_single_player_difficulty()
{
    return this->single_player_difficulty;
}

void RGE_Base_Game::set_single_player_difficulty(int val)
{
    this->single_player_difficulty = val;
}

void RGE_Base_Game::setup_map_save_area()
{
    RGE_Base_Game *v1; // esi@1
    TDrawArea *v2; // eax@1
    TDrawArea *v3; // eax@2
    TDrawArea *v4; // edi@6

    this->map_save_area = new TDrawArea(SurfaceName, 0);

    if( this->map_save_area && !this->map_save_area->Init(this->draw_system, 280, 140, 0, 0) )
    {
        v4 = v1->map_save_area;
        if( v4 )
        {
            TDrawArea::~TDrawArea(v1->map_save_area);
            operator delete(v4);
        }
        v1->map_save_area = 0;
    }
}

void RGE_Base_Game::reload_scenarios_info()
{
    this->scenario_info->reload_scenarios();
}

void RGE_Base_Game::set_render_all()
{
    this->render_all = 1;

    &panel_system->set_restore();
}
