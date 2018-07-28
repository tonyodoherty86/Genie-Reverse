
int SDI_Object_ID;
int SDI_Draw_Line;
int ASM_Fast_Count;
int Shape_Loads;
int SDI_Draw_Level;
int fog_next_shape;
int SDI_Capture_Info;
DClipInfo_List *SDI_List;

TShape::TShape(char *filename, int resource_file_id)
{
  TShape *v3; // ebp@1
  int v4; // ebx@2
  int v5; // eax@3
  int v6; // esi@3
  __int32 v7; // edi@4
  SLhape_File_Header *v8; // eax@4
  int v9; // eax@6
  int v10; // esi@6
  __int32 v11; // edi@7
  char *v12; // eax@7
  char *v13; // eax@12
  char *v14; // eax@15
  char NextFile[260]; // [sp+10h] [bp-104h]@3

  v3 = this;
  this->shape = 0;
  this->shape_header = 0;
  this->head = 0;
  this->offsets = 0;
  this->FShape = 0;
  if ( shape_file_first || (v4 = resource_file_id, resource_file_id < 0) )
  {
    color_log(84, 84, 1);
    strcpy(NextFile, filename);
    strcpy(&NextFile[strlen(NextFile) - 3], aSlp);
    ++Shape_Loads;
    v5 = _open(NextFile, 0x8000);
    v6 = v5;
    if ( v5 != -1 )
    {
      lseek(v5, 0, 2);
      v7 = _tell(v6);
      v3->FShape = (SLhape_File_Header *)malloc(v7);
      lseek(v6, 0, 0);
      read(v6, v3->FShape, v7);
      _close(v6);
      v8 = v3->FShape;
      v3->load_type = 1;
      v3->shape_info = (Shape_Info *)&v8[1];
      v3->load_size = v7;
    }
    if ( !v3->FShape )
    {
      strcpy(&NextFile[strlen(NextFile) - 3], aShp);
      v9 = _open(NextFile, 0x8000);
      v10 = v9;
      if ( v9 != -1 )
      {
        lseek(v9, 0, 2);
        v11 = _tell(v10);
        v3->shape = (char *)malloc(v11);
        lseek(v10, 0, 0);
        read(v10, v3->shape, v11);
        _close(v10);
        v12 = v3->shape;
        v3->head = (Shape_File_Header *)v3->shape;
        v3->offsets = (Shape_Offsets *)(v12 + 8);
        v3->load_type = 1;
        v3->load_size = v11;
      }
    }
    color_log(84, 95, 1);
    v4 = resource_file_id;
  }
  if ( !v3->FShape && !v3->shape && v4 >= 0 )
  {
    ++Shape_Loads;
    v13 = RESFILE_load(0x73687020u, v4, &v3->load_type, &v3->load_size);
    v3->shape = v13;
    if ( v13 )
    {
      if ( *(_DWORD *)v13 == *(_DWORD *)a1_10 )
      {
        v3->head = (Shape_File_Header *)v13;
        v3->offsets = (Shape_Offsets *)(v13 + 8);
      }
    }
    else
    {
      v14 = RESFILE_load(0x736C7020u, v4, &v3->load_type, &v3->load_size);
      v3->shape = v14;
      if ( v14 )
      {
        v3->FShape = (SLhape_File_Header *)v14;
        v3->shape = 0;
        v3->shape_info = (Shape_Info *)(v14 + 32);
      }
    }
  }
}

TShape::~TShape()
{
    /* Destroy SLP */
    if ( this->FShape )
    {
        if ( this->load_type == 1 )
            delete this->FShape;

        if ( !this->load_type )
            RESFILE_Decommit_Mapped_Memory(this->FShape->Version, this->load_size);
    }
    /* Destroy SHP */
    if ( this->shape )
    {
        if ( this->load_type == 1 )
            delete this->shape;

        if ( this->load_type == 0 )
            RESFILE_Decommit_Mapped_Memory(this->shape, this->load_size);
    }
    this->shape = 0;
    this->shape_header = 0;
    this->head = 0;
    this->offsets = 0;
    this->FShape = 0;
}

#define SHAPE_HEADER_VERSION "1.10"

/*
Determines if a shape is valid.
Returns TRUE if the shape is invalid, otherwise FALSE.
This method should be protected.
*/
bool TShape::Check_shape(int shape_num)
{
    switch( true )
    {
        /* SHP and SLP not loaded */
        case this->shape == nullptr && this->FShape == nullptr:
            return true;

        /* SHP without a header */
        case this->shape && this->head == nullptr:
            return true;

        /* SHP number out of bounds */
        case this->shape && shape_num >= 0 && shape_num >= this->head->shape_num:
            return true;

        /* SHP version wrong */
        case this->shape && this->head->version != SHAPE_HEADER_VERSION:
            return true;

        /* SLP number out of bounds */
        case this->FShape && shape_num >= 0 && shape_num >= this->FShape->Num_Shapes:
            return true;

        /* SHP is valid */
        default:
            return false;
    }
}

bool TShape::is_loaded()
{
  return this->shape || this->FShape;
}

bool TShape::shape_bounds(int shape_num, short *width, short *height)
{
    switch( true )
    {
        case this->FShape:
            *width =  this->shape_info[shape_num].Width;
            *height = this->shape_info[shape_num].Height;
            return true;

        /* Shape resolution */
        case shape_num >= 0 && this->Check_shape(shape_num):
            this->shape_header = &this->shape[this->offsets[shape_num].shape];
            *width =  this->shape_header->bounds >> 16;
            *height = this->shape_header->bounds;
            return true;

        default:
            return false;
    }
}

int TShape::shape_count()
{
    /* Shape count */
    if ( this->Check_shape(-1) )
        return 0;

    _DWORD *v3 = (_DWORD *)this->FShape->Version;
    if ( !v3 )
        v3 = &this->head->version;

    return v3[1];
}

bool TShape::shape_minmax(int *x_min, int *y_min, int *x_max, int *y_max, int shape_num)
{
    switch( true )
    {
        case this->FShape:
            *x_min = -this->shape_info[shape_num].Hotspot_X;
            *y_min = -this->shape_info[shape_num].Hotspot_Y;
            *x_max = +this->shape_info[shape_num].Width  - this->shape_info[shape_num].Hotspot_X - 1;
            *y_max = +this->shape_info[shape_num].Height - this->shape_info[shape_num].Hotspot_Y - 1;
            return true;

        /* Shape minimum XY */
        case shape_num >= 0 && this->Check_shape(shape_num):
            this->shape_header = &this->shape[this->offsets[shape_num].shape];
            *x_min = this->shape_header->xmin;
            *y_min = this->shape_header->ymin;
            *x_max = this->shape_header->xmax;
            *y_max = this->shape_header->ymax;
            return true;

        default:
            return false;
    }
}

bool TShape::shape_check(int check_x, int check_y, int shape_num)
{
  TShape *v4; // esi@1
  SLhape_File_Header *v5; // ebx@3
  int v6; // eax@4
  int v7; // edi@4
  int v8; // ebp@4
  int v9; // ecx@4
  int v10; // esi@8
  int v11; // edx@8
  int v12; // ecx@8
  char *v13; // eax@11
  unsigned __int8 v14; // dl@13
  unsigned int v15; // edx@14
  int v16; // esi@16
  int v17; // eax@16
  int v18; // edx@19
  unsigned int v19; // edx@20
  unsigned int v20; // edx@24
  unsigned int v21; // edx@28
  int v23; // ecx@33
  int v24; // edx@33
  int v25; // ebx@33
  int v26; // edi@33
  unsigned __int8 *v27; // eax@33
  int v28; // ecx@33
  int v29; // ebp@35
  int v30; // esi@38
  char v31; // dl@39
  unsigned __int8 v32; // cl@40
  int v33; // ecx@48
  unsigned __int8 v34; // dl@49
  unsigned __int8 check_xa; // [sp+14h] [bp+4h]@13
  unsigned __int8 check_xb; // [sp+14h] [bp+4h]@50
  char command; // [sp+18h] [bp+8h]@48

  v4 = this;
  /* Shape draw */
  if ( shape_num >= 0 && !this->Check_shape(shape_num) )
  {
    v5 = v4->FShape;
    if ( v5 )
    {
      v6 = (int)&v4->shape_info[shape_num];
      v7 = check_x + *(_DWORD *)(v6 + 24);
      v8 = *(_DWORD *)(v6 + 16);
      v9 = check_y + *(_DWORD *)(v6 + 28);
      if ( v7 >= 0 && v9 >= 0 && v7 < v8 && v9 < *(_DWORD *)(v6 + 20) )
      {
        v10 = 4 * v9;
        v11 = (int)v5 + *(_DWORD *)(v6 + 4);
        v12 = *(_WORD *)(v11 + 4 * v9);
        if ( v12 >= 0 && v7 >= v12 && v7 <= v8 - *(_WORD *)(v11 + v10 + 2) )
        {
          v13 = &v5->Version[*(_DWORD *)(&v5->Version[*(_DWORD *)v6] + v10)];
          if ( v12 < v8 )
          {
            while ( v7 >= v12 )
            {
              v14 = *v13++;
              check_xa = v14;
              switch ( v14 & 0xF )
              {
                case 0:
                case 4:
                case 8:
                case 0xC:
                  v15 = (unsigned int)v14 >> 2;
                  v12 += v15;
                  if ( v7 < v12 )
                    return 1;
                  v13 += v15;
                  break;
                case 2:
                  v16 = (unsigned __int8)*v13 | 16 * v14;
                  v17 = (int)(v13 + 1);
                  v12 += v16;
                  if ( v7 < v12 )
                    return 1;
                  v13 = (char *)(v16 + v17);
                  break;
                case 1:
                case 5:
                case 9:
                case 0xD:
                  v12 += (unsigned int)v14 >> 2;
                  break;
                case 3:
                  v18 = (unsigned __int8)*v13++;
                  v12 += v18 | 16 * check_xa;
                  break;
                case 6:
                  v19 = (unsigned int)v14 >> 4;
                  if ( !((unsigned int)check_xa >> 4) )
                    v19 = (unsigned __int8)*v13++;
                  v12 += v19;
                  if ( v7 < v12 )
                    return 1;
                  v13 += v19;
                  break;
                case 7:
                case 0xA:
                  v20 = (unsigned int)v14 >> 4;
                  if ( !((unsigned int)check_xa >> 4) )
                    v20 = (unsigned __int8)*v13++;
                  v12 += v20;
                  if ( v7 < v12 )
                    return 1;
                  ++v13;
                  break;
                case 0xB:
                  v21 = (unsigned int)v14 >> 4;
                  if ( !((unsigned int)check_xa >> 4) )
                    v21 = (unsigned __int8)*v13++;
                  v12 += v21;
                  if ( v7 < v12 )
                    return 1;
                  break;
                default:
                  return 0;
              }
              if ( v12 >= v8 )
                return 0;
            }
          }
        }
      }
      return 0;
    }
    v23 = (int)&v4->shape[v4->offsets[shape_num].shape];
    v4->shape_header = (Shape_Header *)v23;
    v24 = *(_DWORD *)(v23 + 12);
    v25 = *(_DWORD *)(v23 + 8);
    v26 = *(_DWORD *)(v23 + 16);
    v27 = (unsigned __int8 *)(v23 + 24);
    v28 = *(_DWORD *)(v23 + 20);
    if ( check_y >= v24 && check_y <= v28 )
    {
      v29 = check_x;
      if ( check_x >= v25 && check_x <= v26 )
      {
        if ( v24 >= check_y )
          goto LABEL_48;
        v30 = check_y - v24;
        while ( 1 )
        {
          v31 = 0;
          do
          {
            v32 = *v27++;
            if ( (v32 & 1) == 1 )
            {
              if ( v32 >> 1 )
              {
                v27 += v32 >> 1;
                continue;
              }
            }
            else if ( !(v32 & 0xFE) )
            {
              v31 = 1;
              continue;
            }
            ++v27;
          }
          while ( !v31 );
          if ( !--v30 )
          {
LABEL_48:
            v33 = v25;
            command = 0;
            while ( 1 )
            {
              v34 = *v27++;
              if ( (v34 & 1) == 1 )
              {
                check_xb = v34 >> 1;
                if ( !(v34 >> 1) )
                {
                  v33 += *v27;
                  if ( v33 > v29 )
                    return 0;
LABEL_58:
                  ++v27;
                  goto LABEL_59;
                }
                v33 += check_xb;
                if ( v33 > v29 )
                  return 1;
                v27 += check_xb;
              }
              else
              {
                if ( v34 >> 1 )
                {
                  v33 += v34 >> 1;
                  if ( v33 > v29 )
                    return 1;
                  goto LABEL_58;
                }
                command = 1;
              }
LABEL_59:
              if ( command )
                return 0;
            }
          }
        }
      }
    }
  }
  return 0;
}

bool TShape::shape_draw(TDrawArea *drawarea, int x, int y, int shape_num, char flags, char *color_table)
{
  TShape *v7; // esi@1
  SLhape_File_Header *v8; // eax@3
  Shape_Info *v9; // edi@5
  int v10; // ST24_4@5
  int v11; // ST20_4@5
  int v12; // eax@5
  char result; // al@5
  TSpan_List_Manager *v14; // eax@6
  int v15; // edx@6
  int v16; // edi@6
  int v17; // edx@7
  SLhape_File_Header *v18; // esi@11
  int v19; // eax@11
  TDrawArea *v20; // edi@12
  int v21; // edx@13
  int v22; // ebx@13
  int v23; // eax@13
  int v24; // ecx@13
  int v25; // ebp@13
  int v26; // edx@25
  int v27; // ebx@25
  int v28; // edx@27
  int v29; // edx@30
  int shape_y1; // [sp+14h] [bp-18h]@13
  int shape_x1; // [sp+18h] [bp-14h]@13
  int rect; // [sp+1Ch] [bp-10h]@12
  int rect_4; // [sp+20h] [bp-Ch]@12
  int rect_8; // [sp+24h] [bp-8h]@12
  int rect_12; // [sp+28h] [bp-4h]@12
  TDrawArea *drawareaa; // [sp+30h] [bp+4h]@13
  int clip_x0; // [sp+34h] [bp+8h]@13
  int clip_x1; // [sp+38h] [bp+Ch]@13

  v7 = this;
  /* Shape draw */
  if ( shape_num < 0 || TShape::Check_shape(this, shape_num) )
    return 0;
  v8 = v7->FShape;
  if ( !v8 )
  {
    v20 = drawarea;
    rect = drawarea->ClipRect.left;
    rect_4 = drawarea->ClipRect.top;
    rect_8 = drawarea->ClipRect.right;
    rect_12 = drawarea->ClipRect.bottom;
    if ( v7->shape )
    {
      v21 = (int)&v7->shape[v7->offsets[shape_num].shape];
      v7->shape_header = (Shape_Header *)v21;
      v22 = x + *(_DWORD *)(v21 + 16);
      v23 = x + *(_DWORD *)(v21 + 8);
      drawareaa = (TDrawArea *)v23;
      v24 = y + *(_DWORD *)(v21 + 12);
      shape_y1 = y + *(_DWORD *)(v21 + 20);
      v25 = y + *(_DWORD *)(v21 + 20);
      clip_x1 = y + *(_DWORD *)(v21 + 12);
      shape_x1 = x + *(_DWORD *)(v21 + 16);
      clip_x0 = x + *(_DWORD *)(v21 + 16);
      if ( v23 < rect )
        drawareaa = (TDrawArea *)rect;
      if ( v24 < rect_4 )
        clip_x1 = rect_4;
      if ( v22 > rect_8 )
        clip_x0 = rect_8;
      if ( shape_y1 > rect_12 )
        v25 = rect_12;
      if ( (signed int)drawareaa < 0 )
        drawareaa = 0;
      if ( clip_x1 < 0 )
        clip_x1 = 0;
      v26 = v20->Width;
      v27 = clip_x0;
      if ( clip_x0 >= v26 )
      {
        v27 = v26 - 1;
        clip_x0 = v26 - 1;
      }
      v28 = v20->Height;
      if ( v25 >= v28 )
        v25 = v28 - 1;
      if ( v27 >= (signed int)drawareaa )
      {
        v29 = clip_x1;
        if ( v25 >= clip_x1 )
        {
          if ( drawareaa == (TDrawArea *)v23 && clip_x1 == v24 )
          {
            if ( clip_x0 == shape_x1 && v25 == shape_y1 )
            {
              if ( !flags )
                return TShape::shape_draw_unclipped(v7, v20, v23, v24, shape_num);
              if ( flags == 1 )
              {
                if ( color_table )
                  result = TShape::shape_color_trans_unclipped(v7, v20, v23, v24, shape_num, color_table);
                else
                  result = TShape::shape_draw_unclipped(v7, v20, v23, v24, shape_num);
                return result;
              }
              if ( flags == 2 )
              {
                if ( color_table )
                  result = TShape::shape_shadow_unclipped(v7, v20, v23, v24, color_table);
                else
                  result = TShape::shape_draw_unclipped(v7, v20, v23, v24, shape_num);
                return result;
              }
              return 0;
            }
            v29 = clip_x1;
          }
          if ( flags )
          {
            if ( flags == 1 )
            {
              if ( color_table )
                return TShape::shape_color_trans_clipped(
                         v7,
                         v20,
                         v23,
                         v24,
                         shape_num,
                         (int)drawareaa,
                         v29,
                         clip_x0,
                         v25,
                         color_table);
            }
            else
            {
              if ( flags != 2 )
                return 0;
              if ( color_table )
                return TShape::shape_shadow_clipped(v7, v20, v23, v24, (int)drawareaa, v29, clip_x0, v25, color_table);
            }
          }
          return TShape::shape_draw_clipped(v7, v20, v23, v24, (int)drawareaa, v29, clip_x0, v25);
        }
      }
    }
    return 0;
  }
  if ( SDI_Capture_Info )
  {
    v9 = (Shape_Info *)&v8[shape_num + 1];
    v10 = SDI_Object_ID;
    v11 = SDI_Draw_Level;
    v12 = ASMGet_Color_Xform();
    DClipInfo_List::AddDrawNode(
      SDI_List,
      v7->FShape,
      v9,
      SDI_Draw_Line,
      x - v9->Hotspot_X,
      y - v9->Hotspot_Y,
      fog_next_shape,
      color_table,
      v12,
      v11,
      v10);
    result = 1;
  }
  else
  {
    v14 = drawarea->CurSpanList;
    v15 = drawarea->SpanList->Num_Lines;
    v16 = v14->Num_Lines;
    if ( v15 >= v16 )
      v17 = v16 - 1;
    else
      v17 = v15 - 1;
    ASMSet_Surface_Info(
      (int)drawarea->CurDisplayOffsets,
      (int)v14->Line_Head_Ptrs,
      (int)v14->Line_Tail_Ptrs,
      0,
      0,
      v14->Max_Span_Px,
      v17);
    if ( color_table )
      ASMSet_Xlate_Table((int)color_table);
    v18 = v7->FShape;
    v19 = (int)&v18[shape_num + 1];
    ASMDraw_Sprite(
      v18,
      x - *(_DWORD *)(v19 + 24),
      y - *(_DWORD *)(v19 + 28),
      *(_DWORD *)(v19 + 16),
      *(_DWORD *)(v19 + 20),
      *(_DWORD *)v19,
      *(_DWORD *)(v19 + 4),
      fog_next_shape);
    ++ASM_Fast_Count;
    result = 1;
  }
  return result;
}

bool TShape::shape_draw_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int shape_num)
{
  Shape_Header *v5; // eax@1
  int v6; // esi@1
  int v7; // ebp@1
  unsigned __int8 *v8; // edi@1
  int v9; // eax@1
  int v10; // esi@2
  char *v11; // esi@4
  char v12; // bl@6
  unsigned __int8 v13; // al@7
  bool v14; // zf@16
  int width; // [sp+10h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+18h] [bp+4h]@5
  int shape_x0a; // [sp+1Ch] [bp+8h]@4
  unsigned __int8 save_buffer; // [sp+20h] [bp+Ch]@8
  unsigned __int8 save_buffera; // [sp+20h] [bp+Ch]@11

  v5 = this->shape_header;
  v6 = drawarea->Orien;
  v7 = v5->ymax - v5->ymin + 1;
  v8 = (unsigned __int8 *)&v5[1];
  v9 = v6 * TDrawArea::AlignedWidth(drawarea);
  width = v9;
  if ( v6 >= 1 )
    v10 = shape_y0 * v9;
  else
    v10 = v9 * (shape_y0 - drawarea->Height + 1);
  v11 = &drawarea->Bits[v10] + shape_x0;
  shape_x0a = (int)v11;
  if ( v7 > 0 )
  {
    drawareaa = (TDrawArea *)v7;
    do
    {
      v12 = 0;
      do
      {
        v13 = *v8++;
        if ( (v13 & 1) == 1 )
        {
          save_buffer = v13 >> 1;
          if ( v13 >> 1 )
          {
            memcpy(v11, v8, save_buffer);
            v11 += save_buffer;
            v8 += save_buffer;
            continue;
          }
          v11 += *v8;
        }
        else
        {
          save_buffera = v13 >> 1;
          if ( !(v13 >> 1) )
          {
            v12 = 1;
            continue;
          }
          memset(v11, *v8, save_buffera);
          v11 += save_buffera;
        }
        ++v8;
      }
      while ( !v12 );
      v11 = (char *)(width + shape_x0a);
      v14 = drawareaa == (TDrawArea *)1;
      shape_x0a += width;
      drawareaa = (TDrawArea *)((char *)drawareaa - 1);
    }
    while ( !v14 );
  }
  return 1;
}

bool TShape::shape_color_trans_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int shape_num, char *color_table)
{
  Shape_Header *v6; // edi@1
  int v7; // esi@1
  int v8; // ebp@1
  unsigned __int8 *v9; // edi@1
  int v10; // eax@1
  int v11; // esi@2
  char *v12; // esi@4
  unsigned __int8 v13; // al@7
  unsigned int i; // eax@10
  int v15; // edx@11
  bool v16; // zf@18
  int v18; // [sp+10h] [bp-8h]@5
  int width; // [sp+14h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+1Ch] [bp+4h]@4
  unsigned __int8 save_buffer; // [sp+20h] [bp+8h]@13
  char command; // [sp+24h] [bp+Ch]@6

  v6 = this->shape_header;
  v7 = drawarea->Orien;
  v8 = v6->ymax - v6->ymin + 1;
  v9 = (unsigned __int8 *)&v6[1];
  v10 = v7 * TDrawArea::AlignedWidth(drawarea);
  width = v10;
  if ( v7 >= 1 )
    v11 = shape_y0 * v10;
  else
    v11 = v10 * (shape_y0 - drawarea->Height + 1);
  v12 = &drawarea->Bits[v11] + shape_x0;
  drawareaa = (TDrawArea *)v12;
  if ( v8 > 0 )
  {
    v18 = v8;
    do
    {
      command = 0;
      do
      {
        v13 = *v9++;
        if ( (v13 & 1) != 1 )
        {
          save_buffer = v13 >> 1;
          if ( !(v13 >> 1) )
          {
            command = 1;
            continue;
          }
          memset(v12, (unsigned __int8)color_table[*v9], save_buffer);
          v12 += save_buffer;
          goto LABEL_16;
        }
        if ( !(v13 >> 1) )
        {
          v12 += *v9;
LABEL_16:
          ++v9;
          continue;
        }
        for ( i = (unsigned int)&v12[v13 >> 1]; (unsigned int)v12 < i; *(v12 - 1) = color_table[v15] )
        {
          v15 = *v9++;
          ++v12;
        }
      }
      while ( !command );
      v12 = (char *)drawareaa + width;
      v16 = v18 == 1;
      drawareaa = (TDrawArea *)((char *)drawareaa + width);
      --v18;
    }
    while ( !v16 );
  }
  return 1;
}

bool TShape::shape_shadow_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, char *color_table)
{
  Shape_Header *v5; // eax@1
  unsigned __int8 *v6; // ebp@1
  int v7; // esi@1
  int v8; // ebx@1
  int v9; // eax@1
  int v10; // ecx@2
  char *v11; // ecx@4
  char v12; // bl@6
  unsigned __int8 v13; // dl@7
  unsigned int j; // edx@10
  int v15; // eax@11
  unsigned int i; // edx@15
  int v17; // eax@16
  bool v18; // zf@19
  int width; // [sp+10h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+18h] [bp+4h]@5
  int shape_x0a; // [sp+1Ch] [bp+8h]@4
  unsigned __int8 save_buffer; // [sp+20h] [bp+Ch]@8

  v5 = this->shape_header;
  v6 = (unsigned __int8 *)&v5[1];
  v7 = v5->ymax - v5->ymin + 1;
  v8 = drawarea->Orien;
  v9 = v8 * TDrawArea::AlignedWidth(drawarea);
  width = v9;
  if ( v8 >= 1 )
    v10 = shape_y0 * v9;
  else
    v10 = v9 * (shape_y0 - drawarea->Height + 1);
  v11 = &drawarea->Bits[v10] + shape_x0;
  shape_x0a = (int)v11;
  if ( v7 > 0 )
  {
    drawareaa = (TDrawArea *)v7;
    do
    {
      v12 = 0;
      do
      {
        v13 = *v6++;
        if ( (v13 & 1) != 1 )
        {
          if ( !(v13 >> 1) )
          {
            v12 = 1;
            continue;
          }
          for ( i = (unsigned int)&v11[v13 >> 1]; (unsigned int)v11 < i; *(v11 - 1) = color_table[v17] )
            v17 = (unsigned __int8)*v11++;
          goto LABEL_17;
        }
        save_buffer = v13 >> 1;
        if ( !(v13 >> 1) )
        {
          v11 += *v6;
LABEL_17:
          ++v6;
          continue;
        }
        for ( j = (unsigned int)&v11[save_buffer]; (unsigned int)v11 < j; *(v11 - 1) = color_table[v15] )
          v15 = (unsigned __int8)*v11++;
        v6 += save_buffer;
      }
      while ( !v12 );
      v11 = (char *)(width + shape_x0a);
      v18 = drawareaa == (TDrawArea *)1;
      shape_x0a += width;
      drawareaa = (TDrawArea *)((char *)drawareaa - 1);
    }
    while ( !v18 );
  }
  return 1;
}

bool TShape::shape_draw_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1)
{
  int v8; // esi@1
  TShape *v9; // edi@1
  int v10; // eax@1
  int v11; // ecx@1
  unsigned __int8 *v12; // edi@1
  int v13; // eax@2
  int v14; // edx@2
  char *v15; // esi@2
  int v16; // ebp@4
  char v17; // cl@6
  unsigned __int8 v18; // al@7
  int v19; // ebp@17
  unsigned __int8 v20; // al@19
  int v21; // ecx@25
  size_t v22; // ebx@27
  size_t v23; // ebx@35
  unsigned __int8 v24; // al@43
  int v25; // eax@45
  unsigned __int8 v26; // al@59
  bool v27; // zf@66
  char *save_buffer; // [sp+10h] [bp-8h]@4
  int width; // [sp+14h] [bp-4h]@1
  unsigned __int8 drawareaa; // [sp+1Ch] [bp+4h]@20
  unsigned __int8 drawareab; // [sp+1Ch] [bp+4h]@44
  unsigned __int8 drawareac; // [sp+1Ch] [bp+4h]@50
  int clip_y0a; // [sp+2Ch] [bp+14h]@5
  char clip_y0b; // [sp+2Ch] [bp+14h]@18
  char clip_y0c; // [sp+2Ch] [bp+14h]@42
  char clip_y0d; // [sp+2Ch] [bp+14h]@58
  int clip_y1a; // [sp+34h] [bp+1Ch]@16

  v8 = drawarea->Orien;
  v9 = this;
  v10 = drawarea->AlignedWidth();
  v11 = v8 * v10;
  v12 = (unsigned __int8 *)&v9->shape_header[1];
  width = v8 * v10;
  if ( v8 >= 1 )
  {
    v13 = clip_y0;
    v14 = clip_x0;
    v15 = &drawarea->Bits[clip_y0 * v11] + clip_x0;
  }
  else
  {
    v13 = clip_y0;
    v14 = clip_x0;
    v15 = &drawarea->Bits[v11 * (clip_y0 - drawarea->Height + 1)] + clip_x0;
  }
  save_buffer = v15;
  v16 = shape_y0;
  if ( shape_y0 < v13 )
  {
    clip_y0a = v13 - shape_y0;
    v16 = v13;
    do
    {
      v17 = 0;
      do
      {
        v18 = *v12++;
        if ( (v18 & 1) == 1 )
        {
          if ( v18 >> 1 )
          {
            v12 += v18 >> 1;
            continue;
          }
        }
        else if ( !(v18 & 0xFE) )
        {
          v17 = 1;
          continue;
        }
        ++v12;
      }
      while ( !v17 );
      --clip_y0a;
    }
    while ( clip_y0a );
  }
  if ( v16 <= clip_y1 )
  {
    clip_y1a = clip_y1 - v16 + 1;
    while ( 1 )
    {
      v19 = shape_x0;
      if ( shape_x0 >= v14 )
      {
        clip_y0b = 1;
      }
      else
      {
        clip_y0b = 0;
        do
        {
          v20 = *v12++;
          if ( (v20 & 1) == 1 )
          {
            drawareaa = v20 >> 1;
            if ( v20 >> 1 )
            {
              v21 = drawareaa;
              v19 += drawareaa;
              if ( v19 >= v14 )
              {
                if ( v19 <= clip_x1 )
                {
                  clip_y0b = 1;
                  v22 = v19 - clip_x0;
                  memcpy(v15, &v12[drawareaa - (v19 - clip_x0)], v19 - clip_x0);
                }
                else
                {
                  clip_y0b = 2;
                  v22 = clip_x1 - clip_x0 + 1;
                  memcpy(v15, &v12[clip_x0] + drawareaa - v19, v22);
                }
                v21 = drawareaa;
                v14 = clip_x0;
                v15 += v22;
              }
              v12 += v21;
            }
            else
            {
              v19 += *v12++;
              if ( v19 >= v14 )
              {
                if ( v19 <= clip_x1 )
                {
                  clip_y0b = 1;
                  v15 += v19 - v14;
                }
                else
                {
                  clip_y0b = 2;
                }
              }
            }
          }
          else if ( v20 >> 1 )
          {
            v19 += v20 >> 1;
            if ( v19 >= v14 )
            {
              if ( v19 <= clip_x1 )
              {
                clip_y0b = 1;
                v23 = v19 - v14;
                memset(v15, *v12, v19 - v14);
              }
              else
              {
                clip_y0b = 2;
                v23 = clip_x1 - v14 + 1;
                memset(v15, *v12, v23);
              }
              v14 = clip_x0;
              v15 += v23;
            }
            ++v12;
          }
          else
          {
            clip_y0b = 3;
          }
        }
        while ( !clip_y0b );
      }
      clip_y0c = clip_y0b - 1;
      if ( !clip_y0c )
      {
        while ( 1 )
        {
          v24 = *v12++;
          if ( (v24 & 1) == 1 )
            break;
          drawareac = v24 >> 1;
          if ( v24 >> 1 )
          {
            v19 += drawareac;
            if ( v19 <= clip_x1 )
            {
              memset(v15, *v12, drawareac);
            }
            else
            {
              clip_y0c = 1;
              memset(v15, *v12, clip_x1 - v19 + drawareac + 1);
            }
            v15 += drawareac;
            ++v12;
LABEL_56:
            v14 = clip_x0;
            goto LABEL_57;
          }
          clip_y0c = 3;
LABEL_57:
          if ( clip_y0c )
            goto LABEL_58;
        }
        drawareab = v24 >> 1;
        if ( !(v24 >> 1) )
        {
          v25 = *v12;
          v19 += v25;
          v15 += v25;
          ++v12;
          if ( v19 > clip_x1 )
            clip_y0c = 1;
          goto LABEL_57;
        }
        v19 += drawareab;
        if ( v19 <= clip_x1 )
        {
          memcpy(v15, v12, drawareab);
          v15 += drawareab;
          v12 += drawareab;
        }
        else
        {
          clip_y0c = 1;
          memcpy(v15, v12, clip_x1 - v19 + drawareab + 1);
          v15 += drawareab;
          v12 += drawareab;
        }
        goto LABEL_56;
      }
LABEL_58:
      clip_y0d = clip_y0c - 1;
      if ( !clip_y0d )
        break;
LABEL_66:
      v15 = &save_buffer[width];
      v27 = clip_y1a == 1;
      save_buffer += width;
      --clip_y1a;
      if ( v27 )
        return 1;
    }
    while ( 1 )
    {
      v26 = *v12++;
      if ( (v26 & 1) == 1 )
      {
        if ( !(v26 >> 1) )
          goto LABEL_64;
        v12 += v26 >> 1;
      }
      else
      {
        if ( v26 & 0xFE )
        {
LABEL_64:
          ++v12;
          goto LABEL_65;
        }
        clip_y0d = 2;
      }
LABEL_65:
      if ( clip_y0d )
        goto LABEL_66;
    }
  }
  return 1;
}

char shape_color_trans_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int shape_num, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table)
{
  int v10; // esi@1
  TShape *v11; // edi@1
  int v12; // eax@1
  int v13; // ecx@1
  unsigned __int8 *v14; // edi@1
  int v15; // eax@2
  int v16; // edx@2
  char *v17; // esi@2
  int v18; // ebp@4
  char v19; // cl@6
  unsigned __int8 v20; // al@7
  int v21; // ebp@17
  unsigned __int8 v22; // al@19
  int v23; // ecx@27
  int v24; // edx@27
  unsigned __int8 *v25; // edi@27
  int v26; // edx@28
  int v27; // eax@30
  unsigned int v28; // ecx@31
  int v29; // eax@32
  size_t v30; // ebx@39
  unsigned __int8 v31; // al@47
  int v32; // eax@49
  int v33; // ebx@52
  unsigned int v34; // ecx@52
  int v35; // edx@53
  unsigned int i; // eax@56
  int v37; // ecx@57
  unsigned __int8 v38; // al@67
  bool v39; // zf@74
  char *save_buffer; // [sp+10h] [bp-Ch]@4
  char *temp_buffer; // [sp+14h] [bp-8h]@27
  int width; // [sp+18h] [bp-4h]@1
  unsigned __int8 drawareaa; // [sp+20h] [bp+4h]@20
  unsigned __int8 drawareab; // [sp+20h] [bp+4h]@48
  unsigned __int8 drawareac; // [sp+20h] [bp+4h]@59
  int shape_y0a; // [sp+28h] [bp+Ch]@27
  int clip_y0a; // [sp+34h] [bp+18h]@5
  char clip_y0b; // [sp+34h] [bp+18h]@18
  char clip_y0c; // [sp+34h] [bp+18h]@46
  char clip_y0d; // [sp+34h] [bp+18h]@66
  int clip_y1a; // [sp+3Ch] [bp+20h]@16

  v10 = drawarea->Orien;
  v11 = this;
  v12 = TDrawArea::AlignedWidth(drawarea);
  v13 = v10 * v12;
  v14 = (unsigned __int8 *)&v11->shape_header[1];
  width = v10 * v12;
  if ( v10 >= 1 )
  {
    v15 = clip_y0;
    v16 = clip_x0;
    v17 = &drawarea->Bits[clip_y0 * v13] + clip_x0;
  }
  else
  {
    v15 = clip_y0;
    v16 = clip_x0;
    v17 = &drawarea->Bits[v13 * (clip_y0 - drawarea->Height + 1)] + clip_x0;
  }
  save_buffer = v17;
  v18 = shape_y0;
  if ( shape_y0 < v15 )
  {
    clip_y0a = v15 - shape_y0;
    v18 = v15;
    do
    {
      v19 = 0;
      do
      {
        v20 = *v14++;
        if ( (v20 & 1) == 1 )
        {
          if ( v20 >> 1 )
          {
            v14 += v20 >> 1;
            continue;
          }
        }
        else if ( !(v20 & 0xFE) )
        {
          v19 = 1;
          continue;
        }
        ++v14;
      }
      while ( !v19 );
      --clip_y0a;
    }
    while ( clip_y0a );
  }
  if ( v18 <= clip_y1 )
  {
    clip_y1a = clip_y1 - v18 + 1;
    while ( 1 )
    {
      v21 = shape_x0;
      if ( shape_x0 >= v16 )
      {
        clip_y0b = 1;
      }
      else
      {
        clip_y0b = 0;
        do
        {
          v22 = *v14++;
          if ( (v22 & 1) == 1 )
          {
            drawareaa = v22 >> 1;
            if ( v22 >> 1 )
            {
              v21 += drawareaa;
              if ( v21 < v16 )
              {
                v14 += drawareaa;
              }
              else if ( v21 <= clip_x1 )
              {
                clip_y0b = 1;
                v28 = (unsigned int)&v17[v21 - v16];
                for ( v14 += drawareaa - (v21 - v16); (unsigned int)v17 < v28; *(v17 - 1) = color_table[v29] )
                {
                  v29 = *v14++;
                  ++v17;
                }
              }
              else
              {
                v23 = drawareaa + v16 - v21;
                v24 = clip_x1 - clip_x0 + 1;
                v25 = &v14[v23];
                clip_y0b = 2;
                shape_y0a = v24;
                temp_buffer = &v17[v24];
                if ( v17 < &v17[v24] )
                {
                  do
                  {
                    v26 = *v25++;
                    *(++v17 - 1) = color_table[v26];
                  }
                  while ( v17 < temp_buffer );
                  v24 = shape_y0a;
                }
                v27 = drawareaa - v24;
                v16 = clip_x0;
                v14 = &v25[v27 - v23];
              }
            }
            else
            {
              v21 += *v14++;
              if ( v21 >= v16 )
              {
                if ( v21 <= clip_x1 )
                {
                  clip_y0b = 1;
                  v17 += v21 - v16;
                }
                else
                {
                  clip_y0b = 2;
                }
              }
            }
          }
          else if ( v22 >> 1 )
          {
            v21 += v22 >> 1;
            if ( v21 >= v16 )
            {
              if ( v21 <= clip_x1 )
              {
                clip_y0b = 1;
                v30 = v21 - v16;
              }
              else
              {
                clip_y0b = 2;
                v30 = clip_x1 - v16 + 1;
              }
              memset(v17, (unsigned __int8)color_table[*v14], v30);
              v16 = clip_x0;
              v17 += v30;
            }
            ++v14;
          }
          else
          {
            clip_y0b = 3;
          }
        }
        while ( !clip_y0b );
      }
      clip_y0c = clip_y0b - 1;
      while ( !clip_y0c )
      {
        v31 = *v14++;
        if ( (v31 & 1) == 1 )
        {
          drawareab = v31 >> 1;
          if ( v31 >> 1 )
          {
            v21 += drawareab;
            if ( v21 <= clip_x1 )
            {
              for ( i = (unsigned int)&v17[drawareab]; (unsigned int)v17 < i; *(v17 - 1) = color_table[v37] )
              {
                v37 = *v14++;
                ++v17;
              }
            }
            else
            {
              clip_y0c = 1;
              v33 = clip_x1 - v21 + drawareab + 1;
              v34 = (unsigned int)&v17[v33];
              if ( v17 < &v17[v33] )
              {
                do
                {
                  v35 = *v14++;
                  *(++v17 - 1) = color_table[v35];
                }
                while ( (unsigned int)v17 < v34 );
                v16 = clip_x0;
              }
              v14 += drawareab - v33;
            }
          }
          else
          {
            v32 = *v14;
            v21 += v32;
            v17 += v32;
            ++v14;
            if ( v21 > clip_x1 )
              clip_y0c = 1;
          }
        }
        else
        {
          drawareac = v31 >> 1;
          if ( v31 >> 1 )
          {
            v21 += drawareac;
            if ( v21 <= clip_x1 )
            {
              memset(v17, (unsigned __int8)color_table[*v14], drawareac);
            }
            else
            {
              clip_y0c = 1;
              memset(v17, (unsigned __int8)color_table[*v14], clip_x1 - v21 + drawareac + 1);
            }
            v16 = clip_x0;
            v17 += drawareac;
            ++v14;
          }
          else
          {
            clip_y0c = 3;
          }
        }
      }
      clip_y0d = clip_y0c - 1;
      if ( !clip_y0d )
        break;
LABEL_74:
      v17 = &save_buffer[width];
      v39 = clip_y1a == 1;
      save_buffer += width;
      --clip_y1a;
      if ( v39 )
        return 1;
    }
    while ( 1 )
    {
      v38 = *v14++;
      if ( (v38 & 1) == 1 )
      {
        if ( !(v38 >> 1) )
          goto LABEL_72;
        v14 += v38 >> 1;
      }
      else
      {
        if ( v38 & 0xFE )
        {
LABEL_72:
          ++v14;
          goto LABEL_73;
        }
        clip_y0d = 2;
      }
LABEL_73:
      if ( clip_y0d )
        goto LABEL_74;
    }
  }
  return 1;
}

char shape_shadow_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table)
{
  TDrawArea *v9; // esi@1
  TShape *v10; // ebx@1
  int v11; // edi@1
  int v12; // eax@1
  int v13; // edx@1
  unsigned __int8 *v14; // ebx@1
  int v15; // eax@2
  int v16; // ecx@2
  char *v17; // ecx@4
  int v18; // esi@4
  int v19; // edi@5
  char v20; // dl@6
  unsigned __int8 v21; // al@8
  int v22; // edx@18
  char v23; // al@19
  _BYTE *v24; // esi@20
  unsigned int v25; // esi@28
  int v26; // ebx@29
  int v27; // esi@30
  unsigned int k; // esi@31
  int v29; // ebx@32
  unsigned int j; // esi@38
  int v31; // ebx@39
  unsigned int i; // esi@41
  int v33; // ebx@42
  char v34; // al@48
  _BYTE *v35; // esi@49
  _BYTE *v36; // edi@51
  int v37; // esi@51
  unsigned int v38; // esi@54
  int v39; // ebx@55
  int v40; // esi@56
  unsigned int v41; // esi@57
  int v42; // ebx@58
  unsigned int m; // esi@63
  int v44; // ebx@64
  unsigned int l; // esi@66
  int v46; // ebx@67
  char v47; // al@71
  unsigned __int8 v48; // cl@72
  bool v49; // zf@80
  char *save_buffer; // [sp+10h] [bp-8h]@4
  int width; // [sp+14h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+1Ch] [bp+4h]@1
  int shape_y0a; // [sp+24h] [bp+Ch]@17
  unsigned __int8 clip_y0a; // [sp+2Ch] [bp+14h]@20
  unsigned __int8 clip_y0b; // [sp+2Ch] [bp+14h]@21
  unsigned __int8 clip_y0c; // [sp+2Ch] [bp+14h]@34
  unsigned __int8 clip_y0d; // [sp+2Ch] [bp+14h]@49
  unsigned __int8 clip_y0e; // [sp+2Ch] [bp+14h]@50
  unsigned __int8 clip_y0f; // [sp+2Ch] [bp+14h]@60

  v9 = drawarea;
  v10 = this;
  v11 = drawarea->Orien;
  v12 = TDrawArea::AlignedWidth(drawarea);
  v13 = v11 * v12;
  v14 = (unsigned __int8 *)&v10->shape_header[1];
  width = v11 * v12;
  drawareaa = (TDrawArea *)v14;
  if ( v11 >= 1 )
  {
    v15 = clip_y0;
    v16 = clip_y0 * v13;
  }
  else
  {
    v15 = clip_y0;
    v16 = v13 * (clip_y0 - v9->Height + 1);
  }
  v17 = &v9->Bits[v16] + clip_x0;
  save_buffer = v17;
  v18 = shape_y0;
  if ( shape_y0 < v15 )
  {
    v19 = v15 - shape_y0;
    v18 = v15;
    do
    {
      v20 = 0;
      while ( 1 )
      {
        v21 = *v14;
        drawareaa = (TDrawArea *)(v14 + 1);
        if ( (*v14 & 1) == 1 )
        {
          if ( v21 >> 1 )
          {
            drawareaa = (TDrawArea *)((char *)drawareaa + (v21 >> 1));
            goto LABEL_14;
          }
        }
        else if ( !(v21 & 0xFE) )
        {
          v20 = 1;
          goto LABEL_14;
        }
        drawareaa = (TDrawArea *)(v14 + 2);
LABEL_14:
        if ( v20 )
          break;
        v14 = (unsigned __int8 *)drawareaa;
      }
      v14 = (unsigned __int8 *)drawareaa;
      --v19;
    }
    while ( v19 );
  }
  if ( v18 > clip_y1 )
    return 1;
  shape_y0a = clip_y1 - v18 + 1;
  do
  {
    v22 = shape_x0;
    if ( shape_x0 < clip_x0 )
    {
      v23 = 0;
      while ( 1 )
      {
        clip_y0a = *v14;
        v24 = (char *)&drawareaa->DrawSystem + 1;
        drawareaa = (TDrawArea *)((char *)drawareaa + 1);
        if ( (*v14 & 1) == 1 )
          break;
        clip_y0c = clip_y0a >> 1;
        if ( clip_y0c )
        {
          v22 += clip_y0c;
          if ( v22 >= clip_x0 )
          {
            if ( v22 <= clip_x1 )
            {
              v23 = 1;
              for ( i = (unsigned int)(&v17[v22] - clip_x0); (unsigned int)v17 < i; *(v17 - 1) = color_table[v33] )
                v33 = (unsigned __int8)*v17++;
            }
            else
            {
              v23 = 2;
              for ( j = (unsigned int)(&v17[clip_x1 + 1] - clip_x0); (unsigned int)v17 < j; *(v17 - 1) = color_table[v31] )
                v31 = (unsigned __int8)*v17++;
            }
          }
          v27 = (int)&drawareaa->DrawSystem + 1;
          goto LABEL_44;
        }
        v23 = 3;
LABEL_45:
        v14 = (unsigned __int8 *)drawareaa;
        if ( v23 )
          goto LABEL_48;
      }
      clip_y0b = clip_y0a >> 1;
      if ( !clip_y0b )
      {
        v22 += *v24;
        drawareaa = (TDrawArea *)(v24 + 1);
        if ( v22 >= clip_x0 )
        {
          if ( v22 <= clip_x1 )
          {
            v23 = 1;
            v17 += v22 - clip_x0;
          }
          else
          {
            v23 = 2;
          }
        }
        goto LABEL_45;
      }
      v22 += clip_y0b;
      if ( v22 >= clip_x0 )
      {
        if ( v22 <= clip_x1 )
        {
          v23 = 1;
          for ( k = (unsigned int)(&v17[v22] - clip_x0); (unsigned int)v17 < k; *(v17 - 1) = color_table[v29] )
            v29 = (unsigned __int8)*v17++;
        }
        else
        {
          v23 = 2;
          v25 = (unsigned int)(&v17[clip_x1 + 1] - clip_x0);
          if ( (unsigned int)v17 < v25 )
          {
            do
            {
              v26 = (unsigned __int8)*v17++;
              *(v17 - 1) = color_table[v26];
            }
            while ( (unsigned int)v17 < v25 );
            v27 = (int)drawareaa + clip_y0b;
            goto LABEL_44;
          }
        }
      }
      v27 = (int)drawareaa + clip_y0b;
LABEL_44:
      drawareaa = (TDrawArea *)v27;
      goto LABEL_45;
    }
    v23 = 1;
LABEL_48:
    v34 = v23 - 1;
    if ( !v34 )
    {
      while ( 1 )
      {
        clip_y0d = *v14;
        v35 = (char *)&drawareaa->DrawSystem + 1;
        drawareaa = (TDrawArea *)((char *)drawareaa + 1);
        if ( (*v14 & 1) == 1 )
          break;
        clip_y0f = clip_y0d >> 1;
        if ( clip_y0f )
        {
          v22 += clip_y0f;
          if ( v22 <= clip_x1 )
          {
            for ( l = (unsigned int)&v17[clip_y0f]; (unsigned int)v17 < l; *(v17 - 1) = color_table[v46] )
              v46 = (unsigned __int8)*v17++;
          }
          else
          {
            v34 = 1;
            for ( m = (unsigned int)(&v17[clip_y0f - v22 + 1] + clip_x1);
                  (unsigned int)v17 < m;
                  *(v17 - 1) = color_table[v44] )
            {
              v44 = (unsigned __int8)*v17++;
            }
          }
          v40 = (int)&drawareaa->DrawSystem + 1;
          goto LABEL_69;
        }
        v34 = 3;
LABEL_70:
        v14 = (unsigned __int8 *)drawareaa;
        if ( v34 )
          goto LABEL_71;
      }
      clip_y0e = clip_y0d >> 1;
      if ( !clip_y0e )
      {
        v36 = v35;
        v37 = *v35;
        v22 += v37;
        v17 += v37;
        drawareaa = (TDrawArea *)(v36 + 1);
        if ( v22 > clip_x1 )
          v34 = 1;
        goto LABEL_70;
      }
      v22 += clip_y0e;
      if ( v22 <= clip_x1 )
      {
        v41 = (unsigned int)&v17[clip_y0e];
        if ( v17 < &v17[clip_y0e] )
        {
          do
          {
            v42 = (unsigned __int8)*v17++;
            *(v17 - 1) = color_table[v42];
          }
          while ( (unsigned int)v17 < v41 );
        }
      }
      else
      {
        v34 = 1;
        v38 = (unsigned int)(&v17[clip_y0e - v22 + 1] + clip_x1);
        if ( (unsigned int)v17 < v38 )
        {
          do
          {
            v39 = (unsigned __int8)*v17++;
            *(v17 - 1) = color_table[v39];
          }
          while ( (unsigned int)v17 < v38 );
          v40 = (int)drawareaa + clip_y0e;
          goto LABEL_69;
        }
      }
      v40 = (int)drawareaa + clip_y0e;
LABEL_69:
      drawareaa = (TDrawArea *)v40;
      goto LABEL_70;
    }
LABEL_71:
    v47 = v34 - 1;
    if ( v47 )
      goto LABEL_80;
    do
    {
      v48 = *v14++;
      if ( (v48 & 1) == 1 )
      {
        if ( v48 >> 1 )
        {
          v14 += v48 >> 1;
          continue;
        }
      }
      else if ( !(v48 & 0xFE) )
      {
        v47 = 2;
        continue;
      }
      ++v14;
    }
    while ( !v47 );
    drawareaa = (TDrawArea *)v14;
LABEL_80:
    v17 = &save_buffer[width];
    v49 = shape_y0a == 1;
    save_buffer += width;
    --shape_y0a;
  }
  while ( !v49 );
  return 1;
}

char shape_mirror(TDrawArea *drawarea, int x, int y, int shape_num, char flags, char *color_table)
{
  TShape *v7; // esi@1
  SLhape_File_Header *v8; // eax@3
  Shape_Info *v9; // edi@5
  int v10; // ST24_4@5
  int v11; // ST20_4@5
  int v12; // eax@5
  char result; // al@5
  TSpan_List_Manager *v14; // eax@6
  int v15; // edx@6
  int v16; // ebx@6
  int v17; // edx@7
  SLhape_File_Header *v18; // esi@11
  int v19; // eax@11
  TDrawArea *v20; // ebp@12
  int v21; // ecx@13
  int v22; // edi@13
  int v23; // eax@13
  int v24; // edx@13
  int v25; // ecx@13
  int v26; // ecx@25
  int v27; // ecx@27
  int v28; // ecx@33
  int clip_y0; // [sp+14h] [bp-18h]@13
  int shape_y1; // [sp+18h] [bp-14h]@13
  int rect; // [sp+1Ch] [bp-10h]@12
  int rect_4; // [sp+20h] [bp-Ch]@12
  int rect_8; // [sp+24h] [bp-8h]@12
  int rect_12; // [sp+28h] [bp-4h]@12
  TDrawArea *drawareaa; // [sp+30h] [bp+4h]@13
  int clip_x1; // [sp+34h] [bp+8h]@13
  int clip_x0; // [sp+38h] [bp+Ch]@13

  v7 = this;
  /* Shape draw */
  if ( shape_num < 0 || TShape::Check_shape(this, shape_num) )
    return 0;
  v8 = v7->FShape;
  if ( !v8 )
  {
    v20 = drawarea;
    rect = drawarea->ClipRect.left;
    rect_4 = drawarea->ClipRect.top;
    rect_8 = drawarea->ClipRect.right;
    rect_12 = drawarea->ClipRect.bottom;
    if ( v7->shape )
    {
      v21 = (int)&v7->shape[v7->offsets[shape_num].shape];
      v7->shape_header = (Shape_Header *)v21;
      v22 = x - *(_DWORD *)(v21 + 16);
      v23 = y + *(_DWORD *)(v21 + 12);
      v24 = x - *(_DWORD *)(v21 + 8);
      clip_x1 = v22;
      v25 = y + *(_DWORD *)(v21 + 20);
      clip_y0 = v23;
      drawareaa = (TDrawArea *)v24;
      shape_y1 = v25;
      clip_x0 = v25;
      if ( v22 < rect )
        clip_x1 = rect;
      if ( v23 < rect_4 )
        clip_y0 = rect_4;
      if ( v24 > rect_8 )
        drawareaa = (TDrawArea *)rect_8;
      if ( v25 > rect_12 )
        clip_x0 = rect_12;
      if ( clip_x1 < 0 )
        clip_x1 = 0;
      if ( clip_y0 < 0 )
        clip_y0 = 0;
      v26 = v20->Width;
      if ( (signed int)drawareaa >= v26 )
        drawareaa = (TDrawArea *)(v26 - 1);
      v27 = v20->Height;
      if ( clip_x0 >= v27 )
        clip_x0 = v27 - 1;
      if ( (signed int)drawareaa >= clip_x1 && clip_x0 >= clip_y0 )
      {
        if ( clip_x1 != v22 || clip_y0 != v23 )
        {
          v28 = (int)drawareaa;
        }
        else
        {
          v28 = (int)drawareaa;
          if ( drawareaa == (TDrawArea *)v24 && clip_x0 == shape_y1 )
          {
            if ( !flags )
              return TShape::shape_mirror_unclipped(v7, v20, v24, v23);
            if ( flags == 1 )
            {
              if ( color_table )
                result = TShape::shape_mirror_color_trans_unclipped(v7, v20, v24, v23, shape_num, color_table);
              else
                result = TShape::shape_mirror_unclipped(v7, v20, v24, v23);
              return result;
            }
            if ( flags == 2 )
            {
              if ( color_table )
                result = TShape::shape_mirror_shadow_unclipped(v7, v20, v24, v23, color_table);
              else
                result = TShape::shape_mirror_unclipped(v7, v20, v24, v23);
              return result;
            }
            return 0;
          }
        }
        if ( flags )
        {
          if ( flags == 1 )
          {
            if ( color_table )
              return TShape::shape_mirror_color_trans_clipped(
                       v7,
                       v20,
                       v24,
                       v23,
                       shape_num,
                       clip_x1,
                       clip_y0,
                       v28,
                       clip_x0,
                       color_table);
          }
          else
          {
            if ( flags != 2 )
              return 0;
            if ( color_table )
              return TShape::shape_mirror_shadow_clipped(v7, v20, v24, v23, clip_x1, clip_y0, v28, clip_x0, color_table);
          }
        }
        return TShape::shape_mirror_clipped(v7, v20, v24, v23, clip_x1, clip_y0, v28, clip_x0);
      }
    }
    return 0;
  }
  if ( SDI_Capture_Info )
  {
    v9 = (Shape_Info *)&v8[shape_num + 1];
    v10 = SDI_Object_ID;
    v11 = SDI_Draw_Level;
    v12 = ASMGet_Color_Xform();
    DClipInfo_List::AddDrawNode(
      SDI_List,
      v7->FShape,
      v9,
      SDI_Draw_Line,
      x + v9->Hotspot_X - v9->Width,
      y - v9->Hotspot_Y,
      fog_next_shape + 2,
      color_table,
      v12,
      v11,
      v10);
    result = 1;
  }
  else
  {
    v14 = drawarea->CurSpanList;
    v15 = drawarea->SpanList->Num_Lines;
    v16 = v14->Num_Lines;
    if ( v15 >= v16 )
      v17 = v16 - 1;
    else
      v17 = v15 - 1;
    ASMSet_Surface_Info(
      (int)drawarea->CurDisplayOffsets,
      (int)v14->Line_Head_Ptrs,
      (int)v14->Line_Tail_Ptrs,
      0,
      0,
      v14->Max_Span_Px,
      v17);
    if ( color_table )
      ASMSet_Xlate_Table((int)color_table);
    v18 = v7->FShape;
    v19 = (int)&v18[shape_num + 1];
    ASMDraw_Sprite(
      v18,
      x + *(_DWORD *)(v19 + 24) - *(_DWORD *)(v19 + 16),
      y - *(_DWORD *)(v19 + 28),
      *(_DWORD *)(v19 + 16),
      *(_DWORD *)(v19 + 20),
      *(_DWORD *)v19,
      *(_DWORD *)(v19 + 4),
      fog_next_shape + 2);
    ++ASM_Fast_Count;
    result = 1;
  }
  return result;
}

char shape_mirror_unclipped(TDrawArea *drawarea, int shape_x1, int shape_y0)
{
  TShape *v4; // esi@1
  int v5; // ebx@1
  int v6; // eax@1
  Shape_Header *v7; // ecx@1
  int v8; // ebp@1
  unsigned __int8 *v9; // esi@1
  int v10; // eax@1
  int v11; // ecx@2
  char *v12; // ecx@4
  char *v13; // edi@4
  char v14; // bl@6
  unsigned __int8 v15; // al@7
  int v16; // eax@8
  unsigned __int8 v17; // cl@12
  bool v18; // zf@19
  TDrawArea *drawareaa; // [sp+14h] [bp+4h]@5
  int shape_x1a; // [sp+18h] [bp+8h]@4
  unsigned __int8 save_buffer; // [sp+1Ch] [bp+Ch]@14

  v4 = this;
  v5 = drawarea->Orien;
  v6 = TDrawArea::AlignedWidth(drawarea);
  v7 = v4->shape_header;
  v8 = v5 * v6;
  v9 = (unsigned __int8 *)&v7[1];
  v10 = v7->ymax - v7->ymin + 1;
  if ( v5 >= 1 )
    v11 = shape_y0 * v8;
  else
    v11 = v8 * (shape_y0 - drawarea->Height + 1);
  v12 = &drawarea->Bits[v11];
  v13 = &v12[shape_x1 + 1];
  shape_x1a = (int)&v12[shape_x1 + 1];
  if ( v10 > 0 )
  {
    drawareaa = (TDrawArea *)v10;
    do
    {
      v14 = 0;
      do
      {
        v15 = *v9++;
        if ( (v15 & 1) != 1 )
        {
          save_buffer = v15 >> 1;
          if ( !(v15 >> 1) )
          {
            v14 = 1;
            continue;
          }
          v13 -= save_buffer;
          memset(v13, *v9, save_buffer);
          goto LABEL_17;
        }
        LOBYTE(v16) = v15 >> 1;
        if ( !(_BYTE)v16 )
        {
          v13 -= *v9;
LABEL_17:
          ++v9;
          continue;
        }
        if ( (_BYTE)v16 )
        {
          v16 = (unsigned __int8)v16;
          do
          {
            v17 = *v9;
            --v13;
            ++v9;
            --v16;
            *v13 = v17;
          }
          while ( v16 );
        }
      }
      while ( !v14 );
      v13 = (char *)(v8 + shape_x1a);
      v18 = drawareaa == (TDrawArea *)1;
      shape_x1a += v8;
      drawareaa = (TDrawArea *)((char *)drawareaa - 1);
    }
    while ( !v18 );
  }
  return 1;
}

//----- (004BA9E0) --------------------------------------------------------
char shape_mirror_color_trans_unclipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int shape_num, char *color_table)
{
  TShape *v6; // esi@1
  int v7; // ebp@1
  int v8; // eax@1
  Shape_Header *v9; // ecx@1
  int v10; // edx@1
  unsigned __int8 *v11; // esi@1
  char *v12; // edi@2
  char v13; // bl@6
  unsigned __int8 v14; // al@7
  int v15; // eax@8
  int v16; // ecx@12
  bool v17; // zf@19
  int width; // [sp+10h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+18h] [bp+4h]@5
  int shape_x1a; // [sp+1Ch] [bp+8h]@4
  unsigned __int8 save_buffer; // [sp+20h] [bp+Ch]@14

  v6 = this;
  v7 = drawarea->Orien;
  v8 = TDrawArea::AlignedWidth(drawarea);
  v9 = v6->shape_header;
  v10 = v7 * v8;
  width = v7 * v8;
  v11 = (unsigned __int8 *)&v9[1];
  if ( v7 >= 1 )
    v12 = &drawarea->Bits[shape_x1 + 1] + shape_y0 * v10;
  else
    v12 = &drawarea->Bits[shape_x1 + 1] + v10 * (shape_y0 - drawarea->Height + 1);
  shape_x1a = (int)v12;
  if ( v9->ymax - v9->ymin + 1 > 0 )
  {
    drawareaa = (TDrawArea *)(v9->ymax - v9->ymin + 1);
    do
    {
      v13 = 0;
      do
      {
        v14 = *v11++;
        if ( (v14 & 1) != 1 )
        {
          save_buffer = v14 >> 1;
          if ( !(v14 >> 1) )
          {
            v13 = 1;
            continue;
          }
          v12 -= save_buffer;
          memset(v12, (unsigned __int8)color_table[*v11], save_buffer);
          goto LABEL_17;
        }
        LOBYTE(v15) = v14 >> 1;
        if ( !(_BYTE)v15 )
        {
          v12 -= *v11;
LABEL_17:
          ++v11;
          continue;
        }
        if ( (_BYTE)v15 )
        {
          v15 = (unsigned __int8)v15;
          do
          {
            --v12;
            v16 = *v11++;
            --v15;
            *v12 = color_table[v16];
          }
          while ( v15 );
        }
      }
      while ( !v13 );
      v12 = (char *)(width + shape_x1a);
      v17 = drawareaa == (TDrawArea *)1;
      shape_x1a += width;
      drawareaa = (TDrawArea *)((char *)drawareaa - 1);
    }
    while ( !v17 );
  }
  return 1;
}

//----- (004BAAF0) --------------------------------------------------------
char shape_mirror_shadow_unclipped(TDrawArea *drawarea, int shape_x1, int shape_y0, char *color_table)
{
  TShape *v5; // ebx@1
  int v6; // edi@1
  int v7; // eax@1
  Shape_Header *v8; // ecx@1
  unsigned __int8 *v9; // ebp@1
  int v10; // edx@1
  char *v11; // ecx@2
  char v12; // bl@6
  unsigned __int8 v13; // dl@7
  int v14; // edx@8
  int v15; // edx@14
  bool v16; // zf@21
  TDrawArea *drawareaa; // [sp+18h] [bp+4h]@5
  int shape_x1a; // [sp+1Ch] [bp+8h]@4
  unsigned __int8 save_buffer; // [sp+20h] [bp+Ch]@8

  v5 = this;
  v6 = drawarea->Orien;
  v7 = v6 * TDrawArea::AlignedWidth(drawarea);
  v8 = v5->shape_header;
  v9 = (unsigned __int8 *)&v8[1];
  v10 = v8->ymax - v8->ymin + 1;
  if ( v6 >= 1 )
    v11 = &drawarea->Bits[shape_x1 + 1] + shape_y0 * v7;
  else
    v11 = &drawarea->Bits[shape_x1 + 1] + v7 * (shape_y0 - drawarea->Height + 1);
  shape_x1a = (int)v11;
  if ( v10 > 0 )
  {
    drawareaa = (TDrawArea *)v10;
    do
    {
      v12 = 0;
      do
      {
        v13 = *v9++;
        if ( (v13 & 1) != 1 )
        {
          LOBYTE(v15) = v13 >> 1;
          if ( !(_BYTE)v15 )
          {
            v12 = 1;
            continue;
          }
          if ( (_BYTE)v15 )
          {
            v15 = (unsigned __int8)v15;
            do
            {
              --v11;
              --v15;
              *v11 = color_table[(unsigned __int8)*v11];
            }
            while ( v15 );
          }
          goto LABEL_19;
        }
        LOBYTE(v14) = v13 >> 1;
        save_buffer = v14;
        if ( !(_BYTE)v14 )
        {
          v11 -= *v9;
LABEL_19:
          ++v9;
          continue;
        }
        if ( (_BYTE)v14 )
        {
          v14 = (unsigned __int8)v14;
          do
          {
            --v11;
            --v14;
            *v11 = color_table[(unsigned __int8)*v11];
          }
          while ( v14 );
        }
        v9 += save_buffer;
      }
      while ( !v12 );
      v11 = (char *)(v7 + shape_x1a);
      v16 = drawareaa == (TDrawArea *)1;
      shape_x1a += v7;
      drawareaa = (TDrawArea *)((char *)drawareaa - 1);
    }
    while ( !v16 );
  }
  return 1;
}

//----- (004BAC00) --------------------------------------------------------
char shape_mirror_clipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1)
{
  TShape *v8; // esi@1
  int v9; // ebx@1
  int v10; // eax@1
  int v11; // ecx@1
  unsigned __int8 *v12; // esi@1
  int v13; // edx@2
  char *v14; // ebp@2
  int v15; // edi@4
  char v16; // cl@6
  unsigned __int8 v17; // al@7
  int v18; // edi@17
  char v19; // bl@18
  unsigned __int8 v20; // al@19
  char *v21; // esi@27
  int v22; // eax@28
  char v23; // cl@29
  int v24; // eax@32
  char v25; // cl@33
  char v26; // bl@47
  unsigned __int8 v27; // al@48
  int v28; // eax@50
  int v29; // ecx@52
  int v30; // eax@53
  char v31; // dl@55
  char v32; // al@58
  char v33; // bl@68
  unsigned __int8 v34; // al@69
  bool v35; // zf@76
  char *save_buffer; // [sp+10h] [bp-8h]@4
  int width; // [sp+14h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+1Ch] [bp+4h]@5
  TDrawArea *drawareab; // [sp+1Ch] [bp+4h]@54
  int shape_y0a; // [sp+24h] [bp+Ch]@16
  unsigned __int8 clip_y0a; // [sp+2Ch] [bp+14h]@20
  unsigned __int8 clip_y0b; // [sp+2Ch] [bp+14h]@49
  unsigned __int8 clip_y0c; // [sp+2Ch] [bp+14h]@60

  v8 = this;
  v9 = drawarea->Orien;
  v10 = TDrawArea::AlignedWidth(drawarea);
  v11 = v9 * v10;
  v12 = (unsigned __int8 *)&v8->shape_header[1];
  width = v9 * v10;
  if ( v9 >= 1 )
  {
    v13 = clip_x1;
    v14 = &drawarea->Bits[clip_x1 + 1] + clip_y0 * v11;
  }
  else
  {
    v13 = clip_x1;
    v14 = &drawarea->Bits[clip_x1 + 1] + v11 * (clip_y0 - drawarea->Height + 1);
  }
  save_buffer = v14;
  v15 = shape_y0;
  if ( shape_y0 < clip_y0 )
  {
    drawareaa = (TDrawArea *)(clip_y0 - shape_y0);
    v15 = clip_y0;
    do
    {
      v16 = 0;
      do
      {
        v17 = *v12++;
        if ( (v17 & 1) == 1 )
        {
          if ( v17 >> 1 )
          {
            v12 += v17 >> 1;
            continue;
          }
        }
        else if ( !(v17 & 0xFE) )
        {
          v16 = 1;
          continue;
        }
        ++v12;
      }
      while ( !v16 );
      drawareaa = (TDrawArea *)((char *)drawareaa - 1);
    }
    while ( drawareaa );
  }
  if ( v15 <= clip_y1 )
  {
    shape_y0a = clip_y1 - v15 + 1;
    while ( 1 )
    {
      v18 = shape_x1;
      if ( shape_x1 <= v13 )
      {
        v19 = 1;
      }
      else
      {
        v19 = 0;
        do
        {
          v20 = *v12++;
          if ( (v20 & 1) == 1 )
          {
            clip_y0a = v20 >> 1;
            if ( v20 >> 1 )
            {
              v18 -= clip_y0a;
              if ( v18 > v13 )
              {
                v12 += clip_y0a;
              }
              else if ( v18 >= clip_x0 )
              {
                v19 = 1;
                v12 += clip_y0a - (v13 - v18);
                if ( (_BYTE)v13 != (_BYTE)v18 )
                {
                  v24 = (unsigned __int8)(v13 - v18);
                  do
                  {
                    v25 = *v12;
                    --v14;
                    ++v12;
                    --v24;
                    *v14 = v25;
                  }
                  while ( v24 );
                }
              }
              else
              {
                v19 = 2;
                v21 = (char *)(&v12[v18 - clip_x1 - 1] + clip_y0a);
                if ( (_BYTE)v13 - (_BYTE)clip_x0 != -1 )
                {
                  v22 = (v13 - clip_x0 + 1) & 0xFF;
                  do
                  {
                    v23 = *v21;
                    --v14;
                    ++v21;
                    --v22;
                    *v14 = v23;
                  }
                  while ( v22 );
                }
                v12 = (unsigned __int8 *)&v21[clip_x0 - v18];
                v13 = clip_x1;
              }
            }
            else
            {
              v18 -= *v12++;
              if ( v18 <= v13 )
              {
                if ( v18 >= clip_x0 )
                {
                  v19 = 1;
                  v14 += v18 - v13;
                }
                else
                {
                  v19 = 2;
                }
              }
            }
          }
          else if ( v20 >> 1 )
          {
            v18 -= v20 >> 1;
            if ( v18 <= v13 )
            {
              if ( v18 >= clip_x0 )
              {
                v19 = 1;
                v14 -= v13 - v18;
                memset(v14, *v12, v13 - v18);
              }
              else
              {
                v19 = 2;
                v14 += -(v13 - clip_x0) - 1;
                memset(v14, *v12, v13 - clip_x0 + 1);
              }
              v13 = clip_x1;
            }
            ++v12;
          }
          else
          {
            v19 = 3;
          }
        }
        while ( !v19 );
      }
      v26 = v19 - 1;
      if ( !v26 )
      {
        while ( 1 )
        {
          v27 = *v12++;
          if ( (v27 & 1) == 1 )
            break;
          clip_y0c = v27 >> 1;
          if ( v27 >> 1 )
          {
            v18 -= clip_y0c;
            if ( v18 >= clip_x0 )
            {
              v14 -= clip_y0c;
              memset(v14, *v12, clip_y0c);
            }
            else
            {
              v26 = 1;
              v14 += -clip_y0c - (v18 - clip_x0);
              memset(v14, *v12, clip_y0c + v18 - clip_x0);
            }
            ++v12;
LABEL_66:
            v13 = clip_x1;
            goto LABEL_67;
          }
          v26 = 3;
LABEL_67:
          if ( v26 )
            goto LABEL_68;
        }
        clip_y0b = v27 >> 1;
        if ( !(v27 >> 1) )
        {
          v28 = *v12;
          v18 -= v28;
          v14 -= v28;
          ++v12;
          if ( v18 < clip_x0 )
            v26 = 1;
          goto LABEL_67;
        }
        v29 = clip_y0b;
        v18 -= clip_y0b;
        if ( v18 >= clip_x0 )
        {
          if ( clip_y0b )
          {
            do
            {
              v32 = *v12;
              --v14;
              ++v12;
              --v29;
              *v14 = v32;
            }
            while ( v29 );
          }
          goto LABEL_67;
        }
        v26 = 1;
        v30 = clip_y0b + v18 - clip_x0;
        if ( (_BYTE)v30 )
        {
          drawareab = (TDrawArea *)(unsigned __int8)v30;
          do
          {
            v31 = *v12;
            --v14;
            ++v12;
            *v14 = v31;
            drawareab = (TDrawArea *)((char *)drawareab - 1);
          }
          while ( drawareab );
        }
        v12 -= v18 - clip_x0;
        goto LABEL_66;
      }
LABEL_68:
      v33 = v26 - 1;
      if ( !v33 )
        break;
LABEL_76:
      v14 = &save_buffer[width];
      v35 = shape_y0a == 1;
      save_buffer += width;
      --shape_y0a;
      if ( v35 )
        return 1;
    }
    while ( 1 )
    {
      v34 = *v12++;
      if ( (v34 & 1) == 1 )
      {
        if ( !(v34 >> 1) )
          goto LABEL_74;
        v12 += v34 >> 1;
      }
      else
      {
        if ( v34 & 0xFE )
        {
LABEL_74:
          ++v12;
          goto LABEL_75;
        }
        v33 = 2;
      }
LABEL_75:
      if ( v33 )
        goto LABEL_76;
    }
  }
  return 1;
}

char shape_mirror_color_trans_clipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int shape_num, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table)
{
  TShape *v10; // esi@1
  int v11; // ebx@1
  int v12; // eax@1
  int v13; // ecx@1
  unsigned __int8 *v14; // esi@1
  int v15; // edx@2
  char *v16; // edi@2
  int v17; // ebp@4
  char v18; // cl@6
  unsigned __int8 v19; // al@7
  int v20; // ebp@17
  char v21; // bl@18
  unsigned __int8 v22; // al@19
  unsigned __int8 *v23; // esi@27
  int v24; // eax@28
  int v25; // ecx@29
  int v26; // eax@32
  int v27; // ecx@33
  size_t v28; // eax@40
  char v29; // bl@47
  unsigned __int8 v30; // al@48
  int v31; // eax@50
  int v32; // eax@53
  int v33; // edx@55
  int v34; // eax@60
  char v35; // bl@70
  unsigned __int8 v36; // al@71
  bool v37; // zf@78
  char *save_buffer; // [sp+10h] [bp-8h]@4
  int width; // [sp+14h] [bp-4h]@1
  unsigned __int8 drawareaa; // [sp+1Ch] [bp+4h]@20
  unsigned __int8 drawareab; // [sp+1Ch] [bp+4h]@49
  unsigned __int8 drawareac; // [sp+1Ch] [bp+4h]@62
  int shape_y0a; // [sp+24h] [bp+Ch]@54
  int clip_y0a; // [sp+30h] [bp+18h]@5
  int clip_y0b; // [sp+30h] [bp+18h]@59
  int clip_y1a; // [sp+38h] [bp+20h]@16

  v10 = this;
  v11 = drawarea->Orien;
  v12 = TDrawArea::AlignedWidth(drawarea);
  v13 = v11 * v12;
  v14 = (unsigned __int8 *)&v10->shape_header[1];
  width = v11 * v12;
  if ( v11 >= 1 )
  {
    v15 = clip_x1;
    v16 = &drawarea->Bits[clip_x1 + 1] + clip_y0 * v13;
  }
  else
  {
    v15 = clip_x1;
    v16 = &drawarea->Bits[clip_x1 + 1] + v13 * (clip_y0 - drawarea->Height + 1);
  }
  save_buffer = v16;
  v17 = shape_y0;
  if ( shape_y0 < clip_y0 )
  {
    clip_y0a = clip_y0 - shape_y0;
    v17 = shape_y0 + clip_y0a;
    do
    {
      v18 = 0;
      do
      {
        v19 = *v14++;
        if ( (v19 & 1) == 1 )
        {
          if ( v19 >> 1 )
          {
            v14 += v19 >> 1;
            continue;
          }
        }
        else if ( !(v19 & 0xFE) )
        {
          v18 = 1;
          continue;
        }
        ++v14;
      }
      while ( !v18 );
      --clip_y0a;
    }
    while ( clip_y0a );
  }
  if ( v17 <= clip_y1 )
  {
    clip_y1a = clip_y1 - v17 + 1;
    while ( 1 )
    {
      v20 = shape_x1;
      if ( shape_x1 <= v15 )
      {
        v21 = 1;
      }
      else
      {
        v21 = 0;
        do
        {
          v22 = *v14++;
          if ( (v22 & 1) == 1 )
          {
            drawareaa = v22 >> 1;
            if ( v22 >> 1 )
            {
              v20 -= drawareaa;
              if ( v20 > v15 )
              {
                v14 += drawareaa;
              }
              else if ( v20 >= clip_x0 )
              {
                v21 = 1;
                v14 += drawareaa - (v15 - v20);
                if ( (_BYTE)v15 != (_BYTE)v20 )
                {
                  v26 = (unsigned __int8)(v15 - v20);
                  do
                  {
                    v27 = *v14;
                    --v16;
                    ++v14;
                    --v26;
                    *v16 = color_table[v27];
                  }
                  while ( v26 );
                  v15 = clip_x1;
                }
              }
              else
              {
                v21 = 2;
                v23 = &v14[v20 - clip_x1 - 1] + drawareaa;
                if ( (_BYTE)v15 - (_BYTE)clip_x0 != -1 )
                {
                  v24 = (v15 - clip_x0 + 1) & 0xFF;
                  do
                  {
                    v25 = *v23;
                    --v16;
                    ++v23;
                    --v24;
                    *v16 = color_table[v25];
                  }
                  while ( v24 );
                }
                v14 = &v23[clip_x0 - v20];
                v15 = clip_x1;
              }
            }
            else
            {
              v20 -= *v14++;
              if ( v20 <= v15 )
              {
                if ( v20 >= clip_x0 )
                {
                  v21 = 1;
                  v16 += v20 - v15;
                }
                else
                {
                  v21 = 2;
                }
              }
            }
          }
          else if ( v22 >> 1 )
          {
            v20 -= v22 >> 1;
            if ( v20 <= v15 )
            {
              if ( v20 >= clip_x0 )
              {
                v21 = 1;
                v28 = v15 - v20;
              }
              else
              {
                v21 = 2;
                v28 = v15 - clip_x0 + 1;
              }
              v16 -= v28;
              memset(v16, (unsigned __int8)color_table[*v14], v28);
              v15 = clip_x1;
            }
            ++v14;
          }
          else
          {
            v21 = 3;
          }
        }
        while ( !v21 );
      }
      v29 = v21 - 1;
      if ( !v29 )
      {
        while ( 1 )
        {
          v30 = *v14++;
          if ( (v30 & 1) == 1 )
            break;
          drawareac = v30 >> 1;
          if ( v30 >> 1 )
          {
            v20 -= drawareac;
            if ( v20 >= clip_x0 )
            {
              v16 -= drawareac;
              memset(v16, (unsigned __int8)color_table[*v14], drawareac);
            }
            else
            {
              v29 = 1;
              v16 += -drawareac - (v20 - clip_x0);
              memset(v16, (unsigned __int8)color_table[*v14], drawareac + v20 - clip_x0);
            }
            ++v14;
LABEL_68:
            v15 = clip_x1;
            goto LABEL_69;
          }
          v29 = 3;
LABEL_69:
          if ( v29 )
            goto LABEL_70;
        }
        drawareab = v30 >> 1;
        if ( !(v30 >> 1) )
        {
          v31 = *v14;
          v20 -= v31;
          v16 -= v31;
          ++v14;
          if ( v20 < clip_x0 )
            v29 = 1;
          goto LABEL_69;
        }
        v20 -= drawareab;
        if ( v20 >= clip_x0 )
        {
          if ( drawareab )
          {
            clip_y0b = drawareab;
            do
            {
              v34 = *v14;
              --v16;
              ++v14;
              *v16 = color_table[v34];
              --clip_y0b;
            }
            while ( clip_y0b );
          }
          goto LABEL_69;
        }
        v29 = 1;
        v32 = drawareab + v20 - clip_x0;
        if ( (_BYTE)v32 )
        {
          shape_y0a = (unsigned __int8)v32;
          do
          {
            v33 = *v14;
            --v16;
            ++v14;
            *v16 = color_table[v33];
            --shape_y0a;
          }
          while ( shape_y0a );
          v29 = 1;
        }
        v14 -= v20 - clip_x0;
        goto LABEL_68;
      }
LABEL_70:
      v35 = v29 - 1;
      if ( !v35 )
        break;
LABEL_78:
      v16 = &save_buffer[width];
      v37 = clip_y1a == 1;
      save_buffer += width;
      --clip_y1a;
      if ( v37 )
        return 1;
    }
    while ( 1 )
    {
      v36 = *v14++;
      if ( (v36 & 1) == 1 )
      {
        if ( !(v36 >> 1) )
          goto LABEL_76;
        v14 += v36 >> 1;
      }
      else
      {
        if ( v36 & 0xFE )
        {
LABEL_76:
          ++v14;
          goto LABEL_77;
        }
        v35 = 2;
      }
LABEL_77:
      if ( v35 )
        goto LABEL_78;
    }
  }
  return 1;
}

//----- (004BB280) --------------------------------------------------------
char shape_mirror_shadow_clipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table)
{
  TDrawArea *v9; // esi@1
  TShape *v10; // ebx@1
  int v11; // edi@1
  int v12; // eax@1
  unsigned __int8 *v13; // ebp@1
  char *v14; // ecx@2
  int v15; // esi@4
  int v16; // edi@5
  char v17; // al@6
  unsigned __int8 v18; // dl@7
  unsigned __int8 *v19; // edi@17
  int v20; // edx@17
  int v21; // esi@17
  char v22; // al@20
  unsigned __int8 v23; // dl@21
  int v24; // edx@30
  int v25; // edx@34
  int v26; // edx@42
  int v27; // edx@46
  char v28; // al@52
  unsigned __int8 v29; // dl@53
  int v30; // edx@54
  int v31; // edx@55
  int v32; // edx@58
  int v33; // edx@61
  unsigned __int8 v34; // dl@66
  int v35; // edi@68
  int v36; // edx@69
  char v37; // al@78
  unsigned __int8 v38; // cl@79
  bool v39; // zf@86
  char *save_buffer; // [sp+10h] [bp-8h]@4
  int width; // [sp+14h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+1Ch] [bp+4h]@1
  TDrawArea *drawareab; // [sp+1Ch] [bp+4h]@53
  int shape_y0a; // [sp+24h] [bp+Ch]@17
  unsigned __int8 clip_y0a; // [sp+2Ch] [bp+14h]@22
  unsigned __int8 clip_y0b; // [sp+2Ch] [bp+14h]@54

  v9 = drawarea;
  v10 = this;
  v11 = drawarea->Orien;
  v12 = v11 * TDrawArea::AlignedWidth(drawarea);
  v13 = (unsigned __int8 *)&v10->shape_header[1];
  width = v12;
  drawareaa = (TDrawArea *)&v10->shape_header[1];
  if ( v11 >= 1 )
    v14 = &v9->Bits[clip_x1 + 1] + clip_y0 * v12;
  else
    v14 = &v9->Bits[clip_x1 + 1] + v12 * (clip_y0 - v9->Height + 1);
  v15 = shape_y0;
  save_buffer = v14;
  if ( shape_y0 < clip_y0 )
  {
    v16 = clip_y0 - shape_y0;
    v15 = clip_y0;
    while ( 1 )
    {
      v17 = 0;
      do
      {
        v18 = *v13++;
        if ( (v18 & 1) == 1 )
        {
          if ( v18 >> 1 )
          {
            v13 += v18 >> 1;
            continue;
          }
        }
        else if ( !(v18 & 0xFE) )
        {
          v17 = 1;
          continue;
        }
        ++v13;
      }
      while ( !v17 );
      if ( !--v16 )
      {
        drawareaa = (TDrawArea *)v13;
        break;
      }
    }
  }
  if ( v15 <= clip_y1 )
  {
    v19 = (unsigned __int8 *)drawareaa;
    v20 = clip_y1 - v15;
    v21 = shape_x1;
    shape_y0a = v20 + 1;
    while ( 1 )
    {
      if ( v21 > clip_x1 )
      {
        v22 = 0;
        while ( 1 )
        {
          v23 = *v19++;
          if ( (v23 & 1) != 1 )
          {
            if ( v23 >> 1 )
            {
              v21 -= v23 >> 1;
              if ( v21 <= clip_x1 )
              {
                if ( v21 >= clip_x0 )
                {
                  v22 = 1;
                  if ( (_BYTE)clip_x1 != (_BYTE)v21 )
                  {
                    v27 = (unsigned __int8)(clip_x1 - v21);
                    do
                    {
                      --v14;
                      --v27;
                      *v14 = color_table[(unsigned __int8)*v14];
                    }
                    while ( v27 );
                  }
                }
                else
                {
                  v22 = 2;
                  if ( (_BYTE)clip_x1 - (_BYTE)clip_x0 != -1 )
                  {
                    v26 = (clip_x1 - clip_x0 + 1) & 0xFF;
                    do
                    {
                      --v14;
                      --v26;
                      *v14 = color_table[(unsigned __int8)*v14];
                    }
                    while ( v26 );
                  }
                }
              }
              ++v19;
            }
            else
            {
              v22 = 3;
            }
            goto LABEL_49;
          }
          clip_y0a = v23 >> 1;
          if ( !(v23 >> 1) )
          {
            v21 -= *v19++;
            if ( v21 <= clip_x1 )
            {
              if ( v21 >= clip_x0 )
              {
                v22 = 1;
                v14 += v21 - clip_x1;
              }
              else
              {
                v22 = 2;
              }
            }
            goto LABEL_49;
          }
          v21 -= clip_y0a;
          if ( v21 <= clip_x1 )
          {
            if ( v21 >= clip_x0 )
            {
              v22 = 1;
              if ( (_BYTE)clip_x1 != (_BYTE)v21 )
              {
                v25 = (unsigned __int8)(clip_x1 - v21);
                do
                {
                  --v14;
                  --v25;
                  *v14 = color_table[(unsigned __int8)*v14];
                }
                while ( v25 );
              }
            }
            else
            {
              v22 = 2;
              if ( (_BYTE)clip_x1 - (_BYTE)clip_x0 != -1 )
              {
                v24 = (clip_x1 - clip_x0 + 1) & 0xFF;
                do
                {
                  --v14;
                  --v24;
                  *v14 = color_table[(unsigned __int8)*v14];
                }
                while ( v24 );
                v19 += clip_y0a;
                goto LABEL_49;
              }
            }
          }
          v19 += clip_y0a;
LABEL_49:
          if ( v22 )
            goto LABEL_52;
        }
      }
      v22 = 1;
LABEL_52:
      v28 = v22 - 1;
      if ( !v28 )
      {
        while ( 1 )
        {
          v29 = *v19++;
          drawareab = (TDrawArea *)v19;
          if ( (v29 & 1) == 1 )
            break;
          v34 = v29 >> 1;
          if ( v34 )
          {
            v35 = v34;
            v21 -= v34;
            if ( v21 >= clip_x0 )
            {
              if ( v34 )
              {
                do
                {
                  --v14;
                  --v35;
                  *v14 = color_table[(unsigned __int8)*v14];
                }
                while ( v35 );
              }
            }
            else
            {
              v28 = 1;
              v36 = v34 + v21 - clip_x0;
              if ( (_BYTE)v36 )
              {
                v36 = (unsigned __int8)v36;
                do
                {
                  --v14;
                  --v36;
                  *v14 = color_table[(unsigned __int8)*v14];
                }
                while ( v36 );
              }
            }
            v33 = (int)&drawareab->DrawSystem + 1;
            goto LABEL_76;
          }
          v28 = 3;
LABEL_77:
          if ( v28 )
            goto LABEL_78;
        }
        LOBYTE(v30) = v29 >> 1;
        clip_y0b = v30;
        if ( !(_BYTE)v30 )
        {
          v31 = *v19;
          v21 -= v31;
          v14 -= v31;
          ++v19;
          if ( v21 < clip_x0 )
            v28 = 1;
          goto LABEL_77;
        }
        v21 -= (unsigned __int8)v30;
        if ( v21 >= clip_x0 )
        {
          if ( (_BYTE)v30 )
          {
            v30 = (unsigned __int8)v30;
            do
            {
              --v14;
              --v30;
              *v14 = color_table[(unsigned __int8)*v14];
            }
            while ( v30 );
          }
        }
        else
        {
          v28 = 1;
          v32 = (unsigned __int8)v30 + v21 - clip_x0;
          if ( (_BYTE)v32 )
          {
            v32 = (unsigned __int8)v32;
            do
            {
              --v14;
              --v32;
              *v14 = color_table[(unsigned __int8)*v14];
            }
            while ( v32 );
            v33 = (int)&v19[clip_y0b];
            goto LABEL_76;
          }
        }
        v33 = (int)&v19[clip_y0b];
LABEL_76:
        v19 = (unsigned __int8 *)v33;
        goto LABEL_77;
      }
LABEL_78:
      v37 = v28 - 1;
      if ( !v37 )
        break;
LABEL_86:
      v14 = &save_buffer[width];
      v39 = shape_y0a == 1;
      save_buffer += width;
      --shape_y0a;
      if ( v39 )
        return 1;
      v21 = shape_x1;
    }
    while ( 1 )
    {
      v38 = *v19++;
      if ( (v38 & 1) == 1 )
      {
        if ( !(v38 >> 1) )
          goto LABEL_84;
        v19 += v38 >> 1;
      }
      else
      {
        if ( v38 & 0xFE )
        {
LABEL_84:
          ++v19;
          goto LABEL_85;
        }
        v37 = 2;
      }
LABEL_85:
      if ( v37 )
        goto LABEL_86;
    }
  }
  return 1;
}

bool TShape::shape_dither(TDrawArea *drawarea, int x, int y, int shape_num, int dx, int dy)
{
    int rectl = drawarea->ClipRect.left;
    int rectt = drawarea->ClipRect.top;
    int rectr = drawarea->ClipRect.right;
    int rectb = drawarea->ClipRect.bottom;

    /* Shape draw */
    if ( this->Check_shape(shape_num) )
        return false;

    this->shape_header = &this->shape[this->offsets[shape_num].shape];

    int v13 = x + this->shape_header->xmin;
    int v10 = y + this->shape_header->ymin;
    int v11 = x + this->shape_header->xmax;
    int v12 = y + this->shape_header->ymax;

    int clip_y0 = v13;
    if ( v13 < rectl )
        clip_y0 = rectl;

    int clip_x1 = v10;
    if ( v10 < rectt )
        clip_x1 = rectt;

    int clip_x0 = v11;
    if ( v11 > rectr )
        clip_x0 = rectr;

    int clip_y1 = v12;
    if ( v12 > rectb )
        clip_y1 = rectb;

    if ( clip_y0 < 0 )
        clip_y0 = 0;

    if ( clip_x1 < 0 )
        clip_x1 = 0;

    if ( rectr >= drawarea->Width )
        clip_x0 = drawarea->Width - 1;

    if ( clip_y1 >= drawarea->Height )
        clip_y1 = drawarea->Height - 1;

    switch( true )
    {
        case clip_x0 >= clip_y0 && clip_y1 >= clip_x1:
            return this->shape_dithered_unclipped(
                drawarea,
                v13,
                v10,
                dx,
                dy);

        case clip_y0 != v13 || clip_x1 != v10 || clip_x0 != v11 || clip_y1 != v12:
            return this->shape_dithered_clipped(
                drawarea,
                v13,
                v10,
                clip_y0,
                clip_x1,
                clip_x0,
                clip_y1,
                dx,
                dy);

        default:
            return false;

    }
}

bool TShape::shape_dithered_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int dx, int dy)
{
  TShape *v6; // ebx@1
  int v7; // edi@1
  int v8; // eax@1
  Shape_Header *v9; // ecx@1
  int v10; // edx@1
  int v11; // eax@1
  unsigned __int8 *v12; // ebp@1
  char v13; // di@2
  int v14; // ecx@2
  char *v15; // ecx@4
  int v16; // esi@4
  int v17; // edi@7
  int i; // edx@9
  unsigned __int8 v19; // al@10
  unsigned __int8 v20; // al@11
  unsigned int v21; // esi@16
  unsigned __int8 v22; // al@21
  unsigned int v23; // esi@25
  char *save_buffer; // [sp+10h] [bp-8h]@4
  int width; // [sp+14h] [bp-4h]@1
  TDrawArea *drawareaa; // [sp+1Ch] [bp+4h]@9
  unsigned __int8 save_flag; // [sp+20h] [bp+8h]@14
  unsigned __int8 save_flaga; // [sp+20h] [bp+8h]@23
  char index1; // [sp+24h] [bp+Ch]@9

  v6 = this;
  v7 = drawarea->Orien;
  v8 = TDrawArea::AlignedWidth(drawarea);
  v9 = v6->shape_header;
  v10 = v7 * v8;
  width = v7 * v8;
  v11 = v9->ymax - v9->ymin + 1;
  v12 = (unsigned __int8 *)&v9[1];
  if ( v7 >= 1 )
  {
    v13 = shape_y0;
    v14 = shape_y0 * v10;
  }
  else
  {
    v13 = shape_y0;
    v14 = v10 * (shape_y0 - drawarea->Height + 1);
  }
  v15 = &drawarea->Bits[v14] + shape_x0;
  v16 = ((_BYTE)shape_x0 + (_BYTE)dx) & 1;
  save_buffer = v15;
  if ( (v13 + (_BYTE)dy) & 1 )
    v16 = v16 != 1;
  if ( v11 <= 0 )
    return 1;
  v17 = v11;
  while ( 2 )
  {
    i = v16;
    drawareaa = (TDrawArea *)(v16 != 1);
    index1 = 0;
    do
    {
      v19 = *v12++;
      if ( (v19 & 1) != 1 )
      {
        v22 = v19 >> 1;
        if ( !v22 )
        {
          index1 = 1;
          continue;
        }
        save_flaga = v22;
        if ( i )
        {
          ++v15;
          save_flaga = v22 - 1;
        }
        v23 = (unsigned int)&v15[save_flaga];
        for ( i = save_flaga & 1; (unsigned int)v15 < v23; v15 += 2 )
          *v15 = 0;
        if ( save_flaga & 1 )
          --v15;
        goto LABEL_29;
      }
      v20 = v19 >> 1;
      if ( !v20 )
      {
        v15 += *v12;
        if ( *v12 & 1 )
          i = i != 1;
LABEL_29:
        ++v12;
        continue;
      }
      save_flag = v20;
      if ( i )
      {
        ++v15;
        save_flag = v20 - 1;
      }
      v21 = (unsigned int)&v15[save_flag];
      for ( i = save_flag & 1; (unsigned int)v15 < v21; v15 += 2 )
        *v15 = 0;
      if ( save_flag & 1 )
        --v15;
      v12 += v20;
    }
    while ( !index1 );
    v15 = &save_buffer[width];
    --v17;
    save_buffer += width;
    if ( v17 )
    {
      v16 = (int)drawareaa;
      continue;
    }
    return 1;
  }
}

bool shape_dithered_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1, int dx, int dy)
{
  TShape *v10; // ebx@1
  int v11; // esi@1
  int v12; // eax@1
  unsigned __int8 *v13; // ebp@1
  int v14; // esi@2
  int v15; // ecx@2
  char *v16; // ecx@4
  int v17; // edi@6
  int v18; // esi@7
  char v19; // dl@8
  unsigned __int8 v20; // al@9
  int v21; // edi@18
  char v22; // al@19
  unsigned __int8 v23; // dl@21
  int v24; // esi@23
  int v25; // edx@30
  unsigned int j; // edx@32
  unsigned __int8 v27; // dl@36
  unsigned int i; // edx@38
  int v29; // edx@47
  unsigned int l; // edx@49
  unsigned __int8 v31; // dl@53
  unsigned int k; // edx@55
  char v33; // dl@60
  char v34; // dl@63
  unsigned __int8 v35; // dl@64
  unsigned __int8 v36; // dl@65
  int v37; // esi@66
  int v38; // edx@71
  unsigned int ii; // edx@73
  unsigned int jj; // edx@79
  unsigned __int8 v41; // dl@85
  int v42; // edx@88
  unsigned int n; // edx@90
  unsigned int m; // edx@96
  char v45; // dl@103
  unsigned __int8 v46; // al@104
  bool v47; // zf@111
  bool v48; // sf@111
  unsigned __int8 v49; // of@111
  int y; // [sp+14h] [bp-Ch]@6
  char *save_buffer; // [sp+18h] [bp-8h]@4
  int width; // [sp+1Ch] [bp-4h]@1
  char drawareaa; // [sp+24h] [bp+4h]@4
  unsigned __int8 shape_y0a; // [sp+2Ch] [bp+Ch]@22
  unsigned __int8 shape_y0b; // [sp+2Ch] [bp+Ch]@65
  unsigned __int8 shape_y0c; // [sp+2Ch] [bp+Ch]@85
  char clip_y0a; // [sp+34h] [bp+14h]@20
  char clip_y0b; // [sp+34h] [bp+14h]@63
  unsigned __int8 v60; // [sp+40h] [bp+20h]@30
  unsigned __int8 v61; // [sp+40h] [bp+20h]@36
  unsigned __int8 v62; // [sp+40h] [bp+20h]@47
  unsigned __int8 v63; // [sp+40h] [bp+20h]@53
  unsigned __int8 v64; // [sp+40h] [bp+20h]@71
  unsigned __int8 v65; // [sp+40h] [bp+20h]@77
  unsigned __int8 v66; // [sp+40h] [bp+20h]@88
  unsigned __int8 v67; // [sp+40h] [bp+20h]@94
  int index1; // [sp+44h] [bp+24h]@19

  v10 = this;
  v11 = drawarea->Orien;
  v12 = v11 * TDrawArea::AlignedWidth(drawarea);
  width = v12;
  v13 = (unsigned __int8 *)&v10->shape_header[1];
  if ( v11 >= 1 )
  {
    v14 = clip_y0;
    v15 = clip_y0 * v12;
  }
  else
  {
    v14 = clip_y0;
    v15 = v12 * (clip_y0 - drawarea->Height + 1);
  }
  v16 = &drawarea->Bits[v15] + clip_x0;
  save_buffer = v16;
  drawareaa = (clip_x0 + dx) & 1;
  if ( ((_BYTE)v14 + (_BYTE)dy) & 1 )
    drawareaa = (((_BYTE)clip_x0 + (_BYTE)dx) & 1) != 1;
  v17 = shape_y0;
  y = shape_y0;
  if ( shape_y0 < v14 )
  {
    v18 = v14 - shape_y0;
    v17 = shape_y0 + v18;
    y = shape_y0 + v18;
    do
    {
      v19 = 0;
      do
      {
        v20 = *v13++;
        if ( (v20 & 1) == 1 )
        {
          if ( v20 >> 1 )
          {
            v13 += v20 >> 1;
            continue;
          }
        }
        else if ( !(v20 & 0xFE) )
        {
          v19 = 1;
          continue;
        }
        ++v13;
      }
      while ( !v19 );
      --v18;
    }
    while ( v18 );
  }
  if ( v17 <= clip_y1 )
  {
    v21 = clip_x1;
    while ( 1 )
    {
      v22 = drawareaa;
      drawareaa = drawareaa != 1;
      index1 = shape_x0;
      if ( shape_x0 < clip_x0 )
      {
        clip_y0a = 0;
        while ( 1 )
        {
          v23 = *v13++;
          if ( (v23 & 1) == 1 )
          {
            shape_y0a = v23 >> 1;
            if ( !(v23 >> 1) )
            {
              v24 = *v13++ + index1;
              index1 = v24;
              if ( v24 >= clip_x0 )
              {
                if ( v24 <= v21 )
                {
                  clip_y0a = 1;
                  v16 += (unsigned __int8)(v24 - clip_x0);
                  if ( ((_BYTE)v24 - (_BYTE)clip_x0) & 1 )
                    v22 = v22 != 1;
                }
                else
                {
                  clip_y0a = 2;
                }
              }
              goto LABEL_60;
            }
            index1 += shape_y0a;
            if ( index1 <= clip_x0 )
              goto LABEL_42;
            if ( index1 <= v21 )
            {
              clip_y0a = 1;
              v27 = index1 - clip_x0;
              v61 = index1 - clip_x0;
              if ( v22 )
              {
                --v27;
                ++v16;
                v61 = v27;
              }
              v22 = v27 & 1;
              for ( i = (unsigned int)&v16[v61]; (unsigned int)v16 < i; v16 += 2 )
                *v16 = 0;
              if ( v22 )
                --v16;
LABEL_42:
              v13 += shape_y0a;
              goto LABEL_60;
            }
            clip_y0a = 2;
            v25 = v21 - clip_x0 + 1;
            v60 = v21 - clip_x0 + 1;
            if ( v22 )
            {
              LOBYTE(v25) = v21 - clip_x0;
              ++v16;
              v60 = v21 - clip_x0;
            }
            v22 = v25 & 1;
            for ( j = (unsigned int)&v16[v60]; (unsigned int)v16 < j; v16 += 2 )
              *v16 = 0;
            if ( !v22 )
              goto LABEL_42;
            --v16;
            v13 += shape_y0a;
          }
          else
          {
            if ( v23 >> 1 )
            {
              index1 += v23 >> 1;
              if ( index1 > clip_x0 )
              {
                if ( index1 <= v21 )
                {
                  clip_y0a = 1;
                  v31 = index1 - clip_x0;
                  v63 = index1 - clip_x0;
                  if ( v22 )
                  {
                    --v31;
                    ++v16;
                    v63 = v31;
                  }
                  v22 = v31 & 1;
                  for ( k = (unsigned int)&v16[v63]; (unsigned int)v16 < k; v16 += 2 )
                    *v16 = 0;
                  if ( v22 )
LABEL_58:
                    --v16;
                }
                else
                {
                  clip_y0a = 2;
                  v29 = v21 - clip_x0 + 1;
                  v62 = v21 - clip_x0 + 1;
                  if ( v22 )
                  {
                    LOBYTE(v29) = v21 - clip_x0;
                    ++v16;
                    v62 = v21 - clip_x0;
                  }
                  v22 = v29 & 1;
                  for ( l = (unsigned int)&v16[v62]; (unsigned int)v16 < l; v16 += 2 )
                    *v16 = 0;
                  if ( v22 )
                    goto LABEL_58;
                }
              }
              ++v13;
              goto LABEL_60;
            }
            clip_y0a = 3;
          }
LABEL_60:
          v33 = clip_y0a;
          if ( clip_y0a )
            goto LABEL_63;
        }
      }
      v33 = 1;
LABEL_63:
      v34 = v33 - 1;
      clip_y0b = v34;
      if ( !v34 )
      {
        while ( 1 )
        {
          v35 = *v13++;
          if ( (v35 & 1) != 1 )
          {
            v41 = v35 >> 1;
            shape_y0c = v41;
            if ( v41 )
            {
              index1 += v41;
              if ( index1 <= clip_x1 )
              {
                v67 = v41;
                if ( v22 )
                {
                  --v41;
                  ++v16;
                  v67 = v41;
                }
                v22 = v41 & 1;
                for ( m = (unsigned int)&v16[v67]; (unsigned int)v16 < m; v16 += 2 )
                  *v16 = 0;
                if ( v22 )
                  --v16;
                v21 = clip_x1;
              }
              else
              {
                v21 = clip_x1;
                clip_y0b = 1;
                v42 = clip_x1 - index1 + v41 + 1;
                v66 = clip_x1 - index1 + shape_y0c + 1;
                if ( v22 )
                {
                  LOBYTE(v42) = v42 - 1;
                  ++v16;
                  v66 = v42;
                }
                v22 = v42 & 1;
                for ( n = (unsigned int)&v16[v66]; (unsigned int)v16 < n; v16 += 2 )
                  *v16 = 0;
                if ( v22 )
                  --v16;
              }
              ++v13;
            }
            else
            {
              clip_y0b = 3;
            }
            goto LABEL_102;
          }
          v36 = v35 >> 1;
          shape_y0b = v36;
          if ( !v36 )
          {
            v37 = *v13;
            index1 += v37;
            if ( *v13 & 1 )
              v22 = v22 != 1;
            v16 += v37;
            ++v13;
            if ( index1 > v21 )
              clip_y0b = 1;
            goto LABEL_102;
          }
          index1 += v36;
          if ( index1 <= clip_x1 )
            break;
          v21 = clip_x1;
          clip_y0b = 1;
          v38 = clip_x1 - index1 + v36 + 1;
          v64 = clip_x1 - index1 + shape_y0b + 1;
          if ( v22 )
          {
            LOBYTE(v38) = v38 - 1;
            ++v16;
            v64 = v38;
          }
          v22 = v38 & 1;
          for ( ii = (unsigned int)&v16[v64]; (unsigned int)v16 < ii; v16 += 2 )
            *v16 = 0;
          if ( !v22 )
            goto LABEL_84;
          --v16;
          v13 += shape_y0b;
LABEL_102:
          v34 = clip_y0b;
          if ( clip_y0b )
            goto LABEL_103;
        }
        v65 = v36;
        if ( v22 )
        {
          --v36;
          ++v16;
          v65 = v36;
        }
        v22 = v36 & 1;
        for ( jj = (unsigned int)&v16[v65]; (unsigned int)v16 < jj; v16 += 2 )
          *v16 = 0;
        if ( v22 )
          --v16;
        v21 = clip_x1;
LABEL_84:
        v13 += shape_y0b;
        goto LABEL_102;
      }
LABEL_103:
      v45 = v34 - 1;
      if ( !v45 )
        break;
LABEL_111:
      v16 = &save_buffer[width];
      v49 = __OFSUB__(y + 1, clip_y1);
      v47 = y + 1 == clip_y1;
      v48 = y + 1 - clip_y1 < 0;
      save_buffer += width;
      ++y;
      if ( !((unsigned __int8)(v48 ^ v49) | v47) )
        return 1;
    }
    while ( 1 )
    {
      v46 = *v13++;
      if ( (v46 & 1) == 1 )
      {
        if ( !(v46 >> 1) )
          goto LABEL_109;
        v13 += v46 >> 1;
      }
      else
      {
        if ( v46 & 0xFE )
        {
LABEL_109:
          ++v13;
          goto LABEL_110;
        }
        v45 = 2;
      }
LABEL_110:
      if ( v45 )
        goto LABEL_111;
    }
  }
  return 1;
}
