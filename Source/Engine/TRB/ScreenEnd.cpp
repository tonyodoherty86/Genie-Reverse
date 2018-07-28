
//----- (004936D0) --------------------------------------------------------
void __thiscall TribeEndScreen::TribeEndScreen(TribeEndScreen *this, char *titleText, char **textText, int textLineCount)
{
  TribeEndScreen *v4; // ebp@1
  signed int v5; // eax@3
  char *v6; // edx@4
  const char *v7; // edi@4
  TPicturePanel *v8; // eax@7
  TPicturePanel *v9; // eax@8
  RGE_Font *v10; // ebx@14
  TTextPanel *v11; // eax@14
  TTextPanel *v12; // eax@15
  TTextPanel *v13; // eax@19
  TTextPanel *v14; // eax@20
  RGE_Font *v15; // eax@24
  TDigital **v16; // esi@24
  RGE_Font *v17; // ebx@24
  TButtonPanel *v18; // eax@24
  char *v19; // eax@25
  TTextPanel *v20; // [sp+34h] [bp-20h]@15
  char backgroundName[10]; // [sp+3Ch] [bp-18h]@4
  int v22; // [sp+50h] [bp-4h]@1
  char *titleTexta; // [sp+58h] [bp+4h]@25

  v4 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aEndScreen);
  v4->vfptr = (TPanelVtbl *)&TribeEndScreen::`vftable';
  v22 = 0;
  if( TScreenPanel::setup((TScreenPanel *)&v4->vfptr, rge_base_game->draw_area, 0, 0, 1) )
  {
    v5 = v4->render_area->Width;
    if( v5 >= 800 )
    {
      v6 = backgroundName;
      v7 = aBga800;
      if( v5 >= 1024 )
        v7 = aBga1024;
    }
    else
    {
      v6 = backgroundName;
      v7 = aBga640;
    }
    strcpy(v6, v7);
    v8 = (TPicturePanel *)operator new(0x11Cu);
    LOBYTE(v22) = 1;
    if( v8 )
      TPicturePanel::TPicturePanel(v8);
    else
      v9 = 0;
    LOBYTE(v22) = 0;
    v4->background = v9;
    if( v9 )
    {
      if( TPicturePanel::setup(v9, v4->render_area, (TPanel *)&v4->vfptr, 0, 0, 0, 0, backgroundName, -1, 0, 1) )
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))&v4->background->vfptr->gap10[8])(
          2,
          0,
          0,
          0,
          0,
          640 * v4->pnl_wid / 640,
          640 * v4->pnl_wid / 640,
          480 * v4->pnl_hgt / 480,
          480 * v4->pnl_hgt / 480,
          0,
          0,
          0,
          0);
        v10 = RGE_Base_Game::get_font(rge_base_game, 1);
        v11 = (TTextPanel *)operator new(0x188u);
        LOBYTE(v22) = 2;
        if( v11 )
        {
          TTextPanel::TTextPanel(v11);
          v20 = v12;
        }
        else
        {
          v20 = 0;
          v12 = 0;
        }
        LOBYTE(v22) = 0;
        v4->title = v12;
        if( v12 )
        {
          TTextPanel::setup(
            v20,
            v4->render_area,
            (TPanel *)&v4->background->vfptr,
            20 * v4->pnl_wid / 640,
            20 * v4->pnl_hgt / 480,
            600 * v4->pnl_wid / 640,
            30 * v4->pnl_hgt / 480,
            v10->font,
            v10->font_wid,
            v10->font_hgt,
            0,
            0,
            0,
            0,
            0,
            0,
            titleText);
          v13 = (TTextPanel *)operator new(0x188u);
          LOBYTE(v22) = 3;
          if( v13 )
            TTextPanel::TTextPanel(v13);
          else
            v14 = 0;
          LOBYTE(v22) = 0;
          v4->text = v14;
          if( v14 )
          {
            v15 = RGE_Base_Game::get_font(rge_base_game, 11);
            TTextPanel::setup(
              v4->text,
              v4->render_area,
              (TPanel *)&v4->background->vfptr,
              20 * v4->pnl_wid / 640,
              70 * v4->pnl_hgt / 480,
              600 * v4->pnl_wid / 640,
              340 * v4->pnl_hgt / 480,
              v15->font,
              v15->font_wid,
              v15->font_hgt,
              0,
              0,
              0,
              0,
              0,
              0,
              0);
            ((void (__stdcall *)(char **, int))v4->text->vfptr[1].__vecDelDtor)(textText, textLineCount);
            TTextPanel::set_alignment(v4->text, 0, 0);
            TTextPanel::scroll(v4->text, 6, 0, 1);
            v16 = RGE_Base_Game::get_sound(rge_base_game, 0);
            v17 = RGE_Base_Game::get_font(rge_base_game, 0);
            v18 = (TButtonPanel *)operator new(0x2B8u);
            LOBYTE(v22) = 4;
            if( v18 )
            {
              TButtonPanel::TButtonPanel(v18);
              titleTexta = v19;
            }
            else
            {
              titleTexta = 0;
              v19 = 0;
            }
            LOBYTE(v22) = 0;
            v4->okButton = (TButtonPanel *)v19;
            if( v19 )
            {
              TButtonPanel::setup(
                (TPanel *)titleTexta,
                v4->render_area,
                (TPanel *)&v4->background->vfptr,
                170 * v4->pnl_wid / 640,
                430 * v4->pnl_hgt / 480,
                300 * v4->pnl_wid / 640,
                40 * v4->pnl_hgt / 480,
                (TPanel *)3,
                (TDigital *)v16,
                (TPanel *)1,
                0);
              TButtonPanel::set_text_info(v4->okButton, aOk, v17->font, v17->font_wid, v17->font_hgt, -1, -1);
              TPanel::set_curr_child((TPanel *)&v4->vfptr, (TPanel *)&v4->background->vfptr);
              TPanel::set_curr_child((TPanel *)&v4->background->vfptr, (TPanel *)&v4->text->vfptr);
            }
            else
            {
              v4->error_code = 1;
            }
          }
          else
          {
            v4->error_code = 1;
          }
        }
        else
        {
          v4->error_code = 1;
        }
      }
      else
      {
        v4->error_code = 1;
      }
    }
    else
    {
      v4->error_code = 1;
    }
  }
  else
  {
    v4->error_code = 1;
  }
}
// 572980: using guessed type int (__thiscall *TribeEndScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (00493BE0) --------------------------------------------------------
TribeEndScreen *__thiscall TribeEndScreen::`vector deleting destructor'(TribeEndScreen *this, unsigned int __flags)
{
  TribeEndScreen *v2; // esi@1

  v2 = this;
  TribeEndScreen::~TribeEndScreen(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00493C00) --------------------------------------------------------
void __thiscall TribeEndScreen::~TribeEndScreen(TribeEndScreen *this)
{
  TribeEndScreen *v1; // esi@1
  TTextPanel *v2; // ecx@1
  TTextPanel *v3; // ecx@3
  TButtonPanel *v4; // ecx@5
  TPicturePanel *v5; // ecx@7

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeEndScreen::`vftable';
  v2 = this->title;
  if( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->text;
  if( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->okButton;
  if( v4 )
    (**(void (__stdcall ***)(_DWORD))v4)(1);
  v5 = v1->background;
  if( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 572980: using guessed type int (__thiscall *TribeEndScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (00493C90) --------------------------------------------------------
int __thiscall TribeEndScreen::action(TribeEndScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeAchievementsScreen *v5; // edi@3
  char *v6; // eax@4
  int result; // eax@5

  if( fromPanel && actionIn == 1 )
  {
    v5 = (TribeAchievementsScreen *)operator new(0x5F8u);
    if( v5 )
    {
      v6 = TPanel::get_string(9886);
      TribeAchievementsScreen::TribeAchievementsScreen(v5, v6, 1);
    }
    TPanelSystem::setCurrentPanel(&panel_system, aAchievementsSc, 0);
    TPanelSystem::destroyPanel(&panel_system, aEndScreen);
    result = 1;
  }
  else
  {
    result = TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  return result;
}
