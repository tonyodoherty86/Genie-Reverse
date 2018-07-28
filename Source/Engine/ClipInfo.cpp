
//----- (0053AD90) --------------------------------------------------------
void __thiscall DClipInfo_List::DClipInfo_List(DClipInfo_List *this, int InitialSize, int GrowSize, int szitem, int top_Yline, int bottom_Yline, int mxLevel)
{
  DClipInfo_List *v7; // esi@1
  DClipInfo_Node **v8; // eax@1
  size_t v9; // ecx@1

  v7 = this;
  this->Free_Pool_Zone = -1;
  this->Free_Pool_Index = -1;
  this->Element_Size = szitem;
  this->Default_Grow_Size = GrowSize;
  this->YLine_Size = bottom_Yline - top_Yline + 1;
  this->Zone_Ptrs = 0;
  this->Zone_Size_Ptrs = 0;
  this->Max_Zones = 8;
  this->Used_Zones = 0;
  this->Free_Head = 0;
  this->Total_Blocks = 0;
  this->Free_Blocks = 0;
  this->YLine_Offset = -top_Yline;
  this->Max_Draw_Levels = mxLevel;
  DClipInfo_List::SetCaptureLevel(this, 0, mxLevel);
  v7->Draw_Clip_Nodes = (DClipInfo_Node **)calloc(v7->YLine_Size, 4u);
  v8 = (DClipInfo_Node **)calloc(v7->Max_Draw_Levels + 1, 4u);
  v9 = v7->Max_Draw_Levels + 1;
  v7->Draw_Level_Head = v8;
  v7->Draw_Level_Tail = (DClipInfo_Node **)calloc(v9, 4u);
  DClipInfo_List::ResetStats(v7);
  DClipInfo_List::SetNumZones(v7, 8);
  DClipInfo_List::InitNewZone(v7, InitialSize);
  v7->Select_Box = 0;
}

//----- (0053AE50) --------------------------------------------------------
void __thiscall DClipInfo_List::~DClipInfo_List(DClipInfo_List *this)
{
  DClipInfo_List *v1; // esi@1
  int i; // edi@1
  DClipInfo_Node **v3; // esi@13

  v1 = this;
  for( i = 0; i < v1->Used_Zones; ++i )
  {
    if( v1->Zone_Ptrs[i] )
      free(v1->Zone_Ptrs[i]);
  }
  if( v1->Zone_Ptrs )
    free(v1->Zone_Ptrs);
  if( v1->Zone_Size_Ptrs )
    free(v1->Zone_Size_Ptrs);
  if( v1->Draw_Clip_Nodes )
    free(v1->Draw_Clip_Nodes);
  if( v1->Draw_Level_Head )
    free(v1->Draw_Level_Head);
  v3 = v1->Draw_Level_Tail;
  if( v3 )
    free(v3);
}

//----- (0053AED0) --------------------------------------------------------
void __thiscall DClipInfo_List::SetCaptureLevel(DClipInfo_List *this, int minLevel, int maxLevel)
{
  int v3; // edx@1
  int v4; // eax@1

  v3 = minLevel;
  v4 = maxLevel;
  if( minLevel > maxLevel )
  {
    v3 = maxLevel;
    v4 = minLevel;
  }
  if( v3 < 0 )
    v3 = 0;
  if( v4 > this->Max_Draw_Levels )
    v4 = this->Max_Draw_Levels;
  this->Accept_Min_Level = v3;
  this->Accept_Max_Level = v4;
}

//----- (0053AF00) --------------------------------------------------------
void __thiscall DClipInfo_List::SetNumZones(DClipInfo_List *this, int New_Size)
{
  int v2; // ebx@1
  DClipInfo_List *v3; // esi@1
  DClipInfo_Node **v4; // ebp@2
  int *v5; // edi@2
  int v6; // eax@3
  int v7; // edx@4
  char *v8; // ecx@5
  DClipInfo_Node *v9; // ebp@5
  int New_Sizea; // [sp+Ch] [bp+4h]@2

  v2 = New_Size;
  v3 = this;
  if( New_Size >= this->Max_Zones )
  {
    v4 = (DClipInfo_Node **)calloc(New_Size, 4u);
    New_Sizea = (int)v4;
    v5 = (int *)calloc(v2, 4u);
    if( v3->Zone_Ptrs )
    {
      v6 = 0;
      if( v3->Used_Zones > 0 )
      {
        v7 = (char *)v4 - (char *)v5;
        do
        {
          v8 = (char *)&v5[v6];
          v9 = v3->Zone_Ptrs[v6++];
          *(_DWORD *)&v8[v7] = v9;
          *(_DWORD *)v8 = v3->Zone_Size_Ptrs[v6 - 1];
        }
        while( v6 < v3->Used_Zones );
        v4 = (DClipInfo_Node **)New_Sizea;
      }
      free(v3->Zone_Ptrs);
      free(v3->Zone_Size_Ptrs);
    }
    v3->Zone_Ptrs = v4;
    v3->Zone_Size_Ptrs = v5;
    v3->Max_Zones = v2;
  }
}

//----- (0053AF90) --------------------------------------------------------
void __thiscall DClipInfo_List::InitNewZone(DClipInfo_List *this, int Zone_Size)
{
  DClipInfo_List *v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@3
  int *v5; // ecx@3
  size_t v6; // ST00_4@3
  int v7; // ecx@3
  int v8; // edx@3
  int v9; // eax@3

  v2 = this;
  v3 = this->Used_Zones;
  if( v3 == this->Max_Zones )
    DClipInfo_List::SetNumZones(this, v3 + 4);
  v4 = v2->Used_Zones;
  v5 = v2->Zone_Size_Ptrs;
  v2->Used_Zones = v4 + 1;
  v6 = Zone_Size * v2->Element_Size;
  v5[v4] = Zone_Size;
  v2->Zone_Ptrs[v4] = (DClipInfo_Node *)malloc(v6);
  v7 = v2->Free_Blocks;
  v8 = Zone_Size + v2->Total_Blocks;
  ++v2->NewZone_Count;
  v9 = v2->Free_Pool_Zone;
  v2->Total_Blocks = v8;
  v2->Free_Blocks = Zone_Size + v7;
  if( v9 == -1 )
  {
    v2->Free_Pool_Zone = v4;
    v2->Free_Pool_Index = 0;
  }
}

//----- (0053B000) --------------------------------------------------------
DClipInfo_Node *__thiscall DClipInfo_List::GetNode(DClipInfo_List *this)
{
  DClipInfo_List *v1; // esi@1
  DClipInfo_Node *result; // eax@3
  int v3; // edx@5
  int v4; // ecx@5
  int *v5; // edi@5
  int v6; // ecx@6
  int v7; // edx@6

  v1 = this;
  if( !this->Free_Blocks )
    DClipInfo_List::InitNewZone(this, this->Default_Grow_Size);
  result = v1->Free_Head;
  if( result )
  {
    v1->Free_Head = result->Next;
    --v1->Free_Blocks;
  }
  else
  {
    v3 = v1->Free_Pool_Zone;
    result = &v1->Zone_Ptrs[v3][v1->Free_Pool_Index];
    v4 = v1->Free_Pool_Index + 1;
    --v1->Free_Blocks;
    v5 = v1->Zone_Size_Ptrs;
    v1->Free_Pool_Index = v4;
    if( v4 == v5[v3] )
    {
      v6 = v3 + 1;
      v7 = v1->Used_Zones;
      v1->Free_Pool_Zone = v6;
      v1->Free_Pool_Index = 0;
      if( v6 == v7 )
        v1->Free_Pool_Zone = -1;
    }
  }
  return result;
}

//----- (0053B070) --------------------------------------------------------
void __thiscall DClipInfo_List::SetDrawRegion(DClipInfo_List *this, int Left, int Top, int Right, int Bottom)
{
  if( Left <= Right && Top <= Bottom )
  {
    this->SD_XMin = Left;
    this->SD_XMax = Right;
    this->SD_YMin = Top;
    this->SD_YMax = Bottom;
  }
}

//----- (0053B0A0) --------------------------------------------------------
void __thiscall DClipInfo_List::AddDrawNode(DClipInfo_List *this, void *ShapeBase, Shape_Info *theShape, int SortLine, int Xpos, int Ypos, int DrawFlags, char *ColorTable, int XformMask, int DrawLevel, int Object_ID)
{
  DClipInfo_List *v11; // esi@1
  Shape_Info *v12; // ebx@3
  int v13; // edi@3
  int v14; // ecx@3
  int v15; // edx@3
  DClipInfo_Node *v16; // eax@9
  DClipInfo_Node **v17; // ecx@9
  DClipInfo_Node **v18; // edx@9
  DClipInfo_Node *i; // ecx@11
  __int16 *v20; // edx@14
  __int16 v21; // di@15
  __int16 v22; // dx@15
  Shape_Info *theShapea; // [sp+18h] [bp+8h]@3
  int HotX; // [sp+1Ch] [bp+Ch]@1
  int Line; // [sp+20h] [bp+10h]@3

  v11 = this;
  HotX = SortLine + this->YLine_Offset;
  if( DrawLevel <= this->Accept_Max_Level && DrawLevel >= this->Accept_Min_Level )
  {
    v12 = theShape;
    v13 = Xpos;
    v14 = Xpos + theShape->Width - 1;
    v15 = Ypos + theShape->Height - 1;
    theShapea = (Shape_Info *)(Xpos + theShape->Hotspot_X);
    Line = Ypos + v12->Hotspot_Y;
    if( v13 <= v11->SD_XMax
      && v14 >= v11->SD_XMin
      && Ypos <= v11->SD_YMax
      && v15 >= v11->SD_YMin
      && HotX >= 0
      && HotX < v11->YLine_Size )
    {
      v16 = DClipInfo_List::GetNode(v11);
      v17 = &v11->Draw_Clip_Nodes[HotX];
      v18 = (DClipInfo_Node **)*v17;
      if( *v17 )
      {
        for( i = *v18; i; i = i->Next )
          v18 = (DClipInfo_Node **)i;
        *v18 = v16;
      }
      else
      {
        *v17 = v16;
      }
      v16->Object_ID = Object_ID;
      v16->Draw_Flag = DrawFlags;
      v16->Shape_Base = (char *)ShapeBase;
      v16->Color_Table = ColorTable;
      v16->Xform_Mask = XformMask;
      v16->Next = 0;
      v16->NextOnLevel = 0;
      v16->Shape = v12;
      v16->Draw_X = v13;
      v16->Draw_Y = Ypos;
      v16->Draw_Level = DrawLevel;
      v16->Node_Type = 0;
      v20 = v11->Select_Box;
      if( v20 )
      {
        v21 = (signed __int16)theShapea;
        v16->x1 = *v20 + (_WORD)theShapea;
        v22 = Line;
        v16->y1 = Line + v11->Select_Box[1];
        v16->x2 = (_WORD)theShapea + v11->Select_Box[2];
        v16->y2 = Line + v11->Select_Box[3];
        v11->Select_Box = 0;
      }
      else
      {
        v16->x1 = v13;
        v16->y1 = Ypos;
        v22 = Line;
        v16->x2 = LOWORD(v12->Width) + v13 - 1;
        v21 = (signed __int16)theShapea;
        v16->y2 = LOWORD(v12->Height) + Ypos - 1;
      }
      v16->x3 = v21;
      v16->y3 = v22;
      v16->x4 = 0;
      v16->y4 = 0;
    }
  }
}

//----- (0053B220) --------------------------------------------------------
DClipInfo_Node *__thiscall DClipInfo_List::AddGDINode(DClipInfo_List *this, int GDI_Type, int SortLine, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, int DrawLevel, int DrawColor, int Object_ID)
{
  DClipInfo_List *v14; // esi@1
  int v15; // ebx@1
  DClipInfo_Node *result; // eax@5

  v14 = this;
  v15 = SortLine + this->YLine_Offset;
  if( DrawLevel > this->Accept_Max_Level || DrawLevel < this->Accept_Min_Level || v15 < 0 || v15 >= this->YLine_Size )
  {
    result = 0;
  }
  else
  {
    result = DClipInfo_List::GetNode(this);
    result->Next = v14->Draw_Clip_Nodes[v15];
    v14->Draw_Clip_Nodes[v15] = result;
    result->Object_ID = Object_ID;
    result->Draw_Flag = DrawColor;
    result->Node_Type = GDI_Type;
    result->x1 = X1;
    result->y1 = Y1;
    result->x2 = X2;
    result->y2 = Y2;
    result->x3 = X3;
    result->y3 = Y3;
    result->NextOnLevel = 0;
    result->Shape = 0;
    result->Draw_X = 0;
    result->Draw_Y = 0;
    result->Shape_Base = 0;
    result->Color_Table = 0;
    result->Xform_Mask = 0;
    result->Draw_Level = DrawLevel;
    result->x4 = X4;
    result->y4 = Y4;
  }
  return result;
}

//----- (0053B300) --------------------------------------------------------
DClipInfo_Node *__thiscall DClipInfo_List::LocateIDbyDrawLevel(DClipInfo_List *this, int SearchID, int StartLevel, int EndLevel, int NodeType)
{
  int v5; // eax@1
  int v6; // esi@1
  int v7; // edx@5
  int v8; // edx@9
  DClipInfo_Node **v9; // ecx@10
  DClipInfo_Node *result; // eax@11

  v5 = StartLevel;
  v6 = EndLevel;
  if( StartLevel > EndLevel )
  {
    v5 = EndLevel;
    v6 = StartLevel;
  }
  if( v5 < 0 )
    v5 = 0;
  v7 = this->Max_Draw_Levels;
  if( v6 > v7 )
    v6 = this->Max_Draw_Levels;
  if( v5 > v7 || v6 < 0 || (v8 = v5, v5 > v6) )
  {
LABEL_16:
    result = 0;
  }
  else
  {
    v9 = &this->Draw_Level_Head[v5];
    while( 1 )
    {
      result = *v9;
      if( *v9 )
        break;
LABEL_15:
      ++v8;
      ++v9;
      if( v8 > v6 )
        goto LABEL_16;
    }
    while( result->Object_ID != SearchID || result->Node_Type != NodeType )
    {
      result = result->NextOnLevel;
      if( !result )
        goto LABEL_15;
    }
  }
  return result;
}

//----- (0053B370) --------------------------------------------------------
void __thiscall DClipInfo_List::Scroll(DClipInfo_List *this, int xDelta, int yDelta)
{
  bool v3; // sf@1
  int v4; // eax@2
  int v5; // edi@3
  DClipInfo_Node **v6; // esi@4
  DClipInfo_Node *v7; // ebx@4
  int i; // eax@5
  int v9; // esi@9
  int v10; // edi@9
  int v11; // eax@9
  int v12; // esi@9
  int v13; // ebx@10
  DClipInfo_Node **v14; // esi@11
  DClipInfo_Node *v15; // ebp@11
  int v16; // eax@12
  int j; // ebx@14
  DClipInfo_Node *k; // eax@15
  int v19; // edi@17

  v3 = yDelta < 0;
  if( yDelta > 0 )
  {
    v4 = 0;
    if( this->YLine_Size - yDelta > 0 )
    {
      v5 = yDelta;
      do
      {
        v6 = this->Draw_Clip_Nodes;
        ++v4;
        v7 = v6[v5];
        ++v5;
        v6[v4 - 1] = v7;
      }
      while( v4 < this->YLine_Size - yDelta );
    }
    for( i = this->YLine_Size - yDelta; i < this->YLine_Size; this->Draw_Clip_Nodes[i - 1] = 0 )
      ++i;
    v3 = yDelta < 0;
  }
  if( v3 )
  {
    v9 = this->YLine_Size;
    v10 = -yDelta;
    v11 = v9 - 1;
    v12 = yDelta + v9 - 1;
    if( v11 >= -yDelta )
    {
      v13 = v12;
      do
      {
        v14 = this->Draw_Clip_Nodes;
        --v11;
        v15 = v14[v13];
        --v13;
        v14[v11 + 1] = v15;
      }
      while( v11 >= v10 );
    }
    v16 = 0;
    if( yDelta < 0 )
    {
      do
        this->Draw_Clip_Nodes[++v16 - 1] = 0;
      while( v16 < v10 );
    }
  }
  for( j = 0; j < this->YLine_Size; ++j )
  {
    for( k = this->Draw_Clip_Nodes[j]; k; k = k->Next )
    {
      switch ( k->Node_Type )
      {
        case 0:
          v19 = k->Draw_Y - yDelta;
          k->Draw_X -= xDelta;
          k->Draw_Y = v19;
          continue;
        case 1:
          k->y3 -= yDelta;
          k->y4 -= yDelta;
          goto LABEL_19;
        case 2:
LABEL_19:
          k->x3 -= xDelta;
          k->x4 -= xDelta;
          goto LABEL_20;
        case 3:
        case 4:
LABEL_20:
          k->x1 -= xDelta;
          k->y1 -= yDelta;
          k->x2 -= xDelta;
          k->y2 -= yDelta;
          break;
        default:
          continue;
      }
    }
  }
}

//----- (0053B490) --------------------------------------------------------
void __thiscall DClipInfo_List::FreeNode(DClipInfo_List *this, DClipInfo_Node *theNode)
{
  theNode->Next = this->Free_Head;
  this->Free_Head = theNode;
  ++this->Free_Blocks;
}

//----- (0053B4B0) --------------------------------------------------------
int __thiscall DClipInfo_List::FreeThread(DClipInfo_List *this, DClipInfo_Node *HeadNode, DClipInfo_Node *TailNode)
{
  int result; // eax@1
  DClipInfo_Node *v4; // edx@1
  _DWORD *v5; // esi@3

  result = 0;
  v4 = HeadNode;
  if( HeadNode )
  {
    if( TailNode )
    {
      do
      {
        ++result;
        ++this->Free_Blocks;
        if( v4 == TailNode )
          v4 = 0;
        else
          v4 = v4->Next;
      }
      while( v4 );
      TailNode->Next = this->Free_Head;
      this->Free_Head = HeadNode;
    }
    else
    {
      do
      {
        v5 = v4;
        ++result;
        ++this->Free_Blocks;
        v4 = v4->Next;
      }
      while( v4 );
      *v5 = this->Free_Head;
      this->Free_Head = HeadNode;
    }
  }
  return result;
}

//----- (0053B510) --------------------------------------------------------
void __thiscall DClipInfo_List::ReclaimAllNodes(DClipInfo_List *this)
{
  DClipInfo_List *v1; // edx@1

  v1 = this;
  memset(this->Draw_Clip_Nodes, 0, 4 * this->YLine_Size);
  memset(this->Draw_Level_Head, 0, 4 * this->Max_Draw_Levels + 4);
  memset(this->Draw_Level_Tail, 0, 4 * this->Max_Draw_Levels + 4);
  this->Free_Head = 0;
  this->Free_Pool_Zone = 0;
  this->Free_Pool_Index = 0;
  v1->Free_Blocks = v1->Total_Blocks;
  ++v1->Reset_Count;
}

//----- (0053B590) --------------------------------------------------------
void __thiscall DClipInfo_List::ResetStats(DClipInfo_List *this)
{
  this->Alloc_Count = 0;
  this->Dealloc_Count = 0;
  this->NewZone_Count = 0;
  this->Reset_Count = 0;
}
