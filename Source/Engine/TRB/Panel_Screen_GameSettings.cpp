
//----- (004B4880) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::TribeGameSettingsScreen(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  char *v2; // ebx@1
  TDrawArea *v3; // edi@3
  int v4; // eax@3
  TDropDownPanel **v5; // edi@7
  TDropDownPanel **v6; // edi@9
  TDropDownPanel **v7; // edi@11
  TDropDownPanel **v8; // edi@15
  TDropDownPanel **v9; // edi@17
  TDropDownPanel **v10; // edi@20
  TDropDownPanel **v11; // edi@22
  TDropDownPanel **v12; // edi@24
  TDropDownPanel **v13; // ebx@27
  int v14; // edi@28
  TDropDownPanel **v15; // edi@32
  TTextPanel **v16; // edi@46
  int v17; // ST10_4@51
  int v18; // ST0C_4@51
  int v19; // eax@51
  int v20; // ecx@53
  int v21; // eax@53
  TTextPanel **v22; // edi@54
  TPanel **v23; // ebx@56
  TPanel **v24; // edi@57
  TPanel *v25; // eax@58
  int v26; // [sp+1Ch] [bp-28h]@12
  char num_str[5]; // [sp+30h] [bp-14h]@29
  int v28; // [sp+40h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aGameSettingsSc);
  v28 = 0;
  v1->vfptr = (TPanelVtbl *)&TribeGameSettingsScreen::`vftable';
  TribeGameSettingsScreen::init_vars(v1);
  v1->chat_scr = (TribeMPSetupScreen *)TPanelSystem::panel(&panel_system, aMpSetupScreen);
  v2 = info_file_name_in;
  if ( !RGE_Base_Game::multiplayerGame(rge_base_game) )
    v2 = aScr2;
  v3 = rge_base_game->draw_area;
  v4 = RGE_Base_Game::multiplayerGame(rge_base_game);
  if ( !TEasy_Panel::setup((TEasy_Panel *)&v1->vfptr, v3, 0, v2, (v4 != 0) + 50052, 1, 0, 0, 0, 0, 1) )
  {
    v1->error_code = 1;
    return;
  }
  TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
  TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
  if ( TEasy_Panel::create_text(
         (TEasy_Panel *)&v1->vfptr,
         (TPanel *)&v1->vfptr,
         &v1->title,
         9750,
         20,
         10,
         600,
         30,
         1,
         1,
         0,
         1) )
  {
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->mapSizeLabel,
           10656,
           20,
           216,
           180,
           20,
           11,
           0,
           0,
           0) )
    {
      v5 = &v1->mapSizeDrop;
      if ( TEasy_Panel::create_drop_down(
             (TEasy_Panel *)&v1->vfptr,
             (TPanel *)&v1->vfptr,
             &v1->mapSizeDrop,
             180,
             100,
             20,
             236,
             180,
             24,
             11) )
      {
        TDropDownPanel::empty_list(*v5);
        TDropDownPanel::append_line(*v5, 10611, 0);
        TDropDownPanel::append_line(*v5, 10612, 1);
        TDropDownPanel::append_line(*v5, 10613, 2);
        TDropDownPanel::append_line(*v5, 10614, 3);
        TDropDownPanel::append_line(*v5, 10615, 4);
        TDropDownPanel::append_line(*v5, 10616, 5);
        TPanel::set_help_info((TPanel *)&(*v5)->vfptr, 30250, -1);
        if ( TEasy_Panel::create_text(
               (TEasy_Panel *)&v1->vfptr,
               (TPanel *)&v1->vfptr,
               &v1->mapTypeLabel,
               9691,
               220,
               216,
               180,
               20,
               11,
               0,
               0,
               0) )
        {
          v6 = &v1->mapTypeDrop;
          if ( TEasy_Panel::create_drop_down(
                 (TEasy_Panel *)&v1->vfptr,
                 (TPanel *)&v1->vfptr,
                 &v1->mapTypeDrop,
                 180,
                 100,
                 220,
                 236,
                 180,
                 24,
                 11) )
          {
            TDropDownPanel::empty_list(*v6);
            TDropDownPanel::append_line(*v6, 10602, 0);
            TDropDownPanel::append_line(*v6, 10603, 1);
            TDropDownPanel::append_line(*v6, 10604, 2);
            TDropDownPanel::append_line(*v6, 10605, 3);
            TDropDownPanel::append_line(*v6, 10606, 4);
            TDropDownPanel::append_line(*v6, 10607, 5);
            TDropDownPanel::append_line(*v6, 10608, 6);
            TDropDownPanel::append_line(*v6, 10609, 7);
            TDropDownPanel::append_line(*v6, 10610, 8);
            TPanel::set_help_info((TPanel *)&(*v6)->vfptr, 30251, -1);
            if ( TEasy_Panel::create_text(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->victoryTypeLabel,
                   10804,
                   20,
                   264,
                   180,
                   20,
                   11,
                   0,
                   0,
                   0) )
            {
              v7 = &v1->victoryTypeDrop;
              if ( TEasy_Panel::create_drop_down(
                     (TEasy_Panel *)&v1->vfptr,
                     (TPanel *)&v1->vfptr,
                     &v1->victoryTypeDrop,
                     180,
                     100,
                     20,
                     284,
                     180,
                     24,
                     11) )
              {
                TDropDownPanel::empty_list(*v7);
                v26 = 0;
                if ( RGE_Base_Game::scenarioGame(rge_base_game) )
                {
                  TDropDownPanel::append_line(*v7, 4327, 0);
                  v26 = 9;
                }
                TDropDownPanel::append_line(*v7, 4332, v26);
                TDropDownPanel::append_line(*v7, 4321, 1);
                TDropDownPanel::append_line(*v7, 4329, 7);
                TDropDownPanel::append_line(*v7, 4330, 8);
                TPanel::set_help_info((TPanel *)&(*v7)->vfptr, 30252, 155402);
                if ( TEasy_Panel::create_text(
                       (TEasy_Panel *)&v1->vfptr,
                       (TPanel *)&v1->vfptr,
                       &v1->timeLabel,
                       4329,
                       20,
                       312,
                       180,
                       20,
                       11,
                       0,
                       0,
                       0) )
                {
                  v8 = &v1->timeDrop;
                  if ( TEasy_Panel::create_drop_down(
                         (TEasy_Panel *)&v1->vfptr,
                         (TPanel *)&v1->vfptr,
                         &v1->timeDrop,
                         180,
                         100,
                         20,
                         332,
                         180,
                         24,
                         11) )
                  {
                    TDropDownPanel::empty_list(*v8);
                    TDropDownPanel::append_line(*v8, 9780, 15000);
                    TDropDownPanel::append_line(*v8, 9781, 13000);
                    TDropDownPanel::append_line(*v8, 9782, 11000);
                    TDropDownPanel::append_line(*v8, 9783, 9000);
                    TDropDownPanel::append_line(*v8, 9784, 7000);
                    TDropDownPanel::append_line(*v8, 9785, 5000);
                    TDropDownPanel::append_line(*v8, 9786, 3000);
                    TPanel::set_help_info((TPanel *)&(*v8)->vfptr, 30267, -1);
                    if ( TEasy_Panel::create_text(
                           (TEasy_Panel *)&v1->vfptr,
                           (TPanel *)&v1->vfptr,
                           &v1->scoreLabel,
                           4330,
                           20,
                           312,
                           180,
                           20,
                           11,
                           0,
                           0,
                           0) )
                    {
                      v9 = &v1->scoreDrop;
                      if ( TEasy_Panel::create_drop_down(
                             (TEasy_Panel *)&v1->vfptr,
                             (TPanel *)&v1->vfptr,
                             &v1->scoreDrop,
                             180,
                             100,
                             20,
                             332,
                             180,
                             24,
                             11) )
                      {
                        TDropDownPanel::empty_list(*v9);
                        TDropDownPanel::append_line(*v9, a3000, 3000);
                        TDropDownPanel::append_line(*v9, a2700, 2700);
                        TDropDownPanel::append_line(*v9, a2400, 2400);
                        TDropDownPanel::append_line(*v9, a2100, 2100);
                        TDropDownPanel::append_line(*v9, a1800, 1800);
                        TDropDownPanel::append_line(*v9, a1500, 1500);
                        TDropDownPanel::append_line(*v9, a1200, 1200);
                        TDropDownPanel::append_line(*v9, a900, 900);
                        TDropDownPanel::append_line(*v9, a800, 800);
                        TDropDownPanel::append_line(*v9, a700, 700);
                        TDropDownPanel::append_line(*v9, a600, 600);
                        TDropDownPanel::append_line(*v9, a500, 500);
                        TDropDownPanel::append_line(*v9, a400, 400);
                        TDropDownPanel::append_line(*v9, a300, 300);
                        TPanel::set_help_info((TPanel *)&(*v9)->vfptr, 30268, -1);
                        if ( TEasy_Panel::create_text(
                               (TEasy_Panel *)&v1->vfptr,
                               (TPanel *)&v1->vfptr,
                               &v1->victoryFixedText,
                               9689,
                               20,
                               264,
                               180,
                               92,
                               11,
                               1,
                               1,
                               1) )
                        {
                          ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v1->victoryFixedText->vfptr[1].set_rect)(
                            3,
                            v1->bevel_color1,
                            v1->bevel_color2,
                            v1->bevel_color3,
                            v1->bevel_color4,
                            v1->bevel_color5,
                            v1->bevel_color6);
                          if ( TEasy_Panel::create_text(
                                 (TEasy_Panel *)&v1->vfptr,
                                 (TPanel *)&v1->vfptr,
                                 &v1->ageLabel,
                                 9734,
                                 220,
                                 264,
                                 180,
                                 20,
                                 11,
                                 0,
                                 0,
                                 0) )
                          {
                            v10 = &v1->ageDrop;
                            if ( TEasy_Panel::create_drop_down(
                                   (TEasy_Panel *)&v1->vfptr,
                                   (TPanel *)&v1->vfptr,
                                   &v1->ageDrop,
                                   180,
                                   100,
                                   220,
                                   284,
                                   180,
                                   24,
                                   11) )
                            {
                              TDropDownPanel::empty_list(*v10);
                              TDropDownPanel::append_line(*v10, 4327, 0);
                              TDropDownPanel::append_line(*v10, 4206, 1);
                              TDropDownPanel::append_line(*v10, 4201, 2);
                              TDropDownPanel::append_line(*v10, 4202, 3);
                              TDropDownPanel::append_line(*v10, 4203, 4);
                              TDropDownPanel::append_line(*v10, 4204, 5);
                              TPanel::set_help_info((TPanel *)&(*v10)->vfptr, 30257, -1);
                              if ( TEasy_Panel::create_text(
                                     (TEasy_Panel *)&v1->vfptr,
                                     (TPanel *)&v1->vfptr,
                                     &v1->resourcesLabel,
                                     9735,
                                     220,
                                     312,
                                     180,
                                     20,
                                     11,
                                     0,
                                     0,
                                     0) )
                              {
                                v11 = &v1->resourcesDrop;
                                if ( TEasy_Panel::create_drop_down(
                                       (TEasy_Panel *)&v1->vfptr,
                                       (TPanel *)&v1->vfptr,
                                       &v1->resourcesDrop,
                                       180,
                                       100,
                                       220,
                                       332,
                                       180,
                                       24,
                                       11) )
                                {
                                  TDropDownPanel::empty_list(*v11);
                                  TDropDownPanel::append_line(*v11, 4327, 0);
                                  TDropDownPanel::append_line(*v11, 9737, 2);
                                  TDropDownPanel::append_line(*v11, 9738, 3);
                                  TPanel::set_help_info((TPanel *)&(*v11)->vfptr, 30258, -1);
                                  if ( TEasy_Panel::create_text(
                                         (TEasy_Panel *)&v1->vfptr,
                                         (TPanel *)&v1->vfptr,
                                         &v1->pathingLabel,
                                         9741,
                                         420,
                                         312,
                                         180,
                                         20,
                                         11,
                                         0,
                                         0,
                                         0) )
                                  {
                                    v12 = &v1->pathingDrop;
                                    if ( TEasy_Panel::create_drop_down(
                                           (TEasy_Panel *)&v1->vfptr,
                                           (TPanel *)&v1->vfptr,
                                           &v1->pathingDrop,
                                           180,
                                           100,
                                           420,
                                           332,
                                           180,
                                           24,
                                           11) )
                                    {
                                      TDropDownPanel::empty_list(*v12);
                                      TDropDownPanel::append_line(*v12, 9742, 0);
                                      TDropDownPanel::append_line(*v12, 9743, 1);
                                      TDropDownPanel::append_line(*v12, 9744, 2);
                                      TPanel::set_help_info((TPanel *)&(*v12)->vfptr, 30270, -1);
                                      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                      {
                                        if ( !TEasy_Panel::create_text(
                                                (TEasy_Panel *)&v1->vfptr,
                                                (TPanel *)&v1->vfptr,
                                                &v1->limitLabel,
                                                9747,
                                                420,
                                                216,
                                                180,
                                                20,
                                                11,
                                                0,
                                                0,
                                                0) )
                                          return;
                                        v13 = &v1->limitDrop;
                                        if ( !TEasy_Panel::create_drop_down(
                                                (TEasy_Panel *)&v1->vfptr,
                                                (TPanel *)&v1->vfptr,
                                                &v1->limitDrop,
                                                180,
                                                100,
                                                420,
                                                236,
                                                180,
                                                24,
                                                11) )
                                          return;
                                        TDropDownPanel::empty_list(*v13);
                                        v14 = 25;
                                        do
                                        {
                                          sprintf(num_str, aD_3, v14);
                                          TDropDownPanel::append_line(*v13, num_str, v14);
                                          v14 += 25;
                                        }
                                        while ( v14 <= 200 );
                                        TPanel::set_help_info((TPanel *)&(*v13)->vfptr, 30271, -1);
                                      }
                                      if ( TEasy_Panel::create_text(
                                             (TEasy_Panel *)&v1->vfptr,
                                             (TPanel *)&v1->vfptr,
                                             &v1->difficultyLabel,
                                             11215,
                                             420,
                                             264,
                                             180,
                                             20,
                                             11,
                                             0,
                                             0,
                                             0) )
                                      {
                                        v15 = &v1->difficultyDrop;
                                        if ( TEasy_Panel::create_drop_down(
                                               (TEasy_Panel *)&v1->vfptr,
                                               (TPanel *)&v1->vfptr,
                                               &v1->difficultyDrop,
                                               180,
                                               100,
                                               420,
                                               284,
                                               180,
                                               24,
                                               11) )
                                        {
                                          TDropDownPanel::empty_list(*v15);
                                          TDropDownPanel::append_line(*v15, 11220, 4);
                                          TDropDownPanel::append_line(*v15, 11219, 3);
                                          TDropDownPanel::append_line(*v15, 11218, 2);
                                          TDropDownPanel::append_line(*v15, 11217, 1);
                                          TDropDownPanel::append_line(*v15, 11216, 0);
                                          TPanel::set_help_info((TPanel *)&(*v15)->vfptr, 30269, -1);
                                          if ( TEasy_Panel::create_check_box(
                                                 (TEasy_Panel *)&v1->vfptr,
                                                 (TPanel *)&v1->vfptr,
                                                 v1->optionButton,
                                                 10,
                                                 360,
                                                 30,
                                                 30,
                                                 0,
                                                 0) )
                                          {
                                            if ( TEasy_Panel::create_text(
                                                   (TEasy_Panel *)&v1->vfptr,
                                                   (TPanel *)&v1->vfptr,
                                                   v1->optionText,
                                                   9729,
                                                   40,
                                                   360,
                                                   170,
                                                   30,
                                                   11,
                                                   0,
                                                   1,
                                                   0) )
                                            {
                                              TPanel::set_help_info((TPanel *)v1->optionButton[0], 30259, -1);
                                              if ( TEasy_Panel::create_check_box(
                                                     (TEasy_Panel *)&v1->vfptr,
                                                     (TPanel *)&v1->vfptr,
                                                     &v1->optionButton[2],
                                                     220,
                                                     360,
                                                     30,
                                                     30,
                                                     0,
                                                     0) )
                                              {
                                                if ( TEasy_Panel::create_text(
                                                       (TEasy_Panel *)&v1->vfptr,
                                                       (TPanel *)&v1->vfptr,
                                                       &v1->optionText[2],
                                                       9732,
                                                       250,
                                                       360,
                                                       170,
                                                       30,
                                                       11,
                                                       0,
                                                       1,
                                                       0) )
                                                {
                                                  TPanel::set_help_info((TPanel *)v1->optionButton[2], 30263, -1);
                                                  if ( TEasy_Panel::create_check_box(
                                                         (TEasy_Panel *)&v1->vfptr,
                                                         (TPanel *)&v1->vfptr,
                                                         &v1->optionButton[1],
                                                         430,
                                                         360,
                                                         30,
                                                         30,
                                                         0,
                                                         0) )
                                                  {
                                                    if ( TEasy_Panel::create_text(
                                                           (TEasy_Panel *)&v1->vfptr,
                                                           (TPanel *)&v1->vfptr,
                                                           &v1->optionText[1],
                                                           9724,
                                                           460,
                                                           360,
                                                           170,
                                                           30,
                                                           11,
                                                           0,
                                                           1,
                                                           0) )
                                                    {
                                                      TPanel::set_help_info((TPanel *)v1->optionButton[1], 30260, -1);
                                                      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                                      {
                                                        if ( !TEasy_Panel::create_check_box(
                                                                (TEasy_Panel *)&v1->vfptr,
                                                                (TPanel *)&v1->vfptr,
                                                                &v1->optionButton[3],
                                                                430,
                                                                395,
                                                                30,
                                                                30,
                                                                0,
                                                                0)
                                                          || !TEasy_Panel::create_text(
                                                                (TEasy_Panel *)&v1->vfptr,
                                                                (TPanel *)&v1->vfptr,
                                                                &v1->optionText[3],
                                                                9723,
                                                                460,
                                                                395,
                                                                165,
                                                                30,
                                                                11,
                                                                0,
                                                                1,
                                                                0) )
                                                        {
                                                          return;
                                                        }
                                                        TPanel::set_help_info((TPanel *)v1->optionButton[3], 30264, -1);
                                                      }
                                                      v1->scenarioListX = 20;
                                                      v1->scenarioListY = 60;
                                                      v1->scenarioListWidth = 600;
                                                      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                                        v1->scenarioListHeight = 111;
                                                      else
                                                        v1->scenarioListHeight = 24;
                                                      v16 = (TTextPanel **)&v1->scenarioList;
                                                      if ( TEasy_Panel::create_list(
                                                             (TEasy_Panel *)&v1->vfptr,
                                                             (TPanel *)&v1->vfptr,
                                                             &v1->scenarioList,
                                                             v1->scenarioListX,
                                                             v1->scenarioListY,
                                                             v1->scenarioListWidth,
                                                             v1->scenarioListHeight,
                                                             11) )
                                                      {
                                                        TTextPanel::set_second_column_pos(
                                                          *v16,
                                                          (v1->scenarioListWidth - 60) * v1->pnl_wid / v1->ideal_width);
                                                        if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                                        {
                                                          (*(void (__stdcall **)(signed int))&(*v16)->vfptr[1].gap4[0])(9725);
                                                          TPanel::set_help_info((TPanel *)&(*v16)->vfptr, 30265, -1);
                                                          if ( !TEasy_Panel::create_auto_scrollbar(
                                                                  (TEasy_Panel *)&v1->vfptr,
                                                                  &v1->scenarioScrollbar,
                                                                  *v16,
                                                                  20) )
                                                            return;
                                                        }
                                                        else
                                                        {
                                                          (*v16)->handle_mouse_input = 0;
                                                          TListPanel::setDrawHighlightBar((TListPanel *)*v16, 0);
                                                          TTextPanel::set_spacer_size(*v16, 0);
                                                        }
                                                        v17 = v1->scenarioListY - 20;
                                                        v18 = v1->scenarioListX;
                                                        v19 = -(RGE_Base_Game::multiplayerGame(rge_base_game) != 0);
                                                        LOBYTE(v19) = v19 & 0xDE;
                                                        if ( TEasy_Panel::create_text(
                                                               (TEasy_Panel *)&v1->vfptr,
                                                               (TPanel *)&v1->vfptr,
                                                               &v1->scenarioTitle,
                                                               v19 + 9760,
                                                               v18,
                                                               v17,
                                                               300,
                                                               20,
                                                               4,
                                                               0,
                                                               0,
                                                               0) )
                                                        {
                                                          if ( TEasy_Panel::create_text(
                                                                 (TEasy_Panel *)&v1->vfptr,
                                                                 (TPanel *)&v1->vfptr,
                                                                 &v1->scenarioPlayersTitle,
                                                                 9727,
                                                                 v1->scenarioListWidth + v1->scenarioListX - 220,
                                                                 v1->scenarioListY - 20,
                                                                 220,
                                                                 20,
                                                                 4,
                                                                 0,
                                                                 0,
                                                                 0) )
                                                          {
                                                            TTextPanel::set_alignment(
                                                              v1->scenarioPlayersTitle,
                                                              AlignTop,
                                                              AlignRight);
                                                            v20 = v1->scenarioListX;
                                                            v21 = v1->scenarioListHeight + v1->scenarioListY + 24;
                                                            v1->missionTextWidth = v1->scenarioListWidth;
                                                            v1->missionTextY = v21;
                                                            v1->missionTextX = v20;
                                                            v1->missionTextHeight = 260 - v21;
                                                            if ( TEasy_Panel::create_text(
                                                                   (TEasy_Panel *)&v1->vfptr,
                                                                   (TPanel *)&v1->vfptr,
                                                                   &v1->missionTitle,
                                                                   9728,
                                                                   v20,
                                                                   v21 - 20,
                                                                   300,
                                                                   20,
                                                                   4,
                                                                   0,
                                                                   0,
                                                                   0) )
                                                            {
                                                              v22 = &v1->missionText;
                                                              if ( TEasy_Panel::create_text(
                                                                     (TEasy_Panel *)&v1->vfptr,
                                                                     (TPanel *)&v1->vfptr,
                                                                     &v1->missionText,
                                                                     message_in,
                                                                     v1->missionTextX,
                                                                     v1->missionTextY,
                                                                     v1->missionTextWidth,
                                                                     v1->missionTextHeight,
                                                                     11,
                                                                     0,
                                                                     0,
                                                                     1) )
                                                              {
                                                                ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*v22)->vfptr[1].set_rect)(
                                                                  3,
                                                                  v1->bevel_color1,
                                                                  v1->bevel_color2,
                                                                  v1->bevel_color3,
                                                                  v1->bevel_color4,
                                                                  v1->bevel_color5,
                                                                  v1->bevel_color6);
                                                                if ( TEasy_Panel::create_auto_scrollbar(
                                                                       (TEasy_Panel *)&v1->vfptr,
                                                                       &v1->missionScrollbar,
                                                                       *v22,
                                                                       20) )
                                                                {
                                                                  TPanel::set_help_info(
                                                                    (TPanel *)&v1->missionScrollbar->vfptr,
                                                                    30266,
                                                                    -1);
                                                                  v23 = (TPanel **)&v1->okButton;
                                                                  if ( TEasy_Panel::create_button(
                                                                         (TEasy_Panel *)&v1->vfptr,
                                                                         (TPanel *)&v1->vfptr,
                                                                         &v1->okButton,
                                                                         4001,
                                                                         0,
                                                                         60,
                                                                         440,
                                                                         240,
                                                                         30,
                                                                         0,
                                                                         0,
                                                                         0) )
                                                                  {
                                                                    TPanel::set_help_info(*v23, 30001, -1);
                                                                    v24 = (TPanel **)&v1->cancelButton;
                                                                    if ( TEasy_Panel::create_button(
                                                                           (TEasy_Panel *)&v1->vfptr,
                                                                           (TPanel *)&v1->vfptr,
                                                                           &v1->cancelButton,
                                                                           4002,
                                                                           0,
                                                                           320,
                                                                           440,
                                                                           240,
                                                                           30,
                                                                           0,
                                                                           0,
                                                                           0) )
                                                                    {
                                                                      v25 = *v24;
                                                                      v25[2].max_wid = 27;
                                                                      v25[2].min_hgt = 0;
                                                                      TPanel::set_help_info(*v24, 30002, -1);
                                                                      if ( TEasy_Panel::create_button(
                                                                             (TEasy_Panel *)&v1->vfptr,
                                                                             (TPanel *)&v1->vfptr,
                                                                             &v1->help_button,
                                                                             4009,
                                                                             0,
                                                                             580,
                                                                             440,
                                                                             30,
                                                                             30,
                                                                             0,
                                                                             0,
                                                                             0) )
                                                                      {
                                                                        TribeGameSettingsScreen::fillScenarios(v1);
                                                                        v1->scenariosLoaded = 1;
                                                                        TribeGameSettingsScreen::getSettings(v1);
                                                                        TribeGameSettingsScreen::fillMissionText(v1);
                                                                        TribeGameSettingsScreen::activatePanels(v1);
                                                                        TPanel::set_curr_child(
                                                                          (TPanel *)&v1->vfptr,
                                                                          *v23);
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
// 573E78: using guessed type int (__thiscall *TribeGameSettingsScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B57F0) --------------------------------------------------------
TribeGameSettingsScreen *__thiscall TribeGameSettingsScreen::`vector deleting destructor'(TribeGameSettingsScreen *this, unsigned int __flags)
{
  TribeGameSettingsScreen *v2; // esi@1

  v2 = this;
  TribeGameSettingsScreen::~TribeGameSettingsScreen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B5810) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::init_vars(TribeGameSettingsScreen *this)
{
  char *v1; // edx@1
  signed int v2; // esi@1

  this->title = 0;
  this->mapSizeLabel = 0;
  this->mapSizeDrop = 0;
  this->mapTypeLabel = 0;
  this->mapTypeDrop = 0;
  this->victoryTypeLabel = 0;
  this->victoryTypeDrop = 0;
  this->scoreLabel = 0;
  this->scoreDrop = 0;
  this->timeLabel = 0;
  this->timeDrop = 0;
  this->victoryFixedText = 0;
  this->difficultyLabel = 0;
  this->difficultyDrop = 0;
  this->ageLabel = 0;
  this->ageDrop = 0;
  this->limitLabel = 0;
  this->limitDrop = 0;
  this->resourcesLabel = 0;
  this->resourcesDrop = 0;
  this->pathingLabel = 0;
  this->pathingDrop = 0;
  this->scenarioTitle = 0;
  this->scenarioPlayersTitle = 0;
  this->scenarioList = 0;
  this->scenarioScrollbar = 0;
  this->scenarioCount = 0;
  this->scenarioMission = 0;
  this->scenarioFixed = 0;
  this->scenariosLoaded = 0;
  this->missionTitle = 0;
  this->missionText = 0;
  this->missionScrollbar = 0;
  v1 = (char *)this->optionText;
  v2 = 4;
  do
  {
    *((_DWORD *)v1 - 4) = 0;
    *(_DWORD *)v1 = 0;
    v1 += 4;
    --v2;
  }
  while ( v2 );
  this->okButton = 0;
  this->cancelButton = 0;
  this->help_button = 0;
  this->chat_scr = 0;
  this->last_scenario_line = -1;
  this->scenario_line_offset = 0;
  this->last_send_shared = 0;
}

//----- (004B5920) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::~TribeGameSettingsScreen(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  TPanel **v2; // edi@1
  signed int v3; // ebx@1
  int i; // edi@4

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeGameSettingsScreen::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->mapSizeLabel);
  TPanel::delete_panel((TPanel **)&v1->mapSizeDrop);
  TPanel::delete_panel((TPanel **)&v1->mapTypeLabel);
  TPanel::delete_panel((TPanel **)&v1->mapTypeDrop);
  TPanel::delete_panel((TPanel **)&v1->victoryTypeLabel);
  TPanel::delete_panel((TPanel **)&v1->victoryTypeDrop);
  TPanel::delete_panel((TPanel **)&v1->timeDrop);
  TPanel::delete_panel((TPanel **)&v1->timeLabel);
  TPanel::delete_panel((TPanel **)&v1->scoreDrop);
  TPanel::delete_panel((TPanel **)&v1->scoreLabel);
  TPanel::delete_panel((TPanel **)&v1->victoryFixedText);
  TPanel::delete_panel((TPanel **)&v1->difficultyLabel);
  TPanel::delete_panel((TPanel **)&v1->difficultyDrop);
  TPanel::delete_panel((TPanel **)&v1->ageLabel);
  TPanel::delete_panel((TPanel **)&v1->ageDrop);
  TPanel::delete_panel((TPanel **)&v1->resourcesLabel);
  TPanel::delete_panel((TPanel **)&v1->resourcesDrop);
  TPanel::delete_panel((TPanel **)&v1->scenarioTitle);
  TPanel::delete_panel((TPanel **)&v1->scenarioPlayersTitle);
  TPanel::delete_panel((TPanel **)&v1->scenarioList);
  TPanel::delete_panel((TPanel **)&v1->scenarioScrollbar);
  TPanel::delete_panel((TPanel **)&v1->missionTitle);
  TPanel::delete_panel((TPanel **)&v1->missionText);
  TPanel::delete_panel((TPanel **)&v1->missionScrollbar);
  TPanel::delete_panel((TPanel **)&v1->pathingLabel);
  TPanel::delete_panel((TPanel **)&v1->pathingDrop);
  TPanel::delete_panel((TPanel **)&v1->limitLabel);
  TPanel::delete_panel((TPanel **)&v1->limitDrop);
  v2 = (TPanel **)v1->optionText;
  v3 = 4;
  do
  {
    TPanel::delete_panel(v2 - 4);
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TPanel::delete_panel((TPanel **)&v1->help_button);
  if ( v1->scenarioMission )
  {
    for ( i = 0; i < v1->scenarioCount; ++i )
    {
      if ( v1->scenarioMission[i] )
        free(v1->scenarioMission[i]);
    }
    free(v1->scenarioMission);
  }
  if ( v1->scenarioFixed )
    free(v1->scenarioFixed);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573E78: using guessed type int (__thiscall *TribeGameSettingsScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B5BB0) --------------------------------------------------------
int __thiscall TribeGameSettingsScreen::handle_idle(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  RGE_Base_Game *v2; // ecx@3

  v1 = this;
  if ( !this->scenariosLoaded )
  {
    TribeGameSettingsScreen::fillScenarios(this);
    TribeGameSettingsScreen::fillMissionText(v1);
    v1->scenariosLoaded = 1;
    TribeGameSettingsScreen::activatePanels(v1);
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->scenarioList->vfptr);
  }
  v2 = rge_base_game;
  if ( !rge_base_game->input_enabled )
  {
    RGE_Base_Game::enable_input(rge_base_game);
    v2 = rge_base_game;
  }
  if ( RGE_Base_Game::multiplayerGame(v2) )
  {
    if ( !v1->last_send_shared )
    {
LABEL_9:
      v1->last_send_shared = debug_timeGetTime();
      return TPanel::handle_idle((TPanel *)&v1->vfptr);
    }
    if ( debug_timeGetTime() != v1->last_send_shared )
    {
      TCommunications_Handler::SendSharedData(comm, 0);
      goto LABEL_9;
    }
  }
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004B5C70) --------------------------------------------------------
int __thiscall TribeGameSettingsScreen::handle_user_command(TribeGameSettingsScreen *this, unsigned int wParam, int lParam)
{
  TribeMPSetupScreen *v3; // ecx@1
  int result; // eax@2

  v3 = this->chat_scr;
  if ( !v3 || (result = ((int (__stdcall *)(unsigned int, int))v3->vfptr->handle_user_command)(wParam, lParam)) == 0 )
    result = TPanel::handle_user_command(wParam, lParam);
  return result;
}

//----- (004B5CB0) --------------------------------------------------------
int __thiscall TribeGameSettingsScreen::action(TribeGameSettingsScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeGameSettingsScreen *v5; // esi@1
  TDropDownPanel *v7; // ecx@12
  int v8; // eax@14

  v5 = this;
  if ( fromPanel && this->scenariosLoaded )
  {
    if ( fromPanel == (TPanel *)this->okButton && actionIn == 1 )
    {
      TPanel::set_curr_child((TPanel *)&this->vfptr, (TPanel *)&this->scenarioList->vfptr);
      TribeGameSettingsScreen::sendSettings(v5);
      ((void (__stdcall *)(TribeGameSettingsScreen *, signed int, _DWORD, _DWORD))v5->chat_scr->vfptr->action)(
        v5,
        1,
        0,
        0);
      return 1;
    }
    if ( fromPanel == (TPanel *)this->cancelButton && actionIn == 1 )
    {
      TPanel::set_curr_child((TPanel *)&this->vfptr, (TPanel *)&this->scenarioList->vfptr);
      TribeGameSettingsScreen::getSettings(v5);
      ((void (__stdcall *)(TribeGameSettingsScreen *, _DWORD, _DWORD, _DWORD))v5->chat_scr->vfptr->action)(v5, 0, 0, 0);
      return 1;
    }
    if ( fromPanel == (TPanel *)this->help_button && actionIn == 1 )
    {
      TEasy_Panel::setup_popup_help((TEasy_Panel *)&this->vfptr);
      return 1;
    }
    v7 = this->victoryTypeDrop;
    if ( (TDropDownPanel *)fromPanel == v7 && !actionIn )
    {
      v8 = TDropDownPanel::get_id(v7) - 7;
      if ( !v8 )
      {
        TDropDownPanel::set_line(v5->timeDrop, 3);
        goto LABEL_18;
      }
      if ( v8 == 1 )
      {
        TDropDownPanel::set_line(v5->scoreDrop, 7);
LABEL_18:
        TribeGameSettingsScreen::activatePanels(v5);
        return 1;
      }
      goto LABEL_24;
    }
    if ( fromPanel == (TPanel *)v5->scenarioList )
    {
      if ( actionIn == 3 )
        return 1;
      if ( actionIn == 1 )
      {
        TribeGameSettingsScreen::fillMissionText(v5);
LABEL_24:
        TribeGameSettingsScreen::activatePanels(v5);
        return 1;
      }
    }
  }
  return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
}

//----- (004B5E00) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::fillScenarios(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // ebp@1
  RGE_Scenario_File_Info *v2; // ebx@3
  const char *v3; // eax@4
  unsigned int v4; // kr04_4@5
  RGE_Base_Game *v5; // ecx@5
  int *v6; // eax@9
  char **v7; // ecx@9
  int v8; // esi@11
  int v9; // eax@14
  RGE_Scenario_Header *v10; // ebx@14
  char *v11; // edx@15
  const char *v12; // edi@16
  signed int v13; // ebx@18
  char *v14; // eax@28
  char *v15; // eax@32
  int i; // [sp+10h] [bp-224h]@3
  int ia; // [sp+10h] [bp-224h]@11
  RGE_Scenario_File_Info *scenario_info_file; // [sp+14h] [bp-220h]@3
  char player_str[20]; // [sp+18h] [bp-21Ch]@21
  char file_name[260]; // [sp+2Ch] [bp-208h]@5
  char scenario_file[260]; // [sp+130h] [bp-104h]@23

  v1 = this;
  TTextPanel::empty_list((TTextPanel *)&this->scenarioList->vfptr);
  v1->scenario_line_offset = 0;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) || RGE_Base_Game::scenarioGame(rge_base_game) )
  {
    v2 = rge_base_game->scenario_info;
    scenario_info_file = rge_base_game->scenario_info;
    RGE_Scenario_File_Info::reload_scenarios(scenario_info_file);
    i = 0;
    v1->scenarioList->sorted = 1;
    v1->scenarioCount = 0;
    while ( 1 )
    {
      v3 = RGE_Scenario_File_Info::get_scenario_name(v2, i);
      if ( !v3 )
        break;
      v4 = strlen(v3) + 1;
      strncpy(file_name, v3, v4 - 5);
      v5 = rge_base_game;
      file_name[v4 - 5] = 0;
      if ( RGE_Base_Game::multiplayerGame(v5) || !strcmp(file_name, RGE_Base_Game::scenarioName(rge_base_game)) )
      {
        TTextPanel::append_line((TTextPanel *)&v1->scenarioList->vfptr, file_name, i);
        ++v1->scenarioCount;
      }
      ++i;
    }
    v1->scenarioMission = (char **)calloc(v1->scenarioCount, 4u);
    v6 = (int *)calloc(v1->scenarioCount, 4u);
    v7 = v1->scenarioMission;
    v1->scenarioFixed = v6;
    if ( v7 )
    {
      if ( v6 )
      {
        v8 = 0;
        ia = 0;
        if ( v1->scenarioCount > 0 )
        {
          while ( 1 )
          {
            v9 = TTextPanel::get_id((TTextPanel *)&v1->scenarioList->vfptr, v8);
            v10 = RGE_Scenario_File_Info::get_scenario_info(v2, v9);
            if ( v10 )
            {
              v1->scenarioMission[v8] = (char *)calloc(0x1000u, 1u);
              v11 = v1->scenarioMission[v8];
              if ( v11 )
              {
                v12 = v10->description;
                if ( v12 )
                {
                  strcpy(v11, v12);
                  v8 = ia;
                }
              }
              v1->scenarioFixed[v8] = (int)v10[1].vfptr;
              v13 = v10[1].error_code;
              if ( v13 > 0 )
              {
                if ( v1->scenarioFixed[v8] || v13 < 3 )
                  sprintf(player_str, aD_3, v13);
                else
                  sprintf(player_str, aDD_0, 2, v13);
                strcpy(scenario_file, TTextPanel::get_text((TTextPanel *)&v1->scenarioList->vfptr, v8));
                TTextPanel::change_line((TTextPanel *)&v1->scenarioList->vfptr, ia, scenario_file, player_str, 0);
                v8 = ia;
              }
            }
            ia = ++v8;
            if ( v8 >= v1->scenarioCount )
              break;
            v2 = scenario_info_file;
          }
        }
      }
    }
  }
  v1->scenarioList->sorted = 0;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game)
    || RGE_Base_Game::randomGame(rge_base_game) && !TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
  {
    v14 = TPanel::get_string(9653);
    TTextPanel::insert_line((TTextPanel *)&v1->scenarioList->vfptr, 0, v14, text2_in, -2);
    --v1->scenario_line_offset;
  }
  if ( RGE_Base_Game::multiplayerGame(rge_base_game)
    || RGE_Base_Game::randomGame(rge_base_game) && TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
  {
    v15 = TPanel::get_string(9751);
    TTextPanel::insert_line((TTextPanel *)&v1->scenarioList->vfptr, 1, v15, text2_in, -1);
    --v1->scenario_line_offset;
  }
}

//----- (004B6160) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::fillMissionText(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  int v2; // edi@1
  int v3; // eax@1
  int v4; // ebx@1
  TTextPanel *v5; // ecx@3

  v1 = this;
  (*(void (__stdcall **)(char *))&this->missionText->vfptr[1].gap4[4])(message_in);
  v2 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr);
  v3 = TTextPanel::get_id((TTextPanel *)&v1->scenarioList->vfptr);
  v4 = v3;
  if ( v3 == -2 )
  {
    (*(void (__stdcall **)(signed int))&v1->missionText->vfptr[1].gap4[0])(9692);
  }
  else
  {
    v5 = v1->missionText;
    if ( v3 == -1 )
      (*(void (__stdcall **)(signed int))&v5->vfptr[1].gap4[0])(9752);
    else
      (*(void (__stdcall **)(char *))&v5->vfptr[1].gap4[4])(v1->scenarioMission[v2 + v1->scenario_line_offset]);
  }
  if ( v2 != v1->last_scenario_line )
    TDropDownPanel::set_line(v1->victoryTypeDrop, 0);
  if ( v4 >= 0 )
  {
    v1->last_scenario_line = v2;
    v1->state = 0;
  }
  else
  {
    v1->state = 1;
    v1->last_scenario_line = v2;
  }
}

//----- (004B6230) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::getSettings(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  TribeGameSettingsScreen::State v2; // eax@4
  char *v3; // eax@7
  int v4; // eax@7
  int v5; // edi@7
  int v6; // eax@11
  int v7; // eax@11
  int v8; // eax@11
  int v9; // eax@11
  int v10; // eax@11
  int v11; // eax@11
  TButtonPanel *v12; // eax@11
  int v13; // edi@12
  int v14; // eax@12
  int v15; // edi@13
  int v16; // eax@13
  int v17; // edi@13
  int v18; // eax@13
  int v19; // edi@13
  int v20; // eax@13
  int v21; // eax@13
  int v22; // eax@13
  int v23; // eax@13
  int v24; // eax@13
  int v25; // eax@13
  int v26; // eax@13
  char v27; // al@14
  int v28; // eax@16
  char v29; // al@17
  int v30; // eax@17
  int v31; // eax@19
  int v32; // eax@19
  int v33; // eax@21
  int v34; // eax@21
  __int16 v35; // [sp-8h] [bp-10h]@6

  v1 = this;
  if ( RGE_Base_Game::scenarioGame(rge_base_game) )
    v1->state = 0;
  else
    v1->state = 1;
  v2 = v1->state;
  v1->last_scenario_line = 0;
  if ( v2 != 1 )
  {
    v3 = RGE_Base_Game::scenarioName(rge_base_game);
    v4 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr, v3);
    v5 = v4;
    if ( v4 != -1 )
    {
      TListPanel::scroll_cur_line(v1->scenarioList, 1, v4, 1);
      v1->last_scenario_line = v5 - 1;
      goto LABEL_11;
    }
    goto LABEL_9;
  }
  if ( !TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
  {
LABEL_9:
    v35 = 0;
    goto LABEL_10;
  }
  v35 = 1;
LABEL_10:
  TListPanel::scroll_cur_line(v1->scenarioList, 1, v35, 1);
LABEL_11:
  v6 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
  v7 = TDropDownPanel::get_line(v1->mapSizeDrop, v6);
  TDropDownPanel::set_line(v1->mapSizeDrop, v7);
  v8 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
  v9 = TDropDownPanel::get_line(v1->mapTypeDrop, v8);
  TDropDownPanel::set_line(v1->mapTypeDrop, v9);
  v10 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
  v11 = TDropDownPanel::get_line(v1->victoryTypeDrop, v10);
  TDropDownPanel::set_line(v1->victoryTypeDrop, v11);
  v12 = v1->optionButton[3];
  if ( v12 )
  {
    v13 = *(_DWORD *)v12;
    v14 = RGE_Base_Game::allowCheatCodes(rge_base_game);
    (*(void (__thiscall **)(TButtonPanel *, int))(v13 + 224))(v1->optionButton[3], v14);
  }
  v15 = *(_DWORD *)v1->optionButton[1];
  v16 = RGE_Base_Game::fullVisibility(rge_base_game);
  (*(void (__thiscall **)(TButtonPanel *, int))(v15 + 224))(v1->optionButton[1], v16);
  v17 = *(_DWORD *)v1->optionButton[0];
  v18 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game);
  (*(void (__thiscall **)(TButtonPanel *, _DWORD))(v17 + 224))(v1->optionButton[0], v18 == 0);
  v19 = *(_DWORD *)v1->optionButton[2];
  v20 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
  (*(void (__thiscall **)(TButtonPanel *, int))(v19 + 224))(v1->optionButton[2], v20);
  v21 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
  v22 = TDropDownPanel::get_line(v1->resourcesDrop, v21);
  TDropDownPanel::set_line(v1->resourcesDrop, v22);
  v23 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
  v24 = TDropDownPanel::get_line(v1->ageDrop, v23);
  TDropDownPanel::set_line(v1->ageDrop, v24);
  v25 = RGE_Base_Game::difficulty(rge_base_game);
  v26 = TDropDownPanel::get_line(v1->difficultyDrop, v25);
  TDropDownPanel::set_line(v1->difficultyDrop, v26);
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
    v27 = RGE_Base_Game::mpPathFinding(rge_base_game);
  else
    v27 = RGE_Base_Game::pathFinding(rge_base_game);
  v28 = TDropDownPanel::get_line(v1->pathingDrop, (unsigned __int8)v27);
  TDropDownPanel::set_line(v1->pathingDrop, v28);
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    v29 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
    v30 = TDropDownPanel::get_line(v1->limitDrop, (unsigned __int8)v29);
    TDropDownPanel::set_line(v1->limitDrop, v30);
  }
  if ( TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) == 7 )
  {
    v31 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    v32 = TDropDownPanel::get_line(v1->timeDrop, v31);
    TDropDownPanel::set_line(v1->timeDrop, v32);
  }
  else if ( TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) == 8 )
  {
    v33 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
    v34 = TDropDownPanel::get_line(v1->scoreDrop, v33);
    TDropDownPanel::set_line(v1->scoreDrop, v34);
  }
}

//----- (004B6500) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::sendSettings(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  char *v2; // ST04_4@2
  int v3; // eax@4
  int v4; // eax@4
  TRIBE_Game::VictoryType v5; // ST00_4@6
  int v6; // ST04_4@7
  int v7; // ST04_4@8
  TRIBE_Game::MapSize v8; // eax@10
  TRIBE_Game::MapType v9; // eax@10
  TButtonPanel *v10; // ecx@11
  int v11; // eax@12
  int v12; // eax@13
  int v13; // eax@13
  int v14; // eax@13
  TRIBE_Game::ResourceLevel v15; // ST04_4@15
  int v16; // eax@16
  TDropDownPanel *v17; // ecx@16
  char v18; // al@17
  char v19; // al@18
  char v20; // al@20
  TRIBE_Game::Age v21; // eax@21
  int v22; // eax@21
  int v23; // eax@22

  v1 = this;
  if ( TTextPanel::get_id((TTextPanel *)&this->scenarioList->vfptr) < 0 )
  {
    RGE_Base_Game::setScenarioGame(rge_base_game, 0);
    RGE_Base_Game::setScenarioName(rge_base_game, message_in);
  }
  else
  {
    RGE_Base_Game::setScenarioGame(rge_base_game, 1);
    v2 = TTextPanel::get_text((TTextPanel *)&v1->scenarioList->vfptr);
    RGE_Base_Game::setScenarioName(rge_base_game, v2);
  }
  v3 = TTextPanel::get_id((TTextPanel *)&v1->scenarioList->vfptr);
  TRIBE_Game::setDeathMatch((TRIBE_Game *)rge_base_game, v3 == -1);
  v4 = TDropDownPanel::get_id(v1->victoryTypeDrop) - 7;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v6 = TDropDownPanel::get_id(v1->scoreDrop);
      TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game, VictoryScore, v6);
    }
    else
    {
      v5 = TDropDownPanel::get_id(v1->victoryTypeDrop);
      TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game, v5, 1);
    }
  }
  else
  {
    v7 = TDropDownPanel::get_id(v1->timeDrop);
    TRIBE_Game::setVictoryType((TRIBE_Game *)rge_base_game, VictoryTime, v7);
  }
  if ( RGE_Base_Game::randomGame(rge_base_game) )
  {
    v8 = TDropDownPanel::get_id(v1->mapSizeDrop);
    TRIBE_Game::setMapSize((TRIBE_Game *)rge_base_game, v8);
    v9 = TDropDownPanel::get_id(v1->mapTypeDrop);
    TRIBE_Game::setMapType((TRIBE_Game *)rge_base_game, v9);
  }
  v10 = v1->optionButton[3];
  if ( v10 )
  {
    v11 = TButtonPanel::get_state(v10);
    RGE_Base_Game::setAllowCheatCodes(rge_base_game, v11);
  }
  v12 = TButtonPanel::get_state(v1->optionButton[1]);
  RGE_Base_Game::setFullVisibility(rge_base_game, v12);
  v13 = TButtonPanel::get_state(v1->optionButton[0]);
  TRIBE_Game::setRandomizePositions((TRIBE_Game *)rge_base_game, v13 == 0);
  v14 = TButtonPanel::get_state(v1->optionButton[2]);
  TRIBE_Game::setFullTechTree((TRIBE_Game *)rge_base_game, v14);
  if ( TTextPanel::get_id((TTextPanel *)&v1->scenarioList->vfptr) == -1 )
  {
    TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game, 0);
  }
  else
  {
    v15 = TDropDownPanel::get_id(v1->resourcesDrop);
    TRIBE_Game::setResourceLevel((TRIBE_Game *)rge_base_game, v15);
  }
  v16 = RGE_Base_Game::multiplayerGame(rge_base_game);
  v17 = v1->pathingDrop;
  if ( v16 )
  {
    v18 = TDropDownPanel::get_id(v17);
    RGE_Base_Game::setMpPathFinding(rge_base_game, v18);
  }
  else
  {
    v19 = TDropDownPanel::get_id(v17);
    RGE_Base_Game::setPathFinding(rge_base_game, v19);
  }
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    v20 = TDropDownPanel::get_id(v1->limitDrop);
    TRIBE_Game::setPopLimit((TRIBE_Game *)rge_base_game, v20);
  }
  v21 = TDropDownPanel::get_id(v1->ageDrop);
  TRIBE_Game::setStartingAge((TRIBE_Game *)rge_base_game, v21);
  v22 = TDropDownPanel::get_id(v1->difficultyDrop);
  RGE_Base_Game::setDifficulty(rge_base_game, v22);
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
  {
    v23 = TDropDownPanel::get_id(v1->difficultyDrop);
    RGE_Base_Game::set_single_player_difficulty(rge_base_game, v23);
  }
}

//----- (004B6740) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::activatePanels(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  TPanelVtbl *v2; // edx@1
  int v3; // edi@1
  int v4; // edi@4
  bool v5; // zf@4
  TPanelVtbl *v6; // eax@4
  signed int v7; // edi@7
  TPanel *v8; // edx@9
  TPanelVtbl *v9; // eax@9
  int v10; // edi@9
  TPanel *v11; // eax@9
  int v12; // [sp+18h] [bp-14h]@0
  int v13; // [sp+18h] [bp-14h]@2
  TPanel *tabList[3]; // [sp+20h] [bp-Ch]@8

  v1 = this;
  v2 = this->missionTitle->vfptr;
  v3 = this->state == 0;
  if ( this->state == 0 )
  {
    (*(void (__stdcall **)(signed int, int))&v2->gap10[4])(1, v12);
    (*(void (__cdecl **)(signed int))&v1->missionText->vfptr->gap10[4])(1);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD, int))&v2->gap10[4])(0, v12);
    (*(void (__cdecl **)(signed int))&v1->missionText->vfptr->gap10[4])(0);
  }
  v4 = v3 == 0;
  (*(void (__stdcall **)(int))&v1->mapSizeDrop->vfptr->gap10[4])(v4);
  (*(void (__stdcall **)(int))&v1->mapTypeDrop->vfptr->gap10[4])(v4);
  (*(void (__stdcall **)(int))&v1->mapSizeLabel->vfptr->gap10[4])(v4);
  (*(void (__stdcall **)(int))&v1->mapTypeLabel->vfptr->gap10[4])(v4);
  v5 = TTextPanel::get_id((TTextPanel *)&v1->scenarioList->vfptr) == -1;
  v6 = v1->resourcesDrop->vfptr;
  if ( v5 )
  {
    (*(void (__stdcall **)(_DWORD, int))&v6->gap10[4])(0, v13);
    (*(void (__cdecl **)(signed int))&v1->resourcesLabel->vfptr->gap10[4])(0);
  }
  else
  {
    (*(void (__stdcall **)(signed int, int))&v6->gap10[4])(1, v13);
    (*(void (__cdecl **)(signed int))&v1->resourcesLabel->vfptr->gap10[4])(1);
  }
  TribeGameSettingsScreen::activateVictoryPanels(v1);
  v7 = 0;
  if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
  {
    v7 = 1;
    tabList[0] = (TPanel *)&v1->scenarioList->vfptr;
  }
  v8 = (TPanel *)v1->cancelButton;
  tabList[v7] = (TPanel *)v1->okButton;
  v9 = v1->vfptr;
  v10 = v7 + 1;
  tabList[v10] = v8;
  v9->set_tab_order((TPanel *)v1, (TPanel *)tabList, (TPanel *)(v10 + 1));
  v11 = v1->curr_child;
  if ( !v11 || !v11->active )
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)v1->okButton);
}

//----- (004B6870) --------------------------------------------------------
void __thiscall TribeGameSettingsScreen::activateVictoryPanels(TribeGameSettingsScreen *this)
{
  TribeGameSettingsScreen *v1; // esi@1
  int v2; // edi@2
  int v3; // eax@2

  v1 = this;
  (*(void (__stdcall **)(_DWORD))&this->timeLabel->vfptr->gap10[4])(0);
  (*(void (__stdcall **)(_DWORD))&v1->timeDrop->vfptr->gap10[4])(0);
  (*(void (__stdcall **)(_DWORD))&v1->scoreLabel->vfptr->gap10[4])(0);
  (*(void (__stdcall **)(_DWORD))&v1->scoreDrop->vfptr->gap10[4])(0);
  if ( v1->state == StateScenario
    && (v2 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr),
        v3 = TTextPanel::get_line((TTextPanel *)&v1->scenarioList->vfptr),
        v1->scenariosLoaded)
    && v3 >= 0
    && v1->scenarioFixed[v2 + v1->scenario_line_offset] )
  {
    (*(void (__stdcall **)(signed int))&v1->victoryFixedText->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(_DWORD))&v1->victoryTypeLabel->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(_DWORD))&v1->victoryTypeDrop->vfptr->gap10[4])(0);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD))&v1->victoryFixedText->vfptr->gap10[4])(0);
    (*(void (__stdcall **)(signed int))&v1->victoryTypeLabel->vfptr->gap10[4])(1);
    (*(void (__stdcall **)(signed int))&v1->victoryTypeDrop->vfptr->gap10[4])(1);
    if ( TDropDownPanel::get_id(v1->victoryTypeDrop) == 7 )
    {
      (*(void (__stdcall **)(signed int))&v1->timeLabel->vfptr->gap10[4])(1);
      (*(void (__stdcall **)(signed int))&v1->timeDrop->vfptr->gap10[4])(1);
    }
    if ( TDropDownPanel::get_id(v1->victoryTypeDrop) == 8 )
    {
      (*(void (__stdcall **)(signed int))&v1->scoreLabel->vfptr->gap10[4])(1);
      (*(void (__stdcall **)(signed int))&v1->scoreDrop->vfptr->gap10[4])(1);
    }
  }
}
