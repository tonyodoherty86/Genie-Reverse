
/**
 * @file    Engine\SpanList.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TSpan_Node_List
{
public:

    struct VSpan_Node **Zone_Ptrs;
    int *Zone_Size_Ptrs = 0;
    int Used_Zones = 0;
    int Max_Zones = 8;

    struct VSpan_Node *Free_Head;
    int Free_Pool_Zone = -1;
    int Free_Pool_Index = -1;

    int Total_Blocks = 0;
    int Free_Blocks = 0;

    int Default_Grow_Size = 0;

    int Element_Size = 0;

    int Alloc_Count = 0;
    int Dealloc_Count = 0;
    int NewZone_Count = 0;
    int Reset_Count = 0;

    TSpan_Node_List(int InitialSize, int GrowSize, int szitem);
    ~TSpan_Node_List();

    void InitNewZone(int Zone_Size);

    void SetNumZones(int New_Size);

    VSpan_Node * GetNode();

    void FreeNode(VSpan_Node *theNode);

    int FreeThread(VSpan_Node *HeadNode, VSpan_Node *TailNode);

    void ReclaimAllNodes();

    void ResetStats();
};

struct VSpan_Node
{
    VSpan_Node *Next;
    VSpan_Node *Prev;
    int StartPx;
    int EndPx;
};

class TShape;
struct Shape_Info;

class TSpan_List_Manager
{
public:

    TSpan_Node_List VSList;

    VSpan_Node **Line_Head_Ptrs,
               **Line_Tail_Ptrs;

    int *LeftMostPx,
        *RightMostPx;

    int *Span_Count;

    int Num_Lines;
    int Num_Pixels;

    int Min_Span_Px,
        Max_Span_Px;

    int Min_Line,
        Max_Line;

    TSpan_List_Manager(int Surface_Width, int Surface_Height);
    ~TSpan_List_Manager();

    void SetSpanRegions(int MinS, int MinL, int MaxS, int MaxL);

    void ResetAll();

    void AddSpan(int LeftPx, int RightPx, int Line);

    void AddShape(TShape *theShape, int shape_num, int Xpos, int Ypos, int Mirror);

    void AddShape_Align(char *Shape_Base, Shape_Info *SI, int Xpos, int Ypos, int Mirror);

    void AddLine_Align(int x1, int y1, int x2, int y2);
};

struct VSpanMiniList
{
    char Y_delta,
         X_start,
         X_end;
};
