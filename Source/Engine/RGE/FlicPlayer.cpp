
//----- (00449B30) --------------------------------------------------------
void __thiscall RGE_Flic_Player::RGE_Flic_Player(RGE_Flic_Player *this, char *filename)
{
  RGE_Flic_Player *v2; // ebx@1
  signed int v3; // eax@1
  int v4; // ebp@1
  __int32 v5; // esi@2

  v2 = this;
  v3 = _open(filename, 0x8000);
  v4 = v3;
  if ( v3 <= -1 )
  {
    v2->flic_buffer = 0;
    v2->flic_handle = -1;
  }
  else
  {
    lseek(v3, 0, 2);
    v5 = _tell(v4);
    v2->flic_buffer = (char *)calloc(v5, 1u);
    lseek(v4, 0, 0);
    read(v4, v2->flic_buffer, v5);
    qmemcpy(&v2->flichead, v2->flic_buffer, sizeof(v2->flichead));
    v2->flic_width = v2->flichead.width;
    RGE_Flic_Player::start(v2);
    _close(v4);
  }
}

//----- (00449BE0) --------------------------------------------------------
void __thiscall RGE_Flic_Player::RGE_Flic_Player(RGE_Flic_Player *this, int handle)
{
  RGE_Flic_Player *v2; // esi@1

  v2 = this;
  if ( handle <= -1 )
  {
    this->flic_buffer = 0;
    this->flic_handle = -1;
  }
  else
  {
    read(handle, &this->flichead, 0x84u);
    v2->flic_width = v2->flichead.width;
    v2->flic_handle = handle;
    v2->flic_buffer = 0;
    RGE_Flic_Player::start(v2);
  }
}

//----- (00449C40) --------------------------------------------------------
void __thiscall RGE_Flic_Player::~RGE_Flic_Player(RGE_Flic_Player *this)
{
  if ( this->flic_buffer )
    free(this->flic_buffer);
}

//----- (00449C50) --------------------------------------------------------
void __thiscall RGE_Flic_Player::palette(RGE_Flic_Player *this, tagRGBQUAD *palette)
{
  RGE_Flic_Player *v2; // edi@1
  char *v3; // ebx@2
  FrameHead *v4; // ecx@4
  int v5; // edi@6
  int v6; // eax@6
  int v7; // ebp@7
  signed int v8; // edx@8
  int v9; // eax@8
  signed int v10; // esi@11
  char *v11; // ecx@11
  char v12; // dl@12
  int v13; // edi@15
  int v14; // eax@15
  int v15; // ebp@16
  signed int v16; // edx@17
  int v17; // eax@17
  signed int v18; // esi@20
  char *v19; // ecx@20
  FrameHead *framehead; // [sp+10h] [bp-10h]@2
  int index1; // [sp+14h] [bp-Ch]@4
  char *temp_buffer; // [sp+18h] [bp-8h]@1
  RGE_Flic_Player *v23; // [sp+1Ch] [bp-4h]@1

  v2 = this;
  v23 = this;
  temp_buffer = 0;
  if ( this->flic_handle <= -1 )
  {
    framehead = (FrameHead *)this->flichead.oframe2;
    v3 = (char *)&framehead[1];
  }
  else
  {
    framehead = (FrameHead *)calloc(1u, 0x10u);
    lseek(v2->flic_handle, (__int32)v2->flichead.oframe2, 0);
    read(v2->flic_handle, framehead, 0x10u);
    v3 = (char *)calloc(framehead->size, 1u);
    temp_buffer = v3;
    read(v2->flic_handle, v3, framehead->size);
  }
  v4 = framehead;
  index1 = 0;
  if ( framehead->chunks > 0 )
  {
    do
    {
      if ( *((_WORD *)v3 + 2) == 4 )
      {
        v5 = 0;
        v6 = (int)(v3 + 8);
        if ( (signed int)*((_WORD *)v3 + 3) > 0 )
        {
          v7 = *((_WORD *)v3 + 3);
          do
          {
            v8 = *(_BYTE *)(v6 + 1);
            v5 += *(_BYTE *)v6;
            v9 = v6 + 1;
            if ( !v8 )
              v8 = 256;
            v6 = v9 + 1;
            if ( v8 > 0 )
            {
              v10 = v8;
              v11 = &palette[v5].rgbGreen;
              v5 += v8;
              do
              {
                v12 = *(_BYTE *)v6;
                v6 += 3;
                v11[1] = v12;
                *v11 = *(_BYTE *)(v6 - 2);
                *(v11 - 1) = *(_BYTE *)(v6 - 1);
                v11 += 4;
                --v10;
              }
              while ( v10 );
            }
            --v7;
          }
          while ( v7 );
        }
      }
      if ( *((_WORD *)v3 + 2) == 11 )
      {
        v13 = 0;
        v14 = (int)(v3 + 8);
        if ( (signed int)*((_WORD *)v3 + 3) > 0 )
        {
          v15 = *((_WORD *)v3 + 3);
          do
          {
            v16 = *(_BYTE *)(v14 + 1);
            v13 += *(_BYTE *)v14;
            v17 = v14 + 1;
            if ( !v16 )
              v16 = 256;
            v14 = v17 + 1;
            if ( v16 > 0 )
            {
              v18 = v16;
              v19 = &palette[v13].rgbGreen;
              v13 += v16;
              do
              {
                v19 += 4;
                *(v19 - 3) = 4 * *(_BYTE *)v14;
                *(v19 - 4) = 4 * *(_BYTE *)(v14 + 1);
                *(v19 - 5) = 4 * *(_BYTE *)(v14 + 2);
                v14 += 3;
                --v18;
              }
              while ( v18 );
            }
            --v15;
          }
          while ( v15 );
        }
      }
      v4 = framehead;
      v3 += *(_DWORD *)v3;
      ++index1;
    }
    while ( index1 < framehead->chunks );
    v2 = v23;
  }
  if ( v2->flic_handle > -1 )
  {
    if ( v4 )
      free(v4);
    if ( temp_buffer )
      free(temp_buffer);
  }
}

//----- (00449DF0) --------------------------------------------------------
int __thiscall RGE_Flic_Player::resolution(RGE_Flic_Player *this)
{
  return this->flichead.height | (this->flichead.width << 16);
}

//----- (00449E00) --------------------------------------------------------
int __thiscall RGE_Flic_Player::time_delay(RGE_Flic_Player *this)
{
  return this->flichead.speed;
}

//----- (00449E10) --------------------------------------------------------
__int16 __thiscall RGE_Flic_Player::frames(RGE_Flic_Player *this)
{
  return this->flichead.frames;
}

//----- (00449E20) --------------------------------------------------------
void __thiscall RGE_Flic_Player::start(RGE_Flic_Player *this)
{
  char *v1; // edx@3
  int v2; // eax@4

  if ( this->flichead.type == 44817 )
  {
    v2 = 5 * this->flichead.speed;
    this->flichead.oframe1 = this->flic_buffer + 132;
    this->flichead.speed = 200 * v2 / 70;
  }
  else if ( this->flichead.type == 44818 )
  {
    v1 = &this->flic_buffer[(unsigned int)this->flichead.oframe1];
    this->flichead.oframe1 = v1;
    this->flichead.oframe2 = v1;
    return;
  }
  this->flichead.oframe2 = this->flichead.oframe1;
}

//----- (00449E80) --------------------------------------------------------
void __thiscall RGE_Flic_Player::reset(RGE_Flic_Player *this)
{
  this->flichead.oframe2 = this->flichead.oframe1;
}

//----- (00449E90) --------------------------------------------------------
char __thiscall RGE_Flic_Player::draw(RGE_Flic_Player *this, TDrawArea *drawarea_in, int flic_x, int flic_y)
{
  RGE_Flic_Player *v4; // esi@1
  void *v5; // ebp@2
  char *v6; // edi@2
  int v7; // ebx@4
  int v8; // eax@4
  int v9; // eax@4
  signed int v10; // ebx@7
  char *v11; // ecx@15
  int v12; // edx@15
  int v13; // ebx@15
  char *v14; // eax@16
  char v15; // bl@18
  char *temp_buffer; // [sp+10h] [bp-4h]@1

  v4 = this;
  temp_buffer = 0;
  if ( this->flic_handle <= -1 )
  {
    v5 = this->flichead.oframe2;
    v6 = (char *)v5 + 16;
  }
  else
  {
    v5 = calloc(1u, 0x10u);
    lseek(v4->flic_handle, (__int32)v4->flichead.oframe2, 0);
    read(v4->flic_handle, v5, 0x10u);
    v6 = (char *)calloc(*(_DWORD *)v5, 1u);
    temp_buffer = v6;
    read(v4->flic_handle, v6, *(_DWORD *)v5);
  }
  v7 = v4->flichead.width;
  v4->x1 = flic_x;
  v4->drawarea = drawarea_in;
  v8 = flic_y + v4->flichead.height;
  v4->x2 = flic_x + v7;
  v4->y1 = flic_y;
  v4->y2 = v8;
  v9 = drawarea_in->Orien * TDrawArea::AlignedWidth(drawarea_in);
  v4->drawarea_width = v9;
  if ( drawarea_in->Orien >= 1 )
    v4->window_buffer = &drawarea_in->Bits[v4->y1 * v9] + v4->x1;
  else
    v4->window_buffer = &drawarea_in->Bits[v9 * (v4->y1 - drawarea_in->Height + 1)] + v4->x1;
  v10 = 0;
  for ( v4->save_buffer = v4->window_buffer; v10 < *((_WORD *)v5 + 3); ++v10 )
  {
    v4->chunk = v6 + 6;
    switch ( *((_WORD *)v6 + 2) )
    {
      case 16:
        RGE_Flic_Player::literal(v4);
        break;
      case 7:
        RGE_Flic_Player::delta_flc(v4);
        break;
      case 12:
        RGE_Flic_Player::delta_fli(v4);
        break;
      case 13:
        RGE_Flic_Player::black(v4);
        break;
      case 15:
        RGE_Flic_Player::byte_run(v4);
        break;
      default:
        break;
    }
    v6 += *(_DWORD *)v6;
  }
  v11 = v4->flic_buffer;
  v12 = v4->flichead.size;
  v13 = (int)&v4->flichead.oframe2[*(_DWORD *)v5];
  v4->flichead.oframe2 = (char *)v13;
  if ( v13 - (signed int)v11 < v12 )
  {
    v15 = 0;
  }
  else
  {
    v14 = v4->flichead.oframe1;
    v4->flichead.oframe2 = v14;
    if ( v11 )
      v4->flichead.oframe2 = &v14[*(_DWORD *)v14];
    v15 = 2;
  }
  if ( v4->flic_handle > -1 )
  {
    if ( v5 )
      free(v5);
    if ( temp_buffer )
      free(temp_buffer);
  }
  return v15;
}

//----- (0044A090) --------------------------------------------------------
void __thiscall RGE_Flic_Player::literal(RGE_Flic_Player *this)
{
  RGE_Flic_Player *v1; // eax@1
  int v2; // edx@1
  char *v3; // edi@2
  int v4; // ecx@2
  int v5; // edi@2
  int v6; // ecx@2

  v1 = this;
  v2 = 0;
  if ( this->flic_size_y > 0 )
  {
    do
    {
      qmemcpy(v1->window_buffer, v1->chunk, v1->flic_size_x);
      v3 = v1->chunk;
      v4 = v1->flic_width;
      v1->window_buffer += v1->drawarea_width;
      v5 = (int)&v3[v4];
      v6 = v1->flic_size_y;
      ++v2;
      v1->chunk = (char *)v5;
    }
    while ( v2 < v6 );
  }
}

//----- (0044A100) --------------------------------------------------------
void __thiscall RGE_Flic_Player::delta_flc(RGE_Flic_Player *this)
{
  RGE_Flic_Player *v1; // eax@1
  char *v2; // ebp@1
  int v3; // ecx@1
  char *v4; // ebp@1
  char v5; // bl@3
  __int16 v6; // cx@4
  __int16 v7; // di@4
  unsigned __int16 v8; // si@4
  int v9; // ecx@7
  int v10; // ecx@7
  char *v11; // ebx@13
  _BYTE *v12; // ebp@13
  char v13; // cl@13
  const void *v14; // ebp@13
  unsigned int v15; // kr00_4@14
  unsigned int v16; // ecx@15
  bool v17; // zf@15
  unsigned int v18; // edx@16
  int v19; // edx@23
  int cur_y; // [sp+4h] [bp-Ch]@1
  int v21; // [sp+8h] [bp-8h]@12
  int v22; // [sp+Ch] [bp-4h]@2

  v1 = this;
  cur_y = 0;
  v2 = this->chunk;
  v3 = *(_WORD *)v2;
  v4 = v2 + 2;
  if ( v3 <= 0 )
    return;
  v22 = v3;
  do
  {
    v5 = 0;
    do
    {
      v6 = *(_WORD *)v4;
      v7 = 0;
      v8 = *(_WORD *)v4;
      v4 += 2;
      if ( !((unsigned int)v8 >> 14) )
        goto LABEL_9;
      if ( (unsigned int)v8 >> 14 == 2 )
      {
        v1->window_buffer[v1->flic_width - 1] = v8;
        v6 = *(_WORD *)v4;
        v4 += 2;
LABEL_9:
        v7 = v6;
        v5 = 1;
        continue;
      }
      if ( (unsigned int)v8 >> 14 == 3 )
      {
        v9 = (signed __int16)-v6;
        cur_y += v9;
        v10 = (int)&v1->save_buffer[v9 * v1->drawarea_width];
        v1->save_buffer = (char *)v10;
        v1->window_buffer = (char *)v10;
      }
    }
    while ( !v5 );
    if ( v7 > 0 )
    {
      v21 = v7;
      do
      {
        v11 = &v1->window_buffer[*v4];
        v12 = v4 + 1;
        v1->window_buffer = v11;
        v13 = *v12;
        v14 = v12 + 1;
        if ( v13 <= 0 )
        {
          v16 = -2 * v13;
          v17 = v16 == 1;
          if ( (signed int)v16 > 1 )
          {
            v18 = v16 >> 1;
            do
            {
              v16 -= 2;
              *(_WORD *)v1->window_buffer = *(_WORD *)v14;
              --v18;
              v1->window_buffer += 2;
            }
            while ( v18 );
            v17 = v16 == 1;
          }
          if ( v17 )
            *v1->window_buffer++ = *(_BYTE *)v14;
          v4 = (char *)v14 + 2;
        }
        else
        {
          v15 = 2 * v13;
          qmemcpy(v11, v14, v15);
          v4 = (char *)v14 + v15;
          v1->window_buffer += v15;
        }
        --v21;
      }
      while ( v21 );
    }
    v19 = (int)&v1->save_buffer[v1->drawarea_width];
    v1->window_buffer = (char *)v19;
    v17 = v22 == 1;
    ++cur_y;
    v1->save_buffer = (char *)v19;
    --v22;
  }
  while ( !v17 );
}

//----- (0044A2A0) --------------------------------------------------------
void __thiscall RGE_Flic_Player::delta_fli(RGE_Flic_Player *this)
{
  RGE_Flic_Player *v1; // esi@1
  char *v2; // ebp@1
  int v3; // eax@1
  int v4; // ebp@1
  int v5; // eax@3
  int v6; // ebx@3
  int v7; // ebx@5
  char v8; // al@5
  const void *v9; // ebp@5
  int v10; // edx@6
  int v11; // edi@6
  char *v12; // ebx@6
  char *v13; // edi@6
  unsigned int v14; // ecx@6
  char v15; // si@6
  int v16; // eax@6
  char *v17; // edi@6
  char *v18; // edi@7
  unsigned int v19; // ecx@7
  char *v20; // esi@7
  bool v21; // zf@9
  RGE_Flic_Player *v22; // [sp+8h] [bp-10h]@1
  int v23; // [sp+Ch] [bp-Ch]@4
  int v24; // [sp+10h] [bp-8h]@2
  int cur_x; // [sp+14h] [bp-4h]@5

  v1 = this;
  v22 = this;
  v2 = this->chunk;
  v3 = *(_DWORD *)v2;
  v4 = (int)(v2 + 8);
  if ( v3 > 0 )
  {
    v24 = v3;
    do
    {
      v5 = *(_BYTE *)v4;
      v6 = 0;
      ++v4;
      if ( v5 > 0 )
      {
        v23 = v5;
        do
        {
          v7 = *(_BYTE *)v4 + v6;
          v8 = *(_BYTE *)(v4 + 1);
          cur_x = v7;
          v9 = (const void *)(v4 + 2);
          if ( v8 >= 0 )
          {
            v10 = v8;
            v18 = &v22->window_buffer[v7];
            v19 = (unsigned int)v8 >> 2;
            qmemcpy(v18, v9, 4 * v19);
            v20 = (char *)v9 + 4 * v19;
            v4 = (int)v9 + v8;
            qmemcpy(&v18[4 * v19], v20, v8 & 3);
            v1 = v22;
          }
          else
          {
            v10 = (char)-v8;
            v11 = v7;
            v12 = v1->window_buffer;
            v13 = &v12[v11];
            LOBYTE(v12) = *(_BYTE *)v9;
            BYTE1(v12) = *(_BYTE *)v9;
            v14 = (char)-v8;
            v15 = -v8;
            v16 = (_DWORD)v12 << 16;
            LOWORD(v16) = (_WORD)v12;
            v7 = cur_x;
            v14 >>= 2;
            memset32(v13, v16, v14);
            v17 = &v13[4 * v14];
            LOBYTE(v14) = v15;
            v1 = v22;
            v4 = (int)v9 + 1;
            memset(v17, v16, v14 & 3);
          }
          v6 = v10 + v7;
          --v23;
        }
        while ( v23 );
      }
      v21 = v24 == 1;
      v1->window_buffer += v1->drawarea_width;
      --v24;
    }
    while ( !v21 );
  }
}

//----- (0044A390) --------------------------------------------------------
void __thiscall RGE_Flic_Player::black(RGE_Flic_Player *this)
{
  int v1; // esi@1
  int v2; // eax@2

  v1 = 0;
  if ( this->flic_size_y > 0 )
  {
    do
    {
      memset(this->window_buffer, 0, this->flic_size_x);
      v2 = this->flic_size_y;
      ++v1;
      this->window_buffer += this->drawarea_width;
    }
    while ( v1 < v2 );
  }
}

//----- (0044A3E0) --------------------------------------------------------
void __thiscall RGE_Flic_Player::byte_run(RGE_Flic_Player *this)
{
  RGE_Flic_Player *v1; // esi@1
  char *v2; // edx@1
  int v3; // ebx@3
  char v4; // al@4
  const void *v5; // edx@4
  int v6; // ebp@5
  int v7; // edi@5
  char *v8; // ebx@5
  char *v9; // edi@5
  unsigned int v10; // ecx@5
  char v11; // si@5
  int v12; // eax@5
  char *v13; // edi@5
  char *v14; // edi@6
  unsigned int v15; // eax@6
  char *v16; // esi@6
  bool v17; // zf@8
  RGE_Flic_Player *v18; // [sp+4h] [bp-Ch]@1
  int cur_x; // [sp+8h] [bp-8h]@3
  int v20; // [sp+Ch] [bp-4h]@2

  v1 = this;
  v18 = this;
  v2 = this->chunk;
  if ( this->y1 + this->flic_size_y - 1 >= 0 )
  {
    v20 = this->y1 + this->flic_size_y;
    do
    {
      v3 = 0;
      ++v2;
      cur_x = 0;
      do
      {
        v4 = *v2;
        v5 = v2 + 1;
        if ( v4 < 0 )
        {
          v6 = (char)-v4;
          v14 = &v18->window_buffer[v3];
          v15 = (char)-v4;
          qmemcpy(v14, v5, 4 * (v15 >> 2));
          v16 = (char *)v5 + 4 * (v15 >> 2);
          v2 = (char *)v5 + v6;
          qmemcpy(&v14[4 * (v15 >> 2)], v16, v15 & 3);
          v1 = v18;
        }
        else
        {
          v6 = v4;
          v7 = v3;
          v8 = v1->window_buffer;
          v9 = &v8[v7];
          LOBYTE(v8) = *(_BYTE *)v5;
          BYTE1(v8) = *(_BYTE *)v5;
          v10 = v4;
          v11 = v4;
          v12 = (_DWORD)v8 << 16;
          LOWORD(v12) = (_WORD)v8;
          v3 = cur_x;
          v10 >>= 2;
          memset32(v9, v12, v10);
          v13 = &v9[4 * v10];
          LOBYTE(v10) = v11;
          v1 = v18;
          v2 = (char *)v5 + 1;
          memset(v13, v12, v10 & 3);
        }
        v3 += v6;
        cur_x = v3;
      }
      while ( v3 < v1->flic_width );
      v17 = v20 == 1;
      v1->window_buffer += v1->drawarea_width;
      --v20;
    }
    while ( !v17 );
  }
}
