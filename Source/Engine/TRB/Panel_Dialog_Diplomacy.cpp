
//----- (0043C930) --------------------------------------------------------
void __thiscall TribeDiplomacyDialog::TribeDiplomacyDialog(TribeDiplomacyDialog *this, TScreenPanel *parentPanel)
{
  TribeDiplomacyDialog *v2; // esi@1
  int v3; // eax@1
  signed int v4; // ecx@1
  int v5; // ST24_4@3
  char *v6; // ST20_4@3
  TDrawArea *v7; // eax@3
  TShape *v8; // eax@4
  TShape *v9; // eax@5
  TShape *v10; // eax@8
  TShape *v11; // eax@9
  int v12; // ST28_4@19
  char *v13; // eax@19
  RGE_Game_World *v14; // edi@21
  int v15; // ebp@22
  int v16; // ebp@24
  signed int v17; // eax@25
  signed int v18; // edi@32
  int i; // ebx@34
  PLAYERHUMANITY v20; // eax@36
  TButtonPanel **v21; // ebp@46
  TButtonPanel **v22; // edi@50
  signed int v23; // ebx@50
  RGE_Player *v24; // eax@54
  char v25; // al@54
  TButtonPanel **v26; // ebx@63
  TButtonPanel **v27; // ebp@64
  TButtonPanel **v28; // edi@65
  TPanel **v29; // edi@68
  TPanelVtbl *v30; // ebp@69
  RGE_Player *v31; // eax@69
  unsigned int v32; // ecx@69
  TPanel **v33; // edi@75
  TPanel *v34; // edi@76
  signed __int64 v35; // rax@77
  double v36; // st7@78
  double v37; // st7@79
  int v38; // ebp@79
  signed __int64 v39; // rax@80
  int v40; // edi@80
  RGE_Game_World *v41; // eax@81
  TTextPanel *v42; // ecx@82
  TTextPanel *v43; // ecx@83
  RGE_Game_World *v44; // eax@84
  TPanel *v45; // ecx@88
  int v46; // eax@88
  TPanel *v47; // ecx@90
  int v48; // [sp+Ch] [bp-140h]@0
  TButtonPanel **v49; // [sp+1Ch] [bp-130h]@22
  signed int y; // [sp+20h] [bp-12Ch]@22
  signed int a; // [sp+24h] [bp-128h]@21
  RGE_Game_World *world; // [sp+28h] [bp-124h]@21
  int humanity; // [sp+2Ch] [bp-120h]@34
  int humanitya; // [sp+2Ch] [bp-120h]@46
  TButtonPanel **button; // [sp+30h] [bp-11Ch]@22
  int tabCount; // [sp+34h] [bp-118h]@1
  int v57; // [sp+3Ch] [bp-110h]@22
  int disable_buttons; // [sp+40h] [bp-10Ch]@27
  tagPALETTEENTRY paletteColor; // [sp+4Ch] [bp-100h]@24
  char temp_str[100]; // [sp+50h] [bp-FCh]@19
  TPanel *tabList[35]; // [sp+B4h] [bp-98h]@87
  int v62; // [sp+148h] [bp-4h]@1

  v2 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aDiplomacyDialo);
  v2->vfptr = (TPanelVtbl *)&TribeDiplomacyDialog::`vftable';
  v62 = 0;
  tabCount = 0;
  v3 = (int)v2->playerName;
  v4 = 8;
  do
  {
    *(_DWORD *)(v3 - 32) = 0;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 32) = 0;
    *(_DWORD *)(v3 + 64) = 0;
    *(_DWORD *)(v3 + 100) = 0;
    *(_DWORD *)(v3 + 164) = 0;
    *(_DWORD *)(v3 + 132) = 0;
    *(_DWORD *)(v3 + 196) = 0;
    *(_DWORD *)(v3 + 384) = 0;
    *(_DWORD *)(v3 + 416) = 0;
    *(_DWORD *)(v3 + 448) = 0;
    *(_DWORD *)(v3 + 480) = 0;
    v3 += 4;
    --v4;
  }
  while( v4 );
  memset(v2->allyButton, 0, sizeof(v2->allyButton));
  v2->allianceButton = 0;
  v2->okButton = 0;
  v2->cancelButton = 0;
  v2->clearButton = 0;
  v2->help_button = 0;
  v2->needMarket = 0;
  v2->buttonPics = 0;
  v2->backgroundPics = 0;
  v2->playerWood = 0;
  v2->playerStone = 0;
  v2->playerGold = 0;
  v2->playerFood = 0;
  LODWORD(v2->woodTotal) = 0;
  LODWORD(v2->stoneTotal) = 0;
  LODWORD(v2->foodTotal) = 0;
  LODWORD(v2->goldTotal) = 0;
  v2->tribute_flag = 0;
  v5 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parentPanel->vfptr);
  v6 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parentPanel->vfptr);
  v7 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
  if( TDialogPanel::setup((TDialogPanel *)&v2->vfptr, v7, (TPanel *)&parentPanel->vfptr, 625, 405, v6, v5, 1) )
  {
    v8 = (TShape *)operator new(0x20u);
    LOBYTE(v62) = 1;
    if( v8 )
      TShape::TShape(v8, aTradicon_shp, 50732);
    else
      v9 = 0;
    LOBYTE(v62) = 0;
    v2->buttonPics = v9;
    if( v9 )
    {
      v10 = (TShape *)operator new(0x20u);
      LOBYTE(v62) = 2;
      if( v10 )
        TShape::TShape(v10, aDlg_plbn_shp, 50746);
      else
        v11 = 0;
      LOBYTE(v62) = 0;
      v2->backgroundPics = v11;
      if( v11 )
      {
        RGE_Base_Game::get_font(rge_base_game, 1);
        if( TEasy_Panel::create_text(
               (TEasy_Panel *)&v2->vfptr,
               (TPanel *)&v2->vfptr,
               v2->title,
               9851,
               72,
               5,
               500,
               30,
               1,
               1,
               1,
               0) )
        {
          if( TEasy_Panel::create_text(
                 (TEasy_Panel *)&v2->vfptr,
                 (TPanel *)&v2->vfptr,
                 &v2->needMarket,
                 9863,
                 440,
                 110,
                 175,
                 60,
                 11,
                 1,
                 1,
                 1) )
          {
            if( TEasy_Panel::create_text(
                   (TEasy_Panel *)&v2->vfptr,
                   (TPanel *)&v2->vfptr,
                   &v2->title[1],
                   9862,
                   5,
                   50,
                   130,
                   30,
                   11,
                   0,
                   1,
                   0) )
            {
              if( TEasy_Panel::create_text(
                     (TEasy_Panel *)&v2->vfptr,
                     (TPanel *)&v2->vfptr,
                     &v2->title[2],
                     9852,
                     137,
                     50,
                     80,
                     30,
                     11,
                     0,
                     1,
                     0) )
              {
                if( TEasy_Panel::create_text(
                       (TEasy_Panel *)&v2->vfptr,
                       (TPanel *)&v2->vfptr,
                       &v2->title[3],
                       9853,
                       235,
                       50,
                       70,
                       30,
                       11,
                       0,
                       1,
                       0) )
                {
                  if( TEasy_Panel::create_text(
                         (TEasy_Panel *)&v2->vfptr,
                         (TPanel *)&v2->vfptr,
                         &v2->title[4],
                         9854,
                         290,
                         50,
                         70,
                         30,
                         11,
                         0,
                         1,
                         0) )
                  {
                    if( TEasy_Panel::create_text(
                           (TEasy_Panel *)&v2->vfptr,
                           (TPanel *)&v2->vfptr,
                           &v2->title[5],
                           9855,
                           360,
                           50,
                           70,
                           30,
                           11,
                           0,
                           1,
                           0) )
                    {
                      v12 = (signed __int64)(*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                                      + 184)
                                           * 100.0);
                      v13 = TPanel::get_string(9856);
                      sprintf(temp_str, v13, v12);
                      if( TEasy_Panel::create_text(
                             (TEasy_Panel *)&v2->vfptr,
                             (TPanel *)&v2->vfptr,
                             &v2->title[6],
                             temp_str,
                             440,
                             50,
                             180,
                             30,
                             11,
                             0,
                             1,
                             0) )
                      {
                        if( TEasy_Panel::create_text(
                               (TEasy_Panel *)&v2->vfptr,
                               (TPanel *)&v2->vfptr,
                               &v2->title[7],
                               9857,
                               318,
                               330,
                               300,
                               30,
                               11,
                               0,
                               1,
                               0) )
                        {
                          v2->cur_player_row = -1;
                          a = 1;
                          v14 = rge_base_game->world;
                          world = v14;
                          if( v14->player_num - 1 > 0 )
                          {
                            v49 = v2->woodTributeButton;
                            button = v2->allyButton;
                            v15 = -1328 - (_DWORD)v2;
                            v57 = 0;
                            y = 80;
                            while( 1 )
                            {
                              v16 = (int)v49 + v15;
                              GetPaletteEntries(
                                v2->palette,
                                (*(RGE_Player **)((char *)v14->players + v16))->color_table->map_color,
                                1u,
                                &paletteColor);
                              if( rge_base_game->prog_mode == 5 )
                              {
                                v17 = a;
                              }
                              else
                              {
                                v17 = a;
                                if( a != v14->curr_player
                                  && !(*(RGE_Player **)((char *)v14->players + v16))->game_status )
                                {
                                  disable_buttons = 0;
                                  goto LABEL_30;
                                }
                              }
                              disable_buttons = 1;
LABEL_30:
                              if( v17 == v14->curr_player )
                                v2->cur_player_row = v17 - 1;
                              v18 = 0;
                              if( (*(RGE_Player **)((char *)world->players + v16))->game_status == 2 )
                                goto LABEL_95;
                              if( RGE_Base_Game::multiplayerGame(rge_base_game) )
                              {
                                humanity = 0;
                                for( i = 1; i <= RGE_Base_Game::numberPlayers(rge_base_game); ++i )
                                {
                                  if( RGE_Base_Game::playerID(rge_base_game, i) == a )
                                  {
                                    v20 = TCommunications_Handler::GetPlayerHumanity(comm, i);
                                    if( v20 == 2 || v20 == 4 )
                                      humanity = v20;
                                  }
                                }
                                if( humanity != 2 && humanity != 4 )
LABEL_95:
                                  v18 = 1;
                              }
                              if( !TEasy_Panel::create_text(
                                      (TEasy_Panel *)&v2->vfptr,
                                      (TPanel *)&v2->vfptr,
                                      (TTextPanel **)v49 - 33,
                                      (*(RGE_Player **)((char *)world->players + v16))->name,
                                      5,
                                      y,
                                      130,
                                      30,
                                      v18 != 0 ? 8 : 11,
                                      0,
                                      1,
                                      0) )
                                return;
                              (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
                                105,
                                (*(RGE_Player **)((char *)world->players + v16))->master_player_id,
                                0,
                                temp_str,
                                100);
                              if( !TEasy_Panel::create_text(
                                      (TEasy_Panel *)&v2->vfptr,
                                      (TPanel *)&v2->vfptr,
                                      (TTextPanel **)v49 - 17,
                                      temp_str,
                                      137,
                                      y,
                                      100,
                                      30,
                                      11,
                                      0,
                                      1,
                                      0) )
                                return;
                              if( a == world->curr_player )
                              {
                                v21 = button;
                              }
                              else
                              {
                                v21 = button;
                                humanitya = (int)button + -1428 - (_DWORD)v2;
                                if( !TEasy_Panel::create_radio_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        button,
                                        240,
                                        y,
                                        30,
                                        30,
                                        0,
                                        0) )
                                  return;
                                TPanel::set_help_info((TPanel *)*button, 30340, -1);
                                if( !TEasy_Panel::create_radio_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        button + 1,
                                        310,
                                        y,
                                        30,
                                        30,
                                        0,
                                        0) )
                                  return;
                                TPanel::set_help_info((TPanel *)button[1], 30341, -1);
                                if( !TEasy_Panel::create_radio_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        button + 2,
                                        380,
                                        y,
                                        30,
                                        30,
                                        0,
                                        0) )
                                  return;
                                TPanel::set_help_info((TPanel *)button[2], 30342, -1);
                                if( __OFSUB__(v57, v57 + 3) ^ 1 )
                                {
                                  v22 = button;
                                  v23 = 3;
                                  do
                                  {
                                    TButtonPanel::set_radio_info(*v22, button, 3);
                                    if( rge_base_game->prog_mode == 5 )
                                      TButtonPanel::set_disabled(*v22, 1);
                                    ++v22;
                                    --v23;
                                  }
                                  while( v23 );
                                }
                                v24 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                                v25 = RGE_Player::relation(v24, a);
                                if( a != world->curr_player && v25 )
                                {
                                  if( v25 == 1 )
                                    TButtonPanel::set_radio_button(*(TButtonPanel **)((char *)&v2->allyButton[1]
                                                                                    + humanitya));
                                  else
                                    TButtonPanel::set_radio_button(*(TButtonPanel **)((char *)&v2->allyButton[2]
                                                                                    + humanitya));
                                }
                                else
                                {
                                  TButtonPanel::set_radio_button(*(TButtonPanel **)((char *)v2->allyButton + humanitya));
                                }
                              }
                              if( !disable_buttons )
                              {
                                if( !TEasy_Panel::create_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        v49,
                                        -1,
                                        0,
                                        440,
                                        y,
                                        40,
                                        30,
                                        11,
                                        0,
                                        0) )
                                  return;
                                v26 = v49 + 8;
                                if( !TEasy_Panel::create_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        v49 + 8,
                                        -1,
                                        0,
                                        480,
                                        y,
                                        40,
                                        30,
                                        11,
                                        0,
                                        0) )
                                  return;
                                v27 = v49 - 8;
                                if( !TEasy_Panel::create_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        v49 - 8,
                                        -1,
                                        0,
                                        520,
                                        y,
                                        40,
                                        30,
                                        11,
                                        0,
                                        0) )
                                  return;
                                v28 = v49 + 16;
                                if( !TEasy_Panel::create_button(
                                        (TEasy_Panel *)&v2->vfptr,
                                        (TPanel *)&v2->vfptr,
                                        v49 + 16,
                                        -1,
                                        0,
                                        560,
                                        y,
                                        40,
                                        30,
                                        11,
                                        0,
                                        0) )
                                  return;
                                TButtonPanel::set_picture(*v49, 0, v2->buttonPics, 0);
                                TButtonPanel::set_picture(*v26, 0, v2->buttonPics, 2);
                                TButtonPanel::set_picture(*v27, 0, v2->buttonPics, 3);
                                TButtonPanel::set_picture(*v28, 0, v2->buttonPics, 1);
                                TButtonPanel::setDrawType((int)*v49, 4);
                                TButtonPanel::setDrawType((int)*v26, 4);
                                TButtonPanel::setDrawType((int)*v27, 4);
                                TButtonPanel::setDrawType((int)*v28, 4);
                                TPanel::set_help_info((TPanel *)*v49, 30343, -1);
                                TPanel::set_help_info((TPanel *)*v26, 30344, -1);
                                TPanel::set_help_info((TPanel *)*v27, 30345, -1);
                                TPanel::set_help_info((TPanel *)*v28, 30346, -1);
                                v21 = button;
                              }
                              v57 += 3;
                              button = v21 + 3;
                              ++a;
                              y += 30;
                              ++v49;
                              if( a - 1 >= world->player_num - 1 )
                                break;
                              v15 = -1328 - (_DWORD)v2;
                              v14 = world;
                            }
                          }
                          v29 = (TPanel **)&v2->allianceButton;
                          if( TEasy_Panel::create_check_box(
                                 (TEasy_Panel *)&v2->vfptr,
                                 (TPanel *)&v2->vfptr,
                                 &v2->allianceButton,
                                 282,
                                 327,
                                 30,
                                 30,
                                 0,
                                 0) )
                          {
                            v30 = (*v29)->vfptr;
                            v31 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
                            LOWORD(v32) = (unsigned __int8)RGE_Player::get_allied_victory(v31);
                            v30[1].__vecDelDtor(*v29, v32);
                            TPanel::set_help_info(*v29, 30348, -1);
                            if( rge_base_game->prog_mode == 5 )
                              TButtonPanel::set_disabled((TButtonPanel *)*v29, 1);
                            if( rge_base_game->prog_mode != 5 )
                            {
                              if( !TEasy_Panel::create_button(
                                      (TEasy_Panel *)&v2->vfptr,
                                      (TPanel *)&v2->vfptr,
                                      &v2->okButton,
                                      4001,
                                      0,
                                      10,
                                      367,
                                      190,
                                      30,
                                      0,
                                      0,
                                      0) )
                                return;
                              TPanel::set_help_info((TPanel *)v2->okButton, 30001, -1);
                              if( !TEasy_Panel::create_button(
                                      (TEasy_Panel *)&v2->vfptr,
                                      (TPanel *)&v2->vfptr,
                                      &v2->clearButton,
                                      9859,
                                      0,
                                      215,
                                      367,
                                      190,
                                      30,
                                      0,
                                      0,
                                      0) )
                                return;
                              TPanel::set_help_info((TPanel *)v2->clearButton, 30347, -1);
                            }
                            v33 = (TPanel **)&v2->cancelButton;
                            if( TEasy_Panel::create_button(
                                   (TEasy_Panel *)&v2->vfptr,
                                   (TPanel *)&v2->vfptr,
                                   &v2->cancelButton,
                                   4002,
                                   0,
                                   420,
                                   367,
                                   190,
                                   30,
                                   0,
                                   0,
                                   0) )
                            {
                              TPanel::set_help_info(*v33, 30002, -1);
                              v34 = *v33;
                              v34[2].max_wid = 27;
                              v34[2].min_hgt = 0;
                              if( TEasy_Panel::create_button(
                                     (TEasy_Panel *)&v2->vfptr,
                                     (TPanel *)&v2->vfptr,
                                     &v2->help_button,
                                     4009,
                                     0,
                                     500,
                                     327,
                                     30,
                                     30,
                                     0,
                                     0,
                                     0) )
                              {
                                v35 = (signed __int64)(*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                                                + 4)
                                                     - v2->woodTotal);
                                sprintf(temp_str, aLd_0, (_DWORD)v35);
                                if( TEasy_Panel::create_text(
                                       (TEasy_Panel *)&v2->vfptr,
                                       (TPanel *)&v2->vfptr,
                                       &v2->playerWood,
                                       temp_str,
                                       440,
                                       30 * v2->cur_player_row + 80,
                                       40,
                                       30,
                                       11,
                                       0,
                                       1,
                                       0) )
                                {
                                  v36 = **(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                      - v2->foodTotal;
                                  sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v36);
                                  if( TEasy_Panel::create_text(
                                         (TEasy_Panel *)&v2->vfptr,
                                         (TPanel *)&v2->vfptr,
                                         &v2->playerFood,
                                         temp_str,
                                         480,
                                         30 * v2->cur_player_row + 80,
                                         40,
                                         30,
                                         11,
                                         0,
                                         1,
                                         0) )
                                  {
                                    v37 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                                   + 12)
                                        - v2->goldTotal;
                                    sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v37);
                                    v38 = (int)&v2->playerGold;
                                    if( TEasy_Panel::create_text(
                                           (TEasy_Panel *)&v2->vfptr,
                                           (TPanel *)&v2->vfptr,
                                           &v2->playerGold,
                                           temp_str,
                                           520,
                                           30 * v2->cur_player_row + 80,
                                           40,
                                           30,
                                           11,
                                           0,
                                           1,
                                           0) )
                                    {
                                      v39 = (signed __int64)(*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num
                                                                      + 8)
                                                           - v2->stoneTotal);
                                      sprintf(temp_str, aLd_0, (_DWORD)v39);
                                      v40 = (int)&v2->playerStone;
                                      if( TEasy_Panel::create_text(
                                             (TEasy_Panel *)&v2->vfptr,
                                             (TPanel *)&v2->vfptr,
                                             &v2->playerStone,
                                             temp_str,
                                             560,
                                             30 * v2->cur_player_row + 80,
                                             40,
                                             30,
                                             11,
                                             0,
                                             1,
                                             0) )
                                      {
                                        v41 = RGE_Base_Game::get_player(rge_base_game);
                                        if( RGE_Object_List::find_by_master_id(
                                               (RGE_Object_List *)v41->map,
                                               84,
                                               -1.0,
                                               -1.0,
                                               1,
                                               2,
                                               0) )
                                        {
                                          v42 = v2->needMarket;
                                          v2->tribute_flag = 1;
                                          (*(void (__stdcall **)(_DWORD, int))&v42->vfptr->gap10[4])(0, v48);
                                          (*(void (__stdcall **)(signed int))&v2->title[6]->vfptr->gap10[4])(1);
                                          (*(void (__stdcall **)(signed int))&v2->playerWood->vfptr->gap10[4])(1);
                                          (*(void (__stdcall **)(signed int))&v2->playerFood->vfptr->gap10[4])(1);
                                          (*(void (__stdcall **)(signed int))(**(_DWORD **)v38 + 20))(1);
                                          (*(void (__cdecl **)(signed int))(**(_DWORD **)v40 + 20))(1);
                                        }
                                        else
                                        {
                                          v43 = v2->needMarket;
                                          v2->tribute_flag = 0;
                                          (*(void (__stdcall **)(signed int, int))&v43->vfptr->gap10[4])(1, v48);
                                          (*(void (__stdcall **)(_DWORD))&v2->title[6]->vfptr->gap10[4])(0);
                                          (*(void (__stdcall **)(_DWORD))&v2->playerWood->vfptr->gap10[4])(0);
                                          (*(void (__stdcall **)(_DWORD))&v2->playerFood->vfptr->gap10[4])(0);
                                          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v38 + 20))(0);
                                          (*(void (__cdecl **)(signed int))(**(_DWORD **)v40 + 20))(0);
                                        }
                                        v44 = RGE_Base_Game::get_player(rge_base_game);
                                        if( TRIBE_Player_Tech::get_tech_state(
                                               (TRIBE_Player_Tech *)LODWORD(v44[2].game_speed),
                                               30) == 3 )
                                          (*(void (__stdcall **)(_DWORD))&v2->title[6]->vfptr->gap10[4])(0);
                                        TribeDiplomacyDialog::check_gold(v2);
                                        TribeDiplomacyDialog::check_wood(v2);
                                        TribeDiplomacyDialog::check_food(v2);
                                        TribeDiplomacyDialog::check_stone(v2);
                                        TPanel::set_curr_child((TPanel *)&v2->vfptr, (TPanel *)v2->okButton);
                                        if( v2->okButton )
                                        {
                                          tabList[0] = (TPanel *)v2->okButton;
                                          tabCount = 1;
                                        }
                                        v45 = (TPanel *)v2->clearButton;
                                        v46 = tabCount;
                                        if( v45 )
                                        {
                                          tabList[tabCount] = v45;
                                          v46 = tabCount + 1;
                                        }
                                        v47 = (TPanel *)v2->cancelButton;
                                        if( v47 )
                                        {
                                          tabList[v46] = v47;
                                          LOWORD(v46) = v46 + 1;
                                        }
                                        TPanel::set_tab_order(tabList, v46);
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
// 56F898: using guessed type int (__thiscall *TribeDiplomacyDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043D6C0) --------------------------------------------------------
TribeDiplomacyDialog *__thiscall TribeDiplomacyDialog::`vector deleting destructor'(TribeDiplomacyDialog *this, unsigned int __flags)
{
  TribeDiplomacyDialog *v2; // esi@1

  v2 = this;
  TribeDiplomacyDialog::~TribeDiplomacyDialog(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043D6E0) --------------------------------------------------------
void __thiscall TribeDiplomacyDialog::~TribeDiplomacyDialog(TribeDiplomacyDialog *this)
{
  TribeDiplomacyDialog *v1; // ebx@1
  char *v2; // esi@1
  signed int v3; // edi@1
  void (__stdcall ***v4)(_DWORD); // ecx@2
  void (__stdcall ***v5)(_DWORD); // ecx@6
  void (__stdcall ***v6)(_DWORD); // ecx@8
  void (__stdcall ***v7)(_DWORD); // ecx@10
  void (__stdcall ***v8)(_DWORD); // ecx@12
  void (__stdcall ***v9)(_DWORD); // ecx@14
  void (__stdcall ***v10)(_DWORD); // ecx@16
  TButtonPanel **v11; // esi@19
  signed int v12; // edi@19
  TButtonPanel *v13; // ecx@23
  TButtonPanel *v14; // ecx@25
  TButtonPanel *v15; // ecx@27
  TButtonPanel *v16; // ecx@29
  TButtonPanel *v17; // ecx@31
  TTextPanel *v18; // ecx@33
  TTextPanel *v19; // ecx@35
  TTextPanel *v20; // ecx@37
  TTextPanel *v21; // ecx@39
  TTextPanel *v22; // ecx@41
  TShape *v23; // esi@43
  TShape *v24; // esi@45

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeDiplomacyDialog::`vftable';
  v2 = (char *)this->playerVictoryScores;
  v3 = 8;
  do
  {
    v4 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 - 16);
    if( v4 )
      (**v4)(1);
    if( *(_DWORD *)v2 )
      (***(void (__stdcall ****)(_DWORD))v2)(1);
    v5 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 - 8);
    if( v5 )
      (**v5)(1);
    v6 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 + 8);
    if( v6 )
      (**v6)(1);
    v7 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 + 25);
    if( v7 )
      (**v7)(1);
    v8 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 + 33);
    if( v8 )
      (**v8)(1);
    v9 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 + 17);
    if( v9 )
      (**v9)(1);
    v10 = (void (__stdcall ***)(_DWORD))*((_DWORD *)v2 + 41);
    if( v10 )
      (**v10)(1);
    v2 += 4;
    --v3;
  }
  while( v3 );
  v11 = v1->allyButton;
  v12 = 24;
  do
  {
    if( *v11 )
      (**(void (__stdcall ***)(_DWORD))*v11)(1);
    ++v11;
    --v12;
  }
  while( v12 );
  v13 = v1->allianceButton;
  if( v13 )
    (**(void (__stdcall ***)(_DWORD))v13)(1);
  v14 = v1->okButton;
  if( v14 )
    (**(void (__stdcall ***)(_DWORD))v14)(1);
  v15 = v1->cancelButton;
  if( v15 )
    (**(void (__stdcall ***)(_DWORD))v15)(1);
  v16 = v1->clearButton;
  if( v16 )
    (**(void (__stdcall ***)(_DWORD))v16)(1);
  v17 = v1->help_button;
  if( v17 )
    (**(void (__stdcall ***)(_DWORD))v17)(1);
  v18 = v1->playerFood;
  if( v18 )
    ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
  v19 = v1->playerGold;
  if( v19 )
    ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
  v20 = v1->playerWood;
  if( v20 )
    ((void (__stdcall *)(signed int))v20->vfptr->__vecDelDtor)(1);
  v21 = v1->playerStone;
  if( v21 )
    ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
  v22 = v1->needMarket;
  if( v22 )
    ((void (__stdcall *)(signed int))v22->vfptr->__vecDelDtor)(1);
  v23 = v1->buttonPics;
  if( v23 )
  {
    TShape::~TShape(v1->buttonPics);
    operator delete(v23);
  }
  v24 = v1->backgroundPics;
  if( v24 )
  {
    TShape::~TShape(v1->backgroundPics);
    operator delete(v24);
  }
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56F898: using guessed type int (__thiscall *TribeDiplomacyDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043D8A0) --------------------------------------------------------
int __thiscall TribeDiplomacyDialog::action(TribeDiplomacyDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeDiplomacyDialog *v5; // esi@1
  TRIBE_Command *v6; // edi@4
  RGE_Player *v7; // eax@5
  int v8; // ebx@5
  char v9; // ST30_1@6
  RGE_Game_World *v10; // eax@6
  RGE_Base_Game *v11; // ecx@7
  signed int v12; // edi@7
  RGE_Game_World *v13; // eax@7
  float *v14; // ebp@8
  int v15; // esi@8
  char v16; // bl@12
  RGE_Player *v17; // eax@15
  RGE_Game_World *v18; // eax@16
  RGE_Game_World *v19; // esi@18
  RGE_Game_WorldVtbl *v20; // ebx@18
  int v21; // eax@18
  RGE_Game_World *v22; // esi@20
  RGE_Game_WorldVtbl *v23; // ebx@20
  int v24; // edx@20
  RGE_Game_World *v25; // ebx@22
  RGE_Game_WorldVtbl *v26; // esi@22
  int v27; // ecx@22
  RGE_Game_World *v28; // ebx@24
  RGE_Game_WorldVtbl *v29; // esi@24
  int v30; // eax@24
  int result; // eax@28
  char *v32; // edi@38
  signed int v33; // ebp@38
  TButtonPanel *v34; // ecx@39
  TButtonPanel *v35; // ecx@43
  TButtonPanel *v36; // ecx@45
  double v37; // st7@48
  signed __int64 v38; // rax@48
  double v39; // st7@48
  signed __int64 v40; // rax@48
  int v41; // ebx@51
  signed int v42; // edi@51
  int v43; // ecx@51
  int v44; // eax@52
  double v45; // st7@61
  double v46; // st7@61
  signed __int64 v47; // rax@63
  double v48; // st7@64
  double v49; // st7@69
  double v50; // st7@69
  double v51; // st7@71
  double v52; // st7@72
  double v53; // st7@77
  double v54; // st7@77
  double v55; // st7@79
  double v56; // st7@80
  double v57; // st7@85
  double v58; // st7@85
  double v59; // st7@87
  double v60; // st7@88
  float cost; // [sp+44h] [bp-108h]@8
  float costa; // [sp+44h] [bp-108h]@49
  float costb; // [sp+44h] [bp-108h]@60
  float costc; // [sp+44h] [bp-108h]@68
  float costd; // [sp+44h] [bp-108h]@76
  float coste; // [sp+44h] [bp-108h]@84
  TRIBE_Command *tc; // [sp+48h] [bp-104h]@4
  char temp_str[256]; // [sp+4Ch] [bp-100h]@48

  v5 = this;
  if( !fromPanel || actionIn != 1 )
    return TPanel::action((TPanel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  if( fromPanel == (TPanel *)this->okButton )
  {
    v6 = (TRIBE_Command *)rge_base_game->world->commands;
    tc = (TRIBE_Command *)rge_base_game->world->commands;
    if( allow_user_commands )
    {
      v7 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
      v8 = (unsigned __int8)RGE_Player::get_allied_victory(v7);
      if( TButtonPanel::get_state(v5->allianceButton) != v8 )
      {
        v9 = TButtonPanel::get_state(v5->allianceButton);
        v10 = RGE_Base_Game::get_player(rge_base_game);
        TRIBE_Command::command_allied_victory(v6, HIWORD(v10->master_players), v9);
      }
    }
    v11 = rge_base_game;
    v12 = 1;
    v13 = rge_base_game->world;
    if( v13->player_num - 1 > 0 )
    {
      v14 = v5->woodTributeAmount;
      v15 = (int)v5->allyButton;
      cost = *(float *)&v15;
      do
      {
        if( v12 != v13->curr_player && *(_DWORD *)v15 )
        {
          v16 = TButtonPanel::get_state(*(TButtonPanel **)v15) == 1 ? 0 : TButtonPanel::get_state(*(TButtonPanel **)(v15 + 4)) != 1 ? 3 : 1;
          if( allow_user_commands )
          {
            v17 = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
            if( RGE_Player::relation(v17, v12) != v16 )
            {
              v18 = RGE_Base_Game::get_player(rge_base_game);
              TRIBE_Command::command_relation(tc, HIWORD(v18->master_players), v12, (unsigned __int8)v16);
            }
            if( *(v14 - 24) > 0.0 )
            {
              v19 = RGE_Base_Game::get_player(rge_base_game);
              v20 = v19->vfptr;
              v21 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num;
              ((void (__thiscall *)(RGE_Game_World *, signed int, signed int, _DWORD, _DWORD))v20->addObject)(
                v19,
                v12,
                3,
                *((_DWORD *)v14 - 24),
                *(float *)(v21 + 184));
            }
            if( *v14 > 0.0 )
            {
              v22 = RGE_Base_Game::get_player(rge_base_game);
              v23 = v22->vfptr;
              v24 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num;
              ((void (__thiscall *)(RGE_Game_World *, signed int, signed int, float, _DWORD))v23->addObject)(
                v22,
                v12,
                1,
                COERCE_FLOAT(*(_DWORD *)v14),
                *(float *)(v24 + 184));
            }
            if( *(v14 - 16) > 0.0 )
            {
              v25 = RGE_Base_Game::get_player(rge_base_game);
              v26 = v25->vfptr;
              v27 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num;
              ((void (__thiscall *)(RGE_Game_World *, signed int, _DWORD, _DWORD, _DWORD))v26->addObject)(
                v25,
                v12,
                0,
                *((_DWORD *)v14 - 16),
                *(float *)(v27 + 184));
            }
            if( *(v14 - 8) > 0.0 )
            {
              v28 = RGE_Base_Game::get_player(rge_base_game);
              v29 = v28->vfptr;
              v30 = *(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num;
              ((void (__thiscall *)(RGE_Game_World *, signed int, signed int, _DWORD, _DWORD))v29->addObject)(
                v28,
                v12,
                2,
                *((_DWORD *)v14 - 8),
                *(float *)(v30 + 184));
            }
          }
        }
        ++v12;
        v15 = LODWORD(cost) + 12;
        v13 = rge_base_game->world;
        ++v14;
        LODWORD(cost) += 12;
      }
      while( v12 - 1 < v13->player_num - 1 );
      if( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
      {
        RGE_Base_Game::set_paused(rge_base_game, 0, 0);
        TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
        TPanelSystem::destroyPanel(&panel_system, aDiplomacyDialo);
        return 1;
      }
      goto LABEL_34;
    }
LABEL_31:
    if( RGE_Base_Game::singlePlayerGame(v11) == 1 && !rge_base_game->save_paused )
      RGE_Base_Game::set_paused(rge_base_game, 0, 0);
LABEL_34:
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
    TPanelSystem::destroyPanel(&panel_system, aDiplomacyDialo);
    return 1;
  }
  if( fromPanel == (TPanel *)this->cancelButton )
  {
    v11 = rge_base_game;
    goto LABEL_31;
  }
  if( fromPanel == (TPanel *)this->help_button )
  {
    TEasy_Panel::setup_popup_help((TEasy_Panel *)&this->vfptr);
    return 1;
  }
  if( fromPanel == (TPanel *)this->clearButton )
  {
    v32 = (char *)this->foodTributeButton;
    LODWORD(this->foodTotal) = 0;
    LODWORD(this->goldTotal) = 0;
    LODWORD(this->stoneTotal) = 0;
    LODWORD(this->woodTotal) = 0;
    v33 = 8;
    do
    {
      v34 = (TButtonPanel *)*((_DWORD *)v32 - 16);
      if( v34 )
        TButtonPanel::set_text(v34, 0, message_in);
      if( *(_DWORD *)v32 )
        TButtonPanel::set_text(*(TButtonPanel **)v32, 0, message_in);
      v35 = (TButtonPanel *)*((_DWORD *)v32 - 8);
      if( v35 )
        TButtonPanel::set_text(v35, 0, message_in);
      v36 = (TButtonPanel *)*((_DWORD *)v32 + 8);
      if( v36 )
        TButtonPanel::set_text(v36, 0, message_in);
      *((_DWORD *)v32 + 55) = 0;
      *((_DWORD *)v32 + 63) = 0;
      *((_DWORD *)v32 + 71) = 0;
      *((_DWORD *)v32 + 79) = 0;
      v32 += 4;
      --v33;
    }
    while( v33 );
    v37 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 12);
    sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v37);
    (*(void (__stdcall **)(char *))&v5->playerGold->vfptr[1].gap4[4])(temp_str);
    v38 = (signed __int64)**(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num;
    sprintf(temp_str, aLd_0, (_DWORD)v38);
    (*(void (__stdcall **)(char *))&v5->playerFood->vfptr[1].gap4[4])(temp_str);
    v39 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 4);
    sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v39);
    (*(void (__stdcall **)(char *))&v5->playerWood->vfptr[1].gap4[4])(temp_str);
    v40 = (signed __int64)*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 8);
    sprintf(temp_str, aLd_0, (_DWORD)v40);
    (*(void (__stdcall **)(char *))&v5->playerStone->vfptr[1].gap4[4])(temp_str);
    TribeDiplomacyDialog::check_gold(v5);
    TribeDiplomacyDialog::check_wood(v5);
    TribeDiplomacyDialog::check_stone(v5);
    TribeDiplomacyDialog::check_food(v5);
    return 1;
  }
  costa = 0.0;
  if( *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 184) > 0.0 )
    costa = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 184);
  v41 = 0;
  v42 = 1;
  v43 = rge_base_game->world->player_num - 1;
  if( v43 <= 0 )
    return TPanel::action((TPanel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  v44 = (int)v5->woodTributeButton;
  while( fromPanel != *(TPanel **)(v44 - 32) )
  {
    if( fromPanel == *(TPanel **)v44 )
    {
      if( TribeDiplomacyDialog::check_wood(v5) )
      {
        v52 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 4) - v5->woodTotal;
        if( v52 < 0.0 )
          v52 = 0.0;
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v52);
        (*(void (__stdcall **)(char *))&v5->playerWood->vfptr[1].gap4[4])(temp_str);
        TribeDiplomacyDialog::check_wood(v5);
        result = 1;
      }
      else
      {
        costc = costa - -1.0;
        if( costc * 100.0 <= *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 4)
                            - v5->woodTotal )
        {
          v5->stoneTributeAmount[v42 + 7] = v5->stoneTributeAmount[v42 + 7] - -100.0;
          v50 = v5->woodTotal - costc * -100.0;
        }
        else
        {
          v49 = (*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 4) - v5->woodTotal)
              / costc;
          v5->stoneTributeAmount[v42 + 7] = v49 + v5->stoneTributeAmount[v42 + 7];
          v50 = v49 * costc + v5->woodTotal;
        }
        v5->woodTotal = v50;
        v51 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 4) - v5->woodTotal;
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v51);
        (*(void (__stdcall **)(char *))&v5->playerWood->vfptr[1].gap4[4])(temp_str);
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v5->stoneTributeAmount[v42 + 7]);
        TButtonPanel::set_text(v5->woodTributeButton[v41], 0, temp_str);
        TribeDiplomacyDialog::check_wood(v5);
        result = 1;
      }
      return result;
    }
    if( fromPanel == *(TPanel **)(v44 + 32) )
    {
      if( TribeDiplomacyDialog::check_food(v5) )
      {
        v56 = **(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num - v5->foodTotal;
        if( v56 < 0.0 )
          v56 = 0.0;
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v56);
        (*(void (__stdcall **)(char *))&v5->playerFood->vfptr[1].gap4[4])(temp_str);
        TribeDiplomacyDialog::check_food(v5);
        result = 1;
      }
      else
      {
        costd = costa - -1.0;
        if( costd * 100.0 <= **(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num - v5->foodTotal )
        {
          v5->goldTributeAmount[v42 + 7] = v5->goldTributeAmount[v42 + 7] - -100.0;
          v54 = v5->foodTotal - costd * -100.0;
        }
        else
        {
          v53 = (**(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num - v5->foodTotal) / costd;
          v5->goldTributeAmount[v42 + 7] = v53 + v5->goldTributeAmount[v42 + 7];
          v54 = v53 * costd + v5->foodTotal;
        }
        v5->foodTotal = v54;
        v55 = **(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num - v5->foodTotal;
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v55);
        (*(void (__stdcall **)(char *))&v5->playerFood->vfptr[1].gap4[4])(temp_str);
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v5->goldTributeAmount[v42 + 7]);
        TButtonPanel::set_text(v5->foodTributeButton[v41], 0, temp_str);
        TribeDiplomacyDialog::check_food(v5);
        result = 1;
      }
      return result;
    }
    if( fromPanel == *(TPanel **)(v44 + 64) )
    {
      if( TribeDiplomacyDialog::check_stone(v5) )
      {
        v60 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 8) - v5->stoneTotal;
        if( v60 < 0.0 )
          v60 = 0.0;
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v60);
        (*(void (__stdcall **)(char *))&v5->playerStone->vfptr[1].gap4[4])(temp_str);
        TribeDiplomacyDialog::check_stone(v5);
        result = 1;
      }
      else
      {
        coste = costa - -1.0;
        if( coste * 100.0 <= *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 8)
                            - v5->stoneTotal )
        {
          v5->foodTributeAmount[v42 + 7] = v5->foodTributeAmount[v42 + 7] - -100.0;
          v58 = v5->stoneTotal - coste * -100.0;
        }
        else
        {
          v57 = (*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 8) - v5->stoneTotal)
              / coste;
          v5->foodTributeAmount[v42 + 7] = v57 + v5->foodTributeAmount[v42 + 7];
          v58 = v57 * coste + v5->stoneTotal;
        }
        v5->stoneTotal = v58;
        v59 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 8) - v5->stoneTotal;
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v59);
        (*(void (__stdcall **)(char *))&v5->playerStone->vfptr[1].gap4[4])(temp_str);
        sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v5->foodTributeAmount[v42 + 7]);
        TButtonPanel::set_text(v5->stoneTributeButton[v41], 0, temp_str);
        TribeDiplomacyDialog::check_stone(v5);
        result = 1;
      }
      return result;
    }
    ++v41;
    v44 += 4;
    ++v42;
    if( v41 >= v43 )
      return TPanel::action((TPanel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  }
  if( TribeDiplomacyDialog::check_gold(v5) )
  {
    v48 = *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 12) - v5->goldTotal;
    if( v48 < 0.0 )
      v48 = 0.0;
    sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)v48);
    (*(void (__stdcall **)(char *))&v5->playerGold->vfptr[1].gap4[4])(temp_str);
    TribeDiplomacyDialog::check_gold(v5);
    result = 1;
  }
  else
  {
    costb = costa - -1.0;
    if( costb * 100.0 <= *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 12)
                        - v5->goldTotal )
    {
      *((float *)&v5->playerStone + v42) = *((float *)&v5->playerStone + v42) - -100.0;
      v46 = v5->goldTotal - costb * -100.0;
    }
    else
    {
      v45 = (*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 12) - v5->goldTotal) / costb;
      *((float *)&v5->playerStone + v42) = v45 + *((float *)&v5->playerStone + v42);
      v46 = v45 * costb + v5->goldTotal;
    }
    v5->goldTotal = v46;
    v47 = (signed __int64)(*(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 12)
                         - v5->goldTotal);
    sprintf(temp_str, aLd_0, (_DWORD)v47);
    (*(void (__stdcall **)(char *))&v5->playerGold->vfptr[1].gap4[4])(temp_str);
    sprintf(temp_str, aLd_0, (unsigned int)(signed __int64)*((float *)&v5->playerStone + v42));
    TButtonPanel::set_text(v5->goldTributeButton[v41], 0, temp_str);
    TribeDiplomacyDialog::check_gold(v5);
    result = 1;
  }
  return result;
}
// 58631C: using guessed type int allow_user_commands;

//----- (0043E530) --------------------------------------------------------
int __thiscall TribeDiplomacyDialog::check_gold(TribeDiplomacyDialog *this)
{
  TribeDiplomacyDialog *v1; // ebx@1
  int v2; // ebp@3
  signed int v3; // edi@5
  TButtonPanel **v4; // esi@5
  TButtonPanel *v5; // ecx@6
  TButtonPanel *v6; // ecx@10

  v1 = this;
  v2 = rge_base_game->prog_mode == 5
    || *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 12) - this->goldTotal <= 0.0;
  v3 = 0;
  v4 = v1->goldTributeButton;
  do
  {
    v5 = *v4;
    if( *v4 )
    {
      if( v3 == v1->cur_player_row )
        TButtonPanel::set_disabled(v5, 1);
      else
        TButtonPanel::set_disabled(v5, v2);
      v6 = *v4;
      if( v1->tribute_flag )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v6 + 20))(1);
      else
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 20))(0);
    }
    ++v3;
    ++v4;
  }
  while( v3 < 8 );
  return v2;
}

//----- (0043E5C0) --------------------------------------------------------
int __thiscall TribeDiplomacyDialog::check_wood(TribeDiplomacyDialog *this)
{
  TribeDiplomacyDialog *v1; // ebx@1
  int v2; // ebp@3
  signed int v3; // edi@5
  TButtonPanel **v4; // esi@5
  TButtonPanel *v5; // ecx@6
  TButtonPanel *v6; // ecx@10

  v1 = this;
  v2 = rge_base_game->prog_mode == 5
    || *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 4) - this->woodTotal <= 0.0;
  v3 = 0;
  v4 = v1->woodTributeButton;
  do
  {
    v5 = *v4;
    if( *v4 )
    {
      if( v3 == v1->cur_player_row )
        TButtonPanel::set_disabled(v5, 1);
      else
        TButtonPanel::set_disabled(v5, v2);
      v6 = *v4;
      if( v1->tribute_flag )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v6 + 20))(1);
      else
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 20))(0);
    }
    ++v3;
    ++v4;
  }
  while( v3 < 8 );
  return v2;
}

//----- (0043E650) --------------------------------------------------------
int __thiscall TribeDiplomacyDialog::check_food(TribeDiplomacyDialog *this)
{
  TribeDiplomacyDialog *v1; // ebx@1
  int v2; // ebp@3
  signed int v3; // edi@5
  TButtonPanel **v4; // esi@5
  TButtonPanel *v5; // ecx@6
  TButtonPanel *v6; // ecx@10

  v1 = this;
  v2 = rge_base_game->prog_mode == 5
    || **(float **)&RGE_Base_Game::get_player(rge_base_game)->terrain_num - this->foodTotal <= 0.0;
  v3 = 0;
  v4 = v1->foodTributeButton;
  do
  {
    v5 = *v4;
    if( *v4 )
    {
      if( v3 == v1->cur_player_row )
        TButtonPanel::set_disabled(v5, 1);
      else
        TButtonPanel::set_disabled(v5, v2);
      v6 = *v4;
      if( v1->tribute_flag )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v6 + 20))(1);
      else
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 20))(0);
    }
    ++v3;
    ++v4;
  }
  while( v3 < 8 );
  return v2;
}

//----- (0043E6E0) --------------------------------------------------------
int __thiscall TribeDiplomacyDialog::check_stone(TribeDiplomacyDialog *this)
{
  TribeDiplomacyDialog *v1; // ebx@1
  int v2; // ebp@3
  signed int v3; // edi@5
  TButtonPanel **v4; // esi@5
  TButtonPanel *v5; // ecx@6
  TButtonPanel *v6; // ecx@10

  v1 = this;
  v2 = rge_base_game->prog_mode == 5
    || *(float *)(*(_DWORD *)&RGE_Base_Game::get_player(rge_base_game)->terrain_num + 8) - this->stoneTotal <= 0.0;
  v3 = 0;
  v4 = v1->stoneTributeButton;
  do
  {
    v5 = *v4;
    if( *v4 )
    {
      if( v3 == v1->cur_player_row )
        TButtonPanel::set_disabled(v5, 1);
      else
        TButtonPanel::set_disabled(v5, v2);
      v6 = *v4;
      if( v1->tribute_flag )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v6 + 20))(1);
      else
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 20))(0);
    }
    ++v3;
    ++v4;
  }
  while( v3 < 8 );
  return v2;
}

//----- (0043E770) --------------------------------------------------------
void __thiscall TribeDiplomacyDialog::draw(TribeDiplomacyDialog *this)
{
  TribeDiplomacyDialog *v1; // esi@1
  int v2; // ebp@1
  TPanelVtbl *v3; // ebx@2
  RGE_Game_World *v4; // edi@2
  signed int v5; // ebx@3
  RGE_Color_Table *v6; // eax@4
  int v7; // [sp+8h] [bp-8h]@3
  TPanelVtbl *v8; // [sp+Ch] [bp-4h]@2

  v1 = this;
  TEasy_Panel::draw((TEasy_Panel *)&this->vfptr);
  v2 = 0;
  if( v1->backgroundPics )
  {
    v3 = v1->vfptr;
    v4 = rge_base_game->world;
    v8 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    if( v4->player_num - 1 > 0 )
    {
      v7 = 0;
      v5 = 1;
      do
      {
        v6 = v4->players[v5]->color_table;
        if( v6 )
        {
          ASMSet_Color_Xform(16 * (v6->id + 1));
          TShape::shape_draw(
            v1->backgroundPics,
            v1->render_area,
            v1->pnl_x + 10,
            v1->pnl_y + v2 + 80,
            0,
            1,
            v4->players[v5]->color_table->table);
        }
        v2 += 30;
        ++v5;
        ++v7;
      }
      while( v7 < v4->player_num - 1 );
      v3 = v8;
    }
    v3->draw_finish((TPanel *)v1);
  }
}
