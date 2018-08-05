
/**
 * @file    Engine\AsmDraw.c
 * @author  Yvan Burrie
 * @date    2018/07/28
 * @version 1.0
 */

#ifndef ASM_DRAW_H
    #include "AsmDraw.h"
#endif

#ifndef ASM_DRAW_C
    #define ASM_DRAW_C
#endif

/**
 * dword_88C000 (ROR)
 */
void **ASMRenderOffsets;

/**
 * dword_88C004 (ROR)
 */
VSpan_Node **ASMLineHeadPtrs;

/**
 * dword_88C008 (ROR)
 */
VSpan_Node **ASMLineTailPtrs;

/**
 * dword_88C014 (ROR)
 */
int ASMCurrentRenderXOffset = 0;

/**
 * dword_88C01C (ROR)
 */
int ASMXlate = 0;

/**
 * dword_88C020 (ROR)
 */
int ASMCurrentRenderYOffset = 0;

/**
 *
 */
int dword_88C02C = 0;

/**
 *
 */
int dword_88C030 = 0;

/**
 *
 */
int dword_88C034 = 0;

/**
 * dword_88C038 (ROR)
 */
int ASMDrawYOffset = 0;

/**
 * dword_88C03C (ROR)
 */
VSpan_Node *ASMCurrentLineHead;

/**
 * dword_88C040 (ROR)
 */
int ASMColorXForm1 = 0;

/**
 * dword_88C044 (ROR)
 * dword_795044 (AOC)
 */
int (*ASMLocation)(void);

/**
 * dword_88C04C (ROR)
 */
int ASMCurrentLineHeadPx = 0;

/**
 * dword_88C060 (ROR)
 */
int ASMShadowing1A = 0;

/**
 * dword_88C064 (ROR)
 */
int ASMShadowing3A = 0;

/**
 * dword_88C068 (ROR)
 */
int ASMShadowing1B = 0;

/**
 * dword_88C06C (ROR)
 */
int ASMShadowing3B = 0;

/**
 * dword_88C070 (ROR)
 */
int ASMShadowing2A = 0;

/**
 * dword_88C074 (ROR)
 */
int ASMShadowing4A = 0;

/**
 * dword_88C078 (ROR)
 */
int ASMShadowing2B = 0;

/**
 * dword_88C07C (ROR)
 */
int ASMShadowing4B = 0;

/**
 * dword_88C080 (ROR)
 */
int ASMMinLine = 0;

/**
 * dword_88C084 (ROR)
 */
int ASMMaxLine = 0;

/**
 * dword_88C088 (ROR)
 */
int ASMMinSpanPx = 0;

/**
 * dword_88C08C (ROR)
 */
int ASMMaxSpanPx = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Shadowing(
    int a1,
    int a2,
    int a3,
    int a4)
{
    ASMShadowing1A = a1;
    ASMShadowing1B = a1;
    ASMShadowing2A = a2;
    ASMShadowing2B = a2;
    ASMShadowing3A = a3;
    ASMShadowing3B = a3;
    ASMShadowing4A = a4;
    ASMShadowing4B = a4;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Surface_Info(
    void **RenderOffsets,
    VSpan_Node **LineHeadPtrs,
    VSpan_Node **LineTailPtrs,
    int MinSpanPx,
    int MinLine,
    int MaxSpanPx,
    int MaxLine)
{
    ASMRenderOffsets = RenderOffsets;
    ASMLineHeadPtrs  = LineHeadPtrs;
    ASMLineTailPtrs  = LineTailPtrs;
    ASMMinLine       = MinLine;
    ASMMaxLine       = MaxLine;
    ASMMinSpanPx     = MinSpanPx;
    ASMMaxSpanPx     = MaxSpanPx;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Color_Xform( unsigned int a1 )
{
    /*
    asm("push    ebp");
    asm("mov     ebp, esp");
    asm("mov     eax, [ebp+0x08]");
    asm("mov     cl, al");
    asm("mov     ah, al");
    asm("bswap   eax");
    asm("mov     al, cl");
    asm("mov     ah, cl");
    asm("mov     ds:ASMColorXForm1, eax");
    asm("pop     ebp");
    asm("retn");
    */
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int ASMGet_Color_Xform()
{
    return (unsigned char)ASMColorXForm1;// XformMask
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Xlate_Table( int ColorTable )
{
    ASMXlate = ColorTable;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int ASMGet_Xlate_Table()
{
    return ASMXlate;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMDraw_HLine( int x1, int x2, int y1 )
{
    if( y1 < ASMMinLine ||
        y1 > ASMMaxLine ){
        return;
    }

    int xmax = x1;
    int xmin = x2;

    if( x1 > x2 ){
        xmax = x2;
        xmin = x1;
        x1 = x2;
        x2 = xmin;
    }

    if( xmin < ASMMinSpanPx ||
        xmax > ASMMaxSpanPx ){
        return;
    }
    if( xmax < ASMMinSpanPx ){
        xmax = ASMMinSpanPx;
        x1 = ASMMinSpanPx;
    }
    if( xmin > ASMMaxSpanPx ){
        xmin = ASMMaxSpanPx;
        x2 = ASMMaxSpanPx;
    }

    VSpan_Node *LineHead = ASMLineHeadPtrs[y1]
    if( LineHead == NULL ){
        return;
    }

    ASMCurrentLineHead = ASMLineHeadPtrs[y1];

    int tempx = xmax;

    ASMDrawYOffset = xmin - xmax + 1;

    ASMLocation = &&loc_56C99A;

    ASMCurrentRenderYOffset = ASMRenderOffsets[y1];

    xmax += ASMCurrentRenderYOffset;

    ASMCurrentRenderXOffset = xmax;

    while( xmin >= LineHead->StartPx ){

        if( tempx <= LineHead->EndPx ){
            if( tempx >= LineHead->StartPx &&
                xmin <= LineHead->EndPx ){
                int v8 = ASMDrawYOffset & 127;
                if( ASMDrawYOffset >= 128 ){
                    LOBYTE(v8) = v8 | 0x80;
                }
                JUMPOUT(__CS__, off_56A700[(byte_56B300[v8] | ASMCurrentRenderXOffset & 3)]);
            }

            ASMCurrentLineHead = LineHead;

            while( true ){

                int v9 = ASMDrawYOffset;

                if( x2 < ASMCurrentLineHead->StartPx ){
                    break;
                }

                if( x1 <= ASMCurrentLineHead->EndPx ){
                    int v10 = 0;
                    if( x1 < ASMCurrentLineHead->StartPx ){
                        v10 = ASMCurrentLineHead->StartPx - x1;
                        v9 = ASMDrawYOffset - v10;
                    }
                    ASMCurrentLineHeadPx = v10;
                    if( x2 > ASMCurrentLineHead->EndPx ){
                        v9 -= x2 - ASMCurrentLineHead->EndPx;
                        ASMLocation = &&loc_56C8FA;
                    }
                    int v11 = v9 & 127;
                    if( v9 >= 128 ){
                        LOBYTE(v11) = v11 | 0x80;
                    }
                    JUMPOUT(__CS__, off_56A700[(byte_56B300[v11] | (ASMCurrentLineHeadPx + ASMCurrentRenderXOffset) & 3)]);
                }

                loc_56C8FA:
                if( ASMCurrentLineHead->Next == NULL ){
                    break;
                }
                ASMCurrentLineHead = ASMCurrentLineHead->Next;

                ASMLocation = &&loc_56C99A;
            }
            return;
        }

        LineHead = LineHead->Next;
        if( LineHead == NULL ){
            loc_56C99A:
            return;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMDraw_Sprite(
    SLhape_File_Header *ShapeBase,
    int DrawX,
    int DrawY,
    int DrawW,
    int DrawH,
    int ShapeDataOffsets,
    int ShapeLineOffsets,
    int DrawFlag )
{
    /* TODO */
}
