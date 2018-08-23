
/**
 * @file    Engine\SpanList.hpp
 * @author  Yvan Burrie
 * @date    2018/08/19
 * @version 1.0
 */

class TSpan_List_Manager
{
public:

    TSpan_Node_List *VSList;

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

    TSpan_List_Manager( int Surface_Width, int Surface_Height );

    ~TSpan_List_Manager();

    void SetSpanRegions( int MinS, int MinL, int MaxS, int MaxL );

    void ResetAll();

    void AddSpan( int LeftPx, int RightPx, int Line );

    void AddShape( TShape *theShape, int shape_num, int Xpos, int Ypos, int Mirror );

    void AddShape_Align( char *Shape_Base, Shape_Info *SI, int Xpos, int Ypos, int Mirror );

    void AddLine_Align( int x1, int y1, int x2, int y2 );

    void AddMiniList( VSpanMiniList *theList, int Xpos, int Ypos );
    void SubtractMiniList( VSpanMiniList *theList, int Xpos, int Ypos );

    void DeleteSpan( int LeftPx, int RightPx, int Line );
    void DeleteShape( TShape *theShape, int shape_num, int Xpos, int Ypos, int Mirror );
    VSpan_Node *PointVisible( int x, int Line );
    void Merge_n_Align( TSpan_List_Manager *List1, TSpan_List_Manager *List2 );
    void AlignamizeSpans();
    void ScrollSpansHorizontally( int XOffset, int ClipToCurrentRegion );
    void ScrollSpansVertically( int YOffset, int ClipToCurrentRegion );
    int ValidateSpan( int Line );
    int DecodeLine( char *LineBuf, int Line, char fillC, int MaxX );

    void take_snapshot(
        char *filespec,
        int *index_no,
        TDrawArea *render_area,
        int scolor,
        TSpan_List_Manager **SpanArray,
        int *colorArray,
        int ArraySize );
};

struct VSpanMiniList
{
    char Y_delta,
         X_start,
         X_end;
};

class TSpan_Node_List
{
    public:

    VSpan_Node **Zone_Ptrs;

    int *Zone_Size_Ptrs;

    unsigned int Used_Zones,
                 Max_Zones = 8;

    VSpan_Node *Free_Head;

    int Free_Pool_Zone  = -1,
        Free_Pool_Index = -1;

    int Total_Blocks,
        Free_Blocks;

    int Default_Grow_Size,
        Element_Size;

    int Alloc_Count,
        Dealloc_Count,
        NewZone_Count,
        Reset_Count;

    public: TSpan_Node_List( unsigned int InitialSize, unsigned int GrowSize, size_t szitem );

    public: ~TSpan_Node_List();

    private: void InitNewZone( unsigned int Zone_Size );

    private: void SetNumZones( size_t New_Size );

    public: VSpan_Node *GetNode();

    public: void FreeNode( VSpan_Node *theNode );

    public: int FreeThread( VSpan_Node *HeadNode, VSpan_Node *TailNode );

    public: void ReclaimAllNodes();

    public: void ResetStats();
};

struct VSpan_Node
{
    VSpan_Node *Next, *Prev;

    int StartPx, EndPx;
};
