
//----- (004A5610) --------------------------------------------------------
void __thiscall TRIBE_Screen_Wait::TRIBE_Screen_Wait(TRIBE_Screen_Wait *this)
{
  TRIBE_Screen_Wait *v1; // ebx@1
  int v2; // esi@1
  int v3; // esi@5
  TTextPanel **v4; // edi@5
  int v5; // esi@8
  signed int v6; // edi@8
  char *v7; // ST78_4@11
  char *v8; // eax@11
  int v9; // ebp@11
  char *v10; // eax@15
  char *v11; // eax@18
  char *v12; // eax@25
  int v13; // ebp@25
  char *v14; // eax@26
  char *v15; // eax@36
  int v16; // ebp@37
  char *v17; // eax@39
  int v18; // ST78_4@41
  char *v19; // eax@41
  char *v20; // eax@38
  char *v21; // eax@45
  int v22; // ebp@46
  TRIBE_Game::Age v23; // eax@46
  char *v24; // eax@51
  int v25; // ebp@51
  TRIBE_Game::ResourceLevel v26; // eax@51
  char *v27; // eax@54
  int v28; // ebp@54
  int v29; // eax@54
  int v30; // ebp@54
  char *v31; // eax@57
  int v32; // ebp@57
  char *v33; // eax@58
  char *v34; // eax@60
  int v35; // ebp@60
  char *v36; // eax@63
  int v37; // ebp@63
  char *v38; // eax@65
  char *v39; // eax@67
  char v40; // al@69
  char *v41; // eax@71
  int v42; // ebp@71
  int v43; // ST78_4@71
  char *v44; // eax@71
  int v45; // [sp+70h] [bp-32Ch]@47
  char *v46; // [sp+74h] [bp-328h]@47
  char *v47; // [sp+74h] [bp-328h]@69
  int v48; // [sp+7Ch] [bp-320h]@0
  int v49; // [sp+7Ch] [bp-320h]@57
  char str1[256]; // [sp+90h] [bp-30Ch]@13
  char str2[256]; // [sp+190h] [bp-20Ch]@11
  char str3[256]; // [sp+290h] [bp-10Ch]@54
  int v53; // [sp+398h] [bp-4h]@1

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aMultiplayerWai);
  v2 = (int)&v1->close_button;
  v1->vfptr = (TPanelVtbl *)&TRIBE_Screen_Wait::`vftable';
  v1->message = 0;
  v1->cancel_button = 0;
  v1->close_button = 0;
  v1->scenarioName = 0;
  memset(v1->settingText, 0, sizeof(v1->settingText));
  v53 = 0;
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, info_file_name_in, 50053, 0) )
  {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v1->vfptr,
      (TPanel *)&v1->vfptr,
      &v1->message,
      message_in,
      20,
      40,
      380,
      400,
      4,
      1,
      1,
      1);
    if ( TEasy_Panel::create_button(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->close_button,
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
      (*(void (__stdcall **)(signed int))(**(_DWORD **)v2 + 20))(1);
      (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v2 + 24))(
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
      if ( TEasy_Panel::create_text(
             (TEasy_Panel *)&v1->vfptr,
             (TPanel *)&v1->vfptr,
             &v1->scenarioName,
             message_in,
             420,
             84,
             220,
             68,
             11,
             0,
             0,
             1) )
      {
        v3 = 83;
        v4 = v1->settingText;
        while ( TEasy_Panel::create_text(
                  (TEasy_Panel *)&v1->vfptr,
                  (TPanel *)&v1->vfptr,
                  v4,
                  message_in,
                  420,
                  v3,
                  220,
                  20,
                  11,
                  0,
                  0,
                  0) )
        {
          v3 += 24;
          ++v4;
          if ( v3 >= 563 )
          {
            v5 = (int)v1->settingText;
            v6 = 20;
            do
            {
              (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v5 + 20))(0);
              v5 += 4;
              --v6;
            }
            while ( v6 );
            if ( RGE_Base_Game::scenarioGame(rge_base_game) )
            {
              v7 = RGE_Base_Game::scenarioName(rge_base_game);
              v8 = TPanel::get_string(9709);
              sprintf(str2, v8, v7);
              (*(void (__stdcall **)(char *))&v1->scenarioName->vfptr[1].gap4[4])(str2);
              v9 = 3;
            }
            else
            {
              if ( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
                TPanel::get_string(9751, str1, 256);
              else
                TPanel::get_string(9653, str1, 256);
              v10 = TPanel::get_string(9709);
              sprintf(str2, v10, str1);
              (*(void (__stdcall **)(char *))&v1->scenarioName->vfptr[1].gap4[4])(str2);
              v9 = 1;
            }
            if ( RGE_Base_Game::randomGame(rge_base_game) )
            {
              switch ( TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game) )
              {
                case 0:
                  v11 = TPanel::get_string(10611);
                  goto LABEL_24;
                case 1:
                  v11 = TPanel::get_string(10612);
                  goto LABEL_24;
                case 2:
                  v11 = TPanel::get_string(10613);
                  goto LABEL_24;
                case 3:
                  v11 = TPanel::get_string(10614);
                  goto LABEL_24;
                case 4:
                  v11 = TPanel::get_string(10615);
                  goto LABEL_24;
                case 5:
                  v11 = TPanel::get_string(10616);
LABEL_24:
                  strcpy(str1, v11);
                  break;
                default:
                  break;
              }
              v12 = TPanel::get_string(9690);
              sprintf(str2, v12, str1);
              (*(void (__stdcall **)(char *))&v1->settingText[v9]->vfptr[1].gap4[4])(str2);
              (*(void (__stdcall **)(signed int))&v1->settingText[v9]->vfptr->gap10[4])(1);
              v13 = v9 + 1;
              switch ( TRIBE_Game::mapType((TRIBE_Game *)rge_base_game) )
              {
                case 0:
                  v14 = TPanel::get_string(10602);
                  goto LABEL_35;
                case 1:
                  v14 = TPanel::get_string(10603);
                  goto LABEL_35;
                case 2:
                  v14 = TPanel::get_string(10604);
                  goto LABEL_35;
                case 3:
                  v14 = TPanel::get_string(10605);
                  goto LABEL_35;
                case 4:
                  v14 = TPanel::get_string(10606);
                  goto LABEL_35;
                case 5:
                  v14 = TPanel::get_string(10607);
                  goto LABEL_35;
                case 6:
                  v14 = TPanel::get_string(10608);
                  goto LABEL_35;
                case 7:
                  v14 = TPanel::get_string(10609);
                  goto LABEL_35;
                case 8:
                  v14 = TPanel::get_string(10610);
LABEL_35:
                  strcpy(str1, v14);
                  break;
                default:
                  break;
              }
              v15 = TPanel::get_string(9654);
              sprintf(str2, v15, str1);
              (*(void (__stdcall **)(char *))&v1->settingText[v13]->vfptr[1].gap4[4])(str2);
              (*(void (__stdcall **)(signed int))&v1->settingText[v13]->vfptr->gap10[4])(1);
              v9 = v13 + 1;
            }
            v16 = v9 + 1;
            switch ( TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) )
            {
              case 1:
                v20 = TPanel::get_string(4321);
                break;
              case 7:
                v17 = TPanel::get_string(4329);
                goto LABEL_41;
              case 8:
                v17 = TPanel::get_string(4330);
LABEL_41:
                strcpy(str1, v17);
                v18 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
                v19 = TPanel::get_string(9662);
                sprintf(str2, v19, str1, v18);
                goto LABEL_46;
              default:
                if ( RGE_Base_Game::randomGame(rge_base_game) )
                  goto LABEL_43;
                v20 = TPanel::get_string(4327);
                break;
              case 9:
LABEL_43:
                v20 = TPanel::get_string(4332);
                break;
            }
            strcpy(str1, v20);
            v21 = TPanel::get_string(9660);
            sprintf(str2, v21, str1);
LABEL_46:
            (*(void (__stdcall **)(char *))&v1->settingText[v16]->vfptr[1].gap4[4])(str2);
            (*(void (__stdcall **)(signed int))&v1->settingText[v16]->vfptr->gap10[4])(1);
            v22 = v16 + 1;
            v23 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
            if ( v23 )
            {
              if ( v23 == 1 )
              {
                v46 = str1;
                v45 = 4206;
              }
              else
              {
                v46 = str1;
                v45 = v23 + 4199;
              }
            }
            else
            {
              v46 = str1;
              v45 = 4327;
            }
            TPanel::get_string(v45, v46, 256);
            v24 = TPanel::get_string(9700);
            sprintf(str2, v24, str1);
            (*(void (__stdcall **)(char *, int))&v1->settingText[v22]->vfptr[1].gap4[4])(str2, v48);
            (*(void (__stdcall **)(signed int))&v1->settingText[v22]->vfptr->gap10[4])(1);
            v25 = v22 + 1;
            v26 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
            if ( v26 )
              TPanel::get_string(v26 + 9701, &str1[4], 256);
            else
              TPanel::get_string(4327, &str1[4], 256);
            v27 = TPanel::get_string(9701);
            sprintf(&str2[4], v27, &str1[4]);
            (*(void (__stdcall **)(char *))&v1->settingText[v25]->vfptr[1].gap4[4])(&str2[4]);
            (*(void (__stdcall **)(signed int))&v1->settingText[v25]->vfptr->gap10[4])(1);
            v28 = v25 + 1;
            RGE_Base_Game::difficulty(rge_base_game);
            v29 = RGE_Base_Game::difficulty(rge_base_game);
            TPanel::get_string(v29 + 11216, &str1[4], 256);
            TPanel::get_string(9696, &str2[4], 256);
            sprintf(&str3[4], &str2[4], &str1[4]);
            (*(void (__stdcall **)(char *))&v1->settingText[v28]->vfptr[1].gap4[4])(&str3[4]);
            (*(void (__stdcall **)(signed int))&v1->settingText[v28]->vfptr->gap10[4])(1);
            v30 = v28 + 1;
            if ( TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game) )
              TPanel::get_string(4004, &str1[4], 256);
            else
              TPanel::get_string(4003, &str1[4], 256);
            v31 = TPanel::get_string(9705);
            sprintf(&str2[4], v31, &str1[4]);
            (*(void (__cdecl **)(char *))&v1->settingText[v30]->vfptr[1].gap4[4])(&str2[4]);
            (*(void (__stdcall **)(signed int))&v1->settingText[v30]->vfptr->gap10[4])(1);
            v32 = v30 + 1;
            if ( RGE_Base_Game::fullVisibility(rge_base_game) )
              v33 = TPanel::get_string(4003);
            else
              v33 = TPanel::get_string(4004);
            strcpy(str1, v33);
            v34 = TPanel::get_string(9656);
            sprintf(str2, v34, str1);
            (*(void (__stdcall **)(char *, int))&v1->settingText[v32]->vfptr[1].gap4[4])(str2, v49);
            (*(void (__stdcall **)(signed int))&v1->settingText[v32]->vfptr->gap10[4])(1);
            v35 = v32 + 1;
            if ( TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game) )
              TPanel::get_string(4003, &str1[4], 256);
            else
              TPanel::get_string(4004, &str1[4], 256);
            v36 = TPanel::get_string(9708);
            sprintf(&str2[4], v36, &str1[4]);
            (*(void (__cdecl **)(char *))&v1->settingText[v35]->vfptr[1].gap4[4])(&str2[4]);
            (*(void (__stdcall **)(signed int))&v1->settingText[v35]->vfptr->gap10[4])(1);
            v37 = v35 + 1;
            if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
            {
              if ( RGE_Base_Game::allowCheatCodes(rge_base_game) )
                v38 = TPanel::get_string(4003);
              else
                v38 = TPanel::get_string(4004);
              strcpy(str1, v38);
              v39 = TPanel::get_string(9659);
              sprintf(str2, v39, str1);
              (*(void (__stdcall **)(char *))&v1->settingText[v37]->vfptr[1].gap4[4])(str2);
              (*(void (__stdcall **)(signed int))&v1->settingText[v37++]->vfptr->gap10[4])(1);
            }
            if ( RGE_Base_Game::multiplayerGame(rge_base_game) )
            {
              v47 = str1;
              v40 = RGE_Base_Game::mpPathFinding(rge_base_game);
            }
            else
            {
              v47 = str1;
              v40 = RGE_Base_Game::pathFinding(rge_base_game);
            }
            TPanel::get_string((unsigned __int8)v40 + 9742, v47, 256);
            v41 = TPanel::get_string(9713);
            sprintf(str2, v41, str1);
            (*(void (__stdcall **)(char *))&v1->settingText[v37]->vfptr[1].gap4[4])(str2);
            (*(void (__stdcall **)(signed int))&v1->settingText[v37]->vfptr->gap10[4])(1);
            v42 = v37 + 1;
            v43 = (unsigned __int8)TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
            v44 = TPanel::get_string(9712);
            sprintf(str2, v44, v43);
            (*(void (__stdcall **)(char *))&v1->settingText[v42]->vfptr[1].gap4[4])(str2);
            (*(void (__stdcall **)(signed int))&v1->settingText[v42]->vfptr->gap10[4])(1);
            return;
          }
        }
      }
    }
  }
  else
  {
    v1->error_code = 1;
  }
}
// 5733F0: using guessed type int (__thiscall *TRIBE_Screen_Wait::`vftable')(void *Memory, unsigned int __flags);

//----- (004A6030) --------------------------------------------------------
TRIBE_Screen_Wait *__thiscall TRIBE_Screen_Wait::`vector deleting destructor'(TRIBE_Screen_Wait *this, unsigned int __flags)
{
  TRIBE_Screen_Wait *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Wait::~TRIBE_Screen_Wait(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A6050) --------------------------------------------------------
void __thiscall TRIBE_Screen_Wait::~TRIBE_Screen_Wait(TRIBE_Screen_Wait *this)
{
  TRIBE_Screen_Wait *v1; // esi@1
  TPanel **v2; // edi@1
  signed int v3; // ebx@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Wait::`vftable';
  TPanel::delete_panel((TPanel **)&this->message);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TPanel::delete_panel((TPanel **)&v1->scenarioName);
  v2 = (TPanel **)v1->settingText;
  v3 = 20;
  do
  {
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 5733F0: using guessed type int (__thiscall *TRIBE_Screen_Wait::`vftable')(void *Memory, unsigned int __flags);

//----- (004A60E0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Wait::set_text(TRIBE_Screen_Wait *this, char *message_in)
{
  (*(void (__stdcall **)(_DWORD))&this->message->vfptr[1].gap4[4])(message_in);
}

//----- (004A6100) --------------------------------------------------------
void __thiscall TRIBE_Screen_Wait::set_text(TRIBE_Screen_Wait *this, int message_in)
{
  (*(void (__stdcall **)(_DWORD))&this->message->vfptr[1].gap4[0])(message_in);
}

//----- (004A6120) --------------------------------------------------------
int __thiscall TRIBE_Screen_Wait::action(TRIBE_Screen_Wait *this, TPanel *from_panel, int action_in, unsigned int val1, unsigned int val2)
{
  int result; // eax@4

  if ( from_panel && from_panel == (TPanel *)this->close_button && action_in == 1 )
  {
    RGE_Base_Game::close(rge_base_game);
    result = 1;
  }
  else
  {
    result = TEasy_Panel::action((TEasy_Panel *)&this->vfptr, from_panel, action_in, val1, val2);
  }
  return result;
}

//----- (004A6170) --------------------------------------------------------
int __thiscall TRIBE_Screen_Wait::handle_idle(TRIBE_Screen_Wait *this)
{
  TRIBE_Screen_Wait *v1; // esi@1

  v1 = this;
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}
