
//----- (00473ED0) --------------------------------------------------------
void __thiscall TDropDownPanel::TDropDownPanel(TDropDownPanel *this)
{
  TDropDownPanel *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->vfptr = (TPanelVtbl *)&TDropDownPanel::`vftable';
  v1->val_panel = 0;
  v1->btn_panel = 0;
  v1->list_panel = 0;
  v1->scbar_panel = 0;
  v1->mode = 0;
  v1->val_num = 0;
  v1->list_is_above = 0;
  v1->draw_style = 0;
  v1->panel_type = 6;
  v1->draw_val_rect = 1;
}
// 5711E0: using guessed type int (__thiscall *TDropDownPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00473F30) --------------------------------------------------------
TDropDownPanel *__thiscall TDropDownPanel::`scalar deleting destructor'(TDropDownPanel *this, unsigned int __flags)
{
  TDropDownPanel *v2; // esi@1

  v2 = this;
  TDropDownPanel::~TDropDownPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00473F50) --------------------------------------------------------
void __thiscall TDropDownPanel::~TDropDownPanel(TDropDownPanel *this)
{
  TDropDownPanel *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TDropDownPanel::`vftable';
  TPanel::delete_panel((TPanel **)&this->btn_panel);
  TPanel::delete_panel((TPanel **)&v1->list_panel);
  TPanel::delete_panel((TPanel **)&v1->scbar_panel);
  TPanel::delete_panel((TPanel **)&v1->val_panel);
  TPanel::~TPanel((TPanel *)&v1->vfptr);
}
// 5711E0: using guessed type int (__thiscall *TDropDownPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00473FD0) --------------------------------------------------------
void __thiscall TDropDownPanel::setup(TDropDownPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, void *font_in, int font_wid_in, int font_hgt_in, int fill_back_in, char back_color_in, int outline_in, int outline_color_in, int x_in, int y_in, int wid_in, int hgt_in, __int16 val_len_in, __int16 val_num_in, int btn_wid_in, int btn_hgt_in, char *btn_pic_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, int scbar_wid_in, char *scbar_back_pic_in, char *scbar_up_pic_in, char *scbar_down_pic_in, char *scbar_tab_pic_in, int scbar_arrow_hgt_in, int scbar_tab_hgt_in)
{
  TDropDownPanel *v30; // esi@1
  TTextPanel *v31; // eax@1
  TTextPanel *v32; // eax@2
  TDropDownButtonPanel *v33; // eax@6
  TPanel *v34; // eax@7
  TListPanel *v35; // eax@11
  TTextPanel *v36; // eax@12
  TScrollBarPanel *v37; // eax@16
  TScrollBarPanel *v38; // eax@17

  v30 = this;
  this->val_num = val_num_in;
  this->btn_wid = btn_wid_in;
  this->btn_hgt = btn_hgt_in;
  this->list_wid = list_wid_in;
  this->list_hgt = list_hgt_in;
  this->scbar_wid = scbar_wid_in;
  this->scbar_arrow_hgt = scbar_arrow_hgt_in;
  this->scbar_tab_hgt = scbar_tab_hgt_in;
  this->val_wid = wid_in - btn_wid_in - 1;
  this->val_hgt = hgt_in;
  this->outline_color = (unsigned __int8)outline_color_in;
  this->font_hgt = font_hgt_in;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  v31 = (TTextPanel *)operator new(0x188u);
  if ( v31 )
    TTextPanel::TTextPanel(v31);
  else
    v32 = 0;
  v30->val_panel = v32;
  if ( v32
    && TTextPanel::setup(
         v32,
         render_area_in,
         (TPanel *)&v30->vfptr,
         0,
         0,
         v30->val_wid,
         v30->val_hgt,
         font_in,
         font_wid_in,
         font_hgt_in,
         0,
         fill_back_in,
         back_color_in,
         outline_in,
         outline_color_in,
         val_len_in,
         list_in[v30->val_num]) )
  {
    TTextPanel::set_alignment(v30->val_panel, 0, AlignLeft);
    v33 = (TDropDownButtonPanel *)operator new(0x2BCu);
    if ( v33 )
      TDropDownButtonPanel::TDropDownButtonPanel(v33, v30);
    else
      v34 = 0;
    v30->btn_panel = (TButtonPanel *)v34;
    if ( v34
      && TButtonPanel::setup(
           v34,
           render_area_in,
           (TPanel *)&v30->vfptr,
           0,
           0,
           v30->btn_wid,
           v30->btn_hgt,
           (TPanel *)6,
           0,
           (TPanel *)1,
           0) )
    {
      v35 = (TListPanel *)operator new(0x1A0u);
      if ( v35 )
        TListPanel::TListPanel(v35);
      else
        v36 = 0;
      v30->list_panel = (TListPanel *)v36;
      if ( v36 )
      {
        if ( TTextPanel::setup(
               v36,
               render_area_in,
               (TPanel *)&v30->vfptr,
               0,
               0,
               v30->list_wid,
               v30->list_hgt,
               font_in,
               font_wid_in,
               font_hgt_in,
               0,
               fill_back_in,
               back_color_in,
               outline_in,
               outline_color_in,
               val_len_in,
               list_in,
               list_num_lines_in) )
        {
          TListPanel::set_auto_track(v30->list_panel, 1);
          (*(void (__stdcall **)(_DWORD))&v30->list_panel->vfptr->gap10[4])(0);
          TTextPanel::setCurrentLineNumber((TTextPanel *)&v30->list_panel->vfptr, v30->val_num);
          v37 = (TScrollBarPanel *)operator new(0x1C4u);
          if ( v37 )
            TScrollBarPanel::TScrollBarPanel(v37);
          else
            v38 = 0;
          v30->scbar_panel = v38;
          if ( v38 )
          {
            if ( TScrollBarPanel::setup(
                   v38,
                   v30->render_area,
                   (TPanel *)&v30->vfptr,
                   0,
                   0,
                   v30->scbar_wid,
                   v30->list_hgt,
                   message_in,
                   message_in,
                   message_in,
                   message_in,
                   v30->scbar_arrow_hgt,
                   v30->scbar_tab_hgt,
                   (TPanel *)&v30->list_panel->vfptr,
                   (signed __int16)list_num_lines_in,
                   0) )
            {
              TTextPanel::set_scrollbar((TTextPanel *)&v30->list_panel->vfptr, v30->scbar_panel, 0);
              (*(void (__stdcall **)(_DWORD))&v30->scbar_panel->vfptr->gap10[4])(0);
              TDropDownPanel::set_mode(v30, font_hgt_in, outline_color_in, (int)render_area_in, ModeValue);
            }
          }
        }
      }
    }
  }
}

//----- (00474350) --------------------------------------------------------
int __thiscall TDropDownPanel::handle_mouse_down(TDropDownPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TDropDownPanel *v6; // esi@1
  TPanel *v7; // ecx@2
  int v8; // eax@5
  TScrollBarPanel *v9; // ecx@5
  int v10; // ebp@5
  int v11; // eax@6
  int result; // eax@10

  v6 = this;
  if ( this->tab_stop )
  {
    v7 = this->parent_panel;
    if ( v7 )
      TPanel::set_curr_child(v7, (TPanel *)&v6->vfptr);
  }
  if ( v6->mode != 2
    || ((v8 = ((int (__stdcall *)(int, int))v6->list_panel->vfptr->is_inside)(x, y), v9 = v6->scbar_panel, v10 = v8, !v9) ? (v11 = 0) : (v11 = ((int (__stdcall *)(int, int))v9->vfptr->is_inside)(x, y)),
        v10 || v11) )
  {
    result = TPanel::handle_mouse_down((TPanel *)&v6->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
  }
  else
  {
    TDropDownPanel::set_mode(v6, x, 0, y, ModeValue);
    TDropDownPanel::set_line(v6, v6->val_num);
    result = 1;
  }
  return result;
}

//----- (00474400) --------------------------------------------------------
int __thiscall TDropDownPanel::handle_mouse_move(TDropDownPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  return TPanel::handle_mouse_move((TPanel *)&this->vfptr, x, y, ctrl_key, shift_key);
}

//----- (00474420) --------------------------------------------------------
int __thiscall TDropDownPanel::handle_mouse_up(TDropDownPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  return TPanel::handle_mouse_up((TPanel *)&this->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
}

//----- (00474450) --------------------------------------------------------
int __userpurge TDropDownPanel::handle_key_down@<eax>(TDropDownPanel *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int key, int count, int alt_key, int ctrl_key, int shift_key)
{
  int result; // eax@5

  if ( this->have_focus && (key == 40 || key == 38) && this->mode == 1 )
  {
    TDropDownPanel::set_mode(this, a2, a3, a4, ModeList);
    result = 1;
  }
  else
  {
    result = TPanel::handle_key_down((TPanel *)&this->vfptr, key, count, alt_key, ctrl_key, shift_key);
  }
  return result;
}

//----- (004744A0) --------------------------------------------------------
int __thiscall TDropDownPanel::action(TDropDownPanel *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  int v5; // ebp@1
  TDropDownPanel *v6; // esi@1
  TListPanel *v7; // ecx@5
  int *v8; // eax@8
  int v9; // ebp@8
  char *v10; // eax@8
  TPanel *v11; // ecx@8

  v5 = action_in;
  v6 = this;
  if ( from_panel == (TPanel *)this->btn_panel )
  {
    if ( action_in == 2 && this->mode == 1 )
      TDropDownPanel::set_mode(this, (int)from_panel, 2, action_val1, ModeList);
  }
  else
  {
    v7 = this->list_panel;
    if ( (TListPanel *)from_panel == v7 && (action_in == 3 || action_in == 2) )
    {
      v8 = (int *)v6->val_panel;
      v6->val_num = action_val1;
      v9 = *v8;
      v10 = TTextPanel::get_text((TTextPanel *)&v7->vfptr, (signed __int16)action_val1);
      (*(void (__thiscall **)(TTextPanel *, char *))(v9 + 232))(v6->val_panel, v10);
      TDropDownPanel::set_mode(v6, (int)from_panel, v9, action_val1, ModeValue);
      v11 = v6->parent_panel;
      if ( v11 )
        ((void (__stdcall *)(TDropDownPanel *, _DWORD, _DWORD, _DWORD))v11->vfptr->action)(v6, 0, 0, 0);
      v5 = action_in;
    }
  }
  return TPanel::action((TPanel *)&v6->vfptr, from_panel, v5, action_val1, action_val2);
}

//----- (00474550) --------------------------------------------------------
void __userpurge TDropDownPanel::set_rect(TDropDownPanel *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int x_in, int y_in, int wid_in, int hgt_in)
{
  TDropDownPanel *v8; // esi@1
  TDropDownPanel::DropdownMode v9; // eax@1
  int v10; // edx@2
  int v11; // ecx@4

  v8 = this;
  TPanel::set_rect((TPanel *)&this->vfptr, x_in, y_in, wid_in, hgt_in);
  v9 = v8->mode;
  if ( v9 == 1 )
  {
    v10 = v8->pnl_hgt;
    v8->val_wid = v8->pnl_wid - v8->btn_wid - 1;
    v8->val_hgt = v10;
    TDropDownPanel::set_mode(v8, a2, a3, a4, 0);
    TDropDownPanel::set_mode(v8, a2, a3, a4, ModeValue);
  }
  else if ( v9 == 2 )
  {
    v11 = v8->pnl_hgt;
    v8->list_wid = v8->pnl_wid;
    v8->list_hgt = v11 - v8->val_hgt - 1;
    TDropDownPanel::set_mode(v8, a2, a3, a4, ModeValue);
    TDropDownPanel::set_mode(v8, a2, a3, a4, ModeList);
  }
}

//----- (004745E0) --------------------------------------------------------
void __thiscall TDropDownPanel::set_val_text_color(TDropDownPanel *this, unsigned int text_color1_in, unsigned int text_color2_in)
{
  TTextPanel *v3; // ecx@1

  v3 = this->val_panel;
  if ( v3 )
    TTextPanel::set_text_color(v3, text_color1_in, text_color2_in);
}

//----- (00474600) --------------------------------------------------------
void __userpurge TDropDownPanel::set_draw_style(TDropDownPanel *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, TDropDownPanel::DrawStyle draw_style_in)
{
  TDropDownPanel::DropdownMode v5; // eax@2

  this->draw_style = draw_style_in;
  if ( this->val_panel )
  {
    v5 = this->mode;
    this->mode = 0;
    TDropDownPanel::set_mode(this, a2, a3, a4, v5);
  }
}

//----- (00474630) --------------------------------------------------------
void __thiscall TDropDownPanel::set_draw_val_rect(TDropDownPanel *this, int draw_val_rect_in)
{
  TDropDownPanel *v2; // esi@1
  TTextPanel *v3; // ecx@1

  v2 = this;
  v3 = this->val_panel;
  v2->draw_val_rect = draw_val_rect_in;
  if ( v3 )
  {
    TTextPanel::set_outline(v3, draw_val_rect_in, v2->outline_color);
    v2->vfptr->set_redraw((TPanel *)v2, RedrawNormal);
  }
}

//----- (00474670) --------------------------------------------------------
void __thiscall TDropDownPanel::set_bevel_info(TDropDownPanel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  int v8; // ebp@1
  TDropDownPanel *v9; // esi@1
  TTextPanel *v10; // ecx@1
  signed int v11; // eax@3
  TListPanel *v12; // ecx@9
  signed int v13; // eax@11
  TScrollBarPanel *v14; // ecx@17
  int v15; // eax@19
  TButtonPanel *v16; // ecx@25
  int v17; // eax@27

  v8 = c1;
  v9 = this;
  v10 = this->val_panel;
  if ( v10 )
  {
    switch ( bevel_type_in )
    {
      case 1:
        v11 = 1;
        break;
      case 2:
        v11 = 5;
        break;
      case 3:
        v11 = 6;
        break;
      case 4:
        v11 = 7;
        break;
      default:
        v11 = 0;
        break;
    }
    v8 = c1;
    ((void (__stdcall *)(signed int, int, int, int, int, int, int))v10->vfptr[1].set_rect)(v11, c1, c2, c3, c4, c5, c6);
  }
  v12 = v9->list_panel;
  if ( v12 )
  {
    switch ( bevel_type_in )
    {
      case 1:
        v13 = 1;
        break;
      case 2:
        v13 = 2;
        break;
      case 3:
        v13 = 3;
        break;
      case 4:
        v13 = 4;
        break;
      default:
        v13 = 0;
        break;
    }
    v8 = c1;
    ((void (__stdcall *)(signed int, int, int, int, int, int, int))v12->vfptr[1].set_rect)(v13, c1, c2, c3, c4, c5, c6);
  }
  v14 = v9->scbar_panel;
  if ( v14 )
  {
    switch ( bevel_type_in )
    {
      case 1:
        v15 = 1;
        break;
      case 2:
        v15 = 2;
        break;
      case 3:
        v15 = 3;
        break;
      case 4:
        v15 = 4;
        break;
      default:
        v15 = 0;
        break;
    }
    TScrollBarPanel::set_bevel_info(v14, v15, v8, c2, c3, c4, c5, c6);
  }
  v16 = v9->btn_panel;
  if ( v16 )
  {
    switch ( bevel_type_in )
    {
      case 1:
        v17 = 1;
        break;
      case 2:
        v17 = 2;
        break;
      case 3:
        v17 = 3;
        break;
      case 4:
        v17 = 4;
        break;
      default:
        v17 = 0;
        break;
    }
    TButtonPanel::set_bevel_info(v16, v17, v8, c2, c3, c4, c5, c6);
  }
}

//----- (00474820) --------------------------------------------------------
void __thiscall TDropDownPanel::set_buttons(TDropDownPanel *this, TShape *button_shape_in, int btn_frame_in, int scbar_back_frame_in, int scbar_up_frame_in, int scbar_down_frame_in, int scbar_tab_frame_in)
{
  TDropDownPanel *v7; // esi@1
  TButtonPanel *v8; // ecx@1
  TScrollBarPanel *v9; // ecx@5

  v7 = this;
  v8 = this->btn_panel;
  if ( v8 )
  {
    if ( button_shape_in )
      TButtonPanel::set_picture(v8, 0, button_shape_in, btn_frame_in);
    else
      TButtonPanel::set_picture(v8, 0, 0, -1);
  }
  v9 = v7->scbar_panel;
  if ( v9 )
    TScrollBarPanel::set_buttons(
      v9,
      button_shape_in,
      scbar_back_frame_in,
      scbar_up_frame_in,
      scbar_down_frame_in,
      scbar_tab_frame_in);
}

//----- (00474880) --------------------------------------------------------
void __userpurge TDropDownPanel::set_mode(TDropDownPanel *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, TDropDownPanel::DropdownMode mode_in)
{
  TDropDownPanel *v5; // esi@1
  TPanel *v6; // ecx@2
  int v7; // eax@3
  int v8; // ebp@3
  int v9; // eax@3
  int v10; // ebx@3
  int v11; // edi@3
  int v12; // eax@3
  TDrawArea *v13; // eax@4
  TDropDownPanel::DropdownMode v14; // ecx@5
  TPanel *v15; // ecx@7
  TPanel *v16; // ecx@8
  int v17; // eax@15
  int v18; // edx@15
  void *v19; // ebx@15
  TPanelVtbl *v20; // edi@15
  char v21; // dl@17
  TPanelVtbl *v22; // edi@17
  int v23; // ecx@17
  int v24; // eax@17
  int v25; // ST1E4_4@18
  int v26; // ST1E0_4@18
  int v27; // ST1E4_4@19
  int v28; // ST1E0_4@19
  TPanel *v29; // ecx@20
  TPanel *v30; // ecx@26
  TTextPanel *v31; // ecx@29
  int v32; // edi@29
  int v33; // edi@30
  int v34; // ebx@31
  int v35; // edi@32
  int v36; // eax@32
  TScrollBarPanel *v37; // ecx@32
  int v38; // eax@36
  int v39; // edx@36
  void *v40; // ebx@36
  TPanelVtbl *v41; // edi@36
  int v42; // ebx@38
  int v43; // edi@38
  int v44; // ST1DC_4@38
  void (__thiscall *v45)(TPanel *, int, int, int, int); // eax@38
  int v46; // ST1D4_4@38
  int v47; // ST1D0_4@38
  int v48; // ebp@38
  int v49; // ebp@39
  int v50; // ebp@39
  int v51; // eax@39
  TPanelVtbl *v52; // edx@41
  int v53; // ST1DC_4@41
  int v54; // ST1D8_4@41
  TTextPanel *v55; // ecx@41
  int v56; // edi@41
  int v57; // edi@42
  int v58; // ebx@43
  int v59; // ebx@45
  int v60; // eax@48
  int v61; // edx@48
  TButtonPanel *v62; // ebp@48
  TPanelVtbl *v63; // ebx@48
  TTextPanel *v64; // ebp@49
  int v65; // eax@51
  TPanelVtbl *v66; // edx@51
  TTextPanel *v67; // ecx@51
  int v68; // edi@51
  int v69; // edi@52
  int v70; // ebp@53
  int v71; // edi@54
  int v72; // ebp@55
  TPanel *v73; // ecx@59
  int v74; // [sp+1DCh] [bp-20h]@2
  int v75; // [sp+1E0h] [bp-1Ch]@2
  int v76; // [sp+1E0h] [bp-1Ch]@38
  int v77; // [sp+1E4h] [bp-18h]@2
  void *v78; // [sp+1E4h] [bp-18h]@38
  int v79; // [sp+1E8h] [bp-14h]@0
  int parent_y; // [sp+1ECh] [bp-10h]@3
  int parent_x; // [sp+1F0h] [bp-Ch]@3
  TDropDownPanel::DropdownMode save_mode; // [sp+1F4h] [bp-8h]@5
  void (__thiscall *calc_wid)(TPanel *, int, int, int, int); // [sp+1F8h] [bp-4h]@38
  int retaddr; // [sp+1FCh] [bp+0h]@38

  v5 = this;
  if ( mode_in != this->mode )
  {
    v6 = this->parent_panel;
    v77 = a4;
    v75 = a3;
    v74 = a2;
    if ( v6 )
    {
      v7 = TPanel::xPosition(v6);
      v8 = v7;
      parent_x = v7;
      v9 = TPanel::yPosition(v5->parent_panel);
      v10 = v9;
      parent_y = v9;
      v11 = TPanel::width(v5->parent_panel);
      v12 = TPanel::height(v5->parent_panel);
    }
    else
    {
      v13 = v5->render_area;
      parent_x = 0;
      parent_y = 0;
      v8 = 0;
      v11 = v13->Width;
      v12 = v13->Height;
      v10 = 0;
    }
    v14 = v5->mode;
    v5->mode = 0;
    save_mode = v14;
    if ( mode_in == 1 )
    {
      if ( v14 == 2 )
      {
        v15 = v5->parent_panel;
        if ( v15 )
        {
          v16 = v15->parent_panel;
          if ( v16 )
          {
            if ( v5->clip_rect.left < v8
              || v5->clip_rect.top < v10
              || v5->clip_rect.right > v11 + v8 - 1
              || v5->clip_rect.bottom > v12 + v10 - 1 )
            {
              ((void (__stdcall *)(signed int))v16->vfptr->set_redraw)(2);
            }
          }
        }
      }
      (*(void (__stdcall **)(_DWORD, int, int, int))&v5->list_panel->vfptr->gap10[4])(0, v74, v75, v77);
      (*(void (__stdcall **)(_DWORD))&v5->scbar_panel->vfptr->gap10[4])(0);
      if ( v5->draw_style == 1 )
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))(*(_DWORD *)v5->btn_panel + 24))(
          7,
          0,
          0,
          1,
          0,
          v5->btn_wid,
          v5->btn_wid,
          v5->btn_hgt,
          v5->btn_hgt,
          0,
          0,
          0,
          0,
          v79,
          parent_y,
          parent_x);
        v17 = v5->val_hgt;
        v18 = v5->val_wid;
        v19 = v5->btn_panel;
        v20 = v5->val_panel->vfptr;
      }
      else
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))&v5->val_panel->vfptr->gap10[8])(
          7,
          0,
          0,
          1,
          0,
          v5->val_wid,
          v5->val_wid,
          v5->val_hgt,
          v5->val_hgt,
          0,
          0,
          0,
          0,
          v79,
          parent_y,
          parent_x);
        v17 = v5->btn_hgt;
        v18 = v5->btn_wid;
        v19 = v5->val_panel;
        v20 = *(TPanelVtbl **)v5->btn_panel;
      }
      (*(void (__stdcall **)(signed int, signed int, _DWORD, _DWORD, _DWORD, int, int, int, int, void *, _DWORD, _DWORD))&v20->gap10[8])(
        7,
        1,
        0,
        0,
        0,
        v18,
        v18,
        v17,
        v17,
        v19,
        0,
        0);
      v21 = v5->list_is_above;
      v22 = v5->vfptr;
      v23 = v5->val_wid + v5->btn_wid + 1;
      v24 = v5->val_hgt;
      v5->clip_to_parent = 1;
      if ( v21 )
      {
        v25 = v5->pnl_hgt + v5->pnl_y - v24 - 1;
        v26 = v5->pnl_x - v8;
        ((void (__thiscall *)(TDropDownPanel *))v22->set_fixed_position)(v5);
        v5->list_is_above = 0;
      }
      else
      {
        v27 = v5->pnl_y - 1;
        v28 = v5->pnl_x - v8;
        ((void (__thiscall *)(TDropDownPanel *))v22->set_fixed_position)(v5);
      }
      v29 = v5->parent_panel;
      if ( v29 )
        ((void (__cdecl *)(signed int))v29->vfptr->set_redraw)(1);
      else
        ((void (__thiscall *)(TDropDownPanel *))v22->set_redraw)(v5);
      TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->val_panel->vfptr);
      if ( save_mode == 2 )
      {
        if ( !TPanelSystem::restorePreviousModalPanel(&panel_system) )
          TPanelSystem::setModalPanel(&panel_system, 0);
        v30 = v5->parent_panel;
        if ( v30 )
        {
          ((void (__stdcall *)(TDropDownPanel *, signed int, _DWORD, _DWORD))v30->vfptr->action)(v5, 2, 0, 0);
          v5->mode = 1;
          return;
        }
      }
    }
    else if ( mode_in == 2 )
    {
      (*(void (__stdcall **)(signed int, int, int, int))&v5->list_panel->vfptr->gap10[4])(1, v74, v75, v77);
      v31 = (TTextPanel *)&v5->list_panel->vfptr;
      v32 = v31->spacer_size;
      if ( v32 )
      {
        v34 = v31->border_size;
        v5->list_hgt = (v5->font_hgt + 2 * v32 + 1) * TTextPanel::numberLines(v31) + 2 * v34;
      }
      else
      {
        v33 = v31->border_size;
        v5->list_hgt = (v5->font_hgt + 2) * TTextPanel::numberLines(v31) + 2 * v33;
      }
      ((void (__stdcall *)(_DWORD, _DWORD, int, int))v5->list_panel->vfptr->set_fixed_position)(
        0,
        0,
        v5->list_wid,
        v5->list_hgt);
      v35 = TTextPanel::numberLines((TTextPanel *)&v5->list_panel->vfptr);
      v36 = TTextPanel::numberDrawLines((TTextPanel *)&v5->list_panel->vfptr);
      v37 = v5->scbar_panel;
      if ( v35 <= v36 )
        (*(void (__stdcall **)(_DWORD))&v37->vfptr->gap10[4])(0);
      else
        (*(void (__stdcall **)(signed int))&v37->vfptr->gap10[4])(1);
      if ( v5->draw_style == 1 )
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))(*(_DWORD *)v5->btn_panel + 24))(
          7,
          0,
          0,
          1,
          0,
          v5->btn_wid,
          v5->btn_wid,
          v5->btn_hgt,
          v5->btn_hgt,
          0,
          0,
          0,
          0,
          v79,
          parent_y,
          parent_x);
        v38 = v5->val_hgt;
        v39 = v5->val_wid;
        v40 = v5->btn_panel;
        v41 = v5->val_panel->vfptr;
      }
      else
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))&v5->val_panel->vfptr->gap10[8])(
          7,
          0,
          0,
          1,
          0,
          v5->val_wid,
          v5->val_wid,
          v5->val_hgt,
          v5->val_hgt,
          0,
          0,
          0,
          0,
          v79,
          parent_y,
          parent_x);
        v38 = v5->btn_hgt;
        v39 = v5->btn_wid;
        v40 = v5->val_panel;
        v41 = *(TPanelVtbl **)v5->btn_panel;
      }
      v78 = v40;
      v76 = v38;
      (*(void (__stdcall **)(signed int, signed int, _DWORD, _DWORD, _DWORD, int, int, int))&v41->gap10[8])(
        7,
        1,
        0,
        0,
        0,
        v39,
        v39,
        v38);
      (*(void (__stdcall **)(signed int, signed int, signed int, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, TTextPanel *, _DWORD, _DWORD))&v5->scbar_panel->vfptr->gap10[8])(
        10,
        1,
        1,
        0,
        0,
        v5->scbar_wid,
        v5->scbar_wid,
        0,
        0,
        0,
        v5->val_panel,
        0,
        0);
      (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *, TScrollBarPanel *, _DWORD))&v5->list_panel->vfptr->gap10[8])(
        8,
        0,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        v5->val_panel,
        v5->scbar_panel,
        0);
      v42 = v5->list_wid;
      v43 = v5->list_hgt + v5->val_hgt + 1;
      v44 = v5->list_hgt + v5->val_hgt + 1;
      v45 = v5->vfptr->set_fixed_position;
      v46 = v5->pnl_y;
      v47 = v5->pnl_x - v8;
      v5->clip_to_parent = 0;
      retaddr = v42;
      calc_wid = v45;
      v45((TPanel *)&v5->vfptr, v47, v46, v42, v44);
      v48 = TPanel::yPosition((TPanel *)&v5->list_panel->vfptr);
      if ( TPanel::height((TPanel *)&v5->list_panel->vfptr) + v48 > v5->render_area->Height - 4 )
      {
        v49 = TPanel::yPosition((TPanel *)&v5->list_panel->vfptr);
        v50 = 4 - v5->render_area->Height + TPanel::height((TPanel *)&v5->list_panel->vfptr) + v49;
        v51 = 4 - v5->pnl_y + TPanel::height((TPanel *)&v5->list_panel->vfptr);
        if ( v51 >= v50 )
        {
          v65 = v5->list_hgt - v50;
          v66 = v5->list_panel->vfptr;
          v5->list_hgt = v65;
          ((void (__stdcall *)(_DWORD, _DWORD, int, int, int, void *))v66->set_fixed_position)(
            0,
            0,
            v5->list_wid,
            v65,
            v76,
            v78);
          v67 = (TTextPanel *)&v5->list_panel->vfptr;
          v68 = v67->spacer_size;
          if ( v68 )
          {
            v70 = v67->border_size;
            v5->list_hgt = (v5->font_hgt + 2 * v68 + 1) * TTextPanel::numberDrawLines(v67) + 2 * v70;
          }
          else
          {
            v69 = v67->border_size;
            v5->list_hgt = (v5->font_hgt + 2) * TTextPanel::numberDrawLines(v67) + 2 * v69;
          }
          v71 = v5->list_hgt + v5->val_hgt + 1;
          if ( !v5->scbar_panel->active )
          {
            ((void (__stdcall *)(_DWORD, _DWORD, int, int))v5->list_panel->vfptr->set_fixed_position)(
              0,
              0,
              v5->list_wid,
              v5->list_hgt);
            v72 = TTextPanel::numberLines((TTextPanel *)&v5->list_panel->vfptr);
            if ( v72 > TTextPanel::numberDrawLines((TTextPanel *)&v5->list_panel->vfptr) )
              (*(void (__stdcall **)(signed int))&v5->scbar_panel->vfptr->gap10[4])(1);
            (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *, TScrollBarPanel *, _DWORD))&v5->list_panel->vfptr->gap10[8])(
              8,
              0,
              1,
              1,
              0,
              0,
              0,
              0,
              0,
              0,
              v5->val_panel,
              v5->scbar_panel,
              0);
          }
          ((void (__thiscall *)(TDropDownPanel *, int, int))v2)(v5, v5->pnl_x - retaddr, v5->pnl_y - (_DWORD)calc_wid);
        }
        else
        {
          if ( v51 > 0 )
          {
            v52 = v5->list_panel->vfptr;
            v53 = v5->list_hgt - v51;
            v54 = v5->list_wid;
            v5->list_hgt = v53;
            ((void (__stdcall *)(_DWORD, _DWORD, int, int))v52->set_fixed_position)(0, 0, v54, v53);
            v55 = (TTextPanel *)&v5->list_panel->vfptr;
            v56 = v55->spacer_size;
            if ( v56 )
            {
              v58 = v55->border_size;
              v5->list_hgt = (v5->font_hgt + 2 * v56 + 1) * TTextPanel::numberDrawLines(v55) + 2 * v58;
            }
            else
            {
              v57 = v55->border_size;
              v5->list_hgt = (v5->font_hgt + 2) * TTextPanel::numberDrawLines(v55) + 2 * v57;
            }
            v43 = v5->list_hgt + v5->val_hgt + 1;
            if ( !v5->scbar_panel->active )
            {
              ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v5->list_panel->vfptr->set_fixed_position)(
                0,
                0,
                v5->list_wid,
                v5->list_hgt);
              v59 = TTextPanel::numberLines((TTextPanel *)&v5->list_panel->vfptr);
              if ( v59 > TTextPanel::numberDrawLines((TTextPanel *)&v5->list_panel->vfptr) )
                (*(void (__stdcall **)(signed int))&v5->scbar_panel->vfptr->gap10[4])(1);
            }
          }
          if ( v5->draw_style == 1 )
          {
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, void *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5->btn_panel + 24))(
              8,
              0,
              0,
              1,
              0,
              v5->btn_wid,
              v5->btn_wid,
              v5->btn_hgt,
              v5->btn_hgt,
              0,
              0,
              0,
              0,
              v76,
              v78,
              0,
              0,
              0);
            v60 = v5->val_hgt;
            v61 = v5->val_wid;
            v62 = v5->btn_panel;
            v63 = v5->val_panel->vfptr;
          }
          else
          {
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, void *, _DWORD, _DWORD, _DWORD))&v5->val_panel->vfptr->gap10[8])(
              8,
              0,
              0,
              1,
              0,
              v5->val_wid,
              v5->val_wid,
              v5->val_hgt,
              v5->val_hgt,
              0,
              0,
              0,
              0,
              v76,
              v78,
              0,
              0,
              0);
            v60 = v5->btn_hgt;
            v61 = v5->btn_wid;
            v64 = v5->val_panel;
            v63 = *(TPanelVtbl **)v5->btn_panel;
          }
          (*(void (__stdcall **)(signed int, signed int, _DWORD, _DWORD, _DWORD, int, int, int))&v63->gap10[8])(
            8,
            1,
            0,
            0,
            0,
            v61,
            v61,
            v60);
          (*(void (__stdcall **)(signed int, signed int, signed int, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TTextPanel *))&v5->scbar_panel->vfptr->gap10[8])(
            9,
            1,
            1,
            0,
            0,
            v5->scbar_wid,
            v5->scbar_wid,
            0,
            0,
            0,
            0,
            0,
            v5->val_panel);
          (*(void (__stdcall **)(signed int, _DWORD, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, TScrollBarPanel *, TTextPanel *))&v5->list_panel->vfptr->gap10[8])(
            7,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            v5->scbar_panel,
            v5->val_panel);
          calc_wid((TPanel *)&v5->vfptr, v5->pnl_x - save_mode, v5->pnl_y + v5->val_hgt - v43, retaddr, v43);
          v5->list_is_above = 1;
        }
      }
      ((void (__thiscall *)(TDropDownPanel *))v5->vfptr->set_redraw)(v5);
      TPanel::set_z_order((TPanel *)&v5->vfptr, 1, 0);
      TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->list_panel->vfptr);
      TPanelSystem::setModalPanel(&panel_system, (TPanel *)&v5->vfptr);
      v73 = v5->parent_panel;
      if ( v73 )
        ((void (__stdcall *)(TDropDownPanel *, signed int, _DWORD, _DWORD))v73->vfptr->action)(v5, 1, 0, 0);
    }
    v5->mode = mode_in;
  }
}
// 474880: could not find valid save-restore pair for ebx
// 474880: could not find valid save-restore pair for ebp
// 474880: could not find valid save-restore pair for edi

//----- (00475110) --------------------------------------------------------
int __thiscall TDropDownPanel::numberLines(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1
  int result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = TTextPanel::numberLines((TTextPanel *)&v1->vfptr);
  else
    result = 0;
  return result;
}

//----- (00475130) --------------------------------------------------------
int __thiscall TDropDownPanel::currentLineNumber(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1
  int result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = TTextPanel::currentLineNumber((TTextPanel *)&v1->vfptr);
  else
    result = 0;
  return result;
}

//----- (00475150) --------------------------------------------------------
void __thiscall TDropDownPanel::setCurrentLineNumber(TDropDownPanel *this, int line_num_in)
{
  TDropDownPanel::set_line(this, line_num_in);
}

//----- (00475160) --------------------------------------------------------
void __thiscall TDropDownPanel::setCurrentLineId(TDropDownPanel *this, int id_in)
{
  TDropDownPanel *v2; // esi@1
  TListPanel *v3; // ecx@1
  __int16 v4; // ax@2
  TPanelVtbl **v5; // ecx@2
  TPanelVtbl *v6; // edi@3
  char *v7; // eax@3

  v2 = this;
  v3 = this->list_panel;
  if ( v3 )
  {
    TTextPanel::set_line_by_id((TTextPanel *)&v3->vfptr, id_in);
    v4 = TTextPanel::get_line((TTextPanel *)&v2->list_panel->vfptr);
    v5 = &v2->val_panel->vfptr;
    v2->val_num = v4;
    if ( v5 )
    {
      v6 = *v5;
      v7 = TTextPanel::get_text((TTextPanel *)&v2->list_panel->vfptr, v4);
      (*(void (__thiscall **)(TTextPanel *, char *))&v6[1].gap4[4])(v2->val_panel, v7);
    }
  }
}

//----- (004751C0) --------------------------------------------------------
char *__thiscall TDropDownPanel::currentLine(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1
  char *result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = TTextPanel::currentLine((TTextPanel *)&v1->vfptr);
  else
    result = 0;
  return result;
}

//----- (004751E0) --------------------------------------------------------
void __thiscall TDropDownPanel::set_tab_order(TDropDownPanel *this, TPanel *prev_panel, TPanel *next_panel)
{
  TDropDownPanel *v3; // esi@1
  TTextPanel *v4; // ecx@1

  v3 = this;
  TPanel::set_tab_order((TPanel *)&this->vfptr, prev_panel, next_panel);
  v4 = v3->val_panel;
  if ( v4 )
    (*((void (__stdcall **)(_DWORD, _DWORD))&v4->vfptr->set_focus + 1))(0, 0);
}

//----- (00475210) --------------------------------------------------------
void __thiscall TDropDownPanel::set_sorted(TDropDownPanel *this, int sorted_in)
{
  TListPanel *v2; // eax@1

  v2 = this->list_panel;
  if ( v2 )
    v2->sorted = sorted_in;
}

//----- (00475230) --------------------------------------------------------
int __thiscall TDropDownPanel::get_sorted(TDropDownPanel *this)
{
  TListPanel *v1; // eax@1
  int result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = v1->sorted;
  else
    result = 0;
  return result;
}

//----- (00475250) --------------------------------------------------------
void __thiscall TDropDownPanel::set_line(TDropDownPanel *this, int line_in)
{
  TDropDownPanel *v2; // esi@1
  TListPanel *v3; // ecx@1
  TPanelVtbl **v4; // eax@2
  TPanelVtbl *v5; // ebx@3
  char *v6; // eax@3

  v2 = this;
  v3 = this->list_panel;
  v2->val_num = line_in;
  if ( v3 )
  {
    TTextPanel::set_line((TTextPanel *)&v3->vfptr, line_in);
    v4 = &v2->val_panel->vfptr;
    if ( v4 )
    {
      v5 = *v4;
      v6 = TTextPanel::get_text((TTextPanel *)&v2->list_panel->vfptr, line_in);
      (*(void (__thiscall **)(TTextPanel *, char *))&v5[1].gap4[4])(v2->val_panel, v6);
    }
  }
}

//----- (004752A0) --------------------------------------------------------
void *__thiscall TDropDownPanel::append_line(TDropDownPanel *this, char *text_in, int id_in)
{
  TListPanel *v3; // ecx@1
  void *result; // eax@2

  v3 = this->list_panel;
  if ( v3 )
    result = TTextPanel::append_line((TTextPanel *)&v3->vfptr, text_in, id_in);
  else
    result = 0;
  return result;
}

//----- (004752D0) --------------------------------------------------------
void *__thiscall TDropDownPanel::append_line(TDropDownPanel *this, int string_id_in, int id_in)
{
  TListPanel *v3; // ecx@1
  void *result; // eax@2

  v3 = this->list_panel;
  if ( v3 )
    result = TTextPanel::append_line((TTextPanel *)&v3->vfptr, string_id_in, id_in);
  else
    result = 0;
  return result;
}

//----- (00475300) --------------------------------------------------------
void *__thiscall TDropDownPanel::insert_line(TDropDownPanel *this, int line_in, char *text_in, int id_in)
{
  TListPanel *v4; // ecx@1
  void *result; // eax@2

  v4 = this->list_panel;
  if ( v4 )
    result = TTextPanel::insert_line((TTextPanel *)&v4->vfptr, line_in, text_in, id_in);
  else
    result = 0;
  return result;
}

//----- (00475330) --------------------------------------------------------
void *__thiscall TDropDownPanel::insert_line(TDropDownPanel *this, int line_in, int string_id_in, int id_in)
{
  TListPanel *v4; // ecx@1
  void *result; // eax@2

  v4 = this->list_panel;
  if ( v4 )
    result = TTextPanel::insert_line((TTextPanel *)&v4->vfptr, line_in, string_id_in, id_in);
  else
    result = 0;
  return result;
}

//----- (00475360) --------------------------------------------------------
int __thiscall TDropDownPanel::delete_line(TDropDownPanel *this, int line_in)
{
  TListPanel *v2; // ecx@1
  int result; // eax@2

  v2 = this->list_panel;
  if ( v2 )
    result = TTextPanel::delete_line((TTextPanel *)&v2->vfptr, line_in);
  else
    result = 0;
  return result;
}

//----- (00475380) --------------------------------------------------------
int __thiscall TDropDownPanel::get_line(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1
  int result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = TTextPanel::get_line((TTextPanel *)&v1->vfptr);
  else
    result = 0;
  return result;
}

//----- (004753A0) --------------------------------------------------------
int __thiscall TDropDownPanel::get_line(TDropDownPanel *this, int id_in)
{
  TListPanel *v2; // ecx@1
  int result; // eax@2

  v2 = this->list_panel;
  if ( v2 )
    result = TTextPanel::get_line((TTextPanel *)&v2->vfptr, id_in);
  else
    result = 0;
  return result;
}

//----- (004753C0) --------------------------------------------------------
int __thiscall TDropDownPanel::get_line(TDropDownPanel *this, char *text_in)
{
  TListPanel *v2; // ecx@1
  int result; // eax@2

  v2 = this->list_panel;
  if ( v2 )
    result = TTextPanel::get_line((TTextPanel *)&v2->vfptr, text_in);
  else
    result = 0;
  return result;
}

//----- (004753E0) --------------------------------------------------------
char *__thiscall TDropDownPanel::get_text(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1
  char *result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = TTextPanel::get_text((TTextPanel *)&v1->vfptr);
  else
    result = 0;
  return result;
}

//----- (00475400) --------------------------------------------------------
char *__thiscall TDropDownPanel::get_text(TDropDownPanel *this, int line_in)
{
  TListPanel *v2; // ecx@1
  char *result; // eax@2

  v2 = this->list_panel;
  if ( v2 )
    result = TTextPanel::get_text((TTextPanel *)&v2->vfptr, line_in);
  else
    result = 0;
  return result;
}

//----- (00475420) --------------------------------------------------------
int __thiscall TDropDownPanel::get_id(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1
  int result; // eax@2

  v1 = this->list_panel;
  if ( v1 )
    result = TTextPanel::get_id((TTextPanel *)&v1->vfptr);
  else
    result = 0;
  return result;
}

//----- (00475440) --------------------------------------------------------
int __thiscall TDropDownPanel::get_id(TDropDownPanel *this, int line_in)
{
  TListPanel *v2; // ecx@1
  int result; // eax@2

  v2 = this->list_panel;
  if ( v2 )
    result = TTextPanel::get_id((TTextPanel *)&v2->vfptr, line_in);
  else
    result = 0;
  return result;
}

//----- (00475460) --------------------------------------------------------
void __thiscall TDropDownPanel::empty_list(TDropDownPanel *this)
{
  TListPanel *v1; // ecx@1

  v1 = this->list_panel;
  if ( v1 )
    TTextPanel::empty_list((TTextPanel *)&v1->vfptr);
}
