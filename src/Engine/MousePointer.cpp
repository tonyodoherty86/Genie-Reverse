
//----- (0045AE50) --------------------------------------------------------
void __thiscall TMousePointer::TMousePointer(TMousePointer *this, int MouseModeIn)
{
  TMousePointer *v2; // esi@1
  char *v3; // eax@1
  int v4; // edi@1
  char *v5; // ecx@1
  int v6; // edi@1
  int v7; // edi@1
  int v8; // edx@1
  int v9; // ecx@1
  int v10; // edi@1
  int v11; // edi@1
  int v12; // edi@1
  int v13; // edx@1
  int v14; // ecx@1
  int v15; // edi@1
  int v16; // edi@1
  int v17; // edi@1
  int v18; // edx@1
  int v19; // ecx@1
  int v20; // edx@1
  int v21; // edx@1
  int v22; // eax@1

  v2 = this;
  v3 = (char *)&this->save_rect;
  this->save_rect.top = 0;
  this->save_rect.right = 0;
  *(_DWORD *)v3 = 0;
  this->save_rect.bottom = 0;
  v4 = this->save_rect.left;
  v5 = (char *)&this->mouse_rect;
  v2->custom_draw = 0;
  v2->render_area = 0;
  *(_DWORD *)v5 = v4;
  v6 = *((_DWORD *)v3 + 1);
  v2->save_area = 0;
  v2->primary_area = 0;
  *((_DWORD *)v5 + 1) = v6;
  v7 = *((_DWORD *)v3 + 2);
  v2->Cursor_Shape = 0;
  v2->Max_CX = 0;
  v8 = *((_DWORD *)v3 + 3);
  *((_DWORD *)v5 + 2) = v7;
  v2->Max_CY = 0;
  v2->cWidth = 0;
  *((_DWORD *)v5 + 3) = v8;
  v9 = (int)&v2->cursor_rect.left;
  v2->cHeight = 0;
  v10 = *(_DWORD *)v3;
  v2->gWidth = 0;
  *(_DWORD *)v9 = v10;
  v2->gHeight = 0;
  v11 = *((_DWORD *)v3 + 1);
  v2->mouse_x = 0;
  *(_DWORD *)(v9 + 4) = v11;
  v2->mouse_y = 0;
  v12 = *((_DWORD *)v3 + 2);
  v2->facet = 0;
  *(_DWORD *)(v9 + 8) = v12;
  v2->game_facet = 0;
  v13 = *((_DWORD *)v3 + 3);
  v2->next_facet = 0;
  *(_DWORD *)(v9 + 12) = v13;
  v14 = (int)&v2->new_save_rect.left;
  v2->last_facet = 0;
  v15 = *(_DWORD *)v3;
  v2->d_top = 0;
  *(_DWORD *)v14 = v15;
  v2->d_left = 0;
  v16 = *((_DWORD *)v3 + 1);
  v2->d_bottom = 0;
  *(_DWORD *)(v14 + 4) = v16;
  v2->d_right = 0;
  v17 = *((_DWORD *)v3 + 2);
  v2->g_top = 0;
  *(_DWORD *)(v14 + 8) = v17;
  v2->g_left = 0;
  v18 = *((_DWORD *)v3 + 3);
  v2->g_bottom = 0;
  *(_DWORD *)(v14 + 12) = v18;
  v19 = (int)&v2->restore_rect.left;
  v2->g_right = 0;
  *(_DWORD *)v19 = 0;
  v20 = *((_DWORD *)v3 + 1);
  v2->active = 0;
  v2->drawn = 0;
  *(_DWORD *)(v19 + 4) = v20;
  v21 = *((_DWORD *)v3 + 2);
  v22 = *((_DWORD *)v3 + 3);
  v2->Shutdown = 0;
  *(_DWORD *)(v19 + 8) = v21;
  v2->Setup = 0;
  *(_DWORD *)(v19 + 12) = v22;
  v2->save_x = -32767;
  v2->save_y = -32767;
  v2->Mouse_Mode = MouseModeIn;
  v2->restoreSurface = 0;
  v2->renderSurface = 0;
  v2->GameMode = 0;
  v2->GameEnabled = 0;
  v2->MouseOnScreen = 0;
  v2->Num_Cursors = 0;
  v2->Max_Cursors = 0;
  v2->cursor_file_id = -1;
  v2->cursor_file[0] = 0;
  memset(v2->cursors, 0, sizeof(v2->cursors));
  v2->LastDrawTime = debug_timeGetTime() - 36;
  v2->save_area_valid = 0;
  v2->LastddError = 0;
}

//----- (0045B000) --------------------------------------------------------
void __thiscall TMousePointer::~TMousePointer(TMousePointer *this)
{
  TMousePointer *v1; // edi@1
  TShape *v2; // esi@1

  v1 = this;
  v2 = this->Cursor_Shape;
  if ( v2 )
  {
    TShape::~TShape(this->Cursor_Shape);
    operator delete(v2);
    v1->Cursor_Shape = 0;
  }
  TMousePointer::delete_surfaces(v1);
  MouseSystem = 0;
}

//----- (0045B040) --------------------------------------------------------
int __thiscall TMousePointer::Shutdown_Mouse(TMousePointer *this)
{
  TMousePointer *v1; // esi@1
  int result; // eax@2

  v1 = this;
  if ( this->Shutdown )
  {
    result = 0;
  }
  else if ( this->custom_draw )
  {
    if ( this->Setup )
    {
      TMousePointer::reset(this);
      result = 1;
      v1->render_area = 0;
      v1->restoreSurface = 0;
      v1->renderSurface = 0;
      v1->PrimarySurface = 0;
      v1->primary_area = 0;
      v1->active = 0;
      v1->Shutdown = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0045B0A0) --------------------------------------------------------
int __thiscall TMousePointer::Restore_Mouse(TMousePointer *this, TDrawArea *render_area_in)
{
  TMousePointer *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if ( !this->Shutdown )
    return 0;
  if ( !this->custom_draw )
    goto LABEL_8;
  if ( !this->Setup )
    return 0;
  this->render_area = render_area_in;
  this->renderSurface = render_area_in->DrawSurface;
  this->PrimarySurface = render_area_in->DrawSystem->PrimarySurface;
  this->primary_area = render_area_in->DrawSystem->PrimaryArea;
  result = TMousePointer::LoadCursors(this, 0, -1, 1);
  if ( result )
  {
    v2->Shutdown = 0;
LABEL_8:
    result = 1;
  }
  return result;
}

//----- (0045B120) --------------------------------------------------------
int __thiscall TMousePointer::setup(TMousePointer *this, int custom_draw_in, TDrawArea *render_area_in, char *cursor_file_name, int cursor_resId, int maxCursors_in)
{
  TMousePointer *v6; // esi@1
  int result; // eax@2
  TShape *v8; // eax@4
  TShape *v9; // eax@5
  TShape *v10; // ecx@9
  int v11; // eax@12
  int v12; // ecx@12
  char file_name[260]; // [sp+10h] [bp-110h]@4
  int v14; // [sp+11Ch] [bp-4h]@4

  v6 = this;
  MouseSystem = this;
  this->custom_draw = custom_draw_in;
  this->render_area = render_area_in;
  if ( custom_draw_in )
  {
    if ( render_area_in->DrawSystem->DrawType != 1
      && ((this->renderSurface = render_area_in->DrawSurface,
           this->PrimarySurface = render_area_in->DrawSystem->PrimarySurface,
           this->primary_area = render_area_in->DrawSystem->PrimaryArea,
           SetCursor(0),
           sprintf(file_name, aS_slp, cursor_file_name),
           v8 = (TShape *)operator new(0x20u),
           v14 = 0,
           !v8) ? (v9 = 0) : TShape::TShape(v8, file_name, cursor_resId),
          (v14 = -1, (v6->Cursor_Shape = v9) != 0)
       && TShape::is_loaded(v9)
       && (v10 = v6->Cursor_Shape, v10->FShape)
       && (v6->Max_Cursors = maxCursors_in, maxCursors_in >= 1)
       && maxCursors_in <= 16
       && (v11 = TShape::shape_count(v10), v12 = v6->Max_Cursors, v6->Num_Cursors = v11, v11 <= v12)
       && TMousePointer::LoadCursors(v6, cursor_file_name, cursor_resId, 0)) )
    {
      TMousePointer::set_facet(v6, 0);
      TMousePointer::set_game_facet(v6, 0);
      v6->Setup = 1;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0045B290) --------------------------------------------------------
void __thiscall TMousePointer::set_game_mode(TMousePointer *this, int mode)
{
  this->GameMode = mode;
}

//----- (0045B2A0) --------------------------------------------------------
void __thiscall TMousePointer::set_game_enable(TMousePointer *this, int enable)
{
  this->GameEnabled = enable;
}

//----- (0045B2B0) --------------------------------------------------------
int __thiscall TMousePointer::get_game_enable(TMousePointer *this)
{
  return this->GameEnabled;
}

//----- (0045B2C0) --------------------------------------------------------
BOOL __thiscall TMousePointer::in_game_mode(TMousePointer *this)
{
  return this->GameMode && this->GameEnabled;
}

//----- (0045B2E0) --------------------------------------------------------
void __thiscall TMousePointer::set_game_window(TMousePointer *this, int Left, int Top, int Right, int Bottom)
{
  this->game_window.left = Left;
  this->game_window.top = Top;
  this->game_window.right = Right;
  this->game_window.bottom = Bottom;
}

//----- (0045B310) --------------------------------------------------------
int __thiscall TMousePointer::LoadCursors(TMousePointer *this, char *cursor_file_name, int resId, int Reload)
{
  TMousePointer *v4; // esi@1
  TShape *v5; // edi@1
  TShape *v6; // eax@5
  TShape *v7; // eax@6
  TShape *v8; // ecx@10
  int v9; // eax@11
  TShape *v10; // edi@12
  int v11; // edx@12
  int v12; // ebx@12
  int v13; // eax@13
  int v14; // ecx@13
  int v15; // eax@15
  TDrawArea *v16; // eax@20
  int v17; // edx@23
  int v18; // ebp@23
  int v19; // ecx@24
  int *v20; // eax@25
  int v21; // ebx@29
  int v22; // ebp@30
  TDrawArea **v23; // edi@30
  int LoadOk; // [sp+10h] [bp-10h]@1

  v4 = this;
  v5 = this->Cursor_Shape;
  LoadOk = 1;
  if ( v5 )
  {
    TShape::~TShape(v5);
    operator delete(v5);
  }
  if ( !Reload )
  {
    v4->cursor_file_id = resId;
    sprintf(v4->cursor_file, aS_slp, cursor_file_name);
  }
  v6 = (TShape *)operator new(0x20u);
  if ( v6 )
    TShape::TShape(v6, v4->cursor_file, v4->cursor_file_id);
  else
    v7 = 0;
  v4->Cursor_Shape = v7;
  if ( v7 )
  {
    if ( TShape::is_loaded(v7) )
    {
      v8 = v4->Cursor_Shape;
      if ( v8->FShape )
      {
        v9 = TShape::shape_count(v8);
        v4->Num_Cursors = v9;
        v4->Max_CX = 0;
        v4->Max_CY = 0;
        if ( v9 > 0 )
        {
          v10 = v4->Cursor_Shape;
          v11 = 0;
          v12 = v9;
          do
          {
            v13 = (int)&v10->shape_info[v11];
            v14 = *(_DWORD *)(v13 + 16);
            if ( v14 > v4->Max_CX )
              v4->Max_CX = v14;
            v15 = *(_DWORD *)(v13 + 20);
            if ( v15 > v4->Max_CY )
              v4->Max_CY = v15;
            ++v11;
            --v12;
          }
          while ( v12 );
        }
        if ( v4->Max_CX )
        {
          if ( v4->Max_CY )
          {
            v16 = v4->save_area;
            v4->Max_CX = 64;
            v4->Max_CY = 48;
            if ( v16 || TMousePointer::create_surfaces(v4) )
            {
              TMousePointer::set_facet(v4, v4->facet);
              TMousePointer::set_game_facet(v4, v4->game_facet);
              if ( v4->Mouse_Mode )
                return LoadOk;
              v17 = v4->Num_Cursors;
              v18 = v4->Max_Cursors;
              if ( v17 <= v18 )
              {
                v19 = 0;
                if ( v17 > 0 )
                {
                  v20 = &v4->Cursor_Shape->shape_info->Height;
                  while ( *(v20 - 1) <= v4->Max_CX && *v20 <= v4->Max_CY )
                  {
                    ++v19;
                    v20 += 8;
                    if ( v19 >= v17 )
                      goto LABEL_29;
                  }
                  return 0;
                }
LABEL_29:
                v21 = 0;
                if ( v18 > 0 )
                {
                  v22 = 0;
                  v23 = v4->cursors;
                  do
                  {
                    TDrawArea::Clear(*v23, 0, 0);
                    TDrawArea::SetTrans(*v23, 1, 0);
                    if ( v21 < v4->Num_Cursors )
                    {
                      if ( TDrawArea::Lock(*v23, aMouseptrLoadcu, 1) )
                      {
                        TDrawArea::FillRect(*v23, 0, 0, v4->Max_CX, v4->Max_CY, 0);
                        TShape::shape_draw(
                          v4->Cursor_Shape,
                          *v23,
                          v4->Cursor_Shape->shape_info[v22].Hotspot_X,
                          v4->Cursor_Shape->shape_info[v22].Hotspot_Y,
                          v21,
                          0,
                          0);
                        TDrawArea::Unlock(*v23, aMouseptrLoadcu);
                      }
                      else
                      {
                        LoadOk = 0;
                      }
                    }
                    ++v21;
                    ++v23;
                    ++v22;
                  }
                  while ( v21 < v4->Max_Cursors );
                }
                return LoadOk;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

//----- (0045B560) --------------------------------------------------------
void __thiscall TMousePointer::delete_surfaces(TMousePointer *this)
{
  TMousePointer *v1; // ebp@1
  int v2; // ebx@1
  TDrawArea *v3; // esi@2
  TDrawArea **v4; // edi@5
  TDrawArea *v5; // esi@6

  v1 = this;
  v2 = 0;
  if ( this->custom_draw )
  {
    v3 = this->save_area;
    if ( v3 )
    {
      TDrawArea::~TDrawArea(this->save_area);
      operator delete(v3);
      v1->save_area = 0;
    }
    if ( v1->Max_Cursors > 0 )
    {
      v4 = v1->cursors;
      do
      {
        v5 = *v4;
        if ( *v4 )
        {
          TDrawArea::~TDrawArea(*v4);
          operator delete(v5);
          *v4 = 0;
        }
        ++v2;
        ++v4;
      }
      while ( v2 < v1->Max_Cursors );
    }
    v1->Num_Cursors = 0;
    TMousePointer::reset(v1);
  }
}

//----- (0045B5D0) --------------------------------------------------------
DrawAreaNode *__thiscall TMousePointer::create_surfaces(TMousePointer *this)
{
  TMousePointer *v1; // esi@1
  int v2; // edi@1
  DrawAreaNode *result; // eax@2
  TDrawArea *v4; // eax@6
  TDrawArea *v5; // eax@7
  TDrawArea **v6; // ebx@14
  TDrawArea *v7; // eax@16
  TDrawArea *v8; // eax@17
  char NameBuf[32]; // [sp+14h] [bp-2Ch]@16
  int v10; // [sp+3Ch] [bp-4h]@6

  v1 = this;
  v2 = 0;
  if ( !this->custom_draw )
    return (DrawAreaNode *)1;
  if ( this->save_area || this->Max_CX <= 0 || this->Max_CY <= 0 )
    goto LABEL_26;
  v4 = (TDrawArea *)operator new(0x100u);
  v10 = 0;
  if ( v4 )
    TDrawArea::TDrawArea(v4, aMouseSaveArea, 0);
  else
    v5 = 0;
  v10 = -1;
  v1->save_area = v5;
  if ( !v5 )
    return 0;
  result = TDrawArea::Init(v5, v1->render_area->DrawSystem, v1->Max_CX, v1->Max_CY, 0, 0);
  if ( result )
  {
LABEL_26:
    if ( v1->Mouse_Mode || v1->Max_Cursors <= 0 )
    {
LABEL_22:
      result = (DrawAreaNode *)1;
    }
    else
    {
      v6 = v1->cursors;
      while ( 1 )
      {
        if ( !*v6 )
        {
          sprintf(NameBuf, aMouseCursorD, v2);
          v7 = (TDrawArea *)operator new(0x100u);
          v10 = 1;
          if ( v7 )
            TDrawArea::TDrawArea(v7, NameBuf, 0);
          else
            v8 = 0;
          v10 = -1;
          *v6 = v8;
          if ( !v8 || !TDrawArea::Init(v8, v1->render_area->DrawSystem, v1->Max_CX, v1->Max_CY, 0, 0) )
            break;
        }
        ++v2;
        ++v6;
        if ( v2 >= v1->Max_Cursors )
          goto LABEL_22;
      }
      result = 0;
    }
  }
  return result;
}

//----- (0045B760) --------------------------------------------------------
int __thiscall TMousePointer::update_mouse_position(TMousePointer *this)
{
  TMousePointer *v1; // esi@1
  int result; // eax@2
  TDrawArea *v3; // eax@3
  int v4; // edx@4
  int v5; // eax@6
  int v6; // ecx@11
  signed int v7; // ecx@15
  int v8; // edx@23
  int v9; // eax@23
  int v10; // ebp@23
  int v11; // ecx@23
  int v12; // edx@23
  int v13; // eax@23
  int v14; // edx@24
  int v15; // eax@24
  int v16; // ebp@24
  int v17; // edx@24
  int v18; // edx@25
  int v19; // eax@25
  int v20; // ecx@25
  int v21; // eax@25
  int v22; // edx@25
  int v23; // eax@25
  int v24; // ecx@25
  int v25; // ebp@26
  TDrawArea *v26; // edx@27
  int v27; // eax@27
  int v28; // edi@28
  int v29; // eax@30
  int v30; // ebx@30
  int v31; // eax@31
  int v32; // ecx@32
  int v33; // eax@32
  int v34; // eax@34
  int v35; // edi@34
  int v36; // eax@35
  int v37; // eax@36
  int v38; // ecx@36
  tagPOINT point; // [sp+10h] [bp-8h]@3

  v1 = this;
  if ( this->custom_draw )
  {
    GetCursorPos(&point);
    v3 = v1->render_area;
    if ( v3->DrawSystem->ScreenMode == 1 )
    {
      ScreenToClient(v3->Wnd, &point);
      v4 = point.x;
      if ( point.x > 0x8000 )
      {
        v4 = point.x - 0x10000;
        point.x -= 0x10000;
      }
      v5 = point.y;
      if ( point.y > 0x8000 )
      {
        v5 = point.y - 0x10000;
        point.y -= 0x10000;
      }
    }
    else
    {
      v5 = point.y;
      v4 = point.x;
    }
    v1->mouse_x = v4;
    v1->mouse_y = v5;
    if ( v1->GameMode
      && v1->GameEnabled
      && (v6 = v1->mouse_x, v6 >= v1->game_window.left)
      && v6 < v1->game_window.right
      && v5 >= v1->game_window.top
      && v5 < v1->game_window.bottom )
    {
      v1->next_facet = v1->game_facet;
      v7 = 1;
    }
    else
    {
      v1->next_facet = v1->facet;
      v7 = 0;
    }
    if ( v1->save_area_valid && v4 == v1->save_x && v5 == v1->save_y && v1->next_facet == v1->last_facet )
    {
      result = 0;
    }
    else
    {
      v1->save_x = v4;
      v1->save_y = v5;
      v1->new_save_rect.left = 0;
      v1->new_save_rect.top = 0;
      if ( v7 )
      {
        v8 = v1->gWidth;
        v1->new_save_rect.bottom = v1->gHeight;
        v9 = v1->mouse_x;
        v1->new_save_rect.right = v8;
        v10 = v1->g_top;
        v1->mouse_rect.left = v9 - v1->g_left;
        v11 = v1->mouse_y;
        v1->mouse_rect.top = v1->mouse_y - v10;
        v12 = v9 + v1->g_right;
        v13 = v1->g_bottom;
        v1->mouse_rect.right = v12;
      }
      else
      {
        v14 = v1->cHeight;
        v15 = v1->mouse_x;
        v1->new_save_rect.right = v1->cWidth;
        v1->new_save_rect.bottom = v14;
        v16 = v1->d_top;
        v1->mouse_rect.left = v15 - v1->d_left;
        v11 = v1->mouse_y;
        v1->mouse_rect.top = v1->mouse_y - v16;
        v17 = v15 + v1->d_right;
        v13 = v1->d_bottom;
        v1->mouse_rect.right = v17;
      }
      v18 = v1->new_save_rect.left;
      v19 = v11 + v13;
      v20 = (int)&v1->cursor_rect.left;
      v1->mouse_rect.bottom = v19;
      v21 = v1->new_save_rect.top;
      *(_DWORD *)v20 = v18;
      v22 = v1->new_save_rect.right;
      *(_DWORD *)(v20 + 4) = v21;
      v23 = v1->new_save_rect.bottom;
      *(_DWORD *)(v20 + 8) = v22;
      *(_DWORD *)(v20 + 12) = v23;
      v24 = v1->mouse_rect.right;
      if ( v24 < 0
        || (v25 = v1->mouse_rect.bottom, v25 < 0)
        || (v26 = v1->render_area, v27 = v1->mouse_rect.left, v27 > v26->Width)
        || (v28 = v1->mouse_rect.top, v28 > v26->Height) )
      {
        v1->MouseOnScreen = 0;
        result = 1;
      }
      else
      {
        if ( v27 < 0 )
        {
          v29 = -v27;
          v1->cursor_rect.left = v29;
          v30 = v1->new_save_rect.right - v29;
          v1->mouse_rect.left = 0;
          v1->new_save_rect.right = v30;
        }
        v31 = v26->Width;
        if ( v24 > v31 )
        {
          v32 = v24 - v31;
          v33 = v1->new_save_rect.right - v32;
          v1->cursor_rect.right -= v32;
          v1->new_save_rect.right = v33;
          v1->mouse_rect.right = v26->Width;
        }
        if ( v28 < 0 )
        {
          v34 = v1->new_save_rect.bottom;
          v1->mouse_rect.top = 0;
          v35 = -v28;
          v1->cursor_rect.top = v35;
          v1->new_save_rect.bottom = v34 - v35;
        }
        v36 = v26->Height;
        if ( v25 > v36 )
        {
          v37 = v25 - v36;
          v38 = v1->new_save_rect.bottom - v37;
          v1->cursor_rect.bottom -= v37;
          v1->new_save_rect.bottom = v38;
          v1->mouse_rect.bottom = v26->Height;
        }
        result = 1;
        v1->MouseOnScreen = 1;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045BA60) --------------------------------------------------------
void __thiscall TMousePointer::draw(TMousePointer *this, int dMode)
{
  TMousePointer *v2; // esi@1
  unsigned int v3; // edi@3
  int v4; // eax@9
  IDirectDrawSurface *v5; // eax@10
  int v6; // eax@11
  int *v7; // ebx@14
  int v8; // eax@14
  int v9; // ecx@16
  IDirectDrawSurface *v10; // eax@16
  int v11; // ebp@16
  int v12; // ecx@16
  int v13; // ecx@16
  int v14; // eax@17
  int v15; // eax@22
  TShape *v16; // ecx@26
  int v17; // eax@26
  int v18; // eax@28
  int v19; // eax@32
  IDirectDrawClipper *lplpDDClipper; // [sp+20h] [bp-4h]@1

  v2 = this;
  lplpDDClipper = 0;
  if ( this->active )
  {
    if ( this->custom_draw )
    {
      v3 = debug_timeGetTime();
      if ( (!v2->GameMode || !v2->GameEnabled || dMode || v3 - v2->LastDrawTime >= 0x22)
        && (TMousePointer::update_mouse_position(v2) || dMode) )
      {
        v4 = v2->save_area_valid;
        v2->LastDrawTime = v3;
        if ( v4 )
        {
          v5 = v2->restoreSurface;
          if ( v5 != v2->PrimarySurface )
          {
            v6 = ((int (__stdcall *)(IDirectDrawSurface *, int, IDirectDrawSurface *, int, signed int, _DWORD))v5->vfptr[1].Release)(
                   v5,
                   (int)&v2->restore_rect,
                   v2->save_area->DrawSurface,
                   (int)&v2->save_rect,
                   0x1000000,
                   0);
            if ( v6 )
            {
              v2->LastddError = v6;
              return;
            }
          }
        }
        if ( v2->MouseOnScreen )
        {
          v7 = &v2->mouse_rect.left;
          v8 = ((int (__stdcall *)(_DWORD, int, _DWORD, int, signed int, _DWORD))v2->save_area->DrawSurface->vfptr[1].Release)(
                 v2->save_area->DrawSurface,
                 (int)&v2->new_save_rect,
                 v2->renderSurface,
                 (int)&v2->mouse_rect,
                 0x1000000,
                 0);
          if ( v8 )
          {
            v2->LastddError = v8;
            return;
          }
          v9 = (int)&v2->restore_rect.left;
          v10 = v2->renderSurface;
          v11 = *v7;
          v2->restoreSurface = v10;
          *(_DWORD *)v9 = v11;
          *(_DWORD *)(v9 + 4) = v2->mouse_rect.top;
          *(_DWORD *)(v9 + 8) = v2->mouse_rect.right;
          *(_DWORD *)(v9 + 12) = v2->mouse_rect.bottom;
          v12 = (int)&v2->save_rect.left;
          v2->save_rect.left = v2->new_save_rect.left;
          *(_DWORD *)(v12 + 4) = v2->new_save_rect.top;
          *(_DWORD *)(v12 + 8) = v2->new_save_rect.right;
          *(_DWORD *)(v12 + 12) = v2->new_save_rect.bottom;
          v13 = v2->Mouse_Mode;
          v2->save_area_valid = 1;
          if ( !v13 )
          {
            v14 = ((int (__stdcall *)(IDirectDrawSurface *, IDirectDrawClipper **))v10->vfptr[5].QueryInterface)(
                    v10,
                    &lplpDDClipper);
            if ( v14 == -2005532104 )
            {
              v14 = 0;
              lplpDDClipper = 0;
            }
            if ( v14 )
            {
              v2->LastddError = v14;
              return;
            }
            if ( lplpDDClipper )
            {
              v15 = ((int (__stdcall *)(_DWORD, _DWORD))v2->renderSurface->vfptr[9].AddRef)(v2->renderSurface, 0);
              if ( v15 )
              {
                v2->LastddError = v15;
                return;
              }
            }
          }
          if ( v2->Mouse_Mode == 1 && TDrawArea::Lock(v2->render_area, aMouseptrDraw, 1) )
          {
            v16 = v2->Cursor_Shape;
            v17 = (int)&v16->shape_info[v2->next_facet];
            TShape::shape_draw(
              v16,
              v2->render_area,
              *v7 + *(_DWORD *)(v17 + 24),
              v2->mouse_rect.top + *(_DWORD *)(v17 + 28),
              v2->next_facet,
              0,
              0);
            TDrawArea::Unlock(v2->render_area, aMouseptrDraw);
          }
          if ( !v2->Mouse_Mode )
          {
            TDrawArea::SetTrans(v2->cursors[v2->next_facet], 1, 0);
            v18 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, int, signed int))v2->renderSurface->vfptr[2].AddRef)(
                    v2->renderSurface,
                    *v7,
                    v2->mouse_rect.top,
                    v2->cursors[v2->next_facet]->DrawSurface,
                    (int)&v2->cursor_rect,
                    17);
            if ( v18 )
            {
              v2->LastddError = v18;
              return;
            }
          }
          v2->last_facet = v2->next_facet;
          if ( !v2->Mouse_Mode )
          {
            if ( lplpDDClipper )
            {
              v19 = ((int (__stdcall *)(_DWORD, IDirectDrawClipper *))v2->renderSurface->vfptr[9].AddRef)(
                      v2->renderSurface,
                      lplpDDClipper);
              if ( v19 )
              {
                v2->LastddError = v19;
                return;
              }
            }
          }
        }
        else
        {
          v2->save_area_valid = 0;
        }
        if ( !v2->GameMode || !v2->GameEnabled )
          InvalidateRect(v2->render_area->Wnd, &v2->mouse_rect, 0);
        v2->drawn = 1;
      }
    }
  }
}

//----- (0045BD60) --------------------------------------------------------
void __thiscall TMousePointer::erase(TMousePointer *this)
{
  TMousePointer *v1; // esi@1
  IDirectDrawSurface *v2; // eax@5
  int v3; // eax@6
  IDirectDrawSurface *v4; // eax@10

  v1 = this;
  if ( this->active )
  {
    if ( this->custom_draw )
    {
      if ( this->drawn )
      {
        if ( this->save_area_valid )
        {
          v2 = this->restoreSurface;
          if ( v2 != this->PrimarySurface )
          {
            v3 = ((int (__stdcall *)(IDirectDrawSurface *, tagRECT *, IDirectDrawSurface *, tagRECT *, signed int, _DWORD))v2->vfptr[1].Release)(
                   v2,
                   &this->restore_rect,
                   this->save_area->DrawSurface,
                   &this->save_rect,
                   0x1000000,
                   0);
            if ( v3 )
            {
              v1->LastddError = v3;
            }
            else if ( v1->GameMode && v1->GameEnabled )
            {
              v4 = v1->PrimarySurface;
              v1->save_area_valid = 1;
              v1->restoreSurface = v4;
            }
            else
            {
              InvalidateRect(v1->render_area->Wnd, &v1->restore_rect, 0);
              v1->save_area_valid = 0;
            }
          }
        }
      }
    }
  }
}

//----- (0045BE20) --------------------------------------------------------
void __thiscall TMousePointer::set_facet(TMousePointer *this, int facet_in)
{
  TShape *v2; // eax@3
  int v3; // eax@3

  if ( facet_in >= 0 && facet_in < this->Num_Cursors )
  {
    v2 = this->Cursor_Shape;
    this->facet = facet_in;
    v3 = (int)&v2->shape_info[facet_in];
    this->cWidth = *(_DWORD *)(v3 + 16);
    this->cHeight = *(_DWORD *)(v3 + 20);
    this->d_top = *(_DWORD *)(v3 + 28);
    this->d_left = *(_DWORD *)(v3 + 24);
    this->d_right = this->cWidth - *(_DWORD *)(v3 + 24);
    this->d_bottom = this->cHeight - *(_DWORD *)(v3 + 28);
  }
}

//----- (0045BE80) --------------------------------------------------------
void __thiscall TMousePointer::set_game_facet(TMousePointer *this, int facet_in)
{
  TShape *v2; // eax@3
  int v3; // eax@3

  if ( facet_in >= 0 && facet_in < this->Num_Cursors )
  {
    v2 = this->Cursor_Shape;
    this->game_facet = facet_in;
    v3 = (int)&v2->shape_info[facet_in];
    this->gWidth = *(_DWORD *)(v3 + 16);
    this->gHeight = *(_DWORD *)(v3 + 20);
    this->g_top = *(_DWORD *)(v3 + 28);
    this->g_left = *(_DWORD *)(v3 + 24);
    this->g_right = this->gWidth - *(_DWORD *)(v3 + 24);
    this->g_bottom = this->gHeight - *(_DWORD *)(v3 + 28);
  }
}

//----- (0045BEE0) --------------------------------------------------------
void __thiscall TMousePointer::off(TMousePointer *this)
{
  TMousePointer *v1; // esi@1

  v1 = this;
  if ( !this->Shutdown )
  {
    if ( this->custom_draw && this->drawn )
    {
      if ( this->save_area_valid )
      {
        TMousePointer::erase(this);
        TDrawSystem::Paint(v1->render_area->DrawSystem, &v1->restore_rect);
      }
    }
    SetCursor(0);
    v1->active = 0;
    TMousePointer::reset(v1);
  }
}

//----- (0045BF40) --------------------------------------------------------
void __thiscall TMousePointer::on(TMousePointer *this)
{
  TMousePointer *v1; // esi@1
  HCURSOR v2; // eax@3

  v1 = this;
  if ( !this->Shutdown )
  {
    if ( !this->custom_draw )
    {
      v2 = LoadCursorA(0, (LPCSTR)0x7F00);
      SetCursor(v2);
    }
    v1->active = 1;
  }
}

//----- (0045BF80) --------------------------------------------------------
void __thiscall TMousePointer::reset(TMousePointer *this)
{
  this->save_area_valid = 0;
  this->drawn = 0;
}

//----- (0045BF90) --------------------------------------------------------
void __thiscall TMousePointer::center(TMousePointer *this)
{
  TDrawArea *v1; // eax@1
  TDrawSystem *v2; // esi@1
  tagRECT win_rect; // [sp+4h] [bp-10h]@2

  v1 = this->render_area;
  v2 = v1->DrawSystem;
  if ( v1->DrawSystem->ScreenMode == 1 )
  {
    GetWindowRect(v2->Wnd, &win_rect);
    SetCursorPos(
      win_rect.left + (win_rect.right - win_rect.left) / 2,
      win_rect.top + (win_rect.bottom - win_rect.top) / 2);
  }
  else
  {
    SetCursorPos(v2->ScreenWidth / 2, v2->ScreenHeight / 2);
  }
}

//----- (0045C010) --------------------------------------------------------
void __thiscall TMousePointer::Poll(TMousePointer *this)
{
  TMousePointer *v1; // esi@1
  unsigned int v2; // edi@5
  int v3; // eax@7
  int v4; // eax@8
  int v5; // eax@13
  int v6; // eax@16
  IDirectDrawSurface *v7; // eax@18
  int v8; // eax@19
  int *v9; // ebx@22
  int v10; // eax@22
  int v11; // ecx@24
  int v12; // eax@24
  int v13; // edx@24
  int v14; // ecx@24
  int v15; // edx@24
  int v16; // eax@25
  TShape *v17; // ecx@29
  int v18; // eax@29
  int v19; // eax@34
  IDirectDrawClipper *lplpDDClipper; // [sp+Ch] [bp-4h]@1

  v1 = this;
  lplpDDClipper = 0;
  if ( this->active )
  {
    if ( this->custom_draw )
    {
      if ( this->GameMode )
      {
        if ( this->GameEnabled )
        {
          v2 = debug_timeGetTime();
          if ( v2 - v1->LastDrawTime >= 0x22 )
          {
            if ( TMousePointer::update_mouse_position(v1) )
            {
              v3 = v1->Mouse_Mode;
              v1->LastDrawTime = v2;
              if ( !v3 )
              {
                v4 = ((int (__stdcall *)(_DWORD, IDirectDrawClipper **))v1->PrimarySurface->vfptr[5].QueryInterface)(
                       v1->PrimarySurface,
                       &lplpDDClipper);
                if ( v4 == -2005532104 )
                {
                  v4 = 0;
                  lplpDDClipper = 0;
                }
                if ( v4 )
                {
                  v1->LastddError = v4;
                  return;
                }
                if ( lplpDDClipper )
                {
                  v5 = ((int (__stdcall *)(_DWORD, _DWORD))v1->PrimarySurface->vfptr[9].AddRef)(v1->PrimarySurface, 0);
                  if ( v5 )
                  {
                    v1->LastddError = v5;
                    return;
                  }
                }
              }
              if ( v1->save_area_valid )
              {
                v6 = ((int (__stdcall *)(_DWORD, int, _DWORD, int, signed int, _DWORD))v1->restoreSurface->vfptr[1].Release)(
                       v1->restoreSurface,
                       (int)&v1->restore_rect,
                       v1->save_area->DrawSurface,
                       (int)&v1->save_rect,
                       0x1000000,
                       0);
                if ( v6 )
                {
                  v1->LastddError = v6;
                  return;
                }
                v7 = v1->PrimarySurface;
                if ( v1->restoreSurface != v7 )
                {
                  v8 = ((int (__stdcall *)(IDirectDrawSurface *, int, IDirectDrawSurface *, int, signed int, _DWORD))v7->vfptr[1].Release)(
                         v7,
                         (int)&v1->restore_rect,
                         v1->save_area->DrawSurface,
                         (int)&v1->save_rect,
                         0x1000000,
                         0);
                  if ( v8 )
                  {
                    v1->LastddError = v8;
                    return;
                  }
                }
              }
              if ( v1->MouseOnScreen )
              {
                v9 = &v1->mouse_rect.left;
                v10 = ((int (__stdcall *)(_DWORD, int, _DWORD, int, signed int, _DWORD))v1->save_area->DrawSurface->vfptr[1].Release)(
                        v1->save_area->DrawSurface,
                        (int)&v1->new_save_rect,
                        v1->PrimarySurface,
                        (int)&v1->mouse_rect,
                        0x1000000,
                        0);
                if ( v10 )
                {
                  v1->LastddError = v10;
                  v1->LastddError = TMousePointer::GetDDBltError(v10);
                  return;
                }
                v1->restoreSurface = v1->PrimarySurface;
                v11 = (int)&v1->restore_rect.left;
                *(_DWORD *)v11 = *v9;
                *(_DWORD *)(v11 + 4) = v1->mouse_rect.top;
                *(_DWORD *)(v11 + 8) = v1->mouse_rect.right;
                v12 = (int)&v1->save_rect.left;
                *(_DWORD *)(v11 + 12) = v1->mouse_rect.bottom;
                v13 = v1->new_save_rect.top;
                *(_DWORD *)v12 = v1->new_save_rect.left;
                v14 = v1->new_save_rect.right;
                *(_DWORD *)(v12 + 4) = v13;
                v15 = v1->new_save_rect.bottom;
                *(_DWORD *)(v12 + 8) = v14;
                v1->save_area_valid = 1;
                *(_DWORD *)(v12 + 12) = v15;
                if ( !v1->Mouse_Mode )
                {
                  TDrawArea::SetTrans(v1->cursors[v1->next_facet], 1, 0);
                  v16 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, int, signed int))v1->PrimarySurface->vfptr[2].AddRef)(
                          v1->PrimarySurface,
                          *v9,
                          v1->mouse_rect.top,
                          v1->cursors[v1->next_facet]->DrawSurface,
                          (int)&v1->cursor_rect,
                          17);
                  if ( v16 )
                  {
                    v1->LastddError = v16;
                    return;
                  }
                }
                if ( v1->Mouse_Mode == 1 && TDrawArea::Lock(v1->primary_area, aMouseptrPoll, 1) )
                {
                  v17 = v1->Cursor_Shape;
                  v18 = (int)&v17->shape_info[v1->next_facet];
                  TShape::shape_draw(
                    v17,
                    v1->primary_area,
                    *v9 + *(_DWORD *)(v18 + 24),
                    *(_DWORD *)(v18 + 28) + v1->mouse_rect.top,
                    v1->next_facet,
                    0,
                    0);
                  TDrawArea::Unlock(v1->primary_area, aMouseptrPoll);
                }
                v1->last_facet = v1->next_facet;
              }
              else
              {
                v1->save_area_valid = 0;
              }
              if ( !v1->Mouse_Mode
                && lplpDDClipper
                && (v19 = ((int (__stdcall *)(_DWORD, IDirectDrawClipper *))v1->PrimarySurface->vfptr[9].AddRef)(
                            v1->PrimarySurface,
                            lplpDDClipper)) != 0 )
              {
                v1->LastddError = v19;
              }
              else
              {
                v1->drawn = 1;
              }
            }
          }
        }
      }
    }
  }
}

//----- (0045C300) --------------------------------------------------------
int __stdcall TMousePointer::GetDDBltError(int theError)
{
  int result; // eax@4

  if ( theError <= -2147467259 )
  {
    if ( theError == -2147467259 )
      return 1;
    if ( theError == -2147467263 )
      return 17;
    return -1;
  }
  if ( theError <= -2005532617 )
  {
    if ( theError == -2005532617 )
      return 18;
    if ( theError == -2147024809 )
      return 4;
    return -1;
  }
  if ( theError <= -2005532542 )
  {
    if ( theError == -2005532542 )
      return 3;
    if ( theError == -2005532562 )
      return 2;
    return -1;
  }
  if ( theError <= -2005532492 )
  {
    if ( theError == -2005532492 )
      return 6;
    if ( theError == -2005532522 )
      return 5;
    return -1;
  }
  if ( theError <= -2005532422 )
  {
    if ( theError == -2005532422 )
      return 10;
    if ( theError == -2005532467 )
      return 8;
    return -1;
  }
  if ( theError <= -2005532382 )
  {
    if ( theError == -2005532382 )
      return 12;
    if ( theError == -2005532392 )
      return 11;
    return -1;
  }
  if ( theError <= -2005532332 )
  {
    if ( theError == -2005532332 )
      return 14;
    if ( theError == -2005532362 )
      return 13;
    return -1;
  }
  if ( theError <= -2005532222 )
  {
    if ( theError == -2005532222 )
      return 16;
    if ( theError == -2005532242 )
      return 15;
    return -1;
  }
  if ( theError == -2005532097 )
  {
    result = 7;
  }
  else if ( theError == -2005532096 )
  {
    result = 9;
  }
  else
  {
    if ( theError )
      return -1;
    result = 0;
  }
  return result;
}
