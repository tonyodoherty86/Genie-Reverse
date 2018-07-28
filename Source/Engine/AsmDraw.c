
/**
 * @file    Engine\AsmDraw.c
 * @author  Yvan Burrie
 * @date    2018/07/19
 * @version 1.0
 */

#ifndef ASM_DRAW_C
#define ASM_DRAW_C

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
int dword_88C014 = 0;

/**
 * dword_88C01C (ROR)
 */
int ASMXlate = 0;

/**
 * dword_88C020 (ROR)
 */
int dword_88C020 = 0;

/**
 * dword_88C02C (ROR)
 */
int dword_88C02C = 0;

/**
 * dword_88C030 (ROR)
 */
int dword_88C030 = 0;

int dword_88C034 = 0;

/**
 * 88C038 (ROR)
 */
int ASMDrawYOffset = 0;

/**
 *  (ROR)
 */
VSpan_Node *ASMCurrentLineHead;

/**
 * 88C040 (ROR)
 */
int ASMColorXForm1 = 0;

//int (*dword_88C044)(void) = NULL;

int dword_88C04C = 0;

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

/**
 *
 */
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

/**
 *
 */
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

/**
 *
 */
void ASMSet_Color_Xform(unsigned int a1)
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

/**
 *
 */
int ASMGet_Color_Xform()
{
    return (unsigned char)ASMColorXForm1;// XformMask
}

/**
 *
 */
void ASMSet_Xlate_Table(int a1)
{
    asm("push    ebp");
    asm("mov     ebp, esp");
    asm("mov     eax, [ebp+arg_0]");
    asm("mov     ds:ASMXlate, eax");
    asm("pop     ebp");
    asm("retn");
}

/**
 *
 */
int ASMGet_Xlate_Table()
{
    return ASMXlate;
}

/**
 *
 */
void ASMDraw_HLine(
    int x1,
    int x2,
    int y1)
{
    int result;
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    int v9;
    int v10;
    int v11;

    result = y1;

    if( y1 >= ASMMinLine &&
        y1 <= ASMMaxLine ){

        result = x1;
        v4 = x2;

        if( x1 > x2 ){
            result = x2;
            v4 = x1;
            x1 = x2;
            x2 = v4;
        }
        if( v4 >= ASMMinSpanPx &&
            result <= ASMMaxSpanPx ){
            if( result < ASMMinSpanPx ){
                result = ASMMinSpanPx;
                x1 = ASMMinSpanPx;
            }
            if( v4 > ASMMaxSpanPx ){
                v4 = ASMMaxSpanPx;
                x2 = ASMMaxSpanPx;
            }

            v5 = ASMLineHeadPtrs[y1];
            if( ASMLineHeadPtrs[y1] ){

                ASMCurrentLineHead = ASMLineHeadPtrs[y1];

                v6 = result;

                ASMDrawYOffset = v4 - result + 1;

                dword_88C044 = &loc_56C99A;

                v7 = ASMRenderOffsets[y1];

                dword_88C020 = v7;

                result = v6 + v7;

                dword_88C014 = result;

                while( v4 >= *(v5 + 8) ){
                    if( v6 <= *(v5 + 12) ){
                        if( v6 >= *(v5 + 8) && v4 <= *(v5 + 12) ){
                            v8 = ASMDrawYOffset & 0x7F;
                            if( ASMDrawYOffset >= 128 ){
                                LOBYTE(v8) = v8 | 0x80;
                            }
                            JUMPOUT(__CS__, off_56A700[(byte_56B300[v8] | dword_88C014 & 3)]);
                        }

                        ASMCurrentLineHead = v5;

                        while( true ){

                            v9 = ASMDrawYOffset;

                            if( x2 < ASMCurrentLineHead->StartPx ){
                                break;
                            }

                            if( x1 <= ASMCurrentLineHead->EndPx ){
                                v10 = 0;
                                if( x1 < ASMCurrentLineHead->StartPx ){
                                    v10 = ASMCurrentLineHead->StartPx - x1;
                                    v9 = ASMDrawYOffset - v10;
                                }
                                dword_88C04C = v10;
                                if( x2 > ASMCurrentLineHead->EndPx ){
                                    v9 -= x2 - ASMCurrentLineHead->EndPx;
                                    dword_88C044 = &loc_56C8FA;
                                }
                                v11 = v9 & 0x7F;
                                if( v9 >= 128 ){
                                    LOBYTE(v11) = v11 | 0x80;
                                }
                                JUMPOUT(__CS__, off_56A700[(byte_56B300[v11] | (dword_88C04C + dword_88C014) & 3)]);
                            }

                            if( ASMCurrentLineHead->Next == nullptr ){
                                break;
                            }
                            ASMCurrentLineHead = ASMCurrentLineHead->Next;

                            dword_88C044 = &loc_56C99A;
                        }
                        return result;
                    }

                    v5 = *v5;
                    if( !v5 ){
                        return result;
                    }
                }
            }
        }
    }
    return result;
}

/**
 *
 */
void ASMDraw_Sprite(
    int ShapeBase,
    int DrawX,
    int DrawY,
    int DrawW,
    int DrawH,
    int ShapeDataOffsets,
    int ShapeLineOffsets,
    int DrawFlag)
{
    /* TODO */
}

#endif // ASM_DRAW_C
