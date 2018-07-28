
//----- (004926E0) --------------------------------------------------------
void __thiscall TRIBE_Credits_Screen::TRIBE_Credits_Screen(TRIBE_Credits_Screen *this)
{
  TRIBE_Credits_Screen *v1; // ebp@1
  TDrawArea *v2; // ecx@1
  RGE_Font *v3; // ebx@3
  void *v4; // edi@3
  int v5; // eax@3
  int v6; // esi@3
  TScrollTextPanel *v7; // ecx@7
  TScrollTextPanel *v8; // eax@8
  int v9; // esi@12
  TShape **v10; // edi@12
  TShape *v11; // eax@13
  TShape *v12; // eax@14
  TMusic_System *v13; // ecx@17
  __int32 size; // [sp+10h] [bp-24h]@4
  char temp_file_name[13]; // [sp+18h] [bp-1Ch]@13
  int v16; // [sp+30h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aCreditsScreen);
  v1->vfptr = (TPanelVtbl *)&TRIBE_Credits_Screen::`vftable';
  v1->text_panel = 0;
  v1->text_set = 1;
  v1->picture_set = 1;
  v1->last_picture_time = 0;
  v1->last_pause_time = 0;
  v1->mode = 1;
  v1->first_draw = 1;
  v1->text_done = 0;
  memset(v1->back_pics, 0, sizeof(v1->back_pics));
  v2 = rge_base_game->draw_area;
  v16 = 0;
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, v2, aScr_cred, 50059, 1) )
  {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    v3 = RGE_Base_Game::get_font(rge_base_game, 4);
    v4 = 0;
    v5 = _open(aData2List_cr, 0x8000);
    v6 = v5;
    if ( v5 != -1 )
    {
      lseek(v5, 0, 2);
      size = _tell(v6);
      v4 = calloc(size + 1, 0x400u);
      if ( v4 )
      {
        lseek(v6, 0, 0);
        read(v6, v4, size);
      }
      _close(v6);
    }
    v7 = (TScrollTextPanel *)operator new(0x198u);
    LOBYTE(v16) = 1;
    if ( v7 )
      TScrollTextPanel::TScrollTextPanel(
        v7,
        (TPanel *)&v1->vfptr,
        v1->render_area,
        v1->pnl_wid / 2 - 250,
        v1->pnl_hgt / 2 - 150,
        500,
        300,
        30,
        v3->font,
        v3->font_wid,
        v3->font_hgt,
        (char *)v4);
    else
      v8 = 0;
    LOBYTE(v16) = 0;
    v1->text_panel = v8;
    if ( v4 )
      free(v4);
    v9 = 50155;
    v1->back_pics[0] = v1->background_pic;
    v10 = &v1->back_pics[1];
    do
    {
      sprintf(temp_file_name, aCreditD, v9 - 50153);
      v11 = (TShape *)operator new(0x20u);
      LOBYTE(v16) = 2;
      if ( v11 )
        TShape::TShape(v11, temp_file_name, v9);
      else
        v12 = 0;
      *v10 = v12;
      ++v10;
      ++v9;
      LOBYTE(v16) = 0;
    }
    while ( v9 - 50154 < 7 );
    v13 = rge_base_game->music_system;
    if ( v13 && v13->music_type == 1 && v13->track_count == 15 )
      TMusic_System::play_tracks(v13, 15, 15, 1, 0, 0);
  }
  else
  {
    v1->error_code = 1;
  }
}
// 572750: using guessed type int (__thiscall *TRIBE_Credits_Screen::`vftable')(void *Memory, unsigned int __flags);

//----- (00492950) --------------------------------------------------------
TRIBE_Credits_Screen *__thiscall TRIBE_Credits_Screen::`vector deleting destructor'(TRIBE_Credits_Screen *this, unsigned int __flags)
{
  TRIBE_Credits_Screen *v2; // esi@1

  v2 = this;
  TRIBE_Credits_Screen::~TRIBE_Credits_Screen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00492970) --------------------------------------------------------
void __thiscall TRIBE_Credits_Screen::~TRIBE_Credits_Screen(TRIBE_Credits_Screen *this)
{
  TRIBE_Credits_Screen *v1; // ebp@1
  TShape **v2; // edi@1
  signed int v3; // ebx@1
  TShape *v4; // esi@2
  TScrollTextPanel *v5; // ecx@5
  TMusic_System *v6; // ecx@7

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Credits_Screen::`vftable';
  v2 = this->back_pics;
  v3 = 7;
  do
  {
    v4 = *v2;
    if ( *v2 )
    {
      TShape::~TShape(*v2);
      operator delete(v4);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v5 = v1->text_panel;
  v1->background_pic = 0;
  if ( v5 )
  {
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->text_panel = 0;
  }
  v6 = rge_base_game->music_system;
  if ( v6 && v6->music_type == 1 && v6->track_count == 15 )
    TMusic_System::play_tracks(v6, 5, 14, 1, 0, 0);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 572750: using guessed type int (__thiscall *TRIBE_Credits_Screen::`vftable')(void *Memory, unsigned int __flags);

//----- (00492A40) --------------------------------------------------------
int __stdcall TRIBE_Credits_Screen::handle_mouse_down(char mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TRIBE_Credits_Screen::close_screen();
  return 1;
}

//----- (00492A50) --------------------------------------------------------
int __thiscall TRIBE_Credits_Screen::handle_idle(TRIBE_Credits_Screen *this)
{
  TRIBE_Credits_Screen *v1; // esi@1
  TRIBE_Credits_Screen::ScreenMode v2; // eax@1
  TDrawArea *v3; // ecx@4
  void *v4; // eax@7
  TPanelVtbl *v5; // edi@13
  int v6; // ecx@17
  TPanelVtbl *v7; // edi@19
  TDrawArea *v8; // eax@19
  int result; // eax@28

  v1 = this;
  v2 = this->mode;
  if ( v2 == 1 )
  {
    if ( this->last_picture_time )
    {
      if ( debug_timeGetTime() - this->last_picture_time >= 0x2710 )
      {
        v3 = v1->render_area;
        if ( v3->DrawSystem->ScreenMode == 2 || v3->DrawSystem->DrawType == 1 )
        {
          v4 = v1->palette;
          v1->mode = 2;
          v1->color.peRed = 0;
          v1->color.peGreen = 0;
          v1->color.peBlue = 0;
          if ( v4 )
            GetPaletteEntries(v4, 0, 0x100u, v1->color_table);
          else
            TDrawArea::GetPalette(v3, v1->color_table);
          RGE_fade_palette_start(v1->render_area, v1->color, 0.5, 1, 0, 255, -1);
        }
        else
        {
          v1->mode = 4;
        }
      }
      goto LABEL_27;
    }
LABEL_26:
    v1->last_picture_time = debug_timeGetTime();
    goto LABEL_27;
  }
  if ( v2 != 2 )
  {
    if ( v2 == 4 )
    {
      if ( !this->last_pause_time )
      {
        this->last_pause_time = debug_timeGetTime();
        goto LABEL_27;
      }
      debug_timeGetTime();
      v6 = v1->picture_set + 1;
      v1->mode = 5;
      v1->picture_set = v6;
      if ( v6 > 7 )
        v1->picture_set = 1;
      v7 = v1->vfptr;
      v1->background_pic = (TShape *)*((_DWORD *)&v1->color + v1->picture_set);
      v7->set_redraw((TPanel *)v1, RedrawNormal);
      v7->handle_paint((TPanel *)v1);
      TDrawSystem::Paint(v1->render_area->DrawSystem, 0);
      v8 = v1->render_area;
      if ( v8->DrawSystem->ScreenMode == 2 || v8->DrawSystem->DrawType == 1 )
      {
        RGE_fade_palette_start(v8, v1->color, 0.5, 2, v1->color_table, 255, -1);
        goto LABEL_27;
      }
      v1->mode = 1;
    }
    else
    {
      if ( v2 != 5 || !RGE_fade_palette_step() )
        goto LABEL_27;
      v1->mode = 1;
    }
    goto LABEL_26;
  }
  if ( RGE_fade_palette_step() )
  {
    v5 = v1->vfptr;
    v1->mode = 4;
    v1->last_pause_time = 0;
    v5->set_redraw((TPanel *)v1, RedrawNormal);
    v5->handle_paint((TPanel *)v1);
    TDrawSystem::Paint(v1->render_area->DrawSystem, 0);
  }
LABEL_27:
  if ( v1->text_done )
  {
    TRIBE_Credits_Screen::close_screen();
    result = 1;
  }
  else
  {
    result = TPanel::handle_idle((TPanel *)&v1->vfptr);
  }
  return result;
}

//----- (00492CC0) --------------------------------------------------------
void __thiscall TRIBE_Credits_Screen::draw(TRIBE_Credits_Screen *this)
{
  TRIBE_Credits_Screen *v1; // esi@1
  TDrawArea *v2; // ecx@2
  signed int v3; // ebx@6
  TShape **v4; // edi@6
  TShape *v5; // ecx@8

  v1 = this;
  if ( this->mode != 4 || (v2 = this->render_area, v2->DrawSystem->ScreenMode != 2) && v2->DrawSystem->DrawType != 1 )
  {
    if ( v1->first_draw )
    {
      v3 = 7;
      v4 = v1->back_pics;
      do
      {
        v1->background_pic = *v4;
        TScreenPanel::draw((TScreenPanel *)&v1->vfptr);
        ++v4;
        --v3;
      }
      while ( v3 );
      v5 = v1->back_pics[0];
      v1->first_draw = 0;
      v1->background_pic = v5;
    }
    TScreenPanel::draw((TScreenPanel *)&v1->vfptr);
  }
  else
  {
    TDrawArea::Clear(v2, &v1->clip_rect, 0);
  }
}

//----- (00492D50) --------------------------------------------------------
int __stdcall TRIBE_Credits_Screen::key_down_action(int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  int result; // eax@3

  if ( key == 13 || key == 27 )
  {
    TRIBE_Credits_Screen::close_screen();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00492D70) --------------------------------------------------------
int __thiscall TRIBE_Credits_Screen::action(TRIBE_Credits_Screen *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  int result; // eax@4

  if ( from_panel && from_panel == (TPanel *)this->text_panel && action_in == 1 )
  {
    this->text_done = 1;
    result = 1;
  }
  else
  {
    result = TEasy_Panel::action((TEasy_Panel *)&this->vfptr, from_panel, action_in, action_val1, action_val2);
  }
  return result;
}

//----- (00492DB0) --------------------------------------------------------
void TRIBE_Credits_Screen::close_screen()
{
  TRIBE_Screen_Main_Menu *v1; // eax@6
  char *v2; // [sp-8h] [bp-18h]@5

  if ( TPanelSystem::panel(&panel_system, aGameScreen) )
  {
    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
      RGE_Base_Game::set_paused(rge_base_game, 0, 0);
    v2 = aGameScreen;
  }
  else
  {
    v1 = (TRIBE_Screen_Main_Menu *)operator new(0x4B0u);
    if ( v1 )
      TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(v1);
    v2 = aMainMenu;
  }
  TPanelSystem::setCurrentPanel(&panel_system, v2, 0);
  TPanelSystem::destroyPanel(&panel_system, aCreditsScreen);
}
