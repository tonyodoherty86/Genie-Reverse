
//----- (00471EC0) --------------------------------------------------------
void __thiscall TButtonPanel::TButtonPanel(TButtonPanel *this)
{
  TButtonPanel *v1; // esi@1
  TButtonPanel *v2; // edx@1
  int v3; // eax@1
  signed int v4; // edi@1

  v1 = this;
  TPanel::TPanel((TPanel *)this);
  *((_DWORD *)v1 + 79) = 1;
  *((_DWORD *)v1 + 80) = 1;
  *((_DWORD *)v1 + 81) = 1;
  *((_DWORD *)v1 + 97) = 1;
  *((_DWORD *)v1 + 100) = 1;
  *((_DWORD *)v1 + 120) = -1;
  *((_DWORD *)v1 + 121) = -1;
  *((_WORD *)v1 + 250) = 1;
  *((_DWORD *)v1 + 168) = 1;
  *((_DWORD *)v1 + 173) = -1;
  *((_DWORD *)v1 + 82) = 0;
  *((_DWORD *)v1 + 98) = 0;
  *((_DWORD *)v1 + 99) = 0;
  *((_DWORD *)v1 + 101) = 0;
  *((_DWORD *)v1 + 122) = 0;
  *((_DWORD *)v1 + 123) = 0;
  *((_DWORD *)v1 + 124) = 0;
  *((_WORD *)v1 + 251) = 0;
  *((_DWORD *)v1 + 126) = 0;
  *((_DWORD *)v1 + 127) = 0;
  *((_WORD *)v1 + 256) = 0;
  *((_DWORD *)v1 + 129) = 0;
  *((_DWORD *)v1 + 166) = 0;
  *((_DWORD *)v1 + 167) = 0;
  *((_BYTE *)v1 + 676) = 0;
  *((_BYTE *)v1 + 677) = 0;
  *((_BYTE *)v1 + 678) = 0;
  *((_BYTE *)v1 + 679) = 0;
  *((_BYTE *)v1 + 680) = 0;
  *((_BYTE *)v1 + 681) = 0;
  *((_DWORD *)v1 + 171) = 0;
  *((_DWORD *)v1 + 172) = 0;
  *(_DWORD *)v1 = &TButtonPanel::`vftable';
  *((_BYTE *)v1 + 238) = 3;
  v2 = (TButtonPanel *)((char *)v1 + 368);
  v3 = (int)v1 + 280;
  v4 = 9;
  do
  {
    *(_DWORD *)(v3 - 36) = 0;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 52) = 0;
    *(_WORD *)v2 = -1;
    *(_DWORD *)(v3 + 128) = 0;
    *(_DWORD *)(v3 + 164) = 0;
    *(_DWORD *)(v3 + 240) = 0xFFFFFF;
    *(_DWORD *)(v3 + 276) = 0;
    *(_DWORD *)(v3 + 312) = 0xFFFF;
    *(_DWORD *)(v3 + 348) = 0;
    v2 = (TButtonPanel *)((char *)v2 + 2);
    v3 += 4;
    --v4;
  }
  while ( v4 );
}
// 570FC8: using guessed type int (__thiscall *TButtonPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00472010) --------------------------------------------------------
TButtonPanel *__thiscall TButtonPanel::`vector deleting destructor'(TButtonPanel *this, unsigned int __flags)
{
  TButtonPanel *v2; // esi@1

  v2 = this;
  TButtonPanel::~TButtonPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00472030) --------------------------------------------------------
void __thiscall TButtonPanel::~TButtonPanel(TButtonPanel *this)
{
  TButtonPanel *v1; // ebp@1
  signed int v2; // ebx@1
  void **v3; // esi@1

  v1 = this;
  v2 = 9;
  *(_DWORD *)this = &TButtonPanel::`vftable';
  v3 = (void **)((char *)this + 444);
  do
  {
    if ( *(v3 - 9) )
    {
      free(*(v3 - 9));
      *(v3 - 9) = 0;
    }
    if ( *v3 )
    {
      free(*v3);
      *v3 = 0;
    }
    ++v3;
    --v2;
  }
  while ( v2 );
  if ( *((_DWORD *)v1 + 127) )
  {
    free(*((void **)v1 + 127));
    *((_DWORD *)v1 + 127) = 0;
  }
  TPanel::~TPanel((TPanel *)v1);
}
// 570FC8: using guessed type int (__thiscall *TButtonPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (004720A0) --------------------------------------------------------
signed int __thiscall TButtonPanel::setup(TPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, TPanel *a8, TDigital *sound_in, TPanel *notifyTypeIn, int id_in)
{
  TPanel *v11; // esi@1

  v11 = this;
  TPanel::setup(this, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  v11[1].bottom_panel = notifyTypeIn;
  v11[1].right_panel = a8;
  TButtonPanel::set_sound((TButtonPanel *)v11, sound_in);
  TButtonPanel::set_id((TButtonPanel *)v11, 0, id_in, 0);
  return 1;
}

//----- (00472110) --------------------------------------------------------
TButtonPanel::ButtonType __thiscall TButtonPanel::buttonType(TButtonPanel *this)
{
  return *((_DWORD *)this + 79);
}

//----- (00472120) --------------------------------------------------------
int __thiscall TButtonPanel::drawType(int this)
{
  return *(_DWORD *)(this + 320);
}

//----- (00472130) --------------------------------------------------------
TButtonPanel::NotifyType __thiscall TButtonPanel::notifyType(TButtonPanel *this)
{
  return *((_DWORD *)this + 81);
}

//----- (00472140) --------------------------------------------------------
int __thiscall TButtonPanel::setDrawType(int this, int a2)
{
  int result; // eax@1

  result = a2;
  *(_DWORD *)(this + 320) = a2;
  return result;
}

//----- (00472150) --------------------------------------------------------
void __thiscall TButtonPanel::setButtonType(TButtonPanel *this, TButtonPanel::ButtonType buttonTypeIn)
{
  *((_DWORD *)this + 79) = buttonTypeIn;
}

//----- (00472160) --------------------------------------------------------
void __thiscall TButtonPanel::set_picture_info(TButtonPanel *this, TShape *pic_in, __int16 pic_index_in, int pic_x_in, int pic_y_in, int all_hot_in, int auto_pic_pos_in)
{
  *((_DWORD *)this + 98) = pic_x_in;
  *((_DWORD *)this + 99) = pic_y_in;
  *((_DWORD *)this + 100) = all_hot_in;
  *((_DWORD *)this + 97) = auto_pic_pos_in;
  TButtonPanel::set_picture(this, 0, pic_in, pic_index_in);
}

//----- (004721A0) --------------------------------------------------------
void __thiscall TButtonPanel::set_text_info(TButtonPanel *this, char *text_in, void *font_in, int font_wid_in, int font_hgt_in, int text_x_in, int text_y_in)
{
  TButtonPanel *v7; // esi@1

  v7 = this;
  TButtonPanel::set_text_pos(this, text_x_in, text_y_in);
  TButtonPanel::set_text(v7, 0, text_in);
  TButtonPanel::set_font(v7, font_in, font_wid_in, font_hgt_in);
}

//----- (004721E0) --------------------------------------------------------
void __thiscall TButtonPanel::set_text_info(TButtonPanel *this, int string_id_in, void *font_in, int font_wid_in, int font_hgt_in, int text_x_in, int text_y_in)
{
  TButtonPanel *v7; // esi@1

  v7 = this;
  TButtonPanel::set_text_pos(this, text_x_in, text_y_in);
  TButtonPanel::set_text(v7, 0, string_id_in);
  TButtonPanel::set_font(v7, font_in, font_wid_in, font_hgt_in);
}

//----- (00472220) --------------------------------------------------------
void __thiscall TButtonPanel::set_text_pos(TButtonPanel *this, int text_x_in, int text_y_in)
{
  int v3; // eax@1

  *((_DWORD *)this + 120) = text_x_in;
  v3 = *(_DWORD *)this;
  *((_DWORD *)this + 121) = text_y_in;
  (*(void (__stdcall **)(signed int))(v3 + 32))(1);
}

//----- (00472240) --------------------------------------------------------
void __thiscall TButtonPanel::set_radio_info(TButtonPanel *this, TButtonPanel **buttons_in, __int16 button_count_in)
{
  TButtonPanel *v3; // esi@1
  void *v4; // eax@1
  int v5; // eax@5
  int v6; // ecx@5

  v3 = this;
  v4 = (void *)*((_DWORD *)this + 127);
  *((_DWORD *)this + 79) = 2;
  if ( v4 )
  {
    free(v4);
    *((_DWORD *)v3 + 127) = 0;
  }
  if ( button_count_in )
  {
    *((_WORD *)v3 + 256) = button_count_in;
    *((_DWORD *)v3 + 127) = calloc(button_count_in, 4u);
    if ( button_count_in > 0 )
    {
      v5 = 0;
      v6 = button_count_in;
      do
      {
        *(_DWORD *)(*((_DWORD *)v3 + 127) + v5 * 4) = buttons_in[v5];
        ++v5;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (004722C0) --------------------------------------------------------
void __thiscall TButtonPanel::set_state_info(TButtonPanel *this, __int16 num_states_in)
{
  *((_DWORD *)this + 79) = 3;
  *((_WORD *)this + 250) = num_states_in;
}

//----- (004722E0) --------------------------------------------------------
void __thiscall TButtonPanel::set_id(TButtonPanel *this, __int16 state_in, int id_in, int id2_in)
{
  int v4; // eax@1

  v4 = state_in;
  *((_DWORD *)this + v4 + 61) = id_in;
  *((_DWORD *)this + v4 + 70) = id2_in;
}

//----- (00472300) --------------------------------------------------------
void __thiscall TButtonPanel::set_picture(TButtonPanel *this, __int16 state_in, TShape *pic_in, __int16 pic_index_in)
{
  int v4; // eax@1

  v4 = state_in;
  *((_DWORD *)this + v4 + 83) = pic_in;
  *((_WORD *)this + v4 + 184) = pic_index_in;
  (*(void (__stdcall **)(signed int))(*(_DWORD *)this + 32))(1);
}

//----- (00472330) --------------------------------------------------------
void __thiscall TButtonPanel::set_text(TButtonPanel *this, __int16 state_in, char *text_in)
{
  TButtonPanel *v3; // ebp@1
  char *v4; // eax@7
  char *v5; // ebx@7
  __int16 v6; // cx@8
  size_t v7; // edi@10
  char *v8; // eax@10
  const char *v9; // ebx@12
  char *v10; // edx@12

  v3 = this;
  if ( *((_DWORD *)this + state_in + 102) )
  {
    free(*((void **)this + state_in + 102));
    *((_DWORD *)v3 + state_in + 102) = 0;
  }
  if ( *((_DWORD *)v3 + state_in + 111) )
  {
    free(*((void **)v3 + state_in + 111));
    *((_DWORD *)v3 + state_in + 111) = 0;
  }
  if ( text_in && *text_in )
  {
    v4 = strchr(text_in, 10);
    v5 = v4;
    if ( v4 )
      v6 = (_WORD)v4 - (_WORD)text_in;
    else
      v6 = strlen(text_in);
    v7 = v6;
    v8 = (char *)calloc(v6 + 1, 1u);
    *((_DWORD *)v3 + state_in + 102) = v8;
    if ( v8 )
    {
      strncpy(v8, text_in, v7);
      *(_BYTE *)(v7 + *((_DWORD *)v3 + state_in + 102)) = 0;
      if ( v5 )
      {
        v9 = v5 + 1;
        v10 = (char *)calloc(strlen(v9) + 1, 1u);
        *((_DWORD *)v3 + state_in + 111) = v10;
        if ( v10 )
          strcpy(v10, v9);
      }
    }
  }
  (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v3 + 32))(v3, 1);
}

//----- (00472440) --------------------------------------------------------
void __thiscall TButtonPanel::set_text(TButtonPanel *this, __int16 state_in, char *text1_in, char *text2_in)
{
  TButtonPanel *v4; // ebp@1
  char *v5; // edx@7
  char *v6; // edx@10

  v4 = this;
  if ( *((_DWORD *)this + state_in + 102) )
  {
    free(*((void **)this + state_in + 102));
    *((_DWORD *)v4 + state_in + 102) = 0;
  }
  if ( *((_DWORD *)v4 + state_in + 111) )
  {
    free(*((void **)v4 + state_in + 111));
    *((_DWORD *)v4 + state_in + 111) = 0;
  }
  if ( text1_in )
  {
    if ( *text1_in )
    {
      v5 = (char *)calloc(strlen(text1_in) + 1, 1u);
      *((_DWORD *)v4 + state_in + 102) = v5;
      if ( v5 )
      {
        strcpy(v5, text1_in);
        if ( text2_in )
        {
          if ( *text2_in )
          {
            v6 = (char *)calloc(strlen(text2_in) + 1, 1u);
            *((_DWORD *)v4 + state_in + 111) = v6;
            if ( v6 )
              strcpy(v6, text2_in);
          }
        }
      }
    }
  }
  (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v4 + 32))(v4, 1);
}

//----- (00472540) --------------------------------------------------------
void __thiscall TButtonPanel::set_text(TButtonPanel *this, __int16 state_in, int string_id_in)
{
  TButtonPanel *v3; // esi@1
  char str[256]; // [sp+4h] [bp-100h]@1

  v3 = this;
  TPanel::get_string(string_id_in, str, 256);
  TButtonPanel::set_text(v3, state_in, str);
}

//----- (00472580) --------------------------------------------------------
void __thiscall TButtonPanel::set_text(TButtonPanel *this, __int16 state_in, int string_id1_in, int string_id2_in)
{
  TButtonPanel *v4; // esi@1
  char str2[256]; // [sp+4h] [bp-200h]@1
  char str1[256]; // [sp+104h] [bp-100h]@1

  v4 = this;
  TPanel::get_string(string_id1_in, str1, 256);
  TPanel::get_string(string_id2_in, str2, 256);
  TButtonPanel::set_text(v4, state_in, str1, str2);
}

//----- (004725F0) --------------------------------------------------------
void __thiscall TButtonPanel::set_font(TButtonPanel *this, void *font_in, int font_wid_in, int font_hgt_in)
{
  int v4; // edx@1

  *((_DWORD *)this + 122) = font_in;
  *((_DWORD *)this + 123) = font_wid_in;
  v4 = *(_DWORD *)this;
  *((_DWORD *)this + 124) = font_hgt_in;
  (*(void (__stdcall **)(signed int))(v4 + 32))(1);
}

//----- (00472620) --------------------------------------------------------
void __thiscall TButtonPanel::set_text_color(TButtonPanel *this, int state, unsigned int text_color1_in, unsigned int text_color2_in)
{
  if ( state >= 0 && state <= 8 )
  {
    *((_DWORD *)this + state + 130) = text_color1_in;
    *((_DWORD *)this + state + 139) = text_color2_in;
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)this + 32))(1);
  }
}

//----- (00472650) --------------------------------------------------------
void __thiscall TButtonPanel::set_highlight_text_color(TButtonPanel *this, int state, unsigned int text_color1_in, unsigned int text_color2_in)
{
  if ( state >= 0 && state <= 8 )
  {
    *((_DWORD *)this + state + 148) = text_color1_in;
    *((_DWORD *)this + state + 157) = text_color2_in;
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)this + 32))(1);
  }
}

//----- (00472680) --------------------------------------------------------
void __thiscall TButtonPanel::set_sound(TButtonPanel *this, TDigital *sound_in)
{
  *((_DWORD *)this + 82) = sound_in;
}

//----- (00472690) --------------------------------------------------------
void __thiscall TButtonPanel::set_radio_button(TButtonPanel *this)
{
  TButtonPanel *v1; // esi@1
  signed int i; // edi@1
  int v3; // eax@3

  v1 = this;
  for ( i = 0;
        i < *((_WORD *)v1 + 256);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)v1 + 127) + 4 * i++) + 224))(0) )
  {
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 127) + 4 * i) + 504) = 0;
  }
  v3 = *((_DWORD *)v1 + 80);
  if ( v3 == 3 || v3 == 5 )
    *((_DWORD *)v1 + 126) = 1;
  (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v1 + 224))(v1, 1);
}

//----- (00472700) --------------------------------------------------------
void __thiscall TButtonPanel::set_state(TButtonPanel *this, __int16 state_in)
{
  int v2; // edx@1

  v2 = *(_DWORD *)this;
  *((_WORD *)this + 251) = state_in;
  (*(void (__stdcall **)(signed int))(v2 + 32))(1);
}

//----- (00472720) --------------------------------------------------------
void __thiscall TButtonPanel::set_state_by_id(TButtonPanel *this, int id_in)
{
  int v2; // esi@1
  int v3; // eax@1
  char *v4; // edx@2

  v2 = *((_WORD *)this + 250);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = (char *)this + 244;
    while ( *(_DWORD *)v4 != id_in )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        return;
    }
    *((_WORD *)this + 251) = v3;
    (*(void (__stdcall **)(signed int))(*(_DWORD *)this + 32))(1);
  }
}

//----- (00472760) --------------------------------------------------------
void __thiscall TButtonPanel::set_bevel_info(TButtonPanel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  *((_DWORD *)this + 168) = bevel_type_in;
  *((_BYTE *)this + 676) = c1;
  *((_BYTE *)this + 677) = c2;
  *((_BYTE *)this + 678) = c3;
  *((_BYTE *)this + 679) = c4;
  *((_BYTE *)this + 680) = c5;
  *((_BYTE *)this + 681) = c6;
}

//----- (004727B0) --------------------------------------------------------
void __thiscall TButtonPanel::set_disabled(TButtonPanel *this, int val)
{
  TButtonPanel *v2; // esi@1
  int v3; // edx@1

  v2 = this;
  v3 = *(_DWORD *)this;
  *((_DWORD *)this + 172) = val;
  (*(void (__stdcall **)(signed int))(v3 + 32))(1);
  if ( *((_DWORD *)v2 + 172) )
    *((_DWORD *)v2 + 32) = 0;
  else
    *((_DWORD *)v2 + 32) = 1;
}

//----- (004727F0) --------------------------------------------------------
void __thiscall TButtonPanel::set_rect(TButtonPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  TPanel::set_rect((TPanel *)this, x_in, y_in, wid_in, hgt_in);
}

//----- (00472810) --------------------------------------------------------
int __thiscall TButtonPanel::get_state(TButtonPanel *this)
{
  return *((_WORD *)this + 251);
}

//----- (00472820) --------------------------------------------------------
int __thiscall TButtonPanel::get_id(TButtonPanel *this)
{
  return *((_DWORD *)this + *((_WORD *)this + 251) + 61);
}

//----- (00472830) --------------------------------------------------------
int __thiscall TButtonPanel::get_id2(TButtonPanel *this)
{
  return *((_DWORD *)this + *((_WORD *)this + 251) + 70);
}

//----- (00472840) --------------------------------------------------------
BOOL __thiscall TButtonPanel::get_text(TButtonPanel *this, __int16 state_in, char **text1_in, char **text2_in)
{
  __int16 v4; // ax@1

  v4 = state_in;
  if ( state_in == -1 )
    v4 = *((_WORD *)this + 251);
  *text1_in = (char *)*((_DWORD *)this + v4 + 102);
  *text2_in = (char *)*((_DWORD *)this + v4 + 111);
  return *text1_in != 0;
}

//----- (00472880) --------------------------------------------------------
void __thiscall TButtonPanel::get_text_color(TButtonPanel *this, __int16 state_in, unsigned int *color1, unsigned int *color2)
{
  __int16 v4; // ax@1

  v4 = state_in;
  if ( state_in == -1 )
    v4 = *((_WORD *)this + 251);
  *color1 = *((_DWORD *)this + v4 + 130);
  *color2 = *((_DWORD *)this + v4 + 139);
}

//----- (004728C0) --------------------------------------------------------
void __thiscall TButtonPanel::draw(TButtonPanel *this)
{
  TButtonPanel *v1; // esi@1
  TDrawArea *v2; // ecx@1
  int v3; // eax@4
  int v4; // ecx@7
  signed int v5; // eax@8
  int v6; // edi@13
  int v7; // eax@13
  int v8; // eax@17
  TShape *v9; // ecx@17
  int v10; // eax@19
  int v11; // ecx@20
  int v12; // eax@20
  int v13; // eax@27
  void *v14; // eax@30
  void *v15; // ebx@30
  int v16; // ebp@32
  int v17; // eax@34
  int v18; // eax@36
  const char *v19; // edx@36
  int v20; // edi@40
  int v21; // ecx@40
  int v22; // ebp@41
  int v23; // ebp@43
  int v24; // ST1C_4@49
  void (__stdcall *v25)(HDC, int, int, LPCSTR, int); // ebp@49
  const char *v26; // edx@51
  int v27; // edi@55
  int v28; // eax@64
  char *text; // [sp+10h] [bp-30h]@37
  char *texta; // [sp+10h] [bp-30h]@52
  int y; // [sp+14h] [bp-2Ch]@36
  int ya; // [sp+14h] [bp-2Ch]@55
  int x; // [sp+18h] [bp-28h]@40
  int xa; // [sp+18h] [bp-28h]@55
  int calc_x; // [sp+1Ch] [bp-24h]@32
  int x_max; // [sp+20h] [bp-20h]@19
  int x_min; // [sp+24h] [bp-1Ch]@19
  int y_max; // [sp+28h] [bp-18h]@19
  int y_min; // [sp+2Ch] [bp-14h]@19
  void *old_font; // [sp+30h] [bp-10h]@31
  int v41; // [sp+34h] [bp-Ch]@13
  tagSIZE text_size; // [sp+38h] [bp-8h]@40

  v1 = this;
  v2 = (TDrawArea *)*((_DWORD *)this + 8);
  if ( v2 )
  {
    if ( *((_DWORD *)v1 + 28) )
    {
      if ( *((_DWORD *)v1 + 27) )
      {
        v3 = *((_DWORD *)v1 + 80);
        if ( v3 != 1 )
        {
          if ( v3 == 5 )
          {
            TDrawArea::Clear(v2, (tagRECT *)((char *)v1 + 36), *((_BYTE *)v1 + 239));
          }
          else
          {
            v4 = *((_DWORD *)v1 + 16);
            if ( v4 )
            {
              v5 = *((_DWORD *)v1 + 168);
              if ( v5 < 2 || v5 > 4 )
              {
                if ( !*(_DWORD *)(v4 + 132) )
                  (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 52))((int)v1 + 36);
              }
              else
              {
                (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 60))((int)v1 + 36);
              }
            }
          }
          v6 = *(_DWORD *)v1;
          v41 = v6;
          (*(void (__thiscall **)(TButtonPanel *, _DWORD))(v6 + 40))(v1, 0);
          v7 = *((_DWORD *)v1 + 80);
          if ( v7 != 2 && v7 != 4 && v7 != 6 || !TDrawArea::Lock(*((TDrawArea **)v1 + 8), aPnl_btnDraw, 1) )
          {
LABEL_27:
            v13 = *((_DWORD *)v1 + 80);
            if ( v13 != 3 && v13 != 4 && v13 != 5
              || (v14 = TDrawArea::GetDc(*((TDrawArea **)v1 + 8), aPnl_btnDraw), (v15 = v14) == 0) )
            {
LABEL_64:
              v28 = *((_DWORD *)v1 + 80);
              if ( v28 != 3 && v28 != 4 && v28 != 5 && v28 != 6
                || !TDrawArea::Lock(*((TDrawArea **)v1 + 8), aPnl_btnDraw2, 1) )
              {
                goto LABEL_87;
              }
              if ( *((_DWORD *)v1 + 172) )
              {
                TDrawArea::DrawRect(
                  *((TDrawArea **)v1 + 8),
                  *((_DWORD *)v1 + 3),
                  *((_DWORD *)v1 + 4),
                  *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                  *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                  *((_BYTE *)v1 + 681));
                TDrawArea::DrawRect(
                  *((TDrawArea **)v1 + 8),
                  *((_DWORD *)v1 + 3) + 1,
                  *((_DWORD *)v1 + 4) + 1,
                  *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 2,
                  *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 2,
                  *((_BYTE *)v1 + 676));
LABEL_86:
                TDrawArea::Unlock(*((TDrawArea **)v1 + 8), aPnl_btnDraw2);
LABEL_87:
                (*(void (__thiscall **)(TButtonPanel *))(v6 + 44))(v1);
                return;
              }
              if ( *((_DWORD *)v1 + 101) )
              {
                if ( *((_DWORD *)v1 + 126) )
                  goto LABEL_80;
              }
              else if ( !*((_DWORD *)v1 + 126) )
              {
LABEL_80:
                switch ( *((_DWORD *)v1 + 168) )
                {
                  case 1:
                    TDrawArea::DrawVertLine(
                      *((TDrawArea **)v1 + 8),
                      *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                      *((_DWORD *)v1 + 4) + 1,
                      *((_DWORD *)v1 + 6) - 1,
                      0);
                    TDrawArea::DrawHorzLine(
                      *((TDrawArea **)v1 + 8),
                      *((_DWORD *)v1 + 3) + 1,
                      *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                      *((_DWORD *)v1 + 5) - 1,
                      0);
                    TDrawArea::DrawRect(
                      *((TDrawArea **)v1 + 8),
                      *((_DWORD *)v1 + 3),
                      *((_DWORD *)v1 + 4),
                      *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 2,
                      *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 2,
                      -1);
                    break;
                  case 2:
                    TDrawArea::DrawBevel(
                      *((TDrawArea **)v1 + 8),
                      *((_DWORD *)v1 + 3),
                      *((_DWORD *)v1 + 4),
                      *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                      *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                      *((_BYTE *)v1 + 676),
                      *((_BYTE *)v1 + 681));
                    break;
                  case 3:
                    TDrawArea::DrawBevel2(
                      *((TDrawArea **)v1 + 8),
                      *((_DWORD *)v1 + 3),
                      *((_DWORD *)v1 + 4),
                      *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                      *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                      *((_BYTE *)v1 + 676),
                      *((_BYTE *)v1 + 677),
                      *((_BYTE *)v1 + 680),
                      *((_BYTE *)v1 + 681));
                    break;
                  case 4:
                    TDrawArea::DrawBevel3(
                      *((TDrawArea **)v1 + 8),
                      *((_DWORD *)v1 + 3),
                      *((_DWORD *)v1 + 4),
                      *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                      *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                      *((_BYTE *)v1 + 676),
                      *((_BYTE *)v1 + 677),
                      *((_BYTE *)v1 + 678),
                      *((_BYTE *)v1 + 679),
                      *((_BYTE *)v1 + 680),
                      *((_BYTE *)v1 + 681));
                    break;
                  default:
                    goto LABEL_86;
                }
                goto LABEL_86;
              }
              switch ( *((_DWORD *)v1 + 168) )
              {
                case 1:
                  TDrawArea::DrawRect(
                    *((TDrawArea **)v1 + 8),
                    *((_DWORD *)v1 + 3) + 1,
                    *((_DWORD *)v1 + 4) + 1,
                    *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 2,
                    *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 2,
                    -1);
                  break;
                case 2:
                  TDrawArea::DrawBevel(
                    *((TDrawArea **)v1 + 8),
                    *((_DWORD *)v1 + 3),
                    *((_DWORD *)v1 + 4),
                    *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                    *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                    *((_BYTE *)v1 + 681),
                    *((_BYTE *)v1 + 676));
                  break;
                case 3:
                  TDrawArea::DrawBevel21(
                    *((TDrawArea **)v1 + 8),
                    *((_DWORD *)v1 + 3),
                    *((_DWORD *)v1 + 4),
                    *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                    *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                    *((_BYTE *)v1 + 681),
                    *((_BYTE *)v1 + 680),
                    *((_BYTE *)v1 + 677),
                    *((_BYTE *)v1 + 676));
                  break;
                case 4:
                  TDrawArea::DrawBevel32(
                    *((TDrawArea **)v1 + 8),
                    *((_DWORD *)v1 + 3),
                    *((_DWORD *)v1 + 4),
                    *((_DWORD *)v1 + 5) + *((_DWORD *)v1 + 3) - 1,
                    *((_DWORD *)v1 + 6) + *((_DWORD *)v1 + 4) - 1,
                    *((_BYTE *)v1 + 681),
                    *((_BYTE *)v1 + 680),
                    *((_BYTE *)v1 + 679),
                    *((_BYTE *)v1 + 678),
                    *((_BYTE *)v1 + 677),
                    *((_BYTE *)v1 + 676));
                  break;
                default:
                  goto LABEL_86;
              }
              goto LABEL_86;
            }
            SelectClipRgn(v14, *((HRGN *)v1 + 34));
            old_font = SelectObject(v15, *((HGDIOBJ *)v1 + 122));
            SetBkMode(v15, 1);
            if ( *((_DWORD *)v1 + 120) == -1 )
            {
              v16 = *((_DWORD *)v1 + 5) / 2;
              calc_x = *((_DWORD *)v1 + 5) / 2;
            }
            else
            {
              calc_x = *((_DWORD *)v1 + 120);
              v16 = *((_DWORD *)v1 + 120);
            }
            v17 = *((_DWORD *)v1 + 121);
            if ( v17 == -1 )
              v17 = *((_DWORD *)v1 + 6) / 2;
            y = v17;
            v18 = *((_WORD *)v1 + 251);
            v19 = (const char *)*((_DWORD *)v1 + v18 + 102);
            if ( v19 )
            {
              text = (char *)*((_DWORD *)v1 + v18 + 102);
            }
            else
            {
              text = (char *)*((_DWORD *)v1 + 102);
              v19 = (const char *)*((_DWORD *)v1 + 102);
            }
            if ( !v19 )
            {
LABEL_63:
              SelectObject(v15, old_font);
              SelectClipRgn(v15, 0);
              TDrawArea::ReleaseDc(*((TDrawArea **)v1 + 8), aPnl_btnDraw);
              v6 = v41;
              goto LABEL_64;
            }
            x = (signed __int16)strlen(v19);
            GetTextExtentPoint32A(v15, (LPCSTR)v19, x, &text_size);
            v20 = *((_DWORD *)v1 + 3) + v16 - text_size.cx / 2;
            v21 = *((_WORD *)v1 + 251);
            if ( *((_DWORD *)v1 + v21 + 111) )
              v22 = y - *((_DWORD *)v1 + 124);
            else
              v22 = y - *((_DWORD *)v1 + 124) / 2;
            v23 = *((_DWORD *)v1 + 4) + v22;
            if ( *((_DWORD *)v1 + 101) )
            {
              if ( *((_DWORD *)v1 + 126) )
                goto LABEL_48;
            }
            else if ( !*((_DWORD *)v1 + 126) )
            {
LABEL_48:
              if ( *((_DWORD *)v1 + 30) )
              {
                SetTextColor(v15, *((_DWORD *)v1 + v21 + 157));
                TextOutA(v15, v20 - 1, v23 + 1, text, x);
                SetTextColor(v15, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 148));
                v24 = v23;
                v25 = (void (__stdcall *)(HDC, int, int, LPCSTR, int))TextOutA;
                TextOutA(v15, v20, v24, text, x);
              }
              else
              {
                SetTextColor(v15, *((_DWORD *)v1 + v21 + 139));
                TextOutA(v15, v20 - 1, v23 + 1, text, x);
                SetTextColor(v15, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 130));
                TextOutA(v15, v20, v23, text, x);
                v25 = (void (__stdcall *)(HDC, int, int, LPCSTR, int))TextOutA;
              }
              v26 = (const char *)*((_DWORD *)v1 + *((_WORD *)v1 + 251) + 111);
              if ( v26 )
              {
                texta = (char *)*((_DWORD *)v1 + *((_WORD *)v1 + 251) + 111);
              }
              else
              {
                texta = (char *)*((_DWORD *)v1 + 111);
                v26 = (const char *)*((_DWORD *)v1 + 111);
              }
              if ( !v26 )
                goto LABEL_63;
              v27 = (signed __int16)strlen(v26);
              GetTextExtentPoint32A(v15, (LPCSTR)v26, v27, &text_size);
              xa = *((_DWORD *)v1 + 3) + calc_x - text_size.cx / 2;
              ya = *((_DWORD *)v1 + 4) + y;
              if ( *((_DWORD *)v1 + 101) )
              {
                if ( *((_DWORD *)v1 + 126) )
                  goto LABEL_60;
              }
              else if ( !*((_DWORD *)v1 + 126) )
              {
LABEL_60:
                if ( *((_DWORD *)v1 + 30) )
                {
                  SetTextColor(v15, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 157));
                  v25(v15, xa - 1, ya + 1, texta, v27);
                  SetTextColor(v15, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 148));
                  v25(v15, xa, ya, texta, v27);
                }
                else
                {
                  SetTextColor(v15, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 139));
                  v25(v15, xa - 1, ya + 1, texta, v27);
                  SetTextColor(v15, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 130));
                  v25(v15, xa, ya, texta, v27);
                }
                goto LABEL_63;
              }
              ++xa;
              --ya;
              goto LABEL_60;
            }
            ++v20;
            --v23;
            goto LABEL_48;
          }
          v8 = *((_WORD *)v1 + 251);
          v9 = (TShape *)*((_DWORD *)v1 + v8 + 83);
          if ( !v9 )
          {
LABEL_26:
            TDrawArea::Unlock(*((TDrawArea **)v1 + 8), aPnl_btnDraw);
            goto LABEL_27;
          }
          if ( *((_DWORD *)v1 + 97) )
          {
            TShape::shape_minmax(v9, &x_min, &y_min, &x_max, &y_max, *((_WORD *)v1 + v8 + 184));
            v10 = y_max;
            *((_DWORD *)v1 + 98) = (signed __int16)(*((_DWORD *)v1 + 5) / 2 - (x_max - x_min + 1) / 2 - x_min);
            *((_DWORD *)v1 + 99) = (signed __int16)(*((_DWORD *)v1 + 6) / 2 - (v10 - y_min + 1) / 2 - y_min);
          }
          v11 = *((_DWORD *)v1 + 4) + *((_DWORD *)v1 + 99);
          v12 = *((_DWORD *)v1 + 3) + *((_DWORD *)v1 + 98);
          if ( *((_DWORD *)v1 + 101) )
          {
            if ( *((_DWORD *)v1 + 126) )
            {
LABEL_25:
              TShape::shape_draw(
                *((TShape **)v1 + *((_WORD *)v1 + 251) + 83),
                *((TDrawArea **)v1 + 8),
                v12,
                v11,
                *((_WORD *)v1 + *((_WORD *)v1 + 251) + 184),
                0,
                0);
              goto LABEL_26;
            }
          }
          else if ( !*((_DWORD *)v1 + 126) )
          {
            goto LABEL_25;
          }
          ++v12;
          --v11;
          goto LABEL_25;
        }
      }
    }
  }
  *((_DWORD *)v1 + 14) = 0;
}

//----- (00473120) --------------------------------------------------------
int __thiscall TButtonPanel::handle_mouse_down(TButtonPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v6; // esi@1
  int result; // eax@2

  v6 = this;
  if ( *((_DWORD *)this + 27) )
  {
    if ( *((_DWORD *)this + 26) )
    {
      result = 0;
    }
    else
    {
      result = (*(int (__stdcall **)(int, int))(*(_DWORD *)this + 228))(x, y);
      if ( result )
        result = TPanel::handle_mouse_down((TPanel *)v6, mouse_button_in, x, y, ctrl_key, shift_key);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00473180) --------------------------------------------------------
int __stdcall TButtonPanel::mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00473190) --------------------------------------------------------
int __thiscall TButtonPanel::mouse_left_down_action(TButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v5; // esi@1
  int result; // eax@2
  TDigital *v7; // ecx@3
  int v8; // ecx@7

  v5 = this;
  if ( *((_DWORD *)this + 172) )
  {
    result = 0;
  }
  else
  {
    v7 = (TDigital *)*((_DWORD *)this + 82);
    if ( v7 )
    {
      if ( TDigital::is_playing(v7) )
        TDigital::stop(*((TDigital **)v5 + 82));
      TDigital::play(*((TDigital **)v5 + 82));
    }
    TPanel::capture_mouse((TPanel *)v5);
    *((_DWORD *)v5 + 126) = 1;
    *((_DWORD *)v5 + 129) = debug_timeGetTime();
    (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v5 + 32))(v5, 1);
    v8 = *((_DWORD *)v5 + 16);
    if ( v8 )
      (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 180))(
        v5,
        2,
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 61),
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 70));
    result = 1;
  }
  return result;
}

//----- (00473240) --------------------------------------------------------
int __thiscall TButtonPanel::mouse_left_move_action(TButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v5; // esi@1
  int v6; // edi@1
  int v7; // eax@1
  int v8; // ecx@4

  v5 = this;
  v6 = *(_DWORD *)this;
  v7 = (*(int (__stdcall **)(int, int))(*(_DWORD *)this + 188))(x, y) != 0;
  if ( *((_DWORD *)v5 + 126) != v7 )
  {
    *((_DWORD *)v5 + 126) = v7;
    if ( v7 )
      *((_DWORD *)v5 + 129) = debug_timeGetTime();
    (*(void (__thiscall **)(TButtonPanel *, signed int))(v6 + 32))(v5, 1);
    v8 = *((_DWORD *)v5 + 16);
    if ( *((_DWORD *)v5 + 126) )
    {
      if ( v8 )
      {
        (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 180))(
          v5,
          2,
          *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 61),
          *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 70));
        return 1;
      }
    }
    else if ( v8 )
    {
      (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 180))(
        v5,
        3,
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 61),
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 70));
    }
  }
  return 1;
}

//----- (00473310) --------------------------------------------------------
int __thiscall TButtonPanel::mouse_left_up_action(TButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v5; // esi@1
  int v6; // eax@1
  int result; // eax@4
  int v8; // eax@7

  v5 = this;
  TPanel::release_mouse((TPanel *)this);
  v6 = *((_DWORD *)v5 + 79);
  if ( *((_DWORD *)v5 + 126) )
  {
    if ( v6 != 2 )
      *((_DWORD *)v5 + 126) = 0;
    (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v5 + 32))(v5, 1);
    SendMessageA(*(HWND *)(*((_DWORD *)v5 + 8) + 4), 0xFu, 0, 0);
    TButtonPanel::do_action(v5);
    result = 1;
  }
  else
  {
    if ( v6 == 2 && *((_WORD *)v5 + 251) == 1 )
    {
      v8 = *(_DWORD *)v5;
      *((_DWORD *)v5 + 126) = 1;
      (*(void (__thiscall **)(TButtonPanel *, signed int))(v8 + 32))(v5, 1);
    }
    result = 1;
  }
  return result;
}

//----- (00473390) --------------------------------------------------------
int __stdcall TButtonPanel::mouse_right_dbl_click_action(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (004733A0) --------------------------------------------------------
int __thiscall TButtonPanel::mouse_right_down_action(TButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v5; // esi@1
  int result; // eax@2
  TDigital *v7; // ecx@3
  int v8; // ecx@7

  v5 = this;
  if ( *((_DWORD *)this + 172) )
  {
    result = 0;
  }
  else
  {
    v7 = (TDigital *)*((_DWORD *)this + 82);
    if ( v7 )
    {
      if ( TDigital::is_playing(v7) )
        TDigital::stop(*((TDigital **)v5 + 82));
      TDigital::play(*((TDigital **)v5 + 82));
    }
    TPanel::capture_mouse((TPanel *)v5);
    *((_DWORD *)v5 + 126) = 1;
    *((_DWORD *)v5 + 129) = debug_timeGetTime();
    (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v5 + 32))(v5, 1);
    v8 = *((_DWORD *)v5 + 16);
    if ( v8 )
      (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 180))(
        v5,
        5,
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 61),
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 70));
    result = 1;
  }
  return result;
}

//----- (00473450) --------------------------------------------------------
int __thiscall TButtonPanel::mouse_right_move_action(TButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v5; // esi@1
  int v6; // edi@1
  int v7; // eax@1
  int v8; // ecx@4

  v5 = this;
  v6 = *(_DWORD *)this;
  v7 = (*(int (__stdcall **)(int, int))(*(_DWORD *)this + 188))(x, y) != 0;
  if ( *((_DWORD *)v5 + 126) != v7 )
  {
    *((_DWORD *)v5 + 126) = v7;
    if ( v7 )
      *((_DWORD *)v5 + 129) = debug_timeGetTime();
    (*(void (__thiscall **)(TButtonPanel *, signed int))(v6 + 32))(v5, 1);
    v8 = *((_DWORD *)v5 + 16);
    if ( *((_DWORD *)v5 + 126) )
    {
      if ( v8 )
      {
        (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 180))(
          v5,
          5,
          *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 61),
          *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 70));
        return 1;
      }
    }
    else if ( v8 )
    {
      (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 180))(
        v5,
        6,
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 61),
        *((_DWORD *)v5 + *((_WORD *)v5 + 251) + 70));
    }
  }
  return 1;
}

//----- (00473520) --------------------------------------------------------
int __thiscall TButtonPanel::mouse_right_up_action(TButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TButtonPanel *v5; // esi@1
  int v6; // eax@1
  int result; // eax@4
  int v8; // edx@7

  v5 = this;
  TPanel::release_mouse((TPanel *)this);
  v6 = *((_DWORD *)v5 + 79);
  if ( *((_DWORD *)v5 + 126) )
  {
    if ( v6 != 2 )
      *((_DWORD *)v5 + 126) = 0;
    (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v5 + 32))(v5, 1);
    SendMessageA(*(HWND *)(*((_DWORD *)v5 + 8) + 4), 0xFu, 0, 0);
    TButtonPanel::do_right_action(v5, shift_key);
    result = 1;
  }
  else
  {
    if ( v6 == 2 && *((_WORD *)v5 + 251) == 1 )
    {
      v8 = *(_DWORD *)v5;
      *((_DWORD *)v5 + 126) = 1;
      (*(void (__thiscall **)(TButtonPanel *, signed int))(v8 + 32))(v5, 1);
    }
    result = 1;
  }
  return result;
}

//----- (004735B0) --------------------------------------------------------
int __thiscall TButtonPanel::handle_key_down(TButtonPanel *this, int key, int count, int alt_key, int ctrl_key, int shift_key)
{
  TButtonPanel *v6; // esi@1
  int v7; // eax@5
  int v8; // eax@8
  TPanel *v9; // ecx@11
  TDigital *v10; // ecx@14
  int v11; // ecx@18
  int result; // eax@20

  v6 = this;
  if ( !*((_DWORD *)this + 27)
    || *((_DWORD *)this + 172)
    || alt_key
    || ctrl_key
    || (v7 = *((_DWORD *)this + 166)) == 0
    || key != v7
    || *((_DWORD *)this + 171)
    || (v8 = *((_DWORD *)this + 167)) != 0 && shift_key != v8 )
  {
    result = TPanel::handle_key_down((TPanel *)this, key, count, alt_key, ctrl_key, shift_key);
  }
  else
  {
    if ( *((_DWORD *)this + 29) )
    {
      v9 = (TPanel *)*((_DWORD *)this + 16);
      if ( v9 )
      {
        if ( !*((_DWORD *)v6 + 30) )
          TPanel::set_curr_child(v9, (TPanel *)v6);
      }
    }
    v10 = (TDigital *)*((_DWORD *)v6 + 82);
    if ( v10 )
    {
      if ( TDigital::is_playing(v10) )
        TDigital::stop(*((TDigital **)v6 + 82));
      TDigital::play(*((TDigital **)v6 + 82));
    }
    *((_DWORD *)v6 + 171) = key;
    *((_DWORD *)v6 + 126) = 1;
    *((_DWORD *)v6 + 129) = debug_timeGetTime();
    (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v6 + 32))(v6, 1);
    v11 = *((_DWORD *)v6 + 16);
    if ( v11 )
      (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v11 + 180))(
        v6,
        2,
        *((_DWORD *)v6 + *((_WORD *)v6 + 251) + 61),
        *((_DWORD *)v6 + *((_WORD *)v6 + 251) + 70));
    result = 1;
  }
  return result;
}

//----- (004736F0) --------------------------------------------------------
int __thiscall TButtonPanel::key_down_action(TButtonPanel *this, int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  TButtonPanel *v6; // esi@1
  TPanel *v7; // ecx@6
  TPanel *v8; // esi@7
  int result; // eax@14
  TDigital *v10; // ecx@18
  unsigned int v11; // eax@22
  int v12; // edx@22
  int v13; // ecx@22

  v6 = this;
  if ( *((_DWORD *)this + 171) )
  {
LABEL_25:
    result = 0;
  }
  else
  {
    switch ( key )
    {
      case 40:
        if ( alt_key )
          goto LABEL_24;
        if ( ctrl_key )
          goto LABEL_24;
        if ( !*((_DWORD *)this + 29) )
          goto LABEL_24;
        v7 = (TPanel *)*((_DWORD *)this + 16);
        if ( !v7 )
          goto LABEL_24;
        v8 = (TPanel *)*((_DWORD *)v6 + 25);
        goto LABEL_13;
      case 38:
        if ( alt_key )
          goto LABEL_24;
        if ( ctrl_key )
          goto LABEL_24;
        if ( !*((_DWORD *)this + 29) )
          goto LABEL_24;
        v7 = (TPanel *)*((_DWORD *)this + 16);
        if ( !v7 )
          goto LABEL_24;
        v8 = (TPanel *)*((_DWORD *)v6 + 24);
LABEL_13:
        if ( !v8 )
          goto LABEL_24;
        TPanel::set_curr_child(v7, v8);
        result = 1;
        break;
      case 13:
      case 32:
        if ( *((_DWORD *)this + 172) || alt_key || ctrl_key )
          goto LABEL_25;
        v10 = (TDigital *)*((_DWORD *)this + 82);
        if ( v10 )
        {
          if ( TDigital::is_playing(v10) )
            TDigital::stop(*((TDigital **)v6 + 82));
          TDigital::play(*((TDigital **)v6 + 82));
        }
        *((_DWORD *)v6 + 171) = key;
        *((_DWORD *)v6 + 126) = 1;
        v11 = debug_timeGetTime();
        v12 = *(_DWORD *)v6;
        *((_DWORD *)v6 + 129) = v11;
        (*(void (__thiscall **)(TButtonPanel *, signed int))(v12 + 32))(v6, 1);
        v13 = *((_DWORD *)v6 + 16);
        if ( v13 )
          (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v13 + 180))(
            v6,
            2,
            *((_DWORD *)v6 + *((_WORD *)v6 + 251) + 61),
            *((_DWORD *)v6 + *((_WORD *)v6 + 251) + 70));
LABEL_24:
        result = 1;
        break;
      default:
        goto LABEL_25;
    }
  }
  return result;
}

//----- (00473890) --------------------------------------------------------
int __thiscall TButtonPanel::wnd_proc(TButtonPanel *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
  TButtonPanel *v5; // esi@1
  int v6; // eax@2
  int v7; // eax@4
  int result; // eax@6

  v5 = this;
  if ( msg == 257 && (v6 = *((_DWORD *)this + 171)) != 0 && wParam == v6 )
  {
    v7 = *((_DWORD *)this + 79);
    *((_DWORD *)this + 171) = 0;
    if ( v7 != 2 )
      *((_DWORD *)this + 126) = 0;
    (*(void (__fastcall **)(TButtonPanel *, unsigned int, signed int))(*(_DWORD *)this + 32))(this, wParam, 1);
    SendMessageA(*(HWND *)(*((_DWORD *)v5 + 8) + 4), 0xFu, 0, 0);
    TButtonPanel::do_action(v5);
    result = 1;
  }
  else
  {
    result = TPanel::wnd_proc((TPanel *)this, hwnd, msg, wParam, lParam);
  }
  return result;
}

//----- (00473920) --------------------------------------------------------
int __stdcall TButtonPanel::char_action(int key, __int16 count)
{
  return 0;
}

//----- (00473930) --------------------------------------------------------
int __thiscall TButtonPanel::hit_button(TButtonPanel *this, int x, int y)
{
  TButtonPanel *v3; // esi@1
  int result; // eax@1
  int v5; // eax@3
  TShape *v6; // ecx@3

  v3 = this;
  result = (*(int (__stdcall **)(int, int))(*(_DWORD *)this + 188))(x, y);
  if ( result )
  {
    if ( *((_DWORD *)v3 + 100) || (v5 = *((_WORD *)v3 + 251), (v6 = (TShape *)*((_DWORD *)v3 + v5 + 83)) == 0) )
      result = 1;
    else
      result = TShape::shape_check(
                 v6,
                 x - *((_DWORD *)v3 + 98) - *((_DWORD *)v3 + 3),
                 y - *((_DWORD *)v3 + 99) - *((_DWORD *)v3 + 4),
                 *((_WORD *)v3 + v5 + 184)) != 0;
  }
  return result;
}

//----- (004739B0) --------------------------------------------------------
void __thiscall TButtonPanel::do_action(TButtonPanel *this)
{
  TButtonPanel *v1; // esi@1
  int v2; // eax@1
  int v3; // ecx@7
  int v4; // ecx@10
  int v5; // eax@12
  WPARAM v6; // ecx@12

  v1 = this;
  v2 = *((_DWORD *)this + 79);
  if ( v2 == 3 )
  {
    if ( *((_WORD *)this + 251) == *((_WORD *)this + 250) - 1 )
    {
      (*(void (__thiscall **)(TButtonPanel *, _DWORD))(*(_DWORD *)this + 224))(this, 0);
    }
    else
    {
      LOWORD(v2) = *((_WORD *)this + 251);
      (*(void (__thiscall **)(TButtonPanel *, int))(*(_DWORD *)this + 224))(this, v2 + 1);
    }
  }
  else if ( v2 == 2 )
  {
    TButtonPanel::set_radio_button(this);
  }
  v3 = *((_DWORD *)v1 + 16);
  if ( v3 )
    (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v3 + 180))(
      v1,
      3,
      *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 61),
      *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 70));
  if ( *((_DWORD *)v1 + 81) == 1 )
  {
    v4 = *((_DWORD *)v1 + 16);
    if ( v4 )
      (*(void (__stdcall **)(TButtonPanel *, signed int, _DWORD, _DWORD))(*(_DWORD *)v4 + 180))(
        v1,
        1,
        *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 61),
        *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 70));
  }
  else
  {
    v5 = *((_WORD *)v1 + 251);
    v6 = *((_DWORD *)v1 + v5 + 61);
    if ( v6 || *((_DWORD *)v1 + v5 + 70) )
      SendMessageA(*(HWND *)(*((_DWORD *)v1 + 8) + 4), 0x111u, v6, *((_DWORD *)v1 + v5 + 70));
  }
}

//----- (00473AA0) --------------------------------------------------------
void __thiscall TButtonPanel::do_right_action(TButtonPanel *this, int shift_key)
{
  TButtonPanel *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@7
  int v5; // ecx@7
  WPARAM v6; // edi@7
  LPARAM v7; // ebx@7
  int v8; // ecx@10
  int v9; // eax@12

  v2 = this;
  v3 = *((_DWORD *)this + 79);
  if ( v3 == 3 )
  {
    if ( *((_WORD *)this + 251) == *((_WORD *)this + 250) - 1 )
    {
      (*(void (__thiscall **)(TButtonPanel *, _DWORD))(*(_DWORD *)this + 224))(this, 0);
    }
    else
    {
      LOWORD(v3) = *((_WORD *)this + 251);
      (*(void (__thiscall **)(TButtonPanel *, int))(*(_DWORD *)this + 224))(this, v3 + 1);
    }
  }
  else if ( v3 == 2 )
  {
    TButtonPanel::set_radio_button(this);
  }
  v4 = *((_WORD *)v2 + 251);
  v5 = *((_DWORD *)v2 + 16);
  v6 = *((_DWORD *)v2 + v4 + 61);
  v7 = *((_DWORD *)v2 + v4 + 70);
  if ( v5 )
    (*(void (__stdcall **)(TButtonPanel *, signed int, WPARAM, LPARAM))(*(_DWORD *)v5 + 180))(v2, 6, v6, v7);
  if ( *((_DWORD *)v2 + 81) == 1 )
  {
    v8 = *((_DWORD *)v2 + 16);
    if ( v8 )
      (*(void (__stdcall **)(TButtonPanel *, signed int, WPARAM, LPARAM))(*(_DWORD *)v8 + 180))(v2, 4, v6, v7);
  }
  else
  {
    v9 = *((_WORD *)v2 + 251);
    if ( *((_DWORD *)v2 + v9 + 61) || *((_DWORD *)v2 + v9 + 70) )
      SendMessageA(*(HWND *)(*((_DWORD *)v2 + 8) + 4), 0x111u, v6, v7);
  }
}

//----- (00473B80) --------------------------------------------------------
void __thiscall TButtonPanel::reset(TButtonPanel *this)
{
  TButtonPanel *v1; // esi@1

  v1 = this;
  TPanel::release_mouse((TPanel *)this);
  if ( *((_DWORD *)v1 + 126) )
  {
    if ( *((_DWORD *)v1 + 79) != 2 )
      *((_DWORD *)v1 + 126) = 0;
    (*(void (__thiscall **)(TButtonPanel *, signed int))(*(_DWORD *)v1 + 32))(v1, 1);
  }
}

//----- (00473BB0) --------------------------------------------------------
void __thiscall TButtonPanel::set_sound_number(TButtonPanel *this, int sound_number_in)
{
  *((_DWORD *)this + 173) = sound_number_in;
}

//----- (00473BC0) --------------------------------------------------------
void __thiscall TButtonPanel::stop_sound_system(TButtonPanel *this)
{
  if ( *((_DWORD *)this + 82) )
    *((_DWORD *)this + 82) = 0;
}

//----- (00473BE0) --------------------------------------------------------
int __thiscall TButtonPanel::restart_sound_system(TButtonPanel *this)
{
  int v1; // eax@1

  v1 = *((_DWORD *)this + 173);
  if ( v1 != -1 )
    *((_DWORD *)this + 82) = RGE_Base_Game::get_sound(rge_base_game, v1);
  return 1;
}
