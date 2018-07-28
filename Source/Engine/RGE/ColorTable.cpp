
void RGE_translate_palette(PALETTEENTRY *palette1, PALETTEENTRY *palette2, PALETTEENTRY color, int amount, int ignore_color1, int ignore_color2)
{
  signed int v6; // eax@1
  char *v7; // ebp@1
  signed int v8; // ecx@1
  char *v9; // edi@1
  int v10; // ebx@4
  int v11; // ecx@4
  int *v12; // eax@5
  signed int v13; // esi@5
  int v14; // ecx@6
  int v15; // ecx@10
  unsigned int v16; // edx@10
  unsigned int v17; // edx@10
  int index1; // [sp+10h] [bp-10h]@1
  int intense[3]; // [sp+14h] [bp-Ch]@4
  PALETTEENTRY *palette1a; // [sp+24h] [bp+4h]@1
  PALETTEENTRY *palette2a; // [sp+28h] [bp+8h]@4

  v6 = 0;
  v7 = &palette2->peFlags;
  v8 = (char *)palette2 - (char *)palette1;
  index1 = 0;
  v9 = &palette1->peGreen;
  palette1a = (PALETTEENTRY *)((char *)palette2 - (char *)palette1);
  do
  {
    if( v6 == ignore_color1 || v6 == ignore_color2 )
    {
      *(v7 - 3) = *(v9 - 1);
      v9[v8] = *v9;
      *(v7 - 1) = v9[1];
      *v7 = v9[2];
    }
    else
    {
      v10 = *(_DWORD *)(v9 - 1) & 0xFF;
      intense[0] = *(_DWORD *)(v9 - 1) & 0xFF;
      v11 = (unsigned __int8)v9[1];
      intense[1] = (unsigned __int8)*v9;
      intense[2] = v11;
      palette2a = (PALETTEENTRY *)2;
      do
      {
        v12 = &intense[1];
        v13 = 2;
        do
        {
          v14 = *(v12 - 1);
          if( v14 < *v12 )
          {
            *(v12 - 1) = *v12;
            *v12 = v14;
          }
          ++v12;
          --v13;
        }
        while( v13 );
        palette2a = (PALETTEENTRY *)((char *)palette2a - 1);
      }
      while( palette2a );
      v15 = intense[0] + (255 - intense[0]) * (intense[1] + intense[2]) / 512;
      v16 = (signed int)((unsigned __int64)(1374389535i64 * amount * (v15 * (unsigned __int8)color.peRed / 255 - v10)) >> 32) >> 5;
      *(v7 - 3) = *(v9 - 1) + (v16 >> 31) + v16;
      v17 = (signed int)((unsigned __int64)(1374389535i64
                                          * amount
                                          * (v15 * (unsigned __int8)color.peGreen / 255 - (unsigned __int8)*v9)) >> 32) >> 5;
      v9[(_DWORD)palette1a] = *v9 + (v17 >> 31) + v17;
      *(v7 - 1) = v9[1] + amount * (v15 * (unsigned __int8)color.peBlue / 255 - (unsigned __int8)v9[1]) / 100;
      v8 = (signed int)palette1a;
      v6 = index1;
      *v7 = v9[2];
    }
    ++v6;
    v9 += 4;
    v7 += 4;
    index1 = v6;
  }
  while( v6 < 256 );
}

void RGE_fade_palette(TDrawArea *surface, PALETTEENTRY color, float fade_time, char direction, PALETTEENTRY *new_palette, int ignore_color1, int ignore_color2)
{
    char *v10; // eax@5
    PALETTEENTRY *v11; // ecx@5
    signed int v12; // edx@5
    char v13; // bl@6

    signed __int64 amount;
    float delta_time;
    float delta_timea;
    int old_time;
    float fade_time2;
    PALETTEENTRY palette1[256];
    PALETTEENTRY palette2[256];

    v7 = 0;
    v8 = 0;
    do
    {
        palette1[v8].peRed = 0;
        palette2[v8].peRed = 0;
        palette1[v8].peBlue = 0;
        palette2[v8].peBlue = 0;
        palette1[v8].peGreen = 0;
        palette2[v8].peGreen = 0;
        palette1[v8].peFlags = 0;
        palette2[v8].peFlags = 0;
    }
    while( ++v8 < 256 );

    if( new_palette )
    {
        v10 = &new_palette->peGreen;
        v11 = palette1;
        v12 = 256;
        do
        {
            v13 = *(v10 - 1);
            v10 += 4;
            v11->peRed = v13;
            v10[&palette1[0].peGreen - (char *)new_palette - 4] = *(v10 - 3);
            v10[(char *)palette1 - (char *)new_palette - 4] = *(v10 - 4);
            v10[&palette1[0].peBlue - (char *)new_palette - 4] = *(v10 - 2);
            ++v11;
        }
        while( --v12 );
        v7 = 0;
    }
    else
    {
        surface->GetPalette(palette1);
    }
    old_time = timeGetTime();
    fade_time2 = fade_time * fade_time;

    if( direction == 1 )
    {
        do
        {
            delta_time = (timeGetTime() - old_time) * 0.001;
            if( fade_time <= 0.0 || delta_time > fade_time || delta_time < 0.0 ||
                amount = (delta_time * delta_time / fade_time2 * 100.0), amount >= 100 )
            {
                LODWORD(amount) = 100;
                v7 = 1;
            }
            RGE_translate_palette(palette1, palette2, color, amount, ignore_color1, ignore_color2);
            surface->SetPalette(palette2);
        }
        while( v7 == 0 );
    }
    else
    {
        do
        {
            delta_timea = fade_time - (timeGetTime() - old_time) * 0.001;
            if( fade_time <= 0.0 || delta_timea > fade_time || delta_timea < 0.0 ||
                amount = (delta_timea * delta_timea / fade_time2 * 100.0), amount <= 0 )
            {
                LODWORD(amount) = 0;
                v7 = 1;
            }
            RGE_translate_palette(palette1, palette2, color, amount, ignore_color1, ignore_color2);
            surface->SetPalette(palette2);
        }
        while( v7 == 0 );
    }
}

RGE_Color_Table::RGE_Color_Table(int infile)
{
    short temp_color;
    char tempname[300];

    rge_read(infile, this->color_table_name, sizeof(RGE_Color_Table::color_table_name));
    rge_read(infile, &this->id, 2);
    rge_read(infile, &this->resource_id, 2);
    rge_read(infile, &this->map_color, 1);
    rge_read(infile, &this->type, 1);

    sprintf(tempname, "data\\%s", this->color_table_name);

    if( FILE *hFile = fopen(tempname, "r") )
    {
        int i = 0;
        do
        {
            fscanf(hFile, "%hd", &temp_color);
            this->table[i++] = temp_color;
        }
        while( i < 256 );
        fclose(hFile);
    }
}

RGE_Color_Table::RGE_Color_Table(char *filename)
{
    char last[] = ".col";
    char tempname[300];

    this->resource_id = 0;
    this->map_color = 0;
    this->type = 0;

    memset(this->table, 0, sizeof(this->table));
    strcpy(this->color_table_name, filename);
    short temp_color = strlen(last) + 1;
    qmemcpy(&this->color_table_name[strlen(this->color_table_name)], last, temp_color);
    sprintf(tempname, "data\\%s", this->color_table_name);

    if( FILE *hFile = fopen(tempname, "r") )
    {
        int i = 0;
        do
        {
            fscanf(hFile, "%hd", &temp_color);
            this->table[i++] = temp_color;
        }
        while( i < 256 );
        fclose(hFile);
    }
}

RGE_Color_Table::RGE_Color_Table(TDrawArea *surface, int amount, PALETTEENTRY *in_color, PALETTEENTRY *palette1)
{
  RGE_Color_Table *v5; // esi@1
  char *v6; // ecx@3
  char *v7; // eax@3
  signed int v8; // ebp@3
  char v9; // dl@4
  char *v10; // ecx@9
  signed int v11; // ebp@10
  signed int v12; // edi@10
  char *v13; // esi@10
  int v14; // edx@11
  int v15; // ebx@11
  int temp_color; // [sp+10h] [bp-81Ch]@7
  char temp_colora; // [sp+10h] [bp-81Ch]@10
  RGE_Color_Table *v18; // [sp+14h] [bp-818h]@1
  int index1; // [sp+18h] [bp-814h]@9
  char *v20; // [sp+1Ch] [bp-810h]@9
  int v21; // [sp+20h] [bp-80Ch]@10
  PALETTEENTRY palette[256]; // [sp+2Ch] [bp-800h]@2
  PALETTEENTRY temp_palette[256]; // [sp+42Ch] [bp-400h]@9

  v5 = this;
  v18 = this;
  this->vfptr = (RGE_Color_TableVtbl *)&RGE_Color_Table::`vftable';
  if( palette1 )
  {
    v6 = &palette[0].peGreen;
    v7 = &palette1->peBlue;
    v8 = 256;
    do
    {
      v9 = *(v7 - 2);
      v7 += 4;
      *(v6 - 1) = v9;
      *v6 = *(v7 - 5);
      v7[(char *)palette - (char *)palette1 - 4] = *(v7 - 4);
      v7[&palette[0].peGreen - (char *)palette1 - 4] = *(v7 - 3);
      v6 += 4;
      --v8;
    }
    while( v8 );
    v5 = v18;
  }
  else
  {
    surface->GetPalette(palette);
  }
  if( in_color )
  {
    LOBYTE(temp_color) = in_color->peRed;
    BYTE2(temp_color) = in_color->peBlue;
    BYTE1(temp_color) = in_color->peGreen;
    BYTE3(temp_color) = in_color->peFlags;
  }
  else
  {
    LOBYTE(temp_color) = 0;
    *(_WORD *)((char *)&temp_color + 1) = 0;
    BYTE3(temp_color) = 0;
  }
  v5->resource_id = 0;
  v5->map_color = 0;
  v5->type = 0;
  memset(v5->table, 0, sizeof(v5->table));
  RGE_translate_palette(palette, temp_palette, (PALETTEENTRY)temp_color, amount, -1, -1);
  v10 = &temp_palette[0].peGreen;
  index1 = 0;
  v20 = &temp_palette[0].peGreen;
  do
  {
    v11 = 0;
    v21 = (unsigned __int8)*(v10 - 1);
    temp_colora = 0;
    v12 = 20000;
    v13 = &palette[0].peGreen;
    do
    {
      v14 = (unsigned __int8)v10[1] - (unsigned __int8)v13[1];
      v15 = ((unsigned __int8)*v10 - (unsigned __int8)*v13) * ((unsigned __int8)*v10 - (unsigned __int8)*v13);
      if( v14 * v14 + v15 + (v21 - (unsigned __int8)*(v13 - 1)) * (v21 - (unsigned __int8)*(v13 - 1)) < v12 )
      {
        v12 = v14 * v14 + v15 + (v21 - (unsigned __int8)*(v13 - 1)) * (v21 - (unsigned __int8)*(v13 - 1));
        temp_colora = v11;
      }
      ++v11;
      v13 += 4;
    }
    while( v11 <= 255 );
    v18->table[index1] = temp_colora;
    v10 = v20 + 4;
    ++index1;
    v20 += 4;
  }
  while( index1 <= 255 );
}

void RGE_Color_Table::save(int outfile)
{
    rge_write(outfile, this->color_table_name, sizeof(RGE_Color_Table::color_table_name));
    rge_write(outfile, &this->id, 2);
    rge_write(outfile, &this->resource_id, 2);
    rge_write(outfile, &this->map_color, 1);
    rge_write(outfile, &this->type, 1);
}

void color_log(char c1, char c2, int pos)
{
  TDrawSystem *v3; // esi@4
  __int64 v4; // rax@6
  int v5; // ecx@6
  int v6; // eax@6
  tagRECT scr_dest; // [sp+38h] [bp-8Ch]@8
  tagRECT back_dest; // [sp+48h] [bp-7Ch]@6
  tagPOINT point; // [sp+58h] [bp-6Ch]@6
  _DDBLTFX ddbltfx; // [sp+60h] [bp-64h]@8

  if( do_color_log )
  {
    if( rge_base_game )
    {
      if( rge_base_game->prog_mode >= 2 )
      {
        v3 = rge_base_game->draw_system;
        if( v3 )
        {
          if( v3->PrimarySurface )
          {
            v4 = v3->DrawArea->Width;
            back_dest.top = 0;
            back_dest.bottom = 10;
            v5 = (((signed int)v4 - HIDWORD(v4)) >> 1) + 20 * (2 - pos);
            back_dest.left = v5;
            point.x = (((signed int)v4 - HIDWORD(v4)) >> 1) + 20 * (2 - pos);
            back_dest.right = v5 + 10;
            v6 = 0;
            point.y = 0;
            if( v3->ScreenMode == 2 )
            {
              ClientToScreen(v3->Wnd, &point);
              v6 = point.y;
              v5 = point.x;
            }
            scr_dest.left = v5;
            scr_dest.top = v6;
            scr_dest.right = v5 + 10;
            scr_dest.bottom = v6 + 10;
            ddbltfx.dwSize = 100;
            ddbltfx.dwFillColor = (unsigned __int8)c1;
            ((void (__stdcall *)(IDirectDrawSurface *, tagRECT *, _DWORD, _DWORD, signed int, _DDBLTFX *))v3->PrimarySurface->vfptr[1].Release)(
              v3->PrimarySurface,
              &scr_dest,
              0,
              0,
              16778240,
              &ddbltfx);
            ddbltfx.dwSize = 100;
            ddbltfx.dwFillColor = (unsigned __int8)c1;
            ((void (__stdcall *)(IDirectDrawSurface *, tagRECT *, _DWORD, _DWORD, signed int, _DDBLTFX *))v3->DrawArea->DrawSurface->vfptr[1].Release)(
              v3->DrawArea->DrawSurface,
              &back_dest,
              0,
              0,
              16778240,
              &ddbltfx);
            back_dest.bottom += 10;
            scr_dest.top += 10;
            back_dest.top += 10;
            scr_dest.bottom += 10;
            ddbltfx.dwSize = 100;
            ddbltfx.dwFillColor = (unsigned __int8)c2;
            ((void (__stdcall *)(IDirectDrawSurface *, tagRECT *, _DWORD, _DWORD, signed int, _DDBLTFX *))v3->PrimarySurface->vfptr[1].Release)(
              v3->PrimarySurface,
              &scr_dest,
              0,
              0,
              16778240,
              &ddbltfx);
            ddbltfx.dwSize = 100;
            ddbltfx.dwFillColor = (unsigned __int8)c2;
            ((void (__stdcall *)(IDirectDrawSurface *, tagRECT *, _DWORD, _DWORD, signed int, _DDBLTFX *))v3->DrawArea->DrawSurface->vfptr[1].Release)(
              v3->DrawArea->DrawSurface,
              &back_dest,
              0,
              0,
              16778240,
              &ddbltfx);
          }
        }
      }
    }
  }
}
