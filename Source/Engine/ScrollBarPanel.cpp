
//----- (0047A700) --------------------------------------------------------
void __thiscall TScrollBarPanel::TScrollBarPanel(TScrollBarPanel *this)
{
  TScrollBarPanel *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->list_panel = 0;
  v1->list_len = 0;
  v1->one_step = 0;
  v1->page_step = 0;
  v1->list_num = 0;
  v1->button_pics = 0;
  v1->back_frame = 0;
  v1->up_frame = 0;
  v1->down_frame = 0;
  v1->tab_frame = 0;
  v1->arrowSize = 0;
  v1->tabSize = 0;
  v1->tab_y = 0;
  v1->tab_min_y = 0;
  v1->tab_max_y = 0;
  v1->tab_mouse_y = 0;
  v1->tab_x = 0;
  v1->tab_min_x = 0;
  v1->tab_max_x = 0;
  v1->tab_mouse_x = 0;
  v1->item_down = 0;
  v1->item_is_down = 0;
  v1->item_x = 0;
  v1->item_y = 0;
  v1->item_mode = 0;
  v1->item_last_time = 0;
  v1->item_hold_interval = 100;
  v1->item_down_interval = 250;
  v1->orientationValue = 0;
  v1->bevel_type = 1;
  v1->bevel_color1 = 0;
  v1->bevel_color2 = 0;
  v1->bevel_color3 = 0;
  v1->bevel_color4 = 0;
  v1->bevel_color5 = 0;
  v1->bevel_color6 = 0;
  v1->vfptr = (TPanelVtbl *)&TScrollBarPanel::`vftable';
  v1->panel_type = 5;
  v1->mouse_move_tolerance = 0;
  SetRect(&v1->up_rect, 0, 0, 0, 0);
  SetRect(&v1->down_rect, 0, 0, 0, 0);
  SetRect(&v1->tab_rect, 0, 0, 0, 0);
  SetRect(&v1->top_rect, 0, 0, 0, 0);
  SetRect(&v1->bottom_rect, 0, 0, 0, 0);
}
// 571830: using guessed type int (__thiscall *TScrollBarPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047A880) --------------------------------------------------------
TScrollBarPanel *__thiscall TScrollBarPanel::`vector deleting destructor'(TScrollBarPanel *this, unsigned int __flags)
{
  TScrollBarPanel *v2; // esi@1

  v2 = this;
  TScrollBarPanel::~TScrollBarPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0047A8A0) --------------------------------------------------------
void __thiscall TScrollBarPanel::~TScrollBarPanel(TScrollBarPanel *this)
{
  this->vfptr = (TPanelVtbl *)&TScrollBarPanel::`vftable';
  TPanel::~TPanel((TPanel *)&this->vfptr);
}
// 571830: using guessed type int (__thiscall *TScrollBarPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047A8B0) --------------------------------------------------------
int __thiscall TScrollBarPanel::setup(TScrollBarPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, char *back_pic_in, char *up_pic_in, char *down_pic_in, char *tab_pic_in, int arrowSizeIn, int tabSizeIn, TPanel *list_panel_in, int list_len_in, TScrollBarPanel::Orientation orientation)
{
  this->orientationValue = orientation;
  this->arrowSize = arrowSizeIn;
  this->tabSize = tabSizeIn;
  this->list_panel = list_panel_in;
  this->list_len = list_len_in;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  return 1;
}

//----- (0047A910) --------------------------------------------------------
void __thiscall TScrollBarPanel::set_rect(TScrollBarPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  TScrollBarPanel *v5; // esi@1
  int v6; // eax@2
  int v7; // edx@2
  int v8; // ebp@2
  int v9; // ecx@2
  int v10; // edi@2
  int v11; // eax@2
  int v12; // ebx@2
  int v13; // eax@2
  int v14; // ebx@2
  int v15; // ecx@3
  int v16; // edx@3
  int v17; // ebp@3
  int v18; // eax@3
  int v19; // ebx@3
  int v20; // edi@3

  v5 = this;
  TPanel::set_rect((TPanel *)&this->vfptr, x_in, y_in, wid_in, hgt_in);
  if( v5->orientationValue == 1 )
  {
    v6 = v5->pnl_y;
    v7 = v5->pnl_hgt;
    v8 = v5->pnl_wid;
    v9 = v6 + 2;
    v10 = v7 + v6 - 5;
    v11 = v5->pnl_x;
    v5->up_rect.top = v9;
    v5->down_rect.top = v9;
    v12 = v11 + 2;
    v5->up_rect.left = v11 + 2;
    v5->tab_rect.top = v9;
    v13 = v11 + v8 - v7 + 2;
    v14 = v12 + v7 - 5;
    v5->down_rect.left = v13;
    v5->top_rect.top = v9;
    v5->bottom_rect.top = v9;
    v5->tab_min_x = v14 + 1;
    v5->tab_x = v14 + 1;
    v5->up_rect.bottom = v10;
    v5->up_rect.right = v14;
    v5->down_rect.bottom = v10;
    v5->down_rect.right = v13 + v7 - 5;
    v5->tab_rect.bottom = v10;
    v5->top_rect.bottom = v10;
    v5->bottom_rect.bottom = v10;
    v5->tab_max_x = v13 - v7 + 4;
    TScrollBarPanel::calc_item_rects(v5);
  }
  else
  {
    v15 = v5->pnl_y;
    v16 = v5->pnl_wid;
    v17 = v15 + v5->pnl_hgt - v16;
    v18 = v5->pnl_x + 2;
    v5->up_rect.top = v15 + 2;
    v19 = v16 + v15 + 2 - 5;
    v5->up_rect.left = v18;
    v5->down_rect.top = v17 + 2;
    v20 = v16 + v18 - 5;
    v5->down_rect.left = v18;
    v5->tab_rect.left = v18;
    v5->top_rect.left = v18;
    v5->bottom_rect.left = v18;
    v5->tab_max_y = v17 + 2 - v16 + 4;
    v5->up_rect.right = v20;
    v5->up_rect.bottom = v19;
    v5->down_rect.right = v20;
    v5->down_rect.bottom = v17 + 2 + v16 - 5;
    v5->tab_rect.right = v20;
    v5->top_rect.right = v20;
    v5->bottom_rect.right = v20;
    v5->tab_min_y = v19 + 1;
    v5->tab_y = v19 + 1;
    TScrollBarPanel::calc_item_rects(v5);
  }
}

//----- (0047AA80) --------------------------------------------------------
void __thiscall TScrollBarPanel::calc_item_rects(TScrollBarPanel *this)
{
  int v1; // eax@2
  int v2; // edx@2
  int v3; // esi@2
  int v4; // edx@2
  int v5; // eax@2
  int v6; // eax@3
  int v7; // edx@3
  int v8; // esi@3
  int v9; // edx@3
  int v10; // eax@3

  if( this->orientationValue == 1 )
  {
    v1 = this->tab_x;
    v2 = this->pnl_hgt;
    v3 = this->up_rect.right;
    this->tab_rect.left = v1;
    v4 = v2 + v1 - 5;
    this->tab_rect.right = v4;
    this->top_rect.right = v1 - 1;
    v5 = this->down_rect.left - 1;
    this->top_rect.left = v3 + 1;
    this->bottom_rect.left = v4 + 1;
    this->bottom_rect.right = v5;
  }
  else
  {
    v6 = this->tab_y;
    v7 = this->pnl_wid;
    v8 = this->up_rect.bottom;
    this->tab_rect.top = v6;
    v9 = v7 + v6 - 5;
    this->tab_rect.bottom = v9;
    this->top_rect.bottom = v6 - 1;
    v10 = this->down_rect.top - 1;
    this->top_rect.top = v8 + 1;
    this->bottom_rect.top = v9 + 1;
    this->bottom_rect.bottom = v10;
  }
}

//----- (0047AB20) --------------------------------------------------------
void __thiscall TScrollBarPanel::set_tab_pos(TScrollBarPanel *this, int list_num_in)
{
  TScrollBarPanel *v2; // esi@1
  TScrollBarPanel::Orientation v3; // eax@1
  int v4; // ebx@1
  int v5; // eax@4
  int v6; // ecx@4
  int v7; // ecx@6
  int v8; // eax@12
  int v9; // ecx@12

  v2 = this;
  v3 = this->orientationValue;
  v4 = this->list_len;
  this->list_num = list_num_in;
  if( v3 == 1 )
  {
    if( v4 > 0 )
      this->tab_x = this->tab_min_x + list_num_in * (this->tab_max_x + this->tabSize / 2 - this->tab_min_x) / v4;
    v5 = this->tab_x;
    v6 = this->tab_min_x;
    if( v5 >= v6 )
    {
      v7 = v2->tab_max_x;
      if( v5 > v7 )
        v2->tab_x = v7;
    }
    else
    {
      v2->tab_x = v6;
    }
  }
  else
  {
    if( v4 > 0 )
    {
      if( list_num_in == v4 - 1 )
        this->tab_y = this->tab_max_y;
      else
        this->tab_y = this->tab_min_y + list_num_in * (this->tab_max_y + this->tabSize / 2 - this->tab_min_y) / v4;
    }
    v8 = this->tab_y;
    v9 = this->tab_min_y;
    if( v8 < v9 || (v9 = v2->tab_max_y, v8 > v9) )
      v2->tab_y = v9;
  }
  TScrollBarPanel::calc_item_rects(v2);
  v2->vfptr->set_redraw((TPanel *)v2, RedrawNormal);
}

//----- (0047AC10) --------------------------------------------------------
void __thiscall TScrollBarPanel::set_list_len(TScrollBarPanel *this, int list_len_in, int list_num_in)
{
  this->list_len = list_len_in;
  TScrollBarPanel::set_tab_pos(this, list_num_in);
}

//----- (0047AC30) --------------------------------------------------------
void __thiscall TScrollBarPanel::set_buttons(TScrollBarPanel *this, TShape *button_pics_in, int back_frame_in, int up_frame_in, int down_frame_in, int tab_frame_in)
{
  this->button_pics = button_pics_in;
  this->back_frame = back_frame_in;
  this->up_frame = up_frame_in;
  this->down_frame = down_frame_in;
  this->tab_frame = tab_frame_in;
}

//----- (0047AC70) --------------------------------------------------------
void __thiscall TScrollBarPanel::set_bevel_info(TScrollBarPanel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  this->bevel_type = bevel_type_in;
  this->bevel_color1 = c1;
  this->bevel_color2 = c2;
  this->bevel_color3 = c3;
  this->bevel_color4 = c4;
  this->bevel_color5 = c5;
  this->bevel_color6 = c6;
}

//----- (0047ACC0) --------------------------------------------------------
int __thiscall TScrollBarPanel::handle_idle(TScrollBarPanel *this)
{
  TScrollBarPanel *v1; // esi@1
  unsigned int v2; // eax@4
  int result; // eax@6
  TPanelVtbl *v4; // edx@9
  TPanelVtbl *v5; // eax@12
  unsigned int v6; // eax@14
  unsigned int v7; // ecx@15

  v1 = this;
  if( this->item_mode == 1 )
  {
    v6 = debug_timeGetTime();
    if( v6 - v1->item_last_time >= v1->item_down_interval )
    {
      v7 = v1->item_hold_interval;
      v1->item_mode = 2;
      v1->item_last_time = v6 - v7;
    }
    return 0;
  }
  if( this->item_mode != 2 )
    return 0;
  if( !this->item_is_down )
    return 0;
  v2 = debug_timeGetTime();
  if( v2 - v1->item_last_time < v1->item_hold_interval )
    return 0;
  v1->item_last_time = v2;
  switch ( v1->item_down )
  {
    case 1:
      TScrollBarPanel::scroll(v1, 0, 0);
      result = 0;
      break;
    case 2:
      TScrollBarPanel::scroll(v1, ActionDown, 0);
      result = 0;
      break;
    case 4:
      if( TPanel::is_inside_rect(v1->item_x, v1->item_y, &v1->top_rect) )
      {
        TScrollBarPanel::scroll(v1, ActionPrior, 0);
        result = 0;
      }
      else
      {
        v4 = v1->vfptr;
        v1->item_is_down = 0;
        v1->item_mode = 0;
        v4->set_redraw((TPanel *)v1, RedrawNormal);
        result = 0;
      }
      break;
    case 5:
      if( TPanel::is_inside_rect(v1->item_x, v1->item_y, &v1->bottom_rect) )
      {
        TScrollBarPanel::scroll(v1, ActionNext, 0);
        result = 0;
      }
      else
      {
        v5 = v1->vfptr;
        v1->item_is_down = 0;
        v1->item_mode = 0;
        v5->set_redraw((TPanel *)v1, RedrawNormal);
        result = 0;
      }
      break;
    default:
      return 0;
  }
  return result;
}

//----- (0047AE40) --------------------------------------------------------
int __thiscall TScrollBarPanel::mouse_left_down_action(TScrollBarPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TScrollBarPanel *v5; // esi@1
  TScrollBarPanel::Orientation v6; // eax@6
  TPanel *v7; // eax@15
  TPanel *v8; // ecx@17
  unsigned int v9; // eax@19
  TPanelVtbl *v10; // edx@19

  v5 = this;
  TPanel::capture_mouse((TPanel *)&this->vfptr);
  if( TPanel::is_inside_rect(x, y, &v5->up_rect) )
  {
    v5->item_down = 1;
    v5->item_is_down = 1;
    TScrollBarPanel::scroll(v5, 0, 0);
  }
  else if( TPanel::is_inside_rect(x, y, &v5->down_rect) )
  {
    v5->item_down = 2;
    v5->item_is_down = 1;
    TScrollBarPanel::scroll(v5, ActionDown, 0);
  }
  else if( TPanel::is_inside_rect(x, y, &v5->tab_rect) )
  {
    v6 = v5->orientationValue;
    v5->item_down = 3;
    if( v6 == 1 )
      v5->tab_mouse_x = x - v5->tab_x;
    else
      v5->tab_mouse_y = y - v5->tab_y;
  }
  else if( TPanel::is_inside_rect(x, y, &v5->top_rect) )
  {
    v5->item_down = 4;
    v5->item_is_down = 1;
    TScrollBarPanel::scroll(v5, ActionPrior, 0);
  }
  else if( TPanel::is_inside_rect(x, y, &v5->bottom_rect) )
  {
    v5->item_down = 5;
    v5->item_is_down = 1;
    TScrollBarPanel::scroll(v5, ActionNext, 0);
  }
  else
  {
    v5->item_down = 0;
  }
  if( v5->item_down )
  {
    v7 = v5->list_panel;
    if( v7 )
    {
      if( v7->tab_stop )
      {
        v8 = v7->parent_panel;
        if( v8 )
          TPanel::set_curr_child(v8, v5->list_panel);
      }
    }
    v5->item_x = x;
    v5->item_y = y;
    v5->item_mode = 1;
    v9 = debug_timeGetTime();
    v10 = v5->vfptr;
    v5->item_last_time = v9;
    v10->set_redraw((TPanel *)v5, RedrawNormal);
  }
  return 0;
}

//----- (0047AFD0) --------------------------------------------------------
int __thiscall TScrollBarPanel::mouse_left_move_action(TScrollBarPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TScrollBarPanel *v5; // esi@1
  int v6; // ebp@1
  int v7; // eax@2
  int v8; // eax@5
  TPanelVtbl *v9; // eax@13
  TPanelVtbl *v10; // edx@19
  int v11; // eax@21
  int v12; // ecx@22
  int v13; // ecx@23
  int v14; // edx@23
  bool v15; // zf@27
  int v16; // edi@32
  int v17; // ecx@34
  int v18; // edx@36
  int v19; // ecx@36
  int v20; // eax@37
  int v21; // edi@38
  int v22; // ecx@40
  int v23; // eax@42
  int v24; // ecx@43
  int v25; // ecx@44
  int v26; // edx@44
  bool v27; // zf@50
  int v28; // edi@55
  int v29; // ecx@57
  int v30; // edx@59
  int v31; // ecx@59
  int v32; // edi@61
  TScrollBarPanel::ActionType v34; // [sp-8h] [bp-18h]@4
  TScrollBarPanel::ActionType v35; // [sp-8h] [bp-18h]@7

  v5 = this;
  v6 = x;
  switch ( this->item_down )
  {
    case 1:
      v15 = TPanel::is_inside_rect(x, y, &this->up_rect) == 0;
      v7 = v5->item_is_down;
      if( v15 )
        goto LABEL_12;
      if( !v7 )
      {
        v5->item_is_down = 1;
        v5->item_mode = 2;
        v5->item_last_time = debug_timeGetTime();
        v34 = 0;
        goto LABEL_11;
      }
      goto LABEL_66;
    case 2:
      v15 = TPanel::is_inside_rect(x, y, &this->down_rect) == 0;
      v8 = v5->item_is_down;
      if( v15 )
        goto LABEL_18;
      if( !v8 )
      {
        v5->item_is_down = 1;
        v5->item_mode = 2;
        v5->item_last_time = debug_timeGetTime();
        v35 = 1;
        goto LABEL_17;
      }
      goto LABEL_66;
    case 4:
      v15 = TPanel::is_inside_rect(x, y, &this->top_rect) == 0;
      v7 = v5->item_is_down;
      if( v15 )
      {
LABEL_12:
        if( v7 )
        {
          v9 = v5->vfptr;
          v5->item_is_down = 0;
          v5->item_mode = 0;
          v9->set_redraw((TPanel *)v5, RedrawNormal);
        }
      }
      else if( !v7 )
      {
        v5->item_is_down = 1;
        v5->item_mode = 2;
        v5->item_last_time = debug_timeGetTime();
        v34 = 2;
LABEL_11:
        TScrollBarPanel::scroll(v5, v34, 0);
        v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
      }
      goto LABEL_66;
    case 5:
      v15 = TPanel::is_inside_rect(x, y, &this->bottom_rect) == 0;
      v8 = v5->item_is_down;
      if( v15 )
      {
LABEL_18:
        if( v8 )
        {
          v10 = v5->vfptr;
          v5->item_is_down = 0;
          v5->item_mode = 0;
          v10->set_redraw((TPanel *)v5, RedrawNormal);
        }
      }
      else if( !v8 )
      {
        v5->item_is_down = 1;
        v5->item_mode = 2;
        v5->item_last_time = debug_timeGetTime();
        v35 = 3;
LABEL_17:
        TScrollBarPanel::scroll(v5, v35, 0);
        v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
      }
      goto LABEL_66;
    case 3:
      if( this->orientationValue == 1 )
      {
        v11 = x - this->item_x;
        if( v11 > 0 )
          v12 = this->tab_min_x;
        v13 = v5->tab_x;
        v14 = v5->tab_min_x;
        if( v13 == v14 && v11 > 0 && x < v13 + v5->tab_mouse_x )
          goto LABEL_71;
        if( v13 == v5->tab_max_x )
        {
          v15 = v11 == 0;
          if( v11 >= 0 )
          {
LABEL_31:
            if( v15 )
              goto LABEL_66;
            v16 = v11 + v5->tab_x;
            v5->tab_x = v16;
            if( v16 >= v14 )
            {
              v17 = v5->tab_max_x;
              if( v16 > v17 )
                v5->tab_x = v17;
            }
            else
            {
              v5->tab_x = v14;
            }
            TScrollBarPanel::calc_item_rects(v5);
            v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
            v18 = v5->tab_min_x;
            v19 = v5->tab_max_x;
            if( v18 == v19 )
            {
              v20 = 0;
LABEL_65:
              TScrollBarPanel::scroll(v5, ActionPosition, v20);
              goto LABEL_66;
            }
            v21 = v5->list_len;
            v20 = v21 * (v5->tab_x - v18) / (v19 - v18);
            if( v20 < 0 )
            {
              v20 = 0;
              goto LABEL_65;
            }
            v22 = v21 - 1;
            if( v20 <= v21 - 1 )
              goto LABEL_65;
LABEL_64:
            v20 = v22;
            goto LABEL_65;
          }
          if( x >= v13 + v5->tab_mouse_x )
LABEL_71:
            v11 = 0;
        }
        v15 = v11 == 0;
        goto LABEL_31;
      }
      v23 = y - this->item_y;
      if( v23 > 0 )
        v24 = this->tab_min_y;
      v25 = v5->tab_y;
      v26 = v5->tab_min_y;
      if( v25 != v26 || v23 <= 0 )
        goto LABEL_49;
      if( y >= v25 + v5->tab_mouse_y )
      {
        v6 = x;
LABEL_49:
        if( v25 == v5->tab_max_y )
        {
          v27 = v23 == 0;
          if( v23 >= 0 )
          {
LABEL_54:
            if( v27 )
              goto LABEL_66;
            v28 = v23 + v5->tab_y;
            v5->tab_y = v28;
            if( v28 >= v26 )
            {
              v29 = v5->tab_max_y;
              if( v28 > v29 )
                v5->tab_y = v29;
            }
            else
            {
              v5->tab_y = v26;
            }
            TScrollBarPanel::calc_item_rects(v5);
            v5->vfptr->set_redraw((TPanel *)v5, RedrawNormal);
            v30 = v5->tab_min_y;
            v31 = v5->tab_max_y;
            if( v30 == v31 )
            {
              v20 = 0;
              goto LABEL_65;
            }
            v32 = v5->list_len;
            v20 = v32 * (v5->tab_y - v30) / (v31 - v30);
            if( v20 < 0 )
            {
              v20 = 0;
              goto LABEL_65;
            }
            v22 = v32 - 1;
            if( v20 <= v32 - 1 )
              goto LABEL_65;
            goto LABEL_64;
          }
          if( y >= v25 + v5->tab_mouse_y )
            v23 = 0;
        }
      }
      else
      {
        v6 = x;
        v23 = 0;
      }
      v27 = v23 == 0;
      goto LABEL_54;
    default:
LABEL_66:
      if( v5->item_down )
      {
        v5->item_x = v6;
        v5->item_y = y;
      }
      return 0;
  }
}

//----- (0047B3D0) --------------------------------------------------------
int __thiscall TScrollBarPanel::mouse_left_up_action(TScrollBarPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TScrollBarPanel *v5; // esi@1
  TPanel *v6; // ecx@1
  TPanelVtbl *v7; // eax@3

  v5 = this;
  v6 = this->parent_panel;
  if( v6 )
    ((void (__stdcall *)(TScrollBarPanel *, signed int, int, _DWORD))v6->vfptr->action)(v5, 5, v5->list_num, 0);
  TPanel::release_mouse((TPanel *)&v5->vfptr);
  v7 = v5->vfptr;
  v5->item_down = 0;
  v5->item_mode = 0;
  v5->item_is_down = 0;
  v7->set_redraw((TPanel *)v5, RedrawNormal);
  return 0;
}

//----- (0047B420) --------------------------------------------------------
void __thiscall TScrollBarPanel::scroll(TScrollBarPanel *this, TScrollBarPanel::ActionType action, int val)
{
  TScrollBarPanel *v3; // edi@1
  TPanel *v4; // ecx@1
  int v5; // esi@3
  int v6; // esi@4
  TPanel *v7; // ecx@14

  v3 = this;
  v4 = this->list_panel;
  if( v4 )
  {
    ((void (__stdcall *)(TScrollBarPanel *, TScrollBarPanel::ActionType, int, _DWORD))v4->vfptr->action)(
      v3,
      action,
      val,
      0);
  }
  else
  {
    v5 = v3->list_num;
    switch ( action )
    {
      case 0:
        v6 = v5 - v3->one_step;
        goto LABEL_9;
      case 1:
        v6 = v3->one_step + v5;
        goto LABEL_9;
      case 2:
        v6 = v5 - v3->page_step;
        goto LABEL_9;
      case 3:
        v6 = v3->page_step + v5;
        goto LABEL_9;
      case 4:
        v6 = val;
LABEL_9:
        if( v6 >= 0 )
        {
          if( v6 > v3->list_len - 1 )
            v6 = v3->list_len - 1;
        }
        else
        {
          v6 = 0;
        }
        if( v6 != v3->list_num )
        {
          TScrollBarPanel::set_tab_pos(v3, v6);
          v7 = v3->parent_panel;
          if( v7 )
            ((void (__stdcall *)(TScrollBarPanel *, signed int, int, _DWORD))v7->vfptr->action)(v3, 4, v6, 0);
        }
        break;
      default:
        return;
    }
  }
}

//----- (0047B4E0) --------------------------------------------------------
void __thiscall TScrollBarPanel::draw(TScrollBarPanel *this)
{
  TScrollBarPanel *v1; // esi@1
  TPanel *v2; // ecx@1
  TPanelVtbl *v3; // ebp@3
  int v4; // eax@8
  int v5; // eax@12
  int v6; // eax@19
  int v7; // eax@23

  v1 = this;
  v2 = this->parent_panel;
  if( v2 )
    ((void (__stdcall *)(int))v2->vfptr->draw_rect2)((int)&v1->clip_rect);
  v3 = v1->vfptr;
  v1->vfptr->draw_setup((TPanel *)v1, 0);
  if( TDrawArea::Lock(v1->render_area, aPnl_scbrDraw, 1) )
  {
    TScrollBarPanel::draw_back_pic(v1);
    TScrollBarPanel::draw_border(v1, 0, 1, &v1->render_rect);
    if( v1->up_rect.top != v1->up_rect.bottom && v1->up_rect.left != v1->up_rect.right )
    {
      v4 = v1->item_down == 1 && v1->item_is_down;
      TScrollBarPanel::draw_button_pic(v1, v1->up_frame, v4, &v1->up_rect);
      v5 = v1->item_down == 1 && v1->item_is_down;
      TScrollBarPanel::draw_border(v1, 1, v5, &v1->up_rect);
    }
    if( v1->down_rect.top != v1->down_rect.bottom && v1->down_rect.left != v1->down_rect.right )
    {
      v6 = v1->item_down == 2 && v1->item_is_down;
      TScrollBarPanel::draw_button_pic(v1, v1->down_frame, v6, &v1->down_rect);
      v7 = v1->item_down == 2 && v1->item_is_down;
      TScrollBarPanel::draw_border(v1, 1, v7, &v1->down_rect);
    }
    TScrollBarPanel::draw_button_pic(v1, v1->tab_frame, 0, &v1->tab_rect);
    TScrollBarPanel::draw_border(v1, 1, 0, &v1->tab_rect);
    TDrawArea::Unlock(v1->render_area, aPnl_scbrDraw);
  }
  v3->draw_finish((TPanel *)v1);
}

//----- (0047B660) --------------------------------------------------------
void __thiscall TScrollBarPanel::draw_border(TScrollBarPanel *this, int button, int down, tagRECT *rect)
{
  TScrollBarPanel::draw_border(this, button, down, rect->left, rect->top, rect->right, rect->bottom);
}

//----- (0047B690) --------------------------------------------------------
void __thiscall TScrollBarPanel::draw_border(TScrollBarPanel *this, int button, int down, int x1, int y1, int x2, int y2)
{
  TScrollBarPanel *v7; // esi@1
  int v8; // ecx@3
  int v9; // [sp-8h] [bp-18h]@5
  char v10; // [sp-4h] [bp-14h]@5

  v7 = this;
  if( x1 != x2 && y1 != y2 )
  {
    v8 = this->bevel_type;
    if( down )
    {
      switch ( v8 )
      {
        case 1:
          v10 = -1;
          v9 = y2;
          if( !button )
            goto LABEL_14;
          TDrawArea::DrawRect(v7->render_area, x1 + 1, y1 + 1, x2, y2, -1);
          break;
        case 2:
          TDrawArea::DrawBevel(v7->render_area, x1, y1, x2, y2, v7->bevel_color6, v7->bevel_color1);
          break;
        case 3:
          TDrawArea::DrawBevel2(
            v7->render_area,
            x1,
            y1,
            x2,
            y2,
            v7->bevel_color6,
            v7->bevel_color5,
            v7->bevel_color2,
            v7->bevel_color1);
          break;
        case 4:
          TDrawArea::DrawBevel3(
            v7->render_area,
            x1,
            y1,
            x2,
            y2,
            v7->bevel_color6,
            v7->bevel_color5,
            v7->bevel_color4,
            v7->bevel_color3,
            v7->bevel_color2,
            v7->bevel_color1);
          break;
        default:
          return;
      }
    }
    else
    {
      switch ( v8 )
      {
        case 1:
          v10 = 0;
          if( button )
          {
            TDrawArea::DrawVertLine(v7->render_area, x2, y1 + 1, y2 - y1, 0);
            TDrawArea::DrawHorzLine(v7->render_area, x1 + 1, y1, x2 - x1, 0);
            TDrawArea::DrawRect(v7->render_area, x1, y1, x2 - 1, y1 - 1, -1);
          }
          else
          {
            v9 = y2;
LABEL_14:
            TDrawArea::DrawRect(v7->render_area, x1, y1, x2 - 1, v9, v10);
          }
          break;
        case 2:
          TDrawArea::DrawBevel(v7->render_area, x1, y1, x2, y2, v7->bevel_color1, v7->bevel_color6);
          break;
        case 3:
          TDrawArea::DrawBevel2(
            v7->render_area,
            x1,
            y1,
            x2,
            y2,
            v7->bevel_color1,
            v7->bevel_color2,
            v7->bevel_color5,
            v7->bevel_color6);
          break;
        case 4:
          TDrawArea::DrawBevel3(
            v7->render_area,
            x1,
            y1,
            x2,
            y2,
            v7->bevel_color1,
            v7->bevel_color2,
            v7->bevel_color3,
            v7->bevel_color4,
            v7->bevel_color5,
            v7->bevel_color6);
          break;
        default:
          return;
      }
    }
  }
}

//----- (0047B8B0) --------------------------------------------------------
void __thiscall TScrollBarPanel::draw_back_pic(TScrollBarPanel *this)
{
  TScrollBarPanel *v1; // esi@1
  TShape *v2; // ecx@1
  int v3; // ecx@3
  int v4; // ebp@3
  int v5; // eax@3
  int v6; // ebx@3
  int v7; // edi@4
  int x_max; // [sp+10h] [bp-14h]@3
  int x_min; // [sp+14h] [bp-10h]@3
  int y_max; // [sp+18h] [bp-Ch]@3
  int y_min; // [sp+1Ch] [bp-8h]@3
  int pic_hgt; // [sp+20h] [bp-4h]@3

  v1 = this;
  v2 = this->button_pics;
  if( v2 )
  {
    if( v1->back_frame != -1 )
    {
      TShape::shape_minmax(v2, &x_min, &y_min, &x_max, &y_max, v1->back_frame);
      v3 = v1->pnl_hgt;
      v4 = x_max - x_min + 1;
      v5 = y_max - y_min + 1;
      v6 = 0;
      pic_hgt = y_max - y_min + 1;
      if( v3 >= 0 )
      {
        do
        {
          v7 = 0;
          if( v1->pnl_wid >= 0 )
          {
            do
            {
              TShape::shape_draw(v1->button_pics, v1->render_area, v1->pnl_x + v7, v1->pnl_y + v6, v1->back_frame, 0, 0);
              v7 += v4;
            }
            while( v7 <= v1->pnl_wid );
            v5 = pic_hgt;
          }
          v6 += v5;
        }
        while( v6 <= v1->pnl_hgt );
      }
    }
  }
}

//----- (0047B970) --------------------------------------------------------
void __thiscall TScrollBarPanel::draw_button_pic(TScrollBarPanel *this, int frame, int down, tagRECT *rect)
{
  TScrollBarPanel *v4; // ebx@1
  tagRECT *v5; // esi@3
  __int64 v6; // rax@3
  __int16 v7; // cx@3
  __int64 v8; // rax@3
  __int16 v9; // di@3
  int x_min; // [sp+10h] [bp-Ch]@3
  int y_max; // [sp+14h] [bp-8h]@3
  int y_min; // [sp+18h] [bp-4h]@3

  v4 = this;
  if( this->button_pics && frame != -1 )
  {
    v5 = rect;
    TDrawArea::SetClipRect(this->render_area, rect);
    TShape::shape_minmax(v4->button_pics, &x_min, &y_min, (int *)&rect, &y_max, frame);
    v6 = v5->right - v5->left + 1;
    v7 = LOWORD(v5->left) + (((signed int)v6 - HIDWORD(v6)) >> 1) - ((signed int)&rect->left + -x_min + 1) / 2 - x_min;
    v8 = v5->bottom - v5->top + 1;
    v9 = LOWORD(v5->top) + (((signed int)v8 - HIDWORD(v8)) >> 1) - (y_max - y_min + 1) / 2 - y_min;
    if( down )
    {
      ++v7;
      --v9;
    }
    TShape::shape_draw(v4->button_pics, v4->render_area, v7, v9, frame + (down != 0), 0, 0);
  }
  else
  {
    ((void (__stdcall *)(tagRECT *))this->parent_panel->vfptr->draw_rect2)(rect);
  }
}
