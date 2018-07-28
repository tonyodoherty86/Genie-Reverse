
//----- (0048D530) --------------------------------------------------------
void __thiscall TribeAchievementsScreen::TribeAchievementsScreen(TribeAchievementsScreen *this, char *titleText, int end_flag)
{
  TribeAchievementsScreen *v3; // ebp@1
  int v4; // ebx@1
  int v5; // eax@1
  TTextPanel *(*v6)[7]; // esi@1
  TTextPanel **v7; // edx@1
  unsigned int v8; // ecx@5
  char v9; // al@5
  char *v10; // edi@5
  char *v11; // esi@5
  int v12; // eax@5
  unsigned int v13; // ecx@6
  char v14; // al@6
  char *v15; // edi@6
  char *v16; // esi@6
  unsigned int v17; // ecx@7
  char v18; // al@7
  char *v19; // edi@7
  char *v20; // esi@7
  int v21; // esi@10
  int v22; // edi@10
  signed int v23; // ecx@10
  char *v24; // eax@15
  char *v25; // edi@17
  TTextPanel **v26; // esi@19
  int v27; // esi@22
  int v28; // edi@22
  RGE_Game_World *v29; // eax@23
  char *v30; // eax@24
  TTextPanel **v31; // ebx@26
  RGE_Game_World *v32; // eax@26
  TButtonPanel *v33; // eax@46
  TButtonPanel *v34; // eax@46
  TButtonPanel *v35; // eax@46
  TShape *v36; // eax@47
  TShape *v37; // eax@48
  TShape *v38; // eax@49
  TPanel *v39; // ecx@52
  signed int v40; // eax@52
  TPanel *v41; // ecx@54
  TPanel *v42; // ecx@56
  int v43; // [sp+2Ch] [bp-20Ch]@43
  int v44; // [sp+34h] [bp-204h]@43
  char *color; // [sp+58h] [bp-1E0h]@28
  signed int v46; // [sp+5Ch] [bp-1DCh]@1
  signed int v47; // [sp+5Ch] [bp-1DCh]@22
  signed int v48; // [sp+60h] [bp-1D8h]@37
  TTextPanel **text_panel; // [sp+64h] [bp-1D4h]@22
  signed int v50; // [sp+68h] [bp-1D0h]@22
  TPanel *tabList[8]; // [sp+70h] [bp-1C8h]@53
  char temptxt[50]; // [sp+90h] [bp-1A8h]@1
  char str[100]; // [sp+C4h] [bp-174h]@13
  char info_file[260]; // [sp+128h] [bp-110h]@5
  int v55; // [sp+234h] [bp-4h]@1

  v3 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aAchievementsSc);
  *(_DWORD *)&temptxt[31] = 0;
  v4 = (int)&v3->close_button;
  *(_DWORD *)&temptxt[35] = 0;
  *(_DWORD *)&temptxt[39] = 0;
  v55 = 0;
  *(_DWORD *)&temptxt[43] = 0;
  v3->title = 0;
  v3->time = 0;
  v3->summary_text = 0;
  v3->win_loss_text = 0;
  v3->instruction = 0;
  v3->time_line = 0;
  v3->okButton = 0;
  v3->timelineButton = 0;
  v3->restartButton = 0;
  v3->aftermathButton = 0;
  v3->backButton = 0;
  v3->backButton2 = 0;
  v3->win_decal = 0;
  v3->close_button = 0;
  v3->instruction_bar = 0;
  v3->win_loss_text_bar = 0;
  v3->summary_text_bar = 0;
  *(_WORD *)&temptxt[47] = 0;
  v5 = (int)v3->achievement_choice;
  v3->vfptr = (TPanelVtbl *)&TribeAchievementsScreen::`vftable';
  temptxt[49] = 0;
  v3->end_game_flag = end_flag;
  *(_DWORD *)v5 = 0;
  v6 = v3->statistics;
  *(_DWORD *)(v5 + 4) = 0;
  v7 = v3->player_names;
  v46 = 8;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 16) = 0;
  memset(v3->title_bar, 0, sizeof(v3->title_bar));
  do
  {
    *v7 = 0;
    memset(v6, 0, sizeof(TTextPanel *[7]));
    ++v7;
    ++v6;
    --v46;
  }
  while( v46 );
  if( v3->end_game_flag )
  {
    if( LOBYTE(RGE_Base_Game::get_player(rge_base_game)->sound_driver) == 1 )
    {
      v8 = strlen(aScr7) + 1;
      v9 = v8;
      v8 >>= 2;
      qmemcpy(info_file, aScr7, 4 * v8);
      v11 = &aScr7[4 * v8];
      v10 = &info_file[4 * v8];
      LOBYTE(v8) = v9;
      v12 = 50057;
      qmemcpy(v10, v11, v8 & 3);
    }
    else
    {
      v13 = strlen(aScr8) + 1;
      v14 = v13;
      v13 >>= 2;
      qmemcpy(info_file, aScr8, 4 * v13);
      v16 = &aScr8[4 * v13];
      v15 = &info_file[4 * v13];
      LOBYTE(v13) = v14;
      v12 = 50058;
      qmemcpy(v15, v16, v13 & 3);
    }
  }
  else
  {
    v17 = strlen(aScr10) + 1;
    v18 = v17;
    v17 >>= 2;
    qmemcpy(info_file, aScr10, 4 * v17);
    v20 = &aScr10[4 * v17];
    v19 = &info_file[4 * v17];
    LOBYTE(v17) = v18;
    v12 = 50061;
    qmemcpy(v19, v20, v17 & 3);
  }
  if( !TScreenPanel::setup((TScreenPanel *)&v3->vfptr, rge_base_game->draw_area, info_file, v12, 1) )
  {
    v3->error_code = 1;
    return;
  }
  TEasy_Panel::set_ideal_size((TEasy_Panel *)&v3->vfptr, 640, 480);
  v21 = 0;
  v22 = 0;
  v23 = rge_base_game->world->world_time / 0x3E8;
  if( v23 > 59 )
  {
    v21 = v23 / 60;
    v23 %= 60;
    if( v21 > 59 )
    {
      v22 = v21 / 60;
      v21 %= 60;
    }
  }
  sprintf(str, a02ld02ld02ld, v22, v21, v23);
  TEasy_Panel::create_text(
    (TEasy_Panel *)&v3->vfptr,
    (TPanel *)&v3->vfptr,
    &v3->time,
    str,
    480,
    10,
    110,
    20,
    11,
    0,
    0,
    0);
  TTextPanel::set_alignment(v3->time, AlignTop, AlignRight);
  TEasy_Panel::create_text((TEasy_Panel *)&v3->vfptr, (TPanel *)&v3->vfptr, &v3->title, 9886, 0, 5, 640, 30, 1, 1, 0, 0);
  TEasy_Panel::create_text(
    (TEasy_Panel *)&v3->vfptr,
    (TPanel *)&v3->vfptr,
    &v3->summary_text,
    0,
    10,
    35,
    620,
    30,
    1,
    1,
    0,
    0);
  TEasy_Panel::create_text(
    (TEasy_Panel *)&v3->vfptr,
    (TPanel *)&v3->vfptr,
    &v3->instruction,
    9947,
    10,
    410,
    620,
    20,
    11,
    1,
    0,
    0);
  if( v3->end_game_flag )
  {
    v24 = LOBYTE(RGE_Base_Game::get_player(rge_base_game)->sound_driver) == 1 ? RGE_Scenario::Get_message(
                                                                                  rge_base_game->world->scenario,
                                                                                  2) : RGE_Scenario::Get_message(
                                                                                         rge_base_game->world->scenario,
                                                                                         3);
    v25 = v24;
    if( v24 )
    {
      if( *v24 )
      {
        v26 = &v3->win_loss_text;
        TEasy_Panel::create_text(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->win_loss_text,
          message_in,
          10,
          85,
          620,
          330,
          11,
          0,
          0,
          1);
        if( v3->win_loss_text )
        {
          TEasy_Panel::create_auto_scrollbar((TEasy_Panel *)&v3->vfptr, &v3->win_loss_text_bar, v3->win_loss_text, 20);
          ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*v26)->vfptr[1].set_rect)(
            4,
            v3->bevel_color1,
            v3->bevel_color2,
            v3->bevel_color3,
            v3->bevel_color4,
            v3->bevel_color5,
            v3->bevel_color6);
          (*(void (__thiscall **)(TTextPanel *, char *))&(*v26)->vfptr[1].gap4[4])(*v26, v25);
        }
      }
    }
  }
  Time_Line_Panel::create_timeline(
    v3->time_line,
    (TPanel *)&v3->vfptr,
    &v3->time_line,
    10,
    85,
    620,
    330,
    11,
    9,
    640,
    480);
  Time_Line_Panel::set_bevel_info(
    v3->time_line,
    3,
    v3->bevel_color1,
    v3->bevel_color2,
    v3->bevel_color3,
    v3->bevel_color4,
    v3->bevel_color5,
    v3->bevel_color6);
  Time_Line_Panel::set_special_events(v3->time_line, aTimeline_slp);
  if( TEasy_Panel::create_button(
         (TEasy_Panel *)&v3->vfptr,
         (TPanel *)&v3->vfptr,
         &v3->close_button,
         1002,
         0,
         0,
         0,
         0,
         0,
         -1,
         -1,
         0) )
  {
    (*(void (__stdcall **)(signed int))(**(_DWORD **)v4 + 20))(1);
    (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v4 + 24))(
      9,
      4,
      4,
      4,
      4,
      17,
      17,
      17,
      17,
      0,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      v3->title_bar,
      0,
      98,
      151,
      200,
      30,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->title_bar[1],
      0,
      152,
      131,
      200,
      30,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->title_bar[2],
      0,
      212,
      111,
      145,
      30,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->title_bar[3],
      0,
      260,
      91,
      200,
      30,
      11,
      1,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->title_bar[4],
      0,
      364,
      111,
      145,
      30,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->title_bar[5],
      0,
      370,
      131,
      200,
      30,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->title_bar[6],
      0,
      424,
      151,
      200,
      30,
      11,
      0,
      0,
      0);
    TTextPanel::set_alignment(v3->title_bar[4], AlignTop, AlignRight);
    TTextPanel::set_alignment(v3->title_bar[5], AlignTop, AlignRight);
    TTextPanel::set_alignment(v3->title_bar[6], AlignTop, AlignRight);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      v3->achievement_choice,
      0,
      100,
      151,
      130,
      250,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->achievement_choice[1],
      0,
      154,
      131,
      128,
      274,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->achievement_choice[2],
      0,
      214,
      111,
      121,
      289,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->achievement_choice[3],
      0,
      282,
      91,
      156,
      309,
      11,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->achievement_choice[4],
      0,
      388,
      111,
      121,
      289,
      11,
      0,
      0,
      0);
    v47 = 1;
    v50 = 1;
    v27 = 171;
    text_panel = v3->player_names;
    v28 = (int)&v3->statistics[0][2];
    do
    {
      v29 = rge_base_game->world;
      if( v47 >= v29->player_num )
        v30 = 0;
      else
        v30 = v29->players[v50]->name;
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        text_panel,
        v30,
        22,
        v27,
        150,
        29,
        11,
        0,
        1,
        0);
      v31 = (TTextPanel **)(v28 - 8);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)(v28 - 8),
        0,
        178,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)(v28 - 4),
        0,
        231,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)v28,
        0,
        283,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)(v28 + 4),
        0,
        336,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)(v28 + 8),
        0,
        389,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)(v28 + 12),
        0,
        442,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        (TTextPanel **)(v28 + 16),
        0,
        494,
        v27,
        51,
        29,
        11,
        1,
        1,
        0);
      v32 = rge_base_game->world;
      if( v47 < v32->player_num )
      {
        switch ( v32->players[v50]->color_table->id )
        {
          case 0:
            color = (char *)12845056;
            TTextPanel::set_text_color(*text_panel, 0xC40000u, 0);
            break;
          case 1:
            color = (char *)200;
            TTextPanel::set_text_color(*text_panel, 0xC8u, 0);
            break;
          case 2:
            color = (char *)60138;
            TTextPanel::set_text_color(*text_panel, 0xEAEAu, 0);
            break;
          case 3:
            color = (char *)2185868;
            TTextPanel::set_text_color(*text_panel, 0x215A8Cu, 0);
            break;
          case 4:
            color = (char *)33023;
            TTextPanel::set_text_color(*text_panel, 0x80FFu, 0);
            break;
          case 5:
            color = (char *)0x8000;
            TTextPanel::set_text_color(*text_panel, 0x8000u, 0);
            break;
          case 6:
            color = (char *)&pathSystem.MGP_openPaths[54981].total;
            TTextPanel::set_text_color(*text_panel, (unsigned int)&pathSystem.MGP_openPaths[54981].total, 0);
            break;
          case 7:
            color = (char *)&pathSystem.MGP_openPaths[54973].total;
            TTextPanel::set_text_color(*text_panel, (unsigned int)&pathSystem.MGP_openPaths[54973].total, 0);
            break;
          default:
            color = (char *)0xFFFFFF;
            TTextPanel::set_text_color(*text_panel, 0xFFFFFFu, 0);
            break;
        }
        v48 = 7;
        do
        {
          TTextPanel::set_text_color(*v31, (unsigned int)color, 0);
          ++v31;
          --v48;
        }
        while( v48 );
      }
      v27 += 30;
      v28 += 28;
      ++v50;
      ++v47;
      ++text_panel;
    }
    while( v47 - 1 < 8 );
    if( v3->end_game_flag && RGE_Base_Game::singlePlayerGame(rge_base_game) )
    {
      if( v3->win_loss_text )
      {
        TEasy_Panel::create_button(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->aftermathButton,
          9906,
          0,
          5,
          441,
          150,
          30,
          0,
          0,
          0);
        TEasy_Panel::create_button(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->timelineButton,
          9944,
          0,
          165,
          441,
          150,
          30,
          0,
          0,
          0);
        TEasy_Panel::create_button(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->restartButton,
          9887,
          0,
          325,
          441,
          150,
          30,
          0,
          0,
          0);
        v44 = 150;
        v43 = 485;
      }
      else
      {
        TEasy_Panel::create_button(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->timelineButton,
          9944,
          0,
          20,
          441,
          180,
          30,
          0,
          0,
          0);
        TEasy_Panel::create_button(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->restartButton,
          9887,
          0,
          230,
          441,
          180,
          30,
          0,
          0,
          0);
        v44 = 180;
        v43 = 440;
      }
    }
    else
    {
      TEasy_Panel::create_button(
        (TEasy_Panel *)&v3->vfptr,
        (TPanel *)&v3->vfptr,
        &v3->timelineButton,
        9944,
        0,
        100,
        441,
        200,
        30,
        0,
        0,
        0);
      v44 = 200;
      v43 = 340;
    }
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->okButton,
      9884,
      0,
      v43,
      441,
      v44,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->backButton,
      9946,
      0,
      200,
      441,
      240,
      30,
      0,
      0,
      0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->backButton + 20))(0);
    v33 = v3->backButton;
    *((_DWORD *)v33 + 166) = 27;
    *((_DWORD *)v33 + 167) = 0;
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v3->vfptr,
      (TPanel *)&v3->vfptr,
      &v3->backButton2,
      9884,
      0,
      200,
      441,
      240,
      30,
      0,
      0,
      0);
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3->backButton2 + 20))(0);
    v34 = v3->backButton2;
    *((_DWORD *)v34 + 166) = 27;
    *((_DWORD *)v34 + 167) = 0;
    v35 = v3->okButton;
    *((_DWORD *)v35 + 166) = 27;
    *((_DWORD *)v35 + 167) = 0;
    if( LOBYTE(RGE_Base_Game::get_player(rge_base_game)->sound_driver) == 1 )
    {
      v36 = (TShape *)operator new(0x20u);
      LOBYTE(v55) = 1;
      if( v36 )
      {
        TShape::TShape(v36, aViccheck_slp, 52001);
LABEL_52:
        v39 = (TPanel *)v3->aftermathButton;
        v3->win_decal = v37;
        v40 = 0;
        LOBYTE(v55) = 0;
        if( v39 )
        {
          tabList[0] = v39;
          v40 = 1;
        }
        v41 = (TPanel *)v3->timelineButton;
        if( v41 )
          tabList[v40++] = v41;
        v42 = (TPanel *)v3->restartButton;
        if( v42 )
          tabList[v40++] = v42;
        tabList[v40] = (TPanel *)v3->okButton;
        TPanel::set_tab_order(tabList, v40 + 1);
        TPanel::set_curr_child((TPanel *)&v3->vfptr, (TPanel *)v3->okButton);
        (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v3->backButton + 196))(0, 0);
        (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v3->backButton2 + 196))(0, 0);
        if( v3->win_loss_text )
          TribeAchievementsScreen::set_mode(v3, 5);
        else
          TribeAchievementsScreen::set_mode(v3, 0);
        return;
      }
    }
    else
    {
      v38 = (TShape *)operator new(0x20u);
      LOBYTE(v55) = 2;
      if( v38 )
      {
        TShape::TShape(v38, aDefcheck_slp, 52002);
        goto LABEL_52;
      }
    }
    v37 = 0;
    goto LABEL_52;
  }
}
// 572180: using guessed type int (__thiscall *TribeAchievementsScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (0048E1F0) --------------------------------------------------------
TribeAchievementsScreen *__thiscall TribeAchievementsScreen::`vector deleting destructor'(TribeAchievementsScreen *this, unsigned int __flags)
{
  TribeAchievementsScreen *v2; // esi@1

  v2 = this;
  TribeAchievementsScreen::~TribeAchievementsScreen(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048E210) --------------------------------------------------------
void __thiscall TribeAchievementsScreen::~TribeAchievementsScreen(TribeAchievementsScreen *this)
{
  TribeAchievementsScreen *v1; // ebx@1
  TShape *v2; // esi@1
  TTextPanel *v3; // ecx@3
  TTextPanel *v4; // ecx@5
  TTextPanel *v5; // ecx@7
  TTextPanel *v6; // ecx@9
  TTextPanel *v7; // ecx@11
  TButtonPanel *v8; // ecx@13
  TButtonPanel *v9; // ecx@15
  TButtonPanel *v10; // ecx@17
  TButtonPanel *v11; // ecx@19
  TButtonPanel *v12; // ecx@21
  TButtonPanel *v13; // ecx@23
  Time_Line_Panel *v14; // ecx@25
  TScrollBarPanel *v15; // ecx@27
  TScrollBarPanel *v16; // ecx@29
  TScrollBarPanel *v17; // ecx@31
  TTextPanel **v18; // esi@33
  signed int v19; // edi@33
  TTextPanel **v20; // esi@37
  signed int v21; // edi@37
  TTextPanel *(*v22)[7]; // esi@41
  TTextPanel **v23; // ebx@41
  signed int v24; // ebp@41
  signed int v25; // edi@44
  TribeAchievementsScreen *v26; // [sp+4Ch] [bp-10h]@1

  v1 = this;
  v26 = this;
  this->vfptr = (TPanelVtbl *)&TribeAchievementsScreen::`vftable';
  TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
  v2 = v1->win_decal;
  if( v2 )
  {
    TShape::~TShape(v1->win_decal);
    operator delete(v2);
  }
  v3 = v1->title;
  if( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->summary_text;
  if( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->time;
  if( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  v6 = v1->win_loss_text;
  if( v6 )
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  v7 = v1->instruction;
  if( v7 )
    ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
  v8 = v1->restartButton;
  if( v8 )
    (**(void (__stdcall ***)(_DWORD))v8)(1);
  v9 = v1->okButton;
  if( v9 )
    (**(void (__stdcall ***)(_DWORD))v9)(1);
  v10 = v1->backButton;
  if( v10 )
    (**(void (__stdcall ***)(_DWORD))v10)(1);
  v11 = v1->backButton2;
  if( v11 )
    (**(void (__stdcall ***)(_DWORD))v11)(1);
  v12 = v1->aftermathButton;
  if( v12 )
    (**(void (__stdcall ***)(_DWORD))v12)(1);
  v13 = v1->timelineButton;
  if( v13 )
    (**(void (__stdcall ***)(_DWORD))v13)(1);
  v14 = v1->time_line;
  if( v14 )
    ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
  v15 = v1->win_loss_text_bar;
  if( v15 )
    ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
  v16 = v1->summary_text_bar;
  if( v16 )
    ((void (__stdcall *)(_DWORD))v16->vfptr->__vecDelDtor)(1);
  v17 = v1->instruction_bar;
  if( v17 )
    ((void (__stdcall *)(_DWORD))v17->vfptr->__vecDelDtor)(1);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  v18 = v1->title_bar;
  v19 = 7;
  do
  {
    if( *v18 )
      ((void (__stdcall *)(_DWORD))(*v18)->vfptr->__vecDelDtor)(1);
    ++v18;
    --v19;
  }
  while( v19 );
  v20 = v1->achievement_choice;
  v21 = 5;
  do
  {
    if( *v20 )
      ((void (__stdcall *)(_DWORD))(*v20)->vfptr->__vecDelDtor)(1);
    ++v20;
    --v21;
  }
  while( v21 );
  v22 = v1->statistics;
  v23 = v1->player_names;
  v24 = 8;
  do
  {
    if( *v23 )
      ((void (__stdcall *)(_DWORD))(*v23)->vfptr->__vecDelDtor)(1);
    v25 = 7;
    do
    {
      if( (*v22)[0] )
        ((void (__stdcall *)(_DWORD))(*v22)[0]->vfptr->__vecDelDtor)(1);
      v22 = (TTextPanel *(*)[7])((char *)v22 + 4);
      --v25;
    }
    while( v25 );
    ++v23;
    --v24;
  }
  while( v24 );
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v26->vfptr);
}
// 572180: using guessed type int (__thiscall *TribeAchievementsScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (0048E400) --------------------------------------------------------
void __thiscall TribeAchievementsScreen::set_mode(TribeAchievementsScreen *this, int new_mode)
{
  TribeAchievementsScreen *v2; // ebx@1
  int v3; // esi@1
  int v4; // esi@1
  TTextPanel *v5; // ecx@1
  Time_Line_Panel *v6; // ecx@3
  TButtonPanel *v7; // ecx@3
  TButtonPanel *v8; // ecx@5
  TButtonPanel *v9; // ecx@7
  TButtonPanel *v10; // ecx@9
  TButtonPanel *v11; // ecx@11
  TButtonPanel *v12; // ecx@13
  TPanel *v13; // ecx@16
  TButtonPanel *v14; // ecx@16
  TButtonPanel *v15; // ecx@18
  TButtonPanel *v16; // ecx@20
  TButtonPanel *v17; // ecx@22
  TButtonPanel *v18; // ecx@24
  signed int v19; // ebp@27
  int v20; // edi@27
  RGE_Player *v21; // esi@28
  int v22; // eax@28
  int v23; // eax@28
  int v24; // eax@28
  int v25; // eax@28
  int v26; // eax@28
  int v27; // ecx@28
  int v28; // eax@31
  int v29; // ecx@31
  int v30; // eax@34
  TTextPanel *v31; // ecx@36
  signed int v32; // ebp@37
  int v33; // edi@37
  RGE_Player *v34; // esi@38
  int v35; // eax@38
  int v36; // eax@38
  int v37; // eax@38
  int v38; // eax@38
  int v39; // ecx@38
  int v40; // eax@41
  TTextPanel *v41; // ecx@43
  signed int v42; // ebp@44
  int v43; // esi@44
  RGE_Player *v44; // edi@45
  int v45; // eax@45
  int v46; // eax@45
  int v47; // eax@45
  int v48; // ecx@45
  int v49; // eax@48
  int v50; // eax@48
  int v51; // ecx@48
  int v52; // eax@51
  int v53; // eax@51
  TTextPanel *v54; // ecx@53
  int v55; // edi@54
  RGE_Player *v56; // esi@55
  int v57; // eax@55
  int v58; // eax@55
  int v59; // ecx@55
  int v60; // eax@58
  int v61; // eax@58
  int v62; // eax@58
  int v63; // ebp@58
  int v64; // eax@58
  int v65; // eax@58
  TTextPanel *v66; // ecx@60
  signed int v67; // ebp@61
  int v68; // esi@61
  RGE_Player *v69; // edi@62
  int v70; // eax@62
  int v71; // eax@62
  int v72; // ecx@62
  int v73; // eax@65
  int v74; // ecx@65
  int v75; // eax@68
  int v76; // ecx@68
  int v77; // eax@71
  Time_Line_Panel *v78; // ecx@73
  TTextPanel *v79; // ecx@74
  TTextPanel *v80; // ecx@74
  TButtonPanel *v81; // ecx@76
  TButtonPanel *v82; // ecx@78
  int v83; // esi@81
  signed int v84; // edi@81
  signed int v85; // esi@84
  int v86; // edi@84
  signed int v87; // edi@86
  int v88; // ebp@88
  int v89; // esi@88
  int player_num; // [sp+70h] [bp-3Ch]@1
  int v91; // [sp+74h] [bp-38h]@54
  char temptxt[50]; // [sp+78h] [bp-34h]@1
  int new_modea; // [sp+B0h] [bp+4h]@27
  int new_modeb; // [sp+B0h] [bp+4h]@37
  int new_modec; // [sp+B0h] [bp+4h]@44
  int new_moded; // [sp+B0h] [bp+4h]@54
  int new_modee; // [sp+B0h] [bp+4h]@61
  int new_modef; // [sp+B0h] [bp+4h]@86

  v2 = this;
  v3 = rge_base_game->world->player_num;
  *(_DWORD *)&temptxt[31] = 0;
  v4 = v3 - 1;
  *(_DWORD *)&temptxt[35] = 0;
  player_num = v4;
  *(_DWORD *)&temptxt[39] = 0;
  *(_DWORD *)&temptxt[43] = 0;
  *(_WORD *)&temptxt[47] = 0;
  temptxt[49] = 0;
  RGE_Base_Game::disable_input(rge_base_game);
  v5 = v2->win_loss_text;
  if( v5 )
    (*(void (__stdcall **)(_DWORD))&v5->vfptr->gap10[4])(0);
  v6 = v2->time_line;
  v2->current_mode = new_mode;
  (*(void (__stdcall **)(_DWORD))&v6->vfptr->gap10[4])(0);
  (*(void (__stdcall **)(_DWORD))&v2->instruction->vfptr->gap10[4])(0);
  (*(void (__stdcall **)(signed int))&v2->time->vfptr->gap10[4])(1);
  v7 = v2->restartButton;
  if( v7 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 20))(0);
  v8 = v2->okButton;
  if( v8 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 20))(0);
  v9 = v2->aftermathButton;
  if( v9 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 20))(0);
  v10 = v2->timelineButton;
  if( v10 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v10 + 20))(0);
  v11 = v2->backButton;
  if( v11 )
    (*(void (__stdcall **)(signed int))(*(_DWORD *)v11 + 20))(1);
  v12 = v2->backButton2;
  if( v12 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v12 + 20))(0);
  TPanel::set_curr_child((TPanel *)&v2->vfptr, (TPanel *)v2->backButton);
  switch ( new_mode )
  {
    case 0:
      v13 = (TPanel *)v2->okButton;
      v2->size = 7;
      TPanel::set_curr_child((TPanel *)&v2->vfptr, v13);
      v14 = v2->restartButton;
      if( v14 )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v14 + 20))(1);
      v15 = v2->okButton;
      if( v15 )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v15 + 20))(1);
      v16 = v2->aftermathButton;
      if( v16 )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v16 + 20))(1);
      v17 = v2->timelineButton;
      if( v17 )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v17 + 20))(1);
      v18 = v2->backButton;
      if( v18 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v18 + 20))(0);
      (*(void (__stdcall **)(signed int))&v2->instruction->vfptr->gap10[4])(1);
      (*(void (__stdcall **)(signed int))&v2->summary_text->vfptr[1].gap4[0])(9945);
      (*(void (__stdcall **)(signed int))&v2->title_bar[0]->vfptr[1].gap4[0])(9900);
      (*(void (__stdcall **)(signed int))&v2->title_bar[1]->vfptr[1].gap4[0])(9901);
      (*(void (__stdcall **)(signed int))&v2->title_bar[2]->vfptr[1].gap4[0])(9902);
      (*(void (__stdcall **)(signed int))&v2->title_bar[3]->vfptr[1].gap4[0])(9903);
      (*(void (__stdcall **)(signed int))&v2->title_bar[4]->vfptr[1].gap4[0])(9942);
      (*(void (__stdcall **)(signed int))&v2->title_bar[5]->vfptr[1].gap4[0])(9943);
      (*(void (__stdcall **)(signed int))&v2->title_bar[6]->vfptr[1].gap4[0])(9905);
      if( v4 > 0 )
      {
        v19 = 1;
        v20 = (int)&v2->statistics[0][1];
        new_modea = v4;
        do
        {
          v21 = rge_base_game->world->players[v19];
          v22 = RGE_Victory_Conditions::get_victory_points_group(v21->victory_conditions, 0);
          itoa(v22, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v20 - 4) + 232))(temptxt);
          v23 = RGE_Victory_Conditions::get_victory_points_group(v21->victory_conditions, 1);
          itoa(v23, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)v20 + 232))(temptxt);
          v24 = RGE_Victory_Conditions::get_victory_points_group(v21->victory_conditions, 2);
          itoa(v24, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v20 + 4) + 232))(temptxt);
          v25 = RGE_Victory_Conditions::get_victory_points_group(v21->victory_conditions, 3);
          itoa(v25, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v20 + 8) + 232))(temptxt);
          v26 = RGE_Victory_Conditions::get_victory_points_id(v21->victory_conditions, 22);
          v27 = *(_DWORD *)(v20 + 12);
          if( v26 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v27 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v27 + 228))(4003);
          v28 = RGE_Victory_Conditions::get_victory_points_id(v21->victory_conditions, 23);
          v29 = *(_DWORD *)(v20 + 16);
          if( v28 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v29 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v29 + 228))(4003);
          v30 = RGE_Victory_Conditions::get_victory_points(v21->victory_conditions);
          itoa(v30, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v20 + 20) + 232))(temptxt);
          ++v19;
          v20 += 28;
          --new_modea;
        }
        while( new_modea );
      }
      break;
    case 1:
      v31 = v2->summary_text;
      v2->size = 6;
      (*(void (__stdcall **)(signed int))&v31->vfptr[1].gap4[0])(9900);
      (*(void (__stdcall **)(signed int))&v2->title_bar[0]->vfptr[1].gap4[0])(9910);
      (*(void (__stdcall **)(signed int))&v2->title_bar[1]->vfptr[1].gap4[0])(9911);
      (*(void (__stdcall **)(signed int))&v2->title_bar[2]->vfptr[1].gap4[0])(9913);
      (*(void (__stdcall **)(signed int))&v2->title_bar[3]->vfptr[1].gap4[0])(9912);
      (*(void (__stdcall **)(signed int))&v2->title_bar[4]->vfptr[1].gap4[0])(9914);
      (*(void (__stdcall **)(signed int))&v2->title_bar[5]->vfptr[1].gap4[0])(9909);
      if( v4 > 0 )
      {
        v32 = 1;
        v33 = (int)&v2->statistics[0][1];
        new_modeb = v4;
        do
        {
          v34 = rge_base_game->world->players[v32];
          v35 = RGE_Victory_Conditions::get_attribute_id(v34->victory_conditions, 0);
          itoa(v35, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v33 - 4) + 232))(temptxt);
          v36 = RGE_Victory_Conditions::get_attribute_id(v34->victory_conditions, 1);
          itoa(v36, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)v33 + 232))(temptxt);
          itoa((signed __int64)(v34->attributes[19] - v34->attributes[11]), temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v33 + 4) + 232))(temptxt);
          v37 = RGE_Victory_Conditions::get_attribute_id(v34->victory_conditions, 2);
          itoa(v37, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v33 + 8) + 232))(temptxt);
          v38 = RGE_Victory_Conditions::get_victory_points_id(v34->victory_conditions, 3);
          v39 = *(_DWORD *)(v33 + 12);
          if( v38 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v39 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v39 + 228))(4003);
          v40 = RGE_Victory_Conditions::get_victory_points_group(v34->victory_conditions, 0);
          itoa(v40, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v33 + 16) + 232))(temptxt);
          ++v32;
          v33 += 28;
          --new_modeb;
        }
        while( new_modeb );
      }
      break;
    case 2:
      v41 = v2->summary_text;
      v2->size = 7;
      (*(void (__stdcall **)(signed int))&v41->vfptr[1].gap4[0])(9901);
      (*(void (__stdcall **)(signed int))&v2->title_bar[0]->vfptr[1].gap4[0])(9918);
      (*(void (__stdcall **)(signed int))&v2->title_bar[1]->vfptr[1].gap4[0])(9919);
      (*(void (__stdcall **)(signed int))&v2->title_bar[2]->vfptr[1].gap4[0])(9920);
      (*(void (__stdcall **)(signed int))&v2->title_bar[3]->vfptr[1].gap4[0])(9921);
      (*(void (__stdcall **)(signed int))&v2->title_bar[4]->vfptr[1].gap4[0])(9922);
      (*(void (__stdcall **)(signed int))&v2->title_bar[5]->vfptr[1].gap4[0])(9923);
      (*(void (__stdcall **)(signed int))&v2->title_bar[6]->vfptr[1].gap4[0])(9909);
      if( v4 > 0 )
      {
        v42 = 1;
        v43 = (int)&v2->statistics[0][2];
        new_modec = player_num;
        do
        {
          v44 = rge_base_game->world->players[v42];
          v45 = RGE_Victory_Conditions::get_attribute_id(v44->victory_conditions, 4);
          itoa(v45, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v43 - 8) + 232))(temptxt);
          v46 = RGE_Victory_Conditions::get_attribute_id(v44->victory_conditions, 5);
          itoa(v46, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v43 - 4) + 232))(temptxt);
          v47 = RGE_Victory_Conditions::get_victory_points_id(v44->victory_conditions, 6);
          v48 = *(_DWORD *)v43;
          if( v47 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v48 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v48 + 228))(4003);
          v49 = RGE_Victory_Conditions::get_attribute_id(v44->victory_conditions, 7);
          sprintf(temptxt, aD_2, v49);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v43 + 4) + 232))(temptxt);
          v50 = RGE_Victory_Conditions::get_victory_points_id(v44->victory_conditions, 8);
          v51 = *(_DWORD *)(v43 + 8);
          if( v50 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v51 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v51 + 228))(4003);
          v52 = RGE_Victory_Conditions::get_attribute_id(v44->victory_conditions, 9);
          itoa(v52, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v43 + 12) + 232))(temptxt);
          v53 = RGE_Victory_Conditions::get_victory_points_group(v44->victory_conditions, 1);
          itoa(v53, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v43 + 16) + 232))(temptxt);
          ++v42;
          v43 += 28;
          --new_modec;
        }
        while( new_modec );
      }
      break;
    case 3:
      v54 = v2->summary_text;
      v2->size = 7;
      (*(void (__stdcall **)(signed int))&v54->vfptr[1].gap4[0])(9902);
      (*(void (__stdcall **)(signed int))&v2->title_bar[0]->vfptr[1].gap4[0])(9926);
      (*(void (__stdcall **)(signed int))&v2->title_bar[1]->vfptr[1].gap4[0])(9927);
      (*(void (__stdcall **)(signed int))&v2->title_bar[2]->vfptr[1].gap4[0])(9928);
      (*(void (__stdcall **)(signed int))&v2->title_bar[3]->vfptr[1].gap4[0])(9929);
      (*(void (__stdcall **)(signed int))&v2->title_bar[4]->vfptr[1].gap4[0])(9930);
      (*(void (__stdcall **)(signed int))&v2->title_bar[5]->vfptr[1].gap4[0])(9948);
      (*(void (__stdcall **)(signed int))&v2->title_bar[6]->vfptr[1].gap4[0])(9909);
      if( v4 > 0 )
      {
        new_moded = 1;
        v55 = (int)&v2->statistics[0][1];
        v91 = v4;
        do
        {
          v56 = rge_base_game->world->players[new_moded];
          (*(void (__stdcall **)(_DWORD))&v2->time_line->vfptr->gap10[4])(0);
          v57 = RGE_Victory_Conditions::get_attribute_id(v56->victory_conditions, 10);
          itoa(v57, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v55 - 4) + 232))(temptxt);
          v58 = RGE_Victory_Conditions::get_victory_points_id(v56->victory_conditions, 11);
          v59 = *(_DWORD *)v55;
          if( v58 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v59 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v59 + 228))(4003);
          v60 = RGE_Victory_Conditions::get_attribute_id(v56->victory_conditions, 12);
          itoa(v60, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v55 + 4) + 232))(temptxt);
          v61 = RGE_Victory_Conditions::get_attribute_id(v56->victory_conditions, 13);
          itoa(v61, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v55 + 8) + 232))(temptxt);
          v62 = RGE_Victory_Conditions::get_attribute_id(v56->victory_conditions, 14);
          itoa(v62, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v55 + 12) + 232))(temptxt);
          v63 = RGE_Victory_Conditions::get_victory_points_id(v56->victory_conditions, 16);
          v64 = RGE_Victory_Conditions::get_victory_points_id(v56->victory_conditions, 15);
          itoa(v64 + v63, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v55 + 16) + 232))(temptxt);
          v65 = RGE_Victory_Conditions::get_victory_points_group(v56->victory_conditions, 2);
          itoa(v65, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v55 + 20) + 232))(temptxt);
          v55 += 28;
          ++new_moded;
          --v91;
        }
        while( v91 );
      }
      break;
    case 4:
      v66 = v2->summary_text;
      v2->size = 5;
      (*(void (__stdcall **)(signed int))&v66->vfptr[1].gap4[0])(9903);
      (*(void (__stdcall **)(signed int))&v2->title_bar[0]->vfptr[1].gap4[0])(9934);
      (*(void (__stdcall **)(signed int))&v2->title_bar[1]->vfptr[1].gap4[0])(9937);
      (*(void (__stdcall **)(signed int))&v2->title_bar[2]->vfptr[1].gap4[0])(9935);
      (*(void (__stdcall **)(signed int))&v2->title_bar[3]->vfptr[1].gap4[0])(9936);
      (*(void (__stdcall **)(signed int))&v2->title_bar[4]->vfptr[1].gap4[0])(9909);
      if( v4 > 0 )
      {
        v67 = 1;
        v68 = (int)&v2->statistics[0][1];
        new_modee = player_num;
        do
        {
          v69 = rge_base_game->world->players[v67];
          v70 = RGE_Victory_Conditions::get_attribute_id(v69->victory_conditions, 17);
          itoa(v70, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v68 - 4) + 232))(temptxt);
          v71 = RGE_Victory_Conditions::get_victory_points_id(v69->victory_conditions, 18);
          v72 = *(_DWORD *)v68;
          if( v71 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v72 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v72 + 228))(4003);
          v73 = RGE_Victory_Conditions::get_victory_points_id(v69->victory_conditions, 19);
          v74 = *(_DWORD *)(v68 + 4);
          if( v73 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v74 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v74 + 228))(4003);
          v75 = RGE_Victory_Conditions::get_victory_points_id(v69->victory_conditions, 20);
          v76 = *(_DWORD *)(v68 + 8);
          if( v75 <= 0 )
            (*(void (__stdcall **)(char *))(*(_DWORD *)v76 + 232))(message_in);
          else
            (*(void (__stdcall **)(signed int))(*(_DWORD *)v76 + 228))(4003);
          v77 = RGE_Victory_Conditions::get_victory_points_group(v69->victory_conditions, 3);
          itoa(v77, temptxt, 10);
          (*(void (__stdcall **)(char *))(**(_DWORD **)(v68 + 12) + 232))(temptxt);
          ++v67;
          v68 += 28;
          --new_modee;
        }
        while( new_modee );
      }
      break;
    case 6:
      v78 = v2->time_line;
      v2->size = 0;
      (*(void (__stdcall **)(signed int))&v78->vfptr->gap10[4])(1);
      (*(void (__stdcall **)(signed int))&v2->summary_text->vfptr[1].gap4[0])(9944);
      (*(void (__stdcall **)(signed int))&v2->time->vfptr->gap10[4])(1);
      break;
    case 5:
      v79 = v2->summary_text;
      v2->size = 0;
      (*(void (__stdcall **)(signed int))&v79->vfptr[1].gap4[0])(9906);
      v80 = v2->win_loss_text;
      if( v80 )
        (*(void (__stdcall **)(signed int))&v80->vfptr->gap10[4])(1);
      (*(void (__stdcall **)(_DWORD))&v2->time->vfptr->gap10[4])(0);
      v81 = v2->backButton;
      if( v81 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v81 + 20))(0);
      v82 = v2->backButton2;
      if( v82 )
      {
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v82 + 20))(1);
        TPanel::set_curr_child((TPanel *)&v2->vfptr, (TPanel *)v2->backButton2);
      }
      break;
    default:
      break;
  }
  if( v2->size )
  {
    v85 = 0;
    v86 = (int)v2->player_names;
    do
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v86 + 20))(v85++ < player_num);
      v86 += 4;
    }
    while( v85 < 8 );
  }
  else
  {
    v83 = (int)v2->player_names;
    v84 = 8;
    do
    {
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v83 + 20))(0);
      v83 += 4;
      --v84;
    }
    while( v84 );
  }
  v87 = 0;
  new_modef = (int)v2->title_bar;
  do
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)new_modef + 20))(v87 < v2->size);
    if( player_num > 0 )
    {
      v88 = player_num;
      v89 = new_modef + 48;
      do
      {
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v89 + 20))(v87 < v2->size);
        v89 += 28;
        --v88;
      }
      while( v88 );
    }
    ++v87;
    new_modef += 4;
  }
  while( v87 < 7 );
}

//----- (0048F0B0) --------------------------------------------------------
void __thiscall TribeAchievementsScreen::draw(TribeAchievementsScreen *this)
{
  TribeAchievementsScreen *v1; // edi@1
  TPanelVtbl *v2; // esi@2
  RGE_Game_World *v3; // ebx@4
  TPanel **v4; // esi@5
  int v5; // ST08_4@7
  int v6; // eax@7
  int v7; // [sp+4h] [bp-8h]@5
  TPanelVtbl *v8; // [sp+8h] [bp-4h]@2

  v1 = this;
  TScreenPanel::draw((TScreenPanel *)&this->vfptr);
  if( v1->current_mode < 5 )
  {
    v2 = v1->vfptr;
    v8 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    if( v1->win_decal && TDrawArea::Lock(v1->render_area, aScr_achDraw, 1) )
    {
      v3 = rge_base_game->world;
      if( v3->player_num - 1 > 0 )
      {
        v4 = (TPanel **)v1->player_names;
        v7 = v3->player_num - 1;
        do
        {
          if( (*(RGE_Player **)((char *)v3->players + -1444 - (_DWORD)v1 + (unsigned int)v4))->game_status == 1 )
          {
            v5 = TPanel::yPosition(*v4);
            v6 = TPanel::xPosition(*v4);
            TShape::shape_draw(v1->win_decal, v1->render_area, v6 - 20, v5, 0, 0, 0);
          }
          ++v4;
          --v7;
        }
        while( v7 );
        v2 = v8;
      }
      TDrawArea::Unlock(v1->render_area, aScr_achDraw);
    }
    v2->draw_finish((TPanel *)v1);
  }
}

//----- (0048F190) --------------------------------------------------------
int __thiscall TribeAchievementsScreen::handle_mouse_down(TribeAchievementsScreen *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TribeAchievementsScreen *v6; // esi@1
  int v7; // ebp@1

  v6 = this;
  v7 = TEasy_Panel::handle_mouse_down((TEasy_Panel *)&this->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
  if( !v6->current_mode )
  {
    if( ((int (__stdcall *)(int, int))v6->achievement_choice[0]->vfptr->is_inside)(x, y) )
    {
      TribeAchievementsScreen::set_mode(v6, 1);
      return v7;
    }
    if( ((int (__stdcall *)(int, int))v6->achievement_choice[1]->vfptr->is_inside)(x, y) )
    {
      TribeAchievementsScreen::set_mode(v6, 2);
      return v7;
    }
    if( ((int (__stdcall *)(int, int))v6->achievement_choice[2]->vfptr->is_inside)(x, y) )
    {
      TribeAchievementsScreen::set_mode(v6, 3);
      return v7;
    }
    if( ((int (__stdcall *)(int, int))v6->achievement_choice[3]->vfptr->is_inside)(x, y) )
    {
      if( !((int (__stdcall *)(int, int))v6->achievement_choice[4]->vfptr->is_inside)(x, y) )
        TribeAchievementsScreen::set_mode(v6, 4);
    }
  }
  return v7;
}

//----- (0048F280) --------------------------------------------------------
int __thiscall TribeAchievementsScreen::action(TribeAchievementsScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeAchievementsScreen *v5; // edi@1
  TButtonPanel *v7; // ecx@15
  TButtonPanel *v8; // ecx@17
  TButtonPanel *v9; // ecx@19
  TButtonPanel *v10; // ecx@21
  TButtonPanel *v11; // ecx@23
  TButtonPanel *v12; // ecx@27
  TButtonPanel *v13; // ecx@29
  TButtonPanel *v14; // ecx@31
  TButtonPanel *v15; // ecx@33
  TButtonPanel *v16; // ecx@35

  v5 = this;
  if( fromPanel != (TPanel *)this->okButton || actionIn != 1 )
  {
    if( fromPanel == (TPanel *)this->restartButton && actionIn == 1 )
    {
      TRIBE_Game::restart_game((TRIBE_Game *)rge_base_game);
      return 1;
    }
    if( fromPanel != (TPanel *)this->timelineButton || actionIn != 1 )
    {
      if( fromPanel != (TPanel *)this->aftermathButton || actionIn != 1 )
      {
        if( (fromPanel == (TPanel *)this->backButton || fromPanel == (TPanel *)this->backButton2) && actionIn == 1 )
        {
          TribeAchievementsScreen::set_mode(this, 0);
          return 1;
        }
        if( fromPanel == (TPanel *)this->close_button && actionIn == 1 )
        {
          RGE_Base_Game::close(rge_base_game);
          return 1;
        }
        if( !TPanel::panelName(fromPanel) || strcmp(TPanel::panelName(fromPanel), aYesnodialog) )
          return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
        TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
        if( !actionIn )
        {
          RGE_Base_Game::close(rge_base_game);
          return 1;
        }
        confirmed_close = 0;
      }
      else
      {
        TribeAchievementsScreen::set_mode(this, 5);
        v12 = v5->restartButton;
        if( v12 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v12 + 20))(0);
        v13 = v5->okButton;
        if( v13 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 20))(0);
        v14 = v5->aftermathButton;
        if( v14 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14 + 20))(0);
        v15 = v5->timelineButton;
        if( v15 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v15 + 20))(0);
        v16 = v5->backButton;
        if( v16 )
        {
          (*(void (__stdcall **)(signed int))(*(_DWORD *)v16 + 20))(1);
          return 1;
        }
      }
    }
    else
    {
      TribeAchievementsScreen::set_mode(this, 6);
      v7 = v5->restartButton;
      if( v7 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 20))(0);
      v8 = v5->okButton;
      if( v8 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 20))(0);
      v9 = v5->aftermathButton;
      if( v9 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 20))(0);
      v10 = v5->timelineButton;
      if( v10 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v10 + 20))(0);
      v11 = v5->backButton;
      if( v11 )
      {
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v11 + 20))(1);
        return 1;
      }
    }
    return 1;
  }
  if( this->end_game_flag )
  {
    TRIBE_Game::quit_game((TRIBE_Game *)rge_base_game);
  }
  else
  {
    if( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
      RGE_Base_Game::set_paused(rge_base_game, 0, 0);
    TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
  }
  TPanelSystem::destroyPanel(&panel_system, aAchievementsSc);
  return 1;
}
// 86BACC: using guessed type int confirmed_close;

//----- (0048F500) --------------------------------------------------------
int __thiscall TribeAchievementsScreen::handle_idle(TribeAchievementsScreen *this)
{
  TribeAchievementsScreen *v1; // esi@1

  v1 = this;
  if( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (0048F530) --------------------------------------------------------
int __thiscall TribeAchievementsScreen::wnd_proc(TribeAchievementsScreen *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
  TribeAchievementsScreen *v5; // esi@1
  int v6; // eax@3
  char *v7; // eax@8
  int result; // eax@8

  v5 = this;
  if( msg != 16
    || confirmed_close
    || (confirmed_close = 1, v6 = rge_base_game->prog_mode, v6 != 5) && v6 != 4 && v6 != 6 && v6 != 7
    || IsIconic(this->render_area->Wnd) )
  {
    result = TPanel::wnd_proc((TPanel *)&v5->vfptr, hwnd, msg, wParam, lParam);
  }
  else
  {
    v7 = TPanel::get_string(3101);
    TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v5->vfptr, v7, 0, 450, 100);
    result = 1;
  }
  return result;
}
// 86BACC: using guessed type int confirmed_close;
