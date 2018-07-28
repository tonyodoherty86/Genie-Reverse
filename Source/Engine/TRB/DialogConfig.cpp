
//----- (0043B560) --------------------------------------------------------
void __thiscall TribeConfigDialog::TribeConfigDialog(TribeConfigDialog *this, TribeConfigDialog::Mode m, TScreenPanel *parentPanel)
{
  TribeConfigDialog *v3; // esi@1
  int v4; // edx@1
  int v5; // eax@1
  int v6; // eax@1
  int v7; // eax@1
  int v8; // eax@1
  int v9; // eax@1
  int v10; // eax@1
  int v11; // eax@1
  int v12; // eax@1
  int v13; // eax@1
  int v14; // eax@1
  int v15; // ST24_4@1
  char *v16; // ST20_4@1
  TDrawArea *v17; // eax@1
  signed int v18; // edi@4
  int v19; // ecx@8
  signed int v20; // ebp@14
  TButtonPanel **v21; // edi@14
  TButtonPanel **v22; // edi@17
  signed int v23; // ebx@17
  RGE_Game_World *v24; // ecx@19
  double v25; // st7@19
  char v27; // c3@19
  TButtonPanel *v28; // ecx@20
  TMusic_System *v29; // eax@30
  TSound_Driver *v30; // ecx@37
  TScrollBarPanel *v31; // ecx@44
  unsigned int v32; // eax@44
  int v33; // ebp@45
  signed int v34; // edi@45
  TButtonPanel **v35; // ebx@55
  signed int v36; // ebp@55
  TButtonPanel **v37; // edi@55
  int v38; // eax@57
  TButtonPanel *v39; // ecx@60
  int v40; // edi@71
  signed int v41; // ebp@78
  TButtonPanel **v42; // edi@78
  TButtonPanel *v43; // ecx@81
  int v44; // edi@84
  signed int v45; // ebp@91
  TButtonPanel **v46; // edi@91
  TButtonPanel *v47; // ecx@94
  int v48; // ebp@97
  int v49; // edi@97
  TButtonPanel **v50; // ebx@97
  TButtonPanel **v51; // edi@103
  signed int v52; // ebx@103
  char v53; // al@106
  TPanel **v54; // ebx@110
  TPanel **v55; // edi@111
  TPanel *v56; // eax@112
  TPanel *v57; // edx@112
  TPanel *tabList[10]; // [sp+14h] [bp-34h]@112
  int v59; // [sp+44h] [bp-4h]@1
  TribeConfigDialog::Mode ma; // [sp+4Ch] [bp+4h]@11

  v3 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aConfigDialog);
  v4 = (int)v3->speedTitle;
  v3->modeValue = m;
  v3->vfptr = (TPanelVtbl *)&TribeConfigDialog::`vftable';
  v3->title = 0;
  *(_DWORD *)v4 = 0;
  v5 = (int)v3->speedButton;
  *(_DWORD *)(v4 + 4) = 0;
  v59 = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  v6 = (int)v3->musicTitle;
  v3->musicTitle[0] = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  v7 = (int)v3->soundTitle;
  v3->musicSlider = 0;
  *(_DWORD *)v7 = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  v8 = (int)v3->scrollSpeedTitle;
  v3->soundSlider = 0;
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 4) = 0;
  *(_DWORD *)(v8 + 8) = 0;
  v9 = (int)v3->sizeTitle;
  v3->scrollSpeedSlider = 0;
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = 0;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 12) = 0;
  v10 = (int)v3->sizeButton;
  v3->sizeButton[0] = 0;
  *(_DWORD *)(v10 + 4) = 0;
  *(_DWORD *)(v10 + 8) = 0;
  v11 = (int)v3->mouseTitle;
  v3->mouseTitle[0] = 0;
  *(_DWORD *)(v11 + 4) = 0;
  *(_DWORD *)(v11 + 8) = 0;
  v3->mouseButton[0] = 0;
  v3->mouseButton[1] = 0;
  v12 = (int)v3->rolloverTitle;
  v3->rolloverTitle[0] = 0;
  *(_DWORD *)(v12 + 4) = 0;
  *(_DWORD *)(v12 + 8) = 0;
  v3->rolloverButton[0] = 0;
  v3->rolloverButton[1] = 0;
  v13 = (int)v3->pathFindingTitle;
  v3->pathFindingTitle[0] = 0;
  *(_DWORD *)(v13 + 4) = 0;
  *(_DWORD *)(v13 + 8) = 0;
  *(_DWORD *)(v13 + 12) = 0;
  v14 = (int)v3->pathFindingButton;
  *(_DWORD *)v14 = 0;
  *(_DWORD *)(v14 + 4) = 0;
  *(_DWORD *)(v14 + 8) = 0;
  v3->okButton = 0;
  v3->cancelButton = 0;
  v15 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parentPanel->vfptr);
  v16 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parentPanel->vfptr);
  v17 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
  if ( !TDialogPanel::setup((TDialogPanel *)&v3->vfptr, v17, (TPanel *)&parentPanel->vfptr, 600, 390, v16, v15, 1)
    || !TEasy_Panel::create_text(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          &v3->title,
          9431,
          103,
          10,
          395,
          30,
          1,
          1,
          1,
          0)
    || !TEasy_Panel::create_text(
          (TEasy_Panel *)&v3->vfptr,
          (TPanel *)&v3->vfptr,
          v3->speedTitle,
          9439,
          20,
          50,
          110,
          30,
          11,
          0,
          1,
          0) )
  {
    return;
  }
  v18 = 0;
  do
  {
    if ( !v18 )
    {
LABEL_10:
      v19 = 9432;
      goto LABEL_11;
    }
    if ( v18 == 1 )
    {
      v19 = 9433;
    }
    else
    {
      if ( v18 != 2 )
        goto LABEL_10;
      v19 = 9434;
    }
LABEL_11:
    ma = v19;
    if ( !TEasy_Panel::create_text(
            (TEasy_Panel *)&v3->vfptr,
            (TPanel *)&v3->vfptr,
            &v3->speedTitle[v18 + 1],
            v19,
            55,
            35 * v18 + 85,
            110,
            30,
            11,
            0,
            1,
            0)
      || !TEasy_Panel::create_radio_button(
            (TEasy_Panel *)&v3->vfptr,
            (TPanel *)&v3->vfptr,
            &v3->speedButton[v18],
            20,
            35 * v18 + 85,
            30,
            30,
            0,
            0) )
    {
      return;
    }
    ++v18;
  }
  while ( v18 < 3 );
  v20 = 3;
  v21 = v3->speedButton;
  do
  {
    TButtonPanel::set_radio_info(*v21, v3->speedButton, 3);
    ++v21;
    --v20;
  }
  while ( v20 );
  if ( rge_base_game->prog_mode == 5 )
  {
    v22 = v3->speedButton;
    v23 = 3;
    do
    {
      TButtonPanel::set_disabled(*v22, 1);
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  v24 = rge_base_game->world;
  v25 = v24->game_speed;
  v3->gameSpeed = v24->game_speed;
  if ( v27 )
  {
    v28 = v3->speedButton[2];
    goto LABEL_25;
  }
  if ( v25 == 1.5 )
  {
    v28 = v3->speedButton[1];
    goto LABEL_25;
  }
  if ( v25 == 1.0 )
  {
    v28 = v3->speedButton[0];
LABEL_25:
    TButtonPanel::set_radio_button(v28);
  }
  if ( TEasy_Panel::create_text(
         (TEasy_Panel *)&v3->vfptr,
         (TPanel *)&v3->vfptr,
         v3->musicTitle,
         9435,
         165,
         45,
         110,
         40,
         11,
         0,
         1,
         1)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v3->vfptr,
         (TPanel *)&v3->vfptr,
         &v3->musicTitle[1],
         9436,
         190,
         85,
         110,
         20,
         11,
         0,
         1,
         0)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v3->vfptr,
         (TPanel *)&v3->vfptr,
         &v3->musicTitle[2],
         9437,
         190,
         165,
         110,
         20,
         11,
         0,
         1,
         0)
    && TEasy_Panel::create_vert_slider(
         (TEasy_Panel *)&v3->vfptr,
         (TPanel *)&v3->vfptr,
         &v3->musicSlider,
         100,
         10,
         20,
         170,
         85,
         20,
         100) )
  {
    v29 = rge_base_game->music_system;
    v3->musicVolume = v29 ? v29->volume / -100 : 99;
    TScrollBarPanel::set_tab_pos((TScrollBarPanel *)&v3->musicSlider->vfptr, v3->musicVolume);
    v3->newMusicVolume = v3->musicVolume;
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v3->vfptr,
           (TPanel *)&v3->vfptr,
           v3->soundTitle,
           9438,
           305,
           45,
           110,
           40,
           11,
           0,
           1,
           1) )
    {
      if ( TEasy_Panel::create_text(
             (TEasy_Panel *)&v3->vfptr,
             (TPanel *)&v3->vfptr,
             &v3->soundTitle[1],
             9436,
             330,
             85,
             110,
             20,
             11,
             0,
             1,
             0)
        && TEasy_Panel::create_text(
             (TEasy_Panel *)&v3->vfptr,
             (TPanel *)&v3->vfptr,
             &v3->soundTitle[2],
             9437,
             330,
             165,
             110,
             20,
             11,
             0,
             1,
             0)
        && TEasy_Panel::create_vert_slider(
             (TEasy_Panel *)&v3->vfptr,
             (TPanel *)&v3->vfptr,
             &v3->soundSlider,
             100,
             10,
             20,
             310,
             85,
             20,
             100) )
      {
        v30 = rge_base_game->sound_system;
        v3->soundVolume = v30 ? TSound_Driver::get_volume(v30) / -100 : 99;
        TScrollBarPanel::set_tab_pos((TScrollBarPanel *)&v3->soundSlider->vfptr, v3->soundVolume);
        v3->newSoundVolume = v3->soundVolume;
        if ( TEasy_Panel::create_text(
               (TEasy_Panel *)&v3->vfptr,
               (TPanel *)&v3->vfptr,
               v3->scrollSpeedTitle,
               9456,
               445,
               45,
               110,
               40,
               11,
               0,
               1,
               1) )
        {
          if ( TEasy_Panel::create_text(
                 (TEasy_Panel *)&v3->vfptr,
                 (TPanel *)&v3->vfptr,
                 &v3->scrollSpeedTitle[1],
                 9457,
                 470,
                 85,
                 110,
                 20,
                 11,
                 0,
                 1,
                 0) )
          {
            if ( TEasy_Panel::create_text(
                   (TEasy_Panel *)&v3->vfptr,
                   (TPanel *)&v3->vfptr,
                   &v3->scrollSpeedTitle[2],
                   9458,
                   470,
                   165,
                   110,
                   20,
                   11,
                   0,
                   1,
                   0) )
            {
              if ( TEasy_Panel::create_vert_slider(
                     (TEasy_Panel *)&v3->vfptr,
                     (TPanel *)&v3->vfptr,
                     &v3->scrollSpeedSlider,
                     100,
                     10,
                     20,
                     450,
                     85,
                     20,
                     100) )
              {
                v31 = (TScrollBarPanel *)&v3->scrollSpeedSlider->vfptr;
                v32 = rge_base_game->prog_info->mouse_scroll_interval;
                v3->scrollSpeed = v32;
                TScrollBarPanel::set_tab_pos(v31, v32 - 10);
                if ( TEasy_Panel::create_text(
                       (TEasy_Panel *)&v3->vfptr,
                       (TPanel *)&v3->vfptr,
                       v3->sizeTitle,
                       9440,
                       20,
                       190,
                       200,
                       30,
                       11,
                       0,
                       1,
                       0) )
                {
                  v33 = ma;
                  v34 = 0;
                  do
                  {
                    if ( v34 )
                    {
                      if ( v34 == 1 )
                      {
                        v33 = 9448;
                      }
                      else if ( v34 == 2 )
                      {
                        v33 = 9449;
                      }
                    }
                    else
                    {
                      v33 = 9447;
                    }
                    if ( !TEasy_Panel::create_text(
                            (TEasy_Panel *)&v3->vfptr,
                            (TPanel *)&v3->vfptr,
                            &v3->sizeTitle[v34 + 1],
                            v33,
                            55,
                            35 * v34 + 225,
                            100,
                            30,
                            11,
                            0,
                            1,
                            0)
                      || !TEasy_Panel::create_radio_button(
                            (TEasy_Panel *)&v3->vfptr,
                            (TPanel *)&v3->vfptr,
                            &v3->sizeButton[v34],
                            20,
                            35 * v34 + 225,
                            30,
                            30,
                            0,
                            0) )
                    {
                      return;
                    }
                    ++v34;
                  }
                  while ( v34 < 3 );
                  v35 = v3->sizeButton;
                  v36 = 3;
                  v37 = v3->sizeButton;
                  do
                  {
                    TButtonPanel::set_radio_info(*v37, v3->sizeButton, 3);
                    ++v37;
                    --v36;
                  }
                  while ( v36 );
                  v38 = v3->render_area->DrawSystem->ScreenWidth;
                  if ( v38 == 640 )
                  {
                    v39 = *v35;
                  }
                  else
                  {
                    if ( v38 != 800 )
                    {
                      if ( v38 == 1024 )
                      {
                        v39 = v3->sizeButton[2];
                        goto LABEL_63;
                      }
LABEL_64:
                      if ( !TDrawSystem::IsModeAvail(v3->render_area->DrawSystem, 640, 0, 8) )
                        TButtonPanel::set_disabled(*v35, 1);
                      if ( !TDrawSystem::IsModeAvail(v3->render_area->DrawSystem, 800, 0, 8) )
                        TButtonPanel::set_disabled(v3->sizeButton[1], 1);
                      if ( !TDrawSystem::IsModeAvail(v3->render_area->DrawSystem, 1024, 0, 8) )
                        TButtonPanel::set_disabled(v3->sizeButton[2], 1);
                      if ( TEasy_Panel::create_text(
                             (TEasy_Panel *)&v3->vfptr,
                             (TPanel *)&v3->vfptr,
                             v3->mouseTitle,
                             9450,
                             170,
                             190,
                             210,
                             30,
                             11,
                             0,
                             1,
                             0) )
                      {
                        v40 = 0;
                        while ( 1 )
                        {
                          if ( v40 )
                          {
                            if ( !TEasy_Panel::create_text(
                                    (TEasy_Panel *)&v3->vfptr,
                                    (TPanel *)&v3->vfptr,
                                    &v3->mouseTitle[v40 + 1],
                                    9452,
                                    205,
                                    35 * v40 + 225,
                                    120,
                                    30,
                                    11,
                                    0,
                                    1,
                                    0) )
                              return;
                          }
                          else if ( !TEasy_Panel::create_text(
                                       (TEasy_Panel *)&v3->vfptr,
                                       (TPanel *)&v3->vfptr,
                                       &v3->mouseTitle[1],
                                       9451,
                                       205,
                                       225,
                                       120,
                                       30,
                                       11,
                                       0,
                                       1,
                                       0) )
                          {
                            return;
                          }
                          if ( !TEasy_Panel::create_radio_button(
                                  (TEasy_Panel *)&v3->vfptr,
                                  (TPanel *)&v3->vfptr,
                                  &v3->mouseButton[v40],
                                  170,
                                  35 * v40 + 225,
                                  30,
                                  30,
                                  0,
                                  0) )
                            break;
                          if ( ++v40 >= 2 )
                          {
                            v41 = 2;
                            v42 = v3->mouseButton;
                            do
                            {
                              TButtonPanel::set_radio_info(*v42, v3->mouseButton, 2);
                              ++v42;
                              --v41;
                            }
                            while ( v41 );
                            if ( rge_base_game->prog_info->interface_style == 2 )
                              v43 = v3->mouseButton[0];
                            else
                              v43 = v3->mouseButton[1];
                            TButtonPanel::set_radio_button(v43);
                            if ( TEasy_Panel::create_text(
                                   (TEasy_Panel *)&v3->vfptr,
                                   (TPanel *)&v3->vfptr,
                                   v3->rolloverTitle,
                                   9453,
                                   330,
                                   190,
                                   210,
                                   30,
                                   11,
                                   0,
                                   1,
                                   0) )
                            {
                              v44 = 0;
                              while ( 1 )
                              {
                                if ( v44 )
                                {
                                  if ( !TEasy_Panel::create_text(
                                          (TEasy_Panel *)&v3->vfptr,
                                          (TPanel *)&v3->vfptr,
                                          &v3->rolloverTitle[v44 + 1],
                                          9455,
                                          365,
                                          35 * v44 + 225,
                                          120,
                                          30,
                                          11,
                                          0,
                                          1,
                                          0) )
                                    return;
                                }
                                else if ( !TEasy_Panel::create_text(
                                             (TEasy_Panel *)&v3->vfptr,
                                             (TPanel *)&v3->vfptr,
                                             &v3->rolloverTitle[1],
                                             9454,
                                             365,
                                             225,
                                             120,
                                             30,
                                             11,
                                             0,
                                             1,
                                             0) )
                                {
                                  return;
                                }
                                if ( !TEasy_Panel::create_radio_button(
                                        (TEasy_Panel *)&v3->vfptr,
                                        (TPanel *)&v3->vfptr,
                                        &v3->rolloverButton[v44],
                                        330,
                                        35 * v44 + 225,
                                        30,
                                        30,
                                        0,
                                        0) )
                                  break;
                                if ( ++v44 >= 2 )
                                {
                                  v45 = 2;
                                  v46 = v3->rolloverButton;
                                  do
                                  {
                                    TButtonPanel::set_radio_info(*v46, v3->rolloverButton, 2);
                                    ++v46;
                                    --v45;
                                  }
                                  while ( v45 );
                                  if ( rge_base_game->rollover )
                                    v47 = v3->rolloverButton[0];
                                  else
                                    v47 = v3->rolloverButton[1];
                                  TButtonPanel::set_radio_button(v47);
                                  if ( TEasy_Panel::create_text(
                                         (TEasy_Panel *)&v3->vfptr,
                                         (TPanel *)&v3->vfptr,
                                         v3->pathFindingTitle,
                                         9741,
                                         460,
                                         190,
                                         210,
                                         30,
                                         11,
                                         0,
                                         1,
                                         0) )
                                  {
                                    v48 = 0;
                                    v49 = 225;
                                    v50 = v3->pathFindingButton;
                                    while ( TEasy_Panel::create_text(
                                              (TEasy_Panel *)&v3->vfptr,
                                              (TPanel *)&v3->vfptr,
                                              (TTextPanel **)v50 - 3,
                                              v48 + 9742,
                                              495,
                                              v49,
                                              120,
                                              30,
                                              11,
                                              0,
                                              1,
                                              0)
                                         && TEasy_Panel::create_radio_button(
                                              (TEasy_Panel *)&v3->vfptr,
                                              (TPanel *)&v3->vfptr,
                                              v50,
                                              460,
                                              v49,
                                              30,
                                              30,
                                              0,
                                              0) )
                                    {
                                      if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                        TButtonPanel::set_disabled(*v50, 1);
                                      v49 += 35;
                                      ++v48;
                                      ++v50;
                                      if ( v49 >= 330 )
                                      {
                                        v51 = v3->pathFindingButton;
                                        v52 = 3;
                                        do
                                        {
                                          TButtonPanel::set_radio_info(*v51, v3->pathFindingButton, 3);
                                          ++v51;
                                          --v52;
                                        }
                                        while ( v52 );
                                        if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
                                          v53 = RGE_Base_Game::mpPathFinding(rge_base_game);
                                        else
                                          v53 = RGE_Base_Game::pathFinding(rge_base_game);
                                        if ( (unsigned __int8)v53 <= 2u )
                                          TButtonPanel::set_radio_button(v3->pathFindingButton[(unsigned __int8)v53]);
                                        v54 = (TPanel **)&v3->okButton;
                                        if ( TEasy_Panel::create_button(
                                               (TEasy_Panel *)&v3->vfptr,
                                               (TPanel *)&v3->vfptr,
                                               &v3->okButton,
                                               4001,
                                               0,
                                               120,
                                               345,
                                               170,
                                               30,
                                               0,
                                               0,
                                               0) )
                                        {
                                          v55 = (TPanel **)&v3->cancelButton;
                                          if ( TEasy_Panel::create_button(
                                                 (TEasy_Panel *)&v3->vfptr,
                                                 (TPanel *)&v3->vfptr,
                                                 &v3->cancelButton,
                                                 4002,
                                                 0,
                                                 310,
                                                 345,
                                                 170,
                                                 30,
                                                 0,
                                                 0,
                                                 0) )
                                          {
                                            v56 = *v55;
                                            v56[2].max_wid = 27;
                                            v56[2].min_hgt = 0;
                                            TPanel::set_curr_child((TPanel *)&v3->vfptr, *v54);
                                            v57 = *v55;
                                            tabList[0] = *v54;
                                            tabList[1] = v57;
                                            TPanel::set_tab_order(tabList, 2);
                                          }
                                        }
                                        return;
                                      }
                                    }
                                  }
                                  return;
                                }
                              }
                            }
                            return;
                          }
                        }
                      }
                      return;
                    }
                    v39 = v3->sizeButton[1];
                  }
LABEL_63:
                  TButtonPanel::set_radio_button(v39);
                  goto LABEL_64;
                }
              }
            }
          }
        }
      }
    }
  }
}
// 56F750: using guessed type int (__thiscall *TribeConfigDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043C0A0) --------------------------------------------------------
TribeConfigDialog *__thiscall TribeConfigDialog::`vector deleting destructor'(TribeConfigDialog *this, unsigned int __flags)
{
  TribeConfigDialog *v2; // esi@1

  v2 = this;
  TribeConfigDialog::~TribeConfigDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043C0C0) --------------------------------------------------------
void __thiscall TribeConfigDialog::~TribeConfigDialog(TribeConfigDialog *this)
{
  TribeConfigDialog *v1; // esi@1
  TPanel **v2; // edi@1
  signed int v3; // ebx@1
  TPanel **v4; // edi@3
  signed int v5; // ebx@3
  TPanel **v6; // edi@5
  signed int v7; // ebx@5
  TPanel **v8; // edi@7
  signed int v9; // ebx@7
  TPanel **v10; // edi@9
  signed int v11; // ebx@9
  TPanel **v12; // edi@11
  signed int v13; // ebx@11
  TPanel **v14; // edi@13
  signed int v15; // ebx@13
  TPanel **v16; // edi@15
  signed int v17; // ebx@15
  TPanel **v18; // edi@17
  signed int v19; // ebx@17
  TPanel **v20; // edi@19
  signed int v21; // ebx@19
  TPanel **v22; // edi@21
  signed int v23; // ebx@21
  TPanel **v24; // edi@23
  signed int v25; // ebx@23
  TPanel **v26; // edi@25
  signed int v27; // ebx@25

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeConfigDialog::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  v2 = (TPanel **)v1->speedTitle;
  v3 = 4;
  do
  {
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = (TPanel **)v1->speedButton;
  v5 = 3;
  do
  {
    TPanel::delete_panel(v4);
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = (TPanel **)v1->musicTitle;
  v7 = 3;
  do
  {
    TPanel::delete_panel(v6);
    ++v6;
    --v7;
  }
  while ( v7 );
  TPanel::delete_panel((TPanel **)&v1->musicSlider);
  v8 = (TPanel **)v1->soundTitle;
  v9 = 3;
  do
  {
    TPanel::delete_panel(v8);
    ++v8;
    --v9;
  }
  while ( v9 );
  TPanel::delete_panel((TPanel **)&v1->soundSlider);
  v10 = (TPanel **)v1->scrollSpeedTitle;
  v11 = 3;
  do
  {
    TPanel::delete_panel(v10);
    ++v10;
    --v11;
  }
  while ( v11 );
  TPanel::delete_panel((TPanel **)&v1->scrollSpeedSlider);
  v12 = (TPanel **)v1->sizeTitle;
  v13 = 4;
  do
  {
    TPanel::delete_panel(v12);
    ++v12;
    --v13;
  }
  while ( v13 );
  v14 = (TPanel **)v1->sizeButton;
  v15 = 3;
  do
  {
    TPanel::delete_panel(v14);
    ++v14;
    --v15;
  }
  while ( v15 );
  v16 = (TPanel **)v1->mouseTitle;
  v17 = 3;
  do
  {
    TPanel::delete_panel(v16);
    ++v16;
    --v17;
  }
  while ( v17 );
  v18 = (TPanel **)v1->mouseButton;
  v19 = 2;
  do
  {
    TPanel::delete_panel(v18);
    ++v18;
    --v19;
  }
  while ( v19 );
  v20 = (TPanel **)v1->rolloverTitle;
  v21 = 3;
  do
  {
    TPanel::delete_panel(v20);
    ++v20;
    --v21;
  }
  while ( v21 );
  v22 = (TPanel **)v1->rolloverButton;
  v23 = 2;
  do
  {
    TPanel::delete_panel(v22);
    ++v22;
    --v23;
  }
  while ( v23 );
  v24 = (TPanel **)v1->pathFindingTitle;
  v25 = 4;
  do
  {
    TPanel::delete_panel(v24);
    ++v24;
    --v25;
  }
  while ( v25 );
  v26 = (TPanel **)v1->pathFindingButton;
  v27 = 3;
  do
  {
    TPanel::delete_panel(v26);
    ++v26;
    --v27;
  }
  while ( v27 );
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56F750: using guessed type int (__thiscall *TribeConfigDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043C2B0) --------------------------------------------------------
int __thiscall TribeConfigDialog::action(TribeConfigDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeConfigDialog *v5; // esi@1
  unsigned int v6; // eax@32
  char *v7; // ST10_4@32
  char *v8; // eax@32
  int v9; // ecx@35
  bool v10; // sf@36
  unsigned __int8 v11; // of@36
  RGE_Prog_Info *v12; // eax@36
  int v13; // ecx@36
  TMusic_System *v14; // ecx@40
  char v15; // al@41
  TSound_Driver *v16; // ecx@46
  int v17; // edi@50
  int v18; // ebp@50
  TMusic_System *v20; // ecx@73
  TSound_Driver *v21; // ecx@74
  int v22; // eax@75
  RGE_Prog_Info *v23; // ecx@83
  TMusic_System *v24; // ecx@87
  TSound_Driver *v25; // ecx@89
  RGE_Prog_Info *v26; // eax@91
  int v27; // [sp-14h] [bp-124h]@42
  int v28; // [sp-10h] [bp-120h]@42
  int v29; // [sp-Ch] [bp-11Ch]@42
  float new_speed; // [sp+Ch] [bp-104h]@22
  char msg[256]; // [sp+10h] [bp-100h]@32

  v5 = this;
  if ( !fromPanel )
    return TPanel::action((TPanel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  if ( fromPanel == (TPanel *)this->okButton && actionIn == 1 )
  {
    if ( this->modeValue == InGame )
    {
      if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
        RGE_Base_Game::set_paused(rge_base_game, 0, 0);
      if ( TButtonPanel::get_state(v5->mouseButton[0]) )
        rge_base_game->prog_info->interface_style = 2;
      else
        rge_base_game->prog_info->interface_style = 1;
      ((void (*)(void))rge_base_game->vfptr->set_interface_messages)();
      if ( TButtonPanel::get_state(v5->rolloverButton[0]) )
        rge_base_game->rollover = 1;
      else
        rge_base_game->rollover = 0;
      if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
      {
        if ( TButtonPanel::get_state(v5->pathFindingButton[0]) )
        {
          RGE_Base_Game::setPathFinding(rge_base_game, 0);
          numberPathingIterations = 2500;
        }
        else if ( TButtonPanel::get_state(v5->pathFindingButton[1]) )
        {
          RGE_Base_Game::setPathFinding(rge_base_game, 1);
          numberPathingIterations = 5000;
        }
        else if ( TButtonPanel::get_state(v5->pathFindingButton[2]) )
        {
          RGE_Base_Game::setPathFinding(rge_base_game, 2);
          numberPathingIterations = 7500;
        }
      }
      if ( rge_base_game->prog_mode != 5 )
      {
        new_speed = 0.0;
        if ( TButtonPanel::get_state(v5->speedButton[0]) )
        {
          new_speed = 1.0;
        }
        else if ( TButtonPanel::get_state(v5->speedButton[1]) )
        {
          new_speed = 1.5;
        }
        else if ( TButtonPanel::get_state(v5->speedButton[2]) )
        {
          new_speed = 2.0;
        }
        if ( allow_user_commands && new_speed != 0.0 && new_speed != v5->gameSpeed )
        {
          if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
          {
            v6 = TCommunications_Handler::WhoAmI(comm);
            v7 = TCommunications_Handler::GetPlayerName(comm, v6);
            v8 = TPanel::get_string(3059);
            sprintf(msg, v8, v7);
            TCommunications_Handler::SendChatMsgAll(comm, msg);
          }
          TRIBE_Command::command_game_speed((TRIBE_Command *)rge_base_game->world->commands, new_speed);
          if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
            RGE_Base_Game::set_game_speed(rge_base_game, new_speed);
        }
      }
      v9 = v5->newMusicVolume;
      if ( v9 == v5->musicVolume )
        goto LABEL_48;
      v11 = __OFSUB__(v9, 99);
      v10 = v9 - 99 < 0;
      v12 = rge_base_game->prog_info;
      v13 = v12->use_music;
      if ( !(v10 ^ v11) )
      {
        if ( v13 )
        {
          v12->use_music = 0;
          ((void (*)(void))rge_base_game->vfptr->shutdown_music_system)();
        }
        goto LABEL_46;
      }
      if ( !v13 )
      {
        v12->use_music = 1;
        TRegistry::RegSetInt(Regs, 1, aMusicVolume, 100 * v5->newMusicVolume);
        ((void (*)(void))rge_base_game->vfptr->setup_music_system)();
        v14 = rge_base_game->music_system;
        if ( v14 )
        {
          v15 = v14->music_type;
          if ( v15 == 1 )
          {
            v29 = 1;
            v28 = v14->track_count;
            v27 = 5;
          }
          else
          {
            if ( v15 != 2 )
              goto LABEL_46;
            v29 = 1;
            v28 = v14->track_count;
            v27 = 1;
          }
          TMusic_System::play_tracks(v14, v27, v28, v29, 0, 0);
        }
      }
LABEL_46:
      v16 = rge_base_game->sound_system;
      if ( v16 )
        TSound_Driver::set_volume(v16, -100 * v5->newSoundVolume, 1);
LABEL_48:
      if ( TButtonPanel::get_state(v5->sizeButton[0]) )
        goto LABEL_101;
      if ( TButtonPanel::get_state(v5->sizeButton[1]) )
      {
        v17 = 800;
        v18 = 600;
        goto LABEL_54;
      }
      if ( !TButtonPanel::get_state(v5->sizeButton[2]) )
      {
LABEL_101:
        v17 = 640;
        v18 = 480;
      }
      else
      {
        v17 = 1024;
        v18 = 768;
      }
LABEL_54:
      TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
      (*(void (__thiscall **)(TribeConfigDialog *, _DWORD))&v5->vfptr->gap10[4])(v5, 0);
      TEasy_Panel::prepare_for_close((TEasy_Panel *)&v5->vfptr);
      if ( !do_color_log )
        RGE_Base_Game::set_screen_size(rge_base_game, v17, v18);
      goto LABEL_97;
    }
LABEL_96:
    TPanelSystem::setCurrentPanel(&panel_system, aMainMenu, 0);
LABEL_97:
    TPanelSystem::destroyPanel(&panel_system, aConfigDialog);
    return 1;
  }
  if ( fromPanel == (TPanel *)this->speedButton[0] && actionIn == 1 )
    return 1;
  if ( fromPanel == (TPanel *)this->speedButton[1] && actionIn == 1 )
    return 1;
  if ( fromPanel == (TPanel *)this->speedButton[2] && actionIn == 1 )
    return 1;
  if ( fromPanel == (TPanel *)this->sizeButton[0] )
    return 1;
  if ( fromPanel == (TPanel *)this->sizeButton[1] )
    return 1;
  if ( fromPanel == (TPanel *)this->sizeButton[2] )
    return 1;
  if ( fromPanel == (TPanel *)this->musicSlider && actionIn == 4 )
  {
    this->newMusicVolume = a1;
    v20 = rge_base_game->music_system;
    if ( !v20 )
      return 1;
    TMusic_System::set_volume(v20, -100 * a1, 1);
    v21 = rge_base_game->sound_system;
    if ( !v21 )
      return 1;
    v22 = -5 * v5->newSoundVolume;
LABEL_80:
    TSound_Driver::set_volume(v21, 20 * v22, 1);
    return 1;
  }
  if ( fromPanel != (TPanel *)this->soundSlider || actionIn != 4 )
  {
    if ( fromPanel != (TPanel *)this->scrollSpeedSlider || actionIn != 4 )
    {
      if ( fromPanel == (TPanel *)this->cancelButton && actionIn == 1 )
      {
        v24 = rge_base_game->music_system;
        if ( v24 )
          TMusic_System::set_volume(v24, -100 * v5->musicVolume, 1);
        v25 = rge_base_game->sound_system;
        if ( v25 )
          TSound_Driver::set_volume(v25, -100 * v5->soundVolume, 1);
        v26 = rge_base_game->prog_info;
        v26->mouse_scroll_interval = v5->scrollSpeed;
        v26->key_scroll_interval = v5->scrollSpeed;
        if ( v5->modeValue == InGame )
        {
          if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
            RGE_Base_Game::set_paused(rge_base_game, 0, 0);
          TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
          (*(void (__thiscall **)(TribeConfigDialog *, _DWORD))&v5->vfptr->gap10[4])(v5, 0);
          goto LABEL_97;
        }
        goto LABEL_96;
      }
    }
    else
    {
      v23 = rge_base_game->prog_info;
      v23->mouse_scroll_interval = a1 + 10;
      v23->key_scroll_interval = a1 + 10;
    }
    return TPanel::action((TPanel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
  }
  this->newSoundVolume = a1;
  v21 = rge_base_game->sound_system;
  if ( v21 )
  {
    v22 = -5 * a1;
    goto LABEL_80;
  }
  return 1;
}
// 57F9F4: using guessed type int numberPathingIterations;
// 58631C: using guessed type int allow_user_commands;
// 62C584: using guessed type unsigned __int8 do_color_log;
