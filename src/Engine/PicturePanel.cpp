
//----- (0047A1D0) --------------------------------------------------------
void __thiscall TPicturePanel::TPicturePanel(TPicturePanel *this)
{
  TPicturePanel *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->keep_loaded = 1;
  v1->size_from_pic = 0;
  v1->own_pic = 0;
  v1->pic_type = 0;
  v1->pic = 0;
  v1->shape = 0;
  v1->handle_mouse_input = 0;
  v1->pic_name[0] = 0;
  v1->vfptr = (TPanelVtbl *)&TPicturePanel::`vftable';
  v1->panel_type = 2;
  v1->res_id = -1;
}
// 571750: using guessed type int (__thiscall *TPicturePanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047A230) --------------------------------------------------------
TPicturePanel *__thiscall TPicturePanel::`scalar deleting destructor'(TPicturePanel *this, unsigned int __flags)
{
  TPicturePanel *v2; // esi@1

  v2 = this;
  TPicturePanel::~TPicturePanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0047A2A0) --------------------------------------------------------
int __thiscall TPicturePanel::setup(TPicturePanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, char *pic_name_in, int res_id_in, int size_from_pic_in, int keep_loaded_in)
{
  TPicturePanel *v11; // ebx@1
  int v12; // eax@4
  int v13; // ecx@4
  TPicture *v14; // eax@9
  int v15; // edi@9
  int v16; // esi@9

  v11 = this;
  if ( pic_name_in )
    strcpy(this->pic_name, pic_name_in);
  else
    this->pic_name[0] = 0;
  v12 = size_from_pic_in;
  this->res_id = res_id_in;
  v13 = keep_loaded_in;
  v11->size_from_pic = v12;
  v11->keep_loaded = v13;
  if ( (v12 || v13) && TPicturePanel::load_pic(v11) )
  {
    if ( v11->size_from_pic )
    {
      if ( v11->pic_type )
      {
        TShape::shape_bounds(v11->shape, 0, (__int16 *)&pic_name_in, (__int16 *)&res_id_in);
        v15 = (signed __int16)pic_name_in;
        v16 = (signed __int16)res_id_in;
      }
      else
      {
        v14 = v11->pic;
        v15 = v14->Width;
        v16 = v14->Height;
      }
    }
    else
    {
      v16 = hgt_in;
      v15 = wid_in;
    }
    if ( !v11->keep_loaded )
      TPicturePanel::free_pic(v11);
  }
  else
  {
    v16 = hgt_in;
    v15 = wid_in;
  }
  TPanel::setup((TPanel *)&v11->vfptr, render_area_in, parent_panel_in, x_in, y_in, v15, v16, 0);
  return 1;
}

//----- (0047A3A0) --------------------------------------------------------
void __thiscall TPicturePanel::set_picture(TPicturePanel *this, TShape *pic_in, int res_id_in)
{
  TPicturePanel *v3; // esi@1
  TPanelVtbl *v4; // edx@1

  v3 = this;
  TPicturePanel::free_pic(this);
  v4 = v3->vfptr;
  v3->res_id = res_id_in;
  v3->shape = pic_in;
  v3->own_pic = 0;
  v4->set_redraw((TPanel *)v3, RedrawNormal);
}

//----- (0047A3E0) --------------------------------------------------------
int __thiscall TPicturePanel::load_pic(TPicturePanel *this)
{
  TPicturePanel *v1; // esi@1
  TShape *v2; // eax@2
  TShape *v3; // eax@3
  TShape *v4; // eax@6
  int result; // eax@12
  TShape *v6; // edi@13
  TPicture *v7; // eax@16
  TPicture *v8; // eax@17
  TPicture *v9; // edi@17
  char file_name[80]; // [sp+14h] [bp-5Ch]@2
  int v11; // [sp+6Ch] [bp-4h]@2

  v1 = this;
  TPicturePanel::free_pic(this);
  if ( v1->pic_name[0] )
  {
    sprintf(file_name, aS_shp, v1->pic_name);
    v2 = (TShape *)operator new(0x20u);
    v11 = 0;
    if ( v2 )
    {
      TShape::TShape(v2, file_name, v1->res_id);
      v11 = -1;
    }
    else
    {
      v3 = 0;
      v11 = -1;
    }
  }
  else
  {
    if ( v1->res_id == -1 )
      return 0;
    v4 = (TShape *)operator new(0x20u);
    v11 = 1;
    if ( v4 )
      TShape::TShape(v4, message_in, v1->res_id);
    else
      v3 = 0;
    v11 = -1;
  }
  v1->shape = v3;
  if ( v3 )
  {
    if ( TShape::is_loaded(v3) )
    {
      result = 1;
      v1->pic_type = 1;
      v1->own_pic = 1;
      return result;
    }
    v6 = v1->shape;
    if ( v6 )
    {
      TShape::~TShape(v1->shape);
      operator delete(v6);
    }
    v1->shape = 0;
  }
  sprintf(file_name, aS_bmp, v1->pic_name);
  v7 = (TPicture *)operator new(0x20u);
  v11 = 2;
  if ( v7 )
  {
    TPicture::TPicture(v7, file_name, -1, 0, 0, 0);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v11 = -1;
  v1->pic = v9;
  if ( v9 )
  {
    if ( v9->Dib )
    {
      result = 1;
      v1->pic_type = 0;
      v1->own_pic = 1;
      return result;
    }
    TPicture::~TPicture(v9);
    operator delete(v9);
    v1->pic = 0;
  }
  return 0;
}

//----- (0047A5B0) --------------------------------------------------------
void __thiscall TPicturePanel::free_pic(TPicturePanel *this)
{
  TPicturePanel *v1; // esi@1
  TPicture *v2; // edi@1
  TShape *v3; // edi@6

  v1 = this;
  v2 = this->pic;
  if ( v2 )
  {
    if ( this->own_pic && v2 )
    {
      TPicture::~TPicture(this->pic);
      operator delete(v2);
    }
    v1->pic = 0;
  }
  v3 = v1->shape;
  if ( v3 )
  {
    if ( v1->own_pic && v3 )
    {
      TShape::~TShape(v1->shape);
      operator delete(v3);
    }
    v1->shape = 0;
  }
  v1->own_pic = 0;
}

//----- (0047A630) --------------------------------------------------------
void __thiscall TPicturePanel::draw(TPicturePanel *this)
{
  TPicturePanel *v1; // esi@1
  TPanelVtbl *v2; // edi@4
  TPicture *v3; // ecx@8
  TShape *v4; // ecx@10

  v1 = this;
  if ( this->render_area && this->visible && this->active )
  {
    v2 = this->vfptr;
    ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
    if ( !v1->keep_loaded )
      TPicturePanel::load_pic(v1);
    if ( TDrawArea::Lock(v1->render_area, aPnl_picDraw, 1) )
    {
      if ( v1->pic_type )
      {
        v4 = v1->shape;
        if ( v4 )
          TShape::shape_draw(v4, v1->render_area, v1->pnl_x, v1->pnl_y, 0, 0, 0);
      }
      else
      {
        v3 = v1->pic;
        if ( v3 )
          TPicture::Draw(v3, v1->render_area, v1->pnl_x, v1->pnl_y, 0, 0);
      }
      TDrawArea::Unlock(v1->render_area, aPnl_picDraw);
    }
    if ( !v1->keep_loaded )
      TPicturePanel::free_pic(v1);
    v2->draw_finish((TPanel *)v1);
  }
}
