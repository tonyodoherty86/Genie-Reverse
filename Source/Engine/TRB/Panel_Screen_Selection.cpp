
//----- (004B75A0) --------------------------------------------------------
void __thiscall TribeSelectTribeScreen::TribeSelectTribeScreen(TribeSelectTribeScreen *this)
{
  TribeSelectTribeScreen *v1; // ebp@1
  TDrawArea *v2; // ST30_4@1
  signed int v3; // eax@3
  char *v4; // edx@4
  const char *v5; // edi@4
  TPicturePanel *v6; // eax@7
  TPicturePanel *v7; // eax@8
  RGE_Font *v8; // ebx@14
  TTextPanel *v9; // eax@14
  TTextPanel *v10; // eax@15
  TButtonPanel *v11; // eax@20
  TPanel *v12; // eax@21
  int v13; // esi@24
  int v14; // ST34_4@24
  int v15; // ST30_4@24
  void *v16; // ST2C_4@24
  char *v17; // eax@24
  RGE_Font *v18; // esi@28
  TTextPanel *v19; // eax@28
  TTextPanel *v20; // eax@29
  int v21; // ebx@33
  unsigned int v22; // edx@33
  TButtonPanel *v23; // eax@33
  TPanel *v24; // eax@34
  int v25; // ecx@38
  unsigned int v26; // edx@38
  TButtonPanel *v27; // eax@38
  TPanel *v28; // eax@39
  int v29; // ecx@43
  unsigned int v30; // edx@43
  TPanel *v31; // edx@43
  TButtonPanel **v32; // [sp+34h] [bp-60h]@19
  TTextPanel *secondHeight; // [sp+38h] [bp-5Ch]@15
  int secondHeighta; // [sp+38h] [bp-5Ch]@19
  TPanel *v35; // [sp+3Ch] [bp-58h]@21
  int secondWidth; // [sp+40h] [bp-54h]@19
  TTextPanel *secondWidtha; // [sp+40h] [bp-54h]@29
  TPanel *secondWidthb; // [sp+40h] [bp-54h]@34
  TPanel *secondWidthc; // [sp+40h] [bp-54h]@39
  TDigital *buttonSound; // [sp+44h] [bp-50h]@19
  int i; // [sp+48h] [bp-4Ch]@19
  RGE_Font *font; // [sp+4Ch] [bp-48h]@19
  char backgroundName[10]; // [sp+54h] [bp-40h]@4
  TPanel *tabList[10]; // [sp+60h] [bp-34h]@43
  int v45; // [sp+90h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aSelectTribeScr);
  v1->vfptr = (TPanelVtbl *)&TribeSelectTribeScreen::`vftable';
  v1->screenText = 0;
  v2 = rge_base_game->draw_area;
  v45 = 0;
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, v2, 0, 0, 1) )
  {
    v3 = v1->render_area->Width;
    if ( v3 >= 800 )
    {
      v4 = backgroundName;
      v5 = aBga800;
      if ( v3 >= 1024 )
        v5 = aBga1024;
    }
    else
    {
      v4 = backgroundName;
      v5 = aBga640;
    }
    strcpy(v4, v5);
    v6 = (TPicturePanel *)operator new(0x11Cu);
    LOBYTE(v45) = 1;
    if ( v6 )
      TPicturePanel::TPicturePanel(v6);
    else
      v7 = 0;
    LOBYTE(v45) = 0;
    v1->background = v7;
    if ( v7 )
    {
      if ( TPicturePanel::setup(v7, v1->render_area, (TPanel *)&v1->vfptr, 0, 0, 0, 0, backgroundName, -1, 0, 1) )
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))&v1->background->vfptr->gap10[8])(
          2,
          0,
          0,
          0,
          0,
          640 * v1->pnl_wid / 640,
          640 * v1->pnl_wid / 640,
          480 * v1->pnl_hgt / 480,
          480 * v1->pnl_hgt / 480,
          0,
          0,
          0,
          0);
        v8 = RGE_Base_Game::get_font(rge_base_game, 1);
        v9 = (TTextPanel *)operator new(0x188u);
        LOBYTE(v45) = 2;
        if ( v9 )
        {
          TTextPanel::TTextPanel(v9);
          secondHeight = v10;
        }
        else
        {
          secondHeight = 0;
          v10 = 0;
        }
        LOBYTE(v45) = 0;
        v1->title = v10;
        if ( v10 )
        {
          TTextPanel::setup(
            secondHeight,
            v1->render_area,
            (TPanel *)&v1->background->vfptr,
            20 * v1->pnl_wid / 640,
            20 * v1->pnl_hgt / 480,
            600 * v1->pnl_wid / 640,
            30 * v1->pnl_hgt / 480,
            v8->font,
            v8->font_wid,
            v8->font_hgt,
            0,
            0,
            0,
            0,
            0,
            0,
            aCivilizationSe);
          buttonSound = (TDigital *)RGE_Base_Game::get_sound(rge_base_game, 0);
          font = RGE_Base_Game::get_font(rge_base_game, 0);
          secondWidth = 0;
          secondHeighta = 0;
          i = 0;
          v32 = v1->tribeButton;
          do
          {
            v11 = (TButtonPanel *)operator new(0x2B8u);
            LOBYTE(v45) = 3;
            if ( v11 )
            {
              TButtonPanel::TButtonPanel(v11);
              v35 = v12;
            }
            else
            {
              v35 = 0;
              v12 = 0;
            }
            LOBYTE(v45) = 0;
            *v32 = (TButtonPanel *)v12;
            if ( !v12 )
              goto LABEL_42;
            TButtonPanel::setup(
              v35,
              v1->render_area,
              (TPanel *)&v1->background->vfptr,
              20 * v1->pnl_wid / 640 + v1->pnl_wid * secondWidth / 640,
              50 * v1->pnl_hgt / 480 + 115 * v1->pnl_hgt * secondHeighta / 480,
              200 * v1->pnl_wid / 640,
              110 * v1->pnl_hgt / 480,
              (TPanel *)3,
              buttonSound,
              (TPanel *)1,
              0);
            v13 = i;
            v14 = font->font_hgt;
            v15 = font->font_wid;
            v16 = font->font;
            v17 = TribeSelectTribeScreen::tribeName(i);
            TButtonPanel::set_text_info(*v32, v17, v16, v15, v14, -1, -1);
            if ( i == 2 || i == 5 )
            {
              secondHeighta = -1;
              secondWidth += 200;
            }
            ++i;
            ++v32;
            ++secondHeighta;
          }
          while ( v13 + 1 < 9 );
          v18 = RGE_Base_Game::get_font(rge_base_game, 11);
          v19 = (TTextPanel *)operator new(0x188u);
          LOBYTE(v45) = 4;
          if ( v19 )
          {
            TTextPanel::TTextPanel(v19);
            secondWidtha = v20;
          }
          else
          {
            secondWidtha = 0;
            v20 = 0;
          }
          LOBYTE(v45) = 0;
          v1->tribeText = v20;
          if ( !v20 )
          {
            v1->error_code = 1;
            return;
          }
          v21 = v1->pnl_wid;
          v22 = (signed int)((unsigned __int64)(876173328690i64 * v21) >> 32) >> 8;
          TTextPanel::setup(
            secondWidtha,
            v1->render_area,
            (TPanel *)&v1->background->vfptr,
            20 * v21 / 640,
            400 * v1->pnl_hgt / 480,
            (v22 >> 31) + v22,
            60 * v1->pnl_hgt / 480,
            v18->font,
            v18->font_wid,
            v18->font_hgt,
            0,
            0,
            0,
            0,
            0,
            0,
            message_in);
          TTextPanel::set_alignment(v1->tribeText, AlignTop, AlignWordwrap);
          v23 = (TButtonPanel *)operator new(0x2B8u);
          LOBYTE(v45) = 5;
          if ( v23 )
          {
            TButtonPanel::TButtonPanel(v23);
            secondWidthb = v24;
          }
          else
          {
            secondWidthb = 0;
            v24 = 0;
          }
          LOBYTE(v45) = 0;
          v1->okButton = (TButtonPanel *)v24;
          if ( !v24 )
          {
            v1->error_code = 1;
            return;
          }
          v25 = v1->pnl_wid;
          v26 = (signed int)((unsigned __int64)(858993459500i64 * v25) >> 32) >> 8;
          TButtonPanel::setup(
            secondWidthb,
            v1->render_area,
            (TPanel *)&v1->background->vfptr,
            (v26 >> 31) + v26,
            400 * v1->pnl_hgt / 480,
            120 * v25 / 640,
            30 * v1->pnl_hgt / 480,
            (TPanel *)3,
            buttonSound,
            (TPanel *)1,
            0);
          TButtonPanel::set_text_info(v1->okButton, aPreviousScreen, v18->font, v18->font_wid, v18->font_hgt, -1, -1);
          v27 = (TButtonPanel *)operator new(0x2B8u);
          LOBYTE(v45) = 6;
          if ( v27 )
          {
            TButtonPanel::TButtonPanel(v27);
            secondWidthc = v28;
          }
          else
          {
            secondWidthc = 0;
            v28 = 0;
          }
          LOBYTE(v45) = 0;
          v1->cancelButton = (TButtonPanel *)v28;
          if ( !v28 )
          {
LABEL_42:
            v1->error_code = 1;
            return;
          }
          v29 = v1->pnl_wid;
          v30 = (signed int)((unsigned __int64)(858993459500i64 * v29) >> 32) >> 8;
          TButtonPanel::setup(
            secondWidthc,
            v1->render_area,
            (TPanel *)&v1->background->vfptr,
            (v30 >> 31) + v30,
            440 * v1->pnl_hgt / 480,
            120 * v29 / 640,
            30 * v1->pnl_hgt / 480,
            (TPanel *)3,
            buttonSound,
            (TPanel *)1,
            0);
          TButtonPanel::set_text_info(v1->cancelButton, aCancel, v18->font, v18->font_wid, v18->font_hgt, -1, -1);
          TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->background->vfptr);
          TPanel::set_curr_child((TPanel *)&v1->background->vfptr, (TPanel *)v1->tribeButton[0]);
          TribeSelectTribeScreen::fillTribeText(v1, 0);
          v31 = (TPanel *)v1->okButton;
          qmemcpy(tabList, v1->tribeButton, 0x24u);
          tabList[9] = v31;
          TPanel::set_tab_order(tabList, 10);
        }
        else
        {
          v1->error_code = 1;
        }
      }
      else
      {
        v1->error_code = 1;
      }
    }
    else
    {
      v1->error_code = 1;
    }
  }
  else
  {
    v1->error_code = 1;
  }
}
// 5741F0: using guessed type int (__thiscall *TribeSelectTribeScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B7DD0) --------------------------------------------------------
TribeSelectTribeScreen *__thiscall TribeSelectTribeScreen::`scalar deleting destructor'(TribeSelectTribeScreen *this, unsigned int __flags)
{
  TribeSelectTribeScreen *v2; // esi@1

  v2 = this;
  TribeSelectTribeScreen::~TribeSelectTribeScreen(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B7DF0) --------------------------------------------------------
void __thiscall TribeSelectTribeScreen::~TribeSelectTribeScreen(TribeSelectTribeScreen *this)
{
  TribeSelectTribeScreen *v1; // edi@1
  TTextPanel *v2; // ecx@1
  TTextPanel *v3; // ecx@3
  TButtonPanel **v4; // esi@5
  signed int v5; // ebx@5
  TButtonPanel *v6; // ecx@9
  TButtonPanel *v7; // ecx@11
  int i; // esi@13

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeSelectTribeScreen::`vftable';
  v2 = this->title;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->tribeText;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->tribeButton;
  v5 = 9;
  do
  {
    if ( *v4 )
      (**(void (__stdcall ***)(_DWORD))*v4)(1);
    ++v4;
    --v5;
  }
  while ( v5 );
  v6 = v1->okButton;
  if ( v6 )
    (**(void (__stdcall ***)(_DWORD))v6)(1);
  v7 = v1->cancelButton;
  if ( v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  for ( i = 0; i < v1->numLines; ++i )
    free(v1->screenText[i]);
  free(v1->screenText);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5741F0: using guessed type int (__thiscall *TribeSelectTribeScreen::`vftable')(void *Memory, unsigned int __flags);

//----- (004B7EE0) --------------------------------------------------------
int __thiscall TribeSelectTribeScreen::action(TribeSelectTribeScreen *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  int v5; // edi@3
  int v6; // eax@4
  TPanel **v7; // edx@4

  if ( fromPanel == (TPanel *)this->okButton || fromPanel == (TPanel *)this->cancelButton )
  {
    v5 = actionIn;
    if ( actionIn == 1 )
    {
      TPanelSystem::setCurrentPanel(&panel_system, aMpSetupScreen, 0);
      TPanelSystem::destroyPanel(&panel_system, aSelectTribeScr);
      return 1;
    }
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, v5, a1, a2);
  }
  v5 = actionIn;
  if ( actionIn != 1 )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, v5, a1, a2);
  v6 = 0;
  v7 = (TPanel **)this->tribeButton;
  while ( fromPanel != *v7 )
  {
    ++v6;
    ++v7;
    if ( v6 >= 9 )
      return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, v5, a1, a2);
  }
  TribeSelectTribeScreen::fillTribeText(this, v6);
  return 1;
}

//----- (004B7F70) --------------------------------------------------------
void __thiscall TribeSelectTribeScreen::fillTribeText(TribeSelectTribeScreen *this, int t)
{
  TribeSelectTribeScreen *v2; // esi@1

  v2 = this;
  switch ( t )
  {
    case 0:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aAssyrianInform);
      break;
    case 1:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aBabylonianInfo);
      break;
    case 2:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aEgyptianInform);
      break;
    case 3:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aGreekInformati);
      break;
    case 4:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aHittiteInforma);
      break;
    case 5:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aIsrealiteInfor);
      break;
    case 6:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aMinoanInformat);
      break;
    case 7:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aPhoenicianInfo);
      break;
    case 8:
      (*(void (__stdcall **)(char *))&this->tribeText->vfptr[1].gap4[4])(aSumerianInform);
      break;
    default:
      break;
  }
  TTextPanel::scroll(v2->tribeText, 6, 0, 1);
}

//----- (004B8070) --------------------------------------------------------
char *__stdcall TribeSelectTribeScreen::tribeName(int i)
{
  char *result; // eax@2

  switch ( i )
  {
    case 0:
      result = aAssyrian;
      break;
    case 1:
      result = aBabylonian;
      break;
    case 2:
      result = aEgyptian;
      break;
    case 3:
      result = aGreek;
      break;
    case 4:
      result = aHittite;
      break;
    case 5:
      result = aIsrealite;
      break;
    case 6:
      result = aMinoan;
      break;
    case 7:
      result = aPhoenician;
      break;
    case 8:
      result = aSumerian;
      break;
    default:
      result = aNoCulture;
      break;
  }
  return result;
}
