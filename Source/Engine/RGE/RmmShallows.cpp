
//----- (00487010) --------------------------------------------------------
void __thiscall RGE_RMM_Shallows_Generator::RGE_RMM_Shallows_Generator(RGE_RMM_Shallows_Generator *this, RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Shallows_Info *in_info)
{
  RGE_RMM_Shallows_Generator *v4; // ebx@1

  v4 = this;
  RGE_Random_Map_Module::RGE_Random_Map_Module((RGE_Random_Map_Module *)&this->vfptr, in_map, parent_module, 1);
  v4->vfptr = (RGE_Random_Map_ModuleVtbl *)&RGE_RMM_Shallows_Generator::`vftable';
  LODWORD(v4->schedule) = 1066192077;
  qmemcpy(&v4->info, in_info, sizeof(v4->info));
}
// 571EE4: using guessed type unsigned __int8 (__thiscall *RGE_RMM_Shallows_Generator::`vftable')(RGE_RMM_Shallows_Generator *this);

//----- (00487050) --------------------------------------------------------
char __thiscall RGE_RMM_Shallows_Generator::generate(RGE_RMM_Shallows_Generator *this)
{
  RGE_RMM_Shallows_Generator *v1; // esi@1
  int v2; // eax@1
  int v3; // ebx@1
  int v4; // ebp@2
  int v5; // edi@2
  int v6; // eax@5
  int v7; // ebp@5
  signed int v8; // ebx@6
  int v9; // eax@7
  unsigned int v10; // edx@7
  int v11; // edi@7
  int v12; // edx@7
  char v13; // al@7
  signed int v14; // ebx@12
  int v15; // edi@13
  int v16; // edx@13
  char v17; // al@13
  int index2; // [sp+10h] [bp-8h]@5
  signed int v20; // [sp+14h] [bp-4h]@5

  v1 = this;
  RGE_Random_Map_Module::clear_stack((RGE_Random_Map_Module *)&this->vfptr);
  v2 = v1->info.shallows_num;
  v3 = 0;
  if( v2 > 0 )
  {
    do
    {
      v4 = v3 + 1;
      v5 = v3 + 1;
      if( v3 + 1 < v2 )
      {
        do
          RGE_RMM_Shallows_Generator::make_tribe_connections(v1, v3, v5++);
        while( v5 < v1->info.shallows_num );
      }
      v2 = v1->info.shallows_num;
      ++v3;
    }
    while( v4 < v2 );
  }
  v6 = v1->info.shallows_num + 2;
  v20 = 2;
  v1->info.shallows_num = v6;
  v7 = v6 - 1;
  index2 = v6 - 2;
  do
  {
    v8 = 0;
    do
    {
      v9 = debug_rand(aCMsdevWorkA_44, 69);
      v10 = (signed int)((v1->map_width - 1) * v9 + ((unsigned __int64)(-2147418109i64 * (v1->map_width - 1) * v9) >> 32)) >> 14;
      v11 = (v10 >> 31) + v10;
      v12 = (v1->map_height - 1) * debug_rand(aCMsdevWorkA_44, 70) / 0x7FFF;
      v13 = *((_BYTE *)&v1->map_row_offset[v12][v11] + 5) & 0x1F;
      if( v13 != 1 && v13 != 22 && v13 != 4 )
      {
        v1->info.shallows[v7].x = v11;
        v8 = 1;
        v1->info.shallows[v7].y = v12;
      }
    }
    while( !v8 );
    v14 = 0;
    do
    {
      v15 = (v1->map_width - 1) * debug_rand(aCMsdevWorkA_44, 84) / 0x7FFF;
      v16 = (v1->map_height - 1) * debug_rand(aCMsdevWorkA_44, 85) / 0x7FFF;
      v17 = *((_BYTE *)&v1->map_row_offset[v16][v15] + 5) & 0x1F;
      if( v17 != 1 && v17 != 22 && v17 != 4 )
      {
        v14 = 1;
        v1->info.shallows[index2].x = v15;
        v1->info.shallows[index2].y = v16;
      }
    }
    while( !v14 );
    RGE_RMM_Shallows_Generator::make_tribe_connections(v1, v7, index2);
    --v20;
  }
  while( v20 );
  return 1;
}

//----- (00487200) --------------------------------------------------------
void __thiscall RGE_RMM_Shallows_Generator::make_tribe_connections(RGE_RMM_Shallows_Generator *this, int point1, int point2)
{
  RGE_RMM_Shallows_Generator *v3; // esi@1
  int v4; // edx@1
  int v5; // ebx@1
  int v6; // ebp@1
  int v7; // eax@1
  int v8; // ecx@2
  int v9; // edi@24
  char v10; // dl@24
  char v11; // dl@27
  char v12; // dl@31
  char v13; // dl@35
  int v14; // edx@39
  char v15; // cl@39
  int v16; // ebx@42
  int v17; // eax@44
  unsigned int v18; // edx@44
  int v19; // edi@44
  int v20; // edx@46
  int v21; // eax@46
  int v22; // edx@48
  int v23; // eax@48
  int v24; // ecx@50
  int v25; // ebp@51
  int v26; // edi@54
  RGE_Tile **v27; // eax@55
  _BYTE *v28; // eax@62
  int x; // [sp+10h] [bp-E0h]@3
  int y; // [sp+14h] [bp-DCh]@3
  int ty2; // [sp+18h] [bp-D8h]@1
  int end_x; // [sp+1Ch] [bp-D4h]@1
  int tx1; // [sp+20h] [bp-D0h]@42
  int end_y; // [sp+24h] [bp-CCh]@1
  int ty; // [sp+28h] [bp-C8h]@1
  int done; // [sp+2Ch] [bp-C4h]@7
  int tx2; // [sp+30h] [bp-C0h]@46
  float in_zone; // [sp+34h] [bp-BCh]@61
  Map_Stack stack; // [sp+38h] [bp-B8h]@1
  float terrain[40]; // [sp+50h] [bp-A0h]@1

  v3 = this;
  LODWORD(terrain[0]) = 0;
  v4 = this->info.shallows[point1].y;
  ty2 = this->info.shallows[point1].x;
  ty = v4;
  v6 = this->info.shallows[point2].y;
  end_x = this->info.shallows[point2].x;
  v5 = end_x;
  memset(&terrain[1], 0, 0x9Cu);
  end_y = v6;
  RGE_Random_Map_Module::init_stack(&stack);
  LODWORD(terrain[0]) = 1065353216;
  LODWORD(terrain[2]) = 1065353216;
  LODWORD(terrain[1]) = 1088421888;
  LODWORD(terrain[22]) = 1096810496;
  LODWORD(terrain[4]) = 0x40000000;
  RGE_Random_Map_Module::find_path((RGE_Random_Map_Module *)&v3->vfptr, ty2, ty, &end_x, &end_y, terrain);
  v7 = end_x;
  if( end_x == v5 )
  {
    v8 = end_y;
    if( end_y == v6 )
    {
      y = end_y;
      x = end_x;
      if( end_x >= 0 && end_x < v3->map_width && end_y >= 0 && end_y < v3->map_height )
      {
        stack.next = 0;
        stack.prev = 0;
        done = 0;
        while( 1 )
        {
          switch ( v3->search_map_rows[v8][v7] )
          {
            case 7:
              y = --v8;
              break;
            case 6:
              y = ++v8;
              break;
            case 0xB:
              --v8;
              --v7;
              y = v8;
              x = v7;
              break;
            case 9:
              --v8;
              ++v7;
              y = v8;
              x = v7;
              break;
            case 0xA:
              y = ++v8;
              goto LABEL_14;
            case 5:
LABEL_14:
              x = --v7;
              break;
            case 8:
              y = ++v8;
              goto LABEL_16;
            case 4:
LABEL_16:
              x = ++v7;
              break;
            default:
              done = 1;
              break;
          }
          if( v7 < 0 || v7 >= v3->map_width || v8 < 0 || v8 >= v3->map_height )
            done = 1;
          if( done )
            break;
          v9 = (int)&v3->map_row_offset[v8][v7].screen_xpos;
          v10 = *(_BYTE *)(v9 + 5) & 0x1F;
          if( v10 == 1 || v10 == 22 )
          {
            v16 = x - 2 * debug_rand(aCMsdevWorkA_44, 198) / 0x7FFF - 1;
            tx1 = v16;
            if( v16 < 0 )
            {
              tx1 = 0;
              v16 = 0;
            }
            v17 = debug_rand(aCMsdevWorkA_44, 202);
            v18 = (signed int)(2 * v17 + ((unsigned __int64)(-4294836218i64 * v17) >> 32)) >> 14;
            v19 = y - ((v18 >> 31) + v18) - 1;
            if( v19 < 0 )
              v19 = 0;
            v20 = 2 * debug_rand(aCMsdevWorkA_44, 206) / 0x7FFF;
            v21 = v3->map_width;
            tx2 = v20 + x + 1;
            if( tx2 >= v21 )
              tx2 = v21 - 1;
            v22 = 3 * debug_rand(aCMsdevWorkA_44, 210) / 0x7FFF;
            v23 = v3->map_height;
            ty2 = v22 + y + 1;
            if( ty2 >= v23 )
              ty2 = v23 - 1;
            v24 = v19;
            ty = v19;
            if( v19 <= ty2 )
            {
              v25 = v19;
              while( 1 )
              {
                if( tx1 <= tx2 )
                {
                  v26 = tx1;
                  do
                  {
                    v27 = &v3->map_row_offset[v25];
                    if( (*((_BYTE *)&(*v27)[v26] + 5) & 0x1F) == 1 || (*((_BYTE *)&(*v27)[v26] + 5) & 0x1F) == 22 )
                    {
                      RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v3->vfptr, &stack, v16, v24, 0.0, 0.0);
                      v24 = ty;
                    }
                    ++v16;
                    ++v26;
                  }
                  while( v16 <= tx2 );
                }
                ++v24;
                ++v25;
                ty = v24;
                if( v24 > ty2 )
                  break;
                v16 = tx1;
              }
            }
          }
          else
          {
            if( v7 > 0 )
            {
              v11 = *(_BYTE *)(v9 - 19) & 0x1F;
              if( v11 == 1 || v11 == 22 )
              {
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v3->vfptr, &stack, v7 - 1, v8, 0.0, 0.0);
                v8 = y;
                v7 = x;
              }
            }
            if( v7 < v3->map_width - 1 )
            {
              v12 = *((_BYTE *)&v3->map_row_offset[v8][v7 + 1] + 5) & 0x1F;
              if( v12 == 1 || v12 == 22 )
              {
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v3->vfptr, &stack, v7 + 1, v8, 0.0, 0.0);
                v8 = y;
                v7 = x;
              }
            }
            if( v8 > 0 )
            {
              v13 = *((_BYTE *)&v3->map_row_offset[v8 - 1][v7] + 5) & 0x1F;
              if( v13 == 1 || v13 == 22 )
              {
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v3->vfptr, &stack, v7, v8 - 1, 0.0, 0.0);
                v8 = y;
                v7 = x;
              }
            }
            if( v8 < v3->map_height - 1 )
            {
              v14 = v8 + 1;
              v15 = *((_BYTE *)&v3->map_row_offset[v8 + 1][v7] + 5) & 0x1F;
              if( v15 == 1 || v15 == 22 )
                RGE_Random_Map_Module::push_stack((RGE_Random_Map_Module *)&v3->vfptr, &stack, v7, v14, 0.0, 0.0);
            }
          }
          v3->search_map_rows[end_y][end_x] = -1;
          v7 = x;
          v8 = y;
          end_x = x;
          end_y = y;
        }
        for( ; RGE_Random_Map_Module::pop_stack(&stack, &x, &y, &in_zone); *v28 = *v28 & 0xE4 | 4 )
          v28 = (char *)&v3->map_row_offset[y][x] + 5;
        RGE_Random_Map_Module::deinit_stack(&stack);
      }
    }
  }
}
