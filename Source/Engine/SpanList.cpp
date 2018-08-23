
/**
 * @file    Engine\SpanList.hpp
 * @author  Yvan Burrie
 * @date    2018/08/21
 * @version 1.0
 */

/**
 *
 */
TSpan_List_Manager::TSpan_List_Manager( int Surface_Width, int Surface_Height )
{
    this->VSList = new TSpan_Node_List(
        Surface_Height * ((Surface_Width + 31) / 32),
        16 * Surface_Height,
        16);

    if( (this->Num_Lines = Surface_Height) < 16 ){
        this->Num_Lines = 16;
    }
    if( (this->Num_Pixels = Surface_Width) < 16 ){
        this->Num_Pixels = 16;
    }

    this->SetSpanRegions(
        0,
        0,
        this->Num_Pixels - 1,
        this->Num_Lines  - 1);

    *this->Line_Head_Ptrs = new VSpan_Node[this->Num_Lines];
    *this->Line_Tail_Ptrs = new VSpan_Node[this->Num_Lines];

    this->LeftMostPx   = new int[this->Num_Lines];
    this->RightMostPx  = new int[this->Num_Lines];
    this->Span_Count   = new int[this->Num_Lines];
}

/**
 *
 */
TSpan_List_Manager::~TSpan_List_Manager()
{
    if( this->Line_Head_Ptrs ){
        delete this->Line_Head_Ptrs;
    }

    if( this->Line_Tail_Ptrs ){
        delete this->Line_Tail_Ptrs;
    }

    if( this->LeftMostPx ){
        delete this->LeftMostPx;
    }

    if( this->RightMostPx ){
        delete this->RightMostPx;
    }

    if( this->Span_Count ){
        delete this->Span_Count;
    }

    delete this->VSList;
}

/**
 *
 */
void TSpan_List_Manager::SetSpanRegions( int MinS, int MinL, int MaxS, int MaxL )
{
    int v5 = MaxS;
    int v6 = MinS;

    if( MinS > MaxS ){
        v6 = MaxS;
        v5 = MinS;
    }

    int v7 = MinL;
    int v8 = MaxL;

    if( MinL > MaxL )
    {
        v7 = MaxL;
        v8 = MinL;
    }

    if( v7 < 0 ){
        v7 = 0;
    }

    if( v8 >= 0 ){
        if( v7 < this->Num_Lines ){
            if( v8 >= this->Num_Lines )
                v8 = this->Num_Lines - 1;
            if( v6 < 0 )
                v6 = 0;
            if( v5 >= 0 ){
                if( v6 < this->Num_Pixels ){

                    if( v5 >= this->Num_Pixels ){
                        v5 = this->Num_Pixels - 1;
                    }

                    this->Min_Line    = v7;
                    this->Max_Line    = v8;
                    this->Min_Span_Px = v6;
                    this->Max_Span_Px = v5;
                }
            }
        }
    }
}

/**
 *
 */
void TSpan_List_Manager::ResetAll()
{
    this->VSList->ReclaimAllNodes();

    memset(this->Line_Head_Ptrs, 0, sizeof(long) * this->Num_Lines);
    memset(this->Line_Tail_Ptrs, 0, sizeof(long) * this->Num_Lines);
    memset(this->LeftMostPx,     0, sizeof(long) * this->Num_Lines);
    memset(this->RightMostPx,    0, sizeof(long) * this->Num_Lines);
    memset(this->Span_Count,     0, sizeof(long) * this->Num_Lines);
}

/**
 *
 */
void TSpan_List_Manager::AddSpan( int LeftPx, int RightPx, int Line )
{
    int v5;
    int v6;

    VSpan_Node *v10; // ebx@11
    VSpan_Node *v11; // eax@12
    int *v12; // ecx@13
    VSpan_Node *v13; // ebp@13
    int v14; // eax@13
    int *v15; // edx@13
    int v16; // ecx@13
    VSpan_Node *v18; // eax@15
    int v19; // ebp@18
    VSpan_Node *v20; // eax@18
    int *v21; // edx@27
    VSpan_Node *v22; // eax@29
    VSpan_Node *v23; // eax@30
    int v24; // ebx@30
    int v25; // edx@41
    int v26; // ebp@41
    int v27; // eax@41

    VSpan_Node *v28;
    VSpan_Node *v29;
    VSpan_Node *v30;
    VSpan_Node **v31;
    VSpan_Node *v32;

    int *RightPxa;

    if( Line >= this->Min_Line &&
        Line <= this->Max_Line ){

        v5 = RightPx;
        v6 = LeftPx;

        if( LeftPx > RightPx ){
            RightPx = LeftPx;
            LeftPx = v5;
            v6 = v5;
            v5 = RightPx;
        }

        if( v5 >= this->Min_Span_Px &&
            v6 <= this->Max_Span_Px ){

            if( v6 < this->Min_Span_Px ){
                LeftPx = this->Min_Span_Px;
            }

            if( v5 > this->Max_Span_Px ){
                RightPx = this->Max_Span_Px;
                v5 = this->Max_Span_Px;
            }

            if( VSpan_Node *v10 = this->Line_Head_Ptrs[Line] ){

                v12 = this->LeftMostPx;
                v13 = this->Line_Tail_Ptrs[Line];
                v14 = this->LeftMostPx[Line];
                v15 = &v12[Line];
                v16 = LeftPx;

                if( LeftPx > v14 ){

                    v21 = &this->RightMostPx[Line];
                    if( RightPx < *v21 ){
                        for( ; v10->EndPx < LeftPx - 1; v10 = v10->Next );
                        v25 = RightPx;
                        v26 = v10->StartPx;
                        v27 = RightPx + 1;
                        if( v26 <= RightPx + 1 ){
                            if( LeftPx < v26 ){
                                v10->StartPx = LeftPx;
                            }
                            if( v10->EndPx < RightPx ){
                                v30 = v10->Next;
                                if( v10->Next ){
                                    while( true ){
                                        if( v27 < v30->StartPx ){
                                            v10->EndPx = v25;
                                            return;
                                        }
                                        if( v25 <= v30->EndPx )
                                            break;
                                        v31 = &v30->Prev->Next;
                                        if( v31 )
                                            *v31 = v30->Next;
                                        if( v30->Next )
                                            v30->Next->Prev = v30->Prev;
                                        v32 = v30;
                                        v30 = v30->Next;
                                        this->VSList->FreeNode(v32);
                                        this->Span_Count[Line]--;
                                        if( !v30 )
                                            return;
                                        v25 = RightPx;
                                        v27 = RightPx + 1;
                                    }
                                    v10->EndPx = v30->EndPx;
                                    v10->Next = v30->Next;
                                    this->VSList->FreeNode(v30);
                                    this->Span_Count[Line]--;
                                    if( v10->Next )
                                        v10->Next->Prev = v10;
                                    else
                                        this->Line_Tail_Ptrs[Line] = v10;
                                }
                            }
                        }else{

                            VSpan_Node *v28 = this->VSList->GetNode();
                            v29 = v10->Prev;
                            v28->Next = v10;
                            v28->Prev = v29;
                            v10->Prev = v28;
                            v28->Prev->Next = v28;
                            v28->StartPx = LeftPx;
                            v28->EndPx = RightPx;

                            this->Span_Count[Line]++;
                        }
                    }else if( LeftPx <= *v21 + 1 ){

                        v23 = this->Line_Tail_Ptrs[Line];
                        *v21 = RightPx;
                        v24 = LeftPx - 1;
                        if( LeftPx - 1 <= v13->EndPx ){
                            while( true ){
                                if( v16 >= v13->StartPx ){
                                    v23->EndPx = RightPx;
                                    return;
                                }
                                v13 = v13->Prev;
                                if( v24 > v13->EndPx )
                                    break;
                                this->Line_Tail_Ptrs[Line] = v13;
                                v13->Next = 0;
                                this->VSList->FreeNode(v23);
                                this->Span_Count[Line]--;
                                v23 = v13;
                                if( v24 > v13->EndPx )
                                    return;
                                v16 = LeftPx;
                            }
                            v23->StartPx = v16;
                            v23->EndPx = RightPx;
                        }
                    }else{

                        VSpan_Node *v22 = this->VSList->GetNode();

                        v22->Prev    = v13;
                        v22->Next    = nullptr;
                        v13->Next    = v22;
                        v22->StartPx = LeftPx;
                        v22->EndPx   = RightPx;

                        this->RightMostPx[Line]    = RightPx;
                        this->Line_Tail_Ptrs[Line] = v22;
                        this->Span_Count[Line]++;
                    }
                }else{

                    if( RightPx >= v14 - 1 ){
                        if( RightPx < this->RightMostPx[Line] ){

                            *v15 = LeftPx;
                            v19 = RightPx + 1;
                            v20 = v10;

                            if( RightPx + 1 >= v10->StartPx ){
                                while( true ){
                                    if( RightPx <= v10->EndPx ){
                                        v20->StartPx = v16;
                                        return;
                                    }
                                    v10 = v10->Next;
                                    if( v19 < v10->StartPx )
                                        break;
                                    this->Line_Head_Ptrs[Line] = v10;
                                    v10->Prev = 0;
                                    this->VSList->FreeNode(v20);
                                    this->Span_Count[Line]--;
                                    v20 = v10;
                                    if( v19 < v10->StartPx )
                                        return;
                                    v16 = LeftPx;
                                }
                                v20->StartPx = v16;
                                v20->EndPx = RightPx;
                            }
                        }else{

                            RightPxa = &this->Span_Count[Line];
                            *RightPxa -= this->VSList->FreeThread(v10->Next, nullptr);

                            v10->Prev    = nullptr;
                            v10->Next    = nullptr;
                            v10->StartPx = LeftPx;
                            v10->EndPx   = RightPx;

                            this->Line_Tail_Ptrs[Line] = v10;
                            this->RightMostPx[Line]    = RightPx;
                            this->LeftMostPx[Line]     = LeftPx;
                        }
                    }else{

                        VSpan_Node *v18 = this->VSList->GetNode();

                        v18->Prev    = nullptr;
                        v18->Next    = v10;
                        v10->Prev    = v18;
                        v18->StartPx = LeftPx;
                        v18->EndPx   = RightPx;

                        this->LeftMostPx[Line]     = LeftPx;
                        this->Line_Head_Ptrs[Line] = v18;
                        this->Span_Count[Line]++;
                    }
                }
            }else{

                VSpan_Node *v11 = this->VSList->GetNode();

                v11->Prev    = nullptr;
                v11->Next    = nullptr;
                v11->StartPx = LeftPx;
                v11->EndPx   = v5;

                this->Line_Head_Ptrs[Line] = v11;
                this->Line_Tail_Ptrs[Line] = v11;
                this->LeftMostPx[Line]     = LeftPx;
                this->RightMostPx[Line]    = v11->EndPx;
                this->Span_Count[Line]++;
            }
        }
    }
}

/**
 *
 */
void TSpan_List_Manager::AddShape( TShape *theShape, int shape_num, int Xpos, int Ypos, int Mirror )
{
    Shape_Info *v8; // ebp@3
    int v9; // esi@3
    int v12; // ebx@3
    short v13; // ax@5
    short v14; // cx@5
    short v15; // cx@12
    short v16; // ax@12
    TShape *theShapea; // [sp+14h] [bp+4h]@3

    if( theShape &&
        theShape->FShape ){

        v8 = &theShape->shape_info[shape_num];
        v9 = (int)theShape->FShape + v8->Shape_Outline_Offset;
        theShapea = (TShape *)(v8->Width + Xpos - 1);
        v12 = Ypos;
        if( Mirror ){
            if( Ypos < v8->Height + Ypos ){
                do
                {
                    v15 = *(WORD *)v9;
                    v16 = *(WORD *)(v9 + 2);
                    v9 += 4;
                    if( v12 >= this->Min_Line && v12 <= this->Max_Line && !(HIBYTE(v16) & 0x80) )
                    {
                        this->AddSpan(Xpos + v16, (int)theShapea - v15, v12);
                    }
                    ++v12;
                }
                while( v12 < v8->Height + Ypos );
            }
        }else if( Ypos < v8->Height + Ypos ){
            do
            {
                v13 = *(WORD *)v9;
                v14 = *(WORD *)(v9 + 2);
                v9 += 4;
                if( v12 >= this->Min_Line && v12 <= this->Max_Line && !(HIBYTE(v13) & 0x80) )
                {
                    this->AddSpan(Xpos + v13, (int)theShapea - v14, v12);
                }
                ++v12;
            }
            while( v12 < v8->Height + Ypos );
        }
    }
}

/**
 *
 */
void TSpan_List_Manager::AddLine_Align( int x1, int y1, int x2, int y2 )
{
    int v5; // eax@1
    int v6; // ebp@1
    TSpan_List_Manager *v7; // edx@1
    int v8; // esi@2
    int v9; // ebp@2
    int i; // ebx@4
    int v11; // ecx@7
    int v12; // esi@7
    int v13; // edi@12
    int v14; // ebp@12
    int v15; // edx@13
    int v16; // ebx@16
    int j; // esi@16
    int v18; // ebx@21
    int v19; // eax@22
    int v20; // ecx@23
    TSpan_List_Manager *v21; // [sp+10h] [bp-4h]@1
    int Linea; // [sp+1Ch] [bp+8h]@13
    int x2a; // [sp+20h] [bp+Ch]@21
    int y2a; // [sp+24h] [bp+10h]@13

    v5 = x1;
    v6 = x2;
    v7 = this;
    v21 = this;
    if( x1 == x2 )
    {
        v8 = y1;
        v9 = y2;
        if( y1 > y2 )
        {
            v8 = y2;
            v9 = y1;
        }
        v5 = x1 | 3;
        for( i = v5; v8 <= v9; ++v8 )
            v21->AddSpan(x1 & 0xFFFFFFFC, i, v8);
    }
    else
    {
        v11 = y1;
        v12 = y2;
        if( y1 == y2 )
        {
            v5 = x1 & 0xFC;
            v7->AddSpan(v5, x2 | 3, y1);
        }
        else
        {
            if( x2 < x1 )
            {
                v11 = y2;
                v12 = y1;
                v5 = x2;
                x2 = x1;
                v6 = x1;
            }
            v13 = v11;
            v14 = v6 - v5 + 1;
            if( v11 >= v12 )
            {
                y2a = -1;
                Linea = v11 - v12 + 1;
                v15 = v11 - v12 + 1;
            }
            else
            {
                y2a = 1;
                v15 = v12 - v11 + 1;
                Linea = v12 - v11 + 1;
            }
            if( v14 < v15 )
            {
                v18 = v5;
                x2a = 0;
                while( 1 )
                {
                    v19 = v18;
                    v19 = v18 & 0xFC;
                    v21->AddSpan(v19, v18 | 3, v13);
                    if( v13 == v12 )
                        break;
                    v20 = v14 + x2a;
                    x2a += v14;
                    if( x2a >= Linea )
                    {
                        ++v18;
                        x2a = v20 - Linea;
                    }
                    v13 += y2a;
                }
            }
            else
            {
                v16 = 0;
                for( j = v5; j < x2; ++j )
                {
                    v16 += v15;
                    if( v16 >= v14 )
                    {
                        v5 &= 0xFC;
                        v21->AddSpan(v5, j | 3, v13);
                        v15 = Linea;
                        v13 += y2a;
                        v16 -= v14;
                        v5 = j + 1;
                    }
                }
                v5 &= 0xFC;
                v21->AddSpan(v5, j | 3, v13);
            }
        }
    }
}

/**
 *
 */
void TSpan_List_Manager::AddMiniList( VSpanMiniList *theList, int Xpos, int Ypos )
{
    if( theList &&
        theList->Y_delta != -1 ){

        this->AddSpan(
            theList->X_start + Xpos,
            theList->X_end   + Xpos,
            theList->Y_delta + Ypos);
    }
}

/**
 *
 */
void TSpan_List_Manager::SubtractMiniList( VSpanMiniList *theList, int Xpos, int Ypos )
{
    if( theList &&
        theList->Y_delta != -1 ){

        this->DeleteSpan(
            theList->X_start + Xpos,
            theList->X_end   + Xpos,
            theList->Y_delta + Ypos);
    }
}

/**
 *
 */
void TSpan_List_Manager::DeleteSpan( int LeftPx, int RightPx, int Line )
{
    TSpan_List_Manager *v4; // ebx@1
    int v5; // edi@3
    int v6; // edx@3
    int v7; // eax@5
    int v8; // ecx@6
    int v9; // ebp@11
    VSpan_Node *v10; // eax@11
    int v11; // esi@12
    int v12; // ecx@13
    VSpan_Node *v13; // esi@17
    int v14; // ecx@19
    VSpan_Node *v15; // eax@21
    VSpan_Node **v16; // eax@37
    VSpan_Node *v17; // edi@41
    VSpan_Node *L; // [sp+10h] [bp-4h]@17
    int Linea; // [sp+20h] [bp+Ch]@17

    if( Line >= this->Min_Line &&
        Line <= this->Max_Line ){

        v5 = LeftPx;
        v6 = RightPx;
        if( LeftPx > RightPx )
        {
            RightPx = LeftPx;
            LeftPx = v6;
            v5 = v6;
            v6 = RightPx;
        }
        v7 = this->Min_Span_Px;
        if( v6 >= v7 )
        {
            v8 = this->Max_Span_Px;
            if( v5 <= v8 )
            {
                if( v5 < v7 )
                {
                    LeftPx = this->Min_Span_Px;
                    v5 = v7;
                }
                if( v6 > v8 )
                {
                    RightPx = v8;
                    v6 = v8;
                }
                v9 = Line;
                if( VSpan_Node *v10 = this->Line_Head_Ptrs[Line] )
                {
                    v11 = this->LeftMostPx[v9];
                    if( v6 >= v11 )
                    {
                        v12 = this->RightMostPx[v9];
                        if( v5 <= v12 )
                        {
                            if( v5 <= v11 && v6 >= v12 )
                            {
                                this->VSList->FreeThread(v10, this->Line_Tail_Ptrs[v9]);

                                this->Line_Head_Ptrs[v9] = nullptr;
                                this->Line_Tail_Ptrs[v9] = nullptr;

                                this->Span_Count[v9]  = 0;
                                this->LeftMostPx[v9]  = 0;
                                this->RightMostPx[v9] = 0;

                                return;
                            }
                            L = this->Line_Head_Ptrs[Line];
                            v13 = this->Line_Head_Ptrs[Line];
                            Linea = (int)this->Line_Tail_Ptrs[v9];
                            if( v10->EndPx < v5 )
                            {
                                do
                                    v13 = v13->Next;
                                while( v13->EndPx < v5 );
                            }
                            v14 = v13->StartPx;
                            if( v5 > v14 )
                            {
                                if( v6 < v13->EndPx )
                                {
                                    v15 = this->VSList->GetNode();
                                    v15->Prev = v13;
                                    v15->Next = v13->Next;
                                    v13->Next = v15;
                                    if( v15->Next )
                                        v15->Next->Prev = v15;
                                    if( v13 == (VSpan_Node *)Linea )
                                        this->Line_Tail_Ptrs[v9] = v15;
                                    v15->StartPx = RightPx + 1;
                                    v15->EndPx = v13->EndPx;
                                    v13->EndPx = v5 - 1;
                                    ++this->Span_Count[v9];
                                    return;
                                }
                                if( v5 > v14 )
                                {
                                    v13->EndPx = v5 - 1;
                                    v13 = v13->Next;
                                }
                            }
                            if( v13 )
                            {
                                while( 1 )
                                {
                                    if( v5 > v13->StartPx || v6 < v13->EndPx )
                                    {
                                        v17 = 0;
                                    }
                                    else
                                    {
                                        if( v13 == v10 )
                                            L = v13->Next;
                                        if( v13 == (VSpan_Node *)Linea )
                                            Linea = (int)v13->Prev;
                                        v16 = &v13->Prev->Next;
                                        if( v16 )
                                            *v16 = v13->Next;
                                        if( v13->Next )
                                            v13->Next->Prev = v13->Prev;
                                        v17 = v13->Next;
                                        this->VSList->FreeNode(v13);
                                        v13 = v17;
                                        --this->Span_Count[v9];
                                        v10 = L;
                                    }
                                    if( !v17 )
                                        break;
                                    v5 = LeftPx;
                                    v6 = RightPx;
                                }
                                if( v13 && RightPx >= v13->StartPx )
                                    v13->StartPx = RightPx + 1;
                            }
                            this->Line_Head_Ptrs[v9] = v10;
                            this->Line_Tail_Ptrs[v9] = (VSpan_Node *)Linea;
                            this->LeftMostPx[v9] = v10->StartPx;
                            this->RightMostPx[v9] = *(_DWORD *)(Linea + 12);
                        }
                    }
                }
            }
        }
    }
}

/**
 *
 */
void TSpan_List_Manager::DeleteShape(
    TShape *theShape,
    int shape_num,
    int Xpos,
    int Ypos,
    int Mirror )
{
    if( theShape ){

        if( theShape->FShape ){

            Shape_Info * v7 = &theShape->shape_info[shape_num];
            int v8 = Ypos;
            int v9 = Ypos;
            int v10 = (int)theShape->FShape + v7->Shape_Outline_Offset;
            TShape *theShapea = (TShape *)(v7->Width + Xpos - 1);

            if( Mirror ){

                if( Ypos < v7->Height + Ypos ){

                    do{

                        short v13 = *(WORD *)v10;
                        short v14 = *(WORD *)(v10 + 2);

                        v10 += 4;

                        if( !(HIBYTE(v14) & 0x80) ){
                            this->DeleteSpan(v14 + Xpos, (int)theShapea - v13, v9);
                        }
                    }
                    while( ++v9 < v7->Height + Ypos );
                }
            }else{
                if( Ypos < v7->Height + Ypos ){
                    do{
                        short v11 = *(WORD *)v10;
                        short v12 = *(WORD *)(v10 + 2);

                        v10 += 4;

                        if( !(HIBYTE(v11) & 0x80) ){

                            this->DeleteSpan(v11 + Xpos, (int)theShapea - v12, v9);
                        }
                    }while( ++v9 < v7->Height + Ypos );
                }
            }
        }
    }
}

/**
 *
 */
VSpan_Node *TSpan_List_Manager::PointVisible( int x, int Line )
{
    VSpan_Node *result;

    if( Line >= 0 &&
        Line < this->Num_Lines &&
        (result = this->Line_Head_Ptrs[Line]) != 0 ){

        while( x < result->StartPx || x > result->EndPx ){
            result = result->Next;
            if( result->Next == nullptr ){
                return nullptr;
            }
        }
        return (VSpan_Node *)1;
    }else{
        return nullptr;
    }
}

/**
 *
 */
void TSpan_List_Manager::Merge_n_Align( TSpan_List_Manager *List1, TSpan_List_Manager *List2 )
{
    this->ResetAll();

    if( this->Num_Lines != List1->Num_Lines ){
        return;
    }

    if( this->Num_Lines != List2->Num_Lines ){
        return;
    }

    if( this->Num_Pixels != List1->Num_Pixels ){
        return;
    }

    if( this->Num_Pixels != List2->Num_Pixels ){
        return;
    }

    if( this->Num_Lines <= 0 ){
        return;
    }

    int i = 0;
    while( true ){

        VSpan_Node *v9 = List1->Line_Head_Ptrs[i];
        VSpan_Node *v10 = List2->Line_Head_Ptrs[i];
        while( v9 ){
            int v11 = v9->StartPx;
            LOBYTE(v11) = v11 & 0xFC;
            this->AddSpan(
                v11,
                v9->EndPx | 3,
                i);

            v9 = v9->Next;

            if( v10 ){

                LABEL_13:
                this->AddSpan(
                    v10->StartPx & 0xFFFFFFFC,
                    v10->EndPx | 3,
                    i);

                v10 = v10->Next;
            }
        }

        if( v10 ){
            this->AddSpan(
                    v10->StartPx & 0xFFFFFFFC,
                    v10->EndPx | 3,
                    i);

            v10 = v10->Next;
        }

        if( ++i < this->Num_Lines ){
            continue;
        }

        break;
    }
}

/**
 *
 */
void TSpan_List_Manager::AlignamizeSpans()
{
    VSpan_Node **v8;

    for( int i = 0; i < this->Num_Lines; this->RightMostPx[i] = this->Line_Tail_Ptrs[i]->EndPx, i++ ){

        while( VSpan_Node *v3 = this->Line_Head_Ptrs[i] ){

            v3->StartPx &= 0xFFFFFFFC;
            v3->EndPx |= 3;

            if( VSpan_Node *v4 = v3->Next ){

                if( v3->EndPx < (v4->StartPx & 0x7FFFFFFC) - 1 ){

                    v3 = v3->Next;

                }else{

                    v3->EndPx = v4->EndPx | 3;

                    v3->Next = v4->Next;

                    v8 = &this->Line_Tail_Ptrs[i];

                    if( v4 == this->Line_Tail_Ptrs[i] ){
                        *v8 = v3;
                    }

                    if( v4->Next ){
                        v4->Next->Prev = v3;
                    }

                    this->VSList->FreeNode(v4);

                    this->Span_Count[i]--;
                }
            }else{
                v3 = nullptr;
            }
        }
        this->LeftMostPx[i] = this->Line_Head_Ptrs[i + 1]->StartPx;
    }
}

/**
 *
 */
void TSpan_List_Manager::ScrollSpansHorizontally( int XOffset, int ClipToCurrentRegion )
{
    TSpan_List_Manager *v3; // ebx@1
    int v4; // ecx@1
    VSpan_Node *v6; // eax@6
    VSpan_Node *v7; // ebp@9
    int v8; // edi@9
    int v9; // esi@9
    VSpan_Node **v10; // ecx@9
    int v11; // edx@10
    int v12; // ebx@11
    int y; // [sp+14h] [bp-4h]@5

    v4 = XOffset;

    if( XOffset ){
        if( ClipToCurrentRegion && abs(XOffset) > this->Max_Span_Px - this->Min_Span_Px ){
            this->ResetAll();
            return;
        }
        y = 0;
        for( int v5 = 0; v5 < this->Num_Lines; ){

            v6 = this->Line_Head_Ptrs[v5];
            if( this->Line_Head_Ptrs[v5] == nullptr ){
                goto LABEL_21;
            }

            while( true ){
                v7 = v6->Next;
                v8 = v4 + v6->StartPx;
                v9 = v4 + v6->EndPx;
                v10 = &v6->Prev->Next;
                if( !ClipToCurrentRegion )
                    goto LABEL_17;
                v11 = this->Min_Span_Px;
                if( v9 >= v11 ){
                    v12 = this->Max_Span_Px;
                    if( v8 <= v12 ){
                        if( v8 < v11 ){
                            v8 = v11;
                        }
                        if( v9 > v12 ){
                            v9 = v12;
                        }
                        goto LABEL_17;
                    }
                }
                if( v10 )
                    *v10 = v7;
                if( v7 )
                    v7->Prev = (VSpan_Node *)v10;
                this->VSList->FreeNode(v6);
                this->Span_Count[y]--;
                v6 = 0;
                LABEL_17:
                if( v6 ){
                    v6->StartPx = v8;
                    v6->EndPx = v9;
                }
                v6 = v7;
                if( v7 == nullptr ){
                    break;
                }
                v4 = XOffset;
            }
            v5 = y;
            v4 = XOffset;
            LABEL_21:
            y = ++v5;
        }
    }
}

/**
 *
 */
void TSpan_List_Manager::ScrollSpansVertically( int YOffset, int ClipToCurrentRegion )
{
    int v6; // ebx@8
    int v8; // ebx@15
    signed int v9; // edi@15
    int v10; // ecx@15
    int v11; // eax@15
    int v12; // edx@15
    int v13; // ebx@17
    int v14; // eax@18
    int *v15; // edx@19
    int v16; // ebp@19

    int YOffseta;
    int YOffsetb;
    int ClearStart;
    int ClearStarta;

    if( YOffset ){
        return;
    }

    if( ClipToCurrentRegion ){
        YOffseta   = this->Min_Line;
        ClearStart = this->Max_Line;
    }else{
        YOffseta   = 0;
        ClearStart = this->Num_Lines - 1;
    }

    int v3 = YOffset;

    if( abs(v3) > ClearStart - YOffseta ){
        this->ResetAll();
        return;
    }

    for( int i = 0; i < this->Num_Lines; i++, v6++ ){

        v6 = v3;

        if( this->Line_Head_Ptrs[i] ){

            if( v6 > YOffseta &&
                v6 < ClearStart ){
                continue;
            }

            this->VSList->FreeThread(
                this->Line_Head_Ptrs[i],
                this->Line_Tail_Ptrs[i]);

            this->Line_Head_Ptrs[i] = nullptr;
            this->Line_Tail_Ptrs[i] = nullptr;

            this->Span_Count[i]  = 0;
            this->LeftMostPx[i]  = 0;
            this->RightMostPx[i] = 0;
        }
    }

    if( v3 <= 0 ){
        v12 = this->Num_Lines;
        v10 = v3;
        v9 = 1;
        v11 = this->Num_Lines - v3;
        v8 = v12 - 1;
        YOffsetb = this->Num_Lines - v3;
    }else{
        v8 = 0;
        v9 = -1;
        v10 = this->Num_Lines - v3 - 1;
        v11 = 0;
        YOffsetb = 0;
        v12 = v3 - 1;
    }

    v13 = v9 + v8;
    ClearStarta = v12;

    if( v10 != v13 ){

        v14 = v10 + v3;
        do
        {
            this->Line_Head_Ptrs[v14] = this->Line_Head_Ptrs[v10];
            this->Line_Tail_Ptrs[v14] = this->Line_Tail_Ptrs[v10];

            this->Span_Count[v14] = this->Span_Count[v10];
            this->LeftMostPx[v14] = this->LeftMostPx[v10];

            v15 = this->RightMostPx;
            v16 = v15[v10];
            v10 += v9;
            v15[v14] = v16;
            v14 += v9;
        }
        while( v10 != v13 );

        v11 = YOffsetb;
        v12 = ClearStarta;
    }

    for( ; v11 <= v12; v11++ ){

        this->Line_Head_Ptrs[v11] = 0;
        this->Line_Tail_Ptrs[v11] = 0;

        this->Span_Count[v11]  = 0;
        this->LeftMostPx[v11]  = 0;
        this->RightMostPx[v11] = 0;
    }
}

/**
 *
 */
int TSpan_List_Manager::ValidateSpan( int Line )
{
    int v2 = 0;
    int v3 = 0;

    if( Line >= 0 &&
        Line < this->Num_Lines ){

        if( VSpan_Node *v5 = this->Line_Head_Ptrs[Line] ){

            VSpan_Node *v7 = nullptr;

            while( ++v2 != 1 ||
                   v5->StartPx == this->LeftMostPx[Line] ){

                if( v5->Prev != v7 {
                    break;
                }

                if( v5->StartPx > v5->EndPx || v2 > 1 &&
                    v5->StartPx <= v3 ){
                    break;
                }

                v3 = v5->EndPx;
                v7 = v5;
                v5 = v5->Next;
                if( v5 == nullptr ){

                    if( this->Span_Count[Line] == v2 &&
                        this->Line_Tail_Ptrs[Line] == v7 ){

                        if( v7->EndPx == this->RightMostPx[Line] ){
                            return this->LeftMostPx[Line] <= this->RightMostPx[Line];
                        }
                    }
                    return 0;
                }
            }
        }else if( (this->Line_Tail_Ptrs[Line] == nullptr) &&
                  (this->Span_Count[Line]     == nullptr) &&
                  (this->LeftMostPx[Line]     == nullptr) ){

            return this->RightMostPx[Line] == 0;
        }
    }
    return 0;
}

/**
 *
 */
int TSpan_List_Manager::DecodeLine( char *LineBuf, int Line, char fillC, int MaxX )
{
    for( int dl = 0, VSpan_Node *node = this->Line_Head_Ptrs[Line]; node; dl++ ){

        for( int v7 = node->StartPx, int j = i->EndPx; v7 <= j; v7++ ){
            LineBuf[v7] += fillC;
        }
        node = node->Next;
    }

    return dl;
}

/**
 *
 */
void TSpan_List_Manager::take_snapshot(
    char *filespec,
    int *index_no,
    TDrawArea *render_area,
    int scolor,
    TSpan_List_Manager **SpanArray,
    int *colorArray,
    int ArraySize )
{
    if( ArraySize <= 0 ){

        LABEL_6:
        int Width  = this->Num_Pixels;
        int Height = this->Num_Lines;

        int bmWide = ((WORD)Width + 3) & 0xFFFC;

        BITMAPFILEHEADER bmFH;
        bmFH.bfType             = (WORD)'MB';
        bmFH.bfReserved1        = 0;
        bmFH.bfReserved2        = 0;
        bmFH.bfOffBits          = 1078;
        bmFH.bfSize             = bmWide * Height + bmFH.bfOffBits;

        BITMAPINFOHEADER bmIH;
        bmIH.biSize             = sizeof(BITMAPINFOHEADER);
        bmIH.biWidth            = Width;
        bmIH.biHeight           = Height;
        bmIH.biPlanes           = 1;
        bmIH.biBitCount         = 8;
        bmIH.biCompression      = 0;
        bmIH.biSizeImage        = 0;
        bmIH.biXPelsPerMeter    = 0;
        bmIH.biYPelsPerMeter    = 0;
        bmIH.biClrUsed          = 0;
        bmIH.biClrImportant     = 0;

        PALETTEENTRY thePal[256];
        render_area->GetPalette(thePal);

        RGBQUAD bmPAL[256];
        for( int i = 0; i < 256; i++ ){
            bmPAL[i].rgbBlue     = thePal[i].peBlue;
            bmPAL[i].rgbGreen    = thePal[i].peGreen;
            bmPAL[i].rgbRed      = thePal[i].peRed;
            bmPAL[i].rgbReserved = (BYTE)0;
        }

        if( *index_no < 0 ){
            *index_no = 0;
        }
        int v15 = 0;
        while( 1 ){
            char BMPFile[60];
            if( filespec ){
                sprintf(BMPFile, filespec, *index_no);
            }else{
                sprintf(BMPFile, "C:\\AOE_%03d.BMP", *index_no);
            }
            ++v15;
            int v16 = open(BMPFile, 0);
            if( v16 == -1 ){
                break;
            }
            *index_no++;
            close(v16);
            if( v15 > 1000 ){
                return;
            }
        }
        void *v17 = malloc(bmWide);
        int infile = open(BMPFile, 33537, 384);

        if( infile != -1 ){

            write(infile, &bmFH, sizeof(BITMAPFILEHEADER));
            write(infile, &bmIH, sizeof(BITMAPINFOHEADER));
            write(infile, bmPAL, sizeof(RGBQUAD) * 256);

            for( int v20 = Height - 1; v20 >= 0; v20-- ){

                memset(v17, 0, bmWide);

                this->DecodeLine((char *)v17, v20, scolor, Width);

                if( ArraySize > 0 ){

                    TSpan_List_Manager **v21 = SpanArray;
                    int Heighta = ArraySize;
                    do{
                        *v21->DecodeLine(
                            (char *)v17,
                            v20,
                            *((_BYTE *)v21 + (char *)colorArray - (char *)SpanArray),
                            Width);
                        ++v21;
                        --Heighta;
                    }while( Heighta );
                }

                write(infile, v17, bmWide);
            }

            close(infile);
        }
        free(v17);
    }else{
        int v8 = 0;
        TSpan_List_Manager **v9 = SpanArray;
        while( *v9 ){
            ++v9;
            if( ++v8 >= ArraySize ){
                goto LABEL_6;
            }
        }
    }
}

/**
 *
 */
TSpan_Node_List::TSpan_Node_List( unsigned int InitialSize, unsigned int GrowSize, size_t szitem )
{
    this->Element_Size      = szitem;
    this->Default_Grow_Size = GrowSize;

    this->ResetStats();

    if( InitialSize > 0 ){
        this->SetNumZones(8);
        this->InitNewZone(InitialSize);
    }
}

/**
 *
 */
TSpan_Node_List::~TSpan_Node_List()
{
    for( size_t index = 0; index < this->Used_Zones; index++ ){
        if( this->Zone_Ptrs[index] ){
            delete this->Zone_Ptrs[index];
        }
    }

    if( this->Zone_Ptrs ){
        delete this->Zone_Ptrs;
    }

    if( this->Zone_Size_Ptrs ){
        delete this->Zone_Size_Ptrs;
    }
}

/**
 *
 */
void TSpan_Node_List::InitNewZone( unsigned int Zone_Size )
{
    if( this->Used_Zones == this->Max_Zones ){
        this->SetNumZones(this->Used_Zones + 4);
    }

    this->Zone_Size_Ptrs[this->Used_Zones] = Zone_Size;
    this->Zone_Ptrs[this->Used_Zones] = (VSpan_Node *)malloc(Zone_Size * this->Element_Size);
    this->NewZone_Count++;
    this->Total_Blocks += Zone_Size;
    this->Free_Blocks  += Zone_Size;

    if( this->Free_Pool_Zone == -1 ){
        this->Free_Pool_Zone = this->Used_Zones;
        this->Free_Pool_Index = 0;
    }
    this->Used_Zones++;
}

/**
 *
 */
void TSpan_Node_List::SetNumZones( size_t New_Size )
{
    int New_Sizea;

    if( New_Size < this->Max_Zones ){
        return;
    }

    VSpan_Node **zone_ptrs = new VSpan_Node[New_Size];

    New_Sizea = (int)zone_ptrs;

    int *zone_size_ptrs = new int[New_Size];
    if( this->Zone_Ptrs ){
        if( this->Used_Zones > 0 ){
            unsigned int i = 0;
            do{
                char *v8 = (char *)&zone_size_ptrs[i];
                *(size_t *)&v8[(char *)zone_ptrs - (char *)zone_size_ptrs] = this->Zone_Ptrs[i];
                *(size_t *)v8 = this->Zone_Size_Ptrs[i];
            }while( ++i < this->Used_Zones );

            zone_ptrs = (VSpan_Node **)New_Sizea;
        }
        delete this->Zone_Ptrs;
        delete this->Zone_Size_Ptrs;
    }

    this->Zone_Ptrs      = zone_ptrs;
    this->Zone_Size_Ptrs = zone_size_ptrs;
    this->Max_Zones      = New_Size;
}

/**
 *
 */
VSpan_Node *TSpan_Node_List::GetNode()
{
    if( this->Free_Blocks == 0 ){
        this->InitNewZone(this->Default_Grow_Size);
    }

    VSpan_Node *node = this->Free_Head;

    if( node ){

        this->Free_Head = node->Next;
        this->Free_Blocks--;

    }else{

        node = &this->Zone_Ptrs[this->Free_Pool_Zone][this->Free_Pool_Index];

        this->Free_Pool_Index++;
        this->Free_Blocks--;

        if( this->Free_Pool_Index == this->Zone_Size_Ptrs[this->Free_Pool_Zone] ){

            this->Free_Pool_Zone++;
            this->Free_Pool_Index = 0;

            if( this->Free_Pool_Zone == (int)this->Used_Zones ){

                this->Free_Pool_Zone = -1;

                if( this->Free_Blocks > 0 ){
                    raise(SIGABRT);
                }
            }
        }
    }

    return node;
}

/**
 *
 */
void TSpan_Node_List::FreeNode( VSpan_Node *theNode )
{
    theNode->Next = this->Free_Head;
    theNode->Prev = nullptr;
    this->Free_Head = theNode;
    this->Free_Blocks++;
}

/**
 *
 */
int TSpan_Node_List::FreeThread( VSpan_Node *HeadNode, VSpan_Node *TailNode )
{
    int result = 0;

    if( HeadNode == nullptr ){
        return result;
    }

    if( TailNode ){
        do{
            result++;
            this->Free_Blocks++;

            if( HeadNode == TailNode )
                break;

            HeadNode = HeadNode->Next;

        }while( HeadNode );

        TailNode->Next = this->Free_Head;

    }else{

        VSpan_Node *v5;

        do{
            result++;
            this->Free_Blocks++;

            v5 = HeadNode;

            HeadNode = HeadNode->Next;

        }while( HeadNode );

        v5->Next = this->Free_Head;
    }

    this->Free_Head = HeadNode;

    return result;
}

/**
 *
 */
void TSpan_Node_List::ReclaimAllNodes()
{
    this->Free_Head       = nullptr;
    this->Free_Pool_Zone  = 0;
    this->Free_Pool_Index = 0;
    this->Free_Blocks     = this->Total_Blocks;
    this->Reset_Count++;
}

/**
 *
 */
void TSpan_Node_List::ResetStats()
{
    this->Alloc_Count   = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count   = 0;
}
