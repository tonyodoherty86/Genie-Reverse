
/**
 * @file    Engine\TRB\Game.cpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

/**
 * Specifies the String-Table DLL file for standard usage.
 */
HMODULE StringTableX;

/**
 * Specifies the String-Table DLL file for Patch-1 usage.
 */
HMODULE StringTableXP1;

/**
 * Determines the command option for quick-start.
 */
bool quick_start_game_mode;

bool SyncError;

bool GameRunning;

bool AlreadyDesynced;

bool LastDesync;

bool DesyncData;

bool DiskOutOfSpace;

/**
 * Determines whether video compressors are installed on the device.
 */
bool video_codec_available;

/**
 *
 */
TRIBE_Game::TRIBE_Game( RGE_Prog_Info *prog_info_in, bool do_setup )
{
    TRIBE_Game *v3; // esi@1
    int *v4; // eax@1
    signed int v5; // ecx@1
    int v6; // edi@3
    int **v7; // ebp@3
    bool v8; // zf@4
    bool v9; // sf@4
    unsigned __int8 v10; // of@4
    int v11; // eax@8

    RGE_Prog_Info *prog_info_ina;

    /* call parent constructor: */
    RGE_Base_Game::RGE_Base_Game(prog_info_in, 0);

    this->input_enabled = 1;
    this->input_disabled_window = 0;
    this->testing_scenario[0] = 0;
    StringTableX = 0;
    this->startup_scenario[0] = 0;
    this->startup_game[0] = 0;
    this->save_game_name[0] = 0;
    this->load_game_name[0] = 0;
    this->auto_exit_time = 0;
    this->timing_text2[0] = 0;
    *(_DWORD *)&__S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[4] = 0;
    out_of_sync = 0;
    out_of_sync2 = 0;
    this->MouseRightClickTable = 0;
    this->MouseRightClickTableSize = 0;
    this->MouseLeftClickTable = 0;
    this->MouseLeftClickTableSize = 0;

    this->setMapSize(MapSize::Medium);
    this->setMapType(MapType::WaterAndLand);
    this->setAnimals(1);
    this->setPredators(1);
    this->setVictoryType(VictoryType::VictoryConquest, 1);
    this->setAllowTrading(1);
    this->setLongCombat(0);
    this->setRandomizePositions(0);
    this->setFullTechTree(0);
    this->setResourceLevel(0);
    this->setStartingAge(0);
    this->setStartingUnits(0);
    this->setDeathMatch(0);
    this->setPopLimit(50);
    this->setQuickStartGame(0);
    this->setRandomStartValue(-1);

    // this->notification_loc_ set to -1

    prog_info_ina = (RGE_Prog_Info *)1;
    v6 = 0;
    v7 = &player_dropped;
    do
    {
        this->setCivilization(v6, (int)prog_info_ina);

        v10 = __OFSUB__(&prog_info_ina->prog_name[1], 16);
        v8 = &prog_info_ina->prog_name[1] == (char *)16;
        v9 = (signed int)&prog_info_ina[-1].avi_dir[249] < 0;
        prog_info_ina = (RGE_Prog_Info *)((char *)prog_info_ina + 1);
        if( !((unsigned __int8)(v9 ^ v10) | v8) )
            prog_info_ina = (RGE_Prog_Info *)1;

        this->setScenarioPlayer(v6, v6);
        this->setPlayerColor(v6, 1);
        this->setComputerName(v6, 0);

        *v7 = 0;
        ++v7;
        ++v6;
    }
    while( (signed int)v7 < (signed int)&PalSetRes );

    memset(this->save_humanity, 0, sizeof(this->save_humanity));

    this->setNumberPlayers(4);

    this->resetRandomComputerName();

    if( do_setup ){

        this->setup();

        if( v11 == 0 &&
            this->error_code == ErrorCode::None ){
            this->error_code = ErrorCode::SetupFailed;
        }
    }
}

void TRIBE_Game::close_game_screens( bool close_main_game_screen )
{
#if ENGINE_AOC
    &panel_system->destroyPanel("Full Map Print Dialog");
    &panel_system->destroyPanel("Full Map Print Status Dialog");
#endif
    &panel_system->destroyPanel("Object List Dialog");
    &panel_system->destroyPanel("OKDialog");
    &panel_system->destroyPanel("YesNoDialog");
    &panel_system->destroyPanel("RestartDialog");
    &panel_system->destroyPanel("QuitGameDialog");
    &panel_system->destroyPanel("CloseProgramDialog");
    &panel_system->destroyPanel("QuitAndLoadDialog");
    &panel_system->destroyPanel("ResignDialog");
#if ENGINE_AOC
    &panel_system->destroyPanel("Quit Dialog");
    &panel_system->destroyPanel("New Dialog");
    &panel_system->destroyPanel("Open Dialog");
    &panel_system->destroyPanel("Load Dialog");
    &panel_system->destroyPanel("NewSaveDialog");
    &panel_system->destroyPanel("OpenSaveDialog");
    &panel_system->destroyPanel("QuitSaveDialog");
    &panel_system->destroyPanel("RestartReplayDialog");
    &panel_system->destroyPanel("SessionCancelledOKDialog");
    &panel_system->destroyPanel("Cancel Dialog");
#endif
    &panel_system->destroyPanel("Help Dialog");
    &panel_system->destroyPanel("About Dialog");
    &panel_system->destroyPanel("Send Quick Message Dialog");
    &panel_system->destroyPanel("Mission Dialog");
    &panel_system->destroyPanel("Send Message Dialog");
#if ENGINE_AOC
    &panel_system->destroyPanel("Vote System Dialog");
#endif
    &panel_system->destroyPanel("Diplomacy Dialog");
    &panel_system->destroyPanel("Menu Dialog");
#if ENGINE_AOC
    &panel_system->destroyPanel("Objective Dialog");
#endif
    &panel_system->destroyPanel("Save Game Screen");
    &panel_system->destroyPanel("Load Saved Game Screen");
#if ENGINE_AOC
    &panel_system->destroyPanel("Load Multiplayer Saved Game Screen");
#endif
    &panel_system->destroyPanel("End Screen");
#if ENGINE_AOC
    &panel_system->destroyPanel("Aftermath Screen");
#endif
    &panel_system->destroyPanel("Achievements Screen");
    &panel_system->destroyPanel("Multiplayer Wait Screen");
    &panel_system->destroyPanel("Multiplayer Disconnect Screen");
#if ENGINE_AOC
    &panel_system->destroyPanel("Multiplayer Save Game Screen");
    &panel_system->destroyPanel("One Button Tech Tree Screen");
    &panel_system->destroyPanel("Chat Edit Dialog");
    &panel_system->destroyPanel("Chat Edit Screen");
#endif

    if( close_main_game_screen ){

        this->game_screen = nullptr;

        &panel_system->destroyPanel("Game Screen");
#if ENGINE_AOC
        &panel_system->destroyPanel("Combat Comparison Run Screen");
#endif
    }
}

void TRIBE_Game::setup()
{
    TRIBE_Game *v1; // esi@1
    unsigned __int8 *v2; // edx@7
    unsigned __int8 *v3; // edi@10
    void *v4; // ST20_4@15
    TRIBE_Screen_Status_Message *v5; // eax@16
    IDirectPlay3 *v6; // eax@18
    TribeMPSetupScreen *v7; // eax@19
    int v8; // eax@20
    TRIBE_Screen_Main_Error *v9; // eax@26
    TRIBE_Screen_Main_Error *v10; // eax@27
    HANDLE v11; // edi@32
    HANDLE v12; // edi@34
    TribeMPSetupScreen *v13; // eax@40
    int v14; // eax@45
    int v15; // eax@49
    TEasy_Panel *v16; // eax@50
    int v17; // eax@54
    _SYSTEMTIME file_time; // [sp+10h] [bp-918h]@33

    void *v20; // [sp+3Ch] [bp-8ECh]@16
     // [sp+40h] [bp-8E8h]@7
    _WIN32_FIND_DATAA file_data; // [sp+A4h] [bp-884h]@32
    char cmd_line[256]; // [sp+1E4h] [bp-744h]@7
    char str[1024]; // [sp+2E4h] [bp-644h]@33
     // [sp+6E4h] [bp-244h]@15
    int v26; // [sp+924h] [bp-4h]@16

    if( this->error_code == 0 ){
        return;
    }

    /* Allows RM (Resource-Manager) files to be written into DRS (Dynamic Resources): */
    if( strstr(this->prog_info->cmd_line, "MAKERES") ||
        strstr(this->prog_info->cmd_line, "Makeres") ||
        strstr(this->prog_info->cmd_line, "makeres") ){

        RESFILE_build_res_file("graphics.rm", source_path, this->prog_info->resource_dir);
        RESFILE_build_res_file("sounds.rm",   source_path, this->prog_info->resource_dir);
        RESFILE_build_res_file("interfac.rm", source_path, this->prog_info->resource_dir);
    }

    /* Read DRS files: */
    RESFILE_open_new_resource_file("sounds.drs",   password, this->prog_info->resource_dir, 1);
    RESFILE_open_new_resource_file("graphics.drs", password, this->prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("Interfac.drs", password, this->prog_info->resource_dir, 0);
    RESFILE_open_new_resource_file("sounds.drs",   password, path, 1);
    RESFILE_open_new_resource_file("graphics.drs", password, path, 0);
    RESFILE_open_new_resource_file("Terrain.drs",  password, path, 0);
    RESFILE_open_new_resource_file("Border.drs",   password, path, 0);
    RESFILE_open_new_resource_file("Interfac.drs", password, path, 0);

    if( RGE_Base_Game::setup() ){
        return false;
    }

    strncpy(cmd_line, this->prog_info->cmd_line, 0xFFu);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);
    v2 = _mbsstr((const unsigned __int8 *)cmd_line, aString);
    char new_string_dll_name[100];
    strcpy(new_string_dll_name, "languagex.dll");
    memset(&new_string_dll_name[14], 0, 0x54u);
    *(_WORD *)&new_string_dll_name[98] = 0;
    if( v2 )
    {
        for( ; *v2 != 61; v2 = _mbsninc(v2, 1u) )
            ;
        v3 = _mbsninc(v2, 1u);
        for( new_string_dll_name[0] = 0; !_ismbcspace(*v3); v3 = _mbsninc(v3, 1u) )
        {
            if( !*v3 )
                break;
            _mbsncat((unsigned __int8 *)new_string_dll_name, v3, 1u);
        }
    }
    StringTableX = LoadLibraryA(new_string_dll_name);
    if( StringTableX == nullptr ){
        this->error_code = 1;
        return false;
    }

    PALETTEENTRY pal_entries[7];

    pal_entries[0].peRed   = 23;
    pal_entries[0].peGreen = 39;
    pal_entries[0].peBlue  = 124;
    pal_entries[0].peFlags = 0;
    pal_entries[1].peRed   = 39;
    pal_entries[1].peGreen = 63;
    pal_entries[1].peBlue  = -112;
    pal_entries[1].peFlags = 0;
    pal_entries[2].peRed   = 63;
    pal_entries[2].peGreen = 95;
    pal_entries[2].peBlue  = -97;
    pal_entries[2].peFlags = 0;
    pal_entries[3].peRed   = 87;
    pal_entries[3].peGreen = 123;
    pal_entries[3].peBlue  = -76;
    pal_entries[3].peFlags = 0;
    pal_entries[4].peRed   = 63;
    pal_entries[4].peGreen = 95;
    pal_entries[4].peBlue  = -96;
    pal_entries[4].peFlags = 0;
    pal_entries[5].peRed   = 39;
    pal_entries[5].peGreen = 63;
    pal_entries[5].peBlue  = -111;
    pal_entries[5].peFlags = 0;
    pal_entries[6].peRed   = 23;
    pal_entries[6].peGreen = 39;
    pal_entries[6].peBlue  = 123;
    pal_entries[6].peFlags = 0;

    SetPaletteEntries(this->prog_palette, 0xF8u, 7u, pal_entries);

    this->input_disabled_window = CreateWindowExA(
        0,
        "Static",
        "InputDisabledWindow",
        WS_CHILD,
        0,
        0,
        1,
        1,
        this->prog_window,
        (HMENU)NULL,
        this->prog_info->instance,
        (LPVOID)NULL);

    ICINFO ici;
#if ENGINE_AOC
    video_codec_available = ICInfo("cdiv", "05vi", &ici);
#elif
    video_codec_available = ICInfo("cdiv", "14vi", &ici);
#endif

    if( this->check_prog_argument("Lobby") != true ){

        if( this->comm_handler->LaunchLobbyGame() == (IDirectPlay3 *)1 ){

            this->setMultiplayerGame(1);

            TribeMPSetupScreen *v13 = new TribeMPSetupScreen;

            LABEL_43:
            &panel_system->setCurrentPanel("MP Setup Screen", 0);
            &panel_system->destroyPanel("Status Screen");

            goto LABEL_32;
        }

        int v14;

        if( this->startup_scenario[0] != 0 ){

            v14 = this->start_scenario(this->startup_scenario);

        }else{

            if( this->startup_game[0] == 0 ){

                if( this->prog_info->skip_startup ){
                    this->start_menu();
                    if( !v17 ){
                        return false;
                    }
                }else{
                    this->start_video(0, video_file);
                }

                goto LABEL_32;
            }

            v14 = this->load_game(this->startup_game);
        }

        if( v14 == nullptr ){

            this->start_menu();

            if( !v15 )
                return false;

            if( v16 = panel_system->panel("Main Menu") ){
                v16->popupOKDialog(2401, 0, 450, 100);
            }
        }

        LABEL_32:
        this->set_interface_messages();

        run_log(::str, 0);
        run_log(message_in, 1);

        HANDLE v11 = FindFirstFileA(_pgmptr, &file_data);
        if( v11 != (HANDLE)-1 ){

            *(_DWORD *)&file_time.wYear      = 0;
            *(_DWORD *)&file_time.wDayOfWeek = 0;
            *(_DWORD *)&file_time.wHour      = 0;
            *(_DWORD *)&file_time.wSecond    = 0;

            FileTimeToSystemTime(&file_data.ftLastWriteTime, &file_time);

            sprintf(
                str,
                "program=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d",
                _pgmptr,
                file_data.nFileSizeLow,
                file_time.wMonth,
                file_time.wMonth,
                file_time.wYear,
                file_time.wHour,
                file_time.wMinute,
                file_time.wSecond);

            run_log(str, 0);

            FindClose(v11);
        }

        HANDLE v12 = FindFirstFileA(this->prog_info->game_data_file, &file_data);
        if( v12 != (HANDLE)-1 ){

            *(_DWORD *)&file_time.wYear = 0;
            *(_DWORD *)&file_time.wDayOfWeek = 0;
            *(_DWORD *)&file_time.wHour = 0;
            *(_DWORD *)&file_time.wSecond = 0;

            FileTimeToSystemTime(&file_data.ftLastWriteTime, &file_time);

            sprintf(
                str,
                "data=%s, size=%d, date=%d/%d/%d, time=%d:%d:%d",
                this->prog_info->game_data_file,
                file_data.nFileSizeLow,
                file_time.wMonth,
                file_time.wMonth,
                file_time.wYear,
                file_time.wHour,
                file_time.wMinute,
                file_time.wSecond);

            run_log(str, 0);
            FindClose(v12);
        }

        sprintf(str, "options=%s", this->prog_info->cmd_line);
        run_log(str, 0);

        return false;
    }

    TRIBE_Screen_Status_Message *v5 = new TRIBE_Screen_Status_Message;
    if( v5 ){
        v5->TRIBE_Screen_Status_Message("Status Screen", 1215, aScr1, 50051);
    }

    &panel_system->setCurrentPanel("Status Screen", 0);

    IDirectPlay3 *v6 = this->comm_handler->LaunchLobbyGame();
    if( v6 == (IDirectPlay3 *)1 ){

        this->setMultiplayerGame(1);

        TribeMPSetupScreen *v8 = new TribeMPSetupScreen;
        if( v8 == nullptr ||
            v8->error_code != 0 ){
            return false;
        }
        goto LABEL_43;
    }

    if( v6 != (IDirectPlay3 *)-1 ){
        this->close();
        return false;
    }

    TRIBE_Screen_Main_Error *v10 = new TRIBE_Screen_Main_Error;
    if( v10 &&
        v10->error_code == 0 ){

        v10->set_text(2410);

        &panel_system->setCurrentPanel(aMainErrorScree, 0);
        &panel_system->destroyPanel("Status Screen");

        goto LABEL_32;
    }
}

bool TRIBE_Game::setup_cmd_options()
{
    TRIBE_Game *v1; // ebp@1
    char *v2; // eax@3
    char v3; // cl@5
    char v4; // cl@6
    int v5; // eax@6
    int i; // edx@6
    __int32 v7; // eax@9
    char *v8; // eax@16
    char v9; // cl@18
    char v10; // cl@19
    int v11; // eax@19
    int j; // edx@19
    char *v13; // eax@23
    char v14; // cl@25
    char v15; // cl@26
    int v16; // eax@26
    int k; // edx@26
    char *v18; // eax@30
    char v19; // cl@32
    char v20; // cl@33
    int v21; // eax@33
    int l; // edx@33
    char cmd_line[256]; // [sp+10h] [bp-400h]@1
    char temp_str[256]; // [sp+110h] [bp-300h]@8
    char encstr[512]; // [sp+210h] [bp-200h]@1

    v1 = this;
    strncpy(cmd_line, this->prog_info->cmd_line, 0xFFu);
    cmd_line[255] = 0;
    CharUpperA(cmd_line);
    encrypt_codes(cmd_line, encstr, 512);

    /*  */
    if( strstr(cmd_line, "NOTERRAINSOUND") ){
        *(_DWORD *)&__S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[4] = 1;
    }

    /*  */
    if( strstr(encstr, aLCL) ){

        if( *v2 != 61 )
        {
            do
                v3 = (v2++)[1];
            while( v3 != 61 );
        }
        v4 = v2[1];
        v5 = (int)(v2 + 1);
        for( i = 0; v4 != 32; ++v5 )
        {
            if( !v4 )
                break;
            temp_str[i] = v4;
            v4 = *(_BYTE *)(v5 + 1);
            ++i;
        }
        temp_str[i] = 0;
        v7 = atol(temp_str);
        if( v7 > 25 )
        {
            if( v7 > 200 )
                LOBYTE(v7) = -56;
        }
        else
        {
            LOBYTE(v7) = 25;
        }
        this->setPopLimit(v7);
    }

    /* Command-line check quick-start: */
    if( strstr(cmd_line, TRB_CMD_QUICK_START_MODE) ){
        quick_start_game_mode = 1;
    }

#if DEBUG_RELEASE
    /* Command-line check scenario: */
    if( strstr(cmd_line, TRB_CMD_STARTING_SCENARIO) ){
        if( *v8 != 61 )
        {
            do
                v9 = (v8++)[1];
            while( v9 != 61 );
        }
        v10 = v8[1];
        v11 = (int)(v8 + 1);
        for( j = 0; v10 != 32; ++v11 )
        {
            if( !v10 )
                break;
            this->startup_scenario[j] = v10;
            v10 = *(_BYTE *)(v11 + 1);
            ++j;
        }
        this->startup_scenario[j] = 0;
    }
#endif

#if DEBUG_RELEASE
    /* Command-line check exit: */
    if( strstr(cmd_line, TRB_CMD_AUTO_EXIT) ){
        if( *v13 != 61 )
        {
            do
                v14 = (v13++)[1];
            while( v14 != 61 );
        }
        v15 = v13[1];
        v16 = (int)(v13 + 1);
        for( k = 0; v15 != 32; ++v16 )
        {
            if( !v15 )
                break;
            temp_str[k] = v15;
            v15 = *(_BYTE *)(v16 + 1);
            ++k;
        }
        temp_str[k] = 0;
        this->auto_exit_time = atol(temp_str);
    }
#endif

    /* Command-line, check for save-game by file-name: */
    if( strstr(cmd_line, "GAM=") ){

        if( *v18 != 61 )
        {
            do
                v19 = (v18++)[1];
            while( v19 != 61 );
        }
        v20 = v18[1];
        v21 = (int)(v18 + 1);
        for( l = 0; v20 != 32; ++v21 )
        {
            if( !v20 )
                break;
            this->startup_game[l] = v20;
            v20 = *(_BYTE *)(v21 + 1);
            ++l;
        }
        this->startup_game[l] = 0;
        if( !strchr(this->startup_game, 46) )
            strcpy(&this->startup_game[strlen(this->startup_game)], a_gmx);
    }

    /* call parent method: */
    return RGE_Base_Game::setup_cmd_options();
}

bool TRIBE_Game::setup_palette()
{
    PALETTEENTRY pal_entries[7];

    if( !this->setup_palette() ){
        return false;
    }

    pal_entries[0].peFlags = 0;
    pal_entries[1].peFlags = 0;
    pal_entries[2].peFlags = 0;
    pal_entries[3].peFlags = 0;
    pal_entries[4].peFlags = 0;
    pal_entries[5].peFlags = 0;
    pal_entries[6].peFlags = 0;
    pal_entries[1].peGreen = 63;
    pal_entries[2].peRed   = 63;
    pal_entries[4].peRed   = 63;
    pal_entries[5].peGreen = 63;
    pal_entries[0].peRed   = 23;
    pal_entries[0].peGreen = 39;
    pal_entries[0].peBlue  = 124;
    pal_entries[1].peRed   = 39;
    pal_entries[1].peBlue  = -112;
    pal_entries[2].peGreen = 95;
    pal_entries[2].peBlue  = -97;
    pal_entries[3].peRed   = 87;
    pal_entries[3].peGreen = 123;
    pal_entries[3].peBlue  = -76;
    pal_entries[4].peGreen = 95;
    pal_entries[4].peBlue  = -96;
    pal_entries[5].peRed   = 39;
    pal_entries[5].peBlue  = -111;
    pal_entries[6].peRed   = 23;
    pal_entries[6].peGreen = 39;
    pal_entries[6].peBlue  = 123;

    this->prog_palette->SetPaletteEntries(0xF8u, 7u, pal_entries);

    return true;
}

TDigital **TRIBE_Game::setup_sounds()
{
    TRIBE_Game *v1; // esi@1
    TDigital **result; // eax@1
    signed int i; // eax@2
    TDigital *v4; // eax@4
    TDigital *v5; // eax@5
    TDigital *v6; // eax@7
    int v7; // eax@8
    TDigital *v8; // eax@10
    int v9; // eax@11
    TDigital *v10; // eax@13
    int v11; // eax@14
    TDigital *v12; // eax@16
    int v13; // eax@17
    TDigital *v14; // eax@19
    int v15; // eax@20
    TDigital *v16; // eax@22
    int v17; // eax@23
    TDigital *v18; // eax@25
    int v19; // eax@26
    TDigital *v20; // eax@28
    int v21; // eax@29
    TDigital *v22; // eax@31
    int v23; // eax@32
    TDigital *v24; // eax@34
    int v25; // eax@35
    TDigital *v26; // eax@37
    int v27; // eax@38
    TDigital *v28; // eax@40
    int v29; // eax@41
    TDigital *v30; // eax@43
    int v31; // eax@44
    TDigital *v32; // eax@46
    int v33; // eax@47
    TDigital *v34; // eax@49
    int v35; // eax@50
    TDigital *v36; // eax@52
    int v37; // eax@53
    signed int v38; // edi@55
    TDigital *v39; // ecx@56

    struct SoundSetupInfo
    {
        char *file_name;

        unsigned int res_id;
    }
    sound_setups[] = {
        { "button1.wav",  50300 },
        { "button2.wav",  50301 },
        { "chatrcvd.wav", 50302 },
    };

    if( this->sounds = new TDigital[this->sound_num = sizeof(sound_setups)] ){

        for( i = 0; i < v1->sound_num; v1->sounds[++i - 1] = 0 )
            ;
        v4 = new TDigital(
            this->sound_system,
            sound_setups[i]->);
        if( v4 )
            TDigital::TDigital(v4, v1->sound_system, "button1.wav", 50300);
        else
            v5 = 0;
        *v1->sounds = v5;
        v6 = (TDigital *)operator new(0x3Cu);
        if( v6 )
            TDigital::TDigital(v6, v1->sound_system, "button2.wav", 50301);
        else
            v7 = 0;
        *((_DWORD *)v1->sounds + 1) = v7;
        v8 = (TDigital *)operator new(0x3Cu);
        if( v8 )
            TDigital::TDigital(v8, v1->sound_system, aChatrcvd_wav, 50302);
        else
            v9 = 0;
        *((_DWORD *)v1->sounds + 2) = v9;
        v10 = (TDigital *)operator new(0x3Cu);
        if( v10 )
            TDigital::TDigital(v10, v1->sound_system, aCantdo_wav, 50303);
        else
            v11 = 0;
        *((_DWORD *)v1->sounds + 3) = v11;
        v12 = (TDigital *)operator new(0x3Cu);
        if( v12 )
            TDigital::TDigital(v12, v1->sound_system, aTribute_wav, 50304);
        else
            v13 = 0;
        *((_DWORD *)v1->sounds + 4) = v13;
        v14 = (TDigital *)operator new(0x3Cu);
        if( v14 )
            TDigital::TDigital(v14, v1->sound_system, aResdone_wav, 50305);
        else
            v15 = 0;
        *((_DWORD *)v1->sounds + 5) = v15;
        v16 = (TDigital *)operator new(0x3Cu);
        if( v16 )
            TDigital::TDigital(v16, v1->sound_system, aPkilled_wav, 50306);
        else
            v17 = 0;
        *((_DWORD *)v1->sounds + 6) = v17;
        v18 = (TDigital *)operator new(0x3Cu);
        if( v18 )
            TDigital::TDigital(v18, v1->sound_system, aPdropped_wav, 50307);
        else
            v19 = 0;
        *((_DWORD *)v1->sounds + 7) = v19;
        v20 = (TDigital *)operator new(0x3Cu);
        if( v20 )
            TDigital::TDigital(v20, v1->sound_system, aMstart_wav, 50308);
        else
            v21 = 0;
        *((_DWORD *)v1->sounds + 8) = v21;
        v22 = (TDigital *)operator new(0x3Cu);
        if( v22 )
            TDigital::TDigital(v22, v1->sound_system, aMdone_wav, 50309);
        else
            v23 = 0;
        *((_DWORD *)v1->sounds + 9) = v23;
        v24 = (TDigital *)operator new(0x3Cu);
        if( v24 )
            TDigital::TDigital(v24, v1->sound_system, aMkilled_wav, 50310);
        else
            v25 = 0;
        *((_DWORD *)v1->sounds + 10) = v25;
        v26 = (TDigital *)operator new(0x3Cu);
        if( v26 )
            TDigital::TDigital(v26, v1->sound_system, aArtheld_wav, 50311);
        else
            v27 = 0;
        *((_DWORD *)v1->sounds + 11) = v27;
        v28 = (TDigital *)operator new(0x3Cu);
        if( v28 )
            TDigital::TDigital(v28, v1->sound_system, aArtlost_wav, 50312);
        else
            v29 = 0;
        *((_DWORD *)v1->sounds + 12) = v29;
        v30 = (TDigital *)operator new(0x3Cu);
        if( v30 )
            TDigital::TDigital(v30, v1->sound_system, aConvwarn_wav, 50313);
        else
            v31 = 0;
        *((_DWORD *)v1->sounds + 13) = v31;
        v32 = (TDigital *)operator new(0x3Cu);
        if( v32 )
            TDigital::TDigital(v32, v1->sound_system, aConvdone_wav, 50314);
        else
            v33 = 0;
        *((_DWORD *)v1->sounds + 14) = v33;
        v34 = (TDigital *)operator new(0x3Cu);
        if( v34 )
            TDigital::TDigital(v34, v1->sound_system, aRes_wav, 50315);
        else
            v35 = 0;
        *((_DWORD *)v1->sounds + 15) = v35;
        v36 = (TDigital *)operator new(0x3Cu);
        if( v36 )
            TDigital::TDigital(v36, v1->sound_system, aFarmdie_wav, 50316);
        else
            v37 = 0;
        v38 = 0;
        *((_DWORD *)v1->sounds + 16) = v37;
        do
        {
            v39 = v1->sounds[v38];
            if( v39 )
                TDigital::load(v39, 0, -1);
            ++v38;
        }
        while( v38 < 3 );
        result = (TDigital **)1;
    }
    return result;
}

void TRIBE_Game::create_world()
{
    return new TRIBE_World();
}

void TRIBE_Game::set_game_mode(int new_mode, int new_sub_mode)
{
    this->set_game_mode(new_mode, new_sub_mode);

    if( this->game_screen )
        this->game_screen->game_mode_changed(this->game_mode, this->game_mode);
}

void TRIBE_Game::set_player(short new_player_id)
{
    if( this->world )
        curr_player_id = v3->curr_player;
    else
        curr_player_id = 0;

    this->set_player(new_player_id);

    if( this->world &&
        this->game_screen )
    {
        this->game_screen->player_changed(curr_player_id, this->world->curr_player);
    }
}

void TRIBE_Game::set_save_game_name(char *file_name)
{
    if( file_name )
        strcpy(this->save_game_name, file_name);
    else
        this->save_game_name[0] = 0;
}

void TRIBE_Game::set_load_game_name(char *file_name)
{
    if( file_name )
        strcpy(this->load_game_name, file_name);
    else
        this->load_game_name[0] = 0;
}

char *TRIBE_Game::get_string(int string_id, char *str, int max_len)
{
    if( LoadStringA(StringTableX, string_id, str, max_len) )
    {
        str[max_len - 1] = 0;
        return str;
    }
    else
    {
        return RGE_Base_Game::get_string(string_id, str, max_len);
    }
}

char *TRIBE_Game::get_string2(int string_type, int id, int id2, char *str, int max_len)
{
    char *result; // eax@3

    *str = 0;
    switch( string_type )
    {
        case 100:
            switch( id )
            {
                case 0:
                case 15:
                case 16:
                case 17:
                    result = (char *)(*(int (__stdcall **)(signed int, char *, int))&this->vfptr->gap8[24])(4301, str, max_len);
                    break;
                case 1:
                    result = (char *)(*(int (__stdcall **)(signed int, char *, int))&this->vfptr->gap8[24])(4302, str, max_len);
                    break;
                case 2:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4303, str, max_len);
                    break;
                case 3:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4304, str, max_len);
                    break;
                case 9:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4315, str, max_len);
                    break;
                default:
                    goto LABEL_15;
            }
            return result;
        case 101:
            switch( id )
            {
                case 1:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4201, str, max_len);
                    break;
                case 2:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4202, str, max_len);
                    break;
                case 3:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4203, str, max_len);
                    break;
                case 4:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4204, str, max_len);
                    break;
                default:
                    goto LABEL_15;
            }
            return result;
        case 105:
            switch( id )
            {
                case 1:
                    (*(void (__fastcall **)(TRIBE_Game *, int, signed int, char *, int))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10231,
                        str,
                        max_len);
                    goto LABEL_15;
                case 2:
                    (*(void (__stdcall **)(signed int, char *, int))&this->vfptr->gap8[24])(10232, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 3:
                    (*(void (__fastcall **)(TRIBE_Game *, int, signed int, char *, int))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10233,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 4:
                    (*(void (__stdcall **)(signed int, char *, int))&this->vfptr->gap8[24])(10234, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 5:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10235,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 6:
                    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(10236, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 7:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10237,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 8:
                    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(10238, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 9:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10239,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 10:
                    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(10240, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 11:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10241,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 12:
                    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(10242, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 13:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10246,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 14:
                    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(10247, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 15:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10249,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                case 16:
                    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(10248, str, max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
                default:
                    (*(void (__fastcall **)(_DWORD, _DWORD, signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                        this,
                        id,
                        10244,
                        str,
                        max_len);
                    str[max_len - 1] = 0;
                    result = str;
                    break;
            }
            return result;
        case 102:
            switch( id )
            {
                default:
                    goto LABEL_15;
                case 1:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4101, str, max_len);
                    break;
                case 2:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4102, str, max_len);
                    break;
                case 3:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4103, str, max_len);
                    break;
                case 4:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4104, str, max_len);
                    break;
                case 5:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4105, str, max_len);
                    break;
                case 6:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4106, str, max_len);
                    break;
                case 7:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4107, str, max_len);
                    break;
                case 8:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4108, str, max_len);
                    break;
                case 9:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4109, str, max_len);
                    break;
                case 10:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4110, str, max_len);
                    break;
                case 11:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4111, str, max_len);
                    break;
                case 12:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4112, str, max_len);
                    break;
                case 13:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4113, str, max_len);
                    break;
                case 14:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4114, str, max_len);
                    break;
                case 15:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4115, str, max_len);
                    break;
                case 16:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4116, str, max_len);
                    break;
                case 17:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4117, str, max_len);
                    break;
                case 18:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4118, str, max_len);
                    break;
                case 19:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4119, str, max_len);
                    break;
                case 20:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4120, str, max_len);
                    break;
                case 21:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4121, str, max_len);
                    break;
                case 22:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4122, str, max_len);
                    break;
                case 23:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4123, str, max_len);
                    break;
                case 28:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4124, str, max_len);
                    break;
                case 29:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4125, str, max_len);
                    break;
                case 30:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4126, str, max_len);
                    break;
                case 31:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4127, str, max_len);
                    break;
                case 25:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4128, str, max_len);
                    break;
                case 26:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4129, str, max_len);
                    break;
                case 27:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4130, str, max_len);
                    break;
                case 32:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4133, str, max_len);
                    break;
                case 33:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4134, str, max_len);
                    break;
            }
            return result;
        case 1:
            switch( id )
            {
                case 100:
                case 101:
                case 102:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2401, str, max_len);
                    break;
                case 103:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2402, str, max_len);
                    break;
                case 104:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2403, str, max_len);
                    break;
                case 105:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2404, str, max_len);
                    break;
                case 106:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(2405, str, max_len);
                    break;
                default:
                    result = RGE_Base_Game::get_string2((RGE_Base_Game *)&this->vfptr, string_type, id, id2, str, max_len);
                    break;
            }
            return result;
        case 103:
            if( id <= 101 )
            {
                if( id == 101 )
                    return (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(3006, str, max_len);
                if( id == 1 )
                {
                    switch( id2 )
                    {
                        default:
                            goto LABEL_15;
                        case 4:
                            result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                                 3005,
                                                                 str,
                                                                 max_len);
                            break;
                        case 0:
                            result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                                 3001,
                                                                 str,
                                                                 max_len);
                            break;
                        case 1:
                            result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                                 3002,
                                                                 str,
                                                                 max_len);
                            break;
                        case 2:
                            result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                                 3003,
                                                                 str,
                                                                 max_len);
                            break;
                        case 3:
                            result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                                 3004,
                                                                 str,
                                                                 max_len);
                            break;
                        case 32:
                            result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                                 3046,
                                                                 str,
                                                                 max_len);
                            break;
                    }
                    return result;
                }
LABEL_15:
                str[max_len - 1] = 0;
                return str;
            }
            if( id > 1000 )
                goto LABEL_15;
            if( id == 1000 )
            {
                result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(3010, str, max_len);
            }
            else
            {
                switch( id )
                {
                    case 104:
                        result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                             3009,
                                                             str,
                                                             max_len);
                        break;
                    case 102:
                        result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                             3007,
                                                             str,
                                                             max_len);
                        break;
                    case 103:
                        result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                             3008,
                                                             str,
                                                             max_len);
                        break;
                    case 105:
                        result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                             3011,
                                                             str,
                                                             max_len);
                        break;
                    case 106:
                        result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(
                                                             3018,
                                                             str,
                                                             max_len);
                        break;
                    default:
                        goto LABEL_15;
                }
            }
            return result;
        case 104:
            switch( id )
            {
                case 2:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4305, str, max_len);
                    break;
                case 3:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4306, str, max_len);
                    break;
                case 4:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4307, str, max_len);
                    break;
                case 1:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4308, str, max_len);
                    break;
                case 5:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4309, str, max_len);
                    break;
                case 6:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4310, str, max_len);
                    break;
                case 7:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4311, str, max_len);
                    break;
                case 8:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4312, str, max_len);
                    break;
                case 9:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4313, str, max_len);
                    break;
                case 10:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4314, str, max_len);
                    break;
                case 11:
                    result = (char *)(*(int (__stdcall **)(signed int, _DWORD, _DWORD))&this->vfptr->gap8[24])(4316, str, max_len);
                    break;
                default:
                    goto LABEL_15;
            }
            return result;
        default:
            return RGE_Base_Game::get_string2((RGE_Base_Game *)&this->vfptr, string_type, id, id2, str, max_len);
    }
}

TPanel *TRIBE_Game::get_view_panel()
{
    int v1; // eax@1
    TRIBE_Screen_Game *v2; // ecx@4
    TPanel *result; // eax@5
    TPanel *v4; // eax@7

    v1 = this->prog_mode;
    if( (v1 == 4 || v1 == 6 || v1 == 5) && (v2 = this->game_screen) != 0 )
    {
        result = (TPanel *)&v2->main_view->vfptr;
    }
    else if( v1 == 7 && (v4 = @panel_system->panel(aScenarioEdit_0)) != 0 )
    {
        result = v4[5].previousPanelValue;
    }
    else
    {
        result = 0;
    }
    return result;
}

TPanel *TRIBE_Game::get_map_panel()
{
    int v1; // eax@1
    TRIBE_Screen_Game *v2; // ecx@4
    TPanel *result; // eax@5
    TPanel *v4; // eax@7

    v1 = this->prog_mode;
    if( (v1 == 4 || v1 == 6 || v1 == 5) && (v2 = this->game_screen) != 0 )
    {
        result = (TPanel *)&v2->map_view->vfptr;
    }
    else if( v1 == 7 && (v4 = @panel_system->panel(aScenarioEdit_0)) != 0 )
    {
        result = v4[5].previousModalPanelValue;
    }
    else
    {
        result = 0;
    }
    return result;
}

char *TRIBE_Game::get_save_game_name()
{
    return this->save_game_name;
}

char *TRIBE_Game::get_load_game_name()
{
    return this->load_game_name;
}

void TRIBE_Game::new_scenario_header(int infile)
{
    return new TRIBE_Scenario_Header(infile);
}

void TRIBE_Game::new_scenario_header(RGE_Scenario *scenario_info)
{
    return new TRIBE_Scenario_Header((T_Scenario *)scenario_info);
}

void TRIBE_Game::new_scenario_info(int infile)
{
    return new T_Scenario(infile, 0);
}

void TRIBE_Game::show_error_message(int error_code_in)
{
    TRIBE_Game *v2; // esi@1
    RGE_Base_GameVtbl *v3; // edi@1

    char title[256],
         msg[256];

    v2 = this;
    v3 = this->vfptr;
    (*(void (__stdcall **)(signed int, char *, signed int))&this->vfptr->gap8[24])(4008, title, 256);
    (*(void (**)(TRIBE_Game *, signed int, int, _DWORD, char *, signed int))&v3->gap28[0])(
        v2,
        1,
        error_code_in,
        0,
        msg,
        256);

    MessageBoxA(this->prog_window, msg, title, 0x10u);
}

void TRIBE_Game::show_status_message(char *messageIn, char *info_file, int info_id)
{
    if( TRIBE_Screen_Status_Message *status_message = &panel_system->panel("Status Screen") )
    {
        status_message->set_text(messageIn);

        this->draw_window();
    }
    else
    {
        /* TODO */
        status_message = new TRIBE_Screen_Status_Message("Status Screen", messageIn, info_file, info_id);
    }
    &panel_system->setCurrentPanel("Status Screen", 0);
}

void TRIBE_Game::show_status_message(int string_id, char *info_file, int info_id)
{
    TRIBE_Game *v4; // esi@1
    char str[256];

    v4 = this;
    (*(void (__stdcall **)(int, char *, signed int))&this->vfptr->gap8[24])(string_id, str, 256);
    RGE_Base_Game::show_status_message(str, info_file, info_id);
}

void TRIBE_Game::close_status_message()
{
    &panel_system->restorePreviousPanel(1);
}

int TRIBE_Game::start_video(int video_num, char *video_file)
{
    TRIBE_Game *v3; // esi@1
    void *v4; // eax@1
    char v5; // al@6
    int v6; // edi@9
    char *v7; // eax@10
    HWND v8; // eax@16
    void *v9; // eax@18
    signed int v10; // edi@20
    signed int v11; // eax@20
    int result; // eax@22
    tagRECT video_rect; // [sp+Ch] [bp-178h]@19
    char str[100]; // [sp+1Ch] [bp-168h]@2
    char temp_name[260]; // [sp+80h] [bp-104h]@9

    v3 = this;
    v4 = this->video_window;
    if( v4 )
    {
        SendMessageA(v4, 0x46Au, 0x64u, (LPARAM)str);
        if( str[0] && strcmp(str, aStopped) )
            SendMessageA(v3->video_window, 0x808u, 0, 0);
        SendMessageA(v3->video_window, 0x10u, 0, 0);
        v3->video_window = 0;
    }
    v5 = v3->rge_game_options.multiplayerGameValue;
    v3->cur_video = video_num;
    if( v5 == 1 || !video_file || !*video_file )
        goto LABEL_26;
    sprintf(temp_name, aSS_avi, v3->prog_info->avi_dir, video_file);
    v6 = _open(temp_name, 0, 256);
    if( v6 == -1 )
    {
        v7 = TRegistry::RegGetAscii(v3->registry, 0, aCdpath);
        if( v7 )
        {
            sprintf(temp_name, aSgameAviS_avi, v7, video_file);
            v6 = _open(temp_name, 0, 256);
        }
        if( v6 == -1 )
            goto LABEL_26;
    }
    if( video_codec_available
        && (v3->video_setup || TRIBE_Game::setup_video_system(v3))
        && (v8 = MCIWndCreateA(v3->prog_window, v3->prog_info->instance, 0x50001F0Au, temp_name),
                (v3->video_window = v8) != 0) )
    {
        v3->old_video_wnd_proc = (int (__stdcall *)())GetWindowLongA(v8, -4);
        SetWindowLongA(v3->video_window, -4, (LONG)video_sub_wnd_proc);
        if( !v3->video_hi_color )
        {
            v9 = (void *)SendMessageA(v3->video_window, 0x47Eu, 0, 0);
            TDrawSystem::SetPalette(v3->draw_system, v9);
        }
        GetClientRect(v3->video_window, &video_rect);
        if( v3->video_double_size )
        {
            v10 = 2 * video_rect.right;
            v11 = 2 * video_rect.bottom;
            video_rect.right *= 2;
            video_rect.bottom *= 2;
        }
        else
        {
            v11 = video_rect.bottom;
            v10 = video_rect.right;
        }
        MoveWindow(
            v3->video_window,
            v3->prog_info->main_wid / 2 - v10 / 2,
            v3->prog_info->main_hgt / 2 - v11 / 2,
            v10,
            v11,
            0);
        RGE_Base_Game::set_render_all((RGE_Base_Game *)&v3->vfptr);
        InvalidateRect(v3->prog_window, 0, 1);
        SendMessageA(v3->prog_window, 0xFu, 0, 0);
        TDrawSystem::ClearPrimarySurface(v3->draw_system);
        v3->video_paused = 0;
        v3->last_video_time = debug_timeGetTime();
        SendMessageA(v3->video_window, 0x806u, 0, 0);
        RGE_Base_Game::enable_input((RGE_Base_Game *)&v3->vfptr);
        SetCursor(0);
        SetClassLongA(v3->prog_window, -12, 0);
        result = 1;
    }
    else
    {
LABEL_26:
        TRIBE_Game::stop_video(v3, 1);
        result = 0;
    }
    return result;
}

void TRIBE_Game::stop_video(char goto_next_video)
{
    TRIBE_Game *v2; // esi@1
    void *v3; // eax@1
    int v4; // ecx@1
    TDrawSystem *v5; // ecx@5
    int v6; // eax@11
    char *v7; // eax@15
    char *v8; // edi@15
    TRIBE_Mission_Screen *v9; // eax@20
    TribeAchievementsScreen *v10; // edi@27
    char *v11; // eax@28
    int v12; // eax@28
    TMusic_System *v13; // eax@32
    char v14; // al@33
    int save_vid_num; // [sp+Ch] [bp-74h]@1
    char str[100]; // [sp+10h] [bp-70h]@2
    int v17; // [sp+7Ch] [bp-4h]@20

    v2 = this;
    v3 = this->video_window;
    v4 = this->cur_video;
    save_vid_num = v4;
    v2->cur_video = -1;
    if( v3 )
    {
        SendMessageA(v3, 0x46Au, 0x64u, (LPARAM)str);
        if( str[0] && strcmp(str, aStopped) )
            SendMessageA(v2->video_window, 0x808u, 0, 0);
        SendMessageA(v2->video_window, 0x10u, 0, 0);
        v5 = v2->draw_system;
        v2->video_window = 0;
        TDrawSystem::ClearPrimarySurface(v5);
        TDrawSystem::SetPalette(v2->draw_system, v2->prog_palette);
        RGE_Base_Game::set_render_all((RGE_Base_Game *)&v2->vfptr);
        InvalidateRect(v2->prog_window, 0, 1);
        SendMessageA(v2->prog_window, 0xFu, 0, 0);
        TDrawSystem::ClearPrimarySurface(v2->draw_system);
        v4 = save_vid_num;
    }
    switch( v4 )
    {
        case 0:
            if( !goto_next_video )
                goto LABEL_11;
            TRIBE_Game::start_video(v2, 1, aLogo2);
            return;
        case 1:
            if( !goto_next_video )
                goto LABEL_11;
            TRIBE_Game::start_video(v2, 2, aIntrox);
            return;
        case 2:
        case 5:
LABEL_11:
            TRIBE_Game::start_menu(v2);
            if( !v6 )
                RGE_Base_Game::close((RGE_Base_Game *)&v2->vfptr);
            return;
        case 3:
            if( v2->video_setup )
                TRIBE_Game::shutdown_video_system(v2);
            v7 = RGE_Scenario::Get_description(v2->world->scenario);
            v8 = v7;
            if( v7
                && *v7
                && !RGE_Base_Game::multiplayerGame((RGE_Base_Game *)&v2->vfptr)
                && (!RGE_Base_Game::randomGame((RGE_Base_Game *)&v2->vfptr)
                 || RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr)) )
            {
                v9 = (TRIBE_Mission_Screen *)operator new(0x49Cu);
                v17 = 0;
                if( v9 )
                    TRIBE_Mission_Screen::TRIBE_Mission_Screen(v9, v8, 0, v2->world->scenario->mission_picture);
                v17 = -1;
                TPanelSystem::setCurrentPanel(&panel_system, aMissionDialog, 0);
            }
            else
            {
                TRIBE_Game::create_game_screen(v2);
            }
            return;
        case 4:
            if( v2->video_setup )
                TRIBE_Game::shutdown_video_system(v2);
            if( !v2->world )
                return;
            TRIBE_Game::close_game_screens(v2, 0);
            v10 = (TribeAchievementsScreen *)operator new(0x5F8u);
            v17 = 1;
            if( v10 )
            {
                v11 = TRIBE_Game::game_over_msg(v2);
                TribeAchievementsScreen::TribeAchievementsScreen(v10, v11, 1);
            }
            else
            {
                v12 = 0;
            }
            v17 = -1;
            if( !v12 )
                goto LABEL_43;
            if( *(_DWORD *)(v12 + 216) )
            {
                if( v12 )
                    (**(void (***)(_DWORD, _DWORD))v12)(v12, 1);
LABEL_43:
                TRIBE_Game::quit_game(v2);
                return;
            }
            TPanelSystem::setCurrentPanel(&panel_system, aAchievementsSc, 0);
            v13 = v2->music_system;
            if( v13 )
            {
                v14 = v13->music_type;
                if( v14 == 1 )
                {
                    if( LOBYTE(RGE_Base_Game::get_player((RGE_Base_Game *)&v2->vfptr)->sound_driver) == 1 )
                        TMusic_System::play_track(v2->music_system, 3, 0, 0);
                    else
                        TMusic_System::play_track(v2->music_system, 4, 0, 0);
                }
                else if( v14 == 2 )
                {
                    if( LOBYTE(RGE_Base_Game::get_player((RGE_Base_Game *)&v2->vfptr)->sound_driver) == 1 )
                        TMusic_System::play_file(v2->music_system, file_name_in, 0, 0);
                    else
                        TMusic_System::play_file(v2->music_system, aLost_mid, 0, 0);
                }
            }
            break;
        default:
            return;
    }
}

//----- (00523F10) --------------------------------------------------------
void TRIBE_Game::start_campaign_menu()
{
    TRIBE_Game *v1; // esi@1
    TRIBE_Screen_Campaign_Selection *v2; // eax@3
    int v3; // eax@4
    TMusic_System *v4; // ecx@9
    char v5; // al@11
    char *v6; // [sp-Ch] [bp-20h]@14

    v1 = this;
    if( this->video_setup )
        TRIBE_Game::shutdown_video_system(this);
    v2 = (TRIBE_Screen_Campaign_Selection *)operator new(0x4CCu);
    if( v2 )
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(v2);
    else
        v3 = 0;
    if( v3 )
    {
        if( *(_DWORD *)(v3 + 216) )
        {
            (**(void (***)(_DWORD, _DWORD))v3)(v3, 1);
            return;
        }
        TPanelSystem::setCurrentPanel(&panel_system, aCampaignSelect, 0);
        (*(void (**)(TRIBE_Game *, signed int))&v1->vfptr->gap8[4])(v1, 2);
        v4 = v1->music_system;
        if( v4 )
        {
            if( !v1->started_menu_music )
            {
                v5 = v4->music_type;
                if( v5 == 1 )
                {
                    TMusic_System::play_track(v4, 2, 0, 0);
LABEL_18:
                    v1->started_menu_music = 1;
                    return;
                }
                if( v5 == 2 )
                {
                    v6 = aOpen_mid;
                }
                else
                {
                    if( v5 != 3 )
                        goto LABEL_18;
                    v6 = aOpen_wav;
                }
                TMusic_System::play_file(v4, v6, 0, 0);
                goto LABEL_18;
            }
        }
    }
}

//----- (00524030) --------------------------------------------------------
void TRIBE_Game::start_menu()
{
    TRIBE_Game *v1; // esi@1
    TRIBE_Screen_Main_Menu *v2; // eax@3
    int v3; // eax@4
    TMusic_System *v4; // ecx@9
    char v5; // al@11
    char *v6; // [sp-Ch] [bp-20h]@14

    v1 = this;
    if( this->video_setup )
        TRIBE_Game::shutdown_video_system(this);
    v2 = (TRIBE_Screen_Main_Menu *)operator new(0x4B0u);
    if( v2 )
        TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(v2);
    else
        v3 = 0;
    if( v3 )
    {
        if( *(_DWORD *)(v3 + 216) )
        {
            (**(void (***)(_DWORD, _DWORD))v3)(v3, 1);
            return;
        }
        TPanelSystem::setCurrentPanel(&panel_system, aMainMenu, 0);
        (*(void (**)(TRIBE_Game *, signed int))&v1->vfptr->gap8[4])(v1, 2);
        v4 = v1->music_system;
        if( v4 )
        {
            if( !v1->started_menu_music )
            {
                v5 = v4->music_type;
                if( v5 == 1 )
                {
                    TMusic_System::play_track(v4, 2, 0, 0);
LABEL_18:
                    v1->started_menu_music = 1;
                    return;
                }
                if( v5 == 2 )
                {
                    v6 = aOpen_mid;
                }
                else
                {
                    if( v5 != 3 )
                        goto LABEL_18;
                    v6 = aOpen_wav;
                }
                v4->play_file(v6, 0, 0);
                goto LABEL_18;
            }
        }
    }
}

void TRIBE_Game::quit_game()
{
    TRIBE_Game *v1; // esi@1
    TRIBE_World *v2; // ecx@2
    RGE_Game_World *v3; // eax@7
    RGE_Game_World *v4; // ecx@12
    int v5; // eax@16
    char *v6; // edi@18
    __int32 v7; // eax@19
    int v8; // eax@24
    TribeJoinScreen *v9; // eax@28
    int v10; // [sp-4h] [bp-240h]@19
    char campaign; // [sp+Fh] [bp-22Dh]@1
    char temp_test_scenario[260]; // [sp+14h] [bp-228h]@19
    _finddata_t file_info; // [sp+118h] [bp-124h]@19
    int v14; // [sp+238h] [bp-4h]@28

    v1 = this;
    campaign = 0;
    if( TCommunications_Handler::IsLobbyLaunched(this->comm_handler) )
    {
        v2 = (TRIBE_World *)v1->world;
        if( v2 )
            TRIBE_World::send_zone_score_info(v2);
    }
    TRIBE_Game::disconnect_multiplayer_game(v1);
    v1->prog_mode = 0;
    if( do_debug_random )
    {
        debug_random_write();
        dump_vismap_log();
    }
    if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v1->vfptr) == 1 )
    {
        v3 = v1->world;
        if( v3 )
        {
            if( v3->campaign > -1
                && RGE_Game_Info::set_current_person(v1->player_game_info, v3->campaign_player)
                && RGE_Game_Info::set_current_campaign(v1->player_game_info, v1->world->campaign) )
            {
                campaign = 1;
            }
        }
    }
    v4 = v1->world;
    if( v4 )
        ((void (*)(void))v4->vfptr->del_game_info)();
    if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v1->vfptr) == 1 )
    {
        if( campaign )
        {
            TRIBE_Game::start_campaign_menu(v1);
            if( !v5 )
                this->close();;
        }
        else
        {
            v6 = this->testing_scenario;
            if( this->testing_scenario[0] )
            {
                this->close_game_screens(0);

                this->game_screen = 0;

                &panel_system->destroyPanel("Game Screen");

                sprintf(temp_test_scenario, aSS_scn, this->prog_info->scenario_dir, this->testing_scenario);

                v7 = _findfirst(temp_test_scenario, &file_info);
                v10 = (int)this->testing_scenario;
                if( v7 == -1 )
                    sprintf(temp_test_scenario, aS_scx, v10);
                else
                    sprintf(temp_test_scenario, aS_scn, v10);
                *v6 = 0;
                if( this->start_scenario_editor(temp_test_scenario, 0) )
                {
                    *v6 = 0;

                    return;
                }
            }
            this->start_menu();

            if( !v8 )
                this->close();
        }
    }
    else
    {
        if( this->comm_handler->IsLobbyLaunched() )
        {
            this->close();

            return;
        }
        v9 = (TribeJoinScreen *)operator new(0x4B0u);
        v14 = 0;
        if( v9 )
            v9->TribeJoinScreen();
        v14 = -1;
        &panel_system->setCurrentPanel(aJoinScreen, 0);
        (*(void (**)(TRIBE_Game *, signed int))&this->vfptr->gap8[4])(v1, 2);
    }
    this->close_game_screens(0);

    this->game_screen = 0;

    &panel_system->destroyPanel("Game Screen");

    this->testing_scenario[0] = 0;
}

void TRIBE_Game::restart_game()
{
    TRIBE_Game *v1; // esi@1
    RGE_Game_World *v2; // ecx@1
    signed int v3; // edi@1
    PLAYERHUMANITY *v4; // ebx@1
    __int32 v5; // eax@4
    int v6; // edi@7
    int v7; // ebx@8
    int v8; // eax@15
    TEasy_Panel *v9; // eax@17
    int v10; // [sp-4h] [bp-22Ch]@4
    char temp_name[260]; // [sp+Ch] [bp-21Ch]@4
    _finddata_t fileInfo; // [sp+110h] [bp-118h]@4

    v1 = this;

    this->show_status_message(1105, 0, -1);
    this->lose_game_screens(0);
    this->game_screen = 0;

    &panel_system->destroyPanel(aGameScreen);

    this->prog_mode = 0;

    ((void (*)(void))this->world->del_game_info)();
    int i = 1;
    v4 = (PLAYERHUMANITY *)&this->save_humanity[1];
    do
    {
        this->comm_handler->SetPlayerHumanity(i, *v4);
        ++v4;
    }
    while( ++i < RGE_PLAYERS_COUNT );
    if( this->savedGame() )
    {
        sprintf(temp_name, aSS_gmx, this->prog_info->save_dir, this->load_game_name);
        v5 = _findfirst(temp_name, &fileInfo);
        v10 = this->load_game_name;
        if( v5 == -1 )
            sprintf(temp_name, aS_gam, v10);
        else
            sprintf(temp_name, aS_gmx, v10);
        v6 = this->load_game(temp_name);
    }
    else
    {
        v7 = 0;
        if( this->randomGame() == 1 &&
           !this->campaignGame() )
        {
            v7 = this->random_game_seed;
            this->random_game_seed = this->save_random_game_seed;
        }
        v6 = this->start_game(1);
        if( this->randomGame() &&
           !this->campaignGame() )
        {
            this->random_game_seed = v7;
        }
    }
    if( !v6 )
    {
        this->start_menu();
        if( v8 )
        {
            if( v9 = (TEasy_Panel *)&panel_system->panel(aMainMenu) )
                TEasy_Panel::popupOKDialog(v9, 2401, 0, 450, 100);
        }
        else
        {
            this->close();
        }
    }
}

//----- (00524530) --------------------------------------------------------
int TRIBE_Game::load_db_files()
{
    TRIBE_Game *v1; // esi@1
    RGE_Game_World *v2; // ecx@1
    signed int v3; // edi@1
    int v4; // eax@3
    RGE_Game_World *v5; // ecx@6

    v1 = this;
    RGE_Base_Game::disable_input((RGE_Base_Game *)&this->vfptr);
    TRIBE_Game::show_status_message(v1, 1101, 0, -1);
    v2 = v1->world;
    v3 = 0;
    if( v2 )
    {
        ((void (__stdcall *)(signed int))v2->vfptr->~RGE_Game_World)(1);
        v1->world = 0;
    }
    v4 = (int)v1->vfptr->create_world((RGE_Base_Game *)v1);
    v1->world = (RGE_Game_World *)v4;
    if( v4 )
    {
        if( (unsigned __int8)(*(int (**)(int, int, int))(*(_DWORD *)v4 + 172))(
                                                        v4,
                                                        (int)v1->prog_info->game_data_file,
                                                        (int)v1->prog_info->world_db_file) )
            v3 = 1;
        v5 = v1->world;
        if( v5 )
            ((void (__stdcall *)(signed int))v5->vfptr->~RGE_Game_World)(1);
        v1->world = 0;
    }
    TRIBE_Game::close_status_message();
    RGE_Base_Game::enable_input((RGE_Base_Game *)&v1->vfptr);
    return v3;
}

//----- (005245D0) --------------------------------------------------------
RGE_Game_World *TRIBE_Game::load_game_data()
{
    TRIBE_Game *v1; // esi@1
    RGE_Game_World *result; // eax@2
    RGE_Game_World *v3; // ecx@4

    v1 = this;
    if( this->world )
        goto LABEL_10;
    result = (RGE_Game_World *)((int (*)(void))this->vfptr->create_world)();
    v1->world = result;
    if( !result )
        return result;
    if( result->vfptr->init(result, v1->prog_info->game_data_file, v1->sound_system, v1->comm_handler) )
    {
LABEL_10:
        result = (RGE_Game_World *)1;
    }
    else
    {
        v3 = v1->world;
        if( v3 )
            ((void (__stdcall *)(signed int))v3->vfptr->~RGE_Game_World)(1);
        v1->world = 0;
        result = 0;
    }
    return result;
}

//----- (00524640) --------------------------------------------------------
int TRIBE_Game::save_game(char *fileName)
{
    TRIBE_Game *v2; // ebx@1
    int v3; // eax@1
    int result; // eax@5
    char v5; // al@8
    char *v6; // eax@10
    char fileNameNoExt[260]; // [sp+10h] [bp-104h]@10

    v2 = this;
    v3 = this->prog_mode;
    if( v3 == 4 || v3 == 6 || v3 == 7 || v3 == 5 )
    {
        RGE_Base_Game::disable_input((RGE_Base_Game *)&this->vfptr);
        TRIBE_Game::show_status_message(v2, 1107, 0, -1);
        if( RGE_Base_Game::check_prog_argument((RGE_Base_Game *)&v2->vfptr, aDebugsavegame) )
            ENABLE_COMPRESSION = 0;
        v5 = ((int (__stdcall *)(char *))v2->world->vfptr->save_game)(fileName);
        ENABLE_COMPRESSION = 1;
        if( v5 )
        {
            strcpy(fileNameNoExt, fileName);
            v6 = strchr(fileNameNoExt, 46);
            if( v6 )
                *v6 = 0;
            TRIBE_Game::set_save_game_name(v2, fileNameNoExt);
            if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v2->vfptr) == 1 )
                RGE_Base_Game::set_paused((RGE_Base_Game *)&v2->vfptr, 0, 0);
            TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
            &panel_system->destroyPanel(aSaveGameScreen);
            &panel_system->destroyPanel("Status Screen");
            RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
            result = 1;
        }
        else
        {
            TRIBE_Game::close_status_message();
            RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}
// 585A6C: using guessed type int ENABLE_COMPRESSION;

//----- (00524790) --------------------------------------------------------
int TRIBE_Game::save_scenario(char *fileName)
{
    TRIBE_Game *v2; // edi@1
    int v3; // eax@1
    int result; // eax@5
    RGE_Game_World *v5; // eax@6
    signed int i; // esi@6

    v2 = this;
    v3 = this->prog_mode;
    if( v3 == 4 || v3 == 6 || v3 == 7 || v3 == 5 )
    {
        RGE_Base_Game::disable_input((RGE_Base_Game *)&this->vfptr);
        TRIBE_Game::show_status_message(v2, 1104, 0, -1);
        v5 = v2->world;
        for( i = 1; i < v5->player_num; ++i )
        {
            RGE_Scenario::Set_player_Active(v5->scenario, i - 1, 1);
            v5 = v2->world;
        }
        if( (unsigned __int8)((int (__stdcall *)(char *))v2->world->vfptr->save_scenario)(fileName) )
        {
            if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v2->vfptr) == 1 )
                RGE_Base_Game::set_paused((RGE_Base_Game *)&v2->vfptr, 0, 0);
            TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
            &panel_system->destroyPanel(aSaveGameScreen);
            &panel_system->destroyPanel("Status Screen");
            RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
            result = 1;
        }
        else
        {
            RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

void TRIBE_Game::calc_timing_text()
{
    TRIBE_Game *v1; // ebx@1
    unsigned int v2; // ecx@3
    unsigned int v3; // ecx@8

    v1 = this;
    if( !(__S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[0] & 1) )
    {
        __S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[0] |= 1u;
        *(_DWORD *)&__S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[8] = debug_timeGetTime();
    }
    *(_DWORD *)&__S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[8] = debug_timeGetTime();
    v2 = v1->world_update_count;
    if( v2 )
    {
        if( show_timing_max )
            sprintf(
                v1->timing_text2,
                aTLuFLuMaxRVLuM,
                v1->world_update_fps,
                v1->view_update_fps,
                v1->timings[6].last_max_time,
                v1->timings[7].last_max_time,
                v1->timings[17].last_max_time,
                v1->timings[3].last_max_time,
                v1->timings[1].last_max_time,
                v1->timings[14].last_max_time,
                v1->timings[10].last_max_time,
                v1->timings[12].last_max_time,
                v1->timings[13].last_max_time,
                v1->timings[4].last_max_time);
        else
            sprintf(
                v1->timing_text2,
                aTLuFLuAvgRVLuM,
                v1->world_update_fps,
                v1->view_update_fps,
                v1->timings[6].last_time / v2,
                v1->timings[7].last_time / v2,
                v1->timings[17].last_time / v2,
                v1->timings[3].last_time / v2,
                v1->timings[1].last_time / v2,
                v1->timings[14].last_time / v2,
                (v1->timings[12].last_time + v1->timings[10].last_time) / v2,
                v1->timings[13].last_time / v2,
                v1->timings[4].last_time / v2);
    }
    else
    {
        strcpy(v1->timing_text2, aF_);
    }
    v3 = v1->view_update_count;
    if( v3 )
        sprintf(v1->timing_text, aAvgViewTimeLuC, v1->timings[6].last_time / v3, v1->view_update_count);
    else
        strcpy(v1->timing_text, aAvgViewTime___);
}

void TRIBE_Game::show_timings()
{
    if( this->game_screen )
        this->game_screen->show_timings(this->timing_text, this->timing_text2);
}

void TRIBE_Game::show_comm()
{
    if( this->game_screen )
    {
        this->game_screen->show_comm(
            this->comm_handler->GetCommInfo(1),
            this->comm_handler->GetCommInfo(2),
            this->comm_handler->GetCommInfo(3),
            this->comm_handler->GetCommInfo(4),
            this->comm_handler->GetCommInfo(5),
            this->comm_handler->GetCommInfo(6));
    }
}

void TRIBE_Game::show_ai()
{
    TRIBE_Game *v1; // ebx@1
    RGE_Game_World *v2; // eax@1
    RGE_Player **v3; // ecx@1
    bool v4; // zf@2
    RGE_PlayerVtbl *v5; // eax@2
    int v6; // eax@3
    signed int v7; // ebx@6
    char *v8; // ebp@6
    int v9; // eax@7
    char *v10; // edx@7
    const char *v11; // edi@7
    TRIBE_Game *v12; // [sp+10h] [bp-604h]@1
    char str[6][256]; // [sp+14h] [bp-600h]@4

    v1 = this;
    v2 = this->world;
    v12 = this;
    v3 = v2->players;
    if( v3 )
    {
        v4 = RGE_Player::computerPlayer(v3[v2->curr_player]) == 1;
        v5 = v1->world->players[v1->world->curr_player]->vfptr;
        if( v4 )
        {
            v6 = (*(int (__stdcall **)(signed int))&v5->gap4[16])(1);
            if( v6 )
                sprintf((char *)str, aPlayerDS, v1->world->curr_player, v6);
            else
                sprintf((char *)str, aPlayerDAiIsNot, v1->world->curr_player);
            v7 = 2;
            v8 = str[2];
            do
            {
                v9 = (*(int (__stdcall **)(signed int))&v12->world->players[v12->world->curr_player]->vfptr->gap4[16])(v7);
                v10 = v8 - 256;
                v11 = message_in;
                if( v9 )
                    v11 = (const char *)v9;
                v8 += 256;
                strcpy(v10, v11);
                ++v7;
            }
            while( v7 <= 6 );
            v1 = v12;
        }
        else
        {
            strcpy((char *)str, (const char *)(*(int (__stdcall **)(_DWORD))&v5->gap4[16])(0));
            sprintf(str[1], aPlayerDIsNotAC, v1->world->curr_player);
            strcpy(str[2], message_in);
            strcpy(str[3], message_in);
            strcpy(str[4], message_in);
            strcpy(str[5], message_in);
        }
        if( v1->game_screen )
        {
            if( RGE_Player::computerPlayer(v1->world->players[v1->world->curr_player]) == 1 )
                TRIBE_Screen_Game::show_ai(v1->game_screen, str[5], str[4], str[3], str[2], str[1], (char *)str);
            else
                TRIBE_Screen_Game::show_ai(v1->game_screen, (char *)str, str[1], str[2], str[3], str[4], str[5]);
        }
    }
}

void TRIBE_Game::notification(int notify_type, int val1, int val2, int val3, int val4)
{
    TRIBE_Game *v6; // esi@1
    TRIBE_Screen_Game *v7; // ecx@6
    RGE_Base_GameVtbl *v8; // edx@10
    TRIBE_Screen_Game *v9; // ecx@20
    RGE_Base_GameVtbl *v10; // edx@28
    int v11; // eax@43
    int v12; // edi@44
    RGE_Base_GameVtbl *v13; // edx@47
    RGE_Base_GameVtbl *v14; // edx@59
    TRIBE_Screen_Game *v15; // ecx@65
    RGE_Base_GameVtbl *v16; // edx@73
    RGE_Game_World *v17; // eax@78
    RGE_Player *v18; // edi@80
    RGE_Game_World *v19; // eax@83
    RGE_Player **v20; // ecx@83
    RGE_Player *v21; // ebx@83
    RGE_Player *v22; // edi@83
    RGE_Base_GameVtbl *v23; // edx@91
    char *v24; // ecx@92
    RGE_Game_World *v25; // eax@98
    RGE_Player **v26; // ecx@98
    RGE_Player *v27; // edi@98
    RGE_Player *v28; // ebx@98
    RGE_Game_World *v29; // eax@109
    RGE_Player **v30; // ecx@109
    RGE_Player *v31; // ebx@109
    RGE_Player *v32; // edi@109
    RGE_Base_GameVtbl *v33; // edx@116
    RGE_Game_World *v34; // eax@120
    signed int i; // edi@120
    RGE_Base_GameVtbl *v36; // eax@125
    RGE_Game_World *v37; // eax@127
    RGE_Player **v38; // ecx@127
    RGE_Player *v39; // ebx@127
    RGE_Player *v40; // edi@127
    RGE_Base_GameVtbl *v41; // edx@134
    RGE_Game_World *v42; // eax@138
    signed int j; // edi@138
    RGE_Base_GameVtbl *v44; // edx@148
    int v45; // eax@163
    signed int v46; // [sp-8h] [bp-21Ch]@10
    signed int v47; // [sp-8h] [bp-21Ch]@28
    int v48; // [sp-4h] [bp-218h]@10
    signed int v49; // [sp-4h] [bp-218h]@48
    signed int v50; // [sp-4h] [bp-218h]@60
    signed int v51; // [sp-4h] [bp-218h]@73
    signed int v52; // [sp-4h] [bp-218h]@116
    signed int v53; // [sp-4h] [bp-218h]@125
    signed int v54; // [sp-4h] [bp-218h]@134
    signed int v55; // [sp-4h] [bp-218h]@148
    char *v56; // [sp+0h] [bp-214h]@10
    char *v57; // [sp+0h] [bp-214h]@28
    char *v58; // [sp+0h] [bp-214h]@47
    char *v59; // [sp+0h] [bp-214h]@59
    char *v60; // [sp+0h] [bp-214h]@73
    char *v61; // [sp+0h] [bp-214h]@91
    char *v62; // [sp+0h] [bp-214h]@116
    char *v63; // [sp+0h] [bp-214h]@125
    char *v64; // [sp+0h] [bp-214h]@134
    char *v65; // [sp+0h] [bp-214h]@148
    char msg[256]; // [sp+14h] [bp-200h]@10
    char temp_str[256]; // [sp+114h] [bp-100h]@43

    v6 = this;
    switch( notify_type )
    {
        case 126:
            if( val1 == this->world->curr_player )
            {
                if( this->game_screen )
                {
                    this->play_sound(16);
                    TRIBE_Game::add_notification_loc(v6, val3, val4);
                }
            }
            return;

        case 124:
            if( val1 == this->world->curr_player )
            {
                v7 = this->game_screen;
                if( v7 )
                    TRIBE_Screen_Game::setup_buttons(v7);
            }
            return;

        case 125:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                v8 = this->vfptr;
                v56 = msg;
                v48 = val2;
                v46 = 1;
                goto LABEL_25;
            }
            return;

        case 100:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                switch( val2 )
                {
                    case 101:
                    case 102:
                    case 103:
                        this->play_sound(5);
                        break;

                    default:
                        this->play_sound(15);
                }
                this->game_screen->setup_buttons();
                this->add_notification_loc(val3, val4);
            }
            return;

        case 102:
        case 105:
            if( val1 == this->world->curr_player )
            {
                v9 = this->game_screen;
                if( v9 )
                {
                    TRIBE_Screen_Game::setup_buttons(v9);
                    TRIBE_Game::add_notification_loc(v6, val3, val4);
                }
            }
            return;

        case 104:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v8 = v6->vfptr;
                v56 = msg;
                v48 = val2;
                v46 = 1000;
LABEL_25:
                (*(void (**)(TRIBE_Game *, signed int, signed int, int, char *, signed int))&v8->gap28[0])(
                    v6,
                    103,
                    v46,
                    v48,
                    v56,
                    256);
                TRIBE_Screen_Game::show_message(v6->game_screen, BadMessage, msg, 85, 0);
            }
            return;

        case 107:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v10 = v6->vfptr;
                v57 = msg;
                v47 = 106;
                goto LABEL_38;
            }
            return;

        case 1:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v10 = v6->vfptr;
                v57 = msg;
                v47 = 102;
                goto LABEL_38;
            }
            return;

        case 3:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v10 = v6->vfptr;
                v57 = msg;
                v47 = 105;
                goto LABEL_38;
            }
            return;

        case 2:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v10 = v6->vfptr;
                v57 = msg;
                v47 = 103;
LABEL_38:
                (*(void (**)(TRIBE_Game *, signed int, signed int, _DWORD, char *, signed int))&v10->gap28[0])(
                    v6,
                    103,
                    v47,
                    0,
                    v57,
                    256);
                TRIBE_Screen_Game::show_message(v6->game_screen, BadMessage, msg, 85, 0);
            }
            return;

        case 4:
            if( RGE_Base_Game::playerID((RGE_Base_Game *)&this->vfptr, val1) != this->world->curr_player )
            {
                if( v6->game_screen )
                {
                    if( !(&player_dropped)[val1] )
                    {
                        (&player_dropped)[val1] = (int *)1;
                        RGE_Base_Game::play_sound((RGE_Base_Game *)&v6->vfptr, 7);
                        if( RGE_Base_Game::playerID((RGE_Base_Game *)&v6->vfptr, val1) > 0 )
                        {
                            (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                                v6,
                                3012,
                                temp_str,
                                256);
                            v11 = RGE_Base_Game::playerID((RGE_Base_Game *)&v6->vfptr, val1);
                            sprintf(msg, temp_str, v6->world->players[v11]->name);
                            TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
                        }
                    }
                }
            }
            return;

        case 5:
            v12 = val1;
            if( val1 != this->world->curr_player && this->game_screen && val1 > 0 )
            {
                this->play_sound(6);
                v13 = v6->vfptr;
                v58 = temp_str;
                if( val2 )
                {
                    v49 = 3012;
                    goto LABEL_54;
                }
                (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v13->gap8[24])(v6, 3013, temp_str, 256);
                sprintf(msg, temp_str, v6->world->players[val1]->name);
                TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
            }
            return;

        case 6:
            v12 = val1;
            if( val1 != this->world->curr_player )
            {
                if( this->game_screen )
                {
                    this->play_sound(6);
                    if( val1 > 0 )
                    {
                        v13 = v6->vfptr;
                        v58 = temp_str;
                        v49 = 3014;
LABEL_54:
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v13->gap8[24])(v6, v49, v58, 256);
                        sprintf(msg, temp_str, v6->world->players[v12]->name);
                        TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
                    }
                }
            }
            return;

        case 7:
            if( val2 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(4);
                if( val3 )
                {
                    if( val3 == 1 )
                    {
                        v14 = v6->vfptr;
                        v59 = temp_str;
                        v50 = 3015;
                    }
                    else
                    {
                        v14 = v6->vfptr;
                        v59 = temp_str;
                        if( val3 == 3 )
                            v50 = 3009;
                        else
                            v50 = 3017;
                    }
                }
                else
                {
                    v14 = v6->vfptr;
                    v59 = temp_str;
                    v50 = 3016;
                }
                (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v14->gap8[24])(v6, v50, v59, 256);
                sprintf(msg, temp_str, v6->world->players[val1]->name, val4);
                TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
            }
            return;

        case 8:
            v15 = this->game_screen;
            if( v15 )
                TRIBE_Screen_Game::reset_clocks(v15);
            if( val2 != v6->world->curr_player || !v6->game_screen )
                return;
            if( val3 )
            {
                if( val3 != 1 )
                {
                    if( val3 == 3 )
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                            v6,
                            3027,
                            temp_str,
                            256);
                    goto LABEL_76;
                }
                v16 = v6->vfptr;
                v60 = temp_str;
                v51 = 3025;
            }
            else
            {
                v16 = v6->vfptr;
                v60 = temp_str;
                v51 = 3026;
            }
            (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v16->gap8[24])(v6, v51, v60, 256);
LABEL_76:
            sprintf(msg, temp_str, v6->world->players[val1]->name);
            TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
            return;

        case 108:
            if( this->game_screen )
            {
                this->play_sound(8);
                v17 = v6->world;
                if( val1 == v17->curr_player )
                {
                    (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                        v6,
                        3058,
                        msg,
                        256);
                    TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
                }
                else
                {
                    v18 = v17->players[val1];
                    (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                        v6,
                        3019,
                        temp_str,
                        256);
                    sprintf(msg, temp_str, v18->name);
                    TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
                }
                TRIBE_Game::add_notification_loc(v6, val2, val3);
            }
            return;

        case 109:
            if( this->game_screen )
            {
                this->play_sound(9);
                v19 = v6->world;
                v20 = v19->players;
                v21 = v20[val1];
                v22 = v20[v19->curr_player];
                if( v21 == v22 )
                {
                    if( v19[1].world_time )
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                            v6,
                            3054,
                            msg,
                            256);
                    else
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                            v6,
                            3020,
                            msg,
                            256);
                    goto LABEL_107;
                }
                if( !v21->allied_victory
                    || RGE_Player::relation(v21, v22->id)
                    || !v22->allied_victory
                    || RGE_Player::relation(v22, v21->id) )
                {
                    v23 = v6->vfptr;
                    v61 = temp_str;
                    if( !v6->world[1].world_time )
                    {
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v23->gap8[24])(
                            v6,
                            3022,
                            temp_str,
                            256);
                        v24 = v21->name;
                        goto LABEL_106;
                    }
                }
                else
                {
                    v23 = v6->vfptr;
                    v61 = temp_str;
                    if( !v6->world[1].world_time )
                    {
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v23->gap8[24])(
                            v6,
                            3021,
                            temp_str,
                            256);
                        v24 = v21->name;
                        goto LABEL_106;
                    }
                }
                (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v23->gap8[24])(v6, 3055, v61, 256);
                v24 = v21->name;
                goto LABEL_106;
            }
            return;

        case 110:
            if( this->game_screen && !this->world[1].world_time )
            {
                this->play_sound(10);
                v25 = v6->world;
                v26 = v25->players;
                v27 = v26[val1];
                v28 = v26[v25->curr_player];
                if( v27 == v28 )
                {
                    (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                        v6,
                        3023,
                        msg,
                        256);
                }
                else if( !v27->allied_victory
                             || RGE_Player::relation(v27, v28->id)
                             || !v28->allied_victory
                             || RGE_Player::relation(v28, v27->id) )
                {
                    (*(void (**)(_DWORD, signed int, _DWORD, _DWORD))&v6->vfptr->gap8[24])(v6, 3024, temp_str, 256);
                    v24 = v27->name;
LABEL_106:
                    sprintf(msg, temp_str, v24);
                }
                else
                {
                    (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v6->vfptr->gap8[24])(
                        v6,
                        3024,
                        temp_str,
                        256);
                    sprintf(msg, temp_str, v27->name);
                }
LABEL_107:
                TRIBE_Game::add_notification_loc(v6, val2, val3);
                TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
                goto LABEL_145;
            }
            return;

        case 114:
            if( !this->game_screen )
                return;
            this->play_sound(11);
            v29 = v6->world;
            v30 = v29->players;
            v31 = v30[val1];
            v32 = v30[v29->curr_player];
            if( v29[1].world_time )
            {
                v33 = v6->vfptr;
                v62 = msg;
                v52 = 3056;
            }
            else
            {
                if( v31 == v32 )
                {
                    (*(void (**)(_DWORD, signed int, _DWORD, _DWORD))&v6->vfptr->gap8[24])(v6, 3028, msg, 256);
                    goto LABEL_120;
                }
                if( !v31->allied_victory
                    || RGE_Player::relation(v31, v32->id)
                    || !v32->allied_victory
                    || RGE_Player::relation(v32, v31->id) )
                {
                    v33 = v6->vfptr;
                    v62 = msg;
                    v52 = 3029;
                }
                else
                {
                    v33 = v6->vfptr;
                    v62 = msg;
                    v52 = 3028;
                }
            }
            (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v33->gap8[24])(v6, v52, v62, 256);
LABEL_120:
            TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
            TRIBE_Screen_Game::reset_clocks(v6->game_screen);
            v34 = v6->world;
            for( i = 1; i < v34->player_num; ++i )
            {
                ((void (__stdcall *)(_DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD))v34->players[i]->vfptr->notify)(
                    v31->id,
                    i,
                    114,
                    0,
                    0,
                    0);
                v34 = v6->world;
            }
            return;

        case 115:
            if( this->game_screen && !this->world[1].world_time )
            {
                this->play_sound(12);
                v36 = v6->vfptr;
                v63 = msg;
                v53 = 3030;
                goto LABEL_144;
            }
            return;

        case 116:
            if( !this->game_screen )
                return;
            this->play_sound(11);
            v37 = v6->world;
            v38 = v37->players;
            v39 = v38[val1];
            v40 = v38[v37->curr_player];
            if( v37[1].world_time )
            {
                v41 = v6->vfptr;
                v64 = msg;
                v54 = 3057;
            }
            else
            {
                if( v39 == v40 )
                {
                    (*(void (**)(_DWORD, signed int, _DWORD, _DWORD))&v6->vfptr->gap8[24])(v6, 3033, msg, 256);
                    goto LABEL_138;
                }
                if( !v39->allied_victory
                    || RGE_Player::relation(v39, v40->id)
                    || !v40->allied_victory
                    || RGE_Player::relation(v40, v39->id) )
                {
                    v41 = v6->vfptr;
                    v64 = msg;
                    v54 = 3034;
                }
                else
                {
                    v41 = v6->vfptr;
                    v64 = msg;
                    v54 = 3033;
                }
            }
            (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v41->gap8[24])(v6, v54, v64, 256);
LABEL_138:
            TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
            TRIBE_Screen_Game::reset_clocks(v6->game_screen);
            v42 = v6->world;
            for( j = 1; j < v42->player_num; ++j )
            {
                ((void (__stdcall *)(_DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD))v42->players[j]->vfptr->notify)(
                    v39->id,
                    j,
                    116,
                    0,
                    0,
                    0);
                v42 = v6->world;
            }
            return;

        case 117:
            if( this->game_screen && !this->world[1].world_time )
            {
                this->play_sound(12);
                v36 = v6->vfptr;
                v63 = msg;
                v53 = 3035;
LABEL_144:
                (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v36->gap8[24])(v6, v53, v63, 256);
                TRIBE_Screen_Game::display_system_message(v6->game_screen, msg);
LABEL_145:
                TRIBE_Screen_Game::reset_clocks(v6->game_screen);
            }
            return;

        case 118:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v44 = v6->vfptr;
                v65 = msg;
                v55 = 3047;
                goto LABEL_161;
            }
            return;

        case 119:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v44 = v6->vfptr;
                v65 = msg;
                v55 = 3048;
                goto LABEL_161;
            }
            return;

        case 120:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v44 = v6->vfptr;
                v65 = msg;
                v55 = 3049;
                goto LABEL_161;
            }
            return;

        case 121:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v44 = v6->vfptr;
                v65 = msg;
                v55 = 3050;
                goto LABEL_161;
            }
            return;

        case 122:
            if( val1 == this->world->curr_player && this->game_screen )
            {
                this->play_sound(3);
                v44 = v6->vfptr;
                v65 = msg;
                v55 = 3051;
LABEL_161:
                (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v44->gap8[24])(v6, v55, v65, 256);
                TRIBE_Screen_Game::show_message(v6->game_screen, BadMessage, msg, 85, 0);
            }
            return;

        case 123:
            if( this->game_screen )
            {
                v45 = this->world->curr_player;
                if( val1 != v45 && val2 == v45 )
                    this->play_sound(13);
            }
            return;

        default:
            return;
    }
}
// 86BCA8: using guessed type int *player_dropped;

//----- (00525D20) --------------------------------------------------------
int TRIBE_Game::start_game(int skip_startup_screens)
{
    TRIBE_Game *v2; // ebx@1
    int v3; // esi@2
    int result; // eax@7
    char info_file[256]; // [sp+Ch] [bp-100h]@2

    v2 = this;
    if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&this->vfptr) )
    {
        strcpy(info_file, aScr2);
        v3 = 50052;
    }
    else
    {
        strcpy(info_file, info_file_name_in);
        v3 = 50053;
    }
    RGE_Base_Game::disable_input((RGE_Base_Game *)&v2->vfptr);
    if( (v2->world || (TRIBE_Game::show_status_message(v2, 1101, info_file, v3), TRIBE_Game::load_game_data(v2)))
        && (TRIBE_Game::show_status_message(v2, 1105, info_file, v3), TRIBE_Game::create_game(v2, 0)) )
    {
        TRIBE_Game::set_save_game_name(v2, 0);
        TRIBE_Game::set_load_game_name(v2, 0);
        if( skip_startup_screens )
        {
            result = TRIBE_Game::create_game_screen(v2);
        }
        else
        {
            TRIBE_Game::start_video(v2, 3, v2->world->scenario->Cine_PreGame);
            result = 1;
        }
    }
    else
    {
        TRIBE_Game::close_status_message();
        RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
        result = 0;
    }
    return result;
}

//----- (00525E50) --------------------------------------------------------
int TRIBE_Game::test_scenario(char *scenario_file)
{
    TRIBE_Game *v2; // ebx@1
    int result; // eax@2
    int v4; // eax@4

    v2 = this;
    strcpy(this->testing_scenario, scenario_file);
    &panel_system->destroyPanel(aScenarioEdit_0);
    (*(void (**)(TRIBE_Game *, _DWORD))&v2->vfptr->gap8[4])(v2, 0);
    if( TRIBE_Game::start_scenario(v2, (int)v2->testing_scenario, v2->testing_scenario) )
    {
        result = 1;
    }
    else
    {
        if( !TRIBE_Game::start_scenario_editor(v2, v2->testing_scenario, 0) )
        {
            TRIBE_Game::start_menu(v2);
            if( !v4 )
                RGE_Base_Game::close((RGE_Base_Game *)&v2->vfptr);
        }
        result = 0;
    }
    return result;
}

//----- (00525EE0) --------------------------------------------------------
int __userpurge TRIBE_Game::start_scenario@<eax>(TRIBE_Game *this@<ecx>, int a2@<ebp>, char *scenario_file)
{
    TRIBE_Game *v3; // esi@1
    int v4; // eax@1
    int v5; // ebx@1
    RGE_Scenario *v6; // ebp@4
    int result; // eax@5
    int v8; // edi@6
    int v9; // eax@8
    int v10; // edi@15
    int v11; // eax@19
    signed int i; // edi@21
    signed int j; // ebx@23
    signed int first_any_player; // [sp+10h] [bp-220h]@1
    char scenario_file2[260]; // [sp+14h] [bp-21Ch]@1
    _finddata_t file_info; // [sp+118h] [bp-118h]@1

    v3 = this;
    RGE_Base_Game::disable_input((RGE_Base_Game *)&this->vfptr);
    RGE_Base_Game::setSinglePlayerGame((RGE_Base_Game *)&v3->vfptr, 1);
    RGE_Base_Game::setCampaignGame((RGE_Base_Game *)&v3->vfptr, 0);
    RGE_Base_Game::setSavedGame((RGE_Base_Game *)&v3->vfptr, 0);
    RGE_Base_Game::setScenarioGame((RGE_Base_Game *)&v3->vfptr, 1);
    RGE_Base_Game::setScenarioName((RGE_Base_Game *)&v3->vfptr, scenario_file);
    TRIBE_Game::setVictoryType(v3, 0, 0);
    RGE_Base_Game::setFullVisibility((RGE_Base_Game *)&v3->vfptr, 0);
    RGE_Base_Game::setFogOfWar((RGE_Base_Game *)&v3->vfptr, 1);
    RGE_Base_Game::setAllowCheatCodes((RGE_Base_Game *)&v3->vfptr, 1);
    TRIBE_Game::setRandomizePositions(v3, 0);
    TRIBE_Game::setLongCombat(v3, 0);
    TRIBE_Game::setAllowTrading(v3, 1);
    TRIBE_Game::setFullTechTree(v3, 0);
    TRIBE_Game::setResourceLevel(v3, 0);
    TRIBE_Game::setStartingAge(v3, 0);
    TRIBE_Game::setStartingUnits(v3, 0);
    TRIBE_Game::setDeathMatch(v3, 0);
    TRIBE_Game::setPopLimit(v3, 50);
    v4 = RGE_Base_Game::get_single_player_difficulty((RGE_Base_Game *)&v3->vfptr);
    RGE_Base_Game::setDifficulty((RGE_Base_Game *)&v3->vfptr, v4);
    TRIBE_Game::setQuickStartGame(v3, 0);
    v5 = 0;
    first_any_player = -1;
    sprintf(scenario_file2, aSS_scn, v3->prog_info->scenario_dir, scenario_file);
    if( _findfirst(scenario_file2, &file_info) == -1 )
        sprintf(scenario_file2, aS_scx, scenario_file);
    else
        sprintf(scenario_file2, aS_scn, scenario_file);
    v6 = RGE_Base_Game::get_scenario_info((RGE_Base_Game *)&v3->vfptr, a2, scenario_file, scenario_file2, 0);
    if( v6 )
    {
        v8 = 0;
        do
        {
            if( RGE_Scenario::Get_player_Active(v6, v8) )
            {
                TRIBE_Game::setScenarioPlayer(v3, v5, v8);
                v9 = RGE_Scenario::Get_player_Civ(v6, v8);
                TRIBE_Game::setCivilization(v3, v8, v9);
                TRIBE_Game::setPlayerColor(v3, v8, v8 + 1);
                RGE_Base_Game::setPlayerTeam((RGE_Base_Game *)&v3->vfptr, v8, 1);
                TRIBE_Game::setComputerName(v3, v8, 0);
                ++v5;
                if( first_any_player == -1 && RGE_Scenario::Get_player_Type(v6, v8) == 1 )
                    first_any_player = v8;
            }
            ++v8;
        }
        while( v8 < 9 );
        ((void (*)(RGE_Scenario *, signed int))v6->vfptr->~RGE_Scenario)(v6, 1);
        if( v5 )
        {
            RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)&v3->vfptr, v5);
            if( first_any_player != -1 )
            {
                v10 = 1;
                if( v5 > 1 )
                {
                    while( TRIBE_Game::scenarioPlayer(v3, v10) != first_any_player )
                    {
                        if( ++v10 >= v5 )
                            goto LABEL_20;
                    }
                    v11 = TRIBE_Game::scenarioPlayer(v3, 0);
                    TRIBE_Game::setScenarioPlayer(v3, v10, v11);
                }
LABEL_20:
                TRIBE_Game::setScenarioPlayer(v3, 0, first_any_player);
            }
            TCommunications_Handler::SetPlayerHumanity(v3->comm_handler, 1u, ME_HUMAN);
            for( i = 2; i <= v5; ++i )
                TCommunications_Handler::SetPlayerHumanity(v3->comm_handler, i, ME_COMPUTER);
            for( j = v5 + 1; j <= 9; ++j )
                TCommunications_Handler::SetPlayerHumanity(v3->comm_handler, j, 0);
            result = TRIBE_Game::start_game(v3, 1);
        }
        else
        {
            RGE_Base_Game::enable_input((RGE_Base_Game *)&v3->vfptr);
            result = 0;
        }
    }
    else
    {
        RGE_Base_Game::enable_input((RGE_Base_Game *)&v3->vfptr);
        result = 0;
    }
    return result;
}

int TRIBE_Game::load_game(char *fileName)
{
    TRIBE_Game *v2; // ebx@1
    TPanel *v3; // eax@1
    TPanel *v4; // esi@1
    int v5; // eax@1
    RGE_Game_World *v6; // ecx@4
    TSound_Driver *v7; // eax@10
    int v8; // esi@14
    int v9; // edi@14
    TSound_Driver *v10; // eax@16
    char *v11; // eax@23
    int v13; // eax@25
    signed int v14; // esi@30
    unsigned __int8 *v15; // eax@39
    FILE *v16; // eax@42
    FILE *v17; // ebx@42
    int v18; // edi@42
    RGE_Game_World *v19; // eax@43
    RGE_Player *v20; // esi@44
    char *v21; // ST3C_4@44
    int v22; // eax@44
    signed int v23; // edi@44
    float *v24; // ST54_4@45
    RGE_Object_Node *v25; // eax@46
    RGE_Static_Object *v26; // esi@47
    int v27; // eax@47
    RGE_Object_Node *v28; // esi@47
    int v29; // edx@47
    signed int v30; // edx@48
    RGE_Static_Object *v31; // esi@50
    char v32; // al@50
    Path *v33; // edi@52
    Path *v34; // ecx@53
    int v35; // esi@53
    int v36; // ST3C_4@54
    double v37; // ST34_8@54
    double v38; // st7@54
    char v39; // cl@56
    UnitAIModule *v40; // edx@58
    RGE_Action_Node *v41; // eax@58
    RGE_Action *v42; // esi@59
    int v43; // edi@60
    char v44; // ST8C_1@60
    double v45; // ST38_8@60
    int v46; // ST84_4@60
    short v47; // ST58_2@60
    int v48; // ST34_4@60
    double v49; // ST2C_8@60
    double v50; // ST24_8@60
    double v51; // st7@60
    RGE_Object_List *v52; // edx@63
    RGE_Object_Node *v53; // eax@63
    RGE_Static_Object *v54; // esi@64
    int v55; // eax@64
    RGE_Object_Node *v56; // esi@64
    int v57; // eax@64
    signed int v58; // edx@65
    RGE_Static_Object *v59; // esi@67
    RGE_Player *v60; // esi@68
    RGE_Static_Object *v61; // edi@71
    char v62; // al@71
    Path *v63; // esi@73
    Path *v64; // ecx@74
    int v65; // edi@74
    int v66; // ST3C_4@75
    double v67; // ST34_8@75
    double v68; // st7@75
    char v69; // cl@77
    UnitAIModule *v70; // edx@79
    RGE_Action_Node *v71; // eax@79
    RGE_Action *v72; // esi@80
    int v73; // edi@81
    char v74; // ST90_1@81
    double v75; // ST38_8@81
    int v76; // ST58_4@81
    short v77; // ST84_2@81
    int v78; // ST34_4@81
    double v79; // ST2C_8@81
    double v80; // ST24_8@81
    double v81; // st7@81
    RGE_Object_List *v82; // edx@84
    RGE_Object_Node *v83; // esi@84
    int v84; // edx@85
    signed int v85; // edx@86
    int v86; // [sp+38h] [bp-2FCh]@9
    PLAYERHUMANITY v87[6]; // [sp+38h] [bp-2FCh]@35
    RGE_Object_Node *list; // [sp+4Ch] [bp-2E8h]@46
    RGE_Object_Node *lista; // [sp+4Ch] [bp-2E8h]@63
    RGE_Object_Node *listb; // [sp+4Ch] [bp-2E8h]@84
    RGE_Action_Node *act_node; // [sp+50h] [bp-2E4h]@58
    RGE_Action_Node *act_nodea; // [sp+50h] [bp-2E4h]@79
    RGE_Player *p; // [sp+58h] [bp-2DCh]@44
    int action_checksum; // [sp+5Ch] [bp-2D8h]@44
    int num2; // [sp+60h] [bp-2D4h]@44
    int num2_4; // [sp+64h] [bp-2D0h]@44
    float temp_position_checksum; // [sp+68h] [bp-2CCh]@44
    TPanel *i; // [sp+6Ch] [bp-2C8h]@1
    int ia; // [sp+6Ch] [bp-2C8h]@43
    int total_action_checksum; // [sp+70h] [bp-2C4h]@43
    int total_checksum; // [sp+74h] [bp-2C0h]@43
    TRIBE_Game *v102; // [sp+78h] [bp-2BCh]@1
    int num1; // [sp+7Ch] [bp-2B8h]@44
    int num4; // [sp+84h] [bp-2B0h]@44
    char v105; // [sp+90h] [bp-2A4h]@65
    char v106; // [sp+C4h] [bp-270h]@86
    char target_name[50]; // [sp+F8h] [bp-23Ch]@48
    char fileNameNoExt[260]; // [sp+12Ch] [bp-208h]@39
    char fn[260]; // [sp+230h] [bp-104h]@42

    v2 = this;
    v102 = this;
    this->inHandleIdle = 0;
    v3 = TPanelSystem::currentPanel(&panel_system);
    v4 = v3;
    i = v3;
    RGE_Base_Game::disable_input((RGE_Base_Game *)&v2->vfptr);
    v5 = v2->prog_mode;
    if( v5 == 4 || v5 == 6 || v5 == 5 )
    {
        v6 = v2->world;
        v2->prog_mode = 0;
        ((void (*)(void))v6->vfptr->del_game_info)();
        v2->game_screen = 0;
        &panel_system->destroyPanel(aGameScreen);
    }
    TRIBE_Game::show_status_message(v2, 1101, 0, -1);
    if( !TRIBE_Game::load_game_data(v2) )
    {
        if( v4 && TPanel::panelName(v4) && *TPanel::panelName(v4) )
        {
            v86 = 0;
LABEL_23:
            v11 = TPanel::panelName(v4);
            TPanelSystem::setCurrentPanel(&panel_system, v11, v86);
            &panel_system->destroyPanel("Status Screen");
            RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
            return 0;
        }
        goto LABEL_24;
    }
    TRIBE_Game::show_status_message(v2, 1106, 0, -1);
    v7 = v2->sound_system;
    if( v7 )
        v7->mute = 1;
    if( RGE_Base_Game::check_prog_argument((RGE_Base_Game *)&v2->vfptr, aDebugsavegame) )
        ENABLE_COMPRESSION = 0;
    v8 = 0;
    v9 = ((int (__stdcall *)(char *))v2->world->vfptr->load_game)(fileName) & 0xFF;
    while( v8 < v2->world->player_num )
        RGE_Base_Game::reset_countdown_timer((RGE_Base_Game *)&v2->vfptr, v8++);
    ENABLE_COMPRESSION = 1;
    v10 = v2->sound_system;
    if( v10 )
        v10->mute = 0;
    if( !v9 )
    {
        v4 = i;
        if( i && TPanel::panelName(i) && *TPanel::panelName(i) )
        {
            v86 = 0;
            goto LABEL_23;
        }
LABEL_24:
        TRIBE_Game::close_status_message();
        RGE_Base_Game::enable_input((RGE_Base_Game *)&v2->vfptr);
        return 0;
    }
    RGE_Base_Game::setFullVisibility((RGE_Base_Game *)&v2->vfptr, v2->world->map->map_visible_flag);
    RGE_Base_Game::setFogOfWar((RGE_Base_Game *)&v2->vfptr, v2->world->map->fog_flag);
    RGE_Base_Game::setAllowCheatCodes((RGE_Base_Game *)&v2->vfptr, 1);
    RGE_Base_Game::setSavedGame((RGE_Base_Game *)&v2->vfptr, 1);
    RGE_Base_Game::setNumberPlayers((RGE_Base_Game *)&v2->vfptr, v2->world->player_num - 1);
    v13 = (unsigned __int8)RGE_Base_Game::pathFinding((RGE_Base_Game *)&v2->vfptr) - 1;
    if( v13 )
    {
        if( v13 == 1 )
            numberPathingIterations = 7500;
        else
            numberPathingIterations = 2500;
    }
    else
    {
        numberPathingIterations = 5000;
    }
    v14 = 0;
    do
    {
        if( v14 >= v2->world->player_num )
        {
            RGE_Base_Game::setPlayerID((RGE_Base_Game *)&v2->vfptr, v14, 0);
            v87[0] = 0;
        }
        else
        {
            RGE_Base_Game::setPlayerID((RGE_Base_Game *)&v2->vfptr, v14, v14);
            if( v14 <= 0 )
                goto LABEL_38;
            TCommunications_Handler::SetPlayerName(v2->comm_handler, v14, v2->world->players[v14]->name);
            if( v14 == 1 )
            {
                TCommunications_Handler::SetPlayerHumanity(v2->comm_handler, 1u, ME_HUMAN);
                goto LABEL_38;
            }
            v87[0] = 4;
        }
        TCommunications_Handler::SetPlayerHumanity(v2->comm_handler, v14, v87[0]);
LABEL_38:
        ++v14;
    }
    while( v14 < 9 );
    strcpy(fileNameNoExt, fileName);
    v15 = _mbschr((const unsigned __int8 *)fileNameNoExt, 0x2Eu);
    if( v15 )
        *v15 = 0;
    TRIBE_Game::set_save_game_name(v2, fileNameNoExt);
    TRIBE_Game::set_load_game_name(v2, fileNameNoExt);
    if( RGE_Base_Game::check_prog_argument((RGE_Base_Game *)&v2->vfptr, aDebugload) )
    {
        sprintf(fn, aCS_txt, fileNameNoExt);
        v16 = fopen(fn, aW_1);
        v17 = v16;
        v18 = 0;
        if( v16 )
        {
            total_checksum = 0;
            total_action_checksum = 0;
            fprintf(v16, aWorld_timeU, v102->world->world_time);
            fprintf(v17, aOld_world_time, v102->world->old_world_time);
            fprintf(v17, aGame_speed6_2f, v102->world->game_speed);
            v19 = v102->world;
            ia = 0;
            if( v19->player_num > 0 )
            {
                do
                {
                    v20 = v19->players[v18];
                    p = v20;
                    v21 = v20->name;
                    v22 = RGE_Victory_Conditions::get_victory_points(v20->victory_conditions);
                    fprintf(v17, aPlayerDCivDSco, v18, v20->master_player_id, v22, v21);
                    fprintf(v17, aWritingF, v20->attributes[50]);
                    v23 = 0;
                    num1 = 0;
                    num2 = 0;
                    num2_4 = 0;
                    temp_position_checksum = 0.0;
                    action_checksum = 0;
                    num4 = v20->id + v20->sleeping_objects->number_of_objects + v20->doppleganger_objects->number_of_objects;
                    fprintf(v17, aNum_sleep_objD, v20->sleeping_objects->number_of_objects);
                    fprintf(v17, aNum_dopple_obj, v20->doppleganger_objects->number_of_objects);
                    if( v20->attribute_num > 0 )
                    {
                        do
                        {
                            v24 = &v20->attributes[v23];
                            num1 += (signed __int64)*v24;
                            fprintf(v17, aPDAttrD12_8f, v20->id, v23++, *v24);
                        }
                        while( v23 < v20->attribute_num );
                    }
                    v25 = v20->objects->list;
                    list = v20->objects->list;
                    if( v25 )
                    {
                        do
                        {
                            v26 = v25->node;
                            ++num2_4;
                            num2 += (unsigned __int64)(signed __int64)v25->node->attribute_amount_held
                                        + v25->node->object_state
                                        + v25->node->master_obj->id;
                            temp_position_checksum = v26->world_z + v26->world_x + temp_position_checksum + v26->world_y;
                            v27 = v26->vfptr->get_action_checksum(v26);
                            v28 = list;
                            action_checksum += v27;
                            v29 = ((int (*)(void))list->node->vfptr->get_target_obj)();
                            if( v29 )
                            {
                                strcpy(target_name, *(const char **)(*(_DWORD *)(v29 + 8) + 8));
                                v30 = *(_DWORD *)(v29 + 4);
                                v28 = list;
                            }
                            else
                            {
                                target_name[0] = 0;
                                v30 = -1;
                            }
                            fprintf(
                                v17,
                                aPDObDSStDAt8_4,
                                p->id,
                                v28->node->id,
                                v28->node->master_obj->name,
                                v28->node->object_state,
                                v28->node->attribute_amount_held,
                                v28->node->world_x,
                                v28->node->world_y,
                                v28->node->world_z,
                                v30,
                                target_name);
                            v31 = v28->node;
                            v32 = v31->master_obj->master_type;
                            if( (unsigned __int8)v32 >= 0x1Eu && v32 != 90 )
                            {
                                v33 = (Path *)&v31[1].tile;
                                if( Path::numberOfWaypoints((Path *)&v31[1].tile) > 0 )
                                {
                                    Path::initToStart((Path *)&v31[1].tile);
                                    fprintf(
                                        v17,
                                        aPathS6_2f6_2f6,
                                        *(float *)&v31[1].inObstructionMapValue,
                                        v31[2].vfptr,
                                        v31[2].id,
                                        v31[2].owner,
                                        v31[2].sprite,
                                        v31[2].old_sprite,
                                        *(_DWORD *)&v31[2].curr_damage_percent,
                                        BYTE2(v31[2].attribute_amount_held));
                                    v34 = (Path *)&v31[1].tile;
                                    v35 = 0;
                                    if( Path::numberOfWaypoints(v34) > 0 )
                                    {
                                        do
                                        {
                                            v36 = Path::currentWaypoint(v33)->facetToNextWaypoint;
                                            v37 = Path::currentWaypoint(v33)->y;
                                            v38 = Path::currentWaypoint(v33)->x;
                                            fprintf(v17, aWI6_2f6_2fD, v35++, v38, v37, v36);
                                            Path::moveToNextWaypoint(v33);
                                        }
                                        while( v35 < Path::numberOfWaypoints(v33) );
                                    }
                                    Path::initToStart(v33);
                                    Path::moveToNextWaypoint(v33);
                                }
                            }
                            v39 = list->node->master_obj->master_type;
                            if( (unsigned __int8)v39 >= 0x28u && v39 != 90 )
                            {
                                v40 = list->node[2].unitAIValue;
                                v41 = (RGE_Action_Node *)v40->moodValue;
                                for( act_node = (RGE_Action_Node *)v40->moodValue; v41; act_node = v41 )
                                {
                                    v42 = v41->action;
                                    if( v41->action )
                                    {
                                        v43 = v42->target2ID;
                                        v44 = v42->state;
                                        v45 = v42->timer;
                                        v46 = v42->targetID;
                                        v47 = v42->action_type;
                                        v48 = (unsigned __int8)RGE_Action::subAction(v42);
                                        v49 = RGE_Action::targetZ(v42);
                                        v50 = RGE_Action::targetY(v42);
                                        v51 = RGE_Action::targetX(v42);
                                        fprintf(
                                            v17,
                                            aActionTypDStDT,
                                            v47,
                                            (unsigned __int8)v44,
                                            v46,
                                            v43,
                                            LODWORD(v51),
                                            (_DWORD)(*(unsigned __int64 *)&v51 >> 32),
                                            v50,
                                            v49,
                                            v48,
                                            v45);
                                        v41 = act_node;
                                    }
                                    v41 = v41->next;
                                }
                            }
                            list = list->next;
                            v25 = list;
                        }
                        while( list );
                    }
                    v52 = p->doppleganger_objects;
                    v53 = v52->list;
                    lista = v52->list;
                    if( v53 )
                    {
                        do
                        {
                            v54 = v53->node;
                            num2 += (unsigned __int64)(signed __int64)v53->node->attribute_amount_held
                                        + v53->node->object_state
                                        + v53->node->master_obj->id;
                            temp_position_checksum = v54->world_z + v54->world_x + temp_position_checksum + v54->world_y;
                            ++num2_4;
                            v55 = v54->vfptr->get_action_checksum(v54);
                            v56 = lista;
                            action_checksum += v55;
                            v57 = ((int (*)(void))lista->node->vfptr->get_target_obj)();
                            if( v57 )
                            {
                                strcpy(&v105, *(const char **)(*(_DWORD *)(v57 + 8) + 8));
                                v58 = *(_DWORD *)(v57 + 4);
                                v56 = lista;
                            }
                            else
                            {
                                v105 = 0;
                                v58 = -1;
                            }
                            fprintf(
                                v17,
                                aPDObDSStDAt8_4,
                                p->id,
                                v56->node->id,
                                v56->node->master_obj->name,
                                v56->node->object_state,
                                v56->node->attribute_amount_held,
                                v56->node->world_x,
                                v56->node->world_y,
                                v56->node->world_z,
                                v58,
                                &v105);
                            v59 = v56->node;
                            if( v59 )
                            {
                                v60 = v59[1].owner;
                                if( v60 )
                                    fprintf(
                                        v17,
                                        aDoppledMasterO,
                                        v60->pathingAttemptCapValue,
                                        LOWORD(v60->currentUpdatePathingAttemptsValue));
                                else
                                    fprintf(v17, aNullDoppledMas);
                            }
                            v61 = lista->node;
                            v62 = lista->node->master_obj->master_type;
                            if( (unsigned __int8)v62 >= 0x1Eu && v62 != 90 )
                            {
                                v63 = (Path *)&v61[1].tile;
                                if( Path::numberOfWaypoints((Path *)&v61[1].tile) > 0 )
                                {
                                    Path::initToStart((Path *)&v61[1].tile);
                                    fprintf(
                                        v17,
                                        aPathS6_2f6_2f6,
                                        *(float *)&v61[1].inObstructionMapValue,
                                        v61[2].vfptr,
                                        v61[2].id,
                                        v61[2].owner,
                                        v61[2].sprite,
                                        v61[2].old_sprite,
                                        *(_DWORD *)&v61[2].curr_damage_percent,
                                        BYTE2(v61[2].attribute_amount_held));
                                    v64 = (Path *)&v61[1].tile;
                                    v65 = 0;
                                    if( Path::numberOfWaypoints(v64) > 0 )
                                    {
                                        do
                                        {
                                            v66 = Path::currentWaypoint(v63)->facetToNextWaypoint;
                                            v67 = Path::currentWaypoint(v63)->y;
                                            v68 = Path::currentWaypoint(v63)->x;
                                            fprintf(v17, aWI6_2f6_2fD, v65++, v68, v67, v66);
                                            Path::moveToNextWaypoint(v63);
                                        }
                                        while( v65 < Path::numberOfWaypoints(v63) );
                                    }
                                    Path::initToStart(v63);
                                    Path::moveToNextWaypoint(v63);
                                }
                            }
                            v69 = lista->node->master_obj->master_type;
                            if( (unsigned __int8)v69 >= 0x28u && v69 != 90 )
                            {
                                v70 = lista->node[2].unitAIValue;
                                v71 = (RGE_Action_Node *)v70->moodValue;
                                for( act_nodea = (RGE_Action_Node *)v70->moodValue; v71; act_nodea = v71 )
                                {
                                    v72 = v71->action;
                                    if( v71->action )
                                    {
                                        v73 = v72->target2ID;
                                        v74 = v72->state;
                                        v75 = v72->timer;
                                        v76 = v72->targetID;
                                        v77 = v72->action_type;
                                        v78 = (unsigned __int8)RGE_Action::subAction(v72);
                                        v79 = RGE_Action::targetZ(v72);
                                        v80 = RGE_Action::targetY(v72);
                                        v81 = RGE_Action::targetX(v72);
                                        fprintf(
                                            v17,
                                            aActionTypDStDT,
                                            v77,
                                            (unsigned __int8)v74,
                                            v76,
                                            v73,
                                            LODWORD(v81),
                                            (_DWORD)(*(unsigned __int64 *)&v81 >> 32),
                                            v80,
                                            v79,
                                            v78,
                                            v75);
                                        v71 = act_nodea;
                                    }
                                    v71 = v71->next;
                                }
                            }
                            lista = lista->next;
                            v53 = lista;
                        }
                        while( lista );
                    }
                    v82 = p->sleeping_objects;
                    v83 = v82->list;
                    for( listb = v82->list; v83; listb = v83 )
                    {
                        v84 = ((int (*)(void))v83->node->vfptr->get_target_obj)();
                        if( v84 )
                        {
                            strcpy(&v106, *(const char **)(*(_DWORD *)(v84 + 8) + 8));
                            v85 = *(_DWORD *)(v84 + 4);
                            v83 = listb;
                        }
                        else
                        {
                            v106 = 0;
                            v85 = -1;
                        }
                        fprintf(
                            v17,
                            aPDObDSStDAt8_4,
                            p->id,
                            v83->node->id,
                            v83->node->master_obj->name,
                            v83->node->object_state,
                            v83->node->attribute_amount_held,
                            v83->node->world_x,
                            v83->node->world_y,
                            v83->node->world_z,
                            v85,
                            &v106);
                        v83 = v83->next;
                    }
                    total_checksum += num1 + ((num2 + ((num2_4 + (num4 << 8)) << 8)) << 8);
                    total_action_checksum += action_checksum;
                    fprintf(
                        v17,
                        aPDChecksumD1D2,
                        p->id,
                        num1 + ((num2 + ((num2_4 + (num4 << 8)) << 8)) << 8),
                        num1,
                        num2,
                        num2_4,
                        num4,
                        action_checksum);
                    v18 = ia + 1;
                    v19 = v102->world;
                    ia = v18;
                }
                while( v18 < v19->player_num );
            }
            fprintf(v17, aTotalChecksumD, total_checksum, total_action_checksum);
            fclose(v17);
        }
    }
    TRIBE_Game::close_game_screens(v102, 0);

    return TRIBE_Game::create_game_screen(v102);
}

void TRIBE_Game::do_game_over()
{
    TRIBE_Game *v1; // esi@1
    int v2; // eax@3
    RGE_Game_World *v3; // eax@7

    v1 = this;
    TRIBE_Game::disconnect_multiplayer_game(this);
    if( v1->testing_scenario[0] )
    {
        TRIBE_Game::quit_game(v1);
    }
    else
    {
        v2 = v1->prog_mode;
        if( v2 == 4 || v2 == 6 || v2 == 5 || v2 == 3 )
        {
            v3 = v1->world;
            v1->prog_mode = 0;
            if( v3 )
            {
                RGE_Base_Game::turn_world_sound_off((RGE_Base_Game *)&v1->vfptr);
                if( LOBYTE(RGE_Base_Game::get_player((RGE_Base_Game *)&v1->vfptr)->sound_driver) == 1 )
                    TRIBE_Game::start_video(v1, 4, v1->world->scenario->Cine_Victory);
                else
                    TRIBE_Game::start_video(v1, 4, v1->world->scenario->Cine_Loss);
            }
        }
    }
}

char *TRIBE_Game::create_game(int not_used)
{
    TRIBE_Game *v2; // ebp@1
    int v3; // edi@1
    signed int v4; // ecx@1
    int *v5; // eax@1
    char *v6; // ecx@6
    _DWORD *v7; // eax@6
    int *v8; // edx@6
    int v9; // edx@11
    signed int v10; // eax@12
    int v11; // esi@28
    int v12; // eax@28
    char *result; // eax@32
    int v14; // esi@33
    char *v15; // eax@33
    char *v16; // ST0C_4@34
    char *v17; // ST0C_4@35
    unsigned int v18; // ST0C_4@39
    unsigned int v19; // ST0C_4@42
    int v20; // esi@43
    RGE_Player_Info *v21; // ebx@43
    int *v22; // edi@43
    int v23; // eax@46
    unsigned int v24; // edx@46
    int v25; // esi@48
    int v26; // eax@50
    int v27; // eax@50
    RGE_Scenario *v28; // eax@53
    int v29; // esi@59
    int v30; // esi@61
    int v31; // eax@63
    int v32; // ecx@63
    int *v33; // eax@63
    signed int v34; // edi@67
    signed int v35; // ebx@69
    unsigned int v36; // esi@69
    int *v37; // edi@79
    int v38; // esi@81
    RGE_Player_Info *v39; // ebx@81
    int v40; // edi@82
    int v41; // eax@88
    int v42; // edi@88
    char *v43; // esi@92
    char v44; // al@95
    const char *v45; // eax@99
    const char *v46; // eax@102
    RGE_Base_GameVtbl *v47; // esi@116
    int v48; // eax@116
    int v49; // ST34_4@117
    int v50; // eax@117
    TSound_Driver *v51; // eax@124
    int v52; // ST0C_4@127
    int v53; // eax@127
    char *v54; // ebx@129
    RGE_Game_World *v55; // ecx@130
    TSound_Driver *v56; // eax@132
    int j; // esi@134
    RGE_Game_World *v58; // eax@137
    signed int k; // esi@137
    char v60; // al@141
    char v61; // al@142
    int v62; // eax@144
    signed int v63; // esi@149
    PLAYERHUMANITY *v64; // edi@149
    char *i; // [sp+10h] [bp-A2Ch]@43
    signed int ia; // [sp+10h] [bp-A2Ch]@61
    int ib; // [sp+10h] [bp-A2Ch]@92
    T_Scenario *scenario_info; // [sp+14h] [bp-A28h]@43
    T_Scenario *scenario_infoa; // [sp+14h] [bp-A28h]@56
    int player_index; // [sp+18h] [bp-A24h]@61
    int player_indexa; // [sp+18h] [bp-A24h]@82
    int *scenario_player; // [sp+1Ch] [bp-A20h]@67
    int scenario_playera; // [sp+1Ch] [bp-A20h]@88
    char *path_finding_val; // [sp+20h] [bp-A1Ch]@81
    int humanity; // [sp+24h] [bp-A18h]@88
    int player_num; // [sp+28h] [bp-A14h]@88
    int v77; // [sp+2Ch] [bp-A10h]@82
    char *v78; // [sp+30h] [bp-A0Ch]@81
    int position_used[8]; // [sp+34h] [bp-A08h]@59
    RGE_Player_Info player_info; // [sp+54h] [bp-9E8h]@29
    char scenario_file[260]; // [sp+300h] [bp-73Ch]@33
    _finddata_t file_info; // [sp+404h] [bp-638h]@33
    RGE_Map_Gen_Info map_info; // [sp+51Ch] [bp-520h]@29

    v2 = this;
    v3 = 0;
    v4 = 5;
    v2->inHandleIdle = 0;
    v5 = v2->notification_loc_y;
    do
    {
        *(v5 - 5) = -1;
        *v5 = -1;
        ++v5;
        --v4;
    }
    while( v4 );
    v2->current_notification_loc = -1;
    v2->current_notification_recalled = -1;
    v2->quick_build = RGE_Base_Game::check_prog_argument((RGE_Base_Game *)&v2->vfptr, aQuickbuild) != 0;
    v2->do_show_timings = 0;
    v2->do_show_comm = 0;
    v2->do_show_ai = 0;
    RGE_Base_Game::set_map_visible((RGE_Base_Game *)&v2->vfptr, 0);
    RGE_Base_Game::set_map_fog((RGE_Base_Game *)&v2->vfptr, 0);
    v6 = &v2->resigned[1];
    v7 = &unk_86BCAC;
    v8 = &v2->queue_is_waiting_on_pop_counter[1];
    do
    {
        *v6 = 0;
        *v7 = 0;
        *v8 = 0;
        ++v7;
        ++v6;
        ++v8;
    }
    while( (signed int)v7 < (signed int)&PalSetRes );
    out_of_sync = 0;
    out_of_sync2 = 0;
    no_other_humans_count = 0;
    if( TRIBE_Game::quickStartGame(v2) )
    {
        if( quick_start_game_mode == 1 )
        {
            TRIBE_Game::setMapSize(v2, Medium);
            TRIBE_Game::setMapType(v2, AllLand);
        }
        else
        {
            TRIBE_Game::setMapSize(v2, Large);
            v9 = debug_rand(aCMsdevWorkA_41, 3293) % 10;
            if( v9 >= 2 )
            {
                switch( v9 )
                {
                    case 2:
                        v10 = 3;
                        break;
                    case 3:
                        v10 = 2;
                        break;
                    case 4:
                        v10 = 1;
                        break;
                    case 5:
                        v10 = 5;
                        break;
                    case 6:
                        v10 = 6;
                        break;
                    default:
                        v10 = v9 == 7 ? 7 : v9 != 8 ? 0 : 8;
                        break;
                }
            }
            else
            {
                v10 = 4;
            }
            TRIBE_Game::setMapType(v2, (TRIBE_Game::MapType)v10);
        }
        TRIBE_Game::resetRandomComputerName(v2);
        if( RGE_Base_Game::numberPlayers((RGE_Base_Game *)&v2->vfptr) > 0 )
        {
            do
            {
                v11 = (unsigned __int8)((char)debug_rand(aCMsdevWorkA_41, 3320) % -16) + 1;
                TRIBE_Game::setCivilization(v2, v3, v11);
                v12 = TRIBE_Game::randomComputerName(v2, v11);
                TRIBE_Game::setComputerName(v2, v3++, v12);
            }
            while( v3 < RGE_Base_Game::numberPlayers((RGE_Base_Game *)&v2->vfptr) );
        }
    }
    memset(&player_info, 0, sizeof(player_info));
    memset(&map_info, 0, sizeof(map_info));
    if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr) )
    {
        player_info.campaign = 1;
    }
    else if( RGE_Base_Game::scenarioGame((RGE_Base_Game *)&v2->vfptr) )
    {
        result = RGE_Base_Game::scenarioName((RGE_Base_Game *)&v2->vfptr);
        if( !result )
            return result;
        v14 = (int)v2->prog_info->scenario_dir;
        v15 = RGE_Base_Game::scenarioName((RGE_Base_Game *)&v2->vfptr);
        sprintf(scenario_file, aSS_scn, v14, v15);
        if( _findfirst(scenario_file, &file_info) == -1 )
        {
            v16 = RGE_Base_Game::scenarioName((RGE_Base_Game *)&v2->vfptr);
            sprintf(scenario_file, aS_scx, v16);
        }
        else
        {
            v17 = RGE_Base_Game::scenarioName((RGE_Base_Game *)&v2->vfptr);
            sprintf(scenario_file, aS_scn, v17);
        }
        player_info.scenario = scenario_file;
    }
    else
    {
        player_info.map_info = &map_info;
        player_info.map_type = TRIBE_Game::mapType(v2);
        player_info.map_width = RGE_Base_Game::mapXSize((RGE_Base_Game *)&v2->vfptr);
        player_info.map_height = RGE_Base_Game::mapYSize((RGE_Base_Game *)&v2->vfptr);
    }
    if( RGE_Base_Game::multiplayerGame((RGE_Base_Game *)&v2->vfptr) )
    {
        v18 = TCommunications_Handler::GetRandomSeed(comm);
        debug_srand(aCMsdevWorkA_41, 3364, v18);
    }
    else if( v2->random_game_seed == -1 )
    {
        v19 = debug_rand(aCMsdevWorkA_41, 3370);
        debug_srand(aCMsdevWorkA_41, 3370, v19);
    }
    else
    {
        debug_srand(aCMsdevWorkA_41, 3368, v2->random_game_seed);
    }
    v20 = 0;
    player_info.player_num = 0;
    scenario_info = (T_Scenario *)player_info.color;
    i = (char *)player_info.player_id_hash;
    v21 = &player_info;
    v22 = v2->random_civ;
    do
    {
        player_info.type[v20] = -1;
        v21->name[0][0] = 0;
        *(_DWORD *)i = v20;
        player_info.tribe[v20] = 1;
        LOWORD(scenario_info->vfptr) = -1;
        *v22 = 0;
        if( TRIBE_Game::civilization(v2, v20) > 16 || TRIBE_Game::civilization(v2, v20) < 0 )
        {
            v23 = debug_rand(aCMsdevWorkA_41, 3387);
            v24 = (signed int)(16 * v23 + ((unsigned __int64)(-34358689744i64 * v23) >> 32)) >> 14;
            TRIBE_Game::setCivilization(v2, v20, v24 + (v24 >> 31) + 1);
            *v22 = 1;
        }
        ++v20;
        v21 = (RGE_Player_Info *)((char *)v21 + 65);
        ++v22;
        i += 4;
        scenario_info = (T_Scenario *)((char *)scenario_info + 2);
    }
    while( v20 < 9 );
    TRIBE_Game::resetRandomComputerName(v2);
    v25 = 0;
    if( RGE_Base_Game::numberPlayers((RGE_Base_Game *)&v2->vfptr) > 0 )
    {
        do
        {
            v22 = (int *)(v25 + 1);
            if( TCommunications_Handler::GetPlayerHumanity(comm, v25 + 1) == 4 )
            {
                v26 = TRIBE_Game::civilization(v2, v25);
                v27 = TRIBE_Game::randomComputerName(v2, v26);
                TRIBE_Game::setComputerName(v2, v25, v27);
            }
            ++v25;
        }
        while( (signed int)v22 < RGE_Base_Game::numberPlayers((RGE_Base_Game *)&v2->vfptr) );
    }
    if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr) )
    {
        v28 = RGE_Base_Game::get_scenario_info((RGE_Base_Game *)&v2->vfptr, (int)v2, v22, 0, 1);
        goto LABEL_56;
    }
    if( RGE_Base_Game::scenarioGame((RGE_Base_Game *)&v2->vfptr) )
    {
        v28 = RGE_Base_Game::get_scenario_info((RGE_Base_Game *)&v2->vfptr, (int)v2, v22, player_info.scenario, 0);
LABEL_56:
        scenario_infoa = (T_Scenario *)v28;
        if( !v28 )
            return 0;
        goto LABEL_59;
    }
    scenario_infoa = 0;
LABEL_59:
    v29 = 0;
    memset(position_used, 0xFFu, 0x24u);
    do
        RGE_Base_Game::setPlayerID((RGE_Base_Game *)&v2->vfptr, v29++, 0);
    while( v29 < 9 );
    v30 = 1;
    player_index = 0;
    for( ia = 1; v30 <= RGE_Base_Game::numberPlayers((RGE_Base_Game *)&v2->vfptr); ia = v30 )
    {
        if( TCommunications_Handler::GetPlayerHumanity(v2->comm_handler, v30) != 2 )
        {
            if( TCommunications_Handler::GetPlayerHumanity(v2->comm_handler, v30) != 4 )
                goto LABEL_80;
            v34 = 0;
            scenario_player = position_used;
            while( 1 )
            {
                if( *scenario_player == -1 )
                {
                    v35 = 0;
                    v36 = 1;
                    while( TCommunications_Handler::GetPlayerHumanity(v2->comm_handler, v36) != 2
                             || TRIBE_Game::playerColor(v2, v36 - 1) - 1 != v34 )
                    {
                        if( (signed int)++v36 >= 9 )
                            goto LABEL_75;
                    }
                    v35 = 1;
LABEL_75:
                    if( !v35 )
                    {
                        v30 = ia;
                        TRIBE_Game::setPlayerColor(v2, ia - 1, v34 + 1);
                        v37 = &position_used[v34];
                        *v37 = player_index++;
                        RGE_Base_Game::setPlayerID((RGE_Base_Game *)&v2->vfptr, ia, *v37 + 1);
                        goto LABEL_80;
                    }
                    v30 = ia;
                }
                ++v34;
                ++scenario_player;
                if( v34 >= 8 )
                    goto LABEL_80;
            }
        }
        v31 = TRIBE_Game::playerColor(v2, v30 - 1) - 1;
        v32 = position_used[v31];
        v33 = &position_used[v31];
        if( v32 == -1 )
            *v33 = player_index++;
        RGE_Base_Game::setPlayerID((RGE_Base_Game *)&v2->vfptr, v30, *v33 + 1);
LABEL_80:
        ++v30;
    }
    TRIBE_Game::resetRandomComputerName(v2);
    v38 = 0;
    path_finding_val = (char *)player_info.color;
    v78 = (char *)&player_info.player_id_hash[1];
    v39 = &player_info;
    do
    {
        player_indexa = 0;
        v40 = 1;
        v77 = v38 + 1;
        while( RGE_Base_Game::playerID((RGE_Base_Game *)&v2->vfptr, v40) != v77 )
        {
            if( ++v40 >= 9 )
                goto LABEL_87;
        }
        player_indexa = v40;
LABEL_87:
        if( !player_indexa )
            break;
        humanity = TCommunications_Handler::GetPlayerHumanity(v2->comm_handler, player_indexa);
        player_num = player_indexa - 1;
        v41 = TRIBE_Game::playerColor(v2, player_indexa - 1);
        v42 = v41 - 1;
        scenario_playera = v41 - 1;
        if( humanity == 4 || all_cp == 1 || all_cp == 2 && v38 > 0 )
        {
            v43 = &player_info.type[v38];
            ib = (int)v43;
            *v43 = 4;
        }
        else
        {
            v43 = &player_info.type[v38];
            ib = (int)v43;
            *v43 = 0;
        }
        if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr) )
            v44 = RGE_Scenario::Get_player_Civ((RGE_Scenario *)&scenario_infoa->vfptr, v42);
        else
            v44 = TRIBE_Game::civilization(v2, player_num);
        v43[9] = v44;
        if( !RGE_Base_Game::multiplayerGame((RGE_Base_Game *)&v2->vfptr) || humanity != 2 )
        {
            if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr) && !*v43 )
            {
                v46 = (const char *)RGE_Game_Info::get_current_player_name(v2->player_game_info);
                goto LABEL_110;
            }
            if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr)
                || !RGE_Base_Game::randomGame((RGE_Base_Game *)&v2->vfptr)
                || *v43 )
            {
                if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr)
                    || RGE_Base_Game::scenarioGame((RGE_Base_Game *)&v2->vfptr) )
                {
                    v46 = (const char *)RGE_Scenario::GetPlayerName((RGE_Scenario *)&scenario_infoa->vfptr, scenario_playera);
LABEL_110:
                    strcpy((char *)v39, v46);
                    v42 = scenario_playera;
                    v43 = (char *)ib;
                }
            }
            else
            {
                (*(void (**)(TRIBE_Game *, signed int, RGE_Player_Info *, signed int))&v2->vfptr->gap8[24])(
                    v2,
                    10349,
                    v39,
                    65);
            }
            if( !v39->name[0][0] )
            {
                if( *v43 )
                {
                    if( RGE_Base_Game::campaignGame((RGE_Base_Game *)&v2->vfptr) || !TRIBE_Game::computerName(v2, player_num) )
                    {
                        v49 = (int)v2->vfptr;
                        v50 = TRIBE_Game::randomComputerName(v2, v43[9]);
                        (*(void (**)(TRIBE_Game *, int, RGE_Player_Info *, signed int))(v49 + 32))(
                            v2,
                            v50 + 4400,
                            v39,
                            65);
                    }
                    else
                    {
                        v47 = v2->vfptr;
                        v48 = TRIBE_Game::computerName(v2, player_num);
                        (*(void (**)(TRIBE_Game *, int, RGE_Player_Info *, signed int))&v47->gap8[24])(
                            v2,
                            v48 + 4400,
                            v39,
                            65);
                    }
                }
                else
                {
                    (*(void (**)(TRIBE_Game *, signed int, RGE_Player_Info *, signed int))&v2->vfptr->gap8[24])(
                        v2,
                        10349,
                        v39,
                        65);
                }
            }
            TCommunications_Handler::SetPlayerName(v2->comm_handler, player_indexa, (char *)v39);
            goto LABEL_119;
        }
        v45 = TCommunications_Handler::GetPlayerName(v2->comm_handler, player_indexa);
        strncpy((char *)v39, v45, 0x40u);
LABEL_119:
        v38 = v77;
        v39 = (RGE_Player_Info *)((char *)v39 + 65);
        *(_DWORD *)v78 = v42 + 1;
        *(_WORD *)path_finding_val = v42;
        ++player_info.player_num;
        v78 += 4;
        path_finding_val += 2;
    }
    while( v77 < 8 );
    if( scenario_infoa )
        ((void (__stdcall *)(signed int))scenario_infoa->vfptr->~RGE_Scenario)(1);
    if( player_info.player_num )
    {
        v51 = v2->sound_system;
        if( v51 )
            v51->mute = 1;
        if( RGE_Base_Game::multiplayerGame((RGE_Base_Game *)&v2->vfptr) )
        {
            v52 = TCommunications_Handler::WhoAmI(v2->comm_handler);
            v53 = RGE_Base_Game::playerID((RGE_Base_Game *)&v2->vfptr, v52);
        }
        else
        {
            v53 = RGE_Base_Game::playerID((RGE_Base_Game *)&v2->vfptr, 1);
        }
        v54 = (char *)(((int (__stdcall *)(RGE_Player_Info *, int))v2->world->vfptr->new_game)(&player_info, v53) & 0xFF);
        if( v54 )
        {
            v55 = v2->world;
            if( v55->player_num < 2 )
            {
                v54 = 0;
                ((void (*)(void))v55->vfptr->del_game_info)();
            }
        }
        v56 = v2->sound_system;
        if( v56 )
            v56->mute = 0;
        for( j = 0; j < v2->world->player_num; RGE_Base_Game::reset_countdown_timer((RGE_Base_Game *)&v2->vfptr, j++) )
            ;
        RGE_Game_World::update_mutual_allies(v2->world);
        RGE_Base_Game::set_map_visible((RGE_Base_Game *)&v2->vfptr, 0);
        if( RGE_Base_Game::fullVisibility((RGE_Base_Game *)&v2->vfptr) )
        {
            v58 = v2->world;
            for( k = 1; k < v58->player_num; ++k )
            {
                if( !RGE_Player::computerPlayer(v58->players[k]) )
                    RGE_Visible_Map::explore_all(v2->world->players[k]->visible);
                v58 = v2->world;
            }
        }
        v60 = RGE_Base_Game::fogOfWar((RGE_Base_Game *)&v2->vfptr);
        RGE_Base_Game::set_map_fog((RGE_Base_Game *)&v2->vfptr, v60);
        if( RGE_Base_Game::multiplayerGame((RGE_Base_Game *)&v2->vfptr) )
            v61 = RGE_Base_Game::mpPathFinding((RGE_Base_Game *)&v2->vfptr);
        else
            v61 = RGE_Base_Game::pathFinding((RGE_Base_Game *)&v2->vfptr);
        v62 = (unsigned __int8)v61 - 1;
        if( v62 )
        {
            if( v62 == 1 )
                numberPathingIterations = 7500;
            else
                numberPathingIterations = 2500;
        }
        else
        {
            numberPathingIterations = 5000;
        }
        v63 = 1;
        v64 = (PLAYERHUMANITY *)&v2->save_humanity[1];
        do
        {
            *v64 = TCommunications_Handler::GetPlayerHumanity(v2->comm_handler, v63++);
            ++v64;
        }
        while( v63 < 9 );
        result = v54;
    }
    else
    {
        result = 0;
    }
    return result;
}

bool TRIBE_Game::create_game_screen()
{
    TRIBE_Game *v1; // esi@1
    RGE_Base_GameVtbl *v2; // edi@1
    TRIBE_Screen_Game *v3; // eax@1
    TRIBE_Screen_Game *v4; // eax@2
    TRIBE_Screen_Wait *v5; // eax@7
    TRIBE_Screen_Wait *v6; // eax@8
    TRIBE_Screen_Game *v7; // ecx@12
    RGE_Game_World *v8; // ecx@14

    v1 = this;
    this->disable_input();
    v2 = v1->vfptr;
    (*(void (**)(TRIBE_Game *, _DWORD, _DWORD))&v1->vfptr->gap8[8])(v1, 0, 0);
    v3 = (TRIBE_Screen_Game *)operator new(0x7C4u);
    if( v3 )
        TRIBE_Screen_Game::TRIBE_Screen_Game(v3);
    else
        v4 = 0;
    v1->game_screen = v4;
    if( !v4 )
    {
LABEL_21:
        ((void (*)(void))v1->world->vfptr->del_game_info)();
LABEL_22:
        TRIBE_Game::close_status_message();
        RGE_Base_Game::enable_input((RGE_Base_Game *)&v1->vfptr);
        return 0;
    }
    if( v4->error_code )
    {
        if( v4 )
        {
            v4->vfptr->__vecDelDtor((TPanel *)v4, 1u);
            v1->game_screen = 0;
        }
        goto LABEL_21;
    }
    if( this->comm_handler->MultiplayerGameStart() )
    {
        &panel_system->setCurrentPanel(aGameScreen, 0);
        &panel_system->destroyPanel("Status Screen");
        goto LABEL_16;
    }
    v5 = (TRIBE_Screen_Wait *)operator new(0x4D8u);
    if( v5 )
        TRIBE_Screen_Wait::TRIBE_Screen_Wait(v5);
    else
        v6 = 0;
    if( !v6 )
    {
        v7 = v1->game_screen;
        if( v7 )
            ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
        v8 = v1->world;
        v1->game_screen = 0;
        ((void (*)(void))v8->vfptr->del_game_info)();
        goto LABEL_22;
    }
    v6->set_text(1108);
    TPanelSystem::setCurrentPanel(&panel_system, aMultiplayerWai, 0);
    &panel_system->destroyPanel("Status Screen");
    (*(void (**)(TRIBE_Game *, signed int))&v2->gap8[4])(v1, 3);
LABEL_16:
    &panel_system->destroyPanel(aSinglePlayerMe);
    &panel_system->destroyPanel(aGameSetupScree);
    &panel_system->destroyPanel(aSelectScenario);
    &panel_system->destroyPanel(aGameSettingsSc);
    &panel_system->destroyPanel(aLoadSavedGameS);
    &panel_system->destroyPanel(aMpSetupScreen);
    &panel_system->destroyPanel(aJoinScreen);
    &panel_system->destroyPanel(aMpStartupScree);
    &panel_system->destroyPanel(aMainMenu);
    &panel_system->destroyPanel(aCampaignSelect);

    if( this->prog_mode != 3 ){
        this->let_game_begin();
    }

    return true;
}

bool TRIBE_Game::processCheatCode( int playerID, char *text )
{
    TRIBE_Game *v3; // ebp@1
    RGE_Player *v4; // eax@66
    RGE_Game_World *v6; // eax@71
    RGE_Game_World *v7; // eax@73
    RGE_Game_World *v8; // eax@75
    RGE_Game_World *v9; // eax@77
    RGE_Static_Object *v10; // eax@88
    int v11; // eax@91
    int target; // [sp+10h] [bp-508h]@88
    int commander; // [sp+14h] [bp-504h]@91
    char encstr[512]; // [sp+18h] [bp-500h]@4
    char str[256]; // [sp+218h] [bp-300h]@4
    char tempStr1[256]; // [sp+318h] [bp-200h]@87
    char playName[256]; // [sp+418h] [bp-100h]@91

    v3 = this;

    if( text == NULL )
        return false;

    if( playerID < 0 )
        return false;

    if( playerID >= this->world->player_num )
        return false;

    strcpy(str, text);
    _mbsupr((unsigned __int8 *)str);
    encrypt_codes(str, encstr, 512);

    if( !RGE_Base_Game::allowCheatCodes((RGE_Base_Game *)&v3->vfptr) )
        return false;

    if( !strcmp(encstr, a_Cam_jdw) && RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v3->vfptr) )
    {
        this->world->send_cheat(102);
        return true;
    }
    if( strstr(str, aStormbilly) )
    {
        this->world->send_cheat(14);
        return true;
    }
    if( strstr(str, aConvertThis) )
    {
        this->world->send_cheat(15);
        return true;
    }
    if( strstr(str, aBigMomma) )
    {
        this->world->send_cheat(16);
        return true;
    }
    if( strstr(str, aMiniwinsett) )
    {
        this->world->send_cheat(17);
        return true;
    }
    if( strstr(str, aGrantlinkspenc) )
    {
        this->world->send_cheat(18);
        return true;
    }
    if( strstr(str, aKingArthur) )
    {
        this->world->send_cheat(19);
        return true;
    }
    if( !strcmp(encstr, aW_DwChxdw) )
    {
        this->world->send_cheat(0);
        return true;
    }
    if( !strcmp(encstr, aAmC3c2WAm) )
    {
        this->world->send_cheat(1);
        return true;
    }
    if( !strcmp(encstr, aHx3ccw_amDwLC_) )
    {
        this->world->send_cheat(2);
        return true;
    }
    if( !strcmp(encstr, a_L1z_am_Hx) )
    {
        this->world->send_cheat(3);
        return true;
    }
    if( !strcmp(encstr, aJmLdw1z__j3c_C) )
    {
        this->world->send_cheat(4);
        return true;
    }
    if( !strcmp(encstr, a_jw1L_JmLdwC_L) )
    {
        this->world->send_cheat(7);
        return true;
    }
    if( !strcmp(encstr, a__) )
    {
        this->world->send_cheat(8);
        return true;
    }
    if( !strcmp(encstr, a_HxCwHxLdw) )
    {
        this->world->send_cheat(10);
        return true;
    }
    if( !strcmp(encstr, a_Hx3ccwL_Am) )
    {
        this->world->send_cheat(11);
        return true;
    }
    if( !strcmp(encstr, aCam__j1Hx) )
    {
        this->world->send_cheat(12);
        return true;
    }
    if( !strcmp(encstr, aL3c_C) )
    {
        this->world->send_cheat(13);
        return true;
    }
    if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v3->vfptr) )
    {
        if( !strcmp(encstr, a_Lam_Lam_Lam) )
        {
            this->world->send_cheat(100);
            return true;
        }
        if( !strcmp(encstr, aCwL1) )
        {
            this->world->send_cheat(201);
            return true;
        }
        if( !strcmp(encstr, aCwL2) )
        {
            this->world->send_cheat(202);
            return true;
        }
        if( !strcmp(encstr, aCwL3) )
        {
            this->world->send_cheat(203);
            return true;
        }
        if( !strcmp(encstr, aCwL4) )
        {
            this->world->send_cheat(204);
            return true;
        }
        if( !strcmp(encstr, aCwL5) )
        {
            this->world->send_cheat(205);
            return true;
        }
        if( !strcmp(encstr, aCwL6) )
        {
            this->world->send_cheat(206);
            return true;
        }
        if( !strcmp(encstr, aCwL7) )
        {
            this->world->send_cheat(207);
            return true;
        }
        if( !strcmp(encstr, aCwL9) )
        {
            this->world->send_cheat(208);
            return true;
        }
    }
    if( !strcmp(encstr, a_HxLCwhxL) )
    {
        this->world->send_cheat(101);
        return true;
    }
    if( !strcmp(encstr, aAm1L1zdw) )
    {
        this->world->send_cheat(103);
        return true;
    }
    if( strcmp(encstr, a1zhxLhx) )
    {
        if( !strcmp(encstr, aWAmwWAmDwLWLs_) )
        {
            v6 = RGE_Base_Game::get_player((RGE_Base_Game *)&v3->vfptr);
            ((void (*)(RGE_Game_World *, _DWORD, signed int))v6->vfptr->turn_sound_off)(v6, 0, 1148846080);
            return true;
        }
        if( !strcmp(encstr, a3cLdwhx1zam) )
        {
            v7 = RGE_Base_Game::get_player((RGE_Base_Game *)&v3->vfptr);
            ((void (*)(RGE_Game_World *, signed int, signed int))v7->vfptr->turn_sound_off)(v7, 3, 1148846080);
            return true;
        }
        if( !strcmp(encstr, a43_13ccw) )
        {
            v8 = RGE_Base_Game::get_player((RGE_Base_Game *)&v3->vfptr);
            ((void (*)(RGE_Game_World *, signed int, signed int))v8->vfptr->turn_sound_off)(v8, 1, 1148846080);
            return true;
        }
        if( !strcmp(encstr, aHx_jhx) )
        {
            v9 = RGE_Base_Game::get_player((RGE_Base_Game *)&v3->vfptr);
            ((void (*)(RGE_Game_World *, signed int, signed int))v9->vfptr->turn_sound_off)(v9, 2, 1148846080);
            return true;
        }
        if( !strcmp(encstr, a1AmL_1) )
        {
            TRIBE_Command::command_quick_build((TRIBE_Command *)v3->world->commands, v3->quick_build == 0);
            return true;
        }
        if( !strcmp(encstr, a_L1z_Hx__) )
        {
            this->world->send_cheat(220);
            return true;
        }
        if( !strcmp(encstr, aAmTamhxChxw) )
        {
            this->world->send_cheat(230);
            return true;
        }
        if( !strcmp(encstr, aDwJm1z) )
        {
            this->world->send_cheat(231);
            return true;
        }
        sscanf(str, aS, tempStr1);
        if( !strcmp(tempStr1, aSelectobj) )
        {
            sscanf(text, aSD, &target);
            v10 = RGE_Game_World::object(v3->world, target);
            if( v10 )
            {
                v10->selected = 1;
                v3->world->players[playerID]->selected_obj = v10;
            }
        }
        if( !strcmp(tempStr1, aRunplay) )
        {
            sscanf(text, aSDSD, &commander, playName, &target);
            v11 = AIPlayBook::playNumber(v3->world->playbook, playName);
            if( v11 != -1 )
            {
                ((void (__stdcall *)(int, int, int))v3->world->players[playerID]->vfptr->sendPlayCommand)(
                    commander,
                    target,
                    v11);
                return true;
            }
            return true;
        }
        if( !strcmp(encstr, aS_am_j1) )
        {
            ((void (__stdcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD))v3->world->players[playerID]->vfptr->sendAICommand)(
                playerID,
                0,
                0,
                0,
                0);
            return true;
        }
        return false;
    }
    v4 = (RGE_Player *)RGE_Base_Game::get_player((RGE_Base_Game *)&v3->vfptr);
    RGE_Player::unselect_object(v4);
    if( v3->game_mode == 6 && v3->sub_game_mode == 1 )
        (*(void (**)(TRIBE_Game *, _DWORD, _DWORD))&v3->vfptr->gap8[8])(v3, 0, 0);
    (*(void (**)(TRIBE_Game *, _DWORD))&v3->vfptr->gap8[12])(v3, 0);

    return true;
}

void TRIBE_Game::let_game_begin()
{
    TRIBE_Game *v1; // ebp@1
    void (*v2)(TRIBE_Game *, signed int, char *, signed int); // ebx@2
    char *v3; // edx@19
    const char *v4; // edi@19
    int v5; // eax@20
    int v6; // eax@21
    char *v7; // edx@26
    const char *v8; // edi@26
    char *v9; // edx@34
    const char *v10; // edi@34
    int v11; // eax@40
    int v12; // ST14_4@40
    int v13; // eax@40
    unsigned int v14; // ebx@40
    char *v15; // edi@40
    char *v16; // edi@40
    char *v17; // esi@40
    RGE_Game_World *v18; // eax@40
    int v19; // ecx@40
    signed int v20; // ebx@40
    int v21; // eax@41
    unsigned int v22; // ebx@42
    char *v23; // edi@42
    char *v24; // edi@42
    char *v25; // esi@42
    RGE_Game_World *v26; // eax@42
    int v27; // ecx@42
    signed int v28; // ebx@42
    int v29; // eax@43
    unsigned int v30; // ebx@44
    char *v31; // edi@44
    char *v32; // edi@44
    char *v33; // esi@44
    RGE_Game_World *v34; // eax@44
    int v35; // ecx@44
    signed int v36; // ebx@44
    int v37; // eax@45
    TMusic_System *v38; // ecx@46
    char v39; // al@47
    signed int v40; // [sp+8h] [bp-850h]@2
    signed int v41; // [sp+8h] [bp-850h]@11
    char *v42; // [sp+Ch] [bp-84Ch]@2
    char *v43; // [sp+Ch] [bp-84Ch]@11

    char int_str[10];

    char age_str[256];
    char res_str[256];
    char vic_str[256];
    char str[1024];

    &panel_system->setCurrentPanel("Game Screen", 0);
    &panel_system->destroyPanel("Status Screen");
    &panel_system->destroyPanel("Multiplayer");

    run_log(aGameStarted, 1);

    switch( this->mapType() ){

    case 0:
        v40 = 10602;
        break;

    case 1:
        v40 = 10603;
        break;

    case 2:
        v40 = 10604;
        break;

    case 3:
        v40 = 10605;
        break;

    case 4:
        v40 = 10606;
        break;

    case 5:
        v40 = 10607;
        break;

    case 6:
        v40 = 10608;
        break;

    default:
        v40 = 10244;
        break;
    }

    char map_type_str[20];
    this->get_string(v40, map_type_str, sizeof(map_type_str));

    char map_size_str[20];

    switch( this->mapSize() ){

    case 0:
        v43 = map_size_str;
        v41 = 10611;
        break;

    case 1:
        v43 = map_size_str;
        v41 = 10612;
        break;

    case 2:
        v43 = map_size_str;
        v41 = 10613;
        break;

    case 3:
        v43 = map_size_str;
        v41 = 10614;
        break;

    case 4:
        v43 = map_size_str;
        v41 = 10615;
        break;

    case 5:
        v43 = map_size_str;
        v41 = 10616;
        break;

    default:
        v43 = map_size_str;
        v41 = 10244;
        break;
    }

    this->get_string(v41, v43, sizeof(map_size_str));

    sprintf(
        str,
        "    randomgame=%d, randommap=%d, mapsize=%s, maptype=%s",
        this->save_random_game_seed,
        this->save_random_map_seed,
        map_size_str,
        map_type_str);

    run_log(str, 0);

    switch( this->victoryType() ){

    case 0:
        v3 = vic_str;
        v4 = "Default";
        break;

    case 7:
        v5 = this->victoryAmount();
        sprintf(vic_str, "Time(%d)", v5);
        goto LABEL_25;

    case 8:
        v6 = this->victoryAmount();
        sprintf(vic_str, "Score(%d)", v6);
        goto LABEL_25;

    case 9:
        v3 = vic_str;
        v4 = "Standard";
        break;

    default:
        v3 = vic_str;
        v4 = "Unknown";
        break;
    }

    strcpy(v3, v4);

    LABEL_25:
    if( this->deathMatch() ){
        v7 = res_str;
        v8 = aDeathmatch;
    }else{
        switch( this->resourceLevel() ){

            case 0:
                v7 = res_str;
                v8 = aDefault;
                break;
            case 1:
                v7 = res_str;
                v8 = aLow;
                break;
            case 2:
                v7 = res_str;
                v8 = aMedium;
                break;
            case 3:
                v7 = res_str;
                v8 = aHigh;
                break;
            default:
                v7 = res_str;
                v8 = aUnknown;
                break;
        }
    }

    strcpy(v7, v8);

    switch( this->startingAge() ){

    case 0:
        v9 = age_str;
        v10 = aDefault;
        break;
    case 2:
        v9 = age_str;
        v10 = aStone;
        break;
    case 3:
        v9 = age_str;
        v10 = aTool;
        break;
    case 4:
        v9 = age_str;
        v10 = aBronze;
        break;
    case 5:
        v9 = age_str;
        v10 = aIron;
        break;
    default:
        v9 = age_str;
        v10 = aUnknown;
        break;
    }

    strcpy(v9, v10);
    char diff_str[256];
    strcpy(diff_str, "Unknown");

    this->get_string(this->difficulty() + 11216, diff_str, sizeof(diff_str));
    sprintf(str, "    resources=%s, age=%s, victory=%s, difficulty=%s", res_str, age_str, vic_str, diff_str);
    run_log(str, 0);

    sprintf(str, aFulltechDRevea, this->fullTechTree(), this->fullVisibility());
    run_log(str, 0);
    sprintf(str, aNumplayersD, v1->world->player_num - 1);
    v14 = strlen(aPlayers) + 1;
    v15 = &str[strlen(str)];
    qmemcpy(v15, aPlayers, 4 * (v14 >> 2));
    v17 = &aPlayers[4 * (v14 >> 2)];
    v16 = &v15[4 * (v14 >> 2)];
    v18 = v1->world;
    v19 = v14 & 3;
    v20 = 1;
    qmemcpy(v16, v17, v19);
    if( v18->player_num > 1 )
    {
        do
        {
            v21 = TRIBE_Game::playerColor(v1, v20 - 1);
            sprintf(int_str, aD_3, v21);
            strcat(str, int_str);
            ++v20;
        }
        while( v20 < v1->world->player_num );
    }
    v22 = strlen(aTeams) + 1;
    v23 = &str[strlen(str)];
    qmemcpy(v23, aTeams, 4 * (v22 >> 2));
    v25 = &aTeams[4 * (v22 >> 2)];
    v24 = &v23[4 * (v22 >> 2)];
    v26 = v1->world;
    v27 = v22 & 3;
    v28 = 1;
    qmemcpy(v24, v25, v27);
    if( v26->player_num > 1 )
    {
        do
        {
            v29 = RGE_Base_Game::playerTeam((RGE_Base_Game *)&v1->vfptr, v28 - 1);
            sprintf(int_str, aD_3, v29 - 1);
            strcat(str, int_str);
            ++v28;
        }
        while( v28 < v1->world->player_num );
    }
    v30 = strlen(aCivs) + 1;
    v31 = &str[strlen(str)];
    qmemcpy(v31, aCivs, 4 * (v30 >> 2));
    v33 = &aCivs[4 * (v30 >> 2)];
    v32 = &v31[4 * (v30 >> 2)];
    v34 = v1->world;
    v35 = v30 & 3;
    v36 = 1;
    qmemcpy(v32, v33, v35);
    if( v34->player_num > 1 )
    {
        do
        {
            v37 = TRIBE_Game::civilization(v1, v36 - 1);
            sprintf(int_str, aD, v37);
            strcat(str, int_str);
            ++v36;
        }
        while( v36 < v1->world->player_num );
    }
    run_log(str, 0);
    v38 = v1->music_system;
    if( v38 )
    {
        v39 = v38->music_type;
        switch( v39 )
        {
            case 1:
                TMusic_System::play_tracks(v38, 5, 14, 1, 0, 0);
                break;
            case 2:
                TMusic_System::play_tracks(v38, 1, v38->track_count, 1, 0, 0);
                break;
            case 3:
                TMusic_System::stop_track(v38);
                break;
        }
        v1->started_menu_music = 0;
    }
    RGE_Base_Game::reset_timings((RGE_Base_Game *)&v1->vfptr);
    (*(void (**)(TRIBE_Game *, signed int))&v1->vfptr->gap8[4])(v1, 4);
    if( RGE_Base_Game::singlePlayerGame((RGE_Base_Game *)&v1->vfptr) == 1 )
        RGE_Base_Game::set_paused((RGE_Base_Game *)&v1->vfptr, 0, 0);
    v1->auto_paused = 0;
    TChat::ClearChat(chat);
    TChat::setInChatGroup(chat, v1->world->curr_player, 1);
    if( v1->mouse_pointer && v1->prog_active && !IsIconic(v1->prog_window) )
        TMousePointer::center(v1->mouse_pointer);
    RGE_Base_Game::enable_input((RGE_Base_Game *)&v1->vfptr);
}

int TRIBE_Game::start_scenario_editor( char *scenario_name_in, int is_multi_player_in )
{
    this->disable_input();

    &panel_system->destroyPanel("Scenario Editor Screen");

    TRIBE_Screen_Sed *v5 = new TRIBE_Screen_Sed(scenario_name_in, is_multi_player_in);
    if( v5 == nullptr ||
        v5->error_code != ErrorCode::None ){

        char *v8;

        switch( true ){

        case &panel_system->panel("Scenario Editor Open"):
            v8 = "Scenario Editor Open";
            break;

        case &panel_system->panel("Scenario Editor Menu"):
            v8 = "Scenario Editor Menu";
            break;

        default:
            v8 = "Blank Screen";
            break;
        }

        &panel_system->setCurrentPanel(v8, 0);

        &panel_system->destroyPanel("Scenario Editor Screen");
        &panel_system->destroyPanel("Status Screen");

        this->enable_input();

        return false;

    }else{
        if( this->music_system ){
            this->music_system->stop_track();
            this->started_menu_music = 0;
        }
        &panel_system->setCurrentPanel("Scenario Editor Screen", 0);

        &panel_system->destroyPanel("Scenario Editor Open");
        &panel_system->destroyPanel("Scenario Editor Menu");
        &panel_system->destroyPanel("Status Screen");

        this->mouse_pointer->center();

        this->enable_input();

        return true;
    }
}

void TRIBE_Game::send_game_options()
{
    TRIBE_Game::send_game_options::combined_options combined_options;

    if( this->comm_handler )
    {
        this->get_game_options(&combined_options.rge_options);
        this->get_tribe_options(&combined_options.tribe_options);
        this->comm_handler->SetMyGameOptions((char *)&combined_options, 0x114u);
    }
}

void TRIBE_Game::receive_game_options()
{
    if( this->comm_handler ){
        unsigned int size = 0;
        char *v3 = this->comm_handler->GetMyGameOptions(&size);
        char *v4 = v3;
        if( v3 ){
            if( size == 276 ){
                this->set_game_options(v3);
                this->set_tribe_options((TRIBE_Game::TRIBE_Game_Options *)(v4 + 168));
            }
        }
    }
}

void TRIBE_Game::set_tribe_options( TRIBE_Game::TRIBE_Game_Options *options )
{
    this->setMapSize(           options->mapSizeValue);
    this->setMapType(           options->mapTypeValue);
    this->setAnimals(           options->animalsValue);
    this->setPredators(         options->predatorsValue);
    this->setVictoryType(       options->victoryTypeValue,
                                options->victoryAmountValue);
    this->setAllowTrading(      options->allowTradingValue);
    this->setLongCombat(        options->longCombatValue);
    this->setRandomizePositions(options->randomizePositionsValue);
    this->setFullTechTree(      options->fullTechTreeValue);
    this->setResourceLevel(     options->resourceLevelValue);
    this->setStartingAge(       options->startingAgeValue);
    this->setStartingUnits(     options->startingUnitsValue);
    this->setDeathMatch(        options->deathMatchValue);
    this->setPopLimit(          options->popLimitValue);
    i = 0;
    do
    {
        this->setCivilization(  i, options->civilizationValue  [i]);
        this->setScenarioPlayer(i, options->scenarioPlayerValue[i]);
        this->setPlayerColor(   i, options->playerColorValue   [i]);
        this->setComputerName(  i, options->computerNameValue  [i]);
    }
    while( ++i < RGE_PLAYERS_COUNT );
}

void TRIBE_Game::get_tribe_options( TRIBE_Game::TRIBE_Game_Options *options )
{
    options->mapSizeValue            = this->mapSize();
    options->mapTypeValue            = this->mapType();
    options->animalsValue            = this->animals();
    options->predatorsValue          = this->predators();
    options->victoryTypeValue        = this->victoryType();
    options->victoryAmountValue      = this->victoryAmount();
    options->allowTradingValue       = this->allowTrading();
    options->longCombatValue         = this->longCombat());
    options->randomizePositionsValue = this->randomizePositions();
    options->fullTechTreeValue       = this->fullTechTree();
    options->resourceLevelValue      = this->resourceLevel();
    options->startingAgeValue        = this->startingAge();
    options->startingUnitsValue      = this->startingUnits();
    options->deathMatchValue         = this->deathMatch();
    options->popLimitValue           = this->popLimit();
    i = 0;
    do
    {
        options->civilizationValue[i]   = this->civilization(i);
        options->scenarioPlayerValue[i] = this->scenarioPlayer(i);
        options->playerColorValue[i]    = this->playerColor(i);
        options->computerNameValue[i]   = this->computerName(i);
    }
    while( ++i < RGE_PLAYERS_COUNT );
}

void TRIBE_Game::setMapSize( MapSize v )
{
    int s;

    switch( this->tribe_game_options.mapSizeValue = v )
    {
        case 0:
            s = 72;
            break;

        case 1:
            s = 96;
            break;

        case 2:
            s = 120;
            break;

        case 3:
            s = 144;
            break;

        case 4:
            s = 200;
            break;

        case 5:
            s = 250;
            break;

        default:
            return;
    }

    RGE_Base_Game::setMapSize(s, s, 8);
}

char aTemp_0[4] = "TEMP";

char *TRIBE_Game::gameSummary()
{
    temp_0[0] = 0;
    return temp_0;
}

RGE_Base_Game *TRIBE_Game::wnd_proc(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    if( msg <= 0x200 )
    {
        if( msg == 512 )
        {
            if( this->prog_mode == 1 )
                SetCursor(0);
        }
        else if( msg == 7 )
        {
            if( this->input_enabled )
                this->enable_input();
            else
                this->disable_input();
        }
        return this->wnd_proc(wnd, msg, wparam, lparam);
    }
    if( msg != 513 && msg != 516 || this->prog_mode != 1 )
    {
        return this->wnd_proc(wnd, msg, wparam, lparam);
    }
    this->stop_video(1);

    return (RGE_Base_Game*)NULL;
}

int TRIBE_Game::handle_idle()
{
    TRIBE_Game *v1; // ebp@1
    int result; // eax@1
    signed int v3; // ebx@4
    int v4; // eax@4
    TRIBE_Screen_Wait *v5; // eax@23
    TRIBE_Screen_Game *v6; // ecx@30

    int retval;
    char str[100];
    char msg[2304];

    v1 = this;

    result = this->handle_idle();

    retval = result;
    if( result )
    {
        if( this->inHandleIdle )
        {
            L->Log(aAlreadyInHandl, this->world->world_time);

            result = 0;
        }
        else
        {
            v3 = 1;
            this->inHandleIdle = 1;

            color_log(76, 76, 5);
            color_log(76, 22, 5);

            if( this->prog_mode == 1 && this->video_window )
            {
                if( debug_timeGetTime() - this->last_video_time >= 0x3E8 )
                {
                    SendMessageA(v1->video_window, 0x46Au, 0x64u, (LPARAM)str);
                    if( !str[0] || !strcmp(str, aStopped) )
                    {
                        this->stop_video(1);
                    }
                    else if( !this->video_paused && !strcmp(str, aPaused) )
                    {
                        SendMessageA(this->video_window, 0x855u, 0, 0);
                    }
                    this->last_video_time = debug_timeGetTime();
                }
            }
            else if( v4 == 3 )
            {
                if( this->comm_handler->MultiplayerGameStart() )
                {
                    color_log(76, 36, 5);

                    this->let_game_begin();
                }
                else
                {
                    color_log(76, 84, 5);

                    if( debug_timeGetTime() - last_wait_time >= 0x1F4 )
                    {
                        (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v1->vfptr->gap8[24])(
                            v1,
                            1108,
                            msg,
                            2304);

                        strcat(msg, Str);
                        do
                        {
                            if( v3 != this->comm_handler->WhoAmI() &&
                                this->comm_handler->IsPlayerHuman(v3) )
                            {
                                strcat(msg, Str);
                                strcat(msg, TCommunications_Handler::WaitingOnNamedInfo(v1->comm_handler, v3));
                            }
                        }
                        while( ++v3 < RGE_PLAYERS_COUNT );

                        if( v5 = (TRIBE_Screen_Wait *)@panel_system->panel(aMultiplayerWai) )
                            v5->set_text(msg);

                        last_wait_time = debug_timeGetTime();
                    }
                }
            }
            else
            {
                switch( v4 )
                {
                    case 4:
                    case 5:
                    case 6:
                        color_log(76, 50, 5);
                        if( !out_of_sync2 )
                        {
                            if( this->game_screen )
                                this->game_screen->handle_game_update();
                        }
                        break;
                }
            }
            color_log(76, 95, 5);

            result = retval;

            this->inHandleIdle = 0;
        }
    }
    return result;
}

int TRIBE_Game::handle_query_new_palette(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    int v5 = 1;
    if( this->prog_mode == 1 )
    {
        if( this->video_window &&
            this->video_hi_color == 0 )
        {
            SendMessageA(this->video_window, 0x476u, 0, 0);
            return 1;
        }
    }
    else
    {
        v5 = this->handle_query_new_palette(wnd, msg, wparam, lparam);
    }
    return v5;
}

int TRIBE_Game::handle_activate(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    this->handle_activate(wnd, msg, wparam, lparam);

    if( this->prog_mode == 1 &&
        this->video_window )
    {
        if( wparam == 1 &&
            this->video_paused )
        {
            SendMessageA(this->video_window, 0x855u, 0, 0);

            this->video_paused = 0;

            return true;
        }
        if( this->video_paused == 0 )
        {
            SendMessageA(this->video_window, 0x809u, 0, 0);

            this->video_paused = 1;
        }
    }
    return true;
}

int TRIBE_Game::action_user_command(unsigned int val1, unsigned int val2)
{
    TRIBE_Game *v3; // esi@1
    int v4; // eax@1
    TEasy_Panel *v5; // eax@3
    TEasy_Panel *v6; // eax@5
    unsigned int v7; // eax@21
    TRIBE_Screen_Status_Message *v8; // eax@22
    unsigned int v9; // eax@26
    TEasy_Panel *v10; // eax@26
    TRIBE_Screen_Game *v11; // ecx@29
    TRIBE_Screen_Game *v12; // ecx@31
    int v13; // eax@39
    int v14; // eax@39
    char msg[256]; // [sp+Ch] [bp-210h]@26
    char temp_str[256]; // [sp+110h] [bp-10Ch]@39
    int v18; // [sp+218h] [bp-4h]@22

    v3 = this;
    v4 = this->prog_mode;
    if( v4 == 3 )
    {
        switch( val1 )
        {
            case 0x17A8u:
            case 0x17A9u:
            case 0x17AAu:
            case 0x17ABu:
            case 0x17B2u:
            case 0x17B6u:
                TRIBE_Game::quit_game(this);
                &panel_system->destroyPanel(aMultiplayerWai);
                &panel_system->destroyPanel("Status Screen");
                v5 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
                if( v5 )
                    goto LABEL_13;
                break;

            case 0x17ACu:
            case 0x17B7u:
                this->vfptr->reset_comm((RGE_Base_Game *)this);
                RGE_Base_Game::setSinglePlayerGame((RGE_Base_Game *)&v3->vfptr, 1);
                TRIBE_Game::quit_game(v3);
                &panel_system->destroyPanel(aMultiplayerWai);
                &panel_system->destroyPanel("Status Screen");
                v6 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
                if( v6 )
                    TEasy_Panel::popupOKDialog(v6, 9673, 0, 450, 100);
                break;

            default:
                return 1;
        }
    }
    else if( v4 == 4 || v4 == 6 || v4 == 5 )
    {
        switch( val1 )
        {
            case 0x17B2u:
                if( this->game_screen )
                {
                    RGE_Player::loss_if_game_on(this->world->players[this->world->curr_player]);
                    TRIBE_Game::do_game_over(v3);
                    v5 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
                    if( v5 )
LABEL_13:
                        TEasy_Panel::popupOKDialog(v5, 9673, 0, 450, 100);
                }
                break;

            case 0x17B0u:
                if( this->game_screen )
                {
                    this->play_sound(2);
                    TRIBE_Screen_Game::display_system_message(v3->game_screen, ::msg);
                }
                if( RGE_Base_Game::check_prog_argument((RGE_Base_Game *)&v3->vfptr, aSkipsyncsave) )
                {
                    if( !out_of_sync )
                    {
                        v7 = TCommunications_Handler::WhoAmI(v3->comm_handler);
                        if( TCommunications_Handler::IsPlayerOutOfSync(v3->comm_handler, v7, val2) )
                        {
                            out_of_sync = 1;
                            out_of_sync2 = 1;
                            v8 = (TRIBE_Screen_Status_Message *)operator new(0x47Cu);
                            v18 = 0;
                            if( v8 )
                                TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(v8, aTempScreen, message_in, 0, -1);
                            v18 = -1;
                            TPanelSystem::setCurrentPanel(&panel_system, aTempScreen, 0);
                            TRIBE_Game::close_game_screens(v3, 1);
                            if( do_debug_random )
                            {
                                debug_random_write();
                                dump_vismap_log();
                            }
                            v9 = TCommunications_Handler::WhoAmI(v3->comm_handler);
                            sprintf(msg, aSyncerrD_gam, v9);
                            TRIBE_Game::save_game(v3, msg);
                            RGE_Player::loss_if_game_on(v3->world->players[v3->world->curr_player]);
                            TRIBE_Game::do_game_over(v3);
                            v10 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
                            if( v10 )
                                TEasy_Panel::popupOKDialog(v10, 2406, 0, 450, 100);
                            &panel_system->destroyPanel(aTempScreen);
                        }
                    }
                }
                else if( !out_of_sync )
                {
                    out_of_sync = 1;

                    if( this->comm_handler->IsHost() )
                        this->world->commands->command_save_game();
                }
                break;

            case 0x17A2u:
                v11 = this->game_screen;
                if( v11 )
                    TRIBE_Screen_Game::handle_pause(v11);
                break;

            case 0x17A3u:
                v12 = this->game_screen;
                if( v12 )
                    TRIBE_Screen_Game::handle_resume(v12);
                break;

            case 0x17D5u:
                if( this->game_screen )
                {
                    this->play_sound(2);
                    TRIBE_Screen_Game::handleChatReceived(v3->game_screen, val2);
                }
                break;

            case 0x17BDu:
                if( RGE_Base_Game::playerID((RGE_Base_Game *)&this->vfptr, val2) != this->world->curr_player
                    && v3->game_screen
                    && RGE_Base_Game::playerID((RGE_Base_Game *)&v3->vfptr, val2) > 0
                    && !(&player_dropped)[val2] )
                {
                    RGE_Base_Game::play_sound((RGE_Base_Game *)&v3->vfptr, 2);
                    (*(void (**)(TRIBE_Game *, signed int, char *, signed int))&v3->vfptr->gap8[24])(
                        v3,
                        1217,
                        temp_str,
                        256);
                    v13 = RGE_Base_Game::playerID((RGE_Base_Game *)&v3->vfptr, val2);
                    sprintf(msg, temp_str, v3->world->players[v13]->name);
                    TRIBE_Screen_Game::display_system_message(v3->game_screen, msg);
                    v14 = RGE_Base_Game::playerID((RGE_Base_Game *)&v3->vfptr, val2);
                    TDebuggingLog::Log(L, aProblemCommuni, v3->world->players[v14]->name);
                }
                break;

            default:
                return 1;
        }
    }
    return 1;
}

int TRIBE_Game::action_key_down(
    unsigned int key,
    int repeat_count,
    int ctrl_key,
    int alt_key,
    int shift_key )
{
    if( this->prog_mode == 1 )
    {
        if( key != VK_RETURN )
        {
            if( key == VK_ESCAPE )
            {
                this->stop_video(false);

                return false;
            }
            if( key != VK_CAPITAL )
                return true;
        }
        this->stop_video(true);

        return false;
    }

    if( key == VK_F1 ){
        if( this->multiplayerGame() == 0 ||
            this->prog_mode != 4 &&
            this->prog_mode != 6 &&
            this->prog_mode != 7 &&
            this->prog_mode != 5 ){
            WinHelp(this->prog_window, "empires.hlp", HELP_CONTENTS, NULL);
        }
        return false;
    }
    return true;
}

bool TRIBE_Game::action_close()
{
    if( this->comm_handler ){
        this->disconnect_multiplayer_game();
        this->prog_mode = 0;
    }
    return true;
}

char __S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA[272];

char *TRIBE_Game::game_over_msg()
{
    if( this->world->players[this->world->curr_player]->game_status == 1 ){
        (*(void (__stdcall **)(signed int, signed int, signed int))&this->vfptr->gap8[24])(1150, 8830176, 256);
        return __S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA + 16;
    }else{
        (*(void (__stdcall **)(signed int, signed int, signed int))&this->vfptr->gap8[24])(1151, 8830176, 256);
        return __S9__1__calc_timing_text_TRIBE_Game__UAEXXZ_4EA + 16;
    }
}

int TRIBE_Game::get_achievement_info( char achievement, char **info )
{
    if( this->world ){
        return this->world->get_achievement(achievement, info);
    }else{
        return NULL;
    }
}

int TRIBE_Game::randomComputerName( int civ )
{
    int v2; // esi@1
    TRIBE_Game *v3; // ebp@1
    int v4; // ebx@1
    int v5; // esi@1
    int v6; // edx@2
    bool v7; // sf@5
    unsigned __int8 v8; // of@5
    int v9; // eax@7
    char scount[10]; // [sp+10h] [bp-Ch]@1
    int civa; // [sp+20h] [bp+4h]@1

    v2 = civ;
    v3 = this;
    (*(void (__stdcall **)(int, char *, signed int))&this->vfptr->gap8[24])(10 * (civ + 439), scount, 10);
    v4 = atoi(scount);
    civa = 0;
    v5 = 10 * v2;
    do
    {
        v6 = debug_rand(aCMsdevWorkA_41, 5409) % v4;
        if( v6 > v4 - 1 )
            v6 = v4 - 1;
        if( !v3->computerNameUsed[v5 / 0xAu][v6] )
            break;
        v8 = __OFSUB__(civa + 1, 20);
        v7 = civa++ - 19 < 0;
    }
    while( v7 ^ v8 );
    if( *(&v3->computerNameUsed[0][v6] + v5) == 1 )
    {
        v9 = 0;
        while( v3->computerNameUsed[v5 / 0xAu][v9] )
        {
            if( ++v9 >= 10 )
                goto LABEL_12;
        }
        v6 = v9;
    }
LABEL_12:
    *(&v3->computerNameUsed[0][v6] + v5) = 1;
    return v6 + v5 - 9;
}

void TRIBE_Game::resetRandomComputerName()
{
    memset(this->computerNameUsed, 0, sizeof(TRIBE_Game::computerNameUsed);
}

int TRIBE_Game::video_wnd_proc(
    HWND *hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam )
{
    switch( msg ){

    case 512:
        SetCursor(0);
        return 0;

    case 513:
    case 516:
        this->stop_video(1);
        return 0;

    default:
        return CallWindowProcA(
            this->old_video_wnd_proc,
            hWnd,
            msg,
            wParam,
            lParam);
    }
}

void TRIBE_Game::SetClickTables(
    MouseClickInfo *RC,
    int RCS,
    MouseClickInfo *LC,
    int LCS )
{
    this->MouseRightClickTable     = RC;
    this->MouseRightClickTableSize = RCS;
    this->MouseLeftClickTable      = LC;
    this->MouseLeftClickTableSize  = LCS;
}

void TRIBE_Game::set_interface_messages()
{
    if( this->prog_info->interface_style == 1 ){
        this->SetClickTables(
            &Tribe1btnMouseRightClickTable,
            Tribe1btnMouseRightClickTableSize,
            &Tribe1btnMouseLeftClickTable,
            Tribe1btnMouseLeftClickTableSize);
    }else{
        this->SetClickTables(
            &Tribe2btnMouseRightClickTable,
            Tribe2btnMouseRightClickTableSize,
            &Tribe2btnMouseLeftClickTable,
            Tribe2btnMouseLeftClickTableSize);
    }
}

int TRIBE_Game::setup_video_system()
{
    if( this->video_setup ){
        return true;
    }

    &panel_system->setCurrentPanel("Blank Screen", 0);

    this->mouse_off();
    this->video_double_size = 1;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_palette = this->draw_system->Pal;

    if( this->draw_system->ScreenMode == 2 ){

        SetCursor((HCURSOR)NULL);
        SetClassLongA(this->prog_window, -12, 0);

        this->mouse_pointer->Shutdown_Mouse();

        this->video_save_res_wid = this->draw_system->ScreenWidth;
        this->video_save_res_hgt = this->draw_system->ScreenHeight;

        if( this->check_prog_argument("8BITVIDEO") != true ){
            if( this->draw_system->IsModeAvail(640, 480, 16) ){

                L->Log("640x480 16bit success");

                if( this->video_changed_res = this->draw_system->SetDisplaySize(640, 480, 16) ){
                    this->video_double_size = 1;
                    this->video_hi_color = 1;

                    L->Log("640x480 16bit success");
                }
            }
            if( this->video_changed_res != true ){
                if( this->draw_system->ScreenWidth != 640 ){
                    if( this->draw_system->IsModeAvail(640, 480, 8) ){
                        L->Log("640x480 8bit success");

                        if( this->video_changed_res = this->draw_system->SetDisplaySize(640, 480, 8) ){
                            this->video_double_size = 1;

                            L->Log("640x480 8bit success");
                        }
                    }
                }
            }
        }
    }
    L->Log(aVideo_changed_, this->video_changed_res, this->video_double_size);
    v8 = v1->vfptr;
    (*(void (**)(TRIBE_Game *, signed int))&v1->vfptr->gap8[4])(v1, 1);
    v8->stop_sound_system((RGE_Base_Game *)v1);
    this->video_setup = 1;

    return true;
}

void TRIBE_Game::shutdown_video_system()
{
    if( this->video_setup ){

        if( this->video_changed_res ){

            this->draw_system->SetDisplaySize(this->video_save_res_wid, this->video_save_res_hgt, 8);
            this->draw_system->ClearPrimarySurface();
            this->draw_system->SetPalette(this->video_save_palette);
            this->video_changed_res = 0;
            this->draw_system->CheckSurfaces();
            this->draw_system->ClearRestored();
            this->check_paint();
            restore_mouse_after_paint = 1;
        }
        this->draw_system->ClearPrimarySurface();
        this->SetPalette(this->video_save_palette);
        this->set_render_all();
        InvalidateRect(this->prog_window, 0, 1);
        (*(void (**)(TRIBE_Game *, signed int))&this->vfptr->gap8[4])(v1, 2);
        this->restart_sound_system();
        this->set_mouse_cursor(LoadCursorA(0, (LPCSTR)0x7F00));
        this->mouse_on();
        this->video_setup = 0;
    }
}

void TRIBE_Game::disconnect_multiplayer_game()
{
    if( this->multiplayerGame() ){

        switch( this->prog_mode ){

        case 4:
        case 6:
        case 7:
        case 5:

            this->comm_handler->SendIResignMsg();
            this->comm_handler->ShutdownGameMessages();
            if( this->comm_handler->CountWaitingMessages() > 0 )
            {
                this->disable_input();
                this->show_status_message(1216, 0, -1);
                unsigned int v3 = debug_timeGetTime();
                unsigned int v4 = v3;
                while( 1 )
                {
                    if( !this->world )
                        break;
                    if( this->world->game_state == 1 )
                        break;
                    this->comm_handler->ShutdownGameMessages();
                    if( debug_timeGetTime() - v4 >= 0x1F4 )
                    {
                        if( !this->comm_handler->CountWaitingMessages() )
                            break;
                        v4 = debug_timeGetTime();
                        if( v4 - v3 >= 0x3A98 )
                            break;
                    }
                }
            }
            this->comm_handler->GameOver();
            this->comm_handler->UnlinkToLevel(SERVICE_AVAILABLE);

            break;
        }
    }else{
        this->comm_handler->GameOver();
    }
}

void TRIBE_Game::add_notification_loc(int x, int y)
{
    if( this->current_notification_loc < 0 ||
        this->notification_loc_x[this->current_notification_loc] != x ||
        this->notification_loc_y[this->current_notification_loc] != y ){

        this->current_notification_loc++;

        if( this->current_notification_loc >= 5 ){
            this->current_notification_loc = 0;
        }

        this->notification_loc_x[this->current_notification_loc] = x;
        this->notification_loc_y[this->current_notification_loc] = y;
    }
    this->current_notification_recalled = this->current_notification_loc;
}

void TRIBE_Game::goto_notification_loc()
{
    if( this->current_notification_recalled != -1 ){

        int x = this->notification_loc_x[this->current_notification_recalled];
        int y = this->notification_loc_y[this->current_notification_recalled];

        this->current_notification_recalled--;

        if( this->current_notification_recalled < 0 ){
            this->current_notification_recalled = 4;
        }

        if( this->notification_loc_x[this->current_notification_recalled] == -1 ||
            this->notification_loc_y[this->current_notification_recalled] == -1 ){
            this->current_notification_recalled = this->current_notification_loc;
        }

        this->get_player()->set_view_loc((double)x, (double)y);
    }
}

video_sub_wnd_proc(
    HWND *hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam )
{
    return rge_base_game->video_wnd_proc(hWnd, msg, wParam, lParam);
}
