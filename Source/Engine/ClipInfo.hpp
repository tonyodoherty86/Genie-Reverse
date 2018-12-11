#pragma once

#include "Shape.hpp"

/**
 * @file    Engine\ClipInfo.hpp
 * @author  Yvan Burrie
 * @date    2018/08/21
 * @version 1.0
 */

struct DClipInfo_Node
{
    DClipInfo_Node *Next, *NextOnLevel;

    int Object_ID;

    Shape_Info *Shape;

    int Draw_Level;

    int Draw_X,
        Draw_Y;

    int Draw_Flag;

    char *Shape_Base;
    char *Color_Table;

    int Xform_Mask;

    int Node_Type;

    short x1, y1, x2, y2, x3, y3, x4, y4;
};

class DClipInfo_List
{
public:

    DClipInfo_Node **Zone_Ptrs;

    int *Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;

    DClipInfo_Node *Free_Head;

    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;
    int Max_Draw_Levels;

    int Accept_Min_Level,
        Accept_Max_Level;

    DClipInfo_Node **Draw_Clip_Nodes,
                   **Draw_Level_Head,
                   **Draw_Level_Tail;

    int YLine_Offset;
    int YLine_Size;

    short *Select_Box;

    DClipInfo_List(
        int InitialSize,
        int GrowSize,
        int szitem,
        int top_Yline,
        int bottom_Yline,
        int mxLevel );

    ~DClipInfo_List();

    void SetCaptureLevel(int minLevel, int maxLevel);
    void SetNumZones(int New_Size);
    void InitNewZone(int Zone_Size);
    DClipInfo_Node *GetNode();
    void SetDrawRegion(int Left, int Top, int Right, int Bottom);
    void AddDrawNode(void *ShapeBase, Shape_Info *theShape, int SortLine, int Xpos, int Ypos, int DrawFlags, char *ColorTable, int XformMask, int DrawLevel, int Object_ID);
    DClipInfo_Node *AddGDINode(int GDI_Type, int SortLine, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4, int DrawLevel, int DrawColor, int Object_ID);
    DClipInfo_Node *LocateIDbyDrawLevel(int SearchID, int StartLevel, int EndLevel, int NodeType);
    void Scroll(int xDelta, int yDelta);
    void FreeNode(DClipInfo_Node *theNode);
    int FreeThread(DClipInfo_Node *HeadNode, DClipInfo_Node *TailNode);
    void ReclaimAllNodes();
    void ResetStats();
};
